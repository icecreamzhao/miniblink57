// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_MOJO_INTERFACES_MEDIA_SERVICE_MOJOM_SHARED_INTERNAL_H_
#define MEDIA_MOJO_INTERFACES_MEDIA_SERVICE_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "media/mojo/interfaces/interface_factory.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "services/service_manager/public/interfaces/interface_provider.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace media {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kMediaService_CreateInterfaceFactory_Name = 0;
        class MediaService_CreateInterfaceFactory_Params_Data {
        public:
            static MediaService_CreateInterfaceFactory_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(MediaService_CreateInterfaceFactory_Params_Data))) MediaService_CreateInterfaceFactory_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data factory;
            mojo::internal::Interface_Data host_interfaces;
            uint8_t padfinal_[4];

        private:
            MediaService_CreateInterfaceFactory_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~MediaService_CreateInterfaceFactory_Params_Data() = delete;
        };
        static_assert(sizeof(MediaService_CreateInterfaceFactory_Params_Data) == 24,
            "Bad sizeof(MediaService_CreateInterfaceFactory_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace media

#endif // MEDIA_MOJO_INTERFACES_MEDIA_SERVICE_MOJOM_SHARED_INTERNAL_H_