// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_PUBLIC_COMMON_WINDOW_CONTAINER_TYPE_MOJOM_SHARED_H_
#define CONTENT_PUBLIC_COMMON_WINDOW_CONTAINER_TYPE_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "content/public/common/window_container_type.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"

namespace content {
namespace mojom {

} // namespace mojom
} // namespace content

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace content {
namespace mojom {

    enum class WindowContainerType : int32_t {
        NORMAL = 0,
        BACKGROUND,
        PERSISTENT,
    };

    inline std::ostream& operator<<(std::ostream& os, WindowContainerType value)
    {
        switch (value) {
        case WindowContainerType::NORMAL:
            return os << "WindowContainerType::NORMAL";
        case WindowContainerType::BACKGROUND:
            return os << "WindowContainerType::BACKGROUND";
        case WindowContainerType::PERSISTENT:
            return os << "WindowContainerType::PERSISTENT";
        default:
            return os << "Unknown WindowContainerType value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(WindowContainerType value)
    {
        return internal::WindowContainerType_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

} // namespace mojom
} // namespace content

namespace std {

template <>
struct hash<::content::mojom::WindowContainerType>
    : public mojo::internal::EnumHashImpl<::content::mojom::WindowContainerType> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::content::mojom::WindowContainerType, ::content::mojom::WindowContainerType> {
    static ::content::mojom::WindowContainerType ToMojom(::content::mojom::WindowContainerType input) { return input; }
    static bool FromMojom(::content::mojom::WindowContainerType input, ::content::mojom::WindowContainerType* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::content::mojom::WindowContainerType, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::content::mojom::WindowContainerType, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::content::mojom::WindowContainerType>(input), output);
        }
    };

} // namespace internal

} // namespace mojo

namespace content {
namespace mojom {

} // namespace mojom
} // namespace content

#endif // CONTENT_PUBLIC_COMMON_WINDOW_CONTAINER_TYPE_MOJOM_SHARED_H_
