// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_SERVICE_WORKER_SERVICE_WORKER_EVENT_DISPATCHER_MOJOM_SHARED_INTERNAL_H_
#define CONTENT_COMMON_SERVICE_WORKER_SERVICE_WORKER_EVENT_DISPATCHER_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "components/payments/payment_app.mojom-shared-internal.h"
#include "content/common/url_loader.mojom-shared-internal.h"
#include "mojo/common/string16.mojom-shared-internal.h"
#include "mojo/common/time.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "third_party/WebKit/public/platform/modules/background_sync/background_sync.mojom-shared-internal.h"
#include "third_party/WebKit/public/platform/modules/serviceworker/service_worker_event_status.mojom-shared-internal.h"
#include "url/mojo/origin.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace content {
namespace mojom {
    namespace internal {
        using PushEventPayload_Data = mojo::internal::NativeStruct_Data;
        using ServiceWorkerFetchRequest_Data = mojo::internal::NativeStruct_Data;
        using ExtendableMessageEventSource_Data = mojo::internal::NativeStruct_Data;
        class FetchEventPreloadHandle_Data;
        class ExtendableMessageEvent_Data;

#pragma pack(push, 1)
        class FetchEventPreloadHandle_Data {
        public:
            static FetchEventPreloadHandle_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(FetchEventPreloadHandle_Data))) FetchEventPreloadHandle_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Interface_Data url_loader;
            mojo::internal::Handle_Data url_loader_client_request;
            uint8_t padfinal_[4];

