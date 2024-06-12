// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_WINDOW_TREE_MOJOM_SHARED_H_
#define SERVICES_UI_PUBLIC_INTERFACES_WINDOW_TREE_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "cc/ipc/mojo_compositor_frame_sink.mojom-shared.h"
#include "cc/ipc/surface_info.mojom-shared.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "services/ui/public/interfaces/cursor.mojom-shared.h"
#include "services/ui/public/interfaces/event_matcher.mojom-shared.h"
#include "services/ui/public/interfaces/mus_constants.mojom-shared.h"
#include "services/ui/public/interfaces/window_manager.mojom-shared.h"
#include "services/ui/public/interfaces/window_manager_constants.mojom-shared.h"
#include "services/ui/public/interfaces/window_tree.mojom-shared-internal.h"
#include "services/ui/public/interfaces/window_tree_constants.mojom-shared.h"
#include "ui/events/mojo/event.mojom-shared.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared.h"
#include "ui/platform_window/mojo/text_input_state.mojom-shared.h"

namespace ui {
namespace mojom {

} // namespace mojom
} // namespace ui

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace ui {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class WindowTreeInterfaceBase {
    };

    using WindowTreePtrDataView = mojo::InterfacePtrDataView<WindowTreeInterfaceBase>;
    using WindowTreeRequestDataView = mojo::InterfaceRequestDataView<WindowTreeInterfaceBase>;
    using WindowTreeAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<WindowTreeInterfaceBase>;
    using WindowTreeAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<WindowTreeInterfaceBase>;
    class WindowTreeClientInterfaceBase {
    };

    using WindowTreeClientPtrDataView = mojo::InterfacePtrDataView<WindowTreeClientInterfaceBase>;
    using WindowTreeClientRequestDataView = mojo::InterfaceRequestDataView<WindowTreeClientInterfaceBase>;
    using WindowTreeClientAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<WindowTreeClientInterfaceBase>;
    using WindowTreeClientAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<WindowTreeClientInterfaceBase>;
    class WindowTreeFactoryInterfaceBase {
    };

    using WindowTreeFactoryPtrDataView = mojo::InterfacePtrDataView<WindowTreeFactoryInterfaceBase>;
    using WindowTreeFactoryRequestDataView = mojo::InterfaceRequestDataView<WindowTreeFactoryInterfaceBase>;
    using WindowTreeFactoryAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<WindowTreeFactoryInterfaceBase>;
    using WindowTreeFactoryAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<WindowTreeFactoryInterfaceBase>;
    class WindowTree_NewWindow_ParamsDataView {
    public:
        WindowTree_NewWindow_ParamsDataView() { }

        WindowTree_NewWindow_ParamsDataView(
            internal::WindowTree_NewWindow_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t change_id() const
        {
            return data_->change_id;
        }
        uint32_t window_id() const
        {
            return data_->window_id;
        }
        inline void GetPropertiesDataView(
            mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadProperties(UserType* output)
        {
            auto* pointer = data_->properties.Get();
            return mojo::internal::Deserialize<mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>>(
                pointer, output, context_);
        }

    private:
        internal::WindowTree_NewWindow_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowTree_NewTopLevelWindow_ParamsDataView {
    public:
        WindowTree_NewTopLevelWindow_ParamsDataView() { }

        WindowTree_NewTopLevelWindow_ParamsDataView(
            internal::WindowTree_NewTopLevelWindow_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t change_id() const
        {
            return data_->change_id;
        }
        uint32_t window_id() const
        {
            return data_->window_id;
        }
        inline void GetPropertiesDataView(
            mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadProperties(UserType* output)
        {
            auto* pointer = data_->properties.Get();
            return mojo::internal::Deserialize<mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>>(
                pointer, output, context_);
        }

    private:
        internal::WindowTree_NewTopLevelWindow_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowTree_DeleteWindow_ParamsDataView {
    public:
        WindowTree_DeleteWindow_ParamsDataView() { }

        WindowTree_DeleteWindow_ParamsDataView(
            internal::WindowTree_DeleteWindow_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t change_id() const
        {
            return data_->change_id;
        }
        uint32_t window_id() const
        {
            return data_->window_id;
        }

    private:
        internal::WindowTree_DeleteWindow_Params_Data* data_ = nullptr;
    };

    class WindowTree_SetCapture_ParamsDataView {
    public:
        WindowTree_SetCapture_ParamsDataView() { }

        WindowTree_SetCapture_ParamsDataView(
            internal::WindowTree_SetCapture_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t change_id() const
        {
            return data_->change_id;
        }
        uint32_t window_id() const
        {
            return data_->window_id;
        }

    private:
        internal::WindowTree_SetCapture_Params_Data* data_ = nullptr;
    };

    class WindowTree_ReleaseCapture_ParamsDataView {
    public:
        WindowTree_ReleaseCapture_ParamsDataView() { }

        WindowTree_ReleaseCapture_ParamsDataView(
            internal::WindowTree_ReleaseCapture_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t change_id() const
        {
            return data_->change_id;
        }
        uint32_t window_id() const
        {
            return data_->window_id;
        }

    private:
        internal::WindowTree_ReleaseCapture_Params_Data* data_ = nullptr;
    };

    class WindowTree_StartPointerWatcher_ParamsDataView {
    public:
        WindowTree_StartPointerWatcher_ParamsDataView() { }

        WindowTree_StartPointerWatcher_ParamsDataView(
            internal::WindowTree_StartPointerWatcher_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool want_moves() const
        {
            return data_->want_moves;
        }

    private:
        internal::WindowTree_StartPointerWatcher_Params_Data* data_ = nullptr;
    };

    class WindowTree_StopPointerWatcher_ParamsDataView {
    public:
        WindowTree_StopPointerWatcher_ParamsDataView() { }

        WindowTree_StopPointerWatcher_ParamsDataView(
            internal::WindowTree_StopPointerWatcher_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::WindowTree_StopPointerWatcher_Params_Data* data_ = nullptr;
    };

    class WindowTree_SetWindowBounds_ParamsDataView {
    public:
        WindowTree_SetWindowBounds_ParamsDataView() { }

        WindowTree_SetWindowBounds_ParamsDataView(
            internal::WindowTree_SetWindowBounds_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t change_id() const
        {
            return data_->change_id;
        }
        uint32_t window_id() const
        {
            return data_->window_id;
        }
        inline void GetBoundsDataView(
            ::gfx::mojom::RectDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadBounds(UserType* output)
        {
            auto* pointer = data_->bounds.Get();
            return mojo::internal::Deserialize<::gfx::mojom::RectDataView>(
                pointer, output, context_);
        }

    private:
        internal::WindowTree_SetWindowBounds_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowTree_SetClientArea_ParamsDataView {
    public:
        WindowTree_SetClientArea_ParamsDataView() { }

        WindowTree_SetClientArea_ParamsDataView(
            internal::WindowTree_SetClientArea_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t window_id() const
        {
            return data_->window_id;
        }
        inline void GetInsetsDataView(
            ::gfx::mojom::InsetsDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadInsets(UserType* output)
        {
            auto* pointer = data_->insets.Get();
            return mojo::internal::Deserialize<::gfx::mojom::InsetsDataView>(
                pointer, output, context_);
        }
        inline void GetAdditionalClientAreasDataView(
            mojo::ArrayDataView<::gfx::mojom::RectDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadAdditionalClientAreas(UserType* output)
        {
            auto* pointer = data_->additional_client_areas.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::gfx::mojom::RectDataView>>(
                pointer, output, context_);
        }

    private:
        internal::WindowTree_SetClientArea_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowTree_SetHitTestMask_ParamsDataView {
    public:
        WindowTree_SetHitTestMask_ParamsDataView() { }

        WindowTree_SetHitTestMask_ParamsDataView(
            internal::WindowTree_SetHitTestMask_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t window_id() const
        {
            return data_->window_id;
        }
        inline void GetMaskDataView(
            ::gfx::mojom::RectDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMask(UserType* output)
        {
            auto* pointer = data_->mask.Get();
            return mojo::internal::Deserialize<::gfx::mojom::RectDataView>(
                pointer, output, context_);
        }

    private:
        internal::WindowTree_SetHitTestMask_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowTree_SetCanAcceptDrops_ParamsDataView {
    public:
        WindowTree_SetCanAcceptDrops_ParamsDataView() { }

        WindowTree_SetCanAcceptDrops_ParamsDataView(
            internal::WindowTree_SetCanAcceptDrops_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t window_id() const
        {
            return data_->window_id;
        }
        bool accepts_drops() const
        {
            return data_->accepts_drops;
        }

    private:
        internal::WindowTree_SetCanAcceptDrops_Params_Data* data_ = nullptr;
    };

    class WindowTree_SetWindowVisibility_ParamsDataView {
    public:
        WindowTree_SetWindowVisibility_ParamsDataView() { }

        WindowTree_SetWindowVisibility_ParamsDataView(
            internal::WindowTree_SetWindowVisibility_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t change_id() const
        {
            return data_->change_id;
        }
        uint32_t window_id() const
        {
            return data_->window_id;
        }
        bool visible() const
        {
            return data_->visible;
        }

    private:
        internal::WindowTree_SetWindowVisibility_Params_Data* data_ = nullptr;
    };

    class WindowTree_SetWindowProperty_ParamsDataView {
    public:
        WindowTree_SetWindowProperty_ParamsDataView() { }

        WindowTree_SetWindowProperty_ParamsDataView(
            internal::WindowTree_SetWindowProperty_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t change_id() const
        {
            return data_->change_id;
        }
        uint32_t window_id() const
        {
            return data_->window_id;
        }
        inline void GetNameDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadName(UserType* output)
        {
            auto* pointer = data_->name.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetValueDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadValue(UserType* output)
        {
            auto* pointer = data_->value.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }

    private:
        internal::WindowTree_SetWindowProperty_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowTree_SetWindowOpacity_ParamsDataView {
    public:
        WindowTree_SetWindowOpacity_ParamsDataView() { }

        WindowTree_SetWindowOpacity_ParamsDataView(
            internal::WindowTree_SetWindowOpacity_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t change_id() const
        {
            return data_->change_id;
        }
        uint32_t window_id() const
        {
            return data_->window_id;
        }
        float opacity() const
        {
            return data_->opacity;
        }

    private:
        internal::WindowTree_SetWindowOpacity_Params_Data* data_ = nullptr;
    };

    class WindowTree_AttachCompositorFrameSink_ParamsDataView {
    public:
        WindowTree_AttachCompositorFrameSink_ParamsDataView() { }

        WindowTree_AttachCompositorFrameSink_ParamsDataView(
            internal::WindowTree_AttachCompositorFrameSink_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t window_id() const
        {
            return data_->window_id;
        }
        template <typename UserType>
        UserType TakeCompositorFrameSink()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::cc::mojom::MojoCompositorFrameSinkRequestDataView>(
                &data_->compositor_frame_sink, &result, context_);
            DCHECK(ret);
            return result;
        }
        template <typename UserType>
        UserType TakeClient()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::cc::mojom::MojoCompositorFrameSinkClientPtrDataView>(
                &data_->client, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::WindowTree_AttachCompositorFrameSink_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowTree_AddWindow_ParamsDataView {
    public:
        WindowTree_AddWindow_ParamsDataView() { }

        WindowTree_AddWindow_ParamsDataView(
            internal::WindowTree_AddWindow_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t change_id() const
        {
            return data_->change_id;
        }
        uint32_t parent() const
        {
            return data_->parent;
        }
        uint32_t child() const
        {
            return data_->child;
        }

    private:
        internal::WindowTree_AddWindow_Params_Data* data_ = nullptr;
    };

    class WindowTree_RemoveWindowFromParent_ParamsDataView {
    public:
        WindowTree_RemoveWindowFromParent_ParamsDataView() { }

        WindowTree_RemoveWindowFromParent_ParamsDataView(
            internal::WindowTree_RemoveWindowFromParent_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t change_id() const
        {
            return data_->change_id;
        }
        uint32_t window_id() const
        {
            return data_->window_id;
        }

    private:
        internal::WindowTree_RemoveWindowFromParent_Params_Data* data_ = nullptr;
    };

    class WindowTree_AddTransientWindow_ParamsDataView {
    public:
        WindowTree_AddTransientWindow_ParamsDataView() { }

        WindowTree_AddTransientWindow_ParamsDataView(
            internal::WindowTree_AddTransientWindow_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t change_id() const
        {
            return data_->change_id;
        }
        uint32_t window_id() const
        {
            return data_->window_id;
        }
        uint32_t transient_window_id() const
        {
            return data_->transient_window_id;
        }

    private:
        internal::WindowTree_AddTransientWindow_Params_Data* data_ = nullptr;
    };

    class WindowTree_RemoveTransientWindowFromParent_ParamsDataView {
    public:
        WindowTree_RemoveTransientWindowFromParent_ParamsDataView() { }

        WindowTree_RemoveTransientWindowFromParent_ParamsDataView(
            internal::WindowTree_RemoveTransientWindowFromParent_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t change_id() const
        {
            return data_->change_id;
        }
        uint32_t transient_window_id() const
        {
            return data_->transient_window_id;
        }

    private:
        internal::WindowTree_RemoveTransientWindowFromParent_Params_Data* data_ = nullptr;
    };

    class WindowTree_SetModal_ParamsDataView {
    public:
        WindowTree_SetModal_ParamsDataView() { }

        WindowTree_SetModal_ParamsDataView(
            internal::WindowTree_SetModal_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t change_id() const
        {
            return data_->change_id;
        }
        uint32_t window_id() const
        {
            return data_->window_id;
        }

    private:
        internal::WindowTree_SetModal_Params_Data* data_ = nullptr;
    };

    class WindowTree_ReorderWindow_ParamsDataView {
    public:
        WindowTree_ReorderWindow_ParamsDataView() { }

        WindowTree_ReorderWindow_ParamsDataView(
            internal::WindowTree_ReorderWindow_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t change_id() const
        {
            return data_->change_id;
        }
        uint32_t window_id() const
        {
            return data_->window_id;
        }
        uint32_t relative_window_id() const
        {
            return data_->relative_window_id;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDirection(UserType* output) const
        {
            auto data_value = data_->direction;
            return mojo::internal::Deserialize<::ui::mojom::OrderDirection>(
                data_value, output);
        }

        ::ui::mojom::OrderDirection direction() const
        {
            return static_cast<::ui::mojom::OrderDirection>(data_->direction);
        }

    private:
        internal::WindowTree_ReorderWindow_Params_Data* data_ = nullptr;
    };

    class WindowTree_GetWindowTree_ParamsDataView {
    public:
        WindowTree_GetWindowTree_ParamsDataView() { }

        WindowTree_GetWindowTree_ParamsDataView(
            internal::WindowTree_GetWindowTree_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t window_id() const
        {
            return data_->window_id;
        }

    private:
        internal::WindowTree_GetWindowTree_Params_Data* data_ = nullptr;
    };

    class WindowTree_GetWindowTree_ResponseParamsDataView {
    public:
        WindowTree_GetWindowTree_ResponseParamsDataView() { }

        WindowTree_GetWindowTree_ResponseParamsDataView(
            internal::WindowTree_GetWindowTree_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetWindowsDataView(
            mojo::ArrayDataView<::ui::mojom::WindowDataDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadWindows(UserType* output)
        {
            auto* pointer = data_->windows.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::ui::mojom::WindowDataDataView>>(
                pointer, output, context_);
        }

    private:
        internal::WindowTree_GetWindowTree_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowTree_Embed_ParamsDataView {
    public:
        WindowTree_Embed_ParamsDataView() { }

        WindowTree_Embed_ParamsDataView(
            internal::WindowTree_Embed_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t window_id() const
        {
            return data_->window_id;
        }
        template <typename UserType>
        UserType TakeClient()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::ui::mojom::WindowTreeClientPtrDataView>(
                &data_->client, &result, context_);
            DCHECK(ret);
            return result;
        }
        uint32_t embed_flags() const
        {
            return data_->embed_flags;
        }

    private:
        internal::WindowTree_Embed_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowTree_Embed_ResponseParamsDataView {
    public:
        WindowTree_Embed_ResponseParamsDataView() { }

        WindowTree_Embed_ResponseParamsDataView(
            internal::WindowTree_Embed_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool success() const
        {
            return data_->success;
        }

    private:
        internal::WindowTree_Embed_ResponseParams_Data* data_ = nullptr;
    };

    class WindowTree_SetFocus_ParamsDataView {
    public:
        WindowTree_SetFocus_ParamsDataView() { }

        WindowTree_SetFocus_ParamsDataView(
            internal::WindowTree_SetFocus_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t change_id() const
        {
            return data_->change_id;
        }
        uint32_t window_id() const
        {
            return data_->window_id;
        }

    private:
        internal::WindowTree_SetFocus_Params_Data* data_ = nullptr;
    };

    class WindowTree_SetCanFocus_ParamsDataView {
    public:
        WindowTree_SetCanFocus_ParamsDataView() { }

        WindowTree_SetCanFocus_ParamsDataView(
            internal::WindowTree_SetCanFocus_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t window_id() const
        {
            return data_->window_id;
        }
        bool can_focus() const
        {
            return data_->can_focus;
        }

    private:
        internal::WindowTree_SetCanFocus_Params_Data* data_ = nullptr;
    };

    class WindowTree_SetPredefinedCursor_ParamsDataView {
    public:
        WindowTree_SetPredefinedCursor_ParamsDataView() { }

        WindowTree_SetPredefinedCursor_ParamsDataView(
            internal::WindowTree_SetPredefinedCursor_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t change_id() const
        {
            return data_->change_id;
        }
        uint32_t window_id() const
        {
            return data_->window_id;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadCursorId(UserType* output) const
        {
            auto data_value = data_->cursor_id;
            return mojo::internal::Deserialize<::ui::mojom::Cursor>(
                data_value, output);
        }

        ::ui::mojom::Cursor cursor_id() const
        {
            return static_cast<::ui::mojom::Cursor>(data_->cursor_id);
        }

    private:
        internal::WindowTree_SetPredefinedCursor_Params_Data* data_ = nullptr;
    };

    class WindowTree_SetWindowTextInputState_ParamsDataView {
    public:
        WindowTree_SetWindowTextInputState_ParamsDataView() { }

        WindowTree_SetWindowTextInputState_ParamsDataView(
            internal::WindowTree_SetWindowTextInputState_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t window_id() const
        {
            return data_->window_id;
        }
        inline void GetStateDataView(
            ::mojo::TextInputStateDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadState(UserType* output)
        {
            auto* pointer = data_->state.Get();
            return mojo::internal::Deserialize<::mojo::TextInputStateDataView>(
                pointer, output, context_);
        }

    private:
        internal::WindowTree_SetWindowTextInputState_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowTree_SetImeVisibility_ParamsDataView {
    public:
        WindowTree_SetImeVisibility_ParamsDataView() { }

        WindowTree_SetImeVisibility_ParamsDataView(
            internal::WindowTree_SetImeVisibility_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t window_id() const
        {
            return data_->window_id;
        }
        bool visible() const
        {
            return data_->visible;
        }
        inline void GetStateDataView(
            ::mojo::TextInputStateDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadState(UserType* output)
        {
            auto* pointer = data_->state.Get();
            return mojo::internal::Deserialize<::mojo::TextInputStateDataView>(
                pointer, output, context_);
        }

    private:
        internal::WindowTree_SetImeVisibility_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowTree_SetCanAcceptEvents_ParamsDataView {
    public:
        WindowTree_SetCanAcceptEvents_ParamsDataView() { }

        WindowTree_SetCanAcceptEvents_ParamsDataView(
            internal::WindowTree_SetCanAcceptEvents_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t window_id() const
        {
            return data_->window_id;
        }
        bool accept_events() const
        {
            return data_->accept_events;
        }

    private:
        internal::WindowTree_SetCanAcceptEvents_Params_Data* data_ = nullptr;
    };

    class WindowTree_OnWindowInputEventAck_ParamsDataView {
    public:
        WindowTree_OnWindowInputEventAck_ParamsDataView() { }

        WindowTree_OnWindowInputEventAck_ParamsDataView(
            internal::WindowTree_OnWindowInputEventAck_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t event_id() const
        {
            return data_->event_id;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadResult(UserType* output) const
        {
            auto data_value = data_->result;
            return mojo::internal::Deserialize<::ui::mojom::EventResult>(
                data_value, output);
        }

        ::ui::mojom::EventResult result() const
        {
            return static_cast<::ui::mojom::EventResult>(data_->result);
        }

    private:
        internal::WindowTree_OnWindowInputEventAck_Params_Data* data_ = nullptr;
    };

    class WindowTree_DeactivateWindow_ParamsDataView {
    public:
        WindowTree_DeactivateWindow_ParamsDataView() { }

        WindowTree_DeactivateWindow_ParamsDataView(
            internal::WindowTree_DeactivateWindow_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t window_id() const
        {
            return data_->window_id;
        }

    private:
        internal::WindowTree_DeactivateWindow_Params_Data* data_ = nullptr;
    };

    class WindowTree_GetWindowManagerClient_ParamsDataView {
    public:
        WindowTree_GetWindowManagerClient_ParamsDataView() { }

        WindowTree_GetWindowManagerClient_ParamsDataView(
            internal::WindowTree_GetWindowManagerClient_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeInternal()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::ui::mojom::WindowManagerClientAssociatedRequestDataView>(
                &data_->internal, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::WindowTree_GetWindowManagerClient_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowTree_GetCursorLocationMemory_ParamsDataView {
    public:
        WindowTree_GetCursorLocationMemory_ParamsDataView() { }

        WindowTree_GetCursorLocationMemory_ParamsDataView(
            internal::WindowTree_GetCursorLocationMemory_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::WindowTree_GetCursorLocationMemory_Params_Data* data_ = nullptr;
    };

    class WindowTree_GetCursorLocationMemory_ResponseParamsDataView {
    public:
        WindowTree_GetCursorLocationMemory_ResponseParamsDataView() { }

        WindowTree_GetCursorLocationMemory_ResponseParamsDataView(
            internal::WindowTree_GetCursorLocationMemory_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        mojo::ScopedSharedBufferHandle TakeCursorBuffer()
        {
            mojo::ScopedSharedBufferHandle result;
            bool ret = mojo::internal::Deserialize<mojo::ScopedSharedBufferHandle>(
                &data_->cursor_buffer, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::WindowTree_GetCursorLocationMemory_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowTree_PerformWindowMove_ParamsDataView {
    public:
        WindowTree_PerformWindowMove_ParamsDataView() { }

        WindowTree_PerformWindowMove_ParamsDataView(
            internal::WindowTree_PerformWindowMove_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t change_id() const
        {
            return data_->change_id;
        }
        uint32_t window_id() const
        {
            return data_->window_id;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSource(UserType* output) const
        {
            auto data_value = data_->source;
            return mojo::internal::Deserialize<::ui::mojom::MoveLoopSource>(
                data_value, output);
        }

        ::ui::mojom::MoveLoopSource source() const
        {
            return static_cast<::ui::mojom::MoveLoopSource>(data_->source);
        }
        inline void GetCursorDataView(
            ::gfx::mojom::PointDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadCursor(UserType* output)
        {
            auto* pointer = data_->cursor.Get();
            return mojo::internal::Deserialize<::gfx::mojom::PointDataView>(
                pointer, output, context_);
        }

    private:
        internal::WindowTree_PerformWindowMove_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowTree_CancelWindowMove_ParamsDataView {
    public:
        WindowTree_CancelWindowMove_ParamsDataView() { }

        WindowTree_CancelWindowMove_ParamsDataView(
            internal::WindowTree_CancelWindowMove_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t window_id() const
        {
            return data_->window_id;
        }

    private:
        internal::WindowTree_CancelWindowMove_Params_Data* data_ = nullptr;
    };

    class WindowTree_PerformDragDrop_ParamsDataView {
    public:
        WindowTree_PerformDragDrop_ParamsDataView() { }

        WindowTree_PerformDragDrop_ParamsDataView(
            internal::WindowTree_PerformDragDrop_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t change_id() const
        {
            return data_->change_id;
        }
        uint32_t source_window_id() const
        {
            return data_->source_window_id;
        }
        inline void GetDragDataDataView(
            mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDragData(UserType* output)
        {
            auto* pointer = data_->drag_data.Get();
            return mojo::internal::Deserialize<mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>>(
                pointer, output, context_);
        }
        uint32_t drag_operation() const
        {
            return data_->drag_operation;
        }

    private:
        internal::WindowTree_PerformDragDrop_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowTree_CancelDragDrop_ParamsDataView {
    public:
        WindowTree_CancelDragDrop_ParamsDataView() { }

        WindowTree_CancelDragDrop_ParamsDataView(
            internal::WindowTree_CancelDragDrop_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t window_id() const
        {
            return data_->window_id;
        }

    private:
        internal::WindowTree_CancelDragDrop_Params_Data* data_ = nullptr;
    };

    class WindowTreeClient_OnEmbed_ParamsDataView {
    public:
        WindowTreeClient_OnEmbed_ParamsDataView() { }

        WindowTreeClient_OnEmbed_ParamsDataView(
            internal::WindowTreeClient_OnEmbed_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint16_t connection_id() const
        {
            return data_->connection_id;
        }
        inline void GetRootDataView(
            ::ui::mojom::WindowDataDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadRoot(UserType* output)
        {
            auto* pointer = data_->root.Get();
            return mojo::internal::Deserialize<::ui::mojom::WindowDataDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        UserType TakeTree()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::ui::mojom::WindowTreePtrDataView>(
                &data_->tree, &result, context_);
            DCHECK(ret);
            return result;
        }
        int64_t display_id() const
        {
            return data_->display_id;
        }
        uint32_t focused_window() const
        {
            return data_->focused_window;
        }
        bool parent_drawn() const
        {
            return data_->parent_drawn;
        }

    private:
        internal::WindowTreeClient_OnEmbed_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowTreeClient_OnEmbeddedAppDisconnected_ParamsDataView {
    public:
        WindowTreeClient_OnEmbeddedAppDisconnected_ParamsDataView() { }

        WindowTreeClient_OnEmbeddedAppDisconnected_ParamsDataView(
            internal::WindowTreeClient_OnEmbeddedAppDisconnected_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t window() const
        {
            return data_->window;
        }

    private:
        internal::WindowTreeClient_OnEmbeddedAppDisconnected_Params_Data* data_ = nullptr;
    };

    class WindowTreeClient_OnUnembed_ParamsDataView {
    public:
        WindowTreeClient_OnUnembed_ParamsDataView() { }

        WindowTreeClient_OnUnembed_ParamsDataView(
            internal::WindowTreeClient_OnUnembed_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t window() const
        {
            return data_->window;
        }

    private:
        internal::WindowTreeClient_OnUnembed_Params_Data* data_ = nullptr;
    };

    class WindowTreeClient_OnCaptureChanged_ParamsDataView {
    public:
        WindowTreeClient_OnCaptureChanged_ParamsDataView() { }

        WindowTreeClient_OnCaptureChanged_ParamsDataView(
            internal::WindowTreeClient_OnCaptureChanged_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t new_capture() const
        {
            return data_->new_capture;
        }
        uint32_t old_capture() const
        {
            return data_->old_capture;
        }

    private:
        internal::WindowTreeClient_OnCaptureChanged_Params_Data* data_ = nullptr;
    };

    class WindowTreeClient_OnTopLevelCreated_ParamsDataView {
    public:
        WindowTreeClient_OnTopLevelCreated_ParamsDataView() { }

        WindowTreeClient_OnTopLevelCreated_ParamsDataView(
            internal::WindowTreeClient_OnTopLevelCreated_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t change_id() const
        {
            return data_->change_id;
        }
        inline void GetDataDataView(
            ::ui::mojom::WindowDataDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadData(UserType* output)
        {
            auto* pointer = data_->data.Get();
            return mojo::internal::Deserialize<::ui::mojom::WindowDataDataView>(
                pointer, output, context_);
        }
        int64_t display_id() const
        {
            return data_->display_id;
        }
        bool parent_drawn() const
        {
            return data_->parent_drawn;
        }

    private:
        internal::WindowTreeClient_OnTopLevelCreated_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowTreeClient_OnWindowBoundsChanged_ParamsDataView {
    public:
        WindowTreeClient_OnWindowBoundsChanged_ParamsDataView() { }

        WindowTreeClient_OnWindowBoundsChanged_ParamsDataView(
            internal::WindowTreeClient_OnWindowBoundsChanged_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t window() const
        {
            return data_->window;
        }
        inline void GetOldBoundsDataView(
            ::gfx::mojom::RectDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOldBounds(UserType* output)
        {
            auto* pointer = data_->old_bounds.Get();
            return mojo::internal::Deserialize<::gfx::mojom::RectDataView>(
                pointer, output, context_);
        }
        inline void GetNewBoundsDataView(
            ::gfx::mojom::RectDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadNewBounds(UserType* output)
        {
            auto* pointer = data_->new_bounds.Get();
            return mojo::internal::Deserialize<::gfx::mojom::RectDataView>(
                pointer, output, context_);
        }

    private:
        internal::WindowTreeClient_OnWindowBoundsChanged_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowTreeClient_OnClientAreaChanged_ParamsDataView {
    public:
        WindowTreeClient_OnClientAreaChanged_ParamsDataView() { }

        WindowTreeClient_OnClientAreaChanged_ParamsDataView(
            internal::WindowTreeClient_OnClientAreaChanged_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t window_id() const
        {
            return data_->window_id;
        }
        inline void GetNewClientAreaDataView(
            ::gfx::mojom::InsetsDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadNewClientArea(UserType* output)
        {
            auto* pointer = data_->new_client_area.Get();
            return mojo::internal::Deserialize<::gfx::mojom::InsetsDataView>(
                pointer, output, context_);
        }
        inline void GetNewAdditionalClientAreasDataView(
            mojo::ArrayDataView<::gfx::mojom::RectDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadNewAdditionalClientAreas(UserType* output)
        {
            auto* pointer = data_->new_additional_client_areas.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::gfx::mojom::RectDataView>>(
                pointer, output, context_);
        }

    private:
        internal::WindowTreeClient_OnClientAreaChanged_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowTreeClient_OnTransientWindowAdded_ParamsDataView {
    public:
        WindowTreeClient_OnTransientWindowAdded_ParamsDataView() { }

        WindowTreeClient_OnTransientWindowAdded_ParamsDataView(
            internal::WindowTreeClient_OnTransientWindowAdded_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t window_id() const
        {
            return data_->window_id;
        }
        uint32_t transient_window_id() const
        {
            return data_->transient_window_id;
        }

    private:
        internal::WindowTreeClient_OnTransientWindowAdded_Params_Data* data_ = nullptr;
    };

    class WindowTreeClient_OnTransientWindowRemoved_ParamsDataView {
    public:
        WindowTreeClient_OnTransientWindowRemoved_ParamsDataView() { }

        WindowTreeClient_OnTransientWindowRemoved_ParamsDataView(
            internal::WindowTreeClient_OnTransientWindowRemoved_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t window_id() const
        {
            return data_->window_id;
        }
        uint32_t transient_window_id() const
        {
            return data_->transient_window_id;
        }

    private:
        internal::WindowTreeClient_OnTransientWindowRemoved_Params_Data* data_ = nullptr;
    };

    class WindowTreeClient_OnWindowHierarchyChanged_ParamsDataView {
    public:
        WindowTreeClient_OnWindowHierarchyChanged_ParamsDataView() { }

        WindowTreeClient_OnWindowHierarchyChanged_ParamsDataView(
            internal::WindowTreeClient_OnWindowHierarchyChanged_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t window() const
        {
            return data_->window;
        }
        uint32_t old_parent() const
        {
            return data_->old_parent;
        }
        uint32_t new_parent() const
        {
            return data_->new_parent;
        }
        inline void GetWindowsDataView(
            mojo::ArrayDataView<::ui::mojom::WindowDataDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadWindows(UserType* output)
        {
            auto* pointer = data_->windows.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::ui::mojom::WindowDataDataView>>(
                pointer, output, context_);
        }

    private:
        internal::WindowTreeClient_OnWindowHierarchyChanged_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowTreeClient_OnWindowReordered_ParamsDataView {
    public:
        WindowTreeClient_OnWindowReordered_ParamsDataView() { }

        WindowTreeClient_OnWindowReordered_ParamsDataView(
            internal::WindowTreeClient_OnWindowReordered_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t window_id() const
        {
            return data_->window_id;
        }
        uint32_t relative_window_id() const
        {
            return data_->relative_window_id;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDirection(UserType* output) const
        {
            auto data_value = data_->direction;
            return mojo::internal::Deserialize<::ui::mojom::OrderDirection>(
                data_value, output);
        }

        ::ui::mojom::OrderDirection direction() const
        {
            return static_cast<::ui::mojom::OrderDirection>(data_->direction);
        }

    private:
        internal::WindowTreeClient_OnWindowReordered_Params_Data* data_ = nullptr;
    };

    class WindowTreeClient_OnWindowDeleted_ParamsDataView {
    public:
        WindowTreeClient_OnWindowDeleted_ParamsDataView() { }

        WindowTreeClient_OnWindowDeleted_ParamsDataView(
            internal::WindowTreeClient_OnWindowDeleted_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t window() const
        {
            return data_->window;
        }

    private:
        internal::WindowTreeClient_OnWindowDeleted_Params_Data* data_ = nullptr;
    };

    class WindowTreeClient_OnWindowVisibilityChanged_ParamsDataView {
    public:
        WindowTreeClient_OnWindowVisibilityChanged_ParamsDataView() { }

        WindowTreeClient_OnWindowVisibilityChanged_ParamsDataView(
            internal::WindowTreeClient_OnWindowVisibilityChanged_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t window() const
        {
            return data_->window;
        }
        bool visible() const
        {
            return data_->visible;
        }

    private:
        internal::WindowTreeClient_OnWindowVisibilityChanged_Params_Data* data_ = nullptr;
    };

    class WindowTreeClient_OnWindowOpacityChanged_ParamsDataView {
    public:
        WindowTreeClient_OnWindowOpacityChanged_ParamsDataView() { }

        WindowTreeClient_OnWindowOpacityChanged_ParamsDataView(
            internal::WindowTreeClient_OnWindowOpacityChanged_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t window() const
        {
            return data_->window;
        }
        float old_opacity() const
        {
            return data_->old_opacity;
        }
        float new_opacity() const
        {
            return data_->new_opacity;
        }

    private:
        internal::WindowTreeClient_OnWindowOpacityChanged_Params_Data* data_ = nullptr;
    };

    class WindowTreeClient_OnWindowParentDrawnStateChanged_ParamsDataView {
    public:
        WindowTreeClient_OnWindowParentDrawnStateChanged_ParamsDataView() { }

        WindowTreeClient_OnWindowParentDrawnStateChanged_ParamsDataView(
            internal::WindowTreeClient_OnWindowParentDrawnStateChanged_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t window() const
        {
            return data_->window;
        }
        bool drawn() const
        {
            return data_->drawn;
        }

    private:
        internal::WindowTreeClient_OnWindowParentDrawnStateChanged_Params_Data* data_ = nullptr;
    };

    class WindowTreeClient_OnWindowSharedPropertyChanged_ParamsDataView {
    public:
        WindowTreeClient_OnWindowSharedPropertyChanged_ParamsDataView() { }

        WindowTreeClient_OnWindowSharedPropertyChanged_ParamsDataView(
            internal::WindowTreeClient_OnWindowSharedPropertyChanged_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t window() const
        {
            return data_->window;
        }
        inline void GetNameDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadName(UserType* output)
        {
            auto* pointer = data_->name.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetNewDataDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadNewData(UserType* output)
        {
            auto* pointer = data_->new_data.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }

    private:
        internal::WindowTreeClient_OnWindowSharedPropertyChanged_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowTreeClient_OnWindowInputEvent_ParamsDataView {
    public:
        WindowTreeClient_OnWindowInputEvent_ParamsDataView() { }

        WindowTreeClient_OnWindowInputEvent_ParamsDataView(
            internal::WindowTreeClient_OnWindowInputEvent_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t event_id() const
        {
            return data_->event_id;
        }
        uint32_t window() const
        {
            return data_->window;
        }
        inline void GetEventDataView(
            ::ui::mojom::EventDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadEvent(UserType* output)
        {
            auto* pointer = data_->event.Get();
            return mojo::internal::Deserialize<::ui::mojom::EventDataView>(
                pointer, output, context_);
        }
        bool matches_pointer_watcher() const
        {
            return data_->matches_pointer_watcher;
        }

    private:
        internal::WindowTreeClient_OnWindowInputEvent_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowTreeClient_OnPointerEventObserved_ParamsDataView {
    public:
        WindowTreeClient_OnPointerEventObserved_ParamsDataView() { }

        WindowTreeClient_OnPointerEventObserved_ParamsDataView(
            internal::WindowTreeClient_OnPointerEventObserved_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetEventDataView(
            ::ui::mojom::EventDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadEvent(UserType* output)
        {
            auto* pointer = data_->event.Get();
            return mojo::internal::Deserialize<::ui::mojom::EventDataView>(
                pointer, output, context_);
        }
        uint32_t window_id() const
        {
            return data_->window_id;
        }

    private:
        internal::WindowTreeClient_OnPointerEventObserved_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowTreeClient_OnWindowFocused_ParamsDataView {
    public:
        WindowTreeClient_OnWindowFocused_ParamsDataView() { }

        WindowTreeClient_OnWindowFocused_ParamsDataView(
            internal::WindowTreeClient_OnWindowFocused_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t focused_window_id() const
        {
            return data_->focused_window_id;
        }

    private:
        internal::WindowTreeClient_OnWindowFocused_Params_Data* data_ = nullptr;
    };

    class WindowTreeClient_OnWindowPredefinedCursorChanged_ParamsDataView {
    public:
        WindowTreeClient_OnWindowPredefinedCursorChanged_ParamsDataView() { }

        WindowTreeClient_OnWindowPredefinedCursorChanged_ParamsDataView(
            internal::WindowTreeClient_OnWindowPredefinedCursorChanged_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t window_id() const
        {
            return data_->window_id;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadCursorId(UserType* output) const
        {
            auto data_value = data_->cursor_id;
            return mojo::internal::Deserialize<::ui::mojom::Cursor>(
                data_value, output);
        }

        ::ui::mojom::Cursor cursor_id() const
        {
            return static_cast<::ui::mojom::Cursor>(data_->cursor_id);
        }

    private:
        internal::WindowTreeClient_OnWindowPredefinedCursorChanged_Params_Data* data_ = nullptr;
    };

    class WindowTreeClient_OnWindowSurfaceChanged_ParamsDataView {
    public:
        WindowTreeClient_OnWindowSurfaceChanged_ParamsDataView() { }

        WindowTreeClient_OnWindowSurfaceChanged_ParamsDataView(
            internal::WindowTreeClient_OnWindowSurfaceChanged_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t window_id() const
        {
            return data_->window_id;
        }
        inline void GetSurfaceInfoDataView(
            ::cc::mojom::SurfaceInfoDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSurfaceInfo(UserType* output)
        {
            auto* pointer = data_->surface_info.Get();
            return mojo::internal::Deserialize<::cc::mojom::SurfaceInfoDataView>(
                pointer, output, context_);
        }

    private:
        internal::WindowTreeClient_OnWindowSurfaceChanged_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowTreeClient_OnDragDropStart_ParamsDataView {
    public:
        WindowTreeClient_OnDragDropStart_ParamsDataView() { }

        WindowTreeClient_OnDragDropStart_ParamsDataView(
            internal::WindowTreeClient_OnDragDropStart_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetDragDataDataView(
            mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDragData(UserType* output)
        {
            auto* pointer = data_->drag_data.Get();
            return mojo::internal::Deserialize<mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>>(
                pointer, output, context_);
        }

    private:
        internal::WindowTreeClient_OnDragDropStart_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowTreeClient_OnDragEnter_ParamsDataView {
    public:
        WindowTreeClient_OnDragEnter_ParamsDataView() { }

        WindowTreeClient_OnDragEnter_ParamsDataView(
            internal::WindowTreeClient_OnDragEnter_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t window() const
        {
            return data_->window;
        }
        uint32_t key_state() const
        {
            return data_->key_state;
        }
        inline void GetScreenPositionDataView(
            ::gfx::mojom::PointDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadScreenPosition(UserType* output)
        {
            auto* pointer = data_->screen_position.Get();
            return mojo::internal::Deserialize<::gfx::mojom::PointDataView>(
                pointer, output, context_);
        }
        uint32_t effect_bitmask() const
        {
            return data_->effect_bitmask;
        }

    private:
        internal::WindowTreeClient_OnDragEnter_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowTreeClient_OnDragEnter_ResponseParamsDataView {
    public:
        WindowTreeClient_OnDragEnter_ResponseParamsDataView() { }

        WindowTreeClient_OnDragEnter_ResponseParamsDataView(
            internal::WindowTreeClient_OnDragEnter_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t supported_op_bitmask() const
        {
            return data_->supported_op_bitmask;
        }

    private:
        internal::WindowTreeClient_OnDragEnter_ResponseParams_Data* data_ = nullptr;
    };

    class WindowTreeClient_OnDragOver_ParamsDataView {
    public:
        WindowTreeClient_OnDragOver_ParamsDataView() { }

        WindowTreeClient_OnDragOver_ParamsDataView(
            internal::WindowTreeClient_OnDragOver_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t window() const
        {
            return data_->window;
        }
        uint32_t key_state() const
        {
            return data_->key_state;
        }
        inline void GetScreenPositionDataView(
            ::gfx::mojom::PointDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadScreenPosition(UserType* output)
        {
            auto* pointer = data_->screen_position.Get();
            return mojo::internal::Deserialize<::gfx::mojom::PointDataView>(
                pointer, output, context_);
        }
        uint32_t effect_bitmask() const
        {
            return data_->effect_bitmask;
        }

    private:
        internal::WindowTreeClient_OnDragOver_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowTreeClient_OnDragOver_ResponseParamsDataView {
    public:
        WindowTreeClient_OnDragOver_ResponseParamsDataView() { }

        WindowTreeClient_OnDragOver_ResponseParamsDataView(
            internal::WindowTreeClient_OnDragOver_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t supported_op_bitmask() const
        {
            return data_->supported_op_bitmask;
        }

    private:
        internal::WindowTreeClient_OnDragOver_ResponseParams_Data* data_ = nullptr;
    };

    class WindowTreeClient_OnDragLeave_ParamsDataView {
    public:
        WindowTreeClient_OnDragLeave_ParamsDataView() { }

        WindowTreeClient_OnDragLeave_ParamsDataView(
            internal::WindowTreeClient_OnDragLeave_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t window() const
        {
            return data_->window;
        }

    private:
        internal::WindowTreeClient_OnDragLeave_Params_Data* data_ = nullptr;
    };

    class WindowTreeClient_OnCompleteDrop_ParamsDataView {
    public:
        WindowTreeClient_OnCompleteDrop_ParamsDataView() { }

        WindowTreeClient_OnCompleteDrop_ParamsDataView(
            internal::WindowTreeClient_OnCompleteDrop_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t window() const
        {
            return data_->window;
        }
        uint32_t key_state() const
        {
            return data_->key_state;
        }
        inline void GetScreenPositionDataView(
            ::gfx::mojom::PointDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadScreenPosition(UserType* output)
        {
            auto* pointer = data_->screen_position.Get();
            return mojo::internal::Deserialize<::gfx::mojom::PointDataView>(
                pointer, output, context_);
        }
        uint32_t effect_bitmask() const
        {
            return data_->effect_bitmask;
        }

    private:
        internal::WindowTreeClient_OnCompleteDrop_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowTreeClient_OnCompleteDrop_ResponseParamsDataView {
    public:
        WindowTreeClient_OnCompleteDrop_ResponseParamsDataView() { }

        WindowTreeClient_OnCompleteDrop_ResponseParamsDataView(
            internal::WindowTreeClient_OnCompleteDrop_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t action_taken() const
        {
            return data_->action_taken;
        }

    private:
        internal::WindowTreeClient_OnCompleteDrop_ResponseParams_Data* data_ = nullptr;
    };

    class WindowTreeClient_OnPerformDragDropCompleted_ParamsDataView {
    public:
        WindowTreeClient_OnPerformDragDropCompleted_ParamsDataView() { }

        WindowTreeClient_OnPerformDragDropCompleted_ParamsDataView(
            internal::WindowTreeClient_OnPerformDragDropCompleted_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t window() const
        {
            return data_->window;
        }
        bool success() const
        {
            return data_->success;
        }
        uint32_t action_taken() const
        {
            return data_->action_taken;
        }

    private:
        internal::WindowTreeClient_OnPerformDragDropCompleted_Params_Data* data_ = nullptr;
    };

    class WindowTreeClient_OnDragDropDone_ParamsDataView {
    public:
        WindowTreeClient_OnDragDropDone_ParamsDataView() { }

        WindowTreeClient_OnDragDropDone_ParamsDataView(
            internal::WindowTreeClient_OnDragDropDone_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::WindowTreeClient_OnDragDropDone_Params_Data* data_ = nullptr;
    };

    class WindowTreeClient_OnChangeCompleted_ParamsDataView {
    public:
        WindowTreeClient_OnChangeCompleted_ParamsDataView() { }

        WindowTreeClient_OnChangeCompleted_ParamsDataView(
            internal::WindowTreeClient_OnChangeCompleted_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t change_id() const
        {
            return data_->change_id;
        }
        bool success() const
        {
            return data_->success;
        }

    private:
        internal::WindowTreeClient_OnChangeCompleted_Params_Data* data_ = nullptr;
    };

    class WindowTreeClient_RequestClose_ParamsDataView {
    public:
        WindowTreeClient_RequestClose_ParamsDataView() { }

        WindowTreeClient_RequestClose_ParamsDataView(
            internal::WindowTreeClient_RequestClose_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t window_id() const
        {
            return data_->window_id;
        }

    private:
        internal::WindowTreeClient_RequestClose_Params_Data* data_ = nullptr;
    };

    class WindowTreeClient_GetWindowManager_ParamsDataView {
    public:
        WindowTreeClient_GetWindowManager_ParamsDataView() { }

        WindowTreeClient_GetWindowManager_ParamsDataView(
            internal::WindowTreeClient_GetWindowManager_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeInternal()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::ui::mojom::WindowManagerAssociatedRequestDataView>(
                &data_->internal, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::WindowTreeClient_GetWindowManager_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowTreeFactory_CreateWindowTree_ParamsDataView {
    public:
        WindowTreeFactory_CreateWindowTree_ParamsDataView() { }

        WindowTreeFactory_CreateWindowTree_ParamsDataView(
            internal::WindowTreeFactory_CreateWindowTree_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeTreeRequest()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::ui::mojom::WindowTreeRequestDataView>(
                &data_->tree_request, &result, context_);
            DCHECK(ret);
            return result;
        }
        template <typename UserType>
        UserType TakeClient()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::ui::mojom::WindowTreeClientPtrDataView>(
                &data_->client, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::WindowTreeFactory_CreateWindowTree_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace ui

namespace std {

} // namespace std

namespace mojo {

} // namespace mojo

namespace ui {
namespace mojom {

    inline void WindowTree_NewWindow_ParamsDataView::GetPropertiesDataView(
        mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>* output)
    {
        auto pointer = data_->properties.Get();
        *output = mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>(pointer, context_);
    }

    inline void WindowTree_NewTopLevelWindow_ParamsDataView::GetPropertiesDataView(
        mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>* output)
    {
        auto pointer = data_->properties.Get();
        *output = mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>(pointer, context_);
    }

    inline void WindowTree_SetWindowBounds_ParamsDataView::GetBoundsDataView(
        ::gfx::mojom::RectDataView* output)
    {
        auto pointer = data_->bounds.Get();
        *output = ::gfx::mojom::RectDataView(pointer, context_);
    }

    inline void WindowTree_SetClientArea_ParamsDataView::GetInsetsDataView(
        ::gfx::mojom::InsetsDataView* output)
    {
        auto pointer = data_->insets.Get();
        *output = ::gfx::mojom::InsetsDataView(pointer, context_);
    }
    inline void WindowTree_SetClientArea_ParamsDataView::GetAdditionalClientAreasDataView(
        mojo::ArrayDataView<::gfx::mojom::RectDataView>* output)
    {
        auto pointer = data_->additional_client_areas.Get();
        *output = mojo::ArrayDataView<::gfx::mojom::RectDataView>(pointer, context_);
    }

    inline void WindowTree_SetHitTestMask_ParamsDataView::GetMaskDataView(
        ::gfx::mojom::RectDataView* output)
    {
        auto pointer = data_->mask.Get();
        *output = ::gfx::mojom::RectDataView(pointer, context_);
    }

    inline void WindowTree_SetWindowProperty_ParamsDataView::GetNameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->name.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void WindowTree_SetWindowProperty_ParamsDataView::GetValueDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->value.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

    inline void WindowTree_GetWindowTree_ResponseParamsDataView::GetWindowsDataView(
        mojo::ArrayDataView<::ui::mojom::WindowDataDataView>* output)
    {
        auto pointer = data_->windows.Get();
        *output = mojo::ArrayDataView<::ui::mojom::WindowDataDataView>(pointer, context_);
    }

    inline void WindowTree_SetWindowTextInputState_ParamsDataView::GetStateDataView(
        ::mojo::TextInputStateDataView* output)
    {
        auto pointer = data_->state.Get();
        *output = ::mojo::TextInputStateDataView(pointer, context_);
    }

    inline void WindowTree_SetImeVisibility_ParamsDataView::GetStateDataView(
        ::mojo::TextInputStateDataView* output)
    {
        auto pointer = data_->state.Get();
        *output = ::mojo::TextInputStateDataView(pointer, context_);
    }

    inline void WindowTree_PerformWindowMove_ParamsDataView::GetCursorDataView(
        ::gfx::mojom::PointDataView* output)
    {
        auto pointer = data_->cursor.Get();
        *output = ::gfx::mojom::PointDataView(pointer, context_);
    }

    inline void WindowTree_PerformDragDrop_ParamsDataView::GetDragDataDataView(
        mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>* output)
    {
        auto pointer = data_->drag_data.Get();
        *output = mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>(pointer, context_);
    }

    inline void WindowTreeClient_OnEmbed_ParamsDataView::GetRootDataView(
        ::ui::mojom::WindowDataDataView* output)
    {
        auto pointer = data_->root.Get();
        *output = ::ui::mojom::WindowDataDataView(pointer, context_);
    }

    inline void WindowTreeClient_OnTopLevelCreated_ParamsDataView::GetDataDataView(
        ::ui::mojom::WindowDataDataView* output)
    {
        auto pointer = data_->data.Get();
        *output = ::ui::mojom::WindowDataDataView(pointer, context_);
    }

    inline void WindowTreeClient_OnWindowBoundsChanged_ParamsDataView::GetOldBoundsDataView(
        ::gfx::mojom::RectDataView* output)
    {
        auto pointer = data_->old_bounds.Get();
        *output = ::gfx::mojom::RectDataView(pointer, context_);
    }
    inline void WindowTreeClient_OnWindowBoundsChanged_ParamsDataView::GetNewBoundsDataView(
        ::gfx::mojom::RectDataView* output)
    {
        auto pointer = data_->new_bounds.Get();
        *output = ::gfx::mojom::RectDataView(pointer, context_);
    }

    inline void WindowTreeClient_OnClientAreaChanged_ParamsDataView::GetNewClientAreaDataView(
        ::gfx::mojom::InsetsDataView* output)
    {
        auto pointer = data_->new_client_area.Get();
        *output = ::gfx::mojom::InsetsDataView(pointer, context_);
    }
    inline void WindowTreeClient_OnClientAreaChanged_ParamsDataView::GetNewAdditionalClientAreasDataView(
        mojo::ArrayDataView<::gfx::mojom::RectDataView>* output)
    {
        auto pointer = data_->new_additional_client_areas.Get();
        *output = mojo::ArrayDataView<::gfx::mojom::RectDataView>(pointer, context_);
    }

    inline void WindowTreeClient_OnWindowHierarchyChanged_ParamsDataView::GetWindowsDataView(
        mojo::ArrayDataView<::ui::mojom::WindowDataDataView>* output)
    {
        auto pointer = data_->windows.Get();
        *output = mojo::ArrayDataView<::ui::mojom::WindowDataDataView>(pointer, context_);
    }

    inline void WindowTreeClient_OnWindowSharedPropertyChanged_ParamsDataView::GetNameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->name.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void WindowTreeClient_OnWindowSharedPropertyChanged_ParamsDataView::GetNewDataDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->new_data.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

    inline void WindowTreeClient_OnWindowInputEvent_ParamsDataView::GetEventDataView(
        ::ui::mojom::EventDataView* output)
    {
        auto pointer = data_->event.Get();
        *output = ::ui::mojom::EventDataView(pointer, context_);
    }

    inline void WindowTreeClient_OnPointerEventObserved_ParamsDataView::GetEventDataView(
        ::ui::mojom::EventDataView* output)
    {
        auto pointer = data_->event.Get();
        *output = ::ui::mojom::EventDataView(pointer, context_);
    }

    inline void WindowTreeClient_OnWindowSurfaceChanged_ParamsDataView::GetSurfaceInfoDataView(
        ::cc::mojom::SurfaceInfoDataView* output)
    {
        auto pointer = data_->surface_info.Get();
        *output = ::cc::mojom::SurfaceInfoDataView(pointer, context_);
    }

    inline void WindowTreeClient_OnDragDropStart_ParamsDataView::GetDragDataDataView(
        mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>* output)
    {
        auto pointer = data_->drag_data.Get();
        *output = mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>(pointer, context_);
    }

    inline void WindowTreeClient_OnDragEnter_ParamsDataView::GetScreenPositionDataView(
        ::gfx::mojom::PointDataView* output)
    {
        auto pointer = data_->screen_position.Get();
        *output = ::gfx::mojom::PointDataView(pointer, context_);
    }

    inline void WindowTreeClient_OnDragOver_ParamsDataView::GetScreenPositionDataView(
        ::gfx::mojom::PointDataView* output)
    {
        auto pointer = data_->screen_position.Get();
        *output = ::gfx::mojom::PointDataView(pointer, context_);
    }

    inline void WindowTreeClient_OnCompleteDrop_ParamsDataView::GetScreenPositionDataView(
        ::gfx::mojom::PointDataView* output)
    {
        auto pointer = data_->screen_position.Get();
        *output = ::gfx::mojom::PointDataView(pointer, context_);
    }

} // namespace mojom
} // namespace ui

#endif // SERVICES_UI_PUBLIC_INTERFACES_WINDOW_TREE_MOJOM_SHARED_H_
