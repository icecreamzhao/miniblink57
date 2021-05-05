// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_GPU_INTERFACES_CONTEXT_LOST_REASON_MOJOM_SHARED_H_
#define SERVICES_UI_GPU_INTERFACES_CONTEXT_LOST_REASON_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "services/ui/gpu/interfaces/context_lost_reason.mojom-shared-internal.h"

namespace ui {
namespace mojom {

} // namespace mojom
} // namespace ui

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace ui {
namespace mojom {

    enum class ContextLostReason : int32_t {
        GUILTY,
        INNOCENT,
        UNKNOWN,
        OUT_OF_MEMORY,
        MAKE_CURRENT_FAILED,
        GPU_CHANNEL_LOST,
        INVALID_GPU_MESSAGE,
    };

    inline std::ostream& operator<<(std::ostream& os, ContextLostReason value)
    {
        switch (value) {
        case ContextLostReason::GUILTY:
            return os << "ContextLostReason::GUILTY";
        case ContextLostReason::INNOCENT:
            return os << "ContextLostReason::INNOCENT";
        case ContextLostReason::UNKNOWN:
            return os << "ContextLostReason::UNKNOWN";
        case ContextLostReason::OUT_OF_MEMORY:
            return os << "ContextLostReason::OUT_OF_MEMORY";
        case ContextLostReason::MAKE_CURRENT_FAILED:
            return os << "ContextLostReason::MAKE_CURRENT_FAILED";
        case ContextLostReason::GPU_CHANNEL_LOST:
            return os << "ContextLostReason::GPU_CHANNEL_LOST";
        case ContextLostReason::INVALID_GPU_MESSAGE:
            return os << "ContextLostReason::INVALID_GPU_MESSAGE";
        default:
            return os << "Unknown ContextLostReason value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(ContextLostReason value)
    {
        return internal::ContextLostReason_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

} // namespace mojom
} // namespace ui

namespace std {

template <>
struct hash<::ui::mojom::ContextLostReason>
    : public mojo::internal::EnumHashImpl<::ui::mojom::ContextLostReason> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::ui::mojom::ContextLostReason, ::ui::mojom::ContextLostReason> {
    static ::ui::mojom::ContextLostReason ToMojom(::ui::mojom::ContextLostReason input) { return input; }
    static bool FromMojom(::ui::mojom::ContextLostReason input, ::ui::mojom::ContextLostReason* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::ui::mojom::ContextLostReason, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::ui::mojom::ContextLostReason, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::ui::mojom::ContextLostReason>(input), output);
        }
    };

} // namespace internal

} // namespace mojo

namespace ui {
namespace mojom {

} // namespace mojom
} // namespace ui

#endif // SERVICES_UI_GPU_INTERFACES_CONTEXT_LOST_REASON_MOJOM_SHARED_H_
