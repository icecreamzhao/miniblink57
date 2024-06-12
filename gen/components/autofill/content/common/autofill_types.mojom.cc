// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-private-field"
#elif defined(_MSC_VER)
#pragma warning(push)
#pragma warning(disable : 4056)
#pragma warning(disable : 4065)
#pragma warning(disable : 4756)
#endif

#include "components/autofill/content/common/autofill_types.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "components/autofill/content/common/autofill_types_struct_traits.h"
#include "ipc/ipc_message_utils.h"
#include "mojo/common/common_custom_types_struct_traits.h"
#include "mojo/common/values_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
#include "url/mojo/origin_struct_traits.h"
#include "url/mojo/url_gurl_struct_traits.h"
namespace autofill {
namespace mojom { // static
    FormFieldDataPtr FormFieldData::New()
    {
        FormFieldDataPtr rv;
        mojo::internal::StructHelper<FormFieldData>::Initialize(&rv);
        return rv;
    }

    FormFieldData::FormFieldData()
        : label()
        , name()
        , value()
        , form_control_type()
        , autocomplete_attribute()
        , placeholder()
        , css_classes()
        , properties_mask()
        , max_length()
        , is_autofilled()
        , check_status()
        , is_focusable()
        , should_autocomplete()
        , role()
        , text_direction()
        , option_values()
        , option_contents()
    {
    }

    FormFieldData::~FormFieldData()
    {
    } // static
    FormDataPtr FormData::New()
    {
        FormDataPtr rv;
        mojo::internal::StructHelper<FormData>::Initialize(&rv);
        return rv;
    }

    FormData::FormData()
        : name()
        , origin()
        , action()
        , is_form_tag()
        , is_formless_checkout()
        , fields()
    {
    }

    FormData::~FormData()
    {
    } // static
    FormFieldDataPredictionsPtr FormFieldDataPredictions::New()
    {
        FormFieldDataPredictionsPtr rv;
        mojo::internal::StructHelper<FormFieldDataPredictions>::Initialize(&rv);
        return rv;
    }

    FormFieldDataPredictions::FormFieldDataPredictions()
        : field()
        , signature()
        , heuristic_type()
        , server_type()
        , overall_type()
        , parseable_name()
    {
    }

    FormFieldDataPredictions::~FormFieldDataPredictions()
    {
    } // static
    FormDataPredictionsPtr FormDataPredictions::New()
    {
        FormDataPredictionsPtr rv;
        mojo::internal::StructHelper<FormDataPredictions>::Initialize(&rv);
        return rv;
    }

    FormDataPredictions::FormDataPredictions()
        : data()
        , signature()
        , fields()
    {
    }

    FormDataPredictions::~FormDataPredictions()
    {
    } // static
    PasswordAndRealmPtr PasswordAndRealm::New()
    {
        PasswordAndRealmPtr rv;
        mojo::internal::StructHelper<PasswordAndRealm>::Initialize(&rv);
        return rv;
    }

    PasswordAndRealm::PasswordAndRealm()
        : password()
        , realm()
    {
    }

    PasswordAndRealm::~PasswordAndRealm()
    {
    } // static
    UsernamesCollectionKeyPtr UsernamesCollectionKey::New()
    {
        UsernamesCollectionKeyPtr rv;
        mojo::internal::StructHelper<UsernamesCollectionKey>::Initialize(&rv);
        return rv;
    }

    UsernamesCollectionKey::UsernamesCollectionKey()
        : username()
        , password()
        , realm()
    {
    }

    UsernamesCollectionKey::~UsernamesCollectionKey()
    {
    } // static
    PasswordFormFillDataPtr PasswordFormFillData::New()
    {
        PasswordFormFillDataPtr rv;
        mojo::internal::StructHelper<PasswordFormFillData>::Initialize(&rv);
        return rv;
    }

    PasswordFormFillData::PasswordFormFillData()
        : name()
        , origin()
        , action()
        , username_field()
        , password_field()
        , preferred_realm()
        , additional_logins()
        , other_possible_usernames_keys()
        , other_possible_usernames_values()
        , wait_for_username()
        , is_possible_change_password_form()
    {
    }

    PasswordFormFillData::~PasswordFormFillData()
    {
    } // static
    PasswordFormGenerationDataPtr PasswordFormGenerationData::New()
    {
        PasswordFormGenerationDataPtr rv;
        mojo::internal::StructHelper<PasswordFormGenerationData>::Initialize(&rv);
        return rv;
    }

