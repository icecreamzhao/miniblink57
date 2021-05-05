// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_USB_PUBLIC_INTERFACES_DEVICE_MOJOM_BLINK_H_
#define DEVICE_USB_PUBLIC_INTERFACES_DEVICE_MOJOM_BLINK_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "device/usb/public/interfaces/device.mojom-shared.h"
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
        using OpenDeviceError = OpenDeviceError; // Alias for definition in the parent namespace.
        using TransferDirection = TransferDirection; // Alias for definition in the parent namespace.
        using ControlTransferType = ControlTransferType; // Alias for definition in the parent namespace.
        using ControlTransferRecipient = ControlTransferRecipient; // Alias for definition in the parent namespace.
        using EndpointType = EndpointType; // Alias for definition in the parent namespace.
        using TransferStatus = TransferStatus; // Alias for definition in the parent namespace.
        class Device;
        using DevicePtr = mojo::InterfacePtr<Device>;
        using DevicePtrInfo = mojo::InterfacePtrInfo<Device>;
        using ThreadSafeDevicePtr = mojo::ThreadSafeInterfacePtr<Device>;
        using DeviceRequest = mojo::InterfaceRequest<Device>;
        using DeviceAssociatedPtr = mojo::AssociatedInterfacePtr<Device>;
        using ThreadSafeDeviceAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<Device>;
        using DeviceAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<Device>;
        using DeviceAssociatedRequest = mojo::AssociatedInterfaceRequest<Device>;

        class EndpointInfo;
        using EndpointInfoPtr = mojo::InlinedStructPtr<EndpointInfo>;

        class AlternateInterfaceInfo;
        using AlternateInterfaceInfoPtr = mojo::StructPtr<AlternateInterfaceInfo>;

        class InterfaceInfo;
        using InterfaceInfoPtr = mojo::StructPtr<InterfaceInfo>;

        class ConfigurationInfo;
        using ConfigurationInfoPtr = mojo::StructPtr<ConfigurationInfo>;

        class DeviceInfo;
        using DeviceInfoPtr = mojo::StructPtr<DeviceInfo>;

        class ControlTransferParams;
        using ControlTransferParamsPtr = mojo::StructPtr<ControlTransferParams>;

        class IsochronousPacket;
        using IsochronousPacketPtr = mojo::InlinedStructPtr<IsochronousPacket>;

        class DeviceProxy;

        template <typename ImplRefTraits>
        class DeviceStub;

        class DeviceRequestValidator;
        class DeviceResponseValidator;

        class Device
            : public DeviceInterfaceBase {
        public:
            static const char Name_[];
            static constexpr uint32_t Version_ = 0;
            static constexpr bool PassesAssociatedKinds_ = false;
            static constexpr bool HasSyncMethods_ = false;

            using Proxy_ = DeviceProxy;

            template <typename ImplRefTraits>
            using Stub_ = DeviceStub<ImplRefTraits>;

            using RequestValidator_ = DeviceRequestValidator;
            using ResponseValidator_ = DeviceResponseValidator;
            enum MethodMinVersions : uint32_t {
                kGetDeviceInfoMinVersion = 0,
                kOpenMinVersion = 0,
                kCloseMinVersion = 0,
                kSetConfigurationMinVersion = 0,
                kClaimInterfaceMinVersion = 0,
                kReleaseInterfaceMinVersion = 0,
                kSetInterfaceAlternateSettingMinVersion = 0,
                kResetMinVersion = 0,
                kClearHaltMinVersion = 0,
                kControlTransferInMinVersion = 0,
                kControlTransferOutMinVersion = 0,
                kGenericTransferInMinVersion = 0,
                kGenericTransferOutMinVersion = 0,
                kIsochronousTransferInMinVersion = 0,
                kIsochronousTransferOutMinVersion = 0,
            };
            virtual ~Device() { }

            using GetDeviceInfoCallback = base::Callback<void(DeviceInfoPtr)>;
            virtual void GetDeviceInfo(const GetDeviceInfoCallback& callback) = 0;

            using OpenCallback = base::Callback<void(OpenDeviceError)>;
            virtual void Open(const OpenCallback& callback) = 0;

            using CloseCallback = base::Callback<void()>;
            virtual void Close(const CloseCallback& callback) = 0;

            using SetConfigurationCallback = base::Callback<void(bool)>;
            virtual void SetConfiguration(uint8_t value, const SetConfigurationCallback& callback) = 0;

            using ClaimInterfaceCallback = base::Callback<void(bool)>;
            virtual void ClaimInterface(uint8_t interface_number, const ClaimInterfaceCallback& callback) = 0;

            using ReleaseInterfaceCallback = base::Callback<void(bool)>;
            virtual void ReleaseInterface(uint8_t interface_number, const ReleaseInterfaceCallback& callback) = 0;

            using SetInterfaceAlternateSettingCallback = base::Callback<void(bool)>;
            virtual void SetInterfaceAlternateSetting(uint8_t interface_number, uint8_t alternate_setting, const SetInterfaceAlternateSettingCallback& callback) = 0;

            using ResetCallback = base::Callback<void(bool)>;
            virtual void Reset(const ResetCallback& callback) = 0;

            using ClearHaltCallback = base::Callback<void(bool)>;
            virtual void ClearHalt(uint8_t endpoint, const ClearHaltCallback& callback) = 0;

            using ControlTransferInCallback = base::Callback<void(TransferStatus, const WTF::Optional<WTF::Vector<uint8_t>>&)>;
            virtual void ControlTransferIn(ControlTransferParamsPtr params, uint32_t length, uint32_t timeout, const ControlTransferInCallback& callback) = 0;

            using ControlTransferOutCallback = base::Callback<void(TransferStatus)>;
            virtual void ControlTransferOut(ControlTransferParamsPtr params, const WTF::Vector<uint8_t>& data, uint32_t timeout, const ControlTransferOutCallback& callback) = 0;

            using GenericTransferInCallback = base::Callback<void(TransferStatus, const WTF::Optional<WTF::Vector<uint8_t>>&)>;
            virtual void GenericTransferIn(uint8_t endpoint_number, uint32_t length, uint32_t timeout, const GenericTransferInCallback& callback) = 0;

            using GenericTransferOutCallback = base::Callback<void(TransferStatus)>;
            virtual void GenericTransferOut(uint8_t endpoint_number, const WTF::Vector<uint8_t>& data, uint32_t timeout, const GenericTransferOutCallback& callback) = 0;

            using IsochronousTransferInCallback = base::Callback<void(const WTF::Optional<WTF::Vector<uint8_t>>&, WTF::Vector<IsochronousPacketPtr>)>;
            virtual void IsochronousTransferIn(uint8_t endpoint_number, const WTF::Vector<uint32_t>& packet_lengths, uint32_t timeout, const IsochronousTransferInCallback& callback) = 0;

            using IsochronousTransferOutCallback = base::Callback<void(WTF::Vector<IsochronousPacketPtr>)>;
            virtual void IsochronousTransferOut(uint8_t endpoint_number, const WTF::Vector<uint8_t>& data, const WTF::Vector<uint32_t>& packet_lengths, uint32_t timeout, const IsochronousTransferOutCallback& callback) = 0;
        };

        class DeviceProxy
            : public Device {
        public:
            explicit DeviceProxy(mojo::MessageReceiverWithResponder* receiver);
            void GetDeviceInfo(const GetDeviceInfoCallback& callback) override;
            void Open(const OpenCallback& callback) override;
            void Close(const CloseCallback& callback) override;
            void SetConfiguration(uint8_t value, const SetConfigurationCallback& callback) override;
            void ClaimInterface(uint8_t interface_number, const ClaimInterfaceCallback& callback) override;
            void ReleaseInterface(uint8_t interface_number, const ReleaseInterfaceCallback& callback) override;
            void SetInterfaceAlternateSetting(uint8_t interface_number, uint8_t alternate_setting, const SetInterfaceAlternateSettingCallback& callback) override;
            void Reset(const ResetCallback& callback) override;
            void ClearHalt(uint8_t endpoint, const ClearHaltCallback& callback) override;
            void ControlTransferIn(ControlTransferParamsPtr params, uint32_t length, uint32_t timeout, const ControlTransferInCallback& callback) override;
            void ControlTransferOut(ControlTransferParamsPtr params, const WTF::Vector<uint8_t>& data, uint32_t timeout, const ControlTransferOutCallback& callback) override;
            void GenericTransferIn(uint8_t endpoint_number, uint32_t length, uint32_t timeout, const GenericTransferInCallback& callback) override;
            void GenericTransferOut(uint8_t endpoint_number, const WTF::Vector<uint8_t>& data, uint32_t timeout, const GenericTransferOutCallback& callback) override;
            void IsochronousTransferIn(uint8_t endpoint_number, const WTF::Vector<uint32_t>& packet_lengths, uint32_t timeout, const IsochronousTransferInCallback& callback) override;
            void IsochronousTransferOut(uint8_t endpoint_number, const WTF::Vector<uint8_t>& data, const WTF::Vector<uint32_t>& packet_lengths, uint32_t timeout, const IsochronousTransferOutCallback& callback) override;

            void set_group_controller(
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
            {
                group_controller_ = std::move(group_controller);
            }

        private:
            mojo::MessageReceiverWithResponder* receiver_;
            scoped_refptr<mojo::AssociatedGroupController> group_controller_;
        };
        class DeviceStubDispatch {
        public:
            static bool Accept(Device* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message);
            static bool AcceptWithResponder(Device* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder);
        };

        template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<Device>>
        class DeviceStub
            : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
        public:
            using ImplPointerType = typename ImplRefTraits::PointerType;

            DeviceStub() { }
            ~DeviceStub() override { }

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
                return DeviceStubDispatch::Accept(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
            }

            bool AcceptWithResponder(
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder) override
            {
                if (ImplRefTraits::IsNull(sink_))
                    return false;
                return DeviceStubDispatch::AcceptWithResponder(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                    responder);
            }

        private:
            ImplPointerType sink_;
            mojo::internal::SerializationContext serialization_context_;
        };
        class DeviceRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };
        class DeviceResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };

        class EndpointInfo {
        public:
            using DataView = EndpointInfoDataView;
            using Data_ = internal::EndpointInfo_Data;

            static EndpointInfoPtr New();

            template <typename U>
            static EndpointInfoPtr From(const U& u)
            {
                return mojo::TypeConverter<EndpointInfoPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, EndpointInfo>::Convert(*this);
            }

            EndpointInfo();
            ~EndpointInfo();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = EndpointInfoPtr>
            EndpointInfoPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, EndpointInfo>::value>::type* = nullptr>
            bool Equals(const T& other) const;
            size_t Hash(size_t seed) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    EndpointInfo::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    EndpointInfo::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            uint8_t endpoint_number;
            TransferDirection direction;
            EndpointType type;
            uint32_t packet_size;
        };

        class IsochronousPacket {
        public:
            using DataView = IsochronousPacketDataView;
            using Data_ = internal::IsochronousPacket_Data;

            static IsochronousPacketPtr New();

            template <typename U>
            static IsochronousPacketPtr From(const U& u)
            {
                return mojo::TypeConverter<IsochronousPacketPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, IsochronousPacket>::Convert(*this);
            }

            IsochronousPacket();
            ~IsochronousPacket();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = IsochronousPacketPtr>
            IsochronousPacketPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, IsochronousPacket>::value>::type* = nullptr>
            bool Equals(const T& other) const;
            size_t Hash(size_t seed) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    IsochronousPacket::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    IsochronousPacket::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            uint32_t length;
            uint32_t transferred_length;
            TransferStatus status;
        };

        class AlternateInterfaceInfo {
        public:
            using DataView = AlternateInterfaceInfoDataView;
            using Data_ = internal::AlternateInterfaceInfo_Data;

            static AlternateInterfaceInfoPtr New();

            template <typename U>
            static AlternateInterfaceInfoPtr From(const U& u)
            {
                return mojo::TypeConverter<AlternateInterfaceInfoPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, AlternateInterfaceInfo>::Convert(*this);
            }

            AlternateInterfaceInfo();
            ~AlternateInterfaceInfo();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = AlternateInterfaceInfoPtr>
            AlternateInterfaceInfoPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, AlternateInterfaceInfo>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    AlternateInterfaceInfo::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    AlternateInterfaceInfo::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            uint8_t alternate_setting;
            uint8_t class_code;
            uint8_t subclass_code;
            uint8_t protocol_code;
            WTF::String interface_name;
            WTF::Vector<EndpointInfoPtr> endpoints;

        private:
            DISALLOW_COPY_AND_ASSIGN(AlternateInterfaceInfo);
        };

        class InterfaceInfo {
        public:
            using DataView = InterfaceInfoDataView;
            using Data_ = internal::InterfaceInfo_Data;

            static InterfaceInfoPtr New();

            template <typename U>
            static InterfaceInfoPtr From(const U& u)
            {
                return mojo::TypeConverter<InterfaceInfoPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, InterfaceInfo>::Convert(*this);
            }

            InterfaceInfo();
            ~InterfaceInfo();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = InterfaceInfoPtr>
            InterfaceInfoPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, InterfaceInfo>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    InterfaceInfo::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    InterfaceInfo::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            uint8_t interface_number;
            WTF::Vector<AlternateInterfaceInfoPtr> alternates;

        private:
            DISALLOW_COPY_AND_ASSIGN(InterfaceInfo);
        };

        class ConfigurationInfo {
        public:
            using DataView = ConfigurationInfoDataView;
            using Data_ = internal::ConfigurationInfo_Data;

            static ConfigurationInfoPtr New();

            template <typename U>
            static ConfigurationInfoPtr From(const U& u)
            {
                return mojo::TypeConverter<ConfigurationInfoPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, ConfigurationInfo>::Convert(*this);
            }

            ConfigurationInfo();
            ~ConfigurationInfo();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = ConfigurationInfoPtr>
            ConfigurationInfoPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, ConfigurationInfo>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    ConfigurationInfo::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    ConfigurationInfo::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            uint8_t configuration_value;
            WTF::String configuration_name;
            WTF::Vector<InterfaceInfoPtr> interfaces;

        private:
            DISALLOW_COPY_AND_ASSIGN(ConfigurationInfo);
        };

        class DeviceInfo {
        public:
            using DataView = DeviceInfoDataView;
            using Data_ = internal::DeviceInfo_Data;

            static DeviceInfoPtr New();

            template <typename U>
            static DeviceInfoPtr From(const U& u)
            {
                return mojo::TypeConverter<DeviceInfoPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, DeviceInfo>::Convert(*this);
            }

            DeviceInfo();
            ~DeviceInfo();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = DeviceInfoPtr>
            DeviceInfoPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, DeviceInfo>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    DeviceInfo::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    DeviceInfo::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            WTF::String guid;
            uint8_t usb_version_major;
            uint8_t usb_version_minor;
            uint8_t usb_version_subminor;
            uint8_t class_code;
            uint8_t subclass_code;
            uint8_t protocol_code;
            uint16_t vendor_id;
            uint16_t product_id;
            uint8_t device_version_major;
            uint8_t device_version_minor;
            uint8_t device_version_subminor;
            WTF::String manufacturer_name;
            WTF::String product_name;
            WTF::String serial_number;
            uint8_t active_configuration;
            WTF::Vector<ConfigurationInfoPtr> configurations;

        private:
            DISALLOW_COPY_AND_ASSIGN(DeviceInfo);
        };

        class ControlTransferParams {
        public:
            using DataView = ControlTransferParamsDataView;
            using Data_ = internal::ControlTransferParams_Data;

            static ControlTransferParamsPtr New();

            template <typename U>
            static ControlTransferParamsPtr From(const U& u)
            {
                return mojo::TypeConverter<ControlTransferParamsPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, ControlTransferParams>::Convert(*this);
            }

            ControlTransferParams();
            ~ControlTransferParams();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = ControlTransferParamsPtr>
            ControlTransferParamsPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, ControlTransferParams>::value>::type* = nullptr>
            bool Equals(const T& other) const;
            size_t Hash(size_t seed) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    ControlTransferParams::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    ControlTransferParams::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            ControlTransferType type;
            ControlTransferRecipient recipient;
            uint8_t request;
            uint16_t value;
            uint16_t index;
        };

        template <typename StructPtrType>
        EndpointInfoPtr EndpointInfo::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->endpoint_number = mojo::internal::Clone(endpoint_number);
            rv->direction = mojo::internal::Clone(direction);
            rv->type = mojo::internal::Clone(type);
            rv->packet_size = mojo::internal::Clone(packet_size);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, EndpointInfo>::value>::type*>
        bool EndpointInfo::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->endpoint_number, other.endpoint_number))
                return false;
            if (!mojo::internal::Equals(this->direction, other.direction))
                return false;
            if (!mojo::internal::Equals(this->type, other.type))
                return false;
            if (!mojo::internal::Equals(this->packet_size, other.packet_size))
                return false;
            return true;
        }
        template <typename StructPtrType>
        AlternateInterfaceInfoPtr AlternateInterfaceInfo::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->alternate_setting = mojo::internal::Clone(alternate_setting);
            rv->class_code = mojo::internal::Clone(class_code);
            rv->subclass_code = mojo::internal::Clone(subclass_code);
            rv->protocol_code = mojo::internal::Clone(protocol_code);
            rv->interface_name = mojo::internal::Clone(interface_name);
            rv->endpoints = mojo::internal::Clone(endpoints);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, AlternateInterfaceInfo>::value>::type*>
        bool AlternateInterfaceInfo::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->alternate_setting, other.alternate_setting))
                return false;
            if (!mojo::internal::Equals(this->class_code, other.class_code))
                return false;
            if (!mojo::internal::Equals(this->subclass_code, other.subclass_code))
                return false;
            if (!mojo::internal::Equals(this->protocol_code, other.protocol_code))
                return false;
            if (!mojo::internal::Equals(this->interface_name, other.interface_name))
                return false;
            if (!mojo::internal::Equals(this->endpoints, other.endpoints))
                return false;
            return true;
        }
        template <typename StructPtrType>
        InterfaceInfoPtr InterfaceInfo::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->interface_number = mojo::internal::Clone(interface_number);
            rv->alternates = mojo::internal::Clone(alternates);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, InterfaceInfo>::value>::type*>
        bool InterfaceInfo::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->interface_number, other.interface_number))
                return false;
            if (!mojo::internal::Equals(this->alternates, other.alternates))
                return false;
            return true;
        }
        template <typename StructPtrType>
        ConfigurationInfoPtr ConfigurationInfo::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->configuration_value = mojo::internal::Clone(configuration_value);
            rv->configuration_name = mojo::internal::Clone(configuration_name);
            rv->interfaces = mojo::internal::Clone(interfaces);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, ConfigurationInfo>::value>::type*>
        bool ConfigurationInfo::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->configuration_value, other.configuration_value))
                return false;
            if (!mojo::internal::Equals(this->configuration_name, other.configuration_name))
                return false;
            if (!mojo::internal::Equals(this->interfaces, other.interfaces))
                return false;
            return true;
        }
        template <typename StructPtrType>
        DeviceInfoPtr DeviceInfo::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->guid = mojo::internal::Clone(guid);
            rv->usb_version_major = mojo::internal::Clone(usb_version_major);
            rv->usb_version_minor = mojo::internal::Clone(usb_version_minor);
            rv->usb_version_subminor = mojo::internal::Clone(usb_version_subminor);
            rv->class_code = mojo::internal::Clone(class_code);
            rv->subclass_code = mojo::internal::Clone(subclass_code);
            rv->protocol_code = mojo::internal::Clone(protocol_code);
            rv->vendor_id = mojo::internal::Clone(vendor_id);
            rv->product_id = mojo::internal::Clone(product_id);
            rv->device_version_major = mojo::internal::Clone(device_version_major);
            rv->device_version_minor = mojo::internal::Clone(device_version_minor);
            rv->device_version_subminor = mojo::internal::Clone(device_version_subminor);
            rv->manufacturer_name = mojo::internal::Clone(manufacturer_name);
            rv->product_name = mojo::internal::Clone(product_name);
            rv->serial_number = mojo::internal::Clone(serial_number);
            rv->active_configuration = mojo::internal::Clone(active_configuration);
            rv->configurations = mojo::internal::Clone(configurations);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, DeviceInfo>::value>::type*>
        bool DeviceInfo::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->guid, other.guid))
                return false;
            if (!mojo::internal::Equals(this->usb_version_major, other.usb_version_major))
                return false;
            if (!mojo::internal::Equals(this->usb_version_minor, other.usb_version_minor))
                return false;
            if (!mojo::internal::Equals(this->usb_version_subminor, other.usb_version_subminor))
                return false;
            if (!mojo::internal::Equals(this->class_code, other.class_code))
                return false;
            if (!mojo::internal::Equals(this->subclass_code, other.subclass_code))
                return false;
            if (!mojo::internal::Equals(this->protocol_code, other.protocol_code))
                return false;
            if (!mojo::internal::Equals(this->vendor_id, other.vendor_id))
                return false;
            if (!mojo::internal::Equals(this->product_id, other.product_id))
                return false;
            if (!mojo::internal::Equals(this->device_version_major, other.device_version_major))
                return false;
            if (!mojo::internal::Equals(this->device_version_minor, other.device_version_minor))
                return false;
            if (!mojo::internal::Equals(this->device_version_subminor, other.device_version_subminor))
                return false;
            if (!mojo::internal::Equals(this->manufacturer_name, other.manufacturer_name))
                return false;
            if (!mojo::internal::Equals(this->product_name, other.product_name))
                return false;
            if (!mojo::internal::Equals(this->serial_number, other.serial_number))
                return false;
            if (!mojo::internal::Equals(this->active_configuration, other.active_configuration))
                return false;
            if (!mojo::internal::Equals(this->configurations, other.configurations))
                return false;
            return true;
        }
        template <typename StructPtrType>
        ControlTransferParamsPtr ControlTransferParams::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->type = mojo::internal::Clone(type);
            rv->recipient = mojo::internal::Clone(recipient);
            rv->request = mojo::internal::Clone(request);
            rv->value = mojo::internal::Clone(value);
            rv->index = mojo::internal::Clone(index);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, ControlTransferParams>::value>::type*>
        bool ControlTransferParams::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->type, other.type))
                return false;
            if (!mojo::internal::Equals(this->recipient, other.recipient))
                return false;
            if (!mojo::internal::Equals(this->request, other.request))
                return false;
            if (!mojo::internal::Equals(this->value, other.value))
                return false;
            if (!mojo::internal::Equals(this->index, other.index))
                return false;
            return true;
        }
        template <typename StructPtrType>
        IsochronousPacketPtr IsochronousPacket::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->length = mojo::internal::Clone(length);
            rv->transferred_length = mojo::internal::Clone(transferred_length);
            rv->status = mojo::internal::Clone(status);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, IsochronousPacket>::value>::type*>
        bool IsochronousPacket::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->length, other.length))
                return false;
            if (!mojo::internal::Equals(this->transferred_length, other.transferred_length))
                return false;
            if (!mojo::internal::Equals(this->status, other.status))
                return false;
            return true;
        }

    } // namespace blink
} // namespace usb
} // namespace device

namespace mojo {

template <>
struct StructTraits<::device::usb::blink::EndpointInfo::DataView,
    ::device::usb::blink::EndpointInfoPtr> {
    static bool IsNull(const ::device::usb::blink::EndpointInfoPtr& input) { return !input; }
    static void SetToNull(::device::usb::blink::EndpointInfoPtr* output) { output->reset(); }

    static decltype(::device::usb::blink::EndpointInfo::endpoint_number) endpoint_number(
        const ::device::usb::blink::EndpointInfoPtr& input)
    {
        return input->endpoint_number;
    }

    static decltype(::device::usb::blink::EndpointInfo::direction) direction(
        const ::device::usb::blink::EndpointInfoPtr& input)
    {
        return input->direction;
    }

    static decltype(::device::usb::blink::EndpointInfo::type) type(
        const ::device::usb::blink::EndpointInfoPtr& input)
    {
        return input->type;
    }

    static decltype(::device::usb::blink::EndpointInfo::packet_size) packet_size(
        const ::device::usb::blink::EndpointInfoPtr& input)
    {
        return input->packet_size;
    }

    static bool Read(::device::usb::blink::EndpointInfo::DataView input, ::device::usb::blink::EndpointInfoPtr* output);
};

template <>
struct StructTraits<::device::usb::blink::AlternateInterfaceInfo::DataView,
    ::device::usb::blink::AlternateInterfaceInfoPtr> {
    static bool IsNull(const ::device::usb::blink::AlternateInterfaceInfoPtr& input) { return !input; }
    static void SetToNull(::device::usb::blink::AlternateInterfaceInfoPtr* output) { output->reset(); }

    static decltype(::device::usb::blink::AlternateInterfaceInfo::alternate_setting) alternate_setting(
        const ::device::usb::blink::AlternateInterfaceInfoPtr& input)
    {
        return input->alternate_setting;
    }

    static decltype(::device::usb::blink::AlternateInterfaceInfo::class_code) class_code(
        const ::device::usb::blink::AlternateInterfaceInfoPtr& input)
    {
        return input->class_code;
    }

    static decltype(::device::usb::blink::AlternateInterfaceInfo::subclass_code) subclass_code(
        const ::device::usb::blink::AlternateInterfaceInfoPtr& input)
    {
        return input->subclass_code;
    }

    static decltype(::device::usb::blink::AlternateInterfaceInfo::protocol_code) protocol_code(
        const ::device::usb::blink::AlternateInterfaceInfoPtr& input)
    {
        return input->protocol_code;
    }

    static const decltype(::device::usb::blink::AlternateInterfaceInfo::interface_name)& interface_name(
        const ::device::usb::blink::AlternateInterfaceInfoPtr& input)
    {
        return input->interface_name;
    }

    static const decltype(::device::usb::blink::AlternateInterfaceInfo::endpoints)& endpoints(
        const ::device::usb::blink::AlternateInterfaceInfoPtr& input)
    {
        return input->endpoints;
    }

    static bool Read(::device::usb::blink::AlternateInterfaceInfo::DataView input, ::device::usb::blink::AlternateInterfaceInfoPtr* output);
};

template <>
struct StructTraits<::device::usb::blink::InterfaceInfo::DataView,
    ::device::usb::blink::InterfaceInfoPtr> {
    static bool IsNull(const ::device::usb::blink::InterfaceInfoPtr& input) { return !input; }
    static void SetToNull(::device::usb::blink::InterfaceInfoPtr* output) { output->reset(); }

    static decltype(::device::usb::blink::InterfaceInfo::interface_number) interface_number(
        const ::device::usb::blink::InterfaceInfoPtr& input)
    {
        return input->interface_number;
    }

    static const decltype(::device::usb::blink::InterfaceInfo::alternates)& alternates(
        const ::device::usb::blink::InterfaceInfoPtr& input)
    {
        return input->alternates;
    }

    static bool Read(::device::usb::blink::InterfaceInfo::DataView input, ::device::usb::blink::InterfaceInfoPtr* output);
};

template <>
struct StructTraits<::device::usb::blink::ConfigurationInfo::DataView,
    ::device::usb::blink::ConfigurationInfoPtr> {
    static bool IsNull(const ::device::usb::blink::ConfigurationInfoPtr& input) { return !input; }
    static void SetToNull(::device::usb::blink::ConfigurationInfoPtr* output) { output->reset(); }

    static decltype(::device::usb::blink::ConfigurationInfo::configuration_value) configuration_value(
        const ::device::usb::blink::ConfigurationInfoPtr& input)
    {
        return input->configuration_value;
    }

    static const decltype(::device::usb::blink::ConfigurationInfo::configuration_name)& configuration_name(
        const ::device::usb::blink::ConfigurationInfoPtr& input)
    {
        return input->configuration_name;
    }

    static const decltype(::device::usb::blink::ConfigurationInfo::interfaces)& interfaces(
        const ::device::usb::blink::ConfigurationInfoPtr& input)
    {
        return input->interfaces;
    }

    static bool Read(::device::usb::blink::ConfigurationInfo::DataView input, ::device::usb::blink::ConfigurationInfoPtr* output);
};

template <>
struct StructTraits<::device::usb::blink::DeviceInfo::DataView,
    ::device::usb::blink::DeviceInfoPtr> {
    static bool IsNull(const ::device::usb::blink::DeviceInfoPtr& input) { return !input; }
    static void SetToNull(::device::usb::blink::DeviceInfoPtr* output) { output->reset(); }

    static const decltype(::device::usb::blink::DeviceInfo::guid)& guid(
        const ::device::usb::blink::DeviceInfoPtr& input)
    {
        return input->guid;
    }

    static decltype(::device::usb::blink::DeviceInfo::usb_version_major) usb_version_major(
        const ::device::usb::blink::DeviceInfoPtr& input)
    {
        return input->usb_version_major;
    }

    static decltype(::device::usb::blink::DeviceInfo::usb_version_minor) usb_version_minor(
        const ::device::usb::blink::DeviceInfoPtr& input)
    {
        return input->usb_version_minor;
    }

    static decltype(::device::usb::blink::DeviceInfo::usb_version_subminor) usb_version_subminor(
        const ::device::usb::blink::DeviceInfoPtr& input)
    {
        return input->usb_version_subminor;
    }

    static decltype(::device::usb::blink::DeviceInfo::class_code) class_code(
        const ::device::usb::blink::DeviceInfoPtr& input)
    {
        return input->class_code;
    }

    static decltype(::device::usb::blink::DeviceInfo::subclass_code) subclass_code(
        const ::device::usb::blink::DeviceInfoPtr& input)
    {
        return input->subclass_code;
    }

    static decltype(::device::usb::blink::DeviceInfo::protocol_code) protocol_code(
        const ::device::usb::blink::DeviceInfoPtr& input)
    {
        return input->protocol_code;
    }

    static decltype(::device::usb::blink::DeviceInfo::vendor_id) vendor_id(
        const ::device::usb::blink::DeviceInfoPtr& input)
    {
        return input->vendor_id;
    }

    static decltype(::device::usb::blink::DeviceInfo::product_id) product_id(
        const ::device::usb::blink::DeviceInfoPtr& input)
    {
        return input->product_id;
    }

    static decltype(::device::usb::blink::DeviceInfo::device_version_major) device_version_major(
        const ::device::usb::blink::DeviceInfoPtr& input)
    {
        return input->device_version_major;
    }

    static decltype(::device::usb::blink::DeviceInfo::device_version_minor) device_version_minor(
        const ::device::usb::blink::DeviceInfoPtr& input)
    {
        return input->device_version_minor;
    }

    static decltype(::device::usb::blink::DeviceInfo::device_version_subminor) device_version_subminor(
        const ::device::usb::blink::DeviceInfoPtr& input)
    {
        return input->device_version_subminor;
    }

    static const decltype(::device::usb::blink::DeviceInfo::manufacturer_name)& manufacturer_name(
        const ::device::usb::blink::DeviceInfoPtr& input)
    {
        return input->manufacturer_name;
    }

    static const decltype(::device::usb::blink::DeviceInfo::product_name)& product_name(
        const ::device::usb::blink::DeviceInfoPtr& input)
    {
        return input->product_name;
    }

    static const decltype(::device::usb::blink::DeviceInfo::serial_number)& serial_number(
        const ::device::usb::blink::DeviceInfoPtr& input)
    {
        return input->serial_number;
    }

    static decltype(::device::usb::blink::DeviceInfo::active_configuration) active_configuration(
        const ::device::usb::blink::DeviceInfoPtr& input)
    {
        return input->active_configuration;
    }

    static const decltype(::device::usb::blink::DeviceInfo::configurations)& configurations(
        const ::device::usb::blink::DeviceInfoPtr& input)
    {
        return input->configurations;
    }

    static bool Read(::device::usb::blink::DeviceInfo::DataView input, ::device::usb::blink::DeviceInfoPtr* output);
};

template <>
struct StructTraits<::device::usb::blink::ControlTransferParams::DataView,
    ::device::usb::blink::ControlTransferParamsPtr> {
    static bool IsNull(const ::device::usb::blink::ControlTransferParamsPtr& input) { return !input; }
    static void SetToNull(::device::usb::blink::ControlTransferParamsPtr* output) { output->reset(); }

    static decltype(::device::usb::blink::ControlTransferParams::type) type(
        const ::device::usb::blink::ControlTransferParamsPtr& input)
    {
        return input->type;
    }

    static decltype(::device::usb::blink::ControlTransferParams::recipient) recipient(
        const ::device::usb::blink::ControlTransferParamsPtr& input)
    {
        return input->recipient;
    }

    static decltype(::device::usb::blink::ControlTransferParams::request) request(
        const ::device::usb::blink::ControlTransferParamsPtr& input)
    {
        return input->request;
    }

    static decltype(::device::usb::blink::ControlTransferParams::value) value(
        const ::device::usb::blink::ControlTransferParamsPtr& input)
    {
        return input->value;
    }

    static decltype(::device::usb::blink::ControlTransferParams::index) index(
        const ::device::usb::blink::ControlTransferParamsPtr& input)
    {
        return input->index;
    }

    static bool Read(::device::usb::blink::ControlTransferParams::DataView input, ::device::usb::blink::ControlTransferParamsPtr* output);
};

template <>
struct StructTraits<::device::usb::blink::IsochronousPacket::DataView,
    ::device::usb::blink::IsochronousPacketPtr> {
    static bool IsNull(const ::device::usb::blink::IsochronousPacketPtr& input) { return !input; }
    static void SetToNull(::device::usb::blink::IsochronousPacketPtr* output) { output->reset(); }

    static decltype(::device::usb::blink::IsochronousPacket::length) length(
        const ::device::usb::blink::IsochronousPacketPtr& input)
    {
        return input->length;
    }

    static decltype(::device::usb::blink::IsochronousPacket::transferred_length) transferred_length(
        const ::device::usb::blink::IsochronousPacketPtr& input)
    {
        return input->transferred_length;
    }

    static decltype(::device::usb::blink::IsochronousPacket::status) status(
        const ::device::usb::blink::IsochronousPacketPtr& input)
    {
        return input->status;
    }

    static bool Read(::device::usb::blink::IsochronousPacket::DataView input, ::device::usb::blink::IsochronousPacketPtr* output);
};

} // namespace mojo

#endif // DEVICE_USB_PUBLIC_INTERFACES_DEVICE_MOJOM_BLINK_H_