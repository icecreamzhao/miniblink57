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

#include "components/filesystem/public/interfaces/directory.mojom.h"

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
namespace filesystem {
namespace mojom { // static
    FileOpenDetailsPtr FileOpenDetails::New()
    {
        FileOpenDetailsPtr rv;
        mojo::internal::StructHelper<FileOpenDetails>::Initialize(&rv);
        return rv;
    }

    FileOpenDetails::FileOpenDetails()
        : path()
        , open_flags()
    {
    }

    FileOpenDetails::~FileOpenDetails()
    {
    }
    size_t FileOpenDetails::Hash(size_t seed) const
    {
        seed = mojo::internal::Hash(seed, this->path);
        seed = mojo::internal::Hash(seed, this->open_flags);
        return seed;
    } // static
    FileOpenResultPtr FileOpenResult::New()
    {
        FileOpenResultPtr rv;
        mojo::internal::StructHelper<FileOpenResult>::Initialize(&rv);
        return rv;
    }

    FileOpenResult::FileOpenResult()
        : path()
        , error()
        , file_handle()
    {
    }

    FileOpenResult::~FileOpenResult()
    {
    }
    const char Directory::Name_[] = "filesystem::mojom::Directory";
    bool Directory::Read(::filesystem::mojom::FileError* error, base::Optional<std::vector<::filesystem::mojom::DirectoryEntryPtr>>* directory_contents)
    {
        NOTREACHED();
        return false;
    }
    bool Directory::OpenFile(const std::string& path, ::filesystem::mojom::FileRequest file, uint32_t open_flags, ::filesystem::mojom::FileError* error)
    {
        NOTREACHED();
        return false;
    }
    bool Directory::OpenFileHandle(const std::string& path, uint32_t open_flags, ::filesystem::mojom::FileError* error, base::File* file_handle)
    {
        NOTREACHED();
        return false;
    }
    bool Directory::OpenFileHandles(std::vector<FileOpenDetailsPtr> files, std::vector<FileOpenResultPtr>* results)
    {
        NOTREACHED();
        return false;
    }
    bool Directory::OpenDirectory(const std::string& path, DirectoryRequest directory, uint32_t open_flags, ::filesystem::mojom::FileError* error)
    {
        NOTREACHED();
        return false;
    }
    bool Directory::Rename(const std::string& path, const std::string& new_path, ::filesystem::mojom::FileError* error)
    {
        NOTREACHED();
        return false;
    }
    bool Directory::Delete(const std::string& path, uint32_t delete_flags, ::filesystem::mojom::FileError* error)
    {
        NOTREACHED();
        return false;
    }
    bool Directory::Exists(const std::string& path, ::filesystem::mojom::FileError* error, bool* exists)
    {
        NOTREACHED();
        return false;
    }
    bool Directory::IsWritable(const std::string& path, ::filesystem::mojom::FileError* error, bool* is_writable)
    {
        NOTREACHED();
        return false;
    }
    bool Directory::Flush(::filesystem::mojom::FileError* error)
    {
        NOTREACHED();
        return false;
    }
    bool Directory::StatFile(const std::string& path, ::filesystem::mojom::FileError* error, ::filesystem::mojom::FileInformationPtr* file_information)
    {
        NOTREACHED();
        return false;
    }
    bool Directory::ReadEntireFile(const std::string& path, ::filesystem::mojom::FileError* error, std::vector<uint8_t>* data)
    {
        NOTREACHED();
        return false;
    }
    bool Directory::WriteFile(const std::string& path, const std::vector<uint8_t>& data, ::filesystem::mojom::FileError* error)
    {
        NOTREACHED();
        return false;
    }
    class Directory_Read_HandleSyncResponse
        : public mojo::MessageReceiver {
    public:
        Directory_Read_HandleSyncResponse(
            scoped_refptr<mojo::AssociatedGroupController> group_controller,
            bool* result, ::filesystem::mojom::FileError* out_error, base::Optional<std::vector<::filesystem::mojom::DirectoryEntryPtr>>* out_directory_contents)
            : serialization_context_(std::move(group_controller))
            , result_(result)
            , out_error_(out_error)
            , out_directory_contents_(out_directory_contents)
        {
            DCHECK(!*result_);
        }
        bool Accept(mojo::Message* message) override;

    private:
        mojo::internal::SerializationContext serialization_context_;
        bool* result_;
        ::filesystem::mojom::FileError* out_error_;
        base::Optional<std::vector<::filesystem::mojom::DirectoryEntryPtr>>* out_directory_contents_;
        DISALLOW_COPY_AND_ASSIGN(Directory_Read_HandleSyncResponse);
    };
    bool Directory_Read_HandleSyncResponse::Accept(
        mojo::Message* message)
    {
        internal::Directory_Read_ResponseParams_Data* params = reinterpret_cast<internal::Directory_Read_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::filesystem::mojom::FileError p_error {};
        base::Optional<std::vector<::filesystem::mojom::DirectoryEntryPtr>> p_directory_contents {};
        Directory_Read_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadError(&p_error))
            success = false;
        if (!input_data_view.ReadDirectoryContents(&p_directory_contents))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Directory::Read response deserializer");
            return false;
        }
        *out_error_ = std::move(p_error);
        *out_directory_contents_ = std::move(p_directory_contents);
        mojo::internal::SyncMessageResponseSetup::SetCurrentSyncResponseMessage(
            message);
        *result_ = true;
        return true;
    }

    class Directory_Read_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        Directory_Read_ForwardToCallback(
            const Directory::ReadCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        Directory::ReadCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(Directory_Read_ForwardToCallback);
    };
    bool Directory_Read_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::Directory_Read_ResponseParams_Data* params = reinterpret_cast<internal::Directory_Read_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::filesystem::mojom::FileError p_error {};
        base::Optional<std::vector<::filesystem::mojom::DirectoryEntryPtr>> p_directory_contents {};
        Directory_Read_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadError(&p_error))
            success = false;
        if (!input_data_view.ReadDirectoryContents(&p_directory_contents))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Directory::Read response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_error),
                std::move(p_directory_contents));
        }
        return true;
    }
    class Directory_OpenFile_HandleSyncResponse
        : public mojo::MessageReceiver {
    public:
        Directory_OpenFile_HandleSyncResponse(
            scoped_refptr<mojo::AssociatedGroupController> group_controller,
            bool* result, ::filesystem::mojom::FileError* out_error)
            : serialization_context_(std::move(group_controller))
            , result_(result)
            , out_error_(out_error)
        {
            DCHECK(!*result_);
        }
        bool Accept(mojo::Message* message) override;

    private:
        mojo::internal::SerializationContext serialization_context_;
        bool* result_;
        ::filesystem::mojom::FileError* out_error_;
        DISALLOW_COPY_AND_ASSIGN(Directory_OpenFile_HandleSyncResponse);
    };
    bool Directory_OpenFile_HandleSyncResponse::Accept(
        mojo::Message* message)
    {
        internal::Directory_OpenFile_ResponseParams_Data* params = reinterpret_cast<internal::Directory_OpenFile_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::filesystem::mojom::FileError p_error {};
        Directory_OpenFile_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadError(&p_error))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Directory::OpenFile response deserializer");
            return false;
        }
        *out_error_ = std::move(p_error);
        mojo::internal::SyncMessageResponseSetup::SetCurrentSyncResponseMessage(
            message);
        *result_ = true;
        return true;
    }

    class Directory_OpenFile_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        Directory_OpenFile_ForwardToCallback(
            const Directory::OpenFileCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        Directory::OpenFileCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(Directory_OpenFile_ForwardToCallback);
    };
    bool Directory_OpenFile_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::Directory_OpenFile_ResponseParams_Data* params = reinterpret_cast<internal::Directory_OpenFile_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::filesystem::mojom::FileError p_error {};
        Directory_OpenFile_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadError(&p_error))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Directory::OpenFile response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_error));
        }
        return true;
    }
    class Directory_OpenFileHandle_HandleSyncResponse
        : public mojo::MessageReceiver {
    public:
        Directory_OpenFileHandle_HandleSyncResponse(
            scoped_refptr<mojo::AssociatedGroupController> group_controller,
            bool* result, ::filesystem::mojom::FileError* out_error, base::File* out_file_handle)
            : serialization_context_(std::move(group_controller))
            , result_(result)
            , out_error_(out_error)
            , out_file_handle_(out_file_handle)
        {
            DCHECK(!*result_);
        }
        bool Accept(mojo::Message* message) override;

    private:
        mojo::internal::SerializationContext serialization_context_;
        bool* result_;
        ::filesystem::mojom::FileError* out_error_;
        base::File* out_file_handle_;
        DISALLOW_COPY_AND_ASSIGN(Directory_OpenFileHandle_HandleSyncResponse);
    };
    bool Directory_OpenFileHandle_HandleSyncResponse::Accept(
        mojo::Message* message)
    {
        internal::Directory_OpenFileHandle_ResponseParams_Data* params = reinterpret_cast<internal::Directory_OpenFileHandle_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::filesystem::mojom::FileError p_error {};
        base::File p_file_handle {};
        Directory_OpenFileHandle_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadError(&p_error))
            success = false;
        if (!input_data_view.ReadFileHandle(&p_file_handle))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Directory::OpenFileHandle response deserializer");
            return false;
        }
        *out_error_ = std::move(p_error);
        *out_file_handle_ = std::move(p_file_handle);
        mojo::internal::SyncMessageResponseSetup::SetCurrentSyncResponseMessage(
            message);
        *result_ = true;
        return true;
    }

    class Directory_OpenFileHandle_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        Directory_OpenFileHandle_ForwardToCallback(
            const Directory::OpenFileHandleCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        Directory::OpenFileHandleCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(Directory_OpenFileHandle_ForwardToCallback);
    };
    bool Directory_OpenFileHandle_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::Directory_OpenFileHandle_ResponseParams_Data* params = reinterpret_cast<internal::Directory_OpenFileHandle_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::filesystem::mojom::FileError p_error {};
        base::File p_file_handle {};
        Directory_OpenFileHandle_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadError(&p_error))
            success = false;
        if (!input_data_view.ReadFileHandle(&p_file_handle))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Directory::OpenFileHandle response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_error),
                std::move(p_file_handle));
        }
        return true;
    }
    class Directory_OpenFileHandles_HandleSyncResponse
        : public mojo::MessageReceiver {
    public:
        Directory_OpenFileHandles_HandleSyncResponse(
            scoped_refptr<mojo::AssociatedGroupController> group_controller,
            bool* result, std::vector<FileOpenResultPtr>* out_results)
            : serialization_context_(std::move(group_controller))
            , result_(result)
            , out_results_(out_results)
        {
            DCHECK(!*result_);
        }
        bool Accept(mojo::Message* message) override;

    private:
        mojo::internal::SerializationContext serialization_context_;
        bool* result_;
        std::vector<FileOpenResultPtr>* out_results_;
        DISALLOW_COPY_AND_ASSIGN(Directory_OpenFileHandles_HandleSyncResponse);
    };
    bool Directory_OpenFileHandles_HandleSyncResponse::Accept(
        mojo::Message* message)
    {
        internal::Directory_OpenFileHandles_ResponseParams_Data* params = reinterpret_cast<internal::Directory_OpenFileHandles_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        std::vector<FileOpenResultPtr> p_results {};
        Directory_OpenFileHandles_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadResults(&p_results))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Directory::OpenFileHandles response deserializer");
            return false;
        }
        *out_results_ = std::move(p_results);
        mojo::internal::SyncMessageResponseSetup::SetCurrentSyncResponseMessage(
            message);
        *result_ = true;
        return true;
    }

    class Directory_OpenFileHandles_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        Directory_OpenFileHandles_ForwardToCallback(
            const Directory::OpenFileHandlesCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        Directory::OpenFileHandlesCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(Directory_OpenFileHandles_ForwardToCallback);
    };
    bool Directory_OpenFileHandles_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::Directory_OpenFileHandles_ResponseParams_Data* params = reinterpret_cast<internal::Directory_OpenFileHandles_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        std::vector<FileOpenResultPtr> p_results {};
        Directory_OpenFileHandles_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadResults(&p_results))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Directory::OpenFileHandles response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_results));
        }
        return true;
    }
    class Directory_OpenDirectory_HandleSyncResponse
        : public mojo::MessageReceiver {
    public:
        Directory_OpenDirectory_HandleSyncResponse(
            scoped_refptr<mojo::AssociatedGroupController> group_controller,
            bool* result, ::filesystem::mojom::FileError* out_error)
            : serialization_context_(std::move(group_controller))
            , result_(result)
            , out_error_(out_error)
        {
            DCHECK(!*result_);
        }
        bool Accept(mojo::Message* message) override;

    private:
        mojo::internal::SerializationContext serialization_context_;
        bool* result_;
        ::filesystem::mojom::FileError* out_error_;
        DISALLOW_COPY_AND_ASSIGN(Directory_OpenDirectory_HandleSyncResponse);
    };
    bool Directory_OpenDirectory_HandleSyncResponse::Accept(
        mojo::Message* message)
    {
        internal::Directory_OpenDirectory_ResponseParams_Data* params = reinterpret_cast<internal::Directory_OpenDirectory_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::filesystem::mojom::FileError p_error {};
        Directory_OpenDirectory_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadError(&p_error))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Directory::OpenDirectory response deserializer");
            return false;
        }
        *out_error_ = std::move(p_error);
        mojo::internal::SyncMessageResponseSetup::SetCurrentSyncResponseMessage(
            message);
        *result_ = true;
        return true;
    }

    class Directory_OpenDirectory_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        Directory_OpenDirectory_ForwardToCallback(
            const Directory::OpenDirectoryCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        Directory::OpenDirectoryCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(Directory_OpenDirectory_ForwardToCallback);
    };
    bool Directory_OpenDirectory_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::Directory_OpenDirectory_ResponseParams_Data* params = reinterpret_cast<internal::Directory_OpenDirectory_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::filesystem::mojom::FileError p_error {};
        Directory_OpenDirectory_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadError(&p_error))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Directory::OpenDirectory response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_error));
        }
        return true;
    }
    class Directory_Rename_HandleSyncResponse
        : public mojo::MessageReceiver {
    public:
        Directory_Rename_HandleSyncResponse(
            scoped_refptr<mojo::AssociatedGroupController> group_controller,
            bool* result, ::filesystem::mojom::FileError* out_error)
            : serialization_context_(std::move(group_controller))
            , result_(result)
            , out_error_(out_error)
        {
            DCHECK(!*result_);
        }
        bool Accept(mojo::Message* message) override;

    private:
        mojo::internal::SerializationContext serialization_context_;
        bool* result_;
        ::filesystem::mojom::FileError* out_error_;
        DISALLOW_COPY_AND_ASSIGN(Directory_Rename_HandleSyncResponse);
    };
    bool Directory_Rename_HandleSyncResponse::Accept(
        mojo::Message* message)
    {
        internal::Directory_Rename_ResponseParams_Data* params = reinterpret_cast<internal::Directory_Rename_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::filesystem::mojom::FileError p_error {};
        Directory_Rename_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadError(&p_error))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Directory::Rename response deserializer");
            return false;
        }
        *out_error_ = std::move(p_error);
        mojo::internal::SyncMessageResponseSetup::SetCurrentSyncResponseMessage(
            message);
        *result_ = true;
        return true;
    }

    class Directory_Rename_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        Directory_Rename_ForwardToCallback(
            const Directory::RenameCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        Directory::RenameCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(Directory_Rename_ForwardToCallback);
    };
    bool Directory_Rename_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::Directory_Rename_ResponseParams_Data* params = reinterpret_cast<internal::Directory_Rename_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::filesystem::mojom::FileError p_error {};
        Directory_Rename_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadError(&p_error))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Directory::Rename response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_error));
        }
        return true;
    }
    class Directory_Delete_HandleSyncResponse
        : public mojo::MessageReceiver {
    public:
        Directory_Delete_HandleSyncResponse(
            scoped_refptr<mojo::AssociatedGroupController> group_controller,
            bool* result, ::filesystem::mojom::FileError* out_error)
            : serialization_context_(std::move(group_controller))
            , result_(result)
            , out_error_(out_error)
        {
            DCHECK(!*result_);
        }
        bool Accept(mojo::Message* message) override;

    private:
        mojo::internal::SerializationContext serialization_context_;
        bool* result_;
        ::filesystem::mojom::FileError* out_error_;
        DISALLOW_COPY_AND_ASSIGN(Directory_Delete_HandleSyncResponse);
    };
    bool Directory_Delete_HandleSyncResponse::Accept(
        mojo::Message* message)
    {
        internal::Directory_Delete_ResponseParams_Data* params = reinterpret_cast<internal::Directory_Delete_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::filesystem::mojom::FileError p_error {};
        Directory_Delete_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadError(&p_error))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Directory::Delete response deserializer");
            return false;
        }
        *out_error_ = std::move(p_error);
        mojo::internal::SyncMessageResponseSetup::SetCurrentSyncResponseMessage(
            message);
        *result_ = true;
        return true;
    }

    class Directory_Delete_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        Directory_Delete_ForwardToCallback(
            const Directory::DeleteCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        Directory::DeleteCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(Directory_Delete_ForwardToCallback);
    };
    bool Directory_Delete_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::Directory_Delete_ResponseParams_Data* params = reinterpret_cast<internal::Directory_Delete_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::filesystem::mojom::FileError p_error {};
        Directory_Delete_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadError(&p_error))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Directory::Delete response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_error));
        }
        return true;
    }
    class Directory_Exists_HandleSyncResponse
        : public mojo::MessageReceiver {
    public:
        Directory_Exists_HandleSyncResponse(
            scoped_refptr<mojo::AssociatedGroupController> group_controller,
            bool* result, ::filesystem::mojom::FileError* out_error, bool* out_exists)
            : serialization_context_(std::move(group_controller))
            , result_(result)
            , out_error_(out_error)
            , out_exists_(out_exists)
        {
            DCHECK(!*result_);
        }
        bool Accept(mojo::Message* message) override;

    private:
        mojo::internal::SerializationContext serialization_context_;
        bool* result_;
        ::filesystem::mojom::FileError* out_error_;
        bool* out_exists_;
        DISALLOW_COPY_AND_ASSIGN(Directory_Exists_HandleSyncResponse);
    };
    bool Directory_Exists_HandleSyncResponse::Accept(
        mojo::Message* message)
    {
        internal::Directory_Exists_ResponseParams_Data* params = reinterpret_cast<internal::Directory_Exists_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::filesystem::mojom::FileError p_error {};
        bool p_exists {};
        Directory_Exists_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadError(&p_error))
            success = false;
        p_exists = input_data_view.exists();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Directory::Exists response deserializer");
            return false;
        }
        *out_error_ = std::move(p_error);
        *out_exists_ = std::move(p_exists);
        mojo::internal::SyncMessageResponseSetup::SetCurrentSyncResponseMessage(
            message);
        *result_ = true;
        return true;
    }

    class Directory_Exists_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        Directory_Exists_ForwardToCallback(
            const Directory::ExistsCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        Directory::ExistsCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(Directory_Exists_ForwardToCallback);
    };
    bool Directory_Exists_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::Directory_Exists_ResponseParams_Data* params = reinterpret_cast<internal::Directory_Exists_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::filesystem::mojom::FileError p_error {};
        bool p_exists {};
        Directory_Exists_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadError(&p_error))
            success = false;
        p_exists = input_data_view.exists();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Directory::Exists response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_error),
                std::move(p_exists));
        }
        return true;
    }
    class Directory_IsWritable_HandleSyncResponse
        : public mojo::MessageReceiver {
    public:
        Directory_IsWritable_HandleSyncResponse(
            scoped_refptr<mojo::AssociatedGroupController> group_controller,
            bool* result, ::filesystem::mojom::FileError* out_error, bool* out_is_writable)
            : serialization_context_(std::move(group_controller))
            , result_(result)
            , out_error_(out_error)
            , out_is_writable_(out_is_writable)
        {
            DCHECK(!*result_);
        }
        bool Accept(mojo::Message* message) override;

    private:
        mojo::internal::SerializationContext serialization_context_;
        bool* result_;
        ::filesystem::mojom::FileError* out_error_;
        bool* out_is_writable_;
        DISALLOW_COPY_AND_ASSIGN(Directory_IsWritable_HandleSyncResponse);
    };
    bool Directory_IsWritable_HandleSyncResponse::Accept(
        mojo::Message* message)
    {
        internal::Directory_IsWritable_ResponseParams_Data* params = reinterpret_cast<internal::Directory_IsWritable_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::filesystem::mojom::FileError p_error {};
        bool p_is_writable {};
        Directory_IsWritable_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadError(&p_error))
            success = false;
        p_is_writable = input_data_view.is_writable();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Directory::IsWritable response deserializer");
            return false;
        }
        *out_error_ = std::move(p_error);
        *out_is_writable_ = std::move(p_is_writable);
        mojo::internal::SyncMessageResponseSetup::SetCurrentSyncResponseMessage(
            message);
        *result_ = true;
        return true;
    }

    class Directory_IsWritable_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        Directory_IsWritable_ForwardToCallback(
            const Directory::IsWritableCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        Directory::IsWritableCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(Directory_IsWritable_ForwardToCallback);
    };
    bool Directory_IsWritable_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::Directory_IsWritable_ResponseParams_Data* params = reinterpret_cast<internal::Directory_IsWritable_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::filesystem::mojom::FileError p_error {};
        bool p_is_writable {};
        Directory_IsWritable_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadError(&p_error))
            success = false;
        p_is_writable = input_data_view.is_writable();
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Directory::IsWritable response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_error),
                std::move(p_is_writable));
        }
        return true;
    }
    class Directory_Flush_HandleSyncResponse
        : public mojo::MessageReceiver {
    public:
        Directory_Flush_HandleSyncResponse(
            scoped_refptr<mojo::AssociatedGroupController> group_controller,
            bool* result, ::filesystem::mojom::FileError* out_error)
            : serialization_context_(std::move(group_controller))
            , result_(result)
            , out_error_(out_error)
        {
            DCHECK(!*result_);
        }
        bool Accept(mojo::Message* message) override;

    private:
        mojo::internal::SerializationContext serialization_context_;
        bool* result_;
        ::filesystem::mojom::FileError* out_error_;
        DISALLOW_COPY_AND_ASSIGN(Directory_Flush_HandleSyncResponse);
    };
    bool Directory_Flush_HandleSyncResponse::Accept(
        mojo::Message* message)
    {
        internal::Directory_Flush_ResponseParams_Data* params = reinterpret_cast<internal::Directory_Flush_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::filesystem::mojom::FileError p_error {};
        Directory_Flush_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadError(&p_error))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Directory::Flush response deserializer");
            return false;
        }
        *out_error_ = std::move(p_error);
        mojo::internal::SyncMessageResponseSetup::SetCurrentSyncResponseMessage(
            message);
        *result_ = true;
        return true;
    }

    class Directory_Flush_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        Directory_Flush_ForwardToCallback(
            const Directory::FlushCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        Directory::FlushCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(Directory_Flush_ForwardToCallback);
    };
    bool Directory_Flush_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::Directory_Flush_ResponseParams_Data* params = reinterpret_cast<internal::Directory_Flush_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::filesystem::mojom::FileError p_error {};
        Directory_Flush_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadError(&p_error))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Directory::Flush response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_error));
        }
        return true;
    }
    class Directory_StatFile_HandleSyncResponse
        : public mojo::MessageReceiver {
    public:
        Directory_StatFile_HandleSyncResponse(
            scoped_refptr<mojo::AssociatedGroupController> group_controller,
            bool* result, ::filesystem::mojom::FileError* out_error, ::filesystem::mojom::FileInformationPtr* out_file_information)
            : serialization_context_(std::move(group_controller))
            , result_(result)
            , out_error_(out_error)
            , out_file_information_(out_file_information)
        {
            DCHECK(!*result_);
        }
        bool Accept(mojo::Message* message) override;

    private:
        mojo::internal::SerializationContext serialization_context_;
        bool* result_;
        ::filesystem::mojom::FileError* out_error_;
        ::filesystem::mojom::FileInformationPtr* out_file_information_;
        DISALLOW_COPY_AND_ASSIGN(Directory_StatFile_HandleSyncResponse);
    };
    bool Directory_StatFile_HandleSyncResponse::Accept(
        mojo::Message* message)
    {
        internal::Directory_StatFile_ResponseParams_Data* params = reinterpret_cast<internal::Directory_StatFile_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::filesystem::mojom::FileError p_error {};
        ::filesystem::mojom::FileInformationPtr p_file_information {};
        Directory_StatFile_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadError(&p_error))
            success = false;
        if (!input_data_view.ReadFileInformation(&p_file_information))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Directory::StatFile response deserializer");
            return false;
        }
        *out_error_ = std::move(p_error);
        *out_file_information_ = std::move(p_file_information);
        mojo::internal::SyncMessageResponseSetup::SetCurrentSyncResponseMessage(
            message);
        *result_ = true;
        return true;
    }

    class Directory_StatFile_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        Directory_StatFile_ForwardToCallback(
            const Directory::StatFileCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        Directory::StatFileCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(Directory_StatFile_ForwardToCallback);
    };
    bool Directory_StatFile_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::Directory_StatFile_ResponseParams_Data* params = reinterpret_cast<internal::Directory_StatFile_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::filesystem::mojom::FileError p_error {};
        ::filesystem::mojom::FileInformationPtr p_file_information {};
        Directory_StatFile_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadError(&p_error))
            success = false;
        if (!input_data_view.ReadFileInformation(&p_file_information))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Directory::StatFile response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_error),
                std::move(p_file_information));
        }
        return true;
    }
    class Directory_ReadEntireFile_HandleSyncResponse
        : public mojo::MessageReceiver {
    public:
        Directory_ReadEntireFile_HandleSyncResponse(
            scoped_refptr<mojo::AssociatedGroupController> group_controller,
            bool* result, ::filesystem::mojom::FileError* out_error, std::vector<uint8_t>* out_data)
            : serialization_context_(std::move(group_controller))
            , result_(result)
            , out_error_(out_error)
            , out_data_(out_data)
        {
            DCHECK(!*result_);
        }
        bool Accept(mojo::Message* message) override;

    private:
        mojo::internal::SerializationContext serialization_context_;
        bool* result_;
        ::filesystem::mojom::FileError* out_error_;
        std::vector<uint8_t>* out_data_;
        DISALLOW_COPY_AND_ASSIGN(Directory_ReadEntireFile_HandleSyncResponse);
    };
    bool Directory_ReadEntireFile_HandleSyncResponse::Accept(
        mojo::Message* message)
    {
        internal::Directory_ReadEntireFile_ResponseParams_Data* params = reinterpret_cast<internal::Directory_ReadEntireFile_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::filesystem::mojom::FileError p_error {};
        std::vector<uint8_t> p_data {};
        Directory_ReadEntireFile_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadError(&p_error))
            success = false;
        if (!input_data_view.ReadData(&p_data))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Directory::ReadEntireFile response deserializer");
            return false;
        }
        *out_error_ = std::move(p_error);
        *out_data_ = std::move(p_data);
        mojo::internal::SyncMessageResponseSetup::SetCurrentSyncResponseMessage(
            message);
        *result_ = true;
        return true;
    }

    class Directory_ReadEntireFile_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        Directory_ReadEntireFile_ForwardToCallback(
            const Directory::ReadEntireFileCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        Directory::ReadEntireFileCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(Directory_ReadEntireFile_ForwardToCallback);
    };
    bool Directory_ReadEntireFile_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::Directory_ReadEntireFile_ResponseParams_Data* params = reinterpret_cast<internal::Directory_ReadEntireFile_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::filesystem::mojom::FileError p_error {};
        std::vector<uint8_t> p_data {};
        Directory_ReadEntireFile_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadError(&p_error))
            success = false;
        if (!input_data_view.ReadData(&p_data))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Directory::ReadEntireFile response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_error),
                std::move(p_data));
        }
        return true;
    }
    class Directory_WriteFile_HandleSyncResponse
        : public mojo::MessageReceiver {
    public:
        Directory_WriteFile_HandleSyncResponse(
            scoped_refptr<mojo::AssociatedGroupController> group_controller,
            bool* result, ::filesystem::mojom::FileError* out_error)
            : serialization_context_(std::move(group_controller))
            , result_(result)
            , out_error_(out_error)
        {
            DCHECK(!*result_);
        }
        bool Accept(mojo::Message* message) override;

    private:
        mojo::internal::SerializationContext serialization_context_;
        bool* result_;
        ::filesystem::mojom::FileError* out_error_;
        DISALLOW_COPY_AND_ASSIGN(Directory_WriteFile_HandleSyncResponse);
    };
    bool Directory_WriteFile_HandleSyncResponse::Accept(
        mojo::Message* message)
    {
        internal::Directory_WriteFile_ResponseParams_Data* params = reinterpret_cast<internal::Directory_WriteFile_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::filesystem::mojom::FileError p_error {};
        Directory_WriteFile_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadError(&p_error))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Directory::WriteFile response deserializer");
            return false;
        }
        *out_error_ = std::move(p_error);
        mojo::internal::SyncMessageResponseSetup::SetCurrentSyncResponseMessage(
            message);
        *result_ = true;
        return true;
    }

    class Directory_WriteFile_ForwardToCallback
        : public mojo::MessageReceiver {
    public:
        Directory_WriteFile_ForwardToCallback(
            const Directory::WriteFileCallback& callback,
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
            : callback_(std::move(callback))
            , serialization_context_(std::move(group_controller))
        {
        }
        bool Accept(mojo::Message* message) override;

    private:
        Directory::WriteFileCallback callback_;
        mojo::internal::SerializationContext serialization_context_;
        DISALLOW_COPY_AND_ASSIGN(Directory_WriteFile_ForwardToCallback);
    };
    bool Directory_WriteFile_ForwardToCallback::Accept(
        mojo::Message* message)
    {
        internal::Directory_WriteFile_ResponseParams_Data* params = reinterpret_cast<internal::Directory_WriteFile_ResponseParams_Data*>(
            message->mutable_payload());

        (&serialization_context_)->handles.Swap((message)->mutable_handles());
        bool success = true;
        ::filesystem::mojom::FileError p_error {};
        Directory_WriteFile_ResponseParamsDataView input_data_view(params,
            &serialization_context_);

        if (!input_data_view.ReadError(&p_error))
            success = false;
        if (!success) {
            ReportValidationErrorForMessage(
                message,
                mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                "Directory::WriteFile response deserializer");
            return false;
        }
        if (!callback_.is_null()) {
            mojo::internal::MessageDispatchContext context(message);
            std::move(callback_).Run(
                std::move(p_error));
        }
        return true;
    }

    DirectoryProxy::DirectoryProxy(mojo::MessageReceiverWithResponder* receiver)
        : receiver_(receiver)
    {
    }
    bool DirectoryProxy::Read(
        ::filesystem::mojom::FileError* param_error, base::Optional<std::vector<::filesystem::mojom::DirectoryEntryPtr>>* param_directory_contents)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::filesystem::mojom::internal::Directory_Read_Params_Data);

        mojo::internal::RequestMessageBuilder builder(internal::kDirectory_Read_Name, size,
            mojo::Message::kFlagIsSync);

        auto params = ::filesystem::mojom::internal::Directory_Read_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());

        bool result = false;
        mojo::MessageReceiver* responder = new Directory_Read_HandleSyncResponse(
            group_controller_, &result, param_error, param_directory_contents);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
        return result;
    }

    void DirectoryProxy::Read(
        const ReadCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::filesystem::mojom::internal::Directory_Read_Params_Data);
        mojo::internal::RequestMessageBuilder builder(internal::kDirectory_Read_Name, size);

        auto params = ::filesystem::mojom::internal::Directory_Read_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new Directory_Read_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    bool DirectoryProxy::OpenFile(
        const std::string& param_path, ::filesystem::mojom::FileRequest param_file, uint32_t param_open_flags, ::filesystem::mojom::FileError* param_error)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::filesystem::mojom::internal::Directory_OpenFile_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            param_path, &serialization_context);

        mojo::internal::RequestMessageBuilder builder(internal::kDirectory_OpenFile_Name, size,
            mojo::Message::kFlagIsSync);

        auto params = ::filesystem::mojom::internal::Directory_OpenFile_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->path)::BaseType* path_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            param_path, builder.buffer(), &path_ptr, &serialization_context);
        params->path.Set(path_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->path.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null path in Directory.OpenFile request");
        mojo::internal::Serialize<::filesystem::mojom::FileRequestDataView>(
            param_file, &params->file, &serialization_context);
        params->open_flags = param_open_flags;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());

        bool result = false;
        mojo::MessageReceiver* responder = new Directory_OpenFile_HandleSyncResponse(
            group_controller_, &result, param_error);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
        return result;
    }

    void DirectoryProxy::OpenFile(
        const std::string& in_path, ::filesystem::mojom::FileRequest in_file, uint32_t in_open_flags, const OpenFileCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::filesystem::mojom::internal::Directory_OpenFile_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_path, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kDirectory_OpenFile_Name, size);

        auto params = ::filesystem::mojom::internal::Directory_OpenFile_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->path)::BaseType* path_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_path, builder.buffer(), &path_ptr, &serialization_context);
        params->path.Set(path_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->path.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null path in Directory.OpenFile request");
        mojo::internal::Serialize<::filesystem::mojom::FileRequestDataView>(
            in_file, &params->file, &serialization_context);
        params->open_flags = in_open_flags;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new Directory_OpenFile_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    bool DirectoryProxy::OpenFileHandle(
        const std::string& param_path, uint32_t param_open_flags, ::filesystem::mojom::FileError* param_error, base::File* param_file_handle)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::filesystem::mojom::internal::Directory_OpenFileHandle_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            param_path, &serialization_context);

        mojo::internal::RequestMessageBuilder builder(internal::kDirectory_OpenFileHandle_Name, size,
            mojo::Message::kFlagIsSync);

        auto params = ::filesystem::mojom::internal::Directory_OpenFileHandle_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->path)::BaseType* path_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            param_path, builder.buffer(), &path_ptr, &serialization_context);
        params->path.Set(path_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->path.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null path in Directory.OpenFileHandle request");
        params->open_flags = param_open_flags;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());

        bool result = false;
        mojo::MessageReceiver* responder = new Directory_OpenFileHandle_HandleSyncResponse(
            group_controller_, &result, param_error, param_file_handle);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
        return result;
    }

    void DirectoryProxy::OpenFileHandle(
        const std::string& in_path, uint32_t in_open_flags, const OpenFileHandleCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::filesystem::mojom::internal::Directory_OpenFileHandle_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_path, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kDirectory_OpenFileHandle_Name, size);

        auto params = ::filesystem::mojom::internal::Directory_OpenFileHandle_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->path)::BaseType* path_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_path, builder.buffer(), &path_ptr, &serialization_context);
        params->path.Set(path_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->path.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null path in Directory.OpenFileHandle request");
        params->open_flags = in_open_flags;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new Directory_OpenFileHandle_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    bool DirectoryProxy::OpenFileHandles(
        std::vector<FileOpenDetailsPtr> param_files, std::vector<FileOpenResultPtr>* param_results)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::filesystem::mojom::internal::Directory_OpenFileHandles_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::filesystem::mojom::FileOpenDetailsDataView>>(
            param_files, &serialization_context);

        mojo::internal::RequestMessageBuilder builder(internal::kDirectory_OpenFileHandles_Name, size,
            mojo::Message::kFlagIsSync);

        auto params = ::filesystem::mojom::internal::Directory_OpenFileHandles_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->files)::BaseType* files_ptr;
        const mojo::internal::ContainerValidateParams files_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::filesystem::mojom::FileOpenDetailsDataView>>(
            param_files, builder.buffer(), &files_ptr, &files_validate_params,
            &serialization_context);
        params->files.Set(files_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->files.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null files in Directory.OpenFileHandles request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());

        bool result = false;
        mojo::MessageReceiver* responder = new Directory_OpenFileHandles_HandleSyncResponse(
            group_controller_, &result, param_results);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
        return result;
    }

    void DirectoryProxy::OpenFileHandles(
        std::vector<FileOpenDetailsPtr> in_files, const OpenFileHandlesCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::filesystem::mojom::internal::Directory_OpenFileHandles_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::filesystem::mojom::FileOpenDetailsDataView>>(
            in_files, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kDirectory_OpenFileHandles_Name, size);

        auto params = ::filesystem::mojom::internal::Directory_OpenFileHandles_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->files)::BaseType* files_ptr;
        const mojo::internal::ContainerValidateParams files_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::filesystem::mojom::FileOpenDetailsDataView>>(
            in_files, builder.buffer(), &files_ptr, &files_validate_params,
            &serialization_context);
        params->files.Set(files_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->files.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null files in Directory.OpenFileHandles request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new Directory_OpenFileHandles_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    bool DirectoryProxy::OpenDirectory(
        const std::string& param_path, DirectoryRequest param_directory, uint32_t param_open_flags, ::filesystem::mojom::FileError* param_error)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::filesystem::mojom::internal::Directory_OpenDirectory_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            param_path, &serialization_context);

        mojo::internal::RequestMessageBuilder builder(internal::kDirectory_OpenDirectory_Name, size,
            mojo::Message::kFlagIsSync);

        auto params = ::filesystem::mojom::internal::Directory_OpenDirectory_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->path)::BaseType* path_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            param_path, builder.buffer(), &path_ptr, &serialization_context);
        params->path.Set(path_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->path.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null path in Directory.OpenDirectory request");
        mojo::internal::Serialize<::filesystem::mojom::DirectoryRequestDataView>(
            param_directory, &params->directory, &serialization_context);
        params->open_flags = param_open_flags;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());

        bool result = false;
        mojo::MessageReceiver* responder = new Directory_OpenDirectory_HandleSyncResponse(
            group_controller_, &result, param_error);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
        return result;
    }

    void DirectoryProxy::OpenDirectory(
        const std::string& in_path, DirectoryRequest in_directory, uint32_t in_open_flags, const OpenDirectoryCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::filesystem::mojom::internal::Directory_OpenDirectory_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_path, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kDirectory_OpenDirectory_Name, size);

        auto params = ::filesystem::mojom::internal::Directory_OpenDirectory_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->path)::BaseType* path_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_path, builder.buffer(), &path_ptr, &serialization_context);
        params->path.Set(path_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->path.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null path in Directory.OpenDirectory request");
        mojo::internal::Serialize<::filesystem::mojom::DirectoryRequestDataView>(
            in_directory, &params->directory, &serialization_context);
        params->open_flags = in_open_flags;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new Directory_OpenDirectory_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    bool DirectoryProxy::Rename(
        const std::string& param_path, const std::string& param_new_path, ::filesystem::mojom::FileError* param_error)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::filesystem::mojom::internal::Directory_Rename_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            param_path, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            param_new_path, &serialization_context);

        mojo::internal::RequestMessageBuilder builder(internal::kDirectory_Rename_Name, size,
            mojo::Message::kFlagIsSync);

        auto params = ::filesystem::mojom::internal::Directory_Rename_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->path)::BaseType* path_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            param_path, builder.buffer(), &path_ptr, &serialization_context);
        params->path.Set(path_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->path.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null path in Directory.Rename request");
        typename decltype(params->new_path)::BaseType* new_path_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            param_new_path, builder.buffer(), &new_path_ptr, &serialization_context);
        params->new_path.Set(new_path_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->new_path.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null new_path in Directory.Rename request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());

        bool result = false;
        mojo::MessageReceiver* responder = new Directory_Rename_HandleSyncResponse(
            group_controller_, &result, param_error);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
        return result;
    }

    void DirectoryProxy::Rename(
        const std::string& in_path, const std::string& in_new_path, const RenameCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::filesystem::mojom::internal::Directory_Rename_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_path, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_new_path, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kDirectory_Rename_Name, size);

        auto params = ::filesystem::mojom::internal::Directory_Rename_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->path)::BaseType* path_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_path, builder.buffer(), &path_ptr, &serialization_context);
        params->path.Set(path_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->path.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null path in Directory.Rename request");
        typename decltype(params->new_path)::BaseType* new_path_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_new_path, builder.buffer(), &new_path_ptr, &serialization_context);
        params->new_path.Set(new_path_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->new_path.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null new_path in Directory.Rename request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new Directory_Rename_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    bool DirectoryProxy::Delete(
        const std::string& param_path, uint32_t param_delete_flags, ::filesystem::mojom::FileError* param_error)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::filesystem::mojom::internal::Directory_Delete_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            param_path, &serialization_context);

        mojo::internal::RequestMessageBuilder builder(internal::kDirectory_Delete_Name, size,
            mojo::Message::kFlagIsSync);

        auto params = ::filesystem::mojom::internal::Directory_Delete_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->path)::BaseType* path_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            param_path, builder.buffer(), &path_ptr, &serialization_context);
        params->path.Set(path_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->path.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null path in Directory.Delete request");
        params->delete_flags = param_delete_flags;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());

        bool result = false;
        mojo::MessageReceiver* responder = new Directory_Delete_HandleSyncResponse(
            group_controller_, &result, param_error);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
        return result;
    }

    void DirectoryProxy::Delete(
        const std::string& in_path, uint32_t in_delete_flags, const DeleteCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::filesystem::mojom::internal::Directory_Delete_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_path, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kDirectory_Delete_Name, size);

        auto params = ::filesystem::mojom::internal::Directory_Delete_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->path)::BaseType* path_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_path, builder.buffer(), &path_ptr, &serialization_context);
        params->path.Set(path_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->path.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null path in Directory.Delete request");
        params->delete_flags = in_delete_flags;
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new Directory_Delete_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    bool DirectoryProxy::Exists(
        const std::string& param_path, ::filesystem::mojom::FileError* param_error, bool* param_exists)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::filesystem::mojom::internal::Directory_Exists_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            param_path, &serialization_context);

        mojo::internal::RequestMessageBuilder builder(internal::kDirectory_Exists_Name, size,
            mojo::Message::kFlagIsSync);

        auto params = ::filesystem::mojom::internal::Directory_Exists_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->path)::BaseType* path_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            param_path, builder.buffer(), &path_ptr, &serialization_context);
        params->path.Set(path_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->path.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null path in Directory.Exists request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());

        bool result = false;
        mojo::MessageReceiver* responder = new Directory_Exists_HandleSyncResponse(
            group_controller_, &result, param_error, param_exists);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
        return result;
    }

    void DirectoryProxy::Exists(
        const std::string& in_path, const ExistsCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::filesystem::mojom::internal::Directory_Exists_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_path, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kDirectory_Exists_Name, size);

        auto params = ::filesystem::mojom::internal::Directory_Exists_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->path)::BaseType* path_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_path, builder.buffer(), &path_ptr, &serialization_context);
        params->path.Set(path_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->path.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null path in Directory.Exists request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new Directory_Exists_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    bool DirectoryProxy::IsWritable(
        const std::string& param_path, ::filesystem::mojom::FileError* param_error, bool* param_is_writable)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::filesystem::mojom::internal::Directory_IsWritable_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            param_path, &serialization_context);

        mojo::internal::RequestMessageBuilder builder(internal::kDirectory_IsWritable_Name, size,
            mojo::Message::kFlagIsSync);

        auto params = ::filesystem::mojom::internal::Directory_IsWritable_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->path)::BaseType* path_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            param_path, builder.buffer(), &path_ptr, &serialization_context);
        params->path.Set(path_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->path.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null path in Directory.IsWritable request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());

        bool result = false;
        mojo::MessageReceiver* responder = new Directory_IsWritable_HandleSyncResponse(
            group_controller_, &result, param_error, param_is_writable);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
        return result;
    }

    void DirectoryProxy::IsWritable(
        const std::string& in_path, const IsWritableCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::filesystem::mojom::internal::Directory_IsWritable_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_path, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kDirectory_IsWritable_Name, size);

        auto params = ::filesystem::mojom::internal::Directory_IsWritable_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->path)::BaseType* path_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_path, builder.buffer(), &path_ptr, &serialization_context);
        params->path.Set(path_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->path.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null path in Directory.IsWritable request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new Directory_IsWritable_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    bool DirectoryProxy::Flush(
        ::filesystem::mojom::FileError* param_error)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::filesystem::mojom::internal::Directory_Flush_Params_Data);

        mojo::internal::RequestMessageBuilder builder(internal::kDirectory_Flush_Name, size,
            mojo::Message::kFlagIsSync);

        auto params = ::filesystem::mojom::internal::Directory_Flush_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());

        bool result = false;
        mojo::MessageReceiver* responder = new Directory_Flush_HandleSyncResponse(
            group_controller_, &result, param_error);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
        return result;
    }

    void DirectoryProxy::Flush(
        const FlushCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::filesystem::mojom::internal::Directory_Flush_Params_Data);
        mojo::internal::RequestMessageBuilder builder(internal::kDirectory_Flush_Name, size);

        auto params = ::filesystem::mojom::internal::Directory_Flush_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new Directory_Flush_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    bool DirectoryProxy::StatFile(
        const std::string& param_path, ::filesystem::mojom::FileError* param_error, ::filesystem::mojom::FileInformationPtr* param_file_information)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::filesystem::mojom::internal::Directory_StatFile_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            param_path, &serialization_context);

        mojo::internal::RequestMessageBuilder builder(internal::kDirectory_StatFile_Name, size,
            mojo::Message::kFlagIsSync);

        auto params = ::filesystem::mojom::internal::Directory_StatFile_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->path)::BaseType* path_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            param_path, builder.buffer(), &path_ptr, &serialization_context);
        params->path.Set(path_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->path.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null path in Directory.StatFile request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());

        bool result = false;
        mojo::MessageReceiver* responder = new Directory_StatFile_HandleSyncResponse(
            group_controller_, &result, param_error, param_file_information);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
        return result;
    }

    void DirectoryProxy::StatFile(
        const std::string& in_path, const StatFileCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::filesystem::mojom::internal::Directory_StatFile_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_path, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kDirectory_StatFile_Name, size);

        auto params = ::filesystem::mojom::internal::Directory_StatFile_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->path)::BaseType* path_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_path, builder.buffer(), &path_ptr, &serialization_context);
        params->path.Set(path_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->path.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null path in Directory.StatFile request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new Directory_StatFile_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }

    void DirectoryProxy::Clone(
        DirectoryRequest in_directory)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::filesystem::mojom::internal::Directory_Clone_Params_Data);
        mojo::internal::MessageBuilder builder(internal::kDirectory_Clone_Name, size);

        auto params = ::filesystem::mojom::internal::Directory_Clone_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::filesystem::mojom::DirectoryRequestDataView>(
            in_directory, &params->directory, &serialization_context);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            !mojo::internal::IsHandleOrInterfaceValid(params->directory),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_INVALID_HANDLE,
            "invalid directory in Directory.Clone request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        bool ok = receiver_->Accept(builder.message());
        // This return value may be ignored as !ok implies the Connector has
        // encountered an error, which will be visible through other means.
        ALLOW_UNUSED_LOCAL(ok);
    }
    bool DirectoryProxy::ReadEntireFile(
        const std::string& param_path, ::filesystem::mojom::FileError* param_error, std::vector<uint8_t>* param_data)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::filesystem::mojom::internal::Directory_ReadEntireFile_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            param_path, &serialization_context);

        mojo::internal::RequestMessageBuilder builder(internal::kDirectory_ReadEntireFile_Name, size,
            mojo::Message::kFlagIsSync);

        auto params = ::filesystem::mojom::internal::Directory_ReadEntireFile_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->path)::BaseType* path_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            param_path, builder.buffer(), &path_ptr, &serialization_context);
        params->path.Set(path_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->path.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null path in Directory.ReadEntireFile request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());

        bool result = false;
        mojo::MessageReceiver* responder = new Directory_ReadEntireFile_HandleSyncResponse(
            group_controller_, &result, param_error, param_data);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
        return result;
    }

    void DirectoryProxy::ReadEntireFile(
        const std::string& in_path, const ReadEntireFileCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::filesystem::mojom::internal::Directory_ReadEntireFile_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_path, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kDirectory_ReadEntireFile_Name, size);

        auto params = ::filesystem::mojom::internal::Directory_ReadEntireFile_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->path)::BaseType* path_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_path, builder.buffer(), &path_ptr, &serialization_context);
        params->path.Set(path_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->path.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null path in Directory.ReadEntireFile request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new Directory_ReadEntireFile_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    bool DirectoryProxy::WriteFile(
        const std::string& param_path, const std::vector<uint8_t>& param_data, ::filesystem::mojom::FileError* param_error)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::filesystem::mojom::internal::Directory_WriteFile_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            param_path, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            param_data, &serialization_context);

        mojo::internal::RequestMessageBuilder builder(internal::kDirectory_WriteFile_Name, size,
            mojo::Message::kFlagIsSync);

        auto params = ::filesystem::mojom::internal::Directory_WriteFile_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->path)::BaseType* path_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            param_path, builder.buffer(), &path_ptr, &serialization_context);
        params->path.Set(path_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->path.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null path in Directory.WriteFile request");
        typename decltype(params->data)::BaseType* data_ptr;
        const mojo::internal::ContainerValidateParams data_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            param_data, builder.buffer(), &data_ptr, &data_validate_params,
            &serialization_context);
        params->data.Set(data_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->data.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null data in Directory.WriteFile request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());

        bool result = false;
        mojo::MessageReceiver* responder = new Directory_WriteFile_HandleSyncResponse(
            group_controller_, &result, param_error);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
        return result;
    }

    void DirectoryProxy::WriteFile(
        const std::string& in_path, const std::vector<uint8_t>& in_data, const WriteFileCallback& callback)
    {
        mojo::internal::SerializationContext serialization_context(
            group_controller_);
        size_t size = sizeof(::filesystem::mojom::internal::Directory_WriteFile_Params_Data);
        size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
            in_path, &serialization_context);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_data, &serialization_context);
        mojo::internal::RequestMessageBuilder builder(internal::kDirectory_WriteFile_Name, size);

        auto params = ::filesystem::mojom::internal::Directory_WriteFile_Params_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->path)::BaseType* path_ptr;
        mojo::internal::Serialize<mojo::StringDataView>(
            in_path, builder.buffer(), &path_ptr, &serialization_context);
        params->path.Set(path_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->path.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null path in Directory.WriteFile request");
        typename decltype(params->data)::BaseType* data_ptr;
        const mojo::internal::ContainerValidateParams data_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_data, builder.buffer(), &data_ptr, &data_validate_params,
            &serialization_context);
        params->data.Set(data_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->data.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null data in Directory.WriteFile request");
        (&serialization_context)->handles.Swap(builder.message()->mutable_handles());
        mojo::MessageReceiver* responder = new Directory_WriteFile_ForwardToCallback(
            std::move(callback), group_controller_);
        if (!receiver_->AcceptWithResponder(builder.message(), responder))
            delete responder;
    }
    class Directory_Read_ProxyToResponder {
    public:
        static Directory::ReadCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<Directory_Read_ProxyToResponder> proxy(
                new Directory_Read_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&Directory_Read_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~Directory_Read_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "Directory::Read() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        Directory_Read_ProxyToResponder(
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
            ::filesystem::mojom::FileError in_error, base::Optional<std::vector<::filesystem::mojom::DirectoryEntryPtr>> in_directory_contents);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(Directory_Read_ProxyToResponder);
    };

    void Directory_Read_ProxyToResponder::Run(
        ::filesystem::mojom::FileError in_error, base::Optional<std::vector<::filesystem::mojom::DirectoryEntryPtr>> in_directory_contents)
    {
        size_t size = sizeof(::filesystem::mojom::internal::Directory_Read_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::filesystem::mojom::DirectoryEntryDataView>>(
            in_directory_contents, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kDirectory_Read_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::filesystem::mojom::internal::Directory_Read_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::filesystem::mojom::FileError>(
            in_error, &params->error);
        typename decltype(params->directory_contents)::BaseType* directory_contents_ptr;
        const mojo::internal::ContainerValidateParams directory_contents_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::filesystem::mojom::DirectoryEntryDataView>>(
            in_directory_contents, builder.buffer(), &directory_contents_ptr, &directory_contents_validate_params,
            &serialization_context_);
        params->directory_contents.Set(directory_contents_ptr);
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class Directory_OpenFile_ProxyToResponder {
    public:
        static Directory::OpenFileCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<Directory_OpenFile_ProxyToResponder> proxy(
                new Directory_OpenFile_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&Directory_OpenFile_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~Directory_OpenFile_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "Directory::OpenFile() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        Directory_OpenFile_ProxyToResponder(
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
            ::filesystem::mojom::FileError in_error);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(Directory_OpenFile_ProxyToResponder);
    };

    void Directory_OpenFile_ProxyToResponder::Run(
        ::filesystem::mojom::FileError in_error)
    {
        size_t size = sizeof(::filesystem::mojom::internal::Directory_OpenFile_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kDirectory_OpenFile_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::filesystem::mojom::internal::Directory_OpenFile_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::filesystem::mojom::FileError>(
            in_error, &params->error);
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class Directory_OpenFileHandle_ProxyToResponder {
    public:
        static Directory::OpenFileHandleCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<Directory_OpenFileHandle_ProxyToResponder> proxy(
                new Directory_OpenFileHandle_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&Directory_OpenFileHandle_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~Directory_OpenFileHandle_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "Directory::OpenFileHandle() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        Directory_OpenFileHandle_ProxyToResponder(
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
            ::filesystem::mojom::FileError in_error, base::File in_file_handle);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(Directory_OpenFileHandle_ProxyToResponder);
    };

    void Directory_OpenFileHandle_ProxyToResponder::Run(
        ::filesystem::mojom::FileError in_error, base::File in_file_handle)
    {
        size_t size = sizeof(::filesystem::mojom::internal::Directory_OpenFileHandle_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::FileDataView>(
            in_file_handle, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kDirectory_OpenFileHandle_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::filesystem::mojom::internal::Directory_OpenFileHandle_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::filesystem::mojom::FileError>(
            in_error, &params->error);
        typename decltype(params->file_handle)::BaseType* file_handle_ptr;
        mojo::internal::Serialize<::mojo::common::mojom::FileDataView>(
            in_file_handle, builder.buffer(), &file_handle_ptr, &serialization_context_);
        params->file_handle.Set(file_handle_ptr);
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class Directory_OpenFileHandles_ProxyToResponder {
    public:
        static Directory::OpenFileHandlesCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<Directory_OpenFileHandles_ProxyToResponder> proxy(
                new Directory_OpenFileHandles_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&Directory_OpenFileHandles_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~Directory_OpenFileHandles_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "Directory::OpenFileHandles() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        Directory_OpenFileHandles_ProxyToResponder(
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
            std::vector<FileOpenResultPtr> in_results);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(Directory_OpenFileHandles_ProxyToResponder);
    };

    void Directory_OpenFileHandles_ProxyToResponder::Run(
        std::vector<FileOpenResultPtr> in_results)
    {
        size_t size = sizeof(::filesystem::mojom::internal::Directory_OpenFileHandles_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<::filesystem::mojom::FileOpenResultDataView>>(
            in_results, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kDirectory_OpenFileHandles_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::filesystem::mojom::internal::Directory_OpenFileHandles_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        typename decltype(params->results)::BaseType* results_ptr;
        const mojo::internal::ContainerValidateParams results_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<::filesystem::mojom::FileOpenResultDataView>>(
            in_results, builder.buffer(), &results_ptr, &results_validate_params,
            &serialization_context_);
        params->results.Set(results_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->results.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null results in Directory.OpenFileHandles response");
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class Directory_OpenDirectory_ProxyToResponder {
    public:
        static Directory::OpenDirectoryCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<Directory_OpenDirectory_ProxyToResponder> proxy(
                new Directory_OpenDirectory_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&Directory_OpenDirectory_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~Directory_OpenDirectory_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "Directory::OpenDirectory() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        Directory_OpenDirectory_ProxyToResponder(
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
            ::filesystem::mojom::FileError in_error);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(Directory_OpenDirectory_ProxyToResponder);
    };

    void Directory_OpenDirectory_ProxyToResponder::Run(
        ::filesystem::mojom::FileError in_error)
    {
        size_t size = sizeof(::filesystem::mojom::internal::Directory_OpenDirectory_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kDirectory_OpenDirectory_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::filesystem::mojom::internal::Directory_OpenDirectory_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::filesystem::mojom::FileError>(
            in_error, &params->error);
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class Directory_Rename_ProxyToResponder {
    public:
        static Directory::RenameCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<Directory_Rename_ProxyToResponder> proxy(
                new Directory_Rename_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&Directory_Rename_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~Directory_Rename_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "Directory::Rename() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        Directory_Rename_ProxyToResponder(
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
            ::filesystem::mojom::FileError in_error);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(Directory_Rename_ProxyToResponder);
    };

    void Directory_Rename_ProxyToResponder::Run(
        ::filesystem::mojom::FileError in_error)
    {
        size_t size = sizeof(::filesystem::mojom::internal::Directory_Rename_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kDirectory_Rename_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::filesystem::mojom::internal::Directory_Rename_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::filesystem::mojom::FileError>(
            in_error, &params->error);
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class Directory_Delete_ProxyToResponder {
    public:
        static Directory::DeleteCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<Directory_Delete_ProxyToResponder> proxy(
                new Directory_Delete_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&Directory_Delete_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~Directory_Delete_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "Directory::Delete() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        Directory_Delete_ProxyToResponder(
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
            ::filesystem::mojom::FileError in_error);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(Directory_Delete_ProxyToResponder);
    };

    void Directory_Delete_ProxyToResponder::Run(
        ::filesystem::mojom::FileError in_error)
    {
        size_t size = sizeof(::filesystem::mojom::internal::Directory_Delete_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kDirectory_Delete_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::filesystem::mojom::internal::Directory_Delete_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::filesystem::mojom::FileError>(
            in_error, &params->error);
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class Directory_Exists_ProxyToResponder {
    public:
        static Directory::ExistsCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<Directory_Exists_ProxyToResponder> proxy(
                new Directory_Exists_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&Directory_Exists_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~Directory_Exists_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "Directory::Exists() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        Directory_Exists_ProxyToResponder(
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
            ::filesystem::mojom::FileError in_error, bool in_exists);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(Directory_Exists_ProxyToResponder);
    };

    void Directory_Exists_ProxyToResponder::Run(
        ::filesystem::mojom::FileError in_error, bool in_exists)
    {
        size_t size = sizeof(::filesystem::mojom::internal::Directory_Exists_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kDirectory_Exists_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::filesystem::mojom::internal::Directory_Exists_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::filesystem::mojom::FileError>(
            in_error, &params->error);
        params->exists = in_exists;
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class Directory_IsWritable_ProxyToResponder {
    public:
        static Directory::IsWritableCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<Directory_IsWritable_ProxyToResponder> proxy(
                new Directory_IsWritable_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&Directory_IsWritable_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~Directory_IsWritable_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "Directory::IsWritable() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        Directory_IsWritable_ProxyToResponder(
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
            ::filesystem::mojom::FileError in_error, bool in_is_writable);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(Directory_IsWritable_ProxyToResponder);
    };

    void Directory_IsWritable_ProxyToResponder::Run(
        ::filesystem::mojom::FileError in_error, bool in_is_writable)
    {
        size_t size = sizeof(::filesystem::mojom::internal::Directory_IsWritable_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kDirectory_IsWritable_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::filesystem::mojom::internal::Directory_IsWritable_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::filesystem::mojom::FileError>(
            in_error, &params->error);
        params->is_writable = in_is_writable;
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class Directory_Flush_ProxyToResponder {
    public:
        static Directory::FlushCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<Directory_Flush_ProxyToResponder> proxy(
                new Directory_Flush_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&Directory_Flush_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~Directory_Flush_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "Directory::Flush() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        Directory_Flush_ProxyToResponder(
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
            ::filesystem::mojom::FileError in_error);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(Directory_Flush_ProxyToResponder);
    };

    void Directory_Flush_ProxyToResponder::Run(
        ::filesystem::mojom::FileError in_error)
    {
        size_t size = sizeof(::filesystem::mojom::internal::Directory_Flush_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kDirectory_Flush_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::filesystem::mojom::internal::Directory_Flush_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::filesystem::mojom::FileError>(
            in_error, &params->error);
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class Directory_StatFile_ProxyToResponder {
    public:
        static Directory::StatFileCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<Directory_StatFile_ProxyToResponder> proxy(
                new Directory_StatFile_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&Directory_StatFile_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~Directory_StatFile_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "Directory::StatFile() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        Directory_StatFile_ProxyToResponder(
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
            ::filesystem::mojom::FileError in_error, ::filesystem::mojom::FileInformationPtr in_file_information);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(Directory_StatFile_ProxyToResponder);
    };

    void Directory_StatFile_ProxyToResponder::Run(
        ::filesystem::mojom::FileError in_error, ::filesystem::mojom::FileInformationPtr in_file_information)
    {
        size_t size = sizeof(::filesystem::mojom::internal::Directory_StatFile_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<::filesystem::mojom::FileInformationDataView>(
            in_file_information, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kDirectory_StatFile_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::filesystem::mojom::internal::Directory_StatFile_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::filesystem::mojom::FileError>(
            in_error, &params->error);
        typename decltype(params->file_information)::BaseType* file_information_ptr;
        mojo::internal::Serialize<::filesystem::mojom::FileInformationDataView>(
            in_file_information, builder.buffer(), &file_information_ptr, &serialization_context_);
        params->file_information.Set(file_information_ptr);
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class Directory_ReadEntireFile_ProxyToResponder {
    public:
        static Directory::ReadEntireFileCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<Directory_ReadEntireFile_ProxyToResponder> proxy(
                new Directory_ReadEntireFile_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&Directory_ReadEntireFile_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~Directory_ReadEntireFile_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "Directory::ReadEntireFile() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        Directory_ReadEntireFile_ProxyToResponder(
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
            ::filesystem::mojom::FileError in_error, const std::vector<uint8_t>& in_data);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(Directory_ReadEntireFile_ProxyToResponder);
    };

    void Directory_ReadEntireFile_ProxyToResponder::Run(
        ::filesystem::mojom::FileError in_error, const std::vector<uint8_t>& in_data)
    {
        size_t size = sizeof(::filesystem::mojom::internal::Directory_ReadEntireFile_ResponseParams_Data);
        size += mojo::internal::PrepareToSerialize<mojo::ArrayDataView<uint8_t>>(
            in_data, &serialization_context_);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kDirectory_ReadEntireFile_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::filesystem::mojom::internal::Directory_ReadEntireFile_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::filesystem::mojom::FileError>(
            in_error, &params->error);
        typename decltype(params->data)::BaseType* data_ptr;
        const mojo::internal::ContainerValidateParams data_validate_params(
            0, false, nullptr);
        mojo::internal::Serialize<mojo::ArrayDataView<uint8_t>>(
            in_data, builder.buffer(), &data_ptr, &data_validate_params,
            &serialization_context_);
        params->data.Set(data_ptr);
        MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
            params->data.is_null(),
            mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
            "null data in Directory.ReadEntireFile response");
        (&serialization_context_)->handles.Swap(builder.message()->mutable_handles());
        bool ok = responder_->Accept(builder.message());
        ALLOW_UNUSED_LOCAL(ok);
        // TODO(darin): !ok returned here indicates a malformed message, and that may
        // be good reason to close the connection. However, we don't have a way to do
        // that from here. We should add a way.
        delete responder_;
        responder_ = nullptr;
    }
    class Directory_WriteFile_ProxyToResponder {
    public:
        static Directory::WriteFileCallback CreateCallback(
            uint64_t request_id,
            bool is_sync,
            mojo::MessageReceiverWithStatus* responder,
            scoped_refptr<mojo::AssociatedGroupController>
                group_controller)
        {
            std::unique_ptr<Directory_WriteFile_ProxyToResponder> proxy(
                new Directory_WriteFile_ProxyToResponder(
                    request_id, is_sync, responder, group_controller));
            return base::Bind(&Directory_WriteFile_ProxyToResponder::Run,
                base::Passed(&proxy));
        }

        ~Directory_WriteFile_ProxyToResponder()
        {
#if DCHECK_IS_ON()
            if (responder_) {
                // Is the Service destroying the callback without running it
                // and without first closing the pipe?
                responder_->DCheckInvalid("The callback passed to "
                                          "Directory::WriteFile() was never run.");
            }
#endif
            // If the Callback was dropped then deleting the responder will close
            // the pipe so the calling application knows to stop waiting for a reply.
            delete responder_;
        }

    private:
        Directory_WriteFile_ProxyToResponder(
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
            ::filesystem::mojom::FileError in_error);

        uint64_t request_id_;
        bool is_sync_;
        mojo::MessageReceiverWithStatus* responder_;
        // TODO(yzshen): maybe I should use a ref to the original one?
        mojo::internal::SerializationContext serialization_context_;

        DISALLOW_COPY_AND_ASSIGN(Directory_WriteFile_ProxyToResponder);
    };

    void Directory_WriteFile_ProxyToResponder::Run(
        ::filesystem::mojom::FileError in_error)
    {
        size_t size = sizeof(::filesystem::mojom::internal::Directory_WriteFile_ResponseParams_Data);
        mojo::internal::ResponseMessageBuilder builder(
            internal::kDirectory_WriteFile_Name, size, request_id_,
            is_sync_ ? mojo::Message::kFlagIsSync : 0);
        auto params = ::filesystem::mojom::internal::Directory_WriteFile_ResponseParams_Data::New(builder.buffer());
        ALLOW_UNUSED_LOCAL(params);
        mojo::internal::Serialize<::filesystem::mojom::FileError>(
            in_error, &params->error);
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
    bool DirectoryStubDispatch::Accept(
        Directory* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message)
    {
        switch (message->header()->name) {
        case internal::kDirectory_Read_Name: {
            break;
        }
        case internal::kDirectory_OpenFile_Name: {
            break;
        }
        case internal::kDirectory_OpenFileHandle_Name: {
            break;
        }
        case internal::kDirectory_OpenFileHandles_Name: {
            break;
        }
        case internal::kDirectory_OpenDirectory_Name: {
            break;
        }
        case internal::kDirectory_Rename_Name: {
            break;
        }
        case internal::kDirectory_Delete_Name: {
            break;
        }
        case internal::kDirectory_Exists_Name: {
            break;
        }
        case internal::kDirectory_IsWritable_Name: {
            break;
        }
        case internal::kDirectory_Flush_Name: {
            break;
        }
        case internal::kDirectory_StatFile_Name: {
            break;
        }
        case internal::kDirectory_Clone_Name: {
            internal::Directory_Clone_Params_Data* params = reinterpret_cast<internal::Directory_Clone_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            DirectoryRequest p_directory {};
            Directory_Clone_ParamsDataView input_data_view(params,
                context);

            p_directory = input_data_view.TakeDirectory<decltype(p_directory)>();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Directory::Clone deserializer");
                return false;
            }
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Directory::Clone");
            mojo::internal::MessageDispatchContext context(message);
            impl->Clone(
                std::move(p_directory));
            return true;
        }
        case internal::kDirectory_ReadEntireFile_Name: {
            break;
        }
        case internal::kDirectory_WriteFile_Name: {
            break;
        }
        }
        return false;
    }

    // static
    bool DirectoryStubDispatch::AcceptWithResponder(
        Directory* impl,
        mojo::internal::SerializationContext* context,
        mojo::Message* message,
        mojo::MessageReceiverWithStatus* responder)
    {
        switch (message->header()->name) {
        case internal::kDirectory_Read_Name: {
            internal::Directory_Read_Params_Data* params = reinterpret_cast<internal::Directory_Read_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            Directory_Read_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Directory::Read deserializer");
                return false;
            }
            Directory::ReadCallback callback = Directory_Read_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Directory::Read");
            mojo::internal::MessageDispatchContext context(message);
            impl->Read(std::move(callback));
            return true;
        }
        case internal::kDirectory_OpenFile_Name: {
            internal::Directory_OpenFile_Params_Data* params = reinterpret_cast<internal::Directory_OpenFile_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_path {};
            ::filesystem::mojom::FileRequest p_file {};
            uint32_t p_open_flags {};
            Directory_OpenFile_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadPath(&p_path))
                success = false;
            p_file = input_data_view.TakeFile<decltype(p_file)>();
            p_open_flags = input_data_view.open_flags();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Directory::OpenFile deserializer");
                return false;
            }
            Directory::OpenFileCallback callback = Directory_OpenFile_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Directory::OpenFile");
            mojo::internal::MessageDispatchContext context(message);
            impl->OpenFile(
                std::move(p_path),
                std::move(p_file),
                std::move(p_open_flags), std::move(callback));
            return true;
        }
        case internal::kDirectory_OpenFileHandle_Name: {
            internal::Directory_OpenFileHandle_Params_Data* params = reinterpret_cast<internal::Directory_OpenFileHandle_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_path {};
            uint32_t p_open_flags {};
            Directory_OpenFileHandle_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadPath(&p_path))
                success = false;
            p_open_flags = input_data_view.open_flags();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Directory::OpenFileHandle deserializer");
                return false;
            }
            Directory::OpenFileHandleCallback callback = Directory_OpenFileHandle_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Directory::OpenFileHandle");
            mojo::internal::MessageDispatchContext context(message);
            impl->OpenFileHandle(
                std::move(p_path),
                std::move(p_open_flags), std::move(callback));
            return true;
        }
        case internal::kDirectory_OpenFileHandles_Name: {
            internal::Directory_OpenFileHandles_Params_Data* params = reinterpret_cast<internal::Directory_OpenFileHandles_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::vector<FileOpenDetailsPtr> p_files {};
            Directory_OpenFileHandles_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadFiles(&p_files))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Directory::OpenFileHandles deserializer");
                return false;
            }
            Directory::OpenFileHandlesCallback callback = Directory_OpenFileHandles_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Directory::OpenFileHandles");
            mojo::internal::MessageDispatchContext context(message);
            impl->OpenFileHandles(
                std::move(p_files), std::move(callback));
            return true;
        }
        case internal::kDirectory_OpenDirectory_Name: {
            internal::Directory_OpenDirectory_Params_Data* params = reinterpret_cast<internal::Directory_OpenDirectory_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_path {};
            DirectoryRequest p_directory {};
            uint32_t p_open_flags {};
            Directory_OpenDirectory_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadPath(&p_path))
                success = false;
            p_directory = input_data_view.TakeDirectory<decltype(p_directory)>();
            p_open_flags = input_data_view.open_flags();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Directory::OpenDirectory deserializer");
                return false;
            }
            Directory::OpenDirectoryCallback callback = Directory_OpenDirectory_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Directory::OpenDirectory");
            mojo::internal::MessageDispatchContext context(message);
            impl->OpenDirectory(
                std::move(p_path),
                std::move(p_directory),
                std::move(p_open_flags), std::move(callback));
            return true;
        }
        case internal::kDirectory_Rename_Name: {
            internal::Directory_Rename_Params_Data* params = reinterpret_cast<internal::Directory_Rename_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_path {};
            std::string p_new_path {};
            Directory_Rename_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadPath(&p_path))
                success = false;
            if (!input_data_view.ReadNewPath(&p_new_path))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Directory::Rename deserializer");
                return false;
            }
            Directory::RenameCallback callback = Directory_Rename_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Directory::Rename");
            mojo::internal::MessageDispatchContext context(message);
            impl->Rename(
                std::move(p_path),
                std::move(p_new_path), std::move(callback));
            return true;
        }
        case internal::kDirectory_Delete_Name: {
            internal::Directory_Delete_Params_Data* params = reinterpret_cast<internal::Directory_Delete_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_path {};
            uint32_t p_delete_flags {};
            Directory_Delete_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadPath(&p_path))
                success = false;
            p_delete_flags = input_data_view.delete_flags();
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Directory::Delete deserializer");
                return false;
            }
            Directory::DeleteCallback callback = Directory_Delete_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Directory::Delete");
            mojo::internal::MessageDispatchContext context(message);
            impl->Delete(
                std::move(p_path),
                std::move(p_delete_flags), std::move(callback));
            return true;
        }
        case internal::kDirectory_Exists_Name: {
            internal::Directory_Exists_Params_Data* params = reinterpret_cast<internal::Directory_Exists_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_path {};
            Directory_Exists_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadPath(&p_path))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Directory::Exists deserializer");
                return false;
            }
            Directory::ExistsCallback callback = Directory_Exists_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Directory::Exists");
            mojo::internal::MessageDispatchContext context(message);
            impl->Exists(
                std::move(p_path), std::move(callback));
            return true;
        }
        case internal::kDirectory_IsWritable_Name: {
            internal::Directory_IsWritable_Params_Data* params = reinterpret_cast<internal::Directory_IsWritable_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_path {};
            Directory_IsWritable_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadPath(&p_path))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Directory::IsWritable deserializer");
                return false;
            }
            Directory::IsWritableCallback callback = Directory_IsWritable_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Directory::IsWritable");
            mojo::internal::MessageDispatchContext context(message);
            impl->IsWritable(
                std::move(p_path), std::move(callback));
            return true;
        }
        case internal::kDirectory_Flush_Name: {
            internal::Directory_Flush_Params_Data* params = reinterpret_cast<internal::Directory_Flush_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            Directory_Flush_ParamsDataView input_data_view(params,
                context);

            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Directory::Flush deserializer");
                return false;
            }
            Directory::FlushCallback callback = Directory_Flush_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Directory::Flush");
            mojo::internal::MessageDispatchContext context(message);
            impl->Flush(std::move(callback));
            return true;
        }
        case internal::kDirectory_StatFile_Name: {
            internal::Directory_StatFile_Params_Data* params = reinterpret_cast<internal::Directory_StatFile_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_path {};
            Directory_StatFile_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadPath(&p_path))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Directory::StatFile deserializer");
                return false;
            }
            Directory::StatFileCallback callback = Directory_StatFile_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Directory::StatFile");
            mojo::internal::MessageDispatchContext context(message);
            impl->StatFile(
                std::move(p_path), std::move(callback));
            return true;
        }
        case internal::kDirectory_Clone_Name: {
            break;
        }
        case internal::kDirectory_ReadEntireFile_Name: {
            internal::Directory_ReadEntireFile_Params_Data* params = reinterpret_cast<internal::Directory_ReadEntireFile_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_path {};
            Directory_ReadEntireFile_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadPath(&p_path))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Directory::ReadEntireFile deserializer");
                return false;
            }
            Directory::ReadEntireFileCallback callback = Directory_ReadEntireFile_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Directory::ReadEntireFile");
            mojo::internal::MessageDispatchContext context(message);
            impl->ReadEntireFile(
                std::move(p_path), std::move(callback));
            return true;
        }
        case internal::kDirectory_WriteFile_Name: {
            internal::Directory_WriteFile_Params_Data* params = reinterpret_cast<internal::Directory_WriteFile_Params_Data*>(
                message->mutable_payload());

            (context)->handles.Swap((message)->mutable_handles());
            bool success = true;
            std::string p_path {};
            std::vector<uint8_t> p_data {};
            Directory_WriteFile_ParamsDataView input_data_view(params,
                context);

            if (!input_data_view.ReadPath(&p_path))
                success = false;
            if (!input_data_view.ReadData(&p_data))
                success = false;
            if (!success) {
                ReportValidationErrorForMessage(
                    message,
                    mojo::internal::VALIDATION_ERROR_DESERIALIZATION_FAILED,
                    "Directory::WriteFile deserializer");
                return false;
            }
            Directory::WriteFileCallback callback = Directory_WriteFile_ProxyToResponder::CreateCallback(
                message->request_id(),
                message->has_flag(mojo::Message::kFlagIsSync), responder,
                context->group_controller);
            // A null |impl| means no implementation was bound.
            assert(impl);
            TRACE_EVENT0("mojom", "Directory::WriteFile");
            mojo::internal::MessageDispatchContext context(message);
            impl->WriteFile(
                std::move(p_path),
                std::move(p_data), std::move(callback));
            return true;
        }
        }
        return false;
    }

    bool DirectoryRequestValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "Directory RequestValidator");

        switch (message->header()->name) {
        case internal::kDirectory_Read_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Directory_Read_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDirectory_OpenFile_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Directory_OpenFile_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDirectory_OpenFileHandle_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Directory_OpenFileHandle_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDirectory_OpenFileHandles_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Directory_OpenFileHandles_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDirectory_OpenDirectory_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Directory_OpenDirectory_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDirectory_Rename_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Directory_Rename_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDirectory_Delete_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Directory_Delete_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDirectory_Exists_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Directory_Exists_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDirectory_IsWritable_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Directory_IsWritable_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDirectory_Flush_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Directory_Flush_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDirectory_StatFile_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Directory_StatFile_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDirectory_Clone_Name: {
            if (!mojo::internal::ValidateMessageIsRequestWithoutResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Directory_Clone_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDirectory_ReadEntireFile_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Directory_ReadEntireFile_Params_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDirectory_WriteFile_Name: {
            if (!mojo::internal::ValidateMessageIsRequestExpectingResponse(
                    message, &validation_context)) {
                return false;
            }
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Directory_WriteFile_Params_Data>(
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

    bool DirectoryResponseValidator::Accept(mojo::Message* message)
    {
        if (mojo::internal::ControlMessageHandler::IsControlMessage(message))
            return true;

        mojo::internal::ValidationContext validation_context(
            message->data(), message->data_num_bytes(), message->handles()->size(),
            message, "Directory ResponseValidator");

        if (!mojo::internal::ValidateMessageIsResponse(message, &validation_context))
            return false;
        switch (message->header()->name) {
        case internal::kDirectory_Read_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Directory_Read_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDirectory_OpenFile_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Directory_OpenFile_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDirectory_OpenFileHandle_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Directory_OpenFileHandle_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDirectory_OpenFileHandles_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Directory_OpenFileHandles_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDirectory_OpenDirectory_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Directory_OpenDirectory_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDirectory_Rename_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Directory_Rename_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDirectory_Delete_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Directory_Delete_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDirectory_Exists_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Directory_Exists_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDirectory_IsWritable_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Directory_IsWritable_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDirectory_Flush_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Directory_Flush_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDirectory_StatFile_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Directory_StatFile_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDirectory_ReadEntireFile_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Directory_ReadEntireFile_ResponseParams_Data>(
                    message, &validation_context)) {
                return false;
            }
            return true;
        }
        case internal::kDirectory_WriteFile_Name: {
            if (!mojo::internal::ValidateMessagePayload<
                    internal::Directory_WriteFile_ResponseParams_Data>(
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
} // namespace filesystem

namespace mojo {

// static
bool StructTraits<::filesystem::mojom::FileOpenDetails::DataView, ::filesystem::mojom::FileOpenDetailsPtr>::Read(
    ::filesystem::mojom::FileOpenDetails::DataView input,
    ::filesystem::mojom::FileOpenDetailsPtr* output)
{
    bool success = true;
    ::filesystem::mojom::FileOpenDetailsPtr result(::filesystem::mojom::FileOpenDetails::New());

    if (!input.ReadPath(&result->path))
        success = false;
    result->open_flags = input.open_flags();
    *output = std::move(result);
    return success;
}

// static
bool StructTraits<::filesystem::mojom::FileOpenResult::DataView, ::filesystem::mojom::FileOpenResultPtr>::Read(
    ::filesystem::mojom::FileOpenResult::DataView input,
    ::filesystem::mojom::FileOpenResultPtr* output)
{
    bool success = true;
    ::filesystem::mojom::FileOpenResultPtr result(::filesystem::mojom::FileOpenResult::New());

    if (!input.ReadPath(&result->path))
        success = false;
    if (!input.ReadError(&result->error))
        success = false;
    if (!input.ReadFileHandle(&result->file_handle))
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