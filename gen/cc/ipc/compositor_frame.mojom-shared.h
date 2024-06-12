// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_COMPOSITOR_FRAME_MOJOM_SHARED_H_
#define CC_IPC_COMPOSITOR_FRAME_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "cc/ipc/compositor_frame.mojom-shared-internal.h"
#include "cc/ipc/compositor_frame_metadata.mojom-shared.h"
#include "cc/ipc/render_pass.mojom-shared.h"
#include "cc/ipc/transferable_resource.mojom-shared.h"
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
    class CompositorFrameDataView;

} // namespace mojom
} // namespace cc

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::cc::mojom::CompositorFrameDataView> {
        using Data = ::cc::mojom::internal::CompositorFrame_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace cc {
namespace mojom {
    class CompositorFrameDataView {
    public:
        CompositorFrameDataView() { }

        CompositorFrameDataView(
            internal::CompositorFrame_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetMetadataDataView(
            ::cc::mojom::CompositorFrameMetadataDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMetadata(UserType* output)
        {
            auto* pointer = data_->metadata.Get();
            return mojo::internal::Deserialize<::cc::mojom::CompositorFrameMetadataDataView>(
                pointer, output, context_);
        }
        inline void GetResourcesDataView(
            mojo::ArrayDataView<::cc::mojom::TransferableResourceDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadResources(UserType* output)
        {
            auto* pointer = data_->resources.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::cc::mojom::TransferableResourceDataView>>(
                pointer, output, context_);
        }
        inline void GetPassesDataView(
            mojo::ArrayDataView<::cc::mojom::RenderPassDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPasses(UserType* output)
        {
            auto* pointer = data_->passes.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::cc::mojom::RenderPassDataView>>(
                pointer, output, context_);
        }

    private:
        internal::CompositorFrame_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace cc

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::cc::mojom::CompositorFrameDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::cc::mojom::CompositorFrameDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::cc::mojom::internal::CompositorFrame_Data);
            decltype(CallWithContext(Traits::metadata, input, custom_context)) in_metadata = CallWithContext(Traits::metadata, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::cc::mojom::CompositorFrameMetadataDataView>(
                in_metadata, context);
            decltype(CallWithContext(Traits::resources, input, custom_context)) in_resources = CallWithContext(Traits::resources, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::cc::mojom::TransferableResourceDataView>>(
                in_resources, context);
            decltype(CallWithContext(Traits::passes, input, custom_context)) in_passes = CallWithContext(Traits::passes, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::cc::mojom::RenderPassDataView>>(
                in_passes, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::cc::mojom::internal::CompositorFrame_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::cc::mojom::internal::CompositorFrame_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::metadata, input, custom_context)) in_metadata = CallWithContext(Traits::metadata, input, custom_context);
            typename decltype(result->metadata)::BaseType* metadata_ptr;
            mojo::internal::Serialize<::cc::mojom::CompositorFrameMetadataDataView>(
                in_metadata, buffer, &metadata_ptr, context);
            result->metadata.Set(metadata_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->metadata.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null metadata in CompositorFrame struct");
            decltype(CallWithContext(Traits::resources, input, custom_context)) in_resources = CallWithContext(Traits::resources, input, custom_context);
            typename decltype(result->resources)::BaseType* resources_ptr;
            const mojo::internal::ContainerValidateParams resources_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::cc::mojom::TransferableResourceDataView>>(
                in_resources, buffer, &resources_ptr, &resources_validate_params,
                context);
            result->resources.Set(resources_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->resources.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null resources in CompositorFrame struct");
            decltype(CallWithContext(Traits::passes, input, custom_context)) in_passes = CallWithContext(Traits::passes, input, custom_context);
            typename decltype(result->passes)::BaseType* passes_ptr;
            const mojo::internal::ContainerValidateParams passes_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::cc::mojom::RenderPassDataView>>(
                in_passes, buffer, &passes_ptr, &passes_validate_params,
                context);
            result->passes.Set(passes_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->passes.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null passes in CompositorFrame struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::cc::mojom::internal::CompositorFrame_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::cc::mojom::CompositorFrameDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace cc {
namespace mojom {

    inline void CompositorFrameDataView::GetMetadataDataView(
        ::cc::mojom::CompositorFrameMetadataDataView* output)
    {
        auto pointer = data_->metadata.Get();
        *output = ::cc::mojom::CompositorFrameMetadataDataView(pointer, context_);
    }
    inline void CompositorFrameDataView::GetResourcesDataView(
        mojo::ArrayDataView<::cc::mojom::TransferableResourceDataView>* output)
    {
        auto pointer = data_->resources.Get();
        *output = mojo::ArrayDataView<::cc::mojom::TransferableResourceDataView>(pointer, context_);
    }
    inline void CompositorFrameDataView::GetPassesDataView(
        mojo::ArrayDataView<::cc::mojom::RenderPassDataView>* output)
    {
        auto pointer = data_->passes.Get();
        *output = mojo::ArrayDataView<::cc::mojom::RenderPassDataView>(pointer, context_);
    }

} // namespace mojom
} // namespace cc

#endif // CC_IPC_COMPOSITOR_FRAME_MOJOM_SHARED_H_
