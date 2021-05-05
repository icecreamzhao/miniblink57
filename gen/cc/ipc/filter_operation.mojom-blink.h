// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_FILTER_OPERATION_MOJOM_BLINK_H_
#define CC_IPC_FILTER_OPERATION_MOJOM_BLINK_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "cc/ipc/filter_operation.mojom-shared.h"
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
#include "skia/public/interfaces/image_filter.mojom-blink.h"
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
        using FilterType = FilterType; // Alias for definition in the parent namespace.
        class FilterOperation;
        using FilterOperationPtr = mojo::StructPtr<FilterOperation>;

        class FilterOperation {
        public:
            using DataView = FilterOperationDataView;
            using Data_ = internal::FilterOperation_Data;

            static FilterOperationPtr New();

            template <typename U>
            static FilterOperationPtr From(const U& u)
            {
                return mojo::TypeConverter<FilterOperationPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, FilterOperation>::Convert(*this);
            }

            FilterOperation();
            ~FilterOperation();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = FilterOperationPtr>
            FilterOperationPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, FilterOperation>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    FilterOperation::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    FilterOperation::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            FilterType type;
            float amount;
            ::gfx::mojom::blink::PointPtr drop_shadow_offset;
            uint32_t drop_shadow_color;
            ::skia::mojom::blink::ImageFilterPtr image_filter;
            WTF::Optional<WTF::Vector<float>> matrix;
            int32_t zoom_inset;

        private:
            DISALLOW_COPY_AND_ASSIGN(FilterOperation);
        };

        template <typename StructPtrType>
        FilterOperationPtr FilterOperation::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->type = mojo::internal::Clone(type);
            rv->amount = mojo::internal::Clone(amount);
            rv->drop_shadow_offset = mojo::internal::Clone(drop_shadow_offset);
            rv->drop_shadow_color = mojo::internal::Clone(drop_shadow_color);
            rv->image_filter = mojo::internal::Clone(image_filter);
            rv->matrix = mojo::internal::Clone(matrix);
            rv->zoom_inset = mojo::internal::Clone(zoom_inset);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, FilterOperation>::value>::type*>
        bool FilterOperation::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->type, other.type))
                return false;
            if (!mojo::internal::Equals(this->amount, other.amount))
                return false;
            if (!mojo::internal::Equals(this->drop_shadow_offset, other.drop_shadow_offset))
                return false;
            if (!mojo::internal::Equals(this->drop_shadow_color, other.drop_shadow_color))
                return false;
            if (!mojo::internal::Equals(this->image_filter, other.image_filter))
                return false;
            if (!mojo::internal::Equals(this->matrix, other.matrix))
                return false;
            if (!mojo::internal::Equals(this->zoom_inset, other.zoom_inset))
                return false;
            return true;
        }

    } // namespace blink
} // namespace mojom
} // namespace cc

namespace mojo {

template <>
struct StructTraits<::cc::mojom::blink::FilterOperation::DataView,
    ::cc::mojom::blink::FilterOperationPtr> {
    static bool IsNull(const ::cc::mojom::blink::FilterOperationPtr& input) { return !input; }
    static void SetToNull(::cc::mojom::blink::FilterOperationPtr* output) { output->reset(); }

    static decltype(::cc::mojom::blink::FilterOperation::type) type(
        const ::cc::mojom::blink::FilterOperationPtr& input)
    {
        return input->type;
    }

    static decltype(::cc::mojom::blink::FilterOperation::amount) amount(
        const ::cc::mojom::blink::FilterOperationPtr& input)
    {
        return input->amount;
    }

    static const decltype(::cc::mojom::blink::FilterOperation::drop_shadow_offset)& drop_shadow_offset(
        const ::cc::mojom::blink::FilterOperationPtr& input)
    {
        return input->drop_shadow_offset;
    }

    static decltype(::cc::mojom::blink::FilterOperation::drop_shadow_color) drop_shadow_color(
        const ::cc::mojom::blink::FilterOperationPtr& input)
    {
        return input->drop_shadow_color;
    }

    static const decltype(::cc::mojom::blink::FilterOperation::image_filter)& image_filter(
        const ::cc::mojom::blink::FilterOperationPtr& input)
    {
        return input->image_filter;
    }

    static const decltype(::cc::mojom::blink::FilterOperation::matrix)& matrix(
        const ::cc::mojom::blink::FilterOperationPtr& input)
    {
        return input->matrix;
    }

    static decltype(::cc::mojom::blink::FilterOperation::zoom_inset) zoom_inset(
        const ::cc::mojom::blink::FilterOperationPtr& input)
    {
        return input->zoom_inset;
    }

    static bool Read(::cc::mojom::blink::FilterOperation::DataView input, ::cc::mojom::blink::FilterOperationPtr* output);
};

} // namespace mojo

#endif // CC_IPC_FILTER_OPERATION_MOJOM_BLINK_H_