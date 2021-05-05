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

#include "components/autofill/content/common/autofill_driver.mojom.h"

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
    const char AutofillDriver::Name_[] = "autofill::mojom::AutofillDriver";

    AutofillDriverProxy::AutofillDriverProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void AutofillDriverProxy::FirstUserGestureObserved()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::AutofillDriver_FirstUserGestureObserved_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kAutofillDriver_FirstUserGestureObserved_Name, size);

        auto params = ::autofill::mojom::internal::AutofillDriver_FirstUserGestureObserved_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void AutofillDriverProxy::FormsSeen(
        const std::vector<autofill::FormData>& in_forms, base::TimeTicks in_timestamp)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::AutofillDriver_FormsSeen_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::autofill::mojom::FormDataDataView>>(
            in_forms, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::TimeTicksDataView>(
            in_timestamp, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kAutofillDriver_FormsSeen_Name, size);

        auto params = ::autofill::mojom::internal::AutofillDriver_FormsSeen_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->forms)::BaseType* forms_ptr;
        const mojo::internal::ContainerValidateParams forms_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::autofill::mojom::FormDataDataView>>(
            in_forms, builder.buffer(), &forms_ptr, &forms_validate_params,
            &serialization_context);
        params->forms.Set(forms_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->forms.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null forms in AutofillDriver.FormsSeen request");
        typename decltype(params->timestamp)::BaseType* timestamp_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::TimeTicksDataView>(
            in_timestamp, builder.buffer(), &timestamp_ptr, &serialization_context);
        params->timestamp.Set(timestamp_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->timestamp.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null timestamp in AutofillDriver.FormsSeen request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void AutofillDriverProxy::WillSubmitForm(
        const autofill::FormData& in_form, base::TimeTicks in_timestamp)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::AutofillDriver_WillSubmitForm_Params_Data);
        size += mojo::internal::PrepareToSerialize<::autofill::mojom::FormDataDataView>(
            in_form, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::TimeTicksDataView>(
            in_timestamp, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kAutofillDriver_WillSubmitForm_Name, size);

        auto params = ::autofill::mojom::internal::AutofillDriver_WillSubmitForm_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->form)::BaseType* form_ptr;
        mojo::internal::Serialize<::autofill::mojom::FormDataDataView>(
            in_form, builder.buffer(), &form_ptr, &serialization_context);
        params->form.Set(form_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->form.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null form in AutofillDriver.WillSubmitForm request");
        typename decltype(params->timestamp)::BaseType* timestamp_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::TimeTicksDataView>(
            in_timestamp, builder.buffer(), &timestamp_ptr, &serialization_context);
        params->timestamp.Set(timestamp_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->timestamp.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null timestamp in AutofillDriver.WillSubmitForm request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void AutofillDriverProxy::FormSubmitted(
        const autofill::FormData& in_form)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::AutofillDriver_FormSubmitted_Params_Data);
        size += mojo::internal::PrepareToSerialize<::autofill::mojom::FormDataDataView>(
            in_form, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kAutofillDriver_FormSubmitted_Name, size);

        auto params = ::autofill::mojom::internal::AutofillDriver_FormSubmitted_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->form)::BaseType* form_ptr;
        mojo::internal::Serialize<::autofill::mojom::FormDataDataView>(
            in_form, builder.buffer(), &form_ptr, &serialization_context);
        params->form.Set(form_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->form.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null form in AutofillDriver.FormSubmitted request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void AutofillDriverProxy::TextFieldDidChange(
        const autofill::FormData& in_form, const autofill::FormFieldData& in_field, base::TimeTicks in_timestamp)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::AutofillDriver_TextFieldDidChange_Params_Data);
        size += mojo::internal::PrepareToSerialize<::autofill::mojom::FormDataDataView>(
            in_form, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::autofill::mojom::FormFieldDataDataView>(
            in_field, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::TimeTicksDataView>(
            in_timestamp, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kAutofillDriver_TextFieldDidChange_Name, size);

        auto params = ::autofill::mojom::internal::AutofillDriver_TextFieldDidChange_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->form)::BaseType* form_ptr;
        mojo::internal::Serialize<::autofill::mojom::FormDataDataView>(
            in_form, builder.buffer(), &form_ptr, &serialization_context);
        params->form.Set(form_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->form.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null form in AutofillDriver.TextFieldDidChange request");
        typename decltype(params->field)::BaseType* field_ptr;
        mojo::internal::Serialize<::autofill::mojom::FormFieldDataDataView>(
            in_field, builder.buffer(), &field_ptr, &serialization_context);
        params->field.Set(field_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->field.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null field in AutofillDriver.TextFieldDidChange request");
        typename decltype(params->timestamp)::BaseType* timestamp_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::TimeTicksDataView>(
            in_timestamp, builder.buffer(), &timestamp_ptr, &serialization_context);
        params->timestamp.Set(timestamp_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->timestamp.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null timestamp in AutofillDriver.TextFieldDidChange request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void AutofillDriverProxy::QueryFormFieldAutofill(
        int32_t in_id, const autofill::FormData& in_form, const autofill::FormFieldData& in_field, const gfx::RectF& in_bounding_box)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::AutofillDriver_QueryFormFieldAutofill_Params_Data);
        size += mojo::internal::PrepareToSerialize<::autofill::mojom::FormDataDataView>(
            in_form, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::autofill::mojom::FormFieldDataDataView>(
            in_field, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::gfx::mojom::RectFDataView>(
            in_bounding_box, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kAutofillDriver_QueryFormFieldAutofill_Name, size);

        auto params = ::autofill::mojom::internal::AutofillDriver_QueryFormFieldAutofill_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->id = in_id;
        typename decltype(params->form)::BaseType* form_ptr;
        mojo::internal::Serialize<::autofill::mojom::FormDataDataView>(
            in_form, builder.buffer(), &form_ptr, &serialization_context);
        params->form.Set(form_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->form.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null form in AutofillDriver.QueryFormFieldAutofill request");
        typename decltype(params->field)::BaseType* field_ptr;
        mojo::internal::Serialize<::autofill::mojom::FormFieldDataDataView>(
            in_field, builder.buffer(), &field_ptr, &serialization_context);
        params->field.Set(field_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->field.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null field in AutofillDriver.QueryFormFieldAutofill request");
        typename decltype(params->bounding_box)::BaseType* bounding_box_ptr;
        mojo::internal::Serialize<::gfx::mojom::RectFDataView>(
            in_bounding_box, builder.buffer(), &bounding_box_ptr, &serialization_context);
        params->bounding_box.Set(bounding_box_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->bounding_box.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null bounding_box in AutofillDriver.QueryFormFieldAutofill request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void AutofillDriverProxy::HidePopup()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::AutofillDriver_HidePopup_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kAutofillDriver_HidePopup_Name, size);

        auto params = ::autofill::mojom::internal::AutofillDriver_HidePopup_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void AutofillDriverProxy::FocusNoLongerOnForm()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::AutofillDriver_FocusNoLongerOnForm_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kAutofillDriver_FocusNoLongerOnForm_Name, size);

        auto params = ::autofill::mojom::internal::AutofillDriver_FocusNoLongerOnForm_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void AutofillDriverProxy::DidFillAutofillFormData(
        const autofill::FormData& in_form, base::TimeTicks in_timestamp)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::AutofillDriver_DidFillAutofillFormData_Params_Data);
        size += mojo::internal::PrepareToSerialize<::autofill::mojom::FormDataDataView>(
            in_form, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::TimeTicksDataView>(
            in_timestamp, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kAutofillDriver_DidFillAutofillFormData_Name, size);

        auto params = ::autofill::mojom::internal::AutofillDriver_DidFillAutofillFormData_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->form)::BaseType* form_ptr;
        mojo::internal::Serialize<::autofill::mojom::FormDataDataView>(
            in_form, builder.buffer(), &form_ptr, &serialization_context);
        params->form.Set(form_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->form.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null form in AutofillDriver.DidFillAutofillFormData request");
        typename decltype(params->timestamp)::BaseType* timestamp_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::TimeTicksDataView>(
            in_timestamp, builder.buffer(), &timestamp_ptr, &serialization_context);
        params->timestamp.Set(timestamp_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->timestamp.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null timestamp in AutofillDriver.DidFillAutofillFormData request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void AutofillDriverProxy::DidPreviewAutofillFormData()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::AutofillDriver_DidPreviewAutofillFormData_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kAutofillDriver_DidPreviewAutofillFormData_Name, size);

        auto params = ::autofill::mojom::internal::AutofillDriver_DidPreviewAutofillFormData_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void AutofillDriverProxy::DidEndTextFieldEditing()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::AutofillDriver_DidEndTextFieldEditing_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kAutofillDriver_DidEndTextFieldEditing_Name, size);

        auto params = ::autofill::mojom::internal::AutofillDriver_DidEndTextFieldEditing_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void AutofillDriverProxy::SetDataList(
        const std::vector<base::string16>& in_values, const std::vector<base::string16>& in_labels)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::AutofillDriver_SetDataList_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::mojo::common::mojom::String16DataView>>(
            in_values, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::mojo::common::mojom::String16DataView>>(
            in_labels, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kAutofillDriver_SetDataList_Name, size);

        auto params = ::autofill::mojom::internal::AutofillDriver_SetDataList_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->values)::BaseType* values_ptr;
        const mojo::internal::ContainerValidateParams values_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::mojo::common::mojom::String16DataView>>(
            in_values, builder.buffer(), &values_ptr, &values_validate_params,
            &serialization_context);
        params->values.Set(values_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->values.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null values in AutofillDriver.SetDataList request");
        typename decltype(params->labels)::BaseType* labels_ptr;
        const mojo::internal::ContainerValidateParams labels_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::mojo::common::mojom::String16DataView>>(
            in_labels, builder.buffer(), &labels_ptr, &labels_validate_params,
            &serialization_context);
        params->labels.Set(labels_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->labels.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null labels in AutofillDriver.SetDataList request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool AutofillDriverStubDispatch::Accept(
        AutofillDriver* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kAutofillDriver_FirstUserGestureObserved_Name: {
            internal::AutofillDriver_FirstUserGestureObserved_Params_Data* params = reinterpret_cast<internal::AutofillDriver_FirstUserGestureObserved_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            AutofillDriver_FirstUserGestureObserved_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "AutofillDriver::FirstUserGestureObserved deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "AutofillDriver::FirstUserGestureObserved");
            mojo::internal::MessageDispatchContext context(message);
            impl->FirstUserGestureObserved();
            return true;
        }
        case internal::kAutofillDriver_FormsSeen_Name: {
            internal::AutofillDriver_FormsSeen_Params_Data* params = reinterpret_cast<internal::AutofillDriver_FormsSeen_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::vector<autofill::FormData> p_forms {};
            base::TimeTicks p_timestamp {};
            AutofillDriver_FormsSeen_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadForms(&p_forms))
                success = false;
            if (!input_data_view.ReadTimestamp(&p_timestamp))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "AutofillDriver::FormsSeen deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "AutofillDriver::FormsSeen");
            mojo::internal::MessageDispatchContext context(message);
            impl->FormsSeen(
                std::move(p_forms),
                std::move(p_timestamp));
            return true;
        }
        case internal::kAutofillDriver_WillSubmitForm_Name: {
            internal::AutofillDriver_WillSubmitForm_Params_Data* params = reinterpret_cast<internal::AutofillDriver_WillSubmitForm_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            autofill::FormData p_form {};
            base::TimeTicks p_timestamp {};
            AutofillDriver_WillSubmitForm_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadForm(&p_form))
                success = false;
            if (!input_data_view.ReadTimestamp(&p_timestamp))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "AutofillDriver::WillSubmitForm deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "AutofillDriver::WillSubmitForm");
            mojo::internal::MessageDispatchContext context(message);
            impl->WillSubmitForm(
                std::move(p_form),
                std::move(p_timestamp));
            return true;
        }
        case internal::kAutofillDriver_FormSubmitted_Name: {
            internal::AutofillDriver_FormSubmitted_Params_Data* params = reinterpret_cast<internal::AutofillDriver_FormSubmitted_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            autofill::FormData p_form {};
            AutofillDriver_FormSubmitted_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadForm(&p_form))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "AutofillDriver::FormSubmitted deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "AutofillDriver::FormSubmitted");
            mojo::internal::MessageDispatchContext context(message);
            impl->FormSubmitted(
                std::move(p_form));
            return true;
        }
        case internal::kAutofillDriver_TextFieldDidChange_Name: {
            internal::AutofillDriver_TextFieldDidChange_Params_Data* params = reinterpret_cast<internal::AutofillDriver_TextFieldDidChange_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            autofill::FormData p_form {};
            autofill::FormFieldData p_field {};
            base::TimeTicks p_timestamp {};
            AutofillDriver_TextFieldDidChange_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadForm(&p_form))
                success = false;
            if (!input_data_view.ReadField(&p_field))
                success = false;
            if (!input_data_view.ReadTimestamp(&p_timestamp))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "AutofillDriver::TextFieldDidChange deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "AutofillDriver::TextFieldDidChange");
            mojo::internal::MessageDispatchContext context(message);
            impl->TextFieldDidChange(
                std::move(p_form),
                std::move(p_field),
                std::move(p_timestamp));
            return true;
        }
        case internal::kAutofillDriver_QueryFormFieldAutofill_Name: {
            internal::AutofillDriver_QueryFormFieldAutofill_Params_Data* params = reinterpret_cast<internal::AutofillDriver_QueryFormFieldAutofill_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_id {};
            autofill::FormData p_form {};
            autofill::FormFieldData p_field {};
            gfx::RectF p_bounding_box {};
            AutofillDriver_QueryFormFieldAutofill_ParamsDataView input_data_view(params,
                context);

            p_id = input_data_view.id();
            if (!input_data_view.ReadForm(&p_form))
                success = false;
            if (!input_data_view.ReadField(&p_field))
                success = false;
            if (!input_data_view.ReadBoundingBox(&p_bounding_box))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "AutofillDriver::QueryFormFieldAutofill deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "AutofillDriver::QueryFormFieldAutofill");
            mojo::internal::MessageDispatchContext context(message);
            impl->QueryFormFieldAutofill(
                std::move(p_id),
                std::move(p_form),
                std::move(p_field),
                std::move(p_bounding_box));
            return true;
        }
        case internal::kAutofillDriver_HidePopup_Name: {
            internal::AutofillDriver_HidePopup_Params_Data* params = reinterpret_cast<internal::AutofillDriver_HidePopup_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            AutofillDriver_HidePopup_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "AutofillDriver::HidePopup deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "AutofillDriver::HidePopup");
            mojo::internal::MessageDispatchContext context(message);
            impl->HidePopup();
            return true;
        }
        case internal::kAutofillDriver_FocusNoLongerOnForm_Name: {
            internal::AutofillDriver_FocusNoLongerOnForm_Params_Data* params = reinterpret_cast<internal::AutofillDriver_FocusNoLongerOnForm_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            AutofillDriver_FocusNoLongerOnForm_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "AutofillDriver::FocusNoLongerOnForm deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "AutofillDriver::FocusNoLongerOnForm");
            mojo::internal::MessageDispatchContext context(message);
            impl->FocusNoLongerOnForm();
            return true;
        }
        case internal::kAutofillDriver_DidFillAutofillFormData_Name: {
            internal::AutofillDriver_DidFillAutofillFormData_Params_Data* params = reinterpret_cast<internal::AutofillDriver_DidFillAutofillFormData_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            autofill::FormData p_form {};
            base::TimeTicks p_timestamp {};
            AutofillDriver_DidFillAutofillFormData_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadForm(&p_form))
                success = false;
            if (!input_data_view.ReadTimestamp(&p_timestamp))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "AutofillDriver::DidFillAutofillFormData deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "AutofillDriver::DidFillAutofillFormData");
            mojo::internal::MessageDispatchContext context(message);
            impl->DidFillAutofillFormData(
                std::move(p_form),
                std::move(p_timestamp));
            return true;
        }
        case internal::kAutofillDriver_DidPreviewAutofillFormData_Name: {
            internal::AutofillDriver_DidPreviewAutofillFormData_Params_Data* params = reinterpret_cast<internal::AutofillDriver_DidPreviewAutofillFormData_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            AutofillDriver_DidPreviewAutofillFormData_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "AutofillDriver::DidPreviewAutofillFormData deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "AutofillDriver::DidPreviewAutofillFormData");
            mojo::internal::MessageDispatchContext context(message);
            impl->DidPreviewAutofillFormData();
            return true;
        }
        case internal::kAutofillDriver_DidEndTextFieldEditing_Name: {
            internal::AutofillDriver_DidEndTextFieldEditing_Params_Data* params = reinterpret_cast<internal::AutofillDriver_DidEndTextFieldEditing_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            AutofillDriver_DidEndTextFieldEditing_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "AutofillDriver::DidEndTextFieldEditing deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "AutofillDriver::DidEndTextFieldEditing");
            mojo::internal::MessageDispatchContext context(message);
            impl->DidEndTextFieldEditing();
            return true;
        }
        case internal::kAutofillDriver_SetDataList_Name: {
            internal::AutofillDriver_SetDataList_Params_Data* params = reinterpret_cast<internal::AutofillDriver_SetDataList_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::vector<base::string16> p_values {};
            std::vector<base::string16> p_labels {};
            AutofillDriver_SetDataList_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadValues(&p_values))
                success = false;
            if (!input_data_view.ReadLabels(&p_labels))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "AutofillDriver::SetDataList deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "AutofillDriver::SetDataList");
            mojo::internal::MessageDispatchContext context(message);
            impl->SetDataList(
                std::move(p_values),
                std::move(p_labels));
            return true;
        }
        }
        return false;
    }

    // static
    bool AutofillDriverStubDispatch::AcceptWithResponder(
        AutofillDriver* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kAutofillDriver_FirstUserGestureObserved_Name: {
            break;
        }
        case internal::kAutofillDriver_FormsSeen_Name: {
            break;
        }
        case internal::kAutofillDriver_WillSubmitForm_Name: {
            break;
        }
        case internal::kAutofillDriver_FormSubmitted_Name: {
            break;
        }
        case internal::kAutofillDriver_TextFieldDidChange_Name: {
            break;
        }
        case internal::kAutofillDriver_QueryFormFieldAutofill_Name: {
            break;
        }
        case internal::kAutofillDriver_HidePopup_Name: {
            break;
        }
        case internal::kAutofillDriver_FocusNoLongerOnForm_Name: {
            break;
        }
        case internal::kAutofillDriver_DidFillAutofillFormData_Name: {
            break;
        }
        case internal::kAutofillDriver_DidPreviewAutofillFormData_Name: {
            break;
        }
        case internal::kAutofillDriver_DidEndTextFieldEditing_Name: {
            break;
        }
        case internal::kAutofillDriver_SetDataList_Name: {
            break;
        }
        }
        return false;
    }

    bool AutofillDriverRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "AutofillDriver RequestValidator");

        switch (message->header()->name) {
        case internal::kAutofillDriver_FirstUserGestureObserved_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AutofillDriver_FirstUserGestureObserved_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kAutofillDriver_FormsSeen_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AutofillDriver_FormsSeen_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kAutofillDriver_WillSubmitForm_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AutofillDriver_WillSubmitForm_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kAutofillDriver_FormSubmitted_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AutofillDriver_FormSubmitted_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kAutofillDriver_TextFieldDidChange_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AutofillDriver_TextFieldDidChange_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kAutofillDriver_QueryFormFieldAutofill_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AutofillDriver_QueryFormFieldAutofill_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kAutofillDriver_HidePopup_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AutofillDriver_HidePopup_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kAutofillDriver_FocusNoLongerOnForm_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AutofillDriver_FocusNoLongerOnForm_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kAutofillDriver_DidFillAutofillFormData_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AutofillDriver_DidFillAutofillFormData_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kAutofillDriver_DidPreviewAutofillFormData_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AutofillDriver_DidPreviewAutofillFormData_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kAutofillDriver_DidEndTextFieldEditing_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AutofillDriver_DidEndTextFieldEditing_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kAutofillDriver_SetDataList_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::AutofillDriver_SetDataList_Params_Data>(
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

    const char PasswordManagerDriver::Name_[] = "autofill::mojom::PasswordManagerDriver";

    PasswordManagerDriverProxy::PasswordManagerDriverProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void PasswordManagerDriverProxy::PasswordFormsParsed(
        const std::vector<autofill::PasswordForm>& in_forms)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::PasswordManagerDriver_PasswordFormsParsed_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::autofill::mojom::PasswordFormDataView>>(
            in_forms, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kPasswordManagerDriver_PasswordFormsParsed_Name, size);

        auto params = ::autofill::mojom::internal::PasswordManagerDriver_PasswordFormsParsed_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->forms)::BaseType* forms_ptr;
        const mojo::internal::ContainerValidateParams forms_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::autofill::mojom::PasswordFormDataView>>(
            in_forms, builder.buffer(), &forms_ptr, &forms_validate_params,
            &serialization_context);
        params->forms.Set(forms_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->forms.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null forms in PasswordManagerDriver.PasswordFormsParsed request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PasswordManagerDriverProxy::PasswordFormsRendered(
        const std::vector<autofill::PasswordForm>& in_visible_forms, bool in_did_stop_loading)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::PasswordManagerDriver_PasswordFormsRendered_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::autofill::mojom::PasswordFormDataView>>(
            in_visible_forms, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kPasswordManagerDriver_PasswordFormsRendered_Name, size);

        auto params = ::autofill::mojom::internal::PasswordManagerDriver_PasswordFormsRendered_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->visible_forms)::BaseType* visible_forms_ptr;
        const mojo::internal::ContainerValidateParams visible_forms_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::autofill::mojom::PasswordFormDataView>>(
            in_visible_forms, builder.buffer(), &visible_forms_ptr, &visible_forms_validate_params,
            &serialization_context);
        params->visible_forms.Set(visible_forms_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->visible_forms.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null visible_forms in PasswordManagerDriver.PasswordFormsRendered request");
        params->did_stop_loading = in_did_stop_loading;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PasswordManagerDriverProxy::PasswordFormSubmitted(
        const autofill::PasswordForm& in_password_form)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::PasswordManagerDriver_PasswordFormSubmitted_Params_Data);
        size += mojo::internal::PrepareToSerialize<::autofill::mojom::PasswordFormDataView>(
            in_password_form, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kPasswordManagerDriver_PasswordFormSubmitted_Name, size);

        auto params = ::autofill::mojom::internal::PasswordManagerDriver_PasswordFormSubmitted_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->password_form)::BaseType* password_form_ptr;
        mojo::internal::Serialize<::autofill::mojom::PasswordFormDataView>(
            in_password_form, builder.buffer(), &password_form_ptr, &serialization_context);
        params->password_form.Set(password_form_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->password_form.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null password_form in PasswordManagerDriver.PasswordFormSubmitted request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PasswordManagerDriverProxy::InPageNavigation(
        const autofill::PasswordForm& in_password_form)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::PasswordManagerDriver_InPageNavigation_Params_Data);
        size += mojo::internal::PrepareToSerialize<::autofill::mojom::PasswordFormDataView>(
            in_password_form, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kPasswordManagerDriver_InPageNavigation_Name, size);

        auto params = ::autofill::mojom::internal::PasswordManagerDriver_InPageNavigation_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->password_form)::BaseType* password_form_ptr;
        mojo::internal::Serialize<::autofill::mojom::PasswordFormDataView>(
            in_password_form, builder.buffer(), &password_form_ptr, &serialization_context);
        params->password_form.Set(password_form_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->password_form.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null password_form in PasswordManagerDriver.InPageNavigation request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PasswordManagerDriverProxy::RecordSavePasswordProgress(
        const std::string& in_log)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::PasswordManagerDriver_RecordSavePasswordProgress_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_log, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kPasswordManagerDriver_RecordSavePasswordProgress_Name, size);

        auto params = ::autofill::mojom::internal::PasswordManagerDriver_RecordSavePasswordProgress_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->log)::BaseType* log_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_log, builder.buffer(), &log_ptr, &serialization_context);
        params->log.Set(log_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->log.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null log in PasswordManagerDriver.RecordSavePasswordProgress request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PasswordManagerDriverProxy::ShowPasswordSuggestions(
        int32_t in_key, base::i18n::TextDirection in_text_direction, const base::string16& in_typed_username, int32_t in_options, const gfx::RectF& in_bounds)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::PasswordManagerDriver_ShowPasswordSuggestions_Params_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::String16DataView>(
            in_typed_username, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::gfx::mojom::RectFDataView>(
            in_bounds, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kPasswordManagerDriver_ShowPasswordSuggestions_Name, size);

        auto params = ::autofill::mojom::internal::PasswordManagerDriver_ShowPasswordSuggestions_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->key = in_key;
        mojo::internal::Serialize<::mojo::common::mojom::TextDirection>(
            in_text_direction, &params->text_direction);
        typename decltype(params->typed_username)::BaseType* typed_username_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::String16DataView>(
            in_typed_username, builder.buffer(), &typed_username_ptr, &serialization_context);
        params->typed_username.Set(typed_username_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->typed_username.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null typed_username in PasswordManagerDriver.ShowPasswordSuggestions request");
        params->options = in_options;
        typename decltype(params->bounds)::BaseType* bounds_ptr;
        mojo::internal::Serialize<::gfx::mojom::RectFDataView>(
            in_bounds, builder.buffer(), &bounds_ptr, &serialization_context);
        params->bounds.Set(bounds_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->bounds.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null bounds in PasswordManagerDriver.ShowPasswordSuggestions request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PasswordManagerDriverProxy::ShowNotSecureWarning(
        base::i18n::TextDirection in_text_direction, const gfx::RectF& in_bounds)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::PasswordManagerDriver_ShowNotSecureWarning_Params_Data);
        size += mojo::internal::PrepareToSerialize<::gfx::mojom::RectFDataView>(
            in_bounds, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kPasswordManagerDriver_ShowNotSecureWarning_Name, size);

        auto params = ::autofill::mojom::internal::PasswordManagerDriver_ShowNotSecureWarning_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::mojo::common::mojom::TextDirection>(
            in_text_direction, &params->text_direction);
        typename decltype(params->bounds)::BaseType* bounds_ptr;
        mojo::internal::Serialize<::gfx::mojom::RectFDataView>(
            in_bounds, builder.buffer(), &bounds_ptr, &serialization_context);
        params->bounds.Set(bounds_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->bounds.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null bounds in PasswordManagerDriver.ShowNotSecureWarning request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PasswordManagerDriverProxy::PresaveGeneratedPassword(
        const autofill::PasswordForm& in_password_form)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::PasswordManagerDriver_PresaveGeneratedPassword_Params_Data);
        size += mojo::internal::PrepareToSerialize<::autofill::mojom::PasswordFormDataView>(
            in_password_form, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kPasswordManagerDriver_PresaveGeneratedPassword_Name, size);

        auto params = ::autofill::mojom::internal::PasswordManagerDriver_PresaveGeneratedPassword_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->password_form)::BaseType* password_form_ptr;
        mojo::internal::Serialize<::autofill::mojom::PasswordFormDataView>(
            in_password_form, builder.buffer(), &password_form_ptr, &serialization_context);
        params->password_form.Set(password_form_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->password_form.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null password_form in PasswordManagerDriver.PresaveGeneratedPassword request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PasswordManagerDriverProxy::PasswordNoLongerGenerated(
        const autofill::PasswordForm& in_password_form)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::PasswordManagerDriver_PasswordNoLongerGenerated_Params_Data);
        size += mojo::internal::PrepareToSerialize<::autofill::mojom::PasswordFormDataView>(
            in_password_form, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kPasswordManagerDriver_PasswordNoLongerGenerated_Name, size);

        auto params = ::autofill::mojom::internal::PasswordManagerDriver_PasswordNoLongerGenerated_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->password_form)::BaseType* password_form_ptr;
        mojo::internal::Serialize<::autofill::mojom::PasswordFormDataView>(
            in_password_form, builder.buffer(), &password_form_ptr, &serialization_context);
        params->password_form.Set(password_form_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->password_form.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null password_form in PasswordManagerDriver.PasswordNoLongerGenerated request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PasswordManagerDriverProxy::SaveGenerationFieldDetectedByClassifier(
        const autofill::PasswordForm& in_password_form, const base::string16& in_generation_field)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::PasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_Params_Data);
        size += mojo::internal::PrepareToSerialize<::autofill::mojom::PasswordFormDataView>(
            in_password_form, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::String16DataView>(
            in_generation_field, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kPasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_Name, size);

        auto params = ::autofill::mojom::internal::PasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->password_form)::BaseType* password_form_ptr;
        mojo::internal::Serialize<::autofill::mojom::PasswordFormDataView>(
            in_password_form, builder.buffer(), &password_form_ptr, &serialization_context);
        params->password_form.Set(password_form_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->password_form.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null password_form in PasswordManagerDriver.SaveGenerationFieldDetectedByClassifier request");
        typename decltype(params->generation_field)::BaseType* generation_field_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::String16DataView>(
            in_generation_field, builder.buffer(), &generation_field_ptr, &serialization_context);
        params->generation_field.Set(generation_field_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->generation_field.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null generation_field in PasswordManagerDriver.SaveGenerationFieldDetectedByClassifier request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool PasswordManagerDriverStubDispatch::Accept(
        PasswordManagerDriver* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kPasswordManagerDriver_PasswordFormsParsed_Name: {
            internal::PasswordManagerDriver_PasswordFormsParsed_Params_Data* params = reinterpret_cast<internal::PasswordManagerDriver_PasswordFormsParsed_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::vector<autofill::PasswordForm> p_forms {};
            PasswordManagerDriver_PasswordFormsParsed_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadForms(&p_forms))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PasswordManagerDriver::PasswordFormsParsed deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PasswordManagerDriver::PasswordFormsParsed");
            mojo::internal::MessageDispatchContext context(message);
            impl->PasswordFormsParsed(
                std::move(p_forms));
            return true;
        }
        case internal::kPasswordManagerDriver_PasswordFormsRendered_Name: {
            internal::PasswordManagerDriver_PasswordFormsRendered_Params_Data* params = reinterpret_cast<internal::PasswordManagerDriver_PasswordFormsRendered_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::vector<autofill::PasswordForm> p_visible_forms {};
            bool p_did_stop_loading {};
            PasswordManagerDriver_PasswordFormsRendered_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadVisibleForms(&p_visible_forms))
                success = false;
            p_did_stop_loading = input_data_view.did_stop_loading();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PasswordManagerDriver::PasswordFormsRendered deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PasswordManagerDriver::PasswordFormsRendered");
            mojo::internal::MessageDispatchContext context(message);
            impl->PasswordFormsRendered(
                std::move(p_visible_forms),
                std::move(p_did_stop_loading));
            return true;
        }
        case internal::kPasswordManagerDriver_PasswordFormSubmitted_Name: {
            internal::PasswordManagerDriver_PasswordFormSubmitted_Params_Data* params = reinterpret_cast<internal::PasswordManagerDriver_PasswordFormSubmitted_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            autofill::PasswordForm p_password_form {};
            PasswordManagerDriver_PasswordFormSubmitted_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadPasswordForm(&p_password_form))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PasswordManagerDriver::PasswordFormSubmitted deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PasswordManagerDriver::PasswordFormSubmitted");
            mojo::internal::MessageDispatchContext context(message);
            impl->PasswordFormSubmitted(
                std::move(p_password_form));
            return true;
        }
        case internal::kPasswordManagerDriver_InPageNavigation_Name: {
            internal::PasswordManagerDriver_InPageNavigation_Params_Data* params = reinterpret_cast<internal::PasswordManagerDriver_InPageNavigation_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            autofill::PasswordForm p_password_form {};
            PasswordManagerDriver_InPageNavigation_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadPasswordForm(&p_password_form))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PasswordManagerDriver::InPageNavigation deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PasswordManagerDriver::InPageNavigation");
            mojo::internal::MessageDispatchContext context(message);
            impl->InPageNavigation(
                std::move(p_password_form));
            return true;
        }
        case internal::kPasswordManagerDriver_RecordSavePasswordProgress_Name: {
            internal::PasswordManagerDriver_RecordSavePasswordProgress_Params_Data* params = reinterpret_cast<internal::PasswordManagerDriver_RecordSavePasswordProgress_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_log {};
            PasswordManagerDriver_RecordSavePasswordProgress_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadLog(&p_log))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PasswordManagerDriver::RecordSavePasswordProgress deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PasswordManagerDriver::RecordSavePasswordProgress");
            mojo::internal::MessageDispatchContext context(message);
            impl->RecordSavePasswordProgress(
                std::move(p_log));
            return true;
        }
        case internal::kPasswordManagerDriver_ShowPasswordSuggestions_Name: {
            internal::PasswordManagerDriver_ShowPasswordSuggestions_Params_Data* params = reinterpret_cast<internal::PasswordManagerDriver_ShowPasswordSuggestions_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            int32_t p_key {};
            base::i18n::TextDirection p_text_direction {};
            base::string16 p_typed_username {};
            int32_t p_options {};
            gfx::RectF p_bounds {};
            PasswordManagerDriver_ShowPasswordSuggestions_ParamsDataView input_data_view(params,
                context);

            p_key = input_data_view.key();
            if (!input_data_view.ReadTextDirection(&p_text_direction))
                success = false;
            if (!input_data_view.ReadTypedUsername(&p_typed_username))
                success = false;
            p_options = input_data_view.options();
            if (!input_data_view.ReadBounds(&p_bounds))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PasswordManagerDriver::ShowPasswordSuggestions deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PasswordManagerDriver::ShowPasswordSuggestions");
            mojo::internal::MessageDispatchContext context(message);
            impl->ShowPasswordSuggestions(
                std::move(p_key),
                std::move(p_text_direction),
                std::move(p_typed_username),
                std::move(p_options),
                std::move(p_bounds));
            return true;
        }
        case internal::kPasswordManagerDriver_ShowNotSecureWarning_Name: {
            internal::PasswordManagerDriver_ShowNotSecureWarning_Params_Data* params = reinterpret_cast<internal::PasswordManagerDriver_ShowNotSecureWarning_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            base::i18n::TextDirection p_text_direction {};
            gfx::RectF p_bounds {};
            PasswordManagerDriver_ShowNotSecureWarning_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadTextDirection(&p_text_direction))
                success = false;
            if (!input_data_view.ReadBounds(&p_bounds))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PasswordManagerDriver::ShowNotSecureWarning deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PasswordManagerDriver::ShowNotSecureWarning");
            mojo::internal::MessageDispatchContext context(message);
            impl->ShowNotSecureWarning(
                std::move(p_text_direction),
                std::move(p_bounds));
            return true;
        }
        case internal::kPasswordManagerDriver_PresaveGeneratedPassword_Name: {
            internal::PasswordManagerDriver_PresaveGeneratedPassword_Params_Data* params = reinterpret_cast<internal::PasswordManagerDriver_PresaveGeneratedPassword_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            autofill::PasswordForm p_password_form {};
            PasswordManagerDriver_PresaveGeneratedPassword_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadPasswordForm(&p_password_form))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PasswordManagerDriver::PresaveGeneratedPassword deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PasswordManagerDriver::PresaveGeneratedPassword");
            mojo::internal::MessageDispatchContext context(message);
            impl->PresaveGeneratedPassword(
                std::move(p_password_form));
            return true;
        }
        case internal::kPasswordManagerDriver_PasswordNoLongerGenerated_Name: {
            internal::PasswordManagerDriver_PasswordNoLongerGenerated_Params_Data* params = reinterpret_cast<internal::PasswordManagerDriver_PasswordNoLongerGenerated_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            autofill::PasswordForm p_password_form {};
            PasswordManagerDriver_PasswordNoLongerGenerated_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadPasswordForm(&p_password_form))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PasswordManagerDriver::PasswordNoLongerGenerated deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PasswordManagerDriver::PasswordNoLongerGenerated");
            mojo::internal::MessageDispatchContext context(message);
            impl->PasswordNoLongerGenerated(
                std::move(p_password_form));
            return true;
        }
        case internal::kPasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_Name: {
            internal::PasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_Params_Data* params = reinterpret_cast<internal::PasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            autofill::PasswordForm p_password_form {};
            base::string16 p_generation_field {};
            PasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadPasswordForm(&p_password_form))
                success = false;
            if (!input_data_view.ReadGenerationField(&p_generation_field))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PasswordManagerDriver::SaveGenerationFieldDetectedByClassifier deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PasswordManagerDriver::SaveGenerationFieldDetectedByClassifier");
            mojo::internal::MessageDispatchContext context(message);
            impl->SaveGenerationFieldDetectedByClassifier(
                std::move(p_password_form),
                std::move(p_generation_field));
            return true;
        }
        }
        return false;
    }

    // static
    bool PasswordManagerDriverStubDispatch::AcceptWithResponder(
        PasswordManagerDriver* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kPasswordManagerDriver_PasswordFormsParsed_Name: {
            break;
        }
        case internal::kPasswordManagerDriver_PasswordFormsRendered_Name: {
            break;
        }
        case internal::kPasswordManagerDriver_PasswordFormSubmitted_Name: {
            break;
        }
        case internal::kPasswordManagerDriver_InPageNavigation_Name: {
            break;
        }
        case internal::kPasswordManagerDriver_RecordSavePasswordProgress_Name: {
            break;
        }
        case internal::kPasswordManagerDriver_ShowPasswordSuggestions_Name: {
            break;
        }
        case internal::kPasswordManagerDriver_ShowNotSecureWarning_Name: {
            break;
        }
        case internal::kPasswordManagerDriver_PresaveGeneratedPassword_Name: {
            break;
        }
        case internal::kPasswordManagerDriver_PasswordNoLongerGenerated_Name: {
            break;
        }
        case internal::kPasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_Name: {
            break;
        }
        }
        return false;
    }

    bool PasswordManagerDriverRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "PasswordManagerDriver RequestValidator");

        switch (message->header()->name) {
        case internal::kPasswordManagerDriver_PasswordFormsParsed_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PasswordManagerDriver_PasswordFormsParsed_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPasswordManagerDriver_PasswordFormsRendered_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PasswordManagerDriver_PasswordFormsRendered_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPasswordManagerDriver_PasswordFormSubmitted_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PasswordManagerDriver_PasswordFormSubmitted_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPasswordManagerDriver_InPageNavigation_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PasswordManagerDriver_InPageNavigation_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPasswordManagerDriver_RecordSavePasswordProgress_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PasswordManagerDriver_RecordSavePasswordProgress_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPasswordManagerDriver_ShowPasswordSuggestions_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PasswordManagerDriver_ShowPasswordSuggestions_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPasswordManagerDriver_ShowNotSecureWarning_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PasswordManagerDriver_ShowNotSecureWarning_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPasswordManagerDriver_PresaveGeneratedPassword_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PasswordManagerDriver_PresaveGeneratedPassword_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPasswordManagerDriver_PasswordNoLongerGenerated_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PasswordManagerDriver_PasswordNoLongerGenerated_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PasswordManagerDriver_SaveGenerationFieldDetectedByClassifier_Params_Data>(
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

    const char PasswordManagerClient::Name_[] = "autofill::mojom::PasswordManagerClient";

    PasswordManagerClientProxy::PasswordManagerClientProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void PasswordManagerClientProxy::GenerationAvailableForForm(
        const autofill::PasswordForm& in_password_form)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::PasswordManagerClient_GenerationAvailableForForm_Params_Data);
        size += mojo::internal::PrepareToSerialize<::autofill::mojom::PasswordFormDataView>(
            in_password_form, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kPasswordManagerClient_GenerationAvailableForForm_Name, size);

        auto params = ::autofill::mojom::internal::PasswordManagerClient_GenerationAvailableForForm_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->password_form)::BaseType* password_form_ptr;
        mojo::internal::Serialize<::autofill::mojom::PasswordFormDataView>(
            in_password_form, builder.buffer(), &password_form_ptr, &serialization_context);
        params->password_form.Set(password_form_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->password_form.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null password_form in PasswordManagerClient.GenerationAvailableForForm request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PasswordManagerClientProxy::ShowPasswordGenerationPopup(
        const gfx::RectF& in_bounds, int32_t in_max_length, const base::string16& in_generation_element, bool in_is_manually_triggered, const autofill::PasswordForm& in_password_form)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::PasswordManagerClient_ShowPasswordGenerationPopup_Params_Data);
        size += mojo::internal::PrepareToSerialize<::gfx::mojom::RectFDataView>(
            in_bounds, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::String16DataView>(
            in_generation_element, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::autofill::mojom::PasswordFormDataView>(
            in_password_form, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kPasswordManagerClient_ShowPasswordGenerationPopup_Name, size);

        auto params = ::autofill::mojom::internal::PasswordManagerClient_ShowPasswordGenerationPopup_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->bounds)::BaseType* bounds_ptr;
        mojo::internal::Serialize<::gfx::mojom::RectFDataView>(
            in_bounds, builder.buffer(), &bounds_ptr, &serialization_context);
        params->bounds.Set(bounds_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->bounds.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null bounds in PasswordManagerClient.ShowPasswordGenerationPopup request");
        params->max_length = in_max_length;
        typename decltype(params->generation_element)::BaseType* generation_element_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::String16DataView>(
            in_generation_element, builder.buffer(), &generation_element_ptr, &serialization_context);
        params->generation_element.Set(generation_element_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->generation_element.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null generation_element in PasswordManagerClient.ShowPasswordGenerationPopup request");
        params->is_manually_triggered = in_is_manually_triggered;
        typename decltype(params->password_form)::BaseType* password_form_ptr;
        mojo::internal::Serialize<::autofill::mojom::PasswordFormDataView>(
            in_password_form, builder.buffer(), &password_form_ptr, &serialization_context);
        params->password_form.Set(password_form_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->password_form.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null password_form in PasswordManagerClient.ShowPasswordGenerationPopup request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PasswordManagerClientProxy::ShowPasswordEditingPopup(
        const gfx::RectF& in_bounds, const autofill::PasswordForm& in_password_form)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::PasswordManagerClient_ShowPasswordEditingPopup_Params_Data);
        size += mojo::internal::PrepareToSerialize<::gfx::mojom::RectFDataView>(
            in_bounds, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::autofill::mojom::PasswordFormDataView>(
            in_password_form, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kPasswordManagerClient_ShowPasswordEditingPopup_Name, size);

        auto params = ::autofill::mojom::internal::PasswordManagerClient_ShowPasswordEditingPopup_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->bounds)::BaseType* bounds_ptr;
        mojo::internal::Serialize<::gfx::mojom::RectFDataView>(
            in_bounds, builder.buffer(), &bounds_ptr, &serialization_context);
        params->bounds.Set(bounds_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->bounds.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null bounds in PasswordManagerClient.ShowPasswordEditingPopup request");
        typename decltype(params->password_form)::BaseType* password_form_ptr;
        mojo::internal::Serialize<::autofill::mojom::PasswordFormDataView>(
            in_password_form, builder.buffer(), &password_form_ptr, &serialization_context);
        params->password_form.Set(password_form_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->password_form.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null password_form in PasswordManagerClient.ShowPasswordEditingPopup request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void PasswordManagerClientProxy::HidePasswordGenerationPopup()
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::autofill::mojom::internal::PasswordManagerClient_HidePasswordGenerationPopup_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kPasswordManagerClient_HidePasswordGenerationPopup_Name, size);

        auto params = ::autofill::mojom::internal::PasswordManagerClient_HidePasswordGenerationPopup_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    // static
    bool PasswordManagerClientStubDispatch::Accept(
        PasswordManagerClient* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kPasswordManagerClient_GenerationAvailableForForm_Name: {
            internal::PasswordManagerClient_GenerationAvailableForForm_Params_Data* params = reinterpret_cast<internal::PasswordManagerClient_GenerationAvailableForForm_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            autofill::PasswordForm p_password_form {};
            PasswordManagerClient_GenerationAvailableForForm_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadPasswordForm(&p_password_form))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PasswordManagerClient::GenerationAvailableForForm deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PasswordManagerClient::GenerationAvailableForForm");
            mojo::internal::MessageDispatchContext context(message);
            impl->GenerationAvailableForForm(
                std::move(p_password_form));
            return true;
        }
        case internal::kPasswordManagerClient_ShowPasswordGenerationPopup_Name: {
            internal::PasswordManagerClient_ShowPasswordGenerationPopup_Params_Data* params = reinterpret_cast<internal::PasswordManagerClient_ShowPasswordGenerationPopup_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            gfx::RectF p_bounds {};
            int32_t p_max_length {};
            base::string16 p_generation_element {};
            bool p_is_manually_triggered {};
            autofill::PasswordForm p_password_form {};
            PasswordManagerClient_ShowPasswordGenerationPopup_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadBounds(&p_bounds))
                success = false;
            p_max_length = input_data_view.max_length();
            if (!input_data_view.ReadGenerationElement(&p_generation_element))
                success = false;
            p_is_manually_triggered = input_data_view.is_manually_triggered();
            if (!input_data_view.ReadPasswordForm(&p_password_form))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PasswordManagerClient::ShowPasswordGenerationPopup deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PasswordManagerClient::ShowPasswordGenerationPopup");
            mojo::internal::MessageDispatchContext context(message);
            impl->ShowPasswordGenerationPopup(
                std::move(p_bounds),
                std::move(p_max_length),
                std::move(p_generation_element),
                std::move(p_is_manually_triggered),
                std::move(p_password_form));
            return true;
        }
        case internal::kPasswordManagerClient_ShowPasswordEditingPopup_Name: {
            internal::PasswordManagerClient_ShowPasswordEditingPopup_Params_Data* params = reinterpret_cast<internal::PasswordManagerClient_ShowPasswordEditingPopup_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            gfx::RectF p_bounds {};
            autofill::PasswordForm p_password_form {};
            PasswordManagerClient_ShowPasswordEditingPopup_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadBounds(&p_bounds))
                success = false;
            if (!input_data_view.ReadPasswordForm(&p_password_form))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PasswordManagerClient::ShowPasswordEditingPopup deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PasswordManagerClient::ShowPasswordEditingPopup");
            mojo::internal::MessageDispatchContext context(message);
            impl->ShowPasswordEditingPopup(
                std::move(p_bounds),
                std::move(p_password_form));
            return true;
        }
        case internal::kPasswordManagerClient_HidePasswordGenerationPopup_Name: {
            internal::PasswordManagerClient_HidePasswordGenerationPopup_Params_Data* params = reinterpret_cast<internal::PasswordManagerClient_HidePasswordGenerationPopup_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            PasswordManagerClient_HidePasswordGenerationPopup_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "PasswordManagerClient::HidePasswordGenerationPopup deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "PasswordManagerClient::HidePasswordGenerationPopup");
            mojo::internal::MessageDispatchContext context(message);
            impl->HidePasswordGenerationPopup();
            return true;
        }
        }
        return false;
    }

    // static
    bool PasswordManagerClientStubDispatch::AcceptWithResponder(
        PasswordManagerClient* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kPasswordManagerClient_GenerationAvailableForForm_Name: {
            break;
        }
        case internal::kPasswordManagerClient_ShowPasswordGenerationPopup_Name: {
            break;
        }
        case internal::kPasswordManagerClient_ShowPasswordEditingPopup_Name: {
            break;
        }
        case internal::kPasswordManagerClient_HidePasswordGenerationPopup_Name: {
            break;
        }
        }
        return false;
    }

    bool PasswordManagerClientRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "PasswordManagerClient RequestValidator");

        switch (message->header()->name) {
        case internal::kPasswordManagerClient_GenerationAvailableForForm_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PasswordManagerClient_GenerationAvailableForForm_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPasswordManagerClient_ShowPasswordGenerationPopup_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PasswordManagerClient_ShowPasswordGenerationPopup_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPasswordManagerClient_ShowPasswordEditingPopup_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PasswordManagerClient_ShowPasswordEditingPopup_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kPasswordManagerClient_HidePasswordGenerationPopup_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::PasswordManagerClient_HidePasswordGenerationPopup_Params_Data>(
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