// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_PAYMENTS_PAYMENT_APP_MOJOM_H_
#define COMPONENTS_PAYMENTS_PAYMENT_APP_MOJOM_H_

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
#include "components/payments/payment_app.mojom-shared.h"
#include "components/payments/payment_request.mojom.h"
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
#include "url/gurl.h"
#include "url/mojo/url.mojom.h"
#include <string>
#include <vector>

namespace payments {
namespace mojom {
    class PaymentAppManager;
    using PaymentAppManagerPtr = mojo::InterfacePtr<PaymentAppManager>;
    using PaymentAppManagerPtrInfo = mojo::InterfacePtrInfo<PaymentAppManager>;
    using ThreadSafePaymentAppManagerPtr = mojo::ThreadSafeInterfacePtr<PaymentAppManager>;
    using PaymentAppManagerRequest = mojo::InterfaceRequest<PaymentAppManager>;
    using PaymentAppManagerAssociatedPtr = mojo::AssociatedInterfacePtr<PaymentAppManager>;
    using ThreadSafePaymentAppManagerAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<PaymentAppManager>;
    using PaymentAppManagerAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<PaymentAppManager>;
    using PaymentAppManagerAssociatedRequest = mojo::AssociatedInterfaceRequest<PaymentAppManager>;

    class PaymentAppOption;
    using PaymentAppOptionPtr = mojo::StructPtr<PaymentAppOption>;

    class PaymentAppManifest;
    using PaymentAppManifestPtr = mojo::StructPtr<PaymentAppManifest>;

    class PaymentAppRequestData;
    using PaymentAppRequestDataPtr = mojo::StructPtr<PaymentAppRequestData>;

    class PaymentAppManagerProxy;

    template <typename ImplRefTraits>
    class PaymentAppManagerStub;

    class PaymentAppManagerRequestValidator;
    class PaymentAppManagerResponseValidator;

    class PaymentAppManager
        : public PaymentAppManagerInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = PaymentAppManagerProxy;

        template <typename ImplRefTraits>
        using Stub_ = PaymentAppManagerStub<ImplRefTraits>;

        using RequestValidator_ = PaymentAppManagerRequestValidator;
        using ResponseValidator_ = PaymentAppManagerResponseValidator;
        enum MethodMinVersions : uint32_t {
            kInitMinVersion = 0,
            kSetManifestMinVersion = 0,
            kGetManifestMinVersion = 0,
        };
        virtual ~PaymentAppManager() { }

        virtual void Init(const std::string& service_worker_scope) = 0;

        using SetManifestCallback = base::Callback<void(PaymentAppManifestError)>;
        virtual void SetManifest(PaymentAppManifestPtr payment_app_manifest, const SetManifestCallback& callback) = 0;

        using GetManifestCallback = base::Callback<void(PaymentAppManifestPtr, PaymentAppManifestError)>;
        virtual void GetManifest(const GetManifestCallback& callback) = 0;
    };

