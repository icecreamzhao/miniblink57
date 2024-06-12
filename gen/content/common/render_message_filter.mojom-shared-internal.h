// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_RENDER_MESSAGE_FILTER_MOJOM_SHARED_INTERNAL_H_
#define CONTENT_COMMON_RENDER_MESSAGE_FILTER_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "content/common/native_types.mojom-shared-internal.h"
#include "content/public/common/window_container_type.mojom-shared-internal.h"
#include "gpu/ipc/common/mailbox.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "third_party/WebKit/public/platform/referrer.mojom-shared-internal.h"
#include "third_party/WebKit/public/web/window_features.mojom-shared-internal.h"
#include "ui/base/mojo/window_open_disposition.mojom-shared-internal.h"
#include "url/mojo/url.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace content {
namespace mojom {
    namespace internal {
        class CreateNewWindowParams_Data;
        class CreateNewWindowReply_Data;

#pragma pack(push, 1)
        class CreateNewWindowParams_Data {
        public:
            static CreateNewWindowParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(CreateNewWindowParams_Data))) CreateNewWindowParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t opener_render_frame_id;
            uint8_t user_gesture : 1;
            uint8_t opener_suppressed : 1;
            uint8_t pad2_[3];
            int32_t window_container_type;
            int32_t disposition;
            int64_t session_storage_namespace_id;
            mojo::internal::Pointer<mojo::internal::String_Data> frame_name;
            mojo::internal::Pointer<::url::mojom::internal::Url_Data> opener_url;
            mojo::internal::Pointer<::url::mojom::internal::Url_Data> opener_top_level_frame_url;
            mojo::internal::Pointer<::url::mojom::internal::Url_Data> opener_security_origin;
            mojo::internal::Pointer<::url::mojom::internal::Url_Data> target_url;
            mojo::internal::Pointer<::blink::mojom::internal::Referrer_Data> referrer;
            mojo::internal::Pointer<::blink::mojom::internal::WindowFeatures_Data> features;

