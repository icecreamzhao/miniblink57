// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4065)
#endif

#include "third_party/WebKit/public/platform/modules/offscreencanvas/offscreen_canvas_surface.mojom-shared.h"

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
        bool OffscreenCanvasSurface_Require_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const OffscreenCanvasSurface_Require_Params_Data* object = static_cast<const OffscreenCanvasSurface_Require_Params_Data*>(data);

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
                    object->surface_id, "null surface_id field in OffscreenCanvasSurface_Require_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->surface_id, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->sequence, "null sequence field in OffscreenCanvasSurface_Require_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->sequence, validation_context))
                return false;

            return true;
        }

        // static
        bool OffscreenCanvasSurface_Satisfy_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const OffscreenCanvasSurface_Satisfy_Params_Data* object = static_cast<const OffscreenCanvasSurface_Satisfy_Params_Data*>(data);

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
                    object->sequence, "null sequence field in OffscreenCanvasSurface_Satisfy_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->sequence, validation_context))
                return false;

            return true;
        }

        // static
        bool OffscreenCanvasSurfaceClient_OnSurfaceCreated_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const OffscreenCanvasSurfaceClient_OnSurfaceCreated_Params_Data* object = static_cast<const OffscreenCanvasSurfaceClient_OnSurfaceCreated_Params_Data*>(data);

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
                    object->surface_info, "null surface_info field in OffscreenCanvasSurfaceClient_OnSurfaceCreated_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->surface_info, validation_context))
                return false;

            return true;
        }

        // static
        bool OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Params_Data* object = static_cast<const OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Params_Data*>(data);

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
                    object->frame_sink_id, "null frame_sink_id field in OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->frame_sink_id, validation_context))
                return false;

            if (!mojo::internal::ValidateHandleOrInterfaceNonNullable(
                    object->client,
                    "invalid client field in OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Params", validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateHandleOrInterface(object->client,
                    validation_context)) {
                return false;
            }

            if (!mojo::internal::ValidateHandleOrInterfaceNonNullable(
                    object->service,
                    "invalid service field in OffscreenCanvasSurfaceFactory_CreateOffscreenCanvasSurface_Params", validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateHandleOrInterface(object->service,
                    validation_context)) {
                return false;
            }

            return true;
        }

        // static
        bool OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Params_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Params_Data* object = static_cast<const OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Params_Data*>(data);

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
                    object->frame_sink_id, "null frame_sink_id field in OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Params",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->frame_sink_id, validation_context))
                return false;

            if (!mojo::internal::ValidateHandleOrInterfaceNonNullable(
                    object->client,
                    "invalid client field in OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Params", validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateHandleOrInterface(object->client,
                    validation_context)) {
                return false;
            }

            if (!mojo::internal::ValidateHandleOrInterfaceNonNullable(
                    object->sink,
                    "invalid sink field in OffscreenCanvasCompositorFrameSinkProvider_CreateCompositorFrameSink_Params", validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateHandleOrInterface(object->sink,
                    validation_context)) {
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
