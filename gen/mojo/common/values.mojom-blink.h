// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MOJO_COMMON_VALUES_MOJOM_BLINK_H_
#define MOJO_COMMON_VALUES_MOJOM_BLINK_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "mojo/common/values.mojom-shared.h"
#include "mojo/public/cpp/bindings/associated_interface_ptr.h"
#include "mojo/public/cpp/bindings/associated_interface_ptr_info.h"
#include "mojo/public/cpp/bindings/associated_interface_request.h"
#include "mojo/public/cpp/bindings/interface_ptr.h"
#include "mojo/public/cpp/bindings/interface_request.h"
#include "mojo/public/cpp/bindings/lib/clone_equals_util.h"
#include "mojo/public/cpp/bindings/lib/control_message_handler.h"
#include "mojo/public/cpp/bindings/lib/control_message_proxy.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/lib/union_accessor.h"
#include "mojo/public/cpp/bindings/native_struct.h"
#include "mojo/public/cpp/bindings/no_interface.h"
#include "mojo/public/cpp/bindings/raw_ptr_impl_ref_traits.h"
#include "mojo/public/cpp/bindings/struct_ptr.h"
#include "mojo/public/cpp/bindings/struct_traits.h"
#include "mojo/public/cpp/bindings/thread_safe_interface_ptr.h"
#include "mojo/public/cpp/bindings/union_traits.h"

#include "base/files/file.h"
#include "mojo/public/cpp/bindings/lib/wtf_hash_util.h"
#include "third_party/WebKit/Source/wtf/HashFunctions.h"
#include "third_party/WebKit/Source/wtf/Optional.h"
#include "third_party/WebKit/Source/wtf/text/WTFString.h"

namespace mojo {
namespace common {
    namespace mojom {
        namespace blink {
            class ListValue;
            using ListValuePtr = mojo::StructPtr<ListValue>;

            class DictionaryValue;
            using DictionaryValuePtr = mojo::StructPtr<DictionaryValue>;

            class NullValue;
            using NullValuePtr = mojo::InlinedStructPtr<NullValue>;

            using LegacyListValue = mojo::NativeStruct;
            using LegacyListValuePtr = mojo::NativeStructPtr;

            class Value;

            typedef mojo::StructPtr<Value> ValuePtr;

            class NullValue {
            public:
                using DataView = NullValueDataView;
                using Data_ = internal::NullValue_Data;

                static NullValuePtr New();

                template <typename U>
                static NullValuePtr From(const U& u)
                {
                    return mojo::TypeConverter<NullValuePtr, U>::Convert(u);
                }

                template <typename U>
                U To() const
                {
                    return mojo::TypeConverter<U, NullValue>::Convert(*this);
                }

                NullValue();
                ~NullValue();

                // Clone() is a template so it is only instantiated if it is used. Thus, the
                // bindings generator does not need to know whether Clone() or copy
                // constructor/assignment are available for members.
                template <typename StructPtrType = NullValuePtr>
                NullValuePtr Clone() const;

                // Equals() is a template so it is only instantiated if it is used. Thus, the
                // bindings generator does not need to know whether Equals() or == operator
                // are available for members.
                template <typename T,
                    typename std::enable_if<std::is_same<
                        T, NullValue>::value>::type* = nullptr>
                bool Equals(const T& other) const;
                size_t Hash(size_t seed) const;

                template <typename UserType>
                static WTF::Vector<uint8_t> Serialize(UserType* input)
                {
                    return mojo::internal::StructSerializeImpl<
                        NullValue::DataView, WTF::Vector<uint8_t>>(input);
                }

                template <typename UserType>
                static bool Deserialize(const WTF::Vector<uint8_t>& input,
                    UserType* output)
                {
                    return mojo::internal::StructDeserializeImpl<
                        NullValue::DataView, WTF::Vector<uint8_t>>(
                        input, output);
                }
            };

            class Value {
            public:
                using DataView = ValueDataView;
                using Data_ = internal::Value_Data;
                using Tag = Data_::Value_Tag;

