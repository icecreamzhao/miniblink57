// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4065)
#endif

#include "device/nfc/nfc.mojom-shared.h"

#include <utility>

#include "base/logging.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/cpp/bindings/lib/validation_util.h"
namespace device {
namespace nfc {
    namespace mojom {

        namespace internal {

            // static
            bool NFCError_Data::Validate(
                const void* data,
                mojo::internal::ValidationContext* validation_context)
            {
                if (!data)
                    return true;

                if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                    return false;

                // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
                // the message comes from an older version.
                const NFCError_Data* object = static_cast<const NFCError_Data*>(data);

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

                if (!::device::nfc::mojom::internal::NFCErrorType_Data ::Validate(object->error_type, validation_context))
                    return false;

                return true;
            }

            // static
            bool NFCRecord_Data::Validate(
                const void* data,
                mojo::internal::ValidationContext* validation_context)
            {
                if (!data)
                    return true;

                if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                    return false;

                // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
                // the message comes from an older version.
                const NFCRecord_Data* object = static_cast<const NFCRecord_Data*>(data);

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

                if (!::device::nfc::mojom::internal::NFCRecordType_Data ::Validate(object->record_type, validation_context))
                    return false;

                const mojo::internal::ContainerValidateParams media_type_validate_params(
                    0, false, nullptr);
                if (!mojo::internal::ValidateContainer(object->media_type, validation_context,
                        &media_type_validate_params)) {
                    return false;
                }

                if (!mojo::internal::ValidatePointerNonNullable(
                        object->data, "null data field in NFCRecord",
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

            // static
            bool NFCMessage_Data::Validate(
                const void* data,
                mojo::internal::ValidationContext* validation_context)
            {
                if (!data)
                    return true;

                if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                    return false;

                // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
                // the message comes from an older version.
                const NFCMessage_Data* object = static_cast<const NFCMessage_Data*>(data);

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
                        object->data, "null data field in NFCMessage",
                        validation_context)) {
                    return false;
                }
                const mojo::internal::ContainerValidateParams data_validate_params(
                    0, false, nullptr);
                if (!mojo::internal::ValidateContainer(object->data, validation_context,
                        &data_validate_params)) {
                    return false;
                }

                const mojo::internal::ContainerValidateParams url_validate_params(
                    0, false, nullptr);
                if (!mojo::internal::ValidateContainer(object->url, validation_context,
                        &url_validate_params)) {
                    return false;
                }

                return true;
            }

            // static
            bool NFCPushOptions_Data::Validate(
                const void* data,
                mojo::internal::ValidationContext* validation_context)
            {
                if (!data)
                    return true;

                if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                    return false;

                // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
                // the message comes from an older version.
                const NFCPushOptions_Data* object = static_cast<const NFCPushOptions_Data*>(data);

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

                if (!::device::nfc::mojom::internal::NFCPushTarget_Data ::Validate(object->target, validation_context))
                    return false;

                return true;
            }

            // static
            bool NFCRecordTypeFilter_Data::Validate(
                const void* data,
                mojo::internal::ValidationContext* validation_context)
            {
                if (!data)
                    return true;

                if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                    return false;

                // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
                // the message comes from an older version.
                const NFCRecordTypeFilter_Data* object = static_cast<const NFCRecordTypeFilter_Data*>(data);

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

                if (!::device::nfc::mojom::internal::NFCRecordType_Data ::Validate(object->record_type, validation_context))
                    return false;

                return true;
            }

            // static
            bool NFCWatchOptions_Data::Validate(
                const void* data,
                mojo::internal::ValidationContext* validation_context)
            {
                if (!data)
                    return true;

                if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                    return false;

                // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
                // the message comes from an older version.
                const NFCWatchOptions_Data* object = static_cast<const NFCWatchOptions_Data*>(data);

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

                const mojo::internal::ContainerValidateParams url_validate_params(
                    0, false, nullptr);
                if (!mojo::internal::ValidateContainer(object->url, validation_context,
                        &url_validate_params)) {
                    return false;
                }

                if (!mojo::internal::ValidateStruct(object->record_filter, validation_context))
                    return false;

                const mojo::internal::ContainerValidateParams media_type_validate_params(
                    0, false, nullptr);
                if (!mojo::internal::ValidateContainer(object->media_type, validation_context,
                        &media_type_validate_params)) {
                    return false;
                }

                if (!::device::nfc::mojom::internal::NFCWatchMode_Data ::Validate(object->mode, validation_context))
                    return false;

                return true;
            }

            // static
            bool NFC_SetClient_Params_Data::Validate(
                const void* data,
                mojo::internal::ValidationContext* validation_context)
            {
                if (!data)
                    return true;

                if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                    return false;

                // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
                // the message comes from an older version.
                const NFC_SetClient_Params_Data* object = static_cast<const NFC_SetClient_Params_Data*>(data);

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
                        "invalid client field in NFC_SetClient_Params", validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateHandleOrInterface(object->client,
                        validation_context)) {
                    return false;
                }

                return true;
            }

