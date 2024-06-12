// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_WINDOW_TREE_MOJOM_SHARED_INTERNAL_H_
#define SERVICES_UI_PUBLIC_INTERFACES_WINDOW_TREE_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "cc/ipc/mojo_compositor_frame_sink.mojom-shared-internal.h"
#include "cc/ipc/surface_info.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "services/ui/public/interfaces/cursor.mojom-shared-internal.h"
#include "services/ui/public/interfaces/event_matcher.mojom-shared-internal.h"
#include "services/ui/public/interfaces/mus_constants.mojom-shared-internal.h"
#include "services/ui/public/interfaces/window_manager.mojom-shared-internal.h"
#include "services/ui/public/interfaces/window_manager_constants.mojom-shared-internal.h"
#include "services/ui/public/interfaces/window_tree_constants.mojom-shared-internal.h"
#include "ui/events/mojo/event.mojom-shared-internal.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared-internal.h"
#include "ui/platform_window/mojo/text_input_state.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace ui {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kWindowTree_NewWindow_Name = 0;
        class WindowTree_NewWindow_Params_Data {
        public:
            static WindowTree_NewWindow_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTree_NewWindow_Params_Data))) WindowTree_NewWindow_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t change_id;
            uint32_t window_id;
            mojo::internal::Pointer<mojo::internal::Map_Data<mojo::internal::Pointer<mojo::internal::String_Data>, mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>>>> properties;

        private:
            WindowTree_NewWindow_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTree_NewWindow_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTree_NewWindow_Params_Data) == 24,
            "Bad sizeof(WindowTree_NewWindow_Params_Data)");
        constexpr uint32_t kWindowTree_NewTopLevelWindow_Name = 1;
        class WindowTree_NewTopLevelWindow_Params_Data {
        public:
            static WindowTree_NewTopLevelWindow_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTree_NewTopLevelWindow_Params_Data))) WindowTree_NewTopLevelWindow_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t change_id;
            uint32_t window_id;
            mojo::internal::Pointer<mojo::internal::Map_Data<mojo::internal::Pointer<mojo::internal::String_Data>, mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>>>> properties;

        private:
            WindowTree_NewTopLevelWindow_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTree_NewTopLevelWindow_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTree_NewTopLevelWindow_Params_Data) == 24,
            "Bad sizeof(WindowTree_NewTopLevelWindow_Params_Data)");
        constexpr uint32_t kWindowTree_DeleteWindow_Name = 2;
        class WindowTree_DeleteWindow_Params_Data {
        public:
            static WindowTree_DeleteWindow_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTree_DeleteWindow_Params_Data))) WindowTree_DeleteWindow_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t change_id;
            uint32_t window_id;

        private:
            WindowTree_DeleteWindow_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTree_DeleteWindow_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTree_DeleteWindow_Params_Data) == 16,
            "Bad sizeof(WindowTree_DeleteWindow_Params_Data)");
        constexpr uint32_t kWindowTree_SetCapture_Name = 3;
        class WindowTree_SetCapture_Params_Data {
        public:
            static WindowTree_SetCapture_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTree_SetCapture_Params_Data))) WindowTree_SetCapture_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t change_id;
            uint32_t window_id;

        private:
            WindowTree_SetCapture_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTree_SetCapture_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTree_SetCapture_Params_Data) == 16,
            "Bad sizeof(WindowTree_SetCapture_Params_Data)");
        constexpr uint32_t kWindowTree_ReleaseCapture_Name = 4;
        class WindowTree_ReleaseCapture_Params_Data {
        public:
            static WindowTree_ReleaseCapture_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTree_ReleaseCapture_Params_Data))) WindowTree_ReleaseCapture_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t change_id;
            uint32_t window_id;

        private:
            WindowTree_ReleaseCapture_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTree_ReleaseCapture_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTree_ReleaseCapture_Params_Data) == 16,
            "Bad sizeof(WindowTree_ReleaseCapture_Params_Data)");
        constexpr uint32_t kWindowTree_StartPointerWatcher_Name = 5;
        class WindowTree_StartPointerWatcher_Params_Data {
        public:
            static WindowTree_StartPointerWatcher_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTree_StartPointerWatcher_Params_Data))) WindowTree_StartPointerWatcher_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t want_moves : 1;
            uint8_t padfinal_[7];

        private:
            WindowTree_StartPointerWatcher_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTree_StartPointerWatcher_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTree_StartPointerWatcher_Params_Data) == 16,
            "Bad sizeof(WindowTree_StartPointerWatcher_Params_Data)");
        constexpr uint32_t kWindowTree_StopPointerWatcher_Name = 6;
        class WindowTree_StopPointerWatcher_Params_Data {
        public:
            static WindowTree_StopPointerWatcher_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTree_StopPointerWatcher_Params_Data))) WindowTree_StopPointerWatcher_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            WindowTree_StopPointerWatcher_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTree_StopPointerWatcher_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTree_StopPointerWatcher_Params_Data) == 8,
            "Bad sizeof(WindowTree_StopPointerWatcher_Params_Data)");
        constexpr uint32_t kWindowTree_SetWindowBounds_Name = 7;
        class WindowTree_SetWindowBounds_Params_Data {
        public:
            static WindowTree_SetWindowBounds_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTree_SetWindowBounds_Params_Data))) WindowTree_SetWindowBounds_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t change_id;
            uint32_t window_id;
            mojo::internal::Pointer<::gfx::mojom::internal::Rect_Data> bounds;

        private:
            WindowTree_SetWindowBounds_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTree_SetWindowBounds_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTree_SetWindowBounds_Params_Data) == 24,
            "Bad sizeof(WindowTree_SetWindowBounds_Params_Data)");
        constexpr uint32_t kWindowTree_SetClientArea_Name = 8;
        class WindowTree_SetClientArea_Params_Data {
        public:
            static WindowTree_SetClientArea_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTree_SetClientArea_Params_Data))) WindowTree_SetClientArea_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t window_id;
            uint8_t pad0_[4];
            mojo::internal::Pointer<::gfx::mojom::internal::Insets_Data> insets;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::gfx::mojom::internal::Rect_Data>>> additional_client_areas;

        private:
            WindowTree_SetClientArea_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTree_SetClientArea_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTree_SetClientArea_Params_Data) == 32,
            "Bad sizeof(WindowTree_SetClientArea_Params_Data)");
        constexpr uint32_t kWindowTree_SetHitTestMask_Name = 9;
        class WindowTree_SetHitTestMask_Params_Data {
        public:
            static WindowTree_SetHitTestMask_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTree_SetHitTestMask_Params_Data))) WindowTree_SetHitTestMask_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t window_id;
            uint8_t pad0_[4];
            mojo::internal::Pointer<::gfx::mojom::internal::Rect_Data> mask;

        private:
            WindowTree_SetHitTestMask_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTree_SetHitTestMask_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTree_SetHitTestMask_Params_Data) == 24,
            "Bad sizeof(WindowTree_SetHitTestMask_Params_Data)");
        constexpr uint32_t kWindowTree_SetCanAcceptDrops_Name = 10;
        class WindowTree_SetCanAcceptDrops_Params_Data {
        public:
            static WindowTree_SetCanAcceptDrops_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTree_SetCanAcceptDrops_Params_Data))) WindowTree_SetCanAcceptDrops_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t window_id;
            uint8_t accepts_drops : 1;
            uint8_t padfinal_[3];

        private:
            WindowTree_SetCanAcceptDrops_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTree_SetCanAcceptDrops_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTree_SetCanAcceptDrops_Params_Data) == 16,
            "Bad sizeof(WindowTree_SetCanAcceptDrops_Params_Data)");
        constexpr uint32_t kWindowTree_SetWindowVisibility_Name = 11;
        class WindowTree_SetWindowVisibility_Params_Data {
        public:
            static WindowTree_SetWindowVisibility_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTree_SetWindowVisibility_Params_Data))) WindowTree_SetWindowVisibility_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t change_id;
            uint32_t window_id;
            uint8_t visible : 1;
            uint8_t padfinal_[7];

        private:
            WindowTree_SetWindowVisibility_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTree_SetWindowVisibility_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTree_SetWindowVisibility_Params_Data) == 24,
            "Bad sizeof(WindowTree_SetWindowVisibility_Params_Data)");
        constexpr uint32_t kWindowTree_SetWindowProperty_Name = 12;
        class WindowTree_SetWindowProperty_Params_Data {
        public:
            static WindowTree_SetWindowProperty_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTree_SetWindowProperty_Params_Data))) WindowTree_SetWindowProperty_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t change_id;
            uint32_t window_id;
            mojo::internal::Pointer<mojo::internal::String_Data> name;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> value;

        private:
            WindowTree_SetWindowProperty_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTree_SetWindowProperty_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTree_SetWindowProperty_Params_Data) == 32,
            "Bad sizeof(WindowTree_SetWindowProperty_Params_Data)");
        constexpr uint32_t kWindowTree_SetWindowOpacity_Name = 13;
        class WindowTree_SetWindowOpacity_Params_Data {
        public:
            static WindowTree_SetWindowOpacity_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTree_SetWindowOpacity_Params_Data))) WindowTree_SetWindowOpacity_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t change_id;
            uint32_t window_id;
            float opacity;
            uint8_t padfinal_[4];

        private:
            WindowTree_SetWindowOpacity_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTree_SetWindowOpacity_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTree_SetWindowOpacity_Params_Data) == 24,
            "Bad sizeof(WindowTree_SetWindowOpacity_Params_Data)");
        constexpr uint32_t kWindowTree_AttachCompositorFrameSink_Name = 14;
        class WindowTree_AttachCompositorFrameSink_Params_Data {
        public:
            static WindowTree_AttachCompositorFrameSink_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTree_AttachCompositorFrameSink_Params_Data))) WindowTree_AttachCompositorFrameSink_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t window_id;
            mojo::internal::Handle_Data compositor_frame_sink;
            mojo::internal::Interface_Data client;

        private:
            WindowTree_AttachCompositorFrameSink_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTree_AttachCompositorFrameSink_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTree_AttachCompositorFrameSink_Params_Data) == 24,
            "Bad sizeof(WindowTree_AttachCompositorFrameSink_Params_Data)");
        constexpr uint32_t kWindowTree_AddWindow_Name = 15;
        class WindowTree_AddWindow_Params_Data {
        public:
            static WindowTree_AddWindow_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTree_AddWindow_Params_Data))) WindowTree_AddWindow_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t change_id;
            uint32_t parent;
            uint32_t child;
            uint8_t padfinal_[4];

        private:
            WindowTree_AddWindow_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTree_AddWindow_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTree_AddWindow_Params_Data) == 24,
            "Bad sizeof(WindowTree_AddWindow_Params_Data)");
        constexpr uint32_t kWindowTree_RemoveWindowFromParent_Name = 16;
        class WindowTree_RemoveWindowFromParent_Params_Data {
        public:
            static WindowTree_RemoveWindowFromParent_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTree_RemoveWindowFromParent_Params_Data))) WindowTree_RemoveWindowFromParent_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t change_id;
            uint32_t window_id;

        private:
            WindowTree_RemoveWindowFromParent_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTree_RemoveWindowFromParent_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTree_RemoveWindowFromParent_Params_Data) == 16,
            "Bad sizeof(WindowTree_RemoveWindowFromParent_Params_Data)");
        constexpr uint32_t kWindowTree_AddTransientWindow_Name = 17;
        class WindowTree_AddTransientWindow_Params_Data {
        public:
            static WindowTree_AddTransientWindow_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTree_AddTransientWindow_Params_Data))) WindowTree_AddTransientWindow_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t change_id;
            uint32_t window_id;
            uint32_t transient_window_id;
            uint8_t padfinal_[4];

        private:
            WindowTree_AddTransientWindow_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTree_AddTransientWindow_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTree_AddTransientWindow_Params_Data) == 24,
            "Bad sizeof(WindowTree_AddTransientWindow_Params_Data)");
        constexpr uint32_t kWindowTree_RemoveTransientWindowFromParent_Name = 18;
        class WindowTree_RemoveTransientWindowFromParent_Params_Data {
        public:
            static WindowTree_RemoveTransientWindowFromParent_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTree_RemoveTransientWindowFromParent_Params_Data))) WindowTree_RemoveTransientWindowFromParent_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t change_id;
            uint32_t transient_window_id;

        private:
            WindowTree_RemoveTransientWindowFromParent_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTree_RemoveTransientWindowFromParent_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTree_RemoveTransientWindowFromParent_Params_Data) == 16,
            "Bad sizeof(WindowTree_RemoveTransientWindowFromParent_Params_Data)");
        constexpr uint32_t kWindowTree_SetModal_Name = 19;
        class WindowTree_SetModal_Params_Data {
        public:
            static WindowTree_SetModal_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTree_SetModal_Params_Data))) WindowTree_SetModal_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t change_id;
            uint32_t window_id;

        private:
            WindowTree_SetModal_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTree_SetModal_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTree_SetModal_Params_Data) == 16,
            "Bad sizeof(WindowTree_SetModal_Params_Data)");
        constexpr uint32_t kWindowTree_ReorderWindow_Name = 20;
        class WindowTree_ReorderWindow_Params_Data {
        public:
            static WindowTree_ReorderWindow_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTree_ReorderWindow_Params_Data))) WindowTree_ReorderWindow_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t change_id;
            uint32_t window_id;
            uint32_t relative_window_id;
            int32_t direction;

        private:
            WindowTree_ReorderWindow_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTree_ReorderWindow_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTree_ReorderWindow_Params_Data) == 24,
            "Bad sizeof(WindowTree_ReorderWindow_Params_Data)");
        constexpr uint32_t kWindowTree_GetWindowTree_Name = 21;
        class WindowTree_GetWindowTree_Params_Data {
        public:
            static WindowTree_GetWindowTree_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTree_GetWindowTree_Params_Data))) WindowTree_GetWindowTree_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t window_id;
            uint8_t padfinal_[4];

        private:
            WindowTree_GetWindowTree_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTree_GetWindowTree_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTree_GetWindowTree_Params_Data) == 16,
            "Bad sizeof(WindowTree_GetWindowTree_Params_Data)");
        class WindowTree_GetWindowTree_ResponseParams_Data {
        public:
            static WindowTree_GetWindowTree_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTree_GetWindowTree_ResponseParams_Data))) WindowTree_GetWindowTree_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::ui::mojom::internal::WindowData_Data>>> windows;

        private:
            WindowTree_GetWindowTree_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTree_GetWindowTree_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(WindowTree_GetWindowTree_ResponseParams_Data) == 16,
            "Bad sizeof(WindowTree_GetWindowTree_ResponseParams_Data)");
        constexpr uint32_t kWindowTree_Embed_Name = 22;
        class WindowTree_Embed_Params_Data {
        public:
            static WindowTree_Embed_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTree_Embed_Params_Data))) WindowTree_Embed_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t window_id;
            mojo::internal::Interface_Data client;
            uint32_t embed_flags;

        private:
            WindowTree_Embed_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTree_Embed_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTree_Embed_Params_Data) == 24,
            "Bad sizeof(WindowTree_Embed_Params_Data)");
        class WindowTree_Embed_ResponseParams_Data {
        public:
            static WindowTree_Embed_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTree_Embed_ResponseParams_Data))) WindowTree_Embed_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t success : 1;
            uint8_t padfinal_[7];

        private:
            WindowTree_Embed_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTree_Embed_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(WindowTree_Embed_ResponseParams_Data) == 16,
            "Bad sizeof(WindowTree_Embed_ResponseParams_Data)");
        constexpr uint32_t kWindowTree_SetFocus_Name = 23;
        class WindowTree_SetFocus_Params_Data {
        public:
            static WindowTree_SetFocus_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTree_SetFocus_Params_Data))) WindowTree_SetFocus_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t change_id;
            uint32_t window_id;

        private:
            WindowTree_SetFocus_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTree_SetFocus_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTree_SetFocus_Params_Data) == 16,
            "Bad sizeof(WindowTree_SetFocus_Params_Data)");
        constexpr uint32_t kWindowTree_SetCanFocus_Name = 24;
        class WindowTree_SetCanFocus_Params_Data {
        public:
            static WindowTree_SetCanFocus_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTree_SetCanFocus_Params_Data))) WindowTree_SetCanFocus_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t window_id;
            uint8_t can_focus : 1;
            uint8_t padfinal_[3];

        private:
            WindowTree_SetCanFocus_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTree_SetCanFocus_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTree_SetCanFocus_Params_Data) == 16,
            "Bad sizeof(WindowTree_SetCanFocus_Params_Data)");
        constexpr uint32_t kWindowTree_SetPredefinedCursor_Name = 25;
        class WindowTree_SetPredefinedCursor_Params_Data {
        public:
            static WindowTree_SetPredefinedCursor_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTree_SetPredefinedCursor_Params_Data))) WindowTree_SetPredefinedCursor_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t change_id;
            uint32_t window_id;
            int32_t cursor_id;
            uint8_t padfinal_[4];

        private:
            WindowTree_SetPredefinedCursor_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTree_SetPredefinedCursor_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTree_SetPredefinedCursor_Params_Data) == 24,
            "Bad sizeof(WindowTree_SetPredefinedCursor_Params_Data)");
        constexpr uint32_t kWindowTree_SetWindowTextInputState_Name = 26;
        class WindowTree_SetWindowTextInputState_Params_Data {
        public:
            static WindowTree_SetWindowTextInputState_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTree_SetWindowTextInputState_Params_Data))) WindowTree_SetWindowTextInputState_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t window_id;
            uint8_t pad0_[4];
            mojo::internal::Pointer<::mojo::internal::TextInputState_Data> state;

        private:
            WindowTree_SetWindowTextInputState_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTree_SetWindowTextInputState_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTree_SetWindowTextInputState_Params_Data) == 24,
            "Bad sizeof(WindowTree_SetWindowTextInputState_Params_Data)");
        constexpr uint32_t kWindowTree_SetImeVisibility_Name = 27;
        class WindowTree_SetImeVisibility_Params_Data {
        public:
            static WindowTree_SetImeVisibility_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTree_SetImeVisibility_Params_Data))) WindowTree_SetImeVisibility_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t window_id;
            uint8_t visible : 1;
            uint8_t pad1_[3];
            mojo::internal::Pointer<::mojo::internal::TextInputState_Data> state;

        private:
            WindowTree_SetImeVisibility_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTree_SetImeVisibility_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTree_SetImeVisibility_Params_Data) == 24,
            "Bad sizeof(WindowTree_SetImeVisibility_Params_Data)");
        constexpr uint32_t kWindowTree_SetCanAcceptEvents_Name = 28;
        class WindowTree_SetCanAcceptEvents_Params_Data {
        public:
            static WindowTree_SetCanAcceptEvents_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTree_SetCanAcceptEvents_Params_Data))) WindowTree_SetCanAcceptEvents_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t window_id;
            uint8_t accept_events : 1;
            uint8_t padfinal_[3];

        private:
            WindowTree_SetCanAcceptEvents_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTree_SetCanAcceptEvents_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTree_SetCanAcceptEvents_Params_Data) == 16,
            "Bad sizeof(WindowTree_SetCanAcceptEvents_Params_Data)");
        constexpr uint32_t kWindowTree_OnWindowInputEventAck_Name = 29;
        class WindowTree_OnWindowInputEventAck_Params_Data {
        public:
            static WindowTree_OnWindowInputEventAck_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTree_OnWindowInputEventAck_Params_Data))) WindowTree_OnWindowInputEventAck_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t event_id;
            int32_t result;

        private:
            WindowTree_OnWindowInputEventAck_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTree_OnWindowInputEventAck_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTree_OnWindowInputEventAck_Params_Data) == 16,
            "Bad sizeof(WindowTree_OnWindowInputEventAck_Params_Data)");
        constexpr uint32_t kWindowTree_DeactivateWindow_Name = 30;
        class WindowTree_DeactivateWindow_Params_Data {
        public:
            static WindowTree_DeactivateWindow_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTree_DeactivateWindow_Params_Data))) WindowTree_DeactivateWindow_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t window_id;
            uint8_t padfinal_[4];

        private:
            WindowTree_DeactivateWindow_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTree_DeactivateWindow_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTree_DeactivateWindow_Params_Data) == 16,
            "Bad sizeof(WindowTree_DeactivateWindow_Params_Data)");
        constexpr uint32_t kWindowTree_GetWindowManagerClient_Name = 31;
        class WindowTree_GetWindowManagerClient_Params_Data {
        public:
            static WindowTree_GetWindowManagerClient_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTree_GetWindowManagerClient_Params_Data))) WindowTree_GetWindowManagerClient_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::AssociatedInterfaceRequest_Data internal;
            uint8_t padfinal_[4];

        private:
            WindowTree_GetWindowManagerClient_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTree_GetWindowManagerClient_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTree_GetWindowManagerClient_Params_Data) == 16,
            "Bad sizeof(WindowTree_GetWindowManagerClient_Params_Data)");
        constexpr uint32_t kWindowTree_GetCursorLocationMemory_Name = 32;
        class WindowTree_GetCursorLocationMemory_Params_Data {
        public:
            static WindowTree_GetCursorLocationMemory_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTree_GetCursorLocationMemory_Params_Data))) WindowTree_GetCursorLocationMemory_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            WindowTree_GetCursorLocationMemory_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTree_GetCursorLocationMemory_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTree_GetCursorLocationMemory_Params_Data) == 8,
            "Bad sizeof(WindowTree_GetCursorLocationMemory_Params_Data)");
        class WindowTree_GetCursorLocationMemory_ResponseParams_Data {
        public:
            static WindowTree_GetCursorLocationMemory_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTree_GetCursorLocationMemory_ResponseParams_Data))) WindowTree_GetCursorLocationMemory_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data cursor_buffer;
            uint8_t padfinal_[4];

        private:
            WindowTree_GetCursorLocationMemory_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTree_GetCursorLocationMemory_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(WindowTree_GetCursorLocationMemory_ResponseParams_Data) == 16,
            "Bad sizeof(WindowTree_GetCursorLocationMemory_ResponseParams_Data)");
        constexpr uint32_t kWindowTree_PerformWindowMove_Name = 33;
        class WindowTree_PerformWindowMove_Params_Data {
        public:
            static WindowTree_PerformWindowMove_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTree_PerformWindowMove_Params_Data))) WindowTree_PerformWindowMove_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t change_id;
            uint32_t window_id;
            int32_t source;
            uint8_t pad2_[4];
            mojo::internal::Pointer<::gfx::mojom::internal::Point_Data> cursor;

        private:
            WindowTree_PerformWindowMove_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTree_PerformWindowMove_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTree_PerformWindowMove_Params_Data) == 32,
            "Bad sizeof(WindowTree_PerformWindowMove_Params_Data)");
        constexpr uint32_t kWindowTree_CancelWindowMove_Name = 34;
        class WindowTree_CancelWindowMove_Params_Data {
        public:
            static WindowTree_CancelWindowMove_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTree_CancelWindowMove_Params_Data))) WindowTree_CancelWindowMove_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t window_id;
            uint8_t padfinal_[4];

        private:
            WindowTree_CancelWindowMove_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTree_CancelWindowMove_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTree_CancelWindowMove_Params_Data) == 16,
            "Bad sizeof(WindowTree_CancelWindowMove_Params_Data)");
        constexpr uint32_t kWindowTree_PerformDragDrop_Name = 35;
        class WindowTree_PerformDragDrop_Params_Data {
        public:
            static WindowTree_PerformDragDrop_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTree_PerformDragDrop_Params_Data))) WindowTree_PerformDragDrop_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t change_id;
            uint32_t source_window_id;
            mojo::internal::Pointer<mojo::internal::Map_Data<mojo::internal::Pointer<mojo::internal::String_Data>, mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>>>> drag_data;
            uint32_t drag_operation;
            uint8_t padfinal_[4];

        private:
            WindowTree_PerformDragDrop_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTree_PerformDragDrop_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTree_PerformDragDrop_Params_Data) == 32,
            "Bad sizeof(WindowTree_PerformDragDrop_Params_Data)");
        constexpr uint32_t kWindowTree_CancelDragDrop_Name = 36;
        class WindowTree_CancelDragDrop_Params_Data {
        public:
            static WindowTree_CancelDragDrop_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTree_CancelDragDrop_Params_Data))) WindowTree_CancelDragDrop_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t window_id;
            uint8_t padfinal_[4];

        private:
            WindowTree_CancelDragDrop_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTree_CancelDragDrop_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTree_CancelDragDrop_Params_Data) == 16,
            "Bad sizeof(WindowTree_CancelDragDrop_Params_Data)");
        constexpr uint32_t kWindowTreeClient_OnEmbed_Name = 0;
        class WindowTreeClient_OnEmbed_Params_Data {
        public:
            static WindowTreeClient_OnEmbed_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTreeClient_OnEmbed_Params_Data))) WindowTreeClient_OnEmbed_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint16_t connection_id;
            uint8_t parent_drawn : 1;
            uint8_t pad1_[1];
            uint32_t focused_window;
            mojo::internal::Pointer<::ui::mojom::internal::WindowData_Data> root;
            mojo::internal::Interface_Data tree;
            int64_t display_id;

        private:
            WindowTreeClient_OnEmbed_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTreeClient_OnEmbed_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTreeClient_OnEmbed_Params_Data) == 40,
            "Bad sizeof(WindowTreeClient_OnEmbed_Params_Data)");
        constexpr uint32_t kWindowTreeClient_OnEmbeddedAppDisconnected_Name = 1;
        class WindowTreeClient_OnEmbeddedAppDisconnected_Params_Data {
        public:
            static WindowTreeClient_OnEmbeddedAppDisconnected_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTreeClient_OnEmbeddedAppDisconnected_Params_Data))) WindowTreeClient_OnEmbeddedAppDisconnected_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t window;
            uint8_t padfinal_[4];

        private:
            WindowTreeClient_OnEmbeddedAppDisconnected_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTreeClient_OnEmbeddedAppDisconnected_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTreeClient_OnEmbeddedAppDisconnected_Params_Data) == 16,
            "Bad sizeof(WindowTreeClient_OnEmbeddedAppDisconnected_Params_Data)");
        constexpr uint32_t kWindowTreeClient_OnUnembed_Name = 2;
        class WindowTreeClient_OnUnembed_Params_Data {
        public:
            static WindowTreeClient_OnUnembed_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTreeClient_OnUnembed_Params_Data))) WindowTreeClient_OnUnembed_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t window;
            uint8_t padfinal_[4];

        private:
            WindowTreeClient_OnUnembed_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTreeClient_OnUnembed_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTreeClient_OnUnembed_Params_Data) == 16,
            "Bad sizeof(WindowTreeClient_OnUnembed_Params_Data)");
        constexpr uint32_t kWindowTreeClient_OnCaptureChanged_Name = 3;
        class WindowTreeClient_OnCaptureChanged_Params_Data {
        public:
            static WindowTreeClient_OnCaptureChanged_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTreeClient_OnCaptureChanged_Params_Data))) WindowTreeClient_OnCaptureChanged_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t new_capture;
            uint32_t old_capture;

        private:
            WindowTreeClient_OnCaptureChanged_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTreeClient_OnCaptureChanged_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTreeClient_OnCaptureChanged_Params_Data) == 16,
            "Bad sizeof(WindowTreeClient_OnCaptureChanged_Params_Data)");
        constexpr uint32_t kWindowTreeClient_OnTopLevelCreated_Name = 4;
        class WindowTreeClient_OnTopLevelCreated_Params_Data {
        public:
            static WindowTreeClient_OnTopLevelCreated_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTreeClient_OnTopLevelCreated_Params_Data))) WindowTreeClient_OnTopLevelCreated_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t change_id;
            uint8_t parent_drawn : 1;
            uint8_t pad1_[3];
            mojo::internal::Pointer<::ui::mojom::internal::WindowData_Data> data;
            int64_t display_id;

        private:
            WindowTreeClient_OnTopLevelCreated_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTreeClient_OnTopLevelCreated_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTreeClient_OnTopLevelCreated_Params_Data) == 32,
            "Bad sizeof(WindowTreeClient_OnTopLevelCreated_Params_Data)");
        constexpr uint32_t kWindowTreeClient_OnWindowBoundsChanged_Name = 5;
        class WindowTreeClient_OnWindowBoundsChanged_Params_Data {
        public:
            static WindowTreeClient_OnWindowBoundsChanged_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTreeClient_OnWindowBoundsChanged_Params_Data))) WindowTreeClient_OnWindowBoundsChanged_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t window;
            uint8_t pad0_[4];
            mojo::internal::Pointer<::gfx::mojom::internal::Rect_Data> old_bounds;
            mojo::internal::Pointer<::gfx::mojom::internal::Rect_Data> new_bounds;

        private:
            WindowTreeClient_OnWindowBoundsChanged_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTreeClient_OnWindowBoundsChanged_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTreeClient_OnWindowBoundsChanged_Params_Data) == 32,
            "Bad sizeof(WindowTreeClient_OnWindowBoundsChanged_Params_Data)");
        constexpr uint32_t kWindowTreeClient_OnClientAreaChanged_Name = 6;
        class WindowTreeClient_OnClientAreaChanged_Params_Data {
        public:
            static WindowTreeClient_OnClientAreaChanged_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTreeClient_OnClientAreaChanged_Params_Data))) WindowTreeClient_OnClientAreaChanged_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t window_id;
            uint8_t pad0_[4];
            mojo::internal::Pointer<::gfx::mojom::internal::Insets_Data> new_client_area;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::gfx::mojom::internal::Rect_Data>>> new_additional_client_areas;

        private:
            WindowTreeClient_OnClientAreaChanged_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTreeClient_OnClientAreaChanged_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTreeClient_OnClientAreaChanged_Params_Data) == 32,
            "Bad sizeof(WindowTreeClient_OnClientAreaChanged_Params_Data)");
        constexpr uint32_t kWindowTreeClient_OnTransientWindowAdded_Name = 7;
        class WindowTreeClient_OnTransientWindowAdded_Params_Data {
        public:
            static WindowTreeClient_OnTransientWindowAdded_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTreeClient_OnTransientWindowAdded_Params_Data))) WindowTreeClient_OnTransientWindowAdded_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t window_id;
            uint32_t transient_window_id;

        private:
            WindowTreeClient_OnTransientWindowAdded_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTreeClient_OnTransientWindowAdded_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTreeClient_OnTransientWindowAdded_Params_Data) == 16,
            "Bad sizeof(WindowTreeClient_OnTransientWindowAdded_Params_Data)");
        constexpr uint32_t kWindowTreeClient_OnTransientWindowRemoved_Name = 8;
        class WindowTreeClient_OnTransientWindowRemoved_Params_Data {
        public:
            static WindowTreeClient_OnTransientWindowRemoved_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTreeClient_OnTransientWindowRemoved_Params_Data))) WindowTreeClient_OnTransientWindowRemoved_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t window_id;
            uint32_t transient_window_id;

        private:
            WindowTreeClient_OnTransientWindowRemoved_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTreeClient_OnTransientWindowRemoved_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTreeClient_OnTransientWindowRemoved_Params_Data) == 16,
            "Bad sizeof(WindowTreeClient_OnTransientWindowRemoved_Params_Data)");
        constexpr uint32_t kWindowTreeClient_OnWindowHierarchyChanged_Name = 9;
        class WindowTreeClient_OnWindowHierarchyChanged_Params_Data {
        public:
            static WindowTreeClient_OnWindowHierarchyChanged_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTreeClient_OnWindowHierarchyChanged_Params_Data))) WindowTreeClient_OnWindowHierarchyChanged_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t window;
            uint32_t old_parent;
            uint32_t new_parent;
            uint8_t pad2_[4];
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::ui::mojom::internal::WindowData_Data>>> windows;

        private:
            WindowTreeClient_OnWindowHierarchyChanged_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTreeClient_OnWindowHierarchyChanged_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTreeClient_OnWindowHierarchyChanged_Params_Data) == 32,
            "Bad sizeof(WindowTreeClient_OnWindowHierarchyChanged_Params_Data)");
        constexpr uint32_t kWindowTreeClient_OnWindowReordered_Name = 10;
        class WindowTreeClient_OnWindowReordered_Params_Data {
        public:
            static WindowTreeClient_OnWindowReordered_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTreeClient_OnWindowReordered_Params_Data))) WindowTreeClient_OnWindowReordered_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t window_id;
            uint32_t relative_window_id;
            int32_t direction;
            uint8_t padfinal_[4];

        private:
            WindowTreeClient_OnWindowReordered_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTreeClient_OnWindowReordered_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTreeClient_OnWindowReordered_Params_Data) == 24,
            "Bad sizeof(WindowTreeClient_OnWindowReordered_Params_Data)");
        constexpr uint32_t kWindowTreeClient_OnWindowDeleted_Name = 11;
        class WindowTreeClient_OnWindowDeleted_Params_Data {
        public:
            static WindowTreeClient_OnWindowDeleted_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTreeClient_OnWindowDeleted_Params_Data))) WindowTreeClient_OnWindowDeleted_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t window;
            uint8_t padfinal_[4];

        private:
            WindowTreeClient_OnWindowDeleted_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTreeClient_OnWindowDeleted_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTreeClient_OnWindowDeleted_Params_Data) == 16,
            "Bad sizeof(WindowTreeClient_OnWindowDeleted_Params_Data)");
        constexpr uint32_t kWindowTreeClient_OnWindowVisibilityChanged_Name = 12;
        class WindowTreeClient_OnWindowVisibilityChanged_Params_Data {
        public:
            static WindowTreeClient_OnWindowVisibilityChanged_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTreeClient_OnWindowVisibilityChanged_Params_Data))) WindowTreeClient_OnWindowVisibilityChanged_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t window;
            uint8_t visible : 1;
            uint8_t padfinal_[3];

        private:
            WindowTreeClient_OnWindowVisibilityChanged_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTreeClient_OnWindowVisibilityChanged_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTreeClient_OnWindowVisibilityChanged_Params_Data) == 16,
            "Bad sizeof(WindowTreeClient_OnWindowVisibilityChanged_Params_Data)");
        constexpr uint32_t kWindowTreeClient_OnWindowOpacityChanged_Name = 13;
        class WindowTreeClient_OnWindowOpacityChanged_Params_Data {
        public:
            static WindowTreeClient_OnWindowOpacityChanged_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTreeClient_OnWindowOpacityChanged_Params_Data))) WindowTreeClient_OnWindowOpacityChanged_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t window;
            float old_opacity;
            float new_opacity;
            uint8_t padfinal_[4];

        private:
            WindowTreeClient_OnWindowOpacityChanged_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTreeClient_OnWindowOpacityChanged_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTreeClient_OnWindowOpacityChanged_Params_Data) == 24,
            "Bad sizeof(WindowTreeClient_OnWindowOpacityChanged_Params_Data)");
        constexpr uint32_t kWindowTreeClient_OnWindowParentDrawnStateChanged_Name = 14;
        class WindowTreeClient_OnWindowParentDrawnStateChanged_Params_Data {
        public:
            static WindowTreeClient_OnWindowParentDrawnStateChanged_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTreeClient_OnWindowParentDrawnStateChanged_Params_Data))) WindowTreeClient_OnWindowParentDrawnStateChanged_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t window;
            uint8_t drawn : 1;
            uint8_t padfinal_[3];

        private:
            WindowTreeClient_OnWindowParentDrawnStateChanged_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTreeClient_OnWindowParentDrawnStateChanged_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTreeClient_OnWindowParentDrawnStateChanged_Params_Data) == 16,
            "Bad sizeof(WindowTreeClient_OnWindowParentDrawnStateChanged_Params_Data)");
        constexpr uint32_t kWindowTreeClient_OnWindowSharedPropertyChanged_Name = 15;
        class WindowTreeClient_OnWindowSharedPropertyChanged_Params_Data {
        public:
            static WindowTreeClient_OnWindowSharedPropertyChanged_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTreeClient_OnWindowSharedPropertyChanged_Params_Data))) WindowTreeClient_OnWindowSharedPropertyChanged_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t window;
            uint8_t pad0_[4];
            mojo::internal::Pointer<mojo::internal::String_Data> name;
            mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>> new_data;

        private:
            WindowTreeClient_OnWindowSharedPropertyChanged_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTreeClient_OnWindowSharedPropertyChanged_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTreeClient_OnWindowSharedPropertyChanged_Params_Data) == 32,
            "Bad sizeof(WindowTreeClient_OnWindowSharedPropertyChanged_Params_Data)");
        constexpr uint32_t kWindowTreeClient_OnWindowInputEvent_Name = 16;
        class WindowTreeClient_OnWindowInputEvent_Params_Data {
        public:
            static WindowTreeClient_OnWindowInputEvent_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTreeClient_OnWindowInputEvent_Params_Data))) WindowTreeClient_OnWindowInputEvent_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t event_id;
            uint32_t window;
            mojo::internal::Pointer<::ui::mojom::internal::Event_Data> event;
            uint8_t matches_pointer_watcher : 1;
            uint8_t padfinal_[7];

        private:
            WindowTreeClient_OnWindowInputEvent_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTreeClient_OnWindowInputEvent_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTreeClient_OnWindowInputEvent_Params_Data) == 32,
            "Bad sizeof(WindowTreeClient_OnWindowInputEvent_Params_Data)");
        constexpr uint32_t kWindowTreeClient_OnPointerEventObserved_Name = 17;
        class WindowTreeClient_OnPointerEventObserved_Params_Data {
        public:
            static WindowTreeClient_OnPointerEventObserved_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTreeClient_OnPointerEventObserved_Params_Data))) WindowTreeClient_OnPointerEventObserved_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::ui::mojom::internal::Event_Data> event;
            uint32_t window_id;
            uint8_t padfinal_[4];

        private:
            WindowTreeClient_OnPointerEventObserved_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTreeClient_OnPointerEventObserved_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTreeClient_OnPointerEventObserved_Params_Data) == 24,
            "Bad sizeof(WindowTreeClient_OnPointerEventObserved_Params_Data)");
        constexpr uint32_t kWindowTreeClient_OnWindowFocused_Name = 18;
        class WindowTreeClient_OnWindowFocused_Params_Data {
        public:
            static WindowTreeClient_OnWindowFocused_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTreeClient_OnWindowFocused_Params_Data))) WindowTreeClient_OnWindowFocused_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t focused_window_id;
            uint8_t padfinal_[4];

        private:
            WindowTreeClient_OnWindowFocused_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTreeClient_OnWindowFocused_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTreeClient_OnWindowFocused_Params_Data) == 16,
            "Bad sizeof(WindowTreeClient_OnWindowFocused_Params_Data)");
        constexpr uint32_t kWindowTreeClient_OnWindowPredefinedCursorChanged_Name = 19;
        class WindowTreeClient_OnWindowPredefinedCursorChanged_Params_Data {
        public:
            static WindowTreeClient_OnWindowPredefinedCursorChanged_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTreeClient_OnWindowPredefinedCursorChanged_Params_Data))) WindowTreeClient_OnWindowPredefinedCursorChanged_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t window_id;
            int32_t cursor_id;

        private:
            WindowTreeClient_OnWindowPredefinedCursorChanged_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTreeClient_OnWindowPredefinedCursorChanged_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTreeClient_OnWindowPredefinedCursorChanged_Params_Data) == 16,
            "Bad sizeof(WindowTreeClient_OnWindowPredefinedCursorChanged_Params_Data)");
        constexpr uint32_t kWindowTreeClient_OnWindowSurfaceChanged_Name = 20;
        class WindowTreeClient_OnWindowSurfaceChanged_Params_Data {
        public:
            static WindowTreeClient_OnWindowSurfaceChanged_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTreeClient_OnWindowSurfaceChanged_Params_Data))) WindowTreeClient_OnWindowSurfaceChanged_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t window_id;
            uint8_t pad0_[4];
            mojo::internal::Pointer<::cc::mojom::internal::SurfaceInfo_Data> surface_info;

        private:
            WindowTreeClient_OnWindowSurfaceChanged_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTreeClient_OnWindowSurfaceChanged_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTreeClient_OnWindowSurfaceChanged_Params_Data) == 24,
            "Bad sizeof(WindowTreeClient_OnWindowSurfaceChanged_Params_Data)");
        constexpr uint32_t kWindowTreeClient_OnDragDropStart_Name = 21;
        class WindowTreeClient_OnDragDropStart_Params_Data {
        public:
            static WindowTreeClient_OnDragDropStart_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTreeClient_OnDragDropStart_Params_Data))) WindowTreeClient_OnDragDropStart_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Map_Data<mojo::internal::Pointer<mojo::internal::String_Data>, mojo::internal::Pointer<mojo::internal::Array_Data<uint8_t>>>> drag_data;

        private:
            WindowTreeClient_OnDragDropStart_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTreeClient_OnDragDropStart_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTreeClient_OnDragDropStart_Params_Data) == 16,
            "Bad sizeof(WindowTreeClient_OnDragDropStart_Params_Data)");
        constexpr uint32_t kWindowTreeClient_OnDragEnter_Name = 22;
        class WindowTreeClient_OnDragEnter_Params_Data {
        public:
            static WindowTreeClient_OnDragEnter_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTreeClient_OnDragEnter_Params_Data))) WindowTreeClient_OnDragEnter_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t window;
            uint32_t key_state;
            mojo::internal::Pointer<::gfx::mojom::internal::Point_Data> screen_position;
            uint32_t effect_bitmask;
            uint8_t padfinal_[4];

        private:
            WindowTreeClient_OnDragEnter_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTreeClient_OnDragEnter_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTreeClient_OnDragEnter_Params_Data) == 32,
            "Bad sizeof(WindowTreeClient_OnDragEnter_Params_Data)");
        class WindowTreeClient_OnDragEnter_ResponseParams_Data {
        public:
            static WindowTreeClient_OnDragEnter_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTreeClient_OnDragEnter_ResponseParams_Data))) WindowTreeClient_OnDragEnter_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t supported_op_bitmask;
            uint8_t padfinal_[4];

        private:
            WindowTreeClient_OnDragEnter_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTreeClient_OnDragEnter_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(WindowTreeClient_OnDragEnter_ResponseParams_Data) == 16,
            "Bad sizeof(WindowTreeClient_OnDragEnter_ResponseParams_Data)");
        constexpr uint32_t kWindowTreeClient_OnDragOver_Name = 23;
        class WindowTreeClient_OnDragOver_Params_Data {
        public:
            static WindowTreeClient_OnDragOver_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTreeClient_OnDragOver_Params_Data))) WindowTreeClient_OnDragOver_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t window;
            uint32_t key_state;
            mojo::internal::Pointer<::gfx::mojom::internal::Point_Data> screen_position;
            uint32_t effect_bitmask;
            uint8_t padfinal_[4];

        private:
            WindowTreeClient_OnDragOver_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTreeClient_OnDragOver_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTreeClient_OnDragOver_Params_Data) == 32,
            "Bad sizeof(WindowTreeClient_OnDragOver_Params_Data)");
        class WindowTreeClient_OnDragOver_ResponseParams_Data {
        public:
            static WindowTreeClient_OnDragOver_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTreeClient_OnDragOver_ResponseParams_Data))) WindowTreeClient_OnDragOver_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t supported_op_bitmask;
            uint8_t padfinal_[4];

        private:
            WindowTreeClient_OnDragOver_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTreeClient_OnDragOver_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(WindowTreeClient_OnDragOver_ResponseParams_Data) == 16,
            "Bad sizeof(WindowTreeClient_OnDragOver_ResponseParams_Data)");
        constexpr uint32_t kWindowTreeClient_OnDragLeave_Name = 24;
        class WindowTreeClient_OnDragLeave_Params_Data {
        public:
            static WindowTreeClient_OnDragLeave_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTreeClient_OnDragLeave_Params_Data))) WindowTreeClient_OnDragLeave_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t window;
            uint8_t padfinal_[4];

        private:
            WindowTreeClient_OnDragLeave_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTreeClient_OnDragLeave_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTreeClient_OnDragLeave_Params_Data) == 16,
            "Bad sizeof(WindowTreeClient_OnDragLeave_Params_Data)");
        constexpr uint32_t kWindowTreeClient_OnCompleteDrop_Name = 25;
        class WindowTreeClient_OnCompleteDrop_Params_Data {
        public:
            static WindowTreeClient_OnCompleteDrop_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTreeClient_OnCompleteDrop_Params_Data))) WindowTreeClient_OnCompleteDrop_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t window;
            uint32_t key_state;
            mojo::internal::Pointer<::gfx::mojom::internal::Point_Data> screen_position;
            uint32_t effect_bitmask;
            uint8_t padfinal_[4];

        private:
            WindowTreeClient_OnCompleteDrop_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTreeClient_OnCompleteDrop_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTreeClient_OnCompleteDrop_Params_Data) == 32,
            "Bad sizeof(WindowTreeClient_OnCompleteDrop_Params_Data)");
        class WindowTreeClient_OnCompleteDrop_ResponseParams_Data {
        public:
            static WindowTreeClient_OnCompleteDrop_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTreeClient_OnCompleteDrop_ResponseParams_Data))) WindowTreeClient_OnCompleteDrop_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t action_taken;
            uint8_t padfinal_[4];

        private:
            WindowTreeClient_OnCompleteDrop_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTreeClient_OnCompleteDrop_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(WindowTreeClient_OnCompleteDrop_ResponseParams_Data) == 16,
            "Bad sizeof(WindowTreeClient_OnCompleteDrop_ResponseParams_Data)");
        constexpr uint32_t kWindowTreeClient_OnPerformDragDropCompleted_Name = 26;
        class WindowTreeClient_OnPerformDragDropCompleted_Params_Data {
        public:
            static WindowTreeClient_OnPerformDragDropCompleted_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTreeClient_OnPerformDragDropCompleted_Params_Data))) WindowTreeClient_OnPerformDragDropCompleted_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t window;
            uint8_t success : 1;
            uint8_t pad1_[3];
            uint32_t action_taken;
            uint8_t padfinal_[4];

        private:
            WindowTreeClient_OnPerformDragDropCompleted_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTreeClient_OnPerformDragDropCompleted_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTreeClient_OnPerformDragDropCompleted_Params_Data) == 24,
            "Bad sizeof(WindowTreeClient_OnPerformDragDropCompleted_Params_Data)");
        constexpr uint32_t kWindowTreeClient_OnDragDropDone_Name = 27;
        class WindowTreeClient_OnDragDropDone_Params_Data {
        public:
            static WindowTreeClient_OnDragDropDone_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTreeClient_OnDragDropDone_Params_Data))) WindowTreeClient_OnDragDropDone_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            WindowTreeClient_OnDragDropDone_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTreeClient_OnDragDropDone_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTreeClient_OnDragDropDone_Params_Data) == 8,
            "Bad sizeof(WindowTreeClient_OnDragDropDone_Params_Data)");
        constexpr uint32_t kWindowTreeClient_OnChangeCompleted_Name = 28;
        class WindowTreeClient_OnChangeCompleted_Params_Data {
        public:
            static WindowTreeClient_OnChangeCompleted_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTreeClient_OnChangeCompleted_Params_Data))) WindowTreeClient_OnChangeCompleted_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t change_id;
            uint8_t success : 1;
            uint8_t padfinal_[3];

        private:
            WindowTreeClient_OnChangeCompleted_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTreeClient_OnChangeCompleted_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTreeClient_OnChangeCompleted_Params_Data) == 16,
            "Bad sizeof(WindowTreeClient_OnChangeCompleted_Params_Data)");
        constexpr uint32_t kWindowTreeClient_RequestClose_Name = 29;
        class WindowTreeClient_RequestClose_Params_Data {
        public:
            static WindowTreeClient_RequestClose_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTreeClient_RequestClose_Params_Data))) WindowTreeClient_RequestClose_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint32_t window_id;
            uint8_t padfinal_[4];

        private:
            WindowTreeClient_RequestClose_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTreeClient_RequestClose_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTreeClient_RequestClose_Params_Data) == 16,
            "Bad sizeof(WindowTreeClient_RequestClose_Params_Data)");
        constexpr uint32_t kWindowTreeClient_GetWindowManager_Name = 30;
        class WindowTreeClient_GetWindowManager_Params_Data {
        public:
            static WindowTreeClient_GetWindowManager_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTreeClient_GetWindowManager_Params_Data))) WindowTreeClient_GetWindowManager_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::AssociatedInterfaceRequest_Data internal;
            uint8_t padfinal_[4];

        private:
            WindowTreeClient_GetWindowManager_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTreeClient_GetWindowManager_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTreeClient_GetWindowManager_Params_Data) == 16,
            "Bad sizeof(WindowTreeClient_GetWindowManager_Params_Data)");
        constexpr uint32_t kWindowTreeFactory_CreateWindowTree_Name = 0;
        class WindowTreeFactory_CreateWindowTree_Params_Data {
        public:
            static WindowTreeFactory_CreateWindowTree_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(WindowTreeFactory_CreateWindowTree_Params_Data))) WindowTreeFactory_CreateWindowTree_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Handle_Data tree_request;
            mojo::internal::Interface_Data client;
            uint8_t padfinal_[4];

        private:
            WindowTreeFactory_CreateWindowTree_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~WindowTreeFactory_CreateWindowTree_Params_Data() = delete;
        };
        static_assert(sizeof(WindowTreeFactory_CreateWindowTree_Params_Data) == 24,
            "Bad sizeof(WindowTreeFactory_CreateWindowTree_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace ui

#endif // SERVICES_UI_PUBLIC_INTERFACES_WINDOW_TREE_MOJOM_SHARED_INTERNAL_H_