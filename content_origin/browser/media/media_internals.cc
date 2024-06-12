// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "content/browser/media/media_internals.h"

#include <stddef.h>

#include <memory>
#include <utility>

#include "base/macros.h"
#include "base/metrics/histogram_macros.h"
#include "base/strings/string16.h"
#include "base/strings/string_number_conversions.h"
#include "base/strings/stringprintf.h"
#include "build/build_config.h"
#include "content/browser/renderer_host/media/media_stream_manager.h"
#include "content/public/browser/browser_thread.h"
#include "content/public/browser/notification_service.h"
#include "content/public/browser/notification_types.h"
#include "content/public/browser/render_frame_host.h"
#include "content/public/browser/render_process_host.h"
#include "content/public/browser/web_contents.h"
#include "content/public/browser/web_ui.h"
#include "media/base/audio_parameters.h"
#include "media/base/media_log_event.h"
#include "media/filters/gpu_video_decoder.h"

#if !defined(OS_ANDROID)
#include "media/filters/decrypting_video_decoder.h"
#endif

namespace {

static base::LazyInstance<content::MediaInternals>::Leaky g_media_internals = LAZY_INSTANCE_INITIALIZER;

base::string16 SerializeUpdate(const std::string& function,
    const base::Value* value)
{
    return content::WebUI::GetJavascriptCall(
        function, std::vector<const base::Value*>(1, value));
}

std::string EffectsToString(int effects)
{
    if (effects == media::AudioParameters::NO_EFFECTS)
        return "NO_EFFECTS";

    struct {
        int flag;
        const char* name;
    } flags[] = {
        { media::AudioParameters::ECHO_CANCELLER, "ECHO_CANCELLER" },
        { media::AudioParameters::DUCKING, "DUCKING" },
        { media::AudioParameters::KEYBOARD_MIC, "KEYBOARD_MIC" },
        { media::AudioParameters::HOTWORD, "HOTWORD" },
    };

    std::string ret;
    for (size_t i = 0; i < arraysize(flags); ++i) {
        if (effects & flags[i].flag) {
            if (!ret.empty())
                ret += " | ";
            ret += flags[i].name;
            effects &= ~flags[i].flag;
        }
    }

    if (effects) {
        if (!ret.empty())
            ret += " | ";
        ret += base::IntToString(effects);
    }

    return ret;
}

std::string FormatToString(media::AudioParameters::Format format)
{
    switch (format) {
    case media::AudioParameters::AUDIO_PCM_LINEAR:
        return "pcm_linear";
    case media::AudioParameters::AUDIO_PCM_LOW_LATENCY:
        return "pcm_low_latency";
    case media::AudioParameters::AUDIO_BITSTREAM_AC3:
        return "ac3";
    case media::AudioParameters::AUDIO_BITSTREAM_EAC3:
        return "eac3";
    case media::AudioParameters::AUDIO_FAKE:
        return "fake";
    }

    NOTREACHED();
    return "unknown";
}

const char kAudioLogStatusKey[] = "status";
const char kAudioLogUpdateFunction[] = "media.updateAudioComponent";

} // namespace

namespace content {

class AudioLogImpl : public media::AudioLog {
public:
    AudioLogImpl(int owner_id,
        media::AudioLogFactory::AudioComponent component,
        content::MediaInternals* media_internals);
    ~AudioLogImpl() override;

    void OnCreated(int component_id,
        const media::AudioParameters& params,
        const std::string& device_id) override;
    void OnStarted(int component_id) override;
    void OnStopped(int component_id) override;
    void OnClosed(int component_id) override;
    void OnError(int component_id) override;
    void OnSetVolume(int component_id, double volume) override;
    void OnSwitchOutputDevice(int component_id,
        const std::string& device_id) override;
    void OnLogMessage(int component_id, const std::string& message) override;

    // Called by MediaInternals to update the WebContents title for a stream.
    void SendWebContentsTitle(int component_id,
        int render_process_id,
        int render_frame_id);

private:
    void SendSingleStringUpdate(int component_id,
        const std::string& key,
        const std::string& value);
    void StoreComponentMetadata(int component_id, base::DictionaryValue* dict);
    std::string FormatCacheKey(int component_id);

    static void SendWebContentsTitleHelper(
        const std::string& cache_key,
        std::unique_ptr<base::DictionaryValue> dict,
        int render_process_id,
        int render_frame_id);

