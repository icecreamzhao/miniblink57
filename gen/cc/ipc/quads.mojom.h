// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_QUADS_MOJOM_H_
#define CC_IPC_QUADS_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/files/file.h"
#include "base/files/file_path.h"
#include "base/i18n/rtl.h"
#include "base/optional.h"
#include "base/strings/string16.h"
#include "base/time/time.h"
#include "base/unguessable_token.h"
#include "base/values.h"
#include "base/version.h"
#include "cc/input/selection.h"
#include "cc/ipc/filter_operations.mojom.h"
#include "cc/ipc/quads.mojom-shared.h"
#include "cc/ipc/shared_quad_state.mojom.h"
#include "cc/ipc/surface_id.mojom.h"
#include "cc/output/begin_frame_args.h"
#include "cc/output/compositor_frame.h"
#include "cc/output/compositor_frame_metadata.h"
#include "cc/output/filter_operation.h"
#include "cc/output/filter_operations.h"
#include "cc/quads/draw_quad.h"
#include "cc/quads/render_pass.h"
#include "cc/quads/shared_quad_state.h"
#include "cc/resources/returned_resource.h"
#include "cc/resources/transferable_resource.h"
#include "cc/surfaces/frame_sink_id.h"
#include "cc/surfaces/local_frame_id.h"
#include "cc/surfaces/surface_id.h"
#include "cc/surfaces/surface_info.h"
#include "cc/surfaces/surface_reference.h"
#include "cc/surfaces/surface_sequence.h"
#include "gpu/command_buffer/common/capabilities.h"
#include "gpu/command_buffer/common/mailbox.h"
#include "gpu/command_buffer/common/mailbox_holder.h"
#include "gpu/command_buffer/common/sync_token.h"
#include "gpu/command_buffer/service/gpu_preferences.h"
#include "gpu/config/dx_diag_node.h"
#include "gpu/config/gpu_info.h"
#include "gpu/ipc/common/surface_handle.h"
#include "mojo/public/cpp/bindings/associated_interface_ptr.h"
#include "mojo/public/cpp/bindings/associated_interface_ptr_info.h"
#include "mojo/public/cpp/bindings/associated_interface_request.h"
#include "mojo/public/cpp/bindings/interface_ptr.h"
#include "mojo/public/cpp/bindings/interface_request.h"
#include "mojo/public/cpp/bindings/lib/clone_equals_util.h"
#include "mojo/public/cpp/bindings/lib/control_message_handler.h"
#include "mojo/public/cpp/bindings/lib/control_message_proxy.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/lib/union_accessor.h"
#include "mojo/public/cpp/bindings/native_struct.h"
#include "mojo/public/cpp/bindings/no_interface.h"
#include "mojo/public/cpp/bindings/raw_ptr_impl_ref_traits.h"
#include "mojo/public/cpp/bindings/struct_ptr.h"
#include "mojo/public/cpp/bindings/struct_traits.h"
#include "mojo/public/cpp/bindings/thread_safe_interface_ptr.h"
#include "mojo/public/cpp/bindings/union_traits.h"
#include "third_party/skia/include/core/SkBitmap.h"
#include "third_party/skia/include/core/SkImageFilter.h"
#include "ui/events/event.h"
#include "ui/events/latency_info.h"
#include "ui/gfx/buffer_types.h"
#include "ui/gfx/color_space.h"
#include "ui/gfx/geometry/insets.h"
#include "ui/gfx/geometry/mojo/geometry.mojom.h"
#include "ui/gfx/geometry/point.h"
#include "ui/gfx/geometry/point_f.h"
#include "ui/gfx/geometry/rect.h"
#include "ui/gfx/geometry/rect_f.h"
#include "ui/gfx/geometry/safe_integer_conversions.h"
#include "ui/gfx/geometry/size.h"
#include "ui/gfx/geometry/vector2d.h"
#include "ui/gfx/geometry/vector2d_f.h"
#include "ui/gfx/gpu_memory_buffer.h"
#include "ui/gfx/icc_profile.h"
#include "ui/gfx/mojo/transform.mojom.h"
#include "ui/gfx/native_pixmap_handle.h"
#include "ui/gfx/native_widget_types.h"
#include "ui/gfx/selection_bound.h"
#include "ui/gfx/transform.h"
#include <string>
#include <vector>

namespace cc {
namespace mojom {
    class DebugBorderQuadState;
    using DebugBorderQuadStatePtr = mojo::InlinedStructPtr<DebugBorderQuadState>;

    class RenderPassQuadState;
    using RenderPassQuadStatePtr = mojo::StructPtr<RenderPassQuadState>;

    class SolidColorQuadState;
    using SolidColorQuadStatePtr = mojo::InlinedStructPtr<SolidColorQuadState>;

    class StreamVideoQuadState;
    using StreamVideoQuadStatePtr = mojo::StructPtr<StreamVideoQuadState>;

    class SurfaceQuadState;
    using SurfaceQuadStatePtr = mojo::StructPtr<SurfaceQuadState>;

    class TextureQuadState;
    using TextureQuadStatePtr = mojo::StructPtr<TextureQuadState>;

    class TileQuadState;
    using TileQuadStatePtr = mojo::StructPtr<TileQuadState>;

    class YUVVideoQuadState;
    using YUVVideoQuadStatePtr = mojo::StructPtr<YUVVideoQuadState>;

    class DrawQuad;
    using DrawQuadPtr = mojo::StructPtr<DrawQuad>;

    class DrawQuadState;

    typedef mojo::StructPtr<DrawQuadState> DrawQuadStatePtr;

    class DebugBorderQuadState {
    public:
        using DataView = DebugBorderQuadStateDataView;
        using Data_ = internal::DebugBorderQuadState_Data;

        static DebugBorderQuadStatePtr New();

        template <typename U>
        static DebugBorderQuadStatePtr From(const U& u)
        {
            return mojo::TypeConverter<DebugBorderQuadStatePtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, DebugBorderQuadState>::Convert(*this);
        }

