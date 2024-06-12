// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-private-field"
#elif defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4056)
#pragma warning(disable : 4065)
#pragma warning(disable : 4756)
#endif

#include "mojo/common/values.mojom-blink.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "mojo/common/common_custom_types_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/cpp/bindings/lib/wtf_serialization.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "third_party/WebKit/Source/platform/mojo/CommonCustomTypesStructTraits.h"
namespace mojo {
namespace common {
    namespace mojom {
        namespace blink { // static
            ListValuePtr ListValue::New()
            {
                ListValuePtr rv;
                mojo::internal::StructHelper<ListValue>::Initialize(&rv);
                return rv;
            }

            ListValue::ListValue()
                : values()
            {
            }

            ListValue::~ListValue()
            {
            } // static
            DictionaryValuePtr DictionaryValue::New()
            {
                DictionaryValuePtr rv;
                mojo::internal::StructHelper<DictionaryValue>::Initialize(&rv);
                return rv;
            }

            DictionaryValue::DictionaryValue()
                : values()
            {
            }

            DictionaryValue::~DictionaryValue()
            {
            } // static
            NullValuePtr NullValue::New()
            {
                NullValuePtr rv;
                mojo::internal::StructHelper<NullValue>::Initialize(&rv);
                return rv;
            }

            NullValue::NullValue()
            {
            }

            NullValue::~NullValue()
            {
            }
            size_t NullValue::Hash(size_t seed) const
            {
                return seed;
            } // static
            ValuePtr Value::New()
            {
                ValuePtr rv;
                mojo::internal::StructHelper<Value>::Initialize(&rv);
                return rv;
            }

            Value::Value()
            {
                // TODO(azani): Implement default values here when/if we support them.
                // TODO(azani): Set to UNKNOWN when unknown is implemented.
                SetActive(static_cast<Tag>(0));
            }

            Value::~Value()
            {
                DestroyActive();
            }

            void Value::set_null_value(NullValuePtr null_value)
            {
                SwitchActive(Tag::NULL_VALUE);

                *(data_.null_value) = std::move(null_value);
            }
            void Value::set_bool_value(bool bool_value)
            {
                SwitchActive(Tag::BOOL_VALUE);

                data_.bool_value = bool_value;
            }
            void Value::set_int_value(int32_t int_value)
            {
                SwitchActive(Tag::INT_VALUE);

                data_.int_value = int_value;
            }
            void Value::set_double_value(double double_value)
            {
                SwitchActive(Tag::DOUBLE_VALUE);

                data_.double_value = double_value;
            }
            void Value::set_string_value(const WTF::String& string_value)
            {
                SwitchActive(Tag::STRING_VALUE);

                *(data_.string_value) = string_value;
            }
            void Value::set_binary_value(const WTF::Vector<uint8_t>& binary_value)
            {
                SwitchActive(Tag::BINARY_VALUE);

                *(data_.binary_value) = std::move(binary_value);
            }
            void Value::set_dictionary_value(DictionaryValuePtr dictionary_value)
            {
                SwitchActive(Tag::DICTIONARY_VALUE);

                *(data_.dictionary_value) = std::move(dictionary_value);
            }
            void Value::set_list_value(ListValuePtr list_value)
            {
                SwitchActive(Tag::LIST_VALUE);

                *(data_.list_value) = std::move(list_value);
            }

            void Value::SwitchActive(Tag new_active)
            {
                if (new_active == tag_) {
                    return;
                }

                DestroyActive();
                SetActive(new_active);
            }

            void Value::SetActive(Tag new_active)
            {
                switch (new_active) {

                case Tag::NULL_VALUE:

                    data_.null_value = new NullValuePtr();
                    break;
                case Tag::BOOL_VALUE:

                    break;
                case Tag::INT_VALUE:

                    break;
                case Tag::DOUBLE_VALUE:

                    break;
                case Tag::STRING_VALUE:

                    data_.string_value = new WTF::String();
                    break;
                case Tag::BINARY_VALUE:

                    data_.binary_value = new WTF::Vector<uint8_t>();
                    break;
                case Tag::DICTIONARY_VALUE:

                    data_.dictionary_value = new DictionaryValuePtr();
                    break;
                case Tag::LIST_VALUE:

                    data_.list_value = new ListValuePtr();
                    break;
                }

                tag_ = new_active;
            }

