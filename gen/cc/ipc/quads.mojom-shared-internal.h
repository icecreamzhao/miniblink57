// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_QUADS_MOJOM_SHARED_INTERNAL_H_
#define CC_IPC_QUADS_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "cc/ipc/filter_operations.mojom-shared-internal.h"
#include "cc/ipc/shared_quad_state.mojom-shared-internal.h"
#include "cc/ipc/surface_id.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared-internal.h"
#include "ui/gfx/mojo/transform.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace cc {
namespace mojom {
    namespace internal {
        class DebugBorderQuadState_Data;
        class RenderPassQuadState_Data;
        class SolidColorQuadState_Data;
        class StreamVideoQuadState_Data;
        class SurfaceQuadState_Data;
        class TextureQuadState_Data;
        class TileQuadState_Data;
        class YUVVideoQuadState_Data;
        class DrawQuad_Data;
        class DrawQuadState_Data;

        struct YUVColorSpace_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                case 2:
                    return true;
                }
                return false;
            }

            static bool Validate(int32_t value,
                mojo::internal::ValidationContext* validation_context)
            {
                if (kIsExtensible || IsKnownValue(value))
                    return true;

                ReportValidationError(validation_context,
                    mojo::internal::VALIDATION_ERROR_UNKNOWN_ENUM_VALUE);
                return false;
            }
        };

