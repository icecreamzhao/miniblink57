// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef MEDIA_MOJO_INTERFACES_REMOTING_MOJOM_H_
#define MEDIA_MOJO_INTERFACES_REMOTING_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "media/mojo/interfaces/remoting.mojom-shared.h"
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
#include <string>
#include <vector>

namespace media {
namespace mojom {
    class RemoterFactory;
    using RemoterFactoryPtr = mojo::InterfacePtr<RemoterFactory>;
    using RemoterFactoryPtrInfo = mojo::InterfacePtrInfo<RemoterFactory>;
    using ThreadSafeRemoterFactoryPtr = mojo::ThreadSafeInterfacePtr<RemoterFactory>;
    using RemoterFactoryRequest = mojo::InterfaceRequest<RemoterFactory>;
    using RemoterFactoryAssociatedPtr = mojo::AssociatedInterfacePtr<RemoterFactory>;
    using ThreadSafeRemoterFactoryAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<RemoterFactory>;
    using RemoterFactoryAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<RemoterFactory>;
    using RemoterFactoryAssociatedRequest = mojo::AssociatedInterfaceRequest<RemoterFactory>;

    class RemotingDataStreamSender;
    using RemotingDataStreamSenderPtr = mojo::InterfacePtr<RemotingDataStreamSender>;
    using RemotingDataStreamSenderPtrInfo = mojo::InterfacePtrInfo<RemotingDataStreamSender>;
    using ThreadSafeRemotingDataStreamSenderPtr = mojo::ThreadSafeInterfacePtr<RemotingDataStreamSender>;
    using RemotingDataStreamSenderRequest = mojo::InterfaceRequest<RemotingDataStreamSender>;
    using RemotingDataStreamSenderAssociatedPtr = mojo::AssociatedInterfacePtr<RemotingDataStreamSender>;
    using ThreadSafeRemotingDataStreamSenderAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<RemotingDataStreamSender>;
    using RemotingDataStreamSenderAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<RemotingDataStreamSender>;
    using RemotingDataStreamSenderAssociatedRequest = mojo::AssociatedInterfaceRequest<RemotingDataStreamSender>;

    class Remoter;
    using RemoterPtr = mojo::InterfacePtr<Remoter>;
    using RemoterPtrInfo = mojo::InterfacePtrInfo<Remoter>;
    using ThreadSafeRemoterPtr = mojo::ThreadSafeInterfacePtr<Remoter>;
    using RemoterRequest = mojo::InterfaceRequest<Remoter>;
    using RemoterAssociatedPtr = mojo::AssociatedInterfacePtr<Remoter>;
    using ThreadSafeRemoterAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<Remoter>;
    using RemoterAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<Remoter>;
    using RemoterAssociatedRequest = mojo::AssociatedInterfaceRequest<Remoter>;

    class RemotingSource;
    using RemotingSourcePtr = mojo::InterfacePtr<RemotingSource>;
    using RemotingSourcePtrInfo = mojo::InterfacePtrInfo<RemotingSource>;
    using ThreadSafeRemotingSourcePtr = mojo::ThreadSafeInterfacePtr<RemotingSource>;
    using RemotingSourceRequest = mojo::InterfaceRequest<RemotingSource>;
    using RemotingSourceAssociatedPtr = mojo::AssociatedInterfacePtr<RemotingSource>;
    using ThreadSafeRemotingSourceAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<RemotingSource>;
    using RemotingSourceAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<RemotingSource>;
    using RemotingSourceAssociatedRequest = mojo::AssociatedInterfaceRequest<RemotingSource>;

    class RemoterFactoryProxy;

    template <typename ImplRefTraits>
    class RemoterFactoryStub;

    class RemoterFactoryRequestValidator;

    class RemoterFactory
        : public RemoterFactoryInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = RemoterFactoryProxy;

        template <typename ImplRefTraits>
        using Stub_ = RemoterFactoryStub<ImplRefTraits>;

        using RequestValidator_ = RemoterFactoryRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kCreateMinVersion = 0,
        };
        virtual ~RemoterFactory() { }

