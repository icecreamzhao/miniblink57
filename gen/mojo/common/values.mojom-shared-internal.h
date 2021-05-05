// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MOJO_COMMON_VALUES_MOJOM_SHARED_INTERNAL_H_
#define MOJO_COMMON_VALUES_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace mojo {
namespace common {
    namespace mojom {
        namespace internal {
            class ListValue_Data;
            class DictionaryValue_Data;
            class NullValue_Data;
            using LegacyListValue_Data = mojo::internal::NativeStruct_Data;
            class Value_Data;

#pragma pack(push, 1)

            class Value_Data {
            public:
                // Used to identify Mojom Union Data Classes.
                typedef void MojomUnionDataType;

                Value_Data() { }
                // Do nothing in the destructor since it won't be called when it is a
                // non-inlined union.
                ~Value_Data() { }

                static Value_Data* New(mojo::internal::Buffer* buf)
                {
                    return new (buf->Allocate(sizeof(Value_Data))) Value_Data();
                }

                static bool Validate(const void* data,
                    mojo::internal::ValidationContext* validation_context,
                    bool inlined);

                bool is_null() const { return size == 0; }

                void set_null()
                {
                    size = 0U;
                    tag = static_cast<Value_Tag>(0);
                    data.unknown = 0U;
                }

                enum class Value_Tag : uint32_t {

                    NULL_VALUE,
                    BOOL_VALUE,
                    INT_VALUE,
                    DOUBLE_VALUE,
                    STRING_VALUE,
                    BINARY_VALUE,
                    DICTIONARY_VALUE,
                    LIST_VALUE,
                };

                // A note on layout:
                // "Each non-static data member is allocated as if it were the sole member of
                // a struct." - Section 9.5.2 ISO/IEC 14882:2011 (The C++ Spec)
                union MOJO_ALIGNAS(8) Union_ {
                    mojo::internal::Pointer<internal::NullValue_Data> f_null_value;
                    uint8_t f_bool_value : 1;
                    int32_t f_int_value;
                    double f_double_value;
                    mojo::internal::Pointer<mojo::internal::String_Data> f_string_value;
                    mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> f_binary_value;
                    mojo::internal::Pointer<internal::DictionaryValue_Data> f_dictionary_value;
                    mojo::internal::Pointer<internal::ListValue_Data> f_list_value;
                    uint64_t unknown;
                };

                uint32_t size;
                Value_Tag tag;
                Union_ data;
            };
            static_assert(sizeof(Value_Data) == mojo::internal::kUnionDataSize,
                "Bad sizeof(Value_Data)");
            class ListValue_Data {
            public:
                static ListValue_Data* New(mojo::internal::Buffer* buf)
                {
                    return new (buf->Allocate(sizeof(ListValue_Data))) ListValue_Data();
                }

                static bool Validate(const void* data,
                    mojo::internal::ValidationContext* validation_context);

                mojo::internal::StructHeader header_;
                mojo::internal::Pointer<mojo::internal::Array_Data<internal::Value_Data>> values;

            private:
                ListValue_Data()
                    : header_({ sizeof(*this), 0 })
                {
                }
                ~ListValue_Data() = delete;
            };
            static_assert(sizeof(ListValue_Data) == 16,
                "Bad sizeof(ListValue_Data)");
            class DictionaryValue_Data {
            public:
                static DictionaryValue_Data* New(mojo::internal::Buffer* buf)
                {
                    return new (buf->Allocate(sizeof(DictionaryValue_Data))) DictionaryValue_Data();
                }

                static bool Validate(const void* data,
                    mojo::internal::ValidationContext* validation_context);

                mojo::internal::StructHeader header_;
                mojo::internal::Pointer<mojo::internal::Map_Data<mojo::internal::Pointer<mojo::internal::String_Data>, internal::Value_Data>> values;

            private:
                DictionaryValue_Data()
                    : header_({ sizeof(*this), 0 })
                {
                }
                ~DictionaryValue_Data() = delete;
            };
            static_assert(sizeof(DictionaryValue_Data) == 16,
                "Bad sizeof(DictionaryValue_Data)");
            class NullValue_Data {
            public:
                static NullValue_Data* New(mojo::internal::Buffer* buf)
                {
                    return new (buf->Allocate(sizeof(NullValue_Data))) NullValue_Data();
                }

                static bool Validate(const void* data,
                    mojo::internal::ValidationContext* validation_context);

                mojo::internal::StructHeader header_;

            private:
                NullValue_Data()
                    : header_({ sizeof(*this), 0 })
                {
                }
                ~NullValue_Data() = delete;
            };
            static_assert(sizeof(NullValue_Data) == 8,
                "Bad sizeof(NullValue_Data)");

#pragma pack(pop)

        } // namespace internal
    } // namespace mojom
} // namespace common
} // namespace mojo

#endif // MOJO_COMMON_VALUES_MOJOM_SHARED_INTERNAL_H_