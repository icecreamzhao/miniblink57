// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef GPU_IPC_COMMON_DX_DIAG_NODE_MOJOM_BLINK_H_
#define GPU_IPC_COMMON_DX_DIAG_NODE_MOJOM_BLINK_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "gpu/ipc/common/dx_diag_node.mojom-shared.h"
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

#include "base/files/file.h"
#include "mojo/public/cpp/bindings/lib/wtf_hash_util.h"
#include "third_party/WebKit/Source/wtf/HashFunctions.h"
#include "third_party/WebKit/Source/wtf/Optional.h"
#include "third_party/WebKit/Source/wtf/text/WTFString.h"
#include "third_party/WebKit/public/platform/WebSize.h"

namespace gpu {
namespace mojom {
    namespace blink {
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
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    DxDiagNode::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    DxDiagNode::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            WTF::HashMap<WTF::String, WTF::String> values;
            WTF::HashMap<WTF::String, DxDiagNodePtr> children;

        private:
            DISALLOW_COPY_AND_ASSIGN(DxDiagNode);
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

    } // namespace blink
} // namespace mojom
} // namespace gpu

namespace mojo {

template <>
struct StructTraits<::gpu::mojom::blink::DxDiagNode::DataView,
    ::gpu::mojom::blink::DxDiagNodePtr> {
    static bool IsNull(const ::gpu::mojom::blink::DxDiagNodePtr& input) { return !input; }
    static void SetToNull(::gpu::mojom::blink::DxDiagNodePtr* output) { output->reset(); }

    static const decltype(::gpu::mojom::blink::DxDiagNode::values)& values(
        const ::gpu::mojom::blink::DxDiagNodePtr& input)
    {
        return input->values;
    }

    static const decltype(::gpu::mojom::blink::DxDiagNode::children)& children(
        const ::gpu::mojom::blink::DxDiagNodePtr& input)
    {
        return input->children;
    }

    static bool Read(::gpu::mojom::blink::DxDiagNode::DataView input, ::gpu::mojom::blink::DxDiagNodePtr* output);
};

} // namespace mojo

#endif // GPU_IPC_COMMON_DX_DIAG_NODE_MOJOM_BLINK_H_