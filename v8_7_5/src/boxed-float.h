// Copyright 2017 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef V8_BOXED_FLOAT_H_
#define V8_BOXED_FLOAT_H_

#include <cmath>
#include "src/base/macros.h"
#include "src/globals.h"

namespace v8 {
namespace internal {

    // TODO(ahaas): Make these classes with the one in double.h

    // Safety wrapper for a 32-bit floating-point value to make sure we don't lose
    // the exact bit pattern during deoptimization when passing this value.
    class Float32 {
    public:
        Float32() = default;

        // This constructor does not guarantee that bit pattern of the input value
        // is preserved if the input is a NaN.
        explicit Float32(float value)
            : bit_pattern_(bit_cast<uint32_t>(value))
        {
            // Check that the provided value is not a NaN, because the bit pattern of a
            // NaN may be changed by a bit_cast, e.g. for signalling NaNs on ia32.
            DCHECK(!/*std::*/isnan(value));
        }

        uint32_t get_bits() const { return bit_pattern_; }

        float get_scalar() const { return bit_cast<float>(bit_pattern_); }

        bool is_nan() const
        {
            // Even though {get_scalar()} might flip the quiet NaN bit, it's ok here,
            // because this does not change the is_nan property.
            return /*std::*/isnan(get_scalar());
        }

        // Return a pointer to the field storing the bit pattern. Used in code
        // generation tests to store generated values there directly.
        uint32_t* get_bits_address() { return &bit_pattern_; }

        static constexpr Float32 FromBits(uint32_t bits) { return Float32(bits); }

    private:
        uint32_t bit_pattern_ = 0;

        explicit constexpr Float32(uint32_t bit_pattern)
            : bit_pattern_(bit_pattern)
        {
        }
    };

    ASSERT_TRIVIALLY_COPYABLE(Float32);

    // Safety wrapper for a 64-bit floating-point value to make sure we don't lose
    // the exact bit pattern during deoptimization when passing this value.
    // TODO(ahaas): Unify this class with Double in double.h
    class Float64 {
    public:
        Float64() = default;

        // This constructor does not guarantee that bit pattern of the input value
        // is preserved if the input is a NaN.
        explicit Float64(double value)
            : bit_pattern_(bit_cast<uint64_t>(value))
        {
            // Check that the provided value is not a NaN, because the bit pattern of a
            // NaN may be changed by a bit_cast, e.g. for signalling NaNs on ia32.
            DCHECK(!/*std::*/isnan(value));
        }

        uint64_t get_bits() const { return bit_pattern_; }
        double get_scalar() const { return bit_cast<double>(bit_pattern_); }
        bool is_hole_nan() const { return bit_pattern_ == kHoleNanInt64; }
        bool is_nan() const
        {
            // Even though {get_scalar()} might flip the quiet NaN bit, it's ok here,
            // because this does not change the is_nan property.
            return /*std::*/isnan(get_scalar());
        }

        // Return a pointer to the field storing the bit pattern. Used in code
        // generation tests to store generated values there directly.
        uint64_t* get_bits_address() { return &bit_pattern_; }

        static constexpr Float64 FromBits(uint64_t bits) { return Float64(bits); }

    private:
        uint64_t bit_pattern_ = 0;

        explicit constexpr Float64(uint64_t bit_pattern)
            : bit_pattern_(bit_pattern)
        {
        }
    };

    ASSERT_TRIVIALLY_COPYABLE(Float64);

} // namespace internal
} // namespace v8

#endif // V8_BOXED_FLOAT_H_
