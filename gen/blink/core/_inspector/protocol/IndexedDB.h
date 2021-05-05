// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef blink_protocol_IndexedDB_h
#define blink_protocol_IndexedDB_h

#include "core/CoreExport.h"
#include "core/inspector/protocol/Protocol.h"
// For each imported domain we generate a ValueConversions struct instead of a full domain definition
// and include Domain::API version from there.
#include "core/inspector/protocol/Runtime.h"

namespace blink {
namespace protocol {
    namespace IndexedDB {

        // ------------- Forward and enum declarations.
        // Database with an array of object stores.
        class DatabaseWithObjectStores;
        // Object store.
        class ObjectStore;
        // Object store index.
        class ObjectStoreIndex;
        // Key.
        class Key;
        // Key range.
        class KeyRange;
        // Data entry.
        class DataEntry;
        // Key path.
        class KeyPath;

        // ------------- Type and builder declarations.

        // Database with an array of object stores.
        class CORE_EXPORT DatabaseWithObjectStores : public Serializable {
            PROTOCOL_DISALLOW_COPY(DatabaseWithObjectStores);

        public:
            static std::unique_ptr<DatabaseWithObjectStores> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~DatabaseWithObjectStores() override { }

            String getName() { return m_name; }
            void setName(const String& value) { m_name = value; }

            int getVersion() { return m_version; }
            void setVersion(int value) { m_version = value; }

            protocol::Array<protocol::IndexedDB::ObjectStore>* getObjectStores() { return m_objectStores.get(); }
            void setObjectStores(std::unique_ptr<protocol::Array<protocol::IndexedDB::ObjectStore>> value) { m_objectStores = std::move(value); }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<DatabaseWithObjectStores> clone() const;

            template <int STATE>
            class DatabaseWithObjectStoresBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    NameSet = 1 << 1,
                    VersionSet = 1 << 2,
                    ObjectStoresSet = 1 << 3,
                    AllFieldsSet = (NameSet | VersionSet | ObjectStoresSet | 0)
                };

                DatabaseWithObjectStoresBuilder<STATE | NameSet>& setName(const String& value)
                {
                    static_assert(!(STATE & NameSet), "property name should not be set yet");
                    m_result->setName(value);
                    return castState<NameSet>();
                }

                DatabaseWithObjectStoresBuilder<STATE | VersionSet>& setVersion(int value)
                {
                    static_assert(!(STATE & VersionSet), "property version should not be set yet");
                    m_result->setVersion(value);
                    return castState<VersionSet>();
                }

                DatabaseWithObjectStoresBuilder<STATE | ObjectStoresSet>& setObjectStores(std::unique_ptr<protocol::Array<protocol::IndexedDB::ObjectStore>> value)
                {
                    static_assert(!(STATE & ObjectStoresSet), "property objectStores should not be set yet");
                    m_result->setObjectStores(std::move(value));
                    return castState<ObjectStoresSet>();
                }

                std::unique_ptr<DatabaseWithObjectStores> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class DatabaseWithObjectStores;
                DatabaseWithObjectStoresBuilder()
                    : m_result(new DatabaseWithObjectStores())
                {
                }

                template <int STEP>
                DatabaseWithObjectStoresBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<DatabaseWithObjectStoresBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::IndexedDB::DatabaseWithObjectStores> m_result;
            };

            static DatabaseWithObjectStoresBuilder<0> create()
            {
                return DatabaseWithObjectStoresBuilder<0>();
            }

        private:
            DatabaseWithObjectStores()
            {
                m_version = 0;
            }

            String m_name;
            int m_version;
            std::unique_ptr<protocol::Array<protocol::IndexedDB::ObjectStore>> m_objectStores;
        };

        // Object store.
        class CORE_EXPORT ObjectStore : public Serializable {
            PROTOCOL_DISALLOW_COPY(ObjectStore);

        public:
            static std::unique_ptr<ObjectStore> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~ObjectStore() override { }

            String getName() { return m_name; }
            void setName(const String& value) { m_name = value; }

            protocol::IndexedDB::KeyPath* getKeyPath() { return m_keyPath.get(); }
            void setKeyPath(std::unique_ptr<protocol::IndexedDB::KeyPath> value) { m_keyPath = std::move(value); }

            bool getAutoIncrement() { return m_autoIncrement; }
            void setAutoIncrement(bool value) { m_autoIncrement = value; }

            protocol::Array<protocol::IndexedDB::ObjectStoreIndex>* getIndexes() { return m_indexes.get(); }
            void setIndexes(std::unique_ptr<protocol::Array<protocol::IndexedDB::ObjectStoreIndex>> value) { m_indexes = std::move(value); }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<ObjectStore> clone() const;

            template <int STATE>
            class ObjectStoreBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    NameSet = 1 << 1,
                    KeyPathSet = 1 << 2,
                    AutoIncrementSet = 1 << 3,
                    IndexesSet = 1 << 4,
                    AllFieldsSet = (NameSet | KeyPathSet | AutoIncrementSet | IndexesSet | 0)
                };

                ObjectStoreBuilder<STATE | NameSet>& setName(const String& value)
                {
                    static_assert(!(STATE & NameSet), "property name should not be set yet");
                    m_result->setName(value);
                    return castState<NameSet>();
                }

                ObjectStoreBuilder<STATE | KeyPathSet>& setKeyPath(std::unique_ptr<protocol::IndexedDB::KeyPath> value)
                {
                    static_assert(!(STATE & KeyPathSet), "property keyPath should not be set yet");
                    m_result->setKeyPath(std::move(value));
                    return castState<KeyPathSet>();
                }

                ObjectStoreBuilder<STATE | AutoIncrementSet>& setAutoIncrement(bool value)
                {
                    static_assert(!(STATE & AutoIncrementSet), "property autoIncrement should not be set yet");
                    m_result->setAutoIncrement(value);
                    return castState<AutoIncrementSet>();
                }

                ObjectStoreBuilder<STATE | IndexesSet>& setIndexes(std::unique_ptr<protocol::Array<protocol::IndexedDB::ObjectStoreIndex>> value)
                {
                    static_assert(!(STATE & IndexesSet), "property indexes should not be set yet");
                    m_result->setIndexes(std::move(value));
                    return castState<IndexesSet>();
                }

                std::unique_ptr<ObjectStore> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class ObjectStore;
                ObjectStoreBuilder()
                    : m_result(new ObjectStore())
                {
                }

