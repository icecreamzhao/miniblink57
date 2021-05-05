// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4065)
#endif

#include "mojo/common/values.mojom-shared.h"

#include <utility>

#include "base/logging.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/cpp/bindings/lib/validation_util.h"
namespace mojo {
namespace common {
    namespace mojom {

        namespace internal {
            // static
            bool Value_Data::Validate(
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

                const Value_Data* object = static_cast<const Value_Data*>(data);
                ALLOW_UNUSED_LOCAL(object);

                if (inlined && object->is_null())
                    return true;

                switch (object->tag) {

                case Value_Tag::NULL_VALUE: {

                    if (!mojo::internal::ValidateStruct(object->data.f_null_value, validation_context))
                        return false;
                    return true;
                }
                case Value_Tag::BOOL_VALUE: {

                    return true;
                }
                case Value_Tag::INT_VALUE: {

                    return true;
                }
                case Value_Tag::DOUBLE_VALUE: {

                    return true;
                }
                case Value_Tag::STRING_VALUE: {

                    if (!mojo::internal::ValidatePointerNonNullable(
                            object->data.f_string_value, "null string_value field in Value",
                            validation_context)) {
                        return false;
                    }
                    const mojo::internal::ContainerValidateParams string_value_validate_params(
                        0, false, nullptr);
                    if (!mojo::internal::ValidateContainer(object->data.f_string_value, validation_context,
                            &string_value_validate_params)) {
                        return false;
                    }
                    return true;
                }
                case Value_Tag::BINARY_VALUE: {

                    if (!mojo::internal::ValidatePointerNonNullable(
                            object->data.f_binary_value, "null binary_value field in Value",
                            validation_context)) {
                        return false;
                    }
                    const mojo::internal::ContainerValidateParams binary_value_validate_params(
                        0, false, nullptr);
                    if (!mojo::internal::ValidateContainer(object->data.f_binary_value, validation_context,
                            &binary_value_validate_params)) {
                        return false;
                    }
                    return true;
                }
                case Value_Tag::DICTIONARY_VALUE: {

                    if (!mojo::internal::ValidatePointerNonNullable(
                            object->data.f_dictionary_value, "null dictionary_value field in Value",
                            validation_context)) {
                        return false;
                    }
                    if (!mojo::internal::ValidateStruct(object->data.f_dictionary_value, validation_context))
                        return false;
                    return true;
                }
                case Value_Tag::LIST_VALUE: {

                    if (!mojo::internal::ValidatePointerNonNullable(
                            object->data.f_list_value, "null list_value field in Value",
                            validation_context)) {
                        return false;
                    }
                    if (!mojo::internal::ValidateStruct(object->data.f_list_value, validation_context))
                        return false;
                    return true;
                }
                default: {
                    ReportValidationError(
                        validation_context,
                        mojo::internal::VALIDATION_ERROR_UNKNOWN_UNION_TAG,
                        "unknown tag in Value");
                    return false;
                }
                }
            }

            // static
            bool ListValue_Data::Validate(
                const void* data,
                mojo::internal::ValidationContext* validation_context)
            {
                if (!data)
                    return true;

                if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                    return false;

                // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
                // the message comes from an older version.
                const ListValue_Data* object = static_cast<const ListValue_Data*>(data);

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
                        object->values, "null values field in ListValue",
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
            bool DictionaryValue_Data::Validate(
                const void* data,
                mojo::internal::ValidationContext* validation_context)
            {
                if (!data)
                    return true;

                if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                    return false;

                // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
                // the message comes from an older version.
                const DictionaryValue_Data* object = static_cast<const DictionaryValue_Data*>(data);

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
                        object->values, "null values field in DictionaryValue",
                        validation_context)) {
                    return false;
                }
                const mojo::internal::ContainerValidateParams values_validate_params(
                    new mojo::internal::ContainerValidateParams(0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr)), new mojo::internal::ContainerValidateParams(0, false, nullptr));
                if (!mojo::internal::ValidateContainer(object->values, validation_context,
                        &values_validate_params)) {
                    return false;
                }

                return true;
            }

            // static
            bool NullValue_Data::Validate(
                const void* data,
                mojo::internal::ValidationContext* validation_context)
            {
                if (!data)
                    return true;

                if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                    return false;

                // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
                // the message comes from an older version.
                const NullValue_Data* object = static_cast<const NullValue_Data*>(data);

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
} // namespace common
} // namespace mojo

#if defined(_MSC_VER)
#pragma warning(pop)
#endif
