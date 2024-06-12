// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_COMPOSITOR_FRAME_METADATA_MOJOM_BLINK_H_
#define CC_IPC_COMPOSITOR_FRAME_METADATA_MOJOM_BLINK_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "cc/ipc/compositor_frame_metadata.mojom-shared.h"
#include "cc/ipc/selection.mojom-blink.h"
#include "cc/ipc/surface_id.mojom-blink.h"
#include "mojo/public/cpp/bindings/associated_interface_ptr.h"
#include "mojo/public/cpp/bindings/associated_interface_ptr_info.h"
#include "mojo/public/cpp/bindings/associated_interface_request.h"
#include "mojo/public/cpp/bindings/interface_ptr.h"
#include "mojo/public/cpp/bindings/interface_request.h"
#include "mojo/public/cpp/bindings/lib/clone_equals_util.h"
#include "mojo/public/cpp/bindings/lib/control_message_handler.h"
#include "mojo/public/cpp/bindings/lib/control_message_proxy.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/lib/union_accessor.h"
#include "mojo/public/cpp/bindings/native_struct.h"
#include "mojo/public/cpp/bindings/no_interface.h"
#include "mojo/public/cpp/bindings/raw_ptr_impl_ref_traits.h"
#include "mojo/public/cpp/bindings/struct_ptr.h"
#include "mojo/public/cpp/bindings/struct_traits.h"
#include "mojo/public/cpp/bindings/thread_safe_interface_ptr.h"
#include "mojo/public/cpp/bindings/union_traits.h"
#include "ui/events/mojo/latency_info.mojom-blink.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-blink.h"

#include "base/files/file.h"
#include "cc/output/begin_frame_args.h"
#include "cc/output/compositor_frame.h"
#include "cc/resources/returned_resource.h"
#include "cc/surfaces/frame_sink_id.h"
#include "cc/surfaces/local_frame_id.h"
#include "cc/surfaces/surface_id.h"
#include "cc/surfaces/surface_info.h"
#include "cc/surfaces/surface_sequence.h"
#include "mojo/public/cpp/bindings/lib/wtf_hash_util.h"
#include "third_party/WebKit/Source/wtf/HashFunctions.h"
#include "third_party/WebKit/Source/wtf/Optional.h"
#include "third_party/WebKit/Source/wtf/text/WTFString.h"
#include "third_party/WebKit/public/platform/WebSize.h"

namespace cc {
namespace mojom {
    namespace blink {
        class CompositorFrameMetadata;
        using CompositorFrameMetadataPtr = mojo::StructPtr<CompositorFrameMetadata>;

        class CompositorFrameMetadata {
        public:
            using DataView = CompositorFrameMetadataDataView;
            using Data_ = internal::CompositorFrameMetadata_Data;

            static CompositorFrameMetadataPtr New();

            template <typename U>
            static CompositorFrameMetadataPtr From(const U& u)
            {
                return mojo::TypeConverter<CompositorFrameMetadataPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, CompositorFrameMetadata>::Convert(*this);
            }

            CompositorFrameMetadata();
            ~CompositorFrameMetadata();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = CompositorFrameMetadataPtr>
            CompositorFrameMetadataPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, CompositorFrameMetadata>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    CompositorFrameMetadata::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    CompositorFrameMetadata::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            float device_scale_factor;
            ::gfx::mojom::blink::Vector2dFPtr root_scroll_offset;
            float page_scale_factor;
            ::gfx::mojom::blink::SizeFPtr scrollable_viewport_size;
            ::gfx::mojom::blink::SizeFPtr root_layer_size;
            float min_page_scale_factor;
            float max_page_scale_factor;
            bool root_overflow_x_hidden;
            bool root_overflow_y_hidden;
            bool may_contain_video;
            bool is_resourceless_software_draw_with_scroll_or_animation;
            float top_controls_height;
            float top_controls_shown_ratio;
            float bottom_controls_height;
            float bottom_controls_shown_ratio;
            uint32_t root_background_color;
            ::cc::mojom::blink::SelectionPtr selection;
            WTF::Vector<::ui::mojom::blink::LatencyInfoPtr> latency_info;
            WTF::Vector<cc::SurfaceId> referenced_surfaces;

        private:
            DISALLOW_COPY_AND_ASSIGN(CompositorFrameMetadata);
        };

