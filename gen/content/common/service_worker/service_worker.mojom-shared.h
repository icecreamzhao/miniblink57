// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_SERVICE_WORKER_SERVICE_WORKER_MOJOM_SHARED_H_
#define CONTENT_COMMON_SERVICE_WORKER_SERVICE_WORKER_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "content/common/service_worker/service_worker.mojom-shared-internal.h"
#include "content/common/service_worker/service_worker_types.mojom-shared.h"
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
    class ServiceWorkerDispatcherHostInterfaceBase {
    };

    using ServiceWorkerDispatcherHostPtrDataView = mojo::InterfacePtrDataView<ServiceWorkerDispatcherHostInterfaceBase>;
    using ServiceWorkerDispatcherHostRequestDataView = mojo::InterfaceRequestDataView<ServiceWorkerDispatcherHostInterfaceBase>;
    using ServiceWorkerDispatcherHostAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<ServiceWorkerDispatcherHostInterfaceBase>;
    using ServiceWorkerDispatcherHostAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<ServiceWorkerDispatcherHostInterfaceBase>;
    class ServiceWorkerDispatcherHost_OnProviderCreated_ParamsDataView {
    public:
        ServiceWorkerDispatcherHost_OnProviderCreated_ParamsDataView() { }

        ServiceWorkerDispatcherHost_OnProviderCreated_ParamsDataView(
            internal::ServiceWorkerDispatcherHost_OnProviderCreated_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int32_t provider_id() const
        {
            return data_->provider_id;
        }
        int32_t route_id() const
        {
            return data_->route_id;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadProviderType(UserType* output) const
        {
            auto data_value = data_->provider_type;
            return mojo::internal::Deserialize<::content::mojom::ServiceWorkerProviderType>(
                data_value, output);
        }

        ::content::mojom::ServiceWorkerProviderType provider_type() const
        {
            return static_cast<::content::mojom::ServiceWorkerProviderType>(data_->provider_type);
        }
        bool is_parent_frame_secure() const
        {
            return data_->is_parent_frame_secure;
        }

    private:
        internal::ServiceWorkerDispatcherHost_OnProviderCreated_Params_Data* data_ = nullptr;
    };

    class ServiceWorkerDispatcherHost_OnProviderDestroyed_ParamsDataView {
    public:
        ServiceWorkerDispatcherHost_OnProviderDestroyed_ParamsDataView() { }

        ServiceWorkerDispatcherHost_OnProviderDestroyed_ParamsDataView(
            internal::ServiceWorkerDispatcherHost_OnProviderDestroyed_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int32_t provider_id() const
        {
            return data_->provider_id;
        }

    private:
        internal::ServiceWorkerDispatcherHost_OnProviderDestroyed_Params_Data* data_ = nullptr;
    };

    class ServiceWorkerDispatcherHost_OnSetHostedVersionId_ParamsDataView {
    public:
        ServiceWorkerDispatcherHost_OnSetHostedVersionId_ParamsDataView() { }

        ServiceWorkerDispatcherHost_OnSetHostedVersionId_ParamsDataView(
            internal::ServiceWorkerDispatcherHost_OnSetHostedVersionId_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int32_t provider_id() const
        {
            return data_->provider_id;
        }
        int64_t version_id() const
        {
            return data_->version_id;
        }
        int32_t embedded_worker_id() const
        {
            return data_->embedded_worker_id;
        }

    private:
        internal::ServiceWorkerDispatcherHost_OnSetHostedVersionId_Params_Data* data_ = nullptr;
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

#endif // CONTENT_COMMON_SERVICE_WORKER_SERVICE_WORKER_MOJOM_SHARED_H_
