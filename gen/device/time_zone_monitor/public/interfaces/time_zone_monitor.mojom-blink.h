// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_TIME_ZONE_MONITOR_PUBLIC_INTERFACES_TIME_ZONE_MONITOR_MOJOM_BLINK_H_
#define DEVICE_TIME_ZONE_MONITOR_PUBLIC_INTERFACES_TIME_ZONE_MONITOR_MOJOM_BLINK_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "device/time_zone_monitor/public/interfaces/time_zone_monitor.mojom-shared.h"
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
namespace mojom {
    namespace blink {
        class TimeZoneMonitor;
        using TimeZoneMonitorPtr = mojo::InterfacePtr<TimeZoneMonitor>;
        using TimeZoneMonitorPtrInfo = mojo::InterfacePtrInfo<TimeZoneMonitor>;
        using ThreadSafeTimeZoneMonitorPtr = mojo::ThreadSafeInterfacePtr<TimeZoneMonitor>;
        using TimeZoneMonitorRequest = mojo::InterfaceRequest<TimeZoneMonitor>;
        using TimeZoneMonitorAssociatedPtr = mojo::AssociatedInterfacePtr<TimeZoneMonitor>;
        using ThreadSafeTimeZoneMonitorAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<TimeZoneMonitor>;
        using TimeZoneMonitorAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<TimeZoneMonitor>;
        using TimeZoneMonitorAssociatedRequest = mojo::AssociatedInterfaceRequest<TimeZoneMonitor>;

        class TimeZoneMonitorClient;
        using TimeZoneMonitorClientPtr = mojo::InterfacePtr<TimeZoneMonitorClient>;
        using TimeZoneMonitorClientPtrInfo = mojo::InterfacePtrInfo<TimeZoneMonitorClient>;
        using ThreadSafeTimeZoneMonitorClientPtr = mojo::ThreadSafeInterfacePtr<TimeZoneMonitorClient>;
        using TimeZoneMonitorClientRequest = mojo::InterfaceRequest<TimeZoneMonitorClient>;
        using TimeZoneMonitorClientAssociatedPtr = mojo::AssociatedInterfacePtr<TimeZoneMonitorClient>;
        using ThreadSafeTimeZoneMonitorClientAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<TimeZoneMonitorClient>;
        using TimeZoneMonitorClientAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<TimeZoneMonitorClient>;
        using TimeZoneMonitorClientAssociatedRequest = mojo::AssociatedInterfaceRequest<TimeZoneMonitorClient>;

        class TimeZoneMonitorProxy;

        template <typename ImplRefTraits>
        class TimeZoneMonitorStub;

        class TimeZoneMonitorRequestValidator;

        class TimeZoneMonitor
            : public TimeZoneMonitorInterfaceBase {
        public:
            static const char Name_[];
            static constexpr uint32_t Version_ = 0;
            static constexpr bool PassesAssociatedKinds_ = false;
            static constexpr bool HasSyncMethods_ = false;

            using Proxy_ = TimeZoneMonitorProxy;

            template <typename ImplRefTraits>
            using Stub_ = TimeZoneMonitorStub<ImplRefTraits>;

            using RequestValidator_ = TimeZoneMonitorRequestValidator;
            using ResponseValidator_ = mojo::PassThroughFilter;
            enum MethodMinVersions : uint32_t {
                kAddClientMinVersion = 0,
            };
            virtual ~TimeZoneMonitor() { }

            virtual void AddClient(TimeZoneMonitorClientPtr client) = 0;
        };

        class TimeZoneMonitorClientProxy;

        template <typename ImplRefTraits>
        class TimeZoneMonitorClientStub;

        class TimeZoneMonitorClientRequestValidator;

