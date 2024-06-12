// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_BACKGROUND_SYNC_BACKGROUND_SYNC_MOJOM_SHARED_INTERNAL_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_BACKGROUND_SYNC_BACKGROUND_SYNC_MOJOM_SHARED_INTERNAL_H_

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
namespace blink {
namespace mojom {
    namespace internal {
        class SyncRegistration_Data;

        struct BackgroundSyncNetworkState_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                case 2:
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

        struct BackgroundSyncError_Data {
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

        struct BackgroundSyncState_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                case 2:
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

        struct BackgroundSyncEventLastChance_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
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
        class SyncRegistration_Data {
        public:
            static SyncRegistration_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(SyncRegistration_Data))) SyncRegistration_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t id;
            mojo::internal::Pointer<mojo::internal::String_Data> tag;
            int32_t network_state;
            uint8_t padfinal_[4];

        private:
            SyncRegistration_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~SyncRegistration_Data() = delete;
        };
        static_assert(sizeof(SyncRegistration_Data) == 32,
            "Bad sizeof(SyncRegistration_Data)");
        constexpr uint32_t kBackgroundSyncService_Register_Name = 0;
        class BackgroundSyncService_Register_Params_Data {
        public:
            static BackgroundSyncService_Register_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(BackgroundSyncService_Register_Params_Data))) BackgroundSyncService_Register_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::SyncRegistration_Data> options;
            int64_t service_worker_registration_id;

        private:
            BackgroundSyncService_Register_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~BackgroundSyncService_Register_Params_Data() = delete;
        };
        static_assert(sizeof(BackgroundSyncService_Register_Params_Data) == 24,
            "Bad sizeof(BackgroundSyncService_Register_Params_Data)");
        class BackgroundSyncService_Register_ResponseParams_Data {
        public:
            static BackgroundSyncService_Register_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(BackgroundSyncService_Register_ResponseParams_Data))) BackgroundSyncService_Register_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t err;
            uint8_t pad0_[4];
            mojo::internal::Pointer<internal::SyncRegistration_Data> options;

        private:
            BackgroundSyncService_Register_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~BackgroundSyncService_Register_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(BackgroundSyncService_Register_ResponseParams_Data) == 24,
            "Bad sizeof(BackgroundSyncService_Register_ResponseParams_Data)");
        constexpr uint32_t kBackgroundSyncService_GetRegistrations_Name = 1;
        class BackgroundSyncService_GetRegistrations_Params_Data {
        public:
            static BackgroundSyncService_GetRegistrations_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(BackgroundSyncService_GetRegistrations_Params_Data))) BackgroundSyncService_GetRegistrations_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t service_worker_registration_id;

        private:
            BackgroundSyncService_GetRegistrations_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~BackgroundSyncService_GetRegistrations_Params_Data() = delete;
        };
        static_assert(sizeof(BackgroundSyncService_GetRegistrations_Params_Data) == 16,
            "Bad sizeof(BackgroundSyncService_GetRegistrations_Params_Data)");
        class BackgroundSyncService_GetRegistrations_ResponseParams_Data {
        public:
            static BackgroundSyncService_GetRegistrations_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(BackgroundSyncService_GetRegistrations_ResponseParams_Data))) BackgroundSyncService_GetRegistrations_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t err;
            uint8_t pad0_[4];
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::SyncRegistration_Data>>> registrations;

        private:
            BackgroundSyncService_GetRegistrations_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~BackgroundSyncService_GetRegistrations_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(BackgroundSyncService_GetRegistrations_ResponseParams_Data) == 24,
            "Bad sizeof(BackgroundSyncService_GetRegistrations_ResponseParams_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace blink

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_BACKGROUND_SYNC_BACKGROUND_SYNC_MOJOM_SHARED_INTERNAL_H_