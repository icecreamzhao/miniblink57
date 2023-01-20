/*
 * Copyright (C) 2011 Google Inc. All rights reserved.
 * Copyright (C) 2011 Ericsson AB. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
<<<<<<< HEAD
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

=======
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
>>>>>>> miniblink49
#include "modules/mediastream/MediaStreamTrack.h"

#include "bindings/core/v8/ExceptionMessages.h"
#include "core/dom/Document.h"
#include "core/dom/ExceptionCode.h"
#include "core/dom/ExecutionContext.h"
#include "core/events/Event.h"
<<<<<<< HEAD
#include "core/frame/Deprecation.h"
#include "modules/mediastream/MediaConstraintsImpl.h"
#include "modules/mediastream/MediaStream.h"
#include "modules/mediastream/MediaTrackSettings.h"
#include "modules/mediastream/UserMediaController.h"
#include "platform/mediastream/MediaStreamCenter.h"
#include "platform/mediastream/MediaStreamComponent.h"
#include "public/platform/WebMediaStreamTrack.h"
#include "wtf/Assertions.h"
#include <memory>

namespace blink {

namespace {
    static const char kContentHintStringNone[] = "";
    static const char kContentHintStringAudioSpeech[] = "speech";
    static const char kContentHintStringAudioMusic[] = "music";
    static const char kContentHintStringVideoMotion[] = "motion";
    static const char kContentHintStringVideoDetail[] = "detail";
} // namespace

MediaStreamTrack* MediaStreamTrack::create(ExecutionContext* context,
    MediaStreamComponent* component)
{
    return new MediaStreamTrack(context, component);
}

MediaStreamTrack::MediaStreamTrack(ExecutionContext* context,
    MediaStreamComponent* component)
    : ContextLifecycleObserver(context)
=======
#include "modules/mediastream/MediaStream.h"
#include "modules/mediastream/MediaStreamTrackSourcesCallback.h"
#include "modules/mediastream/MediaStreamTrackSourcesRequestImpl.h"
#include "modules/mediastream/UserMediaController.h"
#include "platform/mediastream/MediaStreamCenter.h"
#include "platform/mediastream/MediaStreamComponent.h"
#include "public/platform/WebSourceInfo.h"

namespace blink {

MediaStreamTrack* MediaStreamTrack::create(ExecutionContext* context, MediaStreamComponent* component)
{
    MediaStreamTrack* track = new MediaStreamTrack(context, component);
    track->suspendIfNeeded();
    return track;
}

MediaStreamTrack::MediaStreamTrack(ExecutionContext* context, MediaStreamComponent* component)
    : ActiveDOMObject(context)
>>>>>>> miniblink49
    , m_readyState(MediaStreamSource::ReadyStateLive)
    , m_isIteratingRegisteredMediaStreams(false)
    , m_stopped(false)
    , m_component(component)
<<<<<<< HEAD
    ,
    // The source's constraints aren't yet initialized at creation time.
    m_constraints()
=======
>>>>>>> miniblink49
{
    m_component->source()->addObserver(this);
}

<<<<<<< HEAD
MediaStreamTrack::~MediaStreamTrack() { }
=======
MediaStreamTrack::~MediaStreamTrack()
{
    m_component->source()->removeObserver(this);
}
>>>>>>> miniblink49

String MediaStreamTrack::kind() const
{
    DEFINE_STATIC_LOCAL(String, audioKind, ("audio"));
    DEFINE_STATIC_LOCAL(String, videoKind, ("video"));

    switch (m_component->source()->type()) {
    case MediaStreamSource::TypeAudio:
        return audioKind;
    case MediaStreamSource::TypeVideo:
        return videoKind;
    }

<<<<<<< HEAD
    NOTREACHED();
=======
    ASSERT_NOT_REACHED();
>>>>>>> miniblink49
    return audioKind;
}

String MediaStreamTrack::id() const
{
    return m_component->id();
}

String MediaStreamTrack::label() const
{
    return m_component->source()->name();
}

bool MediaStreamTrack::enabled() const
{
    return m_component->enabled();
}

void MediaStreamTrack::setEnabled(bool enabled)
{
    if (enabled == m_component->enabled())
        return;

    m_component->setEnabled(enabled);

    if (!ended())
<<<<<<< HEAD
        MediaStreamCenter::instance().didSetMediaStreamTrackEnabled(
            m_component.get());
=======
        MediaStreamCenter::instance().didSetMediaStreamTrackEnabled(m_component.get());
>>>>>>> miniblink49
}

bool MediaStreamTrack::muted() const
{
    return m_component->muted();
}

<<<<<<< HEAD
String MediaStreamTrack::contentHint() const
{
    WebMediaStreamTrack::ContentHintType hint = m_component->contentHint();
    switch (hint) {
    case WebMediaStreamTrack::ContentHintType::None:
        return kContentHintStringNone;
    case WebMediaStreamTrack::ContentHintType::AudioSpeech:
        return kContentHintStringAudioSpeech;
    case WebMediaStreamTrack::ContentHintType::AudioMusic:
        return kContentHintStringAudioMusic;
    case WebMediaStreamTrack::ContentHintType::VideoMotion:
        return kContentHintStringVideoMotion;
    case WebMediaStreamTrack::ContentHintType::VideoDetail:
        return kContentHintStringVideoDetail;
    }

    NOTREACHED();
    return String();
}

void MediaStreamTrack::setContentHint(const String& hint)
{
    WebMediaStreamTrack::ContentHintType translatedHint = WebMediaStreamTrack::ContentHintType::None;
    switch (m_component->source()->type()) {
    case MediaStreamSource::TypeAudio:
        if (hint == kContentHintStringNone) {
            translatedHint = WebMediaStreamTrack::ContentHintType::None;
        } else if (hint == kContentHintStringAudioSpeech) {
            translatedHint = WebMediaStreamTrack::ContentHintType::AudioSpeech;
        } else if (hint == kContentHintStringAudioMusic) {
            translatedHint = WebMediaStreamTrack::ContentHintType::AudioMusic;
        } else {
            // TODO(pbos): Log warning?
            // Invalid values for audio are to be ignored (similar to invalid enum
            // values).
            return;
        }
        break;
    case MediaStreamSource::TypeVideo:
        if (hint == kContentHintStringNone) {
            translatedHint = WebMediaStreamTrack::ContentHintType::None;
        } else if (hint == kContentHintStringVideoMotion) {
            translatedHint = WebMediaStreamTrack::ContentHintType::VideoMotion;
        } else if (hint == kContentHintStringVideoDetail) {
            translatedHint = WebMediaStreamTrack::ContentHintType::VideoDetail;
        } else {
            // TODO(pbos): Log warning?
            // Invalid values for video are to be ignored (similar to invalid enum
            // values).
            return;
        }
    }

    m_component->setContentHint(translatedHint);
}

=======
>>>>>>> miniblink49
bool MediaStreamTrack::remote() const
{
    return m_component->source()->remote();
}

<<<<<<< HEAD
=======
bool MediaStreamTrack::readonly() const
{
    return m_component->source()->readonly();
}

>>>>>>> miniblink49
String MediaStreamTrack::readyState() const
{
    if (ended())
        return "ended";

    switch (m_readyState) {
    case MediaStreamSource::ReadyStateLive:
        return "live";
    case MediaStreamSource::ReadyStateMuted:
        return "muted";
    case MediaStreamSource::ReadyStateEnded:
        return "ended";
    }

<<<<<<< HEAD
    NOTREACHED();
    return String();
}

=======
    ASSERT_NOT_REACHED();
    return String();
}

void MediaStreamTrack::getSources(ExecutionContext* context, MediaStreamTrackSourcesCallback* callback, ExceptionState& exceptionState)
{
    LocalFrame* frame = toDocument(context)->frame();
    UserMediaController* userMedia = UserMediaController::from(frame);
    if (!userMedia) {
        exceptionState.throwDOMException(NotSupportedError, "No sources controller available; is this a detached window?");
        return;
    }
    MediaStreamTrackSourcesRequest* request = MediaStreamTrackSourcesRequestImpl::create(*context, callback);
    userMedia->requestSources(request);
}

>>>>>>> miniblink49
void MediaStreamTrack::stopTrack(ExceptionState& exceptionState)
{
    if (ended())
        return;

    m_readyState = MediaStreamSource::ReadyStateEnded;
    MediaStreamCenter::instance().didStopMediaStreamTrack(component());
    dispatchEvent(Event::create(EventTypeNames::ended));
    propagateTrackEnded();
}

MediaStreamTrack* MediaStreamTrack::clone(ExecutionContext* context)
{
<<<<<<< HEAD
    // TODO(pbos): Make sure m_readyState and m_stopped carries over on cloned
    // tracks.
    MediaStreamComponent* clonedComponent = component()->clone();
    MediaStreamTrack* clonedTrack = MediaStreamTrack::create(context, clonedComponent);
    MediaStreamCenter::instance().didCreateMediaStreamTrack(clonedComponent);
    return clonedTrack;
}

void MediaStreamTrack::getConstraints(MediaTrackConstraints& constraints)
{
    MediaConstraintsImpl::convertConstraints(m_constraints, constraints);
}

void MediaStreamTrack::setConstraints(const WebMediaConstraints& constraints)
{
    m_constraints = constraints;
}

void MediaStreamTrack::getSettings(MediaTrackSettings& settings)
{
    WebMediaStreamTrack::Settings platformSettings;
    m_component->getSettings(platformSettings);
    if (platformSettings.hasFrameRate()) {
        settings.setFrameRate(platformSettings.frameRate);
    }
    if (platformSettings.hasWidth()) {
        settings.setWidth(platformSettings.width);
    }
    if (platformSettings.hasHeight()) {
        settings.setHeight(platformSettings.height);
    }
    settings.setDeviceId(platformSettings.deviceId);
    if (platformSettings.hasFacingMode()) {
        switch (platformSettings.facingMode) {
        case WebMediaStreamTrack::FacingMode::User:
            settings.setFacingMode("user");
            break;
        case WebMediaStreamTrack::FacingMode::Environment:
            settings.setFacingMode("environment");
            break;
        case WebMediaStreamTrack::FacingMode::Left:
            settings.setFacingMode("left");
            break;
        case WebMediaStreamTrack::FacingMode::Right:
            settings.setFacingMode("right");
            break;
        default:
            // None, or unknown facing mode. Ignore.
            break;
        }
    }
}

=======
    RefPtr<MediaStreamComponent> clonedComponent = MediaStreamComponent::create(component()->source());
    MediaStreamTrack* clonedTrack = MediaStreamTrack::create(context, clonedComponent.get());
    MediaStreamCenter::instance().didCreateMediaStreamTrack(clonedComponent.get());
    return clonedTrack;
}

>>>>>>> miniblink49
bool MediaStreamTrack::ended() const
{
    return m_stopped || (m_readyState == MediaStreamSource::ReadyStateEnded);
}

void MediaStreamTrack::sourceChangedState()
{
    if (ended())
        return;

<<<<<<< HEAD
    m_readyState = m_component->source()->getReadyState();
=======
    m_readyState = m_component->source()->readyState();
>>>>>>> miniblink49
    switch (m_readyState) {
    case MediaStreamSource::ReadyStateLive:
        m_component->setMuted(false);
        dispatchEvent(Event::create(EventTypeNames::unmute));
        break;
    case MediaStreamSource::ReadyStateMuted:
        m_component->setMuted(true);
        dispatchEvent(Event::create(EventTypeNames::mute));
        break;
    case MediaStreamSource::ReadyStateEnded:
        dispatchEvent(Event::create(EventTypeNames::ended));
        propagateTrackEnded();
        break;
    }
}

void MediaStreamTrack::propagateTrackEnded()
{
<<<<<<< HEAD
    CHECK(!m_isIteratingRegisteredMediaStreams);
    m_isIteratingRegisteredMediaStreams = true;
    for (HeapHashSet<Member<MediaStream>>::iterator iter = m_registeredMediaStreams.begin();
         iter != m_registeredMediaStreams.end(); ++iter)
=======
    RELEASE_ASSERT(!m_isIteratingRegisteredMediaStreams);
    m_isIteratingRegisteredMediaStreams = true;
    for (HeapHashSet<Member<MediaStream>>::iterator iter = m_registeredMediaStreams.begin(); iter != m_registeredMediaStreams.end(); ++iter)
>>>>>>> miniblink49
        (*iter)->trackEnded();
    m_isIteratingRegisteredMediaStreams = false;
}

<<<<<<< HEAD
void MediaStreamTrack::contextDestroyed(ExecutionContext*)
=======
MediaStreamComponent* MediaStreamTrack::component()
{
    return m_component.get();
}

void MediaStreamTrack::stop()
>>>>>>> miniblink49
{
    m_stopped = true;
}

<<<<<<< HEAD
bool MediaStreamTrack::hasPendingActivity() const
{
    // If 'ended' listeners exist and the object hasn't yet reached
    // that state, keep the object alive.
    //
    // An otherwise unreachable MediaStreamTrack object in an non-ended
    // state will otherwise indirectly be transitioned to the 'ended' state
    // while finalizing m_component. Which dispatches an 'ended' event,
    // referring to this object as the target. If this object is then GCed
    // at the same time, v8 objects will retain (wrapper) references to
    // this dead MediaStreamTrack object. Bad.
    //
    // Hence insisting on keeping this object alive until the 'ended'
    // state has been reached & handled.
    return !ended() && hasEventListeners(EventTypeNames::ended);
}

std::unique_ptr<AudioSourceProvider> MediaStreamTrack::createWebAudioSource()
{
    return MediaStreamCenter::instance().createWebAudioSourceFromMediaStreamTrack(
        component());
=======
PassOwnPtr<AudioSourceProvider> MediaStreamTrack::createWebAudioSource()
{
    return MediaStreamCenter::instance().createWebAudioSourceFromMediaStreamTrack(component());
>>>>>>> miniblink49
}

void MediaStreamTrack::registerMediaStream(MediaStream* mediaStream)
{
<<<<<<< HEAD
    CHECK(!m_isIteratingRegisteredMediaStreams);
    CHECK(!m_registeredMediaStreams.contains(mediaStream));
=======
    RELEASE_ASSERT(!m_isIteratingRegisteredMediaStreams);
    RELEASE_ASSERT(!m_registeredMediaStreams.contains(mediaStream));
>>>>>>> miniblink49
    m_registeredMediaStreams.add(mediaStream);
}

void MediaStreamTrack::unregisterMediaStream(MediaStream* mediaStream)
{
<<<<<<< HEAD
    CHECK(!m_isIteratingRegisteredMediaStreams);
    HeapHashSet<Member<MediaStream>>::iterator iter = m_registeredMediaStreams.find(mediaStream);
    CHECK(iter != m_registeredMediaStreams.end());
=======
    RELEASE_ASSERT(!m_isIteratingRegisteredMediaStreams);
    HeapHashSet<Member<MediaStream>>::iterator iter = m_registeredMediaStreams.find(mediaStream);
    RELEASE_ASSERT(iter != m_registeredMediaStreams.end());
>>>>>>> miniblink49
    m_registeredMediaStreams.remove(iter);
}

const AtomicString& MediaStreamTrack::interfaceName() const
{
    return EventTargetNames::MediaStreamTrack;
}

<<<<<<< HEAD
ExecutionContext* MediaStreamTrack::getExecutionContext() const
{
    return ContextLifecycleObserver::getExecutionContext();
=======
ExecutionContext* MediaStreamTrack::executionContext() const
{
    return ActiveDOMObject::executionContext();
>>>>>>> miniblink49
}

DEFINE_TRACE(MediaStreamTrack)
{
    visitor->trace(m_registeredMediaStreams);
<<<<<<< HEAD
    visitor->trace(m_component);
    EventTargetWithInlineData::trace(visitor);
    ContextLifecycleObserver::trace(visitor);
=======
    RefCountedGarbageCollectedEventTargetWithInlineData<MediaStreamTrack>::trace(visitor);
    ActiveDOMObject::trace(visitor);
>>>>>>> miniblink49
}

} // namespace blink
