// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_DISPLAY_TEST_DISPLAY_CONTROLLER_MOJOM_H_
#define SERVICES_UI_PUBLIC_INTERFACES_DISPLAY_TEST_DISPLAY_CONTROLLER_MOJOM_H_

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
#include "services/ui/public/interfaces/display/test_display_controller.mojom-shared.h"
#include "ui/display/display.h"
#include "ui/gfx/geometry/insets.h"
#include "ui/gfx/geometry/point.h"
#include "ui/gfx/geometry/point_f.h"
#include "ui/gfx/geometry/rect.h"
#include "ui/gfx/geometry/rect_f.h"
#include "ui/gfx/geometry/safe_integer_conversions.h"
#include "ui/gfx/geometry/size.h"
#include "ui/gfx/geometry/vector2d.h"
#include "ui/gfx/geometry/vector2d_f.h"
#include <string>
#include <vector>

namespace display {
namespace mojom {
    class TestDisplayController;
    using TestDisplayControllerPtr = mojo::InterfacePtr<TestDisplayController>;
    using TestDisplayControllerPtrInfo = mojo::InterfacePtrInfo<TestDisplayController>;
    using ThreadSafeTestDisplayControllerPtr = mojo::ThreadSafeInterfacePtr<TestDisplayController>;
    using TestDisplayControllerRequest = mojo::InterfaceRequest<TestDisplayController>;
    using TestDisplayControllerAssociatedPtr = mojo::AssociatedInterfacePtr<TestDisplayController>;
    using ThreadSafeTestDisplayControllerAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<TestDisplayController>;
    using TestDisplayControllerAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<TestDisplayController>;
    using TestDisplayControllerAssociatedRequest = mojo::AssociatedInterfaceRequest<TestDisplayController>;

    class TestDisplayControllerProxy;

    template <typename ImplRefTraits>
    class TestDisplayControllerStub;

    class TestDisplayControllerRequestValidator;

    class TestDisplayController
        : public TestDisplayControllerInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = TestDisplayControllerProxy;

        template <typename ImplRefTraits>
        using Stub_ = TestDisplayControllerStub<ImplRefTraits>;

        using RequestValidator_ = TestDisplayControllerRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kToggleAddRemoveDisplayMinVersion = 0,
            kToggleDisplayResolutionMinVersion = 0,
        };
        virtual ~TestDisplayController() { }

        virtual void ToggleAddRemoveDisplay() = 0;

        virtual void ToggleDisplayResolution() = 0;
    };

    class TestDisplayControllerProxy
        : public TestDisplayController {
    public:
        explicit TestDisplayControllerProxy(mojo::MessageReceiverWithResponder* receiver);
        void ToggleAddRemoveDisplay() override;
        void ToggleDisplayResolution() override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class TestDisplayControllerStubDispatch {
    public:
        static bool Accept(TestDisplayController* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(TestDisplayController* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<TestDisplayController>>
    class TestDisplayControllerStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        TestDisplayControllerStub() { }
        ~TestDisplayControllerStub() override { }

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
            return TestDisplayControllerStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return TestDisplayControllerStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class TestDisplayControllerRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

} // namespace mojom
} // namespace display

namespace mojo {

} // namespace mojo

#endif // SERVICES_UI_PUBLIC_INTERFACES_DISPLAY_TEST_DISPLAY_CONTROLLER_MOJOM_H_