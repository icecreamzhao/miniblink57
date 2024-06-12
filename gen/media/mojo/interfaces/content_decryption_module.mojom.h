// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_MOJO_INTERFACES_CONTENT_DECRYPTION_MODULE_MOJOM_H_
#define MEDIA_MOJO_INTERFACES_CONTENT_DECRYPTION_MODULE_MOJOM_H_

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
#include "media/mojo/interfaces/content_decryption_module.mojom-shared.h"
#include "media/mojo/interfaces/decryptor.mojom.h"
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
#include "services/service_manager/public/cpp/identity.h"
#include "services/service_manager/public/cpp/interface_provider_spec.h"
#include "services/service_manager/public/cpp/service_info.h"
#include "ui/gfx/geometry/insets.h"
#include "ui/gfx/geometry/point.h"
#include "ui/gfx/geometry/point_f.h"
#include "ui/gfx/geometry/rect.h"
#include "ui/gfx/geometry/rect_f.h"
#include "ui/gfx/geometry/safe_integer_conversions.h"
#include "ui/gfx/geometry/size.h"
#include "ui/gfx/geometry/vector2d.h"
#include "ui/gfx/geometry/vector2d_f.h"
#include "url/gurl.h"
#include "url/mojo/url.mojom.h"
#include <string>
#include <vector>

namespace media {
namespace mojom {
    class ContentDecryptionModule;
    using ContentDecryptionModulePtr = mojo::InterfacePtr<ContentDecryptionModule>;
    using ContentDecryptionModulePtrInfo = mojo::InterfacePtrInfo<ContentDecryptionModule>;
    using ThreadSafeContentDecryptionModulePtr = mojo::ThreadSafeInterfacePtr<ContentDecryptionModule>;
    using ContentDecryptionModuleRequest = mojo::InterfaceRequest<ContentDecryptionModule>;
    using ContentDecryptionModuleAssociatedPtr = mojo::AssociatedInterfacePtr<ContentDecryptionModule>;
    using ThreadSafeContentDecryptionModuleAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<ContentDecryptionModule>;
    using ContentDecryptionModuleAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<ContentDecryptionModule>;
    using ContentDecryptionModuleAssociatedRequest = mojo::AssociatedInterfaceRequest<ContentDecryptionModule>;

    class ContentDecryptionModuleClient;
    using ContentDecryptionModuleClientPtr = mojo::InterfacePtr<ContentDecryptionModuleClient>;
    using ContentDecryptionModuleClientPtrInfo = mojo::InterfacePtrInfo<ContentDecryptionModuleClient>;
    using ThreadSafeContentDecryptionModuleClientPtr = mojo::ThreadSafeInterfacePtr<ContentDecryptionModuleClient>;
    using ContentDecryptionModuleClientRequest = mojo::InterfaceRequest<ContentDecryptionModuleClient>;
    using ContentDecryptionModuleClientAssociatedPtr = mojo::AssociatedInterfacePtr<ContentDecryptionModuleClient>;
    using ThreadSafeContentDecryptionModuleClientAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<ContentDecryptionModuleClient>;
    using ContentDecryptionModuleClientAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<ContentDecryptionModuleClient>;
    using ContentDecryptionModuleClientAssociatedRequest = mojo::AssociatedInterfaceRequest<ContentDecryptionModuleClient>;

    class CdmConfig;
    using CdmConfigPtr = mojo::InlinedStructPtr<CdmConfig>;

    class CdmPromiseResult;
    using CdmPromiseResultPtr = mojo::InlinedStructPtr<CdmPromiseResult>;

    class CdmKeyInformation;
    using CdmKeyInformationPtr = mojo::StructPtr<CdmKeyInformation>;

    class ContentDecryptionModuleProxy;

    template <typename ImplRefTraits>
    class ContentDecryptionModuleStub;

    class ContentDecryptionModuleRequestValidator;
    class ContentDecryptionModuleResponseValidator;

    class ContentDecryptionModule
        : public ContentDecryptionModuleInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = ContentDecryptionModuleProxy;

        template <typename ImplRefTraits>
        using Stub_ = ContentDecryptionModuleStub<ImplRefTraits>;

        using RequestValidator_ = ContentDecryptionModuleRequestValidator;
        using ResponseValidator_ = ContentDecryptionModuleResponseValidator;
        enum MethodMinVersions : uint32_t {
            kSetClientMinVersion = 0,
            kInitializeMinVersion = 0,
            kSetServerCertificateMinVersion = 0,
            kCreateSessionAndGenerateRequestMinVersion = 0,
            kLoadSessionMinVersion = 0,
            kUpdateSessionMinVersion = 0,
            kCloseSessionMinVersion = 0,
            kRemoveSessionMinVersion = 0,
        };
        using SessionType = ContentDecryptionModule_SessionType;
        virtual ~ContentDecryptionModule() { }

