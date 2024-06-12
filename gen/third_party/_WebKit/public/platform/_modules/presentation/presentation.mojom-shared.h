// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_PRESENTATION_PRESENTATION_MOJOM_SHARED_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_PRESENTATION_PRESENTATION_MOJOM_SHARED_H_

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
#include "third_party/WebKit/public/platform/modules/presentation/presentation.mojom-shared-internal.h"
#include "url/mojo/url.mojom-shared.h"

namespace blink {
namespace mojom {
    class PresentationSessionInfoDataView;

    class PresentationErrorDataView;

    class ConnectionMessageDataView;

} // namespace mojom
} // namespace blink

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::blink::mojom::PresentationSessionInfoDataView> {
        using Data = ::blink::mojom::internal::PresentationSessionInfo_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::blink::mojom::PresentationErrorDataView> {
        using Data = ::blink::mojom::internal::PresentationError_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::blink::mojom::ConnectionMessageDataView> {
        using Data = ::blink::mojom::internal::ConnectionMessage_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace blink {
namespace mojom {

    enum class PresentationConnectionState : int32_t {
        CONNECTING,
        CONNECTED,
        CLOSED,
        TERMINATED,
    };

    inline std::ostream& operator<<(std::ostream& os, PresentationConnectionState value)
    {
        switch (value) {
        case PresentationConnectionState::CONNECTING:
            return os << "PresentationConnectionState::CONNECTING";
        case PresentationConnectionState::CONNECTED:
            return os << "PresentationConnectionState::CONNECTED";
        case PresentationConnectionState::CLOSED:
            return os << "PresentationConnectionState::CLOSED";
        case PresentationConnectionState::TERMINATED:
            return os << "PresentationConnectionState::TERMINATED";
        default:
            return os << "Unknown PresentationConnectionState value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(PresentationConnectionState value)
    {
        return internal::PresentationConnectionState_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class PresentationConnectionCloseReason : int32_t {
        CONNECTION_ERROR,
        CLOSED,
        WENT_AWAY,
    };

    inline std::ostream& operator<<(std::ostream& os, PresentationConnectionCloseReason value)
    {
        switch (value) {
        case PresentationConnectionCloseReason::CONNECTION_ERROR:
            return os << "PresentationConnectionCloseReason::CONNECTION_ERROR";
        case PresentationConnectionCloseReason::CLOSED:
            return os << "PresentationConnectionCloseReason::CLOSED";
        case PresentationConnectionCloseReason::WENT_AWAY:
            return os << "PresentationConnectionCloseReason::WENT_AWAY";
        default:
            return os << "Unknown PresentationConnectionCloseReason value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(PresentationConnectionCloseReason value)
    {
        return internal::PresentationConnectionCloseReason_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class PresentationErrorType : int32_t {
        NO_AVAILABLE_SCREENS,
        SESSION_REQUEST_CANCELLED,
        NO_PRESENTATION_FOUND,
        UNKNOWN,
    };

    inline std::ostream& operator<<(std::ostream& os, PresentationErrorType value)
    {
        switch (value) {
        case PresentationErrorType::NO_AVAILABLE_SCREENS:
            return os << "PresentationErrorType::NO_AVAILABLE_SCREENS";
        case PresentationErrorType::SESSION_REQUEST_CANCELLED:
            return os << "PresentationErrorType::SESSION_REQUEST_CANCELLED";
        case PresentationErrorType::NO_PRESENTATION_FOUND:
            return os << "PresentationErrorType::NO_PRESENTATION_FOUND";
        case PresentationErrorType::UNKNOWN:
            return os << "PresentationErrorType::UNKNOWN";
        default:
            return os << "Unknown PresentationErrorType value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(PresentationErrorType value)
    {
        return internal::PresentationErrorType_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class PresentationMessageType : int32_t {
        TEXT,
        BINARY,
    };

    inline std::ostream& operator<<(std::ostream& os, PresentationMessageType value)
    {
        switch (value) {
        case PresentationMessageType::TEXT:
            return os << "PresentationMessageType::TEXT";
        case PresentationMessageType::BINARY:
            return os << "PresentationMessageType::BINARY";
        default:
            return os << "Unknown PresentationMessageType value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(PresentationMessageType value)
    {
        return internal::PresentationMessageType_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    // Interface base classes. They are used for type safety check.
    class PresentationConnectionInterfaceBase {
    };

    using PresentationConnectionPtrDataView = mojo::InterfacePtrDataView<PresentationConnectionInterfaceBase>;
    using PresentationConnectionRequestDataView = mojo::InterfaceRequestDataView<PresentationConnectionInterfaceBase>;
    using PresentationConnectionAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<PresentationConnectionInterfaceBase>;
    using PresentationConnectionAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<PresentationConnectionInterfaceBase>;
    class PresentationServiceInterfaceBase {
    };

    using PresentationServicePtrDataView = mojo::InterfacePtrDataView<PresentationServiceInterfaceBase>;
    using PresentationServiceRequestDataView = mojo::InterfaceRequestDataView<PresentationServiceInterfaceBase>;
    using PresentationServiceAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<PresentationServiceInterfaceBase>;
    using PresentationServiceAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<PresentationServiceInterfaceBase>;
    class PresentationServiceClientInterfaceBase {
    };

    using PresentationServiceClientPtrDataView = mojo::InterfacePtrDataView<PresentationServiceClientInterfaceBase>;
    using PresentationServiceClientRequestDataView = mojo::InterfaceRequestDataView<PresentationServiceClientInterfaceBase>;
    using PresentationServiceClientAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<PresentationServiceClientInterfaceBase>;
    using PresentationServiceClientAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<PresentationServiceClientInterfaceBase>;
    class PresentationSessionInfoDataView {
    public:
        PresentationSessionInfoDataView() { }

        PresentationSessionInfoDataView(
            internal::PresentationSessionInfo_Data* data,
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
        inline void GetIdDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadId(UserType* output)
        {
            auto* pointer = data_->id.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::PresentationSessionInfo_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PresentationErrorDataView {
    public:
        PresentationErrorDataView() { }

        PresentationErrorDataView(
            internal::PresentationError_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadErrorType(UserType* output) const
        {
            auto data_value = data_->error_type;
            return mojo::internal::Deserialize<::blink::mojom::PresentationErrorType>(
                data_value, output);
        }

        PresentationErrorType error_type() const
        {
            return static_cast<PresentationErrorType>(data_->error_type);
        }
        inline void GetMessageDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMessage(UserType* output)
        {
            auto* pointer = data_->message.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::PresentationError_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class ConnectionMessageDataView {
    public:
        ConnectionMessageDataView() { }

        ConnectionMessageDataView(
            internal::ConnectionMessage_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadType(UserType* output) const
        {
            auto data_value = data_->type;
            return mojo::internal::Deserialize<::blink::mojom::PresentationMessageType>(
                data_value, output);
        }

        PresentationMessageType type() const
        {
            return static_cast<PresentationMessageType>(data_->type);
        }
        inline void GetMessageDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMessage(UserType* output)
        {
            auto* pointer = data_->message.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
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
        internal::ConnectionMessage_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PresentationConnection_OnMessage_ParamsDataView {
    public:
        PresentationConnection_OnMessage_ParamsDataView() { }

        PresentationConnection_OnMessage_ParamsDataView(
            internal::PresentationConnection_OnMessage_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetMessageDataView(
            ConnectionMessageDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMessage(UserType* output)
        {
            auto* pointer = data_->message.Get();
            return mojo::internal::Deserialize<::blink::mojom::ConnectionMessageDataView>(
                pointer, output, context_);
        }

    private:
        internal::PresentationConnection_OnMessage_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PresentationConnection_OnMessage_ResponseParamsDataView {
    public:
        PresentationConnection_OnMessage_ResponseParamsDataView() { }

        PresentationConnection_OnMessage_ResponseParamsDataView(
            internal::PresentationConnection_OnMessage_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool success() const
        {
            return data_->success;
        }

    private:
        internal::PresentationConnection_OnMessage_ResponseParams_Data* data_ = nullptr;
    };

    class PresentationConnection_DidChangeState_ParamsDataView {
    public:
        PresentationConnection_DidChangeState_ParamsDataView() { }

        PresentationConnection_DidChangeState_ParamsDataView(
            internal::PresentationConnection_DidChangeState_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadState(UserType* output) const
        {
            auto data_value = data_->state;
            return mojo::internal::Deserialize<::blink::mojom::PresentationConnectionState>(
                data_value, output);
        }

        PresentationConnectionState state() const
        {
            return static_cast<PresentationConnectionState>(data_->state);
        }

    private:
        internal::PresentationConnection_DidChangeState_Params_Data* data_ = nullptr;
    };

    class PresentationService_SetClient_ParamsDataView {
    public:
        PresentationService_SetClient_ParamsDataView() { }

        PresentationService_SetClient_ParamsDataView(
            internal::PresentationService_SetClient_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeClient()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::blink::mojom::PresentationServiceClientPtrDataView>(
                &data_->client, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::PresentationService_SetClient_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PresentationService_SetDefaultPresentationUrls_ParamsDataView {
    public:
        PresentationService_SetDefaultPresentationUrls_ParamsDataView() { }

        PresentationService_SetDefaultPresentationUrls_ParamsDataView(
            internal::PresentationService_SetDefaultPresentationUrls_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetPresentationUrlsDataView(
            mojo::ArrayDataView<::url::mojom::UrlDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPresentationUrls(UserType* output)
        {
            auto* pointer = data_->presentation_urls.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::url::mojom::UrlDataView>>(
                pointer, output, context_);
        }

    private:
        internal::PresentationService_SetDefaultPresentationUrls_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PresentationService_ListenForScreenAvailability_ParamsDataView {
    public:
        PresentationService_ListenForScreenAvailability_ParamsDataView() { }

        PresentationService_ListenForScreenAvailability_ParamsDataView(
            internal::PresentationService_ListenForScreenAvailability_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetAvailabilityUrlDataView(
            ::url::mojom::UrlDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadAvailabilityUrl(UserType* output)
        {
            auto* pointer = data_->availability_url.Get();
            return mojo::internal::Deserialize<::url::mojom::UrlDataView>(
                pointer, output, context_);
        }

    private:
        internal::PresentationService_ListenForScreenAvailability_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PresentationService_StopListeningForScreenAvailability_ParamsDataView {
    public:
        PresentationService_StopListeningForScreenAvailability_ParamsDataView() { }

        PresentationService_StopListeningForScreenAvailability_ParamsDataView(
            internal::PresentationService_StopListeningForScreenAvailability_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetAvailabilityUrlDataView(
            ::url::mojom::UrlDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadAvailabilityUrl(UserType* output)
        {
            auto* pointer = data_->availability_url.Get();
            return mojo::internal::Deserialize<::url::mojom::UrlDataView>(
                pointer, output, context_);
        }

    private:
        internal::PresentationService_StopListeningForScreenAvailability_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PresentationService_StartSession_ParamsDataView {
    public:
        PresentationService_StartSession_ParamsDataView() { }

        PresentationService_StartSession_ParamsDataView(
            internal::PresentationService_StartSession_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetPresentationUrlsDataView(
            mojo::ArrayDataView<::url::mojom::UrlDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPresentationUrls(UserType* output)
        {
            auto* pointer = data_->presentation_urls.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::url::mojom::UrlDataView>>(
                pointer, output, context_);
        }

    private:
        internal::PresentationService_StartSession_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PresentationService_StartSession_ResponseParamsDataView {
    public:
        PresentationService_StartSession_ResponseParamsDataView() { }

        PresentationService_StartSession_ResponseParamsDataView(
            internal::PresentationService_StartSession_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetSessioninfoDataView(
            PresentationSessionInfoDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSessioninfo(UserType* output)
        {
            auto* pointer = data_->sessionInfo.Get();
            return mojo::internal::Deserialize<::blink::mojom::PresentationSessionInfoDataView>(
                pointer, output, context_);
        }
        inline void GetErrorDataView(
            PresentationErrorDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadError(UserType* output)
        {
            auto* pointer = data_->error.Get();
            return mojo::internal::Deserialize<::blink::mojom::PresentationErrorDataView>(
                pointer, output, context_);
        }

    private:
        internal::PresentationService_StartSession_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PresentationService_JoinSession_ParamsDataView {
    public:
        PresentationService_JoinSession_ParamsDataView() { }

        PresentationService_JoinSession_ParamsDataView(
            internal::PresentationService_JoinSession_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetPresentationUrlsDataView(
            mojo::ArrayDataView<::url::mojom::UrlDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPresentationUrls(UserType* output)
        {
            auto* pointer = data_->presentation_urls.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::url::mojom::UrlDataView>>(
                pointer, output, context_);
        }
        inline void GetPresentationIdDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPresentationId(UserType* output)
        {
            auto* pointer = data_->presentation_id.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::PresentationService_JoinSession_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PresentationService_JoinSession_ResponseParamsDataView {
    public:
        PresentationService_JoinSession_ResponseParamsDataView() { }

        PresentationService_JoinSession_ResponseParamsDataView(
            internal::PresentationService_JoinSession_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetSessioninfoDataView(
            PresentationSessionInfoDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSessioninfo(UserType* output)
        {
            auto* pointer = data_->sessionInfo.Get();
            return mojo::internal::Deserialize<::blink::mojom::PresentationSessionInfoDataView>(
                pointer, output, context_);
        }
        inline void GetErrorDataView(
            PresentationErrorDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadError(UserType* output)
        {
            auto* pointer = data_->error.Get();
            return mojo::internal::Deserialize<::blink::mojom::PresentationErrorDataView>(
                pointer, output, context_);
        }

    private:
        internal::PresentationService_JoinSession_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PresentationService_SetPresentationConnection_ParamsDataView {
    public:
        PresentationService_SetPresentationConnection_ParamsDataView() { }

        PresentationService_SetPresentationConnection_ParamsDataView(
            internal::PresentationService_SetPresentationConnection_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetSessioninfoDataView(
            PresentationSessionInfoDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSessioninfo(UserType* output)
        {
            auto* pointer = data_->sessionInfo.Get();
            return mojo::internal::Deserialize<::blink::mojom::PresentationSessionInfoDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        UserType TakeControllerConnectionPtr()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::blink::mojom::PresentationConnectionPtrDataView>(
                &data_->controller_connection_ptr, &result, context_);
            DCHECK(ret);
            return result;
        }
        template <typename UserType>
        UserType TakeReceiverConnectionRequest()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::blink::mojom::PresentationConnectionRequestDataView>(
                &data_->receiver_connection_request, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::PresentationService_SetPresentationConnection_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PresentationService_SendConnectionMessage_ParamsDataView {
    public:
        PresentationService_SendConnectionMessage_ParamsDataView() { }

        PresentationService_SendConnectionMessage_ParamsDataView(
            internal::PresentationService_SendConnectionMessage_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetSessioninfoDataView(
            PresentationSessionInfoDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSessioninfo(UserType* output)
        {
            auto* pointer = data_->sessionInfo.Get();
            return mojo::internal::Deserialize<::blink::mojom::PresentationSessionInfoDataView>(
                pointer, output, context_);
        }
        inline void GetMessageRequestDataView(
            ConnectionMessageDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMessageRequest(UserType* output)
        {
            auto* pointer = data_->message_request.Get();
            return mojo::internal::Deserialize<::blink::mojom::ConnectionMessageDataView>(
                pointer, output, context_);
        }

    private:
        internal::PresentationService_SendConnectionMessage_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PresentationService_SendConnectionMessage_ResponseParamsDataView {
    public:
        PresentationService_SendConnectionMessage_ResponseParamsDataView() { }

        PresentationService_SendConnectionMessage_ResponseParamsDataView(
            internal::PresentationService_SendConnectionMessage_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool success() const
        {
            return data_->success;
        }

    private:
        internal::PresentationService_SendConnectionMessage_ResponseParams_Data* data_ = nullptr;
    };

    class PresentationService_CloseConnection_ParamsDataView {
    public:
        PresentationService_CloseConnection_ParamsDataView() { }

        PresentationService_CloseConnection_ParamsDataView(
            internal::PresentationService_CloseConnection_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetPresentationUrlDataView(
            ::url::mojom::UrlDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPresentationUrl(UserType* output)
        {
            auto* pointer = data_->presentation_url.Get();
            return mojo::internal::Deserialize<::url::mojom::UrlDataView>(
                pointer, output, context_);
        }
        inline void GetPresentationIdDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPresentationId(UserType* output)
        {
            auto* pointer = data_->presentation_id.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::PresentationService_CloseConnection_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PresentationService_Terminate_ParamsDataView {
    public:
        PresentationService_Terminate_ParamsDataView() { }

        PresentationService_Terminate_ParamsDataView(
            internal::PresentationService_Terminate_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetPresentationUrlDataView(
            ::url::mojom::UrlDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPresentationUrl(UserType* output)
        {
            auto* pointer = data_->presentation_url.Get();
            return mojo::internal::Deserialize<::url::mojom::UrlDataView>(
                pointer, output, context_);
        }
        inline void GetPresentationIdDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPresentationId(UserType* output)
        {
            auto* pointer = data_->presentation_id.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::PresentationService_Terminate_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PresentationService_ListenForConnectionMessages_ParamsDataView {
    public:
        PresentationService_ListenForConnectionMessages_ParamsDataView() { }

        PresentationService_ListenForConnectionMessages_ParamsDataView(
            internal::PresentationService_ListenForConnectionMessages_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetSessioninfoDataView(
            PresentationSessionInfoDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSessioninfo(UserType* output)
        {
            auto* pointer = data_->sessionInfo.Get();
            return mojo::internal::Deserialize<::blink::mojom::PresentationSessionInfoDataView>(
                pointer, output, context_);
        }

    private:
        internal::PresentationService_ListenForConnectionMessages_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PresentationServiceClient_OnScreenAvailabilityNotSupported_ParamsDataView {
    public:
        PresentationServiceClient_OnScreenAvailabilityNotSupported_ParamsDataView() { }

        PresentationServiceClient_OnScreenAvailabilityNotSupported_ParamsDataView(
            internal::PresentationServiceClient_OnScreenAvailabilityNotSupported_Params_Data* data,
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

    private:
        internal::PresentationServiceClient_OnScreenAvailabilityNotSupported_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PresentationServiceClient_OnScreenAvailabilityUpdated_ParamsDataView {
    public:
        PresentationServiceClient_OnScreenAvailabilityUpdated_ParamsDataView() { }

        PresentationServiceClient_OnScreenAvailabilityUpdated_ParamsDataView(
            internal::PresentationServiceClient_OnScreenAvailabilityUpdated_Params_Data* data,
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
        bool available() const
        {
            return data_->available;
        }

    private:
        internal::PresentationServiceClient_OnScreenAvailabilityUpdated_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PresentationServiceClient_OnDefaultSessionStarted_ParamsDataView {
    public:
        PresentationServiceClient_OnDefaultSessionStarted_ParamsDataView() { }

        PresentationServiceClient_OnDefaultSessionStarted_ParamsDataView(
            internal::PresentationServiceClient_OnDefaultSessionStarted_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetSessioninfoDataView(
            PresentationSessionInfoDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSessioninfo(UserType* output)
        {
            auto* pointer = data_->sessionInfo.Get();
            return mojo::internal::Deserialize<::blink::mojom::PresentationSessionInfoDataView>(
                pointer, output, context_);
        }

    private:
        internal::PresentationServiceClient_OnDefaultSessionStarted_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PresentationServiceClient_OnConnectionStateChanged_ParamsDataView {
    public:
        PresentationServiceClient_OnConnectionStateChanged_ParamsDataView() { }

        PresentationServiceClient_OnConnectionStateChanged_ParamsDataView(
            internal::PresentationServiceClient_OnConnectionStateChanged_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetConnectionDataView(
            PresentationSessionInfoDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadConnection(UserType* output)
        {
            auto* pointer = data_->connection.Get();
            return mojo::internal::Deserialize<::blink::mojom::PresentationSessionInfoDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadNewstate(UserType* output) const
        {
            auto data_value = data_->newState;
            return mojo::internal::Deserialize<::blink::mojom::PresentationConnectionState>(
                data_value, output);
        }

        PresentationConnectionState newState() const
        {
            return static_cast<PresentationConnectionState>(data_->newState);
        }

    private:
        internal::PresentationServiceClient_OnConnectionStateChanged_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PresentationServiceClient_OnConnectionClosed_ParamsDataView {
    public:
        PresentationServiceClient_OnConnectionClosed_ParamsDataView() { }

        PresentationServiceClient_OnConnectionClosed_ParamsDataView(
            internal::PresentationServiceClient_OnConnectionClosed_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetConnectionDataView(
            PresentationSessionInfoDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadConnection(UserType* output)
        {
            auto* pointer = data_->connection.Get();
            return mojo::internal::Deserialize<::blink::mojom::PresentationSessionInfoDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadReason(UserType* output) const
        {
            auto data_value = data_->reason;
            return mojo::internal::Deserialize<::blink::mojom::PresentationConnectionCloseReason>(
                data_value, output);
        }

        PresentationConnectionCloseReason reason() const
        {
            return static_cast<PresentationConnectionCloseReason>(data_->reason);
        }
        inline void GetMessageDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMessage(UserType* output)
        {
            auto* pointer = data_->message.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::PresentationServiceClient_OnConnectionClosed_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PresentationServiceClient_OnConnectionMessagesReceived_ParamsDataView {
    public:
        PresentationServiceClient_OnConnectionMessagesReceived_ParamsDataView() { }

        PresentationServiceClient_OnConnectionMessagesReceived_ParamsDataView(
            internal::PresentationServiceClient_OnConnectionMessagesReceived_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetSessioninfoDataView(
            PresentationSessionInfoDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSessioninfo(UserType* output)
        {
            auto* pointer = data_->sessionInfo.Get();
            return mojo::internal::Deserialize<::blink::mojom::PresentationSessionInfoDataView>(
                pointer, output, context_);
        }
        inline void GetMessagesDataView(
            mojo::ArrayDataView<ConnectionMessageDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMessages(UserType* output)
        {
            auto* pointer = data_->messages.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::blink::mojom::ConnectionMessageDataView>>(
                pointer, output, context_);
        }

    private:
        internal::PresentationServiceClient_OnConnectionMessagesReceived_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PresentationServiceClient_OnReceiverConnectionAvailable_ParamsDataView {
    public:
        PresentationServiceClient_OnReceiverConnectionAvailable_ParamsDataView() { }

        PresentationServiceClient_OnReceiverConnectionAvailable_ParamsDataView(
            internal::PresentationServiceClient_OnReceiverConnectionAvailable_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetSessioninfoDataView(
            PresentationSessionInfoDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSessioninfo(UserType* output)
        {
            auto* pointer = data_->sessionInfo.Get();
            return mojo::internal::Deserialize<::blink::mojom::PresentationSessionInfoDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        UserType TakeControllerConnectionPtr()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::blink::mojom::PresentationConnectionPtrDataView>(
                &data_->controller_connection_ptr, &result, context_);
            DCHECK(ret);
            return result;
        }
        template <typename UserType>
        UserType TakeReceiverConnectionRequest()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::blink::mojom::PresentationConnectionRequestDataView>(
                &data_->receiver_connection_request, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::PresentationServiceClient_OnReceiverConnectionAvailable_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace blink

namespace std {

template <>
struct hash<::blink::mojom::PresentationConnectionState>
    : public mojo::internal::EnumHashImpl<::blink::mojom::PresentationConnectionState> {
};

template <>
struct hash<::blink::mojom::PresentationConnectionCloseReason>
    : public mojo::internal::EnumHashImpl<::blink::mojom::PresentationConnectionCloseReason> {
};

template <>
struct hash<::blink::mojom::PresentationErrorType>
    : public mojo::internal::EnumHashImpl<::blink::mojom::PresentationErrorType> {
};

template <>
struct hash<::blink::mojom::PresentationMessageType>
    : public mojo::internal::EnumHashImpl<::blink::mojom::PresentationMessageType> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::blink::mojom::PresentationConnectionState, ::blink::mojom::PresentationConnectionState> {
    static ::blink::mojom::PresentationConnectionState ToMojom(::blink::mojom::PresentationConnectionState input) { return input; }
    static bool FromMojom(::blink::mojom::PresentationConnectionState input, ::blink::mojom::PresentationConnectionState* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::PresentationConnectionState, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::blink::mojom::PresentationConnectionState, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::blink::mojom::PresentationConnectionState>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::blink::mojom::PresentationConnectionCloseReason, ::blink::mojom::PresentationConnectionCloseReason> {
    static ::blink::mojom::PresentationConnectionCloseReason ToMojom(::blink::mojom::PresentationConnectionCloseReason input) { return input; }
    static bool FromMojom(::blink::mojom::PresentationConnectionCloseReason input, ::blink::mojom::PresentationConnectionCloseReason* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::PresentationConnectionCloseReason, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::blink::mojom::PresentationConnectionCloseReason, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::blink::mojom::PresentationConnectionCloseReason>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::blink::mojom::PresentationErrorType, ::blink::mojom::PresentationErrorType> {
    static ::blink::mojom::PresentationErrorType ToMojom(::blink::mojom::PresentationErrorType input) { return input; }
    static bool FromMojom(::blink::mojom::PresentationErrorType input, ::blink::mojom::PresentationErrorType* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::PresentationErrorType, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::blink::mojom::PresentationErrorType, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::blink::mojom::PresentationErrorType>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::blink::mojom::PresentationMessageType, ::blink::mojom::PresentationMessageType> {
    static ::blink::mojom::PresentationMessageType ToMojom(::blink::mojom::PresentationMessageType input) { return input; }
    static bool FromMojom(::blink::mojom::PresentationMessageType input, ::blink::mojom::PresentationMessageType* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::PresentationMessageType, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::blink::mojom::PresentationMessageType, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::blink::mojom::PresentationMessageType>(input), output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::PresentationSessionInfoDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::blink::mojom::PresentationSessionInfoDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::blink::mojom::internal::PresentationSessionInfo_Data);
            decltype(CallWithContext(Traits::url, input, custom_context)) in_url = CallWithContext(Traits::url, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::url::mojom::UrlDataView>(
                in_url, context);
            decltype(CallWithContext(Traits::id, input, custom_context)) in_id = CallWithContext(Traits::id, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_id, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::blink::mojom::internal::PresentationSessionInfo_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::blink::mojom::internal::PresentationSessionInfo_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::url, input, custom_context)) in_url = CallWithContext(Traits::url, input, custom_context);
            typename decltype(result->url)::BaseType* url_ptr;
            mojo::internal::Serialize<::url::mojom::UrlDataView>(
                in_url, buffer, &url_ptr, context);
            result->url.Set(url_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->url.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null url in PresentationSessionInfo struct");
            decltype(CallWithContext(Traits::id, input, custom_context)) in_id = CallWithContext(Traits::id, input, custom_context);
            typename decltype(result->id)::BaseType* id_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_id, buffer, &id_ptr, context);
            result->id.Set(id_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->id.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null id in PresentationSessionInfo struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::blink::mojom::internal::PresentationSessionInfo_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::blink::mojom::PresentationSessionInfoDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::PresentationErrorDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::blink::mojom::PresentationErrorDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::blink::mojom::internal::PresentationError_Data);
            decltype(CallWithContext(Traits::message, input, custom_context)) in_message = CallWithContext(Traits::message, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_message, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::blink::mojom::internal::PresentationError_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::blink::mojom::internal::PresentationError_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            mojo::internal::Serialize<::blink::mojom::PresentationErrorType>(
                CallWithContext(Traits::error_type, input, custom_context), &result->error_type);
            decltype(CallWithContext(Traits::message, input, custom_context)) in_message = CallWithContext(Traits::message, input, custom_context);
            typename decltype(result->message)::BaseType* message_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_message, buffer, &message_ptr, context);
            result->message.Set(message_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->message.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null message in PresentationError struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::blink::mojom::internal::PresentationError_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::blink::mojom::PresentationErrorDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::ConnectionMessageDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::blink::mojom::ConnectionMessageDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::blink::mojom::internal::ConnectionMessage_Data);
            decltype(CallWithContext(Traits::message, input, custom_context)) in_message = CallWithContext(Traits::message, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_message, context);
            decltype(CallWithContext(Traits::data, input, custom_context)) in_data = CallWithContext(Traits::data, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
                in_data, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::blink::mojom::internal::ConnectionMessage_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::blink::mojom::internal::ConnectionMessage_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            mojo::internal::Serialize<::blink::mojom::PresentationMessageType>(
                CallWithContext(Traits::type, input, custom_context), &result->type);
            decltype(CallWithContext(Traits::message, input, custom_context)) in_message = CallWithContext(Traits::message, input, custom_context);
            typename decltype(result->message)::BaseType* message_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_message, buffer, &message_ptr, context);
            result->message.Set(message_ptr);
            decltype(CallWithContext(Traits::data, input, custom_context)) in_data = CallWithContext(Traits::data, input, custom_context);
            typename decltype(result->data)::BaseType* data_ptr;
            const mojo::internal::ContainerValidateParams data_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
                in_data, buffer, &data_ptr, &data_validate_params,
                context);
            result->data.Set(data_ptr);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::blink::mojom::internal::ConnectionMessage_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::blink::mojom::ConnectionMessageDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace blink {
namespace mojom {

    inline void PresentationSessionInfoDataView::GetUrlDataView(
        ::url::mojom::UrlDataView* output)
    {
        auto pointer = data_->url.Get();
        *output = ::url::mojom::UrlDataView(pointer, context_);
    }
    inline void PresentationSessionInfoDataView::GetIdDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->id.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void PresentationErrorDataView::GetMessageDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->message.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void ConnectionMessageDataView::GetMessageDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->message.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void ConnectionMessageDataView::GetDataDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->data.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

    inline void PresentationConnection_OnMessage_ParamsDataView::GetMessageDataView(
        ConnectionMessageDataView* output)
    {
        auto pointer = data_->message.Get();
        *output = ConnectionMessageDataView(pointer, context_);
    }

    inline void PresentationService_SetDefaultPresentationUrls_ParamsDataView::GetPresentationUrlsDataView(
        mojo::ArrayDataView<::url::mojom::UrlDataView>* output)
    {
        auto pointer = data_->presentation_urls.Get();
        *output = mojo::ArrayDataView<::url::mojom::UrlDataView>(pointer, context_);
    }

    inline void PresentationService_ListenForScreenAvailability_ParamsDataView::GetAvailabilityUrlDataView(
        ::url::mojom::UrlDataView* output)
    {
        auto pointer = data_->availability_url.Get();
        *output = ::url::mojom::UrlDataView(pointer, context_);
    }

    inline void PresentationService_StopListeningForScreenAvailability_ParamsDataView::GetAvailabilityUrlDataView(
        ::url::mojom::UrlDataView* output)
    {
        auto pointer = data_->availability_url.Get();
        *output = ::url::mojom::UrlDataView(pointer, context_);
    }

    inline void PresentationService_StartSession_ParamsDataView::GetPresentationUrlsDataView(
        mojo::ArrayDataView<::url::mojom::UrlDataView>* output)
    {
        auto pointer = data_->presentation_urls.Get();
        *output = mojo::ArrayDataView<::url::mojom::UrlDataView>(pointer, context_);
    }

    inline void PresentationService_StartSession_ResponseParamsDataView::GetSessioninfoDataView(
        PresentationSessionInfoDataView* output)
    {
        auto pointer = data_->sessionInfo.Get();
        *output = PresentationSessionInfoDataView(pointer, context_);
    }
    inline void PresentationService_StartSession_ResponseParamsDataView::GetErrorDataView(
        PresentationErrorDataView* output)
    {
        auto pointer = data_->error.Get();
        *output = PresentationErrorDataView(pointer, context_);
    }

    inline void PresentationService_JoinSession_ParamsDataView::GetPresentationUrlsDataView(
        mojo::ArrayDataView<::url::mojom::UrlDataView>* output)
    {
        auto pointer = data_->presentation_urls.Get();
        *output = mojo::ArrayDataView<::url::mojom::UrlDataView>(pointer, context_);
    }
    inline void PresentationService_JoinSession_ParamsDataView::GetPresentationIdDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->presentation_id.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void PresentationService_JoinSession_ResponseParamsDataView::GetSessioninfoDataView(
        PresentationSessionInfoDataView* output)
    {
        auto pointer = data_->sessionInfo.Get();
        *output = PresentationSessionInfoDataView(pointer, context_);
    }
    inline void PresentationService_JoinSession_ResponseParamsDataView::GetErrorDataView(
        PresentationErrorDataView* output)
    {
        auto pointer = data_->error.Get();
        *output = PresentationErrorDataView(pointer, context_);
    }

    inline void PresentationService_SetPresentationConnection_ParamsDataView::GetSessioninfoDataView(
        PresentationSessionInfoDataView* output)
    {
        auto pointer = data_->sessionInfo.Get();
        *output = PresentationSessionInfoDataView(pointer, context_);
    }

    inline void PresentationService_SendConnectionMessage_ParamsDataView::GetSessioninfoDataView(
        PresentationSessionInfoDataView* output)
    {
        auto pointer = data_->sessionInfo.Get();
        *output = PresentationSessionInfoDataView(pointer, context_);
    }
    inline void PresentationService_SendConnectionMessage_ParamsDataView::GetMessageRequestDataView(
        ConnectionMessageDataView* output)
    {
        auto pointer = data_->message_request.Get();
        *output = ConnectionMessageDataView(pointer, context_);
    }

    inline void PresentationService_CloseConnection_ParamsDataView::GetPresentationUrlDataView(
        ::url::mojom::UrlDataView* output)
    {
        auto pointer = data_->presentation_url.Get();
        *output = ::url::mojom::UrlDataView(pointer, context_);
    }
    inline void PresentationService_CloseConnection_ParamsDataView::GetPresentationIdDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->presentation_id.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void PresentationService_Terminate_ParamsDataView::GetPresentationUrlDataView(
        ::url::mojom::UrlDataView* output)
    {
        auto pointer = data_->presentation_url.Get();
        *output = ::url::mojom::UrlDataView(pointer, context_);
    }
    inline void PresentationService_Terminate_ParamsDataView::GetPresentationIdDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->presentation_id.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void PresentationService_ListenForConnectionMessages_ParamsDataView::GetSessioninfoDataView(
        PresentationSessionInfoDataView* output)
    {
        auto pointer = data_->sessionInfo.Get();
        *output = PresentationSessionInfoDataView(pointer, context_);
    }

    inline void PresentationServiceClient_OnScreenAvailabilityNotSupported_ParamsDataView::GetUrlDataView(
        ::url::mojom::UrlDataView* output)
    {
        auto pointer = data_->url.Get();
        *output = ::url::mojom::UrlDataView(pointer, context_);
    }

    inline void PresentationServiceClient_OnScreenAvailabilityUpdated_ParamsDataView::GetUrlDataView(
        ::url::mojom::UrlDataView* output)
    {
        auto pointer = data_->url.Get();
        *output = ::url::mojom::UrlDataView(pointer, context_);
    }

    inline void PresentationServiceClient_OnDefaultSessionStarted_ParamsDataView::GetSessioninfoDataView(
        PresentationSessionInfoDataView* output)
    {
        auto pointer = data_->sessionInfo.Get();
        *output = PresentationSessionInfoDataView(pointer, context_);
    }

    inline void PresentationServiceClient_OnConnectionStateChanged_ParamsDataView::GetConnectionDataView(
        PresentationSessionInfoDataView* output)
    {
        auto pointer = data_->connection.Get();
        *output = PresentationSessionInfoDataView(pointer, context_);
    }

    inline void PresentationServiceClient_OnConnectionClosed_ParamsDataView::GetConnectionDataView(
        PresentationSessionInfoDataView* output)
    {
        auto pointer = data_->connection.Get();
        *output = PresentationSessionInfoDataView(pointer, context_);
    }
    inline void PresentationServiceClient_OnConnectionClosed_ParamsDataView::GetMessageDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->message.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void PresentationServiceClient_OnConnectionMessagesReceived_ParamsDataView::GetSessioninfoDataView(
        PresentationSessionInfoDataView* output)
    {
        auto pointer = data_->sessionInfo.Get();
        *output = PresentationSessionInfoDataView(pointer, context_);
    }
    inline void PresentationServiceClient_OnConnectionMessagesReceived_ParamsDataView::GetMessagesDataView(
        mojo::ArrayDataView<ConnectionMessageDataView>* output)
    {
        auto pointer = data_->messages.Get();
        *output = mojo::ArrayDataView<ConnectionMessageDataView>(pointer, context_);
    }

    inline void PresentationServiceClient_OnReceiverConnectionAvailable_ParamsDataView::GetSessioninfoDataView(
        PresentationSessionInfoDataView* output)
    {
        auto pointer = data_->sessionInfo.Get();
        *output = PresentationSessionInfoDataView(pointer, context_);
    }

} // namespace mojom
} // namespace blink

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_PRESENTATION_PRESENTATION_MOJOM_SHARED_H_
