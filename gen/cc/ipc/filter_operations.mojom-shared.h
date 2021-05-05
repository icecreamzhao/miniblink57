// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_FILTER_OPERATIONS_MOJOM_SHARED_H_
#define CC_IPC_FILTER_OPERATIONS_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "cc/ipc/filter_operation.mojom-shared.h"
#include "cc/ipc/filter_operations.mojom-shared-internal.h"
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
    class FilterOperationsDataView;

} // namespace mojom
} // namespace cc

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::cc::mojom::FilterOperationsDataView> {
        using Data = ::cc::mojom::internal::FilterOperations_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace cc {
namespace mojom {
    class FilterOperationsDataView {
    public:
        FilterOperationsDataView() { }

        FilterOperationsDataView(
            internal::FilterOperations_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetOperationsDataView(
            mojo::ArrayDataView<::cc::mojom::FilterOperationDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOperations(UserType* output)
        {
            auto* pointer = data_->operations.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::cc::mojom::FilterOperationDataView>>(
                pointer, output, context_);
        }

    private:
        internal::FilterOperations_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace cc

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::cc::mojom::FilterOperationsDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::cc::mojom::FilterOperationsDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::cc::mojom::internal::FilterOperations_Data);
            decltype(CallWithContext(Traits::operations, input, custom_context)) in_operations = CallWithContext(Traits::operations, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::cc::mojom::FilterOperationDataView>>(
                in_operations, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::cc::mojom::internal::FilterOperations_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::cc::mojom::internal::FilterOperations_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::operations, input, custom_context)) in_operations = CallWithContext(Traits::operations, input, custom_context);
            typename decltype(result->operations)::BaseType* operations_ptr;
            const mojo::internal::ContainerValidateParams operations_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::cc::mojom::FilterOperationDataView>>(
                in_operations, buffer, &operations_ptr, &operations_validate_params,
                context);
            result->operations.Set(operations_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->operations.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null operations in FilterOperations struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::cc::mojom::internal::FilterOperations_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::cc::mojom::FilterOperationsDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace cc {
namespace mojom {

    inline void FilterOperationsDataView::GetOperationsDataView(
        mojo::ArrayDataView<::cc::mojom::FilterOperationDataView>* output)
    {
        auto pointer = data_->operations.Get();
        *output = mojo::ArrayDataView<::cc::mojom::FilterOperationDataView>(pointer, context_);
    }

} // namespace mojom
} // namespace cc

#endif // CC_IPC_FILTER_OPERATIONS_MOJOM_SHARED_H_
