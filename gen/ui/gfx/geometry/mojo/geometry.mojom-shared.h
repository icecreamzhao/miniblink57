// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_GFX_GEOMETRY_MOJO_GEOMETRY_MOJOM_SHARED_H_
#define UI_GFX_GEOMETRY_MOJO_GEOMETRY_MOJOM_SHARED_H_

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
#include "ui/gfx/geometry/mojo/geometry.mojom-shared-internal.h"

namespace gfx {
namespace mojom {
    class PointDataView;

    class PointFDataView;

    class SizeDataView;

    class SizeFDataView;

    class RectDataView;

    class RectFDataView;

    class InsetsDataView;

    class InsetsFDataView;

    class Vector2dDataView;

    class Vector2dFDataView;

} // namespace mojom
} // namespace gfx

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::gfx::mojom::PointDataView> {
        using Data = ::gfx::mojom::internal::Point_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::gfx::mojom::PointFDataView> {
        using Data = ::gfx::mojom::internal::PointF_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::gfx::mojom::SizeDataView> {
        using Data = ::gfx::mojom::internal::Size_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::gfx::mojom::SizeFDataView> {
        using Data = ::gfx::mojom::internal::SizeF_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::gfx::mojom::RectDataView> {
        using Data = ::gfx::mojom::internal::Rect_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::gfx::mojom::RectFDataView> {
        using Data = ::gfx::mojom::internal::RectF_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::gfx::mojom::InsetsDataView> {
        using Data = ::gfx::mojom::internal::Insets_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::gfx::mojom::InsetsFDataView> {
        using Data = ::gfx::mojom::internal::InsetsF_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::gfx::mojom::Vector2dDataView> {
        using Data = ::gfx::mojom::internal::Vector2d_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::gfx::mojom::Vector2dFDataView> {
        using Data = ::gfx::mojom::internal::Vector2dF_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace gfx {
namespace mojom {
    class PointDataView {
    public:
        PointDataView() { }

        PointDataView(
            internal::Point_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int32_t x() const
        {
            return data_->x;
        }
        int32_t y() const
        {
            return data_->y;
        }

    private:
        internal::Point_Data* data_ = nullptr;
    };

    class PointFDataView {
    public:
        PointFDataView() { }

        PointFDataView(
            internal::PointF_Data* data,
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
        internal::PointF_Data* data_ = nullptr;
    };

    class SizeDataView {
    public:
        SizeDataView() { }

        SizeDataView(
            internal::Size_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int32_t width() const
        {
            return data_->width;
        }
        int32_t height() const
        {
            return data_->height;
        }

    private:
        internal::Size_Data* data_ = nullptr;
    };

    class SizeFDataView {
    public:
        SizeFDataView() { }

        SizeFDataView(
            internal::SizeF_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        float width() const
        {
            return data_->width;
        }
        float height() const
        {
            return data_->height;
        }

    private:
        internal::SizeF_Data* data_ = nullptr;
    };

    class RectDataView {
    public:
        RectDataView() { }

        RectDataView(
            internal::Rect_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int32_t x() const
        {
            return data_->x;
        }
        int32_t y() const
        {
            return data_->y;
        }
        int32_t width() const
        {
            return data_->width;
        }
        int32_t height() const
        {
            return data_->height;
        }

    private:
        internal::Rect_Data* data_ = nullptr;
    };

    class RectFDataView {
    public:
        RectFDataView() { }

        RectFDataView(
            internal::RectF_Data* data,
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
        float width() const
        {
            return data_->width;
        }
        float height() const
        {
            return data_->height;
        }

    private:
        internal::RectF_Data* data_ = nullptr;
    };

    class InsetsDataView {
    public:
        InsetsDataView() { }

        InsetsDataView(
            internal::Insets_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int32_t top() const
        {
            return data_->top;
        }
        int32_t left() const
        {
            return data_->left;
        }
        int32_t bottom() const
        {
            return data_->bottom;
        }
        int32_t right() const
        {
            return data_->right;
        }

    private:
        internal::Insets_Data* data_ = nullptr;
    };

    class InsetsFDataView {
    public:
        InsetsFDataView() { }

        InsetsFDataView(
            internal::InsetsF_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        float top() const
        {
            return data_->top;
        }
        float left() const
        {
            return data_->left;
        }
        float bottom() const
        {
            return data_->bottom;
        }
        float right() const
        {
            return data_->right;
        }

    private:
        internal::InsetsF_Data* data_ = nullptr;
    };

    class Vector2dDataView {
    public:
        Vector2dDataView() { }

        Vector2dDataView(
            internal::Vector2d_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int32_t x() const
        {
            return data_->x;
        }
        int32_t y() const
        {
            return data_->y;
        }

    private:
        internal::Vector2d_Data* data_ = nullptr;
    };

    class Vector2dFDataView {
    public:
        Vector2dFDataView() { }

        Vector2dFDataView(
            internal::Vector2dF_Data* data,
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
        internal::Vector2dF_Data* data_ = nullptr;
    };

} // namespace mojom
} // namespace gfx

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::gfx::mojom::PointDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::gfx::mojom::PointDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::gfx::mojom::internal::Point_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::gfx::mojom::internal::Point_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::gfx::mojom::internal::Point_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->x = CallWithContext(Traits::x, input, custom_context);
            result->y = CallWithContext(Traits::y, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::gfx::mojom::internal::Point_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::gfx::mojom::PointDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::gfx::mojom::PointFDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::gfx::mojom::PointFDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::gfx::mojom::internal::PointF_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::gfx::mojom::internal::PointF_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::gfx::mojom::internal::PointF_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->x = CallWithContext(Traits::x, input, custom_context);
            result->y = CallWithContext(Traits::y, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::gfx::mojom::internal::PointF_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::gfx::mojom::PointFDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::gfx::mojom::SizeDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::gfx::mojom::SizeDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::gfx::mojom::internal::Size_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::gfx::mojom::internal::Size_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::gfx::mojom::internal::Size_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->width = CallWithContext(Traits::width, input, custom_context);
            result->height = CallWithContext(Traits::height, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::gfx::mojom::internal::Size_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::gfx::mojom::SizeDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::gfx::mojom::SizeFDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::gfx::mojom::SizeFDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::gfx::mojom::internal::SizeF_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::gfx::mojom::internal::SizeF_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::gfx::mojom::internal::SizeF_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->width = CallWithContext(Traits::width, input, custom_context);
            result->height = CallWithContext(Traits::height, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::gfx::mojom::internal::SizeF_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::gfx::mojom::SizeFDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::gfx::mojom::RectDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::gfx::mojom::RectDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::gfx::mojom::internal::Rect_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::gfx::mojom::internal::Rect_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::gfx::mojom::internal::Rect_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->x = CallWithContext(Traits::x, input, custom_context);
            result->y = CallWithContext(Traits::y, input, custom_context);
            result->width = CallWithContext(Traits::width, input, custom_context);
            result->height = CallWithContext(Traits::height, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::gfx::mojom::internal::Rect_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::gfx::mojom::RectDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::gfx::mojom::RectFDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::gfx::mojom::RectFDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::gfx::mojom::internal::RectF_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::gfx::mojom::internal::RectF_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::gfx::mojom::internal::RectF_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->x = CallWithContext(Traits::x, input, custom_context);
            result->y = CallWithContext(Traits::y, input, custom_context);
            result->width = CallWithContext(Traits::width, input, custom_context);
            result->height = CallWithContext(Traits::height, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::gfx::mojom::internal::RectF_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::gfx::mojom::RectFDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::gfx::mojom::InsetsDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::gfx::mojom::InsetsDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::gfx::mojom::internal::Insets_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::gfx::mojom::internal::Insets_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::gfx::mojom::internal::Insets_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->top = CallWithContext(Traits::top, input, custom_context);
            result->left = CallWithContext(Traits::left, input, custom_context);
            result->bottom = CallWithContext(Traits::bottom, input, custom_context);
            result->right = CallWithContext(Traits::right, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::gfx::mojom::internal::Insets_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::gfx::mojom::InsetsDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::gfx::mojom::InsetsFDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::gfx::mojom::InsetsFDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::gfx::mojom::internal::InsetsF_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::gfx::mojom::internal::InsetsF_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::gfx::mojom::internal::InsetsF_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->top = CallWithContext(Traits::top, input, custom_context);
            result->left = CallWithContext(Traits::left, input, custom_context);
            result->bottom = CallWithContext(Traits::bottom, input, custom_context);
            result->right = CallWithContext(Traits::right, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::gfx::mojom::internal::InsetsF_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::gfx::mojom::InsetsFDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::gfx::mojom::Vector2dDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::gfx::mojom::Vector2dDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::gfx::mojom::internal::Vector2d_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::gfx::mojom::internal::Vector2d_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::gfx::mojom::internal::Vector2d_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->x = CallWithContext(Traits::x, input, custom_context);
            result->y = CallWithContext(Traits::y, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::gfx::mojom::internal::Vector2d_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::gfx::mojom::Vector2dDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::gfx::mojom::Vector2dFDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::gfx::mojom::Vector2dFDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::gfx::mojom::internal::Vector2dF_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::gfx::mojom::internal::Vector2dF_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::gfx::mojom::internal::Vector2dF_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->x = CallWithContext(Traits::x, input, custom_context);
            result->y = CallWithContext(Traits::y, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::gfx::mojom::internal::Vector2dF_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::gfx::mojom::Vector2dFDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace gfx {
namespace mojom {

} // namespace mojom
} // namespace gfx

#endif // UI_GFX_GEOMETRY_MOJO_GEOMETRY_MOJOM_SHARED_H_
