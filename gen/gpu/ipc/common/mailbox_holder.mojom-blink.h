// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef GPU_IPC_COMMON_MAILBOX_HOLDER_MOJOM_BLINK_H_
#define GPU_IPC_COMMON_MAILBOX_HOLDER_MOJOM_BLINK_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "gpu/ipc/common/mailbox.mojom-blink.h"
#include "gpu/ipc/common/mailbox_holder.mojom-shared.h"
#include "gpu/ipc/common/sync_token.mojom-blink.h"
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
        class MailboxHolder;
        using MailboxHolderPtr = mojo::StructPtr<MailboxHolder>;

        class MailboxHolder {
        public:
            using DataView = MailboxHolderDataView;
            using Data_ = internal::MailboxHolder_Data;

            static MailboxHolderPtr New();

            template <typename U>
            static MailboxHolderPtr From(const U& u)
            {
                return mojo::TypeConverter<MailboxHolderPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, MailboxHolder>::Convert(*this);
            }

            MailboxHolder();
            ~MailboxHolder();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = MailboxHolderPtr>
            MailboxHolderPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, MailboxHolder>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    MailboxHolder::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    MailboxHolder::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            ::gpu::mojom::blink::MailboxPtr mailbox;
            ::gpu::mojom::blink::SyncTokenPtr sync_token;
            uint32_t texture_target;

        private:
            DISALLOW_COPY_AND_ASSIGN(MailboxHolder);
        };

        template <typename StructPtrType>
        MailboxHolderPtr MailboxHolder::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->mailbox = mojo::internal::Clone(mailbox);
            rv->sync_token = mojo::internal::Clone(sync_token);
            rv->texture_target = mojo::internal::Clone(texture_target);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, MailboxHolder>::value>::type*>
        bool MailboxHolder::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->mailbox, other.mailbox))
                return false;
            if (!mojo::internal::Equals(this->sync_token, other.sync_token))
                return false;
            if (!mojo::internal::Equals(this->texture_target, other.texture_target))
                return false;
            return true;
        }

    } // namespace blink
} // namespace mojom
} // namespace gpu

namespace mojo {

template <>
struct StructTraits<::gpu::mojom::blink::MailboxHolder::DataView,
    ::gpu::mojom::blink::MailboxHolderPtr> {
    static bool IsNull(const ::gpu::mojom::blink::MailboxHolderPtr& input) { return !input; }
    static void SetToNull(::gpu::mojom::blink::MailboxHolderPtr* output) { output->reset(); }

    static const decltype(::gpu::mojom::blink::MailboxHolder::mailbox)& mailbox(
        const ::gpu::mojom::blink::MailboxHolderPtr& input)
    {
        return input->mailbox;
    }

    static const decltype(::gpu::mojom::blink::MailboxHolder::sync_token)& sync_token(
        const ::gpu::mojom::blink::MailboxHolderPtr& input)
    {
        return input->sync_token;
    }

    static decltype(::gpu::mojom::blink::MailboxHolder::texture_target) texture_target(
        const ::gpu::mojom::blink::MailboxHolderPtr& input)
    {
        return input->texture_target;
    }

    static bool Read(::gpu::mojom::blink::MailboxHolder::DataView input, ::gpu::mojom::blink::MailboxHolderPtr* output);
};

} // namespace mojo

#endif // GPU_IPC_COMMON_MAILBOX_HOLDER_MOJOM_BLINK_H_