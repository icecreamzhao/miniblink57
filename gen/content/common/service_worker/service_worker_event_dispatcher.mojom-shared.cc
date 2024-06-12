// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4065)
#endif

#include "content/common/service_worker/service_worker_event_dispatcher.mojom-shared.h"

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
        bool FetchEventPreloadHandle_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const FetchEventPreloadHandle_Data* object = static_cast<const FetchEventPreloadHandle_Data*>(data);

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
                    object->url_loader,
                    "invalid url_loader field in FetchEventPreloadHandle", validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateHandleOrInterface(object->url_loader,
                    validation_context)) {
                return false;
            }

            if (!mojo::internal::ValidateHandleOrInterfaceNonNullable(
                    object->url_loader_client_request,
                    "invalid url_loader_client_request field in FetchEventPreloadHandle", validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateHandleOrInterface(object->url_loader_client_request,
                    validation_context)) {
                return false;
            }

            return true;
        }

        // static
        bool ExtendableMessageEvent_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const ExtendableMessageEvent_Data* object = static_cast<const ExtendableMessageEvent_Data*>(data);

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
                    object->message, "null message field in ExtendableMessageEvent",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->message, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->source_origin, "null source_origin field in ExtendableMessageEvent",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->source_origin, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->message_ports, "null message_ports field in ExtendableMessageEvent",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams message_ports_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->message_ports, validation_context,
                    &message_ports_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->new_routing_ids, "null new_routing_ids field in ExtendableMessageEvent",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams new_routing_ids_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->new_routing_ids, validation_context,
                    &new_routing_ids_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->source, "null source field in ExtendableMessageEvent",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->source, validation_context))
                return false;

            return true;
        }

        // static
        bool ServiceWorkerEventDispatcher_DispatchFetchEvent_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const ServiceWorkerEventDispatcher_DispatchFetchEvent_Params_Data* object = static_cast<const ServiceWorkerEventDispatcher_DispatchFetchEvent_Params_Data*>(data);

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
                    object->request, "null request field in ServiceWorkerEventDispatcher_DispatchFetchEvent_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->request, validation_context))
                return false;

            if (!mojo::internal::ValidateStruct(object->preload_handle, validation_context))
                return false;

            return true;
        }

        // static
        bool ServiceWorkerEventDispatcher_DispatchFetchEvent_ResponseParams_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const ServiceWorkerEventDispatcher_DispatchFetchEvent_ResponseParams_Data* object = static_cast<const ServiceWorkerEventDispatcher_DispatchFetchEvent_ResponseParams_Data*>(data);

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

            if (!::blink::mojom::internal::ServiceWorkerEventStatus_Data ::Validate(object->status, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->dispatch_event_time, "null dispatch_event_time field in ServiceWorkerEventDispatcher_DispatchFetchEvent_ResponseParams",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->dispatch_event_time, validation_context))
                return false;

            return true;
        }

        // static
        bool ServiceWorkerEventDispatcher_DispatchPushEvent_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const ServiceWorkerEventDispatcher_DispatchPushEvent_Params_Data* object = static_cast<const ServiceWorkerEventDispatcher_DispatchPushEvent_Params_Data*>(data);

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
                    object->payload, "null payload field in ServiceWorkerEventDispatcher_DispatchPushEvent_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->payload, validation_context))
                return false;

            return true;
        }

        // static
        bool ServiceWorkerEventDispatcher_DispatchPushEvent_ResponseParams_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const ServiceWorkerEventDispatcher_DispatchPushEvent_ResponseParams_Data* object = static_cast<const ServiceWorkerEventDispatcher_DispatchPushEvent_ResponseParams_Data*>(data);

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

            if (!::blink::mojom::internal::ServiceWorkerEventStatus_Data ::Validate(object->status, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->dispatch_event_time, "null dispatch_event_time field in ServiceWorkerEventDispatcher_DispatchPushEvent_ResponseParams",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->dispatch_event_time, validation_context))
                return false;

            return true;
        }

        // static
        bool ServiceWorkerEventDispatcher_DispatchSyncEvent_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const ServiceWorkerEventDispatcher_DispatchSyncEvent_Params_Data* object = static_cast<const ServiceWorkerEventDispatcher_DispatchSyncEvent_Params_Data*>(data);

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
                    object->tag, "null tag field in ServiceWorkerEventDispatcher_DispatchSyncEvent_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams tag_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->tag, validation_context,
                    &tag_validate_params)) {
                return false;
            }

            if (!::blink::mojom::internal::BackgroundSyncEventLastChance_Data ::Validate(object->last_chance, validation_context))
                return false;

            return true;
        }

        // static
        bool ServiceWorkerEventDispatcher_DispatchSyncEvent_ResponseParams_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const ServiceWorkerEventDispatcher_DispatchSyncEvent_ResponseParams_Data* object = static_cast<const ServiceWorkerEventDispatcher_DispatchSyncEvent_ResponseParams_Data*>(data);

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

            if (!::blink::mojom::internal::ServiceWorkerEventStatus_Data ::Validate(object->status, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->dispatch_event_time, "null dispatch_event_time field in ServiceWorkerEventDispatcher_DispatchSyncEvent_ResponseParams",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->dispatch_event_time, validation_context))
                return false;

            return true;
        }

        // static
        bool ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_Params_Data* object = static_cast<const ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_Params_Data*>(data);

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
                    object->data, "null data field in ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->data, validation_context))
                return false;

            return true;
        }

        // static
        bool ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ResponseParams_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ResponseParams_Data* object = static_cast<const ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ResponseParams_Data*>(data);

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

            if (!::blink::mojom::internal::ServiceWorkerEventStatus_Data ::Validate(object->status, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->dispatch_event_time, "null dispatch_event_time field in ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ResponseParams",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->dispatch_event_time, validation_context))
                return false;

            return true;
        }

        // static
        bool ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_Params_Data* object = static_cast<const ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_Params_Data*>(data);

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
                    object->event, "null event field in ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->event, validation_context))
                return false;

            return true;
        }

        // static
        bool ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ResponseParams_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ResponseParams_Data* object = static_cast<const ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ResponseParams_Data*>(data);

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

            if (!::blink::mojom::internal::ServiceWorkerEventStatus_Data ::Validate(object->status, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->dispatch_event_time, "null dispatch_event_time field in ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ResponseParams",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->dispatch_event_time, validation_context))
                return false;

            return true;
        }

    } // namespace internal
} // namespace mojom
} // namespace content

#if defined(_MSC_VER)
#pragma warning(pop)
#endif
