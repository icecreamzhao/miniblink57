// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_AUTOFILL_CONTENT_COMMON_AUTOFILL_TYPES_MOJOM_H_
#define COMPONENTS_AUTOFILL_CONTENT_COMMON_AUTOFILL_TYPES_MOJOM_H_

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
#include "components/autofill/content/common/autofill_types.mojom-shared.h"
#include "components/autofill/core/common/form_data.h"
#include "components/autofill/core/common/form_data_predictions.h"
#include "components/autofill/core/common/form_field_data.h"
#include "components/autofill/core/common/form_field_data_predictions.h"
#include "components/autofill/core/common/password_form.h"
#include "components/autofill/core/common/password_form_field_prediction_map.h"
#include "components/autofill/core/common/password_form_fill_data.h"
#include "components/autofill/core/common/password_form_generation_data.h"
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
#include "url/gurl.h"
#include "url/mojo/origin.mojom.h"
#include "url/mojo/url.mojom.h"
#include "url/origin.h"
#include <string>
#include <vector>

namespace autofill {
namespace mojom {
    class FormFieldData;
    using FormFieldDataPtr = mojo::StructPtr<FormFieldData>;

    class FormData;
    using FormDataPtr = mojo::StructPtr<FormData>;

    class FormFieldDataPredictions;
    using FormFieldDataPredictionsPtr = mojo::StructPtr<FormFieldDataPredictions>;

    class FormDataPredictions;
    using FormDataPredictionsPtr = mojo::StructPtr<FormDataPredictions>;

    class PasswordAndRealm;
    using PasswordAndRealmPtr = mojo::InlinedStructPtr<PasswordAndRealm>;

    class UsernamesCollectionKey;
    using UsernamesCollectionKeyPtr = mojo::InlinedStructPtr<UsernamesCollectionKey>;

    class PasswordFormFillData;
    using PasswordFormFillDataPtr = mojo::StructPtr<PasswordFormFillData>;

    class PasswordFormGenerationData;
    using PasswordFormGenerationDataPtr = mojo::InlinedStructPtr<PasswordFormGenerationData>;

    class PasswordForm;
    using PasswordFormPtr = mojo::StructPtr<PasswordForm>;

    class PasswordFormFieldPredictionMap;
    using PasswordFormFieldPredictionMapPtr = mojo::StructPtr<PasswordFormFieldPredictionMap>;

    class FormsPredictionsMap;
    using FormsPredictionsMapPtr = mojo::StructPtr<FormsPredictionsMap>;

    class PasswordAndRealm {
    public:
        using DataView = PasswordAndRealmDataView;
        using Data_ = internal::PasswordAndRealm_Data;

        static PasswordAndRealmPtr New();

        template <typename U>
        static PasswordAndRealmPtr From(const U& u)
        {
            return mojo::TypeConverter<PasswordAndRealmPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, PasswordAndRealm>::Convert(*this);
        }

        PasswordAndRealm();
        ~PasswordAndRealm();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = PasswordAndRealmPtr>
        PasswordAndRealmPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, PasswordAndRealm>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                PasswordAndRealm::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                PasswordAndRealm::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::string password;
        std::string realm;
    };

    class UsernamesCollectionKey {
    public:
        using DataView = UsernamesCollectionKeyDataView;
        using Data_ = internal::UsernamesCollectionKey_Data;

        static UsernamesCollectionKeyPtr New();

        template <typename U>
        static UsernamesCollectionKeyPtr From(const U& u)
        {
            return mojo::TypeConverter<UsernamesCollectionKeyPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, UsernamesCollectionKey>::Convert(*this);
        }

        UsernamesCollectionKey();
        ~UsernamesCollectionKey();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = UsernamesCollectionKeyPtr>
        UsernamesCollectionKeyPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, UsernamesCollectionKey>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                UsernamesCollectionKey::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                UsernamesCollectionKey::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::string username;
        std::string password;
        std::string realm;
    };

    class PasswordFormGenerationData {
    public:
        using DataView = PasswordFormGenerationDataDataView;
        using Data_ = internal::PasswordFormGenerationData_Data;

        static PasswordFormGenerationDataPtr New();

        template <typename U>
        static PasswordFormGenerationDataPtr From(const U& u)
        {
            return mojo::TypeConverter<PasswordFormGenerationDataPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, PasswordFormGenerationData>::Convert(*this);
        }

        PasswordFormGenerationData();
        ~PasswordFormGenerationData();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = PasswordFormGenerationDataPtr>
        PasswordFormGenerationDataPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, PasswordFormGenerationData>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                PasswordFormGenerationData::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                PasswordFormGenerationData::DataView, std::vector<uint8_t>>(
                input, output);
        }

        uint64_t form_signature;
        uint32_t field_signature;
    };

    class FormFieldData {
    public:
        using DataView = FormFieldDataDataView;
        using Data_ = internal::FormFieldData_Data;

        static FormFieldDataPtr New();

        template <typename U>
        static FormFieldDataPtr From(const U& u)
        {
            return mojo::TypeConverter<FormFieldDataPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, FormFieldData>::Convert(*this);
        }

        FormFieldData();
        ~FormFieldData();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = FormFieldDataPtr>
        FormFieldDataPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, FormFieldData>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                FormFieldData::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                FormFieldData::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::string label;
        std::string name;
        std::string value;
        std::string form_control_type;
        std::string autocomplete_attribute;
        std::string placeholder;
        std::string css_classes;
        uint32_t properties_mask;
        uint64_t max_length;
        bool is_autofilled;
        autofill::FormFieldData::CheckStatus check_status;
        bool is_focusable;
        bool should_autocomplete;
        autofill::FormFieldData::RoleAttribute role;
        base::i18n::TextDirection text_direction;
        std::vector<std::string> option_values;
        std::vector<std::string> option_contents;
    };

    class FormData {
    public:
        using DataView = FormDataDataView;
        using Data_ = internal::FormData_Data;

        static FormDataPtr New();

        template <typename U>
        static FormDataPtr From(const U& u)
        {
            return mojo::TypeConverter<FormDataPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, FormData>::Convert(*this);
        }

        FormData();
        ~FormData();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = FormDataPtr>
        FormDataPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, FormData>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                FormData::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                FormData::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::string name;
        GURL origin;
        GURL action;
        bool is_form_tag;
        bool is_formless_checkout;
        std::vector<autofill::FormFieldData> fields;
    };

