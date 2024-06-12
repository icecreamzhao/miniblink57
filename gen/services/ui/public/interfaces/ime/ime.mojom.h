// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_UI_PUBLIC_INTERFACES_IME_IME_MOJOM_H_
#define SERVICES_UI_PUBLIC_INTERFACES_IME_IME_MOJOM_H_

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
#include "mojo/common/text_direction.mojom.h"
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
#include "services/ui/public/interfaces/ime/ime.mojom-shared.h"
#include "ui/base/ime/composition_text.h"
#include "ui/base/ime/composition_underline.h"
#include "ui/base/ime/text_input_mode.h"
#include "ui/base/ime/text_input_type.h"
#include "ui/events/event.h"
#include "ui/events/latency_info.h"
#include "ui/events/mojo/event.mojom.h"
#include "ui/gfx/buffer_types.h"
#include "ui/gfx/color_space.h"
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
#include "ui/gfx/gpu_memory_buffer.h"
#include "ui/gfx/icc_profile.h"
#include "ui/gfx/native_pixmap_handle.h"
#include "ui/gfx/native_widget_types.h"
#include "ui/gfx/range/mojo/range.mojom.h"
#include "ui/gfx/range/range.h"
#include "ui/gfx/range/range_f.h"
#include "ui/gfx/selection_bound.h"
#include "ui/gfx/transform.h"
#include <string>
#include <vector>

namespace ui {
namespace mojom {
    class IMEDriver;
    using IMEDriverPtr = mojo::InterfacePtr<IMEDriver>;
    using IMEDriverPtrInfo = mojo::InterfacePtrInfo<IMEDriver>;
    using ThreadSafeIMEDriverPtr = mojo::ThreadSafeInterfacePtr<IMEDriver>;
    using IMEDriverRequest = mojo::InterfaceRequest<IMEDriver>;
    using IMEDriverAssociatedPtr = mojo::AssociatedInterfacePtr<IMEDriver>;
    using ThreadSafeIMEDriverAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<IMEDriver>;
    using IMEDriverAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<IMEDriver>;
    using IMEDriverAssociatedRequest = mojo::AssociatedInterfaceRequest<IMEDriver>;

    class IMEServer;
    using IMEServerPtr = mojo::InterfacePtr<IMEServer>;
    using IMEServerPtrInfo = mojo::InterfacePtrInfo<IMEServer>;
    using ThreadSafeIMEServerPtr = mojo::ThreadSafeInterfacePtr<IMEServer>;
    using IMEServerRequest = mojo::InterfaceRequest<IMEServer>;
    using IMEServerAssociatedPtr = mojo::AssociatedInterfacePtr<IMEServer>;
    using ThreadSafeIMEServerAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<IMEServer>;
    using IMEServerAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<IMEServer>;
    using IMEServerAssociatedRequest = mojo::AssociatedInterfaceRequest<IMEServer>;

    class IMERegistrar;
    using IMERegistrarPtr = mojo::InterfacePtr<IMERegistrar>;
    using IMERegistrarPtrInfo = mojo::InterfacePtrInfo<IMERegistrar>;
    using ThreadSafeIMERegistrarPtr = mojo::ThreadSafeInterfacePtr<IMERegistrar>;
    using IMERegistrarRequest = mojo::InterfaceRequest<IMERegistrar>;
    using IMERegistrarAssociatedPtr = mojo::AssociatedInterfacePtr<IMERegistrar>;
    using ThreadSafeIMERegistrarAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<IMERegistrar>;
    using IMERegistrarAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<IMERegistrar>;
    using IMERegistrarAssociatedRequest = mojo::AssociatedInterfaceRequest<IMERegistrar>;

    class InputMethod;
    using InputMethodPtr = mojo::InterfacePtr<InputMethod>;
    using InputMethodPtrInfo = mojo::InterfacePtrInfo<InputMethod>;
    using ThreadSafeInputMethodPtr = mojo::ThreadSafeInterfacePtr<InputMethod>;
    using InputMethodRequest = mojo::InterfaceRequest<InputMethod>;
    using InputMethodAssociatedPtr = mojo::AssociatedInterfacePtr<InputMethod>;
    using ThreadSafeInputMethodAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<InputMethod>;
    using InputMethodAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<InputMethod>;
    using InputMethodAssociatedRequest = mojo::AssociatedInterfaceRequest<InputMethod>;

