// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_TRANSFERABLE_RESOURCE_MOJOM_H_
#define CC_IPC_TRANSFERABLE_RESOURCE_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/files/file.h"
#include "base/files/file_path.h"
#include "base/i18n/rtl.h"
#include "base/optional.h"
#include "base/strings/string16.h"
#include "base/time/time.h"
#include "base/unguessable_token.h"
#include "base/values.h"
#include "base/version.h"
#include "cc/input/selection.h"
#include "cc/ipc/transferable_resource.mojom-shared.h"
#include "cc/output/begin_frame_args.h"
#include "cc/output/compositor_frame.h"
#include "cc/output/compositor_frame_metadata.h"
#include "cc/output/filter_operation.h"
#include "cc/output/filter_operations.h"
#include "cc/quads/draw_quad.h"
#include "cc/quads/render_pass.h"
#include "cc/quads/shared_quad_state.h"
#include "cc/resources/returned_resource.h"
#include "cc/resources/transferable_resource.h"
#include "cc/surfaces/frame_sink_id.h"
#include "cc/surfaces/local_frame_id.h"
#include "cc/surfaces/surface_id.h"
#include "cc/surfaces/surface_info.h"
#include "cc/surfaces/surface_reference.h"
#include "cc/surfaces/surface_sequence.h"
#include "gpu/command_buffer/common/capabilities.h"
#include "gpu/command_buffer/common/mailbox.h"
#include "gpu/command_buffer/common/mailbox_holder.h"
#include "gpu/command_buffer/common/sync_token.h"
#include "gpu/command_buffer/service/gpu_preferences.h"
#include "gpu/config/dx_diag_node.h"
#include "gpu/config/gpu_info.h"
#include "gpu/ipc/common/mailbox_holder.mojom.h"
#include "gpu/ipc/common/surface_handle.h"
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
#include "third_party/skia/include/core/SkBitmap.h"
#include "third_party/skia/include/core/SkImageFilter.h"
#include "ui/events/event.h"
#include "ui/events/latency_info.h"
#include "ui/gfx/buffer_types.h"
#include "ui/gfx/color_space.h"
#include "ui/gfx/geometry/insets.h"
#include "ui/gfx/geometry/mojo/geometry.mojom.h"
#include "ui/gfx/geometry/point.h"
#include "ui/gfx/geometry/point_f.h"
#include "ui/gfx/geometry/rect.h"
#include "ui/gfx/geometry/rect_f.h"
#include "ui/gfx/geometry/safe_integer_conversions.h"
#include "ui/gfx/geometry/size.h"
#include "ui/gfx/geometry/vector2d.h"
#include "ui/gfx/geometry/vector2d_f.h"
#include "ui/gfx/gpu_memory_buffer.h"
#include "ui/gfx/icc_profile.h"
#include "ui/gfx/native_pixmap_handle.h"
#include "ui/gfx/native_widget_types.h"
#include "ui/gfx/selection_bound.h"
#include "ui/gfx/transform.h"
#include <string>
#include <vector>

namespace cc {
namespace mojom {
    class TransferableResource;
    using TransferableResourcePtr = mojo::StructPtr<TransferableResource>;

    class TransferableResource {
    public:
        using DataView = TransferableResourceDataView;
        using Data_ = internal::TransferableResource_Data;

        static TransferableResourcePtr New();

        template <typename U>
        static TransferableResourcePtr From(const U& u)
        {
            return mojo::TypeConverter<TransferableResourcePtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, TransferableResource>::Convert(*this);
        }

        TransferableResource();
        ~TransferableResource();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = TransferableResourcePtr>
        TransferableResourcePtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, TransferableResource>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                TransferableResource::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                TransferableResource::DataView, std::vector<uint8_t>>(
                input, output);
        }

        uint32_t id;
        ResourceFormat format;
        uint32_t filter;
        gfx::Size size;
        ::gpu::MailboxHolder mailbox_holder;
        bool read_lock_fences_enabled;
        bool is_software;
        bool is_overlay_candidate;
        bool is_backed_by_surface_texture;
        bool wants_promotion_hint;
    };

