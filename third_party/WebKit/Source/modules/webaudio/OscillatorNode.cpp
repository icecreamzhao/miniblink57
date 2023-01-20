/*
 * Copyright (C) 2012, Google Inc. All rights reserved.
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

#include "modules/webaudio/OscillatorNode.h"
#include "bindings/core/v8/ExceptionMessages.h"
#include "bindings/core/v8/ExceptionState.h"
#include "core/dom/ExceptionCode.h"
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
#include "modules/webaudio/OscillatorNode.h"

#include "bindings/core/v8/ExceptionMessages.h"
#include "bindings/core/v8/ExceptionState.h"
#include "core/dom/ExceptionCode.h"
#include "modules/webaudio/AudioContext.h"
>>>>>>> miniblink49
#include "modules/webaudio/AudioNodeOutput.h"
#include "modules/webaudio/PeriodicWave.h"
#include "platform/audio/AudioUtilities.h"
#include "platform/audio/VectorMath.h"
#include "wtf/MathExtras.h"
#include "wtf/StdLibExtras.h"
#include <algorithm>

namespace blink {

using namespace VectorMath;

<<<<<<< HEAD
OscillatorHandler::OscillatorHandler(AudioNode& node,
    float sampleRate,
    AudioParamHandler& frequency,
    AudioParamHandler& detune)
=======
OscillatorHandler::OscillatorHandler(AudioNode& node, float sampleRate, AudioParamHandler& frequency, AudioParamHandler& detune)
>>>>>>> miniblink49
    : AudioScheduledSourceHandler(NodeTypeOscillator, node, sampleRate)
    , m_type(SINE)
    , m_frequency(frequency)
    , m_detune(detune)
    , m_firstRender(true)
    , m_virtualReadIndex(0)
<<<<<<< HEAD
    , m_phaseIncrements(AudioUtilities::kRenderQuantumFrames)
    , m_detuneValues(AudioUtilities::kRenderQuantumFrames)
=======
    , m_phaseIncrements(ProcessingSizeInFrames)
    , m_detuneValues(ProcessingSizeInFrames)
>>>>>>> miniblink49
{
    // Sets up default wavetable.
    setType(m_type);

    // An oscillator is always mono.
    addOutput(1);

    initialize();
}

<<<<<<< HEAD
PassRefPtr<OscillatorHandler> OscillatorHandler::create(
    AudioNode& node,
    float sampleRate,
    AudioParamHandler& frequency,
    AudioParamHandler& detune)
=======
PassRefPtr<OscillatorHandler> OscillatorHandler::create(AudioNode& node, float sampleRate, AudioParamHandler& frequency, AudioParamHandler& detune)
>>>>>>> miniblink49
{
    return adoptRef(new OscillatorHandler(node, sampleRate, frequency, detune));
}

OscillatorHandler::~OscillatorHandler()
{
    uninitialize();
}

String OscillatorHandler::type() const
{
    switch (m_type) {
    case SINE:
        return "sine";
    case SQUARE:
        return "square";
    case SAWTOOTH:
        return "sawtooth";
    case TRIANGLE:
        return "triangle";
    case CUSTOM:
        return "custom";
    default:
        ASSERT_NOT_REACHED();
        return "custom";
    }
}

<<<<<<< HEAD
void OscillatorHandler::setType(const String& type,
    ExceptionState& exceptionState)
=======
void OscillatorHandler::setType(const String& type, ExceptionState& exceptionState)
>>>>>>> miniblink49
{
    if (type == "sine") {
        setType(SINE);
    } else if (type == "square") {
        setType(SQUARE);
    } else if (type == "sawtooth") {
        setType(SAWTOOTH);
    } else if (type == "triangle") {
        setType(TRIANGLE);
    } else if (type == "custom") {
<<<<<<< HEAD
        exceptionState.throwDOMException(InvalidStateError,
            "'type' cannot be set directly to "
            "'custom'.  Use setPeriodicWave() to "
            "create a custom Oscillator type.");
=======
        exceptionState.throwDOMException(
            InvalidStateError,
            "'type' cannot be set directly to 'custom'.  Use setPeriodicWave() to create a custom Oscillator type.");
>>>>>>> miniblink49
    }
}

bool OscillatorHandler::setType(unsigned type)
{
    PeriodicWave* periodicWave = nullptr;
<<<<<<< HEAD

    switch (type) {
    case SINE:
        periodicWave = context()->periodicWave(SINE);
        break;
    case SQUARE:
        periodicWave = context()->periodicWave(SQUARE);
        break;
    case SAWTOOTH:
        periodicWave = context()->periodicWave(SAWTOOTH);
        break;
    case TRIANGLE:
        periodicWave = context()->periodicWave(TRIANGLE);
        break;
    case CUSTOM:
    default:
        // Return false for invalid types, including CUSTOM since
        // setPeriodicWave() method must be called explicitly.
=======
    float sampleRate = this->sampleRate();

    switch (type) {
    case SINE: {
        DEFINE_STATIC_LOCAL(Persistent<PeriodicWave>, periodicWaveSine, (PeriodicWave::createSine(sampleRate)));
        periodicWave = periodicWaveSine;
        break;
    }
    case SQUARE: {
        DEFINE_STATIC_LOCAL(Persistent<PeriodicWave>, periodicWaveSquare, (PeriodicWave::createSquare(sampleRate)));
        periodicWave = periodicWaveSquare;
        break;
    }
    case SAWTOOTH: {
        DEFINE_STATIC_LOCAL(Persistent<PeriodicWave>, periodicWaveSawtooth, (PeriodicWave::createSawtooth(sampleRate)));
        periodicWave = periodicWaveSawtooth;
        break;
    }
    case TRIANGLE: {
        DEFINE_STATIC_LOCAL(Persistent<PeriodicWave>, periodicWaveTriangle, (PeriodicWave::createTriangle(sampleRate)));
        periodicWave = periodicWaveTriangle;
        break;
    }
    case CUSTOM:
    default:
        // Return error for invalid types, including CUSTOM since setPeriodicWave() method must be
        // called explicitly.
>>>>>>> miniblink49
        ASSERT_NOT_REACHED();
        return false;
    }

    setPeriodicWave(periodicWave);
    m_type = type;
    return true;
}

<<<<<<< HEAD
bool OscillatorHandler::calculateSampleAccuratePhaseIncrements(
    size_t framesToProcess)
{
    bool isGood = framesToProcess <= m_phaseIncrements.size() && framesToProcess <= m_detuneValues.size();
    DCHECK(isGood);
=======
bool OscillatorHandler::calculateSampleAccuratePhaseIncrements(size_t framesToProcess)
{
    bool isGood = framesToProcess <= m_phaseIncrements.size() && framesToProcess <= m_detuneValues.size();
    ASSERT(isGood);
>>>>>>> miniblink49
    if (!isGood)
        return false;

    if (m_firstRender) {
        m_firstRender = false;
        m_frequency->resetSmoothedValue();
        m_detune->resetSmoothedValue();
    }

    bool hasSampleAccurateValues = false;
    bool hasFrequencyChanges = false;
    float* phaseIncrements = m_phaseIncrements.data();

    float finalScale = m_periodicWave->rateScale();

    if (m_frequency->hasSampleAccurateValues()) {
        hasSampleAccurateValues = true;
        hasFrequencyChanges = true;

        // Get the sample-accurate frequency values and convert to phase increments.
        // They will be converted to phase increments below.
<<<<<<< HEAD
        m_frequency->calculateSampleAccurateValues(phaseIncrements,
            framesToProcess);
    } else {
        // Handle ordinary parameter smoothing/de-zippering if there are no
        // scheduled changes.
=======
        m_frequency->calculateSampleAccurateValues(phaseIncrements, framesToProcess);
    } else {
        // Handle ordinary parameter smoothing/de-zippering if there are no scheduled changes.
>>>>>>> miniblink49
        m_frequency->smooth();
        float frequency = m_frequency->smoothedValue();
        finalScale *= frequency;
    }

    if (m_detune->hasSampleAccurateValues()) {
        hasSampleAccurateValues = true;

        // Get the sample-accurate detune values.
        float* detuneValues = hasFrequencyChanges ? m_detuneValues.data() : phaseIncrements;
        m_detune->calculateSampleAccurateValues(detuneValues, framesToProcess);

        // Convert from cents to rate scalar.
        float k = 1.0 / 1200;
        vsmul(detuneValues, 1, &k, detuneValues, 1, framesToProcess);
        for (unsigned i = 0; i < framesToProcess; ++i)
<<<<<<< HEAD
            detuneValues[i] = powf(
                2, detuneValues[i]); // FIXME: converting to expf() will be faster.

        if (hasFrequencyChanges) {
            // Multiply frequencies by detune scalings.
            vmul(detuneValues, 1, phaseIncrements, 1, phaseIncrements, 1,
                framesToProcess);
        }
    } else {
        // Handle ordinary parameter smoothing/de-zippering if there are no
        // scheduled changes.
=======
            detuneValues[i] = powf(2, detuneValues[i]); // FIXME: converting to expf() will be faster.

        if (hasFrequencyChanges) {
            // Multiply frequencies by detune scalings.
            vmul(detuneValues, 1, phaseIncrements, 1, phaseIncrements, 1, framesToProcess);
        }
    } else {
        // Handle ordinary parameter smoothing/de-zippering if there are no scheduled changes.
>>>>>>> miniblink49
        m_detune->smooth();
        float detune = m_detune->smoothedValue();
        float detuneScale = powf(2, detune / 1200);
        finalScale *= detuneScale;
    }

    if (hasSampleAccurateValues) {
        // Convert from frequency to wavetable increment.
        vsmul(phaseIncrements, 1, &finalScale, phaseIncrements, 1, framesToProcess);
    }

    return hasSampleAccurateValues;
}

void OscillatorHandler::process(size_t framesToProcess)
{
    AudioBus* outputBus = output(0).bus();

    if (!isInitialized() || !outputBus->numberOfChannels()) {
        outputBus->zero();
        return;
    }

<<<<<<< HEAD
    DCHECK_LE(framesToProcess, m_phaseIncrements.size());
=======
    ASSERT(framesToProcess <= m_phaseIncrements.size());
>>>>>>> miniblink49
    if (framesToProcess > m_phaseIncrements.size())
        return;

    // The audio thread can't block on this lock, so we call tryLock() instead.
    MutexTryLocker tryLocker(m_processLock);
    if (!tryLocker.locked()) {
<<<<<<< HEAD
        // Too bad - the tryLock() failed. We must be in the middle of changing
        // wave-tables.
=======
        // Too bad - the tryLock() failed. We must be in the middle of changing wave-tables.
>>>>>>> miniblink49
        outputBus->zero();
        return;
    }

    // We must access m_periodicWave only inside the lock.
    if (!m_periodicWave.get()) {
        outputBus->zero();
        return;
    }

    size_t quantumFrameOffset;
    size_t nonSilentFramesToProcess;
<<<<<<< HEAD
    double startFrameOffset;

    updateSchedulingInfo(framesToProcess, outputBus, quantumFrameOffset,
        nonSilentFramesToProcess, startFrameOffset);
=======

    updateSchedulingInfo(framesToProcess, outputBus, quantumFrameOffset, nonSilentFramesToProcess);
>>>>>>> miniblink49

    if (!nonSilentFramesToProcess) {
        outputBus->zero();
        return;
    }

    unsigned periodicWaveSize = m_periodicWave->periodicWaveSize();
    double invPeriodicWaveSize = 1.0 / periodicWaveSize;

    float* destP = outputBus->channel(0)->mutableData();

<<<<<<< HEAD
    DCHECK_LE(quantumFrameOffset, framesToProcess);
=======
    ASSERT(quantumFrameOffset <= framesToProcess);
>>>>>>> miniblink49

    // We keep virtualReadIndex double-precision since we're accumulating values.
    double virtualReadIndex = m_virtualReadIndex;

    float rateScale = m_periodicWave->rateScale();
    float invRateScale = 1 / rateScale;
    bool hasSampleAccurateValues = calculateSampleAccuratePhaseIncrements(framesToProcess);

    float frequency = 0;
    float* higherWaveData = 0;
    float* lowerWaveData = 0;
    float tableInterpolationFactor = 0;

    if (!hasSampleAccurateValues) {
        frequency = m_frequency->smoothedValue();
        float detune = m_detune->smoothedValue();
        float detuneScale = powf(2, detune / 1200);
        frequency *= detuneScale;
<<<<<<< HEAD
        m_periodicWave->waveDataForFundamentalFrequency(
            frequency, lowerWaveData, higherWaveData, tableInterpolationFactor);
=======
        m_periodicWave->waveDataForFundamentalFrequency(frequency, lowerWaveData, higherWaveData, tableInterpolationFactor);
>>>>>>> miniblink49
    }

    float incr = frequency * rateScale;
    float* phaseIncrements = m_phaseIncrements.data();

    unsigned readIndexMask = periodicWaveSize - 1;

    // Start rendering at the correct offset.
    destP += quantumFrameOffset;
    int n = nonSilentFramesToProcess;

<<<<<<< HEAD
    // If startFrameOffset is not 0, that means the oscillator doesn't actually
    // start at quantumFrameOffset, but just past that time.  Adjust destP and n
    // to reflect that, and adjust virtualReadIndex to start the value at
    // startFrameOffset.
    if (startFrameOffset > 0) {
        ++destP;
        --n;
        virtualReadIndex += (1 - startFrameOffset) * frequency * rateScale;
        DCHECK(virtualReadIndex < periodicWaveSize);
    } else if (startFrameOffset < 0) {
        virtualReadIndex = -startFrameOffset * frequency * rateScale;
    }

=======
>>>>>>> miniblink49
    while (n--) {
        unsigned readIndex = static_cast<unsigned>(virtualReadIndex);
        unsigned readIndex2 = readIndex + 1;

        // Contain within valid range.
        readIndex = readIndex & readIndexMask;
        readIndex2 = readIndex2 & readIndexMask;

        if (hasSampleAccurateValues) {
            incr = *phaseIncrements++;

            frequency = invRateScale * incr;
<<<<<<< HEAD
            m_periodicWave->waveDataForFundamentalFrequency(
                frequency, lowerWaveData, higherWaveData, tableInterpolationFactor);
=======
            m_periodicWave->waveDataForFundamentalFrequency(frequency, lowerWaveData, higherWaveData, tableInterpolationFactor);
>>>>>>> miniblink49
        }

        float sample1Lower = lowerWaveData[readIndex];
        float sample2Lower = lowerWaveData[readIndex2];
        float sample1Higher = higherWaveData[readIndex];
        float sample2Higher = higherWaveData[readIndex2];

        // Linearly interpolate within each table (lower and higher).
        float interpolationFactor = static_cast<float>(virtualReadIndex) - readIndex;
        float sampleHigher = (1 - interpolationFactor) * sample1Higher + interpolationFactor * sample2Higher;
        float sampleLower = (1 - interpolationFactor) * sample1Lower + interpolationFactor * sample2Lower;

        // Then interpolate between the two tables.
        float sample = (1 - tableInterpolationFactor) * sampleHigher + tableInterpolationFactor * sampleLower;

        *destP++ = sample;

<<<<<<< HEAD
        // Increment virtual read index and wrap virtualReadIndex into the range
        // 0 -> periodicWaveSize.
=======
        // Increment virtual read index and wrap virtualReadIndex into the range 0 -> periodicWaveSize.
>>>>>>> miniblink49
        virtualReadIndex += incr;
        virtualReadIndex -= floor(virtualReadIndex * invPeriodicWaveSize) * periodicWaveSize;
    }

    m_virtualReadIndex = virtualReadIndex;

    outputBus->clearSilentFlag();
}

void OscillatorHandler::setPeriodicWave(PeriodicWave* periodicWave)
{
<<<<<<< HEAD
    DCHECK(isMainThread());
    DCHECK(periodicWave);
=======
    ASSERT(isMainThread());
>>>>>>> miniblink49

    // This synchronizes with process().
    MutexLocker processLocker(m_processLock);
    m_periodicWave = periodicWave;
    m_type = CUSTOM;
}

bool OscillatorHandler::propagatesSilence() const
{
    return !isPlayingOrScheduled() || hasFinished() || !m_periodicWave.get();
}

// ----------------------------------------------------------------

<<<<<<< HEAD
OscillatorNode::OscillatorNode(BaseAudioContext& context)
    : AudioScheduledSourceNode(context)
    ,
    // Use musical pitch standard A440 as a default.
    m_frequency(AudioParam::create(context,
        ParamTypeOscillatorFrequency,
        440,
        -context.sampleRate() / 2,
        context.sampleRate() / 2))
    ,
    // Default to no detuning.
    m_detune(AudioParam::create(context, ParamTypeOscillatorDetune, 0))
{
    setHandler(OscillatorHandler::create(*this, context.sampleRate(),
        m_frequency->handler(),
        m_detune->handler()));
}

OscillatorNode* OscillatorNode::create(BaseAudioContext& context,
    ExceptionState& exceptionState)
{
    DCHECK(isMainThread());

    if (context.isContextClosed()) {
        context.throwExceptionForClosedState(exceptionState);
        return nullptr;
    }

    return new OscillatorNode(context);
}

OscillatorNode* OscillatorNode::create(BaseAudioContext* context,
    const OscillatorOptions& options,
    ExceptionState& exceptionState)
{
    OscillatorNode* node = create(*context, exceptionState);

    if (!node)
        return nullptr;

    node->handleChannelOptions(options, exceptionState);

    if (options.hasType()) {
        if (options.type() == "custom" && !options.hasPeriodicWave()) {
            exceptionState.throwDOMException(InvalidStateError,
                "'type' cannot be set to 'custom' "
                "without also specifying "
                "'periodicWave'");
            return nullptr;
        }
        if (options.type() != "custom" && options.hasPeriodicWave()) {
            exceptionState.throwDOMException(InvalidStateError,
                "'type' MUST be 'custom' instead of '" + options.type() + "' if 'periodicWave' is also given");
            return nullptr;
        }

        // At this both type and periodicWave are consistently defined.  In that
        // case, don't set the type if periodicWave is specified because that
        // will cause an (incorrect) error to be signaled.
        if (options.type() != "custom")
            node->setType(options.type(), exceptionState);
    }
    if (options.hasDetune())
        node->detune()->setValue(options.detune());
    if (options.hasFrequency())
        node->frequency()->setValue(options.frequency());

    if (options.hasPeriodicWave())
        node->setPeriodicWave(options.periodicWave());

    return node;
=======
OscillatorNode::OscillatorNode(AudioContext& context, float sampleRate)
    : AudioScheduledSourceNode(context)
    // Use musical pitch standard A440 as a default.
    , m_frequency(AudioParam::create(context, 440))
    // Default to no detuning.
    , m_detune(AudioParam::create(context, 0))
{
    setHandler(OscillatorHandler::create(*this, sampleRate, m_frequency->handler(), m_detune->handler()));
}

OscillatorNode* OscillatorNode::create(AudioContext& context, float sampleRate)
{
    return new OscillatorNode(context, sampleRate);
>>>>>>> miniblink49
}

DEFINE_TRACE(OscillatorNode)
{
    visitor->trace(m_frequency);
    visitor->trace(m_detune);
    AudioScheduledSourceNode::trace(visitor);
}

OscillatorHandler& OscillatorNode::oscillatorHandler() const
{
    return static_cast<OscillatorHandler&>(handler());
}

String OscillatorNode::type() const
{
    return oscillatorHandler().type();
}

<<<<<<< HEAD
void OscillatorNode::setType(const String& type,
    ExceptionState& exceptionState)
=======
void OscillatorNode::setType(const String& type, ExceptionState& exceptionState)
>>>>>>> miniblink49
{
    oscillatorHandler().setType(type, exceptionState);
}

AudioParam* OscillatorNode::frequency()
{
    return m_frequency;
}

AudioParam* OscillatorNode::detune()
{
    return m_detune;
}

void OscillatorNode::setPeriodicWave(PeriodicWave* wave)
{
    oscillatorHandler().setPeriodicWave(wave);
}

} // namespace blink
<<<<<<< HEAD
=======

#endif // ENABLE(WEB_AUDIO)
>>>>>>> miniblink49