        DebugBorderQuadState();
        ~DebugBorderQuadState();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = DebugBorderQuadStatePtr>
        DebugBorderQuadStatePtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, DebugBorderQuadState>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                DebugBorderQuadState::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                DebugBorderQuadState::DataView, std::vector<uint8_t>>(
                input, output);
        }

        uint32_t color;
        int32_t width;
    };

    class SolidColorQuadState {
    public:
        using DataView = SolidColorQuadStateDataView;
        using Data_ = internal::SolidColorQuadState_Data;

        static SolidColorQuadStatePtr New();

        template <typename U>
        static SolidColorQuadStatePtr From(const U& u)
        {
            return mojo::TypeConverter<SolidColorQuadStatePtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, SolidColorQuadState>::Convert(*this);
        }

        SolidColorQuadState();
        ~SolidColorQuadState();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = SolidColorQuadStatePtr>
        SolidColorQuadStatePtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, SolidColorQuadState>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                SolidColorQuadState::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                SolidColorQuadState::DataView, std::vector<uint8_t>>(
                input, output);
        }

        uint32_t color;
        bool force_anti_aliasing_off;
    };

    class DrawQuadState {
    public:
        using DataView = DrawQuadStateDataView;
        using Data_ = internal::DrawQuadState_Data;
        using Tag = Data_::DrawQuadState_Tag;

        static DrawQuadStatePtr New();

        template <typename U>
        static DrawQuadStatePtr From(const U& u)
        {
            return mojo::TypeConverter<DrawQuadStatePtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, DrawQuadState>::Convert(*this);
        }

        DrawQuadState();
        ~DrawQuadState();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename UnionPtrType = DrawQuadStatePtr>
        DrawQuadStatePtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, DrawQuadState>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        Tag which() const
        {
            return tag_;
        }

        bool is_debug_border_quad_state() const { return tag_ == Tag::DEBUG_BORDER_QUAD_STATE; }

        DebugBorderQuadStatePtr& get_debug_border_quad_state() const
        {
            DCHECK(tag_ == Tag::DEBUG_BORDER_QUAD_STATE);
            return *(data_.debug_border_quad_state);
        }

        void set_debug_border_quad_state(DebugBorderQuadStatePtr debug_border_quad_state);
        bool is_render_pass_quad_state() const { return tag_ == Tag::RENDER_PASS_QUAD_STATE; }

        RenderPassQuadStatePtr& get_render_pass_quad_state() const
        {
            DCHECK(tag_ == Tag::RENDER_PASS_QUAD_STATE);
            return *(data_.render_pass_quad_state);
        }

        void set_render_pass_quad_state(RenderPassQuadStatePtr render_pass_quad_state);
        bool is_solid_color_quad_state() const { return tag_ == Tag::SOLID_COLOR_QUAD_STATE; }

        SolidColorQuadStatePtr& get_solid_color_quad_state() const
        {
            DCHECK(tag_ == Tag::SOLID_COLOR_QUAD_STATE);
            return *(data_.solid_color_quad_state);
        }

        void set_solid_color_quad_state(SolidColorQuadStatePtr solid_color_quad_state);
        bool is_stream_video_quad_state() const { return tag_ == Tag::STREAM_VIDEO_QUAD_STATE; }

        StreamVideoQuadStatePtr& get_stream_video_quad_state() const
        {
            DCHECK(tag_ == Tag::STREAM_VIDEO_QUAD_STATE);
            return *(data_.stream_video_quad_state);
        }

        void set_stream_video_quad_state(StreamVideoQuadStatePtr stream_video_quad_state);
        bool is_surface_quad_state() const { return tag_ == Tag::SURFACE_QUAD_STATE; }

        SurfaceQuadStatePtr& get_surface_quad_state() const
        {
            DCHECK(tag_ == Tag::SURFACE_QUAD_STATE);
            return *(data_.surface_quad_state);
        }

        void set_surface_quad_state(SurfaceQuadStatePtr surface_quad_state);
        bool is_texture_quad_state() const { return tag_ == Tag::TEXTURE_QUAD_STATE; }

        TextureQuadStatePtr& get_texture_quad_state() const
        {
            DCHECK(tag_ == Tag::TEXTURE_QUAD_STATE);
            return *(data_.texture_quad_state);
        }

        void set_texture_quad_state(TextureQuadStatePtr texture_quad_state);
        bool is_tile_quad_state() const { return tag_ == Tag::TILE_QUAD_STATE; }

        TileQuadStatePtr& get_tile_quad_state() const
        {
            DCHECK(tag_ == Tag::TILE_QUAD_STATE);
            return *(data_.tile_quad_state);
        }

        void set_tile_quad_state(TileQuadStatePtr tile_quad_state);
        bool is_yuv_video_quad_state() const { return tag_ == Tag::YUV_VIDEO_QUAD_STATE; }

        YUVVideoQuadStatePtr& get_yuv_video_quad_state() const
        {
            DCHECK(tag_ == Tag::YUV_VIDEO_QUAD_STATE);
            return *(data_.yuv_video_quad_state);
        }

        void set_yuv_video_quad_state(YUVVideoQuadStatePtr yuv_video_quad_state);

    private:
        friend class mojo::internal::UnionAccessor<DrawQuadState>;
        union Union_ {
            Union_() { }
            ~Union_() { }
            DebugBorderQuadStatePtr* debug_border_quad_state;
            RenderPassQuadStatePtr* render_pass_quad_state;
            SolidColorQuadStatePtr* solid_color_quad_state;
            StreamVideoQuadStatePtr* stream_video_quad_state;
            SurfaceQuadStatePtr* surface_quad_state;
            TextureQuadStatePtr* texture_quad_state;
            TileQuadStatePtr* tile_quad_state;
            YUVVideoQuadStatePtr* yuv_video_quad_state;
        };
        void SwitchActive(Tag new_active);
        void SetActive(Tag new_active);
        void DestroyActive();
        Tag tag_;
        Union_ data_;
    };

    class RenderPassQuadState {
    public:
        using DataView = RenderPassQuadStateDataView;
        using Data_ = internal::RenderPassQuadState_Data;

        static RenderPassQuadStatePtr New();

        template <typename U>
        static RenderPassQuadStatePtr From(const U& u)
        {
            return mojo::TypeConverter<RenderPassQuadStatePtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, RenderPassQuadState>::Convert(*this);
        }

        RenderPassQuadState();
        ~RenderPassQuadState();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = RenderPassQuadStatePtr>
        RenderPassQuadStatePtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, RenderPassQuadState>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                RenderPassQuadState::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                RenderPassQuadState::DataView, std::vector<uint8_t>>(
                input, output);
        }

        int32_t render_pass_id;
        uint32_t mask_resource_id;
        gfx::Vector2dF mask_uv_scale;
        gfx::Size mask_texture_size;
        gfx::Vector2dF filters_scale;
        gfx::PointF filters_origin;
    };

    class StreamVideoQuadState {
    public:
        using DataView = StreamVideoQuadStateDataView;
        using Data_ = internal::StreamVideoQuadState_Data;

        static StreamVideoQuadStatePtr New();

        template <typename U>
        static StreamVideoQuadStatePtr From(const U& u)
        {
            return mojo::TypeConverter<StreamVideoQuadStatePtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, StreamVideoQuadState>::Convert(*this);
        }

        StreamVideoQuadState();
        ~StreamVideoQuadState();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = StreamVideoQuadStatePtr>
        StreamVideoQuadStatePtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, StreamVideoQuadState>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                StreamVideoQuadState::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                StreamVideoQuadState::DataView, std::vector<uint8_t>>(
                input, output);
        }

        uint32_t resource_id;
        gfx::Size resource_size_in_pixels;
        gfx::Transform matrix;
    };

    class SurfaceQuadState {
    public:
        using DataView = SurfaceQuadStateDataView;
        using Data_ = internal::SurfaceQuadState_Data;

        static SurfaceQuadStatePtr New();

        template <typename U>
        static SurfaceQuadStatePtr From(const U& u)
        {
            return mojo::TypeConverter<SurfaceQuadStatePtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, SurfaceQuadState>::Convert(*this);
        }

        SurfaceQuadState();
        ~SurfaceQuadState();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = SurfaceQuadStatePtr>
        SurfaceQuadStatePtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, SurfaceQuadState>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                SurfaceQuadState::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                SurfaceQuadState::DataView, std::vector<uint8_t>>(
                input, output);
        }

        cc::SurfaceId surface;
    };

    class TextureQuadState {
    public:
        using DataView = TextureQuadStateDataView;
        using Data_ = internal::TextureQuadState_Data;

        static TextureQuadStatePtr New();

        template <typename U>
        static TextureQuadStatePtr From(const U& u)
        {
            return mojo::TypeConverter<TextureQuadStatePtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, TextureQuadState>::Convert(*this);
        }

        TextureQuadState();
        ~TextureQuadState();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = TextureQuadStatePtr>
        TextureQuadStatePtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, TextureQuadState>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                TextureQuadState::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                TextureQuadState::DataView, std::vector<uint8_t>>(
                input, output);
        }

        uint32_t resource_id;
        gfx::Size resource_size_in_pixels;
        bool premultiplied_alpha;
        gfx::PointF uv_top_left;
        gfx::PointF uv_bottom_right;
        uint32_t background_color;
        std::vector<float> vertex_opacity;
        bool y_flipped;
        bool nearest_neighbor;
        bool secure_output_only;
    };

    class TileQuadState {
    public:
        using DataView = TileQuadStateDataView;
        using Data_ = internal::TileQuadState_Data;

        static TileQuadStatePtr New();

        template <typename U>
        static TileQuadStatePtr From(const U& u)
        {
            return mojo::TypeConverter<TileQuadStatePtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, TileQuadState>::Convert(*this);
        }

        TileQuadState();
        ~TileQuadState();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = TileQuadStatePtr>
        TileQuadStatePtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, TileQuadState>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                TileQuadState::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                TileQuadState::DataView, std::vector<uint8_t>>(
                input, output);
        }

        gfx::RectF tex_coord_rect;
        gfx::Size texture_size;
        bool swizzle_contents;
        uint32_t resource_id;
        bool nearest_neighbor;
    };

    class YUVVideoQuadState {
    public:
        using DataView = YUVVideoQuadStateDataView;
        using Data_ = internal::YUVVideoQuadState_Data;

        static YUVVideoQuadStatePtr New();

        template <typename U>
        static YUVVideoQuadStatePtr From(const U& u)
        {
            return mojo::TypeConverter<YUVVideoQuadStatePtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, YUVVideoQuadState>::Convert(*this);
        }

        YUVVideoQuadState();
        ~YUVVideoQuadState();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = YUVVideoQuadStatePtr>
        YUVVideoQuadStatePtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, YUVVideoQuadState>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                YUVVideoQuadState::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                YUVVideoQuadState::DataView, std::vector<uint8_t>>(
                input, output);
        }

        gfx::RectF ya_tex_coord_rect;
        gfx::RectF uv_tex_coord_rect;
        gfx::Size ya_tex_size;
        gfx::Size uv_tex_size;
        uint32_t y_plane_resource_id;
        uint32_t u_plane_resource_id;
        uint32_t v_plane_resource_id;
        uint32_t a_plane_resource_id;
        YUVColorSpace color_space;
        float resource_offset;
        float resource_multiplier;
        uint32_t bits_per_channel;
    };

    class DrawQuad {
    public:
        using DataView = DrawQuadDataView;
        using Data_ = internal::DrawQuad_Data;

        static DrawQuadPtr New();

        template <typename U>
        static DrawQuadPtr From(const U& u)
        {
            return mojo::TypeConverter<DrawQuadPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, DrawQuad>::Convert(*this);
        }

        DrawQuad();
        ~DrawQuad();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = DrawQuadPtr>
        DrawQuadPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, DrawQuad>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                DrawQuad::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                DrawQuad::DataView, std::vector<uint8_t>>(
                input, output);
        }

        gfx::Rect rect;
        gfx::Rect opaque_rect;
        gfx::Rect visible_rect;
        bool needs_blending;
        base::Optional<cc::SharedQuadState> sqs;
        DrawQuadStatePtr draw_quad_state;

    private:
        DISALLOW_COPY_AND_ASSIGN(DrawQuad);
    };

    template <typename UnionPtrType>
    DrawQuadStatePtr DrawQuadState::Clone() const
    {
        // Use UnionPtrType to prevent the compiler from trying to compile this
        // without being asked.
        UnionPtrType rv(New());
        switch (tag_) {
        case Tag::DEBUG_BORDER_QUAD_STATE:
            rv->set_debug_border_quad_state(mojo::internal::Clone(*data_.debug_border_quad_state));
            break;
        case Tag::RENDER_PASS_QUAD_STATE:
            rv->set_render_pass_quad_state(mojo::internal::Clone(*data_.render_pass_quad_state));
            break;
        case Tag::SOLID_COLOR_QUAD_STATE:
            rv->set_solid_color_quad_state(mojo::internal::Clone(*data_.solid_color_quad_state));
            break;
        case Tag::STREAM_VIDEO_QUAD_STATE:
            rv->set_stream_video_quad_state(mojo::internal::Clone(*data_.stream_video_quad_state));
            break;
        case Tag::SURFACE_QUAD_STATE:
            rv->set_surface_quad_state(mojo::internal::Clone(*data_.surface_quad_state));
            break;
        case Tag::TEXTURE_QUAD_STATE:
            rv->set_texture_quad_state(mojo::internal::Clone(*data_.texture_quad_state));
            break;
        case Tag::TILE_QUAD_STATE:
            rv->set_tile_quad_state(mojo::internal::Clone(*data_.tile_quad_state));
            break;
        case Tag::YUV_VIDEO_QUAD_STATE:
            rv->set_yuv_video_quad_state(mojo::internal::Clone(*data_.yuv_video_quad_state));
            break;
        };
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, DrawQuadState>::value>::type*>
    bool DrawQuadState::Equals(const T& other) const
    {
        if (tag_ != other.which())
            return false;

        switch (tag_) {
        case Tag::DEBUG_BORDER_QUAD_STATE:
            return mojo::internal::Equals(*(data_.debug_border_quad_state), *(other.data_.debug_border_quad_state));
        case Tag::RENDER_PASS_QUAD_STATE:
            return mojo::internal::Equals(*(data_.render_pass_quad_state), *(other.data_.render_pass_quad_state));
        case Tag::SOLID_COLOR_QUAD_STATE:
            return mojo::internal::Equals(*(data_.solid_color_quad_state), *(other.data_.solid_color_quad_state));
        case Tag::STREAM_VIDEO_QUAD_STATE:
            return mojo::internal::Equals(*(data_.stream_video_quad_state), *(other.data_.stream_video_quad_state));
        case Tag::SURFACE_QUAD_STATE:
            return mojo::internal::Equals(*(data_.surface_quad_state), *(other.data_.surface_quad_state));
        case Tag::TEXTURE_QUAD_STATE:
            return mojo::internal::Equals(*(data_.texture_quad_state), *(other.data_.texture_quad_state));
        case Tag::TILE_QUAD_STATE:
            return mojo::internal::Equals(*(data_.tile_quad_state), *(other.data_.tile_quad_state));
        case Tag::YUV_VIDEO_QUAD_STATE:
            return mojo::internal::Equals(*(data_.yuv_video_quad_state), *(other.data_.yuv_video_quad_state));
        };

        return false;
    }
    template <typename StructPtrType>
    DebugBorderQuadStatePtr DebugBorderQuadState::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->color = mojo::internal::Clone(color);
        rv->width = mojo::internal::Clone(width);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, DebugBorderQuadState>::value>::type*>
    bool DebugBorderQuadState::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->color, other.color))
            return false;
        if (!mojo::internal::Equals(this->width, other.width))
            return false;
        return true;
    }
    template <typename StructPtrType>
    RenderPassQuadStatePtr RenderPassQuadState::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->render_pass_id = mojo::internal::Clone(render_pass_id);
        rv->mask_resource_id = mojo::internal::Clone(mask_resource_id);
        rv->mask_uv_scale = mojo::internal::Clone(mask_uv_scale);
        rv->mask_texture_size = mojo::internal::Clone(mask_texture_size);
        rv->filters_scale = mojo::internal::Clone(filters_scale);
        rv->filters_origin = mojo::internal::Clone(filters_origin);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, RenderPassQuadState>::value>::type*>
    bool RenderPassQuadState::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->render_pass_id, other.render_pass_id))
            return false;
        if (!mojo::internal::Equals(this->mask_resource_id, other.mask_resource_id))
            return false;
        if (!mojo::internal::Equals(this->mask_uv_scale, other.mask_uv_scale))
            return false;
        if (!mojo::internal::Equals(this->mask_texture_size, other.mask_texture_size))
            return false;
        if (!mojo::internal::Equals(this->filters_scale, other.filters_scale))
            return false;
        if (!mojo::internal::Equals(this->filters_origin, other.filters_origin))
            return false;
        return true;
    }
    template <typename StructPtrType>
    SolidColorQuadStatePtr SolidColorQuadState::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->color = mojo::internal::Clone(color);
        rv->force_anti_aliasing_off = mojo::internal::Clone(force_anti_aliasing_off);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, SolidColorQuadState>::value>::type*>
    bool SolidColorQuadState::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->color, other.color))
            return false;
        if (!mojo::internal::Equals(this->force_anti_aliasing_off, other.force_anti_aliasing_off))
            return false;
        return true;
    }
    template <typename StructPtrType>
    StreamVideoQuadStatePtr StreamVideoQuadState::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->resource_id = mojo::internal::Clone(resource_id);
        rv->resource_size_in_pixels = mojo::internal::Clone(resource_size_in_pixels);
        rv->matrix = mojo::internal::Clone(matrix);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, StreamVideoQuadState>::value>::type*>
    bool StreamVideoQuadState::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->resource_id, other.resource_id))
            return false;
        if (!mojo::internal::Equals(this->resource_size_in_pixels, other.resource_size_in_pixels))
            return false;
        if (!mojo::internal::Equals(this->matrix, other.matrix))
            return false;
        return true;
    }
    template <typename StructPtrType>
    SurfaceQuadStatePtr SurfaceQuadState::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->surface = mojo::internal::Clone(surface);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, SurfaceQuadState>::value>::type*>
    bool SurfaceQuadState::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->surface, other.surface))
            return false;
        return true;
    }
    template <typename StructPtrType>
    TextureQuadStatePtr TextureQuadState::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->resource_id = mojo::internal::Clone(resource_id);
        rv->resource_size_in_pixels = mojo::internal::Clone(resource_size_in_pixels);
        rv->premultiplied_alpha = mojo::internal::Clone(premultiplied_alpha);
        rv->uv_top_left = mojo::internal::Clone(uv_top_left);
        rv->uv_bottom_right = mojo::internal::Clone(uv_bottom_right);
        rv->background_color = mojo::internal::Clone(background_color);
        rv->vertex_opacity = mojo::internal::Clone(vertex_opacity);
        rv->y_flipped = mojo::internal::Clone(y_flipped);
        rv->nearest_neighbor = mojo::internal::Clone(nearest_neighbor);
        rv->secure_output_only = mojo::internal::Clone(secure_output_only);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, TextureQuadState>::value>::type*>
    bool TextureQuadState::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->resource_id, other.resource_id))
            return false;
        if (!mojo::internal::Equals(this->resource_size_in_pixels, other.resource_size_in_pixels))
            return false;
        if (!mojo::internal::Equals(this->premultiplied_alpha, other.premultiplied_alpha))
            return false;
        if (!mojo::internal::Equals(this->uv_top_left, other.uv_top_left))
            return false;
        if (!mojo::internal::Equals(this->uv_bottom_right, other.uv_bottom_right))
            return false;
        if (!mojo::internal::Equals(this->background_color, other.background_color))
            return false;
        if (!mojo::internal::Equals(this->vertex_opacity, other.vertex_opacity))
            return false;
        if (!mojo::internal::Equals(this->y_flipped, other.y_flipped))
            return false;
        if (!mojo::internal::Equals(this->nearest_neighbor, other.nearest_neighbor))
            return false;
        if (!mojo::internal::Equals(this->secure_output_only, other.secure_output_only))
            return false;
        return true;
    }
    template <typename StructPtrType>
    TileQuadStatePtr TileQuadState::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->tex_coord_rect = mojo::internal::Clone(tex_coord_rect);
        rv->texture_size = mojo::internal::Clone(texture_size);
        rv->swizzle_contents = mojo::internal::Clone(swizzle_contents);
        rv->resource_id = mojo::internal::Clone(resource_id);
        rv->nearest_neighbor = mojo::internal::Clone(nearest_neighbor);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, TileQuadState>::value>::type*>
    bool TileQuadState::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->tex_coord_rect, other.tex_coord_rect))
            return false;
        if (!mojo::internal::Equals(this->texture_size, other.texture_size))
            return false;
        if (!mojo::internal::Equals(this->swizzle_contents, other.swizzle_contents))
            return false;
        if (!mojo::internal::Equals(this->resource_id, other.resource_id))
            return false;
        if (!mojo::internal::Equals(this->nearest_neighbor, other.nearest_neighbor))
            return false;
        return true;
    }
    template <typename StructPtrType>
    YUVVideoQuadStatePtr YUVVideoQuadState::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->ya_tex_coord_rect = mojo::internal::Clone(ya_tex_coord_rect);
        rv->uv_tex_coord_rect = mojo::internal::Clone(uv_tex_coord_rect);
        rv->ya_tex_size = mojo::internal::Clone(ya_tex_size);
        rv->uv_tex_size = mojo::internal::Clone(uv_tex_size);
        rv->y_plane_resource_id = mojo::internal::Clone(y_plane_resource_id);
        rv->u_plane_resource_id = mojo::internal::Clone(u_plane_resource_id);
        rv->v_plane_resource_id = mojo::internal::Clone(v_plane_resource_id);
        rv->a_plane_resource_id = mojo::internal::Clone(a_plane_resource_id);
        rv->color_space = mojo::internal::Clone(color_space);
        rv->resource_offset = mojo::internal::Clone(resource_offset);
        rv->resource_multiplier = mojo::internal::Clone(resource_multiplier);
        rv->bits_per_channel = mojo::internal::Clone(bits_per_channel);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, YUVVideoQuadState>::value>::type*>
    bool YUVVideoQuadState::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->ya_tex_coord_rect, other.ya_tex_coord_rect))
            return false;
        if (!mojo::internal::Equals(this->uv_tex_coord_rect, other.uv_tex_coord_rect))
            return false;
        if (!mojo::internal::Equals(this->ya_tex_size, other.ya_tex_size))
            return false;
        if (!mojo::internal::Equals(this->uv_tex_size, other.uv_tex_size))
            return false;
        if (!mojo::internal::Equals(this->y_plane_resource_id, other.y_plane_resource_id))
            return false;
        if (!mojo::internal::Equals(this->u_plane_resource_id, other.u_plane_resource_id))
            return false;
        if (!mojo::internal::Equals(this->v_plane_resource_id, other.v_plane_resource_id))
            return false;
        if (!mojo::internal::Equals(this->a_plane_resource_id, other.a_plane_resource_id))
            return false;
        if (!mojo::internal::Equals(this->color_space, other.color_space))
            return false;
        if (!mojo::internal::Equals(this->resource_offset, other.resource_offset))
            return false;
        if (!mojo::internal::Equals(this->resource_multiplier, other.resource_multiplier))
            return false;
        if (!mojo::internal::Equals(this->bits_per_channel, other.bits_per_channel))
            return false;
        return true;
    }
    template <typename StructPtrType>
    DrawQuadPtr DrawQuad::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->rect = mojo::internal::Clone(rect);
        rv->opaque_rect = mojo::internal::Clone(opaque_rect);
        rv->visible_rect = mojo::internal::Clone(visible_rect);
        rv->needs_blending = mojo::internal::Clone(needs_blending);
        rv->sqs = mojo::internal::Clone(sqs);
        rv->draw_quad_state = mojo::internal::Clone(draw_quad_state);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, DrawQuad>::value>::type*>
    bool DrawQuad::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->rect, other.rect))
            return false;
        if (!mojo::internal::Equals(this->opaque_rect, other.opaque_rect))
            return false;
        if (!mojo::internal::Equals(this->visible_rect, other.visible_rect))
            return false;
        if (!mojo::internal::Equals(this->needs_blending, other.needs_blending))
            return false;
        if (!mojo::internal::Equals(this->sqs, other.sqs))
            return false;
        if (!mojo::internal::Equals(this->draw_quad_state, other.draw_quad_state))
            return false;
        return true;
    }

} // namespace mojom
} // namespace cc

