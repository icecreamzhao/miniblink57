// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef GPU_IPC_COMMON_SYNC_TOKEN_MOJOM_BLINK_H_
#define GPU_IPC_COMMON_SYNC_TOKEN_MOJOM_BLINK_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "gpu/ipc/common/sync_token.mojom-shared.h"
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
        using CommandBufferNamespace = CommandBufferNamespace; // Alias for definition in the parent namespace.
        class SyncToken;
        using SyncTokenPtr = mojo::StructPtr<SyncToken>;

        class SyncToken {
        public:
            using DataView = SyncTokenDataView;
            using Data_ = internal::SyncToken_Data;

            static SyncTokenPtr New();

            template <typename U>
            static SyncTokenPtr From(const U& u)
            {
                return mojo::TypeConverter<SyncTokenPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, SyncToken>::Convert(*this);
            }

            SyncToken();
            ~SyncToken();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = SyncTokenPtr>
            SyncTokenPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, SyncToken>::value>::type* = nullptr>
            bool Equals(const T& other) const;
            size_t Hash(size_t seed) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    SyncToken::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    SyncToken::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            bool verified_flush;
            CommandBufferNamespace namespace_id;
            int32_t extra_data_field;
            uint64_t command_buffer_id;
            uint64_t release_count;
        };

        template <typename StructPtrType>
        SyncTokenPtr SyncToken::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->verified_flush = mojo::internal::Clone(verified_flush);
            rv->namespace_id = mojo::internal::Clone(namespace_id);
            rv->extra_data_field = mojo::internal::Clone(extra_data_field);
            rv->command_buffer_id = mojo::internal::Clone(command_buffer_id);
            rv->release_count = mojo::internal::Clone(release_count);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, SyncToken>::value>::type*>
        bool SyncToken::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->verified_flush, other.verified_flush))
                return false;
            if (!mojo::internal::Equals(this->namespace_id, other.namespace_id))
                return false;
            if (!mojo::internal::Equals(this->extra_data_field, other.extra_data_field))
                return false;
            if (!mojo::internal::Equals(this->command_buffer_id, other.command_buffer_id))
                return false;
            if (!mojo::internal::Equals(this->release_count, other.release_count))
                return false;
            return true;
        }

    } // namespace blink
} // namespace mojom
} // namespace gpu

namespace mojo {

template <>
struct StructTraits<::gpu::mojom::blink::SyncToken::DataView,
    ::gpu::mojom::blink::SyncTokenPtr> {
    static bool IsNull(const ::gpu::mojom::blink::SyncTokenPtr& input) { return !input; }
    static void SetToNull(::gpu::mojom::blink::SyncTokenPtr* output) { output->reset(); }

    static decltype(::gpu::mojom::blink::SyncToken::verified_flush) verified_flush(
        const ::gpu::mojom::blink::SyncTokenPtr& input)
    {
        return input->verified_flush;
    }

    static decltype(::gpu::mojom::blink::SyncToken::namespace_id) namespace_id(
        const ::gpu::mojom::blink::SyncTokenPtr& input)
    {
        return input->namespace_id;
    }

    static decltype(::gpu::mojom::blink::SyncToken::extra_data_field) extra_data_field(
        const ::gpu::mojom::blink::SyncTokenPtr& input)
    {
        return input->extra_data_field;
    }

    static decltype(::gpu::mojom::blink::SyncToken::command_buffer_id) command_buffer_id(
        const ::gpu::mojom::blink::SyncTokenPtr& input)
    {
        return input->command_buffer_id;
    }

    static decltype(::gpu::mojom::blink::SyncToken::release_count) release_count(
        const ::gpu::mojom::blink::SyncTokenPtr& input)
    {
        return input->release_count;
    }

    static bool Read(::gpu::mojom::blink::SyncToken::DataView input, ::gpu::mojom::blink::SyncTokenPtr* output);
};

} // namespace mojo

#endif // GPU_IPC_COMMON_SYNC_TOKEN_MOJOM_BLINK_H_