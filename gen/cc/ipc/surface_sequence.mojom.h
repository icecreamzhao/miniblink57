// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_SURFACE_SEQUENCE_MOJOM_H_
#define CC_IPC_SURFACE_SEQUENCE_MOJOM_H_

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
#include "cc/ipc/frame_sink_id.mojom.h"
#include "cc/ipc/surface_sequence.mojom-shared.h"
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
    class SurfaceSequence;
    using SurfaceSequencePtr = mojo::StructPtr<SurfaceSequence>;

    class SurfaceSequence {
    public:
        using DataView = SurfaceSequenceDataView;
        using Data_ = internal::SurfaceSequence_Data;

        static SurfaceSequencePtr New();

        template <typename U>
        static SurfaceSequencePtr From(const U& u)
        {
            return mojo::TypeConverter<SurfaceSequencePtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, SurfaceSequence>::Convert(*this);
        }

        SurfaceSequence();
        ~SurfaceSequence();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = SurfaceSequencePtr>
        SurfaceSequencePtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, SurfaceSequence>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                SurfaceSequence::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                SurfaceSequence::DataView, std::vector<uint8_t>>(
                input, output);
        }

        cc::FrameSinkId frame_sink_id;
        uint32_t sequence;
    };

    template <typename StructPtrType>
    SurfaceSequencePtr SurfaceSequence::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->frame_sink_id = mojo::internal::Clone(frame_sink_id);
        rv->sequence = mojo::internal::Clone(sequence);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, SurfaceSequence>::value>::type*>
    bool SurfaceSequence::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->frame_sink_id, other.frame_sink_id))
            return false;
        if (!mojo::internal::Equals(this->sequence, other.sequence))
            return false;
        return true;
    }

} // namespace mojom
} // namespace cc

namespace mojo {

template <>
struct StructTraits<::cc::mojom::SurfaceSequence::DataView,
    ::cc::mojom::SurfaceSequencePtr> {
    static bool IsNull(const ::cc::mojom::SurfaceSequencePtr& input) { return !input; }
    static void SetToNull(::cc::mojom::SurfaceSequencePtr* output) { output->reset(); }

    static const decltype(::cc::mojom::SurfaceSequence::frame_sink_id)& frame_sink_id(
        const ::cc::mojom::SurfaceSequencePtr& input)
    {
        return input->frame_sink_id;
    }

    static decltype(::cc::mojom::SurfaceSequence::sequence) sequence(
        const ::cc::mojom::SurfaceSequencePtr& input)
    {
        return input->sequence;
    }

    static bool Read(::cc::mojom::SurfaceSequence::DataView input, ::cc::mojom::SurfaceSequencePtr* output);
};

} // namespace mojo

#endif // CC_IPC_SURFACE_SEQUENCE_MOJOM_H_