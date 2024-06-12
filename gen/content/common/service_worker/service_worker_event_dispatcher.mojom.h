// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_SERVICE_WORKER_SERVICE_WORKER_EVENT_DISPATCHER_MOJOM_H_
#define CONTENT_COMMON_SERVICE_WORKER_SERVICE_WORKER_EVENT_DISPATCHER_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/files/file.h"
#include "base/files/file_path.h"
#include "base/i18n/rtl.h"
#include "base/optional.h"
#include "base/strings/string16.h"
#include "base/time/time.h"
#include "base/unguessable_token.h"
#include "base/values.h"
#include "base/version.h"
#include "cc/input/selection.h"
#include "cc/output/begin_frame_args.h"
#include "cc/output/compositor_frame.h"
#include "cc/output/compositor_frame_metadata.h"
#include "cc/output/filter_operation.h"
#include "cc/output/filter_operations.h"
#include "cc/quads/draw_quad.h"
#include "cc/quads/render_pass.h"
#include "cc/quads/shared_quad_state.h"
#include "cc/resources/returned_resource.h"
#include "cc/resources/transferable_resource.h"
#include "cc/surfaces/frame_sink_id.h"
#include "cc/surfaces/local_frame_id.h"
#include "cc/surfaces/surface_id.h"
#include "cc/surfaces/surface_info.h"
#include "cc/surfaces/surface_reference.h"
#include "cc/surfaces/surface_sequence.h"
#include "components/payments/payment_app.mojom.h"
#include "content/common/bluetooth/web_bluetooth_device_id.h"
#include "content/common/content_export.h"
#include "content/common/frame_owner_properties.h"
#include "content/common/frame_replication_state.h"
#include "content/common/indexed_db/indexed_db_key.h"
#include "content/common/indexed_db/indexed_db_key_path.h"
#include "content/common/indexed_db/indexed_db_key_range.h"
#include "content/common/indexed_db/indexed_db_metadata.h"
#include "content/common/media/media_devices.h"
#include "content/common/resize_params.h"
#include "content/common/resource_request.h"
#include "content/common/resource_request_completion_status.h"
#include "content/common/service_worker/embedded_worker_start_params.h"
#include "content/common/service_worker/service_worker_event_dispatcher.mojom-shared.h"
#include "content/common/service_worker/service_worker_status_code.h"
#include "content/common/service_worker/service_worker_types.h"
#include "content/common/url_loader.mojom.h"
#include "content/public/common/media_metadata.h"
#include "content/public/common/push_event_payload.h"
#include "content/public/common/referrer.h"
#include "content/public/common/renderer_preferences.h"
#include "content/public/common/resource_response.h"
#include "content/public/common/web_preferences.h"
#include "device/bluetooth/bluetooth_uuid.h"
#include "gpu/command_buffer/common/capabilities.h"
#include "gpu/command_buffer/common/mailbox.h"
#include "gpu/command_buffer/common/mailbox_holder.h"
#include "gpu/command_buffer/common/sync_token.h"
#include "gpu/command_buffer/service/gpu_preferences.h"
#include "gpu/config/dx_diag_node.h"
#include "gpu/config/gpu_info.h"
#include "gpu/ipc/common/surface_handle.h"
#include "media/base/audio_codecs.h"
#include "media/base/audio_parameters.h"
#include "media/base/buffering_state.h"
#include "media/base/cdm_key_information.h"
#include "media/base/cdm_promise.h"
#include "media/base/channel_layout.h"
#include "media/base/content_decryption_module.h"
#include "media/base/decode_status.h"
#include "media/base/decryptor.h"
#include "media/base/demuxer_stream.h"
#include "media/base/eme_constants.h"
#include "media/base/encryption_scheme.h"
#include "media/base/pipeline_status.h"
#include "media/base/sample_format.h"
#include "media/base/subsample_entry.h"
#include "media/base/video_codecs.h"
#include "media/base/video_types.h"
#include "media/capture/video/video_capture_device_descriptor.h"
#include "media/capture/video_capture_types.h"
#include "mojo/common/string16.mojom.h"
#include "mojo/common/time.mojom.h"
#include "mojo/public/cpp/bindings/associated_interface_ptr.h"
#include "mojo/public/cpp/bindings/associated_interface_ptr_info.h"
#include "mojo/public/cpp/bindings/associated_interface_request.h"
#include "mojo/public/cpp/bindings/interface_ptr.h"
#include "mojo/public/cpp/bindings/interface_request.h"
#include "mojo/public/cpp/bindings/lib/clone_equals_util.h"
#include "mojo/public/cpp/bindings/lib/control_message_handler.h"
#include "mojo/public/cpp/bindings/lib/control_message_proxy.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/lib/union_accessor.h"
#include "mojo/public/cpp/bindings/native_struct.h"
#include "mojo/public/cpp/bindings/no_interface.h"
#include "mojo/public/cpp/bindings/raw_ptr_impl_ref_traits.h"
#include "mojo/public/cpp/bindings/struct_ptr.h"
#include "mojo/public/cpp/bindings/struct_traits.h"
#include "mojo/public/cpp/bindings/thread_safe_interface_ptr.h"
#include "mojo/public/cpp/bindings/union_traits.h"
#include "net/base/network_change_notifier.h"
#include "net/url_request/redirect_info.h"
#include "services/service_manager/public/cpp/identity.h"
#include "services/service_manager/public/cpp/interface_provider_spec.h"
#include "services/service_manager/public/cpp/service_info.h"
#include "services/video_capture/public/cpp/capture_settings.h"
#include "third_party/WebKit/public/platform/WebReferrerPolicy.h"
#include "third_party/WebKit/public/platform/modules/background_sync/background_sync.mojom.h"
#include "third_party/WebKit/public/platform/modules/indexeddb/WebIDBTypes.h"
#include "third_party/WebKit/public/platform/modules/serviceworker/service_worker_event_status.mojom.h"
#include "third_party/WebKit/public/web/WebConsoleMessage.h"
#include "third_party/WebKit/public/web/WebPopupType.h"
#include "third_party/WebKit/public/web/WebWindowFeatures.h"
#include "third_party/skia/include/core/SkBitmap.h"
#include "third_party/skia/include/core/SkImageFilter.h"
#include "ui/base/ime/composition_text.h"
#include "ui/base/ime/composition_underline.h"
#include "ui/base/ime/text_input_mode.h"
#include "ui/base/ime/text_input_type.h"
#include "ui/base/window_open_disposition.h"
#include "ui/display/display.h"
#include "ui/events/event.h"
#include "ui/events/latency_info.h"
#include "ui/gfx/buffer_types.h"
#include "ui/gfx/color_space.h"
#include "ui/gfx/geometry/insets.h"
#include "ui/gfx/geometry/point.h"
#include "ui/gfx/geometry/point_f.h"
#include "ui/gfx/geometry/rect.h"
#include "ui/gfx/geometry/rect_f.h"
#include "ui/gfx/geometry/safe_integer_conversions.h"
#include "ui/gfx/geometry/size.h"
#include "ui/gfx/geometry/vector2d.h"
#include "ui/gfx/geometry/vector2d_f.h"
#include "ui/gfx/gpu_memory_buffer.h"
#include "ui/gfx/icc_profile.h"
#include "ui/gfx/native_pixmap_handle.h"
#include "ui/gfx/native_widget_types.h"
#include "ui/gfx/range/range.h"
#include "ui/gfx/range/range_f.h"
#include "ui/gfx/selection_bound.h"
#include "ui/gfx/transform.h"
#include "url/gurl.h"
#include "url/mojo/origin.mojom.h"
#include "url/origin.h"
#include <string>
#include <vector>

