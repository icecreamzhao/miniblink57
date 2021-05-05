// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_COMPOSITOR_FRAME_MOJOM_BLINK_H_
#define CC_IPC_COMPOSITOR_FRAME_MOJOM_BLINK_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "cc/ipc/compositor_frame.mojom-shared.h"
#include "cc/ipc/compositor_frame_metadata.mojom-blink.h"
#include "cc/ipc/render_pass.mojom-blink.h"
#include "cc/ipc/transferable_resource.mojom-blink.h"
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
        class CompositorFrame;
        using CompositorFramePtr = mojo::StructPtr<CompositorFrame>;

        class CompositorFrame {
        public:
            using DataView = CompositorFrameDataView;
            using Data_ = internal::CompositorFrame_Data;

            static CompositorFramePtr New();

            template <typename U>
            static CompositorFramePtr From(const U& u)
            {
                return mojo::TypeConverter<CompositorFramePtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, CompositorFrame>::Convert(*this);
            }

            CompositorFrame();
            ~CompositorFrame();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = CompositorFramePtr>
            CompositorFramePtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, CompositorFrame>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    CompositorFrame::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    CompositorFrame::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            ::cc::mojom::blink::CompositorFrameMetadataPtr metadata;
            WTF::Vector<::cc::mojom::blink::TransferableResourcePtr> resources;
            WTF::Vector<::cc::mojom::blink::RenderPassPtr> passes;

        private:
            DISALLOW_COPY_AND_ASSIGN(CompositorFrame);
        };

        template <typename StructPtrType>
        CompositorFramePtr CompositorFrame::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->metadata = mojo::internal::Clone(metadata);
            rv->resources = mojo::internal::Clone(resources);
            rv->passes = mojo::internal::Clone(passes);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, CompositorFrame>::value>::type*>
        bool CompositorFrame::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->metadata, other.metadata))
                return false;
            if (!mojo::internal::Equals(this->resources, other.resources))
                return false;
            if (!mojo::internal::Equals(this->passes, other.passes))
                return false;
            return true;
        }

    } // namespace blink
} // namespace mojom
} // namespace cc

namespace mojo {

template <>
struct StructTraits<::cc::mojom::blink::CompositorFrame::DataView,
    ::cc::mojom::blink::CompositorFramePtr> {
    static bool IsNull(const ::cc::mojom::blink::CompositorFramePtr& input) { return !input; }
    static void SetToNull(::cc::mojom::blink::CompositorFramePtr* output) { output->reset(); }

    static const decltype(::cc::mojom::blink::CompositorFrame::metadata)& metadata(
        const ::cc::mojom::blink::CompositorFramePtr& input)
    {
        return input->metadata;
    }

    static const decltype(::cc::mojom::blink::CompositorFrame::resources)& resources(
        const ::cc::mojom::blink::CompositorFramePtr& input)
    {
        return input->resources;
    }

    static const decltype(::cc::mojom::blink::CompositorFrame::passes)& passes(
        const ::cc::mojom::blink::CompositorFramePtr& input)
    {
        return input->passes;
    }

    static bool Read(::cc::mojom::blink::CompositorFrame::DataView input, ::cc::mojom::blink::CompositorFramePtr* output);
};

} // namespace mojo

#endif // CC_IPC_COMPOSITOR_FRAME_MOJOM_BLINK_H_