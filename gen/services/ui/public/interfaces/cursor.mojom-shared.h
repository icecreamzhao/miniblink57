// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_CURSOR_MOJOM_SHARED_H_
#define SERVICES_UI_PUBLIC_INTERFACES_CURSOR_MOJOM_SHARED_H_

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
#include "services/ui/public/interfaces/cursor.mojom-shared-internal.h"

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

    enum class Cursor : int32_t {
        CURSOR_NULL = 0,
        POINTER,
        CROSS,
        HAND,
        IBEAM,
        WAIT,
        HELP,
        EAST_RESIZE,
        NORTH_RESIZE,
        NORTH_EAST_RESIZE,
        NORTH_WEST_RESIZE,
        SOUTH_RESIZE,
        SOUTH_EAST_RESIZE,
        SOUTH_WEST_RESIZE,
        WEST_RESIZE,
        NORTH_SOUTH_RESIZE,
        EAST_WEST_RESIZE,
        NORTH_EAST_SOUTH_WEST_RESIZE,
        NORTH_WEST_SOUTH_EAST_RESIZE,
        COLUMN_RESIZE,
        ROW_RESIZE,
        MIDDLE_PANNING,
        EAST_PANNING,
        NORTH_PANNING,
        NORTH_EAST_PANNING,
        NORTH_WEST_PANNING,
        SOUTH_PANNING,
        SOUTH_EAST_PANNING,
        SOUTH_WEST_PANNING,
        WEST_PANNING,
        MOVE,
        VERTICAL_TEXT,
        CELL,
        CONTEXT_MENU,
        ALIAS,
        PROGRESS,
        NO_DROP,
        COPY,
        NONE,
        NOT_ALLOWED,
        ZOOM_IN,
        ZOOM_OUT,
        GRAB,
        GRABBING,
        CUSTOM,
    };

    inline std::ostream& operator<<(std::ostream& os, Cursor value)
    {
        switch (value) {
        case Cursor::CURSOR_NULL:
            return os << "Cursor::CURSOR_NULL";
        case Cursor::POINTER:
            return os << "Cursor::POINTER";
        case Cursor::CROSS:
            return os << "Cursor::CROSS";
        case Cursor::HAND:
            return os << "Cursor::HAND";
        case Cursor::IBEAM:
            return os << "Cursor::IBEAM";
        case Cursor::WAIT:
            return os << "Cursor::WAIT";
        case Cursor::HELP:
            return os << "Cursor::HELP";
        case Cursor::EAST_RESIZE:
            return os << "Cursor::EAST_RESIZE";
        case Cursor::NORTH_RESIZE:
            return os << "Cursor::NORTH_RESIZE";
        case Cursor::NORTH_EAST_RESIZE:
            return os << "Cursor::NORTH_EAST_RESIZE";
        case Cursor::NORTH_WEST_RESIZE:
            return os << "Cursor::NORTH_WEST_RESIZE";
        case Cursor::SOUTH_RESIZE:
            return os << "Cursor::SOUTH_RESIZE";
        case Cursor::SOUTH_EAST_RESIZE:
            return os << "Cursor::SOUTH_EAST_RESIZE";
        case Cursor::SOUTH_WEST_RESIZE:
            return os << "Cursor::SOUTH_WEST_RESIZE";
        case Cursor::WEST_RESIZE:
            return os << "Cursor::WEST_RESIZE";
        case Cursor::NORTH_SOUTH_RESIZE:
            return os << "Cursor::NORTH_SOUTH_RESIZE";
        case Cursor::EAST_WEST_RESIZE:
            return os << "Cursor::EAST_WEST_RESIZE";
        case Cursor::NORTH_EAST_SOUTH_WEST_RESIZE:
            return os << "Cursor::NORTH_EAST_SOUTH_WEST_RESIZE";
        case Cursor::NORTH_WEST_SOUTH_EAST_RESIZE:
            return os << "Cursor::NORTH_WEST_SOUTH_EAST_RESIZE";
        case Cursor::COLUMN_RESIZE:
            return os << "Cursor::COLUMN_RESIZE";
        case Cursor::ROW_RESIZE:
            return os << "Cursor::ROW_RESIZE";
        case Cursor::MIDDLE_PANNING:
            return os << "Cursor::MIDDLE_PANNING";
        case Cursor::EAST_PANNING:
            return os << "Cursor::EAST_PANNING";
        case Cursor::NORTH_PANNING:
            return os << "Cursor::NORTH_PANNING";
        case Cursor::NORTH_EAST_PANNING:
            return os << "Cursor::NORTH_EAST_PANNING";
        case Cursor::NORTH_WEST_PANNING:
            return os << "Cursor::NORTH_WEST_PANNING";
        case Cursor::SOUTH_PANNING:
            return os << "Cursor::SOUTH_PANNING";
        case Cursor::SOUTH_EAST_PANNING:
            return os << "Cursor::SOUTH_EAST_PANNING";
        case Cursor::SOUTH_WEST_PANNING:
            return os << "Cursor::SOUTH_WEST_PANNING";
        case Cursor::WEST_PANNING:
            return os << "Cursor::WEST_PANNING";
        case Cursor::MOVE:
            return os << "Cursor::MOVE";
        case Cursor::VERTICAL_TEXT:
            return os << "Cursor::VERTICAL_TEXT";
        case Cursor::CELL:
            return os << "Cursor::CELL";
        case Cursor::CONTEXT_MENU:
            return os << "Cursor::CONTEXT_MENU";
        case Cursor::ALIAS:
            return os << "Cursor::ALIAS";
        case Cursor::PROGRESS:
            return os << "Cursor::PROGRESS";
        case Cursor::NO_DROP:
            return os << "Cursor::NO_DROP";
        case Cursor::COPY:
            return os << "Cursor::COPY";
        case Cursor::NONE:
            return os << "Cursor::NONE";
        case Cursor::NOT_ALLOWED:
            return os << "Cursor::NOT_ALLOWED";
        case Cursor::ZOOM_IN:
            return os << "Cursor::ZOOM_IN";
        case Cursor::ZOOM_OUT:
            return os << "Cursor::ZOOM_OUT";
        case Cursor::GRAB:
            return os << "Cursor::GRAB";
        case Cursor::GRABBING:
            return os << "Cursor::GRABBING";
        case Cursor::CUSTOM:
            return os << "Cursor::CUSTOM";
        default:
            return os << "Unknown Cursor value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(Cursor value)
    {
        return internal::Cursor_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

} // namespace mojom
} // namespace ui

namespace std {

template <>
struct hash<::ui::mojom::Cursor>
    : public mojo::internal::EnumHashImpl<::ui::mojom::Cursor> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::ui::mojom::Cursor, ::ui::mojom::Cursor> {
    static ::ui::mojom::Cursor ToMojom(::ui::mojom::Cursor input) { return input; }
    static bool FromMojom(::ui::mojom::Cursor input, ::ui::mojom::Cursor* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::ui::mojom::Cursor, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::ui::mojom::Cursor, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::ui::mojom::Cursor>(input), output);
        }
    };

} // namespace internal

} // namespace mojo

namespace ui {
namespace mojom {

} // namespace mojom
} // namespace ui

#endif // SERVICES_UI_PUBLIC_INTERFACES_CURSOR_MOJOM_SHARED_H_
