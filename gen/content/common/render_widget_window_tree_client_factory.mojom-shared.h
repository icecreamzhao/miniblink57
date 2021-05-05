// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_RENDER_WIDGET_WINDOW_TREE_CLIENT_FACTORY_MOJOM_SHARED_H_
#define CONTENT_COMMON_RENDER_WIDGET_WINDOW_TREE_CLIENT_FACTORY_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "content/common/render_widget_window_tree_client_factory.mojom-shared-internal.h"
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

namespace content {
namespace mojom {

} // namespace mojom
} // namespace content

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace content {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class RenderWidgetWindowTreeClientFactoryInterfaceBase {
    };

    using RenderWidgetWindowTreeClientFactoryPtrDataView = mojo::InterfacePtrDataView<RenderWidgetWindowTreeClientFactoryInterfaceBase>;
    using RenderWidgetWindowTreeClientFactoryRequestDataView = mojo::InterfaceRequestDataView<RenderWidgetWindowTreeClientFactoryInterfaceBase>;
    using RenderWidgetWindowTreeClientFactoryAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<RenderWidgetWindowTreeClientFactoryInterfaceBase>;
    using RenderWidgetWindowTreeClientFactoryAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<RenderWidgetWindowTreeClientFactoryInterfaceBase>;
    class RenderWidgetWindowTreeClientFactory_CreateWindowTreeClientForRenderWidget_ParamsDataView {
    public:
        RenderWidgetWindowTreeClientFactory_CreateWindowTreeClientForRenderWidget_ParamsDataView() { }

        RenderWidgetWindowTreeClientFactory_CreateWindowTreeClientForRenderWidget_ParamsDataView(
            internal::RenderWidgetWindowTreeClientFactory_CreateWindowTreeClientForRenderWidget_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t routing_id() const
        {
            return data_->routing_id;
        }
        template <typename UserType>
        UserType TakeWindowTreeClient()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::ui::mojom::WindowTreeClientRequestDataView>(
                &data_->window_tree_client, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::RenderWidgetWindowTreeClientFactory_CreateWindowTreeClientForRenderWidget_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace content

namespace std {

} // namespace std

namespace mojo {

} // namespace mojo

namespace content {
namespace mojom {

} // namespace mojom
} // namespace content

#endif // CONTENT_COMMON_RENDER_WIDGET_WINDOW_TREE_CLIENT_FACTORY_MOJOM_SHARED_H_
