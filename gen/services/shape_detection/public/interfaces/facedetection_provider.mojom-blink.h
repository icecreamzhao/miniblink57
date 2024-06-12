// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_SHAPE_DETECTION_PUBLIC_INTERFACES_FACEDETECTION_PROVIDER_MOJOM_BLINK_H_
#define SERVICES_SHAPE_DETECTION_PUBLIC_INTERFACES_FACEDETECTION_PROVIDER_MOJOM_BLINK_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
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
#include "services/shape_detection/public/interfaces/facedetection.mojom-blink.h"
#include "services/shape_detection/public/interfaces/facedetection_provider.mojom-shared.h"

#include "mojo/public/cpp/bindings/lib/wtf_hash_util.h"
#include "third_party/WebKit/Source/wtf/HashFunctions.h"
#include "third_party/WebKit/Source/wtf/Optional.h"
#include "third_party/WebKit/Source/wtf/text/WTFString.h"
#include "third_party/WebKit/public/platform/WebSize.h"

namespace shape_detection {
namespace mojom {
    namespace blink {
        class FaceDetectionProvider;
        using FaceDetectionProviderPtr = mojo::InterfacePtr<FaceDetectionProvider>;
        using FaceDetectionProviderPtrInfo = mojo::InterfacePtrInfo<FaceDetectionProvider>;
        using ThreadSafeFaceDetectionProviderPtr = mojo::ThreadSafeInterfacePtr<FaceDetectionProvider>;
        using FaceDetectionProviderRequest = mojo::InterfaceRequest<FaceDetectionProvider>;
        using FaceDetectionProviderAssociatedPtr = mojo::AssociatedInterfacePtr<FaceDetectionProvider>;
        using ThreadSafeFaceDetectionProviderAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<FaceDetectionProvider>;
        using FaceDetectionProviderAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<FaceDetectionProvider>;
        using FaceDetectionProviderAssociatedRequest = mojo::AssociatedInterfaceRequest<FaceDetectionProvider>;

        class FaceDetectionProviderProxy;

        template <typename ImplRefTraits>
        class FaceDetectionProviderStub;

        class FaceDetectionProviderRequestValidator;

        class FaceDetectionProvider
            : public FaceDetectionProviderInterfaceBase {
        public:
            static const char Name_[];
            static constexpr uint32_t Version_ = 0;
            static constexpr bool PassesAssociatedKinds_ = false;
            static constexpr bool HasSyncMethods_ = false;

            using Proxy_ = FaceDetectionProviderProxy;

            template <typename ImplRefTraits>
            using Stub_ = FaceDetectionProviderStub<ImplRefTraits>;

            using RequestValidator_ = FaceDetectionProviderRequestValidator;
            using ResponseValidator_ = mojo::PassThroughFilter;
            enum MethodMinVersions : uint32_t {
                kCreateFaceDetectionMinVersion = 0,
            };
            virtual ~FaceDetectionProvider() { }

            virtual void CreateFaceDetection(::shape_detection::mojom::blink::FaceDetectionRequest request, ::shape_detection::mojom::blink::FaceDetectorOptionsPtr options) = 0;
        };

        class FaceDetectionProviderProxy
            : public FaceDetectionProvider {
        public:
            explicit FaceDetectionProviderProxy(mojo::MessageReceiverWithResponder* receiver);
            void CreateFaceDetection(::shape_detection::mojom::blink::FaceDetectionRequest request, ::shape_detection::mojom::blink::FaceDetectorOptionsPtr options) override;

            void set_group_controller(
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
            {
                group_controller_ = std::move(group_controller);
            }

        private:
            mojo::MessageReceiverWithResponder* receiver_;
            scoped_refptr<mojo::AssociatedGroupController> group_controller_;
        };
        class FaceDetectionProviderStubDispatch {
        public:
            static bool Accept(FaceDetectionProvider* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message);
            static bool AcceptWithResponder(FaceDetectionProvider* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder);
        };

        template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<FaceDetectionProvider>>
        class FaceDetectionProviderStub
            : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
        public:
            using ImplPointerType = typename ImplRefTraits::PointerType;

            FaceDetectionProviderStub() { }
            ~FaceDetectionProviderStub() override { }

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
                return FaceDetectionProviderStubDispatch::Accept(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
            }

            bool AcceptWithResponder(
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder) override
            {
                if (ImplRefTraits::IsNull(sink_))
                    return false;
                return FaceDetectionProviderStubDispatch::AcceptWithResponder(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                    responder);
            }

        private:
            ImplPointerType sink_;
            mojo::internal::SerializationContext serialization_context_;
        };
        class FaceDetectionProviderRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };

    } // namespace blink
} // namespace mojom
} // namespace shape_detection

namespace mojo {

} // namespace mojo

#endif // SERVICES_SHAPE_DETECTION_PUBLIC_INTERFACES_FACEDETECTION_PROVIDER_MOJOM_BLINK_H_