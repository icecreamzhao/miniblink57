/*
 * Copyright (c) 2014, Google Inc. All rights reserved.
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

#include "core/animation/AnimationClock.h"

#include "wtf/CurrentTime.h"
#include <math.h>

namespace {

// FIXME: This is an approximation of time between frames, used when
// ticking the animation clock outside of animation frame callbacks.
// Ideally this would be generated by the compositor.
const double approximateFrameTime = 1 / 60.0;
}

namespace blink {

unsigned AnimationClock::s_currentlyRunningTask = 0;

void AnimationClock::updateTime(double time)
{
    if (time > m_time)
        m_time = time;
    m_taskForWhichTimeWasCalculated = s_currentlyRunningTask;
}

double AnimationClock::currentTime()
{
    if (m_taskForWhichTimeWasCalculated != s_currentlyRunningTask) {
        const double currentTime = m_monotonicallyIncreasingTime();
        if (m_time < currentTime) {
            // Advance to the first estimated frame after the current time.
            const double frameShift = fmod(currentTime - m_time, approximateFrameTime);
            const double newTime = currentTime + (approximateFrameTime - frameShift);
            DCHECK_GE(newTime, currentTime);
            DCHECK_LE(newTime, currentTime + approximateFrameTime);
            updateTime(newTime);
        } else {
            m_taskForWhichTimeWasCalculated = s_currentlyRunningTask;
        }
    }
    return m_time;
}

void AnimationClock::resetTimeForTesting(double time)
{
    m_time = time;
    m_taskForWhichTimeWasCalculated = 0;
    s_currentlyRunningTask = 0;
}

} // namespace blink
