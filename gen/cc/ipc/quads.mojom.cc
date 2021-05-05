// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-private-field"
#elif defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4056)
#pragma warning(disable : 4065)
#pragma warning(disable : 4756)
#endif

#include "cc/ipc/quads.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "cc/ipc/begin_frame_args_struct_traits.h"
#include "cc/ipc/compositor_frame_metadata_struct_traits.h"
#include "cc/ipc/compositor_frame_struct_traits.h"
#include "cc/ipc/filter_operation_struct_traits.h"
#include "cc/ipc/filter_operations_struct_traits.h"
#include "cc/ipc/frame_sink_id_struct_traits.h"
#include "cc/ipc/local_frame_id_struct_traits.h"
#include "cc/ipc/quads_struct_traits.h"
#include "cc/ipc/render_pass_struct_traits.h"
#include "cc/ipc/returned_resource_struct_traits.h"
#include "cc/ipc/selection_struct_traits.h"
#include "cc/ipc/shared_quad_state_struct_traits.h"
#include "cc/ipc/surface_id_struct_traits.h"
#include "cc/ipc/surface_info_struct_traits.h"
#include "cc/ipc/surface_reference_struct_traits.h"
#include "cc/ipc/surface_sequence_struct_traits.h"
#include "cc/ipc/transferable_resource_struct_traits.h"
#include "gpu/ipc/common/dx_diag_node_struct_traits.h"
#include "gpu/ipc/common/gpu_command_buffer_traits.h"
#include "gpu/ipc/common/gpu_info_struct_traits.h"
#include "gpu/ipc/common/gpu_preferences_struct_traits.h"
#include "gpu/ipc/common/mailbox_holder_struct_traits.h"
#include "gpu/ipc/common/mailbox_struct_traits.h"
#include "gpu/ipc/common/surface_handle_struct_traits.h"
#include "gpu/ipc/common/sync_token_struct_traits.h"
#include "ipc/ipc_message_utils.h"
#include "mojo/common/common_custom_types_struct_traits.h"
#include "mojo/common/values_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "skia/public/interfaces/bitmap_skbitmap_struct_traits.h"
#include "skia/public/interfaces/image_filter_struct_traits.h"
#include "ui/events/mojo/event_struct_traits.h"
#include "ui/events/mojo/latency_info_struct_traits.h"
#include "ui/gfx/geometry/mojo/geometry_struct_traits.h"
#include "ui/gfx/ipc/color/gfx_param_traits.h"
#include "ui/gfx/mojo/accelerated_widget_struct_traits.h"
#include "ui/gfx/mojo/buffer_types_traits.h"
#include "ui/gfx/mojo/icc_profile_struct_traits.h"
#include "ui/gfx/mojo/selection_bound_struct_traits.h"
#include "ui/gfx/mojo/transform_struct_traits.h"
namespace cc {
namespace mojom { // static
    DebugBorderQuadStatePtr DebugBorderQuadState::New()
    {
        DebugBorderQuadStatePtr rv;
        mojo::internal::StructHelper<DebugBorderQuadState>::Initialize(&rv);
        return rv;
    }

    DebugBorderQuadState::DebugBorderQuadState()
        : color()
        , width()
    {
    }

    DebugBorderQuadState::~DebugBorderQuadState()
    {
    }
    size_t DebugBorderQuadState::Hash(size_t seed) const
    {
        seed = mojo::internal::Hash(seed, this->color);
        seed = mojo::internal::Hash(seed, this->width);
        return seed;
    } // static
    RenderPassQuadStatePtr RenderPassQuadState::New()
    {
        RenderPassQuadStatePtr rv;
        mojo::internal::StructHelper<RenderPassQuadState>::Initialize(&rv);
        return rv;
    }

    RenderPassQuadState::RenderPassQuadState()
        : render_pass_id()
        , mask_resource_id()
        , mask_uv_scale()
        , mask_texture_size()
        , filters_scale()
        , filters_origin()
    {
    }

