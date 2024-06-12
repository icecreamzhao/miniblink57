// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_AUTOFILL_CONTENT_COMMON_AUTOFILL_TYPES_MOJOM_SHARED_H_
#define COMPONENTS_AUTOFILL_CONTENT_COMMON_AUTOFILL_TYPES_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "components/autofill/content/common/autofill_types.mojom-shared-internal.h"
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
#include "url/mojo/origin.mojom-shared.h"
#include "url/mojo/url.mojom-shared.h"

namespace autofill {
namespace mojom {
    class FormFieldDataDataView;

    class FormDataDataView;

    class FormFieldDataPredictionsDataView;

    class FormDataPredictionsDataView;

    class PasswordAndRealmDataView;

    class UsernamesCollectionKeyDataView;

    class PasswordFormFillDataDataView;

    class PasswordFormGenerationDataDataView;

    class PasswordFormDataView;

    class PasswordFormFieldPredictionMapDataView;

    class FormsPredictionsMapDataView;

} // namespace mojom
} // namespace autofill

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::autofill::mojom::FormFieldDataDataView> {
        using Data = ::autofill::mojom::internal::FormFieldData_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::autofill::mojom::FormDataDataView> {
        using Data = ::autofill::mojom::internal::FormData_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::autofill::mojom::FormFieldDataPredictionsDataView> {
        using Data = ::autofill::mojom::internal::FormFieldDataPredictions_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::autofill::mojom::FormDataPredictionsDataView> {
        using Data = ::autofill::mojom::internal::FormDataPredictions_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::autofill::mojom::PasswordAndRealmDataView> {
        using Data = ::autofill::mojom::internal::PasswordAndRealm_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::autofill::mojom::UsernamesCollectionKeyDataView> {
        using Data = ::autofill::mojom::internal::UsernamesCollectionKey_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::autofill::mojom::PasswordFormFillDataDataView> {
        using Data = ::autofill::mojom::internal::PasswordFormFillData_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::autofill::mojom::PasswordFormGenerationDataDataView> {
        using Data = ::autofill::mojom::internal::PasswordFormGenerationData_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::autofill::mojom::PasswordFormDataView> {
        using Data = ::autofill::mojom::internal::PasswordForm_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::autofill::mojom::PasswordFormFieldPredictionMapDataView> {
        using Data = ::autofill::mojom::internal::PasswordFormFieldPredictionMap_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::autofill::mojom::FormsPredictionsMapDataView> {
        using Data = ::autofill::mojom::internal::FormsPredictionsMap_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace autofill {
namespace mojom {

    enum class CheckStatus : int32_t {
        NOT_CHECKABLE,
        CHECKABLE_BUT_UNCHECKED,
        CHECKED,
    };

    inline std::ostream& operator<<(std::ostream& os, CheckStatus value)
    {
        switch (value) {
        case CheckStatus::NOT_CHECKABLE:
            return os << "CheckStatus::NOT_CHECKABLE";
        case CheckStatus::CHECKABLE_BUT_UNCHECKED:
            return os << "CheckStatus::CHECKABLE_BUT_UNCHECKED";
        case CheckStatus::CHECKED:
            return os << "CheckStatus::CHECKED";
        default:
            return os << "Unknown CheckStatus value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(CheckStatus value)
    {
        return internal::CheckStatus_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class RoleAttribute : int32_t {
        ROLE_ATTRIBUTE_PRESENTATION,
        ROLE_ATTRIBUTE_OTHER,
    };

    inline std::ostream& operator<<(std::ostream& os, RoleAttribute value)
    {
        switch (value) {
        case RoleAttribute::ROLE_ATTRIBUTE_PRESENTATION:
            return os << "RoleAttribute::ROLE_ATTRIBUTE_PRESENTATION";
        case RoleAttribute::ROLE_ATTRIBUTE_OTHER:
            return os << "RoleAttribute::ROLE_ATTRIBUTE_OTHER";
        default:
            return os << "Unknown RoleAttribute value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(RoleAttribute value)
    {
        return internal::RoleAttribute_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class GenerationUploadStatus : int32_t {
        NO_SIGNAL_SENT,
        POSITIVE_SIGNAL_SENT,
        NEGATIVE_SIGNAL_SENT,
        UNKNOWN_STATUS = 10,
    };

    inline std::ostream& operator<<(std::ostream& os, GenerationUploadStatus value)
    {
        switch (value) {
        case GenerationUploadStatus::NO_SIGNAL_SENT:
            return os << "GenerationUploadStatus::NO_SIGNAL_SENT";
        case GenerationUploadStatus::POSITIVE_SIGNAL_SENT:
            return os << "GenerationUploadStatus::POSITIVE_SIGNAL_SENT";
        case GenerationUploadStatus::NEGATIVE_SIGNAL_SENT:
            return os << "GenerationUploadStatus::NEGATIVE_SIGNAL_SENT";
        case GenerationUploadStatus::UNKNOWN_STATUS:
            return os << "GenerationUploadStatus::UNKNOWN_STATUS";
        default:
            return os << "Unknown GenerationUploadStatus value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(GenerationUploadStatus value)
    {
        return internal::GenerationUploadStatus_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class PasswordFormLayout : int32_t {
        LAYOUT_OTHER,
        LAYOUT_LOGIN_AND_SIGNUP,
    };

    inline std::ostream& operator<<(std::ostream& os, PasswordFormLayout value)
    {
        switch (value) {
        case PasswordFormLayout::LAYOUT_OTHER:
            return os << "PasswordFormLayout::LAYOUT_OTHER";
        case PasswordFormLayout::LAYOUT_LOGIN_AND_SIGNUP:
            return os << "PasswordFormLayout::LAYOUT_LOGIN_AND_SIGNUP";
        default:
            return os << "Unknown PasswordFormLayout value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(PasswordFormLayout value)
    {
        return internal::PasswordFormLayout_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class PasswordFormType : int32_t {
        TYPE_MANUAL,
        TYPE_GENERATED,
        TYPE_API,
    };

    inline std::ostream& operator<<(std::ostream& os, PasswordFormType value)
    {
        switch (value) {
        case PasswordFormType::TYPE_MANUAL:
            return os << "PasswordFormType::TYPE_MANUAL";
        case PasswordFormType::TYPE_GENERATED:
            return os << "PasswordFormType::TYPE_GENERATED";
        case PasswordFormType::TYPE_API:
            return os << "PasswordFormType::TYPE_API";
        default:
            return os << "Unknown PasswordFormType value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(PasswordFormType value)
    {
        return internal::PasswordFormType_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class PasswordFormScheme : int32_t {
        SCHEME_HTML,
        SCHEME_BASIC,
        SCHEME_DIGEST,
        SCHEME_OTHER,
        SCHEME_USERNAME_ONLY,
    };

    inline std::ostream& operator<<(std::ostream& os, PasswordFormScheme value)
    {
        switch (value) {
        case PasswordFormScheme::SCHEME_HTML:
            return os << "PasswordFormScheme::SCHEME_HTML";
        case PasswordFormScheme::SCHEME_BASIC:
            return os << "PasswordFormScheme::SCHEME_BASIC";
        case PasswordFormScheme::SCHEME_DIGEST:
            return os << "PasswordFormScheme::SCHEME_DIGEST";
        case PasswordFormScheme::SCHEME_OTHER:
            return os << "PasswordFormScheme::SCHEME_OTHER";
        case PasswordFormScheme::SCHEME_USERNAME_ONLY:
            return os << "PasswordFormScheme::SCHEME_USERNAME_ONLY";
        default:
            return os << "Unknown PasswordFormScheme value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(PasswordFormScheme value)
    {
        return internal::PasswordFormScheme_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }

    enum class PasswordFormFieldPredictionType : int32_t {
        PREDICTION_USERNAME,
        PREDICTION_CURRENT_PASSWORD,
        PREDICTION_NEW_PASSWORD,
        PREDICTION_NOT_PASSWORD,
    };

    inline std::ostream& operator<<(std::ostream& os, PasswordFormFieldPredictionType value)
    {
        switch (value) {
        case PasswordFormFieldPredictionType::PREDICTION_USERNAME:
            return os << "PasswordFormFieldPredictionType::PREDICTION_USERNAME";
        case PasswordFormFieldPredictionType::PREDICTION_CURRENT_PASSWORD:
            return os << "PasswordFormFieldPredictionType::PREDICTION_CURRENT_PASSWORD";
        case PasswordFormFieldPredictionType::PREDICTION_NEW_PASSWORD:
            return os << "PasswordFormFieldPredictionType::PREDICTION_NEW_PASSWORD";
        case PasswordFormFieldPredictionType::PREDICTION_NOT_PASSWORD:
            return os << "PasswordFormFieldPredictionType::PREDICTION_NOT_PASSWORD";
        default:
            return os << "Unknown PasswordFormFieldPredictionType value: " << static_cast<int32_t>(value);
        }
    }
    inline bool IsKnownEnumValue(PasswordFormFieldPredictionType value)
    {
        return internal::PasswordFormFieldPredictionType_Data::IsKnownValue(
            static_cast<int32_t>(value));
    }
    class FormFieldDataDataView {
    public:
        FormFieldDataDataView() { }

        FormFieldDataDataView(
            internal::FormFieldData_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetLabelDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadLabel(UserType* output)
        {
            auto* pointer = data_->label.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetNameDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadName(UserType* output)
        {
            auto* pointer = data_->name.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetValueDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadValue(UserType* output)
        {
            auto* pointer = data_->value.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetFormControlTypeDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFormControlType(UserType* output)
        {
            auto* pointer = data_->form_control_type.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetAutocompleteAttributeDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadAutocompleteAttribute(UserType* output)
        {
            auto* pointer = data_->autocomplete_attribute.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetPlaceholderDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPlaceholder(UserType* output)
        {
            auto* pointer = data_->placeholder.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetCssClassesDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadCssClasses(UserType* output)
        {
            auto* pointer = data_->css_classes.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        uint32_t properties_mask() const
        {
            return data_->properties_mask;
        }
        uint64_t max_length() const
        {
            return data_->max_length;
        }
        bool is_autofilled() const
        {
            return data_->is_autofilled;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadCheckStatus(UserType* output) const
        {
            auto data_value = data_->check_status;
            return mojo::internal::Deserialize<::autofill::mojom::CheckStatus>(
                data_value, output);
        }

        CheckStatus check_status() const
        {
            return static_cast<CheckStatus>(data_->check_status);
        }
        bool is_focusable() const
        {
            return data_->is_focusable;
        }
        bool should_autocomplete() const
        {
            return data_->should_autocomplete;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadRole(UserType* output) const
        {
            auto data_value = data_->role;
            return mojo::internal::Deserialize<::autofill::mojom::RoleAttribute>(
                data_value, output);
        }

        RoleAttribute role() const
        {
            return static_cast<RoleAttribute>(data_->role);
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
        inline void GetOptionValuesDataView(
            mojo::ArrayDataView<mojo::StringDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOptionValues(UserType* output)
        {
            auto* pointer = data_->option_values.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<mojo::StringDataView>>(
                pointer, output, context_);
        }
        inline void GetOptionContentsDataView(
            mojo::ArrayDataView<mojo::StringDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOptionContents(UserType* output)
        {
            auto* pointer = data_->option_contents.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<mojo::StringDataView>>(
                pointer, output, context_);
        }

    private:
        internal::FormFieldData_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class FormDataDataView {
    public:
        FormDataDataView() { }

        FormDataDataView(
            internal::FormData_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetNameDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadName(UserType* output)
        {
            auto* pointer = data_->name.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetOriginDataView(
            ::url::mojom::UrlDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOrigin(UserType* output)
        {
            auto* pointer = data_->origin.Get();
            return mojo::internal::Deserialize<::url::mojom::UrlDataView>(
                pointer, output, context_);
        }
        inline void GetActionDataView(
            ::url::mojom::UrlDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadAction(UserType* output)
        {
            auto* pointer = data_->action.Get();
            return mojo::internal::Deserialize<::url::mojom::UrlDataView>(
                pointer, output, context_);
        }
        bool is_form_tag() const
        {
            return data_->is_form_tag;
        }
        bool is_formless_checkout() const
        {
            return data_->is_formless_checkout;
        }
        inline void GetFieldsDataView(
            mojo::ArrayDataView<FormFieldDataDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFields(UserType* output)
        {
            auto* pointer = data_->fields.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::autofill::mojom::FormFieldDataDataView>>(
                pointer, output, context_);
        }

    private:
        internal::FormData_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class FormFieldDataPredictionsDataView {
    public:
        FormFieldDataPredictionsDataView() { }

        FormFieldDataPredictionsDataView(
            internal::FormFieldDataPredictions_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetFieldDataView(
            FormFieldDataDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadField(UserType* output)
        {
            auto* pointer = data_->field.Get();
            return mojo::internal::Deserialize<::autofill::mojom::FormFieldDataDataView>(
                pointer, output, context_);
        }
        inline void GetSignatureDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSignature(UserType* output)
        {
            auto* pointer = data_->signature.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetHeuristicTypeDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadHeuristicType(UserType* output)
        {
            auto* pointer = data_->heuristic_type.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetServerTypeDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadServerType(UserType* output)
        {
            auto* pointer = data_->server_type.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetOverallTypeDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOverallType(UserType* output)
        {
            auto* pointer = data_->overall_type.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetParseableNameDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadParseableName(UserType* output)
        {
            auto* pointer = data_->parseable_name.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::FormFieldDataPredictions_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class FormDataPredictionsDataView {
    public:
        FormDataPredictionsDataView() { }

        FormDataPredictionsDataView(
            internal::FormDataPredictions_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetDataDataView(
            FormDataDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadData(UserType* output)
        {
            auto* pointer = data_->data.Get();
            return mojo::internal::Deserialize<::autofill::mojom::FormDataDataView>(
                pointer, output, context_);
        }
        inline void GetSignatureDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSignature(UserType* output)
        {
            auto* pointer = data_->signature.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetFieldsDataView(
            mojo::ArrayDataView<FormFieldDataPredictionsDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFields(UserType* output)
        {
            auto* pointer = data_->fields.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::autofill::mojom::FormFieldDataPredictionsDataView>>(
                pointer, output, context_);
        }

    private:
        internal::FormDataPredictions_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PasswordAndRealmDataView {
    public:
        PasswordAndRealmDataView() { }

        PasswordAndRealmDataView(
            internal::PasswordAndRealm_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetPasswordDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPassword(UserType* output)
        {
            auto* pointer = data_->password.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetRealmDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadRealm(UserType* output)
        {
            auto* pointer = data_->realm.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::PasswordAndRealm_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class UsernamesCollectionKeyDataView {
    public:
        UsernamesCollectionKeyDataView() { }

        UsernamesCollectionKeyDataView(
            internal::UsernamesCollectionKey_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetUsernameDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadUsername(UserType* output)
        {
            auto* pointer = data_->username.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetPasswordDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPassword(UserType* output)
        {
            auto* pointer = data_->password.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetRealmDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadRealm(UserType* output)
        {
            auto* pointer = data_->realm.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::UsernamesCollectionKey_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PasswordFormFillDataDataView {
    public:
        PasswordFormFillDataDataView() { }

        PasswordFormFillDataDataView(
            internal::PasswordFormFillData_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetNameDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadName(UserType* output)
        {
            auto* pointer = data_->name.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetOriginDataView(
            ::url::mojom::UrlDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOrigin(UserType* output)
        {
            auto* pointer = data_->origin.Get();
            return mojo::internal::Deserialize<::url::mojom::UrlDataView>(
                pointer, output, context_);
        }
        inline void GetActionDataView(
            ::url::mojom::UrlDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadAction(UserType* output)
        {
            auto* pointer = data_->action.Get();
            return mojo::internal::Deserialize<::url::mojom::UrlDataView>(
                pointer, output, context_);
        }
        inline void GetUsernameFieldDataView(
            FormFieldDataDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadUsernameField(UserType* output)
        {
            auto* pointer = data_->username_field.Get();
            return mojo::internal::Deserialize<::autofill::mojom::FormFieldDataDataView>(
                pointer, output, context_);
        }
        inline void GetPasswordFieldDataView(
            FormFieldDataDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPasswordField(UserType* output)
        {
            auto* pointer = data_->password_field.Get();
            return mojo::internal::Deserialize<::autofill::mojom::FormFieldDataDataView>(
                pointer, output, context_);
        }
        inline void GetPreferredRealmDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPreferredRealm(UserType* output)
        {
            auto* pointer = data_->preferred_realm.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetAdditionalLoginsDataView(
            mojo::MapDataView<mojo::StringDataView, PasswordAndRealmDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadAdditionalLogins(UserType* output)
        {
            auto* pointer = data_->additional_logins.Get();
            return mojo::internal::Deserialize<mojo::MapDataView<mojo::StringDataView, ::autofill::mojom::PasswordAndRealmDataView>>(
                pointer, output, context_);
        }
        inline void GetOtherPossibleUsernamesKeysDataView(
            mojo::ArrayDataView<UsernamesCollectionKeyDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOtherPossibleUsernamesKeys(UserType* output)
        {
            auto* pointer = data_->other_possible_usernames_keys.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::autofill::mojom::UsernamesCollectionKeyDataView>>(
                pointer, output, context_);
        }
        inline void GetOtherPossibleUsernamesValuesDataView(
            mojo::ArrayDataView<mojo::ArrayDataView<mojo::StringDataView>>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOtherPossibleUsernamesValues(UserType* output)
        {
            auto* pointer = data_->other_possible_usernames_values.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<mojo::ArrayDataView<mojo::StringDataView>>>(
                pointer, output, context_);
        }
        bool wait_for_username() const
        {
            return data_->wait_for_username;
        }
        bool is_possible_change_password_form() const
        {
            return data_->is_possible_change_password_form;
        }

    private:
        internal::PasswordFormFillData_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PasswordFormGenerationDataDataView {
    public:
        PasswordFormGenerationDataDataView() { }

        PasswordFormGenerationDataDataView(
            internal::PasswordFormGenerationData_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint64_t form_signature() const
        {
            return data_->form_signature;
        }
        uint32_t field_signature() const
        {
            return data_->field_signature;
        }

    private:
        internal::PasswordFormGenerationData_Data* data_ = nullptr;
    };

    class PasswordFormDataView {
    public:
        PasswordFormDataView() { }

        PasswordFormDataView(
            internal::PasswordForm_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadScheme(UserType* output) const
        {
            auto data_value = data_->scheme;
            return mojo::internal::Deserialize<::autofill::mojom::PasswordFormScheme>(
                data_value, output);
        }

        PasswordFormScheme scheme() const
        {
            return static_cast<PasswordFormScheme>(data_->scheme);
        }
        inline void GetSignonRealmDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSignonRealm(UserType* output)
        {
            auto* pointer = data_->signon_realm.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetOriginWithPathDataView(
            ::url::mojom::UrlDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOriginWithPath(UserType* output)
        {
            auto* pointer = data_->origin_with_path.Get();
            return mojo::internal::Deserialize<::url::mojom::UrlDataView>(
                pointer, output, context_);
        }
        inline void GetActionDataView(
            ::url::mojom::UrlDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadAction(UserType* output)
        {
            auto* pointer = data_->action.Get();
            return mojo::internal::Deserialize<::url::mojom::UrlDataView>(
                pointer, output, context_);
        }
        inline void GetAffiliatedWebRealmDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadAffiliatedWebRealm(UserType* output)
        {
            auto* pointer = data_->affiliated_web_realm.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetSubmitElementDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadSubmitElement(UserType* output)
        {
            auto* pointer = data_->submit_element.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetUsernameElementDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadUsernameElement(UserType* output)
        {
            auto* pointer = data_->username_element.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        bool username_marked_by_site() const
        {
            return data_->username_marked_by_site;
        }
        inline void GetUsernameValueDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadUsernameValue(UserType* output)
        {
            auto* pointer = data_->username_value.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetOtherPossibleUsernamesDataView(
            mojo::ArrayDataView<mojo::StringDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadOtherPossibleUsernames(UserType* output)
        {
            auto* pointer = data_->other_possible_usernames.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<mojo::StringDataView>>(
                pointer, output, context_);
        }
        inline void GetPasswordElementDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPasswordElement(UserType* output)
        {
            auto* pointer = data_->password_element.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetPasswordValueDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPasswordValue(UserType* output)
        {
            auto* pointer = data_->password_value.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        bool password_value_is_default() const
        {
            return data_->password_value_is_default;
        }
        inline void GetNewPasswordElementDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadNewPasswordElement(UserType* output)
        {
            auto* pointer = data_->new_password_element.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetNewPasswordValueDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadNewPasswordValue(UserType* output)
        {
            auto* pointer = data_->new_password_value.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        bool new_password_value_is_default() const
        {
            return data_->new_password_value_is_default;
        }
        bool new_password_marked_by_site() const
        {
            return data_->new_password_marked_by_site;
        }
        bool preferred() const
        {
            return data_->preferred;
        }
        inline void GetDateCreatedDataView(
            ::mojo::common::mojom::TimeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDateCreated(UserType* output)
        {
            auto* pointer = data_->date_created.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::TimeDataView>(
                pointer, output, context_);
        }
        inline void GetDateSyncedDataView(
            ::mojo::common::mojom::TimeDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDateSynced(UserType* output)
        {
            auto* pointer = data_->date_synced.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::TimeDataView>(
                pointer, output, context_);
        }
        bool blacklisted_by_user() const
        {
            return data_->blacklisted_by_user;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadType(UserType* output) const
        {
            auto data_value = data_->type;
            return mojo::internal::Deserialize<::autofill::mojom::PasswordFormType>(
                data_value, output);
        }

        PasswordFormType type() const
        {
            return static_cast<PasswordFormType>(data_->type);
        }
        int32_t times_used() const
        {
            return data_->times_used;
        }
        inline void GetFormDataDataView(
            FormDataDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFormData(UserType* output)
        {
            auto* pointer = data_->form_data.Get();
            return mojo::internal::Deserialize<::autofill::mojom::FormDataDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadGenerationUploadStatus(UserType* output) const
        {
            auto data_value = data_->generation_upload_status;
            return mojo::internal::Deserialize<::autofill::mojom::GenerationUploadStatus>(
                data_value, output);
        }

        GenerationUploadStatus generation_upload_status() const
        {
            return static_cast<GenerationUploadStatus>(data_->generation_upload_status);
        }
        inline void GetDisplayNameDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDisplayName(UserType* output)
        {
            auto* pointer = data_->display_name.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetIconUrlDataView(
            ::url::mojom::UrlDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadIconUrl(UserType* output)
        {
            auto* pointer = data_->icon_url.Get();
            return mojo::internal::Deserialize<::url::mojom::UrlDataView>(
                pointer, output, context_);
        }
        inline void GetFederationOriginDataView(
            ::url::mojom::OriginDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFederationOrigin(UserType* output)
        {
            auto* pointer = data_->federation_origin.Get();
            return mojo::internal::Deserialize<::url::mojom::OriginDataView>(
                pointer, output, context_);
        }
        bool skip_zero_click() const
        {
            return data_->skip_zero_click;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadLayout(UserType* output) const
        {
            auto data_value = data_->layout;
            return mojo::internal::Deserialize<::autofill::mojom::PasswordFormLayout>(
                data_value, output);
        }

        PasswordFormLayout layout() const
        {
            return static_cast<PasswordFormLayout>(data_->layout);
        }
        bool was_parsed_using_autofill_predictions() const
        {
            return data_->was_parsed_using_autofill_predictions;
        }
        bool is_public_suffix_match() const
        {
            return data_->is_public_suffix_match;
        }
        bool is_affiliation_based_match() const
        {
            return data_->is_affiliation_based_match;
        }
        bool does_look_like_signup_form() const
        {
            return data_->does_look_like_signup_form;
        }

    private:
        internal::PasswordForm_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class PasswordFormFieldPredictionMapDataView {
    public:
        PasswordFormFieldPredictionMapDataView() { }

        PasswordFormFieldPredictionMapDataView(
            internal::PasswordFormFieldPredictionMap_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetKeysDataView(
            mojo::ArrayDataView<FormFieldDataDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadKeys(UserType* output)
        {
            auto* pointer = data_->keys.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::autofill::mojom::FormFieldDataDataView>>(
                pointer, output, context_);
        }
        inline void GetValuesDataView(
            mojo::ArrayDataView<PasswordFormFieldPredictionType>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadValues(UserType* output)
        {
            auto* pointer = data_->values.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::autofill::mojom::PasswordFormFieldPredictionType>>(
                pointer, output, context_);
        }

    private:
        internal::PasswordFormFieldPredictionMap_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class FormsPredictionsMapDataView {
    public:
        FormsPredictionsMapDataView() { }

        FormsPredictionsMapDataView(
            internal::FormsPredictionsMap_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetKeysDataView(
            mojo::ArrayDataView<FormDataDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadKeys(UserType* output)
        {
            auto* pointer = data_->keys.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::autofill::mojom::FormDataDataView>>(
                pointer, output, context_);
        }
        inline void GetValuesDataView(
            mojo::ArrayDataView<PasswordFormFieldPredictionMapDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadValues(UserType* output)
        {
            auto* pointer = data_->values.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::autofill::mojom::PasswordFormFieldPredictionMapDataView>>(
                pointer, output, context_);
        }

    private:
        internal::FormsPredictionsMap_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace autofill

namespace std {

template <>
struct hash<::autofill::mojom::CheckStatus>
    : public mojo::internal::EnumHashImpl<::autofill::mojom::CheckStatus> {
};

template <>
struct hash<::autofill::mojom::RoleAttribute>
    : public mojo::internal::EnumHashImpl<::autofill::mojom::RoleAttribute> {
};

template <>
struct hash<::autofill::mojom::GenerationUploadStatus>
    : public mojo::internal::EnumHashImpl<::autofill::mojom::GenerationUploadStatus> {
};

template <>
struct hash<::autofill::mojom::PasswordFormLayout>
    : public mojo::internal::EnumHashImpl<::autofill::mojom::PasswordFormLayout> {
};

template <>
struct hash<::autofill::mojom::PasswordFormType>
    : public mojo::internal::EnumHashImpl<::autofill::mojom::PasswordFormType> {
};

template <>
struct hash<::autofill::mojom::PasswordFormScheme>
    : public mojo::internal::EnumHashImpl<::autofill::mojom::PasswordFormScheme> {
};

template <>
struct hash<::autofill::mojom::PasswordFormFieldPredictionType>
    : public mojo::internal::EnumHashImpl<::autofill::mojom::PasswordFormFieldPredictionType> {
};

} // namespace std

namespace mojo {

template <>
struct EnumTraits<::autofill::mojom::CheckStatus, ::autofill::mojom::CheckStatus> {
    static ::autofill::mojom::CheckStatus ToMojom(::autofill::mojom::CheckStatus input) { return input; }
    static bool FromMojom(::autofill::mojom::CheckStatus input, ::autofill::mojom::CheckStatus* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::autofill::mojom::CheckStatus, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::autofill::mojom::CheckStatus, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::autofill::mojom::CheckStatus>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::autofill::mojom::RoleAttribute, ::autofill::mojom::RoleAttribute> {
    static ::autofill::mojom::RoleAttribute ToMojom(::autofill::mojom::RoleAttribute input) { return input; }
    static bool FromMojom(::autofill::mojom::RoleAttribute input, ::autofill::mojom::RoleAttribute* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::autofill::mojom::RoleAttribute, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::autofill::mojom::RoleAttribute, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::autofill::mojom::RoleAttribute>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::autofill::mojom::GenerationUploadStatus, ::autofill::mojom::GenerationUploadStatus> {
    static ::autofill::mojom::GenerationUploadStatus ToMojom(::autofill::mojom::GenerationUploadStatus input) { return input; }
    static bool FromMojom(::autofill::mojom::GenerationUploadStatus input, ::autofill::mojom::GenerationUploadStatus* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::autofill::mojom::GenerationUploadStatus, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::autofill::mojom::GenerationUploadStatus, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::autofill::mojom::GenerationUploadStatus>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::autofill::mojom::PasswordFormLayout, ::autofill::mojom::PasswordFormLayout> {
    static ::autofill::mojom::PasswordFormLayout ToMojom(::autofill::mojom::PasswordFormLayout input) { return input; }
    static bool FromMojom(::autofill::mojom::PasswordFormLayout input, ::autofill::mojom::PasswordFormLayout* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::autofill::mojom::PasswordFormLayout, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::autofill::mojom::PasswordFormLayout, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::autofill::mojom::PasswordFormLayout>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::autofill::mojom::PasswordFormType, ::autofill::mojom::PasswordFormType> {
    static ::autofill::mojom::PasswordFormType ToMojom(::autofill::mojom::PasswordFormType input) { return input; }
    static bool FromMojom(::autofill::mojom::PasswordFormType input, ::autofill::mojom::PasswordFormType* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::autofill::mojom::PasswordFormType, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::autofill::mojom::PasswordFormType, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::autofill::mojom::PasswordFormType>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::autofill::mojom::PasswordFormScheme, ::autofill::mojom::PasswordFormScheme> {
    static ::autofill::mojom::PasswordFormScheme ToMojom(::autofill::mojom::PasswordFormScheme input) { return input; }
    static bool FromMojom(::autofill::mojom::PasswordFormScheme input, ::autofill::mojom::PasswordFormScheme* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::autofill::mojom::PasswordFormScheme, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::autofill::mojom::PasswordFormScheme, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::autofill::mojom::PasswordFormScheme>(input), output);
        }
    };

} // namespace internal

template <>
struct EnumTraits<::autofill::mojom::PasswordFormFieldPredictionType, ::autofill::mojom::PasswordFormFieldPredictionType> {
    static ::autofill::mojom::PasswordFormFieldPredictionType ToMojom(::autofill::mojom::PasswordFormFieldPredictionType input) { return input; }
    static bool FromMojom(::autofill::mojom::PasswordFormFieldPredictionType input, ::autofill::mojom::PasswordFormFieldPredictionType* output)
    {
        *output = input;
        return true;
    }
};

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::autofill::mojom::PasswordFormFieldPredictionType, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = EnumTraits<::autofill::mojom::PasswordFormFieldPredictionType, UserType>;

        static void Serialize(UserType input, int32_t* output)
        {
            *output = static_cast<int32_t>(Traits::ToMojom(input));
        }

        static bool Deserialize(int32_t input, UserType* output)
        {
            return Traits::FromMojom(static_cast<::autofill::mojom::PasswordFormFieldPredictionType>(input), output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::autofill::mojom::FormFieldDataDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::autofill::mojom::FormFieldDataDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::autofill::mojom::internal::FormFieldData_Data);
            decltype(CallWithContext(Traits::label, input, custom_context)) in_label = CallWithContext(Traits::label, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_label, context);
            decltype(CallWithContext(Traits::name, input, custom_context)) in_name = CallWithContext(Traits::name, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_name, context);
            decltype(CallWithContext(Traits::value, input, custom_context)) in_value = CallWithContext(Traits::value, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_value, context);
            decltype(CallWithContext(Traits::form_control_type, input, custom_context)) in_form_control_type = CallWithContext(Traits::form_control_type, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_form_control_type, context);
            decltype(CallWithContext(Traits::autocomplete_attribute, input, custom_context)) in_autocomplete_attribute = CallWithContext(Traits::autocomplete_attribute, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_autocomplete_attribute, context);
            decltype(CallWithContext(Traits::placeholder, input, custom_context)) in_placeholder = CallWithContext(Traits::placeholder, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_placeholder, context);
            decltype(CallWithContext(Traits::css_classes, input, custom_context)) in_css_classes = CallWithContext(Traits::css_classes, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_css_classes, context);
            decltype(CallWithContext(Traits::option_values, input, custom_context)) in_option_values = CallWithContext(Traits::option_values, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<mojo::StringDataView>>(
                in_option_values, context);
            decltype(CallWithContext(Traits::option_contents, input, custom_context)) in_option_contents = CallWithContext(Traits::option_contents, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<mojo::StringDataView>>(
                in_option_contents, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::autofill::mojom::internal::FormFieldData_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::autofill::mojom::internal::FormFieldData_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::label, input, custom_context)) in_label = CallWithContext(Traits::label, input, custom_context);
            typename decltype(result->label)::BaseType* label_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_label, buffer, &label_ptr, context);
            result->label.Set(label_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->label.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null label in FormFieldData struct");
            decltype(CallWithContext(Traits::name, input, custom_context)) in_name = CallWithContext(Traits::name, input, custom_context);
            typename decltype(result->name)::BaseType* name_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_name, buffer, &name_ptr, context);
            result->name.Set(name_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->name.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null name in FormFieldData struct");
            decltype(CallWithContext(Traits::value, input, custom_context)) in_value = CallWithContext(Traits::value, input, custom_context);
            typename decltype(result->value)::BaseType* value_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_value, buffer, &value_ptr, context);
            result->value.Set(value_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->value.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null value in FormFieldData struct");
            decltype(CallWithContext(Traits::form_control_type, input, custom_context)) in_form_control_type = CallWithContext(Traits::form_control_type, input, custom_context);
            typename decltype(result->form_control_type)::BaseType* form_control_type_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_form_control_type, buffer, &form_control_type_ptr, context);
            result->form_control_type.Set(form_control_type_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->form_control_type.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null form_control_type in FormFieldData struct");
            decltype(CallWithContext(Traits::autocomplete_attribute, input, custom_context)) in_autocomplete_attribute = CallWithContext(Traits::autocomplete_attribute, input, custom_context);
            typename decltype(result->autocomplete_attribute)::BaseType* autocomplete_attribute_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_autocomplete_attribute, buffer, &autocomplete_attribute_ptr, context);
            result->autocomplete_attribute.Set(autocomplete_attribute_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->autocomplete_attribute.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null autocomplete_attribute in FormFieldData struct");
            decltype(CallWithContext(Traits::placeholder, input, custom_context)) in_placeholder = CallWithContext(Traits::placeholder, input, custom_context);
            typename decltype(result->placeholder)::BaseType* placeholder_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_placeholder, buffer, &placeholder_ptr, context);
            result->placeholder.Set(placeholder_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->placeholder.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null placeholder in FormFieldData struct");
            decltype(CallWithContext(Traits::css_classes, input, custom_context)) in_css_classes = CallWithContext(Traits::css_classes, input, custom_context);
            typename decltype(result->css_classes)::BaseType* css_classes_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_css_classes, buffer, &css_classes_ptr, context);
            result->css_classes.Set(css_classes_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->css_classes.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null css_classes in FormFieldData struct");
            result->properties_mask = CallWithContext(Traits::properties_mask, input, custom_context);
            result->max_length = CallWithContext(Traits::max_length, input, custom_context);
            result->is_autofilled = CallWithContext(Traits::is_autofilled, input, custom_context);
            mojo::internal::Serialize<::autofill::mojom::CheckStatus>(
                CallWithContext(Traits::check_status, input, custom_context), &result->check_status);
            result->is_focusable = CallWithContext(Traits::is_focusable, input, custom_context);
            result->should_autocomplete = CallWithContext(Traits::should_autocomplete, input, custom_context);
            mojo::internal::Serialize<::autofill::mojom::RoleAttribute>(
                CallWithContext(Traits::role, input, custom_context), &result->role);
            mojo::internal::Serialize<::mojo::common::mojom::TextDirection>(
                CallWithContext(Traits::text_direction, input, custom_context), &result->text_direction);
            decltype(CallWithContext(Traits::option_values, input, custom_context)) in_option_values = CallWithContext(Traits::option_values, input, custom_context);
            typename decltype(result->option_values)::BaseType* option_values_ptr;
            const mojo::internal::ContainerValidateParams option_values_validate_params(
                0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr));
            mojo::internal::Serialize<mojo::ArrayDataView<mojo::StringDataView>>(
                in_option_values, buffer, &option_values_ptr, &option_values_validate_params,
                context);
            result->option_values.Set(option_values_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->option_values.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null option_values in FormFieldData struct");
            decltype(CallWithContext(Traits::option_contents, input, custom_context)) in_option_contents = CallWithContext(Traits::option_contents, input, custom_context);
            typename decltype(result->option_contents)::BaseType* option_contents_ptr;
            const mojo::internal::ContainerValidateParams option_contents_validate_params(
                0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr));
            mojo::internal::Serialize<mojo::ArrayDataView<mojo::StringDataView>>(
                in_option_contents, buffer, &option_contents_ptr, &option_contents_validate_params,
                context);
            result->option_contents.Set(option_contents_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->option_contents.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null option_contents in FormFieldData struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::autofill::mojom::internal::FormFieldData_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::autofill::mojom::FormFieldDataDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::autofill::mojom::FormDataDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::autofill::mojom::FormDataDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::autofill::mojom::internal::FormData_Data);
            decltype(CallWithContext(Traits::name, input, custom_context)) in_name = CallWithContext(Traits::name, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_name, context);
            decltype(CallWithContext(Traits::origin, input, custom_context)) in_origin = CallWithContext(Traits::origin, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::url::mojom::UrlDataView>(
                in_origin, context);
            decltype(CallWithContext(Traits::action, input, custom_context)) in_action = CallWithContext(Traits::action, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::url::mojom::UrlDataView>(
                in_action, context);
            decltype(CallWithContext(Traits::fields, input, custom_context)) in_fields = CallWithContext(Traits::fields, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::autofill::mojom::FormFieldDataDataView>>(
                in_fields, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::autofill::mojom::internal::FormData_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::autofill::mojom::internal::FormData_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::name, input, custom_context)) in_name = CallWithContext(Traits::name, input, custom_context);
            typename decltype(result->name)::BaseType* name_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_name, buffer, &name_ptr, context);
            result->name.Set(name_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->name.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null name in FormData struct");
            decltype(CallWithContext(Traits::origin, input, custom_context)) in_origin = CallWithContext(Traits::origin, input, custom_context);
            typename decltype(result->origin)::BaseType* origin_ptr;
            mojo::internal::Serialize<::url::mojom::UrlDataView>(
                in_origin, buffer, &origin_ptr, context);
            result->origin.Set(origin_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->origin.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null origin in FormData struct");
            decltype(CallWithContext(Traits::action, input, custom_context)) in_action = CallWithContext(Traits::action, input, custom_context);
            typename decltype(result->action)::BaseType* action_ptr;
            mojo::internal::Serialize<::url::mojom::UrlDataView>(
                in_action, buffer, &action_ptr, context);
            result->action.Set(action_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->action.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null action in FormData struct");
            result->is_form_tag = CallWithContext(Traits::is_form_tag, input, custom_context);
            result->is_formless_checkout = CallWithContext(Traits::is_formless_checkout, input, custom_context);
            decltype(CallWithContext(Traits::fields, input, custom_context)) in_fields = CallWithContext(Traits::fields, input, custom_context);
            typename decltype(result->fields)::BaseType* fields_ptr;
            const mojo::internal::ContainerValidateParams fields_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::autofill::mojom::FormFieldDataDataView>>(
                in_fields, buffer, &fields_ptr, &fields_validate_params,
                context);
            result->fields.Set(fields_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->fields.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null fields in FormData struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::autofill::mojom::internal::FormData_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::autofill::mojom::FormDataDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::autofill::mojom::FormFieldDataPredictionsDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::autofill::mojom::FormFieldDataPredictionsDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::autofill::mojom::internal::FormFieldDataPredictions_Data);
            decltype(CallWithContext(Traits::field, input, custom_context)) in_field = CallWithContext(Traits::field, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::autofill::mojom::FormFieldDataDataView>(
                in_field, context);
            decltype(CallWithContext(Traits::signature, input, custom_context)) in_signature = CallWithContext(Traits::signature, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_signature, context);
            decltype(CallWithContext(Traits::heuristic_type, input, custom_context)) in_heuristic_type = CallWithContext(Traits::heuristic_type, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_heuristic_type, context);
            decltype(CallWithContext(Traits::server_type, input, custom_context)) in_server_type = CallWithContext(Traits::server_type, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_server_type, context);
            decltype(CallWithContext(Traits::overall_type, input, custom_context)) in_overall_type = CallWithContext(Traits::overall_type, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_overall_type, context);
            decltype(CallWithContext(Traits::parseable_name, input, custom_context)) in_parseable_name = CallWithContext(Traits::parseable_name, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_parseable_name, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::autofill::mojom::internal::FormFieldDataPredictions_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::autofill::mojom::internal::FormFieldDataPredictions_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::field, input, custom_context)) in_field = CallWithContext(Traits::field, input, custom_context);
            typename decltype(result->field)::BaseType* field_ptr;
            mojo::internal::Serialize<::autofill::mojom::FormFieldDataDataView>(
                in_field, buffer, &field_ptr, context);
            result->field.Set(field_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->field.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null field in FormFieldDataPredictions struct");
            decltype(CallWithContext(Traits::signature, input, custom_context)) in_signature = CallWithContext(Traits::signature, input, custom_context);
            typename decltype(result->signature)::BaseType* signature_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_signature, buffer, &signature_ptr, context);
            result->signature.Set(signature_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->signature.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null signature in FormFieldDataPredictions struct");
            decltype(CallWithContext(Traits::heuristic_type, input, custom_context)) in_heuristic_type = CallWithContext(Traits::heuristic_type, input, custom_context);
            typename decltype(result->heuristic_type)::BaseType* heuristic_type_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_heuristic_type, buffer, &heuristic_type_ptr, context);
            result->heuristic_type.Set(heuristic_type_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->heuristic_type.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null heuristic_type in FormFieldDataPredictions struct");
            decltype(CallWithContext(Traits::server_type, input, custom_context)) in_server_type = CallWithContext(Traits::server_type, input, custom_context);
            typename decltype(result->server_type)::BaseType* server_type_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_server_type, buffer, &server_type_ptr, context);
            result->server_type.Set(server_type_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->server_type.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null server_type in FormFieldDataPredictions struct");
            decltype(CallWithContext(Traits::overall_type, input, custom_context)) in_overall_type = CallWithContext(Traits::overall_type, input, custom_context);
            typename decltype(result->overall_type)::BaseType* overall_type_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_overall_type, buffer, &overall_type_ptr, context);
            result->overall_type.Set(overall_type_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->overall_type.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null overall_type in FormFieldDataPredictions struct");
            decltype(CallWithContext(Traits::parseable_name, input, custom_context)) in_parseable_name = CallWithContext(Traits::parseable_name, input, custom_context);
            typename decltype(result->parseable_name)::BaseType* parseable_name_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_parseable_name, buffer, &parseable_name_ptr, context);
            result->parseable_name.Set(parseable_name_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->parseable_name.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null parseable_name in FormFieldDataPredictions struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::autofill::mojom::internal::FormFieldDataPredictions_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::autofill::mojom::FormFieldDataPredictionsDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::autofill::mojom::FormDataPredictionsDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::autofill::mojom::FormDataPredictionsDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::autofill::mojom::internal::FormDataPredictions_Data);
            decltype(CallWithContext(Traits::data, input, custom_context)) in_data = CallWithContext(Traits::data, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::autofill::mojom::FormDataDataView>(
                in_data, context);
            decltype(CallWithContext(Traits::signature, input, custom_context)) in_signature = CallWithContext(Traits::signature, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_signature, context);
            decltype(CallWithContext(Traits::fields, input, custom_context)) in_fields = CallWithContext(Traits::fields, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::autofill::mojom::FormFieldDataPredictionsDataView>>(
                in_fields, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::autofill::mojom::internal::FormDataPredictions_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::autofill::mojom::internal::FormDataPredictions_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::data, input, custom_context)) in_data = CallWithContext(Traits::data, input, custom_context);
            typename decltype(result->data)::BaseType* data_ptr;
            mojo::internal::Serialize<::autofill::mojom::FormDataDataView>(
                in_data, buffer, &data_ptr, context);
            result->data.Set(data_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->data.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null data in FormDataPredictions struct");
            decltype(CallWithContext(Traits::signature, input, custom_context)) in_signature = CallWithContext(Traits::signature, input, custom_context);
            typename decltype(result->signature)::BaseType* signature_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_signature, buffer, &signature_ptr, context);
            result->signature.Set(signature_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->signature.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null signature in FormDataPredictions struct");
            decltype(CallWithContext(Traits::fields, input, custom_context)) in_fields = CallWithContext(Traits::fields, input, custom_context);
            typename decltype(result->fields)::BaseType* fields_ptr;
            const mojo::internal::ContainerValidateParams fields_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::autofill::mojom::FormFieldDataPredictionsDataView>>(
                in_fields, buffer, &fields_ptr, &fields_validate_params,
                context);
            result->fields.Set(fields_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->fields.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null fields in FormDataPredictions struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::autofill::mojom::internal::FormDataPredictions_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::autofill::mojom::FormDataPredictionsDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::autofill::mojom::PasswordAndRealmDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::autofill::mojom::PasswordAndRealmDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::autofill::mojom::internal::PasswordAndRealm_Data);
            decltype(CallWithContext(Traits::password, input, custom_context)) in_password = CallWithContext(Traits::password, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_password, context);
            decltype(CallWithContext(Traits::realm, input, custom_context)) in_realm = CallWithContext(Traits::realm, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_realm, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::autofill::mojom::internal::PasswordAndRealm_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::autofill::mojom::internal::PasswordAndRealm_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::password, input, custom_context)) in_password = CallWithContext(Traits::password, input, custom_context);
            typename decltype(result->password)::BaseType* password_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_password, buffer, &password_ptr, context);
            result->password.Set(password_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->password.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null password in PasswordAndRealm struct");
            decltype(CallWithContext(Traits::realm, input, custom_context)) in_realm = CallWithContext(Traits::realm, input, custom_context);
            typename decltype(result->realm)::BaseType* realm_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_realm, buffer, &realm_ptr, context);
            result->realm.Set(realm_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->realm.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null realm in PasswordAndRealm struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::autofill::mojom::internal::PasswordAndRealm_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::autofill::mojom::PasswordAndRealmDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::autofill::mojom::UsernamesCollectionKeyDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::autofill::mojom::UsernamesCollectionKeyDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::autofill::mojom::internal::UsernamesCollectionKey_Data);
            decltype(CallWithContext(Traits::username, input, custom_context)) in_username = CallWithContext(Traits::username, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_username, context);
            decltype(CallWithContext(Traits::password, input, custom_context)) in_password = CallWithContext(Traits::password, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_password, context);
            decltype(CallWithContext(Traits::realm, input, custom_context)) in_realm = CallWithContext(Traits::realm, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_realm, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::autofill::mojom::internal::UsernamesCollectionKey_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::autofill::mojom::internal::UsernamesCollectionKey_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::username, input, custom_context)) in_username = CallWithContext(Traits::username, input, custom_context);
            typename decltype(result->username)::BaseType* username_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_username, buffer, &username_ptr, context);
            result->username.Set(username_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->username.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null username in UsernamesCollectionKey struct");
            decltype(CallWithContext(Traits::password, input, custom_context)) in_password = CallWithContext(Traits::password, input, custom_context);
            typename decltype(result->password)::BaseType* password_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_password, buffer, &password_ptr, context);
            result->password.Set(password_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->password.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null password in UsernamesCollectionKey struct");
            decltype(CallWithContext(Traits::realm, input, custom_context)) in_realm = CallWithContext(Traits::realm, input, custom_context);
            typename decltype(result->realm)::BaseType* realm_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_realm, buffer, &realm_ptr, context);
            result->realm.Set(realm_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->realm.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null realm in UsernamesCollectionKey struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::autofill::mojom::internal::UsernamesCollectionKey_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::autofill::mojom::UsernamesCollectionKeyDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::autofill::mojom::PasswordFormFillDataDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::autofill::mojom::PasswordFormFillDataDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::autofill::mojom::internal::PasswordFormFillData_Data);
            decltype(CallWithContext(Traits::name, input, custom_context)) in_name = CallWithContext(Traits::name, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_name, context);
            decltype(CallWithContext(Traits::origin, input, custom_context)) in_origin = CallWithContext(Traits::origin, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::url::mojom::UrlDataView>(
                in_origin, context);
            decltype(CallWithContext(Traits::action, input, custom_context)) in_action = CallWithContext(Traits::action, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::url::mojom::UrlDataView>(
                in_action, context);
            decltype(CallWithContext(Traits::username_field, input, custom_context)) in_username_field = CallWithContext(Traits::username_field, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::autofill::mojom::FormFieldDataDataView>(
                in_username_field, context);
            decltype(CallWithContext(Traits::password_field, input, custom_context)) in_password_field = CallWithContext(Traits::password_field, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::autofill::mojom::FormFieldDataDataView>(
                in_password_field, context);
            decltype(CallWithContext(Traits::preferred_realm, input, custom_context)) in_preferred_realm = CallWithContext(Traits::preferred_realm, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_preferred_realm, context);
            decltype(CallWithContext(Traits::additional_logins, input, custom_context)) in_additional_logins = CallWithContext(Traits::additional_logins, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::MapDataView<mojo::StringDataView, ::autofill::mojom::PasswordAndRealmDataView>>(
                in_additional_logins, context);
            decltype(CallWithContext(Traits::other_possible_usernames_keys, input, custom_context)) in_other_possible_usernames_keys = CallWithContext(Traits::other_possible_usernames_keys, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::autofill::mojom::UsernamesCollectionKeyDataView>>(
                in_other_possible_usernames_keys, context);
            decltype(CallWithContext(Traits::other_possible_usernames_values, input, custom_context)) in_other_possible_usernames_values = CallWithContext(Traits::other_possible_usernames_values, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<mojo::ArrayDataView<mojo::StringDataView>>>(
                in_other_possible_usernames_values, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::autofill::mojom::internal::PasswordFormFillData_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::autofill::mojom::internal::PasswordFormFillData_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::name, input, custom_context)) in_name = CallWithContext(Traits::name, input, custom_context);
            typename decltype(result->name)::BaseType* name_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_name, buffer, &name_ptr, context);
            result->name.Set(name_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->name.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null name in PasswordFormFillData struct");
            decltype(CallWithContext(Traits::origin, input, custom_context)) in_origin = CallWithContext(Traits::origin, input, custom_context);
            typename decltype(result->origin)::BaseType* origin_ptr;
            mojo::internal::Serialize<::url::mojom::UrlDataView>(
                in_origin, buffer, &origin_ptr, context);
            result->origin.Set(origin_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->origin.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null origin in PasswordFormFillData struct");
            decltype(CallWithContext(Traits::action, input, custom_context)) in_action = CallWithContext(Traits::action, input, custom_context);
            typename decltype(result->action)::BaseType* action_ptr;
            mojo::internal::Serialize<::url::mojom::UrlDataView>(
                in_action, buffer, &action_ptr, context);
            result->action.Set(action_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->action.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null action in PasswordFormFillData struct");
            decltype(CallWithContext(Traits::username_field, input, custom_context)) in_username_field = CallWithContext(Traits::username_field, input, custom_context);
            typename decltype(result->username_field)::BaseType* username_field_ptr;
            mojo::internal::Serialize<::autofill::mojom::FormFieldDataDataView>(
                in_username_field, buffer, &username_field_ptr, context);
            result->username_field.Set(username_field_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->username_field.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null username_field in PasswordFormFillData struct");
            decltype(CallWithContext(Traits::password_field, input, custom_context)) in_password_field = CallWithContext(Traits::password_field, input, custom_context);
            typename decltype(result->password_field)::BaseType* password_field_ptr;
            mojo::internal::Serialize<::autofill::mojom::FormFieldDataDataView>(
                in_password_field, buffer, &password_field_ptr, context);
            result->password_field.Set(password_field_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->password_field.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null password_field in PasswordFormFillData struct");
            decltype(CallWithContext(Traits::preferred_realm, input, custom_context)) in_preferred_realm = CallWithContext(Traits::preferred_realm, input, custom_context);
            typename decltype(result->preferred_realm)::BaseType* preferred_realm_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_preferred_realm, buffer, &preferred_realm_ptr, context);
            result->preferred_realm.Set(preferred_realm_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->preferred_realm.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null preferred_realm in PasswordFormFillData struct");
            decltype(CallWithContext(Traits::additional_logins, input, custom_context)) in_additional_logins = CallWithContext(Traits::additional_logins, input, custom_context);
            typename decltype(result->additional_logins)::BaseType* additional_logins_ptr;
            const mojo::internal::ContainerValidateParams additional_logins_validate_params(
                new mojo::internal::ContainerValidateParams(0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr)), new mojo::internal::ContainerValidateParams(0, false, nullptr));
            mojo::internal::Serialize<mojo::MapDataView<mojo::StringDataView, ::autofill::mojom::PasswordAndRealmDataView>>(
                in_additional_logins, buffer, &additional_logins_ptr, &additional_logins_validate_params,
                context);
            result->additional_logins.Set(additional_logins_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->additional_logins.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null additional_logins in PasswordFormFillData struct");
            decltype(CallWithContext(Traits::other_possible_usernames_keys, input, custom_context)) in_other_possible_usernames_keys = CallWithContext(Traits::other_possible_usernames_keys, input, custom_context);
            typename decltype(result->other_possible_usernames_keys)::BaseType* other_possible_usernames_keys_ptr;
            const mojo::internal::ContainerValidateParams other_possible_usernames_keys_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::autofill::mojom::UsernamesCollectionKeyDataView>>(
                in_other_possible_usernames_keys, buffer, &other_possible_usernames_keys_ptr, &other_possible_usernames_keys_validate_params,
                context);
            result->other_possible_usernames_keys.Set(other_possible_usernames_keys_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->other_possible_usernames_keys.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null other_possible_usernames_keys in PasswordFormFillData struct");
            decltype(CallWithContext(Traits::other_possible_usernames_values, input, custom_context)) in_other_possible_usernames_values = CallWithContext(Traits::other_possible_usernames_values, input, custom_context);
            typename decltype(result->other_possible_usernames_values)::BaseType* other_possible_usernames_values_ptr;
            const mojo::internal::ContainerValidateParams other_possible_usernames_values_validate_params(
                0, false, new mojo::internal::ContainerValidateParams(0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr)));
            mojo::internal::Serialize<mojo::ArrayDataView<mojo::ArrayDataView<mojo::StringDataView>>>(
                in_other_possible_usernames_values, buffer, &other_possible_usernames_values_ptr, &other_possible_usernames_values_validate_params,
                context);
            result->other_possible_usernames_values.Set(other_possible_usernames_values_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->other_possible_usernames_values.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null other_possible_usernames_values in PasswordFormFillData struct");
            result->wait_for_username = CallWithContext(Traits::wait_for_username, input, custom_context);
            result->is_possible_change_password_form = CallWithContext(Traits::is_possible_change_password_form, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::autofill::mojom::internal::PasswordFormFillData_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::autofill::mojom::PasswordFormFillDataDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::autofill::mojom::PasswordFormGenerationDataDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::autofill::mojom::PasswordFormGenerationDataDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::autofill::mojom::internal::PasswordFormGenerationData_Data);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::autofill::mojom::internal::PasswordFormGenerationData_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::autofill::mojom::internal::PasswordFormGenerationData_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            result->form_signature = CallWithContext(Traits::form_signature, input, custom_context);
            result->field_signature = CallWithContext(Traits::field_signature, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::autofill::mojom::internal::PasswordFormGenerationData_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::autofill::mojom::PasswordFormGenerationDataDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::autofill::mojom::PasswordFormDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::autofill::mojom::PasswordFormDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::autofill::mojom::internal::PasswordForm_Data);
            decltype(CallWithContext(Traits::signon_realm, input, custom_context)) in_signon_realm = CallWithContext(Traits::signon_realm, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_signon_realm, context);
            decltype(CallWithContext(Traits::origin_with_path, input, custom_context)) in_origin_with_path = CallWithContext(Traits::origin_with_path, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::url::mojom::UrlDataView>(
                in_origin_with_path, context);
            decltype(CallWithContext(Traits::action, input, custom_context)) in_action = CallWithContext(Traits::action, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::url::mojom::UrlDataView>(
                in_action, context);
            decltype(CallWithContext(Traits::affiliated_web_realm, input, custom_context)) in_affiliated_web_realm = CallWithContext(Traits::affiliated_web_realm, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_affiliated_web_realm, context);
            decltype(CallWithContext(Traits::submit_element, input, custom_context)) in_submit_element = CallWithContext(Traits::submit_element, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_submit_element, context);
            decltype(CallWithContext(Traits::username_element, input, custom_context)) in_username_element = CallWithContext(Traits::username_element, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_username_element, context);
            decltype(CallWithContext(Traits::username_value, input, custom_context)) in_username_value = CallWithContext(Traits::username_value, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_username_value, context);
            decltype(CallWithContext(Traits::other_possible_usernames, input, custom_context)) in_other_possible_usernames = CallWithContext(Traits::other_possible_usernames, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<mojo::StringDataView>>(
                in_other_possible_usernames, context);
            decltype(CallWithContext(Traits::password_element, input, custom_context)) in_password_element = CallWithContext(Traits::password_element, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_password_element, context);
            decltype(CallWithContext(Traits::password_value, input, custom_context)) in_password_value = CallWithContext(Traits::password_value, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_password_value, context);
            decltype(CallWithContext(Traits::new_password_element, input, custom_context)) in_new_password_element = CallWithContext(Traits::new_password_element, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_new_password_element, context);
            decltype(CallWithContext(Traits::new_password_value, input, custom_context)) in_new_password_value = CallWithContext(Traits::new_password_value, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_new_password_value, context);
            decltype(CallWithContext(Traits::date_created, input, custom_context)) in_date_created = CallWithContext(Traits::date_created, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::TimeDataView>(
                in_date_created, context);
            decltype(CallWithContext(Traits::date_synced, input, custom_context)) in_date_synced = CallWithContext(Traits::date_synced, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::TimeDataView>(
                in_date_synced, context);
            decltype(CallWithContext(Traits::form_data, input, custom_context)) in_form_data = CallWithContext(Traits::form_data, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::autofill::mojom::FormDataDataView>(
                in_form_data, context);
            decltype(CallWithContext(Traits::display_name, input, custom_context)) in_display_name = CallWithContext(Traits::display_name, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_display_name, context);
            decltype(CallWithContext(Traits::icon_url, input, custom_context)) in_icon_url = CallWithContext(Traits::icon_url, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::url::mojom::UrlDataView>(
                in_icon_url, context);
            decltype(CallWithContext(Traits::federation_origin, input, custom_context)) in_federation_origin = CallWithContext(Traits::federation_origin, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::url::mojom::OriginDataView>(
                in_federation_origin, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::autofill::mojom::internal::PasswordForm_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::autofill::mojom::internal::PasswordForm_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            mojo::internal::Serialize<::autofill::mojom::PasswordFormScheme>(
                CallWithContext(Traits::scheme, input, custom_context), &result->scheme);
            decltype(CallWithContext(Traits::signon_realm, input, custom_context)) in_signon_realm = CallWithContext(Traits::signon_realm, input, custom_context);
            typename decltype(result->signon_realm)::BaseType* signon_realm_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_signon_realm, buffer, &signon_realm_ptr, context);
            result->signon_realm.Set(signon_realm_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->signon_realm.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null signon_realm in PasswordForm struct");
            decltype(CallWithContext(Traits::origin_with_path, input, custom_context)) in_origin_with_path = CallWithContext(Traits::origin_with_path, input, custom_context);
            typename decltype(result->origin_with_path)::BaseType* origin_with_path_ptr;
            mojo::internal::Serialize<::url::mojom::UrlDataView>(
                in_origin_with_path, buffer, &origin_with_path_ptr, context);
            result->origin_with_path.Set(origin_with_path_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->origin_with_path.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null origin_with_path in PasswordForm struct");
            decltype(CallWithContext(Traits::action, input, custom_context)) in_action = CallWithContext(Traits::action, input, custom_context);
            typename decltype(result->action)::BaseType* action_ptr;
            mojo::internal::Serialize<::url::mojom::UrlDataView>(
                in_action, buffer, &action_ptr, context);
            result->action.Set(action_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->action.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null action in PasswordForm struct");
            decltype(CallWithContext(Traits::affiliated_web_realm, input, custom_context)) in_affiliated_web_realm = CallWithContext(Traits::affiliated_web_realm, input, custom_context);
            typename decltype(result->affiliated_web_realm)::BaseType* affiliated_web_realm_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_affiliated_web_realm, buffer, &affiliated_web_realm_ptr, context);
            result->affiliated_web_realm.Set(affiliated_web_realm_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->affiliated_web_realm.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null affiliated_web_realm in PasswordForm struct");
            decltype(CallWithContext(Traits::submit_element, input, custom_context)) in_submit_element = CallWithContext(Traits::submit_element, input, custom_context);
            typename decltype(result->submit_element)::BaseType* submit_element_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_submit_element, buffer, &submit_element_ptr, context);
            result->submit_element.Set(submit_element_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->submit_element.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null submit_element in PasswordForm struct");
            decltype(CallWithContext(Traits::username_element, input, custom_context)) in_username_element = CallWithContext(Traits::username_element, input, custom_context);
            typename decltype(result->username_element)::BaseType* username_element_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_username_element, buffer, &username_element_ptr, context);
            result->username_element.Set(username_element_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->username_element.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null username_element in PasswordForm struct");
            result->username_marked_by_site = CallWithContext(Traits::username_marked_by_site, input, custom_context);
            decltype(CallWithContext(Traits::username_value, input, custom_context)) in_username_value = CallWithContext(Traits::username_value, input, custom_context);
            typename decltype(result->username_value)::BaseType* username_value_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_username_value, buffer, &username_value_ptr, context);
            result->username_value.Set(username_value_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->username_value.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null username_value in PasswordForm struct");
            decltype(CallWithContext(Traits::other_possible_usernames, input, custom_context)) in_other_possible_usernames = CallWithContext(Traits::other_possible_usernames, input, custom_context);
            typename decltype(result->other_possible_usernames)::BaseType* other_possible_usernames_ptr;
            const mojo::internal::ContainerValidateParams other_possible_usernames_validate_params(
                0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr));
            mojo::internal::Serialize<mojo::ArrayDataView<mojo::StringDataView>>(
                in_other_possible_usernames, buffer, &other_possible_usernames_ptr, &other_possible_usernames_validate_params,
                context);
            result->other_possible_usernames.Set(other_possible_usernames_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->other_possible_usernames.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null other_possible_usernames in PasswordForm struct");
            decltype(CallWithContext(Traits::password_element, input, custom_context)) in_password_element = CallWithContext(Traits::password_element, input, custom_context);
            typename decltype(result->password_element)::BaseType* password_element_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_password_element, buffer, &password_element_ptr, context);
            result->password_element.Set(password_element_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->password_element.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null password_element in PasswordForm struct");
            decltype(CallWithContext(Traits::password_value, input, custom_context)) in_password_value = CallWithContext(Traits::password_value, input, custom_context);
            typename decltype(result->password_value)::BaseType* password_value_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_password_value, buffer, &password_value_ptr, context);
            result->password_value.Set(password_value_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->password_value.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null password_value in PasswordForm struct");
            result->password_value_is_default = CallWithContext(Traits::password_value_is_default, input, custom_context);
            decltype(CallWithContext(Traits::new_password_element, input, custom_context)) in_new_password_element = CallWithContext(Traits::new_password_element, input, custom_context);
            typename decltype(result->new_password_element)::BaseType* new_password_element_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_new_password_element, buffer, &new_password_element_ptr, context);
            result->new_password_element.Set(new_password_element_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->new_password_element.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null new_password_element in PasswordForm struct");
            decltype(CallWithContext(Traits::new_password_value, input, custom_context)) in_new_password_value = CallWithContext(Traits::new_password_value, input, custom_context);
            typename decltype(result->new_password_value)::BaseType* new_password_value_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_new_password_value, buffer, &new_password_value_ptr, context);
            result->new_password_value.Set(new_password_value_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->new_password_value.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null new_password_value in PasswordForm struct");
            result->new_password_value_is_default = CallWithContext(Traits::new_password_value_is_default, input, custom_context);
            result->new_password_marked_by_site = CallWithContext(Traits::new_password_marked_by_site, input, custom_context);
            result->preferred = CallWithContext(Traits::preferred, input, custom_context);
            decltype(CallWithContext(Traits::date_created, input, custom_context)) in_date_created = CallWithContext(Traits::date_created, input, custom_context);
            typename decltype(result->date_created)::BaseType* date_created_ptr;
            mojo::internal::Serialize<::mojo::common::mojom::TimeDataView>(
                in_date_created, buffer, &date_created_ptr, context);
            result->date_created.Set(date_created_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->date_created.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null date_created in PasswordForm struct");
            decltype(CallWithContext(Traits::date_synced, input, custom_context)) in_date_synced = CallWithContext(Traits::date_synced, input, custom_context);
            typename decltype(result->date_synced)::BaseType* date_synced_ptr;
            mojo::internal::Serialize<::mojo::common::mojom::TimeDataView>(
                in_date_synced, buffer, &date_synced_ptr, context);
            result->date_synced.Set(date_synced_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->date_synced.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null date_synced in PasswordForm struct");
            result->blacklisted_by_user = CallWithContext(Traits::blacklisted_by_user, input, custom_context);
            mojo::internal::Serialize<::autofill::mojom::PasswordFormType>(
                CallWithContext(Traits::type, input, custom_context), &result->type);
            result->times_used = CallWithContext(Traits::times_used, input, custom_context);
            decltype(CallWithContext(Traits::form_data, input, custom_context)) in_form_data = CallWithContext(Traits::form_data, input, custom_context);
            typename decltype(result->form_data)::BaseType* form_data_ptr;
            mojo::internal::Serialize<::autofill::mojom::FormDataDataView>(
                in_form_data, buffer, &form_data_ptr, context);
            result->form_data.Set(form_data_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->form_data.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null form_data in PasswordForm struct");
            mojo::internal::Serialize<::autofill::mojom::GenerationUploadStatus>(
                CallWithContext(Traits::generation_upload_status, input, custom_context), &result->generation_upload_status);
            decltype(CallWithContext(Traits::display_name, input, custom_context)) in_display_name = CallWithContext(Traits::display_name, input, custom_context);
            typename decltype(result->display_name)::BaseType* display_name_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_display_name, buffer, &display_name_ptr, context);
            result->display_name.Set(display_name_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->display_name.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null display_name in PasswordForm struct");
            decltype(CallWithContext(Traits::icon_url, input, custom_context)) in_icon_url = CallWithContext(Traits::icon_url, input, custom_context);
            typename decltype(result->icon_url)::BaseType* icon_url_ptr;
            mojo::internal::Serialize<::url::mojom::UrlDataView>(
                in_icon_url, buffer, &icon_url_ptr, context);
            result->icon_url.Set(icon_url_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->icon_url.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null icon_url in PasswordForm struct");
            decltype(CallWithContext(Traits::federation_origin, input, custom_context)) in_federation_origin = CallWithContext(Traits::federation_origin, input, custom_context);
            typename decltype(result->federation_origin)::BaseType* federation_origin_ptr;
            mojo::internal::Serialize<::url::mojom::OriginDataView>(
                in_federation_origin, buffer, &federation_origin_ptr, context);
            result->federation_origin.Set(federation_origin_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->federation_origin.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null federation_origin in PasswordForm struct");
            result->skip_zero_click = CallWithContext(Traits::skip_zero_click, input, custom_context);
            mojo::internal::Serialize<::autofill::mojom::PasswordFormLayout>(
                CallWithContext(Traits::layout, input, custom_context), &result->layout);
            result->was_parsed_using_autofill_predictions = CallWithContext(Traits::was_parsed_using_autofill_predictions, input, custom_context);
            result->is_public_suffix_match = CallWithContext(Traits::is_public_suffix_match, input, custom_context);
            result->is_affiliation_based_match = CallWithContext(Traits::is_affiliation_based_match, input, custom_context);
            result->does_look_like_signup_form = CallWithContext(Traits::does_look_like_signup_form, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::autofill::mojom::internal::PasswordForm_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::autofill::mojom::PasswordFormDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::autofill::mojom::PasswordFormFieldPredictionMapDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::autofill::mojom::PasswordFormFieldPredictionMapDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::autofill::mojom::internal::PasswordFormFieldPredictionMap_Data);
            decltype(CallWithContext(Traits::keys, input, custom_context)) in_keys = CallWithContext(Traits::keys, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::autofill::mojom::FormFieldDataDataView>>(
                in_keys, context);
            decltype(CallWithContext(Traits::values, input, custom_context)) in_values = CallWithContext(Traits::values, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::autofill::mojom::PasswordFormFieldPredictionType>>(
                in_values, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::autofill::mojom::internal::PasswordFormFieldPredictionMap_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::autofill::mojom::internal::PasswordFormFieldPredictionMap_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::keys, input, custom_context)) in_keys = CallWithContext(Traits::keys, input, custom_context);
            typename decltype(result->keys)::BaseType* keys_ptr;
            const mojo::internal::ContainerValidateParams keys_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::autofill::mojom::FormFieldDataDataView>>(
                in_keys, buffer, &keys_ptr, &keys_validate_params,
                context);
            result->keys.Set(keys_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->keys.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null keys in PasswordFormFieldPredictionMap struct");
            decltype(CallWithContext(Traits::values, input, custom_context)) in_values = CallWithContext(Traits::values, input, custom_context);
            typename decltype(result->values)::BaseType* values_ptr;
            const mojo::internal::ContainerValidateParams values_validate_params(
                0, ::autofill::mojom::internal::PasswordFormFieldPredictionType_Data::Validate);
            mojo::internal::Serialize<mojo::ArrayDataView<::autofill::mojom::PasswordFormFieldPredictionType>>(
                in_values, buffer, &values_ptr, &values_validate_params,
                context);
            result->values.Set(values_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->values.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null values in PasswordFormFieldPredictionMap struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::autofill::mojom::internal::PasswordFormFieldPredictionMap_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::autofill::mojom::PasswordFormFieldPredictionMapDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::autofill::mojom::FormsPredictionsMapDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::autofill::mojom::FormsPredictionsMapDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::autofill::mojom::internal::FormsPredictionsMap_Data);
            decltype(CallWithContext(Traits::keys, input, custom_context)) in_keys = CallWithContext(Traits::keys, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::autofill::mojom::FormDataDataView>>(
                in_keys, context);
            decltype(CallWithContext(Traits::values, input, custom_context)) in_values = CallWithContext(Traits::values, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::autofill::mojom::PasswordFormFieldPredictionMapDataView>>(
                in_values, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::autofill::mojom::internal::FormsPredictionsMap_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::autofill::mojom::internal::FormsPredictionsMap_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::keys, input, custom_context)) in_keys = CallWithContext(Traits::keys, input, custom_context);
            typename decltype(result->keys)::BaseType* keys_ptr;
            const mojo::internal::ContainerValidateParams keys_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::autofill::mojom::FormDataDataView>>(
                in_keys, buffer, &keys_ptr, &keys_validate_params,
                context);
            result->keys.Set(keys_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->keys.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null keys in FormsPredictionsMap struct");
            decltype(CallWithContext(Traits::values, input, custom_context)) in_values = CallWithContext(Traits::values, input, custom_context);
            typename decltype(result->values)::BaseType* values_ptr;
            const mojo::internal::ContainerValidateParams values_validate_params(
                0, false, nullptr);
            mojo::internal::Serialize<mojo::ArrayDataView<::autofill::mojom::PasswordFormFieldPredictionMapDataView>>(
                in_values, buffer, &values_ptr, &values_validate_params,
                context);
            result->values.Set(values_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->values.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null values in FormsPredictionsMap struct");
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::autofill::mojom::internal::FormsPredictionsMap_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::autofill::mojom::FormsPredictionsMapDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace autofill {
namespace mojom {

    inline void FormFieldDataDataView::GetLabelDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->label.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void FormFieldDataDataView::GetNameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->name.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void FormFieldDataDataView::GetValueDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->value.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void FormFieldDataDataView::GetFormControlTypeDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->form_control_type.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void FormFieldDataDataView::GetAutocompleteAttributeDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->autocomplete_attribute.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void FormFieldDataDataView::GetPlaceholderDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->placeholder.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void FormFieldDataDataView::GetCssClassesDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->css_classes.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void FormFieldDataDataView::GetOptionValuesDataView(
        mojo::ArrayDataView<mojo::StringDataView>* output)
    {
        auto pointer = data_->option_values.Get();
        *output = mojo::ArrayDataView<mojo::StringDataView>(pointer, context_);
    }
    inline void FormFieldDataDataView::GetOptionContentsDataView(
        mojo::ArrayDataView<mojo::StringDataView>* output)
    {
        auto pointer = data_->option_contents.Get();
        *output = mojo::ArrayDataView<mojo::StringDataView>(pointer, context_);
    }

    inline void FormDataDataView::GetNameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->name.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void FormDataDataView::GetOriginDataView(
        ::url::mojom::UrlDataView* output)
    {
        auto pointer = data_->origin.Get();
        *output = ::url::mojom::UrlDataView(pointer, context_);
    }
    inline void FormDataDataView::GetActionDataView(
        ::url::mojom::UrlDataView* output)
    {
        auto pointer = data_->action.Get();
        *output = ::url::mojom::UrlDataView(pointer, context_);
    }
    inline void FormDataDataView::GetFieldsDataView(
        mojo::ArrayDataView<FormFieldDataDataView>* output)
    {
        auto pointer = data_->fields.Get();
        *output = mojo::ArrayDataView<FormFieldDataDataView>(pointer, context_);
    }

    inline void FormFieldDataPredictionsDataView::GetFieldDataView(
        FormFieldDataDataView* output)
    {
        auto pointer = data_->field.Get();
        *output = FormFieldDataDataView(pointer, context_);
    }
    inline void FormFieldDataPredictionsDataView::GetSignatureDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->signature.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void FormFieldDataPredictionsDataView::GetHeuristicTypeDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->heuristic_type.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void FormFieldDataPredictionsDataView::GetServerTypeDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->server_type.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void FormFieldDataPredictionsDataView::GetOverallTypeDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->overall_type.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void FormFieldDataPredictionsDataView::GetParseableNameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->parseable_name.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void FormDataPredictionsDataView::GetDataDataView(
        FormDataDataView* output)
    {
        auto pointer = data_->data.Get();
        *output = FormDataDataView(pointer, context_);
    }
    inline void FormDataPredictionsDataView::GetSignatureDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->signature.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void FormDataPredictionsDataView::GetFieldsDataView(
        mojo::ArrayDataView<FormFieldDataPredictionsDataView>* output)
    {
        auto pointer = data_->fields.Get();
        *output = mojo::ArrayDataView<FormFieldDataPredictionsDataView>(pointer, context_);
    }

    inline void PasswordAndRealmDataView::GetPasswordDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->password.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PasswordAndRealmDataView::GetRealmDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->realm.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void UsernamesCollectionKeyDataView::GetUsernameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->username.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void UsernamesCollectionKeyDataView::GetPasswordDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->password.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void UsernamesCollectionKeyDataView::GetRealmDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->realm.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void PasswordFormFillDataDataView::GetNameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->name.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PasswordFormFillDataDataView::GetOriginDataView(
        ::url::mojom::UrlDataView* output)
    {
        auto pointer = data_->origin.Get();
        *output = ::url::mojom::UrlDataView(pointer, context_);
    }
    inline void PasswordFormFillDataDataView::GetActionDataView(
        ::url::mojom::UrlDataView* output)
    {
        auto pointer = data_->action.Get();
        *output = ::url::mojom::UrlDataView(pointer, context_);
    }
    inline void PasswordFormFillDataDataView::GetUsernameFieldDataView(
        FormFieldDataDataView* output)
    {
        auto pointer = data_->username_field.Get();
        *output = FormFieldDataDataView(pointer, context_);
    }
    inline void PasswordFormFillDataDataView::GetPasswordFieldDataView(
        FormFieldDataDataView* output)
    {
        auto pointer = data_->password_field.Get();
        *output = FormFieldDataDataView(pointer, context_);
    }
    inline void PasswordFormFillDataDataView::GetPreferredRealmDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->preferred_realm.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PasswordFormFillDataDataView::GetAdditionalLoginsDataView(
        mojo::MapDataView<mojo::StringDataView, PasswordAndRealmDataView>* output)
    {
        auto pointer = data_->additional_logins.Get();
        *output = mojo::MapDataView<mojo::StringDataView, PasswordAndRealmDataView>(pointer, context_);
    }
    inline void PasswordFormFillDataDataView::GetOtherPossibleUsernamesKeysDataView(
        mojo::ArrayDataView<UsernamesCollectionKeyDataView>* output)
    {
        auto pointer = data_->other_possible_usernames_keys.Get();
        *output = mojo::ArrayDataView<UsernamesCollectionKeyDataView>(pointer, context_);
    }
    inline void PasswordFormFillDataDataView::GetOtherPossibleUsernamesValuesDataView(
        mojo::ArrayDataView<mojo::ArrayDataView<mojo::StringDataView>>* output)
    {
        auto pointer = data_->other_possible_usernames_values.Get();
        *output = mojo::ArrayDataView<mojo::ArrayDataView<mojo::StringDataView>>(pointer, context_);
    }

    inline void PasswordFormDataView::GetSignonRealmDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->signon_realm.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PasswordFormDataView::GetOriginWithPathDataView(
        ::url::mojom::UrlDataView* output)
    {
        auto pointer = data_->origin_with_path.Get();
        *output = ::url::mojom::UrlDataView(pointer, context_);
    }
    inline void PasswordFormDataView::GetActionDataView(
        ::url::mojom::UrlDataView* output)
    {
        auto pointer = data_->action.Get();
        *output = ::url::mojom::UrlDataView(pointer, context_);
    }
    inline void PasswordFormDataView::GetAffiliatedWebRealmDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->affiliated_web_realm.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PasswordFormDataView::GetSubmitElementDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->submit_element.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PasswordFormDataView::GetUsernameElementDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->username_element.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PasswordFormDataView::GetUsernameValueDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->username_value.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PasswordFormDataView::GetOtherPossibleUsernamesDataView(
        mojo::ArrayDataView<mojo::StringDataView>* output)
    {
        auto pointer = data_->other_possible_usernames.Get();
        *output = mojo::ArrayDataView<mojo::StringDataView>(pointer, context_);
    }
    inline void PasswordFormDataView::GetPasswordElementDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->password_element.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PasswordFormDataView::GetPasswordValueDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->password_value.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PasswordFormDataView::GetNewPasswordElementDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->new_password_element.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PasswordFormDataView::GetNewPasswordValueDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->new_password_value.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PasswordFormDataView::GetDateCreatedDataView(
        ::mojo::common::mojom::TimeDataView* output)
    {
        auto pointer = data_->date_created.Get();
        *output = ::mojo::common::mojom::TimeDataView(pointer, context_);
    }
    inline void PasswordFormDataView::GetDateSyncedDataView(
        ::mojo::common::mojom::TimeDataView* output)
    {
        auto pointer = data_->date_synced.Get();
        *output = ::mojo::common::mojom::TimeDataView(pointer, context_);
    }
    inline void PasswordFormDataView::GetFormDataDataView(
        FormDataDataView* output)
    {
        auto pointer = data_->form_data.Get();
        *output = FormDataDataView(pointer, context_);
    }
    inline void PasswordFormDataView::GetDisplayNameDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->display_name.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void PasswordFormDataView::GetIconUrlDataView(
        ::url::mojom::UrlDataView* output)
    {
        auto pointer = data_->icon_url.Get();
        *output = ::url::mojom::UrlDataView(pointer, context_);
    }
    inline void PasswordFormDataView::GetFederationOriginDataView(
        ::url::mojom::OriginDataView* output)
    {
        auto pointer = data_->federation_origin.Get();
        *output = ::url::mojom::OriginDataView(pointer, context_);
    }

    inline void PasswordFormFieldPredictionMapDataView::GetKeysDataView(
        mojo::ArrayDataView<FormFieldDataDataView>* output)
    {
        auto pointer = data_->keys.Get();
        *output = mojo::ArrayDataView<FormFieldDataDataView>(pointer, context_);
    }
    inline void PasswordFormFieldPredictionMapDataView::GetValuesDataView(
        mojo::ArrayDataView<PasswordFormFieldPredictionType>* output)
    {
        auto pointer = data_->values.Get();
        *output = mojo::ArrayDataView<PasswordFormFieldPredictionType>(pointer, context_);
    }

    inline void FormsPredictionsMapDataView::GetKeysDataView(
        mojo::ArrayDataView<FormDataDataView>* output)
    {
        auto pointer = data_->keys.Get();
        *output = mojo::ArrayDataView<FormDataDataView>(pointer, context_);
    }
    inline void FormsPredictionsMapDataView::GetValuesDataView(
        mojo::ArrayDataView<PasswordFormFieldPredictionMapDataView>* output)
    {
        auto pointer = data_->values.Get();
        *output = mojo::ArrayDataView<PasswordFormFieldPredictionMapDataView>(pointer, context_);
    }

} // namespace mojom
} // namespace autofill

#endif // COMPONENTS_AUTOFILL_CONTENT_COMMON_AUTOFILL_TYPES_MOJOM_SHARED_H_
