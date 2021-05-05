// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_SERVICE_MOJOM_SHARED_H_
#define SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_SERVICE_MOJOM_SHARED_H_

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
#include "services/video_capture/public/interfaces/device_factory.mojom-shared.h"
#include "services/video_capture/public/interfaces/service.mojom-shared-internal.h"

namespace video_capture {
namespace mojom {

} // namespace mojom
} // namespace video_capture

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace video_capture {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class ServiceInterfaceBase {
    };

    using ServicePtrDataView = mojo::InterfacePtrDataView<ServiceInterfaceBase>;
    using ServiceRequestDataView = mojo::InterfaceRequestDataView<ServiceInterfaceBase>;
    using ServiceAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<ServiceInterfaceBase>;
    using ServiceAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<ServiceInterfaceBase>;
    class Service_ConnectToDeviceFactory_ParamsDataView {
    public:
        Service_ConnectToDeviceFactory_ParamsDataView() { }

        Service_ConnectToDeviceFactory_ParamsDataView(
            internal::Service_ConnectToDeviceFactory_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeRequest()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::video_capture::mojom::DeviceFactoryRequestDataView>(
                &data_->request, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::Service_ConnectToDeviceFactory_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Service_ConnectToFakeDeviceFactory_ParamsDataView {
    public:
        Service_ConnectToFakeDeviceFactory_ParamsDataView() { }

        Service_ConnectToFakeDeviceFactory_ParamsDataView(
            internal::Service_ConnectToFakeDeviceFactory_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeRequest()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::video_capture::mojom::DeviceFactoryRequestDataView>(
                &data_->request, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::Service_ConnectToFakeDeviceFactory_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace video_capture

namespace std {

} // namespace std

namespace mojo {

} // namespace mojo

namespace video_capture {
namespace mojom {

} // namespace mojom
} // namespace video_capture

#endif // SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_SERVICE_MOJOM_SHARED_H_
