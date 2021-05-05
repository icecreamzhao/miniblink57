// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_POWER_MONITOR_PUBLIC_INTERFACES_POWER_MONITOR_MOJOM_H_
#define DEVICE_POWER_MONITOR_PUBLIC_INTERFACES_POWER_MONITOR_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "device/power_monitor/public/interfaces/power_monitor.mojom-shared.h"
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
    class PowerMonitor;
    using PowerMonitorPtr = mojo::InterfacePtr<PowerMonitor>;
    using PowerMonitorPtrInfo = mojo::InterfacePtrInfo<PowerMonitor>;
    using ThreadSafePowerMonitorPtr = mojo::ThreadSafeInterfacePtr<PowerMonitor>;
    using PowerMonitorRequest = mojo::InterfaceRequest<PowerMonitor>;
    using PowerMonitorAssociatedPtr = mojo::AssociatedInterfacePtr<PowerMonitor>;
    using ThreadSafePowerMonitorAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<PowerMonitor>;
    using PowerMonitorAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<PowerMonitor>;
    using PowerMonitorAssociatedRequest = mojo::AssociatedInterfaceRequest<PowerMonitor>;

    class PowerMonitorClient;
    using PowerMonitorClientPtr = mojo::InterfacePtr<PowerMonitorClient>;
    using PowerMonitorClientPtrInfo = mojo::InterfacePtrInfo<PowerMonitorClient>;
    using ThreadSafePowerMonitorClientPtr = mojo::ThreadSafeInterfacePtr<PowerMonitorClient>;
    using PowerMonitorClientRequest = mojo::InterfaceRequest<PowerMonitorClient>;
    using PowerMonitorClientAssociatedPtr = mojo::AssociatedInterfacePtr<PowerMonitorClient>;
    using ThreadSafePowerMonitorClientAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<PowerMonitorClient>;
    using PowerMonitorClientAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<PowerMonitorClient>;
    using PowerMonitorClientAssociatedRequest = mojo::AssociatedInterfaceRequest<PowerMonitorClient>;

    class PowerMonitorProxy;

    template <typename ImplRefTraits>
    class PowerMonitorStub;

    class PowerMonitorRequestValidator;

    class PowerMonitor
        : public PowerMonitorInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = PowerMonitorProxy;

        template <typename ImplRefTraits>
        using Stub_ = PowerMonitorStub<ImplRefTraits>;

        using RequestValidator_ = PowerMonitorRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kSetClientMinVersion = 0,
        };
        virtual ~PowerMonitor() { }

        virtual void SetClient(PowerMonitorClientPtr client) = 0;
    };

    class PowerMonitorClientProxy;

    template <typename ImplRefTraits>
    class PowerMonitorClientStub;

    class PowerMonitorClientRequestValidator;

    class PowerMonitorClient
        : public PowerMonitorClientInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = PowerMonitorClientProxy;

        template <typename ImplRefTraits>
        using Stub_ = PowerMonitorClientStub<ImplRefTraits>;

        using RequestValidator_ = PowerMonitorClientRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kPowerStateChangeMinVersion = 0,
            kSuspendMinVersion = 0,
            kResumeMinVersion = 0,
        };
        virtual ~PowerMonitorClient() { }

        virtual void PowerStateChange(bool on_battery_power) = 0;

        virtual void Suspend() = 0;

        virtual void Resume() = 0;
    };

    class PowerMonitorProxy
        : public PowerMonitor {
    public:
        explicit PowerMonitorProxy(mojo::MessageReceiverWithResponder* receiver);
        void SetClient(PowerMonitorClientPtr client) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class PowerMonitorClientProxy
        : public PowerMonitorClient {
    public:
        explicit PowerMonitorClientProxy(mojo::MessageReceiverWithResponder* receiver);
        void PowerStateChange(bool on_battery_power) override;
        void Suspend() override;
        void Resume() override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class PowerMonitorStubDispatch {
    public:
        static bool Accept(PowerMonitor* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(PowerMonitor* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<PowerMonitor>>
    class PowerMonitorStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        PowerMonitorStub() { }
        ~PowerMonitorStub() override { }

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
            return PowerMonitorStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return PowerMonitorStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class PowerMonitorClientStubDispatch {
    public:
        static bool Accept(PowerMonitorClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(PowerMonitorClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<PowerMonitorClient>>
    class PowerMonitorClientStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        PowerMonitorClientStub() { }
        ~PowerMonitorClientStub() override { }

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
            return PowerMonitorClientStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return PowerMonitorClientStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class PowerMonitorRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class PowerMonitorClientRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

} // namespace mojom
} // namespace device

namespace mojo {

} // namespace mojo

#endif // DEVICE_POWER_MONITOR_PUBLIC_INTERFACES_POWER_MONITOR_MOJOM_H_