// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_SERVICE_WORKER_SERVICE_WORKER_EVENT_DISPATCHER_MOJOM_SHARED_H_
#define CONTENT_COMMON_SERVICE_WORKER_SERVICE_WORKER_EVENT_DISPATCHER_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "components/payments/payment_app.mojom-shared.h"
#include "content/common/service_worker/service_worker_event_dispatcher.mojom-shared-internal.h"
#include "content/common/url_loader.mojom-shared.h"
#include "mojo/common/string16.mojom-shared.h"
#include "mojo/common/time.mojom-shared.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "third_party/WebKit/public/platform/modules/background_sync/background_sync.mojom-shared.h"
#include "third_party/WebKit/public/platform/modules/serviceworker/service_worker_event_status.mojom-shared.h"
#include "url/mojo/origin.mojom-shared.h"

namespace content {
namespace mojom {
    using PushEventPayloadDataView = mojo::NativeStructDataView;

    using ServiceWorkerFetchRequestDataView = mojo::NativeStructDataView;

    using ExtendableMessageEventSourceDataView = mojo::NativeStructDataView;

    class FetchEventPreloadHandleDataView;

    class ExtendableMessageEventDataView;

} // namespace mojom
} // namespace content

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::content::mojom::FetchEventPreloadHandleDataView> {
        using Data = ::content::mojom::internal::FetchEventPreloadHandle_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::content::mojom::ExtendableMessageEventDataView> {
        using Data = ::content::mojom::internal::ExtendableMessageEvent_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace content {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class ServiceWorkerEventDispatcherInterfaceBase {
    };

    using ServiceWorkerEventDispatcherPtrDataView = mojo::InterfacePtrDataView<ServiceWorkerEventDispatcherInterfaceBase>;
    using ServiceWorkerEventDispatcherRequestDataView = mojo::InterfaceRequestDataView<ServiceWorkerEventDispatcherInterfaceBase>;
    using ServiceWorkerEventDispatcherAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<ServiceWorkerEventDispatcherInterfaceBase>;
    using ServiceWorkerEventDispatcherAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<ServiceWorkerEventDispatcherInterfaceBase>;
    class FetchEventPreloadHandleDataView {
    public:
        FetchEventPreloadHandleDataView() { }

        FetchEventPreloadHandleDataView(
            internal::FetchEventPreloadHandle_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeUrlLoader()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::content::mojom::URLLoaderPtrDataView>(
                &data_->url_loader, &result, context_);
            DCHECK(ret);
            return result;
        }
        template <typename UserType>
        UserType TakeUrlLoaderClientRequest()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::content::mojom::URLLoaderClientRequestDataView>(
                &data_->url_loader_client_request, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::FetchEventPreloadHandle_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class ExtendableMessageEventDataView {
    public:
        ExtendableMessageEventDataView() { }

        ExtendableMessageEventDataView(
            internal::ExtendableMessageEvent_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetMessageDataView(
            ::mojo::common::mojom::String16DataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMessage(UserType* output)
        {
            auto* pointer = data_->message.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::String16DataView>(
                pointer, output, context_);
        }
        inline void GetSourceOriginDataView(
            ::url::mojom::OriginDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSourceOrigin(UserType* output)
        {
            auto* pointer = data_->source_origin.Get();
            return mojo::internal::Deserialize<::url::mojom::OriginDataView>(
                pointer, output, context_);
        }
        inline void GetMessagePortsDataView(
            mojo::ArrayDataView<int32_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMessagePorts(UserType* output)
        {
            auto* pointer = data_->message_ports.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<int32_t>>(
                pointer, output, context_);
        }
        inline void GetNewRoutingIdsDataView(
            mojo::ArrayDataView<int32_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadNewRoutingIds(UserType* output)
        {
            auto* pointer = data_->new_routing_ids.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<int32_t>>(
                pointer, output, context_);
        }
        inline void GetSourceDataView(
            ExtendableMessageEventSourceDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSource(UserType* output)
        {
            auto* pointer = data_->source.Get();
            return mojo::internal::Deserialize<::content::mojom::ExtendableMessageEventSourceDataView>(
                pointer, output, context_);
        }

    private:
        internal::ExtendableMessageEvent_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class ServiceWorkerEventDispatcher_DispatchFetchEvent_ParamsDataView {
    public:
        ServiceWorkerEventDispatcher_DispatchFetchEvent_ParamsDataView() { }

        ServiceWorkerEventDispatcher_DispatchFetchEvent_ParamsDataView(
            internal::ServiceWorkerEventDispatcher_DispatchFetchEvent_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        int32_t fetch_event_id() const
        {
            return data_->fetch_event_id;
        }
        inline void GetRequestDataView(
            ServiceWorkerFetchRequestDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadRequest(UserType* output)
        {
            auto* pointer = data_->request.Get();
            return mojo::internal::Deserialize<::content::mojom::ServiceWorkerFetchRequestDataView>(
                pointer, output, context_);
        }
        inline void GetPreloadHandleDataView(
            FetchEventPreloadHandleDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPreloadHandle(UserType* output)
        {
            auto* pointer = data_->preload_handle.Get();
            return mojo::internal::Deserialize<::content::mojom::FetchEventPreloadHandleDataView>(
                pointer, output, context_);
        }

    private:
        internal::ServiceWorkerEventDispatcher_DispatchFetchEvent_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class ServiceWorkerEventDispatcher_DispatchFetchEvent_ResponseParamsDataView {
    public:
        ServiceWorkerEventDispatcher_DispatchFetchEvent_ResponseParamsDataView() { }

        ServiceWorkerEventDispatcher_DispatchFetchEvent_ResponseParamsDataView(
            internal::ServiceWorkerEventDispatcher_DispatchFetchEvent_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStatus(UserType* output) const
        {
            auto data_value = data_->status;
            return mojo::internal::Deserialize<::blink::mojom::ServiceWorkerEventStatus>(
                data_value, output);
        }

        ::blink::mojom::ServiceWorkerEventStatus status() const
        {
            return static_cast<::blink::mojom::ServiceWorkerEventStatus>(data_->status);
        }
        inline void GetDispatchEventTimeDataView(
            ::mojo::common::mojom::TimeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDispatchEventTime(UserType* output)
        {
            auto* pointer = data_->dispatch_event_time.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::TimeDataView>(
                pointer, output, context_);
        }

    private:
        internal::ServiceWorkerEventDispatcher_DispatchFetchEvent_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class ServiceWorkerEventDispatcher_DispatchPushEvent_ParamsDataView {
    public:
        ServiceWorkerEventDispatcher_DispatchPushEvent_ParamsDataView() { }

        ServiceWorkerEventDispatcher_DispatchPushEvent_ParamsDataView(
            internal::ServiceWorkerEventDispatcher_DispatchPushEvent_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetPayloadDataView(
            PushEventPayloadDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPayload(UserType* output)
        {
            auto* pointer = data_->payload.Get();
            return mojo::internal::Deserialize<::content::mojom::PushEventPayloadDataView>(
                pointer, output, context_);
        }

    private:
        internal::ServiceWorkerEventDispatcher_DispatchPushEvent_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class ServiceWorkerEventDispatcher_DispatchPushEvent_ResponseParamsDataView {
    public:
        ServiceWorkerEventDispatcher_DispatchPushEvent_ResponseParamsDataView() { }

        ServiceWorkerEventDispatcher_DispatchPushEvent_ResponseParamsDataView(
            internal::ServiceWorkerEventDispatcher_DispatchPushEvent_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStatus(UserType* output) const
        {
            auto data_value = data_->status;
            return mojo::internal::Deserialize<::blink::mojom::ServiceWorkerEventStatus>(
                data_value, output);
        }

        ::blink::mojom::ServiceWorkerEventStatus status() const
        {
            return static_cast<::blink::mojom::ServiceWorkerEventStatus>(data_->status);
        }
        inline void GetDispatchEventTimeDataView(
            ::mojo::common::mojom::TimeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDispatchEventTime(UserType* output)
        {
            auto* pointer = data_->dispatch_event_time.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::TimeDataView>(
                pointer, output, context_);
        }

    private:
        internal::ServiceWorkerEventDispatcher_DispatchPushEvent_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class ServiceWorkerEventDispatcher_DispatchSyncEvent_ParamsDataView {
    public:
        ServiceWorkerEventDispatcher_DispatchSyncEvent_ParamsDataView() { }

        ServiceWorkerEventDispatcher_DispatchSyncEvent_ParamsDataView(
            internal::ServiceWorkerEventDispatcher_DispatchSyncEvent_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetTagDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTag(UserType* output)
        {
            auto* pointer = data_->tag.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadLastChance(UserType* output) const
        {
            auto data_value = data_->last_chance;
            return mojo::internal::Deserialize<::blink::mojom::BackgroundSyncEventLastChance>(
                data_value, output);
        }

        ::blink::mojom::BackgroundSyncEventLastChance last_chance() const
        {
            return static_cast<::blink::mojom::BackgroundSyncEventLastChance>(data_->last_chance);
        }

    private:
        internal::ServiceWorkerEventDispatcher_DispatchSyncEvent_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class ServiceWorkerEventDispatcher_DispatchSyncEvent_ResponseParamsDataView {
    public:
        ServiceWorkerEventDispatcher_DispatchSyncEvent_ResponseParamsDataView() { }

        ServiceWorkerEventDispatcher_DispatchSyncEvent_ResponseParamsDataView(
            internal::ServiceWorkerEventDispatcher_DispatchSyncEvent_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStatus(UserType* output) const
        {
            auto data_value = data_->status;
            return mojo::internal::Deserialize<::blink::mojom::ServiceWorkerEventStatus>(
                data_value, output);
        }

        ::blink::mojom::ServiceWorkerEventStatus status() const
        {
            return static_cast<::blink::mojom::ServiceWorkerEventStatus>(data_->status);
        }
        inline void GetDispatchEventTimeDataView(
            ::mojo::common::mojom::TimeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDispatchEventTime(UserType* output)
        {
            auto* pointer = data_->dispatch_event_time.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::TimeDataView>(
                pointer, output, context_);
        }

    private:
        internal::ServiceWorkerEventDispatcher_DispatchSyncEvent_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ParamsDataView {
    public:
        ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ParamsDataView() { }

        ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ParamsDataView(
            internal::ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetDataDataView(
            ::payments::mojom::PaymentAppRequestDataDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadData(UserType* output)
        {
            auto* pointer = data_->data.Get();
            return mojo::internal::Deserialize<::payments::mojom::PaymentAppRequestDataDataView>(
                pointer, output, context_);
        }

    private:
        internal::ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ResponseParamsDataView {
    public:
        ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ResponseParamsDataView() { }

        ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ResponseParamsDataView(
            internal::ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStatus(UserType* output) const
        {
            auto data_value = data_->status;
            return mojo::internal::Deserialize<::blink::mojom::ServiceWorkerEventStatus>(
                data_value, output);
        }

        ::blink::mojom::ServiceWorkerEventStatus status() const
        {
            return static_cast<::blink::mojom::ServiceWorkerEventStatus>(data_->status);
        }
        inline void GetDispatchEventTimeDataView(
            ::mojo::common::mojom::TimeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDispatchEventTime(UserType* output)
        {
            auto* pointer = data_->dispatch_event_time.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::TimeDataView>(
                pointer, output, context_);
        }

    private:
        internal::ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ParamsDataView {
    public:
        ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ParamsDataView() { }

        ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ParamsDataView(
            internal::ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetEventDataView(
            ExtendableMessageEventDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadEvent(UserType* output)
        {
            auto* pointer = data_->event.Get();
            return mojo::internal::Deserialize<::content::mojom::ExtendableMessageEventDataView>(
                pointer, output, context_);
        }

    private:
        internal::ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ResponseParamsDataView {
    public:
        ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ResponseParamsDataView() { }

        ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ResponseParamsDataView(
            internal::ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStatus(UserType* output) const
        {
            auto data_value = data_->status;
            return mojo::internal::Deserialize<::blink::mojom::ServiceWorkerEventStatus>(
                data_value, output);
        }

        ::blink::mojom::ServiceWorkerEventStatus status() const
        {
            return static_cast<::blink::mojom::ServiceWorkerEventStatus>(data_->status);
        }
        inline void GetDispatchEventTimeDataView(
            ::mojo::common::mojom::TimeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDispatchEventTime(UserType* output)
        {
            auto* pointer = data_->dispatch_event_time.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::TimeDataView>(
                pointer, output, context_);
        }

    private:
        internal::ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace content

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::content::mojom::FetchEventPreloadHandleDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::content::mojom::FetchEventPreloadHandleDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::content::mojom::internal::FetchEventPreloadHandle_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::content::mojom::internal::FetchEventPreloadHandle_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::content::mojom::internal::FetchEventPreloadHandle_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::url_loader, input, custom_context)) in_url_loader = CallWithContext(Traits::url_loader, input, custom_context);
            mojo::internal::Serialize<::content::mojom::URLLoaderPtrDataView>(
                in_url_loader, &result->url_loader, context);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                !mojo::internal::IsHandleOrInterfaceValid(result->url_loader),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
                "invalid url_loader in FetchEventPreloadHandle struct");
            decltype(CallWithContext(Traits::url_loader_client_request, input, custom_context)) in_url_loader_client_request = CallWithContext(Traits::url_loader_client_request, input, custom_context);
            mojo::internal::Serialize<::content::mojom::URLLoaderClientRequestDataView>(
                in_url_loader_client_request, &result->url_loader_client_request, context);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                !mojo::internal::IsHandleOrInterfaceValid(result->url_loader_client_request),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
                "invalid url_loader_client_request in FetchEventPreloadHandle struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::content::mojom::internal::FetchEventPreloadHandle_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::content::mojom::FetchEventPreloadHandleDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::content::mojom::ExtendableMessageEventDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::content::mojom::ExtendableMessageEventDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::content::mojom::internal::ExtendableMessageEvent_Data);
            decltype(CallWithContext(Traits::message, input, custom_context)) in_message = CallWithContext(Traits::message, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::String16DataView>(
                in_message, context);
            decltype(CallWithContext(Traits::source_origin, input, custom_context)) in_source_origin = CallWithContext(Traits::source_origin, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::url::mojom::OriginDataView>(
                in_source_origin, context);
            decltype(CallWithContext(Traits::message_ports, input, custom_context)) in_message_ports = CallWithContext(Traits::message_ports, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<int32_t>>(
                in_message_ports, context);
            decltype(CallWithContext(Traits::new_routing_ids, input, custom_context)) in_new_routing_ids = CallWithContext(Traits::new_routing_ids, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<int32_t>>(
                in_new_routing_ids, context);
            decltype(CallWithContext(Traits::source, input, custom_context)) in_source = CallWithContext(Traits::source, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::content::mojom::ExtendableMessageEventSourceDataView>(
                in_source, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::content::mojom::internal::ExtendableMessageEvent_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::content::mojom::internal::ExtendableMessageEvent_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::message, input, custom_context)) in_message = CallWithContext(Traits::message, input, custom_context);
            typename decltype(result->message)::BaseType* message_ptr;
            mojo::internal::Serialize<::mojo::common::mojom::String16DataView>(
                in_message, buffer, &message_ptr, context);
            result->message.Set(message_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->message.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null message in ExtendableMessageEvent struct");
            decltype(CallWithContext(Traits::source_origin, input, custom_context)) in_source_origin = CallWithContext(Traits::source_origin, input, custom_context);
            typename decltype(result->source_origin)::BaseType* source_origin_ptr;
            mojo::internal::Serialize<::url::mojom::OriginDataView>(
                in_source_origin, buffer, &source_origin_ptr, context);
            result->source_origin.Set(source_origin_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->source_origin.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null source_origin in ExtendableMessageEvent struct");
            decltype(CallWithContext(Traits::message_ports, input, custom_context)) in_message_ports = CallWithContext(Traits::message_ports, input, custom_context);
            typename decltype(result->message_ports)::BaseType* message_ports_ptr;
            const mojo::internal::ContainerValidateParams message_ports_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<int32_t>>(
                in_message_ports, buffer, &message_ports_ptr, &message_ports_validate_params,
                context);
            result->message_ports.Set(message_ports_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->message_ports.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null message_ports in ExtendableMessageEvent struct");
            decltype(CallWithContext(Traits::new_routing_ids, input, custom_context)) in_new_routing_ids = CallWithContext(Traits::new_routing_ids, input, custom_context);
            typename decltype(result->new_routing_ids)::BaseType* new_routing_ids_ptr;
            const mojo::internal::ContainerValidateParams new_routing_ids_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<int32_t>>(
                in_new_routing_ids, buffer, &new_routing_ids_ptr, &new_routing_ids_validate_params,
                context);
            result->new_routing_ids.Set(new_routing_ids_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->new_routing_ids.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null new_routing_ids in ExtendableMessageEvent struct");
            decltype(CallWithContext(Traits::source, input, custom_context)) in_source = CallWithContext(Traits::source, input, custom_context);
            typename decltype(result->source)::BaseType* source_ptr;
            mojo::internal::Serialize<::content::mojom::ExtendableMessageEventSourceDataView>(
                in_source, buffer, &source_ptr, context);
            result->source.Set(source_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->source.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null source in ExtendableMessageEvent struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::content::mojom::internal::ExtendableMessageEvent_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::content::mojom::ExtendableMessageEventDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace content {
namespace mojom {

    inline void ExtendableMessageEventDataView::GetMessageDataView(
        ::mojo::common::mojom::String16DataView* output)
    {
        auto pointer = data_->message.Get();
        *output = ::mojo::common::mojom::String16DataView(pointer, context_);
    }
    inline void ExtendableMessageEventDataView::GetSourceOriginDataView(
        ::url::mojom::OriginDataView* output)
    {
        auto pointer = data_->source_origin.Get();
        *output = ::url::mojom::OriginDataView(pointer, context_);
    }
    inline void ExtendableMessageEventDataView::GetMessagePortsDataView(
        mojo::ArrayDataView<int32_t>* output)
    {
        auto pointer = data_->message_ports.Get();
        *output = mojo::ArrayDataView<int32_t>(pointer, context_);
    }
    inline void ExtendableMessageEventDataView::GetNewRoutingIdsDataView(
        mojo::ArrayDataView<int32_t>* output)
    {
        auto pointer = data_->new_routing_ids.Get();
        *output = mojo::ArrayDataView<int32_t>(pointer, context_);
    }
    inline void ExtendableMessageEventDataView::GetSourceDataView(
        ExtendableMessageEventSourceDataView* output)
    {
        auto pointer = data_->source.Get();
        *output = ExtendableMessageEventSourceDataView(pointer, context_);
    }

    inline void ServiceWorkerEventDispatcher_DispatchFetchEvent_ParamsDataView::GetRequestDataView(
        ServiceWorkerFetchRequestDataView* output)
    {
        auto pointer = data_->request.Get();
        *output = ServiceWorkerFetchRequestDataView(pointer, context_);
    }
    inline void ServiceWorkerEventDispatcher_DispatchFetchEvent_ParamsDataView::GetPreloadHandleDataView(
        FetchEventPreloadHandleDataView* output)
    {
        auto pointer = data_->preload_handle.Get();
        *output = FetchEventPreloadHandleDataView(pointer, context_);
    }

    inline void ServiceWorkerEventDispatcher_DispatchFetchEvent_ResponseParamsDataView::GetDispatchEventTimeDataView(
        ::mojo::common::mojom::TimeDataView* output)
    {
        auto pointer = data_->dispatch_event_time.Get();
        *output = ::mojo::common::mojom::TimeDataView(pointer, context_);
    }

    inline void ServiceWorkerEventDispatcher_DispatchPushEvent_ParamsDataView::GetPayloadDataView(
        PushEventPayloadDataView* output)
    {
        auto pointer = data_->payload.Get();
        *output = PushEventPayloadDataView(pointer, context_);
    }

    inline void ServiceWorkerEventDispatcher_DispatchPushEvent_ResponseParamsDataView::GetDispatchEventTimeDataView(
        ::mojo::common::mojom::TimeDataView* output)
    {
        auto pointer = data_->dispatch_event_time.Get();
        *output = ::mojo::common::mojom::TimeDataView(pointer, context_);
    }

    inline void ServiceWorkerEventDispatcher_DispatchSyncEvent_ParamsDataView::GetTagDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->tag.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void ServiceWorkerEventDispatcher_DispatchSyncEvent_ResponseParamsDataView::GetDispatchEventTimeDataView(
        ::mojo::common::mojom::TimeDataView* output)
    {
        auto pointer = data_->dispatch_event_time.Get();
        *output = ::mojo::common::mojom::TimeDataView(pointer, context_);
    }

    inline void ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ParamsDataView::GetDataDataView(
        ::payments::mojom::PaymentAppRequestDataDataView* output)
    {
        auto pointer = data_->data.Get();
        *output = ::payments::mojom::PaymentAppRequestDataDataView(pointer, context_);
    }

    inline void ServiceWorkerEventDispatcher_DispatchPaymentRequestEvent_ResponseParamsDataView::GetDispatchEventTimeDataView(
        ::mojo::common::mojom::TimeDataView* output)
    {
        auto pointer = data_->dispatch_event_time.Get();
        *output = ::mojo::common::mojom::TimeDataView(pointer, context_);
    }

    inline void ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ParamsDataView::GetEventDataView(
        ExtendableMessageEventDataView* output)
    {
        auto pointer = data_->event.Get();
        *output = ExtendableMessageEventDataView(pointer, context_);
    }

    inline void ServiceWorkerEventDispatcher_DispatchExtendableMessageEvent_ResponseParamsDataView::GetDispatchEventTimeDataView(
        ::mojo::common::mojom::TimeDataView* output)
    {
        auto pointer = data_->dispatch_event_time.Get();
        *output = ::mojo::common::mojom::TimeDataView(pointer, context_);
    }

} // namespace mojom
} // namespace content

#endif // CONTENT_COMMON_SERVICE_WORKER_SERVICE_WORKER_EVENT_DISPATCHER_MOJOM_SHARED_H_
