// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_SHAPE_DETECTION_PUBLIC_INTERFACES_FACEDETECTION_MOJOM_SHARED_H_
#define SERVICES_SHAPE_DETECTION_PUBLIC_INTERFACES_FACEDETECTION_MOJOM_SHARED_H_

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
#include "services/shape_detection/public/interfaces/facedetection.mojom-shared-internal.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared.h"

namespace shape_detection {
namespace mojom {
    class FaceDetectionResultDataView;

    class FaceDetectorOptionsDataView;

} // namespace mojom
} // namespace shape_detection

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::shape_detection::mojom::FaceDetectionResultDataView> {
        using Data = ::shape_detection::mojom::internal::FaceDetectionResult_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::shape_detection::mojom::FaceDetectorOptionsDataView> {
        using Data = ::shape_detection::mojom::internal::FaceDetectorOptions_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace shape_detection {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class FaceDetectionInterfaceBase {
    };

    using FaceDetectionPtrDataView = mojo::InterfacePtrDataView<FaceDetectionInterfaceBase>;
    using FaceDetectionRequestDataView = mojo::InterfaceRequestDataView<FaceDetectionInterfaceBase>;
    using FaceDetectionAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<FaceDetectionInterfaceBase>;
    using FaceDetectionAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<FaceDetectionInterfaceBase>;
    class FaceDetectionResultDataView {
    public:
        FaceDetectionResultDataView() { }

        FaceDetectionResultDataView(
            internal::FaceDetectionResult_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetBoundingBoxesDataView(
            mojo::ArrayDataView<::gfx::mojom::RectFDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadBoundingBoxes(UserType* output)
        {
            auto* pointer = data_->bounding_boxes.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::gfx::mojom::RectFDataView>>(
                pointer, output, context_);
        }

    private:
        internal::FaceDetectionResult_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class FaceDetectorOptionsDataView {
    public:
        FaceDetectorOptionsDataView() { }

        FaceDetectorOptionsDataView(
            internal::FaceDetectorOptions_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t max_detected_faces() const
        {
            return data_->max_detected_faces;
        }
        bool fast_mode() const
        {
            return data_->fast_mode;
        }

    private:
        internal::FaceDetectorOptions_Data* data_ = nullptr;
    };

    class FaceDetection_Detect_ParamsDataView {
    public:
        FaceDetection_Detect_ParamsDataView() { }

        FaceDetection_Detect_ParamsDataView(
            internal::FaceDetection_Detect_Params_Data* data,
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
        internal::FaceDetection_Detect_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class FaceDetection_Detect_ResponseParamsDataView {
    public:
        FaceDetection_Detect_ResponseParamsDataView() { }

        FaceDetection_Detect_ResponseParamsDataView(
            internal::FaceDetection_Detect_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetResultDataView(
            FaceDetectionResultDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadResult(UserType* output)
        {
            auto* pointer = data_->result.Get();
            return mojo::internal::Deserialize<::shape_detection::mojom::FaceDetectionResultDataView>(
                pointer, output, context_);
        }

    private:
        internal::FaceDetection_Detect_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace shape_detection

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::shape_detection::mojom::FaceDetectionResultDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::shape_detection::mojom::FaceDetectionResultDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::shape_detection::mojom::internal::FaceDetectionResult_Data);
            decltype(CallWithContext(Traits::bounding_boxes, input, custom_context)) in_bounding_boxes = CallWithContext(Traits::bounding_boxes, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::gfx::mojom::RectFDataView>>(
                in_bounding_boxes, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::shape_detection::mojom::internal::FaceDetectionResult_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::shape_detection::mojom::internal::FaceDetectionResult_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::bounding_boxes, input, custom_context)) in_bounding_boxes = CallWithContext(Traits::bounding_boxes, input, custom_context);
            typename decltype(result->bounding_boxes)::BaseType* bounding_boxes_ptr;
            const mojo::internal::ContainerValidateParams bounding_boxes_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::gfx::mojom::RectFDataView>>(
                in_bounding_boxes, buffer, &bounding_boxes_ptr, &bounding_boxes_validate_params,
                context);
            result->bounding_boxes.Set(bounding_boxes_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->bounding_boxes.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null bounding_boxes in FaceDetectionResult struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::shape_detection::mojom::internal::FaceDetectionResult_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::shape_detection::mojom::FaceDetectionResultDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::shape_detection::mojom::FaceDetectorOptionsDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::shape_detection::mojom::FaceDetectorOptionsDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::shape_detection::mojom::internal::FaceDetectorOptions_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::shape_detection::mojom::internal::FaceDetectorOptions_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::shape_detection::mojom::internal::FaceDetectorOptions_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->max_detected_faces = CallWithContext(Traits::max_detected_faces, input, custom_context);
            result->fast_mode = CallWithContext(Traits::fast_mode, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::shape_detection::mojom::internal::FaceDetectorOptions_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::shape_detection::mojom::FaceDetectorOptionsDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace shape_detection {
namespace mojom {

    inline void FaceDetectionResultDataView::GetBoundingBoxesDataView(
        mojo::ArrayDataView<::gfx::mojom::RectFDataView>* output)
    {
        auto pointer = data_->bounding_boxes.Get();
        *output = mojo::ArrayDataView<::gfx::mojom::RectFDataView>(pointer, context_);
    }

    inline void FaceDetection_Detect_ResponseParamsDataView::GetResultDataView(
        FaceDetectionResultDataView* output)
    {
        auto pointer = data_->result.Get();
        *output = FaceDetectionResultDataView(pointer, context_);
    }

} // namespace mojom
} // namespace shape_detection

#endif // SERVICES_SHAPE_DETECTION_PUBLIC_INTERFACES_FACEDETECTION_MOJOM_SHARED_H_
