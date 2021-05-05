// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_BLUETOOTH_WEB_BLUETOOTH_MOJOM_BLINK_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_BLUETOOTH_WEB_BLUETOOTH_MOJOM_BLINK_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "device/bluetooth/public/interfaces/uuid.mojom-blink.h"
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
#include "third_party/WebKit/public/platform/modules/bluetooth/web_bluetooth.mojom-shared.h"

#include "base/files/file.h"
#include "mojo/public/cpp/bindings/lib/wtf_hash_util.h"
#include "third_party/WebKit/Source/platform/weborigin/KURL.h"
#include "third_party/WebKit/Source/platform/weborigin/SecurityOrigin.h"
#include "third_party/WebKit/Source/wtf/HashFunctions.h"
#include "third_party/WebKit/Source/wtf/Optional.h"
#include "third_party/WebKit/Source/wtf/text/WTFString.h"
#include "third_party/WebKit/public/platform/WebCommon.h"
#include "third_party/WebKit/public/platform/WebReferrerPolicy.h"
#include "third_party/WebKit/public/platform/WebSize.h"
#include "third_party/WebKit/public/web/WebConsoleMessage.h"
#include "third_party/WebKit/public/web/WebWindowFeatures.h"

namespace blink {
namespace mojom {
    namespace blink {
        using WebBluetoothResult = WebBluetoothResult; // Alias for definition in the parent namespace.
        using WebBluetoothGATTQueryQuantity = WebBluetoothGATTQueryQuantity; // Alias for definition in the parent namespace.
        class WebBluetoothService;
        using WebBluetoothServicePtr = mojo::InterfacePtr<WebBluetoothService>;
        using WebBluetoothServicePtrInfo = mojo::InterfacePtrInfo<WebBluetoothService>;
        using ThreadSafeWebBluetoothServicePtr = mojo::ThreadSafeInterfacePtr<WebBluetoothService>;
        using WebBluetoothServiceRequest = mojo::InterfaceRequest<WebBluetoothService>;
        using WebBluetoothServiceAssociatedPtr = mojo::AssociatedInterfacePtr<WebBluetoothService>;
        using ThreadSafeWebBluetoothServiceAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<WebBluetoothService>;
        using WebBluetoothServiceAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<WebBluetoothService>;
        using WebBluetoothServiceAssociatedRequest = mojo::AssociatedInterfaceRequest<WebBluetoothService>;

        class WebBluetoothServiceClient;
        using WebBluetoothServiceClientPtr = mojo::InterfacePtr<WebBluetoothServiceClient>;
        using WebBluetoothServiceClientPtrInfo = mojo::InterfacePtrInfo<WebBluetoothServiceClient>;
        using ThreadSafeWebBluetoothServiceClientPtr = mojo::ThreadSafeInterfacePtr<WebBluetoothServiceClient>;
        using WebBluetoothServiceClientRequest = mojo::InterfaceRequest<WebBluetoothServiceClient>;
        using WebBluetoothServiceClientAssociatedPtr = mojo::AssociatedInterfacePtr<WebBluetoothServiceClient>;
        using ThreadSafeWebBluetoothServiceClientAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<WebBluetoothServiceClient>;
        using WebBluetoothServiceClientAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<WebBluetoothServiceClient>;
        using WebBluetoothServiceClientAssociatedRequest = mojo::AssociatedInterfaceRequest<WebBluetoothServiceClient>;

        class WebBluetoothScanFilter;
        using WebBluetoothScanFilterPtr = mojo::StructPtr<WebBluetoothScanFilter>;

        class WebBluetoothRequestDeviceOptions;
        using WebBluetoothRequestDeviceOptionsPtr = mojo::StructPtr<WebBluetoothRequestDeviceOptions>;

        class WebBluetoothDeviceId;
        using WebBluetoothDeviceIdPtr = mojo::InlinedStructPtr<WebBluetoothDeviceId>;

        class WebBluetoothDevice;
        using WebBluetoothDevicePtr = mojo::StructPtr<WebBluetoothDevice>;

        class WebBluetoothRemoteGATTService;
        using WebBluetoothRemoteGATTServicePtr = mojo::StructPtr<WebBluetoothRemoteGATTService>;

        class WebBluetoothRemoteGATTCharacteristic;
        using WebBluetoothRemoteGATTCharacteristicPtr = mojo::StructPtr<WebBluetoothRemoteGATTCharacteristic>;

        class WebBluetoothRemoteGATTDescriptor;
        using WebBluetoothRemoteGATTDescriptorPtr = mojo::StructPtr<WebBluetoothRemoteGATTDescriptor>;

        class WebBluetoothServiceProxy;

        template <typename ImplRefTraits>
        class WebBluetoothServiceStub;

        class WebBluetoothServiceRequestValidator;
        class WebBluetoothServiceResponseValidator;

        class BLINK_PLATFORM_EXPORT WebBluetoothService
            : public WebBluetoothServiceInterfaceBase {
        public:
            static const char Name_[];
            static constexpr uint32_t Version_ = 0;
            static constexpr bool PassesAssociatedKinds_ = true;
            static constexpr bool HasSyncMethods_ = false;

            using Proxy_ = WebBluetoothServiceProxy;

            template <typename ImplRefTraits>
            using Stub_ = WebBluetoothServiceStub<ImplRefTraits>;

            using RequestValidator_ = WebBluetoothServiceRequestValidator;
            using ResponseValidator_ = WebBluetoothServiceResponseValidator;
            enum MethodMinVersions : uint32_t {
                kSetClientMinVersion = 0,
                kRequestDeviceMinVersion = 0,
                kRemoteServerConnectMinVersion = 0,
                kRemoteServerDisconnectMinVersion = 0,
                kRemoteServerGetPrimaryServicesMinVersion = 0,
                kRemoteServiceGetCharacteristicsMinVersion = 0,
                kRemoteCharacteristicReadValueMinVersion = 0,
                kRemoteCharacteristicWriteValueMinVersion = 0,
                kRemoteCharacteristicStartNotificationsMinVersion = 0,
                kRemoteCharacteristicStopNotificationsMinVersion = 0,
                kRemoteCharacteristicGetDescriptorsMinVersion = 0,
            };
            virtual ~WebBluetoothService() { }

            virtual void SetClient(WebBluetoothServiceClientAssociatedPtrInfo client) = 0;

            using RequestDeviceCallback = base::Callback<void(WebBluetoothResult, WebBluetoothDevicePtr)>;
            virtual void RequestDevice(WebBluetoothRequestDeviceOptionsPtr options, const RequestDeviceCallback& callback) = 0;

            using RemoteServerConnectCallback = base::Callback<void(WebBluetoothResult)>;
            virtual void RemoteServerConnect(const WTF::String& device_id, const RemoteServerConnectCallback& callback) = 0;

            virtual void RemoteServerDisconnect(const WTF::String& device_id) = 0;

            using RemoteServerGetPrimaryServicesCallback = base::Callback<void(WebBluetoothResult, WTF::Optional<WTF::Vector<WebBluetoothRemoteGATTServicePtr>>)>;
            virtual void RemoteServerGetPrimaryServices(const WTF::String& device_id, WebBluetoothGATTQueryQuantity quantity, const WTF::Optional<WTF::String>& services_uuid, const RemoteServerGetPrimaryServicesCallback& callback) = 0;

            using RemoteServiceGetCharacteristicsCallback = base::Callback<void(WebBluetoothResult, WTF::Optional<WTF::Vector<WebBluetoothRemoteGATTCharacteristicPtr>>)>;
            virtual void RemoteServiceGetCharacteristics(const WTF::String& service_instance_id, WebBluetoothGATTQueryQuantity quantity, const WTF::Optional<WTF::String>& characteristics_uuid, const RemoteServiceGetCharacteristicsCallback& callback) = 0;

            using RemoteCharacteristicReadValueCallback = base::Callback<void(WebBluetoothResult, const WTF::Optional<WTF::Vector<uint8_t>>&)>;
            virtual void RemoteCharacteristicReadValue(const WTF::String& characteristic_instance_id, const RemoteCharacteristicReadValueCallback& callback) = 0;

            using RemoteCharacteristicWriteValueCallback = base::Callback<void(WebBluetoothResult)>;
            virtual void RemoteCharacteristicWriteValue(const WTF::String& characteristic_instance_id, const WTF::Vector<uint8_t>& value, const RemoteCharacteristicWriteValueCallback& callback) = 0;

            using RemoteCharacteristicStartNotificationsCallback = base::Callback<void(WebBluetoothResult)>;
            virtual void RemoteCharacteristicStartNotifications(const WTF::String& characteristic_instance_id, const RemoteCharacteristicStartNotificationsCallback& callback) = 0;

            using RemoteCharacteristicStopNotificationsCallback = base::Callback<void()>;
            virtual void RemoteCharacteristicStopNotifications(const WTF::String& characteristic_instance_id, const RemoteCharacteristicStopNotificationsCallback& callback) = 0;

            using RemoteCharacteristicGetDescriptorsCallback = base::Callback<void(WebBluetoothResult, WTF::Optional<WTF::Vector<WebBluetoothRemoteGATTDescriptorPtr>>)>;
            virtual void RemoteCharacteristicGetDescriptors(const WTF::String& characteristics_instance_id, WebBluetoothGATTQueryQuantity quantity, const WTF::Optional<WTF::String>& descriptor_uuid, const RemoteCharacteristicGetDescriptorsCallback& callback) = 0;
        };

        class WebBluetoothServiceClientProxy;

        template <typename ImplRefTraits>
        class WebBluetoothServiceClientStub;

        class WebBluetoothServiceClientRequestValidator;

        class BLINK_PLATFORM_EXPORT WebBluetoothServiceClient
            : public WebBluetoothServiceClientInterfaceBase {
        public:
            static const char Name_[];
            static constexpr uint32_t Version_ = 0;
            static constexpr bool PassesAssociatedKinds_ = false;
            static constexpr bool HasSyncMethods_ = false;

            using Proxy_ = WebBluetoothServiceClientProxy;

            template <typename ImplRefTraits>
            using Stub_ = WebBluetoothServiceClientStub<ImplRefTraits>;

            using RequestValidator_ = WebBluetoothServiceClientRequestValidator;
            using ResponseValidator_ = mojo::PassThroughFilter;
            enum MethodMinVersions : uint32_t {
                kRemoteCharacteristicValueChangedMinVersion = 0,
                kGattServerDisconnectedMinVersion = 0,
            };
            virtual ~WebBluetoothServiceClient() { }

            virtual void RemoteCharacteristicValueChanged(const WTF::String& characteristic_instance_id, const WTF::Vector<uint8_t>& value) = 0;

            virtual void GattServerDisconnected(const WTF::String& device_id) = 0;
        };

