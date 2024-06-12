// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MOJO_COMMON_TEXT_DIRECTION_MOJOM_SHARED_H_
#define MOJO_COMMON_TEXT_DIRECTION_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "mojo/common/text_direction.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"

namespace mojo {
namespace common {
    namespace mojom {

    } // namespace mojom
} // namespace common
} // namespace mojo

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace mojo {
namespace common {
    namespace mojom {

        enum class TextDirection : int32_t {
            UNKNOWN_DIRECTION,
            RIGHT_TO_LEFT,
            LEFT_TO_RIGHT,
        };

        inline std::ostream& operator<<(std::ostream& os, TextDirection value)
        {
            switch (value) {
            case TextDirection::UNKNOWN_DIRECTION:
                return os << "TextDirection::UNKNOWN_DIRECTION";
            case TextDirection::RIGHT_TO_LEFT:
                return os << "TextDirection::RIGHT_TO_LEFT";
            case TextDirection::LEFT_TO_RIGHT:
                return os << "TextDirection::LEFT_TO_RIGHT";
            default:
                return os << "Unknown TextDirection value: " << static_cast<int32_t>(value);
            }
        }
        inline bool IsKnownEnumValue(TextDirection value)
        {
            return internal::TextDirection_Data::IsKnownValue(
                static_cast<int32_t>(value));
        }

    } // namespace mojom
} // namespace common
} // namespace mojo

namespace std {

template <>
struct hash<::mojo::common::mojom::TextDirection>
    : public mojo::internal::EnumHashImpl<::mojo::common::mojom::TextDirection> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::mojo::common::mojom::TextDirection, ::mojo::common::mojom::TextDirection> {
    static ::mojo::common::mojom::TextDirection ToMojom(::mojo::common::mojom::TextDirection input) { return input; }
    static bool FromMojom(::mojo::common::mojom::TextDirection input, ::mojo::common::mojom::TextDirection* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::mojo::common::mojom::TextDirection, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::mojo::common::mojom::TextDirection, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::mojo::common::mojom::TextDirection>(input), output);
        }
    };

} // namespace internal

} // namespace mojo

namespace mojo {
namespace common {
    namespace mojom {

    } // namespace mojom
} // namespace common
} // namespace mojo

#endif // MOJO_COMMON_TEXT_DIRECTION_MOJOM_SHARED_H_
