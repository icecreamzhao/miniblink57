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

#include "modules/webaudio/AnalyserNode.h"
#include "bindings/core/v8/ExceptionMessages.h"
#include "bindings/core/v8/ExceptionState.h"
#include "core/dom/ExceptionCode.h"
#include "modules/webaudio/AnalyserOptions.h"
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
#include "modules/webaudio/AnalyserNode.h"

#include "bindings/core/v8/ExceptionMessages.h"
#include "bindings/core/v8/ExceptionState.h"
#include "core/dom/ExceptionCode.h"
>>>>>>> miniblink49
#include "modules/webaudio/AudioNodeInput.h"
#include "modules/webaudio/AudioNodeOutput.h"

namespace blink {

AnalyserHandler::AnalyserHandler(AudioNode& node, float sampleRate)
    : AudioBasicInspectorHandler(NodeTypeAnalyser, node, sampleRate, 2)
{
    initialize();
}

<<<<<<< HEAD
PassRefPtr<AnalyserHandler> AnalyserHandler::create(AudioNode& node,
    float sampleRate)
=======
PassRefPtr<AnalyserHandler> AnalyserHandler::create(AudioNode& node, float sampleRate)
>>>>>>> miniblink49
{
    return adoptRef(new AnalyserHandler(node, sampleRate));
}

AnalyserHandler::~AnalyserHandler()
{
    uninitialize();
}

void AnalyserHandler::process(size_t framesToProcess)
{
    AudioBus* outputBus = output(0).bus();

    if (!isInitialized() || !input(0).isConnected()) {
        outputBus->zero();
        return;
    }

    AudioBus* inputBus = input(0).bus();

    // Give the analyser the audio which is passing through this AudioNode.
    m_analyser.writeInput(inputBus, framesToProcess);

<<<<<<< HEAD
    // For in-place processing, our override of pullInputs() will just pass the
    // audio data through unchanged if the channel count matches from input to
    // output (resulting in inputBus == outputBus). Otherwise, do an up-mix to
    // stereo.
=======
    // For in-place processing, our override of pullInputs() will just pass the audio data through unchanged if the channel count matches from input to output
    // (resulting in inputBus == outputBus). Otherwise, do an up-mix to stereo.
>>>>>>> miniblink49
    if (inputBus != outputBus)
        outputBus->copyFrom(*inputBus);
}

<<<<<<< HEAD
void AnalyserHandler::setFftSize(unsigned size,
    ExceptionState& exceptionState)
=======
void AnalyserHandler::setFftSize(unsigned size, ExceptionState& exceptionState)
>>>>>>> miniblink49
{
    if (!m_analyser.setFftSize(size)) {
        exceptionState.throwDOMException(
            IndexSizeError,
<<<<<<< HEAD
            (size < RealtimeAnalyser::MinFFTSize || size > RealtimeAnalyser::MaxFFTSize)
                ? ExceptionMessages::indexOutsideRange(
                    "FFT size", size, RealtimeAnalyser::MinFFTSize,
                    ExceptionMessages::InclusiveBound,
                    RealtimeAnalyser::MaxFFTSize,
                    ExceptionMessages::InclusiveBound)
=======
            (size < RealtimeAnalyser::MinFFTSize || size > RealtimeAnalyser::MaxFFTSize) ?
                ExceptionMessages::indexOutsideRange("FFT size", size, RealtimeAnalyser::MinFFTSize, ExceptionMessages::InclusiveBound, RealtimeAnalyser::MaxFFTSize, ExceptionMessages::InclusiveBound)
>>>>>>> miniblink49
                : ("The value provided (" + String::number(size) + ") is not a power of two."));
    }
}

void AnalyserHandler::setMinDecibels(double k, ExceptionState& exceptionState)
{
    if (k < maxDecibels()) {
        m_analyser.setMinDecibels(k);
    } else {
        exceptionState.throwDOMException(
<<<<<<< HEAD
            IndexSizeError, ExceptionMessages::indexExceedsMaximumBound("minDecibels", k, maxDecibels()));
=======
            IndexSizeError,
            ExceptionMessages::indexExceedsMaximumBound("minDecibels", k, maxDecibels()));
>>>>>>> miniblink49
    }
}

void AnalyserHandler::setMaxDecibels(double k, ExceptionState& exceptionState)
{
    if (k > minDecibels()) {
        m_analyser.setMaxDecibels(k);
    } else {
        exceptionState.throwDOMException(
<<<<<<< HEAD
            IndexSizeError, ExceptionMessages::indexExceedsMinimumBound("maxDecibels", k, minDecibels()));
    }
}

void AnalyserHandler::setMinMaxDecibels(double minDecibels,
    double maxDecibels,
    ExceptionState& exceptionState)
{
    if (minDecibels >= maxDecibels) {
        exceptionState.throwDOMException(
            IndexSizeError, "maxDecibels (" + String::number(maxDecibels) + ") must be greater than or equal to minDecibels " + "( " + String::number(minDecibels) + ").");
        return;
    }
    m_analyser.setMinDecibels(minDecibels);
    m_analyser.setMaxDecibels(maxDecibels);
}

void AnalyserHandler::setSmoothingTimeConstant(double k,
    ExceptionState& exceptionState)
=======
            IndexSizeError,
            ExceptionMessages::indexExceedsMinimumBound("maxDecibels", k, minDecibels()));
    }
}