    PasswordFormGenerationData::PasswordFormGenerationData()
        : form_signature()
        , field_signature()
    {
    }

    PasswordFormGenerationData::~PasswordFormGenerationData()
    {
    } // static
    PasswordFormPtr PasswordForm::New()
    {
        PasswordFormPtr rv;
        mojo::internal::StructHelper<PasswordForm>::Initialize(&rv);
        return rv;
    }

    PasswordForm::PasswordForm()
        : scheme()
        , signon_realm()
        , origin_with_path()
        , action()
        , affiliated_web_realm()
        , submit_element()
        , username_element()
        , username_marked_by_site()
        , username_value()
        , other_possible_usernames()
        , password_element()
        , password_value()
        , password_value_is_default()
        , new_password_element()
        , new_password_value()
        , new_password_value_is_default()
        , new_password_marked_by_site()
        , preferred()
        , date_created()
        , date_synced()
        , blacklisted_by_user()
        , type()
        , times_used()
        , form_data()
        , generation_upload_status()
        , display_name()
        , icon_url()
        , federation_origin()
        , skip_zero_click()
        , layout()
        , was_parsed_using_autofill_predictions()
        , is_public_suffix_match()
        , is_affiliation_based_match()
        , does_look_like_signup_form()
    {
    }

    PasswordForm::~PasswordForm()
    {
    } // static
    PasswordFormFieldPredictionMapPtr PasswordFormFieldPredictionMap::New()
    {
        PasswordFormFieldPredictionMapPtr rv;
        mojo::internal::StructHelper<PasswordFormFieldPredictionMap>::Initialize(&rv);
        return rv;
    }

    PasswordFormFieldPredictionMap::PasswordFormFieldPredictionMap()
        : keys()
        , values()
    {
    }

    PasswordFormFieldPredictionMap::~PasswordFormFieldPredictionMap()
    {
    } // static
    FormsPredictionsMapPtr FormsPredictionsMap::New()
    {
        FormsPredictionsMapPtr rv;
        mojo::internal::StructHelper<FormsPredictionsMap>::Initialize(&rv);
        return rv;
    }

    FormsPredictionsMap::FormsPredictionsMap()
        : keys()
        , values()
    {
    }

    FormsPredictionsMap::~FormsPredictionsMap()
    {
    }
} // namespace mojom
} // namespace autofill

