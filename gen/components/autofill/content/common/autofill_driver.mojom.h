// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_AUTOFILL_CONTENT_COMMON_AUTOFILL_DRIVER_MOJOM_H_
#define COMPONENTS_AUTOFILL_CONTENT_COMMON_AUTOFILL_DRIVER_MOJOM_H_

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
#include "components/autofill/content/common/autofill_driver.mojom-shared.h"
#include "components/autofill/content/common/autofill_types.mojom.h"
#include "components/autofill/core/common/form_data.h"
#include "components/autofill/core/common/form_data_predictions.h"
#include "components/autofill/core/common/form_field_data.h"
#include "components/autofill/core/common/form_field_data_predictions.h"
#include "components/autofill/core/common/password_form.h"
#include "components/autofill/core/common/password_form_field_prediction_map.h"
#include "components/autofill/core/common/password_form_fill_data.h"
#include "components/autofill/core/common/password_form_generation_data.h"
#include "mojo/common/string16.mojom.h"
#include "mojo/common/text_direction.mojom.h"
#include "mojo/common/time.mojom.h"
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
#include "url/gurl.h"
#include "url/origin.h"
#include <string>
#include <vector>

namespace autofill {
namespace mojom {
    class AutofillDriver;
    using AutofillDriverPtr = mojo::InterfacePtr<AutofillDriver>;
    using AutofillDriverPtrInfo = mojo::InterfacePtrInfo<AutofillDriver>;
    using ThreadSafeAutofillDriverPtr = mojo::ThreadSafeInterfacePtr<AutofillDriver>;
    using AutofillDriverRequest = mojo::InterfaceRequest<AutofillDriver>;
    using AutofillDriverAssociatedPtr = mojo::AssociatedInterfacePtr<AutofillDriver>;
    using ThreadSafeAutofillDriverAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<AutofillDriver>;
    using AutofillDriverAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<AutofillDriver>;
    using AutofillDriverAssociatedRequest = mojo::AssociatedInterfaceRequest<AutofillDriver>;

    class PasswordManagerDriver;
    using PasswordManagerDriverPtr = mojo::InterfacePtr<PasswordManagerDriver>;
    using PasswordManagerDriverPtrInfo = mojo::InterfacePtrInfo<PasswordManagerDriver>;
    using ThreadSafePasswordManagerDriverPtr = mojo::ThreadSafeInterfacePtr<PasswordManagerDriver>;
    using PasswordManagerDriverRequest = mojo::InterfaceRequest<PasswordManagerDriver>;
    using PasswordManagerDriverAssociatedPtr = mojo::AssociatedInterfacePtr<PasswordManagerDriver>;
    using ThreadSafePasswordManagerDriverAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<PasswordManagerDriver>;
    using PasswordManagerDriverAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<PasswordManagerDriver>;
    using PasswordManagerDriverAssociatedRequest = mojo::AssociatedInterfaceRequest<PasswordManagerDriver>;

    class PasswordManagerClient;
    using PasswordManagerClientPtr = mojo::InterfacePtr<PasswordManagerClient>;
    using PasswordManagerClientPtrInfo = mojo::InterfacePtrInfo<PasswordManagerClient>;
    using ThreadSafePasswordManagerClientPtr = mojo::ThreadSafeInterfacePtr<PasswordManagerClient>;
    using PasswordManagerClientRequest = mojo::InterfaceRequest<PasswordManagerClient>;
    using PasswordManagerClientAssociatedPtr = mojo::AssociatedInterfacePtr<PasswordManagerClient>;
    using ThreadSafePasswordManagerClientAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<PasswordManagerClient>;
    using PasswordManagerClientAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<PasswordManagerClient>;
    using PasswordManagerClientAssociatedRequest = mojo::AssociatedInterfaceRequest<PasswordManagerClient>;

    class AutofillDriverProxy;

    template <typename ImplRefTraits>
    class AutofillDriverStub;

    class AutofillDriverRequestValidator;

    class AutofillDriver
        : public AutofillDriverInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = AutofillDriverProxy;

        template <typename ImplRefTraits>
        using Stub_ = AutofillDriverStub<ImplRefTraits>;

        using RequestValidator_ = AutofillDriverRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kFirstUserGestureObservedMinVersion = 0,
            kFormsSeenMinVersion = 0,
            kWillSubmitFormMinVersion = 0,
            kFormSubmittedMinVersion = 0,
            kTextFieldDidChangeMinVersion = 0,
            kQueryFormFieldAutofillMinVersion = 0,
            kHidePopupMinVersion = 0,
            kFocusNoLongerOnFormMinVersion = 0,
            kDidFillAutofillFormDataMinVersion = 0,
            kDidPreviewAutofillFormDataMinVersion = 0,
            kDidEndTextFieldEditingMinVersion = 0,
            kSetDataListMinVersion = 0,
        };
        virtual ~AutofillDriver() { }

