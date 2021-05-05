// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_MOJO_INTERFACES_DECRYPTOR_MOJOM_H_
#define MEDIA_MOJO_INTERFACES_DECRYPTOR_MOJOM_H_

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
#include "media/mojo/interfaces/decryptor.mojom-shared.h"
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
    class Decryptor;
    using DecryptorPtr = mojo::InterfacePtr<Decryptor>;
    using DecryptorPtrInfo = mojo::InterfacePtrInfo<Decryptor>;
    using ThreadSafeDecryptorPtr = mojo::ThreadSafeInterfacePtr<Decryptor>;
    using DecryptorRequest = mojo::InterfaceRequest<Decryptor>;
    using DecryptorAssociatedPtr = mojo::AssociatedInterfacePtr<Decryptor>;
    using ThreadSafeDecryptorAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<Decryptor>;
    using DecryptorAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<Decryptor>;
    using DecryptorAssociatedRequest = mojo::AssociatedInterfaceRequest<Decryptor>;

    class DecryptorProxy;

    template <typename ImplRefTraits>
    class DecryptorStub;

    class DecryptorRequestValidator;
    class DecryptorResponseValidator;

    class Decryptor
        : public DecryptorInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = DecryptorProxy;

        template <typename ImplRefTraits>
        using Stub_ = DecryptorStub<ImplRefTraits>;

        using RequestValidator_ = DecryptorRequestValidator;
        using ResponseValidator_ = DecryptorResponseValidator;
        enum MethodMinVersions : uint32_t {
            kInitializeMinVersion = 0,
            kDecryptMinVersion = 0,
            kCancelDecryptMinVersion = 0,
            kInitializeAudioDecoderMinVersion = 0,
            kInitializeVideoDecoderMinVersion = 0,
            kDecryptAndDecodeAudioMinVersion = 0,
            kDecryptAndDecodeVideoMinVersion = 0,
            kResetDecoderMinVersion = 0,
            kDeinitializeDecoderMinVersion = 0,
            kReleaseSharedBufferMinVersion = 0,
        };
        using Status = Decryptor_Status;
        using StreamType = Decryptor_StreamType;
        virtual ~Decryptor() { }

        virtual void Initialize(mojo::ScopedDataPipeConsumerHandle receive_pipe, mojo::ScopedDataPipeProducerHandle transmit_pipe) = 0;

        using DecryptCallback = base::Callback<void(media::Decryptor::Status, ::media::mojom::DecoderBufferPtr)>;
        virtual void Decrypt(media::Decryptor::StreamType stream_type, ::media::mojom::DecoderBufferPtr encrypted, const DecryptCallback& callback) = 0;

        virtual void CancelDecrypt(media::Decryptor::StreamType stream_type) = 0;

        using InitializeAudioDecoderCallback = base::Callback<void(bool)>;
        virtual void InitializeAudioDecoder(::media::mojom::AudioDecoderConfigPtr config, const InitializeAudioDecoderCallback& callback) = 0;

        using InitializeVideoDecoderCallback = base::Callback<void(bool)>;
        virtual void InitializeVideoDecoder(::media::mojom::VideoDecoderConfigPtr config, const InitializeVideoDecoderCallback& callback) = 0;

        using DecryptAndDecodeAudioCallback = base::Callback<void(media::Decryptor::Status, std::vector<::media::mojom::AudioBufferPtr>)>;
        virtual void DecryptAndDecodeAudio(::media::mojom::DecoderBufferPtr encrypted, const DecryptAndDecodeAudioCallback& callback) = 0;

        using DecryptAndDecodeVideoCallback = base::Callback<void(media::Decryptor::Status, ::media::mojom::VideoFramePtr)>;
        virtual void DecryptAndDecodeVideo(::media::mojom::DecoderBufferPtr encrypted, const DecryptAndDecodeVideoCallback& callback) = 0;

        virtual void ResetDecoder(media::Decryptor::StreamType stream_type) = 0;

        virtual void DeinitializeDecoder(media::Decryptor::StreamType stream_type) = 0;

        virtual void ReleaseSharedBuffer(mojo::ScopedSharedBufferHandle buffer, uint64_t buffer_size) = 0;
    };

    class DecryptorProxy
        : public Decryptor {
    public:
        explicit DecryptorProxy(mojo::MessageReceiverWithResponder* receiver);
        void Initialize(mojo::ScopedDataPipeConsumerHandle receive_pipe, mojo::ScopedDataPipeProducerHandle transmit_pipe) override;
        void Decrypt(media::Decryptor::StreamType stream_type, ::media::mojom::DecoderBufferPtr encrypted, const DecryptCallback& callback) override;
        void CancelDecrypt(media::Decryptor::StreamType stream_type) override;
        void InitializeAudioDecoder(::media::mojom::AudioDecoderConfigPtr config, const InitializeAudioDecoderCallback& callback) override;
        void InitializeVideoDecoder(::media::mojom::VideoDecoderConfigPtr config, const InitializeVideoDecoderCallback& callback) override;
        void DecryptAndDecodeAudio(::media::mojom::DecoderBufferPtr encrypted, const DecryptAndDecodeAudioCallback& callback) override;
        void DecryptAndDecodeVideo(::media::mojom::DecoderBufferPtr encrypted, const DecryptAndDecodeVideoCallback& callback) override;
        void ResetDecoder(media::Decryptor::StreamType stream_type) override;
        void DeinitializeDecoder(media::Decryptor::StreamType stream_type) override;
        void ReleaseSharedBuffer(mojo::ScopedSharedBufferHandle buffer, uint64_t buffer_size) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class DecryptorStubDispatch {
    public:
        static bool Accept(Decryptor* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(Decryptor* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<Decryptor>>
    class DecryptorStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        DecryptorStub() { }
        ~DecryptorStub() override { }

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
            return DecryptorStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return DecryptorStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class DecryptorRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class DecryptorResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

} // namespace mojom
} // namespace media

namespace mojo {

} // namespace mojo

#endif // MEDIA_MOJO_INTERFACES_DECRYPTOR_MOJOM_H_