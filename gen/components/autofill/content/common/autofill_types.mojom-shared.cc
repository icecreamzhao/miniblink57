// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4065)
#endif

#include "components/autofill/content/common/autofill_types.mojom-shared.h"

#include <utility>

#include "base/logging.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/cpp/bindings/lib/validation_util.h"
namespace autofill {
namespace mojom {

    namespace internal {

        // static
        bool FormFieldData_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const FormFieldData_Data* object = static_cast<const FormFieldData_Data*>(data);

            static constexpr struct {
                uint32_t version;
                uint32_t num_bytes;
            } kVersionSizes[] = { { 0, 112 } };

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
                    object->label, "null label field in FormFieldData",
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
                    object->name, "null name field in FormFieldData",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams name_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->name, validation_context,
                    &name_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->value, "null value field in FormFieldData",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams value_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->value, validation_context,
                    &value_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->form_control_type, "null form_control_type field in FormFieldData",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams form_control_type_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->form_control_type, validation_context,
                    &form_control_type_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->autocomplete_attribute, "null autocomplete_attribute field in FormFieldData",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams autocomplete_attribute_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->autocomplete_attribute, validation_context,
                    &autocomplete_attribute_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->placeholder, "null placeholder field in FormFieldData",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams placeholder_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->placeholder, validation_context,
                    &placeholder_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->css_classes, "null css_classes field in FormFieldData",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams css_classes_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->css_classes, validation_context,
                    &css_classes_validate_params)) {
                return false;
            }

            if (!::autofill::mojom::internal::CheckStatus_Data ::Validate(object->check_status, validation_context))
                return false;

            if (!::autofill::mojom::internal::RoleAttribute_Data ::Validate(object->role, validation_context))
                return false;

