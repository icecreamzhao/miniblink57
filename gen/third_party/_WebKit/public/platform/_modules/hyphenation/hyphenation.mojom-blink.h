// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_HYPHENATION_HYPHENATION_MOJOM_BLINK_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_HYPHENATION_HYPHENATION_MOJOM_BLINK_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "mojo/common/file.mojom-blink.h"
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
#include "third_party/WebKit/public/platform/modules/hyphenation/hyphenation.mojom-shared.h"

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
        class Hyphenation;
        using HyphenationPtr = mojo::InterfacePtr<Hyphenation>;
        using HyphenationPtrInfo = mojo::InterfacePtrInfo<Hyphenation>;
        using ThreadSafeHyphenationPtr = mojo::ThreadSafeInterfacePtr<Hyphenation>;
        using HyphenationRequest = mojo::InterfaceRequest<Hyphenation>;
        using HyphenationAssociatedPtr = mojo::AssociatedInterfacePtr<Hyphenation>;
        using ThreadSafeHyphenationAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<Hyphenation>;
        using HyphenationAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<Hyphenation>;
        using HyphenationAssociatedRequest = mojo::AssociatedInterfaceRequest<Hyphenation>;

        class HyphenationProxy;

        template <typename ImplRefTraits>
        class HyphenationStub;

        class HyphenationRequestValidator;
        class HyphenationResponseValidator;

        class BLINK_PLATFORM_EXPORT Hyphenation
            : public HyphenationInterfaceBase {
        public:
            static const char Name_[];
            static constexpr uint32_t Version_ = 0;
            static constexpr bool PassesAssociatedKinds_ = false;
            static constexpr bool HasSyncMethods_ = true;

            using Proxy_ = HyphenationProxy;

            template <typename ImplRefTraits>
            using Stub_ = HyphenationStub<ImplRefTraits>;

            using RequestValidator_ = HyphenationRequestValidator;
            using ResponseValidator_ = HyphenationResponseValidator;
            enum MethodMinVersions : uint32_t {
                kOpenDictionaryMinVersion = 0,
            };
            virtual ~Hyphenation() { }

            // Sync method. This signature is used by the client side; the service side
            // should implement the signature with callback below.
            virtual bool OpenDictionary(const WTF::String& locale, base::File* hyphenation_dictionary_handle);

            using OpenDictionaryCallback = base::Callback<void(base::File)>;
            virtual void OpenDictionary(const WTF::String& locale, const OpenDictionaryCallback& callback) = 0;
        };

        class BLINK_PLATFORM_EXPORT HyphenationProxy
            : public Hyphenation {
        public:
            explicit HyphenationProxy(mojo::MessageReceiverWithResponder* receiver);
            bool OpenDictionary(const WTF::String& locale, base::File* hyphenation_dictionary_handle) override;
            void OpenDictionary(const WTF::String& locale, const OpenDictionaryCallback& callback) override;

            void set_group_controller(
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
            {
                group_controller_ = std::move(group_controller);
            }

        private:
            mojo::MessageReceiverWithResponder* receiver_;
            scoped_refptr<mojo::AssociatedGroupController> group_controller_;
        };
        class BLINK_PLATFORM_EXPORT HyphenationStubDispatch {
        public:
            static bool Accept(Hyphenation* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message);
            static bool AcceptWithResponder(Hyphenation* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder);
        };

        template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<Hyphenation>>
        class HyphenationStub
            : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
        public:
            using ImplPointerType = typename ImplRefTraits::PointerType;

            HyphenationStub() { }
            ~HyphenationStub() override { }

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
                return HyphenationStubDispatch::Accept(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
            }

            bool AcceptWithResponder(
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder) override
            {
                if (ImplRefTraits::IsNull(sink_))
                    return false;
                return HyphenationStubDispatch::AcceptWithResponder(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                    responder);
            }

        private:
            ImplPointerType sink_;
            mojo::internal::SerializationContext serialization_context_;
        };
        class BLINK_PLATFORM_EXPORT HyphenationRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };
        class BLINK_PLATFORM_EXPORT HyphenationResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };

    } // namespace blink
} // namespace mojom
} // namespace blink

namespace mojo {

} // namespace mojo

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_HYPHENATION_HYPHENATION_MOJOM_BLINK_H_