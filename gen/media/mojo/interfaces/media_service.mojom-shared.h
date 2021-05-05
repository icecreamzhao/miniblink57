// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_MOJO_INTERFACES_MEDIA_SERVICE_MOJOM_SHARED_H_
#define MEDIA_MOJO_INTERFACES_MEDIA_SERVICE_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "media/mojo/interfaces/interface_factory.mojom-shared.h"
#include "media/mojo/interfaces/media_service.mojom-shared-internal.h"
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

namespace media {
namespace mojom {

} // namespace mojom
} // namespace media

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace media {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class MediaServiceInterfaceBase {
    };

    using MediaServicePtrDataView = mojo::InterfacePtrDataView<MediaServiceInterfaceBase>;
    using MediaServiceRequestDataView = mojo::InterfaceRequestDataView<MediaServiceInterfaceBase>;
    using MediaServiceAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<MediaServiceInterfaceBase>;
    using MediaServiceAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<MediaServiceInterfaceBase>;
    class MediaService_CreateInterfaceFactory_ParamsDataView {
    public:
        MediaService_CreateInterfaceFactory_ParamsDataView() { }

        MediaService_CreateInterfaceFactory_ParamsDataView(
            internal::MediaService_CreateInterfaceFactory_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeFactory()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::media::mojom::InterfaceFactoryRequestDataView>(
                &data_->factory, &result, context_);
            DCHECK(ret);
            return result;
        }
        template <typename UserType>
        UserType TakeHostInterfaces()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::service_manager::mojom::InterfaceProviderPtrDataView>(
                &data_->host_interfaces, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::MediaService_CreateInterfaceFactory_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace media

namespace std {

} // namespace std

namespace mojo {

} // namespace mojo

namespace media {
namespace mojom {

} // namespace mojom
} // namespace media

#endif // MEDIA_MOJO_INTERFACES_MEDIA_SERVICE_MOJOM_SHARED_H_
