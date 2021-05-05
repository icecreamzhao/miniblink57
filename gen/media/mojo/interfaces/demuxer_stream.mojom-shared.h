// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_MOJO_INTERFACES_DEMUXER_STREAM_MOJOM_SHARED_H_
#define MEDIA_MOJO_INTERFACES_DEMUXER_STREAM_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "media/mojo/interfaces/demuxer_stream.mojom-shared-internal.h"
#include "media/mojo/interfaces/media_types.mojom-shared.h"
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
    using DemuxerStream_Type = mojo::NativeEnum;
    using DemuxerStream_Status = mojo::NativeEnum;
    // Interface base classes. They are used for type safety check.
    class DemuxerStreamInterfaceBase {
    };

    using DemuxerStreamPtrDataView = mojo::InterfacePtrDataView<DemuxerStreamInterfaceBase>;
    using DemuxerStreamRequestDataView = mojo::InterfaceRequestDataView<DemuxerStreamInterfaceBase>;
    using DemuxerStreamAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<DemuxerStreamInterfaceBase>;
    using DemuxerStreamAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<DemuxerStreamInterfaceBase>;
    class DemuxerStream_Initialize_ParamsDataView {
    public:
        DemuxerStream_Initialize_ParamsDataView() { }

        DemuxerStream_Initialize_ParamsDataView(
            internal::DemuxerStream_Initialize_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::DemuxerStream_Initialize_Params_Data* data_ = nullptr;
    };

    class DemuxerStream_Initialize_ResponseParamsDataView {
    public:
        DemuxerStream_Initialize_ResponseParamsDataView() { }

        DemuxerStream_Initialize_ResponseParamsDataView(
            internal::DemuxerStream_Initialize_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadType(UserType* output) const
        {
            auto data_value = data_->type;
            return mojo::internal::Deserialize<::media::mojom::DemuxerStream_Type>(
                data_value, output);
        }

        DemuxerStream_Type type() const
        {
            return static_cast<DemuxerStream_Type>(data_->type);
        }
        mojo::ScopedDataPipeConsumerHandle TakePipe()
        {
            mojo::ScopedDataPipeConsumerHandle result;
            bool ret = mojo::internal::Deserialize<mojo::ScopedDataPipeConsumerHandle>(
                &data_->pipe, &result, context_);
            DCHECK(ret);
            return result;
        }
        inline void GetAudioConfigDataView(
            ::media::mojom::AudioDecoderConfigDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadAudioConfig(UserType* output)
        {
            auto* pointer = data_->audio_config.Get();
            return mojo::internal::Deserialize<::media::mojom::AudioDecoderConfigDataView>(
                pointer, output, context_);
        }
        inline void GetVideoConfigDataView(
            ::media::mojom::VideoDecoderConfigDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadVideoConfig(UserType* output)
        {
            auto* pointer = data_->video_config.Get();
            return mojo::internal::Deserialize<::media::mojom::VideoDecoderConfigDataView>(
                pointer, output, context_);
        }

    private:
        internal::DemuxerStream_Initialize_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class DemuxerStream_Read_ParamsDataView {
    public:
        DemuxerStream_Read_ParamsDataView() { }

        DemuxerStream_Read_ParamsDataView(
            internal::DemuxerStream_Read_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::DemuxerStream_Read_Params_Data* data_ = nullptr;
    };

    class DemuxerStream_Read_ResponseParamsDataView {
    public:
        DemuxerStream_Read_ResponseParamsDataView() { }

        DemuxerStream_Read_ResponseParamsDataView(
            internal::DemuxerStream_Read_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStatus(UserType* output) const
        {
            auto data_value = data_->status;
            return mojo::internal::Deserialize<::media::mojom::DemuxerStream_Status>(
                data_value, output);
        }

        DemuxerStream_Status status() const
        {
            return static_cast<DemuxerStream_Status>(data_->status);
        }
        inline void GetBufferDataView(
            ::media::mojom::DecoderBufferDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadBuffer(UserType* output)
        {
            auto* pointer = data_->buffer.Get();
            return mojo::internal::Deserialize<::media::mojom::DecoderBufferDataView>(
                pointer, output, context_);
        }
        inline void GetAudioConfigDataView(
            ::media::mojom::AudioDecoderConfigDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadAudioConfig(UserType* output)
        {
            auto* pointer = data_->audio_config.Get();
            return mojo::internal::Deserialize<::media::mojom::AudioDecoderConfigDataView>(
                pointer, output, context_);
        }
        inline void GetVideoConfigDataView(
            ::media::mojom::VideoDecoderConfigDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadVideoConfig(UserType* output)
        {
            auto* pointer = data_->video_config.Get();
            return mojo::internal::Deserialize<::media::mojom::VideoDecoderConfigDataView>(
                pointer, output, context_);
        }

    private:
        internal::DemuxerStream_Read_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class DemuxerStream_EnableBitstreamConverter_ParamsDataView {
    public:
        DemuxerStream_EnableBitstreamConverter_ParamsDataView() { }

        DemuxerStream_EnableBitstreamConverter_ParamsDataView(
            internal::DemuxerStream_EnableBitstreamConverter_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::DemuxerStream_EnableBitstreamConverter_Params_Data* data_ = nullptr;
    };

} // namespace mojom
} // namespace media

namespace std {

} // namespace std

namespace mojo {

} // namespace mojo

namespace media {
namespace mojom {

    inline void DemuxerStream_Initialize_ResponseParamsDataView::GetAudioConfigDataView(
        ::media::mojom::AudioDecoderConfigDataView* output)
    {
        auto pointer = data_->audio_config.Get();
        *output = ::media::mojom::AudioDecoderConfigDataView(pointer, context_);
    }
    inline void DemuxerStream_Initialize_ResponseParamsDataView::GetVideoConfigDataView(
        ::media::mojom::VideoDecoderConfigDataView* output)
    {
        auto pointer = data_->video_config.Get();
        *output = ::media::mojom::VideoDecoderConfigDataView(pointer, context_);
    }

    inline void DemuxerStream_Read_ResponseParamsDataView::GetBufferDataView(
        ::media::mojom::DecoderBufferDataView* output)
    {
        auto pointer = data_->buffer.Get();
        *output = ::media::mojom::DecoderBufferDataView(pointer, context_);
    }
    inline void DemuxerStream_Read_ResponseParamsDataView::GetAudioConfigDataView(
        ::media::mojom::AudioDecoderConfigDataView* output)
    {
        auto pointer = data_->audio_config.Get();
        *output = ::media::mojom::AudioDecoderConfigDataView(pointer, context_);
    }
    inline void DemuxerStream_Read_ResponseParamsDataView::GetVideoConfigDataView(
        ::media::mojom::VideoDecoderConfigDataView* output)
    {
        auto pointer = data_->video_config.Get();
        *output = ::media::mojom::VideoDecoderConfigDataView(pointer, context_);
    }

} // namespace mojom
} // namespace media

#endif // MEDIA_MOJO_INTERFACES_DEMUXER_STREAM_MOJOM_SHARED_H_