namespace content {
namespace mojom {
    class ServiceWorkerEventDispatcher;
    using ServiceWorkerEventDispatcherPtr = mojo::InterfacePtr<ServiceWorkerEventDispatcher>;
    using ServiceWorkerEventDispatcherPtrInfo = mojo::InterfacePtrInfo<ServiceWorkerEventDispatcher>;
    using ThreadSafeServiceWorkerEventDispatcherPtr = mojo::ThreadSafeInterfacePtr<ServiceWorkerEventDispatcher>;
    using ServiceWorkerEventDispatcherRequest = mojo::InterfaceRequest<ServiceWorkerEventDispatcher>;
    using ServiceWorkerEventDispatcherAssociatedPtr = mojo::AssociatedInterfacePtr<ServiceWorkerEventDispatcher>;
    using ThreadSafeServiceWorkerEventDispatcherAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<ServiceWorkerEventDispatcher>;
    using ServiceWorkerEventDispatcherAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<ServiceWorkerEventDispatcher>;
    using ServiceWorkerEventDispatcherAssociatedRequest = mojo::AssociatedInterfaceRequest<ServiceWorkerEventDispatcher>;

    using PushEventPayload = mojo::NativeStruct;
    using PushEventPayloadPtr = mojo::NativeStructPtr;

    using ServiceWorkerFetchRequest = mojo::NativeStruct;
    using ServiceWorkerFetchRequestPtr = mojo::NativeStructPtr;

    using ExtendableMessageEventSource = mojo::NativeStruct;
    using ExtendableMessageEventSourcePtr = mojo::NativeStructPtr;

    class FetchEventPreloadHandle;
    using FetchEventPreloadHandlePtr = mojo::StructPtr<FetchEventPreloadHandle>;

    class ExtendableMessageEvent;
    using ExtendableMessageEventPtr = mojo::StructPtr<ExtendableMessageEvent>;

    class ServiceWorkerEventDispatcherProxy;

    template <typename ImplRefTraits>
    class ServiceWorkerEventDispatcherStub;

    class ServiceWorkerEventDispatcherRequestValidator;
    class ServiceWorkerEventDispatcherResponseValidator;

    class CONTENT_EXPORT ServiceWorkerEventDispatcher
        : public ServiceWorkerEventDispatcherInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = ServiceWorkerEventDispatcherProxy;

        template <typename ImplRefTraits>
        using Stub_ = ServiceWorkerEventDispatcherStub<ImplRefTraits>;

        using RequestValidator_ = ServiceWorkerEventDispatcherRequestValidator;
        using ResponseValidator_ = ServiceWorkerEventDispatcherResponseValidator;
        enum MethodMinVersions : uint32_t {
            kDispatchFetchEventMinVersion = 0,
            kDispatchPushEventMinVersion = 0,
            kDispatchSyncEventMinVersion = 0,
            kDispatchPaymentRequestEventMinVersion = 0,
            kDispatchExtendableMessageEventMinVersion = 0,
        };
        virtual ~ServiceWorkerEventDispatcher() { }

        using DispatchFetchEventCallback = base::Callback<void(::content::ServiceWorkerStatusCode, base::Time)>;
        virtual void DispatchFetchEvent(int32_t fetch_event_id, const ::content::ServiceWorkerFetchRequest& request, FetchEventPreloadHandlePtr preload_handle, const DispatchFetchEventCallback& callback) = 0;

        using DispatchPushEventCallback = base::Callback<void(::content::ServiceWorkerStatusCode, base::Time)>;
        virtual void DispatchPushEvent(const ::content::PushEventPayload& payload, const DispatchPushEventCallback& callback) = 0;

        using DispatchSyncEventCallback = base::Callback<void(::content::ServiceWorkerStatusCode, base::Time)>;
        virtual void DispatchSyncEvent(const std::string& tag, ::blink::mojom::BackgroundSyncEventLastChance last_chance, const DispatchSyncEventCallback& callback) = 0;

        using DispatchPaymentRequestEventCallback = base::Callback<void(::content::ServiceWorkerStatusCode, base::Time)>;
        virtual void DispatchPaymentRequestEvent(::payments::mojom::PaymentAppRequestDataPtr data, const DispatchPaymentRequestEventCallback& callback) = 0;

        using DispatchExtendableMessageEventCallback = base::Callback<void(::content::ServiceWorkerStatusCode, base::Time)>;
        virtual void DispatchExtendableMessageEvent(ExtendableMessageEventPtr event, const DispatchExtendableMessageEventCallback& callback) = 0;
    };

