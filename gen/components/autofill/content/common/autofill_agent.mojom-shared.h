// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_AUTOFILL_CONTENT_COMMON_AUTOFILL_AGENT_MOJOM_SHARED_H_
#define COMPONENTS_AUTOFILL_CONTENT_COMMON_AUTOFILL_AGENT_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "components/autofill/content/common/autofill_agent.mojom-shared-internal.h"
#include "components/autofill/content/common/autofill_types.mojom-shared.h"
#include "mojo/common/string16.mojom-shared.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"

namespace autofill {
namespace mojom {

} // namespace mojom
} // namespace autofill

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace autofill {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class AutofillAgentInterfaceBase {
    };

    using AutofillAgentPtrDataView = mojo::InterfacePtrDataView<AutofillAgentInterfaceBase>;
    using AutofillAgentRequestDataView = mojo::InterfaceRequestDataView<AutofillAgentInterfaceBase>;
    using AutofillAgentAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<AutofillAgentInterfaceBase>;
    using AutofillAgentAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<AutofillAgentInterfaceBase>;
    class PasswordAutofillAgentInterfaceBase {
    };

    using PasswordAutofillAgentPtrDataView = mojo::InterfacePtrDataView<PasswordAutofillAgentInterfaceBase>;
    using PasswordAutofillAgentRequestDataView = mojo::InterfaceRequestDataView<PasswordAutofillAgentInterfaceBase>;
    using PasswordAutofillAgentAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<PasswordAutofillAgentInterfaceBase>;
    using PasswordAutofillAgentAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<PasswordAutofillAgentInterfaceBase>;
    class PasswordGenerationAgentInterfaceBase {
    };

    using PasswordGenerationAgentPtrDataView = mojo::InterfacePtrDataView<PasswordGenerationAgentInterfaceBase>;
    using PasswordGenerationAgentRequestDataView = mojo::InterfaceRequestDataView<PasswordGenerationAgentInterfaceBase>;
    using PasswordGenerationAgentAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<PasswordGenerationAgentInterfaceBase>;
    using PasswordGenerationAgentAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<PasswordGenerationAgentInterfaceBase>;
    class AutofillAgent_FirstUserGestureObservedInTab_ParamsDataView {
    public:
        AutofillAgent_FirstUserGestureObservedInTab_ParamsDataView() { }

        AutofillAgent_FirstUserGestureObservedInTab_ParamsDataView(
            internal::AutofillAgent_FirstUserGestureObservedInTab_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::AutofillAgent_FirstUserGestureObservedInTab_Params_Data* data_ = nullptr;
    };

    class AutofillAgent_FillForm_ParamsDataView {
    public:
        AutofillAgent_FillForm_ParamsDataView() { }

        AutofillAgent_FillForm_ParamsDataView(
            internal::AutofillAgent_FillForm_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        int32_t id() const
        {
            return data_->id;
        }
        inline void GetFormDataView(
            ::autofill::mojom::FormDataDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadForm(UserType* output)
        {
            auto* pointer = data_->form.Get();
            return mojo::internal::Deserialize<::autofill::mojom::FormDataDataView>(
                pointer, output, context_);
        }

    private:
        internal::AutofillAgent_FillForm_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class AutofillAgent_PreviewForm_ParamsDataView {
    public:
        AutofillAgent_PreviewForm_ParamsDataView() { }

        AutofillAgent_PreviewForm_ParamsDataView(
            internal::AutofillAgent_PreviewForm_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        int32_t id() const
        {
            return data_->id;
        }
        inline void GetFormDataView(
            ::autofill::mojom::FormDataDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadForm(UserType* output)
        {
            auto* pointer = data_->form.Get();
            return mojo::internal::Deserialize<::autofill::mojom::FormDataDataView>(
                pointer, output, context_);
        }

    private:
        internal::AutofillAgent_PreviewForm_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class AutofillAgent_FieldTypePredictionsAvailable_ParamsDataView {
    public:
        AutofillAgent_FieldTypePredictionsAvailable_ParamsDataView() { }

        AutofillAgent_FieldTypePredictionsAvailable_ParamsDataView(
            internal::AutofillAgent_FieldTypePredictionsAvailable_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetFormsDataView(
            mojo::ArrayDataView<::autofill::mojom::FormDataPredictionsDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadForms(UserType* output)
        {
            auto* pointer = data_->forms.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::autofill::mojom::FormDataPredictionsDataView>>(
                pointer, output, context_);
        }

    private:
        internal::AutofillAgent_FieldTypePredictionsAvailable_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class AutofillAgent_ClearForm_ParamsDataView {
    public:
        AutofillAgent_ClearForm_ParamsDataView() { }

        AutofillAgent_ClearForm_ParamsDataView(
            internal::AutofillAgent_ClearForm_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::AutofillAgent_ClearForm_Params_Data* data_ = nullptr;
    };

    class AutofillAgent_ClearPreviewedForm_ParamsDataView {
    public:
        AutofillAgent_ClearPreviewedForm_ParamsDataView() { }

        AutofillAgent_ClearPreviewedForm_ParamsDataView(
            internal::AutofillAgent_ClearPreviewedForm_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::AutofillAgent_ClearPreviewedForm_Params_Data* data_ = nullptr;
    };

    class AutofillAgent_FillFieldWithValue_ParamsDataView {
    public:
        AutofillAgent_FillFieldWithValue_ParamsDataView() { }

        AutofillAgent_FillFieldWithValue_ParamsDataView(
            internal::AutofillAgent_FillFieldWithValue_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetValueDataView(
            ::mojo::common::mojom::String16DataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadValue(UserType* output)
        {
            auto* pointer = data_->value.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::String16DataView>(
                pointer, output, context_);
        }

    private:
        internal::AutofillAgent_FillFieldWithValue_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class AutofillAgent_PreviewFieldWithValue_ParamsDataView {
    public:
        AutofillAgent_PreviewFieldWithValue_ParamsDataView() { }

        AutofillAgent_PreviewFieldWithValue_ParamsDataView(
            internal::AutofillAgent_PreviewFieldWithValue_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetValueDataView(
            ::mojo::common::mojom::String16DataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadValue(UserType* output)
        {
            auto* pointer = data_->value.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::String16DataView>(
                pointer, output, context_);
        }

    private:
        internal::AutofillAgent_PreviewFieldWithValue_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class AutofillAgent_AcceptDataListSuggestion_ParamsDataView {
    public:
        AutofillAgent_AcceptDataListSuggestion_ParamsDataView() { }

        AutofillAgent_AcceptDataListSuggestion_ParamsDataView(
            internal::AutofillAgent_AcceptDataListSuggestion_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetValueDataView(
            ::mojo::common::mojom::String16DataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadValue(UserType* output)
        {
            auto* pointer = data_->value.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::String16DataView>(
                pointer, output, context_);
        }

    private:
        internal::AutofillAgent_AcceptDataListSuggestion_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class AutofillAgent_FillPasswordSuggestion_ParamsDataView {
    public:
        AutofillAgent_FillPasswordSuggestion_ParamsDataView() { }

        AutofillAgent_FillPasswordSuggestion_ParamsDataView(
            internal::AutofillAgent_FillPasswordSuggestion_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetUsernameDataView(
            ::mojo::common::mojom::String16DataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadUsername(UserType* output)
        {
            auto* pointer = data_->username.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::String16DataView>(
                pointer, output, context_);
        }
        inline void GetPasswordDataView(
            ::mojo::common::mojom::String16DataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPassword(UserType* output)
        {
            auto* pointer = data_->password.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::String16DataView>(
                pointer, output, context_);
        }

    private:
        internal::AutofillAgent_FillPasswordSuggestion_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class AutofillAgent_PreviewPasswordSuggestion_ParamsDataView {
    public:
        AutofillAgent_PreviewPasswordSuggestion_ParamsDataView() { }

        AutofillAgent_PreviewPasswordSuggestion_ParamsDataView(
            internal::AutofillAgent_PreviewPasswordSuggestion_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetUsernameDataView(
            ::mojo::common::mojom::String16DataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadUsername(UserType* output)
        {
            auto* pointer = data_->username.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::String16DataView>(
                pointer, output, context_);
        }
        inline void GetPasswordDataView(
            ::mojo::common::mojom::String16DataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPassword(UserType* output)
        {
            auto* pointer = data_->password.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::String16DataView>(
                pointer, output, context_);
        }

    private:
        internal::AutofillAgent_PreviewPasswordSuggestion_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class AutofillAgent_ShowInitialPasswordAccountSuggestions_ParamsDataView {
    public:
        AutofillAgent_ShowInitialPasswordAccountSuggestions_ParamsDataView() { }

        AutofillAgent_ShowInitialPasswordAccountSuggestions_ParamsDataView(
            internal::AutofillAgent_ShowInitialPasswordAccountSuggestions_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        int32_t key() const
        {
            return data_->key;
        }
        inline void GetFormDataDataView(
            ::autofill::mojom::PasswordFormFillDataDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFormData(UserType* output)
        {
            auto* pointer = data_->form_data.Get();
            return mojo::internal::Deserialize<::autofill::mojom::PasswordFormFillDataDataView>(
                pointer, output, context_);
        }

    private:
        internal::AutofillAgent_ShowInitialPasswordAccountSuggestions_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PasswordAutofillAgent_FillPasswordForm_ParamsDataView {
    public:
        PasswordAutofillAgent_FillPasswordForm_ParamsDataView() { }

        PasswordAutofillAgent_FillPasswordForm_ParamsDataView(
            internal::PasswordAutofillAgent_FillPasswordForm_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        int32_t key() const
        {
            return data_->key;
        }
        inline void GetFormDataDataView(
            ::autofill::mojom::PasswordFormFillDataDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFormData(UserType* output)
        {
            auto* pointer = data_->form_data.Get();
            return mojo::internal::Deserialize<::autofill::mojom::PasswordFormFillDataDataView>(
                pointer, output, context_);
        }

    private:
        internal::PasswordAutofillAgent_FillPasswordForm_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PasswordAutofillAgent_SetLoggingState_ParamsDataView {
    public:
        PasswordAutofillAgent_SetLoggingState_ParamsDataView() { }

        PasswordAutofillAgent_SetLoggingState_ParamsDataView(
            internal::PasswordAutofillAgent_SetLoggingState_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        bool active() const
        {
            return data_->active;
        }

    private:
        internal::PasswordAutofillAgent_SetLoggingState_Params_Data* data_ = nullptr;
    };

    class PasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_ParamsDataView {
    public:
        PasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_ParamsDataView() { }

        PasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_ParamsDataView(
            internal::PasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetPredictionsDataView(
            ::autofill::mojom::FormsPredictionsMapDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPredictions(UserType* output)
        {
            auto* pointer = data_->predictions.Get();
            return mojo::internal::Deserialize<::autofill::mojom::FormsPredictionsMapDataView>(
                pointer, output, context_);
        }

    private:
        internal::PasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PasswordAutofillAgent_FindFocusedPasswordForm_ParamsDataView {
    public:
        PasswordAutofillAgent_FindFocusedPasswordForm_ParamsDataView() { }

        PasswordAutofillAgent_FindFocusedPasswordForm_ParamsDataView(
            internal::PasswordAutofillAgent_FindFocusedPasswordForm_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::PasswordAutofillAgent_FindFocusedPasswordForm_Params_Data* data_ = nullptr;
    };

    class PasswordAutofillAgent_FindFocusedPasswordForm_ResponseParamsDataView {
    public:
        PasswordAutofillAgent_FindFocusedPasswordForm_ResponseParamsDataView() { }

        PasswordAutofillAgent_FindFocusedPasswordForm_ResponseParamsDataView(
            internal::PasswordAutofillAgent_FindFocusedPasswordForm_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetFormDataView(
            ::autofill::mojom::PasswordFormDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadForm(UserType* output)
        {
            auto* pointer = data_->form.Get();
            return mojo::internal::Deserialize<::autofill::mojom::PasswordFormDataView>(
                pointer, output, context_);
        }

    private:
        internal::PasswordAutofillAgent_FindFocusedPasswordForm_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PasswordGenerationAgent_GeneratedPasswordAccepted_ParamsDataView {
    public:
        PasswordGenerationAgent_GeneratedPasswordAccepted_ParamsDataView() { }

        PasswordGenerationAgent_GeneratedPasswordAccepted_ParamsDataView(
            internal::PasswordGenerationAgent_GeneratedPasswordAccepted_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetGeneratedPasswordDataView(
            ::mojo::common::mojom::String16DataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadGeneratedPassword(UserType* output)
        {
            auto* pointer = data_->generated_password.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::String16DataView>(
                pointer, output, context_);
        }

    private:
        internal::PasswordGenerationAgent_GeneratedPasswordAccepted_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PasswordGenerationAgent_UserTriggeredGeneratePassword_ParamsDataView {
    public:
        PasswordGenerationAgent_UserTriggeredGeneratePassword_ParamsDataView() { }

        PasswordGenerationAgent_UserTriggeredGeneratePassword_ParamsDataView(
            internal::PasswordGenerationAgent_UserTriggeredGeneratePassword_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::PasswordGenerationAgent_UserTriggeredGeneratePassword_Params_Data* data_ = nullptr;
    };

    class PasswordGenerationAgent_FormNotBlacklisted_ParamsDataView {
    public:
        PasswordGenerationAgent_FormNotBlacklisted_ParamsDataView() { }

        PasswordGenerationAgent_FormNotBlacklisted_ParamsDataView(
            internal::PasswordGenerationAgent_FormNotBlacklisted_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetFormDataView(
            ::autofill::mojom::PasswordFormDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadForm(UserType* output)
        {
            auto* pointer = data_->form.Get();
            return mojo::internal::Deserialize<::autofill::mojom::PasswordFormDataView>(
                pointer, output, context_);
        }

    private:
        internal::PasswordGenerationAgent_FormNotBlacklisted_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PasswordGenerationAgent_FoundFormsEligibleForGeneration_ParamsDataView {
    public:
        PasswordGenerationAgent_FoundFormsEligibleForGeneration_ParamsDataView() { }

        PasswordGenerationAgent_FoundFormsEligibleForGeneration_ParamsDataView(
            internal::PasswordGenerationAgent_FoundFormsEligibleForGeneration_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetFormsDataView(
            mojo::ArrayDataView<::autofill::mojom::PasswordFormGenerationDataDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadForms(UserType* output)
        {
            auto* pointer = data_->forms.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::autofill::mojom::PasswordFormGenerationDataDataView>>(
                pointer, output, context_);
        }

    private:
        internal::PasswordGenerationAgent_FoundFormsEligibleForGeneration_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PasswordGenerationAgent_AllowToRunFormClassifier_ParamsDataView {
    public:
        PasswordGenerationAgent_AllowToRunFormClassifier_ParamsDataView() { }

        PasswordGenerationAgent_AllowToRunFormClassifier_ParamsDataView(
            internal::PasswordGenerationAgent_AllowToRunFormClassifier_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::PasswordGenerationAgent_AllowToRunFormClassifier_Params_Data* data_ = nullptr;
    };

} // namespace mojom
} // namespace autofill

namespace std {

} // namespace std

namespace mojo {

} // namespace mojo

namespace autofill {
namespace mojom {

    inline void AutofillAgent_FillForm_ParamsDataView::GetFormDataView(
        ::autofill::mojom::FormDataDataView* output)
    {
        auto pointer = data_->form.Get();
        *output = ::autofill::mojom::FormDataDataView(pointer, context_);
    }

    inline void AutofillAgent_PreviewForm_ParamsDataView::GetFormDataView(
        ::autofill::mojom::FormDataDataView* output)
    {
        auto pointer = data_->form.Get();
        *output = ::autofill::mojom::FormDataDataView(pointer, context_);
    }

    inline void AutofillAgent_FieldTypePredictionsAvailable_ParamsDataView::GetFormsDataView(
        mojo::ArrayDataView<::autofill::mojom::FormDataPredictionsDataView>* output)
    {
        auto pointer = data_->forms.Get();
        *output = mojo::ArrayDataView<::autofill::mojom::FormDataPredictionsDataView>(pointer, context_);
    }

    inline void AutofillAgent_FillFieldWithValue_ParamsDataView::GetValueDataView(
        ::mojo::common::mojom::String16DataView* output)
    {
        auto pointer = data_->value.Get();
        *output = ::mojo::common::mojom::String16DataView(pointer, context_);
    }

    inline void AutofillAgent_PreviewFieldWithValue_ParamsDataView::GetValueDataView(
        ::mojo::common::mojom::String16DataView* output)
    {
        auto pointer = data_->value.Get();
        *output = ::mojo::common::mojom::String16DataView(pointer, context_);
    }

    inline void AutofillAgent_AcceptDataListSuggestion_ParamsDataView::GetValueDataView(
        ::mojo::common::mojom::String16DataView* output)
    {
        auto pointer = data_->value.Get();
        *output = ::mojo::common::mojom::String16DataView(pointer, context_);
    }

    inline void AutofillAgent_FillPasswordSuggestion_ParamsDataView::GetUsernameDataView(
        ::mojo::common::mojom::String16DataView* output)
    {
        auto pointer = data_->username.Get();
        *output = ::mojo::common::mojom::String16DataView(pointer, context_);
    }
    inline void AutofillAgent_FillPasswordSuggestion_ParamsDataView::GetPasswordDataView(
        ::mojo::common::mojom::String16DataView* output)
    {
        auto pointer = data_->password.Get();
        *output = ::mojo::common::mojom::String16DataView(pointer, context_);
    }

    inline void AutofillAgent_PreviewPasswordSuggestion_ParamsDataView::GetUsernameDataView(
        ::mojo::common::mojom::String16DataView* output)
    {
        auto pointer = data_->username.Get();
        *output = ::mojo::common::mojom::String16DataView(pointer, context_);
    }
    inline void AutofillAgent_PreviewPasswordSuggestion_ParamsDataView::GetPasswordDataView(
        ::mojo::common::mojom::String16DataView* output)
    {
        auto pointer = data_->password.Get();
        *output = ::mojo::common::mojom::String16DataView(pointer, context_);
    }

    inline void AutofillAgent_ShowInitialPasswordAccountSuggestions_ParamsDataView::GetFormDataDataView(
        ::autofill::mojom::PasswordFormFillDataDataView* output)
    {
        auto pointer = data_->form_data.Get();
        *output = ::autofill::mojom::PasswordFormFillDataDataView(pointer, context_);
    }

    inline void PasswordAutofillAgent_FillPasswordForm_ParamsDataView::GetFormDataDataView(
        ::autofill::mojom::PasswordFormFillDataDataView* output)
    {
        auto pointer = data_->form_data.Get();
        *output = ::autofill::mojom::PasswordFormFillDataDataView(pointer, context_);
    }

    inline void PasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_ParamsDataView::GetPredictionsDataView(
        ::autofill::mojom::FormsPredictionsMapDataView* output)
    {
        auto pointer = data_->predictions.Get();
        *output = ::autofill::mojom::FormsPredictionsMapDataView(pointer, context_);
    }

    inline void PasswordAutofillAgent_FindFocusedPasswordForm_ResponseParamsDataView::GetFormDataView(
        ::autofill::mojom::PasswordFormDataView* output)
    {
        auto pointer = data_->form.Get();
        *output = ::autofill::mojom::PasswordFormDataView(pointer, context_);
    }

    inline void PasswordGenerationAgent_GeneratedPasswordAccepted_ParamsDataView::GetGeneratedPasswordDataView(
        ::mojo::common::mojom::String16DataView* output)
    {
        auto pointer = data_->generated_password.Get();
        *output = ::mojo::common::mojom::String16DataView(pointer, context_);
    }

    inline void PasswordGenerationAgent_FormNotBlacklisted_ParamsDataView::GetFormDataView(
        ::autofill::mojom::PasswordFormDataView* output)
    {
        auto pointer = data_->form.Get();
        *output = ::autofill::mojom::PasswordFormDataView(pointer, context_);
    }

    inline void PasswordGenerationAgent_FoundFormsEligibleForGeneration_ParamsDataView::GetFormsDataView(
        mojo::ArrayDataView<::autofill::mojom::PasswordFormGenerationDataDataView>* output)
    {
        auto pointer = data_->forms.Get();
        *output = mojo::ArrayDataView<::autofill::mojom::PasswordFormGenerationDataDataView>(pointer, context_);
    }

} // namespace mojom
} // namespace autofill

#endif // COMPONENTS_AUTOFILL_CONTENT_COMMON_AUTOFILL_AGENT_MOJOM_SHARED_H_
