// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_FRAME_MOJOM_SHARED_H_
#define CONTENT_COMMON_FRAME_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "content/common/frame.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "services/service_manager/public/interfaces/interface_provider.mojom-shared.h"

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
    class FrameInterfaceBase {
    };

    using FramePtrDataView = mojo::InterfacePtrDataView<FrameInterfaceBase>;
    using FrameRequestDataView = mojo::InterfaceRequestDataView<FrameInterfaceBase>;
    using FrameAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<FrameInterfaceBase>;
    using FrameAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<FrameInterfaceBase>;
    class FrameHostInterfaceBase {
    };

    using FrameHostPtrDataView = mojo::InterfacePtrDataView<FrameHostInterfaceBase>;
    using FrameHostRequestDataView = mojo::InterfaceRequestDataView<FrameHostInterfaceBase>;
    using FrameHostAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<FrameHostInterfaceBase>;
    using FrameHostAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<FrameHostInterfaceBase>;
    class FrameFactoryInterfaceBase {
    };

    using FrameFactoryPtrDataView = mojo::InterfacePtrDataView<FrameFactoryInterfaceBase>;
    using FrameFactoryRequestDataView = mojo::InterfaceRequestDataView<FrameFactoryInterfaceBase>;
    using FrameFactoryAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<FrameFactoryInterfaceBase>;
    using FrameFactoryAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<FrameFactoryInterfaceBase>;
    class Frame_GetInterfaceProvider_ParamsDataView {
    public:
        Frame_GetInterfaceProvider_ParamsDataView() { }

        Frame_GetInterfaceProvider_ParamsDataView(
            internal::Frame_GetInterfaceProvider_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeInterfaces()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::service_manager::mojom::InterfaceProviderRequestDataView>(
                &data_->interfaces, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::Frame_GetInterfaceProvider_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class FrameHost_GetInterfaceProvider_ParamsDataView {
    public:
        FrameHost_GetInterfaceProvider_ParamsDataView() { }

        FrameHost_GetInterfaceProvider_ParamsDataView(
            internal::FrameHost_GetInterfaceProvider_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeInterfaces()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::service_manager::mojom::InterfaceProviderRequestDataView>(
                &data_->interfaces, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::FrameHost_GetInterfaceProvider_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class FrameFactory_CreateFrame_ParamsDataView {
    public:
        FrameFactory_CreateFrame_ParamsDataView() { }

        FrameFactory_CreateFrame_ParamsDataView(
            internal::FrameFactory_CreateFrame_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        int32_t frame_routing_id() const
        {
            return data_->frame_routing_id;
        }
        template <typename UserType>
        UserType TakeFrame()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::content::mojom::FrameRequestDataView>(
                &data_->frame, &result, context_);
            DCHECK(ret);
            return result;
        }
        template <typename UserType>
        UserType TakeHost()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::content::mojom::FrameHostPtrDataView>(
                &data_->host, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::FrameFactory_CreateFrame_Params_Data* data_ = nullptr;
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

#endif // CONTENT_COMMON_FRAME_MOJOM_SHARED_H_
