// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_INTERFACE_PROVIDER_MOJOM_BLINK_H_
#define SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_INTERFACE_PROVIDER_MOJOM_BLINK_H_

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
#include "services/service_manager/public/interfaces/interface_provider.mojom-shared.h"

#include "base/files/file.h"
#include "mojo/public/cpp/bindings/lib/wtf_hash_util.h"
#include "third_party/WebKit/Source/wtf/HashFunctions.h"
#include "third_party/WebKit/Source/wtf/Optional.h"
#include "third_party/WebKit/Source/wtf/text/WTFString.h"

namespace service_manager {
namespace mojom {
    namespace blink {
        class InterfaceProvider;
        using InterfaceProviderPtr = mojo::InterfacePtr<InterfaceProvider>;
        using InterfaceProviderPtrInfo = mojo::InterfacePtrInfo<InterfaceProvider>;
        using ThreadSafeInterfaceProviderPtr = mojo::ThreadSafeInterfacePtr<InterfaceProvider>;
        using InterfaceProviderRequest = mojo::InterfaceRequest<InterfaceProvider>;
        using InterfaceProviderAssociatedPtr = mojo::AssociatedInterfacePtr<InterfaceProvider>;
        using ThreadSafeInterfaceProviderAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<InterfaceProvider>;
        using InterfaceProviderAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<InterfaceProvider>;
        using InterfaceProviderAssociatedRequest = mojo::AssociatedInterfaceRequest<InterfaceProvider>;

        class InterfaceProviderProxy;

        template <typename ImplRefTraits>
        class InterfaceProviderStub;

        class InterfaceProviderRequestValidator;

        class InterfaceProvider
            : public InterfaceProviderInterfaceBase {
        public:
            static const char Name_[];
            static constexpr uint32_t Version_ = 0;
            static constexpr bool PassesAssociatedKinds_ = false;
            static constexpr bool HasSyncMethods_ = false;

            using Proxy_ = InterfaceProviderProxy;

            template <typename ImplRefTraits>
            using Stub_ = InterfaceProviderStub<ImplRefTraits>;

            using RequestValidator_ = InterfaceProviderRequestValidator;
            using ResponseValidator_ = mojo::PassThroughFilter;
            enum MethodMinVersions : uint32_t {
                kGetInterfaceMinVersion = 0,
            };
            virtual ~InterfaceProvider() { }

            virtual void GetInterface(const WTF::String& interface_name, mojo::ScopedMessagePipeHandle pipe) = 0;
        };

        class InterfaceProviderProxy
            : public InterfaceProvider {
        public:
            explicit InterfaceProviderProxy(mojo::MessageReceiverWithResponder* receiver);
            void GetInterface(const WTF::String& interface_name, mojo::ScopedMessagePipeHandle pipe) override;

            void set_group_controller(
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
            {
                group_controller_ = std::move(group_controller);
            }

        private:
            mojo::MessageReceiverWithResponder* receiver_;
            scoped_refptr<mojo::AssociatedGroupController> group_controller_;
        };
        class InterfaceProviderStubDispatch {
        public:
            static bool Accept(InterfaceProvider* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message);
            static bool AcceptWithResponder(InterfaceProvider* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder);
        };

        template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<InterfaceProvider>>
        class InterfaceProviderStub
            : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
        public:
            using ImplPointerType = typename ImplRefTraits::PointerType;

            InterfaceProviderStub() { }
            ~InterfaceProviderStub() override { }

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
                return InterfaceProviderStubDispatch::Accept(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
            }

            bool AcceptWithResponder(
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder) override
            {
                if (ImplRefTraits::IsNull(sink_))
                    return false;
                return InterfaceProviderStubDispatch::AcceptWithResponder(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                    responder);
            }

        private:
            ImplPointerType sink_;
            mojo::internal::SerializationContext serialization_context_;
        };
        class InterfaceProviderRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };

    } // namespace blink
} // namespace mojom
} // namespace service_manager

namespace mojo {

} // namespace mojo

#endif // SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_INTERFACE_PROVIDER_MOJOM_BLINK_H_