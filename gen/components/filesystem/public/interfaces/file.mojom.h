// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_FILESYSTEM_PUBLIC_INTERFACES_FILE_MOJOM_H_
#define COMPONENTS_FILESYSTEM_PUBLIC_INTERFACES_FILE_MOJOM_H_

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
#include "components/filesystem/public/interfaces/file.mojom-shared.h"
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
    class File;
    using FilePtr = mojo::InterfacePtr<File>;
    using FilePtrInfo = mojo::InterfacePtrInfo<File>;
    using ThreadSafeFilePtr = mojo::ThreadSafeInterfacePtr<File>;
    using FileRequest = mojo::InterfaceRequest<File>;
    using FileAssociatedPtr = mojo::AssociatedInterfacePtr<File>;
    using ThreadSafeFileAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<File>;
    using FileAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<File>;
    using FileAssociatedRequest = mojo::AssociatedInterfaceRequest<File>;

    class FileProxy;

    template <typename ImplRefTraits>
    class FileStub;

    class FileRequestValidator;
    class FileResponseValidator;

    class File
        : public FileInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = true;

        using Proxy_ = FileProxy;

        template <typename ImplRefTraits>
        using Stub_ = FileStub<ImplRefTraits>;

        using RequestValidator_ = FileRequestValidator;
        using ResponseValidator_ = FileResponseValidator;
        enum MethodMinVersions : uint32_t {
            kCloseMinVersion = 0,
            kReadMinVersion = 0,
            kWriteMinVersion = 0,
            kTellMinVersion = 0,
            kSeekMinVersion = 0,
            kStatMinVersion = 0,
            kTruncateMinVersion = 0,
            kTouchMinVersion = 0,
            kDupMinVersion = 0,
            kFlushMinVersion = 0,
            kLockMinVersion = 0,
            kUnlockMinVersion = 0,
            kAsHandleMinVersion = 0,
        };
        virtual ~File() { }

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool Close(::filesystem::mojom::FileError* err);

        using CloseCallback = base::Callback<void(::filesystem::mojom::FileError)>;
        virtual void Close(const CloseCallback& callback) = 0;

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool Read(uint32_t num_bytes_to_read, int64_t offset, ::filesystem::mojom::Whence whence, ::filesystem::mojom::FileError* error, base::Optional<std::vector<uint8_t>>* bytes_read);

        using ReadCallback = base::Callback<void(::filesystem::mojom::FileError, const base::Optional<std::vector<uint8_t>>&)>;
        virtual void Read(uint32_t num_bytes_to_read, int64_t offset, ::filesystem::mojom::Whence whence, const ReadCallback& callback) = 0;

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool Write(const std::vector<uint8_t>& bytes_to_write, int64_t offset, ::filesystem::mojom::Whence whence, ::filesystem::mojom::FileError* error, uint32_t* num_bytes_written);

        using WriteCallback = base::Callback<void(::filesystem::mojom::FileError, uint32_t)>;
        virtual void Write(const std::vector<uint8_t>& bytes_to_write, int64_t offset, ::filesystem::mojom::Whence whence, const WriteCallback& callback) = 0;

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool Tell(::filesystem::mojom::FileError* error, int64_t* position);

        using TellCallback = base::Callback<void(::filesystem::mojom::FileError, int64_t)>;
        virtual void Tell(const TellCallback& callback) = 0;

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool Seek(int64_t offset, ::filesystem::mojom::Whence whence, ::filesystem::mojom::FileError* error, int64_t* position);

        using SeekCallback = base::Callback<void(::filesystem::mojom::FileError, int64_t)>;
        virtual void Seek(int64_t offset, ::filesystem::mojom::Whence whence, const SeekCallback& callback) = 0;

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool Stat(::filesystem::mojom::FileError* error, ::filesystem::mojom::FileInformationPtr* file_information);

        using StatCallback = base::Callback<void(::filesystem::mojom::FileError, ::filesystem::mojom::FileInformationPtr)>;
        virtual void Stat(const StatCallback& callback) = 0;

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool Truncate(int64_t size, ::filesystem::mojom::FileError* error);

        using TruncateCallback = base::Callback<void(::filesystem::mojom::FileError)>;
        virtual void Truncate(int64_t size, const TruncateCallback& callback) = 0;

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool Touch(::filesystem::mojom::TimespecOrNowPtr atime, ::filesystem::mojom::TimespecOrNowPtr mtime, ::filesystem::mojom::FileError* error);

        using TouchCallback = base::Callback<void(::filesystem::mojom::FileError)>;
        virtual void Touch(::filesystem::mojom::TimespecOrNowPtr atime, ::filesystem::mojom::TimespecOrNowPtr mtime, const TouchCallback& callback) = 0;

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool Dup(FileRequest file, ::filesystem::mojom::FileError* error);

        using DupCallback = base::Callback<void(::filesystem::mojom::FileError)>;
        virtual void Dup(FileRequest file, const DupCallback& callback) = 0;

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool Flush(::filesystem::mojom::FileError* error);

        using FlushCallback = base::Callback<void(::filesystem::mojom::FileError)>;
        virtual void Flush(const FlushCallback& callback) = 0;

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool Lock(::filesystem::mojom::FileError* error);

        using LockCallback = base::Callback<void(::filesystem::mojom::FileError)>;
        virtual void Lock(const LockCallback& callback) = 0;

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool Unlock(::filesystem::mojom::FileError* error);

        using UnlockCallback = base::Callback<void(::filesystem::mojom::FileError)>;
        virtual void Unlock(const UnlockCallback& callback) = 0;

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool AsHandle(::filesystem::mojom::FileError* error, base::File* file_handle);

        using AsHandleCallback = base::Callback<void(::filesystem::mojom::FileError, base::File)>;
        virtual void AsHandle(const AsHandleCallback& callback) = 0;
    };

    class FileProxy
        : public File {
    public:
        explicit FileProxy(mojo::MessageReceiverWithResponder* receiver);
        bool Close(::filesystem::mojom::FileError* err) override;
        void Close(const CloseCallback& callback) override;
        bool Read(uint32_t num_bytes_to_read, int64_t offset, ::filesystem::mojom::Whence whence, ::filesystem::mojom::FileError* error, base::Optional<std::vector<uint8_t>>* bytes_read) override;
        void Read(uint32_t num_bytes_to_read, int64_t offset, ::filesystem::mojom::Whence whence, const ReadCallback& callback) override;
        bool Write(const std::vector<uint8_t>& bytes_to_write, int64_t offset, ::filesystem::mojom::Whence whence, ::filesystem::mojom::FileError* error, uint32_t* num_bytes_written) override;
        void Write(const std::vector<uint8_t>& bytes_to_write, int64_t offset, ::filesystem::mojom::Whence whence, const WriteCallback& callback) override;
        bool Tell(::filesystem::mojom::FileError* error, int64_t* position) override;
        void Tell(const TellCallback& callback) override;
        bool Seek(int64_t offset, ::filesystem::mojom::Whence whence, ::filesystem::mojom::FileError* error, int64_t* position) override;
        void Seek(int64_t offset, ::filesystem::mojom::Whence whence, const SeekCallback& callback) override;
        bool Stat(::filesystem::mojom::FileError* error, ::filesystem::mojom::FileInformationPtr* file_information) override;
        void Stat(const StatCallback& callback) override;
        bool Truncate(int64_t size, ::filesystem::mojom::FileError* error) override;
        void Truncate(int64_t size, const TruncateCallback& callback) override;
        bool Touch(::filesystem::mojom::TimespecOrNowPtr atime, ::filesystem::mojom::TimespecOrNowPtr mtime, ::filesystem::mojom::FileError* error) override;
        void Touch(::filesystem::mojom::TimespecOrNowPtr atime, ::filesystem::mojom::TimespecOrNowPtr mtime, const TouchCallback& callback) override;
        bool Dup(FileRequest file, ::filesystem::mojom::FileError* error) override;
        void Dup(FileRequest file, const DupCallback& callback) override;
        bool Flush(::filesystem::mojom::FileError* error) override;
        void Flush(const FlushCallback& callback) override;
        bool Lock(::filesystem::mojom::FileError* error) override;
        void Lock(const LockCallback& callback) override;
        bool Unlock(::filesystem::mojom::FileError* error) override;
        void Unlock(const UnlockCallback& callback) override;
        bool AsHandle(::filesystem::mojom::FileError* error, base::File* file_handle) override;
        void AsHandle(const AsHandleCallback& callback) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class FileStubDispatch {
    public:
        static bool Accept(File* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(File* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<File>>
    class FileStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        FileStub() { }
        ~FileStub() override { }

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
            return FileStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return FileStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class FileRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class FileResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

} // namespace mojom
} // namespace filesystem

namespace mojo {

} // namespace mojo

#endif // COMPONENTS_FILESYSTEM_PUBLIC_INTERFACES_FILE_MOJOM_H_