        class TimeZoneMonitorClient
            : public TimeZoneMonitorClientInterfaceBase {
        public:
            static const char Name_[];
            static constexpr uint32_t Version_ = 0;
            static constexpr bool PassesAssociatedKinds_ = false;
            static constexpr bool HasSyncMethods_ = false;

            using Proxy_ = TimeZoneMonitorClientProxy;

            template <typename ImplRefTraits>
            using Stub_ = TimeZoneMonitorClientStub<ImplRefTraits>;

            using RequestValidator_ = TimeZoneMonitorClientRequestValidator;
            using ResponseValidator_ = mojo::PassThroughFilter;
            enum MethodMinVersions : uint32_t {
                kOnTimeZoneChangeMinVersion = 0,
            };
            virtual ~TimeZoneMonitorClient() { }

            virtual void OnTimeZoneChange(const WTF::String& tz_info) = 0;
        };

        class TimeZoneMonitorProxy
            : public TimeZoneMonitor {
        public:
            explicit TimeZoneMonitorProxy(mojo::MessageReceiverWithResponder* receiver);
            void AddClient(TimeZoneMonitorClientPtr client) override;

            void set_group_controller(
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
            {
                group_controller_ = std::move(group_controller);
            }

        private:
            mojo::MessageReceiverWithResponder* receiver_;
            scoped_refptr<mojo::AssociatedGroupController> group_controller_;
        };

        class TimeZoneMonitorClientProxy
            : public TimeZoneMonitorClient {
        public:
            explicit TimeZoneMonitorClientProxy(mojo::MessageReceiverWithResponder* receiver);
            void OnTimeZoneChange(const WTF::String& tz_info) override;

            void set_group_controller(
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
            {
                group_controller_ = std::move(group_controller);
            }

        private:
            mojo::MessageReceiverWithResponder* receiver_;
            scoped_refptr<mojo::AssociatedGroupController> group_controller_;
        };
        class TimeZoneMonitorStubDispatch {
        public:
            static bool Accept(TimeZoneMonitor* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message);
            static bool AcceptWithResponder(TimeZoneMonitor* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder);
        };

        template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<TimeZoneMonitor>>
        class TimeZoneMonitorStub
            : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
        public:
            using ImplPointerType = typename ImplRefTraits::PointerType;

            TimeZoneMonitorStub() { }
            ~TimeZoneMonitorStub() override { }

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
                return TimeZoneMonitorStubDispatch::Accept(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
            }

            bool AcceptWithResponder(
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder) override
            {
                if (ImplRefTraits::IsNull(sink_))
                    return false;
                return TimeZoneMonitorStubDispatch::AcceptWithResponder(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                    responder);
            }

        private:
            ImplPointerType sink_;
            mojo::internal::SerializationContext serialization_context_;
        };
        class TimeZoneMonitorClientStubDispatch {
        public:
            static bool Accept(TimeZoneMonitorClient* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message);
            static bool AcceptWithResponder(TimeZoneMonitorClient* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder);
        };

        template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<TimeZoneMonitorClient>>
        class TimeZoneMonitorClientStub
            : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
        public:
            using ImplPointerType = typename ImplRefTraits::PointerType;

            TimeZoneMonitorClientStub() { }
            ~TimeZoneMonitorClientStub() override { }

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
                return TimeZoneMonitorClientStubDispatch::Accept(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
            }

            bool AcceptWithResponder(
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder) override
            {
                if (ImplRefTraits::IsNull(sink_))
                    return false;
                return TimeZoneMonitorClientStubDispatch::AcceptWithResponder(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                    responder);
            }

        private:
            ImplPointerType sink_;
            mojo::internal::SerializationContext serialization_context_;
        };
        class TimeZoneMonitorRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };
        class TimeZoneMonitorClientRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };

    } // namespace blink
} // namespace mojom
} // namespace device

namespace mojo {

} // namespace mojo

#endif // DEVICE_TIME_ZONE_MONITOR_PUBLIC_INTERFACES_TIME_ZONE_MONITOR_MOJOM_BLINK_H_