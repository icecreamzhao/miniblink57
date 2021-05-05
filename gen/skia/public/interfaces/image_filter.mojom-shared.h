// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SKIA_PUBLIC_INTERFACES_IMAGE_FILTER_MOJOM_SHARED_H_
#define SKIA_PUBLIC_INTERFACES_IMAGE_FILTER_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "skia/public/interfaces/image_filter.mojom-shared-internal.h"

namespace skia {
namespace mojom {
    class ImageFilterDataView;

} // namespace mojom
} // namespace skia

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::skia::mojom::ImageFilterDataView> {
        using Data = ::skia::mojom::internal::ImageFilter_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace skia {
namespace mojom {
    class ImageFilterDataView {
    public:
        ImageFilterDataView() { }

        ImageFilterDataView(
            internal::ImageFilter_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetDataDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadData(UserType* output)
        {
            auto* pointer = data_->data.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }

    private:
        internal::ImageFilter_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace skia

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::skia::mojom::ImageFilterDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::skia::mojom::ImageFilterDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::skia::mojom::internal::ImageFilter_Data);
            decltype(CallWithContext(Traits::data, input, custom_context)) in_data = CallWithContext(Traits::data, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
                in_data, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::skia::mojom::internal::ImageFilter_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::skia::mojom::internal::ImageFilter_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::data, input, custom_context)) in_data = CallWithContext(Traits::data, input, custom_context);
            typename decltype(result->data)::BaseType* data_ptr;
            const mojo::internal::ContainerValidateParams data_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
                in_data, buffer, &data_ptr, &data_validate_params,
                context);
            result->data.Set(data_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->data.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null data in ImageFilter struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::skia::mojom::internal::ImageFilter_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::skia::mojom::ImageFilterDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace skia {
namespace mojom {

    inline void ImageFilterDataView::GetDataDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->data.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

} // namespace mojom
} // namespace skia

#endif // SKIA_PUBLIC_INTERFACES_IMAGE_FILTER_MOJOM_SHARED_H_
