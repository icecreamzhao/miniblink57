// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_FILESYSTEM_PUBLIC_INTERFACES_DIRECTORY_MOJOM_SHARED_H_
#define COMPONENTS_FILESYSTEM_PUBLIC_INTERFACES_DIRECTORY_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "components/filesystem/public/interfaces/directory.mojom-shared-internal.h"
#include "components/filesystem/public/interfaces/file.mojom-shared.h"
#include "components/filesystem/public/interfaces/types.mojom-shared.h"
#include "mojo/common/file.mojom-shared.h"
#include "mojo/public/cpp/bindings/array_data_view.h"
#include "mojo/public/cpp/bindings/enum_traits.h"
#include "mojo/public/cpp/bindings/interface_data_view.h"
#include "mojo/public/cpp/bindings/lib/bindings_internal.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/map_data_view.h"
#include "mojo/public/cpp/bindings/native_enum.h"
#include "mojo/public/cpp/bindings/native_struct_data_view.h"
#include "mojo/public/cpp/bindings/string_data_view.h"

namespace filesystem {
namespace mojom {
    class FileOpenDetailsDataView;

    class FileOpenResultDataView;

} // namespace mojom
} // namespace filesystem

namespace mojo {
namespace internal {

    template <>
    struct MojomTypeTraits<::filesystem::mojom::FileOpenDetailsDataView> {
        using Data = ::filesystem::mojom::internal::FileOpenDetails_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

    template <>
    struct MojomTypeTraits<::filesystem::mojom::FileOpenResultDataView> {
        using Data = ::filesystem::mojom::internal::FileOpenResult_Data;
        using DataAsArrayElement = Pointer<Data>;
        static constexpr MojomTypeCategory category = MojomTypeCategory::STRUCT;
    };

} // namespace internal
} // namespace mojo

namespace filesystem {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class DirectoryInterfaceBase {
    };

    using DirectoryPtrDataView = mojo::InterfacePtrDataView<DirectoryInterfaceBase>;
    using DirectoryRequestDataView = mojo::InterfaceRequestDataView<DirectoryInterfaceBase>;
    using DirectoryAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<DirectoryInterfaceBase>;
    using DirectoryAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<DirectoryInterfaceBase>;
    class FileOpenDetailsDataView {
    public:
        FileOpenDetailsDataView() { }

