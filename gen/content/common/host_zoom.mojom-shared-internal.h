// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_HOST_ZOOM_MOJOM_SHARED_INTERNAL_H_
#define CONTENT_COMMON_HOST_ZOOM_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "url/mojo/url.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace content {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kHostZoom_SetHostZoomLevel_Name = 0;
        class HostZoom_SetHostZoomLevel_Params_Data {
        public:
            static HostZoom_SetHostZoomLevel_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(HostZoom_SetHostZoomLevel_Params_Data))) HostZoom_SetHostZoomLevel_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::url::mojom::internal::Url_Data> url;
            double zoom_level;

        private:
            HostZoom_SetHostZoomLevel_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~HostZoom_SetHostZoomLevel_Params_Data() = delete;
        };
        static_assert(sizeof(HostZoom_SetHostZoomLevel_Params_Data) == 24,
            "Bad sizeof(HostZoom_SetHostZoomLevel_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace content

#endif // CONTENT_COMMON_HOST_ZOOM_MOJOM_SHARED_INTERNAL_H_