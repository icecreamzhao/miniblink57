// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_GENERIC_SENSOR_PUBLIC_INTERFACES_SENSOR_PROVIDER_MOJOM_BLINK_H_
#define DEVICE_GENERIC_SENSOR_PUBLIC_INTERFACES_SENSOR_PROVIDER_MOJOM_BLINK_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "device/generic_sensor/public/interfaces/sensor.mojom-blink.h"
#include "device/generic_sensor/public/interfaces/sensor_provider.mojom-shared.h"
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
        class SensorProvider;
        using SensorProviderPtr = mojo::InterfacePtr<SensorProvider>;
        using SensorProviderPtrInfo = mojo::InterfacePtrInfo<SensorProvider>;
        using ThreadSafeSensorProviderPtr = mojo::ThreadSafeInterfacePtr<SensorProvider>;
        using SensorProviderRequest = mojo::InterfaceRequest<SensorProvider>;
        using SensorProviderAssociatedPtr = mojo::AssociatedInterfacePtr<SensorProvider>;
        using ThreadSafeSensorProviderAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<SensorProvider>;
        using SensorProviderAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<SensorProvider>;
        using SensorProviderAssociatedRequest = mojo::AssociatedInterfaceRequest<SensorProvider>;

        class SensorInitParams;
        using SensorInitParamsPtr = mojo::StructPtr<SensorInitParams>;

        class SensorProviderProxy;

        template <typename ImplRefTraits>
        class SensorProviderStub;

        class SensorProviderRequestValidator;
        class SensorProviderResponseValidator;

        class SensorProvider
            : public SensorProviderInterfaceBase {
        public:
            static const char Name_[];
            static constexpr uint32_t Version_ = 0;
            static constexpr bool PassesAssociatedKinds_ = false;
            static constexpr bool HasSyncMethods_ = false;

            using Proxy_ = SensorProviderProxy;

            template <typename ImplRefTraits>
            using Stub_ = SensorProviderStub<ImplRefTraits>;

            using RequestValidator_ = SensorProviderRequestValidator;
            using ResponseValidator_ = SensorProviderResponseValidator;
            enum MethodMinVersions : uint32_t {
                kGetSensorMinVersion = 0,
            };
            virtual ~SensorProvider() { }

            using GetSensorCallback = base::Callback<void(SensorInitParamsPtr, ::device::mojom::blink::SensorClientRequest)>;
            virtual void GetSensor(::device::mojom::blink::SensorType type, ::device::mojom::blink::SensorRequest sensor_request, const GetSensorCallback& callback) = 0;
        };

        class SensorProviderProxy
            : public SensorProvider {
        public:
            explicit SensorProviderProxy(mojo::MessageReceiverWithResponder* receiver);
            void GetSensor(::device::mojom::blink::SensorType type, ::device::mojom::blink::SensorRequest sensor_request, const GetSensorCallback& callback) override;

            void set_group_controller(
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
            {
                group_controller_ = std::move(group_controller);
            }

        private:
            mojo::MessageReceiverWithResponder* receiver_;
            scoped_refptr<mojo::AssociatedGroupController> group_controller_;
        };
        class SensorProviderStubDispatch {
        public:
            static bool Accept(SensorProvider* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message);
            static bool AcceptWithResponder(SensorProvider* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder);
        };

        template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<SensorProvider>>
        class SensorProviderStub
            : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
        public:
            using ImplPointerType = typename ImplRefTraits::PointerType;

            SensorProviderStub() { }
            ~SensorProviderStub() override { }

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
                return SensorProviderStubDispatch::Accept(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
            }

            bool AcceptWithResponder(
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder) override
            {
                if (ImplRefTraits::IsNull(sink_))
                    return false;
                return SensorProviderStubDispatch::AcceptWithResponder(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                    responder);
            }

        private:
            ImplPointerType sink_;
            mojo::internal::SerializationContext serialization_context_;
        };
        class SensorProviderRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };
        class SensorProviderResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };

        class SensorInitParams {
        public:
            using DataView = SensorInitParamsDataView;
            using Data_ = internal::SensorInitParams_Data;
            static constexpr uint64_t kReadBufferSizeForTests = 40ULL;

            static SensorInitParamsPtr New();

            template <typename U>
            static SensorInitParamsPtr From(const U& u)
            {
                return mojo::TypeConverter<SensorInitParamsPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, SensorInitParams>::Convert(*this);
            }

            SensorInitParams();
            ~SensorInitParams();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = SensorInitParamsPtr>
            SensorInitParamsPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, SensorInitParams>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    SensorInitParams::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    SensorInitParams::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            mojo::ScopedSharedBufferHandle memory;
            uint64_t buffer_offset;
            ::device::mojom::blink::ReportingMode mode;
            ::device::mojom::blink::SensorConfigurationPtr default_configuration;
            double maximum_frequency;

        private:
            DISALLOW_COPY_AND_ASSIGN(SensorInitParams);
        };

        template <typename StructPtrType>
        SensorInitParamsPtr SensorInitParams::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->memory = mojo::internal::Clone(memory);
            rv->buffer_offset = mojo::internal::Clone(buffer_offset);
            rv->mode = mojo::internal::Clone(mode);
            rv->default_configuration = mojo::internal::Clone(default_configuration);
            rv->maximum_frequency = mojo::internal::Clone(maximum_frequency);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, SensorInitParams>::value>::type*>
        bool SensorInitParams::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->memory, other.memory))
                return false;
            if (!mojo::internal::Equals(this->buffer_offset, other.buffer_offset))
                return false;
            if (!mojo::internal::Equals(this->mode, other.mode))
                return false;
            if (!mojo::internal::Equals(this->default_configuration, other.default_configuration))
                return false;
            if (!mojo::internal::Equals(this->maximum_frequency, other.maximum_frequency))
                return false;
            return true;
        }

    } // namespace blink
} // namespace mojom
} // namespace device

namespace mojo {

template <>
struct StructTraits<::device::mojom::blink::SensorInitParams::DataView,
    ::device::mojom::blink::SensorInitParamsPtr> {
    static bool IsNull(const ::device::mojom::blink::SensorInitParamsPtr& input) { return !input; }
    static void SetToNull(::device::mojom::blink::SensorInitParamsPtr* output) { output->reset(); }

    static decltype(::device::mojom::blink::SensorInitParams::memory)& memory(
        ::device::mojom::blink::SensorInitParamsPtr& input)
    {
        return input->memory;
    }

    static decltype(::device::mojom::blink::SensorInitParams::buffer_offset) buffer_offset(
        const ::device::mojom::blink::SensorInitParamsPtr& input)
    {
        return input->buffer_offset;
    }

    static decltype(::device::mojom::blink::SensorInitParams::mode) mode(
        const ::device::mojom::blink::SensorInitParamsPtr& input)
    {
        return input->mode;
    }

    static const decltype(::device::mojom::blink::SensorInitParams::default_configuration)& default_configuration(
        const ::device::mojom::blink::SensorInitParamsPtr& input)
    {
        return input->default_configuration;
    }

    static decltype(::device::mojom::blink::SensorInitParams::maximum_frequency) maximum_frequency(
        const ::device::mojom::blink::SensorInitParamsPtr& input)
    {
        return input->maximum_frequency;
    }

    static bool Read(::device::mojom::blink::SensorInitParams::DataView input, ::device::mojom::blink::SensorInitParamsPtr* output);
};

} // namespace mojo

#endif // DEVICE_GENERIC_SENSOR_PUBLIC_INTERFACES_SENSOR_PROVIDER_MOJOM_BLINK_H_