    template <typename StructPtrType>
    TransferableResourcePtr TransferableResource::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->id = mojo::internal::Clone(id);
        rv->format = mojo::internal::Clone(format);
        rv->filter = mojo::internal::Clone(filter);
        rv->size = mojo::internal::Clone(size);
        rv->mailbox_holder = mojo::internal::Clone(mailbox_holder);
        rv->read_lock_fences_enabled = mojo::internal::Clone(read_lock_fences_enabled);
        rv->is_software = mojo::internal::Clone(is_software);
        rv->is_overlay_candidate = mojo::internal::Clone(is_overlay_candidate);
        rv->is_backed_by_surface_texture = mojo::internal::Clone(is_backed_by_surface_texture);
        rv->wants_promotion_hint = mojo::internal::Clone(wants_promotion_hint);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, TransferableResource>::value>::type*>
    bool TransferableResource::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->id, other.id))
            return false;
        if (!mojo::internal::Equals(this->format, other.format))
            return false;
        if (!mojo::internal::Equals(this->filter, other.filter))
            return false;
        if (!mojo::internal::Equals(this->size, other.size))
            return false;
        if (!mojo::internal::Equals(this->mailbox_holder, other.mailbox_holder))
            return false;
        if (!mojo::internal::Equals(this->read_lock_fences_enabled, other.read_lock_fences_enabled))
            return false;
        if (!mojo::internal::Equals(this->is_software, other.is_software))
            return false;
        if (!mojo::internal::Equals(this->is_overlay_candidate, other.is_overlay_candidate))
            return false;
        if (!mojo::internal::Equals(this->is_backed_by_surface_texture, other.is_backed_by_surface_texture))
            return false;
        if (!mojo::internal::Equals(this->wants_promotion_hint, other.wants_promotion_hint))
            return false;
        return true;
    }

} // namespace mojom
} // namespace cc

namespace mojo {

template <>
struct StructTraits<::cc::mojom::TransferableResource::DataView,
    ::cc::mojom::TransferableResourcePtr> {
    static bool IsNull(const ::cc::mojom::TransferableResourcePtr& input) { return !input; }
    static void SetToNull(::cc::mojom::TransferableResourcePtr* output) { output->reset(); }

    static decltype(::cc::mojom::TransferableResource::id) id(
        const ::cc::mojom::TransferableResourcePtr& input)
    {
        return input->id;
    }

    static decltype(::cc::mojom::TransferableResource::format) format(
        const ::cc::mojom::TransferableResourcePtr& input)
    {
        return input->format;
    }

    static decltype(::cc::mojom::TransferableResource::filter) filter(
        const ::cc::mojom::TransferableResourcePtr& input)
    {
        return input->filter;
    }

    static const decltype(::cc::mojom::TransferableResource::size)& size(
        const ::cc::mojom::TransferableResourcePtr& input)
    {
        return input->size;
    }

    static const decltype(::cc::mojom::TransferableResource::mailbox_holder)& mailbox_holder(
        const ::cc::mojom::TransferableResourcePtr& input)
    {
        return input->mailbox_holder;
    }

    static decltype(::cc::mojom::TransferableResource::read_lock_fences_enabled) read_lock_fences_enabled(
        const ::cc::mojom::TransferableResourcePtr& input)
    {
        return input->read_lock_fences_enabled;
    }

    static decltype(::cc::mojom::TransferableResource::is_software) is_software(
        const ::cc::mojom::TransferableResourcePtr& input)
    {
        return input->is_software;
    }

    static decltype(::cc::mojom::TransferableResource::is_overlay_candidate) is_overlay_candidate(
        const ::cc::mojom::TransferableResourcePtr& input)
    {
        return input->is_overlay_candidate;
    }

    static decltype(::cc::mojom::TransferableResource::is_backed_by_surface_texture) is_backed_by_surface_texture(
        const ::cc::mojom::TransferableResourcePtr& input)
    {
        return input->is_backed_by_surface_texture;
    }

    static decltype(::cc::mojom::TransferableResource::wants_promotion_hint) wants_promotion_hint(
        const ::cc::mojom::TransferableResourcePtr& input)
    {
        return input->wants_promotion_hint;
    }

    static bool Read(::cc::mojom::TransferableResource::DataView input, ::cc::mojom::TransferableResourcePtr* output);
};

} // namespace mojo

#endif // CC_IPC_TRANSFERABLE_RESOURCE_MOJOM_H_