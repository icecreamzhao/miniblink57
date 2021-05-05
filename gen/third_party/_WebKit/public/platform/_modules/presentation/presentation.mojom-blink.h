// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_PRESENTATION_PRESENTATION_MOJOM_BLINK_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_PRESENTATION_PRESENTATION_MOJOM_BLINK_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
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
#include "third_party/WebKit/public/platform/modules/presentation/presentation.mojom-shared.h"
#include "url/mojo/url.mojom-blink.h"

#include "base/files/file.h"
#include "mojo/public/cpp/bindings/lib/wtf_hash_util.h"
#include "third_party/WebKit/Source/platform/weborigin/KURL.h"
#include "third_party/WebKit/Source/platform/weborigin/SecurityOrigin.h"
#include "third_party/WebKit/Source/wtf/HashFunctions.h"
#include "third_party/WebKit/Source/wtf/Optional.h"
#include "third_party/WebKit/Source/wtf/text/WTFString.h"
#include "third_party/WebKit/public/platform/WebCommon.h"
#include "third_party/WebKit/public/platform/WebReferrerPolicy.h"
#include "third_party/WebKit/public/platform/WebSize.h"
#include "third_party/WebKit/public/web/WebConsoleMessage.h"
#include "third_party/WebKit/public/web/WebWindowFeatures.h"

namespace blink {
namespace mojom {
    namespace blink {
        using PresentationConnectionState = PresentationConnectionState; // Alias for definition in the parent namespace.
        using PresentationConnectionCloseReason = PresentationConnectionCloseReason; // Alias for definition in the parent namespace.
        using PresentationErrorType = PresentationErrorType; // Alias for definition in the parent namespace.
        using PresentationMessageType = PresentationMessageType; // Alias for definition in the parent namespace.
        class PresentationConnection;
        using PresentationConnectionPtr = mojo::InterfacePtr<PresentationConnection>;
        using PresentationConnectionPtrInfo = mojo::InterfacePtrInfo<PresentationConnection>;
        using ThreadSafePresentationConnectionPtr = mojo::ThreadSafeInterfacePtr<PresentationConnection>;
        using PresentationConnectionRequest = mojo::InterfaceRequest<PresentationConnection>;
        using PresentationConnectionAssociatedPtr = mojo::AssociatedInterfacePtr<PresentationConnection>;
        using ThreadSafePresentationConnectionAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<PresentationConnection>;
        using PresentationConnectionAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<PresentationConnection>;
        using PresentationConnectionAssociatedRequest = mojo::AssociatedInterfaceRequest<PresentationConnection>;

        class PresentationService;
        using PresentationServicePtr = mojo::InterfacePtr<PresentationService>;
        using PresentationServicePtrInfo = mojo::InterfacePtrInfo<PresentationService>;
        using ThreadSafePresentationServicePtr = mojo::ThreadSafeInterfacePtr<PresentationService>;
        using PresentationServiceRequest = mojo::InterfaceRequest<PresentationService>;
        using PresentationServiceAssociatedPtr = mojo::AssociatedInterfacePtr<PresentationService>;
        using ThreadSafePresentationServiceAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<PresentationService>;
        using PresentationServiceAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<PresentationService>;
        using PresentationServiceAssociatedRequest = mojo::AssociatedInterfaceRequest<PresentationService>;

        class PresentationServiceClient;
        using PresentationServiceClientPtr = mojo::InterfacePtr<PresentationServiceClient>;
        using PresentationServiceClientPtrInfo = mojo::InterfacePtrInfo<PresentationServiceClient>;
        using ThreadSafePresentationServiceClientPtr = mojo::ThreadSafeInterfacePtr<PresentationServiceClient>;
        using PresentationServiceClientRequest = mojo::InterfaceRequest<PresentationServiceClient>;
        using PresentationServiceClientAssociatedPtr = mojo::AssociatedInterfacePtr<PresentationServiceClient>;
        using ThreadSafePresentationServiceClientAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<PresentationServiceClient>;
        using PresentationServiceClientAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<PresentationServiceClient>;
        using PresentationServiceClientAssociatedRequest = mojo::AssociatedInterfaceRequest<PresentationServiceClient>;

