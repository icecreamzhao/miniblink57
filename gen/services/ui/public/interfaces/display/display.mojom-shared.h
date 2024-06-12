// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_DISPLAY_DISPLAY_MOJOM_SHARED_H_
#define SERVICES_UI_PUBLIC_INTERFACES_DISPLAY_DISPLAY_MOJOM_SHARED_H_

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
#include "services/ui/public/interfaces/display/display.mojom-shared-internal.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared.h"

namespace display {
namespace mojom {
    class DisplayDataView;

} // namespace mojom
} // namespace display

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::display::mojom::DisplayDataView> {
        using Data = ::display::mojom::internal::Display_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace display {
namespace mojom {

    enum class Rotation : int32_t {
        VALUE_0,
        VALUE_90,
        VALUE_180,
        VALUE_270,
    };

    inline std::ostream& operator<<(std::ostream& os, Rotation value)
    {
        switch (value) {
        case Rotation::VALUE_0:
            return os << "Rotation::VALUE_0";
        case Rotation::VALUE_90:
            return os << "Rotation::VALUE_90";
        case Rotation::VALUE_180:
            return os << "Rotation::VALUE_180";
        case Rotation::VALUE_270:
            return os << "Rotation::VALUE_270";
        default:
            return os << "Unknown Rotation value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(Rotation value)
    {
        return internal::Rotation_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class TouchSupport : int32_t {
        UNKNOWN,
        AVAILABLE,
        UNAVAILABLE,
    };

    inline std::ostream& operator<<(std::ostream& os, TouchSupport value)
    {
        switch (value) {
        case TouchSupport::UNKNOWN:
            return os << "TouchSupport::UNKNOWN";
        case TouchSupport::AVAILABLE:
            return os << "TouchSupport::AVAILABLE";
        case TouchSupport::UNAVAILABLE:
            return os << "TouchSupport::UNAVAILABLE";
        default:
            return os << "Unknown TouchSupport value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(TouchSupport value)
    {
        return internal::TouchSupport_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    class DisplayDataView {
    public:
        DisplayDataView() { }

        DisplayDataView(
            internal::Display_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        int64_t id() const
        {
            return data_->id;
        }
        inline void GetBoundsDataView(
            ::gfx::mojom::RectDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadBounds(UserType* output)
        {
            auto* pointer = data_->bounds.Get();
            return mojo::internal::Deserialize<::gfx::mojom::RectDataView>(
                pointer, output, context_);
        }
        inline void GetWorkAreaDataView(
            ::gfx::mojom::RectDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadWorkArea(UserType* output)
        {
            auto* pointer = data_->work_area.Get();
            return mojo::internal::Deserialize<::gfx::mojom::RectDataView>(
                pointer, output, context_);
        }
        float device_scale_factor() const
        {
            return data_->device_scale_factor;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadRotation(UserType* output) const
        {
            auto data_value = data_->rotation;
            return mojo::internal::Deserialize<::display::mojom::Rotation>(
                data_value, output);
        }

        Rotation rotation() const
        {
            return static_cast<Rotation>(data_->rotation);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTouchSupport(UserType* output) const
        {
            auto data_value = data_->touch_support;
            return mojo::internal::Deserialize<::display::mojom::TouchSupport>(
                data_value, output);
        }

        TouchSupport touch_support() const
        {
            return static_cast<TouchSupport>(data_->touch_support);
        }
        inline void GetMaximumCursorSizeDataView(
            ::gfx::mojom::SizeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMaximumCursorSize(UserType* output)
        {
            auto* pointer = data_->maximum_cursor_size.Get();
            return mojo::internal::Deserialize<::gfx::mojom::SizeDataView>(
                pointer, output, context_);
        }

    private:
        internal::Display_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace display

namespace std {

template <>
struct hash<::display::mojom::Rotation>
    : public mojo::internal::EnumHashImpl<::display::mojom::Rotation> {
};

template <>
struct hash<::display::mojom::TouchSupport>
    : public mojo::internal::EnumHashImpl<::display::mojom::TouchSupport> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::display::mojom::Rotation, ::display::mojom::Rotation> {
    static ::display::mojom::Rotation ToMojom(::display::mojom::Rotation input) { return input; }
    static bool FromMojom(::display::mojom::Rotation input, ::display::mojom::Rotation* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::display::mojom::Rotation, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::display::mojom::Rotation, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::display::mojom::Rotation>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::display::mojom::TouchSupport, ::display::mojom::TouchSupport> {
    static ::display::mojom::TouchSupport ToMojom(::display::mojom::TouchSupport input) { return input; }
    static bool FromMojom(::display::mojom::TouchSupport input, ::display::mojom::TouchSupport* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::display::mojom::TouchSupport, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::display::mojom::TouchSupport, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::display::mojom::TouchSupport>(input), output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::display::mojom::DisplayDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::display::mojom::DisplayDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::display::mojom::internal::Display_Data);
            decltype(CallWithContext(Traits::bounds, input, custom_context)) in_bounds = CallWithContext(Traits::bounds, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::RectDataView>(
                in_bounds, context);
            decltype(CallWithContext(Traits::work_area, input, custom_context)) in_work_area = CallWithContext(Traits::work_area, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::RectDataView>(
                in_work_area, context);
            decltype(CallWithContext(Traits::maximum_cursor_size, input, custom_context)) in_maximum_cursor_size = CallWithContext(Traits::maximum_cursor_size, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::SizeDataView>(
                in_maximum_cursor_size, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::display::mojom::internal::Display_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::display::mojom::internal::Display_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->id = CallWithContext(Traits::id, input, custom_context);
            decltype(CallWithContext(Traits::bounds, input, custom_context)) in_bounds = CallWithContext(Traits::bounds, input, custom_context);
            typename decltype(result->bounds)::BaseType* bounds_ptr;
            mojo::internal::Serialize<::gfx::mojom::RectDataView>(
                in_bounds, buffer, &bounds_ptr, context);
            result->bounds.Set(bounds_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->bounds.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null bounds in Display struct");
            decltype(CallWithContext(Traits::work_area, input, custom_context)) in_work_area = CallWithContext(Traits::work_area, input, custom_context);
            typename decltype(result->work_area)::BaseType* work_area_ptr;
            mojo::internal::Serialize<::gfx::mojom::RectDataView>(
                in_work_area, buffer, &work_area_ptr, context);
            result->work_area.Set(work_area_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->work_area.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null work_area in Display struct");
            result->device_scale_factor = CallWithContext(Traits::device_scale_factor, input, custom_context);
            mojo::internal::Serialize<::display::mojom::Rotation>(
                CallWithContext(Traits::rotation, input, custom_context), &result->rotation);
            mojo::internal::Serialize<::display::mojom::TouchSupport>(
                CallWithContext(Traits::touch_support, input, custom_context), &result->touch_support);
            decltype(CallWithContext(Traits::maximum_cursor_size, input, custom_context)) in_maximum_cursor_size = CallWithContext(Traits::maximum_cursor_size, input, custom_context);
            typename decltype(result->maximum_cursor_size)::BaseType* maximum_cursor_size_ptr;
            mojo::internal::Serialize<::gfx::mojom::SizeDataView>(
                in_maximum_cursor_size, buffer, &maximum_cursor_size_ptr, context);
            result->maximum_cursor_size.Set(maximum_cursor_size_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->maximum_cursor_size.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null maximum_cursor_size in Display struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::display::mojom::internal::Display_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::display::mojom::DisplayDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace display {
namespace mojom {

    inline void DisplayDataView::GetBoundsDataView(
        ::gfx::mojom::RectDataView* output)
    {
        auto pointer = data_->bounds.Get();
        *output = ::gfx::mojom::RectDataView(pointer, context_);
    }
    inline void DisplayDataView::GetWorkAreaDataView(
        ::gfx::mojom::RectDataView* output)
    {
        auto pointer = data_->work_area.Get();
        *output = ::gfx::mojom::RectDataView(pointer, context_);
    }
    inline void DisplayDataView::GetMaximumCursorSizeDataView(
        ::gfx::mojom::SizeDataView* output)
    {
        auto pointer = data_->maximum_cursor_size.Get();
        *output = ::gfx::mojom::SizeDataView(pointer, context_);
    }

} // namespace mojom
} // namespace display

#endif // SERVICES_UI_PUBLIC_INTERFACES_DISPLAY_DISPLAY_MOJOM_SHARED_H_
