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
#include "platform/audio/HRTFDatabase.h"

#include "wtf/MathExtras.h"
#include "wtf/PtrUtil.h"
#include <memory>
=======
#include "config.h"

#if ENABLE(WEB_AUDIO)

#include "platform/audio/HRTFDatabase.h"
>>>>>>> miniblink49

namespace blink {

const int HRTFDatabase::MinElevation = -45;
const int HRTFDatabase::MaxElevation = 90;
const unsigned HRTFDatabase::RawElevationAngleSpacing = 15;
const unsigned HRTFDatabase::NumberOfRawElevations = 10; // -45 -> +90 (each 15 degrees)
const unsigned HRTFDatabase::InterpolationFactor = 1;
const unsigned HRTFDatabase::NumberOfTotalElevations = NumberOfRawElevations * InterpolationFactor;

<<<<<<< HEAD
std::unique_ptr<HRTFDatabase> HRTFDatabase::create(float sampleRate)
{
    return WTF::wrapUnique(new HRTFDatabase(sampleRate));
=======
PassOwnPtr<HRTFDatabase> HRTFDatabase::create(float sampleRate)
{
    OwnPtr<HRTFDatabase> hrtfDatabase = adoptPtr(new HRTFDatabase(sampleRate));
    return hrtfDatabase.release();
>>>>>>> miniblink49
}

HRTFDatabase::HRTFDatabase(float sampleRate)
    : m_elevations(NumberOfTotalElevations)
    , m_sampleRate(sampleRate)
{
    unsigned elevationIndex = 0;
<<<<<<< HEAD
    for (int elevation = MinElevation; elevation <= MaxElevation;
         elevation += RawElevationAngleSpacing) {
        std::unique_ptr<HRTFElevation> hrtfElevation = HRTFElevation::createForSubject("Composite", elevation, sampleRate);
=======
    for (int elevation = MinElevation; elevation <= MaxElevation; elevation += RawElevationAngleSpacing) {
        OwnPtr<HRTFElevation> hrtfElevation = HRTFElevation::createForSubject("Composite", elevation, sampleRate);
>>>>>>> miniblink49
        ASSERT(hrtfElevation.get());
        if (!hrtfElevation.get())
            return;

<<<<<<< HEAD
        m_elevations[elevationIndex] = std::move(hrtfElevation);
=======
        m_elevations[elevationIndex] = hrtfElevation.release();
>>>>>>> miniblink49
        elevationIndex += InterpolationFactor;
    }

    // Now, go back and interpolate elevations.
    if (InterpolationFactor > 1) {
<<<<<<< HEAD
        for (unsigned i = 0; i < NumberOfTotalElevations;
             i += InterpolationFactor) {
=======
        for (unsigned i = 0; i < NumberOfTotalElevations; i += InterpolationFactor) {
>>>>>>> miniblink49
            unsigned j = (i + InterpolationFactor);
            if (j >= NumberOfTotalElevations)
                j = i; // for last elevation interpolate with itself

            // Create the interpolated convolution kernels and delays.
            for (unsigned jj = 1; jj < InterpolationFactor; ++jj) {
                float x = static_cast<float>(jj) / static_cast<float>(InterpolationFactor);
<<<<<<< HEAD
                m_elevations[i + jj] = HRTFElevation::createByInterpolatingSlices(
                    m_elevations[i].get(), m_elevations[j].get(), x, sampleRate);
=======
                m_elevations[i + jj] = HRTFElevation::createByInterpolatingSlices(m_elevations[i].get(), m_elevations[j].get(), x, sampleRate);
>>>>>>> miniblink49
                ASSERT(m_elevations[i + jj].get());
            }
        }
    }
}

<<<<<<< HEAD
void HRTFDatabase::getKernelsFromAzimuthElevation(double azimuthBlend,
    unsigned azimuthIndex,
    double elevationAngle,
    HRTFKernel*& kernelL,
    HRTFKernel*& kernelR,
    double& frameDelayL,
    double& frameDelayR)
{
    unsigned elevationIndex = indexFromElevationAngle(elevationAngle);
    SECURITY_DCHECK(elevationIndex < m_elevations.size() && m_elevations.size() > 0);
=======
void HRTFDatabase::getKernelsFromAzimuthElevation(double azimuthBlend, unsigned azimuthIndex, double elevationAngle, HRTFKernel* &kernelL, HRTFKernel* &kernelR,
                                                  double& frameDelayL, double& frameDelayR)
{
    unsigned elevationIndex = indexFromElevationAngle(elevationAngle);
    ASSERT_WITH_SECURITY_IMPLICATION(elevationIndex < m_elevations.size() && m_elevations.size() > 0);
>>>>>>> miniblink49

    if (!m_elevations.size()) {
        kernelL = 0;
        kernelR = 0;
        return;
    }

    if (elevationIndex > m_elevations.size() - 1)
        elevationIndex = m_elevations.size() - 1;

    HRTFElevation* hrtfElevation = m_elevations[elevationIndex].get();
    ASSERT(hrtfElevation);
    if (!hrtfElevation) {
        kernelL = 0;
        kernelR = 0;
        return;
    }

<<<<<<< HEAD
    hrtfElevation->getKernelsFromAzimuth(azimuthBlend, azimuthIndex, kernelL,
        kernelR, frameDelayL, frameDelayR);
=======
    hrtfElevation->getKernelsFromAzimuth(azimuthBlend, azimuthIndex, kernelL, kernelR, frameDelayL, frameDelayR);
>>>>>>> miniblink49
}

unsigned HRTFDatabase::indexFromElevationAngle(double elevationAngle)
{
    // Clamp to allowed range.
<<<<<<< HEAD
    elevationAngle = clampTo<double, double>(elevationAngle, MinElevation, MaxElevation);
=======
    elevationAngle = std::max(static_cast<double>(MinElevation), elevationAngle);
    elevationAngle = std::min(static_cast<double>(MaxElevation), elevationAngle);
>>>>>>> miniblink49

    unsigned elevationIndex = static_cast<int>(InterpolationFactor * (elevationAngle - MinElevation) / RawElevationAngleSpacing);
    return elevationIndex;
}

} // namespace blink
<<<<<<< HEAD
=======

#endif // ENABLE(WEB_AUDIO)
>>>>>>> miniblink49