                template <int STEP>
                ObjectStoreBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<ObjectStoreBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::IndexedDB::ObjectStore> m_result;
            };

            static ObjectStoreBuilder<0> create()
            {
                return ObjectStoreBuilder<0>();
            }

        private:
            ObjectStore()
            {
                m_autoIncrement = false;
            }

            String m_name;
            std::unique_ptr<protocol::IndexedDB::KeyPath> m_keyPath;
            bool m_autoIncrement;
            std::unique_ptr<protocol::Array<protocol::IndexedDB::ObjectStoreIndex>> m_indexes;
        };

        // Object store index.
        class CORE_EXPORT ObjectStoreIndex : public Serializable {
            PROTOCOL_DISALLOW_COPY(ObjectStoreIndex);

        public:
            static std::unique_ptr<ObjectStoreIndex> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~ObjectStoreIndex() override { }

            String getName() { return m_name; }
            void setName(const String& value) { m_name = value; }

            protocol::IndexedDB::KeyPath* getKeyPath() { return m_keyPath.get(); }
            void setKeyPath(std::unique_ptr<protocol::IndexedDB::KeyPath> value) { m_keyPath = std::move(value); }

            bool getUnique() { return m_unique; }
            void setUnique(bool value) { m_unique = value; }

            bool getMultiEntry() { return m_multiEntry; }
            void setMultiEntry(bool value) { m_multiEntry = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<ObjectStoreIndex> clone() const;

            template <int STATE>
            class ObjectStoreIndexBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    NameSet = 1 << 1,
                    KeyPathSet = 1 << 2,
                    UniqueSet = 1 << 3,
                    MultiEntrySet = 1 << 4,
                    AllFieldsSet = (NameSet | KeyPathSet | UniqueSet | MultiEntrySet | 0)
                };

                ObjectStoreIndexBuilder<STATE | NameSet>& setName(const String& value)
                {
                    static_assert(!(STATE & NameSet), "property name should not be set yet");
                    m_result->setName(value);
                    return castState<NameSet>();
                }

                ObjectStoreIndexBuilder<STATE | KeyPathSet>& setKeyPath(std::unique_ptr<protocol::IndexedDB::KeyPath> value)
                {
                    static_assert(!(STATE & KeyPathSet), "property keyPath should not be set yet");
                    m_result->setKeyPath(std::move(value));
                    return castState<KeyPathSet>();
                }

                ObjectStoreIndexBuilder<STATE | UniqueSet>& setUnique(bool value)
                {
                    static_assert(!(STATE & UniqueSet), "property unique should not be set yet");
                    m_result->setUnique(value);
                    return castState<UniqueSet>();
                }

                ObjectStoreIndexBuilder<STATE | MultiEntrySet>& setMultiEntry(bool value)
                {
                    static_assert(!(STATE & MultiEntrySet), "property multiEntry should not be set yet");
                    m_result->setMultiEntry(value);
                    return castState<MultiEntrySet>();
                }

                std::unique_ptr<ObjectStoreIndex> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class ObjectStoreIndex;
                ObjectStoreIndexBuilder()
                    : m_result(new ObjectStoreIndex())
                {
                }

                template <int STEP>
                ObjectStoreIndexBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<ObjectStoreIndexBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::IndexedDB::ObjectStoreIndex> m_result;
            };

            static ObjectStoreIndexBuilder<0> create()
            {
                return ObjectStoreIndexBuilder<0>();
            }

        private:
            ObjectStoreIndex()
            {
                m_unique = false;
                m_multiEntry = false;
            }

            String m_name;
            std::unique_ptr<protocol::IndexedDB::KeyPath> m_keyPath;
            bool m_unique;
            bool m_multiEntry;
        };

        // Key.
        class CORE_EXPORT Key : public Serializable {
            PROTOCOL_DISALLOW_COPY(Key);

        public:
            static std::unique_ptr<Key> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~Key() override { }

            struct CORE_EXPORT TypeEnum {
                static const char* Number;
                static const char* String;
                static const char* Date;
                static const char* Array;
            }; // TypeEnum

            String getType() { return m_type; }
            void setType(const String& value) { m_type = value; }

            bool hasNumber() { return m_number.isJust(); }
            double getNumber(double defaultValue) { return m_number.isJust() ? m_number.fromJust() : defaultValue; }
            void setNumber(double value) { m_number = value; }

            bool hasString() { return m_string.isJust(); }
            String getString(const String& defaultValue) { return m_string.isJust() ? m_string.fromJust() : defaultValue; }
            void setString(const String& value) { m_string = value; }

            bool hasDate() { return m_date.isJust(); }
            double getDate(double defaultValue) { return m_date.isJust() ? m_date.fromJust() : defaultValue; }
            void setDate(double value) { m_date = value; }

            bool hasArray() { return m_array.isJust(); }
            protocol::Array<protocol::IndexedDB::Key>* getArray(protocol::Array<protocol::IndexedDB::Key>* defaultValue) { return m_array.isJust() ? m_array.fromJust() : defaultValue; }
            void setArray(std::unique_ptr<protocol::Array<protocol::IndexedDB::Key>> value) { m_array = std::move(value); }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<Key> clone() const;

            template <int STATE>
            class KeyBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    TypeSet = 1 << 1,
                    AllFieldsSet = (TypeSet | 0)
                };

                KeyBuilder<STATE | TypeSet>& setType(const String& value)
                {
                    static_assert(!(STATE & TypeSet), "property type should not be set yet");
                    m_result->setType(value);
                    return castState<TypeSet>();
                }

                KeyBuilder<STATE>& setNumber(double value)
                {
                    m_result->setNumber(value);
                    return *this;
                }

                KeyBuilder<STATE>& setString(const String& value)
                {
                    m_result->setString(value);
                    return *this;
                }

                KeyBuilder<STATE>& setDate(double value)
                {
                    m_result->setDate(value);
                    return *this;
                }

                KeyBuilder<STATE>& setArray(std::unique_ptr<protocol::Array<protocol::IndexedDB::Key>> value)
                {
                    m_result->setArray(std::move(value));
                    return *this;
                }

                std::unique_ptr<Key> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class Key;
                KeyBuilder()
                    : m_result(new Key())
                {
                }

                template <int STEP>
                KeyBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<KeyBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::IndexedDB::Key> m_result;
            };

            static KeyBuilder<0> create()
            {
                return KeyBuilder<0>();
            }

        private:
            Key()
            {
            }

            String m_type;
            Maybe<double> m_number;
            Maybe<String> m_string;
            Maybe<double> m_date;
            Maybe<protocol::Array<protocol::IndexedDB::Key>> m_array;
        };

        // Key range.
        class CORE_EXPORT KeyRange : public Serializable {
            PROTOCOL_DISALLOW_COPY(KeyRange);

        public:
            static std::unique_ptr<KeyRange> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~KeyRange() override { }

            bool hasLower() { return m_lower.isJust(); }
            protocol::IndexedDB::Key* getLower(protocol::IndexedDB::Key* defaultValue) { return m_lower.isJust() ? m_lower.fromJust() : defaultValue; }
            void setLower(std::unique_ptr<protocol::IndexedDB::Key> value) { m_lower = std::move(value); }

            bool hasUpper() { return m_upper.isJust(); }
            protocol::IndexedDB::Key* getUpper(protocol::IndexedDB::Key* defaultValue) { return m_upper.isJust() ? m_upper.fromJust() : defaultValue; }
            void setUpper(std::unique_ptr<protocol::IndexedDB::Key> value) { m_upper = std::move(value); }

            bool getLowerOpen() { return m_lowerOpen; }
            void setLowerOpen(bool value) { m_lowerOpen = value; }

            bool getUpperOpen() { return m_upperOpen; }
            void setUpperOpen(bool value) { m_upperOpen = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<KeyRange> clone() const;

            template <int STATE>
            class KeyRangeBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    LowerOpenSet = 1 << 1,
                    UpperOpenSet = 1 << 2,
                    AllFieldsSet = (LowerOpenSet | UpperOpenSet | 0)
                };

                KeyRangeBuilder<STATE>& setLower(std::unique_ptr<protocol::IndexedDB::Key> value)
                {
                    m_result->setLower(std::move(value));
                    return *this;
                }

                KeyRangeBuilder<STATE>& setUpper(std::unique_ptr<protocol::IndexedDB::Key> value)
                {
                    m_result->setUpper(std::move(value));
                    return *this;
                }

                KeyRangeBuilder<STATE | LowerOpenSet>& setLowerOpen(bool value)
                {
                    static_assert(!(STATE & LowerOpenSet), "property lowerOpen should not be set yet");
                    m_result->setLowerOpen(value);
                    return castState<LowerOpenSet>();
                }

                KeyRangeBuilder<STATE | UpperOpenSet>& setUpperOpen(bool value)
                {
                    static_assert(!(STATE & UpperOpenSet), "property upperOpen should not be set yet");
                    m_result->setUpperOpen(value);
                    return castState<UpperOpenSet>();
                }

                std::unique_ptr<KeyRange> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class KeyRange;
                KeyRangeBuilder()
                    : m_result(new KeyRange())
                {
                }

                template <int STEP>
                KeyRangeBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<KeyRangeBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::IndexedDB::KeyRange> m_result;
            };

            static KeyRangeBuilder<0> create()
            {
                return KeyRangeBuilder<0>();
            }

        private:
            KeyRange()
            {
                m_lowerOpen = false;
                m_upperOpen = false;
            }

            Maybe<protocol::IndexedDB::Key> m_lower;
            Maybe<protocol::IndexedDB::Key> m_upper;
            bool m_lowerOpen;
            bool m_upperOpen;
        };

        // Data entry.
        class CORE_EXPORT DataEntry : public Serializable {
            PROTOCOL_DISALLOW_COPY(DataEntry);

        public:
            static std::unique_ptr<DataEntry> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~DataEntry() override { }

            v8_inspector::protocol::Runtime::API::RemoteObject* getKey() { return m_key.get(); }
            void setKey(std::unique_ptr<v8_inspector::protocol::Runtime::API::RemoteObject> value) { m_key = std::move(value); }

            v8_inspector::protocol::Runtime::API::RemoteObject* getPrimaryKey() { return m_primaryKey.get(); }
            void setPrimaryKey(std::unique_ptr<v8_inspector::protocol::Runtime::API::RemoteObject> value) { m_primaryKey = std::move(value); }

            v8_inspector::protocol::Runtime::API::RemoteObject* getValue() { return m_value.get(); }
            void setValue(std::unique_ptr<v8_inspector::protocol::Runtime::API::RemoteObject> value) { m_value = std::move(value); }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<DataEntry> clone() const;

            template <int STATE>
            class DataEntryBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    KeySet = 1 << 1,
                    PrimaryKeySet = 1 << 2,
                    ValueSet = 1 << 3,
                    AllFieldsSet = (KeySet | PrimaryKeySet | ValueSet | 0)
                };

                DataEntryBuilder<STATE | KeySet>& setKey(std::unique_ptr<v8_inspector::protocol::Runtime::API::RemoteObject> value)
                {
                    static_assert(!(STATE & KeySet), "property key should not be set yet");
                    m_result->setKey(std::move(value));
                    return castState<KeySet>();
                }

                DataEntryBuilder<STATE | PrimaryKeySet>& setPrimaryKey(std::unique_ptr<v8_inspector::protocol::Runtime::API::RemoteObject> value)
                {
                    static_assert(!(STATE & PrimaryKeySet), "property primaryKey should not be set yet");
                    m_result->setPrimaryKey(std::move(value));
                    return castState<PrimaryKeySet>();
                }

                DataEntryBuilder<STATE | ValueSet>& setValue(std::unique_ptr<v8_inspector::protocol::Runtime::API::RemoteObject> value)
                {
                    static_assert(!(STATE & ValueSet), "property value should not be set yet");
                    m_result->setValue(std::move(value));
                    return castState<ValueSet>();
                }

                std::unique_ptr<DataEntry> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class DataEntry;
                DataEntryBuilder()
                    : m_result(new DataEntry())
                {
                }

                template <int STEP>
                DataEntryBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<DataEntryBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::IndexedDB::DataEntry> m_result;
            };

            static DataEntryBuilder<0> create()
            {
                return DataEntryBuilder<0>();
            }

        private:
            DataEntry()
            {
            }

            std::unique_ptr<v8_inspector::protocol::Runtime::API::RemoteObject> m_key;
            std::unique_ptr<v8_inspector::protocol::Runtime::API::RemoteObject> m_primaryKey;
            std::unique_ptr<v8_inspector::protocol::Runtime::API::RemoteObject> m_value;
        };

        // Key path.
        class CORE_EXPORT KeyPath : public Serializable {
            PROTOCOL_DISALLOW_COPY(KeyPath);

        public:
            static std::unique_ptr<KeyPath> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~KeyPath() override { }

            struct CORE_EXPORT TypeEnum {
                static const char* Null;
                static const char* String;
                static const char* Array;
            }; // TypeEnum

            String getType() { return m_type; }
            void setType(const String& value) { m_type = value; }

            bool hasString() { return m_string.isJust(); }
            String getString(const String& defaultValue) { return m_string.isJust() ? m_string.fromJust() : defaultValue; }
            void setString(const String& value) { m_string = value; }

            bool hasArray() { return m_array.isJust(); }
            protocol::Array<String>* getArray(protocol::Array<String>* defaultValue) { return m_array.isJust() ? m_array.fromJust() : defaultValue; }
            void setArray(std::unique_ptr<protocol::Array<String>> value) { m_array = std::move(value); }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<KeyPath> clone() const;

            template <int STATE>
            class KeyPathBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    TypeSet = 1 << 1,
                    AllFieldsSet = (TypeSet | 0)
                };

                KeyPathBuilder<STATE | TypeSet>& setType(const String& value)
                {
                    static_assert(!(STATE & TypeSet), "property type should not be set yet");
                    m_result->setType(value);
                    return castState<TypeSet>();
                }

                KeyPathBuilder<STATE>& setString(const String& value)
                {
                    m_result->setString(value);
                    return *this;
                }

                KeyPathBuilder<STATE>& setArray(std::unique_ptr<protocol::Array<String>> value)
                {
                    m_result->setArray(std::move(value));
                    return *this;
                }

                std::unique_ptr<KeyPath> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class KeyPath;
                KeyPathBuilder()
                    : m_result(new KeyPath())
                {
                }

                template <int STEP>
                KeyPathBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<KeyPathBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::IndexedDB::KeyPath> m_result;
            };

            static KeyPathBuilder<0> create()
            {
                return KeyPathBuilder<0>();
            }

        private:
            KeyPath()
            {
            }

            String m_type;
            Maybe<String> m_string;
            Maybe<protocol::Array<String>> m_array;
        };

        // ------------- Backend interface.

        class CORE_EXPORT Backend {
        public:
            virtual ~Backend() { }

            virtual DispatchResponse enable() = 0;
            virtual DispatchResponse disable() = 0;
            class CORE_EXPORT RequestDatabaseNamesCallback {
            public:
                virtual void sendSuccess(std::unique_ptr<protocol::Array<String>> databaseNames) = 0;
                virtual void sendFailure(const DispatchResponse&) = 0;
                virtual void fallThrough() = 0;
                virtual ~RequestDatabaseNamesCallback() { }
            };
            virtual void requestDatabaseNames(const String& in_securityOrigin, std::unique_ptr<RequestDatabaseNamesCallback> callback) = 0;
            class CORE_EXPORT RequestDatabaseCallback {
            public:
                virtual void sendSuccess(std::unique_ptr<protocol::IndexedDB::DatabaseWithObjectStores> databaseWithObjectStores) = 0;
                virtual void sendFailure(const DispatchResponse&) = 0;
                virtual void fallThrough() = 0;
                virtual ~RequestDatabaseCallback() { }
            };
            virtual void requestDatabase(const String& in_securityOrigin, const String& in_databaseName, std::unique_ptr<RequestDatabaseCallback> callback) = 0;
            class CORE_EXPORT RequestDataCallback {
            public:
                virtual void sendSuccess(std::unique_ptr<protocol::Array<protocol::IndexedDB::DataEntry>> objectStoreDataEntries, bool hasMore) = 0;
                virtual void sendFailure(const DispatchResponse&) = 0;
                virtual void fallThrough() = 0;
                virtual ~RequestDataCallback() { }
            };
            virtual void requestData(const String& in_securityOrigin, const String& in_databaseName, const String& in_objectStoreName, const String& in_indexName, int in_skipCount, int in_pageSize, Maybe<protocol::IndexedDB::KeyRange> in_keyRange, std::unique_ptr<RequestDataCallback> callback) = 0;
            class CORE_EXPORT ClearObjectStoreCallback {
            public:
                virtual void sendSuccess() = 0;
                virtual void sendFailure(const DispatchResponse&) = 0;
                virtual void fallThrough() = 0;
                virtual ~ClearObjectStoreCallback() { }
            };
            virtual void clearObjectStore(const String& in_securityOrigin, const String& in_databaseName, const String& in_objectStoreName, std::unique_ptr<ClearObjectStoreCallback> callback) = 0;
        };

        // ------------- Frontend interface.

        class CORE_EXPORT Frontend {
        public:
            explicit Frontend(FrontendChannel* frontendChannel)
                : m_frontendChannel(frontendChannel)
            {
            }

            void flush();
            void sendRawNotification(const String&);

        private:
            FrontendChannel* m_frontendChannel;
        };

        // ------------- Dispatcher.

        class CORE_EXPORT Dispatcher {
        public:
            static void wire(UberDispatcher*, Backend*);

        private:
            Dispatcher() { }
        };

        // ------------- Metainfo.

        class CORE_EXPORT Metainfo {
        public:
            using BackendClass = Backend;
            using FrontendClass = Frontend;
            using DispatcherClass = Dispatcher;
            static const char domainName[];
            static const char commandPrefix[];
            static const char version[];
        };

    } // namespace IndexedDB
} // namespace blink
} // namespace protocol

#endif // !defined(blink_protocol_IndexedDB_h)
