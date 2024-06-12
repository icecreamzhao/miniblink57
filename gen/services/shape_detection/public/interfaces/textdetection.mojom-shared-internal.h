// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_SHAPE_DETECTION_PUBLIC_INTERFACES_TEXTDETECTION_MOJOM_SHARED_INTERNAL_H_
#define SERVICES_SHAPE_DETECTION_PUBLIC_INTERFACES_TEXTDETECTION_MOJOM_SHARED_INTERNAL_H_

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
        class TextDetectionResult_Data;

#pragma pack(push, 1)
        class TextDetectionResult_Data {
        public:
            static TextDetectionResult_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(TextDetectionResult_Data))) TextDetectionResult_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> raw_value;
            mojo::internal::Pointer<::gfx::mojom::internal::RectF_Data> bounding_box;

        private:
            TextDetectionResult_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~TextDetectionResult_Data() = delete;
        };
        static_assert(sizeof(TextDetectionResult_Data) == 24,
            "Bad sizeof(TextDetectionResult_Data)");
        constexpr uint32_t kTextDetection_Detect_Name = 0;
        class TextDetection_Detect_Params_Data {
        public:
            static TextDetection_Detect_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(TextDetection_Detect_Params_Data))) TextDetection_Detect_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data frame_data;
            uint32_t width;
            uint32_t height;
            uint8_t padfinal_[4];

        private:
            TextDetection_Detect_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~TextDetection_Detect_Params_Data() = delete;
        };
        static_assert(sizeof(TextDetection_Detect_Params_Data) == 24,
            "Bad sizeof(TextDetection_Detect_Params_Data)");
        class TextDetection_Detect_ResponseParams_Data {
        public:
            static TextDetection_Detect_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(TextDetection_Detect_ResponseParams_Data))) TextDetection_Detect_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::TextDetectionResult_Data>>> results;

        private:
            TextDetection_Detect_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~TextDetection_Detect_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(TextDetection_Detect_ResponseParams_Data) == 16,
            "Bad sizeof(TextDetection_Detect_ResponseParams_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace shape_detection

#endif // SERVICES_SHAPE_DETECTION_PUBLIC_INTERFACES_TEXTDETECTION_MOJOM_SHARED_INTERNAL_H_