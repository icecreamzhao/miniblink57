// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_RETURNED_RESOURCE_MOJOM_H_
#define CC_IPC_RETURNED_RESOURCE_MOJOM_H_

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
#include "cc/ipc/returned_resource.mojom-shared.h"
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
#include "gpu/ipc/common/sync_token.mojom.h"
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
    class ReturnedResource;
    using ReturnedResourcePtr = mojo::StructPtr<ReturnedResource>;

    class ReturnedResourceArray;
    using ReturnedResourceArrayPtr = mojo::StructPtr<ReturnedResourceArray>;

    class ReturnedResource {
    public:
        using DataView = ReturnedResourceDataView;
        using Data_ = internal::ReturnedResource_Data;

        static ReturnedResourcePtr New();

        template <typename U>
        static ReturnedResourcePtr From(const U& u)
        {
            return mojo::TypeConverter<ReturnedResourcePtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, ReturnedResource>::Convert(*this);
        }

        ReturnedResource();
        ~ReturnedResource();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = ReturnedResourcePtr>
        ReturnedResourcePtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, ReturnedResource>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                ReturnedResource::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                ReturnedResource::DataView, std::vector<uint8_t>>(
                input, output);
        }

        uint32_t id;
        ::gpu::SyncToken sync_token;
        int32_t count;
        bool lost;
    };

    class ReturnedResourceArray {
    public:
        using DataView = ReturnedResourceArrayDataView;
        using Data_ = internal::ReturnedResourceArray_Data;

        static ReturnedResourceArrayPtr New();

        template <typename U>
        static ReturnedResourceArrayPtr From(const U& u)
        {
            return mojo::TypeConverter<ReturnedResourceArrayPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, ReturnedResourceArray>::Convert(*this);
        }

        ReturnedResourceArray();
        ~ReturnedResourceArray();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = ReturnedResourceArrayPtr>
        ReturnedResourceArrayPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, ReturnedResourceArray>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                ReturnedResourceArray::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                ReturnedResourceArray::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::vector<cc::ReturnedResource> returned_resources;
    };

    template <typename StructPtrType>
    ReturnedResourcePtr ReturnedResource::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->id = mojo::internal::Clone(id);
        rv->sync_token = mojo::internal::Clone(sync_token);
        rv->count = mojo::internal::Clone(count);
        rv->lost = mojo::internal::Clone(lost);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, ReturnedResource>::value>::type*>
    bool ReturnedResource::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->id, other.id))
            return false;
        if (!mojo::internal::Equals(this->sync_token, other.sync_token))
            return false;
        if (!mojo::internal::Equals(this->count, other.count))
            return false;
        if (!mojo::internal::Equals(this->lost, other.lost))
            return false;
        return true;
    }
    template <typename StructPtrType>
    ReturnedResourceArrayPtr ReturnedResourceArray::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->returned_resources = mojo::internal::Clone(returned_resources);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, ReturnedResourceArray>::value>::type*>
    bool ReturnedResourceArray::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->returned_resources, other.returned_resources))
            return false;
        return true;
    }

} // namespace mojom
} // namespace cc

namespace mojo {

template <>
struct StructTraits<::cc::mojom::ReturnedResource::DataView,
    ::cc::mojom::ReturnedResourcePtr> {
    static bool IsNull(const ::cc::mojom::ReturnedResourcePtr& input) { return !input; }
    static void SetToNull(::cc::mojom::ReturnedResourcePtr* output) { output->reset(); }

    static decltype(::cc::mojom::ReturnedResource::id) id(
        const ::cc::mojom::ReturnedResourcePtr& input)
    {
        return input->id;
    }

    static const decltype(::cc::mojom::ReturnedResource::sync_token)& sync_token(
        const ::cc::mojom::ReturnedResourcePtr& input)
    {
        return input->sync_token;
    }

    static decltype(::cc::mojom::ReturnedResource::count) count(
        const ::cc::mojom::ReturnedResourcePtr& input)
    {
        return input->count;
    }

    static decltype(::cc::mojom::ReturnedResource::lost) lost(
        const ::cc::mojom::ReturnedResourcePtr& input)
    {
        return input->lost;
    }

    static bool Read(::cc::mojom::ReturnedResource::DataView input, ::cc::mojom::ReturnedResourcePtr* output);
};

template <>
struct StructTraits<::cc::mojom::ReturnedResourceArray::DataView,
    ::cc::mojom::ReturnedResourceArrayPtr> {
    static bool IsNull(const ::cc::mojom::ReturnedResourceArrayPtr& input) { return !input; }
    static void SetToNull(::cc::mojom::ReturnedResourceArrayPtr* output) { output->reset(); }

    static const decltype(::cc::mojom::ReturnedResourceArray::returned_resources)& returned_resources(
        const ::cc::mojom::ReturnedResourceArrayPtr& input)
    {
        return input->returned_resources;
    }

    static bool Read(::cc::mojom::ReturnedResourceArray::DataView input, ::cc::mojom::ReturnedResourceArrayPtr* output);
};

} // namespace mojo

#endif // CC_IPC_RETURNED_RESOURCE_MOJOM_H_