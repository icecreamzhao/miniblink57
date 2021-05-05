// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_USB_PUBLIC_INTERFACES_DEVICE_MANAGER_MOJOM_BLINK_H_
#define DEVICE_USB_PUBLIC_INTERFACES_DEVICE_MANAGER_MOJOM_BLINK_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "device/usb/public/interfaces/device.mojom-blink.h"
#include "device/usb/public/interfaces/device_manager.mojom-shared.h"
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
namespace usb {
    namespace blink {
        class DeviceManager;
        using DeviceManagerPtr = mojo::InterfacePtr<DeviceManager>;
        using DeviceManagerPtrInfo = mojo::InterfacePtrInfo<DeviceManager>;
        using ThreadSafeDeviceManagerPtr = mojo::ThreadSafeInterfacePtr<DeviceManager>;
        using DeviceManagerRequest = mojo::InterfaceRequest<DeviceManager>;
        using DeviceManagerAssociatedPtr = mojo::AssociatedInterfacePtr<DeviceManager>;
        using ThreadSafeDeviceManagerAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<DeviceManager>;
        using DeviceManagerAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<DeviceManager>;
        using DeviceManagerAssociatedRequest = mojo::AssociatedInterfaceRequest<DeviceManager>;

        class DeviceManagerClient;
        using DeviceManagerClientPtr = mojo::InterfacePtr<DeviceManagerClient>;
        using DeviceManagerClientPtrInfo = mojo::InterfacePtrInfo<DeviceManagerClient>;
        using ThreadSafeDeviceManagerClientPtr = mojo::ThreadSafeInterfacePtr<DeviceManagerClient>;
        using DeviceManagerClientRequest = mojo::InterfaceRequest<DeviceManagerClient>;
        using DeviceManagerClientAssociatedPtr = mojo::AssociatedInterfacePtr<DeviceManagerClient>;
        using ThreadSafeDeviceManagerClientAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<DeviceManagerClient>;
        using DeviceManagerClientAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<DeviceManagerClient>;
        using DeviceManagerClientAssociatedRequest = mojo::AssociatedInterfaceRequest<DeviceManagerClient>;

        class DeviceFilter;
        using DeviceFilterPtr = mojo::StructPtr<DeviceFilter>;

        class EnumerationOptions;
        using EnumerationOptionsPtr = mojo::StructPtr<EnumerationOptions>;

        class DeviceManagerProxy;

        template <typename ImplRefTraits>
        class DeviceManagerStub;

        class DeviceManagerRequestValidator;
        class DeviceManagerResponseValidator;

        class DeviceManager
            : public DeviceManagerInterfaceBase {
        public:
            static const char Name_[];
            static constexpr uint32_t Version_ = 0;
            static constexpr bool PassesAssociatedKinds_ = false;
            static constexpr bool HasSyncMethods_ = false;

            using Proxy_ = DeviceManagerProxy;

            template <typename ImplRefTraits>
            using Stub_ = DeviceManagerStub<ImplRefTraits>;

            using RequestValidator_ = DeviceManagerRequestValidator;
            using ResponseValidator_ = DeviceManagerResponseValidator;
            enum MethodMinVersions : uint32_t {
                kGetDevicesMinVersion = 0,
                kGetDeviceMinVersion = 0,
                kSetClientMinVersion = 0,
            };
            virtual ~DeviceManager() { }

            using GetDevicesCallback = base::Callback<void(WTF::Vector<::device::usb::blink::DeviceInfoPtr>)>;
            virtual void GetDevices(EnumerationOptionsPtr options, const GetDevicesCallback& callback) = 0;

            virtual void GetDevice(const WTF::String& guid, ::device::usb::blink::DeviceRequest device_request) = 0;

            virtual void SetClient(DeviceManagerClientPtr client) = 0;
        };

        class DeviceManagerClientProxy;

        template <typename ImplRefTraits>
        class DeviceManagerClientStub;

        class DeviceManagerClientRequestValidator;

        class DeviceManagerClient
            : public DeviceManagerClientInterfaceBase {
        public:
            static const char Name_[];
            static constexpr uint32_t Version_ = 0;
            static constexpr bool PassesAssociatedKinds_ = false;
            static constexpr bool HasSyncMethods_ = false;

            using Proxy_ = DeviceManagerClientProxy;

            template <typename ImplRefTraits>
            using Stub_ = DeviceManagerClientStub<ImplRefTraits>;

            using RequestValidator_ = DeviceManagerClientRequestValidator;
            using ResponseValidator_ = mojo::PassThroughFilter;
            enum MethodMinVersions : uint32_t {
                kOnDeviceAddedMinVersion = 0,
                kOnDeviceRemovedMinVersion = 0,
            };
            virtual ~DeviceManagerClient() { }

            virtual void OnDeviceAdded(::device::usb::blink::DeviceInfoPtr device_info) = 0;

            virtual void OnDeviceRemoved(::device::usb::blink::DeviceInfoPtr device_info) = 0;
        };

        class DeviceManagerProxy
            : public DeviceManager {
        public:
            explicit DeviceManagerProxy(mojo::MessageReceiverWithResponder* receiver);
            void GetDevices(EnumerationOptionsPtr options, const GetDevicesCallback& callback) override;
            void GetDevice(const WTF::String& guid, ::device::usb::blink::DeviceRequest device_request) override;
            void SetClient(DeviceManagerClientPtr client) override;

            void set_group_controller(
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
            {
                group_controller_ = std::move(group_controller);
            }

        private:
            mojo::MessageReceiverWithResponder* receiver_;
            scoped_refptr<mojo::AssociatedGroupController> group_controller_;
        };

        class DeviceManagerClientProxy
            : public DeviceManagerClient {
        public:
            explicit DeviceManagerClientProxy(mojo::MessageReceiverWithResponder* receiver);
            void OnDeviceAdded(::device::usb::blink::DeviceInfoPtr device_info) override;
            void OnDeviceRemoved(::device::usb::blink::DeviceInfoPtr device_info) override;

            void set_group_controller(
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
            {
                group_controller_ = std::move(group_controller);
            }

        private:
            mojo::MessageReceiverWithResponder* receiver_;
            scoped_refptr<mojo::AssociatedGroupController> group_controller_;
        };
        class DeviceManagerStubDispatch {
        public:
            static bool Accept(DeviceManager* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message);
            static bool AcceptWithResponder(DeviceManager* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder);
        };

        template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<DeviceManager>>
        class DeviceManagerStub
            : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
        public:
            using ImplPointerType = typename ImplRefTraits::PointerType;

            DeviceManagerStub() { }
            ~DeviceManagerStub() override { }

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
                return DeviceManagerStubDispatch::Accept(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
            }

            bool AcceptWithResponder(
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder) override
            {
                if (ImplRefTraits::IsNull(sink_))
                    return false;
                return DeviceManagerStubDispatch::AcceptWithResponder(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                    responder);
            }

        private:
            ImplPointerType sink_;
            mojo::internal::SerializationContext serialization_context_;
        };
        class DeviceManagerClientStubDispatch {
        public:
            static bool Accept(DeviceManagerClient* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message);
            static bool AcceptWithResponder(DeviceManagerClient* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder);
        };

        template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<DeviceManagerClient>>
        class DeviceManagerClientStub
            : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
        public:
            using ImplPointerType = typename ImplRefTraits::PointerType;

            DeviceManagerClientStub() { }
            ~DeviceManagerClientStub() override { }

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
                return DeviceManagerClientStubDispatch::Accept(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
            }

            bool AcceptWithResponder(
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder) override
            {
                if (ImplRefTraits::IsNull(sink_))
                    return false;
                return DeviceManagerClientStubDispatch::AcceptWithResponder(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                    responder);
            }

        private:
            ImplPointerType sink_;
            mojo::internal::SerializationContext serialization_context_;
        };
        class DeviceManagerRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };
        class DeviceManagerClientRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };
        class DeviceManagerResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };

        class DeviceFilter {
        public:
            using DataView = DeviceFilterDataView;
            using Data_ = internal::DeviceFilter_Data;

            static DeviceFilterPtr New();

            template <typename U>
            static DeviceFilterPtr From(const U& u)
            {
                return mojo::TypeConverter<DeviceFilterPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, DeviceFilter>::Convert(*this);
            }

            DeviceFilter();
            ~DeviceFilter();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = DeviceFilterPtr>
            DeviceFilterPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, DeviceFilter>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    DeviceFilter::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    DeviceFilter::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            bool has_vendor_id;
            uint16_t vendor_id;
            bool has_product_id;
            uint16_t product_id;
            bool has_class_code;
            uint8_t class_code;
            bool has_subclass_code;
            uint8_t subclass_code;
            bool has_protocol_code;
            uint8_t protocol_code;
            WTF::String serial_number;
        };

        class EnumerationOptions {
        public:
            using DataView = EnumerationOptionsDataView;
            using Data_ = internal::EnumerationOptions_Data;

            static EnumerationOptionsPtr New();

            template <typename U>
            static EnumerationOptionsPtr From(const U& u)
            {
                return mojo::TypeConverter<EnumerationOptionsPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, EnumerationOptions>::Convert(*this);
            }

            EnumerationOptions();
            ~EnumerationOptions();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = EnumerationOptionsPtr>
            EnumerationOptionsPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, EnumerationOptions>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    EnumerationOptions::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    EnumerationOptions::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            WTF::Optional<WTF::Vector<DeviceFilterPtr>> filters;

        private:
            DISALLOW_COPY_AND_ASSIGN(EnumerationOptions);
        };

        template <typename StructPtrType>
        DeviceFilterPtr DeviceFilter::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->has_vendor_id = mojo::internal::Clone(has_vendor_id);
            rv->vendor_id = mojo::internal::Clone(vendor_id);
            rv->has_product_id = mojo::internal::Clone(has_product_id);
            rv->product_id = mojo::internal::Clone(product_id);
            rv->has_class_code = mojo::internal::Clone(has_class_code);
            rv->class_code = mojo::internal::Clone(class_code);
            rv->has_subclass_code = mojo::internal::Clone(has_subclass_code);
            rv->subclass_code = mojo::internal::Clone(subclass_code);
            rv->has_protocol_code = mojo::internal::Clone(has_protocol_code);
            rv->protocol_code = mojo::internal::Clone(protocol_code);
            rv->serial_number = mojo::internal::Clone(serial_number);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, DeviceFilter>::value>::type*>
        bool DeviceFilter::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->has_vendor_id, other.has_vendor_id))
                return false;
            if (!mojo::internal::Equals(this->vendor_id, other.vendor_id))
                return false;
            if (!mojo::internal::Equals(this->has_product_id, other.has_product_id))
                return false;
            if (!mojo::internal::Equals(this->product_id, other.product_id))
                return false;
            if (!mojo::internal::Equals(this->has_class_code, other.has_class_code))
                return false;
            if (!mojo::internal::Equals(this->class_code, other.class_code))
                return false;
            if (!mojo::internal::Equals(this->has_subclass_code, other.has_subclass_code))
                return false;
            if (!mojo::internal::Equals(this->subclass_code, other.subclass_code))
                return false;
            if (!mojo::internal::Equals(this->has_protocol_code, other.has_protocol_code))
                return false;
            if (!mojo::internal::Equals(this->protocol_code, other.protocol_code))
                return false;
            if (!mojo::internal::Equals(this->serial_number, other.serial_number))
                return false;
            return true;
        }
        template <typename StructPtrType>
        EnumerationOptionsPtr EnumerationOptions::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->filters = mojo::internal::Clone(filters);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, EnumerationOptions>::value>::type*>
        bool EnumerationOptions::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->filters, other.filters))
                return false;
            return true;
        }

    } // namespace blink
} // namespace usb
} // namespace device

namespace mojo {

template <>
struct StructTraits<::device::usb::blink::DeviceFilter::DataView,
    ::device::usb::blink::DeviceFilterPtr> {
    static bool IsNull(const ::device::usb::blink::DeviceFilterPtr& input) { return !input; }
    static void SetToNull(::device::usb::blink::DeviceFilterPtr* output) { output->reset(); }

    static decltype(::device::usb::blink::DeviceFilter::has_vendor_id) has_vendor_id(
        const ::device::usb::blink::DeviceFilterPtr& input)
    {
        return input->has_vendor_id;
    }

    static decltype(::device::usb::blink::DeviceFilter::vendor_id) vendor_id(
        const ::device::usb::blink::DeviceFilterPtr& input)
    {
        return input->vendor_id;
    }

    static decltype(::device::usb::blink::DeviceFilter::has_product_id) has_product_id(
        const ::device::usb::blink::DeviceFilterPtr& input)
    {
        return input->has_product_id;
    }

    static decltype(::device::usb::blink::DeviceFilter::product_id) product_id(
        const ::device::usb::blink::DeviceFilterPtr& input)
    {
        return input->product_id;
    }

    static decltype(::device::usb::blink::DeviceFilter::has_class_code) has_class_code(
        const ::device::usb::blink::DeviceFilterPtr& input)
    {
        return input->has_class_code;
    }

    static decltype(::device::usb::blink::DeviceFilter::class_code) class_code(
        const ::device::usb::blink::DeviceFilterPtr& input)
    {
        return input->class_code;
    }

    static decltype(::device::usb::blink::DeviceFilter::has_subclass_code) has_subclass_code(
        const ::device::usb::blink::DeviceFilterPtr& input)
    {
        return input->has_subclass_code;
    }

    static decltype(::device::usb::blink::DeviceFilter::subclass_code) subclass_code(
        const ::device::usb::blink::DeviceFilterPtr& input)
    {
        return input->subclass_code;
    }

    static decltype(::device::usb::blink::DeviceFilter::has_protocol_code) has_protocol_code(
        const ::device::usb::blink::DeviceFilterPtr& input)
    {
        return input->has_protocol_code;
    }

    static decltype(::device::usb::blink::DeviceFilter::protocol_code) protocol_code(
        const ::device::usb::blink::DeviceFilterPtr& input)
    {
        return input->protocol_code;
    }

    static const decltype(::device::usb::blink::DeviceFilter::serial_number)& serial_number(
        const ::device::usb::blink::DeviceFilterPtr& input)
    {
        return input->serial_number;
    }

    static bool Read(::device::usb::blink::DeviceFilter::DataView input, ::device::usb::blink::DeviceFilterPtr* output);
};

template <>
struct StructTraits<::device::usb::blink::EnumerationOptions::DataView,
    ::device::usb::blink::EnumerationOptionsPtr> {
    static bool IsNull(const ::device::usb::blink::EnumerationOptionsPtr& input) { return !input; }
    static void SetToNull(::device::usb::blink::EnumerationOptionsPtr* output) { output->reset(); }

    static const decltype(::device::usb::blink::EnumerationOptions::filters)& filters(
        const ::device::usb::blink::EnumerationOptionsPtr& input)
    {
        return input->filters;
    }

    static bool Read(::device::usb::blink::EnumerationOptions::DataView input, ::device::usb::blink::EnumerationOptionsPtr* output);
};

} // namespace mojo

#endif // DEVICE_USB_PUBLIC_INTERFACES_DEVICE_MANAGER_MOJOM_BLINK_H_