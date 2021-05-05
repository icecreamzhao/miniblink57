// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-private-field"
#elif defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4056)
#pragma warning(disable : 4065)
#pragma warning(disable : 4756)
#endif

#include "media/mojo/interfaces/renderer.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "ipc/ipc_message_utils.h"
#include "media/base/ipc/media_param_traits.h"
#include "media/base/ipc/media_param_traits_macros.h"
#include "media/mojo/interfaces/pipeline_statistics_struct_traits.h"
#include "mojo/common/common_custom_types_struct_traits.h"
#include "mojo/common/values_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "services/service_manager/public/cpp/identity_struct_traits.h"
#include "services/service_manager/public/cpp/interface_provider_spec_struct_traits.h"
#include "services/service_manager/public/cpp/service_info_struct_traits.h"
#include "ui/gfx/geometry/mojo/geometry_struct_traits.h"
#include "url/mojo/url_gurl_struct_traits.h"
namespace media {
namespace mojom {
    const char Renderer::Name_[] = "media::mojom::Renderer";

    class Renderer_Initialize_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        Renderer_Initialize_ForwardToCallback(
            const Renderer::InitializeCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        Renderer::InitializeCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(Renderer_Initialize_ForwardToCallback);
    };
    bool Renderer_Initialize_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::Renderer_Initialize_ResponseParams_Data* params = reinterpret_cast<internal::Renderer_Initialize_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        bool p_success {};
        Renderer_Initialize_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_success = input_data_view.success();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Renderer::Initialize response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_success));
        }
        return true;
    }

    class Renderer_Flush_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        Renderer_Flush_ForwardToCallback(
            const Renderer::FlushCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        Renderer::FlushCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(Renderer_Flush_ForwardToCallback);
    };
    bool Renderer_Flush_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::Renderer_Flush_ResponseParams_Data* params = reinterpret_cast<internal::Renderer_Flush_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        Renderer_Flush_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Renderer::Flush response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run();
        }
        return true;
    }

    class Renderer_SetCdm_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        Renderer_SetCdm_ForwardToCallback(
            const Renderer::SetCdmCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        Renderer::SetCdmCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(Renderer_SetCdm_ForwardToCallback);
    };
    bool Renderer_SetCdm_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::Renderer_SetCdm_ResponseParams_Data* params = reinterpret_cast<internal::Renderer_SetCdm_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        bool p_success {};
        Renderer_SetCdm_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_success = input_data_view.success();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Renderer::SetCdm response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_success));
        }
        return true;
    }

    class Renderer_InitiateScopedSurfaceRequest_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        Renderer_InitiateScopedSurfaceRequest_ForwardToCallback(
            const Renderer::InitiateScopedSurfaceRequestCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        Renderer::InitiateScopedSurfaceRequestCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(Renderer_InitiateScopedSurfaceRequest_ForwardToCallback);
    };
    bool Renderer_InitiateScopedSurfaceRequest_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::Renderer_InitiateScopedSurfaceRequest_ResponseParams_Data* params = reinterpret_cast<internal::Renderer_InitiateScopedSurfaceRequest_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        base::UnguessableToken p_request_token {};
        Renderer_InitiateScopedSurfaceRequest_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadRequestToken(&p_request_token))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Renderer::InitiateScopedSurfaceRequest response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_request_token));
        }
        return true;
    }

    RendererProxy::RendererProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void RendererProxy::Initialize(
        RendererClientAssociatedPtrInfo in_client, ::media::mojom::DemuxerStreamPtr in_audio, ::media::mojom::DemuxerStreamPtr in_video, const base::Optional<GURL>& in_media_url, const base::Optional<GURL>& in_first_party_for_cookies, const InitializeCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::Renderer_Initialize_Params_Data);
        size += mojo::internal::PrepareToSerialize<::url::mojom::UrlDataView>(
            in_media_url, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::url::mojom::UrlDataView>(
            in_first_party_for_cookies, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kRenderer_Initialize_Name, size);

        auto params = ::media::mojom::internal::Renderer_Initialize_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::media::mojom::RendererClientAssociatedPtrInfoDataView>(
            in_client, &params->client, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->client),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_INTERFACE_ID,
            "invalid client in Renderer.Initialize request");
        mojo::internal::Serialize<::media::mojom::DemuxerStreamPtrDataView>(
            in_audio, &params->audio, &serialization_context);
        mojo::internal::Serialize<::media::mojom::DemuxerStreamPtrDataView>(
            in_video, &params->video, &serialization_context);
        typename decltype(params->media_url)::BaseType* media_url_ptr;
        mojo::internal::Serialize<::url::mojom::UrlDataView>(
            in_media_url, builder.buffer(), &media_url_ptr, &serialization_context);
        params->media_url.Set(media_url_ptr);
        typename decltype(params->first_party_for_cookies)::BaseType* first_party_for_cookies_ptr;
        mojo::internal::Serialize<::url::mojom::UrlDataView>(
            in_first_party_for_cookies, builder.buffer(), &first_party_for_cookies_ptr, &serialization_context);
        params->first_party_for_cookies.Set(first_party_for_cookies_ptr);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new Renderer_Initialize_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void RendererProxy::Flush(
        const FlushCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::Renderer_Flush_Params_Data);
        mojo::internal::RequestMessageBuilder builder(internal::kRenderer_Flush_Name, size);

        auto params = ::media::mojom::internal::Renderer_Flush_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new Renderer_Flush_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void RendererProxy::StartPlayingFrom(
        base::TimeDelta in_time)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::Renderer_StartPlayingFrom_Params_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::TimeDeltaDataView>(
            in_time, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kRenderer_StartPlayingFrom_Name, size);

        auto params = ::media::mojom::internal::Renderer_StartPlayingFrom_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->time)::BaseType* time_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::TimeDeltaDataView>(
            in_time, builder.buffer(), &time_ptr, &serialization_context);
        params->time.Set(time_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->time.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null time in Renderer.StartPlayingFrom request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void RendererProxy::SetPlaybackRate(
        double in_playback_rate)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::Renderer_SetPlaybackRate_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kRenderer_SetPlaybackRate_Name, size);

        auto params = ::media::mojom::internal::Renderer_SetPlaybackRate_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->playback_rate = in_playback_rate;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void RendererProxy::SetVolume(
        float in_volume)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::Renderer_SetVolume_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kRenderer_SetVolume_Name, size);

        auto params = ::media::mojom::internal::Renderer_SetVolume_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->volume = in_volume;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void RendererProxy::SetCdm(
        int32_t in_cdm_id, const SetCdmCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::Renderer_SetCdm_Params_Data);
        mojo::internal::RequestMessageBuilder builder(internal::kRenderer_SetCdm_Name, size);

        auto params = ::media::mojom::internal::Renderer_SetCdm_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->cdm_id = in_cdm_id;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new Renderer_SetCdm_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void RendererProxy::InitiateScopedSurfaceRequest(
        const InitiateScopedSurfaceRequestCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::Renderer_InitiateScopedSurfaceRequest_Params_Data);
        mojo::internal::RequestMessageBuilder builder(internal::kRenderer_InitiateScopedSurfaceRequest_Name, size);

        auto params = ::media::mojom::internal::Renderer_InitiateScopedSurfaceRequest_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new Renderer_InitiateScopedSurfaceRequest_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    class Renderer_Initialize_ProxyToResponder {
    public:
        static Renderer::InitializeCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<Renderer_Initialize_ProxyToResponder> proxy(
                new Renderer_Initialize_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&Renderer_Initialize_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~Renderer_Initialize_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "Renderer::Initialize() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        Renderer_Initialize_ProxyToResponder(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : request_id_(request_id)
            , is_sync_(is_sync)
            , responder_(responder)
            , serialization_context_(std::move(group_controller))
        {
        }

        void Run(
            bool in_success);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(Renderer_Initialize_ProxyToResponder);
    };

    void Renderer_Initialize_ProxyToResponder::Run(
        bool in_success)
    {
        size_t size = sizeof(::media::mojom::internal::Renderer_Initialize_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kRenderer_Initialize_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::media::mojom::internal::Renderer_Initialize_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->success = in_success;
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class Renderer_Flush_ProxyToResponder {
    public:
        static Renderer::FlushCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<Renderer_Flush_ProxyToResponder> proxy(
                new Renderer_Flush_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&Renderer_Flush_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~Renderer_Flush_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "Renderer::Flush() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        Renderer_Flush_ProxyToResponder(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : request_id_(request_id)
            , is_sync_(is_sync)
            , responder_(responder)
            , serialization_context_(std::move(group_controller))
        {
        }

        void Run();

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(Renderer_Flush_ProxyToResponder);
    };

    void Renderer_Flush_ProxyToResponder::Run()
    {
        size_t size = sizeof(::media::mojom::internal::Renderer_Flush_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kRenderer_Flush_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::media::mojom::internal::Renderer_Flush_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class Renderer_SetCdm_ProxyToResponder {
    public:
        static Renderer::SetCdmCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<Renderer_SetCdm_ProxyToResponder> proxy(
                new Renderer_SetCdm_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&Renderer_SetCdm_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~Renderer_SetCdm_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "Renderer::SetCdm() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        Renderer_SetCdm_ProxyToResponder(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : request_id_(request_id)
            , is_sync_(is_sync)
            , responder_(responder)
            , serialization_context_(std::move(group_controller))
        {
        }

        void Run(
            bool in_success);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(Renderer_SetCdm_ProxyToResponder);
    };

    void Renderer_SetCdm_ProxyToResponder::Run(
        bool in_success)
    {
        size_t size = sizeof(::media::mojom::internal::Renderer_SetCdm_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kRenderer_SetCdm_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::media::mojom::internal::Renderer_SetCdm_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->success = in_success;
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class Renderer_InitiateScopedSurfaceRequest_ProxyToResponder {
    public:
        static Renderer::InitiateScopedSurfaceRequestCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<Renderer_InitiateScopedSurfaceRequest_ProxyToResponder> proxy(
                new Renderer_InitiateScopedSurfaceRequest_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&Renderer_InitiateScopedSurfaceRequest_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~Renderer_InitiateScopedSurfaceRequest_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "Renderer::InitiateScopedSurfaceRequest() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        Renderer_InitiateScopedSurfaceRequest_ProxyToResponder(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : request_id_(request_id)
            , is_sync_(is_sync)
            , responder_(responder)
            , serialization_context_(std::move(group_controller))
        {
        }

        void Run(
            const base::UnguessableToken& in_request_token);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(Renderer_InitiateScopedSurfaceRequest_ProxyToResponder);
    };

    void Renderer_InitiateScopedSurfaceRequest_ProxyToResponder::Run(
        const base::UnguessableToken& in_request_token)
    {
        size_t size = sizeof(::media::mojom::internal::Renderer_InitiateScopedSurfaceRequest_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::UnguessableTokenDataView>(
            in_request_token, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kRenderer_InitiateScopedSurfaceRequest_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::media::mojom::internal::Renderer_InitiateScopedSurfaceRequest_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->request_token)::BaseType* request_token_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::UnguessableTokenDataView>(
            in_request_token, builder.buffer(), &request_token_ptr, &serialization_context_);
        params->request_token.Set(request_token_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->request_token.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null request_token in Renderer.InitiateScopedSurfaceRequest response");
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }

    // static
    bool RendererStubDispatch::Accept(
        Renderer* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kRenderer_Initialize_Name: {
            break;
        }
        case internal::kRenderer_Flush_Name: {
            break;
        }
        case internal::kRenderer_StartPlayingFrom_Name: {
            internal::Renderer_StartPlayingFrom_Params_Data* params = reinterpret_cast<internal::Renderer_StartPlayingFrom_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            base::TimeDelta p_time {};
            Renderer_StartPlayingFrom_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadTime(&p_time))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Renderer::StartPlayingFrom deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Renderer::StartPlayingFrom");
            mojo::internal::MessageDispatchContext context(message);
            impl->StartPlayingFrom(
                std::move(p_time));
            return true;
        }
        case internal::kRenderer_SetPlaybackRate_Name: {
            internal::Renderer_SetPlaybackRate_Params_Data* params = reinterpret_cast<internal::Renderer_SetPlaybackRate_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            double p_playback_rate {};
            Renderer_SetPlaybackRate_ParamsDataView input_data_view(params,
                context);

            p_playback_rate = input_data_view.playback_rate();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Renderer::SetPlaybackRate deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Renderer::SetPlaybackRate");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetPlaybackRate(
                std::move(p_playback_rate));
            return true;
        }
        case internal::kRenderer_SetVolume_Name: {
            internal::Renderer_SetVolume_Params_Data* params = reinterpret_cast<internal::Renderer_SetVolume_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            float p_volume {};
            Renderer_SetVolume_ParamsDataView input_data_view(params,
                context);

            p_volume = input_data_view.volume();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Renderer::SetVolume deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Renderer::SetVolume");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetVolume(
                std::move(p_volume));
            return true;
        }
        case internal::kRenderer_SetCdm_Name: {
            break;
        }
        case internal::kRenderer_InitiateScopedSurfaceRequest_Name: {
            break;
        }
        }
        return false;
    }

    // static
    bool RendererStubDispatch::AcceptWithResponder(
        Renderer* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kRenderer_Initialize_Name: {
            internal::Renderer_Initialize_Params_Data* params = reinterpret_cast<internal::Renderer_Initialize_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            RendererClientAssociatedPtrInfo p_client {};
            ::media::mojom::DemuxerStreamPtr p_audio {};
            ::media::mojom::DemuxerStreamPtr p_video {};
            base::Optional<GURL> p_media_url {};
            base::Optional<GURL> p_first_party_for_cookies {};
            Renderer_Initialize_ParamsDataView input_data_view(params,
                context);

            p_client = input_data_view.TakeClient<decltype(p_client)>();
            p_audio = input_data_view.TakeAudio<decltype(p_audio)>();
            p_video = input_data_view.TakeVideo<decltype(p_video)>();
            if (!input_data_view.ReadMediaUrl(&p_media_url))
                success = false;
            if (!input_data_view.ReadFirstPartyForCookies(&p_first_party_for_cookies))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Renderer::Initialize deserializer");
                return false;
            }
            Renderer::InitializeCallback callback = Renderer_Initialize_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Renderer::Initialize");
            mojo::internal::MessageDispatchContext context(message);
            impl->Initialize(
                std::move(p_client),
                std::move(p_audio),
                std::move(p_video),
                std::move(p_media_url),
                std::move(p_first_party_for_cookies), std::move(callback));
            return true;
        }
        case internal::kRenderer_Flush_Name: {
            internal::Renderer_Flush_Params_Data* params = reinterpret_cast<internal::Renderer_Flush_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            Renderer_Flush_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Renderer::Flush deserializer");
                return false;
            }
            Renderer::FlushCallback callback = Renderer_Flush_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Renderer::Flush");
            mojo::internal::MessageDispatchContext context(message);
            impl->Flush(std::move(callback));
            return true;
        }
        case internal::kRenderer_StartPlayingFrom_Name: {
            break;
        }
        case internal::kRenderer_SetPlaybackRate_Name: {
            break;
        }
        case internal::kRenderer_SetVolume_Name: {
            break;
        }
        case internal::kRenderer_SetCdm_Name: {
            internal::Renderer_SetCdm_Params_Data* params = reinterpret_cast<internal::Renderer_SetCdm_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_cdm_id {};
            Renderer_SetCdm_ParamsDataView input_data_view(params,
                context);

            p_cdm_id = input_data_view.cdm_id();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Renderer::SetCdm deserializer");
                return false;
            }
            Renderer::SetCdmCallback callback = Renderer_SetCdm_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Renderer::SetCdm");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetCdm(
                std::move(p_cdm_id), std::move(callback));
            return true;
        }
        case internal::kRenderer_InitiateScopedSurfaceRequest_Name: {
            internal::Renderer_InitiateScopedSurfaceRequest_Params_Data* params = reinterpret_cast<internal::Renderer_InitiateScopedSurfaceRequest_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            Renderer_InitiateScopedSurfaceRequest_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Renderer::InitiateScopedSurfaceRequest deserializer");
                return false;
            }
            Renderer::InitiateScopedSurfaceRequestCallback callback = Renderer_InitiateScopedSurfaceRequest_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Renderer::InitiateScopedSurfaceRequest");
            mojo::internal::MessageDispatchContext context(message);
            impl->InitiateScopedSurfaceRequest(std::move(callback));
            return true;
        }
        }
        return false;
    }

    bool RendererRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "Renderer RequestValidator");

        switch (message->header()->name) {
        case internal::kRenderer_Initialize_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Renderer_Initialize_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRenderer_Flush_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Renderer_Flush_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRenderer_StartPlayingFrom_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Renderer_StartPlayingFrom_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRenderer_SetPlaybackRate_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Renderer_SetPlaybackRate_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRenderer_SetVolume_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Renderer_SetVolume_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRenderer_SetCdm_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Renderer_SetCdm_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRenderer_InitiateScopedSurfaceRequest_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Renderer_InitiateScopedSurfaceRequest_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        default:
            break;
        }

        // Unrecognized message.
        ReportValidationError(
            &validation_context,
            mojo::internal::VALIDATION_ERROR_MESSAGE_HEADER_UNKNOWN_METHOD);
        return false;
    }

    bool RendererResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "Renderer ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kRenderer_Initialize_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Renderer_Initialize_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRenderer_Flush_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Renderer_Flush_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRenderer_SetCdm_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Renderer_SetCdm_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRenderer_InitiateScopedSurfaceRequest_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Renderer_InitiateScopedSurfaceRequest_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        default:
            break;
        }

        // Unrecognized message.
        ReportValidationError(
            &validation_context,
            mojo::internal::VALIDATION_ERROR_MESSAGE_HEADER_UNKNOWN_METHOD);
        return false;
    }
    const char RendererClient::Name_[] = "media::mojom::RendererClient";

    RendererClientProxy::RendererClientProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void RendererClientProxy::OnTimeUpdate(
        base::TimeDelta in_time, base::TimeDelta in_max_time, base::TimeTicks in_capture_time)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::RendererClient_OnTimeUpdate_Params_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::TimeDeltaDataView>(
            in_time, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::TimeDeltaDataView>(
            in_max_time, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::TimeTicksDataView>(
            in_capture_time, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kRendererClient_OnTimeUpdate_Name, size);

        auto params = ::media::mojom::internal::RendererClient_OnTimeUpdate_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->time)::BaseType* time_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::TimeDeltaDataView>(
            in_time, builder.buffer(), &time_ptr, &serialization_context);
        params->time.Set(time_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->time.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null time in RendererClient.OnTimeUpdate request");
        typename decltype(params->max_time)::BaseType* max_time_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::TimeDeltaDataView>(
            in_max_time, builder.buffer(), &max_time_ptr, &serialization_context);
        params->max_time.Set(max_time_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->max_time.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null max_time in RendererClient.OnTimeUpdate request");
        typename decltype(params->capture_time)::BaseType* capture_time_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::TimeTicksDataView>(
            in_capture_time, builder.buffer(), &capture_time_ptr, &serialization_context);
        params->capture_time.Set(capture_time_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->capture_time.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null capture_time in RendererClient.OnTimeUpdate request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void RendererClientProxy::OnBufferingStateChange(
        media::BufferingState in_state)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::RendererClient_OnBufferingStateChange_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kRendererClient_OnBufferingStateChange_Name, size);

        auto params = ::media::mojom::internal::RendererClient_OnBufferingStateChange_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::media::mojom::BufferingState>(
            in_state, &params->state);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void RendererClientProxy::OnEnded()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::RendererClient_OnEnded_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kRendererClient_OnEnded_Name, size);

        auto params = ::media::mojom::internal::RendererClient_OnEnded_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void RendererClientProxy::OnError()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::RendererClient_OnError_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kRendererClient_OnError_Name, size);

        auto params = ::media::mojom::internal::RendererClient_OnError_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void RendererClientProxy::OnVideoNaturalSizeChange(
        const gfx::Size& in_size)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::RendererClient_OnVideoNaturalSizeChange_Params_Data);
        size += mojo::internal::PrepareToSerialize<::gfx::mojom::SizeDataView>(
            in_size, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kRendererClient_OnVideoNaturalSizeChange_Name, size);

        auto params = ::media::mojom::internal::RendererClient_OnVideoNaturalSizeChange_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->size)::BaseType* size_ptr;
        mojo::internal::Serialize<::gfx::mojom::SizeDataView>(
            in_size, builder.buffer(), &size_ptr, &serialization_context);
        params->size.Set(size_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->size.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null size in RendererClient.OnVideoNaturalSizeChange request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void RendererClientProxy::OnVideoOpacityChange(
        bool in_opaque)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::RendererClient_OnVideoOpacityChange_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kRendererClient_OnVideoOpacityChange_Name, size);

        auto params = ::media::mojom::internal::RendererClient_OnVideoOpacityChange_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->opaque = in_opaque;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void RendererClientProxy::OnStatisticsUpdate(
        const media::PipelineStatistics& in_stats)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::RendererClient_OnStatisticsUpdate_Params_Data);
        size += mojo::internal::PrepareToSerialize<::media::mojom::PipelineStatisticsDataView>(
            in_stats, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kRendererClient_OnStatisticsUpdate_Name, size);

        auto params = ::media::mojom::internal::RendererClient_OnStatisticsUpdate_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->stats)::BaseType* stats_ptr;
        mojo::internal::Serialize<::media::mojom::PipelineStatisticsDataView>(
            in_stats, builder.buffer(), &stats_ptr, &serialization_context);
        params->stats.Set(stats_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->stats.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null stats in RendererClient.OnStatisticsUpdate request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void RendererClientProxy::OnWaitingForDecryptionKey()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::RendererClient_OnWaitingForDecryptionKey_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kRendererClient_OnWaitingForDecryptionKey_Name, size);

        auto params = ::media::mojom::internal::RendererClient_OnWaitingForDecryptionKey_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void RendererClientProxy::OnDurationChange(
        base::TimeDelta in_duration)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::RendererClient_OnDurationChange_Params_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::TimeDeltaDataView>(
            in_duration, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kRendererClient_OnDurationChange_Name, size);

        auto params = ::media::mojom::internal::RendererClient_OnDurationChange_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->duration)::BaseType* duration_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::TimeDeltaDataView>(
            in_duration, builder.buffer(), &duration_ptr, &serialization_context);
        params->duration.Set(duration_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->duration.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null duration in RendererClient.OnDurationChange request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool RendererClientStubDispatch::Accept(
        RendererClient* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kRendererClient_OnTimeUpdate_Name: {
            internal::RendererClient_OnTimeUpdate_Params_Data* params = reinterpret_cast<internal::RendererClient_OnTimeUpdate_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            base::TimeDelta p_time {};
            base::TimeDelta p_max_time {};
            base::TimeTicks p_capture_time {};
            RendererClient_OnTimeUpdate_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadTime(&p_time))
                success = false;
            if (!input_data_view.ReadMaxTime(&p_max_time))
                success = false;
            if (!input_data_view.ReadCaptureTime(&p_capture_time))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "RendererClient::OnTimeUpdate deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "RendererClient::OnTimeUpdate");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnTimeUpdate(
                std::move(p_time),
                std::move(p_max_time),
                std::move(p_capture_time));
            return true;
        }
        case internal::kRendererClient_OnBufferingStateChange_Name: {
            internal::RendererClient_OnBufferingStateChange_Params_Data* params = reinterpret_cast<internal::RendererClient_OnBufferingStateChange_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            media::BufferingState p_state {};
            RendererClient_OnBufferingStateChange_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadState(&p_state))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "RendererClient::OnBufferingStateChange deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "RendererClient::OnBufferingStateChange");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnBufferingStateChange(
                std::move(p_state));
            return true;
        }
        case internal::kRendererClient_OnEnded_Name: {
            internal::RendererClient_OnEnded_Params_Data* params = reinterpret_cast<internal::RendererClient_OnEnded_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            RendererClient_OnEnded_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "RendererClient::OnEnded deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "RendererClient::OnEnded");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnEnded();
            return true;
        }
        case internal::kRendererClient_OnError_Name: {
            internal::RendererClient_OnError_Params_Data* params = reinterpret_cast<internal::RendererClient_OnError_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            RendererClient_OnError_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "RendererClient::OnError deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "RendererClient::OnError");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnError();
            return true;
        }
        case internal::kRendererClient_OnVideoNaturalSizeChange_Name: {
            internal::RendererClient_OnVideoNaturalSizeChange_Params_Data* params = reinterpret_cast<internal::RendererClient_OnVideoNaturalSizeChange_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            gfx::Size p_size {};
            RendererClient_OnVideoNaturalSizeChange_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadSize(&p_size))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "RendererClient::OnVideoNaturalSizeChange deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "RendererClient::OnVideoNaturalSizeChange");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnVideoNaturalSizeChange(
                std::move(p_size));
            return true;
        }
        case internal::kRendererClient_OnVideoOpacityChange_Name: {
            internal::RendererClient_OnVideoOpacityChange_Params_Data* params = reinterpret_cast<internal::RendererClient_OnVideoOpacityChange_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            bool p_opaque {};
            RendererClient_OnVideoOpacityChange_ParamsDataView input_data_view(params,
                context);

            p_opaque = input_data_view.opaque();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "RendererClient::OnVideoOpacityChange deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "RendererClient::OnVideoOpacityChange");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnVideoOpacityChange(
                std::move(p_opaque));
            return true;
        }
        case internal::kRendererClient_OnStatisticsUpdate_Name: {
            internal::RendererClient_OnStatisticsUpdate_Params_Data* params = reinterpret_cast<internal::RendererClient_OnStatisticsUpdate_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            media::PipelineStatistics p_stats {};
            RendererClient_OnStatisticsUpdate_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadStats(&p_stats))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "RendererClient::OnStatisticsUpdate deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "RendererClient::OnStatisticsUpdate");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnStatisticsUpdate(
                std::move(p_stats));
            return true;
        }
        case internal::kRendererClient_OnWaitingForDecryptionKey_Name: {
            internal::RendererClient_OnWaitingForDecryptionKey_Params_Data* params = reinterpret_cast<internal::RendererClient_OnWaitingForDecryptionKey_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            RendererClient_OnWaitingForDecryptionKey_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "RendererClient::OnWaitingForDecryptionKey deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "RendererClient::OnWaitingForDecryptionKey");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnWaitingForDecryptionKey();
            return true;
        }
        case internal::kRendererClient_OnDurationChange_Name: {
            internal::RendererClient_OnDurationChange_Params_Data* params = reinterpret_cast<internal::RendererClient_OnDurationChange_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            base::TimeDelta p_duration {};
            RendererClient_OnDurationChange_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadDuration(&p_duration))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "RendererClient::OnDurationChange deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "RendererClient::OnDurationChange");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnDurationChange(
                std::move(p_duration));
            return true;
        }
        }
        return false;
    }

    // static
    bool RendererClientStubDispatch::AcceptWithResponder(
        RendererClient* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kRendererClient_OnTimeUpdate_Name: {
            break;
        }
        case internal::kRendererClient_OnBufferingStateChange_Name: {
            break;
        }
        case internal::kRendererClient_OnEnded_Name: {
            break;
        }
        case internal::kRendererClient_OnError_Name: {
            break;
        }
        case internal::kRendererClient_OnVideoNaturalSizeChange_Name: {
            break;
        }
        case internal::kRendererClient_OnVideoOpacityChange_Name: {
            break;
        }
        case internal::kRendererClient_OnStatisticsUpdate_Name: {
            break;
        }
        case internal::kRendererClient_OnWaitingForDecryptionKey_Name: {
            break;
        }
        case internal::kRendererClient_OnDurationChange_Name: {
            break;
        }
        }
        return false;
    }

    bool RendererClientRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "RendererClient RequestValidator");

        switch (message->header()->name) {
        case internal::kRendererClient_OnTimeUpdate_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::RendererClient_OnTimeUpdate_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRendererClient_OnBufferingStateChange_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::RendererClient_OnBufferingStateChange_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRendererClient_OnEnded_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::RendererClient_OnEnded_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRendererClient_OnError_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::RendererClient_OnError_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRendererClient_OnVideoNaturalSizeChange_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::RendererClient_OnVideoNaturalSizeChange_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRendererClient_OnVideoOpacityChange_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::RendererClient_OnVideoOpacityChange_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRendererClient_OnStatisticsUpdate_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::RendererClient_OnStatisticsUpdate_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRendererClient_OnWaitingForDecryptionKey_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::RendererClient_OnWaitingForDecryptionKey_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kRendererClient_OnDurationChange_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::RendererClient_OnDurationChange_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        default:
            break;
        }

        // Unrecognized message.
        ReportValidationError(
            &validation_context,
            mojo::internal::VALIDATION_ERROR_MESSAGE_HEADER_UNKNOWN_METHOD);
        return false;
    }

} // namespace mojom
} // namespace media

namespace mojo {

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif