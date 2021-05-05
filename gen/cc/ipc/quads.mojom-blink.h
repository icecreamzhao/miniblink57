// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_QUADS_MOJOM_BLINK_H_
#define CC_IPC_QUADS_MOJOM_BLINK_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "cc/ipc/filter_operations.mojom-blink.h"
#include "cc/ipc/quads.mojom-shared.h"
#include "cc/ipc/shared_quad_state.mojom-blink.h"
#include "cc/ipc/surface_id.mojom-blink.h"
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
#include "ui/gfx/geometry/mojo/geometry.mojom-blink.h"
#include "ui/gfx/mojo/transform.mojom-blink.h"

#include "base/files/file.h"
#include "cc/output/begin_frame_args.h"
#include "cc/output/compositor_frame.h"
#include "cc/resources/returned_resource.h"
#include "cc/surfaces/frame_sink_id.h"
#include "cc/surfaces/local_frame_id.h"
#include "cc/surfaces/surface_id.h"
#include "cc/surfaces/surface_info.h"
#include "cc/surfaces/surface_sequence.h"
#include "mojo/public/cpp/bindings/lib/wtf_hash_util.h"
#include "third_party/WebKit/Source/wtf/HashFunctions.h"
#include "third_party/WebKit/Source/wtf/Optional.h"
#include "third_party/WebKit/Source/wtf/text/WTFString.h"
#include "third_party/WebKit/public/platform/WebSize.h"

namespace cc {
namespace mojom {
    namespace blink {
        using YUVColorSpace = YUVColorSpace; // Alias for definition in the parent namespace.
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
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    DebugBorderQuadState::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    DebugBorderQuadState::DataView, WTF::Vector<uint8_t>>(
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
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    SolidColorQuadState::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    SolidColorQuadState::DataView, WTF::Vector<uint8_t>>(
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
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    RenderPassQuadState::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    RenderPassQuadState::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            int32_t render_pass_id;
            uint32_t mask_resource_id;
            ::gfx::mojom::blink::Vector2dFPtr mask_uv_scale;
            ::blink::WebSize mask_texture_size;
            ::gfx::mojom::blink::Vector2dFPtr filters_scale;
            ::gfx::mojom::blink::PointFPtr filters_origin;

        private:
            DISALLOW_COPY_AND_ASSIGN(RenderPassQuadState);
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
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    StreamVideoQuadState::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    StreamVideoQuadState::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            uint32_t resource_id;
            ::blink::WebSize resource_size_in_pixels;
            ::gfx::mojom::blink::TransformPtr matrix;

        private:
            DISALLOW_COPY_AND_ASSIGN(StreamVideoQuadState);
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
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    SurfaceQuadState::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    SurfaceQuadState::DataView, WTF::Vector<uint8_t>>(
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
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    TextureQuadState::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    TextureQuadState::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            uint32_t resource_id;
            ::blink::WebSize resource_size_in_pixels;
            bool premultiplied_alpha;
            ::gfx::mojom::blink::PointFPtr uv_top_left;
            ::gfx::mojom::blink::PointFPtr uv_bottom_right;
            uint32_t background_color;
            WTF::Vector<float> vertex_opacity;
            bool y_flipped;
            bool nearest_neighbor;
            bool secure_output_only;

        private:
            DISALLOW_COPY_AND_ASSIGN(TextureQuadState);
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
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    TileQuadState::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    TileQuadState::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            ::gfx::mojom::blink::RectFPtr tex_coord_rect;
            ::blink::WebSize texture_size;
            bool swizzle_contents;
            uint32_t resource_id;
            bool nearest_neighbor;

        private:
            DISALLOW_COPY_AND_ASSIGN(TileQuadState);
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
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    YUVVideoQuadState::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    YUVVideoQuadState::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            ::gfx::mojom::blink::RectFPtr ya_tex_coord_rect;
            ::gfx::mojom::blink::RectFPtr uv_tex_coord_rect;
            ::blink::WebSize ya_tex_size;
            ::blink::WebSize uv_tex_size;
            uint32_t y_plane_resource_id;
            uint32_t u_plane_resource_id;
            uint32_t v_plane_resource_id;
            uint32_t a_plane_resource_id;
            YUVColorSpace color_space;
            float resource_offset;
            float resource_multiplier;
            uint32_t bits_per_channel;

        private:
            DISALLOW_COPY_AND_ASSIGN(YUVVideoQuadState);
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
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    DrawQuad::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    DrawQuad::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            ::gfx::mojom::blink::RectPtr rect;
            ::gfx::mojom::blink::RectPtr opaque_rect;
            ::gfx::mojom::blink::RectPtr visible_rect;
            bool needs_blending;
            ::cc::mojom::blink::SharedQuadStatePtr sqs;
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

    } // namespace blink
} // namespace mojom
} // namespace cc

namespace mojo {

template <>
struct StructTraits<::cc::mojom::blink::DebugBorderQuadState::DataView,
    ::cc::mojom::blink::DebugBorderQuadStatePtr> {
    static bool IsNull(const ::cc::mojom::blink::DebugBorderQuadStatePtr& input) { return !input; }
    static void SetToNull(::cc::mojom::blink::DebugBorderQuadStatePtr* output) { output->reset(); }

    static decltype(::cc::mojom::blink::DebugBorderQuadState::color) color(
        const ::cc::mojom::blink::DebugBorderQuadStatePtr& input)
    {
        return input->color;
    }

    static decltype(::cc::mojom::blink::DebugBorderQuadState::width) width(
        const ::cc::mojom::blink::DebugBorderQuadStatePtr& input)
    {
        return input->width;
    }

    static bool Read(::cc::mojom::blink::DebugBorderQuadState::DataView input, ::cc::mojom::blink::DebugBorderQuadStatePtr* output);
};

template <>
struct StructTraits<::cc::mojom::blink::RenderPassQuadState::DataView,
    ::cc::mojom::blink::RenderPassQuadStatePtr> {
    static bool IsNull(const ::cc::mojom::blink::RenderPassQuadStatePtr& input) { return !input; }
    static void SetToNull(::cc::mojom::blink::RenderPassQuadStatePtr* output) { output->reset(); }

    static decltype(::cc::mojom::blink::RenderPassQuadState::render_pass_id) render_pass_id(
        const ::cc::mojom::blink::RenderPassQuadStatePtr& input)
    {
        return input->render_pass_id;
    }

    static decltype(::cc::mojom::blink::RenderPassQuadState::mask_resource_id) mask_resource_id(
        const ::cc::mojom::blink::RenderPassQuadStatePtr& input)
    {
        return input->mask_resource_id;
    }

    static const decltype(::cc::mojom::blink::RenderPassQuadState::mask_uv_scale)& mask_uv_scale(
        const ::cc::mojom::blink::RenderPassQuadStatePtr& input)
    {
        return input->mask_uv_scale;
    }

    static const decltype(::cc::mojom::blink::RenderPassQuadState::mask_texture_size)& mask_texture_size(
        const ::cc::mojom::blink::RenderPassQuadStatePtr& input)
    {
        return input->mask_texture_size;
    }

    static const decltype(::cc::mojom::blink::RenderPassQuadState::filters_scale)& filters_scale(
        const ::cc::mojom::blink::RenderPassQuadStatePtr& input)
    {
        return input->filters_scale;
    }

    static const decltype(::cc::mojom::blink::RenderPassQuadState::filters_origin)& filters_origin(
        const ::cc::mojom::blink::RenderPassQuadStatePtr& input)
    {
        return input->filters_origin;
    }

    static bool Read(::cc::mojom::blink::RenderPassQuadState::DataView input, ::cc::mojom::blink::RenderPassQuadStatePtr* output);
};

template <>
struct StructTraits<::cc::mojom::blink::SolidColorQuadState::DataView,
    ::cc::mojom::blink::SolidColorQuadStatePtr> {
    static bool IsNull(const ::cc::mojom::blink::SolidColorQuadStatePtr& input) { return !input; }
    static void SetToNull(::cc::mojom::blink::SolidColorQuadStatePtr* output) { output->reset(); }

    static decltype(::cc::mojom::blink::SolidColorQuadState::color) color(
        const ::cc::mojom::blink::SolidColorQuadStatePtr& input)
    {
        return input->color;
    }

    static decltype(::cc::mojom::blink::SolidColorQuadState::force_anti_aliasing_off) force_anti_aliasing_off(
        const ::cc::mojom::blink::SolidColorQuadStatePtr& input)
    {
        return input->force_anti_aliasing_off;
    }

    static bool Read(::cc::mojom::blink::SolidColorQuadState::DataView input, ::cc::mojom::blink::SolidColorQuadStatePtr* output);
};

template <>
struct StructTraits<::cc::mojom::blink::StreamVideoQuadState::DataView,
    ::cc::mojom::blink::StreamVideoQuadStatePtr> {
    static bool IsNull(const ::cc::mojom::blink::StreamVideoQuadStatePtr& input) { return !input; }
    static void SetToNull(::cc::mojom::blink::StreamVideoQuadStatePtr* output) { output->reset(); }

    static decltype(::cc::mojom::blink::StreamVideoQuadState::resource_id) resource_id(
        const ::cc::mojom::blink::StreamVideoQuadStatePtr& input)
    {
        return input->resource_id;
    }

    static const decltype(::cc::mojom::blink::StreamVideoQuadState::resource_size_in_pixels)& resource_size_in_pixels(
        const ::cc::mojom::blink::StreamVideoQuadStatePtr& input)
    {
        return input->resource_size_in_pixels;
    }

    static const decltype(::cc::mojom::blink::StreamVideoQuadState::matrix)& matrix(
        const ::cc::mojom::blink::StreamVideoQuadStatePtr& input)
    {
        return input->matrix;
    }

    static bool Read(::cc::mojom::blink::StreamVideoQuadState::DataView input, ::cc::mojom::blink::StreamVideoQuadStatePtr* output);
};

template <>
struct StructTraits<::cc::mojom::blink::SurfaceQuadState::DataView,
    ::cc::mojom::blink::SurfaceQuadStatePtr> {
    static bool IsNull(const ::cc::mojom::blink::SurfaceQuadStatePtr& input) { return !input; }
    static void SetToNull(::cc::mojom::blink::SurfaceQuadStatePtr* output) { output->reset(); }

    static const decltype(::cc::mojom::blink::SurfaceQuadState::surface)& surface(
        const ::cc::mojom::blink::SurfaceQuadStatePtr& input)
    {
        return input->surface;
    }

    static bool Read(::cc::mojom::blink::SurfaceQuadState::DataView input, ::cc::mojom::blink::SurfaceQuadStatePtr* output);
};

template <>
struct StructTraits<::cc::mojom::blink::TextureQuadState::DataView,
    ::cc::mojom::blink::TextureQuadStatePtr> {
    static bool IsNull(const ::cc::mojom::blink::TextureQuadStatePtr& input) { return !input; }
    static void SetToNull(::cc::mojom::blink::TextureQuadStatePtr* output) { output->reset(); }

    static decltype(::cc::mojom::blink::TextureQuadState::resource_id) resource_id(
        const ::cc::mojom::blink::TextureQuadStatePtr& input)
    {
        return input->resource_id;
    }

    static const decltype(::cc::mojom::blink::TextureQuadState::resource_size_in_pixels)& resource_size_in_pixels(
        const ::cc::mojom::blink::TextureQuadStatePtr& input)
    {
        return input->resource_size_in_pixels;
    }

    static decltype(::cc::mojom::blink::TextureQuadState::premultiplied_alpha) premultiplied_alpha(
        const ::cc::mojom::blink::TextureQuadStatePtr& input)
    {
        return input->premultiplied_alpha;
    }

    static const decltype(::cc::mojom::blink::TextureQuadState::uv_top_left)& uv_top_left(
        const ::cc::mojom::blink::TextureQuadStatePtr& input)
    {
        return input->uv_top_left;
    }

    static const decltype(::cc::mojom::blink::TextureQuadState::uv_bottom_right)& uv_bottom_right(
        const ::cc::mojom::blink::TextureQuadStatePtr& input)
    {
        return input->uv_bottom_right;
    }

    static decltype(::cc::mojom::blink::TextureQuadState::background_color) background_color(
        const ::cc::mojom::blink::TextureQuadStatePtr& input)
    {
        return input->background_color;
    }

    static const decltype(::cc::mojom::blink::TextureQuadState::vertex_opacity)& vertex_opacity(
        const ::cc::mojom::blink::TextureQuadStatePtr& input)
    {
        return input->vertex_opacity;
    }

    static decltype(::cc::mojom::blink::TextureQuadState::y_flipped) y_flipped(
        const ::cc::mojom::blink::TextureQuadStatePtr& input)
    {
        return input->y_flipped;
    }

    static decltype(::cc::mojom::blink::TextureQuadState::nearest_neighbor) nearest_neighbor(
        const ::cc::mojom::blink::TextureQuadStatePtr& input)
    {
        return input->nearest_neighbor;
    }

    static decltype(::cc::mojom::blink::TextureQuadState::secure_output_only) secure_output_only(
        const ::cc::mojom::blink::TextureQuadStatePtr& input)
    {
        return input->secure_output_only;
    }

    static bool Read(::cc::mojom::blink::TextureQuadState::DataView input, ::cc::mojom::blink::TextureQuadStatePtr* output);
};

template <>
struct StructTraits<::cc::mojom::blink::TileQuadState::DataView,
    ::cc::mojom::blink::TileQuadStatePtr> {
    static bool IsNull(const ::cc::mojom::blink::TileQuadStatePtr& input) { return !input; }
    static void SetToNull(::cc::mojom::blink::TileQuadStatePtr* output) { output->reset(); }

    static const decltype(::cc::mojom::blink::TileQuadState::tex_coord_rect)& tex_coord_rect(
        const ::cc::mojom::blink::TileQuadStatePtr& input)
    {
        return input->tex_coord_rect;
    }

    static const decltype(::cc::mojom::blink::TileQuadState::texture_size)& texture_size(
        const ::cc::mojom::blink::TileQuadStatePtr& input)
    {
        return input->texture_size;
    }

    static decltype(::cc::mojom::blink::TileQuadState::swizzle_contents) swizzle_contents(
        const ::cc::mojom::blink::TileQuadStatePtr& input)
    {
        return input->swizzle_contents;
    }

    static decltype(::cc::mojom::blink::TileQuadState::resource_id) resource_id(
        const ::cc::mojom::blink::TileQuadStatePtr& input)
    {
        return input->resource_id;
    }

    static decltype(::cc::mojom::blink::TileQuadState::nearest_neighbor) nearest_neighbor(
        const ::cc::mojom::blink::TileQuadStatePtr& input)
    {
        return input->nearest_neighbor;
    }

    static bool Read(::cc::mojom::blink::TileQuadState::DataView input, ::cc::mojom::blink::TileQuadStatePtr* output);
};

template <>
struct StructTraits<::cc::mojom::blink::YUVVideoQuadState::DataView,
    ::cc::mojom::blink::YUVVideoQuadStatePtr> {
    static bool IsNull(const ::cc::mojom::blink::YUVVideoQuadStatePtr& input) { return !input; }
    static void SetToNull(::cc::mojom::blink::YUVVideoQuadStatePtr* output) { output->reset(); }

    static const decltype(::cc::mojom::blink::YUVVideoQuadState::ya_tex_coord_rect)& ya_tex_coord_rect(
        const ::cc::mojom::blink::YUVVideoQuadStatePtr& input)
    {
        return input->ya_tex_coord_rect;
    }

    static const decltype(::cc::mojom::blink::YUVVideoQuadState::uv_tex_coord_rect)& uv_tex_coord_rect(
        const ::cc::mojom::blink::YUVVideoQuadStatePtr& input)
    {
        return input->uv_tex_coord_rect;
    }

    static const decltype(::cc::mojom::blink::YUVVideoQuadState::ya_tex_size)& ya_tex_size(
        const ::cc::mojom::blink::YUVVideoQuadStatePtr& input)
    {
        return input->ya_tex_size;
    }

    static const decltype(::cc::mojom::blink::YUVVideoQuadState::uv_tex_size)& uv_tex_size(
        const ::cc::mojom::blink::YUVVideoQuadStatePtr& input)
    {
        return input->uv_tex_size;
    }

    static decltype(::cc::mojom::blink::YUVVideoQuadState::y_plane_resource_id) y_plane_resource_id(
        const ::cc::mojom::blink::YUVVideoQuadStatePtr& input)
    {
        return input->y_plane_resource_id;
    }

    static decltype(::cc::mojom::blink::YUVVideoQuadState::u_plane_resource_id) u_plane_resource_id(
        const ::cc::mojom::blink::YUVVideoQuadStatePtr& input)
    {
        return input->u_plane_resource_id;
    }

    static decltype(::cc::mojom::blink::YUVVideoQuadState::v_plane_resource_id) v_plane_resource_id(
        const ::cc::mojom::blink::YUVVideoQuadStatePtr& input)
    {
        return input->v_plane_resource_id;
    }

    static decltype(::cc::mojom::blink::YUVVideoQuadState::a_plane_resource_id) a_plane_resource_id(
        const ::cc::mojom::blink::YUVVideoQuadStatePtr& input)
    {
        return input->a_plane_resource_id;
    }

    static decltype(::cc::mojom::blink::YUVVideoQuadState::color_space) color_space(
        const ::cc::mojom::blink::YUVVideoQuadStatePtr& input)
    {
        return input->color_space;
    }

    static decltype(::cc::mojom::blink::YUVVideoQuadState::resource_offset) resource_offset(
        const ::cc::mojom::blink::YUVVideoQuadStatePtr& input)
    {
        return input->resource_offset;
    }

    static decltype(::cc::mojom::blink::YUVVideoQuadState::resource_multiplier) resource_multiplier(
        const ::cc::mojom::blink::YUVVideoQuadStatePtr& input)
    {
        return input->resource_multiplier;
    }

    static decltype(::cc::mojom::blink::YUVVideoQuadState::bits_per_channel) bits_per_channel(
        const ::cc::mojom::blink::YUVVideoQuadStatePtr& input)
    {
        return input->bits_per_channel;
    }

    static bool Read(::cc::mojom::blink::YUVVideoQuadState::DataView input, ::cc::mojom::blink::YUVVideoQuadStatePtr* output);
};

template <>
struct StructTraits<::cc::mojom::blink::DrawQuad::DataView,
    ::cc::mojom::blink::DrawQuadPtr> {
    static bool IsNull(const ::cc::mojom::blink::DrawQuadPtr& input) { return !input; }
    static void SetToNull(::cc::mojom::blink::DrawQuadPtr* output) { output->reset(); }

    static const decltype(::cc::mojom::blink::DrawQuad::rect)& rect(
        const ::cc::mojom::blink::DrawQuadPtr& input)
    {
        return input->rect;
    }

    static const decltype(::cc::mojom::blink::DrawQuad::opaque_rect)& opaque_rect(
        const ::cc::mojom::blink::DrawQuadPtr& input)
    {
        return input->opaque_rect;
    }

    static const decltype(::cc::mojom::blink::DrawQuad::visible_rect)& visible_rect(
        const ::cc::mojom::blink::DrawQuadPtr& input)
    {
        return input->visible_rect;
    }

    static decltype(::cc::mojom::blink::DrawQuad::needs_blending) needs_blending(
        const ::cc::mojom::blink::DrawQuadPtr& input)
    {
        return input->needs_blending;
    }

    static const decltype(::cc::mojom::blink::DrawQuad::sqs)& sqs(
        const ::cc::mojom::blink::DrawQuadPtr& input)
    {
        return input->sqs;
    }

    static const decltype(::cc::mojom::blink::DrawQuad::draw_quad_state)& draw_quad_state(
        const ::cc::mojom::blink::DrawQuadPtr& input)
    {
        return input->draw_quad_state;
    }

    static bool Read(::cc::mojom::blink::DrawQuad::DataView input, ::cc::mojom::blink::DrawQuadPtr* output);
};

template <>
struct UnionTraits<::cc::mojom::blink::DrawQuadState::DataView,
    ::cc::mojom::blink::DrawQuadStatePtr> {
    static bool IsNull(const ::cc::mojom::blink::DrawQuadStatePtr& input) { return !input; }
    static void SetToNull(::cc::mojom::blink::DrawQuadStatePtr* output) { output->reset(); }

    static ::cc::mojom::blink::DrawQuadState::Tag GetTag(const ::cc::mojom::blink::DrawQuadStatePtr& input)
    {
        return input->which();
    }

    static const ::cc::mojom::blink::DebugBorderQuadStatePtr& debug_border_quad_state(const ::cc::mojom::blink::DrawQuadStatePtr& input)
    {
        return input->get_debug_border_quad_state();
    }

    static const ::cc::mojom::blink::RenderPassQuadStatePtr& render_pass_quad_state(const ::cc::mojom::blink::DrawQuadStatePtr& input)
    {
        return input->get_render_pass_quad_state();
    }

    static const ::cc::mojom::blink::SolidColorQuadStatePtr& solid_color_quad_state(const ::cc::mojom::blink::DrawQuadStatePtr& input)
    {
        return input->get_solid_color_quad_state();
    }

    static const ::cc::mojom::blink::StreamVideoQuadStatePtr& stream_video_quad_state(const ::cc::mojom::blink::DrawQuadStatePtr& input)
    {
        return input->get_stream_video_quad_state();
    }

    static const ::cc::mojom::blink::SurfaceQuadStatePtr& surface_quad_state(const ::cc::mojom::blink::DrawQuadStatePtr& input)
    {
        return input->get_surface_quad_state();
    }

    static const ::cc::mojom::blink::TextureQuadStatePtr& texture_quad_state(const ::cc::mojom::blink::DrawQuadStatePtr& input)
    {
        return input->get_texture_quad_state();
    }

    static const ::cc::mojom::blink::TileQuadStatePtr& tile_quad_state(const ::cc::mojom::blink::DrawQuadStatePtr& input)
    {
        return input->get_tile_quad_state();
    }

    static const ::cc::mojom::blink::YUVVideoQuadStatePtr& yuv_video_quad_state(const ::cc::mojom::blink::DrawQuadStatePtr& input)
    {
        return input->get_yuv_video_quad_state();
    }

    static bool Read(::cc::mojom::blink::DrawQuadState::DataView input, ::cc::mojom::blink::DrawQuadStatePtr* output);
};

} // namespace mojo

#endif // CC_IPC_QUADS_MOJOM_BLINK_H_