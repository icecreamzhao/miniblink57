// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_VISITEDLINK_COMMON_VISITEDLINK_MOJOM_SHARED_INTERNAL_H_
#define COMPONENTS_VISITEDLINK_COMMON_VISITEDLINK_MOJOM_SHARED_INTERNAL_H_

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
namespace visitedlink {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kVisitedLinkNotificationSink_UpdateVisitedLinks_Name = 0;
        class VisitedLinkNotificationSink_UpdateVisitedLinks_Params_Data {
        public:
            static VisitedLinkNotificationSink_UpdateVisitedLinks_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VisitedLinkNotificationSink_UpdateVisitedLinks_Params_Data))) VisitedLinkNotificationSink_UpdateVisitedLinks_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data table_handle;
            uint8_t padfinal_[4];

        private:
            VisitedLinkNotificationSink_UpdateVisitedLinks_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VisitedLinkNotificationSink_UpdateVisitedLinks_Params_Data() = delete;
        };
        static_assert(sizeof(VisitedLinkNotificationSink_UpdateVisitedLinks_Params_Data) == 16,
            "Bad sizeof(VisitedLinkNotificationSink_UpdateVisitedLinks_Params_Data)");
        constexpr uint32_t kVisitedLinkNotificationSink_AddVisitedLinks_Name = 1;
        class VisitedLinkNotificationSink_AddVisitedLinks_Params_Data {
        public:
            static VisitedLinkNotificationSink_AddVisitedLinks_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VisitedLinkNotificationSink_AddVisitedLinks_Params_Data))) VisitedLinkNotificationSink_AddVisitedLinks_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint64_t>> link_hashes;

        private:
            VisitedLinkNotificationSink_AddVisitedLinks_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VisitedLinkNotificationSink_AddVisitedLinks_Params_Data() = delete;
        };
        static_assert(sizeof(VisitedLinkNotificationSink_AddVisitedLinks_Params_Data) == 16,
            "Bad sizeof(VisitedLinkNotificationSink_AddVisitedLinks_Params_Data)");
        constexpr uint32_t kVisitedLinkNotificationSink_ResetVisitedLinks_Name = 2;
        class VisitedLinkNotificationSink_ResetVisitedLinks_Params_Data {
        public:
            static VisitedLinkNotificationSink_ResetVisitedLinks_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(VisitedLinkNotificationSink_ResetVisitedLinks_Params_Data))) VisitedLinkNotificationSink_ResetVisitedLinks_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t invalidate_cached_hashes : 1;
            uint8_t padfinal_[7];

        private:
            VisitedLinkNotificationSink_ResetVisitedLinks_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~VisitedLinkNotificationSink_ResetVisitedLinks_Params_Data() = delete;
        };
        static_assert(sizeof(VisitedLinkNotificationSink_ResetVisitedLinks_Params_Data) == 16,
            "Bad sizeof(VisitedLinkNotificationSink_ResetVisitedLinks_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace visitedlink

#endif // COMPONENTS_VISITEDLINK_COMMON_VISITEDLINK_MOJOM_SHARED_INTERNAL_H_