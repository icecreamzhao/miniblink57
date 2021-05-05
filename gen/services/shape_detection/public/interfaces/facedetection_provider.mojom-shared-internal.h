// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_SHAPE_DETECTION_PUBLIC_INTERFACES_FACEDETECTION_PROVIDER_MOJOM_SHARED_INTERNAL_H_
#define SERVICES_SHAPE_DETECTION_PUBLIC_INTERFACES_FACEDETECTION_PROVIDER_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "services/shape_detection/public/interfaces/facedetection.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace shape_detection {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kFaceDetectionProvider_CreateFaceDetection_Name = 0;
        class FaceDetectionProvider_CreateFaceDetection_Params_Data {
        public:
            static FaceDetectionProvider_CreateFaceDetection_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(FaceDetectionProvider_CreateFaceDetection_Params_Data))) FaceDetectionProvider_CreateFaceDetection_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data request;
            uint8_t pad0_[4];
            mojo::internal::Pointer<::shape_detection::mojom::internal::FaceDetectorOptions_Data> options;

        private:
            FaceDetectionProvider_CreateFaceDetection_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~FaceDetectionProvider_CreateFaceDetection_Params_Data() = delete;
        };
        static_assert(sizeof(FaceDetectionProvider_CreateFaceDetection_Params_Data) == 24,
            "Bad sizeof(FaceDetectionProvider_CreateFaceDetection_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace shape_detection

#endif // SERVICES_SHAPE_DETECTION_PUBLIC_INTERFACES_FACEDETECTION_PROVIDER_MOJOM_SHARED_INTERNAL_H_