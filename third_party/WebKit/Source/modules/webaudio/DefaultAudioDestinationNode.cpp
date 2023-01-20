/*
 * Copyright (C) 2011, Google Inc. All rights reserved.
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
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 */

#include "modules/webaudio/DefaultAudioDestinationNode.h"
#include "bindings/core/v8/ExceptionMessages.h"
#include "bindings/core/v8/ExceptionState.h"
#include "core/dom/ExceptionCode.h"
#include "modules/webaudio/BaseAudioContext.h"
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
#if ENABLE(WEB_AUDIO)
#include "modules/webaudio/DefaultAudioDestinationNode.h"

#include "bindings/core/v8/ExceptionMessages.h"
#include "bindings/core/v8/ExceptionState.h"
#include "core/dom/ExceptionCode.h"
#include "platform/Logging.h"
#include "wtf/MainThread.h"
>>>>>>> miniblink49

namespace blink {

DefaultAudioDestinationHandler::DefaultAudioDestinationHandler(AudioNode& node)
    : AudioDestinationHandler(node, AudioDestination::hardwareSampleRate())
    , m_numberOfInputChannels(0)
{
    // Node-specific default mixing rules.
    m_channelCount = 2;
<<<<<<< HEAD
    setInternalChannelCountMode(Explicit);
    setInternalChannelInterpretation(AudioBus::Speakers);
}

PassRefPtr<DefaultAudioDestinationHandler>
DefaultAudioDestinationHandler::create(AudioNode& node)
=======
    m_channelCountMode = Explicit;
    m_channelInterpretation = AudioBus::Speakers;
}

PassRefPtr<DefaultAudioDestinationHandler> DefaultAudioDestinationHandler::create(AudioNode& node)
>>>>>>> miniblink49
{
    return adoptRef(new DefaultAudioDestinationHandler(node));
}

DefaultAudioDestinationHandler::~DefaultAudioDestinationHandler()
{
<<<<<<< HEAD
    DCHECK(!isInitialized());
=======
    ASSERT(!isInitialized());
>>>>>>> miniblink49
}

void DefaultAudioDestinationHandler::dispose()
{
    uninitialize();
    AudioDestinationHandler::dispose();
}

void DefaultAudioDestinationHandler::initialize()
{
<<<<<<< HEAD
    DCHECK(isMainThread());
=======
    ASSERT(isMainThread());
>>>>>>> miniblink49
    if (isInitialized())
        return;

    createDestination();
    AudioHandler::initialize();
}

void DefaultAudioDestinationHandler::uninitialize()
{
<<<<<<< HEAD
    DCHECK(isMainThread());
=======
    ASSERT(isMainThread());
>>>>>>> miniblink49
    if (!isInitialized())
        return;

    m_destination->stop();
    m_numberOfInputChannels = 0;

    AudioHandler::uninitialize();
}

void DefaultAudioDestinationHandler::createDestination()
{
    float hardwareSampleRate = AudioDestination::hardwareSampleRate();
<<<<<<< HEAD
    VLOG(1) << ">>>> hardwareSampleRate = " << hardwareSampleRate;

    m_destination = AudioDestination::create(*this, channelCount(), hardwareSampleRate,
        context()->getSecurityOrigin());
=======
    WTF_LOG(WebAudio, ">>>> hardwareSampleRate = %f\n", hardwareSampleRate);

    m_destination = AudioDestination::create(*this, m_inputDeviceId, m_numberOfInputChannels, channelCount(), hardwareSampleRate);
>>>>>>> miniblink49
}

void DefaultAudioDestinationHandler::startRendering()
{
<<<<<<< HEAD
    DCHECK(isInitialized());
    if (isInitialized()) {
        DCHECK(!m_destination->isPlaying());
=======
    ASSERT(isInitialized());
    if (isInitialized()) {
        ASSERT(!m_destination->isPlaying());
>>>>>>> miniblink49
        m_destination->start();
    }
}

void DefaultAudioDestinationHandler::stopRendering()
{
<<<<<<< HEAD
    DCHECK(isInitialized());
    if (isInitialized()) {
        DCHECK(m_destination->isPlaying());
=======
    ASSERT(isInitialized());
    if (isInitialized()) {
        ASSERT(m_destination->isPlaying());
>>>>>>> miniblink49
        m_destination->stop();
    }
}

unsigned long DefaultAudioDestinationHandler::maxChannelCount() const
{
    return AudioDestination::maxChannelCount();
}

<<<<<<< HEAD
size_t DefaultAudioDestinationHandler::callbackBufferSize() const
{
    return m_destination->callbackBufferSize();
}

void DefaultAudioDestinationHandler::setChannelCount(
    unsigned long channelCount,
    ExceptionState& exceptionState)
{
    // The channelCount for the input to this node controls the actual number of
    // channels we send to the audio hardware. It can only be set depending on the
    // maximum number of channels supported by the hardware.

    DCHECK(isMainThread());
=======
void DefaultAudioDestinationHandler::setChannelCount(unsigned long channelCount, ExceptionState& exceptionState)
{
    // The channelCount for the input to this node controls the actual number of channels we
    // send to the audio hardware. It can only be set depending on the maximum number of
    // channels supported by the hardware.

    ASSERT(isMainThread());
>>>>>>> miniblink49

    if (!maxChannelCount() || channelCount > maxChannelCount()) {
        exceptionState.throwDOMException(
            IndexSizeError,
<<<<<<< HEAD
            ExceptionMessages::indexOutsideRange<unsigned>(
                "channel count", channelCount, 1, ExceptionMessages::InclusiveBound,
                maxChannelCount(), ExceptionMessages::InclusiveBound));
=======
            ExceptionMessages::indexOutsideRange<unsigned>("channel count", channelCount, 1, ExceptionMessages::InclusiveBound, maxChannelCount(), ExceptionMessages::InclusiveBound));
>>>>>>> miniblink49
        return;
    }

    unsigned long oldChannelCount = this->channelCount();
    AudioHandler::setChannelCount(channelCount, exceptionState);

    if (!exceptionState.hadException() && this->channelCount() != oldChannelCount && isInitialized()) {
        // Re-create destination.
        m_destination->stop();
        createDestination();
        m_destination->start();
    }
}

// ----------------------------------------------------------------

<<<<<<< HEAD
DefaultAudioDestinationNode::DefaultAudioDestinationNode(
    BaseAudioContext& context)
=======
DefaultAudioDestinationNode::DefaultAudioDestinationNode(AudioContext& context)
>>>>>>> miniblink49
    : AudioDestinationNode(context)
{
    setHandler(DefaultAudioDestinationHandler::create(*this));
}

<<<<<<< HEAD
DefaultAudioDestinationNode* DefaultAudioDestinationNode::create(
    BaseAudioContext* context)
=======
DefaultAudioDestinationNode* DefaultAudioDestinationNode::create(AudioContext* context)
>>>>>>> miniblink49
{
    return new DefaultAudioDestinationNode(*context);
}

} // namespace blink
<<<<<<< HEAD
=======

#endif // ENABLE(WEB_AUDIO)
>>>>>>> miniblink49