    class FormFieldDataPredictions {
    public:
        using DataView = FormFieldDataPredictionsDataView;
        using Data_ = internal::FormFieldDataPredictions_Data;

        static FormFieldDataPredictionsPtr New();

        template <typename U>
        static FormFieldDataPredictionsPtr From(const U& u)
        {
            return mojo::TypeConverter<FormFieldDataPredictionsPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, FormFieldDataPredictions>::Convert(*this);
        }

        FormFieldDataPredictions();
        ~FormFieldDataPredictions();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = FormFieldDataPredictionsPtr>
        FormFieldDataPredictionsPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, FormFieldDataPredictions>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                FormFieldDataPredictions::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                FormFieldDataPredictions::DataView, std::vector<uint8_t>>(
                input, output);
        }

        autofill::FormFieldData field;
        std::string signature;
        std::string heuristic_type;
        std::string server_type;
        std::string overall_type;
        std::string parseable_name;
    };

    class FormDataPredictions {
    public:
        using DataView = FormDataPredictionsDataView;
        using Data_ = internal::FormDataPredictions_Data;

        static FormDataPredictionsPtr New();

        template <typename U>
        static FormDataPredictionsPtr From(const U& u)
        {
            return mojo::TypeConverter<FormDataPredictionsPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, FormDataPredictions>::Convert(*this);
        }

        FormDataPredictions();
        ~FormDataPredictions();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = FormDataPredictionsPtr>
        FormDataPredictionsPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, FormDataPredictions>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                FormDataPredictions::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                FormDataPredictions::DataView, std::vector<uint8_t>>(
                input, output);
        }

        autofill::FormData data;
        std::string signature;
        std::vector<autofill::FormFieldDataPredictions> fields;
    };

    class PasswordFormFillData {
    public:
        using DataView = PasswordFormFillDataDataView;
        using Data_ = internal::PasswordFormFillData_Data;

        static PasswordFormFillDataPtr New();

        template <typename U>
        static PasswordFormFillDataPtr From(const U& u)
        {
            return mojo::TypeConverter<PasswordFormFillDataPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, PasswordFormFillData>::Convert(*this);
        }

        PasswordFormFillData();
        ~PasswordFormFillData();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = PasswordFormFillDataPtr>
        PasswordFormFillDataPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, PasswordFormFillData>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                PasswordFormFillData::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                PasswordFormFillData::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::string name;
        GURL origin;
        GURL action;
        autofill::FormFieldData username_field;
        autofill::FormFieldData password_field;
        std::string preferred_realm;
        std::unordered_map<std::string, autofill::PasswordAndRealm> additional_logins;
        std::vector<autofill::UsernamesCollectionKey> other_possible_usernames_keys;
        std::vector<std::vector<std::string>> other_possible_usernames_values;
        bool wait_for_username;
        bool is_possible_change_password_form;
    };

    class PasswordForm {
    public:
        using DataView = PasswordFormDataView;
        using Data_ = internal::PasswordForm_Data;

        static PasswordFormPtr New();

        template <typename U>
        static PasswordFormPtr From(const U& u)
        {
            return mojo::TypeConverter<PasswordFormPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, PasswordForm>::Convert(*this);
        }

        PasswordForm();
        ~PasswordForm();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = PasswordFormPtr>
        PasswordFormPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, PasswordForm>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                PasswordForm::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                PasswordForm::DataView, std::vector<uint8_t>>(
                input, output);
        }

        autofill::PasswordForm::Scheme scheme;
        std::string signon_realm;
        GURL origin_with_path;
        GURL action;
        std::string affiliated_web_realm;
        std::string submit_element;
        std::string username_element;
        bool username_marked_by_site;
        std::string username_value;
        std::vector<std::string> other_possible_usernames;
        std::string password_element;
        std::string password_value;
        bool password_value_is_default;
        std::string new_password_element;
        std::string new_password_value;
        bool new_password_value_is_default;
        bool new_password_marked_by_site;
        bool preferred;
        base::Time date_created;
        base::Time date_synced;
        bool blacklisted_by_user;
        autofill::PasswordForm::Type type;
        int32_t times_used;
        autofill::FormData form_data;
        autofill::PasswordForm::GenerationUploadStatus generation_upload_status;
        std::string display_name;
        GURL icon_url;
        url::Origin federation_origin;
        bool skip_zero_click;
        autofill::PasswordForm::Layout layout;
        bool was_parsed_using_autofill_predictions;
        bool is_public_suffix_match;
        bool is_affiliation_based_match;
        bool does_look_like_signup_form;
    };

    class PasswordFormFieldPredictionMap {
    public:
        using DataView = PasswordFormFieldPredictionMapDataView;
        using Data_ = internal::PasswordFormFieldPredictionMap_Data;

        static PasswordFormFieldPredictionMapPtr New();

        template <typename U>
        static PasswordFormFieldPredictionMapPtr From(const U& u)
        {
            return mojo::TypeConverter<PasswordFormFieldPredictionMapPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, PasswordFormFieldPredictionMap>::Convert(*this);
        }

        PasswordFormFieldPredictionMap();
        ~PasswordFormFieldPredictionMap();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = PasswordFormFieldPredictionMapPtr>
        PasswordFormFieldPredictionMapPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, PasswordFormFieldPredictionMap>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                PasswordFormFieldPredictionMap::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                PasswordFormFieldPredictionMap::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::vector<autofill::FormFieldData> keys;
        std::vector<autofill::PasswordFormFieldPredictionType> values;
    };

    class FormsPredictionsMap {
    public:
        using DataView = FormsPredictionsMapDataView;
        using Data_ = internal::FormsPredictionsMap_Data;

        static FormsPredictionsMapPtr New();

        template <typename U>
        static FormsPredictionsMapPtr From(const U& u)
        {
            return mojo::TypeConverter<FormsPredictionsMapPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, FormsPredictionsMap>::Convert(*this);
        }

        FormsPredictionsMap();
        ~FormsPredictionsMap();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = FormsPredictionsMapPtr>
        FormsPredictionsMapPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, FormsPredictionsMap>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                FormsPredictionsMap::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                FormsPredictionsMap::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::vector<autofill::FormData> keys;
        std::vector<autofill::PasswordFormFieldPredictionMap> values;
    };

    template <typename StructPtrType>
    FormFieldDataPtr FormFieldData::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->label = mojo::internal::Clone(label);
        rv->name = mojo::internal::Clone(name);
        rv->value = mojo::internal::Clone(value);
        rv->form_control_type = mojo::internal::Clone(form_control_type);
        rv->autocomplete_attribute = mojo::internal::Clone(autocomplete_attribute);
        rv->placeholder = mojo::internal::Clone(placeholder);
        rv->css_classes = mojo::internal::Clone(css_classes);
        rv->properties_mask = mojo::internal::Clone(properties_mask);
        rv->max_length = mojo::internal::Clone(max_length);
        rv->is_autofilled = mojo::internal::Clone(is_autofilled);
        rv->check_status = mojo::internal::Clone(check_status);
        rv->is_focusable = mojo::internal::Clone(is_focusable);
        rv->should_autocomplete = mojo::internal::Clone(should_autocomplete);
        rv->role = mojo::internal::Clone(role);
        rv->text_direction = mojo::internal::Clone(text_direction);
        rv->option_values = mojo::internal::Clone(option_values);
        rv->option_contents = mojo::internal::Clone(option_contents);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, FormFieldData>::value>::type*>
    bool FormFieldData::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->label, other.label))
            return false;
        if (!mojo::internal::Equals(this->name, other.name))
            return false;
        if (!mojo::internal::Equals(this->value, other.value))
            return false;
        if (!mojo::internal::Equals(this->form_control_type, other.form_control_type))
            return false;
        if (!mojo::internal::Equals(this->autocomplete_attribute, other.autocomplete_attribute))
            return false;
        if (!mojo::internal::Equals(this->placeholder, other.placeholder))
            return false;
        if (!mojo::internal::Equals(this->css_classes, other.css_classes))
            return false;
        if (!mojo::internal::Equals(this->properties_mask, other.properties_mask))
            return false;
        if (!mojo::internal::Equals(this->max_length, other.max_length))
            return false;
        if (!mojo::internal::Equals(this->is_autofilled, other.is_autofilled))
            return false;
        if (!mojo::internal::Equals(this->check_status, other.check_status))
            return false;
        if (!mojo::internal::Equals(this->is_focusable, other.is_focusable))
            return false;
        if (!mojo::internal::Equals(this->should_autocomplete, other.should_autocomplete))
            return false;
        if (!mojo::internal::Equals(this->role, other.role))
            return false;
        if (!mojo::internal::Equals(this->text_direction, other.text_direction))
            return false;
        if (!mojo::internal::Equals(this->option_values, other.option_values))
            return false;
        if (!mojo::internal::Equals(this->option_contents, other.option_contents))
            return false;
        return true;
    }
    template <typename StructPtrType>
    FormDataPtr FormData::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->name = mojo::internal::Clone(name);
        rv->origin = mojo::internal::Clone(origin);
        rv->action = mojo::internal::Clone(action);
        rv->is_form_tag = mojo::internal::Clone(is_form_tag);
        rv->is_formless_checkout = mojo::internal::Clone(is_formless_checkout);
        rv->fields = mojo::internal::Clone(fields);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, FormData>::value>::type*>
    bool FormData::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->name, other.name))
            return false;
        if (!mojo::internal::Equals(this->origin, other.origin))
            return false;
        if (!mojo::internal::Equals(this->action, other.action))
            return false;
        if (!mojo::internal::Equals(this->is_form_tag, other.is_form_tag))
            return false;
        if (!mojo::internal::Equals(this->is_formless_checkout, other.is_formless_checkout))
            return false;
        if (!mojo::internal::Equals(this->fields, other.fields))
            return false;
        return true;
    }
    template <typename StructPtrType>
    FormFieldDataPredictionsPtr FormFieldDataPredictions::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->field = mojo::internal::Clone(field);
        rv->signature = mojo::internal::Clone(signature);
        rv->heuristic_type = mojo::internal::Clone(heuristic_type);
        rv->server_type = mojo::internal::Clone(server_type);
        rv->overall_type = mojo::internal::Clone(overall_type);
        rv->parseable_name = mojo::internal::Clone(parseable_name);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, FormFieldDataPredictions>::value>::type*>
    bool FormFieldDataPredictions::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->field, other.field))
            return false;
        if (!mojo::internal::Equals(this->signature, other.signature))
            return false;
        if (!mojo::internal::Equals(this->heuristic_type, other.heuristic_type))
            return false;
        if (!mojo::internal::Equals(this->server_type, other.server_type))
            return false;
        if (!mojo::internal::Equals(this->overall_type, other.overall_type))
            return false;
        if (!mojo::internal::Equals(this->parseable_name, other.parseable_name))
            return false;
        return true;
    }
    template <typename StructPtrType>
    FormDataPredictionsPtr FormDataPredictions::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->data = mojo::internal::Clone(data);
        rv->signature = mojo::internal::Clone(signature);
        rv->fields = mojo::internal::Clone(fields);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, FormDataPredictions>::value>::type*>
    bool FormDataPredictions::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->data, other.data))
            return false;
        if (!mojo::internal::Equals(this->signature, other.signature))
            return false;
        if (!mojo::internal::Equals(this->fields, other.fields))
            return false;
        return true;
    }
    template <typename StructPtrType>
    PasswordAndRealmPtr PasswordAndRealm::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->password = mojo::internal::Clone(password);
        rv->realm = mojo::internal::Clone(realm);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, PasswordAndRealm>::value>::type*>
    bool PasswordAndRealm::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->password, other.password))
            return false;
        if (!mojo::internal::Equals(this->realm, other.realm))
            return false;
        return true;
    }
    template <typename StructPtrType>
    UsernamesCollectionKeyPtr UsernamesCollectionKey::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->username = mojo::internal::Clone(username);
        rv->password = mojo::internal::Clone(password);
        rv->realm = mojo::internal::Clone(realm);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, UsernamesCollectionKey>::value>::type*>
    bool UsernamesCollectionKey::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->username, other.username))
            return false;
        if (!mojo::internal::Equals(this->password, other.password))
            return false;
        if (!mojo::internal::Equals(this->realm, other.realm))
            return false;
        return true;
    }
    template <typename StructPtrType>
    PasswordFormFillDataPtr PasswordFormFillData::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->name = mojo::internal::Clone(name);
        rv->origin = mojo::internal::Clone(origin);
        rv->action = mojo::internal::Clone(action);
        rv->username_field = mojo::internal::Clone(username_field);
        rv->password_field = mojo::internal::Clone(password_field);
        rv->preferred_realm = mojo::internal::Clone(preferred_realm);
        rv->additional_logins = mojo::internal::Clone(additional_logins);
        rv->other_possible_usernames_keys = mojo::internal::Clone(other_possible_usernames_keys);
        rv->other_possible_usernames_values = mojo::internal::Clone(other_possible_usernames_values);
        rv->wait_for_username = mojo::internal::Clone(wait_for_username);
        rv->is_possible_change_password_form = mojo::internal::Clone(is_possible_change_password_form);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, PasswordFormFillData>::value>::type*>
    bool PasswordFormFillData::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->name, other.name))
            return false;
        if (!mojo::internal::Equals(this->origin, other.origin))
            return false;
        if (!mojo::internal::Equals(this->action, other.action))
            return false;
        if (!mojo::internal::Equals(this->username_field, other.username_field))
            return false;
        if (!mojo::internal::Equals(this->password_field, other.password_field))
            return false;
        if (!mojo::internal::Equals(this->preferred_realm, other.preferred_realm))
            return false;
        if (!mojo::internal::Equals(this->additional_logins, other.additional_logins))
            return false;
        if (!mojo::internal::Equals(this->other_possible_usernames_keys, other.other_possible_usernames_keys))
            return false;
        if (!mojo::internal::Equals(this->other_possible_usernames_values, other.other_possible_usernames_values))
            return false;
        if (!mojo::internal::Equals(this->wait_for_username, other.wait_for_username))
            return false;
        if (!mojo::internal::Equals(this->is_possible_change_password_form, other.is_possible_change_password_form))
            return false;
        return true;
    }
    template <typename StructPtrType>
    PasswordFormGenerationDataPtr PasswordFormGenerationData::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->form_signature = mojo::internal::Clone(form_signature);
        rv->field_signature = mojo::internal::Clone(field_signature);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, PasswordFormGenerationData>::value>::type*>
    bool PasswordFormGenerationData::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->form_signature, other.form_signature))
            return false;
        if (!mojo::internal::Equals(this->field_signature, other.field_signature))
            return false;
        return true;
    }
    template <typename StructPtrType>
    PasswordFormPtr PasswordForm::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->scheme = mojo::internal::Clone(scheme);
        rv->signon_realm = mojo::internal::Clone(signon_realm);
        rv->origin_with_path = mojo::internal::Clone(origin_with_path);
        rv->action = mojo::internal::Clone(action);
        rv->affiliated_web_realm = mojo::internal::Clone(affiliated_web_realm);
        rv->submit_element = mojo::internal::Clone(submit_element);
        rv->username_element = mojo::internal::Clone(username_element);
        rv->username_marked_by_site = mojo::internal::Clone(username_marked_by_site);
        rv->username_value = mojo::internal::Clone(username_value);
        rv->other_possible_usernames = mojo::internal::Clone(other_possible_usernames);
        rv->password_element = mojo::internal::Clone(password_element);
        rv->password_value = mojo::internal::Clone(password_value);
        rv->password_value_is_default = mojo::internal::Clone(password_value_is_default);
        rv->new_password_element = mojo::internal::Clone(new_password_element);
        rv->new_password_value = mojo::internal::Clone(new_password_value);
        rv->new_password_value_is_default = mojo::internal::Clone(new_password_value_is_default);
        rv->new_password_marked_by_site = mojo::internal::Clone(new_password_marked_by_site);
        rv->preferred = mojo::internal::Clone(preferred);
        rv->date_created = mojo::internal::Clone(date_created);
        rv->date_synced = mojo::internal::Clone(date_synced);
        rv->blacklisted_by_user = mojo::internal::Clone(blacklisted_by_user);
        rv->type = mojo::internal::Clone(type);
        rv->times_used = mojo::internal::Clone(times_used);
        rv->form_data = mojo::internal::Clone(form_data);
        rv->generation_upload_status = mojo::internal::Clone(generation_upload_status);
        rv->display_name = mojo::internal::Clone(display_name);
        rv->icon_url = mojo::internal::Clone(icon_url);
        rv->federation_origin = mojo::internal::Clone(federation_origin);
        rv->skip_zero_click = mojo::internal::Clone(skip_zero_click);
        rv->layout = mojo::internal::Clone(layout);
        rv->was_parsed_using_autofill_predictions = mojo::internal::Clone(was_parsed_using_autofill_predictions);
        rv->is_public_suffix_match = mojo::internal::Clone(is_public_suffix_match);
        rv->is_affiliation_based_match = mojo::internal::Clone(is_affiliation_based_match);
        rv->does_look_like_signup_form = mojo::internal::Clone(does_look_like_signup_form);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, PasswordForm>::value>::type*>
    bool PasswordForm::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->scheme, other.scheme))
            return false;
        if (!mojo::internal::Equals(this->signon_realm, other.signon_realm))
            return false;
        if (!mojo::internal::Equals(this->origin_with_path, other.origin_with_path))
            return false;
        if (!mojo::internal::Equals(this->action, other.action))
            return false;
        if (!mojo::internal::Equals(this->affiliated_web_realm, other.affiliated_web_realm))
            return false;
        if (!mojo::internal::Equals(this->submit_element, other.submit_element))
            return false;
        if (!mojo::internal::Equals(this->username_element, other.username_element))
            return false;
        if (!mojo::internal::Equals(this->username_marked_by_site, other.username_marked_by_site))
            return false;
        if (!mojo::internal::Equals(this->username_value, other.username_value))
            return false;
        if (!mojo::internal::Equals(this->other_possible_usernames, other.other_possible_usernames))
            return false;
        if (!mojo::internal::Equals(this->password_element, other.password_element))
            return false;
        if (!mojo::internal::Equals(this->password_value, other.password_value))
            return false;
        if (!mojo::internal::Equals(this->password_value_is_default, other.password_value_is_default))
            return false;
        if (!mojo::internal::Equals(this->new_password_element, other.new_password_element))
            return false;
        if (!mojo::internal::Equals(this->new_password_value, other.new_password_value))
            return false;
        if (!mojo::internal::Equals(this->new_password_value_is_default, other.new_password_value_is_default))
            return false;
        if (!mojo::internal::Equals(this->new_password_marked_by_site, other.new_password_marked_by_site))
            return false;
        if (!mojo::internal::Equals(this->preferred, other.preferred))
            return false;
        if (!mojo::internal::Equals(this->date_created, other.date_created))
            return false;
        if (!mojo::internal::Equals(this->date_synced, other.date_synced))
            return false;
        if (!mojo::internal::Equals(this->blacklisted_by_user, other.blacklisted_by_user))
            return false;
        if (!mojo::internal::Equals(this->type, other.type))
            return false;
        if (!mojo::internal::Equals(this->times_used, other.times_used))
            return false;
        if (!mojo::internal::Equals(this->form_data, other.form_data))
            return false;
        if (!mojo::internal::Equals(this->generation_upload_status, other.generation_upload_status))
            return false;
        if (!mojo::internal::Equals(this->display_name, other.display_name))
            return false;
        if (!mojo::internal::Equals(this->icon_url, other.icon_url))
            return false;
        if (!mojo::internal::Equals(this->federation_origin, other.federation_origin))
            return false;
        if (!mojo::internal::Equals(this->skip_zero_click, other.skip_zero_click))
            return false;
        if (!mojo::internal::Equals(this->layout, other.layout))
            return false;
        if (!mojo::internal::Equals(this->was_parsed_using_autofill_predictions, other.was_parsed_using_autofill_predictions))
            return false;
        if (!mojo::internal::Equals(this->is_public_suffix_match, other.is_public_suffix_match))
            return false;
        if (!mojo::internal::Equals(this->is_affiliation_based_match, other.is_affiliation_based_match))
            return false;
        if (!mojo::internal::Equals(this->does_look_like_signup_form, other.does_look_like_signup_form))
            return false;
        return true;
    }
    template <typename StructPtrType>
    PasswordFormFieldPredictionMapPtr PasswordFormFieldPredictionMap::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->keys = mojo::internal::Clone(keys);
        rv->values = mojo::internal::Clone(values);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, PasswordFormFieldPredictionMap>::value>::type*>
    bool PasswordFormFieldPredictionMap::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->keys, other.keys))
            return false;
        if (!mojo::internal::Equals(this->values, other.values))
            return false;
        return true;
    }
    template <typename StructPtrType>
    FormsPredictionsMapPtr FormsPredictionsMap::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->keys = mojo::internal::Clone(keys);
        rv->values = mojo::internal::Clone(values);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, FormsPredictionsMap>::value>::type*>
    bool FormsPredictionsMap::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->keys, other.keys))
            return false;
        if (!mojo::internal::Equals(this->values, other.values))
            return false;
        return true;
    }

} // namespace mojom
} // namespace autofill

