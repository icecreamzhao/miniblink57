// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_RENDER_WIDGET_WINDOW_TREE_CLIENT_FACTORY_MOJOM_SHARED_INTERNAL_H_
#define CONTENT_COMMON_RENDER_WIDGET_WINDOW_TREE_CLIENT_FACTORY_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "services/ui/public/interfaces/window_tree.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace content {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kRenderWidgetWindowTreeClientFactory_CreateWindowTreeClientForRenderWidget_Name = 0;
        class RenderWidgetWindowTreeClientFactory_CreateWindowTreeClientForRenderWidget_Params_Data {
        public:
            static RenderWidgetWindowTreeClientFactory_CreateWindowTreeClientForRenderWidget_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(RenderWidgetWindowTreeClientFactory_CreateWindowTreeClientForRenderWidget_Params_Data))) RenderWidgetWindowTreeClientFactory_CreateWindowTreeClientForRenderWidget_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t routing_id;
            mojo::internal::Handle_Data window_tree_client;

        private:
            RenderWidgetWindowTreeClientFactory_CreateWindowTreeClientForRenderWidget_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~RenderWidgetWindowTreeClientFactory_CreateWindowTreeClientForRenderWidget_Params_Data() = delete;
        };
        static_assert(sizeof(RenderWidgetWindowTreeClientFactory_CreateWindowTreeClientForRenderWidget_Params_Data) == 16,
            "Bad sizeof(RenderWidgetWindowTreeClientFactory_CreateWindowTreeClientForRenderWidget_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace content

#endif // CONTENT_COMMON_RENDER_WIDGET_WINDOW_TREE_CLIENT_FACTORY_MOJOM_SHARED_INTERNAL_H_