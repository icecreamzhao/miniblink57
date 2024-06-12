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

#include "services/catalog/public/interfaces/catalog.mojom.h"

#include <math.h>
#include <stdint.h>
#include <utility>

#include "base/logging.h"
#include "base/trace_event/trace_event.h"
#include "ipc/ipc_message_utils.h"
#include "mojo/common/common_custom_types_struct_traits.h"
#include "mojo/common/values_struct_traits.h"
#include "mojo/public/cpp/bindings/lib/message_builder.h"
#include "mojo/public/cpp/bindings/lib/serialization_util.h"
#include "mojo/public/cpp/bindings/lib/validate_params.h"
#include "mojo/public/cpp/bindings/lib/validation_context.h"
#include "mojo/public/cpp/bindings/lib/validation_errors.h"
#include "mojo/public/interfaces/bindings/interface_control_messages.mojom.h"
namespace catalog {
namespace mojom { // static
    EntryPtr Entry::New()
    {
        EntryPtr rv;
        mojo::internal::StructHelper<Entry>::Initialize(&rv);
        return rv;
    }

    Entry::Entry()
        : name()
        , display_name()
    {
    }

    Entry::~Entry()
    {
    }
    size_t Entry::Hash(size_t seed) const
    {
        seed = mojo::internal::Hash(seed, this->name);
        seed = mojo::internal::Hash(seed, this->display_name);
        return seed;
    }
    const char Catalog::Name_[] = "catalog::mojom::Catalog";
    bool Catalog::GetEntries(const base::Optional<std::vector<std::string>>& names, std::vector<EntryPtr>* entries)
    {
        NOTREACHED();
        return false;
    }
    class Catalog_GetEntries_HandleSyncResponse
        : public mojo::MessageReceiver {
    public:
        Catalog_GetEntries_HandleSyncResponse(
            scoped_refptr<mojo::AssociatedGroupController> group_controller,
            bool* result, std::vector<EntryPtr>* out_entries)
            : serialization_context_(std::move(group_controller))
            , result_(result)
            , out_entries_(out_entries)
        {
            DCHECK(!*result_);
        }
        bool Accept(mojo::Message* message) override;

    private:
        mojo::internal::SerializationContext serialization_context_;
        bool* result_;
        std::vector<EntryPtr>* out_entries_;
        DISALLOW_COPY_AND_ASSIGN(Catalog_GetEntries_HandleSyncResponse);
    };
    bool Catalog_GetEntries_HandleSyncResponse::Accept(
        mojo::Message* message)
    {
        internal::Catalog_GetEntries_ResponseParams_Data* params = reinterpret_cast<internal::Catalog_GetEntries_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        std::vector<EntryPtr> p_entries {};
        Catalog_GetEntries_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadEntries(&p_entries))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Catalog::GetEntries response deserializer");
            return false;
        }
        *out_entries_ = std::move(p_entries);
        mojo::internal::SyncMessageResponseSetup::SetCurrentSyncResponseMessage(
            message);
        *result_ = true;
        return true;
    }

    class Catalog_GetEntries_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        Catalog_GetEntries_ForwardToCallback(
            const Catalog::GetEntriesCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        Catalog::GetEntriesCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(Catalog_GetEntries_ForwardToCallback);
    };
    bool Catalog_GetEntries_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::Catalog_GetEntries_ResponseParams_Data* params = reinterpret_cast<internal::Catalog_GetEntries_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        std::vector<EntryPtr> p_entries {};
        Catalog_GetEntries_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadEntries(&p_entries))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Catalog::GetEntries response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_entries));
        }
        return true;
    }

    class Catalog_GetEntriesProvidingCapability_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        Catalog_GetEntriesProvidingCapability_ForwardToCallback(
            const Catalog::GetEntriesProvidingCapabilityCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        Catalog::GetEntriesProvidingCapabilityCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(Catalog_GetEntriesProvidingCapability_ForwardToCallback);
    };
    bool Catalog_GetEntriesProvidingCapability_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::Catalog_GetEntriesProvidingCapability_ResponseParams_Data* params = reinterpret_cast<internal::Catalog_GetEntriesProvidingCapability_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        std::vector<EntryPtr> p_entries {};
        Catalog_GetEntriesProvidingCapability_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadEntries(&p_entries))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Catalog::GetEntriesProvidingCapability response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_entries));
        }
        return true;
    }

    class Catalog_GetEntriesConsumingMIMEType_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        Catalog_GetEntriesConsumingMIMEType_ForwardToCallback(
            const Catalog::GetEntriesConsumingMIMETypeCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        Catalog::GetEntriesConsumingMIMETypeCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(Catalog_GetEntriesConsumingMIMEType_ForwardToCallback);
    };
    bool Catalog_GetEntriesConsumingMIMEType_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::Catalog_GetEntriesConsumingMIMEType_ResponseParams_Data* params = reinterpret_cast<internal::Catalog_GetEntriesConsumingMIMEType_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        std::vector<EntryPtr> p_entries {};
        Catalog_GetEntriesConsumingMIMEType_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadEntries(&p_entries))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Catalog::GetEntriesConsumingMIMEType response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_entries));
        }
        return true;
    }

    class Catalog_GetEntriesSupportingScheme_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        Catalog_GetEntriesSupportingScheme_ForwardToCallback(
            const Catalog::GetEntriesSupportingSchemeCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        Catalog::GetEntriesSupportingSchemeCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(Catalog_GetEntriesSupportingScheme_ForwardToCallback);
    };
    bool Catalog_GetEntriesSupportingScheme_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::Catalog_GetEntriesSupportingScheme_ResponseParams_Data* params = reinterpret_cast<internal::Catalog_GetEntriesSupportingScheme_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        std::vector<EntryPtr> p_entries {};
        Catalog_GetEntriesSupportingScheme_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadEntries(&p_entries))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Catalog::GetEntriesSupportingScheme response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_entries));
        }
        return true;
    }

    CatalogProxy::CatalogProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }
    bool CatalogProxy::GetEntries(
        const base::Optional<std::vector<std::string>>& param_names, std::vector<EntryPtr>* param_entries)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::catalog::mojom::internal::Catalog_GetEntries_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<mojo::StringDataView>>(
            param_names, &serialization_context);

        mojo::internal::RequestMessageBuilder builder(internal::kCatalog_GetEntries_Name, size,
            mojo::Message::kFlagIsSync);

        auto params = ::catalog::mojom::internal::Catalog_GetEntries_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->names)::BaseType* names_ptr;
        const mojo::internal::ContainerValidateParams names_validate_params(
            0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr));
        mojo::internal::Serialize<mojo::ArrayDataView<mojo::StringDataView>>(
            param_names, builder.buffer(), &names_ptr, &names_validate_params,
            &serialization_context);
        params->names.Set(names_ptr);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());

        bool result = false;
        mojo::MessageReceiver* responder = new Catalog_GetEntries_HandleSyncResponse(
            group_controller_, &result, param_entries);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
        return result;
    }

    void CatalogProxy::GetEntries(
        const base::Optional<std::vector<std::string>>& in_names, const GetEntriesCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::catalog::mojom::internal::Catalog_GetEntries_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<mojo::StringDataView>>(
            in_names, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kCatalog_GetEntries_Name, size);

        auto params = ::catalog::mojom::internal::Catalog_GetEntries_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->names)::BaseType* names_ptr;
        const mojo::internal::ContainerValidateParams names_validate_params(
            0, false, new mojo::internal::ContainerValidateParams(0, false, nullptr));
        mojo::internal::Serialize<mojo::ArrayDataView<mojo::StringDataView>>(
            in_names, builder.buffer(), &names_ptr, &names_validate_params,
            &serialization_context);
        params->names.Set(names_ptr);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new Catalog_GetEntries_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void CatalogProxy::GetEntriesProvidingCapability(
        const std::string& in_capability, const GetEntriesProvidingCapabilityCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::catalog::mojom::internal::Catalog_GetEntriesProvidingCapability_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_capability, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kCatalog_GetEntriesProvidingCapability_Name, size);

        auto params = ::catalog::mojom::internal::Catalog_GetEntriesProvidingCapability_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->capability)::BaseType* capability_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_capability, builder.buffer(), &capability_ptr, &serialization_context);
        params->capability.Set(capability_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->capability.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null capability in Catalog.GetEntriesProvidingCapability request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new Catalog_GetEntriesProvidingCapability_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void CatalogProxy::GetEntriesConsumingMIMEType(
        const std::string& in_mime_type, const GetEntriesConsumingMIMETypeCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::catalog::mojom::internal::Catalog_GetEntriesConsumingMIMEType_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_mime_type, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kCatalog_GetEntriesConsumingMIMEType_Name, size);

        auto params = ::catalog::mojom::internal::Catalog_GetEntriesConsumingMIMEType_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->mime_type)::BaseType* mime_type_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_mime_type, builder.buffer(), &mime_type_ptr, &serialization_context);
        params->mime_type.Set(mime_type_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->mime_type.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null mime_type in Catalog.GetEntriesConsumingMIMEType request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new Catalog_GetEntriesConsumingMIMEType_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void CatalogProxy::GetEntriesSupportingScheme(
        const std::string& in_protocol_scheme, const GetEntriesSupportingSchemeCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::catalog::mojom::internal::Catalog_GetEntriesSupportingScheme_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_protocol_scheme, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kCatalog_GetEntriesSupportingScheme_Name, size);

        auto params = ::catalog::mojom::internal::Catalog_GetEntriesSupportingScheme_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->protocol_scheme)::BaseType* protocol_scheme_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_protocol_scheme, builder.buffer(), &protocol_scheme_ptr, &serialization_context);
        params->protocol_scheme.Set(protocol_scheme_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->protocol_scheme.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null protocol_scheme in Catalog.GetEntriesSupportingScheme request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new Catalog_GetEntriesSupportingScheme_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    class Catalog_GetEntries_ProxyToResponder {
    public:
        static Catalog::GetEntriesCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<Catalog_GetEntries_ProxyToResponder> proxy(
                new Catalog_GetEntries_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&Catalog_GetEntries_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~Catalog_GetEntries_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "Catalog::GetEntries() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        Catalog_GetEntries_ProxyToResponder(
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
            std::vector<EntryPtr> in_entries);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(Catalog_GetEntries_ProxyToResponder);
    };

    void Catalog_GetEntries_ProxyToResponder::Run(
        std::vector<EntryPtr> in_entries)
    {
        size_t size = sizeof(::catalog::mojom::internal::Catalog_GetEntries_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::catalog::mojom::EntryDataView>>(
            in_entries, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kCatalog_GetEntries_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::catalog::mojom::internal::Catalog_GetEntries_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->entries)::BaseType* entries_ptr;
        const mojo::internal::ContainerValidateParams entries_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::catalog::mojom::EntryDataView>>(
            in_entries, builder.buffer(), &entries_ptr, &entries_validate_params,
            &serialization_context_);
        params->entries.Set(entries_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->entries.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null entries in Catalog.GetEntries response");
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class Catalog_GetEntriesProvidingCapability_ProxyToResponder {
    public:
        static Catalog::GetEntriesProvidingCapabilityCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<Catalog_GetEntriesProvidingCapability_ProxyToResponder> proxy(
                new Catalog_GetEntriesProvidingCapability_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&Catalog_GetEntriesProvidingCapability_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~Catalog_GetEntriesProvidingCapability_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "Catalog::GetEntriesProvidingCapability() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        Catalog_GetEntriesProvidingCapability_ProxyToResponder(
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
            std::vector<EntryPtr> in_entries);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(Catalog_GetEntriesProvidingCapability_ProxyToResponder);
    };

    void Catalog_GetEntriesProvidingCapability_ProxyToResponder::Run(
        std::vector<EntryPtr> in_entries)
    {
        size_t size = sizeof(::catalog::mojom::internal::Catalog_GetEntriesProvidingCapability_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::catalog::mojom::EntryDataView>>(
            in_entries, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kCatalog_GetEntriesProvidingCapability_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::catalog::mojom::internal::Catalog_GetEntriesProvidingCapability_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->entries)::BaseType* entries_ptr;
        const mojo::internal::ContainerValidateParams entries_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::catalog::mojom::EntryDataView>>(
            in_entries, builder.buffer(), &entries_ptr, &entries_validate_params,
            &serialization_context_);
        params->entries.Set(entries_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->entries.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null entries in Catalog.GetEntriesProvidingCapability response");
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class Catalog_GetEntriesConsumingMIMEType_ProxyToResponder {
    public:
        static Catalog::GetEntriesConsumingMIMETypeCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<Catalog_GetEntriesConsumingMIMEType_ProxyToResponder> proxy(
                new Catalog_GetEntriesConsumingMIMEType_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&Catalog_GetEntriesConsumingMIMEType_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~Catalog_GetEntriesConsumingMIMEType_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "Catalog::GetEntriesConsumingMIMEType() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        Catalog_GetEntriesConsumingMIMEType_ProxyToResponder(
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
            std::vector<EntryPtr> in_entries);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(Catalog_GetEntriesConsumingMIMEType_ProxyToResponder);
    };

    void Catalog_GetEntriesConsumingMIMEType_ProxyToResponder::Run(
        std::vector<EntryPtr> in_entries)
    {
        size_t size = sizeof(::catalog::mojom::internal::Catalog_GetEntriesConsumingMIMEType_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::catalog::mojom::EntryDataView>>(
            in_entries, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kCatalog_GetEntriesConsumingMIMEType_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::catalog::mojom::internal::Catalog_GetEntriesConsumingMIMEType_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->entries)::BaseType* entries_ptr;
        const mojo::internal::ContainerValidateParams entries_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::catalog::mojom::EntryDataView>>(
            in_entries, builder.buffer(), &entries_ptr, &entries_validate_params,
            &serialization_context_);
        params->entries.Set(entries_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->entries.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null entries in Catalog.GetEntriesConsumingMIMEType response");
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class Catalog_GetEntriesSupportingScheme_ProxyToResponder {
    public:
        static Catalog::GetEntriesSupportingSchemeCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<Catalog_GetEntriesSupportingScheme_ProxyToResponder> proxy(
                new Catalog_GetEntriesSupportingScheme_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&Catalog_GetEntriesSupportingScheme_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~Catalog_GetEntriesSupportingScheme_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "Catalog::GetEntriesSupportingScheme() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        Catalog_GetEntriesSupportingScheme_ProxyToResponder(
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
            std::vector<EntryPtr> in_entries);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(Catalog_GetEntriesSupportingScheme_ProxyToResponder);
    };

    void Catalog_GetEntriesSupportingScheme_ProxyToResponder::Run(
        std::vector<EntryPtr> in_entries)
    {
        size_t size = sizeof(::catalog::mojom::internal::Catalog_GetEntriesSupportingScheme_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::catalog::mojom::EntryDataView>>(
            in_entries, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kCatalog_GetEntriesSupportingScheme_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::catalog::mojom::internal::Catalog_GetEntriesSupportingScheme_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->entries)::BaseType* entries_ptr;
        const mojo::internal::ContainerValidateParams entries_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::catalog::mojom::EntryDataView>>(
            in_entries, builder.buffer(), &entries_ptr, &entries_validate_params,
            &serialization_context_);
        params->entries.Set(entries_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->entries.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null entries in Catalog.GetEntriesSupportingScheme response");
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
    bool CatalogStubDispatch::Accept(
        Catalog* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kCatalog_GetEntries_Name: {
            break;
        }
        case internal::kCatalog_GetEntriesProvidingCapability_Name: {
            break;
        }
        case internal::kCatalog_GetEntriesConsumingMIMEType_Name: {
            break;
        }
        case internal::kCatalog_GetEntriesSupportingScheme_Name: {
            break;
        }
        }
        return false;
    }

    // static
    bool CatalogStubDispatch::AcceptWithResponder(
        Catalog* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kCatalog_GetEntries_Name: {
            internal::Catalog_GetEntries_Params_Data* params = reinterpret_cast<internal::Catalog_GetEntries_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            base::Optional<std::vector<std::string>> p_names {};
            Catalog_GetEntries_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadNames(&p_names))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Catalog::GetEntries deserializer");
                return false;
            }
            Catalog::GetEntriesCallback callback = Catalog_GetEntries_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Catalog::GetEntries");
            mojo::internal::MessageDispatchContext context(message);
            impl->GetEntries(
                std::move(p_names), std::move(callback));
            return true;
        }
        case internal::kCatalog_GetEntriesProvidingCapability_Name: {
            internal::Catalog_GetEntriesProvidingCapability_Params_Data* params = reinterpret_cast<internal::Catalog_GetEntriesProvidingCapability_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_capability {};
            Catalog_GetEntriesProvidingCapability_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadCapability(&p_capability))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Catalog::GetEntriesProvidingCapability deserializer");
                return false;
            }
            Catalog::GetEntriesProvidingCapabilityCallback callback = Catalog_GetEntriesProvidingCapability_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Catalog::GetEntriesProvidingCapability");
            mojo::internal::MessageDispatchContext context(message);
            impl->GetEntriesProvidingCapability(
                std::move(p_capability), std::move(callback));
            return true;
        }
        case internal::kCatalog_GetEntriesConsumingMIMEType_Name: {
            internal::Catalog_GetEntriesConsumingMIMEType_Params_Data* params = reinterpret_cast<internal::Catalog_GetEntriesConsumingMIMEType_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_mime_type {};
            Catalog_GetEntriesConsumingMIMEType_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadMimeType(&p_mime_type))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Catalog::GetEntriesConsumingMIMEType deserializer");
                return false;
            }
            Catalog::GetEntriesConsumingMIMETypeCallback callback = Catalog_GetEntriesConsumingMIMEType_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Catalog::GetEntriesConsumingMIMEType");
            mojo::internal::MessageDispatchContext context(message);
            impl->GetEntriesConsumingMIMEType(
                std::move(p_mime_type), std::move(callback));
            return true;
        }
        case internal::kCatalog_GetEntriesSupportingScheme_Name: {
            internal::Catalog_GetEntriesSupportingScheme_Params_Data* params = reinterpret_cast<internal::Catalog_GetEntriesSupportingScheme_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_protocol_scheme {};
            Catalog_GetEntriesSupportingScheme_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadProtocolScheme(&p_protocol_scheme))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Catalog::GetEntriesSupportingScheme deserializer");
                return false;
            }
            Catalog::GetEntriesSupportingSchemeCallback callback = Catalog_GetEntriesSupportingScheme_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Catalog::GetEntriesSupportingScheme");
            mojo::internal::MessageDispatchContext context(message);
            impl->GetEntriesSupportingScheme(
                std::move(p_protocol_scheme), std::move(callback));
            return true;
        }
        }
        return false;
    }

    bool CatalogRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "Catalog RequestValidator");

        switch (message->header()->name) {
        case internal::kCatalog_GetEntries_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Catalog_GetEntries_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kCatalog_GetEntriesProvidingCapability_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Catalog_GetEntriesProvidingCapability_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kCatalog_GetEntriesConsumingMIMEType_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Catalog_GetEntriesConsumingMIMEType_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kCatalog_GetEntriesSupportingScheme_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Catalog_GetEntriesSupportingScheme_Params_Data>(
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

    bool CatalogResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "Catalog ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kCatalog_GetEntries_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Catalog_GetEntries_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kCatalog_GetEntriesProvidingCapability_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Catalog_GetEntriesProvidingCapability_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kCatalog_GetEntriesConsumingMIMEType_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Catalog_GetEntriesConsumingMIMEType_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kCatalog_GetEntriesSupportingScheme_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Catalog_GetEntriesSupportingScheme_ResponseParams_Data>(
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
    const char CatalogControl::Name_[] = "catalog::mojom::CatalogControl";
    bool CatalogControl::OverrideManifestPath(const std::string& name, const base::FilePath& path)
    {
        NOTREACHED();
        return false;
    }
    class CatalogControl_OverrideManifestPath_HandleSyncResponse
        : public mojo::MessageReceiver {
    public:
        CatalogControl_OverrideManifestPath_HandleSyncResponse(
            scoped_refptr<mojo::AssociatedGroupController> group_controller,
            bool* result)
            : serialization_context_(std::move(group_controller))
            , result_(result)
        {
            DCHECK(!*result_);
        }
        bool Accept(mojo::Message* message) override;

    private:
        mojo::internal::SerializationContext serialization_context_;
        bool* result_;
        DISALLOW_COPY_AND_ASSIGN(CatalogControl_OverrideManifestPath_HandleSyncResponse);
    };
    bool CatalogControl_OverrideManifestPath_HandleSyncResponse::Accept(
        mojo::Message* message)
    {
        internal::CatalogControl_OverrideManifestPath_ResponseParams_Data* params = reinterpret_cast<internal::CatalogControl_OverrideManifestPath_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        CatalogControl_OverrideManifestPath_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "CatalogControl::OverrideManifestPath response deserializer");
            return false;
        }
        mojo::internal::SyncMessageResponseSetup::SetCurrentSyncResponseMessage(
            message);
        *result_ = true;
        return true;
    }

    class CatalogControl_OverrideManifestPath_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        CatalogControl_OverrideManifestPath_ForwardToCallback(
            const CatalogControl::OverrideManifestPathCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        CatalogControl::OverrideManifestPathCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(CatalogControl_OverrideManifestPath_ForwardToCallback);
    };
    bool CatalogControl_OverrideManifestPath_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::CatalogControl_OverrideManifestPath_ResponseParams_Data* params = reinterpret_cast<internal::CatalogControl_OverrideManifestPath_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        CatalogControl_OverrideManifestPath_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "CatalogControl::OverrideManifestPath response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run();
        }
        return true;
    }

    CatalogControlProxy::CatalogControlProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }
    bool CatalogControlProxy::OverrideManifestPath(
        const std::string& param_name, const base::FilePath& param_path)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::catalog::mojom::internal::CatalogControl_OverrideManifestPath_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            param_name, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::FilePathDataView>(
            param_path, &serialization_context);

        mojo::internal::RequestMessageBuilder builder(internal::kCatalogControl_OverrideManifestPath_Name, size,
            mojo::Message::kFlagIsSync);

        auto params = ::catalog::mojom::internal::CatalogControl_OverrideManifestPath_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->name)::BaseType* name_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            param_name, builder.buffer(), &name_ptr, &serialization_context);
        params->name.Set(name_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->name.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null name in CatalogControl.OverrideManifestPath request");
        typename decltype(params->path)::BaseType* path_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::FilePathDataView>(
            param_path, builder.buffer(), &path_ptr, &serialization_context);
        params->path.Set(path_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->path.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null path in CatalogControl.OverrideManifestPath request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());

        bool result = false;
        mojo::MessageReceiver* responder = new CatalogControl_OverrideManifestPath_HandleSyncResponse(
            group_controller_, &result);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
        return result;
    }

    void CatalogControlProxy::OverrideManifestPath(
        const std::string& in_name, const base::FilePath& in_path, const OverrideManifestPathCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::catalog::mojom::internal::CatalogControl_OverrideManifestPath_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_name, &serialization_context);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::FilePathDataView>(
            in_path, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kCatalogControl_OverrideManifestPath_Name, size);

        auto params = ::catalog::mojom::internal::CatalogControl_OverrideManifestPath_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->name)::BaseType* name_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_name, builder.buffer(), &name_ptr, &serialization_context);
        params->name.Set(name_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->name.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null name in CatalogControl.OverrideManifestPath request");
        typename decltype(params->path)::BaseType* path_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::FilePathDataView>(
            in_path, builder.buffer(), &path_ptr, &serialization_context);
        params->path.Set(path_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->path.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null path in CatalogControl.OverrideManifestPath request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new CatalogControl_OverrideManifestPath_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    class CatalogControl_OverrideManifestPath_ProxyToResponder {
    public:
        static CatalogControl::OverrideManifestPathCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<CatalogControl_OverrideManifestPath_ProxyToResponder> proxy(
                new CatalogControl_OverrideManifestPath_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&CatalogControl_OverrideManifestPath_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~CatalogControl_OverrideManifestPath_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "CatalogControl::OverrideManifestPath() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        CatalogControl_OverrideManifestPath_ProxyToResponder(
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

        void Run();

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(CatalogControl_OverrideManifestPath_ProxyToResponder);
    };

    void CatalogControl_OverrideManifestPath_ProxyToResponder::Run()
    {
        size_t size = sizeof(::catalog::mojom::internal::CatalogControl_OverrideManifestPath_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kCatalogControl_OverrideManifestPath_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::catalog::mojom::internal::CatalogControl_OverrideManifestPath_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
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
    bool CatalogControlStubDispatch::Accept(
        CatalogControl* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kCatalogControl_OverrideManifestPath_Name: {
            break;
        }
        }
        return false;
    }

    // static
    bool CatalogControlStubDispatch::AcceptWithResponder(
        CatalogControl* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kCatalogControl_OverrideManifestPath_Name: {
            internal::CatalogControl_OverrideManifestPath_Params_Data* params = reinterpret_cast<internal::CatalogControl_OverrideManifestPath_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_name {};
            base::FilePath p_path {};
            CatalogControl_OverrideManifestPath_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadName(&p_name))
                success = false;
            if (!input_data_view.ReadPath(&p_path))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "CatalogControl::OverrideManifestPath deserializer");
                return false;
            }
            CatalogControl::OverrideManifestPathCallback callback = CatalogControl_OverrideManifestPath_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "CatalogControl::OverrideManifestPath");
            mojo::internal::MessageDispatchContext context(message);
            impl->OverrideManifestPath(
                std::move(p_name),
                std::move(p_path), std::move(callback));
            return true;
        }
        }
        return false;
    }

    bool CatalogControlRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "CatalogControl RequestValidator");

        switch (message->header()->name) {
        case internal::kCatalogControl_OverrideManifestPath_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::CatalogControl_OverrideManifestPath_Params_Data>(
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

    bool CatalogControlResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "CatalogControl ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kCatalogControl_OverrideManifestPath_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::CatalogControl_OverrideManifestPath_ResponseParams_Data>(
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
} // namespace catalog

namespace mojo {

// static
bool StructTraits<::catalog::mojom::Entry::DataView, ::catalog::mojom::EntryPtr>::Read(
    ::catalog::mojom::Entry::DataView input,
    ::catalog::mojom::EntryPtr* output)
{
    bool success = true;
    ::catalog::mojom::EntryPtr result(::catalog::mojom::Entry::New());

    if (!input.ReadName(&result->name))
        success = false;
    if (!input.ReadDisplayName(&result->display_name))
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