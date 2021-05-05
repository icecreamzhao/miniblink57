// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_LEVELDB_PUBLIC_INTERFACES_LEVELDB_MOJOM_H_
#define COMPONENTS_LEVELDB_PUBLIC_INTERFACES_LEVELDB_MOJOM_H_

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
#include "components/leveldb/public/interfaces/leveldb.mojom-shared.h"
#include "mojo/common/unguessable_token.mojom.h"
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

namespace leveldb {
namespace mojom {
    class LevelDBService;
    using LevelDBServicePtr = mojo::InterfacePtr<LevelDBService>;
    using LevelDBServicePtrInfo = mojo::InterfacePtrInfo<LevelDBService>;
    using ThreadSafeLevelDBServicePtr = mojo::ThreadSafeInterfacePtr<LevelDBService>;
    using LevelDBServiceRequest = mojo::InterfaceRequest<LevelDBService>;
    using LevelDBServiceAssociatedPtr = mojo::AssociatedInterfacePtr<LevelDBService>;
    using ThreadSafeLevelDBServiceAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<LevelDBService>;
    using LevelDBServiceAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<LevelDBService>;
    using LevelDBServiceAssociatedRequest = mojo::AssociatedInterfaceRequest<LevelDBService>;

    class LevelDBDatabase;
    using LevelDBDatabasePtr = mojo::InterfacePtr<LevelDBDatabase>;
    using LevelDBDatabasePtrInfo = mojo::InterfacePtrInfo<LevelDBDatabase>;
    using ThreadSafeLevelDBDatabasePtr = mojo::ThreadSafeInterfacePtr<LevelDBDatabase>;
    using LevelDBDatabaseRequest = mojo::InterfaceRequest<LevelDBDatabase>;
    using LevelDBDatabaseAssociatedPtr = mojo::AssociatedInterfacePtr<LevelDBDatabase>;
    using ThreadSafeLevelDBDatabaseAssociatedPtr = mojo::ThreadSafeAssociatedInterfacePtr<LevelDBDatabase>;
    using LevelDBDatabaseAssociatedPtrInfo = mojo::AssociatedInterfacePtrInfo<LevelDBDatabase>;
    using LevelDBDatabaseAssociatedRequest = mojo::AssociatedInterfaceRequest<LevelDBDatabase>;

    class BatchedOperation;
    using BatchedOperationPtr = mojo::StructPtr<BatchedOperation>;

    class KeyValue;
    using KeyValuePtr = mojo::StructPtr<KeyValue>;

    class OpenOptions;
    using OpenOptionsPtr = mojo::StructPtr<OpenOptions>;

    class LevelDBServiceProxy;

    template <typename ImplRefTraits>
    class LevelDBServiceStub;

    class LevelDBServiceRequestValidator;
    class LevelDBServiceResponseValidator;

    class LevelDBService
        : public LevelDBServiceInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = true;
        static constexpr bool HasSyncMethods_ = false;

        using Proxy_ = LevelDBServiceProxy;

        template <typename ImplRefTraits>
        using Stub_ = LevelDBServiceStub<ImplRefTraits>;

        using RequestValidator_ = LevelDBServiceRequestValidator;
        using ResponseValidator_ = LevelDBServiceResponseValidator;
        enum MethodMinVersions : uint32_t {
            kOpenMinVersion = 0,
            kOpenWithOptionsMinVersion = 0,
            kOpenInMemoryMinVersion = 0,
            kDestroyMinVersion = 0,
        };
        virtual ~LevelDBService() { }

        using OpenCallback = base::Callback<void(DatabaseError)>;
        virtual void Open(::filesystem::mojom::DirectoryPtr directory, const std::string& dbname, LevelDBDatabaseAssociatedRequest database, const OpenCallback& callback) = 0;

        using OpenWithOptionsCallback = base::Callback<void(DatabaseError)>;
        virtual void OpenWithOptions(OpenOptionsPtr options, ::filesystem::mojom::DirectoryPtr directory, const std::string& dbname, LevelDBDatabaseAssociatedRequest database, const OpenWithOptionsCallback& callback) = 0;

        using OpenInMemoryCallback = base::Callback<void(DatabaseError)>;
        virtual void OpenInMemory(LevelDBDatabaseAssociatedRequest database, const OpenInMemoryCallback& callback) = 0;

