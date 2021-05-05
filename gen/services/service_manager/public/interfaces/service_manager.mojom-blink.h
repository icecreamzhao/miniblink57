// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_SERVICE_MANAGER_MOJOM_BLINK_H_
#define SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_SERVICE_MANAGER_MOJOM_BLINK_H_

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
#include "services/service_manager/public/interfaces/service_manager.mojom-shared.h"

#include "base/files/file.h"
#include "mojo/public/cpp/bindings/lib/wtf_hash_util.h"
#include "third_party/WebKit/Source/wtf/HashFunctions.h"
#include "third_party/WebKit/Source/wtf/Optional.h"
#include "third_party/WebKit/Source/wtf/text/WTFString.h"

namespace service_manager {
namespace mojom {
    namespace blink {
        class ServiceManagerListener;
        using ServiceManagerListenerPtr = mojo::InterfacePtr<ServiceManagerListener>;
        using ServiceManagerListenerPtrInfo = mojo::InterfacePtrInfo<ServiceManagerListener>;
        using ThreadSafeServiceManagerListenerPtr = mojo::ThreadSafeInterfacePtr<ServiceManagerListener>;
        using ServiceManagerListenerRequest = mojo::InterfaceRequest<ServiceManagerListener>;
        using ServiceManagerListenerAssociatedPtr = mojo::AssociatedInterfacePtr<ServiceManagerListener>;
        using ThreadSafeServiceManagerListenerAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<ServiceManagerListener>;
        using ServiceManagerListenerAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<ServiceManagerListener>;
        using ServiceManagerListenerAssociatedRequest = mojo::AssociatedInterfaceRequest<ServiceManagerListener>;

        class ServiceManager;
        using ServiceManagerPtr = mojo::InterfacePtr<ServiceManager>;
        using ServiceManagerPtrInfo = mojo::InterfacePtrInfo<ServiceManager>;
        using ThreadSafeServiceManagerPtr = mojo::ThreadSafeInterfacePtr<ServiceManager>;
        using ServiceManagerRequest = mojo::InterfaceRequest<ServiceManager>;
        using ServiceManagerAssociatedPtr = mojo::AssociatedInterfacePtr<ServiceManager>;
        using ThreadSafeServiceManagerAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<ServiceManager>;
        using ServiceManagerAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<ServiceManager>;
        using ServiceManagerAssociatedRequest = mojo::AssociatedInterfaceRequest<ServiceManager>;

        class RunningServiceInfo;
        using RunningServiceInfoPtr = mojo::StructPtr<RunningServiceInfo>;

        class ServiceManagerListenerProxy;

        template <typename ImplRefTraits>
        class ServiceManagerListenerStub;

        class ServiceManagerListenerRequestValidator;

        class ServiceManagerListener
            : public ServiceManagerListenerInterfaceBase {
        public:
            static const char Name_[];
            static constexpr uint32_t Version_ = 0;
            static constexpr bool PassesAssociatedKinds_ = false;
            static constexpr bool HasSyncMethods_ = false;

            using Proxy_ = ServiceManagerListenerProxy;

            template <typename ImplRefTraits>
            using Stub_ = ServiceManagerListenerStub<ImplRefTraits>;

            using RequestValidator_ = ServiceManagerListenerRequestValidator;
            using ResponseValidator_ = mojo::PassThroughFilter;
            enum MethodMinVersions : uint32_t {
                kOnInitMinVersion = 0,
                kOnServiceCreatedMinVersion = 0,
                kOnServiceStartedMinVersion = 0,
                kOnServiceFailedToStartMinVersion = 0,
                kOnServiceStoppedMinVersion = 0,
            };
            virtual ~ServiceManagerListener() { }

            virtual void OnInit(WTF::Vector<RunningServiceInfoPtr> running_services) = 0;

            virtual void OnServiceCreated(RunningServiceInfoPtr service) = 0;

            virtual void OnServiceStarted(::service_manager::mojom::blink::IdentityPtr identity, uint32_t pid) = 0;

            virtual void OnServiceFailedToStart(::service_manager::mojom::blink::IdentityPtr identity) = 0;

            virtual void OnServiceStopped(::service_manager::mojom::blink::IdentityPtr identity) = 0;
        };

        class ServiceManagerProxy;

        template <typename ImplRefTraits>
        class ServiceManagerStub;

        class ServiceManagerRequestValidator;

        class ServiceManager
            : public ServiceManagerInterfaceBase {
        public:
            static const char Name_[];
            static constexpr uint32_t Version_ = 0;
            static constexpr bool PassesAssociatedKinds_ = false;
            static constexpr bool HasSyncMethods_ = false;

            using Proxy_ = ServiceManagerProxy;

            template <typename ImplRefTraits>
            using Stub_ = ServiceManagerStub<ImplRefTraits>;

            using RequestValidator_ = ServiceManagerRequestValidator;
            using ResponseValidator_ = mojo::PassThroughFilter;
            enum MethodMinVersions : uint32_t {
                kAddListenerMinVersion = 0,
            };
            virtual ~ServiceManager() { }

            virtual void AddListener(ServiceManagerListenerPtr listener) = 0;
        };

