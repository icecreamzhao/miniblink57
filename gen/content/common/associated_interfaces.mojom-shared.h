// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_ASSOCIATED_INTERFACES_MOJOM_SHARED_H_
#define CONTENT_COMMON_ASSOCIATED_INTERFACES_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "content/common/associated_interfaces.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"

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
    class AssociatedInterfaceInterfaceBase {
    };

    using AssociatedInterfacePtrDataView = mojo::InterfacePtrDataView<AssociatedInterfaceInterfaceBase>;
    using AssociatedInterfaceRequestDataView = mojo::InterfaceRequestDataView<AssociatedInterfaceInterfaceBase>;
    using AssociatedInterfaceAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<AssociatedInterfaceInterfaceBase>;
    using AssociatedInterfaceAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<AssociatedInterfaceInterfaceBase>;
    class AssociatedInterfaceProviderInterfaceBase {
    };

    using AssociatedInterfaceProviderPtrDataView = mojo::InterfacePtrDataView<AssociatedInterfaceProviderInterfaceBase>;
    using AssociatedInterfaceProviderRequestDataView = mojo::InterfaceRequestDataView<AssociatedInterfaceProviderInterfaceBase>;
    using AssociatedInterfaceProviderAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<AssociatedInterfaceProviderInterfaceBase>;
    using AssociatedInterfaceProviderAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<AssociatedInterfaceProviderInterfaceBase>;
    class RouteProviderInterfaceBase {
    };

    using RouteProviderPtrDataView = mojo::InterfacePtrDataView<RouteProviderInterfaceBase>;
    using RouteProviderRequestDataView = mojo::InterfaceRequestDataView<RouteProviderInterfaceBase>;
    using RouteProviderAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<RouteProviderInterfaceBase>;
    using RouteProviderAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<RouteProviderInterfaceBase>;
    class AssociatedInterfaceProvider_GetAssociatedInterface_ParamsDataView {
    public:
        AssociatedInterfaceProvider_GetAssociatedInterface_ParamsDataView() { }

        AssociatedInterfaceProvider_GetAssociatedInterface_ParamsDataView(
            internal::AssociatedInterfaceProvider_GetAssociatedInterface_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetNameDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadName(UserType* output)
        {
            auto* pointer = data_->name.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        UserType TakeRequest()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::content::mojom::AssociatedInterfaceAssociatedRequestDataView>(
                &data_->request, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::AssociatedInterfaceProvider_GetAssociatedInterface_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class RouteProvider_GetRoute_ParamsDataView {
    public:
        RouteProvider_GetRoute_ParamsDataView() { }

        RouteProvider_GetRoute_ParamsDataView(
            internal::RouteProvider_GetRoute_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        int32_t routing_id() const
        {
            return data_->routing_id;
        }
        template <typename UserType>
        UserType TakeRequest()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::content::mojom::AssociatedInterfaceProviderAssociatedRequestDataView>(
                &data_->request, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::RouteProvider_GetRoute_Params_Data* data_ = nullptr;
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

    inline void AssociatedInterfaceProvider_GetAssociatedInterface_ParamsDataView::GetNameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->name.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

} // namespace mojom
} // namespace content

#endif // CONTENT_COMMON_ASSOCIATED_INTERFACES_MOJOM_SHARED_H_