    class PaymentAppManagerProxy
        : public PaymentAppManager {
    public:
        explicit PaymentAppManagerProxy(mojo::MessageReceiverWithResponder* receiver);
        void Init(const std::string& service_worker_scope) override;
        void SetManifest(PaymentAppManifestPtr payment_app_manifest, const SetManifestCallback& callback) override;
        void GetManifest(const GetManifestCallback& callback) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class PaymentAppManagerStubDispatch {
    public:
        static bool Accept(PaymentAppManager* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(PaymentAppManager* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<PaymentAppManager>>
    class PaymentAppManagerStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        PaymentAppManagerStub() { }
        ~PaymentAppManagerStub() override { }

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
            return PaymentAppManagerStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return PaymentAppManagerStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class PaymentAppManagerRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class PaymentAppManagerResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

    class PaymentAppOption {
    public:
        using DataView = PaymentAppOptionDataView;
        using Data_ = internal::PaymentAppOption_Data;

        static PaymentAppOptionPtr New();

        template <typename U>
        static PaymentAppOptionPtr From(const U& u)
        {
            return mojo::TypeConverter<PaymentAppOptionPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, PaymentAppOption>::Convert(*this);
        }

        PaymentAppOption();
        ~PaymentAppOption();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = PaymentAppOptionPtr>
        PaymentAppOptionPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, PaymentAppOption>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                PaymentAppOption::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                PaymentAppOption::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::string name;
        base::Optional<std::string> icon;
        std::string id;
        std::vector<std::string> enabled_methods;
    };

    class PaymentAppManifest {
    public:
        using DataView = PaymentAppManifestDataView;
        using Data_ = internal::PaymentAppManifest_Data;

        static PaymentAppManifestPtr New();

        template <typename U>
        static PaymentAppManifestPtr From(const U& u)
        {
            return mojo::TypeConverter<PaymentAppManifestPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, PaymentAppManifest>::Convert(*this);
        }

        PaymentAppManifest();
        ~PaymentAppManifest();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = PaymentAppManifestPtr>
        PaymentAppManifestPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, PaymentAppManifest>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                PaymentAppManifest::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                PaymentAppManifest::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::string name;
        base::Optional<std::string> icon;
        std::vector<PaymentAppOptionPtr> options;

    private:
        DISALLOW_COPY_AND_ASSIGN(PaymentAppManifest);
    };

    class PaymentAppRequestData {
    public:
        using DataView = PaymentAppRequestDataDataView;
        using Data_ = internal::PaymentAppRequestData_Data;

        static PaymentAppRequestDataPtr New();

        template <typename U>
        static PaymentAppRequestDataPtr From(const U& u)
        {
            return mojo::TypeConverter<PaymentAppRequestDataPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, PaymentAppRequestData>::Convert(*this);
        }

        PaymentAppRequestData();
        ~PaymentAppRequestData();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = PaymentAppRequestDataPtr>
        PaymentAppRequestDataPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, PaymentAppRequestData>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                PaymentAppRequestData::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                PaymentAppRequestData::DataView, std::vector<uint8_t>>(
                input, output);
        }

        GURL origin;
        std::vector<::payments::mojom::PaymentMethodDataPtr> methodData;
        ::payments::mojom::PaymentItemPtr total;
        std::vector<::payments::mojom::PaymentDetailsModifierPtr> modifiers;
        std::string optionId;

    private:
        DISALLOW_COPY_AND_ASSIGN(PaymentAppRequestData);
    };

    template <typename StructPtrType>
    PaymentAppOptionPtr PaymentAppOption::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->name = mojo::internal::Clone(name);
        rv->icon = mojo::internal::Clone(icon);
        rv->id = mojo::internal::Clone(id);
        rv->enabled_methods = mojo::internal::Clone(enabled_methods);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, PaymentAppOption>::value>::type*>
    bool PaymentAppOption::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->name, other.name))
            return false;
        if (!mojo::internal::Equals(this->icon, other.icon))
            return false;
        if (!mojo::internal::Equals(this->id, other.id))
            return false;
        if (!mojo::internal::Equals(this->enabled_methods, other.enabled_methods))
            return false;
        return true;
    }
    template <typename StructPtrType>
    PaymentAppManifestPtr PaymentAppManifest::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->name = mojo::internal::Clone(name);
        rv->icon = mojo::internal::Clone(icon);
        rv->options = mojo::internal::Clone(options);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, PaymentAppManifest>::value>::type*>
    bool PaymentAppManifest::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->name, other.name))
            return false;
        if (!mojo::internal::Equals(this->icon, other.icon))
            return false;
        if (!mojo::internal::Equals(this->options, other.options))
            return false;
        return true;
    }
    template <typename StructPtrType>
    PaymentAppRequestDataPtr PaymentAppRequestData::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->origin = mojo::internal::Clone(origin);
        rv->methodData = mojo::internal::Clone(methodData);
        rv->total = mojo::internal::Clone(total);
        rv->modifiers = mojo::internal::Clone(modifiers);
        rv->optionId = mojo::internal::Clone(optionId);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, PaymentAppRequestData>::value>::type*>
    bool PaymentAppRequestData::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->origin, other.origin))
            return false;
        if (!mojo::internal::Equals(this->methodData, other.methodData))
            return false;
        if (!mojo::internal::Equals(this->total, other.total))
            return false;
        if (!mojo::internal::Equals(this->modifiers, other.modifiers))
            return false;
        if (!mojo::internal::Equals(this->optionId, other.optionId))
            return false;
        return true;
    }

} // namespace mojom
} // namespace payments