        private:
            CreateNewWindowParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~CreateNewWindowParams_Data() = delete;
        };
        static_assert(sizeof(CreateNewWindowParams_Data) == 88,
            "Bad sizeof(CreateNewWindowParams_Data)");
        class CreateNewWindowReply_Data {
        public:
            static CreateNewWindowReply_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(CreateNewWindowReply_Data))) CreateNewWindowReply_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t route_id;
            int32_t main_frame_route_id;
            int32_t main_frame_widget_route_id;
            uint8_t pad2_[4];
            int64_t cloned_session_storage_namespace_id;

        private:
            CreateNewWindowReply_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~CreateNewWindowReply_Data() = delete;
        };
        static_assert(sizeof(CreateNewWindowReply_Data) == 32,
            "Bad sizeof(CreateNewWindowReply_Data)");
        constexpr uint32_t kRenderMessageFilter_GenerateRoutingID_Name = 0;
        class RenderMessageFilter_GenerateRoutingID_Params_Data {
        public:
            static RenderMessageFilter_GenerateRoutingID_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RenderMessageFilter_GenerateRoutingID_Params_Data))) RenderMessageFilter_GenerateRoutingID_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            RenderMessageFilter_GenerateRoutingID_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RenderMessageFilter_GenerateRoutingID_Params_Data() = delete;
        };
        static_assert(sizeof(RenderMessageFilter_GenerateRoutingID_Params_Data) == 8,
            "Bad sizeof(RenderMessageFilter_GenerateRoutingID_Params_Data)");
        class RenderMessageFilter_GenerateRoutingID_ResponseParams_Data {
        public:
            static RenderMessageFilter_GenerateRoutingID_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RenderMessageFilter_GenerateRoutingID_ResponseParams_Data))) RenderMessageFilter_GenerateRoutingID_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t routing_id;
            uint8_t padfinal_[4];

        private:
            RenderMessageFilter_GenerateRoutingID_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RenderMessageFilter_GenerateRoutingID_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(RenderMessageFilter_GenerateRoutingID_ResponseParams_Data) == 16,
            "Bad sizeof(RenderMessageFilter_GenerateRoutingID_ResponseParams_Data)");
        constexpr uint32_t kRenderMessageFilter_CreateNewWindow_Name = 1;
        class RenderMessageFilter_CreateNewWindow_Params_Data {
        public:
            static RenderMessageFilter_CreateNewWindow_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RenderMessageFilter_CreateNewWindow_Params_Data))) RenderMessageFilter_CreateNewWindow_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::CreateNewWindowParams_Data> params;

        private:
            RenderMessageFilter_CreateNewWindow_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RenderMessageFilter_CreateNewWindow_Params_Data() = delete;
        };
        static_assert(sizeof(RenderMessageFilter_CreateNewWindow_Params_Data) == 16,
            "Bad sizeof(RenderMessageFilter_CreateNewWindow_Params_Data)");
        class RenderMessageFilter_CreateNewWindow_ResponseParams_Data {
        public:
            static RenderMessageFilter_CreateNewWindow_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RenderMessageFilter_CreateNewWindow_ResponseParams_Data))) RenderMessageFilter_CreateNewWindow_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::CreateNewWindowReply_Data> reply;

        private:
            RenderMessageFilter_CreateNewWindow_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RenderMessageFilter_CreateNewWindow_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(RenderMessageFilter_CreateNewWindow_ResponseParams_Data) == 16,
            "Bad sizeof(RenderMessageFilter_CreateNewWindow_ResponseParams_Data)");
        constexpr uint32_t kRenderMessageFilter_CreateNewWidget_Name = 2;
        class RenderMessageFilter_CreateNewWidget_Params_Data {
        public:
            static RenderMessageFilter_CreateNewWidget_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RenderMessageFilter_CreateNewWidget_Params_Data))) RenderMessageFilter_CreateNewWidget_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t opener_id;
            int32_t popup_type;

        private:
            RenderMessageFilter_CreateNewWidget_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RenderMessageFilter_CreateNewWidget_Params_Data() = delete;
        };
        static_assert(sizeof(RenderMessageFilter_CreateNewWidget_Params_Data) == 16,
            "Bad sizeof(RenderMessageFilter_CreateNewWidget_Params_Data)");
        class RenderMessageFilter_CreateNewWidget_ResponseParams_Data {
        public:
            static RenderMessageFilter_CreateNewWidget_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RenderMessageFilter_CreateNewWidget_ResponseParams_Data))) RenderMessageFilter_CreateNewWidget_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t route_id;
            uint8_t padfinal_[4];

        private:
            RenderMessageFilter_CreateNewWidget_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RenderMessageFilter_CreateNewWidget_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(RenderMessageFilter_CreateNewWidget_ResponseParams_Data) == 16,
            "Bad sizeof(RenderMessageFilter_CreateNewWidget_ResponseParams_Data)");
        constexpr uint32_t kRenderMessageFilter_CreateFullscreenWidget_Name = 3;
        class RenderMessageFilter_CreateFullscreenWidget_Params_Data {
        public:
            static RenderMessageFilter_CreateFullscreenWidget_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RenderMessageFilter_CreateFullscreenWidget_Params_Data))) RenderMessageFilter_CreateFullscreenWidget_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t opener_id;
            uint8_t padfinal_[4];

        private:
            RenderMessageFilter_CreateFullscreenWidget_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RenderMessageFilter_CreateFullscreenWidget_Params_Data() = delete;
        };
        static_assert(sizeof(RenderMessageFilter_CreateFullscreenWidget_Params_Data) == 16,
            "Bad sizeof(RenderMessageFilter_CreateFullscreenWidget_Params_Data)");
        class RenderMessageFilter_CreateFullscreenWidget_ResponseParams_Data {
        public:
            static RenderMessageFilter_CreateFullscreenWidget_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RenderMessageFilter_CreateFullscreenWidget_ResponseParams_Data))) RenderMessageFilter_CreateFullscreenWidget_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t route_id;
            uint8_t padfinal_[4];

        private:
            RenderMessageFilter_CreateFullscreenWidget_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RenderMessageFilter_CreateFullscreenWidget_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(RenderMessageFilter_CreateFullscreenWidget_ResponseParams_Data) == 16,
            "Bad sizeof(RenderMessageFilter_CreateFullscreenWidget_ResponseParams_Data)");
        constexpr uint32_t kRenderMessageFilter_AllocatedSharedBitmap_Name = 4;
        class RenderMessageFilter_AllocatedSharedBitmap_Params_Data {
        public:
            static RenderMessageFilter_AllocatedSharedBitmap_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RenderMessageFilter_AllocatedSharedBitmap_Params_Data))) RenderMessageFilter_AllocatedSharedBitmap_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data buffer;
            uint8_t pad0_[4];
            mojo::internal::Pointer<::gpu::mojom::internal::Mailbox_Data> id;

        private:
            RenderMessageFilter_AllocatedSharedBitmap_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RenderMessageFilter_AllocatedSharedBitmap_Params_Data() = delete;
        };
        static_assert(sizeof(RenderMessageFilter_AllocatedSharedBitmap_Params_Data) == 24,
            "Bad sizeof(RenderMessageFilter_AllocatedSharedBitmap_Params_Data)");
        constexpr uint32_t kRenderMessageFilter_DeletedSharedBitmap_Name = 5;
        class RenderMessageFilter_DeletedSharedBitmap_Params_Data {
        public:
            static RenderMessageFilter_DeletedSharedBitmap_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RenderMessageFilter_DeletedSharedBitmap_Params_Data))) RenderMessageFilter_DeletedSharedBitmap_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::gpu::mojom::internal::Mailbox_Data> id;

        private:
            RenderMessageFilter_DeletedSharedBitmap_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RenderMessageFilter_DeletedSharedBitmap_Params_Data() = delete;
        };
        static_assert(sizeof(RenderMessageFilter_DeletedSharedBitmap_Params_Data) == 16,
            "Bad sizeof(RenderMessageFilter_DeletedSharedBitmap_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace content

#endif // CONTENT_COMMON_RENDER_MESSAGE_FILTER_MOJOM_SHARED_INTERNAL_H_