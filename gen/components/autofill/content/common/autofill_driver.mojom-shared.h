// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_AUTOFILL_CONTENT_COMMON_AUTOFILL_DRIVER_MOJOM_SHARED_H_
#define COMPONENTS_AUTOFILL_CONTENT_COMMON_AUTOFILL_DRIVER_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "components/autofill/content/common/autofill_driver.mojom-shared-internal.h"
#include "components/autofill/content/common/autofill_types.mojom-shared.h"
#include "mojo/common/string16.mojom-shared.h"
#include "mojo/common/text_direction.mojom-shared.h"
#include "mojo/common/time.mojom-shared.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared.h"

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
    class AutofillDriverInterfaceBase {
    };

    using AutofillDriverPtrDataView = mojo::InterfacePtrDataView<AutofillDriverInterfaceBase>;
    using AutofillDriverRequestDataView = mojo::InterfaceRequestDataView<AutofillDriverInterfaceBase>;
    using AutofillDriverAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<AutofillDriverInterfaceBase>;
    using AutofillDriverAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<AutofillDriverInterfaceBase>;
    class PasswordManagerDriverInterfaceBase {
    };

    using PasswordManagerDriverPtrDataView = mojo::InterfacePtrDataView<PasswordManagerDriverInterfaceBase>;
    using PasswordManagerDriverRequestDataView = mojo::InterfaceRequestDataView<PasswordManagerDriverInterfaceBase>;
    using PasswordManagerDriverAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<PasswordManagerDriverInterfaceBase>;
    using PasswordManagerDriverAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<PasswordManagerDriverInterfaceBase>;
    class PasswordManagerClientInterfaceBase {
    };

    using PasswordManagerClientPtrDataView = mojo::InterfacePtrDataView<PasswordManagerClientInterfaceBase>;
    using PasswordManagerClientRequestDataView = mojo::InterfaceRequestDataView<PasswordManagerClientInterfaceBase>;
    using PasswordManagerClientAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<PasswordManagerClientInterfaceBase>;
    using PasswordManagerClientAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<PasswordManagerClientInterfaceBase>;
    class AutofillDriver_FirstUserGestureObserved_ParamsDataView {
    public:
        AutofillDriver_FirstUserGestureObserved_ParamsDataView() { }

        AutofillDriver_FirstUserGestureObserved_ParamsDataView(
            internal::AutofillDriver_FirstUserGestureObserved_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::AutofillDriver_FirstUserGestureObserved_Params_Data* data_ = nullptr;
    };

    class AutofillDriver_FormsSeen_ParamsDataView {
    public:
        AutofillDriver_FormsSeen_ParamsDataView() { }

        AutofillDriver_FormsSeen_ParamsDataView(
            internal::AutofillDriver_FormsSeen_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetFormsDataView(
            mojo::ArrayDataView<::autofill::mojom::FormDataDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadForms(UserType* output)
        {
            auto* pointer = data_->forms.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::autofill::mojom::FormDataDataView>>(
                pointer, output, context_);
        }
        inline void GetTimestampDataView(
            ::mojo::common::mojom::TimeTicksDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTimestamp(UserType* output)
        {
            auto* pointer = data_->timestamp.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::TimeTicksDataView>(
                pointer, output, context_);
        }

    private:
        internal::AutofillDriver_FormsSeen_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class AutofillDriver_WillSubmitForm_ParamsDataView {
    public:
        AutofillDriver_WillSubmitForm_ParamsDataView() { }

        AutofillDriver_WillSubmitForm_ParamsDataView(
            internal::AutofillDriver_WillSubmitForm_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetFormDataView(
            ::autofill::mojom::FormDataDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadForm(UserType* output)
        {
            auto* pointer = data_->form.Get();
            return mojo::internal::Deserialize<::autofill::mojom::FormDataDataView>(
                pointer, output, context_);
        }
        inline void GetTimestampDataView(
            ::mojo::common::mojom::TimeTicksDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTimestamp(UserType* output)
        {
            auto* pointer = data_->timestamp.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::TimeTicksDataView>(
                pointer, output, context_);
        }

    private:
        internal::AutofillDriver_WillSubmitForm_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class AutofillDriver_FormSubmitted_ParamsDataView {
    public:
        AutofillDriver_FormSubmitted_ParamsDataView() { }

        AutofillDriver_FormSubmitted_ParamsDataView(
            internal::AutofillDriver_FormSubmitted_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
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
        internal::AutofillDriver_FormSubmitted_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class AutofillDriver_TextFieldDidChange_ParamsDataView {
    public:
        AutofillDriver_TextFieldDidChange_ParamsDataView() { }

        AutofillDriver_TextFieldDidChange_ParamsDataView(
            internal::AutofillDriver_TextFieldDidChange_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetFormDataView(
            ::autofill::mojom::FormDataDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadForm(UserType* output)
        {
            auto* pointer = data_->form.Get();
            return mojo::internal::Deserialize<::autofill::mojom::FormDataDataView>(
                pointer, output, context_);
        }
        inline void GetFieldDataView(
            ::autofill::mojom::FormFieldDataDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadField(UserType* output)
        {
            auto* pointer = data_->field.Get();
            return mojo::internal::Deserialize<::autofill::mojom::FormFieldDataDataView>(
                pointer, output, context_);
        }
        inline void GetTimestampDataView(
            ::mojo::common::mojom::TimeTicksDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTimestamp(UserType* output)
        {
            auto* pointer = data_->timestamp.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::TimeTicksDataView>(
                pointer, output, context_);
        }

    private:
        internal::AutofillDriver_TextFieldDidChange_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class AutofillDriver_QueryFormFieldAutofill_ParamsDataView {
    public:
        AutofillDriver_QueryFormFieldAutofill_ParamsDataView() { }

        AutofillDriver_QueryFormFieldAutofill_ParamsDataView(
            internal::AutofillDriver_QueryFormFieldAutofill_Params_Data* data,
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
        inline void GetFieldDataView(
            ::autofill::mojom::FormFieldDataDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadField(UserType* output)
        {
            auto* pointer = data_->field.Get();
            return mojo::internal::Deserialize<::autofill::mojom::FormFieldDataDataView>(
                pointer, output, context_);
        }
        inline void GetBoundingBoxDataView(
            ::gfx::mojom::RectFDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadBoundingBox(UserType* output)
        {
            auto* pointer = data_->bounding_box.Get();
            return mojo::internal::Deserialize<::gfx::mojom::RectFDataView>(
                pointer, output, context_);
        }

    private:
        internal::AutofillDriver_QueryFormFieldAutofill_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class AutofillDriver_HidePopup_ParamsDataView {
    public:
        AutofillDriver_HidePopup_ParamsDataView() { }

        AutofillDriver_HidePopup_ParamsDataView(
            internal::AutofillDriver_HidePopup_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::AutofillDriver_HidePopup_Params_Data* data_ = nullptr;
    };

    class AutofillDriver_FocusNoLongerOnForm_ParamsDataView {
    public:
        AutofillDriver_FocusNoLongerOnForm_ParamsDataView() { }

        AutofillDriver_FocusNoLongerOnForm_ParamsDataView(
            internal::AutofillDriver_FocusNoLongerOnForm_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::AutofillDriver_FocusNoLongerOnForm_Params_Data* data_ = nullptr;
    };

    class AutofillDriver_DidFillAutofillFormData_ParamsDataView {
    public:
        AutofillDriver_DidFillAutofillFormData_ParamsDataView() { }

        AutofillDriver_DidFillAutofillFormData_ParamsDataView(
            internal::AutofillDriver_DidFillAutofillFormData_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetFormDataView(
            ::autofill::mojom::FormDataDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadForm(UserType* output)
        {
            auto* pointer = data_->form.Get();
            return mojo::internal::Deserialize<::autofill::mojom::FormDataDataView>(
                pointer, output, context_);
        }
        inline void GetTimestampDataView(
            ::mojo::common::mojom::TimeTicksDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTimestamp(UserType* output)
        {
            auto* pointer = data_->timestamp.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::TimeTicksDataView>(
                pointer, output, context_);
        }

    private:
        internal::AutofillDriver_DidFillAutofillFormData_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class AutofillDriver_DidPreviewAutofillFormData_ParamsDataView {
    public:
        AutofillDriver_DidPreviewAutofillFormData_ParamsDataView() { }

        AutofillDriver_DidPreviewAutofillFormData_ParamsDataView(
            internal::AutofillDriver_DidPreviewAutofillFormData_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::AutofillDriver_DidPreviewAutofillFormData_Params_Data* data_ = nullptr;
    };

    class AutofillDriver_DidEndTextFieldEditing_ParamsDataView {
    public:
        AutofillDriver_DidEndTextFieldEditing_ParamsDataView() { }

        AutofillDriver_DidEndTextFieldEditing_ParamsDataView(
            internal::AutofillDriver_DidEndTextFieldEditing_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::AutofillDriver_DidEndTextFieldEditing_Params_Data* data_ = nullptr;
    };

    class AutofillDriver_SetDataList_ParamsDataView {
    public:
        AutofillDriver_SetDataList_ParamsDataView() { }

        AutofillDriver_SetDataList_ParamsDataView(
            internal::AutofillDriver_SetDataList_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetValuesDataView(
            mojo::ArrayDataView<::mojo::common::mojom::String16DataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadValues(UserType* output)
        {
            auto* pointer = data_->values.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::mojo::common::mojom::String16DataView>>(
                pointer, output, context_);
        }
        inline void GetLabelsDataView(
            mojo::ArrayDataView<::mojo::common::mojom::String16DataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadLabels(UserType* output)
        {
            auto* pointer = data_->labels.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::mojo::common::mojom::String16DataView>>(
                pointer, output, context_);
        }

    private:
        internal::AutofillDriver_SetDataList_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PasswordManagerDriver_PasswordFormsParsed_ParamsDataView {
    public:
        PasswordManagerDriver_PasswordFormsParsed_ParamsDataView() { }

        PasswordManagerDriver_PasswordFormsParsed_ParamsDataView(
            internal::PasswordManagerDriver_PasswordFormsParsed_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetFormsDataView(
            mojo::ArrayDataView<::autofill::mojom::PasswordFormDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadForms(UserType* output)
        {
            auto* pointer = data_->forms.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::autofill::mojom::PasswordFormDataView>>(
                pointer, output, context_);
        }

    private:
        internal::PasswordManagerDriver_PasswordFormsParsed_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PasswordManagerDriver_PasswordFormsRendered_ParamsDataView {
    public:
        PasswordManagerDriver_PasswordFormsRendered_ParamsDataView() { }

        PasswordManagerDriver_PasswordFormsRendered_ParamsDataView(
            internal::PasswordManagerDriver_PasswordFormsRendered_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetVisibleFormsDataView(
            mojo::ArrayDataView<::autofill::mojom::PasswordFormDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadVisibleForms(UserType* output)
        {
            auto* pointer = data_->visible_forms.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::autofill::mojom::PasswordFormDataView>>(
                pointer, output, context_);
        }
        bool did_stop_loading() const
        {
            return data_->did_stop_loading;
        }

    private:
        internal::PasswordManagerDriver_PasswordFormsRendered_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PasswordManagerDriver_PasswordFormSubmitted_ParamsDataView {
    public:
        PasswordManagerDriver_PasswordFormSubmitted_ParamsDataView() { }

        PasswordManagerDriver_PasswordFormSubmitted_ParamsDataView(
            internal::PasswordManagerDriver_PasswordFormSubmitted_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetPasswordFormDataView(
            ::autofill::mojom::PasswordFormDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPasswordForm(UserType* output)
        {
            auto* pointer = data_->password_form.Get();
            return mojo::internal::Deserialize<::autofill::mojom::PasswordFormDataView>(
                pointer, output, context_);
        }

    private:
        internal::PasswordManagerDriver_PasswordFormSubmitted_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PasswordManagerDriver_InPageNavigation_ParamsDataView {
    public:
        PasswordManagerDriver_InPageNavigation_ParamsDataView() { }

        PasswordManagerDriver_InPageNavigation_ParamsDataView(
            internal::PasswordManagerDriver_InPageNavigation_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetPasswordFormDataView(
            ::autofill::mojom::PasswordFormDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPasswordForm(UserType* output)
        {
            auto* pointer = data_->password_form.Get();
            return mojo::internal::Deserialize<::autofill::mojom::PasswordFormDataView>(
                pointer, output, context_);
        }

    private:
        internal::PasswordManagerDriver_InPageNavigation_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PasswordManagerDriver_RecordSavePasswordProgress_ParamsDataView {
    public:
        PasswordManagerDriver_RecordSavePasswordProgress_ParamsDataView() { }

        PasswordManagerDriver_RecordSavePasswordProgress_ParamsDataView(
            internal::PasswordManagerDriver_RecordSavePasswordProgress_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetLogDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadLog(UserType* output)
        {
            auto* pointer = data_->log.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::PasswordManagerDriver_RecordSavePasswordProgress_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PasswordManagerDriver_ShowPasswordSuggestions_ParamsDataView {
    public:
        PasswordManagerDriver_ShowPasswordSuggestions_ParamsDataView() { }

        PasswordManagerDriver_ShowPasswordSuggestions_ParamsDataView(
            internal::PasswordManagerDriver_ShowPasswordSuggestions_Params_Data* data,
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
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTextDirection(UserType* output) const
        {
            auto data_value = data_->text_direction;
            return mojo::internal::Deserialize<::mojo::common::mojom::TextDirection>(
                data_value, output);
        }

        ::mojo::common::mojom::TextDirection text_direction() const
        {
            return static_cast<::mojo::common::mojom::TextDirection>(data_->text_direction);
        }
        inline void GetTypedUsernameDataView(
            ::mojo::common::mojom::String16DataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTypedUsername(UserType* output)
        {
            auto* pointer = data_->typed_username.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::String16DataView>(
                pointer, output, context_);
        }
        int32_t options() const
        {
            return data_->options;
        }
        inline void GetBoundsDataView(
            ::gfx::mojom::RectFDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadBounds(UserType* output)
        {
            auto* pointer = data_->bounds.Get();
            return mojo::internal::Deserialize<::gfx::mojom::RectFDataView>(
                pointer, output, context_);
        }

    private:
        internal::PasswordManagerDriver_ShowPasswordSuggestions_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PasswordManagerDriver_ShowNotSecureWarning_ParamsDataView {
    public:
        PasswordManagerDriver_ShowNotSecureWarning_ParamsDataView() { }

        PasswordManagerDriver_ShowNotSecureWarning_ParamsDataView(
            internal::PasswordManagerDriver_ShowNotSecureWarning_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadTextDirection(UserType* output) const
        {
            auto data_value = data_->text_direction;
            return mojo::internal::Deserialize<::mojo::common::mojom::TextDirection>(
                data_value, output);
        }

        ::mojo::common::mojom::TextDirection text_direction() const
        {
            return static_cast<::mojo::common::mojom::TextDirection>(data_->text_direction);
        }
        inline void GetBoundsDataView(
            ::gfx::mojom::RectFDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadBounds(UserType* output)
        {
            auto* pointer = data_->bounds.Get();
            return mojo::internal::Deserialize<::gfx::mojom::RectFDataView>(
                pointer, output, context_);
        }

    private:
        internal::PasswordManagerDriver_ShowNotSecureWarning_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PasswordManagerDriver_PresaveGeneratedPassword_ParamsDataView {
    public:
        PasswordManagerDriver_PresaveGeneratedPassword_ParamsDataView() { }

        PasswordManagerDriver_PresaveGeneratedPassword_ParamsDataView(
            internal::PasswordManagerDriver_PresaveGeneratedPassword_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetPasswordFormDataView(
            ::autofill::mojom::PasswordFormDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPasswordForm(UserType* output)
        {
            auto* pointer = data_->password_form.Get();
            return mojo::internal::Deserialize<::autofill::mojom::PasswordFormDataView>(
                pointer, output, context_);
        }

    private:
        internal::PasswordManagerDriver_PresaveGeneratedPassword_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PasswordManagerDriver_PasswordNoLongerGenerated_ParamsDataView {
    public:
        PasswordManagerDriver_PasswordNoLongerGenerated_ParamsDataView() { }

        PasswordManagerDriver_PasswordNoLongerGenerated_ParamsDataView(
            internal::PasswordManagerDriver_PasswordNoLongerGenerated_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetPasswordFormDataView(
            ::autofill::mojom::PasswordFormDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPasswordForm(UserType* output)
        {
            auto* pointer = data_->password_form.Get();
            return mojo::internal::Deserialize<::autofill::mojom::PasswordFormDataView>(
                pointer, output, context_);
        }

    private:
        internal::PasswordManagerDriver_PasswordNoLongerGenerated_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_ParamsDataView {
    public:
        PasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_ParamsDataView() { }

        PasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_ParamsDataView(
            internal::PasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetPasswordFormDataView(
            ::autofill::mojom::PasswordFormDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPasswordForm(UserType* output)
        {
            auto* pointer = data_->password_form.Get();
            return mojo::internal::Deserialize<::autofill::mojom::PasswordFormDataView>(
                pointer, output, context_);
        }
        inline void GetGenerationFieldDataView(
            ::mojo::common::mojom::String16DataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadGenerationField(UserType* output)
        {
            auto* pointer = data_->generation_field.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::String16DataView>(
                pointer, output, context_);
        }

    private:
        internal::PasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PasswordManagerClient_GenerationAvailableForForm_ParamsDataView {
    public:
        PasswordManagerClient_GenerationAvailableForForm_ParamsDataView() { }

        PasswordManagerClient_GenerationAvailableForForm_ParamsDataView(
            internal::PasswordManagerClient_GenerationAvailableForForm_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetPasswordFormDataView(
            ::autofill::mojom::PasswordFormDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPasswordForm(UserType* output)
        {
            auto* pointer = data_->password_form.Get();
            return mojo::internal::Deserialize<::autofill::mojom::PasswordFormDataView>(
                pointer, output, context_);
        }

    private:
        internal::PasswordManagerClient_GenerationAvailableForForm_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PasswordManagerClient_ShowPasswordGenerationPopup_ParamsDataView {
    public:
        PasswordManagerClient_ShowPasswordGenerationPopup_ParamsDataView() { }

        PasswordManagerClient_ShowPasswordGenerationPopup_ParamsDataView(
            internal::PasswordManagerClient_ShowPasswordGenerationPopup_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetBoundsDataView(
            ::gfx::mojom::RectFDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadBounds(UserType* output)
        {
            auto* pointer = data_->bounds.Get();
            return mojo::internal::Deserialize<::gfx::mojom::RectFDataView>(
                pointer, output, context_);
        }
        int32_t max_length() const
        {
            return data_->max_length;
        }
        inline void GetGenerationElementDataView(
            ::mojo::common::mojom::String16DataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadGenerationElement(UserType* output)
        {
            auto* pointer = data_->generation_element.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::String16DataView>(
                pointer, output, context_);
        }
        bool is_manually_triggered() const
        {
            return data_->is_manually_triggered;
        }
        inline void GetPasswordFormDataView(
            ::autofill::mojom::PasswordFormDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPasswordForm(UserType* output)
        {
            auto* pointer = data_->password_form.Get();
            return mojo::internal::Deserialize<::autofill::mojom::PasswordFormDataView>(
                pointer, output, context_);
        }

    private:
        internal::PasswordManagerClient_ShowPasswordGenerationPopup_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PasswordManagerClient_ShowPasswordEditingPopup_ParamsDataView {
    public:
        PasswordManagerClient_ShowPasswordEditingPopup_ParamsDataView() { }

        PasswordManagerClient_ShowPasswordEditingPopup_ParamsDataView(
            internal::PasswordManagerClient_ShowPasswordEditingPopup_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetBoundsDataView(
            ::gfx::mojom::RectFDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadBounds(UserType* output)
        {
            auto* pointer = data_->bounds.Get();
            return mojo::internal::Deserialize<::gfx::mojom::RectFDataView>(
                pointer, output, context_);
        }
        inline void GetPasswordFormDataView(
            ::autofill::mojom::PasswordFormDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPasswordForm(UserType* output)
        {
            auto* pointer = data_->password_form.Get();
            return mojo::internal::Deserialize<::autofill::mojom::PasswordFormDataView>(
                pointer, output, context_);
        }

    private:
        internal::PasswordManagerClient_ShowPasswordEditingPopup_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PasswordManagerClient_HidePasswordGenerationPopup_ParamsDataView {
    public:
        PasswordManagerClient_HidePasswordGenerationPopup_ParamsDataView() { }

        PasswordManagerClient_HidePasswordGenerationPopup_ParamsDataView(
            internal::PasswordManagerClient_HidePasswordGenerationPopup_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::PasswordManagerClient_HidePasswordGenerationPopup_Params_Data* data_ = nullptr;
    };

} // namespace mojom
} // namespace autofill

namespace std {

} // namespace std

namespace mojo {

} // namespace mojo

namespace autofill {
namespace mojom {

    inline void AutofillDriver_FormsSeen_ParamsDataView::GetFormsDataView(
        mojo::ArrayDataView<::autofill::mojom::FormDataDataView>* output)
    {
        auto pointer = data_->forms.Get();
        *output = mojo::ArrayDataView<::autofill::mojom::FormDataDataView>(pointer, context_);
    }
    inline void AutofillDriver_FormsSeen_ParamsDataView::GetTimestampDataView(
        ::mojo::common::mojom::TimeTicksDataView* output)
    {
        auto pointer = data_->timestamp.Get();
        *output = ::mojo::common::mojom::TimeTicksDataView(pointer, context_);
    }

    inline void AutofillDriver_WillSubmitForm_ParamsDataView::GetFormDataView(
        ::autofill::mojom::FormDataDataView* output)
    {
        auto pointer = data_->form.Get();
        *output = ::autofill::mojom::FormDataDataView(pointer, context_);
    }
    inline void AutofillDriver_WillSubmitForm_ParamsDataView::GetTimestampDataView(
        ::mojo::common::mojom::TimeTicksDataView* output)
    {
        auto pointer = data_->timestamp.Get();
        *output = ::mojo::common::mojom::TimeTicksDataView(pointer, context_);
    }

    inline void AutofillDriver_FormSubmitted_ParamsDataView::GetFormDataView(
        ::autofill::mojom::FormDataDataView* output)
    {
        auto pointer = data_->form.Get();
        *output = ::autofill::mojom::FormDataDataView(pointer, context_);
    }

    inline void AutofillDriver_TextFieldDidChange_ParamsDataView::GetFormDataView(
        ::autofill::mojom::FormDataDataView* output)
    {
        auto pointer = data_->form.Get();
        *output = ::autofill::mojom::FormDataDataView(pointer, context_);
    }
    inline void AutofillDriver_TextFieldDidChange_ParamsDataView::GetFieldDataView(
        ::autofill::mojom::FormFieldDataDataView* output)
    {
        auto pointer = data_->field.Get();
        *output = ::autofill::mojom::FormFieldDataDataView(pointer, context_);
    }
    inline void AutofillDriver_TextFieldDidChange_ParamsDataView::GetTimestampDataView(
        ::mojo::common::mojom::TimeTicksDataView* output)
    {
        auto pointer = data_->timestamp.Get();
        *output = ::mojo::common::mojom::TimeTicksDataView(pointer, context_);
    }

    inline void AutofillDriver_QueryFormFieldAutofill_ParamsDataView::GetFormDataView(
        ::autofill::mojom::FormDataDataView* output)
    {
        auto pointer = data_->form.Get();
        *output = ::autofill::mojom::FormDataDataView(pointer, context_);
    }
    inline void AutofillDriver_QueryFormFieldAutofill_ParamsDataView::GetFieldDataView(
        ::autofill::mojom::FormFieldDataDataView* output)
    {
        auto pointer = data_->field.Get();
        *output = ::autofill::mojom::FormFieldDataDataView(pointer, context_);
    }
    inline void AutofillDriver_QueryFormFieldAutofill_ParamsDataView::GetBoundingBoxDataView(
        ::gfx::mojom::RectFDataView* output)
    {
        auto pointer = data_->bounding_box.Get();
        *output = ::gfx::mojom::RectFDataView(pointer, context_);
    }

    inline void AutofillDriver_DidFillAutofillFormData_ParamsDataView::GetFormDataView(
        ::autofill::mojom::FormDataDataView* output)
    {
        auto pointer = data_->form.Get();
        *output = ::autofill::mojom::FormDataDataView(pointer, context_);
    }
    inline void AutofillDriver_DidFillAutofillFormData_ParamsDataView::GetTimestampDataView(
        ::mojo::common::mojom::TimeTicksDataView* output)
    {
        auto pointer = data_->timestamp.Get();
        *output = ::mojo::common::mojom::TimeTicksDataView(pointer, context_);
    }

    inline void AutofillDriver_SetDataList_ParamsDataView::GetValuesDataView(
        mojo::ArrayDataView<::mojo::common::mojom::String16DataView>* output)
    {
        auto pointer = data_->values.Get();
        *output = mojo::ArrayDataView<::mojo::common::mojom::String16DataView>(pointer, context_);
    }
    inline void AutofillDriver_SetDataList_ParamsDataView::GetLabelsDataView(
        mojo::ArrayDataView<::mojo::common::mojom::String16DataView>* output)
    {
        auto pointer = data_->labels.Get();
        *output = mojo::ArrayDataView<::mojo::common::mojom::String16DataView>(pointer, context_);
    }

    inline void PasswordManagerDriver_PasswordFormsParsed_ParamsDataView::GetFormsDataView(
        mojo::ArrayDataView<::autofill::mojom::PasswordFormDataView>* output)
    {
        auto pointer = data_->forms.Get();
        *output = mojo::ArrayDataView<::autofill::mojom::PasswordFormDataView>(pointer, context_);
    }

    inline void PasswordManagerDriver_PasswordFormsRendered_ParamsDataView::GetVisibleFormsDataView(
        mojo::ArrayDataView<::autofill::mojom::PasswordFormDataView>* output)
    {
        auto pointer = data_->visible_forms.Get();
        *output = mojo::ArrayDataView<::autofill::mojom::PasswordFormDataView>(pointer, context_);
    }

    inline void PasswordManagerDriver_PasswordFormSubmitted_ParamsDataView::GetPasswordFormDataView(
        ::autofill::mojom::PasswordFormDataView* output)
    {
        auto pointer = data_->password_form.Get();
        *output = ::autofill::mojom::PasswordFormDataView(pointer, context_);
    }

    inline void PasswordManagerDriver_InPageNavigation_ParamsDataView::GetPasswordFormDataView(
        ::autofill::mojom::PasswordFormDataView* output)
    {
        auto pointer = data_->password_form.Get();
        *output = ::autofill::mojom::PasswordFormDataView(pointer, context_);
    }

    inline void PasswordManagerDriver_RecordSavePasswordProgress_ParamsDataView::GetLogDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->log.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void PasswordManagerDriver_ShowPasswordSuggestions_ParamsDataView::GetTypedUsernameDataView(
        ::mojo::common::mojom::String16DataView* output)
    {
        auto pointer = data_->typed_username.Get();
        *output = ::mojo::common::mojom::String16DataView(pointer, context_);
    }
    inline void PasswordManagerDriver_ShowPasswordSuggestions_ParamsDataView::GetBoundsDataView(
        ::gfx::mojom::RectFDataView* output)
    {
        auto pointer = data_->bounds.Get();
        *output = ::gfx::mojom::RectFDataView(pointer, context_);
    }

    inline void PasswordManagerDriver_ShowNotSecureWarning_ParamsDataView::GetBoundsDataView(
        ::gfx::mojom::RectFDataView* output)
    {
        auto pointer = data_->bounds.Get();
        *output = ::gfx::mojom::RectFDataView(pointer, context_);
    }

    inline void PasswordManagerDriver_PresaveGeneratedPassword_ParamsDataView::GetPasswordFormDataView(
        ::autofill::mojom::PasswordFormDataView* output)
    {
        auto pointer = data_->password_form.Get();
        *output = ::autofill::mojom::PasswordFormDataView(pointer, context_);
    }

    inline void PasswordManagerDriver_PasswordNoLongerGenerated_ParamsDataView::GetPasswordFormDataView(
        ::autofill::mojom::PasswordFormDataView* output)
    {
        auto pointer = data_->password_form.Get();
        *output = ::autofill::mojom::PasswordFormDataView(pointer, context_);
    }

    inline void PasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_ParamsDataView::GetPasswordFormDataView(
        ::autofill::mojom::PasswordFormDataView* output)
    {
        auto pointer = data_->password_form.Get();
        *output = ::autofill::mojom::PasswordFormDataView(pointer, context_);
    }
    inline void PasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_ParamsDataView::GetGenerationFieldDataView(
        ::mojo::common::mojom::String16DataView* output)
    {
        auto pointer = data_->generation_field.Get();
        *output = ::mojo::common::mojom::String16DataView(pointer, context_);
    }

    inline void PasswordManagerClient_GenerationAvailableForForm_ParamsDataView::GetPasswordFormDataView(
        ::autofill::mojom::PasswordFormDataView* output)
    {
        auto pointer = data_->password_form.Get();
        *output = ::autofill::mojom::PasswordFormDataView(pointer, context_);
    }

    inline void PasswordManagerClient_ShowPasswordGenerationPopup_ParamsDataView::GetBoundsDataView(
        ::gfx::mojom::RectFDataView* output)
    {
        auto pointer = data_->bounds.Get();
        *output = ::gfx::mojom::RectFDataView(pointer, context_);
    }
    inline void PasswordManagerClient_ShowPasswordGenerationPopup_ParamsDataView::GetGenerationElementDataView(
        ::mojo::common::mojom::String16DataView* output)
    {
        auto pointer = data_->generation_element.Get();
        *output = ::mojo::common::mojom::String16DataView(pointer, context_);
    }
    inline void PasswordManagerClient_ShowPasswordGenerationPopup_ParamsDataView::GetPasswordFormDataView(
        ::autofill::mojom::PasswordFormDataView* output)
    {
        auto pointer = data_->password_form.Get();
        *output = ::autofill::mojom::PasswordFormDataView(pointer, context_);
    }

    inline void PasswordManagerClient_ShowPasswordEditingPopup_ParamsDataView::GetBoundsDataView(
        ::gfx::mojom::RectFDataView* output)
    {
        auto pointer = data_->bounds.Get();
        *output = ::gfx::mojom::RectFDataView(pointer, context_);
    }
    inline void PasswordManagerClient_ShowPasswordEditingPopup_ParamsDataView::GetPasswordFormDataView(
        ::autofill::mojom::PasswordFormDataView* output)
    {
        auto pointer = data_->password_form.Get();
        *output = ::autofill::mojom::PasswordFormDataView(pointer, context_);
    }

} // namespace mojom
} // namespace autofill

#endif // COMPONENTS_AUTOFILL_CONTENT_COMMON_AUTOFILL_DRIVER_MOJOM_SHARED_H_
