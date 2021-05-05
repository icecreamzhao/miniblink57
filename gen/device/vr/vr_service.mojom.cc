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

#include "device/vr/vr_service.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
namespace device {
namespace mojom { // static
    VRFieldOfViewPtr VRFieldOfView::New()
    {
        VRFieldOfViewPtr rv;
        mojo::internal::StructHelper<VRFieldOfView>::Initialize(&rv);
        return rv;
    }

    VRFieldOfView::VRFieldOfView()
        : upDegrees()
        , downDegrees()
        , leftDegrees()
        , rightDegrees()
    {
    }

    VRFieldOfView::~VRFieldOfView()
    {
    }
    size_t VRFieldOfView::Hash(size_t seed) const
    {
        seed = mojo::internal::Hash(seed, this->upDegrees);
        seed = mojo::internal::Hash(seed, this->downDegrees);
        seed = mojo::internal::Hash(seed, this->leftDegrees);
        seed = mojo::internal::Hash(seed, this->rightDegrees);
        return seed;
    } // static
    VRPosePtr VRPose::New()
    {
        VRPosePtr rv;
        mojo::internal::StructHelper<VRPose>::Initialize(&rv);
        return rv;
    }

    VRPose::VRPose()
        : timestamp()
        , orientation()
        , position()
        , angularVelocity()
        , linearVelocity()
        , angularAcceleration()
        , linearAcceleration()
        , poseIndex()
    {
    }

    VRPose::~VRPose()
    {
    } // static
    VRDisplayCapabilitiesPtr VRDisplayCapabilities::New()
    {
        VRDisplayCapabilitiesPtr rv;
        mojo::internal::StructHelper<VRDisplayCapabilities>::Initialize(&rv);
        return rv;
    }

    VRDisplayCapabilities::VRDisplayCapabilities()
        : hasOrientation()
        , hasPosition()
        , hasExternalDisplay()
        , canPresent()
    {
    }

    VRDisplayCapabilities::~VRDisplayCapabilities()
    {
    }
    size_t VRDisplayCapabilities::Hash(size_t seed) const
    {
        seed = mojo::internal::Hash(seed, this->hasOrientation);
        seed = mojo::internal::Hash(seed, this->hasPosition);
        seed = mojo::internal::Hash(seed, this->hasExternalDisplay);
        seed = mojo::internal::Hash(seed, this->canPresent);
        return seed;
    } // static
    VREyeParametersPtr VREyeParameters::New()
    {
        VREyeParametersPtr rv;
        mojo::internal::StructHelper<VREyeParameters>::Initialize(&rv);
        return rv;
    }

    VREyeParameters::VREyeParameters()
        : fieldOfView()
        , offset()
        , renderWidth()
        , renderHeight()
    {
    }

    VREyeParameters::~VREyeParameters()
    {
    } // static
    VRStageParametersPtr VRStageParameters::New()
    {
        VRStageParametersPtr rv;
        mojo::internal::StructHelper<VRStageParameters>::Initialize(&rv);
        return rv;
    }

    VRStageParameters::VRStageParameters()
        : standingTransform()
        , sizeX()
        , sizeZ()
    {
    }

    VRStageParameters::~VRStageParameters()
    {
    } // static
    VRDisplayInfoPtr VRDisplayInfo::New()
    {
        VRDisplayInfoPtr rv;
        mojo::internal::StructHelper<VRDisplayInfo>::Initialize(&rv);
        return rv;
    }

    VRDisplayInfo::VRDisplayInfo()
        : index()
        , displayName()
        , capabilities()
        , stageParameters()
        , leftEye()
        , rightEye()
    {
    }

    VRDisplayInfo::~VRDisplayInfo()
    {
    } // static
    VRLayerBoundsPtr VRLayerBounds::New()
    {
        VRLayerBoundsPtr rv;
        mojo::internal::StructHelper<VRLayerBounds>::Initialize(&rv);
        return rv;
    }

    VRLayerBounds::VRLayerBounds()
        : left()
        , top()
        , width()
        , height()
    {
    }

    VRLayerBounds::~VRLayerBounds()
    {
    }
    size_t VRLayerBounds::Hash(size_t seed) const
    {
        seed = mojo::internal::Hash(seed, this->left);
        seed = mojo::internal::Hash(seed, this->top);
        seed = mojo::internal::Hash(seed, this->width);
        seed = mojo::internal::Hash(seed, this->height);
        return seed;
    }
    const char VRService::Name_[] = "device::mojom::VRService";

    class VRService_SetClient_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        VRService_SetClient_ForwardToCallback(
            const VRService::SetClientCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        VRService::SetClientCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(VRService_SetClient_ForwardToCallback);
    };
    bool VRService_SetClient_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::VRService_SetClient_ResponseParams_Data* params = reinterpret_cast<internal::VRService_SetClient_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        uint32_t p_numberOfConnectedDevices {};
        VRService_SetClient_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_numberOfConnectedDevices = input_data_view.numberOfConnectedDevices();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "VRService::SetClient response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_numberOfConnectedDevices));
        }
        return true;
    }

    VRServiceProxy::VRServiceProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void VRServiceProxy::SetClient(
        VRServiceClientPtr in_client, const SetClientCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::device::mojom::internal::VRService_SetClient_Params_Data);
        mojo::internal::RequestMessageBuilder builder(internal::kVRService_SetClient_Name, size);

        auto params = ::device::mojom::internal::VRService_SetClient_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::device::mojom::VRServiceClientPtrDataView>(
            in_client, &params->client, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->client),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid client in VRService.SetClient request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new VRService_SetClient_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void VRServiceProxy::SetListeningForActivate(
        bool in_listening)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::device::mojom::internal::VRService_SetListeningForActivate_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kVRService_SetListeningForActivate_Name, size);

        auto params = ::device::mojom::internal::VRService_SetListeningForActivate_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->listening = in_listening;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }
    class VRService_SetClient_ProxyToResponder {
    public:
        static VRService::SetClientCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<VRService_SetClient_ProxyToResponder> proxy(
                new VRService_SetClient_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&VRService_SetClient_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~VRService_SetClient_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "VRService::SetClient() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        VRService_SetClient_ProxyToResponder(
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
            uint32_t in_numberOfConnectedDevices);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(VRService_SetClient_ProxyToResponder);
    };

    void VRService_SetClient_ProxyToResponder::Run(
        uint32_t in_numberOfConnectedDevices)
    {
        size_t size = sizeof(::device::mojom::internal::VRService_SetClient_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kVRService_SetClient_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::device::mojom::internal::VRService_SetClient_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->numberOfConnectedDevices = in_numberOfConnectedDevices;
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
    bool VRServiceStubDispatch::Accept(
        VRService* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kVRService_SetClient_Name: {
            break;
        }
        case internal::kVRService_SetListeningForActivate_Name: {
            internal::VRService_SetListeningForActivate_Params_Data* params = reinterpret_cast<internal::VRService_SetListeningForActivate_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            bool p_listening {};
            VRService_SetListeningForActivate_ParamsDataView input_data_view(params,
                context);

            p_listening = input_data_view.listening();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "VRService::SetListeningForActivate deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "VRService::SetListeningForActivate");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetListeningForActivate(
                std::move(p_listening));
            return true;
        }
        }
        return false;
    }

    // static
    bool VRServiceStubDispatch::AcceptWithResponder(
        VRService* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kVRService_SetClient_Name: {
            internal::VRService_SetClient_Params_Data* params = reinterpret_cast<internal::VRService_SetClient_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            VRServiceClientPtr p_client {};
            VRService_SetClient_ParamsDataView input_data_view(params,
                context);

            p_client = input_data_view.TakeClient<decltype(p_client)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "VRService::SetClient deserializer");
                return false;
            }
            VRService::SetClientCallback callback = VRService_SetClient_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "VRService::SetClient");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetClient(
                std::move(p_client), std::move(callback));
            return true;
        }
        case internal::kVRService_SetListeningForActivate_Name: {
            break;
        }
        }
        return false;
    }

    bool VRServiceRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "VRService RequestValidator");

        switch (message->header()->name) {
        case internal::kVRService_SetClient_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VRService_SetClient_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kVRService_SetListeningForActivate_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VRService_SetListeningForActivate_Params_Data>(
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

    bool VRServiceResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "VRService ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kVRService_SetClient_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VRService_SetClient_ResponseParams_Data>(
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
    const char VRServiceClient::Name_[] = "device::mojom::VRServiceClient";

    VRServiceClientProxy::VRServiceClientProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void VRServiceClientProxy::OnDisplayConnected(
        VRDisplayPtr in_display, VRDisplayClientRequest in_request, VRDisplayInfoPtr in_displayInfo)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::device::mojom::internal::VRServiceClient_OnDisplayConnected_Params_Data);
        size += mojo::internal::PrepareToSerialize<::device::mojom::VRDisplayInfoDataView>(
            in_displayInfo, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kVRServiceClient_OnDisplayConnected_Name, size);

        auto params = ::device::mojom::internal::VRServiceClient_OnDisplayConnected_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::device::mojom::VRDisplayPtrDataView>(
            in_display, &params->display, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->display),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid display in VRServiceClient.OnDisplayConnected request");
        mojo::internal::Serialize<::device::mojom::VRDisplayClientRequestDataView>(
            in_request, &params->request, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->request),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid request in VRServiceClient.OnDisplayConnected request");
        typename decltype(params->displayInfo)::BaseType* displayInfo_ptr;
        mojo::internal::Serialize<::device::mojom::VRDisplayInfoDataView>(
            in_displayInfo, builder.buffer(), &displayInfo_ptr, &serialization_context);
        params->displayInfo.Set(displayInfo_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->displayInfo.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null displayInfo in VRServiceClient.OnDisplayConnected request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool VRServiceClientStubDispatch::Accept(
        VRServiceClient* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kVRServiceClient_OnDisplayConnected_Name: {
            internal::VRServiceClient_OnDisplayConnected_Params_Data* params = reinterpret_cast<internal::VRServiceClient_OnDisplayConnected_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            VRDisplayPtr p_display {};
            VRDisplayClientRequest p_request {};
            VRDisplayInfoPtr p_displayInfo {};
            VRServiceClient_OnDisplayConnected_ParamsDataView input_data_view(params,
                context);

            p_display = input_data_view.TakeDisplay<decltype(p_display)>();
            p_request = input_data_view.TakeRequest<decltype(p_request)>();
            if (!input_data_view.ReadDisplayinfo(&p_displayInfo))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "VRServiceClient::OnDisplayConnected deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "VRServiceClient::OnDisplayConnected");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnDisplayConnected(
                std::move(p_display),
                std::move(p_request),
                std::move(p_displayInfo));
            return true;
        }
        }
        return false;
    }

    // static
    bool VRServiceClientStubDispatch::AcceptWithResponder(
        VRServiceClient* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kVRServiceClient_OnDisplayConnected_Name: {
            break;
        }
        }
        return false;
    }

    bool VRServiceClientRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "VRServiceClient RequestValidator");

        switch (message->header()->name) {
        case internal::kVRServiceClient_OnDisplayConnected_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VRServiceClient_OnDisplayConnected_Params_Data>(
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

    const char VRDisplay::Name_[] = "device::mojom::VRDisplay";
    bool VRDisplay::GetPose(VRPosePtr* pose)
    {
        NOTREACHED();
        return false;
    }
    class VRDisplay_GetPose_HandleSyncResponse
        : public mojo::MessageReceiver {
    public:
        VRDisplay_GetPose_HandleSyncResponse(
            scoped_refptr<mojo::AssociatedGroupController> group_controller,
            bool* result, VRPosePtr* out_pose)
            : serialization_context_(std::move(group_controller))
            , result_(result)
            , out_pose_(out_pose)
        {
            DCHECK(!*result_);
        }
        bool Accept(mojo::Message* message) override;

    private:
        mojo::internal::SerializationContext serialization_context_;
        bool* result_;
        VRPosePtr* out_pose_;
        DISALLOW_COPY_AND_ASSIGN(VRDisplay_GetPose_HandleSyncResponse);
    };
    bool VRDisplay_GetPose_HandleSyncResponse::Accept(
        mojo::Message* message)
    {
        internal::VRDisplay_GetPose_ResponseParams_Data* params = reinterpret_cast<internal::VRDisplay_GetPose_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        VRPosePtr p_pose {};
        VRDisplay_GetPose_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadPose(&p_pose))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "VRDisplay::GetPose response deserializer");
            return false;
        }
        *out_pose_ = std::move(p_pose);
        mojo::internal::SyncMessageResponseSetup::SetCurrentSyncResponseMessage(
            message);
        *result_ = true;
        return true;
    }

    class VRDisplay_GetPose_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        VRDisplay_GetPose_ForwardToCallback(
            const VRDisplay::GetPoseCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        VRDisplay::GetPoseCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(VRDisplay_GetPose_ForwardToCallback);
    };
    bool VRDisplay_GetPose_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::VRDisplay_GetPose_ResponseParams_Data* params = reinterpret_cast<internal::VRDisplay_GetPose_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        VRPosePtr p_pose {};
        VRDisplay_GetPose_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadPose(&p_pose))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "VRDisplay::GetPose response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_pose));
        }
        return true;
    }

    class VRDisplay_RequestPresent_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        VRDisplay_RequestPresent_ForwardToCallback(
            const VRDisplay::RequestPresentCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        VRDisplay::RequestPresentCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(VRDisplay_RequestPresent_ForwardToCallback);
    };
    bool VRDisplay_RequestPresent_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::VRDisplay_RequestPresent_ResponseParams_Data* params = reinterpret_cast<internal::VRDisplay_RequestPresent_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        bool p_success {};
        VRDisplay_RequestPresent_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_success = input_data_view.success();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "VRDisplay::RequestPresent response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_success));
        }
        return true;
    }

    VRDisplayProxy::VRDisplayProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }
    bool VRDisplayProxy::GetPose(
        VRPosePtr* param_pose)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::device::mojom::internal::VRDisplay_GetPose_Params_Data);

        mojo::internal::RequestMessageBuilder builder(internal::kVRDisplay_GetPose_Name, size,
            mojo::Message::kFlagIsSync);

        auto params = ::device::mojom::internal::VRDisplay_GetPose_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());

        bool result = false;
        mojo::MessageReceiver* responder = new VRDisplay_GetPose_HandleSyncResponse(
            group_controller_, &result, param_pose);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
        return result;
    }

    void VRDisplayProxy::GetPose(
        const GetPoseCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::device::mojom::internal::VRDisplay_GetPose_Params_Data);
        mojo::internal::RequestMessageBuilder builder(internal::kVRDisplay_GetPose_Name, size);

        auto params = ::device::mojom::internal::VRDisplay_GetPose_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new VRDisplay_GetPose_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void VRDisplayProxy::ResetPose()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::device::mojom::internal::VRDisplay_ResetPose_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kVRDisplay_ResetPose_Name, size);

        auto params = ::device::mojom::internal::VRDisplay_ResetPose_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void VRDisplayProxy::RequestPresent(
        bool in_secureOrigin, const RequestPresentCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::device::mojom::internal::VRDisplay_RequestPresent_Params_Data);
        mojo::internal::RequestMessageBuilder builder(internal::kVRDisplay_RequestPresent_Name, size);

        auto params = ::device::mojom::internal::VRDisplay_RequestPresent_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->secureOrigin = in_secureOrigin;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new VRDisplay_RequestPresent_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void VRDisplayProxy::ExitPresent()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::device::mojom::internal::VRDisplay_ExitPresent_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kVRDisplay_ExitPresent_Name, size);

        auto params = ::device::mojom::internal::VRDisplay_ExitPresent_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void VRDisplayProxy::SubmitFrame(
        VRPosePtr in_pose)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::device::mojom::internal::VRDisplay_SubmitFrame_Params_Data);
        size += mojo::internal::PrepareToSerialize<::device::mojom::VRPoseDataView>(
            in_pose, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kVRDisplay_SubmitFrame_Name, size);

        auto params = ::device::mojom::internal::VRDisplay_SubmitFrame_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->pose)::BaseType* pose_ptr;
        mojo::internal::Serialize<::device::mojom::VRPoseDataView>(
            in_pose, builder.buffer(), &pose_ptr, &serialization_context);
        params->pose.Set(pose_ptr);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void VRDisplayProxy::UpdateLayerBounds(
        VRLayerBoundsPtr in_leftBounds, VRLayerBoundsPtr in_rightBounds)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::device::mojom::internal::VRDisplay_UpdateLayerBounds_Params_Data);
        size += mojo::internal::PrepareToSerialize<::device::mojom::VRLayerBoundsDataView>(
            in_leftBounds, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::device::mojom::VRLayerBoundsDataView>(
            in_rightBounds, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kVRDisplay_UpdateLayerBounds_Name, size);

        auto params = ::device::mojom::internal::VRDisplay_UpdateLayerBounds_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->leftBounds)::BaseType* leftBounds_ptr;
        mojo::internal::Serialize<::device::mojom::VRLayerBoundsDataView>(
            in_leftBounds, builder.buffer(), &leftBounds_ptr, &serialization_context);
        params->leftBounds.Set(leftBounds_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->leftBounds.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null leftBounds in VRDisplay.UpdateLayerBounds request");
        typename decltype(params->rightBounds)::BaseType* rightBounds_ptr;
        mojo::internal::Serialize<::device::mojom::VRLayerBoundsDataView>(
            in_rightBounds, builder.buffer(), &rightBounds_ptr, &serialization_context);
        params->rightBounds.Set(rightBounds_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->rightBounds.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null rightBounds in VRDisplay.UpdateLayerBounds request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }
    class VRDisplay_GetPose_ProxyToResponder {
    public:
        static VRDisplay::GetPoseCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<VRDisplay_GetPose_ProxyToResponder> proxy(
                new VRDisplay_GetPose_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&VRDisplay_GetPose_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~VRDisplay_GetPose_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "VRDisplay::GetPose() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        VRDisplay_GetPose_ProxyToResponder(
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
            VRPosePtr in_pose);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(VRDisplay_GetPose_ProxyToResponder);
    };

    void VRDisplay_GetPose_ProxyToResponder::Run(
        VRPosePtr in_pose)
    {
        size_t size = sizeof(::device::mojom::internal::VRDisplay_GetPose_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<::device::mojom::VRPoseDataView>(
            in_pose, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kVRDisplay_GetPose_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::device::mojom::internal::VRDisplay_GetPose_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->pose)::BaseType* pose_ptr;
        mojo::internal::Serialize<::device::mojom::VRPoseDataView>(
            in_pose, builder.buffer(), &pose_ptr, &serialization_context_);
        params->pose.Set(pose_ptr);
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class VRDisplay_RequestPresent_ProxyToResponder {
    public:
        static VRDisplay::RequestPresentCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<VRDisplay_RequestPresent_ProxyToResponder> proxy(
                new VRDisplay_RequestPresent_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&VRDisplay_RequestPresent_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~VRDisplay_RequestPresent_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "VRDisplay::RequestPresent() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        VRDisplay_RequestPresent_ProxyToResponder(
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

        DISALLOW_COPY_AND_ASSIGN(VRDisplay_RequestPresent_ProxyToResponder);
    };

    void VRDisplay_RequestPresent_ProxyToResponder::Run(
        bool in_success)
    {
        size_t size = sizeof(::device::mojom::internal::VRDisplay_RequestPresent_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kVRDisplay_RequestPresent_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::device::mojom::internal::VRDisplay_RequestPresent_ResponseParams_Data::New(builder.buffer());
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

    // static
    bool VRDisplayStubDispatch::Accept(
        VRDisplay* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kVRDisplay_GetPose_Name: {
            break;
        }
        case internal::kVRDisplay_ResetPose_Name: {
            internal::VRDisplay_ResetPose_Params_Data* params = reinterpret_cast<internal::VRDisplay_ResetPose_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            VRDisplay_ResetPose_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "VRDisplay::ResetPose deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "VRDisplay::ResetPose");
            mojo::internal::MessageDispatchContext context(message);
            impl->ResetPose();
            return true;
        }
        case internal::kVRDisplay_RequestPresent_Name: {
            break;
        }
        case internal::kVRDisplay_ExitPresent_Name: {
            internal::VRDisplay_ExitPresent_Params_Data* params = reinterpret_cast<internal::VRDisplay_ExitPresent_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            VRDisplay_ExitPresent_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "VRDisplay::ExitPresent deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "VRDisplay::ExitPresent");
            mojo::internal::MessageDispatchContext context(message);
            impl->ExitPresent();
            return true;
        }
        case internal::kVRDisplay_SubmitFrame_Name: {
            internal::VRDisplay_SubmitFrame_Params_Data* params = reinterpret_cast<internal::VRDisplay_SubmitFrame_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            VRPosePtr p_pose {};
            VRDisplay_SubmitFrame_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadPose(&p_pose))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "VRDisplay::SubmitFrame deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "VRDisplay::SubmitFrame");
            mojo::internal::MessageDispatchContext context(message);
            impl->SubmitFrame(
                std::move(p_pose));
            return true;
        }
        case internal::kVRDisplay_UpdateLayerBounds_Name: {
            internal::VRDisplay_UpdateLayerBounds_Params_Data* params = reinterpret_cast<internal::VRDisplay_UpdateLayerBounds_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            VRLayerBoundsPtr p_leftBounds {};
            VRLayerBoundsPtr p_rightBounds {};
            VRDisplay_UpdateLayerBounds_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadLeftbounds(&p_leftBounds))
                success = false;
            if (!input_data_view.ReadRightbounds(&p_rightBounds))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "VRDisplay::UpdateLayerBounds deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "VRDisplay::UpdateLayerBounds");
            mojo::internal::MessageDispatchContext context(message);
            impl->UpdateLayerBounds(
                std::move(p_leftBounds),
                std::move(p_rightBounds));
            return true;
        }
        }
        return false;
    }

    // static
    bool VRDisplayStubDispatch::AcceptWithResponder(
        VRDisplay* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kVRDisplay_GetPose_Name: {
            internal::VRDisplay_GetPose_Params_Data* params = reinterpret_cast<internal::VRDisplay_GetPose_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            VRDisplay_GetPose_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "VRDisplay::GetPose deserializer");
                return false;
            }
            VRDisplay::GetPoseCallback callback = VRDisplay_GetPose_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "VRDisplay::GetPose");
            mojo::internal::MessageDispatchContext context(message);
            impl->GetPose(std::move(callback));
            return true;
        }
        case internal::kVRDisplay_ResetPose_Name: {
            break;
        }
        case internal::kVRDisplay_RequestPresent_Name: {
            internal::VRDisplay_RequestPresent_Params_Data* params = reinterpret_cast<internal::VRDisplay_RequestPresent_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            bool p_secureOrigin {};
            VRDisplay_RequestPresent_ParamsDataView input_data_view(params,
                context);

            p_secureOrigin = input_data_view.secureOrigin();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "VRDisplay::RequestPresent deserializer");
                return false;
            }
            VRDisplay::RequestPresentCallback callback = VRDisplay_RequestPresent_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "VRDisplay::RequestPresent");
            mojo::internal::MessageDispatchContext context(message);
            impl->RequestPresent(
                std::move(p_secureOrigin), std::move(callback));
            return true;
        }
        case internal::kVRDisplay_ExitPresent_Name: {
            break;
        }
        case internal::kVRDisplay_SubmitFrame_Name: {
            break;
        }
        case internal::kVRDisplay_UpdateLayerBounds_Name: {
            break;
        }
        }
        return false;
    }

    bool VRDisplayRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "VRDisplay RequestValidator");

        switch (message->header()->name) {
        case internal::kVRDisplay_GetPose_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VRDisplay_GetPose_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kVRDisplay_ResetPose_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VRDisplay_ResetPose_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kVRDisplay_RequestPresent_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VRDisplay_RequestPresent_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kVRDisplay_ExitPresent_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VRDisplay_ExitPresent_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kVRDisplay_SubmitFrame_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VRDisplay_SubmitFrame_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kVRDisplay_UpdateLayerBounds_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VRDisplay_UpdateLayerBounds_Params_Data>(
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

    bool VRDisplayResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "VRDisplay ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kVRDisplay_GetPose_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VRDisplay_GetPose_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kVRDisplay_RequestPresent_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VRDisplay_RequestPresent_ResponseParams_Data>(
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
    const char VRDisplayClient::Name_[] = "device::mojom::VRDisplayClient";

    VRDisplayClientProxy::VRDisplayClientProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void VRDisplayClientProxy::OnChanged(
        VRDisplayInfoPtr in_display)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::device::mojom::internal::VRDisplayClient_OnChanged_Params_Data);
        size += mojo::internal::PrepareToSerialize<::device::mojom::VRDisplayInfoDataView>(
            in_display, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kVRDisplayClient_OnChanged_Name, size);

        auto params = ::device::mojom::internal::VRDisplayClient_OnChanged_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->display)::BaseType* display_ptr;
        mojo::internal::Serialize<::device::mojom::VRDisplayInfoDataView>(
            in_display, builder.buffer(), &display_ptr, &serialization_context);
        params->display.Set(display_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->display.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null display in VRDisplayClient.OnChanged request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void VRDisplayClientProxy::OnExitPresent()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::device::mojom::internal::VRDisplayClient_OnExitPresent_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kVRDisplayClient_OnExitPresent_Name, size);

        auto params = ::device::mojom::internal::VRDisplayClient_OnExitPresent_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void VRDisplayClientProxy::OnBlur()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::device::mojom::internal::VRDisplayClient_OnBlur_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kVRDisplayClient_OnBlur_Name, size);

        auto params = ::device::mojom::internal::VRDisplayClient_OnBlur_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void VRDisplayClientProxy::OnFocus()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::device::mojom::internal::VRDisplayClient_OnFocus_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kVRDisplayClient_OnFocus_Name, size);

        auto params = ::device::mojom::internal::VRDisplayClient_OnFocus_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void VRDisplayClientProxy::OnActivate(
        VRDisplayEventReason in_reason)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::device::mojom::internal::VRDisplayClient_OnActivate_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kVRDisplayClient_OnActivate_Name, size);

        auto params = ::device::mojom::internal::VRDisplayClient_OnActivate_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::device::mojom::VRDisplayEventReason>(
            in_reason, &params->reason);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void VRDisplayClientProxy::OnDeactivate(
        VRDisplayEventReason in_reason)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::device::mojom::internal::VRDisplayClient_OnDeactivate_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kVRDisplayClient_OnDeactivate_Name, size);

        auto params = ::device::mojom::internal::VRDisplayClient_OnDeactivate_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::device::mojom::VRDisplayEventReason>(
            in_reason, &params->reason);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool VRDisplayClientStubDispatch::Accept(
        VRDisplayClient* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kVRDisplayClient_OnChanged_Name: {
            internal::VRDisplayClient_OnChanged_Params_Data* params = reinterpret_cast<internal::VRDisplayClient_OnChanged_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            VRDisplayInfoPtr p_display {};
            VRDisplayClient_OnChanged_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadDisplay(&p_display))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "VRDisplayClient::OnChanged deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "VRDisplayClient::OnChanged");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnChanged(
                std::move(p_display));
            return true;
        }
        case internal::kVRDisplayClient_OnExitPresent_Name: {
            internal::VRDisplayClient_OnExitPresent_Params_Data* params = reinterpret_cast<internal::VRDisplayClient_OnExitPresent_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            VRDisplayClient_OnExitPresent_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "VRDisplayClient::OnExitPresent deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "VRDisplayClient::OnExitPresent");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnExitPresent();
            return true;
        }
        case internal::kVRDisplayClient_OnBlur_Name: {
            internal::VRDisplayClient_OnBlur_Params_Data* params = reinterpret_cast<internal::VRDisplayClient_OnBlur_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            VRDisplayClient_OnBlur_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "VRDisplayClient::OnBlur deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "VRDisplayClient::OnBlur");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnBlur();
            return true;
        }
        case internal::kVRDisplayClient_OnFocus_Name: {
            internal::VRDisplayClient_OnFocus_Params_Data* params = reinterpret_cast<internal::VRDisplayClient_OnFocus_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            VRDisplayClient_OnFocus_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "VRDisplayClient::OnFocus deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "VRDisplayClient::OnFocus");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnFocus();
            return true;
        }
        case internal::kVRDisplayClient_OnActivate_Name: {
            internal::VRDisplayClient_OnActivate_Params_Data* params = reinterpret_cast<internal::VRDisplayClient_OnActivate_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            VRDisplayEventReason p_reason {};
            VRDisplayClient_OnActivate_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadReason(&p_reason))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "VRDisplayClient::OnActivate deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "VRDisplayClient::OnActivate");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnActivate(
                std::move(p_reason));
            return true;
        }
        case internal::kVRDisplayClient_OnDeactivate_Name: {
            internal::VRDisplayClient_OnDeactivate_Params_Data* params = reinterpret_cast<internal::VRDisplayClient_OnDeactivate_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            VRDisplayEventReason p_reason {};
            VRDisplayClient_OnDeactivate_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadReason(&p_reason))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "VRDisplayClient::OnDeactivate deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "VRDisplayClient::OnDeactivate");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnDeactivate(
                std::move(p_reason));
            return true;
        }
        }
        return false;
    }

    // static
    bool VRDisplayClientStubDispatch::AcceptWithResponder(
        VRDisplayClient* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kVRDisplayClient_OnChanged_Name: {
            break;
        }
        case internal::kVRDisplayClient_OnExitPresent_Name: {
            break;
        }
        case internal::kVRDisplayClient_OnBlur_Name: {
            break;
        }
        case internal::kVRDisplayClient_OnFocus_Name: {
            break;
        }
        case internal::kVRDisplayClient_OnActivate_Name: {
            break;
        }
        case internal::kVRDisplayClient_OnDeactivate_Name: {
            break;
        }
        }
        return false;
    }

    bool VRDisplayClientRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "VRDisplayClient RequestValidator");

        switch (message->header()->name) {
        case internal::kVRDisplayClient_OnChanged_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VRDisplayClient_OnChanged_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kVRDisplayClient_OnExitPresent_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VRDisplayClient_OnExitPresent_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kVRDisplayClient_OnBlur_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VRDisplayClient_OnBlur_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kVRDisplayClient_OnFocus_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VRDisplayClient_OnFocus_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kVRDisplayClient_OnActivate_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VRDisplayClient_OnActivate_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kVRDisplayClient_OnDeactivate_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::VRDisplayClient_OnDeactivate_Params_Data>(
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
} // namespace device

namespace mojo {

// static
bool StructTraits<::device::mojom::VRFieldOfView::DataView, ::device::mojom::VRFieldOfViewPtr>::Read(
    ::device::mojom::VRFieldOfView::DataView input,
    ::device::mojom::VRFieldOfViewPtr* output)
{
    bool success = true;
    ::device::mojom::VRFieldOfViewPtr result(::device::mojom::VRFieldOfView::New());

    result->upDegrees = input.upDegrees();
    result->downDegrees = input.downDegrees();
    result->leftDegrees = input.leftDegrees();
    result->rightDegrees = input.rightDegrees();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::device::mojom::VRPose::DataView, ::device::mojom::VRPosePtr>::Read(
    ::device::mojom::VRPose::DataView input,
    ::device::mojom::VRPosePtr* output)
{
    bool success = true;
    ::device::mojom::VRPosePtr result(::device::mojom::VRPose::New());

    result->timestamp = input.timestamp();
    if (!input.ReadOrientation(&result->orientation))
        success = false;
    if (!input.ReadPosition(&result->position))
        success = false;
    if (!input.ReadAngularvelocity(&result->angularVelocity))
        success = false;
    if (!input.ReadLinearvelocity(&result->linearVelocity))
        success = false;
    if (!input.ReadAngularacceleration(&result->angularAcceleration))
        success = false;
    if (!input.ReadLinearacceleration(&result->linearAcceleration))
        success = false;
    result->poseIndex = input.poseIndex();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::device::mojom::VRDisplayCapabilities::DataView, ::device::mojom::VRDisplayCapabilitiesPtr>::Read(
    ::device::mojom::VRDisplayCapabilities::DataView input,
    ::device::mojom::VRDisplayCapabilitiesPtr* output)
{
    bool success = true;
    ::device::mojom::VRDisplayCapabilitiesPtr result(::device::mojom::VRDisplayCapabilities::New());

    result->hasOrientation = input.hasOrientation();
    result->hasPosition = input.hasPosition();
    result->hasExternalDisplay = input.hasExternalDisplay();
    result->canPresent = input.canPresent();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::device::mojom::VREyeParameters::DataView, ::device::mojom::VREyeParametersPtr>::Read(
    ::device::mojom::VREyeParameters::DataView input,
    ::device::mojom::VREyeParametersPtr* output)
{
    bool success = true;
    ::device::mojom::VREyeParametersPtr result(::device::mojom::VREyeParameters::New());

    if (!input.ReadFieldofview(&result->fieldOfView))
        success = false;
    if (!input.ReadOffset(&result->offset))
        success = false;
    result->renderWidth = input.renderWidth();
    result->renderHeight = input.renderHeight();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::device::mojom::VRStageParameters::DataView, ::device::mojom::VRStageParametersPtr>::Read(
    ::device::mojom::VRStageParameters::DataView input,
    ::device::mojom::VRStageParametersPtr* output)
{
    bool success = true;
    ::device::mojom::VRStageParametersPtr result(::device::mojom::VRStageParameters::New());

    if (!input.ReadStandingtransform(&result->standingTransform))
        success = false;
    result->sizeX = input.sizeX();
    result->sizeZ = input.sizeZ();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::device::mojom::VRDisplayInfo::DataView, ::device::mojom::VRDisplayInfoPtr>::Read(
    ::device::mojom::VRDisplayInfo::DataView input,
    ::device::mojom::VRDisplayInfoPtr* output)
{
    bool success = true;
    ::device::mojom::VRDisplayInfoPtr result(::device::mojom::VRDisplayInfo::New());

    result->index = input.index();
    if (!input.ReadDisplayname(&result->displayName))
        success = false;
    if (!input.ReadCapabilities(&result->capabilities))
        success = false;
    if (!input.ReadStageparameters(&result->stageParameters))
        success = false;
    if (!input.ReadLefteye(&result->leftEye))
        success = false;
    if (!input.ReadRighteye(&result->rightEye))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::device::mojom::VRLayerBounds::DataView, ::device::mojom::VRLayerBoundsPtr>::Read(
    ::device::mojom::VRLayerBounds::DataView input,
    ::device::mojom::VRLayerBoundsPtr* output)
{
    bool success = true;
    ::device::mojom::VRLayerBoundsPtr result(::device::mojom::VRLayerBounds::New());

    result->left = input.left();
    result->top = input.top();
    result->width = input.width();
    result->height = input.height();
    *output = std::move(result);
    return success;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif