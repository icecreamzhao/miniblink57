// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_URL_LOADER_FACTORY_MOJOM_SHARED_H_
#define CONTENT_COMMON_URL_LOADER_FACTORY_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "content/common/url_loader.mojom-shared.h"
#include "content/common/url_loader_factory.mojom-shared-internal.h"
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
    using URLSyncLoadResultDataView = mojo::NativeStructDataView;

} // namespace mojom
} // namespace content

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace content {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class URLLoaderFactoryInterfaceBase {
    };

    using URLLoaderFactoryPtrDataView = mojo::InterfacePtrDataView<URLLoaderFactoryInterfaceBase>;
    using URLLoaderFactoryRequestDataView = mojo::InterfaceRequestDataView<URLLoaderFactoryInterfaceBase>;
    using URLLoaderFactoryAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<URLLoaderFactoryInterfaceBase>;
    using URLLoaderFactoryAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<URLLoaderFactoryInterfaceBase>;
    class URLLoaderFactory_CreateLoaderAndStart_ParamsDataView {
    public:
        URLLoaderFactory_CreateLoaderAndStart_ParamsDataView() { }

        URLLoaderFactory_CreateLoaderAndStart_ParamsDataView(
            internal::URLLoaderFactory_CreateLoaderAndStart_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeLoader()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::content::mojom::URLLoaderAssociatedRequestDataView>(
                &data_->loader, &result, context_);
            DCHECK(ret);
            return result;
        }
        int32_t routing_id() const
        {
            return data_->routing_id;
        }
        int32_t request_id() const
        {
            return data_->request_id;
        }
        inline void GetRequestDataView(
            ::content::mojom::URLRequestDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadRequest(UserType* output)
        {
            auto* pointer = data_->request.Get();
            return mojo::internal::Deserialize<::content::mojom::URLRequestDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        UserType TakeClient()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::content::mojom::URLLoaderClientAssociatedPtrInfoDataView>(
                &data_->client, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::URLLoaderFactory_CreateLoaderAndStart_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class URLLoaderFactory_SyncLoad_ParamsDataView {
    public:
        URLLoaderFactory_SyncLoad_ParamsDataView() { }

        URLLoaderFactory_SyncLoad_ParamsDataView(
            internal::URLLoaderFactory_SyncLoad_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        int32_t routing_id() const
        {
            return data_->routing_id;
        }
        int32_t request_id() const
        {
            return data_->request_id;
        }
        inline void GetRequestDataView(
            ::content::mojom::URLRequestDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadRequest(UserType* output)
        {
            auto* pointer = data_->request.Get();
            return mojo::internal::Deserialize<::content::mojom::URLRequestDataView>(
                pointer, output, context_);
        }

    private:
        internal::URLLoaderFactory_SyncLoad_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class URLLoaderFactory_SyncLoad_ResponseParamsDataView {
    public:
        URLLoaderFactory_SyncLoad_ResponseParamsDataView() { }

        URLLoaderFactory_SyncLoad_ResponseParamsDataView(
            internal::URLLoaderFactory_SyncLoad_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetResultDataView(
            URLSyncLoadResultDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadResult(UserType* output)
        {
            auto* pointer = data_->result.Get();
            return mojo::internal::Deserialize<::content::mojom::URLSyncLoadResultDataView>(
                pointer, output, context_);
        }

    private:
        internal::URLLoaderFactory_SyncLoad_ResponseParams_Data* data_ = nullptr;
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

    inline void URLLoaderFactory_CreateLoaderAndStart_ParamsDataView::GetRequestDataView(
        ::content::mojom::URLRequestDataView* output)
    {
        auto pointer = data_->request.Get();
        *output = ::content::mojom::URLRequestDataView(pointer, context_);
    }

    inline void URLLoaderFactory_SyncLoad_ParamsDataView::GetRequestDataView(
        ::content::mojom::URLRequestDataView* output)
    {
        auto pointer = data_->request.Get();
        *output = ::content::mojom::URLRequestDataView(pointer, context_);
    }

    inline void URLLoaderFactory_SyncLoad_ResponseParamsDataView::GetResultDataView(
        URLSyncLoadResultDataView* output)
    {
        auto pointer = data_->result.Get();
        *output = URLSyncLoadResultDataView(pointer, context_);
    }

} // namespace mojom
} // namespace content

#endif // CONTENT_COMMON_URL_LOADER_FACTORY_MOJOM_SHARED_H_
