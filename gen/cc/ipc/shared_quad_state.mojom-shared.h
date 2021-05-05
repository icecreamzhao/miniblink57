// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_SHARED_QUAD_STATE_MOJOM_SHARED_H_
#define CC_IPC_SHARED_QUAD_STATE_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "cc/ipc/shared_quad_state.mojom-shared-internal.h"
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
#include "ui/gfx/mojo/transform.mojom-shared.h"

namespace cc {
namespace mojom {
    class SharedQuadStateDataView;

} // namespace mojom
} // namespace cc

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::cc::mojom::SharedQuadStateDataView> {
        using Data = ::cc::mojom::internal::SharedQuadState_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace cc {
namespace mojom {
    class SharedQuadStateDataView {
    public:
        SharedQuadStateDataView() { }

        SharedQuadStateDataView(
            internal::SharedQuadState_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetQuadToTargetTransformDataView(
            ::gfx::mojom::TransformDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadQuadToTargetTransform(UserType* output)
        {
            auto* pointer = data_->quad_to_target_transform.Get();
            return mojo::internal::Deserialize<::gfx::mojom::TransformDataView>(
                pointer, output, context_);
        }
        inline void GetQuadLayerBoundsDataView(
            ::gfx::mojom::SizeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadQuadLayerBounds(UserType* output)
        {
            auto* pointer = data_->quad_layer_bounds.Get();
            return mojo::internal::Deserialize<::gfx::mojom::SizeDataView>(
                pointer, output, context_);
        }
        inline void GetVisibleQuadLayerRectDataView(
            ::gfx::mojom::RectDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadVisibleQuadLayerRect(UserType* output)
        {
            auto* pointer = data_->visible_quad_layer_rect.Get();
            return mojo::internal::Deserialize<::gfx::mojom::RectDataView>(
                pointer, output, context_);
        }
        inline void GetClipRectDataView(
            ::gfx::mojom::RectDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadClipRect(UserType* output)
        {
            auto* pointer = data_->clip_rect.Get();
            return mojo::internal::Deserialize<::gfx::mojom::RectDataView>(
                pointer, output, context_);
        }
        bool is_clipped() const
        {
            return data_->is_clipped;
        }
        float opacity() const
        {
            return data_->opacity;
        }
        uint32_t blend_mode() const
        {
            return data_->blend_mode;
        }
        int32_t sorting_context_id() const
        {
            return data_->sorting_context_id;
        }

    private:
        internal::SharedQuadState_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace cc

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::cc::mojom::SharedQuadStateDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::cc::mojom::SharedQuadStateDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::cc::mojom::internal::SharedQuadState_Data);
            decltype(CallWithContext(Traits::quad_to_target_transform, input, custom_context)) in_quad_to_target_transform = CallWithContext(Traits::quad_to_target_transform, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::TransformDataView>(
                in_quad_to_target_transform, context);
            decltype(CallWithContext(Traits::quad_layer_bounds, input, custom_context)) in_quad_layer_bounds = CallWithContext(Traits::quad_layer_bounds, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::SizeDataView>(
                in_quad_layer_bounds, context);
            decltype(CallWithContext(Traits::visible_quad_layer_rect, input, custom_context)) in_visible_quad_layer_rect = CallWithContext(Traits::visible_quad_layer_rect, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::RectDataView>(
                in_visible_quad_layer_rect, context);
            decltype(CallWithContext(Traits::clip_rect, input, custom_context)) in_clip_rect = CallWithContext(Traits::clip_rect, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::RectDataView>(
                in_clip_rect, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::cc::mojom::internal::SharedQuadState_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::cc::mojom::internal::SharedQuadState_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::quad_to_target_transform, input, custom_context)) in_quad_to_target_transform = CallWithContext(Traits::quad_to_target_transform, input, custom_context);
            typename decltype(result->quad_to_target_transform)::BaseType* quad_to_target_transform_ptr;
            mojo::internal::Serialize<::gfx::mojom::TransformDataView>(
                in_quad_to_target_transform, buffer, &quad_to_target_transform_ptr, context);
            result->quad_to_target_transform.Set(quad_to_target_transform_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->quad_to_target_transform.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null quad_to_target_transform in SharedQuadState struct");
            decltype(CallWithContext(Traits::quad_layer_bounds, input, custom_context)) in_quad_layer_bounds = CallWithContext(Traits::quad_layer_bounds, input, custom_context);
            typename decltype(result->quad_layer_bounds)::BaseType* quad_layer_bounds_ptr;
            mojo::internal::Serialize<::gfx::mojom::SizeDataView>(
                in_quad_layer_bounds, buffer, &quad_layer_bounds_ptr, context);
            result->quad_layer_bounds.Set(quad_layer_bounds_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->quad_layer_bounds.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null quad_layer_bounds in SharedQuadState struct");
            decltype(CallWithContext(Traits::visible_quad_layer_rect, input, custom_context)) in_visible_quad_layer_rect = CallWithContext(Traits::visible_quad_layer_rect, input, custom_context);
            typename decltype(result->visible_quad_layer_rect)::BaseType* visible_quad_layer_rect_ptr;
            mojo::internal::Serialize<::gfx::mojom::RectDataView>(
                in_visible_quad_layer_rect, buffer, &visible_quad_layer_rect_ptr, context);
            result->visible_quad_layer_rect.Set(visible_quad_layer_rect_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->visible_quad_layer_rect.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null visible_quad_layer_rect in SharedQuadState struct");
            decltype(CallWithContext(Traits::clip_rect, input, custom_context)) in_clip_rect = CallWithContext(Traits::clip_rect, input, custom_context);
            typename decltype(result->clip_rect)::BaseType* clip_rect_ptr;
            mojo::internal::Serialize<::gfx::mojom::RectDataView>(
                in_clip_rect, buffer, &clip_rect_ptr, context);
            result->clip_rect.Set(clip_rect_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->clip_rect.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null clip_rect in SharedQuadState struct");
            result->is_clipped = CallWithContext(Traits::is_clipped, input, custom_context);
            result->opacity = CallWithContext(Traits::opacity, input, custom_context);
            result->blend_mode = CallWithContext(Traits::blend_mode, input, custom_context);
            result->sorting_context_id = CallWithContext(Traits::sorting_context_id, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::cc::mojom::internal::SharedQuadState_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::cc::mojom::SharedQuadStateDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace cc {
namespace mojom {

    inline void SharedQuadStateDataView::GetQuadToTargetTransformDataView(
        ::gfx::mojom::TransformDataView* output)
    {
        auto pointer = data_->quad_to_target_transform.Get();
        *output = ::gfx::mojom::TransformDataView(pointer, context_);
    }
    inline void SharedQuadStateDataView::GetQuadLayerBoundsDataView(
        ::gfx::mojom::SizeDataView* output)
    {
        auto pointer = data_->quad_layer_bounds.Get();
        *output = ::gfx::mojom::SizeDataView(pointer, context_);
    }
    inline void SharedQuadStateDataView::GetVisibleQuadLayerRectDataView(
        ::gfx::mojom::RectDataView* output)
    {
        auto pointer = data_->visible_quad_layer_rect.Get();
        *output = ::gfx::mojom::RectDataView(pointer, context_);
    }
    inline void SharedQuadStateDataView::GetClipRectDataView(
        ::gfx::mojom::RectDataView* output)
    {
        auto pointer = data_->clip_rect.Get();
        *output = ::gfx::mojom::RectDataView(pointer, context_);
    }

} // namespace mojom
} // namespace cc

#endif // CC_IPC_SHARED_QUAD_STATE_MOJOM_SHARED_H_
