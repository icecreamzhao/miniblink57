// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_AUTOFILL_CONTENT_COMMON_AUTOFILL_TYPES_MOJOM_SHARED_INTERNAL_H_
#define COMPONENTS_AUTOFILL_CONTENT_COMMON_AUTOFILL_TYPES_MOJOM_SHARED_INTERNAL_H_

#include <stdint.h>

#include "mojo/common/text_direction.mojom-shared-internal.h"
#include "mojo/common/time.mojom-shared-internal.h"
#include "mojo/public/cpp/bindings/lib/array_internal.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/buffer.h"
#include "mojo/public/cpp/bindings/lib/map_data_internal.h"
#include "mojo/public/cpp/bindings/lib/native_enum_data.h"
#include "mojo/public/cpp/bindings/lib/native_struct_data.h"
#include "url/mojo/origin.mojom-shared-internal.h"
#include "url/mojo/url.mojom-shared-internal.h"

namespace mojo {
namespace internal {
    class ValidationContext;
}
}
namespace autofill {
namespace mojom {
    namespace internal {
        class FormFieldData_Data;
        class FormData_Data;
        class FormFieldDataPredictions_Data;
        class FormDataPredictions_Data;
        class PasswordAndRealm_Data;
        class UsernamesCollectionKey_Data;
        class PasswordFormFillData_Data;
        class PasswordFormGenerationData_Data;
        class PasswordForm_Data;
        class PasswordFormFieldPredictionMap_Data;
        class FormsPredictionsMap_Data;

        struct CheckStatus_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                case 2:
                    return true;
                }
                return false;
            }

            static bool Validate(int32_t value,
                mojo::internal::ValidationContext* validation_context)
            {
                if (kIsExtensible || IsKnownValue(value))
                    return true;

                ReportValidationError(validation_context,
                    mojo::internal::VALIDATION_ERROR_UNKNOWN_ENUM_VALUE);
                return false;
            }
        };

        struct RoleAttribute_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                    return true;
                }
                return false;
            }

            static bool Validate(int32_t value,
                mojo::internal::ValidationContext* validation_context)
            {
                if (kIsExtensible || IsKnownValue(value))
                    return true;

                ReportValidationError(validation_context,
                    mojo::internal::VALIDATION_ERROR_UNKNOWN_ENUM_VALUE);
                return false;
            }
        };

        struct GenerationUploadStatus_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                case 2:
                case 10:
                    return true;
                }
                return false;
            }

            static bool Validate(int32_t value,
                mojo::internal::ValidationContext* validation_context)
            {
                if (kIsExtensible || IsKnownValue(value))
                    return true;

                ReportValidationError(validation_context,
                    mojo::internal::VALIDATION_ERROR_UNKNOWN_ENUM_VALUE);
                return false;
            }
        };

        struct PasswordFormLayout_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                    return true;
                }
                return false;
            }

            static bool Validate(int32_t value,
                mojo::internal::ValidationContext* validation_context)
            {
                if (kIsExtensible || IsKnownValue(value))
                    return true;

                ReportValidationError(validation_context,
                    mojo::internal::VALIDATION_ERROR_UNKNOWN_ENUM_VALUE);
                return false;
            }
        };

        struct PasswordFormType_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                case 2:
                    return true;
                }
                return false;
            }

            static bool Validate(int32_t value,
                mojo::internal::ValidationContext* validation_context)
            {
                if (kIsExtensible || IsKnownValue(value))
                    return true;

                ReportValidationError(validation_context,
                    mojo::internal::VALIDATION_ERROR_UNKNOWN_ENUM_VALUE);
                return false;
            }
        };

        struct PasswordFormScheme_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                case 2:
                case 3:
                case 4:
                    return true;
                }
                return false;
            }

            static bool Validate(int32_t value,
                mojo::internal::ValidationContext* validation_context)
            {
                if (kIsExtensible || IsKnownValue(value))
                    return true;

                ReportValidationError(validation_context,
                    mojo::internal::VALIDATION_ERROR_UNKNOWN_ENUM_VALUE);
                return false;
            }
        };

        struct PasswordFormFieldPredictionType_Data {
        public:
            static bool constexpr kIsExtensible = false;

            static bool IsKnownValue(int32_t value)
            {
                switch (value) {
                case 0:
                case 1:
                case 2:
                case 3:
                    return true;
                }
                return false;
            }

            static bool Validate(int32_t value,
                mojo::internal::ValidationContext* validation_context)
            {
                if (kIsExtensible || IsKnownValue(value))
                    return true;

                ReportValidationError(validation_context,
                    mojo::internal::VALIDATION_ERROR_UNKNOWN_ENUM_VALUE);
                return false;
            }
        };

