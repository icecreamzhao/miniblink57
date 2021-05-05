// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_GPU_INTERFACES_GPU_HOST_MOJOM_SHARED_INTERNAL_H_
#define SERVICES_UI_GPU_INTERFACES_GPU_HOST_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "gpu/ipc/common/gpu_info.mojom-shared-internal.h"
#include "gpu/ipc/common/surface_handle.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "services/ui/gpu/interfaces/context_lost_reason.mojom-shared-internal.h"
#include "url/mojo/url.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace ui {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kGpuHost_DidInitialize_Name = 0;
        class GpuHost_DidInitialize_Params_Data {
        public:
            static GpuHost_DidInitialize_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(GpuHost_DidInitialize_Params_Data))) GpuHost_DidInitialize_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::gpu::mojom::internal::GpuInfo_Data> gpu_info;

        private:
            GpuHost_DidInitialize_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~GpuHost_DidInitialize_Params_Data() = delete;
        };
        static_assert(sizeof(GpuHost_DidInitialize_Params_Data) == 16,
            "Bad sizeof(GpuHost_DidInitialize_Params_Data)");
        constexpr uint32_t kGpuHost_DidCreateOffscreenContext_Name = 1;
        class GpuHost_DidCreateOffscreenContext_Params_Data {
        public:
            static GpuHost_DidCreateOffscreenContext_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(GpuHost_DidCreateOffscreenContext_Params_Data))) GpuHost_DidCreateOffscreenContext_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::url::mojom::internal::Url_Data> url;

        private:
            GpuHost_DidCreateOffscreenContext_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~GpuHost_DidCreateOffscreenContext_Params_Data() = delete;
        };
        static_assert(sizeof(GpuHost_DidCreateOffscreenContext_Params_Data) == 16,
            "Bad sizeof(GpuHost_DidCreateOffscreenContext_Params_Data)");
        constexpr uint32_t kGpuHost_DidDestroyOffscreenContext_Name = 2;
        class GpuHost_DidDestroyOffscreenContext_Params_Data {
        public:
            static GpuHost_DidDestroyOffscreenContext_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(GpuHost_DidDestroyOffscreenContext_Params_Data))) GpuHost_DidDestroyOffscreenContext_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::url::mojom::internal::Url_Data> url;

        private:
            GpuHost_DidDestroyOffscreenContext_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~GpuHost_DidDestroyOffscreenContext_Params_Data() = delete;
        };
        static_assert(sizeof(GpuHost_DidDestroyOffscreenContext_Params_Data) == 16,
            "Bad sizeof(GpuHost_DidDestroyOffscreenContext_Params_Data)");
        constexpr uint32_t kGpuHost_DidDestroyChannel_Name = 3;
        class GpuHost_DidDestroyChannel_Params_Data {
        public:
            static GpuHost_DidDestroyChannel_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(GpuHost_DidDestroyChannel_Params_Data))) GpuHost_DidDestroyChannel_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t client_id;
            uint8_t padfinal_[4];

        private:
            GpuHost_DidDestroyChannel_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~GpuHost_DidDestroyChannel_Params_Data() = delete;
        };
        static_assert(sizeof(GpuHost_DidDestroyChannel_Params_Data) == 16,
            "Bad sizeof(GpuHost_DidDestroyChannel_Params_Data)");
        constexpr uint32_t kGpuHost_DidLoseContext_Name = 4;
        class GpuHost_DidLoseContext_Params_Data {
        public:
            static GpuHost_DidLoseContext_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(GpuHost_DidLoseContext_Params_Data))) GpuHost_DidLoseContext_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t offscreen : 1;
            uint8_t pad0_[3];
            int32_t reason;
            mojo::internal::Pointer<::url::mojom::internal::Url_Data> active_url;

        private:
            GpuHost_DidLoseContext_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~GpuHost_DidLoseContext_Params_Data() = delete;
        };
        static_assert(sizeof(GpuHost_DidLoseContext_Params_Data) == 24,
            "Bad sizeof(GpuHost_DidLoseContext_Params_Data)");
        constexpr uint32_t kGpuHost_SetChildSurface_Name = 5;
        class GpuHost_SetChildSurface_Params_Data {
        public:
            static GpuHost_SetChildSurface_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(GpuHost_SetChildSurface_Params_Data))) GpuHost_SetChildSurface_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::gpu::mojom::internal::SurfaceHandle_Data> parent;
            mojo::internal::Pointer<::gpu::mojom::internal::SurfaceHandle_Data> child;

        private:
            GpuHost_SetChildSurface_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~GpuHost_SetChildSurface_Params_Data() = delete;
        };
        static_assert(sizeof(GpuHost_SetChildSurface_Params_Data) == 24,
            "Bad sizeof(GpuHost_SetChildSurface_Params_Data)");
        constexpr uint32_t kGpuHost_StoreShaderToDisk_Name = 6;
        class GpuHost_StoreShaderToDisk_Params_Data {
        public:
            static GpuHost_StoreShaderToDisk_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(GpuHost_StoreShaderToDisk_Params_Data))) GpuHost_StoreShaderToDisk_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t client_id;
            uint8_t pad0_[4];
            mojo::internal::Pointer<mojo::internal::String_Data> key;
            mojo::internal::Pointer<mojo::internal::String_Data> shader;

        private:
            GpuHost_StoreShaderToDisk_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~GpuHost_StoreShaderToDisk_Params_Data() = delete;
        };
        static_assert(sizeof(GpuHost_StoreShaderToDisk_Params_Data) == 32,
            "Bad sizeof(GpuHost_StoreShaderToDisk_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace ui

#endif // SERVICES_UI_GPU_INTERFACES_GPU_HOST_MOJOM_SHARED_INTERNAL_H_