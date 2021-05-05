// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_AUTOFILL_CONTENT_COMMON_AUTOFILL_DRIVER_MOJOM_SHARED_INTERNAL_H_
#define COMPONENTS_AUTOFILL_CONTENT_COMMON_AUTOFILL_DRIVER_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "components/autofill/content/common/autofill_types.mojom-shared-internal.h"
#include "mojo/common/string16.mojom-shared-internal.h"
#include "mojo/common/text_direction.mojom-shared-internal.h"
#include "mojo/common/time.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "ui/gfx/geometry/mojo/geometry.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace autofill {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kAutofillDriver_FirstUserGestureObserved_Name = 0;
        class AutofillDriver_FirstUserGestureObserved_Params_Data {
        public:
            static AutofillDriver_FirstUserGestureObserved_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AutofillDriver_FirstUserGestureObserved_Params_Data))) AutofillDriver_FirstUserGestureObserved_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            AutofillDriver_FirstUserGestureObserved_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AutofillDriver_FirstUserGestureObserved_Params_Data() = delete;
        };
        static_assert(sizeof(AutofillDriver_FirstUserGestureObserved_Params_Data) == 8,
            "Bad sizeof(AutofillDriver_FirstUserGestureObserved_Params_Data)");
        constexpr uint32_t kAutofillDriver_FormsSeen_Name = 1;
        class AutofillDriver_FormsSeen_Params_Data {
        public:
            static AutofillDriver_FormsSeen_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AutofillDriver_FormsSeen_Params_Data))) AutofillDriver_FormsSeen_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::autofill::mojom::internal::FormData_Data>>> forms;
            mojo::internal::Pointer<::mojo::common::mojom::internal::TimeTicks_Data> timestamp;

        private:
            AutofillDriver_FormsSeen_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AutofillDriver_FormsSeen_Params_Data() = delete;
        };
        static_assert(sizeof(AutofillDriver_FormsSeen_Params_Data) == 24,
            "Bad sizeof(AutofillDriver_FormsSeen_Params_Data)");
        constexpr uint32_t kAutofillDriver_WillSubmitForm_Name = 2;
        class AutofillDriver_WillSubmitForm_Params_Data {
        public:
            static AutofillDriver_WillSubmitForm_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AutofillDriver_WillSubmitForm_Params_Data))) AutofillDriver_WillSubmitForm_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::autofill::mojom::internal::FormData_Data> form;
            mojo::internal::Pointer<::mojo::common::mojom::internal::TimeTicks_Data> timestamp;

        private:
            AutofillDriver_WillSubmitForm_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AutofillDriver_WillSubmitForm_Params_Data() = delete;
        };
        static_assert(sizeof(AutofillDriver_WillSubmitForm_Params_Data) == 24,
            "Bad sizeof(AutofillDriver_WillSubmitForm_Params_Data)");
        constexpr uint32_t kAutofillDriver_FormSubmitted_Name = 3;
        class AutofillDriver_FormSubmitted_Params_Data {
        public:
            static AutofillDriver_FormSubmitted_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AutofillDriver_FormSubmitted_Params_Data))) AutofillDriver_FormSubmitted_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::autofill::mojom::internal::FormData_Data> form;

        private:
            AutofillDriver_FormSubmitted_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AutofillDriver_FormSubmitted_Params_Data() = delete;
        };
        static_assert(sizeof(AutofillDriver_FormSubmitted_Params_Data) == 16,
            "Bad sizeof(AutofillDriver_FormSubmitted_Params_Data)");
        constexpr uint32_t kAutofillDriver_TextFieldDidChange_Name = 4;
        class AutofillDriver_TextFieldDidChange_Params_Data {
        public:
            static AutofillDriver_TextFieldDidChange_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AutofillDriver_TextFieldDidChange_Params_Data))) AutofillDriver_TextFieldDidChange_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::autofill::mojom::internal::FormData_Data> form;
            mojo::internal::Pointer<::autofill::mojom::internal::FormFieldData_Data> field;
            mojo::internal::Pointer<::mojo::common::mojom::internal::TimeTicks_Data> timestamp;

        private:
            AutofillDriver_TextFieldDidChange_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AutofillDriver_TextFieldDidChange_Params_Data() = delete;
        };
        static_assert(sizeof(AutofillDriver_TextFieldDidChange_Params_Data) == 32,
            "Bad sizeof(AutofillDriver_TextFieldDidChange_Params_Data)");
        constexpr uint32_t kAutofillDriver_QueryFormFieldAutofill_Name = 5;
        class AutofillDriver_QueryFormFieldAutofill_Params_Data {
        public:
            static AutofillDriver_QueryFormFieldAutofill_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AutofillDriver_QueryFormFieldAutofill_Params_Data))) AutofillDriver_QueryFormFieldAutofill_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t id;
            uint8_t pad0_[4];
            mojo::internal::Pointer<::autofill::mojom::internal::FormData_Data> form;
            mojo::internal::Pointer<::autofill::mojom::internal::FormFieldData_Data> field;
            mojo::internal::Pointer<::gfx::mojom::internal::RectF_Data> bounding_box;

        private:
            AutofillDriver_QueryFormFieldAutofill_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AutofillDriver_QueryFormFieldAutofill_Params_Data() = delete;
        };
        static_assert(sizeof(AutofillDriver_QueryFormFieldAutofill_Params_Data) == 40,
            "Bad sizeof(AutofillDriver_QueryFormFieldAutofill_Params_Data)");
        constexpr uint32_t kAutofillDriver_HidePopup_Name = 6;
        class AutofillDriver_HidePopup_Params_Data {
        public:
            static AutofillDriver_HidePopup_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AutofillDriver_HidePopup_Params_Data))) AutofillDriver_HidePopup_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            AutofillDriver_HidePopup_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AutofillDriver_HidePopup_Params_Data() = delete;
        };
        static_assert(sizeof(AutofillDriver_HidePopup_Params_Data) == 8,
            "Bad sizeof(AutofillDriver_HidePopup_Params_Data)");
        constexpr uint32_t kAutofillDriver_FocusNoLongerOnForm_Name = 7;
        class AutofillDriver_FocusNoLongerOnForm_Params_Data {
        public:
            static AutofillDriver_FocusNoLongerOnForm_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AutofillDriver_FocusNoLongerOnForm_Params_Data))) AutofillDriver_FocusNoLongerOnForm_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            AutofillDriver_FocusNoLongerOnForm_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AutofillDriver_FocusNoLongerOnForm_Params_Data() = delete;
        };
        static_assert(sizeof(AutofillDriver_FocusNoLongerOnForm_Params_Data) == 8,
            "Bad sizeof(AutofillDriver_FocusNoLongerOnForm_Params_Data)");
        constexpr uint32_t kAutofillDriver_DidFillAutofillFormData_Name = 8;
        class AutofillDriver_DidFillAutofillFormData_Params_Data {
        public:
            static AutofillDriver_DidFillAutofillFormData_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AutofillDriver_DidFillAutofillFormData_Params_Data))) AutofillDriver_DidFillAutofillFormData_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::autofill::mojom::internal::FormData_Data> form;
            mojo::internal::Pointer<::mojo::common::mojom::internal::TimeTicks_Data> timestamp;

        private:
            AutofillDriver_DidFillAutofillFormData_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AutofillDriver_DidFillAutofillFormData_Params_Data() = delete;
        };
        static_assert(sizeof(AutofillDriver_DidFillAutofillFormData_Params_Data) == 24,
            "Bad sizeof(AutofillDriver_DidFillAutofillFormData_Params_Data)");
        constexpr uint32_t kAutofillDriver_DidPreviewAutofillFormData_Name = 9;
        class AutofillDriver_DidPreviewAutofillFormData_Params_Data {
        public:
            static AutofillDriver_DidPreviewAutofillFormData_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AutofillDriver_DidPreviewAutofillFormData_Params_Data))) AutofillDriver_DidPreviewAutofillFormData_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            AutofillDriver_DidPreviewAutofillFormData_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AutofillDriver_DidPreviewAutofillFormData_Params_Data() = delete;
        };
        static_assert(sizeof(AutofillDriver_DidPreviewAutofillFormData_Params_Data) == 8,
            "Bad sizeof(AutofillDriver_DidPreviewAutofillFormData_Params_Data)");
        constexpr uint32_t kAutofillDriver_DidEndTextFieldEditing_Name = 10;
        class AutofillDriver_DidEndTextFieldEditing_Params_Data {
        public:
            static AutofillDriver_DidEndTextFieldEditing_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AutofillDriver_DidEndTextFieldEditing_Params_Data))) AutofillDriver_DidEndTextFieldEditing_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            AutofillDriver_DidEndTextFieldEditing_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AutofillDriver_DidEndTextFieldEditing_Params_Data() = delete;
        };
        static_assert(sizeof(AutofillDriver_DidEndTextFieldEditing_Params_Data) == 8,
            "Bad sizeof(AutofillDriver_DidEndTextFieldEditing_Params_Data)");
        constexpr uint32_t kAutofillDriver_SetDataList_Name = 11;
        class AutofillDriver_SetDataList_Params_Data {
        public:
            static AutofillDriver_SetDataList_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AutofillDriver_SetDataList_Params_Data))) AutofillDriver_SetDataList_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::mojo::common::mojom::internal::String16_Data>>> values;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::mojo::common::mojom::internal::String16_Data>>> labels;

        private:
            AutofillDriver_SetDataList_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AutofillDriver_SetDataList_Params_Data() = delete;
        };
        static_assert(sizeof(AutofillDriver_SetDataList_Params_Data) == 24,
            "Bad sizeof(AutofillDriver_SetDataList_Params_Data)");
        constexpr uint32_t kPasswordManagerDriver_PasswordFormsParsed_Name = 0;
        class PasswordManagerDriver_PasswordFormsParsed_Params_Data {
        public:
            static PasswordManagerDriver_PasswordFormsParsed_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PasswordManagerDriver_PasswordFormsParsed_Params_Data))) PasswordManagerDriver_PasswordFormsParsed_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::autofill::mojom::internal::PasswordForm_Data>>> forms;

        private:
            PasswordManagerDriver_PasswordFormsParsed_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PasswordManagerDriver_PasswordFormsParsed_Params_Data() = delete;
        };
        static_assert(sizeof(PasswordManagerDriver_PasswordFormsParsed_Params_Data) == 16,
            "Bad sizeof(PasswordManagerDriver_PasswordFormsParsed_Params_Data)");
        constexpr uint32_t kPasswordManagerDriver_PasswordFormsRendered_Name = 1;
        class PasswordManagerDriver_PasswordFormsRendered_Params_Data {
        public:
            static PasswordManagerDriver_PasswordFormsRendered_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PasswordManagerDriver_PasswordFormsRendered_Params_Data))) PasswordManagerDriver_PasswordFormsRendered_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::autofill::mojom::internal::PasswordForm_Data>>> visible_forms;
            uint8_t did_stop_loading : 1;
            uint8_t padfinal_[7];

        private:
            PasswordManagerDriver_PasswordFormsRendered_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PasswordManagerDriver_PasswordFormsRendered_Params_Data() = delete;
        };
        static_assert(sizeof(PasswordManagerDriver_PasswordFormsRendered_Params_Data) == 24,
            "Bad sizeof(PasswordManagerDriver_PasswordFormsRendered_Params_Data)");
        constexpr uint32_t kPasswordManagerDriver_PasswordFormSubmitted_Name = 2;
        class PasswordManagerDriver_PasswordFormSubmitted_Params_Data {
        public:
            static PasswordManagerDriver_PasswordFormSubmitted_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PasswordManagerDriver_PasswordFormSubmitted_Params_Data))) PasswordManagerDriver_PasswordFormSubmitted_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::autofill::mojom::internal::PasswordForm_Data> password_form;

        private:
            PasswordManagerDriver_PasswordFormSubmitted_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PasswordManagerDriver_PasswordFormSubmitted_Params_Data() = delete;
        };
        static_assert(sizeof(PasswordManagerDriver_PasswordFormSubmitted_Params_Data) == 16,
            "Bad sizeof(PasswordManagerDriver_PasswordFormSubmitted_Params_Data)");
        constexpr uint32_t kPasswordManagerDriver_InPageNavigation_Name = 3;
        class PasswordManagerDriver_InPageNavigation_Params_Data {
        public:
            static PasswordManagerDriver_InPageNavigation_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PasswordManagerDriver_InPageNavigation_Params_Data))) PasswordManagerDriver_InPageNavigation_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::autofill::mojom::internal::PasswordForm_Data> password_form;

        private:
            PasswordManagerDriver_InPageNavigation_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PasswordManagerDriver_InPageNavigation_Params_Data() = delete;
        };
        static_assert(sizeof(PasswordManagerDriver_InPageNavigation_Params_Data) == 16,
            "Bad sizeof(PasswordManagerDriver_InPageNavigation_Params_Data)");
        constexpr uint32_t kPasswordManagerDriver_RecordSavePasswordProgress_Name = 4;
        class PasswordManagerDriver_RecordSavePasswordProgress_Params_Data {
        public:
            static PasswordManagerDriver_RecordSavePasswordProgress_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PasswordManagerDriver_RecordSavePasswordProgress_Params_Data))) PasswordManagerDriver_RecordSavePasswordProgress_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> log;

        private:
            PasswordManagerDriver_RecordSavePasswordProgress_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PasswordManagerDriver_RecordSavePasswordProgress_Params_Data() = delete;
        };
        static_assert(sizeof(PasswordManagerDriver_RecordSavePasswordProgress_Params_Data) == 16,
            "Bad sizeof(PasswordManagerDriver_RecordSavePasswordProgress_Params_Data)");
        constexpr uint32_t kPasswordManagerDriver_ShowPasswordSuggestions_Name = 5;
        class PasswordManagerDriver_ShowPasswordSuggestions_Params_Data {
        public:
            static PasswordManagerDriver_ShowPasswordSuggestions_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PasswordManagerDriver_ShowPasswordSuggestions_Params_Data))) PasswordManagerDriver_ShowPasswordSuggestions_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t key;
            int32_t text_direction;
            mojo::internal::Pointer<::mojo::common::mojom::internal::String16_Data> typed_username;
            int32_t options;
            uint8_t pad3_[4];
            mojo::internal::Pointer<::gfx::mojom::internal::RectF_Data> bounds;

        private:
            PasswordManagerDriver_ShowPasswordSuggestions_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PasswordManagerDriver_ShowPasswordSuggestions_Params_Data() = delete;
        };
        static_assert(sizeof(PasswordManagerDriver_ShowPasswordSuggestions_Params_Data) == 40,
            "Bad sizeof(PasswordManagerDriver_ShowPasswordSuggestions_Params_Data)");
        constexpr uint32_t kPasswordManagerDriver_ShowNotSecureWarning_Name = 6;
        class PasswordManagerDriver_ShowNotSecureWarning_Params_Data {
        public:
            static PasswordManagerDriver_ShowNotSecureWarning_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PasswordManagerDriver_ShowNotSecureWarning_Params_Data))) PasswordManagerDriver_ShowNotSecureWarning_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t text_direction;
            uint8_t pad0_[4];
            mojo::internal::Pointer<::gfx::mojom::internal::RectF_Data> bounds;

        private:
            PasswordManagerDriver_ShowNotSecureWarning_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PasswordManagerDriver_ShowNotSecureWarning_Params_Data() = delete;
        };
        static_assert(sizeof(PasswordManagerDriver_ShowNotSecureWarning_Params_Data) == 24,
            "Bad sizeof(PasswordManagerDriver_ShowNotSecureWarning_Params_Data)");
        constexpr uint32_t kPasswordManagerDriver_PresaveGeneratedPassword_Name = 7;
        class PasswordManagerDriver_PresaveGeneratedPassword_Params_Data {
        public:
            static PasswordManagerDriver_PresaveGeneratedPassword_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PasswordManagerDriver_PresaveGeneratedPassword_Params_Data))) PasswordManagerDriver_PresaveGeneratedPassword_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::autofill::mojom::internal::PasswordForm_Data> password_form;

        private:
            PasswordManagerDriver_PresaveGeneratedPassword_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PasswordManagerDriver_PresaveGeneratedPassword_Params_Data() = delete;
        };
        static_assert(sizeof(PasswordManagerDriver_PresaveGeneratedPassword_Params_Data) == 16,
            "Bad sizeof(PasswordManagerDriver_PresaveGeneratedPassword_Params_Data)");
        constexpr uint32_t kPasswordManagerDriver_PasswordNoLongerGenerated_Name = 8;
        class PasswordManagerDriver_PasswordNoLongerGenerated_Params_Data {
        public:
            static PasswordManagerDriver_PasswordNoLongerGenerated_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PasswordManagerDriver_PasswordNoLongerGenerated_Params_Data))) PasswordManagerDriver_PasswordNoLongerGenerated_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::autofill::mojom::internal::PasswordForm_Data> password_form;

        private:
            PasswordManagerDriver_PasswordNoLongerGenerated_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PasswordManagerDriver_PasswordNoLongerGenerated_Params_Data() = delete;
        };
        static_assert(sizeof(PasswordManagerDriver_PasswordNoLongerGenerated_Params_Data) == 16,
            "Bad sizeof(PasswordManagerDriver_PasswordNoLongerGenerated_Params_Data)");
        constexpr uint32_t kPasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_Name = 9;
        class PasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_Params_Data {
        public:
            static PasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_Params_Data))) PasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::autofill::mojom::internal::PasswordForm_Data> password_form;
            mojo::internal::Pointer<::mojo::common::mojom::internal::String16_Data> generation_field;

        private:
            PasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_Params_Data() = delete;
        };
        static_assert(sizeof(PasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_Params_Data) == 24,
            "Bad sizeof(PasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_Params_Data)");
        constexpr uint32_t kPasswordManagerClient_GenerationAvailableForForm_Name = 0;
        class PasswordManagerClient_GenerationAvailableForForm_Params_Data {
        public:
            static PasswordManagerClient_GenerationAvailableForForm_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PasswordManagerClient_GenerationAvailableForForm_Params_Data))) PasswordManagerClient_GenerationAvailableForForm_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::autofill::mojom::internal::PasswordForm_Data> password_form;

        private:
            PasswordManagerClient_GenerationAvailableForForm_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PasswordManagerClient_GenerationAvailableForForm_Params_Data() = delete;
        };
        static_assert(sizeof(PasswordManagerClient_GenerationAvailableForForm_Params_Data) == 16,
            "Bad sizeof(PasswordManagerClient_GenerationAvailableForForm_Params_Data)");
        constexpr uint32_t kPasswordManagerClient_ShowPasswordGenerationPopup_Name = 1;
        class PasswordManagerClient_ShowPasswordGenerationPopup_Params_Data {
        public:
            static PasswordManagerClient_ShowPasswordGenerationPopup_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PasswordManagerClient_ShowPasswordGenerationPopup_Params_Data))) PasswordManagerClient_ShowPasswordGenerationPopup_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::gfx::mojom::internal::RectF_Data> bounds;
            int32_t max_length;
            uint8_t is_manually_triggered : 1;
            uint8_t pad2_[3];
            mojo::internal::Pointer<::mojo::common::mojom::internal::String16_Data> generation_element;
            mojo::internal::Pointer<::autofill::mojom::internal::PasswordForm_Data> password_form;

        private:
            PasswordManagerClient_ShowPasswordGenerationPopup_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PasswordManagerClient_ShowPasswordGenerationPopup_Params_Data() = delete;
        };
        static_assert(sizeof(PasswordManagerClient_ShowPasswordGenerationPopup_Params_Data) == 40,
            "Bad sizeof(PasswordManagerClient_ShowPasswordGenerationPopup_Params_Data)");
        constexpr uint32_t kPasswordManagerClient_ShowPasswordEditingPopup_Name = 2;
        class PasswordManagerClient_ShowPasswordEditingPopup_Params_Data {
        public:
            static PasswordManagerClient_ShowPasswordEditingPopup_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PasswordManagerClient_ShowPasswordEditingPopup_Params_Data))) PasswordManagerClient_ShowPasswordEditingPopup_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::gfx::mojom::internal::RectF_Data> bounds;
            mojo::internal::Pointer<::autofill::mojom::internal::PasswordForm_Data> password_form;

        private:
            PasswordManagerClient_ShowPasswordEditingPopup_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PasswordManagerClient_ShowPasswordEditingPopup_Params_Data() = delete;
        };
        static_assert(sizeof(PasswordManagerClient_ShowPasswordEditingPopup_Params_Data) == 24,
            "Bad sizeof(PasswordManagerClient_ShowPasswordEditingPopup_Params_Data)");
        constexpr uint32_t kPasswordManagerClient_HidePasswordGenerationPopup_Name = 3;
        class PasswordManagerClient_HidePasswordGenerationPopup_Params_Data {
        public:
            static PasswordManagerClient_HidePasswordGenerationPopup_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PasswordManagerClient_HidePasswordGenerationPopup_Params_Data))) PasswordManagerClient_HidePasswordGenerationPopup_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            PasswordManagerClient_HidePasswordGenerationPopup_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PasswordManagerClient_HidePasswordGenerationPopup_Params_Data() = delete;
        };
        static_assert(sizeof(PasswordManagerClient_HidePasswordGenerationPopup_Params_Data) == 8,
            "Bad sizeof(PasswordManagerClient_HidePasswordGenerationPopup_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace autofill

#endif // COMPONENTS_AUTOFILL_CONTENT_COMMON_AUTOFILL_DRIVER_MOJOM_SHARED_INTERNAL_H_