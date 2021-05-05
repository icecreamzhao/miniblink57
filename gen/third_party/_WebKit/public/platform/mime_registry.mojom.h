// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MIME_REGISTRY_MOJOM_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MIME_REGISTRY_MOJOM_H_

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
#include "content/common/bluetooth/web_bluetooth_device_id.h"
#include "content/common/content_export.h"
#include "content/public/common/media_metadata.h"
#include "content/public/common/referrer.h"
#include "device/bluetooth/bluetooth_uuid.h"
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
#include "third_party/WebKit/public/platform/WebReferrerPolicy.h"
#include "third_party/WebKit/public/platform/mime_registry.mojom-shared.h"
#include "third_party/WebKit/public/web/WebConsoleMessage.h"
#include "third_party/WebKit/public/web/WebWindowFeatures.h"
#include "ui/gfx/geometry/insets.h"
#include "ui/gfx/geometry/point.h"
#include "ui/gfx/geometry/point_f.h"
#include "ui/gfx/geometry/rect.h"
#include "ui/gfx/geometry/rect_f.h"
#include "ui/gfx/geometry/safe_integer_conversions.h"
#include "ui/gfx/geometry/size.h"
#include "ui/gfx/geometry/vector2d.h"
#include "ui/gfx/geometry/vector2d_f.h"
#include "url/gurl.h"
#include "url/origin.h"
#include <string>
#include <vector>

namespace blink {
namespace mojom {
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

    class CONTENT_EXPORT MimeRegistry
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
        virtual bool GetMimeTypeFromExtension(const std::string& extension, std::string* mime_type);

        using GetMimeTypeFromExtensionCallback = base::Callback<void(const std::string&)>;
        virtual void GetMimeTypeFromExtension(const std::string& extension, const GetMimeTypeFromExtensionCallback& callback) = 0;
    };

    class CONTENT_EXPORT MimeRegistryProxy
        : public MimeRegistry {
    public:
        explicit MimeRegistryProxy(mojo::MessageReceiverWithResponder* receiver);
        bool GetMimeTypeFromExtension(const std::string& extension, std::string* mime_type) override;
        void GetMimeTypeFromExtension(const std::string& extension, const GetMimeTypeFromExtensionCallback& callback) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class CONTENT_EXPORT MimeRegistryStubDispatch {
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
    class CONTENT_EXPORT MimeRegistryRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class CONTENT_EXPORT MimeRegistryResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

} // namespace mojom
} // namespace blink

namespace mojo {

} // namespace mojo

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MIME_REGISTRY_MOJOM_H_