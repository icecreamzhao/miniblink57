// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_BACKGROUND_SYNC_BACKGROUND_SYNC_MOJOM_BLINK_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_BACKGROUND_SYNC_BACKGROUND_SYNC_MOJOM_BLINK_H_

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
#include "third_party/WebKit/public/platform/modules/background_sync/background_sync.mojom-shared.h"

#include "base/files/file.h"
#include "mojo/public/cpp/bindings/lib/wtf_hash_util.h"
#include "third_party/WebKit/Source/platform/weborigin/KURL.h"
#include "third_party/WebKit/Source/platform/weborigin/SecurityOrigin.h"
#include "third_party/WebKit/Source/wtf/HashFunctions.h"
#include "third_party/WebKit/Source/wtf/Optional.h"
#include "third_party/WebKit/Source/wtf/text/WTFString.h"
#include "third_party/WebKit/public/platform/WebCommon.h"
#include "third_party/WebKit/public/platform/WebReferrerPolicy.h"
#include "third_party/WebKit/public/platform/WebSize.h"
#include "third_party/WebKit/public/web/WebConsoleMessage.h"
#include "third_party/WebKit/public/web/WebWindowFeatures.h"

namespace blink {
namespace mojom {
    namespace blink {
        using BackgroundSyncNetworkState = BackgroundSyncNetworkState; // Alias for definition in the parent namespace.
        using BackgroundSyncError = BackgroundSyncError; // Alias for definition in the parent namespace.
        using BackgroundSyncState = BackgroundSyncState; // Alias for definition in the parent namespace.
        using BackgroundSyncEventLastChance = BackgroundSyncEventLastChance; // Alias for definition in the parent namespace.
        class BackgroundSyncService;
        using BackgroundSyncServicePtr = mojo::InterfacePtr<BackgroundSyncService>;
        using BackgroundSyncServicePtrInfo = mojo::InterfacePtrInfo<BackgroundSyncService>;
        using ThreadSafeBackgroundSyncServicePtr = mojo::ThreadSafeInterfacePtr<BackgroundSyncService>;
        using BackgroundSyncServiceRequest = mojo::InterfaceRequest<BackgroundSyncService>;
        using BackgroundSyncServiceAssociatedPtr = mojo::AssociatedInterfacePtr<BackgroundSyncService>;
        using ThreadSafeBackgroundSyncServiceAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<BackgroundSyncService>;
        using BackgroundSyncServiceAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<BackgroundSyncService>;
        using BackgroundSyncServiceAssociatedRequest = mojo::AssociatedInterfaceRequest<BackgroundSyncService>;

        class SyncRegistration;
        using SyncRegistrationPtr = mojo::InlinedStructPtr<SyncRegistration>;

        class BackgroundSyncServiceProxy;

        template <typename ImplRefTraits>
        class BackgroundSyncServiceStub;

        class BackgroundSyncServiceRequestValidator;
        class BackgroundSyncServiceResponseValidator;

        class BLINK_PLATFORM_EXPORT BackgroundSyncService
            : public BackgroundSyncServiceInterfaceBase {
        public:
            static const char Name_[];
            static constexpr uint32_t Version_ = 0;
            static constexpr bool PassesAssociatedKinds_ = false;
            static constexpr bool HasSyncMethods_ = false;

            using Proxy_ = BackgroundSyncServiceProxy;

            template <typename ImplRefTraits>
            using Stub_ = BackgroundSyncServiceStub<ImplRefTraits>;

            using RequestValidator_ = BackgroundSyncServiceRequestValidator;
            using ResponseValidator_ = BackgroundSyncServiceResponseValidator;
            enum MethodMinVersions : uint32_t {
                kRegisterMinVersion = 0,
                kGetRegistrationsMinVersion = 0,
            };
            virtual ~BackgroundSyncService() { }

            using RegisterCallback = base::Callback<void(BackgroundSyncError, SyncRegistrationPtr)>;
            virtual void Register(SyncRegistrationPtr options, int64_t service_worker_registration_id, const RegisterCallback& callback) = 0;

            using GetRegistrationsCallback = base::Callback<void(BackgroundSyncError, WTF::Vector<SyncRegistrationPtr>)>;
            virtual void GetRegistrations(int64_t service_worker_registration_id, const GetRegistrationsCallback& callback) = 0;
        };

