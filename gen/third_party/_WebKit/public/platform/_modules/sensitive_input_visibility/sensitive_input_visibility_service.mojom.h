// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_SENSITIVE_INPUT_VISIBILITY_SENSITIVE_INPUT_VISIBILITY_SERVICE_MOJOM_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_SENSITIVE_INPUT_VISIBILITY_SENSITIVE_INPUT_VISIBILITY_SERVICE_MOJOM_H_

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
#include "third_party/WebKit/public/platform/modules/sensitive_input_visibility/sensitive_input_visibility_service.mojom-shared.h"
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
    class SensitiveInputVisibilityService;
    using SensitiveInputVisibilityServicePtr = mojo::InterfacePtr<SensitiveInputVisibilityService>;
    using SensitiveInputVisibilityServicePtrInfo = mojo::InterfacePtrInfo<SensitiveInputVisibilityService>;
    using ThreadSafeSensitiveInputVisibilityServicePtr = mojo::ThreadSafeInterfacePtr<SensitiveInputVisibilityService>;
    using SensitiveInputVisibilityServiceRequest = mojo::InterfaceRequest<SensitiveInputVisibilityService>;
    using SensitiveInputVisibilityServiceAssociatedPtr = mojo::AssociatedInterfacePtr<SensitiveInputVisibilityService>;
    using ThreadSafeSensitiveInputVisibilityServiceAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<SensitiveInputVisibilityService>;
    using SensitiveInputVisibilityServiceAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<SensitiveInputVisibilityService>;
    using SensitiveInputVisibilityServiceAssociatedRequest = mojo::AssociatedInterfaceRequest<SensitiveInputVisibilityService>;

    class SensitiveInputVisibilityServiceProxy;

    template <typename ImplRefTraits>
    class SensitiveInputVisibilityServiceStub;

    class SensitiveInputVisibilityServiceRequestValidator;

    class CONTENT_EXPORT SensitiveInputVisibilityService
        : public SensitiveInputVisibilityServiceInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = SensitiveInputVisibilityServiceProxy;

        template <typename ImplRefTraits>
        using Stub_ = SensitiveInputVisibilityServiceStub<ImplRefTraits>;

        using RequestValidator_ = SensitiveInputVisibilityServiceRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kPasswordFieldVisibleInInsecureContextMinVersion = 0,
            kAllPasswordFieldsInInsecureContextInvisibleMinVersion = 0,
        };
        virtual ~SensitiveInputVisibilityService() { }

        virtual void PasswordFieldVisibleInInsecureContext() = 0;

        virtual void AllPasswordFieldsInInsecureContextInvisible() = 0;
    };

    class CONTENT_EXPORT SensitiveInputVisibilityServiceProxy
        : public SensitiveInputVisibilityService {
    public:
        explicit SensitiveInputVisibilityServiceProxy(mojo::MessageReceiverWithResponder* receiver);
        void PasswordFieldVisibleInInsecureContext() override;
        void AllPasswordFieldsInInsecureContextInvisible() override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class CONTENT_EXPORT SensitiveInputVisibilityServiceStubDispatch {
    public:
        static bool Accept(SensitiveInputVisibilityService* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(SensitiveInputVisibilityService* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<SensitiveInputVisibilityService>>
    class SensitiveInputVisibilityServiceStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        SensitiveInputVisibilityServiceStub() { }
        ~SensitiveInputVisibilityServiceStub() override { }

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
            return SensitiveInputVisibilityServiceStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return SensitiveInputVisibilityServiceStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class CONTENT_EXPORT SensitiveInputVisibilityServiceRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

} // namespace mojom
} // namespace blink

namespace mojo {

} // namespace mojo

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_SENSITIVE_INPUT_VISIBILITY_SENSITIVE_INPUT_VISIBILITY_SERVICE_MOJOM_H_