        class ServiceManagerListenerProxy
            : public ServiceManagerListener {
        public:
            explicit ServiceManagerListenerProxy(mojo::MessageReceiverWithResponder* receiver);
            void OnInit(WTF::Vector<RunningServiceInfoPtr> running_services) override;
            void OnServiceCreated(RunningServiceInfoPtr service) override;
            void OnServiceStarted(::service_manager::mojom::blink::IdentityPtr identity, uint32_t pid) override;
            void OnServiceFailedToStart(::service_manager::mojom::blink::IdentityPtr identity) override;
            void OnServiceStopped(::service_manager::mojom::blink::IdentityPtr identity) override;

            void set_group_controller(
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
            {
                group_controller_ = std::move(group_controller);
            }

        private:
            mojo::MessageReceiverWithResponder* receiver_;
            scoped_refptr<mojo::AssociatedGroupController> group_controller_;
        };

        class ServiceManagerProxy
            : public ServiceManager {
        public:
            explicit ServiceManagerProxy(mojo::MessageReceiverWithResponder* receiver);
            void AddListener(ServiceManagerListenerPtr listener) override;

            void set_group_controller(
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
            {
                group_controller_ = std::move(group_controller);
            }

        private:
            mojo::MessageReceiverWithResponder* receiver_;
            scoped_refptr<mojo::AssociatedGroupController> group_controller_;
        };
        class ServiceManagerListenerStubDispatch {
        public:
            static bool Accept(ServiceManagerListener* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message);
            static bool AcceptWithResponder(ServiceManagerListener* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder);
        };

        template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<ServiceManagerListener>>
        class ServiceManagerListenerStub
            : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
        public:
            using ImplPointerType = typename ImplRefTraits::PointerType;

            ServiceManagerListenerStub() { }
            ~ServiceManagerListenerStub() override { }

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
                return ServiceManagerListenerStubDispatch::Accept(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
            }

            bool AcceptWithResponder(
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder) override
            {
                if (ImplRefTraits::IsNull(sink_))
                    return false;
                return ServiceManagerListenerStubDispatch::AcceptWithResponder(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                    responder);
            }

        private:
            ImplPointerType sink_;
            mojo::internal::SerializationContext serialization_context_;
        };
        class ServiceManagerStubDispatch {
        public:
            static bool Accept(ServiceManager* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message);
            static bool AcceptWithResponder(ServiceManager* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder);
        };

        template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<ServiceManager>>
        class ServiceManagerStub
            : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
        public:
            using ImplPointerType = typename ImplRefTraits::PointerType;

            ServiceManagerStub() { }
            ~ServiceManagerStub() override { }

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
                return ServiceManagerStubDispatch::Accept(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
            }

            bool AcceptWithResponder(
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder) override
            {
                if (ImplRefTraits::IsNull(sink_))
                    return false;
                return ServiceManagerStubDispatch::AcceptWithResponder(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                    responder);
            }

        private:
            ImplPointerType sink_;
            mojo::internal::SerializationContext serialization_context_;
        };
        class ServiceManagerListenerRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };
        class ServiceManagerRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };

        class RunningServiceInfo {
        public:
            using DataView = RunningServiceInfoDataView;
            using Data_ = internal::RunningServiceInfo_Data;

            static RunningServiceInfoPtr New();

            template <typename U>
            static RunningServiceInfoPtr From(const U& u)
            {
                return mojo::TypeConverter<RunningServiceInfoPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, RunningServiceInfo>::Convert(*this);
            }

            RunningServiceInfo();
            ~RunningServiceInfo();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = RunningServiceInfoPtr>
            RunningServiceInfoPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, RunningServiceInfo>::value>::type* = nullptr>
            bool Equals(const T& other) const;
            size_t Hash(size_t seed) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    RunningServiceInfo::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    RunningServiceInfo::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            uint32_t id;
            ::service_manager::mojom::blink::IdentityPtr identity;
            uint32_t pid;

        private:
            DISALLOW_COPY_AND_ASSIGN(RunningServiceInfo);
        };

        template <typename StructPtrType>
        RunningServiceInfoPtr RunningServiceInfo::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->id = mojo::internal::Clone(id);
            rv->identity = mojo::internal::Clone(identity);
            rv->pid = mojo::internal::Clone(pid);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, RunningServiceInfo>::value>::type*>
        bool RunningServiceInfo::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->id, other.id))
                return false;
            if (!mojo::internal::Equals(this->identity, other.identity))
                return false;
            if (!mojo::internal::Equals(this->pid, other.pid))
                return false;
            return true;
        }

    } // namespace blink
} // namespace mojom
} // namespace service_manager

namespace mojo {

template <>
struct StructTraits<::service_manager::mojom::blink::RunningServiceInfo::DataView,
    ::service_manager::mojom::blink::RunningServiceInfoPtr> {
    static bool IsNull(const ::service_manager::mojom::blink::RunningServiceInfoPtr& input) { return !input; }
    static void SetToNull(::service_manager::mojom::blink::RunningServiceInfoPtr* output) { output->reset(); }

    static decltype(::service_manager::mojom::blink::RunningServiceInfo::id) id(
        const ::service_manager::mojom::blink::RunningServiceInfoPtr& input)
    {
        return input->id;
    }

    static const decltype(::service_manager::mojom::blink::RunningServiceInfo::identity)& identity(
        const ::service_manager::mojom::blink::RunningServiceInfoPtr& input)
    {
        return input->identity;
    }

    static decltype(::service_manager::mojom::blink::RunningServiceInfo::pid) pid(
        const ::service_manager::mojom::blink::RunningServiceInfoPtr& input)
    {
        return input->pid;
    }

    static bool Read(::service_manager::mojom::blink::RunningServiceInfo::DataView input, ::service_manager::mojom::blink::RunningServiceInfoPtr* output);
};

} // namespace mojo

#endif // SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_SERVICE_MANAGER_MOJOM_BLINK_H_