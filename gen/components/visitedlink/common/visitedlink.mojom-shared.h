// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_VISITEDLINK_COMMON_VISITEDLINK_MOJOM_SHARED_H_
#define COMPONENTS_VISITEDLINK_COMMON_VISITEDLINK_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "components/visitedlink/common/visitedlink.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"

namespace visitedlink {
namespace mojom {

} // namespace mojom
} // namespace visitedlink

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace visitedlink {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class VisitedLinkNotificationSinkInterfaceBase {
    };

    using VisitedLinkNotificationSinkPtrDataView = mojo::InterfacePtrDataView<VisitedLinkNotificationSinkInterfaceBase>;
    using VisitedLinkNotificationSinkRequestDataView = mojo::InterfaceRequestDataView<VisitedLinkNotificationSinkInterfaceBase>;
    using VisitedLinkNotificationSinkAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<VisitedLinkNotificationSinkInterfaceBase>;
    using VisitedLinkNotificationSinkAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<VisitedLinkNotificationSinkInterfaceBase>;
    class VisitedLinkNotificationSink_UpdateVisitedLinks_ParamsDataView {
    public:
        VisitedLinkNotificationSink_UpdateVisitedLinks_ParamsDataView() { }

        VisitedLinkNotificationSink_UpdateVisitedLinks_ParamsDataView(
            internal::VisitedLinkNotificationSink_UpdateVisitedLinks_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        mojo::ScopedSharedBufferHandle TakeTableHandle()
        {
            mojo::ScopedSharedBufferHandle result;
            bool ret = mojo::internal::Deserialize<mojo::ScopedSharedBufferHandle>(
                &data_->table_handle, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::VisitedLinkNotificationSink_UpdateVisitedLinks_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class VisitedLinkNotificationSink_AddVisitedLinks_ParamsDataView {
    public:
        VisitedLinkNotificationSink_AddVisitedLinks_ParamsDataView() { }

        VisitedLinkNotificationSink_AddVisitedLinks_ParamsDataView(
            internal::VisitedLinkNotificationSink_AddVisitedLinks_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetLinkHashesDataView(
            mojo::ArrayDataView<uint64_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadLinkHashes(UserType* output)
        {
            auto* pointer = data_->link_hashes.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint64_t>>(
                pointer, output, context_);
        }

    private:
        internal::VisitedLinkNotificationSink_AddVisitedLinks_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class VisitedLinkNotificationSink_ResetVisitedLinks_ParamsDataView {
    public:
        VisitedLinkNotificationSink_ResetVisitedLinks_ParamsDataView() { }

        VisitedLinkNotificationSink_ResetVisitedLinks_ParamsDataView(
            internal::VisitedLinkNotificationSink_ResetVisitedLinks_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool invalidate_cached_hashes() const
        {
            return data_->invalidate_cached_hashes;
        }

    private:
        internal::VisitedLinkNotificationSink_ResetVisitedLinks_Params_Data* data_ = nullptr;
    };

} // namespace mojom
} // namespace visitedlink

namespace std {

} // namespace std

namespace mojo {

} // namespace mojo

namespace visitedlink {
namespace mojom {

    inline void VisitedLinkNotificationSink_AddVisitedLinks_ParamsDataView::GetLinkHashesDataView(
        mojo::ArrayDataView<uint64_t>* output)
    {
        auto pointer = data_->link_hashes.Get();
        *output = mojo::ArrayDataView<uint64_t>(pointer, context_);
    }

} // namespace mojom
} // namespace visitedlink

#endif // COMPONENTS_VISITEDLINK_COMMON_VISITEDLINK_MOJOM_SHARED_H_
