// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_GFX_MOJO_ICC_PROFILE_MOJOM_SHARED_H_
#define UI_GFX_MOJO_ICC_PROFILE_MOJOM_SHARED_H_

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
#include "ui/gfx/mojo/color_space.mojom-shared.h"
#include "ui/gfx/mojo/icc_profile.mojom-shared-internal.h"

namespace gfx {
namespace mojom {
    class ICCProfileDataView;

} // namespace mojom
} // namespace gfx

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::gfx::mojom::ICCProfileDataView> {
        using Data = ::gfx::mojom::internal::ICCProfile_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace gfx {
namespace mojom {
    using ICCProfile_Type = mojo::NativeEnum;
    class ICCProfileDataView {
    public:
        ICCProfileDataView() { }

        ICCProfileDataView(
            internal::ICCProfile_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetColorSpaceDataView(
            ::gfx::mojom::ColorSpaceDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadColorSpace(UserType* output)
        {
            auto* pointer = data_->color_space.Get();
            return mojo::internal::Deserialize<::gfx::mojom::ColorSpaceDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadType(UserType* output) const
        {
            auto data_value = data_->type;
            return mojo::internal::Deserialize<::gfx::mojom::ICCProfile_Type>(
                data_value, output);
        }

        ICCProfile_Type type() const
        {
            return static_cast<ICCProfile_Type>(data_->type);
        }
        inline void GetDataDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadData(UserType* output)
        {
            auto* pointer = data_->data.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        uint64_t id() const
        {
            return data_->id;
        }

    private:
        internal::ICCProfile_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace gfx

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::gfx::mojom::ICCProfileDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::gfx::mojom::ICCProfileDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::gfx::mojom::internal::ICCProfile_Data);
            decltype(CallWithContext(Traits::color_space, input, custom_context)) in_color_space = CallWithContext(Traits::color_space, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::ColorSpaceDataView>(
                in_color_space, context);
            decltype(CallWithContext(Traits::data, input, custom_context)) in_data = CallWithContext(Traits::data, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_data, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::gfx::mojom::internal::ICCProfile_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::gfx::mojom::internal::ICCProfile_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::color_space, input, custom_context)) in_color_space = CallWithContext(Traits::color_space, input, custom_context);
            typename decltype(result->color_space)::BaseType* color_space_ptr;
            mojo::internal::Serialize<::gfx::mojom::ColorSpaceDataView>(
                in_color_space, buffer, &color_space_ptr, context);
            result->color_space.Set(color_space_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->color_space.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null color_space in ICCProfile struct");
            mojo::internal::Serialize<::gfx::mojom::ICCProfile_Type>(
                CallWithContext(Traits::type, input, custom_context), &result->type);
            decltype(CallWithContext(Traits::data, input, custom_context)) in_data = CallWithContext(Traits::data, input, custom_context);
            typename decltype(result->data)::BaseType* data_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_data, buffer, &data_ptr, context);
            result->data.Set(data_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->data.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null data in ICCProfile struct");
            result->id = CallWithContext(Traits::id, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::gfx::mojom::internal::ICCProfile_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::gfx::mojom::ICCProfileDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace gfx {
namespace mojom {

    inline void ICCProfileDataView::GetColorSpaceDataView(
        ::gfx::mojom::ColorSpaceDataView* output)
    {
        auto pointer = data_->color_space.Get();
        *output = ::gfx::mojom::ColorSpaceDataView(pointer, context_);
    }
    inline void ICCProfileDataView::GetDataDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->data.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

} // namespace mojom
} // namespace gfx

#endif // UI_GFX_MOJO_ICC_PROFILE_MOJOM_SHARED_H_
