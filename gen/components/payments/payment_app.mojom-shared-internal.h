// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_PAYMENTS_PAYMENT_APP_MOJOM_SHARED_INTERNAL_H_
#define COMPONENTS_PAYMENTS_PAYMENT_APP_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "components/payments/payment_request.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "url/mojo/url.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace payments {
namespace mojom {
    namespace internal {
        class PaymentAppOption_Data;
        class PaymentAppManifest_Data;
        class PaymentAppRequestData_Data;

        struct PaymentAppManifestError_Data {
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
        class PaymentAppOption_Data {
        public:
            static PaymentAppOption_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PaymentAppOption_Data))) PaymentAppOption_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> name;
            mojo::internal::Pointer<mojo::internal::String_Data> icon;
            mojo::internal::Pointer<mojo::internal::String_Data> id;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<mojo::internal::String_Data>>> enabled_methods;

        private:
            PaymentAppOption_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PaymentAppOption_Data() = delete;
        };
        static_assert(sizeof(PaymentAppOption_Data) == 40,
            "Bad sizeof(PaymentAppOption_Data)");
        class PaymentAppManifest_Data {
        public:
            static PaymentAppManifest_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PaymentAppManifest_Data))) PaymentAppManifest_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> name;
            mojo::internal::Pointer<mojo::internal::String_Data> icon;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::PaymentAppOption_Data>>> options;

        private:
            PaymentAppManifest_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PaymentAppManifest_Data() = delete;
        };
        static_assert(sizeof(PaymentAppManifest_Data) == 32,
            "Bad sizeof(PaymentAppManifest_Data)");
        class PaymentAppRequestData_Data {
        public:
            static PaymentAppRequestData_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PaymentAppRequestData_Data))) PaymentAppRequestData_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::url::mojom::internal::Url_Data> origin;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::payments::mojom::internal::PaymentMethodData_Data>>> methodData;
            mojo::internal::Pointer<::payments::mojom::internal::PaymentItem_Data> total;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::payments::mojom::internal::PaymentDetailsModifier_Data>>> modifiers;
            mojo::internal::Pointer<mojo::internal::String_Data> optionId;

        private:
            PaymentAppRequestData_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PaymentAppRequestData_Data() = delete;
        };
        static_assert(sizeof(PaymentAppRequestData_Data) == 48,
            "Bad sizeof(PaymentAppRequestData_Data)");
        constexpr uint32_t kPaymentAppManager_Init_Name = 0;
        class PaymentAppManager_Init_Params_Data {
        public:
            static PaymentAppManager_Init_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PaymentAppManager_Init_Params_Data))) PaymentAppManager_Init_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> service_worker_scope;

        private:
            PaymentAppManager_Init_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PaymentAppManager_Init_Params_Data() = delete;
        };
        static_assert(sizeof(PaymentAppManager_Init_Params_Data) == 16,
            "Bad sizeof(PaymentAppManager_Init_Params_Data)");
        constexpr uint32_t kPaymentAppManager_SetManifest_Name = 1;
        class PaymentAppManager_SetManifest_Params_Data {
        public:
            static PaymentAppManager_SetManifest_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PaymentAppManager_SetManifest_Params_Data))) PaymentAppManager_SetManifest_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::PaymentAppManifest_Data> payment_app_manifest;

        private:
            PaymentAppManager_SetManifest_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PaymentAppManager_SetManifest_Params_Data() = delete;
        };
        static_assert(sizeof(PaymentAppManager_SetManifest_Params_Data) == 16,
            "Bad sizeof(PaymentAppManager_SetManifest_Params_Data)");
        class PaymentAppManager_SetManifest_ResponseParams_Data {
        public:
            static PaymentAppManager_SetManifest_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PaymentAppManager_SetManifest_ResponseParams_Data))) PaymentAppManager_SetManifest_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t error;
            uint8_t padfinal_[4];

        private:
            PaymentAppManager_SetManifest_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PaymentAppManager_SetManifest_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(PaymentAppManager_SetManifest_ResponseParams_Data) == 16,
            "Bad sizeof(PaymentAppManager_SetManifest_ResponseParams_Data)");
        constexpr uint32_t kPaymentAppManager_GetManifest_Name = 2;
        class PaymentAppManager_GetManifest_Params_Data {
        public:
            static PaymentAppManager_GetManifest_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PaymentAppManager_GetManifest_Params_Data))) PaymentAppManager_GetManifest_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            PaymentAppManager_GetManifest_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PaymentAppManager_GetManifest_Params_Data() = delete;
        };
        static_assert(sizeof(PaymentAppManager_GetManifest_Params_Data) == 8,
            "Bad sizeof(PaymentAppManager_GetManifest_Params_Data)");
        class PaymentAppManager_GetManifest_ResponseParams_Data {
        public:
            static PaymentAppManager_GetManifest_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PaymentAppManager_GetManifest_ResponseParams_Data))) PaymentAppManager_GetManifest_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::PaymentAppManifest_Data> payment_app_manifest;
            int32_t error;
            uint8_t padfinal_[4];

        private:
            PaymentAppManager_GetManifest_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PaymentAppManager_GetManifest_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(PaymentAppManager_GetManifest_ResponseParams_Data) == 24,
            "Bad sizeof(PaymentAppManager_GetManifest_ResponseParams_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace payments

#endif // COMPONENTS_PAYMENTS_PAYMENT_APP_MOJOM_SHARED_INTERNAL_H_