// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_SHAPE_DETECTION_PUBLIC_INTERFACES_BARCODEDETECTION_MOJOM_SHARED_INTERNAL_H_
#define SERVICES_SHAPE_DETECTION_PUBLIC_INTERFACES_BARCODEDETECTION_MOJOM_SHARED_INTERNAL_H_

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
        class BarcodeDetectionResult_Data;

#pragma pack(push, 1)
        class BarcodeDetectionResult_Data {
        public:
            static BarcodeDetectionResult_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(BarcodeDetectionResult_Data))) BarcodeDetectionResult_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> raw_value;
            mojo::internal::Pointer<::gfx::mojom::internal::RectF_Data> bounding_box;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::gfx::mojom::internal::PointF_Data>>> corner_points;

        private:
            BarcodeDetectionResult_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~BarcodeDetectionResult_Data() = delete;
        };
        static_assert(sizeof(BarcodeDetectionResult_Data) == 32,
            "Bad sizeof(BarcodeDetectionResult_Data)");
        constexpr uint32_t kBarcodeDetection_Detect_Name = 0;
        class BarcodeDetection_Detect_Params_Data {
        public:
            static BarcodeDetection_Detect_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(BarcodeDetection_Detect_Params_Data))) BarcodeDetection_Detect_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data frame_data;
            uint32_t width;
            uint32_t height;
            uint8_t padfinal_[4];

        private:
            BarcodeDetection_Detect_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~BarcodeDetection_Detect_Params_Data() = delete;
        };
        static_assert(sizeof(BarcodeDetection_Detect_Params_Data) == 24,
            "Bad sizeof(BarcodeDetection_Detect_Params_Data)");
        class BarcodeDetection_Detect_ResponseParams_Data {
        public:
            static BarcodeDetection_Detect_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(BarcodeDetection_Detect_ResponseParams_Data))) BarcodeDetection_Detect_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::BarcodeDetectionResult_Data>>> results;

        private:
            BarcodeDetection_Detect_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~BarcodeDetection_Detect_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(BarcodeDetection_Detect_ResponseParams_Data) == 16,
            "Bad sizeof(BarcodeDetection_Detect_ResponseParams_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace shape_detection

#endif // SERVICES_SHAPE_DETECTION_PUBLIC_INTERFACES_BARCODEDETECTION_MOJOM_SHARED_INTERNAL_H_