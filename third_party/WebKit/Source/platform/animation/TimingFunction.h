/*
 * Copyright (C) 2000 Lars Knoll (knoll@kde.org)
 *           (C) 2000 Antti Koivisto (koivisto@kde.org)
 *           (C) 2000 Dirk Mueller (mueller@kde.org)
 * Copyright (C) 2003, 2005, 2006, 2007, 2008 Apple Inc. All rights reserved.
 * Copyright (C) 2006 Graham Dennis (graham.dennis@gmail.com)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 */

#ifndef TimingFunction_h
#define TimingFunction_h

<<<<<<< HEAD
#include "cc/animation/timing_function.h"
#include "platform/PlatformExport.h"
#include "wtf/Assertions.h"
#include "wtf/PassRefPtr.h"
#include "wtf/RefCounted.h"
#include "wtf/StdLibExtras.h"
=======
#include "platform/animation/AnimationUtilities.h" // For blend()
#include "platform/animation/UnitBezier.h"
#include "platform/heap/Handle.h"
#include "platform/heap/Heap.h"
#include "wtf/OwnPtr.h"
#include "wtf/PassOwnPtr.h"
#include "wtf/PassRefPtr.h"
#include "wtf/RefCounted.h"
#include "wtf/StdLibExtras.h"
#include "wtf/text/StringBuilder.h"
>>>>>>> miniblink49
#include "wtf/text/WTFString.h"

namespace blink {

class PLATFORM_EXPORT TimingFunction : public RefCounted<TimingFunction> {
public:
<<<<<<< HEAD
    using Type = cc::TimingFunction::Type;

    virtual ~TimingFunction() { }

    Type getType() const { return m_type; }

    virtual String toString() const = 0;

    // Evaluates the timing function at the given fraction. The accuracy parameter
    // provides a hint as to the required accuracy and is not guaranteed.
=======

    enum Type {
        LinearFunction, CubicBezierFunction, StepsFunction
    };

    virtual ~TimingFunction() { }

    Type type() const { return m_type; }

    virtual String toString() const = 0;

    // Evaluates the timing function at the given fraction. The accuracy parameter provides a hint as to the required
    // accuracy and is not guaranteed.
>>>>>>> miniblink49
    virtual double evaluate(double fraction, double accuracy) const = 0;

    // This function returns the minimum and maximum values obtainable when
    // calling evaluate();
    virtual void range(double* minValue, double* maxValue) const = 0;

<<<<<<< HEAD
    // Create CC instance.
    virtual std::unique_ptr<cc::TimingFunction> cloneToCC() const = 0;
=======
    enum RangeHalf {
        Lower, // Timing function values < 0.5
        Upper // Timing function values >= 0.5
    };

    struct PartitionRegion {
        RangeHalf half;
        double start; // inclusive
        double end; // exclusive

        PartitionRegion(RangeHalf half, double start, double end)
            : half(half)
            , start(start)
            , end(end)
        { }
    };

    // Partitions the timing function into a number of regions,
    // representing the ranges in which the function's value is < 0.5
    // and >= 0.5, and hence whether interpolation 0 or 1 should be
    // used.
    virtual void partition(Vector<PartitionRegion>& regions) const = 0;
>>>>>>> miniblink49

protected:
    TimingFunction(Type type)
        : m_type(type)
    {
    }

private:
    Type m_type;
};

class PLATFORM_EXPORT LinearTimingFunction final : public TimingFunction {
public:
    static LinearTimingFunction* shared()
    {
<<<<<<< HEAD
        DEFINE_STATIC_REF(LinearTimingFunction, linear,
            (adoptRef(new LinearTimingFunction())));
=======
        DEFINE_STATIC_REF(LinearTimingFunction, linear, (adoptRef(new LinearTimingFunction())));
>>>>>>> miniblink49
        return linear;
    }

    ~LinearTimingFunction() override { }

<<<<<<< HEAD
    // TimingFunction implementation.
    String toString() const override;
    double evaluate(double fraction, double) const override;
    void range(double* minValue, double* maxValue) const override;
    std::unique_ptr<cc::TimingFunction> cloneToCC() const override;

private:
    LinearTimingFunction()
        : TimingFunction(Type::LINEAR)
=======
    String toString() const override;