    const int owner_id_;
    const media::AudioLogFactory::AudioComponent component_;
    content::MediaInternals* const media_internals_;

    DISALLOW_COPY_AND_ASSIGN(AudioLogImpl);
};

AudioLogImpl::AudioLogImpl(int owner_id,
    media::AudioLogFactory::AudioComponent component,
    content::MediaInternals* media_internals)
    : owner_id_(owner_id)
    , component_(component)
    , media_internals_(media_internals)
{
}

AudioLogImpl::~AudioLogImpl() { }

void AudioLogImpl::OnCreated(int component_id,
    const media::AudioParameters& params,
    const std::string& device_id)
{
    base::DictionaryValue dict;
    StoreComponentMetadata(component_id, &dict);

    dict.SetString(kAudioLogStatusKey, "created");
    dict.SetString("device_id", device_id);
    dict.SetString("device_type", FormatToString(params.format()));
    dict.SetInteger("frames_per_buffer", params.frames_per_buffer());
    dict.SetInteger("sample_rate", params.sample_rate());
    dict.SetInteger("channels", params.channels());
    dict.SetString("channel_layout",
        ChannelLayoutToString(params.channel_layout()));
    dict.SetString("effects", EffectsToString(params.effects()));

    media_internals_->UpdateAudioLog(MediaInternals::CREATE,
        FormatCacheKey(component_id),
        kAudioLogUpdateFunction, &dict);
}

void AudioLogImpl::OnStarted(int component_id)
{
    SendSingleStringUpdate(component_id, kAudioLogStatusKey, "started");
}

void AudioLogImpl::OnStopped(int component_id)
{
    SendSingleStringUpdate(component_id, kAudioLogStatusKey, "stopped");
}

void AudioLogImpl::OnClosed(int component_id)
{
    base::DictionaryValue dict;
    StoreComponentMetadata(component_id, &dict);
    dict.SetString(kAudioLogStatusKey, "closed");
    media_internals_->UpdateAudioLog(MediaInternals::UPDATE_AND_DELETE,
        FormatCacheKey(component_id),
        kAudioLogUpdateFunction, &dict);
}

void AudioLogImpl::OnError(int component_id)
{
    SendSingleStringUpdate(component_id, "error_occurred", "true");
}

void AudioLogImpl::OnSetVolume(int component_id, double volume)
{
    base::DictionaryValue dict;
    StoreComponentMetadata(component_id, &dict);
    dict.SetDouble("volume", volume);
    media_internals_->UpdateAudioLog(MediaInternals::UPDATE_IF_EXISTS,
        FormatCacheKey(component_id),
        kAudioLogUpdateFunction, &dict);
}

void AudioLogImpl::OnSwitchOutputDevice(int component_id,
    const std::string& device_id)
{
    base::DictionaryValue dict;
    StoreComponentMetadata(component_id, &dict);
    dict.SetString("device_id", device_id);
    media_internals_->UpdateAudioLog(MediaInternals::UPDATE_IF_EXISTS,
        FormatCacheKey(component_id),
        kAudioLogUpdateFunction, &dict);
}

void AudioLogImpl::OnLogMessage(int component_id, const std::string& message)
{
    MediaStreamManager::SendMessageToNativeLog(message);
}

void AudioLogImpl::SendWebContentsTitle(int component_id,
    int render_process_id,
    int render_frame_id)
{
    std::unique_ptr<base::DictionaryValue> dict(new base::DictionaryValue());
    StoreComponentMetadata(component_id, dict.get());
    SendWebContentsTitleHelper(FormatCacheKey(component_id), std::move(dict),
        render_process_id, render_frame_id);
}

std::string AudioLogImpl::FormatCacheKey(int component_id)
{
    return base::StringPrintf("%d:%d:%d", owner_id_, component_, component_id);
}

// static
void AudioLogImpl::SendWebContentsTitleHelper(
    const std::string& cache_key,
    std::unique_ptr<base::DictionaryValue> dict,
    int render_process_id,
    int render_frame_id)
{
    // Page title information can only be retrieved from the UI thread.
    if (!BrowserThread::CurrentlyOn(BrowserThread::UI)) {
        BrowserThread::PostTask(
            BrowserThread::UI, FROM_HERE,
            base::Bind(&SendWebContentsTitleHelper, cache_key, base::Passed(&dict),
                render_process_id, render_frame_id));
        return;
    }

    const WebContents* web_contents = WebContents::FromRenderFrameHost(
        RenderFrameHost::FromID(render_process_id, render_frame_id));
    if (!web_contents)
        return;

    // Note: by this point the given audio log entry could have been destroyed, so
    // we use UPDATE_IF_EXISTS to discard such instances.
    dict->SetInteger("render_process_id", render_process_id);
    dict->SetString("web_contents_title", web_contents->GetTitle());
    MediaInternals::GetInstance()->UpdateAudioLog(
        MediaInternals::UPDATE_IF_EXISTS, cache_key, kAudioLogUpdateFunction,
        dict.get());
}

void AudioLogImpl::SendSingleStringUpdate(int component_id,
    const std::string& key,
    const std::string& value)
{
    base::DictionaryValue dict;
    StoreComponentMetadata(component_id, &dict);
    dict.SetString(key, value);
    media_internals_->UpdateAudioLog(MediaInternals::UPDATE_IF_EXISTS,
        FormatCacheKey(component_id),
        kAudioLogUpdateFunction, &dict);
}

void AudioLogImpl::StoreComponentMetadata(int component_id,
    base::DictionaryValue* dict)
{
    dict->SetInteger("owner_id", owner_id_);
    dict->SetInteger("component_id", component_id);
    dict->SetInteger("component_type", component_);
}

// This class lives on the browser UI thread.
class MediaInternals::MediaInternalsUMAHandler {
public:
    MediaInternalsUMAHandler();

