// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_QUADS_MOJOM_SHARED_H_
#define CC_IPC_QUADS_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "cc/ipc/filter_operations.mojom-shared.h"
#include "cc/ipc/quads.mojom-shared-internal.h"
#include "cc/ipc/shared_quad_state.mojom-shared.h"
#include "cc/ipc/surface_id.mojom-shared.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared.h"
#include "ui/gfx/mojo/transform.mojom-shared.h"

namespace cc {
namespace mojom {
    class DebugBorderQuadStateDataView;

    class RenderPassQuadStateDataView;

    class SolidColorQuadStateDataView;

    class StreamVideoQuadStateDataView;

    class SurfaceQuadStateDataView;

    class TextureQuadStateDataView;

    class TileQuadStateDataView;

    class YUVVideoQuadStateDataView;

    class DrawQuadDataView;

    class DrawQuadStateDataView;

} // namespace mojom
} // namespace cc

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::cc::mojom::DebugBorderQuadStateDataView> {
        using Data = ::cc::mojom::internal::DebugBorderQuadState_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::cc::mojom::RenderPassQuadStateDataView> {
        using Data = ::cc::mojom::internal::RenderPassQuadState_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::cc::mojom::SolidColorQuadStateDataView> {
        using Data = ::cc::mojom::internal::SolidColorQuadState_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::cc::mojom::StreamVideoQuadStateDataView> {
        using Data = ::cc::mojom::internal::StreamVideoQuadState_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::cc::mojom::SurfaceQuadStateDataView> {
        using Data = ::cc::mojom::internal::SurfaceQuadState_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::cc::mojom::TextureQuadStateDataView> {
        using Data = ::cc::mojom::internal::TextureQuadState_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::cc::mojom::TileQuadStateDataView> {
        using Data = ::cc::mojom::internal::TileQuadState_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::cc::mojom::YUVVideoQuadStateDataView> {
        using Data = ::cc::mojom::internal::YUVVideoQuadState_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::cc::mojom::DrawQuadDataView> {
        using Data = ::cc::mojom::internal::DrawQuad_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::cc::mojom::DrawQuadStateDataView> {
        using Data = ::cc::mojom::internal::DrawQuadState_Data;
        using DataAsArrayElement = Data;
        static constexpr MojomTypeCategory category = MojomTypeCategory::UNION;
    };

} // namespace internal
} // namespace mojo

namespace cc {
namespace mojom {

    enum class YUVColorSpace : int32_t {
        REC_601,
        REC_709,
        JPEG,
    };

    inline std::ostream& operator<<(std::ostream& os, YUVColorSpace value)
    {
        switch (value) {
        case YUVColorSpace::REC_601:
            return os << "YUVColorSpace::REC_601";
        case YUVColorSpace::REC_709:
            return os << "YUVColorSpace::REC_709";
        case YUVColorSpace::JPEG:
            return os << "YUVColorSpace::JPEG";
        default:
            return os << "Unknown YUVColorSpace value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(YUVColorSpace value)
    {
        return internal::YUVColorSpace_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    class DebugBorderQuadStateDataView {
    public:
        DebugBorderQuadStateDataView() { }

        DebugBorderQuadStateDataView(
            internal::DebugBorderQuadState_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t color() const
        {
            return data_->color;
        }
        int32_t width() const
        {
            return data_->width;
        }

    private:
        internal::DebugBorderQuadState_Data* data_ = nullptr;
    };

    class RenderPassQuadStateDataView {
    public:
        RenderPassQuadStateDataView() { }

        RenderPassQuadStateDataView(
            internal::RenderPassQuadState_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        int32_t render_pass_id() const
        {
            return data_->render_pass_id;
        }
        uint32_t mask_resource_id() const
        {
            return data_->mask_resource_id;
        }
        inline void GetMaskUvScaleDataView(
            ::gfx::mojom::Vector2dFDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMaskUvScale(UserType* output)
        {
            auto* pointer = data_->mask_uv_scale.Get();
            return mojo::internal::Deserialize<::gfx::mojom::Vector2dFDataView>(
                pointer, output, context_);
        }
        inline void GetMaskTextureSizeDataView(
            ::gfx::mojom::SizeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMaskTextureSize(UserType* output)
        {
            auto* pointer = data_->mask_texture_size.Get();
            return mojo::internal::Deserialize<::gfx::mojom::SizeDataView>(
                pointer, output, context_);
        }
        inline void GetFiltersScaleDataView(
            ::gfx::mojom::Vector2dFDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFiltersScale(UserType* output)
        {
            auto* pointer = data_->filters_scale.Get();
            return mojo::internal::Deserialize<::gfx::mojom::Vector2dFDataView>(
                pointer, output, context_);
        }
        inline void GetFiltersOriginDataView(
            ::gfx::mojom::PointFDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFiltersOrigin(UserType* output)
        {
            auto* pointer = data_->filters_origin.Get();
            return mojo::internal::Deserialize<::gfx::mojom::PointFDataView>(
                pointer, output, context_);
        }

    private:
        internal::RenderPassQuadState_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class SolidColorQuadStateDataView {
    public:
        SolidColorQuadStateDataView() { }

        SolidColorQuadStateDataView(
            internal::SolidColorQuadState_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t color() const
        {
            return data_->color;
        }
        bool force_anti_aliasing_off() const
        {
            return data_->force_anti_aliasing_off;
        }

    private:
        internal::SolidColorQuadState_Data* data_ = nullptr;
    };

    class StreamVideoQuadStateDataView {
    public:
        StreamVideoQuadStateDataView() { }

        StreamVideoQuadStateDataView(
            internal::StreamVideoQuadState_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t resource_id() const
        {
            return data_->resource_id;
        }
        inline void GetResourceSizeInPixelsDataView(
            ::gfx::mojom::SizeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadResourceSizeInPixels(UserType* output)
        {
            auto* pointer = data_->resource_size_in_pixels.Get();
            return mojo::internal::Deserialize<::gfx::mojom::SizeDataView>(
                pointer, output, context_);
        }
        inline void GetMatrixDataView(
            ::gfx::mojom::TransformDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMatrix(UserType* output)
        {
            auto* pointer = data_->matrix.Get();
            return mojo::internal::Deserialize<::gfx::mojom::TransformDataView>(
                pointer, output, context_);
        }

    private:
        internal::StreamVideoQuadState_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class SurfaceQuadStateDataView {
    public:
        SurfaceQuadStateDataView() { }

        SurfaceQuadStateDataView(
            internal::SurfaceQuadState_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetSurfaceDataView(
            ::cc::mojom::SurfaceIdDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSurface(UserType* output)
        {
            auto* pointer = data_->surface.Get();
            return mojo::internal::Deserialize<::cc::mojom::SurfaceIdDataView>(
                pointer, output, context_);
        }

    private:
        internal::SurfaceQuadState_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class TextureQuadStateDataView {
    public:
        TextureQuadStateDataView() { }

        TextureQuadStateDataView(
            internal::TextureQuadState_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t resource_id() const
        {
            return data_->resource_id;
        }
        inline void GetResourceSizeInPixelsDataView(
            ::gfx::mojom::SizeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadResourceSizeInPixels(UserType* output)
        {
            auto* pointer = data_->resource_size_in_pixels.Get();
            return mojo::internal::Deserialize<::gfx::mojom::SizeDataView>(
                pointer, output, context_);
        }
        bool premultiplied_alpha() const
        {
            return data_->premultiplied_alpha;
        }
        inline void GetUvTopLeftDataView(
            ::gfx::mojom::PointFDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadUvTopLeft(UserType* output)
        {
            auto* pointer = data_->uv_top_left.Get();
            return mojo::internal::Deserialize<::gfx::mojom::PointFDataView>(
                pointer, output, context_);
        }
        inline void GetUvBottomRightDataView(
            ::gfx::mojom::PointFDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadUvBottomRight(UserType* output)
        {
            auto* pointer = data_->uv_bottom_right.Get();
            return mojo::internal::Deserialize<::gfx::mojom::PointFDataView>(
                pointer, output, context_);
        }
        uint32_t background_color() const
        {
            return data_->background_color;
        }
        inline void GetVertexOpacityDataView(
            mojo::ArrayDataView<float>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadVertexOpacity(UserType* output)
        {
            auto* pointer = data_->vertex_opacity.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<float>>(
                pointer, output, context_);
        }
        bool y_flipped() const
        {
            return data_->y_flipped;
        }
        bool nearest_neighbor() const
        {
            return data_->nearest_neighbor;
        }
        bool secure_output_only() const
        {
            return data_->secure_output_only;
        }

    private:
        internal::TextureQuadState_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class TileQuadStateDataView {
    public:
        TileQuadStateDataView() { }

        TileQuadStateDataView(
            internal::TileQuadState_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetTexCoordRectDataView(
            ::gfx::mojom::RectFDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTexCoordRect(UserType* output)
        {
            auto* pointer = data_->tex_coord_rect.Get();
            return mojo::internal::Deserialize<::gfx::mojom::RectFDataView>(
                pointer, output, context_);
        }
        inline void GetTextureSizeDataView(
            ::gfx::mojom::SizeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTextureSize(UserType* output)
        {
            auto* pointer = data_->texture_size.Get();
            return mojo::internal::Deserialize<::gfx::mojom::SizeDataView>(
                pointer, output, context_);
        }
        bool swizzle_contents() const
        {
            return data_->swizzle_contents;
        }
        uint32_t resource_id() const
        {
            return data_->resource_id;
        }
        bool nearest_neighbor() const
        {
            return data_->nearest_neighbor;
        }

    private:
        internal::TileQuadState_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class YUVVideoQuadStateDataView {
    public:
        YUVVideoQuadStateDataView() { }

        YUVVideoQuadStateDataView(
            internal::YUVVideoQuadState_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetYaTexCoordRectDataView(
            ::gfx::mojom::RectFDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadYaTexCoordRect(UserType* output)
        {
            auto* pointer = data_->ya_tex_coord_rect.Get();
            return mojo::internal::Deserialize<::gfx::mojom::RectFDataView>(
                pointer, output, context_);
        }
        inline void GetUvTexCoordRectDataView(
            ::gfx::mojom::RectFDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadUvTexCoordRect(UserType* output)
        {
            auto* pointer = data_->uv_tex_coord_rect.Get();
            return mojo::internal::Deserialize<::gfx::mojom::RectFDataView>(
                pointer, output, context_);
        }
        inline void GetYaTexSizeDataView(
            ::gfx::mojom::SizeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadYaTexSize(UserType* output)
        {
            auto* pointer = data_->ya_tex_size.Get();
            return mojo::internal::Deserialize<::gfx::mojom::SizeDataView>(
                pointer, output, context_);
        }
        inline void GetUvTexSizeDataView(
            ::gfx::mojom::SizeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadUvTexSize(UserType* output)
        {
            auto* pointer = data_->uv_tex_size.Get();
            return mojo::internal::Deserialize<::gfx::mojom::SizeDataView>(
                pointer, output, context_);
        }
        uint32_t y_plane_resource_id() const
        {
            return data_->y_plane_resource_id;
        }
        uint32_t u_plane_resource_id() const
        {
            return data_->u_plane_resource_id;
        }
        uint32_t v_plane_resource_id() const
        {
            return data_->v_plane_resource_id;
        }
        uint32_t a_plane_resource_id() const
        {
            return data_->a_plane_resource_id;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadColorSpace(UserType* output) const
        {
            auto data_value = data_->color_space;
            return mojo::internal::Deserialize<::cc::mojom::YUVColorSpace>(
                data_value, output);
        }

        YUVColorSpace color_space() const
        {
            return static_cast<YUVColorSpace>(data_->color_space);
        }
        float resource_offset() const
        {
            return data_->resource_offset;
        }
        float resource_multiplier() const
        {
            return data_->resource_multiplier;
        }
        uint32_t bits_per_channel() const
        {
            return data_->bits_per_channel;
        }

    private:
        internal::YUVVideoQuadState_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class DrawQuadDataView {
    public:
        DrawQuadDataView() { }

        DrawQuadDataView(
            internal::DrawQuad_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetRectDataView(
            ::gfx::mojom::RectDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadRect(UserType* output)
        {
            auto* pointer = data_->rect.Get();
            return mojo::internal::Deserialize<::gfx::mojom::RectDataView>(
                pointer, output, context_);
        }
        inline void GetOpaqueRectDataView(
            ::gfx::mojom::RectDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOpaqueRect(UserType* output)
        {
            auto* pointer = data_->opaque_rect.Get();
            return mojo::internal::Deserialize<::gfx::mojom::RectDataView>(
                pointer, output, context_);
        }
        inline void GetVisibleRectDataView(
            ::gfx::mojom::RectDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadVisibleRect(UserType* output)
        {
            auto* pointer = data_->visible_rect.Get();
            return mojo::internal::Deserialize<::gfx::mojom::RectDataView>(
                pointer, output, context_);
        }
        bool needs_blending() const
        {
            return data_->needs_blending;
        }
        inline void GetSqsDataView(
            ::cc::mojom::SharedQuadStateDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSqs(UserType* output)
        {
            auto* pointer = data_->sqs.Get();
            return mojo::internal::Deserialize<::cc::mojom::SharedQuadStateDataView>(
                pointer, output, context_);
        }
        inline void GetDrawQuadStateDataView(
            DrawQuadStateDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDrawQuadState(UserType* output)
        {
            auto* pointer = &data_->draw_quad_state;
            return mojo::internal::Deserialize<::cc::mojom::DrawQuadStateDataView>(
                pointer, output, context_);
        }

    private:
        internal::DrawQuad_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class DrawQuadStateDataView {
    public:
        using Tag = internal::DrawQuadState_Data::DrawQuadState_Tag;

        DrawQuadStateDataView() { }

        DrawQuadStateDataView(
            internal::DrawQuadState_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const
        {
            // For inlined unions, |data_| is always non-null. In that case we need to
            // check |data_->is_null()|.
            return !data_ || data_->is_null();
        }

        Tag tag() const { return data_->tag; }
        bool is_debug_border_quad_state() const { return data_->tag == Tag::DEBUG_BORDER_QUAD_STATE; }
        inline void GetDebugBorderQuadStateDataView(
            DebugBorderQuadStateDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDebugBorderQuadState(UserType* output)
        {
            DCHECK(is_debug_border_quad_state());
            return mojo::internal::Deserialize<::cc::mojom::DebugBorderQuadStateDataView>(
                data_->data.f_debug_border_quad_state.Get(), output, context_);
        }
        bool is_render_pass_quad_state() const { return data_->tag == Tag::RENDER_PASS_QUAD_STATE; }
        inline void GetRenderPassQuadStateDataView(
            RenderPassQuadStateDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadRenderPassQuadState(UserType* output)
        {
            DCHECK(is_render_pass_quad_state());
            return mojo::internal::Deserialize<::cc::mojom::RenderPassQuadStateDataView>(
                data_->data.f_render_pass_quad_state.Get(), output, context_);
        }
        bool is_solid_color_quad_state() const { return data_->tag == Tag::SOLID_COLOR_QUAD_STATE; }
        inline void GetSolidColorQuadStateDataView(
            SolidColorQuadStateDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSolidColorQuadState(UserType* output)
        {
            DCHECK(is_solid_color_quad_state());
            return mojo::internal::Deserialize<::cc::mojom::SolidColorQuadStateDataView>(
                data_->data.f_solid_color_quad_state.Get(), output, context_);
        }
        bool is_stream_video_quad_state() const { return data_->tag == Tag::STREAM_VIDEO_QUAD_STATE; }
        inline void GetStreamVideoQuadStateDataView(
            StreamVideoQuadStateDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStreamVideoQuadState(UserType* output)
        {
            DCHECK(is_stream_video_quad_state());
            return mojo::internal::Deserialize<::cc::mojom::StreamVideoQuadStateDataView>(
                data_->data.f_stream_video_quad_state.Get(), output, context_);
        }
        bool is_surface_quad_state() const { return data_->tag == Tag::SURFACE_QUAD_STATE; }
        inline void GetSurfaceQuadStateDataView(
            SurfaceQuadStateDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSurfaceQuadState(UserType* output)
        {
            DCHECK(is_surface_quad_state());
            return mojo::internal::Deserialize<::cc::mojom::SurfaceQuadStateDataView>(
                data_->data.f_surface_quad_state.Get(), output, context_);
        }
        bool is_texture_quad_state() const { return data_->tag == Tag::TEXTURE_QUAD_STATE; }
        inline void GetTextureQuadStateDataView(
            TextureQuadStateDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTextureQuadState(UserType* output)
        {
            DCHECK(is_texture_quad_state());
            return mojo::internal::Deserialize<::cc::mojom::TextureQuadStateDataView>(
                data_->data.f_texture_quad_state.Get(), output, context_);
        }
        bool is_tile_quad_state() const { return data_->tag == Tag::TILE_QUAD_STATE; }
        inline void GetTileQuadStateDataView(
            TileQuadStateDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTileQuadState(UserType* output)
        {
            DCHECK(is_tile_quad_state());
            return mojo::internal::Deserialize<::cc::mojom::TileQuadStateDataView>(
                data_->data.f_tile_quad_state.Get(), output, context_);
        }
        bool is_yuv_video_quad_state() const { return data_->tag == Tag::YUV_VIDEO_QUAD_STATE; }
        inline void GetYuvVideoQuadStateDataView(
            YUVVideoQuadStateDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadYuvVideoQuadState(UserType* output)
        {
            DCHECK(is_yuv_video_quad_state());
            return mojo::internal::Deserialize<::cc::mojom::YUVVideoQuadStateDataView>(
                data_->data.f_yuv_video_quad_state.Get(), output, context_);
        }

    private:
        internal::DrawQuadState_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace cc

namespace std {

template <>
struct hash<::cc::mojom::YUVColorSpace>
    : public mojo::internal::EnumHashImpl<::cc::mojom::YUVColorSpace> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::cc::mojom::YUVColorSpace, ::cc::mojom::YUVColorSpace> {
    static ::cc::mojom::YUVColorSpace ToMojom(::cc::mojom::YUVColorSpace input) { return input; }
    static bool FromMojom(::cc::mojom::YUVColorSpace input, ::cc::mojom::YUVColorSpace* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::cc::mojom::YUVColorSpace, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::cc::mojom::YUVColorSpace, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::cc::mojom::YUVColorSpace>(input), output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::cc::mojom::DebugBorderQuadStateDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::cc::mojom::DebugBorderQuadStateDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::cc::mojom::internal::DebugBorderQuadState_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::cc::mojom::internal::DebugBorderQuadState_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::cc::mojom::internal::DebugBorderQuadState_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->color = CallWithContext(Traits::color, input, custom_context);
            result->width = CallWithContext(Traits::width, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::cc::mojom::internal::DebugBorderQuadState_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::cc::mojom::DebugBorderQuadStateDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::cc::mojom::RenderPassQuadStateDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::cc::mojom::RenderPassQuadStateDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::cc::mojom::internal::RenderPassQuadState_Data);
            decltype(CallWithContext(Traits::mask_uv_scale, input, custom_context)) in_mask_uv_scale = CallWithContext(Traits::mask_uv_scale, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::Vector2dFDataView>(
                in_mask_uv_scale, context);
            decltype(CallWithContext(Traits::mask_texture_size, input, custom_context)) in_mask_texture_size = CallWithContext(Traits::mask_texture_size, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::SizeDataView>(
                in_mask_texture_size, context);
            decltype(CallWithContext(Traits::filters_scale, input, custom_context)) in_filters_scale = CallWithContext(Traits::filters_scale, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::Vector2dFDataView>(
                in_filters_scale, context);
            decltype(CallWithContext(Traits::filters_origin, input, custom_context)) in_filters_origin = CallWithContext(Traits::filters_origin, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::PointFDataView>(
                in_filters_origin, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::cc::mojom::internal::RenderPassQuadState_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::cc::mojom::internal::RenderPassQuadState_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->render_pass_id = CallWithContext(Traits::render_pass_id, input, custom_context);
            result->mask_resource_id = CallWithContext(Traits::mask_resource_id, input, custom_context);
            decltype(CallWithContext(Traits::mask_uv_scale, input, custom_context)) in_mask_uv_scale = CallWithContext(Traits::mask_uv_scale, input, custom_context);
            typename decltype(result->mask_uv_scale)::BaseType* mask_uv_scale_ptr;
            mojo::internal::Serialize<::gfx::mojom::Vector2dFDataView>(
                in_mask_uv_scale, buffer, &mask_uv_scale_ptr, context);
            result->mask_uv_scale.Set(mask_uv_scale_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->mask_uv_scale.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null mask_uv_scale in RenderPassQuadState struct");
            decltype(CallWithContext(Traits::mask_texture_size, input, custom_context)) in_mask_texture_size = CallWithContext(Traits::mask_texture_size, input, custom_context);
            typename decltype(result->mask_texture_size)::BaseType* mask_texture_size_ptr;
            mojo::internal::Serialize<::gfx::mojom::SizeDataView>(
                in_mask_texture_size, buffer, &mask_texture_size_ptr, context);
            result->mask_texture_size.Set(mask_texture_size_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->mask_texture_size.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null mask_texture_size in RenderPassQuadState struct");
            decltype(CallWithContext(Traits::filters_scale, input, custom_context)) in_filters_scale = CallWithContext(Traits::filters_scale, input, custom_context);
            typename decltype(result->filters_scale)::BaseType* filters_scale_ptr;
            mojo::internal::Serialize<::gfx::mojom::Vector2dFDataView>(
                in_filters_scale, buffer, &filters_scale_ptr, context);
            result->filters_scale.Set(filters_scale_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->filters_scale.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null filters_scale in RenderPassQuadState struct");
            decltype(CallWithContext(Traits::filters_origin, input, custom_context)) in_filters_origin = CallWithContext(Traits::filters_origin, input, custom_context);
            typename decltype(result->filters_origin)::BaseType* filters_origin_ptr;
            mojo::internal::Serialize<::gfx::mojom::PointFDataView>(
                in_filters_origin, buffer, &filters_origin_ptr, context);
            result->filters_origin.Set(filters_origin_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->filters_origin.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null filters_origin in RenderPassQuadState struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::cc::mojom::internal::RenderPassQuadState_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::cc::mojom::RenderPassQuadStateDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::cc::mojom::SolidColorQuadStateDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::cc::mojom::SolidColorQuadStateDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::cc::mojom::internal::SolidColorQuadState_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::cc::mojom::internal::SolidColorQuadState_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::cc::mojom::internal::SolidColorQuadState_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->color = CallWithContext(Traits::color, input, custom_context);
            result->force_anti_aliasing_off = CallWithContext(Traits::force_anti_aliasing_off, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::cc::mojom::internal::SolidColorQuadState_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::cc::mojom::SolidColorQuadStateDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::cc::mojom::StreamVideoQuadStateDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::cc::mojom::StreamVideoQuadStateDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::cc::mojom::internal::StreamVideoQuadState_Data);
            decltype(CallWithContext(Traits::resource_size_in_pixels, input, custom_context)) in_resource_size_in_pixels = CallWithContext(Traits::resource_size_in_pixels, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::SizeDataView>(
                in_resource_size_in_pixels, context);
            decltype(CallWithContext(Traits::matrix, input, custom_context)) in_matrix = CallWithContext(Traits::matrix, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::TransformDataView>(
                in_matrix, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::cc::mojom::internal::StreamVideoQuadState_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::cc::mojom::internal::StreamVideoQuadState_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->resource_id = CallWithContext(Traits::resource_id, input, custom_context);
            decltype(CallWithContext(Traits::resource_size_in_pixels, input, custom_context)) in_resource_size_in_pixels = CallWithContext(Traits::resource_size_in_pixels, input, custom_context);
            typename decltype(result->resource_size_in_pixels)::BaseType* resource_size_in_pixels_ptr;
            mojo::internal::Serialize<::gfx::mojom::SizeDataView>(
                in_resource_size_in_pixels, buffer, &resource_size_in_pixels_ptr, context);
            result->resource_size_in_pixels.Set(resource_size_in_pixels_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->resource_size_in_pixels.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null resource_size_in_pixels in StreamVideoQuadState struct");
            decltype(CallWithContext(Traits::matrix, input, custom_context)) in_matrix = CallWithContext(Traits::matrix, input, custom_context);
            typename decltype(result->matrix)::BaseType* matrix_ptr;
            mojo::internal::Serialize<::gfx::mojom::TransformDataView>(
                in_matrix, buffer, &matrix_ptr, context);
            result->matrix.Set(matrix_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->matrix.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null matrix in StreamVideoQuadState struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::cc::mojom::internal::StreamVideoQuadState_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::cc::mojom::StreamVideoQuadStateDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::cc::mojom::SurfaceQuadStateDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::cc::mojom::SurfaceQuadStateDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::cc::mojom::internal::SurfaceQuadState_Data);
            decltype(CallWithContext(Traits::surface, input, custom_context)) in_surface = CallWithContext(Traits::surface, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::cc::mojom::SurfaceIdDataView>(
                in_surface, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::cc::mojom::internal::SurfaceQuadState_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::cc::mojom::internal::SurfaceQuadState_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::surface, input, custom_context)) in_surface = CallWithContext(Traits::surface, input, custom_context);
            typename decltype(result->surface)::BaseType* surface_ptr;
            mojo::internal::Serialize<::cc::mojom::SurfaceIdDataView>(
                in_surface, buffer, &surface_ptr, context);
            result->surface.Set(surface_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->surface.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null surface in SurfaceQuadState struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::cc::mojom::internal::SurfaceQuadState_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::cc::mojom::SurfaceQuadStateDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::cc::mojom::TextureQuadStateDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::cc::mojom::TextureQuadStateDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::cc::mojom::internal::TextureQuadState_Data);
            decltype(CallWithContext(Traits::resource_size_in_pixels, input, custom_context)) in_resource_size_in_pixels = CallWithContext(Traits::resource_size_in_pixels, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::SizeDataView>(
                in_resource_size_in_pixels, context);
            decltype(CallWithContext(Traits::uv_top_left, input, custom_context)) in_uv_top_left = CallWithContext(Traits::uv_top_left, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::PointFDataView>(
                in_uv_top_left, context);
            decltype(CallWithContext(Traits::uv_bottom_right, input, custom_context)) in_uv_bottom_right = CallWithContext(Traits::uv_bottom_right, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::PointFDataView>(
                in_uv_bottom_right, context);
            decltype(CallWithContext(Traits::vertex_opacity, input, custom_context)) in_vertex_opacity = CallWithContext(Traits::vertex_opacity, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<float>>(
                in_vertex_opacity, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::cc::mojom::internal::TextureQuadState_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::cc::mojom::internal::TextureQuadState_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->resource_id = CallWithContext(Traits::resource_id, input, custom_context);
            decltype(CallWithContext(Traits::resource_size_in_pixels, input, custom_context)) in_resource_size_in_pixels = CallWithContext(Traits::resource_size_in_pixels, input, custom_context);
            typename decltype(result->resource_size_in_pixels)::BaseType* resource_size_in_pixels_ptr;
            mojo::internal::Serialize<::gfx::mojom::SizeDataView>(
                in_resource_size_in_pixels, buffer, &resource_size_in_pixels_ptr, context);
            result->resource_size_in_pixels.Set(resource_size_in_pixels_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->resource_size_in_pixels.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null resource_size_in_pixels in TextureQuadState struct");
            result->premultiplied_alpha = CallWithContext(Traits::premultiplied_alpha, input, custom_context);
            decltype(CallWithContext(Traits::uv_top_left, input, custom_context)) in_uv_top_left = CallWithContext(Traits::uv_top_left, input, custom_context);
            typename decltype(result->uv_top_left)::BaseType* uv_top_left_ptr;
            mojo::internal::Serialize<::gfx::mojom::PointFDataView>(
                in_uv_top_left, buffer, &uv_top_left_ptr, context);
            result->uv_top_left.Set(uv_top_left_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->uv_top_left.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null uv_top_left in TextureQuadState struct");
            decltype(CallWithContext(Traits::uv_bottom_right, input, custom_context)) in_uv_bottom_right = CallWithContext(Traits::uv_bottom_right, input, custom_context);
            typename decltype(result->uv_bottom_right)::BaseType* uv_bottom_right_ptr;
            mojo::internal::Serialize<::gfx::mojom::PointFDataView>(
                in_uv_bottom_right, buffer, &uv_bottom_right_ptr, context);
            result->uv_bottom_right.Set(uv_bottom_right_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->uv_bottom_right.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null uv_bottom_right in TextureQuadState struct");
            result->background_color = CallWithContext(Traits::background_color, input, custom_context);
            decltype(CallWithContext(Traits::vertex_opacity, input, custom_context)) in_vertex_opacity = CallWithContext(Traits::vertex_opacity, input, custom_context);
            typename decltype(result->vertex_opacity)::BaseType* vertex_opacity_ptr;
            const mojo::internal::ContainerValidateParams vertex_opacity_validate_params(
                4, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<float>>(
                in_vertex_opacity, buffer, &vertex_opacity_ptr, &vertex_opacity_validate_params,
                context);
            result->vertex_opacity.Set(vertex_opacity_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->vertex_opacity.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null vertex_opacity in TextureQuadState struct");
            result->y_flipped = CallWithContext(Traits::y_flipped, input, custom_context);
            result->nearest_neighbor = CallWithContext(Traits::nearest_neighbor, input, custom_context);
            result->secure_output_only = CallWithContext(Traits::secure_output_only, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::cc::mojom::internal::TextureQuadState_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::cc::mojom::TextureQuadStateDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::cc::mojom::TileQuadStateDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::cc::mojom::TileQuadStateDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::cc::mojom::internal::TileQuadState_Data);
            decltype(CallWithContext(Traits::tex_coord_rect, input, custom_context)) in_tex_coord_rect = CallWithContext(Traits::tex_coord_rect, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::RectFDataView>(
                in_tex_coord_rect, context);
            decltype(CallWithContext(Traits::texture_size, input, custom_context)) in_texture_size = CallWithContext(Traits::texture_size, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::SizeDataView>(
                in_texture_size, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::cc::mojom::internal::TileQuadState_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::cc::mojom::internal::TileQuadState_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::tex_coord_rect, input, custom_context)) in_tex_coord_rect = CallWithContext(Traits::tex_coord_rect, input, custom_context);
            typename decltype(result->tex_coord_rect)::BaseType* tex_coord_rect_ptr;
            mojo::internal::Serialize<::gfx::mojom::RectFDataView>(
                in_tex_coord_rect, buffer, &tex_coord_rect_ptr, context);
            result->tex_coord_rect.Set(tex_coord_rect_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->tex_coord_rect.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null tex_coord_rect in TileQuadState struct");
            decltype(CallWithContext(Traits::texture_size, input, custom_context)) in_texture_size = CallWithContext(Traits::texture_size, input, custom_context);
            typename decltype(result->texture_size)::BaseType* texture_size_ptr;
            mojo::internal::Serialize<::gfx::mojom::SizeDataView>(
                in_texture_size, buffer, &texture_size_ptr, context);
            result->texture_size.Set(texture_size_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->texture_size.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null texture_size in TileQuadState struct");
            result->swizzle_contents = CallWithContext(Traits::swizzle_contents, input, custom_context);
            result->resource_id = CallWithContext(Traits::resource_id, input, custom_context);
            result->nearest_neighbor = CallWithContext(Traits::nearest_neighbor, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::cc::mojom::internal::TileQuadState_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::cc::mojom::TileQuadStateDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::cc::mojom::YUVVideoQuadStateDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::cc::mojom::YUVVideoQuadStateDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::cc::mojom::internal::YUVVideoQuadState_Data);
            decltype(CallWithContext(Traits::ya_tex_coord_rect, input, custom_context)) in_ya_tex_coord_rect = CallWithContext(Traits::ya_tex_coord_rect, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::RectFDataView>(
                in_ya_tex_coord_rect, context);
            decltype(CallWithContext(Traits::uv_tex_coord_rect, input, custom_context)) in_uv_tex_coord_rect = CallWithContext(Traits::uv_tex_coord_rect, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::RectFDataView>(
                in_uv_tex_coord_rect, context);
            decltype(CallWithContext(Traits::ya_tex_size, input, custom_context)) in_ya_tex_size = CallWithContext(Traits::ya_tex_size, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::SizeDataView>(
                in_ya_tex_size, context);
            decltype(CallWithContext(Traits::uv_tex_size, input, custom_context)) in_uv_tex_size = CallWithContext(Traits::uv_tex_size, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::SizeDataView>(
                in_uv_tex_size, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::cc::mojom::internal::YUVVideoQuadState_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::cc::mojom::internal::YUVVideoQuadState_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::ya_tex_coord_rect, input, custom_context)) in_ya_tex_coord_rect = CallWithContext(Traits::ya_tex_coord_rect, input, custom_context);
            typename decltype(result->ya_tex_coord_rect)::BaseType* ya_tex_coord_rect_ptr;
            mojo::internal::Serialize<::gfx::mojom::RectFDataView>(
                in_ya_tex_coord_rect, buffer, &ya_tex_coord_rect_ptr, context);
            result->ya_tex_coord_rect.Set(ya_tex_coord_rect_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->ya_tex_coord_rect.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null ya_tex_coord_rect in YUVVideoQuadState struct");
            decltype(CallWithContext(Traits::uv_tex_coord_rect, input, custom_context)) in_uv_tex_coord_rect = CallWithContext(Traits::uv_tex_coord_rect, input, custom_context);
            typename decltype(result->uv_tex_coord_rect)::BaseType* uv_tex_coord_rect_ptr;
            mojo::internal::Serialize<::gfx::mojom::RectFDataView>(
                in_uv_tex_coord_rect, buffer, &uv_tex_coord_rect_ptr, context);
            result->uv_tex_coord_rect.Set(uv_tex_coord_rect_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->uv_tex_coord_rect.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null uv_tex_coord_rect in YUVVideoQuadState struct");
            decltype(CallWithContext(Traits::ya_tex_size, input, custom_context)) in_ya_tex_size = CallWithContext(Traits::ya_tex_size, input, custom_context);
            typename decltype(result->ya_tex_size)::BaseType* ya_tex_size_ptr;
            mojo::internal::Serialize<::gfx::mojom::SizeDataView>(
                in_ya_tex_size, buffer, &ya_tex_size_ptr, context);
            result->ya_tex_size.Set(ya_tex_size_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->ya_tex_size.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null ya_tex_size in YUVVideoQuadState struct");
            decltype(CallWithContext(Traits::uv_tex_size, input, custom_context)) in_uv_tex_size = CallWithContext(Traits::uv_tex_size, input, custom_context);
            typename decltype(result->uv_tex_size)::BaseType* uv_tex_size_ptr;
            mojo::internal::Serialize<::gfx::mojom::SizeDataView>(
                in_uv_tex_size, buffer, &uv_tex_size_ptr, context);
            result->uv_tex_size.Set(uv_tex_size_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->uv_tex_size.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null uv_tex_size in YUVVideoQuadState struct");
            result->y_plane_resource_id = CallWithContext(Traits::y_plane_resource_id, input, custom_context);
            result->u_plane_resource_id = CallWithContext(Traits::u_plane_resource_id, input, custom_context);
            result->v_plane_resource_id = CallWithContext(Traits::v_plane_resource_id, input, custom_context);
            result->a_plane_resource_id = CallWithContext(Traits::a_plane_resource_id, input, custom_context);
            mojo::internal::Serialize<::cc::mojom::YUVColorSpace>(
                CallWithContext(Traits::color_space, input, custom_context), &result->color_space);
            result->resource_offset = CallWithContext(Traits::resource_offset, input, custom_context);
            result->resource_multiplier = CallWithContext(Traits::resource_multiplier, input, custom_context);
            result->bits_per_channel = CallWithContext(Traits::bits_per_channel, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::cc::mojom::internal::YUVVideoQuadState_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::cc::mojom::YUVVideoQuadStateDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::cc::mojom::DrawQuadDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::cc::mojom::DrawQuadDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::cc::mojom::internal::DrawQuad_Data);
            decltype(CallWithContext(Traits::rect, input, custom_context)) in_rect = CallWithContext(Traits::rect, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::RectDataView>(
                in_rect, context);
            decltype(CallWithContext(Traits::opaque_rect, input, custom_context)) in_opaque_rect = CallWithContext(Traits::opaque_rect, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::RectDataView>(
                in_opaque_rect, context);
            decltype(CallWithContext(Traits::visible_rect, input, custom_context)) in_visible_rect = CallWithContext(Traits::visible_rect, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::RectDataView>(
                in_visible_rect, context);
            decltype(CallWithContext(Traits::sqs, input, custom_context)) in_sqs = CallWithContext(Traits::sqs, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::cc::mojom::SharedQuadStateDataView>(
                in_sqs, context);
            decltype(CallWithContext(Traits::draw_quad_state, input, custom_context)) in_draw_quad_state = CallWithContext(Traits::draw_quad_state, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::cc::mojom::DrawQuadStateDataView>(
                in_draw_quad_state, true, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::cc::mojom::internal::DrawQuad_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::cc::mojom::internal::DrawQuad_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::rect, input, custom_context)) in_rect = CallWithContext(Traits::rect, input, custom_context);
            typename decltype(result->rect)::BaseType* rect_ptr;
            mojo::internal::Serialize<::gfx::mojom::RectDataView>(
                in_rect, buffer, &rect_ptr, context);
            result->rect.Set(rect_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->rect.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null rect in DrawQuad struct");
            decltype(CallWithContext(Traits::opaque_rect, input, custom_context)) in_opaque_rect = CallWithContext(Traits::opaque_rect, input, custom_context);
            typename decltype(result->opaque_rect)::BaseType* opaque_rect_ptr;
            mojo::internal::Serialize<::gfx::mojom::RectDataView>(
                in_opaque_rect, buffer, &opaque_rect_ptr, context);
            result->opaque_rect.Set(opaque_rect_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->opaque_rect.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null opaque_rect in DrawQuad struct");
            decltype(CallWithContext(Traits::visible_rect, input, custom_context)) in_visible_rect = CallWithContext(Traits::visible_rect, input, custom_context);
            typename decltype(result->visible_rect)::BaseType* visible_rect_ptr;
            mojo::internal::Serialize<::gfx::mojom::RectDataView>(
                in_visible_rect, buffer, &visible_rect_ptr, context);
            result->visible_rect.Set(visible_rect_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->visible_rect.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null visible_rect in DrawQuad struct");
            result->needs_blending = CallWithContext(Traits::needs_blending, input, custom_context);
            decltype(CallWithContext(Traits::sqs, input, custom_context)) in_sqs = CallWithContext(Traits::sqs, input, custom_context);
            typename decltype(result->sqs)::BaseType* sqs_ptr;
            mojo::internal::Serialize<::cc::mojom::SharedQuadStateDataView>(
                in_sqs, buffer, &sqs_ptr, context);
            result->sqs.Set(sqs_ptr);
            decltype(CallWithContext(Traits::draw_quad_state, input, custom_context)) in_draw_quad_state = CallWithContext(Traits::draw_quad_state, input, custom_context);
            auto draw_quad_state_ptr = &result->draw_quad_state;
            mojo::internal::Serialize<::cc::mojom::DrawQuadStateDataView>(
                in_draw_quad_state, buffer, &draw_quad_state_ptr, true, context);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->draw_quad_state.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null draw_quad_state in DrawQuad struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::cc::mojom::internal::DrawQuad_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::cc::mojom::DrawQuadDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::cc::mojom::DrawQuadStateDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = UnionTraits<::cc::mojom::DrawQuadStateDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            bool inlined,
            SerializationContext* context)
        {
            size_t size = inlined ? 0 : sizeof(::cc::mojom::internal::DrawQuadState_Data);

            if (CallIsNullIfExists<Traits>(input))
                return size;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            switch (CallWithContext(Traits::GetTag, input, custom_context)) {
            case ::cc::mojom::DrawQuadStateDataView::Tag::DEBUG_BORDER_QUAD_STATE: {
                decltype(CallWithContext(Traits::debug_border_quad_state, input, custom_context))
                    in_debug_border_quad_state
                    = CallWithContext(Traits::debug_border_quad_state, input,
                        custom_context);
                size += mojo::internal::PrepareToSerialize<::cc::mojom::DebugBorderQuadStateDataView>(
                    in_debug_border_quad_state, context);
                break;
            }
            case ::cc::mojom::DrawQuadStateDataView::Tag::RENDER_PASS_QUAD_STATE: {
                decltype(CallWithContext(Traits::render_pass_quad_state, input, custom_context))
                    in_render_pass_quad_state
                    = CallWithContext(Traits::render_pass_quad_state, input,
                        custom_context);
                size += mojo::internal::PrepareToSerialize<::cc::mojom::RenderPassQuadStateDataView>(
                    in_render_pass_quad_state, context);
                break;
            }
            case ::cc::mojom::DrawQuadStateDataView::Tag::SOLID_COLOR_QUAD_STATE: {
                decltype(CallWithContext(Traits::solid_color_quad_state, input, custom_context))
                    in_solid_color_quad_state
                    = CallWithContext(Traits::solid_color_quad_state, input,
                        custom_context);
                size += mojo::internal::PrepareToSerialize<::cc::mojom::SolidColorQuadStateDataView>(
                    in_solid_color_quad_state, context);
                break;
            }
            case ::cc::mojom::DrawQuadStateDataView::Tag::STREAM_VIDEO_QUAD_STATE: {
                decltype(CallWithContext(Traits::stream_video_quad_state, input, custom_context))
                    in_stream_video_quad_state
                    = CallWithContext(Traits::stream_video_quad_state, input,
                        custom_context);
                size += mojo::internal::PrepareToSerialize<::cc::mojom::StreamVideoQuadStateDataView>(
                    in_stream_video_quad_state, context);
                break;
            }
            case ::cc::mojom::DrawQuadStateDataView::Tag::SURFACE_QUAD_STATE: {
                decltype(CallWithContext(Traits::surface_quad_state, input, custom_context))
                    in_surface_quad_state
                    = CallWithContext(Traits::surface_quad_state, input,
                        custom_context);
                size += mojo::internal::PrepareToSerialize<::cc::mojom::SurfaceQuadStateDataView>(
                    in_surface_quad_state, context);
                break;
            }
            case ::cc::mojom::DrawQuadStateDataView::Tag::TEXTURE_QUAD_STATE: {
                decltype(CallWithContext(Traits::texture_quad_state, input, custom_context))
                    in_texture_quad_state
                    = CallWithContext(Traits::texture_quad_state, input,
                        custom_context);
                size += mojo::internal::PrepareToSerialize<::cc::mojom::TextureQuadStateDataView>(
                    in_texture_quad_state, context);
                break;
            }
            case ::cc::mojom::DrawQuadStateDataView::Tag::TILE_QUAD_STATE: {
                decltype(CallWithContext(Traits::tile_quad_state, input, custom_context))
                    in_tile_quad_state
                    = CallWithContext(Traits::tile_quad_state, input,
                        custom_context);
                size += mojo::internal::PrepareToSerialize<::cc::mojom::TileQuadStateDataView>(
                    in_tile_quad_state, context);
                break;
            }
            case ::cc::mojom::DrawQuadStateDataView::Tag::YUV_VIDEO_QUAD_STATE: {
                decltype(CallWithContext(Traits::yuv_video_quad_state, input, custom_context))
                    in_yuv_video_quad_state
                    = CallWithContext(Traits::yuv_video_quad_state, input,
                        custom_context);
                size += mojo::internal::PrepareToSerialize<::cc::mojom::YUVVideoQuadStateDataView>(
                    in_yuv_video_quad_state, context);
                break;
            }
            }
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::cc::mojom::internal::DrawQuadState_Data** output,
            bool inlined,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                if (inlined)
                    (*output)->set_null();
                else
                    *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            if (!inlined)
                *output = ::cc::mojom::internal::DrawQuadState_Data::New(buffer);

            ::cc::mojom::internal::DrawQuadState_Data* result = *output;
            ALLOW_UNUSED_LOCAL(result);
            // TODO(azani): Handle unknown and objects.
            // Set the not-null flag.
            result->size = kUnionDataSize;
            result->tag = CallWithContext(Traits::GetTag, input, custom_context);
            switch (result->tag) {
            case ::cc::mojom::DrawQuadStateDataView::Tag::DEBUG_BORDER_QUAD_STATE: {
                decltype(CallWithContext(Traits::debug_border_quad_state, input, custom_context))
                    in_debug_border_quad_state
                    = CallWithContext(Traits::debug_border_quad_state, input,
                        custom_context);
                typename decltype(result->data.f_debug_border_quad_state)::BaseType* ptr;
                mojo::internal::Serialize<::cc::mojom::DebugBorderQuadStateDataView>(
                    in_debug_border_quad_state, buffer, &ptr, context);
                result->data.f_debug_border_quad_state.Set(ptr);
                MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                    !ptr, mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                    "null debug_border_quad_state in DrawQuadState union");
                break;
            }
            case ::cc::mojom::DrawQuadStateDataView::Tag::RENDER_PASS_QUAD_STATE: {
                decltype(CallWithContext(Traits::render_pass_quad_state, input, custom_context))
                    in_render_pass_quad_state
                    = CallWithContext(Traits::render_pass_quad_state, input,
                        custom_context);
                typename decltype(result->data.f_render_pass_quad_state)::BaseType* ptr;
                mojo::internal::Serialize<::cc::mojom::RenderPassQuadStateDataView>(
                    in_render_pass_quad_state, buffer, &ptr, context);
                result->data.f_render_pass_quad_state.Set(ptr);
                MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                    !ptr, mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                    "null render_pass_quad_state in DrawQuadState union");
                break;
            }
            case ::cc::mojom::DrawQuadStateDataView::Tag::SOLID_COLOR_QUAD_STATE: {
                decltype(CallWithContext(Traits::solid_color_quad_state, input, custom_context))
                    in_solid_color_quad_state
                    = CallWithContext(Traits::solid_color_quad_state, input,
                        custom_context);
                typename decltype(result->data.f_solid_color_quad_state)::BaseType* ptr;
                mojo::internal::Serialize<::cc::mojom::SolidColorQuadStateDataView>(
                    in_solid_color_quad_state, buffer, &ptr, context);
                result->data.f_solid_color_quad_state.Set(ptr);
                MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                    !ptr, mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                    "null solid_color_quad_state in DrawQuadState union");
                break;
            }
            case ::cc::mojom::DrawQuadStateDataView::Tag::STREAM_VIDEO_QUAD_STATE: {
                decltype(CallWithContext(Traits::stream_video_quad_state, input, custom_context))
                    in_stream_video_quad_state
                    = CallWithContext(Traits::stream_video_quad_state, input,
                        custom_context);
                typename decltype(result->data.f_stream_video_quad_state)::BaseType* ptr;
                mojo::internal::Serialize<::cc::mojom::StreamVideoQuadStateDataView>(
                    in_stream_video_quad_state, buffer, &ptr, context);
                result->data.f_stream_video_quad_state.Set(ptr);
                MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                    !ptr, mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                    "null stream_video_quad_state in DrawQuadState union");
                break;
            }
            case ::cc::mojom::DrawQuadStateDataView::Tag::SURFACE_QUAD_STATE: {
                decltype(CallWithContext(Traits::surface_quad_state, input, custom_context))
                    in_surface_quad_state
                    = CallWithContext(Traits::surface_quad_state, input,
                        custom_context);
                typename decltype(result->data.f_surface_quad_state)::BaseType* ptr;
                mojo::internal::Serialize<::cc::mojom::SurfaceQuadStateDataView>(
                    in_surface_quad_state, buffer, &ptr, context);
                result->data.f_surface_quad_state.Set(ptr);
                MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                    !ptr, mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                    "null surface_quad_state in DrawQuadState union");
                break;
            }
            case ::cc::mojom::DrawQuadStateDataView::Tag::TEXTURE_QUAD_STATE: {
                decltype(CallWithContext(Traits::texture_quad_state, input, custom_context))
                    in_texture_quad_state
                    = CallWithContext(Traits::texture_quad_state, input,
                        custom_context);
                typename decltype(result->data.f_texture_quad_state)::BaseType* ptr;
                mojo::internal::Serialize<::cc::mojom::TextureQuadStateDataView>(
                    in_texture_quad_state, buffer, &ptr, context);
                result->data.f_texture_quad_state.Set(ptr);
                MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                    !ptr, mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                    "null texture_quad_state in DrawQuadState union");
                break;
            }
            case ::cc::mojom::DrawQuadStateDataView::Tag::TILE_QUAD_STATE: {
                decltype(CallWithContext(Traits::tile_quad_state, input, custom_context))
                    in_tile_quad_state
                    = CallWithContext(Traits::tile_quad_state, input,
                        custom_context);
                typename decltype(result->data.f_tile_quad_state)::BaseType* ptr;
                mojo::internal::Serialize<::cc::mojom::TileQuadStateDataView>(
                    in_tile_quad_state, buffer, &ptr, context);
                result->data.f_tile_quad_state.Set(ptr);
                MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                    !ptr, mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                    "null tile_quad_state in DrawQuadState union");
                break;
            }
            case ::cc::mojom::DrawQuadStateDataView::Tag::YUV_VIDEO_QUAD_STATE: {
                decltype(CallWithContext(Traits::yuv_video_quad_state, input, custom_context))
                    in_yuv_video_quad_state
                    = CallWithContext(Traits::yuv_video_quad_state, input,
                        custom_context);
                typename decltype(result->data.f_yuv_video_quad_state)::BaseType* ptr;
                mojo::internal::Serialize<::cc::mojom::YUVVideoQuadStateDataView>(
                    in_yuv_video_quad_state, buffer, &ptr, context);
                result->data.f_yuv_video_quad_state.Set(ptr);
                MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                    !ptr, mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                    "null yuv_video_quad_state in DrawQuadState union");
                break;
            }
            }

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::cc::mojom::internal::DrawQuadState_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input || input->is_null())
                return CallSetToNullIfExists<Traits>(output);

            ::cc::mojom::DrawQuadStateDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace cc {
namespace mojom {

    inline void RenderPassQuadStateDataView::GetMaskUvScaleDataView(
        ::gfx::mojom::Vector2dFDataView* output)
    {
        auto pointer = data_->mask_uv_scale.Get();
        *output = ::gfx::mojom::Vector2dFDataView(pointer, context_);
    }
    inline void RenderPassQuadStateDataView::GetMaskTextureSizeDataView(
        ::gfx::mojom::SizeDataView* output)
    {
        auto pointer = data_->mask_texture_size.Get();
        *output = ::gfx::mojom::SizeDataView(pointer, context_);
    }
    inline void RenderPassQuadStateDataView::GetFiltersScaleDataView(
        ::gfx::mojom::Vector2dFDataView* output)
    {
        auto pointer = data_->filters_scale.Get();
        *output = ::gfx::mojom::Vector2dFDataView(pointer, context_);
    }
    inline void RenderPassQuadStateDataView::GetFiltersOriginDataView(
        ::gfx::mojom::PointFDataView* output)
    {
        auto pointer = data_->filters_origin.Get();
        *output = ::gfx::mojom::PointFDataView(pointer, context_);
    }

    inline void StreamVideoQuadStateDataView::GetResourceSizeInPixelsDataView(
        ::gfx::mojom::SizeDataView* output)
    {
        auto pointer = data_->resource_size_in_pixels.Get();
        *output = ::gfx::mojom::SizeDataView(pointer, context_);
    }
    inline void StreamVideoQuadStateDataView::GetMatrixDataView(
        ::gfx::mojom::TransformDataView* output)
    {
        auto pointer = data_->matrix.Get();
        *output = ::gfx::mojom::TransformDataView(pointer, context_);
    }

    inline void SurfaceQuadStateDataView::GetSurfaceDataView(
        ::cc::mojom::SurfaceIdDataView* output)
    {
        auto pointer = data_->surface.Get();
        *output = ::cc::mojom::SurfaceIdDataView(pointer, context_);
    }

    inline void TextureQuadStateDataView::GetResourceSizeInPixelsDataView(
        ::gfx::mojom::SizeDataView* output)
    {
        auto pointer = data_->resource_size_in_pixels.Get();
        *output = ::gfx::mojom::SizeDataView(pointer, context_);
    }
    inline void TextureQuadStateDataView::GetUvTopLeftDataView(
        ::gfx::mojom::PointFDataView* output)
    {
        auto pointer = data_->uv_top_left.Get();
        *output = ::gfx::mojom::PointFDataView(pointer, context_);
    }
    inline void TextureQuadStateDataView::GetUvBottomRightDataView(
        ::gfx::mojom::PointFDataView* output)
    {
        auto pointer = data_->uv_bottom_right.Get();
        *output = ::gfx::mojom::PointFDataView(pointer, context_);
    }
    inline void TextureQuadStateDataView::GetVertexOpacityDataView(
        mojo::ArrayDataView<float>* output)
    {
        auto pointer = data_->vertex_opacity.Get();
        *output = mojo::ArrayDataView<float>(pointer, context_);
    }

    inline void TileQuadStateDataView::GetTexCoordRectDataView(
        ::gfx::mojom::RectFDataView* output)
    {
        auto pointer = data_->tex_coord_rect.Get();
        *output = ::gfx::mojom::RectFDataView(pointer, context_);
    }
    inline void TileQuadStateDataView::GetTextureSizeDataView(
        ::gfx::mojom::SizeDataView* output)
    {
        auto pointer = data_->texture_size.Get();
        *output = ::gfx::mojom::SizeDataView(pointer, context_);
    }

    inline void YUVVideoQuadStateDataView::GetYaTexCoordRectDataView(
        ::gfx::mojom::RectFDataView* output)
    {
        auto pointer = data_->ya_tex_coord_rect.Get();
        *output = ::gfx::mojom::RectFDataView(pointer, context_);
    }
    inline void YUVVideoQuadStateDataView::GetUvTexCoordRectDataView(
        ::gfx::mojom::RectFDataView* output)
    {
        auto pointer = data_->uv_tex_coord_rect.Get();
        *output = ::gfx::mojom::RectFDataView(pointer, context_);
    }
    inline void YUVVideoQuadStateDataView::GetYaTexSizeDataView(
        ::gfx::mojom::SizeDataView* output)
    {
        auto pointer = data_->ya_tex_size.Get();
        *output = ::gfx::mojom::SizeDataView(pointer, context_);
    }
    inline void YUVVideoQuadStateDataView::GetUvTexSizeDataView(
        ::gfx::mojom::SizeDataView* output)
    {
        auto pointer = data_->uv_tex_size.Get();
        *output = ::gfx::mojom::SizeDataView(pointer, context_);
    }

    inline void DrawQuadDataView::GetRectDataView(
        ::gfx::mojom::RectDataView* output)
    {
        auto pointer = data_->rect.Get();
        *output = ::gfx::mojom::RectDataView(pointer, context_);
    }
    inline void DrawQuadDataView::GetOpaqueRectDataView(
        ::gfx::mojom::RectDataView* output)
    {
        auto pointer = data_->opaque_rect.Get();
        *output = ::gfx::mojom::RectDataView(pointer, context_);
    }
    inline void DrawQuadDataView::GetVisibleRectDataView(
        ::gfx::mojom::RectDataView* output)
    {
        auto pointer = data_->visible_rect.Get();
        *output = ::gfx::mojom::RectDataView(pointer, context_);
    }
    inline void DrawQuadDataView::GetSqsDataView(
        ::cc::mojom::SharedQuadStateDataView* output)
    {
        auto pointer = data_->sqs.Get();
        *output = ::cc::mojom::SharedQuadStateDataView(pointer, context_);
    }
    inline void DrawQuadDataView::GetDrawQuadStateDataView(
        DrawQuadStateDataView* output)
    {
        auto pointer = &data_->draw_quad_state;
        *output = DrawQuadStateDataView(pointer, context_);
    }

    inline void DrawQuadStateDataView::GetDebugBorderQuadStateDataView(
        DebugBorderQuadStateDataView* output)
    {
        DCHECK(is_debug_border_quad_state());
        *output = DebugBorderQuadStateDataView(data_->data.f_debug_border_quad_state.Get(), context_);
    }
    inline void DrawQuadStateDataView::GetRenderPassQuadStateDataView(
        RenderPassQuadStateDataView* output)
    {
        DCHECK(is_render_pass_quad_state());
        *output = RenderPassQuadStateDataView(data_->data.f_render_pass_quad_state.Get(), context_);
    }
    inline void DrawQuadStateDataView::GetSolidColorQuadStateDataView(
        SolidColorQuadStateDataView* output)
    {
        DCHECK(is_solid_color_quad_state());
        *output = SolidColorQuadStateDataView(data_->data.f_solid_color_quad_state.Get(), context_);
    }
    inline void DrawQuadStateDataView::GetStreamVideoQuadStateDataView(
        StreamVideoQuadStateDataView* output)
    {
        DCHECK(is_stream_video_quad_state());
        *output = StreamVideoQuadStateDataView(data_->data.f_stream_video_quad_state.Get(), context_);
    }
    inline void DrawQuadStateDataView::GetSurfaceQuadStateDataView(
        SurfaceQuadStateDataView* output)
    {
        DCHECK(is_surface_quad_state());
        *output = SurfaceQuadStateDataView(data_->data.f_surface_quad_state.Get(), context_);
    }
    inline void DrawQuadStateDataView::GetTextureQuadStateDataView(
        TextureQuadStateDataView* output)
    {
        DCHECK(is_texture_quad_state());
        *output = TextureQuadStateDataView(data_->data.f_texture_quad_state.Get(), context_);
    }
    inline void DrawQuadStateDataView::GetTileQuadStateDataView(
        TileQuadStateDataView* output)
    {
        DCHECK(is_tile_quad_state());
        *output = TileQuadStateDataView(data_->data.f_tile_quad_state.Get(), context_);
    }
    inline void DrawQuadStateDataView::GetYuvVideoQuadStateDataView(
        YUVVideoQuadStateDataView* output)
    {
        DCHECK(is_yuv_video_quad_state());
        *output = YUVVideoQuadStateDataView(data_->data.f_yuv_video_quad_state.Get(), context_);
    }

} // namespace mojom
} // namespace cc

#endif // CC_IPC_QUADS_MOJOM_SHARED_H_
