// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_CLIPBOARD_MOJOM_H_
#define SERVICES_UI_PUBLIC_INTERFACES_CLIPBOARD_MOJOM_H_

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
#include "cc/input/selection.h"
#include "cc/output/begin_frame_args.h"
#include "cc/output/compositor_frame.h"
#include "cc/output/compositor_frame_metadata.h"
#include "cc/output/filter_operation.h"
#include "cc/output/filter_operations.h"
#include "cc/quads/draw_quad.h"
#include "cc/quads/render_pass.h"
#include "cc/quads/shared_quad_state.h"
#include "cc/resources/returned_resource.h"
#include "cc/resources/transferable_resource.h"
#include "cc/surfaces/frame_sink_id.h"
#include "cc/surfaces/local_frame_id.h"
#include "cc/surfaces/surface_id.h"
#include "cc/surfaces/surface_info.h"
#include "cc/surfaces/surface_reference.h"
#include "cc/surfaces/surface_sequence.h"
#include "gpu/command_buffer/common/capabilities.h"
#include "gpu/command_buffer/common/mailbox.h"
#include "gpu/command_buffer/common/mailbox_holder.h"
#include "gpu/command_buffer/common/sync_token.h"
#include "gpu/command_buffer/service/gpu_preferences.h"
#include "gpu/config/dx_diag_node.h"
#include "gpu/config/gpu_info.h"
#include "gpu/ipc/common/surface_handle.h"
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
#include "services/ui/public/interfaces/clipboard.mojom-shared.h"
#include "third_party/skia/include/core/SkBitmap.h"
#include "third_party/skia/include/core/SkImageFilter.h"
#include "ui/base/ime/composition_text.h"
#include "ui/base/ime/composition_underline.h"
#include "ui/base/ime/text_input_mode.h"
#include "ui/base/ime/text_input_type.h"
#include "ui/display/display.h"
#include "ui/events/event.h"
#include "ui/events/latency_info.h"
#include "ui/gfx/buffer_types.h"
#include "ui/gfx/color_space.h"
#include "ui/gfx/geometry/insets.h"
#include "ui/gfx/geometry/point.h"
#include "ui/gfx/geometry/point_f.h"
#include "ui/gfx/geometry/rect.h"
#include "ui/gfx/geometry/rect_f.h"
#include "ui/gfx/geometry/safe_integer_conversions.h"
#include "ui/gfx/geometry/size.h"
#include "ui/gfx/geometry/vector2d.h"
#include "ui/gfx/geometry/vector2d_f.h"
#include "ui/gfx/gpu_memory_buffer.h"
#include "ui/gfx/icc_profile.h"
#include "ui/gfx/native_pixmap_handle.h"
#include "ui/gfx/native_widget_types.h"
#include "ui/gfx/range/range.h"
#include "ui/gfx/range/range_f.h"
#include "ui/gfx/selection_bound.h"
#include "ui/gfx/transform.h"
#include <string>
#include <vector>

namespace ui {
namespace mojom {
    extern const char kMimeTypeHTML[];
    extern const char kMimeTypeMozillaURL[];
    extern const char kMimeTypePNG[];
    extern const char kMimeTypeRTF[];
    extern const char kMimeTypeText[];
    extern const char kMimeTypeURIList[];
    extern const char kMimeTypeURL[];
    class Clipboard;
    using ClipboardPtr = mojo::InterfacePtr<Clipboard>;
    using ClipboardPtrInfo = mojo::InterfacePtrInfo<Clipboard>;
    using ThreadSafeClipboardPtr = mojo::ThreadSafeInterfacePtr<Clipboard>;
    using ClipboardRequest = mojo::InterfaceRequest<Clipboard>;
    using ClipboardAssociatedPtr = mojo::AssociatedInterfacePtr<Clipboard>;
    using ThreadSafeClipboardAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<Clipboard>;
    using ClipboardAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<Clipboard>;
    using ClipboardAssociatedRequest = mojo::AssociatedInterfaceRequest<Clipboard>;

    class ClipboardProxy;

    template <typename ImplRefTraits>
    class ClipboardStub;

    class ClipboardRequestValidator;
    class ClipboardResponseValidator;