        virtual void Create(RemotingSourcePtr source, RemoterRequest remoter) = 0;
    };

    class RemotingDataStreamSenderProxy;

    template <typename ImplRefTraits>
    class RemotingDataStreamSenderStub;

    class RemotingDataStreamSenderRequestValidator;

    class RemotingDataStreamSender
        : public RemotingDataStreamSenderInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = RemotingDataStreamSenderProxy;

        template <typename ImplRefTraits>
        using Stub_ = RemotingDataStreamSenderStub<ImplRefTraits>;

        using RequestValidator_ = RemotingDataStreamSenderRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kConsumeDataChunkMinVersion = 0,
            kSendFrameMinVersion = 0,
            kCancelInFlightDataMinVersion = 0,
        };
        virtual ~RemotingDataStreamSender() { }

        virtual void ConsumeDataChunk(uint32_t offset, uint32_t size, uint32_t total_payload_size) = 0;

        virtual void SendFrame() = 0;

        virtual void CancelInFlightData() = 0;
    };

    class RemoterProxy;

    template <typename ImplRefTraits>
    class RemoterStub;

    class RemoterRequestValidator;

    class Remoter
        : public RemoterInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = RemoterProxy;

        template <typename ImplRefTraits>
        using Stub_ = RemoterStub<ImplRefTraits>;

        using RequestValidator_ = RemoterRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kStartMinVersion = 0,
            kStartDataStreamsMinVersion = 0,
            kStopMinVersion = 0,
            kSendMessageToSinkMinVersion = 0,
        };
        virtual ~Remoter() { }

        virtual void Start() = 0;

        virtual void StartDataStreams(mojo::ScopedDataPipeConsumerHandle audio_pipe, mojo::ScopedDataPipeConsumerHandle video_pipe, RemotingDataStreamSenderRequest audio_sender, RemotingDataStreamSenderRequest video_sender) = 0;

        virtual void Stop(RemotingStopReason reason) = 0;

        virtual void SendMessageToSink(const std::vector<uint8_t>& message) = 0;
    };

    class RemotingSourceProxy;

    template <typename ImplRefTraits>
    class RemotingSourceStub;

    class RemotingSourceRequestValidator;

    class RemotingSource
        : public RemotingSourceInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = RemotingSourceProxy;

        template <typename ImplRefTraits>
        using Stub_ = RemotingSourceStub<ImplRefTraits>;

        using RequestValidator_ = RemotingSourceRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kOnSinkAvailableMinVersion = 0,
            kOnSinkGoneMinVersion = 0,
            kOnStartedMinVersion = 0,
            kOnStartFailedMinVersion = 0,
            kOnMessageFromSinkMinVersion = 0,
            kOnStoppedMinVersion = 0,
        };
        virtual ~RemotingSource() { }

        virtual void OnSinkAvailable(RemotingSinkCapabilities capabilities) = 0;

        virtual void OnSinkGone() = 0;

        virtual void OnStarted() = 0;

        virtual void OnStartFailed(RemotingStartFailReason reason) = 0;

        virtual void OnMessageFromSink(const std::vector<uint8_t>& message) = 0;

        virtual void OnStopped(RemotingStopReason reason) = 0;
    };

    class RemoterFactoryProxy
        : public RemoterFactory {
    public:
        explicit RemoterFactoryProxy(mojo::MessageReceiverWithResponder* receiver);
        void Create(RemotingSourcePtr source, RemoterRequest remoter) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class RemotingDataStreamSenderProxy
        : public RemotingDataStreamSender {
    public:
        explicit RemotingDataStreamSenderProxy(mojo::MessageReceiverWithResponder* receiver);
        void ConsumeDataChunk(uint32_t offset, uint32_t size, uint32_t total_payload_size) override;
        void SendFrame() override;
        void CancelInFlightData() override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class RemoterProxy
        : public Remoter {
    public:
        explicit RemoterProxy(mojo::MessageReceiverWithResponder* receiver);
        void Start() override;
        void StartDataStreams(mojo::ScopedDataPipeConsumerHandle audio_pipe, mojo::ScopedDataPipeConsumerHandle video_pipe, RemotingDataStreamSenderRequest audio_sender, RemotingDataStreamSenderRequest video_sender) override;
        void Stop(RemotingStopReason reason) override;
        void SendMessageToSink(const std::vector<uint8_t>& message) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class RemotingSourceProxy
        : public RemotingSource {
    public:
        explicit RemotingSourceProxy(mojo::MessageReceiverWithResponder* receiver);
        void OnSinkAvailable(RemotingSinkCapabilities capabilities) override;
        void OnSinkGone() override;
        void OnStarted() override;
        void OnStartFailed(RemotingStartFailReason reason) override;
        void OnMessageFromSink(const std::vector<uint8_t>& message) override;
        void OnStopped(RemotingStopReason reason) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class RemoterFactoryStubDispatch {
    public:
        static bool Accept(RemoterFactory* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(RemoterFactory* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<RemoterFactory>>
    class RemoterFactoryStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        RemoterFactoryStub() { }
        ~RemoterFactoryStub() override { }

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
            return RemoterFactoryStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return RemoterFactoryStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class RemotingDataStreamSenderStubDispatch {
    public:
        static bool Accept(RemotingDataStreamSender* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(RemotingDataStreamSender* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<RemotingDataStreamSender>>
    class RemotingDataStreamSenderStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        RemotingDataStreamSenderStub() { }
        ~RemotingDataStreamSenderStub() override { }

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
            return RemotingDataStreamSenderStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return RemotingDataStreamSenderStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class RemoterStubDispatch {
    public:
        static bool Accept(Remoter* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(Remoter* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<Remoter>>
    class RemoterStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        RemoterStub() { }
        ~RemoterStub() override { }

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
            return RemoterStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return RemoterStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class RemotingSourceStubDispatch {
    public:
        static bool Accept(RemotingSource* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(RemotingSource* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<RemotingSource>>
    class RemotingSourceStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        RemotingSourceStub() { }
        ~RemotingSourceStub() override { }

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
            return RemotingSourceStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return RemotingSourceStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class RemoterFactoryRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class RemotingDataStreamSenderRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class RemoterRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class RemotingSourceRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

} // namespace mojom
} // namespace media

namespace mojo {

} // namespace mojo

#endif // MEDIA_MOJO_INTERFACES_REMOTING_MOJOM_H_