        using DestroyCallback = base::Callback<void(DatabaseError)>;
        virtual void Destroy(::filesystem::mojom::DirectoryPtr directory, const std::string& dbname, const DestroyCallback& callback) = 0;
    };

    class LevelDBDatabaseProxy;

    template <typename ImplRefTraits>
    class LevelDBDatabaseStub;

    class LevelDBDatabaseRequestValidator;
    class LevelDBDatabaseResponseValidator;

    class LevelDBDatabase
        : public LevelDBDatabaseInterfaceBase {
    public:
        static const char Name_[];
        static constexpr uint32_t Version_ = 0;
        static constexpr bool PassesAssociatedKinds_ = false;
        static constexpr bool HasSyncMethods_ = true;

        using Proxy_ = LevelDBDatabaseProxy;

        template <typename ImplRefTraits>
        using Stub_ = LevelDBDatabaseStub<ImplRefTraits>;

        using RequestValidator_ = LevelDBDatabaseRequestValidator;
        using ResponseValidator_ = LevelDBDatabaseResponseValidator;
        enum MethodMinVersions : uint32_t {
            kPutMinVersion = 0,
            kDeleteMinVersion = 0,
            kDeletePrefixedMinVersion = 0,
            kWriteMinVersion = 0,
            kGetMinVersion = 0,
            kGetPrefixedMinVersion = 0,
            kGetSnapshotMinVersion = 0,
            kReleaseSnapshotMinVersion = 0,
            kGetFromSnapshotMinVersion = 0,
            kNewIteratorMinVersion = 0,
            kNewIteratorFromSnapshotMinVersion = 0,
            kReleaseIteratorMinVersion = 0,
            kIteratorSeekToFirstMinVersion = 0,
            kIteratorSeekToLastMinVersion = 0,
            kIteratorSeekMinVersion = 0,
            kIteratorNextMinVersion = 0,
            kIteratorPrevMinVersion = 0,
        };
        virtual ~LevelDBDatabase() { }

        using PutCallback = base::Callback<void(DatabaseError)>;
        virtual void Put(const std::vector<uint8_t>& key, const std::vector<uint8_t>& value, const PutCallback& callback) = 0;

        using DeleteCallback = base::Callback<void(DatabaseError)>;
        virtual void Delete(const std::vector<uint8_t>& key, const DeleteCallback& callback) = 0;

        using DeletePrefixedCallback = base::Callback<void(DatabaseError)>;
        virtual void DeletePrefixed(const std::vector<uint8_t>& key_prefix, const DeletePrefixedCallback& callback) = 0;

        using WriteCallback = base::Callback<void(DatabaseError)>;
        virtual void Write(std::vector<BatchedOperationPtr> operations, const WriteCallback& callback) = 0;

        using GetCallback = base::Callback<void(DatabaseError, const std::vector<uint8_t>&)>;
        virtual void Get(const std::vector<uint8_t>& key, const GetCallback& callback) = 0;

        using GetPrefixedCallback = base::Callback<void(DatabaseError, std::vector<KeyValuePtr>)>;
        virtual void GetPrefixed(const std::vector<uint8_t>& key_prefix, const GetPrefixedCallback& callback) = 0;

        using GetSnapshotCallback = base::Callback<void(const base::UnguessableToken&)>;
        virtual void GetSnapshot(const GetSnapshotCallback& callback) = 0;

        virtual void ReleaseSnapshot(const base::UnguessableToken& snapshot) = 0;

        using GetFromSnapshotCallback = base::Callback<void(DatabaseError, const std::vector<uint8_t>&)>;
        virtual void GetFromSnapshot(const base::UnguessableToken& snapshot, const std::vector<uint8_t>& key, const GetFromSnapshotCallback& callback) = 0;

        using NewIteratorCallback = base::Callback<void(const base::UnguessableToken&)>;
        virtual void NewIterator(const NewIteratorCallback& callback) = 0;

        using NewIteratorFromSnapshotCallback = base::Callback<void(const base::Optional<base::UnguessableToken>&)>;
        virtual void NewIteratorFromSnapshot(const base::UnguessableToken& snapshot, const NewIteratorFromSnapshotCallback& callback) = 0;

        virtual void ReleaseIterator(const base::UnguessableToken& iterator) = 0;

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool IteratorSeekToFirst(const base::UnguessableToken& iterator, bool* valid, DatabaseError* status, base::Optional<std::vector<uint8_t>>* key, base::Optional<std::vector<uint8_t>>* value);

        using IteratorSeekToFirstCallback = base::Callback<void(bool, DatabaseError, const base::Optional<std::vector<uint8_t>>&, const base::Optional<std::vector<uint8_t>>&)>;
        virtual void IteratorSeekToFirst(const base::UnguessableToken& iterator, const IteratorSeekToFirstCallback& callback) = 0;

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool IteratorSeekToLast(const base::UnguessableToken& iterator, bool* valid, DatabaseError* status, base::Optional<std::vector<uint8_t>>* key, base::Optional<std::vector<uint8_t>>* value);

        using IteratorSeekToLastCallback = base::Callback<void(bool, DatabaseError, const base::Optional<std::vector<uint8_t>>&, const base::Optional<std::vector<uint8_t>>&)>;
        virtual void IteratorSeekToLast(const base::UnguessableToken& iterator, const IteratorSeekToLastCallback& callback) = 0;

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool IteratorSeek(const base::UnguessableToken& iterator, const std::vector<uint8_t>& target, bool* valid, DatabaseError* status, base::Optional<std::vector<uint8_t>>* key, base::Optional<std::vector<uint8_t>>* value);

        using IteratorSeekCallback = base::Callback<void(bool, DatabaseError, const base::Optional<std::vector<uint8_t>>&, const base::Optional<std::vector<uint8_t>>&)>;
        virtual void IteratorSeek(const base::UnguessableToken& iterator, const std::vector<uint8_t>& target, const IteratorSeekCallback& callback) = 0;

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool IteratorNext(const base::UnguessableToken& iterator, bool* valid, DatabaseError* status, base::Optional<std::vector<uint8_t>>* key, base::Optional<std::vector<uint8_t>>* value);

        using IteratorNextCallback = base::Callback<void(bool, DatabaseError, const base::Optional<std::vector<uint8_t>>&, const base::Optional<std::vector<uint8_t>>&)>;
        virtual void IteratorNext(const base::UnguessableToken& iterator, const IteratorNextCallback& callback) = 0;

        // Sync method. This signature is used by the client side; the service side
        // should implement the signature with callback below.
        virtual bool IteratorPrev(const base::UnguessableToken& iterator, bool* valid, DatabaseError* status, base::Optional<std::vector<uint8_t>>* key, base::Optional<std::vector<uint8_t>>* value);

        using IteratorPrevCallback = base::Callback<void(bool, DatabaseError, const base::Optional<std::vector<uint8_t>>&, const base::Optional<std::vector<uint8_t>>&)>;
        virtual void IteratorPrev(const base::UnguessableToken& iterator, const IteratorPrevCallback& callback) = 0;
    };

    class LevelDBServiceProxy
        : public LevelDBService {
    public:
        explicit LevelDBServiceProxy(mojo::MessageReceiverWithResponder* receiver);
        void Open(::filesystem::mojom::DirectoryPtr directory, const std::string& dbname, LevelDBDatabaseAssociatedRequest database, const OpenCallback& callback) override;
        void OpenWithOptions(OpenOptionsPtr options, ::filesystem::mojom::DirectoryPtr directory, const std::string& dbname, LevelDBDatabaseAssociatedRequest database, const OpenWithOptionsCallback& callback) override;
        void OpenInMemory(LevelDBDatabaseAssociatedRequest database, const OpenInMemoryCallback& callback) override;
        void Destroy(::filesystem::mojom::DirectoryPtr directory, const std::string& dbname, const DestroyCallback& callback) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };

    class LevelDBDatabaseProxy
        : public LevelDBDatabase {
    public:
        explicit LevelDBDatabaseProxy(mojo::MessageReceiverWithResponder* receiver);
        void Put(const std::vector<uint8_t>& key, const std::vector<uint8_t>& value, const PutCallback& callback) override;
        void Delete(const std::vector<uint8_t>& key, const DeleteCallback& callback) override;
        void DeletePrefixed(const std::vector<uint8_t>& key_prefix, const DeletePrefixedCallback& callback) override;
        void Write(std::vector<BatchedOperationPtr> operations, const WriteCallback& callback) override;
        void Get(const std::vector<uint8_t>& key, const GetCallback& callback) override;
        void GetPrefixed(const std::vector<uint8_t>& key_prefix, const GetPrefixedCallback& callback) override;
        void GetSnapshot(const GetSnapshotCallback& callback) override;
        void ReleaseSnapshot(const base::UnguessableToken& snapshot) override;
        void GetFromSnapshot(const base::UnguessableToken& snapshot, const std::vector<uint8_t>& key, const GetFromSnapshotCallback& callback) override;
        void NewIterator(const NewIteratorCallback& callback) override;
        void NewIteratorFromSnapshot(const base::UnguessableToken& snapshot, const NewIteratorFromSnapshotCallback& callback) override;
        void ReleaseIterator(const base::UnguessableToken& iterator) override;
        bool IteratorSeekToFirst(const base::UnguessableToken& iterator, bool* valid, DatabaseError* status, base::Optional<std::vector<uint8_t>>* key, base::Optional<std::vector<uint8_t>>* value) override;
        void IteratorSeekToFirst(const base::UnguessableToken& iterator, const IteratorSeekToFirstCallback& callback) override;
        bool IteratorSeekToLast(const base::UnguessableToken& iterator, bool* valid, DatabaseError* status, base::Optional<std::vector<uint8_t>>* key, base::Optional<std::vector<uint8_t>>* value) override;
        void IteratorSeekToLast(const base::UnguessableToken& iterator, const IteratorSeekToLastCallback& callback) override;
        bool IteratorSeek(const base::UnguessableToken& iterator, const std::vector<uint8_t>& target, bool* valid, DatabaseError* status, base::Optional<std::vector<uint8_t>>* key, base::Optional<std::vector<uint8_t>>* value) override;
        void IteratorSeek(const base::UnguessableToken& iterator, const std::vector<uint8_t>& target, const IteratorSeekCallback& callback) override;
        bool IteratorNext(const base::UnguessableToken& iterator, bool* valid, DatabaseError* status, base::Optional<std::vector<uint8_t>>* key, base::Optional<std::vector<uint8_t>>* value) override;
        void IteratorNext(const base::UnguessableToken& iterator, const IteratorNextCallback& callback) override;
        bool IteratorPrev(const base::UnguessableToken& iterator, bool* valid, DatabaseError* status, base::Optional<std::vector<uint8_t>>* key, base::Optional<std::vector<uint8_t>>* value) override;
        void IteratorPrev(const base::UnguessableToken& iterator, const IteratorPrevCallback& callback) override;

        void set_group_controller(
            scoped_refptr<mojo::AssociatedGroupController> group_controller)
        {
            group_controller_ = std::move(group_controller);
        }

    private:
        mojo::MessageReceiverWithResponder* receiver_;
        scoped_refptr<mojo::AssociatedGroupController> group_controller_;
    };
    class LevelDBServiceStubDispatch {
    public:
        static bool Accept(LevelDBService* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(LevelDBService* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<LevelDBService>>
    class LevelDBServiceStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        LevelDBServiceStub() { }
        ~LevelDBServiceStub() override { }

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
            return LevelDBServiceStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return LevelDBServiceStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class LevelDBDatabaseStubDispatch {
    public:
        static bool Accept(LevelDBDatabase* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message);
        static bool AcceptWithResponder(LevelDBDatabase* impl,
            mojo::internal::SerializationContext* context,
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder);
    };

    template <typename ImplRefTraits = mojo::RawPtrImplRefTraits<LevelDBDatabase>>
    class LevelDBDatabaseStub
        : public NON_EXPORTED_BASE(mojo::MessageReceiverWithResponderStatus) {
    public:
        using ImplPointerType = typename ImplRefTraits::PointerType;

        LevelDBDatabaseStub() { }
        ~LevelDBDatabaseStub() override { }

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
            return LevelDBDatabaseStubDispatch::Accept(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message);
        }

        bool AcceptWithResponder(
            mojo::Message* message,
            mojo::MessageReceiverWithStatus* responder) override
        {
            if (ImplRefTraits::IsNull(sink_))
                return false;
            return LevelDBDatabaseStubDispatch::AcceptWithResponder(
                ImplRefTraits::GetRawPointer(&sink_), &serialization_context_, message,
                responder);
        }

    private:
        ImplPointerType sink_;
        mojo::internal::SerializationContext serialization_context_;
    };
    class LevelDBServiceRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class LevelDBDatabaseRequestValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class LevelDBServiceResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };
    class LevelDBDatabaseResponseValidator : public NON_EXPORTED_BASE(mojo::MessageReceiver) {
    public:
        bool Accept(mojo::Message* message) override;
    };

