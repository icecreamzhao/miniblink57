// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_FILESYSTEM_PUBLIC_INTERFACES_DIRECTORY_MOJOM_H_
#define COMPONENTS_FILESYSTEM_PUBLIC_INTERFACES_DIRECTORY_MOJOM_H_

#include <stdint.h>

#include <limits>
#include <type_traits>
#include <utility>

#include "base/callback.h"
#include "base/files/file.h"
#include "base/files/file_path.h"
#include "base/i18n/rtl.h"
#include "base/optional.h"
#include "base/strings/string16.h"
#include "base/time/time.h"
#include "base/unguessable_token.h"
#include "base/values.h"
#include "base/version.h"
#include "components/filesystem/public/interfaces/directory.mojom-shared.h"
#include "components/filesystem/public/interfaces/file.mojom.h"
#include "components/filesystem/public/interfaces/types.mojom.h"
#include "mojo/common/file.mojom.h"
#include "mojo/public/cpp/bindings/associated_interface_ptr.h"
#include "mojo/public/cpp/bindings/associated_interface_ptr_info.h"
#include "mojo/public/cpp/bindings/associated_interface_request.h"
#include "mojo/public/cpp/bindings/interface_ptr.h"
#include "mojo/public/cpp/bindings/interface_request.h"
#include "mojo/public/cpp/bindings/lib/clone_equals_util.h"
#include "mojo/public/cpp/bindings/lib/control_message_handler.h"
#include "mojo/public/cpp/bindings/lib/control_message_proxy.h"
#include "mojo/public/cpp/bindings/lib/serialization.h"
#include "mojo/public/cpp/bindings/lib/union_accessor.h"
#include "mojo/public/cpp/bindings/native_struct.h"
#include "mojo/public/cpp/bindings/no_interface.h"
#include "mojo/public/cpp/bindings/raw_ptr_impl_ref_traits.h"
#include "mojo/public/cpp/bindings/struct_ptr.h"
#include "mojo/public/cpp/bindings/struct_traits.h"
#include "mojo/public/cpp/bindings/thread_safe_interface_ptr.h"
#include "mojo/public/cpp/bindings/union_traits.h"
#include <string>
#include <vector>

namespace filesystem {
namespace mojom {
    class Directory;
    using DirectoryPtr = mojo::InterfacePtr<Directory>;
    using DirectoryPtrInfo = mojo::InterfacePtrInfo<Directory>;
    using ThreadSafeDirectoryPtr = mojo::ThreadSafeInterfacePtr<Directory>;
    using DirectoryRequest = mojo::InterfaceRequest<Directory>;
    using DirectoryAssociatedPtr = mojo::AssociatedInterfacePtr<Directory>;
    using ThreadSafeDirectoryAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<Directory>;
    using DirectoryAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<Directory>;
    using DirectoryAssociatedRequest = mojo::AssociatedInterfaceRequest<Directory>;

    class FileOpenDetails;
    using FileOpenDetailsPtr = mojo::InlinedStructPtr<FileOpenDetails>;

    class FileOpenResult;
    using FileOpenResultPtr = mojo::StructPtr<FileOpenResult>;

    class DirectoryProxy;

    template <typename ImplRefTraits>
    class DirectoryStub;

    class DirectoryRequestValidator;
    class DirectoryResponseValidator;

    class Directory
        : public DirectoryInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = true;

        using Proxy_ = DirectoryProxy;

        template <typename ImplRefTraits>
        using Stub_ = DirectoryStub<ImplRefTraits>;

        using RequestValidator_ = DirectoryRequestValidator;
        using ResponseValidator_ = DirectoryResponseValidator;
        enum MethodMinVersions : uint32_t {
            kReadMinVersion = 0,
            kOpenFileMinVersion = 0,
            kOpenFileHandleMinVersion = 0,
            kOpenFileHandlesMinVersion = 0,
            kOpenDirectoryMinVersion = 0,
            kRenameMinVersion = 0,
            kDeleteMinVersion = 0,
            kExistsMinVersion = 0,
            kIsWritableMinVersion = 0,
            kFlushMinVersion = 0,
            kStatFileMinVersion = 0,
            kCloneMinVersion = 0,
            kReadEntireFileMinVersion = 0,
            kWriteFileMinVersion = 0,
        };
        virtual ~Directory() { }

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool Read(::filesystem::mojom::FileError* error, base::Optional<std::vector<::filesystem::mojom::DirectoryEntryPtr>>* directory_contents);

