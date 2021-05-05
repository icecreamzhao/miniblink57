// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_WAKE_LOCK_PUBLIC_INTERFACES_WAKE_LOCK_SERVICE_MOJOM_H_
#define DEVICE_WAKE_LOCK_PUBLIC_INTERFACES_WAKE_LOCK_SERVICE_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "device/wake_lock/public/interfaces/wake_lock_service.mojom-shared.h"
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

namespace device {
namespace mojom {
    class WakeLockService;
    using WakeLockServicePtr = mojo::InterfacePtr<WakeLockService>;
    using WakeLockServicePtrInfo = mojo::InterfacePtrInfo<WakeLockService>;
    using ThreadSafeWakeLockServicePtr = mojo::ThreadSafeInterfacePtr<WakeLockService>;
    using WakeLockServiceRequest = mojo::InterfaceRequest<WakeLockService>;
    using WakeLockServiceAssociatedPtr = mojo::AssociatedInterfacePtr<WakeLockService>;
    using ThreadSafeWakeLockServiceAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<WakeLockService>;
    using WakeLockServiceAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<WakeLockService>;
    using WakeLockServiceAssociatedRequest = mojo::AssociatedInterfaceRequest<WakeLockService>;

    class WakeLockServiceProxy;

    template <typename ImplRefTraits>
    class WakeLockServiceStub;

    class WakeLockServiceRequestValidator;

    class WakeLockService
        : public WakeLockServiceInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = WakeLockServiceProxy;

        template <typename ImplRefTraits>
        using Stub_ = WakeLockServiceStub<ImplRefTraits>;

        using RequestValidator_ = WakeLockServiceRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kRequestWakeLockMinVersion = 0,
            kCancelWakeLockMinVersion = 0,
        };
        virtual ~WakeLockService() { }

        virtual void RequestWakeLock() = 0;

        virtual void CancelWakeLock() = 0;
    };

    class WakeLockServiceProxy
        : public WakeLockService {
    public:
        explicit WakeLockServiceProxy(mojo::MessageReceiverWithResponder* receiver);
        void RequestWakeLock() override;
        void CancelWakeLock() override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class WakeLockServiceStubDispatch {
    public:
        static bool Accept(WakeLockService* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(WakeLockService* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<WakeLockService>>
    class WakeLockServiceStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        WakeLockServiceStub() { }
        ~WakeLockServiceStub() override { }

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
            return WakeLockServiceStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return WakeLockServiceStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class WakeLockServiceRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

} // namespace mojom
} // namespace device

namespace mojo {

} // namespace mojo

#endif // DEVICE_WAKE_LOCK_PUBLIC_INTERFACES_WAKE_LOCK_SERVICE_MOJOM_H_