    class BatchedOperation {
    public:
        using DataView = BatchedOperationDataView;
        using Data_ = internal::BatchedOperation_Data;

        static BatchedOperationPtr New();

        template <typename U>
        static BatchedOperationPtr From(const U& u)
        {
            return mojo::TypeConverter<BatchedOperationPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, BatchedOperation>::Convert(*this);
        }

        BatchedOperation();
        ~BatchedOperation();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = BatchedOperationPtr>
        BatchedOperationPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, BatchedOperation>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                BatchedOperation::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                BatchedOperation::DataView, std::vector<uint8_t>>(
                input, output);
        }

        BatchOperationType type;
        std::vector<uint8_t> key;
        base::Optional<std::vector<uint8_t>> value;
    };

    class KeyValue {
    public:
        using DataView = KeyValueDataView;
        using Data_ = internal::KeyValue_Data;

        static KeyValuePtr New();

        template <typename U>
        static KeyValuePtr From(const U& u)
        {
            return mojo::TypeConverter<KeyValuePtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, KeyValue>::Convert(*this);
        }

        KeyValue();
        ~KeyValue();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = KeyValuePtr>
        KeyValuePtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, KeyValue>::value>::type* = nullptr>
        bool Equals(const T& other) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                KeyValue::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                KeyValue::DataView, std::vector<uint8_t>>(
                input, output);
        }

