// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4065)
#endif

#include "content/common/leveldb_wrapper.mojom-shared.h"

#include <utility>

#include "base/logging.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/cpp/bindings/lib/validation_util.h"
namespace content {
namespace mojom {

    namespace internal {

        // static
        bool KeyValue_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const KeyValue_Data* object = static_cast<const KeyValue_Data*>(data);

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
                    object->key, "null key field in KeyValue",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams key_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->key, validation_context,
                    &key_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->value, "null value field in KeyValue",
                    validation_context)) {
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
        bool LevelDBObserver_KeyAdded_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const LevelDBObserver_KeyAdded_Params_Data* object = static_cast<const LevelDBObserver_KeyAdded_Params_Data*>(data);

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
                    object->key, "null key field in LevelDBObserver_KeyAdded_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams key_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->key, validation_context,
                    &key_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->value, "null value field in LevelDBObserver_KeyAdded_Params",
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
                    object->source, "null source field in LevelDBObserver_KeyAdded_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams source_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->source, validation_context,
                    &source_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool LevelDBObserver_KeyChanged_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const LevelDBObserver_KeyChanged_Params_Data* object = static_cast<const LevelDBObserver_KeyChanged_Params_Data*>(data);

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
                    object->key, "null key field in LevelDBObserver_KeyChanged_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams key_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->key, validation_context,
                    &key_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->new_value, "null new_value field in LevelDBObserver_KeyChanged_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams new_value_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->new_value, validation_context,
                    &new_value_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->old_value, "null old_value field in LevelDBObserver_KeyChanged_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams old_value_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->old_value, validation_context,
                    &old_value_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->source, "null source field in LevelDBObserver_KeyChanged_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams source_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->source, validation_context,
                    &source_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool LevelDBObserver_KeyDeleted_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const LevelDBObserver_KeyDeleted_Params_Data* object = static_cast<const LevelDBObserver_KeyDeleted_Params_Data*>(data);

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
                    object->key, "null key field in LevelDBObserver_KeyDeleted_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams key_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->key, validation_context,
                    &key_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->old_value, "null old_value field in LevelDBObserver_KeyDeleted_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams old_value_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->old_value, validation_context,
                    &old_value_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->source, "null source field in LevelDBObserver_KeyDeleted_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams source_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->source, validation_context,
                    &source_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool LevelDBObserver_AllDeleted_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const LevelDBObserver_AllDeleted_Params_Data* object = static_cast<const LevelDBObserver_AllDeleted_Params_Data*>(data);

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
                    object->source, "null source field in LevelDBObserver_AllDeleted_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams source_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->source, validation_context,
                    &source_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool LevelDBWrapperGetAllCallback_Complete_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const LevelDBWrapperGetAllCallback_Complete_Params_Data* object = static_cast<const LevelDBWrapperGetAllCallback_Complete_Params_Data*>(data);

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
        bool LevelDBWrapper_AddObserver_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const LevelDBWrapper_AddObserver_Params_Data* object = static_cast<const LevelDBWrapper_AddObserver_Params_Data*>(data);

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
                    object->observer,
                    "invalid observer field in LevelDBWrapper_AddObserver_Params", validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateHandleOrInterface(object->observer,
                    validation_context)) {
                return false;
            }

            return true;
        }

        // static
        bool LevelDBWrapper_Put_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const LevelDBWrapper_Put_Params_Data* object = static_cast<const LevelDBWrapper_Put_Params_Data*>(data);

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
                    object->key, "null key field in LevelDBWrapper_Put_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams key_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->key, validation_context,
                    &key_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->value, "null value field in LevelDBWrapper_Put_Params",
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
                    object->source, "null source field in LevelDBWrapper_Put_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams source_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->source, validation_context,
                    &source_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool LevelDBWrapper_Put_ResponseParams_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const LevelDBWrapper_Put_ResponseParams_Data* object = static_cast<const LevelDBWrapper_Put_ResponseParams_Data*>(data);

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
        bool LevelDBWrapper_Delete_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const LevelDBWrapper_Delete_Params_Data* object = static_cast<const LevelDBWrapper_Delete_Params_Data*>(data);

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
                    object->key, "null key field in LevelDBWrapper_Delete_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams key_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->key, validation_context,
                    &key_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->source, "null source field in LevelDBWrapper_Delete_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams source_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->source, validation_context,
                    &source_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool LevelDBWrapper_Delete_ResponseParams_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const LevelDBWrapper_Delete_ResponseParams_Data* object = static_cast<const LevelDBWrapper_Delete_ResponseParams_Data*>(data);

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
        bool LevelDBWrapper_DeleteAll_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const LevelDBWrapper_DeleteAll_Params_Data* object = static_cast<const LevelDBWrapper_DeleteAll_Params_Data*>(data);

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
                    object->source, "null source field in LevelDBWrapper_DeleteAll_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams source_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->source, validation_context,
                    &source_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool LevelDBWrapper_DeleteAll_ResponseParams_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const LevelDBWrapper_DeleteAll_ResponseParams_Data* object = static_cast<const LevelDBWrapper_DeleteAll_ResponseParams_Data*>(data);

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
        bool LevelDBWrapper_Get_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const LevelDBWrapper_Get_Params_Data* object = static_cast<const LevelDBWrapper_Get_Params_Data*>(data);

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
                    object->key, "null key field in LevelDBWrapper_Get_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams key_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->key, validation_context,
                    &key_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool LevelDBWrapper_Get_ResponseParams_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const LevelDBWrapper_Get_ResponseParams_Data* object = static_cast<const LevelDBWrapper_Get_ResponseParams_Data*>(data);

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
                    object->value, "null value field in LevelDBWrapper_Get_ResponseParams",
                    validation_context)) {
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
        bool LevelDBWrapper_GetAll_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const LevelDBWrapper_GetAll_Params_Data* object = static_cast<const LevelDBWrapper_GetAll_Params_Data*>(data);

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
                    object->complete_callback,
                    "invalid complete_callback field in LevelDBWrapper_GetAll_Params", validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateHandleOrInterface(object->complete_callback,
                    validation_context)) {
                return false;
            }

            return true;
        }

        // static
        bool LevelDBWrapper_GetAll_ResponseParams_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const LevelDBWrapper_GetAll_ResponseParams_Data* object = static_cast<const LevelDBWrapper_GetAll_ResponseParams_Data*>(data);

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

            if (!::leveldb::mojom::internal::DatabaseError_Data ::Validate(object->status, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->data, "null data field in LevelDBWrapper_GetAll_ResponseParams",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams data_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->data, validation_context,
                    &data_validate_params)) {
                return false;
            }

            return true;
        }

    } // namespace internal
} // namespace mojom
} // namespace content

#if defined(_MSC_VER)
#pragma warning(pop)
#endif
