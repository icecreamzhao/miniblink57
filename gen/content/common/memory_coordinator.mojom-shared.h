// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_MEMORY_COORDINATOR_MOJOM_SHARED_H_
#define CONTENT_COMMON_MEMORY_COORDINATOR_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "content/common/child_memory_coordinator.mojom-shared.h"
#include "content/common/memory_coordinator.mojom-shared-internal.h"
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
    class MemoryCoordinatorHandleInterfaceBase {
    };

    using MemoryCoordinatorHandlePtrDataView = mojo::InterfacePtrDataView<MemoryCoordinatorHandleInterfaceBase>;
    using MemoryCoordinatorHandleRequestDataView = mojo::InterfaceRequestDataView<MemoryCoordinatorHandleInterfaceBase>;
    using MemoryCoordinatorHandleAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<MemoryCoordinatorHandleInterfaceBase>;
    using MemoryCoordinatorHandleAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<MemoryCoordinatorHandleInterfaceBase>;
    class MemoryCoordinatorHandle_AddChild_ParamsDataView {
    public:
        MemoryCoordinatorHandle_AddChild_ParamsDataView() { }

        MemoryCoordinatorHandle_AddChild_ParamsDataView(
            internal::MemoryCoordinatorHandle_AddChild_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeChild()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::content::mojom::ChildMemoryCoordinatorPtrDataView>(
                &data_->child, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::MemoryCoordinatorHandle_AddChild_Params_Data* data_ = nullptr;
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

#endif // CONTENT_COMMON_MEMORY_COORDINATOR_MOJOM_SHARED_H_