                static ValuePtr New();

                template <typename U>
                static ValuePtr From(const U& u)
                {
                    return mojo::TypeConverter<ValuePtr, U>::Convert(u);
                }

                template <typename U>
                U To() const
                {
                    return mojo::TypeConverter<U, Value>::Convert(*this);
                }

                Value();
                ~Value();

                // Clone() is a template so it is only instantiated if it is used. Thus, the
                // bindings generator does not need to know whether Clone() or copy
                // constructor/assignment are available for members.
                template <typename UnionPtrType = ValuePtr>
                ValuePtr Clone() const;

                // Equals() is a template so it is only instantiated if it is used. Thus, the
                // bindings generator does not need to know whether Equals() or == operator
                // are available for members.
                template <typename T,
                    typename std::enable_if<std::is_same<
                        T, Value>::value>::type* = nullptr>
                bool Equals(const T& other) const;

                Tag which() const
                {
                    return tag_;
                }

                bool is_null_value() const { return tag_ == Tag::NULL_VALUE; }

                NullValuePtr& get_null_value() const
                {
                    DCHECK(tag_ == Tag::NULL_VALUE);
                    return *(data_.null_value);
                }

                void set_null_value(NullValuePtr null_value);
                bool is_bool_value() const { return tag_ == Tag::BOOL_VALUE; }

                bool get_bool_value() const
                {
                    DCHECK(tag_ == Tag::BOOL_VALUE);
                    return data_.bool_value;
                }

                void set_bool_value(bool bool_value);
                bool is_int_value() const { return tag_ == Tag::INT_VALUE; }

                int32_t get_int_value() const
                {
                    DCHECK(tag_ == Tag::INT_VALUE);
                    return data_.int_value;
                }

                void set_int_value(int32_t int_value);
                bool is_double_value() const { return tag_ == Tag::DOUBLE_VALUE; }

                double get_double_value() const
                {
                    DCHECK(tag_ == Tag::DOUBLE_VALUE);
                    return data_.double_value;
                }

                void set_double_value(double double_value);
                bool is_string_value() const { return tag_ == Tag::STRING_VALUE; }

                WTF::String& get_string_value() const
                {
                    DCHECK(tag_ == Tag::STRING_VALUE);
                    return *(data_.string_value);
                }

                void set_string_value(const WTF::String& string_value);
                bool is_binary_value() const { return tag_ == Tag::BINARY_VALUE; }

                WTF::Vector<uint8_t>& get_binary_value() const
                {
                    DCHECK(tag_ == Tag::BINARY_VALUE);
                    return *(data_.binary_value);
                }

                void set_binary_value(const WTF::Vector<uint8_t>& binary_value);
                bool is_dictionary_value() const { return tag_ == Tag::DICTIONARY_VALUE; }

                DictionaryValuePtr& get_dictionary_value() const
                {
                    DCHECK(tag_ == Tag::DICTIONARY_VALUE);
                    return *(data_.dictionary_value);
                }

                void set_dictionary_value(DictionaryValuePtr dictionary_value);
                bool is_list_value() const { return tag_ == Tag::LIST_VALUE; }

                ListValuePtr& get_list_value() const
                {
                    DCHECK(tag_ == Tag::LIST_VALUE);
                    return *(data_.list_value);
                }

                void set_list_value(ListValuePtr list_value);

            private:
                friend class mojo::internal::UnionAccessor<Value>;
                union Union_ {
                    Union_() { }
                    ~Union_() { }
                    NullValuePtr* null_value;
                    bool bool_value;
                    int32_t int_value;
                    double double_value;
                    WTF::String* string_value;
                    WTF::Vector<uint8_t>* binary_value;
                    DictionaryValuePtr* dictionary_value;
                    ListValuePtr* list_value;
                };
                void SwitchActive(Tag new_active);
                void SetActive(Tag new_active);
                void DestroyActive();
                Tag tag_;
                Union_ data_;
            };

