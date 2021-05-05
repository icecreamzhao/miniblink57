// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_OFFSCREENCANVAS_OFFSCREEN_CANVAS_SURFACE_MOJOM_BLINK_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_OFFSCREENCANVAS_OFFSCREEN_CANVAS_SURFACE_MOJOM_BLINK_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "cc/ipc/compositor_frame.mojom-blink.h"
#include "cc/ipc/frame_sink_id.mojom-blink.h"
#include "cc/ipc/mojo_compositor_frame_sink.mojom-blink.h"
#include "cc/ipc/surface_id.mojom-blink.h"
#include "cc/ipc/surface_info.mojom-blink.h"
#include "cc/ipc/surface_sequence.mojom-blink.h"
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
#include "third_party/WebKit/public/platform/modules/offscreencanvas/offscreen_canvas_surface.mojom-shared.h"

#include "base/files/file.h"
#include "cc/output/begin_frame_args.h"
#include "cc/output/compositor_frame.h"
#include "cc/resources/returned_resource.h"
#include "cc/surfaces/frame_sink_id.h"
#include "cc/surfaces/local_frame_id.h"
#include "cc/surfaces/surface_id.h"
#include "cc/surfaces/surface_info.h"
#include "cc/surfaces/surface_sequence.h"
#include "mojo/public/cpp/bindings/lib/wtf_hash_util.h"
#include "third_party/WebKit/Source/wtf/HashFunctions.h"
#include "third_party/WebKit/Source/wtf/Optional.h"
#include "third_party/WebKit/Source/wtf/text/WTFString.h"
#include "third_party/WebKit/public/platform/WebCommon.h"
#include "third_party/WebKit/public/platform/WebSize.h"

namespace blink {
namespace mojom {
    namespace blink {
        class OffscreenCanvasSurface;
        using OffscreenCanvasSurfacePtr = mojo::InterfacePtr<OffscreenCanvasSurface>;
        using OffscreenCanvasSurfacePtrInfo = mojo::InterfacePtrInfo<OffscreenCanvasSurface>;
        using ThreadSafeOffscreenCanvasSurfacePtr = mojo::ThreadSafeInterfacePtr<OffscreenCanvasSurface>;
        using OffscreenCanvasSurfaceRequest = mojo::InterfaceRequest<OffscreenCanvasSurface>;
        using OffscreenCanvasSurfaceAssociatedPtr = mojo::AssociatedInterfacePtr<OffscreenCanvasSurface>;
        using ThreadSafeOffscreenCanvasSurfaceAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<OffscreenCanvasSurface>;
        using OffscreenCanvasSurfaceAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<OffscreenCanvasSurface>;
        using OffscreenCanvasSurfaceAssociatedRequest = mojo::AssociatedInterfaceRequest<OffscreenCanvasSurface>;

        class OffscreenCanvasSurfaceClient;
        using OffscreenCanvasSurfaceClientPtr = mojo::InterfacePtr<OffscreenCanvasSurfaceClient>;
        using OffscreenCanvasSurfaceClientPtrInfo = mojo::InterfacePtrInfo<OffscreenCanvasSurfaceClient>;
        using ThreadSafeOffscreenCanvasSurfaceClientPtr = mojo::ThreadSafeInterfacePtr<OffscreenCanvasSurfaceClient>;
        using OffscreenCanvasSurfaceClientRequest = mojo::InterfaceRequest<OffscreenCanvasSurfaceClient>;
        using OffscreenCanvasSurfaceClientAssociatedPtr = mojo::AssociatedInterfacePtr<OffscreenCanvasSurfaceClient>;
        using ThreadSafeOffscreenCanvasSurfaceClientAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<OffscreenCanvasSurfaceClient>;
        using OffscreenCanvasSurfaceClientAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<OffscreenCanvasSurfaceClient>;
        using OffscreenCanvasSurfaceClientAssociatedRequest = mojo::AssociatedInterfaceRequest<OffscreenCanvasSurfaceClient>;

