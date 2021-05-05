// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_WINDOW_MANAGER_WINDOW_TREE_FACTORY_MOJOM_SHARED_INTERNAL_H_
#define SERVICES_UI_PUBLIC_INTERFACES_WINDOW_MANAGER_WINDOW_TREE_FACTORY_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "services/ui/public/interfaces/window_manager_constants.mojom-shared-internal.h"
#include "services/ui/public/interfaces/window_tree.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace ui {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kWindowManagerWindowTreeFactory_CreateWindowTree_Name = 0;
        class WindowManagerWindowTreeFactory_CreateWindowTree_Params_Data {
        public:
            static WindowManagerWindowTreeFactory_CreateWindowTree_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowManagerWindowTreeFactory_CreateWindowTree_Params_Data))) WindowManagerWindowTreeFactory_CreateWindowTree_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data tree_request;
            mojo::internal::Interface_Data client;
            uint8_t padfinal_[4];

        private:
            WindowManagerWindowTreeFactory_CreateWindowTree_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowManagerWindowTreeFactory_CreateWindowTree_Params_Data() = delete;
        };
        static_assert(sizeof(WindowManagerWindowTreeFactory_CreateWindowTree_Params_Data) == 24,
            "Bad sizeof(WindowManagerWindowTreeFactory_CreateWindowTree_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace ui

#endif // SERVICES_UI_PUBLIC_INTERFACES_WINDOW_MANAGER_WINDOW_TREE_FACTORY_MOJOM_SHARED_INTERNAL_H_