// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_USB_PUBLIC_INTERFACES_CHOOSER_SERVICE_MOJOM_H_
#define DEVICE_USB_PUBLIC_INTERFACES_CHOOSER_SERVICE_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "device/usb/public/interfaces/chooser_service.mojom-shared.h"
#include "device/usb/public/interfaces/device.mojom.h"
#include "device/usb/public/interfaces/device_manager.mojom.h"
#include "device/usb/usb_device_filter.h"
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
namespace usb {
    class ChooserService;
    using ChooserServicePtr = mojo::InterfacePtr<ChooserService>;
    using ChooserServicePtrInfo = mojo::InterfacePtrInfo<ChooserService>;
    using ThreadSafeChooserServicePtr = mojo::ThreadSafeInterfacePtr<ChooserService>;
    using ChooserServiceRequest = mojo::InterfaceRequest<ChooserService>;
    using ChooserServiceAssociatedPtr = mojo::AssociatedInterfacePtr<ChooserService>;
    using ThreadSafeChooserServiceAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<ChooserService>;
    using ChooserServiceAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<ChooserService>;
    using ChooserServiceAssociatedRequest = mojo::AssociatedInterfaceRequest<ChooserService>;

    class ChooserServiceProxy;

    template <typename ImplRefTraits>
    class ChooserServiceStub;

    class ChooserServiceRequestValidator;
    class ChooserServiceResponseValidator;

    class ChooserService
        : public ChooserServiceInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = ChooserServiceProxy;

        template <typename ImplRefTraits>
        using Stub_ = ChooserServiceStub<ImplRefTraits>;

        using RequestValidator_ = ChooserServiceRequestValidator;
        using ResponseValidator_ = ChooserServiceResponseValidator;
        enum MethodMinVersions : uint32_t {
            kGetPermissionMinVersion = 0,
        };
        virtual ~ChooserService() { }

        using GetPermissionCallback = base::Callback<void(::device::usb::DeviceInfoPtr)>;
        virtual void GetPermission(const std::vector<device::UsbDeviceFilter>& device_filters, const GetPermissionCallback& callback) = 0;
    };

    class ChooserServiceProxy
        : public ChooserService {
    public:
        explicit ChooserServiceProxy(mojo::MessageReceiverWithResponder* receiver);
        void GetPermission(const std::vector<device::UsbDeviceFilter>& device_filters, const GetPermissionCallback& callback) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class ChooserServiceStubDispatch {
    public:
        static bool Accept(ChooserService* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(ChooserService* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<ChooserService>>
    class ChooserServiceStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        ChooserServiceStub() { }
        ~ChooserServiceStub() override { }

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
            return ChooserServiceStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return ChooserServiceStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class ChooserServiceRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class ChooserServiceResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

} // namespace usb
} // namespace device

namespace mojo {

} // namespace mojo

#endif // DEVICE_USB_PUBLIC_INTERFACES_CHOOSER_SERVICE_MOJOM_H_