namespace mojo {

template <>
struct StructTraits<::autofill::mojom::FormFieldData::DataView,
    ::autofill::mojom::FormFieldDataPtr> {
    static bool IsNull(const ::autofill::mojom::FormFieldDataPtr& input) { return !input; }
    static void SetToNull(::autofill::mojom::FormFieldDataPtr* output) { output->reset(); }

    static const decltype(::autofill::mojom::FormFieldData::label)& label(
        const ::autofill::mojom::FormFieldDataPtr& input)
    {
        return input->label;
    }

    static const decltype(::autofill::mojom::FormFieldData::name)& name(
        const ::autofill::mojom::FormFieldDataPtr& input)
    {
        return input->name;
    }

    static const decltype(::autofill::mojom::FormFieldData::value)& value(
        const ::autofill::mojom::FormFieldDataPtr& input)
    {
        return input->value;
    }

    static const decltype(::autofill::mojom::FormFieldData::form_control_type)& form_control_type(
        const ::autofill::mojom::FormFieldDataPtr& input)
    {
        return input->form_control_type;
    }

    static const decltype(::autofill::mojom::FormFieldData::autocomplete_attribute)& autocomplete_attribute(
        const ::autofill::mojom::FormFieldDataPtr& input)
    {
        return input->autocomplete_attribute;
    }

    static const decltype(::autofill::mojom::FormFieldData::placeholder)& placeholder(
        const ::autofill::mojom::FormFieldDataPtr& input)
    {
        return input->placeholder;
    }

    static const decltype(::autofill::mojom::FormFieldData::css_classes)& css_classes(
        const ::autofill::mojom::FormFieldDataPtr& input)
    {
        return input->css_classes;
    }

    static decltype(::autofill::mojom::FormFieldData::properties_mask) properties_mask(
        const ::autofill::mojom::FormFieldDataPtr& input)
    {
        return input->properties_mask;
    }

    static decltype(::autofill::mojom::FormFieldData::max_length) max_length(
        const ::autofill::mojom::FormFieldDataPtr& input)
    {
        return input->max_length;
    }

    static decltype(::autofill::mojom::FormFieldData::is_autofilled) is_autofilled(
        const ::autofill::mojom::FormFieldDataPtr& input)
    {
        return input->is_autofilled;
    }

    static decltype(::autofill::mojom::FormFieldData::check_status) check_status(
        const ::autofill::mojom::FormFieldDataPtr& input)
    {
        return input->check_status;
    }

    static decltype(::autofill::mojom::FormFieldData::is_focusable) is_focusable(
        const ::autofill::mojom::FormFieldDataPtr& input)
    {
        return input->is_focusable;
    }

    static decltype(::autofill::mojom::FormFieldData::should_autocomplete) should_autocomplete(
        const ::autofill::mojom::FormFieldDataPtr& input)
    {
        return input->should_autocomplete;
    }

    static decltype(::autofill::mojom::FormFieldData::role) role(
        const ::autofill::mojom::FormFieldDataPtr& input)
    {
        return input->role;
    }

    static decltype(::autofill::mojom::FormFieldData::text_direction) text_direction(
        const ::autofill::mojom::FormFieldDataPtr& input)
    {
        return input->text_direction;
    }

    static const decltype(::autofill::mojom::FormFieldData::option_values)& option_values(
        const ::autofill::mojom::FormFieldDataPtr& input)
    {
        return input->option_values;
    }

    static const decltype(::autofill::mojom::FormFieldData::option_contents)& option_contents(
        const ::autofill::mojom::FormFieldDataPtr& input)
    {
        return input->option_contents;
    }

    static bool Read(::autofill::mojom::FormFieldData::DataView input, ::autofill::mojom::FormFieldDataPtr* output);
};

template <>
struct StructTraits<::autofill::mojom::FormData::DataView,
    ::autofill::mojom::FormDataPtr> {
    static bool IsNull(const ::autofill::mojom::FormDataPtr& input) { return !input; }
    static void SetToNull(::autofill::mojom::FormDataPtr* output) { output->reset(); }

    static const decltype(::autofill::mojom::FormData::name)& name(
        const ::autofill::mojom::FormDataPtr& input)
    {
        return input->name;
    }

    static const decltype(::autofill::mojom::FormData::origin)& origin(
        const ::autofill::mojom::FormDataPtr& input)
    {
        return input->origin;
    }

    static const decltype(::autofill::mojom::FormData::action)& action(
        const ::autofill::mojom::FormDataPtr& input)
    {
        return input->action;
    }

    static decltype(::autofill::mojom::FormData::is_form_tag) is_form_tag(
        const ::autofill::mojom::FormDataPtr& input)
    {
        return input->is_form_tag;
    }

    static decltype(::autofill::mojom::FormData::is_formless_checkout) is_formless_checkout(
        const ::autofill::mojom::FormDataPtr& input)
    {
        return input->is_formless_checkout;
    }

    static const decltype(::autofill::mojom::FormData::fields)& fields(
        const ::autofill::mojom::FormDataPtr& input)
    {
        return input->fields;
    }

    static bool Read(::autofill::mojom::FormData::DataView input, ::autofill::mojom::FormDataPtr* output);
};

template <>
struct StructTraits<::autofill::mojom::FormFieldDataPredictions::DataView,
    ::autofill::mojom::FormFieldDataPredictionsPtr> {
    static bool IsNull(const ::autofill::mojom::FormFieldDataPredictionsPtr& input) { return !input; }
    static void SetToNull(::autofill::mojom::FormFieldDataPredictionsPtr* output) { output->reset(); }

    static const decltype(::autofill::mojom::FormFieldDataPredictions::field)& field(
        const ::autofill::mojom::FormFieldDataPredictionsPtr& input)
    {
        return input->field;
    }

    static const decltype(::autofill::mojom::FormFieldDataPredictions::signature)& signature(
        const ::autofill::mojom::FormFieldDataPredictionsPtr& input)
    {
        return input->signature;
    }

    static const decltype(::autofill::mojom::FormFieldDataPredictions::heuristic_type)& heuristic_type(
        const ::autofill::mojom::FormFieldDataPredictionsPtr& input)
    {
        return input->heuristic_type;
    }

    static const decltype(::autofill::mojom::FormFieldDataPredictions::server_type)& server_type(
        const ::autofill::mojom::FormFieldDataPredictionsPtr& input)
    {
        return input->server_type;
    }

    static const decltype(::autofill::mojom::FormFieldDataPredictions::overall_type)& overall_type(
        const ::autofill::mojom::FormFieldDataPredictionsPtr& input)
    {
        return input->overall_type;
    }

    static const decltype(::autofill::mojom::FormFieldDataPredictions::parseable_name)& parseable_name(
        const ::autofill::mojom::FormFieldDataPredictionsPtr& input)
    {
        return input->parseable_name;
    }

    static bool Read(::autofill::mojom::FormFieldDataPredictions::DataView input, ::autofill::mojom::FormFieldDataPredictionsPtr* output);
};

template <>
struct StructTraits<::autofill::mojom::FormDataPredictions::DataView,
    ::autofill::mojom::FormDataPredictionsPtr> {
    static bool IsNull(const ::autofill::mojom::FormDataPredictionsPtr& input) { return !input; }
    static void SetToNull(::autofill::mojom::FormDataPredictionsPtr* output) { output->reset(); }

    static const decltype(::autofill::mojom::FormDataPredictions::data)& data(
        const ::autofill::mojom::FormDataPredictionsPtr& input)
    {
        return input->data;
    }

    static const decltype(::autofill::mojom::FormDataPredictions::signature)& signature(
        const ::autofill::mojom::FormDataPredictionsPtr& input)
    {
        return input->signature;
    }

    static const decltype(::autofill::mojom::FormDataPredictions::fields)& fields(
        const ::autofill::mojom::FormDataPredictionsPtr& input)
    {
        return input->fields;
    }

    static bool Read(::autofill::mojom::FormDataPredictions::DataView input, ::autofill::mojom::FormDataPredictionsPtr* output);
};

template <>
struct StructTraits<::autofill::mojom::PasswordAndRealm::DataView,
    ::autofill::mojom::PasswordAndRealmPtr> {
    static bool IsNull(const ::autofill::mojom::PasswordAndRealmPtr& input) { return !input; }
    static void SetToNull(::autofill::mojom::PasswordAndRealmPtr* output) { output->reset(); }

    static const decltype(::autofill::mojom::PasswordAndRealm::password)& password(
        const ::autofill::mojom::PasswordAndRealmPtr& input)
    {
        return input->password;
    }

    static const decltype(::autofill::mojom::PasswordAndRealm::realm)& realm(
        const ::autofill::mojom::PasswordAndRealmPtr& input)
    {
        return input->realm;
    }

    static bool Read(::autofill::mojom::PasswordAndRealm::DataView input, ::autofill::mojom::PasswordAndRealmPtr* output);
};

template <>
struct StructTraits<::autofill::mojom::UsernamesCollectionKey::DataView,
    ::autofill::mojom::UsernamesCollectionKeyPtr> {
    static bool IsNull(const ::autofill::mojom::UsernamesCollectionKeyPtr& input) { return !input; }
    static void SetToNull(::autofill::mojom::UsernamesCollectionKeyPtr* output) { output->reset(); }

    static const decltype(::autofill::mojom::UsernamesCollectionKey::username)& username(
        const ::autofill::mojom::UsernamesCollectionKeyPtr& input)
    {
        return input->username;
    }

    static const decltype(::autofill::mojom::UsernamesCollectionKey::password)& password(
        const ::autofill::mojom::UsernamesCollectionKeyPtr& input)
    {
        return input->password;
    }

    static const decltype(::autofill::mojom::UsernamesCollectionKey::realm)& realm(
        const ::autofill::mojom::UsernamesCollectionKeyPtr& input)
    {
        return input->realm;
    }

    static bool Read(::autofill::mojom::UsernamesCollectionKey::DataView input, ::autofill::mojom::UsernamesCollectionKeyPtr* output);
};

template <>
struct StructTraits<::autofill::mojom::PasswordFormFillData::DataView,
    ::autofill::mojom::PasswordFormFillDataPtr> {
    static bool IsNull(const ::autofill::mojom::PasswordFormFillDataPtr& input) { return !input; }
    static void SetToNull(::autofill::mojom::PasswordFormFillDataPtr* output) { output->reset(); }

    static const decltype(::autofill::mojom::PasswordFormFillData::name)& name(
        const ::autofill::mojom::PasswordFormFillDataPtr& input)
    {
        return input->name;
    }

    static const decltype(::autofill::mojom::PasswordFormFillData::origin)& origin(
        const ::autofill::mojom::PasswordFormFillDataPtr& input)
    {
        return input->origin;
    }

    static const decltype(::autofill::mojom::PasswordFormFillData::action)& action(
        const ::autofill::mojom::PasswordFormFillDataPtr& input)
    {
        return input->action;
    }

    static const decltype(::autofill::mojom::PasswordFormFillData::username_field)& username_field(
        const ::autofill::mojom::PasswordFormFillDataPtr& input)
    {
        return input->username_field;
    }

    static const decltype(::autofill::mojom::PasswordFormFillData::password_field)& password_field(
        const ::autofill::mojom::PasswordFormFillDataPtr& input)
    {
        return input->password_field;
    }

    static const decltype(::autofill::mojom::PasswordFormFillData::preferred_realm)& preferred_realm(
        const ::autofill::mojom::PasswordFormFillDataPtr& input)
    {
        return input->preferred_realm;
    }

    static const decltype(::autofill::mojom::PasswordFormFillData::additional_logins)& additional_logins(
        const ::autofill::mojom::PasswordFormFillDataPtr& input)
    {
        return input->additional_logins;
    }

    static const decltype(::autofill::mojom::PasswordFormFillData::other_possible_usernames_keys)& other_possible_usernames_keys(
        const ::autofill::mojom::PasswordFormFillDataPtr& input)
    {
        return input->other_possible_usernames_keys;
    }

    static const decltype(::autofill::mojom::PasswordFormFillData::other_possible_usernames_values)& other_possible_usernames_values(
        const ::autofill::mojom::PasswordFormFillDataPtr& input)
    {
        return input->other_possible_usernames_values;
    }

    static decltype(::autofill::mojom::PasswordFormFillData::wait_for_username) wait_for_username(
        const ::autofill::mojom::PasswordFormFillDataPtr& input)
    {
        return input->wait_for_username;
    }

    static decltype(::autofill::mojom::PasswordFormFillData::is_possible_change_password_form) is_possible_change_password_form(
        const ::autofill::mojom::PasswordFormFillDataPtr& input)
    {
        return input->is_possible_change_password_form;
    }

    static bool Read(::autofill::mojom::PasswordFormFillData::DataView input, ::autofill::mojom::PasswordFormFillDataPtr* output);
};

template <>
struct StructTraits<::autofill::mojom::PasswordFormGenerationData::DataView,
    ::autofill::mojom::PasswordFormGenerationDataPtr> {
    static bool IsNull(const ::autofill::mojom::PasswordFormGenerationDataPtr& input) { return !input; }
    static void SetToNull(::autofill::mojom::PasswordFormGenerationDataPtr* output) { output->reset(); }

    static decltype(::autofill::mojom::PasswordFormGenerationData::form_signature) form_signature(
        const ::autofill::mojom::PasswordFormGenerationDataPtr& input)
    {
        return input->form_signature;
    }

    static decltype(::autofill::mojom::PasswordFormGenerationData::field_signature) field_signature(
        const ::autofill::mojom::PasswordFormGenerationDataPtr& input)
    {
        return input->field_signature;
    }

    static bool Read(::autofill::mojom::PasswordFormGenerationData::DataView input, ::autofill::mojom::PasswordFormGenerationDataPtr* output);
};

template <>
struct StructTraits<::autofill::mojom::PasswordForm::DataView,
    ::autofill::mojom::PasswordFormPtr> {
    static bool IsNull(const ::autofill::mojom::PasswordFormPtr& input) { return !input; }
    static void SetToNull(::autofill::mojom::PasswordFormPtr* output) { output->reset(); }

    static decltype(::autofill::mojom::PasswordForm::scheme) scheme(
        const ::autofill::mojom::PasswordFormPtr& input)
    {
        return input->scheme;
    }

    static const decltype(::autofill::mojom::PasswordForm::signon_realm)& signon_realm(
        const ::autofill::mojom::PasswordFormPtr& input)
    {
        return input->signon_realm;
    }

    static const decltype(::autofill::mojom::PasswordForm::origin_with_path)& origin_with_path(
        const ::autofill::mojom::PasswordFormPtr& input)
    {
        return input->origin_with_path;
    }

    static const decltype(::autofill::mojom::PasswordForm::action)& action(
        const ::autofill::mojom::PasswordFormPtr& input)
    {
        return input->action;
    }

    static const decltype(::autofill::mojom::PasswordForm::affiliated_web_realm)& affiliated_web_realm(
        const ::autofill::mojom::PasswordFormPtr& input)
    {
        return input->affiliated_web_realm;
    }

    static const decltype(::autofill::mojom::PasswordForm::submit_element)& submit_element(
        const ::autofill::mojom::PasswordFormPtr& input)
    {
        return input->submit_element;
    }

    static const decltype(::autofill::mojom::PasswordForm::username_element)& username_element(
        const ::autofill::mojom::PasswordFormPtr& input)
    {
        return input->username_element;
    }

    static decltype(::autofill::mojom::PasswordForm::username_marked_by_site) username_marked_by_site(
        const ::autofill::mojom::PasswordFormPtr& input)
    {
        return input->username_marked_by_site;
    }

    static const decltype(::autofill::mojom::PasswordForm::username_value)& username_value(
        const ::autofill::mojom::PasswordFormPtr& input)
    {
        return input->username_value;
    }

    static const decltype(::autofill::mojom::PasswordForm::other_possible_usernames)& other_possible_usernames(
        const ::autofill::mojom::PasswordFormPtr& input)
    {
        return input->other_possible_usernames;
    }

    static const decltype(::autofill::mojom::PasswordForm::password_element)& password_element(
        const ::autofill::mojom::PasswordFormPtr& input)
    {
        return input->password_element;
    }

    static const decltype(::autofill::mojom::PasswordForm::password_value)& password_value(
        const ::autofill::mojom::PasswordFormPtr& input)
    {
        return input->password_value;
    }

    static decltype(::autofill::mojom::PasswordForm::password_value_is_default) password_value_is_default(
        const ::autofill::mojom::PasswordFormPtr& input)
    {
        return input->password_value_is_default;
    }

    static const decltype(::autofill::mojom::PasswordForm::new_password_element)& new_password_element(
        const ::autofill::mojom::PasswordFormPtr& input)
    {
        return input->new_password_element;
    }

    static const decltype(::autofill::mojom::PasswordForm::new_password_value)& new_password_value(
        const ::autofill::mojom::PasswordFormPtr& input)
    {
        return input->new_password_value;
    }

    static decltype(::autofill::mojom::PasswordForm::new_password_value_is_default) new_password_value_is_default(
        const ::autofill::mojom::PasswordFormPtr& input)
    {
        return input->new_password_value_is_default;
    }

    static decltype(::autofill::mojom::PasswordForm::new_password_marked_by_site) new_password_marked_by_site(
        const ::autofill::mojom::PasswordFormPtr& input)
    {
        return input->new_password_marked_by_site;
    }

    static decltype(::autofill::mojom::PasswordForm::preferred) preferred(
        const ::autofill::mojom::PasswordFormPtr& input)
    {
        return input->preferred;
    }

    static const decltype(::autofill::mojom::PasswordForm::date_created)& date_created(
        const ::autofill::mojom::PasswordFormPtr& input)
    {
        return input->date_created;
    }

    static const decltype(::autofill::mojom::PasswordForm::date_synced)& date_synced(
        const ::autofill::mojom::PasswordFormPtr& input)
    {
        return input->date_synced;
    }

    static decltype(::autofill::mojom::PasswordForm::blacklisted_by_user) blacklisted_by_user(
        const ::autofill::mojom::PasswordFormPtr& input)
    {
        return input->blacklisted_by_user;
    }

    static decltype(::autofill::mojom::PasswordForm::type) type(
        const ::autofill::mojom::PasswordFormPtr& input)
    {
        return input->type;
    }

    static decltype(::autofill::mojom::PasswordForm::times_used) times_used(
        const ::autofill::mojom::PasswordFormPtr& input)
    {
        return input->times_used;
    }

    static const decltype(::autofill::mojom::PasswordForm::form_data)& form_data(
        const ::autofill::mojom::PasswordFormPtr& input)
    {
        return input->form_data;
    }

    static decltype(::autofill::mojom::PasswordForm::generation_upload_status) generation_upload_status(
        const ::autofill::mojom::PasswordFormPtr& input)
    {
        return input->generation_upload_status;
    }

    static const decltype(::autofill::mojom::PasswordForm::display_name)& display_name(
        const ::autofill::mojom::PasswordFormPtr& input)
    {
        return input->display_name;
    }

    static const decltype(::autofill::mojom::PasswordForm::icon_url)& icon_url(
        const ::autofill::mojom::PasswordFormPtr& input)
    {
        return input->icon_url;
    }

    static const decltype(::autofill::mojom::PasswordForm::federation_origin)& federation_origin(
        const ::autofill::mojom::PasswordFormPtr& input)
    {
        return input->federation_origin;
    }

    static decltype(::autofill::mojom::PasswordForm::skip_zero_click) skip_zero_click(
        const ::autofill::mojom::PasswordFormPtr& input)
    {
        return input->skip_zero_click;
    }

    static decltype(::autofill::mojom::PasswordForm::layout) layout(
        const ::autofill::mojom::PasswordFormPtr& input)
    {
        return input->layout;
    }

    static decltype(::autofill::mojom::PasswordForm::was_parsed_using_autofill_predictions) was_parsed_using_autofill_predictions(
        const ::autofill::mojom::PasswordFormPtr& input)
    {
        return input->was_parsed_using_autofill_predictions;
    }

    static decltype(::autofill::mojom::PasswordForm::is_public_suffix_match) is_public_suffix_match(
        const ::autofill::mojom::PasswordFormPtr& input)
    {
        return input->is_public_suffix_match;
    }

    static decltype(::autofill::mojom::PasswordForm::is_affiliation_based_match) is_affiliation_based_match(
        const ::autofill::mojom::PasswordFormPtr& input)
    {
        return input->is_affiliation_based_match;
    }

    static decltype(::autofill::mojom::PasswordForm::does_look_like_signup_form) does_look_like_signup_form(
        const ::autofill::mojom::PasswordFormPtr& input)
    {
        return input->does_look_like_signup_form;
    }

    static bool Read(::autofill::mojom::PasswordForm::DataView input, ::autofill::mojom::PasswordFormPtr* output);
};

template <>
struct StructTraits<::autofill::mojom::PasswordFormFieldPredictionMap::DataView,
    ::autofill::mojom::PasswordFormFieldPredictionMapPtr> {
    static bool IsNull(const ::autofill::mojom::PasswordFormFieldPredictionMapPtr& input) { return !input; }
    static void SetToNull(::autofill::mojom::PasswordFormFieldPredictionMapPtr* output) { output->reset(); }

    static const decltype(::autofill::mojom::PasswordFormFieldPredictionMap::keys)& keys(
        const ::autofill::mojom::PasswordFormFieldPredictionMapPtr& input)
    {
        return input->keys;
    }

    static const decltype(::autofill::mojom::PasswordFormFieldPredictionMap::values)& values(
        const ::autofill::mojom::PasswordFormFieldPredictionMapPtr& input)
    {
        return input->values;
    }

    static bool Read(::autofill::mojom::PasswordFormFieldPredictionMap::DataView input, ::autofill::mojom::PasswordFormFieldPredictionMapPtr* output);
};

template <>
struct StructTraits<::autofill::mojom::FormsPredictionsMap::DataView,
    ::autofill::mojom::FormsPredictionsMapPtr> {
    static bool IsNull(const ::autofill::mojom::FormsPredictionsMapPtr& input) { return !input; }
    static void SetToNull(::autofill::mojom::FormsPredictionsMapPtr* output) { output->reset(); }

    static const decltype(::autofill::mojom::FormsPredictionsMap::keys)& keys(
        const ::autofill::mojom::FormsPredictionsMapPtr& input)
    {
        return input->keys;
    }

    static const decltype(::autofill::mojom::FormsPredictionsMap::values)& values(
        const ::autofill::mojom::FormsPredictionsMapPtr& input)
    {
        return input->values;
    }

    static bool Read(::autofill::mojom::FormsPredictionsMap::DataView input, ::autofill::mojom::FormsPredictionsMapPtr* output);
};

} // namespace mojo

#endif // COMPONENTS_AUTOFILL_CONTENT_COMMON_AUTOFILL_TYPES_MOJOM_H_