// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_MIDI_MIDI_SERVICE_MOJOM_SHARED_H_
#define MEDIA_MIDI_MIDI_SERVICE_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "media/midi/midi_service.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"

namespace midi {
namespace mojom {

} // namespace mojom
} // namespace midi

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace midi {
namespace mojom {

    enum class Result : int32_t {
        NOT_INITIALIZED,
        OK,
        NOT_SUPPORTED,
        INITIALIZATION_ERROR,
        MAX = Result::INITIALIZATION_ERROR,
    };

    inline std::ostream& operator<<(std::ostream& os, Result value)
    {
        switch (value) {
        case Result::NOT_INITIALIZED:
            return os << "Result::NOT_INITIALIZED";
        case Result::OK:
            return os << "Result::OK";
        case Result::NOT_SUPPORTED:
            return os << "Result::NOT_SUPPORTED";
        case Result::INITIALIZATION_ERROR:
            return os << "Result::{INITIALIZATION_ERROR, MAX}";
        default:
            return os << "Unknown Result value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(Result value)
    {
        return internal::Result_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class PortState : int32_t {
        DISCONNECTED,
        CONNECTED,
        OPENED,
        LAST = PortState::OPENED,
    };

    inline std::ostream& operator<<(std::ostream& os, PortState value)
    {
        switch (value) {
        case PortState::DISCONNECTED:
            return os << "PortState::DISCONNECTED";
        case PortState::CONNECTED:
            return os << "PortState::CONNECTED";
        case PortState::OPENED:
            return os << "PortState::{OPENED, LAST}";
        default:
            return os << "Unknown PortState value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(PortState value)
    {
        return internal::PortState_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

} // namespace mojom
} // namespace midi

namespace std {

template <>
struct hash<::midi::mojom::Result>
    : public mojo::internal::EnumHashImpl<::midi::mojom::Result> {
};

template <>
struct hash<::midi::mojom::PortState>
    : public mojo::internal::EnumHashImpl<::midi::mojom::PortState> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::midi::mojom::Result, ::midi::mojom::Result> {
    static ::midi::mojom::Result ToMojom(::midi::mojom::Result input) { return input; }
    static bool FromMojom(::midi::mojom::Result input, ::midi::mojom::Result* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::midi::mojom::Result, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::midi::mojom::Result, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::midi::mojom::Result>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::midi::mojom::PortState, ::midi::mojom::PortState> {
    static ::midi::mojom::PortState ToMojom(::midi::mojom::PortState input) { return input; }
    static bool FromMojom(::midi::mojom::PortState input, ::midi::mojom::PortState* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::midi::mojom::PortState, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::midi::mojom::PortState, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::midi::mojom::PortState>(input), output);
        }
    };

} // namespace internal

} // namespace mojo

namespace midi {
namespace mojom {

} // namespace mojom
} // namespace midi

#endif // MEDIA_MIDI_MIDI_SERVICE_MOJOM_SHARED_H_
