// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#if defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4065)
#endif

#include "cc/ipc/quads.mojom-shared.h"

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
        bool DrawQuadState_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context,
            bool inlined)
        {
            if (!data) {
                DCHECK(!inlined);
                return true;
            }

            // If it is inlined, the alignment is already enforced by its enclosing
            // object. We don't have to validate that.
            DCHECK(!inlined || mojo::internal::IsAligned(data));

            if (!inlined && !mojo::internal::ValidateNonInlinedUnionHeaderAndClaimMemory(data, validation_context)) {
                return false;
            }

            const DrawQuadState_Data* object = static_cast<const DrawQuadState_Data*>(data);
            ALLOW_UNUSED_LOCAL(object);

            if (inlined && object->is_null())
                return true;

            switch (object->tag) {

            case DrawQuadState_Tag::DEBUG_BORDER_QUAD_STATE: {

                if (!mojo::internal::ValidatePointerNonNullable(
                        object->data.f_debug_border_quad_state, "null debug_border_quad_state field in DrawQuadState",
                        validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateStruct(object->data.f_debug_border_quad_state, validation_context))
                    return false;
                return true;
            }
            case DrawQuadState_Tag::RENDER_PASS_QUAD_STATE: {

                if (!mojo::internal::ValidatePointerNonNullable(
                        object->data.f_render_pass_quad_state, "null render_pass_quad_state field in DrawQuadState",
                        validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateStruct(object->data.f_render_pass_quad_state, validation_context))
                    return false;
                return true;
            }
            case DrawQuadState_Tag::SOLID_COLOR_QUAD_STATE: {

                if (!mojo::internal::ValidatePointerNonNullable(
                        object->data.f_solid_color_quad_state, "null solid_color_quad_state field in DrawQuadState",
                        validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateStruct(object->data.f_solid_color_quad_state, validation_context))
                    return false;
                return true;
            }
            case DrawQuadState_Tag::STREAM_VIDEO_QUAD_STATE: {

                if (!mojo::internal::ValidatePointerNonNullable(
                        object->data.f_stream_video_quad_state, "null stream_video_quad_state field in DrawQuadState",
                        validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateStruct(object->data.f_stream_video_quad_state, validation_context))
                    return false;
                return true;
            }
            case DrawQuadState_Tag::SURFACE_QUAD_STATE: {

                if (!mojo::internal::ValidatePointerNonNullable(
                        object->data.f_surface_quad_state, "null surface_quad_state field in DrawQuadState",
                        validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateStruct(object->data.f_surface_quad_state, validation_context))
                    return false;
                return true;
            }
            case DrawQuadState_Tag::TEXTURE_QUAD_STATE: {

                if (!mojo::internal::ValidatePointerNonNullable(
                        object->data.f_texture_quad_state, "null texture_quad_state field in DrawQuadState",
                        validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateStruct(object->data.f_texture_quad_state, validation_context))
                    return false;
                return true;
            }
            case DrawQuadState_Tag::TILE_QUAD_STATE: {

                if (!mojo::internal::ValidatePointerNonNullable(
                        object->data.f_tile_quad_state, "null tile_quad_state field in DrawQuadState",
                        validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateStruct(object->data.f_tile_quad_state, validation_context))
                    return false;
                return true;
            }
            case DrawQuadState_Tag::YUV_VIDEO_QUAD_STATE: {

                if (!mojo::internal::ValidatePointerNonNullable(
                        object->data.f_yuv_video_quad_state, "null yuv_video_quad_state field in DrawQuadState",
                        validation_context)) {
                    return false;
                }
                if (!mojo::internal::ValidateStruct(object->data.f_yuv_video_quad_state, validation_context))
                    return false;
                return true;
            }
            default: {
                ReportValidationError(
                    validation_context,
                    mojo::internal::VALIDATION_ERROR_UNKNOWN_UNION_TAG,
                    "unknown tag in DrawQuadState");
                return false;
            }
            }
        }

        // static
        bool DebugBorderQuadState_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const DebugBorderQuadState_Data* object = static_cast<const DebugBorderQuadState_Data*>(data);

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
        bool RenderPassQuadState_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const RenderPassQuadState_Data* object = static_cast<const RenderPassQuadState_Data*>(data);

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
                    object->mask_uv_scale, "null mask_uv_scale field in RenderPassQuadState",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->mask_uv_scale, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->mask_texture_size, "null mask_texture_size field in RenderPassQuadState",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->mask_texture_size, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->filters_scale, "null filters_scale field in RenderPassQuadState",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->filters_scale, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->filters_origin, "null filters_origin field in RenderPassQuadState",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->filters_origin, validation_context))
                return false;

            return true;
        }

        // static
        bool SolidColorQuadState_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const SolidColorQuadState_Data* object = static_cast<const SolidColorQuadState_Data*>(data);

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
        bool StreamVideoQuadState_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const StreamVideoQuadState_Data* object = static_cast<const StreamVideoQuadState_Data*>(data);

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
                    object->resource_size_in_pixels, "null resource_size_in_pixels field in StreamVideoQuadState",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->resource_size_in_pixels, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->matrix, "null matrix field in StreamVideoQuadState",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->matrix, validation_context))
                return false;

            return true;
        }

        // static
        bool SurfaceQuadState_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const SurfaceQuadState_Data* object = static_cast<const SurfaceQuadState_Data*>(data);

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
                    object->surface, "null surface field in SurfaceQuadState",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->surface, validation_context))
                return false;

            return true;
        }

        // static
        bool TextureQuadState_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const TextureQuadState_Data* object = static_cast<const TextureQuadState_Data*>(data);

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
                    object->resource_size_in_pixels, "null resource_size_in_pixels field in TextureQuadState",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->resource_size_in_pixels, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->uv_top_left, "null uv_top_left field in TextureQuadState",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->uv_top_left, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->uv_bottom_right, "null uv_bottom_right field in TextureQuadState",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->uv_bottom_right, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->vertex_opacity, "null vertex_opacity field in TextureQuadState",
                    validation_context)) {
                return false;
            }
            const mojo::internal::ContainerValidateParams vertex_opacity_validate_params(
                4, false, nullptr);
            if (!mojo::internal::ValidateContainer(object->vertex_opacity, validation_context,
                    &vertex_opacity_validate_params)) {
                return false;
            }

            return true;
        }

        // static
        bool TileQuadState_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const TileQuadState_Data* object = static_cast<const TileQuadState_Data*>(data);

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
                    object->tex_coord_rect, "null tex_coord_rect field in TileQuadState",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->tex_coord_rect, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->texture_size, "null texture_size field in TileQuadState",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->texture_size, validation_context))
                return false;

            return true;
        }

        // static
        bool YUVVideoQuadState_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const YUVVideoQuadState_Data* object = static_cast<const YUVVideoQuadState_Data*>(data);

            static constexpr struct {
                uint32_t version;
                uint32_t num_bytes;
            } kVersionSizes[] = { { 0, 72 } };

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
                    object->ya_tex_coord_rect, "null ya_tex_coord_rect field in YUVVideoQuadState",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->ya_tex_coord_rect, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->uv_tex_coord_rect, "null uv_tex_coord_rect field in YUVVideoQuadState",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->uv_tex_coord_rect, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->ya_tex_size, "null ya_tex_size field in YUVVideoQuadState",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->ya_tex_size, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->uv_tex_size, "null uv_tex_size field in YUVVideoQuadState",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->uv_tex_size, validation_context))
                return false;

            if (!::cc::mojom::internal::YUVColorSpace_Data ::Validate(object->color_space, validation_context))
                return false;

            return true;
        }

        // static
        bool DrawQuad_Data::Validate(
            const void* data,
            mojo::internal::ValidationContext* validation_context)
        {
            if (!data)
                return true;

            if (!ValidateStructHeaderAndClaimMemory(data, validation_context))
                return false;

            // NOTE: The memory backing |object| may be smaller than |sizeof(*object)| if
            // the message comes from an older version.
            const DrawQuad_Data* object = static_cast<const DrawQuad_Data*>(data);

            static constexpr struct {
                uint32_t version;
                uint32_t num_bytes;
            } kVersionSizes[] = { { 0, 64 } };

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
                    object->rect, "null rect field in DrawQuad",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->rect, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->opaque_rect, "null opaque_rect field in DrawQuad",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->opaque_rect, validation_context))
                return false;

            if (!mojo::internal::ValidatePointerNonNullable(
                    object->visible_rect, "null visible_rect field in DrawQuad",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateStruct(object->visible_rect, validation_context))
                return false;

            if (!mojo::internal::ValidateStruct(object->sqs, validation_context))
                return false;

            if (!mojo::internal::ValidateInlinedUnionNonNullable(
                    object->draw_quad_state, "null draw_quad_state field in DrawQuad",
                    validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateInlinedUnion(object->draw_quad_state, validation_context))
                return false;

            return true;
        }

    } // namespace internal
} // namespace mojom
} // namespace cc

#if defined(_MSC_VER)
#pragma warning(pop)
#endif
