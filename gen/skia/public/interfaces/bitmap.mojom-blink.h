// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SKIA_PUBLIC_INTERFACES_BITMAP_MOJOM_BLINK_H_
#define SKIA_PUBLIC_INTERFACES_BITMAP_MOJOM_BLINK_H_

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
#include "skia/public/interfaces/bitmap.mojom-shared.h"

#include "mojo/public/cpp/bindings/lib/wtf_hash_util.h"
#include "third_party/WebKit/Source/wtf/HashFunctions.h"
#include "third_party/WebKit/Source/wtf/Optional.h"
#include "third_party/WebKit/Source/wtf/text/WTFString.h"

namespace skia {
namespace mojom {
    namespace blink {
        using ColorType = ColorType; // Alias for definition in the parent namespace.
        using AlphaType = AlphaType; // Alias for definition in the parent namespace.
        using ColorProfileType = ColorProfileType; // Alias for definition in the parent namespace.
        class Bitmap;
        using BitmapPtr = mojo::StructPtr<Bitmap>;

        class Bitmap {
        public:
            using DataView = BitmapDataView;
            using Data_ = internal::Bitmap_Data;

            static BitmapPtr New();

            template <typename U>
            static BitmapPtr From(const U& u)
            {
                return mojo::TypeConverter<BitmapPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, Bitmap>::Convert(*this);
            }

            Bitmap();
            ~Bitmap();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = BitmapPtr>
            BitmapPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, Bitmap>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    Bitmap::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    Bitmap::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            ColorType color_type;
            AlphaType alpha_type;
            ColorProfileType profile_type;
            uint32_t width;
            uint32_t height;
            uint64_t row_bytes;
            WTF::Vector<uint8_t> pixel_data;
        };

        template <typename StructPtrType>
        BitmapPtr Bitmap::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->color_type = mojo::internal::Clone(color_type);
            rv->alpha_type = mojo::internal::Clone(alpha_type);
            rv->profile_type = mojo::internal::Clone(profile_type);
            rv->width = mojo::internal::Clone(width);
            rv->height = mojo::internal::Clone(height);
            rv->row_bytes = mojo::internal::Clone(row_bytes);
            rv->pixel_data = mojo::internal::Clone(pixel_data);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, Bitmap>::value>::type*>
        bool Bitmap::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->color_type, other.color_type))
                return false;
            if (!mojo::internal::Equals(this->alpha_type, other.alpha_type))
                return false;
            if (!mojo::internal::Equals(this->profile_type, other.profile_type))
                return false;
            if (!mojo::internal::Equals(this->width, other.width))
                return false;
            if (!mojo::internal::Equals(this->height, other.height))
                return false;
            if (!mojo::internal::Equals(this->row_bytes, other.row_bytes))
                return false;
            if (!mojo::internal::Equals(this->pixel_data, other.pixel_data))
                return false;
            return true;
        }

    } // namespace blink
} // namespace mojom
} // namespace skia

namespace mojo {

template <>
struct StructTraits<::skia::mojom::blink::Bitmap::DataView,
    ::skia::mojom::blink::BitmapPtr> {
    static bool IsNull(const ::skia::mojom::blink::BitmapPtr& input) { return !input; }
    static void SetToNull(::skia::mojom::blink::BitmapPtr* output) { output->reset(); }

    static decltype(::skia::mojom::blink::Bitmap::color_type) color_type(
        const ::skia::mojom::blink::BitmapPtr& input)
    {
        return input->color_type;
    }

    static decltype(::skia::mojom::blink::Bitmap::alpha_type) alpha_type(
        const ::skia::mojom::blink::BitmapPtr& input)
    {
        return input->alpha_type;
    }

    static decltype(::skia::mojom::blink::Bitmap::profile_type) profile_type(
        const ::skia::mojom::blink::BitmapPtr& input)
    {
        return input->profile_type;
    }

    static decltype(::skia::mojom::blink::Bitmap::width) width(
        const ::skia::mojom::blink::BitmapPtr& input)
    {
        return input->width;
    }

    static decltype(::skia::mojom::blink::Bitmap::height) height(
        const ::skia::mojom::blink::BitmapPtr& input)
    {
        return input->height;
    }

    static decltype(::skia::mojom::blink::Bitmap::row_bytes) row_bytes(
        const ::skia::mojom::blink::BitmapPtr& input)
    {
        return input->row_bytes;
    }

    static const decltype(::skia::mojom::blink::Bitmap::pixel_data)& pixel_data(
        const ::skia::mojom::blink::BitmapPtr& input)
    {
        return input->pixel_data;
    }

    static bool Read(::skia::mojom::blink::Bitmap::DataView input, ::skia::mojom::blink::BitmapPtr* output);
};

} // namespace mojo

#endif // SKIA_PUBLIC_INTERFACES_BITMAP_MOJOM_BLINK_H_