    class CONTENT_EXPORT ServiceWorkerEventDispatcherProxy
        : public ServiceWorkerEventDispatcher {
    public:
        explicit ServiceWorkerEventDispatcherProxy(mojo::MessageReceiverWithResponder* receiver);
        void DispatchFetchEvent(int32_t fetch_event_id, const ::content::ServiceWorkerFetchRequest& request, FetchEventPreloadHandlePtr preload_handle, const DispatchFetchEventCallback& callback) override;
        void DispatchPushEvent(const ::content::PushEventPayload& payload, const DispatchPushEventCallback& callback) override;
        void DispatchSyncEvent(const std::string& tag, ::blink::mojom::BackgroundSyncEventLastChance last_chance, const DispatchSyncEventCallback& callback) override;
        void DispatchPaymentRequestEvent(::payments::mojom::PaymentAppRequestDataPtr data, const DispatchPaymentRequestEventCallback& callback) override;
        void DispatchExtendableMessageEvent(ExtendableMessageEventPtr event, const DispatchExtendableMessageEventCallback& callback) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class CONTENT_EXPORT ServiceWorkerEventDispatcherStubDispatch {
    public:
        static bool Accept(ServiceWorkerEventDispatcher* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(ServiceWorkerEventDispatcher* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<ServiceWorkerEventDispatcher>>
    class ServiceWorkerEventDispatcherStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        ServiceWorkerEventDispatcherStub() { }
        ~ServiceWorkerEventDispatcherStub() override { }

        void set_sink(ImplPointerType sink) { sink_ = std::move(sink); }
        ImplPointerType& sink() { return sink_; }

        mojo::internal::SerializationContext* serialization_context()
        {
            return &serialization_context_;
        }

        bool Accept(mojo::Message* message) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return ServiceWorkerEventDispatcherStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return ServiceWorkerEventDispatcherStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class CONTENT_EXPORT ServiceWorkerEventDispatcherRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class CONTENT_EXPORT ServiceWorkerEventDispatcherResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

    class CONTENT_EXPORT FetchEventPreloadHandle {
    public:
        using DataView = FetchEventPreloadHandleDataView;
        using Data_ = internal::FetchEventPreloadHandle_Data;

        static FetchEventPreloadHandlePtr New();

        template <typename U>
        static FetchEventPreloadHandlePtr From(const U& u)
        {
            return mojo::TypeConverter<FetchEventPreloadHandlePtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, FetchEventPreloadHandle>::Convert(*this);
        }

        FetchEventPreloadHandle();
        ~FetchEventPreloadHandle();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = FetchEventPreloadHandlePtr>
        FetchEventPreloadHandlePtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, FetchEventPreloadHandle>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                FetchEventPreloadHandle::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                FetchEventPreloadHandle::DataView, std::vector<uint8_t>>(
                input, output);
        }

        ::content::mojom::URLLoaderPtr url_loader;
        ::content::mojom::URLLoaderClientRequest url_loader_client_request;

    private:
        DISALLOW_COPY_AND_ASSIGN(FetchEventPreloadHandle);
    };

    class CONTENT_EXPORT ExtendableMessageEvent {
    public:
        using DataView = ExtendableMessageEventDataView;
        using Data_ = internal::ExtendableMessageEvent_Data;

        static ExtendableMessageEventPtr New();

        template <typename U>
        static ExtendableMessageEventPtr From(const U& u)
        {
            return mojo::TypeConverter<ExtendableMessageEventPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, ExtendableMessageEvent>::Convert(*this);
        }

        ExtendableMessageEvent();
        ~ExtendableMessageEvent();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = ExtendableMessageEventPtr>
        ExtendableMessageEventPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, ExtendableMessageEvent>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                ExtendableMessageEvent::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                ExtendableMessageEvent::DataView, std::vector<uint8_t>>(
                input, output);
        }

        base::string16 message;
        url::Origin source_origin;
        std::vector<int32_t> message_ports;
        std::vector<int32_t> new_routing_ids;
        ::content::ExtendableMessageEventSource source;
    };

    template <typename StructPtrType>
    FetchEventPreloadHandlePtr FetchEventPreloadHandle::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->url_loader = mojo::internal::Clone(url_loader);
        rv->url_loader_client_request = mojo::internal::Clone(url_loader_client_request);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, FetchEventPreloadHandle>::value>::type*>
    bool FetchEventPreloadHandle::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->url_loader, other.url_loader))
            return false;
        if (!mojo::internal::Equals(this->url_loader_client_request, other.url_loader_client_request))
            return false;
        return true;
    }
    template <typename StructPtrType>
    ExtendableMessageEventPtr ExtendableMessageEvent::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->message = mojo::internal::Clone(message);
        rv->source_origin = mojo::internal::Clone(source_origin);
        rv->message_ports = mojo::internal::Clone(message_ports);
        rv->new_routing_ids = mojo::internal::Clone(new_routing_ids);
        rv->source = mojo::internal::Clone(source);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, ExtendableMessageEvent>::value>::type*>
    bool ExtendableMessageEvent::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->message, other.message))
            return false;
        if (!mojo::internal::Equals(this->source_origin, other.source_origin))
            return false;
        if (!mojo::internal::Equals(this->message_ports, other.message_ports))
            return false;
        if (!mojo::internal::Equals(this->new_routing_ids, other.new_routing_ids))
            return false;
        if (!mojo::internal::Equals(this->source, other.source))
            return false;
        return true;
    }

} // namespace mojom
} // namespace content

