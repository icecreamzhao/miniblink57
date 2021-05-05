// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_PAYMENTS_PAYMENT_REQUEST_MOJOM_H_
#define COMPONENTS_PAYMENTS_PAYMENT_REQUEST_MOJOM_H_

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
#include "components/payments/payment_request.mojom-shared.h"
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
#include <string>
#include <vector>

namespace payments {
namespace mojom {
    class PaymentRequestClient;
    using PaymentRequestClientPtr = mojo::InterfacePtr<PaymentRequestClient>;
    using PaymentRequestClientPtrInfo = mojo::InterfacePtrInfo<PaymentRequestClient>;
    using ThreadSafePaymentRequestClientPtr = mojo::ThreadSafeInterfacePtr<PaymentRequestClient>;
    using PaymentRequestClientRequest = mojo::InterfaceRequest<PaymentRequestClient>;
    using PaymentRequestClientAssociatedPtr = mojo::AssociatedInterfacePtr<PaymentRequestClient>;
    using ThreadSafePaymentRequestClientAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<PaymentRequestClient>;
    using PaymentRequestClientAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<PaymentRequestClient>;
    using PaymentRequestClientAssociatedRequest = mojo::AssociatedInterfaceRequest<PaymentRequestClient>;

    class PaymentRequest;
    using PaymentRequestPtr = mojo::InterfacePtr<PaymentRequest>;
    using PaymentRequestPtrInfo = mojo::InterfacePtrInfo<PaymentRequest>;
    using ThreadSafePaymentRequestPtr = mojo::ThreadSafeInterfacePtr<PaymentRequest>;
    using PaymentRequestRequest = mojo::InterfaceRequest<PaymentRequest>;
    using PaymentRequestAssociatedPtr = mojo::AssociatedInterfacePtr<PaymentRequest>;
    using ThreadSafePaymentRequestAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<PaymentRequest>;
    using PaymentRequestAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<PaymentRequest>;
    using PaymentRequestAssociatedRequest = mojo::AssociatedInterfaceRequest<PaymentRequest>;

    class PaymentAddress;
    using PaymentAddressPtr = mojo::StructPtr<PaymentAddress>;

    class PaymentCurrencyAmount;
    using PaymentCurrencyAmountPtr = mojo::InlinedStructPtr<PaymentCurrencyAmount>;

    class PaymentResponse;
    using PaymentResponsePtr = mojo::StructPtr<PaymentResponse>;

    class PaymentItem;
    using PaymentItemPtr = mojo::StructPtr<PaymentItem>;

    class PaymentShippingOption;
    using PaymentShippingOptionPtr = mojo::StructPtr<PaymentShippingOption>;

    class AndroidPayTokenizationParameter;
    using AndroidPayTokenizationParameterPtr = mojo::InlinedStructPtr<AndroidPayTokenizationParameter>;

    class PaymentMethodData;
    using PaymentMethodDataPtr = mojo::StructPtr<PaymentMethodData>;

    class PaymentDetailsModifier;
    using PaymentDetailsModifierPtr = mojo::StructPtr<PaymentDetailsModifier>;

    class PaymentDetails;
    using PaymentDetailsPtr = mojo::StructPtr<PaymentDetails>;

    class PaymentOptions;
    using PaymentOptionsPtr = mojo::StructPtr<PaymentOptions>;

    class PaymentRequestClientProxy;

    template <typename ImplRefTraits>
    class PaymentRequestClientStub;

    class PaymentRequestClientRequestValidator;

    class PaymentRequestClient
        : public PaymentRequestClientInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = PaymentRequestClientProxy;

        template <typename ImplRefTraits>
        using Stub_ = PaymentRequestClientStub<ImplRefTraits>;

        using RequestValidator_ = PaymentRequestClientRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kOnShippingAddressChangeMinVersion = 0,
            kOnShippingOptionChangeMinVersion = 0,
            kOnPaymentResponseMinVersion = 0,
            kOnErrorMinVersion = 0,
            kOnCompleteMinVersion = 0,
            kOnAbortMinVersion = 0,
            kOnCanMakePaymentMinVersion = 0,
        };
        virtual ~PaymentRequestClient() { }

        virtual void OnShippingAddressChange(PaymentAddressPtr address) = 0;

        virtual void OnShippingOptionChange(const std::string& shipping_option_id) = 0;

        virtual void OnPaymentResponse(PaymentResponsePtr response) = 0;

        virtual void OnError(PaymentErrorReason error) = 0;

        virtual void OnComplete() = 0;

        virtual void OnAbort(bool aborted_successfully) = 0;

