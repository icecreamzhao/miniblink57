// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_GFX_MOJO_SELECTION_BOUND_MOJOM_SHARED_H_
#define UI_GFX_MOJO_SELECTION_BOUND_MOJOM_SHARED_H_

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
#include "ui/gfx/geometry/mojo/geometry.mojom-shared.h"
#include "ui/gfx/mojo/selection_bound.mojom-shared-internal.h"

namespace gfx {
namespace mojom {
    class SelectionBoundDataView;

} // namespace mojom
} // namespace gfx

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::gfx::mojom::SelectionBoundDataView> {
        using Data = ::gfx::mojom::internal::SelectionBound_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace gfx {
namespace mojom {

    enum class SelectionBoundType : int32_t {
        LEFT,
        RIGHT,
        CENTER,
        EMPTY,
        LAST = SelectionBoundType::EMPTY,
    };

    inline std::ostream& operator<<(std::ostream& os, SelectionBoundType value)
    {
        switch (value) {
        case SelectionBoundType::LEFT:
            return os << "SelectionBoundType::LEFT";
        case SelectionBoundType::RIGHT:
            return os << "SelectionBoundType::RIGHT";
        case SelectionBoundType::CENTER:
            return os << "SelectionBoundType::CENTER";
        case SelectionBoundType::EMPTY:
            return os << "SelectionBoundType::{EMPTY, LAST}";
        default:
            return os << "Unknown SelectionBoundType value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(SelectionBoundType value)
    {
        return internal::SelectionBoundType_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    class SelectionBoundDataView {
    public:
        SelectionBoundDataView() { }

        SelectionBoundDataView(
            internal::SelectionBound_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadType(UserType* output) const
        {
            auto data_value = data_->type;
            return mojo::internal::Deserialize<::gfx::mojom::SelectionBoundType>(
                data_value, output);
        }

        SelectionBoundType type() const
        {
            return static_cast<SelectionBoundType>(data_->type);
        }
        inline void GetEdgeTopDataView(
            ::gfx::mojom::PointFDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadEdgeTop(UserType* output)
        {
            auto* pointer = data_->edge_top.Get();
            return mojo::internal::Deserialize<::gfx::mojom::PointFDataView>(
                pointer, output, context_);
        }
        inline void GetEdgeBottomDataView(
            ::gfx::mojom::PointFDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadEdgeBottom(UserType* output)
        {
            auto* pointer = data_->edge_bottom.Get();
            return mojo::internal::Deserialize<::gfx::mojom::PointFDataView>(
                pointer, output, context_);
        }
        bool visible() const
        {
            return data_->visible;
        }

    private:
        internal::SelectionBound_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace gfx

namespace std {

template <>
struct hash<::gfx::mojom::SelectionBoundType>
    : public mojo::internal::EnumHashImpl<::gfx::mojom::SelectionBoundType> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::gfx::mojom::SelectionBoundType, ::gfx::mojom::SelectionBoundType> {
    static ::gfx::mojom::SelectionBoundType ToMojom(::gfx::mojom::SelectionBoundType input) { return input; }
    static bool FromMojom(::gfx::mojom::SelectionBoundType input, ::gfx::mojom::SelectionBoundType* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::gfx::mojom::SelectionBoundType, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::gfx::mojom::SelectionBoundType, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::gfx::mojom::SelectionBoundType>(input), output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::gfx::mojom::SelectionBoundDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::gfx::mojom::SelectionBoundDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::gfx::mojom::internal::SelectionBound_Data);
            decltype(CallWithContext(Traits::edge_top, input, custom_context)) in_edge_top = CallWithContext(Traits::edge_top, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::PointFDataView>(
                in_edge_top, context);
            decltype(CallWithContext(Traits::edge_bottom, input, custom_context)) in_edge_bottom = CallWithContext(Traits::edge_bottom, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::PointFDataView>(
                in_edge_bottom, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::gfx::mojom::internal::SelectionBound_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::gfx::mojom::internal::SelectionBound_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            mojo::internal::Serialize<::gfx::mojom::SelectionBoundType>(
                CallWithContext(Traits::type, input, custom_context), &result->type);
            decltype(CallWithContext(Traits::edge_top, input, custom_context)) in_edge_top = CallWithContext(Traits::edge_top, input, custom_context);
            typename decltype(result->edge_top)::BaseType* edge_top_ptr;
            mojo::internal::Serialize<::gfx::mojom::PointFDataView>(
                in_edge_top, buffer, &edge_top_ptr, context);
            result->edge_top.Set(edge_top_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->edge_top.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null edge_top in SelectionBound struct");
            decltype(CallWithContext(Traits::edge_bottom, input, custom_context)) in_edge_bottom = CallWithContext(Traits::edge_bottom, input, custom_context);
            typename decltype(result->edge_bottom)::BaseType* edge_bottom_ptr;
            mojo::internal::Serialize<::gfx::mojom::PointFDataView>(
                in_edge_bottom, buffer, &edge_bottom_ptr, context);
            result->edge_bottom.Set(edge_bottom_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->edge_bottom.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null edge_bottom in SelectionBound struct");
            result->visible = CallWithContext(Traits::visible, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::gfx::mojom::internal::SelectionBound_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::gfx::mojom::SelectionBoundDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace gfx {
namespace mojom {

    inline void SelectionBoundDataView::GetEdgeTopDataView(
        ::gfx::mojom::PointFDataView* output)
    {
        auto pointer = data_->edge_top.Get();
        *output = ::gfx::mojom::PointFDataView(pointer, context_);
    }
    inline void SelectionBoundDataView::GetEdgeBottomDataView(
        ::gfx::mojom::PointFDataView* output)
    {
        auto pointer = data_->edge_bottom.Get();
        *output = ::gfx::mojom::PointFDataView(pointer, context_);
    }

} // namespace mojom
} // namespace gfx

#endif // UI_GFX_MOJO_SELECTION_BOUND_MOJOM_SHARED_H_
