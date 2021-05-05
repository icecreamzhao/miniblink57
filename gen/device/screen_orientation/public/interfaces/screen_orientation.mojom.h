// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_SCREEN_ORIENTATION_PUBLIC_INTERFACES_SCREEN_ORIENTATION_MOJOM_H_
#define DEVICE_SCREEN_ORIENTATION_PUBLIC_INTERFACES_SCREEN_ORIENTATION_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "device/screen_orientation/public/interfaces/screen_orientation.mojom-shared.h"
#include "device/screen_orientation/public/interfaces/screen_orientation_lock_types.mojom.h"
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
#include "third_party/WebKit/public/platform/modules/screen_orientation/WebScreenOrientationLockType.h"
#include <string>
#include <vector>

namespace device {
namespace mojom {
    class ScreenOrientation;
    using ScreenOrientationPtr = mojo::InterfacePtr<ScreenOrientation>;
    using ScreenOrientationPtrInfo = mojo::InterfacePtrInfo<ScreenOrientation>;
    using ThreadSafeScreenOrientationPtr = mojo::ThreadSafeInterfacePtr<ScreenOrientation>;
    using ScreenOrientationRequest = mojo::InterfaceRequest<ScreenOrientation>;
    using ScreenOrientationAssociatedPtr = mojo::AssociatedInterfacePtr<ScreenOrientation>;
    using ThreadSafeScreenOrientationAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<ScreenOrientation>;
    using ScreenOrientationAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<ScreenOrientation>;
    using ScreenOrientationAssociatedRequest = mojo::AssociatedInterfaceRequest<ScreenOrientation>;

    class ScreenOrientationListener;
    using ScreenOrientationListenerPtr = mojo::InterfacePtr<ScreenOrientationListener>;
    using ScreenOrientationListenerPtrInfo = mojo::InterfacePtrInfo<ScreenOrientationListener>;
    using ThreadSafeScreenOrientationListenerPtr = mojo::ThreadSafeInterfacePtr<ScreenOrientationListener>;
    using ScreenOrientationListenerRequest = mojo::InterfaceRequest<ScreenOrientationListener>;
    using ScreenOrientationListenerAssociatedPtr = mojo::AssociatedInterfacePtr<ScreenOrientationListener>;
    using ThreadSafeScreenOrientationListenerAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<ScreenOrientationListener>;
    using ScreenOrientationListenerAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<ScreenOrientationListener>;
    using ScreenOrientationListenerAssociatedRequest = mojo::AssociatedInterfaceRequest<ScreenOrientationListener>;

    class ScreenOrientationProxy;

    template <typename ImplRefTraits>
    class ScreenOrientationStub;

    class ScreenOrientationRequestValidator;
    class ScreenOrientationResponseValidator;

    class ScreenOrientation
        : public ScreenOrientationInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = ScreenOrientationProxy;

        template <typename ImplRefTraits>
        using Stub_ = ScreenOrientationStub<ImplRefTraits>;

        using RequestValidator_ = ScreenOrientationRequestValidator;
        using ResponseValidator_ = ScreenOrientationResponseValidator;
        enum MethodMinVersions : uint32_t {
            kLockOrientationMinVersion = 0,
            kUnlockOrientationMinVersion = 0,
        };
        virtual ~ScreenOrientation() { }

        using LockOrientationCallback = base::Callback<void(::device::mojom::ScreenOrientationLockResult)>;
        virtual void LockOrientation(::blink::WebScreenOrientationLockType orientation, const LockOrientationCallback& callback) = 0;

        virtual void UnlockOrientation() = 0;
    };

    class ScreenOrientationListenerProxy;

    template <typename ImplRefTraits>
    class ScreenOrientationListenerStub;

    class ScreenOrientationListenerRequestValidator;

    class ScreenOrientationListener
        : public ScreenOrientationListenerInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = ScreenOrientationListenerProxy;

        template <typename ImplRefTraits>
        using Stub_ = ScreenOrientationListenerStub<ImplRefTraits>;

        using RequestValidator_ = ScreenOrientationListenerRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kStartMinVersion = 0,
            kStopMinVersion = 0,
        };
        virtual ~ScreenOrientationListener() { }

        virtual void Start() = 0;

        virtual void Stop() = 0;
    };

    class ScreenOrientationProxy
        : public ScreenOrientation {
    public:
        explicit ScreenOrientationProxy(mojo::MessageReceiverWithResponder* receiver);
        void LockOrientation(::blink::WebScreenOrientationLockType orientation, const LockOrientationCallback& callback) override;
        void UnlockOrientation() override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class ScreenOrientationListenerProxy
        : public ScreenOrientationListener {
    public:
        explicit ScreenOrientationListenerProxy(mojo::MessageReceiverWithResponder* receiver);
        void Start() override;
        void Stop() override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class ScreenOrientationStubDispatch {
    public:
        static bool Accept(ScreenOrientation* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(ScreenOrientation* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<ScreenOrientation>>
    class ScreenOrientationStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        ScreenOrientationStub() { }
        ~ScreenOrientationStub() override { }

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
            return ScreenOrientationStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return ScreenOrientationStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class ScreenOrientationListenerStubDispatch {
    public:
        static bool Accept(ScreenOrientationListener* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(ScreenOrientationListener* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<ScreenOrientationListener>>
    class ScreenOrientationListenerStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        ScreenOrientationListenerStub() { }
        ~ScreenOrientationListenerStub() override { }

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
            return ScreenOrientationListenerStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return ScreenOrientationListenerStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class ScreenOrientationRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class ScreenOrientationListenerRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class ScreenOrientationResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

} // namespace mojom
} // namespace device

namespace mojo {

} // namespace mojo

#endif // DEVICE_SCREEN_ORIENTATION_PUBLIC_INTERFACES_SCREEN_ORIENTATION_MOJOM_H_