            void Value::DestroyActive()
            {
                switch (tag_) {

                case Tag::NULL_VALUE:

                    delete data_.null_value;
                    break;
                case Tag::BOOL_VALUE:

                    break;
                case Tag::INT_VALUE:

                    break;
                case Tag::DOUBLE_VALUE:

                    break;
                case Tag::STRING_VALUE:

                    delete data_.string_value;
                    break;
                case Tag::BINARY_VALUE:

                    delete data_.binary_value;
                    break;
                case Tag::DICTIONARY_VALUE:

                    delete data_.dictionary_value;
                    break;
                case Tag::LIST_VALUE:

                    delete data_.list_value;
                    break;
                }
            }
        } // namespace blink
    } // namespace mojom
} // namespace common
} // namespace mojo

namespace mojo {

// static
bool StructTraits<::mojo::common::mojom::blink::ListValue::DataView, ::mojo::common::mojom::blink::ListValuePtr>::Read(
    ::mojo::common::mojom::blink::ListValue::DataView input,
    ::mojo::common::mojom::blink::ListValuePtr* output)
{
    bool success = true;
    ::mojo::common::mojom::blink::ListValuePtr result(::mojo::common::mojom::blink::ListValue::New());

    if (!input.ReadValues(&result->values))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::mojo::common::mojom::blink::DictionaryValue::DataView, ::mojo::common::mojom::blink::DictionaryValuePtr>::Read(
    ::mojo::common::mojom::blink::DictionaryValue::DataView input,
    ::mojo::common::mojom::blink::DictionaryValuePtr* output)
{
    bool success = true;
    ::mojo::common::mojom::blink::DictionaryValuePtr result(::mojo::common::mojom::blink::DictionaryValue::New());

    if (!input.ReadValues(&result->values))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::mojo::common::mojom::blink::NullValue::DataView, ::mojo::common::mojom::blink::NullValuePtr>::Read(
    ::mojo::common::mojom::blink::NullValue::DataView input,
    ::mojo::common::mojom::blink::NullValuePtr* output)
{
    bool success = true;
    ::mojo::common::mojom::blink::NullValuePtr result(::mojo::common::mojom::blink::NullValue::New());

    *output = std::move(result);
    return success;
}

// static
bool UnionTraits<::mojo::common::mojom::blink::Value::DataView, ::mojo::common::mojom::blink::ValuePtr>::Read(
    ::mojo::common::mojom::blink::Value::DataView input,
    ::mojo::common::mojom::blink::ValuePtr* output)
{
    *output = ::mojo::common::mojom::blink::Value::New();
    ::mojo::common::mojom::blink::ValuePtr& result = *output;

    internal::UnionAccessor<::mojo::common::mojom::blink::Value> result_acc(result.get());
    switch (input.tag()) {
    case ::mojo::common::mojom::blink::Value::Tag::NULL_VALUE: {
        result_acc.SwitchActive(::mojo::common::mojom::blink::Value::Tag::NULL_VALUE);
        if (!input.ReadNullValue(result_acc.data()->null_value))
            return false;
        break;
    }
    case ::mojo::common::mojom::blink::Value::Tag::BOOL_VALUE: {
        result->set_bool_value(input.bool_value());
        break;
    }
    case ::mojo::common::mojom::blink::Value::Tag::INT_VALUE: {
        result->set_int_value(input.int_value());
        break;
    }
    case ::mojo::common::mojom::blink::Value::Tag::DOUBLE_VALUE: {
        result->set_double_value(input.double_value());
        break;
    }
    case ::mojo::common::mojom::blink::Value::Tag::STRING_VALUE: {
        result_acc.SwitchActive(::mojo::common::mojom::blink::Value::Tag::STRING_VALUE);
        if (!input.ReadStringValue(result_acc.data()->string_value))
            return false;
        break;
    }
    case ::mojo::common::mojom::blink::Value::Tag::BINARY_VALUE: {
        result_acc.SwitchActive(::mojo::common::mojom::blink::Value::Tag::BINARY_VALUE);
        if (!input.ReadBinaryValue(result_acc.data()->binary_value))
            return false;
        break;
    }
    case ::mojo::common::mojom::blink::Value::Tag::DICTIONARY_VALUE: {
        result_acc.SwitchActive(::mojo::common::mojom::blink::Value::Tag::DICTIONARY_VALUE);
        if (!input.ReadDictionaryValue(result_acc.data()->dictionary_value))
            return false;
        break;
    }
    case ::mojo::common::mojom::blink::Value::Tag::LIST_VALUE: {
        result_acc.SwitchActive(::mojo::common::mojom::blink::Value::Tag::LIST_VALUE);
        if (!input.ReadListValue(result_acc.data()->list_value))
            return false;
        break;
    }
    default:
        return false;
    }
    return true;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif