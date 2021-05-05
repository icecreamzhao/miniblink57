// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_MUS_CONSTANTS_MOJOM_SHARED_H_
#define SERVICES_UI_PUBLIC_INTERFACES_MUS_CONSTANTS_MOJOM_SHARED_H_

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
#include "services/ui/public/interfaces/mus_constants.mojom-shared-internal.h"

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

    enum class OrderDirection : int32_t {
        ABOVE = 1,
        BELOW,
    };

    inline std::ostream& operator<<(std::ostream& os, OrderDirection value)
    {
        switch (value) {
        case OrderDirection::ABOVE:
            return os << "OrderDirection::ABOVE";
        case OrderDirection::BELOW:
            return os << "OrderDirection::BELOW";
        default:
            return os << "Unknown OrderDirection value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(OrderDirection value)
    {
        return internal::OrderDirection_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

} // namespace mojom
} // namespace ui

namespace std {

template <>
struct hash<::ui::mojom::OrderDirection>
    : public mojo::internal::EnumHashImpl<::ui::mojom::OrderDirection> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::ui::mojom::OrderDirection, ::ui::mojom::OrderDirection> {
    static ::ui::mojom::OrderDirection ToMojom(::ui::mojom::OrderDirection input) { return input; }
    static bool FromMojom(::ui::mojom::OrderDirection input, ::ui::mojom::OrderDirection* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::ui::mojom::OrderDirection, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::ui::mojom::OrderDirection, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::ui::mojom::OrderDirection>(input), output);
        }
    };

} // namespace internal

} // namespace mojo

namespace ui {
namespace mojom {

} // namespace mojom
} // namespace ui

#endif // SERVICES_UI_PUBLIC_INTERFACES_MUS_CONSTANTS_MOJOM_SHARED_H_