        class PresentationSessionInfo;
        using PresentationSessionInfoPtr = mojo::StructPtr<PresentationSessionInfo>;

        class PresentationError;
        using PresentationErrorPtr = mojo::InlinedStructPtr<PresentationError>;

        class ConnectionMessage;
        using ConnectionMessagePtr = mojo::StructPtr<ConnectionMessage>;

        class PresentationConnectionProxy;

        template <typename ImplRefTraits>
        class PresentationConnectionStub;

        class PresentationConnectionRequestValidator;
        class PresentationConnectionResponseValidator;

        class BLINK_PLATFORM_EXPORT PresentationConnection
            : public PresentationConnectionInterfaceBase {
        public:
            static const char Name_[];
            static constexpr uint32_t Version_ = 0;
            static constexpr bool PassesAssociatedKinds_ = false;
            static constexpr bool HasSyncMethods_ = false;

            using Proxy_ = PresentationConnectionProxy;

            template <typename ImplRefTraits>
            using Stub_ = PresentationConnectionStub<ImplRefTraits>;

            using RequestValidator_ = PresentationConnectionRequestValidator;
            using ResponseValidator_ = PresentationConnectionResponseValidator;
            enum MethodMinVersions : uint32_t {
                kOnMessageMinVersion = 0,
                kDidChangeStateMinVersion = 0,
            };
            virtual ~PresentationConnection() { }

            using OnMessageCallback = base::Callback<void(bool)>;
            virtual void OnMessage(ConnectionMessagePtr message, const OnMessageCallback& callback) = 0;

            virtual void DidChangeState(PresentationConnectionState state) = 0;
        };

        class PresentationServiceProxy;

        template <typename ImplRefTraits>
        class PresentationServiceStub;

        class PresentationServiceRequestValidator;
        class PresentationServiceResponseValidator;

        class BLINK_PLATFORM_EXPORT PresentationService
            : public PresentationServiceInterfaceBase {
        public:
            static const char Name_[];
            static constexpr uint32_t Version_ = 0;
            static constexpr bool PassesAssociatedKinds_ = false;
            static constexpr bool HasSyncMethods_ = false;

            using Proxy_ = PresentationServiceProxy;

            template <typename ImplRefTraits>
            using Stub_ = PresentationServiceStub<ImplRefTraits>;

            using RequestValidator_ = PresentationServiceRequestValidator;
            using ResponseValidator_ = PresentationServiceResponseValidator;
            enum MethodMinVersions : uint32_t {
                kSetClientMinVersion = 0,
                kSetDefaultPresentationUrlsMinVersion = 0,
                kListenForScreenAvailabilityMinVersion = 0,
                kStopListeningForScreenAvailabilityMinVersion = 0,
                kStartSessionMinVersion = 0,
                kJoinSessionMinVersion = 0,
                kSetPresentationConnectionMinVersion = 0,
                kSendConnectionMessageMinVersion = 0,
                kCloseConnectionMinVersion = 0,
                kTerminateMinVersion = 0,
                kListenForConnectionMessagesMinVersion = 0,
            };
            virtual ~PresentationService() { }

            virtual void SetClient(PresentationServiceClientPtr client) = 0;

            virtual void SetDefaultPresentationUrls(const WTF::Vector<::blink::KURL>& presentation_urls) = 0;

            virtual void ListenForScreenAvailability(const ::blink::KURL& availability_url) = 0;

            virtual void StopListeningForScreenAvailability(const ::blink::KURL& availability_url) = 0;

            using StartSessionCallback = base::Callback<void(PresentationSessionInfoPtr, PresentationErrorPtr)>;
            virtual void StartSession(const WTF::Vector<::blink::KURL>& presentation_urls, const StartSessionCallback& callback) = 0;

            using JoinSessionCallback = base::Callback<void(PresentationSessionInfoPtr, PresentationErrorPtr)>;
            virtual void JoinSession(const WTF::Vector<::blink::KURL>& presentation_urls, const WTF::String& presentation_id, const JoinSessionCallback& callback) = 0;

            virtual void SetPresentationConnection(PresentationSessionInfoPtr sessionInfo, PresentationConnectionPtr controller_connection_ptr, PresentationConnectionRequest receiver_connection_request) = 0;

            using SendConnectionMessageCallback = base::Callback<void(bool)>;
            virtual void SendConnectionMessage(PresentationSessionInfoPtr sessionInfo, ConnectionMessagePtr message_request, const SendConnectionMessageCallback& callback) = 0;

            virtual void CloseConnection(const ::blink::KURL& presentation_url, const WTF::String& presentation_id) = 0;

            virtual void Terminate(const ::blink::KURL& presentation_url, const WTF::String& presentation_id) = 0;

            virtual void ListenForConnectionMessages(PresentationSessionInfoPtr sessionInfo) = 0;
        };

        class PresentationServiceClientProxy;

        template <typename ImplRefTraits>
        class PresentationServiceClientStub;

        class PresentationServiceClientRequestValidator;

        class BLINK_PLATFORM_EXPORT PresentationServiceClient
            : public PresentationServiceClientInterfaceBase {
        public:
            static const char Name_[];
            static constexpr uint32_t Version_ = 0;
            static constexpr bool PassesAssociatedKinds_ = false;
            static constexpr bool HasSyncMethods_ = false;

            using Proxy_ = PresentationServiceClientProxy;

            template <typename ImplRefTraits>
            using Stub_ = PresentationServiceClientStub<ImplRefTraits>;

            using RequestValidator_ = PresentationServiceClientRequestValidator;
            using ResponseValidator_ = mojo::PassThroughFilter;
            enum MethodMinVersions : uint32_t {
                kOnScreenAvailabilityNotSupportedMinVersion = 0,
                kOnScreenAvailabilityUpdatedMinVersion = 0,
                kOnDefaultSessionStartedMinVersion = 0,
                kOnConnectionStateChangedMinVersion = 0,
                kOnConnectionClosedMinVersion = 0,
                kOnConnectionMessagesReceivedMinVersion = 0,
                kOnReceiverConnectionAvailableMinVersion = 0,
            };
            virtual ~PresentationServiceClient() { }

            virtual void OnScreenAvailabilityNotSupported(const ::blink::KURL& url) = 0;

            virtual void OnScreenAvailabilityUpdated(const ::blink::KURL& url, bool available) = 0;

            virtual void OnDefaultSessionStarted(PresentationSessionInfoPtr sessionInfo) = 0;

            virtual void OnConnectionStateChanged(PresentationSessionInfoPtr connection, PresentationConnectionState newState) = 0;

            virtual void OnConnectionClosed(PresentationSessionInfoPtr connection, PresentationConnectionCloseReason reason, const WTF::String& message) = 0;

            virtual void OnConnectionMessagesReceived(PresentationSessionInfoPtr sessionInfo, WTF::Vector<ConnectionMessagePtr> messages) = 0;

            virtual void OnReceiverConnectionAvailable(PresentationSessionInfoPtr sessionInfo, PresentationConnectionPtr controller_connection_ptr, PresentationConnectionRequest receiver_connection_request) = 0;
        };

        class BLINK_PLATFORM_EXPORT PresentationConnectionProxy
            : public PresentationConnection {
        public:
            explicit PresentationConnectionProxy(mojo::MessageReceiverWithResponder* receiver);
            void OnMessage(ConnectionMessagePtr message, const OnMessageCallback& callback) override;
            void DidChangeState(PresentationConnectionState state) override;

            void set_group_controller(
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
            {
                group_controller_ = std::move(group_controller);
            }

        private:
            mojo::MessageReceiverWithResponder* receiver_;
            scoped_refptr<mojo::AssociatedGroupController> group_controller_;
        };

        class BLINK_PLATFORM_EXPORT PresentationServiceProxy
            : public PresentationService {
        public:
            explicit PresentationServiceProxy(mojo::MessageReceiverWithResponder* receiver);
            void SetClient(PresentationServiceClientPtr client) override;
            void SetDefaultPresentationUrls(const WTF::Vector<::blink::KURL>& presentation_urls) override;
            void ListenForScreenAvailability(const ::blink::KURL& availability_url) override;
            void StopListeningForScreenAvailability(const ::blink::KURL& availability_url) override;
            void StartSession(const WTF::Vector<::blink::KURL>& presentation_urls, const StartSessionCallback& callback) override;
            void JoinSession(const WTF::Vector<::blink::KURL>& presentation_urls, const WTF::String& presentation_id, const JoinSessionCallback& callback) override;
            void SetPresentationConnection(PresentationSessionInfoPtr sessionInfo, PresentationConnectionPtr controller_connection_ptr, PresentationConnectionRequest receiver_connection_request) override;
            void SendConnectionMessage(PresentationSessionInfoPtr sessionInfo, ConnectionMessagePtr message_request, const SendConnectionMessageCallback& callback) override;
            void CloseConnection(const ::blink::KURL& presentation_url, const WTF::String& presentation_id) override;
            void Terminate(const ::blink::KURL& presentation_url, const WTF::String& presentation_id) override;
            void ListenForConnectionMessages(PresentationSessionInfoPtr sessionInfo) override;

            void set_group_controller(
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
            {
                group_controller_ = std::move(group_controller);
            }

        private:
            mojo::MessageReceiverWithResponder* receiver_;
            scoped_refptr<mojo::AssociatedGroupController> group_controller_;
        };

        class BLINK_PLATFORM_EXPORT PresentationServiceClientProxy
            : public PresentationServiceClient {
        public:
            explicit PresentationServiceClientProxy(mojo::MessageReceiverWithResponder* receiver);
            void OnScreenAvailabilityNotSupported(const ::blink::KURL& url) override;
            void OnScreenAvailabilityUpdated(const ::blink::KURL& url, bool available) override;
            void OnDefaultSessionStarted(PresentationSessionInfoPtr sessionInfo) override;
            void OnConnectionStateChanged(PresentationSessionInfoPtr connection, PresentationConnectionState newState) override;
            void OnConnectionClosed(PresentationSessionInfoPtr connection, PresentationConnectionCloseReason reason, const WTF::String& message) override;
            void OnConnectionMessagesReceived(PresentationSessionInfoPtr sessionInfo, WTF::Vector<ConnectionMessagePtr> messages) override;
            void OnReceiverConnectionAvailable(PresentationSessionInfoPtr sessionInfo, PresentationConnectionPtr controller_connection_ptr, PresentationConnectionRequest receiver_connection_request) override;

            void set_group_controller(
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
            {
                group_controller_ = std::move(group_controller);
            }

        private:
            mojo::MessageReceiverWithResponder* receiver_;
            scoped_refptr<mojo::AssociatedGroupController> group_controller_;
        };
        class BLINK_PLATFORM_EXPORT PresentationConnectionStubDispatch {
        public:
            static bool Accept(PresentationConnection* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message);
            static bool AcceptWithResponder(PresentationConnection* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder);
        };

        template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<PresentationConnection>>
        class PresentationConnectionStub
            : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
        public:
            using ImplPointerType = typename ImplRefTraits::PointerType;

            PresentationConnectionStub() { }
            ~PresentationConnectionStub() override { }

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
                return PresentationConnectionStubDispatch::Accept(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
            }

            bool AcceptWithResponder(
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder) override
            {
                if (ImplRefTraits::IsNull(sink_))
                    return false;
                return PresentationConnectionStubDispatch::AcceptWithResponder(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                    responder);
            }

        private:
            ImplPointerType sink_;
            mojo::internal::SerializationContext serialization_context_;
        };
        class BLINK_PLATFORM_EXPORT PresentationServiceStubDispatch {
        public:
            static bool Accept(PresentationService* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message);
            static bool AcceptWithResponder(PresentationService* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder);
        };

        template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<PresentationService>>
        class PresentationServiceStub
            : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
        public:
            using ImplPointerType = typename ImplRefTraits::PointerType;

            PresentationServiceStub() { }
            ~PresentationServiceStub() override { }

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
                return PresentationServiceStubDispatch::Accept(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
            }

            bool AcceptWithResponder(
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder) override
            {
                if (ImplRefTraits::IsNull(sink_))
                    return false;
                return PresentationServiceStubDispatch::AcceptWithResponder(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                    responder);
            }

        private:
            ImplPointerType sink_;
            mojo::internal::SerializationContext serialization_context_;
        };
        class BLINK_PLATFORM_EXPORT PresentationServiceClientStubDispatch {
        public:
            static bool Accept(PresentationServiceClient* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message);
            static bool AcceptWithResponder(PresentationServiceClient* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder);
        };

        template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<PresentationServiceClient>>
        class PresentationServiceClientStub
            : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
        public:
            using ImplPointerType = typename ImplRefTraits::PointerType;

            PresentationServiceClientStub() { }
            ~PresentationServiceClientStub() override { }

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
                return PresentationServiceClientStubDispatch::Accept(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
            }

            bool AcceptWithResponder(
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder) override
            {
                if (ImplRefTraits::IsNull(sink_))
                    return false;
                return PresentationServiceClientStubDispatch::AcceptWithResponder(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                    responder);
            }

        private:
            ImplPointerType sink_;
            mojo::internal::SerializationContext serialization_context_;
        };
        class BLINK_PLATFORM_EXPORT PresentationConnectionRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };
        class BLINK_PLATFORM_EXPORT PresentationServiceRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };
        class BLINK_PLATFORM_EXPORT PresentationServiceClientRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };
        class BLINK_PLATFORM_EXPORT PresentationConnectionResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };
        class BLINK_PLATFORM_EXPORT PresentationServiceResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };

        class BLINK_PLATFORM_EXPORT PresentationError {
        public:
            using DataView = PresentationErrorDataView;
            using Data_ = internal::PresentationError_Data;

            static PresentationErrorPtr New();

            template <typename U>
            static PresentationErrorPtr From(const U& u)
            {
                return mojo::TypeConverter<PresentationErrorPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, PresentationError>::Convert(*this);
            }

            PresentationError();
            ~PresentationError();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = PresentationErrorPtr>
            PresentationErrorPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, PresentationError>::value>::type* = nullptr>
            bool Equals(const T& other) const;
            size_t Hash(size_t seed) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    PresentationError::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    PresentationError::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            PresentationErrorType error_type;
            WTF::String message;
        };

        class BLINK_PLATFORM_EXPORT PresentationSessionInfo {
        public:
            using DataView = PresentationSessionInfoDataView;
            using Data_ = internal::PresentationSessionInfo_Data;

            static PresentationSessionInfoPtr New();

            template <typename U>
            static PresentationSessionInfoPtr From(const U& u)
            {
                return mojo::TypeConverter<PresentationSessionInfoPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, PresentationSessionInfo>::Convert(*this);
            }

            PresentationSessionInfo();
            ~PresentationSessionInfo();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = PresentationSessionInfoPtr>
            PresentationSessionInfoPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, PresentationSessionInfo>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    PresentationSessionInfo::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    PresentationSessionInfo::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            ::blink::KURL url;
            WTF::String id;
        };

        class BLINK_PLATFORM_EXPORT ConnectionMessage {
        public:
            using DataView = ConnectionMessageDataView;
            using Data_ = internal::ConnectionMessage_Data;

            static ConnectionMessagePtr New();

            template <typename U>
            static ConnectionMessagePtr From(const U& u)
            {
                return mojo::TypeConverter<ConnectionMessagePtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, ConnectionMessage>::Convert(*this);
            }

            ConnectionMessage();
            ~ConnectionMessage();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = ConnectionMessagePtr>
            ConnectionMessagePtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, ConnectionMessage>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    ConnectionMessage::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    ConnectionMessage::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            PresentationMessageType type;
            WTF::String message;
            WTF::Optional<WTF::Vector<uint8_t>> data;
        };

        template <typename StructPtrType>
        PresentationSessionInfoPtr PresentationSessionInfo::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->url = mojo::internal::Clone(url);
            rv->id = mojo::internal::Clone(id);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, PresentationSessionInfo>::value>::type*>
        bool PresentationSessionInfo::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->url, other.url))
                return false;
            if (!mojo::internal::Equals(this->id, other.id))
                return false;
            return true;
        }
        template <typename StructPtrType>
        PresentationErrorPtr PresentationError::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->error_type = mojo::internal::Clone(error_type);
            rv->message = mojo::internal::Clone(message);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, PresentationError>::value>::type*>
        bool PresentationError::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->error_type, other.error_type))
                return false;
            if (!mojo::internal::Equals(this->message, other.message))
                return false;
            return true;
        }
        template <typename StructPtrType>
        ConnectionMessagePtr ConnectionMessage::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->type = mojo::internal::Clone(type);
            rv->message = mojo::internal::Clone(message);
            rv->data = mojo::internal::Clone(data);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, ConnectionMessage>::value>::type*>
        bool ConnectionMessage::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->type, other.type))
                return false;
            if (!mojo::internal::Equals(this->message, other.message))
                return false;
            if (!mojo::internal::Equals(this->data, other.data))
                return false;
            return true;
        }

    } // namespace blink
} // namespace mojom
} // namespace blink

namespace mojo {

template <>
struct BLINK_PLATFORM_EXPORT StructTraits<::blink::mojom::blink::PresentationSessionInfo::DataView,
    ::blink::mojom::blink::PresentationSessionInfoPtr> {
    static bool IsNull(const ::blink::mojom::blink::PresentationSessionInfoPtr& input) { return !input; }
    static void SetToNull(::blink::mojom::blink::PresentationSessionInfoPtr* output) { output->reset(); }

    static const decltype(::blink::mojom::blink::PresentationSessionInfo::url)& url(
        const ::blink::mojom::blink::PresentationSessionInfoPtr& input)
    {
        return input->url;
    }

    static const decltype(::blink::mojom::blink::PresentationSessionInfo::id)& id(
        const ::blink::mojom::blink::PresentationSessionInfoPtr& input)
    {
        return input->id;
    }

    static bool Read(::blink::mojom::blink::PresentationSessionInfo::DataView input, ::blink::mojom::blink::PresentationSessionInfoPtr* output);
};

template <>
struct BLINK_PLATFORM_EXPORT StructTraits<::blink::mojom::blink::PresentationError::DataView,
    ::blink::mojom::blink::PresentationErrorPtr> {
    static bool IsNull(const ::blink::mojom::blink::PresentationErrorPtr& input) { return !input; }
    static void SetToNull(::blink::mojom::blink::PresentationErrorPtr* output) { output->reset(); }

    static decltype(::blink::mojom::blink::PresentationError::error_type) error_type(
        const ::blink::mojom::blink::PresentationErrorPtr& input)
    {
        return input->error_type;
    }

    static const decltype(::blink::mojom::blink::PresentationError::message)& message(
        const ::blink::mojom::blink::PresentationErrorPtr& input)
    {
        return input->message;
    }

    static bool Read(::blink::mojom::blink::PresentationError::DataView input, ::blink::mojom::blink::PresentationErrorPtr* output);
};

template <>
struct BLINK_PLATFORM_EXPORT StructTraits<::blink::mojom::blink::ConnectionMessage::DataView,
    ::blink::mojom::blink::ConnectionMessagePtr> {
    static bool IsNull(const ::blink::mojom::blink::ConnectionMessagePtr& input) { return !input; }
    static void SetToNull(::blink::mojom::blink::ConnectionMessagePtr* output) { output->reset(); }

    static decltype(::blink::mojom::blink::ConnectionMessage::type) type(
        const ::blink::mojom::blink::ConnectionMessagePtr& input)
    {
        return input->type;
    }

    static const decltype(::blink::mojom::blink::ConnectionMessage::message)& message(
        const ::blink::mojom::blink::ConnectionMessagePtr& input)
    {
        return input->message;
    }

    static const decltype(::blink::mojom::blink::ConnectionMessage::data)& data(
        const ::blink::mojom::blink::ConnectionMessagePtr& input)
    {
        return input->data;
    }

    static bool Read(::blink::mojom::blink::ConnectionMessage::DataView input, ::blink::mojom::blink::ConnectionMessagePtr* output);
};

} // namespace mojo

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_PRESENTATION_PRESENTATION_MOJOM_BLINK_H_