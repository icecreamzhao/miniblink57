// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "media/base/media_tracks.h"

#include "base/bind.h"
#include "base/memory/ptr_util.h"
#include "media/base/audio_decoder_config.h"
#include "media/base/video_decoder_config.h"

namespace media {

MediaTracks::MediaTracks() { }

MediaTracks::~MediaTracks() { }

MediaTrack* MediaTracks::AddAudioTrack(
    const AudioDecoderConfig& config,
    StreamParser::TrackId bytestream_track_id,
    const std::string& kind,
    const std::string& label,
    const std::string& language)
{
    DCHECK(config.IsValidConfig());
    CHECK(audio_configs_.find(bytestream_track_id) == audio_configs_.end());
    std::unique_ptr<MediaTrack> track = base::MakeUnique<MediaTrack>(
        MediaTrack::Audio, bytestream_track_id, kind, label, language);
    MediaTrack* track_ptr = track.get();
    tracks_.push_back(std::move(track));
    audio_configs_[bytestream_track_id] = config;
    return track_ptr;
}

MediaTrack* MediaTracks::AddVideoTrack(
    const VideoDecoderConfig& config,
    StreamParser::TrackId bytestream_track_id,
    const std::string& kind,
    const std::string& label,
    const std::string& language)
{
    DCHECK(config.IsValidConfig());
    CHECK(video_configs_.find(bytestream_track_id) == video_configs_.end());
    std::unique_ptr<MediaTrack> track = base::MakeUnique<MediaTrack>(
        MediaTrack::Video, bytestream_track_id, kind, label, language);
    MediaTrack* track_ptr = track.get();
    tracks_.push_back(std::move(track));
    video_configs_[bytestream_track_id] = config;
    return track_ptr;
}

const AudioDecoderConfig& MediaTracks::getAudioConfig(
    StreamParser::TrackId bytestream_track_id) const
{
    auto it = audio_configs_.find(bytestream_track_id);
    if (it != audio_configs_.end())
        return it->second;
    static AudioDecoderConfig invalidConfig;
    return invalidConfig;
}

const VideoDecoderConfig& MediaTracks::getVideoConfig(
    StreamParser::TrackId bytestream_track_id) const
{
    auto it = video_configs_.find(bytestream_track_id);
    if (it != video_configs_.end())
        return it->second;
    static VideoDecoderConfig invalidConfig;
    return invalidConfig;
}

} // namespace media
