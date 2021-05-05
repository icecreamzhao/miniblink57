// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_FILESYSTEM_PUBLIC_INTERFACES_FILE_SYSTEM_MOJOM_SHARED_H_
#define COMPONENTS_FILESYSTEM_PUBLIC_INTERFACES_FILE_SYSTEM_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "components/filesystem/public/interfaces/directory.mojom-shared.h"
#include "components/filesystem/public/interfaces/file_system.mojom-shared-internal.h"
#include "components/filesystem/public/interfaces/types.mojom-shared.h"
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
    class FileSystemInterfaceBase {
    };

    using FileSystemPtrDataView = mojo::InterfacePtrDataView<FileSystemInterfaceBase>;
    using FileSystemRequestDataView = mojo::InterfaceRequestDataView<FileSystemInterfaceBase>;
    using FileSystemAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<FileSystemInterfaceBase>;
    using FileSystemAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<FileSystemInterfaceBase>;
    class FileSystem_OpenTempDirectory_ParamsDataView {
    public:
        FileSystem_OpenTempDirectory_ParamsDataView() { }

        FileSystem_OpenTempDirectory_ParamsDataView(
            internal::FileSystem_OpenTempDirectory_Params_Data* data,
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
        internal::FileSystem_OpenTempDirectory_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class FileSystem_OpenTempDirectory_ResponseParamsDataView {
    public:
        FileSystem_OpenTempDirectory_ResponseParamsDataView() { }

        FileSystem_OpenTempDirectory_ResponseParamsDataView(
            internal::FileSystem_OpenTempDirectory_ResponseParams_Data* data,
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
        internal::FileSystem_OpenTempDirectory_ResponseParams_Data* data_ = nullptr;
    };

    class FileSystem_OpenPersistentFileSystem_ParamsDataView {
    public:
        FileSystem_OpenPersistentFileSystem_ParamsDataView() { }

        FileSystem_OpenPersistentFileSystem_ParamsDataView(
            internal::FileSystem_OpenPersistentFileSystem_Params_Data* data,
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
        internal::FileSystem_OpenPersistentFileSystem_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class FileSystem_OpenPersistentFileSystem_ResponseParamsDataView {
    public:
        FileSystem_OpenPersistentFileSystem_ResponseParamsDataView() { }

        FileSystem_OpenPersistentFileSystem_ResponseParamsDataView(
            internal::FileSystem_OpenPersistentFileSystem_ResponseParams_Data* data,
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
        internal::FileSystem_OpenPersistentFileSystem_ResponseParams_Data* data_ = nullptr;
    };

} // namespace mojom
} // namespace filesystem

namespace std {

} // namespace std

namespace mojo {

} // namespace mojo

namespace filesystem {
namespace mojom {

} // namespace mojom
} // namespace filesystem

#endif // COMPONENTS_FILESYSTEM_PUBLIC_INTERFACES_FILE_SYSTEM_MOJOM_SHARED_H_
