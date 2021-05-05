// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4065)
#endif

#include "services/video_capture/public/interfaces/device_descriptor.mojom-shared.h"

#include <utility>

#include "base/logging.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/cpp/bindings/lib/validation_util.h"
namespace video_capture {
namespace mojom {

    namespace internal {

        // static
        bool DeviceDescriptor_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const DeviceDescriptor_Data* object = static_cast<const DeviceDescriptor_Data*>(data);

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
                    object->display_name, "null display_name field in DeviceDescriptor",
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
                    object->device_id, "null device_id field in DeviceDescriptor",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams device_id_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->device_id, validation_context,
                    &device_id_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->model_id, "null model_id field in DeviceDescriptor",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams model_id_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->model_id, validation_context,
                    &model_id_validate_params)) {
                return false;
            }

            if (!::video_capture::mojom::internal::VideoCaptureApi_Data ::Validate(object->capture_api, validation_context))
                return false;

            if (!::video_capture::mojom::internal::VideoCaptureTransportType_Data ::Validate(object->transport_type, validation_context))
                return false;

            return true;
        }

    } // namespace internal
} // namespace mojom
} // namespace video_capture

#if defined(_MSC_VER)
#pragma warning(pop)
#endif
