// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_MOJO_INTERFACES_AUDIO_DECODER_MOJOM_H_
#define MEDIA_MOJO_INTERFACES_AUDIO_DECODER_MOJOM_H_

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
#include "media/mojo/interfaces/audio_decoder.mojom-shared.h"
#include "media/mojo/interfaces/media_types.mojom.h"
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
    class AudioDecoder;
    using AudioDecoderPtr = mojo::InterfacePtr<AudioDecoder>;
    using AudioDecoderPtrInfo = mojo::InterfacePtrInfo<AudioDecoder>;
    using ThreadSafeAudioDecoderPtr = mojo::ThreadSafeInterfacePtr<AudioDecoder>;
    using AudioDecoderRequest = mojo::InterfaceRequest<AudioDecoder>;
    using AudioDecoderAssociatedPtr = mojo::AssociatedInterfacePtr<AudioDecoder>;
    using ThreadSafeAudioDecoderAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<AudioDecoder>;
    using AudioDecoderAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<AudioDecoder>;
    using AudioDecoderAssociatedRequest = mojo::AssociatedInterfaceRequest<AudioDecoder>;

    class AudioDecoderClient;
    using AudioDecoderClientPtr = mojo::InterfacePtr<AudioDecoderClient>;
    using AudioDecoderClientPtrInfo = mojo::InterfacePtrInfo<AudioDecoderClient>;
    using ThreadSafeAudioDecoderClientPtr = mojo::ThreadSafeInterfacePtr<AudioDecoderClient>;
    using AudioDecoderClientRequest = mojo::InterfaceRequest<AudioDecoderClient>;
    using AudioDecoderClientAssociatedPtr = mojo::AssociatedInterfacePtr<AudioDecoderClient>;
    using ThreadSafeAudioDecoderClientAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<AudioDecoderClient>;
    using AudioDecoderClientAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<AudioDecoderClient>;
    using AudioDecoderClientAssociatedRequest = mojo::AssociatedInterfaceRequest<AudioDecoderClient>;

    class AudioDecoderProxy;

    template <typename ImplRefTraits>
    class AudioDecoderStub;

    class AudioDecoderRequestValidator;
    class AudioDecoderResponseValidator;

    class AudioDecoder
        : public AudioDecoderInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = true;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = AudioDecoderProxy;

        template <typename ImplRefTraits>
        using Stub_ = AudioDecoderStub<ImplRefTraits>;

        using RequestValidator_ = AudioDecoderRequestValidator;
        using ResponseValidator_ = AudioDecoderResponseValidator;
        enum MethodMinVersions : uint32_t {
            kConstructMinVersion = 0,
            kInitializeMinVersion = 0,
            kSetDataSourceMinVersion = 0,
            kDecodeMinVersion = 0,
            kResetMinVersion = 0,
        };
        virtual ~AudioDecoder() { }

        virtual void Construct(AudioDecoderClientAssociatedPtrInfo client) = 0;

        using InitializeCallback = base::Callback<void(bool, bool)>;
        virtual void Initialize(::media::mojom::AudioDecoderConfigPtr config, int32_t cdm_id, const InitializeCallback& callback) = 0;

        virtual void SetDataSource(mojo::ScopedDataPipeConsumerHandle receive_pipe) = 0;

        using DecodeCallback = base::Callback<void(media::DecodeStatus)>;
        virtual void Decode(::media::mojom::DecoderBufferPtr buffer, const DecodeCallback& callback) = 0;

        using ResetCallback = base::Callback<void()>;
        virtual void Reset(const ResetCallback& callback) = 0;
    };

    class AudioDecoderClientProxy;

    template <typename ImplRefTraits>
    class AudioDecoderClientStub;

    class AudioDecoderClientRequestValidator;

    class AudioDecoderClient
        : public AudioDecoderClientInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = AudioDecoderClientProxy;

        template <typename ImplRefTraits>
        using Stub_ = AudioDecoderClientStub<ImplRefTraits>;

        using RequestValidator_ = AudioDecoderClientRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kOnBufferDecodedMinVersion = 0,
        };
        virtual ~AudioDecoderClient() { }

        virtual void OnBufferDecoded(::media::mojom::AudioBufferPtr buffer) = 0;
    };

    class AudioDecoderProxy
        : public AudioDecoder {
    public:
        explicit AudioDecoderProxy(mojo::MessageReceiverWithResponder* receiver);
        void Construct(AudioDecoderClientAssociatedPtrInfo client) override;
        void Initialize(::media::mojom::AudioDecoderConfigPtr config, int32_t cdm_id, const InitializeCallback& callback) override;
        void SetDataSource(mojo::ScopedDataPipeConsumerHandle receive_pipe) override;
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

    class AudioDecoderClientProxy
        : public AudioDecoderClient {
    public:
        explicit AudioDecoderClientProxy(mojo::MessageReceiverWithResponder* receiver);
        void OnBufferDecoded(::media::mojom::AudioBufferPtr buffer) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class AudioDecoderStubDispatch {
    public:
        static bool Accept(AudioDecoder* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(AudioDecoder* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<AudioDecoder>>
    class AudioDecoderStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        AudioDecoderStub() { }
        ~AudioDecoderStub() override { }

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
            return AudioDecoderStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return AudioDecoderStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class AudioDecoderClientStubDispatch {
    public:
        static bool Accept(AudioDecoderClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(AudioDecoderClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<AudioDecoderClient>>
    class AudioDecoderClientStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        AudioDecoderClientStub() { }
        ~AudioDecoderClientStub() override { }

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
            return AudioDecoderClientStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return AudioDecoderClientStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class AudioDecoderRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class AudioDecoderClientRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class AudioDecoderResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

} // namespace mojom
} // namespace media

namespace mojo {

} // namespace mojo

#endif // MEDIA_MOJO_INTERFACES_AUDIO_DECODER_MOJOM_H_