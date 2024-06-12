// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_SURFACE_INFO_MOJOM_SHARED_H_
#define CC_IPC_SURFACE_INFO_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "cc/ipc/surface_id.mojom-shared.h"
#include "cc/ipc/surface_info.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared.h"

namespace cc {
namespace mojom {
    class SurfaceInfoDataView;

} // namespace mojom
} // namespace cc

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::cc::mojom::SurfaceInfoDataView> {
        using Data = ::cc::mojom::internal::SurfaceInfo_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace cc {
namespace mojom {
    class SurfaceInfoDataView {
    public:
        SurfaceInfoDataView() { }

        SurfaceInfoDataView(
            internal::SurfaceInfo_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetSurfaceIdDataView(
            ::cc::mojom::SurfaceIdDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSurfaceId(UserType* output)
        {
            auto* pointer = data_->surface_id.Get();
            return mojo::internal::Deserialize<::cc::mojom::SurfaceIdDataView>(
                pointer, output, context_);
        }
        float device_scale_factor() const
        {
            return data_->device_scale_factor;
        }
        inline void GetSizeInPixelsDataView(
            ::gfx::mojom::SizeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSizeInPixels(UserType* output)
        {
            auto* pointer = data_->size_in_pixels.Get();
            return mojo::internal::Deserialize<::gfx::mojom::SizeDataView>(
                pointer, output, context_);
        }

    private:
        internal::SurfaceInfo_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace cc

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::cc::mojom::SurfaceInfoDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::cc::mojom::SurfaceInfoDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::cc::mojom::internal::SurfaceInfo_Data);
            decltype(CallWithContext(Traits::surface_id, input, custom_context)) in_surface_id = CallWithContext(Traits::surface_id, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::cc::mojom::SurfaceIdDataView>(
                in_surface_id, context);
            decltype(CallWithContext(Traits::size_in_pixels, input, custom_context)) in_size_in_pixels = CallWithContext(Traits::size_in_pixels, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::SizeDataView>(
                in_size_in_pixels, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::cc::mojom::internal::SurfaceInfo_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::cc::mojom::internal::SurfaceInfo_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::surface_id, input, custom_context)) in_surface_id = CallWithContext(Traits::surface_id, input, custom_context);
            typename decltype(result->surface_id)::BaseType* surface_id_ptr;
            mojo::internal::Serialize<::cc::mojom::SurfaceIdDataView>(
                in_surface_id, buffer, &surface_id_ptr, context);
            result->surface_id.Set(surface_id_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->surface_id.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null surface_id in SurfaceInfo struct");
            result->device_scale_factor = CallWithContext(Traits::device_scale_factor, input, custom_context);
            decltype(CallWithContext(Traits::size_in_pixels, input, custom_context)) in_size_in_pixels = CallWithContext(Traits::size_in_pixels, input, custom_context);
            typename decltype(result->size_in_pixels)::BaseType* size_in_pixels_ptr;
            mojo::internal::Serialize<::gfx::mojom::SizeDataView>(
                in_size_in_pixels, buffer, &size_in_pixels_ptr, context);
            result->size_in_pixels.Set(size_in_pixels_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->size_in_pixels.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null size_in_pixels in SurfaceInfo struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::cc::mojom::internal::SurfaceInfo_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::cc::mojom::SurfaceInfoDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace cc {
namespace mojom {

    inline void SurfaceInfoDataView::GetSurfaceIdDataView(
        ::cc::mojom::SurfaceIdDataView* output)
    {
        auto pointer = data_->surface_id.Get();
        *output = ::cc::mojom::SurfaceIdDataView(pointer, context_);
    }
    inline void SurfaceInfoDataView::GetSizeInPixelsDataView(
        ::gfx::mojom::SizeDataView* output)
    {
        auto pointer = data_->size_in_pixels.Get();
        *output = ::gfx::mojom::SizeDataView(pointer, context_);
    }

} // namespace mojom
} // namespace cc

#endif // CC_IPC_SURFACE_INFO_MOJOM_SHARED_H_