        class BLINK_PLATFORM_EXPORT WebBluetoothServiceProxy
            : public WebBluetoothService {
        public:
            explicit WebBluetoothServiceProxy(mojo::MessageReceiverWithResponder* receiver);
            void SetClient(WebBluetoothServiceClientAssociatedPtrInfo client) override;
            void RequestDevice(WebBluetoothRequestDeviceOptionsPtr options, const RequestDeviceCallback& callback) override;
            void RemoteServerConnect(const WTF::String& device_id, const RemoteServerConnectCallback& callback) override;
            void RemoteServerDisconnect(const WTF::String& device_id) override;
            void RemoteServerGetPrimaryServices(const WTF::String& device_id, WebBluetoothGATTQueryQuantity quantity, const WTF::Optional<WTF::String>& services_uuid, const RemoteServerGetPrimaryServicesCallback& callback) override;
            void RemoteServiceGetCharacteristics(const WTF::String& service_instance_id, WebBluetoothGATTQueryQuantity quantity, const WTF::Optional<WTF::String>& characteristics_uuid, const RemoteServiceGetCharacteristicsCallback& callback) override;
            void RemoteCharacteristicReadValue(const WTF::String& characteristic_instance_id, const RemoteCharacteristicReadValueCallback& callback) override;
            void RemoteCharacteristicWriteValue(const WTF::String& characteristic_instance_id, const WTF::Vector<uint8_t>& value, const RemoteCharacteristicWriteValueCallback& callback) override;
            void RemoteCharacteristicStartNotifications(const WTF::String& characteristic_instance_id, const RemoteCharacteristicStartNotificationsCallback& callback) override;
            void RemoteCharacteristicStopNotifications(const WTF::String& characteristic_instance_id, const RemoteCharacteristicStopNotificationsCallback& callback) override;
            void RemoteCharacteristicGetDescriptors(const WTF::String& characteristics_instance_id, WebBluetoothGATTQueryQuantity quantity, const WTF::Optional<WTF::String>& descriptor_uuid, const RemoteCharacteristicGetDescriptorsCallback& callback) override;

            void set_group_controller(
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
            {
                group_controller_ = std::move(group_controller);
            }

        private:
            mojo::MessageReceiverWithResponder* receiver_;
            scoped_refptr<mojo::AssociatedGroupController> group_controller_;
        };

        class BLINK_PLATFORM_EXPORT WebBluetoothServiceClientProxy
            : public WebBluetoothServiceClient {
        public:
            explicit WebBluetoothServiceClientProxy(mojo::MessageReceiverWithResponder* receiver);
            void RemoteCharacteristicValueChanged(const WTF::String& characteristic_instance_id, const WTF::Vector<uint8_t>& value) override;
            void GattServerDisconnected(const WTF::String& device_id) override;

            void set_group_controller(
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
            {
                group_controller_ = std::move(group_controller);
            }

        private:
            mojo::MessageReceiverWithResponder* receiver_;
            scoped_refptr<mojo::AssociatedGroupController> group_controller_;
        };
        class BLINK_PLATFORM_EXPORT WebBluetoothServiceStubDispatch {
        public:
            static bool Accept(WebBluetoothService* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message);
            static bool AcceptWithResponder(WebBluetoothService* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder);
        };

        template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<WebBluetoothService>>
        class WebBluetoothServiceStub
            : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
        public:
            using ImplPointerType = typename ImplRefTraits::PointerType;

            WebBluetoothServiceStub() { }
            ~WebBluetoothServiceStub() override { }

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
                return WebBluetoothServiceStubDispatch::Accept(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
            }

            bool AcceptWithResponder(
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder) override
            {
                if (ImplRefTraits::IsNull(sink_))
                    return false;
                return WebBluetoothServiceStubDispatch::AcceptWithResponder(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                    responder);
            }

        private:
            ImplPointerType sink_;
            mojo::internal::SerializationContext serialization_context_;
        };
        class BLINK_PLATFORM_EXPORT WebBluetoothServiceClientStubDispatch {
        public:
            static bool Accept(WebBluetoothServiceClient* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message);
            static bool AcceptWithResponder(WebBluetoothServiceClient* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder);
        };

        template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<WebBluetoothServiceClient>>
        class WebBluetoothServiceClientStub
            : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
        public:
            using ImplPointerType = typename ImplRefTraits::PointerType;

            WebBluetoothServiceClientStub() { }
            ~WebBluetoothServiceClientStub() override { }

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
                return WebBluetoothServiceClientStubDispatch::Accept(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
            }

            bool AcceptWithResponder(
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder) override
            {
                if (ImplRefTraits::IsNull(sink_))
                    return false;
                return WebBluetoothServiceClientStubDispatch::AcceptWithResponder(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                    responder);
            }

        private:
            ImplPointerType sink_;
            mojo::internal::SerializationContext serialization_context_;
        };
        class BLINK_PLATFORM_EXPORT WebBluetoothServiceRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };
        class BLINK_PLATFORM_EXPORT WebBluetoothServiceClientRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };
        class BLINK_PLATFORM_EXPORT WebBluetoothServiceResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };

        class BLINK_PLATFORM_EXPORT WebBluetoothDeviceId {
        public:
            using DataView = WebBluetoothDeviceIdDataView;
            using Data_ = internal::WebBluetoothDeviceId_Data;

            static WebBluetoothDeviceIdPtr New();

            template <typename U>
            static WebBluetoothDeviceIdPtr From(const U& u)
            {
                return mojo::TypeConverter<WebBluetoothDeviceIdPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, WebBluetoothDeviceId>::Convert(*this);
            }

            WebBluetoothDeviceId();
            ~WebBluetoothDeviceId();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = WebBluetoothDeviceIdPtr>
            WebBluetoothDeviceIdPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, WebBluetoothDeviceId>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    WebBluetoothDeviceId::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    WebBluetoothDeviceId::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            WTF::String device_id;
        };

        class BLINK_PLATFORM_EXPORT WebBluetoothScanFilter {
        public:
            using DataView = WebBluetoothScanFilterDataView;
            using Data_ = internal::WebBluetoothScanFilter_Data;

            static WebBluetoothScanFilterPtr New();

            template <typename U>
            static WebBluetoothScanFilterPtr From(const U& u)
            {
                return mojo::TypeConverter<WebBluetoothScanFilterPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, WebBluetoothScanFilter>::Convert(*this);
            }

            WebBluetoothScanFilter();
            ~WebBluetoothScanFilter();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = WebBluetoothScanFilterPtr>
            WebBluetoothScanFilterPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, WebBluetoothScanFilter>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    WebBluetoothScanFilter::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    WebBluetoothScanFilter::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            WTF::Optional<WTF::Vector<WTF::String>> services;
            WTF::String name;
            WTF::String name_prefix;
        };

        class BLINK_PLATFORM_EXPORT WebBluetoothRequestDeviceOptions {
        public:
            using DataView = WebBluetoothRequestDeviceOptionsDataView;
            using Data_ = internal::WebBluetoothRequestDeviceOptions_Data;

            static WebBluetoothRequestDeviceOptionsPtr New();

            template <typename U>
            static WebBluetoothRequestDeviceOptionsPtr From(const U& u)
            {
                return mojo::TypeConverter<WebBluetoothRequestDeviceOptionsPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, WebBluetoothRequestDeviceOptions>::Convert(*this);
            }

            WebBluetoothRequestDeviceOptions();
            ~WebBluetoothRequestDeviceOptions();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = WebBluetoothRequestDeviceOptionsPtr>
            WebBluetoothRequestDeviceOptionsPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, WebBluetoothRequestDeviceOptions>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    WebBluetoothRequestDeviceOptions::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    WebBluetoothRequestDeviceOptions::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            WTF::Optional<WTF::Vector<WebBluetoothScanFilterPtr>> filters;
            WTF::Vector<WTF::String> optional_services;
            bool accept_all_devices;

        private:
            DISALLOW_COPY_AND_ASSIGN(WebBluetoothRequestDeviceOptions);
        };

        class BLINK_PLATFORM_EXPORT WebBluetoothDevice {
        public:
            using DataView = WebBluetoothDeviceDataView;
            using Data_ = internal::WebBluetoothDevice_Data;

            static WebBluetoothDevicePtr New();

            template <typename U>
            static WebBluetoothDevicePtr From(const U& u)
            {
                return mojo::TypeConverter<WebBluetoothDevicePtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, WebBluetoothDevice>::Convert(*this);
            }

            WebBluetoothDevice();
            ~WebBluetoothDevice();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = WebBluetoothDevicePtr>
            WebBluetoothDevicePtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, WebBluetoothDevice>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    WebBluetoothDevice::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    WebBluetoothDevice::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            WTF::String id;
            WTF::String name;
        };

        class BLINK_PLATFORM_EXPORT WebBluetoothRemoteGATTService {
        public:
            using DataView = WebBluetoothRemoteGATTServiceDataView;
            using Data_ = internal::WebBluetoothRemoteGATTService_Data;

            static WebBluetoothRemoteGATTServicePtr New();

            template <typename U>
            static WebBluetoothRemoteGATTServicePtr From(const U& u)
            {
                return mojo::TypeConverter<WebBluetoothRemoteGATTServicePtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, WebBluetoothRemoteGATTService>::Convert(*this);
            }

            WebBluetoothRemoteGATTService();
            ~WebBluetoothRemoteGATTService();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = WebBluetoothRemoteGATTServicePtr>
            WebBluetoothRemoteGATTServicePtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, WebBluetoothRemoteGATTService>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    WebBluetoothRemoteGATTService::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    WebBluetoothRemoteGATTService::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            WTF::String instance_id;
            WTF::String uuid;
        };

        class BLINK_PLATFORM_EXPORT WebBluetoothRemoteGATTCharacteristic {
        public:
            using DataView = WebBluetoothRemoteGATTCharacteristicDataView;
            using Data_ = internal::WebBluetoothRemoteGATTCharacteristic_Data;

            static WebBluetoothRemoteGATTCharacteristicPtr New();

            template <typename U>
            static WebBluetoothRemoteGATTCharacteristicPtr From(const U& u)
            {
                return mojo::TypeConverter<WebBluetoothRemoteGATTCharacteristicPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, WebBluetoothRemoteGATTCharacteristic>::Convert(*this);
            }

            WebBluetoothRemoteGATTCharacteristic();
            ~WebBluetoothRemoteGATTCharacteristic();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = WebBluetoothRemoteGATTCharacteristicPtr>
            WebBluetoothRemoteGATTCharacteristicPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, WebBluetoothRemoteGATTCharacteristic>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    WebBluetoothRemoteGATTCharacteristic::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    WebBluetoothRemoteGATTCharacteristic::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            WTF::String instance_id;
            WTF::String uuid;
            uint32_t properties;
        };

        class BLINK_PLATFORM_EXPORT WebBluetoothRemoteGATTDescriptor {
        public:
            using DataView = WebBluetoothRemoteGATTDescriptorDataView;
            using Data_ = internal::WebBluetoothRemoteGATTDescriptor_Data;

            static WebBluetoothRemoteGATTDescriptorPtr New();

            template <typename U>
            static WebBluetoothRemoteGATTDescriptorPtr From(const U& u)
            {
                return mojo::TypeConverter<WebBluetoothRemoteGATTDescriptorPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, WebBluetoothRemoteGATTDescriptor>::Convert(*this);
            }

            WebBluetoothRemoteGATTDescriptor();
            ~WebBluetoothRemoteGATTDescriptor();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = WebBluetoothRemoteGATTDescriptorPtr>
            WebBluetoothRemoteGATTDescriptorPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, WebBluetoothRemoteGATTDescriptor>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    WebBluetoothRemoteGATTDescriptor::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    WebBluetoothRemoteGATTDescriptor::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            WTF::String instance_id;
            WTF::String uuid;
        };

        template <typename StructPtrType>
        WebBluetoothScanFilterPtr WebBluetoothScanFilter::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->services = mojo::internal::Clone(services);
            rv->name = mojo::internal::Clone(name);
            rv->name_prefix = mojo::internal::Clone(name_prefix);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, WebBluetoothScanFilter>::value>::type*>
        bool WebBluetoothScanFilter::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->services, other.services))
                return false;
            if (!mojo::internal::Equals(this->name, other.name))
                return false;
            if (!mojo::internal::Equals(this->name_prefix, other.name_prefix))
                return false;
            return true;
        }
        template <typename StructPtrType>
        WebBluetoothRequestDeviceOptionsPtr WebBluetoothRequestDeviceOptions::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->filters = mojo::internal::Clone(filters);
            rv->optional_services = mojo::internal::Clone(optional_services);
            rv->accept_all_devices = mojo::internal::Clone(accept_all_devices);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, WebBluetoothRequestDeviceOptions>::value>::type*>
        bool WebBluetoothRequestDeviceOptions::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->filters, other.filters))
                return false;
            if (!mojo::internal::Equals(this->optional_services, other.optional_services))
                return false;
            if (!mojo::internal::Equals(this->accept_all_devices, other.accept_all_devices))
                return false;
            return true;
        }
        template <typename StructPtrType>
        WebBluetoothDeviceIdPtr WebBluetoothDeviceId::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->device_id = mojo::internal::Clone(device_id);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, WebBluetoothDeviceId>::value>::type*>
        bool WebBluetoothDeviceId::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->device_id, other.device_id))
                return false;
            return true;
        }
        template <typename StructPtrType>
        WebBluetoothDevicePtr WebBluetoothDevice::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->id = mojo::internal::Clone(id);
            rv->name = mojo::internal::Clone(name);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, WebBluetoothDevice>::value>::type*>
        bool WebBluetoothDevice::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->id, other.id))
                return false;
            if (!mojo::internal::Equals(this->name, other.name))
                return false;
            return true;
        }
        template <typename StructPtrType>
        WebBluetoothRemoteGATTServicePtr WebBluetoothRemoteGATTService::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->instance_id = mojo::internal::Clone(instance_id);
            rv->uuid = mojo::internal::Clone(uuid);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, WebBluetoothRemoteGATTService>::value>::type*>
        bool WebBluetoothRemoteGATTService::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->instance_id, other.instance_id))
                return false;
            if (!mojo::internal::Equals(this->uuid, other.uuid))
                return false;
            return true;
        }
        template <typename StructPtrType>
        WebBluetoothRemoteGATTCharacteristicPtr WebBluetoothRemoteGATTCharacteristic::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->instance_id = mojo::internal::Clone(instance_id);
            rv->uuid = mojo::internal::Clone(uuid);
            rv->properties = mojo::internal::Clone(properties);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, WebBluetoothRemoteGATTCharacteristic>::value>::type*>
        bool WebBluetoothRemoteGATTCharacteristic::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->instance_id, other.instance_id))
                return false;
            if (!mojo::internal::Equals(this->uuid, other.uuid))
                return false;
            if (!mojo::internal::Equals(this->properties, other.properties))
                return false;
            return true;
        }
        template <typename StructPtrType>
        WebBluetoothRemoteGATTDescriptorPtr WebBluetoothRemoteGATTDescriptor::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->instance_id = mojo::internal::Clone(instance_id);
            rv->uuid = mojo::internal::Clone(uuid);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, WebBluetoothRemoteGATTDescriptor>::value>::type*>
        bool WebBluetoothRemoteGATTDescriptor::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->instance_id, other.instance_id))
                return false;
            if (!mojo::internal::Equals(this->uuid, other.uuid))
                return false;
            return true;
        }

    } // namespace blink
} // namespace mojom
} // namespace blink

