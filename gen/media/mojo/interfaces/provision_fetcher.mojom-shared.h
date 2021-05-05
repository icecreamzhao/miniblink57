// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_MOJO_INTERFACES_PROVISION_FETCHER_MOJOM_SHARED_H_
#define MEDIA_MOJO_INTERFACES_PROVISION_FETCHER_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "media/mojo/interfaces/provision_fetcher.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"

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
    class ProvisionFetcherInterfaceBase {
    };

    using ProvisionFetcherPtrDataView = mojo::InterfacePtrDataView<ProvisionFetcherInterfaceBase>;
    using ProvisionFetcherRequestDataView = mojo::InterfaceRequestDataView<ProvisionFetcherInterfaceBase>;
    using ProvisionFetcherAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<ProvisionFetcherInterfaceBase>;
    using ProvisionFetcherAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<ProvisionFetcherInterfaceBase>;
    class ProvisionFetcher_Retrieve_ParamsDataView {
    public:
        ProvisionFetcher_Retrieve_ParamsDataView() { }

        ProvisionFetcher_Retrieve_ParamsDataView(
            internal::ProvisionFetcher_Retrieve_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetDefaultUrlDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDefaultUrl(UserType* output)
        {
            auto* pointer = data_->default_url.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetRequestDataDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadRequestData(UserType* output)
        {
            auto* pointer = data_->request_data.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::ProvisionFetcher_Retrieve_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class ProvisionFetcher_Retrieve_ResponseParamsDataView {
    public:
        ProvisionFetcher_Retrieve_ResponseParamsDataView() { }

        ProvisionFetcher_Retrieve_ResponseParamsDataView(
            internal::ProvisionFetcher_Retrieve_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        bool result() const
        {
            return data_->result;
        }
        inline void GetResponseDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadResponse(UserType* output)
        {
            auto* pointer = data_->response.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::ProvisionFetcher_Retrieve_ResponseParams_Data* data_ = nullptr;
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

    inline void ProvisionFetcher_Retrieve_ParamsDataView::GetDefaultUrlDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->default_url.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void ProvisionFetcher_Retrieve_ParamsDataView::GetRequestDataDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->request_data.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void ProvisionFetcher_Retrieve_ResponseParamsDataView::GetResponseDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->response.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

} // namespace mojom
} // namespace media

#endif // MEDIA_MOJO_INTERFACES_PROVISION_FETCHER_MOJOM_SHARED_H_