        virtual void FirstUserGestureObserved() = 0;

        virtual void FormsSeen(const std::vector<autofill::FormData>& forms, base::TimeTicks timestamp) = 0;

        virtual void WillSubmitForm(const autofill::FormData& form, base::TimeTicks timestamp) = 0;

        virtual void FormSubmitted(const autofill::FormData& form) = 0;

        virtual void TextFieldDidChange(const autofill::FormData& form, const autofill::FormFieldData& field, base::TimeTicks timestamp) = 0;

        virtual void QueryFormFieldAutofill(int32_t id, const autofill::FormData& form, const autofill::FormFieldData& field, const gfx::RectF& bounding_box) = 0;

        virtual void HidePopup() = 0;

        virtual void FocusNoLongerOnForm() = 0;

        virtual void DidFillAutofillFormData(const autofill::FormData& form, base::TimeTicks timestamp) = 0;

        virtual void DidPreviewAutofillFormData() = 0;

        virtual void DidEndTextFieldEditing() = 0;

        virtual void SetDataList(const std::vector<base::string16>& values, const std::vector<base::string16>& labels) = 0;
    };

    class PasswordManagerDriverProxy;

    template <typename ImplRefTraits>
    class PasswordManagerDriverStub;

    class PasswordManagerDriverRequestValidator;

    class PasswordManagerDriver
        : public PasswordManagerDriverInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = PasswordManagerDriverProxy;

        template <typename ImplRefTraits>
        using Stub_ = PasswordManagerDriverStub<ImplRefTraits>;

        using RequestValidator_ = PasswordManagerDriverRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kPasswordFormsParsedMinVersion = 0,
            kPasswordFormsRenderedMinVersion = 0,
            kPasswordFormSubmittedMinVersion = 0,
            kInPageNavigationMinVersion = 0,
            kRecordSavePasswordProgressMinVersion = 0,
            kShowPasswordSuggestionsMinVersion = 0,
            kShowNotSecureWarningMinVersion = 0,
            kPresaveGeneratedPasswordMinVersion = 0,
            kPasswordNoLongerGeneratedMinVersion = 0,
            kSaveGenerationFieldDetectedByClassifierMinVersion = 0,
        };
        virtual ~PasswordManagerDriver() { }

        virtual void PasswordFormsParsed(const std::vector<autofill::PasswordForm>& forms) = 0;

        virtual void PasswordFormsRendered(const std::vector<autofill::PasswordForm>& visible_forms, bool did_stop_loading) = 0;

        virtual void PasswordFormSubmitted(const autofill::PasswordForm& password_form) = 0;

        virtual void InPageNavigation(const autofill::PasswordForm& password_form) = 0;

        virtual void RecordSavePasswordProgress(const std::string& log) = 0;

        virtual void ShowPasswordSuggestions(int32_t key, base::i18n::TextDirection text_direction, const base::string16& typed_username, int32_t options, const gfx::RectF& bounds) = 0;

        virtual void ShowNotSecureWarning(base::i18n::TextDirection text_direction, const gfx::RectF& bounds) = 0;

        virtual void PresaveGeneratedPassword(const autofill::PasswordForm& password_form) = 0;

        virtual void PasswordNoLongerGenerated(const autofill::PasswordForm& password_form) = 0;

        virtual void SaveGenerationFieldDetectedByClassifier(const autofill::PasswordForm& password_form, const base::string16& generation_field) = 0;
    };

    class PasswordManagerClientProxy;

    template <typename ImplRefTraits>
    class PasswordManagerClientStub;

    class PasswordManagerClientRequestValidator;

    class PasswordManagerClient
        : public PasswordManagerClientInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = PasswordManagerClientProxy;

        template <typename ImplRefTraits>
        using Stub_ = PasswordManagerClientStub<ImplRefTraits>;

        using RequestValidator_ = PasswordManagerClientRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kGenerationAvailableForFormMinVersion = 0,
            kShowPasswordGenerationPopupMinVersion = 0,
            kShowPasswordEditingPopupMinVersion = 0,
            kHidePasswordGenerationPopupMinVersion = 0,
        };
        virtual ~PasswordManagerClient() { }

        virtual void GenerationAvailableForForm(const autofill::PasswordForm& password_form) = 0;

        virtual void ShowPasswordGenerationPopup(const gfx::RectF& bounds, int32_t max_length, const base::string16& generation_element, bool is_manually_triggered, const autofill::PasswordForm& password_form) = 0;

        virtual void ShowPasswordEditingPopup(const gfx::RectF& bounds, const autofill::PasswordForm& password_form) = 0;

        virtual void HidePasswordGenerationPopup() = 0;
    };

    class AutofillDriverProxy
        : public AutofillDriver {
    public:
        explicit AutofillDriverProxy(mojo::MessageReceiverWithResponder* receiver);
        void FirstUserGestureObserved() override;
        void FormsSeen(const std::vector<autofill::FormData>& forms, base::TimeTicks timestamp) override;
        void WillSubmitForm(const autofill::FormData& form, base::TimeTicks timestamp) override;
        void FormSubmitted(const autofill::FormData& form) override;
        void TextFieldDidChange(const autofill::FormData& form, const autofill::FormFieldData& field, base::TimeTicks timestamp) override;
        void QueryFormFieldAutofill(int32_t id, const autofill::FormData& form, const autofill::FormFieldData& field, const gfx::RectF& bounding_box) override;
        void HidePopup() override;
        void FocusNoLongerOnForm() override;
        void DidFillAutofillFormData(const autofill::FormData& form, base::TimeTicks timestamp) override;
        void DidPreviewAutofillFormData() override;
        void DidEndTextFieldEditing() override;
        void SetDataList(const std::vector<base::string16>& values, const std::vector<base::string16>& labels) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class PasswordManagerDriverProxy
        : public PasswordManagerDriver {
    public:
        explicit PasswordManagerDriverProxy(mojo::MessageReceiverWithResponder* receiver);
        void PasswordFormsParsed(const std::vector<autofill::PasswordForm>& forms) override;
        void PasswordFormsRendered(const std::vector<autofill::PasswordForm>& visible_forms, bool did_stop_loading) override;
        void PasswordFormSubmitted(const autofill::PasswordForm& password_form) override;
        void InPageNavigation(const autofill::PasswordForm& password_form) override;
        void RecordSavePasswordProgress(const std::string& log) override;
        void ShowPasswordSuggestions(int32_t key, base::i18n::TextDirection text_direction, const base::string16& typed_username, int32_t options, const gfx::RectF& bounds) override;
        void ShowNotSecureWarning(base::i18n::TextDirection text_direction, const gfx::RectF& bounds) override;
        void PresaveGeneratedPassword(const autofill::PasswordForm& password_form) override;
        void PasswordNoLongerGenerated(const autofill::PasswordForm& password_form) override;
        void SaveGenerationFieldDetectedByClassifier(const autofill::PasswordForm& password_form, const base::string16& generation_field) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class PasswordManagerClientProxy
        : public PasswordManagerClient {
    public:
        explicit PasswordManagerClientProxy(mojo::MessageReceiverWithResponder* receiver);
        void GenerationAvailableForForm(const autofill::PasswordForm& password_form) override;
        void ShowPasswordGenerationPopup(const gfx::RectF& bounds, int32_t max_length, const base::string16& generation_element, bool is_manually_triggered, const autofill::PasswordForm& password_form) override;
        void ShowPasswordEditingPopup(const gfx::RectF& bounds, const autofill::PasswordForm& password_form) override;
        void HidePasswordGenerationPopup() override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class AutofillDriverStubDispatch {
    public:
        static bool Accept(AutofillDriver* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(AutofillDriver* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<AutofillDriver>>
    class AutofillDriverStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        AutofillDriverStub() { }
        ~AutofillDriverStub() override { }

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
            return AutofillDriverStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return AutofillDriverStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class PasswordManagerDriverStubDispatch {
    public:
        static bool Accept(PasswordManagerDriver* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(PasswordManagerDriver* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<PasswordManagerDriver>>
    class PasswordManagerDriverStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        PasswordManagerDriverStub() { }
        ~PasswordManagerDriverStub() override { }

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
            return PasswordManagerDriverStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return PasswordManagerDriverStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class PasswordManagerClientStubDispatch {
    public:
        static bool Accept(PasswordManagerClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(PasswordManagerClient* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<PasswordManagerClient>>
    class PasswordManagerClientStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        PasswordManagerClientStub() { }
        ~PasswordManagerClientStub() override { }

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
            return PasswordManagerClientStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return PasswordManagerClientStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class AutofillDriverRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class PasswordManagerDriverRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class PasswordManagerClientRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

} // namespace mojom
} // namespace autofill

namespace mojo {

} // namespace mojo

#endif // COMPONENTS_AUTOFILL_CONTENT_COMMON_AUTOFILL_DRIVER_MOJOM_H_