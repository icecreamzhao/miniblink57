// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_GFX_MOJO_TRANSFORM_MOJOM_SHARED_H_
#define UI_GFX_MOJO_TRANSFORM_MOJOM_SHARED_H_

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
#include "ui/gfx/mojo/transform.mojom-shared-internal.h"

namespace gfx {
namespace mojom {
    class TransformDataView;

} // namespace mojom
} // namespace gfx

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::gfx::mojom::TransformDataView> {
        using Data = ::gfx::mojom::internal::Transform_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace gfx {
namespace mojom {
    class TransformDataView {
    public:
        TransformDataView() { }

        TransformDataView(
            internal::Transform_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetMatrixDataView(
            mojo::ArrayDataView<float>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMatrix(UserType* output)
        {
            auto* pointer = data_->matrix.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<float>>(
                pointer, output, context_);
        }

    private:
        internal::Transform_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace gfx

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::gfx::mojom::TransformDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::gfx::mojom::TransformDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::gfx::mojom::internal::Transform_Data);
            decltype(CallWithContext(Traits::matrix, input, custom_context)) in_matrix = CallWithContext(Traits::matrix, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<float>>(
                in_matrix, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::gfx::mojom::internal::Transform_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::gfx::mojom::internal::Transform_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::matrix, input, custom_context)) in_matrix = CallWithContext(Traits::matrix, input, custom_context);
            typename decltype(result->matrix)::BaseType* matrix_ptr;
            const mojo::internal::ContainerValidateParams matrix_validate_params(
                16, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<float>>(
                in_matrix, buffer, &matrix_ptr, &matrix_validate_params,
                context);
            result->matrix.Set(matrix_ptr);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::gfx::mojom::internal::Transform_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::gfx::mojom::TransformDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace gfx {
namespace mojom {

    inline void TransformDataView::GetMatrixDataView(
        mojo::ArrayDataView<float>* output)
    {
        auto pointer = data_->matrix.Get();
        *output = mojo::ArrayDataView<float>(pointer, context_);
    }

} // namespace mojom
} // namespace gfx

#endif // UI_GFX_MOJO_TRANSFORM_MOJOM_SHARED_H_
