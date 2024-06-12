// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_DISPLAY_MANAGER_MOJOM_SHARED_INTERNAL_H_
#define SERVICES_UI_PUBLIC_INTERFACES_DISPLAY_MANAGER_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "services/ui/public/interfaces/window_manager_constants.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace ui {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kDisplayManagerObserver_OnDisplays_Name = 0;
        class DisplayManagerObserver_OnDisplays_Params_Data {
        public:
            static DisplayManagerObserver_OnDisplays_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DisplayManagerObserver_OnDisplays_Params_Data))) DisplayManagerObserver_OnDisplays_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::ui::mojom::internal::WsDisplay_Data>>> displays;
            int64_t primary_display_id;
            int64_t internal_display_id;

        private:
            DisplayManagerObserver_OnDisplays_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DisplayManagerObserver_OnDisplays_Params_Data() = delete;
        };
        static_assert(sizeof(DisplayManagerObserver_OnDisplays_Params_Data) == 32,
            "Bad sizeof(DisplayManagerObserver_OnDisplays_Params_Data)");
        constexpr uint32_t kDisplayManagerObserver_OnDisplaysChanged_Name = 1;
        class DisplayManagerObserver_OnDisplaysChanged_Params_Data {
        public:
            static DisplayManagerObserver_OnDisplaysChanged_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DisplayManagerObserver_OnDisplaysChanged_Params_Data))) DisplayManagerObserver_OnDisplaysChanged_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::ui::mojom::internal::WsDisplay_Data>>> displays;

        private:
            DisplayManagerObserver_OnDisplaysChanged_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DisplayManagerObserver_OnDisplaysChanged_Params_Data() = delete;
        };
        static_assert(sizeof(DisplayManagerObserver_OnDisplaysChanged_Params_Data) == 16,
            "Bad sizeof(DisplayManagerObserver_OnDisplaysChanged_Params_Data)");
        constexpr uint32_t kDisplayManagerObserver_OnDisplayRemoved_Name = 2;
        class DisplayManagerObserver_OnDisplayRemoved_Params_Data {
        public:
            static DisplayManagerObserver_OnDisplayRemoved_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DisplayManagerObserver_OnDisplayRemoved_Params_Data))) DisplayManagerObserver_OnDisplayRemoved_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t display_id;

        private:
            DisplayManagerObserver_OnDisplayRemoved_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DisplayManagerObserver_OnDisplayRemoved_Params_Data() = delete;
        };
        static_assert(sizeof(DisplayManagerObserver_OnDisplayRemoved_Params_Data) == 16,
            "Bad sizeof(DisplayManagerObserver_OnDisplayRemoved_Params_Data)");
        constexpr uint32_t kDisplayManagerObserver_OnPrimaryDisplayChanged_Name = 3;
        class DisplayManagerObserver_OnPrimaryDisplayChanged_Params_Data {
        public:
            static DisplayManagerObserver_OnPrimaryDisplayChanged_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DisplayManagerObserver_OnPrimaryDisplayChanged_Params_Data))) DisplayManagerObserver_OnPrimaryDisplayChanged_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t primary_display_id;

        private:
            DisplayManagerObserver_OnPrimaryDisplayChanged_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DisplayManagerObserver_OnPrimaryDisplayChanged_Params_Data() = delete;
        };
        static_assert(sizeof(DisplayManagerObserver_OnPrimaryDisplayChanged_Params_Data) == 16,
            "Bad sizeof(DisplayManagerObserver_OnPrimaryDisplayChanged_Params_Data)");
        constexpr uint32_t kDisplayManager_AddObserver_Name = 0;
        class DisplayManager_AddObserver_Params_Data {
        public:
            static DisplayManager_AddObserver_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DisplayManager_AddObserver_Params_Data))) DisplayManager_AddObserver_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Interface_Data observer;

        private:
            DisplayManager_AddObserver_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DisplayManager_AddObserver_Params_Data() = delete;
        };
        static_assert(sizeof(DisplayManager_AddObserver_Params_Data) == 16,
            "Bad sizeof(DisplayManager_AddObserver_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace ui

#endif // SERVICES_UI_PUBLIC_INTERFACES_DISPLAY_MANAGER_MOJOM_SHARED_INTERNAL_H_