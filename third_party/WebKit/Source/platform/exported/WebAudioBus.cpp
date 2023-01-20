/*
 * Copyright (C) 2010, Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1.  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
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

#include "public/platform/WebAudioBus.h"

#include "wtf/build_config.h"

#include "platform/audio/AudioBus.h"
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
#include "public/platform/WebAudioBus.h"

#if ENABLE(WEB_AUDIO)
#include "platform/audio/AudioBus.h"
#else
#include "wtf/ThreadSafeRefCounted.h"

namespace blink {
class AudioBus : public ThreadSafeRefCounted<AudioBus> {
};
} // namespace blink
#endif

>>>>>>> miniblink49
#include "wtf/PassRefPtr.h"
#include "wtf/RefPtr.h"

namespace blink {

class WebAudioBusPrivate : public AudioBus {
};

<<<<<<< HEAD
void WebAudioBus::initialize(unsigned numberOfChannels,
    size_t length,
    double sampleRate)
{
=======
void WebAudioBus::initialize(unsigned numberOfChannels, size_t length, double sampleRate)
{
#if ENABLE(WEB_AUDIO)
>>>>>>> miniblink49
    RefPtr<AudioBus> audioBus = AudioBus::create(numberOfChannels, length);
    audioBus->setSampleRate(sampleRate);

    if (m_private)
        (static_cast<AudioBus*>(m_private))->deref();

    audioBus->ref();
    m_private = static_cast<WebAudioBusPrivate*>(audioBus.get());
<<<<<<< HEAD
=======
#else
    ASSERT_NOT_REACHED();
#endif
>>>>>>> miniblink49
}

void WebAudioBus::resizeSmaller(size_t newLength)
{
<<<<<<< HEAD
=======
#if ENABLE(WEB_AUDIO)
>>>>>>> miniblink49
    ASSERT(m_private);
    if (m_private) {
        ASSERT(newLength <= length());
        m_private->resizeSmaller(newLength);
    }
<<<<<<< HEAD
=======
#else
    ASSERT_NOT_REACHED();
#endif
>>>>>>> miniblink49
}

void WebAudioBus::reset()
{
<<<<<<< HEAD
=======
#if ENABLE(WEB_AUDIO)
>>>>>>> miniblink49
    if (m_private) {
        (static_cast<AudioBus*>(m_private))->deref();
        m_private = 0;
    }
<<<<<<< HEAD
=======
#else
    ASSERT_NOT_REACHED();
#endif
>>>>>>> miniblink49
}

unsigned WebAudioBus::numberOfChannels() const
{
<<<<<<< HEAD
    if (!m_private)
        return 0;
    return m_private->numberOfChannels();
=======
#if ENABLE(WEB_AUDIO)
    if (!m_private)
        return 0;
    return m_private->numberOfChannels();
#else
    ASSERT_NOT_REACHED();
    return 0;
#endif
>>>>>>> miniblink49
}

size_t WebAudioBus::length() const
{
<<<<<<< HEAD
    if (!m_private)
        return 0;
    return m_private->length();
=======
#if ENABLE(WEB_AUDIO)
    if (!m_private)
        return 0;
    return m_private->length();
#else
    ASSERT_NOT_REACHED();
    return 0;
#endif
>>>>>>> miniblink49
}

double WebAudioBus::sampleRate() const
{
<<<<<<< HEAD
    if (!m_private)
        return 0;
    return m_private->sampleRate();
=======
#if ENABLE(WEB_AUDIO)
    if (!m_private)
        return 0;
    return m_private->sampleRate();
#else
    ASSERT_NOT_REACHED();
    return 0;
#endif
>>>>>>> miniblink49
}

float* WebAudioBus::channelData(unsigned channelIndex)
{
<<<<<<< HEAD
=======
#if ENABLE(WEB_AUDIO)
>>>>>>> miniblink49
    if (!m_private)
        return 0;
    ASSERT(channelIndex < numberOfChannels());
    return m_private->channel(channelIndex)->mutableData();
<<<<<<< HEAD
=======
#else
    ASSERT_NOT_REACHED();
    return 0;
#endif
>>>>>>> miniblink49
}

PassRefPtr<AudioBus> WebAudioBus::release()
{
<<<<<<< HEAD
    RefPtr<AudioBus> audioBus(adoptRef(static_cast<AudioBus*>(m_private)));
    m_private = 0;
    return audioBus;
=======
#if ENABLE(WEB_AUDIO)
    RefPtr<AudioBus> audioBus(adoptRef(static_cast<AudioBus*>(m_private)));
    m_private = 0;
    return audioBus;
#else
    ASSERT_NOT_REACHED();
    return nullptr;
#endif
>>>>>>> miniblink49
}

} // namespace blink
