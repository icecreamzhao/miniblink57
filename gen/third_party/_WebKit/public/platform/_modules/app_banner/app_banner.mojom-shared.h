// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_APP_BANNER_APP_BANNER_MOJOM_SHARED_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_APP_BANNER_APP_BANNER_MOJOM_SHARED_H_

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
#include "third_party/WebKit/public/platform/modules/app_banner/app_banner.mojom-shared-internal.h"

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

    enum class AppBannerPromptReply : int32_t {
        NONE,
        CANCEL,
    };

    inline std::ostream& operator<<(std::ostream& os, AppBannerPromptReply value)
    {
        switch (value) {
        case AppBannerPromptReply::NONE:
            return os << "AppBannerPromptReply::NONE";
        case AppBannerPromptReply::CANCEL:
            return os << "AppBannerPromptReply::CANCEL";
        default:
            return os << "Unknown AppBannerPromptReply value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(AppBannerPromptReply value)
    {
        return internal::AppBannerPromptReply_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    // Interface base classes. They are used for type safety check.
    class AppBannerControllerInterfaceBase {
    };

    using AppBannerControllerPtrDataView = mojo::InterfacePtrDataView<AppBannerControllerInterfaceBase>;
    using AppBannerControllerRequestDataView = mojo::InterfaceRequestDataView<AppBannerControllerInterfaceBase>;
    using AppBannerControllerAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<AppBannerControllerInterfaceBase>;
    using AppBannerControllerAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<AppBannerControllerInterfaceBase>;
    class AppBannerEventInterfaceBase {
    };

    using AppBannerEventPtrDataView = mojo::InterfacePtrDataView<AppBannerEventInterfaceBase>;
    using AppBannerEventRequestDataView = mojo::InterfaceRequestDataView<AppBannerEventInterfaceBase>;
    using AppBannerEventAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<AppBannerEventInterfaceBase>;
    using AppBannerEventAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<AppBannerEventInterfaceBase>;
    class AppBannerServiceInterfaceBase {
    };

    using AppBannerServicePtrDataView = mojo::InterfacePtrDataView<AppBannerServiceInterfaceBase>;
    using AppBannerServiceRequestDataView = mojo::InterfaceRequestDataView<AppBannerServiceInterfaceBase>;
    using AppBannerServiceAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<AppBannerServiceInterfaceBase>;
    using AppBannerServiceAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<AppBannerServiceInterfaceBase>;
    class AppBannerController_BannerPromptRequest_ParamsDataView {
    public:
        AppBannerController_BannerPromptRequest_ParamsDataView() { }

        AppBannerController_BannerPromptRequest_ParamsDataView(
            internal::AppBannerController_BannerPromptRequest_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeService()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::blink::mojom::AppBannerServicePtrDataView>(
                &data_->service, &result, context_);
            DCHECK(ret);
            return result;
        }
        template <typename UserType>
        UserType TakeEvent()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::blink::mojom::AppBannerEventRequestDataView>(
                &data_->event, &result, context_);
            DCHECK(ret);
            return result;
        }
        inline void GetPlatformDataView(
            mojo::ArrayDataView<mojo::StringDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPlatform(UserType* output)
        {
            auto* pointer = data_->platform.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<mojo::StringDataView>>(
                pointer, output, context_);
        }

    private:
        internal::AppBannerController_BannerPromptRequest_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class AppBannerController_BannerPromptRequest_ResponseParamsDataView {
    public:
        AppBannerController_BannerPromptRequest_ResponseParamsDataView() { }

        AppBannerController_BannerPromptRequest_ResponseParamsDataView(
            internal::AppBannerController_BannerPromptRequest_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadReply(UserType* output) const
        {
            auto data_value = data_->reply;
            return mojo::internal::Deserialize<::blink::mojom::AppBannerPromptReply>(
                data_value, output);
        }

        AppBannerPromptReply reply() const
        {
            return static_cast<AppBannerPromptReply>(data_->reply);
        }
        inline void GetReferrerDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadReferrer(UserType* output)
        {
            auto* pointer = data_->referrer.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::AppBannerController_BannerPromptRequest_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class AppBannerEvent_BannerAccepted_ParamsDataView {
    public:
        AppBannerEvent_BannerAccepted_ParamsDataView() { }

        AppBannerEvent_BannerAccepted_ParamsDataView(
            internal::AppBannerEvent_BannerAccepted_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetPlatformDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPlatform(UserType* output)
        {
            auto* pointer = data_->platform.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::AppBannerEvent_BannerAccepted_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class AppBannerEvent_BannerDismissed_ParamsDataView {
    public:
        AppBannerEvent_BannerDismissed_ParamsDataView() { }

        AppBannerEvent_BannerDismissed_ParamsDataView(
            internal::AppBannerEvent_BannerDismissed_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::AppBannerEvent_BannerDismissed_Params_Data* data_ = nullptr;
    };

    class AppBannerService_DisplayAppBanner_ParamsDataView {
    public:
        AppBannerService_DisplayAppBanner_ParamsDataView() { }

        AppBannerService_DisplayAppBanner_ParamsDataView(
            internal::AppBannerService_DisplayAppBanner_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::AppBannerService_DisplayAppBanner_Params_Data* data_ = nullptr;
    };

} // namespace mojom
} // namespace blink

namespace std {

template <>
struct hash<::blink::mojom::AppBannerPromptReply>
    : public mojo::internal::EnumHashImpl<::blink::mojom::AppBannerPromptReply> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::blink::mojom::AppBannerPromptReply, ::blink::mojom::AppBannerPromptReply> {
    static ::blink::mojom::AppBannerPromptReply ToMojom(::blink::mojom::AppBannerPromptReply input) { return input; }
    static bool FromMojom(::blink::mojom::AppBannerPromptReply input, ::blink::mojom::AppBannerPromptReply* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::blink::mojom::AppBannerPromptReply, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::blink::mojom::AppBannerPromptReply, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::blink::mojom::AppBannerPromptReply>(input), output);
        }
    };

} // namespace internal

} // namespace mojo

namespace blink {
namespace mojom {

    inline void AppBannerController_BannerPromptRequest_ParamsDataView::GetPlatformDataView(
        mojo::ArrayDataView<mojo::StringDataView>* output)
    {
        auto pointer = data_->platform.Get();
        *output = mojo::ArrayDataView<mojo::StringDataView>(pointer, context_);
    }

    inline void AppBannerController_BannerPromptRequest_ResponseParamsDataView::GetReferrerDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->referrer.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void AppBannerEvent_BannerAccepted_ParamsDataView::GetPlatformDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->platform.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

} // namespace mojom
} // namespace blink

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_APP_BANNER_APP_BANNER_MOJOM_SHARED_H_
