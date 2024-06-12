// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_MOJO_INTERFACES_RENDERER_MOJOM_SHARED_H_
#define MEDIA_MOJO_INTERFACES_RENDERER_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "media/mojo/interfaces/demuxer_stream.mojom-shared.h"
#include "media/mojo/interfaces/media_types.mojom-shared.h"
#include "media/mojo/interfaces/renderer.mojom-shared-internal.h"
#include "mojo/common/time.mojom-shared.h"
#include "mojo/common/unguessable_token.mojom-shared.h"
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
#include "url/mojo/url.mojom-shared.h"

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
    class RendererInterfaceBase {
    };

    using RendererPtrDataView = mojo::InterfacePtrDataView<RendererInterfaceBase>;
    using RendererRequestDataView = mojo::InterfaceRequestDataView<RendererInterfaceBase>;
    using RendererAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<RendererInterfaceBase>;
    using RendererAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<RendererInterfaceBase>;
    class RendererClientInterfaceBase {
    };

    using RendererClientPtrDataView = mojo::InterfacePtrDataView<RendererClientInterfaceBase>;
    using RendererClientRequestDataView = mojo::InterfaceRequestDataView<RendererClientInterfaceBase>;
    using RendererClientAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<RendererClientInterfaceBase>;
    using RendererClientAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<RendererClientInterfaceBase>;
    class Renderer_Initialize_ParamsDataView {
    public:
        Renderer_Initialize_ParamsDataView() { }

        Renderer_Initialize_ParamsDataView(
            internal::Renderer_Initialize_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeClient()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::media::mojom::RendererClientAssociatedPtrInfoDataView>(
                &data_->client, &result, context_);
            DCHECK(ret);
            return result;
        }
        template <typename UserType>
        UserType TakeAudio()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::media::mojom::DemuxerStreamPtrDataView>(
                &data_->audio, &result, context_);
            DCHECK(ret);
            return result;
        }
        template <typename UserType>
        UserType TakeVideo()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::media::mojom::DemuxerStreamPtrDataView>(
                &data_->video, &result, context_);
            DCHECK(ret);
            return result;
        }
        inline void GetMediaUrlDataView(
            ::url::mojom::UrlDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMediaUrl(UserType* output)
        {
            auto* pointer = data_->media_url.Get();
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
        internal::Renderer_Initialize_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Renderer_Initialize_ResponseParamsDataView {
    public:
        Renderer_Initialize_ResponseParamsDataView() { }

        Renderer_Initialize_ResponseParamsDataView(
            internal::Renderer_Initialize_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool success() const
        {
            return data_->success;
        }

    private:
        internal::Renderer_Initialize_ResponseParams_Data* data_ = nullptr;
    };

    class Renderer_Flush_ParamsDataView {
    public:
        Renderer_Flush_ParamsDataView() { }

        Renderer_Flush_ParamsDataView(
            internal::Renderer_Flush_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::Renderer_Flush_Params_Data* data_ = nullptr;
    };

    class Renderer_Flush_ResponseParamsDataView {
    public:
        Renderer_Flush_ResponseParamsDataView() { }

        Renderer_Flush_ResponseParamsDataView(
            internal::Renderer_Flush_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::Renderer_Flush_ResponseParams_Data* data_ = nullptr;
    };

    class Renderer_StartPlayingFrom_ParamsDataView {
    public:
        Renderer_StartPlayingFrom_ParamsDataView() { }

        Renderer_StartPlayingFrom_ParamsDataView(
            internal::Renderer_StartPlayingFrom_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetTimeDataView(
            ::mojo::common::mojom::TimeDeltaDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTime(UserType* output)
        {
            auto* pointer = data_->time.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::TimeDeltaDataView>(
                pointer, output, context_);
        }

    private:
        internal::Renderer_StartPlayingFrom_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Renderer_SetPlaybackRate_ParamsDataView {
    public:
        Renderer_SetPlaybackRate_ParamsDataView() { }

        Renderer_SetPlaybackRate_ParamsDataView(
            internal::Renderer_SetPlaybackRate_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        double playback_rate() const
        {
            return data_->playback_rate;
        }

    private:
        internal::Renderer_SetPlaybackRate_Params_Data* data_ = nullptr;
    };

    class Renderer_SetVolume_ParamsDataView {
    public:
        Renderer_SetVolume_ParamsDataView() { }

        Renderer_SetVolume_ParamsDataView(
            internal::Renderer_SetVolume_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        float volume() const
        {
            return data_->volume;
        }

    private:
        internal::Renderer_SetVolume_Params_Data* data_ = nullptr;
    };

    class Renderer_SetCdm_ParamsDataView {
    public:
        Renderer_SetCdm_ParamsDataView() { }

        Renderer_SetCdm_ParamsDataView(
            internal::Renderer_SetCdm_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int32_t cdm_id() const
        {
            return data_->cdm_id;
        }

    private:
        internal::Renderer_SetCdm_Params_Data* data_ = nullptr;
    };

    class Renderer_SetCdm_ResponseParamsDataView {
    public:
        Renderer_SetCdm_ResponseParamsDataView() { }

        Renderer_SetCdm_ResponseParamsDataView(
            internal::Renderer_SetCdm_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool success() const
        {
            return data_->success;
        }

    private:
        internal::Renderer_SetCdm_ResponseParams_Data* data_ = nullptr;
    };

    class Renderer_InitiateScopedSurfaceRequest_ParamsDataView {
    public:
        Renderer_InitiateScopedSurfaceRequest_ParamsDataView() { }

        Renderer_InitiateScopedSurfaceRequest_ParamsDataView(
            internal::Renderer_InitiateScopedSurfaceRequest_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::Renderer_InitiateScopedSurfaceRequest_Params_Data* data_ = nullptr;
    };

    class Renderer_InitiateScopedSurfaceRequest_ResponseParamsDataView {
    public:
        Renderer_InitiateScopedSurfaceRequest_ResponseParamsDataView() { }

        Renderer_InitiateScopedSurfaceRequest_ResponseParamsDataView(
            internal::Renderer_InitiateScopedSurfaceRequest_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetRequestTokenDataView(
            ::mojo::common::mojom::UnguessableTokenDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadRequestToken(UserType* output)
        {
            auto* pointer = data_->request_token.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::UnguessableTokenDataView>(
                pointer, output, context_);
        }

    private:
        internal::Renderer_InitiateScopedSurfaceRequest_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class RendererClient_OnTimeUpdate_ParamsDataView {
    public:
        RendererClient_OnTimeUpdate_ParamsDataView() { }

        RendererClient_OnTimeUpdate_ParamsDataView(
            internal::RendererClient_OnTimeUpdate_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetTimeDataView(
            ::mojo::common::mojom::TimeDeltaDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTime(UserType* output)
        {
            auto* pointer = data_->time.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::TimeDeltaDataView>(
                pointer, output, context_);
        }
        inline void GetMaxTimeDataView(
            ::mojo::common::mojom::TimeDeltaDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMaxTime(UserType* output)
        {
            auto* pointer = data_->max_time.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::TimeDeltaDataView>(
                pointer, output, context_);
        }
        inline void GetCaptureTimeDataView(
            ::mojo::common::mojom::TimeTicksDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadCaptureTime(UserType* output)
        {
            auto* pointer = data_->capture_time.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::TimeTicksDataView>(
                pointer, output, context_);
        }

    private:
        internal::RendererClient_OnTimeUpdate_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class RendererClient_OnBufferingStateChange_ParamsDataView {
    public:
        RendererClient_OnBufferingStateChange_ParamsDataView() { }

        RendererClient_OnBufferingStateChange_ParamsDataView(
            internal::RendererClient_OnBufferingStateChange_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadState(UserType* output) const
        {
            auto data_value = data_->state;
            return mojo::internal::Deserialize<::media::mojom::BufferingState>(
                data_value, output);
        }

        ::media::mojom::BufferingState state() const
        {
            return static_cast<::media::mojom::BufferingState>(data_->state);
        }

    private:
        internal::RendererClient_OnBufferingStateChange_Params_Data* data_ = nullptr;
    };

    class RendererClient_OnEnded_ParamsDataView {
    public:
        RendererClient_OnEnded_ParamsDataView() { }

        RendererClient_OnEnded_ParamsDataView(
            internal::RendererClient_OnEnded_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::RendererClient_OnEnded_Params_Data* data_ = nullptr;
    };

    class RendererClient_OnError_ParamsDataView {
    public:
        RendererClient_OnError_ParamsDataView() { }

        RendererClient_OnError_ParamsDataView(
            internal::RendererClient_OnError_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::RendererClient_OnError_Params_Data* data_ = nullptr;
    };

    class RendererClient_OnVideoNaturalSizeChange_ParamsDataView {
    public:
        RendererClient_OnVideoNaturalSizeChange_ParamsDataView() { }

        RendererClient_OnVideoNaturalSizeChange_ParamsDataView(
            internal::RendererClient_OnVideoNaturalSizeChange_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetSizeDataView(
            ::gfx::mojom::SizeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSize(UserType* output)
        {
            auto* pointer = data_->size.Get();
            return mojo::internal::Deserialize<::gfx::mojom::SizeDataView>(
                pointer, output, context_);
        }

    private:
        internal::RendererClient_OnVideoNaturalSizeChange_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class RendererClient_OnVideoOpacityChange_ParamsDataView {
    public:
        RendererClient_OnVideoOpacityChange_ParamsDataView() { }

        RendererClient_OnVideoOpacityChange_ParamsDataView(
            internal::RendererClient_OnVideoOpacityChange_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool opaque() const
        {
            return data_->opaque;
        }

    private:
        internal::RendererClient_OnVideoOpacityChange_Params_Data* data_ = nullptr;
    };

    class RendererClient_OnStatisticsUpdate_ParamsDataView {
    public:
        RendererClient_OnStatisticsUpdate_ParamsDataView() { }

        RendererClient_OnStatisticsUpdate_ParamsDataView(
            internal::RendererClient_OnStatisticsUpdate_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetStatsDataView(
            ::media::mojom::PipelineStatisticsDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStats(UserType* output)
        {
            auto* pointer = data_->stats.Get();
            return mojo::internal::Deserialize<::media::mojom::PipelineStatisticsDataView>(
                pointer, output, context_);
        }

    private:
        internal::RendererClient_OnStatisticsUpdate_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class RendererClient_OnWaitingForDecryptionKey_ParamsDataView {
    public:
        RendererClient_OnWaitingForDecryptionKey_ParamsDataView() { }

        RendererClient_OnWaitingForDecryptionKey_ParamsDataView(
            internal::RendererClient_OnWaitingForDecryptionKey_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::RendererClient_OnWaitingForDecryptionKey_Params_Data* data_ = nullptr;
    };

    class RendererClient_OnDurationChange_ParamsDataView {
    public:
        RendererClient_OnDurationChange_ParamsDataView() { }

        RendererClient_OnDurationChange_ParamsDataView(
            internal::RendererClient_OnDurationChange_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetDurationDataView(
            ::mojo::common::mojom::TimeDeltaDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDuration(UserType* output)
        {
            auto* pointer = data_->duration.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::TimeDeltaDataView>(
                pointer, output, context_);
        }

    private:
        internal::RendererClient_OnDurationChange_Params_Data* data_ = nullptr;
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

    inline void Renderer_Initialize_ParamsDataView::GetMediaUrlDataView(
        ::url::mojom::UrlDataView* output)
    {
        auto pointer = data_->media_url.Get();
        *output = ::url::mojom::UrlDataView(pointer, context_);
    }
    inline void Renderer_Initialize_ParamsDataView::GetFirstPartyForCookiesDataView(
        ::url::mojom::UrlDataView* output)
    {
        auto pointer = data_->first_party_for_cookies.Get();
        *output = ::url::mojom::UrlDataView(pointer, context_);
    }

    inline void Renderer_StartPlayingFrom_ParamsDataView::GetTimeDataView(
        ::mojo::common::mojom::TimeDeltaDataView* output)
    {
        auto pointer = data_->time.Get();
        *output = ::mojo::common::mojom::TimeDeltaDataView(pointer, context_);
    }

    inline void Renderer_InitiateScopedSurfaceRequest_ResponseParamsDataView::GetRequestTokenDataView(
        ::mojo::common::mojom::UnguessableTokenDataView* output)
    {
        auto pointer = data_->request_token.Get();
        *output = ::mojo::common::mojom::UnguessableTokenDataView(pointer, context_);
    }

    inline void RendererClient_OnTimeUpdate_ParamsDataView::GetTimeDataView(
        ::mojo::common::mojom::TimeDeltaDataView* output)
    {
        auto pointer = data_->time.Get();
        *output = ::mojo::common::mojom::TimeDeltaDataView(pointer, context_);
    }
    inline void RendererClient_OnTimeUpdate_ParamsDataView::GetMaxTimeDataView(
        ::mojo::common::mojom::TimeDeltaDataView* output)
    {
        auto pointer = data_->max_time.Get();
        *output = ::mojo::common::mojom::TimeDeltaDataView(pointer, context_);
    }
    inline void RendererClient_OnTimeUpdate_ParamsDataView::GetCaptureTimeDataView(
        ::mojo::common::mojom::TimeTicksDataView* output)
    {
        auto pointer = data_->capture_time.Get();
        *output = ::mojo::common::mojom::TimeTicksDataView(pointer, context_);
    }

    inline void RendererClient_OnVideoNaturalSizeChange_ParamsDataView::GetSizeDataView(
        ::gfx::mojom::SizeDataView* output)
    {
        auto pointer = data_->size.Get();
        *output = ::gfx::mojom::SizeDataView(pointer, context_);
    }

    inline void RendererClient_OnStatisticsUpdate_ParamsDataView::GetStatsDataView(
        ::media::mojom::PipelineStatisticsDataView* output)
    {
        auto pointer = data_->stats.Get();
        *output = ::media::mojom::PipelineStatisticsDataView(pointer, context_);
    }

    inline void RendererClient_OnDurationChange_ParamsDataView::GetDurationDataView(
        ::mojo::common::mojom::TimeDeltaDataView* output)
    {
        auto pointer = data_->duration.Get();
        *output = ::mojo::common::mojom::TimeDeltaDataView(pointer, context_);
    }

} // namespace mojom
} // namespace media

#endif // MEDIA_MOJO_INTERFACES_RENDERER_MOJOM_SHARED_H_
