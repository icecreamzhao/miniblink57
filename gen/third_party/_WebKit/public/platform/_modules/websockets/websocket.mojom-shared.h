// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_WEBSOCKETS_WEBSOCKET_MOJOM_SHARED_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_WEBSOCKETS_WEBSOCKET_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "third_party/WebKit/public/platform/modules/websockets/websocket.mojom-shared-internal.h"
#include "url/mojo/origin.mojom-shared.h"
#include "url/mojo/url.mojom-shared.h"

namespace blink {
namespace mojom {
    class HttpHeaderDataView;

    class WebSocketHandshakeRequestDataView;

    class WebSocketHandshakeResponseDataView;

} // namespace mojom
} // namespace blink

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::blink::mojom::HttpHeaderDataView> {
        using Data = ::blink::mojom::internal::HttpHeader_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::blink::mojom::WebSocketHandshakeRequestDataView> {
        using Data = ::blink::mojom::internal::WebSocketHandshakeRequest_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::blink::mojom::WebSocketHandshakeResponseDataView> {
        using Data = ::blink::mojom::internal::WebSocketHandshakeResponse_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace blink {
namespace mojom {

    enum class WebSocketMessageType : int32_t {
        CONTINUATION,
        TEXT,
        BINARY,
        LAST = WebSocketMessageType::BINARY,
    };

    inline std::ostream& operator<<(std::ostream& os, WebSocketMessageType value)
    {
        switch (value) {
        case WebSocketMessageType::CONTINUATION:
            return os << "WebSocketMessageType::CONTINUATION";
        case WebSocketMessageType::TEXT:
            return os << "WebSocketMessageType::TEXT";
        case WebSocketMessageType::BINARY:
            return os << "WebSocketMessageType::{BINARY, LAST}";
        default:
            return os << "Unknown WebSocketMessageType value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(WebSocketMessageType value)
    {
        return internal::WebSocketMessageType_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    // Interface base classes. They are used for type safety check.
    class WebSocketClientInterfaceBase {
    };

    using WebSocketClientPtrDataView = mojo::InterfacePtrDataView<WebSocketClientInterfaceBase>;
    using WebSocketClientRequestDataView = mojo::InterfaceRequestDataView<WebSocketClientInterfaceBase>;
    using WebSocketClientAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<WebSocketClientInterfaceBase>;
    using WebSocketClientAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<WebSocketClientInterfaceBase>;
    class WebSocketInterfaceBase {
    };

    using WebSocketPtrDataView = mojo::InterfacePtrDataView<WebSocketInterfaceBase>;
    using WebSocketRequestDataView = mojo::InterfaceRequestDataView<WebSocketInterfaceBase>;
    using WebSocketAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<WebSocketInterfaceBase>;
    using WebSocketAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<WebSocketInterfaceBase>;
    class HttpHeaderDataView {
    public:
        HttpHeaderDataView() { }

        HttpHeaderDataView(
            internal::HttpHeader_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetNameDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadName(UserType* output)
        {
            auto* pointer = data_->name.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetValueDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadValue(UserType* output)
        {
            auto* pointer = data_->value.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::HttpHeader_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WebSocketHandshakeRequestDataView {
    public:
        WebSocketHandshakeRequestDataView() { }

        WebSocketHandshakeRequestDataView(
            internal::WebSocketHandshakeRequest_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetUrlDataView(
            ::url::mojom::UrlDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadUrl(UserType* output)
        {
            auto* pointer = data_->url.Get();
            return mojo::internal::Deserialize<::url::mojom::UrlDataView>(
                pointer, output, context_);
        }
        inline void GetHeadersDataView(
            mojo::ArrayDataView<HttpHeaderDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadHeaders(UserType* output)
        {
            auto* pointer = data_->headers.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::blink::mojom::HttpHeaderDataView>>(
                pointer, output, context_);
        }
        inline void GetHeadersTextDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadHeadersText(UserType* output)
        {
            auto* pointer = data_->headers_text.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::WebSocketHandshakeRequest_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WebSocketHandshakeResponseDataView {
    public:
        WebSocketHandshakeResponseDataView() { }

        WebSocketHandshakeResponseDataView(
            internal::WebSocketHandshakeResponse_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetUrlDataView(
            ::url::mojom::UrlDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadUrl(UserType* output)
        {
            auto* pointer = data_->url.Get();
            return mojo::internal::Deserialize<::url::mojom::UrlDataView>(
                pointer, output, context_);
        }
        int32_t status_code() const
        {
            return data_->status_code;
        }
        inline void GetStatusTextDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStatusText(UserType* output)
        {
            auto* pointer = data_->status_text.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetHeadersDataView(
            mojo::ArrayDataView<HttpHeaderDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadHeaders(UserType* output)
        {
            auto* pointer = data_->headers.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::blink::mojom::HttpHeaderDataView>>(
                pointer, output, context_);
        }
        inline void GetHeadersTextDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadHeadersText(UserType* output)
        {
            auto* pointer = data_->headers_text.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::WebSocketHandshakeResponse_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WebSocketClient_OnFailChannel_ParamsDataView {
    public:
        WebSocketClient_OnFailChannel_ParamsDataView() { }

        WebSocketClient_OnFailChannel_ParamsDataView(
            internal::WebSocketClient_OnFailChannel_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetReasonDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadReason(UserType* output)
        {
            auto* pointer = data_->reason.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::WebSocketClient_OnFailChannel_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WebSocketClient_OnStartOpeningHandshake_ParamsDataView {
    public:
        WebSocketClient_OnStartOpeningHandshake_ParamsDataView() { }

        WebSocketClient_OnStartOpeningHandshake_ParamsDataView(
            internal::WebSocketClient_OnStartOpeningHandshake_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetRequestDataView(
            WebSocketHandshakeRequestDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadRequest(UserType* output)
        {
            auto* pointer = data_->request.Get();
            return mojo::internal::Deserialize<::blink::mojom::WebSocketHandshakeRequestDataView>(
                pointer, output, context_);
        }

    private:
        internal::WebSocketClient_OnStartOpeningHandshake_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WebSocketClient_OnFinishOpeningHandshake_ParamsDataView {
    public:
        WebSocketClient_OnFinishOpeningHandshake_ParamsDataView() { }

        WebSocketClient_OnFinishOpeningHandshake_ParamsDataView(
            internal::WebSocketClient_OnFinishOpeningHandshake_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetResponseDataView(
            WebSocketHandshakeResponseDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadResponse(UserType* output)
        {
            auto* pointer = data_->response.Get();
            return mojo::internal::Deserialize<::blink::mojom::WebSocketHandshakeResponseDataView>(
                pointer, output, context_);
        }

    private:
        internal::WebSocketClient_OnFinishOpeningHandshake_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WebSocketClient_OnAddChannelResponse_ParamsDataView {
    public:
        WebSocketClient_OnAddChannelResponse_ParamsDataView() { }

        WebSocketClient_OnAddChannelResponse_ParamsDataView(
            internal::WebSocketClient_OnAddChannelResponse_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetSelectedProtocolDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSelectedProtocol(UserType* output)
        {
            auto* pointer = data_->selected_protocol.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetExtensionsDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadExtensions(UserType* output)
        {
            auto* pointer = data_->extensions.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::WebSocketClient_OnAddChannelResponse_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WebSocketClient_OnDataFrame_ParamsDataView {
    public:
        WebSocketClient_OnDataFrame_ParamsDataView() { }

        WebSocketClient_OnDataFrame_ParamsDataView(
            internal::WebSocketClient_OnDataFrame_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        bool fin() const
        {
            return data_->fin;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadType(UserType* output) const
        {
            auto data_value = data_->type;
            return mojo::internal::Deserialize<::blink::mojom::WebSocketMessageType>(
                data_value, output);
        }

        WebSocketMessageType type() const
        {
            return static_cast<WebSocketMessageType>(data_->type);
        }
        inline void GetDataDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadData(UserType* output)
        {
            auto* pointer = data_->data.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }

    private:
        internal::WebSocketClient_OnDataFrame_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WebSocketClient_OnFlowControl_ParamsDataView {
    public:
        WebSocketClient_OnFlowControl_ParamsDataView() { }

        WebSocketClient_OnFlowControl_ParamsDataView(
            internal::WebSocketClient_OnFlowControl_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int64_t quota() const
        {
            return data_->quota;
        }

    private:
        internal::WebSocketClient_OnFlowControl_Params_Data* data_ = nullptr;
    };

    class WebSocketClient_OnDropChannel_ParamsDataView {
    public:
        WebSocketClient_OnDropChannel_ParamsDataView() { }

        WebSocketClient_OnDropChannel_ParamsDataView(
            internal::WebSocketClient_OnDropChannel_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        bool was_clean() const
        {
            return data_->was_clean;
        }
        uint16_t code() const
        {
            return data_->code;
        }
        inline void GetReasonDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadReason(UserType* output)
        {
            auto* pointer = data_->reason.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::WebSocketClient_OnDropChannel_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WebSocketClient_OnClosingHandshake_ParamsDataView {
    public:
        WebSocketClient_OnClosingHandshake_ParamsDataView() { }

        WebSocketClient_OnClosingHandshake_ParamsDataView(
            internal::WebSocketClient_OnClosingHandshake_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::WebSocketClient_OnClosingHandshake_Params_Data* data_ = nullptr;
    };

    class WebSocket_AddChannelRequest_ParamsDataView {
    public:
        WebSocket_AddChannelRequest_ParamsDataView() { }

        WebSocket_AddChannelRequest_ParamsDataView(
            internal::WebSocket_AddChannelRequest_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetUrlDataView(
            ::url::mojom::UrlDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadUrl(UserType* output)
        {
            auto* pointer = data_->url.Get();
            return mojo::internal::Deserialize<::url::mojom::UrlDataView>(
                pointer, output, context_);
        }
        inline void GetRequestedProtocolsDataView(
            mojo::ArrayDataView<mojo::StringDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadRequestedProtocols(UserType* output)
        {
            auto* pointer = data_->requested_protocols.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<mojo::StringDataView>>(
                pointer, output, context_);
        }
        inline void GetOriginDataView(
            ::url::mojom::OriginDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOrigin(UserType* output)
        {
            auto* pointer = data_->origin.Get();
            return mojo::internal::Deserialize<::url::mojom::OriginDataView>(
                pointer, output, context_);
        }
        inline void GetFirstPartyForCookiesDataView(
            ::url::mojom::UrlDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFirstPartyForCookies(UserType* output)
        {
            auto* pointer = data_->first_party_for_cookies.Get();
            return mojo::internal::Deserialize<::url::mojom::UrlDataView>(
                pointer, output, context_);
        }
        inline void GetUserAgentOverrideDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadUserAgentOverride(UserType* output)
        {
            auto* pointer = data_->user_agent_override.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        UserType TakeClient()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::blink::mojom::WebSocketClientPtrDataView>(
                &data_->client, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::WebSocket_AddChannelRequest_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WebSocket_SendFrame_ParamsDataView {
    public:
        WebSocket_SendFrame_ParamsDataView() { }

        WebSocket_SendFrame_ParamsDataView(
            internal::WebSocket_SendFrame_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        bool fin() const
        {
            return data_->fin;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadType(UserType* output) const
        {
            auto data_value = data_->type;
            return mojo::internal::Deserialize<::blink::mojom::WebSocketMessageType>(
                data_value, output);
        }

        WebSocketMessageType type() const
        {
            return static_cast<WebSocketMessageType>(data_->type);
        }
        inline void GetDataDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadData(UserType* output)
        {
            auto* pointer = data_->data.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }

    private:
        internal::WebSocket_SendFrame_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WebSocket_SendFlowControl_ParamsDataView {
    public:
        WebSocket_SendFlowControl_ParamsDataView() { }

        WebSocket_SendFlowControl_ParamsDataView(
            internal::WebSocket_SendFlowControl_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int64_t quota() const
        {
            return data_->quota;
        }

    private:
        internal::WebSocket_SendFlowControl_Params_Data* data_ = nullptr;
    };

    class WebSocket_StartClosingHandshake_ParamsDataView {
    public:
        WebSocket_StartClosingHandshake_ParamsDataView() { }

        WebSocket_StartClosingHandshake_ParamsDataView(
            internal::WebSocket_StartClosingHandshake_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint16_t code() const
        {
            return data_->code;
        }
        inline void GetReasonDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadReason(UserType* output)
        {
            auto* pointer = data_->reason.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::WebSocket_StartClosingHandshake_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace blink

namespace std {

template <>
struct hash<::blink::mojom::WebSocketMessageType>
    : public mojo::internal::EnumHashImpl<::blink::mojom::WebSocketMessageType> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::blink::mojom::WebSocketMessageType, ::blink::mojom::WebSocketMessageType> {
    static ::blink::mojom::WebSocketMessageType ToMojom(::blink::mojom::WebSocketMessageType input) { return input; }
    static bool FromMojom(::blink::mojom::WebSocketMessageType input, ::blink::mojom::WebSocketMessageType* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::WebSocketMessageType, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::blink::mojom::WebSocketMessageType, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::blink::mojom::WebSocketMessageType>(input), output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::HttpHeaderDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::blink::mojom::HttpHeaderDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::blink::mojom::internal::HttpHeader_Data);
            decltype(CallWithContext(Traits::name, input, custom_context)) in_name = CallWithContext(Traits::name, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_name, context);
            decltype(CallWithContext(Traits::value, input, custom_context)) in_value = CallWithContext(Traits::value, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_value, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::blink::mojom::internal::HttpHeader_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::blink::mojom::internal::HttpHeader_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::name, input, custom_context)) in_name = CallWithContext(Traits::name, input, custom_context);
            typename decltype(result->name)::BaseType* name_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_name, buffer, &name_ptr, context);
            result->name.Set(name_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->name.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null name in HttpHeader struct");
            decltype(CallWithContext(Traits::value, input, custom_context)) in_value = CallWithContext(Traits::value, input, custom_context);
            typename decltype(result->value)::BaseType* value_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_value, buffer, &value_ptr, context);
            result->value.Set(value_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->value.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null value in HttpHeader struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::blink::mojom::internal::HttpHeader_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::blink::mojom::HttpHeaderDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::WebSocketHandshakeRequestDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::blink::mojom::WebSocketHandshakeRequestDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::blink::mojom::internal::WebSocketHandshakeRequest_Data);
            decltype(CallWithContext(Traits::url, input, custom_context)) in_url = CallWithContext(Traits::url, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::url::mojom::UrlDataView>(
                in_url, context);
            decltype(CallWithContext(Traits::headers, input, custom_context)) in_headers = CallWithContext(Traits::headers, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::blink::mojom::HttpHeaderDataView>>(
                in_headers, context);
            decltype(CallWithContext(Traits::headers_text, input, custom_context)) in_headers_text = CallWithContext(Traits::headers_text, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_headers_text, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::blink::mojom::internal::WebSocketHandshakeRequest_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::blink::mojom::internal::WebSocketHandshakeRequest_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::url, input, custom_context)) in_url = CallWithContext(Traits::url, input, custom_context);
            typename decltype(result->url)::BaseType* url_ptr;
            mojo::internal::Serialize<::url::mojom::UrlDataView>(
                in_url, buffer, &url_ptr, context);
            result->url.Set(url_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->url.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null url in WebSocketHandshakeRequest struct");
            decltype(CallWithContext(Traits::headers, input, custom_context)) in_headers = CallWithContext(Traits::headers, input, custom_context);
            typename decltype(result->headers)::BaseType* headers_ptr;
            const mojo::internal::ContainerValidateParams headers_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::blink::mojom::HttpHeaderDataView>>(
                in_headers, buffer, &headers_ptr, &headers_validate_params,
                context);
            result->headers.Set(headers_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->headers.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null headers in WebSocketHandshakeRequest struct");
            decltype(CallWithContext(Traits::headers_text, input, custom_context)) in_headers_text = CallWithContext(Traits::headers_text, input, custom_context);
            typename decltype(result->headers_text)::BaseType* headers_text_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_headers_text, buffer, &headers_text_ptr, context);
            result->headers_text.Set(headers_text_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->headers_text.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null headers_text in WebSocketHandshakeRequest struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::blink::mojom::internal::WebSocketHandshakeRequest_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::blink::mojom::WebSocketHandshakeRequestDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::WebSocketHandshakeResponseDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::blink::mojom::WebSocketHandshakeResponseDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::blink::mojom::internal::WebSocketHandshakeResponse_Data);
            decltype(CallWithContext(Traits::url, input, custom_context)) in_url = CallWithContext(Traits::url, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::url::mojom::UrlDataView>(
                in_url, context);
            decltype(CallWithContext(Traits::status_text, input, custom_context)) in_status_text = CallWithContext(Traits::status_text, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_status_text, context);
            decltype(CallWithContext(Traits::headers, input, custom_context)) in_headers = CallWithContext(Traits::headers, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::blink::mojom::HttpHeaderDataView>>(
                in_headers, context);
            decltype(CallWithContext(Traits::headers_text, input, custom_context)) in_headers_text = CallWithContext(Traits::headers_text, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_headers_text, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::blink::mojom::internal::WebSocketHandshakeResponse_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::blink::mojom::internal::WebSocketHandshakeResponse_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::url, input, custom_context)) in_url = CallWithContext(Traits::url, input, custom_context);
            typename decltype(result->url)::BaseType* url_ptr;
            mojo::internal::Serialize<::url::mojom::UrlDataView>(
                in_url, buffer, &url_ptr, context);
            result->url.Set(url_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->url.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null url in WebSocketHandshakeResponse struct");
            result->status_code = CallWithContext(Traits::status_code, input, custom_context);
            decltype(CallWithContext(Traits::status_text, input, custom_context)) in_status_text = CallWithContext(Traits::status_text, input, custom_context);
            typename decltype(result->status_text)::BaseType* status_text_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_status_text, buffer, &status_text_ptr, context);
            result->status_text.Set(status_text_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->status_text.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null status_text in WebSocketHandshakeResponse struct");
            decltype(CallWithContext(Traits::headers, input, custom_context)) in_headers = CallWithContext(Traits::headers, input, custom_context);
            typename decltype(result->headers)::BaseType* headers_ptr;
            const mojo::internal::ContainerValidateParams headers_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::blink::mojom::HttpHeaderDataView>>(
                in_headers, buffer, &headers_ptr, &headers_validate_params,
                context);
            result->headers.Set(headers_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->headers.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null headers in WebSocketHandshakeResponse struct");
            decltype(CallWithContext(Traits::headers_text, input, custom_context)) in_headers_text = CallWithContext(Traits::headers_text, input, custom_context);
            typename decltype(result->headers_text)::BaseType* headers_text_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_headers_text, buffer, &headers_text_ptr, context);
            result->headers_text.Set(headers_text_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->headers_text.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null headers_text in WebSocketHandshakeResponse struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::blink::mojom::internal::WebSocketHandshakeResponse_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::blink::mojom::WebSocketHandshakeResponseDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace blink {
namespace mojom {

    inline void HttpHeaderDataView::GetNameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->name.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void HttpHeaderDataView::GetValueDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->value.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void WebSocketHandshakeRequestDataView::GetUrlDataView(
        ::url::mojom::UrlDataView* output)
    {
        auto pointer = data_->url.Get();
        *output = ::url::mojom::UrlDataView(pointer, context_);
    }
    inline void WebSocketHandshakeRequestDataView::GetHeadersDataView(
        mojo::ArrayDataView<HttpHeaderDataView>* output)
    {
        auto pointer = data_->headers.Get();
        *output = mojo::ArrayDataView<HttpHeaderDataView>(pointer, context_);
    }
    inline void WebSocketHandshakeRequestDataView::GetHeadersTextDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->headers_text.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void WebSocketHandshakeResponseDataView::GetUrlDataView(
        ::url::mojom::UrlDataView* output)
    {
        auto pointer = data_->url.Get();
        *output = ::url::mojom::UrlDataView(pointer, context_);
    }
    inline void WebSocketHandshakeResponseDataView::GetStatusTextDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->status_text.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void WebSocketHandshakeResponseDataView::GetHeadersDataView(
        mojo::ArrayDataView<HttpHeaderDataView>* output)
    {
        auto pointer = data_->headers.Get();
        *output = mojo::ArrayDataView<HttpHeaderDataView>(pointer, context_);
    }
    inline void WebSocketHandshakeResponseDataView::GetHeadersTextDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->headers_text.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void WebSocketClient_OnFailChannel_ParamsDataView::GetReasonDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->reason.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void WebSocketClient_OnStartOpeningHandshake_ParamsDataView::GetRequestDataView(
        WebSocketHandshakeRequestDataView* output)
    {
        auto pointer = data_->request.Get();
        *output = WebSocketHandshakeRequestDataView(pointer, context_);
    }

    inline void WebSocketClient_OnFinishOpeningHandshake_ParamsDataView::GetResponseDataView(
        WebSocketHandshakeResponseDataView* output)
    {
        auto pointer = data_->response.Get();
        *output = WebSocketHandshakeResponseDataView(pointer, context_);
    }

    inline void WebSocketClient_OnAddChannelResponse_ParamsDataView::GetSelectedProtocolDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->selected_protocol.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void WebSocketClient_OnAddChannelResponse_ParamsDataView::GetExtensionsDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->extensions.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void WebSocketClient_OnDataFrame_ParamsDataView::GetDataDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->data.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

    inline void WebSocketClient_OnDropChannel_ParamsDataView::GetReasonDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->reason.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void WebSocket_AddChannelRequest_ParamsDataView::GetUrlDataView(
        ::url::mojom::UrlDataView* output)
    {
        auto pointer = data_->url.Get();
        *output = ::url::mojom::UrlDataView(pointer, context_);
    }
    inline void WebSocket_AddChannelRequest_ParamsDataView::GetRequestedProtocolsDataView(
        mojo::ArrayDataView<mojo::StringDataView>* output)
    {
        auto pointer = data_->requested_protocols.Get();
        *output = mojo::ArrayDataView<mojo::StringDataView>(pointer, context_);
    }
    inline void WebSocket_AddChannelRequest_ParamsDataView::GetOriginDataView(
        ::url::mojom::OriginDataView* output)
    {
        auto pointer = data_->origin.Get();
        *output = ::url::mojom::OriginDataView(pointer, context_);
    }
    inline void WebSocket_AddChannelRequest_ParamsDataView::GetFirstPartyForCookiesDataView(
        ::url::mojom::UrlDataView* output)
    {
        auto pointer = data_->first_party_for_cookies.Get();
        *output = ::url::mojom::UrlDataView(pointer, context_);
    }
    inline void WebSocket_AddChannelRequest_ParamsDataView::GetUserAgentOverrideDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->user_agent_override.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void WebSocket_SendFrame_ParamsDataView::GetDataDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->data.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

    inline void WebSocket_StartClosingHandshake_ParamsDataView::GetReasonDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->reason.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

} // namespace mojom
} // namespace blink

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_WEBSOCKETS_WEBSOCKET_MOJOM_SHARED_H_
