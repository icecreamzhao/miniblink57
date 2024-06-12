// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_SERVICE_CONTROL_MOJOM_BLINK_H_
#define SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_SERVICE_CONTROL_MOJOM_BLINK_H_

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
#include "services/service_manager/public/interfaces/service_control.mojom-shared.h"

#include "base/files/file.h"
#include "mojo/public/cpp/bindings/lib/wtf_hash_util.h"
#include "third_party/WebKit/Source/wtf/HashFunctions.h"
#include "third_party/WebKit/Source/wtf/Optional.h"
#include "third_party/WebKit/Source/wtf/text/WTFString.h"

namespace service_manager {
namespace mojom {
    namespace blink {
        class ServiceControl;
        using ServiceControlPtr = mojo::InterfacePtr<ServiceControl>;
        using ServiceControlPtrInfo = mojo::InterfacePtrInfo<ServiceControl>;
        using ThreadSafeServiceControlPtr = mojo::ThreadSafeInterfacePtr<ServiceControl>;
        using ServiceControlRequest = mojo::InterfaceRequest<ServiceControl>;
        using ServiceControlAssociatedPtr = mojo::AssociatedInterfacePtr<ServiceControl>;
        using ThreadSafeServiceControlAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<ServiceControl>;
        using ServiceControlAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<ServiceControl>;
        using ServiceControlAssociatedRequest = mojo::AssociatedInterfaceRequest<ServiceControl>;

        class ServiceControlProxy;

        template <typename ImplRefTraits>
        class ServiceControlStub;

        class ServiceControlRequestValidator;

        class ServiceControl
            : public ServiceControlInterfaceBase {
        public:
            static const char Name_[];
            static constexpr uint32_t Version_ = 0;
            static constexpr bool PassesAssociatedKinds_ = false;
            static constexpr bool HasSyncMethods_ = false;

            using Proxy_ = ServiceControlProxy;

            template <typename ImplRefTraits>
            using Stub_ = ServiceControlStub<ImplRefTraits>;

            using RequestValidator_ = ServiceControlRequestValidator;
            using ResponseValidator_ = mojo::PassThroughFilter;
            enum MethodMinVersions : uint32_t {
                kRequestQuitMinVersion = 0,
            };
            virtual ~ServiceControl() { }

            virtual void RequestQuit() = 0;
        };

        class ServiceControlProxy
            : public ServiceControl {
        public:
            explicit ServiceControlProxy(mojo::MessageReceiverWithResponder* receiver);
            void RequestQuit() override;

            void set_group_controller(
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
            {
                group_controller_ = std::move(group_controller);
            }

        private:
            mojo::MessageReceiverWithResponder* receiver_;
            scoped_refptr<mojo::AssociatedGroupController> group_controller_;
        };
        class ServiceControlStubDispatch {
        public:
            static bool Accept(ServiceControl* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message);
            static bool AcceptWithResponder(ServiceControl* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder);
        };

        template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<ServiceControl>>
        class ServiceControlStub
            : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
        public:
            using ImplPointerType = typename ImplRefTraits::PointerType;

            ServiceControlStub() { }
            ~ServiceControlStub() override { }

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
                return ServiceControlStubDispatch::Accept(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
            }

            bool AcceptWithResponder(
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder) override
            {
                if (ImplRefTraits::IsNull(sink_))
                    return false;
                return ServiceControlStubDispatch::AcceptWithResponder(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                    responder);
            }

        private:
            ImplPointerType sink_;
            mojo::internal::SerializationContext serialization_context_;
        };
        class ServiceControlRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };

    } // namespace blink
} // namespace mojom
} // namespace service_manager

namespace mojo {

} // namespace mojo

#endif // SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_SERVICE_CONTROL_MOJOM_BLINK_H_