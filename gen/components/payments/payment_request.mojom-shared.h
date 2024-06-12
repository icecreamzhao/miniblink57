// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_PAYMENTS_PAYMENT_REQUEST_MOJOM_SHARED_H_
#define COMPONENTS_PAYMENTS_PAYMENT_REQUEST_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "components/payments/payment_request.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"

namespace payments {
namespace mojom {
    class PaymentAddressDataView;

    class PaymentCurrencyAmountDataView;

    class PaymentResponseDataView;

    class PaymentItemDataView;

    class PaymentShippingOptionDataView;

    class AndroidPayTokenizationParameterDataView;

    class PaymentMethodDataDataView;

    class PaymentDetailsModifierDataView;

    class PaymentDetailsDataView;

    class PaymentOptionsDataView;

} // namespace mojom
} // namespace payments

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::payments::mojom::PaymentAddressDataView> {
        using Data = ::payments::mojom::internal::PaymentAddress_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::payments::mojom::PaymentCurrencyAmountDataView> {
        using Data = ::payments::mojom::internal::PaymentCurrencyAmount_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::payments::mojom::PaymentResponseDataView> {
        using Data = ::payments::mojom::internal::PaymentResponse_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::payments::mojom::PaymentItemDataView> {
        using Data = ::payments::mojom::internal::PaymentItem_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::payments::mojom::PaymentShippingOptionDataView> {
        using Data = ::payments::mojom::internal::PaymentShippingOption_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::payments::mojom::AndroidPayTokenizationParameterDataView> {
        using Data = ::payments::mojom::internal::AndroidPayTokenizationParameter_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::payments::mojom::PaymentMethodDataDataView> {
        using Data = ::payments::mojom::internal::PaymentMethodData_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::payments::mojom::PaymentDetailsModifierDataView> {
        using Data = ::payments::mojom::internal::PaymentDetailsModifier_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::payments::mojom::PaymentDetailsDataView> {
        using Data = ::payments::mojom::internal::PaymentDetails_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::payments::mojom::PaymentOptionsDataView> {
        using Data = ::payments::mojom::internal::PaymentOptions_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace payments {
namespace mojom {

    enum class PaymentErrorReason : int32_t {
        UNKNOWN,
        USER_CANCEL,
        NOT_SUPPORTED,
    };

    inline std::ostream& operator<<(std::ostream& os, PaymentErrorReason value)
    {
        switch (value) {
        case PaymentErrorReason::UNKNOWN:
            return os << "PaymentErrorReason::UNKNOWN";
        case PaymentErrorReason::USER_CANCEL:
            return os << "PaymentErrorReason::USER_CANCEL";
        case PaymentErrorReason::NOT_SUPPORTED:
            return os << "PaymentErrorReason::NOT_SUPPORTED";
        default:
            return os << "Unknown PaymentErrorReason value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(PaymentErrorReason value)
    {
        return internal::PaymentErrorReason_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class CanMakePaymentQueryResult : int32_t {
        CAN_MAKE_PAYMENT,
        CANNOT_MAKE_PAYMENT,
        QUERY_QUOTA_EXCEEDED,
    };

    inline std::ostream& operator<<(std::ostream& os, CanMakePaymentQueryResult value)
    {
        switch (value) {
        case CanMakePaymentQueryResult::CAN_MAKE_PAYMENT:
            return os << "CanMakePaymentQueryResult::CAN_MAKE_PAYMENT";
        case CanMakePaymentQueryResult::CANNOT_MAKE_PAYMENT:
            return os << "CanMakePaymentQueryResult::CANNOT_MAKE_PAYMENT";
        case CanMakePaymentQueryResult::QUERY_QUOTA_EXCEEDED:
            return os << "CanMakePaymentQueryResult::QUERY_QUOTA_EXCEEDED";
        default:
            return os << "Unknown CanMakePaymentQueryResult value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(CanMakePaymentQueryResult value)
    {
        return internal::CanMakePaymentQueryResult_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class AndroidPayEnvironment : int32_t {
        PRODUCTION,
        TEST,
    };

    inline std::ostream& operator<<(std::ostream& os, AndroidPayEnvironment value)
    {
        switch (value) {
        case AndroidPayEnvironment::PRODUCTION:
            return os << "AndroidPayEnvironment::PRODUCTION";
        case AndroidPayEnvironment::TEST:
            return os << "AndroidPayEnvironment::TEST";
        default:
            return os << "Unknown AndroidPayEnvironment value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(AndroidPayEnvironment value)
    {
        return internal::AndroidPayEnvironment_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class AndroidPayCardNetwork : int32_t {
        AMEX,
        DISCOVER,
        MASTERCARD,
        VISA,
    };

    inline std::ostream& operator<<(std::ostream& os, AndroidPayCardNetwork value)
    {
        switch (value) {
        case AndroidPayCardNetwork::AMEX:
            return os << "AndroidPayCardNetwork::AMEX";
        case AndroidPayCardNetwork::DISCOVER:
            return os << "AndroidPayCardNetwork::DISCOVER";
        case AndroidPayCardNetwork::MASTERCARD:
            return os << "AndroidPayCardNetwork::MASTERCARD";
        case AndroidPayCardNetwork::VISA:
            return os << "AndroidPayCardNetwork::VISA";
        default:
            return os << "Unknown AndroidPayCardNetwork value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(AndroidPayCardNetwork value)
    {
        return internal::AndroidPayCardNetwork_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class AndroidPayTokenization : int32_t {
        UNSPECIFIED,
        GATEWAY_TOKEN,
        NETWORK_TOKEN,
    };

    inline std::ostream& operator<<(std::ostream& os, AndroidPayTokenization value)
    {
        switch (value) {
        case AndroidPayTokenization::UNSPECIFIED:
            return os << "AndroidPayTokenization::UNSPECIFIED";
        case AndroidPayTokenization::GATEWAY_TOKEN:
            return os << "AndroidPayTokenization::GATEWAY_TOKEN";
        case AndroidPayTokenization::NETWORK_TOKEN:
            return os << "AndroidPayTokenization::NETWORK_TOKEN";
        default:
            return os << "Unknown AndroidPayTokenization value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(AndroidPayTokenization value)
    {
        return internal::AndroidPayTokenization_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class BasicCardNetwork : int32_t {
        AMEX,
        DINERS,
        DISCOVER,
        JCB,
        MASTERCARD,
        MIR,
        UNIONPAY,
        VISA,
    };

    inline std::ostream& operator<<(std::ostream& os, BasicCardNetwork value)
    {
        switch (value) {
        case BasicCardNetwork::AMEX:
            return os << "BasicCardNetwork::AMEX";
        case BasicCardNetwork::DINERS:
            return os << "BasicCardNetwork::DINERS";
        case BasicCardNetwork::DISCOVER:
            return os << "BasicCardNetwork::DISCOVER";
        case BasicCardNetwork::JCB:
            return os << "BasicCardNetwork::JCB";
        case BasicCardNetwork::MASTERCARD:
            return os << "BasicCardNetwork::MASTERCARD";
        case BasicCardNetwork::MIR:
            return os << "BasicCardNetwork::MIR";
        case BasicCardNetwork::UNIONPAY:
            return os << "BasicCardNetwork::UNIONPAY";
        case BasicCardNetwork::VISA:
            return os << "BasicCardNetwork::VISA";
        default:
            return os << "Unknown BasicCardNetwork value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(BasicCardNetwork value)
    {
        return internal::BasicCardNetwork_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class BasicCardType : int32_t {
        CREDIT,
        DEBIT,
        PREPAID,
    };

    inline std::ostream& operator<<(std::ostream& os, BasicCardType value)
    {
        switch (value) {
        case BasicCardType::CREDIT:
            return os << "BasicCardType::CREDIT";
        case BasicCardType::DEBIT:
            return os << "BasicCardType::DEBIT";
        case BasicCardType::PREPAID:
            return os << "BasicCardType::PREPAID";
        default:
            return os << "Unknown BasicCardType value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(BasicCardType value)
    {
        return internal::BasicCardType_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class PaymentShippingType : int32_t {
        SHIPPING,
        DELIVERY,
        PICKUP,
    };

    inline std::ostream& operator<<(std::ostream& os, PaymentShippingType value)
    {
        switch (value) {
        case PaymentShippingType::SHIPPING:
            return os << "PaymentShippingType::SHIPPING";
        case PaymentShippingType::DELIVERY:
            return os << "PaymentShippingType::DELIVERY";
        case PaymentShippingType::PICKUP:
            return os << "PaymentShippingType::PICKUP";
        default:
            return os << "Unknown PaymentShippingType value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(PaymentShippingType value)
    {
        return internal::PaymentShippingType_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class PaymentComplete : int32_t {
        SUCCESS,
        FAIL,
        UNKNOWN,
    };

    inline std::ostream& operator<<(std::ostream& os, PaymentComplete value)
    {
        switch (value) {
        case PaymentComplete::SUCCESS:
            return os << "PaymentComplete::SUCCESS";
        case PaymentComplete::FAIL:
            return os << "PaymentComplete::FAIL";
        case PaymentComplete::UNKNOWN:
            return os << "PaymentComplete::UNKNOWN";
        default:
            return os << "Unknown PaymentComplete value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(PaymentComplete value)
    {
        return internal::PaymentComplete_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    // Interface base classes. They are used for type safety check.
    class PaymentRequestClientInterfaceBase {
    };

    using PaymentRequestClientPtrDataView = mojo::InterfacePtrDataView<PaymentRequestClientInterfaceBase>;
    using PaymentRequestClientRequestDataView = mojo::InterfaceRequestDataView<PaymentRequestClientInterfaceBase>;
    using PaymentRequestClientAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<PaymentRequestClientInterfaceBase>;
    using PaymentRequestClientAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<PaymentRequestClientInterfaceBase>;
    class PaymentRequestInterfaceBase {
    };

    using PaymentRequestPtrDataView = mojo::InterfacePtrDataView<PaymentRequestInterfaceBase>;
    using PaymentRequestRequestDataView = mojo::InterfaceRequestDataView<PaymentRequestInterfaceBase>;
    using PaymentRequestAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<PaymentRequestInterfaceBase>;
    using PaymentRequestAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<PaymentRequestInterfaceBase>;
    class PaymentAddressDataView {
    public:
        PaymentAddressDataView() { }

        PaymentAddressDataView(
            internal::PaymentAddress_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetCountryDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadCountry(UserType* output)
        {
            auto* pointer = data_->country.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetAddressLineDataView(
            mojo::ArrayDataView<mojo::StringDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadAddressLine(UserType* output)
        {
            auto* pointer = data_->address_line.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<mojo::StringDataView>>(
                pointer, output, context_);
        }
        inline void GetRegionDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadRegion(UserType* output)
        {
            auto* pointer = data_->region.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetCityDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadCity(UserType* output)
        {
            auto* pointer = data_->city.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetDependentLocalityDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDependentLocality(UserType* output)
        {
            auto* pointer = data_->dependent_locality.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetPostalCodeDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPostalCode(UserType* output)
        {
            auto* pointer = data_->postal_code.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetSortingCodeDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSortingCode(UserType* output)
        {
            auto* pointer = data_->sorting_code.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetLanguageCodeDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadLanguageCode(UserType* output)
        {
            auto* pointer = data_->language_code.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetScriptCodeDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadScriptCode(UserType* output)
        {
            auto* pointer = data_->script_code.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetOrganizationDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOrganization(UserType* output)
        {
            auto* pointer = data_->organization.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetRecipientDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadRecipient(UserType* output)
        {
            auto* pointer = data_->recipient.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetPhoneDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPhone(UserType* output)
        {
            auto* pointer = data_->phone.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::PaymentAddress_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PaymentCurrencyAmountDataView {
    public:
        PaymentCurrencyAmountDataView() { }

        PaymentCurrencyAmountDataView(
            internal::PaymentCurrencyAmount_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetCurrencyDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadCurrency(UserType* output)
        {
            auto* pointer = data_->currency.Get();
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
        inline void GetCurrencySystemDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadCurrencySystem(UserType* output)
        {
            auto* pointer = data_->currency_system.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::PaymentCurrencyAmount_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PaymentResponseDataView {
    public:
        PaymentResponseDataView() { }

        PaymentResponseDataView(
            internal::PaymentResponse_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetMethodNameDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMethodName(UserType* output)
        {
            auto* pointer = data_->method_name.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetStringifiedDetailsDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStringifiedDetails(UserType* output)
        {
            auto* pointer = data_->stringified_details.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetShippingAddressDataView(
            PaymentAddressDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadShippingAddress(UserType* output)
        {
            auto* pointer = data_->shipping_address.Get();
            return mojo::internal::Deserialize<::payments::mojom::PaymentAddressDataView>(
                pointer, output, context_);
        }
        inline void GetShippingOptionDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadShippingOption(UserType* output)
        {
            auto* pointer = data_->shipping_option.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetPayerNameDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPayerName(UserType* output)
        {
            auto* pointer = data_->payer_name.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetPayerEmailDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPayerEmail(UserType* output)
        {
            auto* pointer = data_->payer_email.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetPayerPhoneDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPayerPhone(UserType* output)
        {
            auto* pointer = data_->payer_phone.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::PaymentResponse_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PaymentItemDataView {
    public:
        PaymentItemDataView() { }

        PaymentItemDataView(
            internal::PaymentItem_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetLabelDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadLabel(UserType* output)
        {
            auto* pointer = data_->label.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetAmountDataView(
            PaymentCurrencyAmountDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadAmount(UserType* output)
        {
            auto* pointer = data_->amount.Get();
            return mojo::internal::Deserialize<::payments::mojom::PaymentCurrencyAmountDataView>(
                pointer, output, context_);
        }
        bool pending() const
        {
            return data_->pending;
        }

    private:
        internal::PaymentItem_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PaymentShippingOptionDataView {
    public:
        PaymentShippingOptionDataView() { }

        PaymentShippingOptionDataView(
            internal::PaymentShippingOption_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetIdDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadId(UserType* output)
        {
            auto* pointer = data_->id.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetLabelDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadLabel(UserType* output)
        {
            auto* pointer = data_->label.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetAmountDataView(
            PaymentCurrencyAmountDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadAmount(UserType* output)
        {
            auto* pointer = data_->amount.Get();
            return mojo::internal::Deserialize<::payments::mojom::PaymentCurrencyAmountDataView>(
                pointer, output, context_);
        }
        bool selected() const
        {
            return data_->selected;
        }

    private:
        internal::PaymentShippingOption_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class AndroidPayTokenizationParameterDataView {
    public:
        AndroidPayTokenizationParameterDataView() { }

        AndroidPayTokenizationParameterDataView(
            internal::AndroidPayTokenizationParameter_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetKeyDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadKey(UserType* output)
        {
            auto* pointer = data_->key.Get();
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
        internal::AndroidPayTokenizationParameter_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PaymentMethodDataDataView {
    public:
        PaymentMethodDataDataView() { }

        PaymentMethodDataDataView(
            internal::PaymentMethodData_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetSupportedMethodsDataView(
            mojo::ArrayDataView<mojo::StringDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSupportedMethods(UserType* output)
        {
            auto* pointer = data_->supported_methods.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<mojo::StringDataView>>(
                pointer, output, context_);
        }
        inline void GetStringifiedDataDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStringifiedData(UserType* output)
        {
            auto* pointer = data_->stringified_data.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadEnvironment(UserType* output) const
        {
            auto data_value = data_->environment;
            return mojo::internal::Deserialize<::payments::mojom::AndroidPayEnvironment>(
                data_value, output);
        }

        AndroidPayEnvironment environment() const
        {
            return static_cast<AndroidPayEnvironment>(data_->environment);
        }
        inline void GetMerchantNameDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMerchantName(UserType* output)
        {
            auto* pointer = data_->merchant_name.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetMerchantIdDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMerchantId(UserType* output)
        {
            auto* pointer = data_->merchant_id.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetAllowedCardNetworksDataView(
            mojo::ArrayDataView<AndroidPayCardNetwork>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadAllowedCardNetworks(UserType* output)
        {
            auto* pointer = data_->allowed_card_networks.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::payments::mojom::AndroidPayCardNetwork>>(
                pointer, output, context_);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTokenizationType(UserType* output) const
        {
            auto data_value = data_->tokenization_type;
            return mojo::internal::Deserialize<::payments::mojom::AndroidPayTokenization>(
                data_value, output);
        }

        AndroidPayTokenization tokenization_type() const
        {
            return static_cast<AndroidPayTokenization>(data_->tokenization_type);
        }
        inline void GetParametersDataView(
            mojo::ArrayDataView<AndroidPayTokenizationParameterDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadParameters(UserType* output)
        {
            auto* pointer = data_->parameters.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::payments::mojom::AndroidPayTokenizationParameterDataView>>(
                pointer, output, context_);
        }
        int32_t min_google_play_services_version() const
        {
            return data_->min_google_play_services_version;
        }
        inline void GetSupportedNetworksDataView(
            mojo::ArrayDataView<BasicCardNetwork>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSupportedNetworks(UserType* output)
        {
            auto* pointer = data_->supported_networks.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::payments::mojom::BasicCardNetwork>>(
                pointer, output, context_);
        }
        inline void GetSupportedTypesDataView(
            mojo::ArrayDataView<BasicCardType>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSupportedTypes(UserType* output)
        {
            auto* pointer = data_->supported_types.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::payments::mojom::BasicCardType>>(
                pointer, output, context_);
        }

    private:
        internal::PaymentMethodData_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PaymentDetailsModifierDataView {
    public:
        PaymentDetailsModifierDataView() { }

        PaymentDetailsModifierDataView(
            internal::PaymentDetailsModifier_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetTotalDataView(
            PaymentItemDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTotal(UserType* output)
        {
            auto* pointer = data_->total.Get();
            return mojo::internal::Deserialize<::payments::mojom::PaymentItemDataView>(
                pointer, output, context_);
        }
        inline void GetAdditionalDisplayItemsDataView(
            mojo::ArrayDataView<PaymentItemDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadAdditionalDisplayItems(UserType* output)
        {
            auto* pointer = data_->additional_display_items.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::payments::mojom::PaymentItemDataView>>(
                pointer, output, context_);
        }
        inline void GetMethodDataDataView(
            PaymentMethodDataDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMethodData(UserType* output)
        {
            auto* pointer = data_->method_data.Get();
            return mojo::internal::Deserialize<::payments::mojom::PaymentMethodDataDataView>(
                pointer, output, context_);
        }

    private:
        internal::PaymentDetailsModifier_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PaymentDetailsDataView {
    public:
        PaymentDetailsDataView() { }

        PaymentDetailsDataView(
            internal::PaymentDetails_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetTotalDataView(
            PaymentItemDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTotal(UserType* output)
        {
            auto* pointer = data_->total.Get();
            return mojo::internal::Deserialize<::payments::mojom::PaymentItemDataView>(
                pointer, output, context_);
        }
        inline void GetDisplayItemsDataView(
            mojo::ArrayDataView<PaymentItemDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDisplayItems(UserType* output)
        {
            auto* pointer = data_->display_items.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::payments::mojom::PaymentItemDataView>>(
                pointer, output, context_);
        }
        inline void GetShippingOptionsDataView(
            mojo::ArrayDataView<PaymentShippingOptionDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadShippingOptions(UserType* output)
        {
            auto* pointer = data_->shipping_options.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::payments::mojom::PaymentShippingOptionDataView>>(
                pointer, output, context_);
        }
        inline void GetModifiersDataView(
            mojo::ArrayDataView<PaymentDetailsModifierDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadModifiers(UserType* output)
        {
            auto* pointer = data_->modifiers.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::payments::mojom::PaymentDetailsModifierDataView>>(
                pointer, output, context_);
        }
        inline void GetErrorDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadError(UserType* output)
        {
            auto* pointer = data_->error.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::PaymentDetails_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PaymentOptionsDataView {
    public:
        PaymentOptionsDataView() { }

        PaymentOptionsDataView(
            internal::PaymentOptions_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool request_payer_name() const
        {
            return data_->request_payer_name;
        }
        bool request_payer_email() const
        {
            return data_->request_payer_email;
        }
        bool request_payer_phone() const
        {
            return data_->request_payer_phone;
        }
        bool request_shipping() const
        {
            return data_->request_shipping;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadShippingType(UserType* output) const
        {
            auto data_value = data_->shipping_type;
            return mojo::internal::Deserialize<::payments::mojom::PaymentShippingType>(
                data_value, output);
        }

        PaymentShippingType shipping_type() const
        {
            return static_cast<PaymentShippingType>(data_->shipping_type);
        }

    private:
        internal::PaymentOptions_Data* data_ = nullptr;
    };

    class PaymentRequestClient_OnShippingAddressChange_ParamsDataView {
    public:
        PaymentRequestClient_OnShippingAddressChange_ParamsDataView() { }

        PaymentRequestClient_OnShippingAddressChange_ParamsDataView(
            internal::PaymentRequestClient_OnShippingAddressChange_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetAddressDataView(
            PaymentAddressDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadAddress(UserType* output)
        {
            auto* pointer = data_->address.Get();
            return mojo::internal::Deserialize<::payments::mojom::PaymentAddressDataView>(
                pointer, output, context_);
        }

    private:
        internal::PaymentRequestClient_OnShippingAddressChange_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PaymentRequestClient_OnShippingOptionChange_ParamsDataView {
    public:
        PaymentRequestClient_OnShippingOptionChange_ParamsDataView() { }

        PaymentRequestClient_OnShippingOptionChange_ParamsDataView(
            internal::PaymentRequestClient_OnShippingOptionChange_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetShippingOptionIdDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadShippingOptionId(UserType* output)
        {
            auto* pointer = data_->shipping_option_id.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::PaymentRequestClient_OnShippingOptionChange_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PaymentRequestClient_OnPaymentResponse_ParamsDataView {
    public:
        PaymentRequestClient_OnPaymentResponse_ParamsDataView() { }

        PaymentRequestClient_OnPaymentResponse_ParamsDataView(
            internal::PaymentRequestClient_OnPaymentResponse_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetResponseDataView(
            PaymentResponseDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadResponse(UserType* output)
        {
            auto* pointer = data_->response.Get();
            return mojo::internal::Deserialize<::payments::mojom::PaymentResponseDataView>(
                pointer, output, context_);
        }

    private:
        internal::PaymentRequestClient_OnPaymentResponse_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PaymentRequestClient_OnError_ParamsDataView {
    public:
        PaymentRequestClient_OnError_ParamsDataView() { }

        PaymentRequestClient_OnError_ParamsDataView(
            internal::PaymentRequestClient_OnError_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadError(UserType* output) const
        {
            auto data_value = data_->error;
            return mojo::internal::Deserialize<::payments::mojom::PaymentErrorReason>(
                data_value, output);
        }

        PaymentErrorReason error() const
        {
            return static_cast<PaymentErrorReason>(data_->error);
        }

    private:
        internal::PaymentRequestClient_OnError_Params_Data* data_ = nullptr;
    };

    class PaymentRequestClient_OnComplete_ParamsDataView {
    public:
        PaymentRequestClient_OnComplete_ParamsDataView() { }

        PaymentRequestClient_OnComplete_ParamsDataView(
            internal::PaymentRequestClient_OnComplete_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::PaymentRequestClient_OnComplete_Params_Data* data_ = nullptr;
    };

    class PaymentRequestClient_OnAbort_ParamsDataView {
    public:
        PaymentRequestClient_OnAbort_ParamsDataView() { }

        PaymentRequestClient_OnAbort_ParamsDataView(
            internal::PaymentRequestClient_OnAbort_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool aborted_successfully() const
        {
            return data_->aborted_successfully;
        }

    private:
        internal::PaymentRequestClient_OnAbort_Params_Data* data_ = nullptr;
    };

    class PaymentRequestClient_OnCanMakePayment_ParamsDataView {
    public:
        PaymentRequestClient_OnCanMakePayment_ParamsDataView() { }

        PaymentRequestClient_OnCanMakePayment_ParamsDataView(
            internal::PaymentRequestClient_OnCanMakePayment_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadResult(UserType* output) const
        {
            auto data_value = data_->result;
            return mojo::internal::Deserialize<::payments::mojom::CanMakePaymentQueryResult>(
                data_value, output);
        }

        CanMakePaymentQueryResult result() const
        {
            return static_cast<CanMakePaymentQueryResult>(data_->result);
        }

    private:
        internal::PaymentRequestClient_OnCanMakePayment_Params_Data* data_ = nullptr;
    };

    class PaymentRequest_Init_ParamsDataView {
    public:
        PaymentRequest_Init_ParamsDataView() { }

        PaymentRequest_Init_ParamsDataView(
            internal::PaymentRequest_Init_Params_Data* data,
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
            bool ret = mojo::internal::Deserialize<::payments::mojom::PaymentRequestClientPtrDataView>(
                &data_->client, &result, context_);
            DCHECK(ret);
            return result;
        }
        inline void GetMethodDataDataView(
            mojo::ArrayDataView<PaymentMethodDataDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMethodData(UserType* output)
        {
            auto* pointer = data_->method_data.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::payments::mojom::PaymentMethodDataDataView>>(
                pointer, output, context_);
        }
        inline void GetDetailsDataView(
            PaymentDetailsDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDetails(UserType* output)
        {
            auto* pointer = data_->details.Get();
            return mojo::internal::Deserialize<::payments::mojom::PaymentDetailsDataView>(
                pointer, output, context_);
        }
        inline void GetOptionsDataView(
            PaymentOptionsDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOptions(UserType* output)
        {
            auto* pointer = data_->options.Get();
            return mojo::internal::Deserialize<::payments::mojom::PaymentOptionsDataView>(
                pointer, output, context_);
        }

    private:
        internal::PaymentRequest_Init_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PaymentRequest_Show_ParamsDataView {
    public:
        PaymentRequest_Show_ParamsDataView() { }

        PaymentRequest_Show_ParamsDataView(
            internal::PaymentRequest_Show_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::PaymentRequest_Show_Params_Data* data_ = nullptr;
    };

    class PaymentRequest_UpdateWith_ParamsDataView {
    public:
        PaymentRequest_UpdateWith_ParamsDataView() { }

        PaymentRequest_UpdateWith_ParamsDataView(
            internal::PaymentRequest_UpdateWith_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetDetailsDataView(
            PaymentDetailsDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDetails(UserType* output)
        {
            auto* pointer = data_->details.Get();
            return mojo::internal::Deserialize<::payments::mojom::PaymentDetailsDataView>(
                pointer, output, context_);
        }

    private:
        internal::PaymentRequest_UpdateWith_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PaymentRequest_Abort_ParamsDataView {
    public:
        PaymentRequest_Abort_ParamsDataView() { }

        PaymentRequest_Abort_ParamsDataView(
            internal::PaymentRequest_Abort_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::PaymentRequest_Abort_Params_Data* data_ = nullptr;
    };

    class PaymentRequest_Complete_ParamsDataView {
    public:
        PaymentRequest_Complete_ParamsDataView() { }

        PaymentRequest_Complete_ParamsDataView(
            internal::PaymentRequest_Complete_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadResult(UserType* output) const
        {
            auto data_value = data_->result;
            return mojo::internal::Deserialize<::payments::mojom::PaymentComplete>(
                data_value, output);
        }

        PaymentComplete result() const
        {
            return static_cast<PaymentComplete>(data_->result);
        }

    private:
        internal::PaymentRequest_Complete_Params_Data* data_ = nullptr;
    };

    class PaymentRequest_CanMakePayment_ParamsDataView {
    public:
        PaymentRequest_CanMakePayment_ParamsDataView() { }

        PaymentRequest_CanMakePayment_ParamsDataView(
            internal::PaymentRequest_CanMakePayment_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::PaymentRequest_CanMakePayment_Params_Data* data_ = nullptr;
    };

} // namespace mojom
} // namespace payments

namespace std {

template <>
struct hash<::payments::mojom::PaymentErrorReason>
    : public mojo::internal::EnumHashImpl<::payments::mojom::PaymentErrorReason> {
};

template <>
struct hash<::payments::mojom::CanMakePaymentQueryResult>
    : public mojo::internal::EnumHashImpl<::payments::mojom::CanMakePaymentQueryResult> {
};

template <>
struct hash<::payments::mojom::AndroidPayEnvironment>
    : public mojo::internal::EnumHashImpl<::payments::mojom::AndroidPayEnvironment> {
};

template <>
struct hash<::payments::mojom::AndroidPayCardNetwork>
    : public mojo::internal::EnumHashImpl<::payments::mojom::AndroidPayCardNetwork> {
};

template <>
struct hash<::payments::mojom::AndroidPayTokenization>
    : public mojo::internal::EnumHashImpl<::payments::mojom::AndroidPayTokenization> {
};

template <>
struct hash<::payments::mojom::BasicCardNetwork>
    : public mojo::internal::EnumHashImpl<::payments::mojom::BasicCardNetwork> {
};

template <>
struct hash<::payments::mojom::BasicCardType>
    : public mojo::internal::EnumHashImpl<::payments::mojom::BasicCardType> {
};

template <>
struct hash<::payments::mojom::PaymentShippingType>
    : public mojo::internal::EnumHashImpl<::payments::mojom::PaymentShippingType> {
};

template <>
struct hash<::payments::mojom::PaymentComplete>
    : public mojo::internal::EnumHashImpl<::payments::mojom::PaymentComplete> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::payments::mojom::PaymentErrorReason, ::payments::mojom::PaymentErrorReason> {
    static ::payments::mojom::PaymentErrorReason ToMojom(::payments::mojom::PaymentErrorReason input) { return input; }
    static bool FromMojom(::payments::mojom::PaymentErrorReason input, ::payments::mojom::PaymentErrorReason* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::payments::mojom::PaymentErrorReason, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::payments::mojom::PaymentErrorReason, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::payments::mojom::PaymentErrorReason>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::payments::mojom::CanMakePaymentQueryResult, ::payments::mojom::CanMakePaymentQueryResult> {
    static ::payments::mojom::CanMakePaymentQueryResult ToMojom(::payments::mojom::CanMakePaymentQueryResult input) { return input; }
    static bool FromMojom(::payments::mojom::CanMakePaymentQueryResult input, ::payments::mojom::CanMakePaymentQueryResult* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::payments::mojom::CanMakePaymentQueryResult, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::payments::mojom::CanMakePaymentQueryResult, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::payments::mojom::CanMakePaymentQueryResult>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::payments::mojom::AndroidPayEnvironment, ::payments::mojom::AndroidPayEnvironment> {
    static ::payments::mojom::AndroidPayEnvironment ToMojom(::payments::mojom::AndroidPayEnvironment input) { return input; }
    static bool FromMojom(::payments::mojom::AndroidPayEnvironment input, ::payments::mojom::AndroidPayEnvironment* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::payments::mojom::AndroidPayEnvironment, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::payments::mojom::AndroidPayEnvironment, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::payments::mojom::AndroidPayEnvironment>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::payments::mojom::AndroidPayCardNetwork, ::payments::mojom::AndroidPayCardNetwork> {
    static ::payments::mojom::AndroidPayCardNetwork ToMojom(::payments::mojom::AndroidPayCardNetwork input) { return input; }
    static bool FromMojom(::payments::mojom::AndroidPayCardNetwork input, ::payments::mojom::AndroidPayCardNetwork* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::payments::mojom::AndroidPayCardNetwork, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::payments::mojom::AndroidPayCardNetwork, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::payments::mojom::AndroidPayCardNetwork>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::payments::mojom::AndroidPayTokenization, ::payments::mojom::AndroidPayTokenization> {
    static ::payments::mojom::AndroidPayTokenization ToMojom(::payments::mojom::AndroidPayTokenization input) { return input; }
    static bool FromMojom(::payments::mojom::AndroidPayTokenization input, ::payments::mojom::AndroidPayTokenization* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::payments::mojom::AndroidPayTokenization, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::payments::mojom::AndroidPayTokenization, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::payments::mojom::AndroidPayTokenization>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::payments::mojom::BasicCardNetwork, ::payments::mojom::BasicCardNetwork> {
    static ::payments::mojom::BasicCardNetwork ToMojom(::payments::mojom::BasicCardNetwork input) { return input; }
    static bool FromMojom(::payments::mojom::BasicCardNetwork input, ::payments::mojom::BasicCardNetwork* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::payments::mojom::BasicCardNetwork, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::payments::mojom::BasicCardNetwork, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::payments::mojom::BasicCardNetwork>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::payments::mojom::BasicCardType, ::payments::mojom::BasicCardType> {
    static ::payments::mojom::BasicCardType ToMojom(::payments::mojom::BasicCardType input) { return input; }
    static bool FromMojom(::payments::mojom::BasicCardType input, ::payments::mojom::BasicCardType* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::payments::mojom::BasicCardType, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::payments::mojom::BasicCardType, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::payments::mojom::BasicCardType>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::payments::mojom::PaymentShippingType, ::payments::mojom::PaymentShippingType> {
    static ::payments::mojom::PaymentShippingType ToMojom(::payments::mojom::PaymentShippingType input) { return input; }
    static bool FromMojom(::payments::mojom::PaymentShippingType input, ::payments::mojom::PaymentShippingType* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::payments::mojom::PaymentShippingType, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::payments::mojom::PaymentShippingType, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::payments::mojom::PaymentShippingType>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::payments::mojom::PaymentComplete, ::payments::mojom::PaymentComplete> {
    static ::payments::mojom::PaymentComplete ToMojom(::payments::mojom::PaymentComplete input) { return input; }
    static bool FromMojom(::payments::mojom::PaymentComplete input, ::payments::mojom::PaymentComplete* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::payments::mojom::PaymentComplete, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::payments::mojom::PaymentComplete, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::payments::mojom::PaymentComplete>(input), output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::payments::mojom::PaymentAddressDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::payments::mojom::PaymentAddressDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::payments::mojom::internal::PaymentAddress_Data);
            decltype(CallWithContext(Traits::country, input, custom_context)) in_country = CallWithContext(Traits::country, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_country, context);
            decltype(CallWithContext(Traits::address_line, input, custom_context)) in_address_line = CallWithContext(Traits::address_line, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<mojo::StringDataView>>(
                in_address_line, context);
            decltype(CallWithContext(Traits::region, input, custom_context)) in_region = CallWithContext(Traits::region, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_region, context);
            decltype(CallWithContext(Traits::city, input, custom_context)) in_city = CallWithContext(Traits::city, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_city, context);
            decltype(CallWithContext(Traits::dependent_locality, input, custom_context)) in_dependent_locality = CallWithContext(Traits::dependent_locality, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_dependent_locality, context);
            decltype(CallWithContext(Traits::postal_code, input, custom_context)) in_postal_code = CallWithContext(Traits::postal_code, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_postal_code, context);
            decltype(CallWithContext(Traits::sorting_code, input, custom_context)) in_sorting_code = CallWithContext(Traits::sorting_code, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_sorting_code, context);
            decltype(CallWithContext(Traits::language_code, input, custom_context)) in_language_code = CallWithContext(Traits::language_code, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_language_code, context);
            decltype(CallWithContext(Traits::script_code, input, custom_context)) in_script_code = CallWithContext(Traits::script_code, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_script_code, context);
            decltype(CallWithContext(Traits::organization, input, custom_context)) in_organization = CallWithContext(Traits::organization, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_organization, context);
            decltype(CallWithContext(Traits::recipient, input, custom_context)) in_recipient = CallWithContext(Traits::recipient, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_recipient, context);
            decltype(CallWithContext(Traits::phone, input, custom_context)) in_phone = CallWithContext(Traits::phone, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_phone, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::payments::mojom::internal::PaymentAddress_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::payments::mojom::internal::PaymentAddress_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::country, input, custom_context)) in_country = CallWithContext(Traits::country, input, custom_context);
            typename decltype(result->country)::BaseType* country_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_country, buffer, &country_ptr, context);
            result->country.Set(country_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->country.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null country in PaymentAddress struct");
            decltype(CallWithContext(Traits::address_line, input, custom_context)) in_address_line = CallWithContext(Traits::address_line, input, custom_context);
            typename decltype(result->address_line)::BaseType* address_line_ptr;
            const mojo::internal::ContainerValidateParams address_line_validate_params(
                0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr));
            mojo::internal::Serialize<mojo::ArrayDataView<mojo::StringDataView>>(
                in_address_line, buffer, &address_line_ptr, &address_line_validate_params,
                context);
            result->address_line.Set(address_line_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->address_line.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null address_line in PaymentAddress struct");
            decltype(CallWithContext(Traits::region, input, custom_context)) in_region = CallWithContext(Traits::region, input, custom_context);
            typename decltype(result->region)::BaseType* region_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_region, buffer, &region_ptr, context);
            result->region.Set(region_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->region.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null region in PaymentAddress struct");
            decltype(CallWithContext(Traits::city, input, custom_context)) in_city = CallWithContext(Traits::city, input, custom_context);
            typename decltype(result->city)::BaseType* city_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_city, buffer, &city_ptr, context);
            result->city.Set(city_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->city.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null city in PaymentAddress struct");
            decltype(CallWithContext(Traits::dependent_locality, input, custom_context)) in_dependent_locality = CallWithContext(Traits::dependent_locality, input, custom_context);
            typename decltype(result->dependent_locality)::BaseType* dependent_locality_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_dependent_locality, buffer, &dependent_locality_ptr, context);
            result->dependent_locality.Set(dependent_locality_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->dependent_locality.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null dependent_locality in PaymentAddress struct");
            decltype(CallWithContext(Traits::postal_code, input, custom_context)) in_postal_code = CallWithContext(Traits::postal_code, input, custom_context);
            typename decltype(result->postal_code)::BaseType* postal_code_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_postal_code, buffer, &postal_code_ptr, context);
            result->postal_code.Set(postal_code_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->postal_code.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null postal_code in PaymentAddress struct");
            decltype(CallWithContext(Traits::sorting_code, input, custom_context)) in_sorting_code = CallWithContext(Traits::sorting_code, input, custom_context);
            typename decltype(result->sorting_code)::BaseType* sorting_code_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_sorting_code, buffer, &sorting_code_ptr, context);
            result->sorting_code.Set(sorting_code_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->sorting_code.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null sorting_code in PaymentAddress struct");
            decltype(CallWithContext(Traits::language_code, input, custom_context)) in_language_code = CallWithContext(Traits::language_code, input, custom_context);
            typename decltype(result->language_code)::BaseType* language_code_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_language_code, buffer, &language_code_ptr, context);
            result->language_code.Set(language_code_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->language_code.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null language_code in PaymentAddress struct");
            decltype(CallWithContext(Traits::script_code, input, custom_context)) in_script_code = CallWithContext(Traits::script_code, input, custom_context);
            typename decltype(result->script_code)::BaseType* script_code_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_script_code, buffer, &script_code_ptr, context);
            result->script_code.Set(script_code_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->script_code.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null script_code in PaymentAddress struct");
            decltype(CallWithContext(Traits::organization, input, custom_context)) in_organization = CallWithContext(Traits::organization, input, custom_context);
            typename decltype(result->organization)::BaseType* organization_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_organization, buffer, &organization_ptr, context);
            result->organization.Set(organization_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->organization.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null organization in PaymentAddress struct");
            decltype(CallWithContext(Traits::recipient, input, custom_context)) in_recipient = CallWithContext(Traits::recipient, input, custom_context);
            typename decltype(result->recipient)::BaseType* recipient_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_recipient, buffer, &recipient_ptr, context);
            result->recipient.Set(recipient_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->recipient.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null recipient in PaymentAddress struct");
            decltype(CallWithContext(Traits::phone, input, custom_context)) in_phone = CallWithContext(Traits::phone, input, custom_context);
            typename decltype(result->phone)::BaseType* phone_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_phone, buffer, &phone_ptr, context);
            result->phone.Set(phone_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->phone.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null phone in PaymentAddress struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::payments::mojom::internal::PaymentAddress_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::payments::mojom::PaymentAddressDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::payments::mojom::PaymentCurrencyAmountDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::payments::mojom::PaymentCurrencyAmountDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::payments::mojom::internal::PaymentCurrencyAmount_Data);
            decltype(CallWithContext(Traits::currency, input, custom_context)) in_currency = CallWithContext(Traits::currency, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_currency, context);
            decltype(CallWithContext(Traits::value, input, custom_context)) in_value = CallWithContext(Traits::value, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_value, context);
            decltype(CallWithContext(Traits::currency_system, input, custom_context)) in_currency_system = CallWithContext(Traits::currency_system, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_currency_system, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::payments::mojom::internal::PaymentCurrencyAmount_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::payments::mojom::internal::PaymentCurrencyAmount_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::currency, input, custom_context)) in_currency = CallWithContext(Traits::currency, input, custom_context);
            typename decltype(result->currency)::BaseType* currency_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_currency, buffer, &currency_ptr, context);
            result->currency.Set(currency_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->currency.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null currency in PaymentCurrencyAmount struct");
            decltype(CallWithContext(Traits::value, input, custom_context)) in_value = CallWithContext(Traits::value, input, custom_context);
            typename decltype(result->value)::BaseType* value_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_value, buffer, &value_ptr, context);
            result->value.Set(value_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->value.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null value in PaymentCurrencyAmount struct");
            decltype(CallWithContext(Traits::currency_system, input, custom_context)) in_currency_system = CallWithContext(Traits::currency_system, input, custom_context);
            typename decltype(result->currency_system)::BaseType* currency_system_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_currency_system, buffer, &currency_system_ptr, context);
            result->currency_system.Set(currency_system_ptr);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::payments::mojom::internal::PaymentCurrencyAmount_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::payments::mojom::PaymentCurrencyAmountDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::payments::mojom::PaymentResponseDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::payments::mojom::PaymentResponseDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::payments::mojom::internal::PaymentResponse_Data);
            decltype(CallWithContext(Traits::method_name, input, custom_context)) in_method_name = CallWithContext(Traits::method_name, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_method_name, context);
            decltype(CallWithContext(Traits::stringified_details, input, custom_context)) in_stringified_details = CallWithContext(Traits::stringified_details, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_stringified_details, context);
            decltype(CallWithContext(Traits::shipping_address, input, custom_context)) in_shipping_address = CallWithContext(Traits::shipping_address, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::payments::mojom::PaymentAddressDataView>(
                in_shipping_address, context);
            decltype(CallWithContext(Traits::shipping_option, input, custom_context)) in_shipping_option = CallWithContext(Traits::shipping_option, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_shipping_option, context);
            decltype(CallWithContext(Traits::payer_name, input, custom_context)) in_payer_name = CallWithContext(Traits::payer_name, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_payer_name, context);
            decltype(CallWithContext(Traits::payer_email, input, custom_context)) in_payer_email = CallWithContext(Traits::payer_email, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_payer_email, context);
            decltype(CallWithContext(Traits::payer_phone, input, custom_context)) in_payer_phone = CallWithContext(Traits::payer_phone, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_payer_phone, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::payments::mojom::internal::PaymentResponse_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::payments::mojom::internal::PaymentResponse_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::method_name, input, custom_context)) in_method_name = CallWithContext(Traits::method_name, input, custom_context);
            typename decltype(result->method_name)::BaseType* method_name_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_method_name, buffer, &method_name_ptr, context);
            result->method_name.Set(method_name_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->method_name.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null method_name in PaymentResponse struct");
            decltype(CallWithContext(Traits::stringified_details, input, custom_context)) in_stringified_details = CallWithContext(Traits::stringified_details, input, custom_context);
            typename decltype(result->stringified_details)::BaseType* stringified_details_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_stringified_details, buffer, &stringified_details_ptr, context);
            result->stringified_details.Set(stringified_details_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->stringified_details.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null stringified_details in PaymentResponse struct");
            decltype(CallWithContext(Traits::shipping_address, input, custom_context)) in_shipping_address = CallWithContext(Traits::shipping_address, input, custom_context);
            typename decltype(result->shipping_address)::BaseType* shipping_address_ptr;
            mojo::internal::Serialize<::payments::mojom::PaymentAddressDataView>(
                in_shipping_address, buffer, &shipping_address_ptr, context);
            result->shipping_address.Set(shipping_address_ptr);
            decltype(CallWithContext(Traits::shipping_option, input, custom_context)) in_shipping_option = CallWithContext(Traits::shipping_option, input, custom_context);
            typename decltype(result->shipping_option)::BaseType* shipping_option_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_shipping_option, buffer, &shipping_option_ptr, context);
            result->shipping_option.Set(shipping_option_ptr);
            decltype(CallWithContext(Traits::payer_name, input, custom_context)) in_payer_name = CallWithContext(Traits::payer_name, input, custom_context);
            typename decltype(result->payer_name)::BaseType* payer_name_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_payer_name, buffer, &payer_name_ptr, context);
            result->payer_name.Set(payer_name_ptr);
            decltype(CallWithContext(Traits::payer_email, input, custom_context)) in_payer_email = CallWithContext(Traits::payer_email, input, custom_context);
            typename decltype(result->payer_email)::BaseType* payer_email_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_payer_email, buffer, &payer_email_ptr, context);
            result->payer_email.Set(payer_email_ptr);
            decltype(CallWithContext(Traits::payer_phone, input, custom_context)) in_payer_phone = CallWithContext(Traits::payer_phone, input, custom_context);
            typename decltype(result->payer_phone)::BaseType* payer_phone_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_payer_phone, buffer, &payer_phone_ptr, context);
            result->payer_phone.Set(payer_phone_ptr);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::payments::mojom::internal::PaymentResponse_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::payments::mojom::PaymentResponseDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::payments::mojom::PaymentItemDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::payments::mojom::PaymentItemDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::payments::mojom::internal::PaymentItem_Data);
            decltype(CallWithContext(Traits::label, input, custom_context)) in_label = CallWithContext(Traits::label, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_label, context);
            decltype(CallWithContext(Traits::amount, input, custom_context)) in_amount = CallWithContext(Traits::amount, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::payments::mojom::PaymentCurrencyAmountDataView>(
                in_amount, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::payments::mojom::internal::PaymentItem_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::payments::mojom::internal::PaymentItem_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::label, input, custom_context)) in_label = CallWithContext(Traits::label, input, custom_context);
            typename decltype(result->label)::BaseType* label_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_label, buffer, &label_ptr, context);
            result->label.Set(label_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->label.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null label in PaymentItem struct");
            decltype(CallWithContext(Traits::amount, input, custom_context)) in_amount = CallWithContext(Traits::amount, input, custom_context);
            typename decltype(result->amount)::BaseType* amount_ptr;
            mojo::internal::Serialize<::payments::mojom::PaymentCurrencyAmountDataView>(
                in_amount, buffer, &amount_ptr, context);
            result->amount.Set(amount_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->amount.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null amount in PaymentItem struct");
            result->pending = CallWithContext(Traits::pending, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::payments::mojom::internal::PaymentItem_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::payments::mojom::PaymentItemDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::payments::mojom::PaymentShippingOptionDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::payments::mojom::PaymentShippingOptionDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::payments::mojom::internal::PaymentShippingOption_Data);
            decltype(CallWithContext(Traits::id, input, custom_context)) in_id = CallWithContext(Traits::id, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_id, context);
            decltype(CallWithContext(Traits::label, input, custom_context)) in_label = CallWithContext(Traits::label, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_label, context);
            decltype(CallWithContext(Traits::amount, input, custom_context)) in_amount = CallWithContext(Traits::amount, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::payments::mojom::PaymentCurrencyAmountDataView>(
                in_amount, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::payments::mojom::internal::PaymentShippingOption_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::payments::mojom::internal::PaymentShippingOption_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::id, input, custom_context)) in_id = CallWithContext(Traits::id, input, custom_context);
            typename decltype(result->id)::BaseType* id_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_id, buffer, &id_ptr, context);
            result->id.Set(id_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->id.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null id in PaymentShippingOption struct");
            decltype(CallWithContext(Traits::label, input, custom_context)) in_label = CallWithContext(Traits::label, input, custom_context);
            typename decltype(result->label)::BaseType* label_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_label, buffer, &label_ptr, context);
            result->label.Set(label_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->label.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null label in PaymentShippingOption struct");
            decltype(CallWithContext(Traits::amount, input, custom_context)) in_amount = CallWithContext(Traits::amount, input, custom_context);
            typename decltype(result->amount)::BaseType* amount_ptr;
            mojo::internal::Serialize<::payments::mojom::PaymentCurrencyAmountDataView>(
                in_amount, buffer, &amount_ptr, context);
            result->amount.Set(amount_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->amount.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null amount in PaymentShippingOption struct");
            result->selected = CallWithContext(Traits::selected, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::payments::mojom::internal::PaymentShippingOption_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::payments::mojom::PaymentShippingOptionDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::payments::mojom::AndroidPayTokenizationParameterDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::payments::mojom::AndroidPayTokenizationParameterDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::payments::mojom::internal::AndroidPayTokenizationParameter_Data);
            decltype(CallWithContext(Traits::key, input, custom_context)) in_key = CallWithContext(Traits::key, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_key, context);
            decltype(CallWithContext(Traits::value, input, custom_context)) in_value = CallWithContext(Traits::value, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_value, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::payments::mojom::internal::AndroidPayTokenizationParameter_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::payments::mojom::internal::AndroidPayTokenizationParameter_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::key, input, custom_context)) in_key = CallWithContext(Traits::key, input, custom_context);
            typename decltype(result->key)::BaseType* key_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_key, buffer, &key_ptr, context);
            result->key.Set(key_ptr);
            decltype(CallWithContext(Traits::value, input, custom_context)) in_value = CallWithContext(Traits::value, input, custom_context);
            typename decltype(result->value)::BaseType* value_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_value, buffer, &value_ptr, context);
            result->value.Set(value_ptr);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::payments::mojom::internal::AndroidPayTokenizationParameter_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::payments::mojom::AndroidPayTokenizationParameterDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::payments::mojom::PaymentMethodDataDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::payments::mojom::PaymentMethodDataDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::payments::mojom::internal::PaymentMethodData_Data);
            decltype(CallWithContext(Traits::supported_methods, input, custom_context)) in_supported_methods = CallWithContext(Traits::supported_methods, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<mojo::StringDataView>>(
                in_supported_methods, context);
            decltype(CallWithContext(Traits::stringified_data, input, custom_context)) in_stringified_data = CallWithContext(Traits::stringified_data, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_stringified_data, context);
            decltype(CallWithContext(Traits::merchant_name, input, custom_context)) in_merchant_name = CallWithContext(Traits::merchant_name, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_merchant_name, context);
            decltype(CallWithContext(Traits::merchant_id, input, custom_context)) in_merchant_id = CallWithContext(Traits::merchant_id, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_merchant_id, context);
            decltype(CallWithContext(Traits::allowed_card_networks, input, custom_context)) in_allowed_card_networks = CallWithContext(Traits::allowed_card_networks, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::payments::mojom::AndroidPayCardNetwork>>(
                in_allowed_card_networks, context);
            decltype(CallWithContext(Traits::parameters, input, custom_context)) in_parameters = CallWithContext(Traits::parameters, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::payments::mojom::AndroidPayTokenizationParameterDataView>>(
                in_parameters, context);
            decltype(CallWithContext(Traits::supported_networks, input, custom_context)) in_supported_networks = CallWithContext(Traits::supported_networks, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::payments::mojom::BasicCardNetwork>>(
                in_supported_networks, context);
            decltype(CallWithContext(Traits::supported_types, input, custom_context)) in_supported_types = CallWithContext(Traits::supported_types, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::payments::mojom::BasicCardType>>(
                in_supported_types, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::payments::mojom::internal::PaymentMethodData_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::payments::mojom::internal::PaymentMethodData_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::supported_methods, input, custom_context)) in_supported_methods = CallWithContext(Traits::supported_methods, input, custom_context);
            typename decltype(result->supported_methods)::BaseType* supported_methods_ptr;
            const mojo::internal::ContainerValidateParams supported_methods_validate_params(
                0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr));
            mojo::internal::Serialize<mojo::ArrayDataView<mojo::StringDataView>>(
                in_supported_methods, buffer, &supported_methods_ptr, &supported_methods_validate_params,
                context);
            result->supported_methods.Set(supported_methods_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->supported_methods.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null supported_methods in PaymentMethodData struct");
            decltype(CallWithContext(Traits::stringified_data, input, custom_context)) in_stringified_data = CallWithContext(Traits::stringified_data, input, custom_context);
            typename decltype(result->stringified_data)::BaseType* stringified_data_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_stringified_data, buffer, &stringified_data_ptr, context);
            result->stringified_data.Set(stringified_data_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->stringified_data.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null stringified_data in PaymentMethodData struct");
            mojo::internal::Serialize<::payments::mojom::AndroidPayEnvironment>(
                CallWithContext(Traits::environment, input, custom_context), &result->environment);
            decltype(CallWithContext(Traits::merchant_name, input, custom_context)) in_merchant_name = CallWithContext(Traits::merchant_name, input, custom_context);
            typename decltype(result->merchant_name)::BaseType* merchant_name_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_merchant_name, buffer, &merchant_name_ptr, context);
            result->merchant_name.Set(merchant_name_ptr);
            decltype(CallWithContext(Traits::merchant_id, input, custom_context)) in_merchant_id = CallWithContext(Traits::merchant_id, input, custom_context);
            typename decltype(result->merchant_id)::BaseType* merchant_id_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_merchant_id, buffer, &merchant_id_ptr, context);
            result->merchant_id.Set(merchant_id_ptr);
            decltype(CallWithContext(Traits::allowed_card_networks, input, custom_context)) in_allowed_card_networks = CallWithContext(Traits::allowed_card_networks, input, custom_context);
            typename decltype(result->allowed_card_networks)::BaseType* allowed_card_networks_ptr;
            const mojo::internal::ContainerValidateParams allowed_card_networks_validate_params(
                0, ::payments::mojom::internal::AndroidPayCardNetwork_Data::Validate);
            mojo::internal::Serialize<mojo::ArrayDataView<::payments::mojom::AndroidPayCardNetwork>>(
                in_allowed_card_networks, buffer, &allowed_card_networks_ptr, &allowed_card_networks_validate_params,
                context);
            result->allowed_card_networks.Set(allowed_card_networks_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->allowed_card_networks.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null allowed_card_networks in PaymentMethodData struct");
            mojo::internal::Serialize<::payments::mojom::AndroidPayTokenization>(
                CallWithContext(Traits::tokenization_type, input, custom_context), &result->tokenization_type);
            decltype(CallWithContext(Traits::parameters, input, custom_context)) in_parameters = CallWithContext(Traits::parameters, input, custom_context);
            typename decltype(result->parameters)::BaseType* parameters_ptr;
            const mojo::internal::ContainerValidateParams parameters_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::payments::mojom::AndroidPayTokenizationParameterDataView>>(
                in_parameters, buffer, &parameters_ptr, &parameters_validate_params,
                context);
            result->parameters.Set(parameters_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->parameters.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null parameters in PaymentMethodData struct");
            result->min_google_play_services_version = CallWithContext(Traits::min_google_play_services_version, input, custom_context);
            decltype(CallWithContext(Traits::supported_networks, input, custom_context)) in_supported_networks = CallWithContext(Traits::supported_networks, input, custom_context);
            typename decltype(result->supported_networks)::BaseType* supported_networks_ptr;
            const mojo::internal::ContainerValidateParams supported_networks_validate_params(
                0, ::payments::mojom::internal::BasicCardNetwork_Data::Validate);
            mojo::internal::Serialize<mojo::ArrayDataView<::payments::mojom::BasicCardNetwork>>(
                in_supported_networks, buffer, &supported_networks_ptr, &supported_networks_validate_params,
                context);
            result->supported_networks.Set(supported_networks_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->supported_networks.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null supported_networks in PaymentMethodData struct");
            decltype(CallWithContext(Traits::supported_types, input, custom_context)) in_supported_types = CallWithContext(Traits::supported_types, input, custom_context);
            typename decltype(result->supported_types)::BaseType* supported_types_ptr;
            const mojo::internal::ContainerValidateParams supported_types_validate_params(
                0, ::payments::mojom::internal::BasicCardType_Data::Validate);
            mojo::internal::Serialize<mojo::ArrayDataView<::payments::mojom::BasicCardType>>(
                in_supported_types, buffer, &supported_types_ptr, &supported_types_validate_params,
                context);
            result->supported_types.Set(supported_types_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->supported_types.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null supported_types in PaymentMethodData struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::payments::mojom::internal::PaymentMethodData_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::payments::mojom::PaymentMethodDataDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::payments::mojom::PaymentDetailsModifierDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::payments::mojom::PaymentDetailsModifierDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::payments::mojom::internal::PaymentDetailsModifier_Data);
            decltype(CallWithContext(Traits::total, input, custom_context)) in_total = CallWithContext(Traits::total, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::payments::mojom::PaymentItemDataView>(
                in_total, context);
            decltype(CallWithContext(Traits::additional_display_items, input, custom_context)) in_additional_display_items = CallWithContext(Traits::additional_display_items, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::payments::mojom::PaymentItemDataView>>(
                in_additional_display_items, context);
            decltype(CallWithContext(Traits::method_data, input, custom_context)) in_method_data = CallWithContext(Traits::method_data, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::payments::mojom::PaymentMethodDataDataView>(
                in_method_data, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::payments::mojom::internal::PaymentDetailsModifier_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::payments::mojom::internal::PaymentDetailsModifier_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::total, input, custom_context)) in_total = CallWithContext(Traits::total, input, custom_context);
            typename decltype(result->total)::BaseType* total_ptr;
            mojo::internal::Serialize<::payments::mojom::PaymentItemDataView>(
                in_total, buffer, &total_ptr, context);
            result->total.Set(total_ptr);
            decltype(CallWithContext(Traits::additional_display_items, input, custom_context)) in_additional_display_items = CallWithContext(Traits::additional_display_items, input, custom_context);
            typename decltype(result->additional_display_items)::BaseType* additional_display_items_ptr;
            const mojo::internal::ContainerValidateParams additional_display_items_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::payments::mojom::PaymentItemDataView>>(
                in_additional_display_items, buffer, &additional_display_items_ptr, &additional_display_items_validate_params,
                context);
            result->additional_display_items.Set(additional_display_items_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->additional_display_items.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null additional_display_items in PaymentDetailsModifier struct");
            decltype(CallWithContext(Traits::method_data, input, custom_context)) in_method_data = CallWithContext(Traits::method_data, input, custom_context);
            typename decltype(result->method_data)::BaseType* method_data_ptr;
            mojo::internal::Serialize<::payments::mojom::PaymentMethodDataDataView>(
                in_method_data, buffer, &method_data_ptr, context);
            result->method_data.Set(method_data_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->method_data.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null method_data in PaymentDetailsModifier struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::payments::mojom::internal::PaymentDetailsModifier_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::payments::mojom::PaymentDetailsModifierDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::payments::mojom::PaymentDetailsDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::payments::mojom::PaymentDetailsDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::payments::mojom::internal::PaymentDetails_Data);
            decltype(CallWithContext(Traits::total, input, custom_context)) in_total = CallWithContext(Traits::total, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::payments::mojom::PaymentItemDataView>(
                in_total, context);
            decltype(CallWithContext(Traits::display_items, input, custom_context)) in_display_items = CallWithContext(Traits::display_items, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::payments::mojom::PaymentItemDataView>>(
                in_display_items, context);
            decltype(CallWithContext(Traits::shipping_options, input, custom_context)) in_shipping_options = CallWithContext(Traits::shipping_options, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::payments::mojom::PaymentShippingOptionDataView>>(
                in_shipping_options, context);
            decltype(CallWithContext(Traits::modifiers, input, custom_context)) in_modifiers = CallWithContext(Traits::modifiers, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::payments::mojom::PaymentDetailsModifierDataView>>(
                in_modifiers, context);
            decltype(CallWithContext(Traits::error, input, custom_context)) in_error = CallWithContext(Traits::error, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_error, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::payments::mojom::internal::PaymentDetails_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::payments::mojom::internal::PaymentDetails_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::total, input, custom_context)) in_total = CallWithContext(Traits::total, input, custom_context);
            typename decltype(result->total)::BaseType* total_ptr;
            mojo::internal::Serialize<::payments::mojom::PaymentItemDataView>(
                in_total, buffer, &total_ptr, context);
            result->total.Set(total_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->total.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null total in PaymentDetails struct");
            decltype(CallWithContext(Traits::display_items, input, custom_context)) in_display_items = CallWithContext(Traits::display_items, input, custom_context);
            typename decltype(result->display_items)::BaseType* display_items_ptr;
            const mojo::internal::ContainerValidateParams display_items_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::payments::mojom::PaymentItemDataView>>(
                in_display_items, buffer, &display_items_ptr, &display_items_validate_params,
                context);
            result->display_items.Set(display_items_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->display_items.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null display_items in PaymentDetails struct");
            decltype(CallWithContext(Traits::shipping_options, input, custom_context)) in_shipping_options = CallWithContext(Traits::shipping_options, input, custom_context);
            typename decltype(result->shipping_options)::BaseType* shipping_options_ptr;
            const mojo::internal::ContainerValidateParams shipping_options_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::payments::mojom::PaymentShippingOptionDataView>>(
                in_shipping_options, buffer, &shipping_options_ptr, &shipping_options_validate_params,
                context);
            result->shipping_options.Set(shipping_options_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->shipping_options.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null shipping_options in PaymentDetails struct");
            decltype(CallWithContext(Traits::modifiers, input, custom_context)) in_modifiers = CallWithContext(Traits::modifiers, input, custom_context);
            typename decltype(result->modifiers)::BaseType* modifiers_ptr;
            const mojo::internal::ContainerValidateParams modifiers_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::payments::mojom::PaymentDetailsModifierDataView>>(
                in_modifiers, buffer, &modifiers_ptr, &modifiers_validate_params,
                context);
            result->modifiers.Set(modifiers_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->modifiers.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null modifiers in PaymentDetails struct");
            decltype(CallWithContext(Traits::error, input, custom_context)) in_error = CallWithContext(Traits::error, input, custom_context);
            typename decltype(result->error)::BaseType* error_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_error, buffer, &error_ptr, context);
            result->error.Set(error_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->error.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null error in PaymentDetails struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::payments::mojom::internal::PaymentDetails_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::payments::mojom::PaymentDetailsDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::payments::mojom::PaymentOptionsDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::payments::mojom::PaymentOptionsDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::payments::mojom::internal::PaymentOptions_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::payments::mojom::internal::PaymentOptions_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::payments::mojom::internal::PaymentOptions_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->request_payer_name = CallWithContext(Traits::request_payer_name, input, custom_context);
            result->request_payer_email = CallWithContext(Traits::request_payer_email, input, custom_context);
            result->request_payer_phone = CallWithContext(Traits::request_payer_phone, input, custom_context);
            result->request_shipping = CallWithContext(Traits::request_shipping, input, custom_context);
            mojo::internal::Serialize<::payments::mojom::PaymentShippingType>(
                CallWithContext(Traits::shipping_type, input, custom_context), &result->shipping_type);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::payments::mojom::internal::PaymentOptions_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::payments::mojom::PaymentOptionsDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace payments {
namespace mojom {

    inline void PaymentAddressDataView::GetCountryDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->country.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PaymentAddressDataView::GetAddressLineDataView(
        mojo::ArrayDataView<mojo::StringDataView>* output)
    {
        auto pointer = data_->address_line.Get();
        *output = mojo::ArrayDataView<mojo::StringDataView>(pointer, context_);
    }
    inline void PaymentAddressDataView::GetRegionDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->region.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PaymentAddressDataView::GetCityDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->city.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PaymentAddressDataView::GetDependentLocalityDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->dependent_locality.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PaymentAddressDataView::GetPostalCodeDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->postal_code.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PaymentAddressDataView::GetSortingCodeDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->sorting_code.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PaymentAddressDataView::GetLanguageCodeDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->language_code.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PaymentAddressDataView::GetScriptCodeDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->script_code.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PaymentAddressDataView::GetOrganizationDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->organization.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PaymentAddressDataView::GetRecipientDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->recipient.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PaymentAddressDataView::GetPhoneDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->phone.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void PaymentCurrencyAmountDataView::GetCurrencyDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->currency.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PaymentCurrencyAmountDataView::GetValueDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->value.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PaymentCurrencyAmountDataView::GetCurrencySystemDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->currency_system.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void PaymentResponseDataView::GetMethodNameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->method_name.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PaymentResponseDataView::GetStringifiedDetailsDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->stringified_details.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PaymentResponseDataView::GetShippingAddressDataView(
        PaymentAddressDataView* output)
    {
        auto pointer = data_->shipping_address.Get();
        *output = PaymentAddressDataView(pointer, context_);
    }
    inline void PaymentResponseDataView::GetShippingOptionDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->shipping_option.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PaymentResponseDataView::GetPayerNameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->payer_name.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PaymentResponseDataView::GetPayerEmailDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->payer_email.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PaymentResponseDataView::GetPayerPhoneDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->payer_phone.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void PaymentItemDataView::GetLabelDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->label.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PaymentItemDataView::GetAmountDataView(
        PaymentCurrencyAmountDataView* output)
    {
        auto pointer = data_->amount.Get();
        *output = PaymentCurrencyAmountDataView(pointer, context_);
    }

    inline void PaymentShippingOptionDataView::GetIdDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->id.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PaymentShippingOptionDataView::GetLabelDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->label.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PaymentShippingOptionDataView::GetAmountDataView(
        PaymentCurrencyAmountDataView* output)
    {
        auto pointer = data_->amount.Get();
        *output = PaymentCurrencyAmountDataView(pointer, context_);
    }

    inline void AndroidPayTokenizationParameterDataView::GetKeyDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->key.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void AndroidPayTokenizationParameterDataView::GetValueDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->value.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void PaymentMethodDataDataView::GetSupportedMethodsDataView(
        mojo::ArrayDataView<mojo::StringDataView>* output)
    {
        auto pointer = data_->supported_methods.Get();
        *output = mojo::ArrayDataView<mojo::StringDataView>(pointer, context_);
    }
    inline void PaymentMethodDataDataView::GetStringifiedDataDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->stringified_data.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PaymentMethodDataDataView::GetMerchantNameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->merchant_name.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PaymentMethodDataDataView::GetMerchantIdDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->merchant_id.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PaymentMethodDataDataView::GetAllowedCardNetworksDataView(
        mojo::ArrayDataView<AndroidPayCardNetwork>* output)
    {
        auto pointer = data_->allowed_card_networks.Get();
        *output = mojo::ArrayDataView<AndroidPayCardNetwork>(pointer, context_);
    }
    inline void PaymentMethodDataDataView::GetParametersDataView(
        mojo::ArrayDataView<AndroidPayTokenizationParameterDataView>* output)
    {
        auto pointer = data_->parameters.Get();
        *output = mojo::ArrayDataView<AndroidPayTokenizationParameterDataView>(pointer, context_);
    }
    inline void PaymentMethodDataDataView::GetSupportedNetworksDataView(
        mojo::ArrayDataView<BasicCardNetwork>* output)
    {
        auto pointer = data_->supported_networks.Get();
        *output = mojo::ArrayDataView<BasicCardNetwork>(pointer, context_);
    }
    inline void PaymentMethodDataDataView::GetSupportedTypesDataView(
        mojo::ArrayDataView<BasicCardType>* output)
    {
        auto pointer = data_->supported_types.Get();
        *output = mojo::ArrayDataView<BasicCardType>(pointer, context_);
    }

    inline void PaymentDetailsModifierDataView::GetTotalDataView(
        PaymentItemDataView* output)
    {
        auto pointer = data_->total.Get();
        *output = PaymentItemDataView(pointer, context_);
    }
    inline void PaymentDetailsModifierDataView::GetAdditionalDisplayItemsDataView(
        mojo::ArrayDataView<PaymentItemDataView>* output)
    {
        auto pointer = data_->additional_display_items.Get();
        *output = mojo::ArrayDataView<PaymentItemDataView>(pointer, context_);
    }
    inline void PaymentDetailsModifierDataView::GetMethodDataDataView(
        PaymentMethodDataDataView* output)
    {
        auto pointer = data_->method_data.Get();
        *output = PaymentMethodDataDataView(pointer, context_);
    }

    inline void PaymentDetailsDataView::GetTotalDataView(
        PaymentItemDataView* output)
    {
        auto pointer = data_->total.Get();
        *output = PaymentItemDataView(pointer, context_);
    }
    inline void PaymentDetailsDataView::GetDisplayItemsDataView(
        mojo::ArrayDataView<PaymentItemDataView>* output)
    {
        auto pointer = data_->display_items.Get();
        *output = mojo::ArrayDataView<PaymentItemDataView>(pointer, context_);
    }
    inline void PaymentDetailsDataView::GetShippingOptionsDataView(
        mojo::ArrayDataView<PaymentShippingOptionDataView>* output)
    {
        auto pointer = data_->shipping_options.Get();
        *output = mojo::ArrayDataView<PaymentShippingOptionDataView>(pointer, context_);
    }
    inline void PaymentDetailsDataView::GetModifiersDataView(
        mojo::ArrayDataView<PaymentDetailsModifierDataView>* output)
    {
        auto pointer = data_->modifiers.Get();
        *output = mojo::ArrayDataView<PaymentDetailsModifierDataView>(pointer, context_);
    }
    inline void PaymentDetailsDataView::GetErrorDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->error.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void PaymentRequestClient_OnShippingAddressChange_ParamsDataView::GetAddressDataView(
        PaymentAddressDataView* output)
    {
        auto pointer = data_->address.Get();
        *output = PaymentAddressDataView(pointer, context_);
    }

    inline void PaymentRequestClient_OnShippingOptionChange_ParamsDataView::GetShippingOptionIdDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->shipping_option_id.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void PaymentRequestClient_OnPaymentResponse_ParamsDataView::GetResponseDataView(
        PaymentResponseDataView* output)
    {
        auto pointer = data_->response.Get();
        *output = PaymentResponseDataView(pointer, context_);
    }

    inline void PaymentRequest_Init_ParamsDataView::GetMethodDataDataView(
        mojo::ArrayDataView<PaymentMethodDataDataView>* output)
    {
        auto pointer = data_->method_data.Get();
        *output = mojo::ArrayDataView<PaymentMethodDataDataView>(pointer, context_);
    }
    inline void PaymentRequest_Init_ParamsDataView::GetDetailsDataView(
        PaymentDetailsDataView* output)
    {
        auto pointer = data_->details.Get();
        *output = PaymentDetailsDataView(pointer, context_);
    }
    inline void PaymentRequest_Init_ParamsDataView::GetOptionsDataView(
        PaymentOptionsDataView* output)
    {
        auto pointer = data_->options.Get();
        *output = PaymentOptionsDataView(pointer, context_);
    }

    inline void PaymentRequest_UpdateWith_ParamsDataView::GetDetailsDataView(
        PaymentDetailsDataView* output)
    {
        auto pointer = data_->details.Get();
        *output = PaymentDetailsDataView(pointer, context_);
    }

} // namespace mojom
} // namespace payments

#endif // COMPONENTS_PAYMENTS_PAYMENT_REQUEST_MOJOM_SHARED_H_
