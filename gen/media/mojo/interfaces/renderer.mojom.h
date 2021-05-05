// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_MOJO_INTERFACES_RENDERER_MOJOM_H_
#define MEDIA_MOJO_INTERFACES_RENDERER_MOJOM_H_

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
#include "media/mojo/interfaces/demuxer_stream.mojom.h"
#include "media/mojo/interfaces/media_types.mojom.h"
#include "media/mojo/interfaces/renderer.mojom-shared.h"
#include "mojo/common/time.mojom.h"
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
#include "ui/gfx/geometry/mojo/geometry.mojom.h"
#include "ui/gfx/geometry/point.h"
#include "ui/gfx/geometry/point_f.h"
#include "ui/gfx/geometry/rect.h"
#include "ui/gfx/geometry/rect_f.h"
#include "ui/gfx/geometry/safe_integer_conversions.h"
#include "ui/gfx/geometry/size.h"
#include "ui/gfx/geometry/vector2d.h"
#include "ui/gfx/geometry/vector2d_f.h"
#include "url/gurl.h"
#include "url/mojo/url.mojom.h"
#include <string>
#include <vector>

namespace media {
namespace mojom {
    class Renderer;
    using RendererPtr = mojo::InterfacePtr<Renderer>;
    using RendererPtrInfo = mojo::InterfacePtrInfo<Renderer>;
    using ThreadSafeRendererPtr = mojo::ThreadSafeInterfacePtr<Renderer>;
    using RendererRequest = mojo::InterfaceRequest<Renderer>;
    using RendererAssociatedPtr = mojo::AssociatedInterfacePtr<Renderer>;
    using ThreadSafeRendererAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<Renderer>;
    using RendererAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<Renderer>;
    using RendererAssociatedRequest = mojo::AssociatedInterfaceRequest<Renderer>;

    class RendererClient;
    using RendererClientPtr = mojo::InterfacePtr<RendererClient>;
    using RendererClientPtrInfo = mojo::InterfacePtrInfo<RendererClient>;
    using ThreadSafeRendererClientPtr = mojo::ThreadSafeInterfacePtr<RendererClient>;
    using RendererClientRequest = mojo::InterfaceRequest<RendererClient>;
    using RendererClientAssociatedPtr = mojo::AssociatedInterfacePtr<RendererClient>;
    using ThreadSafeRendererClientAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<RendererClient>;
    using RendererClientAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<RendererClient>;
    using RendererClientAssociatedRequest = mojo::AssociatedInterfaceRequest<RendererClient>;

    class RendererProxy;

    template <typename ImplRefTraits>
    class RendererStub;

    class RendererRequestValidator;
    class RendererResponseValidator;

    class Renderer
        : public RendererInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = true;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = RendererProxy;

        template <typename ImplRefTraits>
        using Stub_ = RendererStub<ImplRefTraits>;

        using RequestValidator_ = RendererRequestValidator;
        using ResponseValidator_ = RendererResponseValidator;
        enum MethodMinVersions : uint32_t {
            kInitializeMinVersion = 0,
            kFlushMinVersion = 0,
            kStartPlayingFromMinVersion = 0,
            kSetPlaybackRateMinVersion = 0,
            kSetVolumeMinVersion = 0,
            kSetCdmMinVersion = 0,
            kInitiateScopedSurfaceRequestMinVersion = 0,
        };
        virtual ~Renderer() { }

        using InitializeCallback = base::Callback<void(bool)>;
        virtual void Initialize(RendererClientAssociatedPtrInfo client, ::media::mojom::DemuxerStreamPtr audio, ::media::mojom::DemuxerStreamPtr video, const base::Optional<GURL>& media_url, const base::Optional<GURL>& first_party_for_cookies, const InitializeCallback& callback) = 0;

        using FlushCallback = base::Callback<void()>;
        virtual void Flush(const FlushCallback& callback) = 0;

        virtual void StartPlayingFrom(base::TimeDelta time) = 0;

        virtual void SetPlaybackRate(double playback_rate) = 0;

        virtual void SetVolume(float volume) = 0;

        using SetCdmCallback = base::Callback<void(bool)>;
        virtual void SetCdm(int32_t cdm_id, const SetCdmCallback& callback) = 0;

