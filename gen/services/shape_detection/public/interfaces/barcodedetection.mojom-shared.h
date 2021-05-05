// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_SHAPE_DETECTION_PUBLIC_INTERFACES_BARCODEDETECTION_MOJOM_SHARED_H_
#define SERVICES_SHAPE_DETECTION_PUBLIC_INTERFACES_BARCODEDETECTION_MOJOM_SHARED_H_

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
#include "services/shape_detection/public/interfaces/barcodedetection.mojom-shared-internal.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared.h"

namespace shape_detection {
namespace mojom {
    class BarcodeDetectionResultDataView;

} // namespace mojom
} // namespace shape_detection

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::shape_detection::mojom::BarcodeDetectionResultDataView> {
        using Data = ::shape_detection::mojom::internal::BarcodeDetectionResult_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace shape_detection {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class BarcodeDetectionInterfaceBase {
    };

    using BarcodeDetectionPtrDataView = mojo::InterfacePtrDataView<BarcodeDetectionInterfaceBase>;
    using BarcodeDetectionRequestDataView = mojo::InterfaceRequestDataView<BarcodeDetectionInterfaceBase>;
    using BarcodeDetectionAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<BarcodeDetectionInterfaceBase>;
    using BarcodeDetectionAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<BarcodeDetectionInterfaceBase>;
    class BarcodeDetectionResultDataView {
    public:
        BarcodeDetectionResultDataView() { }

        BarcodeDetectionResultDataView(
            internal::BarcodeDetectionResult_Data* data,
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
        inline void GetCornerPointsDataView(
            mojo::ArrayDataView<::gfx::mojom::PointFDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadCornerPoints(UserType* output)
        {
            auto* pointer = data_->corner_points.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::gfx::mojom::PointFDataView>>(
                pointer, output, context_);
        }

    private:
        internal::BarcodeDetectionResult_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class BarcodeDetection_Detect_ParamsDataView {
    public:
        BarcodeDetection_Detect_ParamsDataView() { }

        BarcodeDetection_Detect_ParamsDataView(
            internal::BarcodeDetection_Detect_Params_Data* data,
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
        internal::BarcodeDetection_Detect_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class BarcodeDetection_Detect_ResponseParamsDataView {
    public:
        BarcodeDetection_Detect_ResponseParamsDataView() { }

        BarcodeDetection_Detect_ResponseParamsDataView(
            internal::BarcodeDetection_Detect_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetResultsDataView(
            mojo::ArrayDataView<BarcodeDetectionResultDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadResults(UserType* output)
        {
            auto* pointer = data_->results.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::shape_detection::mojom::BarcodeDetectionResultDataView>>(
                pointer, output, context_);
        }

    private:
        internal::BarcodeDetection_Detect_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace shape_detection

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::shape_detection::mojom::BarcodeDetectionResultDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::shape_detection::mojom::BarcodeDetectionResultDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::shape_detection::mojom::internal::BarcodeDetectionResult_Data);
            decltype(CallWithContext(Traits::raw_value, input, custom_context)) in_raw_value = CallWithContext(Traits::raw_value, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_raw_value, context);
            decltype(CallWithContext(Traits::bounding_box, input, custom_context)) in_bounding_box = CallWithContext(Traits::bounding_box, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::RectFDataView>(
                in_bounding_box, context);
            decltype(CallWithContext(Traits::corner_points, input, custom_context)) in_corner_points = CallWithContext(Traits::corner_points, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::gfx::mojom::PointFDataView>>(
                in_corner_points, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::shape_detection::mojom::internal::BarcodeDetectionResult_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::shape_detection::mojom::internal::BarcodeDetectionResult_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::raw_value, input, custom_context)) in_raw_value = CallWithContext(Traits::raw_value, input, custom_context);
            typename decltype(result->raw_value)::BaseType* raw_value_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_raw_value, buffer, &raw_value_ptr, context);
            result->raw_value.Set(raw_value_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->raw_value.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null raw_value in BarcodeDetectionResult struct");
            decltype(CallWithContext(Traits::bounding_box, input, custom_context)) in_bounding_box = CallWithContext(Traits::bounding_box, input, custom_context);
            typename decltype(result->bounding_box)::BaseType* bounding_box_ptr;
            mojo::internal::Serialize<::gfx::mojom::RectFDataView>(
                in_bounding_box, buffer, &bounding_box_ptr, context);
            result->bounding_box.Set(bounding_box_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->bounding_box.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null bounding_box in BarcodeDetectionResult struct");
            decltype(CallWithContext(Traits::corner_points, input, custom_context)) in_corner_points = CallWithContext(Traits::corner_points, input, custom_context);
            typename decltype(result->corner_points)::BaseType* corner_points_ptr;
            const mojo::internal::ContainerValidateParams corner_points_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::gfx::mojom::PointFDataView>>(
                in_corner_points, buffer, &corner_points_ptr, &corner_points_validate_params,
                context);
            result->corner_points.Set(corner_points_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->corner_points.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null corner_points in BarcodeDetectionResult struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::shape_detection::mojom::internal::BarcodeDetectionResult_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::shape_detection::mojom::BarcodeDetectionResultDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace shape_detection {
namespace mojom {

    inline void BarcodeDetectionResultDataView::GetRawValueDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->raw_value.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void BarcodeDetectionResultDataView::GetBoundingBoxDataView(
        ::gfx::mojom::RectFDataView* output)
    {
        auto pointer = data_->bounding_box.Get();
        *output = ::gfx::mojom::RectFDataView(pointer, context_);
    }
    inline void BarcodeDetectionResultDataView::GetCornerPointsDataView(
        mojo::ArrayDataView<::gfx::mojom::PointFDataView>* output)
    {
        auto pointer = data_->corner_points.Get();
        *output = mojo::ArrayDataView<::gfx::mojom::PointFDataView>(pointer, context_);
    }

    inline void BarcodeDetection_Detect_ResponseParamsDataView::GetResultsDataView(
        mojo::ArrayDataView<BarcodeDetectionResultDataView>* output)
    {
        auto pointer = data_->results.Get();
        *output = mojo::ArrayDataView<BarcodeDetectionResultDataView>(pointer, context_);
    }

} // namespace mojom
} // namespace shape_detection

#endif // SERVICES_SHAPE_DETECTION_PUBLIC_INTERFACES_BARCODEDETECTION_MOJOM_SHARED_H_