    RenderPassQuadState::~RenderPassQuadState()
    {
    } // static
    SolidColorQuadStatePtr SolidColorQuadState::New()
    {
        SolidColorQuadStatePtr rv;
        mojo::internal::StructHelper<SolidColorQuadState>::Initialize(&rv);
        return rv;
    }

    SolidColorQuadState::SolidColorQuadState()
        : color()
        , force_anti_aliasing_off()
    {
    }

    SolidColorQuadState::~SolidColorQuadState()
    {
    }
    size_t SolidColorQuadState::Hash(size_t seed) const
    {
        seed = mojo::internal::Hash(seed, this->color);
        seed = mojo::internal::Hash(seed, this->force_anti_aliasing_off);
        return seed;
    } // static
    StreamVideoQuadStatePtr StreamVideoQuadState::New()
    {
        StreamVideoQuadStatePtr rv;
        mojo::internal::StructHelper<StreamVideoQuadState>::Initialize(&rv);
        return rv;
    }

    StreamVideoQuadState::StreamVideoQuadState()
        : resource_id()
        , resource_size_in_pixels()
        , matrix()
    {
    }

    StreamVideoQuadState::~StreamVideoQuadState()
    {
    } // static
    SurfaceQuadStatePtr SurfaceQuadState::New()
    {
        SurfaceQuadStatePtr rv;
        mojo::internal::StructHelper<SurfaceQuadState>::Initialize(&rv);
        return rv;
    }

    SurfaceQuadState::SurfaceQuadState()
        : surface()
    {
    }

    SurfaceQuadState::~SurfaceQuadState()
    {
    } // static
    TextureQuadStatePtr TextureQuadState::New()
    {
        TextureQuadStatePtr rv;
        mojo::internal::StructHelper<TextureQuadState>::Initialize(&rv);
        return rv;
    }

    TextureQuadState::TextureQuadState()
        : resource_id()
        , resource_size_in_pixels()
        , premultiplied_alpha()
        , uv_top_left()
        , uv_bottom_right()
        , background_color()
        , vertex_opacity()
        , y_flipped()
        , nearest_neighbor()
        , secure_output_only()
    {
    }

    TextureQuadState::~TextureQuadState()
    {
    } // static
    TileQuadStatePtr TileQuadState::New()
    {
        TileQuadStatePtr rv;
        mojo::internal::StructHelper<TileQuadState>::Initialize(&rv);
        return rv;
    }

    TileQuadState::TileQuadState()
        : tex_coord_rect()
        , texture_size()
        , swizzle_contents()
        , resource_id()
        , nearest_neighbor()
    {
    }

    TileQuadState::~TileQuadState()
    {
    } // static
    YUVVideoQuadStatePtr YUVVideoQuadState::New()
    {
        YUVVideoQuadStatePtr rv;
        mojo::internal::StructHelper<YUVVideoQuadState>::Initialize(&rv);
        return rv;
    }

    YUVVideoQuadState::YUVVideoQuadState()
        : ya_tex_coord_rect()
        , uv_tex_coord_rect()
        , ya_tex_size()
        , uv_tex_size()
        , y_plane_resource_id()
        , u_plane_resource_id()
        , v_plane_resource_id()
        , a_plane_resource_id()
        , color_space()
        , resource_offset()
        , resource_multiplier()
        , bits_per_channel()
    {
    }

    YUVVideoQuadState::~YUVVideoQuadState()
    {
    } // static
    DrawQuadPtr DrawQuad::New()
    {
        DrawQuadPtr rv;
        mojo::internal::StructHelper<DrawQuad>::Initialize(&rv);
        return rv;
    }

    DrawQuad::DrawQuad()
        : rect()
        , opaque_rect()
        , visible_rect()
        , needs_blending()
        , sqs()
        , draw_quad_state()
    {
    }

