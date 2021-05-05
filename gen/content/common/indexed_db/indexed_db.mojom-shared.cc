// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4065)
#endif

#include "content/common/indexed_db/indexed_db.mojom-shared.h"

#include <utility>

#include "base/logging.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/cpp/bindings/lib/validation_util.h"
namespace indexed_db {
namespace mojom {

    namespace internal {
        // static
        bool KeyData_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context,
            bool inlined)
        {
            if (!data) {
                DCHECK(!inlined);
                return true;
            }

            // If it is inlined, the alignment is already enforced by its enclosing
            // object. We don't have to validate that.
            DCHECK(!inlined || mojo::internal::IsAligned(data));

            if (!inlined && !mojo::internal::ValidateNonInlinedUnionHeaderAndClaimMemory(data, validation_context)) {
                return false;
            }

            const KeyData_Data* object = static_cast<const KeyData_Data*>(data);
            ALLOW_UNUSED_LOCAL(object);

            if (inlined && object->is_null())
                return true;

            switch (object->tag) {

            case KeyData_Tag::KEY_ARRAY: {

                if (!mojo::internal::ValidatePointerNonNullable(
                        object->data.f_key_array, "null key_array field in KeyData",
                        validation_context)) {
                    return false;
                }
                const mojo::internal::ContainerValidateParams key_array_validate_params(
                    0, false, nullptr);
                if (!mojo::internal::ValidateContainer(object->data.f_key_array, validation_context,
                        &key_array_validate_params)) {
                    return false;
                }
                return true;
            }
            case KeyData_Tag::BINARY: {

                if (!mojo::internal::ValidatePointerNonNullable(
                        object->data.f_binary, "null binary field in KeyData",
                        validation_context)) {
                    return false;
                }
                const mojo::internal::ContainerValidateParams binary_validate_params(
                    0, false, nullptr);
                if (!mojo::internal::ValidateContainer(object->data.f_binary, validation_context,
                        &binary_validate_params)) {
                    return false;
                }
                return true;
            }
            case KeyData_Tag::STRING: {

                if (!mojo::internal::ValidatePointerNonNullable(
                        object->data.f_string, "null string field in KeyData",
                        validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateStruct(object->data.f_string, validation_context))
                    return false;
                return true;
            }
            case KeyData_Tag::DATE: {

                return true;
            }
            case KeyData_Tag::NUMBER: {

                return true;
            }
            case KeyData_Tag::OTHER: {

                if (!::indexed_db::mojom::internal::DatalessKeyType_Data ::Validate(object->data.f_other, validation_context))
                    return false;
                return true;
            }
            default: {
                ReportValidationError(
                    validation_context,
                    mojo::internal::VALIDATION_ERROR_UNKNOWN_UNION_TAG,
                    "unknown tag in KeyData");
                return false;
            }
            }
        }
        // static
        bool KeyPathData_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context,
            bool inlined)
        {
            if (!data) {
                DCHECK(!inlined);
                return true;
            }

            // If it is inlined, the alignment is already enforced by its enclosing
            // object. We don't have to validate that.
            DCHECK(!inlined || mojo::internal::IsAligned(data));

            if (!inlined && !mojo::internal::ValidateNonInlinedUnionHeaderAndClaimMemory(data, validation_context)) {
                return false;
            }

            const KeyPathData_Data* object = static_cast<const KeyPathData_Data*>(data);
            ALLOW_UNUSED_LOCAL(object);

            if (inlined && object->is_null())
                return true;

            switch (object->tag) {

            case KeyPathData_Tag::STRING: {

                if (!mojo::internal::ValidatePointerNonNullable(
                        object->data.f_string, "null string field in KeyPathData",
                        validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateStruct(object->data.f_string, validation_context))
                    return false;
                return true;
            }
            case KeyPathData_Tag::STRING_ARRAY: {

                if (!mojo::internal::ValidatePointerNonNullable(
                        object->data.f_string_array, "null string_array field in KeyPathData",
                        validation_context)) {
                    return false;
                }
                const mojo::internal::ContainerValidateParams string_array_validate_params(
                    0, false, nullptr);
                if (!mojo::internal::ValidateContainer(object->data.f_string_array, validation_context,
                        &string_array_validate_params)) {
                    return false;
                }
                return true;
            }
            default: {
                ReportValidationError(
                    validation_context,
                    mojo::internal::VALIDATION_ERROR_UNKNOWN_UNION_TAG,
                    "unknown tag in KeyPathData");
                return false;
            }
            }
        }

        // static
        bool Key_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Key_Data* object = static_cast<const Key_Data*>(data);

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

            if (!mojo::internal::ValidateInlinedUnionNonNullable(
                    object->data, "null data field in Key",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateInlinedUnion(object->data, validation_context))
                return false;

            return true;
        }

        // static
        bool KeyPath_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const KeyPath_Data* object = static_cast<const KeyPath_Data*>(data);

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

            if (!mojo::internal::ValidateInlinedUnion(object->data, validation_context))
                return false;

            return true;
        }

