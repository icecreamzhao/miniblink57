/*
 * Copyright (C) 2013 Google Inc. All rights reserved.
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
#include "public/platform/WebMediaStreamTrack.h"

#include "platform/mediastream/MediaStreamComponent.h"
#include "platform/mediastream/MediaStreamSource.h"
#include "public/platform/WebAudioSourceProvider.h"
#include "public/platform/WebMediaStream.h"
#include "public/platform/WebMediaStreamSource.h"
#include "public/platform/WebString.h"
<<<<<<< HEAD
#include "wtf/PtrUtil.h"
#include <memory>
=======
>>>>>>> miniblink49

namespace blink {

namespace {

<<<<<<< HEAD
    class TrackDataContainer : public MediaStreamComponent::TrackData {
    public:
        explicit TrackDataContainer(
            std::unique_ptr<WebMediaStreamTrack::TrackData> extraData)
            : m_extraData(std::move(extraData))
        {
        }

        WebMediaStreamTrack::TrackData* getTrackData() { return m_extraData.get(); }
        void getSettings(WebMediaStreamTrack::Settings& settings)
        {
            m_extraData->getSettings(settings);
        }

    private:
        std::unique_ptr<WebMediaStreamTrack::TrackData> m_extraData;
    };

} // namespace

WebMediaStreamTrack::WebMediaStreamTrack(
    MediaStreamComponent* mediaStreamComponent)
=======
class ExtraDataContainer : public MediaStreamComponent::ExtraData {
public:
    explicit ExtraDataContainer(PassOwnPtr<WebMediaStreamTrack::ExtraData> extraData) : m_extraData(extraData) { }

    WebMediaStreamTrack::ExtraData* extraData() { return m_extraData.get(); }

private:
    OwnPtr<WebMediaStreamTrack::ExtraData> m_extraData;
};

} // namespace

WebMediaStreamTrack WebMediaStreamTrack::ExtraData::owner()
{
    ASSERT(m_owner);
    return WebMediaStreamTrack(m_owner);
}

void WebMediaStreamTrack::ExtraData::setOwner(MediaStreamComponent* owner)
{
    ASSERT(!m_owner);
    m_owner = owner;
}

WebMediaStreamTrack::WebMediaStreamTrack(PassRefPtr<MediaStreamComponent> mediaStreamComponent)
>>>>>>> miniblink49
    : m_private(mediaStreamComponent)
{
}

<<<<<<< HEAD
WebMediaStreamTrack& WebMediaStreamTrack::operator=(
    MediaStreamComponent* mediaStreamComponent)
=======
WebMediaStreamTrack::WebMediaStreamTrack(MediaStreamComponent* mediaStreamComponent)
    : m_private(mediaStreamComponent)
{
}

WebMediaStreamTrack& WebMediaStreamTrack::operator=(MediaStreamComponent* mediaStreamComponent)
>>>>>>> miniblink49
{
    m_private = mediaStreamComponent;
    return *this;
}

void WebMediaStreamTrack::initialize(const WebMediaStreamSource& source)
{
    m_private = MediaStreamComponent::create(source);
}

<<<<<<< HEAD
void WebMediaStreamTrack::initialize(const WebString& id,
    const WebMediaStreamSource& source)
=======
void WebMediaStreamTrack::initialize(const WebString& id, const WebMediaStreamSource& source)
>>>>>>> miniblink49
{
    m_private = MediaStreamComponent::create(id, source);
}

void WebMediaStreamTrack::reset()
{
    m_private.reset();
}

<<<<<<< HEAD
=======
WebMediaStreamTrack::operator PassRefPtr<MediaStreamComponent>() const
{
    return m_private.get();
}

>>>>>>> miniblink49
WebMediaStreamTrack::operator MediaStreamComponent*() const
{
    return m_private.get();
}

bool WebMediaStreamTrack::isEnabled() const
{
    ASSERT(!m_private.isNull());
    return m_private->enabled();
}

bool WebMediaStreamTrack::isMuted() const
{
    ASSERT(!m_private.isNull());
    return m_private->muted();
}

<<<<<<< HEAD
WebMediaStreamTrack::ContentHintType WebMediaStreamTrack::contentHint() const
{
    DCHECK(!m_private.isNull());
    return m_private->contentHint();
}

=======
>>>>>>> miniblink49
WebString WebMediaStreamTrack::id() const
{
    ASSERT(!m_private.isNull());
    return m_private->id();
}

WebMediaStreamSource WebMediaStreamTrack::source() const
{
    ASSERT(!m_private.isNull());
    return WebMediaStreamSource(m_private->source());
}

<<<<<<< HEAD
WebMediaStreamTrack::TrackData* WebMediaStreamTrack::getTrackData() const
{
    MediaStreamComponent::TrackData* data = m_private->getTrackData();
    if (!data)
        return 0;
    return static_cast<TrackDataContainer*>(data)->getTrackData();
}

void WebMediaStreamTrack::setTrackData(TrackData* extraData)
{
    ASSERT(!m_private.isNull());

    m_private->setTrackData(
        WTF::wrapUnique(new TrackDataContainer(WTF::wrapUnique(extraData))));
=======
WebMediaStreamTrack::ExtraData* WebMediaStreamTrack::extraData() const
{
    MediaStreamComponent::ExtraData* data = m_private->extraData();
    if (!data)
        return 0;
    return static_cast<ExtraDataContainer*>(data)->extraData();
}

void WebMediaStreamTrack::setExtraData(ExtraData* extraData)
{
    ASSERT(!m_private.isNull());

    if (extraData)
        extraData->setOwner(m_private.get());

    m_private->setExtraData(adoptPtr(new ExtraDataContainer(adoptPtr(extraData))));
>>>>>>> miniblink49
}

void WebMediaStreamTrack::setSourceProvider(WebAudioSourceProvider* provider)
{
<<<<<<< HEAD
    ASSERT(!m_private.isNull());
    m_private->setSourceProvider(provider);
=======
#if ENABLE(WEB_AUDIO)
    ASSERT(!m_private.isNull());
    m_private->setSourceProvider(provider);
#endif // ENABLE(WEB_AUDIO)
>>>>>>> miniblink49
}

void WebMediaStreamTrack::assign(const WebMediaStreamTrack& other)
{
    m_private = other.m_private;
}

} // namespace blink
