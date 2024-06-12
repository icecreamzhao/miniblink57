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

#include "media/mojo/interfaces/content_decryption_module.mojom.h"

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
namespace mojom { // static
    CdmConfigPtr CdmConfig::New()
    {
        CdmConfigPtr rv;
        mojo::internal::StructHelper<CdmConfig>::Initialize(&rv);
        return rv;
    }

    CdmConfig::CdmConfig()
        : allow_distinctive_identifier()
        , allow_persistent_state()
        , use_hw_secure_codecs()
    {
    }

    CdmConfig::~CdmConfig()
    {
    }
    size_t CdmConfig::Hash(size_t seed) const
    {
        seed = mojo::internal::Hash(seed, this->allow_distinctive_identifier);
        seed = mojo::internal::Hash(seed, this->allow_persistent_state);
        seed = mojo::internal::Hash(seed, this->use_hw_secure_codecs);
        return seed;
    } // static
    CdmPromiseResultPtr CdmPromiseResult::New()
    {
        CdmPromiseResultPtr rv;
        mojo::internal::StructHelper<CdmPromiseResult>::Initialize(&rv);
        return rv;
    }

    CdmPromiseResult::CdmPromiseResult()
        : success()
        , exception()
        , system_code()
        , error_message()
    {
    }

    CdmPromiseResult::~CdmPromiseResult()
    {
    } // static
    CdmKeyInformationPtr CdmKeyInformation::New()
    {
        CdmKeyInformationPtr rv;
        mojo::internal::StructHelper<CdmKeyInformation>::Initialize(&rv);
        return rv;
    }

    CdmKeyInformation::CdmKeyInformation()
        : key_id()
        , status()
        , system_code()
    {
    }

    CdmKeyInformation::~CdmKeyInformation()
    {
    }
    const char ContentDecryptionModule::Name_[] = "media::mojom::ContentDecryptionModule";