        // static
        bool KeyRange_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const KeyRange_Data* object = static_cast<const KeyRange_Data*>(data);

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
                    object->lower, "null lower field in KeyRange",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->lower, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->upper, "null upper field in KeyRange",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->upper, validation_context))
                return false;

            return true;
        }

        // static
        bool IndexMetadata_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const IndexMetadata_Data* object = static_cast<const IndexMetadata_Data*>(data);

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
                    object->name, "null name field in IndexMetadata",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->name, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->key_path, "null key_path field in IndexMetadata",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->key_path, validation_context))
                return false;

            return true;
        }

        // static
        bool ObjectStoreMetadata_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const ObjectStoreMetadata_Data* object = static_cast<const ObjectStoreMetadata_Data*>(data);

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
                    object->name, "null name field in ObjectStoreMetadata",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->name, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->key_path, "null key_path field in ObjectStoreMetadata",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->key_path, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->indexes, "null indexes field in ObjectStoreMetadata",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams indexes_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->indexes, validation_context,
                    &indexes_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool DatabaseMetadata_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const DatabaseMetadata_Data* object = static_cast<const DatabaseMetadata_Data*>(data);

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
                    object->name, "null name field in DatabaseMetadata",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->name, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->object_stores, "null object_stores field in DatabaseMetadata",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams object_stores_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->object_stores, validation_context,
                    &object_stores_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool IndexKeys_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const IndexKeys_Data* object = static_cast<const IndexKeys_Data*>(data);

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
                    object->index_keys, "null index_keys field in IndexKeys",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams index_keys_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->index_keys, validation_context,
                    &index_keys_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool FileInfo_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const FileInfo_Data* object = static_cast<const FileInfo_Data*>(data);

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
                    object->path, "null path field in FileInfo",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->path, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->name, "null name field in FileInfo",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->name, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->last_modified, "null last_modified field in FileInfo",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->last_modified, validation_context))
                return false;

            return true;
        }

        // static
        bool BlobInfo_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const BlobInfo_Data* object = static_cast<const BlobInfo_Data*>(data);

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
                    object->uuid, "null uuid field in BlobInfo",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams uuid_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->uuid, validation_context,
                    &uuid_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->mime_type, "null mime_type field in BlobInfo",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->mime_type, validation_context))
                return false;

            if (!mojo::internal::ValidateStruct(object->file, validation_context))
                return false;

            return true;
        }

        // static
        bool Value_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Value_Data* object = static_cast<const Value_Data*>(data);

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
                    object->bits, "null bits field in Value",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams bits_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->bits, validation_context,
                    &bits_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->blob_or_file_info, "null blob_or_file_info field in Value",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams blob_or_file_info_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->blob_or_file_info, validation_context,
                    &blob_or_file_info_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool ReturnValue_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const ReturnValue_Data* object = static_cast<const ReturnValue_Data*>(data);

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
                    object->value, "null value field in ReturnValue",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->value, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->primary_key, "null primary_key field in ReturnValue",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->primary_key, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->key_path, "null key_path field in ReturnValue",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->key_path, validation_context))
                return false;

            return true;
        }

        // static
        bool Observation_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Observation_Data* object = static_cast<const Observation_Data*>(data);

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

            if (!::indexed_db::mojom::internal::OperationType_Data ::Validate(object->type, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->key_range, "null key_range field in Observation",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->key_range, validation_context))
                return false;

            if (!mojo::internal::ValidateStruct(object->value, validation_context))
                return false;

            return true;
        }

        // static
        bool ObserverTransaction_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const ObserverTransaction_Data* object = static_cast<const ObserverTransaction_Data*>(data);

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
                    object->scope, "null scope field in ObserverTransaction",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams scope_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->scope, validation_context,
                    &scope_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool ObserverChanges_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const ObserverChanges_Data* object = static_cast<const ObserverChanges_Data*>(data);

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
                    object->observation_index_map, "null observation_index_map field in ObserverChanges",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams observation_index_map_validate_params(
                new mojo::internal::ContainerValidateParams(0, false, nullptr), new mojo::internal::ContainerValidateParams(0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr)));
            if (!mojo::internal::ValidateContainer(object->observation_index_map, validation_context,
                    &observation_index_map_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->transaction_map, "null transaction_map field in ObserverChanges",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams transaction_map_validate_params(
                new mojo::internal::ContainerValidateParams(0, false, nullptr), new mojo::internal::ContainerValidateParams(0, false, nullptr));
            if (!mojo::internal::ValidateContainer(object->transaction_map, validation_context,
                    &transaction_map_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->observations, "null observations field in ObserverChanges",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams observations_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->observations, validation_context,
                    &observations_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool Callbacks_Error_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Callbacks_Error_Params_Data* object = static_cast<const Callbacks_Error_Params_Data*>(data);

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
                    object->message, "null message field in Callbacks_Error_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->message, validation_context))
                return false;

            return true;
        }

        // static
        bool Callbacks_SuccessStringList_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Callbacks_SuccessStringList_Params_Data* object = static_cast<const Callbacks_SuccessStringList_Params_Data*>(data);

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
                    object->value, "null value field in Callbacks_SuccessStringList_Params",
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
        bool Callbacks_Blocked_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Callbacks_Blocked_Params_Data* object = static_cast<const Callbacks_Blocked_Params_Data*>(data);

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
        bool Callbacks_UpgradeNeeded_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Callbacks_UpgradeNeeded_Params_Data* object = static_cast<const Callbacks_UpgradeNeeded_Params_Data*>(data);

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

            if (!mojo::internal::ValidateHandleOrInterfaceNonNullable(
                    object->database,
                    "invalid database field in Callbacks_UpgradeNeeded_Params", validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateHandleOrInterface(object->database,
                    validation_context)) {
                return false;
            }

            if (!::indexed_db::mojom::internal::DataLoss_Data ::Validate(object->data_loss, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->data_loss_message, "null data_loss_message field in Callbacks_UpgradeNeeded_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams data_loss_message_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->data_loss_message, validation_context,
                    &data_loss_message_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->db_metadata, "null db_metadata field in Callbacks_UpgradeNeeded_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->db_metadata, validation_context))
                return false;

            return true;
        }

        // static
        bool Callbacks_SuccessDatabase_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Callbacks_SuccessDatabase_Params_Data* object = static_cast<const Callbacks_SuccessDatabase_Params_Data*>(data);

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

            if (!mojo::internal::ValidateHandleOrInterface(object->database,
                    validation_context)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->metadata, "null metadata field in Callbacks_SuccessDatabase_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->metadata, validation_context))
                return false;

            return true;
        }

        // static
        bool Callbacks_SuccessCursor_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Callbacks_SuccessCursor_Params_Data* object = static_cast<const Callbacks_SuccessCursor_Params_Data*>(data);

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
                    object->cursor,
                    "invalid cursor field in Callbacks_SuccessCursor_Params", validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateHandleOrInterface(object->cursor,
                    validation_context)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->key, "null key field in Callbacks_SuccessCursor_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->key, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->primary_key, "null primary_key field in Callbacks_SuccessCursor_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->primary_key, validation_context))
                return false;

            if (!mojo::internal::ValidateStruct(object->value, validation_context))
                return false;

            return true;
        }

        // static
        bool Callbacks_SuccessValue_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Callbacks_SuccessValue_Params_Data* object = static_cast<const Callbacks_SuccessValue_Params_Data*>(data);

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

            if (!mojo::internal::ValidateStruct(object->value, validation_context))
                return false;

            return true;
        }

        // static
        bool Callbacks_SuccessCursorContinue_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Callbacks_SuccessCursorContinue_Params_Data* object = static_cast<const Callbacks_SuccessCursorContinue_Params_Data*>(data);

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
                    object->key, "null key field in Callbacks_SuccessCursorContinue_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->key, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->primary_key, "null primary_key field in Callbacks_SuccessCursorContinue_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->primary_key, validation_context))
                return false;

            if (!mojo::internal::ValidateStruct(object->value, validation_context))
                return false;

            return true;
        }

        // static
        bool Callbacks_SuccessCursorPrefetch_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Callbacks_SuccessCursorPrefetch_Params_Data* object = static_cast<const Callbacks_SuccessCursorPrefetch_Params_Data*>(data);

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
                    object->keys, "null keys field in Callbacks_SuccessCursorPrefetch_Params",
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
                    object->primary_keys, "null primary_keys field in Callbacks_SuccessCursorPrefetch_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams primary_keys_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->primary_keys, validation_context,
                    &primary_keys_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->values, "null values field in Callbacks_SuccessCursorPrefetch_Params",
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

        // static
        bool Callbacks_SuccessArray_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Callbacks_SuccessArray_Params_Data* object = static_cast<const Callbacks_SuccessArray_Params_Data*>(data);

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
                    object->values, "null values field in Callbacks_SuccessArray_Params",
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

        // static
        bool Callbacks_SuccessKey_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Callbacks_SuccessKey_Params_Data* object = static_cast<const Callbacks_SuccessKey_Params_Data*>(data);

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
                    object->key, "null key field in Callbacks_SuccessKey_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->key, validation_context))
                return false;

            return true;
        }

        // static
        bool Callbacks_SuccessInteger_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Callbacks_SuccessInteger_Params_Data* object = static_cast<const Callbacks_SuccessInteger_Params_Data*>(data);

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
        bool Callbacks_Success_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Callbacks_Success_Params_Data* object = static_cast<const Callbacks_Success_Params_Data*>(data);

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
        bool DatabaseCallbacks_ForcedClose_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const DatabaseCallbacks_ForcedClose_Params_Data* object = static_cast<const DatabaseCallbacks_ForcedClose_Params_Data*>(data);

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
        bool DatabaseCallbacks_VersionChange_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const DatabaseCallbacks_VersionChange_Params_Data* object = static_cast<const DatabaseCallbacks_VersionChange_Params_Data*>(data);

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
        bool DatabaseCallbacks_Abort_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const DatabaseCallbacks_Abort_Params_Data* object = static_cast<const DatabaseCallbacks_Abort_Params_Data*>(data);

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
                    object->message, "null message field in DatabaseCallbacks_Abort_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->message, validation_context))
                return false;

            return true;
        }

        // static
        bool DatabaseCallbacks_Complete_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const DatabaseCallbacks_Complete_Params_Data* object = static_cast<const DatabaseCallbacks_Complete_Params_Data*>(data);

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
        bool DatabaseCallbacks_Changes_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const DatabaseCallbacks_Changes_Params_Data* object = static_cast<const DatabaseCallbacks_Changes_Params_Data*>(data);

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
                    object->changes, "null changes field in DatabaseCallbacks_Changes_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->changes, validation_context))
                return false;

            return true;
        }

        // static
        bool Cursor_Advance_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Cursor_Advance_Params_Data* object = static_cast<const Cursor_Advance_Params_Data*>(data);

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

            if (!mojo::internal::ValidateHandleOrInterfaceNonNullable(
                    object->callbacks,
                    "invalid callbacks field in Cursor_Advance_Params", validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateHandleOrInterface(object->callbacks,
                    validation_context)) {
                return false;
            }

            return true;
        }

        // static
        bool Cursor_Continue_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Cursor_Continue_Params_Data* object = static_cast<const Cursor_Continue_Params_Data*>(data);

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
                    object->key, "null key field in Cursor_Continue_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->key, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->primary_key, "null primary_key field in Cursor_Continue_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->primary_key, validation_context))
                return false;

            if (!mojo::internal::ValidateHandleOrInterfaceNonNullable(
                    object->callbacks,
                    "invalid callbacks field in Cursor_Continue_Params", validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateHandleOrInterface(object->callbacks,
                    validation_context)) {
                return false;
            }

            return true;
        }

        // static
        bool Cursor_Prefetch_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Cursor_Prefetch_Params_Data* object = static_cast<const Cursor_Prefetch_Params_Data*>(data);

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

            if (!mojo::internal::ValidateHandleOrInterfaceNonNullable(
                    object->callbacks,
                    "invalid callbacks field in Cursor_Prefetch_Params", validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateHandleOrInterface(object->callbacks,
                    validation_context)) {
                return false;
            }

            return true;
        }

        // static
        bool Cursor_PrefetchReset_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Cursor_PrefetchReset_Params_Data* object = static_cast<const Cursor_PrefetchReset_Params_Data*>(data);

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
                    object->unused_blob_uuids, "null unused_blob_uuids field in Cursor_PrefetchReset_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams unused_blob_uuids_validate_params(
                0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr));
            if (!mojo::internal::ValidateContainer(object->unused_blob_uuids, validation_context,
                    &unused_blob_uuids_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool Database_CreateObjectStore_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Database_CreateObjectStore_Params_Data* object = static_cast<const Database_CreateObjectStore_Params_Data*>(data);

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
                    object->name, "null name field in Database_CreateObjectStore_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->name, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->key_path, "null key_path field in Database_CreateObjectStore_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->key_path, validation_context))
                return false;

            return true;
        }

        // static
        bool Database_DeleteObjectStore_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Database_DeleteObjectStore_Params_Data* object = static_cast<const Database_DeleteObjectStore_Params_Data*>(data);

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
        bool Database_RenameObjectStore_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Database_RenameObjectStore_Params_Data* object = static_cast<const Database_RenameObjectStore_Params_Data*>(data);

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
                    object->new_name, "null new_name field in Database_RenameObjectStore_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->new_name, validation_context))
                return false;

            return true;
        }

        // static
        bool Database_CreateTransaction_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Database_CreateTransaction_Params_Data* object = static_cast<const Database_CreateTransaction_Params_Data*>(data);

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
                    object->object_store_ids, "null object_store_ids field in Database_CreateTransaction_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams object_store_ids_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->object_store_ids, validation_context,
                    &object_store_ids_validate_params)) {
                return false;
            }

            if (!::indexed_db::mojom::internal::TransactionMode_Data ::Validate(object->mode, validation_context))
                return false;

            return true;
        }

        // static
        bool Database_Close_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Database_Close_Params_Data* object = static_cast<const Database_Close_Params_Data*>(data);

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
        bool Database_VersionChangeIgnored_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Database_VersionChangeIgnored_Params_Data* object = static_cast<const Database_VersionChangeIgnored_Params_Data*>(data);

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
        bool Database_AddObserver_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Database_AddObserver_Params_Data* object = static_cast<const Database_AddObserver_Params_Data*>(data);

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
        bool Database_RemoveObservers_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Database_RemoveObservers_Params_Data* object = static_cast<const Database_RemoveObservers_Params_Data*>(data);

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
                    object->observers, "null observers field in Database_RemoveObservers_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams observers_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->observers, validation_context,
                    &observers_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool Database_Get_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Database_Get_Params_Data* object = static_cast<const Database_Get_Params_Data*>(data);

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
                    object->key_range, "null key_range field in Database_Get_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->key_range, validation_context))
                return false;

            if (!mojo::internal::ValidateHandleOrInterfaceNonNullable(
                    object->callbacks,
                    "invalid callbacks field in Database_Get_Params", validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateHandleOrInterface(object->callbacks,
                    validation_context)) {
                return false;
            }

            return true;
        }

        // static
        bool Database_GetAll_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Database_GetAll_Params_Data* object = static_cast<const Database_GetAll_Params_Data*>(data);

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
                    object->key_range, "null key_range field in Database_GetAll_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->key_range, validation_context))
                return false;

            if (!mojo::internal::ValidateHandleOrInterfaceNonNullable(
                    object->callbacks,
                    "invalid callbacks field in Database_GetAll_Params", validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateHandleOrInterface(object->callbacks,
                    validation_context)) {
                return false;
            }

            return true;
        }

        // static
        bool Database_Put_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Database_Put_Params_Data* object = static_cast<const Database_Put_Params_Data*>(data);

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
                    object->value, "null value field in Database_Put_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->value, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->key, "null key field in Database_Put_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->key, validation_context))
                return false;

            if (!::indexed_db::mojom::internal::PutMode_Data ::Validate(object->mode, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->index_keys, "null index_keys field in Database_Put_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams index_keys_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->index_keys, validation_context,
                    &index_keys_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidateHandleOrInterfaceNonNullable(
                    object->callbacks,
                    "invalid callbacks field in Database_Put_Params", validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateHandleOrInterface(object->callbacks,
                    validation_context)) {
                return false;
            }

            return true;
        }

        // static
        bool Database_SetIndexKeys_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Database_SetIndexKeys_Params_Data* object = static_cast<const Database_SetIndexKeys_Params_Data*>(data);

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
                    object->primary_key, "null primary_key field in Database_SetIndexKeys_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->primary_key, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->index_keys, "null index_keys field in Database_SetIndexKeys_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams index_keys_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->index_keys, validation_context,
                    &index_keys_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool Database_SetIndexesReady_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Database_SetIndexesReady_Params_Data* object = static_cast<const Database_SetIndexesReady_Params_Data*>(data);

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
                    object->index_ids, "null index_ids field in Database_SetIndexesReady_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams index_ids_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->index_ids, validation_context,
                    &index_ids_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool Database_OpenCursor_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Database_OpenCursor_Params_Data* object = static_cast<const Database_OpenCursor_Params_Data*>(data);

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
                    object->key_range, "null key_range field in Database_OpenCursor_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->key_range, validation_context))
                return false;

            if (!::indexed_db::mojom::internal::CursorDirection_Data ::Validate(object->direction, validation_context))
                return false;

            if (!::indexed_db::mojom::internal::TaskType_Data ::Validate(object->task_type, validation_context))
                return false;

            if (!mojo::internal::ValidateHandleOrInterfaceNonNullable(
                    object->callbacks,
                    "invalid callbacks field in Database_OpenCursor_Params", validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateHandleOrInterface(object->callbacks,
                    validation_context)) {
                return false;
            }

            return true;
        }

        // static
        bool Database_Count_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Database_Count_Params_Data* object = static_cast<const Database_Count_Params_Data*>(data);

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
                    object->key_range, "null key_range field in Database_Count_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->key_range, validation_context))
                return false;

            if (!mojo::internal::ValidateHandleOrInterfaceNonNullable(
                    object->callbacks,
                    "invalid callbacks field in Database_Count_Params", validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateHandleOrInterface(object->callbacks,
                    validation_context)) {
                return false;
            }

            return true;
        }

        // static
        bool Database_DeleteRange_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Database_DeleteRange_Params_Data* object = static_cast<const Database_DeleteRange_Params_Data*>(data);

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
                    object->key_range, "null key_range field in Database_DeleteRange_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->key_range, validation_context))
                return false;

            if (!mojo::internal::ValidateHandleOrInterfaceNonNullable(
                    object->callbacks,
                    "invalid callbacks field in Database_DeleteRange_Params", validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateHandleOrInterface(object->callbacks,
                    validation_context)) {
                return false;
            }

            return true;
        }

        // static
        bool Database_Clear_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Database_Clear_Params_Data* object = static_cast<const Database_Clear_Params_Data*>(data);

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

            if (!mojo::internal::ValidateHandleOrInterfaceNonNullable(
                    object->callbacks,
                    "invalid callbacks field in Database_Clear_Params", validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateHandleOrInterface(object->callbacks,
                    validation_context)) {
                return false;
            }

            return true;
        }

        // static
        bool Database_CreateIndex_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Database_CreateIndex_Params_Data* object = static_cast<const Database_CreateIndex_Params_Data*>(data);

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
                    object->name, "null name field in Database_CreateIndex_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->name, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->key_path, "null key_path field in Database_CreateIndex_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->key_path, validation_context))
                return false;

            return true;
        }

        // static
        bool Database_DeleteIndex_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Database_DeleteIndex_Params_Data* object = static_cast<const Database_DeleteIndex_Params_Data*>(data);

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

            return true;
        }

        // static
        bool Database_RenameIndex_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Database_RenameIndex_Params_Data* object = static_cast<const Database_RenameIndex_Params_Data*>(data);

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
                    object->new_name, "null new_name field in Database_RenameIndex_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->new_name, validation_context))
                return false;

            return true;
        }

        // static
        bool Database_Abort_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Database_Abort_Params_Data* object = static_cast<const Database_Abort_Params_Data*>(data);

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
        bool Database_Commit_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Database_Commit_Params_Data* object = static_cast<const Database_Commit_Params_Data*>(data);

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
        bool Database_AckReceivedBlobs_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Database_AckReceivedBlobs_Params_Data* object = static_cast<const Database_AckReceivedBlobs_Params_Data*>(data);

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
                    object->uuids, "null uuids field in Database_AckReceivedBlobs_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams uuids_validate_params(
                0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr));
            if (!mojo::internal::ValidateContainer(object->uuids, validation_context,
                    &uuids_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool Factory_GetDatabaseNames_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Factory_GetDatabaseNames_Params_Data* object = static_cast<const Factory_GetDatabaseNames_Params_Data*>(data);

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

            if (!mojo::internal::ValidateHandleOrInterfaceNonNullable(
                    object->callbacks,
                    "invalid callbacks field in Factory_GetDatabaseNames_Params", validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateHandleOrInterface(object->callbacks,
                    validation_context)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->origin, "null origin field in Factory_GetDatabaseNames_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->origin, validation_context))
                return false;

            return true;
        }

        // static
        bool Factory_Open_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Factory_Open_Params_Data* object = static_cast<const Factory_Open_Params_Data*>(data);

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

            if (!mojo::internal::ValidateHandleOrInterfaceNonNullable(
                    object->callbacks,
                    "invalid callbacks field in Factory_Open_Params", validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateHandleOrInterface(object->callbacks,
                    validation_context)) {
                return false;
            }

            if (!mojo::internal::ValidateHandleOrInterfaceNonNullable(
                    object->database_callbacks,
                    "invalid database_callbacks field in Factory_Open_Params", validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateHandleOrInterface(object->database_callbacks,
                    validation_context)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->origin, "null origin field in Factory_Open_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->origin, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->name, "null name field in Factory_Open_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->name, validation_context))
                return false;

            return true;
        }

        // static
        bool Factory_DeleteDatabase_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Factory_DeleteDatabase_Params_Data* object = static_cast<const Factory_DeleteDatabase_Params_Data*>(data);

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

            if (!mojo::internal::ValidateHandleOrInterfaceNonNullable(
                    object->callbacks,
                    "invalid callbacks field in Factory_DeleteDatabase_Params", validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateHandleOrInterface(object->callbacks,
                    validation_context)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->origin, "null origin field in Factory_DeleteDatabase_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->origin, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->name, "null name field in Factory_DeleteDatabase_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->name, validation_context))
                return false;

            return true;
        }

    } // namespace internal
} // namespace mojom
} // namespace indexed_db

#if defined(_MSC_VER)
#pragma warning(pop)
#endif
