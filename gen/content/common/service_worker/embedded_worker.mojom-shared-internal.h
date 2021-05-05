// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_SERVICE_WORKER_EMBEDDED_WORKER_MOJOM_SHARED_INTERNAL_H_
#define CONTENT_COMMON_SERVICE_WORKER_EMBEDDED_WORKER_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "content/common/service_worker/service_worker_event_dispatcher.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "services/service_manager/public/interfaces/interface_provider.mojom-shared-internal.h"
#include "third_party/WebKit/public/web/console_message.mojom-shared-internal.h"
#include "url/mojo/url.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace content {
namespace mojom {
    namespace internal {
        using EmbeddedWorkerStartParams_Data = mojo::internal::NativeStruct_Data;

#pragma pack(push, 1)
        constexpr uint32_t kEmbeddedWorkerInstanceClient_StartWorker_Name = 0;
        class EmbeddedWorkerInstanceClient_StartWorker_Params_Data {
        public:
            static EmbeddedWorkerInstanceClient_StartWorker_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(EmbeddedWorkerInstanceClient_StartWorker_Params_Data))) EmbeddedWorkerInstanceClient_StartWorker_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::EmbeddedWorkerStartParams_Data> params;
            mojo::internal::Handle_Data dispatcher_request;
            uint8_t padfinal_[4];

        private:
            EmbeddedWorkerInstanceClient_StartWorker_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~EmbeddedWorkerInstanceClient_StartWorker_Params_Data() = delete;
        };
        static_assert(sizeof(EmbeddedWorkerInstanceClient_StartWorker_Params_Data) == 24,
            "Bad sizeof(EmbeddedWorkerInstanceClient_StartWorker_Params_Data)");
        constexpr uint32_t kEmbeddedWorkerInstanceClient_StopWorker_Name = 1;
        class EmbeddedWorkerInstanceClient_StopWorker_Params_Data {
        public:
            static EmbeddedWorkerInstanceClient_StopWorker_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(EmbeddedWorkerInstanceClient_StopWorker_Params_Data))) EmbeddedWorkerInstanceClient_StopWorker_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            EmbeddedWorkerInstanceClient_StopWorker_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~EmbeddedWorkerInstanceClient_StopWorker_Params_Data() = delete;
        };
        static_assert(sizeof(EmbeddedWorkerInstanceClient_StopWorker_Params_Data) == 8,
            "Bad sizeof(EmbeddedWorkerInstanceClient_StopWorker_Params_Data)");
        class EmbeddedWorkerInstanceClient_StopWorker_ResponseParams_Data {
        public:
            static EmbeddedWorkerInstanceClient_StopWorker_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(EmbeddedWorkerInstanceClient_StopWorker_ResponseParams_Data))) EmbeddedWorkerInstanceClient_StopWorker_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            EmbeddedWorkerInstanceClient_StopWorker_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~EmbeddedWorkerInstanceClient_StopWorker_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(EmbeddedWorkerInstanceClient_StopWorker_ResponseParams_Data) == 8,
            "Bad sizeof(EmbeddedWorkerInstanceClient_StopWorker_ResponseParams_Data)");
        constexpr uint32_t kEmbeddedWorkerInstanceClient_ResumeAfterDownload_Name = 2;
        class EmbeddedWorkerInstanceClient_ResumeAfterDownload_Params_Data {
        public:
            static EmbeddedWorkerInstanceClient_ResumeAfterDownload_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(EmbeddedWorkerInstanceClient_ResumeAfterDownload_Params_Data))) EmbeddedWorkerInstanceClient_ResumeAfterDownload_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            EmbeddedWorkerInstanceClient_ResumeAfterDownload_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~EmbeddedWorkerInstanceClient_ResumeAfterDownload_Params_Data() = delete;
        };
        static_assert(sizeof(EmbeddedWorkerInstanceClient_ResumeAfterDownload_Params_Data) == 8,
            "Bad sizeof(EmbeddedWorkerInstanceClient_ResumeAfterDownload_Params_Data)");
        constexpr uint32_t kEmbeddedWorkerInstanceClient_AddMessageToConsole_Name = 3;
        class EmbeddedWorkerInstanceClient_AddMessageToConsole_Params_Data {
        public:
            static EmbeddedWorkerInstanceClient_AddMessageToConsole_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(EmbeddedWorkerInstanceClient_AddMessageToConsole_Params_Data))) EmbeddedWorkerInstanceClient_AddMessageToConsole_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t level;
            uint8_t pad0_[4];
            mojo::internal::Pointer<mojo::internal::String_Data> message;

        private:
            EmbeddedWorkerInstanceClient_AddMessageToConsole_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~EmbeddedWorkerInstanceClient_AddMessageToConsole_Params_Data() = delete;
        };
        static_assert(sizeof(EmbeddedWorkerInstanceClient_AddMessageToConsole_Params_Data) == 24,
            "Bad sizeof(EmbeddedWorkerInstanceClient_AddMessageToConsole_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace content

#endif // CONTENT_COMMON_SERVICE_WORKER_EMBEDDED_WORKER_MOJOM_SHARED_INTERNAL_H_