namespace mojo {

template <>
struct CONTENT_EXPORT StructTraits<::content::mojom::FetchEventPreloadHandle::DataView,
    ::content::mojom::FetchEventPreloadHandlePtr> {
    static bool IsNull(const ::content::mojom::FetchEventPreloadHandlePtr& input) { return !input; }
    static void SetToNull(::content::mojom::FetchEventPreloadHandlePtr* output) { output->reset(); }

    static decltype(::content::mojom::FetchEventPreloadHandle::url_loader)& url_loader(
        ::content::mojom::FetchEventPreloadHandlePtr& input)
    {
        return input->url_loader;
    }

    static decltype(::content::mojom::FetchEventPreloadHandle::url_loader_client_request)& url_loader_client_request(
        ::content::mojom::FetchEventPreloadHandlePtr& input)
    {
        return input->url_loader_client_request;
    }

    static bool Read(::content::mojom::FetchEventPreloadHandle::DataView input, ::content::mojom::FetchEventPreloadHandlePtr* output);
};

template <>
struct CONTENT_EXPORT StructTraits<::content::mojom::ExtendableMessageEvent::DataView,
    ::content::mojom::ExtendableMessageEventPtr> {
    static bool IsNull(const ::content::mojom::ExtendableMessageEventPtr& input) { return !input; }
    static void SetToNull(::content::mojom::ExtendableMessageEventPtr* output) { output->reset(); }

    static const decltype(::content::mojom::ExtendableMessageEvent::message)& message(
        const ::content::mojom::ExtendableMessageEventPtr& input)
    {
        return input->message;
    }

    static const decltype(::content::mojom::ExtendableMessageEvent::source_origin)& source_origin(
        const ::content::mojom::ExtendableMessageEventPtr& input)
    {
        return input->source_origin;
    }

    static const decltype(::content::mojom::ExtendableMessageEvent::message_ports)& message_ports(
        const ::content::mojom::ExtendableMessageEventPtr& input)
    {
        return input->message_ports;
    }

    static const decltype(::content::mojom::ExtendableMessageEvent::new_routing_ids)& new_routing_ids(
        const ::content::mojom::ExtendableMessageEventPtr& input)
    {
        return input->new_routing_ids;
    }

    static const decltype(::content::mojom::ExtendableMessageEvent::source)& source(
        const ::content::mojom::ExtendableMessageEventPtr& input)
    {
        return input->source;
    }

    static bool Read(::content::mojom::ExtendableMessageEvent::DataView input, ::content::mojom::ExtendableMessageEventPtr* output);
};

} // namespace mojo

#endif // CONTENT_COMMON_SERVICE_WORKER_SERVICE_WORKER_EVENT_DISPATCHER_MOJOM_H_