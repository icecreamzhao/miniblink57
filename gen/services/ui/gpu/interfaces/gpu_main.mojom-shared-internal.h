// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_GPU_INTERFACES_GPU_MAIN_MOJOM_SHARED_INTERNAL_H_
#define SERVICES_UI_GPU_INTERFACES_GPU_MAIN_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "cc/ipc/display_compositor.mojom-shared-internal.h"
#include "gpu/ipc/common/gpu_preferences.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "services/ui/gpu/interfaces/gpu_host.mojom-shared-internal.h"
#include "services/ui/gpu/interfaces/gpu_service.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace ui {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kGpuMain_CreateDisplayCompositor_Name = 0;
        class GpuMain_CreateDisplayCompositor_Params_Data {
        public:
            static GpuMain_CreateDisplayCompositor_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(GpuMain_CreateDisplayCompositor_Params_Data))) GpuMain_CreateDisplayCompositor_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data display_compositor;
            mojo::internal::Interface_Data display_compositor_client;
            uint8_t padfinal_[4];

        private:
            GpuMain_CreateDisplayCompositor_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~GpuMain_CreateDisplayCompositor_Params_Data() = delete;
        };
        static_assert(sizeof(GpuMain_CreateDisplayCompositor_Params_Data) == 24,
            "Bad sizeof(GpuMain_CreateDisplayCompositor_Params_Data)");
        constexpr uint32_t kGpuMain_CreateGpuService_Name = 1;
        class GpuMain_CreateGpuService_Params_Data {
        public:
            static GpuMain_CreateGpuService_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(GpuMain_CreateGpuService_Params_Data))) GpuMain_CreateGpuService_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data gpu_service;
            mojo::internal::Interface_Data gpu_host;
            uint8_t pad1_[4];
            mojo::internal::Pointer<::gpu::mojom::internal::GpuPreferences_Data> preferences;

        private:
            GpuMain_CreateGpuService_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~GpuMain_CreateGpuService_Params_Data() = delete;
        };
        static_assert(sizeof(GpuMain_CreateGpuService_Params_Data) == 32,
            "Bad sizeof(GpuMain_CreateGpuService_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace ui

#endif // SERVICES_UI_GPU_INTERFACES_GPU_MAIN_MOJOM_SHARED_INTERNAL_H_