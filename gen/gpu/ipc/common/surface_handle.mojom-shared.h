// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef GPU_IPC_COMMON_SURFACE_HANDLE_MOJOM_SHARED_H_
#define GPU_IPC_COMMON_SURFACE_HANDLE_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "gpu/ipc/common/surface_handle.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"

namespace gpu {
namespace mojom {
    class SurfaceHandleDataView;

} // namespace mojom
} // namespace gpu

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::gpu::mojom::SurfaceHandleDataView> {
        using Data = ::gpu::mojom::internal::SurfaceHandle_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace gpu {
namespace mojom {
    class SurfaceHandleDataView {
    public:
        SurfaceHandleDataView() { }

        SurfaceHandleDataView(
            internal::SurfaceHandle_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint64_t surface_handle() const
        {
            return data_->surface_handle;
        }

    private:
        internal::SurfaceHandle_Data* data_ = nullptr;
    };

} // namespace mojom
} // namespace gpu

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::gpu::mojom::SurfaceHandleDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::gpu::mojom::SurfaceHandleDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::gpu::mojom::internal::SurfaceHandle_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::gpu::mojom::internal::SurfaceHandle_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::gpu::mojom::internal::SurfaceHandle_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->surface_handle = CallWithContext(Traits::surface_handle, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::gpu::mojom::internal::SurfaceHandle_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::gpu::mojom::SurfaceHandleDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace gpu {
namespace mojom {

} // namespace mojom
} // namespace gpu

#endif // GPU_IPC_COMMON_SURFACE_HANDLE_MOJOM_SHARED_H_