namespace mojo {

template <>
struct StructTraits<::payments::mojom::PaymentAppOption::DataView,
    ::payments::mojom::PaymentAppOptionPtr> {
    static bool IsNull(const ::payments::mojom::PaymentAppOptionPtr& input) { return !input; }
    static void SetToNull(::payments::mojom::PaymentAppOptionPtr* output) { output->reset(); }

    static const decltype(::payments::mojom::PaymentAppOption::name)& name(
        const ::payments::mojom::PaymentAppOptionPtr& input)
    {
        return input->name;
    }

    static const decltype(::payments::mojom::PaymentAppOption::icon)& icon(
        const ::payments::mojom::PaymentAppOptionPtr& input)
    {
        return input->icon;
    }

    static const decltype(::payments::mojom::PaymentAppOption::id)& id(
        const ::payments::mojom::PaymentAppOptionPtr& input)
    {
        return input->id;
    }

    static const decltype(::payments::mojom::PaymentAppOption::enabled_methods)& enabled_methods(
        const ::payments::mojom::PaymentAppOptionPtr& input)
    {
        return input->enabled_methods;
    }

    static bool Read(::payments::mojom::PaymentAppOption::DataView input, ::payments::mojom::PaymentAppOptionPtr* output);
};

template <>
struct StructTraits<::payments::mojom::PaymentAppManifest::DataView,
    ::payments::mojom::PaymentAppManifestPtr> {
    static bool IsNull(const ::payments::mojom::PaymentAppManifestPtr& input) { return !input; }
    static void SetToNull(::payments::mojom::PaymentAppManifestPtr* output) { output->reset(); }

    static const decltype(::payments::mojom::PaymentAppManifest::name)& name(
        const ::payments::mojom::PaymentAppManifestPtr& input)
    {
        return input->name;
    }

    static const decltype(::payments::mojom::PaymentAppManifest::icon)& icon(
        const ::payments::mojom::PaymentAppManifestPtr& input)
    {
        return input->icon;
    }

    static const decltype(::payments::mojom::PaymentAppManifest::options)& options(
        const ::payments::mojom::PaymentAppManifestPtr& input)
    {
        return input->options;
    }

    static bool Read(::payments::mojom::PaymentAppManifest::DataView input, ::payments::mojom::PaymentAppManifestPtr* output);
};

template <>
struct StructTraits<::payments::mojom::PaymentAppRequestData::DataView,
    ::payments::mojom::PaymentAppRequestDataPtr> {
    static bool IsNull(const ::payments::mojom::PaymentAppRequestDataPtr& input) { return !input; }
    static void SetToNull(::payments::mojom::PaymentAppRequestDataPtr* output) { output->reset(); }

    static const decltype(::payments::mojom::PaymentAppRequestData::origin)& origin(
        const ::payments::mojom::PaymentAppRequestDataPtr& input)
    {
        return input->origin;
    }

    static const decltype(::payments::mojom::PaymentAppRequestData::methodData)& methodData(
        const ::payments::mojom::PaymentAppRequestDataPtr& input)
    {
        return input->methodData;
    }

    static const decltype(::payments::mojom::PaymentAppRequestData::total)& total(
        const ::payments::mojom::PaymentAppRequestDataPtr& input)
    {
        return input->total;
    }

    static const decltype(::payments::mojom::PaymentAppRequestData::modifiers)& modifiers(
        const ::payments::mojom::PaymentAppRequestDataPtr& input)
    {
        return input->modifiers;
    }

    static const decltype(::payments::mojom::PaymentAppRequestData::optionId)& optionId(
        const ::payments::mojom::PaymentAppRequestDataPtr& input)
    {
        return input->optionId;
    }

    static bool Read(::payments::mojom::PaymentAppRequestData::DataView input, ::payments::mojom::PaymentAppRequestDataPtr* output);
};

} // namespace mojo

#endif // COMPONENTS_PAYMENTS_PAYMENT_APP_MOJOM_H_