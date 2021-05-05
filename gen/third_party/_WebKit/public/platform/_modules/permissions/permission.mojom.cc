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

#include "third_party/WebKit/public/platform/modules/permissions/permission.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "content/common/bluetooth/web_bluetooth_device_id_struct_traits.h"
#include "content/common/media/media_session_struct_traits.h"
#include "content/public/common/referrer_struct_traits.h"
#include "device/bluetooth/public/interfaces/uuid_struct_traits.h"
#include "ipc/ipc_message_utils.h"
#include "mojo/common/common_custom_types_struct_traits.h"
#include "mojo/common/values_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "third_party/WebKit/public/platform/ReferrerPolicyEnumTraits.h"
#include "third_party/WebKit/public/web/ConsoleMessageStructTraits.h"
#include "third_party/WebKit/public/web/WindowFeaturesStructTraits.h"
#include "ui/gfx/geometry/mojo/geometry_struct_traits.h"
#include "url/mojo/origin_struct_traits.h"
#include "url/mojo/url_gurl_struct_traits.h"
namespace blink {
namespace mojom { // static
    MidiPermissionDescriptorPtr MidiPermissionDescriptor::New()
    {
        MidiPermissionDescriptorPtr rv;
        mojo::internal::StructHelper<MidiPermissionDescriptor>::Initialize(&rv);
        return rv;
    }

    MidiPermissionDescriptor::MidiPermissionDescriptor()
        : sysex()
    {
    }

    MidiPermissionDescriptor::~MidiPermissionDescriptor()
    {
    }
    size_t MidiPermissionDescriptor::Hash(size_t seed) const
    {
        seed = mojo::internal::Hash(seed, this->sysex);
        return seed;
    } // static
    PermissionDescriptorPtr PermissionDescriptor::New()
    {
        PermissionDescriptorPtr rv;
        mojo::internal::StructHelper<PermissionDescriptor>::Initialize(&rv);
        return rv;
    }

    PermissionDescriptor::PermissionDescriptor()
        : name()
        , extension()
    {
    }

    PermissionDescriptor::~PermissionDescriptor()
    {
    } // static
    PermissionDescriptorExtensionPtr PermissionDescriptorExtension::New()
    {
        PermissionDescriptorExtensionPtr rv;
        mojo::internal::StructHelper<PermissionDescriptorExtension>::Initialize(&rv);
        return rv;
    }

    PermissionDescriptorExtension::PermissionDescriptorExtension()
    {
        // TODO(azani): Implement default values here when/if we support them.
        // TODO(azani): Set to UNKNOWN when unknown is implemented.
        SetActive(static_cast<Tag>(0));
    }

    PermissionDescriptorExtension::~PermissionDescriptorExtension()
    {
        DestroyActive();
    }

    void PermissionDescriptorExtension::set_midi(MidiPermissionDescriptorPtr midi)
    {
        SwitchActive(Tag::MIDI);

        *(data_.midi) = std::move(midi);
    }

    void PermissionDescriptorExtension::SwitchActive(Tag new_active)
    {
        if (new_active == tag_) {
            return;
        }

        DestroyActive();
        SetActive(new_active);
    }

    void PermissionDescriptorExtension::SetActive(Tag new_active)
    {
        switch (new_active) {

        case Tag::MIDI:

            data_.midi = new MidiPermissionDescriptorPtr();
            break;
        }

        tag_ = new_active;
    }

    void PermissionDescriptorExtension::DestroyActive()
    {
        switch (tag_) {

        case Tag::MIDI:

            delete data_.midi;
            break;
        }
    }
    size_t PermissionDescriptorExtension::Hash(size_t seed) const
    {
        seed = mojo::internal::HashCombine(seed, static_cast<uint32_t>(tag_));
        switch (tag_) {

        case Tag::MIDI:
            return mojo::internal::Hash(seed, data_.midi);
        default:
            NOTREACHED();
            return seed;
        }
    }
    const char PermissionObserver::Name_[] = "blink::mojom::PermissionObserver";

    PermissionObserverProxy::PermissionObserverProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void PermissionObserverProxy::OnPermissionStatusChange(
        ::blink::mojom::PermissionStatus in_status)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::PermissionObserver_OnPermissionStatusChange_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kPermissionObserver_OnPermissionStatusChange_Name, size);