        using InitiateScopedSurfaceRequestCallback = base::Callback<void(const base::UnguessableToken&)>;
        virtual void InitiateScopedSurfaceRequest(const InitiateScopedSurfaceRequestCallback& callback) = 0;
    };

    class RendererClientProxy;

    template <typename ImplRefTraits>
    class RendererClientStub;

    class RendererClientRequestValidator;

    class RendererClient
        : public RendererClientInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = RendererClientProxy;

        template <typename ImplRefTraits>
        using Stub_ = RendererClientStub<ImplRefTraits>;

        using RequestValidator_ = RendererClientRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kOnTimeUpdateMinVersion = 0,
            kOnBufferingStateChangeMinVersion = 0,
            kOnEndedMinVersion = 0,
            kOnErrorMinVersion = 0,
            kOnVideoNaturalSizeChangeMinVersion = 0,
            kOnVideoOpacityChangeMinVersion = 0,
            kOnStatisticsUpdateMinVersion = 0,
            kOnWaitingForDecryptionKeyMinVersion = 0,
            kOnDurationChangeMinVersion = 0,
        };
        virtual ~RendererClient() { }

        virtual void OnTimeUpdate(base::TimeDelta time, base::TimeDelta max_time, base::TimeTicks capture_time) = 0;

        virtual void OnBufferingStateChange(media::BufferingState state) = 0;

        virtual void OnEnded() = 0;

        virtual void OnError() = 0;

        virtual void OnVideoNaturalSizeChange(const gfx::Size& size) = 0;

        virtual void OnVideoOpacityChange(bool opaque) = 0;

        virtual void OnStatisticsUpdate(const media::PipelineStatistics& stats) = 0;

        virtual void OnWaitingForDecryptionKey() = 0;

        virtual void OnDurationChange(base::TimeDelta duration) = 0;
    };

    class RendererProxy
        : public Renderer {
    public:
        explicit RendererProxy(mojo::MessageReceiverWithResponder* receiver);
        void Initialize(RendererClientAssociatedPtrInfo client, ::media::mojom::DemuxerStreamPtr audio, ::media::mojom::DemuxerStreamPtr video, const base::Optional<GURL>& media_url, const base::Optional<GURL>& first_party_for_cookies, const InitializeCallback& callback) override;
        void Flush(const FlushCallback& callback) override;
        void StartPlayingFrom(base::TimeDelta time) override;
        void SetPlaybackRate(double playback_rate) override;
        void SetVolume(float volume) override;
        void SetCdm(int32_t cdm_id, const SetCdmCallback& callback) override;
        void InitiateScopedSurfaceRequest(const InitiateScopedSurfaceRequestCallback& callback) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class RendererClientProxy
        : public RendererClient {
    public:
        explicit RendererClientProxy(mojo::MessageReceiverWithResponder* receiver);
        void OnTimeUpdate(base::TimeDelta time, base::TimeDelta max_time, base::TimeTicks capture_time) override;
        void OnBufferingStateChange(media::BufferingState state) override;
        void OnEnded() override;
        void OnError() override;
        void OnVideoNaturalSizeChange(const gfx::Size& size) override;
        void OnVideoOpacityChange(bool opaque) override;
        void OnStatisticsUpdate(const media::PipelineStatistics& stats) override;
        void OnWaitingForDecryptionKey() override;
        void OnDurationChange(base::TimeDelta duration) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class RendererStubDispatch {
    public:
        static bool Accept(Renderer* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(Renderer* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<Renderer>>
    class RendererStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        RendererStub() { }
        ~RendererStub() override { }

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
            return RendererStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return RendererStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class RendererClientStubDispatch {
    public:
        static bool Accept(RendererClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(RendererClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<RendererClient>>
    class RendererClientStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        RendererClientStub() { }
        ~RendererClientStub() override { }

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
            return RendererClientStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return RendererClientStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class RendererRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class RendererClientRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class RendererResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

} // namespace mojom
} // namespace media

namespace mojo {

} // namespace mojo

#endif // MEDIA_MOJO_INTERFACES_RENDERER_MOJOM_H_