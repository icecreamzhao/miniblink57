// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SKIA_PUBLIC_INTERFACES_IMAGE_FILTER_MOJOM_H_
#define SKIA_PUBLIC_INTERFACES_IMAGE_FILTER_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
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
#include "skia/public/interfaces/image_filter.mojom-shared.h"
#include "third_party/skia/include/core/SkBitmap.h"
#include "third_party/skia/include/core/SkImageFilter.h"
#include <string>
#include <vector>

namespace skia {
namespace mojom {
    class ImageFilter;
    using ImageFilterPtr = mojo::StructPtr<ImageFilter>;

    class ImageFilter {
    public:
        using DataView = ImageFilterDataView;
        using Data_ = internal::ImageFilter_Data;

        static ImageFilterPtr New();

        template <typename U>
        static ImageFilterPtr From(const U& u)
        {
            return mojo::TypeConverter<ImageFilterPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, ImageFilter>::Convert(*this);
        }

        ImageFilter();
        ~ImageFilter();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = ImageFilterPtr>
        ImageFilterPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, ImageFilter>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                ImageFilter::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                ImageFilter::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::vector<uint8_t> data;
    };

    template <typename StructPtrType>
    ImageFilterPtr ImageFilter::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->data = mojo::internal::Clone(data);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, ImageFilter>::value>::type*>
    bool ImageFilter::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->data, other.data))
            return false;
        return true;
    }

} // namespace mojom
} // namespace skia

namespace mojo {

template <>
struct StructTraits<::skia::mojom::ImageFilter::DataView,
    ::skia::mojom::ImageFilterPtr> {
    static bool IsNull(const ::skia::mojom::ImageFilterPtr& input) { return !input; }
    static void SetToNull(::skia::mojom::ImageFilterPtr* output) { output->reset(); }

    static const decltype(::skia::mojom::ImageFilter::data)& data(
        const ::skia::mojom::ImageFilterPtr& input)
    {
        return input->data;
    }

    static bool Read(::skia::mojom::ImageFilter::DataView input, ::skia::mojom::ImageFilterPtr* output);
};

} // namespace mojo

#endif // SKIA_PUBLIC_INTERFACES_IMAGE_FILTER_MOJOM_H_