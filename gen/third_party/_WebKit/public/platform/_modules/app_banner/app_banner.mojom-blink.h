// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_APP_BANNER_APP_BANNER_MOJOM_BLINK_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_APP_BANNER_APP_BANNER_MOJOM_BLINK_H_

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
#include "third_party/WebKit/public/platform/modules/app_banner/app_banner.mojom-shared.h"

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
        using AppBannerPromptReply = AppBannerPromptReply; // Alias for definition in the parent namespace.
        class AppBannerController;
        using AppBannerControllerPtr = mojo::InterfacePtr<AppBannerController>;
        using AppBannerControllerPtrInfo = mojo::InterfacePtrInfo<AppBannerController>;
        using ThreadSafeAppBannerControllerPtr = mojo::ThreadSafeInterfacePtr<AppBannerController>;
        using AppBannerControllerRequest = mojo::InterfaceRequest<AppBannerController>;
        using AppBannerControllerAssociatedPtr = mojo::AssociatedInterfacePtr<AppBannerController>;
        using ThreadSafeAppBannerControllerAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<AppBannerController>;
        using AppBannerControllerAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<AppBannerController>;
        using AppBannerControllerAssociatedRequest = mojo::AssociatedInterfaceRequest<AppBannerController>;

        class AppBannerEvent;
        using AppBannerEventPtr = mojo::InterfacePtr<AppBannerEvent>;
        using AppBannerEventPtrInfo = mojo::InterfacePtrInfo<AppBannerEvent>;
        using ThreadSafeAppBannerEventPtr = mojo::ThreadSafeInterfacePtr<AppBannerEvent>;
        using AppBannerEventRequest = mojo::InterfaceRequest<AppBannerEvent>;
        using AppBannerEventAssociatedPtr = mojo::AssociatedInterfacePtr<AppBannerEvent>;
        using ThreadSafeAppBannerEventAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<AppBannerEvent>;
        using AppBannerEventAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<AppBannerEvent>;
        using AppBannerEventAssociatedRequest = mojo::AssociatedInterfaceRequest<AppBannerEvent>;

        class AppBannerService;
        using AppBannerServicePtr = mojo::InterfacePtr<AppBannerService>;
        using AppBannerServicePtrInfo = mojo::InterfacePtrInfo<AppBannerService>;
        using ThreadSafeAppBannerServicePtr = mojo::ThreadSafeInterfacePtr<AppBannerService>;
        using AppBannerServiceRequest = mojo::InterfaceRequest<AppBannerService>;
        using AppBannerServiceAssociatedPtr = mojo::AssociatedInterfacePtr<AppBannerService>;
        using ThreadSafeAppBannerServiceAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<AppBannerService>;
        using AppBannerServiceAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<AppBannerService>;
        using AppBannerServiceAssociatedRequest = mojo::AssociatedInterfaceRequest<AppBannerService>;

        class AppBannerControllerProxy;

        template <typename ImplRefTraits>
        class AppBannerControllerStub;

        class AppBannerControllerRequestValidator;
        class AppBannerControllerResponseValidator;

        class BLINK_PLATFORM_EXPORT AppBannerController
            : public AppBannerControllerInterfaceBase {
        public:
            static const char Name_[];
            static constexpr uint32_t Version_ = 0;
            static constexpr bool PassesAssociatedKinds_ = false;
            static constexpr bool HasSyncMethods_ = false;

            using Proxy_ = AppBannerControllerProxy;

            template <typename ImplRefTraits>
            using Stub_ = AppBannerControllerStub<ImplRefTraits>;

            using RequestValidator_ = AppBannerControllerRequestValidator;
            using ResponseValidator_ = AppBannerControllerResponseValidator;
            enum MethodMinVersions : uint32_t {
                kBannerPromptRequestMinVersion = 0,
            };
            virtual ~AppBannerController() { }

            using BannerPromptRequestCallback = base::Callback<void(AppBannerPromptReply, const WTF::String&)>;
            virtual void BannerPromptRequest(AppBannerServicePtr service, AppBannerEventRequest event, const WTF::Vector<WTF::String>& platform, const BannerPromptRequestCallback& callback) = 0;
        };

        class AppBannerEventProxy;

        template <typename ImplRefTraits>
        class AppBannerEventStub;

        class AppBannerEventRequestValidator;

        class BLINK_PLATFORM_EXPORT AppBannerEvent
            : public AppBannerEventInterfaceBase {
        public:
            static const char Name_[];
            static constexpr uint32_t Version_ = 0;
            static constexpr bool PassesAssociatedKinds_ = false;
            static constexpr bool HasSyncMethods_ = false;

            using Proxy_ = AppBannerEventProxy;

            template <typename ImplRefTraits>
            using Stub_ = AppBannerEventStub<ImplRefTraits>;

            using RequestValidator_ = AppBannerEventRequestValidator;
            using ResponseValidator_ = mojo::PassThroughFilter;
            enum MethodMinVersions : uint32_t {
                kBannerAcceptedMinVersion = 0,
                kBannerDismissedMinVersion = 0,
            };
            virtual ~AppBannerEvent() { }

            virtual void BannerAccepted(const WTF::String& platform) = 0;

            virtual void BannerDismissed() = 0;
        };

        class AppBannerServiceProxy;

        template <typename ImplRefTraits>
        class AppBannerServiceStub;

        class AppBannerServiceRequestValidator;

        class BLINK_PLATFORM_EXPORT AppBannerService
            : public AppBannerServiceInterfaceBase {
        public:
            static const char Name_[];
            static constexpr uint32_t Version_ = 0;
            static constexpr bool PassesAssociatedKinds_ = false;
            static constexpr bool HasSyncMethods_ = false;

            using Proxy_ = AppBannerServiceProxy;

            template <typename ImplRefTraits>
            using Stub_ = AppBannerServiceStub<ImplRefTraits>;

            using RequestValidator_ = AppBannerServiceRequestValidator;
            using ResponseValidator_ = mojo::PassThroughFilter;
            enum MethodMinVersions : uint32_t {
                kDisplayAppBannerMinVersion = 0,
            };
            virtual ~AppBannerService() { }

            virtual void DisplayAppBanner() = 0;
        };

        class BLINK_PLATFORM_EXPORT AppBannerControllerProxy
            : public AppBannerController {
        public:
            explicit AppBannerControllerProxy(mojo::MessageReceiverWithResponder* receiver);
            void BannerPromptRequest(AppBannerServicePtr service, AppBannerEventRequest event, const WTF::Vector<WTF::String>& platform, const BannerPromptRequestCallback& callback) override;

            void set_group_controller(
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
            {
                group_controller_ = std::move(group_controller);
            }

        private:
            mojo::MessageReceiverWithResponder* receiver_;
            scoped_refptr<mojo::AssociatedGroupController> group_controller_;
        };

        class BLINK_PLATFORM_EXPORT AppBannerEventProxy
            : public AppBannerEvent {
        public:
            explicit AppBannerEventProxy(mojo::MessageReceiverWithResponder* receiver);
            void BannerAccepted(const WTF::String& platform) override;
            void BannerDismissed() override;

            void set_group_controller(
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
            {
                group_controller_ = std::move(group_controller);
            }

        private:
            mojo::MessageReceiverWithResponder* receiver_;
            scoped_refptr<mojo::AssociatedGroupController> group_controller_;
        };

        class BLINK_PLATFORM_EXPORT AppBannerServiceProxy
            : public AppBannerService {
        public:
            explicit AppBannerServiceProxy(mojo::MessageReceiverWithResponder* receiver);
            void DisplayAppBanner() override;

            void set_group_controller(
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
            {
                group_controller_ = std::move(group_controller);
            }

        private:
            mojo::MessageReceiverWithResponder* receiver_;
            scoped_refptr<mojo::AssociatedGroupController> group_controller_;
        };
        class BLINK_PLATFORM_EXPORT AppBannerControllerStubDispatch {
        public:
            static bool Accept(AppBannerController* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message);
            static bool AcceptWithResponder(AppBannerController* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder);
        };

        template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<AppBannerController>>
        class AppBannerControllerStub
            : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
        public:
            using ImplPointerType = typename ImplRefTraits::PointerType;

            AppBannerControllerStub() { }
            ~AppBannerControllerStub() override { }

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
                return AppBannerControllerStubDispatch::Accept(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
            }

            bool AcceptWithResponder(
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder) override
            {
                if (ImplRefTraits::IsNull(sink_))
                    return false;
                return AppBannerControllerStubDispatch::AcceptWithResponder(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                    responder);
            }

        private:
            ImplPointerType sink_;
            mojo::internal::SerializationContext serialization_context_;
        };
        class BLINK_PLATFORM_EXPORT AppBannerEventStubDispatch {
        public:
            static bool Accept(AppBannerEvent* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message);
            static bool AcceptWithResponder(AppBannerEvent* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder);
        };

        template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<AppBannerEvent>>
        class AppBannerEventStub
            : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
        public:
            using ImplPointerType = typename ImplRefTraits::PointerType;

            AppBannerEventStub() { }
            ~AppBannerEventStub() override { }

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
                return AppBannerEventStubDispatch::Accept(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
            }

            bool AcceptWithResponder(
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder) override
            {
                if (ImplRefTraits::IsNull(sink_))
                    return false;
                return AppBannerEventStubDispatch::AcceptWithResponder(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                    responder);
            }

        private:
            ImplPointerType sink_;
            mojo::internal::SerializationContext serialization_context_;
        };
        class BLINK_PLATFORM_EXPORT AppBannerServiceStubDispatch {
        public:
            static bool Accept(AppBannerService* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message);
            static bool AcceptWithResponder(AppBannerService* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder);
        };

        template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<AppBannerService>>
        class AppBannerServiceStub
            : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
        public:
            using ImplPointerType = typename ImplRefTraits::PointerType;

            AppBannerServiceStub() { }
            ~AppBannerServiceStub() override { }

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
                return AppBannerServiceStubDispatch::Accept(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
            }

            bool AcceptWithResponder(
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder) override
            {
                if (ImplRefTraits::IsNull(sink_))
                    return false;
                return AppBannerServiceStubDispatch::AcceptWithResponder(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                    responder);
            }

        private:
            ImplPointerType sink_;
            mojo::internal::SerializationContext serialization_context_;
        };
        class BLINK_PLATFORM_EXPORT AppBannerControllerRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };
        class BLINK_PLATFORM_EXPORT AppBannerEventRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };
        class BLINK_PLATFORM_EXPORT AppBannerServiceRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };
        class BLINK_PLATFORM_EXPORT AppBannerControllerResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };

    } // namespace blink
} // namespace mojom
} // namespace blink

namespace mojo {

} // namespace mojo

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_APP_BANNER_APP_BANNER_MOJOM_BLINK_H_