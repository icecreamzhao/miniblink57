// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_WEBSHARE_WEBSHARE_MOJOM_SHARED_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_WEBSHARE_WEBSHARE_MOJOM_SHARED_H_

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
#include "third_party/WebKit/public/platform/modules/webshare/webshare.mojom-shared-internal.h"
#include "url/mojo/url.mojom-shared.h"

namespace blink {
namespace mojom {

} // namespace mojom
} // namespace blink

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace blink {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class ShareServiceInterfaceBase {
    };

    using ShareServicePtrDataView = mojo::InterfacePtrDataView<ShareServiceInterfaceBase>;
    using ShareServiceRequestDataView = mojo::InterfaceRequestDataView<ShareServiceInterfaceBase>;
    using ShareServiceAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<ShareServiceInterfaceBase>;
    using ShareServiceAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<ShareServiceInterfaceBase>;
    class ShareService_Share_ParamsDataView {
    public:
        ShareService_Share_ParamsDataView() { }

        ShareService_Share_ParamsDataView(
            internal::ShareService_Share_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetTitleDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTitle(UserType* output)
        {
            auto* pointer = data_->title.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetTextDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadText(UserType* output)
        {
            auto* pointer = data_->text.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetUrlDataView(
            ::url::mojom::UrlDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadUrl(UserType* output)
        {
            auto* pointer = data_->url.Get();
            return mojo::internal::Deserialize<::url::mojom::UrlDataView>(
                pointer, output, context_);
        }

    private:
        internal::ShareService_Share_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class ShareService_Share_ResponseParamsDataView {
    public:
        ShareService_Share_ResponseParamsDataView() { }

        ShareService_Share_ResponseParamsDataView(
            internal::ShareService_Share_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetErrorDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadError(UserType* output)
        {
            auto* pointer = data_->error.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::ShareService_Share_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace blink

namespace std {

} // namespace std

namespace mojo {

} // namespace mojo

namespace blink {
namespace mojom {

    inline void ShareService_Share_ParamsDataView::GetTitleDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->title.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void ShareService_Share_ParamsDataView::GetTextDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->text.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void ShareService_Share_ParamsDataView::GetUrlDataView(
        ::url::mojom::UrlDataView* output)
    {
        auto pointer = data_->url.Get();
        *output = ::url::mojom::UrlDataView(pointer, context_);
    }

    inline void ShareService_Share_ResponseParamsDataView::GetErrorDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->error.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

} // namespace mojom
} // namespace blink

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_WEBSHARE_WEBSHARE_MOJOM_SHARED_H_
