// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_MOJO_INTERFACES_VIDEO_DECODER_MOJOM_SHARED_H_
#define MEDIA_MOJO_INTERFACES_VIDEO_DECODER_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "media/mojo/interfaces/media_types.mojom-shared.h"
#include "media/mojo/interfaces/video_decoder.mojom-shared-internal.h"
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

namespace media {
namespace mojom {
    class CommandBufferIdDataView;

} // namespace mojom
} // namespace media

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::media::mojom::CommandBufferIdDataView> {
        using Data = ::media::mojom::internal::CommandBufferId_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace media {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class VideoDecoderInterfaceBase {
    };

    using VideoDecoderPtrDataView = mojo::InterfacePtrDataView<VideoDecoderInterfaceBase>;
    using VideoDecoderRequestDataView = mojo::InterfaceRequestDataView<VideoDecoderInterfaceBase>;
    using VideoDecoderAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<VideoDecoderInterfaceBase>;
    using VideoDecoderAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<VideoDecoderInterfaceBase>;
    class VideoDecoderClientInterfaceBase {
    };

    using VideoDecoderClientPtrDataView = mojo::InterfacePtrDataView<VideoDecoderClientInterfaceBase>;
    using VideoDecoderClientRequestDataView = mojo::InterfaceRequestDataView<VideoDecoderClientInterfaceBase>;
    using VideoDecoderClientAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<VideoDecoderClientInterfaceBase>;
    using VideoDecoderClientAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<VideoDecoderClientInterfaceBase>;
    class CommandBufferIdDataView {
    public:
        CommandBufferIdDataView() { }

        CommandBufferIdDataView(
            internal::CommandBufferId_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetChannelTokenDataView(
            ::mojo::common::mojom::UnguessableTokenDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadChannelToken(UserType* output)
        {
            auto* pointer = data_->channel_token.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::UnguessableTokenDataView>(
                pointer, output, context_);
        }
        int32_t route_id() const
        {
            return data_->route_id;
        }

    private:
        internal::CommandBufferId_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class VideoDecoder_Construct_ParamsDataView {
    public:
        VideoDecoder_Construct_ParamsDataView() { }

        VideoDecoder_Construct_ParamsDataView(
            internal::VideoDecoder_Construct_Params_Data* data,
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
            bool ret = mojo::internal::Deserialize<::media::mojom::VideoDecoderClientAssociatedPtrInfoDataView>(
                &data_->client, &result, context_);
            DCHECK(ret);
            return result;
        }
        mojo::ScopedDataPipeConsumerHandle TakeDecoderBufferPipe()
        {
            mojo::ScopedDataPipeConsumerHandle result;
            bool ret = mojo::internal::Deserialize<mojo::ScopedDataPipeConsumerHandle>(
                &data_->decoder_buffer_pipe, &result, context_);
            DCHECK(ret);
            return result;
        }
        inline void GetCommandBufferIdDataView(
            CommandBufferIdDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadCommandBufferId(UserType* output)
        {
            auto* pointer = data_->command_buffer_id.Get();
            return mojo::internal::Deserialize<::media::mojom::CommandBufferIdDataView>(
                pointer, output, context_);
        }

    private:
        internal::VideoDecoder_Construct_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class VideoDecoder_Initialize_ParamsDataView {
    public:
        VideoDecoder_Initialize_ParamsDataView() { }

        VideoDecoder_Initialize_ParamsDataView(
            internal::VideoDecoder_Initialize_Params_Data* data,
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
        bool low_delay() const
        {
            return data_->low_delay;
        }

    private:
        internal::VideoDecoder_Initialize_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class VideoDecoder_Initialize_ResponseParamsDataView {
    public:
        VideoDecoder_Initialize_ResponseParamsDataView() { }

        VideoDecoder_Initialize_ResponseParamsDataView(
            internal::VideoDecoder_Initialize_ResponseParams_Data* data,
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
        int32_t max_decode_requests() const
        {
            return data_->max_decode_requests;
        }

    private:
        internal::VideoDecoder_Initialize_ResponseParams_Data* data_ = nullptr;
    };

    class VideoDecoder_Decode_ParamsDataView {
    public:
        VideoDecoder_Decode_ParamsDataView() { }

        VideoDecoder_Decode_ParamsDataView(
            internal::VideoDecoder_Decode_Params_Data* data,
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
        internal::VideoDecoder_Decode_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class VideoDecoder_Decode_ResponseParamsDataView {
    public:
        VideoDecoder_Decode_ResponseParamsDataView() { }

        VideoDecoder_Decode_ResponseParamsDataView(
            internal::VideoDecoder_Decode_ResponseParams_Data* data,
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
        internal::VideoDecoder_Decode_ResponseParams_Data* data_ = nullptr;
    };

    class VideoDecoder_Reset_ParamsDataView {
    public:
        VideoDecoder_Reset_ParamsDataView() { }

        VideoDecoder_Reset_ParamsDataView(
            internal::VideoDecoder_Reset_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::VideoDecoder_Reset_Params_Data* data_ = nullptr;
    };

    class VideoDecoder_Reset_ResponseParamsDataView {
    public:
        VideoDecoder_Reset_ResponseParamsDataView() { }

        VideoDecoder_Reset_ResponseParamsDataView(
            internal::VideoDecoder_Reset_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::VideoDecoder_Reset_ResponseParams_Data* data_ = nullptr;
    };

    class VideoDecoderClient_OnVideoFrameDecoded_ParamsDataView {
    public:
        VideoDecoderClient_OnVideoFrameDecoded_ParamsDataView() { }

        VideoDecoderClient_OnVideoFrameDecoded_ParamsDataView(
            internal::VideoDecoderClient_OnVideoFrameDecoded_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetFrameDataView(
            ::media::mojom::VideoFrameDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFrame(UserType* output)
        {
            auto* pointer = data_->frame.Get();
            return mojo::internal::Deserialize<::media::mojom::VideoFrameDataView>(
                pointer, output, context_);
        }

    private:
        internal::VideoDecoderClient_OnVideoFrameDecoded_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace media

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::media::mojom::CommandBufferIdDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::media::mojom::CommandBufferIdDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::media::mojom::internal::CommandBufferId_Data);
            decltype(CallWithContext(Traits::channel_token, input, custom_context)) in_channel_token = CallWithContext(Traits::channel_token, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::UnguessableTokenDataView>(
                in_channel_token, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::media::mojom::internal::CommandBufferId_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::media::mojom::internal::CommandBufferId_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::channel_token, input, custom_context)) in_channel_token = CallWithContext(Traits::channel_token, input, custom_context);
            typename decltype(result->channel_token)::BaseType* channel_token_ptr;
            mojo::internal::Serialize<::mojo::common::mojom::UnguessableTokenDataView>(
                in_channel_token, buffer, &channel_token_ptr, context);
            result->channel_token.Set(channel_token_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->channel_token.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null channel_token in CommandBufferId struct");
            result->route_id = CallWithContext(Traits::route_id, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::media::mojom::internal::CommandBufferId_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::media::mojom::CommandBufferIdDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace media {
namespace mojom {

    inline void CommandBufferIdDataView::GetChannelTokenDataView(
        ::mojo::common::mojom::UnguessableTokenDataView* output)
    {
        auto pointer = data_->channel_token.Get();
        *output = ::mojo::common::mojom::UnguessableTokenDataView(pointer, context_);
    }

    inline void VideoDecoder_Construct_ParamsDataView::GetCommandBufferIdDataView(
        CommandBufferIdDataView* output)
    {
        auto pointer = data_->command_buffer_id.Get();
        *output = CommandBufferIdDataView(pointer, context_);
    }

    inline void VideoDecoder_Initialize_ParamsDataView::GetConfigDataView(
        ::media::mojom::VideoDecoderConfigDataView* output)
    {
        auto pointer = data_->config.Get();
        *output = ::media::mojom::VideoDecoderConfigDataView(pointer, context_);
    }

    inline void VideoDecoder_Decode_ParamsDataView::GetBufferDataView(
        ::media::mojom::DecoderBufferDataView* output)
    {
        auto pointer = data_->buffer.Get();
        *output = ::media::mojom::DecoderBufferDataView(pointer, context_);
    }

    inline void VideoDecoderClient_OnVideoFrameDecoded_ParamsDataView::GetFrameDataView(
        ::media::mojom::VideoFrameDataView* output)
    {
        auto pointer = data_->frame.Get();
        *output = ::media::mojom::VideoFrameDataView(pointer, context_);
    }

} // namespace mojom
} // namespace media

#endif // MEDIA_MOJO_INTERFACES_VIDEO_DECODER_MOJOM_SHARED_H_
