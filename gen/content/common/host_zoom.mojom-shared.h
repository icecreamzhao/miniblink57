// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_HOST_ZOOM_MOJOM_SHARED_H_
#define CONTENT_COMMON_HOST_ZOOM_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "content/common/host_zoom.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "url/mojo/url.mojom-shared.h"

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
    class HostZoomInterfaceBase {
    };

    using HostZoomPtrDataView = mojo::InterfacePtrDataView<HostZoomInterfaceBase>;
    using HostZoomRequestDataView = mojo::InterfaceRequestDataView<HostZoomInterfaceBase>;
    using HostZoomAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<HostZoomInterfaceBase>;
    using HostZoomAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<HostZoomInterfaceBase>;
    class HostZoom_SetHostZoomLevel_ParamsDataView {
    public:
        HostZoom_SetHostZoomLevel_ParamsDataView() { }

        HostZoom_SetHostZoomLevel_ParamsDataView(
            internal::HostZoom_SetHostZoomLevel_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetUrlDataView(
            ::url::mojom::UrlDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadUrl(UserType* output)
        {
            auto* pointer = data_->url.Get();
            return mojo::internal::Deserialize<::url::mojom::UrlDataView>(
                pointer, output, context_);
        }
        double zoom_level() const
        {
            return data_->zoom_level;
        }

    private:
        internal::HostZoom_SetHostZoomLevel_Params_Data* data_ = nullptr;
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

    inline void HostZoom_SetHostZoomLevel_ParamsDataView::GetUrlDataView(
        ::url::mojom::UrlDataView* output)
    {
        auto pointer = data_->url.Get();
        *output = ::url::mojom::UrlDataView(pointer, context_);
    }

} // namespace mojom
} // namespace content

#endif // CONTENT_COMMON_HOST_ZOOM_MOJOM_SHARED_H_
