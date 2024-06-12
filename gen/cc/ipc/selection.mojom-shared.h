// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_IPC_SELECTION_MOJOM_SHARED_H_
#define CC_IPC_SELECTION_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "cc/ipc/selection.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "ui/gfx/mojo/selection_bound.mojom-shared.h"

namespace cc {
namespace mojom {
    class SelectionDataView;

} // namespace mojom
} // namespace cc

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::cc::mojom::SelectionDataView> {
        using Data = ::cc::mojom::internal::Selection_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace cc {
namespace mojom {
    class SelectionDataView {
    public:
        SelectionDataView() { }

        SelectionDataView(
            internal::Selection_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetStartDataView(
            ::gfx::mojom::SelectionBoundDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStart(UserType* output)
        {
            auto* pointer = data_->start.Get();
            return mojo::internal::Deserialize<::gfx::mojom::SelectionBoundDataView>(
                pointer, output, context_);
        }
        inline void GetEndDataView(
            ::gfx::mojom::SelectionBoundDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadEnd(UserType* output)
        {
            auto* pointer = data_->end.Get();
            return mojo::internal::Deserialize<::gfx::mojom::SelectionBoundDataView>(
                pointer, output, context_);
        }
        bool is_editable() const
        {
            return data_->is_editable;
        }
        bool is_empty_text_form_control() const
        {
            return data_->is_empty_text_form_control;
        }

    private:
        internal::Selection_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace cc

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::cc::mojom::SelectionDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::cc::mojom::SelectionDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::cc::mojom::internal::Selection_Data);
            decltype(CallWithContext(Traits::start, input, custom_context)) in_start = CallWithContext(Traits::start, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::SelectionBoundDataView>(
                in_start, context);
            decltype(CallWithContext(Traits::end, input, custom_context)) in_end = CallWithContext(Traits::end, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::SelectionBoundDataView>(
                in_end, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::cc::mojom::internal::Selection_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::cc::mojom::internal::Selection_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::start, input, custom_context)) in_start = CallWithContext(Traits::start, input, custom_context);
            typename decltype(result->start)::BaseType* start_ptr;
            mojo::internal::Serialize<::gfx::mojom::SelectionBoundDataView>(
                in_start, buffer, &start_ptr, context);
            result->start.Set(start_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->start.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null start in Selection struct");
            decltype(CallWithContext(Traits::end, input, custom_context)) in_end = CallWithContext(Traits::end, input, custom_context);
            typename decltype(result->end)::BaseType* end_ptr;
            mojo::internal::Serialize<::gfx::mojom::SelectionBoundDataView>(
                in_end, buffer, &end_ptr, context);
            result->end.Set(end_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->end.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null end in Selection struct");
            result->is_editable = CallWithContext(Traits::is_editable, input, custom_context);
            result->is_empty_text_form_control = CallWithContext(Traits::is_empty_text_form_control, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::cc::mojom::internal::Selection_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::cc::mojom::SelectionDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace cc {
namespace mojom {

    inline void SelectionDataView::GetStartDataView(
        ::gfx::mojom::SelectionBoundDataView* output)
    {
        auto pointer = data_->start.Get();
        *output = ::gfx::mojom::SelectionBoundDataView(pointer, context_);
    }
    inline void SelectionDataView::GetEndDataView(
        ::gfx::mojom::SelectionBoundDataView* output)
    {
        auto pointer = data_->end.Get();
        *output = ::gfx::mojom::SelectionBoundDataView(pointer, context_);
    }

} // namespace mojom
} // namespace cc

#endif // CC_IPC_SELECTION_MOJOM_SHARED_H_
