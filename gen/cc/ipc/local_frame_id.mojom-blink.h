// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_LOCAL_FRAME_ID_MOJOM_BLINK_H_
#define CC_IPC_LOCAL_FRAME_ID_MOJOM_BLINK_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "cc/ipc/local_frame_id.mojom-shared.h"
#include "mojo/common/unguessable_token.mojom-blink.h"
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
        class LocalFrameId;
        using LocalFrameIdPtr = mojo::StructPtr<LocalFrameId>;

        class LocalFrameId {
        public:
            using DataView = LocalFrameIdDataView;
            using Data_ = internal::LocalFrameId_Data;

            static LocalFrameIdPtr New();

            template <typename U>
            static LocalFrameIdPtr From(const U& u)
            {
                return mojo::TypeConverter<LocalFrameIdPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, LocalFrameId>::Convert(*this);
            }

            LocalFrameId();
            ~LocalFrameId();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = LocalFrameIdPtr>
            LocalFrameIdPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, LocalFrameId>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    LocalFrameId::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    LocalFrameId::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            uint32_t local_id;
            ::mojo::common::mojom::blink::UnguessableTokenPtr nonce;

        private:
            DISALLOW_COPY_AND_ASSIGN(LocalFrameId);
        };

        template <typename StructPtrType>
        LocalFrameIdPtr LocalFrameId::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->local_id = mojo::internal::Clone(local_id);
            rv->nonce = mojo::internal::Clone(nonce);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, LocalFrameId>::value>::type*>
        bool LocalFrameId::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->local_id, other.local_id))
                return false;
            if (!mojo::internal::Equals(this->nonce, other.nonce))
                return false;
            return true;
        }

    } // namespace blink
} // namespace mojom
} // namespace cc

namespace mojo {

template <>
struct StructTraits<::cc::mojom::blink::LocalFrameId::DataView,
    ::cc::mojom::blink::LocalFrameIdPtr> {
    static bool IsNull(const ::cc::mojom::blink::LocalFrameIdPtr& input) { return !input; }
    static void SetToNull(::cc::mojom::blink::LocalFrameIdPtr* output) { output->reset(); }

    static decltype(::cc::mojom::blink::LocalFrameId::local_id) local_id(
        const ::cc::mojom::blink::LocalFrameIdPtr& input)
    {
        return input->local_id;
    }

    static const decltype(::cc::mojom::blink::LocalFrameId::nonce)& nonce(
        const ::cc::mojom::blink::LocalFrameIdPtr& input)
    {
        return input->nonce;
    }

    static bool Read(::cc::mojom::blink::LocalFrameId::DataView input, ::cc::mojom::blink::LocalFrameIdPtr* output);
};

} // namespace mojo

#endif // CC_IPC_LOCAL_FRAME_ID_MOJOM_BLINK_H_