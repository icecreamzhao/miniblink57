// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_MOJO_INTERFACES_AUDIO_DECODER_MOJOM_SHARED_H_
#define MEDIA_MOJO_INTERFACES_AUDIO_DECODER_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "media/mojo/interfaces/audio_decoder.mojom-shared-internal.h"
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
    // Interface base classes. They are used for type safety check.
    class AudioDecoderInterfaceBase {
    };

    using AudioDecoderPtrDataView = mojo::InterfacePtrDataView<AudioDecoderInterfaceBase>;
    using AudioDecoderRequestDataView = mojo::InterfaceRequestDataView<AudioDecoderInterfaceBase>;
    using AudioDecoderAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<AudioDecoderInterfaceBase>;
    using AudioDecoderAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<AudioDecoderInterfaceBase>;
    class AudioDecoderClientInterfaceBase {
    };

    using AudioDecoderClientPtrDataView = mojo::InterfacePtrDataView<AudioDecoderClientInterfaceBase>;
    using AudioDecoderClientRequestDataView = mojo::InterfaceRequestDataView<AudioDecoderClientInterfaceBase>;
    using AudioDecoderClientAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<AudioDecoderClientInterfaceBase>;
    using AudioDecoderClientAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<AudioDecoderClientInterfaceBase>;
    class AudioDecoder_Construct_ParamsDataView {
    public:
        AudioDecoder_Construct_ParamsDataView() { }

        AudioDecoder_Construct_ParamsDataView(
            internal::AudioDecoder_Construct_Params_Data* data,
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
            bool ret = mojo::internal::Deserialize<::media::mojom::AudioDecoderClientAssociatedPtrInfoDataView>(
                &data_->client, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::AudioDecoder_Construct_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class AudioDecoder_Initialize_ParamsDataView {
    public:
        AudioDecoder_Initialize_ParamsDataView() { }

        AudioDecoder_Initialize_ParamsDataView(
            internal::AudioDecoder_Initialize_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetConfigDataView(
            ::media::mojom::AudioDecoderConfigDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadConfig(UserType* output)
        {
            auto* pointer = data_->config.Get();
            return mojo::internal::Deserialize<::media::mojom::AudioDecoderConfigDataView>(
                pointer, output, context_);
        }
        int32_t cdm_id() const
        {
            return data_->cdm_id;
        }

    private:
        internal::AudioDecoder_Initialize_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class AudioDecoder_Initialize_ResponseParamsDataView {
    public:
        AudioDecoder_Initialize_ResponseParamsDataView() { }

        AudioDecoder_Initialize_ResponseParamsDataView(
            internal::AudioDecoder_Initialize_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool success() const
        {
            return data_->success;
        }
        bool needs_bitstream_conversion() const
        {
            return data_->needs_bitstream_conversion;
        }

    private:
        internal::AudioDecoder_Initialize_ResponseParams_Data* data_ = nullptr;
    };

    class AudioDecoder_SetDataSource_ParamsDataView {
    public:
        AudioDecoder_SetDataSource_ParamsDataView() { }

        AudioDecoder_SetDataSource_ParamsDataView(
            internal::AudioDecoder_SetDataSource_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        mojo::ScopedDataPipeConsumerHandle TakeReceivePipe()
        {
            mojo::ScopedDataPipeConsumerHandle result;
            bool ret = mojo::internal::Deserialize<mojo::ScopedDataPipeConsumerHandle>(
                &data_->receive_pipe, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::AudioDecoder_SetDataSource_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class AudioDecoder_Decode_ParamsDataView {
    public:
        AudioDecoder_Decode_ParamsDataView() { }

        AudioDecoder_Decode_ParamsDataView(
            internal::AudioDecoder_Decode_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetBufferDataView(
            ::media::mojom::DecoderBufferDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadBuffer(UserType* output)
        {
            auto* pointer = data_->buffer.Get();
            return mojo::internal::Deserialize<::media::mojom::DecoderBufferDataView>(
                pointer, output, context_);
        }

    private:
        internal::AudioDecoder_Decode_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class AudioDecoder_Decode_ResponseParamsDataView {
    public:
        AudioDecoder_Decode_ResponseParamsDataView() { }

        AudioDecoder_Decode_ResponseParamsDataView(
            internal::AudioDecoder_Decode_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStatus(UserType* output) const
        {
            auto data_value = data_->status;
            return mojo::internal::Deserialize<::media::mojom::DecodeStatus>(
                data_value, output);
        }

        ::media::mojom::DecodeStatus status() const
        {
            return static_cast<::media::mojom::DecodeStatus>(data_->status);
        }

    private:
        internal::AudioDecoder_Decode_ResponseParams_Data* data_ = nullptr;
    };

    class AudioDecoder_Reset_ParamsDataView {
    public:
        AudioDecoder_Reset_ParamsDataView() { }

        AudioDecoder_Reset_ParamsDataView(
            internal::AudioDecoder_Reset_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::AudioDecoder_Reset_Params_Data* data_ = nullptr;
    };

    class AudioDecoder_Reset_ResponseParamsDataView {
    public:
        AudioDecoder_Reset_ResponseParamsDataView() { }

        AudioDecoder_Reset_ResponseParamsDataView(
            internal::AudioDecoder_Reset_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::AudioDecoder_Reset_ResponseParams_Data* data_ = nullptr;
    };

    class AudioDecoderClient_OnBufferDecoded_ParamsDataView {
    public:
        AudioDecoderClient_OnBufferDecoded_ParamsDataView() { }

        AudioDecoderClient_OnBufferDecoded_ParamsDataView(
            internal::AudioDecoderClient_OnBufferDecoded_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetBufferDataView(
            ::media::mojom::AudioBufferDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadBuffer(UserType* output)
        {
            auto* pointer = data_->buffer.Get();
            return mojo::internal::Deserialize<::media::mojom::AudioBufferDataView>(
                pointer, output, context_);
        }

    private:
        internal::AudioDecoderClient_OnBufferDecoded_Params_Data* data_ = nullptr;
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

    inline void AudioDecoder_Initialize_ParamsDataView::GetConfigDataView(
        ::media::mojom::AudioDecoderConfigDataView* output)
    {
        auto pointer = data_->config.Get();
        *output = ::media::mojom::AudioDecoderConfigDataView(pointer, context_);
    }

    inline void AudioDecoder_Decode_ParamsDataView::GetBufferDataView(
        ::media::mojom::DecoderBufferDataView* output)
    {
        auto pointer = data_->buffer.Get();
        *output = ::media::mojom::DecoderBufferDataView(pointer, context_);
    }

    inline void AudioDecoderClient_OnBufferDecoded_ParamsDataView::GetBufferDataView(
        ::media::mojom::AudioBufferDataView* output)
    {
        auto pointer = data_->buffer.Get();
        *output = ::media::mojom::AudioBufferDataView(pointer, context_);
    }

} // namespace mojom
} // namespace media

#endif // MEDIA_MOJO_INTERFACES_AUDIO_DECODER_MOJOM_SHARED_H_
