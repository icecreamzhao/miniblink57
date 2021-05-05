// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_FILESYSTEM_PUBLIC_INTERFACES_FILE_SYSTEM_MOJOM_H_
#define COMPONENTS_FILESYSTEM_PUBLIC_INTERFACES_FILE_SYSTEM_MOJOM_H_

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
#include "components/filesystem/public/interfaces/directory.mojom.h"
#include "components/filesystem/public/interfaces/file_system.mojom-shared.h"
#include "components/filesystem/public/interfaces/types.mojom.h"
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
    class FileSystem;
    using FileSystemPtr = mojo::InterfacePtr<FileSystem>;
    using FileSystemPtrInfo = mojo::InterfacePtrInfo<FileSystem>;
    using ThreadSafeFileSystemPtr = mojo::ThreadSafeInterfacePtr<FileSystem>;
    using FileSystemRequest = mojo::InterfaceRequest<FileSystem>;
    using FileSystemAssociatedPtr = mojo::AssociatedInterfacePtr<FileSystem>;
    using ThreadSafeFileSystemAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<FileSystem>;
    using FileSystemAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<FileSystem>;
    using FileSystemAssociatedRequest = mojo::AssociatedInterfaceRequest<FileSystem>;

    class FileSystemProxy;

    template <typename ImplRefTraits>
    class FileSystemStub;

    class FileSystemRequestValidator;
    class FileSystemResponseValidator;

    class FileSystem
        : public FileSystemInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = true;

        using Proxy_ = FileSystemProxy;

        template <typename ImplRefTraits>
        using Stub_ = FileSystemStub<ImplRefTraits>;

        using RequestValidator_ = FileSystemRequestValidator;
        using ResponseValidator_ = FileSystemResponseValidator;
        enum MethodMinVersions : uint32_t {
            kOpenTempDirectoryMinVersion = 0,
            kOpenPersistentFileSystemMinVersion = 0,
        };
        virtual ~FileSystem() { }

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool OpenTempDirectory(::filesystem::mojom::DirectoryRequest directory, ::filesystem::mojom::FileError* error);

        using OpenTempDirectoryCallback = base::Callback<void(::filesystem::mojom::FileError)>;
        virtual void OpenTempDirectory(::filesystem::mojom::DirectoryRequest directory, const OpenTempDirectoryCallback& callback) = 0;

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool OpenPersistentFileSystem(::filesystem::mojom::DirectoryRequest directory, ::filesystem::mojom::FileError* error);

        using OpenPersistentFileSystemCallback = base::Callback<void(::filesystem::mojom::FileError)>;
        virtual void OpenPersistentFileSystem(::filesystem::mojom::DirectoryRequest directory, const OpenPersistentFileSystemCallback& callback) = 0;
    };

    class FileSystemProxy
        : public FileSystem {
    public:
        explicit FileSystemProxy(mojo::MessageReceiverWithResponder* receiver);
        bool OpenTempDirectory(::filesystem::mojom::DirectoryRequest directory, ::filesystem::mojom::FileError* error) override;
        void OpenTempDirectory(::filesystem::mojom::DirectoryRequest directory, const OpenTempDirectoryCallback& callback) override;
        bool OpenPersistentFileSystem(::filesystem::mojom::DirectoryRequest directory, ::filesystem::mojom::FileError* error) override;
        void OpenPersistentFileSystem(::filesystem::mojom::DirectoryRequest directory, const OpenPersistentFileSystemCallback& callback) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class FileSystemStubDispatch {
    public:
        static bool Accept(FileSystem* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(FileSystem* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<FileSystem>>
    class FileSystemStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        FileSystemStub() { }
        ~FileSystemStub() override { }

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
            return FileSystemStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return FileSystemStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class FileSystemRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class FileSystemResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

} // namespace mojom
} // namespace filesystem

namespace mojo {

} // namespace mojo

#endif // COMPONENTS_FILESYSTEM_PUBLIC_INTERFACES_FILE_SYSTEM_MOJOM_H_