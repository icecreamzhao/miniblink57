// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_AUTOFILL_CONTENT_COMMON_AUTOFILL_AGENT_MOJOM_H_
#define COMPONENTS_AUTOFILL_CONTENT_COMMON_AUTOFILL_AGENT_MOJOM_H_

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
#include "components/autofill/content/common/autofill_agent.mojom-shared.h"
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
    class AutofillAgent;
    using AutofillAgentPtr = mojo::InterfacePtr<AutofillAgent>;
    using AutofillAgentPtrInfo = mojo::InterfacePtrInfo<AutofillAgent>;
    using ThreadSafeAutofillAgentPtr = mojo::ThreadSafeInterfacePtr<AutofillAgent>;
    using AutofillAgentRequest = mojo::InterfaceRequest<AutofillAgent>;
    using AutofillAgentAssociatedPtr = mojo::AssociatedInterfacePtr<AutofillAgent>;
    using ThreadSafeAutofillAgentAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<AutofillAgent>;
    using AutofillAgentAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<AutofillAgent>;
    using AutofillAgentAssociatedRequest = mojo::AssociatedInterfaceRequest<AutofillAgent>;

    class PasswordAutofillAgent;
    using PasswordAutofillAgentPtr = mojo::InterfacePtr<PasswordAutofillAgent>;
    using PasswordAutofillAgentPtrInfo = mojo::InterfacePtrInfo<PasswordAutofillAgent>;
    using ThreadSafePasswordAutofillAgentPtr = mojo::ThreadSafeInterfacePtr<PasswordAutofillAgent>;
    using PasswordAutofillAgentRequest = mojo::InterfaceRequest<PasswordAutofillAgent>;
    using PasswordAutofillAgentAssociatedPtr = mojo::AssociatedInterfacePtr<PasswordAutofillAgent>;
    using ThreadSafePasswordAutofillAgentAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<PasswordAutofillAgent>;
    using PasswordAutofillAgentAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<PasswordAutofillAgent>;
    using PasswordAutofillAgentAssociatedRequest = mojo::AssociatedInterfaceRequest<PasswordAutofillAgent>;

    class PasswordGenerationAgent;
    using PasswordGenerationAgentPtr = mojo::InterfacePtr<PasswordGenerationAgent>;
    using PasswordGenerationAgentPtrInfo = mojo::InterfacePtrInfo<PasswordGenerationAgent>;
    using ThreadSafePasswordGenerationAgentPtr = mojo::ThreadSafeInterfacePtr<PasswordGenerationAgent>;
    using PasswordGenerationAgentRequest = mojo::InterfaceRequest<PasswordGenerationAgent>;
    using PasswordGenerationAgentAssociatedPtr = mojo::AssociatedInterfacePtr<PasswordGenerationAgent>;
    using ThreadSafePasswordGenerationAgentAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<PasswordGenerationAgent>;
    using PasswordGenerationAgentAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<PasswordGenerationAgent>;
    using PasswordGenerationAgentAssociatedRequest = mojo::AssociatedInterfaceRequest<PasswordGenerationAgent>;

    class AutofillAgentProxy;

    template <typename ImplRefTraits>
    class AutofillAgentStub;

    class AutofillAgentRequestValidator;

    class AutofillAgent
        : public AutofillAgentInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = AutofillAgentProxy;

        template <typename ImplRefTraits>
        using Stub_ = AutofillAgentStub<ImplRefTraits>;

        using RequestValidator_ = AutofillAgentRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kFirstUserGestureObservedInTabMinVersion = 0,
            kFillFormMinVersion = 0,
            kPreviewFormMinVersion = 0,
            kFieldTypePredictionsAvailableMinVersion = 0,
            kClearFormMinVersion = 0,
            kClearPreviewedFormMinVersion = 0,
            kFillFieldWithValueMinVersion = 0,
            kPreviewFieldWithValueMinVersion = 0,
            kAcceptDataListSuggestionMinVersion = 0,
            kFillPasswordSuggestionMinVersion = 0,
            kPreviewPasswordSuggestionMinVersion = 0,
            kShowInitialPasswordAccountSuggestionsMinVersion = 0,
        };
        virtual ~AutofillAgent() { }

        virtual void FirstUserGestureObservedInTab() = 0;

        virtual void FillForm(int32_t id, const autofill::FormData& form) = 0;

        virtual void PreviewForm(int32_t id, const autofill::FormData& form) = 0;

        virtual void FieldTypePredictionsAvailable(const std::vector<autofill::FormDataPredictions>& forms) = 0;

        virtual void ClearForm() = 0;

        virtual void ClearPreviewedForm() = 0;

        virtual void FillFieldWithValue(const base::string16& value) = 0;

        virtual void PreviewFieldWithValue(const base::string16& value) = 0;

        virtual void AcceptDataListSuggestion(const base::string16& value) = 0;

        virtual void FillPasswordSuggestion(const base::string16& username, const base::string16& password) = 0;

        virtual void PreviewPasswordSuggestion(const base::string16& username, const base::string16& password) = 0;

        virtual void ShowInitialPasswordAccountSuggestions(int32_t key, const autofill::PasswordFormFillData& form_data) = 0;
    };

    class PasswordAutofillAgentProxy;

    template <typename ImplRefTraits>
    class PasswordAutofillAgentStub;

    class PasswordAutofillAgentRequestValidator;
    class PasswordAutofillAgentResponseValidator;

    class PasswordAutofillAgent
        : public PasswordAutofillAgentInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = PasswordAutofillAgentProxy;

        template <typename ImplRefTraits>
        using Stub_ = PasswordAutofillAgentStub<ImplRefTraits>;

        using RequestValidator_ = PasswordAutofillAgentRequestValidator;
        using ResponseValidator_ = PasswordAutofillAgentResponseValidator;
        enum MethodMinVersions : uint32_t {
            kFillPasswordFormMinVersion = 0,
            kSetLoggingStateMinVersion = 0,
            kAutofillUsernameAndPasswordDataReceivedMinVersion = 0,
            kFindFocusedPasswordFormMinVersion = 0,
        };
        virtual ~PasswordAutofillAgent() { }

        virtual void FillPasswordForm(int32_t key, const autofill::PasswordFormFillData& form_data) = 0;

        virtual void SetLoggingState(bool active) = 0;

        virtual void AutofillUsernameAndPasswordDataReceived(const autofill::FormsPredictionsMap& predictions) = 0;

        using FindFocusedPasswordFormCallback = base::Callback<void(const autofill::PasswordForm&)>;
        virtual void FindFocusedPasswordForm(const FindFocusedPasswordFormCallback& callback) = 0;
    };

    class PasswordGenerationAgentProxy;

    template <typename ImplRefTraits>
    class PasswordGenerationAgentStub;

    class PasswordGenerationAgentRequestValidator;

    class PasswordGenerationAgent
        : public PasswordGenerationAgentInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = PasswordGenerationAgentProxy;

        template <typename ImplRefTraits>
        using Stub_ = PasswordGenerationAgentStub<ImplRefTraits>;

        using RequestValidator_ = PasswordGenerationAgentRequestValidator;
        using ResponseValidator_ = mojo::PassThroughFilter;
        enum MethodMinVersions : uint32_t {
            kGeneratedPasswordAcceptedMinVersion = 0,
            kUserTriggeredGeneratePasswordMinVersion = 0,
            kFormNotBlacklistedMinVersion = 0,
            kFoundFormsEligibleForGenerationMinVersion = 0,
            kAllowToRunFormClassifierMinVersion = 0,
        };
        virtual ~PasswordGenerationAgent() { }

        virtual void GeneratedPasswordAccepted(const base::string16& generated_password) = 0;

        virtual void UserTriggeredGeneratePassword() = 0;

        virtual void FormNotBlacklisted(const autofill::PasswordForm& form) = 0;

        virtual void FoundFormsEligibleForGeneration(const std::vector<autofill::PasswordFormGenerationData>& forms) = 0;

        virtual void AllowToRunFormClassifier() = 0;
    };

    class AutofillAgentProxy
        : public AutofillAgent {
    public:
        explicit AutofillAgentProxy(mojo::MessageReceiverWithResponder* receiver);
        void FirstUserGestureObservedInTab() override;
        void FillForm(int32_t id, const autofill::FormData& form) override;
        void PreviewForm(int32_t id, const autofill::FormData& form) override;
        void FieldTypePredictionsAvailable(const std::vector<autofill::FormDataPredictions>& forms) override;
        void ClearForm() override;
        void ClearPreviewedForm() override;
        void FillFieldWithValue(const base::string16& value) override;
        void PreviewFieldWithValue(const base::string16& value) override;
        void AcceptDataListSuggestion(const base::string16& value) override;
        void FillPasswordSuggestion(const base::string16& username, const base::string16& password) override;
        void PreviewPasswordSuggestion(const base::string16& username, const base::string16& password) override;
        void ShowInitialPasswordAccountSuggestions(int32_t key, const autofill::PasswordFormFillData& form_data) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class PasswordAutofillAgentProxy
        : public PasswordAutofillAgent {
    public:
        explicit PasswordAutofillAgentProxy(mojo::MessageReceiverWithResponder* receiver);
        void FillPasswordForm(int32_t key, const autofill::PasswordFormFillData& form_data) override;
        void SetLoggingState(bool active) override;
        void AutofillUsernameAndPasswordDataReceived(const autofill::FormsPredictionsMap& predictions) override;
        void FindFocusedPasswordForm(const FindFocusedPasswordFormCallback& callback) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class PasswordGenerationAgentProxy
        : public PasswordGenerationAgent {
    public:
        explicit PasswordGenerationAgentProxy(mojo::MessageReceiverWithResponder* receiver);
        void GeneratedPasswordAccepted(const base::string16& generated_password) override;
        void UserTriggeredGeneratePassword() override;
        void FormNotBlacklisted(const autofill::PasswordForm& form) override;
        void FoundFormsEligibleForGeneration(const std::vector<autofill::PasswordFormGenerationData>& forms) override;
        void AllowToRunFormClassifier() override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class AutofillAgentStubDispatch {
    public:
        static bool Accept(AutofillAgent* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(AutofillAgent* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<AutofillAgent>>
    class AutofillAgentStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        AutofillAgentStub() { }
        ~AutofillAgentStub() override { }

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
            return AutofillAgentStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return AutofillAgentStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class PasswordAutofillAgentStubDispatch {
    public:
        static bool Accept(PasswordAutofillAgent* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(PasswordAutofillAgent* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<PasswordAutofillAgent>>
    class PasswordAutofillAgentStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        PasswordAutofillAgentStub() { }
        ~PasswordAutofillAgentStub() override { }

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
            return PasswordAutofillAgentStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return PasswordAutofillAgentStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class PasswordGenerationAgentStubDispatch {
    public:
        static bool Accept(PasswordGenerationAgent* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(PasswordGenerationAgent* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<PasswordGenerationAgent>>
    class PasswordGenerationAgentStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        PasswordGenerationAgentStub() { }
        ~PasswordGenerationAgentStub() override { }

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
            return PasswordGenerationAgentStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return PasswordGenerationAgentStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class AutofillAgentRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class PasswordAutofillAgentRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class PasswordGenerationAgentRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class PasswordAutofillAgentResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

} // namespace mojom
} // namespace autofill

namespace mojo {

} // namespace mojo

#endif // COMPONENTS_AUTOFILL_CONTENT_COMMON_AUTOFILL_AGENT_MOJOM_H_