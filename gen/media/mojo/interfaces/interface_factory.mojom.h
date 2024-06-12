// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_MOJO_INTERFACES_INTERFACE_FACTORY_MOJOM_H_
#define MEDIA_MOJO_INTERFACES_INTERFACE_FACTORY_MOJOM_H_

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
#include "media/mojo/interfaces/audio_decoder.mojom.h"
#include "media/mojo/interfaces/content_decryption_module.mojom.h"
#include "media/mojo/interfaces/interface_factory.mojom-shared.h"
#include "media/mojo/interfaces/renderer.mojom.h"
#include "media/mojo/interfaces/video_decoder.mojom.h"
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
    class InterfaceFactory;
    using InterfaceFactoryPtr = mojo::InterfacePtr<InterfaceFactory>;
    using InterfaceFactoryPtrInfo = mojo::InterfacePtrInfo<InterfaceFactory>;
    using ThreadSafeInterfaceFactoryPtr = mojo::ThreadSafeInterfacePtr<InterfaceFactory>;
    using InterfaceFactoryRequest = mojo::InterfaceRequest<InterfaceFactory>;
    using InterfaceFactoryAssociatedPtr = mojo::AssociatedInterfacePtr<InterfaceFactory>;
    using ThreadSafeInterfaceFactoryAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<InterfaceFactory>;
    using InterfaceFactoryAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<InterfaceFactory>;
    using InterfaceFactoryAssociatedRequest = mojo::AssociatedInterfaceRequest<InterfaceFactory>;

    class InterfaceFactoryProxy;

    template <typename ImplRefTraits>
    class InterfaceFactoryStub;

    class InterfaceFactoryRequestValidator;

    class InterfaceFactory
        : public InterfaceFactoryInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = InterfaceFactoryProxy;

        template <typename ImplRefTraits>
        using Stub_ = InterfaceFactoryStub<ImplRefTraits>;

        using RequestValidator_ = InterfaceFactoryRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kCreateAudioDecoderMinVersion = 0,
            kCreateVideoDecoderMinVersion = 0,
            kCreateRendererMinVersion = 0,
            kCreateCdmMinVersion = 0,
        };
        virtual ~InterfaceFactory() { }

        virtual void CreateAudioDecoder(::media::mojom::AudioDecoderRequest audio_decoder) = 0;

        virtual void CreateVideoDecoder(::media::mojom::VideoDecoderRequest video_decoder) = 0;

        virtual void CreateRenderer(const std::string& audio_device_id, ::media::mojom::RendererRequest renderer) = 0;

        virtual void CreateCdm(::media::mojom::ContentDecryptionModuleRequest cdm) = 0;
    };

    class InterfaceFactoryProxy
        : public InterfaceFactory {
    public:
        explicit InterfaceFactoryProxy(mojo::MessageReceiverWithResponder* receiver);
        void CreateAudioDecoder(::media::mojom::AudioDecoderRequest audio_decoder) override;
        void CreateVideoDecoder(::media::mojom::VideoDecoderRequest video_decoder) override;
        void CreateRenderer(const std::string& audio_device_id, ::media::mojom::RendererRequest renderer) override;
        void CreateCdm(::media::mojom::ContentDecryptionModuleRequest cdm) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class InterfaceFactoryStubDispatch {
    public:
        static bool Accept(InterfaceFactory* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(InterfaceFactory* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<InterfaceFactory>>
    class InterfaceFactoryStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        InterfaceFactoryStub() { }
        ~InterfaceFactoryStub() override { }

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
            return InterfaceFactoryStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return InterfaceFactoryStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class InterfaceFactoryRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

} // namespace mojom
} // namespace media

namespace mojo {

} // namespace mojo

#endif // MEDIA_MOJO_INTERFACES_INTERFACE_FACTORY_MOJOM_H_