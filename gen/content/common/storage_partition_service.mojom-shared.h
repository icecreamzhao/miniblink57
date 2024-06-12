// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_STORAGE_PARTITION_SERVICE_MOJOM_SHARED_H_
#define CONTENT_COMMON_STORAGE_PARTITION_SERVICE_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "content/common/leveldb_wrapper.mojom-shared.h"
#include "content/common/storage_partition_service.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "url/mojo/origin.mojom-shared.h"

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
    class StoragePartitionServiceInterfaceBase {
    };

    using StoragePartitionServicePtrDataView = mojo::InterfacePtrDataView<StoragePartitionServiceInterfaceBase>;
    using StoragePartitionServiceRequestDataView = mojo::InterfaceRequestDataView<StoragePartitionServiceInterfaceBase>;
    using StoragePartitionServiceAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<StoragePartitionServiceInterfaceBase>;
    using StoragePartitionServiceAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<StoragePartitionServiceInterfaceBase>;
    class StoragePartitionService_OpenLocalStorage_ParamsDataView {
    public:
        StoragePartitionService_OpenLocalStorage_ParamsDataView() { }

        StoragePartitionService_OpenLocalStorage_ParamsDataView(
            internal::StoragePartitionService_OpenLocalStorage_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetOriginDataView(
            ::url::mojom::OriginDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOrigin(UserType* output)
        {
            auto* pointer = data_->origin.Get();
            return mojo::internal::Deserialize<::url::mojom::OriginDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        UserType TakeDatabase()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::content::mojom::LevelDBWrapperRequestDataView>(
                &data_->database, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::StoragePartitionService_OpenLocalStorage_Params_Data* data_ = nullptr;
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

    inline void StoragePartitionService_OpenLocalStorage_ParamsDataView::GetOriginDataView(
        ::url::mojom::OriginDataView* output)
    {
        auto pointer = data_->origin.Get();
        *output = ::url::mojom::OriginDataView(pointer, context_);
    }

} // namespace mojom
} // namespace content

#endif // CONTENT_COMMON_STORAGE_PARTITION_SERVICE_MOJOM_SHARED_H_