    class Clipboard
        : public ClipboardInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = true;

        using Proxy_ = ClipboardProxy;

        template <typename ImplRefTraits>
        using Stub_ = ClipboardStub<ImplRefTraits>;

        using RequestValidator_ = ClipboardRequestValidator;
        using ResponseValidator_ = ClipboardResponseValidator;
        enum MethodMinVersions : uint32_t {
            kGetSequenceNumberMinVersion = 0,
            kGetAvailableMimeTypesMinVersion = 0,
            kReadClipboardDataMinVersion = 0,
            kWriteClipboardDataMinVersion = 0,
        };
        using Type = Clipboard_Type;
        virtual ~Clipboard() { }

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool GetSequenceNumber(Clipboard::Type clipboard_type, uint64_t* sequence);

        using GetSequenceNumberCallback = base::Callback<void(uint64_t)>;
        virtual void GetSequenceNumber(Clipboard::Type clipboard_type, const GetSequenceNumberCallback& callback) = 0;

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool GetAvailableMimeTypes(Clipboard::Type clipboard_types, uint64_t* sequence, std::vector<std::string>* types);

        using GetAvailableMimeTypesCallback = base::Callback<void(uint64_t, const std::vector<std::string>&)>;
        virtual void GetAvailableMimeTypes(Clipboard::Type clipboard_types, const GetAvailableMimeTypesCallback& callback) = 0;

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool ReadClipboardData(Clipboard::Type clipboard_type, const std::string& mime_type, uint64_t* sequence, base::Optional<std::vector<uint8_t>>* data);

        using ReadClipboardDataCallback = base::Callback<void(uint64_t, const base::Optional<std::vector<uint8_t>>&)>;
        virtual void ReadClipboardData(Clipboard::Type clipboard_type, const std::string& mime_type, const ReadClipboardDataCallback& callback) = 0;

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool WriteClipboardData(Clipboard::Type clipboard_type, const base::Optional<std::unordered_map<std::string, std::vector<uint8_t>>>& data, uint64_t* sequence);

        using WriteClipboardDataCallback = base::Callback<void(uint64_t)>;
        virtual void WriteClipboardData(Clipboard::Type clipboard_type, const base::Optional<std::unordered_map<std::string, std::vector<uint8_t>>>& data, const WriteClipboardDataCallback& callback) = 0;
    };

    class ClipboardProxy
        : public Clipboard {
    public:
        explicit ClipboardProxy(mojo::MessageReceiverWithResponder* receiver);
        bool GetSequenceNumber(Clipboard::Type clipboard_type, uint64_t* sequence) override;
        void GetSequenceNumber(Clipboard::Type clipboard_type, const GetSequenceNumberCallback& callback) override;
        bool GetAvailableMimeTypes(Clipboard::Type clipboard_types, uint64_t* sequence, std::vector<std::string>* types) override;
        void GetAvailableMimeTypes(Clipboard::Type clipboard_types, const GetAvailableMimeTypesCallback& callback) override;
        bool ReadClipboardData(Clipboard::Type clipboard_type, const std::string& mime_type, uint64_t* sequence, base::Optional<std::vector<uint8_t>>* data) override;
        void ReadClipboardData(Clipboard::Type clipboard_type, const std::string& mime_type, const ReadClipboardDataCallback& callback) override;
        bool WriteClipboardData(Clipboard::Type clipboard_type, const base::Optional<std::unordered_map<std::string, std::vector<uint8_t>>>& data, uint64_t* sequence) override;
        void WriteClipboardData(Clipboard::Type clipboard_type, const base::Optional<std::unordered_map<std::string, std::vector<uint8_t>>>& data, const WriteClipboardDataCallback& callback) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class ClipboardStubDispatch {
    public:
        static bool Accept(Clipboard* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(Clipboard* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<Clipboard>>
    class ClipboardStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        ClipboardStub() { }
        ~ClipboardStub() override { }

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
            return ClipboardStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return ClipboardStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class ClipboardRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class ClipboardResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

} // namespace mojom
} // namespace ui

namespace mojo {

} // namespace mojo

#endif // SERVICES_UI_PUBLIC_INTERFACES_CLIPBOARD_MOJOM_H_