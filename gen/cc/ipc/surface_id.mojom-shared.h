// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_SURFACE_ID_MOJOM_SHARED_H_
#define CC_IPC_SURFACE_ID_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "cc/ipc/frame_sink_id.mojom-shared.h"
#include "cc/ipc/local_frame_id.mojom-shared.h"
#include "cc/ipc/surface_id.mojom-shared-internal.h"
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
    class SurfaceIdDataView;

} // namespace mojom
} // namespace cc

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::cc::mojom::SurfaceIdDataView> {
        using Data = ::cc::mojom::internal::SurfaceId_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace cc {
namespace mojom {
    class SurfaceIdDataView {
    public:
        SurfaceIdDataView() { }

        SurfaceIdDataView(
            internal::SurfaceId_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetFrameSinkIdDataView(
            ::cc::mojom::FrameSinkIdDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFrameSinkId(UserType* output)
        {
            auto* pointer = data_->frame_sink_id.Get();
            return mojo::internal::Deserialize<::cc::mojom::FrameSinkIdDataView>(
                pointer, output, context_);
        }
        inline void GetLocalFrameIdDataView(
            ::cc::mojom::LocalFrameIdDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadLocalFrameId(UserType* output)
        {
            auto* pointer = data_->local_frame_id.Get();
            return mojo::internal::Deserialize<::cc::mojom::LocalFrameIdDataView>(
                pointer, output, context_);
        }

    private:
        internal::SurfaceId_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace cc

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::cc::mojom::SurfaceIdDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::cc::mojom::SurfaceIdDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::cc::mojom::internal::SurfaceId_Data);
            decltype(CallWithContext(Traits::frame_sink_id, input, custom_context)) in_frame_sink_id = CallWithContext(Traits::frame_sink_id, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::cc::mojom::FrameSinkIdDataView>(
                in_frame_sink_id, context);
            decltype(CallWithContext(Traits::local_frame_id, input, custom_context)) in_local_frame_id = CallWithContext(Traits::local_frame_id, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::cc::mojom::LocalFrameIdDataView>(
                in_local_frame_id, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::cc::mojom::internal::SurfaceId_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::cc::mojom::internal::SurfaceId_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::frame_sink_id, input, custom_context)) in_frame_sink_id = CallWithContext(Traits::frame_sink_id, input, custom_context);
            typename decltype(result->frame_sink_id)::BaseType* frame_sink_id_ptr;
            mojo::internal::Serialize<::cc::mojom::FrameSinkIdDataView>(
                in_frame_sink_id, buffer, &frame_sink_id_ptr, context);
            result->frame_sink_id.Set(frame_sink_id_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->frame_sink_id.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null frame_sink_id in SurfaceId struct");
            decltype(CallWithContext(Traits::local_frame_id, input, custom_context)) in_local_frame_id = CallWithContext(Traits::local_frame_id, input, custom_context);
            typename decltype(result->local_frame_id)::BaseType* local_frame_id_ptr;
            mojo::internal::Serialize<::cc::mojom::LocalFrameIdDataView>(
                in_local_frame_id, buffer, &local_frame_id_ptr, context);
            result->local_frame_id.Set(local_frame_id_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->local_frame_id.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null local_frame_id in SurfaceId struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::cc::mojom::internal::SurfaceId_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::cc::mojom::SurfaceIdDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace cc {
namespace mojom {

    inline void SurfaceIdDataView::GetFrameSinkIdDataView(
        ::cc::mojom::FrameSinkIdDataView* output)
    {
        auto pointer = data_->frame_sink_id.Get();
        *output = ::cc::mojom::FrameSinkIdDataView(pointer, context_);
    }
    inline void SurfaceIdDataView::GetLocalFrameIdDataView(
        ::cc::mojom::LocalFrameIdDataView* output)
    {
        auto pointer = data_->local_frame_id.Get();
        *output = ::cc::mojom::LocalFrameIdDataView(pointer, context_);
    }

} // namespace mojom
} // namespace cc

#endif // CC_IPC_SURFACE_ID_MOJOM_SHARED_H_
