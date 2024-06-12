// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MOJO_COMMON_VALUES_MOJOM_SHARED_H_
#define MOJO_COMMON_VALUES_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "mojo/common/values.mojom-shared-internal.h"
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
        class ListValueDataView;

        class DictionaryValueDataView;

        class NullValueDataView;

        using LegacyListValueDataView = mojo::NativeStructDataView;

        class ValueDataView;

    } // namespace mojom
} // namespace common
} // namespace mojo

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::mojo::common::mojom::ListValueDataView> {
        using Data = ::mojo::common::mojom::internal::ListValue_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::mojo::common::mojom::DictionaryValueDataView> {
        using Data = ::mojo::common::mojom::internal::DictionaryValue_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::mojo::common::mojom::NullValueDataView> {
        using Data = ::mojo::common::mojom::internal::NullValue_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::mojo::common::mojom::ValueDataView> {
        using Data = ::mojo::common::mojom::internal::Value_Data;
        using DataAsArrayElement = Data;
        static constexpr MojomTypeCategory category = MojomTypeCategory::UNION;
    };

} // namespace internal
} // namespace mojo

namespace mojo {
namespace common {
    namespace mojom {
        class ListValueDataView {
        public:
            ListValueDataView() { }

            ListValueDataView(
                internal::ListValue_Data* data,
                mojo::internal::SerializationContext* context)
                : data_(data)
                , context_(context)
            {
            }

            bool is_null() const { return !data_; }
            inline void GetValuesDataView(
                mojo::ArrayDataView<ValueDataView>* output);

            template <typename UserType>
            WARN_UNUSED_RESULT bool ReadValues(UserType* output)
            {
                auto* pointer = data_->values.Get();
                return mojo::internal::Deserialize<mojo::ArrayDataView<::mojo::common::mojom::ValueDataView>>(
                    pointer, output, context_);
            }

        private:
            internal::ListValue_Data* data_ = nullptr;
            mojo::internal::SerializationContext* context_ = nullptr;
        };

        class DictionaryValueDataView {
        public:
            DictionaryValueDataView() { }

            DictionaryValueDataView(
                internal::DictionaryValue_Data* data,
                mojo::internal::SerializationContext* context)
                : data_(data)
                , context_(context)
            {
            }

            bool is_null() const { return !data_; }
            inline void GetValuesDataView(
                mojo::MapDataView<mojo::StringDataView, ValueDataView>* output);

            template <typename UserType>
            WARN_UNUSED_RESULT bool ReadValues(UserType* output)
            {
                auto* pointer = data_->values.Get();
                return mojo::internal::Deserialize<mojo::MapDataView<mojo::StringDataView, ::mojo::common::mojom::ValueDataView>>(
                    pointer, output, context_);
            }

        private:
            internal::DictionaryValue_Data* data_ = nullptr;
            mojo::internal::SerializationContext* context_ = nullptr;
        };

        class NullValueDataView {
        public:
            NullValueDataView() { }

            NullValueDataView(
                internal::NullValue_Data* data,
                mojo::internal::SerializationContext* context)
                : data_(data)
            {
            }

            bool is_null() const { return !data_; }

        private:
            internal::NullValue_Data* data_ = nullptr;
        };

        class ValueDataView {
        public:
            using Tag = internal::Value_Data::Value_Tag;

            ValueDataView() { }

            ValueDataView(
                internal::Value_Data* data,
                mojo::internal::SerializationContext* context)
                : data_(data)
                , context_(context)
            {
            }

            bool is_null() const
            {
                // For inlined unions, |data_| is always non-null. In that case we need to
                // check |data_->is_null()|.
                return !data_ || data_->is_null();
            }

            Tag tag() const { return data_->tag; }
            bool is_null_value() const { return data_->tag == Tag::NULL_VALUE; }
            inline void GetNullValueDataView(
                NullValueDataView* output);

            template <typename UserType>
            WARN_UNUSED_RESULT bool ReadNullValue(UserType* output)
            {
                DCHECK(is_null_value());
                return mojo::internal::Deserialize<::mojo::common::mojom::NullValueDataView>(
                    data_->data.f_null_value.Get(), output, context_);
            }
            bool is_bool_value() const { return data_->tag == Tag::BOOL_VALUE; }
            bool bool_value() const
            {
                DCHECK(is_bool_value());
                return data_->data.f_bool_value;
            }
            bool is_int_value() const { return data_->tag == Tag::INT_VALUE; }
            int32_t int_value() const
            {
                DCHECK(is_int_value());
                return data_->data.f_int_value;
            }
            bool is_double_value() const { return data_->tag == Tag::DOUBLE_VALUE; }
            double double_value() const
            {
                DCHECK(is_double_value());
                return data_->data.f_double_value;
            }
            bool is_string_value() const { return data_->tag == Tag::STRING_VALUE; }
            inline void GetStringValueDataView(
                mojo::StringDataView* output);

            template <typename UserType>
            WARN_UNUSED_RESULT bool ReadStringValue(UserType* output)
            {
                DCHECK(is_string_value());
                return mojo::internal::Deserialize<mojo::StringDataView>(
                    data_->data.f_string_value.Get(), output, context_);
            }
            bool is_binary_value() const { return data_->tag == Tag::BINARY_VALUE; }
            inline void GetBinaryValueDataView(
                mojo::ArrayDataView<uint8_t>* output);

            template <typename UserType>
            WARN_UNUSED_RESULT bool ReadBinaryValue(UserType* output)
            {
                DCHECK(is_binary_value());
                return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                    data_->data.f_binary_value.Get(), output, context_);
            }
            bool is_dictionary_value() const { return data_->tag == Tag::DICTIONARY_VALUE; }
            inline void GetDictionaryValueDataView(
                DictionaryValueDataView* output);

            template <typename UserType>
            WARN_UNUSED_RESULT bool ReadDictionaryValue(UserType* output)
            {
                DCHECK(is_dictionary_value());
                return mojo::internal::Deserialize<::mojo::common::mojom::DictionaryValueDataView>(
                    data_->data.f_dictionary_value.Get(), output, context_);
            }
            bool is_list_value() const { return data_->tag == Tag::LIST_VALUE; }
            inline void GetListValueDataView(
                ListValueDataView* output);

            template <typename UserType>
            WARN_UNUSED_RESULT bool ReadListValue(UserType* output)
            {
                DCHECK(is_list_value());
                return mojo::internal::Deserialize<::mojo::common::mojom::ListValueDataView>(
                    data_->data.f_list_value.Get(), output, context_);
            }

        private:
            internal::Value_Data* data_ = nullptr;
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
    struct Serializer<::mojo::common::mojom::ListValueDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::mojo::common::mojom::ListValueDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::mojo::common::mojom::internal::ListValue_Data);
            decltype(CallWithContext(Traits::values, input, custom_context)) in_values = CallWithContext(Traits::values, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::mojo::common::mojom::ValueDataView>>(
                in_values, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::mojo::common::mojom::internal::ListValue_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::mojo::common::mojom::internal::ListValue_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::values, input, custom_context)) in_values = CallWithContext(Traits::values, input, custom_context);
            typename decltype(result->values)::BaseType* values_ptr;
            const mojo::internal::ContainerValidateParams values_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::mojo::common::mojom::ValueDataView>>(
                in_values, buffer, &values_ptr, &values_validate_params,
                context);
            result->values.Set(values_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->values.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null values in ListValue struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::mojo::common::mojom::internal::ListValue_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::mojo::common::mojom::ListValueDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::mojo::common::mojom::DictionaryValueDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::mojo::common::mojom::DictionaryValueDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::mojo::common::mojom::internal::DictionaryValue_Data);
            decltype(CallWithContext(Traits::values, input, custom_context)) in_values = CallWithContext(Traits::values, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::MapDataView<mojo::StringDataView, ::mojo::common::mojom::ValueDataView>>(
                in_values, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::mojo::common::mojom::internal::DictionaryValue_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::mojo::common::mojom::internal::DictionaryValue_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::values, input, custom_context)) in_values = CallWithContext(Traits::values, input, custom_context);
            typename decltype(result->values)::BaseType* values_ptr;
            const mojo::internal::ContainerValidateParams values_validate_params(
                new mojo::internal::ContainerValidateParams(0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr)), new mojo::internal::ContainerValidateParams(0, false, nullptr));
            mojo::internal::Serialize<mojo::MapDataView<mojo::StringDataView, ::mojo::common::mojom::ValueDataView>>(
                in_values, buffer, &values_ptr, &values_validate_params,
                context);
            result->values.Set(values_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->values.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null values in DictionaryValue struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::mojo::common::mojom::internal::DictionaryValue_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::mojo::common::mojom::DictionaryValueDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::mojo::common::mojom::NullValueDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::mojo::common::mojom::NullValueDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::mojo::common::mojom::internal::NullValue_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::mojo::common::mojom::internal::NullValue_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::mojo::common::mojom::internal::NullValue_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::mojo::common::mojom::internal::NullValue_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::mojo::common::mojom::NullValueDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::mojo::common::mojom::ValueDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = UnionTraits<::mojo::common::mojom::ValueDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            bool inlined,
            SerializationContext* context)
        {
            size_t size = inlined ? 0 : sizeof(::mojo::common::mojom::internal::Value_Data);

            if (CallIsNullIfExists<Traits>(input))
                return size;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            switch (CallWithContext(Traits::GetTag, input, custom_context)) {
            case ::mojo::common::mojom::ValueDataView::Tag::NULL_VALUE: {
                decltype(CallWithContext(Traits::null_value, input, custom_context))
                    in_null_value
                    = CallWithContext(Traits::null_value, input,
                        custom_context);
                size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::NullValueDataView>(
                    in_null_value, context);
                break;
            }
            case ::mojo::common::mojom::ValueDataView::Tag::BOOL_VALUE: {
                break;
            }
            case ::mojo::common::mojom::ValueDataView::Tag::INT_VALUE: {
                break;
            }
            case ::mojo::common::mojom::ValueDataView::Tag::DOUBLE_VALUE: {
                break;
            }
            case ::mojo::common::mojom::ValueDataView::Tag::STRING_VALUE: {
                decltype(CallWithContext(Traits::string_value, input, custom_context))
                    in_string_value
                    = CallWithContext(Traits::string_value, input,
                        custom_context);
                size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                    in_string_value, context);
                break;
            }
            case ::mojo::common::mojom::ValueDataView::Tag::BINARY_VALUE: {
                decltype(CallWithContext(Traits::binary_value, input, custom_context))
                    in_binary_value
                    = CallWithContext(Traits::binary_value, input,
                        custom_context);
                size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
                    in_binary_value, context);
                break;
            }
            case ::mojo::common::mojom::ValueDataView::Tag::DICTIONARY_VALUE: {
                decltype(CallWithContext(Traits::dictionary_value, input, custom_context))
                    in_dictionary_value
                    = CallWithContext(Traits::dictionary_value, input,
                        custom_context);
                size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::DictionaryValueDataView>(
                    in_dictionary_value, context);
                break;
            }
            case ::mojo::common::mojom::ValueDataView::Tag::LIST_VALUE: {
                decltype(CallWithContext(Traits::list_value, input, custom_context))
                    in_list_value
                    = CallWithContext(Traits::list_value, input,
                        custom_context);
                size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::ListValueDataView>(
                    in_list_value, context);
                break;
            }
            }
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::mojo::common::mojom::internal::Value_Data** output,
            bool inlined,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                if (inlined)
                    (*output)->set_null();
                else
                    *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            if (!inlined)
                *output = ::mojo::common::mojom::internal::Value_Data::New(buffer);

            ::mojo::common::mojom::internal::Value_Data* result = *output;
            ALLOW_UNUSED_LOCAL(result);
            // TODO(azani): Handle unknown and objects.
            // Set the not-null flag.
            result->size = kUnionDataSize;
            result->tag = CallWithContext(Traits::GetTag, input, custom_context);
            switch (result->tag) {
            case ::mojo::common::mojom::ValueDataView::Tag::NULL_VALUE: {
                decltype(CallWithContext(Traits::null_value, input, custom_context))
                    in_null_value
                    = CallWithContext(Traits::null_value, input,
                        custom_context);
                typename decltype(result->data.f_null_value)::BaseType* ptr;
                mojo::internal::Serialize<::mojo::common::mojom::NullValueDataView>(
                    in_null_value, buffer, &ptr, context);
                result->data.f_null_value.Set(ptr);
                break;
            }
            case ::mojo::common::mojom::ValueDataView::Tag::BOOL_VALUE: {
                decltype(CallWithContext(Traits::bool_value, input, custom_context))
                    in_bool_value
                    = CallWithContext(Traits::bool_value, input,
                        custom_context);
                result->data.f_bool_value = in_bool_value;
                break;
            }
            case ::mojo::common::mojom::ValueDataView::Tag::INT_VALUE: {
                decltype(CallWithContext(Traits::int_value, input, custom_context))
                    in_int_value
                    = CallWithContext(Traits::int_value, input,
                        custom_context);
                result->data.f_int_value = in_int_value;
                break;
            }
            case ::mojo::common::mojom::ValueDataView::Tag::DOUBLE_VALUE: {
                decltype(CallWithContext(Traits::double_value, input, custom_context))
                    in_double_value
                    = CallWithContext(Traits::double_value, input,
                        custom_context);
                result->data.f_double_value = in_double_value;
                break;
            }
            case ::mojo::common::mojom::ValueDataView::Tag::STRING_VALUE: {
                decltype(CallWithContext(Traits::string_value, input, custom_context))
                    in_string_value
                    = CallWithContext(Traits::string_value, input,
                        custom_context);
                typename decltype(result->data.f_string_value)::BaseType* ptr;
                mojo::internal::Serialize<mojo::StringDataView>(
                    in_string_value, buffer, &ptr, context);
                result->data.f_string_value.Set(ptr);
                MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                    !ptr, mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                    "null string_value in Value union");
                break;
            }
            case ::mojo::common::mojom::ValueDataView::Tag::BINARY_VALUE: {
                decltype(CallWithContext(Traits::binary_value, input, custom_context))
                    in_binary_value
                    = CallWithContext(Traits::binary_value, input,
                        custom_context);
                typename decltype(result->data.f_binary_value)::BaseType* ptr;
                const ContainerValidateParams binary_value_validate_params(
                    0, false, nullptr);
                mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
                    in_binary_value, buffer, &ptr, &binary_value_validate_params, context);
                result->data.f_binary_value.Set(ptr);
                MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                    !ptr, mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                    "null binary_value in Value union");
                break;
            }
            case ::mojo::common::mojom::ValueDataView::Tag::DICTIONARY_VALUE: {
                decltype(CallWithContext(Traits::dictionary_value, input, custom_context))
                    in_dictionary_value
                    = CallWithContext(Traits::dictionary_value, input,
                        custom_context);
                typename decltype(result->data.f_dictionary_value)::BaseType* ptr;
                mojo::internal::Serialize<::mojo::common::mojom::DictionaryValueDataView>(
                    in_dictionary_value, buffer, &ptr, context);
                result->data.f_dictionary_value.Set(ptr);
                MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                    !ptr, mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                    "null dictionary_value in Value union");
                break;
            }
            case ::mojo::common::mojom::ValueDataView::Tag::LIST_VALUE: {
                decltype(CallWithContext(Traits::list_value, input, custom_context))
                    in_list_value
                    = CallWithContext(Traits::list_value, input,
                        custom_context);
                typename decltype(result->data.f_list_value)::BaseType* ptr;
                mojo::internal::Serialize<::mojo::common::mojom::ListValueDataView>(
                    in_list_value, buffer, &ptr, context);
                result->data.f_list_value.Set(ptr);
                MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                    !ptr, mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                    "null list_value in Value union");
                break;
            }
            }

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::mojo::common::mojom::internal::Value_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input || input->is_null())
                return CallSetToNullIfExists<Traits>(output);

            ::mojo::common::mojom::ValueDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace mojo {
namespace common {
    namespace mojom {

        inline void ListValueDataView::GetValuesDataView(
            mojo::ArrayDataView<ValueDataView>* output)
        {
            auto pointer = data_->values.Get();
            *output = mojo::ArrayDataView<ValueDataView>(pointer, context_);
        }

        inline void DictionaryValueDataView::GetValuesDataView(
            mojo::MapDataView<mojo::StringDataView, ValueDataView>* output)
        {
            auto pointer = data_->values.Get();
            *output = mojo::MapDataView<mojo::StringDataView, ValueDataView>(pointer, context_);
        }

        inline void ValueDataView::GetNullValueDataView(
            NullValueDataView* output)
        {
            DCHECK(is_null_value());
            *output = NullValueDataView(data_->data.f_null_value.Get(), context_);
        }
        inline void ValueDataView::GetStringValueDataView(
            mojo::StringDataView* output)
        {
            DCHECK(is_string_value());
            *output = mojo::StringDataView(data_->data.f_string_value.Get(), context_);
        }
        inline void ValueDataView::GetBinaryValueDataView(
            mojo::ArrayDataView<uint8_t>* output)
        {
            DCHECK(is_binary_value());
            *output = mojo::ArrayDataView<uint8_t>(data_->data.f_binary_value.Get(), context_);
        }
        inline void ValueDataView::GetDictionaryValueDataView(
            DictionaryValueDataView* output)
        {
            DCHECK(is_dictionary_value());
            *output = DictionaryValueDataView(data_->data.f_dictionary_value.Get(), context_);
        }
        inline void ValueDataView::GetListValueDataView(
            ListValueDataView* output)
        {
            DCHECK(is_list_value());
            *output = ListValueDataView(data_->data.f_list_value.Get(), context_);
        }

    } // namespace mojom
} // namespace common
} // namespace mojo

#endif // MOJO_COMMON_VALUES_MOJOM_SHARED_H_
