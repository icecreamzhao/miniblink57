// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_PAYMENTS_PAYMENT_REQUEST_MOJOM_SHARED_INTERNAL_H_
#define COMPONENTS_PAYMENTS_PAYMENT_REQUEST_MOJOM_SHARED_INTERNAL_H_

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
namespace payments {
namespace mojom {
    namespace internal {
        class PaymentAddress_Data;
        class PaymentCurrencyAmount_Data;
        class PaymentResponse_Data;
        class PaymentItem_Data;
        class PaymentShippingOption_Data;
        class AndroidPayTokenizationParameter_Data;
        class PaymentMethodData_Data;
        class PaymentDetailsModifier_Data;
        class PaymentDetails_Data;
        class PaymentOptions_Data;

        struct PaymentErrorReason_Data {
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

        struct CanMakePaymentQueryResult_Data {
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

        struct AndroidPayEnvironment_Data {
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

        struct AndroidPayCardNetwork_Data {
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

        struct AndroidPayTokenization_Data {
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

        struct BasicCardNetwork_Data {
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

        struct BasicCardType_Data {
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

        struct PaymentShippingType_Data {
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

        struct PaymentComplete_Data {
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

#pragma pack(push, 1)
        class PaymentAddress_Data {
        public:
            static PaymentAddress_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PaymentAddress_Data))) PaymentAddress_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> country;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<mojo::internal::String_Data>>> address_line;
            mojo::internal::Pointer<mojo::internal::String_Data> region;
            mojo::internal::Pointer<mojo::internal::String_Data> city;
            mojo::internal::Pointer<mojo::internal::String_Data> dependent_locality;
            mojo::internal::Pointer<mojo::internal::String_Data> postal_code;
            mojo::internal::Pointer<mojo::internal::String_Data> sorting_code;
            mojo::internal::Pointer<mojo::internal::String_Data> language_code;
            mojo::internal::Pointer<mojo::internal::String_Data> script_code;
            mojo::internal::Pointer<mojo::internal::String_Data> organization;
            mojo::internal::Pointer<mojo::internal::String_Data> recipient;
            mojo::internal::Pointer<mojo::internal::String_Data> phone;

        private:
            PaymentAddress_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PaymentAddress_Data() = delete;
        };
        static_assert(sizeof(PaymentAddress_Data) == 104,
            "Bad sizeof(PaymentAddress_Data)");
        class PaymentCurrencyAmount_Data {
        public:
            static PaymentCurrencyAmount_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PaymentCurrencyAmount_Data))) PaymentCurrencyAmount_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> currency;
            mojo::internal::Pointer<mojo::internal::String_Data> value;
            mojo::internal::Pointer<mojo::internal::String_Data> currency_system;

        private:
            PaymentCurrencyAmount_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PaymentCurrencyAmount_Data() = delete;
        };
        static_assert(sizeof(PaymentCurrencyAmount_Data) == 32,
            "Bad sizeof(PaymentCurrencyAmount_Data)");
        class PaymentResponse_Data {
        public:
            static PaymentResponse_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PaymentResponse_Data))) PaymentResponse_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> method_name;
            mojo::internal::Pointer<mojo::internal::String_Data> stringified_details;
            mojo::internal::Pointer<internal::PaymentAddress_Data> shipping_address;
            mojo::internal::Pointer<mojo::internal::String_Data> shipping_option;
            mojo::internal::Pointer<mojo::internal::String_Data> payer_name;
            mojo::internal::Pointer<mojo::internal::String_Data> payer_email;
            mojo::internal::Pointer<mojo::internal::String_Data> payer_phone;

        private:
            PaymentResponse_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PaymentResponse_Data() = delete;
        };
        static_assert(sizeof(PaymentResponse_Data) == 64,
            "Bad sizeof(PaymentResponse_Data)");
        class PaymentItem_Data {
        public:
            static PaymentItem_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PaymentItem_Data))) PaymentItem_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> label;
            mojo::internal::Pointer<internal::PaymentCurrencyAmount_Data> amount;
            uint8_t pending : 1;
            uint8_t padfinal_[7];

