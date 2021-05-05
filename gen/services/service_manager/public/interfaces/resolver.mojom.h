// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_RESOLVER_MOJOM_H_
#define SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_RESOLVER_MOJOM_H_

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
#include "mojo/common/file_path.mojom.h"
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
#include "services/service_manager/public/interfaces/interface_provider_spec.mojom.h"
#include "services/service_manager/public/interfaces/resolver.mojom-shared.h"
#include <string>
#include <vector>

namespace service_manager {
namespace mojom {
    class Resolver;
    using ResolverPtr = mojo::InterfacePtr<Resolver>;
    using ResolverPtrInfo = mojo::InterfacePtrInfo<Resolver>;
    using ThreadSafeResolverPtr = mojo::ThreadSafeInterfacePtr<Resolver>;
    using ResolverRequest = mojo::InterfaceRequest<Resolver>;
    using ResolverAssociatedPtr = mojo::AssociatedInterfacePtr<Resolver>;
    using ThreadSafeResolverAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<Resolver>;
    using ResolverAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<Resolver>;
    using ResolverAssociatedRequest = mojo::AssociatedInterfaceRequest<Resolver>;

    class ResolveResult;
    using ResolveResultPtr = mojo::StructPtr<ResolveResult>;

    class ResolverProxy;

    template <typename ImplRefTraits>
    class ResolverStub;

    class ResolverRequestValidator;
    class ResolverResponseValidator;

    class Resolver
        : public ResolverInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = ResolverProxy;

        template <typename ImplRefTraits>
        using Stub_ = ResolverStub<ImplRefTraits>;

        using RequestValidator_ = ResolverRequestValidator;
        using ResponseValidator_ = ResolverResponseValidator;
        enum MethodMinVersions : uint32_t {
            kResolveServiceNameMinVersion = 0,
        };
        virtual ~Resolver() { }

        using ResolveServiceNameCallback = base::Callback<void(ResolveResultPtr, ResolveResultPtr)>;
        virtual void ResolveServiceName(const std::string& service_name, const ResolveServiceNameCallback& callback) = 0;
    };

    class ResolverProxy
        : public Resolver {
    public:
        explicit ResolverProxy(mojo::MessageReceiverWithResponder* receiver);
        void ResolveServiceName(const std::string& service_name, const ResolveServiceNameCallback& callback) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class ResolverStubDispatch {
    public:
        static bool Accept(Resolver* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(Resolver* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<Resolver>>
    class ResolverStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        ResolverStub() { }
        ~ResolverStub() override { }

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
            return ResolverStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return ResolverStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class ResolverRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class ResolverResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

    class ResolveResult {
    public:
        using DataView = ResolveResultDataView;
        using Data_ = internal::ResolveResult_Data;

        static ResolveResultPtr New();

        template <typename U>
        static ResolveResultPtr From(const U& u)
        {
            return mojo::TypeConverter<ResolveResultPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, ResolveResult>::Convert(*this);
        }

        ResolveResult();
        ~ResolveResult();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = ResolveResultPtr>
        ResolveResultPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, ResolveResult>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                ResolveResult::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                ResolveResult::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::string name;
        std::unordered_map<std::string, ::service_manager::InterfaceProviderSpec> interface_provider_specs;
        base::FilePath package_path;
    };

    template <typename StructPtrType>
    ResolveResultPtr ResolveResult::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->name = mojo::internal::Clone(name);
        rv->interface_provider_specs = mojo::internal::Clone(interface_provider_specs);
        rv->package_path = mojo::internal::Clone(package_path);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, ResolveResult>::value>::type*>
    bool ResolveResult::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->name, other.name))
            return false;
        if (!mojo::internal::Equals(this->interface_provider_specs, other.interface_provider_specs))
            return false;
        if (!mojo::internal::Equals(this->package_path, other.package_path))
            return false;
        return true;
    }

} // namespace mojom
} // namespace service_manager

namespace mojo {

template <>
struct StructTraits<::service_manager::mojom::ResolveResult::DataView,
    ::service_manager::mojom::ResolveResultPtr> {
    static bool IsNull(const ::service_manager::mojom::ResolveResultPtr& input) { return !input; }
    static void SetToNull(::service_manager::mojom::ResolveResultPtr* output) { output->reset(); }

    static const decltype(::service_manager::mojom::ResolveResult::name)& name(
        const ::service_manager::mojom::ResolveResultPtr& input)
    {
        return input->name;
    }

    static const decltype(::service_manager::mojom::ResolveResult::interface_provider_specs)& interface_provider_specs(
        const ::service_manager::mojom::ResolveResultPtr& input)
    {
        return input->interface_provider_specs;
    }

    static const decltype(::service_manager::mojom::ResolveResult::package_path)& package_path(
        const ::service_manager::mojom::ResolveResultPtr& input)
    {
        return input->package_path;
    }

    static bool Read(::service_manager::mojom::ResolveResult::DataView input, ::service_manager::mojom::ResolveResultPtr* output);
};

} // namespace mojo

#endif // SERVICES_SERVICE_MANAGER_PUBLIC_INTERFACES_RESOLVER_MOJOM_H_