        template <typename StructPtrType>
        CompositorFrameMetadataPtr CompositorFrameMetadata::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->device_scale_factor = mojo::internal::Clone(device_scale_factor);
            rv->root_scroll_offset = mojo::internal::Clone(root_scroll_offset);
            rv->page_scale_factor = mojo::internal::Clone(page_scale_factor);
            rv->scrollable_viewport_size = mojo::internal::Clone(scrollable_viewport_size);
            rv->root_layer_size = mojo::internal::Clone(root_layer_size);
            rv->min_page_scale_factor = mojo::internal::Clone(min_page_scale_factor);
            rv->max_page_scale_factor = mojo::internal::Clone(max_page_scale_factor);
            rv->root_overflow_x_hidden = mojo::internal::Clone(root_overflow_x_hidden);
            rv->root_overflow_y_hidden = mojo::internal::Clone(root_overflow_y_hidden);
            rv->may_contain_video = mojo::internal::Clone(may_contain_video);
            rv->is_resourceless_software_draw_with_scroll_or_animation = mojo::internal::Clone(is_resourceless_software_draw_with_scroll_or_animation);
            rv->top_controls_height = mojo::internal::Clone(top_controls_height);
            rv->top_controls_shown_ratio = mojo::internal::Clone(top_controls_shown_ratio);
            rv->bottom_controls_height = mojo::internal::Clone(bottom_controls_height);
            rv->bottom_controls_shown_ratio = mojo::internal::Clone(bottom_controls_shown_ratio);
            rv->root_background_color = mojo::internal::Clone(root_background_color);
            rv->selection = mojo::internal::Clone(selection);
            rv->latency_info = mojo::internal::Clone(latency_info);
            rv->referenced_surfaces = mojo::internal::Clone(referenced_surfaces);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, CompositorFrameMetadata>::value>::type*>
        bool CompositorFrameMetadata::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->device_scale_factor, other.device_scale_factor))
                return false;
            if (!mojo::internal::Equals(this->root_scroll_offset, other.root_scroll_offset))
                return false;
            if (!mojo::internal::Equals(this->page_scale_factor, other.page_scale_factor))
                return false;
            if (!mojo::internal::Equals(this->scrollable_viewport_size, other.scrollable_viewport_size))
                return false;
            if (!mojo::internal::Equals(this->root_layer_size, other.root_layer_size))
                return false;
            if (!mojo::internal::Equals(this->min_page_scale_factor, other.min_page_scale_factor))
                return false;
            if (!mojo::internal::Equals(this->max_page_scale_factor, other.max_page_scale_factor))
                return false;
            if (!mojo::internal::Equals(this->root_overflow_x_hidden, other.root_overflow_x_hidden))
                return false;
            if (!mojo::internal::Equals(this->root_overflow_y_hidden, other.root_overflow_y_hidden))
                return false;
            if (!mojo::internal::Equals(this->may_contain_video, other.may_contain_video))
                return false;
            if (!mojo::internal::Equals(this->is_resourceless_software_draw_with_scroll_or_animation, other.is_resourceless_software_draw_with_scroll_or_animation))
                return false;
            if (!mojo::internal::Equals(this->top_controls_height, other.top_controls_height))
                return false;
            if (!mojo::internal::Equals(this->top_controls_shown_ratio, other.top_controls_shown_ratio))
                return false;
            if (!mojo::internal::Equals(this->bottom_controls_height, other.bottom_controls_height))
                return false;
            if (!mojo::internal::Equals(this->bottom_controls_shown_ratio, other.bottom_controls_shown_ratio))
                return false;
            if (!mojo::internal::Equals(this->root_background_color, other.root_background_color))
                return false;
            if (!mojo::internal::Equals(this->selection, other.selection))
                return false;
            if (!mojo::internal::Equals(this->latency_info, other.latency_info))
                return false;
            if (!mojo::internal::Equals(this->referenced_surfaces, other.referenced_surfaces))
                return false;
            return true;
        }

    } // namespace blink
} // namespace mojom
} // namespace cc

