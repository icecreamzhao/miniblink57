// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef GPU_IPC_COMMON_DX_DIAG_NODE_MOJOM_H_
#define GPU_IPC_COMMON_DX_DIAG_NODE_MOJOM_H_

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
#include "gpu/command_buffer/common/capabilities.h"
#include "gpu/command_buffer/common/mailbox.h"
#include "gpu/command_buffer/common/mailbox_holder.h"
#include "gpu/command_buffer/common/sync_token.h"
#include "gpu/command_buffer/service/gpu_preferences.h"
#include "gpu/config/dx_diag_node.h"
#include "gpu/config/gpu_info.h"
#include "gpu/ipc/common/dx_diag_node.mojom-shared.h"
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
#include "ui/gfx/geometry/insets.h"
#include "ui/gfx/geometry/point.h"
#include "ui/gfx/geometry/point_f.h"
#include "ui/gfx/geometry/rect.h"
#include "ui/gfx/geometry/rect_f.h"
#include "ui/gfx/geometry/safe_integer_conversions.h"
#include "ui/gfx/geometry/size.h"
#include "ui/gfx/geometry/vector2d.h"
#include "ui/gfx/geometry/vector2d_f.h"
#include <string>
#include <vector>

namespace gpu {
namespace mojom {
    class DxDiagNode;
    using DxDiagNodePtr = mojo::StructPtr<DxDiagNode>;

    class DxDiagNode {
    public:
        using DataView = DxDiagNodeDataView;
        using Data_ = internal::DxDiagNode_Data;

        static DxDiagNodePtr New();

        template <typename U>
        static DxDiagNodePtr From(const U& u)
        {
            return mojo::TypeConverter<DxDiagNodePtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, DxDiagNode>::Convert(*this);
        }

        DxDiagNode();
        ~DxDiagNode();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = DxDiagNodePtr>
        DxDiagNodePtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, DxDiagNode>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                DxDiagNode::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                DxDiagNode::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::unordered_map<std::string, std::string> values;
        std::unordered_map<std::string, gpu::DxDiagNode> children;
    };

    template <typename StructPtrType>
    DxDiagNodePtr DxDiagNode::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->values = mojo::internal::Clone(values);
        rv->children = mojo::internal::Clone(children);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, DxDiagNode>::value>::type*>
    bool DxDiagNode::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->values, other.values))
            return false;
        if (!mojo::internal::Equals(this->children, other.children))
            return false;
        return true;
    }

} // namespace mojom
} // namespace gpu

namespace mojo {

template <>
struct StructTraits<::gpu::mojom::DxDiagNode::DataView,
    ::gpu::mojom::DxDiagNodePtr> {
    static bool IsNull(const ::gpu::mojom::DxDiagNodePtr& input) { return !input; }
    static void SetToNull(::gpu::mojom::DxDiagNodePtr* output) { output->reset(); }

    static const decltype(::gpu::mojom::DxDiagNode::values)& values(
        const ::gpu::mojom::DxDiagNodePtr& input)
    {
        return input->values;
    }

    static const decltype(::gpu::mojom::DxDiagNode::children)& children(
        const ::gpu::mojom::DxDiagNodePtr& input)
    {
        return input->children;
    }

    static bool Read(::gpu::mojom::DxDiagNode::DataView input, ::gpu::mojom::DxDiagNodePtr* output);
};

} // namespace mojo

#endif // GPU_IPC_COMMON_DX_DIAG_NODE_MOJOM_H_