            // static
            bool NFC_Push_Params_Data::Validate(
                const void* data,
                mojo::internal::ValidationContext* validation_context)
            {
                if (!data)
                    return true;

                if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                    return false;

                // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
                // the message comes from an older version.
                const NFC_Push_Params_Data* object = static_cast<const NFC_Push_Params_Data*>(data);

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
                        object->message, "null message field in NFC_Push_Params",
                        validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateStruct(object->message, validation_context))
                    return false;

                if (!mojo::internal::ValidateStruct(object->options, validation_context))
                    return false;

                return true;
            }

            // static
            bool NFC_Push_ResponseParams_Data::Validate(
                const void* data,
                mojo::internal::ValidationContext* validation_context)
            {
                if (!data)
                    return true;

                if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                    return false;

                // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
                // the message comes from an older version.
                const NFC_Push_ResponseParams_Data* object = static_cast<const NFC_Push_ResponseParams_Data*>(data);

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

                if (!mojo::internal::ValidateStruct(object->error, validation_context))
                    return false;

                return true;
            }

            // static
            bool NFC_CancelPush_Params_Data::Validate(
                const void* data,
                mojo::internal::ValidationContext* validation_context)
            {
                if (!data)
                    return true;

                if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                    return false;

                // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
                // the message comes from an older version.
                const NFC_CancelPush_Params_Data* object = static_cast<const NFC_CancelPush_Params_Data*>(data);

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

                if (!::device::nfc::mojom::internal::NFCPushTarget_Data ::Validate(object->target, validation_context))
                    return false;

                return true;
            }

            // static
            bool NFC_CancelPush_ResponseParams_Data::Validate(
                const void* data,
                mojo::internal::ValidationContext* validation_context)
            {
                if (!data)
                    return true;

                if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                    return false;

                // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
                // the message comes from an older version.
                const NFC_CancelPush_ResponseParams_Data* object = static_cast<const NFC_CancelPush_ResponseParams_Data*>(data);

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

                if (!mojo::internal::ValidateStruct(object->error, validation_context))
                    return false;

                return true;
            }

            // static
            bool NFC_Watch_Params_Data::Validate(
                const void* data,
                mojo::internal::ValidationContext* validation_context)
            {
                if (!data)
                    return true;

                if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                    return false;

                // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
                // the message comes from an older version.
                const NFC_Watch_Params_Data* object = static_cast<const NFC_Watch_Params_Data*>(data);

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
                        object->options, "null options field in NFC_Watch_Params",
                        validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateStruct(object->options, validation_context))
                    return false;

                return true;
            }

            // static
            bool NFC_Watch_ResponseParams_Data::Validate(
                const void* data,
                mojo::internal::ValidationContext* validation_context)
            {
                if (!data)
                    return true;

                if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                    return false;

                // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
                // the message comes from an older version.
                const NFC_Watch_ResponseParams_Data* object = static_cast<const NFC_Watch_ResponseParams_Data*>(data);

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

                if (!mojo::internal::ValidateStruct(object->error, validation_context))
                    return false;

                return true;
            }

