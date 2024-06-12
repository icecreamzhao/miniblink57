// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_SHAPE_DETECTION_PUBLIC_INTERFACES_TEXTDETECTION_MOJOM_SHARED_H_
#define SERVICES_SHAPE_DETECTION_PUBLIC_INTERFACES_TEXTDETECTION_MOJOM_SHARED_H_

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
#include "services/shape_detection/public/interfaces/textdetection.mojom-shared-internal.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared.h"

namespace shape_detection {
namespace mojom {
    class TextDetectionResultDataView;

} // namespace mojom
} // namespace shape_detection

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::shape_detection::mojom::TextDetectionResultDataView> {
        using Data = ::shape_detection::mojom::internal::TextDetectionResult_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace shape_detection {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class TextDetectionInterfaceBase {
    };

    using TextDetectionPtrDataView = mojo::InterfacePtrDataView<TextDetectionInterfaceBase>;
    using TextDetectionRequestDataView = mojo::InterfaceRequestDataView<TextDetectionInterfaceBase>;
    using TextDetectionAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<TextDetectionInterfaceBase>;
    using TextDetectionAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<TextDetectionInterfaceBase>;
    class TextDetectionResultDataView {
    public:
        TextDetectionResultDataView() { }

        TextDetectionResultDataView(
            internal::TextDetectionResult_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetRawValueDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadRawValue(UserType* output)
        {
            auto* pointer = data_->raw_value.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetBoundingBoxDataView(
            ::gfx::mojom::RectFDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadBoundingBox(UserType* output)
        {
            auto* pointer = data_->bounding_box.Get();
            return mojo::internal::Deserialize<::gfx::mojom::RectFDataView>(
                pointer, output, context_);
        }

    private:
        internal::TextDetectionResult_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class TextDetection_Detect_ParamsDataView {
    public:
        TextDetection_Detect_ParamsDataView() { }

        TextDetection_Detect_ParamsDataView(
            internal::TextDetection_Detect_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        mojo::ScopedSharedBufferHandle TakeFrameData()
        {
            mojo::ScopedSharedBufferHandle result;
            bool ret = mojo::internal::Deserialize<mojo::ScopedSharedBufferHandle>(
                &data_->frame_data, &result, context_);
            DCHECK(ret);
            return result;
        }
        uint32_t width() const
        {
            return data_->width;
        }
        uint32_t height() const
        {
            return data_->height;
        }

    private:
        internal::TextDetection_Detect_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class TextDetection_Detect_ResponseParamsDataView {
    public:
        TextDetection_Detect_ResponseParamsDataView() { }

        TextDetection_Detect_ResponseParamsDataView(
            internal::TextDetection_Detect_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetResultsDataView(
            mojo::ArrayDataView<TextDetectionResultDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadResults(UserType* output)
        {
            auto* pointer = data_->results.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::shape_detection::mojom::TextDetectionResultDataView>>(
                pointer, output, context_);
        }

    private:
        internal::TextDetection_Detect_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace shape_detection

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::shape_detection::mojom::TextDetectionResultDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::shape_detection::mojom::TextDetectionResultDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::shape_detection::mojom::internal::TextDetectionResult_Data);
            decltype(CallWithContext(Traits::raw_value, input, custom_context)) in_raw_value = CallWithContext(Traits::raw_value, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_raw_value, context);
            decltype(CallWithContext(Traits::bounding_box, input, custom_context)) in_bounding_box = CallWithContext(Traits::bounding_box, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::RectFDataView>(
                in_bounding_box, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::shape_detection::mojom::internal::TextDetectionResult_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::shape_detection::mojom::internal::TextDetectionResult_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::raw_value, input, custom_context)) in_raw_value = CallWithContext(Traits::raw_value, input, custom_context);
            typename decltype(result->raw_value)::BaseType* raw_value_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_raw_value, buffer, &raw_value_ptr, context);
            result->raw_value.Set(raw_value_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->raw_value.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null raw_value in TextDetectionResult struct");
            decltype(CallWithContext(Traits::bounding_box, input, custom_context)) in_bounding_box = CallWithContext(Traits::bounding_box, input, custom_context);
            typename decltype(result->bounding_box)::BaseType* bounding_box_ptr;
            mojo::internal::Serialize<::gfx::mojom::RectFDataView>(
                in_bounding_box, buffer, &bounding_box_ptr, context);
            result->bounding_box.Set(bounding_box_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->bounding_box.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null bounding_box in TextDetectionResult struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::shape_detection::mojom::internal::TextDetectionResult_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::shape_detection::mojom::TextDetectionResultDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace shape_detection {
namespace mojom {

    inline void TextDetectionResultDataView::GetRawValueDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->raw_value.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void TextDetectionResultDataView::GetBoundingBoxDataView(
        ::gfx::mojom::RectFDataView* output)
    {
        auto pointer = data_->bounding_box.Get();
        *output = ::gfx::mojom::RectFDataView(pointer, context_);
    }

    inline void TextDetection_Detect_ResponseParamsDataView::GetResultsDataView(
        mojo::ArrayDataView<TextDetectionResultDataView>* output)
    {
        auto pointer = data_->results.Get();
        *output = mojo::ArrayDataView<TextDetectionResultDataView>(pointer, context_);
    }

} // namespace mojom
} // namespace shape_detection

#endif // SERVICES_SHAPE_DETECTION_PUBLIC_INTERFACES_TEXTDETECTION_MOJOM_SHARED_H_
