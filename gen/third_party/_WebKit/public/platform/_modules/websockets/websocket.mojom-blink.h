// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_WEBSOCKETS_WEBSOCKET_MOJOM_BLINK_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_WEBSOCKETS_WEBSOCKET_MOJOM_BLINK_H_

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
#include "third_party/WebKit/public/platform/modules/websockets/websocket.mojom-shared.h"
#include "url/mojo/origin.mojom-blink.h"
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
        using WebSocketMessageType = WebSocketMessageType; // Alias for definition in the parent namespace.
        class WebSocketClient;
        using WebSocketClientPtr = mojo::InterfacePtr<WebSocketClient>;
        using WebSocketClientPtrInfo = mojo::InterfacePtrInfo<WebSocketClient>;
        using ThreadSafeWebSocketClientPtr = mojo::ThreadSafeInterfacePtr<WebSocketClient>;
        using WebSocketClientRequest = mojo::InterfaceRequest<WebSocketClient>;
        using WebSocketClientAssociatedPtr = mojo::AssociatedInterfacePtr<WebSocketClient>;
        using ThreadSafeWebSocketClientAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<WebSocketClient>;
        using WebSocketClientAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<WebSocketClient>;
        using WebSocketClientAssociatedRequest = mojo::AssociatedInterfaceRequest<WebSocketClient>;

        class WebSocket;
        using WebSocketPtr = mojo::InterfacePtr<WebSocket>;
        using WebSocketPtrInfo = mojo::InterfacePtrInfo<WebSocket>;
        using ThreadSafeWebSocketPtr = mojo::ThreadSafeInterfacePtr<WebSocket>;
        using WebSocketRequest = mojo::InterfaceRequest<WebSocket>;
        using WebSocketAssociatedPtr = mojo::AssociatedInterfacePtr<WebSocket>;
        using ThreadSafeWebSocketAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<WebSocket>;
        using WebSocketAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<WebSocket>;
        using WebSocketAssociatedRequest = mojo::AssociatedInterfaceRequest<WebSocket>;

        class HttpHeader;
        using HttpHeaderPtr = mojo::InlinedStructPtr<HttpHeader>;

        class WebSocketHandshakeRequest;
        using WebSocketHandshakeRequestPtr = mojo::StructPtr<WebSocketHandshakeRequest>;

        class WebSocketHandshakeResponse;
        using WebSocketHandshakeResponsePtr = mojo::StructPtr<WebSocketHandshakeResponse>;

        class WebSocketClientProxy;

        template <typename ImplRefTraits>
        class WebSocketClientStub;

        class WebSocketClientRequestValidator;

        class BLINK_PLATFORM_EXPORT WebSocketClient
            : public WebSocketClientInterfaceBase {
        public:
            static const char Name_[];
            static constexpr uint32_t Version_ = 0;
            static constexpr bool PassesAssociatedKinds_ = false;
            static constexpr bool HasSyncMethods_ = false;

            using Proxy_ = WebSocketClientProxy;

            template <typename ImplRefTraits>
            using Stub_ = WebSocketClientStub<ImplRefTraits>;

            using RequestValidator_ = WebSocketClientRequestValidator;
            using ResponseValidator_ = mojo::PassThroughFilter;
            enum MethodMinVersions : uint32_t {
                kOnFailChannelMinVersion = 0,
                kOnStartOpeningHandshakeMinVersion = 0,
                kOnFinishOpeningHandshakeMinVersion = 0,
                kOnAddChannelResponseMinVersion = 0,
                kOnDataFrameMinVersion = 0,
                kOnFlowControlMinVersion = 0,
                kOnDropChannelMinVersion = 0,
                kOnClosingHandshakeMinVersion = 0,
            };
            virtual ~WebSocketClient() { }

            virtual void OnFailChannel(const WTF::String& reason) = 0;

            virtual void OnStartOpeningHandshake(WebSocketHandshakeRequestPtr request) = 0;

            virtual void OnFinishOpeningHandshake(WebSocketHandshakeResponsePtr response) = 0;

            virtual void OnAddChannelResponse(const WTF::String& selected_protocol, const WTF::String& extensions) = 0;

            virtual void OnDataFrame(bool fin, WebSocketMessageType type, const WTF::Vector<uint8_t>& data) = 0;

            virtual void OnFlowControl(int64_t quota) = 0;

            virtual void OnDropChannel(bool was_clean, uint16_t code, const WTF::String& reason) = 0;

            virtual void OnClosingHandshake() = 0;
        };

        class WebSocketProxy;

        template <typename ImplRefTraits>
        class WebSocketStub;

        class WebSocketRequestValidator;

        class BLINK_PLATFORM_EXPORT WebSocket
            : public WebSocketInterfaceBase {
        public:
            static const char Name_[];
            static constexpr uint32_t Version_ = 0;
            static constexpr bool PassesAssociatedKinds_ = false;
            static constexpr bool HasSyncMethods_ = false;

            using Proxy_ = WebSocketProxy;

            template <typename ImplRefTraits>
            using Stub_ = WebSocketStub<ImplRefTraits>;

            using RequestValidator_ = WebSocketRequestValidator;
            using ResponseValidator_ = mojo::PassThroughFilter;
            enum MethodMinVersions : uint32_t {
                kAddChannelRequestMinVersion = 0,
                kSendFrameMinVersion = 0,
                kSendFlowControlMinVersion = 0,
                kStartClosingHandshakeMinVersion = 0,
            };
            static constexpr uint32_t kInsufficientResources = 1U;
            virtual ~WebSocket() { }

            virtual void AddChannelRequest(const ::blink::KURL& url, const WTF::Vector<WTF::String>& requested_protocols, const RefPtr<::blink::SecurityOrigin>& origin, const ::blink::KURL& first_party_for_cookies, const WTF::String& user_agent_override, WebSocketClientPtr client) = 0;

            virtual void SendFrame(bool fin, WebSocketMessageType type, const WTF::Vector<uint8_t>& data) = 0;

            virtual void SendFlowControl(int64_t quota) = 0;

            virtual void StartClosingHandshake(uint16_t code, const WTF::String& reason) = 0;
        };

        class BLINK_PLATFORM_EXPORT WebSocketClientProxy
            : public WebSocketClient {
        public:
            explicit WebSocketClientProxy(mojo::MessageReceiverWithResponder* receiver);
            void OnFailChannel(const WTF::String& reason) override;
            void OnStartOpeningHandshake(WebSocketHandshakeRequestPtr request) override;
            void OnFinishOpeningHandshake(WebSocketHandshakeResponsePtr response) override;
            void OnAddChannelResponse(const WTF::String& selected_protocol, const WTF::String& extensions) override;
            void OnDataFrame(bool fin, WebSocketMessageType type, const WTF::Vector<uint8_t>& data) override;
            void OnFlowControl(int64_t quota) override;
            void OnDropChannel(bool was_clean, uint16_t code, const WTF::String& reason) override;
            void OnClosingHandshake() override;

            void set_group_controller(
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
            {
                group_controller_ = std::move(group_controller);
            }

        private:
            mojo::MessageReceiverWithResponder* receiver_;
            scoped_refptr<mojo::AssociatedGroupController> group_controller_;
        };

        class BLINK_PLATFORM_EXPORT WebSocketProxy
            : public WebSocket {
        public:
            explicit WebSocketProxy(mojo::MessageReceiverWithResponder* receiver);
            void AddChannelRequest(const ::blink::KURL& url, const WTF::Vector<WTF::String>& requested_protocols, const RefPtr<::blink::SecurityOrigin>& origin, const ::blink::KURL& first_party_for_cookies, const WTF::String& user_agent_override, WebSocketClientPtr client) override;
            void SendFrame(bool fin, WebSocketMessageType type, const WTF::Vector<uint8_t>& data) override;
            void SendFlowControl(int64_t quota) override;
            void StartClosingHandshake(uint16_t code, const WTF::String& reason) override;

            void set_group_controller(
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
            {
                group_controller_ = std::move(group_controller);
            }

        private:
            mojo::MessageReceiverWithResponder* receiver_;
            scoped_refptr<mojo::AssociatedGroupController> group_controller_;
        };
        class BLINK_PLATFORM_EXPORT WebSocketClientStubDispatch {
        public:
            static bool Accept(WebSocketClient* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message);
            static bool AcceptWithResponder(WebSocketClient* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder);
        };

        template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<WebSocketClient>>
        class WebSocketClientStub
            : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
        public:
            using ImplPointerType = typename ImplRefTraits::PointerType;

            WebSocketClientStub() { }
            ~WebSocketClientStub() override { }

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
                return WebSocketClientStubDispatch::Accept(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
            }

            bool AcceptWithResponder(
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder) override
            {
                if (ImplRefTraits::IsNull(sink_))
                    return false;
                return WebSocketClientStubDispatch::AcceptWithResponder(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                    responder);
            }

        private:
            ImplPointerType sink_;
            mojo::internal::SerializationContext serialization_context_;
        };
        class BLINK_PLATFORM_EXPORT WebSocketStubDispatch {
        public:
            static bool Accept(WebSocket* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message);
            static bool AcceptWithResponder(WebSocket* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder);
        };

        template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<WebSocket>>
        class WebSocketStub
            : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
        public:
            using ImplPointerType = typename ImplRefTraits::PointerType;

            WebSocketStub() { }
            ~WebSocketStub() override { }

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
                return WebSocketStubDispatch::Accept(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
            }

            bool AcceptWithResponder(
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder) override
            {
                if (ImplRefTraits::IsNull(sink_))
                    return false;
                return WebSocketStubDispatch::AcceptWithResponder(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                    responder);
            }

        private:
            ImplPointerType sink_;
            mojo::internal::SerializationContext serialization_context_;
        };
        class BLINK_PLATFORM_EXPORT WebSocketClientRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };
        class BLINK_PLATFORM_EXPORT WebSocketRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };

        class BLINK_PLATFORM_EXPORT HttpHeader {
        public:
            using DataView = HttpHeaderDataView;
            using Data_ = internal::HttpHeader_Data;

            static HttpHeaderPtr New();

            template <typename U>
            static HttpHeaderPtr From(const U& u)
            {
                return mojo::TypeConverter<HttpHeaderPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, HttpHeader>::Convert(*this);
            }

            HttpHeader();
            ~HttpHeader();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = HttpHeaderPtr>
            HttpHeaderPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, HttpHeader>::value>::type* = nullptr>
            bool Equals(const T& other) const;
            size_t Hash(size_t seed) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    HttpHeader::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    HttpHeader::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            WTF::String name;
            WTF::String value;
        };

        class BLINK_PLATFORM_EXPORT WebSocketHandshakeRequest {
        public:
            using DataView = WebSocketHandshakeRequestDataView;
            using Data_ = internal::WebSocketHandshakeRequest_Data;

            static WebSocketHandshakeRequestPtr New();

            template <typename U>
            static WebSocketHandshakeRequestPtr From(const U& u)
            {
                return mojo::TypeConverter<WebSocketHandshakeRequestPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, WebSocketHandshakeRequest>::Convert(*this);
            }

            WebSocketHandshakeRequest();
            ~WebSocketHandshakeRequest();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = WebSocketHandshakeRequestPtr>
            WebSocketHandshakeRequestPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, WebSocketHandshakeRequest>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    WebSocketHandshakeRequest::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    WebSocketHandshakeRequest::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            ::blink::KURL url;
            WTF::Vector<HttpHeaderPtr> headers;
            WTF::String headers_text;

        private:
            DISALLOW_COPY_AND_ASSIGN(WebSocketHandshakeRequest);
        };

        class BLINK_PLATFORM_EXPORT WebSocketHandshakeResponse {
        public:
            using DataView = WebSocketHandshakeResponseDataView;
            using Data_ = internal::WebSocketHandshakeResponse_Data;

            static WebSocketHandshakeResponsePtr New();

            template <typename U>
            static WebSocketHandshakeResponsePtr From(const U& u)
            {
                return mojo::TypeConverter<WebSocketHandshakeResponsePtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, WebSocketHandshakeResponse>::Convert(*this);
            }

            WebSocketHandshakeResponse();
            ~WebSocketHandshakeResponse();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = WebSocketHandshakeResponsePtr>
            WebSocketHandshakeResponsePtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, WebSocketHandshakeResponse>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    WebSocketHandshakeResponse::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    WebSocketHandshakeResponse::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            ::blink::KURL url;
            int32_t status_code;
            WTF::String status_text;
            WTF::Vector<HttpHeaderPtr> headers;
            WTF::String headers_text;

        private:
            DISALLOW_COPY_AND_ASSIGN(WebSocketHandshakeResponse);
        };

        template <typename StructPtrType>
        HttpHeaderPtr HttpHeader::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->name = mojo::internal::Clone(name);
            rv->value = mojo::internal::Clone(value);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, HttpHeader>::value>::type*>
        bool HttpHeader::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->name, other.name))
                return false;
            if (!mojo::internal::Equals(this->value, other.value))
                return false;
            return true;
        }
        template <typename StructPtrType>
        WebSocketHandshakeRequestPtr WebSocketHandshakeRequest::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->url = mojo::internal::Clone(url);
            rv->headers = mojo::internal::Clone(headers);
            rv->headers_text = mojo::internal::Clone(headers_text);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, WebSocketHandshakeRequest>::value>::type*>
        bool WebSocketHandshakeRequest::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->url, other.url))
                return false;
            if (!mojo::internal::Equals(this->headers, other.headers))
                return false;
            if (!mojo::internal::Equals(this->headers_text, other.headers_text))
                return false;
            return true;
        }
        template <typename StructPtrType>
        WebSocketHandshakeResponsePtr WebSocketHandshakeResponse::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->url = mojo::internal::Clone(url);
            rv->status_code = mojo::internal::Clone(status_code);
            rv->status_text = mojo::internal::Clone(status_text);
            rv->headers = mojo::internal::Clone(headers);
            rv->headers_text = mojo::internal::Clone(headers_text);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, WebSocketHandshakeResponse>::value>::type*>
        bool WebSocketHandshakeResponse::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->url, other.url))
                return false;
            if (!mojo::internal::Equals(this->status_code, other.status_code))
                return false;
            if (!mojo::internal::Equals(this->status_text, other.status_text))
                return false;
            if (!mojo::internal::Equals(this->headers, other.headers))
                return false;
            if (!mojo::internal::Equals(this->headers_text, other.headers_text))
                return false;
            return true;
        }

    } // namespace blink
} // namespace mojom
} // namespace blink

namespace mojo {

template <>
struct BLINK_PLATFORM_EXPORT StructTraits<::blink::mojom::blink::HttpHeader::DataView,
    ::blink::mojom::blink::HttpHeaderPtr> {
    static bool IsNull(const ::blink::mojom::blink::HttpHeaderPtr& input) { return !input; }
    static void SetToNull(::blink::mojom::blink::HttpHeaderPtr* output) { output->reset(); }

    static const decltype(::blink::mojom::blink::HttpHeader::name)& name(
        const ::blink::mojom::blink::HttpHeaderPtr& input)
    {
        return input->name;
    }

    static const decltype(::blink::mojom::blink::HttpHeader::value)& value(
        const ::blink::mojom::blink::HttpHeaderPtr& input)
    {
        return input->value;
    }

    static bool Read(::blink::mojom::blink::HttpHeader::DataView input, ::blink::mojom::blink::HttpHeaderPtr* output);
};

template <>
struct BLINK_PLATFORM_EXPORT StructTraits<::blink::mojom::blink::WebSocketHandshakeRequest::DataView,
    ::blink::mojom::blink::WebSocketHandshakeRequestPtr> {
    static bool IsNull(const ::blink::mojom::blink::WebSocketHandshakeRequestPtr& input) { return !input; }
    static void SetToNull(::blink::mojom::blink::WebSocketHandshakeRequestPtr* output) { output->reset(); }

    static const decltype(::blink::mojom::blink::WebSocketHandshakeRequest::url)& url(
        const ::blink::mojom::blink::WebSocketHandshakeRequestPtr& input)
    {
        return input->url;
    }

    static const decltype(::blink::mojom::blink::WebSocketHandshakeRequest::headers)& headers(
        const ::blink::mojom::blink::WebSocketHandshakeRequestPtr& input)
    {
        return input->headers;
    }

    static const decltype(::blink::mojom::blink::WebSocketHandshakeRequest::headers_text)& headers_text(
        const ::blink::mojom::blink::WebSocketHandshakeRequestPtr& input)
    {
        return input->headers_text;
    }

    static bool Read(::blink::mojom::blink::WebSocketHandshakeRequest::DataView input, ::blink::mojom::blink::WebSocketHandshakeRequestPtr* output);
};

template <>
struct BLINK_PLATFORM_EXPORT StructTraits<::blink::mojom::blink::WebSocketHandshakeResponse::DataView,
    ::blink::mojom::blink::WebSocketHandshakeResponsePtr> {
    static bool IsNull(const ::blink::mojom::blink::WebSocketHandshakeResponsePtr& input) { return !input; }
    static void SetToNull(::blink::mojom::blink::WebSocketHandshakeResponsePtr* output) { output->reset(); }

    static const decltype(::blink::mojom::blink::WebSocketHandshakeResponse::url)& url(
        const ::blink::mojom::blink::WebSocketHandshakeResponsePtr& input)
    {
        return input->url;
    }

    static decltype(::blink::mojom::blink::WebSocketHandshakeResponse::status_code) status_code(
        const ::blink::mojom::blink::WebSocketHandshakeResponsePtr& input)
    {
        return input->status_code;
    }

    static const decltype(::blink::mojom::blink::WebSocketHandshakeResponse::status_text)& status_text(
        const ::blink::mojom::blink::WebSocketHandshakeResponsePtr& input)
    {
        return input->status_text;
    }

    static const decltype(::blink::mojom::blink::WebSocketHandshakeResponse::headers)& headers(
        const ::blink::mojom::blink::WebSocketHandshakeResponsePtr& input)
    {
        return input->headers;
    }

    static const decltype(::blink::mojom::blink::WebSocketHandshakeResponse::headers_text)& headers_text(
        const ::blink::mojom::blink::WebSocketHandshakeResponsePtr& input)
    {
        return input->headers_text;
    }

    static bool Read(::blink::mojom::blink::WebSocketHandshakeResponse::DataView input, ::blink::mojom::blink::WebSocketHandshakeResponsePtr* output);
};

} // namespace mojo

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_WEBSOCKETS_WEBSOCKET_MOJOM_BLINK_H_