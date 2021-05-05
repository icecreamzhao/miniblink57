// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_WINDOW_MANAGER_MOJOM_SHARED_H_
#define SERVICES_UI_PUBLIC_INTERFACES_WINDOW_MANAGER_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
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
#include "services/ui/public/interfaces/display/display.mojom-shared.h"
#include "services/ui/public/interfaces/event_matcher.mojom-shared.h"
#include "services/ui/public/interfaces/window_manager.mojom-shared-internal.h"
#include "services/ui/public/interfaces/window_manager_constants.mojom-shared.h"
#include "services/ui/public/interfaces/window_tree_constants.mojom-shared.h"
#include "ui/events/mojo/event.mojom-shared.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared.h"

namespace ui {
namespace mojom {
    class AcceleratorDataView;

} // namespace mojom
} // namespace ui

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::ui::mojom::AcceleratorDataView> {
        using Data = ::ui::mojom::internal::Accelerator_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace ui {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class WindowManagerInterfaceBase {
    };

    using WindowManagerPtrDataView = mojo::InterfacePtrDataView<WindowManagerInterfaceBase>;
    using WindowManagerRequestDataView = mojo::InterfaceRequestDataView<WindowManagerInterfaceBase>;
    using WindowManagerAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<WindowManagerInterfaceBase>;
    using WindowManagerAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<WindowManagerInterfaceBase>;
    class WindowManagerClientInterfaceBase {
    };

    using WindowManagerClientPtrDataView = mojo::InterfacePtrDataView<WindowManagerClientInterfaceBase>;
    using WindowManagerClientRequestDataView = mojo::InterfaceRequestDataView<WindowManagerClientInterfaceBase>;
    using WindowManagerClientAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<WindowManagerClientInterfaceBase>;
    using WindowManagerClientAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<WindowManagerClientInterfaceBase>;
    class AcceleratorDataView {
    public:
        AcceleratorDataView() { }

        AcceleratorDataView(
            internal::Accelerator_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t id() const
        {
            return data_->id;
        }
        inline void GetEventMatcherDataView(
            ::ui::mojom::EventMatcherDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadEventMatcher(UserType* output)
        {
            auto* pointer = data_->event_matcher.Get();
            return mojo::internal::Deserialize<::ui::mojom::EventMatcherDataView>(
                pointer, output, context_);
        }

    private:
        internal::Accelerator_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowManager_OnConnect_ParamsDataView {
    public:
        WindowManager_OnConnect_ParamsDataView() { }

        WindowManager_OnConnect_ParamsDataView(
            internal::WindowManager_OnConnect_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint16_t client_id() const
        {
            return data_->client_id;
        }

    private:
        internal::WindowManager_OnConnect_Params_Data* data_ = nullptr;
    };

    class WindowManager_WmNewDisplayAdded_ParamsDataView {
    public:
        WindowManager_WmNewDisplayAdded_ParamsDataView() { }

        WindowManager_WmNewDisplayAdded_ParamsDataView(
            internal::WindowManager_WmNewDisplayAdded_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetDisplayDataView(
            ::display::mojom::DisplayDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDisplay(UserType* output)
        {
            auto* pointer = data_->display.Get();
            return mojo::internal::Deserialize<::display::mojom::DisplayDataView>(
                pointer, output, context_);
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
        bool parent_drawn() const
        {
            return data_->parent_drawn;
        }

    private:
        internal::WindowManager_WmNewDisplayAdded_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowManager_WmDisplayRemoved_ParamsDataView {
    public:
        WindowManager_WmDisplayRemoved_ParamsDataView() { }

        WindowManager_WmDisplayRemoved_ParamsDataView(
            internal::WindowManager_WmDisplayRemoved_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int64_t display_id() const
        {
            return data_->display_id;
        }

    private:
        internal::WindowManager_WmDisplayRemoved_Params_Data* data_ = nullptr;
    };

    class WindowManager_WmDisplayModified_ParamsDataView {
    public:
        WindowManager_WmDisplayModified_ParamsDataView() { }

        WindowManager_WmDisplayModified_ParamsDataView(
            internal::WindowManager_WmDisplayModified_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetDisplayDataView(
            ::display::mojom::DisplayDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDisplay(UserType* output)
        {
            auto* pointer = data_->display.Get();
            return mojo::internal::Deserialize<::display::mojom::DisplayDataView>(
                pointer, output, context_);
        }

    private:
        internal::WindowManager_WmDisplayModified_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowManager_WmSetBounds_ParamsDataView {
    public:
        WindowManager_WmSetBounds_ParamsDataView() { }

        WindowManager_WmSetBounds_ParamsDataView(
            internal::WindowManager_WmSetBounds_Params_Data* data,
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
        internal::WindowManager_WmSetBounds_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowManager_WmSetProperty_ParamsDataView {
    public:
        WindowManager_WmSetProperty_ParamsDataView() { }

        WindowManager_WmSetProperty_ParamsDataView(
            internal::WindowManager_WmSetProperty_Params_Data* data,
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
        internal::WindowManager_WmSetProperty_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowManager_WmCreateTopLevelWindow_ParamsDataView {
    public:
        WindowManager_WmCreateTopLevelWindow_ParamsDataView() { }

        WindowManager_WmCreateTopLevelWindow_ParamsDataView(
            internal::WindowManager_WmCreateTopLevelWindow_Params_Data* data,
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
        uint16_t requesting_client_id() const
        {
            return data_->requesting_client_id;
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
        internal::WindowManager_WmCreateTopLevelWindow_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowManager_WmClientJankinessChanged_ParamsDataView {
    public:
        WindowManager_WmClientJankinessChanged_ParamsDataView() { }

        WindowManager_WmClientJankinessChanged_ParamsDataView(
            internal::WindowManager_WmClientJankinessChanged_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint16_t client_id() const
        {
            return data_->client_id;
        }
        bool janky() const
        {
            return data_->janky;
        }

    private:
        internal::WindowManager_WmClientJankinessChanged_Params_Data* data_ = nullptr;
    };

    class WindowManager_WmPerformMoveLoop_ParamsDataView {
    public:
        WindowManager_WmPerformMoveLoop_ParamsDataView() { }

        WindowManager_WmPerformMoveLoop_ParamsDataView(
            internal::WindowManager_WmPerformMoveLoop_Params_Data* data,
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
        inline void GetCursorLocationDataView(
            ::gfx::mojom::PointDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadCursorLocation(UserType* output)
        {
            auto* pointer = data_->cursor_location.Get();
            return mojo::internal::Deserialize<::gfx::mojom::PointDataView>(
                pointer, output, context_);
        }

    private:
        internal::WindowManager_WmPerformMoveLoop_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowManager_WmCancelMoveLoop_ParamsDataView {
    public:
        WindowManager_WmCancelMoveLoop_ParamsDataView() { }

        WindowManager_WmCancelMoveLoop_ParamsDataView(
            internal::WindowManager_WmCancelMoveLoop_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t change_id() const
        {
            return data_->change_id;
        }

    private:
        internal::WindowManager_WmCancelMoveLoop_Params_Data* data_ = nullptr;
    };

    class WindowManager_WmDeactivateWindow_ParamsDataView {
    public:
        WindowManager_WmDeactivateWindow_ParamsDataView() { }

        WindowManager_WmDeactivateWindow_ParamsDataView(
            internal::WindowManager_WmDeactivateWindow_Params_Data* data,
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
        internal::WindowManager_WmDeactivateWindow_Params_Data* data_ = nullptr;
    };

    class WindowManager_OnAccelerator_ParamsDataView {
    public:
        WindowManager_OnAccelerator_ParamsDataView() { }

        WindowManager_OnAccelerator_ParamsDataView(
            internal::WindowManager_OnAccelerator_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t ack_id() const
        {
            return data_->ack_id;
        }
        uint32_t accelerator_id() const
        {
            return data_->accelerator_id;
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

    private:
        internal::WindowManager_OnAccelerator_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowManagerClient_AddActivationParent_ParamsDataView {
    public:
        WindowManagerClient_AddActivationParent_ParamsDataView() { }

        WindowManagerClient_AddActivationParent_ParamsDataView(
            internal::WindowManagerClient_AddActivationParent_Params_Data* data,
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
        internal::WindowManagerClient_AddActivationParent_Params_Data* data_ = nullptr;
    };

    class WindowManagerClient_RemoveActivationParent_ParamsDataView {
    public:
        WindowManagerClient_RemoveActivationParent_ParamsDataView() { }

        WindowManagerClient_RemoveActivationParent_ParamsDataView(
            internal::WindowManagerClient_RemoveActivationParent_Params_Data* data,
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
        internal::WindowManagerClient_RemoveActivationParent_Params_Data* data_ = nullptr;
    };

    class WindowManagerClient_ActivateNextWindow_ParamsDataView {
    public:
        WindowManagerClient_ActivateNextWindow_ParamsDataView() { }

        WindowManagerClient_ActivateNextWindow_ParamsDataView(
            internal::WindowManagerClient_ActivateNextWindow_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::WindowManagerClient_ActivateNextWindow_Params_Data* data_ = nullptr;
    };

    class WindowManagerClient_SetUnderlaySurfaceOffsetAndExtendedHitArea_ParamsDataView {
    public:
        WindowManagerClient_SetUnderlaySurfaceOffsetAndExtendedHitArea_ParamsDataView() { }

        WindowManagerClient_SetUnderlaySurfaceOffsetAndExtendedHitArea_ParamsDataView(
            internal::WindowManagerClient_SetUnderlaySurfaceOffsetAndExtendedHitArea_Params_Data* data,
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
        int32_t x_offset() const
        {
            return data_->x_offset;
        }
        int32_t y_offset() const
        {
            return data_->y_offset;
        }
        inline void GetHitAreaDataView(
            ::gfx::mojom::InsetsDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadHitArea(UserType* output)
        {
            auto* pointer = data_->hit_area.Get();
            return mojo::internal::Deserialize<::gfx::mojom::InsetsDataView>(
                pointer, output, context_);
        }

    private:
        internal::WindowManagerClient_SetUnderlaySurfaceOffsetAndExtendedHitArea_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowManagerClient_AddAccelerators_ParamsDataView {
    public:
        WindowManagerClient_AddAccelerators_ParamsDataView() { }

        WindowManagerClient_AddAccelerators_ParamsDataView(
            internal::WindowManagerClient_AddAccelerators_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetAcceleratorsDataView(
            mojo::ArrayDataView<AcceleratorDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadAccelerators(UserType* output)
        {
            auto* pointer = data_->accelerators.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::ui::mojom::AcceleratorDataView>>(
                pointer, output, context_);
        }

    private:
        internal::WindowManagerClient_AddAccelerators_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowManagerClient_AddAccelerators_ResponseParamsDataView {
    public:
        WindowManagerClient_AddAccelerators_ResponseParamsDataView() { }

        WindowManagerClient_AddAccelerators_ResponseParamsDataView(
            internal::WindowManagerClient_AddAccelerators_ResponseParams_Data* data,
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
        internal::WindowManagerClient_AddAccelerators_ResponseParams_Data* data_ = nullptr;
    };

    class WindowManagerClient_RemoveAccelerator_ParamsDataView {
    public:
        WindowManagerClient_RemoveAccelerator_ParamsDataView() { }

        WindowManagerClient_RemoveAccelerator_ParamsDataView(
            internal::WindowManagerClient_RemoveAccelerator_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t id() const
        {
            return data_->id;
        }

    private:
        internal::WindowManagerClient_RemoveAccelerator_Params_Data* data_ = nullptr;
    };

    class WindowManagerClient_WmResponse_ParamsDataView {
    public:
        WindowManagerClient_WmResponse_ParamsDataView() { }

        WindowManagerClient_WmResponse_ParamsDataView(
            internal::WindowManagerClient_WmResponse_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t change_id() const
        {
            return data_->change_id;
        }
        bool response() const
        {
            return data_->response;
        }

    private:
        internal::WindowManagerClient_WmResponse_Params_Data* data_ = nullptr;
    };

    class WindowManagerClient_WmRequestClose_ParamsDataView {
    public:
        WindowManagerClient_WmRequestClose_ParamsDataView() { }

        WindowManagerClient_WmRequestClose_ParamsDataView(
            internal::WindowManagerClient_WmRequestClose_Params_Data* data,
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
        internal::WindowManagerClient_WmRequestClose_Params_Data* data_ = nullptr;
    };

    class WindowManagerClient_WmSetFrameDecorationValues_ParamsDataView {
    public:
        WindowManagerClient_WmSetFrameDecorationValues_ParamsDataView() { }

        WindowManagerClient_WmSetFrameDecorationValues_ParamsDataView(
            internal::WindowManagerClient_WmSetFrameDecorationValues_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetValuesDataView(
            ::ui::mojom::FrameDecorationValuesDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadValues(UserType* output)
        {
            auto* pointer = data_->values.Get();
            return mojo::internal::Deserialize<::ui::mojom::FrameDecorationValuesDataView>(
                pointer, output, context_);
        }

    private:
        internal::WindowManagerClient_WmSetFrameDecorationValues_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowManagerClient_WmSetNonClientCursor_ParamsDataView {
    public:
        WindowManagerClient_WmSetNonClientCursor_ParamsDataView() { }

        WindowManagerClient_WmSetNonClientCursor_ParamsDataView(
            internal::WindowManagerClient_WmSetNonClientCursor_Params_Data* data,
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
        internal::WindowManagerClient_WmSetNonClientCursor_Params_Data* data_ = nullptr;
    };

    class WindowManagerClient_OnWmCreatedTopLevelWindow_ParamsDataView {
    public:
        WindowManagerClient_OnWmCreatedTopLevelWindow_ParamsDataView() { }

        WindowManagerClient_OnWmCreatedTopLevelWindow_ParamsDataView(
            internal::WindowManagerClient_OnWmCreatedTopLevelWindow_Params_Data* data,
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
        internal::WindowManagerClient_OnWmCreatedTopLevelWindow_Params_Data* data_ = nullptr;
    };

    class WindowManagerClient_OnAcceleratorAck_ParamsDataView {
    public:
        WindowManagerClient_OnAcceleratorAck_ParamsDataView() { }

        WindowManagerClient_OnAcceleratorAck_ParamsDataView(
            internal::WindowManagerClient_OnAcceleratorAck_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t ack_id() const
        {
            return data_->ack_id;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadEventResult(UserType* output) const
        {
            auto data_value = data_->event_result;
            return mojo::internal::Deserialize<::ui::mojom::EventResult>(
                data_value, output);
        }

        ::ui::mojom::EventResult event_result() const
        {
            return static_cast<::ui::mojom::EventResult>(data_->event_result);
        }

    private:
        internal::WindowManagerClient_OnAcceleratorAck_Params_Data* data_ = nullptr;
    };

} // namespace mojom
} // namespace ui

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::ui::mojom::AcceleratorDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::ui::mojom::AcceleratorDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::ui::mojom::internal::Accelerator_Data);
            decltype(CallWithContext(Traits::event_matcher, input, custom_context)) in_event_matcher = CallWithContext(Traits::event_matcher, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::ui::mojom::EventMatcherDataView>(
                in_event_matcher, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::ui::mojom::internal::Accelerator_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::ui::mojom::internal::Accelerator_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->id = CallWithContext(Traits::id, input, custom_context);
            decltype(CallWithContext(Traits::event_matcher, input, custom_context)) in_event_matcher = CallWithContext(Traits::event_matcher, input, custom_context);
            typename decltype(result->event_matcher)::BaseType* event_matcher_ptr;
            mojo::internal::Serialize<::ui::mojom::EventMatcherDataView>(
                in_event_matcher, buffer, &event_matcher_ptr, context);
            result->event_matcher.Set(event_matcher_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->event_matcher.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null event_matcher in Accelerator struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::ui::mojom::internal::Accelerator_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::ui::mojom::AcceleratorDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace ui {
namespace mojom {

    inline void AcceleratorDataView::GetEventMatcherDataView(
        ::ui::mojom::EventMatcherDataView* output)
    {
        auto pointer = data_->event_matcher.Get();
        *output = ::ui::mojom::EventMatcherDataView(pointer, context_);
    }

    inline void WindowManager_WmNewDisplayAdded_ParamsDataView::GetDisplayDataView(
        ::display::mojom::DisplayDataView* output)
    {
        auto pointer = data_->display.Get();
        *output = ::display::mojom::DisplayDataView(pointer, context_);
    }
    inline void WindowManager_WmNewDisplayAdded_ParamsDataView::GetRootDataView(
        ::ui::mojom::WindowDataDataView* output)
    {
        auto pointer = data_->root.Get();
        *output = ::ui::mojom::WindowDataDataView(pointer, context_);
    }

    inline void WindowManager_WmDisplayModified_ParamsDataView::GetDisplayDataView(
        ::display::mojom::DisplayDataView* output)
    {
        auto pointer = data_->display.Get();
        *output = ::display::mojom::DisplayDataView(pointer, context_);
    }

    inline void WindowManager_WmSetBounds_ParamsDataView::GetBoundsDataView(
        ::gfx::mojom::RectDataView* output)
    {
        auto pointer = data_->bounds.Get();
        *output = ::gfx::mojom::RectDataView(pointer, context_);
    }

    inline void WindowManager_WmSetProperty_ParamsDataView::GetNameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->name.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void WindowManager_WmSetProperty_ParamsDataView::GetValueDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->value.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

    inline void WindowManager_WmCreateTopLevelWindow_ParamsDataView::GetPropertiesDataView(
        mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>* output)
    {
        auto pointer = data_->properties.Get();
        *output = mojo::MapDataView<mojo::StringDataView, mojo::ArrayDataView<uint8_t>>(pointer, context_);
    }

    inline void WindowManager_WmPerformMoveLoop_ParamsDataView::GetCursorLocationDataView(
        ::gfx::mojom::PointDataView* output)
    {
        auto pointer = data_->cursor_location.Get();
        *output = ::gfx::mojom::PointDataView(pointer, context_);
    }

    inline void WindowManager_OnAccelerator_ParamsDataView::GetEventDataView(
        ::ui::mojom::EventDataView* output)
    {
        auto pointer = data_->event.Get();
        *output = ::ui::mojom::EventDataView(pointer, context_);
    }

    inline void WindowManagerClient_SetUnderlaySurfaceOffsetAndExtendedHitArea_ParamsDataView::GetHitAreaDataView(
        ::gfx::mojom::InsetsDataView* output)
    {
        auto pointer = data_->hit_area.Get();
        *output = ::gfx::mojom::InsetsDataView(pointer, context_);
    }

    inline void WindowManagerClient_AddAccelerators_ParamsDataView::GetAcceleratorsDataView(
        mojo::ArrayDataView<AcceleratorDataView>* output)
    {
        auto pointer = data_->accelerators.Get();
        *output = mojo::ArrayDataView<AcceleratorDataView>(pointer, context_);
    }

    inline void WindowManagerClient_WmSetFrameDecorationValues_ParamsDataView::GetValuesDataView(
        ::ui::mojom::FrameDecorationValuesDataView* output)
    {
        auto pointer = data_->values.Get();
        *output = ::ui::mojom::FrameDecorationValuesDataView(pointer, context_);
    }

} // namespace mojom
} // namespace ui

#endif // SERVICES_UI_PUBLIC_INTERFACES_WINDOW_MANAGER_MOJOM_SHARED_H_
