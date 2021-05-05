// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_DISCARDABLE_MEMORY_PUBLIC_INTERFACES_DISCARDABLE_SHARED_MEMORY_MANAGER_MOJOM_H_
#define COMPONENTS_DISCARDABLE_MEMORY_PUBLIC_INTERFACES_DISCARDABLE_SHARED_MEMORY_MANAGER_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "components/discardable_memory/public/interfaces/discardable_shared_memory_manager.mojom-shared.h"
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

namespace discardable_memory {
namespace mojom {
    class DiscardableSharedMemoryManager;
    using DiscardableSharedMemoryManagerPtr = mojo::InterfacePtr<DiscardableSharedMemoryManager>;
    using DiscardableSharedMemoryManagerPtrInfo = mojo::InterfacePtrInfo<DiscardableSharedMemoryManager>;
    using ThreadSafeDiscardableSharedMemoryManagerPtr = mojo::ThreadSafeInterfacePtr<DiscardableSharedMemoryManager>;
    using DiscardableSharedMemoryManagerRequest = mojo::InterfaceRequest<DiscardableSharedMemoryManager>;
    using DiscardableSharedMemoryManagerAssociatedPtr = mojo::AssociatedInterfacePtr<DiscardableSharedMemoryManager>;
    using ThreadSafeDiscardableSharedMemoryManagerAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<DiscardableSharedMemoryManager>;
    using DiscardableSharedMemoryManagerAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<DiscardableSharedMemoryManager>;
    using DiscardableSharedMemoryManagerAssociatedRequest = mojo::AssociatedInterfaceRequest<DiscardableSharedMemoryManager>;

    class DiscardableSharedMemoryManagerProxy;

    template <typename ImplRefTraits>
    class DiscardableSharedMemoryManagerStub;

    class DiscardableSharedMemoryManagerRequestValidator;
    class DiscardableSharedMemoryManagerResponseValidator;

    class DiscardableSharedMemoryManager
        : public DiscardableSharedMemoryManagerInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = DiscardableSharedMemoryManagerProxy;

        template <typename ImplRefTraits>
        using Stub_ = DiscardableSharedMemoryManagerStub<ImplRefTraits>;

        using RequestValidator_ = DiscardableSharedMemoryManagerRequestValidator;
        using ResponseValidator_ = DiscardableSharedMemoryManagerResponseValidator;
        enum MethodMinVersions : uint32_t {
            kAllocateLockedDiscardableSharedMemoryMinVersion = 0,
            kDeletedDiscardableSharedMemoryMinVersion = 0,
        };
        virtual ~DiscardableSharedMemoryManager() { }

        using AllocateLockedDiscardableSharedMemoryCallback = base::Callback<void(mojo::ScopedSharedBufferHandle)>;
        virtual void AllocateLockedDiscardableSharedMemory(uint32_t size, int32_t id, const AllocateLockedDiscardableSharedMemoryCallback& callback) = 0;

        virtual void DeletedDiscardableSharedMemory(int32_t id) = 0;
    };

    class DiscardableSharedMemoryManagerProxy
        : public DiscardableSharedMemoryManager {
    public:
        explicit DiscardableSharedMemoryManagerProxy(mojo::MessageReceiverWithResponder* receiver);
        void AllocateLockedDiscardableSharedMemory(uint32_t size, int32_t id, const AllocateLockedDiscardableSharedMemoryCallback& callback) override;
        void DeletedDiscardableSharedMemory(int32_t id) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class DiscardableSharedMemoryManagerStubDispatch {
    public:
        static bool Accept(DiscardableSharedMemoryManager* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(DiscardableSharedMemoryManager* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<DiscardableSharedMemoryManager>>
    class DiscardableSharedMemoryManagerStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        DiscardableSharedMemoryManagerStub() { }
        ~DiscardableSharedMemoryManagerStub() override { }

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
            return DiscardableSharedMemoryManagerStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return DiscardableSharedMemoryManagerStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class DiscardableSharedMemoryManagerRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class DiscardableSharedMemoryManagerResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

} // namespace mojom
} // namespace discardable_memory

namespace mojo {

} // namespace mojo

#endif // COMPONENTS_DISCARDABLE_MEMORY_PUBLIC_INTERFACES_DISCARDABLE_SHARED_MEMORY_MANAGER_MOJOM_H_