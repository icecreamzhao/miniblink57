// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_DEVICE_FACTORY_MOJOM_SHARED_H_
#define SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_DEVICE_FACTORY_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "media/capture/mojo/video_capture_types.mojom-shared.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "services/video_capture/public/interfaces/capture_settings.mojom-shared.h"
#include "services/video_capture/public/interfaces/device.mojom-shared.h"
#include "services/video_capture/public/interfaces/device_descriptor.mojom-shared.h"
#include "services/video_capture/public/interfaces/device_factory.mojom-shared-internal.h"

namespace video_capture {
namespace mojom {

} // namespace mojom
} // namespace video_capture

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace video_capture {
namespace mojom {

    enum class DeviceAccessResultCode : int32_t {
        NOT_INITIALIZED,
        SUCCESS,
        ERROR_DEVICE_NOT_FOUND,
    };

    inline std::ostream& operator<<(std::ostream& os, DeviceAccessResultCode value)
    {
        switch (value) {
        case DeviceAccessResultCode::NOT_INITIALIZED:
            return os << "DeviceAccessResultCode::NOT_INITIALIZED";
        case DeviceAccessResultCode::SUCCESS:
            return os << "DeviceAccessResultCode::SUCCESS";
        case DeviceAccessResultCode::ERROR_DEVICE_NOT_FOUND:
            return os << "DeviceAccessResultCode::ERROR_DEVICE_NOT_FOUND";
        default:
            return os << "Unknown DeviceAccessResultCode value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(DeviceAccessResultCode value)
    {
        return internal::DeviceAccessResultCode_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    // Interface base classes. They are used for type safety check.
    class DeviceFactoryInterfaceBase {
    };

    using DeviceFactoryPtrDataView = mojo::InterfacePtrDataView<DeviceFactoryInterfaceBase>;
    using DeviceFactoryRequestDataView = mojo::InterfaceRequestDataView<DeviceFactoryInterfaceBase>;
    using DeviceFactoryAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<DeviceFactoryInterfaceBase>;
    using DeviceFactoryAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<DeviceFactoryInterfaceBase>;
    class DeviceFactory_EnumerateDeviceDescriptors_ParamsDataView {
    public:
        DeviceFactory_EnumerateDeviceDescriptors_ParamsDataView() { }

        DeviceFactory_EnumerateDeviceDescriptors_ParamsDataView(
            internal::DeviceFactory_EnumerateDeviceDescriptors_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::DeviceFactory_EnumerateDeviceDescriptors_Params_Data* data_ = nullptr;
    };

    class DeviceFactory_EnumerateDeviceDescriptors_ResponseParamsDataView {
    public:
        DeviceFactory_EnumerateDeviceDescriptors_ResponseParamsDataView() { }

        DeviceFactory_EnumerateDeviceDescriptors_ResponseParamsDataView(
            internal::DeviceFactory_EnumerateDeviceDescriptors_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetDescriptorsDataView(
            mojo::ArrayDataView<::video_capture::mojom::DeviceDescriptorDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDescriptors(UserType* output)
        {
            auto* pointer = data_->descriptors.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::video_capture::mojom::DeviceDescriptorDataView>>(
                pointer, output, context_);
        }

    private:
        internal::DeviceFactory_EnumerateDeviceDescriptors_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class DeviceFactory_GetSupportedFormats_ParamsDataView {
    public:
        DeviceFactory_GetSupportedFormats_ParamsDataView() { }

        DeviceFactory_GetSupportedFormats_ParamsDataView(
            internal::DeviceFactory_GetSupportedFormats_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetDeviceIdDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDeviceId(UserType* output)
        {
            auto* pointer = data_->device_id.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::DeviceFactory_GetSupportedFormats_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class DeviceFactory_GetSupportedFormats_ResponseParamsDataView {
    public:
        DeviceFactory_GetSupportedFormats_ResponseParamsDataView() { }

        DeviceFactory_GetSupportedFormats_ResponseParamsDataView(
            internal::DeviceFactory_GetSupportedFormats_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetSupportedFormatsDataView(
            mojo::ArrayDataView<::video_capture::mojom::I420CaptureFormatDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSupportedFormats(UserType* output)
        {
            auto* pointer = data_->supported_formats.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::video_capture::mojom::I420CaptureFormatDataView>>(
                pointer, output, context_);
        }

    private:
        internal::DeviceFactory_GetSupportedFormats_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class DeviceFactory_CreateDevice_ParamsDataView {
    public:
        DeviceFactory_CreateDevice_ParamsDataView() { }

        DeviceFactory_CreateDevice_ParamsDataView(
            internal::DeviceFactory_CreateDevice_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetDeviceIdDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDeviceId(UserType* output)
        {
            auto* pointer = data_->device_id.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        UserType TakeDeviceRequest()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::video_capture::mojom::DeviceRequestDataView>(
                &data_->device_request, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::DeviceFactory_CreateDevice_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class DeviceFactory_CreateDevice_ResponseParamsDataView {
    public:
        DeviceFactory_CreateDevice_ResponseParamsDataView() { }

        DeviceFactory_CreateDevice_ResponseParamsDataView(
            internal::DeviceFactory_CreateDevice_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadResultCode(UserType* output) const
        {
            auto data_value = data_->result_code;
            return mojo::internal::Deserialize<::video_capture::mojom::DeviceAccessResultCode>(
                data_value, output);
        }

        DeviceAccessResultCode result_code() const
        {
            return static_cast<DeviceAccessResultCode>(data_->result_code);
        }

    private:
        internal::DeviceFactory_CreateDevice_ResponseParams_Data* data_ = nullptr;
    };

} // namespace mojom
} // namespace video_capture

namespace std {

template <>
struct hash<::video_capture::mojom::DeviceAccessResultCode>
    : public mojo::internal::EnumHashImpl<::video_capture::mojom::DeviceAccessResultCode> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::video_capture::mojom::DeviceAccessResultCode, ::video_capture::mojom::DeviceAccessResultCode> {
    static ::video_capture::mojom::DeviceAccessResultCode ToMojom(::video_capture::mojom::DeviceAccessResultCode input) { return input; }
    static bool FromMojom(::video_capture::mojom::DeviceAccessResultCode input, ::video_capture::mojom::DeviceAccessResultCode* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::video_capture::mojom::DeviceAccessResultCode, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::video_capture::mojom::DeviceAccessResultCode, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::video_capture::mojom::DeviceAccessResultCode>(input), output);
        }
    };

} // namespace internal

} // namespace mojo

namespace video_capture {
namespace mojom {

    inline void DeviceFactory_EnumerateDeviceDescriptors_ResponseParamsDataView::GetDescriptorsDataView(
        mojo::ArrayDataView<::video_capture::mojom::DeviceDescriptorDataView>* output)
    {
        auto pointer = data_->descriptors.Get();
        *output = mojo::ArrayDataView<::video_capture::mojom::DeviceDescriptorDataView>(pointer, context_);
    }

    inline void DeviceFactory_GetSupportedFormats_ParamsDataView::GetDeviceIdDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->device_id.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void DeviceFactory_GetSupportedFormats_ResponseParamsDataView::GetSupportedFormatsDataView(
        mojo::ArrayDataView<::video_capture::mojom::I420CaptureFormatDataView>* output)
    {
        auto pointer = data_->supported_formats.Get();
        *output = mojo::ArrayDataView<::video_capture::mojom::I420CaptureFormatDataView>(pointer, context_);
    }

    inline void DeviceFactory_CreateDevice_ParamsDataView::GetDeviceIdDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->device_id.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

} // namespace mojom
} // namespace video_capture

#endif // SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_DEVICE_FACTORY_MOJOM_SHARED_H_
