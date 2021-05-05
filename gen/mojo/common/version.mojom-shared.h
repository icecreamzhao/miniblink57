// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MOJO_COMMON_VERSION_MOJOM_SHARED_H_
#define MOJO_COMMON_VERSION_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "mojo/common/version.mojom-shared-internal.h"
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
        class VersionDataView;

    } // namespace mojom
} // namespace common
} // namespace mojo

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::mojo::common::mojom::VersionDataView> {
        using Data = ::mojo::common::mojom::internal::Version_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace mojo {
namespace common {
    namespace mojom {
        class VersionDataView {
        public:
            VersionDataView() { }

            VersionDataView(
                internal::Version_Data* data,
                mojo::internal::SerializationContext* context)
                : data_(data)
                , context_(context)
            {
            }

            bool is_null() const { return !data_; }
            inline void GetComponentsDataView(
                mojo::ArrayDataView<uint32_t>* output);

            template <typename UserType>
            WARN_UNUSED_RESULT bool ReadComponents(UserType* output)
            {
                auto* pointer = data_->components.Get();
                return mojo::internal::Deserialize<mojo::ArrayDataView<uint32_t>>(
                    pointer, output, context_);
            }

        private:
            internal::Version_Data* data_ = nullptr;
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
    struct Serializer<::mojo::common::mojom::VersionDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::mojo::common::mojom::VersionDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::mojo::common::mojom::internal::Version_Data);
            decltype(CallWithContext(Traits::components, input, custom_context)) in_components = CallWithContext(Traits::components, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint32_t>>(
                in_components, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::mojo::common::mojom::internal::Version_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::mojo::common::mojom::internal::Version_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::components, input, custom_context)) in_components = CallWithContext(Traits::components, input, custom_context);
            typename decltype(result->components)::BaseType* components_ptr;
            const mojo::internal::ContainerValidateParams components_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<uint32_t>>(
                in_components, buffer, &components_ptr, &components_validate_params,
                context);
            result->components.Set(components_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->components.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null components in Version struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::mojo::common::mojom::internal::Version_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::mojo::common::mojom::VersionDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace mojo {
namespace common {
    namespace mojom {

        inline void VersionDataView::GetComponentsDataView(
            mojo::ArrayDataView<uint32_t>* output)
        {
            auto pointer = data_->components.Get();
            *output = mojo::ArrayDataView<uint32_t>(pointer, context_);
        }

    } // namespace mojom
} // namespace common
} // namespace mojo

#endif // MOJO_COMMON_VERSION_MOJOM_SHARED_H_
