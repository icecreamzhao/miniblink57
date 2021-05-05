// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_SCREEN_ORIENTATION_PUBLIC_INTERFACES_SCREEN_ORIENTATION_MOJOM_SHARED_INTERNAL_H_
#define DEVICE_SCREEN_ORIENTATION_PUBLIC_INTERFACES_SCREEN_ORIENTATION_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "device/screen_orientation/public/interfaces/screen_orientation_lock_types.mojom-shared-internal.h"
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
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kScreenOrientation_LockOrientation_Name = 0;
        class ScreenOrientation_LockOrientation_Params_Data {
        public:
            static ScreenOrientation_LockOrientation_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ScreenOrientation_LockOrientation_Params_Data))) ScreenOrientation_LockOrientation_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t orientation;
            uint8_t padfinal_[4];

        private:
            ScreenOrientation_LockOrientation_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ScreenOrientation_LockOrientation_Params_Data() = delete;
        };
        static_assert(sizeof(ScreenOrientation_LockOrientation_Params_Data) == 16,
            "Bad sizeof(ScreenOrientation_LockOrientation_Params_Data)");
        class ScreenOrientation_LockOrientation_ResponseParams_Data {
        public:
            static ScreenOrientation_LockOrientation_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ScreenOrientation_LockOrientation_ResponseParams_Data))) ScreenOrientation_LockOrientation_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t result;
            uint8_t padfinal_[4];

        private:
            ScreenOrientation_LockOrientation_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ScreenOrientation_LockOrientation_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(ScreenOrientation_LockOrientation_ResponseParams_Data) == 16,
            "Bad sizeof(ScreenOrientation_LockOrientation_ResponseParams_Data)");
        constexpr uint32_t kScreenOrientation_UnlockOrientation_Name = 1;
        class ScreenOrientation_UnlockOrientation_Params_Data {
        public:
            static ScreenOrientation_UnlockOrientation_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ScreenOrientation_UnlockOrientation_Params_Data))) ScreenOrientation_UnlockOrientation_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            ScreenOrientation_UnlockOrientation_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ScreenOrientation_UnlockOrientation_Params_Data() = delete;
        };
        static_assert(sizeof(ScreenOrientation_UnlockOrientation_Params_Data) == 8,
            "Bad sizeof(ScreenOrientation_UnlockOrientation_Params_Data)");
        constexpr uint32_t kScreenOrientationListener_Start_Name = 0;
        class ScreenOrientationListener_Start_Params_Data {
        public:
            static ScreenOrientationListener_Start_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ScreenOrientationListener_Start_Params_Data))) ScreenOrientationListener_Start_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            ScreenOrientationListener_Start_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ScreenOrientationListener_Start_Params_Data() = delete;
        };
        static_assert(sizeof(ScreenOrientationListener_Start_Params_Data) == 8,
            "Bad sizeof(ScreenOrientationListener_Start_Params_Data)");
        constexpr uint32_t kScreenOrientationListener_Stop_Name = 1;
        class ScreenOrientationListener_Stop_Params_Data {
        public:
            static ScreenOrientationListener_Stop_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ScreenOrientationListener_Stop_Params_Data))) ScreenOrientationListener_Stop_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            ScreenOrientationListener_Stop_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ScreenOrientationListener_Stop_Params_Data() = delete;
        };
        static_assert(sizeof(ScreenOrientationListener_Stop_Params_Data) == 8,
            "Bad sizeof(ScreenOrientationListener_Stop_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace device

#endif // DEVICE_SCREEN_ORIENTATION_PUBLIC_INTERFACES_SCREEN_ORIENTATION_MOJOM_SHARED_INTERNAL_H_