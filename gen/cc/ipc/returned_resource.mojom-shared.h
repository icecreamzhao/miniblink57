// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_RETURNED_RESOURCE_MOJOM_SHARED_H_
#define CC_IPC_RETURNED_RESOURCE_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "cc/ipc/returned_resource.mojom-shared-internal.h"
#include "gpu/ipc/common/sync_token.mojom-shared.h"
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
    class ReturnedResourceDataView;

    class ReturnedResourceArrayDataView;

} // namespace mojom
} // namespace cc

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::cc::mojom::ReturnedResourceDataView> {
        using Data = ::cc::mojom::internal::ReturnedResource_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::cc::mojom::ReturnedResourceArrayDataView> {
        using Data = ::cc::mojom::internal::ReturnedResourceArray_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace cc {
namespace mojom {
    class ReturnedResourceDataView {
    public:
        ReturnedResourceDataView() { }

        ReturnedResourceDataView(
            internal::ReturnedResource_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t id() const
        {
            return data_->id;
        }
        inline void GetSyncTokenDataView(
            ::gpu::mojom::SyncTokenDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSyncToken(UserType* output)
        {
            auto* pointer = data_->sync_token.Get();
            return mojo::internal::Deserialize<::gpu::mojom::SyncTokenDataView>(
                pointer, output, context_);
        }
        int32_t count() const
        {
            return data_->count;
        }
        bool lost() const
        {
            return data_->lost;
        }

    private:
        internal::ReturnedResource_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class ReturnedResourceArrayDataView {
    public:
        ReturnedResourceArrayDataView() { }

        ReturnedResourceArrayDataView(
            internal::ReturnedResourceArray_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetReturnedResourcesDataView(
            mojo::ArrayDataView<ReturnedResourceDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadReturnedResources(UserType* output)
        {
            auto* pointer = data_->returned_resources.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::cc::mojom::ReturnedResourceDataView>>(
                pointer, output, context_);
        }

    private:
        internal::ReturnedResourceArray_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace cc

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::cc::mojom::ReturnedResourceDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::cc::mojom::ReturnedResourceDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::cc::mojom::internal::ReturnedResource_Data);
            decltype(CallWithContext(Traits::sync_token, input, custom_context)) in_sync_token = CallWithContext(Traits::sync_token, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gpu::mojom::SyncTokenDataView>(
                in_sync_token, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::cc::mojom::internal::ReturnedResource_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::cc::mojom::internal::ReturnedResource_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->id = CallWithContext(Traits::id, input, custom_context);
            decltype(CallWithContext(Traits::sync_token, input, custom_context)) in_sync_token = CallWithContext(Traits::sync_token, input, custom_context);
            typename decltype(result->sync_token)::BaseType* sync_token_ptr;
            mojo::internal::Serialize<::gpu::mojom::SyncTokenDataView>(
                in_sync_token, buffer, &sync_token_ptr, context);
            result->sync_token.Set(sync_token_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->sync_token.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null sync_token in ReturnedResource struct");
            result->count = CallWithContext(Traits::count, input, custom_context);
            result->lost = CallWithContext(Traits::lost, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::cc::mojom::internal::ReturnedResource_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::cc::mojom::ReturnedResourceDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::cc::mojom::ReturnedResourceArrayDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::cc::mojom::ReturnedResourceArrayDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::cc::mojom::internal::ReturnedResourceArray_Data);
            decltype(CallWithContext(Traits::returned_resources, input, custom_context)) in_returned_resources = CallWithContext(Traits::returned_resources, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::cc::mojom::ReturnedResourceDataView>>(
                in_returned_resources, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::cc::mojom::internal::ReturnedResourceArray_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::cc::mojom::internal::ReturnedResourceArray_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::returned_resources, input, custom_context)) in_returned_resources = CallWithContext(Traits::returned_resources, input, custom_context);
            typename decltype(result->returned_resources)::BaseType* returned_resources_ptr;
            const mojo::internal::ContainerValidateParams returned_resources_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::cc::mojom::ReturnedResourceDataView>>(
                in_returned_resources, buffer, &returned_resources_ptr, &returned_resources_validate_params,
                context);
            result->returned_resources.Set(returned_resources_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->returned_resources.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null returned_resources in ReturnedResourceArray struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::cc::mojom::internal::ReturnedResourceArray_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::cc::mojom::ReturnedResourceArrayDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace cc {
namespace mojom {

    inline void ReturnedResourceDataView::GetSyncTokenDataView(
        ::gpu::mojom::SyncTokenDataView* output)
    {
        auto pointer = data_->sync_token.Get();
        *output = ::gpu::mojom::SyncTokenDataView(pointer, context_);
    }

    inline void ReturnedResourceArrayDataView::GetReturnedResourcesDataView(
        mojo::ArrayDataView<ReturnedResourceDataView>* output)
    {
        auto pointer = data_->returned_resources.Get();
        *output = mojo::ArrayDataView<ReturnedResourceDataView>(pointer, context_);
    }

} // namespace mojom
} // namespace cc

#endif // CC_IPC_RETURNED_RESOURCE_MOJOM_SHARED_H_
