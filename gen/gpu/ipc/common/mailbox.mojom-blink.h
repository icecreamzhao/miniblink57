// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef GPU_IPC_COMMON_MAILBOX_MOJOM_BLINK_H_
#define GPU_IPC_COMMON_MAILBOX_MOJOM_BLINK_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "gpu/ipc/common/mailbox.mojom-shared.h"
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
        class Mailbox;
        using MailboxPtr = mojo::StructPtr<Mailbox>;

        class Mailbox {
        public:
            using DataView = MailboxDataView;
            using Data_ = internal::Mailbox_Data;

            static MailboxPtr New();

            template <typename U>
            static MailboxPtr From(const U& u)
            {
                return mojo::TypeConverter<MailboxPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, Mailbox>::Convert(*this);
            }

            Mailbox();
            ~Mailbox();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = MailboxPtr>
            MailboxPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, Mailbox>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    Mailbox::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    Mailbox::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            WTF::Vector<int8_t> name;
        };

        template <typename StructPtrType>
        MailboxPtr Mailbox::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->name = mojo::internal::Clone(name);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, Mailbox>::value>::type*>
        bool Mailbox::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->name, other.name))
                return false;
            return true;
        }

    } // namespace blink
} // namespace mojom
} // namespace gpu

namespace mojo {

template <>
struct StructTraits<::gpu::mojom::blink::Mailbox::DataView,
    ::gpu::mojom::blink::MailboxPtr> {
    static bool IsNull(const ::gpu::mojom::blink::MailboxPtr& input) { return !input; }
    static void SetToNull(::gpu::mojom::blink::MailboxPtr* output) { output->reset(); }

    static const decltype(::gpu::mojom::blink::Mailbox::name)& name(
        const ::gpu::mojom::blink::MailboxPtr& input)
    {
        return input->name;
    }

    static bool Read(::gpu::mojom::blink::Mailbox::DataView input, ::gpu::mojom::blink::MailboxPtr* output);
};

} // namespace mojo

#endif // GPU_IPC_COMMON_MAILBOX_MOJOM_BLINK_H_