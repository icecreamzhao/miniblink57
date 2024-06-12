// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_DISPLAY_DISPLAY_CONTROLLER_MOJOM_H_
#define SERVICES_UI_PUBLIC_INTERFACES_DISPLAY_DISPLAY_CONTROLLER_MOJOM_H_

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
#include "services/ui/public/interfaces/display/display_controller.mojom-shared.h"
#include "ui/display/display.h"
#include "ui/gfx/geometry/insets.h"
#include "ui/gfx/geometry/mojo/geometry.mojom.h"
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
    class DisplayController;
    using DisplayControllerPtr = mojo::InterfacePtr<DisplayController>;
    using DisplayControllerPtrInfo = mojo::InterfacePtrInfo<DisplayController>;
    using ThreadSafeDisplayControllerPtr = mojo::ThreadSafeInterfacePtr<DisplayController>;
    using DisplayControllerRequest = mojo::InterfaceRequest<DisplayController>;
    using DisplayControllerAssociatedPtr = mojo::AssociatedInterfacePtr<DisplayController>;
    using ThreadSafeDisplayControllerAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<DisplayController>;
    using DisplayControllerAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<DisplayController>;
    using DisplayControllerAssociatedRequest = mojo::AssociatedInterfaceRequest<DisplayController>;

    class DisplayControllerProxy;

    template <typename ImplRefTraits>
    class DisplayControllerStub;

    class DisplayControllerRequestValidator;

    class DisplayController
        : public DisplayControllerInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = DisplayControllerProxy;

        template <typename ImplRefTraits>
        using Stub_ = DisplayControllerStub<ImplRefTraits>;

        using RequestValidator_ = DisplayControllerRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kIncreaseInternalDisplayZoomMinVersion = 0,
            kDecreaseInternalDisplayZoomMinVersion = 0,
            kResetInternalDisplayZoomMinVersion = 0,
            kRotateCurrentDisplayCWMinVersion = 0,
            kSwapPrimaryDisplayMinVersion = 0,
            kToggleMirrorModeMinVersion = 0,
            kSetDisplayWorkAreaMinVersion = 0,
        };
        virtual ~DisplayController() { }

        virtual void IncreaseInternalDisplayZoom() = 0;

        virtual void DecreaseInternalDisplayZoom() = 0;

        virtual void ResetInternalDisplayZoom() = 0;

        virtual void RotateCurrentDisplayCW() = 0;

        virtual void SwapPrimaryDisplay() = 0;

        virtual void ToggleMirrorMode() = 0;

        virtual void SetDisplayWorkArea(int64_t display_id, const gfx::Size& size, const gfx::Insets& insets) = 0;
    };

    class DisplayControllerProxy
        : public DisplayController {
    public:
        explicit DisplayControllerProxy(mojo::MessageReceiverWithResponder* receiver);
        void IncreaseInternalDisplayZoom() override;
        void DecreaseInternalDisplayZoom() override;
        void ResetInternalDisplayZoom() override;
        void RotateCurrentDisplayCW() override;
        void SwapPrimaryDisplay() override;
        void ToggleMirrorMode() override;
        void SetDisplayWorkArea(int64_t display_id, const gfx::Size& size, const gfx::Insets& insets) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class DisplayControllerStubDispatch {
    public:
        static bool Accept(DisplayController* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(DisplayController* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<DisplayController>>
    class DisplayControllerStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        DisplayControllerStub() { }
        ~DisplayControllerStub() override { }

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
            return DisplayControllerStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return DisplayControllerStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class DisplayControllerRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

} // namespace mojom
} // namespace display

namespace mojo {

} // namespace mojo

#endif // SERVICES_UI_PUBLIC_INTERFACES_DISPLAY_DISPLAY_CONTROLLER_MOJOM_H_