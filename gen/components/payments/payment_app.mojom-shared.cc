// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4065)
#endif

#include "components/payments/payment_app.mojom-shared.h"

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
        bool PaymentAppOption_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const PaymentAppOption_Data* object = static_cast<const PaymentAppOption_Data*>(data);

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
                    object->name, "null name field in PaymentAppOption",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams name_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->name, validation_context,
                    &name_validate_params)) {
                return false;
            }

            const mojo::internal::ContainerValidateParams icon_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->icon, validation_context,
                    &icon_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->id, "null id field in PaymentAppOption",
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
                    object->enabled_methods, "null enabled_methods field in PaymentAppOption",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams enabled_methods_validate_params(
                0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr));
            if (!mojo::internal::ValidateContainer(object->enabled_methods, validation_context,
                    &enabled_methods_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool PaymentAppManifest_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const PaymentAppManifest_Data* object = static_cast<const PaymentAppManifest_Data*>(data);

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
                    object->name, "null name field in PaymentAppManifest",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams name_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->name, validation_context,
                    &name_validate_params)) {
                return false;
            }

            const mojo::internal::ContainerValidateParams icon_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->icon, validation_context,
                    &icon_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->options, "null options field in PaymentAppManifest",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams options_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->options, validation_context,
                    &options_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool PaymentAppRequestData_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const PaymentAppRequestData_Data* object = static_cast<const PaymentAppRequestData_Data*>(data);

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
                    object->origin, "null origin field in PaymentAppRequestData",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->origin, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->methodData, "null methodData field in PaymentAppRequestData",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams methodData_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->methodData, validation_context,
                    &methodData_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->total, "null total field in PaymentAppRequestData",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->total, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->modifiers, "null modifiers field in PaymentAppRequestData",
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
                    object->optionId, "null optionId field in PaymentAppRequestData",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams optionId_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->optionId, validation_context,
                    &optionId_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool PaymentAppManager_Init_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const PaymentAppManager_Init_Params_Data* object = static_cast<const PaymentAppManager_Init_Params_Data*>(data);

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
                    object->service_worker_scope, "null service_worker_scope field in PaymentAppManager_Init_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams service_worker_scope_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->service_worker_scope, validation_context,
                    &service_worker_scope_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool PaymentAppManager_SetManifest_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const PaymentAppManager_SetManifest_Params_Data* object = static_cast<const PaymentAppManager_SetManifest_Params_Data*>(data);

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
                    object->payment_app_manifest, "null payment_app_manifest field in PaymentAppManager_SetManifest_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->payment_app_manifest, validation_context))
                return false;

            return true;
        }

        // static
        bool PaymentAppManager_SetManifest_ResponseParams_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const PaymentAppManager_SetManifest_ResponseParams_Data* object = static_cast<const PaymentAppManager_SetManifest_ResponseParams_Data*>(data);

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

            if (!::payments::mojom::internal::PaymentAppManifestError_Data ::Validate(object->error, validation_context))
                return false;

            return true;
        }

        // static
        bool PaymentAppManager_GetManifest_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const PaymentAppManager_GetManifest_Params_Data* object = static_cast<const PaymentAppManager_GetManifest_Params_Data*>(data);

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
        bool PaymentAppManager_GetManifest_ResponseParams_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const PaymentAppManager_GetManifest_ResponseParams_Data* object = static_cast<const PaymentAppManager_GetManifest_ResponseParams_Data*>(data);

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

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->payment_app_manifest, "null payment_app_manifest field in PaymentAppManager_GetManifest_ResponseParams",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->payment_app_manifest, validation_context))
                return false;

            if (!::payments::mojom::internal::PaymentAppManifestError_Data ::Validate(object->error, validation_context))
                return false;

            return true;
        }

    } // namespace internal
} // namespace mojom
} // namespace payments

#if defined(_MSC_VER)
#pragma warning(pop)
#endif
