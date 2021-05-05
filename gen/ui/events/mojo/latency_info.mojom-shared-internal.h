// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_EVENTS_MOJO_LATENCY_INFO_MOJOM_SHARED_INTERNAL_H_
#define UI_EVENTS_MOJO_LATENCY_INFO_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/common/time.mojom-shared-internal.h"
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
namespace ui {
namespace mojom {
    namespace internal {
        class LatencyComponentId_Data;
        class LatencyComponent_Data;
        class LatencyComponentPair_Data;
        class LatencyInfo_Data;

        struct LatencyComponentType_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 9:
                case 10:
                case 11:
                case 12:
                case 13:
                case 14:
                case 15:
                case 16:
                case 17:
                case 18:
                case 19:
                case 20:
                case 21:
                case 22:
                case 23:
                case 24:
                case 25:
                    return true;
                }
                return false;
            }

            static bool Validate(int32_t value,
                mojo::internal::ValidationContext* validation_context)
            {
                if (kIsExtensible || IsKnownValue(value))
                    return true;

                ReportValidationError(validation_context,
                    mojo::internal::VALIDATION_ERROR_UNKNOWN_ENUM_VALUE);
                return false;
            }
        };

#pragma pack(push, 1)
        class LatencyComponentId_Data {
        public:
            static LatencyComponentId_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LatencyComponentId_Data))) LatencyComponentId_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t type;
            uint8_t pad0_[4];
            int64_t id;

        private:
            LatencyComponentId_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LatencyComponentId_Data() = delete;
        };
        static_assert(sizeof(LatencyComponentId_Data) == 24,
            "Bad sizeof(LatencyComponentId_Data)");
        class LatencyComponent_Data {
        public:
            static LatencyComponent_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LatencyComponent_Data))) LatencyComponent_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t sequence_number;
            mojo::internal::Pointer<::mojo::common::mojom::internal::TimeTicks_Data> event_time;
            uint32_t event_count;
            uint8_t padfinal_[4];

        private:
            LatencyComponent_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LatencyComponent_Data() = delete;
        };
        static_assert(sizeof(LatencyComponent_Data) == 32,
            "Bad sizeof(LatencyComponent_Data)");
        class LatencyComponentPair_Data {
        public:
            static LatencyComponentPair_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LatencyComponentPair_Data))) LatencyComponentPair_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::LatencyComponentId_Data> key;
            mojo::internal::Pointer<internal::LatencyComponent_Data> value;

        private:
            LatencyComponentPair_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LatencyComponentPair_Data() = delete;
        };
        static_assert(sizeof(LatencyComponentPair_Data) == 24,
            "Bad sizeof(LatencyComponentPair_Data)");
        class LatencyInfo_Data {
        public:
            static LatencyInfo_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(LatencyInfo_Data))) LatencyInfo_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> trace_name;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::LatencyComponentPair_Data>>> latency_components;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::gfx::mojom::internal::PointF_Data>>> input_coordinates;
            int64_t trace_id;
            uint8_t coalesced : 1;
            uint8_t terminated : 1;
            uint8_t padfinal_[7];

        private:
            LatencyInfo_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~LatencyInfo_Data() = delete;
        };
        static_assert(sizeof(LatencyInfo_Data) == 48,
            "Bad sizeof(LatencyInfo_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace ui

#endif // UI_EVENTS_MOJO_LATENCY_INFO_MOJOM_SHARED_INTERNAL_H_