    // Called when a render process is terminated. Reports the pipeline status to
    // UMA for every player associated with the renderer process and then deletes
    // the player state.
    void OnProcessTerminated(int render_process_id);

    // Helper function to save the event payload to RendererPlayerMap.
    void SavePlayerState(int render_process_id,
        const media::MediaLogEvent& event);

private:
    struct WatchTimeInfo {
        base::TimeDelta all_watch_time = media::kNoTimestamp;
        base::TimeDelta mse_watch_time = media::kNoTimestamp;
        base::TimeDelta eme_watch_time = media::kNoTimestamp;
        base::TimeDelta src_watch_time = media::kNoTimestamp;
        base::TimeDelta ac_watch_time = media::kNoTimestamp;
        base::TimeDelta battery_watch_time = media::kNoTimestamp;
    };

    struct PipelineInfo {
        bool has_pipeline = false;
        bool has_ever_played = false;
        bool has_reached_have_enough = false;
        media::PipelineStatus last_pipeline_status = media::PIPELINE_OK;
        bool has_audio = false;
        bool has_video = false;
        bool video_dds = false;
        bool video_decoder_changed = false;
        std::string audio_codec_name;
        std::string video_codec_name;
        std::string video_decoder;
        WatchTimeInfo watch_time_info;
    };

    // Helper function to report PipelineStatus associated with a player to UMA.
    void ReportUMAForPipelineStatus(const PipelineInfo& player_info);

    // Helper to generate PipelineStatus UMA name for AudioVideo streams.
    std::string GetUMANameForAVStream(const PipelineInfo& player_info);

    // Saves the watch time info from |event| under |key| at |watch_time| if |key|
    // is present in |event.params|.
    void MaybeSaveWatchTime(const media::MediaLogEvent& event,
        const char* key,
        base::TimeDelta* watch_time)
    {
        if (!event.params.HasKey(key))
            return;

        double in_seconds;
        const bool result = event.params.GetDoubleWithoutPathExpansion(key, &in_seconds);
        DCHECK(result);
        *watch_time = base::TimeDelta::FromSecondsD(in_seconds);

        DVLOG(2) << "Saved watch time for " << key << " of " << *watch_time;
    }