            // static
            bool NFC_CancelWatch_Params_Data::Validate(
                const void* data,
                mojo::internal::ValidationContext* validation_context)
            {
                if (!data)
                    return true;

                if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                    return false;

                // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
                // the message comes from an older version.
                const NFC_CancelWatch_Params_Data* object = static_cast<const NFC_CancelWatch_Params_Data*>(data);

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
            bool NFC_CancelWatch_ResponseParams_Data::Validate(
                const void* data,
                mojo::internal::ValidationContext* validation_context)
            {
                if (!data)
                    return true;

                if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                    return false;

                // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
                // the message comes from an older version.
                const NFC_CancelWatch_ResponseParams_Data* object = static_cast<const NFC_CancelWatch_ResponseParams_Data*>(data);

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

                if (!mojo::internal::ValidateStruct(object->error, validation_context))
                    return false;

                return true;
            }

            // static
            bool NFC_CancelAllWatches_Params_Data::Validate(
                const void* data,
                mojo::internal::ValidationContext* validation_context)
            {
                if (!data)
                    return true;

                if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                    return false;

                // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
                // the message comes from an older version.
                const NFC_CancelAllWatches_Params_Data* object = static_cast<const NFC_CancelAllWatches_Params_Data*>(data);

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
            bool NFC_CancelAllWatches_ResponseParams_Data::Validate(
                const void* data,
                mojo::internal::ValidationContext* validation_context)
            {
                if (!data)
                    return true;

                if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                    return false;

                // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
                // the message comes from an older version.
                const NFC_CancelAllWatches_ResponseParams_Data* object = static_cast<const NFC_CancelAllWatches_ResponseParams_Data*>(data);

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

                if (!mojo::internal::ValidateStruct(object->error, validation_context))
                    return false;

                return true;
            }

            // static
            bool NFC_SuspendNFCOperations_Params_Data::Validate(
                const void* data,
                mojo::internal::ValidationContext* validation_context)
            {
                if (!data)
                    return true;

                if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                    return false;

                // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
                // the message comes from an older version.
                const NFC_SuspendNFCOperations_Params_Data* object = static_cast<const NFC_SuspendNFCOperations_Params_Data*>(data);

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
            bool NFC_ResumeNFCOperations_Params_Data::Validate(
                const void* data,
                mojo::internal::ValidationContext* validation_context)
            {
                if (!data)
                    return true;

                if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                    return false;

                // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
                // the message comes from an older version.
                const NFC_ResumeNFCOperations_Params_Data* object = static_cast<const NFC_ResumeNFCOperations_Params_Data*>(data);

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
            bool NFCClient_OnWatch_Params_Data::Validate(
                const void* data,
                mojo::internal::ValidationContext* validation_context)
            {
                if (!data)
                    return true;

                if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                    return false;

                // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
                // the message comes from an older version.
                const NFCClient_OnWatch_Params_Data* object = static_cast<const NFCClient_OnWatch_Params_Data*>(data);

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
                        object->watch_ids, "null watch_ids field in NFCClient_OnWatch_Params",
                        validation_context)) {
                    return false;
                }
                const mojo::internal::ContainerValidateParams watch_ids_validate_params(
                    0, false, nullptr);
                if (!mojo::internal::ValidateContainer(object->watch_ids, validation_context,
                        &watch_ids_validate_params)) {
                    return false;
                }

                if (!mojo::internal::ValidatePointerNonNullable(
                        object->message, "null message field in NFCClient_OnWatch_Params",
                        validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateStruct(object->message, validation_context))
                    return false;

                return true;
            }

        } // namespace internal
    } // namespace mojom
} // namespace nfc
} // namespace device

#if defined(_MSC_VER)
#pragma warning(pop)
#endif