        std::vector<uint8_t> key;
        std::vector<uint8_t> value;
    };

    class OpenOptions {
    public:
        using DataView = OpenOptionsDataView;
        using Data_ = internal::OpenOptions_Data;

        static OpenOptionsPtr New();

        template <typename U>
        static OpenOptionsPtr From(const U& u)
        {
            return mojo::TypeConverter<OpenOptionsPtr, U>::Convert(u);
        }

        template <typename U>
        U To() const
        {
            return mojo::TypeConverter<U, OpenOptions>::Convert(*this);
        }

        OpenOptions();
        ~OpenOptions();

        // Clone() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Clone() or copy
        // constructor/assignment are available for members.
        template <typename StructPtrType = OpenOptionsPtr>
        OpenOptionsPtr Clone() const;

        // Equals() is a template so it is only instantiated if it is used. Thus, the
        // bindings generator does not need to know whether Equals() or == operator
        // are available for members.
        template <typename T,
            typename std::enable_if<std::is_same<
                T, OpenOptions>::value>::type* = nullptr>
        bool Equals(const T& other) const;
        size_t Hash(size_t seed) const;

        template <typename UserType>
        static std::vector<uint8_t> Serialize(UserType* input)
        {
            return mojo::internal::StructSerializeImpl<
                OpenOptions::DataView, std::vector<uint8_t>>(input);
        }

        template <typename UserType>
        static bool Deserialize(const std::vector<uint8_t>& input,
            UserType* output)
        {
            return mojo::internal::StructDeserializeImpl<
                OpenOptions::DataView, std::vector<uint8_t>>(
                input, output);
        }

        bool create_if_missing;
        bool error_if_exists;
        bool paranoid_checks;
        uint64_t write_buffer_size;
        int32_t max_open_files;
    };

    template <typename StructPtrType>
    BatchedOperationPtr BatchedOperation::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->type = mojo::internal::Clone(type);
        rv->key = mojo::internal::Clone(key);
        rv->value = mojo::internal::Clone(value);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, BatchedOperation>::value>::type*>
    bool BatchedOperation::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->type, other.type))
            return false;
        if (!mojo::internal::Equals(this->key, other.key))
            return false;
        if (!mojo::internal::Equals(this->value, other.value))
            return false;
        return true;
    }
    template <typename StructPtrType>
    KeyValuePtr KeyValue::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->key = mojo::internal::Clone(key);
        rv->value = mojo::internal::Clone(value);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, KeyValue>::value>::type*>
    bool KeyValue::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->key, other.key))
            return false;
        if (!mojo::internal::Equals(this->value, other.value))
            return false;
        return true;
    }
    template <typename StructPtrType>
    OpenOptionsPtr OpenOptions::Clone() const
    {
        // Use StructPtrType to prevent the compiler from trying to compile this
        // without being asked.
        StructPtrType rv(New());
        rv->create_if_missing = mojo::internal::Clone(create_if_missing);
        rv->error_if_exists = mojo::internal::Clone(error_if_exists);
        rv->paranoid_checks = mojo::internal::Clone(paranoid_checks);
        rv->write_buffer_size = mojo::internal::Clone(write_buffer_size);
        rv->max_open_files = mojo::internal::Clone(max_open_files);
        return rv;
    }

    template <typename T,
        typename std::enable_if<std::is_same<
            T, OpenOptions>::value>::type*>
    bool OpenOptions::Equals(const T& other) const
    {
        if (!mojo::internal::Equals(this->create_if_missing, other.create_if_missing))
            return false;
        if (!mojo::internal::Equals(this->error_if_exists, other.error_if_exists))
            return false;
        if (!mojo::internal::Equals(this->paranoid_checks, other.paranoid_checks))
            return false;
        if (!mojo::internal::Equals(this->write_buffer_size, other.write_buffer_size))
            return false;
        if (!mojo::internal::Equals(this->max_open_files, other.max_open_files))
            return false;
        return true;
    }

} // namespace mojom
} // namespace leveldb

