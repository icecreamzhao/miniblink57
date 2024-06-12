// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MIME_REGISTRY_MOJOM_BLINK_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MIME_REGISTRY_MOJOM_BLINK_H_

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
#include "third_party/WebKit/public/platform/mime_registry.mojom-shared.h"

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
        class MimeRegistry;
        using MimeRegistryPtr = mojo::InterfacePtr<MimeRegistry>;
        using MimeRegistryPtrInfo = mojo::InterfacePtrInfo<MimeRegistry>;
        using ThreadSafeMimeRegistryPtr = mojo::ThreadSafeInterfacePtr<MimeRegistry>;
        using MimeRegistryRequest = mojo::InterfaceRequest<MimeRegistry>;
        using MimeRegistryAssociatedPtr = mojo::AssociatedInterfacePtr<MimeRegistry>;
        using ThreadSafeMimeRegistryAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<MimeRegistry>;
        using MimeRegistryAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<MimeRegistry>;
        using MimeRegistryAssociatedRequest = mojo::AssociatedInterfaceRequest<MimeRegistry>;

        class MimeRegistryProxy;

        template <typename ImplRefTraits>
        class MimeRegistryStub;

        class MimeRegistryRequestValidator;
        class MimeRegistryResponseValidator;

        class BLINK_PLATFORM_EXPORT MimeRegistry
            : public MimeRegistryInterfaceBase {
        public:
            static const char Name_[];
            static constexpr uint32_t Version_ = 0;
            static constexpr bool PassesAssociatedKinds_ = false;
            static constexpr bool HasSyncMethods_ = true;

            using Proxy_ = MimeRegistryProxy;

            template <typename ImplRefTraits>
            using Stub_ = MimeRegistryStub<ImplRefTraits>;

            using RequestValidator_ = MimeRegistryRequestValidator;
            using ResponseValidator_ = MimeRegistryResponseValidator;
            enum MethodMinVersions : uint32_t {
                kGetMimeTypeFromExtensionMinVersion = 0,
            };
            virtual ~MimeRegistry() { }

            // Sync method. This signature is used by the client side; the service side
            // should implement the signature with callback below.
            virtual bool GetMimeTypeFromExtension(const WTF::String& extension, WTF::String* mime_type);

            using GetMimeTypeFromExtensionCallback = base::Callback<void(const WTF::String&)>;
            virtual void GetMimeTypeFromExtension(const WTF::String& extension, const GetMimeTypeFromExtensionCallback& callback) = 0;
        };

        class BLINK_PLATFORM_EXPORT MimeRegistryProxy
            : public MimeRegistry {
        public:
            explicit MimeRegistryProxy(mojo::MessageReceiverWithResponder* receiver);
            bool GetMimeTypeFromExtension(const WTF::String& extension, WTF::String* mime_type) override;
            void GetMimeTypeFromExtension(const WTF::String& extension, const GetMimeTypeFromExtensionCallback& callback) override;

            void set_group_controller(
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
            {
                group_controller_ = std::move(group_controller);
            }

        private:
            mojo::MessageReceiverWithResponder* receiver_;
            scoped_refptr<mojo::AssociatedGroupController> group_controller_;
        };
        class BLINK_PLATFORM_EXPORT MimeRegistryStubDispatch {
        public:
            static bool Accept(MimeRegistry* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message);
            static bool AcceptWithResponder(MimeRegistry* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder);
        };

        template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<MimeRegistry>>
        class MimeRegistryStub
            : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
        public:
            using ImplPointerType = typename ImplRefTraits::PointerType;

            MimeRegistryStub() { }
            ~MimeRegistryStub() override { }

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
                return MimeRegistryStubDispatch::Accept(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
            }

            bool AcceptWithResponder(
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder) override
            {
                if (ImplRefTraits::IsNull(sink_))
                    return false;
                return MimeRegistryStubDispatch::AcceptWithResponder(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                    responder);
            }

        private:
            ImplPointerType sink_;
            mojo::internal::SerializationContext serialization_context_;
        };
        class BLINK_PLATFORM_EXPORT MimeRegistryRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };
        class BLINK_PLATFORM_EXPORT MimeRegistryResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };

    } // namespace blink
} // namespace mojom
} // namespace blink

namespace mojo {

} // namespace mojo

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MIME_REGISTRY_MOJOM_BLINK_H_