            class ListValue {
            public:
                using DataView = ListValueDataView;
                using Data_ = internal::ListValue_Data;

                static ListValuePtr New();

                template <typename U>
                static ListValuePtr From(const U& u)
                {
                    return mojo::TypeConverter<ListValuePtr, U>::Convert(u);
                }

                template <typename U>
                U To() const
                {
                    return mojo::TypeConverter<U, ListValue>::Convert(*this);
                }

                ListValue();
                ~ListValue();

                // Clone() is a template so it is only instantiated if it is used. Thus, the
                // bindings generator does not need to know whether Clone() or copy
                // constructor/assignment are available for members.
                template <typename StructPtrType = ListValuePtr>
                ListValuePtr Clone() const;

                // Equals() is a template so it is only instantiated if it is used. Thus, the
                // bindings generator does not need to know whether Equals() or == operator
                // are available for members.
                template <typename T,
                    typename std::enable_if<std::is_same<
                        T, ListValue>::value>::type* = nullptr>
                bool Equals(const T& other) const;

                template <typename UserType>
                static WTF::Vector<uint8_t> Serialize(UserType* input)
                {
                    return mojo::internal::StructSerializeImpl<
                        ListValue::DataView, WTF::Vector<uint8_t>>(input);
                }

                template <typename UserType>
                static bool Deserialize(const WTF::Vector<uint8_t>& input,
                    UserType* output)
                {
                    return mojo::internal::StructDeserializeImpl<
                        ListValue::DataView, WTF::Vector<uint8_t>>(
                        input, output);
                }

                WTF::Vector<ValuePtr> values;

            private:
                DISALLOW_COPY_AND_ASSIGN(ListValue);
            };

            class DictionaryValue {
            public:
                using DataView = DictionaryValueDataView;
                using Data_ = internal::DictionaryValue_Data;

                static DictionaryValuePtr New();

                template <typename U>
                static DictionaryValuePtr From(const U& u)
                {
                    return mojo::TypeConverter<DictionaryValuePtr, U>::Convert(u);
                }

                template <typename U>
                U To() const
                {
                    return mojo::TypeConverter<U, DictionaryValue>::Convert(*this);
                }

                DictionaryValue();
                ~DictionaryValue();

                // Clone() is a template so it is only instantiated if it is used. Thus, the
                // bindings generator does not need to know whether Clone() or copy
                // constructor/assignment are available for members.
                template <typename StructPtrType = DictionaryValuePtr>
                DictionaryValuePtr Clone() const;

                // Equals() is a template so it is only instantiated if it is used. Thus, the
                // bindings generator does not need to know whether Equals() or == operator
                // are available for members.
                template <typename T,
                    typename std::enable_if<std::is_same<
                        T, DictionaryValue>::value>::type* = nullptr>
                bool Equals(const T& other) const;

                template <typename UserType>
                static WTF::Vector<uint8_t> Serialize(UserType* input)
                {
                    return mojo::internal::StructSerializeImpl<
                        DictionaryValue::DataView, WTF::Vector<uint8_t>>(input);
                }

                template <typename UserType>
                static bool Deserialize(const WTF::Vector<uint8_t>& input,
                    UserType* output)
                {
                    return mojo::internal::StructDeserializeImpl<
                        DictionaryValue::DataView, WTF::Vector<uint8_t>>(
                        input, output);
                }

                WTF::HashMap<WTF::String, ValuePtr> values;

            private:
                DISALLOW_COPY_AND_ASSIGN(DictionaryValue);
            };

