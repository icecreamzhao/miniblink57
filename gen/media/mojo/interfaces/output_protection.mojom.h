// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_MOJO_INTERFACES_OUTPUT_PROTECTION_MOJOM_H_
#define MEDIA_MOJO_INTERFACES_OUTPUT_PROTECTION_MOJOM_H_

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
#include "media/mojo/interfaces/output_protection.mojom-shared.h"
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
    class OutputProtection;
    using OutputProtectionPtr = mojo::InterfacePtr<OutputProtection>;
    using OutputProtectionPtrInfo = mojo::InterfacePtrInfo<OutputProtection>;
    using ThreadSafeOutputProtectionPtr = mojo::ThreadSafeInterfacePtr<OutputProtection>;
    using OutputProtectionRequest = mojo::InterfaceRequest<OutputProtection>;
    using OutputProtectionAssociatedPtr = mojo::AssociatedInterfacePtr<OutputProtection>;
    using ThreadSafeOutputProtectionAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<OutputProtection>;
    using OutputProtectionAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<OutputProtection>;
    using OutputProtectionAssociatedRequest = mojo::AssociatedInterfaceRequest<OutputProtection>;

    class OutputProtectionProxy;

    template <typename ImplRefTraits>
    class OutputProtectionStub;

    class OutputProtectionRequestValidator;
    class OutputProtectionResponseValidator;

    class OutputProtection
        : public OutputProtectionInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = OutputProtectionProxy;

        template <typename ImplRefTraits>
        using Stub_ = OutputProtectionStub<ImplRefTraits>;

        using RequestValidator_ = OutputProtectionRequestValidator;
        using ResponseValidator_ = OutputProtectionResponseValidator;
        enum MethodMinVersions : uint32_t {
            kQueryStatusMinVersion = 0,
            kEnableProtectionMinVersion = 0,
        };
        using ProtectionType = OutputProtection_ProtectionType;
        using LinkType = OutputProtection_LinkType;
        virtual ~OutputProtection() { }

        using QueryStatusCallback = base::Callback<void(bool, uint32_t, uint32_t)>;
        virtual void QueryStatus(const QueryStatusCallback& callback) = 0;

        using EnableProtectionCallback = base::Callback<void(bool)>;
        virtual void EnableProtection(uint32_t desired_protection_mask, const EnableProtectionCallback& callback) = 0;
    };

    class OutputProtectionProxy
        : public OutputProtection {
    public:
        explicit OutputProtectionProxy(mojo::MessageReceiverWithResponder* receiver);
        void QueryStatus(const QueryStatusCallback& callback) override;
        void EnableProtection(uint32_t desired_protection_mask, const EnableProtectionCallback& callback) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class OutputProtectionStubDispatch {
    public:
        static bool Accept(OutputProtection* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(OutputProtection* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<OutputProtection>>
    class OutputProtectionStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        OutputProtectionStub() { }
        ~OutputProtectionStub() override { }

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
            return OutputProtectionStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return OutputProtectionStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class OutputProtectionRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class OutputProtectionResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

} // namespace mojom
} // namespace media

namespace mojo {

} // namespace mojo

#endif // MEDIA_MOJO_INTERFACES_OUTPUT_PROTECTION_MOJOM_H_