        class OffscreenCanvasSurfaceFactory;
        using OffscreenCanvasSurfaceFactoryPtr = mojo::InterfacePtr<OffscreenCanvasSurfaceFactory>;
        using OffscreenCanvasSurfaceFactoryPtrInfo = mojo::InterfacePtrInfo<OffscreenCanvasSurfaceFactory>;
        using ThreadSafeOffscreenCanvasSurfaceFactoryPtr = mojo::ThreadSafeInterfacePtr<OffscreenCanvasSurfaceFactory>;
        using OffscreenCanvasSurfaceFactoryRequest = mojo::InterfaceRequest<OffscreenCanvasSurfaceFactory>;
        using OffscreenCanvasSurfaceFactoryAssociatedPtr = mojo::AssociatedInterfacePtr<OffscreenCanvasSurfaceFactory>;
        using ThreadSafeOffscreenCanvasSurfaceFactoryAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<OffscreenCanvasSurfaceFactory>;
        using OffscreenCanvasSurfaceFactoryAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<OffscreenCanvasSurfaceFactory>;
        using OffscreenCanvasSurfaceFactoryAssociatedRequest = mojo::AssociatedInterfaceRequest<OffscreenCanvasSurfaceFactory>;

        class OffscreenCanvasCompositorFrameSinkProvider;
        using OffscreenCanvasCompositorFrameSinkProviderPtr = mojo::InterfacePtr<OffscreenCanvasCompositorFrameSinkProvider>;
        using OffscreenCanvasCompositorFrameSinkProviderPtrInfo = mojo::InterfacePtrInfo<OffscreenCanvasCompositorFrameSinkProvider>;
        using ThreadSafeOffscreenCanvasCompositorFrameSinkProviderPtr = mojo::ThreadSafeInterfacePtr<OffscreenCanvasCompositorFrameSinkProvider>;
        using OffscreenCanvasCompositorFrameSinkProviderRequest = mojo::InterfaceRequest<OffscreenCanvasCompositorFrameSinkProvider>;
        using OffscreenCanvasCompositorFrameSinkProviderAssociatedPtr = mojo::AssociatedInterfacePtr<OffscreenCanvasCompositorFrameSinkProvider>;
        using ThreadSafeOffscreenCanvasCompositorFrameSinkProviderAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<OffscreenCanvasCompositorFrameSinkProvider>;
        using OffscreenCanvasCompositorFrameSinkProviderAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<OffscreenCanvasCompositorFrameSinkProvider>;
        using OffscreenCanvasCompositorFrameSinkProviderAssociatedRequest = mojo::AssociatedInterfaceRequest<OffscreenCanvasCompositorFrameSinkProvider>;

        class OffscreenCanvasSurfaceProxy;

        template <typename ImplRefTraits>
        class OffscreenCanvasSurfaceStub;

        class OffscreenCanvasSurfaceRequestValidator;

        class BLINK_PLATFORM_EXPORT OffscreenCanvasSurface
            : public OffscreenCanvasSurfaceInterfaceBase {
        public:
            static const char Name_[];
            static constexpr uint32_t Version_ = 0;
            static constexpr bool PassesAssociatedKinds_ = false;
            static constexpr bool HasSyncMethods_ = false;

            using Proxy_ = OffscreenCanvasSurfaceProxy;

            template <typename ImplRefTraits>
            using Stub_ = OffscreenCanvasSurfaceStub<ImplRefTraits>;

            using RequestValidator_ = OffscreenCanvasSurfaceRequestValidator;
            using ResponseValidator_ = mojo::PassThroughFilter;
            enum MethodMinVersions : uint32_t {
                kRequireMinVersion = 0,
                kSatisfyMinVersion = 0,
            };
            virtual ~OffscreenCanvasSurface() { }

            virtual void Require(const cc::SurfaceId& surface_id, const cc::SurfaceSequence& sequence) = 0;

            virtual void Satisfy(const cc::SurfaceSequence& sequence) = 0;
        };