#pragma pack(push, 1)
        class FormFieldData_Data {
        public:
            static FormFieldData_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(FormFieldData_Data))) FormFieldData_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> label;
            mojo::internal::Pointer<mojo::internal::String_Data> name;
            mojo::internal::Pointer<mojo::internal::String_Data> value;
            mojo::internal::Pointer<mojo::internal::String_Data> form_control_type;
            mojo::internal::Pointer<mojo::internal::String_Data> autocomplete_attribute;
            mojo::internal::Pointer<mojo::internal::String_Data> placeholder;
            mojo::internal::Pointer<mojo::internal::String_Data> css_classes;
            uint32_t properties_mask;
            uint8_t is_autofilled : 1;
            uint8_t is_focusable : 1;
            uint8_t should_autocomplete : 1;
            uint8_t pad10_[3];
            uint64_t max_length;
            int32_t check_status;
            int32_t role;
            int32_t text_direction;
            uint8_t pad14_[4];
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<mojo::internal::String_Data>>> option_values;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<mojo::internal::String_Data>>> option_contents;

        private:
            FormFieldData_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~FormFieldData_Data() = delete;
        };
        static_assert(sizeof(FormFieldData_Data) == 112,
            "Bad sizeof(FormFieldData_Data)");
        class FormData_Data {
        public:
            static FormData_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(FormData_Data))) FormData_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> name;
            mojo::internal::Pointer<::url::mojom::internal::Url_Data> origin;
            mojo::internal::Pointer<::url::mojom::internal::Url_Data> action;
            uint8_t is_form_tag : 1;
            uint8_t is_formless_checkout : 1;
            uint8_t pad4_[7];
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::FormFieldData_Data>>> fields;

        private:
            FormData_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~FormData_Data() = delete;
        };
        static_assert(sizeof(FormData_Data) == 48,
            "Bad sizeof(FormData_Data)");
        class FormFieldDataPredictions_Data {
        public:
            static FormFieldDataPredictions_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(FormFieldDataPredictions_Data))) FormFieldDataPredictions_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::FormFieldData_Data> field;
            mojo::internal::Pointer<mojo::internal::String_Data> signature;
            mojo::internal::Pointer<mojo::internal::String_Data> heuristic_type;
            mojo::internal::Pointer<mojo::internal::String_Data> server_type;
            mojo::internal::Pointer<mojo::internal::String_Data> overall_type;
            mojo::internal::Pointer<mojo::internal::String_Data> parseable_name;

        private:
            FormFieldDataPredictions_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~FormFieldDataPredictions_Data() = delete;
        };
        static_assert(sizeof(FormFieldDataPredictions_Data) == 56,
            "Bad sizeof(FormFieldDataPredictions_Data)");
        class FormDataPredictions_Data {
        public:
            static FormDataPredictions_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(FormDataPredictions_Data))) FormDataPredictions_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<internal::FormData_Data> data;
            mojo::internal::Pointer<mojo::internal::String_Data> signature;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::FormFieldDataPredictions_Data>>> fields;

        private:
            FormDataPredictions_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~FormDataPredictions_Data() = delete;
        };
        static_assert(sizeof(FormDataPredictions_Data) == 32,
            "Bad sizeof(FormDataPredictions_Data)");
        class PasswordAndRealm_Data {
        public:
            static PasswordAndRealm_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PasswordAndRealm_Data))) PasswordAndRealm_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> password;
            mojo::internal::Pointer<mojo::internal::String_Data> realm;

        private:
            PasswordAndRealm_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PasswordAndRealm_Data() = delete;
        };
        static_assert(sizeof(PasswordAndRealm_Data) == 24,
            "Bad sizeof(PasswordAndRealm_Data)");
        class UsernamesCollectionKey_Data {
        public:
            static UsernamesCollectionKey_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(UsernamesCollectionKey_Data))) UsernamesCollectionKey_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> username;
            mojo::internal::Pointer<mojo::internal::String_Data> password;
            mojo::internal::Pointer<mojo::internal::String_Data> realm;

        private:
            UsernamesCollectionKey_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~UsernamesCollectionKey_Data() = delete;
        };
        static_assert(sizeof(UsernamesCollectionKey_Data) == 32,
            "Bad sizeof(UsernamesCollectionKey_Data)");
        class PasswordFormFillData_Data {
        public:
            static PasswordFormFillData_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PasswordFormFillData_Data))) PasswordFormFillData_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::String_Data> name;
            mojo::internal::Pointer<::url::mojom::internal::Url_Data> origin;
            mojo::internal::Pointer<::url::mojom::internal::Url_Data> action;
            mojo::internal::Pointer<internal::FormFieldData_Data> username_field;
            mojo::internal::Pointer<internal::FormFieldData_Data> password_field;
            mojo::internal::Pointer<mojo::internal::String_Data> preferred_realm;
            mojo::internal::Pointer<mojo::internal::Map_Data<mojo::internal::Pointer<mojo::internal::String_Data>, mojo::internal::Pointer<internal::PasswordAndRealm_Data>>> additional_logins;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::UsernamesCollectionKey_Data>>> other_possible_usernames_keys;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<mojo::internal::String_Data>>>>> other_possible_usernames_values;
            uint8_t wait_for_username : 1;
            uint8_t is_possible_change_password_form : 1;
            uint8_t padfinal_[7];

        private:
            PasswordFormFillData_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PasswordFormFillData_Data() = delete;
        };
        static_assert(sizeof(PasswordFormFillData_Data) == 88,
            "Bad sizeof(PasswordFormFillData_Data)");
        class PasswordFormGenerationData_Data {
        public:
            static PasswordFormGenerationData_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PasswordFormGenerationData_Data))) PasswordFormGenerationData_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            uint64_t form_signature;
            uint32_t field_signature;
            uint8_t padfinal_[4];

        private:
            PasswordFormGenerationData_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PasswordFormGenerationData_Data() = delete;
        };
        static_assert(sizeof(PasswordFormGenerationData_Data) == 24,
            "Bad sizeof(PasswordFormGenerationData_Data)");
        class PasswordForm_Data {
        public:
            static PasswordForm_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PasswordForm_Data))) PasswordForm_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            int32_t scheme;
            uint8_t username_marked_by_site : 1;
            uint8_t password_value_is_default : 1;
            uint8_t new_password_value_is_default : 1;
            uint8_t new_password_marked_by_site : 1;
            uint8_t preferred : 1;
            uint8_t blacklisted_by_user : 1;
            uint8_t skip_zero_click : 1;
            uint8_t was_parsed_using_autofill_predictions : 1;
            uint8_t is_public_suffix_match : 1;
            uint8_t is_affiliation_based_match : 1;
            uint8_t does_look_like_signup_form : 1;
            uint8_t pad11_[2];
            mojo::internal::Pointer<mojo::internal::String_Data> signon_realm;
            mojo::internal::Pointer<::url::mojom::internal::Url_Data> origin_with_path;
            mojo::internal::Pointer<::url::mojom::internal::Url_Data> action;
            mojo::internal::Pointer<mojo::internal::String_Data> affiliated_web_realm;
            mojo::internal::Pointer<mojo::internal::String_Data> submit_element;
            mojo::internal::Pointer<mojo::internal::String_Data> username_element;
            mojo::internal::Pointer<mojo::internal::String_Data> username_value;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<mojo::internal::String_Data>>> other_possible_usernames;
            mojo::internal::Pointer<mojo::internal::String_Data> password_element;
            mojo::internal::Pointer<mojo::internal::String_Data> password_value;
            mojo::internal::Pointer<mojo::internal::String_Data> new_password_element;
            mojo::internal::Pointer<mojo::internal::String_Data> new_password_value;
            mojo::internal::Pointer<::mojo::common::mojom::internal::Time_Data> date_created;
            mojo::internal::Pointer<::mojo::common::mojom::internal::Time_Data> date_synced;
            int32_t type;
            int32_t times_used;
            mojo::internal::Pointer<internal::FormData_Data> form_data;
            int32_t generation_upload_status;
            int32_t layout;
            mojo::internal::Pointer<mojo::internal::String_Data> display_name;
            mojo::internal::Pointer<::url::mojom::internal::Url_Data> icon_url;
            mojo::internal::Pointer<::url::mojom::internal::Origin_Data> federation_origin;

        private:
            PasswordForm_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PasswordForm_Data() = delete;
        };
        static_assert(sizeof(PasswordForm_Data) == 176,
            "Bad sizeof(PasswordForm_Data)");
        class PasswordFormFieldPredictionMap_Data {
        public:
            static PasswordFormFieldPredictionMap_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(PasswordFormFieldPredictionMap_Data))) PasswordFormFieldPredictionMap_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::FormFieldData_Data>>> keys;
            mojo::internal::Pointer<mojo::internal::Array_Data<int32_t>> values;

        private:
            PasswordFormFieldPredictionMap_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~PasswordFormFieldPredictionMap_Data() = delete;
        };
        static_assert(sizeof(PasswordFormFieldPredictionMap_Data) == 24,
            "Bad sizeof(PasswordFormFieldPredictionMap_Data)");
        class FormsPredictionsMap_Data {
        public:
            static FormsPredictionsMap_Data* New(mojo::internal::Buffer* buf)
            {
                return new (buf->Allocate(sizeof(FormsPredictionsMap_Data))) FormsPredictionsMap_Data();
            }

            static bool Validate(const void* data,
                mojo::internal::ValidationContext* validation_context);

            mojo::internal::StructHeader header_;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::FormData_Data>>> keys;
            mojo::internal::Pointer<mojo::internal::Array_Data<mojo::internal::Pointer<internal::PasswordFormFieldPredictionMap_Data>>> values;

        private:
            FormsPredictionsMap_Data()
                : header_({ sizeof(*this), 0 })
            {
            }
            ~FormsPredictionsMap_Data() = delete;
        };
        static_assert(sizeof(FormsPredictionsMap_Data) == 24,
            "Bad sizeof(FormsPredictionsMap_Data)");

#pragma pack(pop)

    } // namespace internal
} // namespace mojom
} // namespace autofill

#endif // COMPONENTS_AUTOFILL_CONTENT_COMMON_AUTOFILL_TYPES_MOJOM_SHARED_INTERNAL_H_