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

#include "components/autofill/content/common/autofill_agent.mojom.h"

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
#include "ui/gfx/geometry/mojo/geometry_struct_traits.h"
#include "url/mojo/origin_struct_traits.h"
#include "url/mojo/url_gurl_struct_traits.h"
namespace autofill {
namespace mojom {
    const char AutofillAgent::Name_[] = "autofill::mojom::AutofillAgent";

    AutofillAgentProxy::AutofillAgentProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void AutofillAgentProxy::FirstUserGestureObservedInTab()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::AutofillAgent_FirstUserGestureObservedInTab_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kAutofillAgent_FirstUserGestureObservedInTab_Name, size);

        auto params = ::autofill::mojom::internal::AutofillAgent_FirstUserGestureObservedInTab_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void AutofillAgentProxy::FillForm(
        int32_t in_id, const autofill::FormData& in_form)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::AutofillAgent_FillForm_Params_Data);
        size += mojo::internal::PrepareToSerialize<::autofill::mojom::FormDataDataView>(
            in_form, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kAutofillAgent_FillForm_Name, size);

        auto params = ::autofill::mojom::internal::AutofillAgent_FillForm_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->id = in_id;
        typename decltype(params->form)::BaseType* form_ptr;
        mojo::internal::Serialize<::autofill::mojom::FormDataDataView>(
            in_form, builder.buffer(), &form_ptr, &serialization_context);
        params->form.Set(form_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->form.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null form in AutofillAgent.FillForm request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void AutofillAgentProxy::PreviewForm(
        int32_t in_id, const autofill::FormData& in_form)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::AutofillAgent_PreviewForm_Params_Data);
        size += mojo::internal::PrepareToSerialize<::autofill::mojom::FormDataDataView>(
            in_form, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kAutofillAgent_PreviewForm_Name, size);

        auto params = ::autofill::mojom::internal::AutofillAgent_PreviewForm_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->id = in_id;
        typename decltype(params->form)::BaseType* form_ptr;
        mojo::internal::Serialize<::autofill::mojom::FormDataDataView>(
            in_form, builder.buffer(), &form_ptr, &serialization_context);
        params->form.Set(form_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->form.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null form in AutofillAgent.PreviewForm request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void AutofillAgentProxy::FieldTypePredictionsAvailable(
        const std::vector<autofill::FormDataPredictions>& in_forms)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::AutofillAgent_FieldTypePredictionsAvailable_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::autofill::mojom::FormDataPredictionsDataView>>(
            in_forms, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kAutofillAgent_FieldTypePredictionsAvailable_Name, size);

        auto params = ::autofill::mojom::internal::AutofillAgent_FieldTypePredictionsAvailable_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->forms)::BaseType* forms_ptr;
        const mojo::internal::ContainerValidateParams forms_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::autofill::mojom::FormDataPredictionsDataView>>(
            in_forms, builder.buffer(), &forms_ptr, &forms_validate_params,
            &serialization_context);
        params->forms.Set(forms_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->forms.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null forms in AutofillAgent.FieldTypePredictionsAvailable request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void AutofillAgentProxy::ClearForm()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::AutofillAgent_ClearForm_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kAutofillAgent_ClearForm_Name, size);

        auto params = ::autofill::mojom::internal::AutofillAgent_ClearForm_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void AutofillAgentProxy::ClearPreviewedForm()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::AutofillAgent_ClearPreviewedForm_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kAutofillAgent_ClearPreviewedForm_Name, size);

        auto params = ::autofill::mojom::internal::AutofillAgent_ClearPreviewedForm_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void AutofillAgentProxy::FillFieldWithValue(
        const base::string16& in_value)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::AutofillAgent_FillFieldWithValue_Params_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::String16DataView>(
            in_value, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kAutofillAgent_FillFieldWithValue_Name, size);

        auto params = ::autofill::mojom::internal::AutofillAgent_FillFieldWithValue_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->value)::BaseType* value_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::String16DataView>(
            in_value, builder.buffer(), &value_ptr, &serialization_context);
        params->value.Set(value_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->value.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null value in AutofillAgent.FillFieldWithValue request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void AutofillAgentProxy::PreviewFieldWithValue(
        const base::string16& in_value)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::AutofillAgent_PreviewFieldWithValue_Params_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::String16DataView>(
            in_value, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kAutofillAgent_PreviewFieldWithValue_Name, size);

        auto params = ::autofill::mojom::internal::AutofillAgent_PreviewFieldWithValue_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->value)::BaseType* value_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::String16DataView>(
            in_value, builder.buffer(), &value_ptr, &serialization_context);
        params->value.Set(value_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->value.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null value in AutofillAgent.PreviewFieldWithValue request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void AutofillAgentProxy::AcceptDataListSuggestion(
        const base::string16& in_value)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::AutofillAgent_AcceptDataListSuggestion_Params_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::String16DataView>(
            in_value, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kAutofillAgent_AcceptDataListSuggestion_Name, size);

        auto params = ::autofill::mojom::internal::AutofillAgent_AcceptDataListSuggestion_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->value)::BaseType* value_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::String16DataView>(
            in_value, builder.buffer(), &value_ptr, &serialization_context);
        params->value.Set(value_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->value.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null value in AutofillAgent.AcceptDataListSuggestion request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void AutofillAgentProxy::FillPasswordSuggestion(
        const base::string16& in_username, const base::string16& in_password)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::AutofillAgent_FillPasswordSuggestion_Params_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::String16DataView>(
            in_username, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::String16DataView>(
            in_password, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kAutofillAgent_FillPasswordSuggestion_Name, size);

        auto params = ::autofill::mojom::internal::AutofillAgent_FillPasswordSuggestion_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->username)::BaseType* username_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::String16DataView>(
            in_username, builder.buffer(), &username_ptr, &serialization_context);
        params->username.Set(username_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->username.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null username in AutofillAgent.FillPasswordSuggestion request");
        typename decltype(params->password)::BaseType* password_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::String16DataView>(
            in_password, builder.buffer(), &password_ptr, &serialization_context);
        params->password.Set(password_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->password.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null password in AutofillAgent.FillPasswordSuggestion request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void AutofillAgentProxy::PreviewPasswordSuggestion(
        const base::string16& in_username, const base::string16& in_password)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::AutofillAgent_PreviewPasswordSuggestion_Params_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::String16DataView>(
            in_username, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::String16DataView>(
            in_password, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kAutofillAgent_PreviewPasswordSuggestion_Name, size);

        auto params = ::autofill::mojom::internal::AutofillAgent_PreviewPasswordSuggestion_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->username)::BaseType* username_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::String16DataView>(
            in_username, builder.buffer(), &username_ptr, &serialization_context);
        params->username.Set(username_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->username.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null username in AutofillAgent.PreviewPasswordSuggestion request");
        typename decltype(params->password)::BaseType* password_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::String16DataView>(
            in_password, builder.buffer(), &password_ptr, &serialization_context);
        params->password.Set(password_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->password.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null password in AutofillAgent.PreviewPasswordSuggestion request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void AutofillAgentProxy::ShowInitialPasswordAccountSuggestions(
        int32_t in_key, const autofill::PasswordFormFillData& in_form_data)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::AutofillAgent_ShowInitialPasswordAccountSuggestions_Params_Data);
        size += mojo::internal::PrepareToSerialize<::autofill::mojom::PasswordFormFillDataDataView>(
            in_form_data, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kAutofillAgent_ShowInitialPasswordAccountSuggestions_Name, size);

        auto params = ::autofill::mojom::internal::AutofillAgent_ShowInitialPasswordAccountSuggestions_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->key = in_key;
        typename decltype(params->form_data)::BaseType* form_data_ptr;
        mojo::internal::Serialize<::autofill::mojom::PasswordFormFillDataDataView>(
            in_form_data, builder.buffer(), &form_data_ptr, &serialization_context);
        params->form_data.Set(form_data_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->form_data.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null form_data in AutofillAgent.ShowInitialPasswordAccountSuggestions request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool AutofillAgentStubDispatch::Accept(
        AutofillAgent* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kAutofillAgent_FirstUserGestureObservedInTab_Name: {
            internal::AutofillAgent_FirstUserGestureObservedInTab_Params_Data* params = reinterpret_cast<internal::AutofillAgent_FirstUserGestureObservedInTab_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            AutofillAgent_FirstUserGestureObservedInTab_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "AutofillAgent::FirstUserGestureObservedInTab deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "AutofillAgent::FirstUserGestureObservedInTab");
            mojo::internal::MessageDispatchContext context(message);
            impl->FirstUserGestureObservedInTab();
            return true;
        }
        case internal::kAutofillAgent_FillForm_Name: {
            internal::AutofillAgent_FillForm_Params_Data* params = reinterpret_cast<internal::AutofillAgent_FillForm_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_id {};
            autofill::FormData p_form {};
            AutofillAgent_FillForm_ParamsDataView input_data_view(params,
                context);

            p_id = input_data_view.id();
            if (!input_data_view.ReadForm(&p_form))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "AutofillAgent::FillForm deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "AutofillAgent::FillForm");
            mojo::internal::MessageDispatchContext context(message);
            impl->FillForm(
                std::move(p_id),
                std::move(p_form));
            return true;
        }
        case internal::kAutofillAgent_PreviewForm_Name: {
            internal::AutofillAgent_PreviewForm_Params_Data* params = reinterpret_cast<internal::AutofillAgent_PreviewForm_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_id {};
            autofill::FormData p_form {};
            AutofillAgent_PreviewForm_ParamsDataView input_data_view(params,
                context);

            p_id = input_data_view.id();
            if (!input_data_view.ReadForm(&p_form))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "AutofillAgent::PreviewForm deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "AutofillAgent::PreviewForm");
            mojo::internal::MessageDispatchContext context(message);
            impl->PreviewForm(
                std::move(p_id),
                std::move(p_form));
            return true;
        }
        case internal::kAutofillAgent_FieldTypePredictionsAvailable_Name: {
            internal::AutofillAgent_FieldTypePredictionsAvailable_Params_Data* params = reinterpret_cast<internal::AutofillAgent_FieldTypePredictionsAvailable_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::vector<autofill::FormDataPredictions> p_forms {};
            AutofillAgent_FieldTypePredictionsAvailable_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadForms(&p_forms))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "AutofillAgent::FieldTypePredictionsAvailable deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "AutofillAgent::FieldTypePredictionsAvailable");
            mojo::internal::MessageDispatchContext context(message);
            impl->FieldTypePredictionsAvailable(
                std::move(p_forms));
            return true;
        }
        case internal::kAutofillAgent_ClearForm_Name: {
            internal::AutofillAgent_ClearForm_Params_Data* params = reinterpret_cast<internal::AutofillAgent_ClearForm_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            AutofillAgent_ClearForm_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "AutofillAgent::ClearForm deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "AutofillAgent::ClearForm");
            mojo::internal::MessageDispatchContext context(message);
            impl->ClearForm();
            return true;
        }
        case internal::kAutofillAgent_ClearPreviewedForm_Name: {
            internal::AutofillAgent_ClearPreviewedForm_Params_Data* params = reinterpret_cast<internal::AutofillAgent_ClearPreviewedForm_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            AutofillAgent_ClearPreviewedForm_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "AutofillAgent::ClearPreviewedForm deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "AutofillAgent::ClearPreviewedForm");
            mojo::internal::MessageDispatchContext context(message);
            impl->ClearPreviewedForm();
            return true;
        }
        case internal::kAutofillAgent_FillFieldWithValue_Name: {
            internal::AutofillAgent_FillFieldWithValue_Params_Data* params = reinterpret_cast<internal::AutofillAgent_FillFieldWithValue_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            base::string16 p_value {};
            AutofillAgent_FillFieldWithValue_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadValue(&p_value))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "AutofillAgent::FillFieldWithValue deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "AutofillAgent::FillFieldWithValue");
            mojo::internal::MessageDispatchContext context(message);
            impl->FillFieldWithValue(
                std::move(p_value));
            return true;
        }
        case internal::kAutofillAgent_PreviewFieldWithValue_Name: {
            internal::AutofillAgent_PreviewFieldWithValue_Params_Data* params = reinterpret_cast<internal::AutofillAgent_PreviewFieldWithValue_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            base::string16 p_value {};
            AutofillAgent_PreviewFieldWithValue_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadValue(&p_value))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "AutofillAgent::PreviewFieldWithValue deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "AutofillAgent::PreviewFieldWithValue");
            mojo::internal::MessageDispatchContext context(message);
            impl->PreviewFieldWithValue(
                std::move(p_value));
            return true;
        }
        case internal::kAutofillAgent_AcceptDataListSuggestion_Name: {
            internal::AutofillAgent_AcceptDataListSuggestion_Params_Data* params = reinterpret_cast<internal::AutofillAgent_AcceptDataListSuggestion_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            base::string16 p_value {};
            AutofillAgent_AcceptDataListSuggestion_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadValue(&p_value))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "AutofillAgent::AcceptDataListSuggestion deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "AutofillAgent::AcceptDataListSuggestion");
            mojo::internal::MessageDispatchContext context(message);
            impl->AcceptDataListSuggestion(
                std::move(p_value));
            return true;
        }
        case internal::kAutofillAgent_FillPasswordSuggestion_Name: {
            internal::AutofillAgent_FillPasswordSuggestion_Params_Data* params = reinterpret_cast<internal::AutofillAgent_FillPasswordSuggestion_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            base::string16 p_username {};
            base::string16 p_password {};
            AutofillAgent_FillPasswordSuggestion_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadUsername(&p_username))
                success = false;
            if (!input_data_view.ReadPassword(&p_password))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "AutofillAgent::FillPasswordSuggestion deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "AutofillAgent::FillPasswordSuggestion");
            mojo::internal::MessageDispatchContext context(message);
            impl->FillPasswordSuggestion(
                std::move(p_username),
                std::move(p_password));
            return true;
        }
        case internal::kAutofillAgent_PreviewPasswordSuggestion_Name: {
            internal::AutofillAgent_PreviewPasswordSuggestion_Params_Data* params = reinterpret_cast<internal::AutofillAgent_PreviewPasswordSuggestion_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            base::string16 p_username {};
            base::string16 p_password {};
            AutofillAgent_PreviewPasswordSuggestion_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadUsername(&p_username))
                success = false;
            if (!input_data_view.ReadPassword(&p_password))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "AutofillAgent::PreviewPasswordSuggestion deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "AutofillAgent::PreviewPasswordSuggestion");
            mojo::internal::MessageDispatchContext context(message);
            impl->PreviewPasswordSuggestion(
                std::move(p_username),
                std::move(p_password));
            return true;
        }
        case internal::kAutofillAgent_ShowInitialPasswordAccountSuggestions_Name: {
            internal::AutofillAgent_ShowInitialPasswordAccountSuggestions_Params_Data* params = reinterpret_cast<internal::AutofillAgent_ShowInitialPasswordAccountSuggestions_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_key {};
            autofill::PasswordFormFillData p_form_data {};
            AutofillAgent_ShowInitialPasswordAccountSuggestions_ParamsDataView input_data_view(params,
                context);

            p_key = input_data_view.key();
            if (!input_data_view.ReadFormData(&p_form_data))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "AutofillAgent::ShowInitialPasswordAccountSuggestions deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "AutofillAgent::ShowInitialPasswordAccountSuggestions");
            mojo::internal::MessageDispatchContext context(message);
            impl->ShowInitialPasswordAccountSuggestions(
                std::move(p_key),
                std::move(p_form_data));
            return true;
        }
        }
        return false;
    }

    // static
    bool AutofillAgentStubDispatch::AcceptWithResponder(
        AutofillAgent* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kAutofillAgent_FirstUserGestureObservedInTab_Name: {
            break;
        }
        case internal::kAutofillAgent_FillForm_Name: {
            break;
        }
        case internal::kAutofillAgent_PreviewForm_Name: {
            break;
        }
        case internal::kAutofillAgent_FieldTypePredictionsAvailable_Name: {
            break;
        }
        case internal::kAutofillAgent_ClearForm_Name: {
            break;
        }
        case internal::kAutofillAgent_ClearPreviewedForm_Name: {
            break;
        }
        case internal::kAutofillAgent_FillFieldWithValue_Name: {
            break;
        }
        case internal::kAutofillAgent_PreviewFieldWithValue_Name: {
            break;
        }
        case internal::kAutofillAgent_AcceptDataListSuggestion_Name: {
            break;
        }
        case internal::kAutofillAgent_FillPasswordSuggestion_Name: {
            break;
        }
        case internal::kAutofillAgent_PreviewPasswordSuggestion_Name: {
            break;
        }
        case internal::kAutofillAgent_ShowInitialPasswordAccountSuggestions_Name: {
            break;
        }
        }
        return false;
    }

    bool AutofillAgentRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "AutofillAgent RequestValidator");

        switch (message->header()->name) {
        case internal::kAutofillAgent_FirstUserGestureObservedInTab_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AutofillAgent_FirstUserGestureObservedInTab_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kAutofillAgent_FillForm_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AutofillAgent_FillForm_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kAutofillAgent_PreviewForm_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AutofillAgent_PreviewForm_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kAutofillAgent_FieldTypePredictionsAvailable_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AutofillAgent_FieldTypePredictionsAvailable_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kAutofillAgent_ClearForm_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AutofillAgent_ClearForm_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kAutofillAgent_ClearPreviewedForm_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AutofillAgent_ClearPreviewedForm_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kAutofillAgent_FillFieldWithValue_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AutofillAgent_FillFieldWithValue_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kAutofillAgent_PreviewFieldWithValue_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AutofillAgent_PreviewFieldWithValue_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kAutofillAgent_AcceptDataListSuggestion_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AutofillAgent_AcceptDataListSuggestion_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kAutofillAgent_FillPasswordSuggestion_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AutofillAgent_FillPasswordSuggestion_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kAutofillAgent_PreviewPasswordSuggestion_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AutofillAgent_PreviewPasswordSuggestion_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kAutofillAgent_ShowInitialPasswordAccountSuggestions_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AutofillAgent_ShowInitialPasswordAccountSuggestions_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        default:
            break;
        }

        // Unrecognized message.
        ReportValidationError(
            &validation_context,
            mojo::internal::VALIDATION_ERROR_MESSAGE_HEADER_UNKNOWN_METHOD);
        return false;
    }

    const char PasswordAutofillAgent::Name_[] = "autofill::mojom::PasswordAutofillAgent";

    class PasswordAutofillAgent_FindFocusedPasswordForm_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        PasswordAutofillAgent_FindFocusedPasswordForm_ForwardToCallback(
            const PasswordAutofillAgent::FindFocusedPasswordFormCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        PasswordAutofillAgent::FindFocusedPasswordFormCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(PasswordAutofillAgent_FindFocusedPasswordForm_ForwardToCallback);
    };
    bool PasswordAutofillAgent_FindFocusedPasswordForm_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::PasswordAutofillAgent_FindFocusedPasswordForm_ResponseParams_Data* params = reinterpret_cast<internal::PasswordAutofillAgent_FindFocusedPasswordForm_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        autofill::PasswordForm p_form {};
        PasswordAutofillAgent_FindFocusedPasswordForm_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadForm(&p_form))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "PasswordAutofillAgent::FindFocusedPasswordForm response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_form));
        }
        return true;
    }

    PasswordAutofillAgentProxy::PasswordAutofillAgentProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void PasswordAutofillAgentProxy::FillPasswordForm(
        int32_t in_key, const autofill::PasswordFormFillData& in_form_data)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::PasswordAutofillAgent_FillPasswordForm_Params_Data);
        size += mojo::internal::PrepareToSerialize<::autofill::mojom::PasswordFormFillDataDataView>(
            in_form_data, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kPasswordAutofillAgent_FillPasswordForm_Name, size);

        auto params = ::autofill::mojom::internal::PasswordAutofillAgent_FillPasswordForm_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->key = in_key;
        typename decltype(params->form_data)::BaseType* form_data_ptr;
        mojo::internal::Serialize<::autofill::mojom::PasswordFormFillDataDataView>(
            in_form_data, builder.buffer(), &form_data_ptr, &serialization_context);
        params->form_data.Set(form_data_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->form_data.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null form_data in PasswordAutofillAgent.FillPasswordForm request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PasswordAutofillAgentProxy::SetLoggingState(
        bool in_active)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::PasswordAutofillAgent_SetLoggingState_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kPasswordAutofillAgent_SetLoggingState_Name, size);

        auto params = ::autofill::mojom::internal::PasswordAutofillAgent_SetLoggingState_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->active = in_active;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PasswordAutofillAgentProxy::AutofillUsernameAndPasswordDataReceived(
        const autofill::FormsPredictionsMap& in_predictions)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::PasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_Params_Data);
        size += mojo::internal::PrepareToSerialize<::autofill::mojom::FormsPredictionsMapDataView>(
            in_predictions, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kPasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_Name, size);

        auto params = ::autofill::mojom::internal::PasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->predictions)::BaseType* predictions_ptr;
        mojo::internal::Serialize<::autofill::mojom::FormsPredictionsMapDataView>(
            in_predictions, builder.buffer(), &predictions_ptr, &serialization_context);
        params->predictions.Set(predictions_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->predictions.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null predictions in PasswordAutofillAgent.AutofillUsernameAndPasswordDataReceived request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PasswordAutofillAgentProxy::FindFocusedPasswordForm(
        const FindFocusedPasswordFormCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::PasswordAutofillAgent_FindFocusedPasswordForm_Params_Data);
        mojo::internal::RequestMessageBuilder builder(internal::kPasswordAutofillAgent_FindFocusedPasswordForm_Name, size);

        auto params = ::autofill::mojom::internal::PasswordAutofillAgent_FindFocusedPasswordForm_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new PasswordAutofillAgent_FindFocusedPasswordForm_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    class PasswordAutofillAgent_FindFocusedPasswordForm_ProxyToResponder {
    public:
        static PasswordAutofillAgent::FindFocusedPasswordFormCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<PasswordAutofillAgent_FindFocusedPasswordForm_ProxyToResponder> proxy(
                new PasswordAutofillAgent_FindFocusedPasswordForm_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&PasswordAutofillAgent_FindFocusedPasswordForm_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~PasswordAutofillAgent_FindFocusedPasswordForm_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "PasswordAutofillAgent::FindFocusedPasswordForm() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        PasswordAutofillAgent_FindFocusedPasswordForm_ProxyToResponder(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : request_id_(request_id)
            , is_sync_(is_sync)
            , responder_(responder)
            , serialization_context_(std::move(group_controller))
        {
        }

        void Run(
            const autofill::PasswordForm& in_form);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(PasswordAutofillAgent_FindFocusedPasswordForm_ProxyToResponder);
    };

    void PasswordAutofillAgent_FindFocusedPasswordForm_ProxyToResponder::Run(
        const autofill::PasswordForm& in_form)
    {
        size_t size = sizeof(::autofill::mojom::internal::PasswordAutofillAgent_FindFocusedPasswordForm_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<::autofill::mojom::PasswordFormDataView>(
            in_form, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kPasswordAutofillAgent_FindFocusedPasswordForm_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::autofill::mojom::internal::PasswordAutofillAgent_FindFocusedPasswordForm_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->form)::BaseType* form_ptr;
        mojo::internal::Serialize<::autofill::mojom::PasswordFormDataView>(
            in_form, builder.buffer(), &form_ptr, &serialization_context_);
        params->form.Set(form_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->form.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null form in PasswordAutofillAgent.FindFocusedPasswordForm response");
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }

    // static
    bool PasswordAutofillAgentStubDispatch::Accept(
        PasswordAutofillAgent* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kPasswordAutofillAgent_FillPasswordForm_Name: {
            internal::PasswordAutofillAgent_FillPasswordForm_Params_Data* params = reinterpret_cast<internal::PasswordAutofillAgent_FillPasswordForm_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_key {};
            autofill::PasswordFormFillData p_form_data {};
            PasswordAutofillAgent_FillPasswordForm_ParamsDataView input_data_view(params,
                context);

            p_key = input_data_view.key();
            if (!input_data_view.ReadFormData(&p_form_data))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PasswordAutofillAgent::FillPasswordForm deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PasswordAutofillAgent::FillPasswordForm");
            mojo::internal::MessageDispatchContext context(message);
            impl->FillPasswordForm(
                std::move(p_key),
                std::move(p_form_data));
            return true;
        }
        case internal::kPasswordAutofillAgent_SetLoggingState_Name: {
            internal::PasswordAutofillAgent_SetLoggingState_Params_Data* params = reinterpret_cast<internal::PasswordAutofillAgent_SetLoggingState_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            bool p_active {};
            PasswordAutofillAgent_SetLoggingState_ParamsDataView input_data_view(params,
                context);

            p_active = input_data_view.active();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PasswordAutofillAgent::SetLoggingState deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PasswordAutofillAgent::SetLoggingState");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetLoggingState(
                std::move(p_active));
            return true;
        }
        case internal::kPasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_Name: {
            internal::PasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_Params_Data* params = reinterpret_cast<internal::PasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            autofill::FormsPredictionsMap p_predictions {};
            PasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadPredictions(&p_predictions))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PasswordAutofillAgent::AutofillUsernameAndPasswordDataReceived deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PasswordAutofillAgent::AutofillUsernameAndPasswordDataReceived");
            mojo::internal::MessageDispatchContext context(message);
            impl->AutofillUsernameAndPasswordDataReceived(
                std::move(p_predictions));
            return true;
        }
        case internal::kPasswordAutofillAgent_FindFocusedPasswordForm_Name: {
            break;
        }
        }
        return false;
    }

    // static
    bool PasswordAutofillAgentStubDispatch::AcceptWithResponder(
        PasswordAutofillAgent* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kPasswordAutofillAgent_FillPasswordForm_Name: {
            break;
        }
        case internal::kPasswordAutofillAgent_SetLoggingState_Name: {
            break;
        }
        case internal::kPasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_Name: {
            break;
        }
        case internal::kPasswordAutofillAgent_FindFocusedPasswordForm_Name: {
            internal::PasswordAutofillAgent_FindFocusedPasswordForm_Params_Data* params = reinterpret_cast<internal::PasswordAutofillAgent_FindFocusedPasswordForm_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            PasswordAutofillAgent_FindFocusedPasswordForm_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PasswordAutofillAgent::FindFocusedPasswordForm deserializer");
                return false;
            }
            PasswordAutofillAgent::FindFocusedPasswordFormCallback callback = PasswordAutofillAgent_FindFocusedPasswordForm_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PasswordAutofillAgent::FindFocusedPasswordForm");
            mojo::internal::MessageDispatchContext context(message);
            impl->FindFocusedPasswordForm(std::move(callback));
            return true;
        }
        }
        return false;
    }

    bool PasswordAutofillAgentRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "PasswordAutofillAgent RequestValidator");

        switch (message->header()->name) {
        case internal::kPasswordAutofillAgent_FillPasswordForm_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PasswordAutofillAgent_FillPasswordForm_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPasswordAutofillAgent_SetLoggingState_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PasswordAutofillAgent_SetLoggingState_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PasswordAutofillAgent_AutofillUsernameAndPasswordDataReceived_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPasswordAutofillAgent_FindFocusedPasswordForm_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PasswordAutofillAgent_FindFocusedPasswordForm_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        default:
            break;
        }

        // Unrecognized message.
        ReportValidationError(
            &validation_context,
            mojo::internal::VALIDATION_ERROR_MESSAGE_HEADER_UNKNOWN_METHOD);
        return false;
    }

    bool PasswordAutofillAgentResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "PasswordAutofillAgent ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kPasswordAutofillAgent_FindFocusedPasswordForm_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PasswordAutofillAgent_FindFocusedPasswordForm_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        default:
            break;
        }

        // Unrecognized message.
        ReportValidationError(
            &validation_context,
            mojo::internal::VALIDATION_ERROR_MESSAGE_HEADER_UNKNOWN_METHOD);
        return false;
    }
    const char PasswordGenerationAgent::Name_[] = "autofill::mojom::PasswordGenerationAgent";

    PasswordGenerationAgentProxy::PasswordGenerationAgentProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void PasswordGenerationAgentProxy::GeneratedPasswordAccepted(
        const base::string16& in_generated_password)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::PasswordGenerationAgent_GeneratedPasswordAccepted_Params_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::String16DataView>(
            in_generated_password, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kPasswordGenerationAgent_GeneratedPasswordAccepted_Name, size);

        auto params = ::autofill::mojom::internal::PasswordGenerationAgent_GeneratedPasswordAccepted_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->generated_password)::BaseType* generated_password_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::String16DataView>(
            in_generated_password, builder.buffer(), &generated_password_ptr, &serialization_context);
        params->generated_password.Set(generated_password_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->generated_password.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null generated_password in PasswordGenerationAgent.GeneratedPasswordAccepted request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PasswordGenerationAgentProxy::UserTriggeredGeneratePassword()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::PasswordGenerationAgent_UserTriggeredGeneratePassword_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kPasswordGenerationAgent_UserTriggeredGeneratePassword_Name, size);

        auto params = ::autofill::mojom::internal::PasswordGenerationAgent_UserTriggeredGeneratePassword_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PasswordGenerationAgentProxy::FormNotBlacklisted(
        const autofill::PasswordForm& in_form)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::PasswordGenerationAgent_FormNotBlacklisted_Params_Data);
        size += mojo::internal::PrepareToSerialize<::autofill::mojom::PasswordFormDataView>(
            in_form, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kPasswordGenerationAgent_FormNotBlacklisted_Name, size);

        auto params = ::autofill::mojom::internal::PasswordGenerationAgent_FormNotBlacklisted_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->form)::BaseType* form_ptr;
        mojo::internal::Serialize<::autofill::mojom::PasswordFormDataView>(
            in_form, builder.buffer(), &form_ptr, &serialization_context);
        params->form.Set(form_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->form.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null form in PasswordGenerationAgent.FormNotBlacklisted request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PasswordGenerationAgentProxy::FoundFormsEligibleForGeneration(
        const std::vector<autofill::PasswordFormGenerationData>& in_forms)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::PasswordGenerationAgent_FoundFormsEligibleForGeneration_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::autofill::mojom::PasswordFormGenerationDataDataView>>(
            in_forms, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kPasswordGenerationAgent_FoundFormsEligibleForGeneration_Name, size);

        auto params = ::autofill::mojom::internal::PasswordGenerationAgent_FoundFormsEligibleForGeneration_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->forms)::BaseType* forms_ptr;
        const mojo::internal::ContainerValidateParams forms_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::autofill::mojom::PasswordFormGenerationDataDataView>>(
            in_forms, builder.buffer(), &forms_ptr, &forms_validate_params,
            &serialization_context);
        params->forms.Set(forms_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->forms.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null forms in PasswordGenerationAgent.FoundFormsEligibleForGeneration request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PasswordGenerationAgentProxy::AllowToRunFormClassifier()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::PasswordGenerationAgent_AllowToRunFormClassifier_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kPasswordGenerationAgent_AllowToRunFormClassifier_Name, size);

        auto params = ::autofill::mojom::internal::PasswordGenerationAgent_AllowToRunFormClassifier_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool PasswordGenerationAgentStubDispatch::Accept(
        PasswordGenerationAgent* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kPasswordGenerationAgent_GeneratedPasswordAccepted_Name: {
            internal::PasswordGenerationAgent_GeneratedPasswordAccepted_Params_Data* params = reinterpret_cast<internal::PasswordGenerationAgent_GeneratedPasswordAccepted_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            base::string16 p_generated_password {};
            PasswordGenerationAgent_GeneratedPasswordAccepted_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadGeneratedPassword(&p_generated_password))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PasswordGenerationAgent::GeneratedPasswordAccepted deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PasswordGenerationAgent::GeneratedPasswordAccepted");
            mojo::internal::MessageDispatchContext context(message);
            impl->GeneratedPasswordAccepted(
                std::move(p_generated_password));
            return true;
        }
        case internal::kPasswordGenerationAgent_UserTriggeredGeneratePassword_Name: {
            internal::PasswordGenerationAgent_UserTriggeredGeneratePassword_Params_Data* params = reinterpret_cast<internal::PasswordGenerationAgent_UserTriggeredGeneratePassword_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            PasswordGenerationAgent_UserTriggeredGeneratePassword_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PasswordGenerationAgent::UserTriggeredGeneratePassword deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PasswordGenerationAgent::UserTriggeredGeneratePassword");
            mojo::internal::MessageDispatchContext context(message);
            impl->UserTriggeredGeneratePassword();
            return true;
        }
        case internal::kPasswordGenerationAgent_FormNotBlacklisted_Name: {
            internal::PasswordGenerationAgent_FormNotBlacklisted_Params_Data* params = reinterpret_cast<internal::PasswordGenerationAgent_FormNotBlacklisted_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            autofill::PasswordForm p_form {};
            PasswordGenerationAgent_FormNotBlacklisted_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadForm(&p_form))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PasswordGenerationAgent::FormNotBlacklisted deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PasswordGenerationAgent::FormNotBlacklisted");
            mojo::internal::MessageDispatchContext context(message);
            impl->FormNotBlacklisted(
                std::move(p_form));
            return true;
        }
        case internal::kPasswordGenerationAgent_FoundFormsEligibleForGeneration_Name: {
            internal::PasswordGenerationAgent_FoundFormsEligibleForGeneration_Params_Data* params = reinterpret_cast<internal::PasswordGenerationAgent_FoundFormsEligibleForGeneration_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::vector<autofill::PasswordFormGenerationData> p_forms {};
            PasswordGenerationAgent_FoundFormsEligibleForGeneration_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadForms(&p_forms))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PasswordGenerationAgent::FoundFormsEligibleForGeneration deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PasswordGenerationAgent::FoundFormsEligibleForGeneration");
            mojo::internal::MessageDispatchContext context(message);
            impl->FoundFormsEligibleForGeneration(
                std::move(p_forms));
            return true;
        }
        case internal::kPasswordGenerationAgent_AllowToRunFormClassifier_Name: {
            internal::PasswordGenerationAgent_AllowToRunFormClassifier_Params_Data* params = reinterpret_cast<internal::PasswordGenerationAgent_AllowToRunFormClassifier_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            PasswordGenerationAgent_AllowToRunFormClassifier_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PasswordGenerationAgent::AllowToRunFormClassifier deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PasswordGenerationAgent::AllowToRunFormClassifier");
            mojo::internal::MessageDispatchContext context(message);
            impl->AllowToRunFormClassifier();
            return true;
        }
        }
        return false;
    }

    // static
    bool PasswordGenerationAgentStubDispatch::AcceptWithResponder(
        PasswordGenerationAgent* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kPasswordGenerationAgent_GeneratedPasswordAccepted_Name: {
            break;
        }
        case internal::kPasswordGenerationAgent_UserTriggeredGeneratePassword_Name: {
            break;
        }
        case internal::kPasswordGenerationAgent_FormNotBlacklisted_Name: {
            break;
        }
        case internal::kPasswordGenerationAgent_FoundFormsEligibleForGeneration_Name: {
            break;
        }
        case internal::kPasswordGenerationAgent_AllowToRunFormClassifier_Name: {
            break;
        }
        }
        return false;
    }

    bool PasswordGenerationAgentRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "PasswordGenerationAgent RequestValidator");

        switch (message->header()->name) {
        case internal::kPasswordGenerationAgent_GeneratedPasswordAccepted_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PasswordGenerationAgent_GeneratedPasswordAccepted_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPasswordGenerationAgent_UserTriggeredGeneratePassword_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PasswordGenerationAgent_UserTriggeredGeneratePassword_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPasswordGenerationAgent_FormNotBlacklisted_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PasswordGenerationAgent_FormNotBlacklisted_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPasswordGenerationAgent_FoundFormsEligibleForGeneration_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PasswordGenerationAgent_FoundFormsEligibleForGeneration_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPasswordGenerationAgent_AllowToRunFormClassifier_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PasswordGenerationAgent_AllowToRunFormClassifier_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        default:
            break;
        }

        // Unrecognized message.
        ReportValidationError(
            &validation_context,
            mojo::internal::VALIDATION_ERROR_MESSAGE_HEADER_UNKNOWN_METHOD);
        return false;
    }

} // namespace mojom
} // namespace autofill

namespace mojo {

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif