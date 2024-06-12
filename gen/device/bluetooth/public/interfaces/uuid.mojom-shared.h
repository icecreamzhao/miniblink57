// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_BLUETOOTH_PUBLIC_INTERFACES_UUID_MOJOM_SHARED_H_
#define DEVICE_BLUETOOTH_PUBLIC_INTERFACES_UUID_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "device/bluetooth/public/interfaces/uuid.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"

namespace bluetooth {
namespace mojom {
    class UUIDDataView;

} // namespace mojom
} // namespace bluetooth

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::bluetooth::mojom::UUIDDataView> {
        using Data = ::bluetooth::mojom::internal::UUID_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace bluetooth {
namespace mojom {
    class UUIDDataView {
    public:
        UUIDDataView() { }

        UUIDDataView(
            internal::UUID_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetUuidDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadUuid(UserType* output)
        {
            auto* pointer = data_->uuid.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::UUID_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace bluetooth

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::bluetooth::mojom::UUIDDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::bluetooth::mojom::UUIDDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::bluetooth::mojom::internal::UUID_Data);
            decltype(CallWithContext(Traits::uuid, input, custom_context)) in_uuid = CallWithContext(Traits::uuid, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_uuid, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::bluetooth::mojom::internal::UUID_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::bluetooth::mojom::internal::UUID_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::uuid, input, custom_context)) in_uuid = CallWithContext(Traits::uuid, input, custom_context);
            typename decltype(result->uuid)::BaseType* uuid_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_uuid, buffer, &uuid_ptr, context);
            result->uuid.Set(uuid_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->uuid.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null uuid in UUID struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::bluetooth::mojom::internal::UUID_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::bluetooth::mojom::UUIDDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace bluetooth {
namespace mojom {

    inline void UUIDDataView::GetUuidDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->uuid.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

} // namespace mojom
} // namespace bluetooth

#endif // DEVICE_BLUETOOTH_PUBLIC_INTERFACES_UUID_MOJOM_SHARED_H_
