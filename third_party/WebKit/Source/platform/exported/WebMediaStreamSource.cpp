/*
 * Copyright (C) 2011 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

<<<<<<< HEAD
=======
#include "config.h"

>>>>>>> miniblink49
#include "public/platform/WebMediaStreamSource.h"

#include "platform/audio/AudioBus.h"
#include "platform/mediastream/MediaStreamSource.h"
#include "public/platform/WebAudioDestinationConsumer.h"
#include "public/platform/WebMediaConstraints.h"
#include "public/platform/WebString.h"
<<<<<<< HEAD
#include "wtf/PtrUtil.h"
#include "wtf/Vector.h"
#include <memory>
=======
#include "wtf/MainThread.h"
#include "wtf/PassOwnPtr.h"
#include "wtf/Vector.h"
>>>>>>> miniblink49

namespace blink {

namespace {

<<<<<<< HEAD
    class ExtraDataContainer : public MediaStreamSource::ExtraData {
    public:
        ExtraDataContainer(std::unique_ptr<WebMediaStreamSource::ExtraData> extraData)
            : m_extraData(std::move(extraData))
        {
        }

        WebMediaStreamSource::ExtraData* getExtraData() { return m_extraData.get(); }

    private:
        std::unique_ptr<WebMediaStreamSource::ExtraData> m_extraData;
    };
=======
class ExtraDataContainer : public MediaStreamSource::ExtraData {
public:
    ExtraDataContainer(PassOwnPtr<WebMediaStreamSource::ExtraData> extraData) : m_extraData(extraData) { }

    WebMediaStreamSource::ExtraData* extraData() { return m_extraData.get(); }

private:
    OwnPtr<WebMediaStreamSource::ExtraData> m_extraData;
};
>>>>>>> miniblink49

} // namespace

WebMediaStreamSource WebMediaStreamSource::ExtraData::owner()
{
    ASSERT(m_owner);
    return WebMediaStreamSource(m_owner);
}

void WebMediaStreamSource::ExtraData::setOwner(MediaStreamSource* owner)
{
    ASSERT(!m_owner);
    m_owner = owner;
}

<<<<<<< HEAD
WebMediaStreamSource::WebMediaStreamSource(MediaStreamSource* mediaStreamSource)
=======
WebMediaStreamSource::WebMediaStreamSource(const PassRefPtr<MediaStreamSource>& mediaStreamSource)
>>>>>>> miniblink49
    : m_private(mediaStreamSource)
{
}

<<<<<<< HEAD
WebMediaStreamSource& WebMediaStreamSource::operator=(
    MediaStreamSource* mediaStreamSource)
=======
WebMediaStreamSource& WebMediaStreamSource::operator=(MediaStreamSource* mediaStreamSource)
>>>>>>> miniblink49
{
    m_private = mediaStreamSource;
    return *this;
}

void WebMediaStreamSource::assign(const WebMediaStreamSource& other)
{
    m_private = other.m_private;
}

void WebMediaStreamSource::reset()
{
    m_private.reset();
}

<<<<<<< HEAD
=======
WebMediaStreamSource::operator PassRefPtr<MediaStreamSource>() const
{
    return m_private.get();
}

>>>>>>> miniblink49
WebMediaStreamSource::operator MediaStreamSource*() const
{
    return m_private.get();
}

<<<<<<< HEAD
void WebMediaStreamSource::initialize(const WebString& id,
    Type type,
    const WebString& name)
{
    m_private = MediaStreamSource::create(
        id, static_cast<MediaStreamSource::StreamType>(type), name, false);
}

void WebMediaStreamSource::initialize(const WebString& id,
    Type type,
    const WebString& name,
    bool remote)
{
    m_private = MediaStreamSource::create(
        id, static_cast<MediaStreamSource::StreamType>(type), name, remote);
=======
void WebMediaStreamSource::initialize(const WebString& id, Type type, const WebString& name)
{
    m_private = MediaStreamSource::create(id, static_cast<MediaStreamSource::Type>(type), name, false, true);
}

void WebMediaStreamSource::initialize(const WebString& id, Type type, const WebString& name, bool remote, bool readonly)
{
    m_private = MediaStreamSource::create(id, static_cast<MediaStreamSource::Type>(type), name, remote, readonly);
>>>>>>> miniblink49
}

WebString WebMediaStreamSource::id() const
{
    ASSERT(!m_private.isNull());
    return m_private.get()->id();
}

<<<<<<< HEAD
WebMediaStreamSource::Type WebMediaStreamSource::getType() const
=======
WebMediaStreamSource::Type WebMediaStreamSource::type() const
>>>>>>> miniblink49
{
    ASSERT(!m_private.isNull());
    return static_cast<Type>(m_private.get()->type());
}

WebString WebMediaStreamSource::name() const
{
    ASSERT(!m_private.isNull());
    return m_private.get()->name();
}

<<<<<<< HEAD
bool WebMediaStreamSource::remote() const
{
    ASSERT(!m_private.isNull());
    return m_private.get()->remote();
}

=======
>>>>>>> miniblink49
void WebMediaStreamSource::setReadyState(ReadyState state)
{
    ASSERT(!m_private.isNull());
    m_private->setReadyState(static_cast<MediaStreamSource::ReadyState>(state));
}

<<<<<<< HEAD
WebMediaStreamSource::ReadyState WebMediaStreamSource::getReadyState() const
{
    ASSERT(!m_private.isNull());
    return static_cast<ReadyState>(m_private->getReadyState());
}

WebMediaStreamSource::ExtraData* WebMediaStreamSource::getExtraData() const
{
    ASSERT(!m_private.isNull());
    MediaStreamSource::ExtraData* data = m_private->getExtraData();
    if (!data)
        return 0;
    return static_cast<ExtraDataContainer*>(data)->getExtraData();
=======
WebMediaStreamSource::ReadyState WebMediaStreamSource::readyState() const
{
    ASSERT(!m_private.isNull());
    return static_cast<ReadyState>(m_private->readyState());
}

WebMediaStreamSource::ExtraData* WebMediaStreamSource::extraData() const
{
    ASSERT(!m_private.isNull());
    MediaStreamSource::ExtraData* data = m_private->extraData();
    if (!data)
        return 0;
    return static_cast<ExtraDataContainer*>(data)->extraData();
>>>>>>> miniblink49
}

void WebMediaStreamSource::setExtraData(ExtraData* extraData)
{
    ASSERT(!m_private.isNull());

    if (extraData)
        extraData->setOwner(m_private.get());

<<<<<<< HEAD
    m_private->setExtraData(
        WTF::wrapUnique(new ExtraDataContainer(WTF::wrapUnique(extraData))));
=======
    m_private->setExtraData(adoptPtr(new ExtraDataContainer(adoptPtr(extraData))));
>>>>>>> miniblink49
}

WebMediaConstraints WebMediaStreamSource::constraints()
{
    ASSERT(!m_private.isNull());
    return m_private->constraints();
}

bool WebMediaStreamSource::requiresAudioConsumer() const
{
    ASSERT(!m_private.isNull());
    return m_private->requiresAudioConsumer();
}

class ConsumerWrapper final : public AudioDestinationConsumer {
public:
    static ConsumerWrapper* create(WebAudioDestinationConsumer* consumer)
    {
        return new ConsumerWrapper(consumer);
    }

    void setFormat(size_t numberOfChannels, float sampleRate) override;
    void consumeAudio(AudioBus*, size_t numberOfFrames) override;

    WebAudioDestinationConsumer* consumer() { return m_consumer; }

private:
<<<<<<< HEAD
    explicit ConsumerWrapper(WebAudioDestinationConsumer* consumer)
        : m_consumer(consumer)
    {
    }
=======
    explicit ConsumerWrapper(WebAudioDestinationConsumer* consumer) : m_consumer(consumer) { }
>>>>>>> miniblink49

    // m_consumer is not owned by this class.
    WebAudioDestinationConsumer* m_consumer;
};

void ConsumerWrapper::setFormat(size_t numberOfChannels, float sampleRate)
{
    m_consumer->setFormat(numberOfChannels, sampleRate);
}

void ConsumerWrapper::consumeAudio(AudioBus* bus, size_t numberOfFrames)
{
    if (!bus)
        return;

    // Wrap AudioBus.
    size_t numberOfChannels = bus->numberOfChannels();
    WebVector<const float*> busVector(numberOfChannels);
    for (size_t i = 0; i < numberOfChannels; ++i)
        busVector[i] = bus->channel(i)->data();

    m_consumer->consumeAudio(busVector, numberOfFrames);
}

<<<<<<< HEAD
void WebMediaStreamSource::addAudioConsumer(
    WebAudioDestinationConsumer* consumer)
=======
void WebMediaStreamSource::addAudioConsumer(WebAudioDestinationConsumer* consumer)
>>>>>>> miniblink49
{
    ASSERT(isMainThread());
    ASSERT(!m_private.isNull() && consumer);

    m_private->addAudioConsumer(ConsumerWrapper::create(consumer));
}

<<<<<<< HEAD
bool WebMediaStreamSource::removeAudioConsumer(
    WebAudioDestinationConsumer* consumer)
=======
bool WebMediaStreamSource::removeAudioConsumer(WebAudioDestinationConsumer* consumer)
>>>>>>> miniblink49
{
    ASSERT(isMainThread());
    ASSERT(!m_private.isNull() && consumer);

    const HeapHashSet<Member<AudioDestinationConsumer>>& consumers = m_private->audioConsumers();
<<<<<<< HEAD
    for (HeapHashSet<Member<AudioDestinationConsumer>>::const_iterator it = consumers.begin();
         it != consumers.end(); ++it) {
=======
    for (HeapHashSet<Member<AudioDestinationConsumer>>::const_iterator it = consumers.begin(); it != consumers.end(); ++it) {
>>>>>>> miniblink49
        ConsumerWrapper* wrapper = static_cast<ConsumerWrapper*>(it->get());
        if (wrapper->consumer() == consumer) {
            m_private->removeAudioConsumer(wrapper);
            return true;
        }
    }
    return false;
}

} // namespace blink
