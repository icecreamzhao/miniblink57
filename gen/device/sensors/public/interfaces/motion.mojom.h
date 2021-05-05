// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_SENSORS_PUBLIC_INTERFACES_MOTION_MOJOM_H_
#define DEVICE_SENSORS_PUBLIC_INTERFACES_MOTION_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "device/sensors/public/interfaces/motion.mojom-shared.h"
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
    class MotionSensor;
    using MotionSensorPtr = mojo::InterfacePtr<MotionSensor>;
    using MotionSensorPtrInfo = mojo::InterfacePtrInfo<MotionSensor>;
    using ThreadSafeMotionSensorPtr = mojo::ThreadSafeInterfacePtr<MotionSensor>;
    using MotionSensorRequest = mojo::InterfaceRequest<MotionSensor>;
    using MotionSensorAssociatedPtr = mojo::AssociatedInterfacePtr<MotionSensor>;
    using ThreadSafeMotionSensorAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<MotionSensor>;
    using MotionSensorAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<MotionSensor>;
    using MotionSensorAssociatedRequest = mojo::AssociatedInterfaceRequest<MotionSensor>;

    class MotionSensorProxy;

    template <typename ImplRefTraits>
    class MotionSensorStub;

    class MotionSensorRequestValidator;
    class MotionSensorResponseValidator;

    class MotionSensor
        : public MotionSensorInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = MotionSensorProxy;

        template <typename ImplRefTraits>
        using Stub_ = MotionSensorStub<ImplRefTraits>;

        using RequestValidator_ = MotionSensorRequestValidator;
        using ResponseValidator_ = MotionSensorResponseValidator;
        enum MethodMinVersions : uint32_t {
            kStartPollingMinVersion = 0,
            kStopPollingMinVersion = 0,
        };
        virtual ~MotionSensor() { }

        using StartPollingCallback = base::Callback<void(mojo::ScopedSharedBufferHandle)>;
        virtual void StartPolling(const StartPollingCallback& callback) = 0;

        virtual void StopPolling() = 0;
    };

    class MotionSensorProxy
        : public MotionSensor {
    public:
        explicit MotionSensorProxy(mojo::MessageReceiverWithResponder* receiver);
        void StartPolling(const StartPollingCallback& callback) override;
        void StopPolling() override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class MotionSensorStubDispatch {
    public:
        static bool Accept(MotionSensor* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(MotionSensor* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<MotionSensor>>
    class MotionSensorStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        MotionSensorStub() { }
        ~MotionSensorStub() override { }

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
            return MotionSensorStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return MotionSensorStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class MotionSensorRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class MotionSensorResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

} // namespace mojom
} // namespace device

namespace mojo {

} // namespace mojo

#endif // DEVICE_SENSORS_PUBLIC_INTERFACES_MOTION_MOJOM_H_