        private:
            PaymentItem_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PaymentItem_Data() = delete;
        };
        static_assert(sizeof(PaymentItem_Data) == 32,
            "Bad sizeof(PaymentItem_Data)");
        class PaymentShippingOption_Data {
        public:
            static PaymentShippingOption_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PaymentShippingOption_Data))) PaymentShippingOption_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> id;
            mojo::internal::Pointer<mojo::internal::String_Data> label;
            mojo::internal::Pointer<internal::PaymentCurrencyAmount_Data> amount;
            uint8_t selected : 1;
            uint8_t padfinal_[7];

        private:
            PaymentShippingOption_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PaymentShippingOption_Data() = delete;
        };
        static_assert(sizeof(PaymentShippingOption_Data) == 40,
            "Bad sizeof(PaymentShippingOption_Data)");
        class AndroidPayTokenizationParameter_Data {
        public:
            static AndroidPayTokenizationParameter_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AndroidPayTokenizationParameter_Data))) AndroidPayTokenizationParameter_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> key;
            mojo::internal::Pointer<mojo::internal::String_Data> value;

        private:
            AndroidPayTokenizationParameter_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AndroidPayTokenizationParameter_Data() = delete;
        };
        static_assert(sizeof(AndroidPayTokenizationParameter_Data) == 24,
            "Bad sizeof(AndroidPayTokenizationParameter_Data)");
        class PaymentMethodData_Data {
        public:
            static PaymentMethodData_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PaymentMethodData_Data))) PaymentMethodData_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<mojo::internal::String_Data>>> supported_methods;
            mojo::internal::Pointer<mojo::internal::String_Data> stringified_data;
            int32_t environment;
            int32_t tokenization_type;
            mojo::internal::Pointer<mojo::internal::String_Data> merchant_name;
            mojo::internal::Pointer<mojo::internal::String_Data> merchant_id;
            mojo::internal::Pointer<mojo::internal::Array_Data<int32_t>> allowed_card_networks;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::AndroidPayTokenizationParameter_Data>>> parameters;
            int32_t min_google_play_services_version;
            uint8_t pad8_[4];
            mojo::internal::Pointer<mojo::internal::Array_Data<int32_t>> supported_networks;
            mojo::internal::Pointer<mojo::internal::Array_Data<int32_t>> supported_types;

        private:
            PaymentMethodData_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PaymentMethodData_Data() = delete;
        };
        static_assert(sizeof(PaymentMethodData_Data) == 88,
            "Bad sizeof(PaymentMethodData_Data)");
        class PaymentDetailsModifier_Data {
        public:
            static PaymentDetailsModifier_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PaymentDetailsModifier_Data))) PaymentDetailsModifier_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::PaymentItem_Data> total;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::PaymentItem_Data>>> additional_display_items;
            mojo::internal::Pointer<internal::PaymentMethodData_Data> method_data;

        private:
            PaymentDetailsModifier_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PaymentDetailsModifier_Data() = delete;
        };
        static_assert(sizeof(PaymentDetailsModifier_Data) == 32,
            "Bad sizeof(PaymentDetailsModifier_Data)");
        class PaymentDetails_Data {
        public:
            static PaymentDetails_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PaymentDetails_Data))) PaymentDetails_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::PaymentItem_Data> total;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::PaymentItem_Data>>> display_items;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::PaymentShippingOption_Data>>> shipping_options;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::PaymentDetailsModifier_Data>>> modifiers;
            mojo::internal::Pointer<mojo::internal::String_Data> error;

        private:
            PaymentDetails_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PaymentDetails_Data() = delete;
        };
        static_assert(sizeof(PaymentDetails_Data) == 48,
            "Bad sizeof(PaymentDetails_Data)");
        class PaymentOptions_Data {
        public:
            static PaymentOptions_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PaymentOptions_Data))) PaymentOptions_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t request_payer_name : 1;
            uint8_t request_payer_email : 1;
            uint8_t request_payer_phone : 1;
            uint8_t request_shipping : 1;
            uint8_t pad3_[3];
            int32_t shipping_type;

        private:
            PaymentOptions_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PaymentOptions_Data() = delete;
        };
        static_assert(sizeof(PaymentOptions_Data) == 16,
            "Bad sizeof(PaymentOptions_Data)");
        constexpr uint32_t kPaymentRequestClient_OnShippingAddressChange_Name = 0;
        class PaymentRequestClient_OnShippingAddressChange_Params_Data {
        public:
            static PaymentRequestClient_OnShippingAddressChange_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PaymentRequestClient_OnShippingAddressChange_Params_Data))) PaymentRequestClient_OnShippingAddressChange_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::PaymentAddress_Data> address;

        private:
            PaymentRequestClient_OnShippingAddressChange_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PaymentRequestClient_OnShippingAddressChange_Params_Data() = delete;
        };
        static_assert(sizeof(PaymentRequestClient_OnShippingAddressChange_Params_Data) == 16,
            "Bad sizeof(PaymentRequestClient_OnShippingAddressChange_Params_Data)");
        constexpr uint32_t kPaymentRequestClient_OnShippingOptionChange_Name = 1;
        class PaymentRequestClient_OnShippingOptionChange_Params_Data {
        public:
            static PaymentRequestClient_OnShippingOptionChange_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PaymentRequestClient_OnShippingOptionChange_Params_Data))) PaymentRequestClient_OnShippingOptionChange_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> shipping_option_id;

        private:
            PaymentRequestClient_OnShippingOptionChange_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PaymentRequestClient_OnShippingOptionChange_Params_Data() = delete;
        };
        static_assert(sizeof(PaymentRequestClient_OnShippingOptionChange_Params_Data) == 16,
            "Bad sizeof(PaymentRequestClient_OnShippingOptionChange_Params_Data)");
        constexpr uint32_t kPaymentRequestClient_OnPaymentResponse_Name = 2;
        class PaymentRequestClient_OnPaymentResponse_Params_Data {
        public:
            static PaymentRequestClient_OnPaymentResponse_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PaymentRequestClient_OnPaymentResponse_Params_Data))) PaymentRequestClient_OnPaymentResponse_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::PaymentResponse_Data> response;

        private:
            PaymentRequestClient_OnPaymentResponse_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PaymentRequestClient_OnPaymentResponse_Params_Data() = delete;
        };
        static_assert(sizeof(PaymentRequestClient_OnPaymentResponse_Params_Data) == 16,
            "Bad sizeof(PaymentRequestClient_OnPaymentResponse_Params_Data)");
        constexpr uint32_t kPaymentRequestClient_OnError_Name = 3;
        class PaymentRequestClient_OnError_Params_Data {
        public:
            static PaymentRequestClient_OnError_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PaymentRequestClient_OnError_Params_Data))) PaymentRequestClient_OnError_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t error;
            uint8_t padfinal_[4];

        private:
            PaymentRequestClient_OnError_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PaymentRequestClient_OnError_Params_Data() = delete;
        };
        static_assert(sizeof(PaymentRequestClient_OnError_Params_Data) == 16,
            "Bad sizeof(PaymentRequestClient_OnError_Params_Data)");
        constexpr uint32_t kPaymentRequestClient_OnComplete_Name = 4;
        class PaymentRequestClient_OnComplete_Params_Data {
        public:
            static PaymentRequestClient_OnComplete_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PaymentRequestClient_OnComplete_Params_Data))) PaymentRequestClient_OnComplete_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            PaymentRequestClient_OnComplete_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PaymentRequestClient_OnComplete_Params_Data() = delete;
        };
        static_assert(sizeof(PaymentRequestClient_OnComplete_Params_Data) == 8,
            "Bad sizeof(PaymentRequestClient_OnComplete_Params_Data)");
        constexpr uint32_t kPaymentRequestClient_OnAbort_Name = 5;
        class PaymentRequestClient_OnAbort_Params_Data {
        public:
            static PaymentRequestClient_OnAbort_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PaymentRequestClient_OnAbort_Params_Data))) PaymentRequestClient_OnAbort_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t aborted_successfully : 1;
            uint8_t padfinal_[7];

        private:
            PaymentRequestClient_OnAbort_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PaymentRequestClient_OnAbort_Params_Data() = delete;
        };
        static_assert(sizeof(PaymentRequestClient_OnAbort_Params_Data) == 16,
            "Bad sizeof(PaymentRequestClient_OnAbort_Params_Data)");
        constexpr uint32_t kPaymentRequestClient_OnCanMakePayment_Name = 6;
        class PaymentRequestClient_OnCanMakePayment_Params_Data {
        public:
            static PaymentRequestClient_OnCanMakePayment_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PaymentRequestClient_OnCanMakePayment_Params_Data))) PaymentRequestClient_OnCanMakePayment_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t result;
            uint8_t padfinal_[4];

        private:
            PaymentRequestClient_OnCanMakePayment_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PaymentRequestClient_OnCanMakePayment_Params_Data() = delete;
        };
        static_assert(sizeof(PaymentRequestClient_OnCanMakePayment_Params_Data) == 16,
            "Bad sizeof(PaymentRequestClient_OnCanMakePayment_Params_Data)");
        constexpr uint32_t kPaymentRequest_Init_Name = 0;
        class PaymentRequest_Init_Params_Data {
        public:
            static PaymentRequest_Init_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PaymentRequest_Init_Params_Data))) PaymentRequest_Init_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Interface_Data client;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::PaymentMethodData_Data>>> method_data;
            mojo::internal::Pointer<internal::PaymentDetails_Data> details;
            mojo::internal::Pointer<internal::PaymentOptions_Data> options;

        private:
            PaymentRequest_Init_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PaymentRequest_Init_Params_Data() = delete;
        };
        static_assert(sizeof(PaymentRequest_Init_Params_Data) == 40,
            "Bad sizeof(PaymentRequest_Init_Params_Data)");
        constexpr uint32_t kPaymentRequest_Show_Name = 1;
        class PaymentRequest_Show_Params_Data {
        public:
            static PaymentRequest_Show_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PaymentRequest_Show_Params_Data))) PaymentRequest_Show_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            PaymentRequest_Show_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PaymentRequest_Show_Params_Data() = delete;
        };
        static_assert(sizeof(PaymentRequest_Show_Params_Data) == 8,
            "Bad sizeof(PaymentRequest_Show_Params_Data)");
        constexpr uint32_t kPaymentRequest_UpdateWith_Name = 2;
        class PaymentRequest_UpdateWith_Params_Data {
        public:
            static PaymentRequest_UpdateWith_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PaymentRequest_UpdateWith_Params_Data))) PaymentRequest_UpdateWith_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::PaymentDetails_Data> details;

        private:
            PaymentRequest_UpdateWith_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PaymentRequest_UpdateWith_Params_Data() = delete;
        };
        static_assert(sizeof(PaymentRequest_UpdateWith_Params_Data) == 16,
            "Bad sizeof(PaymentRequest_UpdateWith_Params_Data)");
        constexpr uint32_t kPaymentRequest_Abort_Name = 3;
        class PaymentRequest_Abort_Params_Data {
        public:
            static PaymentRequest_Abort_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PaymentRequest_Abort_Params_Data))) PaymentRequest_Abort_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            PaymentRequest_Abort_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PaymentRequest_Abort_Params_Data() = delete;
        };
        static_assert(sizeof(PaymentRequest_Abort_Params_Data) == 8,
            "Bad sizeof(PaymentRequest_Abort_Params_Data)");
        constexpr uint32_t kPaymentRequest_Complete_Name = 4;
        class PaymentRequest_Complete_Params_Data {
        public:
            static PaymentRequest_Complete_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PaymentRequest_Complete_Params_Data))) PaymentRequest_Complete_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t result;
            uint8_t padfinal_[4];

        private:
            PaymentRequest_Complete_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PaymentRequest_Complete_Params_Data() = delete;
        };
        static_assert(sizeof(PaymentRequest_Complete_Params_Data) == 16,
            "Bad sizeof(PaymentRequest_Complete_Params_Data)");
        constexpr uint32_t kPaymentRequest_CanMakePayment_Name = 5;
        class PaymentRequest_CanMakePayment_Params_Data {
        public:
            static PaymentRequest_CanMakePayment_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PaymentRequest_CanMakePayment_Params_Data))) PaymentRequest_CanMakePayment_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            PaymentRequest_CanMakePayment_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PaymentRequest_CanMakePayment_Params_Data() = delete;
        };
        static_assert(sizeof(PaymentRequest_CanMakePayment_Params_Data) == 8,
            "Bad sizeof(PaymentRequest_CanMakePayment_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace payments

#endif // COMPONENTS_PAYMENTS_PAYMENT_REQUEST_MOJOM_SHARED_INTERNAL_H_