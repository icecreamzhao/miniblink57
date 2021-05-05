// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_SENSORS_PUBLIC_INTERFACES_LIGHT_MOJOM_H_
#define DEVICE_SENSORS_PUBLIC_INTERFACES_LIGHT_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "device/sensors/public/interfaces/light.mojom-shared.h"
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
    class LightSensor;
    using LightSensorPtr = mojo::InterfacePtr<LightSensor>;
    using LightSensorPtrInfo = mojo::InterfacePtrInfo<LightSensor>;
    using ThreadSafeLightSensorPtr = mojo::ThreadSafeInterfacePtr<LightSensor>;
    using LightSensorRequest = mojo::InterfaceRequest<LightSensor>;
    using LightSensorAssociatedPtr = mojo::AssociatedInterfacePtr<LightSensor>;
    using ThreadSafeLightSensorAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<LightSensor>;
    using LightSensorAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<LightSensor>;
    using LightSensorAssociatedRequest = mojo::AssociatedInterfaceRequest<LightSensor>;

    class LightSensorProxy;

    template <typename ImplRefTraits>
    class LightSensorStub;

    class LightSensorRequestValidator;
    class LightSensorResponseValidator;

    class LightSensor
        : public LightSensorInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = LightSensorProxy;

        template <typename ImplRefTraits>
        using Stub_ = LightSensorStub<ImplRefTraits>;

        using RequestValidator_ = LightSensorRequestValidator;
        using ResponseValidator_ = LightSensorResponseValidator;
        enum MethodMinVersions : uint32_t {
            kStartPollingMinVersion = 0,
            kStopPollingMinVersion = 0,
        };
        virtual ~LightSensor() { }

        using StartPollingCallback = base::Callback<void(mojo::ScopedSharedBufferHandle)>;
        virtual void StartPolling(const StartPollingCallback& callback) = 0;

        virtual void StopPolling() = 0;
    };

    class LightSensorProxy
        : public LightSensor {
    public:
        explicit LightSensorProxy(mojo::MessageReceiverWithResponder* receiver);
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
    class LightSensorStubDispatch {
    public:
        static bool Accept(LightSensor* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(LightSensor* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<LightSensor>>
    class LightSensorStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        LightSensorStub() { }
        ~LightSensorStub() override { }

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
            return LightSensorStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return LightSensorStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class LightSensorRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class LightSensorResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

} // namespace mojom
} // namespace device

namespace mojo {

} // namespace mojo

#endif // DEVICE_SENSORS_PUBLIC_INTERFACES_LIGHT_MOJOM_H_