            template <typename UnionPtrType>
            ValuePtr Value::Clone() const
            {
                // Use UnionPtrType to prevent the compiler from trying to compile this
                // without being asked.
                UnionPtrType rv(New());
                switch (tag_) {
                case Tag::NULL_VALUE:
                    rv->set_null_value(mojo::internal::Clone(*data_.null_value));
                    break;
                case Tag::BOOL_VALUE:
                    rv->set_bool_value(mojo::internal::Clone(data_.bool_value));
                    break;
                case Tag::INT_VALUE:
                    rv->set_int_value(mojo::internal::Clone(data_.int_value));
                    break;
                case Tag::DOUBLE_VALUE:
                    rv->set_double_value(mojo::internal::Clone(data_.double_value));
                    break;
                case Tag::STRING_VALUE:
                    rv->set_string_value(mojo::internal::Clone(*data_.string_value));
                    break;
                case Tag::BINARY_VALUE:
                    rv->set_binary_value(mojo::internal::Clone(*data_.binary_value));
                    break;
                case Tag::DICTIONARY_VALUE:
                    rv->set_dictionary_value(mojo::internal::Clone(*data_.dictionary_value));
                    break;
                case Tag::LIST_VALUE:
                    rv->set_list_value(mojo::internal::Clone(*data_.list_value));
                    break;
                };
                return rv;
            }

            template <typename T,
                typename std::enable_if<std::is_same<
                    T, Value>::value>::type*>
            bool Value::Equals(const T& other) const
            {
                if (tag_ != other.which())
                    return false;

                switch (tag_) {
                case Tag::NULL_VALUE:
                    return mojo::internal::Equals(*(data_.null_value), *(other.data_.null_value));
                case Tag::BOOL_VALUE:
                    return mojo::internal::Equals(data_.bool_value, other.data_.bool_value);
                case Tag::INT_VALUE:
                    return mojo::internal::Equals(data_.int_value, other.data_.int_value);
                case Tag::DOUBLE_VALUE:
                    return mojo::internal::Equals(data_.double_value, other.data_.double_value);
                case Tag::STRING_VALUE:
                    return mojo::internal::Equals(*(data_.string_value), *(other.data_.string_value));
                case Tag::BINARY_VALUE:
                    return mojo::internal::Equals(*(data_.binary_value), *(other.data_.binary_value));
                case Tag::DICTIONARY_VALUE:
                    return mojo::internal::Equals(*(data_.dictionary_value), *(other.data_.dictionary_value));
                case Tag::LIST_VALUE:
                    return mojo::internal::Equals(*(data_.list_value), *(other.data_.list_value));
                };

                return false;
            }
            template <typename StructPtrType>
            ListValuePtr ListValue::Clone() const
            {
                // Use StructPtrType to prevent the compiler from trying to compile this
                // without being asked.
                StructPtrType rv(New());
                rv->values = mojo::internal::Clone(values);
                return rv;
            }

            template <typename T,
                typename std::enable_if<std::is_same<
                    T, ListValue>::value>::type*>
            bool ListValue::Equals(const T& other) const
            {
                if (!mojo::internal::Equals(this->values, other.values))
                    return false;
                return true;
            }
            template <typename StructPtrType>
            DictionaryValuePtr DictionaryValue::Clone() const
            {
                // Use StructPtrType to prevent the compiler from trying to compile this
                // without being asked.
                StructPtrType rv(New());
                rv->values = mojo::internal::Clone(values);
                return rv;
            }

            template <typename T,
                typename std::enable_if<std::is_same<
                    T, DictionaryValue>::value>::type*>
            bool DictionaryValue::Equals(const T& other) const
            {
                if (!mojo::internal::Equals(this->values, other.values))
                    return false;
                return true;
            }
            template <typename StructPtrType>
            NullValuePtr NullValue::Clone() const
            {
                // Use StructPtrType to prevent the compiler from trying to compile this
                // without being asked.
                StructPtrType rv(New());
                return rv;
            }

            template <typename T,
                typename std::enable_if<std::is_same<
                    T, NullValue>::value>::type*>
            bool NullValue::Equals(const T& other) const
            {
                return true;
            }

        } // namespace blink
    } // namespace mojom
} // namespace common
} // namespace mojo

