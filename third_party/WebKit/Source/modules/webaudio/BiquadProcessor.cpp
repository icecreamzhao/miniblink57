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

#include "modules/webaudio/BiquadProcessor.h"
#include "modules/webaudio/BiquadDSPKernel.h"
#include "platform/audio/AudioUtilities.h"
#include "wtf/PtrUtil.h"
#include <memory>

namespace blink {

BiquadProcessor::BiquadProcessor(float sampleRate,
    size_t numberOfChannels,
    AudioParamHandler& frequency,
    AudioParamHandler& q,
    AudioParamHandler& gain,
    AudioParamHandler& detune)
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
#include "modules/webaudio/BiquadProcessor.h"

#include "modules/webaudio/BiquadDSPKernel.h"

namespace blink {

BiquadProcessor::BiquadProcessor(float sampleRate, size_t numberOfChannels, AudioParamHandler& frequency, AudioParamHandler& q, AudioParamHandler& gain, AudioParamHandler& detune)
>>>>>>> miniblink49
    : AudioDSPKernelProcessor(sampleRate, numberOfChannels)
    , m_type(LowPass)
    , m_parameter1(frequency)
    , m_parameter2(q)
    , m_parameter3(gain)
    , m_parameter4(detune)
    , m_filterCoefficientsDirty(true)
    , m_hasSampleAccurateValues(false)
{
}

BiquadProcessor::~BiquadProcessor()
{
    if (isInitialized())
        uninitialize();
}

<<<<<<< HEAD
std::unique_ptr<AudioDSPKernel> BiquadProcessor::createKernel()
{
    return WTF::makeUnique<BiquadDSPKernel>(this);
=======
PassOwnPtr<AudioDSPKernel> BiquadProcessor::createKernel()
{
    return adoptPtr(new BiquadDSPKernel(this));
>>>>>>> miniblink49
}

void BiquadProcessor::checkForDirtyCoefficients()
{
<<<<<<< HEAD
    // Deal with smoothing / de-zippering. Start out assuming filter parameters
    // are not changing.

    // The BiquadDSPKernel objects rely on this value to see if they need to
    // re-compute their internal filter coefficients.
=======
    // Deal with smoothing / de-zippering. Start out assuming filter parameters are not changing.

    // The BiquadDSPKernel objects rely on this value to see if they need to re-compute their internal filter coefficients.
>>>>>>> miniblink49
    m_filterCoefficientsDirty = false;
    m_hasSampleAccurateValues = false;

    if (m_parameter1->hasSampleAccurateValues() || m_parameter2->hasSampleAccurateValues() || m_parameter3->hasSampleAccurateValues() || m_parameter4->hasSampleAccurateValues()) {
        m_filterCoefficientsDirty = true;
        m_hasSampleAccurateValues = true;
    } else {
        if (m_hasJustReset) {
<<<<<<< HEAD
            // Snap to exact values first time after reset, then smooth for subsequent
            // changes.
=======
            // Snap to exact values first time after reset, then smooth for subsequent changes.
>>>>>>> miniblink49
            m_parameter1->resetSmoothedValue();
            m_parameter2->resetSmoothedValue();
            m_parameter3->resetSmoothedValue();
            m_parameter4->resetSmoothedValue();
            m_filterCoefficientsDirty = true;
            m_hasJustReset = false;
        } else {
<<<<<<< HEAD
            // Smooth all of the filter parameters. If they haven't yet converged to
            // their target value then mark coefficients as dirty.
=======
            // Smooth all of the filter parameters. If they haven't yet converged to their target value then mark coefficients as dirty.
>>>>>>> miniblink49
            bool isStable1 = m_parameter1->smooth();
            bool isStable2 = m_parameter2->smooth();
            bool isStable3 = m_parameter3->smooth();
            bool isStable4 = m_parameter4->smooth();
            if (!(isStable1 && isStable2 && isStable3 && isStable4))
                m_filterCoefficientsDirty = true;
        }
    }
}

<<<<<<< HEAD
void BiquadProcessor::process(const AudioBus* source,
    AudioBus* destination,
    size_t framesToProcess)
=======
void BiquadProcessor::process(const AudioBus* source, AudioBus* destination, size_t framesToProcess)
>>>>>>> miniblink49
{
    if (!isInitialized()) {
        destination->zero();
        return;
    }

<<<<<<< HEAD
    // Synchronize with possible dynamic changes to the impulse response.
    MutexTryLocker tryLocker(m_processLock);
    if (!tryLocker.locked()) {
        // Can't get the lock. We must be in the middle of changing something.
        destination->zero();
        return;
    }

    checkForDirtyCoefficients();

    // For each channel of our input, process using the corresponding
    // BiquadDSPKernel into the output channel.
    for (unsigned i = 0; i < m_kernels.size(); ++i)
        m_kernels[i]->process(source->channel(i)->data(),
            destination->channel(i)->mutableData(),
            framesToProcess);
}

void BiquadProcessor::processOnlyAudioParams(size_t framesToProcess)
{
    DCHECK_LE(framesToProcess, AudioUtilities::kRenderQuantumFrames);

    float values[AudioUtilities::kRenderQuantumFrames];

    m_parameter1->calculateSampleAccurateValues(values, framesToProcess);
    m_parameter2->calculateSampleAccurateValues(values, framesToProcess);
    m_parameter3->calculateSampleAccurateValues(values, framesToProcess);
    m_parameter4->calculateSampleAccurateValues(values, framesToProcess);
=======
    checkForDirtyCoefficients();

    // For each channel of our input, process using the corresponding BiquadDSPKernel into the output channel.
    for (unsigned i = 0; i < m_kernels.size(); ++i)
        m_kernels[i]->process(source->channel(i)->data(), destination->channel(i)->mutableData(), framesToProcess);
>>>>>>> miniblink49
}

void BiquadProcessor::setType(FilterType type)
{
    if (type != m_type) {
        m_type = type;
        reset(); // The filter state must be reset only if the type has changed.
    }
}

<<<<<<< HEAD
void BiquadProcessor::getFrequencyResponse(int nFrequencies,
    const float* frequencyHz,
    float* magResponse,
    float* phaseResponse)
=======
void BiquadProcessor::getFrequencyResponse(int nFrequencies, const float* frequencyHz, float* magResponse, float* phaseResponse)
>>>>>>> miniblink49
{
    // Compute the frequency response on a separate temporary kernel
    // to avoid interfering with the processing running in the audio
    // thread on the main kernels.

<<<<<<< HEAD
    std::unique_ptr<BiquadDSPKernel> responseKernel = WTF::makeUnique<BiquadDSPKernel>(this);
    responseKernel->getFrequencyResponse(nFrequencies, frequencyHz, magResponse,
        phaseResponse);
}

} // namespace blink
=======
    OwnPtr<BiquadDSPKernel> responseKernel = adoptPtr(new BiquadDSPKernel(this));
    responseKernel->getFrequencyResponse(nFrequencies, frequencyHz, magResponse, phaseResponse);
}

} // namespace blink

#endif // ENABLE(WEB_AUDIO)
>>>>>>> miniblink49
