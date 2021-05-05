// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_URL_LOADER_FACTORY_MOJOM_SHARED_INTERNAL_H_
#define CONTENT_COMMON_URL_LOADER_FACTORY_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "content/common/url_loader.mojom-shared-internal.h"
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
        using URLSyncLoadResult_Data = mojo::internal::NativeStruct_Data;

#pragma pack(push, 1)
        constexpr uint32_t kURLLoaderFactory_CreateLoaderAndStart_Name = 0;
        class URLLoaderFactory_CreateLoaderAndStart_Params_Data {
        public:
            static URLLoaderFactory_CreateLoaderAndStart_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(URLLoaderFactory_CreateLoaderAndStart_Params_Data))) URLLoaderFactory_CreateLoaderAndStart_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::AssociatedInterfaceRequest_Data loader;
            int32_t routing_id;
            int32_t request_id;
            uint8_t pad2_[4];
            mojo::internal::Pointer<::content::mojom::internal::URLRequest_Data> request;
            mojo::internal::AssociatedInterface_Data client;

        private:
            URLLoaderFactory_CreateLoaderAndStart_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~URLLoaderFactory_CreateLoaderAndStart_Params_Data() = delete;
        };
        static_assert(sizeof(URLLoaderFactory_CreateLoaderAndStart_Params_Data) == 40,
            "Bad sizeof(URLLoaderFactory_CreateLoaderAndStart_Params_Data)");
        constexpr uint32_t kURLLoaderFactory_SyncLoad_Name = 1;
        class URLLoaderFactory_SyncLoad_Params_Data {
        public:
            static URLLoaderFactory_SyncLoad_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(URLLoaderFactory_SyncLoad_Params_Data))) URLLoaderFactory_SyncLoad_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t routing_id;
            int32_t request_id;
            mojo::internal::Pointer<::content::mojom::internal::URLRequest_Data> request;

        private:
            URLLoaderFactory_SyncLoad_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~URLLoaderFactory_SyncLoad_Params_Data() = delete;
        };
        static_assert(sizeof(URLLoaderFactory_SyncLoad_Params_Data) == 24,
            "Bad sizeof(URLLoaderFactory_SyncLoad_Params_Data)");
        class URLLoaderFactory_SyncLoad_ResponseParams_Data {
        public:
            static URLLoaderFactory_SyncLoad_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(URLLoaderFactory_SyncLoad_ResponseParams_Data))) URLLoaderFactory_SyncLoad_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::URLSyncLoadResult_Data> result;

        private:
            URLLoaderFactory_SyncLoad_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~URLLoaderFactory_SyncLoad_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(URLLoaderFactory_SyncLoad_ResponseParams_Data) == 16,
            "Bad sizeof(URLLoaderFactory_SyncLoad_ResponseParams_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace content

#endif // CONTENT_COMMON_URL_LOADER_FACTORY_MOJOM_SHARED_INTERNAL_H_