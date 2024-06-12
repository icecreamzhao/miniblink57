// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_GPU_MOJOM_SHARED_INTERNAL_H_
#define SERVICES_UI_PUBLIC_INTERFACES_GPU_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "gpu/ipc/common/gpu_info.mojom-shared-internal.h"
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
        constexpr uint32_t kGpu_EstablishGpuChannel_Name = 0;
        class Gpu_EstablishGpuChannel_Params_Data {
        public:
            static Gpu_EstablishGpuChannel_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Gpu_EstablishGpuChannel_Params_Data))) Gpu_EstablishGpuChannel_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            Gpu_EstablishGpuChannel_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Gpu_EstablishGpuChannel_Params_Data() = delete;
        };
        static_assert(sizeof(Gpu_EstablishGpuChannel_Params_Data) == 8,
            "Bad sizeof(Gpu_EstablishGpuChannel_Params_Data)");
        class Gpu_EstablishGpuChannel_ResponseParams_Data {
        public:
            static Gpu_EstablishGpuChannel_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Gpu_EstablishGpuChannel_ResponseParams_Data))) Gpu_EstablishGpuChannel_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t client_id;
            mojo::internal::Handle_Data channel_handle;
            mojo::internal::Pointer<::gpu::mojom::internal::GpuInfo_Data> gpu_info;

        private:
            Gpu_EstablishGpuChannel_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Gpu_EstablishGpuChannel_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Gpu_EstablishGpuChannel_ResponseParams_Data) == 24,
            "Bad sizeof(Gpu_EstablishGpuChannel_ResponseParams_Data)");
        constexpr uint32_t kGpu_CreateGpuMemoryBuffer_Name = 1;
        class Gpu_CreateGpuMemoryBuffer_Params_Data {
        public:
            static Gpu_CreateGpuMemoryBuffer_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Gpu_CreateGpuMemoryBuffer_Params_Data))) Gpu_CreateGpuMemoryBuffer_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::gfx::mojom::internal::GpuMemoryBufferId_Data> id;
            mojo::internal::Pointer<::gfx::mojom::internal::Size_Data> size;
            int32_t format;
            int32_t usage;

        private:
            Gpu_CreateGpuMemoryBuffer_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Gpu_CreateGpuMemoryBuffer_Params_Data() = delete;
        };
        static_assert(sizeof(Gpu_CreateGpuMemoryBuffer_Params_Data) == 32,
            "Bad sizeof(Gpu_CreateGpuMemoryBuffer_Params_Data)");
        class Gpu_CreateGpuMemoryBuffer_ResponseParams_Data {
        public:
            static Gpu_CreateGpuMemoryBuffer_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Gpu_CreateGpuMemoryBuffer_ResponseParams_Data))) Gpu_CreateGpuMemoryBuffer_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::gfx::mojom::internal::GpuMemoryBufferHandle_Data> buffer_handle;

        private:
            Gpu_CreateGpuMemoryBuffer_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Gpu_CreateGpuMemoryBuffer_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(Gpu_CreateGpuMemoryBuffer_ResponseParams_Data) == 16,
            "Bad sizeof(Gpu_CreateGpuMemoryBuffer_ResponseParams_Data)");
        constexpr uint32_t kGpu_DestroyGpuMemoryBuffer_Name = 2;
        class Gpu_DestroyGpuMemoryBuffer_Params_Data {
        public:
            static Gpu_DestroyGpuMemoryBuffer_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Gpu_DestroyGpuMemoryBuffer_Params_Data))) Gpu_DestroyGpuMemoryBuffer_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::gfx::mojom::internal::GpuMemoryBufferId_Data> id;
            mojo::internal::Pointer<::gpu::mojom::internal::SyncToken_Data> sync_token;

        private:
            Gpu_DestroyGpuMemoryBuffer_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Gpu_DestroyGpuMemoryBuffer_Params_Data() = delete;
        };
        static_assert(sizeof(Gpu_DestroyGpuMemoryBuffer_Params_Data) == 24,
            "Bad sizeof(Gpu_DestroyGpuMemoryBuffer_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace ui

#endif // SERVICES_UI_PUBLIC_INTERFACES_GPU_MOJOM_SHARED_INTERNAL_H_