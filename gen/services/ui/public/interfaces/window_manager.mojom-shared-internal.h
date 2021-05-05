// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_WINDOW_MANAGER_MOJOM_SHARED_INTERNAL_H_
#define SERVICES_UI_PUBLIC_INTERFACES_WINDOW_MANAGER_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "services/ui/public/interfaces/cursor.mojom-shared-internal.h"
#include "services/ui/public/interfaces/display/display.mojom-shared-internal.h"
#include "services/ui/public/interfaces/event_matcher.mojom-shared-internal.h"
#include "services/ui/public/interfaces/window_manager_constants.mojom-shared-internal.h"
#include "services/ui/public/interfaces/window_tree_constants.mojom-shared-internal.h"
#include "ui/events/mojo/event.mojom-shared-internal.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace ui {
namespace mojom {
    namespace internal {
        class Accelerator_Data;

#pragma pack(push, 1)
        class Accelerator_Data {
        public:
            static Accelerator_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(Accelerator_Data))) Accelerator_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t id;
            uint8_t pad0_[4];
            mojo::internal::Pointer<::ui::mojom::internal::EventMatcher_Data> event_matcher;

        private:
            Accelerator_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~Accelerator_Data() = delete;
        };
        static_assert(sizeof(Accelerator_Data) == 24,
            "Bad sizeof(Accelerator_Data)");
        constexpr uint32_t kWindowManager_OnConnect_Name = 0;
        class WindowManager_OnConnect_Params_Data {
        public:
            static WindowManager_OnConnect_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowManager_OnConnect_Params_Data))) WindowManager_OnConnect_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint16_t client_id;
            uint8_t padfinal_[6];

        private:
            WindowManager_OnConnect_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowManager_OnConnect_Params_Data() = delete;
        };
        static_assert(sizeof(WindowManager_OnConnect_Params_Data) == 16,
            "Bad sizeof(WindowManager_OnConnect_Params_Data)");
        constexpr uint32_t kWindowManager_WmNewDisplayAdded_Name = 1;
        class WindowManager_WmNewDisplayAdded_Params_Data {
        public:
            static WindowManager_WmNewDisplayAdded_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowManager_WmNewDisplayAdded_Params_Data))) WindowManager_WmNewDisplayAdded_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::display::mojom::internal::Display_Data> display;
            mojo::internal::Pointer<::ui::mojom::internal::WindowData_Data> root;
            uint8_t parent_drawn : 1;
            uint8_t padfinal_[7];

        private:
            WindowManager_WmNewDisplayAdded_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowManager_WmNewDisplayAdded_Params_Data() = delete;
        };
        static_assert(sizeof(WindowManager_WmNewDisplayAdded_Params_Data) == 32,
            "Bad sizeof(WindowManager_WmNewDisplayAdded_Params_Data)");
        constexpr uint32_t kWindowManager_WmDisplayRemoved_Name = 2;
        class WindowManager_WmDisplayRemoved_Params_Data {
        public:
            static WindowManager_WmDisplayRemoved_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowManager_WmDisplayRemoved_Params_Data))) WindowManager_WmDisplayRemoved_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int64_t display_id;

        private:
            WindowManager_WmDisplayRemoved_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowManager_WmDisplayRemoved_Params_Data() = delete;
        };
        static_assert(sizeof(WindowManager_WmDisplayRemoved_Params_Data) == 16,
            "Bad sizeof(WindowManager_WmDisplayRemoved_Params_Data)");
        constexpr uint32_t kWindowManager_WmDisplayModified_Name = 3;
        class WindowManager_WmDisplayModified_Params_Data {
        public:
            static WindowManager_WmDisplayModified_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowManager_WmDisplayModified_Params_Data))) WindowManager_WmDisplayModified_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::display::mojom::internal::Display_Data> display;

        private:
            WindowManager_WmDisplayModified_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowManager_WmDisplayModified_Params_Data() = delete;
        };
        static_assert(sizeof(WindowManager_WmDisplayModified_Params_Data) == 16,
            "Bad sizeof(WindowManager_WmDisplayModified_Params_Data)");
        constexpr uint32_t kWindowManager_WmSetBounds_Name = 4;
        class WindowManager_WmSetBounds_Params_Data {
        public:
            static WindowManager_WmSetBounds_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowManager_WmSetBounds_Params_Data))) WindowManager_WmSetBounds_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t change_id;
            uint32_t window_id;
            mojo::internal::Pointer<::gfx::mojom::internal::Rect_Data> bounds;

        private:
            WindowManager_WmSetBounds_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowManager_WmSetBounds_Params_Data() = delete;
        };
        static_assert(sizeof(WindowManager_WmSetBounds_Params_Data) == 24,
            "Bad sizeof(WindowManager_WmSetBounds_Params_Data)");
        constexpr uint32_t kWindowManager_WmSetProperty_Name = 5;
        class WindowManager_WmSetProperty_Params_Data {
        public:
            static WindowManager_WmSetProperty_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowManager_WmSetProperty_Params_Data))) WindowManager_WmSetProperty_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t change_id;
            uint32_t window_id;
            mojo::internal::Pointer<mojo::internal::String_Data> name;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> value;

        private:
            WindowManager_WmSetProperty_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowManager_WmSetProperty_Params_Data() = delete;
        };
        static_assert(sizeof(WindowManager_WmSetProperty_Params_Data) == 32,
            "Bad sizeof(WindowManager_WmSetProperty_Params_Data)");
        constexpr uint32_t kWindowManager_WmCreateTopLevelWindow_Name = 6;
        class WindowManager_WmCreateTopLevelWindow_Params_Data {
        public:
            static WindowManager_WmCreateTopLevelWindow_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowManager_WmCreateTopLevelWindow_Params_Data))) WindowManager_WmCreateTopLevelWindow_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t change_id;
            uint16_t requesting_client_id;
            uint8_t pad1_[2];
            mojo::internal::Pointer<mojo::internal::Map_Data<mojo::internal::Pointer<mojo::internal::String_Data>, mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>>>> properties;

        private:
            WindowManager_WmCreateTopLevelWindow_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowManager_WmCreateTopLevelWindow_Params_Data() = delete;
        };
        static_assert(sizeof(WindowManager_WmCreateTopLevelWindow_Params_Data) == 24,
            "Bad sizeof(WindowManager_WmCreateTopLevelWindow_Params_Data)");
        constexpr uint32_t kWindowManager_WmClientJankinessChanged_Name = 7;
        class WindowManager_WmClientJankinessChanged_Params_Data {
        public:
            static WindowManager_WmClientJankinessChanged_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowManager_WmClientJankinessChanged_Params_Data))) WindowManager_WmClientJankinessChanged_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint16_t client_id;
            uint8_t janky : 1;
            uint8_t padfinal_[5];

        private:
            WindowManager_WmClientJankinessChanged_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowManager_WmClientJankinessChanged_Params_Data() = delete;
        };
        static_assert(sizeof(WindowManager_WmClientJankinessChanged_Params_Data) == 16,
            "Bad sizeof(WindowManager_WmClientJankinessChanged_Params_Data)");
        constexpr uint32_t kWindowManager_WmPerformMoveLoop_Name = 8;
        class WindowManager_WmPerformMoveLoop_Params_Data {
        public:
            static WindowManager_WmPerformMoveLoop_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowManager_WmPerformMoveLoop_Params_Data))) WindowManager_WmPerformMoveLoop_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t change_id;
            uint32_t window_id;
            int32_t source;
            uint8_t pad2_[4];
            mojo::internal::Pointer<::gfx::mojom::internal::Point_Data> cursor_location;

        private:
            WindowManager_WmPerformMoveLoop_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowManager_WmPerformMoveLoop_Params_Data() = delete;
        };
        static_assert(sizeof(WindowManager_WmPerformMoveLoop_Params_Data) == 32,
            "Bad sizeof(WindowManager_WmPerformMoveLoop_Params_Data)");
        constexpr uint32_t kWindowManager_WmCancelMoveLoop_Name = 9;
        class WindowManager_WmCancelMoveLoop_Params_Data {
        public:
            static WindowManager_WmCancelMoveLoop_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowManager_WmCancelMoveLoop_Params_Data))) WindowManager_WmCancelMoveLoop_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t change_id;
            uint8_t padfinal_[4];

        private:
            WindowManager_WmCancelMoveLoop_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowManager_WmCancelMoveLoop_Params_Data() = delete;
        };
        static_assert(sizeof(WindowManager_WmCancelMoveLoop_Params_Data) == 16,
            "Bad sizeof(WindowManager_WmCancelMoveLoop_Params_Data)");
        constexpr uint32_t kWindowManager_WmDeactivateWindow_Name = 10;
        class WindowManager_WmDeactivateWindow_Params_Data {
        public:
            static WindowManager_WmDeactivateWindow_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowManager_WmDeactivateWindow_Params_Data))) WindowManager_WmDeactivateWindow_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t window_id;
            uint8_t padfinal_[4];

        private:
            WindowManager_WmDeactivateWindow_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowManager_WmDeactivateWindow_Params_Data() = delete;
        };
        static_assert(sizeof(WindowManager_WmDeactivateWindow_Params_Data) == 16,
            "Bad sizeof(WindowManager_WmDeactivateWindow_Params_Data)");
        constexpr uint32_t kWindowManager_OnAccelerator_Name = 11;
        class WindowManager_OnAccelerator_Params_Data {
        public:
            static WindowManager_OnAccelerator_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowManager_OnAccelerator_Params_Data))) WindowManager_OnAccelerator_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t ack_id;
            uint32_t accelerator_id;
            mojo::internal::Pointer<::ui::mojom::internal::Event_Data> event;

        private:
            WindowManager_OnAccelerator_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowManager_OnAccelerator_Params_Data() = delete;
        };
        static_assert(sizeof(WindowManager_OnAccelerator_Params_Data) == 24,
            "Bad sizeof(WindowManager_OnAccelerator_Params_Data)");
        constexpr uint32_t kWindowManagerClient_AddActivationParent_Name = 0;
        class WindowManagerClient_AddActivationParent_Params_Data {
        public:
            static WindowManagerClient_AddActivationParent_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowManagerClient_AddActivationParent_Params_Data))) WindowManagerClient_AddActivationParent_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t window_id;
            uint8_t padfinal_[4];

        private:
            WindowManagerClient_AddActivationParent_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowManagerClient_AddActivationParent_Params_Data() = delete;
        };
        static_assert(sizeof(WindowManagerClient_AddActivationParent_Params_Data) == 16,
            "Bad sizeof(WindowManagerClient_AddActivationParent_Params_Data)");
        constexpr uint32_t kWindowManagerClient_RemoveActivationParent_Name = 1;
        class WindowManagerClient_RemoveActivationParent_Params_Data {
        public:
            static WindowManagerClient_RemoveActivationParent_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowManagerClient_RemoveActivationParent_Params_Data))) WindowManagerClient_RemoveActivationParent_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t window_id;
            uint8_t padfinal_[4];

        private:
            WindowManagerClient_RemoveActivationParent_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowManagerClient_RemoveActivationParent_Params_Data() = delete;
        };
        static_assert(sizeof(WindowManagerClient_RemoveActivationParent_Params_Data) == 16,
            "Bad sizeof(WindowManagerClient_RemoveActivationParent_Params_Data)");
        constexpr uint32_t kWindowManagerClient_ActivateNextWindow_Name = 2;
        class WindowManagerClient_ActivateNextWindow_Params_Data {
        public:
            static WindowManagerClient_ActivateNextWindow_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowManagerClient_ActivateNextWindow_Params_Data))) WindowManagerClient_ActivateNextWindow_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            WindowManagerClient_ActivateNextWindow_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowManagerClient_ActivateNextWindow_Params_Data() = delete;
        };
        static_assert(sizeof(WindowManagerClient_ActivateNextWindow_Params_Data) == 8,
            "Bad sizeof(WindowManagerClient_ActivateNextWindow_Params_Data)");
        constexpr uint32_t kWindowManagerClient_SetUnderlaySurfaceOffsetAndExtendedHitArea_Name = 3;
        class WindowManagerClient_SetUnderlaySurfaceOffsetAndExtendedHitArea_Params_Data {
        public:
            static WindowManagerClient_SetUnderlaySurfaceOffsetAndExtendedHitArea_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowManagerClient_SetUnderlaySurfaceOffsetAndExtendedHitArea_Params_Data))) WindowManagerClient_SetUnderlaySurfaceOffsetAndExtendedHitArea_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t window_id;
            int32_t x_offset;
            int32_t y_offset;
            uint8_t pad2_[4];
            mojo::internal::Pointer<::gfx::mojom::internal::Insets_Data> hit_area;

        private:
            WindowManagerClient_SetUnderlaySurfaceOffsetAndExtendedHitArea_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowManagerClient_SetUnderlaySurfaceOffsetAndExtendedHitArea_Params_Data() = delete;
        };
        static_assert(sizeof(WindowManagerClient_SetUnderlaySurfaceOffsetAndExtendedHitArea_Params_Data) == 32,
            "Bad sizeof(WindowManagerClient_SetUnderlaySurfaceOffsetAndExtendedHitArea_Params_Data)");
        constexpr uint32_t kWindowManagerClient_AddAccelerators_Name = 4;
        class WindowManagerClient_AddAccelerators_Params_Data {
        public:
            static WindowManagerClient_AddAccelerators_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowManagerClient_AddAccelerators_Params_Data))) WindowManagerClient_AddAccelerators_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::Accelerator_Data>>> accelerators;

        private:
            WindowManagerClient_AddAccelerators_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowManagerClient_AddAccelerators_Params_Data() = delete;
        };
        static_assert(sizeof(WindowManagerClient_AddAccelerators_Params_Data) == 16,
            "Bad sizeof(WindowManagerClient_AddAccelerators_Params_Data)");
        class WindowManagerClient_AddAccelerators_ResponseParams_Data {
        public:
            static WindowManagerClient_AddAccelerators_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowManagerClient_AddAccelerators_ResponseParams_Data))) WindowManagerClient_AddAccelerators_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t success : 1;
            uint8_t padfinal_[7];

        private:
            WindowManagerClient_AddAccelerators_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowManagerClient_AddAccelerators_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(WindowManagerClient_AddAccelerators_ResponseParams_Data) == 16,
            "Bad sizeof(WindowManagerClient_AddAccelerators_ResponseParams_Data)");
        constexpr uint32_t kWindowManagerClient_RemoveAccelerator_Name = 5;
        class WindowManagerClient_RemoveAccelerator_Params_Data {
        public:
            static WindowManagerClient_RemoveAccelerator_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowManagerClient_RemoveAccelerator_Params_Data))) WindowManagerClient_RemoveAccelerator_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t id;
            uint8_t padfinal_[4];

        private:
            WindowManagerClient_RemoveAccelerator_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowManagerClient_RemoveAccelerator_Params_Data() = delete;
        };
        static_assert(sizeof(WindowManagerClient_RemoveAccelerator_Params_Data) == 16,
            "Bad sizeof(WindowManagerClient_RemoveAccelerator_Params_Data)");
        constexpr uint32_t kWindowManagerClient_WmResponse_Name = 6;
        class WindowManagerClient_WmResponse_Params_Data {
        public:
            static WindowManagerClient_WmResponse_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowManagerClient_WmResponse_Params_Data))) WindowManagerClient_WmResponse_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t change_id;
            uint8_t response : 1;
            uint8_t padfinal_[3];

        private:
            WindowManagerClient_WmResponse_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowManagerClient_WmResponse_Params_Data() = delete;
        };
        static_assert(sizeof(WindowManagerClient_WmResponse_Params_Data) == 16,
            "Bad sizeof(WindowManagerClient_WmResponse_Params_Data)");
        constexpr uint32_t kWindowManagerClient_WmRequestClose_Name = 7;
        class WindowManagerClient_WmRequestClose_Params_Data {
        public:
            static WindowManagerClient_WmRequestClose_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowManagerClient_WmRequestClose_Params_Data))) WindowManagerClient_WmRequestClose_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t window_id;
            uint8_t padfinal_[4];

        private:
            WindowManagerClient_WmRequestClose_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowManagerClient_WmRequestClose_Params_Data() = delete;
        };
        static_assert(sizeof(WindowManagerClient_WmRequestClose_Params_Data) == 16,
            "Bad sizeof(WindowManagerClient_WmRequestClose_Params_Data)");
        constexpr uint32_t kWindowManagerClient_WmSetFrameDecorationValues_Name = 8;
        class WindowManagerClient_WmSetFrameDecorationValues_Params_Data {
        public:
            static WindowManagerClient_WmSetFrameDecorationValues_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowManagerClient_WmSetFrameDecorationValues_Params_Data))) WindowManagerClient_WmSetFrameDecorationValues_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::ui::mojom::internal::FrameDecorationValues_Data> values;

        private:
            WindowManagerClient_WmSetFrameDecorationValues_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowManagerClient_WmSetFrameDecorationValues_Params_Data() = delete;
        };
        static_assert(sizeof(WindowManagerClient_WmSetFrameDecorationValues_Params_Data) == 16,
            "Bad sizeof(WindowManagerClient_WmSetFrameDecorationValues_Params_Data)");
        constexpr uint32_t kWindowManagerClient_WmSetNonClientCursor_Name = 9;
        class WindowManagerClient_WmSetNonClientCursor_Params_Data {
        public:
            static WindowManagerClient_WmSetNonClientCursor_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowManagerClient_WmSetNonClientCursor_Params_Data))) WindowManagerClient_WmSetNonClientCursor_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t window_id;
            int32_t cursor_id;

        private:
            WindowManagerClient_WmSetNonClientCursor_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowManagerClient_WmSetNonClientCursor_Params_Data() = delete;
        };
        static_assert(sizeof(WindowManagerClient_WmSetNonClientCursor_Params_Data) == 16,
            "Bad sizeof(WindowManagerClient_WmSetNonClientCursor_Params_Data)");
        constexpr uint32_t kWindowManagerClient_OnWmCreatedTopLevelWindow_Name = 10;
        class WindowManagerClient_OnWmCreatedTopLevelWindow_Params_Data {
        public:
            static WindowManagerClient_OnWmCreatedTopLevelWindow_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowManagerClient_OnWmCreatedTopLevelWindow_Params_Data))) WindowManagerClient_OnWmCreatedTopLevelWindow_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t change_id;
            uint32_t window_id;

        private:
            WindowManagerClient_OnWmCreatedTopLevelWindow_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowManagerClient_OnWmCreatedTopLevelWindow_Params_Data() = delete;
        };
        static_assert(sizeof(WindowManagerClient_OnWmCreatedTopLevelWindow_Params_Data) == 16,
            "Bad sizeof(WindowManagerClient_OnWmCreatedTopLevelWindow_Params_Data)");
        constexpr uint32_t kWindowManagerClient_OnAcceleratorAck_Name = 11;
        class WindowManagerClient_OnAcceleratorAck_Params_Data {
        public:
            static WindowManagerClient_OnAcceleratorAck_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowManagerClient_OnAcceleratorAck_Params_Data))) WindowManagerClient_OnAcceleratorAck_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t ack_id;
            int32_t event_result;

        private:
            WindowManagerClient_OnAcceleratorAck_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowManagerClient_OnAcceleratorAck_Params_Data() = delete;
        };
        static_assert(sizeof(WindowManagerClient_OnAcceleratorAck_Params_Data) == 16,
            "Bad sizeof(WindowManagerClient_OnAcceleratorAck_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace ui

#endif // SERVICES_UI_PUBLIC_INTERFACES_WINDOW_MANAGER_MOJOM_SHARED_INTERNAL_H_