    DrawQuad::~DrawQuad()
    {
    } // static
    DrawQuadStatePtr DrawQuadState::New()
    {
        DrawQuadStatePtr rv;
        mojo::internal::StructHelper<DrawQuadState>::Initialize(&rv);
        return rv;
    }

    DrawQuadState::DrawQuadState()
    {
        // TODO(azani): Implement default values here when/if we support them.
        // TODO(azani): Set to UNKNOWN when unknown is implemented.
        SetActive(static_cast<Tag>(0));
    }

    DrawQuadState::~DrawQuadState()
    {
        DestroyActive();
    }

    void DrawQuadState::set_debug_border_quad_state(DebugBorderQuadStatePtr debug_border_quad_state)
    {
        SwitchActive(Tag::DEBUG_BORDER_QUAD_STATE);

        *(data_.debug_border_quad_state) = std::move(debug_border_quad_state);
    }
    void DrawQuadState::set_render_pass_quad_state(RenderPassQuadStatePtr render_pass_quad_state)
    {
        SwitchActive(Tag::RENDER_PASS_QUAD_STATE);

        *(data_.render_pass_quad_state) = std::move(render_pass_quad_state);
    }
    void DrawQuadState::set_solid_color_quad_state(SolidColorQuadStatePtr solid_color_quad_state)
    {
        SwitchActive(Tag::SOLID_COLOR_QUAD_STATE);

        *(data_.solid_color_quad_state) = std::move(solid_color_quad_state);
    }
    void DrawQuadState::set_stream_video_quad_state(StreamVideoQuadStatePtr stream_video_quad_state)
    {
        SwitchActive(Tag::STREAM_VIDEO_QUAD_STATE);

        *(data_.stream_video_quad_state) = std::move(stream_video_quad_state);
    }
    void DrawQuadState::set_surface_quad_state(SurfaceQuadStatePtr surface_quad_state)
    {
        SwitchActive(Tag::SURFACE_QUAD_STATE);

        *(data_.surface_quad_state) = std::move(surface_quad_state);
    }
    void DrawQuadState::set_texture_quad_state(TextureQuadStatePtr texture_quad_state)
    {
        SwitchActive(Tag::TEXTURE_QUAD_STATE);

        *(data_.texture_quad_state) = std::move(texture_quad_state);
    }
    void DrawQuadState::set_tile_quad_state(TileQuadStatePtr tile_quad_state)
    {
        SwitchActive(Tag::TILE_QUAD_STATE);

        *(data_.tile_quad_state) = std::move(tile_quad_state);
    }
    void DrawQuadState::set_yuv_video_quad_state(YUVVideoQuadStatePtr yuv_video_quad_state)
    {
        SwitchActive(Tag::YUV_VIDEO_QUAD_STATE);

        *(data_.yuv_video_quad_state) = std::move(yuv_video_quad_state);
    }

    void DrawQuadState::SwitchActive(Tag new_active)
    {
        if (new_active == tag_) {
            return;
        }

        DestroyActive();
        SetActive(new_active);
    }

    void DrawQuadState::SetActive(Tag new_active)
    {
        switch (new_active) {

        case Tag::DEBUG_BORDER_QUAD_STATE:

            data_.debug_border_quad_state = new DebugBorderQuadStatePtr();
            break;
        case Tag::RENDER_PASS_QUAD_STATE:

            data_.render_pass_quad_state = new RenderPassQuadStatePtr();
            break;
        case Tag::SOLID_COLOR_QUAD_STATE:

            data_.solid_color_quad_state = new SolidColorQuadStatePtr();
            break;
        case Tag::STREAM_VIDEO_QUAD_STATE:

            data_.stream_video_quad_state = new StreamVideoQuadStatePtr();
            break;
        case Tag::SURFACE_QUAD_STATE:

            data_.surface_quad_state = new SurfaceQuadStatePtr();
            break;
        case Tag::TEXTURE_QUAD_STATE:

            data_.texture_quad_state = new TextureQuadStatePtr();
            break;
        case Tag::TILE_QUAD_STATE:

            data_.tile_quad_state = new TileQuadStatePtr();
            break;
        case Tag::YUV_VIDEO_QUAD_STATE:

            data_.yuv_video_quad_state = new YUVVideoQuadStatePtr();
            break;
        }

        tag_ = new_active;
    }

