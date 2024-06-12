// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_RENDER_FRAME_MESSAGE_FILTER_MOJOM_SHARED_H_
#define CONTENT_COMMON_RENDER_FRAME_MESSAGE_FILTER_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "content/common/render_frame_message_filter.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "url/mojo/url.mojom-shared.h"

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
    class RenderFrameMessageFilterInterfaceBase {
    };

    using RenderFrameMessageFilterPtrDataView = mojo::InterfacePtrDataView<RenderFrameMessageFilterInterfaceBase>;
    using RenderFrameMessageFilterRequestDataView = mojo::InterfaceRequestDataView<RenderFrameMessageFilterInterfaceBase>;
    using RenderFrameMessageFilterAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<RenderFrameMessageFilterInterfaceBase>;
    using RenderFrameMessageFilterAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<RenderFrameMessageFilterInterfaceBase>;
    class RenderFrameMessageFilter_SetCookie_ParamsDataView {
    public:
        RenderFrameMessageFilter_SetCookie_ParamsDataView() { }

        RenderFrameMessageFilter_SetCookie_ParamsDataView(
            internal::RenderFrameMessageFilter_SetCookie_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        int32_t render_frame_id() const
        {
            return data_->render_frame_id;
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
        inline void GetFirstPartyForCookiesDataView(
            ::url::mojom::UrlDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFirstPartyForCookies(UserType* output)
        {
            auto* pointer = data_->first_party_for_cookies.Get();
            return mojo::internal::Deserialize<::url::mojom::UrlDataView>(
                pointer, output, context_);
        }
        inline void GetCookieDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadCookie(UserType* output)
        {
            auto* pointer = data_->cookie.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::RenderFrameMessageFilter_SetCookie_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class RenderFrameMessageFilter_GetCookies_ParamsDataView {
    public:
        RenderFrameMessageFilter_GetCookies_ParamsDataView() { }

        RenderFrameMessageFilter_GetCookies_ParamsDataView(
            internal::RenderFrameMessageFilter_GetCookies_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        int32_t render_frame_id() const
        {
            return data_->render_frame_id;
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
        inline void GetFirstPartyForCookiesDataView(
            ::url::mojom::UrlDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFirstPartyForCookies(UserType* output)
        {
            auto* pointer = data_->first_party_for_cookies.Get();
            return mojo::internal::Deserialize<::url::mojom::UrlDataView>(
                pointer, output, context_);
        }

    private:
        internal::RenderFrameMessageFilter_GetCookies_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class RenderFrameMessageFilter_GetCookies_ResponseParamsDataView {
    public:
        RenderFrameMessageFilter_GetCookies_ResponseParamsDataView() { }

        RenderFrameMessageFilter_GetCookies_ResponseParamsDataView(
            internal::RenderFrameMessageFilter_GetCookies_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetCookiesDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadCookies(UserType* output)
        {
            auto* pointer = data_->cookies.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::RenderFrameMessageFilter_GetCookies_ResponseParams_Data* data_ = nullptr;
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

    inline void RenderFrameMessageFilter_SetCookie_ParamsDataView::GetUrlDataView(
        ::url::mojom::UrlDataView* output)
    {
        auto pointer = data_->url.Get();
        *output = ::url::mojom::UrlDataView(pointer, context_);
    }
    inline void RenderFrameMessageFilter_SetCookie_ParamsDataView::GetFirstPartyForCookiesDataView(
        ::url::mojom::UrlDataView* output)
    {
        auto pointer = data_->first_party_for_cookies.Get();
        *output = ::url::mojom::UrlDataView(pointer, context_);
    }
    inline void RenderFrameMessageFilter_SetCookie_ParamsDataView::GetCookieDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->cookie.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void RenderFrameMessageFilter_GetCookies_ParamsDataView::GetUrlDataView(
        ::url::mojom::UrlDataView* output)
    {
        auto pointer = data_->url.Get();
        *output = ::url::mojom::UrlDataView(pointer, context_);
    }
    inline void RenderFrameMessageFilter_GetCookies_ParamsDataView::GetFirstPartyForCookiesDataView(
        ::url::mojom::UrlDataView* output)
    {
        auto pointer = data_->first_party_for_cookies.Get();
        *output = ::url::mojom::UrlDataView(pointer, context_);
    }

    inline void RenderFrameMessageFilter_GetCookies_ResponseParamsDataView::GetCookiesDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->cookies.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

} // namespace mojom
} // namespace content

#endif // CONTENT_COMMON_RENDER_FRAME_MESSAGE_FILTER_MOJOM_SHARED_H_