            if (!::mojo::common::mojom::internal::TextDirection_Data ::Validate(object->text_direction, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->option_values, "null option_values field in FormFieldData",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams option_values_validate_params(
                0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr));
            if (!mojo::internal::ValidateContainer(object->option_values, validation_context,
                    &option_values_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->option_contents, "null option_contents field in FormFieldData",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams option_contents_validate_params(
                0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr));
            if (!mojo::internal::ValidateContainer(object->option_contents, validation_context,
                    &option_contents_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool FormData_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const FormData_Data* object = static_cast<const FormData_Data*>(data);

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
                    object->name, "null name field in FormData",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams name_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->name, validation_context,
                    &name_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->origin, "null origin field in FormData",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->origin, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->action, "null action field in FormData",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->action, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->fields, "null fields field in FormData",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams fields_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->fields, validation_context,
                    &fields_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool FormFieldDataPredictions_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const FormFieldDataPredictions_Data* object = static_cast<const FormFieldDataPredictions_Data*>(data);

            static constexpr struct {
                uint32_t version;
                uint32_t num_bytes;
            } kVersionSizes[] = { { 0, 56 } };

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
                    object->field, "null field field in FormFieldDataPredictions",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->field, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->signature, "null signature field in FormFieldDataPredictions",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams signature_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->signature, validation_context,
                    &signature_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->heuristic_type, "null heuristic_type field in FormFieldDataPredictions",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams heuristic_type_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->heuristic_type, validation_context,
                    &heuristic_type_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->server_type, "null server_type field in FormFieldDataPredictions",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams server_type_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->server_type, validation_context,
                    &server_type_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->overall_type, "null overall_type field in FormFieldDataPredictions",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams overall_type_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->overall_type, validation_context,
                    &overall_type_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->parseable_name, "null parseable_name field in FormFieldDataPredictions",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams parseable_name_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->parseable_name, validation_context,
                    &parseable_name_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool FormDataPredictions_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const FormDataPredictions_Data* object = static_cast<const FormDataPredictions_Data*>(data);

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
                    object->data, "null data field in FormDataPredictions",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->data, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->signature, "null signature field in FormDataPredictions",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams signature_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->signature, validation_context,
                    &signature_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->fields, "null fields field in FormDataPredictions",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams fields_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->fields, validation_context,
                    &fields_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool PasswordAndRealm_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const PasswordAndRealm_Data* object = static_cast<const PasswordAndRealm_Data*>(data);

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
                    object->password, "null password field in PasswordAndRealm",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams password_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->password, validation_context,
                    &password_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->realm, "null realm field in PasswordAndRealm",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams realm_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->realm, validation_context,
                    &realm_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool UsernamesCollectionKey_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const UsernamesCollectionKey_Data* object = static_cast<const UsernamesCollectionKey_Data*>(data);

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
                    object->username, "null username field in UsernamesCollectionKey",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams username_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->username, validation_context,
                    &username_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->password, "null password field in UsernamesCollectionKey",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams password_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->password, validation_context,
                    &password_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->realm, "null realm field in UsernamesCollectionKey",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams realm_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->realm, validation_context,
                    &realm_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool PasswordFormFillData_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const PasswordFormFillData_Data* object = static_cast<const PasswordFormFillData_Data*>(data);

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
                    object->name, "null name field in PasswordFormFillData",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams name_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->name, validation_context,
                    &name_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->origin, "null origin field in PasswordFormFillData",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->origin, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->action, "null action field in PasswordFormFillData",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->action, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->username_field, "null username_field field in PasswordFormFillData",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->username_field, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->password_field, "null password_field field in PasswordFormFillData",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->password_field, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->preferred_realm, "null preferred_realm field in PasswordFormFillData",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams preferred_realm_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->preferred_realm, validation_context,
                    &preferred_realm_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->additional_logins, "null additional_logins field in PasswordFormFillData",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams additional_logins_validate_params(
                new mojo::internal::ContainerValidateParams(0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr)), new mojo::internal::ContainerValidateParams(0, false, nullptr));
            if (!mojo::internal::ValidateContainer(object->additional_logins, validation_context,
                    &additional_logins_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->other_possible_usernames_keys, "null other_possible_usernames_keys field in PasswordFormFillData",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams other_possible_usernames_keys_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->other_possible_usernames_keys, validation_context,
                    &other_possible_usernames_keys_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->other_possible_usernames_values, "null other_possible_usernames_values field in PasswordFormFillData",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams other_possible_usernames_values_validate_params(
                0, false, new mojo::internal::ContainerValidateParams(0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr)));
            if (!mojo::internal::ValidateContainer(object->other_possible_usernames_values, validation_context,
                    &other_possible_usernames_values_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool PasswordFormGenerationData_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const PasswordFormGenerationData_Data* object = static_cast<const PasswordFormGenerationData_Data*>(data);

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

            return true;
        }

        // static
        bool PasswordForm_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const PasswordForm_Data* object = static_cast<const PasswordForm_Data*>(data);

            static constexpr struct {
                uint32_t version;
                uint32_t num_bytes;
            } kVersionSizes[] = { { 0, 176 } };

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

            if (!::autofill::mojom::internal::PasswordFormScheme_Data ::Validate(object->scheme, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->signon_realm, "null signon_realm field in PasswordForm",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams signon_realm_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->signon_realm, validation_context,
                    &signon_realm_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->origin_with_path, "null origin_with_path field in PasswordForm",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->origin_with_path, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->action, "null action field in PasswordForm",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->action, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->affiliated_web_realm, "null affiliated_web_realm field in PasswordForm",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams affiliated_web_realm_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->affiliated_web_realm, validation_context,
                    &affiliated_web_realm_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->submit_element, "null submit_element field in PasswordForm",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams submit_element_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->submit_element, validation_context,
                    &submit_element_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->username_element, "null username_element field in PasswordForm",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams username_element_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->username_element, validation_context,
                    &username_element_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->username_value, "null username_value field in PasswordForm",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams username_value_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->username_value, validation_context,
                    &username_value_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->other_possible_usernames, "null other_possible_usernames field in PasswordForm",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams other_possible_usernames_validate_params(
                0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr));
            if (!mojo::internal::ValidateContainer(object->other_possible_usernames, validation_context,
                    &other_possible_usernames_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->password_element, "null password_element field in PasswordForm",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams password_element_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->password_element, validation_context,
                    &password_element_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->password_value, "null password_value field in PasswordForm",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams password_value_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->password_value, validation_context,
                    &password_value_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->new_password_element, "null new_password_element field in PasswordForm",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams new_password_element_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->new_password_element, validation_context,
                    &new_password_element_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->new_password_value, "null new_password_value field in PasswordForm",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams new_password_value_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->new_password_value, validation_context,
                    &new_password_value_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->date_created, "null date_created field in PasswordForm",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->date_created, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->date_synced, "null date_synced field in PasswordForm",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->date_synced, validation_context))
                return false;

            if (!::autofill::mojom::internal::PasswordFormType_Data ::Validate(object->type, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->form_data, "null form_data field in PasswordForm",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->form_data, validation_context))
                return false;

            if (!::autofill::mojom::internal::GenerationUploadStatus_Data ::Validate(object->generation_upload_status, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->display_name, "null display_name field in PasswordForm",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams display_name_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->display_name, validation_context,
                    &display_name_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->icon_url, "null icon_url field in PasswordForm",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->icon_url, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->federation_origin, "null federation_origin field in PasswordForm",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->federation_origin, validation_context))
                return false;

            if (!::autofill::mojom::internal::PasswordFormLayout_Data ::Validate(object->layout, validation_context))
                return false;

            return true;
        }

        // static
        bool PasswordFormFieldPredictionMap_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const PasswordFormFieldPredictionMap_Data* object = static_cast<const PasswordFormFieldPredictionMap_Data*>(data);

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
                    object->keys, "null keys field in PasswordFormFieldPredictionMap",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams keys_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->keys, validation_context,
                    &keys_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->values, "null values field in PasswordFormFieldPredictionMap",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams values_validate_params(
                0, ::autofill::mojom::internal::PasswordFormFieldPredictionType_Data::Validate);
            if (!mojo::internal::ValidateContainer(object->values, validation_context,
                    &values_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool FormsPredictionsMap_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const FormsPredictionsMap_Data* object = static_cast<const FormsPredictionsMap_Data*>(data);

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
                    object->keys, "null keys field in FormsPredictionsMap",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams keys_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->keys, validation_context,
                    &keys_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->values, "null values field in FormsPredictionsMap",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams values_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->values, validation_context,
                    &values_validate_params)) {
                return false;
            }

            return true;
        }

    } // namespace internal
} // namespace mojom
} // namespace autofill

#if defined(_MSC_VER)
#pragma warning(pop)
#endif
