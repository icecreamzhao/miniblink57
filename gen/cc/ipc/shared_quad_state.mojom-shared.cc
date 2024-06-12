// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4065)
#endif

#include "cc/ipc/shared_quad_state.mojom-shared.h"

#include <utility>

#include "base/logging.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/cpp/bindings/lib/validation_util.h"
namespace cc {
namespace mojom {

    namespace internal {

        // static
        bool SharedQuadState_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const SharedQuadState_Data* object = static_cast<const SharedQuadState_Data*>(data);

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
                    object->quad_to_target_transform, "null quad_to_target_transform field in SharedQuadState",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->quad_to_target_transform, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->quad_layer_bounds, "null quad_layer_bounds field in SharedQuadState",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->quad_layer_bounds, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->visible_quad_layer_rect, "null visible_quad_layer_rect field in SharedQuadState",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->visible_quad_layer_rect, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->clip_rect, "null clip_rect field in SharedQuadState",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->clip_rect, validation_context))
                return false;

            return true;
        }

    } // namespace internal
} // namespace mojom
} // namespace cc

#if defined(_MSC_VER)
#pragma warning(pop)
#endif
