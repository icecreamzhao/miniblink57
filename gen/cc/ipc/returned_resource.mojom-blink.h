// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_RETURNED_RESOURCE_MOJOM_BLINK_H_
#define CC_IPC_RETURNED_RESOURCE_MOJOM_BLINK_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "cc/ipc/returned_resource.mojom-shared.h"
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
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    ReturnedResource::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    ReturnedResource::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            uint32_t id;
            ::gpu::mojom::blink::SyncTokenPtr sync_token;
            int32_t count;
            bool lost;

        private:
            DISALLOW_COPY_AND_ASSIGN(ReturnedResource);
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
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    ReturnedResourceArray::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    ReturnedResourceArray::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            WTF::Vector<cc::ReturnedResource> returned_resources;
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

    } // namespace blink
} // namespace mojom
} // namespace cc

namespace mojo {

template <>
struct StructTraits<::cc::mojom::blink::ReturnedResource::DataView,
    ::cc::mojom::blink::ReturnedResourcePtr> {
    static bool IsNull(const ::cc::mojom::blink::ReturnedResourcePtr& input) { return !input; }
    static void SetToNull(::cc::mojom::blink::ReturnedResourcePtr* output) { output->reset(); }

    static decltype(::cc::mojom::blink::ReturnedResource::id) id(
        const ::cc::mojom::blink::ReturnedResourcePtr& input)
    {
        return input->id;
    }

    static const decltype(::cc::mojom::blink::ReturnedResource::sync_token)& sync_token(
        const ::cc::mojom::blink::ReturnedResourcePtr& input)
    {
        return input->sync_token;
    }

    static decltype(::cc::mojom::blink::ReturnedResource::count) count(
        const ::cc::mojom::blink::ReturnedResourcePtr& input)
    {
        return input->count;
    }

    static decltype(::cc::mojom::blink::ReturnedResource::lost) lost(
        const ::cc::mojom::blink::ReturnedResourcePtr& input)
    {
        return input->lost;
    }

    static bool Read(::cc::mojom::blink::ReturnedResource::DataView input, ::cc::mojom::blink::ReturnedResourcePtr* output);
};

template <>
struct StructTraits<::cc::mojom::blink::ReturnedResourceArray::DataView,
    ::cc::mojom::blink::ReturnedResourceArrayPtr> {
    static bool IsNull(const ::cc::mojom::blink::ReturnedResourceArrayPtr& input) { return !input; }
    static void SetToNull(::cc::mojom::blink::ReturnedResourceArrayPtr* output) { output->reset(); }

    static const decltype(::cc::mojom::blink::ReturnedResourceArray::returned_resources)& returned_resources(
        const ::cc::mojom::blink::ReturnedResourceArrayPtr& input)
    {
        return input->returned_resources;
    }

    static bool Read(::cc::mojom::blink::ReturnedResourceArray::DataView input, ::cc::mojom::blink::ReturnedResourceArrayPtr* output);
};

} // namespace mojo

#endif // CC_IPC_RETURNED_RESOURCE_MOJOM_BLINK_H_