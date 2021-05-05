// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4065)
#endif

#include "services/service_manager/public/interfaces/connector.mojom-shared.h"

#include <utility>

#include "base/logging.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/cpp/bindings/lib/validation_util.h"
namespace service_manager {
namespace mojom {

    namespace internal {

        // static
        bool Identity_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Identity_Data* object = static_cast<const Identity_Data*>(data);

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
                    object->name, "null name field in Identity",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams name_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->name, validation_context,
                    &name_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->user_id, "null user_id field in Identity",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams user_id_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->user_id, validation_context,
                    &user_id_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->instance, "null instance field in Identity",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams instance_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->instance, validation_context,
                    &instance_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool PIDReceiver_SetPID_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const PIDReceiver_SetPID_Params_Data* object = static_cast<const PIDReceiver_SetPID_Params_Data*>(data);

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
        bool Connector_StartService_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Connector_StartService_Params_Data* object = static_cast<const Connector_StartService_Params_Data*>(data);

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
                    object->name, "null name field in Connector_StartService_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->name, validation_context))
                return false;

            if (!mojo::internal::ValidateHandleOrInterfaceNonNullable(
                    object->service,
                    "invalid service field in Connector_StartService_Params", validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateHandleOrInterface(object->service,
                    validation_context)) {
                return false;
            }

            if (!mojo::internal::ValidateHandleOrInterfaceNonNullable(
                    object->pid_receiver_request,
                    "invalid pid_receiver_request field in Connector_StartService_Params", validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateHandleOrInterface(object->pid_receiver_request,
                    validation_context)) {
                return false;
            }

            return true;
        }

        // static
        bool Connector_Connect_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Connector_Connect_Params_Data* object = static_cast<const Connector_Connect_Params_Data*>(data);

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
                    object->target, "null target field in Connector_Connect_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->target, validation_context))
                return false;

            if (!mojo::internal::ValidateHandleOrInterface(object->remote_interfaces,
                    validation_context)) {
                return false;
            }

            return true;
        }

        // static
        bool Connector_Connect_ResponseParams_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Connector_Connect_ResponseParams_Data* object = static_cast<const Connector_Connect_ResponseParams_Data*>(data);

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

            if (!::service_manager::mojom::internal::ConnectResult_Data ::Validate(object->result, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->user_id, "null user_id field in Connector_Connect_ResponseParams",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams user_id_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->user_id, validation_context,
                    &user_id_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool Connector_BindInterface_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Connector_BindInterface_Params_Data* object = static_cast<const Connector_BindInterface_Params_Data*>(data);

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
                    object->target, "null target field in Connector_BindInterface_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->target, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->interface_name, "null interface_name field in Connector_BindInterface_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams interface_name_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->interface_name, validation_context,
                    &interface_name_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidateHandleOrInterfaceNonNullable(
                    object->interface_pipe,
                    "invalid interface_pipe field in Connector_BindInterface_Params", validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateHandleOrInterface(object->interface_pipe,
                    validation_context)) {
                return false;
            }

            return true;
        }

        // static
        bool Connector_BindInterface_ResponseParams_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Connector_BindInterface_ResponseParams_Data* object = static_cast<const Connector_BindInterface_ResponseParams_Data*>(data);

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

            if (!::service_manager::mojom::internal::ConnectResult_Data ::Validate(object->result, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->user_id, "null user_id field in Connector_BindInterface_ResponseParams",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams user_id_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->user_id, validation_context,
                    &user_id_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool Connector_Clone_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Connector_Clone_Params_Data* object = static_cast<const Connector_Clone_Params_Data*>(data);

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
                    object->request,
                    "invalid request field in Connector_Clone_Params", validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateHandleOrInterface(object->request,
                    validation_context)) {
                return false;
            }

            return true;
        }

    } // namespace internal
} // namespace mojom
} // namespace service_manager

#if defined(_MSC_VER)
#pragma warning(pop)
#endif
