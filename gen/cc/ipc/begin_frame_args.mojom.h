// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_BEGIN_FRAME_ARGS_MOJOM_H_
#define CC_IPC_BEGIN_FRAME_ARGS_MOJOM_H_

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
#include "cc/ipc/begin_frame_args.mojom-shared.h"
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
#include "mojo/common/time.mojom.h"
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
    class BeginFrameArgs;
    using BeginFrameArgsPtr = mojo::StructPtr<BeginFrameArgs>;

    class BeginFrameArgs {
    public:
        using DataView = BeginFrameArgsDataView;
        using Data_ = internal::BeginFrameArgs_Data;

        static BeginFrameArgsPtr New();

        template <typename U>
        static BeginFrameArgsPtr From(const U& u)
        {
            return mojo::TypeConverter<BeginFrameArgsPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, BeginFrameArgs>::Convert(*this);
        }

        BeginFrameArgs();
        ~BeginFrameArgs();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = BeginFrameArgsPtr>
        BeginFrameArgsPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, BeginFrameArgs>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                BeginFrameArgs::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                BeginFrameArgs::DataView, std::vector<uint8_t>>(
                input, output);
        }

        base::TimeTicks frame_time;
        base::TimeTicks deadline;
        base::TimeDelta interval;
        uint64_t sequence_number;
        uint32_t source_id;
        BeginFrameArgsType type;
        bool on_critical_path;
    };

    template <typename StructPtrType>
    BeginFrameArgsPtr BeginFrameArgs::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->frame_time = mojo::internal::Clone(frame_time);
        rv->deadline = mojo::internal::Clone(deadline);
        rv->interval = mojo::internal::Clone(interval);
        rv->sequence_number = mojo::internal::Clone(sequence_number);
        rv->source_id = mojo::internal::Clone(source_id);
        rv->type = mojo::internal::Clone(type);
        rv->on_critical_path = mojo::internal::Clone(on_critical_path);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, BeginFrameArgs>::value>::type*>
    bool BeginFrameArgs::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->frame_time, other.frame_time))
            return false;
        if (!mojo::internal::Equals(this->deadline, other.deadline))
            return false;
        if (!mojo::internal::Equals(this->interval, other.interval))
            return false;
        if (!mojo::internal::Equals(this->sequence_number, other.sequence_number))
            return false;
        if (!mojo::internal::Equals(this->source_id, other.source_id))
            return false;
        if (!mojo::internal::Equals(this->type, other.type))
            return false;
        if (!mojo::internal::Equals(this->on_critical_path, other.on_critical_path))
            return false;
        return true;
    }

} // namespace mojom
} // namespace cc

namespace mojo {

template <>
struct StructTraits<::cc::mojom::BeginFrameArgs::DataView,
    ::cc::mojom::BeginFrameArgsPtr> {
    static bool IsNull(const ::cc::mojom::BeginFrameArgsPtr& input) { return !input; }
    static void SetToNull(::cc::mojom::BeginFrameArgsPtr* output) { output->reset(); }

    static const decltype(::cc::mojom::BeginFrameArgs::frame_time)& frame_time(
        const ::cc::mojom::BeginFrameArgsPtr& input)
    {
        return input->frame_time;
    }

    static const decltype(::cc::mojom::BeginFrameArgs::deadline)& deadline(
        const ::cc::mojom::BeginFrameArgsPtr& input)
    {
        return input->deadline;
    }

    static const decltype(::cc::mojom::BeginFrameArgs::interval)& interval(
        const ::cc::mojom::BeginFrameArgsPtr& input)
    {
        return input->interval;
    }

    static decltype(::cc::mojom::BeginFrameArgs::sequence_number) sequence_number(
        const ::cc::mojom::BeginFrameArgsPtr& input)
    {
        return input->sequence_number;
    }

    static decltype(::cc::mojom::BeginFrameArgs::source_id) source_id(
        const ::cc::mojom::BeginFrameArgsPtr& input)
    {
        return input->source_id;
    }

    static decltype(::cc::mojom::BeginFrameArgs::type) type(
        const ::cc::mojom::BeginFrameArgsPtr& input)
    {
        return input->type;
    }

    static decltype(::cc::mojom::BeginFrameArgs::on_critical_path) on_critical_path(
        const ::cc::mojom::BeginFrameArgsPtr& input)
    {
        return input->on_critical_path;
    }

    static bool Read(::cc::mojom::BeginFrameArgs::DataView input, ::cc::mojom::BeginFrameArgsPtr* output);
};

} // namespace mojo

#endif // CC_IPC_BEGIN_FRAME_ARGS_MOJOM_H_