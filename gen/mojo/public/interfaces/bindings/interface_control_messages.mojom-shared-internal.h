// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MOJO_PUBLIC_INTERFACES_BINDINGS_INTERFACE_CONTROL_MESSAGES_MOJOM_SHARED_INTERNAL_H_
#define MOJO_PUBLIC_INTERFACES_BINDINGS_INTERFACE_CONTROL_MESSAGES_MOJOM_SHARED_INTERNAL_H_

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
namespace interface_control {
    namespace internal {
        class RunMessageParams_Data;
        class RunResponseMessageParams_Data;
        class QueryVersion_Data;
        class QueryVersionResult_Data;
        class FlushForTesting_Data;
        class RunOrClosePipeMessageParams_Data;
        class RequireVersion_Data;
        class SendDisconnectReason_Data;
        class RunInput_Data;
        class RunOutput_Data;
        class RunOrClosePipeInput_Data;

#pragma pack(push, 1)

        class RunInput_Data {
        public:
            // Used to identify Mojom Union Data Classes.
            typedef void MojomUnionDataType;

            RunInput_Data() { }
            // Do nothing in the destructor since it won't be called when it is a
            // non-inlined union.
            ~RunInput_Data() { }

            static RunInput_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RunInput_Data))) RunInput_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context,
                bool inlined);

            bool is_null() const { return size == 0; }

            void set_null()
            {
                size = 0U;
                tag = static_cast<RunInput_Tag>(0);
                data.unknown = 0U;
            }

            enum class RunInput_Tag : uint32_t {

                QUERY_VERSION,
                FLUSH_FOR_TESTING,
            };

            // A note on layout:
            // "Each non-static data member is allocated as if it were the sole member of
            // a struct." - Section 9.5.2 ISO/IEC 14882:2011 (The C++ Spec)
            union MOJO_ALIGNAS(8) Union_ {
                mojo::internal::Pointer<internal::QueryVersion_Data> f_query_version;
                mojo::internal::Pointer<internal::FlushForTesting_Data> f_flush_for_testing;
                uint64_t unknown;
            };

            uint32_t size;
            RunInput_Tag tag;
            Union_ data;
        };
        static_assert(sizeof(RunInput_Data) == mojo::internal::kUnionDataSize,
            "Bad sizeof(RunInput_Data)");

        class RunOutput_Data {
        public:
            // Used to identify Mojom Union Data Classes.
            typedef void MojomUnionDataType;

            RunOutput_Data() { }
            // Do nothing in the destructor since it won't be called when it is a
            // non-inlined union.
            ~RunOutput_Data() { }

            static RunOutput_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RunOutput_Data))) RunOutput_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context,
                bool inlined);

            bool is_null() const { return size == 0; }

            void set_null()
            {
                size = 0U;
                tag = static_cast<RunOutput_Tag>(0);
                data.unknown = 0U;
            }

            enum class RunOutput_Tag : uint32_t {

                QUERY_VERSION_RESULT,
            };

            // A note on layout:
            // "Each non-static data member is allocated as if it were the sole member of
            // a struct." - Section 9.5.2 ISO/IEC 14882:2011 (The C++ Spec)
            union MOJO_ALIGNAS(8) Union_ {
                mojo::internal::Pointer<internal::QueryVersionResult_Data> f_query_version_result;
                uint64_t unknown;
            };

            uint32_t size;
            RunOutput_Tag tag;
            Union_ data;
        };
        static_assert(sizeof(RunOutput_Data) == mojo::internal::kUnionDataSize,
            "Bad sizeof(RunOutput_Data)");

        class RunOrClosePipeInput_Data {
        public:
            // Used to identify Mojom Union Data Classes.
            typedef void MojomUnionDataType;

            RunOrClosePipeInput_Data() { }
            // Do nothing in the destructor since it won't be called when it is a
            // non-inlined union.
            ~RunOrClosePipeInput_Data() { }

            static RunOrClosePipeInput_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RunOrClosePipeInput_Data))) RunOrClosePipeInput_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context,
                bool inlined);

            bool is_null() const { return size == 0; }

            void set_null()
            {
                size = 0U;
                tag = static_cast<RunOrClosePipeInput_Tag>(0);
                data.unknown = 0U;
            }

            enum class RunOrClosePipeInput_Tag : uint32_t {

                REQUIRE_VERSION,
                SEND_DISCONNECT_REASON,
            };

            // A note on layout:
            // "Each non-static data member is allocated as if it were the sole member of
            // a struct." - Section 9.5.2 ISO/IEC 14882:2011 (The C++ Spec)
            union MOJO_ALIGNAS(8) Union_ {
                mojo::internal::Pointer<internal::RequireVersion_Data> f_require_version;
                mojo::internal::Pointer<internal::SendDisconnectReason_Data> f_send_disconnect_reason;
                uint64_t unknown;
            };

            uint32_t size;
            RunOrClosePipeInput_Tag tag;
            Union_ data;
        };
        static_assert(sizeof(RunOrClosePipeInput_Data) == mojo::internal::kUnionDataSize,
            "Bad sizeof(RunOrClosePipeInput_Data)");
        class RunMessageParams_Data {
        public:
            static RunMessageParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RunMessageParams_Data))) RunMessageParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            internal::RunInput_Data input;

        private:
            RunMessageParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RunMessageParams_Data() = delete;
        };
        static_assert(sizeof(RunMessageParams_Data) == 24,
            "Bad sizeof(RunMessageParams_Data)");
        class RunResponseMessageParams_Data {
        public:
            static RunResponseMessageParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RunResponseMessageParams_Data))) RunResponseMessageParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            internal::RunOutput_Data output;

        private:
            RunResponseMessageParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RunResponseMessageParams_Data() = delete;
        };
        static_assert(sizeof(RunResponseMessageParams_Data) == 24,
            "Bad sizeof(RunResponseMessageParams_Data)");
        class QueryVersion_Data {
        public:
            static QueryVersion_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(QueryVersion_Data))) QueryVersion_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            QueryVersion_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~QueryVersion_Data() = delete;
        };
        static_assert(sizeof(QueryVersion_Data) == 8,
            "Bad sizeof(QueryVersion_Data)");
        class QueryVersionResult_Data {
        public:
            static QueryVersionResult_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(QueryVersionResult_Data))) QueryVersionResult_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t version;
            uint8_t padfinal_[4];

        private:
            QueryVersionResult_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~QueryVersionResult_Data() = delete;
        };
        static_assert(sizeof(QueryVersionResult_Data) == 16,
            "Bad sizeof(QueryVersionResult_Data)");
        class FlushForTesting_Data {
        public:
            static FlushForTesting_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(FlushForTesting_Data))) FlushForTesting_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            FlushForTesting_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~FlushForTesting_Data() = delete;
        };
        static_assert(sizeof(FlushForTesting_Data) == 8,
            "Bad sizeof(FlushForTesting_Data)");
        class RunOrClosePipeMessageParams_Data {
        public:
            static RunOrClosePipeMessageParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RunOrClosePipeMessageParams_Data))) RunOrClosePipeMessageParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            internal::RunOrClosePipeInput_Data input;

        private:
            RunOrClosePipeMessageParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RunOrClosePipeMessageParams_Data() = delete;
        };
        static_assert(sizeof(RunOrClosePipeMessageParams_Data) == 24,
            "Bad sizeof(RunOrClosePipeMessageParams_Data)");
        class RequireVersion_Data {
        public:
            static RequireVersion_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RequireVersion_Data))) RequireVersion_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t version;
            uint8_t padfinal_[4];

        private:
            RequireVersion_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RequireVersion_Data() = delete;
        };
        static_assert(sizeof(RequireVersion_Data) == 16,
            "Bad sizeof(RequireVersion_Data)");
        class SendDisconnectReason_Data {
        public:
            static SendDisconnectReason_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(SendDisconnectReason_Data))) SendDisconnectReason_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t custom_reason;
            uint8_t pad0_[4];
            mojo::internal::Pointer<mojo::internal::String_Data> description;

        private:
            SendDisconnectReason_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~SendDisconnectReason_Data() = delete;
        };
        static_assert(sizeof(SendDisconnectReason_Data) == 24,
            "Bad sizeof(SendDisconnectReason_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace interface_control
} // namespace mojo

#endif // MOJO_PUBLIC_INTERFACES_BINDINGS_INTERFACE_CONTROL_MESSAGES_MOJOM_SHARED_INTERNAL_H_