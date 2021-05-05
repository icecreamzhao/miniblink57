// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_DISPLAY_DISPLAY_CONTROLLER_MOJOM_SHARED_H_
#define SERVICES_UI_PUBLIC_INTERFACES_DISPLAY_DISPLAY_CONTROLLER_MOJOM_SHARED_H_

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
#include "services/ui/public/interfaces/display/display_controller.mojom-shared-internal.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared.h"

namespace display {
namespace mojom {

} // namespace mojom
} // namespace display

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace display {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class DisplayControllerInterfaceBase {
    };

    using DisplayControllerPtrDataView = mojo::InterfacePtrDataView<DisplayControllerInterfaceBase>;
    using DisplayControllerRequestDataView = mojo::InterfaceRequestDataView<DisplayControllerInterfaceBase>;
    using DisplayControllerAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<DisplayControllerInterfaceBase>;
    using DisplayControllerAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<DisplayControllerInterfaceBase>;
    class DisplayController_IncreaseInternalDisplayZoom_ParamsDataView {
    public:
        DisplayController_IncreaseInternalDisplayZoom_ParamsDataView() { }

        DisplayController_IncreaseInternalDisplayZoom_ParamsDataView(
            internal::DisplayController_IncreaseInternalDisplayZoom_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::DisplayController_IncreaseInternalDisplayZoom_Params_Data* data_ = nullptr;
    };

    class DisplayController_DecreaseInternalDisplayZoom_ParamsDataView {
    public:
        DisplayController_DecreaseInternalDisplayZoom_ParamsDataView() { }

        DisplayController_DecreaseInternalDisplayZoom_ParamsDataView(
            internal::DisplayController_DecreaseInternalDisplayZoom_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::DisplayController_DecreaseInternalDisplayZoom_Params_Data* data_ = nullptr;
    };

    class DisplayController_ResetInternalDisplayZoom_ParamsDataView {
    public:
        DisplayController_ResetInternalDisplayZoom_ParamsDataView() { }

        DisplayController_ResetInternalDisplayZoom_ParamsDataView(
            internal::DisplayController_ResetInternalDisplayZoom_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::DisplayController_ResetInternalDisplayZoom_Params_Data* data_ = nullptr;
    };

    class DisplayController_RotateCurrentDisplayCW_ParamsDataView {
    public:
        DisplayController_RotateCurrentDisplayCW_ParamsDataView() { }

        DisplayController_RotateCurrentDisplayCW_ParamsDataView(
            internal::DisplayController_RotateCurrentDisplayCW_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::DisplayController_RotateCurrentDisplayCW_Params_Data* data_ = nullptr;
    };

    class DisplayController_SwapPrimaryDisplay_ParamsDataView {
    public:
        DisplayController_SwapPrimaryDisplay_ParamsDataView() { }

        DisplayController_SwapPrimaryDisplay_ParamsDataView(
            internal::DisplayController_SwapPrimaryDisplay_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::DisplayController_SwapPrimaryDisplay_Params_Data* data_ = nullptr;
    };

    class DisplayController_ToggleMirrorMode_ParamsDataView {
    public:
        DisplayController_ToggleMirrorMode_ParamsDataView() { }

        DisplayController_ToggleMirrorMode_ParamsDataView(
            internal::DisplayController_ToggleMirrorMode_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::DisplayController_ToggleMirrorMode_Params_Data* data_ = nullptr;
    };

    class DisplayController_SetDisplayWorkArea_ParamsDataView {
    public:
        DisplayController_SetDisplayWorkArea_ParamsDataView() { }

        DisplayController_SetDisplayWorkArea_ParamsDataView(
            internal::DisplayController_SetDisplayWorkArea_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        int64_t display_id() const
        {
            return data_->display_id;
        }
        inline void GetSizeDataView(
            ::gfx::mojom::SizeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSize(UserType* output)
        {
            auto* pointer = data_->size.Get();
            return mojo::internal::Deserialize<::gfx::mojom::SizeDataView>(
                pointer, output, context_);
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

    private:
        internal::DisplayController_SetDisplayWorkArea_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace display

namespace std {

} // namespace std

namespace mojo {

} // namespace mojo

namespace display {
namespace mojom {

    inline void DisplayController_SetDisplayWorkArea_ParamsDataView::GetSizeDataView(
        ::gfx::mojom::SizeDataView* output)
    {
        auto pointer = data_->size.Get();
        *output = ::gfx::mojom::SizeDataView(pointer, context_);
    }
    inline void DisplayController_SetDisplayWorkArea_ParamsDataView::GetInsetsDataView(
        ::gfx::mojom::InsetsDataView* output)
    {
        auto pointer = data_->insets.Get();
        *output = ::gfx::mojom::InsetsDataView(pointer, context_);
    }

} // namespace mojom
} // namespace display

#endif // SERVICES_UI_PUBLIC_INTERFACES_DISPLAY_DISPLAY_CONTROLLER_MOJOM_SHARED_H_
