// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4065)
#endif

#include "media/mojo/interfaces/content_decryption_module.mojom-shared.h"

#include <utility>

#include "base/logging.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/cpp/bindings/lib/validation_util.h"
namespace media {
namespace mojom {

    namespace internal {

        // static
        bool CdmConfig_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const CdmConfig_Data* object = static_cast<const CdmConfig_Data*>(data);

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
        bool CdmPromiseResult_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const CdmPromiseResult_Data* object = static_cast<const CdmPromiseResult_Data*>(data);

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

            if (!::media::mojom::internal::CdmPromiseResult_Exception_Data ::Validate(object->exception, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->error_message, "null error_message field in CdmPromiseResult",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams error_message_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->error_message, validation_context,
                    &error_message_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool CdmKeyInformation_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const CdmKeyInformation_Data* object = static_cast<const CdmKeyInformation_Data*>(data);

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
                    object->key_id, "null key_id field in CdmKeyInformation",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams key_id_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->key_id, validation_context,
                    &key_id_validate_params)) {
                return false;
            }

            if (!::media::mojom::internal::CdmKeyInformation_KeyStatus_Data ::Validate(object->status, validation_context))
                return false;

            return true;
        }

        // static
        bool ContentDecryptionModule_SetClient_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const ContentDecryptionModule_SetClient_Params_Data* object = static_cast<const ContentDecryptionModule_SetClient_Params_Data*>(data);

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

            if (!mojo::internal::ValidateHandleOrInterfaceNonNullable(
                    object->client,
                    "invalid client field in ContentDecryptionModule_SetClient_Params", validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateHandleOrInterface(object->client,
                    validation_context)) {
                return false;
            }

            return true;
        }

        // static
        bool ContentDecryptionModule_Initialize_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const ContentDecryptionModule_Initialize_Params_Data* object = static_cast<const ContentDecryptionModule_Initialize_Params_Data*>(data);

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
                    object->key_system, "null key_system field in ContentDecryptionModule_Initialize_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams key_system_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->key_system, validation_context,
                    &key_system_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->security_origin, "null security_origin field in ContentDecryptionModule_Initialize_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams security_origin_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->security_origin, validation_context,
                    &security_origin_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->cdm_config, "null cdm_config field in ContentDecryptionModule_Initialize_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->cdm_config, validation_context))
                return false;

            return true;
        }

        // static
        bool ContentDecryptionModule_Initialize_ResponseParams_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const ContentDecryptionModule_Initialize_ResponseParams_Data* object = static_cast<const ContentDecryptionModule_Initialize_ResponseParams_Data*>(data);

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
                    object->result, "null result field in ContentDecryptionModule_Initialize_ResponseParams",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->result, validation_context))
                return false;

            if (!mojo::internal::ValidateHandleOrInterface(object->decryptor,
                    validation_context)) {
                return false;
            }

            return true;
        }

        // static
        bool ContentDecryptionModule_SetServerCertificate_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const ContentDecryptionModule_SetServerCertificate_Params_Data* object = static_cast<const ContentDecryptionModule_SetServerCertificate_Params_Data*>(data);

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
                    object->certificate_data, "null certificate_data field in ContentDecryptionModule_SetServerCertificate_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams certificate_data_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->certificate_data, validation_context,
                    &certificate_data_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool ContentDecryptionModule_SetServerCertificate_ResponseParams_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const ContentDecryptionModule_SetServerCertificate_ResponseParams_Data* object = static_cast<const ContentDecryptionModule_SetServerCertificate_ResponseParams_Data*>(data);

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
                    object->result, "null result field in ContentDecryptionModule_SetServerCertificate_ResponseParams",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->result, validation_context))
                return false;

            return true;
        }

        // static
        bool ContentDecryptionModule_CreateSessionAndGenerateRequest_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const ContentDecryptionModule_CreateSessionAndGenerateRequest_Params_Data* object = static_cast<const ContentDecryptionModule_CreateSessionAndGenerateRequest_Params_Data*>(data);

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

            if (!::media::mojom::internal::ContentDecryptionModule_SessionType_Data ::Validate(object->session_type, validation_context))
                return false;

            if (!::media::mojom::internal::EmeInitDataType_Data ::Validate(object->init_data_type, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->init_data, "null init_data field in ContentDecryptionModule_CreateSessionAndGenerateRequest_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams init_data_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->init_data, validation_context,
                    &init_data_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool ContentDecryptionModule_CreateSessionAndGenerateRequest_ResponseParams_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const ContentDecryptionModule_CreateSessionAndGenerateRequest_ResponseParams_Data* object = static_cast<const ContentDecryptionModule_CreateSessionAndGenerateRequest_ResponseParams_Data*>(data);

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
                    object->result, "null result field in ContentDecryptionModule_CreateSessionAndGenerateRequest_ResponseParams",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->result, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->session_id, "null session_id field in ContentDecryptionModule_CreateSessionAndGenerateRequest_ResponseParams",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams session_id_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->session_id, validation_context,
                    &session_id_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool ContentDecryptionModule_LoadSession_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const ContentDecryptionModule_LoadSession_Params_Data* object = static_cast<const ContentDecryptionModule_LoadSession_Params_Data*>(data);

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

            if (!::media::mojom::internal::ContentDecryptionModule_SessionType_Data ::Validate(object->session_type, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->session_id, "null session_id field in ContentDecryptionModule_LoadSession_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams session_id_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->session_id, validation_context,
                    &session_id_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool ContentDecryptionModule_LoadSession_ResponseParams_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const ContentDecryptionModule_LoadSession_ResponseParams_Data* object = static_cast<const ContentDecryptionModule_LoadSession_ResponseParams_Data*>(data);

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
                    object->result, "null result field in ContentDecryptionModule_LoadSession_ResponseParams",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->result, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->session_id, "null session_id field in ContentDecryptionModule_LoadSession_ResponseParams",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams session_id_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->session_id, validation_context,
                    &session_id_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool ContentDecryptionModule_UpdateSession_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const ContentDecryptionModule_UpdateSession_Params_Data* object = static_cast<const ContentDecryptionModule_UpdateSession_Params_Data*>(data);

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
                    object->session_id, "null session_id field in ContentDecryptionModule_UpdateSession_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams session_id_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->session_id, validation_context,
                    &session_id_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->response, "null response field in ContentDecryptionModule_UpdateSession_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams response_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->response, validation_context,
                    &response_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool ContentDecryptionModule_UpdateSession_ResponseParams_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const ContentDecryptionModule_UpdateSession_ResponseParams_Data* object = static_cast<const ContentDecryptionModule_UpdateSession_ResponseParams_Data*>(data);

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
                    object->result, "null result field in ContentDecryptionModule_UpdateSession_ResponseParams",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->result, validation_context))
                return false;

            return true;
        }

        // static
        bool ContentDecryptionModule_CloseSession_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const ContentDecryptionModule_CloseSession_Params_Data* object = static_cast<const ContentDecryptionModule_CloseSession_Params_Data*>(data);

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
                    object->session_id, "null session_id field in ContentDecryptionModule_CloseSession_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams session_id_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->session_id, validation_context,
                    &session_id_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool ContentDecryptionModule_CloseSession_ResponseParams_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const ContentDecryptionModule_CloseSession_ResponseParams_Data* object = static_cast<const ContentDecryptionModule_CloseSession_ResponseParams_Data*>(data);

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
                    object->result, "null result field in ContentDecryptionModule_CloseSession_ResponseParams",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->result, validation_context))
                return false;

            return true;
        }

        // static
        bool ContentDecryptionModule_RemoveSession_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const ContentDecryptionModule_RemoveSession_Params_Data* object = static_cast<const ContentDecryptionModule_RemoveSession_Params_Data*>(data);

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
                    object->session_id, "null session_id field in ContentDecryptionModule_RemoveSession_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams session_id_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->session_id, validation_context,
                    &session_id_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool ContentDecryptionModule_RemoveSession_ResponseParams_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const ContentDecryptionModule_RemoveSession_ResponseParams_Data* object = static_cast<const ContentDecryptionModule_RemoveSession_ResponseParams_Data*>(data);

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
                    object->result, "null result field in ContentDecryptionModule_RemoveSession_ResponseParams",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->result, validation_context))
                return false;

            return true;
        }

        // static
        bool ContentDecryptionModuleClient_OnSessionMessage_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const ContentDecryptionModuleClient_OnSessionMessage_Params_Data* object = static_cast<const ContentDecryptionModuleClient_OnSessionMessage_Params_Data*>(data);

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
                    object->session_id, "null session_id field in ContentDecryptionModuleClient_OnSessionMessage_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams session_id_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->session_id, validation_context,
                    &session_id_validate_params)) {
                return false;
            }

            if (!::media::mojom::internal::ContentDecryptionModuleClient_MessageType_Data ::Validate(object->message_type, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->message, "null message field in ContentDecryptionModuleClient_OnSessionMessage_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams message_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->message, validation_context,
                    &message_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool ContentDecryptionModuleClient_OnSessionClosed_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const ContentDecryptionModuleClient_OnSessionClosed_Params_Data* object = static_cast<const ContentDecryptionModuleClient_OnSessionClosed_Params_Data*>(data);

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
                    object->session_id, "null session_id field in ContentDecryptionModuleClient_OnSessionClosed_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams session_id_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->session_id, validation_context,
                    &session_id_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool ContentDecryptionModuleClient_OnSessionKeysChange_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const ContentDecryptionModuleClient_OnSessionKeysChange_Params_Data* object = static_cast<const ContentDecryptionModuleClient_OnSessionKeysChange_Params_Data*>(data);

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
                    object->session_id, "null session_id field in ContentDecryptionModuleClient_OnSessionKeysChange_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams session_id_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->session_id, validation_context,
                    &session_id_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->keys_info, "null keys_info field in ContentDecryptionModuleClient_OnSessionKeysChange_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams keys_info_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->keys_info, validation_context,
                    &keys_info_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool ContentDecryptionModuleClient_OnSessionExpirationUpdate_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const ContentDecryptionModuleClient_OnSessionExpirationUpdate_Params_Data* object = static_cast<const ContentDecryptionModuleClient_OnSessionExpirationUpdate_Params_Data*>(data);

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
                    object->session_id, "null session_id field in ContentDecryptionModuleClient_OnSessionExpirationUpdate_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams session_id_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->session_id, validation_context,
                    &session_id_validate_params)) {
                return false;
            }

            return true;
        }

    } // namespace internal
} // namespace mojom
} // namespace media

#if defined(_MSC_VER)
#pragma warning(pop)
#endif