namespace mojo {

template <>
struct StructTraits<::cc::mojom::blink::CompositorFrameMetadata::DataView,
    ::cc::mojom::blink::CompositorFrameMetadataPtr> {
    static bool IsNull(const ::cc::mojom::blink::CompositorFrameMetadataPtr& input) { return !input; }
    static void SetToNull(::cc::mojom::blink::CompositorFrameMetadataPtr* output) { output->reset(); }

    static decltype(::cc::mojom::blink::CompositorFrameMetadata::device_scale_factor) device_scale_factor(
        const ::cc::mojom::blink::CompositorFrameMetadataPtr& input)
    {
        return input->device_scale_factor;
    }

    static const decltype(::cc::mojom::blink::CompositorFrameMetadata::root_scroll_offset)& root_scroll_offset(
        const ::cc::mojom::blink::CompositorFrameMetadataPtr& input)
    {
        return input->root_scroll_offset;
    }

    static decltype(::cc::mojom::blink::CompositorFrameMetadata::page_scale_factor) page_scale_factor(
        const ::cc::mojom::blink::CompositorFrameMetadataPtr& input)
    {
        return input->page_scale_factor;
    }

    static const decltype(::cc::mojom::blink::CompositorFrameMetadata::scrollable_viewport_size)& scrollable_viewport_size(
        const ::cc::mojom::blink::CompositorFrameMetadataPtr& input)
    {
        return input->scrollable_viewport_size;
    }

    static const decltype(::cc::mojom::blink::CompositorFrameMetadata::root_layer_size)& root_layer_size(
        const ::cc::mojom::blink::CompositorFrameMetadataPtr& input)
    {
        return input->root_layer_size;
    }

    static decltype(::cc::mojom::blink::CompositorFrameMetadata::min_page_scale_factor) min_page_scale_factor(
        const ::cc::mojom::blink::CompositorFrameMetadataPtr& input)
    {
        return input->min_page_scale_factor;
    }

    static decltype(::cc::mojom::blink::CompositorFrameMetadata::max_page_scale_factor) max_page_scale_factor(
        const ::cc::mojom::blink::CompositorFrameMetadataPtr& input)
    {
        return input->max_page_scale_factor;
    }

    static decltype(::cc::mojom::blink::CompositorFrameMetadata::root_overflow_x_hidden) root_overflow_x_hidden(
        const ::cc::mojom::blink::CompositorFrameMetadataPtr& input)
    {
        return input->root_overflow_x_hidden;
    }

    static decltype(::cc::mojom::blink::CompositorFrameMetadata::root_overflow_y_hidden) root_overflow_y_hidden(
        const ::cc::mojom::blink::CompositorFrameMetadataPtr& input)
    {
        return input->root_overflow_y_hidden;
    }

    static decltype(::cc::mojom::blink::CompositorFrameMetadata::may_contain_video) may_contain_video(
        const ::cc::mojom::blink::CompositorFrameMetadataPtr& input)
    {
        return input->may_contain_video;
    }

    static decltype(::cc::mojom::blink::CompositorFrameMetadata::is_resourceless_software_draw_with_scroll_or_animation) is_resourceless_software_draw_with_scroll_or_animation(
        const ::cc::mojom::blink::CompositorFrameMetadataPtr& input)
    {
        return input->is_resourceless_software_draw_with_scroll_or_animation;
    }

    static decltype(::cc::mojom::blink::CompositorFrameMetadata::top_controls_height) top_controls_height(
        const ::cc::mojom::blink::CompositorFrameMetadataPtr& input)
    {
        return input->top_controls_height;
    }

    static decltype(::cc::mojom::blink::CompositorFrameMetadata::top_controls_shown_ratio) top_controls_shown_ratio(
        const ::cc::mojom::blink::CompositorFrameMetadataPtr& input)
    {
        return input->top_controls_shown_ratio;
    }

    static decltype(::cc::mojom::blink::CompositorFrameMetadata::bottom_controls_height) bottom_controls_height(
        const ::cc::mojom::blink::CompositorFrameMetadataPtr& input)
    {
        return input->bottom_controls_height;
    }

    static decltype(::cc::mojom::blink::CompositorFrameMetadata::bottom_controls_shown_ratio) bottom_controls_shown_ratio(
        const ::cc::mojom::blink::CompositorFrameMetadataPtr& input)
    {
        return input->bottom_controls_shown_ratio;
    }

    static decltype(::cc::mojom::blink::CompositorFrameMetadata::root_background_color) root_background_color(
        const ::cc::mojom::blink::CompositorFrameMetadataPtr& input)
    {
        return input->root_background_color;
    }

    static const decltype(::cc::mojom::blink::CompositorFrameMetadata::selection)& selection(
        const ::cc::mojom::blink::CompositorFrameMetadataPtr& input)
    {
        return input->selection;
    }

    static const decltype(::cc::mojom::blink::CompositorFrameMetadata::latency_info)& latency_info(
        const ::cc::mojom::blink::CompositorFrameMetadataPtr& input)
    {
        return input->latency_info;
    }

    static const decltype(::cc::mojom::blink::CompositorFrameMetadata::referenced_surfaces)& referenced_surfaces(
        const ::cc::mojom::blink::CompositorFrameMetadataPtr& input)
    {
        return input->referenced_surfaces;
    }

    static bool Read(::cc::mojom::blink::CompositorFrameMetadata::DataView input, ::cc::mojom::blink::CompositorFrameMetadataPtr* output);
};

} // namespace mojo

#endif // CC_IPC_COMPOSITOR_FRAME_METADATA_MOJOM_BLINK_H_