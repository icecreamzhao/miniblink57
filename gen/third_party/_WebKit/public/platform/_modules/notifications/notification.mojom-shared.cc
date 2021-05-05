// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4065)
#endif

#include "third_party/WebKit/public/platform/modules/notifications/notification.mojom-shared.h"

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
        bool NotificationAction_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const NotificationAction_Data* object = static_cast<const NotificationAction_Data*>(data);

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

            if (!::blink::mojom::internal::NotificationActionType_Data ::Validate(object->type, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->action, "null action field in NotificationAction",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams action_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->action, validation_context,
                    &action_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->title, "null title field in NotificationAction",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams title_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->title, validation_context,
                    &title_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->icon, "null icon field in NotificationAction",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams icon_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->icon, validation_context,
                    &icon_validate_params)) {
                return false;
            }

            const mojo::internal::ContainerValidateParams placeholder_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->placeholder, validation_context,
                    &placeholder_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool Notification_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const Notification_Data* object = static_cast<const Notification_Data*>(data);

            static constexpr struct {
                uint32_t version;
                uint32_t num_bytes;
            } kVersionSizes[] = { { 0, 96 } };

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
                    object->title, "null title field in Notification",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams title_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->title, validation_context,
                    &title_validate_params)) {
                return false;
            }

            if (!::blink::mojom::internal::NotificationDirection_Data ::Validate(object->direction, validation_context))
                return false;

            const mojo::internal::ContainerValidateParams lang_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->lang, validation_context,
                    &lang_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->body, "null body field in Notification",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams body_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->body, validation_context,
                    &body_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->tag, "null tag field in Notification",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams tag_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->tag, validation_context,
                    &tag_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->icon, "null icon field in Notification",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams icon_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->icon, validation_context,
                    &icon_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->badge, "null badge field in Notification",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams badge_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->badge, validation_context,
                    &badge_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->vibration_pattern, "null vibration_pattern field in Notification",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams vibration_pattern_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->vibration_pattern, validation_context,
                    &vibration_pattern_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->data, "null data field in Notification",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams data_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->data, validation_context,
                    &data_validate_params)) {
                return false;
            }

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->actions, "null actions field in Notification",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams actions_validate_params(
                0, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->actions, validation_context,
                    &actions_validate_params)) {
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
