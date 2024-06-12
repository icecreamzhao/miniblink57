// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_VIBRATION_VIBRATION_MANAGER_MOJOM_SHARED_INTERNAL_H_
#define DEVICE_VIBRATION_VIBRATION_MANAGER_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

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
namespace device {
namespace internal {

#pragma pack(push, 1)
    constexpr uint32_t kVibrationManager_Vibrate_Name = 0;
    class VibrationManager_Vibrate_Params_Data {
    public:
        static VibrationManager_Vibrate_Params_Data* New(mojo::internal::Buffer* buf)
        {
            return new (buf->Allocate(sizeof(VibrationManager_Vibrate_Params_Data))) VibrationManager_Vibrate_Params_Data();
        }

        static bool Validate(const void* data,
            mojo::internal::ValidationContext* validation_context);

        mojo::internal::StructHeader header_;
        int64_t milliseconds;

    private:
        VibrationManager_Vibrate_Params_Data()
            : header_({ sizeof(*this), 0 })
        {
        }
        ~VibrationManager_Vibrate_Params_Data() = delete;
    };
    static_assert(sizeof(VibrationManager_Vibrate_Params_Data) == 16,
        "Bad sizeof(VibrationManager_Vibrate_Params_Data)");
    class VibrationManager_Vibrate_ResponseParams_Data {
    public:
        static VibrationManager_Vibrate_ResponseParams_Data* New(mojo::internal::Buffer* buf)
        {
            return new (buf->Allocate(sizeof(VibrationManager_Vibrate_ResponseParams_Data))) VibrationManager_Vibrate_ResponseParams_Data();
        }

        static bool Validate(const void* data,
            mojo::internal::ValidationContext* validation_context);

        mojo::internal::StructHeader header_;

    private:
        VibrationManager_Vibrate_ResponseParams_Data()
            : header_({ sizeof(*this), 0 })
        {
        }
        ~VibrationManager_Vibrate_ResponseParams_Data() = delete;
    };
    static_assert(sizeof(VibrationManager_Vibrate_ResponseParams_Data) == 8,
        "Bad sizeof(VibrationManager_Vibrate_ResponseParams_Data)");
    constexpr uint32_t kVibrationManager_Cancel_Name = 1;
    class VibrationManager_Cancel_Params_Data {
    public:
        static VibrationManager_Cancel_Params_Data* New(mojo::internal::Buffer* buf)
        {
            return new (buf->Allocate(sizeof(VibrationManager_Cancel_Params_Data))) VibrationManager_Cancel_Params_Data();
        }

        static bool Validate(const void* data,
            mojo::internal::ValidationContext* validation_context);

        mojo::internal::StructHeader header_;

    private:
        VibrationManager_Cancel_Params_Data()
            : header_({ sizeof(*this), 0 })
        {
        }
        ~VibrationManager_Cancel_Params_Data() = delete;
    };
    static_assert(sizeof(VibrationManager_Cancel_Params_Data) == 8,
        "Bad sizeof(VibrationManager_Cancel_Params_Data)");
    class VibrationManager_Cancel_ResponseParams_Data {
    public:
        static VibrationManager_Cancel_ResponseParams_Data* New(mojo::internal::Buffer* buf)
        {
            return new (buf->Allocate(sizeof(VibrationManager_Cancel_ResponseParams_Data))) VibrationManager_Cancel_ResponseParams_Data();
        }

        static bool Validate(const void* data,
            mojo::internal::ValidationContext* validation_context);

        mojo::internal::StructHeader header_;

    private:
        VibrationManager_Cancel_ResponseParams_Data()
            : header_({ sizeof(*this), 0 })
        {
        }
        ~VibrationManager_Cancel_ResponseParams_Data() = delete;
    };
    static_assert(sizeof(VibrationManager_Cancel_ResponseParams_Data) == 8,
        "Bad sizeof(VibrationManager_Cancel_ResponseParams_Data)");

#pragma pack(pop)

} // namespace internal
} // namespace device

#endif // DEVICE_VIBRATION_VIBRATION_MANAGER_MOJOM_SHARED_INTERNAL_H_