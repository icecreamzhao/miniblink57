// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_BEGIN_FRAME_ARGS_MOJOM_SHARED_INTERNAL_H_
#define CC_IPC_BEGIN_FRAME_ARGS_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/common/time.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace cc {
namespace mojom {
    namespace internal {
        class BeginFrameArgs_Data;

        struct BeginFrameArgsType_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                case 2:
                case 3:
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
        class BeginFrameArgs_Data {
        public:
            static BeginFrameArgs_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(BeginFrameArgs_Data))) BeginFrameArgs_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::mojo::common::mojom::internal::TimeTicks_Data> frame_time;
            mojo::internal::Pointer<::mojo::common::mojom::internal::TimeTicks_Data> deadline;
            mojo::internal::Pointer<::mojo::common::mojom::internal::TimeDelta_Data> interval;
            uint64_t sequence_number;
            uint32_t source_id;
            int32_t type;
            uint8_t on_critical_path : 1;
            uint8_t padfinal_[7];

        private:
            BeginFrameArgs_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~BeginFrameArgs_Data() = delete;
        };
        static_assert(sizeof(BeginFrameArgs_Data) == 56,
            "Bad sizeof(BeginFrameArgs_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace cc

#endif // CC_IPC_BEGIN_FRAME_ARGS_MOJOM_SHARED_INTERNAL_H_