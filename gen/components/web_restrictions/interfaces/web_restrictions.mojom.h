// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_WEB_RESTRICTIONS_INTERFACES_WEB_RESTRICTIONS_MOJOM_H_
#define COMPONENTS_WEB_RESTRICTIONS_INTERFACES_WEB_RESTRICTIONS_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "components/web_restrictions/interfaces/web_restrictions.mojom-shared.h"
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

namespace web_restrictions {
namespace mojom {
    class WebRestrictions;
    using WebRestrictionsPtr = mojo::InterfacePtr<WebRestrictions>;
    using WebRestrictionsPtrInfo = mojo::InterfacePtrInfo<WebRestrictions>;
    using ThreadSafeWebRestrictionsPtr = mojo::ThreadSafeInterfacePtr<WebRestrictions>;
    using WebRestrictionsRequest = mojo::InterfaceRequest<WebRestrictions>;
    using WebRestrictionsAssociatedPtr = mojo::AssociatedInterfacePtr<WebRestrictions>;
    using ThreadSafeWebRestrictionsAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<WebRestrictions>;
    using WebRestrictionsAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<WebRestrictions>;
    using WebRestrictionsAssociatedRequest = mojo::AssociatedInterfaceRequest<WebRestrictions>;

    class ClientResult;
    using ClientResultPtr = mojo::StructPtr<ClientResult>;

    class WebRestrictionsProxy;

    template <typename ImplRefTraits>
    class WebRestrictionsStub;

    class WebRestrictionsRequestValidator;
    class WebRestrictionsResponseValidator;

    class WebRestrictions
        : public WebRestrictionsInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = true;

        using Proxy_ = WebRestrictionsProxy;

        template <typename ImplRefTraits>
        using Stub_ = WebRestrictionsStub<ImplRefTraits>;

        using RequestValidator_ = WebRestrictionsRequestValidator;
        using ResponseValidator_ = WebRestrictionsResponseValidator;
        enum MethodMinVersions : uint32_t {
            kGetResultMinVersion = 0,
            kRequestPermissionMinVersion = 0,
        };
        virtual ~WebRestrictions() { }

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool GetResult(const std::string& url, ClientResultPtr* reply);

        using GetResultCallback = base::Callback<void(ClientResultPtr)>;
        virtual void GetResult(const std::string& url, const GetResultCallback& callback) = 0;

        using RequestPermissionCallback = base::Callback<void(bool)>;
        virtual void RequestPermission(const std::string& url, const RequestPermissionCallback& callback) = 0;
    };

    class WebRestrictionsProxy
        : public WebRestrictions {
    public:
        explicit WebRestrictionsProxy(mojo::MessageReceiverWithResponder* receiver);
        bool GetResult(const std::string& url, ClientResultPtr* reply) override;
        void GetResult(const std::string& url, const GetResultCallback& callback) override;
        void RequestPermission(const std::string& url, const RequestPermissionCallback& callback) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class WebRestrictionsStubDispatch {
    public:
        static bool Accept(WebRestrictions* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(WebRestrictions* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<WebRestrictions>>
    class WebRestrictionsStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        WebRestrictionsStub() { }
        ~WebRestrictionsStub() override { }

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
            return WebRestrictionsStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return WebRestrictionsStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class WebRestrictionsRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class WebRestrictionsResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

    class ClientResult {
    public:
        using DataView = ClientResultDataView;
        using Data_ = internal::ClientResult_Data;

        static ClientResultPtr New();

        template <typename U>
        static ClientResultPtr From(const U& u)
        {
            return mojo::TypeConverter<ClientResultPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, ClientResult>::Convert(*this);
        }

        ClientResult();
        ~ClientResult();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = ClientResultPtr>
        ClientResultPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, ClientResult>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                ClientResult::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                ClientResult::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::unordered_map<std::string, int32_t> intParams;
        std::unordered_map<std::string, std::string> stringParams;
    };

    template <typename StructPtrType>
    ClientResultPtr ClientResult::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->intParams = mojo::internal::Clone(intParams);
        rv->stringParams = mojo::internal::Clone(stringParams);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, ClientResult>::value>::type*>
    bool ClientResult::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->intParams, other.intParams))
            return false;
        if (!mojo::internal::Equals(this->stringParams, other.stringParams))
            return false;
        return true;
    }

} // namespace mojom
} // namespace web_restrictions

namespace mojo {

template <>
struct StructTraits<::web_restrictions::mojom::ClientResult::DataView,
    ::web_restrictions::mojom::ClientResultPtr> {
    static bool IsNull(const ::web_restrictions::mojom::ClientResultPtr& input) { return !input; }
    static void SetToNull(::web_restrictions::mojom::ClientResultPtr* output) { output->reset(); }

    static const decltype(::web_restrictions::mojom::ClientResult::intParams)& intParams(
        const ::web_restrictions::mojom::ClientResultPtr& input)
    {
        return input->intParams;
    }

    static const decltype(::web_restrictions::mojom::ClientResult::stringParams)& stringParams(
        const ::web_restrictions::mojom::ClientResultPtr& input)
    {
        return input->stringParams;
    }

    static bool Read(::web_restrictions::mojom::ClientResult::DataView input, ::web_restrictions::mojom::ClientResultPtr* output);
};

} // namespace mojo

#endif // COMPONENTS_WEB_RESTRICTIONS_INTERFACES_WEB_RESTRICTIONS_MOJOM_H_