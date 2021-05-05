// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_SHAPE_DETECTION_PUBLIC_INTERFACES_FACEDETECTION_PROVIDER_MOJOM_SHARED_H_
#define SERVICES_SHAPE_DETECTION_PUBLIC_INTERFACES_FACEDETECTION_PROVIDER_MOJOM_SHARED_H_

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
#include "services/shape_detection/public/interfaces/facedetection.mojom-shared.h"
#include "services/shape_detection/public/interfaces/facedetection_provider.mojom-shared-internal.h"

namespace shape_detection {
namespace mojom {

} // namespace mojom
} // namespace shape_detection

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace shape_detection {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class FaceDetectionProviderInterfaceBase {
    };

    using FaceDetectionProviderPtrDataView = mojo::InterfacePtrDataView<FaceDetectionProviderInterfaceBase>;
    using FaceDetectionProviderRequestDataView = mojo::InterfaceRequestDataView<FaceDetectionProviderInterfaceBase>;
    using FaceDetectionProviderAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<FaceDetectionProviderInterfaceBase>;
    using FaceDetectionProviderAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<FaceDetectionProviderInterfaceBase>;
    class FaceDetectionProvider_CreateFaceDetection_ParamsDataView {
    public:
        FaceDetectionProvider_CreateFaceDetection_ParamsDataView() { }

        FaceDetectionProvider_CreateFaceDetection_ParamsDataView(
            internal::FaceDetectionProvider_CreateFaceDetection_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeRequest()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::shape_detection::mojom::FaceDetectionRequestDataView>(
                &data_->request, &result, context_);
            DCHECK(ret);
            return result;
        }
        inline void GetOptionsDataView(
            ::shape_detection::mojom::FaceDetectorOptionsDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOptions(UserType* output)
        {
            auto* pointer = data_->options.Get();
            return mojo::internal::Deserialize<::shape_detection::mojom::FaceDetectorOptionsDataView>(
                pointer, output, context_);
        }

    private:
        internal::FaceDetectionProvider_CreateFaceDetection_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace shape_detection

namespace std {

} // namespace std

namespace mojo {

} // namespace mojo

namespace shape_detection {
namespace mojom {

    inline void FaceDetectionProvider_CreateFaceDetection_ParamsDataView::GetOptionsDataView(
        ::shape_detection::mojom::FaceDetectorOptionsDataView* output)
    {
        auto pointer = data_->options.Get();
        *output = ::shape_detection::mojom::FaceDetectorOptionsDataView(pointer, context_);
    }

} // namespace mojom
} // namespace shape_detection

#endif // SERVICES_SHAPE_DETECTION_PUBLIC_INTERFACES_FACEDETECTION_PROVIDER_MOJOM_SHARED_H_
