// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_RENDER_MESSAGE_FILTER_MOJOM_SHARED_H_
#define CONTENT_COMMON_RENDER_MESSAGE_FILTER_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "content/common/native_types.mojom-shared.h"
#include "content/common/render_message_filter.mojom-shared-internal.h"
#include "content/public/common/window_container_type.mojom-shared.h"
#include "gpu/ipc/common/mailbox.mojom-shared.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "third_party/WebKit/public/platform/referrer.mojom-shared.h"
#include "third_party/WebKit/public/web/window_features.mojom-shared.h"
#include "ui/base/mojo/window_open_disposition.mojom-shared.h"
#include "url/mojo/url.mojom-shared.h"

namespace content {
namespace mojom {
    class CreateNewWindowParamsDataView;

    class CreateNewWindowReplyDataView;

} // namespace mojom
} // namespace content

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::content::mojom::CreateNewWindowParamsDataView> {
        using Data = ::content::mojom::internal::CreateNewWindowParams_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::content::mojom::CreateNewWindowReplyDataView> {
        using Data = ::content::mojom::internal::CreateNewWindowReply_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace content {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class RenderMessageFilterInterfaceBase {
    };

    using RenderMessageFilterPtrDataView = mojo::InterfacePtrDataView<RenderMessageFilterInterfaceBase>;
    using RenderMessageFilterRequestDataView = mojo::InterfaceRequestDataView<RenderMessageFilterInterfaceBase>;
    using RenderMessageFilterAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<RenderMessageFilterInterfaceBase>;
    using RenderMessageFilterAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<RenderMessageFilterInterfaceBase>;
    class CreateNewWindowParamsDataView {
    public:
        CreateNewWindowParamsDataView() { }

        CreateNewWindowParamsDataView(
            internal::CreateNewWindowParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        int32_t opener_render_frame_id() const
        {
            return data_->opener_render_frame_id;
        }
        bool user_gesture() const
        {
            return data_->user_gesture;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadWindowContainerType(UserType* output) const
        {
            auto data_value = data_->window_container_type;
            return mojo::internal::Deserialize<::content::mojom::WindowContainerType>(
                data_value, output);
        }

        ::content::mojom::WindowContainerType window_container_type() const
        {
            return static_cast<::content::mojom::WindowContainerType>(data_->window_container_type);
        }
        int64_t session_storage_namespace_id() const
        {
            return data_->session_storage_namespace_id;
        }
        inline void GetFrameNameDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFrameName(UserType* output)
        {
            auto* pointer = data_->frame_name.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetOpenerUrlDataView(
            ::url::mojom::UrlDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOpenerUrl(UserType* output)
        {
            auto* pointer = data_->opener_url.Get();
            return mojo::internal::Deserialize<::url::mojom::UrlDataView>(
                pointer, output, context_);
        }
        inline void GetOpenerTopLevelFrameUrlDataView(
            ::url::mojom::UrlDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOpenerTopLevelFrameUrl(UserType* output)
        {
            auto* pointer = data_->opener_top_level_frame_url.Get();
            return mojo::internal::Deserialize<::url::mojom::UrlDataView>(
                pointer, output, context_);
        }
        inline void GetOpenerSecurityOriginDataView(
            ::url::mojom::UrlDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOpenerSecurityOrigin(UserType* output)
        {
            auto* pointer = data_->opener_security_origin.Get();
            return mojo::internal::Deserialize<::url::mojom::UrlDataView>(
                pointer, output, context_);
        }
        bool opener_suppressed() const
        {
            return data_->opener_suppressed;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDisposition(UserType* output) const
        {
            auto data_value = data_->disposition;
            return mojo::internal::Deserialize<::ui::mojom::WindowOpenDisposition>(
                data_value, output);
        }

        ::ui::mojom::WindowOpenDisposition disposition() const
        {
            return static_cast<::ui::mojom::WindowOpenDisposition>(data_->disposition);
        }
        inline void GetTargetUrlDataView(
            ::url::mojom::UrlDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTargetUrl(UserType* output)
        {
            auto* pointer = data_->target_url.Get();
            return mojo::internal::Deserialize<::url::mojom::UrlDataView>(
                pointer, output, context_);
        }
        inline void GetReferrerDataView(
            ::blink::mojom::ReferrerDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadReferrer(UserType* output)
        {
            auto* pointer = data_->referrer.Get();
            return mojo::internal::Deserialize<::blink::mojom::ReferrerDataView>(
                pointer, output, context_);
        }
        inline void GetFeaturesDataView(
            ::blink::mojom::WindowFeaturesDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFeatures(UserType* output)
        {
            auto* pointer = data_->features.Get();
            return mojo::internal::Deserialize<::blink::mojom::WindowFeaturesDataView>(
                pointer, output, context_);
        }

    private:
        internal::CreateNewWindowParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class CreateNewWindowReplyDataView {
    public:
        CreateNewWindowReplyDataView() { }

        CreateNewWindowReplyDataView(
            internal::CreateNewWindowReply_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int32_t route_id() const
        {
            return data_->route_id;
        }
        int32_t main_frame_route_id() const
        {
            return data_->main_frame_route_id;
        }
        int32_t main_frame_widget_route_id() const
        {
            return data_->main_frame_widget_route_id;
        }
        int64_t cloned_session_storage_namespace_id() const
        {
            return data_->cloned_session_storage_namespace_id;
        }

    private:
        internal::CreateNewWindowReply_Data* data_ = nullptr;
    };

    class RenderMessageFilter_GenerateRoutingID_ParamsDataView {
    public:
        RenderMessageFilter_GenerateRoutingID_ParamsDataView() { }

        RenderMessageFilter_GenerateRoutingID_ParamsDataView(
            internal::RenderMessageFilter_GenerateRoutingID_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::RenderMessageFilter_GenerateRoutingID_Params_Data* data_ = nullptr;
    };

    class RenderMessageFilter_GenerateRoutingID_ResponseParamsDataView {
    public:
        RenderMessageFilter_GenerateRoutingID_ResponseParamsDataView() { }

        RenderMessageFilter_GenerateRoutingID_ResponseParamsDataView(
            internal::RenderMessageFilter_GenerateRoutingID_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int32_t routing_id() const
        {
            return data_->routing_id;
        }

    private:
        internal::RenderMessageFilter_GenerateRoutingID_ResponseParams_Data* data_ = nullptr;
    };

    class RenderMessageFilter_CreateNewWindow_ParamsDataView {
    public:
        RenderMessageFilter_CreateNewWindow_ParamsDataView() { }

        RenderMessageFilter_CreateNewWindow_ParamsDataView(
            internal::RenderMessageFilter_CreateNewWindow_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetParamsDataView(
            CreateNewWindowParamsDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadParams(UserType* output)
        {
            auto* pointer = data_->params.Get();
            return mojo::internal::Deserialize<::content::mojom::CreateNewWindowParamsDataView>(
                pointer, output, context_);
        }

    private:
        internal::RenderMessageFilter_CreateNewWindow_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class RenderMessageFilter_CreateNewWindow_ResponseParamsDataView {
    public:
        RenderMessageFilter_CreateNewWindow_ResponseParamsDataView() { }

        RenderMessageFilter_CreateNewWindow_ResponseParamsDataView(
            internal::RenderMessageFilter_CreateNewWindow_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetReplyDataView(
            CreateNewWindowReplyDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadReply(UserType* output)
        {
            auto* pointer = data_->reply.Get();
            return mojo::internal::Deserialize<::content::mojom::CreateNewWindowReplyDataView>(
                pointer, output, context_);
        }

    private:
        internal::RenderMessageFilter_CreateNewWindow_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class RenderMessageFilter_CreateNewWidget_ParamsDataView {
    public:
        RenderMessageFilter_CreateNewWidget_ParamsDataView() { }

        RenderMessageFilter_CreateNewWidget_ParamsDataView(
            internal::RenderMessageFilter_CreateNewWidget_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int32_t opener_id() const
        {
            return data_->opener_id;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPopupType(UserType* output) const
        {
            auto data_value = data_->popup_type;
            return mojo::internal::Deserialize<::content::mojom::WebPopupType>(
                data_value, output);
        }

        ::content::mojom::WebPopupType popup_type() const
        {
            return static_cast<::content::mojom::WebPopupType>(data_->popup_type);
        }

    private:
        internal::RenderMessageFilter_CreateNewWidget_Params_Data* data_ = nullptr;
    };

    class RenderMessageFilter_CreateNewWidget_ResponseParamsDataView {
    public:
        RenderMessageFilter_CreateNewWidget_ResponseParamsDataView() { }

        RenderMessageFilter_CreateNewWidget_ResponseParamsDataView(
            internal::RenderMessageFilter_CreateNewWidget_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int32_t route_id() const
        {
            return data_->route_id;
        }

    private:
        internal::RenderMessageFilter_CreateNewWidget_ResponseParams_Data* data_ = nullptr;
    };

    class RenderMessageFilter_CreateFullscreenWidget_ParamsDataView {
    public:
        RenderMessageFilter_CreateFullscreenWidget_ParamsDataView() { }

        RenderMessageFilter_CreateFullscreenWidget_ParamsDataView(
            internal::RenderMessageFilter_CreateFullscreenWidget_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int32_t opener_id() const
        {
            return data_->opener_id;
        }

    private:
        internal::RenderMessageFilter_CreateFullscreenWidget_Params_Data* data_ = nullptr;
    };

    class RenderMessageFilter_CreateFullscreenWidget_ResponseParamsDataView {
    public:
        RenderMessageFilter_CreateFullscreenWidget_ResponseParamsDataView() { }

        RenderMessageFilter_CreateFullscreenWidget_ResponseParamsDataView(
            internal::RenderMessageFilter_CreateFullscreenWidget_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int32_t route_id() const
        {
            return data_->route_id;
        }

    private:
        internal::RenderMessageFilter_CreateFullscreenWidget_ResponseParams_Data* data_ = nullptr;
    };

    class RenderMessageFilter_AllocatedSharedBitmap_ParamsDataView {
    public:
        RenderMessageFilter_AllocatedSharedBitmap_ParamsDataView() { }

        RenderMessageFilter_AllocatedSharedBitmap_ParamsDataView(
            internal::RenderMessageFilter_AllocatedSharedBitmap_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        mojo::ScopedSharedBufferHandle TakeBuffer()
        {
            mojo::ScopedSharedBufferHandle result;
            bool ret = mojo::internal::Deserialize<mojo::ScopedSharedBufferHandle>(
                &data_->buffer, &result, context_);
            DCHECK(ret);
            return result;
        }
        inline void GetIdDataView(
            ::gpu::mojom::MailboxDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadId(UserType* output)
        {
            auto* pointer = data_->id.Get();
            return mojo::internal::Deserialize<::gpu::mojom::MailboxDataView>(
                pointer, output, context_);
        }

    private:
        internal::RenderMessageFilter_AllocatedSharedBitmap_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class RenderMessageFilter_DeletedSharedBitmap_ParamsDataView {
    public:
        RenderMessageFilter_DeletedSharedBitmap_ParamsDataView() { }

        RenderMessageFilter_DeletedSharedBitmap_ParamsDataView(
            internal::RenderMessageFilter_DeletedSharedBitmap_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetIdDataView(
            ::gpu::mojom::MailboxDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadId(UserType* output)
        {
            auto* pointer = data_->id.Get();
            return mojo::internal::Deserialize<::gpu::mojom::MailboxDataView>(
                pointer, output, context_);
        }

    private:
        internal::RenderMessageFilter_DeletedSharedBitmap_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace content

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::content::mojom::CreateNewWindowParamsDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::content::mojom::CreateNewWindowParamsDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::content::mojom::internal::CreateNewWindowParams_Data);
            decltype(CallWithContext(Traits::frame_name, input, custom_context)) in_frame_name = CallWithContext(Traits::frame_name, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_frame_name, context);
            decltype(CallWithContext(Traits::opener_url, input, custom_context)) in_opener_url = CallWithContext(Traits::opener_url, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::url::mojom::UrlDataView>(
                in_opener_url, context);
            decltype(CallWithContext(Traits::opener_top_level_frame_url, input, custom_context)) in_opener_top_level_frame_url = CallWithContext(Traits::opener_top_level_frame_url, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::url::mojom::UrlDataView>(
                in_opener_top_level_frame_url, context);
            decltype(CallWithContext(Traits::opener_security_origin, input, custom_context)) in_opener_security_origin = CallWithContext(Traits::opener_security_origin, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::url::mojom::UrlDataView>(
                in_opener_security_origin, context);
            decltype(CallWithContext(Traits::target_url, input, custom_context)) in_target_url = CallWithContext(Traits::target_url, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::url::mojom::UrlDataView>(
                in_target_url, context);
            decltype(CallWithContext(Traits::referrer, input, custom_context)) in_referrer = CallWithContext(Traits::referrer, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::blink::mojom::ReferrerDataView>(
                in_referrer, context);
            decltype(CallWithContext(Traits::features, input, custom_context)) in_features = CallWithContext(Traits::features, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::blink::mojom::WindowFeaturesDataView>(
                in_features, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::content::mojom::internal::CreateNewWindowParams_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::content::mojom::internal::CreateNewWindowParams_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->opener_render_frame_id = CallWithContext(Traits::opener_render_frame_id, input, custom_context);
            result->user_gesture = CallWithContext(Traits::user_gesture, input, custom_context);
            mojo::internal::Serialize<::content::mojom::WindowContainerType>(
                CallWithContext(Traits::window_container_type, input, custom_context), &result->window_container_type);
            result->session_storage_namespace_id = CallWithContext(Traits::session_storage_namespace_id, input, custom_context);
            decltype(CallWithContext(Traits::frame_name, input, custom_context)) in_frame_name = CallWithContext(Traits::frame_name, input, custom_context);
            typename decltype(result->frame_name)::BaseType* frame_name_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_frame_name, buffer, &frame_name_ptr, context);
            result->frame_name.Set(frame_name_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->frame_name.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null frame_name in CreateNewWindowParams struct");
            decltype(CallWithContext(Traits::opener_url, input, custom_context)) in_opener_url = CallWithContext(Traits::opener_url, input, custom_context);
            typename decltype(result->opener_url)::BaseType* opener_url_ptr;
            mojo::internal::Serialize<::url::mojom::UrlDataView>(
                in_opener_url, buffer, &opener_url_ptr, context);
            result->opener_url.Set(opener_url_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->opener_url.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null opener_url in CreateNewWindowParams struct");
            decltype(CallWithContext(Traits::opener_top_level_frame_url, input, custom_context)) in_opener_top_level_frame_url = CallWithContext(Traits::opener_top_level_frame_url, input, custom_context);
            typename decltype(result->opener_top_level_frame_url)::BaseType* opener_top_level_frame_url_ptr;
            mojo::internal::Serialize<::url::mojom::UrlDataView>(
                in_opener_top_level_frame_url, buffer, &opener_top_level_frame_url_ptr, context);
            result->opener_top_level_frame_url.Set(opener_top_level_frame_url_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->opener_top_level_frame_url.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null opener_top_level_frame_url in CreateNewWindowParams struct");
            decltype(CallWithContext(Traits::opener_security_origin, input, custom_context)) in_opener_security_origin = CallWithContext(Traits::opener_security_origin, input, custom_context);
            typename decltype(result->opener_security_origin)::BaseType* opener_security_origin_ptr;
            mojo::internal::Serialize<::url::mojom::UrlDataView>(
                in_opener_security_origin, buffer, &opener_security_origin_ptr, context);
            result->opener_security_origin.Set(opener_security_origin_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->opener_security_origin.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null opener_security_origin in CreateNewWindowParams struct");
            result->opener_suppressed = CallWithContext(Traits::opener_suppressed, input, custom_context);
            mojo::internal::Serialize<::ui::mojom::WindowOpenDisposition>(
                CallWithContext(Traits::disposition, input, custom_context), &result->disposition);
            decltype(CallWithContext(Traits::target_url, input, custom_context)) in_target_url = CallWithContext(Traits::target_url, input, custom_context);
            typename decltype(result->target_url)::BaseType* target_url_ptr;
            mojo::internal::Serialize<::url::mojom::UrlDataView>(
                in_target_url, buffer, &target_url_ptr, context);
            result->target_url.Set(target_url_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->target_url.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null target_url in CreateNewWindowParams struct");
            decltype(CallWithContext(Traits::referrer, input, custom_context)) in_referrer = CallWithContext(Traits::referrer, input, custom_context);
            typename decltype(result->referrer)::BaseType* referrer_ptr;
            mojo::internal::Serialize<::blink::mojom::ReferrerDataView>(
                in_referrer, buffer, &referrer_ptr, context);
            result->referrer.Set(referrer_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->referrer.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null referrer in CreateNewWindowParams struct");
            decltype(CallWithContext(Traits::features, input, custom_context)) in_features = CallWithContext(Traits::features, input, custom_context);
            typename decltype(result->features)::BaseType* features_ptr;
            mojo::internal::Serialize<::blink::mojom::WindowFeaturesDataView>(
                in_features, buffer, &features_ptr, context);
            result->features.Set(features_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->features.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null features in CreateNewWindowParams struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::content::mojom::internal::CreateNewWindowParams_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::content::mojom::CreateNewWindowParamsDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::content::mojom::CreateNewWindowReplyDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::content::mojom::CreateNewWindowReplyDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::content::mojom::internal::CreateNewWindowReply_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::content::mojom::internal::CreateNewWindowReply_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::content::mojom::internal::CreateNewWindowReply_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->route_id = CallWithContext(Traits::route_id, input, custom_context);
            result->main_frame_route_id = CallWithContext(Traits::main_frame_route_id, input, custom_context);
            result->main_frame_widget_route_id = CallWithContext(Traits::main_frame_widget_route_id, input, custom_context);
            result->cloned_session_storage_namespace_id = CallWithContext(Traits::cloned_session_storage_namespace_id, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::content::mojom::internal::CreateNewWindowReply_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::content::mojom::CreateNewWindowReplyDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace content {
namespace mojom {

    inline void CreateNewWindowParamsDataView::GetFrameNameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->frame_name.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void CreateNewWindowParamsDataView::GetOpenerUrlDataView(
        ::url::mojom::UrlDataView* output)
    {
        auto pointer = data_->opener_url.Get();
        *output = ::url::mojom::UrlDataView(pointer, context_);
    }
    inline void CreateNewWindowParamsDataView::GetOpenerTopLevelFrameUrlDataView(
        ::url::mojom::UrlDataView* output)
    {
        auto pointer = data_->opener_top_level_frame_url.Get();
        *output = ::url::mojom::UrlDataView(pointer, context_);
    }
    inline void CreateNewWindowParamsDataView::GetOpenerSecurityOriginDataView(
        ::url::mojom::UrlDataView* output)
    {
        auto pointer = data_->opener_security_origin.Get();
        *output = ::url::mojom::UrlDataView(pointer, context_);
    }
    inline void CreateNewWindowParamsDataView::GetTargetUrlDataView(
        ::url::mojom::UrlDataView* output)
    {
        auto pointer = data_->target_url.Get();
        *output = ::url::mojom::UrlDataView(pointer, context_);
    }
    inline void CreateNewWindowParamsDataView::GetReferrerDataView(
        ::blink::mojom::ReferrerDataView* output)
    {
        auto pointer = data_->referrer.Get();
        *output = ::blink::mojom::ReferrerDataView(pointer, context_);
    }
    inline void CreateNewWindowParamsDataView::GetFeaturesDataView(
        ::blink::mojom::WindowFeaturesDataView* output)
    {
        auto pointer = data_->features.Get();
        *output = ::blink::mojom::WindowFeaturesDataView(pointer, context_);
    }

    inline void RenderMessageFilter_CreateNewWindow_ParamsDataView::GetParamsDataView(
        CreateNewWindowParamsDataView* output)
    {
        auto pointer = data_->params.Get();
        *output = CreateNewWindowParamsDataView(pointer, context_);
    }

    inline void RenderMessageFilter_CreateNewWindow_ResponseParamsDataView::GetReplyDataView(
        CreateNewWindowReplyDataView* output)
    {
        auto pointer = data_->reply.Get();
        *output = CreateNewWindowReplyDataView(pointer, context_);
    }

    inline void RenderMessageFilter_AllocatedSharedBitmap_ParamsDataView::GetIdDataView(
        ::gpu::mojom::MailboxDataView* output)
    {
        auto pointer = data_->id.Get();
        *output = ::gpu::mojom::MailboxDataView(pointer, context_);
    }

    inline void RenderMessageFilter_DeletedSharedBitmap_ParamsDataView::GetIdDataView(
        ::gpu::mojom::MailboxDataView* output)
    {
        auto pointer = data_->id.Get();
        *output = ::gpu::mojom::MailboxDataView(pointer, context_);
    }

} // namespace mojom
} // namespace content

#endif // CONTENT_COMMON_RENDER_MESSAGE_FILTER_MOJOM_SHARED_H_