        FileOpenDetailsDataView(
            internal::FileOpenDetails_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetPathDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPath(UserType* output)
        {
            auto* pointer = data_->path.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        uint32_t open_flags() const
        {
            return data_->open_flags;
        }

    private:
        internal::FileOpenDetails_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class FileOpenResultDataView {
    public:
        FileOpenResultDataView() { }

        FileOpenResultDataView(
            internal::FileOpenResult_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetPathDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPath(UserType* output)
        {
            auto* pointer = data_->path.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadError(UserType* output) const
        {
            auto data_value = data_->error;
            return mojo::internal::Deserialize<::filesystem::mojom::FileError>(
                data_value, output);
        }

        ::filesystem::mojom::FileError error() const
        {
            return static_cast<::filesystem::mojom::FileError>(data_->error);
        }
        inline void GetFileHandleDataView(
            ::mojo::common::mojom::FileDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFileHandle(UserType* output)
        {
            auto* pointer = data_->file_handle.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::FileDataView>(
                pointer, output, context_);
        }

    private:
        internal::FileOpenResult_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Directory_Read_ParamsDataView {
    public:
        Directory_Read_ParamsDataView() { }

        Directory_Read_ParamsDataView(
            internal::Directory_Read_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::Directory_Read_Params_Data* data_ = nullptr;
    };

    class Directory_Read_ResponseParamsDataView {
    public:
        Directory_Read_ResponseParamsDataView() { }

        Directory_Read_ResponseParamsDataView(
            internal::Directory_Read_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadError(UserType* output) const
        {
            auto data_value = data_->error;
            return mojo::internal::Deserialize<::filesystem::mojom::FileError>(
                data_value, output);
        }

        ::filesystem::mojom::FileError error() const
        {
            return static_cast<::filesystem::mojom::FileError>(data_->error);
        }
        inline void GetDirectoryContentsDataView(
            mojo::ArrayDataView<::filesystem::mojom::DirectoryEntryDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDirectoryContents(UserType* output)
        {
            auto* pointer = data_->directory_contents.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::filesystem::mojom::DirectoryEntryDataView>>(
                pointer, output, context_);
        }

    private:
        internal::Directory_Read_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Directory_OpenFile_ParamsDataView {
    public:
        Directory_OpenFile_ParamsDataView() { }

        Directory_OpenFile_ParamsDataView(
            internal::Directory_OpenFile_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetPathDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPath(UserType* output)
        {
            auto* pointer = data_->path.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        UserType TakeFile()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::filesystem::mojom::FileRequestDataView>(
                &data_->file, &result, context_);
            DCHECK(ret);
            return result;
        }
        uint32_t open_flags() const
        {
            return data_->open_flags;
        }

    private:
        internal::Directory_OpenFile_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Directory_OpenFile_ResponseParamsDataView {
    public:
        Directory_OpenFile_ResponseParamsDataView() { }

        Directory_OpenFile_ResponseParamsDataView(
            internal::Directory_OpenFile_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadError(UserType* output) const
        {
            auto data_value = data_->error;
            return mojo::internal::Deserialize<::filesystem::mojom::FileError>(
                data_value, output);
        }

        ::filesystem::mojom::FileError error() const
        {
            return static_cast<::filesystem::mojom::FileError>(data_->error);
        }

    private:
        internal::Directory_OpenFile_ResponseParams_Data* data_ = nullptr;
    };

    class Directory_OpenFileHandle_ParamsDataView {
    public:
        Directory_OpenFileHandle_ParamsDataView() { }

        Directory_OpenFileHandle_ParamsDataView(
            internal::Directory_OpenFileHandle_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetPathDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPath(UserType* output)
        {
            auto* pointer = data_->path.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        uint32_t open_flags() const
        {
            return data_->open_flags;
        }

    private:
        internal::Directory_OpenFileHandle_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Directory_OpenFileHandle_ResponseParamsDataView {
    public:
        Directory_OpenFileHandle_ResponseParamsDataView() { }

        Directory_OpenFileHandle_ResponseParamsDataView(
            internal::Directory_OpenFileHandle_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadError(UserType* output) const
        {
            auto data_value = data_->error;
            return mojo::internal::Deserialize<::filesystem::mojom::FileError>(
                data_value, output);
        }

        ::filesystem::mojom::FileError error() const
        {
            return static_cast<::filesystem::mojom::FileError>(data_->error);
        }
        inline void GetFileHandleDataView(
            ::mojo::common::mojom::FileDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFileHandle(UserType* output)
        {
            auto* pointer = data_->file_handle.Get();
            return mojo::internal::Deserialize<::mojo::common::mojom::FileDataView>(
                pointer, output, context_);
        }

    private:
        internal::Directory_OpenFileHandle_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Directory_OpenFileHandles_ParamsDataView {
    public:
        Directory_OpenFileHandles_ParamsDataView() { }

        Directory_OpenFileHandles_ParamsDataView(
            internal::Directory_OpenFileHandles_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetFilesDataView(
            mojo::ArrayDataView<FileOpenDetailsDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFiles(UserType* output)
        {
            auto* pointer = data_->files.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::filesystem::mojom::FileOpenDetailsDataView>>(
                pointer, output, context_);
        }

    private:
        internal::Directory_OpenFileHandles_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Directory_OpenFileHandles_ResponseParamsDataView {
    public:
        Directory_OpenFileHandles_ResponseParamsDataView() { }

        Directory_OpenFileHandles_ResponseParamsDataView(
            internal::Directory_OpenFileHandles_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetResultsDataView(
            mojo::ArrayDataView<FileOpenResultDataView>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadResults(UserType* output)
        {
            auto* pointer = data_->results.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<::filesystem::mojom::FileOpenResultDataView>>(
                pointer, output, context_);
        }

    private:
        internal::Directory_OpenFileHandles_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Directory_OpenDirectory_ParamsDataView {
    public:
        Directory_OpenDirectory_ParamsDataView() { }

        Directory_OpenDirectory_ParamsDataView(
            internal::Directory_OpenDirectory_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetPathDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPath(UserType* output)
        {
            auto* pointer = data_->path.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        UserType TakeDirectory()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::filesystem::mojom::DirectoryRequestDataView>(
                &data_->directory, &result, context_);
            DCHECK(ret);
            return result;
        }
        uint32_t open_flags() const
        {
            return data_->open_flags;
        }

    private:
        internal::Directory_OpenDirectory_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Directory_OpenDirectory_ResponseParamsDataView {
    public:
        Directory_OpenDirectory_ResponseParamsDataView() { }

        Directory_OpenDirectory_ResponseParamsDataView(
            internal::Directory_OpenDirectory_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadError(UserType* output) const
        {
            auto data_value = data_->error;
            return mojo::internal::Deserialize<::filesystem::mojom::FileError>(
                data_value, output);
        }

        ::filesystem::mojom::FileError error() const
        {
            return static_cast<::filesystem::mojom::FileError>(data_->error);
        }

    private:
        internal::Directory_OpenDirectory_ResponseParams_Data* data_ = nullptr;
    };

    class Directory_Rename_ParamsDataView {
    public:
        Directory_Rename_ParamsDataView() { }

        Directory_Rename_ParamsDataView(
            internal::Directory_Rename_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetPathDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPath(UserType* output)
        {
            auto* pointer = data_->path.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetNewPathDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadNewPath(UserType* output)
        {
            auto* pointer = data_->new_path.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::Directory_Rename_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Directory_Rename_ResponseParamsDataView {
    public:
        Directory_Rename_ResponseParamsDataView() { }

        Directory_Rename_ResponseParamsDataView(
            internal::Directory_Rename_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadError(UserType* output) const
        {
            auto data_value = data_->error;
            return mojo::internal::Deserialize<::filesystem::mojom::FileError>(
                data_value, output);
        }

        ::filesystem::mojom::FileError error() const
        {
            return static_cast<::filesystem::mojom::FileError>(data_->error);
        }

    private:
        internal::Directory_Rename_ResponseParams_Data* data_ = nullptr;
    };

    class Directory_Delete_ParamsDataView {
    public:
        Directory_Delete_ParamsDataView() { }

        Directory_Delete_ParamsDataView(
            internal::Directory_Delete_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetPathDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPath(UserType* output)
        {
            auto* pointer = data_->path.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        uint32_t delete_flags() const
        {
            return data_->delete_flags;
        }

    private:
        internal::Directory_Delete_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Directory_Delete_ResponseParamsDataView {
    public:
        Directory_Delete_ResponseParamsDataView() { }

        Directory_Delete_ResponseParamsDataView(
            internal::Directory_Delete_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadError(UserType* output) const
        {
            auto data_value = data_->error;
            return mojo::internal::Deserialize<::filesystem::mojom::FileError>(
                data_value, output);
        }

        ::filesystem::mojom::FileError error() const
        {
            return static_cast<::filesystem::mojom::FileError>(data_->error);
        }

    private:
        internal::Directory_Delete_ResponseParams_Data* data_ = nullptr;
    };

    class Directory_Exists_ParamsDataView {
    public:
        Directory_Exists_ParamsDataView() { }

        Directory_Exists_ParamsDataView(
            internal::Directory_Exists_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetPathDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPath(UserType* output)
        {
            auto* pointer = data_->path.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::Directory_Exists_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Directory_Exists_ResponseParamsDataView {
    public:
        Directory_Exists_ResponseParamsDataView() { }

        Directory_Exists_ResponseParamsDataView(
            internal::Directory_Exists_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadError(UserType* output) const
        {
            auto data_value = data_->error;
            return mojo::internal::Deserialize<::filesystem::mojom::FileError>(
                data_value, output);
        }

        ::filesystem::mojom::FileError error() const
        {
            return static_cast<::filesystem::mojom::FileError>(data_->error);
        }
        bool exists() const
        {
            return data_->exists;
        }

    private:
        internal::Directory_Exists_ResponseParams_Data* data_ = nullptr;
    };

    class Directory_IsWritable_ParamsDataView {
    public:
        Directory_IsWritable_ParamsDataView() { }

        Directory_IsWritable_ParamsDataView(
            internal::Directory_IsWritable_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetPathDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPath(UserType* output)
        {
            auto* pointer = data_->path.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::Directory_IsWritable_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Directory_IsWritable_ResponseParamsDataView {
    public:
        Directory_IsWritable_ResponseParamsDataView() { }

        Directory_IsWritable_ResponseParamsDataView(
            internal::Directory_IsWritable_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadError(UserType* output) const
        {
            auto data_value = data_->error;
            return mojo::internal::Deserialize<::filesystem::mojom::FileError>(
                data_value, output);
        }

        ::filesystem::mojom::FileError error() const
        {
            return static_cast<::filesystem::mojom::FileError>(data_->error);
        }
        bool is_writable() const
        {
            return data_->is_writable;
        }

    private:
        internal::Directory_IsWritable_ResponseParams_Data* data_ = nullptr;
    };

    class Directory_Flush_ParamsDataView {
    public:
        Directory_Flush_ParamsDataView() { }

        Directory_Flush_ParamsDataView(
            internal::Directory_Flush_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::Directory_Flush_Params_Data* data_ = nullptr;
    };

    class Directory_Flush_ResponseParamsDataView {
    public:
        Directory_Flush_ResponseParamsDataView() { }

        Directory_Flush_ResponseParamsDataView(
            internal::Directory_Flush_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadError(UserType* output) const
        {
            auto data_value = data_->error;
            return mojo::internal::Deserialize<::filesystem::mojom::FileError>(
                data_value, output);
        }

        ::filesystem::mojom::FileError error() const
        {
            return static_cast<::filesystem::mojom::FileError>(data_->error);
        }

    private:
        internal::Directory_Flush_ResponseParams_Data* data_ = nullptr;
    };

    class Directory_StatFile_ParamsDataView {
    public:
        Directory_StatFile_ParamsDataView() { }

        Directory_StatFile_ParamsDataView(
            internal::Directory_StatFile_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetPathDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPath(UserType* output)
        {
            auto* pointer = data_->path.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::Directory_StatFile_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Directory_StatFile_ResponseParamsDataView {
    public:
        Directory_StatFile_ResponseParamsDataView() { }

        Directory_StatFile_ResponseParamsDataView(
            internal::Directory_StatFile_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadError(UserType* output) const
        {
            auto data_value = data_->error;
            return mojo::internal::Deserialize<::filesystem::mojom::FileError>(
                data_value, output);
        }

        ::filesystem::mojom::FileError error() const
        {
            return static_cast<::filesystem::mojom::FileError>(data_->error);
        }
        inline void GetFileInformationDataView(
            ::filesystem::mojom::FileInformationDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadFileInformation(UserType* output)
        {
            auto* pointer = data_->file_information.Get();
            return mojo::internal::Deserialize<::filesystem::mojom::FileInformationDataView>(
                pointer, output, context_);
        }

    private:
        internal::Directory_StatFile_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Directory_Clone_ParamsDataView {
    public:
        Directory_Clone_ParamsDataView() { }

        Directory_Clone_ParamsDataView(
            internal::Directory_Clone_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeDirectory()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::filesystem::mojom::DirectoryRequestDataView>(
                &data_->directory, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::Directory_Clone_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Directory_ReadEntireFile_ParamsDataView {
    public:
        Directory_ReadEntireFile_ParamsDataView() { }

        Directory_ReadEntireFile_ParamsDataView(
            internal::Directory_ReadEntireFile_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetPathDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPath(UserType* output)
        {
            auto* pointer = data_->path.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }

    private:
        internal::Directory_ReadEntireFile_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Directory_ReadEntireFile_ResponseParamsDataView {
    public:
        Directory_ReadEntireFile_ResponseParamsDataView() { }

        Directory_ReadEntireFile_ResponseParamsDataView(
            internal::Directory_ReadEntireFile_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadError(UserType* output) const
        {
            auto data_value = data_->error;
            return mojo::internal::Deserialize<::filesystem::mojom::FileError>(
                data_value, output);
        }

        ::filesystem::mojom::FileError error() const
        {
            return static_cast<::filesystem::mojom::FileError>(data_->error);
        }
        inline void GetDataDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadData(UserType* output)
        {
            auto* pointer = data_->data.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }

    private:
        internal::Directory_ReadEntireFile_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Directory_WriteFile_ParamsDataView {
    public:
        Directory_WriteFile_ParamsDataView() { }

        Directory_WriteFile_ParamsDataView(
            internal::Directory_WriteFile_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetPathDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadPath(UserType* output)
        {
            auto* pointer = data_->path.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        inline void GetDataDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadData(UserType* output)
        {
            auto* pointer = data_->data.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }

    private:
        internal::Directory_WriteFile_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class Directory_WriteFile_ResponseParamsDataView {
    public:
        Directory_WriteFile_ResponseParamsDataView() { }

        Directory_WriteFile_ResponseParamsDataView(
            internal::Directory_WriteFile_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadError(UserType* output) const
        {
            auto data_value = data_->error;
            return mojo::internal::Deserialize<::filesystem::mojom::FileError>(
                data_value, output);
        }

        ::filesystem::mojom::FileError error() const
        {
            return static_cast<::filesystem::mojom::FileError>(data_->error);
        }

    private:
        internal::Directory_WriteFile_ResponseParams_Data* data_ = nullptr;
    };

} // namespace mojom
} // namespace filesystem

namespace std {

} // namespace std

namespace mojo {

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::filesystem::mojom::FileOpenDetailsDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::filesystem::mojom::FileOpenDetailsDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::filesystem::mojom::internal::FileOpenDetails_Data);
            decltype(CallWithContext(Traits::path, input, custom_context)) in_path = CallWithContext(Traits::path, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_path, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::filesystem::mojom::internal::FileOpenDetails_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::filesystem::mojom::internal::FileOpenDetails_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::path, input, custom_context)) in_path = CallWithContext(Traits::path, input, custom_context);
            typename decltype(result->path)::BaseType* path_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_path, buffer, &path_ptr, context);
            result->path.Set(path_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->path.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null path in FileOpenDetails struct");
            result->open_flags = CallWithContext(Traits::open_flags, input, custom_context);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::filesystem::mojom::internal::FileOpenDetails_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::filesystem::mojom::FileOpenDetailsDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

namespace internal {

    template <typename MaybeConstUserType>
    struct Serializer<::filesystem::mojom::FileOpenResultDataView, MaybeConstUserType> {
        using UserType = typename std::remove_const<MaybeConstUserType>::type;
        using Traits = StructTraits<::filesystem::mojom::FileOpenResultDataView, UserType>;

        static size_t PrepareToSerialize(MaybeConstUserType& input,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input))
                return 0;

            void* custom_context = CustomContextHelper<Traits>::SetUp(input, context);
            ALLOW_UNUSED_LOCAL(custom_context);

            size_t size = sizeof(::filesystem::mojom::internal::FileOpenResult_Data);
            decltype(CallWithContext(Traits::path, input, custom_context)) in_path = CallWithContext(Traits::path, input, custom_context);
            size += mojo::internal::PrepareToSerialize<mojo::StringDataView>(
                in_path, context);
            decltype(CallWithContext(Traits::file_handle, input, custom_context)) in_file_handle = CallWithContext(Traits::file_handle, input, custom_context);
            size += mojo::internal::PrepareToSerialize<::mojo::common::mojom::FileDataView>(
                in_file_handle, context);
            return size;
        }

        static void Serialize(MaybeConstUserType& input,
            Buffer* buffer,
            ::filesystem::mojom::internal::FileOpenResult_Data** output,
            SerializationContext* context)
        {
            if (CallIsNullIfExists<Traits>(input)) {
                *output = nullptr;
                return;
            }

            void* custom_context = CustomContextHelper<Traits>::GetNext(context);

            auto result = ::filesystem::mojom::internal::FileOpenResult_Data::New(buffer);
            ALLOW_UNUSED_LOCAL(result);
            decltype(CallWithContext(Traits::path, input, custom_context)) in_path = CallWithContext(Traits::path, input, custom_context);
            typename decltype(result->path)::BaseType* path_ptr;
            mojo::internal::Serialize<mojo::StringDataView>(
                in_path, buffer, &path_ptr, context);
            result->path.Set(path_ptr);
            MOJO_INTERNAL_DLOG_SERIALIZATION_WARNING(
                result->path.is_null(),
                mojo::internal::VALIDATION_ERROR_UNEXPECTED_NULL_POINTER,
                "null path in FileOpenResult struct");
            mojo::internal::Serialize<::filesystem::mojom::FileError>(
                CallWithContext(Traits::error, input, custom_context), &result->error);
            decltype(CallWithContext(Traits::file_handle, input, custom_context)) in_file_handle = CallWithContext(Traits::file_handle, input, custom_context);
            typename decltype(result->file_handle)::BaseType* file_handle_ptr;
            mojo::internal::Serialize<::mojo::common::mojom::FileDataView>(
                in_file_handle, buffer, &file_handle_ptr, context);
            result->file_handle.Set(file_handle_ptr);
            *output = result;

            CustomContextHelper<Traits>::TearDown(input, custom_context);
        }

        static bool Deserialize(::filesystem::mojom::internal::FileOpenResult_Data* input,
            UserType* output,
            SerializationContext* context)
        {
            if (!input)
                return CallSetToNullIfExists<Traits>(output);

            ::filesystem::mojom::FileOpenResultDataView data_view(input, context);
            return Traits::Read(data_view, output);
        }
    };

} // namespace internal

} // namespace mojo

namespace filesystem {
namespace mojom {

    inline void FileOpenDetailsDataView::GetPathDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->path.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void FileOpenResultDataView::GetPathDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->path.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void FileOpenResultDataView::GetFileHandleDataView(
        ::mojo::common::mojom::FileDataView* output)
    {
        auto pointer = data_->file_handle.Get();
        *output = ::mojo::common::mojom::FileDataView(pointer, context_);
    }

    inline void Directory_Read_ResponseParamsDataView::GetDirectoryContentsDataView(
        mojo::ArrayDataView<::filesystem::mojom::DirectoryEntryDataView>* output)
    {
        auto pointer = data_->directory_contents.Get();
        *output = mojo::ArrayDataView<::filesystem::mojom::DirectoryEntryDataView>(pointer, context_);
    }

    inline void Directory_OpenFile_ParamsDataView::GetPathDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->path.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void Directory_OpenFileHandle_ParamsDataView::GetPathDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->path.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void Directory_OpenFileHandle_ResponseParamsDataView::GetFileHandleDataView(
        ::mojo::common::mojom::FileDataView* output)
    {
        auto pointer = data_->file_handle.Get();
        *output = ::mojo::common::mojom::FileDataView(pointer, context_);
    }

    inline void Directory_OpenFileHandles_ParamsDataView::GetFilesDataView(
        mojo::ArrayDataView<FileOpenDetailsDataView>* output)
    {
        auto pointer = data_->files.Get();
        *output = mojo::ArrayDataView<FileOpenDetailsDataView>(pointer, context_);
    }

    inline void Directory_OpenFileHandles_ResponseParamsDataView::GetResultsDataView(
        mojo::ArrayDataView<FileOpenResultDataView>* output)
    {
        auto pointer = data_->results.Get();
        *output = mojo::ArrayDataView<FileOpenResultDataView>(pointer, context_);
    }

    inline void Directory_OpenDirectory_ParamsDataView::GetPathDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->path.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void Directory_Rename_ParamsDataView::GetPathDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->path.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void Directory_Rename_ParamsDataView::GetNewPathDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->new_path.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void Directory_Delete_ParamsDataView::GetPathDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->path.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void Directory_Exists_ParamsDataView::GetPathDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->path.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void Directory_IsWritable_ParamsDataView::GetPathDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->path.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void Directory_StatFile_ParamsDataView::GetPathDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->path.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void Directory_StatFile_ResponseParamsDataView::GetFileInformationDataView(
        ::filesystem::mojom::FileInformationDataView* output)
    {
        auto pointer = data_->file_information.Get();
        *output = ::filesystem::mojom::FileInformationDataView(pointer, context_);
    }

    inline void Directory_ReadEntireFile_ParamsDataView::GetPathDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->path.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

    inline void Directory_ReadEntireFile_ResponseParamsDataView::GetDataDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->data.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

    inline void Directory_WriteFile_ParamsDataView::GetPathDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->path.Get();
        *output = mojo::StringDataView(pointer, context_);
    }
    inline void Directory_WriteFile_ParamsDataView::GetDataDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->data.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

} // namespace mojom
} // namespace filesystem

#endif // COMPONENTS_FILESYSTEM_PUBLIC_INTERFACES_DIRECTORY_MOJOM_SHARED_H_