    class TextInputClient;
    using TextInputClientPtr = mojo::InterfacePtr<TextInputClient>;
    using TextInputClientPtrInfo = mojo::InterfacePtrInfo<TextInputClient>;
    using ThreadSafeTextInputClientPtr = mojo::ThreadSafeInterfacePtr<TextInputClient>;
    using TextInputClientRequest = mojo::InterfaceRequest<TextInputClient>;
    using TextInputClientAssociatedPtr = mojo::AssociatedInterfacePtr<TextInputClient>;
    using ThreadSafeTextInputClientAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<TextInputClient>;
    using TextInputClientAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<TextInputClient>;
    using TextInputClientAssociatedRequest = mojo::AssociatedInterfaceRequest<TextInputClient>;

    class CompositionUnderline;
    using CompositionUnderlinePtr = mojo::StructPtr<CompositionUnderline>;

    class CompositionText;
    using CompositionTextPtr = mojo::StructPtr<CompositionText>;

    class StartSessionDetails;
    using StartSessionDetailsPtr = mojo::StructPtr<StartSessionDetails>;

    class IMEDriverProxy;

    template <typename ImplRefTraits>
    class IMEDriverStub;

    class IMEDriverRequestValidator;

    class IMEDriver
        : public IMEDriverInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = IMEDriverProxy;

        template <typename ImplRefTraits>
        using Stub_ = IMEDriverStub<ImplRefTraits>;

        using RequestValidator_ = IMEDriverRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kStartSessionMinVersion = 0,
            kCancelSessionMinVersion = 0,
        };
        virtual ~IMEDriver() { }

        virtual void StartSession(int32_t session_id, StartSessionDetailsPtr details) = 0;

