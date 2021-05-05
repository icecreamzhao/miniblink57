// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_BATTERY_BATTERY_MONITOR_MOJOM_BLINK_H_
#define DEVICE_BATTERY_BATTERY_MONITOR_MOJOM_BLINK_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "device/battery/battery_monitor.mojom-shared.h"
#include "device/battery/battery_status.mojom-blink.h"
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

#include "mojo/public/cpp/bindings/lib/wtf_hash_util.h"
#include "third_party/WebKit/Source/wtf/HashFunctions.h"
#include "third_party/WebKit/Source/wtf/Optional.h"
#include "third_party/WebKit/Source/wtf/text/WTFString.h"

namespace device {
namespace blink {
    class BatteryMonitor;
    using BatteryMonitorPtr = mojo::InterfacePtr<BatteryMonitor>;
    using BatteryMonitorPtrInfo = mojo::InterfacePtrInfo<BatteryMonitor>;
    using ThreadSafeBatteryMonitorPtr = mojo::ThreadSafeInterfacePtr<BatteryMonitor>;
    using BatteryMonitorRequest = mojo::InterfaceRequest<BatteryMonitor>;
    using BatteryMonitorAssociatedPtr = mojo::AssociatedInterfacePtr<BatteryMonitor>;
    using ThreadSafeBatteryMonitorAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<BatteryMonitor>;
    using BatteryMonitorAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<BatteryMonitor>;
    using BatteryMonitorAssociatedRequest = mojo::AssociatedInterfaceRequest<BatteryMonitor>;

    class BatteryMonitorProxy;

    template <typename ImplRefTraits>
    class BatteryMonitorStub;

    class BatteryMonitorRequestValidator;
    class BatteryMonitorResponseValidator;

    class BatteryMonitor
        : public BatteryMonitorInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = BatteryMonitorProxy;

        template <typename ImplRefTraits>
        using Stub_ = BatteryMonitorStub<ImplRefTraits>;

        using RequestValidator_ = BatteryMonitorRequestValidator;
        using ResponseValidator_ = BatteryMonitorResponseValidator;
        enum MethodMinVersions : uint32_t {
            kQueryNextStatusMinVersion = 0,
        };
        virtual ~BatteryMonitor() { }

        using QueryNextStatusCallback = base::Callback<void(::device::blink::BatteryStatusPtr)>;
        virtual void QueryNextStatus(const QueryNextStatusCallback& callback) = 0;
    };

    class BatteryMonitorProxy
        : public BatteryMonitor {
    public:
        explicit BatteryMonitorProxy(mojo::MessageReceiverWithResponder* receiver);
        void QueryNextStatus(const QueryNextStatusCallback& callback) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class BatteryMonitorStubDispatch {
    public:
        static bool Accept(BatteryMonitor* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(BatteryMonitor* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<BatteryMonitor>>
    class BatteryMonitorStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        BatteryMonitorStub() { }
        ~BatteryMonitorStub() override { }

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
            return BatteryMonitorStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return BatteryMonitorStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class BatteryMonitorRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class BatteryMonitorResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

} // namespace blink
} // namespace device

namespace mojo {

} // namespace mojo

#endif // DEVICE_BATTERY_BATTERY_MONITOR_MOJOM_BLINK_H_