// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4065)
#endif

#include "content/common/render_frame_message_filter.mojom-shared.h"

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
        bool RenderFrameMessageFilter_SetCookie_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const RenderFrameMessageFilter_SetCookie_Params_Data* object = static_cast<const RenderFrameMessageFilter_SetCookie_Params_Data*>(data);

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
                    object->url, "null url field in RenderFrameMessageFilter_SetCookie_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->url, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->first_party_for_cookies, "null first_party_for_cookies field in RenderFrameMessageFilter_SetCookie_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->first_party_for_cookies, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->cookie, "null cookie field in RenderFrameMessageFilter_SetCookie_Params",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams cookie_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->cookie, validation_context,
                    &cookie_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool RenderFrameMessageFilter_GetCookies_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const RenderFrameMessageFilter_GetCookies_Params_Data* object = static_cast<const RenderFrameMessageFilter_GetCookies_Params_Data*>(data);

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
                    object->url, "null url field in RenderFrameMessageFilter_GetCookies_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->url, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->first_party_for_cookies, "null first_party_for_cookies field in RenderFrameMessageFilter_GetCookies_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->first_party_for_cookies, validation_context))
                return false;

            return true;
        }

        // static
        bool RenderFrameMessageFilter_GetCookies_ResponseParams_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const RenderFrameMessageFilter_GetCookies_ResponseParams_Data* object = static_cast<const RenderFrameMessageFilter_GetCookies_ResponseParams_Data*>(data);

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
                    object->cookies, "null cookies field in RenderFrameMessageFilter_GetCookies_ResponseParams",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams cookies_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->cookies, validation_context,
                    &cookies_validate_params)) {
                return false;
            }

            return true;
        }

    } // namespace internal
} // namespace mojom
} // namespace content

#if defined(_MSC_VER)
#pragma warning(pop)
#endif