        virtual void OnCanMakePayment(CanMakePaymentQueryResult result) = 0;
    };

    class PaymentRequestProxy;

    template <typename ImplRefTraits>
    class PaymentRequestStub;

    class PaymentRequestRequestValidator;

    class PaymentRequest
        : public PaymentRequestInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = PaymentRequestProxy;

        template <typename ImplRefTraits>
        using Stub_ = PaymentRequestStub<ImplRefTraits>;

        using RequestValidator_ = PaymentRequestRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kInitMinVersion = 0,
            kShowMinVersion = 0,
            kUpdateWithMinVersion = 0,
            kAbortMinVersion = 0,
            kCompleteMinVersion = 0,
            kCanMakePaymentMinVersion = 0,
        };
        virtual ~PaymentRequest() { }

        virtual void Init(PaymentRequestClientPtr client, std::vector<PaymentMethodDataPtr> method_data, PaymentDetailsPtr details, PaymentOptionsPtr options) = 0;

        virtual void Show() = 0;

        virtual void UpdateWith(PaymentDetailsPtr details) = 0;

        virtual void Abort() = 0;

        virtual void Complete(PaymentComplete result) = 0;

        virtual void CanMakePayment() = 0;
    };

    class PaymentRequestClientProxy
        : public PaymentRequestClient {
    public:
        explicit PaymentRequestClientProxy(mojo::MessageReceiverWithResponder* receiver);
        void OnShippingAddressChange(PaymentAddressPtr address) override;
        void OnShippingOptionChange(const std::string& shipping_option_id) override;
        void OnPaymentResponse(PaymentResponsePtr response) override;
        void OnError(PaymentErrorReason error) override;
        void OnComplete() override;
        void OnAbort(bool aborted_successfully) override;
        void OnCanMakePayment(CanMakePaymentQueryResult result) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class PaymentRequestProxy
        : public PaymentRequest {
    public:
        explicit PaymentRequestProxy(mojo::MessageReceiverWithResponder* receiver);
        void Init(PaymentRequestClientPtr client, std::vector<PaymentMethodDataPtr> method_data, PaymentDetailsPtr details, PaymentOptionsPtr options) override;
        void Show() override;
        void UpdateWith(PaymentDetailsPtr details) override;
        void Abort() override;
        void Complete(PaymentComplete result) override;
        void CanMakePayment() override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class PaymentRequestClientStubDispatch {
    public:
        static bool Accept(PaymentRequestClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(PaymentRequestClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<PaymentRequestClient>>
    class PaymentRequestClientStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        PaymentRequestClientStub() { }
        ~PaymentRequestClientStub() override { }

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
            return PaymentRequestClientStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return PaymentRequestClientStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class PaymentRequestStubDispatch {
    public:
        static bool Accept(PaymentRequest* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(PaymentRequest* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<PaymentRequest>>
    class PaymentRequestStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        PaymentRequestStub() { }
        ~PaymentRequestStub() override { }

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
            return PaymentRequestStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return PaymentRequestStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class PaymentRequestClientRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class PaymentRequestRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

    class PaymentCurrencyAmount {
    public:
        using DataView = PaymentCurrencyAmountDataView;
        using Data_ = internal::PaymentCurrencyAmount_Data;

        static PaymentCurrencyAmountPtr New();

        template <typename U>
        static PaymentCurrencyAmountPtr From(const U& u)
        {
            return mojo::TypeConverter<PaymentCurrencyAmountPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, PaymentCurrencyAmount>::Convert(*this);
        }

        PaymentCurrencyAmount();
        ~PaymentCurrencyAmount();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = PaymentCurrencyAmountPtr>
        PaymentCurrencyAmountPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, PaymentCurrencyAmount>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                PaymentCurrencyAmount::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                PaymentCurrencyAmount::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::string currency;
        std::string value;
        base::Optional<std::string> currency_system;
    };

    class AndroidPayTokenizationParameter {
    public:
        using DataView = AndroidPayTokenizationParameterDataView;
        using Data_ = internal::AndroidPayTokenizationParameter_Data;

        static AndroidPayTokenizationParameterPtr New();

        template <typename U>
        static AndroidPayTokenizationParameterPtr From(const U& u)
        {
            return mojo::TypeConverter<AndroidPayTokenizationParameterPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, AndroidPayTokenizationParameter>::Convert(*this);
        }

        AndroidPayTokenizationParameter();
        ~AndroidPayTokenizationParameter();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = AndroidPayTokenizationParameterPtr>
        AndroidPayTokenizationParameterPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, AndroidPayTokenizationParameter>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                AndroidPayTokenizationParameter::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                AndroidPayTokenizationParameter::DataView, std::vector<uint8_t>>(
                input, output);
        }

        base::Optional<std::string> key;
        base::Optional<std::string> value;
    };

    class PaymentAddress {
    public:
        using DataView = PaymentAddressDataView;
        using Data_ = internal::PaymentAddress_Data;

        static PaymentAddressPtr New();

        template <typename U>
        static PaymentAddressPtr From(const U& u)
        {
            return mojo::TypeConverter<PaymentAddressPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, PaymentAddress>::Convert(*this);
        }

        PaymentAddress();
        ~PaymentAddress();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = PaymentAddressPtr>
        PaymentAddressPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, PaymentAddress>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                PaymentAddress::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                PaymentAddress::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::string country;
        std::vector<std::string> address_line;
        std::string region;
        std::string city;
        std::string dependent_locality;
        std::string postal_code;
        std::string sorting_code;
        std::string language_code;
        std::string script_code;
        std::string organization;
        std::string recipient;
        std::string phone;
    };

    class PaymentResponse {
    public:
        using DataView = PaymentResponseDataView;
        using Data_ = internal::PaymentResponse_Data;

        static PaymentResponsePtr New();

        template <typename U>
        static PaymentResponsePtr From(const U& u)
        {
            return mojo::TypeConverter<PaymentResponsePtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, PaymentResponse>::Convert(*this);
        }

        PaymentResponse();
        ~PaymentResponse();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = PaymentResponsePtr>
        PaymentResponsePtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, PaymentResponse>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                PaymentResponse::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                PaymentResponse::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::string method_name;
        std::string stringified_details;
        PaymentAddressPtr shipping_address;
        base::Optional<std::string> shipping_option;
        base::Optional<std::string> payer_name;
        base::Optional<std::string> payer_email;
        base::Optional<std::string> payer_phone;

    private:
        DISALLOW_COPY_AND_ASSIGN(PaymentResponse);
    };

    class PaymentItem {
    public:
        using DataView = PaymentItemDataView;
        using Data_ = internal::PaymentItem_Data;

        static PaymentItemPtr New();

        template <typename U>
        static PaymentItemPtr From(const U& u)
        {
            return mojo::TypeConverter<PaymentItemPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, PaymentItem>::Convert(*this);
        }

        PaymentItem();
        ~PaymentItem();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = PaymentItemPtr>
        PaymentItemPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, PaymentItem>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                PaymentItem::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                PaymentItem::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::string label;
        PaymentCurrencyAmountPtr amount;
        bool pending;

    private:
        DISALLOW_COPY_AND_ASSIGN(PaymentItem);
    };

    class PaymentShippingOption {
    public:
        using DataView = PaymentShippingOptionDataView;
        using Data_ = internal::PaymentShippingOption_Data;

        static PaymentShippingOptionPtr New();

        template <typename U>
        static PaymentShippingOptionPtr From(const U& u)
        {
            return mojo::TypeConverter<PaymentShippingOptionPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, PaymentShippingOption>::Convert(*this);
        }

        PaymentShippingOption();
        ~PaymentShippingOption();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = PaymentShippingOptionPtr>
        PaymentShippingOptionPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, PaymentShippingOption>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                PaymentShippingOption::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                PaymentShippingOption::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::string id;
        std::string label;
        PaymentCurrencyAmountPtr amount;
        bool selected;

    private:
        DISALLOW_COPY_AND_ASSIGN(PaymentShippingOption);
    };

    class PaymentMethodData {
    public:
        using DataView = PaymentMethodDataDataView;
        using Data_ = internal::PaymentMethodData_Data;

        static PaymentMethodDataPtr New();

        template <typename U>
        static PaymentMethodDataPtr From(const U& u)
        {
            return mojo::TypeConverter<PaymentMethodDataPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, PaymentMethodData>::Convert(*this);
        }

        PaymentMethodData();
        ~PaymentMethodData();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = PaymentMethodDataPtr>
        PaymentMethodDataPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, PaymentMethodData>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                PaymentMethodData::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                PaymentMethodData::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::vector<std::string> supported_methods;
        std::string stringified_data;
        AndroidPayEnvironment environment;
        base::Optional<std::string> merchant_name;
        base::Optional<std::string> merchant_id;
        std::vector<AndroidPayCardNetwork> allowed_card_networks;
        AndroidPayTokenization tokenization_type;
        std::vector<AndroidPayTokenizationParameterPtr> parameters;
        int32_t min_google_play_services_version;
        std::vector<BasicCardNetwork> supported_networks;
        std::vector<BasicCardType> supported_types;

    private:
        DISALLOW_COPY_AND_ASSIGN(PaymentMethodData);
    };

    class PaymentDetailsModifier {
    public:
        using DataView = PaymentDetailsModifierDataView;
        using Data_ = internal::PaymentDetailsModifier_Data;

        static PaymentDetailsModifierPtr New();

        template <typename U>
        static PaymentDetailsModifierPtr From(const U& u)
        {
            return mojo::TypeConverter<PaymentDetailsModifierPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, PaymentDetailsModifier>::Convert(*this);
        }

        PaymentDetailsModifier();
        ~PaymentDetailsModifier();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = PaymentDetailsModifierPtr>
        PaymentDetailsModifierPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, PaymentDetailsModifier>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                PaymentDetailsModifier::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                PaymentDetailsModifier::DataView, std::vector<uint8_t>>(
                input, output);
        }

        PaymentItemPtr total;
        std::vector<PaymentItemPtr> additional_display_items;
        PaymentMethodDataPtr method_data;

    private:
        DISALLOW_COPY_AND_ASSIGN(PaymentDetailsModifier);
    };

    class PaymentDetails {
    public:
        using DataView = PaymentDetailsDataView;
        using Data_ = internal::PaymentDetails_Data;

        static PaymentDetailsPtr New();

        template <typename U>
        static PaymentDetailsPtr From(const U& u)
        {
            return mojo::TypeConverter<PaymentDetailsPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, PaymentDetails>::Convert(*this);
        }

        PaymentDetails();
        ~PaymentDetails();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = PaymentDetailsPtr>
        PaymentDetailsPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, PaymentDetails>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                PaymentDetails::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                PaymentDetails::DataView, std::vector<uint8_t>>(
                input, output);
        }

        PaymentItemPtr total;
        std::vector<PaymentItemPtr> display_items;
        std::vector<PaymentShippingOptionPtr> shipping_options;
        std::vector<PaymentDetailsModifierPtr> modifiers;
        std::string error;

    private:
        DISALLOW_COPY_AND_ASSIGN(PaymentDetails);
    };

    class PaymentOptions {
    public:
        using DataView = PaymentOptionsDataView;
        using Data_ = internal::PaymentOptions_Data;

        static PaymentOptionsPtr New();

        template <typename U>
        static PaymentOptionsPtr From(const U& u)
        {
            return mojo::TypeConverter<PaymentOptionsPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, PaymentOptions>::Convert(*this);
        }

        PaymentOptions();
        ~PaymentOptions();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = PaymentOptionsPtr>
        PaymentOptionsPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, PaymentOptions>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                PaymentOptions::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                PaymentOptions::DataView, std::vector<uint8_t>>(
                input, output);
        }

        bool request_payer_name;
        bool request_payer_email;
        bool request_payer_phone;
        bool request_shipping;
        PaymentShippingType shipping_type;
    };

    template <typename StructPtrType>
    PaymentAddressPtr PaymentAddress::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->country = mojo::internal::Clone(country);
        rv->address_line = mojo::internal::Clone(address_line);
        rv->region = mojo::internal::Clone(region);
        rv->city = mojo::internal::Clone(city);
        rv->dependent_locality = mojo::internal::Clone(dependent_locality);
        rv->postal_code = mojo::internal::Clone(postal_code);
        rv->sorting_code = mojo::internal::Clone(sorting_code);
        rv->language_code = mojo::internal::Clone(language_code);
        rv->script_code = mojo::internal::Clone(script_code);
        rv->organization = mojo::internal::Clone(organization);
        rv->recipient = mojo::internal::Clone(recipient);
        rv->phone = mojo::internal::Clone(phone);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, PaymentAddress>::value>::type*>
    bool PaymentAddress::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->country, other.country))
            return false;
        if (!mojo::internal::Equals(this->address_line, other.address_line))
            return false;
        if (!mojo::internal::Equals(this->region, other.region))
            return false;
        if (!mojo::internal::Equals(this->city, other.city))
            return false;
        if (!mojo::internal::Equals(this->dependent_locality, other.dependent_locality))
            return false;
        if (!mojo::internal::Equals(this->postal_code, other.postal_code))
            return false;
        if (!mojo::internal::Equals(this->sorting_code, other.sorting_code))
            return false;
        if (!mojo::internal::Equals(this->language_code, other.language_code))
            return false;
        if (!mojo::internal::Equals(this->script_code, other.script_code))
            return false;
        if (!mojo::internal::Equals(this->organization, other.organization))
            return false;
        if (!mojo::internal::Equals(this->recipient, other.recipient))
            return false;
        if (!mojo::internal::Equals(this->phone, other.phone))
            return false;
        return true;
    }
    template <typename StructPtrType>
    PaymentCurrencyAmountPtr PaymentCurrencyAmount::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->currency = mojo::internal::Clone(currency);
        rv->value = mojo::internal::Clone(value);
        rv->currency_system = mojo::internal::Clone(currency_system);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, PaymentCurrencyAmount>::value>::type*>
    bool PaymentCurrencyAmount::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->currency, other.currency))
            return false;
        if (!mojo::internal::Equals(this->value, other.value))
            return false;
        if (!mojo::internal::Equals(this->currency_system, other.currency_system))
            return false;
        return true;
    }
    template <typename StructPtrType>
    PaymentResponsePtr PaymentResponse::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->method_name = mojo::internal::Clone(method_name);
        rv->stringified_details = mojo::internal::Clone(stringified_details);
        rv->shipping_address = mojo::internal::Clone(shipping_address);
        rv->shipping_option = mojo::internal::Clone(shipping_option);
        rv->payer_name = mojo::internal::Clone(payer_name);
        rv->payer_email = mojo::internal::Clone(payer_email);
        rv->payer_phone = mojo::internal::Clone(payer_phone);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, PaymentResponse>::value>::type*>
    bool PaymentResponse::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->method_name, other.method_name))
            return false;
        if (!mojo::internal::Equals(this->stringified_details, other.stringified_details))
            return false;
        if (!mojo::internal::Equals(this->shipping_address, other.shipping_address))
            return false;
        if (!mojo::internal::Equals(this->shipping_option, other.shipping_option))
            return false;
        if (!mojo::internal::Equals(this->payer_name, other.payer_name))
            return false;
        if (!mojo::internal::Equals(this->payer_email, other.payer_email))
            return false;
        if (!mojo::internal::Equals(this->payer_phone, other.payer_phone))
            return false;
        return true;
    }
    template <typename StructPtrType>
    PaymentItemPtr PaymentItem::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->label = mojo::internal::Clone(label);
        rv->amount = mojo::internal::Clone(amount);
        rv->pending = mojo::internal::Clone(pending);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, PaymentItem>::value>::type*>
    bool PaymentItem::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->label, other.label))
            return false;
        if (!mojo::internal::Equals(this->amount, other.amount))
            return false;
        if (!mojo::internal::Equals(this->pending, other.pending))
            return false;
        return true;
    }
    template <typename StructPtrType>
    PaymentShippingOptionPtr PaymentShippingOption::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->id = mojo::internal::Clone(id);
        rv->label = mojo::internal::Clone(label);
        rv->amount = mojo::internal::Clone(amount);
        rv->selected = mojo::internal::Clone(selected);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, PaymentShippingOption>::value>::type*>
    bool PaymentShippingOption::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->id, other.id))
            return false;
        if (!mojo::internal::Equals(this->label, other.label))
            return false;
        if (!mojo::internal::Equals(this->amount, other.amount))
            return false;
        if (!mojo::internal::Equals(this->selected, other.selected))
            return false;
        return true;
    }
    template <typename StructPtrType>
    AndroidPayTokenizationParameterPtr AndroidPayTokenizationParameter::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->key = mojo::internal::Clone(key);
        rv->value = mojo::internal::Clone(value);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, AndroidPayTokenizationParameter>::value>::type*>
    bool AndroidPayTokenizationParameter::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->key, other.key))
            return false;
        if (!mojo::internal::Equals(this->value, other.value))
            return false;
        return true;
    }
    template <typename StructPtrType>
    PaymentMethodDataPtr PaymentMethodData::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->supported_methods = mojo::internal::Clone(supported_methods);
        rv->stringified_data = mojo::internal::Clone(stringified_data);
        rv->environment = mojo::internal::Clone(environment);
        rv->merchant_name = mojo::internal::Clone(merchant_name);
        rv->merchant_id = mojo::internal::Clone(merchant_id);
        rv->allowed_card_networks = mojo::internal::Clone(allowed_card_networks);
        rv->tokenization_type = mojo::internal::Clone(tokenization_type);
        rv->parameters = mojo::internal::Clone(parameters);
        rv->min_google_play_services_version = mojo::internal::Clone(min_google_play_services_version);
        rv->supported_networks = mojo::internal::Clone(supported_networks);
        rv->supported_types = mojo::internal::Clone(supported_types);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, PaymentMethodData>::value>::type*>
    bool PaymentMethodData::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->supported_methods, other.supported_methods))
            return false;
        if (!mojo::internal::Equals(this->stringified_data, other.stringified_data))
            return false;
        if (!mojo::internal::Equals(this->environment, other.environment))
            return false;
        if (!mojo::internal::Equals(this->merchant_name, other.merchant_name))
            return false;
        if (!mojo::internal::Equals(this->merchant_id, other.merchant_id))
            return false;
        if (!mojo::internal::Equals(this->allowed_card_networks, other.allowed_card_networks))
            return false;
        if (!mojo::internal::Equals(this->tokenization_type, other.tokenization_type))
            return false;
        if (!mojo::internal::Equals(this->parameters, other.parameters))
            return false;
        if (!mojo::internal::Equals(this->min_google_play_services_version, other.min_google_play_services_version))
            return false;
        if (!mojo::internal::Equals(this->supported_networks, other.supported_networks))
            return false;
        if (!mojo::internal::Equals(this->supported_types, other.supported_types))
            return false;
        return true;
    }
    template <typename StructPtrType>
    PaymentDetailsModifierPtr PaymentDetailsModifier::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->total = mojo::internal::Clone(total);
        rv->additional_display_items = mojo::internal::Clone(additional_display_items);
        rv->method_data = mojo::internal::Clone(method_data);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, PaymentDetailsModifier>::value>::type*>
    bool PaymentDetailsModifier::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->total, other.total))
            return false;
        if (!mojo::internal::Equals(this->additional_display_items, other.additional_display_items))
            return false;
        if (!mojo::internal::Equals(this->method_data, other.method_data))
            return false;
        return true;
    }
    template <typename StructPtrType>
    PaymentDetailsPtr PaymentDetails::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->total = mojo::internal::Clone(total);
        rv->display_items = mojo::internal::Clone(display_items);
        rv->shipping_options = mojo::internal::Clone(shipping_options);
        rv->modifiers = mojo::internal::Clone(modifiers);
        rv->error = mojo::internal::Clone(error);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, PaymentDetails>::value>::type*>
    bool PaymentDetails::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->total, other.total))
            return false;
        if (!mojo::internal::Equals(this->display_items, other.display_items))
            return false;
        if (!mojo::internal::Equals(this->shipping_options, other.shipping_options))
            return false;
        if (!mojo::internal::Equals(this->modifiers, other.modifiers))
            return false;
        if (!mojo::internal::Equals(this->error, other.error))
            return false;
        return true;
    }
    template <typename StructPtrType>
    PaymentOptionsPtr PaymentOptions::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->request_payer_name = mojo::internal::Clone(request_payer_name);
        rv->request_payer_email = mojo::internal::Clone(request_payer_email);
        rv->request_payer_phone = mojo::internal::Clone(request_payer_phone);
        rv->request_shipping = mojo::internal::Clone(request_shipping);
        rv->shipping_type = mojo::internal::Clone(shipping_type);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, PaymentOptions>::value>::type*>
    bool PaymentOptions::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->request_payer_name, other.request_payer_name))
            return false;
        if (!mojo::internal::Equals(this->request_payer_email, other.request_payer_email))
            return false;
        if (!mojo::internal::Equals(this->request_payer_phone, other.request_payer_phone))
            return false;
        if (!mojo::internal::Equals(this->request_shipping, other.request_shipping))
            return false;
        if (!mojo::internal::Equals(this->shipping_type, other.shipping_type))
            return false;
        return true;
    }

} // namespace mojom
} // namespace payments