namespace mojo {

// static
bool StructTraits<::autofill::mojom::FormFieldData::DataView, ::autofill::mojom::FormFieldDataPtr>::Read(
    ::autofill::mojom::FormFieldData::DataView input,
    ::autofill::mojom::FormFieldDataPtr* output)
{
    bool success = true;
    ::autofill::mojom::FormFieldDataPtr result(::autofill::mojom::FormFieldData::New());

    if (!input.ReadLabel(&result->label))
        success = false;
    if (!input.ReadName(&result->name))
        success = false;
    if (!input.ReadValue(&result->value))
        success = false;
    if (!input.ReadFormControlType(&result->form_control_type))
        success = false;
    if (!input.ReadAutocompleteAttribute(&result->autocomplete_attribute))
        success = false;
    if (!input.ReadPlaceholder(&result->placeholder))
        success = false;
    if (!input.ReadCssClasses(&result->css_classes))
        success = false;
    result->properties_mask = input.properties_mask();
    result->max_length = input.max_length();
    result->is_autofilled = input.is_autofilled();
    if (!input.ReadCheckStatus(&result->check_status))
        success = false;
    result->is_focusable = input.is_focusable();
    result->should_autocomplete = input.should_autocomplete();
    if (!input.ReadRole(&result->role))
        success = false;
    if (!input.ReadTextDirection(&result->text_direction))
        success = false;
    if (!input.ReadOptionValues(&result->option_values))
        success = false;
    if (!input.ReadOptionContents(&result->option_contents))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::autofill::mojom::FormData::DataView, ::autofill::mojom::FormDataPtr>::Read(
    ::autofill::mojom::FormData::DataView input,
    ::autofill::mojom::FormDataPtr* output)
{
    bool success = true;
    ::autofill::mojom::FormDataPtr result(::autofill::mojom::FormData::New());

    if (!input.ReadName(&result->name))
        success = false;
    if (!input.ReadOrigin(&result->origin))
        success = false;
    if (!input.ReadAction(&result->action))
        success = false;
    result->is_form_tag = input.is_form_tag();
    result->is_formless_checkout = input.is_formless_checkout();
    if (!input.ReadFields(&result->fields))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::autofill::mojom::FormFieldDataPredictions::DataView, ::autofill::mojom::FormFieldDataPredictionsPtr>::Read(
    ::autofill::mojom::FormFieldDataPredictions::DataView input,
    ::autofill::mojom::FormFieldDataPredictionsPtr* output)
{
    bool success = true;
    ::autofill::mojom::FormFieldDataPredictionsPtr result(::autofill::mojom::FormFieldDataPredictions::New());

    if (!input.ReadField(&result->field))
        success = false;
    if (!input.ReadSignature(&result->signature))
        success = false;
    if (!input.ReadHeuristicType(&result->heuristic_type))
        success = false;
    if (!input.ReadServerType(&result->server_type))
        success = false;
    if (!input.ReadOverallType(&result->overall_type))
        success = false;
    if (!input.ReadParseableName(&result->parseable_name))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::autofill::mojom::FormDataPredictions::DataView, ::autofill::mojom::FormDataPredictionsPtr>::Read(
    ::autofill::mojom::FormDataPredictions::DataView input,
    ::autofill::mojom::FormDataPredictionsPtr* output)
{
    bool success = true;
    ::autofill::mojom::FormDataPredictionsPtr result(::autofill::mojom::FormDataPredictions::New());

    if (!input.ReadData(&result->data))
        success = false;
    if (!input.ReadSignature(&result->signature))
        success = false;
    if (!input.ReadFields(&result->fields))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::autofill::mojom::PasswordAndRealm::DataView, ::autofill::mojom::PasswordAndRealmPtr>::Read(
    ::autofill::mojom::PasswordAndRealm::DataView input,
    ::autofill::mojom::PasswordAndRealmPtr* output)
{
    bool success = true;
    ::autofill::mojom::PasswordAndRealmPtr result(::autofill::mojom::PasswordAndRealm::New());

    if (!input.ReadPassword(&result->password))
        success = false;
    if (!input.ReadRealm(&result->realm))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::autofill::mojom::UsernamesCollectionKey::DataView, ::autofill::mojom::UsernamesCollectionKeyPtr>::Read(
    ::autofill::mojom::UsernamesCollectionKey::DataView input,
    ::autofill::mojom::UsernamesCollectionKeyPtr* output)
{
    bool success = true;
    ::autofill::mojom::UsernamesCollectionKeyPtr result(::autofill::mojom::UsernamesCollectionKey::New());

    if (!input.ReadUsername(&result->username))
        success = false;
    if (!input.ReadPassword(&result->password))
        success = false;
    if (!input.ReadRealm(&result->realm))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::autofill::mojom::PasswordFormFillData::DataView, ::autofill::mojom::PasswordFormFillDataPtr>::Read(
    ::autofill::mojom::PasswordFormFillData::DataView input,
    ::autofill::mojom::PasswordFormFillDataPtr* output)
{
    bool success = true;
    ::autofill::mojom::PasswordFormFillDataPtr result(::autofill::mojom::PasswordFormFillData::New());

    if (!input.ReadName(&result->name))
        success = false;
    if (!input.ReadOrigin(&result->origin))
        success = false;
    if (!input.ReadAction(&result->action))
        success = false;
    if (!input.ReadUsernameField(&result->username_field))
        success = false;
    if (!input.ReadPasswordField(&result->password_field))
        success = false;
    if (!input.ReadPreferredRealm(&result->preferred_realm))
        success = false;
    if (!input.ReadAdditionalLogins(&result->additional_logins))
        success = false;
    if (!input.ReadOtherPossibleUsernamesKeys(&result->other_possible_usernames_keys))
        success = false;
    if (!input.ReadOtherPossibleUsernamesValues(&result->other_possible_usernames_values))
        success = false;
    result->wait_for_username = input.wait_for_username();
    result->is_possible_change_password_form = input.is_possible_change_password_form();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::autofill::mojom::PasswordFormGenerationData::DataView, ::autofill::mojom::PasswordFormGenerationDataPtr>::Read(
    ::autofill::mojom::PasswordFormGenerationData::DataView input,
    ::autofill::mojom::PasswordFormGenerationDataPtr* output)
{
    bool success = true;
    ::autofill::mojom::PasswordFormGenerationDataPtr result(::autofill::mojom::PasswordFormGenerationData::New());

    result->form_signature = input.form_signature();
    result->field_signature = input.field_signature();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::autofill::mojom::PasswordForm::DataView, ::autofill::mojom::PasswordFormPtr>::Read(
    ::autofill::mojom::PasswordForm::DataView input,
    ::autofill::mojom::PasswordFormPtr* output)
{
    bool success = true;
    ::autofill::mojom::PasswordFormPtr result(::autofill::mojom::PasswordForm::New());

    if (!input.ReadScheme(&result->scheme))
        success = false;
    if (!input.ReadSignonRealm(&result->signon_realm))
        success = false;
    if (!input.ReadOriginWithPath(&result->origin_with_path))
        success = false;
    if (!input.ReadAction(&result->action))
        success = false;
    if (!input.ReadAffiliatedWebRealm(&result->affiliated_web_realm))
        success = false;
    if (!input.ReadSubmitElement(&result->submit_element))
        success = false;
    if (!input.ReadUsernameElement(&result->username_element))
        success = false;
    result->username_marked_by_site = input.username_marked_by_site();
    if (!input.ReadUsernameValue(&result->username_value))
        success = false;
    if (!input.ReadOtherPossibleUsernames(&result->other_possible_usernames))
        success = false;
    if (!input.ReadPasswordElement(&result->password_element))
        success = false;
    if (!input.ReadPasswordValue(&result->password_value))
        success = false;
    result->password_value_is_default = input.password_value_is_default();
    if (!input.ReadNewPasswordElement(&result->new_password_element))
        success = false;
    if (!input.ReadNewPasswordValue(&result->new_password_value))
        success = false;
    result->new_password_value_is_default = input.new_password_value_is_default();
    result->new_password_marked_by_site = input.new_password_marked_by_site();
    result->preferred = input.preferred();
    if (!input.ReadDateCreated(&result->date_created))
        success = false;
    if (!input.ReadDateSynced(&result->date_synced))
        success = false;
    result->blacklisted_by_user = input.blacklisted_by_user();
    if (!input.ReadType(&result->type))
        success = false;
    result->times_used = input.times_used();
    if (!input.ReadFormData(&result->form_data))
        success = false;
    if (!input.ReadGenerationUploadStatus(&result->generation_upload_status))
        success = false;
    if (!input.ReadDisplayName(&result->display_name))
        success = false;
    if (!input.ReadIconUrl(&result->icon_url))
        success = false;
    if (!input.ReadFederationOrigin(&result->federation_origin))
        success = false;
    result->skip_zero_click = input.skip_zero_click();
    if (!input.ReadLayout(&result->layout))
        success = false;
    result->was_parsed_using_autofill_predictions = input.was_parsed_using_autofill_predictions();
    result->is_public_suffix_match = input.is_public_suffix_match();
    result->is_affiliation_based_match = input.is_affiliation_based_match();
    result->does_look_like_signup_form = input.does_look_like_signup_form();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::autofill::mojom::PasswordFormFieldPredictionMap::DataView, ::autofill::mojom::PasswordFormFieldPredictionMapPtr>::Read(
    ::autofill::mojom::PasswordFormFieldPredictionMap::DataView input,
    ::autofill::mojom::PasswordFormFieldPredictionMapPtr* output)
{
    bool success = true;
    ::autofill::mojom::PasswordFormFieldPredictionMapPtr result(::autofill::mojom::PasswordFormFieldPredictionMap::New());

    if (!input.ReadKeys(&result->keys))
        success = false;
    if (!input.ReadValues(&result->values))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::autofill::mojom::FormsPredictionsMap::DataView, ::autofill::mojom::FormsPredictionsMapPtr>::Read(
    ::autofill::mojom::FormsPredictionsMap::DataView input,
    ::autofill::mojom::FormsPredictionsMapPtr* output)
{
    bool success = true;
    ::autofill::mojom::FormsPredictionsMapPtr result(::autofill::mojom::FormsPredictionsMap::New());

    if (!input.ReadKeys(&result->keys))
        success = false;
    if (!input.ReadValues(&result->values))
        success = false;
    *output = std::move(result);
    return success;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif