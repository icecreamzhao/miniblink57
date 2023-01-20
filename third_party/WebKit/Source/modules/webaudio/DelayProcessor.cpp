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

#include "modules/webaudio/DelayProcessor.h"
#include "modules/webaudio/DelayDSPKernel.h"
#include "platform/audio/AudioUtilities.h"
#include "wtf/PtrUtil.h"
#include <memory>

namespace blink {

DelayProcessor::DelayProcessor(float sampleRate,
    unsigned numberOfChannels,
    AudioParamHandler& delayTime,
    double maxDelayTime)
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
#include "modules/webaudio/DelayProcessor.h"

#include "modules/webaudio/DelayDSPKernel.h"

namespace blink {

DelayProcessor::DelayProcessor(float sampleRate, unsigned numberOfChannels, AudioParamHandler& delayTime, double maxDelayTime)
>>>>>>> miniblink49
    : AudioDSPKernelProcessor(sampleRate, numberOfChannels)
    , m_delayTime(delayTime)
    , m_maxDelayTime(maxDelayTime)
{
}

DelayProcessor::~DelayProcessor()
{
    if (isInitialized())
        uninitialize();
}

<<<<<<< HEAD
std::unique_ptr<AudioDSPKernel> DelayProcessor::createKernel()
{
    return WTF::makeUnique<DelayDSPKernel>(this);
}

void DelayProcessor::processOnlyAudioParams(size_t framesToProcess)
{
    DCHECK_LE(framesToProcess, AudioUtilities::kRenderQuantumFrames);

    float values[AudioUtilities::kRenderQuantumFrames];

    m_delayTime->calculateSampleAccurateValues(values, framesToProcess);
}

} // namespace blink
=======
PassOwnPtr<AudioDSPKernel> DelayProcessor::createKernel()
{
    return adoptPtr(new DelayDSPKernel(this));
}

} // namespace blink

#endif // ENABLE(WEB_AUDIO)
>>>>>>> miniblink49
