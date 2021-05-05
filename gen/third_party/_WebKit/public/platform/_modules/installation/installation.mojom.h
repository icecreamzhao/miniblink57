// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_INSTALLATION_INSTALLATION_MOJOM_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_INSTALLATION_INSTALLATION_MOJOM_H_

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
#include "third_party/WebKit/public/platform/modules/installation/installation.mojom-shared.h"
#include "url/gurl.h"
#include <string>
#include <vector>

namespace blink {
namespace mojom {
    class InstallationService;
    using InstallationServicePtr = mojo::InterfacePtr<InstallationService>;
    using InstallationServicePtrInfo = mojo::InterfacePtrInfo<InstallationService>;
    using ThreadSafeInstallationServicePtr = mojo::ThreadSafeInterfacePtr<InstallationService>;
    using InstallationServiceRequest = mojo::InterfaceRequest<InstallationService>;
    using InstallationServiceAssociatedPtr = mojo::AssociatedInterfacePtr<InstallationService>;
    using ThreadSafeInstallationServiceAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<InstallationService>;
    using InstallationServiceAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<InstallationService>;
    using InstallationServiceAssociatedRequest = mojo::AssociatedInterfaceRequest<InstallationService>;

    class InstallationServiceProxy;

    template <typename ImplRefTraits>
    class InstallationServiceStub;

    class InstallationServiceRequestValidator;

    class CONTENT_EXPORT InstallationService
        : public InstallationServiceInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = InstallationServiceProxy;

        template <typename ImplRefTraits>
        using Stub_ = InstallationServiceStub<ImplRefTraits>;

        using RequestValidator_ = InstallationServiceRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kOnInstallMinVersion = 0,
        };
        virtual ~InstallationService() { }

        virtual void OnInstall() = 0;
    };

    class CONTENT_EXPORT InstallationServiceProxy
        : public InstallationService {
    public:
        explicit InstallationServiceProxy(mojo::MessageReceiverWithResponder* receiver);
        void OnInstall() override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class CONTENT_EXPORT InstallationServiceStubDispatch {
    public:
        static bool Accept(InstallationService* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(InstallationService* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<InstallationService>>
    class InstallationServiceStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        InstallationServiceStub() { }
        ~InstallationServiceStub() override { }

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
            return InstallationServiceStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return InstallationServiceStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class CONTENT_EXPORT InstallationServiceRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

} // namespace mojom
} // namespace blink

namespace mojo {

} // namespace mojo

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_INSTALLATION_INSTALLATION_MOJOM_H_