        class OffscreenCanvasSurfaceClientProxy;

        template <typename ImplRefTraits>
        class OffscreenCanvasSurfaceClientStub;

        class OffscreenCanvasSurfaceClientRequestValidator;

        class BLINK_PLATFORM_EXPORT OffscreenCanvasSurfaceClient
            : public OffscreenCanvasSurfaceClientInterfaceBase {
        public:
            static const char Name_[];
            static constexpr uint32_t Version_ = 0;
            static constexpr bool PassesAssociatedKinds_ = false;
            static constexpr bool HasSyncMethods_ = false;

            using Proxy_ = OffscreenCanvasSurfaceClientProxy;

            template <typename ImplRefTraits>
            using Stub_ = OffscreenCanvasSurfaceClientStub<ImplRefTraits>;

            using RequestValidator_ = OffscreenCanvasSurfaceClientRequestValidator;
            using ResponseValidator_ = mojo::PassThroughFilter;
            enum MethodMinVersions : uint32_t {
                kOnSurfaceCreatedMinVersion = 0,
            };
            virtual ~OffscreenCanvasSurfaceClient() { }

            virtual void OnSurfaceCreated(const cc::SurfaceInfo& surface_info) = 0;
        };

        class OffscreenCanvasSurfaceFactoryProxy;

        template <typename ImplRefTraits>
        class OffscreenCanvasSurfaceFactoryStub;

        class OffscreenCanvasSurfaceFactoryRequestValidator;

        class BLINK_PLATFORM_EXPORT OffscreenCanvasSurfaceFactory
            : public OffscreenCanvasSurfaceFactoryInterfaceBase {
        public:
            static const char Name_[];
            static constexpr uint32_t Version_ = 0;
            static constexpr bool PassesAssociatedKinds_ = false;
            static constexpr bool HasSyncMethods_ = false;

            using Proxy_ = OffscreenCanvasSurfaceFactoryProxy;

            template <typename ImplRefTraits>
            using Stub_ = OffscreenCanvasSurfaceFactoryStub<ImplRefTraits>;

            using RequestValidator_ = OffscreenCanvasSurfaceFactoryRequestValidator;
            using ResponseValidator_ = mojo::PassThroughFilter;
            enum MethodMinVersions : uint32_t {
                kCreateOffscreenCanvasSurfaceMinVersion = 0,
            };
            virtual ~OffscreenCanvasSurfaceFactory() { }

            virtual void CreateOffscreenCanvasSurface(const cc::FrameSinkId& frame_sink_id, OffscreenCanvasSurfaceClientPtr client, OffscreenCanvasSurfaceRequest service) = 0;
        };

        class OffscreenCanvasCompositorFrameSinkProviderProxy;

        template <typename ImplRefTraits>
        class OffscreenCanvasCompositorFrameSinkProviderStub;

        class OffscreenCanvasCompositorFrameSinkProviderRequestValidator;

        class BLINK_PLATFORM_EXPORT OffscreenCanvasCompositorFrameSinkProvider
            : public OffscreenCanvasCompositorFrameSinkProviderInterfaceBase {
        public:
            static const char Name_[];
            static constexpr uint32_t Version_ = 0;
            static constexpr bool PassesAssociatedKinds_ = false;
            static constexpr bool HasSyncMethods_ = false;

            using Proxy_ = OffscreenCanvasCompositorFrameSinkProviderProxy;

            template <typename ImplRefTraits>
            using Stub_ = OffscreenCanvasCompositorFrameSinkProviderStub<ImplRefTraits>;

            using RequestValidator_ = OffscreenCanvasCompositorFrameSinkProviderRequestValidator;
            using ResponseValidator_ = mojo::PassThroughFilter;
            enum MethodMinVersions : uint32_t {
                kCreateCompositorFrameSinkMinVersion = 0,
            };
            virtual ~OffscreenCanvasCompositorFrameSinkProvider() { }

            virtual void CreateCompositorFrameSink(const cc::FrameSinkId& frame_sink_id, ::cc::mojom::blink::MojoCompositorFrameSinkClientPtr client, ::cc::mojom::blink::MojoCompositorFrameSinkRequest sink) = 0;
        };

