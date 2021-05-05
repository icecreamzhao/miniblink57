// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_DISPLAY_MANAGER_MOJOM_SHARED_H_
#define SERVICES_UI_PUBLIC_INTERFACES_DISPLAY_MANAGER_MOJOM_SHARED_H_

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
#include "services/ui/public/interfaces/display_manager.mojom-shared-internal.h"
#include "services/ui/public/interfaces/window_manager_constants.mojom-shared.h"

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
    class DisplayManagerObserverInterfaceBase {
    };

    using DisplayManagerObserverPtrDataView = mojo::InterfacePtrDataView<DisplayManagerObserverInterfaceBase>;
    using DisplayManagerObserverRequestDataView = mojo::InterfaceRequestDataView<DisplayManagerObserverInterfaceBase>;
    using DisplayManagerObserverAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<DisplayManagerObserverInterfaceBase>;
    using DisplayManagerObserverAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<DisplayManagerObserverInterfaceBase>;
    class DisplayManagerInterfaceBase {
    };

    using DisplayManagerPtrDataView = mojo::InterfacePtrDataView<DisplayManagerInterfaceBase>;
    using DisplayManagerRequestDataView = mojo::InterfaceRequestDataView<DisplayManagerInterfaceBase>;
    using DisplayManagerAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<DisplayManagerInterfaceBase>;
    using DisplayManagerAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<DisplayManagerInterfaceBase>;
    class DisplayManagerObserver_OnDisplays_ParamsDataView {
    public:
        DisplayManagerObserver_OnDisplays_ParamsDataView() { }

        DisplayManagerObserver_OnDisplays_ParamsDataView(
            internal::DisplayManagerObserver_OnDisplays_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetDisplaysDataView(
            mojo::ArrayDataView<::ui::mojom::WsDisplayDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDisplays(UserType* output)
        {
            auto* pointer = data_->displays.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::ui::mojom::WsDisplayDataView>>(
                pointer, output, context_);
        }
        int64_t primary_display_id() const
        {
            return data_->primary_display_id;
        }
        int64_t internal_display_id() const
        {
            return data_->internal_display_id;
        }

    private:
        internal::DisplayManagerObserver_OnDisplays_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class DisplayManagerObserver_OnDisplaysChanged_ParamsDataView {
    public:
        DisplayManagerObserver_OnDisplaysChanged_ParamsDataView() { }

        DisplayManagerObserver_OnDisplaysChanged_ParamsDataView(
            internal::DisplayManagerObserver_OnDisplaysChanged_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetDisplaysDataView(
            mojo::ArrayDataView<::ui::mojom::WsDisplayDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDisplays(UserType* output)
        {
            auto* pointer = data_->displays.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::ui::mojom::WsDisplayDataView>>(
                pointer, output, context_);
        }

    private:
        internal::DisplayManagerObserver_OnDisplaysChanged_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class DisplayManagerObserver_OnDisplayRemoved_ParamsDataView {
    public:
        DisplayManagerObserver_OnDisplayRemoved_ParamsDataView() { }

        DisplayManagerObserver_OnDisplayRemoved_ParamsDataView(
            internal::DisplayManagerObserver_OnDisplayRemoved_Params_Data* data,
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
        internal::DisplayManagerObserver_OnDisplayRemoved_Params_Data* data_ = nullptr;
    };

    class DisplayManagerObserver_OnPrimaryDisplayChanged_ParamsDataView {
    public:
        DisplayManagerObserver_OnPrimaryDisplayChanged_ParamsDataView() { }

        DisplayManagerObserver_OnPrimaryDisplayChanged_ParamsDataView(
            internal::DisplayManagerObserver_OnPrimaryDisplayChanged_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int64_t primary_display_id() const
        {
            return data_->primary_display_id;
        }

    private:
        internal::DisplayManagerObserver_OnPrimaryDisplayChanged_Params_Data* data_ = nullptr;
    };

    class DisplayManager_AddObserver_ParamsDataView {
    public:
        DisplayManager_AddObserver_ParamsDataView() { }

        DisplayManager_AddObserver_ParamsDataView(
            internal::DisplayManager_AddObserver_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeObserver()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::ui::mojom::DisplayManagerObserverPtrDataView>(
                &data_->observer, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::DisplayManager_AddObserver_Params_Data* data_ = nullptr;
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

    inline void DisplayManagerObserver_OnDisplays_ParamsDataView::GetDisplaysDataView(
        mojo::ArrayDataView<::ui::mojom::WsDisplayDataView>* output)
    {
        auto pointer = data_->displays.Get();
        *output = mojo::ArrayDataView<::ui::mojom::WsDisplayDataView>(pointer, context_);
    }

    inline void DisplayManagerObserver_OnDisplaysChanged_ParamsDataView::GetDisplaysDataView(
        mojo::ArrayDataView<::ui::mojom::WsDisplayDataView>* output)
    {
        auto pointer = data_->displays.Get();
        *output = mojo::ArrayDataView<::ui::mojom::WsDisplayDataView>(pointer, context_);
    }

} // namespace mojom
} // namespace ui

#endif // SERVICES_UI_PUBLIC_INTERFACES_DISPLAY_MANAGER_MOJOM_SHARED_H_
