// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_MOJO_INTERFACES_AUDIO_OUTPUT_MOJOM_H_
#define MEDIA_MOJO_INTERFACES_AUDIO_OUTPUT_MOJOM_H_

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
#include "media/mojo/interfaces/audio_output.mojom-shared.h"
#include "media/mojo/interfaces/audio_parameters.mojom.h"
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
    class AudioOutputStream;
    using AudioOutputStreamPtr = mojo::InterfacePtr<AudioOutputStream>;
    using AudioOutputStreamPtrInfo = mojo::InterfacePtrInfo<AudioOutputStream>;
    using ThreadSafeAudioOutputStreamPtr = mojo::ThreadSafeInterfacePtr<AudioOutputStream>;
    using AudioOutputStreamRequest = mojo::InterfaceRequest<AudioOutputStream>;
    using AudioOutputStreamAssociatedPtr = mojo::AssociatedInterfacePtr<AudioOutputStream>;
    using ThreadSafeAudioOutputStreamAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<AudioOutputStream>;
    using AudioOutputStreamAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<AudioOutputStream>;
    using AudioOutputStreamAssociatedRequest = mojo::AssociatedInterfaceRequest<AudioOutputStream>;

    class AudioOutput;
    using AudioOutputPtr = mojo::InterfacePtr<AudioOutput>;
    using AudioOutputPtrInfo = mojo::InterfacePtrInfo<AudioOutput>;
    using ThreadSafeAudioOutputPtr = mojo::ThreadSafeInterfacePtr<AudioOutput>;
    using AudioOutputRequest = mojo::InterfaceRequest<AudioOutput>;
    using AudioOutputAssociatedPtr = mojo::AssociatedInterfacePtr<AudioOutput>;
    using ThreadSafeAudioOutputAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<AudioOutput>;
    using AudioOutputAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<AudioOutput>;
    using AudioOutputAssociatedRequest = mojo::AssociatedInterfaceRequest<AudioOutput>;

    class AudioOutputStreamProxy;

    template <typename ImplRefTraits>
    class AudioOutputStreamStub;

    class AudioOutputStreamRequestValidator;

    class AudioOutputStream
        : public AudioOutputStreamInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = AudioOutputStreamProxy;

        template <typename ImplRefTraits>
        using Stub_ = AudioOutputStreamStub<ImplRefTraits>;

        using RequestValidator_ = AudioOutputStreamRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kCloseMinVersion = 0,
        };
        virtual ~AudioOutputStream() { }

        virtual void Close() = 0;
    };

    class AudioOutputProxy;

    template <typename ImplRefTraits>
    class AudioOutputStub;

    class AudioOutputRequestValidator;
    class AudioOutputResponseValidator;

    class AudioOutput
        : public AudioOutputInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = AudioOutputProxy;

        template <typename ImplRefTraits>
        using Stub_ = AudioOutputStub<ImplRefTraits>;

        using RequestValidator_ = AudioOutputRequestValidator;
        using ResponseValidator_ = AudioOutputResponseValidator;
        enum MethodMinVersions : uint32_t {
            kCreateStreamMinVersion = 0,
        };
        virtual ~AudioOutput() { }

        using CreateStreamCallback = base::Callback<void(int32_t, AudioOutputStreamPtr, mojo::ScopedSharedBufferHandle, mojo::ScopedHandle)>;
        virtual void CreateStream(int32_t stream_id, const media::AudioParameters& params, const CreateStreamCallback& callback) = 0;
    };

    class AudioOutputStreamProxy
        : public AudioOutputStream {
    public:
        explicit AudioOutputStreamProxy(mojo::MessageReceiverWithResponder* receiver);
        void Close() override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class AudioOutputProxy
        : public AudioOutput {
    public:
        explicit AudioOutputProxy(mojo::MessageReceiverWithResponder* receiver);
        void CreateStream(int32_t stream_id, const media::AudioParameters& params, const CreateStreamCallback& callback) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class AudioOutputStreamStubDispatch {
    public:
        static bool Accept(AudioOutputStream* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(AudioOutputStream* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<AudioOutputStream>>
    class AudioOutputStreamStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        AudioOutputStreamStub() { }
        ~AudioOutputStreamStub() override { }

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
            return AudioOutputStreamStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return AudioOutputStreamStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class AudioOutputStubDispatch {
    public:
        static bool Accept(AudioOutput* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(AudioOutput* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<AudioOutput>>
    class AudioOutputStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        AudioOutputStub() { }
        ~AudioOutputStub() override { }

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
            return AudioOutputStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return AudioOutputStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class AudioOutputStreamRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class AudioOutputRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class AudioOutputResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

} // namespace mojom
} // namespace media

namespace mojo {

} // namespace mojo

#endif // MEDIA_MOJO_INTERFACES_AUDIO_OUTPUT_MOJOM_H_