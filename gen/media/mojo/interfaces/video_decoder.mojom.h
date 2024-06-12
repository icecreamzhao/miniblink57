// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_MOJO_INTERFACES_VIDEO_DECODER_MOJOM_H_
#define MEDIA_MOJO_INTERFACES_VIDEO_DECODER_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/files/file.h"
#include "base/files/file_path.h"
#include "base/i18n/rtl.h"
#include "base/optional.h"
#include "base/strings/string16.h"
#include "base/time/time.h"
#include "base/unguessable_token.h"
#include "base/values.h"
#include "base/version.h"
#include "media/base/audio_codecs.h"
#include "media/base/audio_parameters.h"
#include "media/base/buffering_state.h"
#include "media/base/cdm_key_information.h"
#include "media/base/cdm_promise.h"
#include "media/base/channel_layout.h"
#include "media/base/content_decryption_module.h"
#include "media/base/decode_status.h"
#include "media/base/decryptor.h"
#include "media/base/demuxer_stream.h"
#include "media/base/eme_constants.h"
#include "media/base/encryption_scheme.h"
#include "media/base/pipeline_status.h"
#include "media/base/sample_format.h"
#include "media/base/subsample_entry.h"
#include "media/base/video_codecs.h"
#include "media/base/video_types.h"
#include "media/mojo/interfaces/media_types.mojom.h"
#include "media/mojo/interfaces/video_decoder.mojom-shared.h"
#include "mojo/common/unguessable_token.mojom.h"
#include "mojo/public/cpp/bindings/associated_interface_ptr.h"
#include "mojo/public/cpp/bindings/associated_interface_ptr_info.h"
#include "mojo/public/cpp/bindings/associated_interface_request.h"
#include "mojo/public/cpp/bindings/interface_ptr.h"
#include "mojo/public/cpp/bindings/interface_request.h"
#include "mojo/public/cpp/bindings/lib/clone_equals_util.h"
#include "mojo/public/cpp/bindings/lib/control_message_handler.h"
#include "mojo/public/cpp/bindings/lib/control_message_proxy.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/lib/union_accessor.h"
#include "mojo/public/cpp/bindings/native_struct.h"
#include "mojo/public/cpp/bindings/no_interface.h"
#include "mojo/public/cpp/bindings/raw_ptr_impl_ref_traits.h"
#include "mojo/public/cpp/bindings/struct_ptr.h"
#include "mojo/public/cpp/bindings/struct_traits.h"
#include "mojo/public/cpp/bindings/thread_safe_interface_ptr.h"
#include "mojo/public/cpp/bindings/union_traits.h"
#include "services/service_manager/public/cpp/identity.h"
#include "services/service_manager/public/cpp/interface_provider_spec.h"
#include "services/service_manager/public/cpp/service_info.h"
#include "ui/gfx/geometry/insets.h"
#include "ui/gfx/geometry/point.h"
#include "ui/gfx/geometry/point_f.h"
#include "ui/gfx/geometry/rect.h"
#include "ui/gfx/geometry/rect_f.h"
#include "ui/gfx/geometry/safe_integer_conversions.h"
#include "ui/gfx/geometry/size.h"
#include "ui/gfx/geometry/vector2d.h"
#include "ui/gfx/geometry/vector2d_f.h"
#include "url/gurl.h"
#include <string>
#include <vector>

namespace media {
namespace mojom {
    class VideoDecoder;
    using VideoDecoderPtr = mojo::InterfacePtr<VideoDecoder>;
    using VideoDecoderPtrInfo = mojo::InterfacePtrInfo<VideoDecoder>;
    using ThreadSafeVideoDecoderPtr = mojo::ThreadSafeInterfacePtr<VideoDecoder>;
    using VideoDecoderRequest = mojo::InterfaceRequest<VideoDecoder>;
    using VideoDecoderAssociatedPtr = mojo::AssociatedInterfacePtr<VideoDecoder>;
    using ThreadSafeVideoDecoderAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<VideoDecoder>;
    using VideoDecoderAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<VideoDecoder>;
    using VideoDecoderAssociatedRequest = mojo::AssociatedInterfaceRequest<VideoDecoder>;

    class VideoDecoderClient;
    using VideoDecoderClientPtr = mojo::InterfacePtr<VideoDecoderClient>;
    using VideoDecoderClientPtrInfo = mojo::InterfacePtrInfo<VideoDecoderClient>;
    using ThreadSafeVideoDecoderClientPtr = mojo::ThreadSafeInterfacePtr<VideoDecoderClient>;
    using VideoDecoderClientRequest = mojo::InterfaceRequest<VideoDecoderClient>;
    using VideoDecoderClientAssociatedPtr = mojo::AssociatedInterfacePtr<VideoDecoderClient>;
    using ThreadSafeVideoDecoderClientAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<VideoDecoderClient>;
    using VideoDecoderClientAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<VideoDecoderClient>;
    using VideoDecoderClientAssociatedRequest = mojo::AssociatedInterfaceRequest<VideoDecoderClient>;

    class CommandBufferId;
    using CommandBufferIdPtr = mojo::StructPtr<CommandBufferId>;

    class VideoDecoderProxy;

    template <typename ImplRefTraits>
    class VideoDecoderStub;

    class VideoDecoderRequestValidator;
    class VideoDecoderResponseValidator;

    class VideoDecoder
        : public VideoDecoderInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = true;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = VideoDecoderProxy;

        template <typename ImplRefTraits>
        using Stub_ = VideoDecoderStub<ImplRefTraits>;

        using RequestValidator_ = VideoDecoderRequestValidator;
        using ResponseValidator_ = VideoDecoderResponseValidator;
        enum MethodMinVersions : uint32_t {
            kConstructMinVersion = 0,
            kInitializeMinVersion = 0,
            kDecodeMinVersion = 0,
            kResetMinVersion = 0,
        };
        virtual ~VideoDecoder() { }

        virtual void Construct(VideoDecoderClientAssociatedPtrInfo client, mojo::ScopedDataPipeConsumerHandle decoder_buffer_pipe, CommandBufferIdPtr command_buffer_id) = 0;

        using InitializeCallback = base::Callback<void(bool, bool, int32_t)>;
        virtual void Initialize(::media::mojom::VideoDecoderConfigPtr config, bool low_delay, const InitializeCallback& callback) = 0;

        using DecodeCallback = base::Callback<void(media::DecodeStatus)>;
        virtual void Decode(::media::mojom::DecoderBufferPtr buffer, const DecodeCallback& callback) = 0;

        using ResetCallback = base::Callback<void()>;
        virtual void Reset(const ResetCallback& callback) = 0;
    };

    class VideoDecoderClientProxy;

    template <typename ImplRefTraits>
    class VideoDecoderClientStub;

    class VideoDecoderClientRequestValidator;

    class VideoDecoderClient
        : public VideoDecoderClientInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = VideoDecoderClientProxy;

        template <typename ImplRefTraits>
        using Stub_ = VideoDecoderClientStub<ImplRefTraits>;

