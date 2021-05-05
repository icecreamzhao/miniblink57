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

#include "device/gamepad/public/interfaces/gamepad.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "device/gamepad/public/interfaces/gamepad_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
namespace device {
namespace mojom { // static
    GamepadQuaternionPtr GamepadQuaternion::New()
    {
        GamepadQuaternionPtr rv;
        mojo::internal::StructHelper<GamepadQuaternion>::Initialize(&rv);
        return rv;
    }

    GamepadQuaternion::GamepadQuaternion()
        : x()
        , y()
        , z()
        , w()
    {
    }

    GamepadQuaternion::~GamepadQuaternion()
    {
    } // static
    GamepadVectorPtr GamepadVector::New()
    {
        GamepadVectorPtr rv;
        mojo::internal::StructHelper<GamepadVector>::Initialize(&rv);
        return rv;
    }

    GamepadVector::GamepadVector()
        : x()
        , y()
        , z()
    {
    }

    GamepadVector::~GamepadVector()
    {
    } // static
    GamepadButtonPtr GamepadButton::New()
    {
        GamepadButtonPtr rv;
        mojo::internal::StructHelper<GamepadButton>::Initialize(&rv);
        return rv;
    }

    GamepadButton::GamepadButton()
        : pressed()
        , touched()
        , value()
    {
    }

    GamepadButton::~GamepadButton()
    {
    } // static
    GamepadPosePtr GamepadPose::New()
    {
        GamepadPosePtr rv;
        mojo::internal::StructHelper<GamepadPose>::Initialize(&rv);
        return rv;
    }

    GamepadPose::GamepadPose()
        : orientation()
        , position()
        , angular_velocity()
        , linear_velocity()
        , angular_acceleration()
        , linear_acceleration()
    {
    }

    GamepadPose::~GamepadPose()
    {
    } // static
    GamepadPtr Gamepad::New()
    {
        GamepadPtr rv;
        mojo::internal::StructHelper<Gamepad>::Initialize(&rv);
        return rv;
    }

    Gamepad::Gamepad()
        : connected()
        , id()
        , timestamp()
        , axes()
        , buttons()
        , mapping()
        , pose()
        , hand()
        , display_id()
    {
    }

    Gamepad::~Gamepad()
    {
    }
    const char GamepadObserver::Name_[] = "device::mojom::GamepadObserver";

    GamepadObserverProxy::GamepadObserverProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void GamepadObserverProxy::GamepadConnected(
        int32_t in_index, const blink::WebGamepad& in_gamepad)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::device::mojom::internal::GamepadObserver_GamepadConnected_Params_Data);
        size += mojo::internal::PrepareToSerialize<::device::mojom::GamepadDataView>(
            in_gamepad, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kGamepadObserver_GamepadConnected_Name, size);

        auto params = ::device::mojom::internal::GamepadObserver_GamepadConnected_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->index = in_index;
        typename decltype(params->gamepad)::BaseType* gamepad_ptr;
        mojo::internal::Serialize<::device::mojom::GamepadDataView>(
            in_gamepad, builder.buffer(), &gamepad_ptr, &serialization_context);
        params->gamepad.Set(gamepad_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->gamepad.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null gamepad in GamepadObserver.GamepadConnected request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void GamepadObserverProxy::GamepadDisconnected(
        int32_t in_index, const blink::WebGamepad& in_gamepad)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::device::mojom::internal::GamepadObserver_GamepadDisconnected_Params_Data);
        size += mojo::internal::PrepareToSerialize<::device::mojom::GamepadDataView>(
            in_gamepad, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kGamepadObserver_GamepadDisconnected_Name, size);

        auto params = ::device::mojom::internal::GamepadObserver_GamepadDisconnected_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->index = in_index;
        typename decltype(params->gamepad)::BaseType* gamepad_ptr;
        mojo::internal::Serialize<::device::mojom::GamepadDataView>(
            in_gamepad, builder.buffer(), &gamepad_ptr, &serialization_context);
        params->gamepad.Set(gamepad_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->gamepad.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null gamepad in GamepadObserver.GamepadDisconnected request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool GamepadObserverStubDispatch::Accept(
        GamepadObserver* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kGamepadObserver_GamepadConnected_Name: {
            internal::GamepadObserver_GamepadConnected_Params_Data* params = reinterpret_cast<internal::GamepadObserver_GamepadConnected_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_index {};
            blink::WebGamepad p_gamepad {};
            GamepadObserver_GamepadConnected_ParamsDataView input_data_view(params,
                context);

            p_index = input_data_view.index();
            if (!input_data_view.ReadGamepad(&p_gamepad))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "GamepadObserver::GamepadConnected deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "GamepadObserver::GamepadConnected");
            mojo::internal::MessageDispatchContext context(message);
            impl->GamepadConnected(
                std::move(p_index),
                std::move(p_gamepad));
            return true;
        }
        case internal::kGamepadObserver_GamepadDisconnected_Name: {
            internal::GamepadObserver_GamepadDisconnected_Params_Data* params = reinterpret_cast<internal::GamepadObserver_GamepadDisconnected_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_index {};
            blink::WebGamepad p_gamepad {};
            GamepadObserver_GamepadDisconnected_ParamsDataView input_data_view(params,
                context);

            p_index = input_data_view.index();
            if (!input_data_view.ReadGamepad(&p_gamepad))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "GamepadObserver::GamepadDisconnected deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "GamepadObserver::GamepadDisconnected");
            mojo::internal::MessageDispatchContext context(message);
            impl->GamepadDisconnected(
                std::move(p_index),
                std::move(p_gamepad));
            return true;
        }
        }
        return false;
    }

    // static
    bool GamepadObserverStubDispatch::AcceptWithResponder(
        GamepadObserver* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kGamepadObserver_GamepadConnected_Name: {
            break;
        }
        case internal::kGamepadObserver_GamepadDisconnected_Name: {
            break;
        }
        }
        return false;
    }

    bool GamepadObserverRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "GamepadObserver RequestValidator");

        switch (message->header()->name) {
        case internal::kGamepadObserver_GamepadConnected_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::GamepadObserver_GamepadConnected_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kGamepadObserver_GamepadDisconnected_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::GamepadObserver_GamepadDisconnected_Params_Data>(
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

    const char GamepadMonitor::Name_[] = "device::mojom::GamepadMonitor";
    bool GamepadMonitor::GamepadStartPolling(mojo::ScopedSharedBufferHandle* memory_handle)
    {
        NOTREACHED();
        return false;
    }
    bool GamepadMonitor::GamepadStopPolling()
    {
        NOTREACHED();
        return false;
    }
    class GamepadMonitor_GamepadStartPolling_HandleSyncResponse
        : public mojo::MessageReceiver {
    public:
        GamepadMonitor_GamepadStartPolling_HandleSyncResponse(
            scoped_refptr<mojo::AssociatedGroupController> group_controller,
            bool* result, mojo::ScopedSharedBufferHandle* out_memory_handle)
            : serialization_context_(std::move(group_controller))
            , result_(result)
            , out_memory_handle_(out_memory_handle)
        {
            DCHECK(!*result_);
        }
        bool Accept(mojo::Message* message) override;

    private:
        mojo::internal::SerializationContext serialization_context_;
        bool* result_;
        mojo::ScopedSharedBufferHandle* out_memory_handle_;
        DISALLOW_COPY_AND_ASSIGN(GamepadMonitor_GamepadStartPolling_HandleSyncResponse);
    };
    bool GamepadMonitor_GamepadStartPolling_HandleSyncResponse::Accept(
        mojo::Message* message)
    {
        internal::GamepadMonitor_GamepadStartPolling_ResponseParams_Data* params = reinterpret_cast<internal::GamepadMonitor_GamepadStartPolling_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        mojo::ScopedSharedBufferHandle p_memory_handle {};
        GamepadMonitor_GamepadStartPolling_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_memory_handle = input_data_view.TakeMemoryHandle();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "GamepadMonitor::GamepadStartPolling response deserializer");
            return false;
        }
        *out_memory_handle_ = std::move(p_memory_handle);
        mojo::internal::SyncMessageResponseSetup::SetCurrentSyncResponseMessage(
            message);
        *result_ = true;
        return true;
    }

    class GamepadMonitor_GamepadStartPolling_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        GamepadMonitor_GamepadStartPolling_ForwardToCallback(
            const GamepadMonitor::GamepadStartPollingCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        GamepadMonitor::GamepadStartPollingCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(GamepadMonitor_GamepadStartPolling_ForwardToCallback);
    };
    bool GamepadMonitor_GamepadStartPolling_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::GamepadMonitor_GamepadStartPolling_ResponseParams_Data* params = reinterpret_cast<internal::GamepadMonitor_GamepadStartPolling_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        mojo::ScopedSharedBufferHandle p_memory_handle {};
        GamepadMonitor_GamepadStartPolling_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_memory_handle = input_data_view.TakeMemoryHandle();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "GamepadMonitor::GamepadStartPolling response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_memory_handle));
        }
        return true;
    }
    class GamepadMonitor_GamepadStopPolling_HandleSyncResponse
        : public mojo::MessageReceiver {
    public:
        GamepadMonitor_GamepadStopPolling_HandleSyncResponse(
            scoped_refptr<mojo::AssociatedGroupController> group_controller,
            bool* result)
            : serialization_context_(std::move(group_controller))
            , result_(result)
        {
            DCHECK(!*result_);
        }
        bool Accept(mojo::Message* message) override;

    private:
        mojo::internal::SerializationContext serialization_context_;
        bool* result_;
        DISALLOW_COPY_AND_ASSIGN(GamepadMonitor_GamepadStopPolling_HandleSyncResponse);
    };
    bool GamepadMonitor_GamepadStopPolling_HandleSyncResponse::Accept(
        mojo::Message* message)
    {
        internal::GamepadMonitor_GamepadStopPolling_ResponseParams_Data* params = reinterpret_cast<internal::GamepadMonitor_GamepadStopPolling_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        GamepadMonitor_GamepadStopPolling_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "GamepadMonitor::GamepadStopPolling response deserializer");
            return false;
        }
        mojo::internal::SyncMessageResponseSetup::SetCurrentSyncResponseMessage(
            message);
        *result_ = true;
        return true;
    }

    class GamepadMonitor_GamepadStopPolling_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        GamepadMonitor_GamepadStopPolling_ForwardToCallback(
            const GamepadMonitor::GamepadStopPollingCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        GamepadMonitor::GamepadStopPollingCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(GamepadMonitor_GamepadStopPolling_ForwardToCallback);
    };
    bool GamepadMonitor_GamepadStopPolling_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::GamepadMonitor_GamepadStopPolling_ResponseParams_Data* params = reinterpret_cast<internal::GamepadMonitor_GamepadStopPolling_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        GamepadMonitor_GamepadStopPolling_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "GamepadMonitor::GamepadStopPolling response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run();
        }
        return true;
    }

    GamepadMonitorProxy::GamepadMonitorProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }
    bool GamepadMonitorProxy::GamepadStartPolling(
        mojo::ScopedSharedBufferHandle* param_memory_handle)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::device::mojom::internal::GamepadMonitor_GamepadStartPolling_Params_Data);

        mojo::internal::RequestMessageBuilder builder(internal::kGamepadMonitor_GamepadStartPolling_Name, size,
            mojo::Message::kFlagIsSync);

        auto params = ::device::mojom::internal::GamepadMonitor_GamepadStartPolling_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());

        bool result = false;
        mojo::MessageReceiver* responder = new GamepadMonitor_GamepadStartPolling_HandleSyncResponse(
            group_controller_, &result, param_memory_handle);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
        return result;
    }

    void GamepadMonitorProxy::GamepadStartPolling(
        const GamepadStartPollingCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::device::mojom::internal::GamepadMonitor_GamepadStartPolling_Params_Data);
        mojo::internal::RequestMessageBuilder builder(internal::kGamepadMonitor_GamepadStartPolling_Name, size);

        auto params = ::device::mojom::internal::GamepadMonitor_GamepadStartPolling_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new GamepadMonitor_GamepadStartPolling_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    bool GamepadMonitorProxy::GamepadStopPolling()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::device::mojom::internal::GamepadMonitor_GamepadStopPolling_Params_Data);

        mojo::internal::RequestMessageBuilder builder(internal::kGamepadMonitor_GamepadStopPolling_Name, size,
            mojo::Message::kFlagIsSync);

        auto params = ::device::mojom::internal::GamepadMonitor_GamepadStopPolling_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());

        bool result = false;
        mojo::MessageReceiver* responder = new GamepadMonitor_GamepadStopPolling_HandleSyncResponse(
            group_controller_, &result);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
        return result;
    }

    void GamepadMonitorProxy::GamepadStopPolling(
        const GamepadStopPollingCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::device::mojom::internal::GamepadMonitor_GamepadStopPolling_Params_Data);
        mojo::internal::RequestMessageBuilder builder(internal::kGamepadMonitor_GamepadStopPolling_Name, size);

        auto params = ::device::mojom::internal::GamepadMonitor_GamepadStopPolling_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new GamepadMonitor_GamepadStopPolling_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void GamepadMonitorProxy::SetObserver(
        GamepadObserverPtr in_gamepad_observer)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::device::mojom::internal::GamepadMonitor_SetObserver_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kGamepadMonitor_SetObserver_Name, size);

        auto params = ::device::mojom::internal::GamepadMonitor_SetObserver_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::device::mojom::GamepadObserverPtrDataView>(
            in_gamepad_observer, &params->gamepad_observer, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->gamepad_observer),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid gamepad_observer in GamepadMonitor.SetObserver request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }
    class GamepadMonitor_GamepadStartPolling_ProxyToResponder {
    public:
        static GamepadMonitor::GamepadStartPollingCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<GamepadMonitor_GamepadStartPolling_ProxyToResponder> proxy(
                new GamepadMonitor_GamepadStartPolling_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&GamepadMonitor_GamepadStartPolling_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~GamepadMonitor_GamepadStartPolling_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "GamepadMonitor::GamepadStartPolling() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        GamepadMonitor_GamepadStartPolling_ProxyToResponder(
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
            mojo::ScopedSharedBufferHandle in_memory_handle);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(GamepadMonitor_GamepadStartPolling_ProxyToResponder);
    };

    void GamepadMonitor_GamepadStartPolling_ProxyToResponder::Run(
        mojo::ScopedSharedBufferHandle in_memory_handle)
    {
        size_t size = sizeof(::device::mojom::internal::GamepadMonitor_GamepadStartPolling_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kGamepadMonitor_GamepadStartPolling_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::device::mojom::internal::GamepadMonitor_GamepadStartPolling_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<mojo::ScopedSharedBufferHandle>(
            in_memory_handle, &params->memory_handle, &serialization_context_);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->memory_handle),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid memory_handle in GamepadMonitor.GamepadStartPolling response");
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class GamepadMonitor_GamepadStopPolling_ProxyToResponder {
    public:
        static GamepadMonitor::GamepadStopPollingCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<GamepadMonitor_GamepadStopPolling_ProxyToResponder> proxy(
                new GamepadMonitor_GamepadStopPolling_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&GamepadMonitor_GamepadStopPolling_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~GamepadMonitor_GamepadStopPolling_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "GamepadMonitor::GamepadStopPolling() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        GamepadMonitor_GamepadStopPolling_ProxyToResponder(
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

        DISALLOW_COPY_AND_ASSIGN(GamepadMonitor_GamepadStopPolling_ProxyToResponder);
    };

    void GamepadMonitor_GamepadStopPolling_ProxyToResponder::Run()
    {
        size_t size = sizeof(::device::mojom::internal::GamepadMonitor_GamepadStopPolling_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kGamepadMonitor_GamepadStopPolling_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::device::mojom::internal::GamepadMonitor_GamepadStopPolling_ResponseParams_Data::New(builder.buffer());
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

    // static
    bool GamepadMonitorStubDispatch::Accept(
        GamepadMonitor* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kGamepadMonitor_GamepadStartPolling_Name: {
            break;
        }
        case internal::kGamepadMonitor_GamepadStopPolling_Name: {
            break;
        }
        case internal::kGamepadMonitor_SetObserver_Name: {
            internal::GamepadMonitor_SetObserver_Params_Data* params = reinterpret_cast<internal::GamepadMonitor_SetObserver_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            GamepadObserverPtr p_gamepad_observer {};
            GamepadMonitor_SetObserver_ParamsDataView input_data_view(params,
                context);

            p_gamepad_observer = input_data_view.TakeGamepadObserver<decltype(p_gamepad_observer)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "GamepadMonitor::SetObserver deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "GamepadMonitor::SetObserver");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetObserver(
                std::move(p_gamepad_observer));
            return true;
        }
        }
        return false;
    }

    // static
    bool GamepadMonitorStubDispatch::AcceptWithResponder(
        GamepadMonitor* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kGamepadMonitor_GamepadStartPolling_Name: {
            internal::GamepadMonitor_GamepadStartPolling_Params_Data* params = reinterpret_cast<internal::GamepadMonitor_GamepadStartPolling_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            GamepadMonitor_GamepadStartPolling_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "GamepadMonitor::GamepadStartPolling deserializer");
                return false;
            }
            GamepadMonitor::GamepadStartPollingCallback callback = GamepadMonitor_GamepadStartPolling_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "GamepadMonitor::GamepadStartPolling");
            mojo::internal::MessageDispatchContext context(message);
            impl->GamepadStartPolling(std::move(callback));
            return true;
        }
        case internal::kGamepadMonitor_GamepadStopPolling_Name: {
            internal::GamepadMonitor_GamepadStopPolling_Params_Data* params = reinterpret_cast<internal::GamepadMonitor_GamepadStopPolling_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            GamepadMonitor_GamepadStopPolling_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "GamepadMonitor::GamepadStopPolling deserializer");
                return false;
            }
            GamepadMonitor::GamepadStopPollingCallback callback = GamepadMonitor_GamepadStopPolling_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "GamepadMonitor::GamepadStopPolling");
            mojo::internal::MessageDispatchContext context(message);
            impl->GamepadStopPolling(std::move(callback));
            return true;
        }
        case internal::kGamepadMonitor_SetObserver_Name: {
            break;
        }
        }
        return false;
    }

    bool GamepadMonitorRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "GamepadMonitor RequestValidator");

        switch (message->header()->name) {
        case internal::kGamepadMonitor_GamepadStartPolling_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::GamepadMonitor_GamepadStartPolling_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kGamepadMonitor_GamepadStopPolling_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::GamepadMonitor_GamepadStopPolling_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kGamepadMonitor_SetObserver_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::GamepadMonitor_SetObserver_Params_Data>(
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

    bool GamepadMonitorResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "GamepadMonitor ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kGamepadMonitor_GamepadStartPolling_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::GamepadMonitor_GamepadStartPolling_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kGamepadMonitor_GamepadStopPolling_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::GamepadMonitor_GamepadStopPolling_ResponseParams_Data>(
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
bool StructTraits<::device::mojom::GamepadQuaternion::DataView, ::device::mojom::GamepadQuaternionPtr>::Read(
    ::device::mojom::GamepadQuaternion::DataView input,
    ::device::mojom::GamepadQuaternionPtr* output)
{
    bool success = true;
    ::device::mojom::GamepadQuaternionPtr result(::device::mojom::GamepadQuaternion::New());

    result->x = input.x();
    result->y = input.y();
    result->z = input.z();
    result->w = input.w();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::device::mojom::GamepadVector::DataView, ::device::mojom::GamepadVectorPtr>::Read(
    ::device::mojom::GamepadVector::DataView input,
    ::device::mojom::GamepadVectorPtr* output)
{
    bool success = true;
    ::device::mojom::GamepadVectorPtr result(::device::mojom::GamepadVector::New());

    result->x = input.x();
    result->y = input.y();
    result->z = input.z();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::device::mojom::GamepadButton::DataView, ::device::mojom::GamepadButtonPtr>::Read(
    ::device::mojom::GamepadButton::DataView input,
    ::device::mojom::GamepadButtonPtr* output)
{
    bool success = true;
    ::device::mojom::GamepadButtonPtr result(::device::mojom::GamepadButton::New());

    result->pressed = input.pressed();
    result->touched = input.touched();
    result->value = input.value();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::device::mojom::GamepadPose::DataView, ::device::mojom::GamepadPosePtr>::Read(
    ::device::mojom::GamepadPose::DataView input,
    ::device::mojom::GamepadPosePtr* output)
{
    bool success = true;
    ::device::mojom::GamepadPosePtr result(::device::mojom::GamepadPose::New());

    if (!input.ReadOrientation(&result->orientation))
        success = false;
    if (!input.ReadPosition(&result->position))
        success = false;
    if (!input.ReadAngularVelocity(&result->angular_velocity))
        success = false;
    if (!input.ReadLinearVelocity(&result->linear_velocity))
        success = false;
    if (!input.ReadAngularAcceleration(&result->angular_acceleration))
        success = false;
    if (!input.ReadLinearAcceleration(&result->linear_acceleration))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::device::mojom::Gamepad::DataView, ::device::mojom::GamepadPtr>::Read(
    ::device::mojom::Gamepad::DataView input,
    ::device::mojom::GamepadPtr* output)
{
    bool success = true;
    ::device::mojom::GamepadPtr result(::device::mojom::Gamepad::New());

    result->connected = input.connected();
    if (!input.ReadId(&result->id))
        success = false;
    result->timestamp = input.timestamp();
    if (!input.ReadAxes(&result->axes))
        success = false;
    if (!input.ReadButtons(&result->buttons))
        success = false;
    if (!input.ReadMapping(&result->mapping))
        success = false;
    if (!input.ReadPose(&result->pose))
        success = false;
    if (!input.ReadHand(&result->hand))
        success = false;
    result->display_id = input.display_id();
    *output = std::move(result);
    return success;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif