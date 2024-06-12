// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_FILTER_OPERATION_MOJOM_SHARED_H_
#define CC_IPC_FILTER_OPERATION_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "cc/ipc/filter_operation.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "skia/public/interfaces/image_filter.mojom-shared.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared.h"

namespace cc {
namespace mojom {
    class FilterOperationDataView;

} // namespace mojom
} // namespace cc

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::cc::mojom::FilterOperationDataView> {
        using Data = ::cc::mojom::internal::FilterOperation_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace cc {
namespace mojom {

    enum class FilterType : int32_t {
        GRAYSCALE,
        SEPIA,
        SATURATE,
        HUE_ROTATE,
        INVERT,
        BRIGHTNESS,
        CONTRAST,
        OPACITY,
        BLUR,
        DROP_SHADOW,
        COLOR_MATRIX,
        ZOOM,
        REFERENCE,
        SATURATING_BRIGHTNESS,
        ALPHA_THRESHOLD,
        FILTER_TYPE_LAST = FilterType::ALPHA_THRESHOLD,
    };

    inline std::ostream& operator<<(std::ostream& os, FilterType value)
    {
        switch (value) {
        case FilterType::GRAYSCALE:
            return os << "FilterType::GRAYSCALE";
        case FilterType::SEPIA:
            return os << "FilterType::SEPIA";
        case FilterType::SATURATE:
            return os << "FilterType::SATURATE";
        case FilterType::HUE_ROTATE:
            return os << "FilterType::HUE_ROTATE";
        case FilterType::INVERT:
            return os << "FilterType::INVERT";
        case FilterType::BRIGHTNESS:
            return os << "FilterType::BRIGHTNESS";
        case FilterType::CONTRAST:
            return os << "FilterType::CONTRAST";
        case FilterType::OPACITY:
            return os << "FilterType::OPACITY";
        case FilterType::BLUR:
            return os << "FilterType::BLUR";
        case FilterType::DROP_SHADOW:
            return os << "FilterType::DROP_SHADOW";
        case FilterType::COLOR_MATRIX:
            return os << "FilterType::COLOR_MATRIX";
        case FilterType::ZOOM:
            return os << "FilterType::ZOOM";
        case FilterType::REFERENCE:
            return os << "FilterType::REFERENCE";
        case FilterType::SATURATING_BRIGHTNESS:
            return os << "FilterType::SATURATING_BRIGHTNESS";
        case FilterType::ALPHA_THRESHOLD:
            return os << "FilterType::{ALPHA_THRESHOLD, FILTER_TYPE_LAST}";
        default:
            return os << "Unknown FilterType value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(FilterType value)
    {
        return internal::FilterType_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    class FilterOperationDataView {
    public:
        FilterOperationDataView() { }

        FilterOperationDataView(
            internal::FilterOperation_Data* data,
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
            return mojo::internal::Deserialize<::cc::mojom::FilterType>(
                data_value, output);
        }

        FilterType type() const
        {
            return static_cast<FilterType>(data_->type);
        }
        float amount() const
        {
            return data_->amount;
        }
        inline void GetDropShadowOffsetDataView(
            ::gfx::mojom::PointDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDropShadowOffset(UserType* output)
        {
            auto* pointer = data_->drop_shadow_offset.Get();
            return mojo::internal::Deserialize<::gfx::mojom::PointDataView>(
                pointer, output, context_);
        }
        uint32_t drop_shadow_color() const
        {
            return data_->drop_shadow_color;
        }
        inline void GetImageFilterDataView(
            ::skia::mojom::ImageFilterDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadImageFilter(UserType* output)
        {
            auto* pointer = data_->image_filter.Get();
            return mojo::internal::Deserialize<::skia::mojom::ImageFilterDataView>(
                pointer, output, context_);
        }
        inline void GetMatrixDataView(
            mojo::ArrayDataView<float>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMatrix(UserType* output)
        {
            auto* pointer = data_->matrix.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<float>>(
                pointer, output, context_);
        }
        int32_t zoom_inset() const
        {
            return data_->zoom_inset;
        }

    private:
        internal::FilterOperation_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace cc

namespace std {

template <>
struct hash<::cc::mojom::FilterType>
    : public mojo::internal::EnumHashImpl<::cc::mojom::FilterType> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::cc::mojom::FilterType, ::cc::mojom::FilterType> {
    static ::cc::mojom::FilterType ToMojom(::cc::mojom::FilterType input) { return input; }
    static bool FromMojom(::cc::mojom::FilterType input, ::cc::mojom::FilterType* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::cc::mojom::FilterType, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::cc::mojom::FilterType, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::cc::mojom::FilterType>(input), output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::cc::mojom::FilterOperationDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::cc::mojom::FilterOperationDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::cc::mojom::internal::FilterOperation_Data);
            decltype(CallWithContext(Traits::drop_shadow_offset, input, custom_context)) in_drop_shadow_offset = CallWithContext(Traits::drop_shadow_offset, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::PointDataView>(
                in_drop_shadow_offset, context);
            decltype(CallWithContext(Traits::image_filter, input, custom_context)) in_image_filter = CallWithContext(Traits::image_filter, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::skia::mojom::ImageFilterDataView>(
                in_image_filter, context);
            decltype(CallWithContext(Traits::matrix, input, custom_context)) in_matrix = CallWithContext(Traits::matrix, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<float>>(
                in_matrix, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::cc::mojom::internal::FilterOperation_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::cc::mojom::internal::FilterOperation_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            mojo::internal::Serialize<::cc::mojom::FilterType>(
                CallWithContext(Traits::type, input, custom_context), &result->type);
            result->amount = CallWithContext(Traits::amount, input, custom_context);
            decltype(CallWithContext(Traits::drop_shadow_offset, input, custom_context)) in_drop_shadow_offset = CallWithContext(Traits::drop_shadow_offset, input, custom_context);
            typename decltype(result->drop_shadow_offset)::BaseType* drop_shadow_offset_ptr;
            mojo::internal::Serialize<::gfx::mojom::PointDataView>(
                in_drop_shadow_offset, buffer, &drop_shadow_offset_ptr, context);
            result->drop_shadow_offset.Set(drop_shadow_offset_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->drop_shadow_offset.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null drop_shadow_offset in FilterOperation struct");
            result->drop_shadow_color = CallWithContext(Traits::drop_shadow_color, input, custom_context);
            decltype(CallWithContext(Traits::image_filter, input, custom_context)) in_image_filter = CallWithContext(Traits::image_filter, input, custom_context);
            typename decltype(result->image_filter)::BaseType* image_filter_ptr;
            mojo::internal::Serialize<::skia::mojom::ImageFilterDataView>(
                in_image_filter, buffer, &image_filter_ptr, context);
            result->image_filter.Set(image_filter_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->image_filter.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null image_filter in FilterOperation struct");
            decltype(CallWithContext(Traits::matrix, input, custom_context)) in_matrix = CallWithContext(Traits::matrix, input, custom_context);
            typename decltype(result->matrix)::BaseType* matrix_ptr;
            const mojo::internal::ContainerValidateParams matrix_validate_params(
                20, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<float>>(
                in_matrix, buffer, &matrix_ptr, &matrix_validate_params,
                context);
            result->matrix.Set(matrix_ptr);
            result->zoom_inset = CallWithContext(Traits::zoom_inset, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::cc::mojom::internal::FilterOperation_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::cc::mojom::FilterOperationDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace cc {
namespace mojom {

    inline void FilterOperationDataView::GetDropShadowOffsetDataView(
        ::gfx::mojom::PointDataView* output)
    {
        auto pointer = data_->drop_shadow_offset.Get();
        *output = ::gfx::mojom::PointDataView(pointer, context_);
    }
    inline void FilterOperationDataView::GetImageFilterDataView(
        ::skia::mojom::ImageFilterDataView* output)
    {
        auto pointer = data_->image_filter.Get();
        *output = ::skia::mojom::ImageFilterDataView(pointer, context_);
    }
    inline void FilterOperationDataView::GetMatrixDataView(
        mojo::ArrayDataView<float>* output)
    {
        auto pointer = data_->matrix.Get();
        *output = mojo::ArrayDataView<float>(pointer, context_);
    }

} // namespace mojom
} // namespace cc

#endif // CC_IPC_FILTER_OPERATION_MOJOM_SHARED_H_
