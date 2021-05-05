// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4065)
#endif

#include "third_party/WebKit/public/platform/modules/websockets/websocket.mojom-shared.h"

#include <utility>

#include "base/logging.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/cpp/bindings/lib/validation_util.h"
namespace blink {
namespace mojom {

    namespace internal {

        // static
        bool HttpHeader_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const HttpHeader_Data* object = static_cast<const HttpHeader_Data*>(data);

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
                    object->name, "null name field in HttpHeader",
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
                    object->value, "null value field in HttpHeader",
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
        bool WebSocketHandshakeRequest_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const WebSocketHandshakeRequest_Data* object = static_cast<const WebSocketHandshakeRequest_Data*>(data);

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
                    object->url, "null url field in WebSocketHandshakeRequest",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->url, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->headers, "null headers field in WebSocketHandshakeRequest",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams headers_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->headers, validation_context,
                    &headers_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->headers_text, "null headers_text field in WebSocketHandshakeRequest",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams headers_text_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->headers_text, validation_context,
                    &headers_text_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool WebSocketHandshakeResponse_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const WebSocketHandshakeResponse_Data* object = static_cast<const WebSocketHandshakeResponse_Data*>(data);

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
                    object->url, "null url field in WebSocketHandshakeResponse",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->url, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->status_text, "null status_text field in WebSocketHandshakeResponse",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams status_text_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->status_text, validation_context,
                    &status_text_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->headers, "null headers field in WebSocketHandshakeResponse",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams headers_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->headers, validation_context,
                    &headers_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->headers_text, "null headers_text field in WebSocketHandshakeResponse",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams headers_text_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->headers_text, validation_context,
                    &headers_text_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool WebSocketClient_OnFailChannel_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const WebSocketClient_OnFailChannel_Params_Data* object = static_cast<const WebSocketClient_OnFailChannel_Params_Data*>(data);

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
                    object->reason, "null reason field in WebSocketClient_OnFailChannel_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams reason_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->reason, validation_context,
                    &reason_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool WebSocketClient_OnStartOpeningHandshake_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const WebSocketClient_OnStartOpeningHandshake_Params_Data* object = static_cast<const WebSocketClient_OnStartOpeningHandshake_Params_Data*>(data);

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
                    object->request, "null request field in WebSocketClient_OnStartOpeningHandshake_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->request, validation_context))
                return false;

            return true;
        }

        // static
        bool WebSocketClient_OnFinishOpeningHandshake_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const WebSocketClient_OnFinishOpeningHandshake_Params_Data* object = static_cast<const WebSocketClient_OnFinishOpeningHandshake_Params_Data*>(data);

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
                    object->response, "null response field in WebSocketClient_OnFinishOpeningHandshake_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->response, validation_context))
                return false;

            return true;
        }

        // static
        bool WebSocketClient_OnAddChannelResponse_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const WebSocketClient_OnAddChannelResponse_Params_Data* object = static_cast<const WebSocketClient_OnAddChannelResponse_Params_Data*>(data);

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
                    object->selected_protocol, "null selected_protocol field in WebSocketClient_OnAddChannelResponse_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams selected_protocol_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->selected_protocol, validation_context,
                    &selected_protocol_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->extensions, "null extensions field in WebSocketClient_OnAddChannelResponse_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams extensions_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->extensions, validation_context,
                    &extensions_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool WebSocketClient_OnDataFrame_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const WebSocketClient_OnDataFrame_Params_Data* object = static_cast<const WebSocketClient_OnDataFrame_Params_Data*>(data);

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

            if (!::blink::mojom::internal::WebSocketMessageType_Data ::Validate(object->type, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->data, "null data field in WebSocketClient_OnDataFrame_Params",
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
        bool WebSocketClient_OnFlowControl_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const WebSocketClient_OnFlowControl_Params_Data* object = static_cast<const WebSocketClient_OnFlowControl_Params_Data*>(data);

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
        bool WebSocketClient_OnDropChannel_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const WebSocketClient_OnDropChannel_Params_Data* object = static_cast<const WebSocketClient_OnDropChannel_Params_Data*>(data);

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
                    object->reason, "null reason field in WebSocketClient_OnDropChannel_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams reason_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->reason, validation_context,
                    &reason_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool WebSocketClient_OnClosingHandshake_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const WebSocketClient_OnClosingHandshake_Params_Data* object = static_cast<const WebSocketClient_OnClosingHandshake_Params_Data*>(data);

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
        bool WebSocket_AddChannelRequest_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const WebSocket_AddChannelRequest_Params_Data* object = static_cast<const WebSocket_AddChannelRequest_Params_Data*>(data);

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
                    object->url, "null url field in WebSocket_AddChannelRequest_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->url, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->requested_protocols, "null requested_protocols field in WebSocket_AddChannelRequest_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams requested_protocols_validate_params(
                0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr));
            if (!mojo::internal::ValidateContainer(object->requested_protocols, validation_context,
                    &requested_protocols_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->origin, "null origin field in WebSocket_AddChannelRequest_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->origin, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->first_party_for_cookies, "null first_party_for_cookies field in WebSocket_AddChannelRequest_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->first_party_for_cookies, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->user_agent_override, "null user_agent_override field in WebSocket_AddChannelRequest_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams user_agent_override_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->user_agent_override, validation_context,
                    &user_agent_override_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidateHandleOrInterfaceNonNullable(
                    object->client,
                    "invalid client field in WebSocket_AddChannelRequest_Params", validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateHandleOrInterface(object->client,
                    validation_context)) {
                return false;
            }

            return true;
        }

        // static
        bool WebSocket_SendFrame_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const WebSocket_SendFrame_Params_Data* object = static_cast<const WebSocket_SendFrame_Params_Data*>(data);

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

            if (!::blink::mojom::internal::WebSocketMessageType_Data ::Validate(object->type, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->data, "null data field in WebSocket_SendFrame_Params",
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
        bool WebSocket_SendFlowControl_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const WebSocket_SendFlowControl_Params_Data* object = static_cast<const WebSocket_SendFlowControl_Params_Data*>(data);

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
        bool WebSocket_StartClosingHandshake_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const WebSocket_StartClosingHandshake_Params_Data* object = static_cast<const WebSocket_StartClosingHandshake_Params_Data*>(data);

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
                    object->reason, "null reason field in WebSocket_StartClosingHandshake_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams reason_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->reason, validation_context,
                    &reason_validate_params)) {
                return false;
            }

            return true;
        }

    } // namespace internal
} // namespace mojom
} // namespace blink

#if defined(_MSC_VER)
#pragma warning(pop)
#endif