    enum class FinalizeType { EVERYTHING,
        POWER_ONLY };
    void FinalizeWatchTime(bool has_video,
        WatchTimeInfo* watch_time_info,
        FinalizeType finalize_type)
    {
// Use a macro instead of a function so we can use the histogram macro (which
// checks that the uma name is a static value). We use a custom time range for
// the histogram macro to capitalize on common expected watch times.
#define MAYBE_RECORD_WATCH_TIME(uma_name, watch_time)                             \
    if (watch_time_info->watch_time != media::kNoTimestamp) {                     \
        UMA_HISTOGRAM_CUSTOM_TIMES(                                               \
            media::MediaLog::uma_name, watch_time_info->watch_time,               \
            base::TimeDelta::FromSeconds(7), base::TimeDelta::FromHours(10), 50); \
        watch_time_info->watch_time = media::kNoTimestamp;                        \
    }

        if (has_video) {
            if (finalize_type == FinalizeType::EVERYTHING) {
                MAYBE_RECORD_WATCH_TIME(kWatchTimeAudioVideoAll, all_watch_time);
                MAYBE_RECORD_WATCH_TIME(kWatchTimeAudioVideoMse, mse_watch_time);
                MAYBE_RECORD_WATCH_TIME(kWatchTimeAudioVideoEme, eme_watch_time);
                MAYBE_RECORD_WATCH_TIME(kWatchTimeAudioVideoSrc, src_watch_time);
            } else {
                DCHECK_EQ(finalize_type, FinalizeType::POWER_ONLY);
            }
            MAYBE_RECORD_WATCH_TIME(kWatchTimeAudioVideoBattery, battery_watch_time);
            MAYBE_RECORD_WATCH_TIME(kWatchTimeAudioVideoAc, ac_watch_time);
        } else {
            if (finalize_type == FinalizeType::EVERYTHING) {
                MAYBE_RECORD_WATCH_TIME(kWatchTimeAudioAll, all_watch_time);
                MAYBE_RECORD_WATCH_TIME(kWatchTimeAudioMse, mse_watch_time);
                MAYBE_RECORD_WATCH_TIME(kWatchTimeAudioEme, eme_watch_time);
                MAYBE_RECORD_WATCH_TIME(kWatchTimeAudioSrc, src_watch_time);
            } else {
                DCHECK_EQ(finalize_type, FinalizeType::POWER_ONLY);
            }
            MAYBE_RECORD_WATCH_TIME(kWatchTimeAudioBattery, battery_watch_time);
            MAYBE_RECORD_WATCH_TIME(kWatchTimeAudioAc, ac_watch_time);
        }
#undef MAYBE_RECORD_WATCH_TIME
    }

    // Key is player id.
    typedef std::map<int, PipelineInfo> PlayerInfoMap;

    // Key is renderer id.
    typedef std::map<int, PlayerInfoMap> RendererPlayerMap;

    // Stores player information per renderer.
    RendererPlayerMap renderer_info_;

