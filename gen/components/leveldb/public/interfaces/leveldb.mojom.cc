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

#include "components/leveldb/public/interfaces/leveldb.mojom.h"

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
namespace leveldb {
namespace mojom { // static
    BatchedOperationPtr BatchedOperation::New()
    {
        BatchedOperationPtr rv;
        mojo::internal::StructHelper<BatchedOperation>::Initialize(&rv);
        return rv;
    }

    BatchedOperation::BatchedOperation()
        : type()
        , key()
        , value()
    {
    }

    BatchedOperation::~BatchedOperation()
    {
    } // static
    KeyValuePtr KeyValue::New()
    {
        KeyValuePtr rv;
        mojo::internal::StructHelper<KeyValue>::Initialize(&rv);
        return rv;
    }

    KeyValue::KeyValue()
        : key()
        , value()
    {
    }

    KeyValue::~KeyValue()
    {
    } // static
    OpenOptionsPtr OpenOptions::New()
    {
        OpenOptionsPtr rv;
        mojo::internal::StructHelper<OpenOptions>::Initialize(&rv);
        return rv;
    }

    OpenOptions::OpenOptions()
        : create_if_missing(false)
        , error_if_exists(false)
        , paranoid_checks(false)
        , write_buffer_size(4194304ULL)
        , max_open_files(80)
    {
    }

    OpenOptions::~OpenOptions()
    {
    }
    size_t OpenOptions::Hash(size_t seed) const
    {
        seed = mojo::internal::Hash(seed, this->create_if_missing);
        seed = mojo::internal::Hash(seed, this->error_if_exists);
        seed = mojo::internal::Hash(seed, this->paranoid_checks);
        seed = mojo::internal::Hash(seed, this->write_buffer_size);
        seed = mojo::internal::Hash(seed, this->max_open_files);
        return seed;
    }
    const char LevelDBService::Name_[] = "leveldb::mojom::LevelDBService";

