// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4065)
#endif

#include "components/payments/payment_request.mojom-shared.h"

#include <utility>

#include "base/logging.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/cpp/bindings/lib/validation_util.h"
namespace payments {
namespace mojom {

    namespace internal {

        // static
        bool PaymentAddress_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const PaymentAddress_Data* object = static_cast<const PaymentAddress_Data*>(data);

            static constexpr struct {
                uint32_t version;
                uint32_t num_bytes;
            } kVersionSizes[] = { { 0, 104 } };

            if (object->header_.version <= kVersionSizes[arraysize(kVersionSizes) - 1].version) {
                // Scan in reverse order to optimize for more recent versions.
                for (int i = arraysize(kVersionSizes) - 1; i >= 0; --i) {
                    if (object->header_.version >= kVersionSizes[i].version) {
                        if (object->header_.num_bytes == kVersionSizes[i].num_bytes)
                            break;

                        ReportValidationError(
                            validation_context,
                            mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                        return false;
                    }
                }
            } else if (object->header_.num_bytes < kVersionSizes[arraysize(kVersionSizes) - 1].num_bytes) {
                ReportValidationError(
                    validation_context,
                    mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->country, "null country field in PaymentAddress",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams country_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->country, validation_context,
                    &country_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->address_line, "null address_line field in PaymentAddress",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams address_line_validate_params(
                0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr));
            if (!mojo::internal::ValidateContainer(object->address_line, validation_context,
                    &address_line_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->region, "null region field in PaymentAddress",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams region_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->region, validation_context,
                    &region_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->city, "null city field in PaymentAddress",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams city_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->city, validation_context,
                    &city_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->dependent_locality, "null dependent_locality field in PaymentAddress",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams dependent_locality_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->dependent_locality, validation_context,
                    &dependent_locality_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->postal_code, "null postal_code field in PaymentAddress",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams postal_code_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->postal_code, validation_context,
                    &postal_code_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->sorting_code, "null sorting_code field in PaymentAddress",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams sorting_code_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->sorting_code, validation_context,
                    &sorting_code_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->language_code, "null language_code field in PaymentAddress",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams language_code_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->language_code, validation_context,
                    &language_code_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->script_code, "null script_code field in PaymentAddress",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams script_code_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->script_code, validation_context,
                    &script_code_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->organization, "null organization field in PaymentAddress",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams organization_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->organization, validation_context,
                    &organization_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->recipient, "null recipient field in PaymentAddress",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams recipient_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->recipient, validation_context,
                    &recipient_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->phone, "null phone field in PaymentAddress",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams phone_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->phone, validation_context,
                    &phone_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool PaymentCurrencyAmount_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const PaymentCurrencyAmount_Data* object = static_cast<const PaymentCurrencyAmount_Data*>(data);

            static constexpr struct {
                uint32_t version;
                uint32_t num_bytes;
            } kVersionSizes[] = { { 0, 32 } };

            if (object->header_.version <= kVersionSizes[arraysize(kVersionSizes) - 1].version) {
                // Scan in reverse order to optimize for more recent versions.
                for (int i = arraysize(kVersionSizes) - 1; i >= 0; --i) {
                    if (object->header_.version >= kVersionSizes[i].version) {
                        if (object->header_.num_bytes == kVersionSizes[i].num_bytes)
                            break;

                        ReportValidationError(
                            validation_context,
                            mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                        return false;
                    }
                }
            } else if (object->header_.num_bytes < kVersionSizes[arraysize(kVersionSizes) - 1].num_bytes) {
                ReportValidationError(
                    validation_context,
                    mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->currency, "null currency field in PaymentCurrencyAmount",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams currency_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->currency, validation_context,
                    &currency_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->value, "null value field in PaymentCurrencyAmount",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams value_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->value, validation_context,
                    &value_validate_params)) {
                return false;
            }

            const mojo::internal::ContainerValidateParams currency_system_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->currency_system, validation_context,
                    &currency_system_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool PaymentResponse_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const PaymentResponse_Data* object = static_cast<const PaymentResponse_Data*>(data);

            static constexpr struct {
                uint32_t version;
                uint32_t num_bytes;
            } kVersionSizes[] = { { 0, 64 } };

            if (object->header_.version <= kVersionSizes[arraysize(kVersionSizes) - 1].version) {
                // Scan in reverse order to optimize for more recent versions.
                for (int i = arraysize(kVersionSizes) - 1; i >= 0; --i) {
                    if (object->header_.version >= kVersionSizes[i].version) {
                        if (object->header_.num_bytes == kVersionSizes[i].num_bytes)
                            break;

                        ReportValidationError(
                            validation_context,
                            mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                        return false;
                    }
                }
            } else if (object->header_.num_bytes < kVersionSizes[arraysize(kVersionSizes) - 1].num_bytes) {
                ReportValidationError(
                    validation_context,
                    mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->method_name, "null method_name field in PaymentResponse",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams method_name_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->method_name, validation_context,
                    &method_name_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->stringified_details, "null stringified_details field in PaymentResponse",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams stringified_details_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->stringified_details, validation_context,
                    &stringified_details_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidateStruct(object->shipping_address, validation_context))
                return false;

            const mojo::internal::ContainerValidateParams shipping_option_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->shipping_option, validation_context,
                    &shipping_option_validate_params)) {
                return false;
            }

            const mojo::internal::ContainerValidateParams payer_name_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->payer_name, validation_context,
                    &payer_name_validate_params)) {
                return false;
            }

            const mojo::internal::ContainerValidateParams payer_email_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->payer_email, validation_context,
                    &payer_email_validate_params)) {
                return false;
            }

            const mojo::internal::ContainerValidateParams payer_phone_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->payer_phone, validation_context,
                    &payer_phone_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool PaymentItem_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const PaymentItem_Data* object = static_cast<const PaymentItem_Data*>(data);

            static constexpr struct {
                uint32_t version;
                uint32_t num_bytes;
            } kVersionSizes[] = { { 0, 32 } };

            if (object->header_.version <= kVersionSizes[arraysize(kVersionSizes) - 1].version) {
                // Scan in reverse order to optimize for more recent versions.
                for (int i = arraysize(kVersionSizes) - 1; i >= 0; --i) {
                    if (object->header_.version >= kVersionSizes[i].version) {
                        if (object->header_.num_bytes == kVersionSizes[i].num_bytes)
                            break;

                        ReportValidationError(
                            validation_context,
                            mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                        return false;
                    }
                }
            } else if (object->header_.num_bytes < kVersionSizes[arraysize(kVersionSizes) - 1].num_bytes) {
                ReportValidationError(
                    validation_context,
                    mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->label, "null label field in PaymentItem",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams label_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->label, validation_context,
                    &label_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->amount, "null amount field in PaymentItem",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->amount, validation_context))
                return false;

            return true;
        }

        // static
        bool PaymentShippingOption_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const PaymentShippingOption_Data* object = static_cast<const PaymentShippingOption_Data*>(data);

            static constexpr struct {
                uint32_t version;
                uint32_t num_bytes;
            } kVersionSizes[] = { { 0, 40 } };

            if (object->header_.version <= kVersionSizes[arraysize(kVersionSizes) - 1].version) {
                // Scan in reverse order to optimize for more recent versions.
                for (int i = arraysize(kVersionSizes) - 1; i >= 0; --i) {
                    if (object->header_.version >= kVersionSizes[i].version) {
                        if (object->header_.num_bytes == kVersionSizes[i].num_bytes)
                            break;

                        ReportValidationError(
                            validation_context,
                            mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                        return false;
                    }
                }
            } else if (object->header_.num_bytes < kVersionSizes[arraysize(kVersionSizes) - 1].num_bytes) {
                ReportValidationError(
                    validation_context,
                    mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->id, "null id field in PaymentShippingOption",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams id_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->id, validation_context,
                    &id_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->label, "null label field in PaymentShippingOption",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams label_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->label, validation_context,
                    &label_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->amount, "null amount field in PaymentShippingOption",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->amount, validation_context))
                return false;

            return true;
        }

        // static
        bool AndroidPayTokenizationParameter_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const AndroidPayTokenizationParameter_Data* object = static_cast<const AndroidPayTokenizationParameter_Data*>(data);

            static constexpr struct {
                uint32_t version;
                uint32_t num_bytes;
            } kVersionSizes[] = { { 0, 24 } };

            if (object->header_.version <= kVersionSizes[arraysize(kVersionSizes) - 1].version) {
                // Scan in reverse order to optimize for more recent versions.
                for (int i = arraysize(kVersionSizes) - 1; i >= 0; --i) {
                    if (object->header_.version >= kVersionSizes[i].version) {
                        if (object->header_.num_bytes == kVersionSizes[i].num_bytes)
                            break;

                        ReportValidationError(
                            validation_context,
                            mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                        return false;
                    }
                }
            } else if (object->header_.num_bytes < kVersionSizes[arraysize(kVersionSizes) - 1].num_bytes) {
                ReportValidationError(
                    validation_context,
                    mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                return false;
            }

            const mojo::internal::ContainerValidateParams key_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->key, validation_context,
                    &key_validate_params)) {
                return false;
            }

            const mojo::internal::ContainerValidateParams value_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->value, validation_context,
                    &value_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool PaymentMethodData_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const PaymentMethodData_Data* object = static_cast<const PaymentMethodData_Data*>(data);

            static constexpr struct {
                uint32_t version;
                uint32_t num_bytes;
            } kVersionSizes[] = { { 0, 88 } };

            if (object->header_.version <= kVersionSizes[arraysize(kVersionSizes) - 1].version) {
                // Scan in reverse order to optimize for more recent versions.
                for (int i = arraysize(kVersionSizes) - 1; i >= 0; --i) {
                    if (object->header_.version >= kVersionSizes[i].version) {
                        if (object->header_.num_bytes == kVersionSizes[i].num_bytes)
                            break;

                        ReportValidationError(
                            validation_context,
                            mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                        return false;
                    }
                }
            } else if (object->header_.num_bytes < kVersionSizes[arraysize(kVersionSizes) - 1].num_bytes) {
                ReportValidationError(
                    validation_context,
                    mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->supported_methods, "null supported_methods field in PaymentMethodData",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams supported_methods_validate_params(
                0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr));
            if (!mojo::internal::ValidateContainer(object->supported_methods, validation_context,
                    &supported_methods_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->stringified_data, "null stringified_data field in PaymentMethodData",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams stringified_data_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->stringified_data, validation_context,
                    &stringified_data_validate_params)) {
                return false;
            }

            if (!::payments::mojom::internal::AndroidPayEnvironment_Data ::Validate(object->environment, validation_context))
                return false;

            const mojo::internal::ContainerValidateParams merchant_name_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->merchant_name, validation_context,
                    &merchant_name_validate_params)) {
                return false;
            }

            const mojo::internal::ContainerValidateParams merchant_id_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->merchant_id, validation_context,
                    &merchant_id_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->allowed_card_networks, "null allowed_card_networks field in PaymentMethodData",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams allowed_card_networks_validate_params(
                0, ::payments::mojom::internal::AndroidPayCardNetwork_Data::Validate);
            if (!mojo::internal::ValidateContainer(object->allowed_card_networks, validation_context,
                    &allowed_card_networks_validate_params)) {
                return false;
            }

            if (!::payments::mojom::internal::AndroidPayTokenization_Data ::Validate(object->tokenization_type, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->parameters, "null parameters field in PaymentMethodData",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams parameters_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->parameters, validation_context,
                    &parameters_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->supported_networks, "null supported_networks field in PaymentMethodData",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams supported_networks_validate_params(
                0, ::payments::mojom::internal::BasicCardNetwork_Data::Validate);
            if (!mojo::internal::ValidateContainer(object->supported_networks, validation_context,
                    &supported_networks_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->supported_types, "null supported_types field in PaymentMethodData",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams supported_types_validate_params(
                0, ::payments::mojom::internal::BasicCardType_Data::Validate);
            if (!mojo::internal::ValidateContainer(object->supported_types, validation_context,
                    &supported_types_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool PaymentDetailsModifier_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const PaymentDetailsModifier_Data* object = static_cast<const PaymentDetailsModifier_Data*>(data);

            static constexpr struct {
                uint32_t version;
                uint32_t num_bytes;
            } kVersionSizes[] = { { 0, 32 } };

            if (object->header_.version <= kVersionSizes[arraysize(kVersionSizes) - 1].version) {
                // Scan in reverse order to optimize for more recent versions.
                for (int i = arraysize(kVersionSizes) - 1; i >= 0; --i) {
                    if (object->header_.version >= kVersionSizes[i].version) {
                        if (object->header_.num_bytes == kVersionSizes[i].num_bytes)
                            break;

                        ReportValidationError(
                            validation_context,
                            mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                        return false;
                    }
                }
            } else if (object->header_.num_bytes < kVersionSizes[arraysize(kVersionSizes) - 1].num_bytes) {
                ReportValidationError(
                    validation_context,
                    mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                return false;
            }

            if (!mojo::internal::ValidateStruct(object->total, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->additional_display_items, "null additional_display_items field in PaymentDetailsModifier",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams additional_display_items_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->additional_display_items, validation_context,
                    &additional_display_items_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->method_data, "null method_data field in PaymentDetailsModifier",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->method_data, validation_context))
                return false;

            return true;
        }

        // static
        bool PaymentDetails_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const PaymentDetails_Data* object = static_cast<const PaymentDetails_Data*>(data);

            static constexpr struct {
                uint32_t version;
                uint32_t num_bytes;
            } kVersionSizes[] = { { 0, 48 } };

            if (object->header_.version <= kVersionSizes[arraysize(kVersionSizes) - 1].version) {
                // Scan in reverse order to optimize for more recent versions.
                for (int i = arraysize(kVersionSizes) - 1; i >= 0; --i) {
                    if (object->header_.version >= kVersionSizes[i].version) {
                        if (object->header_.num_bytes == kVersionSizes[i].num_bytes)
                            break;

                        ReportValidationError(
                            validation_context,
                            mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                        return false;
                    }
                }
            } else if (object->header_.num_bytes < kVersionSizes[arraysize(kVersionSizes) - 1].num_bytes) {
                ReportValidationError(
                    validation_context,
                    mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->total, "null total field in PaymentDetails",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->total, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->display_items, "null display_items field in PaymentDetails",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams display_items_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->display_items, validation_context,
                    &display_items_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->shipping_options, "null shipping_options field in PaymentDetails",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams shipping_options_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->shipping_options, validation_context,
                    &shipping_options_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->modifiers, "null modifiers field in PaymentDetails",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams modifiers_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->modifiers, validation_context,
                    &modifiers_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->error, "null error field in PaymentDetails",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams error_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->error, validation_context,
                    &error_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool PaymentOptions_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const PaymentOptions_Data* object = static_cast<const PaymentOptions_Data*>(data);

            static constexpr struct {
                uint32_t version;
                uint32_t num_bytes;
            } kVersionSizes[] = { { 0, 16 } };

            if (object->header_.version <= kVersionSizes[arraysize(kVersionSizes) - 1].version) {
                // Scan in reverse order to optimize for more recent versions.
                for (int i = arraysize(kVersionSizes) - 1; i >= 0; --i) {
                    if (object->header_.version >= kVersionSizes[i].version) {
                        if (object->header_.num_bytes == kVersionSizes[i].num_bytes)
                            break;

                        ReportValidationError(
                            validation_context,
                            mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                        return false;
                    }
                }
            } else if (object->header_.num_bytes < kVersionSizes[arraysize(kVersionSizes) - 1].num_bytes) {
                ReportValidationError(
                    validation_context,
                    mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                return false;
            }

            if (!::payments::mojom::internal::PaymentShippingType_Data ::Validate(object->shipping_type, validation_context))
                return false;

            return true;
        }

        // static
        bool PaymentRequestClient_OnShippingAddressChange_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const PaymentRequestClient_OnShippingAddressChange_Params_Data* object = static_cast<const PaymentRequestClient_OnShippingAddressChange_Params_Data*>(data);

            static constexpr struct {
                uint32_t version;
                uint32_t num_bytes;
            } kVersionSizes[] = { { 0, 16 } };

            if (object->header_.version <= kVersionSizes[arraysize(kVersionSizes) - 1].version) {
                // Scan in reverse order to optimize for more recent versions.
                for (int i = arraysize(kVersionSizes) - 1; i >= 0; --i) {
                    if (object->header_.version >= kVersionSizes[i].version) {
                        if (object->header_.num_bytes == kVersionSizes[i].num_bytes)
                            break;

                        ReportValidationError(
                            validation_context,
                            mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                        return false;
                    }
                }
            } else if (object->header_.num_bytes < kVersionSizes[arraysize(kVersionSizes) - 1].num_bytes) {
                ReportValidationError(
                    validation_context,
                    mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->address, "null address field in PaymentRequestClient_OnShippingAddressChange_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->address, validation_context))
                return false;

            return true;
        }

        // static
        bool PaymentRequestClient_OnShippingOptionChange_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const PaymentRequestClient_OnShippingOptionChange_Params_Data* object = static_cast<const PaymentRequestClient_OnShippingOptionChange_Params_Data*>(data);

            static constexpr struct {
                uint32_t version;
                uint32_t num_bytes;
            } kVersionSizes[] = { { 0, 16 } };

            if (object->header_.version <= kVersionSizes[arraysize(kVersionSizes) - 1].version) {
                // Scan in reverse order to optimize for more recent versions.
                for (int i = arraysize(kVersionSizes) - 1; i >= 0; --i) {
                    if (object->header_.version >= kVersionSizes[i].version) {
                        if (object->header_.num_bytes == kVersionSizes[i].num_bytes)
                            break;

                        ReportValidationError(
                            validation_context,
                            mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                        return false;
                    }
                }
            } else if (object->header_.num_bytes < kVersionSizes[arraysize(kVersionSizes) - 1].num_bytes) {
                ReportValidationError(
                    validation_context,
                    mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->shipping_option_id, "null shipping_option_id field in PaymentRequestClient_OnShippingOptionChange_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams shipping_option_id_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->shipping_option_id, validation_context,
                    &shipping_option_id_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool PaymentRequestClient_OnPaymentResponse_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const PaymentRequestClient_OnPaymentResponse_Params_Data* object = static_cast<const PaymentRequestClient_OnPaymentResponse_Params_Data*>(data);

            static constexpr struct {
                uint32_t version;
                uint32_t num_bytes;
            } kVersionSizes[] = { { 0, 16 } };

            if (object->header_.version <= kVersionSizes[arraysize(kVersionSizes) - 1].version) {
                // Scan in reverse order to optimize for more recent versions.
                for (int i = arraysize(kVersionSizes) - 1; i >= 0; --i) {
                    if (object->header_.version >= kVersionSizes[i].version) {
                        if (object->header_.num_bytes == kVersionSizes[i].num_bytes)
                            break;

                        ReportValidationError(
                            validation_context,
                            mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                        return false;
                    }
                }
            } else if (object->header_.num_bytes < kVersionSizes[arraysize(kVersionSizes) - 1].num_bytes) {
                ReportValidationError(
                    validation_context,
                    mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->response, "null response field in PaymentRequestClient_OnPaymentResponse_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->response, validation_context))
                return false;

            return true;
        }

        // static
        bool PaymentRequestClient_OnError_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const PaymentRequestClient_OnError_Params_Data* object = static_cast<const PaymentRequestClient_OnError_Params_Data*>(data);

            static constexpr struct {
                uint32_t version;
                uint32_t num_bytes;
            } kVersionSizes[] = { { 0, 16 } };

            if (object->header_.version <= kVersionSizes[arraysize(kVersionSizes) - 1].version) {
                // Scan in reverse order to optimize for more recent versions.
                for (int i = arraysize(kVersionSizes) - 1; i >= 0; --i) {
                    if (object->header_.version >= kVersionSizes[i].version) {
                        if (object->header_.num_bytes == kVersionSizes[i].num_bytes)
                            break;

                        ReportValidationError(
                            validation_context,
                            mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                        return false;
                    }
                }
            } else if (object->header_.num_bytes < kVersionSizes[arraysize(kVersionSizes) - 1].num_bytes) {
                ReportValidationError(
                    validation_context,
                    mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                return false;
            }

            if (!::payments::mojom::internal::PaymentErrorReason_Data ::Validate(object->error, validation_context))
                return false;

            return true;
        }

        // static
        bool PaymentRequestClient_OnComplete_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const PaymentRequestClient_OnComplete_Params_Data* object = static_cast<const PaymentRequestClient_OnComplete_Params_Data*>(data);

            static constexpr struct {
                uint32_t version;
                uint32_t num_bytes;
            } kVersionSizes[] = { { 0, 8 } };

            if (object->header_.version <= kVersionSizes[arraysize(kVersionSizes) - 1].version) {
                // Scan in reverse order to optimize for more recent versions.
                for (int i = arraysize(kVersionSizes) - 1; i >= 0; --i) {
                    if (object->header_.version >= kVersionSizes[i].version) {
                        if (object->header_.num_bytes == kVersionSizes[i].num_bytes)
                            break;

                        ReportValidationError(
                            validation_context,
                            mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                        return false;
                    }
                }
            } else if (object->header_.num_bytes < kVersionSizes[arraysize(kVersionSizes) - 1].num_bytes) {
                ReportValidationError(
                    validation_context,
                    mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                return false;
            }

            return true;
        }

        // static
        bool PaymentRequestClient_OnAbort_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const PaymentRequestClient_OnAbort_Params_Data* object = static_cast<const PaymentRequestClient_OnAbort_Params_Data*>(data);

            static constexpr struct {
                uint32_t version;
                uint32_t num_bytes;
            } kVersionSizes[] = { { 0, 16 } };

            if (object->header_.version <= kVersionSizes[arraysize(kVersionSizes) - 1].version) {
                // Scan in reverse order to optimize for more recent versions.
                for (int i = arraysize(kVersionSizes) - 1; i >= 0; --i) {
                    if (object->header_.version >= kVersionSizes[i].version) {
                        if (object->header_.num_bytes == kVersionSizes[i].num_bytes)
                            break;

                        ReportValidationError(
                            validation_context,
                            mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                        return false;
                    }
                }
            } else if (object->header_.num_bytes < kVersionSizes[arraysize(kVersionSizes) - 1].num_bytes) {
                ReportValidationError(
                    validation_context,
                    mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                return false;
            }

            return true;
        }

        // static
        bool PaymentRequestClient_OnCanMakePayment_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const PaymentRequestClient_OnCanMakePayment_Params_Data* object = static_cast<const PaymentRequestClient_OnCanMakePayment_Params_Data*>(data);

            static constexpr struct {
                uint32_t version;
                uint32_t num_bytes;
            } kVersionSizes[] = { { 0, 16 } };

            if (object->header_.version <= kVersionSizes[arraysize(kVersionSizes) - 1].version) {
                // Scan in reverse order to optimize for more recent versions.
                for (int i = arraysize(kVersionSizes) - 1; i >= 0; --i) {
                    if (object->header_.version >= kVersionSizes[i].version) {
                        if (object->header_.num_bytes == kVersionSizes[i].num_bytes)
                            break;

                        ReportValidationError(
                            validation_context,
                            mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                        return false;
                    }
                }
            } else if (object->header_.num_bytes < kVersionSizes[arraysize(kVersionSizes) - 1].num_bytes) {
                ReportValidationError(
                    validation_context,
                    mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                return false;
            }

            if (!::payments::mojom::internal::CanMakePaymentQueryResult_Data ::Validate(object->result, validation_context))
                return false;

            return true;
        }

        // static
        bool PaymentRequest_Init_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const PaymentRequest_Init_Params_Data* object = static_cast<const PaymentRequest_Init_Params_Data*>(data);

            static constexpr struct {
                uint32_t version;
                uint32_t num_bytes;
            } kVersionSizes[] = { { 0, 40 } };

            if (object->header_.version <= kVersionSizes[arraysize(kVersionSizes) - 1].version) {
                // Scan in reverse order to optimize for more recent versions.
                for (int i = arraysize(kVersionSizes) - 1; i >= 0; --i) {
                    if (object->header_.version >= kVersionSizes[i].version) {
                        if (object->header_.num_bytes == kVersionSizes[i].num_bytes)
                            break;

                        ReportValidationError(
                            validation_context,
                            mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                        return false;
                    }
                }
            } else if (object->header_.num_bytes < kVersionSizes[arraysize(kVersionSizes) - 1].num_bytes) {
                ReportValidationError(
                    validation_context,
                    mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                return false;
            }

            if (!mojo::internal::ValidateHandleOrInterfaceNonNullable(
                    object->client,
                    "invalid client field in PaymentRequest_Init_Params", validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateHandleOrInterface(object->client,
                    validation_context)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->method_data, "null method_data field in PaymentRequest_Init_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams method_data_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->method_data, validation_context,
                    &method_data_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->details, "null details field in PaymentRequest_Init_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->details, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->options, "null options field in PaymentRequest_Init_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->options, validation_context))
                return false;

            return true;
        }

        // static
        bool PaymentRequest_Show_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const PaymentRequest_Show_Params_Data* object = static_cast<const PaymentRequest_Show_Params_Data*>(data);

            static constexpr struct {
                uint32_t version;
                uint32_t num_bytes;
            } kVersionSizes[] = { { 0, 8 } };

            if (object->header_.version <= kVersionSizes[arraysize(kVersionSizes) - 1].version) {
                // Scan in reverse order to optimize for more recent versions.
                for (int i = arraysize(kVersionSizes) - 1; i >= 0; --i) {
                    if (object->header_.version >= kVersionSizes[i].version) {
                        if (object->header_.num_bytes == kVersionSizes[i].num_bytes)
                            break;

                        ReportValidationError(
                            validation_context,
                            mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                        return false;
                    }
                }
            } else if (object->header_.num_bytes < kVersionSizes[arraysize(kVersionSizes) - 1].num_bytes) {
                ReportValidationError(
                    validation_context,
                    mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                return false;
            }

            return true;
        }

        // static
        bool PaymentRequest_UpdateWith_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const PaymentRequest_UpdateWith_Params_Data* object = static_cast<const PaymentRequest_UpdateWith_Params_Data*>(data);

            static constexpr struct {
                uint32_t version;
                uint32_t num_bytes;
            } kVersionSizes[] = { { 0, 16 } };

            if (object->header_.version <= kVersionSizes[arraysize(kVersionSizes) - 1].version) {
                // Scan in reverse order to optimize for more recent versions.
                for (int i = arraysize(kVersionSizes) - 1; i >= 0; --i) {
                    if (object->header_.version >= kVersionSizes[i].version) {
                        if (object->header_.num_bytes == kVersionSizes[i].num_bytes)
                            break;

                        ReportValidationError(
                            validation_context,
                            mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                        return false;
                    }
                }
            } else if (object->header_.num_bytes < kVersionSizes[arraysize(kVersionSizes) - 1].num_bytes) {
                ReportValidationError(
                    validation_context,
                    mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->details, "null details field in PaymentRequest_UpdateWith_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->details, validation_context))
                return false;

            return true;
        }

        // static
        bool PaymentRequest_Abort_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const PaymentRequest_Abort_Params_Data* object = static_cast<const PaymentRequest_Abort_Params_Data*>(data);

            static constexpr struct {
                uint32_t version;
                uint32_t num_bytes;
            } kVersionSizes[] = { { 0, 8 } };

            if (object->header_.version <= kVersionSizes[arraysize(kVersionSizes) - 1].version) {
                // Scan in reverse order to optimize for more recent versions.
                for (int i = arraysize(kVersionSizes) - 1; i >= 0; --i) {
                    if (object->header_.version >= kVersionSizes[i].version) {
                        if (object->header_.num_bytes == kVersionSizes[i].num_bytes)
                            break;

                        ReportValidationError(
                            validation_context,
                            mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                        return false;
                    }
                }
            } else if (object->header_.num_bytes < kVersionSizes[arraysize(kVersionSizes) - 1].num_bytes) {
                ReportValidationError(
                    validation_context,
                    mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                return false;
            }

            return true;
        }

        // static
        bool PaymentRequest_Complete_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const PaymentRequest_Complete_Params_Data* object = static_cast<const PaymentRequest_Complete_Params_Data*>(data);

            static constexpr struct {
                uint32_t version;
                uint32_t num_bytes;
            } kVersionSizes[] = { { 0, 16 } };

            if (object->header_.version <= kVersionSizes[arraysize(kVersionSizes) - 1].version) {
                // Scan in reverse order to optimize for more recent versions.
                for (int i = arraysize(kVersionSizes) - 1; i >= 0; --i) {
                    if (object->header_.version >= kVersionSizes[i].version) {
                        if (object->header_.num_bytes == kVersionSizes[i].num_bytes)
                            break;

                        ReportValidationError(
                            validation_context,
                            mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                        return false;
                    }
                }
            } else if (object->header_.num_bytes < kVersionSizes[arraysize(kVersionSizes) - 1].num_bytes) {
                ReportValidationError(
                    validation_context,
                    mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                return false;
            }

            if (!::payments::mojom::internal::PaymentComplete_Data ::Validate(object->result, validation_context))
                return false;

            return true;
        }

        // static
        bool PaymentRequest_CanMakePayment_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const PaymentRequest_CanMakePayment_Params_Data* object = static_cast<const PaymentRequest_CanMakePayment_Params_Data*>(data);

            static constexpr struct {
                uint32_t version;
                uint32_t num_bytes;
            } kVersionSizes[] = { { 0, 8 } };

            if (object->header_.version <= kVersionSizes[arraysize(kVersionSizes) - 1].version) {
                // Scan in reverse order to optimize for more recent versions.
                for (int i = arraysize(kVersionSizes) - 1; i >= 0; --i) {
                    if (object->header_.version >= kVersionSizes[i].version) {
                        if (object->header_.num_bytes == kVersionSizes[i].num_bytes)
                            break;

                        ReportValidationError(
                            validation_context,
                            mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                        return false;
                    }
                }
            } else if (object->header_.num_bytes < kVersionSizes[arraysize(kVersionSizes) - 1].num_bytes) {
                ReportValidationError(
                    validation_context,
                    mojo::internal::VALIDATION_ERROR_UNEXPECTED_STRUCT_HEADER);
                return false;
            }

            return true;
        }

    } // namespace internal
} // namespace mojom
} // namespace payments

#if defined(_MSC_VER)
#pragma warning(pop)
#endif
