// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_WINDOW_TREE_CONSTANTS_MOJOM_SHARED_H_
#define SERVICES_UI_PUBLIC_INTERFACES_WINDOW_TREE_CONSTANTS_MOJOM_SHARED_H_

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
#include "services/ui/public/interfaces/window_tree_constants.mojom-shared-internal.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared.h"

namespace ui {
namespace mojom {
    class WindowDataDataView;

} // namespace mojom
} // namespace ui

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::ui::mojom::WindowDataDataView> {
        using Data = ::ui::mojom::internal::WindowData_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace ui {
namespace mojom {

    enum class EventResult : int32_t {
        HANDLED,
        UNHANDLED,
    };

    inline std::ostream& operator<<(std::ostream& os, EventResult value)
    {
        switch (value) {
        case EventResult::HANDLED:
            return os << "EventResult::HANDLED";
        case EventResult::UNHANDLED:
            return os << "EventResult::UNHANDLED";
        default:
            return os << "Unknown EventResult value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(EventResult value)
    {
        return internal::EventResult_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    class WindowDataDataView {
    public:
        WindowDataDataView() { }

        WindowDataDataView(
            internal::WindowData_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t parent_id() const
        {
            return data_->parent_id;
        }
        uint32_t window_id() const
        {
            return data_->window_id;
        }
        uint32_t transient_parent_id() const
        {
            return data_->transient_parent_id;
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
        inline void GetPropertiesDataView(
            mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadProperties(UserType* output)
        {
            auto* pointer = data_->properties.Get();
            return mojo::internal::Deserialize<mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>>(
                pointer, output, context_);
        }
        bool visible() const
        {
            return data_->visible;
        }

    private:
        internal::WindowData_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace ui

namespace std {

template <>
struct hash<::ui::mojom::EventResult>
    : public mojo::internal::EnumHashImpl<::ui::mojom::EventResult> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::ui::mojom::EventResult, ::ui::mojom::EventResult> {
    static ::ui::mojom::EventResult ToMojom(::ui::mojom::EventResult input) { return input; }
    static bool FromMojom(::ui::mojom::EventResult input, ::ui::mojom::EventResult* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::ui::mojom::EventResult, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::ui::mojom::EventResult, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::ui::mojom::EventResult>(input), output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::ui::mojom::WindowDataDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::ui::mojom::WindowDataDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::ui::mojom::internal::WindowData_Data);
            decltype(CallWithContext(Traits::bounds, input, custom_context)) in_bounds = CallWithContext(Traits::bounds, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::RectDataView>(
                in_bounds, context);
            decltype(CallWithContext(Traits::properties, input, custom_context)) in_properties = CallWithContext(Traits::properties, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>>(
                in_properties, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::ui::mojom::internal::WindowData_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::ui::mojom::internal::WindowData_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->parent_id = CallWithContext(Traits::parent_id, input, custom_context);
            result->window_id = CallWithContext(Traits::window_id, input, custom_context);
            result->transient_parent_id = CallWithContext(Traits::transient_parent_id, input, custom_context);
            decltype(CallWithContext(Traits::bounds, input, custom_context)) in_bounds = CallWithContext(Traits::bounds, input, custom_context);
            typename decltype(result->bounds)::BaseType* bounds_ptr;
            mojo::internal::Serialize<::gfx::mojom::RectDataView>(
                in_bounds, buffer, &bounds_ptr, context);
            result->bounds.Set(bounds_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->bounds.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null bounds in WindowData struct");
            decltype(CallWithContext(Traits::properties, input, custom_context)) in_properties = CallWithContext(Traits::properties, input, custom_context);
            typename decltype(result->properties)::BaseType* properties_ptr;
            const mojo::internal::ContainerValidateParams properties_validate_params(
                new mojo::internal::ContainerValidateParams(0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr)), new mojo::internal::ContainerValidateParams(0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr)));
            mojo::internal::Serialize<mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>>(
                in_properties, buffer, &properties_ptr, &properties_validate_params,
                context);
            result->properties.Set(properties_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->properties.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null properties in WindowData struct");
            result->visible = CallWithContext(Traits::visible, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::ui::mojom::internal::WindowData_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::ui::mojom::WindowDataDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace ui {
namespace mojom {

    inline void WindowDataDataView::GetBoundsDataView(
        ::gfx::mojom::RectDataView* output)
    {
        auto pointer = data_->bounds.Get();
        *output = ::gfx::mojom::RectDataView(pointer, context_);
    }
    inline void WindowDataDataView::GetPropertiesDataView(
        mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>* output)
    {
        auto pointer = data_->properties.Get();
        *output = mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>(pointer, context_);
    }

} // namespace mojom
} // namespace ui

#endif // SERVICES_UI_PUBLIC_INTERFACES_WINDOW_TREE_CONSTANTS_MOJOM_SHARED_H_