        using RequestValidator_ = VideoDecoderClientRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kOnVideoFrameDecodedMinVersion = 0,
        };
        virtual ~VideoDecoderClient() { }

        virtual void OnVideoFrameDecoded(::media::mojom::VideoFramePtr frame) = 0;
    };

    class VideoDecoderProxy
        : public VideoDecoder {
    public:
        explicit VideoDecoderProxy(mojo::MessageReceiverWithResponder* receiver);
        void Construct(VideoDecoderClientAssociatedPtrInfo client, mojo::ScopedDataPipeConsumerHandle decoder_buffer_pipe, CommandBufferIdPtr command_buffer_id) override;
        void Initialize(::media::mojom::VideoDecoderConfigPtr config, bool low_delay, const InitializeCallback& callback) override;
        void Decode(::media::mojom::DecoderBufferPtr buffer, const DecodeCallback& callback) override;
        void Reset(const ResetCallback& callback) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class VideoDecoderClientProxy
        : public VideoDecoderClient {
    public:
        explicit VideoDecoderClientProxy(mojo::MessageReceiverWithResponder* receiver);
        void OnVideoFrameDecoded(::media::mojom::VideoFramePtr frame) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class VideoDecoderStubDispatch {
    public:
        static bool Accept(VideoDecoder* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(VideoDecoder* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<VideoDecoder>>
    class VideoDecoderStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        VideoDecoderStub() { }
        ~VideoDecoderStub() override { }

        void set_sink(ImplPointerType sink) { sink_ = std::move(sink); }
        ImplPointerType& sink() { return sink_; }

        mojo::internal::SerializationContext* serialization_context()
        {
            return &serialization_context_;
        }

        bool Accept(mojo::Message* message) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return VideoDecoderStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return VideoDecoderStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class VideoDecoderClientStubDispatch {
    public:
        static bool Accept(VideoDecoderClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(VideoDecoderClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<VideoDecoderClient>>
    class VideoDecoderClientStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        VideoDecoderClientStub() { }
        ~VideoDecoderClientStub() override { }

        void set_sink(ImplPointerType sink) { sink_ = std::move(sink); }
        ImplPointerType& sink() { return sink_; }

        mojo::internal::SerializationContext* serialization_context()
        {
            return &serialization_context_;
        }

        bool Accept(mojo::Message* message) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return VideoDecoderClientStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return VideoDecoderClientStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class VideoDecoderRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class VideoDecoderClientRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class VideoDecoderResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

    class CommandBufferId {
    public:
        using DataView = CommandBufferIdDataView;
        using Data_ = internal::CommandBufferId_Data;

        static CommandBufferIdPtr New();

        template <typename U>
        static CommandBufferIdPtr From(const U& u)
        {
            return mojo::TypeConverter<CommandBufferIdPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, CommandBufferId>::Convert(*this);
        }

        CommandBufferId();
        ~CommandBufferId();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = CommandBufferIdPtr>
        CommandBufferIdPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, CommandBufferId>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                CommandBufferId::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                CommandBufferId::DataView, std::vector<uint8_t>>(
                input, output);
        }

        base::UnguessableToken channel_token;
        int32_t route_id;
    };

    template <typename StructPtrType>
    CommandBufferIdPtr CommandBufferId::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->channel_token = mojo::internal::Clone(channel_token);
        rv->route_id = mojo::internal::Clone(route_id);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, CommandBufferId>::value>::type*>
    bool CommandBufferId::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->channel_token, other.channel_token))
            return false;
        if (!mojo::internal::Equals(this->route_id, other.route_id))
            return false;
        return true;
    }

} // namespace mojom
} // namespace media

namespace mojo {

template <>
struct StructTraits<::media::mojom::CommandBufferId::DataView,
    ::media::mojom::CommandBufferIdPtr> {
    static bool IsNull(const ::media::mojom::CommandBufferIdPtr& input) { return !input; }
    static void SetToNull(::media::mojom::CommandBufferIdPtr* output) { output->reset(); }

    static const decltype(::media::mojom::CommandBufferId::channel_token)& channel_token(
        const ::media::mojom::CommandBufferIdPtr& input)
    {
        return input->channel_token;
    }

    static decltype(::media::mojom::CommandBufferId::route_id) route_id(
        const ::media::mojom::CommandBufferIdPtr& input)
    {
        return input->route_id;
    }

    static bool Read(::media::mojom::CommandBufferId::DataView input, ::media::mojom::CommandBufferIdPtr* output);
};

} // namespace mojo

#endif // MEDIA_MOJO_INTERFACES_VIDEO_DECODER_MOJOM_H_