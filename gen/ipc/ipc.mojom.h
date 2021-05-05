// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef IPC_IPC_MOJOM_H_
#define IPC_IPC_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "ipc/ipc.mojom-shared.h"
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

namespace IPC {
namespace mojom {
    constexpr int32_t kRoutingIdNone = -2;
    class GenericInterface;
    using GenericInterfacePtr = mojo::InterfacePtr<GenericInterface>;
    using GenericInterfacePtrInfo = mojo::InterfacePtrInfo<GenericInterface>;
    using ThreadSafeGenericInterfacePtr = mojo::ThreadSafeInterfacePtr<GenericInterface>;
    using GenericInterfaceRequest = mojo::InterfaceRequest<GenericInterface>;
    using GenericInterfaceAssociatedPtr = mojo::AssociatedInterfacePtr<GenericInterface>;
    using ThreadSafeGenericInterfaceAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<GenericInterface>;
    using GenericInterfaceAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<GenericInterface>;
    using GenericInterfaceAssociatedRequest = mojo::AssociatedInterfaceRequest<GenericInterface>;

    class Channel;
    using ChannelPtr = mojo::InterfacePtr<Channel>;
    using ChannelPtrInfo = mojo::InterfacePtrInfo<Channel>;
    using ThreadSafeChannelPtr = mojo::ThreadSafeInterfacePtr<Channel>;
    using ChannelRequest = mojo::InterfaceRequest<Channel>;
    using ChannelAssociatedPtr = mojo::AssociatedInterfacePtr<Channel>;
    using ThreadSafeChannelAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<Channel>;
    using ChannelAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<Channel>;
    using ChannelAssociatedRequest = mojo::AssociatedInterfaceRequest<Channel>;

    class ChannelBootstrap;
    using ChannelBootstrapPtr = mojo::InterfacePtr<ChannelBootstrap>;
    using ChannelBootstrapPtrInfo = mojo::InterfacePtrInfo<ChannelBootstrap>;
    using ThreadSafeChannelBootstrapPtr = mojo::ThreadSafeInterfacePtr<ChannelBootstrap>;
    using ChannelBootstrapRequest = mojo::InterfaceRequest<ChannelBootstrap>;
    using ChannelBootstrapAssociatedPtr = mojo::AssociatedInterfacePtr<ChannelBootstrap>;
    using ThreadSafeChannelBootstrapAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<ChannelBootstrap>;
    using ChannelBootstrapAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<ChannelBootstrap>;
    using ChannelBootstrapAssociatedRequest = mojo::AssociatedInterfaceRequest<ChannelBootstrap>;

    class SerializedHandle;
    using SerializedHandlePtr = mojo::StructPtr<SerializedHandle>;

    class GenericInterfaceProxy;

    template <typename ImplRefTraits>
    class GenericInterfaceStub;

    class GenericInterfaceRequestValidator;

    class GenericInterface
        : public GenericInterfaceInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = GenericInterfaceProxy;

        template <typename ImplRefTraits>
        using Stub_ = GenericInterfaceStub<ImplRefTraits>;

        using RequestValidator_ = GenericInterfaceRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
        };
        virtual ~GenericInterface() { }
    };

    class ChannelProxy;

    template <typename ImplRefTraits>
    class ChannelStub;

    class ChannelRequestValidator;

    class Channel
        : public ChannelInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = true;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = ChannelProxy;

        template <typename ImplRefTraits>
        using Stub_ = ChannelStub<ImplRefTraits>;

        using RequestValidator_ = ChannelRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kSetPeerPidMinVersion = 0,
            kReceiveMinVersion = 0,
            kGetAssociatedInterfaceMinVersion = 0,
        };
        virtual ~Channel() { }

        virtual void SetPeerPid(int32_t pid) = 0;

        virtual void Receive(const std::vector<uint8_t>& data, base::Optional<std::vector<SerializedHandlePtr>> handles) = 0;

        virtual void GetAssociatedInterface(const std::string& name, GenericInterfaceAssociatedRequest request) = 0;
    };

    class ChannelBootstrapProxy;

    template <typename ImplRefTraits>
    class ChannelBootstrapStub;

    class ChannelBootstrapRequestValidator;

    class ChannelBootstrap
        : public ChannelBootstrapInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = ChannelBootstrapProxy;

        template <typename ImplRefTraits>
        using Stub_ = ChannelBootstrapStub<ImplRefTraits>;

        using RequestValidator_ = ChannelBootstrapRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
        };
        virtual ~ChannelBootstrap() { }
    };

    class GenericInterfaceProxy
        : public GenericInterface {
    public:
        explicit GenericInterfaceProxy(mojo::MessageReceiverWithResponder* receiver);

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class ChannelProxy
        : public Channel {
    public:
        explicit ChannelProxy(mojo::MessageReceiverWithResponder* receiver);
        void SetPeerPid(int32_t pid) override;
        void Receive(const std::vector<uint8_t>& data, base::Optional<std::vector<SerializedHandlePtr>> handles) override;
        void GetAssociatedInterface(const std::string& name, GenericInterfaceAssociatedRequest request) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class ChannelBootstrapProxy
        : public ChannelBootstrap {
    public:
        explicit ChannelBootstrapProxy(mojo::MessageReceiverWithResponder* receiver);

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class GenericInterfaceStubDispatch {
    public:
        static bool Accept(GenericInterface* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(GenericInterface* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<GenericInterface>>
    class GenericInterfaceStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        GenericInterfaceStub() { }
        ~GenericInterfaceStub() override { }

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
            return GenericInterfaceStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return GenericInterfaceStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class ChannelStubDispatch {
    public:
        static bool Accept(Channel* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(Channel* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<Channel>>
    class ChannelStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        ChannelStub() { }
        ~ChannelStub() override { }

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
            return ChannelStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return ChannelStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class ChannelBootstrapStubDispatch {
    public:
        static bool Accept(ChannelBootstrap* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(ChannelBootstrap* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<ChannelBootstrap>>
    class ChannelBootstrapStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        ChannelBootstrapStub() { }
        ~ChannelBootstrapStub() override { }

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
            return ChannelBootstrapStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return ChannelBootstrapStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class GenericInterfaceRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class ChannelRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class ChannelBootstrapRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

    class SerializedHandle {
    public:
        using DataView = SerializedHandleDataView;
        using Data_ = internal::SerializedHandle_Data;
        using Type = SerializedHandle_Type;

        static SerializedHandlePtr New();

        template <typename U>
        static SerializedHandlePtr From(const U& u)
        {
            return mojo::TypeConverter<SerializedHandlePtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, SerializedHandle>::Convert(*this);
        }

        SerializedHandle();
        ~SerializedHandle();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = SerializedHandlePtr>
        SerializedHandlePtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, SerializedHandle>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                SerializedHandle::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                SerializedHandle::DataView, std::vector<uint8_t>>(
                input, output);
        }

        mojo::ScopedHandle the_handle;
        SerializedHandle::Type type;

    private:
        DISALLOW_COPY_AND_ASSIGN(SerializedHandle);
    };

    template <typename StructPtrType>
    SerializedHandlePtr SerializedHandle::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->the_handle = mojo::internal::Clone(the_handle);
        rv->type = mojo::internal::Clone(type);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, SerializedHandle>::value>::type*>
    bool SerializedHandle::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->the_handle, other.the_handle))
            return false;
        if (!mojo::internal::Equals(this->type, other.type))
            return false;
        return true;
    }

} // namespace mojom
} // namespace IPC

namespace mojo {

template <>
struct StructTraits<::IPC::mojom::SerializedHandle::DataView,
    ::IPC::mojom::SerializedHandlePtr> {
    static bool IsNull(const ::IPC::mojom::SerializedHandlePtr& input) { return !input; }
    static void SetToNull(::IPC::mojom::SerializedHandlePtr* output) { output->reset(); }

    static decltype(::IPC::mojom::SerializedHandle::the_handle)& the_handle(
        ::IPC::mojom::SerializedHandlePtr& input)
    {
        return input->the_handle;
    }

    static decltype(::IPC::mojom::SerializedHandle::type) type(
        const ::IPC::mojom::SerializedHandlePtr& input)
    {
        return input->type;
    }

    static bool Read(::IPC::mojom::SerializedHandle::DataView input, ::IPC::mojom::SerializedHandlePtr* output);
};

} // namespace mojo

#endif // IPC_IPC_MOJOM_H_