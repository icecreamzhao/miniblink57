// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_GEOLOCATION_PUBLIC_INTERFACES_GEOLOCATION_MOJOM_SHARED_H_
#define DEVICE_GEOLOCATION_PUBLIC_INTERFACES_GEOLOCATION_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "device/geolocation/public/interfaces/geolocation.mojom-shared-internal.h"
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
    class GeopositionDataView;

} // namespace mojom
} // namespace device

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::device::mojom::GeopositionDataView> {
        using Data = ::device::mojom::internal::Geoposition_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace device {
namespace mojom {

    enum class Geoposition_ErrorCode : int32_t {
        NONE = 0,
        PERMISSION_DENIED = 1,
        POSITION_UNAVAILABLE = 2,
        TIMEOUT = 3,
        LAST = Geoposition_ErrorCode::TIMEOUT,
    };

    inline std::ostream& operator<<(std::ostream& os, Geoposition_ErrorCode value)
    {
        switch (value) {
        case Geoposition_ErrorCode::NONE:
            return os << "Geoposition_ErrorCode::NONE";
        case Geoposition_ErrorCode::PERMISSION_DENIED:
            return os << "Geoposition_ErrorCode::PERMISSION_DENIED";
        case Geoposition_ErrorCode::POSITION_UNAVAILABLE:
            return os << "Geoposition_ErrorCode::POSITION_UNAVAILABLE";
        case Geoposition_ErrorCode::TIMEOUT:
            return os << "Geoposition_ErrorCode::{TIMEOUT, LAST}";
        default:
            return os << "Unknown Geoposition_ErrorCode value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(Geoposition_ErrorCode value)
    {
        return internal::Geoposition_ErrorCode_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    // Interface base classes. They are used for type safety check.
    class GeolocationServiceInterfaceBase {
    };

    using GeolocationServicePtrDataView = mojo::InterfacePtrDataView<GeolocationServiceInterfaceBase>;
    using GeolocationServiceRequestDataView = mojo::InterfaceRequestDataView<GeolocationServiceInterfaceBase>;
    using GeolocationServiceAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<GeolocationServiceInterfaceBase>;
    using GeolocationServiceAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<GeolocationServiceInterfaceBase>;
    class GeopositionDataView {
    public:
        GeopositionDataView() { }

        GeopositionDataView(
            internal::Geoposition_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        bool valid() const
        {
            return data_->valid;
        }
        double latitude() const
        {
            return data_->latitude;
        }
        double longitude() const
        {
            return data_->longitude;
        }
        double altitude() const
        {
            return data_->altitude;
        }
        double accuracy() const
        {
            return data_->accuracy;
        }
        double altitude_accuracy() const
        {
            return data_->altitude_accuracy;
        }
        double heading() const
        {
            return data_->heading;
        }
        double speed() const
        {
            return data_->speed;
        }
        double timestamp() const
        {
            return data_->timestamp;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadErrorCode(UserType* output) const
        {
            auto data_value = data_->error_code;
            return mojo::internal::Deserialize<::device::mojom::Geoposition_ErrorCode>(
                data_value, output);
        }

        Geoposition_ErrorCode error_code() const
        {
            return static_cast<Geoposition_ErrorCode>(data_->error_code);
        }
        inline void GetErrorMessageDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadErrorMessage(UserType* output)
        {
            auto* pointer = data_->error_message.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::Geoposition_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class GeolocationService_SetHighAccuracy_ParamsDataView {
    public:
        GeolocationService_SetHighAccuracy_ParamsDataView() { }

        GeolocationService_SetHighAccuracy_ParamsDataView(
            internal::GeolocationService_SetHighAccuracy_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool high_accuracy() const
        {
            return data_->high_accuracy;
        }

    private:
        internal::GeolocationService_SetHighAccuracy_Params_Data* data_ = nullptr;
    };

    class GeolocationService_QueryNextPosition_ParamsDataView {
    public:
        GeolocationService_QueryNextPosition_ParamsDataView() { }

        GeolocationService_QueryNextPosition_ParamsDataView(
            internal::GeolocationService_QueryNextPosition_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::GeolocationService_QueryNextPosition_Params_Data* data_ = nullptr;
    };

    class GeolocationService_QueryNextPosition_ResponseParamsDataView {
    public:
        GeolocationService_QueryNextPosition_ResponseParamsDataView() { }

        GeolocationService_QueryNextPosition_ResponseParamsDataView(
            internal::GeolocationService_QueryNextPosition_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetGeopositionDataView(
            GeopositionDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadGeoposition(UserType* output)
        {
            auto* pointer = data_->geoposition.Get();
            return mojo::internal::Deserialize<::device::mojom::GeopositionDataView>(
                pointer, output, context_);
        }

    private:
        internal::GeolocationService_QueryNextPosition_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace device

namespace std {

template <>
struct hash<::device::mojom::Geoposition_ErrorCode>
    : public mojo::internal::EnumHashImpl<::device::mojom::Geoposition_ErrorCode> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::device::mojom::Geoposition_ErrorCode, ::device::mojom::Geoposition_ErrorCode> {
    static ::device::mojom::Geoposition_ErrorCode ToMojom(::device::mojom::Geoposition_ErrorCode input) { return input; }
    static bool FromMojom(::device::mojom::Geoposition_ErrorCode input, ::device::mojom::Geoposition_ErrorCode* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::mojom::Geoposition_ErrorCode, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::device::mojom::Geoposition_ErrorCode, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::device::mojom::Geoposition_ErrorCode>(input), output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::device::mojom::GeopositionDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::device::mojom::GeopositionDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::device::mojom::internal::Geoposition_Data);
            decltype(CallWithContext(Traits::error_message, input, custom_context)) in_error_message = CallWithContext(Traits::error_message, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_error_message, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::device::mojom::internal::Geoposition_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::device::mojom::internal::Geoposition_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->valid = CallWithContext(Traits::valid, input, custom_context);
            result->latitude = CallWithContext(Traits::latitude, input, custom_context);
            result->longitude = CallWithContext(Traits::longitude, input, custom_context);
            result->altitude = CallWithContext(Traits::altitude, input, custom_context);
            result->accuracy = CallWithContext(Traits::accuracy, input, custom_context);
            result->altitude_accuracy = CallWithContext(Traits::altitude_accuracy, input, custom_context);
            result->heading = CallWithContext(Traits::heading, input, custom_context);
            result->speed = CallWithContext(Traits::speed, input, custom_context);
            result->timestamp = CallWithContext(Traits::timestamp, input, custom_context);
            mojo::internal::Serialize<::device::mojom::Geoposition_ErrorCode>(
                CallWithContext(Traits::error_code, input, custom_context), &result->error_code);
            decltype(CallWithContext(Traits::error_message, input, custom_context)) in_error_message = CallWithContext(Traits::error_message, input, custom_context);
            typename decltype(result->error_message)::BaseType* error_message_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_error_message, buffer, &error_message_ptr, context);
            result->error_message.Set(error_message_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->error_message.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null error_message in Geoposition struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::device::mojom::internal::Geoposition_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::device::mojom::GeopositionDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace device {
namespace mojom {

    inline void GeopositionDataView::GetErrorMessageDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->error_message.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void GeolocationService_QueryNextPosition_ResponseParamsDataView::GetGeopositionDataView(
        GeopositionDataView* output)
    {
        auto pointer = data_->geoposition.Get();
        *output = GeopositionDataView(pointer, context_);
    }

} // namespace mojom
} // namespace device

#endif // DEVICE_GEOLOCATION_PUBLIC_INTERFACES_GEOLOCATION_MOJOM_SHARED_H_
