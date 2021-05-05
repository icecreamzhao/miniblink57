// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_MOJO_INTERFACES_PROVISION_FETCHER_MOJOM_SHARED_INTERNAL_H_
#define MEDIA_MOJO_INTERFACES_PROVISION_FETCHER_MOJOM_SHARED_INTERNAL_H_

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
namespace media {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kProvisionFetcher_Retrieve_Name = 0;
        class ProvisionFetcher_Retrieve_Params_Data {
        public:
            static ProvisionFetcher_Retrieve_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ProvisionFetcher_Retrieve_Params_Data))) ProvisionFetcher_Retrieve_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> default_url;
            mojo::internal::Pointer<mojo::internal::String_Data> request_data;

        private:
            ProvisionFetcher_Retrieve_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ProvisionFetcher_Retrieve_Params_Data() = delete;
        };
        static_assert(sizeof(ProvisionFetcher_Retrieve_Params_Data) == 24,
            "Bad sizeof(ProvisionFetcher_Retrieve_Params_Data)");
        class ProvisionFetcher_Retrieve_ResponseParams_Data {
        public:
            static ProvisionFetcher_Retrieve_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(ProvisionFetcher_Retrieve_ResponseParams_Data))) ProvisionFetcher_Retrieve_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t result : 1;
            uint8_t pad0_[7];
            mojo::internal::Pointer<mojo::internal::String_Data> response;

        private:
            ProvisionFetcher_Retrieve_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~ProvisionFetcher_Retrieve_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(ProvisionFetcher_Retrieve_ResponseParams_Data) == 24,
            "Bad sizeof(ProvisionFetcher_Retrieve_ResponseParams_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace media

#endif // MEDIA_MOJO_INTERFACES_PROVISION_FETCHER_MOJOM_SHARED_INTERNAL_H_