        virtual void SetClient(ContentDecryptionModuleClientPtr client) = 0;

        using InitializeCallback = base::Callback<void(CdmPromiseResultPtr, int32_t, ::media::mojom::DecryptorPtr)>;
        virtual void Initialize(const std::string& key_system, const std::string& security_origin, CdmConfigPtr cdm_config, const InitializeCallback& callback) = 0;

        using SetServerCertificateCallback = base::Callback<void(CdmPromiseResultPtr)>;
        virtual void SetServerCertificate(const std::vector<uint8_t>& certificate_data, const SetServerCertificateCallback& callback) = 0;

        using CreateSessionAndGenerateRequestCallback = base::Callback<void(CdmPromiseResultPtr, const std::string&)>;
        virtual void CreateSessionAndGenerateRequest(media::CdmSessionType session_type, media::EmeInitDataType init_data_type, const std::vector<uint8_t>& init_data, const CreateSessionAndGenerateRequestCallback& callback) = 0;

        using LoadSessionCallback = base::Callback<void(CdmPromiseResultPtr, const std::string&)>;
        virtual void LoadSession(media::CdmSessionType session_type, const std::string& session_id, const LoadSessionCallback& callback) = 0;

        using UpdateSessionCallback = base::Callback<void(CdmPromiseResultPtr)>;
        virtual void UpdateSession(const std::string& session_id, const std::vector<uint8_t>& response, const UpdateSessionCallback& callback) = 0;

        using CloseSessionCallback = base::Callback<void(CdmPromiseResultPtr)>;
        virtual void CloseSession(const std::string& session_id, const CloseSessionCallback& callback) = 0;

        using RemoveSessionCallback = base::Callback<void(CdmPromiseResultPtr)>;
        virtual void RemoveSession(const std::string& session_id, const RemoveSessionCallback& callback) = 0;
    };

    class ContentDecryptionModuleClientProxy;

    template <typename ImplRefTraits>
    class ContentDecryptionModuleClientStub;

    class ContentDecryptionModuleClientRequestValidator;

    class ContentDecryptionModuleClient
        : public ContentDecryptionModuleClientInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = ContentDecryptionModuleClientProxy;

        template <typename ImplRefTraits>
        using Stub_ = ContentDecryptionModuleClientStub<ImplRefTraits>;

        using RequestValidator_ = ContentDecryptionModuleClientRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kOnSessionMessageMinVersion = 0,
            kOnSessionClosedMinVersion = 0,
            kOnSessionKeysChangeMinVersion = 0,
            kOnSessionExpirationUpdateMinVersion = 0,
        };
        using MessageType = ContentDecryptionModuleClient_MessageType;
        virtual ~ContentDecryptionModuleClient() { }

        virtual void OnSessionMessage(const std::string& session_id, media::ContentDecryptionModule::MessageType message_type, const std::vector<uint8_t>& message) = 0;

        virtual void OnSessionClosed(const std::string& session_id) = 0;

        virtual void OnSessionKeysChange(const std::string& session_id, bool has_additional_usable_key, std::vector<CdmKeyInformationPtr> keys_info) = 0;

        virtual void OnSessionExpirationUpdate(const std::string& session_id, double new_expiry_time_sec) = 0;
    };

    class ContentDecryptionModuleProxy
        : public ContentDecryptionModule {
    public:
        explicit ContentDecryptionModuleProxy(mojo::MessageReceiverWithResponder* receiver);
        void SetClient(ContentDecryptionModuleClientPtr client) override;
        void Initialize(const std::string& key_system, const std::string& security_origin, CdmConfigPtr cdm_config, const InitializeCallback& callback) override;
        void SetServerCertificate(const std::vector<uint8_t>& certificate_data, const SetServerCertificateCallback& callback) override;
        void CreateSessionAndGenerateRequest(media::CdmSessionType session_type, media::EmeInitDataType init_data_type, const std::vector<uint8_t>& init_data, const CreateSessionAndGenerateRequestCallback& callback) override;
        void LoadSession(media::CdmSessionType session_type, const std::string& session_id, const LoadSessionCallback& callback) override;
        void UpdateSession(const std::string& session_id, const std::vector<uint8_t>& response, const UpdateSessionCallback& callback) override;
        void CloseSession(const std::string& session_id, const CloseSessionCallback& callback) override;
        void RemoveSession(const std::string& session_id, const RemoveSessionCallback& callback) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class ContentDecryptionModuleClientProxy
        : public ContentDecryptionModuleClient {
    public:
        explicit ContentDecryptionModuleClientProxy(mojo::MessageReceiverWithResponder* receiver);
        void OnSessionMessage(const std::string& session_id, media::ContentDecryptionModule::MessageType message_type, const std::vector<uint8_t>& message) override;
        void OnSessionClosed(const std::string& session_id) override;
        void OnSessionKeysChange(const std::string& session_id, bool has_additional_usable_key, std::vector<CdmKeyInformationPtr> keys_info) override;
        void OnSessionExpirationUpdate(const std::string& session_id, double new_expiry_time_sec) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class ContentDecryptionModuleStubDispatch {
    public:
        static bool Accept(ContentDecryptionModule* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(ContentDecryptionModule* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<ContentDecryptionModule>>
    class ContentDecryptionModuleStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        ContentDecryptionModuleStub() { }
        ~ContentDecryptionModuleStub() override { }

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
            return ContentDecryptionModuleStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return ContentDecryptionModuleStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class ContentDecryptionModuleClientStubDispatch {
    public:
        static bool Accept(ContentDecryptionModuleClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(ContentDecryptionModuleClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<ContentDecryptionModuleClient>>
    class ContentDecryptionModuleClientStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        ContentDecryptionModuleClientStub() { }
        ~ContentDecryptionModuleClientStub() override { }

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
            return ContentDecryptionModuleClientStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return ContentDecryptionModuleClientStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class ContentDecryptionModuleRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class ContentDecryptionModuleClientRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class ContentDecryptionModuleResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

    class CdmConfig {
    public:
        using DataView = CdmConfigDataView;
        using Data_ = internal::CdmConfig_Data;

        static CdmConfigPtr New();

        template <typename U>
        static CdmConfigPtr From(const U& u)
        {
            return mojo::TypeConverter<CdmConfigPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, CdmConfig>::Convert(*this);
        }

        CdmConfig();
        ~CdmConfig();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = CdmConfigPtr>
        CdmConfigPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, CdmConfig>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                CdmConfig::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                CdmConfig::DataView, std::vector<uint8_t>>(
                input, output);
        }

        bool allow_distinctive_identifier;
        bool allow_persistent_state;
        bool use_hw_secure_codecs;
    };

    class CdmPromiseResult {
    public:
        using DataView = CdmPromiseResultDataView;
        using Data_ = internal::CdmPromiseResult_Data;
        using Exception = CdmPromiseResult_Exception;

        static CdmPromiseResultPtr New();

        template <typename U>
        static CdmPromiseResultPtr From(const U& u)
        {
            return mojo::TypeConverter<CdmPromiseResultPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, CdmPromiseResult>::Convert(*this);
        }

        CdmPromiseResult();
        ~CdmPromiseResult();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = CdmPromiseResultPtr>
        CdmPromiseResultPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, CdmPromiseResult>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                CdmPromiseResult::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                CdmPromiseResult::DataView, std::vector<uint8_t>>(
                input, output);
        }

        bool success;
        media::CdmPromise::Exception exception;
        uint32_t system_code;
        std::string error_message;
    };

    class CdmKeyInformation {
    public:
        using DataView = CdmKeyInformationDataView;
        using Data_ = internal::CdmKeyInformation_Data;
        using KeyStatus = CdmKeyInformation_KeyStatus;

        static CdmKeyInformationPtr New();

        template <typename U>
        static CdmKeyInformationPtr From(const U& u)
        {
            return mojo::TypeConverter<CdmKeyInformationPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, CdmKeyInformation>::Convert(*this);
        }

        CdmKeyInformation();
        ~CdmKeyInformation();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = CdmKeyInformationPtr>
        CdmKeyInformationPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, CdmKeyInformation>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                CdmKeyInformation::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                CdmKeyInformation::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::vector<uint8_t> key_id;
        media::CdmKeyInformation::KeyStatus status;
        uint32_t system_code;
    };

    template <typename StructPtrType>
    CdmConfigPtr CdmConfig::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->allow_distinctive_identifier = mojo::internal::Clone(allow_distinctive_identifier);
        rv->allow_persistent_state = mojo::internal::Clone(allow_persistent_state);
        rv->use_hw_secure_codecs = mojo::internal::Clone(use_hw_secure_codecs);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, CdmConfig>::value>::type*>
    bool CdmConfig::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->allow_distinctive_identifier, other.allow_distinctive_identifier))
            return false;
        if (!mojo::internal::Equals(this->allow_persistent_state, other.allow_persistent_state))
            return false;
        if (!mojo::internal::Equals(this->use_hw_secure_codecs, other.use_hw_secure_codecs))
            return false;
        return true;
    }
    template <typename StructPtrType>
    CdmPromiseResultPtr CdmPromiseResult::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->success = mojo::internal::Clone(success);
        rv->exception = mojo::internal::Clone(exception);
        rv->system_code = mojo::internal::Clone(system_code);
        rv->error_message = mojo::internal::Clone(error_message);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, CdmPromiseResult>::value>::type*>
    bool CdmPromiseResult::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->success, other.success))
            return false;
        if (!mojo::internal::Equals(this->exception, other.exception))
            return false;
        if (!mojo::internal::Equals(this->system_code, other.system_code))
            return false;
        if (!mojo::internal::Equals(this->error_message, other.error_message))
            return false;
        return true;
    }
    template <typename StructPtrType>
    CdmKeyInformationPtr CdmKeyInformation::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->key_id = mojo::internal::Clone(key_id);
        rv->status = mojo::internal::Clone(status);
        rv->system_code = mojo::internal::Clone(system_code);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, CdmKeyInformation>::value>::type*>
    bool CdmKeyInformation::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->key_id, other.key_id))
            return false;
        if (!mojo::internal::Equals(this->status, other.status))
            return false;
        if (!mojo::internal::Equals(this->system_code, other.system_code))
            return false;
        return true;
    }

} // namespace mojom
} // namespace media

namespace mojo {

template <>
struct StructTraits<::media::mojom::CdmConfig::DataView,
    ::media::mojom::CdmConfigPtr> {
    static bool IsNull(const ::media::mojom::CdmConfigPtr& input) { return !input; }
    static void SetToNull(::media::mojom::CdmConfigPtr* output) { output->reset(); }

    static decltype(::media::mojom::CdmConfig::allow_distinctive_identifier) allow_distinctive_identifier(
        const ::media::mojom::CdmConfigPtr& input)
    {
        return input->allow_distinctive_identifier;
    }

    static decltype(::media::mojom::CdmConfig::allow_persistent_state) allow_persistent_state(
        const ::media::mojom::CdmConfigPtr& input)
    {
        return input->allow_persistent_state;
    }

    static decltype(::media::mojom::CdmConfig::use_hw_secure_codecs) use_hw_secure_codecs(
        const ::media::mojom::CdmConfigPtr& input)
    {
        return input->use_hw_secure_codecs;
    }

    static bool Read(::media::mojom::CdmConfig::DataView input, ::media::mojom::CdmConfigPtr* output);
};

template <>
struct StructTraits<::media::mojom::CdmPromiseResult::DataView,
    ::media::mojom::CdmPromiseResultPtr> {
    static bool IsNull(const ::media::mojom::CdmPromiseResultPtr& input) { return !input; }
    static void SetToNull(::media::mojom::CdmPromiseResultPtr* output) { output->reset(); }

    static decltype(::media::mojom::CdmPromiseResult::success) success(
        const ::media::mojom::CdmPromiseResultPtr& input)
    {
        return input->success;
    }

    static decltype(::media::mojom::CdmPromiseResult::exception) exception(
        const ::media::mojom::CdmPromiseResultPtr& input)
    {
        return input->exception;
    }

    static decltype(::media::mojom::CdmPromiseResult::system_code) system_code(
        const ::media::mojom::CdmPromiseResultPtr& input)
    {
        return input->system_code;
    }

    static const decltype(::media::mojom::CdmPromiseResult::error_message)& error_message(
        const ::media::mojom::CdmPromiseResultPtr& input)
    {
        return input->error_message;
    }

    static bool Read(::media::mojom::CdmPromiseResult::DataView input, ::media::mojom::CdmPromiseResultPtr* output);
};

template <>
struct StructTraits<::media::mojom::CdmKeyInformation::DataView,
    ::media::mojom::CdmKeyInformationPtr> {
    static bool IsNull(const ::media::mojom::CdmKeyInformationPtr& input) { return !input; }
    static void SetToNull(::media::mojom::CdmKeyInformationPtr* output) { output->reset(); }

    static const decltype(::media::mojom::CdmKeyInformation::key_id)& key_id(
        const ::media::mojom::CdmKeyInformationPtr& input)
    {
        return input->key_id;
    }

    static decltype(::media::mojom::CdmKeyInformation::status) status(
        const ::media::mojom::CdmKeyInformationPtr& input)
    {
        return input->status;
    }

    static decltype(::media::mojom::CdmKeyInformation::system_code) system_code(
        const ::media::mojom::CdmKeyInformationPtr& input)
    {
        return input->system_code;
    }

    static bool Read(::media::mojom::CdmKeyInformation::DataView input, ::media::mojom::CdmKeyInformationPtr* output);
};

} // namespace mojo

#endif // MEDIA_MOJO_INTERFACES_CONTENT_DECRYPTION_MODULE_MOJOM_H_