        auto params = ::blink::mojom::internal::PermissionObserver_OnPermissionStatusChange_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::blink::mojom::PermissionStatus>(
            in_status, &params->status);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool PermissionObserverStubDispatch::Accept(
        PermissionObserver* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kPermissionObserver_OnPermissionStatusChange_Name: {
            internal::PermissionObserver_OnPermissionStatusChange_Params_Data* params = reinterpret_cast<internal::PermissionObserver_OnPermissionStatusChange_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::blink::mojom::PermissionStatus p_status {};
            PermissionObserver_OnPermissionStatusChange_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadStatus(&p_status))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PermissionObserver::OnPermissionStatusChange deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PermissionObserver::OnPermissionStatusChange");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnPermissionStatusChange(
                std::move(p_status));
            return true;
        }
        }
        return false;
    }

    // static
    bool PermissionObserverStubDispatch::AcceptWithResponder(
        PermissionObserver* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kPermissionObserver_OnPermissionStatusChange_Name: {
            break;
        }
        }
        return false;
    }

    bool PermissionObserverRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "PermissionObserver RequestValidator");

        switch (message->header()->name) {
        case internal::kPermissionObserver_OnPermissionStatusChange_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PermissionObserver_OnPermissionStatusChange_Params_Data>(
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

    const char PermissionService::Name_[] = "blink::mojom::PermissionService";

    class PermissionService_HasPermission_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        PermissionService_HasPermission_ForwardToCallback(
            const PermissionService::HasPermissionCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        PermissionService::HasPermissionCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(PermissionService_HasPermission_ForwardToCallback);
    };
    bool PermissionService_HasPermission_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::PermissionService_HasPermission_ResponseParams_Data* params = reinterpret_cast<internal::PermissionService_HasPermission_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::blink::mojom::PermissionStatus p_status {};
        PermissionService_HasPermission_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadStatus(&p_status))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "PermissionService::HasPermission response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_status));
        }
        return true;
    }

    class PermissionService_RequestPermission_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        PermissionService_RequestPermission_ForwardToCallback(
            const PermissionService::RequestPermissionCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        PermissionService::RequestPermissionCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(PermissionService_RequestPermission_ForwardToCallback);
    };
    bool PermissionService_RequestPermission_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::PermissionService_RequestPermission_ResponseParams_Data* params = reinterpret_cast<internal::PermissionService_RequestPermission_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::blink::mojom::PermissionStatus p_status {};
        PermissionService_RequestPermission_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadStatus(&p_status))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "PermissionService::RequestPermission response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_status));
        }
        return true;
    }

    class PermissionService_RequestPermissions_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        PermissionService_RequestPermissions_ForwardToCallback(
            const PermissionService::RequestPermissionsCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        PermissionService::RequestPermissionsCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(PermissionService_RequestPermissions_ForwardToCallback);
    };
    bool PermissionService_RequestPermissions_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::PermissionService_RequestPermissions_ResponseParams_Data* params = reinterpret_cast<internal::PermissionService_RequestPermissions_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        std::vector<::blink::mojom::PermissionStatus> p_statuses {};
        PermissionService_RequestPermissions_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadStatuses(&p_statuses))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "PermissionService::RequestPermissions response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_statuses));
        }
        return true;
    }

    class PermissionService_RevokePermission_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        PermissionService_RevokePermission_ForwardToCallback(
            const PermissionService::RevokePermissionCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        PermissionService::RevokePermissionCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(PermissionService_RevokePermission_ForwardToCallback);
    };
    bool PermissionService_RevokePermission_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::PermissionService_RevokePermission_ResponseParams_Data* params = reinterpret_cast<internal::PermissionService_RevokePermission_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::blink::mojom::PermissionStatus p_status {};
        PermissionService_RevokePermission_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadStatus(&p_status))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "PermissionService::RevokePermission response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_status));
        }
        return true;
    }

    PermissionServiceProxy::PermissionServiceProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void PermissionServiceProxy::HasPermission(
        PermissionDescriptorPtr in_permission, const url::Origin& in_origin, const HasPermissionCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::PermissionService_HasPermission_Params_Data);
        size += mojo::internal::PrepareToSerialize<::blink::mojom::PermissionDescriptorDataView>(
            in_permission, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::url::mojom::OriginDataView>(
            in_origin, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kPermissionService_HasPermission_Name, size);

        auto params = ::blink::mojom::internal::PermissionService_HasPermission_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->permission)::BaseType* permission_ptr;
        mojo::internal::Serialize<::blink::mojom::PermissionDescriptorDataView>(
            in_permission, builder.buffer(), &permission_ptr, &serialization_context);
        params->permission.Set(permission_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->permission.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null permission in PermissionService.HasPermission request");
        typename decltype(params->origin)::BaseType* origin_ptr;
        mojo::internal::Serialize<::url::mojom::OriginDataView>(
            in_origin, builder.buffer(), &origin_ptr, &serialization_context);
        params->origin.Set(origin_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->origin.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null origin in PermissionService.HasPermission request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new PermissionService_HasPermission_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void PermissionServiceProxy::RequestPermission(
        PermissionDescriptorPtr in_permission, const url::Origin& in_origin, bool in_user_gesture, const RequestPermissionCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::PermissionService_RequestPermission_Params_Data);
        size += mojo::internal::PrepareToSerialize<::blink::mojom::PermissionDescriptorDataView>(
            in_permission, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::url::mojom::OriginDataView>(
            in_origin, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kPermissionService_RequestPermission_Name, size);

        auto params = ::blink::mojom::internal::PermissionService_RequestPermission_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->permission)::BaseType* permission_ptr;
        mojo::internal::Serialize<::blink::mojom::PermissionDescriptorDataView>(
            in_permission, builder.buffer(), &permission_ptr, &serialization_context);
        params->permission.Set(permission_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->permission.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null permission in PermissionService.RequestPermission request");
        typename decltype(params->origin)::BaseType* origin_ptr;
        mojo::internal::Serialize<::url::mojom::OriginDataView>(
            in_origin, builder.buffer(), &origin_ptr, &serialization_context);
        params->origin.Set(origin_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->origin.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null origin in PermissionService.RequestPermission request");
        params->user_gesture = in_user_gesture;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new PermissionService_RequestPermission_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void PermissionServiceProxy::RequestPermissions(
        std::vector<PermissionDescriptorPtr> in_permission, const url::Origin& in_origin, bool in_user_gesture, const RequestPermissionsCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::PermissionService_RequestPermissions_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::blink::mojom::PermissionDescriptorDataView>>(
            in_permission, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::url::mojom::OriginDataView>(
            in_origin, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kPermissionService_RequestPermissions_Name, size);

        auto params = ::blink::mojom::internal::PermissionService_RequestPermissions_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->permission)::BaseType* permission_ptr;
        const mojo::internal::ContainerValidateParams permission_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::blink::mojom::PermissionDescriptorDataView>>(
            in_permission, builder.buffer(), &permission_ptr, &permission_validate_params,
            &serialization_context);
        params->permission.Set(permission_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->permission.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null permission in PermissionService.RequestPermissions request");
        typename decltype(params->origin)::BaseType* origin_ptr;
        mojo::internal::Serialize<::url::mojom::OriginDataView>(
            in_origin, builder.buffer(), &origin_ptr, &serialization_context);
        params->origin.Set(origin_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->origin.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null origin in PermissionService.RequestPermissions request");
        params->user_gesture = in_user_gesture;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new PermissionService_RequestPermissions_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void PermissionServiceProxy::RevokePermission(
        PermissionDescriptorPtr in_permission, const url::Origin& in_origin, const RevokePermissionCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::PermissionService_RevokePermission_Params_Data);
        size += mojo::internal::PrepareToSerialize<::blink::mojom::PermissionDescriptorDataView>(
            in_permission, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::url::mojom::OriginDataView>(
            in_origin, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kPermissionService_RevokePermission_Name, size);

        auto params = ::blink::mojom::internal::PermissionService_RevokePermission_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->permission)::BaseType* permission_ptr;
        mojo::internal::Serialize<::blink::mojom::PermissionDescriptorDataView>(
            in_permission, builder.buffer(), &permission_ptr, &serialization_context);
        params->permission.Set(permission_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->permission.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null permission in PermissionService.RevokePermission request");
        typename decltype(params->origin)::BaseType* origin_ptr;
        mojo::internal::Serialize<::url::mojom::OriginDataView>(
            in_origin, builder.buffer(), &origin_ptr, &serialization_context);
        params->origin.Set(origin_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->origin.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null origin in PermissionService.RevokePermission request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new PermissionService_RevokePermission_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void PermissionServiceProxy::AddPermissionObserver(
        PermissionDescriptorPtr in_permission, const url::Origin& in_origin, ::blink::mojom::PermissionStatus in_last_known_status, PermissionObserverPtr in_observer)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::blink::mojom::internal::PermissionService_AddPermissionObserver_Params_Data);
        size += mojo::internal::PrepareToSerialize<::blink::mojom::PermissionDescriptorDataView>(
            in_permission, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::url::mojom::OriginDataView>(
            in_origin, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kPermissionService_AddPermissionObserver_Name, size);

        auto params = ::blink::mojom::internal::PermissionService_AddPermissionObserver_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->permission)::BaseType* permission_ptr;
        mojo::internal::Serialize<::blink::mojom::PermissionDescriptorDataView>(
            in_permission, builder.buffer(), &permission_ptr, &serialization_context);
        params->permission.Set(permission_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->permission.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null permission in PermissionService.AddPermissionObserver request");
        typename decltype(params->origin)::BaseType* origin_ptr;
        mojo::internal::Serialize<::url::mojom::OriginDataView>(
            in_origin, builder.buffer(), &origin_ptr, &serialization_context);
        params->origin.Set(origin_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->origin.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null origin in PermissionService.AddPermissionObserver request");
        mojo::internal::Serialize<::blink::mojom::PermissionStatus>(
            in_last_known_status, &params->last_known_status);
        mojo::internal::Serialize<::blink::mojom::PermissionObserverPtrDataView>(
            in_observer, &params->observer, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->observer),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid observer in PermissionService.AddPermissionObserver request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }
    class PermissionService_HasPermission_ProxyToResponder {
    public:
        static PermissionService::HasPermissionCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<PermissionService_HasPermission_ProxyToResponder> proxy(
                new PermissionService_HasPermission_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&PermissionService_HasPermission_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~PermissionService_HasPermission_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "PermissionService::HasPermission() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        PermissionService_HasPermission_ProxyToResponder(
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
            ::blink::mojom::PermissionStatus in_status);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(PermissionService_HasPermission_ProxyToResponder);
    };

    void PermissionService_HasPermission_ProxyToResponder::Run(
        ::blink::mojom::PermissionStatus in_status)
    {
        size_t size = sizeof(::blink::mojom::internal::PermissionService_HasPermission_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kPermissionService_HasPermission_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::blink::mojom::internal::PermissionService_HasPermission_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::blink::mojom::PermissionStatus>(
            in_status, &params->status);
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class PermissionService_RequestPermission_ProxyToResponder {
    public:
        static PermissionService::RequestPermissionCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<PermissionService_RequestPermission_ProxyToResponder> proxy(
                new PermissionService_RequestPermission_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&PermissionService_RequestPermission_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~PermissionService_RequestPermission_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "PermissionService::RequestPermission() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        PermissionService_RequestPermission_ProxyToResponder(
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
            ::blink::mojom::PermissionStatus in_status);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(PermissionService_RequestPermission_ProxyToResponder);
    };

    void PermissionService_RequestPermission_ProxyToResponder::Run(
        ::blink::mojom::PermissionStatus in_status)
    {
        size_t size = sizeof(::blink::mojom::internal::PermissionService_RequestPermission_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kPermissionService_RequestPermission_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::blink::mojom::internal::PermissionService_RequestPermission_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::blink::mojom::PermissionStatus>(
            in_status, &params->status);
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class PermissionService_RequestPermissions_ProxyToResponder {
    public:
        static PermissionService::RequestPermissionsCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<PermissionService_RequestPermissions_ProxyToResponder> proxy(
                new PermissionService_RequestPermissions_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&PermissionService_RequestPermissions_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~PermissionService_RequestPermissions_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "PermissionService::RequestPermissions() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        PermissionService_RequestPermissions_ProxyToResponder(
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
            const std::vector<::blink::mojom::PermissionStatus>& in_statuses);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(PermissionService_RequestPermissions_ProxyToResponder);
    };

    void PermissionService_RequestPermissions_ProxyToResponder::Run(
        const std::vector<::blink::mojom::PermissionStatus>& in_statuses)
    {
        size_t size = sizeof(::blink::mojom::internal::PermissionService_RequestPermissions_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::blink::mojom::PermissionStatus>>(
            in_statuses, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kPermissionService_RequestPermissions_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::blink::mojom::internal::PermissionService_RequestPermissions_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->statuses)::BaseType* statuses_ptr;
        const mojo::internal::ContainerValidateParams statuses_validate_params(
            0, ::blink::mojom::internal::PermissionStatus_Data::Validate);
        mojo::internal::Serialize<mojo::ArrayDataView<::blink::mojom::PermissionStatus>>(
            in_statuses, builder.buffer(), &statuses_ptr, &statuses_validate_params,
            &serialization_context_);
        params->statuses.Set(statuses_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->statuses.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null statuses in PermissionService.RequestPermissions response");
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class PermissionService_RevokePermission_ProxyToResponder {
    public:
        static PermissionService::RevokePermissionCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<PermissionService_RevokePermission_ProxyToResponder> proxy(
                new PermissionService_RevokePermission_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&PermissionService_RevokePermission_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~PermissionService_RevokePermission_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "PermissionService::RevokePermission() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        PermissionService_RevokePermission_ProxyToResponder(
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
            ::blink::mojom::PermissionStatus in_status);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(PermissionService_RevokePermission_ProxyToResponder);
    };

    void PermissionService_RevokePermission_ProxyToResponder::Run(
        ::blink::mojom::PermissionStatus in_status)
    {
        size_t size = sizeof(::blink::mojom::internal::PermissionService_RevokePermission_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kPermissionService_RevokePermission_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::blink::mojom::internal::PermissionService_RevokePermission_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::blink::mojom::PermissionStatus>(
            in_status, &params->status);
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
    bool PermissionServiceStubDispatch::Accept(
        PermissionService* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kPermissionService_HasPermission_Name: {
            break;
        }
        case internal::kPermissionService_RequestPermission_Name: {
            break;
        }
        case internal::kPermissionService_RequestPermissions_Name: {
            break;
        }
        case internal::kPermissionService_RevokePermission_Name: {
            break;
        }
        case internal::kPermissionService_AddPermissionObserver_Name: {
            internal::PermissionService_AddPermissionObserver_Params_Data* params = reinterpret_cast<internal::PermissionService_AddPermissionObserver_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            PermissionDescriptorPtr p_permission {};
            url::Origin p_origin {};
            ::blink::mojom::PermissionStatus p_last_known_status {};
            PermissionObserverPtr p_observer {};
            PermissionService_AddPermissionObserver_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadPermission(&p_permission))
                success = false;
            if (!input_data_view.ReadOrigin(&p_origin))
                success = false;
            if (!input_data_view.ReadLastKnownStatus(&p_last_known_status))
                success = false;
            p_observer = input_data_view.TakeObserver<decltype(p_observer)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PermissionService::AddPermissionObserver deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PermissionService::AddPermissionObserver");
            mojo::internal::MessageDispatchContext context(message);
            impl->AddPermissionObserver(
                std::move(p_permission),
                std::move(p_origin),
                std::move(p_last_known_status),
                std::move(p_observer));
            return true;
        }
        }
        return false;
    }

    // static
    bool PermissionServiceStubDispatch::AcceptWithResponder(
        PermissionService* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kPermissionService_HasPermission_Name: {
            internal::PermissionService_HasPermission_Params_Data* params = reinterpret_cast<internal::PermissionService_HasPermission_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            PermissionDescriptorPtr p_permission {};
            url::Origin p_origin {};
            PermissionService_HasPermission_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadPermission(&p_permission))
                success = false;
            if (!input_data_view.ReadOrigin(&p_origin))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PermissionService::HasPermission deserializer");
                return false;
            }
            PermissionService::HasPermissionCallback callback = PermissionService_HasPermission_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PermissionService::HasPermission");
            mojo::internal::MessageDispatchContext context(message);
            impl->HasPermission(
                std::move(p_permission),
                std::move(p_origin), std::move(callback));
            return true;
        }
        case internal::kPermissionService_RequestPermission_Name: {
            internal::PermissionService_RequestPermission_Params_Data* params = reinterpret_cast<internal::PermissionService_RequestPermission_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            PermissionDescriptorPtr p_permission {};
            url::Origin p_origin {};
            bool p_user_gesture {};
            PermissionService_RequestPermission_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadPermission(&p_permission))
                success = false;
            if (!input_data_view.ReadOrigin(&p_origin))
                success = false;
            p_user_gesture = input_data_view.user_gesture();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PermissionService::RequestPermission deserializer");
                return false;
            }
            PermissionService::RequestPermissionCallback callback = PermissionService_RequestPermission_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PermissionService::RequestPermission");
            mojo::internal::MessageDispatchContext context(message);
            impl->RequestPermission(
                std::move(p_permission),
                std::move(p_origin),
                std::move(p_user_gesture), std::move(callback));
            return true;
        }
        case internal::kPermissionService_RequestPermissions_Name: {
            internal::PermissionService_RequestPermissions_Params_Data* params = reinterpret_cast<internal::PermissionService_RequestPermissions_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::vector<PermissionDescriptorPtr> p_permission {};
            url::Origin p_origin {};
            bool p_user_gesture {};
            PermissionService_RequestPermissions_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadPermission(&p_permission))
                success = false;
            if (!input_data_view.ReadOrigin(&p_origin))
                success = false;
            p_user_gesture = input_data_view.user_gesture();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PermissionService::RequestPermissions deserializer");
                return false;
            }
            PermissionService::RequestPermissionsCallback callback = PermissionService_RequestPermissions_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PermissionService::RequestPermissions");
            mojo::internal::MessageDispatchContext context(message);
            impl->RequestPermissions(
                std::move(p_permission),
                std::move(p_origin),
                std::move(p_user_gesture), std::move(callback));
            return true;
        }
        case internal::kPermissionService_RevokePermission_Name: {
            internal::PermissionService_RevokePermission_Params_Data* params = reinterpret_cast<internal::PermissionService_RevokePermission_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            PermissionDescriptorPtr p_permission {};
            url::Origin p_origin {};
            PermissionService_RevokePermission_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadPermission(&p_permission))
                success = false;
            if (!input_data_view.ReadOrigin(&p_origin))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PermissionService::RevokePermission deserializer");
                return false;
            }
            PermissionService::RevokePermissionCallback callback = PermissionService_RevokePermission_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PermissionService::RevokePermission");
            mojo::internal::MessageDispatchContext context(message);
            impl->RevokePermission(
                std::move(p_permission),
                std::move(p_origin), std::move(callback));
            return true;
        }
        case internal::kPermissionService_AddPermissionObserver_Name: {
            break;
        }
        }
        return false;
    }

    bool PermissionServiceRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "PermissionService RequestValidator");

        switch (message->header()->name) {
        case internal::kPermissionService_HasPermission_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PermissionService_HasPermission_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPermissionService_RequestPermission_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PermissionService_RequestPermission_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPermissionService_RequestPermissions_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PermissionService_RequestPermissions_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPermissionService_RevokePermission_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PermissionService_RevokePermission_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPermissionService_AddPermissionObserver_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PermissionService_AddPermissionObserver_Params_Data>(
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

    bool PermissionServiceResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "PermissionService ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kPermissionService_HasPermission_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PermissionService_HasPermission_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPermissionService_RequestPermission_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PermissionService_RequestPermission_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPermissionService_RequestPermissions_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PermissionService_RequestPermissions_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPermissionService_RevokePermission_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PermissionService_RevokePermission_ResponseParams_Data>(
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
} // namespace blink

namespace mojo {

// static
bool StructTraits<::blink::mojom::MidiPermissionDescriptor::DataView, ::blink::mojom::MidiPermissionDescriptorPtr>::Read(
    ::blink::mojom::MidiPermissionDescriptor::DataView input,
    ::blink::mojom::MidiPermissionDescriptorPtr* output)
{
    bool success = true;
    ::blink::mojom::MidiPermissionDescriptorPtr result(::blink::mojom::MidiPermissionDescriptor::New());

    result->sysex = input.sysex();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::blink::mojom::PermissionDescriptor::DataView, ::blink::mojom::PermissionDescriptorPtr>::Read(
    ::blink::mojom::PermissionDescriptor::DataView input,
    ::blink::mojom::PermissionDescriptorPtr* output)
{
    bool success = true;
    ::blink::mojom::PermissionDescriptorPtr result(::blink::mojom::PermissionDescriptor::New());

    if (!input.ReadName(&result->name))
        success = false;
    if (!input.ReadExtension(&result->extension))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool UnionTraits<::blink::mojom::PermissionDescriptorExtension::DataView, ::blink::mojom::PermissionDescriptorExtensionPtr>::Read(
    ::blink::mojom::PermissionDescriptorExtension::DataView input,
    ::blink::mojom::PermissionDescriptorExtensionPtr* output)
{
    *output = ::blink::mojom::PermissionDescriptorExtension::New();
    ::blink::mojom::PermissionDescriptorExtensionPtr& result = *output;

    internal::UnionAccessor<::blink::mojom::PermissionDescriptorExtension> result_acc(result.get());
    switch (input.tag()) {
    case ::blink::mojom::PermissionDescriptorExtension::Tag::MIDI: {
        result_acc.SwitchActive(::blink::mojom::PermissionDescriptorExtension::Tag::MIDI);
        if (!input.ReadMidi(result_acc.data()->midi))
            return false;
        break;
    }
    default:
        return false;
    }
    return true;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif