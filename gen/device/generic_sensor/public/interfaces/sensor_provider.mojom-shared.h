// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_GENERIC_SENSOR_PUBLIC_INTERFACES_SENSOR_PROVIDER_MOJOM_SHARED_H_
#define DEVICE_GENERIC_SENSOR_PUBLIC_INTERFACES_SENSOR_PROVIDER_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "device/generic_sensor/public/interfaces/sensor.mojom-shared.h"
#include "device/generic_sensor/public/interfaces/sensor_provider.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"

namespace device {
namespace mojom {
    class SensorInitParamsDataView;

} // namespace mojom
} // namespace device

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::device::mojom::SensorInitParamsDataView> {
        using Data = ::device::mojom::internal::SensorInitParams_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace device {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class SensorProviderInterfaceBase {
    };

    using SensorProviderPtrDataView = mojo::InterfacePtrDataView<SensorProviderInterfaceBase>;
    using SensorProviderRequestDataView = mojo::InterfaceRequestDataView<SensorProviderInterfaceBase>;
    using SensorProviderAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<SensorProviderInterfaceBase>;
    using SensorProviderAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<SensorProviderInterfaceBase>;
    class SensorInitParamsDataView {
    public:
        SensorInitParamsDataView() { }

        SensorInitParamsDataView(
            internal::SensorInitParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        mojo::ScopedSharedBufferHandle TakeMemory()
        {
            mojo::ScopedSharedBufferHandle result;
            bool ret = mojo::internal::Deserialize<mojo::ScopedSharedBufferHandle>(
                &data_->memory, &result, context_);
            DCHECK(ret);
            return result;
        }
        uint64_t buffer_offset() const
        {
            return data_->buffer_offset;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMode(UserType* output) const
        {
            auto data_value = data_->mode;
            return mojo::internal::Deserialize<::device::mojom::ReportingMode>(
                data_value, output);
        }

        ::device::mojom::ReportingMode mode() const
        {
            return static_cast<::device::mojom::ReportingMode>(data_->mode);
        }
        inline void GetDefaultConfigurationDataView(
            ::device::mojom::SensorConfigurationDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDefaultConfiguration(UserType* output)
        {
            auto* pointer = data_->default_configuration.Get();
            return mojo::internal::Deserialize<::device::mojom::SensorConfigurationDataView>(
                pointer, output, context_);
        }
        double maximum_frequency() const
        {
            return data_->maximum_frequency;
        }

    private:
        internal::SensorInitParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class SensorProvider_GetSensor_ParamsDataView {
    public:
        SensorProvider_GetSensor_ParamsDataView() { }

        SensorProvider_GetSensor_ParamsDataView(
            internal::SensorProvider_GetSensor_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadType(UserType* output) const
        {
            auto data_value = data_->type;
            return mojo::internal::Deserialize<::device::mojom::SensorType>(
                data_value, output);
        }

        ::device::mojom::SensorType type() const
        {
            return static_cast<::device::mojom::SensorType>(data_->type);
        }
        template <typename UserType>
        UserType TakeSensorRequest()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::device::mojom::SensorRequestDataView>(
                &data_->sensor_request, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::SensorProvider_GetSensor_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class SensorProvider_GetSensor_ResponseParamsDataView {
    public:
        SensorProvider_GetSensor_ResponseParamsDataView() { }

        SensorProvider_GetSensor_ResponseParamsDataView(
            internal::SensorProvider_GetSensor_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetInitParamsDataView(
            SensorInitParamsDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadInitParams(UserType* output)
        {
            auto* pointer = data_->init_params.Get();
            return mojo::internal::Deserialize<::device::mojom::SensorInitParamsDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        UserType TakeClientRequest()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::device::mojom::SensorClientRequestDataView>(
                &data_->client_request, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::SensorProvider_GetSensor_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace device

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::mojom::SensorInitParamsDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::device::mojom::SensorInitParamsDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::device::mojom::internal::SensorInitParams_Data);
            decltype(CallWithContext(Traits::default_configuration, input, custom_context)) in_default_configuration = CallWithContext(Traits::default_configuration, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::device::mojom::SensorConfigurationDataView>(
                in_default_configuration, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::device::mojom::internal::SensorInitParams_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::device::mojom::internal::SensorInitParams_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::memory, input, custom_context)) in_memory = CallWithContext(Traits::memory, input, custom_context);
            mojo::internal::Serialize<mojo::ScopedSharedBufferHandle>(
                in_memory, &result->memory, context);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                !mojo::internal::IsHandleOrInterfaceValid(result->memory),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
                "invalid memory in SensorInitParams struct");
            result->buffer_offset = CallWithContext(Traits::buffer_offset, input, custom_context);
            mojo::internal::Serialize<::device::mojom::ReportingMode>(
                CallWithContext(Traits::mode, input, custom_context), &result->mode);
            decltype(CallWithContext(Traits::default_configuration, input, custom_context)) in_default_configuration = CallWithContext(Traits::default_configuration, input, custom_context);
            typename decltype(result->default_configuration)::BaseType* default_configuration_ptr;
            mojo::internal::Serialize<::device::mojom::SensorConfigurationDataView>(
                in_default_configuration, buffer, &default_configuration_ptr, context);
            result->default_configuration.Set(default_configuration_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->default_configuration.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null default_configuration in SensorInitParams struct");
            result->maximum_frequency = CallWithContext(Traits::maximum_frequency, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::device::mojom::internal::SensorInitParams_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::device::mojom::SensorInitParamsDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace device {
namespace mojom {

    inline void SensorInitParamsDataView::GetDefaultConfigurationDataView(
        ::device::mojom::SensorConfigurationDataView* output)
    {
        auto pointer = data_->default_configuration.Get();
        *output = ::device::mojom::SensorConfigurationDataView(pointer, context_);
    }

    inline void SensorProvider_GetSensor_ResponseParamsDataView::GetInitParamsDataView(
        SensorInitParamsDataView* output)
    {
        auto pointer = data_->init_params.Get();
        *output = SensorInitParamsDataView(pointer, context_);
    }

} // namespace mojom
} // namespace device

#endif // DEVICE_GENERIC_SENSOR_PUBLIC_INTERFACES_SENSOR_PROVIDER_MOJOM_SHARED_H_
