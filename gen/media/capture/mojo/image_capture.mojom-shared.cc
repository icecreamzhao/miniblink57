// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4065)
#endif

#include "media/capture/mojo/image_capture.mojom-shared.h"

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
        bool Range_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Range_Data* object = static_cast<const Range_Data*>(data);

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

            return true;
        }

        // static
        bool PhotoCapabilities_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const PhotoCapabilities_Data* object = static_cast<const PhotoCapabilities_Data*>(data);

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

            if (!::media::mojom::internal::MeteringMode_Data ::Validate(object->white_balance_mode, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->color_temperature, "null color_temperature field in PhotoCapabilities",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->color_temperature, validation_context))
                return false;

            if (!::media::mojom::internal::MeteringMode_Data ::Validate(object->exposure_mode, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->exposure_compensation, "null exposure_compensation field in PhotoCapabilities",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->exposure_compensation, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->iso, "null iso field in PhotoCapabilities",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->iso, validation_context))
                return false;

            if (!::media::mojom::internal::MeteringMode_Data ::Validate(object->focus_mode, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->brightness, "null brightness field in PhotoCapabilities",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->brightness, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->contrast, "null contrast field in PhotoCapabilities",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->contrast, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->saturation, "null saturation field in PhotoCapabilities",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->saturation, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->sharpness, "null sharpness field in PhotoCapabilities",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->sharpness, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->height, "null height field in PhotoCapabilities",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->height, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->width, "null width field in PhotoCapabilities",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->width, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->zoom, "null zoom field in PhotoCapabilities",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->zoom, validation_context))
                return false;

            if (!::media::mojom::internal::FillLightMode_Data ::Validate(object->fill_light_mode, validation_context))
                return false;

            return true;
        }

        // static
        bool Point2D_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Point2D_Data* object = static_cast<const Point2D_Data*>(data);

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
        bool PhotoSettings_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const PhotoSettings_Data* object = static_cast<const PhotoSettings_Data*>(data);

            static constexpr struct {
                uint32_t version;
                uint32_t num_bytes;
            } kVersionSizes[] = { { 0, 120 } };

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

            if (!::media::mojom::internal::MeteringMode_Data ::Validate(object->white_balance_mode, validation_context))
                return false;

            if (!::media::mojom::internal::MeteringMode_Data ::Validate(object->exposure_mode, validation_context))
                return false;

            if (!::media::mojom::internal::MeteringMode_Data ::Validate(object->focus_mode, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->points_of_interest, "null points_of_interest field in PhotoSettings",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams points_of_interest_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->points_of_interest, validation_context,
                    &points_of_interest_validate_params)) {
                return false;
            }

            if (!::media::mojom::internal::FillLightMode_Data ::Validate(object->fill_light_mode, validation_context))
                return false;

            return true;
        }

        // static
        bool Blob_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Blob_Data* object = static_cast<const Blob_Data*>(data);

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
                    object->mime_type, "null mime_type field in Blob",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams mime_type_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->mime_type, validation_context,
                    &mime_type_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->data, "null data field in Blob",
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
        bool ImageCapture_GetCapabilities_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const ImageCapture_GetCapabilities_Params_Data* object = static_cast<const ImageCapture_GetCapabilities_Params_Data*>(data);

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
                    object->source_id, "null source_id field in ImageCapture_GetCapabilities_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams source_id_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->source_id, validation_context,
                    &source_id_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool ImageCapture_GetCapabilities_ResponseParams_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const ImageCapture_GetCapabilities_ResponseParams_Data* object = static_cast<const ImageCapture_GetCapabilities_ResponseParams_Data*>(data);

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
                    object->capabilities, "null capabilities field in ImageCapture_GetCapabilities_ResponseParams",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->capabilities, validation_context))
                return false;

            return true;
        }

        // static
        bool ImageCapture_SetOptions_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const ImageCapture_SetOptions_Params_Data* object = static_cast<const ImageCapture_SetOptions_Params_Data*>(data);

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
                    object->source_id, "null source_id field in ImageCapture_SetOptions_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams source_id_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->source_id, validation_context,
                    &source_id_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->settings, "null settings field in ImageCapture_SetOptions_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->settings, validation_context))
                return false;

            return true;
        }

        // static
        bool ImageCapture_SetOptions_ResponseParams_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const ImageCapture_SetOptions_ResponseParams_Data* object = static_cast<const ImageCapture_SetOptions_ResponseParams_Data*>(data);

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
        bool ImageCapture_TakePhoto_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const ImageCapture_TakePhoto_Params_Data* object = static_cast<const ImageCapture_TakePhoto_Params_Data*>(data);

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
                    object->source_id, "null source_id field in ImageCapture_TakePhoto_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams source_id_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->source_id, validation_context,
                    &source_id_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool ImageCapture_TakePhoto_ResponseParams_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const ImageCapture_TakePhoto_ResponseParams_Data* object = static_cast<const ImageCapture_TakePhoto_ResponseParams_Data*>(data);

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
                    object->blob, "null blob field in ImageCapture_TakePhoto_ResponseParams",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->blob, validation_context))
                return false;

            return true;
        }

    } // namespace internal
} // namespace mojom
} // namespace media

#if defined(_MSC_VER)
#pragma warning(pop)
#endif
