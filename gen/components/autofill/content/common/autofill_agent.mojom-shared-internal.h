// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_AUTOFILL_CONTENT_COMMON_AUTOFILL_AGENT_MOJOM_SHARED_INTERNAL_H_
#define COMPONENTS_AUTOFILL_CONTENT_COMMON_AUTOFILL_AGENT_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "components/autofill/content/common/autofill_types.mojom-shared-internal.h"
#include "mojo/common/string16.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace autofill {
namespace mojom {
    namespace internal {

#pragma pack(push, 1)
        constexpr uint32_t kAutofillAgent_FirstUserGestureObservedInTab_Name = 0;
        class AutofillAgent_FirstUserGestureObservedInTab_Params_Data {
        public:
            static AutofillAgent_FirstUserGestureObservedInTab_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AutofillAgent_FirstUserGestureObservedInTab_Params_Data))) AutofillAgent_FirstUserGestureObservedInTab_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            AutofillAgent_FirstUserGestureObservedInTab_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AutofillAgent_FirstUserGestureObservedInTab_Params_Data() = delete;
        };
        static_assert(sizeof(AutofillAgent_FirstUserGestureObservedInTab_Params_Data) == 8,
            "Bad sizeof(AutofillAgent_FirstUserGestureObservedInTab_Params_Data)");
        constexpr uint32_t kAutofillAgent_FillForm_Name = 1;
        class AutofillAgent_FillForm_Params_Data {
        public:
            static AutofillAgent_FillForm_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AutofillAgent_FillForm_Params_Data))) AutofillAgent_FillForm_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t id;
            uint8_t pad0_[4];
            mojo::internal::Pointer<::autofill::mojom::internal::FormData_Data> form;

        private:
            AutofillAgent_FillForm_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AutofillAgent_FillForm_Params_Data() = delete;
        };
        static_assert(sizeof(AutofillAgent_FillForm_Params_Data) == 24,
            "Bad sizeof(AutofillAgent_FillForm_Params_Data)");
        constexpr uint32_t kAutofillAgent_PreviewForm_Name = 2;
        class AutofillAgent_PreviewForm_Params_Data {
        public:
            static AutofillAgent_PreviewForm_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AutofillAgent_PreviewForm_Params_Data))) AutofillAgent_PreviewForm_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t id;
            uint8_t pad0_[4];
            mojo::internal::Pointer<::autofill::mojom::internal::FormData_Data> form;

        private:
            AutofillAgent_PreviewForm_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AutofillAgent_PreviewForm_Params_Data() = delete;
        };
        static_assert(sizeof(AutofillAgent_PreviewForm_Params_Data) == 24,
            "Bad sizeof(AutofillAgent_PreviewForm_Params_Data)");
        constexpr uint32_t kAutofillAgent_FieldTypePredictionsAvailable_Name = 3;
        class AutofillAgent_FieldTypePredictionsAvailable_Params_Data {
        public:
            static AutofillAgent_FieldTypePredictionsAvailable_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AutofillAgent_FieldTypePredictionsAvailable_Params_Data))) AutofillAgent_FieldTypePredictionsAvailable_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::autofill::mojom::internal::FormDataPredictions_Data>>> forms;

        private:
            AutofillAgent_FieldTypePredictionsAvailable_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AutofillAgent_FieldTypePredictionsAvailable_Params_Data() = delete;
        };
        static_assert(sizeof(AutofillAgent_FieldTypePredictionsAvailable_Params_Data) == 16,
            "Bad sizeof(AutofillAgent_FieldTypePredictionsAvailable_Params_Data)");
        constexpr uint32_t kAutofillAgent_ClearForm_Name = 4;
        class AutofillAgent_ClearForm_Params_Data {
        public:
            static AutofillAgent_ClearForm_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AutofillAgent_ClearForm_Params_Data))) AutofillAgent_ClearForm_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            AutofillAgent_ClearForm_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AutofillAgent_ClearForm_Params_Data() = delete;
        };
        static_assert(sizeof(AutofillAgent_ClearForm_Params_Data) == 8,
            "Bad sizeof(AutofillAgent_ClearForm_Params_Data)");
        constexpr uint32_t kAutofillAgent_ClearPreviewedForm_Name = 5;
        class AutofillAgent_ClearPreviewedForm_Params_Data {
        public:
            static AutofillAgent_ClearPreviewedForm_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AutofillAgent_ClearPreviewedForm_Params_Data))) AutofillAgent_ClearPreviewedForm_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            AutofillAgent_ClearPreviewedForm_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AutofillAgent_ClearPreviewedForm_Params_Data() = delete;
        };
        static_assert(sizeof(AutofillAgent_ClearPreviewedForm_Params_Data) == 8,
            "Bad sizeof(AutofillAgent_ClearPreviewedForm_Params_Data)");
        constexpr uint32_t kAutofillAgent_FillFieldWithValue_Name = 6;
        class AutofillAgent_FillFieldWithValue_Params_Data {
        public:
            static AutofillAgent_FillFieldWithValue_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AutofillAgent_FillFieldWithValue_Params_Data))) AutofillAgent_FillFieldWithValue_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::mojo::common::mojom::internal::String16_Data> value;

        private:
            AutofillAgent_FillFieldWithValue_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AutofillAgent_FillFieldWithValue_Params_Data() = delete;
        };
        static_assert(sizeof(AutofillAgent_FillFieldWithValue_Params_Data) == 16,
            "Bad sizeof(AutofillAgent_FillFieldWithValue_Params_Data)");
        constexpr uint32_t kAutofillAgent_PreviewFieldWithValue_Name = 7;
        class AutofillAgent_PreviewFieldWithValue_Params_Data {
        public:
            static AutofillAgent_PreviewFieldWithValue_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AutofillAgent_PreviewFieldWithValue_Params_Data))) AutofillAgent_PreviewFieldWithValue_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::mojo::common::mojom::internal::String16_Data> value;

        private:
            AutofillAgent_PreviewFieldWithValue_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AutofillAgent_PreviewFieldWithValue_Params_Data() = delete;
        };
        static_assert(sizeof(AutofillAgent_PreviewFieldWithValue_Params_Data) == 16,
            "Bad sizeof(AutofillAgent_PreviewFieldWithValue_Params_Data)");
        constexpr uint32_t kAutofillAgent_AcceptDataListSuggestion_Name = 8;
        class AutofillAgent_AcceptDataListSuggestion_Params_Data {
        public:
            static AutofillAgent_AcceptDataListSuggestion_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AutofillAgent_AcceptDataListSuggestion_Params_Data))) AutofillAgent_AcceptDataListSuggestion_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::mojo::common::mojom::internal::String16_Data> value;

        private:
            AutofillAgent_AcceptDataListSuggestion_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AutofillAgent_AcceptDataListSuggestion_Params_Data() = delete;
        };
        static_assert(sizeof(AutofillAgent_AcceptDataListSuggestion_Params_Data) == 16,
            "Bad sizeof(AutofillAgent_AcceptDataListSuggestion_Params_Data)");
        constexpr uint32_t kAutofillAgent_FillPasswordSuggestion_Name = 9;
        class AutofillAgent_FillPasswordSuggestion_Params_Data {
        public:
            static AutofillAgent_FillPasswordSuggestion_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AutofillAgent_FillPasswordSuggestion_Params_Data))) AutofillAgent_FillPasswordSuggestion_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::mojo::common::mojom::internal::String16_Data> username;
            mojo::internal::Pointer<::mojo::common::mojom::internal::String16_Data> password;

        private:
            AutofillAgent_FillPasswordSuggestion_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AutofillAgent_FillPasswordSuggestion_Params_Data() = delete;
        };
        static_assert(sizeof(AutofillAgent_FillPasswordSuggestion_Params_Data) == 24,
            "Bad sizeof(AutofillAgent_FillPasswordSuggestion_Params_Data)");
        constexpr uint32_t kAutofillAgent_PreviewPasswordSuggestion_Name = 10;
        class AutofillAgent_PreviewPasswordSuggestion_Params_Data {
        public:
            static AutofillAgent_PreviewPasswordSuggestion_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AutofillAgent_PreviewPasswordSuggestion_Params_Data))) AutofillAgent_PreviewPasswordSuggestion_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::mojo::common::mojom::internal::String16_Data> username;
            mojo::internal::Pointer<::mojo::common::mojom::internal::String16_Data> password;

        private:
            AutofillAgent_PreviewPasswordSuggestion_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AutofillAgent_PreviewPasswordSuggestion_Params_Data() = delete;
        };
        static_assert(sizeof(AutofillAgent_PreviewPasswordSuggestion_Params_Data) == 24,
            "Bad sizeof(AutofillAgent_PreviewPasswordSuggestion_Params_Data)");
        constexpr uint32_t kAutofillAgent_ShowInitialPasswordAccountSuggestions_Name = 11;
        class AutofillAgent_ShowInitialPasswordAccountSuggestions_Params_Data {
        public:
            static AutofillAgent_ShowInitialPasswordAccountSuggestions_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(AutofillAgent_ShowInitialPasswordAccountSuggestions_Params_Data))) AutofillAgent_ShowInitialPasswordAccountSuggestions_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t key;
            uint8_t pad0_[4];
            mojo::internal::Pointer<::autofill::mojom::internal::PasswordFormFillData_Data> form_data;

        private:
            AutofillAgent_ShowInitialPasswordAccountSuggestions_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~AutofillAgent_ShowInitialPasswordAccountSuggestions_Params_Data() = delete;
        };
        static_assert(sizeof(AutofillAgent_ShowInitialPasswordAccountSuggestions_Params_Data) == 24,
            "Bad sizeof(AutofillAgent_ShowInitialPasswordAccountSuggestions_Params_Data)");
        constexpr uint32_t kPasswordAutofillAgent_FillPasswordForm_Name = 0;
        class PasswordAutofillAgent_FillPasswordForm_Params_Data {
        public:
            static PasswordAutofillAgent_FillPasswordForm_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PasswordAutofillAgent_FillPasswordForm_Params_Data))) PasswordAutofillAgent_FillPasswordForm_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t key;
            uint8_t pad0_[4];
            mojo::internal::Pointer<::autofill::mojom::internal::PasswordFormFillData_Data> form_data;

        private:
            PasswordAutofillAgent_FillPasswordForm_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PasswordAutofillAgent_FillPasswordForm_Params_Data() = delete;
        };
        static_assert(sizeof(PasswordAutofillAgent_FillPasswordForm_Params_Data) == 24,
            "Bad sizeof(PasswordAutofillAgent_FillPasswordForm_Params_Data)");
        constexpr uint32_t kPasswordAutofillAgent_SetLoggingState_Name = 1;
        class PasswordAutofillAgent_SetLoggingState_Params_Data {
        public:
            static PasswordAutofillAgent_SetLoggingState_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PasswordAutofillAgent_SetLoggingState_Params_Data))) PasswordAutofillAgent_SetLoggingState_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint8_t active : 1;
            uint8_t padfinal_[7];

        private:
            PasswordAutofillAgent_SetLoggingState_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PasswordAutofillAgent_SetLoggingState_Params_Data() = delete;
        };
        static_assert(sizeof(PasswordAutofillAgent_SetLoggingState_Params_Data) == 16,
            "Bad sizeof(PasswordAutofillAgent_SetLoggingState_Params_Data)");
        constexpr uint32_t kPasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_Name = 2;
        class PasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_Params_Data {
        public:
            static PasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_Params_Data))) PasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::autofill::mojom::internal::FormsPredictionsMap_Data> predictions;

        private:
            PasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_Params_Data() = delete;
        };
        static_assert(sizeof(PasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_Params_Data) == 16,
            "Bad sizeof(PasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_Params_Data)");
        constexpr uint32_t kPasswordAutofillAgent_FindFocusedPasswordForm_Name = 3;
        class PasswordAutofillAgent_FindFocusedPasswordForm_Params_Data {
        public:
            static PasswordAutofillAgent_FindFocusedPasswordForm_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PasswordAutofillAgent_FindFocusedPasswordForm_Params_Data))) PasswordAutofillAgent_FindFocusedPasswordForm_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            PasswordAutofillAgent_FindFocusedPasswordForm_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PasswordAutofillAgent_FindFocusedPasswordForm_Params_Data() = delete;
        };
        static_assert(sizeof(PasswordAutofillAgent_FindFocusedPasswordForm_Params_Data) == 8,
            "Bad sizeof(PasswordAutofillAgent_FindFocusedPasswordForm_Params_Data)");
        class PasswordAutofillAgent_FindFocusedPasswordForm_ResponseParams_Data {
        public:
            static PasswordAutofillAgent_FindFocusedPasswordForm_ResponseParams_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PasswordAutofillAgent_FindFocusedPasswordForm_ResponseParams_Data))) PasswordAutofillAgent_FindFocusedPasswordForm_ResponseParams_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::autofill::mojom::internal::PasswordForm_Data> form;

        private:
            PasswordAutofillAgent_FindFocusedPasswordForm_ResponseParams_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PasswordAutofillAgent_FindFocusedPasswordForm_ResponseParams_Data() = delete;
        };
        static_assert(sizeof(PasswordAutofillAgent_FindFocusedPasswordForm_ResponseParams_Data) == 16,
            "Bad sizeof(PasswordAutofillAgent_FindFocusedPasswordForm_ResponseParams_Data)");
        constexpr uint32_t kPasswordGenerationAgent_GeneratedPasswordAccepted_Name = 0;
        class PasswordGenerationAgent_GeneratedPasswordAccepted_Params_Data {
        public:
            static PasswordGenerationAgent_GeneratedPasswordAccepted_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PasswordGenerationAgent_GeneratedPasswordAccepted_Params_Data))) PasswordGenerationAgent_GeneratedPasswordAccepted_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::mojo::common::mojom::internal::String16_Data> generated_password;

        private:
            PasswordGenerationAgent_GeneratedPasswordAccepted_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PasswordGenerationAgent_GeneratedPasswordAccepted_Params_Data() = delete;
        };
        static_assert(sizeof(PasswordGenerationAgent_GeneratedPasswordAccepted_Params_Data) == 16,
            "Bad sizeof(PasswordGenerationAgent_GeneratedPasswordAccepted_Params_Data)");
        constexpr uint32_t kPasswordGenerationAgent_UserTriggeredGeneratePassword_Name = 1;
        class PasswordGenerationAgent_UserTriggeredGeneratePassword_Params_Data {
        public:
            static PasswordGenerationAgent_UserTriggeredGeneratePassword_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PasswordGenerationAgent_UserTriggeredGeneratePassword_Params_Data))) PasswordGenerationAgent_UserTriggeredGeneratePassword_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            PasswordGenerationAgent_UserTriggeredGeneratePassword_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PasswordGenerationAgent_UserTriggeredGeneratePassword_Params_Data() = delete;
        };
        static_assert(sizeof(PasswordGenerationAgent_UserTriggeredGeneratePassword_Params_Data) == 8,
            "Bad sizeof(PasswordGenerationAgent_UserTriggeredGeneratePassword_Params_Data)");
        constexpr uint32_t kPasswordGenerationAgent_FormNotBlacklisted_Name = 2;
        class PasswordGenerationAgent_FormNotBlacklisted_Params_Data {
        public:
            static PasswordGenerationAgent_FormNotBlacklisted_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PasswordGenerationAgent_FormNotBlacklisted_Params_Data))) PasswordGenerationAgent_FormNotBlacklisted_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<::autofill::mojom::internal::PasswordForm_Data> form;

        private:
            PasswordGenerationAgent_FormNotBlacklisted_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PasswordGenerationAgent_FormNotBlacklisted_Params_Data() = delete;
        };
        static_assert(sizeof(PasswordGenerationAgent_FormNotBlacklisted_Params_Data) == 16,
            "Bad sizeof(PasswordGenerationAgent_FormNotBlacklisted_Params_Data)");
        constexpr uint32_t kPasswordGenerationAgent_FoundFormsEligibleForGeneration_Name = 3;
        class PasswordGenerationAgent_FoundFormsEligibleForGeneration_Params_Data {
        public:
            static PasswordGenerationAgent_FoundFormsEligibleForGeneration_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PasswordGenerationAgent_FoundFormsEligibleForGeneration_Params_Data))) PasswordGenerationAgent_FoundFormsEligibleForGeneration_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<::autofill::mojom::internal::PasswordFormGenerationData_Data>>> forms;

        private:
            PasswordGenerationAgent_FoundFormsEligibleForGeneration_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PasswordGenerationAgent_FoundFormsEligibleForGeneration_Params_Data() = delete;
        };
        static_assert(sizeof(PasswordGenerationAgent_FoundFormsEligibleForGeneration_Params_Data) == 16,
            "Bad sizeof(PasswordGenerationAgent_FoundFormsEligibleForGeneration_Params_Data)");
        constexpr uint32_t kPasswordGenerationAgent_AllowToRunFormClassifier_Name = 4;
        class PasswordGenerationAgent_AllowToRunFormClassifier_Params_Data {
        public:
            static PasswordGenerationAgent_AllowToRunFormClassifier_Params_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PasswordGenerationAgent_AllowToRunFormClassifier_Params_Data))) PasswordGenerationAgent_AllowToRunFormClassifier_Params_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;

        private:
            PasswordGenerationAgent_AllowToRunFormClassifier_Params_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PasswordGenerationAgent_AllowToRunFormClassifier_Params_Data() = delete;
        };
        static_assert(sizeof(PasswordGenerationAgent_AllowToRunFormClassifier_Params_Data) == 8,
            "Bad sizeof(PasswordGenerationAgent_AllowToRunFormClassifier_Params_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace autofill

#endif // COMPONENTS_AUTOFILL_CONTENT_COMMON_AUTOFILL_AGENT_MOJOM_SHARED_INTERNAL_H_