// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_GPU_INTERFACES_GPU_SERVICE_MOJOM_SHARED_INTERNAL_H_
#define SERVICES_UI_GPU_INTERFACES_GPU_SERVICE_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "cc/ipc/display_compositor.mojom-shared-internal.h"
#include "gpu/ipc/common/gpu_info.mojom-shared-internal.h"
#include "gpu/ipc/common/surface_handle.mojom-shared-internal.h"
#include "gpu/ipc/common/sync_token.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared-internal.h"
#include "ui/gfx/mojo/buffer_types.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace ui {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kGpuService_EstablishGpuChannel_Name = 0;
        class GpuService_EstablishGpuChannel_Params_Data {
        public:
            static GpuService_EstablishGpuChannel_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(GpuService_EstablishGpuChannel_Params_Data))) GpuService_EstablishGpuChannel_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t client_id;
            uint8_t is_gpu_host : 1;
            uint8_t pad1_[3];
            uint64_t client_tracing_id;

        private:
            GpuService_EstablishGpuChannel_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~GpuService_EstablishGpuChannel_Params_Data() = delete;
        };
        static_assert(sizeof(GpuService_EstablishGpuChannel_Params_Data) == 24,
            "Bad sizeof(GpuService_EstablishGpuChannel_Params_Data)");
        class GpuService_EstablishGpuChannel_ResponseParams_Data {
        public:
            static GpuService_EstablishGpuChannel_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(GpuService_EstablishGpuChannel_ResponseParams_Data))) GpuService_EstablishGpuChannel_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data channel_handle;
            uint8_t padfinal_[4];

        private:
            GpuService_EstablishGpuChannel_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~GpuService_EstablishGpuChannel_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(GpuService_EstablishGpuChannel_ResponseParams_Data) == 16,
            "Bad sizeof(GpuService_EstablishGpuChannel_ResponseParams_Data)");
        constexpr uint32_t kGpuService_CreateGpuMemoryBuffer_Name = 1;
        class GpuService_CreateGpuMemoryBuffer_Params_Data {
        public:
            static GpuService_CreateGpuMemoryBuffer_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(GpuService_CreateGpuMemoryBuffer_Params_Data))) GpuService_CreateGpuMemoryBuffer_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::gfx::mojom::internal::GpuMemoryBufferId_Data> id;
            mojo::internal::Pointer<::gfx::mojom::internal::Size_Data> size;
            int32_t format;
            int32_t usage;
            int32_t client_id;
            uint8_t pad4_[4];
            mojo::internal::Pointer<::gpu::mojom::internal::SurfaceHandle_Data> surface_handle;

        private:
            GpuService_CreateGpuMemoryBuffer_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~GpuService_CreateGpuMemoryBuffer_Params_Data() = delete;
        };
        static_assert(sizeof(GpuService_CreateGpuMemoryBuffer_Params_Data) == 48,
            "Bad sizeof(GpuService_CreateGpuMemoryBuffer_Params_Data)");
        class GpuService_CreateGpuMemoryBuffer_ResponseParams_Data {
        public:
            static GpuService_CreateGpuMemoryBuffer_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(GpuService_CreateGpuMemoryBuffer_ResponseParams_Data))) GpuService_CreateGpuMemoryBuffer_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::gfx::mojom::internal::GpuMemoryBufferHandle_Data> buffer_handle;

        private:
            GpuService_CreateGpuMemoryBuffer_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~GpuService_CreateGpuMemoryBuffer_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(GpuService_CreateGpuMemoryBuffer_ResponseParams_Data) == 16,
            "Bad sizeof(GpuService_CreateGpuMemoryBuffer_ResponseParams_Data)");
        constexpr uint32_t kGpuService_DestroyGpuMemoryBuffer_Name = 2;
        class GpuService_DestroyGpuMemoryBuffer_Params_Data {
        public:
            static GpuService_DestroyGpuMemoryBuffer_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(GpuService_DestroyGpuMemoryBuffer_Params_Data))) GpuService_DestroyGpuMemoryBuffer_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::gfx::mojom::internal::GpuMemoryBufferId_Data> id;
            int32_t client_id;
            uint8_t pad1_[4];
            mojo::internal::Pointer<::gpu::mojom::internal::SyncToken_Data> sync_token;

        private:
            GpuService_DestroyGpuMemoryBuffer_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~GpuService_DestroyGpuMemoryBuffer_Params_Data() = delete;
        };
        static_assert(sizeof(GpuService_DestroyGpuMemoryBuffer_Params_Data) == 32,
            "Bad sizeof(GpuService_DestroyGpuMemoryBuffer_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace ui

#endif // SERVICES_UI_GPU_INTERFACES_GPU_SERVICE_MOJOM_SHARED_INTERNAL_H_