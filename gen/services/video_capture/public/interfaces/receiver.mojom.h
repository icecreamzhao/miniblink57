// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_RECEIVER_MOJOM_H_
#define SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_RECEIVER_MOJOM_H_

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
#include "media/capture/video/video_capture_device_descriptor.h"
#include "media/capture/video_capture_types.h"
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
#include "services/video_capture/public/cpp/capture_settings.h"
#include "services/video_capture/public/interfaces/receiver.mojom-shared.h"
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

namespace video_capture {
namespace mojom {
    class Receiver;
    using ReceiverPtr = mojo::InterfacePtr<Receiver>;
    using ReceiverPtrInfo = mojo::InterfacePtrInfo<Receiver>;
    using ThreadSafeReceiverPtr = mojo::ThreadSafeInterfacePtr<Receiver>;
    using ReceiverRequest = mojo::InterfaceRequest<Receiver>;
    using ReceiverAssociatedPtr = mojo::AssociatedInterfacePtr<Receiver>;
    using ThreadSafeReceiverAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<Receiver>;
    using ReceiverAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<Receiver>;
    using ReceiverAssociatedRequest = mojo::AssociatedInterfaceRequest<Receiver>;

    class ReceiverProxy;

    template <typename ImplRefTraits>
    class ReceiverStub;

    class ReceiverRequestValidator;

    class Receiver
        : public ReceiverInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = ReceiverProxy;

        template <typename ImplRefTraits>
        using Stub_ = ReceiverStub<ImplRefTraits>;

        using RequestValidator_ = ReceiverRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kOnIncomingCapturedVideoFrameMinVersion = 0,
            kOnErrorMinVersion = 0,
            kOnLogMinVersion = 0,
            kOnBufferDestroyedMinVersion = 0,
        };
        virtual ~Receiver() { }

        virtual void OnIncomingCapturedVideoFrame(::media::mojom::VideoFramePtr frame) = 0;

        virtual void OnError() = 0;

        virtual void OnLog(const std::string& message) = 0;

        virtual void OnBufferDestroyed(int32_t buffer_id_to_drop) = 0;
    };

    class ReceiverProxy
        : public Receiver {
    public:
        explicit ReceiverProxy(mojo::MessageReceiverWithResponder* receiver);
        void OnIncomingCapturedVideoFrame(::media::mojom::VideoFramePtr frame) override;
        void OnError() override;
        void OnLog(const std::string& message) override;
        void OnBufferDestroyed(int32_t buffer_id_to_drop) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class ReceiverStubDispatch {
    public:
        static bool Accept(Receiver* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(Receiver* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<Receiver>>
    class ReceiverStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        ReceiverStub() { }
        ~ReceiverStub() override { }

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
            return ReceiverStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return ReceiverStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class ReceiverRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

} // namespace mojom
} // namespace video_capture

namespace mojo {

} // namespace mojo

#endif // SERVICES_VIDEO_CAPTURE_PUBLIC_INTERFACES_RECEIVER_MOJOM_H_