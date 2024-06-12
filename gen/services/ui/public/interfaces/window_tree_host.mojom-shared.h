// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_WINDOW_TREE_HOST_MOJOM_SHARED_H_
#define SERVICES_UI_PUBLIC_INTERFACES_WINDOW_TREE_HOST_MOJOM_SHARED_H_

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
#include "services/ui/public/interfaces/window_tree.mojom-shared.h"
#include "services/ui/public/interfaces/window_tree_host.mojom-shared-internal.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared.h"

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
    class WindowTreeHostInterfaceBase {
    };

    using WindowTreeHostPtrDataView = mojo::InterfacePtrDataView<WindowTreeHostInterfaceBase>;
    using WindowTreeHostRequestDataView = mojo::InterfaceRequestDataView<WindowTreeHostInterfaceBase>;
    using WindowTreeHostAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<WindowTreeHostInterfaceBase>;
    using WindowTreeHostAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<WindowTreeHostInterfaceBase>;
    class WindowTreeHostFactoryInterfaceBase {
    };

    using WindowTreeHostFactoryPtrDataView = mojo::InterfacePtrDataView<WindowTreeHostFactoryInterfaceBase>;
    using WindowTreeHostFactoryRequestDataView = mojo::InterfaceRequestDataView<WindowTreeHostFactoryInterfaceBase>;
    using WindowTreeHostFactoryAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<WindowTreeHostFactoryInterfaceBase>;
    using WindowTreeHostFactoryAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<WindowTreeHostFactoryInterfaceBase>;
    class WindowTreeHost_SetSize_ParamsDataView {
    public:
        WindowTreeHost_SetSize_ParamsDataView() { }

        WindowTreeHost_SetSize_ParamsDataView(
            internal::WindowTreeHost_SetSize_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetSizeDataView(
            ::gfx::mojom::SizeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSize(UserType* output)
        {
            auto* pointer = data_->size.Get();
            return mojo::internal::Deserialize<::gfx::mojom::SizeDataView>(
                pointer, output, context_);
        }

    private:
        internal::WindowTreeHost_SetSize_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowTreeHost_SetTitle_ParamsDataView {
    public:
        WindowTreeHost_SetTitle_ParamsDataView() { }

        WindowTreeHost_SetTitle_ParamsDataView(
            internal::WindowTreeHost_SetTitle_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetTitleDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTitle(UserType* output)
        {
            auto* pointer = data_->title.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::WindowTreeHost_SetTitle_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class WindowTreeHostFactory_CreateWindowTreeHost_ParamsDataView {
    public:
        WindowTreeHostFactory_CreateWindowTreeHost_ParamsDataView() { }

        WindowTreeHostFactory_CreateWindowTreeHost_ParamsDataView(
            internal::WindowTreeHostFactory_CreateWindowTreeHost_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeWindowTreeHost()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::ui::mojom::WindowTreeHostRequestDataView>(
                &data_->window_tree_host, &result, context_);
            DCHECK(ret);
            return result;
        }
        template <typename UserType>
        UserType TakeTreeClient()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::ui::mojom::WindowTreeClientPtrDataView>(
                &data_->tree_client, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::WindowTreeHostFactory_CreateWindowTreeHost_Params_Data* data_ = nullptr;
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

    inline void WindowTreeHost_SetSize_ParamsDataView::GetSizeDataView(
        ::gfx::mojom::SizeDataView* output)
    {
        auto pointer = data_->size.Get();
        *output = ::gfx::mojom::SizeDataView(pointer, context_);
    }

    inline void WindowTreeHost_SetTitle_ParamsDataView::GetTitleDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->title.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

} // namespace mojom
} // namespace ui

#endif // SERVICES_UI_PUBLIC_INTERFACES_WINDOW_TREE_HOST_MOJOM_SHARED_H_
