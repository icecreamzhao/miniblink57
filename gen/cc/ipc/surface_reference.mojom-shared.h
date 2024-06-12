// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_SURFACE_REFERENCE_MOJOM_SHARED_H_
#define CC_IPC_SURFACE_REFERENCE_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "cc/ipc/surface_id.mojom-shared.h"
#include "cc/ipc/surface_reference.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"

namespace cc {
namespace mojom {
    class SurfaceReferenceDataView;

} // namespace mojom
} // namespace cc

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::cc::mojom::SurfaceReferenceDataView> {
        using Data = ::cc::mojom::internal::SurfaceReference_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace cc {
namespace mojom {
    class SurfaceReferenceDataView {
    public:
        SurfaceReferenceDataView() { }

        SurfaceReferenceDataView(
            internal::SurfaceReference_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetParentIdDataView(
            ::cc::mojom::SurfaceIdDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadParentId(UserType* output)
        {
            auto* pointer = data_->parent_id.Get();
            return mojo::internal::Deserialize<::cc::mojom::SurfaceIdDataView>(
                pointer, output, context_);
        }
        inline void GetChildIdDataView(
            ::cc::mojom::SurfaceIdDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadChildId(UserType* output)
        {
            auto* pointer = data_->child_id.Get();
            return mojo::internal::Deserialize<::cc::mojom::SurfaceIdDataView>(
                pointer, output, context_);
        }

    private:
        internal::SurfaceReference_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace cc

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::cc::mojom::SurfaceReferenceDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::cc::mojom::SurfaceReferenceDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::cc::mojom::internal::SurfaceReference_Data);
            decltype(CallWithContext(Traits::parent_id, input, custom_context)) in_parent_id = CallWithContext(Traits::parent_id, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::cc::mojom::SurfaceIdDataView>(
                in_parent_id, context);
            decltype(CallWithContext(Traits::child_id, input, custom_context)) in_child_id = CallWithContext(Traits::child_id, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::cc::mojom::SurfaceIdDataView>(
                in_child_id, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::cc::mojom::internal::SurfaceReference_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::cc::mojom::internal::SurfaceReference_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::parent_id, input, custom_context)) in_parent_id = CallWithContext(Traits::parent_id, input, custom_context);
            typename decltype(result->parent_id)::BaseType* parent_id_ptr;
            mojo::internal::Serialize<::cc::mojom::SurfaceIdDataView>(
                in_parent_id, buffer, &parent_id_ptr, context);
            result->parent_id.Set(parent_id_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->parent_id.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null parent_id in SurfaceReference struct");
            decltype(CallWithContext(Traits::child_id, input, custom_context)) in_child_id = CallWithContext(Traits::child_id, input, custom_context);
            typename decltype(result->child_id)::BaseType* child_id_ptr;
            mojo::internal::Serialize<::cc::mojom::SurfaceIdDataView>(
                in_child_id, buffer, &child_id_ptr, context);
            result->child_id.Set(child_id_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->child_id.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null child_id in SurfaceReference struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::cc::mojom::internal::SurfaceReference_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::cc::mojom::SurfaceReferenceDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace cc {
namespace mojom {

    inline void SurfaceReferenceDataView::GetParentIdDataView(
        ::cc::mojom::SurfaceIdDataView* output)
    {
        auto pointer = data_->parent_id.Get();
        *output = ::cc::mojom::SurfaceIdDataView(pointer, context_);
    }
    inline void SurfaceReferenceDataView::GetChildIdDataView(
        ::cc::mojom::SurfaceIdDataView* output)
    {
        auto pointer = data_->child_id.Get();
        *output = ::cc::mojom::SurfaceIdDataView(pointer, context_);
    }

} // namespace mojom
} // namespace cc

#endif // CC_IPC_SURFACE_REFERENCE_MOJOM_SHARED_H_
