// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MOJO_PUBLIC_INTERFACES_BINDINGS_PIPE_CONTROL_MESSAGES_MOJOM_SHARED_INTERNAL_H_
#define MOJO_PUBLIC_INTERFACES_BINDINGS_PIPE_CONTROL_MESSAGES_MOJOM_SHARED_INTERNAL_H_

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
namespace pipe_control {
    namespace internal {
        class RunOrClosePipeMessageParams_Data;
        class PeerAssociatedEndpointClosedEvent_Data;
        class AssociatedEndpointClosedBeforeSentEvent_Data;
        class RunOrClosePipeInput_Data;

#pragma pack(push, 1)

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

                PEER_ASSOCIATED_ENDPOINT_CLOSED_EVENT,
                ASSOCIATED_ENDPOINT_CLOSED_BEFORE_SENT_EVENT,
            };

            // A note on layout:
            // "Each non-static data member is allocated as if it were the sole member of
            // a struct." - Section 9.5.2 ISO/IEC 14882:2011 (The C++ Spec)
            union MOJO_ALIGNAS(8) Union_ {
                mojo::internal::Pointer<internal::PeerAssociatedEndpointClosedEvent_Data> f_peer_associated_endpoint_closed_event;
                mojo::internal::Pointer<internal::AssociatedEndpointClosedBeforeSentEvent_Data> f_associated_endpoint_closed_before_sent_event;
                uint64_t unknown;
            };

            uint32_t size;
            RunOrClosePipeInput_Tag tag;
            Union_ data;
        };
        static_assert(sizeof(RunOrClosePipeInput_Data) == mojo::internal::kUnionDataSize,
            "Bad sizeof(RunOrClosePipeInput_Data)");
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
        class PeerAssociatedEndpointClosedEvent_Data {
        public:
            static PeerAssociatedEndpointClosedEvent_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PeerAssociatedEndpointClosedEvent_Data))) PeerAssociatedEndpointClosedEvent_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t id;
            uint8_t padfinal_[4];

        private:
            PeerAssociatedEndpointClosedEvent_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PeerAssociatedEndpointClosedEvent_Data() = delete;
        };
        static_assert(sizeof(PeerAssociatedEndpointClosedEvent_Data) == 16,
            "Bad sizeof(PeerAssociatedEndpointClosedEvent_Data)");
        class AssociatedEndpointClosedBeforeSentEvent_Data {
        public:
            static AssociatedEndpointClosedBeforeSentEvent_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AssociatedEndpointClosedBeforeSentEvent_Data))) AssociatedEndpointClosedBeforeSentEvent_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t id;
            uint8_t padfinal_[4];

        private:
            AssociatedEndpointClosedBeforeSentEvent_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AssociatedEndpointClosedBeforeSentEvent_Data() = delete;
        };
        static_assert(sizeof(AssociatedEndpointClosedBeforeSentEvent_Data) == 16,
            "Bad sizeof(AssociatedEndpointClosedBeforeSentEvent_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace pipe_control
} // namespace mojo

#endif // MOJO_PUBLIC_INTERFACES_BINDINGS_PIPE_CONTROL_MESSAGES_MOJOM_SHARED_INTERNAL_H_