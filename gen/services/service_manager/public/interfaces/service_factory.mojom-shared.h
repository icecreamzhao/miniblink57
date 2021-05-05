// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_SERVICE_FACTORY_MOJOM_SHARED_H_
#define SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_SERVICE_FACTORY_MOJOM_SHARED_H_

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
#include "services/service_manager/public/interfaces/service.mojom-shared.h"
#include "services/service_manager/public/interfaces/service_factory.mojom-shared-internal.h"

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
    class ServiceFactoryInterfaceBase {
    };

    using ServiceFactoryPtrDataView = mojo::InterfacePtrDataView<ServiceFactoryInterfaceBase>;
    using ServiceFactoryRequestDataView = mojo::InterfaceRequestDataView<ServiceFactoryInterfaceBase>;
    using ServiceFactoryAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<ServiceFactoryInterfaceBase>;
    using ServiceFactoryAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<ServiceFactoryInterfaceBase>;
    class ServiceFactory_CreateService_ParamsDataView {
    public:
        ServiceFactory_CreateService_ParamsDataView() { }

        ServiceFactory_CreateService_ParamsDataView(
            internal::ServiceFactory_CreateService_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeService()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::service_manager::mojom::ServiceRequestDataView>(
                &data_->service, &result, context_);
            DCHECK(ret);
            return result;
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

    private:
        internal::ServiceFactory_CreateService_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace service_manager

namespace std {

} // namespace std

namespace mojo {

} // namespace mojo

namespace service_manager {
namespace mojom {

    inline void ServiceFactory_CreateService_ParamsDataView::GetNameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->name.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

} // namespace mojom
} // namespace service_manager

#endif // SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_SERVICE_FACTORY_MOJOM_SHARED_H_