namespace mojo {

template <>
struct StructTraits<::payments::mojom::PaymentAddress::DataView,
    ::payments::mojom::PaymentAddressPtr> {
    static bool IsNull(const ::payments::mojom::PaymentAddressPtr& input) { return !input; }
    static void SetToNull(::payments::mojom::PaymentAddressPtr* output) { output->reset(); }

    static const decltype(::payments::mojom::PaymentAddress::country)& country(
        const ::payments::mojom::PaymentAddressPtr& input)
    {
        return input->country;
    }

    static const decltype(::payments::mojom::PaymentAddress::address_line)& address_line(
        const ::payments::mojom::PaymentAddressPtr& input)
    {
        return input->address_line;
    }

    static const decltype(::payments::mojom::PaymentAddress::region)& region(
        const ::payments::mojom::PaymentAddressPtr& input)
    {
        return input->region;
    }

    static const decltype(::payments::mojom::PaymentAddress::city)& city(
        const ::payments::mojom::PaymentAddressPtr& input)
    {
        return input->city;
    }

    static const decltype(::payments::mojom::PaymentAddress::dependent_locality)& dependent_locality(
        const ::payments::mojom::PaymentAddressPtr& input)
    {
        return input->dependent_locality;
    }

    static const decltype(::payments::mojom::PaymentAddress::postal_code)& postal_code(
        const ::payments::mojom::PaymentAddressPtr& input)
    {
        return input->postal_code;
    }

    static const decltype(::payments::mojom::PaymentAddress::sorting_code)& sorting_code(
        const ::payments::mojom::PaymentAddressPtr& input)
    {
        return input->sorting_code;
    }

    static const decltype(::payments::mojom::PaymentAddress::language_code)& language_code(
        const ::payments::mojom::PaymentAddressPtr& input)
    {
        return input->language_code;
    }

    static const decltype(::payments::mojom::PaymentAddress::script_code)& script_code(
        const ::payments::mojom::PaymentAddressPtr& input)
    {
        return input->script_code;
    }

    static const decltype(::payments::mojom::PaymentAddress::organization)& organization(
        const ::payments::mojom::PaymentAddressPtr& input)
    {
        return input->organization;
    }

    static const decltype(::payments::mojom::PaymentAddress::recipient)& recipient(
        const ::payments::mojom::PaymentAddressPtr& input)
    {
        return input->recipient;
    }

    static const decltype(::payments::mojom::PaymentAddress::phone)& phone(
        const ::payments::mojom::PaymentAddressPtr& input)
    {
        return input->phone;
    }

    static bool Read(::payments::mojom::PaymentAddress::DataView input, ::payments::mojom::PaymentAddressPtr* output);
};

template <>
struct StructTraits<::payments::mojom::PaymentCurrencyAmount::DataView,
    ::payments::mojom::PaymentCurrencyAmountPtr> {
    static bool IsNull(const ::payments::mojom::PaymentCurrencyAmountPtr& input) { return !input; }
    static void SetToNull(::payments::mojom::PaymentCurrencyAmountPtr* output) { output->reset(); }

    static const decltype(::payments::mojom::PaymentCurrencyAmount::currency)& currency(
        const ::payments::mojom::PaymentCurrencyAmountPtr& input)
    {
        return input->currency;
    }

    static const decltype(::payments::mojom::PaymentCurrencyAmount::value)& value(
        const ::payments::mojom::PaymentCurrencyAmountPtr& input)
    {
        return input->value;
    }

    static const decltype(::payments::mojom::PaymentCurrencyAmount::currency_system)& currency_system(
        const ::payments::mojom::PaymentCurrencyAmountPtr& input)
    {
        return input->currency_system;
    }

    static bool Read(::payments::mojom::PaymentCurrencyAmount::DataView input, ::payments::mojom::PaymentCurrencyAmountPtr* output);
};

template <>
struct StructTraits<::payments::mojom::PaymentResponse::DataView,
    ::payments::mojom::PaymentResponsePtr> {
    static bool IsNull(const ::payments::mojom::PaymentResponsePtr& input) { return !input; }
    static void SetToNull(::payments::mojom::PaymentResponsePtr* output) { output->reset(); }

    static const decltype(::payments::mojom::PaymentResponse::method_name)& method_name(
        const ::payments::mojom::PaymentResponsePtr& input)
    {
        return input->method_name;
    }

    static const decltype(::payments::mojom::PaymentResponse::stringified_details)& stringified_details(
        const ::payments::mojom::PaymentResponsePtr& input)
    {
        return input->stringified_details;
    }

    static const decltype(::payments::mojom::PaymentResponse::shipping_address)& shipping_address(
        const ::payments::mojom::PaymentResponsePtr& input)
    {
        return input->shipping_address;
    }

    static const decltype(::payments::mojom::PaymentResponse::shipping_option)& shipping_option(
        const ::payments::mojom::PaymentResponsePtr& input)
    {
        return input->shipping_option;
    }

    static const decltype(::payments::mojom::PaymentResponse::payer_name)& payer_name(
        const ::payments::mojom::PaymentResponsePtr& input)
    {
        return input->payer_name;
    }

    static const decltype(::payments::mojom::PaymentResponse::payer_email)& payer_email(
        const ::payments::mojom::PaymentResponsePtr& input)
    {
        return input->payer_email;
    }

    static const decltype(::payments::mojom::PaymentResponse::payer_phone)& payer_phone(
        const ::payments::mojom::PaymentResponsePtr& input)
    {
        return input->payer_phone;
    }

    static bool Read(::payments::mojom::PaymentResponse::DataView input, ::payments::mojom::PaymentResponsePtr* output);
};

template <>
struct StructTraits<::payments::mojom::PaymentItem::DataView,
    ::payments::mojom::PaymentItemPtr> {
    static bool IsNull(const ::payments::mojom::PaymentItemPtr& input) { return !input; }
    static void SetToNull(::payments::mojom::PaymentItemPtr* output) { output->reset(); }

    static const decltype(::payments::mojom::PaymentItem::label)& label(
        const ::payments::mojom::PaymentItemPtr& input)
    {
        return input->label;
    }

    static const decltype(::payments::mojom::PaymentItem::amount)& amount(
        const ::payments::mojom::PaymentItemPtr& input)
    {
        return input->amount;
    }

    static decltype(::payments::mojom::PaymentItem::pending) pending(
        const ::payments::mojom::PaymentItemPtr& input)
    {
        return input->pending;
    }

    static bool Read(::payments::mojom::PaymentItem::DataView input, ::payments::mojom::PaymentItemPtr* output);
};

template <>
struct StructTraits<::payments::mojom::PaymentShippingOption::DataView,
    ::payments::mojom::PaymentShippingOptionPtr> {
    static bool IsNull(const ::payments::mojom::PaymentShippingOptionPtr& input) { return !input; }
    static void SetToNull(::payments::mojom::PaymentShippingOptionPtr* output) { output->reset(); }

    static const decltype(::payments::mojom::PaymentShippingOption::id)& id(
        const ::payments::mojom::PaymentShippingOptionPtr& input)
    {
        return input->id;
    }

    static const decltype(::payments::mojom::PaymentShippingOption::label)& label(
        const ::payments::mojom::PaymentShippingOptionPtr& input)
    {
        return input->label;
    }

    static const decltype(::payments::mojom::PaymentShippingOption::amount)& amount(
        const ::payments::mojom::PaymentShippingOptionPtr& input)
    {
        return input->amount;
    }

    static decltype(::payments::mojom::PaymentShippingOption::selected) selected(
        const ::payments::mojom::PaymentShippingOptionPtr& input)
    {
        return input->selected;
    }

    static bool Read(::payments::mojom::PaymentShippingOption::DataView input, ::payments::mojom::PaymentShippingOptionPtr* output);
};

template <>
struct StructTraits<::payments::mojom::AndroidPayTokenizationParameter::DataView,
    ::payments::mojom::AndroidPayTokenizationParameterPtr> {
    static bool IsNull(const ::payments::mojom::AndroidPayTokenizationParameterPtr& input) { return !input; }
    static void SetToNull(::payments::mojom::AndroidPayTokenizationParameterPtr* output) { output->reset(); }

    static const decltype(::payments::mojom::AndroidPayTokenizationParameter::key)& key(
        const ::payments::mojom::AndroidPayTokenizationParameterPtr& input)
    {
        return input->key;
    }

    static const decltype(::payments::mojom::AndroidPayTokenizationParameter::value)& value(
        const ::payments::mojom::AndroidPayTokenizationParameterPtr& input)
    {
        return input->value;
    }

    static bool Read(::payments::mojom::AndroidPayTokenizationParameter::DataView input, ::payments::mojom::AndroidPayTokenizationParameterPtr* output);
};

template <>
struct StructTraits<::payments::mojom::PaymentMethodData::DataView,
    ::payments::mojom::PaymentMethodDataPtr> {
    static bool IsNull(const ::payments::mojom::PaymentMethodDataPtr& input) { return !input; }
    static void SetToNull(::payments::mojom::PaymentMethodDataPtr* output) { output->reset(); }

    static const decltype(::payments::mojom::PaymentMethodData::supported_methods)& supported_methods(
        const ::payments::mojom::PaymentMethodDataPtr& input)
    {
        return input->supported_methods;
    }

    static const decltype(::payments::mojom::PaymentMethodData::stringified_data)& stringified_data(
        const ::payments::mojom::PaymentMethodDataPtr& input)
    {
        return input->stringified_data;
    }

    static decltype(::payments::mojom::PaymentMethodData::environment) environment(
        const ::payments::mojom::PaymentMethodDataPtr& input)
    {
        return input->environment;
    }

    static const decltype(::payments::mojom::PaymentMethodData::merchant_name)& merchant_name(
        const ::payments::mojom::PaymentMethodDataPtr& input)
    {
        return input->merchant_name;
    }

    static const decltype(::payments::mojom::PaymentMethodData::merchant_id)& merchant_id(
        const ::payments::mojom::PaymentMethodDataPtr& input)
    {
        return input->merchant_id;
    }

    static const decltype(::payments::mojom::PaymentMethodData::allowed_card_networks)& allowed_card_networks(
        const ::payments::mojom::PaymentMethodDataPtr& input)
    {
        return input->allowed_card_networks;
    }

    static decltype(::payments::mojom::PaymentMethodData::tokenization_type) tokenization_type(
        const ::payments::mojom::PaymentMethodDataPtr& input)
    {
        return input->tokenization_type;
    }

    static const decltype(::payments::mojom::PaymentMethodData::parameters)& parameters(
        const ::payments::mojom::PaymentMethodDataPtr& input)
    {
        return input->parameters;
    }

    static decltype(::payments::mojom::PaymentMethodData::min_google_play_services_version) min_google_play_services_version(
        const ::payments::mojom::PaymentMethodDataPtr& input)
    {
        return input->min_google_play_services_version;
    }

    static const decltype(::payments::mojom::PaymentMethodData::supported_networks)& supported_networks(
        const ::payments::mojom::PaymentMethodDataPtr& input)
    {
        return input->supported_networks;
    }

    static const decltype(::payments::mojom::PaymentMethodData::supported_types)& supported_types(
        const ::payments::mojom::PaymentMethodDataPtr& input)
    {
        return input->supported_types;
    }

    static bool Read(::payments::mojom::PaymentMethodData::DataView input, ::payments::mojom::PaymentMethodDataPtr* output);
};

template <>
struct StructTraits<::payments::mojom::PaymentDetailsModifier::DataView,
    ::payments::mojom::PaymentDetailsModifierPtr> {
    static bool IsNull(const ::payments::mojom::PaymentDetailsModifierPtr& input) { return !input; }
    static void SetToNull(::payments::mojom::PaymentDetailsModifierPtr* output) { output->reset(); }

    static const decltype(::payments::mojom::PaymentDetailsModifier::total)& total(
        const ::payments::mojom::PaymentDetailsModifierPtr& input)
    {
        return input->total;
    }

    static const decltype(::payments::mojom::PaymentDetailsModifier::additional_display_items)& additional_display_items(
        const ::payments::mojom::PaymentDetailsModifierPtr& input)
    {
        return input->additional_display_items;
    }

    static const decltype(::payments::mojom::PaymentDetailsModifier::method_data)& method_data(
        const ::payments::mojom::PaymentDetailsModifierPtr& input)
    {
        return input->method_data;
    }

    static bool Read(::payments::mojom::PaymentDetailsModifier::DataView input, ::payments::mojom::PaymentDetailsModifierPtr* output);
};

template <>
struct StructTraits<::payments::mojom::PaymentDetails::DataView,
    ::payments::mojom::PaymentDetailsPtr> {
    static bool IsNull(const ::payments::mojom::PaymentDetailsPtr& input) { return !input; }
    static void SetToNull(::payments::mojom::PaymentDetailsPtr* output) { output->reset(); }

    static const decltype(::payments::mojom::PaymentDetails::total)& total(
        const ::payments::mojom::PaymentDetailsPtr& input)
    {
        return input->total;
    }

    static const decltype(::payments::mojom::PaymentDetails::display_items)& display_items(
        const ::payments::mojom::PaymentDetailsPtr& input)
    {
        return input->display_items;
    }

    static const decltype(::payments::mojom::PaymentDetails::shipping_options)& shipping_options(
        const ::payments::mojom::PaymentDetailsPtr& input)
    {
        return input->shipping_options;
    }

    static const decltype(::payments::mojom::PaymentDetails::modifiers)& modifiers(
        const ::payments::mojom::PaymentDetailsPtr& input)
    {
        return input->modifiers;
    }

    static const decltype(::payments::mojom::PaymentDetails::error)& error(
        const ::payments::mojom::PaymentDetailsPtr& input)
    {
        return input->error;
    }

    static bool Read(::payments::mojom::PaymentDetails::DataView input, ::payments::mojom::PaymentDetailsPtr* output);
};

template <>
struct StructTraits<::payments::mojom::PaymentOptions::DataView,
    ::payments::mojom::PaymentOptionsPtr> {
    static bool IsNull(const ::payments::mojom::PaymentOptionsPtr& input) { return !input; }
    static void SetToNull(::payments::mojom::PaymentOptionsPtr* output) { output->reset(); }

    static decltype(::payments::mojom::PaymentOptions::request_payer_name) request_payer_name(
        const ::payments::mojom::PaymentOptionsPtr& input)
    {
        return input->request_payer_name;
    }

    static decltype(::payments::mojom::PaymentOptions::request_payer_email) request_payer_email(
        const ::payments::mojom::PaymentOptionsPtr& input)
    {
        return input->request_payer_email;
    }

    static decltype(::payments::mojom::PaymentOptions::request_payer_phone) request_payer_phone(
        const ::payments::mojom::PaymentOptionsPtr& input)
    {
        return input->request_payer_phone;
    }

    static decltype(::payments::mojom::PaymentOptions::request_shipping) request_shipping(
        const ::payments::mojom::PaymentOptionsPtr& input)
    {
        return input->request_shipping;
    }

    static decltype(::payments::mojom::PaymentOptions::shipping_type) shipping_type(
        const ::payments::mojom::PaymentOptionsPtr& input)
    {
        return input->shipping_type;
    }

    static bool Read(::payments::mojom::PaymentOptions::DataView input, ::payments::mojom::PaymentOptionsPtr* output);
};

} // namespace mojo

#endif // COMPONENTS_PAYMENTS_PAYMENT_REQUEST_MOJOM_H_