// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_WINDOW_TREE_HOST_MOJOM_SHARED_INTERNAL_H_
#define SERVICES_UI_PUBLIC_INTERFACES_WINDOW_TREE_HOST_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "services/ui/public/interfaces/window_tree.mojom-shared-internal.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace ui {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kWindowTreeHost_SetSize_Name = 0;
        class WindowTreeHost_SetSize_Params_Data {
        public:
            static WindowTreeHost_SetSize_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTreeHost_SetSize_Params_Data))) WindowTreeHost_SetSize_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::gfx::mojom::internal::Size_Data> size;

        private:
            WindowTreeHost_SetSize_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTreeHost_SetSize_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTreeHost_SetSize_Params_Data) == 16,
            "Bad sizeof(WindowTreeHost_SetSize_Params_Data)");
        constexpr uint32_t kWindowTreeHost_SetTitle_Name = 1;
        class WindowTreeHost_SetTitle_Params_Data {
        public:
            static WindowTreeHost_SetTitle_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTreeHost_SetTitle_Params_Data))) WindowTreeHost_SetTitle_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> title;

        private:
            WindowTreeHost_SetTitle_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTreeHost_SetTitle_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTreeHost_SetTitle_Params_Data) == 16,
            "Bad sizeof(WindowTreeHost_SetTitle_Params_Data)");
        constexpr uint32_t kWindowTreeHostFactory_CreateWindowTreeHost_Name = 0;
        class WindowTreeHostFactory_CreateWindowTreeHost_Params_Data {
        public:
            static WindowTreeHostFactory_CreateWindowTreeHost_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTreeHostFactory_CreateWindowTreeHost_Params_Data))) WindowTreeHostFactory_CreateWindowTreeHost_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data window_tree_host;
            mojo::internal::Interface_Data tree_client;
            uint8_t padfinal_[4];

        private:
            WindowTreeHostFactory_CreateWindowTreeHost_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTreeHostFactory_CreateWindowTreeHost_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTreeHostFactory_CreateWindowTreeHost_Params_Data) == 24,
            "Bad sizeof(WindowTreeHostFactory_CreateWindowTreeHost_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace ui

#endif // SERVICES_UI_PUBLIC_INTERFACES_WINDOW_TREE_HOST_MOJOM_SHARED_INTERNAL_H_