// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_BROADCASTCHANNEL_BROADCAST_CHANNEL_MOJOM_BLINK_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_BROADCASTCHANNEL_BROADCAST_CHANNEL_MOJOM_BLINK_H_

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
#include "third_party/WebKit/public/platform/modules/broadcastchannel/broadcast_channel.mojom-shared.h"
#include "url/mojo/origin.mojom-blink.h"

#include "base/files/file.h"
#include "mojo/public/cpp/bindings/lib/wtf_hash_util.h"
#include "third_party/WebKit/Source/platform/weborigin/KURL.h"
#include "third_party/WebKit/Source/platform/weborigin/SecurityOrigin.h"
#include "third_party/WebKit/Source/wtf/HashFunctions.h"
#include "third_party/WebKit/Source/wtf/Optional.h"
#include "third_party/WebKit/Source/wtf/text/WTFString.h"
#include "third_party/WebKit/public/platform/WebCommon.h"
#include "third_party/WebKit/public/platform/WebReferrerPolicy.h"
#include "third_party/WebKit/public/platform/WebSize.h"
#include "third_party/WebKit/public/web/WebConsoleMessage.h"
#include "third_party/WebKit/public/web/WebWindowFeatures.h"

namespace blink {
namespace mojom {
    namespace blink {
        class BroadcastChannelClient;
        using BroadcastChannelClientPtr = mojo::InterfacePtr<BroadcastChannelClient>;
        using BroadcastChannelClientPtrInfo = mojo::InterfacePtrInfo<BroadcastChannelClient>;
        using ThreadSafeBroadcastChannelClientPtr = mojo::ThreadSafeInterfacePtr<BroadcastChannelClient>;
        using BroadcastChannelClientRequest = mojo::InterfaceRequest<BroadcastChannelClient>;
        using BroadcastChannelClientAssociatedPtr = mojo::AssociatedInterfacePtr<BroadcastChannelClient>;
        using ThreadSafeBroadcastChannelClientAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<BroadcastChannelClient>;
        using BroadcastChannelClientAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<BroadcastChannelClient>;
        using BroadcastChannelClientAssociatedRequest = mojo::AssociatedInterfaceRequest<BroadcastChannelClient>;

        class BroadcastChannelProvider;
        using BroadcastChannelProviderPtr = mojo::InterfacePtr<BroadcastChannelProvider>;
        using BroadcastChannelProviderPtrInfo = mojo::InterfacePtrInfo<BroadcastChannelProvider>;
        using ThreadSafeBroadcastChannelProviderPtr = mojo::ThreadSafeInterfacePtr<BroadcastChannelProvider>;
        using BroadcastChannelProviderRequest = mojo::InterfaceRequest<BroadcastChannelProvider>;
        using BroadcastChannelProviderAssociatedPtr = mojo::AssociatedInterfacePtr<BroadcastChannelProvider>;
        using ThreadSafeBroadcastChannelProviderAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<BroadcastChannelProvider>;
        using BroadcastChannelProviderAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<BroadcastChannelProvider>;
        using BroadcastChannelProviderAssociatedRequest = mojo::AssociatedInterfaceRequest<BroadcastChannelProvider>;

        class BroadcastChannelClientProxy;

        template <typename ImplRefTraits>
        class BroadcastChannelClientStub;

        class BroadcastChannelClientRequestValidator;

        class BLINK_PLATFORM_EXPORT BroadcastChannelClient
            : public BroadcastChannelClientInterfaceBase {
        public:
            static const char Name_[];
            static constexpr uint32_t Version_ = 0;
            static constexpr bool PassesAssociatedKinds_ = false;
            static constexpr bool HasSyncMethods_ = false;

            using Proxy_ = BroadcastChannelClientProxy;

            template <typename ImplRefTraits>
            using Stub_ = BroadcastChannelClientStub<ImplRefTraits>;

            using RequestValidator_ = BroadcastChannelClientRequestValidator;
            using ResponseValidator_ = mojo::PassThroughFilter;
            enum MethodMinVersions : uint32_t {
                kOnMessageMinVersion = 0,
            };
            virtual ~BroadcastChannelClient() { }

            virtual void OnMessage(const WTF::Vector<uint8_t>& message) = 0;
        };

        class BroadcastChannelProviderProxy;

        template <typename ImplRefTraits>
        class BroadcastChannelProviderStub;

        class BroadcastChannelProviderRequestValidator;

