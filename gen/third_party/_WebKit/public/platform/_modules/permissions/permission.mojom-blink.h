// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_PERMISSIONS_PERMISSION_MOJOM_BLINK_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_PERMISSIONS_PERMISSION_MOJOM_BLINK_H_

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
#include "third_party/WebKit/public/platform/modules/permissions/permission.mojom-shared.h"
#include "third_party/WebKit/public/platform/modules/permissions/permission_status.mojom-blink.h"
#include "url/mojo/origin.mojom-blink.h"

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
        using PermissionName = PermissionName; // Alias for definition in the parent namespace.
        class PermissionObserver;
        using PermissionObserverPtr = mojo::InterfacePtr<PermissionObserver>;
        using PermissionObserverPtrInfo = mojo::InterfacePtrInfo<PermissionObserver>;
        using ThreadSafePermissionObserverPtr = mojo::ThreadSafeInterfacePtr<PermissionObserver>;
        using PermissionObserverRequest = mojo::InterfaceRequest<PermissionObserver>;
        using PermissionObserverAssociatedPtr = mojo::AssociatedInterfacePtr<PermissionObserver>;
        using ThreadSafePermissionObserverAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<PermissionObserver>;
        using PermissionObserverAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<PermissionObserver>;
        using PermissionObserverAssociatedRequest = mojo::AssociatedInterfaceRequest<PermissionObserver>;

        class PermissionService;
        using PermissionServicePtr = mojo::InterfacePtr<PermissionService>;
        using PermissionServicePtrInfo = mojo::InterfacePtrInfo<PermissionService>;
        using ThreadSafePermissionServicePtr = mojo::ThreadSafeInterfacePtr<PermissionService>;
        using PermissionServiceRequest = mojo::InterfaceRequest<PermissionService>;
        using PermissionServiceAssociatedPtr = mojo::AssociatedInterfacePtr<PermissionService>;
        using ThreadSafePermissionServiceAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<PermissionService>;
        using PermissionServiceAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<PermissionService>;
        using PermissionServiceAssociatedRequest = mojo::AssociatedInterfaceRequest<PermissionService>;

        class MidiPermissionDescriptor;
        using MidiPermissionDescriptorPtr = mojo::InlinedStructPtr<MidiPermissionDescriptor>;

        class PermissionDescriptor;
        using PermissionDescriptorPtr = mojo::StructPtr<PermissionDescriptor>;

        class PermissionDescriptorExtension;

        typedef mojo::StructPtr<PermissionDescriptorExtension> PermissionDescriptorExtensionPtr;

        class PermissionObserverProxy;

        template <typename ImplRefTraits>
        class PermissionObserverStub;

        class PermissionObserverRequestValidator;

        class BLINK_PLATFORM_EXPORT PermissionObserver
            : public PermissionObserverInterfaceBase {
        public:
            static const char Name_[];
            static constexpr uint32_t Version_ = 0;
            static constexpr bool PassesAssociatedKinds_ = false;
            static constexpr bool HasSyncMethods_ = false;

            using Proxy_ = PermissionObserverProxy;

            template <typename ImplRefTraits>
            using Stub_ = PermissionObserverStub<ImplRefTraits>;

            using RequestValidator_ = PermissionObserverRequestValidator;
            using ResponseValidator_ = mojo::PassThroughFilter;
            enum MethodMinVersions : uint32_t {
                kOnPermissionStatusChangeMinVersion = 0,
            };
            virtual ~PermissionObserver() { }

            virtual void OnPermissionStatusChange(::blink::mojom::blink::PermissionStatus status) = 0;
        };

        class PermissionServiceProxy;

        template <typename ImplRefTraits>
        class PermissionServiceStub;

        class PermissionServiceRequestValidator;
        class PermissionServiceResponseValidator;

        class BLINK_PLATFORM_EXPORT PermissionService
            : public PermissionServiceInterfaceBase {
        public:
            static const char Name_[];
            static constexpr uint32_t Version_ = 0;
            static constexpr bool PassesAssociatedKinds_ = false;
            static constexpr bool HasSyncMethods_ = false;

            using Proxy_ = PermissionServiceProxy;

            template <typename ImplRefTraits>
            using Stub_ = PermissionServiceStub<ImplRefTraits>;

            using RequestValidator_ = PermissionServiceRequestValidator;
            using ResponseValidator_ = PermissionServiceResponseValidator;
            enum MethodMinVersions : uint32_t {
                kHasPermissionMinVersion = 0,
                kRequestPermissionMinVersion = 0,
                kRequestPermissionsMinVersion = 0,
                kRevokePermissionMinVersion = 0,
                kAddPermissionObserverMinVersion = 0,
            };
            virtual ~PermissionService() { }

            using HasPermissionCallback = base::Callback<void(::blink::mojom::blink::PermissionStatus)>;
            virtual void HasPermission(PermissionDescriptorPtr permission, const RefPtr<::blink::SecurityOrigin>& origin, const HasPermissionCallback& callback) = 0;

            using RequestPermissionCallback = base::Callback<void(::blink::mojom::blink::PermissionStatus)>;
            virtual void RequestPermission(PermissionDescriptorPtr permission, const RefPtr<::blink::SecurityOrigin>& origin, bool user_gesture, const RequestPermissionCallback& callback) = 0;

            using RequestPermissionsCallback = base::Callback<void(const WTF::Vector<::blink::mojom::blink::PermissionStatus>&)>;
            virtual void RequestPermissions(WTF::Vector<PermissionDescriptorPtr> permission, const RefPtr<::blink::SecurityOrigin>& origin, bool user_gesture, const RequestPermissionsCallback& callback) = 0;

            using RevokePermissionCallback = base::Callback<void(::blink::mojom::blink::PermissionStatus)>;
            virtual void RevokePermission(PermissionDescriptorPtr permission, const RefPtr<::blink::SecurityOrigin>& origin, const RevokePermissionCallback& callback) = 0;

            virtual void AddPermissionObserver(PermissionDescriptorPtr permission, const RefPtr<::blink::SecurityOrigin>& origin, ::blink::mojom::blink::PermissionStatus last_known_status, PermissionObserverPtr observer) = 0;
        };

        class BLINK_PLATFORM_EXPORT PermissionObserverProxy
            : public PermissionObserver {
        public:
            explicit PermissionObserverProxy(mojo::MessageReceiverWithResponder* receiver);
            void OnPermissionStatusChange(::blink::mojom::blink::PermissionStatus status) override;

            void set_group_controller(
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
            {
                group_controller_ = std::move(group_controller);
            }

        private:
            mojo::MessageReceiverWithResponder* receiver_;
            scoped_refptr<mojo::AssociatedGroupController> group_controller_;
        };

        class BLINK_PLATFORM_EXPORT PermissionServiceProxy
            : public PermissionService {
        public:
            explicit PermissionServiceProxy(mojo::MessageReceiverWithResponder* receiver);
            void HasPermission(PermissionDescriptorPtr permission, const RefPtr<::blink::SecurityOrigin>& origin, const HasPermissionCallback& callback) override;
            void RequestPermission(PermissionDescriptorPtr permission, const RefPtr<::blink::SecurityOrigin>& origin, bool user_gesture, const RequestPermissionCallback& callback) override;
            void RequestPermissions(WTF::Vector<PermissionDescriptorPtr> permission, const RefPtr<::blink::SecurityOrigin>& origin, bool user_gesture, const RequestPermissionsCallback& callback) override;
            void RevokePermission(PermissionDescriptorPtr permission, const RefPtr<::blink::SecurityOrigin>& origin, const RevokePermissionCallback& callback) override;
            void AddPermissionObserver(PermissionDescriptorPtr permission, const RefPtr<::blink::SecurityOrigin>& origin, ::blink::mojom::blink::PermissionStatus last_known_status, PermissionObserverPtr observer) override;

            void set_group_controller(
                scoped_refptr<mojo::AssociatedGroupController> group_controller)
            {
                group_controller_ = std::move(group_controller);
            }

        private:
            mojo::MessageReceiverWithResponder* receiver_;
            scoped_refptr<mojo::AssociatedGroupController> group_controller_;
        };
        class BLINK_PLATFORM_EXPORT PermissionObserverStubDispatch {
        public:
            static bool Accept(PermissionObserver* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message);
            static bool AcceptWithResponder(PermissionObserver* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder);
        };

        template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<PermissionObserver>>
        class PermissionObserverStub
            : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
        public:
            using ImplPointerType = typename ImplRefTraits::PointerType;

            PermissionObserverStub() { }
            ~PermissionObserverStub() override { }

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
                return PermissionObserverStubDispatch::Accept(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
            }

            bool AcceptWithResponder(
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder) override
            {
                if (ImplRefTraits::IsNull(sink_))
                    return false;
                return PermissionObserverStubDispatch::AcceptWithResponder(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                    responder);
            }

        private:
            ImplPointerType sink_;
            mojo::internal::SerializationContext serialization_context_;
        };
        class BLINK_PLATFORM_EXPORT PermissionServiceStubDispatch {
        public:
            static bool Accept(PermissionService* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message);
            static bool AcceptWithResponder(PermissionService* impl,
                mojo::internal::SerializationContext* context,
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder);
        };

        template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<PermissionService>>
        class PermissionServiceStub
            : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
        public:
            using ImplPointerType = typename ImplRefTraits::PointerType;

            PermissionServiceStub() { }
            ~PermissionServiceStub() override { }

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
                return PermissionServiceStubDispatch::Accept(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
            }

            bool AcceptWithResponder(
                mojo::Message* message,
                mojo::MessageReceiverWithStatus* responder) override
            {
                if (ImplRefTraits::IsNull(sink_))
                    return false;
                return PermissionServiceStubDispatch::AcceptWithResponder(
                    ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                    responder);
            }

        private:
            ImplPointerType sink_;
            mojo::internal::SerializationContext serialization_context_;
        };
        class BLINK_PLATFORM_EXPORT PermissionObserverRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };
        class BLINK_PLATFORM_EXPORT PermissionServiceRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };
        class BLINK_PLATFORM_EXPORT PermissionServiceResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
        public:
            bool Accept(mojo::Message* message) override;
        };

        class BLINK_PLATFORM_EXPORT MidiPermissionDescriptor {
        public:
            using DataView = MidiPermissionDescriptorDataView;
            using Data_ = internal::MidiPermissionDescriptor_Data;

            static MidiPermissionDescriptorPtr New();

            template <typename U>
            static MidiPermissionDescriptorPtr From(const U& u)
            {
                return mojo::TypeConverter<MidiPermissionDescriptorPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, MidiPermissionDescriptor>::Convert(*this);
            }

            MidiPermissionDescriptor();
            ~MidiPermissionDescriptor();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = MidiPermissionDescriptorPtr>
            MidiPermissionDescriptorPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, MidiPermissionDescriptor>::value>::type* = nullptr>
            bool Equals(const T& other) const;
            size_t Hash(size_t seed) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    MidiPermissionDescriptor::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    MidiPermissionDescriptor::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            bool sysex;
        };

        class BLINK_PLATFORM_EXPORT PermissionDescriptorExtension {
        public:
            using DataView = PermissionDescriptorExtensionDataView;
            using Data_ = internal::PermissionDescriptorExtension_Data;
            using Tag = Data_::PermissionDescriptorExtension_Tag;

            static PermissionDescriptorExtensionPtr New();

            template <typename U>
            static PermissionDescriptorExtensionPtr From(const U& u)
            {
                return mojo::TypeConverter<PermissionDescriptorExtensionPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, PermissionDescriptorExtension>::Convert(*this);
            }

            PermissionDescriptorExtension();
            ~PermissionDescriptorExtension();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename UnionPtrType = PermissionDescriptorExtensionPtr>
            PermissionDescriptorExtensionPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, PermissionDescriptorExtension>::value>::type* = nullptr>
            bool Equals(const T& other) const;
            size_t Hash(size_t seed) const;

            Tag which() const
            {
                return tag_;
            }

            bool is_midi() const { return tag_ == Tag::MIDI; }

            MidiPermissionDescriptorPtr& get_midi() const
            {
                DCHECK(tag_ == Tag::MIDI);
                return *(data_.midi);
            }

            void set_midi(MidiPermissionDescriptorPtr midi);

        private:
            friend class mojo::internal::UnionAccessor<PermissionDescriptorExtension>;
            union Union_ {
                Union_() { }
                ~Union_() { }
                MidiPermissionDescriptorPtr* midi;
            };
            void SwitchActive(Tag new_active);
            void SetActive(Tag new_active);
            void DestroyActive();
            Tag tag_;
            Union_ data_;
        };

        class BLINK_PLATFORM_EXPORT PermissionDescriptor {
        public:
            using DataView = PermissionDescriptorDataView;
            using Data_ = internal::PermissionDescriptor_Data;

            static PermissionDescriptorPtr New();

            template <typename U>
            static PermissionDescriptorPtr From(const U& u)
            {
                return mojo::TypeConverter<PermissionDescriptorPtr, U>::Convert(u);
            }

            template <typename U>
            U To() const
            {
                return mojo::TypeConverter<U, PermissionDescriptor>::Convert(*this);
            }

            PermissionDescriptor();
            ~PermissionDescriptor();

            // Clone() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Clone() or copy
            // constructor/assignment are available for members.
            template <typename StructPtrType = PermissionDescriptorPtr>
            PermissionDescriptorPtr Clone() const;

            // Equals() is a template so it is only instantiated if it is used. Thus, the
            // bindings generator does not need to know whether Equals() or == operator
            // are available for members.
            template <typename T,
                typename std::enable_if<std::is_same<
                    T, PermissionDescriptor>::value>::type* = nullptr>
            bool Equals(const T& other) const;

            template <typename UserType>
            static WTF::Vector<uint8_t> Serialize(UserType* input)
            {
                return mojo::internal::StructSerializeImpl<
                    PermissionDescriptor::DataView, WTF::Vector<uint8_t>>(input);
            }

            template <typename UserType>
            static bool Deserialize(const WTF::Vector<uint8_t>& input,
                UserType* output)
            {
                return mojo::internal::StructDeserializeImpl<
                    PermissionDescriptor::DataView, WTF::Vector<uint8_t>>(
                    input, output);
            }

            PermissionName name;
            PermissionDescriptorExtensionPtr extension;

        private:
            DISALLOW_COPY_AND_ASSIGN(PermissionDescriptor);
        };

        template <typename UnionPtrType>
        PermissionDescriptorExtensionPtr PermissionDescriptorExtension::Clone() const
        {
            // Use UnionPtrType to prevent the compiler from trying to compile this
            // without being asked.
            UnionPtrType rv(New());
            switch (tag_) {
            case Tag::MIDI:
                rv->set_midi(mojo::internal::Clone(*data_.midi));
                break;
            };
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, PermissionDescriptorExtension>::value>::type*>
        bool PermissionDescriptorExtension::Equals(const T& other) const
        {
            if (tag_ != other.which())
                return false;

            switch (tag_) {
            case Tag::MIDI:
                return mojo::internal::Equals(*(data_.midi), *(other.data_.midi));
            };

            return false;
        }
        template <typename StructPtrType>
        MidiPermissionDescriptorPtr MidiPermissionDescriptor::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->sysex = mojo::internal::Clone(sysex);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, MidiPermissionDescriptor>::value>::type*>
        bool MidiPermissionDescriptor::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->sysex, other.sysex))
                return false;
            return true;
        }
        template <typename StructPtrType>
        PermissionDescriptorPtr PermissionDescriptor::Clone() const
        {
            // Use StructPtrType to prevent the compiler from trying to compile this
            // without being asked.
            StructPtrType rv(New());
            rv->name = mojo::internal::Clone(name);
            rv->extension = mojo::internal::Clone(extension);
            return rv;
        }

        template <typename T,
            typename std::enable_if<std::is_same<
                T, PermissionDescriptor>::value>::type*>
        bool PermissionDescriptor::Equals(const T& other) const
        {
            if (!mojo::internal::Equals(this->name, other.name))
                return false;
            if (!mojo::internal::Equals(this->extension, other.extension))
                return false;
            return true;
        }

    } // namespace blink
} // namespace mojom
} // namespace blink

