// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4065)
#endif

#include "device/generic_sensor/public/interfaces/sensor.mojom-shared.h"

#include <utility>

#include "base/logging.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/cpp/bindings/lib/validation_util.h"
namespace device {
namespace mojom {

    namespace internal {

        // static
        bool SensorConfiguration_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const SensorConfiguration_Data* object = static_cast<const SensorConfiguration_Data*>(data);

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
        bool Sensor_GetDefaultConfiguration_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Sensor_GetDefaultConfiguration_Params_Data* object = static_cast<const Sensor_GetDefaultConfiguration_Params_Data*>(data);

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
        bool Sensor_GetDefaultConfiguration_ResponseParams_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Sensor_GetDefaultConfiguration_ResponseParams_Data* object = static_cast<const Sensor_GetDefaultConfiguration_ResponseParams_Data*>(data);

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
                    object->configuration, "null configuration field in Sensor_GetDefaultConfiguration_ResponseParams",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->configuration, validation_context))
                return false;

            return true;
        }

        // static
        bool Sensor_AddConfiguration_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Sensor_AddConfiguration_Params_Data* object = static_cast<const Sensor_AddConfiguration_Params_Data*>(data);

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
                    object->configuration, "null configuration field in Sensor_AddConfiguration_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->configuration, validation_context))
                return false;

            return true;
        }

        // static
        bool Sensor_AddConfiguration_ResponseParams_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Sensor_AddConfiguration_ResponseParams_Data* object = static_cast<const Sensor_AddConfiguration_ResponseParams_Data*>(data);

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
        bool Sensor_RemoveConfiguration_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Sensor_RemoveConfiguration_Params_Data* object = static_cast<const Sensor_RemoveConfiguration_Params_Data*>(data);

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
                    object->configuration, "null configuration field in Sensor_RemoveConfiguration_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->configuration, validation_context))
                return false;

            return true;
        }

        // static
        bool Sensor_RemoveConfiguration_ResponseParams_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Sensor_RemoveConfiguration_ResponseParams_Data* object = static_cast<const Sensor_RemoveConfiguration_ResponseParams_Data*>(data);

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
        bool Sensor_Suspend_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Sensor_Suspend_Params_Data* object = static_cast<const Sensor_Suspend_Params_Data*>(data);

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
        bool Sensor_Resume_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Sensor_Resume_Params_Data* object = static_cast<const Sensor_Resume_Params_Data*>(data);

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
        bool SensorClient_RaiseError_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const SensorClient_RaiseError_Params_Data* object = static_cast<const SensorClient_RaiseError_Params_Data*>(data);

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
        bool SensorClient_SensorReadingChanged_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const SensorClient_SensorReadingChanged_Params_Data* object = static_cast<const SensorClient_SensorReadingChanged_Params_Data*>(data);

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
} // namespace device

#if defined(_MSC_VER)
#pragma warning(pop)
#endif