    void DrawQuadState::DestroyActive()
    {
        switch (tag_) {

        case Tag::DEBUG_BORDER_QUAD_STATE:

            delete data_.debug_border_quad_state;
            break;
        case Tag::RENDER_PASS_QUAD_STATE:

            delete data_.render_pass_quad_state;
            break;
        case Tag::SOLID_COLOR_QUAD_STATE:

            delete data_.solid_color_quad_state;
            break;
        case Tag::STREAM_VIDEO_QUAD_STATE:

            delete data_.stream_video_quad_state;
            break;
        case Tag::SURFACE_QUAD_STATE:

            delete data_.surface_quad_state;
            break;
        case Tag::TEXTURE_QUAD_STATE:

            delete data_.texture_quad_state;
            break;
        case Tag::TILE_QUAD_STATE:

            delete data_.tile_quad_state;
            break;
        case Tag::YUV_VIDEO_QUAD_STATE:

            delete data_.yuv_video_quad_state;
            break;
        }
    }
} // namespace mojom
} // namespace cc

namespace mojo {

// static
bool StructTraits<::cc::mojom::DebugBorderQuadState::DataView, ::cc::mojom::DebugBorderQuadStatePtr>::Read(
    ::cc::mojom::DebugBorderQuadState::DataView input,
    ::cc::mojom::DebugBorderQuadStatePtr* output)
{
    bool success = true;
    ::cc::mojom::DebugBorderQuadStatePtr result(::cc::mojom::DebugBorderQuadState::New());

    result->color = input.color();
    result->width = input.width();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::cc::mojom::RenderPassQuadState::DataView, ::cc::mojom::RenderPassQuadStatePtr>::Read(
    ::cc::mojom::RenderPassQuadState::DataView input,
    ::cc::mojom::RenderPassQuadStatePtr* output)
{
    bool success = true;
    ::cc::mojom::RenderPassQuadStatePtr result(::cc::mojom::RenderPassQuadState::New());

    result->render_pass_id = input.render_pass_id();
    result->mask_resource_id = input.mask_resource_id();
    if (!input.ReadMaskUvScale(&result->mask_uv_scale))
        success = false;
    if (!input.ReadMaskTextureSize(&result->mask_texture_size))
        success = false;
    if (!input.ReadFiltersScale(&result->filters_scale))
        success = false;
    if (!input.ReadFiltersOrigin(&result->filters_origin))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::cc::mojom::SolidColorQuadState::DataView, ::cc::mojom::SolidColorQuadStatePtr>::Read(
    ::cc::mojom::SolidColorQuadState::DataView input,
    ::cc::mojom::SolidColorQuadStatePtr* output)
{
    bool success = true;
    ::cc::mojom::SolidColorQuadStatePtr result(::cc::mojom::SolidColorQuadState::New());

    result->color = input.color();
    result->force_anti_aliasing_off = input.force_anti_aliasing_off();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::cc::mojom::StreamVideoQuadState::DataView, ::cc::mojom::StreamVideoQuadStatePtr>::Read(
    ::cc::mojom::StreamVideoQuadState::DataView input,
    ::cc::mojom::StreamVideoQuadStatePtr* output)
{
    bool success = true;
    ::cc::mojom::StreamVideoQuadStatePtr result(::cc::mojom::StreamVideoQuadState::New());

    result->resource_id = input.resource_id();
    if (!input.ReadResourceSizeInPixels(&result->resource_size_in_pixels))
        success = false;
    if (!input.ReadMatrix(&result->matrix))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::cc::mojom::SurfaceQuadState::DataView, ::cc::mojom::SurfaceQuadStatePtr>::Read(
    ::cc::mojom::SurfaceQuadState::DataView input,
    ::cc::mojom::SurfaceQuadStatePtr* output)
{
    bool success = true;
    ::cc::mojom::SurfaceQuadStatePtr result(::cc::mojom::SurfaceQuadState::New());

    if (!input.ReadSurface(&result->surface))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::cc::mojom::TextureQuadState::DataView, ::cc::mojom::TextureQuadStatePtr>::Read(
    ::cc::mojom::TextureQuadState::DataView input,
    ::cc::mojom::TextureQuadStatePtr* output)
{
    bool success = true;
    ::cc::mojom::TextureQuadStatePtr result(::cc::mojom::TextureQuadState::New());

    result->resource_id = input.resource_id();
    if (!input.ReadResourceSizeInPixels(&result->resource_size_in_pixels))
        success = false;
    result->premultiplied_alpha = input.premultiplied_alpha();
    if (!input.ReadUvTopLeft(&result->uv_top_left))
        success = false;
    if (!input.ReadUvBottomRight(&result->uv_bottom_right))
        success = false;
    result->background_color = input.background_color();
    if (!input.ReadVertexOpacity(&result->vertex_opacity))
        success = false;
    result->y_flipped = input.y_flipped();
    result->nearest_neighbor = input.nearest_neighbor();
    result->secure_output_only = input.secure_output_only();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::cc::mojom::TileQuadState::DataView, ::cc::mojom::TileQuadStatePtr>::Read(
    ::cc::mojom::TileQuadState::DataView input,
    ::cc::mojom::TileQuadStatePtr* output)
{
    bool success = true;
    ::cc::mojom::TileQuadStatePtr result(::cc::mojom::TileQuadState::New());

    if (!input.ReadTexCoordRect(&result->tex_coord_rect))
        success = false;
    if (!input.ReadTextureSize(&result->texture_size))
        success = false;
    result->swizzle_contents = input.swizzle_contents();
    result->resource_id = input.resource_id();
    result->nearest_neighbor = input.nearest_neighbor();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::cc::mojom::YUVVideoQuadState::DataView, ::cc::mojom::YUVVideoQuadStatePtr>::Read(
    ::cc::mojom::YUVVideoQuadState::DataView input,
    ::cc::mojom::YUVVideoQuadStatePtr* output)
{
    bool success = true;
    ::cc::mojom::YUVVideoQuadStatePtr result(::cc::mojom::YUVVideoQuadState::New());

    if (!input.ReadYaTexCoordRect(&result->ya_tex_coord_rect))
        success = false;
    if (!input.ReadUvTexCoordRect(&result->uv_tex_coord_rect))
        success = false;
    if (!input.ReadYaTexSize(&result->ya_tex_size))
        success = false;
    if (!input.ReadUvTexSize(&result->uv_tex_size))
        success = false;
    result->y_plane_resource_id = input.y_plane_resource_id();
    result->u_plane_resource_id = input.u_plane_resource_id();
    result->v_plane_resource_id = input.v_plane_resource_id();
    result->a_plane_resource_id = input.a_plane_resource_id();
    if (!input.ReadColorSpace(&result->color_space))
        success = false;
    result->resource_offset = input.resource_offset();
    result->resource_multiplier = input.resource_multiplier();
    result->bits_per_channel = input.bits_per_channel();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::cc::mojom::DrawQuad::DataView, ::cc::mojom::DrawQuadPtr>::Read(
    ::cc::mojom::DrawQuad::DataView input,
    ::cc::mojom::DrawQuadPtr* output)
{
    bool success = true;
    ::cc::mojom::DrawQuadPtr result(::cc::mojom::DrawQuad::New());

    if (!input.ReadRect(&result->rect))
        success = false;
    if (!input.ReadOpaqueRect(&result->opaque_rect))
        success = false;
    if (!input.ReadVisibleRect(&result->visible_rect))
        success = false;
    result->needs_blending = input.needs_blending();
    if (!input.ReadSqs(&result->sqs))
        success = false;
    if (!input.ReadDrawQuadState(&result->draw_quad_state))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool UnionTraits<::cc::mojom::DrawQuadState::DataView, ::cc::mojom::DrawQuadStatePtr>::Read(
    ::cc::mojom::DrawQuadState::DataView input,
    ::cc::mojom::DrawQuadStatePtr* output)
{
    *output = ::cc::mojom::DrawQuadState::New();
    ::cc::mojom::DrawQuadStatePtr& result = *output;

    internal::UnionAccessor<::cc::mojom::DrawQuadState> result_acc(result.get());
    switch (input.tag()) {
    case ::cc::mojom::DrawQuadState::Tag::DEBUG_BORDER_QUAD_STATE: {
        result_acc.SwitchActive(::cc::mojom::DrawQuadState::Tag::DEBUG_BORDER_QUAD_STATE);
        if (!input.ReadDebugBorderQuadState(result_acc.data()->debug_border_quad_state))
            return false;
        break;
    }
    case ::cc::mojom::DrawQuadState::Tag::RENDER_PASS_QUAD_STATE: {
        result_acc.SwitchActive(::cc::mojom::DrawQuadState::Tag::RENDER_PASS_QUAD_STATE);
        if (!input.ReadRenderPassQuadState(result_acc.data()->render_pass_quad_state))
            return false;
        break;
    }
    case ::cc::mojom::DrawQuadState::Tag::SOLID_COLOR_QUAD_STATE: {
        result_acc.SwitchActive(::cc::mojom::DrawQuadState::Tag::SOLID_COLOR_QUAD_STATE);
        if (!input.ReadSolidColorQuadState(result_acc.data()->solid_color_quad_state))
            return false;
        break;
    }
    case ::cc::mojom::DrawQuadState::Tag::STREAM_VIDEO_QUAD_STATE: {
        result_acc.SwitchActive(::cc::mojom::DrawQuadState::Tag::STREAM_VIDEO_QUAD_STATE);
        if (!input.ReadStreamVideoQuadState(result_acc.data()->stream_video_quad_state))
            return false;
        break;
    }
    case ::cc::mojom::DrawQuadState::Tag::SURFACE_QUAD_STATE: {
        result_acc.SwitchActive(::cc::mojom::DrawQuadState::Tag::SURFACE_QUAD_STATE);
        if (!input.ReadSurfaceQuadState(result_acc.data()->surface_quad_state))
            return false;
        break;
    }
    case ::cc::mojom::DrawQuadState::Tag::TEXTURE_QUAD_STATE: {
        result_acc.SwitchActive(::cc::mojom::DrawQuadState::Tag::TEXTURE_QUAD_STATE);
        if (!input.ReadTextureQuadState(result_acc.data()->texture_quad_state))
            return false;
        break;
    }
    case ::cc::mojom::DrawQuadState::Tag::TILE_QUAD_STATE: {
        result_acc.SwitchActive(::cc::mojom::DrawQuadState::Tag::TILE_QUAD_STATE);
        if (!input.ReadTileQuadState(result_acc.data()->tile_quad_state))
            return false;
        break;
    }
    case ::cc::mojom::DrawQuadState::Tag::YUV_VIDEO_QUAD_STATE: {
        result_acc.SwitchActive(::cc::mojom::DrawQuadState::Tag::YUV_VIDEO_QUAD_STATE);
        if (!input.ReadYuvVideoQuadState(result_acc.data()->yuv_video_quad_state))
            return false;
        break;
    }
    default:
        return false;
    }
    return true;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif