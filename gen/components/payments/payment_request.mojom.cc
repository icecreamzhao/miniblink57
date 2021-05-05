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

#include "components/payments/payment_request.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "ipc/ipc_message_utils.h"
#include "mojo/common/common_custom_types_struct_traits.h"
#include "mojo/common/values_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
namespace payments {
namespace mojom { // static
    PaymentAddressPtr PaymentAddress::New()
    {
        PaymentAddressPtr rv;
        mojo::internal::StructHelper<PaymentAddress>::Initialize(&rv);
        return rv;
    }

    PaymentAddress::PaymentAddress()
        : country()
        , address_line()
        , region()
        , city()
        , dependent_locality()
        , postal_code()
        , sorting_code()
        , language_code()
        , script_code()
        , organization()
        , recipient()
        , phone()
    {
    }

    PaymentAddress::~PaymentAddress()
    {
    } // static
    PaymentCurrencyAmountPtr PaymentCurrencyAmount::New()
    {
        PaymentCurrencyAmountPtr rv;
        mojo::internal::StructHelper<PaymentCurrencyAmount>::Initialize(&rv);
        return rv;
    }

    PaymentCurrencyAmount::PaymentCurrencyAmount()
        : currency()
        , value()
        , currency_system()
    {
    }

    PaymentCurrencyAmount::~PaymentCurrencyAmount()
    {
    } // static
    PaymentResponsePtr PaymentResponse::New()
    {
        PaymentResponsePtr rv;
        mojo::internal::StructHelper<PaymentResponse>::Initialize(&rv);
        return rv;
    }

    PaymentResponse::PaymentResponse()
        : method_name()
        , stringified_details()
        , shipping_address()
        , shipping_option()
        , payer_name()
        , payer_email()
        , payer_phone()
    {
    }

    PaymentResponse::~PaymentResponse()
    {
    } // static
    PaymentItemPtr PaymentItem::New()
    {
        PaymentItemPtr rv;
        mojo::internal::StructHelper<PaymentItem>::Initialize(&rv);
        return rv;
    }

    PaymentItem::PaymentItem()
        : label()
        , amount()
        , pending()
    {
    }

    PaymentItem::~PaymentItem()
    {
    } // static
    PaymentShippingOptionPtr PaymentShippingOption::New()
    {
        PaymentShippingOptionPtr rv;
        mojo::internal::StructHelper<PaymentShippingOption>::Initialize(&rv);
        return rv;
    }

    PaymentShippingOption::PaymentShippingOption()
        : id()
        , label()
        , amount()
        , selected()
    {
    }

    PaymentShippingOption::~PaymentShippingOption()
    {
    } // static
    AndroidPayTokenizationParameterPtr AndroidPayTokenizationParameter::New()
    {
        AndroidPayTokenizationParameterPtr rv;
        mojo::internal::StructHelper<AndroidPayTokenizationParameter>::Initialize(&rv);
        return rv;
    }

    AndroidPayTokenizationParameter::AndroidPayTokenizationParameter()
        : key()
        , value()
    {
    }

    AndroidPayTokenizationParameter::~AndroidPayTokenizationParameter()
    {
    } // static
    PaymentMethodDataPtr PaymentMethodData::New()
    {
        PaymentMethodDataPtr rv;
        mojo::internal::StructHelper<PaymentMethodData>::Initialize(&rv);
        return rv;
    }

    PaymentMethodData::PaymentMethodData()
        : supported_methods()
        , stringified_data()
        , environment()
        , merchant_name()
        , merchant_id()
        , allowed_card_networks()
        , tokenization_type()
        , parameters()
        , min_google_play_services_version()
        , supported_networks()
        , supported_types()
    {
    }

    PaymentMethodData::~PaymentMethodData()
    {
    } // static
    PaymentDetailsModifierPtr PaymentDetailsModifier::New()
    {
        PaymentDetailsModifierPtr rv;
        mojo::internal::StructHelper<PaymentDetailsModifier>::Initialize(&rv);
        return rv;
    }

    PaymentDetailsModifier::PaymentDetailsModifier()
        : total()
        , additional_display_items()
        , method_data()
    {
    }

    PaymentDetailsModifier::~PaymentDetailsModifier()
    {
    } // static
    PaymentDetailsPtr PaymentDetails::New()
    {
        PaymentDetailsPtr rv;
        mojo::internal::StructHelper<PaymentDetails>::Initialize(&rv);
        return rv;
    }

    PaymentDetails::PaymentDetails()
        : total()
        , display_items()
        , shipping_options()
        , modifiers()
        , error()
    {
    }

    PaymentDetails::~PaymentDetails()
    {
    } // static
    PaymentOptionsPtr PaymentOptions::New()
    {
        PaymentOptionsPtr rv;
        mojo::internal::StructHelper<PaymentOptions>::Initialize(&rv);
        return rv;
    }

    PaymentOptions::PaymentOptions()
        : request_payer_name()
        , request_payer_email()
        , request_payer_phone()
        , request_shipping()
        , shipping_type()
    {
    }

    PaymentOptions::~PaymentOptions()
    {
    }
    size_t PaymentOptions::Hash(size_t seed) const
    {
        seed = mojo::internal::Hash(seed, this->request_payer_name);
        seed = mojo::internal::Hash(seed, this->request_payer_email);
        seed = mojo::internal::Hash(seed, this->request_payer_phone);
        seed = mojo::internal::Hash(seed, this->request_shipping);
        seed = mojo::internal::Hash(seed, this->shipping_type);
        return seed;
    }
    const char PaymentRequestClient::Name_[] = "payments::mojom::PaymentRequestClient";

    PaymentRequestClientProxy::PaymentRequestClientProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void PaymentRequestClientProxy::OnShippingAddressChange(
        PaymentAddressPtr in_address)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::payments::mojom::internal::PaymentRequestClient_OnShippingAddressChange_Params_Data);
        size += mojo::internal::PrepareToSerialize<::payments::mojom::PaymentAddressDataView>(
            in_address, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kPaymentRequestClient_OnShippingAddressChange_Name, size);

        auto params = ::payments::mojom::internal::PaymentRequestClient_OnShippingAddressChange_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->address)::BaseType* address_ptr;
        mojo::internal::Serialize<::payments::mojom::PaymentAddressDataView>(
            in_address, builder.buffer(), &address_ptr, &serialization_context);
        params->address.Set(address_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->address.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null address in PaymentRequestClient.OnShippingAddressChange request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PaymentRequestClientProxy::OnShippingOptionChange(
        const std::string& in_shipping_option_id)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::payments::mojom::internal::PaymentRequestClient_OnShippingOptionChange_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_shipping_option_id, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kPaymentRequestClient_OnShippingOptionChange_Name, size);

        auto params = ::payments::mojom::internal::PaymentRequestClient_OnShippingOptionChange_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->shipping_option_id)::BaseType* shipping_option_id_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_shipping_option_id, builder.buffer(), &shipping_option_id_ptr, &serialization_context);
        params->shipping_option_id.Set(shipping_option_id_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->shipping_option_id.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null shipping_option_id in PaymentRequestClient.OnShippingOptionChange request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PaymentRequestClientProxy::OnPaymentResponse(
        PaymentResponsePtr in_response)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::payments::mojom::internal::PaymentRequestClient_OnPaymentResponse_Params_Data);
        size += mojo::internal::PrepareToSerialize<::payments::mojom::PaymentResponseDataView>(
            in_response, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kPaymentRequestClient_OnPaymentResponse_Name, size);

        auto params = ::payments::mojom::internal::PaymentRequestClient_OnPaymentResponse_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->response)::BaseType* response_ptr;
        mojo::internal::Serialize<::payments::mojom::PaymentResponseDataView>(
            in_response, builder.buffer(), &response_ptr, &serialization_context);
        params->response.Set(response_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->response.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null response in PaymentRequestClient.OnPaymentResponse request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PaymentRequestClientProxy::OnError(
        PaymentErrorReason in_error)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::payments::mojom::internal::PaymentRequestClient_OnError_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kPaymentRequestClient_OnError_Name, size);

        auto params = ::payments::mojom::internal::PaymentRequestClient_OnError_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::payments::mojom::PaymentErrorReason>(
            in_error, &params->error);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PaymentRequestClientProxy::OnComplete()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::payments::mojom::internal::PaymentRequestClient_OnComplete_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kPaymentRequestClient_OnComplete_Name, size);

        auto params = ::payments::mojom::internal::PaymentRequestClient_OnComplete_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PaymentRequestClientProxy::OnAbort(
        bool in_aborted_successfully)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::payments::mojom::internal::PaymentRequestClient_OnAbort_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kPaymentRequestClient_OnAbort_Name, size);

        auto params = ::payments::mojom::internal::PaymentRequestClient_OnAbort_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->aborted_successfully = in_aborted_successfully;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PaymentRequestClientProxy::OnCanMakePayment(
        CanMakePaymentQueryResult in_result)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::payments::mojom::internal::PaymentRequestClient_OnCanMakePayment_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kPaymentRequestClient_OnCanMakePayment_Name, size);

        auto params = ::payments::mojom::internal::PaymentRequestClient_OnCanMakePayment_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::payments::mojom::CanMakePaymentQueryResult>(
            in_result, &params->result);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool PaymentRequestClientStubDispatch::Accept(
        PaymentRequestClient* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kPaymentRequestClient_OnShippingAddressChange_Name: {
            internal::PaymentRequestClient_OnShippingAddressChange_Params_Data* params = reinterpret_cast<internal::PaymentRequestClient_OnShippingAddressChange_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            PaymentAddressPtr p_address {};
            PaymentRequestClient_OnShippingAddressChange_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadAddress(&p_address))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PaymentRequestClient::OnShippingAddressChange deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PaymentRequestClient::OnShippingAddressChange");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnShippingAddressChange(
                std::move(p_address));
            return true;
        }
        case internal::kPaymentRequestClient_OnShippingOptionChange_Name: {
            internal::PaymentRequestClient_OnShippingOptionChange_Params_Data* params = reinterpret_cast<internal::PaymentRequestClient_OnShippingOptionChange_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_shipping_option_id {};
            PaymentRequestClient_OnShippingOptionChange_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadShippingOptionId(&p_shipping_option_id))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PaymentRequestClient::OnShippingOptionChange deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PaymentRequestClient::OnShippingOptionChange");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnShippingOptionChange(
                std::move(p_shipping_option_id));
            return true;
        }
        case internal::kPaymentRequestClient_OnPaymentResponse_Name: {
            internal::PaymentRequestClient_OnPaymentResponse_Params_Data* params = reinterpret_cast<internal::PaymentRequestClient_OnPaymentResponse_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            PaymentResponsePtr p_response {};
            PaymentRequestClient_OnPaymentResponse_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadResponse(&p_response))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PaymentRequestClient::OnPaymentResponse deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PaymentRequestClient::OnPaymentResponse");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnPaymentResponse(
                std::move(p_response));
            return true;
        }
        case internal::kPaymentRequestClient_OnError_Name: {
            internal::PaymentRequestClient_OnError_Params_Data* params = reinterpret_cast<internal::PaymentRequestClient_OnError_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            PaymentErrorReason p_error {};
            PaymentRequestClient_OnError_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadError(&p_error))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PaymentRequestClient::OnError deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PaymentRequestClient::OnError");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnError(
                std::move(p_error));
            return true;
        }
        case internal::kPaymentRequestClient_OnComplete_Name: {
            internal::PaymentRequestClient_OnComplete_Params_Data* params = reinterpret_cast<internal::PaymentRequestClient_OnComplete_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            PaymentRequestClient_OnComplete_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PaymentRequestClient::OnComplete deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PaymentRequestClient::OnComplete");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnComplete();
            return true;
        }
        case internal::kPaymentRequestClient_OnAbort_Name: {
            internal::PaymentRequestClient_OnAbort_Params_Data* params = reinterpret_cast<internal::PaymentRequestClient_OnAbort_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            bool p_aborted_successfully {};
            PaymentRequestClient_OnAbort_ParamsDataView input_data_view(params,
                context);

            p_aborted_successfully = input_data_view.aborted_successfully();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PaymentRequestClient::OnAbort deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PaymentRequestClient::OnAbort");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnAbort(
                std::move(p_aborted_successfully));
            return true;
        }
        case internal::kPaymentRequestClient_OnCanMakePayment_Name: {
            internal::PaymentRequestClient_OnCanMakePayment_Params_Data* params = reinterpret_cast<internal::PaymentRequestClient_OnCanMakePayment_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            CanMakePaymentQueryResult p_result {};
            PaymentRequestClient_OnCanMakePayment_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadResult(&p_result))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PaymentRequestClient::OnCanMakePayment deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PaymentRequestClient::OnCanMakePayment");
            mojo::internal::MessageDispatchContext context(message);
            impl->OnCanMakePayment(
                std::move(p_result));
            return true;
        }
        }
        return false;
    }

    // static
    bool PaymentRequestClientStubDispatch::AcceptWithResponder(
        PaymentRequestClient* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kPaymentRequestClient_OnShippingAddressChange_Name: {
            break;
        }
        case internal::kPaymentRequestClient_OnShippingOptionChange_Name: {
            break;
        }
        case internal::kPaymentRequestClient_OnPaymentResponse_Name: {
            break;
        }
        case internal::kPaymentRequestClient_OnError_Name: {
            break;
        }
        case internal::kPaymentRequestClient_OnComplete_Name: {
            break;
        }
        case internal::kPaymentRequestClient_OnAbort_Name: {
            break;
        }
        case internal::kPaymentRequestClient_OnCanMakePayment_Name: {
            break;
        }
        }
        return false;
    }

    bool PaymentRequestClientRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "PaymentRequestClient RequestValidator");

        switch (message->header()->name) {
        case internal::kPaymentRequestClient_OnShippingAddressChange_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PaymentRequestClient_OnShippingAddressChange_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPaymentRequestClient_OnShippingOptionChange_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PaymentRequestClient_OnShippingOptionChange_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPaymentRequestClient_OnPaymentResponse_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PaymentRequestClient_OnPaymentResponse_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPaymentRequestClient_OnError_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PaymentRequestClient_OnError_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPaymentRequestClient_OnComplete_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PaymentRequestClient_OnComplete_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPaymentRequestClient_OnAbort_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PaymentRequestClient_OnAbort_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPaymentRequestClient_OnCanMakePayment_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PaymentRequestClient_OnCanMakePayment_Params_Data>(
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

    const char PaymentRequest::Name_[] = "payments::mojom::PaymentRequest";

    PaymentRequestProxy::PaymentRequestProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void PaymentRequestProxy::Init(
        PaymentRequestClientPtr in_client, std::vector<PaymentMethodDataPtr> in_method_data, PaymentDetailsPtr in_details, PaymentOptionsPtr in_options)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::payments::mojom::internal::PaymentRequest_Init_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::payments::mojom::PaymentMethodDataDataView>>(
            in_method_data, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::payments::mojom::PaymentDetailsDataView>(
            in_details, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::payments::mojom::PaymentOptionsDataView>(
            in_options, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kPaymentRequest_Init_Name, size);

        auto params = ::payments::mojom::internal::PaymentRequest_Init_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::payments::mojom::PaymentRequestClientPtrDataView>(
            in_client, &params->client, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->client),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid client in PaymentRequest.Init request");
        typename decltype(params->method_data)::BaseType* method_data_ptr;
        const mojo::internal::ContainerValidateParams method_data_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::payments::mojom::PaymentMethodDataDataView>>(
            in_method_data, builder.buffer(), &method_data_ptr, &method_data_validate_params,
            &serialization_context);
        params->method_data.Set(method_data_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->method_data.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null method_data in PaymentRequest.Init request");
        typename decltype(params->details)::BaseType* details_ptr;
        mojo::internal::Serialize<::payments::mojom::PaymentDetailsDataView>(
            in_details, builder.buffer(), &details_ptr, &serialization_context);
        params->details.Set(details_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->details.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null details in PaymentRequest.Init request");
        typename decltype(params->options)::BaseType* options_ptr;
        mojo::internal::Serialize<::payments::mojom::PaymentOptionsDataView>(
            in_options, builder.buffer(), &options_ptr, &serialization_context);
        params->options.Set(options_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->options.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null options in PaymentRequest.Init request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PaymentRequestProxy::Show()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::payments::mojom::internal::PaymentRequest_Show_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kPaymentRequest_Show_Name, size);

        auto params = ::payments::mojom::internal::PaymentRequest_Show_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PaymentRequestProxy::UpdateWith(
        PaymentDetailsPtr in_details)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::payments::mojom::internal::PaymentRequest_UpdateWith_Params_Data);
        size += mojo::internal::PrepareToSerialize<::payments::mojom::PaymentDetailsDataView>(
            in_details, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kPaymentRequest_UpdateWith_Name, size);

        auto params = ::payments::mojom::internal::PaymentRequest_UpdateWith_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->details)::BaseType* details_ptr;
        mojo::internal::Serialize<::payments::mojom::PaymentDetailsDataView>(
            in_details, builder.buffer(), &details_ptr, &serialization_context);
        params->details.Set(details_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->details.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null details in PaymentRequest.UpdateWith request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PaymentRequestProxy::Abort()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::payments::mojom::internal::PaymentRequest_Abort_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kPaymentRequest_Abort_Name, size);

        auto params = ::payments::mojom::internal::PaymentRequest_Abort_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PaymentRequestProxy::Complete(
        PaymentComplete in_result)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::payments::mojom::internal::PaymentRequest_Complete_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kPaymentRequest_Complete_Name, size);

        auto params = ::payments::mojom::internal::PaymentRequest_Complete_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::payments::mojom::PaymentComplete>(
            in_result, &params->result);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PaymentRequestProxy::CanMakePayment()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::payments::mojom::internal::PaymentRequest_CanMakePayment_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kPaymentRequest_CanMakePayment_Name, size);

        auto params = ::payments::mojom::internal::PaymentRequest_CanMakePayment_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool PaymentRequestStubDispatch::Accept(
        PaymentRequest* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kPaymentRequest_Init_Name: {
            internal::PaymentRequest_Init_Params_Data* params = reinterpret_cast<internal::PaymentRequest_Init_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            PaymentRequestClientPtr p_client {};
            std::vector<PaymentMethodDataPtr> p_method_data {};
            PaymentDetailsPtr p_details {};
            PaymentOptionsPtr p_options {};
            PaymentRequest_Init_ParamsDataView input_data_view(params,
                context);

            p_client = input_data_view.TakeClient<decltype(p_client)>();
            if (!input_data_view.ReadMethodData(&p_method_data))
                success = false;
            if (!input_data_view.ReadDetails(&p_details))
                success = false;
            if (!input_data_view.ReadOptions(&p_options))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PaymentRequest::Init deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PaymentRequest::Init");
            mojo::internal::MessageDispatchContext context(message);
            impl->Init(
                std::move(p_client),
                std::move(p_method_data),
                std::move(p_details),
                std::move(p_options));
            return true;
        }
        case internal::kPaymentRequest_Show_Name: {
            internal::PaymentRequest_Show_Params_Data* params = reinterpret_cast<internal::PaymentRequest_Show_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            PaymentRequest_Show_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PaymentRequest::Show deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PaymentRequest::Show");
            mojo::internal::MessageDispatchContext context(message);
            impl->Show();
            return true;
        }
        case internal::kPaymentRequest_UpdateWith_Name: {
            internal::PaymentRequest_UpdateWith_Params_Data* params = reinterpret_cast<internal::PaymentRequest_UpdateWith_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            PaymentDetailsPtr p_details {};
            PaymentRequest_UpdateWith_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadDetails(&p_details))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PaymentRequest::UpdateWith deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PaymentRequest::UpdateWith");
            mojo::internal::MessageDispatchContext context(message);
            impl->UpdateWith(
                std::move(p_details));
            return true;
        }
        case internal::kPaymentRequest_Abort_Name: {
            internal::PaymentRequest_Abort_Params_Data* params = reinterpret_cast<internal::PaymentRequest_Abort_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            PaymentRequest_Abort_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PaymentRequest::Abort deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PaymentRequest::Abort");
            mojo::internal::MessageDispatchContext context(message);
            impl->Abort();
            return true;
        }
        case internal::kPaymentRequest_Complete_Name: {
            internal::PaymentRequest_Complete_Params_Data* params = reinterpret_cast<internal::PaymentRequest_Complete_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            PaymentComplete p_result {};
            PaymentRequest_Complete_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadResult(&p_result))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PaymentRequest::Complete deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PaymentRequest::Complete");
            mojo::internal::MessageDispatchContext context(message);
            impl->Complete(
                std::move(p_result));
            return true;
        }
        case internal::kPaymentRequest_CanMakePayment_Name: {
            internal::PaymentRequest_CanMakePayment_Params_Data* params = reinterpret_cast<internal::PaymentRequest_CanMakePayment_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            PaymentRequest_CanMakePayment_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PaymentRequest::CanMakePayment deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PaymentRequest::CanMakePayment");
            mojo::internal::MessageDispatchContext context(message);
            impl->CanMakePayment();
            return true;
        }
        }
        return false;
    }

    // static
    bool PaymentRequestStubDispatch::AcceptWithResponder(
        PaymentRequest* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kPaymentRequest_Init_Name: {
            break;
        }
        case internal::kPaymentRequest_Show_Name: {
            break;
        }
        case internal::kPaymentRequest_UpdateWith_Name: {
            break;
        }
        case internal::kPaymentRequest_Abort_Name: {
            break;
        }
        case internal::kPaymentRequest_Complete_Name: {
            break;
        }
        case internal::kPaymentRequest_CanMakePayment_Name: {
            break;
        }
        }
        return false;
    }

    bool PaymentRequestRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "PaymentRequest RequestValidator");

        switch (message->header()->name) {
        case internal::kPaymentRequest_Init_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PaymentRequest_Init_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPaymentRequest_Show_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PaymentRequest_Show_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPaymentRequest_UpdateWith_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PaymentRequest_UpdateWith_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPaymentRequest_Abort_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PaymentRequest_Abort_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPaymentRequest_Complete_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PaymentRequest_Complete_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPaymentRequest_CanMakePayment_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PaymentRequest_CanMakePayment_Params_Data>(
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
} // namespace payments

namespace mojo {

// static
bool StructTraits<::payments::mojom::PaymentAddress::DataView, ::payments::mojom::PaymentAddressPtr>::Read(
    ::payments::mojom::PaymentAddress::DataView input,
    ::payments::mojom::PaymentAddressPtr* output)
{
    bool success = true;
    ::payments::mojom::PaymentAddressPtr result(::payments::mojom::PaymentAddress::New());

    if (!input.ReadCountry(&result->country))
        success = false;
    if (!input.ReadAddressLine(&result->address_line))
        success = false;
    if (!input.ReadRegion(&result->region))
        success = false;
    if (!input.ReadCity(&result->city))
        success = false;
    if (!input.ReadDependentLocality(&result->dependent_locality))
        success = false;
    if (!input.ReadPostalCode(&result->postal_code))
        success = false;
    if (!input.ReadSortingCode(&result->sorting_code))
        success = false;
    if (!input.ReadLanguageCode(&result->language_code))
        success = false;
    if (!input.ReadScriptCode(&result->script_code))
        success = false;
    if (!input.ReadOrganization(&result->organization))
        success = false;
    if (!input.ReadRecipient(&result->recipient))
        success = false;
    if (!input.ReadPhone(&result->phone))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::payments::mojom::PaymentCurrencyAmount::DataView, ::payments::mojom::PaymentCurrencyAmountPtr>::Read(
    ::payments::mojom::PaymentCurrencyAmount::DataView input,
    ::payments::mojom::PaymentCurrencyAmountPtr* output)
{
    bool success = true;
    ::payments::mojom::PaymentCurrencyAmountPtr result(::payments::mojom::PaymentCurrencyAmount::New());

    if (!input.ReadCurrency(&result->currency))
        success = false;
    if (!input.ReadValue(&result->value))
        success = false;
    if (!input.ReadCurrencySystem(&result->currency_system))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::payments::mojom::PaymentResponse::DataView, ::payments::mojom::PaymentResponsePtr>::Read(
    ::payments::mojom::PaymentResponse::DataView input,
    ::payments::mojom::PaymentResponsePtr* output)
{
    bool success = true;
    ::payments::mojom::PaymentResponsePtr result(::payments::mojom::PaymentResponse::New());

    if (!input.ReadMethodName(&result->method_name))
        success = false;
    if (!input.ReadStringifiedDetails(&result->stringified_details))
        success = false;
    if (!input.ReadShippingAddress(&result->shipping_address))
        success = false;
    if (!input.ReadShippingOption(&result->shipping_option))
        success = false;
    if (!input.ReadPayerName(&result->payer_name))
        success = false;
    if (!input.ReadPayerEmail(&result->payer_email))
        success = false;
    if (!input.ReadPayerPhone(&result->payer_phone))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::payments::mojom::PaymentItem::DataView, ::payments::mojom::PaymentItemPtr>::Read(
    ::payments::mojom::PaymentItem::DataView input,
    ::payments::mojom::PaymentItemPtr* output)
{
    bool success = true;
    ::payments::mojom::PaymentItemPtr result(::payments::mojom::PaymentItem::New());

    if (!input.ReadLabel(&result->label))
        success = false;
    if (!input.ReadAmount(&result->amount))
        success = false;
    result->pending = input.pending();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::payments::mojom::PaymentShippingOption::DataView, ::payments::mojom::PaymentShippingOptionPtr>::Read(
    ::payments::mojom::PaymentShippingOption::DataView input,
    ::payments::mojom::PaymentShippingOptionPtr* output)
{
    bool success = true;
    ::payments::mojom::PaymentShippingOptionPtr result(::payments::mojom::PaymentShippingOption::New());

    if (!input.ReadId(&result->id))
        success = false;
    if (!input.ReadLabel(&result->label))
        success = false;
    if (!input.ReadAmount(&result->amount))
        success = false;
    result->selected = input.selected();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::payments::mojom::AndroidPayTokenizationParameter::DataView, ::payments::mojom::AndroidPayTokenizationParameterPtr>::Read(
    ::payments::mojom::AndroidPayTokenizationParameter::DataView input,
    ::payments::mojom::AndroidPayTokenizationParameterPtr* output)
{
    bool success = true;
    ::payments::mojom::AndroidPayTokenizationParameterPtr result(::payments::mojom::AndroidPayTokenizationParameter::New());

    if (!input.ReadKey(&result->key))
        success = false;
    if (!input.ReadValue(&result->value))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::payments::mojom::PaymentMethodData::DataView, ::payments::mojom::PaymentMethodDataPtr>::Read(
    ::payments::mojom::PaymentMethodData::DataView input,
    ::payments::mojom::PaymentMethodDataPtr* output)
{
    bool success = true;
    ::payments::mojom::PaymentMethodDataPtr result(::payments::mojom::PaymentMethodData::New());

    if (!input.ReadSupportedMethods(&result->supported_methods))
        success = false;
    if (!input.ReadStringifiedData(&result->stringified_data))
        success = false;
    if (!input.ReadEnvironment(&result->environment))
        success = false;
    if (!input.ReadMerchantName(&result->merchant_name))
        success = false;
    if (!input.ReadMerchantId(&result->merchant_id))
        success = false;
    if (!input.ReadAllowedCardNetworks(&result->allowed_card_networks))
        success = false;
    if (!input.ReadTokenizationType(&result->tokenization_type))
        success = false;
    if (!input.ReadParameters(&result->parameters))
        success = false;
    result->min_google_play_services_version = input.min_google_play_services_version();
    if (!input.ReadSupportedNetworks(&result->supported_networks))
        success = false;
    if (!input.ReadSupportedTypes(&result->supported_types))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::payments::mojom::PaymentDetailsModifier::DataView, ::payments::mojom::PaymentDetailsModifierPtr>::Read(
    ::payments::mojom::PaymentDetailsModifier::DataView input,
    ::payments::mojom::PaymentDetailsModifierPtr* output)
{
    bool success = true;
    ::payments::mojom::PaymentDetailsModifierPtr result(::payments::mojom::PaymentDetailsModifier::New());

    if (!input.ReadTotal(&result->total))
        success = false;
    if (!input.ReadAdditionalDisplayItems(&result->additional_display_items))
        success = false;
    if (!input.ReadMethodData(&result->method_data))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::payments::mojom::PaymentDetails::DataView, ::payments::mojom::PaymentDetailsPtr>::Read(
    ::payments::mojom::PaymentDetails::DataView input,
    ::payments::mojom::PaymentDetailsPtr* output)
{
    bool success = true;
    ::payments::mojom::PaymentDetailsPtr result(::payments::mojom::PaymentDetails::New());

    if (!input.ReadTotal(&result->total))
        success = false;
    if (!input.ReadDisplayItems(&result->display_items))
        success = false;
    if (!input.ReadShippingOptions(&result->shipping_options))
        success = false;
    if (!input.ReadModifiers(&result->modifiers))
        success = false;
    if (!input.ReadError(&result->error))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::payments::mojom::PaymentOptions::DataView, ::payments::mojom::PaymentOptionsPtr>::Read(
    ::payments::mojom::PaymentOptions::DataView input,
    ::payments::mojom::PaymentOptionsPtr* output)
{
    bool success = true;
    ::payments::mojom::PaymentOptionsPtr result(::payments::mojom::PaymentOptions::New());

    result->request_payer_name = input.request_payer_name();
    result->request_payer_email = input.request_payer_email();
    result->request_payer_phone = input.request_payer_phone();
    result->request_shipping = input.request_shipping();
    if (!input.ReadShippingType(&result->shipping_type))
        success = false;
    *output = std::move(result);
    return success;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif