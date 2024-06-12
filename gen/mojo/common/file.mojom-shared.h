// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MOJO_COMMON_FILE_MOJOM_SHARED_H_
#define MOJO_COMMON_FILE_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "mojo/common/file.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"

namespace mojo {
namespace common {
    namespace mojom {
        class FileDataView;

    } // namespace mojom
} // namespace common
} // namespace mojo

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::mojo::common::mojom::FileDataView> {
        using Data = ::mojo::common::mojom::internal::File_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace mojo {
namespace common {
    namespace mojom {
        class FileDataView {
        public:
            FileDataView() { }

            FileDataView(
                internal::File_Data* data,
                mojo::internal::SerializationContext* context)
                : data_(data)
                , context_(context)
            {
            }

            bool is_null() const { return !data_; }
            mojo::ScopedHandle TakeFd()
            {
                mojo::ScopedHandle result;
                bool ret = mojo::internal::Deserialize<mojo::ScopedHandle>(
                    &data_->fd, &result, context_);
                DCHECK(ret);
                return result;
            }

        private:
            internal::File_Data* data_ = nullptr;
            mojo::internal::SerializationContext* context_ = nullptr;
        };

    } // namespace mojom
} // namespace common
} // namespace mojo

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::mojo::common::mojom::FileDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::mojo::common::mojom::FileDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::mojo::common::mojom::internal::File_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::mojo::common::mojom::internal::File_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::mojo::common::mojom::internal::File_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::fd, input, custom_context)) in_fd = CallWithContext(Traits::fd, input, custom_context);
            mojo::internal::Serialize<mojo::ScopedHandle>(
                in_fd, &result->fd, context);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                !mojo::internal::IsHandleOrInterfaceValid(result->fd),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
                "invalid fd in File struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::mojo::common::mojom::internal::File_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::mojo::common::mojom::FileDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace mojo {
namespace common {
    namespace mojom {

    } // namespace mojom
} // namespace common
} // namespace mojo

#endif // MOJO_COMMON_FILE_MOJOM_SHARED_H_
