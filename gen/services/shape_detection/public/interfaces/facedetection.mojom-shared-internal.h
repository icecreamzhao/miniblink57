// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_SHAPE_DETECTION_PUBLIC_INTERFACES_FACEDETECTION_MOJOM_SHARED_INTERNAL_H_
#define SERVICES_SHAPE_DETECTION_PUBLIC_INTERFACES_FACEDETECTION_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace shape_detection {
namespace mojom {
    namespace internal {
        class FaceDetectionResult_Data;
        class FaceDetectorOptions_Data;

#pragma pack(push, 1)
        class FaceDetectionResult_Data {
        public:
            static FaceDetectionResult_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(FaceDetectionResult_Data))) FaceDetectionResult_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::gfx::mojom::internal::RectF_Data>>> bounding_boxes;

        private:
            FaceDetectionResult_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~FaceDetectionResult_Data() = delete;
        };
        static_assert(sizeof(FaceDetectionResult_Data) == 16,
            "Bad sizeof(FaceDetectionResult_Data)");
        class FaceDetectorOptions_Data {
        public:
            static FaceDetectorOptions_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(FaceDetectorOptions_Data))) FaceDetectorOptions_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t max_detected_faces;
            uint8_t fast_mode : 1;
            uint8_t padfinal_[3];

        private:
            FaceDetectorOptions_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~FaceDetectorOptions_Data() = delete;
        };
        static_assert(sizeof(FaceDetectorOptions_Data) == 16,
            "Bad sizeof(FaceDetectorOptions_Data)");
        constexpr uint32_t kFaceDetection_Detect_Name = 0;
        class FaceDetection_Detect_Params_Data {
        public:
            static FaceDetection_Detect_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(FaceDetection_Detect_Params_Data))) FaceDetection_Detect_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data frame_data;
            uint32_t width;
            uint32_t height;
            uint8_t padfinal_[4];

        private:
            FaceDetection_Detect_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~FaceDetection_Detect_Params_Data() = delete;
        };
        static_assert(sizeof(FaceDetection_Detect_Params_Data) == 24,
            "Bad sizeof(FaceDetection_Detect_Params_Data)");
        class FaceDetection_Detect_ResponseParams_Data {
        public:
            static FaceDetection_Detect_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(FaceDetection_Detect_ResponseParams_Data))) FaceDetection_Detect_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::FaceDetectionResult_Data> result;

        private:
            FaceDetection_Detect_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~FaceDetection_Detect_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(FaceDetection_Detect_ResponseParams_Data) == 16,
            "Bad sizeof(FaceDetection_Detect_ResponseParams_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace shape_detection

#endif // SERVICES_SHAPE_DETECTION_PUBLIC_INTERFACES_FACEDETECTION_MOJOM_SHARED_INTERNAL_H_