        class BLINK_PLATFORM_EXPORT OffscreenCanvasSurfaceProxy
            : public OffscreenCanvasSurface {
        public:
            explicit OffscreenCanvasSurfaceProxy(mojo::MessageReceiverWithResponder* receiver);
            void Require(const cc::SurfaceId& surface_id, const cc::SurfaceSequence& sequence) override;
            void Satisfy(const cc::SurfaceSequence& sequence) override;

            void set_group_controller(
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
            {
                group_controller_ = std::move(group_controller);
            }

        private:
            mojo::MessageReceiverWithResponder* receiver_;
            scoped_refptr<mojo::AssociatedGroupController> group_controller_;
        };

        class BLINK_PLATFORM_EXPORT OffscreenCanvasSurfaceClientProxy
            : public OffscreenCanvasSurfaceClient {
        public:
            explicit OffscreenCanvasSurfaceClientProxy(mojo::MessageReceiverWithResponder* receiver);
            void OnSurfaceCreated(const cc::SurfaceInfo& surface_info) override;

            void set_group_controller(
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
            {
                group_controller_ = std::move(group_controller);
            }

        private:
            mojo::MessageReceiverWithResponder* receiver_;
            scoped_refptr<mojo::AssociatedGroupController> group_controller_;
        };

        class BLINK_PLATFORM_EXPORT OffscreenCanvasSurfaceFactoryProxy
            : public OffscreenCanvasSurfaceFactory {
        public:
            explicit OffscreenCanvasSurfaceFactoryProxy(mojo::MessageReceiverWithResponder* receiver);
            void CreateOffscreenCanvasSurface(const cc::FrameSinkId& frame_sink_id, OffscreenCanvasSurfaceClientPtr client, OffscreenCanvasSurfaceRequest service) override;

            void set_group_controller(
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
            {
                group_controller_ = std::move(group_controller);
            }

        private:
            mojo::MessageReceiverWithResponder* receiver_;
            scoped_refptr<mojo::AssociatedGroupController> group_controller_;
        };

        class BLINK_PLATFORM_EXPORT OffscreenCanvasCompositorFrameSinkProviderProxy
            : public OffscreenCanvasCompositorFrameSinkProvider {
        public:
            explicit OffscreenCanvasCompositorFrameSinkProviderProxy(mojo::MessageReceiverWithResponder* receiver);
            void CreateCompositorFrameSink(const cc::FrameSinkId& frame_sink_id, ::cc::mojom::blink::MojoCompositorFrameSinkClientPtr client, ::cc::mojom::blink::MojoCompositorFrameSinkRequest sink) override;

            void set_group_controller(
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
            {
                group_controller_ = std::move(group_controller);
            }

        private:
            mojo::MessageReceiverWithResponder* receiver_;
            scoped_refptr<mojo::AssociatedGroupController> group_controller_;
        };
        class BLINK_PLATFORM_EXPORT OffscreenCanvasSurfaceStubDispatch {
        public:
            static bool Accept(OffscreenCanvasSurface* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message);
            static bool AcceptWithResponder(OffscreenCanvasSurface* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder);
        };

        template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<OffscreenCanvasSurface>>
        class OffscreenCanvasSurfaceStub
            : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
        public:
            using ImplPointerType = typename ImplRefTraits::PointerType;

            OffscreenCanvasSurfaceStub() { }
            ~OffscreenCanvasSurfaceStub() override { }

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
                return OffscreenCanvasSurfaceStubDispatch::Accept(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
            }

            bool AcceptWithResponder(
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder) override
            {
                if (ImplRefTraits::IsNull(sink_))
                    return false;
                return OffscreenCanvasSurfaceStubDispatch::AcceptWithResponder(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                    responder);
            }

        private:
            ImplPointerType sink_;
            mojo::internal::SerializationContext serialization_context_;
        };
        class BLINK_PLATFORM_EXPORT OffscreenCanvasSurfaceClientStubDispatch {
        public:
            static bool Accept(OffscreenCanvasSurfaceClient* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message);
            static bool AcceptWithResponder(OffscreenCanvasSurfaceClient* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder);
        };

        template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<OffscreenCanvasSurfaceClient>>
        class OffscreenCanvasSurfaceClientStub
            : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
        public:
            using ImplPointerType = typename ImplRefTraits::PointerType;

            OffscreenCanvasSurfaceClientStub() { }
            ~OffscreenCanvasSurfaceClientStub() override { }

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
                return OffscreenCanvasSurfaceClientStubDispatch::Accept(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
            }

            bool AcceptWithResponder(
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder) override
            {
                if (ImplRefTraits::IsNull(sink_))
                    return false;
                return OffscreenCanvasSurfaceClientStubDispatch::AcceptWithResponder(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                    responder);
            }

        private:
            ImplPointerType sink_;
            mojo::internal::SerializationContext serialization_context_;
        };
        class BLINK_PLATFORM_EXPORT OffscreenCanvasSurfaceFactoryStubDispatch {
        public:
            static bool Accept(OffscreenCanvasSurfaceFactory* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message);
            static bool AcceptWithResponder(OffscreenCanvasSurfaceFactory* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder);
        };

        template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<OffscreenCanvasSurfaceFactory>>
        class OffscreenCanvasSurfaceFactoryStub
            : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
        public:
            using ImplPointerType = typename ImplRefTraits::PointerType;

            OffscreenCanvasSurfaceFactoryStub() { }
            ~OffscreenCanvasSurfaceFactoryStub() override { }

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
                return OffscreenCanvasSurfaceFactoryStubDispatch::Accept(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
            }

            bool AcceptWithResponder(
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder) override
            {
                if (ImplRefTraits::IsNull(sink_))
                    return false;
                return OffscreenCanvasSurfaceFactoryStubDispatch::AcceptWithResponder(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                    responder);
            }

        private:
            ImplPointerType sink_;
            mojo::internal::SerializationContext serialization_context_;
        };
        class BLINK_PLATFORM_EXPORT OffscreenCanvasCompositorFrameSinkProviderStubDispatch {
        public:
            static bool Accept(OffscreenCanvasCompositorFrameSinkProvider* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message);
            static bool AcceptWithResponder(OffscreenCanvasCompositorFrameSinkProvider* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder);
        };

        template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<OffscreenCanvasCompositorFrameSinkProvider>>
        class OffscreenCanvasCompositorFrameSinkProviderStub
            : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
        public:
            using ImplPointerType = typename ImplRefTraits::PointerType;

            OffscreenCanvasCompositorFrameSinkProviderStub() { }
            ~OffscreenCanvasCompositorFrameSinkProviderStub() override { }

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
                return OffscreenCanvasCompositorFrameSinkProviderStubDispatch::Accept(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
            }

            bool AcceptWithResponder(
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder) override
            {
                if (ImplRefTraits::IsNull(sink_))
                    return false;
                return OffscreenCanvasCompositorFrameSinkProviderStubDispatch::AcceptWithResponder(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                    responder);
            }

        private:
            ImplPointerType sink_;
            mojo::internal::SerializationContext serialization_context_;
        };
        class BLINK_PLATFORM_EXPORT OffscreenCanvasSurfaceRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };
        class BLINK_PLATFORM_EXPORT OffscreenCanvasSurfaceClientRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };
        class BLINK_PLATFORM_EXPORT OffscreenCanvasSurfaceFactoryRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };
        class BLINK_PLATFORM_EXPORT OffscreenCanvasCompositorFrameSinkProviderRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };

    } // namespace blink
} // namespace mojom
} // namespace blink

namespace mojo {

} // namespace mojo

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_OFFSCREENCANVAS_OFFSCREEN_CANVAS_SURFACE_MOJOM_BLINK_H_