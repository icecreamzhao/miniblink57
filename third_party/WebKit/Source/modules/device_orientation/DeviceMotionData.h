/*
 * Copyright (C) 2010 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef DeviceMotionData_h
#define DeviceMotionData_h

#include "platform/heap/Handle.h"

namespace blink {

class WebDeviceMotionData;

class DeviceMotionData final : public GarbageCollected<DeviceMotionData> {
public:
<<<<<<< HEAD
    class Acceleration final
        : public GarbageCollected<DeviceMotionData::Acceleration> {
    public:
        static Acceleration* create(bool canProvideX,
            double x,
            bool canProvideY,
            double y,
            bool canProvideZ,
            double z);
=======

    class Acceleration final : public GarbageCollected<DeviceMotionData::Acceleration> {
    public:
        static Acceleration* create(bool canProvideX, double x, bool canProvideY, double y, bool canProvideZ, double z);
>>>>>>> miniblink49
        DEFINE_INLINE_TRACE() { }

        bool canProvideX() const { return m_canProvideX; }
        bool canProvideY() const { return m_canProvideY; }
        bool canProvideZ() const { return m_canProvideZ; }

        double x() const { return m_x; }
        double y() const { return m_y; }
        double z() const { return m_z; }

    private:
<<<<<<< HEAD
        Acceleration(bool canProvideX,
            double x,
            bool canProvideY,
            double y,
            bool canProvideZ,
            double z);
=======
        Acceleration(bool canProvideX, double x, bool canProvideY, double y, bool canProvideZ, double z);
>>>>>>> miniblink49

        double m_x;
        double m_y;
        double m_z;

        bool m_canProvideX;
        bool m_canProvideY;
        bool m_canProvideZ;
    };

<<<<<<< HEAD
    class RotationRate final
        : public GarbageCollected<DeviceMotionData::RotationRate> {
    public:
        static RotationRate* create(bool canProvideAlpha,
            double alpha,
            bool canProvideBeta,
            double beta,
            bool canProvideGamma,
            double gamma);
=======
    class RotationRate final : public GarbageCollected<DeviceMotionData::RotationRate> {
    public:
        static RotationRate* create(bool canProvideAlpha, double alpha, bool canProvideBeta,  double beta, bool canProvideGamma, double gamma);
>>>>>>> miniblink49
        DEFINE_INLINE_TRACE() { }

        bool canProvideAlpha() const { return m_canProvideAlpha; }
        bool canProvideBeta() const { return m_canProvideBeta; }
        bool canProvideGamma() const { return m_canProvideGamma; }

        double alpha() const { return m_alpha; }
        double beta() const { return m_beta; }
        double gamma() const { return m_gamma; }

    private:
<<<<<<< HEAD
        RotationRate(bool canProvideAlpha,
            double alpha,
            bool canProvideBeta,
            double beta,
            bool canProvideGamma,
            double gamma);
=======
        RotationRate(bool canProvideAlpha, double alpha, bool canProvideBeta,  double beta, bool canProvideGamma, double gamma);
>>>>>>> miniblink49

        double m_alpha;
        double m_beta;
        double m_gamma;

        bool m_canProvideAlpha;
        bool m_canProvideBeta;
        bool m_canProvideGamma;
    };

    static DeviceMotionData* create();
<<<<<<< HEAD
    static DeviceMotionData* create(Acceleration*,
=======
    static DeviceMotionData* create(
        Acceleration*,
>>>>>>> miniblink49
        Acceleration* accelerationIncludingGravity,
        RotationRate*,
        bool canProvideInterval,
        double interval);
    static DeviceMotionData* create(const WebDeviceMotionData&);
    DECLARE_TRACE();

<<<<<<< HEAD
    Acceleration* getAcceleration() const { return m_acceleration.get(); }
    Acceleration* getAccelerationIncludingGravity() const
    {
        return m_accelerationIncludingGravity.get();
    }
    RotationRate* getRotationRate() const { return m_rotationRate.get(); }
=======
    Acceleration* acceleration() const { return m_acceleration.get(); }
    Acceleration* accelerationIncludingGravity() const { return m_accelerationIncludingGravity.get(); }
    RotationRate* rotationRate() const { return m_rotationRate.get(); }
>>>>>>> miniblink49

    bool canProvideInterval() const { return m_canProvideInterval; }
    double interval() const { return m_interval; }

    bool canProvideEventData() const;

private:
    DeviceMotionData();
<<<<<<< HEAD
    DeviceMotionData(Acceleration*,
        Acceleration* accelerationIncludingGravity,
        RotationRate*,
        bool canProvideInterval,
        double interval);
=======
    DeviceMotionData(Acceleration*, Acceleration* accelerationIncludingGravity, RotationRate*, bool canProvideInterval, double interval);
>>>>>>> miniblink49

    Member<Acceleration> m_acceleration;
    Member<Acceleration> m_accelerationIncludingGravity;
    Member<RotationRate> m_rotationRate;
    bool m_canProvideInterval;
    double m_interval;
};

} // namespace blink

#endif // DeviceMotionData_h