namespace mojo {

template <>
struct StructTraits<::cc::mojom::DebugBorderQuadState::DataView,
    ::cc::mojom::DebugBorderQuadStatePtr> {
    static bool IsNull(const ::cc::mojom::DebugBorderQuadStatePtr& input) { return !input; }
    static void SetToNull(::cc::mojom::DebugBorderQuadStatePtr* output) { output->reset(); }

    static decltype(::cc::mojom::DebugBorderQuadState::color) color(
        const ::cc::mojom::DebugBorderQuadStatePtr& input)
    {
        return input->color;
    }

    static decltype(::cc::mojom::DebugBorderQuadState::width) width(
        const ::cc::mojom::DebugBorderQuadStatePtr& input)
    {
        return input->width;
    }

    static bool Read(::cc::mojom::DebugBorderQuadState::DataView input, ::cc::mojom::DebugBorderQuadStatePtr* output);
};

template <>
struct StructTraits<::cc::mojom::RenderPassQuadState::DataView,
    ::cc::mojom::RenderPassQuadStatePtr> {
    static bool IsNull(const ::cc::mojom::RenderPassQuadStatePtr& input) { return !input; }
    static void SetToNull(::cc::mojom::RenderPassQuadStatePtr* output) { output->reset(); }

    static decltype(::cc::mojom::RenderPassQuadState::render_pass_id) render_pass_id(
        const ::cc::mojom::RenderPassQuadStatePtr& input)
    {
        return input->render_pass_id;
    }

    static decltype(::cc::mojom::RenderPassQuadState::mask_resource_id) mask_resource_id(
        const ::cc::mojom::RenderPassQuadStatePtr& input)
    {
        return input->mask_resource_id;
    }

    static const decltype(::cc::mojom::RenderPassQuadState::mask_uv_scale)& mask_uv_scale(
        const ::cc::mojom::RenderPassQuadStatePtr& input)
    {
        return input->mask_uv_scale;
    }

    static const decltype(::cc::mojom::RenderPassQuadState::mask_texture_size)& mask_texture_size(
        const ::cc::mojom::RenderPassQuadStatePtr& input)
    {
        return input->mask_texture_size;
    }

    static const decltype(::cc::mojom::RenderPassQuadState::filters_scale)& filters_scale(
        const ::cc::mojom::RenderPassQuadStatePtr& input)
    {
        return input->filters_scale;
    }

    static const decltype(::cc::mojom::RenderPassQuadState::filters_origin)& filters_origin(
        const ::cc::mojom::RenderPassQuadStatePtr& input)
    {
        return input->filters_origin;
    }

    static bool Read(::cc::mojom::RenderPassQuadState::DataView input, ::cc::mojom::RenderPassQuadStatePtr* output);
};

template <>
struct StructTraits<::cc::mojom::SolidColorQuadState::DataView,
    ::cc::mojom::SolidColorQuadStatePtr> {
    static bool IsNull(const ::cc::mojom::SolidColorQuadStatePtr& input) { return !input; }
    static void SetToNull(::cc::mojom::SolidColorQuadStatePtr* output) { output->reset(); }

    static decltype(::cc::mojom::SolidColorQuadState::color) color(
        const ::cc::mojom::SolidColorQuadStatePtr& input)
    {
        return input->color;
    }

    static decltype(::cc::mojom::SolidColorQuadState::force_anti_aliasing_off) force_anti_aliasing_off(
        const ::cc::mojom::SolidColorQuadStatePtr& input)
    {
        return input->force_anti_aliasing_off;
    }

    static bool Read(::cc::mojom::SolidColorQuadState::DataView input, ::cc::mojom::SolidColorQuadStatePtr* output);
};

template <>
struct StructTraits<::cc::mojom::StreamVideoQuadState::DataView,
    ::cc::mojom::StreamVideoQuadStatePtr> {
    static bool IsNull(const ::cc::mojom::StreamVideoQuadStatePtr& input) { return !input; }
    static void SetToNull(::cc::mojom::StreamVideoQuadStatePtr* output) { output->reset(); }

    static decltype(::cc::mojom::StreamVideoQuadState::resource_id) resource_id(
        const ::cc::mojom::StreamVideoQuadStatePtr& input)
    {
        return input->resource_id;
    }

    static const decltype(::cc::mojom::StreamVideoQuadState::resource_size_in_pixels)& resource_size_in_pixels(
        const ::cc::mojom::StreamVideoQuadStatePtr& input)
    {
        return input->resource_size_in_pixels;
    }

    static const decltype(::cc::mojom::StreamVideoQuadState::matrix)& matrix(
        const ::cc::mojom::StreamVideoQuadStatePtr& input)
    {
        return input->matrix;
    }

    static bool Read(::cc::mojom::StreamVideoQuadState::DataView input, ::cc::mojom::StreamVideoQuadStatePtr* output);
};

template <>
struct StructTraits<::cc::mojom::SurfaceQuadState::DataView,
    ::cc::mojom::SurfaceQuadStatePtr> {
    static bool IsNull(const ::cc::mojom::SurfaceQuadStatePtr& input) { return !input; }
    static void SetToNull(::cc::mojom::SurfaceQuadStatePtr* output) { output->reset(); }

    static const decltype(::cc::mojom::SurfaceQuadState::surface)& surface(
        const ::cc::mojom::SurfaceQuadStatePtr& input)
    {
        return input->surface;
    }

    static bool Read(::cc::mojom::SurfaceQuadState::DataView input, ::cc::mojom::SurfaceQuadStatePtr* output);
};

template <>
struct StructTraits<::cc::mojom::TextureQuadState::DataView,
    ::cc::mojom::TextureQuadStatePtr> {
    static bool IsNull(const ::cc::mojom::TextureQuadStatePtr& input) { return !input; }
    static void SetToNull(::cc::mojom::TextureQuadStatePtr* output) { output->reset(); }

    static decltype(::cc::mojom::TextureQuadState::resource_id) resource_id(
        const ::cc::mojom::TextureQuadStatePtr& input)
    {
        return input->resource_id;
    }

    static const decltype(::cc::mojom::TextureQuadState::resource_size_in_pixels)& resource_size_in_pixels(
        const ::cc::mojom::TextureQuadStatePtr& input)
    {
        return input->resource_size_in_pixels;
    }

    static decltype(::cc::mojom::TextureQuadState::premultiplied_alpha) premultiplied_alpha(
        const ::cc::mojom::TextureQuadStatePtr& input)
    {
        return input->premultiplied_alpha;
    }

    static const decltype(::cc::mojom::TextureQuadState::uv_top_left)& uv_top_left(
        const ::cc::mojom::TextureQuadStatePtr& input)
    {
        return input->uv_top_left;
    }

    static const decltype(::cc::mojom::TextureQuadState::uv_bottom_right)& uv_bottom_right(
        const ::cc::mojom::TextureQuadStatePtr& input)
    {
        return input->uv_bottom_right;
    }

    static decltype(::cc::mojom::TextureQuadState::background_color) background_color(
        const ::cc::mojom::TextureQuadStatePtr& input)
    {
        return input->background_color;
    }

    static const decltype(::cc::mojom::TextureQuadState::vertex_opacity)& vertex_opacity(
        const ::cc::mojom::TextureQuadStatePtr& input)
    {
        return input->vertex_opacity;
    }

    static decltype(::cc::mojom::TextureQuadState::y_flipped) y_flipped(
        const ::cc::mojom::TextureQuadStatePtr& input)
    {
        return input->y_flipped;
    }

    static decltype(::cc::mojom::TextureQuadState::nearest_neighbor) nearest_neighbor(
        const ::cc::mojom::TextureQuadStatePtr& input)
    {
        return input->nearest_neighbor;
    }

    static decltype(::cc::mojom::TextureQuadState::secure_output_only) secure_output_only(
        const ::cc::mojom::TextureQuadStatePtr& input)
    {
        return input->secure_output_only;
    }

    static bool Read(::cc::mojom::TextureQuadState::DataView input, ::cc::mojom::TextureQuadStatePtr* output);
};

template <>
struct StructTraits<::cc::mojom::TileQuadState::DataView,
    ::cc::mojom::TileQuadStatePtr> {
    static bool IsNull(const ::cc::mojom::TileQuadStatePtr& input) { return !input; }
    static void SetToNull(::cc::mojom::TileQuadStatePtr* output) { output->reset(); }

    static const decltype(::cc::mojom::TileQuadState::tex_coord_rect)& tex_coord_rect(
        const ::cc::mojom::TileQuadStatePtr& input)
    {
        return input->tex_coord_rect;
    }

    static const decltype(::cc::mojom::TileQuadState::texture_size)& texture_size(
        const ::cc::mojom::TileQuadStatePtr& input)
    {
        return input->texture_size;
    }

    static decltype(::cc::mojom::TileQuadState::swizzle_contents) swizzle_contents(
        const ::cc::mojom::TileQuadStatePtr& input)
    {
        return input->swizzle_contents;
    }

    static decltype(::cc::mojom::TileQuadState::resource_id) resource_id(
        const ::cc::mojom::TileQuadStatePtr& input)
    {
        return input->resource_id;
    }

    static decltype(::cc::mojom::TileQuadState::nearest_neighbor) nearest_neighbor(
        const ::cc::mojom::TileQuadStatePtr& input)
    {
        return input->nearest_neighbor;
    }

    static bool Read(::cc::mojom::TileQuadState::DataView input, ::cc::mojom::TileQuadStatePtr* output);
};

template <>
struct StructTraits<::cc::mojom::YUVVideoQuadState::DataView,
    ::cc::mojom::YUVVideoQuadStatePtr> {
    static bool IsNull(const ::cc::mojom::YUVVideoQuadStatePtr& input) { return !input; }
    static void SetToNull(::cc::mojom::YUVVideoQuadStatePtr* output) { output->reset(); }

    static const decltype(::cc::mojom::YUVVideoQuadState::ya_tex_coord_rect)& ya_tex_coord_rect(
        const ::cc::mojom::YUVVideoQuadStatePtr& input)
    {
        return input->ya_tex_coord_rect;
    }

    static const decltype(::cc::mojom::YUVVideoQuadState::uv_tex_coord_rect)& uv_tex_coord_rect(
        const ::cc::mojom::YUVVideoQuadStatePtr& input)
    {
        return input->uv_tex_coord_rect;
    }

    static const decltype(::cc::mojom::YUVVideoQuadState::ya_tex_size)& ya_tex_size(
        const ::cc::mojom::YUVVideoQuadStatePtr& input)
    {
        return input->ya_tex_size;
    }

    static const decltype(::cc::mojom::YUVVideoQuadState::uv_tex_size)& uv_tex_size(
        const ::cc::mojom::YUVVideoQuadStatePtr& input)
    {
        return input->uv_tex_size;
    }

    static decltype(::cc::mojom::YUVVideoQuadState::y_plane_resource_id) y_plane_resource_id(
        const ::cc::mojom::YUVVideoQuadStatePtr& input)
    {
        return input->y_plane_resource_id;
    }

    static decltype(::cc::mojom::YUVVideoQuadState::u_plane_resource_id) u_plane_resource_id(
        const ::cc::mojom::YUVVideoQuadStatePtr& input)
    {
        return input->u_plane_resource_id;
    }

    static decltype(::cc::mojom::YUVVideoQuadState::v_plane_resource_id) v_plane_resource_id(
        const ::cc::mojom::YUVVideoQuadStatePtr& input)
    {
        return input->v_plane_resource_id;
    }

    static decltype(::cc::mojom::YUVVideoQuadState::a_plane_resource_id) a_plane_resource_id(
        const ::cc::mojom::YUVVideoQuadStatePtr& input)
    {
        return input->a_plane_resource_id;
    }

    static decltype(::cc::mojom::YUVVideoQuadState::color_space) color_space(
        const ::cc::mojom::YUVVideoQuadStatePtr& input)
    {
        return input->color_space;
    }

    static decltype(::cc::mojom::YUVVideoQuadState::resource_offset) resource_offset(
        const ::cc::mojom::YUVVideoQuadStatePtr& input)
    {
        return input->resource_offset;
    }

    static decltype(::cc::mojom::YUVVideoQuadState::resource_multiplier) resource_multiplier(
        const ::cc::mojom::YUVVideoQuadStatePtr& input)
    {
        return input->resource_multiplier;
    }

    static decltype(::cc::mojom::YUVVideoQuadState::bits_per_channel) bits_per_channel(
        const ::cc::mojom::YUVVideoQuadStatePtr& input)
    {
        return input->bits_per_channel;
    }

    static bool Read(::cc::mojom::YUVVideoQuadState::DataView input, ::cc::mojom::YUVVideoQuadStatePtr* output);
};

template <>
struct StructTraits<::cc::mojom::DrawQuad::DataView,
    ::cc::mojom::DrawQuadPtr> {
    static bool IsNull(const ::cc::mojom::DrawQuadPtr& input) { return !input; }
    static void SetToNull(::cc::mojom::DrawQuadPtr* output) { output->reset(); }

    static const decltype(::cc::mojom::DrawQuad::rect)& rect(
        const ::cc::mojom::DrawQuadPtr& input)
    {
        return input->rect;
    }

    static const decltype(::cc::mojom::DrawQuad::opaque_rect)& opaque_rect(
        const ::cc::mojom::DrawQuadPtr& input)
    {
        return input->opaque_rect;
    }

    static const decltype(::cc::mojom::DrawQuad::visible_rect)& visible_rect(
        const ::cc::mojom::DrawQuadPtr& input)
    {
        return input->visible_rect;
    }

    static decltype(::cc::mojom::DrawQuad::needs_blending) needs_blending(
        const ::cc::mojom::DrawQuadPtr& input)
    {
        return input->needs_blending;
    }

    static const decltype(::cc::mojom::DrawQuad::sqs)& sqs(
        const ::cc::mojom::DrawQuadPtr& input)
    {
        return input->sqs;
    }

    static const decltype(::cc::mojom::DrawQuad::draw_quad_state)& draw_quad_state(
        const ::cc::mojom::DrawQuadPtr& input)
    {
        return input->draw_quad_state;
    }

    static bool Read(::cc::mojom::DrawQuad::DataView input, ::cc::mojom::DrawQuadPtr* output);
};

template <>
struct UnionTraits<::cc::mojom::DrawQuadState::DataView,
    ::cc::mojom::DrawQuadStatePtr> {
    static bool IsNull(const ::cc::mojom::DrawQuadStatePtr& input) { return !input; }
    static void SetToNull(::cc::mojom::DrawQuadStatePtr* output) { output->reset(); }

    static ::cc::mojom::DrawQuadState::Tag GetTag(const ::cc::mojom::DrawQuadStatePtr& input)
    {
        return input->which();
    }

    static const ::cc::mojom::DebugBorderQuadStatePtr& debug_border_quad_state(const ::cc::mojom::DrawQuadStatePtr& input)
    {
        return input->get_debug_border_quad_state();
    }

    static const ::cc::mojom::RenderPassQuadStatePtr& render_pass_quad_state(const ::cc::mojom::DrawQuadStatePtr& input)
    {
        return input->get_render_pass_quad_state();
    }

    static const ::cc::mojom::SolidColorQuadStatePtr& solid_color_quad_state(const ::cc::mojom::DrawQuadStatePtr& input)
    {
        return input->get_solid_color_quad_state();
    }

    static const ::cc::mojom::StreamVideoQuadStatePtr& stream_video_quad_state(const ::cc::mojom::DrawQuadStatePtr& input)
    {
        return input->get_stream_video_quad_state();
    }

    static const ::cc::mojom::SurfaceQuadStatePtr& surface_quad_state(const ::cc::mojom::DrawQuadStatePtr& input)
    {
        return input->get_surface_quad_state();
    }

    static const ::cc::mojom::TextureQuadStatePtr& texture_quad_state(const ::cc::mojom::DrawQuadStatePtr& input)
    {
        return input->get_texture_quad_state();
    }

    static const ::cc::mojom::TileQuadStatePtr& tile_quad_state(const ::cc::mojom::DrawQuadStatePtr& input)
    {
        return input->get_tile_quad_state();
    }

    static const ::cc::mojom::YUVVideoQuadStatePtr& yuv_video_quad_state(const ::cc::mojom::DrawQuadStatePtr& input)
    {
        return input->get_yuv_video_quad_state();
    }

    static bool Read(::cc::mojom::DrawQuadState::DataView input, ::cc::mojom::DrawQuadStatePtr* output);
};

} // namespace mojo

#endif // CC_IPC_QUADS_MOJOM_H_