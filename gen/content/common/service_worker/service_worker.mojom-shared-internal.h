// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_SERVICE_WORKER_SERVICE_WORKER_MOJOM_SHARED_INTERNAL_H_
#define CONTENT_COMMON_SERVICE_WORKER_SERVICE_WORKER_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "content/common/service_worker/service_worker_types.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace content {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kServiceWorkerDispatcherHost_OnProviderCreated_Name = 0;
        class ServiceWorkerDispatcherHost_OnProviderCreated_Params_Data {
        public:
            static ServiceWorkerDispatcherHost_OnProviderCreated_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ServiceWorkerDispatcherHost_OnProviderCreated_Params_Data))) ServiceWorkerDispatcherHost_OnProviderCreated_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t provider_id;
            int32_t route_id;
            int32_t provider_type;
            uint8_t is_parent_frame_secure : 1;
            uint8_t padfinal_[3];

        private:
            ServiceWorkerDispatcherHost_OnProviderCreated_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ServiceWorkerDispatcherHost_OnProviderCreated_Params_Data() = delete;
        };
        static_assert(sizeof(ServiceWorkerDispatcherHost_OnProviderCreated_Params_Data) == 24,
            "Bad sizeof(ServiceWorkerDispatcherHost_OnProviderCreated_Params_Data)");
        constexpr uint32_t kServiceWorkerDispatcherHost_OnProviderDestroyed_Name = 1;
        class ServiceWorkerDispatcherHost_OnProviderDestroyed_Params_Data {
        public:
            static ServiceWorkerDispatcherHost_OnProviderDestroyed_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ServiceWorkerDispatcherHost_OnProviderDestroyed_Params_Data))) ServiceWorkerDispatcherHost_OnProviderDestroyed_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t provider_id;
            uint8_t padfinal_[4];

        private:
            ServiceWorkerDispatcherHost_OnProviderDestroyed_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ServiceWorkerDispatcherHost_OnProviderDestroyed_Params_Data() = delete;
        };
        static_assert(sizeof(ServiceWorkerDispatcherHost_OnProviderDestroyed_Params_Data) == 16,
            "Bad sizeof(ServiceWorkerDispatcherHost_OnProviderDestroyed_Params_Data)");
        constexpr uint32_t kServiceWorkerDispatcherHost_OnSetHostedVersionId_Name = 2;
        class ServiceWorkerDispatcherHost_OnSetHostedVersionId_Params_Data {
        public:
            static ServiceWorkerDispatcherHost_OnSetHostedVersionId_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ServiceWorkerDispatcherHost_OnSetHostedVersionId_Params_Data))) ServiceWorkerDispatcherHost_OnSetHostedVersionId_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t provider_id;
            int32_t embedded_worker_id;
            int64_t version_id;

        private:
            ServiceWorkerDispatcherHost_OnSetHostedVersionId_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ServiceWorkerDispatcherHost_OnSetHostedVersionId_Params_Data() = delete;
        };
        static_assert(sizeof(ServiceWorkerDispatcherHost_OnSetHostedVersionId_Params_Data) == 24,
            "Bad sizeof(ServiceWorkerDispatcherHost_OnSetHostedVersionId_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace content

#endif // CONTENT_COMMON_SERVICE_WORKER_SERVICE_WORKER_MOJOM_SHARED_INTERNAL_H_