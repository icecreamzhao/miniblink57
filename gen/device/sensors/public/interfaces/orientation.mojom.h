// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_SENSORS_PUBLIC_INTERFACES_ORIENTATION_MOJOM_H_
#define DEVICE_SENSORS_PUBLIC_INTERFACES_ORIENTATION_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "device/sensors/public/interfaces/orientation.mojom-shared.h"
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
    class OrientationAbsoluteSensor;
    using OrientationAbsoluteSensorPtr = mojo::InterfacePtr<OrientationAbsoluteSensor>;
    using OrientationAbsoluteSensorPtrInfo = mojo::InterfacePtrInfo<OrientationAbsoluteSensor>;
    using ThreadSafeOrientationAbsoluteSensorPtr = mojo::ThreadSafeInterfacePtr<OrientationAbsoluteSensor>;
    using OrientationAbsoluteSensorRequest = mojo::InterfaceRequest<OrientationAbsoluteSensor>;
    using OrientationAbsoluteSensorAssociatedPtr = mojo::AssociatedInterfacePtr<OrientationAbsoluteSensor>;
    using ThreadSafeOrientationAbsoluteSensorAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<OrientationAbsoluteSensor>;
    using OrientationAbsoluteSensorAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<OrientationAbsoluteSensor>;
    using OrientationAbsoluteSensorAssociatedRequest = mojo::AssociatedInterfaceRequest<OrientationAbsoluteSensor>;

    class OrientationSensor;
    using OrientationSensorPtr = mojo::InterfacePtr<OrientationSensor>;
    using OrientationSensorPtrInfo = mojo::InterfacePtrInfo<OrientationSensor>;
    using ThreadSafeOrientationSensorPtr = mojo::ThreadSafeInterfacePtr<OrientationSensor>;
    using OrientationSensorRequest = mojo::InterfaceRequest<OrientationSensor>;
    using OrientationSensorAssociatedPtr = mojo::AssociatedInterfacePtr<OrientationSensor>;
    using ThreadSafeOrientationSensorAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<OrientationSensor>;
    using OrientationSensorAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<OrientationSensor>;
    using OrientationSensorAssociatedRequest = mojo::AssociatedInterfaceRequest<OrientationSensor>;

    class OrientationAbsoluteSensorProxy;

    template <typename ImplRefTraits>
    class OrientationAbsoluteSensorStub;

    class OrientationAbsoluteSensorRequestValidator;
    class OrientationAbsoluteSensorResponseValidator;

    class OrientationAbsoluteSensor
        : public OrientationAbsoluteSensorInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = OrientationAbsoluteSensorProxy;

        template <typename ImplRefTraits>
        using Stub_ = OrientationAbsoluteSensorStub<ImplRefTraits>;

        using RequestValidator_ = OrientationAbsoluteSensorRequestValidator;
        using ResponseValidator_ = OrientationAbsoluteSensorResponseValidator;
        enum MethodMinVersions : uint32_t {
            kStartPollingMinVersion = 0,
            kStopPollingMinVersion = 0,
        };
        virtual ~OrientationAbsoluteSensor() { }

        using StartPollingCallback = base::Callback<void(mojo::ScopedSharedBufferHandle)>;
        virtual void StartPolling(const StartPollingCallback& callback) = 0;

        virtual void StopPolling() = 0;
    };

    class OrientationSensorProxy;

    template <typename ImplRefTraits>
    class OrientationSensorStub;

    class OrientationSensorRequestValidator;
    class OrientationSensorResponseValidator;

    class OrientationSensor
        : public OrientationSensorInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = OrientationSensorProxy;

        template <typename ImplRefTraits>
        using Stub_ = OrientationSensorStub<ImplRefTraits>;

        using RequestValidator_ = OrientationSensorRequestValidator;
        using ResponseValidator_ = OrientationSensorResponseValidator;
        enum MethodMinVersions : uint32_t {
            kStartPollingMinVersion = 0,
            kStopPollingMinVersion = 0,
        };
        virtual ~OrientationSensor() { }

        using StartPollingCallback = base::Callback<void(mojo::ScopedSharedBufferHandle)>;
        virtual void StartPolling(const StartPollingCallback& callback) = 0;

        virtual void StopPolling() = 0;
    };

    class OrientationAbsoluteSensorProxy
        : public OrientationAbsoluteSensor {
    public:
        explicit OrientationAbsoluteSensorProxy(mojo::MessageReceiverWithResponder* receiver);
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

    class OrientationSensorProxy
        : public OrientationSensor {
    public:
        explicit OrientationSensorProxy(mojo::MessageReceiverWithResponder* receiver);
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
    class OrientationAbsoluteSensorStubDispatch {
    public:
        static bool Accept(OrientationAbsoluteSensor* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(OrientationAbsoluteSensor* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<OrientationAbsoluteSensor>>
    class OrientationAbsoluteSensorStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        OrientationAbsoluteSensorStub() { }
        ~OrientationAbsoluteSensorStub() override { }

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
            return OrientationAbsoluteSensorStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return OrientationAbsoluteSensorStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class OrientationSensorStubDispatch {
    public:
        static bool Accept(OrientationSensor* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(OrientationSensor* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<OrientationSensor>>
    class OrientationSensorStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        OrientationSensorStub() { }
        ~OrientationSensorStub() override { }

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
            return OrientationSensorStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return OrientationSensorStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class OrientationAbsoluteSensorRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class OrientationSensorRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class OrientationAbsoluteSensorResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class OrientationSensorResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

} // namespace mojom
} // namespace device

namespace mojo {

} // namespace mojo

#endif // DEVICE_SENSORS_PUBLIC_INTERFACES_ORIENTATION_MOJOM_H_