        class BLINK_PLATFORM_EXPORT BackgroundSyncServiceProxy
            : public BackgroundSyncService {
        public:
            explicit BackgroundSyncServiceProxy(mojo::MessageReceiverWithResponder* receiver);
            void Register(SyncRegistrationPtr options, int64_t service_worker_registration_id, const RegisterCallback& callback) override;
            void GetRegistrations(int64_t service_worker_registration_id, const GetRegistrationsCallback& callback) override;

            void set_group_controller(
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
            {
                group_controller_ = std::move(group_controller);
            }

        private:
            mojo::MessageReceiverWithResponder* receiver_;
            scoped_refptr<mojo::AssociatedGroupController> group_controller_;
        };
        class BLINK_PLATFORM_EXPORT BackgroundSyncServiceStubDispatch {
        public:
            static bool Accept(BackgroundSyncService* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message);
            static bool AcceptWithResponder(BackgroundSyncService* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder);
        };

        template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<BackgroundSyncService>>
        class BackgroundSyncServiceStub
            : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
        public:
            using ImplPointerType = typename ImplRefTraits::PointerType;

            BackgroundSyncServiceStub() { }
            ~BackgroundSyncServiceStub() override { }

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
                return BackgroundSyncServiceStubDispatch::Accept(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
            }

            bool AcceptWithResponder(
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder) override
            {
                if (ImplRefTraits::IsNull(sink_))
                    return false;
                return BackgroundSyncServiceStubDispatch::AcceptWithResponder(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                    responder);
            }

        private:
            ImplPointerType sink_;
            mojo::internal::SerializationContext serialization_context_;
        };
        class BLINK_PLATFORM_EXPORT BackgroundSyncServiceRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };
        class BLINK_PLATFORM_EXPORT BackgroundSyncServiceResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };

        class BLINK_PLATFORM_EXPORT SyncRegistration {
        public:
            using DataView = SyncRegistrationDataView;
            using Data_ = internal::SyncRegistration_Data;

            static SyncRegistrationPtr New();

            template <typename U>
            static SyncRegistrationPtr From(const U& u)
            {
                return mojo::TypeConverter<SyncRegistrationPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, SyncRegistration>::Convert(*this);
            }

            SyncRegistration();
            ~SyncRegistration();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = SyncRegistrationPtr>
            SyncRegistrationPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, SyncRegistration>::value>::type* = nullptr>
            bool Equals(const T& other) const;
            size_t Hash(size_t seed) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    SyncRegistration::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    SyncRegistration::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            int64_t id;
            WTF::String tag;
            BackgroundSyncNetworkState network_state;
        };

        template <typename StructPtrType>
        SyncRegistrationPtr SyncRegistration::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->id = mojo::internal::Clone(id);
            rv->tag = mojo::internal::Clone(tag);
            rv->network_state = mojo::internal::Clone(network_state);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, SyncRegistration>::value>::type*>
        bool SyncRegistration::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->id, other.id))
                return false;
            if (!mojo::internal::Equals(this->tag, other.tag))
                return false;
            if (!mojo::internal::Equals(this->network_state, other.network_state))
                return false;
            return true;
        }

    } // namespace blink
} // namespace mojom
} // namespace blink

namespace mojo {

template <>
struct BLINK_PLATFORM_EXPORT StructTraits<::blink::mojom::blink::SyncRegistration::DataView,
    ::blink::mojom::blink::SyncRegistrationPtr> {
    static bool IsNull(const ::blink::mojom::blink::SyncRegistrationPtr& input) { return !input; }
    static void SetToNull(::blink::mojom::blink::SyncRegistrationPtr* output) { output->reset(); }

    static decltype(::blink::mojom::blink::SyncRegistration::id) id(
        const ::blink::mojom::blink::SyncRegistrationPtr& input)
    {
        return input->id;
    }

    static const decltype(::blink::mojom::blink::SyncRegistration::tag)& tag(
        const ::blink::mojom::blink::SyncRegistrationPtr& input)
    {
        return input->tag;
    }

    static decltype(::blink::mojom::blink::SyncRegistration::network_state) network_state(
        const ::blink::mojom::blink::SyncRegistrationPtr& input)
    {
        return input->network_state;
    }

    static bool Read(::blink::mojom::blink::SyncRegistration::DataView input, ::blink::mojom::blink::SyncRegistrationPtr* output);
};

} // namespace mojo

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_BACKGROUND_SYNC_BACKGROUND_SYNC_MOJOM_BLINK_H_