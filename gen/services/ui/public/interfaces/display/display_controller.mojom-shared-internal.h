// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_DISPLAY_DISPLAY_CONTROLLER_MOJOM_SHARED_INTERNAL_H_
#define SERVICES_UI_PUBLIC_INTERFACES_DISPLAY_DISPLAY_CONTROLLER_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace display {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kDisplayController_IncreaseInternalDisplayZoom_Name = 0;
        class DisplayController_IncreaseInternalDisplayZoom_Params_Data {
        public:
            static DisplayController_IncreaseInternalDisplayZoom_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DisplayController_IncreaseInternalDisplayZoom_Params_Data))) DisplayController_IncreaseInternalDisplayZoom_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            DisplayController_IncreaseInternalDisplayZoom_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DisplayController_IncreaseInternalDisplayZoom_Params_Data() = delete;
        };
        static_assert(sizeof(DisplayController_IncreaseInternalDisplayZoom_Params_Data) == 8,
            "Bad sizeof(DisplayController_IncreaseInternalDisplayZoom_Params_Data)");
        constexpr uint32_t kDisplayController_DecreaseInternalDisplayZoom_Name = 1;
        class DisplayController_DecreaseInternalDisplayZoom_Params_Data {
        public:
            static DisplayController_DecreaseInternalDisplayZoom_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DisplayController_DecreaseInternalDisplayZoom_Params_Data))) DisplayController_DecreaseInternalDisplayZoom_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            DisplayController_DecreaseInternalDisplayZoom_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DisplayController_DecreaseInternalDisplayZoom_Params_Data() = delete;
        };
        static_assert(sizeof(DisplayController_DecreaseInternalDisplayZoom_Params_Data) == 8,
            "Bad sizeof(DisplayController_DecreaseInternalDisplayZoom_Params_Data)");
        constexpr uint32_t kDisplayController_ResetInternalDisplayZoom_Name = 2;
        class DisplayController_ResetInternalDisplayZoom_Params_Data {
        public:
            static DisplayController_ResetInternalDisplayZoom_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DisplayController_ResetInternalDisplayZoom_Params_Data))) DisplayController_ResetInternalDisplayZoom_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            DisplayController_ResetInternalDisplayZoom_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DisplayController_ResetInternalDisplayZoom_Params_Data() = delete;
        };
        static_assert(sizeof(DisplayController_ResetInternalDisplayZoom_Params_Data) == 8,
            "Bad sizeof(DisplayController_ResetInternalDisplayZoom_Params_Data)");
        constexpr uint32_t kDisplayController_RotateCurrentDisplayCW_Name = 3;
        class DisplayController_RotateCurrentDisplayCW_Params_Data {
        public:
            static DisplayController_RotateCurrentDisplayCW_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DisplayController_RotateCurrentDisplayCW_Params_Data))) DisplayController_RotateCurrentDisplayCW_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            DisplayController_RotateCurrentDisplayCW_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DisplayController_RotateCurrentDisplayCW_Params_Data() = delete;
        };
        static_assert(sizeof(DisplayController_RotateCurrentDisplayCW_Params_Data) == 8,
            "Bad sizeof(DisplayController_RotateCurrentDisplayCW_Params_Data)");
        constexpr uint32_t kDisplayController_SwapPrimaryDisplay_Name = 4;
        class DisplayController_SwapPrimaryDisplay_Params_Data {
        public:
            static DisplayController_SwapPrimaryDisplay_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DisplayController_SwapPrimaryDisplay_Params_Data))) DisplayController_SwapPrimaryDisplay_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            DisplayController_SwapPrimaryDisplay_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DisplayController_SwapPrimaryDisplay_Params_Data() = delete;
        };
        static_assert(sizeof(DisplayController_SwapPrimaryDisplay_Params_Data) == 8,
            "Bad sizeof(DisplayController_SwapPrimaryDisplay_Params_Data)");
        constexpr uint32_t kDisplayController_ToggleMirrorMode_Name = 5;
        class DisplayController_ToggleMirrorMode_Params_Data {
        public:
            static DisplayController_ToggleMirrorMode_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DisplayController_ToggleMirrorMode_Params_Data))) DisplayController_ToggleMirrorMode_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            DisplayController_ToggleMirrorMode_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DisplayController_ToggleMirrorMode_Params_Data() = delete;
        };
        static_assert(sizeof(DisplayController_ToggleMirrorMode_Params_Data) == 8,
            "Bad sizeof(DisplayController_ToggleMirrorMode_Params_Data)");
        constexpr uint32_t kDisplayController_SetDisplayWorkArea_Name = 6;
        class DisplayController_SetDisplayWorkArea_Params_Data {
        public:
            static DisplayController_SetDisplayWorkArea_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(DisplayController_SetDisplayWorkArea_Params_Data))) DisplayController_SetDisplayWorkArea_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t display_id;
            mojo::internal::Pointer<::gfx::mojom::internal::Size_Data> size;
            mojo::internal::Pointer<::gfx::mojom::internal::Insets_Data> insets;

        private:
            DisplayController_SetDisplayWorkArea_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~DisplayController_SetDisplayWorkArea_Params_Data() = delete;
        };
        static_assert(sizeof(DisplayController_SetDisplayWorkArea_Params_Data) == 32,
            "Bad sizeof(DisplayController_SetDisplayWorkArea_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace display

#endif // SERVICES_UI_PUBLIC_INTERFACES_DISPLAY_DISPLAY_CONTROLLER_MOJOM_SHARED_INTERNAL_H_