        using ReadCallback = base::Callback<void(::filesystem::mojom::FileError, base::Optional<std::vector<::filesystem::mojom::DirectoryEntryPtr>>)>;
        virtual void Read(const ReadCallback& callback) = 0;

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool OpenFile(const std::string& path, ::filesystem::mojom::FileRequest file, uint32_t open_flags, ::filesystem::mojom::FileError* error);

        using OpenFileCallback = base::Callback<void(::filesystem::mojom::FileError)>;
        virtual void OpenFile(const std::string& path, ::filesystem::mojom::FileRequest file, uint32_t open_flags, const OpenFileCallback& callback) = 0;

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool OpenFileHandle(const std::string& path, uint32_t open_flags, ::filesystem::mojom::FileError* error, base::File* file_handle);

        using OpenFileHandleCallback = base::Callback<void(::filesystem::mojom::FileError, base::File)>;
        virtual void OpenFileHandle(const std::string& path, uint32_t open_flags, const OpenFileHandleCallback& callback) = 0;

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool OpenFileHandles(std::vector<FileOpenDetailsPtr> files, std::vector<FileOpenResultPtr>* results);

        using OpenFileHandlesCallback = base::Callback<void(std::vector<FileOpenResultPtr>)>;
        virtual void OpenFileHandles(std::vector<FileOpenDetailsPtr> files, const OpenFileHandlesCallback& callback) = 0;

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool OpenDirectory(const std::string& path, DirectoryRequest directory, uint32_t open_flags, ::filesystem::mojom::FileError* error);

        using OpenDirectoryCallback = base::Callback<void(::filesystem::mojom::FileError)>;
        virtual void OpenDirectory(const std::string& path, DirectoryRequest directory, uint32_t open_flags, const OpenDirectoryCallback& callback) = 0;

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool Rename(const std::string& path, const std::string& new_path, ::filesystem::mojom::FileError* error);

        using RenameCallback = base::Callback<void(::filesystem::mojom::FileError)>;
        virtual void Rename(const std::string& path, const std::string& new_path, const RenameCallback& callback) = 0;

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool Delete(const std::string& path, uint32_t delete_flags, ::filesystem::mojom::FileError* error);

        using DeleteCallback = base::Callback<void(::filesystem::mojom::FileError)>;
        virtual void Delete(const std::string& path, uint32_t delete_flags, const DeleteCallback& callback) = 0;

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool Exists(const std::string& path, ::filesystem::mojom::FileError* error, bool* exists);

        using ExistsCallback = base::Callback<void(::filesystem::mojom::FileError, bool)>;
        virtual void Exists(const std::string& path, const ExistsCallback& callback) = 0;

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool IsWritable(const std::string& path, ::filesystem::mojom::FileError* error, bool* is_writable);

        using IsWritableCallback = base::Callback<void(::filesystem::mojom::FileError, bool)>;
        virtual void IsWritable(const std::string& path, const IsWritableCallback& callback) = 0;

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool Flush(::filesystem::mojom::FileError* error);

        using FlushCallback = base::Callback<void(::filesystem::mojom::FileError)>;
        virtual void Flush(const FlushCallback& callback) = 0;

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool StatFile(const std::string& path, ::filesystem::mojom::FileError* error, ::filesystem::mojom::FileInformationPtr* file_information);

        using StatFileCallback = base::Callback<void(::filesystem::mojom::FileError, ::filesystem::mojom::FileInformationPtr)>;
        virtual void StatFile(const std::string& path, const StatFileCallback& callback) = 0;

        virtual void Clone(DirectoryRequest directory) = 0;

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool ReadEntireFile(const std::string& path, ::filesystem::mojom::FileError* error, std::vector<uint8_t>* data);

        using ReadEntireFileCallback = base::Callback<void(::filesystem::mojom::FileError, const std::vector<uint8_t>&)>;
        virtual void ReadEntireFile(const std::string& path, const ReadEntireFileCallback& callback) = 0;

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool WriteFile(const std::string& path, const std::vector<uint8_t>& data, ::filesystem::mojom::FileError* error);

