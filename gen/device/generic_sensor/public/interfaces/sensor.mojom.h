// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_GENERIC_SENSOR_PUBLIC_INTERFACES_SENSOR_MOJOM_H_
#define DEVICE_GENERIC_SENSOR_PUBLIC_INTERFACES_SENSOR_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "device/generic_sensor/public/cpp/generic_sensor_public_export.h"
#include "device/generic_sensor/public/cpp/platform_sensor_configuration.h"
#include "device/generic_sensor/public/interfaces/sensor.mojom-shared.h"
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
    class Sensor;
    using SensorPtr = mojo::InterfacePtr<Sensor>;
    using SensorPtrInfo = mojo::InterfacePtrInfo<Sensor>;
    using ThreadSafeSensorPtr = mojo::ThreadSafeInterfacePtr<Sensor>;
    using SensorRequest = mojo::InterfaceRequest<Sensor>;
    using SensorAssociatedPtr = mojo::AssociatedInterfacePtr<Sensor>;
    using ThreadSafeSensorAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<Sensor>;
    using SensorAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<Sensor>;
    using SensorAssociatedRequest = mojo::AssociatedInterfaceRequest<Sensor>;

    class SensorClient;
    using SensorClientPtr = mojo::InterfacePtr<SensorClient>;
    using SensorClientPtrInfo = mojo::InterfacePtrInfo<SensorClient>;
    using ThreadSafeSensorClientPtr = mojo::ThreadSafeInterfacePtr<SensorClient>;
    using SensorClientRequest = mojo::InterfaceRequest<SensorClient>;
    using SensorClientAssociatedPtr = mojo::AssociatedInterfacePtr<SensorClient>;
    using ThreadSafeSensorClientAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<SensorClient>;
    using SensorClientAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<SensorClient>;
    using SensorClientAssociatedRequest = mojo::AssociatedInterfaceRequest<SensorClient>;

    class SensorConfiguration;
    using SensorConfigurationPtr = mojo::InlinedStructPtr<SensorConfiguration>;

    class SensorProxy;

    template <typename ImplRefTraits>
    class SensorStub;

    class SensorRequestValidator;
    class SensorResponseValidator;

    class DEVICE_GENERIC_SENSOR_PUBLIC_EXPORT Sensor
        : public SensorInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = SensorProxy;

        template <typename ImplRefTraits>
        using Stub_ = SensorStub<ImplRefTraits>;

        using RequestValidator_ = SensorRequestValidator;
        using ResponseValidator_ = SensorResponseValidator;
        enum MethodMinVersions : uint32_t {
            kGetDefaultConfigurationMinVersion = 0,
            kAddConfigurationMinVersion = 0,
            kRemoveConfigurationMinVersion = 0,
            kSuspendMinVersion = 0,
            kResumeMinVersion = 0,
        };
        virtual ~Sensor() { }

        using GetDefaultConfigurationCallback = base::Callback<void(const device::PlatformSensorConfiguration&)>;
        virtual void GetDefaultConfiguration(const GetDefaultConfigurationCallback& callback) = 0;

        using AddConfigurationCallback = base::Callback<void(bool)>;
        virtual void AddConfiguration(const device::PlatformSensorConfiguration& configuration, const AddConfigurationCallback& callback) = 0;

        using RemoveConfigurationCallback = base::Callback<void(bool)>;
        virtual void RemoveConfiguration(const device::PlatformSensorConfiguration& configuration, const RemoveConfigurationCallback& callback) = 0;

        virtual void Suspend() = 0;

        virtual void Resume() = 0;
    };

    class SensorClientProxy;

    template <typename ImplRefTraits>
    class SensorClientStub;

    class SensorClientRequestValidator;

    class DEVICE_GENERIC_SENSOR_PUBLIC_EXPORT SensorClient
        : public SensorClientInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = SensorClientProxy;

        template <typename ImplRefTraits>
        using Stub_ = SensorClientStub<ImplRefTraits>;

        using RequestValidator_ = SensorClientRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kRaiseErrorMinVersion = 0,
            kSensorReadingChangedMinVersion = 0,
        };
        virtual ~SensorClient() { }

        virtual void RaiseError() = 0;

        virtual void SensorReadingChanged() = 0;
    };

    class DEVICE_GENERIC_SENSOR_PUBLIC_EXPORT SensorProxy
        : public Sensor {
    public:
        explicit SensorProxy(mojo::MessageReceiverWithResponder* receiver);
        void GetDefaultConfiguration(const GetDefaultConfigurationCallback& callback) override;
        void AddConfiguration(const device::PlatformSensorConfiguration& configuration, const AddConfigurationCallback& callback) override;
        void RemoveConfiguration(const device::PlatformSensorConfiguration& configuration, const RemoveConfigurationCallback& callback) override;
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

    class DEVICE_GENERIC_SENSOR_PUBLIC_EXPORT SensorClientProxy
        : public SensorClient {
    public:
        explicit SensorClientProxy(mojo::MessageReceiverWithResponder* receiver);
        void RaiseError() override;
        void SensorReadingChanged() override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class DEVICE_GENERIC_SENSOR_PUBLIC_EXPORT SensorStubDispatch {
    public:
        static bool Accept(Sensor* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(Sensor* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<Sensor>>
    class SensorStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        SensorStub() { }
        ~SensorStub() override { }

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
            return SensorStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return SensorStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class DEVICE_GENERIC_SENSOR_PUBLIC_EXPORT SensorClientStubDispatch {
    public:
        static bool Accept(SensorClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(SensorClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<SensorClient>>
    class SensorClientStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        SensorClientStub() { }
        ~SensorClientStub() override { }

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
            return SensorClientStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return SensorClientStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class DEVICE_GENERIC_SENSOR_PUBLIC_EXPORT SensorRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class DEVICE_GENERIC_SENSOR_PUBLIC_EXPORT SensorClientRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class DEVICE_GENERIC_SENSOR_PUBLIC_EXPORT SensorResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

    class DEVICE_GENERIC_SENSOR_PUBLIC_EXPORT SensorConfiguration {
    public:
        using DataView = SensorConfigurationDataView;
        using Data_ = internal::SensorConfiguration_Data;
        static constexpr double kMaxAllowedFrequency = 60.0;

        static SensorConfigurationPtr New();

        template <typename U>
        static SensorConfigurationPtr From(const U& u)
        {
            return mojo::TypeConverter<SensorConfigurationPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, SensorConfiguration>::Convert(*this);
        }

        SensorConfiguration();
        ~SensorConfiguration();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = SensorConfigurationPtr>
        SensorConfigurationPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, SensorConfiguration>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                SensorConfiguration::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                SensorConfiguration::DataView, std::vector<uint8_t>>(
                input, output);
        }

        double frequency;
    };

    template <typename StructPtrType>
    SensorConfigurationPtr SensorConfiguration::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->frequency = mojo::internal::Clone(frequency);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, SensorConfiguration>::value>::type*>
    bool SensorConfiguration::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->frequency, other.frequency))
            return false;
        return true;
    }

} // namespace mojom
} // namespace device

namespace mojo {

template <>
struct DEVICE_GENERIC_SENSOR_PUBLIC_EXPORT StructTraits<::device::mojom::SensorConfiguration::DataView,
    ::device::mojom::SensorConfigurationPtr> {
    static bool IsNull(const ::device::mojom::SensorConfigurationPtr& input) { return !input; }
    static void SetToNull(::device::mojom::SensorConfigurationPtr* output) { output->reset(); }

    static decltype(::device::mojom::SensorConfiguration::frequency) frequency(
        const ::device::mojom::SensorConfigurationPtr& input)
    {
        return input->frequency;
    }

    static bool Read(::device::mojom::SensorConfiguration::DataView input, ::device::mojom::SensorConfigurationPtr* output);
};

} // namespace mojo

#endif // DEVICE_GENERIC_SENSOR_PUBLIC_INTERFACES_SENSOR_MOJOM_H_