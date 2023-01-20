/*
 * Copyright (C) 2010 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 * 3.  Neither the name of Apple Computer, Inc. ("Apple") nor the names of
 *     its contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

<<<<<<< HEAD
#include "platform/audio/Distance.h"
#include "wtf/Assertions.h"
#include "wtf/MathExtras.h"
#include <algorithm>
#include <math.h>
=======
#include "config.h"

#if ENABLE(WEB_AUDIO)

#include "platform/audio/Distance.h"
#include "wtf/Assertions.h"

#include <math.h>
#include <algorithm>
>>>>>>> miniblink49

namespace blink {

DistanceEffect::DistanceEffect()
    : m_model(ModelInverse)
<<<<<<< HEAD
=======
    , m_isClamped(true)
>>>>>>> miniblink49
    , m_refDistance(1.0)
    , m_maxDistance(10000.0)
    , m_rolloffFactor(1.0)
{
}

double DistanceEffect::gain(double distance)
{
<<<<<<< HEAD
    // Don't get closer than the reference distance or go beyond the maximum
    // distance.
    distance = clampTo(distance, m_refDistance, m_maxDistance);
=======
    // don't go beyond maximum distance
    distance = std::min(distance, m_maxDistance);

    // if clamped, don't get closer than reference distance
    if (m_isClamped)
        distance = std::max(distance, m_refDistance);
>>>>>>> miniblink49

    switch (m_model) {
    case ModelLinear:
        return linearGain(distance);
    case ModelInverse:
        return inverseGain(distance);
    case ModelExponential:
        return exponentialGain(distance);
    }
<<<<<<< HEAD
    NOTREACHED();
=======
    ASSERT_NOT_REACHED();
>>>>>>> miniblink49
    return 0.0;
}

double DistanceEffect::linearGain(double distance)
{
    // We want a gain that decreases linearly from m_refDistance to
    // m_maxDistance. The gain is 1 at m_refDistance.
<<<<<<< HEAD
    return (1.0 - clampTo(m_rolloffFactor, 0.0, 1.0) * (distance - m_refDistance) / (m_maxDistance - m_refDistance));
=======
    return (1.0 - m_rolloffFactor * (distance - m_refDistance) / (m_maxDistance - m_refDistance));
>>>>>>> miniblink49
}

double DistanceEffect::inverseGain(double distance)
{
<<<<<<< HEAD
    return m_refDistance / (m_refDistance + clampTo(m_rolloffFactor, 0.0) * (distance - m_refDistance));
=======
    return m_refDistance / (m_refDistance + m_rolloffFactor * (distance - m_refDistance));
>>>>>>> miniblink49
}

double DistanceEffect::exponentialGain(double distance)
{
<<<<<<< HEAD
    return pow(distance / m_refDistance, -clampTo(m_rolloffFactor, 0.0));
}

} // namespace blink
=======
    return pow(distance / m_refDistance, -m_rolloffFactor);
}

} // namespace blink

#endif // ENABLE(WEB_AUDIO)
>>>>>>> miniblink49