void AnalyserHandler::setSmoothingTimeConstant(double k, ExceptionState& exceptionState)
>>>>>>> miniblink49
{
    if (k >= 0 && k <= 1) {
        m_analyser.setSmoothingTimeConstant(k);
    } else {
        exceptionState.throwDOMException(
            IndexSizeError,
<<<<<<< HEAD
            ExceptionMessages::indexOutsideRange(
                "smoothing value", k, 0.0, ExceptionMessages::InclusiveBound, 1.0,
                ExceptionMessages::InclusiveBound));
=======
            ExceptionMessages::indexOutsideRange("smoothing value", k, 0.0, ExceptionMessages::InclusiveBound, 1.0, ExceptionMessages::InclusiveBound));
>>>>>>> miniblink49
    }
}

// ----------------------------------------------------------------

<<<<<<< HEAD
AnalyserNode::AnalyserNode(BaseAudioContext& context)
    : AudioBasicInspectorNode(context)
{
    setHandler(AnalyserHandler::create(*this, context.sampleRate()));
}

AnalyserNode* AnalyserNode::create(BaseAudioContext& context,
    ExceptionState& exceptionState)
{
    DCHECK(isMainThread());

    if (context.isContextClosed()) {
        context.throwExceptionForClosedState(exceptionState);
        return nullptr;
    }

    return new AnalyserNode(context);
}

AnalyserNode* AnalyserNode::create(BaseAudioContext* context,
    const AnalyserOptions& options,
    ExceptionState& exceptionState)
{
    DCHECK(isMainThread());

    AnalyserNode* node = create(*context, exceptionState);

    if (!node)
        return nullptr;

    node->handleChannelOptions(options, exceptionState);

    if (options.hasFftSize())
        node->setFftSize(options.fftSize(), exceptionState);

    if (options.hasSmoothingTimeConstant())
        node->setSmoothingTimeConstant(options.smoothingTimeConstant(),
            exceptionState);

    // minDecibels and maxDecibels have default values.  Set both of the values
    // at once.
    node->setMinMaxDecibels(options.minDecibels(), options.maxDecibels(),
        exceptionState);

    return node;
=======
AnalyserNode::AnalyserNode(AudioContext& context, float sampleRate)
    : AudioBasicInspectorNode(context)
{
    setHandler(AnalyserHandler::create(*this, sampleRate));
}

AnalyserNode* AnalyserNode::create(AudioContext& context, float sampleRate)
{
    return new AnalyserNode(context, sampleRate);
>>>>>>> miniblink49
}

AnalyserHandler& AnalyserNode::analyserHandler() const
{
    return static_cast<AnalyserHandler&>(handler());
}

unsigned AnalyserNode::fftSize() const
{
    return analyserHandler().fftSize();
}

void AnalyserNode::setFftSize(unsigned size, ExceptionState& exceptionState)
{
    return analyserHandler().setFftSize(size, exceptionState);
}

unsigned AnalyserNode::frequencyBinCount() const
{
    return analyserHandler().frequencyBinCount();
}

void AnalyserNode::setMinDecibels(double min, ExceptionState& exceptionState)
{
    analyserHandler().setMinDecibels(min, exceptionState);
}

double AnalyserNode::minDecibels() const
{
    return analyserHandler().minDecibels();
}

void AnalyserNode::setMaxDecibels(double max, ExceptionState& exceptionState)
{
    analyserHandler().setMaxDecibels(max, exceptionState);
}

<<<<<<< HEAD
void AnalyserNode::setMinMaxDecibels(double min,
    double max,
    ExceptionState& exceptionState)
{
    analyserHandler().setMinMaxDecibels(min, max, exceptionState);
}

=======
>>>>>>> miniblink49
double AnalyserNode::maxDecibels() const
{
    return analyserHandler().maxDecibels();
}

<<<<<<< HEAD
void AnalyserNode::setSmoothingTimeConstant(double smoothingTime,
    ExceptionState& exceptionState)
=======
void AnalyserNode::setSmoothingTimeConstant(double smoothingTime, ExceptionState& exceptionState)
>>>>>>> miniblink49
{
    analyserHandler().setSmoothingTimeConstant(smoothingTime, exceptionState);
}

double AnalyserNode::smoothingTimeConstant() const
{
    return analyserHandler().smoothingTimeConstant();
}

void AnalyserNode::getFloatFrequencyData(DOMFloat32Array* array)
{
<<<<<<< HEAD
    analyserHandler().getFloatFrequencyData(array, context()->currentTime());
=======
    analyserHandler().getFloatFrequencyData(array);
>>>>>>> miniblink49
}

void AnalyserNode::getByteFrequencyData(DOMUint8Array* array)
{
<<<<<<< HEAD
    analyserHandler().getByteFrequencyData(array, context()->currentTime());
=======
    analyserHandler().getByteFrequencyData(array);
>>>>>>> miniblink49
}

void AnalyserNode::getFloatTimeDomainData(DOMFloat32Array* array)
{
    analyserHandler().getFloatTimeDomainData(array);
}

void AnalyserNode::getByteTimeDomainData(DOMUint8Array* array)
{
    analyserHandler().getByteTimeDomainData(array);
}

} // namespace blink
<<<<<<< HEAD
=======

#endif // ENABLE(WEB_AUDIO)
>>>>>>> miniblink49
