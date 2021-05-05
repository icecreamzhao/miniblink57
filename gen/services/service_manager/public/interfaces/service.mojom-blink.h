// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_SERVICE_MOJOM_BLINK_H_
#define SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_SERVICE_MOJOM_BLINK_H_

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
#include "services/service_manager/public/interfaces/connector.mojom-blink.h"
#include "services/service_manager/public/interfaces/interface_provider.mojom-blink.h"
#include "services/service_manager/public/interfaces/interface_provider_spec.mojom-blink.h"
#include "services/service_manager/public/interfaces/service.mojom-shared.h"
#include "services/service_manager/public/interfaces/service_control.mojom-blink.h"

#include "base/files/file.h"
#include "mojo/public/cpp/bindings/lib/wtf_hash_util.h"
#include "third_party/WebKit/Source/wtf/HashFunctions.h"
#include "third_party/WebKit/Source/wtf/Optional.h"
#include "third_party/WebKit/Source/wtf/text/WTFString.h"

namespace service_manager {
namespace mojom {
    namespace blink {
        class Service;
        using ServicePtr = mojo::InterfacePtr<Service>;
        using ServicePtrInfo = mojo::InterfacePtrInfo<Service>;
        using ThreadSafeServicePtr = mojo::ThreadSafeInterfacePtr<Service>;
        using ServiceRequest = mojo::InterfaceRequest<Service>;
        using ServiceAssociatedPtr = mojo::AssociatedInterfacePtr<Service>;
        using ThreadSafeServiceAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<Service>;
        using ServiceAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<Service>;
        using ServiceAssociatedRequest = mojo::AssociatedInterfaceRequest<Service>;

        class ServiceInfo;
        using ServiceInfoPtr = mojo::StructPtr<ServiceInfo>;

        class ServiceProxy;

        template <typename ImplRefTraits>
        class ServiceStub;

        class ServiceRequestValidator;
        class ServiceResponseValidator;

        class Service
            : public ServiceInterfaceBase {
        public:
            static const char Name_[];
            static constexpr uint32_t Version_ = 0;
            static constexpr bool PassesAssociatedKinds_ = true;
            static constexpr bool HasSyncMethods_ = false;

            using Proxy_ = ServiceProxy;

            template <typename ImplRefTraits>
            using Stub_ = ServiceStub<ImplRefTraits>;

            using RequestValidator_ = ServiceRequestValidator;
            using ResponseValidator_ = ServiceResponseValidator;
            enum MethodMinVersions : uint32_t {
                kOnStartMinVersion = 0,
                kOnConnectMinVersion = 0,
                kOnBindInterfaceMinVersion = 0,
            };
            virtual ~Service() { }

            using OnStartCallback = base::Callback<void(::service_manager::mojom::blink::ConnectorRequest, ::service_manager::mojom::blink::ServiceControlAssociatedRequest)>;
            virtual void OnStart(ServiceInfoPtr info, const OnStartCallback& callback) = 0;

            using OnConnectCallback = base::Callback<void()>;
            virtual void OnConnect(ServiceInfoPtr source_info, ::service_manager::mojom::blink::InterfaceProviderRequest interfaces, const OnConnectCallback& callback) = 0;

            using OnBindInterfaceCallback = base::Callback<void()>;
            virtual void OnBindInterface(ServiceInfoPtr source_info, const WTF::String& interface_name, mojo::ScopedMessagePipeHandle interface_pipe, const OnBindInterfaceCallback& callback) = 0;
        };

        class ServiceProxy
            : public Service {
        public:
            explicit ServiceProxy(mojo::MessageReceiverWithResponder* receiver);
            void OnStart(ServiceInfoPtr info, const OnStartCallback& callback) override;
            void OnConnect(ServiceInfoPtr source_info, ::service_manager::mojom::blink::InterfaceProviderRequest interfaces, const OnConnectCallback& callback) override;
            void OnBindInterface(ServiceInfoPtr source_info, const WTF::String& interface_name, mojo::ScopedMessagePipeHandle interface_pipe, const OnBindInterfaceCallback& callback) override;

            void set_group_controller(
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
            {
                group_controller_ = std::move(group_controller);
            }

        private:
            mojo::MessageReceiverWithResponder* receiver_;
            scoped_refptr<mojo::AssociatedGroupController> group_controller_;
        };
        class ServiceStubDispatch {
        public:
            static bool Accept(Service* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message);
            static bool AcceptWithResponder(Service* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder);
        };

        template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<Service>>
        class ServiceStub
            : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
        public:
            using ImplPointerType = typename ImplRefTraits::PointerType;

            ServiceStub() { }
            ~ServiceStub() override { }

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
                return ServiceStubDispatch::Accept(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
            }

            bool AcceptWithResponder(
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder) override
            {
                if (ImplRefTraits::IsNull(sink_))
                    return false;
                return ServiceStubDispatch::AcceptWithResponder(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                    responder);
            }

        private:
            ImplPointerType sink_;
            mojo::internal::SerializationContext serialization_context_;
        };
        class ServiceRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };
        class ServiceResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };

        class ServiceInfo {
        public:
            using DataView = ServiceInfoDataView;
            using Data_ = internal::ServiceInfo_Data;

            static ServiceInfoPtr New();

            template <typename U>
            static ServiceInfoPtr From(const U& u)
            {
                return mojo::TypeConverter<ServiceInfoPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, ServiceInfo>::Convert(*this);
            }

            ServiceInfo();
            ~ServiceInfo();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = ServiceInfoPtr>
            ServiceInfoPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, ServiceInfo>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    ServiceInfo::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    ServiceInfo::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            ::service_manager::mojom::blink::IdentityPtr identity;
            WTF::HashMap<WTF::String, ::service_manager::mojom::blink::InterfaceProviderSpecPtr> interface_provider_specs;

        private:
            DISALLOW_COPY_AND_ASSIGN(ServiceInfo);
        };

        template <typename StructPtrType>
        ServiceInfoPtr ServiceInfo::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->identity = mojo::internal::Clone(identity);
            rv->interface_provider_specs = mojo::internal::Clone(interface_provider_specs);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, ServiceInfo>::value>::type*>
        bool ServiceInfo::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->identity, other.identity))
                return false;
            if (!mojo::internal::Equals(this->interface_provider_specs, other.interface_provider_specs))
                return false;
            return true;
        }

    } // namespace blink
} // namespace mojom
} // namespace service_manager

namespace mojo {

template <>
struct StructTraits<::service_manager::mojom::blink::ServiceInfo::DataView,
    ::service_manager::mojom::blink::ServiceInfoPtr> {
    static bool IsNull(const ::service_manager::mojom::blink::ServiceInfoPtr& input) { return !input; }
    static void SetToNull(::service_manager::mojom::blink::ServiceInfoPtr* output) { output->reset(); }

    static const decltype(::service_manager::mojom::blink::ServiceInfo::identity)& identity(
        const ::service_manager::mojom::blink::ServiceInfoPtr& input)
    {
        return input->identity;
    }

    static const decltype(::service_manager::mojom::blink::ServiceInfo::interface_provider_specs)& interface_provider_specs(
        const ::service_manager::mojom::blink::ServiceInfoPtr& input)
    {
        return input->interface_provider_specs;
    }

    static bool Read(::service_manager::mojom::blink::ServiceInfo::DataView input, ::service_manager::mojom::blink::ServiceInfoPtr* output);
};

} // namespace mojo

#endif // SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_SERVICE_MOJOM_BLINK_H_