    class LevelDBService_Open_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        LevelDBService_Open_ForwardToCallback(
            const LevelDBService::OpenCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        LevelDBService::OpenCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(LevelDBService_Open_ForwardToCallback);
    };
    bool LevelDBService_Open_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::LevelDBService_Open_ResponseParams_Data* params = reinterpret_cast<internal::LevelDBService_Open_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        DatabaseError p_status {};
        LevelDBService_Open_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadStatus(&p_status))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "LevelDBService::Open response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_status));
        }
        return true;
    }

    class LevelDBService_OpenWithOptions_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        LevelDBService_OpenWithOptions_ForwardToCallback(
            const LevelDBService::OpenWithOptionsCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        LevelDBService::OpenWithOptionsCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(LevelDBService_OpenWithOptions_ForwardToCallback);
    };
    bool LevelDBService_OpenWithOptions_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::LevelDBService_OpenWithOptions_ResponseParams_Data* params = reinterpret_cast<internal::LevelDBService_OpenWithOptions_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        DatabaseError p_status {};
        LevelDBService_OpenWithOptions_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadStatus(&p_status))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "LevelDBService::OpenWithOptions response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_status));
        }
        return true;
    }

    class LevelDBService_OpenInMemory_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        LevelDBService_OpenInMemory_ForwardToCallback(
            const LevelDBService::OpenInMemoryCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        LevelDBService::OpenInMemoryCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(LevelDBService_OpenInMemory_ForwardToCallback);
    };
    bool LevelDBService_OpenInMemory_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::LevelDBService_OpenInMemory_ResponseParams_Data* params = reinterpret_cast<internal::LevelDBService_OpenInMemory_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        DatabaseError p_status {};
        LevelDBService_OpenInMemory_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadStatus(&p_status))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "LevelDBService::OpenInMemory response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_status));
        }
        return true;
    }

    class LevelDBService_Destroy_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        LevelDBService_Destroy_ForwardToCallback(
            const LevelDBService::DestroyCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        LevelDBService::DestroyCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(LevelDBService_Destroy_ForwardToCallback);
    };
    bool LevelDBService_Destroy_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::LevelDBService_Destroy_ResponseParams_Data* params = reinterpret_cast<internal::LevelDBService_Destroy_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        DatabaseError p_status {};
        LevelDBService_Destroy_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadStatus(&p_status))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "LevelDBService::Destroy response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_status));
        }
        return true;
    }

    LevelDBServiceProxy::LevelDBServiceProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void LevelDBServiceProxy::Open(
        ::filesystem::mojom::DirectoryPtr in_directory, const std::string& in_dbname, LevelDBDatabaseAssociatedRequest in_database, const OpenCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBService_Open_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_dbname, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kLevelDBService_Open_Name, size);

        auto params = ::leveldb::mojom::internal::LevelDBService_Open_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::filesystem::mojom::DirectoryPtrDataView>(
            in_directory, &params->directory, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->directory),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid directory in LevelDBService.Open request");
        typename decltype(params->dbname)::BaseType* dbname_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_dbname, builder.buffer(), &dbname_ptr, &serialization_context);
        params->dbname.Set(dbname_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->dbname.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null dbname in LevelDBService.Open request");
        mojo::internal::Serialize<::leveldb::mojom::LevelDBDatabaseAssociatedRequestDataView>(
            in_database, &params->database, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->database),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_INTERFACE_ID,
            "invalid database in LevelDBService.Open request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new LevelDBService_Open_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void LevelDBServiceProxy::OpenWithOptions(
        OpenOptionsPtr in_options, ::filesystem::mojom::DirectoryPtr in_directory, const std::string& in_dbname, LevelDBDatabaseAssociatedRequest in_database, const OpenWithOptionsCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBService_OpenWithOptions_Params_Data);
        size += mojo::internal::PrepareToSerialize<::leveldb::mojom::OpenOptionsDataView>(
            in_options, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_dbname, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kLevelDBService_OpenWithOptions_Name, size);

        auto params = ::leveldb::mojom::internal::LevelDBService_OpenWithOptions_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->options)::BaseType* options_ptr;
        mojo::internal::Serialize<::leveldb::mojom::OpenOptionsDataView>(
            in_options, builder.buffer(), &options_ptr, &serialization_context);
        params->options.Set(options_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->options.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null options in LevelDBService.OpenWithOptions request");
        mojo::internal::Serialize<::filesystem::mojom::DirectoryPtrDataView>(
            in_directory, &params->directory, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->directory),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid directory in LevelDBService.OpenWithOptions request");
        typename decltype(params->dbname)::BaseType* dbname_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_dbname, builder.buffer(), &dbname_ptr, &serialization_context);
        params->dbname.Set(dbname_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->dbname.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null dbname in LevelDBService.OpenWithOptions request");
        mojo::internal::Serialize<::leveldb::mojom::LevelDBDatabaseAssociatedRequestDataView>(
            in_database, &params->database, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->database),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_INTERFACE_ID,
            "invalid database in LevelDBService.OpenWithOptions request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new LevelDBService_OpenWithOptions_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void LevelDBServiceProxy::OpenInMemory(
        LevelDBDatabaseAssociatedRequest in_database, const OpenInMemoryCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBService_OpenInMemory_Params_Data);
        mojo::internal::RequestMessageBuilder builder(internal::kLevelDBService_OpenInMemory_Name, size);

        auto params = ::leveldb::mojom::internal::LevelDBService_OpenInMemory_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::leveldb::mojom::LevelDBDatabaseAssociatedRequestDataView>(
            in_database, &params->database, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->database),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_INTERFACE_ID,
            "invalid database in LevelDBService.OpenInMemory request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new LevelDBService_OpenInMemory_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void LevelDBServiceProxy::Destroy(
        ::filesystem::mojom::DirectoryPtr in_directory, const std::string& in_dbname, const DestroyCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBService_Destroy_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_dbname, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kLevelDBService_Destroy_Name, size);

        auto params = ::leveldb::mojom::internal::LevelDBService_Destroy_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::filesystem::mojom::DirectoryPtrDataView>(
            in_directory, &params->directory, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->directory),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid directory in LevelDBService.Destroy request");
        typename decltype(params->dbname)::BaseType* dbname_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_dbname, builder.buffer(), &dbname_ptr, &serialization_context);
        params->dbname.Set(dbname_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->dbname.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null dbname in LevelDBService.Destroy request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new LevelDBService_Destroy_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    class LevelDBService_Open_ProxyToResponder {
    public:
        static LevelDBService::OpenCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<LevelDBService_Open_ProxyToResponder> proxy(
                new LevelDBService_Open_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&LevelDBService_Open_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~LevelDBService_Open_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "LevelDBService::Open() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        LevelDBService_Open_ProxyToResponder(
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
            DatabaseError in_status);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(LevelDBService_Open_ProxyToResponder);
    };

    void LevelDBService_Open_ProxyToResponder::Run(
        DatabaseError in_status)
    {
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBService_Open_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kLevelDBService_Open_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::leveldb::mojom::internal::LevelDBService_Open_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::leveldb::mojom::DatabaseError>(
            in_status, &params->status);
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class LevelDBService_OpenWithOptions_ProxyToResponder {
    public:
        static LevelDBService::OpenWithOptionsCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<LevelDBService_OpenWithOptions_ProxyToResponder> proxy(
                new LevelDBService_OpenWithOptions_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&LevelDBService_OpenWithOptions_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~LevelDBService_OpenWithOptions_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "LevelDBService::OpenWithOptions() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        LevelDBService_OpenWithOptions_ProxyToResponder(
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
            DatabaseError in_status);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(LevelDBService_OpenWithOptions_ProxyToResponder);
    };

    void LevelDBService_OpenWithOptions_ProxyToResponder::Run(
        DatabaseError in_status)
    {
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBService_OpenWithOptions_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kLevelDBService_OpenWithOptions_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::leveldb::mojom::internal::LevelDBService_OpenWithOptions_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::leveldb::mojom::DatabaseError>(
            in_status, &params->status);
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class LevelDBService_OpenInMemory_ProxyToResponder {
    public:
        static LevelDBService::OpenInMemoryCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<LevelDBService_OpenInMemory_ProxyToResponder> proxy(
                new LevelDBService_OpenInMemory_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&LevelDBService_OpenInMemory_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~LevelDBService_OpenInMemory_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "LevelDBService::OpenInMemory() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        LevelDBService_OpenInMemory_ProxyToResponder(
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
            DatabaseError in_status);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(LevelDBService_OpenInMemory_ProxyToResponder);
    };

    void LevelDBService_OpenInMemory_ProxyToResponder::Run(
        DatabaseError in_status)
    {
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBService_OpenInMemory_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kLevelDBService_OpenInMemory_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::leveldb::mojom::internal::LevelDBService_OpenInMemory_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::leveldb::mojom::DatabaseError>(
            in_status, &params->status);
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class LevelDBService_Destroy_ProxyToResponder {
    public:
        static LevelDBService::DestroyCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<LevelDBService_Destroy_ProxyToResponder> proxy(
                new LevelDBService_Destroy_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&LevelDBService_Destroy_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~LevelDBService_Destroy_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "LevelDBService::Destroy() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        LevelDBService_Destroy_ProxyToResponder(
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
            DatabaseError in_status);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(LevelDBService_Destroy_ProxyToResponder);
    };

    void LevelDBService_Destroy_ProxyToResponder::Run(
        DatabaseError in_status)
    {
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBService_Destroy_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kLevelDBService_Destroy_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::leveldb::mojom::internal::LevelDBService_Destroy_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::leveldb::mojom::DatabaseError>(
            in_status, &params->status);
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
    bool LevelDBServiceStubDispatch::Accept(
        LevelDBService* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kLevelDBService_Open_Name: {
            break;
        }
        case internal::kLevelDBService_OpenWithOptions_Name: {
            break;
        }
        case internal::kLevelDBService_OpenInMemory_Name: {
            break;
        }
        case internal::kLevelDBService_Destroy_Name: {
            break;
        }
        }
        return false;
    }

    // static
    bool LevelDBServiceStubDispatch::AcceptWithResponder(
        LevelDBService* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kLevelDBService_Open_Name: {
            internal::LevelDBService_Open_Params_Data* params = reinterpret_cast<internal::LevelDBService_Open_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::filesystem::mojom::DirectoryPtr p_directory {};
            std::string p_dbname {};
            LevelDBDatabaseAssociatedRequest p_database {};
            LevelDBService_Open_ParamsDataView input_data_view(params,
                context);

            p_directory = input_data_view.TakeDirectory<decltype(p_directory)>();
            if (!input_data_view.ReadDbname(&p_dbname))
                success = false;
            p_database = input_data_view.TakeDatabase<decltype(p_database)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "LevelDBService::Open deserializer");
                return false;
            }
            LevelDBService::OpenCallback callback = LevelDBService_Open_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "LevelDBService::Open");
            mojo::internal::MessageDispatchContext context(message);
            impl->Open(
                std::move(p_directory),
                std::move(p_dbname),
                std::move(p_database), std::move(callback));
            return true;
        }
        case internal::kLevelDBService_OpenWithOptions_Name: {
            internal::LevelDBService_OpenWithOptions_Params_Data* params = reinterpret_cast<internal::LevelDBService_OpenWithOptions_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            OpenOptionsPtr p_options {};
            ::filesystem::mojom::DirectoryPtr p_directory {};
            std::string p_dbname {};
            LevelDBDatabaseAssociatedRequest p_database {};
            LevelDBService_OpenWithOptions_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadOptions(&p_options))
                success = false;
            p_directory = input_data_view.TakeDirectory<decltype(p_directory)>();
            if (!input_data_view.ReadDbname(&p_dbname))
                success = false;
            p_database = input_data_view.TakeDatabase<decltype(p_database)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "LevelDBService::OpenWithOptions deserializer");
                return false;
            }
            LevelDBService::OpenWithOptionsCallback callback = LevelDBService_OpenWithOptions_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "LevelDBService::OpenWithOptions");
            mojo::internal::MessageDispatchContext context(message);
            impl->OpenWithOptions(
                std::move(p_options),
                std::move(p_directory),
                std::move(p_dbname),
                std::move(p_database), std::move(callback));
            return true;
        }
        case internal::kLevelDBService_OpenInMemory_Name: {
            internal::LevelDBService_OpenInMemory_Params_Data* params = reinterpret_cast<internal::LevelDBService_OpenInMemory_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            LevelDBDatabaseAssociatedRequest p_database {};
            LevelDBService_OpenInMemory_ParamsDataView input_data_view(params,
                context);

            p_database = input_data_view.TakeDatabase<decltype(p_database)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "LevelDBService::OpenInMemory deserializer");
                return false;
            }
            LevelDBService::OpenInMemoryCallback callback = LevelDBService_OpenInMemory_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "LevelDBService::OpenInMemory");
            mojo::internal::MessageDispatchContext context(message);
            impl->OpenInMemory(
                std::move(p_database), std::move(callback));
            return true;
        }
        case internal::kLevelDBService_Destroy_Name: {
            internal::LevelDBService_Destroy_Params_Data* params = reinterpret_cast<internal::LevelDBService_Destroy_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            ::filesystem::mojom::DirectoryPtr p_directory {};
            std::string p_dbname {};
            LevelDBService_Destroy_ParamsDataView input_data_view(params,
                context);

            p_directory = input_data_view.TakeDirectory<decltype(p_directory)>();
            if (!input_data_view.ReadDbname(&p_dbname))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "LevelDBService::Destroy deserializer");
                return false;
            }
            LevelDBService::DestroyCallback callback = LevelDBService_Destroy_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "LevelDBService::Destroy");
            mojo::internal::MessageDispatchContext context(message);
            impl->Destroy(
                std::move(p_directory),
                std::move(p_dbname), std::move(callback));
            return true;
        }
        }
        return false;
    }

    bool LevelDBServiceRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "LevelDBService RequestValidator");

        switch (message->header()->name) {
        case internal::kLevelDBService_Open_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBService_Open_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBService_OpenWithOptions_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBService_OpenWithOptions_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBService_OpenInMemory_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBService_OpenInMemory_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBService_Destroy_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBService_Destroy_Params_Data>(
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

    bool LevelDBServiceResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "LevelDBService ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kLevelDBService_Open_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBService_Open_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBService_OpenWithOptions_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBService_OpenWithOptions_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBService_OpenInMemory_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBService_OpenInMemory_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBService_Destroy_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBService_Destroy_ResponseParams_Data>(
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
    const char LevelDBDatabase::Name_[] = "leveldb::mojom::LevelDBDatabase";
    bool LevelDBDatabase::IteratorSeekToFirst(const base::UnguessableToken& iterator, bool* valid, DatabaseError* status, base::Optional<std::vector<uint8_t>>* key, base::Optional<std::vector<uint8_t>>* value)
    {
        NOTREACHED();
        return false;
    }
    bool LevelDBDatabase::IteratorSeekToLast(const base::UnguessableToken& iterator, bool* valid, DatabaseError* status, base::Optional<std::vector<uint8_t>>* key, base::Optional<std::vector<uint8_t>>* value)
    {
        NOTREACHED();
        return false;
    }
    bool LevelDBDatabase::IteratorSeek(const base::UnguessableToken& iterator, const std::vector<uint8_t>& target, bool* valid, DatabaseError* status, base::Optional<std::vector<uint8_t>>* key, base::Optional<std::vector<uint8_t>>* value)
    {
        NOTREACHED();
        return false;
    }
    bool LevelDBDatabase::IteratorNext(const base::UnguessableToken& iterator, bool* valid, DatabaseError* status, base::Optional<std::vector<uint8_t>>* key, base::Optional<std::vector<uint8_t>>* value)
    {
        NOTREACHED();
        return false;
    }
    bool LevelDBDatabase::IteratorPrev(const base::UnguessableToken& iterator, bool* valid, DatabaseError* status, base::Optional<std::vector<uint8_t>>* key, base::Optional<std::vector<uint8_t>>* value)
    {
        NOTREACHED();
        return false;
    }

    class LevelDBDatabase_Put_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        LevelDBDatabase_Put_ForwardToCallback(
            const LevelDBDatabase::PutCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        LevelDBDatabase::PutCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(LevelDBDatabase_Put_ForwardToCallback);
    };
    bool LevelDBDatabase_Put_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::LevelDBDatabase_Put_ResponseParams_Data* params = reinterpret_cast<internal::LevelDBDatabase_Put_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        DatabaseError p_status {};
        LevelDBDatabase_Put_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadStatus(&p_status))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "LevelDBDatabase::Put response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_status));
        }
        return true;
    }

    class LevelDBDatabase_Delete_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        LevelDBDatabase_Delete_ForwardToCallback(
            const LevelDBDatabase::DeleteCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        LevelDBDatabase::DeleteCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(LevelDBDatabase_Delete_ForwardToCallback);
    };
    bool LevelDBDatabase_Delete_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::LevelDBDatabase_Delete_ResponseParams_Data* params = reinterpret_cast<internal::LevelDBDatabase_Delete_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        DatabaseError p_status {};
        LevelDBDatabase_Delete_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadStatus(&p_status))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "LevelDBDatabase::Delete response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_status));
        }
        return true;
    }

    class LevelDBDatabase_DeletePrefixed_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        LevelDBDatabase_DeletePrefixed_ForwardToCallback(
            const LevelDBDatabase::DeletePrefixedCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        LevelDBDatabase::DeletePrefixedCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(LevelDBDatabase_DeletePrefixed_ForwardToCallback);
    };
    bool LevelDBDatabase_DeletePrefixed_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::LevelDBDatabase_DeletePrefixed_ResponseParams_Data* params = reinterpret_cast<internal::LevelDBDatabase_DeletePrefixed_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        DatabaseError p_status {};
        LevelDBDatabase_DeletePrefixed_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadStatus(&p_status))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "LevelDBDatabase::DeletePrefixed response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_status));
        }
        return true;
    }

    class LevelDBDatabase_Write_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        LevelDBDatabase_Write_ForwardToCallback(
            const LevelDBDatabase::WriteCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        LevelDBDatabase::WriteCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(LevelDBDatabase_Write_ForwardToCallback);
    };
    bool LevelDBDatabase_Write_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::LevelDBDatabase_Write_ResponseParams_Data* params = reinterpret_cast<internal::LevelDBDatabase_Write_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        DatabaseError p_status {};
        LevelDBDatabase_Write_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadStatus(&p_status))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "LevelDBDatabase::Write response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_status));
        }
        return true;
    }

    class LevelDBDatabase_Get_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        LevelDBDatabase_Get_ForwardToCallback(
            const LevelDBDatabase::GetCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        LevelDBDatabase::GetCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(LevelDBDatabase_Get_ForwardToCallback);
    };
    bool LevelDBDatabase_Get_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::LevelDBDatabase_Get_ResponseParams_Data* params = reinterpret_cast<internal::LevelDBDatabase_Get_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        DatabaseError p_status {};
        std::vector<uint8_t> p_value {};
        LevelDBDatabase_Get_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadStatus(&p_status))
            success = false;
        if (!input_data_view.ReadValue(&p_value))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "LevelDBDatabase::Get response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_status),
                std::move(p_value));
        }
        return true;
    }

    class LevelDBDatabase_GetPrefixed_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        LevelDBDatabase_GetPrefixed_ForwardToCallback(
            const LevelDBDatabase::GetPrefixedCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        LevelDBDatabase::GetPrefixedCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(LevelDBDatabase_GetPrefixed_ForwardToCallback);
    };
    bool LevelDBDatabase_GetPrefixed_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::LevelDBDatabase_GetPrefixed_ResponseParams_Data* params = reinterpret_cast<internal::LevelDBDatabase_GetPrefixed_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        DatabaseError p_status {};
        std::vector<KeyValuePtr> p_data {};
        LevelDBDatabase_GetPrefixed_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadStatus(&p_status))
            success = false;
        if (!input_data_view.ReadData(&p_data))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "LevelDBDatabase::GetPrefixed response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_status),
                std::move(p_data));
        }
        return true;
    }

    class LevelDBDatabase_GetSnapshot_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        LevelDBDatabase_GetSnapshot_ForwardToCallback(
            const LevelDBDatabase::GetSnapshotCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        LevelDBDatabase::GetSnapshotCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(LevelDBDatabase_GetSnapshot_ForwardToCallback);
    };
    bool LevelDBDatabase_GetSnapshot_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::LevelDBDatabase_GetSnapshot_ResponseParams_Data* params = reinterpret_cast<internal::LevelDBDatabase_GetSnapshot_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        base::UnguessableToken p_snapshot {};
        LevelDBDatabase_GetSnapshot_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadSnapshot(&p_snapshot))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "LevelDBDatabase::GetSnapshot response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_snapshot));
        }
        return true;
    }

    class LevelDBDatabase_GetFromSnapshot_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        LevelDBDatabase_GetFromSnapshot_ForwardToCallback(
            const LevelDBDatabase::GetFromSnapshotCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        LevelDBDatabase::GetFromSnapshotCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(LevelDBDatabase_GetFromSnapshot_ForwardToCallback);
    };
    bool LevelDBDatabase_GetFromSnapshot_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::LevelDBDatabase_GetFromSnapshot_ResponseParams_Data* params = reinterpret_cast<internal::LevelDBDatabase_GetFromSnapshot_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        DatabaseError p_status {};
        std::vector<uint8_t> p_value {};
        LevelDBDatabase_GetFromSnapshot_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadStatus(&p_status))
            success = false;
        if (!input_data_view.ReadValue(&p_value))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "LevelDBDatabase::GetFromSnapshot response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_status),
                std::move(p_value));
        }
        return true;
    }

    class LevelDBDatabase_NewIterator_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        LevelDBDatabase_NewIterator_ForwardToCallback(
            const LevelDBDatabase::NewIteratorCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        LevelDBDatabase::NewIteratorCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(LevelDBDatabase_NewIterator_ForwardToCallback);
    };
    bool LevelDBDatabase_NewIterator_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::LevelDBDatabase_NewIterator_ResponseParams_Data* params = reinterpret_cast<internal::LevelDBDatabase_NewIterator_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        base::UnguessableToken p_iterator {};
        LevelDBDatabase_NewIterator_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadIterator(&p_iterator))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "LevelDBDatabase::NewIterator response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_iterator));
        }
        return true;
    }

    class LevelDBDatabase_NewIteratorFromSnapshot_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        LevelDBDatabase_NewIteratorFromSnapshot_ForwardToCallback(
            const LevelDBDatabase::NewIteratorFromSnapshotCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        LevelDBDatabase::NewIteratorFromSnapshotCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(LevelDBDatabase_NewIteratorFromSnapshot_ForwardToCallback);
    };
    bool LevelDBDatabase_NewIteratorFromSnapshot_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::LevelDBDatabase_NewIteratorFromSnapshot_ResponseParams_Data* params = reinterpret_cast<internal::LevelDBDatabase_NewIteratorFromSnapshot_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        base::Optional<base::UnguessableToken> p_iterator {};
        LevelDBDatabase_NewIteratorFromSnapshot_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadIterator(&p_iterator))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "LevelDBDatabase::NewIteratorFromSnapshot response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_iterator));
        }
        return true;
    }
    class LevelDBDatabase_IteratorSeekToFirst_HandleSyncResponse
        : public mojo::MessageReceiver {
    public:
        LevelDBDatabase_IteratorSeekToFirst_HandleSyncResponse(
            scoped_refptr<mojo::AssociatedGroupController> group_controller,
            bool* result, bool* out_valid, DatabaseError* out_status, base::Optional<std::vector<uint8_t>>* out_key, base::Optional<std::vector<uint8_t>>* out_value)
            : serialization_context_(std::move(group_controller))
            , result_(result)
            , out_valid_(out_valid)
            , out_status_(out_status)
            , out_key_(out_key)
            , out_value_(out_value)
        {
            DCHECK(!*result_);
        }
        bool Accept(mojo::Message* message) override;

    private:
        mojo::internal::SerializationContext serialization_context_;
        bool* result_;
        bool* out_valid_;
        DatabaseError* out_status_;
        base::Optional<std::vector<uint8_t>>* out_key_;
        base::Optional<std::vector<uint8_t>>* out_value_;
        DISALLOW_COPY_AND_ASSIGN(LevelDBDatabase_IteratorSeekToFirst_HandleSyncResponse);
    };
    bool LevelDBDatabase_IteratorSeekToFirst_HandleSyncResponse::Accept(
        mojo::Message* message)
    {
        internal::LevelDBDatabase_IteratorSeekToFirst_ResponseParams_Data* params = reinterpret_cast<internal::LevelDBDatabase_IteratorSeekToFirst_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        bool p_valid {};
        DatabaseError p_status {};
        base::Optional<std::vector<uint8_t>> p_key {};
        base::Optional<std::vector<uint8_t>> p_value {};
        LevelDBDatabase_IteratorSeekToFirst_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_valid = input_data_view.valid();
        if (!input_data_view.ReadStatus(&p_status))
            success = false;
        if (!input_data_view.ReadKey(&p_key))
            success = false;
        if (!input_data_view.ReadValue(&p_value))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "LevelDBDatabase::IteratorSeekToFirst response deserializer");
            return false;
        }
        *out_valid_ = std::move(p_valid);
        *out_status_ = std::move(p_status);
        *out_key_ = std::move(p_key);
        *out_value_ = std::move(p_value);
        mojo::internal::SyncMessageResponseSetup::SetCurrentSyncResponseMessage(
            message);
        *result_ = true;
        return true;
    }

    class LevelDBDatabase_IteratorSeekToFirst_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        LevelDBDatabase_IteratorSeekToFirst_ForwardToCallback(
            const LevelDBDatabase::IteratorSeekToFirstCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        LevelDBDatabase::IteratorSeekToFirstCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(LevelDBDatabase_IteratorSeekToFirst_ForwardToCallback);
    };
    bool LevelDBDatabase_IteratorSeekToFirst_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::LevelDBDatabase_IteratorSeekToFirst_ResponseParams_Data* params = reinterpret_cast<internal::LevelDBDatabase_IteratorSeekToFirst_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        bool p_valid {};
        DatabaseError p_status {};
        base::Optional<std::vector<uint8_t>> p_key {};
        base::Optional<std::vector<uint8_t>> p_value {};
        LevelDBDatabase_IteratorSeekToFirst_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_valid = input_data_view.valid();
        if (!input_data_view.ReadStatus(&p_status))
            success = false;
        if (!input_data_view.ReadKey(&p_key))
            success = false;
        if (!input_data_view.ReadValue(&p_value))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "LevelDBDatabase::IteratorSeekToFirst response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_valid),
                std::move(p_status),
                std::move(p_key),
                std::move(p_value));
        }
        return true;
    }
    class LevelDBDatabase_IteratorSeekToLast_HandleSyncResponse
        : public mojo::MessageReceiver {
    public:
        LevelDBDatabase_IteratorSeekToLast_HandleSyncResponse(
            scoped_refptr<mojo::AssociatedGroupController> group_controller,
            bool* result, bool* out_valid, DatabaseError* out_status, base::Optional<std::vector<uint8_t>>* out_key, base::Optional<std::vector<uint8_t>>* out_value)
            : serialization_context_(std::move(group_controller))
            , result_(result)
            , out_valid_(out_valid)
            , out_status_(out_status)
            , out_key_(out_key)
            , out_value_(out_value)
        {
            DCHECK(!*result_);
        }
        bool Accept(mojo::Message* message) override;

    private:
        mojo::internal::SerializationContext serialization_context_;
        bool* result_;
        bool* out_valid_;
        DatabaseError* out_status_;
        base::Optional<std::vector<uint8_t>>* out_key_;
        base::Optional<std::vector<uint8_t>>* out_value_;
        DISALLOW_COPY_AND_ASSIGN(LevelDBDatabase_IteratorSeekToLast_HandleSyncResponse);
    };
    bool LevelDBDatabase_IteratorSeekToLast_HandleSyncResponse::Accept(
        mojo::Message* message)
    {
        internal::LevelDBDatabase_IteratorSeekToLast_ResponseParams_Data* params = reinterpret_cast<internal::LevelDBDatabase_IteratorSeekToLast_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        bool p_valid {};
        DatabaseError p_status {};
        base::Optional<std::vector<uint8_t>> p_key {};
        base::Optional<std::vector<uint8_t>> p_value {};
        LevelDBDatabase_IteratorSeekToLast_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_valid = input_data_view.valid();
        if (!input_data_view.ReadStatus(&p_status))
            success = false;
        if (!input_data_view.ReadKey(&p_key))
            success = false;
        if (!input_data_view.ReadValue(&p_value))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "LevelDBDatabase::IteratorSeekToLast response deserializer");
            return false;
        }
        *out_valid_ = std::move(p_valid);
        *out_status_ = std::move(p_status);
        *out_key_ = std::move(p_key);
        *out_value_ = std::move(p_value);
        mojo::internal::SyncMessageResponseSetup::SetCurrentSyncResponseMessage(
            message);
        *result_ = true;
        return true;
    }

    class LevelDBDatabase_IteratorSeekToLast_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        LevelDBDatabase_IteratorSeekToLast_ForwardToCallback(
            const LevelDBDatabase::IteratorSeekToLastCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        LevelDBDatabase::IteratorSeekToLastCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(LevelDBDatabase_IteratorSeekToLast_ForwardToCallback);
    };
    bool LevelDBDatabase_IteratorSeekToLast_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::LevelDBDatabase_IteratorSeekToLast_ResponseParams_Data* params = reinterpret_cast<internal::LevelDBDatabase_IteratorSeekToLast_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        bool p_valid {};
        DatabaseError p_status {};
        base::Optional<std::vector<uint8_t>> p_key {};
        base::Optional<std::vector<uint8_t>> p_value {};
        LevelDBDatabase_IteratorSeekToLast_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_valid = input_data_view.valid();
        if (!input_data_view.ReadStatus(&p_status))
            success = false;
        if (!input_data_view.ReadKey(&p_key))
            success = false;
        if (!input_data_view.ReadValue(&p_value))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "LevelDBDatabase::IteratorSeekToLast response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_valid),
                std::move(p_status),
                std::move(p_key),
                std::move(p_value));
        }
        return true;
    }
    class LevelDBDatabase_IteratorSeek_HandleSyncResponse
        : public mojo::MessageReceiver {
    public:
        LevelDBDatabase_IteratorSeek_HandleSyncResponse(
            scoped_refptr<mojo::AssociatedGroupController> group_controller,
            bool* result, bool* out_valid, DatabaseError* out_status, base::Optional<std::vector<uint8_t>>* out_key, base::Optional<std::vector<uint8_t>>* out_value)
            : serialization_context_(std::move(group_controller))
            , result_(result)
            , out_valid_(out_valid)
            , out_status_(out_status)
            , out_key_(out_key)
            , out_value_(out_value)
        {
            DCHECK(!*result_);
        }
        bool Accept(mojo::Message* message) override;

    private:
        mojo::internal::SerializationContext serialization_context_;
        bool* result_;
        bool* out_valid_;
        DatabaseError* out_status_;
        base::Optional<std::vector<uint8_t>>* out_key_;
        base::Optional<std::vector<uint8_t>>* out_value_;
        DISALLOW_COPY_AND_ASSIGN(LevelDBDatabase_IteratorSeek_HandleSyncResponse);
    };
    bool LevelDBDatabase_IteratorSeek_HandleSyncResponse::Accept(
        mojo::Message* message)
    {
        internal::LevelDBDatabase_IteratorSeek_ResponseParams_Data* params = reinterpret_cast<internal::LevelDBDatabase_IteratorSeek_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        bool p_valid {};
        DatabaseError p_status {};
        base::Optional<std::vector<uint8_t>> p_key {};
        base::Optional<std::vector<uint8_t>> p_value {};
        LevelDBDatabase_IteratorSeek_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_valid = input_data_view.valid();
        if (!input_data_view.ReadStatus(&p_status))
            success = false;
        if (!input_data_view.ReadKey(&p_key))
            success = false;
        if (!input_data_view.ReadValue(&p_value))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "LevelDBDatabase::IteratorSeek response deserializer");
            return false;
        }
        *out_valid_ = std::move(p_valid);
        *out_status_ = std::move(p_status);
        *out_key_ = std::move(p_key);
        *out_value_ = std::move(p_value);
        mojo::internal::SyncMessageResponseSetup::SetCurrentSyncResponseMessage(
            message);
        *result_ = true;
        return true;
    }

    class LevelDBDatabase_IteratorSeek_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        LevelDBDatabase_IteratorSeek_ForwardToCallback(
            const LevelDBDatabase::IteratorSeekCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        LevelDBDatabase::IteratorSeekCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(LevelDBDatabase_IteratorSeek_ForwardToCallback);
    };
    bool LevelDBDatabase_IteratorSeek_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::LevelDBDatabase_IteratorSeek_ResponseParams_Data* params = reinterpret_cast<internal::LevelDBDatabase_IteratorSeek_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        bool p_valid {};
        DatabaseError p_status {};
        base::Optional<std::vector<uint8_t>> p_key {};
        base::Optional<std::vector<uint8_t>> p_value {};
        LevelDBDatabase_IteratorSeek_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_valid = input_data_view.valid();
        if (!input_data_view.ReadStatus(&p_status))
            success = false;
        if (!input_data_view.ReadKey(&p_key))
            success = false;
        if (!input_data_view.ReadValue(&p_value))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "LevelDBDatabase::IteratorSeek response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_valid),
                std::move(p_status),
                std::move(p_key),
                std::move(p_value));
        }
        return true;
    }
    class LevelDBDatabase_IteratorNext_HandleSyncResponse
        : public mojo::MessageReceiver {
    public:
        LevelDBDatabase_IteratorNext_HandleSyncResponse(
            scoped_refptr<mojo::AssociatedGroupController> group_controller,
            bool* result, bool* out_valid, DatabaseError* out_status, base::Optional<std::vector<uint8_t>>* out_key, base::Optional<std::vector<uint8_t>>* out_value)
            : serialization_context_(std::move(group_controller))
            , result_(result)
            , out_valid_(out_valid)
            , out_status_(out_status)
            , out_key_(out_key)
            , out_value_(out_value)
        {
            DCHECK(!*result_);
        }
        bool Accept(mojo::Message* message) override;

    private:
        mojo::internal::SerializationContext serialization_context_;
        bool* result_;
        bool* out_valid_;
        DatabaseError* out_status_;
        base::Optional<std::vector<uint8_t>>* out_key_;
        base::Optional<std::vector<uint8_t>>* out_value_;
        DISALLOW_COPY_AND_ASSIGN(LevelDBDatabase_IteratorNext_HandleSyncResponse);
    };
    bool LevelDBDatabase_IteratorNext_HandleSyncResponse::Accept(
        mojo::Message* message)
    {
        internal::LevelDBDatabase_IteratorNext_ResponseParams_Data* params = reinterpret_cast<internal::LevelDBDatabase_IteratorNext_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        bool p_valid {};
        DatabaseError p_status {};
        base::Optional<std::vector<uint8_t>> p_key {};
        base::Optional<std::vector<uint8_t>> p_value {};
        LevelDBDatabase_IteratorNext_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_valid = input_data_view.valid();
        if (!input_data_view.ReadStatus(&p_status))
            success = false;
        if (!input_data_view.ReadKey(&p_key))
            success = false;
        if (!input_data_view.ReadValue(&p_value))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "LevelDBDatabase::IteratorNext response deserializer");
            return false;
        }
        *out_valid_ = std::move(p_valid);
        *out_status_ = std::move(p_status);
        *out_key_ = std::move(p_key);
        *out_value_ = std::move(p_value);
        mojo::internal::SyncMessageResponseSetup::SetCurrentSyncResponseMessage(
            message);
        *result_ = true;
        return true;
    }

    class LevelDBDatabase_IteratorNext_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        LevelDBDatabase_IteratorNext_ForwardToCallback(
            const LevelDBDatabase::IteratorNextCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        LevelDBDatabase::IteratorNextCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(LevelDBDatabase_IteratorNext_ForwardToCallback);
    };
    bool LevelDBDatabase_IteratorNext_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::LevelDBDatabase_IteratorNext_ResponseParams_Data* params = reinterpret_cast<internal::LevelDBDatabase_IteratorNext_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        bool p_valid {};
        DatabaseError p_status {};
        base::Optional<std::vector<uint8_t>> p_key {};
        base::Optional<std::vector<uint8_t>> p_value {};
        LevelDBDatabase_IteratorNext_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_valid = input_data_view.valid();
        if (!input_data_view.ReadStatus(&p_status))
            success = false;
        if (!input_data_view.ReadKey(&p_key))
            success = false;
        if (!input_data_view.ReadValue(&p_value))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "LevelDBDatabase::IteratorNext response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_valid),
                std::move(p_status),
                std::move(p_key),
                std::move(p_value));
        }
        return true;
    }
    class LevelDBDatabase_IteratorPrev_HandleSyncResponse
        : public mojo::MessageReceiver {
    public:
        LevelDBDatabase_IteratorPrev_HandleSyncResponse(
            scoped_refptr<mojo::AssociatedGroupController> group_controller,
            bool* result, bool* out_valid, DatabaseError* out_status, base::Optional<std::vector<uint8_t>>* out_key, base::Optional<std::vector<uint8_t>>* out_value)
            : serialization_context_(std::move(group_controller))
            , result_(result)
            , out_valid_(out_valid)
            , out_status_(out_status)
            , out_key_(out_key)
            , out_value_(out_value)
        {
            DCHECK(!*result_);
        }
        bool Accept(mojo::Message* message) override;

    private:
        mojo::internal::SerializationContext serialization_context_;
        bool* result_;
        bool* out_valid_;
        DatabaseError* out_status_;
        base::Optional<std::vector<uint8_t>>* out_key_;
        base::Optional<std::vector<uint8_t>>* out_value_;
        DISALLOW_COPY_AND_ASSIGN(LevelDBDatabase_IteratorPrev_HandleSyncResponse);
    };
    bool LevelDBDatabase_IteratorPrev_HandleSyncResponse::Accept(
        mojo::Message* message)
    {
        internal::LevelDBDatabase_IteratorPrev_ResponseParams_Data* params = reinterpret_cast<internal::LevelDBDatabase_IteratorPrev_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        bool p_valid {};
        DatabaseError p_status {};
        base::Optional<std::vector<uint8_t>> p_key {};
        base::Optional<std::vector<uint8_t>> p_value {};
        LevelDBDatabase_IteratorPrev_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_valid = input_data_view.valid();
        if (!input_data_view.ReadStatus(&p_status))
            success = false;
        if (!input_data_view.ReadKey(&p_key))
            success = false;
        if (!input_data_view.ReadValue(&p_value))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "LevelDBDatabase::IteratorPrev response deserializer");
            return false;
        }
        *out_valid_ = std::move(p_valid);
        *out_status_ = std::move(p_status);
        *out_key_ = std::move(p_key);
        *out_value_ = std::move(p_value);
        mojo::internal::SyncMessageResponseSetup::SetCurrentSyncResponseMessage(
            message);
        *result_ = true;
        return true;
    }

    class LevelDBDatabase_IteratorPrev_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        LevelDBDatabase_IteratorPrev_ForwardToCallback(
            const LevelDBDatabase::IteratorPrevCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        LevelDBDatabase::IteratorPrevCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(LevelDBDatabase_IteratorPrev_ForwardToCallback);
    };
    bool LevelDBDatabase_IteratorPrev_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::LevelDBDatabase_IteratorPrev_ResponseParams_Data* params = reinterpret_cast<internal::LevelDBDatabase_IteratorPrev_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        bool p_valid {};
        DatabaseError p_status {};
        base::Optional<std::vector<uint8_t>> p_key {};
        base::Optional<std::vector<uint8_t>> p_value {};
        LevelDBDatabase_IteratorPrev_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        p_valid = input_data_view.valid();
        if (!input_data_view.ReadStatus(&p_status))
            success = false;
        if (!input_data_view.ReadKey(&p_key))
            success = false;
        if (!input_data_view.ReadValue(&p_value))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "LevelDBDatabase::IteratorPrev response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_valid),
                std::move(p_status),
                std::move(p_key),
                std::move(p_value));
        }
        return true;
    }

    LevelDBDatabaseProxy::LevelDBDatabaseProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }

    void LevelDBDatabaseProxy::Put(
        const std::vector<uint8_t>& in_key, const std::vector<uint8_t>& in_value, const PutCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBDatabase_Put_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_key, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_value, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kLevelDBDatabase_Put_Name, size);

        auto params = ::leveldb::mojom::internal::LevelDBDatabase_Put_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->key)::BaseType* key_ptr;
        const mojo::internal::ContainerValidateParams key_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_key, builder.buffer(), &key_ptr, &key_validate_params,
            &serialization_context);
        params->key.Set(key_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->key.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null key in LevelDBDatabase.Put request");
        typename decltype(params->value)::BaseType* value_ptr;
        const mojo::internal::ContainerValidateParams value_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_value, builder.buffer(), &value_ptr, &value_validate_params,
            &serialization_context);
        params->value.Set(value_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->value.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null value in LevelDBDatabase.Put request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new LevelDBDatabase_Put_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void LevelDBDatabaseProxy::Delete(
        const std::vector<uint8_t>& in_key, const DeleteCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBDatabase_Delete_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_key, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kLevelDBDatabase_Delete_Name, size);

        auto params = ::leveldb::mojom::internal::LevelDBDatabase_Delete_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->key)::BaseType* key_ptr;
        const mojo::internal::ContainerValidateParams key_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_key, builder.buffer(), &key_ptr, &key_validate_params,
            &serialization_context);
        params->key.Set(key_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->key.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null key in LevelDBDatabase.Delete request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new LevelDBDatabase_Delete_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void LevelDBDatabaseProxy::DeletePrefixed(
        const std::vector<uint8_t>& in_key_prefix, const DeletePrefixedCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBDatabase_DeletePrefixed_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_key_prefix, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kLevelDBDatabase_DeletePrefixed_Name, size);

        auto params = ::leveldb::mojom::internal::LevelDBDatabase_DeletePrefixed_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->key_prefix)::BaseType* key_prefix_ptr;
        const mojo::internal::ContainerValidateParams key_prefix_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_key_prefix, builder.buffer(), &key_prefix_ptr, &key_prefix_validate_params,
            &serialization_context);
        params->key_prefix.Set(key_prefix_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->key_prefix.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null key_prefix in LevelDBDatabase.DeletePrefixed request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new LevelDBDatabase_DeletePrefixed_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void LevelDBDatabaseProxy::Write(
        std::vector<BatchedOperationPtr> in_operations, const WriteCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBDatabase_Write_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::leveldb::mojom::BatchedOperationDataView>>(
            in_operations, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kLevelDBDatabase_Write_Name, size);

        auto params = ::leveldb::mojom::internal::LevelDBDatabase_Write_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->operations)::BaseType* operations_ptr;
        const mojo::internal::ContainerValidateParams operations_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::leveldb::mojom::BatchedOperationDataView>>(
            in_operations, builder.buffer(), &operations_ptr, &operations_validate_params,
            &serialization_context);
        params->operations.Set(operations_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->operations.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null operations in LevelDBDatabase.Write request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new LevelDBDatabase_Write_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void LevelDBDatabaseProxy::Get(
        const std::vector<uint8_t>& in_key, const GetCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBDatabase_Get_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_key, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kLevelDBDatabase_Get_Name, size);

        auto params = ::leveldb::mojom::internal::LevelDBDatabase_Get_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->key)::BaseType* key_ptr;
        const mojo::internal::ContainerValidateParams key_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_key, builder.buffer(), &key_ptr, &key_validate_params,
            &serialization_context);
        params->key.Set(key_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->key.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null key in LevelDBDatabase.Get request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new LevelDBDatabase_Get_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void LevelDBDatabaseProxy::GetPrefixed(
        const std::vector<uint8_t>& in_key_prefix, const GetPrefixedCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBDatabase_GetPrefixed_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_key_prefix, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kLevelDBDatabase_GetPrefixed_Name, size);

        auto params = ::leveldb::mojom::internal::LevelDBDatabase_GetPrefixed_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->key_prefix)::BaseType* key_prefix_ptr;
        const mojo::internal::ContainerValidateParams key_prefix_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_key_prefix, builder.buffer(), &key_prefix_ptr, &key_prefix_validate_params,
            &serialization_context);
        params->key_prefix.Set(key_prefix_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->key_prefix.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null key_prefix in LevelDBDatabase.GetPrefixed request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new LevelDBDatabase_GetPrefixed_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void LevelDBDatabaseProxy::GetSnapshot(
        const GetSnapshotCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBDatabase_GetSnapshot_Params_Data);
        mojo::internal::RequestMessageBuilder builder(internal::kLevelDBDatabase_GetSnapshot_Name, size);

        auto params = ::leveldb::mojom::internal::LevelDBDatabase_GetSnapshot_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new LevelDBDatabase_GetSnapshot_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void LevelDBDatabaseProxy::ReleaseSnapshot(
        const base::UnguessableToken& in_snapshot)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBDatabase_ReleaseSnapshot_Params_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::UnguessableTokenDataView>(
            in_snapshot, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kLevelDBDatabase_ReleaseSnapshot_Name, size);

        auto params = ::leveldb::mojom::internal::LevelDBDatabase_ReleaseSnapshot_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->snapshot)::BaseType* snapshot_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::UnguessableTokenDataView>(
            in_snapshot, builder.buffer(), &snapshot_ptr, &serialization_context);
        params->snapshot.Set(snapshot_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->snapshot.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null snapshot in LevelDBDatabase.ReleaseSnapshot request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }

    void LevelDBDatabaseProxy::GetFromSnapshot(
        const base::UnguessableToken& in_snapshot, const std::vector<uint8_t>& in_key, const GetFromSnapshotCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBDatabase_GetFromSnapshot_Params_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::UnguessableTokenDataView>(
            in_snapshot, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_key, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kLevelDBDatabase_GetFromSnapshot_Name, size);

        auto params = ::leveldb::mojom::internal::LevelDBDatabase_GetFromSnapshot_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->snapshot)::BaseType* snapshot_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::UnguessableTokenDataView>(
            in_snapshot, builder.buffer(), &snapshot_ptr, &serialization_context);
        params->snapshot.Set(snapshot_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->snapshot.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null snapshot in LevelDBDatabase.GetFromSnapshot request");
        typename decltype(params->key)::BaseType* key_ptr;
        const mojo::internal::ContainerValidateParams key_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_key, builder.buffer(), &key_ptr, &key_validate_params,
            &serialization_context);
        params->key.Set(key_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->key.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null key in LevelDBDatabase.GetFromSnapshot request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new LevelDBDatabase_GetFromSnapshot_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void LevelDBDatabaseProxy::NewIterator(
        const NewIteratorCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBDatabase_NewIterator_Params_Data);
        mojo::internal::RequestMessageBuilder builder(internal::kLevelDBDatabase_NewIterator_Name, size);

        auto params = ::leveldb::mojom::internal::LevelDBDatabase_NewIterator_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new LevelDBDatabase_NewIterator_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void LevelDBDatabaseProxy::NewIteratorFromSnapshot(
        const base::UnguessableToken& in_snapshot, const NewIteratorFromSnapshotCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBDatabase_NewIteratorFromSnapshot_Params_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::UnguessableTokenDataView>(
            in_snapshot, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kLevelDBDatabase_NewIteratorFromSnapshot_Name, size);

        auto params = ::leveldb::mojom::internal::LevelDBDatabase_NewIteratorFromSnapshot_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->snapshot)::BaseType* snapshot_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::UnguessableTokenDataView>(
            in_snapshot, builder.buffer(), &snapshot_ptr, &serialization_context);
        params->snapshot.Set(snapshot_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->snapshot.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null snapshot in LevelDBDatabase.NewIteratorFromSnapshot request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new LevelDBDatabase_NewIteratorFromSnapshot_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void LevelDBDatabaseProxy::ReleaseIterator(
        const base::UnguessableToken& in_iterator)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBDatabase_ReleaseIterator_Params_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::UnguessableTokenDataView>(
            in_iterator, &serialization_context);
        mojo::internal::MessageBuilder builder(internal::kLevelDBDatabase_ReleaseIterator_Name, size);

        auto params = ::leveldb::mojom::internal::LevelDBDatabase_ReleaseIterator_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->iterator)::BaseType* iterator_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::UnguessableTokenDataView>(
            in_iterator, builder.buffer(), &iterator_ptr, &serialization_context);
        params->iterator.Set(iterator_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->iterator.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null iterator in LevelDBDatabase.ReleaseIterator request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }
    bool LevelDBDatabaseProxy::IteratorSeekToFirst(
        const base::UnguessableToken& param_iterator, bool* param_valid, DatabaseError* param_status, base::Optional<std::vector<uint8_t>>* param_key, base::Optional<std::vector<uint8_t>>* param_value)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBDatabase_IteratorSeekToFirst_Params_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::UnguessableTokenDataView>(
            param_iterator, &serialization_context);

        mojo::internal::RequestMessageBuilder builder(internal::kLevelDBDatabase_IteratorSeekToFirst_Name, size,
            mojo::Message::kFlagIsSync);

        auto params = ::leveldb::mojom::internal::LevelDBDatabase_IteratorSeekToFirst_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->iterator)::BaseType* iterator_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::UnguessableTokenDataView>(
            param_iterator, builder.buffer(), &iterator_ptr, &serialization_context);
        params->iterator.Set(iterator_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->iterator.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null iterator in LevelDBDatabase.IteratorSeekToFirst request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());

        bool result = false;
        mojo::MessageReceiver* responder = new LevelDBDatabase_IteratorSeekToFirst_HandleSyncResponse(
            group_controller_, &result, param_valid, param_status, param_key, param_value);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
        return result;
    }

    void LevelDBDatabaseProxy::IteratorSeekToFirst(
        const base::UnguessableToken& in_iterator, const IteratorSeekToFirstCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBDatabase_IteratorSeekToFirst_Params_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::UnguessableTokenDataView>(
            in_iterator, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kLevelDBDatabase_IteratorSeekToFirst_Name, size);

        auto params = ::leveldb::mojom::internal::LevelDBDatabase_IteratorSeekToFirst_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->iterator)::BaseType* iterator_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::UnguessableTokenDataView>(
            in_iterator, builder.buffer(), &iterator_ptr, &serialization_context);
        params->iterator.Set(iterator_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->iterator.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null iterator in LevelDBDatabase.IteratorSeekToFirst request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new LevelDBDatabase_IteratorSeekToFirst_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    bool LevelDBDatabaseProxy::IteratorSeekToLast(
        const base::UnguessableToken& param_iterator, bool* param_valid, DatabaseError* param_status, base::Optional<std::vector<uint8_t>>* param_key, base::Optional<std::vector<uint8_t>>* param_value)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBDatabase_IteratorSeekToLast_Params_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::UnguessableTokenDataView>(
            param_iterator, &serialization_context);

        mojo::internal::RequestMessageBuilder builder(internal::kLevelDBDatabase_IteratorSeekToLast_Name, size,
            mojo::Message::kFlagIsSync);

        auto params = ::leveldb::mojom::internal::LevelDBDatabase_IteratorSeekToLast_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->iterator)::BaseType* iterator_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::UnguessableTokenDataView>(
            param_iterator, builder.buffer(), &iterator_ptr, &serialization_context);
        params->iterator.Set(iterator_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->iterator.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null iterator in LevelDBDatabase.IteratorSeekToLast request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());

        bool result = false;
        mojo::MessageReceiver* responder = new LevelDBDatabase_IteratorSeekToLast_HandleSyncResponse(
            group_controller_, &result, param_valid, param_status, param_key, param_value);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
        return result;
    }

    void LevelDBDatabaseProxy::IteratorSeekToLast(
        const base::UnguessableToken& in_iterator, const IteratorSeekToLastCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBDatabase_IteratorSeekToLast_Params_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::UnguessableTokenDataView>(
            in_iterator, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kLevelDBDatabase_IteratorSeekToLast_Name, size);

        auto params = ::leveldb::mojom::internal::LevelDBDatabase_IteratorSeekToLast_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->iterator)::BaseType* iterator_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::UnguessableTokenDataView>(
            in_iterator, builder.buffer(), &iterator_ptr, &serialization_context);
        params->iterator.Set(iterator_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->iterator.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null iterator in LevelDBDatabase.IteratorSeekToLast request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new LevelDBDatabase_IteratorSeekToLast_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    bool LevelDBDatabaseProxy::IteratorSeek(
        const base::UnguessableToken& param_iterator, const std::vector<uint8_t>& param_target, bool* param_valid, DatabaseError* param_status, base::Optional<std::vector<uint8_t>>* param_key, base::Optional<std::vector<uint8_t>>* param_value)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBDatabase_IteratorSeek_Params_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::UnguessableTokenDataView>(
            param_iterator, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            param_target, &serialization_context);

        mojo::internal::RequestMessageBuilder builder(internal::kLevelDBDatabase_IteratorSeek_Name, size,
            mojo::Message::kFlagIsSync);

        auto params = ::leveldb::mojom::internal::LevelDBDatabase_IteratorSeek_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->iterator)::BaseType* iterator_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::UnguessableTokenDataView>(
            param_iterator, builder.buffer(), &iterator_ptr, &serialization_context);
        params->iterator.Set(iterator_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->iterator.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null iterator in LevelDBDatabase.IteratorSeek request");
        typename decltype(params->target)::BaseType* target_ptr;
        const mojo::internal::ContainerValidateParams target_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            param_target, builder.buffer(), &target_ptr, &target_validate_params,
            &serialization_context);
        params->target.Set(target_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->target.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null target in LevelDBDatabase.IteratorSeek request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());

        bool result = false;
        mojo::MessageReceiver* responder = new LevelDBDatabase_IteratorSeek_HandleSyncResponse(
            group_controller_, &result, param_valid, param_status, param_key, param_value);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
        return result;
    }

    void LevelDBDatabaseProxy::IteratorSeek(
        const base::UnguessableToken& in_iterator, const std::vector<uint8_t>& in_target, const IteratorSeekCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBDatabase_IteratorSeek_Params_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::UnguessableTokenDataView>(
            in_iterator, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_target, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kLevelDBDatabase_IteratorSeek_Name, size);

        auto params = ::leveldb::mojom::internal::LevelDBDatabase_IteratorSeek_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->iterator)::BaseType* iterator_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::UnguessableTokenDataView>(
            in_iterator, builder.buffer(), &iterator_ptr, &serialization_context);
        params->iterator.Set(iterator_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->iterator.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null iterator in LevelDBDatabase.IteratorSeek request");
        typename decltype(params->target)::BaseType* target_ptr;
        const mojo::internal::ContainerValidateParams target_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_target, builder.buffer(), &target_ptr, &target_validate_params,
            &serialization_context);
        params->target.Set(target_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->target.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null target in LevelDBDatabase.IteratorSeek request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new LevelDBDatabase_IteratorSeek_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    bool LevelDBDatabaseProxy::IteratorNext(
        const base::UnguessableToken& param_iterator, bool* param_valid, DatabaseError* param_status, base::Optional<std::vector<uint8_t>>* param_key, base::Optional<std::vector<uint8_t>>* param_value)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBDatabase_IteratorNext_Params_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::UnguessableTokenDataView>(
            param_iterator, &serialization_context);

        mojo::internal::RequestMessageBuilder builder(internal::kLevelDBDatabase_IteratorNext_Name, size,
            mojo::Message::kFlagIsSync);

        auto params = ::leveldb::mojom::internal::LevelDBDatabase_IteratorNext_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->iterator)::BaseType* iterator_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::UnguessableTokenDataView>(
            param_iterator, builder.buffer(), &iterator_ptr, &serialization_context);
        params->iterator.Set(iterator_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->iterator.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null iterator in LevelDBDatabase.IteratorNext request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());

        bool result = false;
        mojo::MessageReceiver* responder = new LevelDBDatabase_IteratorNext_HandleSyncResponse(
            group_controller_, &result, param_valid, param_status, param_key, param_value);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
        return result;
    }

    void LevelDBDatabaseProxy::IteratorNext(
        const base::UnguessableToken& in_iterator, const IteratorNextCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBDatabase_IteratorNext_Params_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::UnguessableTokenDataView>(
            in_iterator, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kLevelDBDatabase_IteratorNext_Name, size);

        auto params = ::leveldb::mojom::internal::LevelDBDatabase_IteratorNext_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->iterator)::BaseType* iterator_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::UnguessableTokenDataView>(
            in_iterator, builder.buffer(), &iterator_ptr, &serialization_context);
        params->iterator.Set(iterator_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->iterator.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null iterator in LevelDBDatabase.IteratorNext request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new LevelDBDatabase_IteratorNext_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    bool LevelDBDatabaseProxy::IteratorPrev(
        const base::UnguessableToken& param_iterator, bool* param_valid, DatabaseError* param_status, base::Optional<std::vector<uint8_t>>* param_key, base::Optional<std::vector<uint8_t>>* param_value)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBDatabase_IteratorPrev_Params_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::UnguessableTokenDataView>(
            param_iterator, &serialization_context);

        mojo::internal::RequestMessageBuilder builder(internal::kLevelDBDatabase_IteratorPrev_Name, size,
            mojo::Message::kFlagIsSync);

        auto params = ::leveldb::mojom::internal::LevelDBDatabase_IteratorPrev_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->iterator)::BaseType* iterator_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::UnguessableTokenDataView>(
            param_iterator, builder.buffer(), &iterator_ptr, &serialization_context);
        params->iterator.Set(iterator_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->iterator.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null iterator in LevelDBDatabase.IteratorPrev request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());

        bool result = false;
        mojo::MessageReceiver* responder = new LevelDBDatabase_IteratorPrev_HandleSyncResponse(
            group_controller_, &result, param_valid, param_status, param_key, param_value);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
        return result;
    }

    void LevelDBDatabaseProxy::IteratorPrev(
        const base::UnguessableToken& in_iterator, const IteratorPrevCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBDatabase_IteratorPrev_Params_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::UnguessableTokenDataView>(
            in_iterator, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kLevelDBDatabase_IteratorPrev_Name, size);

        auto params = ::leveldb::mojom::internal::LevelDBDatabase_IteratorPrev_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->iterator)::BaseType* iterator_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::UnguessableTokenDataView>(
            in_iterator, builder.buffer(), &iterator_ptr, &serialization_context);
        params->iterator.Set(iterator_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->iterator.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null iterator in LevelDBDatabase.IteratorPrev request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new LevelDBDatabase_IteratorPrev_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    class LevelDBDatabase_Put_ProxyToResponder {
    public:
        static LevelDBDatabase::PutCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<LevelDBDatabase_Put_ProxyToResponder> proxy(
                new LevelDBDatabase_Put_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&LevelDBDatabase_Put_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~LevelDBDatabase_Put_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "LevelDBDatabase::Put() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        LevelDBDatabase_Put_ProxyToResponder(
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
            DatabaseError in_status);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(LevelDBDatabase_Put_ProxyToResponder);
    };

    void LevelDBDatabase_Put_ProxyToResponder::Run(
        DatabaseError in_status)
    {
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBDatabase_Put_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kLevelDBDatabase_Put_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::leveldb::mojom::internal::LevelDBDatabase_Put_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::leveldb::mojom::DatabaseError>(
            in_status, &params->status);
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class LevelDBDatabase_Delete_ProxyToResponder {
    public:
        static LevelDBDatabase::DeleteCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<LevelDBDatabase_Delete_ProxyToResponder> proxy(
                new LevelDBDatabase_Delete_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&LevelDBDatabase_Delete_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~LevelDBDatabase_Delete_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "LevelDBDatabase::Delete() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        LevelDBDatabase_Delete_ProxyToResponder(
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
            DatabaseError in_status);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(LevelDBDatabase_Delete_ProxyToResponder);
    };

    void LevelDBDatabase_Delete_ProxyToResponder::Run(
        DatabaseError in_status)
    {
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBDatabase_Delete_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kLevelDBDatabase_Delete_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::leveldb::mojom::internal::LevelDBDatabase_Delete_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::leveldb::mojom::DatabaseError>(
            in_status, &params->status);
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class LevelDBDatabase_DeletePrefixed_ProxyToResponder {
    public:
        static LevelDBDatabase::DeletePrefixedCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<LevelDBDatabase_DeletePrefixed_ProxyToResponder> proxy(
                new LevelDBDatabase_DeletePrefixed_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&LevelDBDatabase_DeletePrefixed_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~LevelDBDatabase_DeletePrefixed_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "LevelDBDatabase::DeletePrefixed() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        LevelDBDatabase_DeletePrefixed_ProxyToResponder(
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
            DatabaseError in_status);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(LevelDBDatabase_DeletePrefixed_ProxyToResponder);
    };

    void LevelDBDatabase_DeletePrefixed_ProxyToResponder::Run(
        DatabaseError in_status)
    {
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBDatabase_DeletePrefixed_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kLevelDBDatabase_DeletePrefixed_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::leveldb::mojom::internal::LevelDBDatabase_DeletePrefixed_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::leveldb::mojom::DatabaseError>(
            in_status, &params->status);
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class LevelDBDatabase_Write_ProxyToResponder {
    public:
        static LevelDBDatabase::WriteCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<LevelDBDatabase_Write_ProxyToResponder> proxy(
                new LevelDBDatabase_Write_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&LevelDBDatabase_Write_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~LevelDBDatabase_Write_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "LevelDBDatabase::Write() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        LevelDBDatabase_Write_ProxyToResponder(
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
            DatabaseError in_status);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(LevelDBDatabase_Write_ProxyToResponder);
    };

    void LevelDBDatabase_Write_ProxyToResponder::Run(
        DatabaseError in_status)
    {
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBDatabase_Write_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kLevelDBDatabase_Write_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::leveldb::mojom::internal::LevelDBDatabase_Write_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::leveldb::mojom::DatabaseError>(
            in_status, &params->status);
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class LevelDBDatabase_Get_ProxyToResponder {
    public:
        static LevelDBDatabase::GetCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<LevelDBDatabase_Get_ProxyToResponder> proxy(
                new LevelDBDatabase_Get_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&LevelDBDatabase_Get_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~LevelDBDatabase_Get_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "LevelDBDatabase::Get() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        LevelDBDatabase_Get_ProxyToResponder(
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
            DatabaseError in_status, const std::vector<uint8_t>& in_value);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(LevelDBDatabase_Get_ProxyToResponder);
    };

    void LevelDBDatabase_Get_ProxyToResponder::Run(
        DatabaseError in_status, const std::vector<uint8_t>& in_value)
    {
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBDatabase_Get_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_value, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kLevelDBDatabase_Get_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::leveldb::mojom::internal::LevelDBDatabase_Get_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::leveldb::mojom::DatabaseError>(
            in_status, &params->status);
        typename decltype(params->value)::BaseType* value_ptr;
        const mojo::internal::ContainerValidateParams value_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_value, builder.buffer(), &value_ptr, &value_validate_params,
            &serialization_context_);
        params->value.Set(value_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->value.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null value in LevelDBDatabase.Get response");
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class LevelDBDatabase_GetPrefixed_ProxyToResponder {
    public:
        static LevelDBDatabase::GetPrefixedCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<LevelDBDatabase_GetPrefixed_ProxyToResponder> proxy(
                new LevelDBDatabase_GetPrefixed_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&LevelDBDatabase_GetPrefixed_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~LevelDBDatabase_GetPrefixed_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "LevelDBDatabase::GetPrefixed() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        LevelDBDatabase_GetPrefixed_ProxyToResponder(
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
            DatabaseError in_status, std::vector<KeyValuePtr> in_data);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(LevelDBDatabase_GetPrefixed_ProxyToResponder);
    };

    void LevelDBDatabase_GetPrefixed_ProxyToResponder::Run(
        DatabaseError in_status, std::vector<KeyValuePtr> in_data)
    {
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBDatabase_GetPrefixed_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::leveldb::mojom::KeyValueDataView>>(
            in_data, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kLevelDBDatabase_GetPrefixed_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::leveldb::mojom::internal::LevelDBDatabase_GetPrefixed_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::leveldb::mojom::DatabaseError>(
            in_status, &params->status);
        typename decltype(params->data)::BaseType* data_ptr;
        const mojo::internal::ContainerValidateParams data_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::leveldb::mojom::KeyValueDataView>>(
            in_data, builder.buffer(), &data_ptr, &data_validate_params,
            &serialization_context_);
        params->data.Set(data_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->data.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null data in LevelDBDatabase.GetPrefixed response");
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class LevelDBDatabase_GetSnapshot_ProxyToResponder {
    public:
        static LevelDBDatabase::GetSnapshotCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<LevelDBDatabase_GetSnapshot_ProxyToResponder> proxy(
                new LevelDBDatabase_GetSnapshot_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&LevelDBDatabase_GetSnapshot_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~LevelDBDatabase_GetSnapshot_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "LevelDBDatabase::GetSnapshot() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        LevelDBDatabase_GetSnapshot_ProxyToResponder(
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
            const base::UnguessableToken& in_snapshot);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(LevelDBDatabase_GetSnapshot_ProxyToResponder);
    };

    void LevelDBDatabase_GetSnapshot_ProxyToResponder::Run(
        const base::UnguessableToken& in_snapshot)
    {
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBDatabase_GetSnapshot_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::UnguessableTokenDataView>(
            in_snapshot, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kLevelDBDatabase_GetSnapshot_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::leveldb::mojom::internal::LevelDBDatabase_GetSnapshot_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->snapshot)::BaseType* snapshot_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::UnguessableTokenDataView>(
            in_snapshot, builder.buffer(), &snapshot_ptr, &serialization_context_);
        params->snapshot.Set(snapshot_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->snapshot.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null snapshot in LevelDBDatabase.GetSnapshot response");
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class LevelDBDatabase_GetFromSnapshot_ProxyToResponder {
    public:
        static LevelDBDatabase::GetFromSnapshotCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<LevelDBDatabase_GetFromSnapshot_ProxyToResponder> proxy(
                new LevelDBDatabase_GetFromSnapshot_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&LevelDBDatabase_GetFromSnapshot_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~LevelDBDatabase_GetFromSnapshot_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "LevelDBDatabase::GetFromSnapshot() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        LevelDBDatabase_GetFromSnapshot_ProxyToResponder(
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
            DatabaseError in_status, const std::vector<uint8_t>& in_value);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(LevelDBDatabase_GetFromSnapshot_ProxyToResponder);
    };

    void LevelDBDatabase_GetFromSnapshot_ProxyToResponder::Run(
        DatabaseError in_status, const std::vector<uint8_t>& in_value)
    {
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBDatabase_GetFromSnapshot_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_value, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kLevelDBDatabase_GetFromSnapshot_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::leveldb::mojom::internal::LevelDBDatabase_GetFromSnapshot_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::leveldb::mojom::DatabaseError>(
            in_status, &params->status);
        typename decltype(params->value)::BaseType* value_ptr;
        const mojo::internal::ContainerValidateParams value_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_value, builder.buffer(), &value_ptr, &value_validate_params,
            &serialization_context_);
        params->value.Set(value_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->value.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null value in LevelDBDatabase.GetFromSnapshot response");
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class LevelDBDatabase_NewIterator_ProxyToResponder {
    public:
        static LevelDBDatabase::NewIteratorCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<LevelDBDatabase_NewIterator_ProxyToResponder> proxy(
                new LevelDBDatabase_NewIterator_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&LevelDBDatabase_NewIterator_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~LevelDBDatabase_NewIterator_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "LevelDBDatabase::NewIterator() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        LevelDBDatabase_NewIterator_ProxyToResponder(
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
            const base::UnguessableToken& in_iterator);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(LevelDBDatabase_NewIterator_ProxyToResponder);
    };

    void LevelDBDatabase_NewIterator_ProxyToResponder::Run(
        const base::UnguessableToken& in_iterator)
    {
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBDatabase_NewIterator_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::UnguessableTokenDataView>(
            in_iterator, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kLevelDBDatabase_NewIterator_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::leveldb::mojom::internal::LevelDBDatabase_NewIterator_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->iterator)::BaseType* iterator_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::UnguessableTokenDataView>(
            in_iterator, builder.buffer(), &iterator_ptr, &serialization_context_);
        params->iterator.Set(iterator_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->iterator.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null iterator in LevelDBDatabase.NewIterator response");
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class LevelDBDatabase_NewIteratorFromSnapshot_ProxyToResponder {
    public:
        static LevelDBDatabase::NewIteratorFromSnapshotCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<LevelDBDatabase_NewIteratorFromSnapshot_ProxyToResponder> proxy(
                new LevelDBDatabase_NewIteratorFromSnapshot_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&LevelDBDatabase_NewIteratorFromSnapshot_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~LevelDBDatabase_NewIteratorFromSnapshot_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "LevelDBDatabase::NewIteratorFromSnapshot() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        LevelDBDatabase_NewIteratorFromSnapshot_ProxyToResponder(
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
            const base::Optional<base::UnguessableToken>& in_iterator);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(LevelDBDatabase_NewIteratorFromSnapshot_ProxyToResponder);
    };

    void LevelDBDatabase_NewIteratorFromSnapshot_ProxyToResponder::Run(
        const base::Optional<base::UnguessableToken>& in_iterator)
    {
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBDatabase_NewIteratorFromSnapshot_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::UnguessableTokenDataView>(
            in_iterator, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kLevelDBDatabase_NewIteratorFromSnapshot_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::leveldb::mojom::internal::LevelDBDatabase_NewIteratorFromSnapshot_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->iterator)::BaseType* iterator_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::UnguessableTokenDataView>(
            in_iterator, builder.buffer(), &iterator_ptr, &serialization_context_);
        params->iterator.Set(iterator_ptr);
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class LevelDBDatabase_IteratorSeekToFirst_ProxyToResponder {
    public:
        static LevelDBDatabase::IteratorSeekToFirstCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<LevelDBDatabase_IteratorSeekToFirst_ProxyToResponder> proxy(
                new LevelDBDatabase_IteratorSeekToFirst_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&LevelDBDatabase_IteratorSeekToFirst_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~LevelDBDatabase_IteratorSeekToFirst_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "LevelDBDatabase::IteratorSeekToFirst() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        LevelDBDatabase_IteratorSeekToFirst_ProxyToResponder(
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
            bool in_valid, DatabaseError in_status, const base::Optional<std::vector<uint8_t>>& in_key, const base::Optional<std::vector<uint8_t>>& in_value);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(LevelDBDatabase_IteratorSeekToFirst_ProxyToResponder);
    };

    void LevelDBDatabase_IteratorSeekToFirst_ProxyToResponder::Run(
        bool in_valid, DatabaseError in_status, const base::Optional<std::vector<uint8_t>>& in_key, const base::Optional<std::vector<uint8_t>>& in_value)
    {
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBDatabase_IteratorSeekToFirst_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_key, &serialization_context_);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_value, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kLevelDBDatabase_IteratorSeekToFirst_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::leveldb::mojom::internal::LevelDBDatabase_IteratorSeekToFirst_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->valid = in_valid;
        mojo::internal::Serialize<::leveldb::mojom::DatabaseError>(
            in_status, &params->status);
        typename decltype(params->key)::BaseType* key_ptr;
        const mojo::internal::ContainerValidateParams key_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_key, builder.buffer(), &key_ptr, &key_validate_params,
            &serialization_context_);
        params->key.Set(key_ptr);
        typename decltype(params->value)::BaseType* value_ptr;
        const mojo::internal::ContainerValidateParams value_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_value, builder.buffer(), &value_ptr, &value_validate_params,
            &serialization_context_);
        params->value.Set(value_ptr);
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class LevelDBDatabase_IteratorSeekToLast_ProxyToResponder {
    public:
        static LevelDBDatabase::IteratorSeekToLastCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<LevelDBDatabase_IteratorSeekToLast_ProxyToResponder> proxy(
                new LevelDBDatabase_IteratorSeekToLast_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&LevelDBDatabase_IteratorSeekToLast_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~LevelDBDatabase_IteratorSeekToLast_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "LevelDBDatabase::IteratorSeekToLast() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        LevelDBDatabase_IteratorSeekToLast_ProxyToResponder(
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
            bool in_valid, DatabaseError in_status, const base::Optional<std::vector<uint8_t>>& in_key, const base::Optional<std::vector<uint8_t>>& in_value);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(LevelDBDatabase_IteratorSeekToLast_ProxyToResponder);
    };

    void LevelDBDatabase_IteratorSeekToLast_ProxyToResponder::Run(
        bool in_valid, DatabaseError in_status, const base::Optional<std::vector<uint8_t>>& in_key, const base::Optional<std::vector<uint8_t>>& in_value)
    {
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBDatabase_IteratorSeekToLast_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_key, &serialization_context_);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_value, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kLevelDBDatabase_IteratorSeekToLast_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::leveldb::mojom::internal::LevelDBDatabase_IteratorSeekToLast_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->valid = in_valid;
        mojo::internal::Serialize<::leveldb::mojom::DatabaseError>(
            in_status, &params->status);
        typename decltype(params->key)::BaseType* key_ptr;
        const mojo::internal::ContainerValidateParams key_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_key, builder.buffer(), &key_ptr, &key_validate_params,
            &serialization_context_);
        params->key.Set(key_ptr);
        typename decltype(params->value)::BaseType* value_ptr;
        const mojo::internal::ContainerValidateParams value_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_value, builder.buffer(), &value_ptr, &value_validate_params,
            &serialization_context_);
        params->value.Set(value_ptr);
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class LevelDBDatabase_IteratorSeek_ProxyToResponder {
    public:
        static LevelDBDatabase::IteratorSeekCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<LevelDBDatabase_IteratorSeek_ProxyToResponder> proxy(
                new LevelDBDatabase_IteratorSeek_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&LevelDBDatabase_IteratorSeek_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~LevelDBDatabase_IteratorSeek_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "LevelDBDatabase::IteratorSeek() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        LevelDBDatabase_IteratorSeek_ProxyToResponder(
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
            bool in_valid, DatabaseError in_status, const base::Optional<std::vector<uint8_t>>& in_key, const base::Optional<std::vector<uint8_t>>& in_value);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(LevelDBDatabase_IteratorSeek_ProxyToResponder);
    };

    void LevelDBDatabase_IteratorSeek_ProxyToResponder::Run(
        bool in_valid, DatabaseError in_status, const base::Optional<std::vector<uint8_t>>& in_key, const base::Optional<std::vector<uint8_t>>& in_value)
    {
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBDatabase_IteratorSeek_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_key, &serialization_context_);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_value, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kLevelDBDatabase_IteratorSeek_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::leveldb::mojom::internal::LevelDBDatabase_IteratorSeek_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->valid = in_valid;
        mojo::internal::Serialize<::leveldb::mojom::DatabaseError>(
            in_status, &params->status);
        typename decltype(params->key)::BaseType* key_ptr;
        const mojo::internal::ContainerValidateParams key_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_key, builder.buffer(), &key_ptr, &key_validate_params,
            &serialization_context_);
        params->key.Set(key_ptr);
        typename decltype(params->value)::BaseType* value_ptr;
        const mojo::internal::ContainerValidateParams value_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_value, builder.buffer(), &value_ptr, &value_validate_params,
            &serialization_context_);
        params->value.Set(value_ptr);
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class LevelDBDatabase_IteratorNext_ProxyToResponder {
    public:
        static LevelDBDatabase::IteratorNextCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<LevelDBDatabase_IteratorNext_ProxyToResponder> proxy(
                new LevelDBDatabase_IteratorNext_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&LevelDBDatabase_IteratorNext_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~LevelDBDatabase_IteratorNext_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "LevelDBDatabase::IteratorNext() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        LevelDBDatabase_IteratorNext_ProxyToResponder(
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
            bool in_valid, DatabaseError in_status, const base::Optional<std::vector<uint8_t>>& in_key, const base::Optional<std::vector<uint8_t>>& in_value);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(LevelDBDatabase_IteratorNext_ProxyToResponder);
    };

    void LevelDBDatabase_IteratorNext_ProxyToResponder::Run(
        bool in_valid, DatabaseError in_status, const base::Optional<std::vector<uint8_t>>& in_key, const base::Optional<std::vector<uint8_t>>& in_value)
    {
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBDatabase_IteratorNext_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_key, &serialization_context_);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_value, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kLevelDBDatabase_IteratorNext_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::leveldb::mojom::internal::LevelDBDatabase_IteratorNext_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->valid = in_valid;
        mojo::internal::Serialize<::leveldb::mojom::DatabaseError>(
            in_status, &params->status);
        typename decltype(params->key)::BaseType* key_ptr;
        const mojo::internal::ContainerValidateParams key_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_key, builder.buffer(), &key_ptr, &key_validate_params,
            &serialization_context_);
        params->key.Set(key_ptr);
        typename decltype(params->value)::BaseType* value_ptr;
        const mojo::internal::ContainerValidateParams value_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_value, builder.buffer(), &value_ptr, &value_validate_params,
            &serialization_context_);
        params->value.Set(value_ptr);
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class LevelDBDatabase_IteratorPrev_ProxyToResponder {
    public:
        static LevelDBDatabase::IteratorPrevCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<LevelDBDatabase_IteratorPrev_ProxyToResponder> proxy(
                new LevelDBDatabase_IteratorPrev_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&LevelDBDatabase_IteratorPrev_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~LevelDBDatabase_IteratorPrev_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "LevelDBDatabase::IteratorPrev() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        LevelDBDatabase_IteratorPrev_ProxyToResponder(
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
            bool in_valid, DatabaseError in_status, const base::Optional<std::vector<uint8_t>>& in_key, const base::Optional<std::vector<uint8_t>>& in_value);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(LevelDBDatabase_IteratorPrev_ProxyToResponder);
    };

    void LevelDBDatabase_IteratorPrev_ProxyToResponder::Run(
        bool in_valid, DatabaseError in_status, const base::Optional<std::vector<uint8_t>>& in_key, const base::Optional<std::vector<uint8_t>>& in_value)
    {
        size_t size = sizeof(::leveldb::mojom::internal::LevelDBDatabase_IteratorPrev_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_key, &serialization_context_);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_value, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kLevelDBDatabase_IteratorPrev_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::leveldb::mojom::internal::LevelDBDatabase_IteratorPrev_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        params->valid = in_valid;
        mojo::internal::Serialize<::leveldb::mojom::DatabaseError>(
            in_status, &params->status);
        typename decltype(params->key)::BaseType* key_ptr;
        const mojo::internal::ContainerValidateParams key_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_key, builder.buffer(), &key_ptr, &key_validate_params,
            &serialization_context_);
        params->key.Set(key_ptr);
        typename decltype(params->value)::BaseType* value_ptr;
        const mojo::internal::ContainerValidateParams value_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_value, builder.buffer(), &value_ptr, &value_validate_params,
            &serialization_context_);
        params->value.Set(value_ptr);
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
    bool LevelDBDatabaseStubDispatch::Accept(
        LevelDBDatabase* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kLevelDBDatabase_Put_Name: {
            break;
        }
        case internal::kLevelDBDatabase_Delete_Name: {
            break;
        }
        case internal::kLevelDBDatabase_DeletePrefixed_Name: {
            break;
        }
        case internal::kLevelDBDatabase_Write_Name: {
            break;
        }
        case internal::kLevelDBDatabase_Get_Name: {
            break;
        }
        case internal::kLevelDBDatabase_GetPrefixed_Name: {
            break;
        }
        case internal::kLevelDBDatabase_GetSnapshot_Name: {
            break;
        }
        case internal::kLevelDBDatabase_ReleaseSnapshot_Name: {
            internal::LevelDBDatabase_ReleaseSnapshot_Params_Data* params = reinterpret_cast<internal::LevelDBDatabase_ReleaseSnapshot_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            base::UnguessableToken p_snapshot {};
            LevelDBDatabase_ReleaseSnapshot_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadSnapshot(&p_snapshot))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "LevelDBDatabase::ReleaseSnapshot deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "LevelDBDatabase::ReleaseSnapshot");
            mojo::internal::MessageDispatchContext context(message);
            impl->ReleaseSnapshot(
                std::move(p_snapshot));
            return true;
        }
        case internal::kLevelDBDatabase_GetFromSnapshot_Name: {
            break;
        }
        case internal::kLevelDBDatabase_NewIterator_Name: {
            break;
        }
        case internal::kLevelDBDatabase_NewIteratorFromSnapshot_Name: {
            break;
        }
        case internal::kLevelDBDatabase_ReleaseIterator_Name: {
            internal::LevelDBDatabase_ReleaseIterator_Params_Data* params = reinterpret_cast<internal::LevelDBDatabase_ReleaseIterator_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            base::UnguessableToken p_iterator {};
            LevelDBDatabase_ReleaseIterator_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadIterator(&p_iterator))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "LevelDBDatabase::ReleaseIterator deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "LevelDBDatabase::ReleaseIterator");
            mojo::internal::MessageDispatchContext context(message);
            impl->ReleaseIterator(
                std::move(p_iterator));
            return true;
        }
        case internal::kLevelDBDatabase_IteratorSeekToFirst_Name: {
            break;
        }
        case internal::kLevelDBDatabase_IteratorSeekToLast_Name: {
            break;
        }
        case internal::kLevelDBDatabase_IteratorSeek_Name: {
            break;
        }
        case internal::kLevelDBDatabase_IteratorNext_Name: {
            break;
        }
        case internal::kLevelDBDatabase_IteratorPrev_Name: {
            break;
        }
        }
        return false;
    }

    // static
    bool LevelDBDatabaseStubDispatch::AcceptWithResponder(
        LevelDBDatabase* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kLevelDBDatabase_Put_Name: {
            internal::LevelDBDatabase_Put_Params_Data* params = reinterpret_cast<internal::LevelDBDatabase_Put_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::vector<uint8_t> p_key {};
            std::vector<uint8_t> p_value {};
            LevelDBDatabase_Put_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadKey(&p_key))
                success = false;
            if (!input_data_view.ReadValue(&p_value))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "LevelDBDatabase::Put deserializer");
                return false;
            }
            LevelDBDatabase::PutCallback callback = LevelDBDatabase_Put_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "LevelDBDatabase::Put");
            mojo::internal::MessageDispatchContext context(message);
            impl->Put(
                std::move(p_key),
                std::move(p_value), std::move(callback));
            return true;
        }
        case internal::kLevelDBDatabase_Delete_Name: {
            internal::LevelDBDatabase_Delete_Params_Data* params = reinterpret_cast<internal::LevelDBDatabase_Delete_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::vector<uint8_t> p_key {};
            LevelDBDatabase_Delete_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadKey(&p_key))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "LevelDBDatabase::Delete deserializer");
                return false;
            }
            LevelDBDatabase::DeleteCallback callback = LevelDBDatabase_Delete_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "LevelDBDatabase::Delete");
            mojo::internal::MessageDispatchContext context(message);
            impl->Delete(
                std::move(p_key), std::move(callback));
            return true;
        }
        case internal::kLevelDBDatabase_DeletePrefixed_Name: {
            internal::LevelDBDatabase_DeletePrefixed_Params_Data* params = reinterpret_cast<internal::LevelDBDatabase_DeletePrefixed_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::vector<uint8_t> p_key_prefix {};
            LevelDBDatabase_DeletePrefixed_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadKeyPrefix(&p_key_prefix))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "LevelDBDatabase::DeletePrefixed deserializer");
                return false;
            }
            LevelDBDatabase::DeletePrefixedCallback callback = LevelDBDatabase_DeletePrefixed_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "LevelDBDatabase::DeletePrefixed");
            mojo::internal::MessageDispatchContext context(message);
            impl->DeletePrefixed(
                std::move(p_key_prefix), std::move(callback));
            return true;
        }
        case internal::kLevelDBDatabase_Write_Name: {
            internal::LevelDBDatabase_Write_Params_Data* params = reinterpret_cast<internal::LevelDBDatabase_Write_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::vector<BatchedOperationPtr> p_operations {};
            LevelDBDatabase_Write_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadOperations(&p_operations))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "LevelDBDatabase::Write deserializer");
                return false;
            }
            LevelDBDatabase::WriteCallback callback = LevelDBDatabase_Write_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "LevelDBDatabase::Write");
            mojo::internal::MessageDispatchContext context(message);
            impl->Write(
                std::move(p_operations), std::move(callback));
            return true;
        }
        case internal::kLevelDBDatabase_Get_Name: {
            internal::LevelDBDatabase_Get_Params_Data* params = reinterpret_cast<internal::LevelDBDatabase_Get_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::vector<uint8_t> p_key {};
            LevelDBDatabase_Get_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadKey(&p_key))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "LevelDBDatabase::Get deserializer");
                return false;
            }
            LevelDBDatabase::GetCallback callback = LevelDBDatabase_Get_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "LevelDBDatabase::Get");
            mojo::internal::MessageDispatchContext context(message);
            impl->Get(
                std::move(p_key), std::move(callback));
            return true;
        }
        case internal::kLevelDBDatabase_GetPrefixed_Name: {
            internal::LevelDBDatabase_GetPrefixed_Params_Data* params = reinterpret_cast<internal::LevelDBDatabase_GetPrefixed_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::vector<uint8_t> p_key_prefix {};
            LevelDBDatabase_GetPrefixed_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadKeyPrefix(&p_key_prefix))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "LevelDBDatabase::GetPrefixed deserializer");
                return false;
            }
            LevelDBDatabase::GetPrefixedCallback callback = LevelDBDatabase_GetPrefixed_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "LevelDBDatabase::GetPrefixed");
            mojo::internal::MessageDispatchContext context(message);
            impl->GetPrefixed(
                std::move(p_key_prefix), std::move(callback));
            return true;
        }
        case internal::kLevelDBDatabase_GetSnapshot_Name: {
            internal::LevelDBDatabase_GetSnapshot_Params_Data* params = reinterpret_cast<internal::LevelDBDatabase_GetSnapshot_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            LevelDBDatabase_GetSnapshot_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "LevelDBDatabase::GetSnapshot deserializer");
                return false;
            }
            LevelDBDatabase::GetSnapshotCallback callback = LevelDBDatabase_GetSnapshot_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "LevelDBDatabase::GetSnapshot");
            mojo::internal::MessageDispatchContext context(message);
            impl->GetSnapshot(std::move(callback));
            return true;
        }
        case internal::kLevelDBDatabase_ReleaseSnapshot_Name: {
            break;
        }
        case internal::kLevelDBDatabase_GetFromSnapshot_Name: {
            internal::LevelDBDatabase_GetFromSnapshot_Params_Data* params = reinterpret_cast<internal::LevelDBDatabase_GetFromSnapshot_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            base::UnguessableToken p_snapshot {};
            std::vector<uint8_t> p_key {};
            LevelDBDatabase_GetFromSnapshot_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadSnapshot(&p_snapshot))
                success = false;
            if (!input_data_view.ReadKey(&p_key))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "LevelDBDatabase::GetFromSnapshot deserializer");
                return false;
            }
            LevelDBDatabase::GetFromSnapshotCallback callback = LevelDBDatabase_GetFromSnapshot_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "LevelDBDatabase::GetFromSnapshot");
            mojo::internal::MessageDispatchContext context(message);
            impl->GetFromSnapshot(
                std::move(p_snapshot),
                std::move(p_key), std::move(callback));
            return true;
        }
        case internal::kLevelDBDatabase_NewIterator_Name: {
            internal::LevelDBDatabase_NewIterator_Params_Data* params = reinterpret_cast<internal::LevelDBDatabase_NewIterator_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            LevelDBDatabase_NewIterator_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "LevelDBDatabase::NewIterator deserializer");
                return false;
            }
            LevelDBDatabase::NewIteratorCallback callback = LevelDBDatabase_NewIterator_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "LevelDBDatabase::NewIterator");
            mojo::internal::MessageDispatchContext context(message);
            impl->NewIterator(std::move(callback));
            return true;
        }
        case internal::kLevelDBDatabase_NewIteratorFromSnapshot_Name: {
            internal::LevelDBDatabase_NewIteratorFromSnapshot_Params_Data* params = reinterpret_cast<internal::LevelDBDatabase_NewIteratorFromSnapshot_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            base::UnguessableToken p_snapshot {};
            LevelDBDatabase_NewIteratorFromSnapshot_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadSnapshot(&p_snapshot))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "LevelDBDatabase::NewIteratorFromSnapshot deserializer");
                return false;
            }
            LevelDBDatabase::NewIteratorFromSnapshotCallback callback = LevelDBDatabase_NewIteratorFromSnapshot_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "LevelDBDatabase::NewIteratorFromSnapshot");
            mojo::internal::MessageDispatchContext context(message);
            impl->NewIteratorFromSnapshot(
                std::move(p_snapshot), std::move(callback));
            return true;
        }
        case internal::kLevelDBDatabase_ReleaseIterator_Name: {
            break;
        }
        case internal::kLevelDBDatabase_IteratorSeekToFirst_Name: {
            internal::LevelDBDatabase_IteratorSeekToFirst_Params_Data* params = reinterpret_cast<internal::LevelDBDatabase_IteratorSeekToFirst_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            base::UnguessableToken p_iterator {};
            LevelDBDatabase_IteratorSeekToFirst_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadIterator(&p_iterator))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "LevelDBDatabase::IteratorSeekToFirst deserializer");
                return false;
            }
            LevelDBDatabase::IteratorSeekToFirstCallback callback = LevelDBDatabase_IteratorSeekToFirst_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "LevelDBDatabase::IteratorSeekToFirst");
            mojo::internal::MessageDispatchContext context(message);
            impl->IteratorSeekToFirst(
                std::move(p_iterator), std::move(callback));
            return true;
        }
        case internal::kLevelDBDatabase_IteratorSeekToLast_Name: {
            internal::LevelDBDatabase_IteratorSeekToLast_Params_Data* params = reinterpret_cast<internal::LevelDBDatabase_IteratorSeekToLast_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            base::UnguessableToken p_iterator {};
            LevelDBDatabase_IteratorSeekToLast_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadIterator(&p_iterator))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "LevelDBDatabase::IteratorSeekToLast deserializer");
                return false;
            }
            LevelDBDatabase::IteratorSeekToLastCallback callback = LevelDBDatabase_IteratorSeekToLast_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "LevelDBDatabase::IteratorSeekToLast");
            mojo::internal::MessageDispatchContext context(message);
            impl->IteratorSeekToLast(
                std::move(p_iterator), std::move(callback));
            return true;
        }
        case internal::kLevelDBDatabase_IteratorSeek_Name: {
            internal::LevelDBDatabase_IteratorSeek_Params_Data* params = reinterpret_cast<internal::LevelDBDatabase_IteratorSeek_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            base::UnguessableToken p_iterator {};
            std::vector<uint8_t> p_target {};
            LevelDBDatabase_IteratorSeek_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadIterator(&p_iterator))
                success = false;
            if (!input_data_view.ReadTarget(&p_target))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "LevelDBDatabase::IteratorSeek deserializer");
                return false;
            }
            LevelDBDatabase::IteratorSeekCallback callback = LevelDBDatabase_IteratorSeek_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "LevelDBDatabase::IteratorSeek");
            mojo::internal::MessageDispatchContext context(message);
            impl->IteratorSeek(
                std::move(p_iterator),
                std::move(p_target), std::move(callback));
            return true;
        }
        case internal::kLevelDBDatabase_IteratorNext_Name: {
            internal::LevelDBDatabase_IteratorNext_Params_Data* params = reinterpret_cast<internal::LevelDBDatabase_IteratorNext_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            base::UnguessableToken p_iterator {};
            LevelDBDatabase_IteratorNext_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadIterator(&p_iterator))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "LevelDBDatabase::IteratorNext deserializer");
                return false;
            }
            LevelDBDatabase::IteratorNextCallback callback = LevelDBDatabase_IteratorNext_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "LevelDBDatabase::IteratorNext");
            mojo::internal::MessageDispatchContext context(message);
            impl->IteratorNext(
                std::move(p_iterator), std::move(callback));
            return true;
        }
        case internal::kLevelDBDatabase_IteratorPrev_Name: {
            internal::LevelDBDatabase_IteratorPrev_Params_Data* params = reinterpret_cast<internal::LevelDBDatabase_IteratorPrev_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            base::UnguessableToken p_iterator {};
            LevelDBDatabase_IteratorPrev_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadIterator(&p_iterator))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "LevelDBDatabase::IteratorPrev deserializer");
                return false;
            }
            LevelDBDatabase::IteratorPrevCallback callback = LevelDBDatabase_IteratorPrev_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "LevelDBDatabase::IteratorPrev");
            mojo::internal::MessageDispatchContext context(message);
            impl->IteratorPrev(
                std::move(p_iterator), std::move(callback));
            return true;
        }
        }
        return false;
    }

    bool LevelDBDatabaseRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "LevelDBDatabase RequestValidator");

        switch (message->header()->name) {
        case internal::kLevelDBDatabase_Put_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBDatabase_Put_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBDatabase_Delete_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBDatabase_Delete_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBDatabase_DeletePrefixed_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBDatabase_DeletePrefixed_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBDatabase_Write_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBDatabase_Write_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBDatabase_Get_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBDatabase_Get_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBDatabase_GetPrefixed_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBDatabase_GetPrefixed_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBDatabase_GetSnapshot_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBDatabase_GetSnapshot_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBDatabase_ReleaseSnapshot_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBDatabase_ReleaseSnapshot_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBDatabase_GetFromSnapshot_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBDatabase_GetFromSnapshot_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBDatabase_NewIterator_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBDatabase_NewIterator_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBDatabase_NewIteratorFromSnapshot_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBDatabase_NewIteratorFromSnapshot_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBDatabase_ReleaseIterator_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBDatabase_ReleaseIterator_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBDatabase_IteratorSeekToFirst_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBDatabase_IteratorSeekToFirst_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBDatabase_IteratorSeekToLast_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBDatabase_IteratorSeekToLast_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBDatabase_IteratorSeek_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBDatabase_IteratorSeek_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBDatabase_IteratorNext_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBDatabase_IteratorNext_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBDatabase_IteratorPrev_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBDatabase_IteratorPrev_Params_Data>(
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

    bool LevelDBDatabaseResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "LevelDBDatabase ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kLevelDBDatabase_Put_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBDatabase_Put_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBDatabase_Delete_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBDatabase_Delete_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBDatabase_DeletePrefixed_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBDatabase_DeletePrefixed_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBDatabase_Write_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBDatabase_Write_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBDatabase_Get_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBDatabase_Get_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBDatabase_GetPrefixed_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBDatabase_GetPrefixed_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBDatabase_GetSnapshot_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBDatabase_GetSnapshot_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBDatabase_GetFromSnapshot_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBDatabase_GetFromSnapshot_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBDatabase_NewIterator_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBDatabase_NewIterator_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBDatabase_NewIteratorFromSnapshot_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBDatabase_NewIteratorFromSnapshot_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBDatabase_IteratorSeekToFirst_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBDatabase_IteratorSeekToFirst_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBDatabase_IteratorSeekToLast_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBDatabase_IteratorSeekToLast_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBDatabase_IteratorSeek_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBDatabase_IteratorSeek_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBDatabase_IteratorNext_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBDatabase_IteratorNext_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kLevelDBDatabase_IteratorPrev_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::LevelDBDatabase_IteratorPrev_ResponseParams_Data>(
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
} // namespace leveldb

namespace mojo {

// static
bool StructTraits<::leveldb::mojom::BatchedOperation::DataView, ::leveldb::mojom::BatchedOperationPtr>::Read(
    ::leveldb::mojom::BatchedOperation::DataView input,
    ::leveldb::mojom::BatchedOperationPtr* output)
{
    bool success = true;
    ::leveldb::mojom::BatchedOperationPtr result(::leveldb::mojom::BatchedOperation::New());

    if (!input.ReadType(&result->type))
        success = false;
    if (!input.ReadKey(&result->key))
        success = false;
    if (!input.ReadValue(&result->value))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::leveldb::mojom::KeyValue::DataView, ::leveldb::mojom::KeyValuePtr>::Read(
    ::leveldb::mojom::KeyValue::DataView input,
    ::leveldb::mojom::KeyValuePtr* output)
{
    bool success = true;
    ::leveldb::mojom::KeyValuePtr result(::leveldb::mojom::KeyValue::New());

    if (!input.ReadKey(&result->key))
        success = false;
    if (!input.ReadValue(&result->value))
        success = false;
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::leveldb::mojom::OpenOptions::DataView, ::leveldb::mojom::OpenOptionsPtr>::Read(
    ::leveldb::mojom::OpenOptions::DataView input,
    ::leveldb::mojom::OpenOptionsPtr* output)
{
    bool success = true;
    ::leveldb::mojom::OpenOptionsPtr result(::leveldb::mojom::OpenOptions::New());

    result->create_if_missing = input.create_if_missing();
    result->error_if_exists = input.error_if_exists();
    result->paranoid_checks = input.paranoid_checks();
    result->write_buffer_size = input.write_buffer_size();
    result->max_open_files = input.max_open_files();
    *output = std::move(result);
    return success;
}

} // namespace mojo

#if defined(__clang__)
#pragma clang diagnostic pop
#elif defined(_MSC_VER)
#pragma warning(pop)
#endif