    DISALLOW_COPY_AND_ASSIGN(MediaInternalsUMAHandler);
};

MediaInternals::MediaInternalsUMAHandler::MediaInternalsUMAHandler()
{
}

void MediaInternals::MediaInternalsUMAHandler::SavePlayerState(
    int render_process_id,
    const media::MediaLogEvent& event)
{
    DCHECK_CURRENTLY_ON(BrowserThread::UI);
    PlayerInfoMap& player_info = renderer_info_[render_process_id];
    switch (event.type) {
    case media::MediaLogEvent::PLAY: {
        player_info[event.id].has_ever_played = true;
        break;
    }
    case media::MediaLogEvent::PIPELINE_STATE_CHANGED: {
        player_info[event.id].has_pipeline = true;
        break;
    }
    case media::MediaLogEvent::PIPELINE_ERROR: {
        int status;
        event.params.GetInteger("pipeline_error", &status);
        player_info[event.id].last_pipeline_status = static_cast<media::PipelineStatus>(status);
        break;
    }
    case media::MediaLogEvent::PROPERTY_CHANGE:
        if (event.params.HasKey("found_audio_stream")) {
            event.params.GetBoolean("found_audio_stream",
                &player_info[event.id].has_audio);
        }
        if (event.params.HasKey("found_video_stream")) {
            event.params.GetBoolean("found_video_stream",
                &player_info[event.id].has_video);
        }
        if (event.params.HasKey("audio_codec_name")) {
            event.params.GetString("audio_codec_name",
                &player_info[event.id].audio_codec_name);
        }
        if (event.params.HasKey("video_codec_name")) {
            event.params.GetString("video_codec_name",
                &player_info[event.id].video_codec_name);
        }
        if (event.params.HasKey("video_decoder")) {
            std::string previous_video_decoder(player_info[event.id].video_decoder);
            event.params.GetString("video_decoder",
                &player_info[event.id].video_decoder);
            if (!previous_video_decoder.empty() && previous_video_decoder != player_info[event.id].video_decoder) {
                player_info[event.id].video_decoder_changed = true;
            }
        }
        if (event.params.HasKey("video_dds")) {
            event.params.GetBoolean("video_dds", &player_info[event.id].video_dds);
        }
        if (event.params.HasKey("pipeline_buffering_state")) {
            std::string buffering_state;
            event.params.GetString("pipeline_buffering_state", &buffering_state);
            if (buffering_state == "BUFFERING_HAVE_ENOUGH")
                player_info[event.id].has_reached_have_enough = true;
        }
        break;
    case media::MediaLogEvent::Type::WATCH_TIME_UPDATE: {
        DVLOG(2) << "Processing watch time update.";
        PipelineInfo& info = player_info[event.id];
        WatchTimeInfo& wti = info.watch_time_info;
        // Save audio only watch time information.
        MaybeSaveWatchTime(event, media::MediaLog::kWatchTimeAudioAll,
            &wti.all_watch_time);
        MaybeSaveWatchTime(event, media::MediaLog::kWatchTimeAudioMse,
            &wti.mse_watch_time);
        MaybeSaveWatchTime(event, media::MediaLog::kWatchTimeAudioEme,
            &wti.eme_watch_time);
        MaybeSaveWatchTime(event, media::MediaLog::kWatchTimeAudioSrc,
            &wti.src_watch_time);
        MaybeSaveWatchTime(event, media::MediaLog::kWatchTimeAudioBattery,
            &wti.battery_watch_time);
        MaybeSaveWatchTime(event, media::MediaLog::kWatchTimeAudioAc,
            &wti.ac_watch_time);

        // Save audio+video watch time information.
        MaybeSaveWatchTime(event, media::MediaLog::kWatchTimeAudioVideoAll,
            &wti.all_watch_time);
        MaybeSaveWatchTime(event, media::MediaLog::kWatchTimeAudioVideoMse,
            &wti.mse_watch_time);
        MaybeSaveWatchTime(event, media::MediaLog::kWatchTimeAudioVideoEme,
            &wti.eme_watch_time);
        MaybeSaveWatchTime(event, media::MediaLog::kWatchTimeAudioVideoSrc,
            &wti.src_watch_time);
        MaybeSaveWatchTime(event, media::MediaLog::kWatchTimeAudioVideoBattery,
            &wti.battery_watch_time);
        MaybeSaveWatchTime(event, media::MediaLog::kWatchTimeAudioVideoAc,
            &wti.ac_watch_time);

        if (event.params.HasKey(media::MediaLog::kWatchTimeFinalize)) {
            bool should_finalize;
            DCHECK(event.params.GetBoolean(media::MediaLog::kWatchTimeFinalize,
                       &should_finalize)
                && should_finalize);
            FinalizeWatchTime(info.has_video, &wti, FinalizeType::EVERYTHING);
        } else if (event.params.HasKey(
                       media::MediaLog::kWatchTimeFinalizePower)) {
            bool should_finalize;
            DCHECK(event.params.GetBoolean(media::MediaLog::kWatchTimeFinalizePower,
                       &should_finalize)
                && should_finalize);
            FinalizeWatchTime(info.has_video, &wti, FinalizeType::POWER_ONLY);
        }
        break;
    }
    case media::MediaLogEvent::Type::WEBMEDIAPLAYER_DESTROYED: {
        // Upon player destruction report UMA data; if the player is not torn down
        // before process exit, it will be logged during OnProcessTerminated().
        auto it = player_info.find(event.id);
        if (it == player_info.end())
            break;

        ReportUMAForPipelineStatus(it->second);
        player_info.erase(it);
    }
    default:
        break;
    }
    return;
}

std::string MediaInternals::MediaInternalsUMAHandler::GetUMANameForAVStream(
    const PipelineInfo& player_info)
{
    DCHECK_CURRENTLY_ON(BrowserThread::UI);
    static const char kPipelineUmaPrefix[] = "Media.PipelineStatus.AudioVideo.";
    std::string uma_name = kPipelineUmaPrefix;
    if (player_info.video_codec_name == "vp8") {
        uma_name += "VP8.";
    } else if (player_info.video_codec_name == "vp9") {
        uma_name += "VP9.";
    } else if (player_info.video_codec_name == "h264") {
        uma_name += "H264.";
    } else {
        return uma_name + "Other";
    }

#if !defined(OS_ANDROID)
    if (player_info.video_decoder == media::DecryptingVideoDecoder::kDecoderName) {
        return uma_name + "DVD";
    }
#endif

    if (player_info.video_dds) {
        uma_name += "DDS.";
    }

    if (player_info.video_decoder == media::GpuVideoDecoder::kDecoderName) {
        uma_name += "HW";
    } else {
        uma_name += "SW";
    }
    return uma_name;
}

void MediaInternals::MediaInternalsUMAHandler::ReportUMAForPipelineStatus(
    const PipelineInfo& player_info)
{
    DCHECK_CURRENTLY_ON(BrowserThread::UI);

    // Don't log pipeline status for players which don't actually have a pipeline;
    // e.g., the Android MediaSourcePlayer implementation.
    if (!player_info.has_pipeline)
        return;

    if (player_info.has_video && player_info.has_audio) {
        base::LinearHistogram::FactoryGet(
            GetUMANameForAVStream(player_info), 1, media::PIPELINE_STATUS_MAX,
            media::PIPELINE_STATUS_MAX + 1,
            base::HistogramBase::kUmaTargetedHistogramFlag)
            ->Add(player_info.last_pipeline_status);
    } else if (player_info.has_audio) {
        UMA_HISTOGRAM_ENUMERATION("Media.PipelineStatus.AudioOnly",
            player_info.last_pipeline_status,
            media::PIPELINE_STATUS_MAX + 1);
    } else if (player_info.has_video) {
        UMA_HISTOGRAM_ENUMERATION("Media.PipelineStatus.VideoOnly",
            player_info.last_pipeline_status,
            media::PIPELINE_STATUS_MAX + 1);
    } else {
        // Note: This metric can be recorded as a result of normal operation with
        // Media Source Extensions. If a site creates a MediaSource object but never
        // creates a source buffer or appends data, PIPELINE_OK will be recorded.
        UMA_HISTOGRAM_ENUMERATION("Media.PipelineStatus.Unsupported",
            player_info.last_pipeline_status,
            media::PIPELINE_STATUS_MAX + 1);
    }
    // Report whether video decoder fallback happened, but only if a video decoder
    // was reported.
    if (!player_info.video_decoder.empty()) {
        UMA_HISTOGRAM_BOOLEAN("Media.VideoDecoderFallback",
            player_info.video_decoder_changed);
    }

    // Report whether this player ever saw a playback event. Used to measure the
    // effectiveness of efforts to reduce loaded-but-never-used players.
    if (player_info.has_reached_have_enough)
        UMA_HISTOGRAM_BOOLEAN("Media.HasEverPlayed", player_info.has_ever_played);
}

void MediaInternals::MediaInternalsUMAHandler::OnProcessTerminated(
    int render_process_id)
{
    DCHECK_CURRENTLY_ON(BrowserThread::UI);

    auto players_it = renderer_info_.find(render_process_id);
    if (players_it == renderer_info_.end())
        return;
    auto it = players_it->second.begin();
    while (it != players_it->second.end()) {
        ReportUMAForPipelineStatus(it->second);
        FinalizeWatchTime(it->second.has_video, &(it->second.watch_time_info),
            FinalizeType::EVERYTHING);
        players_it->second.erase(it++);
    }
    renderer_info_.erase(players_it);
}

MediaInternals* MediaInternals::GetInstance()
{
    return g_media_internals.Pointer();
}

MediaInternals::MediaInternals()
    : can_update_(false)
    , owner_ids_()
    , uma_handler_(new MediaInternalsUMAHandler())
{
    registrar_.Add(this, NOTIFICATION_RENDERER_PROCESS_TERMINATED,
        NotificationService::AllBrowserContextsAndSources());
}

MediaInternals::~MediaInternals() { }

void MediaInternals::Observe(int type,
    const NotificationSource& source,
    const NotificationDetails& details)
{
    DCHECK_CURRENTLY_ON(BrowserThread::UI);
    DCHECK_EQ(type, NOTIFICATION_RENDERER_PROCESS_TERMINATED);
    RenderProcessHost* process = Source<RenderProcessHost>(source).ptr();

    uma_handler_->OnProcessTerminated(process->GetID());
    saved_events_by_process_.erase(process->GetID());
}

// Converts the |event| to a |update|. Returns whether the conversion succeeded.
static bool ConvertEventToUpdate(int render_process_id,
    const media::MediaLogEvent& event,
    base::string16* update)
{
    DCHECK(update);

    base::DictionaryValue dict;
    dict.SetInteger("renderer", render_process_id);
    dict.SetInteger("player", event.id);
    dict.SetString("type", media::MediaLog::EventTypeToString(event.type));

    // TODO(dalecurtis): This is technically not correct.  TimeTicks "can't" be
    // converted to to a human readable time format.  See base/time/time.h.
    const double ticks = event.time.ToInternalValue();
    const double ticks_millis = ticks / base::Time::kMicrosecondsPerMillisecond;
    dict.SetDouble("ticksMillis", ticks_millis);

    // Convert PipelineStatus to human readable string
    if (event.type == media::MediaLogEvent::PIPELINE_ERROR) {
        int status;
        if (!event.params.GetInteger("pipeline_error", &status) || status < static_cast<int>(media::PIPELINE_OK) || status > static_cast<int>(media::PIPELINE_STATUS_MAX)) {
            return false;
        }
        media::PipelineStatus error = static_cast<media::PipelineStatus>(status);
        dict.SetString("params.pipeline_error",
            media::MediaLog::PipelineStatusToString(error));
    } else {
        dict.Set("params", event.params.DeepCopy());
    }

    *update = SerializeUpdate("media.onMediaEvent", &dict);
    return true;
}

void MediaInternals::OnMediaEvents(
    int render_process_id, const std::vector<media::MediaLogEvent>& events)
{
    DCHECK_CURRENTLY_ON(BrowserThread::UI);
    // Notify observers that |event| has occurred.
    for (const auto& event : events) {
        // Some events should not be recorded in the UI.
        if (event.type != media::MediaLogEvent::Type::WATCH_TIME_UPDATE) {
            if (CanUpdate()) {
                base::string16 update;
                if (ConvertEventToUpdate(render_process_id, event, &update))
                    SendUpdate(update);
            }
            SaveEvent(render_process_id, event);
        }
        uma_handler_->SavePlayerState(render_process_id, event);
    }
}

void MediaInternals::AddUpdateCallback(const UpdateCallback& callback)
{
    DCHECK_CURRENTLY_ON(BrowserThread::UI);
    update_callbacks_.push_back(callback);

    base::AutoLock auto_lock(lock_);
    can_update_ = true;
}

void MediaInternals::RemoveUpdateCallback(const UpdateCallback& callback)
{
    DCHECK_CURRENTLY_ON(BrowserThread::UI);
    for (size_t i = 0; i < update_callbacks_.size(); ++i) {
        if (update_callbacks_[i].Equals(callback)) {
            update_callbacks_.erase(update_callbacks_.begin() + i);
            break;
        }
    }

    base::AutoLock auto_lock(lock_);
    can_update_ = !update_callbacks_.empty();
}

bool MediaInternals::CanUpdate()
{
    base::AutoLock auto_lock(lock_);
    return can_update_;
}

void MediaInternals::SendHistoricalMediaEvents()
{
    DCHECK_CURRENTLY_ON(BrowserThread::UI);
    for (const auto& saved_events : saved_events_by_process_) {
        for (const auto& event : saved_events.second) {
            base::string16 update;
            if (ConvertEventToUpdate(saved_events.first, event, &update))
                SendUpdate(update);
        }
    }
    // Do not clear the map/list here so that refreshing the UI or opening a
    // second UI still works nicely!
}

void MediaInternals::SendAudioStreamData()
{
    base::string16 audio_stream_update;
    {
        base::AutoLock auto_lock(lock_);
        audio_stream_update = SerializeUpdate(
            "media.onReceiveAudioStreamData", &audio_streams_cached_data_);
    }
    SendUpdate(audio_stream_update);
}

void MediaInternals::SendVideoCaptureDeviceCapabilities()
{
    DCHECK_CURRENTLY_ON(BrowserThread::IO);

    if (!CanUpdate())
        return;

    SendUpdate(SerializeUpdate("media.onReceiveVideoCaptureCapabilities",
        &video_capture_capabilities_cached_data_));
}

void MediaInternals::UpdateVideoCaptureDeviceCapabilities(
    const std::vector<std::tuple<media::VideoCaptureDeviceDescriptor,
        media::VideoCaptureFormats>>&
        descriptors_and_formats)
{
    DCHECK_CURRENTLY_ON(BrowserThread::IO);
    video_capture_capabilities_cached_data_.Clear();

    for (const auto& device_format_pair : descriptors_and_formats) {
        base::ListValue* format_list = new base::ListValue();
        // TODO(nisse): Representing format information as a string, to be
        // parsed by the javascript handler, is brittle. Consider passing
        // a list of mappings instead.

        const media::VideoCaptureDeviceDescriptor& descriptor = std::get<0>(device_format_pair);
        const media::VideoCaptureFormats& supported_formats = std::get<1>(device_format_pair);
        for (const auto& format : supported_formats)
            format_list->AppendString(media::VideoCaptureFormat::ToString(format));

        std::unique_ptr<base::DictionaryValue> device_dict(
            new base::DictionaryValue());
        device_dict->SetString("id", descriptor.device_id);
        device_dict->SetString("name", descriptor.GetNameAndModel());
        device_dict->Set("formats", format_list);
#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_ANDROID)
        device_dict->SetString("captureApi", descriptor.GetCaptureApiTypeString());
#endif
        video_capture_capabilities_cached_data_.Append(std::move(device_dict));
    }

    SendVideoCaptureDeviceCapabilities();
}

std::unique_ptr<media::AudioLog> MediaInternals::CreateAudioLog(
    AudioComponent component)
{
    base::AutoLock auto_lock(lock_);
    return std::unique_ptr<media::AudioLog>(
        new AudioLogImpl(owner_ids_[component]++, component, this));
}

void MediaInternals::SetWebContentsTitleForAudioLogEntry(
    int component_id,
    int render_process_id,
    int render_frame_id,
    media::AudioLog* audio_log)
{
    static_cast<AudioLogImpl*>(audio_log)
        ->SendWebContentsTitle(component_id, render_process_id, render_frame_id);
}

void MediaInternals::SendUpdate(const base::string16& update)
{
    // SendUpdate() may be called from any thread, but must run on the UI thread.
    if (!BrowserThread::CurrentlyOn(BrowserThread::UI)) {
        BrowserThread::PostTask(BrowserThread::UI, FROM_HERE, base::Bind(&MediaInternals::SendUpdate, base::Unretained(this), update));
        return;
    }

    for (size_t i = 0; i < update_callbacks_.size(); i++)
        update_callbacks_[i].Run(update);
}

void MediaInternals::SaveEvent(int process_id,
    const media::MediaLogEvent& event)
{
    DCHECK_CURRENTLY_ON(BrowserThread::UI);

    // Do not save instantaneous events that happen frequently and have little
    // value in the future.
    if (event.type == media::MediaLogEvent::NETWORK_ACTIVITY_SET || event.type == media::MediaLogEvent::BUFFERED_EXTENTS_CHANGED) {
        return;
    }

    // Save the event and limit the total number per renderer. At the time of
    // writing, 512 events of the kind: { "property": value } together consume
    // ~88kb of memory on linux.
    std::list<media::MediaLogEvent>& saved_events = saved_events_by_process_[process_id];
    saved_events.push_back(event);
    if (saved_events.size() > 512) {
        // Remove all events for a given player as soon as we have to remove a
        // single event for that player to avoid showing incomplete players.
        int id_to_remove = saved_events.front().id;
        auto new_end = std::remove_if(saved_events.begin(), saved_events.end(),
            [&](const media::MediaLogEvent& event) {
                return event.id == id_to_remove;
            });
        saved_events.erase(new_end, saved_events.end());
    }
}

void MediaInternals::UpdateAudioLog(AudioLogUpdateType type,
    const std::string& cache_key,
    const std::string& function,
    const base::DictionaryValue* value)
{
    {
        base::AutoLock auto_lock(lock_);
        const bool has_entry = audio_streams_cached_data_.HasKey(cache_key);
        if ((type == UPDATE_IF_EXISTS || type == UPDATE_AND_DELETE) && !has_entry) {
            return;
        } else if (!has_entry) {
            DCHECK_EQ(type, CREATE);
            audio_streams_cached_data_.Set(cache_key, value->DeepCopy());
        } else if (type == UPDATE_AND_DELETE) {
            std::unique_ptr<base::Value> out_value;
            CHECK(audio_streams_cached_data_.Remove(cache_key, &out_value));
        } else {
            base::DictionaryValue* existing_dict = NULL;
            CHECK(
                audio_streams_cached_data_.GetDictionary(cache_key, &existing_dict));
            existing_dict->MergeDictionary(value);
        }
    }

    if (CanUpdate())
        SendUpdate(SerializeUpdate(function, value));
}

} // namespace content
