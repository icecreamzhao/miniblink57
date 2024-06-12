// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_VISITEDLINK_COMMON_VISITEDLINK_MOJOM_H_
#define COMPONENTS_VISITEDLINK_COMMON_VISITEDLINK_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "components/visitedlink/common/visitedlink.mojom-shared.h"
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
#include <string>
#include <vector>

namespace visitedlink {
namespace mojom {
    class VisitedLinkNotificationSink;
    using VisitedLinkNotificationSinkPtr = mojo::InterfacePtr<VisitedLinkNotificationSink>;
    using VisitedLinkNotificationSinkPtrInfo = mojo::InterfacePtrInfo<VisitedLinkNotificationSink>;
    using ThreadSafeVisitedLinkNotificationSinkPtr = mojo::ThreadSafeInterfacePtr<VisitedLinkNotificationSink>;
    using VisitedLinkNotificationSinkRequest = mojo::InterfaceRequest<VisitedLinkNotificationSink>;
    using VisitedLinkNotificationSinkAssociatedPtr = mojo::AssociatedInterfacePtr<VisitedLinkNotificationSink>;
    using ThreadSafeVisitedLinkNotificationSinkAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<VisitedLinkNotificationSink>;
    using VisitedLinkNotificationSinkAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<VisitedLinkNotificationSink>;
    using VisitedLinkNotificationSinkAssociatedRequest = mojo::AssociatedInterfaceRequest<VisitedLinkNotificationSink>;

    class VisitedLinkNotificationSinkProxy;

    template <typename ImplRefTraits>
    class VisitedLinkNotificationSinkStub;

    class VisitedLinkNotificationSinkRequestValidator;

    class VisitedLinkNotificationSink
        : public VisitedLinkNotificationSinkInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = VisitedLinkNotificationSinkProxy;

        template <typename ImplRefTraits>
        using Stub_ = VisitedLinkNotificationSinkStub<ImplRefTraits>;

        using RequestValidator_ = VisitedLinkNotificationSinkRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kUpdateVisitedLinksMinVersion = 0,
            kAddVisitedLinksMinVersion = 0,
            kResetVisitedLinksMinVersion = 0,
        };
        virtual ~VisitedLinkNotificationSink() { }

        virtual void UpdateVisitedLinks(mojo::ScopedSharedBufferHandle table_handle) = 0;

        virtual void AddVisitedLinks(const std::vector<uint64_t>& link_hashes) = 0;

        virtual void ResetVisitedLinks(bool invalidate_cached_hashes) = 0;
    };

    class VisitedLinkNotificationSinkProxy
        : public VisitedLinkNotificationSink {
    public:
        explicit VisitedLinkNotificationSinkProxy(mojo::MessageReceiverWithResponder* receiver);
        void UpdateVisitedLinks(mojo::ScopedSharedBufferHandle table_handle) override;
        void AddVisitedLinks(const std::vector<uint64_t>& link_hashes) override;
        void ResetVisitedLinks(bool invalidate_cached_hashes) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class VisitedLinkNotificationSinkStubDispatch {
    public:
        static bool Accept(VisitedLinkNotificationSink* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(VisitedLinkNotificationSink* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<VisitedLinkNotificationSink>>
    class VisitedLinkNotificationSinkStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        VisitedLinkNotificationSinkStub() { }
        ~VisitedLinkNotificationSinkStub() override { }

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
            return VisitedLinkNotificationSinkStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return VisitedLinkNotificationSinkStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class VisitedLinkNotificationSinkRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

} // namespace mojom
} // namespace visitedlink

namespace mojo {

} // namespace mojo

#endif // COMPONENTS_VISITEDLINK_COMMON_VISITEDLINK_MOJOM_H_