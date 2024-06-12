// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4065)
#endif

#include "content/common/media/media_devices.mojom-shared.h"

#include <utility>

#include "base/logging.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/cpp/bindings/lib/validation_util.h"
namespace mojom {

namespace internal {

    // static
    bool MediaDevicesDispatcherHost_EnumerateDevices_Params_Data::Validate(
        const void* data,
        mojo::internal::ValidationContext* validation_context)
    {
        if (!data)
            return true;

        if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
            return false;

        // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
        // the message comes from an older version.
        const MediaDevicesDispatcherHost_EnumerateDevices_Params_Data* object = static_cast<const MediaDevicesDispatcherHost_EnumerateDevices_Params_Data*>(data);

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
                object->security_origin, "null security_origin field in MediaDevicesDispatcherHost_EnumerateDevices_Params",
                validation_context)) {
            return false;
        }
        if (!mojo::internal::ValidateStruct(object->security_origin, validation_context))
            return false;

        return true;
    }

    // static
    bool MediaDevicesDispatcherHost_EnumerateDevices_ResponseParams_Data::Validate(
        const void* data,
        mojo::internal::ValidationContext* validation_context)
    {
        if (!data)
            return true;

        if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
            return false;

        // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
        // the message comes from an older version.
        const MediaDevicesDispatcherHost_EnumerateDevices_ResponseParams_Data* object = static_cast<const MediaDevicesDispatcherHost_EnumerateDevices_ResponseParams_Data*>(data);

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
                object->enumeration, "null enumeration field in MediaDevicesDispatcherHost_EnumerateDevices_ResponseParams",
                validation_context)) {
            return false;
        }
        const mojo::internal::ContainerValidateParams enumeration_validate_params(
            0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr));
        if (!mojo::internal::ValidateContainer(object->enumeration, validation_context,
                &enumeration_validate_params)) {
            return false;
        }

        return true;
    }

    // static
    bool MediaDevicesDispatcherHost_SubscribeDeviceChangeNotifications_Params_Data::Validate(
        const void* data,
        mojo::internal::ValidationContext* validation_context)
    {
        if (!data)
            return true;

        if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
            return false;

        // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
        // the message comes from an older version.
        const MediaDevicesDispatcherHost_SubscribeDeviceChangeNotifications_Params_Data* object = static_cast<const MediaDevicesDispatcherHost_SubscribeDeviceChangeNotifications_Params_Data*>(data);

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

        if (!::mojom::internal::MediaDeviceType_Data ::Validate(object->type, validation_context))
            return false;

        if (!mojo::internal::ValidatePointerNonNullable(
                object->security_origin, "null security_origin field in MediaDevicesDispatcherHost_SubscribeDeviceChangeNotifications_Params",
                validation_context)) {
            return false;
        }
        if (!mojo::internal::ValidateStruct(object->security_origin, validation_context))
            return false;

        return true;
    }

    // static
    bool MediaDevicesDispatcherHost_UnsubscribeDeviceChangeNotifications_Params_Data::Validate(
        const void* data,
        mojo::internal::ValidationContext* validation_context)
    {
        if (!data)
            return true;

        if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
            return false;

        // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
        // the message comes from an older version.
        const MediaDevicesDispatcherHost_UnsubscribeDeviceChangeNotifications_Params_Data* object = static_cast<const MediaDevicesDispatcherHost_UnsubscribeDeviceChangeNotifications_Params_Data*>(data);

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

        if (!::mojom::internal::MediaDeviceType_Data ::Validate(object->type, validation_context))
            return false;

        return true;
    }

    // static
    bool MediaDevicesListener_OnDevicesChanged_Params_Data::Validate(
        const void* data,
        mojo::internal::ValidationContext* validation_context)
    {
        if (!data)
            return true;

        if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
            return false;

        // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
        // the message comes from an older version.
        const MediaDevicesListener_OnDevicesChanged_Params_Data* object = static_cast<const MediaDevicesListener_OnDevicesChanged_Params_Data*>(data);

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

        if (!::mojom::internal::MediaDeviceType_Data ::Validate(object->type, validation_context))
            return false;

        if (!mojo::internal::ValidatePointerNonNullable(
                object->device_infos, "null device_infos field in MediaDevicesListener_OnDevicesChanged_Params",
                validation_context)) {
            return false;
        }
        const mojo::internal::ContainerValidateParams device_infos_validate_params(
            0, false, nullptr);
        if (!mojo::internal::ValidateContainer(object->device_infos, validation_context,
                &device_infos_validate_params)) {
            return false;
        }

        return true;
    }

} // namespace internal
} // namespace mojom

#if defined(_MSC_VER)
#pragma warning(pop)
#endif
