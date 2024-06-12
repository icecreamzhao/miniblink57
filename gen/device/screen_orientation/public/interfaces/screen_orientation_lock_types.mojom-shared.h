// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_SCREEN_ORIENTATION_PUBLIC_INTERFACES_SCREEN_ORIENTATION_LOCK_TYPES_MOJOM_SHARED_H_
#define DEVICE_SCREEN_ORIENTATION_PUBLIC_INTERFACES_SCREEN_ORIENTATION_LOCK_TYPES_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "device/screen_orientation/public/interfaces/screen_orientation_lock_types.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"

namespace device {
namespace mojom {

} // namespace mojom
} // namespace device

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace device {
namespace mojom {

    enum class ScreenOrientationLockResult : int32_t {
        SCREEN_ORIENTATION_LOCK_RESULT_SUCCESS,
        SCREEN_ORIENTATION_LOCK_RESULT_ERROR_NOT_AVAILABLE,
        SCREEN_ORIENTATION_LOCK_RESULT_ERROR_FULLSCREEN_REQUIRED,
        SCREEN_ORIENTATION_LOCK_RESULT_ERROR_CANCELED,
    };

    inline std::ostream& operator<<(std::ostream& os, ScreenOrientationLockResult value)
    {
        switch (value) {
        case ScreenOrientationLockResult::SCREEN_ORIENTATION_LOCK_RESULT_SUCCESS:
            return os << "ScreenOrientationLockResult::SCREEN_ORIENTATION_LOCK_RESULT_SUCCESS";
        case ScreenOrientationLockResult::SCREEN_ORIENTATION_LOCK_RESULT_ERROR_NOT_AVAILABLE:
            return os << "ScreenOrientationLockResult::SCREEN_ORIENTATION_LOCK_RESULT_ERROR_NOT_AVAILABLE";
        case ScreenOrientationLockResult::SCREEN_ORIENTATION_LOCK_RESULT_ERROR_FULLSCREEN_REQUIRED:
            return os << "ScreenOrientationLockResult::SCREEN_ORIENTATION_LOCK_RESULT_ERROR_FULLSCREEN_REQUIRED";
        case ScreenOrientationLockResult::SCREEN_ORIENTATION_LOCK_RESULT_ERROR_CANCELED:
            return os << "ScreenOrientationLockResult::SCREEN_ORIENTATION_LOCK_RESULT_ERROR_CANCELED";
        default:
            return os << "Unknown ScreenOrientationLockResult value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(ScreenOrientationLockResult value)
    {
        return internal::ScreenOrientationLockResult_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class ScreenOrientationLockType : int32_t {
        DEFAULT = 0,
        PORTRAIT_PRIMARY,
        PORTRAIT_SECONDARY,
        LANDSCAPE_PRIMARY,
        LANDSCAPE_SECONDARY,
        ANY,
        LANDSCAPE,
        PORTRAIT,
        NATURAL,
    };

    inline std::ostream& operator<<(std::ostream& os, ScreenOrientationLockType value)
    {
        switch (value) {
        case ScreenOrientationLockType::DEFAULT:
            return os << "ScreenOrientationLockType::DEFAULT";
        case ScreenOrientationLockType::PORTRAIT_PRIMARY:
            return os << "ScreenOrientationLockType::PORTRAIT_PRIMARY";
        case ScreenOrientationLockType::PORTRAIT_SECONDARY:
            return os << "ScreenOrientationLockType::PORTRAIT_SECONDARY";
        case ScreenOrientationLockType::LANDSCAPE_PRIMARY:
            return os << "ScreenOrientationLockType::LANDSCAPE_PRIMARY";
        case ScreenOrientationLockType::LANDSCAPE_SECONDARY:
            return os << "ScreenOrientationLockType::LANDSCAPE_SECONDARY";
        case ScreenOrientationLockType::ANY:
            return os << "ScreenOrientationLockType::ANY";
        case ScreenOrientationLockType::LANDSCAPE:
            return os << "ScreenOrientationLockType::LANDSCAPE";
        case ScreenOrientationLockType::PORTRAIT:
            return os << "ScreenOrientationLockType::PORTRAIT";
        case ScreenOrientationLockType::NATURAL:
            return os << "ScreenOrientationLockType::NATURAL";
        default:
            return os << "Unknown ScreenOrientationLockType value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(ScreenOrientationLockType value)
    {
        return internal::ScreenOrientationLockType_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

} // namespace mojom
} // namespace device

namespace std {

template <>
struct hash<::device::mojom::ScreenOrientationLockResult>
    : public mojo::internal::EnumHashImpl<::device::mojom::ScreenOrientationLockResult> {
};

template <>
struct hash<::device::mojom::ScreenOrientationLockType>
    : public mojo::internal::EnumHashImpl<::device::mojom::ScreenOrientationLockType> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::device::mojom::ScreenOrientationLockResult, ::device::mojom::ScreenOrientationLockResult> {
    static ::device::mojom::ScreenOrientationLockResult ToMojom(::device::mojom::ScreenOrientationLockResult input) { return input; }
    static bool FromMojom(::device::mojom::ScreenOrientationLockResult input, ::device::mojom::ScreenOrientationLockResult* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::mojom::ScreenOrientationLockResult, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::device::mojom::ScreenOrientationLockResult, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::device::mojom::ScreenOrientationLockResult>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::device::mojom::ScreenOrientationLockType, ::device::mojom::ScreenOrientationLockType> {
    static ::device::mojom::ScreenOrientationLockType ToMojom(::device::mojom::ScreenOrientationLockType input) { return input; }
    static bool FromMojom(::device::mojom::ScreenOrientationLockType input, ::device::mojom::ScreenOrientationLockType* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::mojom::ScreenOrientationLockType, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::device::mojom::ScreenOrientationLockType, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::device::mojom::ScreenOrientationLockType>(input), output);
        }
    };

} // namespace internal

} // namespace mojo

namespace device {
namespace mojom {

} // namespace mojom
} // namespace device

#endif // DEVICE_SCREEN_ORIENTATION_PUBLIC_INTERFACES_SCREEN_ORIENTATION_LOCK_TYPES_MOJOM_SHARED_H_