        private:
            FetchEventPreloadHandle_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~FetchEventPreloadHandle_Data() = delete;
        };
        static_assert(sizeof(FetchEventPreloadHandle_Data) == 24,
            "Bad sizeof(FetchEventPreloadHandle_Data)");
        class ExtendableMessageEvent_Data {
        public:
            static ExtendableMessageEvent_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ExtendableMessageEvent_Data))) ExtendableMessageEvent_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::mojo::common::mojom::internal::String16_Data> message;
            mojo::internal::Pointer<::url::mojom::internal::Origin_Data> source_origin;
            mojo::internal::Pointer<mojo::internal::Array_Data<int32_t>> message_ports;
            mojo::internal::Pointer<mojo::internal::Array_Data<int32_t>> new_routing_ids;
            mojo::internal::Pointer<internal::ExtendableMessageEventSource_Data> source;

        private:
            ExtendableMessageEvent_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ExtendableMessageEvent_Data() = delete;
        };
        static_assert(sizeof(ExtendableMessageEvent_Data) == 48,
            "Bad sizeof(ExtendableMessageEvent_Data)");
        constexpr uint32_t kServiceWorkerEventDispatcher_DispatchFetchEvent_Name = 0;
        class ServiceWorkerEventDispatcher_DispatchFetchEvent_Params_Data {
        public:
            static ServiceWorkerEventDispatcher_DispatchFetchEvent_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ServiceWorkerEventDispatcher_DispatchFetchEvent_Params_Data))) ServiceWorkerEventDispatcher_DispatchFetchEvent_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t fetch_event_id;
            uint8_t pad0_[4];
            mojo::internal::Pointer<internal::ServiceWorkerFetchRequest_Data> request;
            mojo::internal::Pointer<internal::FetchEventPreloadHandle_Data> preload_handle;

        private:
            ServiceWorkerEventDispatcher_DispatchFetchEvent_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ServiceWorkerEventDispatcher_DispatchFetchEvent_Params_Data() = delete;
        };
        static_assert(sizeof(ServiceWorkerEventDispatcher_DispatchFetchEvent_Params_Data) == 32,
            "Bad sizeof(ServiceWorkerEventDispatcher_DispatchFetchEvent_Params_Data)");
        class ServiceWorkerEventDispatcher_DispatchFetchEvent_ResponseParams_Data {
        public:
            static ServiceWorkerEventDispatcher_DispatchFetchEvent_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ServiceWorkerEventDispatcher_DispatchFetchEvent_ResponseParams_Data))) ServiceWorkerEventDispatcher_DispatchFetchEvent_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t status;
            uint8_t pad0_[4];
            mojo::internal::Pointer<::mojo::common::mojom::internal::Time_Data> dispatch_event_time;

        private:
            ServiceWorkerEventDispatcher_DispatchFetchEvent_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ServiceWorkerEventDispatcher_DispatchFetchEvent_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(ServiceWorkerEventDispatcher_DispatchFetchEvent_ResponseParams_Data) == 24,
            "Bad sizeof(ServiceWorkerEventDispatcher_DispatchFetchEvent_ResponseParams_Data)");
        constexpr uint32_t kServiceWorkerEventDispatcher_DispatchPushEvent_Name = 1;
        class ServiceWorkerEventDispatcher_DispatchPushEvent_Params_Data {
        public:
            static ServiceWorkerEventDispatcher_DispatchPushEvent_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ServiceWorkerEventDispatcher_DispatchPushEvent_Params_Data))) ServiceWorkerEventDispatcher_DispatchPushEvent_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::PushEventPayload_Data> payload;

        private:
            ServiceWorkerEventDispatcher_DispatchPushEvent_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ServiceWorkerEventDispatcher_DispatchPushEvent_Params_Data() = delete;
        };
        static_assert(sizeof(ServiceWorkerEventDispatcher_DispatchPushEvent_Params_Data) == 16,
            "Bad sizeof(ServiceWorkerEventDispatcher_DispatchPushEvent_Params_Data)");
        class ServiceWorkerEventDispatcher_DispatchPushEvent_ResponseParams_Data {
        public:
            static ServiceWorkerEventDispatcher_DispatchPushEvent_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ServiceWorkerEventDispatcher_DispatchPushEvent_ResponseParams_Data))) ServiceWorkerEventDispatcher_DispatchPushEvent_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t status;
            uint8_t pad0_[4];
            mojo::internal::Pointer<::mojo::common::mojom::internal::Time_Data> dispatch_event_time;

        private:
            ServiceWorkerEventDispatcher_DispatchPushEvent_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ServiceWorkerEventDispatcher_DispatchPushEvent_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(ServiceWorkerEventDispatcher_DispatchPushEvent_ResponseParams_Data) == 24,
            "Bad sizeof(ServiceWorkerEventDispatcher_DispatchPushEvent_ResponseParams_Data)");
        constexpr uint32_t kServiceWorkerEventDispatcher_DispatchSyncEvent_Name = 2;
        class ServiceWorkerEventDispatcher_DispatchSyncEvent_Params_Data {
        public:
            static ServiceWorkerEventDispatcher_DispatchSyncEvent_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ServiceWorkerEventDispatcher_DispatchSyncEvent_Params_Data))) ServiceWorkerEventDispatcher_DispatchSyncEvent_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> tag;
            int32_t last_chance;
            uint8_t padfinal_[4];

        private:
            ServiceWorkerEventDispatcher_DispatchSyncEvent_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ServiceWorkerEventDispatcher_DispatchSyncEvent_Params_Data() = delete;
        };
        static_assert(sizeof(ServiceWorkerEventDispatcher_DispatchSyncEvent_Params_Data) == 24,
            "Bad sizeof(ServiceWorkerEventDispatcher_DispatchSyncEvent_Params_Data)");
        class ServiceWorkerEventDispatcher_DispatchSyncEvent_ResponseParams_Data {
        public:
            static ServiceWorkerEventDispatcher_DispatchSyncEvent_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ServiceWorkerEventDispatcher_DispatchSyncEvent_ResponseParams_Data))) ServiceWorkerEventDispatcher_DispatchSyncEvent_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t status;
            uint8_t pad0_[4];
            mojo::internal::Pointer<::mojo::common::mojom::internal::Time_Data> dispatch_event_time;

        private:
            ServiceWorkerEventDispatcher_DispatchSyncEvent_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ServiceWorkerEventDispatcher_DispatchSyncEvent_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(ServiceWorkerEventDispatcher_DispatchSyncEvent_ResponseParams_Data) == 24,
            "Bad sizeof(ServiceWorkerEventDispatcher_DispatchSyncEvent_ResponseParams_Data)");
        constexpr uint32_t kServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_Name = 3;
        class ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_Params_Data {
        public:
            static ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_Params_Data))) ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::payments::mojom::internal::PaymentAppRequestData_Data> data;

        private:
            ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_Params_Data() = delete;
        };
        static_assert(sizeof(ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_Params_Data) == 16,
            "Bad sizeof(ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_Params_Data)");
        class ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ResponseParams_Data {
        public:
            static ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ResponseParams_Data))) ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t status;
            uint8_t pad0_[4];
            mojo::internal::Pointer<::mojo::common::mojom::internal::Time_Data> dispatch_event_time;

        private:
            ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ResponseParams_Data) == 24,
            "Bad sizeof(ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ResponseParams_Data)");
        constexpr uint32_t kServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_Name = 4;
        class ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_Params_Data {
        public:
            static ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_Params_Data))) ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::ExtendableMessageEvent_Data> event;

        private:
            ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_Params_Data() = delete;
        };
        static_assert(sizeof(ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_Params_Data) == 16,
            "Bad sizeof(ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_Params_Data)");
        class ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ResponseParams_Data {
        public:
            static ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ResponseParams_Data))) ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t status;
            uint8_t pad0_[4];
            mojo::internal::Pointer<::mojo::common::mojom::internal::Time_Data> dispatch_event_time;

        private:
            ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ResponseParams_Data) == 24,
            "Bad sizeof(ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ResponseParams_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace content

#endif // CONTENT_COMMON_SERVICE_WORKER_SERVICE_WORKER_EVENT_DISPATCHER_MOJOM_SHARED_INTERNAL_H_