namespace mojo {

template <>
struct StructTraits<::leveldb::mojom::BatchedOperation::DataView,
    ::leveldb::mojom::BatchedOperationPtr> {
    static bool IsNull(const ::leveldb::mojom::BatchedOperationPtr& input) { return !input; }
    static void SetToNull(::leveldb::mojom::BatchedOperationPtr* output) { output->reset(); }

    static decltype(::leveldb::mojom::BatchedOperation::type) type(
        const ::leveldb::mojom::BatchedOperationPtr& input)
    {
        return input->type;
    }

    static const decltype(::leveldb::mojom::BatchedOperation::key)& key(
        const ::leveldb::mojom::BatchedOperationPtr& input)
    {
        return input->key;
    }

    static const decltype(::leveldb::mojom::BatchedOperation::value)& value(
        const ::leveldb::mojom::BatchedOperationPtr& input)
    {
        return input->value;
    }

    static bool Read(::leveldb::mojom::BatchedOperation::DataView input, ::leveldb::mojom::BatchedOperationPtr* output);
};

template <>
struct StructTraits<::leveldb::mojom::KeyValue::DataView,
    ::leveldb::mojom::KeyValuePtr> {
    static bool IsNull(const ::leveldb::mojom::KeyValuePtr& input) { return !input; }
    static void SetToNull(::leveldb::mojom::KeyValuePtr* output) { output->reset(); }

    static const decltype(::leveldb::mojom::KeyValue::key)& key(
        const ::leveldb::mojom::KeyValuePtr& input)
    {
        return input->key;
    }

    static const decltype(::leveldb::mojom::KeyValue::value)& value(
        const ::leveldb::mojom::KeyValuePtr& input)
    {
        return input->value;
    }

    static bool Read(::leveldb::mojom::KeyValue::DataView input, ::leveldb::mojom::KeyValuePtr* output);
};

template <>
struct StructTraits<::leveldb::mojom::OpenOptions::DataView,
    ::leveldb::mojom::OpenOptionsPtr> {
    static bool IsNull(const ::leveldb::mojom::OpenOptionsPtr& input) { return !input; }
    static void SetToNull(::leveldb::mojom::OpenOptionsPtr* output) { output->reset(); }

    static decltype(::leveldb::mojom::OpenOptions::create_if_missing) create_if_missing(
        const ::leveldb::mojom::OpenOptionsPtr& input)
    {
        return input->create_if_missing;
    }

    static decltype(::leveldb::mojom::OpenOptions::error_if_exists) error_if_exists(
        const ::leveldb::mojom::OpenOptionsPtr& input)
    {
        return input->error_if_exists;
    }

    static decltype(::leveldb::mojom::OpenOptions::paranoid_checks) paranoid_checks(
        const ::leveldb::mojom::OpenOptionsPtr& input)
    {
        return input->paranoid_checks;
    }

    static decltype(::leveldb::mojom::OpenOptions::write_buffer_size) write_buffer_size(
        const ::leveldb::mojom::OpenOptionsPtr& input)
    {
        return input->write_buffer_size;
    }

    static decltype(::leveldb::mojom::OpenOptions::max_open_files) max_open_files(
        const ::leveldb::mojom::OpenOptionsPtr& input)
    {
        return input->max_open_files;
    }

    static bool Read(::leveldb::mojom::OpenOptions::DataView input, ::leveldb::mojom::OpenOptionsPtr* output);
};

} // namespace mojo

#endif // COMPONENTS_LEVELDB_PUBLIC_INTERFACES_LEVELDB_MOJOM_H_