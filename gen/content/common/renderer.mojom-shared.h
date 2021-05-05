// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CONTENT_COMMON_RENDERER_MOJOM_SHARED_H_
#define CONTENT_COMMON_RENDERER_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "content/common/native_types.mojom-shared.h"
#include "content/common/renderer.mojom-shared-internal.h"
#include "ipc/ipc.mojom-shared.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared.h"
#include "ui/gfx/mojo/icc_profile.mojom-shared.h"

namespace content {
namespace mojom {
    class CreateViewParamsDataView;

    class CreateFrameWidgetParamsDataView;

    class CreateFrameParamsDataView;

    class UpdateScrollbarThemeParamsDataView;

} // namespace mojom
} // namespace content

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::content::mojom::CreateViewParamsDataView> {
        using Data = ::content::mojom::internal::CreateViewParams_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::content::mojom::CreateFrameWidgetParamsDataView> {
        using Data = ::content::mojom::internal::CreateFrameWidgetParams_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::content::mojom::CreateFrameParamsDataView> {
        using Data = ::content::mojom::internal::CreateFrameParams_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::content::mojom::UpdateScrollbarThemeParamsDataView> {
        using Data = ::content::mojom::internal::UpdateScrollbarThemeParams_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace content {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class RendererInterfaceBase {
    };

    using RendererPtrDataView = mojo::InterfacePtrDataView<RendererInterfaceBase>;
    using RendererRequestDataView = mojo::InterfaceRequestDataView<RendererInterfaceBase>;
    using RendererAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<RendererInterfaceBase>;
    using RendererAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<RendererInterfaceBase>;
    class CreateViewParamsDataView {
    public:
        CreateViewParamsDataView() { }

        CreateViewParamsDataView(
            internal::CreateViewParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetRendererPreferencesDataView(
            ::content::mojom::RendererPreferencesDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadRendererPreferences(UserType* output)
        {
            auto* pointer = data_->renderer_preferences.Get();
            return mojo::internal::Deserialize<::content::mojom::RendererPreferencesDataView>(
                pointer, output, context_);
        }
        inline void GetWebPreferencesDataView(
            ::content::mojom::WebPreferencesDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadWebPreferences(UserType* output)
        {
            auto* pointer = data_->web_preferences.Get();
            return mojo::internal::Deserialize<::content::mojom::WebPreferencesDataView>(
                pointer, output, context_);
        }
        int32_t view_id() const
        {
            return data_->view_id;
        }
        int32_t main_frame_routing_id() const
        {
            return data_->main_frame_routing_id;
        }
        int32_t main_frame_widget_routing_id() const
        {
            return data_->main_frame_widget_routing_id;
        }
        int64_t session_storage_namespace_id() const
        {
            return data_->session_storage_namespace_id;
        }
        int32_t opener_frame_route_id() const
        {
            return data_->opener_frame_route_id;
        }
        bool swapped_out() const
        {
            return data_->swapped_out;
        }
        inline void GetReplicatedFrameStateDataView(
            ::content::mojom::FrameReplicationStateDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadReplicatedFrameState(UserType* output)
        {
            auto* pointer = data_->replicated_frame_state.Get();
            return mojo::internal::Deserialize<::content::mojom::FrameReplicationStateDataView>(
                pointer, output, context_);
        }
        int32_t proxy_routing_id() const
        {
            return data_->proxy_routing_id;
        }
        bool hidden() const
        {
            return data_->hidden;
        }
        bool never_visible() const
        {
            return data_->never_visible;
        }
        bool window_was_created_with_opener() const
        {
            return data_->window_was_created_with_opener;
        }
        inline void GetInitialSizeDataView(
            ::content::mojom::ResizeParamsDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadInitialSize(UserType* output)
        {
            auto* pointer = data_->initial_size.Get();
            return mojo::internal::Deserialize<::content::mojom::ResizeParamsDataView>(
                pointer, output, context_);
        }
        bool enable_auto_resize() const
        {
            return data_->enable_auto_resize;
        }
        inline void GetMinSizeDataView(
            ::gfx::mojom::SizeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMinSize(UserType* output)
        {
            auto* pointer = data_->min_size.Get();
            return mojo::internal::Deserialize<::gfx::mojom::SizeDataView>(
                pointer, output, context_);
        }
        inline void GetMaxSizeDataView(
            ::gfx::mojom::SizeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMaxSize(UserType* output)
        {
            auto* pointer = data_->max_size.Get();
            return mojo::internal::Deserialize<::gfx::mojom::SizeDataView>(
                pointer, output, context_);
        }
        double page_zoom_level() const
        {
            return data_->page_zoom_level;
        }
        inline void GetImageDecodeColorSpaceDataView(
            ::gfx::mojom::ICCProfileDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadImageDecodeColorSpace(UserType* output)
        {
            auto* pointer = data_->image_decode_color_space.Get();
            return mojo::internal::Deserialize<::gfx::mojom::ICCProfileDataView>(
                pointer, output, context_);
        }

    private:
        internal::CreateViewParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class CreateFrameWidgetParamsDataView {
    public:
        CreateFrameWidgetParamsDataView() { }

        CreateFrameWidgetParamsDataView(
            internal::CreateFrameWidgetParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int32_t routing_id() const
        {
            return data_->routing_id;
        }
        bool hidden() const
        {
            return data_->hidden;
        }

    private:
        internal::CreateFrameWidgetParams_Data* data_ = nullptr;
    };

    class CreateFrameParamsDataView {
    public:
        CreateFrameParamsDataView() { }

        CreateFrameParamsDataView(
            internal::CreateFrameParams_Data* data,
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
        int32_t proxy_routing_id() const
        {
            return data_->proxy_routing_id;
        }
        int32_t opener_routing_id() const
        {
            return data_->opener_routing_id;
        }
        int32_t parent_routing_id() const
        {
            return data_->parent_routing_id;
        }
        int32_t previous_sibling_routing_id() const
        {
            return data_->previous_sibling_routing_id;
        }
        inline void GetReplicationStateDataView(
            ::content::mojom::FrameReplicationStateDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadReplicationState(UserType* output)
        {
            auto* pointer = data_->replication_state.Get();
            return mojo::internal::Deserialize<::content::mojom::FrameReplicationStateDataView>(
                pointer, output, context_);
        }
        inline void GetFrameOwnerPropertiesDataView(
            ::content::mojom::FrameOwnerPropertiesDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFrameOwnerProperties(UserType* output)
        {
            auto* pointer = data_->frame_owner_properties.Get();
            return mojo::internal::Deserialize<::content::mojom::FrameOwnerPropertiesDataView>(
                pointer, output, context_);
        }
        inline void GetWidgetParamsDataView(
            CreateFrameWidgetParamsDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadWidgetParams(UserType* output)
        {
            auto* pointer = data_->widget_params.Get();
            return mojo::internal::Deserialize<::content::mojom::CreateFrameWidgetParamsDataView>(
                pointer, output, context_);
        }

    private:
        internal::CreateFrameParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class UpdateScrollbarThemeParamsDataView {
    public:
        UpdateScrollbarThemeParamsDataView() { }

        UpdateScrollbarThemeParamsDataView(
            internal::UpdateScrollbarThemeParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        float initial_button_delay() const
        {
            return data_->initial_button_delay;
        }
        float autoscroll_button_delay() const
        {
            return data_->autoscroll_button_delay;
        }
        bool jump_on_track_click() const
        {
            return data_->jump_on_track_click;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPreferredScrollerStyle(UserType* output) const
        {
            auto data_value = data_->preferred_scroller_style;
            return mojo::internal::Deserialize<::content::mojom::ScrollerStyle>(
                data_value, output);
        }

        ::content::mojom::ScrollerStyle preferred_scroller_style() const
        {
            return static_cast<::content::mojom::ScrollerStyle>(data_->preferred_scroller_style);
        }
        bool redraw() const
        {
            return data_->redraw;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadButtonPlacement(UserType* output) const
        {
            auto data_value = data_->button_placement;
            return mojo::internal::Deserialize<::content::mojom::ScrollbarButtonsPlacement>(
                data_value, output);
        }

        ::content::mojom::ScrollbarButtonsPlacement button_placement() const
        {
            return static_cast<::content::mojom::ScrollbarButtonsPlacement>(data_->button_placement);
        }

    private:
        internal::UpdateScrollbarThemeParams_Data* data_ = nullptr;
    };

    class Renderer_CreateView_ParamsDataView {
    public:
        Renderer_CreateView_ParamsDataView() { }

        Renderer_CreateView_ParamsDataView(
            internal::Renderer_CreateView_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetParamsDataView(
            CreateViewParamsDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadParams(UserType* output)
        {
            auto* pointer = data_->params.Get();
            return mojo::internal::Deserialize<::content::mojom::CreateViewParamsDataView>(
                pointer, output, context_);
        }

    private:
        internal::Renderer_CreateView_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Renderer_CreateFrame_ParamsDataView {
    public:
        Renderer_CreateFrame_ParamsDataView() { }

        Renderer_CreateFrame_ParamsDataView(
            internal::Renderer_CreateFrame_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetParamsDataView(
            CreateFrameParamsDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadParams(UserType* output)
        {
            auto* pointer = data_->params.Get();
            return mojo::internal::Deserialize<::content::mojom::CreateFrameParamsDataView>(
                pointer, output, context_);
        }

    private:
        internal::Renderer_CreateFrame_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Renderer_CreateFrameProxy_ParamsDataView {
    public:
        Renderer_CreateFrameProxy_ParamsDataView() { }

        Renderer_CreateFrameProxy_ParamsDataView(
            internal::Renderer_CreateFrameProxy_Params_Data* data,
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
        int32_t render_view_routing_id() const
        {
            return data_->render_view_routing_id;
        }
        int32_t opener_routing_id() const
        {
            return data_->opener_routing_id;
        }
        int32_t parent_routing_id() const
        {
            return data_->parent_routing_id;
        }
        inline void GetReplicationStateDataView(
            ::content::mojom::FrameReplicationStateDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadReplicationState(UserType* output)
        {
            auto* pointer = data_->replication_state.Get();
            return mojo::internal::Deserialize<::content::mojom::FrameReplicationStateDataView>(
                pointer, output, context_);
        }

    private:
        internal::Renderer_CreateFrameProxy_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Renderer_OnNetworkConnectionChanged_ParamsDataView {
    public:
        Renderer_OnNetworkConnectionChanged_ParamsDataView() { }

        Renderer_OnNetworkConnectionChanged_ParamsDataView(
            internal::Renderer_OnNetworkConnectionChanged_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadConnectionType(UserType* output) const
        {
            auto data_value = data_->connection_type;
            return mojo::internal::Deserialize<::content::mojom::NetworkConnectionType>(
                data_value, output);
        }

        ::content::mojom::NetworkConnectionType connection_type() const
        {
            return static_cast<::content::mojom::NetworkConnectionType>(data_->connection_type);
        }
        double max_bandwidth_mbps() const
        {
            return data_->max_bandwidth_mbps;
        }

    private:
        internal::Renderer_OnNetworkConnectionChanged_Params_Data* data_ = nullptr;
    };

    class Renderer_SetWebKitSharedTimersSuspended_ParamsDataView {
    public:
        Renderer_SetWebKitSharedTimersSuspended_ParamsDataView() { }

        Renderer_SetWebKitSharedTimersSuspended_ParamsDataView(
            internal::Renderer_SetWebKitSharedTimersSuspended_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool suspend() const
        {
            return data_->suspend;
        }

    private:
        internal::Renderer_SetWebKitSharedTimersSuspended_Params_Data* data_ = nullptr;
    };

    class Renderer_UpdateScrollbarTheme_ParamsDataView {
    public:
        Renderer_UpdateScrollbarTheme_ParamsDataView() { }

        Renderer_UpdateScrollbarTheme_ParamsDataView(
            internal::Renderer_UpdateScrollbarTheme_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetParamsDataView(
            UpdateScrollbarThemeParamsDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadParams(UserType* output)
        {
            auto* pointer = data_->params.Get();
            return mojo::internal::Deserialize<::content::mojom::UpdateScrollbarThemeParamsDataView>(
                pointer, output, context_);
        }

    private:
        internal::Renderer_UpdateScrollbarTheme_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Renderer_OnSystemColorsChanged_ParamsDataView {
    public:
        Renderer_OnSystemColorsChanged_ParamsDataView() { }

        Renderer_OnSystemColorsChanged_ParamsDataView(
            internal::Renderer_OnSystemColorsChanged_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        int32_t aqua_color_variant() const
        {
            return data_->aqua_color_variant;
        }
        inline void GetHighlightTextColorDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadHighlightTextColor(UserType* output)
        {
            auto* pointer = data_->highlight_text_color.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetHighlightColorDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadHighlightColor(UserType* output)
        {
            auto* pointer = data_->highlight_color.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::Renderer_OnSystemColorsChanged_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Renderer_PurgePluginListCache_ParamsDataView {
    public:
        Renderer_PurgePluginListCache_ParamsDataView() { }

        Renderer_PurgePluginListCache_ParamsDataView(
            internal::Renderer_PurgePluginListCache_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool reload_pages() const
        {
            return data_->reload_pages;
        }

    private:
        internal::Renderer_PurgePluginListCache_Params_Data* data_ = nullptr;
    };

} // namespace mojom
} // namespace content

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::content::mojom::CreateViewParamsDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::content::mojom::CreateViewParamsDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::content::mojom::internal::CreateViewParams_Data);
            decltype(CallWithContext(Traits::renderer_preferences, input, custom_context)) in_renderer_preferences = CallWithContext(Traits::renderer_preferences, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::content::mojom::RendererPreferencesDataView>(
                in_renderer_preferences, context);
            decltype(CallWithContext(Traits::web_preferences, input, custom_context)) in_web_preferences = CallWithContext(Traits::web_preferences, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::content::mojom::WebPreferencesDataView>(
                in_web_preferences, context);
            decltype(CallWithContext(Traits::replicated_frame_state, input, custom_context)) in_replicated_frame_state = CallWithContext(Traits::replicated_frame_state, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::content::mojom::FrameReplicationStateDataView>(
                in_replicated_frame_state, context);
            decltype(CallWithContext(Traits::initial_size, input, custom_context)) in_initial_size = CallWithContext(Traits::initial_size, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::content::mojom::ResizeParamsDataView>(
                in_initial_size, context);
            decltype(CallWithContext(Traits::min_size, input, custom_context)) in_min_size = CallWithContext(Traits::min_size, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::SizeDataView>(
                in_min_size, context);
            decltype(CallWithContext(Traits::max_size, input, custom_context)) in_max_size = CallWithContext(Traits::max_size, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::SizeDataView>(
                in_max_size, context);
            decltype(CallWithContext(Traits::image_decode_color_space, input, custom_context)) in_image_decode_color_space = CallWithContext(Traits::image_decode_color_space, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::gfx::mojom::ICCProfileDataView>(
                in_image_decode_color_space, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::content::mojom::internal::CreateViewParams_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::content::mojom::internal::CreateViewParams_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::renderer_preferences, input, custom_context)) in_renderer_preferences = CallWithContext(Traits::renderer_preferences, input, custom_context);
            typename decltype(result->renderer_preferences)::BaseType* renderer_preferences_ptr;
            mojo::internal::Serialize<::content::mojom::RendererPreferencesDataView>(
                in_renderer_preferences, buffer, &renderer_preferences_ptr, context);
            result->renderer_preferences.Set(renderer_preferences_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->renderer_preferences.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null renderer_preferences in CreateViewParams struct");
            decltype(CallWithContext(Traits::web_preferences, input, custom_context)) in_web_preferences = CallWithContext(Traits::web_preferences, input, custom_context);
            typename decltype(result->web_preferences)::BaseType* web_preferences_ptr;
            mojo::internal::Serialize<::content::mojom::WebPreferencesDataView>(
                in_web_preferences, buffer, &web_preferences_ptr, context);
            result->web_preferences.Set(web_preferences_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->web_preferences.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null web_preferences in CreateViewParams struct");
            result->view_id = CallWithContext(Traits::view_id, input, custom_context);
            result->main_frame_routing_id = CallWithContext(Traits::main_frame_routing_id, input, custom_context);
            result->main_frame_widget_routing_id = CallWithContext(Traits::main_frame_widget_routing_id, input, custom_context);
            result->session_storage_namespace_id = CallWithContext(Traits::session_storage_namespace_id, input, custom_context);
            result->opener_frame_route_id = CallWithContext(Traits::opener_frame_route_id, input, custom_context);
            result->swapped_out = CallWithContext(Traits::swapped_out, input, custom_context);
            decltype(CallWithContext(Traits::replicated_frame_state, input, custom_context)) in_replicated_frame_state = CallWithContext(Traits::replicated_frame_state, input, custom_context);
            typename decltype(result->replicated_frame_state)::BaseType* replicated_frame_state_ptr;
            mojo::internal::Serialize<::content::mojom::FrameReplicationStateDataView>(
                in_replicated_frame_state, buffer, &replicated_frame_state_ptr, context);
            result->replicated_frame_state.Set(replicated_frame_state_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->replicated_frame_state.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null replicated_frame_state in CreateViewParams struct");
            result->proxy_routing_id = CallWithContext(Traits::proxy_routing_id, input, custom_context);
            result->hidden = CallWithContext(Traits::hidden, input, custom_context);
            result->never_visible = CallWithContext(Traits::never_visible, input, custom_context);
            result->window_was_created_with_opener = CallWithContext(Traits::window_was_created_with_opener, input, custom_context);
            decltype(CallWithContext(Traits::initial_size, input, custom_context)) in_initial_size = CallWithContext(Traits::initial_size, input, custom_context);
            typename decltype(result->initial_size)::BaseType* initial_size_ptr;
            mojo::internal::Serialize<::content::mojom::ResizeParamsDataView>(
                in_initial_size, buffer, &initial_size_ptr, context);
            result->initial_size.Set(initial_size_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->initial_size.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null initial_size in CreateViewParams struct");
            result->enable_auto_resize = CallWithContext(Traits::enable_auto_resize, input, custom_context);
            decltype(CallWithContext(Traits::min_size, input, custom_context)) in_min_size = CallWithContext(Traits::min_size, input, custom_context);
            typename decltype(result->min_size)::BaseType* min_size_ptr;
            mojo::internal::Serialize<::gfx::mojom::SizeDataView>(
                in_min_size, buffer, &min_size_ptr, context);
            result->min_size.Set(min_size_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->min_size.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null min_size in CreateViewParams struct");
            decltype(CallWithContext(Traits::max_size, input, custom_context)) in_max_size = CallWithContext(Traits::max_size, input, custom_context);
            typename decltype(result->max_size)::BaseType* max_size_ptr;
            mojo::internal::Serialize<::gfx::mojom::SizeDataView>(
                in_max_size, buffer, &max_size_ptr, context);
            result->max_size.Set(max_size_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->max_size.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null max_size in CreateViewParams struct");
            result->page_zoom_level = CallWithContext(Traits::page_zoom_level, input, custom_context);
            decltype(CallWithContext(Traits::image_decode_color_space, input, custom_context)) in_image_decode_color_space = CallWithContext(Traits::image_decode_color_space, input, custom_context);
            typename decltype(result->image_decode_color_space)::BaseType* image_decode_color_space_ptr;
            mojo::internal::Serialize<::gfx::mojom::ICCProfileDataView>(
                in_image_decode_color_space, buffer, &image_decode_color_space_ptr, context);
            result->image_decode_color_space.Set(image_decode_color_space_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->image_decode_color_space.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null image_decode_color_space in CreateViewParams struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::content::mojom::internal::CreateViewParams_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::content::mojom::CreateViewParamsDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::content::mojom::CreateFrameWidgetParamsDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::content::mojom::CreateFrameWidgetParamsDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::content::mojom::internal::CreateFrameWidgetParams_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::content::mojom::internal::CreateFrameWidgetParams_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::content::mojom::internal::CreateFrameWidgetParams_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->routing_id = CallWithContext(Traits::routing_id, input, custom_context);
            result->hidden = CallWithContext(Traits::hidden, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::content::mojom::internal::CreateFrameWidgetParams_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::content::mojom::CreateFrameWidgetParamsDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::content::mojom::CreateFrameParamsDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::content::mojom::CreateFrameParamsDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::content::mojom::internal::CreateFrameParams_Data);
            decltype(CallWithContext(Traits::replication_state, input, custom_context)) in_replication_state = CallWithContext(Traits::replication_state, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::content::mojom::FrameReplicationStateDataView>(
                in_replication_state, context);
            decltype(CallWithContext(Traits::frame_owner_properties, input, custom_context)) in_frame_owner_properties = CallWithContext(Traits::frame_owner_properties, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::content::mojom::FrameOwnerPropertiesDataView>(
                in_frame_owner_properties, context);
            decltype(CallWithContext(Traits::widget_params, input, custom_context)) in_widget_params = CallWithContext(Traits::widget_params, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::content::mojom::CreateFrameWidgetParamsDataView>(
                in_widget_params, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::content::mojom::internal::CreateFrameParams_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::content::mojom::internal::CreateFrameParams_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->routing_id = CallWithContext(Traits::routing_id, input, custom_context);
            result->proxy_routing_id = CallWithContext(Traits::proxy_routing_id, input, custom_context);
            result->opener_routing_id = CallWithContext(Traits::opener_routing_id, input, custom_context);
            result->parent_routing_id = CallWithContext(Traits::parent_routing_id, input, custom_context);
            result->previous_sibling_routing_id = CallWithContext(Traits::previous_sibling_routing_id, input, custom_context);
            decltype(CallWithContext(Traits::replication_state, input, custom_context)) in_replication_state = CallWithContext(Traits::replication_state, input, custom_context);
            typename decltype(result->replication_state)::BaseType* replication_state_ptr;
            mojo::internal::Serialize<::content::mojom::FrameReplicationStateDataView>(
                in_replication_state, buffer, &replication_state_ptr, context);
            result->replication_state.Set(replication_state_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->replication_state.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null replication_state in CreateFrameParams struct");
            decltype(CallWithContext(Traits::frame_owner_properties, input, custom_context)) in_frame_owner_properties = CallWithContext(Traits::frame_owner_properties, input, custom_context);
            typename decltype(result->frame_owner_properties)::BaseType* frame_owner_properties_ptr;
            mojo::internal::Serialize<::content::mojom::FrameOwnerPropertiesDataView>(
                in_frame_owner_properties, buffer, &frame_owner_properties_ptr, context);
            result->frame_owner_properties.Set(frame_owner_properties_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->frame_owner_properties.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null frame_owner_properties in CreateFrameParams struct");
            decltype(CallWithContext(Traits::widget_params, input, custom_context)) in_widget_params = CallWithContext(Traits::widget_params, input, custom_context);
            typename decltype(result->widget_params)::BaseType* widget_params_ptr;
            mojo::internal::Serialize<::content::mojom::CreateFrameWidgetParamsDataView>(
                in_widget_params, buffer, &widget_params_ptr, context);
            result->widget_params.Set(widget_params_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->widget_params.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null widget_params in CreateFrameParams struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::content::mojom::internal::CreateFrameParams_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::content::mojom::CreateFrameParamsDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::content::mojom::UpdateScrollbarThemeParamsDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::content::mojom::UpdateScrollbarThemeParamsDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::content::mojom::internal::UpdateScrollbarThemeParams_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::content::mojom::internal::UpdateScrollbarThemeParams_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::content::mojom::internal::UpdateScrollbarThemeParams_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->initial_button_delay = CallWithContext(Traits::initial_button_delay, input, custom_context);
            result->autoscroll_button_delay = CallWithContext(Traits::autoscroll_button_delay, input, custom_context);
            result->jump_on_track_click = CallWithContext(Traits::jump_on_track_click, input, custom_context);
            mojo::internal::Serialize<::content::mojom::ScrollerStyle>(
                CallWithContext(Traits::preferred_scroller_style, input, custom_context), &result->preferred_scroller_style);
            result->redraw = CallWithContext(Traits::redraw, input, custom_context);
            mojo::internal::Serialize<::content::mojom::ScrollbarButtonsPlacement>(
                CallWithContext(Traits::button_placement, input, custom_context), &result->button_placement);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::content::mojom::internal::UpdateScrollbarThemeParams_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::content::mojom::UpdateScrollbarThemeParamsDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace content {
namespace mojom {

    inline void CreateViewParamsDataView::GetRendererPreferencesDataView(
        ::content::mojom::RendererPreferencesDataView* output)
    {
        auto pointer = data_->renderer_preferences.Get();
        *output = ::content::mojom::RendererPreferencesDataView(pointer, context_);
    }
    inline void CreateViewParamsDataView::GetWebPreferencesDataView(
        ::content::mojom::WebPreferencesDataView* output)
    {
        auto pointer = data_->web_preferences.Get();
        *output = ::content::mojom::WebPreferencesDataView(pointer, context_);
    }
    inline void CreateViewParamsDataView::GetReplicatedFrameStateDataView(
        ::content::mojom::FrameReplicationStateDataView* output)
    {
        auto pointer = data_->replicated_frame_state.Get();
        *output = ::content::mojom::FrameReplicationStateDataView(pointer, context_);
    }
    inline void CreateViewParamsDataView::GetInitialSizeDataView(
        ::content::mojom::ResizeParamsDataView* output)
    {
        auto pointer = data_->initial_size.Get();
        *output = ::content::mojom::ResizeParamsDataView(pointer, context_);
    }
    inline void CreateViewParamsDataView::GetMinSizeDataView(
        ::gfx::mojom::SizeDataView* output)
    {
        auto pointer = data_->min_size.Get();
        *output = ::gfx::mojom::SizeDataView(pointer, context_);
    }
    inline void CreateViewParamsDataView::GetMaxSizeDataView(
        ::gfx::mojom::SizeDataView* output)
    {
        auto pointer = data_->max_size.Get();
        *output = ::gfx::mojom::SizeDataView(pointer, context_);
    }
    inline void CreateViewParamsDataView::GetImageDecodeColorSpaceDataView(
        ::gfx::mojom::ICCProfileDataView* output)
    {
        auto pointer = data_->image_decode_color_space.Get();
        *output = ::gfx::mojom::ICCProfileDataView(pointer, context_);
    }

    inline void CreateFrameParamsDataView::GetReplicationStateDataView(
        ::content::mojom::FrameReplicationStateDataView* output)
    {
        auto pointer = data_->replication_state.Get();
        *output = ::content::mojom::FrameReplicationStateDataView(pointer, context_);
    }
    inline void CreateFrameParamsDataView::GetFrameOwnerPropertiesDataView(
        ::content::mojom::FrameOwnerPropertiesDataView* output)
    {
        auto pointer = data_->frame_owner_properties.Get();
        *output = ::content::mojom::FrameOwnerPropertiesDataView(pointer, context_);
    }
    inline void CreateFrameParamsDataView::GetWidgetParamsDataView(
        CreateFrameWidgetParamsDataView* output)
    {
        auto pointer = data_->widget_params.Get();
        *output = CreateFrameWidgetParamsDataView(pointer, context_);
    }

    inline void Renderer_CreateView_ParamsDataView::GetParamsDataView(
        CreateViewParamsDataView* output)
    {
        auto pointer = data_->params.Get();
        *output = CreateViewParamsDataView(pointer, context_);
    }

    inline void Renderer_CreateFrame_ParamsDataView::GetParamsDataView(
        CreateFrameParamsDataView* output)
    {
        auto pointer = data_->params.Get();
        *output = CreateFrameParamsDataView(pointer, context_);
    }

    inline void Renderer_CreateFrameProxy_ParamsDataView::GetReplicationStateDataView(
        ::content::mojom::FrameReplicationStateDataView* output)
    {
        auto pointer = data_->replication_state.Get();
        *output = ::content::mojom::FrameReplicationStateDataView(pointer, context_);
    }

    inline void Renderer_UpdateScrollbarTheme_ParamsDataView::GetParamsDataView(
        UpdateScrollbarThemeParamsDataView* output)
    {
        auto pointer = data_->params.Get();
        *output = UpdateScrollbarThemeParamsDataView(pointer, context_);
    }

    inline void Renderer_OnSystemColorsChanged_ParamsDataView::GetHighlightTextColorDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->highlight_text_color.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void Renderer_OnSystemColorsChanged_ParamsDataView::GetHighlightColorDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->highlight_color.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

} // namespace mojom
} // namespace content

#endif // CONTENT_COMMON_RENDERER_MOJOM_SHARED_H_
