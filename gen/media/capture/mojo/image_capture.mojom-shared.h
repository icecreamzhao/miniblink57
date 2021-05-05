// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_CAPTURE_MOJO_IMAGE_CAPTURE_MOJOM_SHARED_H_
#define MEDIA_CAPTURE_MOJO_IMAGE_CAPTURE_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "media/capture/mojo/image_capture.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"

namespace media {
namespace mojom {
    class RangeDataView;

    class PhotoCapabilitiesDataView;

    class Point2DDataView;

    class PhotoSettingsDataView;

    class BlobDataView;

} // namespace mojom
} // namespace media

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::media::mojom::RangeDataView> {
        using Data = ::media::mojom::internal::Range_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::media::mojom::PhotoCapabilitiesDataView> {
        using Data = ::media::mojom::internal::PhotoCapabilities_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::media::mojom::Point2DDataView> {
        using Data = ::media::mojom::internal::Point2D_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::media::mojom::PhotoSettingsDataView> {
        using Data = ::media::mojom::internal::PhotoSettings_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::media::mojom::BlobDataView> {
        using Data = ::media::mojom::internal::Blob_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace media {
namespace mojom {

    enum class MeteringMode : int32_t {
        NONE,
        MANUAL,
        SINGLE_SHOT,
        CONTINUOUS,
    };

    inline std::ostream& operator<<(std::ostream& os, MeteringMode value)
    {
        switch (value) {
        case MeteringMode::NONE:
            return os << "MeteringMode::NONE";
        case MeteringMode::MANUAL:
            return os << "MeteringMode::MANUAL";
        case MeteringMode::SINGLE_SHOT:
            return os << "MeteringMode::SINGLE_SHOT";
        case MeteringMode::CONTINUOUS:
            return os << "MeteringMode::CONTINUOUS";
        default:
            return os << "Unknown MeteringMode value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(MeteringMode value)
    {
        return internal::MeteringMode_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class FillLightMode : int32_t {
        NONE,
        OFF,
        AUTO,
        FLASH,
        TORCH,
    };

    inline std::ostream& operator<<(std::ostream& os, FillLightMode value)
    {
        switch (value) {
        case FillLightMode::NONE:
            return os << "FillLightMode::NONE";
        case FillLightMode::OFF:
            return os << "FillLightMode::OFF";
        case FillLightMode::AUTO:
            return os << "FillLightMode::AUTO";
        case FillLightMode::FLASH:
            return os << "FillLightMode::FLASH";
        case FillLightMode::TORCH:
            return os << "FillLightMode::TORCH";
        default:
            return os << "Unknown FillLightMode value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(FillLightMode value)
    {
        return internal::FillLightMode_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    // Interface base classes. They are used for type safety check.
    class ImageCaptureInterfaceBase {
    };

    using ImageCapturePtrDataView = mojo::InterfacePtrDataView<ImageCaptureInterfaceBase>;
    using ImageCaptureRequestDataView = mojo::InterfaceRequestDataView<ImageCaptureInterfaceBase>;
    using ImageCaptureAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<ImageCaptureInterfaceBase>;
    using ImageCaptureAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<ImageCaptureInterfaceBase>;
    class RangeDataView {
    public:
        RangeDataView() { }

        RangeDataView(
            internal::Range_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        double max() const
        {
            return data_->max;
        }
        double min() const
        {
            return data_->min;
        }
        double current() const
        {
            return data_->current;
        }
        double step() const
        {
            return data_->step;
        }

    private:
        internal::Range_Data* data_ = nullptr;
    };

    class PhotoCapabilitiesDataView {
    public:
        PhotoCapabilitiesDataView() { }

        PhotoCapabilitiesDataView(
            internal::PhotoCapabilities_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadWhiteBalanceMode(UserType* output) const
        {
            auto data_value = data_->white_balance_mode;
            return mojo::internal::Deserialize<::media::mojom::MeteringMode>(
                data_value, output);
        }

        MeteringMode white_balance_mode() const
        {
            return static_cast<MeteringMode>(data_->white_balance_mode);
        }
        inline void GetColorTemperatureDataView(
            RangeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadColorTemperature(UserType* output)
        {
            auto* pointer = data_->color_temperature.Get();
            return mojo::internal::Deserialize<::media::mojom::RangeDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadExposureMode(UserType* output) const
        {
            auto data_value = data_->exposure_mode;
            return mojo::internal::Deserialize<::media::mojom::MeteringMode>(
                data_value, output);
        }

        MeteringMode exposure_mode() const
        {
            return static_cast<MeteringMode>(data_->exposure_mode);
        }
        inline void GetExposureCompensationDataView(
            RangeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadExposureCompensation(UserType* output)
        {
            auto* pointer = data_->exposure_compensation.Get();
            return mojo::internal::Deserialize<::media::mojom::RangeDataView>(
                pointer, output, context_);
        }
        inline void GetIsoDataView(
            RangeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadIso(UserType* output)
        {
            auto* pointer = data_->iso.Get();
            return mojo::internal::Deserialize<::media::mojom::RangeDataView>(
                pointer, output, context_);
        }
        bool red_eye_reduction() const
        {
            return data_->red_eye_reduction;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFocusMode(UserType* output) const
        {
            auto data_value = data_->focus_mode;
            return mojo::internal::Deserialize<::media::mojom::MeteringMode>(
                data_value, output);
        }

        MeteringMode focus_mode() const
        {
            return static_cast<MeteringMode>(data_->focus_mode);
        }
        inline void GetBrightnessDataView(
            RangeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadBrightness(UserType* output)
        {
            auto* pointer = data_->brightness.Get();
            return mojo::internal::Deserialize<::media::mojom::RangeDataView>(
                pointer, output, context_);
        }
        inline void GetContrastDataView(
            RangeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadContrast(UserType* output)
        {
            auto* pointer = data_->contrast.Get();
            return mojo::internal::Deserialize<::media::mojom::RangeDataView>(
                pointer, output, context_);
        }
        inline void GetSaturationDataView(
            RangeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSaturation(UserType* output)
        {
            auto* pointer = data_->saturation.Get();
            return mojo::internal::Deserialize<::media::mojom::RangeDataView>(
                pointer, output, context_);
        }
        inline void GetSharpnessDataView(
            RangeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSharpness(UserType* output)
        {
            auto* pointer = data_->sharpness.Get();
            return mojo::internal::Deserialize<::media::mojom::RangeDataView>(
                pointer, output, context_);
        }
        inline void GetHeightDataView(
            RangeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadHeight(UserType* output)
        {
            auto* pointer = data_->height.Get();
            return mojo::internal::Deserialize<::media::mojom::RangeDataView>(
                pointer, output, context_);
        }
        inline void GetWidthDataView(
            RangeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadWidth(UserType* output)
        {
            auto* pointer = data_->width.Get();
            return mojo::internal::Deserialize<::media::mojom::RangeDataView>(
                pointer, output, context_);
        }
        inline void GetZoomDataView(
            RangeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadZoom(UserType* output)
        {
            auto* pointer = data_->zoom.Get();
            return mojo::internal::Deserialize<::media::mojom::RangeDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFillLightMode(UserType* output) const
        {
            auto data_value = data_->fill_light_mode;
            return mojo::internal::Deserialize<::media::mojom::FillLightMode>(
                data_value, output);
        }

        FillLightMode fill_light_mode() const
        {
            return static_cast<FillLightMode>(data_->fill_light_mode);
        }

    private:
        internal::PhotoCapabilities_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Point2DDataView {
    public:
        Point2DDataView() { }

        Point2DDataView(
            internal::Point2D_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        float x() const
        {
            return data_->x;
        }
        float y() const
        {
            return data_->y;
        }

    private:
        internal::Point2D_Data* data_ = nullptr;
    };

    class PhotoSettingsDataView {
    public:
        PhotoSettingsDataView() { }

        PhotoSettingsDataView(
            internal::PhotoSettings_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        bool has_white_balance_mode() const
        {
            return data_->has_white_balance_mode;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadWhiteBalanceMode(UserType* output) const
        {
            auto data_value = data_->white_balance_mode;
            return mojo::internal::Deserialize<::media::mojom::MeteringMode>(
                data_value, output);
        }

        MeteringMode white_balance_mode() const
        {
            return static_cast<MeteringMode>(data_->white_balance_mode);
        }
        bool has_color_temperature() const
        {
            return data_->has_color_temperature;
        }
        double color_temperature() const
        {
            return data_->color_temperature;
        }
        bool has_exposure_mode() const
        {
            return data_->has_exposure_mode;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadExposureMode(UserType* output) const
        {
            auto data_value = data_->exposure_mode;
            return mojo::internal::Deserialize<::media::mojom::MeteringMode>(
                data_value, output);
        }

        MeteringMode exposure_mode() const
        {
            return static_cast<MeteringMode>(data_->exposure_mode);
        }
        bool has_exposure_compensation() const
        {
            return data_->has_exposure_compensation;
        }
        double exposure_compensation() const
        {
            return data_->exposure_compensation;
        }
        bool has_iso() const
        {
            return data_->has_iso;
        }
        double iso() const
        {
            return data_->iso;
        }
        bool has_red_eye_reduction() const
        {
            return data_->has_red_eye_reduction;
        }
        bool red_eye_reduction() const
        {
            return data_->red_eye_reduction;
        }
        bool has_focus_mode() const
        {
            return data_->has_focus_mode;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFocusMode(UserType* output) const
        {
            auto data_value = data_->focus_mode;
            return mojo::internal::Deserialize<::media::mojom::MeteringMode>(
                data_value, output);
        }

        MeteringMode focus_mode() const
        {
            return static_cast<MeteringMode>(data_->focus_mode);
        }
        inline void GetPointsOfInterestDataView(
            mojo::ArrayDataView<Point2DDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPointsOfInterest(UserType* output)
        {
            auto* pointer = data_->points_of_interest.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::media::mojom::Point2DDataView>>(
                pointer, output, context_);
        }
        bool has_brightness() const
        {
            return data_->has_brightness;
        }
        double brightness() const
        {
            return data_->brightness;
        }
        bool has_contrast() const
        {
            return data_->has_contrast;
        }
        double contrast() const
        {
            return data_->contrast;
        }
        bool has_saturation() const
        {
            return data_->has_saturation;
        }
        double saturation() const
        {
            return data_->saturation;
        }
        bool has_sharpness() const
        {
            return data_->has_sharpness;
        }
        double sharpness() const
        {
            return data_->sharpness;
        }
        bool has_zoom() const
        {
            return data_->has_zoom;
        }
        double zoom() const
        {
            return data_->zoom;
        }
        bool has_width() const
        {
            return data_->has_width;
        }
        double width() const
        {
            return data_->width;
        }
        bool has_height() const
        {
            return data_->has_height;
        }
        double height() const
        {
            return data_->height;
        }
        bool has_fill_light_mode() const
        {
            return data_->has_fill_light_mode;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFillLightMode(UserType* output) const
        {
            auto data_value = data_->fill_light_mode;
            return mojo::internal::Deserialize<::media::mojom::FillLightMode>(
                data_value, output);
        }

        FillLightMode fill_light_mode() const
        {
            return static_cast<FillLightMode>(data_->fill_light_mode);
        }

    private:
        internal::PhotoSettings_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class BlobDataView {
    public:
        BlobDataView() { }

        BlobDataView(
            internal::Blob_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetMimeTypeDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMimeType(UserType* output)
        {
            auto* pointer = data_->mime_type.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetDataDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadData(UserType* output)
        {
            auto* pointer = data_->data.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }

    private:
        internal::Blob_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class ImageCapture_GetCapabilities_ParamsDataView {
    public:
        ImageCapture_GetCapabilities_ParamsDataView() { }

        ImageCapture_GetCapabilities_ParamsDataView(
            internal::ImageCapture_GetCapabilities_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetSourceIdDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSourceId(UserType* output)
        {
            auto* pointer = data_->source_id.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::ImageCapture_GetCapabilities_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class ImageCapture_GetCapabilities_ResponseParamsDataView {
    public:
        ImageCapture_GetCapabilities_ResponseParamsDataView() { }

        ImageCapture_GetCapabilities_ResponseParamsDataView(
            internal::ImageCapture_GetCapabilities_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetCapabilitiesDataView(
            PhotoCapabilitiesDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadCapabilities(UserType* output)
        {
            auto* pointer = data_->capabilities.Get();
            return mojo::internal::Deserialize<::media::mojom::PhotoCapabilitiesDataView>(
                pointer, output, context_);
        }

    private:
        internal::ImageCapture_GetCapabilities_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class ImageCapture_SetOptions_ParamsDataView {
    public:
        ImageCapture_SetOptions_ParamsDataView() { }

        ImageCapture_SetOptions_ParamsDataView(
            internal::ImageCapture_SetOptions_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetSourceIdDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSourceId(UserType* output)
        {
            auto* pointer = data_->source_id.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetSettingsDataView(
            PhotoSettingsDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSettings(UserType* output)
        {
            auto* pointer = data_->settings.Get();
            return mojo::internal::Deserialize<::media::mojom::PhotoSettingsDataView>(
                pointer, output, context_);
        }

    private:
        internal::ImageCapture_SetOptions_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class ImageCapture_SetOptions_ResponseParamsDataView {
    public:
        ImageCapture_SetOptions_ResponseParamsDataView() { }

        ImageCapture_SetOptions_ResponseParamsDataView(
            internal::ImageCapture_SetOptions_ResponseParams_Data* data,
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
        internal::ImageCapture_SetOptions_ResponseParams_Data* data_ = nullptr;
    };

    class ImageCapture_TakePhoto_ParamsDataView {
    public:
        ImageCapture_TakePhoto_ParamsDataView() { }

        ImageCapture_TakePhoto_ParamsDataView(
            internal::ImageCapture_TakePhoto_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetSourceIdDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSourceId(UserType* output)
        {
            auto* pointer = data_->source_id.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::ImageCapture_TakePhoto_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class ImageCapture_TakePhoto_ResponseParamsDataView {
    public:
        ImageCapture_TakePhoto_ResponseParamsDataView() { }

        ImageCapture_TakePhoto_ResponseParamsDataView(
            internal::ImageCapture_TakePhoto_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetBlobDataView(
            BlobDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadBlob(UserType* output)
        {
            auto* pointer = data_->blob.Get();
            return mojo::internal::Deserialize<::media::mojom::BlobDataView>(
                pointer, output, context_);
        }

    private:
        internal::ImageCapture_TakePhoto_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace media

namespace std {

template <>
struct hash<::media::mojom::MeteringMode>
    : public mojo::internal::EnumHashImpl<::media::mojom::MeteringMode> {
};

template <>
struct hash<::media::mojom::FillLightMode>
    : public mojo::internal::EnumHashImpl<::media::mojom::FillLightMode> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::media::mojom::MeteringMode, ::media::mojom::MeteringMode> {
    static ::media::mojom::MeteringMode ToMojom(::media::mojom::MeteringMode input) { return input; }
    static bool FromMojom(::media::mojom::MeteringMode input, ::media::mojom::MeteringMode* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::media::mojom::MeteringMode, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::media::mojom::MeteringMode, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::media::mojom::MeteringMode>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::media::mojom::FillLightMode, ::media::mojom::FillLightMode> {
    static ::media::mojom::FillLightMode ToMojom(::media::mojom::FillLightMode input) { return input; }
    static bool FromMojom(::media::mojom::FillLightMode input, ::media::mojom::FillLightMode* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::media::mojom::FillLightMode, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::media::mojom::FillLightMode, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::media::mojom::FillLightMode>(input), output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::media::mojom::RangeDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::media::mojom::RangeDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::media::mojom::internal::Range_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::media::mojom::internal::Range_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::media::mojom::internal::Range_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->max = CallWithContext(Traits::max, input, custom_context);
            result->min = CallWithContext(Traits::min, input, custom_context);
            result->current = CallWithContext(Traits::current, input, custom_context);
            result->step = CallWithContext(Traits::step, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::media::mojom::internal::Range_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::media::mojom::RangeDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::media::mojom::PhotoCapabilitiesDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::media::mojom::PhotoCapabilitiesDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::media::mojom::internal::PhotoCapabilities_Data);
            decltype(CallWithContext(Traits::color_temperature, input, custom_context)) in_color_temperature = CallWithContext(Traits::color_temperature, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::media::mojom::RangeDataView>(
                in_color_temperature, context);
            decltype(CallWithContext(Traits::exposure_compensation, input, custom_context)) in_exposure_compensation = CallWithContext(Traits::exposure_compensation, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::media::mojom::RangeDataView>(
                in_exposure_compensation, context);
            decltype(CallWithContext(Traits::iso, input, custom_context)) in_iso = CallWithContext(Traits::iso, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::media::mojom::RangeDataView>(
                in_iso, context);
            decltype(CallWithContext(Traits::brightness, input, custom_context)) in_brightness = CallWithContext(Traits::brightness, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::media::mojom::RangeDataView>(
                in_brightness, context);
            decltype(CallWithContext(Traits::contrast, input, custom_context)) in_contrast = CallWithContext(Traits::contrast, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::media::mojom::RangeDataView>(
                in_contrast, context);
            decltype(CallWithContext(Traits::saturation, input, custom_context)) in_saturation = CallWithContext(Traits::saturation, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::media::mojom::RangeDataView>(
                in_saturation, context);
            decltype(CallWithContext(Traits::sharpness, input, custom_context)) in_sharpness = CallWithContext(Traits::sharpness, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::media::mojom::RangeDataView>(
                in_sharpness, context);
            decltype(CallWithContext(Traits::height, input, custom_context)) in_height = CallWithContext(Traits::height, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::media::mojom::RangeDataView>(
                in_height, context);
            decltype(CallWithContext(Traits::width, input, custom_context)) in_width = CallWithContext(Traits::width, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::media::mojom::RangeDataView>(
                in_width, context);
            decltype(CallWithContext(Traits::zoom, input, custom_context)) in_zoom = CallWithContext(Traits::zoom, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::media::mojom::RangeDataView>(
                in_zoom, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::media::mojom::internal::PhotoCapabilities_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::media::mojom::internal::PhotoCapabilities_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            mojo::internal::Serialize<::media::mojom::MeteringMode>(
                CallWithContext(Traits::white_balance_mode, input, custom_context), &result->white_balance_mode);
            decltype(CallWithContext(Traits::color_temperature, input, custom_context)) in_color_temperature = CallWithContext(Traits::color_temperature, input, custom_context);
            typename decltype(result->color_temperature)::BaseType* color_temperature_ptr;
            mojo::internal::Serialize<::media::mojom::RangeDataView>(
                in_color_temperature, buffer, &color_temperature_ptr, context);
            result->color_temperature.Set(color_temperature_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->color_temperature.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null color_temperature in PhotoCapabilities struct");
            mojo::internal::Serialize<::media::mojom::MeteringMode>(
                CallWithContext(Traits::exposure_mode, input, custom_context), &result->exposure_mode);
            decltype(CallWithContext(Traits::exposure_compensation, input, custom_context)) in_exposure_compensation = CallWithContext(Traits::exposure_compensation, input, custom_context);
            typename decltype(result->exposure_compensation)::BaseType* exposure_compensation_ptr;
            mojo::internal::Serialize<::media::mojom::RangeDataView>(
                in_exposure_compensation, buffer, &exposure_compensation_ptr, context);
            result->exposure_compensation.Set(exposure_compensation_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->exposure_compensation.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null exposure_compensation in PhotoCapabilities struct");
            decltype(CallWithContext(Traits::iso, input, custom_context)) in_iso = CallWithContext(Traits::iso, input, custom_context);
            typename decltype(result->iso)::BaseType* iso_ptr;
            mojo::internal::Serialize<::media::mojom::RangeDataView>(
                in_iso, buffer, &iso_ptr, context);
            result->iso.Set(iso_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->iso.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null iso in PhotoCapabilities struct");
            result->red_eye_reduction = CallWithContext(Traits::red_eye_reduction, input, custom_context);
            mojo::internal::Serialize<::media::mojom::MeteringMode>(
                CallWithContext(Traits::focus_mode, input, custom_context), &result->focus_mode);
            decltype(CallWithContext(Traits::brightness, input, custom_context)) in_brightness = CallWithContext(Traits::brightness, input, custom_context);
            typename decltype(result->brightness)::BaseType* brightness_ptr;
            mojo::internal::Serialize<::media::mojom::RangeDataView>(
                in_brightness, buffer, &brightness_ptr, context);
            result->brightness.Set(brightness_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->brightness.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null brightness in PhotoCapabilities struct");
            decltype(CallWithContext(Traits::contrast, input, custom_context)) in_contrast = CallWithContext(Traits::contrast, input, custom_context);
            typename decltype(result->contrast)::BaseType* contrast_ptr;
            mojo::internal::Serialize<::media::mojom::RangeDataView>(
                in_contrast, buffer, &contrast_ptr, context);
            result->contrast.Set(contrast_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->contrast.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null contrast in PhotoCapabilities struct");
            decltype(CallWithContext(Traits::saturation, input, custom_context)) in_saturation = CallWithContext(Traits::saturation, input, custom_context);
            typename decltype(result->saturation)::BaseType* saturation_ptr;
            mojo::internal::Serialize<::media::mojom::RangeDataView>(
                in_saturation, buffer, &saturation_ptr, context);
            result->saturation.Set(saturation_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->saturation.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null saturation in PhotoCapabilities struct");
            decltype(CallWithContext(Traits::sharpness, input, custom_context)) in_sharpness = CallWithContext(Traits::sharpness, input, custom_context);
            typename decltype(result->sharpness)::BaseType* sharpness_ptr;
            mojo::internal::Serialize<::media::mojom::RangeDataView>(
                in_sharpness, buffer, &sharpness_ptr, context);
            result->sharpness.Set(sharpness_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->sharpness.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null sharpness in PhotoCapabilities struct");
            decltype(CallWithContext(Traits::height, input, custom_context)) in_height = CallWithContext(Traits::height, input, custom_context);
            typename decltype(result->height)::BaseType* height_ptr;
            mojo::internal::Serialize<::media::mojom::RangeDataView>(
                in_height, buffer, &height_ptr, context);
            result->height.Set(height_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->height.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null height in PhotoCapabilities struct");
            decltype(CallWithContext(Traits::width, input, custom_context)) in_width = CallWithContext(Traits::width, input, custom_context);
            typename decltype(result->width)::BaseType* width_ptr;
            mojo::internal::Serialize<::media::mojom::RangeDataView>(
                in_width, buffer, &width_ptr, context);
            result->width.Set(width_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->width.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null width in PhotoCapabilities struct");
            decltype(CallWithContext(Traits::zoom, input, custom_context)) in_zoom = CallWithContext(Traits::zoom, input, custom_context);
            typename decltype(result->zoom)::BaseType* zoom_ptr;
            mojo::internal::Serialize<::media::mojom::RangeDataView>(
                in_zoom, buffer, &zoom_ptr, context);
            result->zoom.Set(zoom_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->zoom.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null zoom in PhotoCapabilities struct");
            mojo::internal::Serialize<::media::mojom::FillLightMode>(
                CallWithContext(Traits::fill_light_mode, input, custom_context), &result->fill_light_mode);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::media::mojom::internal::PhotoCapabilities_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::media::mojom::PhotoCapabilitiesDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::media::mojom::Point2DDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::media::mojom::Point2DDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::media::mojom::internal::Point2D_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::media::mojom::internal::Point2D_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::media::mojom::internal::Point2D_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->x = CallWithContext(Traits::x, input, custom_context);
            result->y = CallWithContext(Traits::y, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::media::mojom::internal::Point2D_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::media::mojom::Point2DDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::media::mojom::PhotoSettingsDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::media::mojom::PhotoSettingsDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::media::mojom::internal::PhotoSettings_Data);
            decltype(CallWithContext(Traits::points_of_interest, input, custom_context)) in_points_of_interest = CallWithContext(Traits::points_of_interest, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::media::mojom::Point2DDataView>>(
                in_points_of_interest, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::media::mojom::internal::PhotoSettings_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::media::mojom::internal::PhotoSettings_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->has_white_balance_mode = CallWithContext(Traits::has_white_balance_mode, input, custom_context);
            mojo::internal::Serialize<::media::mojom::MeteringMode>(
                CallWithContext(Traits::white_balance_mode, input, custom_context), &result->white_balance_mode);
            result->has_color_temperature = CallWithContext(Traits::has_color_temperature, input, custom_context);
            result->color_temperature = CallWithContext(Traits::color_temperature, input, custom_context);
            result->has_exposure_mode = CallWithContext(Traits::has_exposure_mode, input, custom_context);
            mojo::internal::Serialize<::media::mojom::MeteringMode>(
                CallWithContext(Traits::exposure_mode, input, custom_context), &result->exposure_mode);
            result->has_exposure_compensation = CallWithContext(Traits::has_exposure_compensation, input, custom_context);
            result->exposure_compensation = CallWithContext(Traits::exposure_compensation, input, custom_context);
            result->has_iso = CallWithContext(Traits::has_iso, input, custom_context);
            result->iso = CallWithContext(Traits::iso, input, custom_context);
            result->has_red_eye_reduction = CallWithContext(Traits::has_red_eye_reduction, input, custom_context);
            result->red_eye_reduction = CallWithContext(Traits::red_eye_reduction, input, custom_context);
            result->has_focus_mode = CallWithContext(Traits::has_focus_mode, input, custom_context);
            mojo::internal::Serialize<::media::mojom::MeteringMode>(
                CallWithContext(Traits::focus_mode, input, custom_context), &result->focus_mode);
            decltype(CallWithContext(Traits::points_of_interest, input, custom_context)) in_points_of_interest = CallWithContext(Traits::points_of_interest, input, custom_context);
            typename decltype(result->points_of_interest)::BaseType* points_of_interest_ptr;
            const mojo::internal::ContainerValidateParams points_of_interest_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::media::mojom::Point2DDataView>>(
                in_points_of_interest, buffer, &points_of_interest_ptr, &points_of_interest_validate_params,
                context);
            result->points_of_interest.Set(points_of_interest_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->points_of_interest.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null points_of_interest in PhotoSettings struct");
            result->has_brightness = CallWithContext(Traits::has_brightness, input, custom_context);
            result->brightness = CallWithContext(Traits::brightness, input, custom_context);
            result->has_contrast = CallWithContext(Traits::has_contrast, input, custom_context);
            result->contrast = CallWithContext(Traits::contrast, input, custom_context);
            result->has_saturation = CallWithContext(Traits::has_saturation, input, custom_context);
            result->saturation = CallWithContext(Traits::saturation, input, custom_context);
            result->has_sharpness = CallWithContext(Traits::has_sharpness, input, custom_context);
            result->sharpness = CallWithContext(Traits::sharpness, input, custom_context);
            result->has_zoom = CallWithContext(Traits::has_zoom, input, custom_context);
            result->zoom = CallWithContext(Traits::zoom, input, custom_context);
            result->has_width = CallWithContext(Traits::has_width, input, custom_context);
            result->width = CallWithContext(Traits::width, input, custom_context);
            result->has_height = CallWithContext(Traits::has_height, input, custom_context);
            result->height = CallWithContext(Traits::height, input, custom_context);
            result->has_fill_light_mode = CallWithContext(Traits::has_fill_light_mode, input, custom_context);
            mojo::internal::Serialize<::media::mojom::FillLightMode>(
                CallWithContext(Traits::fill_light_mode, input, custom_context), &result->fill_light_mode);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::media::mojom::internal::PhotoSettings_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::media::mojom::PhotoSettingsDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::media::mojom::BlobDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::media::mojom::BlobDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::media::mojom::internal::Blob_Data);
            decltype(CallWithContext(Traits::mime_type, input, custom_context)) in_mime_type = CallWithContext(Traits::mime_type, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_mime_type, context);
            decltype(CallWithContext(Traits::data, input, custom_context)) in_data = CallWithContext(Traits::data, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
                in_data, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::media::mojom::internal::Blob_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::media::mojom::internal::Blob_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::mime_type, input, custom_context)) in_mime_type = CallWithContext(Traits::mime_type, input, custom_context);
            typename decltype(result->mime_type)::BaseType* mime_type_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_mime_type, buffer, &mime_type_ptr, context);
            result->mime_type.Set(mime_type_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->mime_type.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null mime_type in Blob struct");
            decltype(CallWithContext(Traits::data, input, custom_context)) in_data = CallWithContext(Traits::data, input, custom_context);
            typename decltype(result->data)::BaseType* data_ptr;
            const mojo::internal::ContainerValidateParams data_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
                in_data, buffer, &data_ptr, &data_validate_params,
                context);
            result->data.Set(data_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->data.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null data in Blob struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::media::mojom::internal::Blob_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::media::mojom::BlobDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace media {
namespace mojom {

    inline void PhotoCapabilitiesDataView::GetColorTemperatureDataView(
        RangeDataView* output)
    {
        auto pointer = data_->color_temperature.Get();
        *output = RangeDataView(pointer, context_);
    }
    inline void PhotoCapabilitiesDataView::GetExposureCompensationDataView(
        RangeDataView* output)
    {
        auto pointer = data_->exposure_compensation.Get();
        *output = RangeDataView(pointer, context_);
    }
    inline void PhotoCapabilitiesDataView::GetIsoDataView(
        RangeDataView* output)
    {
        auto pointer = data_->iso.Get();
        *output = RangeDataView(pointer, context_);
    }
    inline void PhotoCapabilitiesDataView::GetBrightnessDataView(
        RangeDataView* output)
    {
        auto pointer = data_->brightness.Get();
        *output = RangeDataView(pointer, context_);
    }
    inline void PhotoCapabilitiesDataView::GetContrastDataView(
        RangeDataView* output)
    {
        auto pointer = data_->contrast.Get();
        *output = RangeDataView(pointer, context_);
    }
    inline void PhotoCapabilitiesDataView::GetSaturationDataView(
        RangeDataView* output)
    {
        auto pointer = data_->saturation.Get();
        *output = RangeDataView(pointer, context_);
    }
    inline void PhotoCapabilitiesDataView::GetSharpnessDataView(
        RangeDataView* output)
    {
        auto pointer = data_->sharpness.Get();
        *output = RangeDataView(pointer, context_);
    }
    inline void PhotoCapabilitiesDataView::GetHeightDataView(
        RangeDataView* output)
    {
        auto pointer = data_->height.Get();
        *output = RangeDataView(pointer, context_);
    }
    inline void PhotoCapabilitiesDataView::GetWidthDataView(
        RangeDataView* output)
    {
        auto pointer = data_->width.Get();
        *output = RangeDataView(pointer, context_);
    }
    inline void PhotoCapabilitiesDataView::GetZoomDataView(
        RangeDataView* output)
    {
        auto pointer = data_->zoom.Get();
        *output = RangeDataView(pointer, context_);
    }

    inline void PhotoSettingsDataView::GetPointsOfInterestDataView(
        mojo::ArrayDataView<Point2DDataView>* output)
    {
        auto pointer = data_->points_of_interest.Get();
        *output = mojo::ArrayDataView<Point2DDataView>(pointer, context_);
    }

    inline void BlobDataView::GetMimeTypeDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->mime_type.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void BlobDataView::GetDataDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->data.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

    inline void ImageCapture_GetCapabilities_ParamsDataView::GetSourceIdDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->source_id.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void ImageCapture_GetCapabilities_ResponseParamsDataView::GetCapabilitiesDataView(
        PhotoCapabilitiesDataView* output)
    {
        auto pointer = data_->capabilities.Get();
        *output = PhotoCapabilitiesDataView(pointer, context_);
    }

    inline void ImageCapture_SetOptions_ParamsDataView::GetSourceIdDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->source_id.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void ImageCapture_SetOptions_ParamsDataView::GetSettingsDataView(
        PhotoSettingsDataView* output)
    {
        auto pointer = data_->settings.Get();
        *output = PhotoSettingsDataView(pointer, context_);
    }

    inline void ImageCapture_TakePhoto_ParamsDataView::GetSourceIdDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->source_id.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void ImageCapture_TakePhoto_ResponseParamsDataView::GetBlobDataView(
        BlobDataView* output)
    {
        auto pointer = data_->blob.Get();
        *output = BlobDataView(pointer, context_);
    }

} // namespace mojom
} // namespace media

#endif // MEDIA_CAPTURE_MOJO_IMAGE_CAPTURE_MOJOM_SHARED_H_