#pragma pack(push, 1)

        class DrawQuadState_Data {
        public:
            // Used to identify Mojom Union Data Classes.
            typedef void MojomUnionDataType;

            DrawQuadState_Data() { }
            // Do nothing in the destructor since it won't be called when it is a
            // non-inlined union.
            ~DrawQuadState_Data() { }

            static DrawQuadState_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DrawQuadState_Data))) DrawQuadState_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context,
                bool inlined);

            bool is_null() const { return size == 0; }

            void set_null()
            {
                size = 0U;
                tag = static_cast<DrawQuadState_Tag>(0);
                data.unknown = 0U;
            }

            enum class DrawQuadState_Tag : uint32_t {

                DEBUG_BORDER_QUAD_STATE,
                RENDER_PASS_QUAD_STATE,
                SOLID_COLOR_QUAD_STATE,
                STREAM_VIDEO_QUAD_STATE,
                SURFACE_QUAD_STATE,
                TEXTURE_QUAD_STATE,
                TILE_QUAD_STATE,
                YUV_VIDEO_QUAD_STATE,
            };

            // A note on layout:
            // "Each non-static data member is allocated as if it were the sole member of
            // a struct." - Section 9.5.2 ISO/IEC 14882:2011 (The C++ Spec)
            union MOJO_ALIGNAS(8) Union_ {
                mojo::internal::Pointer<internal::DebugBorderQuadState_Data> f_debug_border_quad_state;
                mojo::internal::Pointer<internal::RenderPassQuadState_Data> f_render_pass_quad_state;
                mojo::internal::Pointer<internal::SolidColorQuadState_Data> f_solid_color_quad_state;
                mojo::internal::Pointer<internal::StreamVideoQuadState_Data> f_stream_video_quad_state;
                mojo::internal::Pointer<internal::SurfaceQuadState_Data> f_surface_quad_state;
                mojo::internal::Pointer<internal::TextureQuadState_Data> f_texture_quad_state;
                mojo::internal::Pointer<internal::TileQuadState_Data> f_tile_quad_state;
                mojo::internal::Pointer<internal::YUVVideoQuadState_Data> f_yuv_video_quad_state;
                uint64_t unknown;
            };

            uint32_t size;
            DrawQuadState_Tag tag;
            Union_ data;
        };
        static_assert(sizeof(DrawQuadState_Data) == mojo::internal::kUnionDataSize,
            "Bad sizeof(DrawQuadState_Data)");
        class DebugBorderQuadState_Data {
        public:
            static DebugBorderQuadState_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DebugBorderQuadState_Data))) DebugBorderQuadState_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t color;
            int32_t width;

        private:
            DebugBorderQuadState_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DebugBorderQuadState_Data() = delete;
        };
        static_assert(sizeof(DebugBorderQuadState_Data) == 16,
            "Bad sizeof(DebugBorderQuadState_Data)");
        class RenderPassQuadState_Data {
        public:
            static RenderPassQuadState_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RenderPassQuadState_Data))) RenderPassQuadState_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t render_pass_id;
            uint32_t mask_resource_id;
            mojo::internal::Pointer<::gfx::mojom::internal::Vector2dF_Data> mask_uv_scale;
            mojo::internal::Pointer<::gfx::mojom::internal::Size_Data> mask_texture_size;
            mojo::internal::Pointer<::gfx::mojom::internal::Vector2dF_Data> filters_scale;
            mojo::internal::Pointer<::gfx::mojom::internal::PointF_Data> filters_origin;

        private:
            RenderPassQuadState_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RenderPassQuadState_Data() = delete;
        };
        static_assert(sizeof(RenderPassQuadState_Data) == 48,
            "Bad sizeof(RenderPassQuadState_Data)");
        class SolidColorQuadState_Data {
        public:
            static SolidColorQuadState_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(SolidColorQuadState_Data))) SolidColorQuadState_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t color;
            uint8_t force_anti_aliasing_off : 1;
            uint8_t padfinal_[3];

        private:
            SolidColorQuadState_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~SolidColorQuadState_Data() = delete;
        };
        static_assert(sizeof(SolidColorQuadState_Data) == 16,
            "Bad sizeof(SolidColorQuadState_Data)");
        class StreamVideoQuadState_Data {
        public:
            static StreamVideoQuadState_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(StreamVideoQuadState_Data))) StreamVideoQuadState_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t resource_id;
            uint8_t pad0_[4];
            mojo::internal::Pointer<::gfx::mojom::internal::Size_Data> resource_size_in_pixels;
            mojo::internal::Pointer<::gfx::mojom::internal::Transform_Data> matrix;

        private:
            StreamVideoQuadState_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~StreamVideoQuadState_Data() = delete;
        };
        static_assert(sizeof(StreamVideoQuadState_Data) == 32,
            "Bad sizeof(StreamVideoQuadState_Data)");
        class SurfaceQuadState_Data {
        public:
            static SurfaceQuadState_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(SurfaceQuadState_Data))) SurfaceQuadState_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::cc::mojom::internal::SurfaceId_Data> surface;

        private:
            SurfaceQuadState_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~SurfaceQuadState_Data() = delete;
        };
        static_assert(sizeof(SurfaceQuadState_Data) == 16,
            "Bad sizeof(SurfaceQuadState_Data)");
        class TextureQuadState_Data {
        public:
            static TextureQuadState_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(TextureQuadState_Data))) TextureQuadState_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t resource_id;
            uint8_t premultiplied_alpha : 1;
            uint8_t y_flipped : 1;
            uint8_t nearest_neighbor : 1;
            uint8_t secure_output_only : 1;
            uint8_t pad4_[3];
            mojo::internal::Pointer<::gfx::mojom::internal::Size_Data> resource_size_in_pixels;
            mojo::internal::Pointer<::gfx::mojom::internal::PointF_Data> uv_top_left;
            mojo::internal::Pointer<::gfx::mojom::internal::PointF_Data> uv_bottom_right;
            uint32_t background_color;
            uint8_t pad8_[4];
            mojo::internal::Pointer<mojo::internal::Array_Data<float>> vertex_opacity;

        private:
            TextureQuadState_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~TextureQuadState_Data() = delete;
        };
        static_assert(sizeof(TextureQuadState_Data) == 56,
            "Bad sizeof(TextureQuadState_Data)");
        class TileQuadState_Data {
        public:
            static TileQuadState_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(TileQuadState_Data))) TileQuadState_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::gfx::mojom::internal::RectF_Data> tex_coord_rect;
            mojo::internal::Pointer<::gfx::mojom::internal::Size_Data> texture_size;
            uint8_t swizzle_contents : 1;
            uint8_t nearest_neighbor : 1;
            uint8_t pad3_[3];
            uint32_t resource_id;

        private:
            TileQuadState_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~TileQuadState_Data() = delete;
        };
        static_assert(sizeof(TileQuadState_Data) == 32,
            "Bad sizeof(TileQuadState_Data)");
        class YUVVideoQuadState_Data {
        public:
            static YUVVideoQuadState_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(YUVVideoQuadState_Data))) YUVVideoQuadState_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::gfx::mojom::internal::RectF_Data> ya_tex_coord_rect;
            mojo::internal::Pointer<::gfx::mojom::internal::RectF_Data> uv_tex_coord_rect;
            mojo::internal::Pointer<::gfx::mojom::internal::Size_Data> ya_tex_size;
            mojo::internal::Pointer<::gfx::mojom::internal::Size_Data> uv_tex_size;
            uint32_t y_plane_resource_id;
            uint32_t u_plane_resource_id;
            uint32_t v_plane_resource_id;
            uint32_t a_plane_resource_id;
            int32_t color_space;
            float resource_offset;
            float resource_multiplier;
            uint32_t bits_per_channel;

        private:
            YUVVideoQuadState_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~YUVVideoQuadState_Data() = delete;
        };
        static_assert(sizeof(YUVVideoQuadState_Data) == 72,
            "Bad sizeof(YUVVideoQuadState_Data)");
        class DrawQuad_Data {
        public:
            static DrawQuad_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DrawQuad_Data))) DrawQuad_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::gfx::mojom::internal::Rect_Data> rect;
            mojo::internal::Pointer<::gfx::mojom::internal::Rect_Data> opaque_rect;
            mojo::internal::Pointer<::gfx::mojom::internal::Rect_Data> visible_rect;
            uint8_t needs_blending : 1;
            uint8_t pad3_[7];
            mojo::internal::Pointer<::cc::mojom::internal::SharedQuadState_Data> sqs;
            internal::DrawQuadState_Data draw_quad_state;

        private:
            DrawQuad_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DrawQuad_Data() = delete;
        };
        static_assert(sizeof(DrawQuad_Data) == 64,
            "Bad sizeof(DrawQuad_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace cc

#endif // CC_IPC_QUADS_MOJOM_SHARED_INTERNAL_H_