// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_TRANSFERABLE_RESOURCE_MOJOM_BLINK_H_
#define CC_IPC_TRANSFERABLE_RESOURCE_MOJOM_BLINK_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "cc/ipc/transferable_resource.mojom-shared.h"
#include "gpu/ipc/common/mailbox_holder.mojom-blink.h"
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
        using ResourceFormat = ResourceFormat; // Alias for definition in the parent namespace.
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
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    TransferableResource::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    TransferableResource::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            uint32_t id;
            ResourceFormat format;
            uint32_t filter;
            ::blink::WebSize size;
            ::gpu::mojom::blink::MailboxHolderPtr mailbox_holder;
            bool read_lock_fences_enabled;
            bool is_software;
            bool is_overlay_candidate;
            bool is_backed_by_surface_texture;
            bool wants_promotion_hint;

        private:
            DISALLOW_COPY_AND_ASSIGN(TransferableResource);
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

    } // namespace blink
} // namespace mojom
} // namespace cc

namespace mojo {

template <>
struct StructTraits<::cc::mojom::blink::TransferableResource::DataView,
    ::cc::mojom::blink::TransferableResourcePtr> {
    static bool IsNull(const ::cc::mojom::blink::TransferableResourcePtr& input) { return !input; }
    static void SetToNull(::cc::mojom::blink::TransferableResourcePtr* output) { output->reset(); }

    static decltype(::cc::mojom::blink::TransferableResource::id) id(
        const ::cc::mojom::blink::TransferableResourcePtr& input)
    {
        return input->id;
    }

    static decltype(::cc::mojom::blink::TransferableResource::format) format(
        const ::cc::mojom::blink::TransferableResourcePtr& input)
    {
        return input->format;
    }

    static decltype(::cc::mojom::blink::TransferableResource::filter) filter(
        const ::cc::mojom::blink::TransferableResourcePtr& input)
    {
        return input->filter;
    }

    static const decltype(::cc::mojom::blink::TransferableResource::size)& size(
        const ::cc::mojom::blink::TransferableResourcePtr& input)
    {
        return input->size;
    }

    static const decltype(::cc::mojom::blink::TransferableResource::mailbox_holder)& mailbox_holder(
        const ::cc::mojom::blink::TransferableResourcePtr& input)
    {
        return input->mailbox_holder;
    }

    static decltype(::cc::mojom::blink::TransferableResource::read_lock_fences_enabled) read_lock_fences_enabled(
        const ::cc::mojom::blink::TransferableResourcePtr& input)
    {
        return input->read_lock_fences_enabled;
    }

    static decltype(::cc::mojom::blink::TransferableResource::is_software) is_software(
        const ::cc::mojom::blink::TransferableResourcePtr& input)
    {
        return input->is_software;
    }

    static decltype(::cc::mojom::blink::TransferableResource::is_overlay_candidate) is_overlay_candidate(
        const ::cc::mojom::blink::TransferableResourcePtr& input)
    {
        return input->is_overlay_candidate;
    }

    static decltype(::cc::mojom::blink::TransferableResource::is_backed_by_surface_texture) is_backed_by_surface_texture(
        const ::cc::mojom::blink::TransferableResourcePtr& input)
    {
        return input->is_backed_by_surface_texture;
    }

    static decltype(::cc::mojom::blink::TransferableResource::wants_promotion_hint) wants_promotion_hint(
        const ::cc::mojom::blink::TransferableResourcePtr& input)
    {
        return input->wants_promotion_hint;
    }

    static bool Read(::cc::mojom::blink::TransferableResource::DataView input, ::cc::mojom::blink::TransferableResourcePtr* output);
};

} // namespace mojo

#endif // CC_IPC_TRANSFERABLE_RESOURCE_MOJOM_BLINK_H_