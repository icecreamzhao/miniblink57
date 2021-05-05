// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_RENDER_PASS_MOJOM_SHARED_H_
#define CC_IPC_RENDER_PASS_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "cc/ipc/filter_operations.mojom-shared.h"
#include "cc/ipc/quads.mojom-shared.h"
#include "cc/ipc/render_pass.mojom-shared-internal.h"
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
    class RenderPassDataView;

} // namespace mojom
} // namespace cc

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::cc::mojom::RenderPassDataView> {
        using Data = ::cc::mojom::internal::RenderPass_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace cc {
namespace mojom {
    class RenderPassDataView {
    public:
        RenderPassDataView() { }

        RenderPassDataView(
            internal::RenderPass_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        int32_t id() const
        {
            return data_->id;
        }
        inline void GetOutputRectDataView(
            ::gfx::mojom::RectDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOutputRect(UserType* output)
        {
            auto* pointer = data_->output_rect.Get();
            return mojo::internal::Deserialize<::gfx::mojom::RectDataView>(
                pointer, output, context_);
        }
        inline void GetDamageRectDataView(
            ::gfx::mojom::RectDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDamageRect(UserType* output)
        {
            auto* pointer = data_->damage_rect.Get();
            return mojo::internal::Deserialize<::gfx::mojom::RectDataView>(
                pointer, output, context_);
        }
        inline void GetTransformToRootTargetDataView(
            ::gfx::mojom::TransformDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTransformToRootTarget(UserType* output)
        {
            auto* pointer = data_->transform_to_root_target.Get();
            return mojo::internal::Deserialize<::gfx::mojom::TransformDataView>(
                pointer, output, context_);
        }
        inline void GetFiltersDataView(
            ::cc::mojom::FilterOperationsDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFilters(UserType* output)
        {
            auto* pointer = data_->filters.Get();
            return mojo::internal::Deserialize<::cc::mojom::FilterOperationsDataView>(
                pointer, output, context_);
        }
        inline void GetBackgroundFiltersDataView(
            ::cc::mojom::FilterOperationsDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadBackgroundFilters(UserType* output)
        {
            auto* pointer = data_->background_filters.Get();
            return mojo::internal::Deserialize<::cc::mojom::FilterOperationsDataView>(
                pointer, output, context_);
        }
        bool has_transparent_background() const
        {
            return data_->has_transparent_background;
        }
        inline void GetQuadListDataView(
            mojo::ArrayDataView<::cc::mojom::DrawQuadDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadQuadList(UserType* output)
        {
            auto* pointer = data_->quad_list.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::cc::mojom::DrawQuadDataView>>(
                pointer, output, context_);
        }

    private:
        internal::RenderPass_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace cc

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::cc::mojom::RenderPassDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::cc::mojom::RenderPassDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::cc::mojom::internal::RenderPass_Data);
            decltype(CallWithContext(Traits::output_rect, input, custom_context)) in_output_rect = CallWithContext(Traits::output_rect, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::RectDataView>(
                in_output_rect, context);
            decltype(CallWithContext(Traits::damage_rect, input, custom_context)) in_damage_rect = CallWithContext(Traits::damage_rect, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::RectDataView>(
                in_damage_rect, context);
            decltype(CallWithContext(Traits::transform_to_root_target, input, custom_context)) in_transform_to_root_target = CallWithContext(Traits::transform_to_root_target, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::TransformDataView>(
                in_transform_to_root_target, context);
            decltype(CallWithContext(Traits::filters, input, custom_context)) in_filters = CallWithContext(Traits::filters, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::cc::mojom::FilterOperationsDataView>(
                in_filters, context);
            decltype(CallWithContext(Traits::background_filters, input, custom_context)) in_background_filters = CallWithContext(Traits::background_filters, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::cc::mojom::FilterOperationsDataView>(
                in_background_filters, context);
            decltype(CallWithContext(Traits::quad_list, input, custom_context)) in_quad_list = CallWithContext(Traits::quad_list, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::cc::mojom::DrawQuadDataView>>(
                in_quad_list, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::cc::mojom::internal::RenderPass_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::cc::mojom::internal::RenderPass_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->id = CallWithContext(Traits::id, input, custom_context);
            decltype(CallWithContext(Traits::output_rect, input, custom_context)) in_output_rect = CallWithContext(Traits::output_rect, input, custom_context);
            typename decltype(result->output_rect)::BaseType* output_rect_ptr;
            mojo::internal::Serialize<::gfx::mojom::RectDataView>(
                in_output_rect, buffer, &output_rect_ptr, context);
            result->output_rect.Set(output_rect_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->output_rect.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null output_rect in RenderPass struct");
            decltype(CallWithContext(Traits::damage_rect, input, custom_context)) in_damage_rect = CallWithContext(Traits::damage_rect, input, custom_context);
            typename decltype(result->damage_rect)::BaseType* damage_rect_ptr;
            mojo::internal::Serialize<::gfx::mojom::RectDataView>(
                in_damage_rect, buffer, &damage_rect_ptr, context);
            result->damage_rect.Set(damage_rect_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->damage_rect.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null damage_rect in RenderPass struct");
            decltype(CallWithContext(Traits::transform_to_root_target, input, custom_context)) in_transform_to_root_target = CallWithContext(Traits::transform_to_root_target, input, custom_context);
            typename decltype(result->transform_to_root_target)::BaseType* transform_to_root_target_ptr;
            mojo::internal::Serialize<::gfx::mojom::TransformDataView>(
                in_transform_to_root_target, buffer, &transform_to_root_target_ptr, context);
            result->transform_to_root_target.Set(transform_to_root_target_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->transform_to_root_target.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null transform_to_root_target in RenderPass struct");
            decltype(CallWithContext(Traits::filters, input, custom_context)) in_filters = CallWithContext(Traits::filters, input, custom_context);
            typename decltype(result->filters)::BaseType* filters_ptr;
            mojo::internal::Serialize<::cc::mojom::FilterOperationsDataView>(
                in_filters, buffer, &filters_ptr, context);
            result->filters.Set(filters_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->filters.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null filters in RenderPass struct");
            decltype(CallWithContext(Traits::background_filters, input, custom_context)) in_background_filters = CallWithContext(Traits::background_filters, input, custom_context);
            typename decltype(result->background_filters)::BaseType* background_filters_ptr;
            mojo::internal::Serialize<::cc::mojom::FilterOperationsDataView>(
                in_background_filters, buffer, &background_filters_ptr, context);
            result->background_filters.Set(background_filters_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->background_filters.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null background_filters in RenderPass struct");
            result->has_transparent_background = CallWithContext(Traits::has_transparent_background, input, custom_context);
            decltype(CallWithContext(Traits::quad_list, input, custom_context)) in_quad_list = CallWithContext(Traits::quad_list, input, custom_context);
            typename decltype(result->quad_list)::BaseType* quad_list_ptr;
            const mojo::internal::ContainerValidateParams quad_list_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::cc::mojom::DrawQuadDataView>>(
                in_quad_list, buffer, &quad_list_ptr, &quad_list_validate_params,
                context);
            result->quad_list.Set(quad_list_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->quad_list.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null quad_list in RenderPass struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::cc::mojom::internal::RenderPass_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::cc::mojom::RenderPassDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace cc {
namespace mojom {

    inline void RenderPassDataView::GetOutputRectDataView(
        ::gfx::mojom::RectDataView* output)
    {
        auto pointer = data_->output_rect.Get();
        *output = ::gfx::mojom::RectDataView(pointer, context_);
    }
    inline void RenderPassDataView::GetDamageRectDataView(
        ::gfx::mojom::RectDataView* output)
    {
        auto pointer = data_->damage_rect.Get();
        *output = ::gfx::mojom::RectDataView(pointer, context_);
    }
    inline void RenderPassDataView::GetTransformToRootTargetDataView(
        ::gfx::mojom::TransformDataView* output)
    {
        auto pointer = data_->transform_to_root_target.Get();
        *output = ::gfx::mojom::TransformDataView(pointer, context_);
    }
    inline void RenderPassDataView::GetFiltersDataView(
        ::cc::mojom::FilterOperationsDataView* output)
    {
        auto pointer = data_->filters.Get();
        *output = ::cc::mojom::FilterOperationsDataView(pointer, context_);
    }
    inline void RenderPassDataView::GetBackgroundFiltersDataView(
        ::cc::mojom::FilterOperationsDataView* output)
    {
        auto pointer = data_->background_filters.Get();
        *output = ::cc::mojom::FilterOperationsDataView(pointer, context_);
    }
    inline void RenderPassDataView::GetQuadListDataView(
        mojo::ArrayDataView<::cc::mojom::DrawQuadDataView>* output)
    {
        auto pointer = data_->quad_list.Get();
        *output = mojo::ArrayDataView<::cc::mojom::DrawQuadDataView>(pointer, context_);
    }

} // namespace mojom
} // namespace cc

#endif // CC_IPC_RENDER_PASS_MOJOM_SHARED_H_
