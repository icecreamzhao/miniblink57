// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SKIA_PUBLIC_INTERFACES_BITMAP_MOJOM_SHARED_H_
#define SKIA_PUBLIC_INTERFACES_BITMAP_MOJOM_SHARED_H_

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
#include "skia/public/interfaces/bitmap.mojom-shared-internal.h"

namespace skia {
namespace mojom {
    class BitmapDataView;

} // namespace mojom
} // namespace skia

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::skia::mojom::BitmapDataView> {
        using Data = ::skia::mojom::internal::Bitmap_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace skia {
namespace mojom {

    enum class ColorType : int32_t {
        UNKNOWN,
        ALPHA_8,
        RGB_565,
        ARGB_4444,
        RGBA_8888,
        BGRA_8888,
        INDEX_8,
        GRAY_8,
    };

    inline std::ostream& operator<<(std::ostream& os, ColorType value)
    {
        switch (value) {
        case ColorType::UNKNOWN:
            return os << "ColorType::UNKNOWN";
        case ColorType::ALPHA_8:
            return os << "ColorType::ALPHA_8";
        case ColorType::RGB_565:
            return os << "ColorType::RGB_565";
        case ColorType::ARGB_4444:
            return os << "ColorType::ARGB_4444";
        case ColorType::RGBA_8888:
            return os << "ColorType::RGBA_8888";
        case ColorType::BGRA_8888:
            return os << "ColorType::BGRA_8888";
        case ColorType::INDEX_8:
            return os << "ColorType::INDEX_8";
        case ColorType::GRAY_8:
            return os << "ColorType::GRAY_8";
        default:
            return os << "Unknown ColorType value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(ColorType value)
    {
        return internal::ColorType_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class AlphaType : int32_t {
        UNKNOWN,
        ALPHA_TYPE_OPAQUE,
        PREMUL,
        UNPREMUL,
    };

    inline std::ostream& operator<<(std::ostream& os, AlphaType value)
    {
        switch (value) {
        case AlphaType::UNKNOWN:
            return os << "AlphaType::UNKNOWN";
        case AlphaType::ALPHA_TYPE_OPAQUE:
            return os << "AlphaType::ALPHA_TYPE_OPAQUE";
        case AlphaType::PREMUL:
            return os << "AlphaType::PREMUL";
        case AlphaType::UNPREMUL:
            return os << "AlphaType::UNPREMUL";
        default:
            return os << "Unknown AlphaType value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(AlphaType value)
    {
        return internal::AlphaType_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class ColorProfileType : int32_t {
        LINEAR,
        SRGB,
    };

    inline std::ostream& operator<<(std::ostream& os, ColorProfileType value)
    {
        switch (value) {
        case ColorProfileType::LINEAR:
            return os << "ColorProfileType::LINEAR";
        case ColorProfileType::SRGB:
            return os << "ColorProfileType::SRGB";
        default:
            return os << "Unknown ColorProfileType value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(ColorProfileType value)
    {
        return internal::ColorProfileType_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    class BitmapDataView {
    public:
        BitmapDataView() { }

        BitmapDataView(
            internal::Bitmap_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadColorType(UserType* output) const
        {
            auto data_value = data_->color_type;
            return mojo::internal::Deserialize<::skia::mojom::ColorType>(
                data_value, output);
        }

        ColorType color_type() const
        {
            return static_cast<ColorType>(data_->color_type);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadAlphaType(UserType* output) const
        {
            auto data_value = data_->alpha_type;
            return mojo::internal::Deserialize<::skia::mojom::AlphaType>(
                data_value, output);
        }

        AlphaType alpha_type() const
        {
            return static_cast<AlphaType>(data_->alpha_type);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadProfileType(UserType* output) const
        {
            auto data_value = data_->profile_type;
            return mojo::internal::Deserialize<::skia::mojom::ColorProfileType>(
                data_value, output);
        }

        ColorProfileType profile_type() const
        {
            return static_cast<ColorProfileType>(data_->profile_type);
        }
        uint32_t width() const
        {
            return data_->width;
        }
        uint32_t height() const
        {
            return data_->height;
        }
        uint64_t row_bytes() const
        {
            return data_->row_bytes;
        }
        inline void GetPixelDataDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPixelData(UserType* output)
        {
            auto* pointer = data_->pixel_data.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }

    private:
        internal::Bitmap_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace skia

namespace std {

template <>
struct hash<::skia::mojom::ColorType>
    : public mojo::internal::EnumHashImpl<::skia::mojom::ColorType> {
};

template <>
struct hash<::skia::mojom::AlphaType>
    : public mojo::internal::EnumHashImpl<::skia::mojom::AlphaType> {
};

template <>
struct hash<::skia::mojom::ColorProfileType>
    : public mojo::internal::EnumHashImpl<::skia::mojom::ColorProfileType> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::skia::mojom::ColorType, ::skia::mojom::ColorType> {
    static ::skia::mojom::ColorType ToMojom(::skia::mojom::ColorType input) { return input; }
    static bool FromMojom(::skia::mojom::ColorType input, ::skia::mojom::ColorType* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::skia::mojom::ColorType, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::skia::mojom::ColorType, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::skia::mojom::ColorType>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::skia::mojom::AlphaType, ::skia::mojom::AlphaType> {
    static ::skia::mojom::AlphaType ToMojom(::skia::mojom::AlphaType input) { return input; }
    static bool FromMojom(::skia::mojom::AlphaType input, ::skia::mojom::AlphaType* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::skia::mojom::AlphaType, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::skia::mojom::AlphaType, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::skia::mojom::AlphaType>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::skia::mojom::ColorProfileType, ::skia::mojom::ColorProfileType> {
    static ::skia::mojom::ColorProfileType ToMojom(::skia::mojom::ColorProfileType input) { return input; }
    static bool FromMojom(::skia::mojom::ColorProfileType input, ::skia::mojom::ColorProfileType* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::skia::mojom::ColorProfileType, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::skia::mojom::ColorProfileType, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::skia::mojom::ColorProfileType>(input), output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::skia::mojom::BitmapDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::skia::mojom::BitmapDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::skia::mojom::internal::Bitmap_Data);
            decltype(CallWithContext(Traits::pixel_data, input, custom_context)) in_pixel_data = CallWithContext(Traits::pixel_data, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
                in_pixel_data, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::skia::mojom::internal::Bitmap_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::skia::mojom::internal::Bitmap_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            mojo::internal::Serialize<::skia::mojom::ColorType>(
                CallWithContext(Traits::color_type, input, custom_context), &result->color_type);
            mojo::internal::Serialize<::skia::mojom::AlphaType>(
                CallWithContext(Traits::alpha_type, input, custom_context), &result->alpha_type);
            mojo::internal::Serialize<::skia::mojom::ColorProfileType>(
                CallWithContext(Traits::profile_type, input, custom_context), &result->profile_type);
            result->width = CallWithContext(Traits::width, input, custom_context);
            result->height = CallWithContext(Traits::height, input, custom_context);
            result->row_bytes = CallWithContext(Traits::row_bytes, input, custom_context);
            decltype(CallWithContext(Traits::pixel_data, input, custom_context)) in_pixel_data = CallWithContext(Traits::pixel_data, input, custom_context);
            typename decltype(result->pixel_data)::BaseType* pixel_data_ptr;
            const mojo::internal::ContainerValidateParams pixel_data_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
                in_pixel_data, buffer, &pixel_data_ptr, &pixel_data_validate_params,
                context);
            result->pixel_data.Set(pixel_data_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->pixel_data.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null pixel_data in Bitmap struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::skia::mojom::internal::Bitmap_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::skia::mojom::BitmapDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace skia {
namespace mojom {

    inline void BitmapDataView::GetPixelDataDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->pixel_data.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

} // namespace mojom
} // namespace skia

#endif // SKIA_PUBLIC_INTERFACES_BITMAP_MOJOM_SHARED_H_
