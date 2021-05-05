// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_NOTIFICATIONS_NOTIFICATION_SERVICE_MOJOM_BLINK_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_NOTIFICATIONS_NOTIFICATION_SERVICE_MOJOM_BLINK_H_

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
#include "third_party/WebKit/public/platform/modules/notifications/notification_service.mojom-shared.h"
#include "third_party/WebKit/public/platform/modules/permissions/permission_status.mojom-blink.h"

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
        class NotificationService;
        using NotificationServicePtr = mojo::InterfacePtr<NotificationService>;
        using NotificationServicePtrInfo = mojo::InterfacePtrInfo<NotificationService>;
        using ThreadSafeNotificationServicePtr = mojo::ThreadSafeInterfacePtr<NotificationService>;
        using NotificationServiceRequest = mojo::InterfaceRequest<NotificationService>;
        using NotificationServiceAssociatedPtr = mojo::AssociatedInterfacePtr<NotificationService>;
        using ThreadSafeNotificationServiceAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<NotificationService>;
        using NotificationServiceAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<NotificationService>;
        using NotificationServiceAssociatedRequest = mojo::AssociatedInterfaceRequest<NotificationService>;

        class NotificationServiceProxy;

        template <typename ImplRefTraits>
        class NotificationServiceStub;

        class NotificationServiceRequestValidator;
        class NotificationServiceResponseValidator;

        class BLINK_PLATFORM_EXPORT NotificationService
            : public NotificationServiceInterfaceBase {
        public:
            static const char Name_[];
            static constexpr uint32_t Version_ = 0;
            static constexpr bool PassesAssociatedKinds_ = false;
            static constexpr bool HasSyncMethods_ = true;

            using Proxy_ = NotificationServiceProxy;

            template <typename ImplRefTraits>
            using Stub_ = NotificationServiceStub<ImplRefTraits>;

            using RequestValidator_ = NotificationServiceRequestValidator;
            using ResponseValidator_ = NotificationServiceResponseValidator;
            enum MethodMinVersions : uint32_t {
                kGetPermissionStatusMinVersion = 0,
            };
            virtual ~NotificationService() { }

            // Sync method. This signature is used by the client side; the service side
            // should implement the signature with callback below.
            virtual bool GetPermissionStatus(const WTF::String& origin, ::blink::mojom::blink::PermissionStatus* status);

            using GetPermissionStatusCallback = base::Callback<void(::blink::mojom::blink::PermissionStatus)>;
            virtual void GetPermissionStatus(const WTF::String& origin, const GetPermissionStatusCallback& callback) = 0;
        };

        class BLINK_PLATFORM_EXPORT NotificationServiceProxy
            : public NotificationService {
        public:
            explicit NotificationServiceProxy(mojo::MessageReceiverWithResponder* receiver);
            bool GetPermissionStatus(const WTF::String& origin, ::blink::mojom::blink::PermissionStatus* status) override;
            void GetPermissionStatus(const WTF::String& origin, const GetPermissionStatusCallback& callback) override;

            void set_group_controller(
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
            {
                group_controller_ = std::move(group_controller);
            }

        private:
            mojo::MessageReceiverWithResponder* receiver_;
            scoped_refptr<mojo::AssociatedGroupController> group_controller_;
        };
        class BLINK_PLATFORM_EXPORT NotificationServiceStubDispatch {
        public:
            static bool Accept(NotificationService* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message);
            static bool AcceptWithResponder(NotificationService* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder);
        };

        template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<NotificationService>>
        class NotificationServiceStub
            : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
        public:
            using ImplPointerType = typename ImplRefTraits::PointerType;

            NotificationServiceStub() { }
            ~NotificationServiceStub() override { }

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
                return NotificationServiceStubDispatch::Accept(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
            }

            bool AcceptWithResponder(
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder) override
            {
                if (ImplRefTraits::IsNull(sink_))
                    return false;
                return NotificationServiceStubDispatch::AcceptWithResponder(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                    responder);
            }

        private:
            ImplPointerType sink_;
            mojo::internal::SerializationContext serialization_context_;
        };
        class BLINK_PLATFORM_EXPORT NotificationServiceRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };
        class BLINK_PLATFORM_EXPORT NotificationServiceResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };

    } // namespace blink
} // namespace mojom
} // namespace blink

namespace mojo {

} // namespace mojo

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_NOTIFICATIONS_NOTIFICATION_SERVICE_MOJOM_BLINK_H_