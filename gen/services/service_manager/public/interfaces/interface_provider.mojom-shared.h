// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_INTERFACE_PROVIDER_MOJOM_SHARED_H_
#define SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_INTERFACE_PROVIDER_MOJOM_SHARED_H_

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
#include "services/service_manager/public/interfaces/interface_provider.mojom-shared-internal.h"

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
    class InterfaceProviderInterfaceBase {
    };

    using InterfaceProviderPtrDataView = mojo::InterfacePtrDataView<InterfaceProviderInterfaceBase>;
    using InterfaceProviderRequestDataView = mojo::InterfaceRequestDataView<InterfaceProviderInterfaceBase>;
    using InterfaceProviderAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<InterfaceProviderInterfaceBase>;
    using InterfaceProviderAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<InterfaceProviderInterfaceBase>;
    class InterfaceProvider_GetInterface_ParamsDataView {
    public:
        InterfaceProvider_GetInterface_ParamsDataView() { }

        InterfaceProvider_GetInterface_ParamsDataView(
            internal::InterfaceProvider_GetInterface_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetInterfaceNameDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadInterfaceName(UserType* output)
        {
            auto* pointer = data_->interface_name.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        mojo::ScopedMessagePipeHandle TakePipe()
        {
            mojo::ScopedMessagePipeHandle result;
            bool ret = mojo::internal::Deserialize<mojo::ScopedMessagePipeHandle>(
                &data_->pipe, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::InterfaceProvider_GetInterface_Params_Data* data_ = nullptr;
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

    inline void InterfaceProvider_GetInterface_ParamsDataView::GetInterfaceNameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->interface_name.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

} // namespace mojom
} // namespace service_manager

#endif // SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_INTERFACE_PROVIDER_MOJOM_SHARED_H_
