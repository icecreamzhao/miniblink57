// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef DEVICE_VIBRATION_VIBRATION_MANAGER_MOJOM_H_
#define DEVICE_VIBRATION_VIBRATION_MANAGER_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/optional.h"
#include "device/vibration/vibration_manager.mojom-shared.h"
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

namespace device {
class VibrationManager;
using VibrationManagerPtr = mojo::InterfacePtr<VibrationManager>;
using VibrationManagerPtrInfo = mojo::InterfacePtrInfo<VibrationManager>;
using ThreadSafeVibrationManagerPtr = mojo::ThreadSafeInterfacePtr<VibrationManager>;
using VibrationManagerRequest = mojo::InterfaceRequest<VibrationManager>;
using VibrationManagerAssociatedPtr = mojo::AssociatedInterfacePtr<VibrationManager>;
using ThreadSafeVibrationManagerAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<VibrationManager>;
using VibrationManagerAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<VibrationManager>;
using VibrationManagerAssociatedRequest = mojo::AssociatedInterfaceRequest<VibrationManager>;

class VibrationManagerProxy;

template <typename ImplRefTraits>
class VibrationManagerStub;

class VibrationManagerRequestValidator;
class VibrationManagerResponseValidator;

class VibrationManager
    : public VibrationManagerInterfaceBase {
public:
    static const char Name_[];
    static constexpr uint32_t Version_ = 0;
    static constexpr bool PassesAssociatedKinds_ = false;
    static constexpr bool HasSyncMethods_ = false;

    using Proxy_ = VibrationManagerProxy;

    template <typename ImplRefTraits>
    using Stub_ = VibrationManagerStub<ImplRefTraits>;

    using RequestValidator_ = VibrationManagerRequestValidator;
    using ResponseValidator_ = VibrationManagerResponseValidator;
    enum MethodMinVersions : uint32_t {
        kVibrateMinVersion = 0,
        kCancelMinVersion = 0,
    };
    virtual ~VibrationManager() { }

    using VibrateCallback = base::Callback<void()>;
    virtual void Vibrate(int64_t milliseconds, const VibrateCallback& callback) = 0;

    using CancelCallback = base::Callback<void()>;
    virtual void Cancel(const CancelCallback& callback) = 0;
};

class VibrationManagerProxy
    : public VibrationManager {
public:
    explicit VibrationManagerProxy(mojo::MessageReceiverWithResponder* receiver);
    void Vibrate(int64_t milliseconds, const VibrateCallback& callback) override;
    void Cancel(const CancelCallback& callback) override;

    void set_group_controller(
        scoped_refptr<mojo::AssociatedGroupController> group_controller)
    {
        group_controller_ = std::move(group_controller);
    }

private:
    mojo::MessageReceiverWithResponder* receiver_;
    scoped_refptr<mojo::AssociatedGroupController> group_controller_;
};
class VibrationManagerStubDispatch {
public:
    static bool Accept(VibrationManager* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message);
    static bool AcceptWithResponder(VibrationManager* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder);
};

template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<VibrationManager>>
class VibrationManagerStub
    : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
public:
    using ImplPointerType = typename ImplRefTraits::PointerType;

    VibrationManagerStub() { }
    ~VibrationManagerStub() override { }

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
        return VibrationManagerStubDispatch::Accept(
            ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
    }

    bool AcceptWithResponder(
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder) override
    {
        if (ImplRefTraits::IsNull(sink_))
            return false;
        return VibrationManagerStubDispatch::AcceptWithResponder(
            ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
            responder);
    }

private:
    ImplPointerType sink_;
    mojo::internal::SerializationContext serialization_context_;
};
class VibrationManagerRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
public:
    bool Accept(mojo::Message* message) override;
};
class VibrationManagerResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
public:
    bool Accept(mojo::Message* message) override;
};

} // namespace device

namespace mojo {

} // namespace mojo

#endif // DEVICE_VIBRATION_VIBRATION_MANAGER_MOJOM_H_