// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_DEVICE_DESCRIPTOR_MOJOM_SHARED_H_
#define SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_DEVICE_DESCRIPTOR_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "services/video_capture/public/interfaces/device_descriptor.mojom-shared-internal.h"

namespace video_capture {
namespace mojom {
    class DeviceDescriptorDataView;

} // namespace mojom
} // namespace video_capture

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::video_capture::mojom::DeviceDescriptorDataView> {
        using Data = ::video_capture::mojom::internal::DeviceDescriptor_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace video_capture {
namespace mojom {

    enum class VideoCaptureApi : int32_t {
        LINUX_V4L2_SINGLE_PLANE,
        WIN_MEDIA_FOUNDATION,
        WIN_DIRECT_SHOW,
        MACOSX_AVFOUNDATION,
        MACOSX_DECKLINK,
        ANDROID_API1,
        ANDROID_API2_LEGACY,
        ANDROID_API2_FULL,
        ANDROID_API2_LIMITED,
        ANDROID_TANGO,
        UNKNOWN,
    };

    inline std::ostream& operator<<(std::ostream& os, VideoCaptureApi value)
    {
        switch (value) {
        case VideoCaptureApi::LINUX_V4L2_SINGLE_PLANE:
            return os << "VideoCaptureApi::LINUX_V4L2_SINGLE_PLANE";
        case VideoCaptureApi::WIN_MEDIA_FOUNDATION:
            return os << "VideoCaptureApi::WIN_MEDIA_FOUNDATION";
        case VideoCaptureApi::WIN_DIRECT_SHOW:
            return os << "VideoCaptureApi::WIN_DIRECT_SHOW";
        case VideoCaptureApi::MACOSX_AVFOUNDATION:
            return os << "VideoCaptureApi::MACOSX_AVFOUNDATION";
        case VideoCaptureApi::MACOSX_DECKLINK:
            return os << "VideoCaptureApi::MACOSX_DECKLINK";
        case VideoCaptureApi::ANDROID_API1:
            return os << "VideoCaptureApi::ANDROID_API1";
        case VideoCaptureApi::ANDROID_API2_LEGACY:
            return os << "VideoCaptureApi::ANDROID_API2_LEGACY";
        case VideoCaptureApi::ANDROID_API2_FULL:
            return os << "VideoCaptureApi::ANDROID_API2_FULL";
        case VideoCaptureApi::ANDROID_API2_LIMITED:
            return os << "VideoCaptureApi::ANDROID_API2_LIMITED";
        case VideoCaptureApi::ANDROID_TANGO:
            return os << "VideoCaptureApi::ANDROID_TANGO";
        case VideoCaptureApi::UNKNOWN:
            return os << "VideoCaptureApi::UNKNOWN";
        default:
            return os << "Unknown VideoCaptureApi value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(VideoCaptureApi value)
    {
        return internal::VideoCaptureApi_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class VideoCaptureTransportType : int32_t {
        MACOSX_USB_OR_BUILT_IN,
        OTHER_TRANSPORT,
    };

    inline std::ostream& operator<<(std::ostream& os, VideoCaptureTransportType value)
    {
        switch (value) {
        case VideoCaptureTransportType::MACOSX_USB_OR_BUILT_IN:
            return os << "VideoCaptureTransportType::MACOSX_USB_OR_BUILT_IN";
        case VideoCaptureTransportType::OTHER_TRANSPORT:
            return os << "VideoCaptureTransportType::OTHER_TRANSPORT";
        default:
            return os << "Unknown VideoCaptureTransportType value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(VideoCaptureTransportType value)
    {
        return internal::VideoCaptureTransportType_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    class DeviceDescriptorDataView {
    public:
        DeviceDescriptorDataView() { }

        DeviceDescriptorDataView(
            internal::DeviceDescriptor_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetDisplayNameDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDisplayName(UserType* output)
        {
            auto* pointer = data_->display_name.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetDeviceIdDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDeviceId(UserType* output)
        {
            auto* pointer = data_->device_id.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetModelIdDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadModelId(UserType* output)
        {
            auto* pointer = data_->model_id.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadCaptureApi(UserType* output) const
        {
            auto data_value = data_->capture_api;
            return mojo::internal::Deserialize<::video_capture::mojom::VideoCaptureApi>(
                data_value, output);
        }

        VideoCaptureApi capture_api() const
        {
            return static_cast<VideoCaptureApi>(data_->capture_api);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTransportType(UserType* output) const
        {
            auto data_value = data_->transport_type;
            return mojo::internal::Deserialize<::video_capture::mojom::VideoCaptureTransportType>(
                data_value, output);
        }

        VideoCaptureTransportType transport_type() const
        {
            return static_cast<VideoCaptureTransportType>(data_->transport_type);
        }

    private:
        internal::DeviceDescriptor_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace video_capture

namespace std {

template <>
struct hash<::video_capture::mojom::VideoCaptureApi>
    : public mojo::internal::EnumHashImpl<::video_capture::mojom::VideoCaptureApi> {
};

template <>
struct hash<::video_capture::mojom::VideoCaptureTransportType>
    : public mojo::internal::EnumHashImpl<::video_capture::mojom::VideoCaptureTransportType> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::video_capture::mojom::VideoCaptureApi, ::video_capture::mojom::VideoCaptureApi> {
    static ::video_capture::mojom::VideoCaptureApi ToMojom(::video_capture::mojom::VideoCaptureApi input) { return input; }
    static bool FromMojom(::video_capture::mojom::VideoCaptureApi input, ::video_capture::mojom::VideoCaptureApi* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::video_capture::mojom::VideoCaptureApi, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::video_capture::mojom::VideoCaptureApi, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::video_capture::mojom::VideoCaptureApi>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::video_capture::mojom::VideoCaptureTransportType, ::video_capture::mojom::VideoCaptureTransportType> {
    static ::video_capture::mojom::VideoCaptureTransportType ToMojom(::video_capture::mojom::VideoCaptureTransportType input) { return input; }
    static bool FromMojom(::video_capture::mojom::VideoCaptureTransportType input, ::video_capture::mojom::VideoCaptureTransportType* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::video_capture::mojom::VideoCaptureTransportType, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::video_capture::mojom::VideoCaptureTransportType, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::video_capture::mojom::VideoCaptureTransportType>(input), output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::video_capture::mojom::DeviceDescriptorDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::video_capture::mojom::DeviceDescriptorDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::video_capture::mojom::internal::DeviceDescriptor_Data);
            decltype(CallWithContext(Traits::display_name, input, custom_context)) in_display_name = CallWithContext(Traits::display_name, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_display_name, context);
            decltype(CallWithContext(Traits::device_id, input, custom_context)) in_device_id = CallWithContext(Traits::device_id, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_device_id, context);
            decltype(CallWithContext(Traits::model_id, input, custom_context)) in_model_id = CallWithContext(Traits::model_id, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_model_id, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::video_capture::mojom::internal::DeviceDescriptor_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::video_capture::mojom::internal::DeviceDescriptor_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::display_name, input, custom_context)) in_display_name = CallWithContext(Traits::display_name, input, custom_context);
            typename decltype(result->display_name)::BaseType* display_name_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_display_name, buffer, &display_name_ptr, context);
            result->display_name.Set(display_name_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->display_name.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null display_name in DeviceDescriptor struct");
            decltype(CallWithContext(Traits::device_id, input, custom_context)) in_device_id = CallWithContext(Traits::device_id, input, custom_context);
            typename decltype(result->device_id)::BaseType* device_id_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_device_id, buffer, &device_id_ptr, context);
            result->device_id.Set(device_id_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->device_id.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null device_id in DeviceDescriptor struct");
            decltype(CallWithContext(Traits::model_id, input, custom_context)) in_model_id = CallWithContext(Traits::model_id, input, custom_context);
            typename decltype(result->model_id)::BaseType* model_id_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_model_id, buffer, &model_id_ptr, context);
            result->model_id.Set(model_id_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->model_id.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null model_id in DeviceDescriptor struct");
            mojo::internal::Serialize<::video_capture::mojom::VideoCaptureApi>(
                CallWithContext(Traits::capture_api, input, custom_context), &result->capture_api);
            mojo::internal::Serialize<::video_capture::mojom::VideoCaptureTransportType>(
                CallWithContext(Traits::transport_type, input, custom_context), &result->transport_type);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::video_capture::mojom::internal::DeviceDescriptor_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::video_capture::mojom::DeviceDescriptorDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace video_capture {
namespace mojom {

    inline void DeviceDescriptorDataView::GetDisplayNameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->display_name.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void DeviceDescriptorDataView::GetDeviceIdDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->device_id.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void DeviceDescriptorDataView::GetModelIdDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->model_id.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

} // namespace mojom
} // namespace video_capture

#endif // SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_DEVICE_DESCRIPTOR_MOJOM_SHARED_H_