namespace mojo {

template <>
struct BLINK_PLATFORM_EXPORT StructTraits<::blink::mojom::blink::WebBluetoothScanFilter::DataView,
    ::blink::mojom::blink::WebBluetoothScanFilterPtr> {
    static bool IsNull(const ::blink::mojom::blink::WebBluetoothScanFilterPtr& input) { return !input; }
    static void SetToNull(::blink::mojom::blink::WebBluetoothScanFilterPtr* output) { output->reset(); }

    static const decltype(::blink::mojom::blink::WebBluetoothScanFilter::services)& services(
        const ::blink::mojom::blink::WebBluetoothScanFilterPtr& input)
    {
        return input->services;
    }

    static const decltype(::blink::mojom::blink::WebBluetoothScanFilter::name)& name(
        const ::blink::mojom::blink::WebBluetoothScanFilterPtr& input)
    {
        return input->name;
    }

    static const decltype(::blink::mojom::blink::WebBluetoothScanFilter::name_prefix)& name_prefix(
        const ::blink::mojom::blink::WebBluetoothScanFilterPtr& input)
    {
        return input->name_prefix;
    }

    static bool Read(::blink::mojom::blink::WebBluetoothScanFilter::DataView input, ::blink::mojom::blink::WebBluetoothScanFilterPtr* output);
};

template <>
struct BLINK_PLATFORM_EXPORT StructTraits<::blink::mojom::blink::WebBluetoothRequestDeviceOptions::DataView,
    ::blink::mojom::blink::WebBluetoothRequestDeviceOptionsPtr> {
    static bool IsNull(const ::blink::mojom::blink::WebBluetoothRequestDeviceOptionsPtr& input) { return !input; }
    static void SetToNull(::blink::mojom::blink::WebBluetoothRequestDeviceOptionsPtr* output) { output->reset(); }

    static const decltype(::blink::mojom::blink::WebBluetoothRequestDeviceOptions::filters)& filters(
        const ::blink::mojom::blink::WebBluetoothRequestDeviceOptionsPtr& input)
    {
        return input->filters;
    }

    static const decltype(::blink::mojom::blink::WebBluetoothRequestDeviceOptions::optional_services)& optional_services(
        const ::blink::mojom::blink::WebBluetoothRequestDeviceOptionsPtr& input)
    {
        return input->optional_services;
    }

    static decltype(::blink::mojom::blink::WebBluetoothRequestDeviceOptions::accept_all_devices) accept_all_devices(
        const ::blink::mojom::blink::WebBluetoothRequestDeviceOptionsPtr& input)
    {
        return input->accept_all_devices;
    }

    static bool Read(::blink::mojom::blink::WebBluetoothRequestDeviceOptions::DataView input, ::blink::mojom::blink::WebBluetoothRequestDeviceOptionsPtr* output);
};

template <>
struct BLINK_PLATFORM_EXPORT StructTraits<::blink::mojom::blink::WebBluetoothDeviceId::DataView,
    ::blink::mojom::blink::WebBluetoothDeviceIdPtr> {
    static bool IsNull(const ::blink::mojom::blink::WebBluetoothDeviceIdPtr& input) { return !input; }
    static void SetToNull(::blink::mojom::blink::WebBluetoothDeviceIdPtr* output) { output->reset(); }

    static const decltype(::blink::mojom::blink::WebBluetoothDeviceId::device_id)& device_id(
        const ::blink::mojom::blink::WebBluetoothDeviceIdPtr& input)
    {
        return input->device_id;
    }

    static bool Read(::blink::mojom::blink::WebBluetoothDeviceId::DataView input, ::blink::mojom::blink::WebBluetoothDeviceIdPtr* output);
};

template <>
struct BLINK_PLATFORM_EXPORT StructTraits<::blink::mojom::blink::WebBluetoothDevice::DataView,
    ::blink::mojom::blink::WebBluetoothDevicePtr> {
    static bool IsNull(const ::blink::mojom::blink::WebBluetoothDevicePtr& input) { return !input; }
    static void SetToNull(::blink::mojom::blink::WebBluetoothDevicePtr* output) { output->reset(); }

    static const decltype(::blink::mojom::blink::WebBluetoothDevice::id)& id(
        const ::blink::mojom::blink::WebBluetoothDevicePtr& input)
    {
        return input->id;
    }

    static const decltype(::blink::mojom::blink::WebBluetoothDevice::name)& name(
        const ::blink::mojom::blink::WebBluetoothDevicePtr& input)
    {
        return input->name;
    }

    static bool Read(::blink::mojom::blink::WebBluetoothDevice::DataView input, ::blink::mojom::blink::WebBluetoothDevicePtr* output);
};

template <>
struct BLINK_PLATFORM_EXPORT StructTraits<::blink::mojom::blink::WebBluetoothRemoteGATTService::DataView,
    ::blink::mojom::blink::WebBluetoothRemoteGATTServicePtr> {
    static bool IsNull(const ::blink::mojom::blink::WebBluetoothRemoteGATTServicePtr& input) { return !input; }
    static void SetToNull(::blink::mojom::blink::WebBluetoothRemoteGATTServicePtr* output) { output->reset(); }

    static const decltype(::blink::mojom::blink::WebBluetoothRemoteGATTService::instance_id)& instance_id(
        const ::blink::mojom::blink::WebBluetoothRemoteGATTServicePtr& input)
    {
        return input->instance_id;
    }

    static const decltype(::blink::mojom::blink::WebBluetoothRemoteGATTService::uuid)& uuid(
        const ::blink::mojom::blink::WebBluetoothRemoteGATTServicePtr& input)
    {
        return input->uuid;
    }

    static bool Read(::blink::mojom::blink::WebBluetoothRemoteGATTService::DataView input, ::blink::mojom::blink::WebBluetoothRemoteGATTServicePtr* output);
};

template <>
struct BLINK_PLATFORM_EXPORT StructTraits<::blink::mojom::blink::WebBluetoothRemoteGATTCharacteristic::DataView,
    ::blink::mojom::blink::WebBluetoothRemoteGATTCharacteristicPtr> {
    static bool IsNull(const ::blink::mojom::blink::WebBluetoothRemoteGATTCharacteristicPtr& input) { return !input; }
    static void SetToNull(::blink::mojom::blink::WebBluetoothRemoteGATTCharacteristicPtr* output) { output->reset(); }

    static const decltype(::blink::mojom::blink::WebBluetoothRemoteGATTCharacteristic::instance_id)& instance_id(
        const ::blink::mojom::blink::WebBluetoothRemoteGATTCharacteristicPtr& input)
    {
        return input->instance_id;
    }

    static const decltype(::blink::mojom::blink::WebBluetoothRemoteGATTCharacteristic::uuid)& uuid(
        const ::blink::mojom::blink::WebBluetoothRemoteGATTCharacteristicPtr& input)
    {
        return input->uuid;
    }

    static decltype(::blink::mojom::blink::WebBluetoothRemoteGATTCharacteristic::properties) properties(
        const ::blink::mojom::blink::WebBluetoothRemoteGATTCharacteristicPtr& input)
    {
        return input->properties;
    }

    static bool Read(::blink::mojom::blink::WebBluetoothRemoteGATTCharacteristic::DataView input, ::blink::mojom::blink::WebBluetoothRemoteGATTCharacteristicPtr* output);
};

template <>
struct BLINK_PLATFORM_EXPORT StructTraits<::blink::mojom::blink::WebBluetoothRemoteGATTDescriptor::DataView,
    ::blink::mojom::blink::WebBluetoothRemoteGATTDescriptorPtr> {
    static bool IsNull(const ::blink::mojom::blink::WebBluetoothRemoteGATTDescriptorPtr& input) { return !input; }
    static void SetToNull(::blink::mojom::blink::WebBluetoothRemoteGATTDescriptorPtr* output) { output->reset(); }

    static const decltype(::blink::mojom::blink::WebBluetoothRemoteGATTDescriptor::instance_id)& instance_id(
        const ::blink::mojom::blink::WebBluetoothRemoteGATTDescriptorPtr& input)
    {
        return input->instance_id;
    }

    static const decltype(::blink::mojom::blink::WebBluetoothRemoteGATTDescriptor::uuid)& uuid(
        const ::blink::mojom::blink::WebBluetoothRemoteGATTDescriptorPtr& input)
    {
        return input->uuid;
    }

    static bool Read(::blink::mojom::blink::WebBluetoothRemoteGATTDescriptor::DataView input, ::blink::mojom::blink::WebBluetoothRemoteGATTDescriptorPtr* output);
};

} // namespace mojo

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_BLUETOOTH_WEB_BLUETOOTH_MOJOM_BLINK_H_