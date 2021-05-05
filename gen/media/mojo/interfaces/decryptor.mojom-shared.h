// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_MOJO_INTERFACES_DECRYPTOR_MOJOM_SHARED_H_
#define MEDIA_MOJO_INTERFACES_DECRYPTOR_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "media/mojo/interfaces/decryptor.mojom-shared-internal.h"
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
    using Decryptor_Status = mojo::NativeEnum;
    using Decryptor_StreamType = mojo::NativeEnum;
    // Interface base classes. They are used for type safety check.
    class DecryptorInterfaceBase {
    };

    using DecryptorPtrDataView = mojo::InterfacePtrDataView<DecryptorInterfaceBase>;
    using DecryptorRequestDataView = mojo::InterfaceRequestDataView<DecryptorInterfaceBase>;
    using DecryptorAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<DecryptorInterfaceBase>;
    using DecryptorAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<DecryptorInterfaceBase>;
    class Decryptor_Initialize_ParamsDataView {
    public:
        Decryptor_Initialize_ParamsDataView() { }

        Decryptor_Initialize_ParamsDataView(
            internal::Decryptor_Initialize_Params_Data* data,
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
        mojo::ScopedDataPipeProducerHandle TakeTransmitPipe()
        {
            mojo::ScopedDataPipeProducerHandle result;
            bool ret = mojo::internal::Deserialize<mojo::ScopedDataPipeProducerHandle>(
                &data_->transmit_pipe, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::Decryptor_Initialize_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Decryptor_Decrypt_ParamsDataView {
    public:
        Decryptor_Decrypt_ParamsDataView() { }

        Decryptor_Decrypt_ParamsDataView(
            internal::Decryptor_Decrypt_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStreamType(UserType* output) const
        {
            auto data_value = data_->stream_type;
            return mojo::internal::Deserialize<::media::mojom::Decryptor_StreamType>(
                data_value, output);
        }

        Decryptor_StreamType stream_type() const
        {
            return static_cast<Decryptor_StreamType>(data_->stream_type);
        }
        inline void GetEncryptedDataView(
            ::media::mojom::DecoderBufferDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadEncrypted(UserType* output)
        {
            auto* pointer = data_->encrypted.Get();
            return mojo::internal::Deserialize<::media::mojom::DecoderBufferDataView>(
                pointer, output, context_);
        }

    private:
        internal::Decryptor_Decrypt_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Decryptor_Decrypt_ResponseParamsDataView {
    public:
        Decryptor_Decrypt_ResponseParamsDataView() { }

        Decryptor_Decrypt_ResponseParamsDataView(
            internal::Decryptor_Decrypt_ResponseParams_Data* data,
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
            return mojo::internal::Deserialize<::media::mojom::Decryptor_Status>(
                data_value, output);
        }

        Decryptor_Status status() const
        {
            return static_cast<Decryptor_Status>(data_->status);
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

    private:
        internal::Decryptor_Decrypt_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Decryptor_CancelDecrypt_ParamsDataView {
    public:
        Decryptor_CancelDecrypt_ParamsDataView() { }

        Decryptor_CancelDecrypt_ParamsDataView(
            internal::Decryptor_CancelDecrypt_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStreamType(UserType* output) const
        {
            auto data_value = data_->stream_type;
            return mojo::internal::Deserialize<::media::mojom::Decryptor_StreamType>(
                data_value, output);
        }

        Decryptor_StreamType stream_type() const
        {
            return static_cast<Decryptor_StreamType>(data_->stream_type);
        }

    private:
        internal::Decryptor_CancelDecrypt_Params_Data* data_ = nullptr;
    };

    class Decryptor_InitializeAudioDecoder_ParamsDataView {
    public:
        Decryptor_InitializeAudioDecoder_ParamsDataView() { }

        Decryptor_InitializeAudioDecoder_ParamsDataView(
            internal::Decryptor_InitializeAudioDecoder_Params_Data* data,
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

    private:
        internal::Decryptor_InitializeAudioDecoder_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Decryptor_InitializeAudioDecoder_ResponseParamsDataView {
    public:
        Decryptor_InitializeAudioDecoder_ResponseParamsDataView() { }

        Decryptor_InitializeAudioDecoder_ResponseParamsDataView(
            internal::Decryptor_InitializeAudioDecoder_ResponseParams_Data* data,
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
        internal::Decryptor_InitializeAudioDecoder_ResponseParams_Data* data_ = nullptr;
    };

    class Decryptor_InitializeVideoDecoder_ParamsDataView {
    public:
        Decryptor_InitializeVideoDecoder_ParamsDataView() { }

        Decryptor_InitializeVideoDecoder_ParamsDataView(
            internal::Decryptor_InitializeVideoDecoder_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetConfigDataView(
            ::media::mojom::VideoDecoderConfigDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadConfig(UserType* output)
        {
            auto* pointer = data_->config.Get();
            return mojo::internal::Deserialize<::media::mojom::VideoDecoderConfigDataView>(
                pointer, output, context_);
        }

    private:
        internal::Decryptor_InitializeVideoDecoder_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Decryptor_InitializeVideoDecoder_ResponseParamsDataView {
    public:
        Decryptor_InitializeVideoDecoder_ResponseParamsDataView() { }

        Decryptor_InitializeVideoDecoder_ResponseParamsDataView(
            internal::Decryptor_InitializeVideoDecoder_ResponseParams_Data* data,
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
        internal::Decryptor_InitializeVideoDecoder_ResponseParams_Data* data_ = nullptr;
    };

    class Decryptor_DecryptAndDecodeAudio_ParamsDataView {
    public:
        Decryptor_DecryptAndDecodeAudio_ParamsDataView() { }

        Decryptor_DecryptAndDecodeAudio_ParamsDataView(
            internal::Decryptor_DecryptAndDecodeAudio_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetEncryptedDataView(
            ::media::mojom::DecoderBufferDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadEncrypted(UserType* output)
        {
            auto* pointer = data_->encrypted.Get();
            return mojo::internal::Deserialize<::media::mojom::DecoderBufferDataView>(
                pointer, output, context_);
        }

    private:
        internal::Decryptor_DecryptAndDecodeAudio_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Decryptor_DecryptAndDecodeAudio_ResponseParamsDataView {
    public:
        Decryptor_DecryptAndDecodeAudio_ResponseParamsDataView() { }

        Decryptor_DecryptAndDecodeAudio_ResponseParamsDataView(
            internal::Decryptor_DecryptAndDecodeAudio_ResponseParams_Data* data,
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
            return mojo::internal::Deserialize<::media::mojom::Decryptor_Status>(
                data_value, output);
        }

        Decryptor_Status status() const
        {
            return static_cast<Decryptor_Status>(data_->status);
        }
        inline void GetAudioBuffersDataView(
            mojo::ArrayDataView<::media::mojom::AudioBufferDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadAudioBuffers(UserType* output)
        {
            auto* pointer = data_->audio_buffers.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::media::mojom::AudioBufferDataView>>(
                pointer, output, context_);
        }

    private:
        internal::Decryptor_DecryptAndDecodeAudio_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Decryptor_DecryptAndDecodeVideo_ParamsDataView {
    public:
        Decryptor_DecryptAndDecodeVideo_ParamsDataView() { }

        Decryptor_DecryptAndDecodeVideo_ParamsDataView(
            internal::Decryptor_DecryptAndDecodeVideo_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetEncryptedDataView(
            ::media::mojom::DecoderBufferDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadEncrypted(UserType* output)
        {
            auto* pointer = data_->encrypted.Get();
            return mojo::internal::Deserialize<::media::mojom::DecoderBufferDataView>(
                pointer, output, context_);
        }

    private:
        internal::Decryptor_DecryptAndDecodeVideo_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Decryptor_DecryptAndDecodeVideo_ResponseParamsDataView {
    public:
        Decryptor_DecryptAndDecodeVideo_ResponseParamsDataView() { }

        Decryptor_DecryptAndDecodeVideo_ResponseParamsDataView(
            internal::Decryptor_DecryptAndDecodeVideo_ResponseParams_Data* data,
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
            return mojo::internal::Deserialize<::media::mojom::Decryptor_Status>(
                data_value, output);
        }

        Decryptor_Status status() const
        {
            return static_cast<Decryptor_Status>(data_->status);
        }
        inline void GetVideoFrameDataView(
            ::media::mojom::VideoFrameDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadVideoFrame(UserType* output)
        {
            auto* pointer = data_->video_frame.Get();
            return mojo::internal::Deserialize<::media::mojom::VideoFrameDataView>(
                pointer, output, context_);
        }

    private:
        internal::Decryptor_DecryptAndDecodeVideo_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Decryptor_ResetDecoder_ParamsDataView {
    public:
        Decryptor_ResetDecoder_ParamsDataView() { }

        Decryptor_ResetDecoder_ParamsDataView(
            internal::Decryptor_ResetDecoder_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStreamType(UserType* output) const
        {
            auto data_value = data_->stream_type;
            return mojo::internal::Deserialize<::media::mojom::Decryptor_StreamType>(
                data_value, output);
        }

        Decryptor_StreamType stream_type() const
        {
            return static_cast<Decryptor_StreamType>(data_->stream_type);
        }

    private:
        internal::Decryptor_ResetDecoder_Params_Data* data_ = nullptr;
    };

    class Decryptor_DeinitializeDecoder_ParamsDataView {
    public:
        Decryptor_DeinitializeDecoder_ParamsDataView() { }

        Decryptor_DeinitializeDecoder_ParamsDataView(
            internal::Decryptor_DeinitializeDecoder_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadStreamType(UserType* output) const
        {
            auto data_value = data_->stream_type;
            return mojo::internal::Deserialize<::media::mojom::Decryptor_StreamType>(
                data_value, output);
        }

        Decryptor_StreamType stream_type() const
        {
            return static_cast<Decryptor_StreamType>(data_->stream_type);
        }

    private:
        internal::Decryptor_DeinitializeDecoder_Params_Data* data_ = nullptr;
    };

    class Decryptor_ReleaseSharedBuffer_ParamsDataView {
    public:
        Decryptor_ReleaseSharedBuffer_ParamsDataView() { }

        Decryptor_ReleaseSharedBuffer_ParamsDataView(
            internal::Decryptor_ReleaseSharedBuffer_Params_Data* data,
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
        uint64_t buffer_size() const
        {
            return data_->buffer_size;
        }

    private:
        internal::Decryptor_ReleaseSharedBuffer_Params_Data* data_ = nullptr;
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

    inline void Decryptor_Decrypt_ParamsDataView::GetEncryptedDataView(
        ::media::mojom::DecoderBufferDataView* output)
    {
        auto pointer = data_->encrypted.Get();
        *output = ::media::mojom::DecoderBufferDataView(pointer, context_);
    }

    inline void Decryptor_Decrypt_ResponseParamsDataView::GetBufferDataView(
        ::media::mojom::DecoderBufferDataView* output)
    {
        auto pointer = data_->buffer.Get();
        *output = ::media::mojom::DecoderBufferDataView(pointer, context_);
    }

    inline void Decryptor_InitializeAudioDecoder_ParamsDataView::GetConfigDataView(
        ::media::mojom::AudioDecoderConfigDataView* output)
    {
        auto pointer = data_->config.Get();
        *output = ::media::mojom::AudioDecoderConfigDataView(pointer, context_);
    }

    inline void Decryptor_InitializeVideoDecoder_ParamsDataView::GetConfigDataView(
        ::media::mojom::VideoDecoderConfigDataView* output)
    {
        auto pointer = data_->config.Get();
        *output = ::media::mojom::VideoDecoderConfigDataView(pointer, context_);
    }

    inline void Decryptor_DecryptAndDecodeAudio_ParamsDataView::GetEncryptedDataView(
        ::media::mojom::DecoderBufferDataView* output)
    {
        auto pointer = data_->encrypted.Get();
        *output = ::media::mojom::DecoderBufferDataView(pointer, context_);
    }

    inline void Decryptor_DecryptAndDecodeAudio_ResponseParamsDataView::GetAudioBuffersDataView(
        mojo::ArrayDataView<::media::mojom::AudioBufferDataView>* output)
    {
        auto pointer = data_->audio_buffers.Get();
        *output = mojo::ArrayDataView<::media::mojom::AudioBufferDataView>(pointer, context_);
    }

    inline void Decryptor_DecryptAndDecodeVideo_ParamsDataView::GetEncryptedDataView(
        ::media::mojom::DecoderBufferDataView* output)
    {
        auto pointer = data_->encrypted.Get();
        *output = ::media::mojom::DecoderBufferDataView(pointer, context_);
    }

    inline void Decryptor_DecryptAndDecodeVideo_ResponseParamsDataView::GetVideoFrameDataView(
        ::media::mojom::VideoFrameDataView* output)
    {
        auto pointer = data_->video_frame.Get();
        *output = ::media::mojom::VideoFrameDataView(pointer, context_);
    }

} // namespace mojom
} // namespace media

#endif // MEDIA_MOJO_INTERFACES_DECRYPTOR_MOJOM_SHARED_H_