namespace mojo {

template <>
struct BLINK_PLATFORM_EXPORT StructTraits<::blink::mojom::blink::MidiPermissionDescriptor::DataView,
    ::blink::mojom::blink::MidiPermissionDescriptorPtr> {
    static bool IsNull(const ::blink::mojom::blink::MidiPermissionDescriptorPtr& input) { return !input; }
    static void SetToNull(::blink::mojom::blink::MidiPermissionDescriptorPtr* output) { output->reset(); }

    static decltype(::blink::mojom::blink::MidiPermissionDescriptor::sysex) sysex(
        const ::blink::mojom::blink::MidiPermissionDescriptorPtr& input)
    {
        return input->sysex;
    }

    static bool Read(::blink::mojom::blink::MidiPermissionDescriptor::DataView input, ::blink::mojom::blink::MidiPermissionDescriptorPtr* output);
};

template <>
struct BLINK_PLATFORM_EXPORT StructTraits<::blink::mojom::blink::PermissionDescriptor::DataView,
    ::blink::mojom::blink::PermissionDescriptorPtr> {
    static bool IsNull(const ::blink::mojom::blink::PermissionDescriptorPtr& input) { return !input; }
    static void SetToNull(::blink::mojom::blink::PermissionDescriptorPtr* output) { output->reset(); }

    static decltype(::blink::mojom::blink::PermissionDescriptor::name) name(
        const ::blink::mojom::blink::PermissionDescriptorPtr& input)
    {
        return input->name;
    }

    static const decltype(::blink::mojom::blink::PermissionDescriptor::extension)& extension(
        const ::blink::mojom::blink::PermissionDescriptorPtr& input)
    {
        return input->extension;
    }

    static bool Read(::blink::mojom::blink::PermissionDescriptor::DataView input, ::blink::mojom::blink::PermissionDescriptorPtr* output);
};

template <>
struct BLINK_PLATFORM_EXPORT UnionTraits<::blink::mojom::blink::PermissionDescriptorExtension::DataView,
    ::blink::mojom::blink::PermissionDescriptorExtensionPtr> {
    static bool IsNull(const ::blink::mojom::blink::PermissionDescriptorExtensionPtr& input) { return !input; }
    static void SetToNull(::blink::mojom::blink::PermissionDescriptorExtensionPtr* output) { output->reset(); }

    static ::blink::mojom::blink::PermissionDescriptorExtension::Tag GetTag(const ::blink::mojom::blink::PermissionDescriptorExtensionPtr& input)
    {
        return input->which();
    }

    static const ::blink::mojom::blink::MidiPermissionDescriptorPtr& midi(const ::blink::mojom::blink::PermissionDescriptorExtensionPtr& input)
    {
        return input->get_midi();
    }

    static bool Read(::blink::mojom::blink::PermissionDescriptorExtension::DataView input, ::blink::mojom::blink::PermissionDescriptorExtensionPtr* output);
};

} // namespace mojo

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_PERMISSIONS_PERMISSION_MOJOM_BLINK_H_