    double evaluate(double fraction, double) const override;
    void range(double* minValue, double* maxValue) const override;
    void partition(Vector<PartitionRegion>& regions) const override;
private:
    LinearTimingFunction()
        : TimingFunction(LinearFunction)
>>>>>>> miniblink49
    {
    }
};

class PLATFORM_EXPORT CubicBezierTimingFunction final : public TimingFunction {
public:
<<<<<<< HEAD
    using EaseType = cc::CubicBezierTimingFunction::EaseType;

    static PassRefPtr<CubicBezierTimingFunction> create(double x1,
        double y1,
        double x2,
        double y2)
    {
        return adoptRef(new CubicBezierTimingFunction(x1, y1, x2, y2));
    }

    static CubicBezierTimingFunction* preset(EaseType easeType)
    {
        DEFINE_STATIC_REF(
            CubicBezierTimingFunction, ease,
            (adoptRef(new CubicBezierTimingFunction(EaseType::EASE))));
        DEFINE_STATIC_REF(
            CubicBezierTimingFunction, easeIn,
            (adoptRef(new CubicBezierTimingFunction(EaseType::EASE_IN))));
        DEFINE_STATIC_REF(
            CubicBezierTimingFunction, easeOut,
            (adoptRef(new CubicBezierTimingFunction(EaseType::EASE_OUT))));
        DEFINE_STATIC_REF(
            CubicBezierTimingFunction, easeInOut,
            (adoptRef(new CubicBezierTimingFunction(EaseType::EASE_IN_OUT))));

        switch (easeType) {
        case EaseType::EASE:
            return ease;
        case EaseType::EASE_IN:
            return easeIn;
        case EaseType::EASE_OUT:
            return easeOut;
        case EaseType::EASE_IN_OUT:
            return easeInOut;
        default:
            NOTREACHED();
            return nullptr;
=======
    enum SubType {
        Ease,
        EaseIn,
        EaseOut,
        EaseInOut,
        Custom
    };

    static PassRefPtr<CubicBezierTimingFunction> create(double x1, double y1, double x2, double y2)
    {
        return adoptRef(new CubicBezierTimingFunction(Custom, x1, y1, x2, y2));
    }

    static CubicBezierTimingFunction* preset(SubType subType)
    {
        switch (subType) {
        case Ease:
            {
                DEFINE_STATIC_REF(CubicBezierTimingFunction, ease, (adoptRef(new CubicBezierTimingFunction(Ease, 0.25, 0.1, 0.25, 1.0))));
                return ease;
            }
        case EaseIn:
            {
                DEFINE_STATIC_REF(CubicBezierTimingFunction, easeIn, (adoptRef(new CubicBezierTimingFunction(EaseIn, 0.42, 0.0, 1.0, 1.0))));
                return easeIn;
            }
        case EaseOut:
            {
                DEFINE_STATIC_REF(CubicBezierTimingFunction, easeOut, (adoptRef(new CubicBezierTimingFunction(EaseOut, 0.0, 0.0, 0.58, 1.0))));
                return easeOut;
            }
        case EaseInOut:
            {
                DEFINE_STATIC_REF(CubicBezierTimingFunction, easeInOut, (adoptRef(new CubicBezierTimingFunction(EaseInOut, 0.42, 0.0, 0.58, 1.0))));
                return easeInOut;
            }
        default:
            ASSERT_NOT_REACHED();
            return 0;
>>>>>>> miniblink49
        }
    }

    ~CubicBezierTimingFunction() override { }

<<<<<<< HEAD
    // TimingFunction implementation.
    String toString() const override;
    double evaluate(double fraction, double accuracy) const override;
    void range(double* minValue, double* maxValue) const override;
    std::unique_ptr<cc::TimingFunction> cloneToCC() const override;

    double x1() const
    {
        DCHECK_EQ(getEaseType(), EaseType::CUSTOM);
        return m_x1;
    }
    double y1() const
    {
        DCHECK_EQ(getEaseType(), EaseType::CUSTOM);
        return m_y1;
    }
    double x2() const
    {
        DCHECK_EQ(getEaseType(), EaseType::CUSTOM);
        return m_x2;
    }
    double y2() const
    {
        DCHECK_EQ(getEaseType(), EaseType::CUSTOM);
        return m_y2;
    }
    EaseType getEaseType() const { return m_bezier->ease_type(); }

private:
    explicit CubicBezierTimingFunction(EaseType easeType)
        : TimingFunction(Type::CUBIC_BEZIER)
        , m_bezier(cc::CubicBezierTimingFunction::CreatePreset(easeType))
        , m_x1()
        , m_y1()
        , m_x2()
        , m_y2()
    {
    }

    CubicBezierTimingFunction(double x1, double y1, double x2, double y2)
        : TimingFunction(Type::CUBIC_BEZIER)
        , m_bezier(cc::CubicBezierTimingFunction::Create(x1, y1, x2, y2))
=======
    String toString() const override;

    double evaluate(double fraction, double accuracy) const override;
    void range(double* minValue, double* maxValue) const override;
    void partition(Vector<PartitionRegion>& regions) const override;

    double x1() const { return m_x1; }
    double y1() const { return m_y1; }
    double x2() const { return m_x2; }
    double y2() const { return m_y2; }

    SubType subType() const { return m_subType; }

private:
    explicit CubicBezierTimingFunction(SubType subType, double x1, double y1, double x2, double y2)
        : TimingFunction(CubicBezierFunction)
>>>>>>> miniblink49
        , m_x1(x1)
        , m_y1(y1)
        , m_x2(x2)
        , m_y2(y2)
<<<<<<< HEAD
    {
    }

    std::unique_ptr<cc::CubicBezierTimingFunction> m_bezier;

    // TODO(loyso): Get these values from m_bezier->bezier_ (gfx::CubicBezier)
    const double m_x1;
    const double m_y1;
    const double m_x2;
    const double m_y2;
=======
        , m_subType(subType)
    {
    }

    // Finds points on the cubic bezier that cross the given horizontal
    // line, storing their x values in solution1-3 and returning the
    // number of solutions found.
    size_t findIntersections(double intersectionY, double& solution1, double& solution2, double& solution3) const;

    double m_x1;
    double m_y1;
    double m_x2;
    double m_y2;
    SubType m_subType;
    mutable OwnPtr<UnitBezier> m_bezier;
>>>>>>> miniblink49
};

class PLATFORM_EXPORT StepsTimingFunction final : public TimingFunction {
public:
<<<<<<< HEAD
    using StepPosition = cc::StepsTimingFunction::StepPosition;

    static PassRefPtr<StepsTimingFunction> create(int steps,
        StepPosition stepPosition)
    {
        return adoptRef(new StepsTimingFunction(steps, stepPosition));
    }

    static StepsTimingFunction* preset(StepPosition position)
    {
        DEFINE_STATIC_REF(StepsTimingFunction, start,
            create(1, StepPosition::START));
        DEFINE_STATIC_REF(StepsTimingFunction, middle,
            create(1, StepPosition::MIDDLE));
        DEFINE_STATIC_REF(StepsTimingFunction, end, create(1, StepPosition::END));
        switch (position) {
        case StepPosition::START:
            return start;
        case StepPosition::MIDDLE:
            return middle;
        case StepPosition::END:
            return end;
        default:
            NOTREACHED();
=======
    enum StepAtPosition {
        Start,
        Middle,
        End
    };

    static PassRefPtr<StepsTimingFunction> create(int steps, StepAtPosition stepAtPosition)
    {
        return adoptRef(new StepsTimingFunction(steps, stepAtPosition));
    }

    static StepsTimingFunction* preset(StepAtPosition position)
    {
        DEFINE_STATIC_REF(StepsTimingFunction, start, create(1, Start));
        DEFINE_STATIC_REF(StepsTimingFunction, middle, create(1, Middle));
        DEFINE_STATIC_REF(StepsTimingFunction, end, create(1, End));
        switch (position) {
        case Start:
            return start;
        case Middle:
            return middle;
        case End:
            return end;
        default:
            ASSERT_NOT_REACHED();
>>>>>>> miniblink49
            return end;
        }
    }

<<<<<<< HEAD
    ~StepsTimingFunction() override { }

    // TimingFunction implementation.
    String toString() const override;
    double evaluate(double fraction, double) const override;
    void range(double* minValue, double* maxValue) const override;
    std::unique_ptr<cc::TimingFunction> cloneToCC() const override;

    int numberOfSteps() const { return m_steps->steps(); }
    StepPosition getStepPosition() const { return m_steps->step_position(); }

private:
    StepsTimingFunction(int steps, StepPosition stepPosition)
        : TimingFunction(Type::STEPS)
        , m_steps(cc::StepsTimingFunction::Create(steps, stepPosition))
    {
    }

    std::unique_ptr<cc::StepsTimingFunction> m_steps;
};

PLATFORM_EXPORT PassRefPtr<TimingFunction> createCompositorTimingFunctionFromCC(
    const cc::TimingFunction*);

PLATFORM_EXPORT bool operator==(const LinearTimingFunction&,
    const TimingFunction&);
PLATFORM_EXPORT bool operator==(const CubicBezierTimingFunction&,
    const TimingFunction&);
PLATFORM_EXPORT bool operator==(const StepsTimingFunction&,
    const TimingFunction&);
=======

    ~StepsTimingFunction() override { }

    String toString() const override;

    double evaluate(double fraction, double) const override;
    void range(double* minValue, double* maxValue) const override;
    void partition(Vector<PartitionRegion>& regions) const override;

    int numberOfSteps() const { return m_steps; }
    StepAtPosition stepAtPosition() const { return m_stepAtPosition; }

private:
    StepsTimingFunction(int steps, StepAtPosition stepAtPosition)
        : TimingFunction(StepsFunction)
        , m_steps(steps)
        , m_stepAtPosition(stepAtPosition)
    {
    }

    int m_steps;
    StepAtPosition m_stepAtPosition;
};

PLATFORM_EXPORT bool operator==(const LinearTimingFunction&, const TimingFunction&);
PLATFORM_EXPORT bool operator==(const CubicBezierTimingFunction&, const TimingFunction&);
PLATFORM_EXPORT bool operator==(const StepsTimingFunction&, const TimingFunction&);
>>>>>>> miniblink49

PLATFORM_EXPORT bool operator==(const TimingFunction&, const TimingFunction&);
PLATFORM_EXPORT bool operator!=(const TimingFunction&, const TimingFunction&);

<<<<<<< HEAD
#define DEFINE_TIMING_FUNCTION_TYPE_CASTS(typeName, enumName)          \
    DEFINE_TYPE_CASTS(typeName##TimingFunction, TimingFunction, value, \
        value->getType() == TimingFunction::Type::enumName,            \
        value.getType() == TimingFunction::Type::enumName)

DEFINE_TIMING_FUNCTION_TYPE_CASTS(Linear, LINEAR);
DEFINE_TIMING_FUNCTION_TYPE_CASTS(CubicBezier, CUBIC_BEZIER);
DEFINE_TIMING_FUNCTION_TYPE_CASTS(Steps, STEPS);
=======
#define DEFINE_TIMING_FUNCTION_TYPE_CASTS(typeName) \
    DEFINE_TYPE_CASTS( \
        typeName##TimingFunction, TimingFunction, value, \
        value->type() == TimingFunction::typeName##Function, \
        value.type() == TimingFunction::typeName##Function)

DEFINE_TIMING_FUNCTION_TYPE_CASTS(Linear);
DEFINE_TIMING_FUNCTION_TYPE_CASTS(CubicBezier);
DEFINE_TIMING_FUNCTION_TYPE_CASTS(Steps);
>>>>>>> miniblink49

} // namespace blink

#endif // TimingFunction_h
