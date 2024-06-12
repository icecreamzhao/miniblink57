// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_DISCARDABLE_MEMORY_PUBLIC_INTERFACES_DISCARDABLE_SHARED_MEMORY_MANAGER_MOJOM_SHARED_H_
#define COMPONENTS_DISCARDABLE_MEMORY_PUBLIC_INTERFACES_DISCARDABLE_SHARED_MEMORY_MANAGER_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "components/discardable_memory/public/interfaces/discardable_shared_memory_manager.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"

namespace discardable_memory {
namespace mojom {

} // namespace mojom
} // namespace discardable_memory

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace discardable_memory {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class DiscardableSharedMemoryManagerInterfaceBase {
    };

    using DiscardableSharedMemoryManagerPtrDataView = mojo::InterfacePtrDataView<DiscardableSharedMemoryManagerInterfaceBase>;
    using DiscardableSharedMemoryManagerRequestDataView = mojo::InterfaceRequestDataView<DiscardableSharedMemoryManagerInterfaceBase>;
    using DiscardableSharedMemoryManagerAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<DiscardableSharedMemoryManagerInterfaceBase>;
    using DiscardableSharedMemoryManagerAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<DiscardableSharedMemoryManagerInterfaceBase>;
    class DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ParamsDataView {
    public:
        DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ParamsDataView() { }

        DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ParamsDataView(
            internal::DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t size() const
        {
            return data_->size;
        }
        int32_t id() const
        {
            return data_->id;
        }

    private:
        internal::DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_Params_Data* data_ = nullptr;
    };

    class DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ResponseParamsDataView {
    public:
        DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ResponseParamsDataView() { }

        DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ResponseParamsDataView(
            internal::DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        mojo::ScopedSharedBufferHandle TakeMemory()
        {
            mojo::ScopedSharedBufferHandle result;
            bool ret = mojo::internal::Deserialize<mojo::ScopedSharedBufferHandle>(
                &data_->memory, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::DiscardableSharedMemoryManager_AllocateLockedDiscardableSharedMemory_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class DiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_ParamsDataView {
    public:
        DiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_ParamsDataView() { }

        DiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_ParamsDataView(
            internal::DiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int32_t id() const
        {
            return data_->id;
        }

    private:
        internal::DiscardableSharedMemoryManager_DeletedDiscardableSharedMemory_Params_Data* data_ = nullptr;
    };

} // namespace mojom
} // namespace discardable_memory

namespace std {

} // namespace std

namespace mojo {

} // namespace mojo

namespace discardable_memory {
namespace mojom {

} // namespace mojom
} // namespace discardable_memory

#endif // COMPONENTS_DISCARDABLE_MEMORY_PUBLIC_INTERFACES_DISCARDABLE_SHARED_MEMORY_MANAGER_MOJOM_SHARED_H_