        virtual void CancelSession(int32_t session_id) = 0;
    };

    class IMEServerProxy;

    template <typename ImplRefTraits>
    class IMEServerStub;

    class IMEServerRequestValidator;

    class IMEServer
        : public IMEServerInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = IMEServerProxy;

        template <typename ImplRefTraits>
        using Stub_ = IMEServerStub<ImplRefTraits>;

        using RequestValidator_ = IMEServerRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kStartSessionMinVersion = 0,
        };
        virtual ~IMEServer() { }

        virtual void StartSession(StartSessionDetailsPtr details) = 0;
    };

    class IMERegistrarProxy;

    template <typename ImplRefTraits>
    class IMERegistrarStub;

    class IMERegistrarRequestValidator;

    class IMERegistrar
        : public IMERegistrarInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = IMERegistrarProxy;

        template <typename ImplRefTraits>
        using Stub_ = IMERegistrarStub<ImplRefTraits>;

        using RequestValidator_ = IMERegistrarRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kRegisterDriverMinVersion = 0,
        };
        virtual ~IMERegistrar() { }

        virtual void RegisterDriver(IMEDriverPtr driver) = 0;
    };

    class InputMethodProxy;

    template <typename ImplRefTraits>
    class InputMethodStub;

    class InputMethodRequestValidator;
    class InputMethodResponseValidator;

    class InputMethod
        : public InputMethodInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = InputMethodProxy;

        template <typename ImplRefTraits>
        using Stub_ = InputMethodStub<ImplRefTraits>;

        using RequestValidator_ = InputMethodRequestValidator;
        using ResponseValidator_ = InputMethodResponseValidator;
        enum MethodMinVersions : uint32_t {
            kOnTextInputTypeChangedMinVersion = 0,
            kOnCaretBoundsChangedMinVersion = 0,
            kProcessKeyEventMinVersion = 0,
            kCancelCompositionMinVersion = 0,
        };
        virtual ~InputMethod() { }

        virtual void OnTextInputTypeChanged(ui::TextInputType text_input_type) = 0;

        virtual void OnCaretBoundsChanged(const gfx::Rect& caret_bounds) = 0;

        using ProcessKeyEventCallback = base::Callback<void(bool)>;
        virtual void ProcessKeyEvent(std::unique_ptr<ui::Event> key_event, const ProcessKeyEventCallback& callback) = 0;

        virtual void CancelComposition() = 0;
    };

    class TextInputClientProxy;

    template <typename ImplRefTraits>
    class TextInputClientStub;

    class TextInputClientRequestValidator;

    class TextInputClient
        : public TextInputClientInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = TextInputClientProxy;

        template <typename ImplRefTraits>
        using Stub_ = TextInputClientStub<ImplRefTraits>;

        using RequestValidator_ = TextInputClientRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kSetCompositionTextMinVersion = 0,
            kConfirmCompositionTextMinVersion = 0,
            kClearCompositionTextMinVersion = 0,
            kInsertTextMinVersion = 0,
            kInsertCharMinVersion = 0,
        };
        virtual ~TextInputClient() { }

        virtual void SetCompositionText(const ui::CompositionText& composition) = 0;

        virtual void ConfirmCompositionText() = 0;

        virtual void ClearCompositionText() = 0;

        virtual void InsertText(const std::string& text) = 0;

        virtual void InsertChar(std::unique_ptr<ui::Event> event) = 0;
    };

    class IMEDriverProxy
        : public IMEDriver {
    public:
        explicit IMEDriverProxy(mojo::MessageReceiverWithResponder* receiver);
        void StartSession(int32_t session_id, StartSessionDetailsPtr details) override;
        void CancelSession(int32_t session_id) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class IMEServerProxy
        : public IMEServer {
    public:
        explicit IMEServerProxy(mojo::MessageReceiverWithResponder* receiver);
        void StartSession(StartSessionDetailsPtr details) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class IMERegistrarProxy
        : public IMERegistrar {
    public:
        explicit IMERegistrarProxy(mojo::MessageReceiverWithResponder* receiver);
        void RegisterDriver(IMEDriverPtr driver) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class InputMethodProxy
        : public InputMethod {
    public:
        explicit InputMethodProxy(mojo::MessageReceiverWithResponder* receiver);
        void OnTextInputTypeChanged(ui::TextInputType text_input_type) override;
        void OnCaretBoundsChanged(const gfx::Rect& caret_bounds) override;
        void ProcessKeyEvent(std::unique_ptr<ui::Event> key_event, const ProcessKeyEventCallback& callback) override;
        void CancelComposition() override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class TextInputClientProxy
        : public TextInputClient {
    public:
        explicit TextInputClientProxy(mojo::MessageReceiverWithResponder* receiver);
        void SetCompositionText(const ui::CompositionText& composition) override;
        void ConfirmCompositionText() override;
        void ClearCompositionText() override;
        void InsertText(const std::string& text) override;
        void InsertChar(std::unique_ptr<ui::Event> event) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class IMEDriverStubDispatch {
    public:
        static bool Accept(IMEDriver* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(IMEDriver* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<IMEDriver>>
    class IMEDriverStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        IMEDriverStub() { }
        ~IMEDriverStub() override { }

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
            return IMEDriverStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return IMEDriverStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class IMEServerStubDispatch {
    public:
        static bool Accept(IMEServer* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(IMEServer* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<IMEServer>>
    class IMEServerStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        IMEServerStub() { }
        ~IMEServerStub() override { }

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
            return IMEServerStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return IMEServerStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class IMERegistrarStubDispatch {
    public:
        static bool Accept(IMERegistrar* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(IMERegistrar* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<IMERegistrar>>
    class IMERegistrarStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        IMERegistrarStub() { }
        ~IMERegistrarStub() override { }

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
            return IMERegistrarStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return IMERegistrarStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class InputMethodStubDispatch {
    public:
        static bool Accept(InputMethod* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(InputMethod* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<InputMethod>>
    class InputMethodStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        InputMethodStub() { }
        ~InputMethodStub() override { }

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
            return InputMethodStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return InputMethodStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class TextInputClientStubDispatch {
    public:
        static bool Accept(TextInputClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(TextInputClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<TextInputClient>>
    class TextInputClientStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        TextInputClientStub() { }
        ~TextInputClientStub() override { }

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
            return TextInputClientStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return TextInputClientStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class IMEDriverRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class IMEServerRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class IMERegistrarRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class InputMethodRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class TextInputClientRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class InputMethodResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

    class CompositionUnderline {
    public:
        using DataView = CompositionUnderlineDataView;
        using Data_ = internal::CompositionUnderline_Data;

        static CompositionUnderlinePtr New();

        template <typename U>
        static CompositionUnderlinePtr From(const U& u)
        {
            return mojo::TypeConverter<CompositionUnderlinePtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, CompositionUnderline>::Convert(*this);
        }

        CompositionUnderline();
        ~CompositionUnderline();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = CompositionUnderlinePtr>
        CompositionUnderlinePtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, CompositionUnderline>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                CompositionUnderline::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                CompositionUnderline::DataView, std::vector<uint8_t>>(
                input, output);
        }

        uint32_t start_offset;
        uint32_t end_offset;
        bool thick;
        uint32_t color;
        uint32_t background_color;
    };

    class CompositionText {
    public:
        using DataView = CompositionTextDataView;
        using Data_ = internal::CompositionText_Data;

        static CompositionTextPtr New();

        template <typename U>
        static CompositionTextPtr From(const U& u)
        {
            return mojo::TypeConverter<CompositionTextPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, CompositionText>::Convert(*this);
        }

        CompositionText();
        ~CompositionText();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = CompositionTextPtr>
        CompositionTextPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, CompositionText>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                CompositionText::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                CompositionText::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::string text;
        std::vector<ui::CompositionUnderline> underlines;
        gfx::Range selection;
    };

    class StartSessionDetails {
    public:
        using DataView = StartSessionDetailsDataView;
        using Data_ = internal::StartSessionDetails_Data;

        static StartSessionDetailsPtr New();

        template <typename U>
        static StartSessionDetailsPtr From(const U& u)
        {
            return mojo::TypeConverter<StartSessionDetailsPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, StartSessionDetails>::Convert(*this);
        }

        StartSessionDetails();
        ~StartSessionDetails();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = StartSessionDetailsPtr>
        StartSessionDetailsPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, StartSessionDetails>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                StartSessionDetails::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                StartSessionDetails::DataView, std::vector<uint8_t>>(
                input, output);
        }

        TextInputClientPtr client;
        InputMethodRequest input_method_request;
        ui::TextInputType text_input_type;
        ui::TextInputMode text_input_mode;
        base::i18n::TextDirection text_direction;
        int32_t text_input_flags;
        gfx::Rect caret_bounds;

    private:
        DISALLOW_COPY_AND_ASSIGN(StartSessionDetails);
    };

    template <typename StructPtrType>
    CompositionUnderlinePtr CompositionUnderline::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->start_offset = mojo::internal::Clone(start_offset);
        rv->end_offset = mojo::internal::Clone(end_offset);
        rv->thick = mojo::internal::Clone(thick);
        rv->color = mojo::internal::Clone(color);
        rv->background_color = mojo::internal::Clone(background_color);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, CompositionUnderline>::value>::type*>
    bool CompositionUnderline::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->start_offset, other.start_offset))
            return false;
        if (!mojo::internal::Equals(this->end_offset, other.end_offset))
            return false;
        if (!mojo::internal::Equals(this->thick, other.thick))
            return false;
        if (!mojo::internal::Equals(this->color, other.color))
            return false;
        if (!mojo::internal::Equals(this->background_color, other.background_color))
            return false;
        return true;
    }
    template <typename StructPtrType>
    CompositionTextPtr CompositionText::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->text = mojo::internal::Clone(text);
        rv->underlines = mojo::internal::Clone(underlines);
        rv->selection = mojo::internal::Clone(selection);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, CompositionText>::value>::type*>
    bool CompositionText::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->text, other.text))
            return false;
        if (!mojo::internal::Equals(this->underlines, other.underlines))
            return false;
        if (!mojo::internal::Equals(this->selection, other.selection))
            return false;
        return true;
    }
    template <typename StructPtrType>
    StartSessionDetailsPtr StartSessionDetails::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->client = mojo::internal::Clone(client);
        rv->input_method_request = mojo::internal::Clone(input_method_request);
        rv->text_input_type = mojo::internal::Clone(text_input_type);
        rv->text_input_mode = mojo::internal::Clone(text_input_mode);
        rv->text_direction = mojo::internal::Clone(text_direction);
        rv->text_input_flags = mojo::internal::Clone(text_input_flags);
        rv->caret_bounds = mojo::internal::Clone(caret_bounds);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, StartSessionDetails>::value>::type*>
    bool StartSessionDetails::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->client, other.client))
            return false;
        if (!mojo::internal::Equals(this->input_method_request, other.input_method_request))
            return false;
        if (!mojo::internal::Equals(this->text_input_type, other.text_input_type))
            return false;
        if (!mojo::internal::Equals(this->text_input_mode, other.text_input_mode))
            return false;
        if (!mojo::internal::Equals(this->text_direction, other.text_direction))
            return false;
        if (!mojo::internal::Equals(this->text_input_flags, other.text_input_flags))
            return false;
        if (!mojo::internal::Equals(this->caret_bounds, other.caret_bounds))
            return false;
        return true;
    }

} // namespace mojom
} // namespace ui

namespace mojo {

template <>
struct StructTraits<::ui::mojom::CompositionUnderline::DataView,
    ::ui::mojom::CompositionUnderlinePtr> {
    static bool IsNull(const ::ui::mojom::CompositionUnderlinePtr& input) { return !input; }
    static void SetToNull(::ui::mojom::CompositionUnderlinePtr* output) { output->reset(); }

    static decltype(::ui::mojom::CompositionUnderline::start_offset) start_offset(
        const ::ui::mojom::CompositionUnderlinePtr& input)
    {
        return input->start_offset;
    }

    static decltype(::ui::mojom::CompositionUnderline::end_offset) end_offset(
        const ::ui::mojom::CompositionUnderlinePtr& input)
    {
        return input->end_offset;
    }

    static decltype(::ui::mojom::CompositionUnderline::thick) thick(
        const ::ui::mojom::CompositionUnderlinePtr& input)
    {
        return input->thick;
    }

    static decltype(::ui::mojom::CompositionUnderline::color) color(
        const ::ui::mojom::CompositionUnderlinePtr& input)
    {
        return input->color;
    }

    static decltype(::ui::mojom::CompositionUnderline::background_color) background_color(
        const ::ui::mojom::CompositionUnderlinePtr& input)
    {
        return input->background_color;
    }

    static bool Read(::ui::mojom::CompositionUnderline::DataView input, ::ui::mojom::CompositionUnderlinePtr* output);
};

template <>
struct StructTraits<::ui::mojom::CompositionText::DataView,
    ::ui::mojom::CompositionTextPtr> {
    static bool IsNull(const ::ui::mojom::CompositionTextPtr& input) { return !input; }
    static void SetToNull(::ui::mojom::CompositionTextPtr* output) { output->reset(); }

    static const decltype(::ui::mojom::CompositionText::text)& text(
        const ::ui::mojom::CompositionTextPtr& input)
    {
        return input->text;
    }

    static const decltype(::ui::mojom::CompositionText::underlines)& underlines(
        const ::ui::mojom::CompositionTextPtr& input)
    {
        return input->underlines;
    }

    static const decltype(::ui::mojom::CompositionText::selection)& selection(
        const ::ui::mojom::CompositionTextPtr& input)
    {
        return input->selection;
    }

    static bool Read(::ui::mojom::CompositionText::DataView input, ::ui::mojom::CompositionTextPtr* output);
};

template <>
struct StructTraits<::ui::mojom::StartSessionDetails::DataView,
    ::ui::mojom::StartSessionDetailsPtr> {
    static bool IsNull(const ::ui::mojom::StartSessionDetailsPtr& input) { return !input; }
    static void SetToNull(::ui::mojom::StartSessionDetailsPtr* output) { output->reset(); }

    static decltype(::ui::mojom::StartSessionDetails::client)& client(
        ::ui::mojom::StartSessionDetailsPtr& input)
    {
        return input->client;
    }

    static decltype(::ui::mojom::StartSessionDetails::input_method_request)& input_method_request(
        ::ui::mojom::StartSessionDetailsPtr& input)
    {
        return input->input_method_request;
    }

    static decltype(::ui::mojom::StartSessionDetails::text_input_type) text_input_type(
        const ::ui::mojom::StartSessionDetailsPtr& input)
    {
        return input->text_input_type;
    }

    static decltype(::ui::mojom::StartSessionDetails::text_input_mode) text_input_mode(
        const ::ui::mojom::StartSessionDetailsPtr& input)
    {
        return input->text_input_mode;
    }

    static decltype(::ui::mojom::StartSessionDetails::text_direction) text_direction(
        const ::ui::mojom::StartSessionDetailsPtr& input)
    {
        return input->text_direction;
    }

    static decltype(::ui::mojom::StartSessionDetails::text_input_flags) text_input_flags(
        const ::ui::mojom::StartSessionDetailsPtr& input)
    {
        return input->text_input_flags;
    }

    static const decltype(::ui::mojom::StartSessionDetails::caret_bounds)& caret_bounds(
        const ::ui::mojom::StartSessionDetailsPtr& input)
    {
        return input->caret_bounds;
    }

    static bool Read(::ui::mojom::StartSessionDetails::DataView input, ::ui::mojom::StartSessionDetailsPtr* output);
};

} // namespace mojo

#endif // SERVICES_UI_PUBLIC_INTERFACES_IME_IME_MOJOM_H_