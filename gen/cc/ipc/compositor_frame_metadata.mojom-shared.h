// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_COMPOSITOR_FRAME_METADATA_MOJOM_SHARED_H_
#define CC_IPC_COMPOSITOR_FRAME_METADATA_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "cc/ipc/compositor_frame_metadata.mojom-shared-internal.h"
#include "cc/ipc/selection.mojom-shared.h"
#include "cc/ipc/surface_id.mojom-shared.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "ui/events/mojo/latency_info.mojom-shared.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared.h"

namespace cc {
namespace mojom {
    class CompositorFrameMetadataDataView;

} // namespace mojom
} // namespace cc

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::cc::mojom::CompositorFrameMetadataDataView> {
        using Data = ::cc::mojom::internal::CompositorFrameMetadata_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace cc {
namespace mojom {
    class CompositorFrameMetadataDataView {
    public:
        CompositorFrameMetadataDataView() { }

        CompositorFrameMetadataDataView(
            internal::CompositorFrameMetadata_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        float device_scale_factor() const
        {
            return data_->device_scale_factor;
        }
        inline void GetRootScrollOffsetDataView(
            ::gfx::mojom::Vector2dFDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadRootScrollOffset(UserType* output)
        {
            auto* pointer = data_->root_scroll_offset.Get();
            return mojo::internal::Deserialize<::gfx::mojom::Vector2dFDataView>(
                pointer, output, context_);
        }
        float page_scale_factor() const
        {
            return data_->page_scale_factor;
        }
        inline void GetScrollableViewportSizeDataView(
            ::gfx::mojom::SizeFDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadScrollableViewportSize(UserType* output)
        {
            auto* pointer = data_->scrollable_viewport_size.Get();
            return mojo::internal::Deserialize<::gfx::mojom::SizeFDataView>(
                pointer, output, context_);
        }
        inline void GetRootLayerSizeDataView(
            ::gfx::mojom::SizeFDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadRootLayerSize(UserType* output)
        {
            auto* pointer = data_->root_layer_size.Get();
            return mojo::internal::Deserialize<::gfx::mojom::SizeFDataView>(
                pointer, output, context_);
        }
        float min_page_scale_factor() const
        {
            return data_->min_page_scale_factor;
        }
        float max_page_scale_factor() const
        {
            return data_->max_page_scale_factor;
        }
        bool root_overflow_x_hidden() const
        {
            return data_->root_overflow_x_hidden;
        }
        bool root_overflow_y_hidden() const
        {
            return data_->root_overflow_y_hidden;
        }
        bool may_contain_video() const
        {
            return data_->may_contain_video;
        }
        bool is_resourceless_software_draw_with_scroll_or_animation() const
        {
            return data_->is_resourceless_software_draw_with_scroll_or_animation;
        }
        float top_controls_height() const
        {
            return data_->top_controls_height;
        }
        float top_controls_shown_ratio() const
        {
            return data_->top_controls_shown_ratio;
        }
        float bottom_controls_height() const
        {
            return data_->bottom_controls_height;
        }
        float bottom_controls_shown_ratio() const
        {
            return data_->bottom_controls_shown_ratio;
        }
        uint32_t root_background_color() const
        {
            return data_->root_background_color;
        }
        inline void GetSelectionDataView(
            ::cc::mojom::SelectionDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSelection(UserType* output)
        {
            auto* pointer = data_->selection.Get();
            return mojo::internal::Deserialize<::cc::mojom::SelectionDataView>(
                pointer, output, context_);
        }
        inline void GetLatencyInfoDataView(
            mojo::ArrayDataView<::ui::mojom::LatencyInfoDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadLatencyInfo(UserType* output)
        {
            auto* pointer = data_->latency_info.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::ui::mojom::LatencyInfoDataView>>(
                pointer, output, context_);
        }
        inline void GetReferencedSurfacesDataView(
            mojo::ArrayDataView<::cc::mojom::SurfaceIdDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadReferencedSurfaces(UserType* output)
        {
            auto* pointer = data_->referenced_surfaces.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::cc::mojom::SurfaceIdDataView>>(
                pointer, output, context_);
        }

    private:
        internal::CompositorFrameMetadata_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace cc

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::cc::mojom::CompositorFrameMetadataDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::cc::mojom::CompositorFrameMetadataDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::cc::mojom::internal::CompositorFrameMetadata_Data);
            decltype(CallWithContext(Traits::root_scroll_offset, input, custom_context)) in_root_scroll_offset = CallWithContext(Traits::root_scroll_offset, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::Vector2dFDataView>(
                in_root_scroll_offset, context);
            decltype(CallWithContext(Traits::scrollable_viewport_size, input, custom_context)) in_scrollable_viewport_size = CallWithContext(Traits::scrollable_viewport_size, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::SizeFDataView>(
                in_scrollable_viewport_size, context);
            decltype(CallWithContext(Traits::root_layer_size, input, custom_context)) in_root_layer_size = CallWithContext(Traits::root_layer_size, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::SizeFDataView>(
                in_root_layer_size, context);
            decltype(CallWithContext(Traits::selection, input, custom_context)) in_selection = CallWithContext(Traits::selection, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::cc::mojom::SelectionDataView>(
                in_selection, context);
            decltype(CallWithContext(Traits::latency_info, input, custom_context)) in_latency_info = CallWithContext(Traits::latency_info, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::ui::mojom::LatencyInfoDataView>>(
                in_latency_info, context);
            decltype(CallWithContext(Traits::referenced_surfaces, input, custom_context)) in_referenced_surfaces = CallWithContext(Traits::referenced_surfaces, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::cc::mojom::SurfaceIdDataView>>(
                in_referenced_surfaces, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::cc::mojom::internal::CompositorFrameMetadata_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::cc::mojom::internal::CompositorFrameMetadata_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->device_scale_factor = CallWithContext(Traits::device_scale_factor, input, custom_context);
            decltype(CallWithContext(Traits::root_scroll_offset, input, custom_context)) in_root_scroll_offset = CallWithContext(Traits::root_scroll_offset, input, custom_context);
            typename decltype(result->root_scroll_offset)::BaseType* root_scroll_offset_ptr;
            mojo::internal::Serialize<::gfx::mojom::Vector2dFDataView>(
                in_root_scroll_offset, buffer, &root_scroll_offset_ptr, context);
            result->root_scroll_offset.Set(root_scroll_offset_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->root_scroll_offset.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null root_scroll_offset in CompositorFrameMetadata struct");
            result->page_scale_factor = CallWithContext(Traits::page_scale_factor, input, custom_context);
            decltype(CallWithContext(Traits::scrollable_viewport_size, input, custom_context)) in_scrollable_viewport_size = CallWithContext(Traits::scrollable_viewport_size, input, custom_context);
            typename decltype(result->scrollable_viewport_size)::BaseType* scrollable_viewport_size_ptr;
            mojo::internal::Serialize<::gfx::mojom::SizeFDataView>(
                in_scrollable_viewport_size, buffer, &scrollable_viewport_size_ptr, context);
            result->scrollable_viewport_size.Set(scrollable_viewport_size_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->scrollable_viewport_size.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null scrollable_viewport_size in CompositorFrameMetadata struct");
            decltype(CallWithContext(Traits::root_layer_size, input, custom_context)) in_root_layer_size = CallWithContext(Traits::root_layer_size, input, custom_context);
            typename decltype(result->root_layer_size)::BaseType* root_layer_size_ptr;
            mojo::internal::Serialize<::gfx::mojom::SizeFDataView>(
                in_root_layer_size, buffer, &root_layer_size_ptr, context);
            result->root_layer_size.Set(root_layer_size_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->root_layer_size.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null root_layer_size in CompositorFrameMetadata struct");
            result->min_page_scale_factor = CallWithContext(Traits::min_page_scale_factor, input, custom_context);
            result->max_page_scale_factor = CallWithContext(Traits::max_page_scale_factor, input, custom_context);
            result->root_overflow_x_hidden = CallWithContext(Traits::root_overflow_x_hidden, input, custom_context);
            result->root_overflow_y_hidden = CallWithContext(Traits::root_overflow_y_hidden, input, custom_context);
            result->may_contain_video = CallWithContext(Traits::may_contain_video, input, custom_context);
            result->is_resourceless_software_draw_with_scroll_or_animation = CallWithContext(Traits::is_resourceless_software_draw_with_scroll_or_animation, input, custom_context);
            result->top_controls_height = CallWithContext(Traits::top_controls_height, input, custom_context);
            result->top_controls_shown_ratio = CallWithContext(Traits::top_controls_shown_ratio, input, custom_context);
            result->bottom_controls_height = CallWithContext(Traits::bottom_controls_height, input, custom_context);
            result->bottom_controls_shown_ratio = CallWithContext(Traits::bottom_controls_shown_ratio, input, custom_context);
            result->root_background_color = CallWithContext(Traits::root_background_color, input, custom_context);
            decltype(CallWithContext(Traits::selection, input, custom_context)) in_selection = CallWithContext(Traits::selection, input, custom_context);
            typename decltype(result->selection)::BaseType* selection_ptr;
            mojo::internal::Serialize<::cc::mojom::SelectionDataView>(
                in_selection, buffer, &selection_ptr, context);
            result->selection.Set(selection_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->selection.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null selection in CompositorFrameMetadata struct");
            decltype(CallWithContext(Traits::latency_info, input, custom_context)) in_latency_info = CallWithContext(Traits::latency_info, input, custom_context);
            typename decltype(result->latency_info)::BaseType* latency_info_ptr;
            const mojo::internal::ContainerValidateParams latency_info_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::ui::mojom::LatencyInfoDataView>>(
                in_latency_info, buffer, &latency_info_ptr, &latency_info_validate_params,
                context);
            result->latency_info.Set(latency_info_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->latency_info.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null latency_info in CompositorFrameMetadata struct");
            decltype(CallWithContext(Traits::referenced_surfaces, input, custom_context)) in_referenced_surfaces = CallWithContext(Traits::referenced_surfaces, input, custom_context);
            typename decltype(result->referenced_surfaces)::BaseType* referenced_surfaces_ptr;
            const mojo::internal::ContainerValidateParams referenced_surfaces_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::cc::mojom::SurfaceIdDataView>>(
                in_referenced_surfaces, buffer, &referenced_surfaces_ptr, &referenced_surfaces_validate_params,
                context);
            result->referenced_surfaces.Set(referenced_surfaces_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->referenced_surfaces.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null referenced_surfaces in CompositorFrameMetadata struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::cc::mojom::internal::CompositorFrameMetadata_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::cc::mojom::CompositorFrameMetadataDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace cc {
namespace mojom {

    inline void CompositorFrameMetadataDataView::GetRootScrollOffsetDataView(
        ::gfx::mojom::Vector2dFDataView* output)
    {
        auto pointer = data_->root_scroll_offset.Get();
        *output = ::gfx::mojom::Vector2dFDataView(pointer, context_);
    }
    inline void CompositorFrameMetadataDataView::GetScrollableViewportSizeDataView(
        ::gfx::mojom::SizeFDataView* output)
    {
        auto pointer = data_->scrollable_viewport_size.Get();
        *output = ::gfx::mojom::SizeFDataView(pointer, context_);
    }
    inline void CompositorFrameMetadataDataView::GetRootLayerSizeDataView(
        ::gfx::mojom::SizeFDataView* output)
    {
        auto pointer = data_->root_layer_size.Get();
        *output = ::gfx::mojom::SizeFDataView(pointer, context_);
    }
    inline void CompositorFrameMetadataDataView::GetSelectionDataView(
        ::cc::mojom::SelectionDataView* output)
    {
        auto pointer = data_->selection.Get();
        *output = ::cc::mojom::SelectionDataView(pointer, context_);
    }
    inline void CompositorFrameMetadataDataView::GetLatencyInfoDataView(
        mojo::ArrayDataView<::ui::mojom::LatencyInfoDataView>* output)
    {
        auto pointer = data_->latency_info.Get();
        *output = mojo::ArrayDataView<::ui::mojom::LatencyInfoDataView>(pointer, context_);
    }
    inline void CompositorFrameMetadataDataView::GetReferencedSurfacesDataView(
        mojo::ArrayDataView<::cc::mojom::SurfaceIdDataView>* output)
    {
        auto pointer = data_->referenced_surfaces.Get();
        *output = mojo::ArrayDataView<::cc::mojom::SurfaceIdDataView>(pointer, context_);
    }

} // namespace mojom
} // namespace cc

#endif // CC_IPC_COMPOSITOR_FRAME_METADATA_MOJOM_SHARED_H_
