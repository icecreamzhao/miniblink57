// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_SERVICE_CONTROL_MOJOM_SHARED_H_
#define SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_SERVICE_CONTROL_MOJOM_SHARED_H_

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
#include "services/service_manager/public/interfaces/service_control.mojom-shared-internal.h"

namespace service_manager {
namespace mojom {

} // namespace mojom
} // namespace service_manager

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace service_manager {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class ServiceControlInterfaceBase {
    };

    using ServiceControlPtrDataView = mojo::InterfacePtrDataView<ServiceControlInterfaceBase>;
    using ServiceControlRequestDataView = mojo::InterfaceRequestDataView<ServiceControlInterfaceBase>;
    using ServiceControlAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<ServiceControlInterfaceBase>;
    using ServiceControlAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<ServiceControlInterfaceBase>;
    class ServiceControl_RequestQuit_ParamsDataView {
    public:
        ServiceControl_RequestQuit_ParamsDataView() { }

        ServiceControl_RequestQuit_ParamsDataView(
            internal::ServiceControl_RequestQuit_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::ServiceControl_RequestQuit_Params_Data* data_ = nullptr;
    };

} // namespace mojom
} // namespace service_manager

namespace std {

} // namespace std

namespace mojo {

} // namespace mojo

namespace service_manager {
namespace mojom {

} // namespace mojom
} // namespace service_manager

#endif // SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_SERVICE_CONTROL_MOJOM_SHARED_H_