        using WriteFileCallback = base::Callback<void(::filesystem::mojom::FileError)>;
        virtual void WriteFile(const std::string& path, const std::vector<uint8_t>& data, const WriteFileCallback& callback) = 0;
    };

    class DirectoryProxy
        : public Directory {
    public:
        explicit DirectoryProxy(mojo::MessageReceiverWithResponder* receiver);
        bool Read(::filesystem::mojom::FileError* error, base::Optional<std::vector<::filesystem::mojom::DirectoryEntryPtr>>* directory_contents) override;
        void Read(const ReadCallback& callback) override;
        bool OpenFile(const std::string& path, ::filesystem::mojom::FileRequest file, uint32_t open_flags, ::filesystem::mojom::FileError* error) override;
        void OpenFile(const std::string& path, ::filesystem::mojom::FileRequest file, uint32_t open_flags, const OpenFileCallback& callback) override;
        bool OpenFileHandle(const std::string& path, uint32_t open_flags, ::filesystem::mojom::FileError* error, base::File* file_handle) override;
        void OpenFileHandle(const std::string& path, uint32_t open_flags, const OpenFileHandleCallback& callback) override;
        bool OpenFileHandles(std::vector<FileOpenDetailsPtr> files, std::vector<FileOpenResultPtr>* results) override;
        void OpenFileHandles(std::vector<FileOpenDetailsPtr> files, const OpenFileHandlesCallback& callback) override;
        bool OpenDirectory(const std::string& path, DirectoryRequest directory, uint32_t open_flags, ::filesystem::mojom::FileError* error) override;
        void OpenDirectory(const std::string& path, DirectoryRequest directory, uint32_t open_flags, const OpenDirectoryCallback& callback) override;
        bool Rename(const std::string& path, const std::string& new_path, ::filesystem::mojom::FileError* error) override;
        void Rename(const std::string& path, const std::string& new_path, const RenameCallback& callback) override;
        bool Delete(const std::string& path, uint32_t delete_flags, ::filesystem::mojom::FileError* error) override;
        void Delete(const std::string& path, uint32_t delete_flags, const DeleteCallback& callback) override;
        bool Exists(const std::string& path, ::filesystem::mojom::FileError* error, bool* exists) override;
        void Exists(const std::string& path, const ExistsCallback& callback) override;
        bool IsWritable(const std::string& path, ::filesystem::mojom::FileError* error, bool* is_writable) override;
        void IsWritable(const std::string& path, const IsWritableCallback& callback) override;
        bool Flush(::filesystem::mojom::FileError* error) override;
        void Flush(const FlushCallback& callback) override;
        bool StatFile(const std::string& path, ::filesystem::mojom::FileError* error, ::filesystem::mojom::FileInformationPtr* file_information) override;
        void StatFile(const std::string& path, const StatFileCallback& callback) override;
        void Clone(DirectoryRequest directory) override;
        bool ReadEntireFile(const std::string& path, ::filesystem::mojom::FileError* error, std::vector<uint8_t>* data) override;
        void ReadEntireFile(const std::string& path, const ReadEntireFileCallback& callback) override;
        bool WriteFile(const std::string& path, const std::vector<uint8_t>& data, ::filesystem::mojom::FileError* error) override;
        void WriteFile(const std::string& path, const std::vector<uint8_t>& data, const WriteFileCallback& callback) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class DirectoryStubDispatch {
    public:
        static bool Accept(Directory* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(Directory* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<Directory>>
    class DirectoryStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        DirectoryStub() { }
        ~DirectoryStub() override { }

        void set_sink(ImplPointerType sink) { sink_ = std::move(sink); }
        ImplPointerType& sink() { return sink_; }

        mojo::internal::SerializationContext* serialization_context()
        {
            return &serialization_context_;
        }

        bool Accept(mojo::Message* message) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return DirectoryStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return DirectoryStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class DirectoryRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class DirectoryResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

    class FileOpenDetails {
    public:
        using DataView = FileOpenDetailsDataView;
        using Data_ = internal::FileOpenDetails_Data;

        static FileOpenDetailsPtr New();

        template <typename U>
        static FileOpenDetailsPtr From(const U& u)
        {
            return mojo::TypeConverter<FileOpenDetailsPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, FileOpenDetails>::Convert(*this);
        }

        FileOpenDetails();
        ~FileOpenDetails();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = FileOpenDetailsPtr>
        FileOpenDetailsPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, FileOpenDetails>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                FileOpenDetails::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                FileOpenDetails::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::string path;
        uint32_t open_flags;
    };

    class FileOpenResult {
    public:
        using DataView = FileOpenResultDataView;
        using Data_ = internal::FileOpenResult_Data;

        static FileOpenResultPtr New();

        template <typename U>
        static FileOpenResultPtr From(const U& u)
        {
            return mojo::TypeConverter<FileOpenResultPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, FileOpenResult>::Convert(*this);
        }

        FileOpenResult();
        ~FileOpenResult();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = FileOpenResultPtr>
        FileOpenResultPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, FileOpenResult>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                FileOpenResult::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                FileOpenResult::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::string path;
        ::filesystem::mojom::FileError error;
        base::File file_handle;

    private:
        DISALLOW_COPY_AND_ASSIGN(FileOpenResult);
    };

    template <typename StructPtrType>
    FileOpenDetailsPtr FileOpenDetails::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->path = mojo::internal::Clone(path);
        rv->open_flags = mojo::internal::Clone(open_flags);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, FileOpenDetails>::value>::type*>
    bool FileOpenDetails::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->path, other.path))
            return false;
        if (!mojo::internal::Equals(this->open_flags, other.open_flags))
            return false;
        return true;
    }
    template <typename StructPtrType>
    FileOpenResultPtr FileOpenResult::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->path = mojo::internal::Clone(path);
        rv->error = mojo::internal::Clone(error);
        rv->file_handle = mojo::internal::Clone(file_handle);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, FileOpenResult>::value>::type*>
    bool FileOpenResult::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->path, other.path))
            return false;
        if (!mojo::internal::Equals(this->error, other.error))
            return false;
        if (!mojo::internal::Equals(this->file_handle, other.file_handle))
            return false;
        return true;
    }

} // namespace mojom
} // namespace filesystem

