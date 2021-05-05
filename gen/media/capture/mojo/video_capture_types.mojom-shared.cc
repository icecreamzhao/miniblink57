// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4065)
#endif

#include "media/capture/mojo/video_capture_types.mojom-shared.h"

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
        bool VideoCaptureFormat_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const VideoCaptureFormat_Data* object = static_cast<const VideoCaptureFormat_Data*>(data);

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
                    object->frame_size, "null frame_size field in VideoCaptureFormat",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->frame_size, validation_context))
                return false;

            if (!::media::mojom::internal::VideoPixelFormat_Data ::Validate(object->pixel_format, validation_context))
                return false;

            if (!::media::mojom::internal::VideoPixelStorage_Data ::Validate(object->pixel_storage, validation_context))
                return false;

            return true;
        }

        // static
        bool VideoCaptureParams_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const VideoCaptureParams_Data* object = static_cast<const VideoCaptureParams_Data*>(data);

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
                    object->requested_format, "null requested_format field in VideoCaptureParams",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->requested_format, validation_context))
                return false;

            if (!::media::mojom::internal::ResolutionChangePolicy_Data ::Validate(object->resolution_change_policy, validation_context))
                return false;

            if (!::media::mojom::internal::PowerLineFrequency_Data ::Validate(object->power_line_frequency, validation_context))
                return false;

            return true;
        }

        // static
        bool VideoFrameInfo_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const VideoFrameInfo_Data* object = static_cast<const VideoFrameInfo_Data*>(data);

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
                    object->timestamp, "null timestamp field in VideoFrameInfo",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->timestamp, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->metadata, "null metadata field in VideoFrameInfo",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->metadata, validation_context))
                return false;

            if (!::media::mojom::internal::VideoPixelFormat_Data ::Validate(object->pixel_format, validation_context))
                return false;

            if (!::media::mojom::internal::VideoPixelStorage_Data ::Validate(object->storage_type, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->coded_size, "null coded_size field in VideoFrameInfo",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->coded_size, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->visible_rect, "null visible_rect field in VideoFrameInfo",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->visible_rect, validation_context))
                return false;

            return true;
        }

    } // namespace internal
} // namespace mojom
} // namespace media

#if defined(_MSC_VER)
#pragma warning(pop)
#endif
