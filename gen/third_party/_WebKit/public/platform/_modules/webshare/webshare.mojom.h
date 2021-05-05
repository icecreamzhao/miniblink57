// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_WEBSHARE_WEBSHARE_MOJOM_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_WEBSHARE_WEBSHARE_MOJOM_H_

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
#include "content/common/content_export.h"
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
#include "third_party/WebKit/public/platform/modules/webshare/webshare.mojom-shared.h"
#include "url/gurl.h"
#include "url/mojo/url.mojom.h"
#include <string>
#include <vector>

namespace blink {
namespace mojom {
    class ShareService;
    using ShareServicePtr = mojo::InterfacePtr<ShareService>;
    using ShareServicePtrInfo = mojo::InterfacePtrInfo<ShareService>;
    using ThreadSafeShareServicePtr = mojo::ThreadSafeInterfacePtr<ShareService>;
    using ShareServiceRequest = mojo::InterfaceRequest<ShareService>;
    using ShareServiceAssociatedPtr = mojo::AssociatedInterfacePtr<ShareService>;
    using ThreadSafeShareServiceAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<ShareService>;
    using ShareServiceAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<ShareService>;
    using ShareServiceAssociatedRequest = mojo::AssociatedInterfaceRequest<ShareService>;

    class ShareServiceProxy;

    template <typename ImplRefTraits>
    class ShareServiceStub;

    class ShareServiceRequestValidator;
    class ShareServiceResponseValidator;

    class CONTENT_EXPORT ShareService
        : public ShareServiceInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = ShareServiceProxy;

        template <typename ImplRefTraits>
        using Stub_ = ShareServiceStub<ImplRefTraits>;

        using RequestValidator_ = ShareServiceRequestValidator;
        using ResponseValidator_ = ShareServiceResponseValidator;
        enum MethodMinVersions : uint32_t {
            kShareMinVersion = 0,
        };
        virtual ~ShareService() { }

        using ShareCallback = base::Callback<void(const base::Optional<std::string>&)>;
        virtual void Share(const std::string& title, const std::string& text, const GURL& url, const ShareCallback& callback) = 0;
    };

    class CONTENT_EXPORT ShareServiceProxy
        : public ShareService {
    public:
        explicit ShareServiceProxy(mojo::MessageReceiverWithResponder* receiver);
        void Share(const std::string& title, const std::string& text, const GURL& url, const ShareCallback& callback) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class CONTENT_EXPORT ShareServiceStubDispatch {
    public:
        static bool Accept(ShareService* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(ShareService* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<ShareService>>
    class ShareServiceStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        ShareServiceStub() { }
        ~ShareServiceStub() override { }

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
            return ShareServiceStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return ShareServiceStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class CONTENT_EXPORT ShareServiceRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class CONTENT_EXPORT ShareServiceResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

} // namespace mojom
} // namespace blink

namespace mojo {

} // namespace mojo

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_WEBSHARE_WEBSHARE_MOJOM_H_