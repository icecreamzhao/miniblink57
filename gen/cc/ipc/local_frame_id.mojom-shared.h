// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_LOCAL_FRAME_ID_MOJOM_SHARED_H_
#define CC_IPC_LOCAL_FRAME_ID_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "cc/ipc/local_frame_id.mojom-shared-internal.h"
#include "mojo/common/unguessable_token.mojom-shared.h"
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
    class LocalFrameIdDataView;

} // namespace mojom
} // namespace cc

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::cc::mojom::LocalFrameIdDataView> {
        using Data = ::cc::mojom::internal::LocalFrameId_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace cc {
namespace mojom {
    class LocalFrameIdDataView {
    public:
        LocalFrameIdDataView() { }

        LocalFrameIdDataView(
            internal::LocalFrameId_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t local_id() const
        {
            return data_->local_id;
        }
        inline void GetNonceDataView(
            ::mojo::common::mojom::UnguessableTokenDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadNonce(UserType* output)
        {
            auto* pointer = data_->nonce.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::UnguessableTokenDataView>(
                pointer, output, context_);
        }

    private:
        internal::LocalFrameId_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace cc

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::cc::mojom::LocalFrameIdDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::cc::mojom::LocalFrameIdDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::cc::mojom::internal::LocalFrameId_Data);
            decltype(CallWithContext(Traits::nonce, input, custom_context)) in_nonce = CallWithContext(Traits::nonce, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::UnguessableTokenDataView>(
                in_nonce, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::cc::mojom::internal::LocalFrameId_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::cc::mojom::internal::LocalFrameId_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->local_id = CallWithContext(Traits::local_id, input, custom_context);
            decltype(CallWithContext(Traits::nonce, input, custom_context)) in_nonce = CallWithContext(Traits::nonce, input, custom_context);
            typename decltype(result->nonce)::BaseType* nonce_ptr;
            mojo::internal::Serialize<::mojo::common::mojom::UnguessableTokenDataView>(
                in_nonce, buffer, &nonce_ptr, context);
            result->nonce.Set(nonce_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->nonce.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null nonce in LocalFrameId struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::cc::mojom::internal::LocalFrameId_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::cc::mojom::LocalFrameIdDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace cc {
namespace mojom {

    inline void LocalFrameIdDataView::GetNonceDataView(
        ::mojo::common::mojom::UnguessableTokenDataView* output)
    {
        auto pointer = data_->nonce.Get();
        *output = ::mojo::common::mojom::UnguessableTokenDataView(pointer, context_);
    }

} // namespace mojom
} // namespace cc

#endif // CC_IPC_LOCAL_FRAME_ID_MOJOM_SHARED_H_