        class BLINK_PLATFORM_EXPORT BroadcastChannelProvider
            : public BroadcastChannelProviderInterfaceBase {
        public:
            static const char Name_[];
            static constexpr uint32_t Version_ = 0;
            static constexpr bool PassesAssociatedKinds_ = true;
            static constexpr bool HasSyncMethods_ = false;

            using Proxy_ = BroadcastChannelProviderProxy;

            template <typename ImplRefTraits>
            using Stub_ = BroadcastChannelProviderStub<ImplRefTraits>;

            using RequestValidator_ = BroadcastChannelProviderRequestValidator;
            using ResponseValidator_ = mojo::PassThroughFilter;
            enum MethodMinVersions : uint32_t {
                kConnectToChannelMinVersion = 0,
            };
            virtual ~BroadcastChannelProvider() { }

            virtual void ConnectToChannel(const RefPtr<::blink::SecurityOrigin>& origin, const WTF::String& name, BroadcastChannelClientAssociatedPtrInfo receiver, BroadcastChannelClientAssociatedRequest sender) = 0;
        };

        class BLINK_PLATFORM_EXPORT BroadcastChannelClientProxy
            : public BroadcastChannelClient {
        public:
            explicit BroadcastChannelClientProxy(mojo::MessageReceiverWithResponder* receiver);
            void OnMessage(const WTF::Vector<uint8_t>& message) override;

            void set_group_controller(
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
            {
                group_controller_ = std::move(group_controller);
            }

        private:
            mojo::MessageReceiverWithResponder* receiver_;
            scoped_refptr<mojo::AssociatedGroupController> group_controller_;
        };

        class BLINK_PLATFORM_EXPORT BroadcastChannelProviderProxy
            : public BroadcastChannelProvider {
        public:
            explicit BroadcastChannelProviderProxy(mojo::MessageReceiverWithResponder* receiver);
            void ConnectToChannel(const RefPtr<::blink::SecurityOrigin>& origin, const WTF::String& name, BroadcastChannelClientAssociatedPtrInfo receiver, BroadcastChannelClientAssociatedRequest sender) override;

            void set_group_controller(
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
            {
                group_controller_ = std::move(group_controller);
            }

        private:
            mojo::MessageReceiverWithResponder* receiver_;
            scoped_refptr<mojo::AssociatedGroupController> group_controller_;
        };
        class BLINK_PLATFORM_EXPORT BroadcastChannelClientStubDispatch {
        public:
            static bool Accept(BroadcastChannelClient* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message);
            static bool AcceptWithResponder(BroadcastChannelClient* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder);
        };

        template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<BroadcastChannelClient>>
        class BroadcastChannelClientStub
            : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
        public:
            using ImplPointerType = typename ImplRefTraits::PointerType;

            BroadcastChannelClientStub() { }
            ~BroadcastChannelClientStub() override { }

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
                return BroadcastChannelClientStubDispatch::Accept(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
            }

            bool AcceptWithResponder(
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder) override
            {
                if (ImplRefTraits::IsNull(sink_))
                    return false;
                return BroadcastChannelClientStubDispatch::AcceptWithResponder(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                    responder);
            }

        private:
            ImplPointerType sink_;
            mojo::internal::SerializationContext serialization_context_;
        };
        class BLINK_PLATFORM_EXPORT BroadcastChannelProviderStubDispatch {
        public:
            static bool Accept(BroadcastChannelProvider* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message);
            static bool AcceptWithResponder(BroadcastChannelProvider* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder);
        };

        template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<BroadcastChannelProvider>>
        class BroadcastChannelProviderStub
            : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
        public:
            using ImplPointerType = typename ImplRefTraits::PointerType;

            BroadcastChannelProviderStub() { }
            ~BroadcastChannelProviderStub() override { }

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
                return BroadcastChannelProviderStubDispatch::Accept(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
            }

            bool AcceptWithResponder(
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder) override
            {
                if (ImplRefTraits::IsNull(sink_))
                    return false;
                return BroadcastChannelProviderStubDispatch::AcceptWithResponder(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                    responder);
            }

        private:
            ImplPointerType sink_;
            mojo::internal::SerializationContext serialization_context_;
        };
        class BLINK_PLATFORM_EXPORT BroadcastChannelClientRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };
        class BLINK_PLATFORM_EXPORT BroadcastChannelProviderRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };

    } // namespace blink
} // namespace mojom
} // namespace blink

namespace mojo {

} // namespace mojo

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_BROADCASTCHANNEL_BROADCAST_CHANNEL_MOJOM_BLINK_H_