// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_CONNECTOR_MOJOM_H_
#define SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_CONNECTOR_MOJOM_H_

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
#include "services/service_manager/public/interfaces/connector.mojom-shared.h"
#include "services/service_manager/public/interfaces/interface_provider.mojom.h"
#include <string>
#include <vector>

namespace service_manager {
namespace mojom {
    extern const char kRootUserID[];
    extern const char kInheritUserID[];
    constexpr uint32_t kInvalidInstanceID = 0U;
    class PIDReceiver;
    using PIDReceiverPtr = mojo::InterfacePtr<PIDReceiver>;
    using PIDReceiverPtrInfo = mojo::InterfacePtrInfo<PIDReceiver>;
    using ThreadSafePIDReceiverPtr = mojo::ThreadSafeInterfacePtr<PIDReceiver>;
    using PIDReceiverRequest = mojo::InterfaceRequest<PIDReceiver>;
    using PIDReceiverAssociatedPtr = mojo::AssociatedInterfacePtr<PIDReceiver>;
    using ThreadSafePIDReceiverAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<PIDReceiver>;
    using PIDReceiverAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<PIDReceiver>;
    using PIDReceiverAssociatedRequest = mojo::AssociatedInterfaceRequest<PIDReceiver>;

    class Connector;
    using ConnectorPtr = mojo::InterfacePtr<Connector>;
    using ConnectorPtrInfo = mojo::InterfacePtrInfo<Connector>;
    using ThreadSafeConnectorPtr = mojo::ThreadSafeInterfacePtr<Connector>;
    using ConnectorRequest = mojo::InterfaceRequest<Connector>;
    using ConnectorAssociatedPtr = mojo::AssociatedInterfacePtr<Connector>;
    using ThreadSafeConnectorAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<Connector>;
    using ConnectorAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<Connector>;
    using ConnectorAssociatedRequest = mojo::AssociatedInterfaceRequest<Connector>;

    class Identity;
    using IdentityPtr = mojo::InlinedStructPtr<Identity>;

    class PIDReceiverProxy;

    template <typename ImplRefTraits>
    class PIDReceiverStub;

    class PIDReceiverRequestValidator;

    class PIDReceiver
        : public PIDReceiverInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = PIDReceiverProxy;

        template <typename ImplRefTraits>
        using Stub_ = PIDReceiverStub<ImplRefTraits>;

        using RequestValidator_ = PIDReceiverRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kSetPIDMinVersion = 0,
        };
        virtual ~PIDReceiver() { }

        virtual void SetPID(uint32_t pid) = 0;
    };

    class ConnectorProxy;

    template <typename ImplRefTraits>
    class ConnectorStub;

    class ConnectorRequestValidator;
    class ConnectorResponseValidator;

    class Connector
        : public ConnectorInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = ConnectorProxy;

        template <typename ImplRefTraits>
        using Stub_ = ConnectorStub<ImplRefTraits>;

        using RequestValidator_ = ConnectorRequestValidator;
        using ResponseValidator_ = ConnectorResponseValidator;
        enum MethodMinVersions : uint32_t {
            kStartServiceMinVersion = 0,
            kConnectMinVersion = 0,
            kBindInterfaceMinVersion = 0,
            kCloneMinVersion = 0,
        };
        virtual ~Connector() { }

        virtual void StartService(const ::service_manager::Identity& name, mojo::ScopedMessagePipeHandle service, PIDReceiverRequest pid_receiver_request) = 0;

        using ConnectCallback = base::Callback<void(ConnectResult, const std::string&)>;
        virtual void Connect(const ::service_manager::Identity& target, ::service_manager::mojom::InterfaceProviderRequest remote_interfaces, const ConnectCallback& callback) = 0;

        using BindInterfaceCallback = base::Callback<void(ConnectResult, const std::string&)>;
        virtual void BindInterface(const ::service_manager::Identity& target, const std::string& interface_name, mojo::ScopedMessagePipeHandle interface_pipe, const BindInterfaceCallback& callback) = 0;

        virtual void Clone(ConnectorRequest request) = 0;
    };

    class PIDReceiverProxy
        : public PIDReceiver {
    public:
        explicit PIDReceiverProxy(mojo::MessageReceiverWithResponder* receiver);
        void SetPID(uint32_t pid) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class ConnectorProxy
        : public Connector {
    public:
        explicit ConnectorProxy(mojo::MessageReceiverWithResponder* receiver);
        void StartService(const ::service_manager::Identity& name, mojo::ScopedMessagePipeHandle service, PIDReceiverRequest pid_receiver_request) override;
        void Connect(const ::service_manager::Identity& target, ::service_manager::mojom::InterfaceProviderRequest remote_interfaces, const ConnectCallback& callback) override;
        void BindInterface(const ::service_manager::Identity& target, const std::string& interface_name, mojo::ScopedMessagePipeHandle interface_pipe, const BindInterfaceCallback& callback) override;
        void Clone(ConnectorRequest request) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class PIDReceiverStubDispatch {
    public:
        static bool Accept(PIDReceiver* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(PIDReceiver* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<PIDReceiver>>
    class PIDReceiverStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        PIDReceiverStub() { }
        ~PIDReceiverStub() override { }

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
            return PIDReceiverStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return PIDReceiverStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class ConnectorStubDispatch {
    public:
        static bool Accept(Connector* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(Connector* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<Connector>>
    class ConnectorStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        ConnectorStub() { }
        ~ConnectorStub() override { }

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
            return ConnectorStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return ConnectorStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class PIDReceiverRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class ConnectorRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class ConnectorResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

    class Identity {
    public:
        using DataView = IdentityDataView;
        using Data_ = internal::Identity_Data;

        static IdentityPtr New();

        template <typename U>
        static IdentityPtr From(const U& u)
        {
            return mojo::TypeConverter<IdentityPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, Identity>::Convert(*this);
        }

        Identity();
        ~Identity();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = IdentityPtr>
        IdentityPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, Identity>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                Identity::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                Identity::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::string name;
        std::string user_id;
        std::string instance;
    };

    template <typename StructPtrType>
    IdentityPtr Identity::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->name = mojo::internal::Clone(name);
        rv->user_id = mojo::internal::Clone(user_id);
        rv->instance = mojo::internal::Clone(instance);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, Identity>::value>::type*>
    bool Identity::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->name, other.name))
            return false;
        if (!mojo::internal::Equals(this->user_id, other.user_id))
            return false;
        if (!mojo::internal::Equals(this->instance, other.instance))
            return false;
        return true;
    }

} // namespace mojom
} // namespace service_manager

namespace mojo {

template <>
struct StructTraits<::service_manager::mojom::Identity::DataView,
    ::service_manager::mojom::IdentityPtr> {
    static bool IsNull(const ::service_manager::mojom::IdentityPtr& input) { return !input; }
    static void SetToNull(::service_manager::mojom::IdentityPtr* output) { output->reset(); }

    static const decltype(::service_manager::mojom::Identity::name)& name(
        const ::service_manager::mojom::IdentityPtr& input)
    {
        return input->name;
    }

    static const decltype(::service_manager::mojom::Identity::user_id)& user_id(
        const ::service_manager::mojom::IdentityPtr& input)
    {
        return input->user_id;
    }

    static const decltype(::service_manager::mojom::Identity::instance)& instance(
        const ::service_manager::mojom::IdentityPtr& input)
    {
        return input->instance;
    }

    static bool Read(::service_manager::mojom::Identity::DataView input, ::service_manager::mojom::IdentityPtr* output);
};

} // namespace mojo

#endif // SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_CONNECTOR_MOJOM_H_