namespace mojo {

template <>
struct StructTraits<::mojo::common::mojom::blink::ListValue::DataView,
    ::mojo::common::mojom::blink::ListValuePtr> {
    static bool IsNull(const ::mojo::common::mojom::blink::ListValuePtr& input) { return !input; }
    static void SetToNull(::mojo::common::mojom::blink::ListValuePtr* output) { output->reset(); }

    static const decltype(::mojo::common::mojom::blink::ListValue::values)& values(
        const ::mojo::common::mojom::blink::ListValuePtr& input)
    {
        return input->values;
    }

    static bool Read(::mojo::common::mojom::blink::ListValue::DataView input, ::mojo::common::mojom::blink::ListValuePtr* output);
};

template <>
struct StructTraits<::mojo::common::mojom::blink::DictionaryValue::DataView,
    ::mojo::common::mojom::blink::DictionaryValuePtr> {
    static bool IsNull(const ::mojo::common::mojom::blink::DictionaryValuePtr& input) { return !input; }
    static void SetToNull(::mojo::common::mojom::blink::DictionaryValuePtr* output) { output->reset(); }

    static const decltype(::mojo::common::mojom::blink::DictionaryValue::values)& values(
        const ::mojo::common::mojom::blink::DictionaryValuePtr& input)
    {
        return input->values;
    }

    static bool Read(::mojo::common::mojom::blink::DictionaryValue::DataView input, ::mojo::common::mojom::blink::DictionaryValuePtr* output);
};

template <>
struct StructTraits<::mojo::common::mojom::blink::NullValue::DataView,
    ::mojo::common::mojom::blink::NullValuePtr> {
    static bool IsNull(const ::mojo::common::mojom::blink::NullValuePtr& input) { return !input; }
    static void SetToNull(::mojo::common::mojom::blink::NullValuePtr* output) { output->reset(); }

    static bool Read(::mojo::common::mojom::blink::NullValue::DataView input, ::mojo::common::mojom::blink::NullValuePtr* output);
};

template <>
struct UnionTraits<::mojo::common::mojom::blink::Value::DataView,
    ::mojo::common::mojom::blink::ValuePtr> {
    static bool IsNull(const ::mojo::common::mojom::blink::ValuePtr& input) { return !input; }
    static void SetToNull(::mojo::common::mojom::blink::ValuePtr* output) { output->reset(); }

    static ::mojo::common::mojom::blink::Value::Tag GetTag(const ::mojo::common::mojom::blink::ValuePtr& input)
    {
        return input->which();
    }

    static const ::mojo::common::mojom::blink::NullValuePtr& null_value(const ::mojo::common::mojom::blink::ValuePtr& input)
    {
        return input->get_null_value();
    }

    static bool bool_value(const ::mojo::common::mojom::blink::ValuePtr& input)
    {
        return input->get_bool_value();
    }

    static int32_t int_value(const ::mojo::common::mojom::blink::ValuePtr& input)
    {
        return input->get_int_value();
    }

    static double double_value(const ::mojo::common::mojom::blink::ValuePtr& input)
    {
        return input->get_double_value();
    }

    static const WTF::String& string_value(const ::mojo::common::mojom::blink::ValuePtr& input)
    {
        return input->get_string_value();
    }

    static const WTF::Vector<uint8_t>& binary_value(const ::mojo::common::mojom::blink::ValuePtr& input)
    {
        return input->get_binary_value();
    }

    static const ::mojo::common::mojom::blink::DictionaryValuePtr& dictionary_value(const ::mojo::common::mojom::blink::ValuePtr& input)
    {
        return input->get_dictionary_value();
    }

    static const ::mojo::common::mojom::blink::ListValuePtr& list_value(const ::mojo::common::mojom::blink::ValuePtr& input)
    {
        return input->get_list_value();
    }

    static bool Read(::mojo::common::mojom::blink::Value::DataView input, ::mojo::common::mojom::blink::ValuePtr* output);
};

} // namespace mojo

#endif // MOJO_COMMON_VALUES_MOJOM_BLINK_H_