namespace mojo {

template <>
struct StructTraits<::filesystem::mojom::FileOpenDetails::DataView,
    ::filesystem::mojom::FileOpenDetailsPtr> {
    static bool IsNull(const ::filesystem::mojom::FileOpenDetailsPtr& input) { return !input; }
    static void SetToNull(::filesystem::mojom::FileOpenDetailsPtr* output) { output->reset(); }

    static const decltype(::filesystem::mojom::FileOpenDetails::path)& path(
        const ::filesystem::mojom::FileOpenDetailsPtr& input)
    {
        return input->path;
    }

    static decltype(::filesystem::mojom::FileOpenDetails::open_flags) open_flags(
        const ::filesystem::mojom::FileOpenDetailsPtr& input)
    {
        return input->open_flags;
    }

    static bool Read(::filesystem::mojom::FileOpenDetails::DataView input, ::filesystem::mojom::FileOpenDetailsPtr* output);
};

template <>
struct StructTraits<::filesystem::mojom::FileOpenResult::DataView,
    ::filesystem::mojom::FileOpenResultPtr> {
    static bool IsNull(const ::filesystem::mojom::FileOpenResultPtr& input) { return !input; }
    static void SetToNull(::filesystem::mojom::FileOpenResultPtr* output) { output->reset(); }

    static const decltype(::filesystem::mojom::FileOpenResult::path)& path(
        const ::filesystem::mojom::FileOpenResultPtr& input)
    {
        return input->path;
    }

    static decltype(::filesystem::mojom::FileOpenResult::error) error(
        const ::filesystem::mojom::FileOpenResultPtr& input)
    {
        return input->error;
    }

    static decltype(::filesystem::mojom::FileOpenResult::file_handle)& file_handle(
        ::filesystem::mojom::FileOpenResultPtr& input)
    {
        return input->file_handle;
    }

    static bool Read(::filesystem::mojom::FileOpenResult::DataView input, ::filesystem::mojom::FileOpenResultPtr* output);
};

} // namespace mojo

#endif // COMPONENTS_FILESYSTEM_PUBLIC_INTERFACES_DIRECTORY_MOJOM_H_