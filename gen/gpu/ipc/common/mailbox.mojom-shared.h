// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef GPU_IPC_COMMON_MAILBOX_MOJOM_SHARED_H_
#define GPU_IPC_COMMON_MAILBOX_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "gpu/ipc/common/mailbox.mojom-shared-internal.h"
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
    class MailboxDataView;

} // namespace mojom
} // namespace gpu

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::gpu::mojom::MailboxDataView> {
        using Data = ::gpu::mojom::internal::Mailbox_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace gpu {
namespace mojom {
    class MailboxDataView {
    public:
        MailboxDataView() { }

        MailboxDataView(
            internal::Mailbox_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetNameDataView(
            mojo::ArrayDataView<int8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadName(UserType* output)
        {
            auto* pointer = data_->name.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<int8_t>>(
                pointer, output, context_);
        }

    private:
        internal::Mailbox_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace gpu

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::gpu::mojom::MailboxDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::gpu::mojom::MailboxDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::gpu::mojom::internal::Mailbox_Data);
            decltype(CallWithContext(Traits::name, input, custom_context)) in_name = CallWithContext(Traits::name, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<int8_t>>(
                in_name, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::gpu::mojom::internal::Mailbox_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::gpu::mojom::internal::Mailbox_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::name, input, custom_context)) in_name = CallWithContext(Traits::name, input, custom_context);
            typename decltype(result->name)::BaseType* name_ptr;
            const mojo::internal::ContainerValidateParams name_validate_params(
                16, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<int8_t>>(
                in_name, buffer, &name_ptr, &name_validate_params,
                context);
            result->name.Set(name_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->name.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null name in Mailbox struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::gpu::mojom::internal::Mailbox_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::gpu::mojom::MailboxDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace gpu {
namespace mojom {

    inline void MailboxDataView::GetNameDataView(
        mojo::ArrayDataView<int8_t>* output)
    {
        auto pointer = data_->name.Get();
        *output = mojo::ArrayDataView<int8_t>(pointer, context_);
    }

} // namespace mojom
} // namespace gpu

#endif // GPU_IPC_COMMON_MAILBOX_MOJOM_SHARED_H_