    class ContentDecryptionModule_Initialize_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        ContentDecryptionModule_Initialize_ForwardToCallback(
            const ContentDecryptionModule::InitializeCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        ContentDecryptionModule::InitializeCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(ContentDecryptionModule_Initialize_ForwardToCallback);
    };
    bool ContentDecryptionModule_Initialize_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::ContentDecryptionModule_Initialize_ResponseParams_Data* params = reinterpret_cast<internal::ContentDecryptionModule_Initialize_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        CdmPromiseResultPtr p_result {};
        int32_t p_cdm_id {};
        ::media::mojom::DecryptorPtr p_decryptor {};
        ContentDecryptionModule_Initialize_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadResult(&p_result))
            success = false;
        p_cdm_id = input_data_view.cdm_id();
        p_decryptor = input_data_view.TakeDecryptor<decltype(p_decryptor)>();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "ContentDecryptionModule::Initialize response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_result),
                std::move(p_cdm_id),
                std::move(p_decryptor));
        }
        return true;
    }

    class ContentDecryptionModule_SetServerCertificate_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        ContentDecryptionModule_SetServerCertificate_ForwardToCallback(
            const ContentDecryptionModule::SetServerCertificateCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        ContentDecryptionModule::SetServerCertificateCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(ContentDecryptionModule_SetServerCertificate_ForwardToCallback);
    };
    bool ContentDecryptionModule_SetServerCertificate_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::ContentDecryptionModule_SetServerCertificate_ResponseParams_Data* params = reinterpret_cast<internal::ContentDecryptionModule_SetServerCertificate_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        CdmPromiseResultPtr p_result {};
        ContentDecryptionModule_SetServerCertificate_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadResult(&p_result))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "ContentDecryptionModule::SetServerCertificate response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_result));
        }
        return true;
    }

    class ContentDecryptionModule_CreateSessionAndGenerateRequest_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        ContentDecryptionModule_CreateSessionAndGenerateRequest_ForwardToCallback(
            const ContentDecryptionModule::CreateSessionAndGenerateRequestCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        ContentDecryptionModule::CreateSessionAndGenerateRequestCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(ContentDecryptionModule_CreateSessionAndGenerateRequest_ForwardToCallback);
    };
    bool ContentDecryptionModule_CreateSessionAndGenerateRequest_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::ContentDecryptionModule_CreateSessionAndGenerateRequest_ResponseParams_Data* params = reinterpret_cast<internal::ContentDecryptionModule_CreateSessionAndGenerateRequest_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        CdmPromiseResultPtr p_result {};
        std::string p_session_id {};
        ContentDecryptionModule_CreateSessionAndGenerateRequest_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadResult(&p_result))
            success = false;
        if (!input_data_view.ReadSessionId(&p_session_id))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "ContentDecryptionModule::CreateSessionAndGenerateRequest response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_result),
                std::move(p_session_id));
        }
        return true;
    }

    class ContentDecryptionModule_LoadSession_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        ContentDecryptionModule_LoadSession_ForwardToCallback(
            const ContentDecryptionModule::LoadSessionCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        ContentDecryptionModule::LoadSessionCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(ContentDecryptionModule_LoadSession_ForwardToCallback);
    };
    bool ContentDecryptionModule_LoadSession_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::ContentDecryptionModule_LoadSession_ResponseParams_Data* params = reinterpret_cast<internal::ContentDecryptionModule_LoadSession_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        CdmPromiseResultPtr p_result {};
        std::string p_session_id {};
        ContentDecryptionModule_LoadSession_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadResult(&p_result))
            success = false;
        if (!input_data_view.ReadSessionId(&p_session_id))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "ContentDecryptionModule::LoadSession response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_result),
                std::move(p_session_id));
        }
        return true;
    }

    class ContentDecryptionModule_UpdateSession_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        ContentDecryptionModule_UpdateSession_ForwardToCallback(
            const ContentDecryptionModule::UpdateSessionCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        ContentDecryptionModule::UpdateSessionCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(ContentDecryptionModule_UpdateSession_ForwardToCallback);
    };
    bool ContentDecryptionModule_UpdateSession_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::ContentDecryptionModule_UpdateSession_ResponseParams_Data* params = reinterpret_cast<internal::ContentDecryptionModule_UpdateSession_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        CdmPromiseResultPtr p_result {};
        ContentDecryptionModule_UpdateSession_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadResult(&p_result))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "ContentDecryptionModule::UpdateSession response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_result));
        }
        return true;
    }

    class ContentDecryptionModule_CloseSession_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        ContentDecryptionModule_CloseSession_ForwardToCallback(
            const ContentDecryptionModule::CloseSessionCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        ContentDecryptionModule::CloseSessionCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(ContentDecryptionModule_CloseSession_ForwardToCallback);
    };
    bool ContentDecryptionModule_CloseSession_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::ContentDecryptionModule_CloseSession_ResponseParams_Data* params = reinterpret_cast<internal::ContentDecryptionModule_CloseSession_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        CdmPromiseResultPtr p_result {};
        ContentDecryptionModule_CloseSession_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadResult(&p_result))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "ContentDecryptionModule::CloseSession response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_result));
        }
        return true;
    }

    class ContentDecryptionModule_RemoveSession_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        ContentDecryptionModule_RemoveSession_ForwardToCallback(
            const ContentDecryptionModule::RemoveSessionCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        ContentDecryptionModule::RemoveSessionCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(ContentDecryptionModule_RemoveSession_ForwardToCallback);
    };
    bool ContentDecryptionModule_RemoveSession_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::ContentDecryptionModule_RemoveSession_ResponseParams_Data* params = reinterpret_cast<internal::ContentDecryptionModule_RemoveSession_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        CdmPromiseResultPtr p_result {};
        ContentDecryptionModule_RemoveSession_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadResult(&p_result))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "ContentDecryptionModule::RemoveSession response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_result));
        }
        return true;
    }

    ContentDecryptionModuleProxy::ContentDecryptionModuleProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void ContentDecryptionModuleProxy::SetClient(
        ContentDecryptionModuleClientPtr in_client)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::ContentDecryptionModule_SetClient_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kContentDecryptionModule_SetClient_Name, size);

        auto params = ::media::mojom::internal::ContentDecryptionModule_SetClient_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::media::mojom::ContentDecryptionModuleClientPtrDataView>(
            in_client, &params->client, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->client),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid client in ContentDecryptionModule.SetClient request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void ContentDecryptionModuleProxy::Initialize(
        const std::string& in_key_system, const std::string& in_security_origin, CdmConfigPtr in_cdm_config, const InitializeCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::ContentDecryptionModule_Initialize_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_key_system, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_security_origin, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::media::mojom::CdmConfigDataView>(
            in_cdm_config, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kContentDecryptionModule_Initialize_Name, size);

        auto params = ::media::mojom::internal::ContentDecryptionModule_Initialize_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->key_system)::BaseType* key_system_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_key_system, builder.buffer(), &key_system_ptr, &serialization_context);
        params->key_system.Set(key_system_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->key_system.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null key_system in ContentDecryptionModule.Initialize request");
        typename decltype(params->security_origin)::BaseType* security_origin_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_security_origin, builder.buffer(), &security_origin_ptr, &serialization_context);
        params->security_origin.Set(security_origin_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->security_origin.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null security_origin in ContentDecryptionModule.Initialize request");
        typename decltype(params->cdm_config)::BaseType* cdm_config_ptr;
        mojo::internal::Serialize<::media::mojom::CdmConfigDataView>(
            in_cdm_config, builder.buffer(), &cdm_config_ptr, &serialization_context);
        params->cdm_config.Set(cdm_config_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->cdm_config.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null cdm_config in ContentDecryptionModule.Initialize request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new ContentDecryptionModule_Initialize_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void ContentDecryptionModuleProxy::SetServerCertificate(
        const std::vector<uint8_t>& in_certificate_data, const SetServerCertificateCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::ContentDecryptionModule_SetServerCertificate_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_certificate_data, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kContentDecryptionModule_SetServerCertificate_Name, size);

        auto params = ::media::mojom::internal::ContentDecryptionModule_SetServerCertificate_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->certificate_data)::BaseType* certificate_data_ptr;
        const mojo::internal::ContainerValidateParams certificate_data_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_certificate_data, builder.buffer(), &certificate_data_ptr, &certificate_data_validate_params,
            &serialization_context);
        params->certificate_data.Set(certificate_data_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->certificate_data.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null certificate_data in ContentDecryptionModule.SetServerCertificate request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new ContentDecryptionModule_SetServerCertificate_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void ContentDecryptionModuleProxy::CreateSessionAndGenerateRequest(
        media::CdmSessionType in_session_type, media::EmeInitDataType in_init_data_type, const std::vector<uint8_t>& in_init_data, const CreateSessionAndGenerateRequestCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::ContentDecryptionModule_CreateSessionAndGenerateRequest_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_init_data, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kContentDecryptionModule_CreateSessionAndGenerateRequest_Name, size);

        auto params = ::media::mojom::internal::ContentDecryptionModule_CreateSessionAndGenerateRequest_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::media::mojom::ContentDecryptionModule_SessionType>(
            in_session_type, &params->session_type);
        mojo::internal::Serialize<::media::mojom::EmeInitDataType>(
            in_init_data_type, &params->init_data_type);
        typename decltype(params->init_data)::BaseType* init_data_ptr;
        const mojo::internal::ContainerValidateParams init_data_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_init_data, builder.buffer(), &init_data_ptr, &init_data_validate_params,
            &serialization_context);
        params->init_data.Set(init_data_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->init_data.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null init_data in ContentDecryptionModule.CreateSessionAndGenerateRequest request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new ContentDecryptionModule_CreateSessionAndGenerateRequest_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void ContentDecryptionModuleProxy::LoadSession(
        media::CdmSessionType in_session_type, const std::string& in_session_id, const LoadSessionCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::ContentDecryptionModule_LoadSession_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_session_id, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kContentDecryptionModule_LoadSession_Name, size);

        auto params = ::media::mojom::internal::ContentDecryptionModule_LoadSession_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::media::mojom::ContentDecryptionModule_SessionType>(
            in_session_type, &params->session_type);
        typename decltype(params->session_id)::BaseType* session_id_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_session_id, builder.buffer(), &session_id_ptr, &serialization_context);
        params->session_id.Set(session_id_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->session_id.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null session_id in ContentDecryptionModule.LoadSession request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new ContentDecryptionModule_LoadSession_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void ContentDecryptionModuleProxy::UpdateSession(
        const std::string& in_session_id, const std::vector<uint8_t>& in_response, const UpdateSessionCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::ContentDecryptionModule_UpdateSession_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_session_id, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_response, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kContentDecryptionModule_UpdateSession_Name, size);

        auto params = ::media::mojom::internal::ContentDecryptionModule_UpdateSession_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->session_id)::BaseType* session_id_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_session_id, builder.buffer(), &session_id_ptr, &serialization_context);
        params->session_id.Set(session_id_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->session_id.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null session_id in ContentDecryptionModule.UpdateSession request");
        typename decltype(params->response)::BaseType* response_ptr;
        const mojo::internal::ContainerValidateParams response_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_response, builder.buffer(), &response_ptr, &response_validate_params,
            &serialization_context);
        params->response.Set(response_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->response.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null response in ContentDecryptionModule.UpdateSession request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new ContentDecryptionModule_UpdateSession_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void ContentDecryptionModuleProxy::CloseSession(
        const std::string& in_session_id, const CloseSessionCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::ContentDecryptionModule_CloseSession_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_session_id, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kContentDecryptionModule_CloseSession_Name, size);

        auto params = ::media::mojom::internal::ContentDecryptionModule_CloseSession_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->session_id)::BaseType* session_id_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_session_id, builder.buffer(), &session_id_ptr, &serialization_context);
        params->session_id.Set(session_id_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->session_id.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null session_id in ContentDecryptionModule.CloseSession request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new ContentDecryptionModule_CloseSession_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void ContentDecryptionModuleProxy::RemoveSession(
        const std::string& in_session_id, const RemoveSessionCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::ContentDecryptionModule_RemoveSession_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_session_id, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kContentDecryptionModule_RemoveSession_Name, size);

        auto params = ::media::mojom::internal::ContentDecryptionModule_RemoveSession_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->session_id)::BaseType* session_id_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_session_id, builder.buffer(), &session_id_ptr, &serialization_context);
        params->session_id.Set(session_id_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->session_id.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null session_id in ContentDecryptionModule.RemoveSession request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new ContentDecryptionModule_RemoveSession_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    class ContentDecryptionModule_Initialize_ProxyToResponder {
    public:
        static ContentDecryptionModule::InitializeCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<ContentDecryptionModule_Initialize_ProxyToResponder> proxy(
                new ContentDecryptionModule_Initialize_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&ContentDecryptionModule_Initialize_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~ContentDecryptionModule_Initialize_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "ContentDecryptionModule::Initialize() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        ContentDecryptionModule_Initialize_ProxyToResponder(
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
            CdmPromiseResultPtr in_result, int32_t in_cdm_id, ::media::mojom::DecryptorPtr in_decryptor);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(ContentDecryptionModule_Initialize_ProxyToResponder);
    };

    void ContentDecryptionModule_Initialize_ProxyToResponder::Run(
        CdmPromiseResultPtr in_result, int32_t in_cdm_id, ::media::mojom::DecryptorPtr in_decryptor)
    {
        size_t size = sizeof(::media::mojom::internal::ContentDecryptionModule_Initialize_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<::media::mojom::CdmPromiseResultDataView>(
            in_result, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kContentDecryptionModule_Initialize_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::media::mojom::internal::ContentDecryptionModule_Initialize_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->result)::BaseType* result_ptr;
        mojo::internal::Serialize<::media::mojom::CdmPromiseResultDataView>(
            in_result, builder.buffer(), &result_ptr, &serialization_context_);
        params->result.Set(result_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->result.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null result in ContentDecryptionModule.Initialize response");
        params->cdm_id = in_cdm_id;
        mojo::internal::Serialize<::media::mojom::DecryptorPtrDataView>(
            in_decryptor, &params->decryptor, &serialization_context_);
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class ContentDecryptionModule_SetServerCertificate_ProxyToResponder {
    public:
        static ContentDecryptionModule::SetServerCertificateCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<ContentDecryptionModule_SetServerCertificate_ProxyToResponder> proxy(
                new ContentDecryptionModule_SetServerCertificate_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&ContentDecryptionModule_SetServerCertificate_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~ContentDecryptionModule_SetServerCertificate_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "ContentDecryptionModule::SetServerCertificate() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        ContentDecryptionModule_SetServerCertificate_ProxyToResponder(
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
            CdmPromiseResultPtr in_result);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(ContentDecryptionModule_SetServerCertificate_ProxyToResponder);
    };

    void ContentDecryptionModule_SetServerCertificate_ProxyToResponder::Run(
        CdmPromiseResultPtr in_result)
    {
        size_t size = sizeof(::media::mojom::internal::ContentDecryptionModule_SetServerCertificate_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<::media::mojom::CdmPromiseResultDataView>(
            in_result, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kContentDecryptionModule_SetServerCertificate_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::media::mojom::internal::ContentDecryptionModule_SetServerCertificate_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->result)::BaseType* result_ptr;
        mojo::internal::Serialize<::media::mojom::CdmPromiseResultDataView>(
            in_result, builder.buffer(), &result_ptr, &serialization_context_);
        params->result.Set(result_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->result.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null result in ContentDecryptionModule.SetServerCertificate response");
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class ContentDecryptionModule_CreateSessionAndGenerateRequest_ProxyToResponder {
    public:
        static ContentDecryptionModule::CreateSessionAndGenerateRequestCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<ContentDecryptionModule_CreateSessionAndGenerateRequest_ProxyToResponder> proxy(
                new ContentDecryptionModule_CreateSessionAndGenerateRequest_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&ContentDecryptionModule_CreateSessionAndGenerateRequest_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~ContentDecryptionModule_CreateSessionAndGenerateRequest_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "ContentDecryptionModule::CreateSessionAndGenerateRequest() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        ContentDecryptionModule_CreateSessionAndGenerateRequest_ProxyToResponder(
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
            CdmPromiseResultPtr in_result, const std::string& in_session_id);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(ContentDecryptionModule_CreateSessionAndGenerateRequest_ProxyToResponder);
    };

    void ContentDecryptionModule_CreateSessionAndGenerateRequest_ProxyToResponder::Run(
        CdmPromiseResultPtr in_result, const std::string& in_session_id)
    {
        size_t size = sizeof(::media::mojom::internal::ContentDecryptionModule_CreateSessionAndGenerateRequest_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<::media::mojom::CdmPromiseResultDataView>(
            in_result, &serialization_context_);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_session_id, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kContentDecryptionModule_CreateSessionAndGenerateRequest_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::media::mojom::internal::ContentDecryptionModule_CreateSessionAndGenerateRequest_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->result)::BaseType* result_ptr;
        mojo::internal::Serialize<::media::mojom::CdmPromiseResultDataView>(
            in_result, builder.buffer(), &result_ptr, &serialization_context_);
        params->result.Set(result_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->result.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null result in ContentDecryptionModule.CreateSessionAndGenerateRequest response");
        typename decltype(params->session_id)::BaseType* session_id_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_session_id, builder.buffer(), &session_id_ptr, &serialization_context_);
        params->session_id.Set(session_id_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->session_id.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null session_id in ContentDecryptionModule.CreateSessionAndGenerateRequest response");
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class ContentDecryptionModule_LoadSession_ProxyToResponder {
    public:
        static ContentDecryptionModule::LoadSessionCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<ContentDecryptionModule_LoadSession_ProxyToResponder> proxy(
                new ContentDecryptionModule_LoadSession_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&ContentDecryptionModule_LoadSession_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~ContentDecryptionModule_LoadSession_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "ContentDecryptionModule::LoadSession() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        ContentDecryptionModule_LoadSession_ProxyToResponder(
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
            CdmPromiseResultPtr in_result, const std::string& in_session_id);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(ContentDecryptionModule_LoadSession_ProxyToResponder);
    };

    void ContentDecryptionModule_LoadSession_ProxyToResponder::Run(
        CdmPromiseResultPtr in_result, const std::string& in_session_id)
    {
        size_t size = sizeof(::media::mojom::internal::ContentDecryptionModule_LoadSession_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<::media::mojom::CdmPromiseResultDataView>(
            in_result, &serialization_context_);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_session_id, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kContentDecryptionModule_LoadSession_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::media::mojom::internal::ContentDecryptionModule_LoadSession_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->result)::BaseType* result_ptr;
        mojo::internal::Serialize<::media::mojom::CdmPromiseResultDataView>(
            in_result, builder.buffer(), &result_ptr, &serialization_context_);
        params->result.Set(result_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->result.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null result in ContentDecryptionModule.LoadSession response");
        typename decltype(params->session_id)::BaseType* session_id_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_session_id, builder.buffer(), &session_id_ptr, &serialization_context_);
        params->session_id.Set(session_id_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->session_id.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null session_id in ContentDecryptionModule.LoadSession response");
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class ContentDecryptionModule_UpdateSession_ProxyToResponder {
    public:
        static ContentDecryptionModule::UpdateSessionCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<ContentDecryptionModule_UpdateSession_ProxyToResponder> proxy(
                new ContentDecryptionModule_UpdateSession_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&ContentDecryptionModule_UpdateSession_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~ContentDecryptionModule_UpdateSession_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "ContentDecryptionModule::UpdateSession() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        ContentDecryptionModule_UpdateSession_ProxyToResponder(
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
            CdmPromiseResultPtr in_result);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(ContentDecryptionModule_UpdateSession_ProxyToResponder);
    };

    void ContentDecryptionModule_UpdateSession_ProxyToResponder::Run(
        CdmPromiseResultPtr in_result)
    {
        size_t size = sizeof(::media::mojom::internal::ContentDecryptionModule_UpdateSession_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<::media::mojom::CdmPromiseResultDataView>(
            in_result, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kContentDecryptionModule_UpdateSession_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::media::mojom::internal::ContentDecryptionModule_UpdateSession_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->result)::BaseType* result_ptr;
        mojo::internal::Serialize<::media::mojom::CdmPromiseResultDataView>(
            in_result, builder.buffer(), &result_ptr, &serialization_context_);
        params->result.Set(result_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->result.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null result in ContentDecryptionModule.UpdateSession response");
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class ContentDecryptionModule_CloseSession_ProxyToResponder {
    public:
        static ContentDecryptionModule::CloseSessionCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<ContentDecryptionModule_CloseSession_ProxyToResponder> proxy(
                new ContentDecryptionModule_CloseSession_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&ContentDecryptionModule_CloseSession_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~ContentDecryptionModule_CloseSession_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "ContentDecryptionModule::CloseSession() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        ContentDecryptionModule_CloseSession_ProxyToResponder(
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
            CdmPromiseResultPtr in_result);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(ContentDecryptionModule_CloseSession_ProxyToResponder);
    };

    void ContentDecryptionModule_CloseSession_ProxyToResponder::Run(
        CdmPromiseResultPtr in_result)
    {
        size_t size = sizeof(::media::mojom::internal::ContentDecryptionModule_CloseSession_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<::media::mojom::CdmPromiseResultDataView>(
            in_result, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kContentDecryptionModule_CloseSession_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::media::mojom::internal::ContentDecryptionModule_CloseSession_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->result)::BaseType* result_ptr;
        mojo::internal::Serialize<::media::mojom::CdmPromiseResultDataView>(
            in_result, builder.buffer(), &result_ptr, &serialization_context_);
        params->result.Set(result_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->result.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null result in ContentDecryptionModule.CloseSession response");
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class ContentDecryptionModule_RemoveSession_ProxyToResponder {
    public:
        static ContentDecryptionModule::RemoveSessionCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<ContentDecryptionModule_RemoveSession_ProxyToResponder> proxy(
                new ContentDecryptionModule_RemoveSession_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&ContentDecryptionModule_RemoveSession_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~ContentDecryptionModule_RemoveSession_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "ContentDecryptionModule::RemoveSession() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        ContentDecryptionModule_RemoveSession_ProxyToResponder(
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
            CdmPromiseResultPtr in_result);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(ContentDecryptionModule_RemoveSession_ProxyToResponder);
    };

    void ContentDecryptionModule_RemoveSession_ProxyToResponder::Run(
        CdmPromiseResultPtr in_result)
    {
        size_t size = sizeof(::media::mojom::internal::ContentDecryptionModule_RemoveSession_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<::media::mojom::CdmPromiseResultDataView>(
            in_result, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kContentDecryptionModule_RemoveSession_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::media::mojom::internal::ContentDecryptionModule_RemoveSession_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->result)::BaseType* result_ptr;
        mojo::internal::Serialize<::media::mojom::CdmPromiseResultDataView>(
            in_result, builder.buffer(), &result_ptr, &serialization_context_);
        params->result.Set(result_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->result.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null result in ContentDecryptionModule.RemoveSession response");
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
    bool ContentDecryptionModuleStubDispatch::Accept(
        ContentDecryptionModule* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kContentDecryptionModule_SetClient_Name: {
            internal::ContentDecryptionModule_SetClient_Params_Data* params = reinterpret_cast<internal::ContentDecryptionModule_SetClient_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ContentDecryptionModuleClientPtr p_client {};
            ContentDecryptionModule_SetClient_ParamsDataView input_data_view(params,
                context);

            p_client = input_data_view.TakeClient<decltype(p_client)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "ContentDecryptionModule::SetClient deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "ContentDecryptionModule::SetClient");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetClient(
                std::move(p_client));
            return true;
        }
        case internal::kContentDecryptionModule_Initialize_Name: {
            break;
        }
        case internal::kContentDecryptionModule_SetServerCertificate_Name: {
            break;
        }
        case internal::kContentDecryptionModule_CreateSessionAndGenerateRequest_Name: {
            break;
        }
        case internal::kContentDecryptionModule_LoadSession_Name: {
            break;
        }
        case internal::kContentDecryptionModule_UpdateSession_Name: {
            break;
        }
        case internal::kContentDecryptionModule_CloseSession_Name: {
            break;
        }
        case internal::kContentDecryptionModule_RemoveSession_Name: {
            break;
        }
        }
        return false;
    }

    // static
    bool ContentDecryptionModuleStubDispatch::AcceptWithResponder(
        ContentDecryptionModule* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kContentDecryptionModule_SetClient_Name: {
            break;
        }
        case internal::kContentDecryptionModule_Initialize_Name: {
            internal::ContentDecryptionModule_Initialize_Params_Data* params = reinterpret_cast<internal::ContentDecryptionModule_Initialize_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_key_system {};
            std::string p_security_origin {};
            CdmConfigPtr p_cdm_config {};
            ContentDecryptionModule_Initialize_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadKeySystem(&p_key_system))
                success = false;
            if (!input_data_view.ReadSecurityOrigin(&p_security_origin))
                success = false;
            if (!input_data_view.ReadCdmConfig(&p_cdm_config))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "ContentDecryptionModule::Initialize deserializer");
                return false;
            }
            ContentDecryptionModule::InitializeCallback callback = ContentDecryptionModule_Initialize_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "ContentDecryptionModule::Initialize");
            mojo::internal::MessageDispatchContext context(message);
            impl->Initialize(
                std::move(p_key_system),
                std::move(p_security_origin),
                std::move(p_cdm_config), std::move(callback));
            return true;
        }
        case internal::kContentDecryptionModule_SetServerCertificate_Name: {
            internal::ContentDecryptionModule_SetServerCertificate_Params_Data* params = reinterpret_cast<internal::ContentDecryptionModule_SetServerCertificate_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::vector<uint8_t> p_certificate_data {};
            ContentDecryptionModule_SetServerCertificate_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadCertificateData(&p_certificate_data))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "ContentDecryptionModule::SetServerCertificate deserializer");
                return false;
            }
            ContentDecryptionModule::SetServerCertificateCallback callback = ContentDecryptionModule_SetServerCertificate_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "ContentDecryptionModule::SetServerCertificate");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetServerCertificate(
                std::move(p_certificate_data), std::move(callback));
            return true;
        }
        case internal::kContentDecryptionModule_CreateSessionAndGenerateRequest_Name: {
            internal::ContentDecryptionModule_CreateSessionAndGenerateRequest_Params_Data* params = reinterpret_cast<internal::ContentDecryptionModule_CreateSessionAndGenerateRequest_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            media::CdmSessionType p_session_type {};
            media::EmeInitDataType p_init_data_type {};
            std::vector<uint8_t> p_init_data {};
            ContentDecryptionModule_CreateSessionAndGenerateRequest_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadSessionType(&p_session_type))
                success = false;
            if (!input_data_view.ReadInitDataType(&p_init_data_type))
                success = false;
            if (!input_data_view.ReadInitData(&p_init_data))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "ContentDecryptionModule::CreateSessionAndGenerateRequest deserializer");
                return false;
            }
            ContentDecryptionModule::CreateSessionAndGenerateRequestCallback callback = ContentDecryptionModule_CreateSessionAndGenerateRequest_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "ContentDecryptionModule::CreateSessionAndGenerateRequest");
            mojo::internal::MessageDispatchContext context(message);
            impl->CreateSessionAndGenerateRequest(
                std::move(p_session_type),
                std::move(p_init_data_type),
                std::move(p_init_data), std::move(callback));
            return true;
        }
        case internal::kContentDecryptionModule_LoadSession_Name: {
            internal::ContentDecryptionModule_LoadSession_Params_Data* params = reinterpret_cast<internal::ContentDecryptionModule_LoadSession_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            media::CdmSessionType p_session_type {};
            std::string p_session_id {};
            ContentDecryptionModule_LoadSession_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadSessionType(&p_session_type))
                success = false;
            if (!input_data_view.ReadSessionId(&p_session_id))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "ContentDecryptionModule::LoadSession deserializer");
                return false;
            }
            ContentDecryptionModule::LoadSessionCallback callback = ContentDecryptionModule_LoadSession_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "ContentDecryptionModule::LoadSession");
            mojo::internal::MessageDispatchContext context(message);
            impl->LoadSession(
                std::move(p_session_type),
                std::move(p_session_id), std::move(callback));
            return true;
        }
        case internal::kContentDecryptionModule_UpdateSession_Name: {
            internal::ContentDecryptionModule_UpdateSession_Params_Data* params = reinterpret_cast<internal::ContentDecryptionModule_UpdateSession_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_session_id {};
            std::vector<uint8_t> p_response {};
            ContentDecryptionModule_UpdateSession_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadSessionId(&p_session_id))
                success = false;
            if (!input_data_view.ReadResponse(&p_response))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "ContentDecryptionModule::UpdateSession deserializer");
                return false;
            }
            ContentDecryptionModule::UpdateSessionCallback callback = ContentDecryptionModule_UpdateSession_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "ContentDecryptionModule::UpdateSession");
            mojo::internal::MessageDispatchContext context(message);
            impl->UpdateSession(
                std::move(p_session_id),
                std::move(p_response), std::move(callback));
            return true;
        }
        case internal::kContentDecryptionModule_CloseSession_Name: {
            internal::ContentDecryptionModule_CloseSession_Params_Data* params = reinterpret_cast<internal::ContentDecryptionModule_CloseSession_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_session_id {};
            ContentDecryptionModule_CloseSession_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadSessionId(&p_session_id))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "ContentDecryptionModule::CloseSession deserializer");
                return false;
            }
            ContentDecryptionModule::CloseSessionCallback callback = ContentDecryptionModule_CloseSession_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "ContentDecryptionModule::CloseSession");
            mojo::internal::MessageDispatchContext context(message);
            impl->CloseSession(
                std::move(p_session_id), std::move(callback));
            return true;
        }
        case internal::kContentDecryptionModule_RemoveSession_Name: {
            internal::ContentDecryptionModule_RemoveSession_Params_Data* params = reinterpret_cast<internal::ContentDecryptionModule_RemoveSession_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_session_id {};
            ContentDecryptionModule_RemoveSession_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadSessionId(&p_session_id))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "ContentDecryptionModule::RemoveSession deserializer");
                return false;
            }
            ContentDecryptionModule::RemoveSessionCallback callback = ContentDecryptionModule_RemoveSession_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "ContentDecryptionModule::RemoveSession");
            mojo::internal::MessageDispatchContext context(message);
            impl->RemoveSession(
                std::move(p_session_id), std::move(callback));
            return true;
        }
        }
        return false;
    }

    bool ContentDecryptionModuleRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "ContentDecryptionModule RequestValidator");

        switch (message->header()->name) {
        case internal::kContentDecryptionModule_SetClient_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ContentDecryptionModule_SetClient_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kContentDecryptionModule_Initialize_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ContentDecryptionModule_Initialize_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kContentDecryptionModule_SetServerCertificate_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ContentDecryptionModule_SetServerCertificate_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kContentDecryptionModule_CreateSessionAndGenerateRequest_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ContentDecryptionModule_CreateSessionAndGenerateRequest_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kContentDecryptionModule_LoadSession_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ContentDecryptionModule_LoadSession_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kContentDecryptionModule_UpdateSession_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ContentDecryptionModule_UpdateSession_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kContentDecryptionModule_CloseSession_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ContentDecryptionModule_CloseSession_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kContentDecryptionModule_RemoveSession_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ContentDecryptionModule_RemoveSession_Params_Data>(
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

    bool ContentDecryptionModuleResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "ContentDecryptionModule ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kContentDecryptionModule_Initialize_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ContentDecryptionModule_Initialize_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kContentDecryptionModule_SetServerCertificate_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ContentDecryptionModule_SetServerCertificate_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kContentDecryptionModule_CreateSessionAndGenerateRequest_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ContentDecryptionModule_CreateSessionAndGenerateRequest_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kContentDecryptionModule_LoadSession_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ContentDecryptionModule_LoadSession_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kContentDecryptionModule_UpdateSession_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ContentDecryptionModule_UpdateSession_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kContentDecryptionModule_CloseSession_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ContentDecryptionModule_CloseSession_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kContentDecryptionModule_RemoveSession_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ContentDecryptionModule_RemoveSession_ResponseParams_Data>(
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
    const char ContentDecryptionModuleClient::Name_[] = "media::mojom::ContentDecryptionModuleClient";

    ContentDecryptionModuleClientProxy::ContentDecryptionModuleClientProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void ContentDecryptionModuleClientProxy::OnSessionMessage(
        const std::string& in_session_id, media::ContentDecryptionModule::MessageType in_message_type, const std::vector<uint8_t>& in_message)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::ContentDecryptionModuleClient_OnSessionMessage_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_session_id, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_message, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kContentDecryptionModuleClient_OnSessionMessage_Name, size);

        auto params = ::media::mojom::internal::ContentDecryptionModuleClient_OnSessionMessage_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->session_id)::BaseType* session_id_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_session_id, builder.buffer(), &session_id_ptr, &serialization_context);
        params->session_id.Set(session_id_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->session_id.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null session_id in ContentDecryptionModuleClient.OnSessionMessage request");
        mojo::internal::Serialize<::media::mojom::ContentDecryptionModuleClient_MessageType>(
            in_message_type, &params->message_type);
        typename decltype(params->message)::BaseType* message_ptr;
        const mojo::internal::ContainerValidateParams message_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_message, builder.buffer(), &message_ptr, &message_validate_params,
            &serialization_context);
        params->message.Set(message_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->message.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null message in ContentDecryptionModuleClient.OnSessionMessage request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void ContentDecryptionModuleClientProxy::OnSessionClosed(
        const std::string& in_session_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::ContentDecryptionModuleClient_OnSessionClosed_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_session_id, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kContentDecryptionModuleClient_OnSessionClosed_Name, size);

        auto params = ::media::mojom::internal::ContentDecryptionModuleClient_OnSessionClosed_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->session_id)::BaseType* session_id_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_session_id, builder.buffer(), &session_id_ptr, &serialization_context);
        params->session_id.Set(session_id_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->session_id.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null session_id in ContentDecryptionModuleClient.OnSessionClosed request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void ContentDecryptionModuleClientProxy::OnSessionKeysChange(
        const std::string& in_session_id, bool in_has_additional_usable_key, std::vector<CdmKeyInformationPtr> in_keys_info)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::ContentDecryptionModuleClient_OnSessionKeysChange_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_session_id, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::media::mojom::CdmKeyInformationDataView>>(
            in_keys_info, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kContentDecryptionModuleClient_OnSessionKeysChange_Name, size);

        auto params = ::media::mojom::internal::ContentDecryptionModuleClient_OnSessionKeysChange_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->session_id)::BaseType* session_id_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_session_id, builder.buffer(), &session_id_ptr, &serialization_context);
        params->session_id.Set(session_id_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->session_id.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null session_id in ContentDecryptionModuleClient.OnSessionKeysChange request");
        params->has_additional_usable_key = in_has_additional_usable_key;
        typename decltype(params->keys_info)::BaseType* keys_info_ptr;
        const mojo::internal::ContainerValidateParams keys_info_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::media::mojom::CdmKeyInformationDataView>>(
            in_keys_info, builder.buffer(), &keys_info_ptr, &keys_info_validate_params,
            &serialization_context);
        params->keys_info.Set(keys_info_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->keys_info.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null keys_info in ContentDecryptionModuleClient.OnSessionKeysChange request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void ContentDecryptionModuleClientProxy::OnSessionExpirationUpdate(
        const std::string& in_session_id, double in_new_expiry_time_sec)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::media::mojom::internal::ContentDecryptionModuleClient_OnSessionExpirationUpdate_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_session_id, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kContentDecryptionModuleClient_OnSessionExpirationUpdate_Name, size);

        auto params = ::media::mojom::internal::ContentDecryptionModuleClient_OnSessionExpirationUpdate_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->session_id)::BaseType* session_id_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_session_id, builder.buffer(), &session_id_ptr, &serialization_context);
        params->session_id.Set(session_id_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->session_id.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null session_id in ContentDecryptionModuleClient.OnSessionExpirationUpdate request");
        params->new_expiry_time_sec = in_new_expiry_time_sec;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool ContentDecryptionModuleClientStubDispatch::Accept(
        ContentDecryptionModuleClient* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kContentDecryptionModuleClient_OnSessionMessage_Name: {
            internal::ContentDecryptionModuleClient_OnSessionMessage_Params_Data* params = reinterpret_cast<internal::ContentDecryptionModuleClient_OnSessionMessage_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_session_id {};
            media::ContentDecryptionModule::MessageType p_message_type {};
            std::vector<uint8_t> p_message {};
            ContentDecryptionModuleClient_OnSessionMessage_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadSessionId(&p_session_id))
                success = false;
            if (!input_data_view.ReadMessageType(&p_message_type))
                success = false;
            if (!input_data_view.ReadMessage(&p_message))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "ContentDecryptionModuleClient::OnSessionMessage deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "ContentDecryptionModuleClient::OnSessionMessage");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnSessionMessage(
                std::move(p_session_id),
                std::move(p_message_type),
                std::move(p_message));
            return true;
        }
        case internal::kContentDecryptionModuleClient_OnSessionClosed_Name: {
            internal::ContentDecryptionModuleClient_OnSessionClosed_Params_Data* params = reinterpret_cast<internal::ContentDecryptionModuleClient_OnSessionClosed_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_session_id {};
            ContentDecryptionModuleClient_OnSessionClosed_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadSessionId(&p_session_id))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "ContentDecryptionModuleClient::OnSessionClosed deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "ContentDecryptionModuleClient::OnSessionClosed");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnSessionClosed(
                std::move(p_session_id));
            return true;
        }
        case internal::kContentDecryptionModuleClient_OnSessionKeysChange_Name: {
            internal::ContentDecryptionModuleClient_OnSessionKeysChange_Params_Data* params = reinterpret_cast<internal::ContentDecryptionModuleClient_OnSessionKeysChange_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_session_id {};
            bool p_has_additional_usable_key {};
            std::vector<CdmKeyInformationPtr> p_keys_info {};
            ContentDecryptionModuleClient_OnSessionKeysChange_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadSessionId(&p_session_id))
                success = false;
            p_has_additional_usable_key = input_data_view.has_additional_usable_key();
            if (!input_data_view.ReadKeysInfo(&p_keys_info))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "ContentDecryptionModuleClient::OnSessionKeysChange deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "ContentDecryptionModuleClient::OnSessionKeysChange");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnSessionKeysChange(
                std::move(p_session_id),
                std::move(p_has_additional_usable_key),
                std::move(p_keys_info));
            return true;
        }
        case internal::kContentDecryptionModuleClient_OnSessionExpirationUpdate_Name: {
            internal::ContentDecryptionModuleClient_OnSessionExpirationUpdate_Params_Data* params = reinterpret_cast<internal::ContentDecryptionModuleClient_OnSessionExpirationUpdate_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_session_id {};
            double p_new_expiry_time_sec {};
            ContentDecryptionModuleClient_OnSessionExpirationUpdate_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadSessionId(&p_session_id))
                success = false;
            p_new_expiry_time_sec = input_data_view.new_expiry_time_sec();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "ContentDecryptionModuleClient::OnSessionExpirationUpdate deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "ContentDecryptionModuleClient::OnSessionExpirationUpdate");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnSessionExpirationUpdate(
                std::move(p_session_id),
                std::move(p_new_expiry_time_sec));
            return true;
        }
        }
        return false;
    }

    // static
    bool ContentDecryptionModuleClientStubDispatch::AcceptWithResponder(
        ContentDecryptionModuleClient* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kContentDecryptionModuleClient_OnSessionMessage_Name: {
            break;
        }
        case internal::kContentDecryptionModuleClient_OnSessionClosed_Name: {
            break;
        }
        case internal::kContentDecryptionModuleClient_OnSessionKeysChange_Name: {
            break;
        }
        case internal::kContentDecryptionModuleClient_OnSessionExpirationUpdate_Name: {
            break;
        }
        }
        return false;
    }

    bool ContentDecryptionModuleClientRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "ContentDecryptionModuleClient RequestValidator");

        switch (message->header()->name) {
        case internal::kContentDecryptionModuleClient_OnSessionMessage_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ContentDecryptionModuleClient_OnSessionMessage_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kContentDecryptionModuleClient_OnSessionClosed_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ContentDecryptionModuleClient_OnSessionClosed_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kContentDecryptionModuleClient_OnSessionKeysChange_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ContentDecryptionModuleClient_OnSessionKeysChange_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kContentDecryptionModuleClient_OnSessionExpirationUpdate_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::ContentDecryptionModuleClient_OnSessionExpirationUpdate_Params_Data>(
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

// static
bool StructTraits<::media::mojom::CdmConfig::DataView, ::media::mojom::CdmConfigPtr>::Read(
    ::media::mojom::CdmConfig::DataView input,
    ::media::mojom::CdmConfigPtr* output)
{
    bool success = true;
    ::media::mojom::CdmConfigPtr result(::media::mojom::CdmConfig::New());

    result->allow_distinctive_identifier = input.allow_distinctive_identifier();
    result->allow_persistent_state = input.allow_persistent_state();
    result->use_hw_secure_codecs = input.use_hw_secure_codecs();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::media::mojom::CdmPromiseResult::DataView, ::media::mojom::CdmPromiseResultPtr>::Read(
    ::media::mojom::CdmPromiseResult::DataView input,
    ::media::mojom::CdmPromiseResultPtr* output)
{
    bool success = true;
    ::media::mojom::CdmPromiseResultPtr result(::media::mojom::CdmPromiseResult::New());

    result->success = input.success();
    if (!input.ReadException(&result->exception))
        success = false;
    result->system_code = input.system_code();
    if (!input.ReadErrorMessage(&result->error_message))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::media::mojom::CdmKeyInformation::DataView, ::media::mojom::CdmKeyInformationPtr>::Read(
    ::media::mojom::CdmKeyInformation::DataView input,
    ::media::mojom::CdmKeyInformationPtr* output)
{
    bool success = true;
    ::media::mojom::CdmKeyInformationPtr result(::media::mojom::CdmKeyInformation::New());

    if (!input.ReadKeyId(&result->key_id))
        success = false;
    if (!input.ReadStatus(&result->status))
        success = false;
    result->system_code = input.system_code();
    *output = std::move(result);
    return success;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif