// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_RENDERER_MOJOM_SHARED_INTERNAL_H_
#define CONTENT_COMMON_RENDERER_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "content/common/native_types.mojom-shared-internal.h"
#include "ipc/ipc.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared-internal.h"
#include "ui/gfx/mojo/icc_profile.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace content {
namespace mojom {
    namespace internal {
        class CreateViewParams_Data;
        class CreateFrameWidgetParams_Data;
        class CreateFrameParams_Data;
        class UpdateScrollbarThemeParams_Data;

#pragma pack(push, 1)
        class CreateViewParams_Data {
        public:
            static CreateViewParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(CreateViewParams_Data))) CreateViewParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::content::mojom::internal::RendererPreferences_Data> renderer_preferences;
            mojo::internal::Pointer<::content::mojom::internal::WebPreferences_Data> web_preferences;
            int32_t view_id;
            int32_t main_frame_routing_id;
            int32_t main_frame_widget_routing_id;
            int32_t opener_frame_route_id;
            int64_t session_storage_namespace_id;
            uint8_t swapped_out : 1;
            uint8_t hidden : 1;
            uint8_t never_visible : 1;
            uint8_t window_was_created_with_opener : 1;
            uint8_t enable_auto_resize : 1;
            uint8_t pad11_[3];
            int32_t proxy_routing_id;
            mojo::internal::Pointer<::content::mojom::internal::FrameReplicationState_Data> replicated_frame_state;
            mojo::internal::Pointer<::content::mojom::internal::ResizeParams_Data> initial_size;
            mojo::internal::Pointer<::gfx::mojom::internal::Size_Data> min_size;
            mojo::internal::Pointer<::gfx::mojom::internal::Size_Data> max_size;
            double page_zoom_level;
            mojo::internal::Pointer<::gfx::mojom::internal::ICCProfile_Data> image_decode_color_space;

        private:
            CreateViewParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~CreateViewParams_Data() = delete;
        };
        static_assert(sizeof(CreateViewParams_Data) == 104,
            "Bad sizeof(CreateViewParams_Data)");
        class CreateFrameWidgetParams_Data {
        public:
            static CreateFrameWidgetParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(CreateFrameWidgetParams_Data))) CreateFrameWidgetParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t routing_id;
            uint8_t hidden : 1;
            uint8_t padfinal_[3];

        private:
            CreateFrameWidgetParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~CreateFrameWidgetParams_Data() = delete;
        };
        static_assert(sizeof(CreateFrameWidgetParams_Data) == 16,
            "Bad sizeof(CreateFrameWidgetParams_Data)");
        class CreateFrameParams_Data {
        public:
            static CreateFrameParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(CreateFrameParams_Data))) CreateFrameParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t routing_id;
            int32_t proxy_routing_id;
            int32_t opener_routing_id;
            int32_t parent_routing_id;
            int32_t previous_sibling_routing_id;
            uint8_t pad4_[4];
            mojo::internal::Pointer<::content::mojom::internal::FrameReplicationState_Data> replication_state;
            mojo::internal::Pointer<::content::mojom::internal::FrameOwnerProperties_Data> frame_owner_properties;
            mojo::internal::Pointer<internal::CreateFrameWidgetParams_Data> widget_params;

        private:
            CreateFrameParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~CreateFrameParams_Data() = delete;
        };
        static_assert(sizeof(CreateFrameParams_Data) == 56,
            "Bad sizeof(CreateFrameParams_Data)");
        class UpdateScrollbarThemeParams_Data {
        public:
            static UpdateScrollbarThemeParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(UpdateScrollbarThemeParams_Data))) UpdateScrollbarThemeParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            float initial_button_delay;
            float autoscroll_button_delay;
            uint8_t jump_on_track_click : 1;
            uint8_t redraw : 1;
            uint8_t pad3_[3];
            int32_t preferred_scroller_style;
            int32_t button_placement;
            uint8_t padfinal_[4];

        private:
            UpdateScrollbarThemeParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~UpdateScrollbarThemeParams_Data() = delete;
        };
        static_assert(sizeof(UpdateScrollbarThemeParams_Data) == 32,
            "Bad sizeof(UpdateScrollbarThemeParams_Data)");
        constexpr uint32_t kRenderer_CreateView_Name = 0;
        class Renderer_CreateView_Params_Data {
        public:
            static Renderer_CreateView_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Renderer_CreateView_Params_Data))) Renderer_CreateView_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::CreateViewParams_Data> params;

        private:
            Renderer_CreateView_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Renderer_CreateView_Params_Data() = delete;
        };
        static_assert(sizeof(Renderer_CreateView_Params_Data) == 16,
            "Bad sizeof(Renderer_CreateView_Params_Data)");
        constexpr uint32_t kRenderer_CreateFrame_Name = 1;
        class Renderer_CreateFrame_Params_Data {
        public:
            static Renderer_CreateFrame_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Renderer_CreateFrame_Params_Data))) Renderer_CreateFrame_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::CreateFrameParams_Data> params;

        private:
            Renderer_CreateFrame_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Renderer_CreateFrame_Params_Data() = delete;
        };
        static_assert(sizeof(Renderer_CreateFrame_Params_Data) == 16,
            "Bad sizeof(Renderer_CreateFrame_Params_Data)");
        constexpr uint32_t kRenderer_CreateFrameProxy_Name = 2;
        class Renderer_CreateFrameProxy_Params_Data {
        public:
            static Renderer_CreateFrameProxy_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Renderer_CreateFrameProxy_Params_Data))) Renderer_CreateFrameProxy_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t routing_id;
            int32_t render_view_routing_id;
            int32_t opener_routing_id;
            int32_t parent_routing_id;
            mojo::internal::Pointer<::content::mojom::internal::FrameReplicationState_Data> replication_state;

        private:
            Renderer_CreateFrameProxy_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Renderer_CreateFrameProxy_Params_Data() = delete;
        };
        static_assert(sizeof(Renderer_CreateFrameProxy_Params_Data) == 32,
            "Bad sizeof(Renderer_CreateFrameProxy_Params_Data)");
        constexpr uint32_t kRenderer_OnNetworkConnectionChanged_Name = 3;
        class Renderer_OnNetworkConnectionChanged_Params_Data {
        public:
            static Renderer_OnNetworkConnectionChanged_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Renderer_OnNetworkConnectionChanged_Params_Data))) Renderer_OnNetworkConnectionChanged_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t connection_type;
            uint8_t pad0_[4];
            double max_bandwidth_mbps;

        private:
            Renderer_OnNetworkConnectionChanged_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Renderer_OnNetworkConnectionChanged_Params_Data() = delete;
        };
        static_assert(sizeof(Renderer_OnNetworkConnectionChanged_Params_Data) == 24,
            "Bad sizeof(Renderer_OnNetworkConnectionChanged_Params_Data)");
        constexpr uint32_t kRenderer_SetWebKitSharedTimersSuspended_Name = 4;
        class Renderer_SetWebKitSharedTimersSuspended_Params_Data {
        public:
            static Renderer_SetWebKitSharedTimersSuspended_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Renderer_SetWebKitSharedTimersSuspended_Params_Data))) Renderer_SetWebKitSharedTimersSuspended_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t suspend : 1;
            uint8_t padfinal_[7];

        private:
            Renderer_SetWebKitSharedTimersSuspended_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Renderer_SetWebKitSharedTimersSuspended_Params_Data() = delete;
        };
        static_assert(sizeof(Renderer_SetWebKitSharedTimersSuspended_Params_Data) == 16,
            "Bad sizeof(Renderer_SetWebKitSharedTimersSuspended_Params_Data)");
        constexpr uint32_t kRenderer_UpdateScrollbarTheme_Name = 5;
        class Renderer_UpdateScrollbarTheme_Params_Data {
        public:
            static Renderer_UpdateScrollbarTheme_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Renderer_UpdateScrollbarTheme_Params_Data))) Renderer_UpdateScrollbarTheme_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::UpdateScrollbarThemeParams_Data> params;

        private:
            Renderer_UpdateScrollbarTheme_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Renderer_UpdateScrollbarTheme_Params_Data() = delete;
        };
        static_assert(sizeof(Renderer_UpdateScrollbarTheme_Params_Data) == 16,
            "Bad sizeof(Renderer_UpdateScrollbarTheme_Params_Data)");
        constexpr uint32_t kRenderer_OnSystemColorsChanged_Name = 6;
        class Renderer_OnSystemColorsChanged_Params_Data {
        public:
            static Renderer_OnSystemColorsChanged_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Renderer_OnSystemColorsChanged_Params_Data))) Renderer_OnSystemColorsChanged_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t aqua_color_variant;
            uint8_t pad0_[4];
            mojo::internal::Pointer<mojo::internal::String_Data> highlight_text_color;
            mojo::internal::Pointer<mojo::internal::String_Data> highlight_color;

        private:
            Renderer_OnSystemColorsChanged_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Renderer_OnSystemColorsChanged_Params_Data() = delete;
        };
        static_assert(sizeof(Renderer_OnSystemColorsChanged_Params_Data) == 32,
            "Bad sizeof(Renderer_OnSystemColorsChanged_Params_Data)");
        constexpr uint32_t kRenderer_PurgePluginListCache_Name = 7;
        class Renderer_PurgePluginListCache_Params_Data {
        public:
            static Renderer_PurgePluginListCache_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Renderer_PurgePluginListCache_Params_Data))) Renderer_PurgePluginListCache_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t reload_pages : 1;
            uint8_t padfinal_[7];

        private:
            Renderer_PurgePluginListCache_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Renderer_PurgePluginListCache_Params_Data() = delete;
        };
        static_assert(sizeof(Renderer_PurgePluginListCache_Params_Data) == 16,
            "Bad sizeof(Renderer_PurgePluginListCache_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace content

#endif // CONTENT_COMMON_RENDERER_MOJOM_SHARED_INTERNAL_H_