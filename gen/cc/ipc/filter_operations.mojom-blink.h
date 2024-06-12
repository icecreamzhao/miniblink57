// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_FILTER_OPERATIONS_MOJOM_BLINK_H_
#define CC_IPC_FILTER_OPERATIONS_MOJOM_BLINK_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "cc/ipc/filter_operation.mojom-blink.h"
#include "cc/ipc/filter_operations.mojom-shared.h"
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
        class FilterOperations;
        using FilterOperationsPtr = mojo::StructPtr<FilterOperations>;

        class FilterOperations {
        public:
            using DataView = FilterOperationsDataView;
            using Data_ = internal::FilterOperations_Data;

            static FilterOperationsPtr New();

            template <typename U>
            static FilterOperationsPtr From(const U& u)
            {
                return mojo::TypeConverter<FilterOperationsPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, FilterOperations>::Convert(*this);
            }

            FilterOperations();
            ~FilterOperations();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = FilterOperationsPtr>
            FilterOperationsPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, FilterOperations>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    FilterOperations::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    FilterOperations::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            WTF::Vector<::cc::mojom::blink::FilterOperationPtr> operations;

        private:
            DISALLOW_COPY_AND_ASSIGN(FilterOperations);
        };

        template <typename StructPtrType>
        FilterOperationsPtr FilterOperations::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->operations = mojo::internal::Clone(operations);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, FilterOperations>::value>::type*>
        bool FilterOperations::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->operations, other.operations))
                return false;
            return true;
        }

    } // namespace blink
} // namespace mojom
} // namespace cc

namespace mojo {

template <>
struct StructTraits<::cc::mojom::blink::FilterOperations::DataView,
    ::cc::mojom::blink::FilterOperationsPtr> {
    static bool IsNull(const ::cc::mojom::blink::FilterOperationsPtr& input) { return !input; }
    static void SetToNull(::cc::mojom::blink::FilterOperationsPtr* output) { output->reset(); }

    static const decltype(::cc::mojom::blink::FilterOperations::operations)& operations(
        const ::cc::mojom::blink::FilterOperationsPtr& input)
    {
        return input->operations;
    }

    static bool Read(::cc::mojom::blink::FilterOperations::DataView input, ::cc::mojom::blink::FilterOperationsPtr* output);
};

} // namespace mojo

#endif // CC_IPC_FILTER_OPERATIONS_MOJOM_BLINK_H_