// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SERVICES_FILE_PUBLIC_INTERFACES_FILE_SYSTEM_MOJOM_SHARED_H_
#define SERVICES_FILE_PUBLIC_INTERFACES_FILE_SYSTEM_MOJOM_SHARED_H_

#include <stdint.h>

#include <functional>
#include <ostream>
#include <type_traits>
#include <utility>

#include "base/compiler_specific.h"
#include "components/filesystem/public/interfaces/directory.mojom-shared.h"
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
#include "services/file/public/interfaces/file_system.mojom-shared-internal.h"

namespace file {
namespace mojom {

} // namespace mojom
} // namespace file

namespace mojo {
namespace internal {

} // namespace internal
} // namespace mojo

namespace file {
namespace mojom {
    // Interface base classes. They are used for type safety check.
    class FileSystemInterfaceBase {
    };

    using FileSystemPtrDataView = mojo::InterfacePtrDataView<FileSystemInterfaceBase>;
    using FileSystemRequestDataView = mojo::InterfaceRequestDataView<FileSystemInterfaceBase>;
    using FileSystemAssociatedPtrInfoDataView = mojo::AssociatedInterfacePtrInfoDataView<FileSystemInterfaceBase>;
    using FileSystemAssociatedRequestDataView = mojo::AssociatedInterfaceRequestDataView<FileSystemInterfaceBase>;
    class FileSystem_GetDirectory_ParamsDataView {
    public:
        FileSystem_GetDirectory_ParamsDataView() { }

        FileSystem_GetDirectory_ParamsDataView(
            internal::FileSystem_GetDirectory_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        template <typename UserType>
        UserType TakeDir()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::filesystem::mojom::DirectoryRequestDataView>(
                &data_->dir, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::FileSystem_GetDirectory_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class FileSystem_GetDirectory_ResponseParamsDataView {
    public:
        FileSystem_GetDirectory_ResponseParamsDataView() { }

        FileSystem_GetDirectory_ResponseParamsDataView(
            internal::FileSystem_GetDirectory_ResponseParams_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
        {
        }

        bool is_null() const { return !data_; }

    private:
        internal::FileSystem_GetDirectory_ResponseParams_Data* data_ = nullptr;
    };

    class FileSystem_GetSubDirectory_ParamsDataView {
    public:
        FileSystem_GetSubDirectory_ParamsDataView() { }

        FileSystem_GetSubDirectory_ParamsDataView(
            internal::FileSystem_GetSubDirectory_Params_Data* data,
            mojo::internal::SerializationContext* context)
            : data_(data)
            , context_(context)
        {
        }

        bool is_null() const { return !data_; }
        inline void GetDirPathDataView(
            mojo::StringDataView* output);

        template <typename UserType>
        WARN_UNUSED_RESULT bool ReadDirPath(UserType* output)
        {
            auto* pointer = data_->dir_path.Get();
            return mojo::internal::Deserialize<mojo::StringDataView>(
                pointer, output, context_);
        }
        template <typename UserType>
        UserType TakeDir()
        {
            UserType result;
            bool ret = mojo::internal::Deserialize<::filesystem::mojom::DirectoryRequestDataView>(
                &data_->dir, &result, context_);
            DCHECK(ret);
            return result;
        }

    private:
        internal::FileSystem_GetSubDirectory_Params_Data* data_ = nullptr;
        mojo::internal::SerializationContext* context_ = nullptr;
    };

    class FileSystem_GetSubDirectory_ResponseParamsDataView {
    public:
        FileSystem_GetSubDirectory_ResponseParamsDataView() { }

        FileSystem_GetSubDirectory_ResponseParamsDataView(
            internal::FileSystem_GetSubDirectory_ResponseParams_Data* data,
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
        internal::FileSystem_GetSubDirectory_ResponseParams_Data* data_ = nullptr;
    };

} // namespace mojom
} // namespace file

namespace std {

} // namespace std

namespace mojo {

} // namespace mojo

namespace file {
namespace mojom {

    inline void FileSystem_GetSubDirectory_ParamsDataView::GetDirPathDataView(
        mojo::StringDataView* output)
    {
        auto pointer = data_->dir_path.Get();
        *output = mojo::StringDataView(pointer, context_);
    }

} // namespace mojom
} // namespace file

#endif // SERVICES_FILE_PUBLIC_INTERFACES_FILE_SYSTEM_MOJOM_SHARED_H_
