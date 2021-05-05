// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_GENERIC_SENSOR_PUBLIC_INTERFACES_SENSOR_MOJOM_SHARED_H_
#define DEVICE_GENERIC_SENSOR_PUBLIC_INTERFACES_SENSOR_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "device/generic_sensor/public/interfaces/sensor.mojom-shared-internal.h"
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
    class SensorConfigurationDataView;

} // namespace mojom
} // namespace device

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::device::mojom::SensorConfigurationDataView> {
        using Data = ::device::mojom::internal::SensorConfiguration_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace device {
namespace mojom {

    enum class SensorType : int32_t {
        FIRST = 1,
        AMBIENT_LIGHT = SensorType::FIRST,
        PROXIMITY,
        ACCELEROMETER,
        LINEAR_ACCELERATION,
        GYROSCOPE,
        MAGNETOMETER,
        PRESSURE,
        LAST = SensorType::PRESSURE,
    };

    inline std::ostream& operator<<(std::ostream& os, SensorType value)
    {
        switch (value) {
        case SensorType::FIRST:
            return os << "SensorType::{FIRST, AMBIENT_LIGHT}";
        case SensorType::PROXIMITY:
            return os << "SensorType::PROXIMITY";
        case SensorType::ACCELEROMETER:
            return os << "SensorType::ACCELEROMETER";
        case SensorType::LINEAR_ACCELERATION:
            return os << "SensorType::LINEAR_ACCELERATION";
        case SensorType::GYROSCOPE:
            return os << "SensorType::GYROSCOPE";
        case SensorType::MAGNETOMETER:
            return os << "SensorType::MAGNETOMETER";
        case SensorType::PRESSURE:
            return os << "SensorType::{PRESSURE, LAST}";
        default:
            return os << "Unknown SensorType value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(SensorType value)
    {
        return internal::SensorType_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class ReportingMode : int32_t {
        ON_CHANGE,
        CONTINUOUS,
    };

    inline std::ostream& operator<<(std::ostream& os, ReportingMode value)
    {
        switch (value) {
        case ReportingMode::ON_CHANGE:
            return os << "ReportingMode::ON_CHANGE";
        case ReportingMode::CONTINUOUS:
            return os << "ReportingMode::CONTINUOUS";
        default:
            return os << "Unknown ReportingMode value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(ReportingMode value)
    {
        return internal::ReportingMode_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    // Interface base classes. They are used for type safety check.
    class SensorInterfaceBase {
    };

    using SensorPtrDataView = mojo::InterfacePtrDataView<SensorInterfaceBase>;
    using SensorRequestDataView = mojo::InterfaceRequestDataView<SensorInterfaceBase>;
    using SensorAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<SensorInterfaceBase>;
    using SensorAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<SensorInterfaceBase>;
    class SensorClientInterfaceBase {
    };

    using SensorClientPtrDataView = mojo::InterfacePtrDataView<SensorClientInterfaceBase>;
    using SensorClientRequestDataView = mojo::InterfaceRequestDataView<SensorClientInterfaceBase>;
    using SensorClientAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<SensorClientInterfaceBase>;
    using SensorClientAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<SensorClientInterfaceBase>;
    class SensorConfigurationDataView {
    public:
        SensorConfigurationDataView() { }

        SensorConfigurationDataView(
            internal::SensorConfiguration_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        double frequency() const
        {
            return data_->frequency;
        }

    private:
        internal::SensorConfiguration_Data* data_ = nullptr;
    };

    class Sensor_GetDefaultConfiguration_ParamsDataView {
    public:
        Sensor_GetDefaultConfiguration_ParamsDataView() { }

        Sensor_GetDefaultConfiguration_ParamsDataView(
            internal::Sensor_GetDefaultConfiguration_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::Sensor_GetDefaultConfiguration_Params_Data* data_ = nullptr;
    };

    class Sensor_GetDefaultConfiguration_ResponseParamsDataView {
    public:
        Sensor_GetDefaultConfiguration_ResponseParamsDataView() { }

        Sensor_GetDefaultConfiguration_ResponseParamsDataView(
            internal::Sensor_GetDefaultConfiguration_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetConfigurationDataView(
            SensorConfigurationDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadConfiguration(UserType* output)
        {
            auto* pointer = data_->configuration.Get();
            return mojo::internal::Deserialize<::device::mojom::SensorConfigurationDataView>(
                pointer, output, context_);
        }

    private:
        internal::Sensor_GetDefaultConfiguration_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Sensor_AddConfiguration_ParamsDataView {
    public:
        Sensor_AddConfiguration_ParamsDataView() { }

        Sensor_AddConfiguration_ParamsDataView(
            internal::Sensor_AddConfiguration_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetConfigurationDataView(
            SensorConfigurationDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadConfiguration(UserType* output)
        {
            auto* pointer = data_->configuration.Get();
            return mojo::internal::Deserialize<::device::mojom::SensorConfigurationDataView>(
                pointer, output, context_);
        }

    private:
        internal::Sensor_AddConfiguration_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Sensor_AddConfiguration_ResponseParamsDataView {
    public:
        Sensor_AddConfiguration_ResponseParamsDataView() { }

        Sensor_AddConfiguration_ResponseParamsDataView(
            internal::Sensor_AddConfiguration_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool success() const
        {
            return data_->success;
        }

    private:
        internal::Sensor_AddConfiguration_ResponseParams_Data* data_ = nullptr;
    };

    class Sensor_RemoveConfiguration_ParamsDataView {
    public:
        Sensor_RemoveConfiguration_ParamsDataView() { }

        Sensor_RemoveConfiguration_ParamsDataView(
            internal::Sensor_RemoveConfiguration_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetConfigurationDataView(
            SensorConfigurationDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadConfiguration(UserType* output)
        {
            auto* pointer = data_->configuration.Get();
            return mojo::internal::Deserialize<::device::mojom::SensorConfigurationDataView>(
                pointer, output, context_);
        }

    private:
        internal::Sensor_RemoveConfiguration_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Sensor_RemoveConfiguration_ResponseParamsDataView {
    public:
        Sensor_RemoveConfiguration_ResponseParamsDataView() { }

        Sensor_RemoveConfiguration_ResponseParamsDataView(
            internal::Sensor_RemoveConfiguration_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool success() const
        {
            return data_->success;
        }

    private:
        internal::Sensor_RemoveConfiguration_ResponseParams_Data* data_ = nullptr;
    };

    class Sensor_Suspend_ParamsDataView {
    public:
        Sensor_Suspend_ParamsDataView() { }

        Sensor_Suspend_ParamsDataView(
            internal::Sensor_Suspend_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::Sensor_Suspend_Params_Data* data_ = nullptr;
    };

    class Sensor_Resume_ParamsDataView {
    public:
        Sensor_Resume_ParamsDataView() { }

        Sensor_Resume_ParamsDataView(
            internal::Sensor_Resume_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::Sensor_Resume_Params_Data* data_ = nullptr;
    };

    class SensorClient_RaiseError_ParamsDataView {
    public:
        SensorClient_RaiseError_ParamsDataView() { }

        SensorClient_RaiseError_ParamsDataView(
            internal::SensorClient_RaiseError_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::SensorClient_RaiseError_Params_Data* data_ = nullptr;
    };

    class SensorClient_SensorReadingChanged_ParamsDataView {
    public:
        SensorClient_SensorReadingChanged_ParamsDataView() { }

        SensorClient_SensorReadingChanged_ParamsDataView(
            internal::SensorClient_SensorReadingChanged_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::SensorClient_SensorReadingChanged_Params_Data* data_ = nullptr;
    };

} // namespace mojom
} // namespace device

namespace std {

template <>
struct hash<::device::mojom::SensorType>
    : public mojo::internal::EnumHashImpl<::device::mojom::SensorType> {
};

template <>
struct hash<::device::mojom::ReportingMode>
    : public mojo::internal::EnumHashImpl<::device::mojom::ReportingMode> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::device::mojom::SensorType, ::device::mojom::SensorType> {
    static ::device::mojom::SensorType ToMojom(::device::mojom::SensorType input) { return input; }
    static bool FromMojom(::device::mojom::SensorType input, ::device::mojom::SensorType* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::mojom::SensorType, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::device::mojom::SensorType, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::device::mojom::SensorType>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::device::mojom::ReportingMode, ::device::mojom::ReportingMode> {
    static ::device::mojom::ReportingMode ToMojom(::device::mojom::ReportingMode input) { return input; }
    static bool FromMojom(::device::mojom::ReportingMode input, ::device::mojom::ReportingMode* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::mojom::ReportingMode, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::device::mojom::ReportingMode, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::device::mojom::ReportingMode>(input), output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::mojom::SensorConfigurationDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::device::mojom::SensorConfigurationDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::device::mojom::internal::SensorConfiguration_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::device::mojom::internal::SensorConfiguration_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::device::mojom::internal::SensorConfiguration_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->frequency = CallWithContext(Traits::frequency, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::device::mojom::internal::SensorConfiguration_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::device::mojom::SensorConfigurationDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace device {
namespace mojom {

    inline void Sensor_GetDefaultConfiguration_ResponseParamsDataView::GetConfigurationDataView(
        SensorConfigurationDataView* output)
    {
        auto pointer = data_->configuration.Get();
        *output = SensorConfigurationDataView(pointer, context_);
    }

    inline void Sensor_AddConfiguration_ParamsDataView::GetConfigurationDataView(
        SensorConfigurationDataView* output)
    {
        auto pointer = data_->configuration.Get();
        *output = SensorConfigurationDataView(pointer, context_);
    }

    inline void Sensor_RemoveConfiguration_ParamsDataView::GetConfigurationDataView(
        SensorConfigurationDataView* output)
    {
        auto pointer = data_->configuration.Get();
        *output = SensorConfigurationDataView(pointer, context_);
    }

} // namespace mojom
} // namespace device

#endif // DEVICE_GENERIC_SENSOR_PUBLIC_INTERFACES_SENSOR_MOJOM_SHARED_H_
