// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_FILESYSTEM_PUBLIC_INTERFACES_FILE_MOJOM_SHARED_H_
#define COMPONENTS_FILESYSTEM_PUBLIC_INTERFACES_FILE_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "components/filesystem/public/interfaces/file.mojom-shared-internal.h"
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

} // namespace mojom
} // namespace filesystem

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace filesystem {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class FileInterfaceBase {
    };

    using FilePtrDataView = mojo::InterfacePtrDataView<FileInterfaceBase>;
    using FileRequestDataView = mojo::InterfaceRequestDataView<FileInterfaceBase>;
    using FileAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<FileInterfaceBase>;
    using FileAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<FileInterfaceBase>;
    class File_Close_ParamsDataView {
    public:
        File_Close_ParamsDataView() { }

        File_Close_ParamsDataView(
            internal::File_Close_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::File_Close_Params_Data* data_ = nullptr;
    };

    class File_Close_ResponseParamsDataView {
    public:
        File_Close_ResponseParamsDataView() { }

        File_Close_ResponseParamsDataView(
            internal::File_Close_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadErr(UserType* output) const
        {
            auto data_value = data_->err;
            return mojo::internal::Deserialize<::filesystem::mojom::FileError>(
                data_value, output);
        }

        ::filesystem::mojom::FileError err() const
        {
            return static_cast<::filesystem::mojom::FileError>(data_->err);
        }

    private:
        internal::File_Close_ResponseParams_Data* data_ = nullptr;
    };

    class File_Read_ParamsDataView {
    public:
        File_Read_ParamsDataView() { }

        File_Read_ParamsDataView(
            internal::File_Read_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        uint32_t num_bytes_to_read() const
        {
            return data_->num_bytes_to_read;
        }
        int64_t offset() const
        {
            return data_->offset;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadWhence(UserType* output) const
        {
            auto data_value = data_->whence;
            return mojo::internal::Deserialize<::filesystem::mojom::Whence>(
                data_value, output);
        }

        ::filesystem::mojom::Whence whence() const
        {
            return static_cast<::filesystem::mojom::Whence>(data_->whence);
        }

    private:
        internal::File_Read_Params_Data* data_ = nullptr;
    };

    class File_Read_ResponseParamsDataView {
    public:
        File_Read_ResponseParamsDataView() { }

        File_Read_ResponseParamsDataView(
            internal::File_Read_ResponseParams_Data* data,
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
        inline void GetBytesReadDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadBytesRead(UserType* output)
        {
            auto* pointer = data_->bytes_read.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }

    private:
        internal::File_Read_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class File_Write_ParamsDataView {
    public:
        File_Write_ParamsDataView() { }

        File_Write_ParamsDataView(
            internal::File_Write_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetBytesToWriteDataView(
            mojo::ArrayDataView<uint8_t>* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadBytesToWrite(UserType* output)
        {
            auto* pointer = data_->bytes_to_write.Get();
            return mojo::internal::Deserialize<mojo::ArrayDataView<uint8_t>>(
                pointer, output, context_);
        }
        int64_t offset() const
        {
            return data_->offset;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadWhence(UserType* output) const
        {
            auto data_value = data_->whence;
            return mojo::internal::Deserialize<::filesystem::mojom::Whence>(
                data_value, output);
        }

        ::filesystem::mojom::Whence whence() const
        {
            return static_cast<::filesystem::mojom::Whence>(data_->whence);
        }

    private:
        internal::File_Write_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class File_Write_ResponseParamsDataView {
    public:
        File_Write_ResponseParamsDataView() { }

        File_Write_ResponseParamsDataView(
            internal::File_Write_ResponseParams_Data* data,
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
        uint32_t num_bytes_written() const
        {
            return data_->num_bytes_written;
        }

    private:
        internal::File_Write_ResponseParams_Data* data_ = nullptr;
    };

    class File_Tell_ParamsDataView {
    public:
        File_Tell_ParamsDataView() { }

        File_Tell_ParamsDataView(
            internal::File_Tell_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::File_Tell_Params_Data* data_ = nullptr;
    };

    class File_Tell_ResponseParamsDataView {
    public:
        File_Tell_ResponseParamsDataView() { }

        File_Tell_ResponseParamsDataView(
            internal::File_Tell_ResponseParams_Data* data,
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
        int64_t position() const
        {
            return data_->position;
        }

    private:
        internal::File_Tell_ResponseParams_Data* data_ = nullptr;
    };

    class File_Seek_ParamsDataView {
    public:
        File_Seek_ParamsDataView() { }

        File_Seek_ParamsDataView(
            internal::File_Seek_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int64_t offset() const
        {
            return data_->offset;
        }
        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadWhence(UserType* output) const
        {
            auto data_value = data_->whence;
            return mojo::internal::Deserialize<::filesystem::mojom::Whence>(
                data_value, output);
        }

        ::filesystem::mojom::Whence whence() const
        {
            return static_cast<::filesystem::mojom::Whence>(data_->whence);
        }

    private:
        internal::File_Seek_Params_Data* data_ = nullptr;
    };

    class File_Seek_ResponseParamsDataView {
    public:
        File_Seek_ResponseParamsDataView() { }

        File_Seek_ResponseParamsDataView(
            internal::File_Seek_ResponseParams_Data* data,
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
        int64_t position() const
        {
            return data_->position;
        }

    private:
        internal::File_Seek_ResponseParams_Data* data_ = nullptr;
    };

    class File_Stat_ParamsDataView {
    public:
        File_Stat_ParamsDataView() { }

        File_Stat_ParamsDataView(
            internal::File_Stat_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::File_Stat_Params_Data* data_ = nullptr;
    };

    class File_Stat_ResponseParamsDataView {
    public:
        File_Stat_ResponseParamsDataView() { }

        File_Stat_ResponseParamsDataView(
            internal::File_Stat_ResponseParams_Data* data,
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
        internal::File_Stat_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class File_Truncate_ParamsDataView {
    public:
        File_Truncate_ParamsDataView() { }

        File_Truncate_ParamsDataView(
            internal::File_Truncate_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }
        int64_t size() const
        {
            return data_->size;
        }

    private:
        internal::File_Truncate_Params_Data* data_ = nullptr;
    };

    class File_Truncate_ResponseParamsDataView {
    public:
        File_Truncate_ResponseParamsDataView() { }

        File_Truncate_ResponseParamsDataView(
            internal::File_Truncate_ResponseParams_Data* data,
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
        internal::File_Truncate_ResponseParams_Data* data_ = nullptr;
    };

    class File_Touch_ParamsDataView {
    public:
        File_Touch_ParamsDataView() { }

        File_Touch_ParamsDataView(
            internal::File_Touch_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetAtimeDataView(
            ::filesystem::mojom::TimespecOrNowDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadAtime(UserType* output)
        {
            auto* pointer = data_->atime.Get();
            return mojo::internal::Deserialize<::filesystem::mojom::TimespecOrNowDataView>(
                pointer, output, context_);
        }
        inline void GetMtimeDataView(
            ::filesystem::mojom::TimespecOrNowDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadMtime(UserType* output)
        {
            auto* pointer = data_->mtime.Get();
            return mojo::internal::Deserialize<::filesystem::mojom::TimespecOrNowDataView>(
                pointer, output, context_);
        }

    private:
        internal::File_Touch_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class File_Touch_ResponseParamsDataView {
    public:
        File_Touch_ResponseParamsDataView() { }

        File_Touch_ResponseParamsDataView(
            internal::File_Touch_ResponseParams_Data* data,
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
        internal::File_Touch_ResponseParams_Data* data_ = nullptr;
    };

    class File_Dup_ParamsDataView {
    public:
        File_Dup_ParamsDataView() { }

        File_Dup_ParamsDataView(
            internal::File_Dup_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeFile()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::filesystem::mojom::FileRequestDataView>(
                &data_->file, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::File_Dup_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class File_Dup_ResponseParamsDataView {
    public:
        File_Dup_ResponseParamsDataView() { }

        File_Dup_ResponseParamsDataView(
            internal::File_Dup_ResponseParams_Data* data,
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
        internal::File_Dup_ResponseParams_Data* data_ = nullptr;
    };

    class File_Flush_ParamsDataView {
    public:
        File_Flush_ParamsDataView() { }

        File_Flush_ParamsDataView(
            internal::File_Flush_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::File_Flush_Params_Data* data_ = nullptr;
    };

    class File_Flush_ResponseParamsDataView {
    public:
        File_Flush_ResponseParamsDataView() { }

        File_Flush_ResponseParamsDataView(
            internal::File_Flush_ResponseParams_Data* data,
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
        internal::File_Flush_ResponseParams_Data* data_ = nullptr;
    };

    class File_Lock_ParamsDataView {
    public:
        File_Lock_ParamsDataView() { }

        File_Lock_ParamsDataView(
            internal::File_Lock_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::File_Lock_Params_Data* data_ = nullptr;
    };

    class File_Lock_ResponseParamsDataView {
    public:
        File_Lock_ResponseParamsDataView() { }

        File_Lock_ResponseParamsDataView(
            internal::File_Lock_ResponseParams_Data* data,
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
        internal::File_Lock_ResponseParams_Data* data_ = nullptr;
    };

    class File_Unlock_ParamsDataView {
    public:
        File_Unlock_ParamsDataView() { }

        File_Unlock_ParamsDataView(
            internal::File_Unlock_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::File_Unlock_Params_Data* data_ = nullptr;
    };

    class File_Unlock_ResponseParamsDataView {
    public:
        File_Unlock_ResponseParamsDataView() { }

        File_Unlock_ResponseParamsDataView(
            internal::File_Unlock_ResponseParams_Data* data,
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
        internal::File_Unlock_ResponseParams_Data* data_ = nullptr;
    };

    class File_AsHandle_ParamsDataView {
    public:
        File_AsHandle_ParamsDataView() { }

        File_AsHandle_ParamsDataView(
            internal::File_AsHandle_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::File_AsHandle_Params_Data* data_ = nullptr;
    };

    class File_AsHandle_ResponseParamsDataView {
    public:
        File_AsHandle_ResponseParamsDataView() { }

        File_AsHandle_ResponseParamsDataView(
            internal::File_AsHandle_ResponseParams_Data* data,
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
        internal::File_AsHandle_ResponseParams_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

} // namespace mojom
} // namespace filesystem

namespace std {

} // namespace std

namespace mojo {

} // namespace mojo

namespace filesystem {
namespace mojom {

    inline void File_Read_ResponseParamsDataView::GetBytesReadDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->bytes_read.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

    inline void File_Write_ParamsDataView::GetBytesToWriteDataView(
        mojo::ArrayDataView<uint8_t>* output)
    {
        auto pointer = data_->bytes_to_write.Get();
        *output = mojo::ArrayDataView<uint8_t>(pointer, context_);
    }

    inline void File_Stat_ResponseParamsDataView::GetFileInformationDataView(
        ::filesystem::mojom::FileInformationDataView* output)
    {
        auto pointer = data_->file_information.Get();
        *output = ::filesystem::mojom::FileInformationDataView(pointer, context_);
    }

    inline void File_Touch_ParamsDataView::GetAtimeDataView(
        ::filesystem::mojom::TimespecOrNowDataView* output)
    {
        auto pointer = data_->atime.Get();
        *output = ::filesystem::mojom::TimespecOrNowDataView(pointer, context_);
    }
    inline void File_Touch_ParamsDataView::GetMtimeDataView(
        ::filesystem::mojom::TimespecOrNowDataView* output)
    {
        auto pointer = data_->mtime.Get();
        *output = ::filesystem::mojom::TimespecOrNowDataView(pointer, context_);
    }

    inline void File_AsHandle_ResponseParamsDataView::GetFileHandleDataView(
        ::mojo::common::mojom::FileDataView* output)
    {
        auto pointer = data_->file_handle.Get();
        *output = ::mojo::common::mojom::FileDataView(pointer, context_);
    }

} // namespace mojom
} // namespace filesystem

#endif // COMPONENTS_FILESYSTEM_PUBLIC_INTERFACES_FILE_MOJOM_SHARED_H_
