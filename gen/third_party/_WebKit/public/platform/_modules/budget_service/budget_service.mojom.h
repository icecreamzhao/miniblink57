// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_BUDGET_SERVICE_BUDGET_SERVICE_MOJOM_H_
#define THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_BUDGET_SERVICE_BUDGET_SERVICE_MOJOM_H_

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
#include "content/common/bluetooth/web_bluetooth_device_id.h"
#include "content/common/content_export.h"
#include "content/public/common/media_metadata.h"
#include "content/public/common/referrer.h"
#include "device/bluetooth/bluetooth_uuid.h"
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
#include "third_party/WebKit/public/platform/WebReferrerPolicy.h"
#include "third_party/WebKit/public/platform/modules/budget_service/budget_service.mojom-shared.h"
#include "third_party/WebKit/public/web/WebConsoleMessage.h"
#include "third_party/WebKit/public/web/WebWindowFeatures.h"
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
#include "url/mojo/origin.mojom.h"
#include "url/origin.h"
#include <string>
#include <vector>

namespace blink {
namespace mojom {
    class BudgetService;
    using BudgetServicePtr = mojo::InterfacePtr<BudgetService>;
    using BudgetServicePtrInfo = mojo::InterfacePtrInfo<BudgetService>;
    using ThreadSafeBudgetServicePtr = mojo::ThreadSafeInterfacePtr<BudgetService>;
    using BudgetServiceRequest = mojo::InterfaceRequest<BudgetService>;
    using BudgetServiceAssociatedPtr = mojo::AssociatedInterfacePtr<BudgetService>;
    using ThreadSafeBudgetServiceAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<BudgetService>;
    using BudgetServiceAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<BudgetService>;
    using BudgetServiceAssociatedRequest = mojo::AssociatedInterfaceRequest<BudgetService>;

    class BudgetState;
    using BudgetStatePtr = mojo::InlinedStructPtr<BudgetState>;

    class BudgetServiceProxy;

    template <typename ImplRefTraits>
    class BudgetServiceStub;

    class BudgetServiceRequestValidator;
    class BudgetServiceResponseValidator;

    class CONTENT_EXPORT BudgetService
        : public BudgetServiceInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = BudgetServiceProxy;

        template <typename ImplRefTraits>
        using Stub_ = BudgetServiceStub<ImplRefTraits>;

        using RequestValidator_ = BudgetServiceRequestValidator;
        using ResponseValidator_ = BudgetServiceResponseValidator;
        enum MethodMinVersions : uint32_t {
            kGetCostMinVersion = 0,
            kGetBudgetMinVersion = 0,
            kReserveMinVersion = 0,
        };
        virtual ~BudgetService() { }

        using GetCostCallback = base::Callback<void(double)>;
        virtual void GetCost(BudgetOperationType operation, const GetCostCallback& callback) = 0;

        using GetBudgetCallback = base::Callback<void(BudgetServiceErrorType, std::vector<BudgetStatePtr>)>;
        virtual void GetBudget(const url::Origin& origin, const GetBudgetCallback& callback) = 0;

        using ReserveCallback = base::Callback<void(BudgetServiceErrorType, bool)>;
        virtual void Reserve(const url::Origin& origin, BudgetOperationType operation, const ReserveCallback& callback) = 0;
    };

    class CONTENT_EXPORT BudgetServiceProxy
        : public BudgetService {
    public:
        explicit BudgetServiceProxy(mojo::MessageReceiverWithResponder* receiver);
        void GetCost(BudgetOperationType operation, const GetCostCallback& callback) override;
        void GetBudget(const url::Origin& origin, const GetBudgetCallback& callback) override;
        void Reserve(const url::Origin& origin, BudgetOperationType operation, const ReserveCallback& callback) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class CONTENT_EXPORT BudgetServiceStubDispatch {
    public:
        static bool Accept(BudgetService* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(BudgetService* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<BudgetService>>
    class BudgetServiceStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        BudgetServiceStub() { }
        ~BudgetServiceStub() override { }

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
            return BudgetServiceStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return BudgetServiceStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class CONTENT_EXPORT BudgetServiceRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class CONTENT_EXPORT BudgetServiceResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

    class CONTENT_EXPORT BudgetState {
    public:
        using DataView = BudgetStateDataView;
        using Data_ = internal::BudgetState_Data;

        static BudgetStatePtr New();

        template <typename U>
        static BudgetStatePtr From(const U& u)
        {
            return mojo::TypeConverter<BudgetStatePtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, BudgetState>::Convert(*this);
        }

        BudgetState();
        ~BudgetState();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = BudgetStatePtr>
        BudgetStatePtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, BudgetState>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                BudgetState::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                BudgetState::DataView, std::vector<uint8_t>>(
                input, output);
        }

        double budget_at;
        double time;
    };

    template <typename StructPtrType>
    BudgetStatePtr BudgetState::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->budget_at = mojo::internal::Clone(budget_at);
        rv->time = mojo::internal::Clone(time);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, BudgetState>::value>::type*>
    bool BudgetState::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->budget_at, other.budget_at))
            return false;
        if (!mojo::internal::Equals(this->time, other.time))
            return false;
        return true;
    }

} // namespace mojom
} // namespace blink

namespace mojo {

template <>
struct CONTENT_EXPORT StructTraits<::blink::mojom::BudgetState::DataView,
    ::blink::mojom::BudgetStatePtr> {
    static bool IsNull(const ::blink::mojom::BudgetStatePtr& input) { return !input; }
    static void SetToNull(::blink::mojom::BudgetStatePtr* output) { output->reset(); }

    static decltype(::blink::mojom::BudgetState::budget_at) budget_at(
        const ::blink::mojom::BudgetStatePtr& input)
    {
        return input->budget_at;
    }

    static decltype(::blink::mojom::BudgetState::time) time(
        const ::blink::mojom::BudgetStatePtr& input)
    {
        return input->time;
    }

    static bool Read(::blink::mojom::BudgetState::DataView input, ::blink::mojom::BudgetStatePtr* output);
};

} // namespace mojo

#endif // THIRD_PARTY_WEBKIT_PUBLIC_PLATFORM_MODULES_BUDGET_SERVICE_BUDGET_SERVICE_MOJOM_H_