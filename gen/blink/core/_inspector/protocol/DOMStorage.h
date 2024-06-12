// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef blink_protocol_DOMStorage_h
#define blink_protocol_DOMStorage_h

#include "core/CoreExport.h"
#include "core/inspector/protocol/Protocol.h"
// For each imported domain we generate a ValueConversions struct instead of a full domain definition
// and include Domain::API version from there.

namespace blink {
namespace protocol {
    namespace DOMStorage {

        // ------------- Forward and enum declarations.
        // DOM Storage identifier.
        class StorageId;
        // Wrapper for notification params
        class DomStorageItemsClearedNotification;
        // Wrapper for notification params
        class DomStorageItemRemovedNotification;
        // Wrapper for notification params
        class DomStorageItemAddedNotification;
        // Wrapper for notification params
        class DomStorageItemUpdatedNotification;

        // ------------- Type and builder declarations.

        // DOM Storage identifier.
        class CORE_EXPORT StorageId : public Serializable {
            PROTOCOL_DISALLOW_COPY(StorageId);

        public:
            static std::unique_ptr<StorageId> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~StorageId() override { }

            String getSecurityOrigin() { return m_securityOrigin; }
            void setSecurityOrigin(const String& value) { m_securityOrigin = value; }

            bool getIsLocalStorage() { return m_isLocalStorage; }
            void setIsLocalStorage(bool value) { m_isLocalStorage = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<StorageId> clone() const;

            template <int STATE>
            class StorageIdBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    SecurityOriginSet = 1 << 1,
                    IsLocalStorageSet = 1 << 2,
                    AllFieldsSet = (SecurityOriginSet | IsLocalStorageSet | 0)
                };

                StorageIdBuilder<STATE | SecurityOriginSet>& setSecurityOrigin(const String& value)
                {
                    static_assert(!(STATE & SecurityOriginSet), "property securityOrigin should not be set yet");
                    m_result->setSecurityOrigin(value);
                    return castState<SecurityOriginSet>();
                }

                StorageIdBuilder<STATE | IsLocalStorageSet>& setIsLocalStorage(bool value)
                {
                    static_assert(!(STATE & IsLocalStorageSet), "property isLocalStorage should not be set yet");
                    m_result->setIsLocalStorage(value);
                    return castState<IsLocalStorageSet>();
                }

                std::unique_ptr<StorageId> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class StorageId;
                StorageIdBuilder()
                    : m_result(new StorageId())
                {
                }

                template <int STEP>
                StorageIdBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<StorageIdBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::DOMStorage::StorageId> m_result;
            };

            static StorageIdBuilder<0> create()
            {
                return StorageIdBuilder<0>();
            }

        private:
            StorageId()
            {
                m_isLocalStorage = false;
            }

            String m_securityOrigin;
            bool m_isLocalStorage;
        };

        // Wrapper for notification params
        class CORE_EXPORT DomStorageItemsClearedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(DomStorageItemsClearedNotification);

        public:
            static std::unique_ptr<DomStorageItemsClearedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~DomStorageItemsClearedNotification() override { }

            protocol::DOMStorage::StorageId* getStorageId() { return m_storageId.get(); }
            void setStorageId(std::unique_ptr<protocol::DOMStorage::StorageId> value) { m_storageId = std::move(value); }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<DomStorageItemsClearedNotification> clone() const;

            template <int STATE>
            class DomStorageItemsClearedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    StorageIdSet = 1 << 1,
                    AllFieldsSet = (StorageIdSet | 0)
                };

                DomStorageItemsClearedNotificationBuilder<STATE | StorageIdSet>& setStorageId(std::unique_ptr<protocol::DOMStorage::StorageId> value)
                {
                    static_assert(!(STATE & StorageIdSet), "property storageId should not be set yet");
                    m_result->setStorageId(std::move(value));
                    return castState<StorageIdSet>();
                }

                std::unique_ptr<DomStorageItemsClearedNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class DomStorageItemsClearedNotification;
                DomStorageItemsClearedNotificationBuilder()
                    : m_result(new DomStorageItemsClearedNotification())
                {
                }

                template <int STEP>
                DomStorageItemsClearedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<DomStorageItemsClearedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::DOMStorage::DomStorageItemsClearedNotification> m_result;
            };

            static DomStorageItemsClearedNotificationBuilder<0> create()
            {
                return DomStorageItemsClearedNotificationBuilder<0>();
            }

        private:
            DomStorageItemsClearedNotification()
            {
            }

            std::unique_ptr<protocol::DOMStorage::StorageId> m_storageId;
        };

        // Wrapper for notification params
        class CORE_EXPORT DomStorageItemRemovedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(DomStorageItemRemovedNotification);

        public:
            static std::unique_ptr<DomStorageItemRemovedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~DomStorageItemRemovedNotification() override { }

            protocol::DOMStorage::StorageId* getStorageId() { return m_storageId.get(); }
            void setStorageId(std::unique_ptr<protocol::DOMStorage::StorageId> value) { m_storageId = std::move(value); }

            String getKey() { return m_key; }
            void setKey(const String& value) { m_key = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<DomStorageItemRemovedNotification> clone() const;

            template <int STATE>
            class DomStorageItemRemovedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    StorageIdSet = 1 << 1,
                    KeySet = 1 << 2,
                    AllFieldsSet = (StorageIdSet | KeySet | 0)
                };

                DomStorageItemRemovedNotificationBuilder<STATE | StorageIdSet>& setStorageId(std::unique_ptr<protocol::DOMStorage::StorageId> value)
                {
                    static_assert(!(STATE & StorageIdSet), "property storageId should not be set yet");
                    m_result->setStorageId(std::move(value));
                    return castState<StorageIdSet>();
                }

                DomStorageItemRemovedNotificationBuilder<STATE | KeySet>& setKey(const String& value)
                {
                    static_assert(!(STATE & KeySet), "property key should not be set yet");
                    m_result->setKey(value);
                    return castState<KeySet>();
                }

                std::unique_ptr<DomStorageItemRemovedNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class DomStorageItemRemovedNotification;
                DomStorageItemRemovedNotificationBuilder()
                    : m_result(new DomStorageItemRemovedNotification())
                {
                }

                template <int STEP>
                DomStorageItemRemovedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<DomStorageItemRemovedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::DOMStorage::DomStorageItemRemovedNotification> m_result;
            };

            static DomStorageItemRemovedNotificationBuilder<0> create()
            {
                return DomStorageItemRemovedNotificationBuilder<0>();
            }

        private:
            DomStorageItemRemovedNotification()
            {
            }

            std::unique_ptr<protocol::DOMStorage::StorageId> m_storageId;
            String m_key;
        };

        // Wrapper for notification params
        class CORE_EXPORT DomStorageItemAddedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(DomStorageItemAddedNotification);

        public:
            static std::unique_ptr<DomStorageItemAddedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~DomStorageItemAddedNotification() override { }

            protocol::DOMStorage::StorageId* getStorageId() { return m_storageId.get(); }
            void setStorageId(std::unique_ptr<protocol::DOMStorage::StorageId> value) { m_storageId = std::move(value); }

            String getKey() { return m_key; }
            void setKey(const String& value) { m_key = value; }

            String getNewValue() { return m_newValue; }
            void setNewValue(const String& value) { m_newValue = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<DomStorageItemAddedNotification> clone() const;

            template <int STATE>
            class DomStorageItemAddedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    StorageIdSet = 1 << 1,
                    KeySet = 1 << 2,
                    NewValueSet = 1 << 3,
                    AllFieldsSet = (StorageIdSet | KeySet | NewValueSet | 0)
                };

                DomStorageItemAddedNotificationBuilder<STATE | StorageIdSet>& setStorageId(std::unique_ptr<protocol::DOMStorage::StorageId> value)
                {
                    static_assert(!(STATE & StorageIdSet), "property storageId should not be set yet");
                    m_result->setStorageId(std::move(value));
                    return castState<StorageIdSet>();
                }

                DomStorageItemAddedNotificationBuilder<STATE | KeySet>& setKey(const String& value)
                {
                    static_assert(!(STATE & KeySet), "property key should not be set yet");
                    m_result->setKey(value);
                    return castState<KeySet>();
                }

                DomStorageItemAddedNotificationBuilder<STATE | NewValueSet>& setNewValue(const String& value)
                {
                    static_assert(!(STATE & NewValueSet), "property newValue should not be set yet");
                    m_result->setNewValue(value);
                    return castState<NewValueSet>();
                }

                std::unique_ptr<DomStorageItemAddedNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class DomStorageItemAddedNotification;
                DomStorageItemAddedNotificationBuilder()
                    : m_result(new DomStorageItemAddedNotification())
                {
                }

                template <int STEP>
                DomStorageItemAddedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<DomStorageItemAddedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::DOMStorage::DomStorageItemAddedNotification> m_result;
            };

            static DomStorageItemAddedNotificationBuilder<0> create()
            {
                return DomStorageItemAddedNotificationBuilder<0>();
            }

        private:
            DomStorageItemAddedNotification()
            {
            }

            std::unique_ptr<protocol::DOMStorage::StorageId> m_storageId;
            String m_key;
            String m_newValue;
        };

        // Wrapper for notification params
        class CORE_EXPORT DomStorageItemUpdatedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(DomStorageItemUpdatedNotification);

        public:
            static std::unique_ptr<DomStorageItemUpdatedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~DomStorageItemUpdatedNotification() override { }

            protocol::DOMStorage::StorageId* getStorageId() { return m_storageId.get(); }
            void setStorageId(std::unique_ptr<protocol::DOMStorage::StorageId> value) { m_storageId = std::move(value); }

            String getKey() { return m_key; }
            void setKey(const String& value) { m_key = value; }

            String getOldValue() { return m_oldValue; }
            void setOldValue(const String& value) { m_oldValue = value; }

            String getNewValue() { return m_newValue; }
            void setNewValue(const String& value) { m_newValue = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<DomStorageItemUpdatedNotification> clone() const;

            template <int STATE>
            class DomStorageItemUpdatedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    StorageIdSet = 1 << 1,
                    KeySet = 1 << 2,
                    OldValueSet = 1 << 3,
                    NewValueSet = 1 << 4,
                    AllFieldsSet = (StorageIdSet | KeySet | OldValueSet | NewValueSet | 0)
                };

                DomStorageItemUpdatedNotificationBuilder<STATE | StorageIdSet>& setStorageId(std::unique_ptr<protocol::DOMStorage::StorageId> value)
                {
                    static_assert(!(STATE & StorageIdSet), "property storageId should not be set yet");
                    m_result->setStorageId(std::move(value));
                    return castState<StorageIdSet>();
                }

                DomStorageItemUpdatedNotificationBuilder<STATE | KeySet>& setKey(const String& value)
                {
                    static_assert(!(STATE & KeySet), "property key should not be set yet");
                    m_result->setKey(value);
                    return castState<KeySet>();
                }

                DomStorageItemUpdatedNotificationBuilder<STATE | OldValueSet>& setOldValue(const String& value)
                {
                    static_assert(!(STATE & OldValueSet), "property oldValue should not be set yet");
                    m_result->setOldValue(value);
                    return castState<OldValueSet>();
                }

                DomStorageItemUpdatedNotificationBuilder<STATE | NewValueSet>& setNewValue(const String& value)
                {
                    static_assert(!(STATE & NewValueSet), "property newValue should not be set yet");
                    m_result->setNewValue(value);
                    return castState<NewValueSet>();
                }

                std::unique_ptr<DomStorageItemUpdatedNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class DomStorageItemUpdatedNotification;
                DomStorageItemUpdatedNotificationBuilder()
                    : m_result(new DomStorageItemUpdatedNotification())
                {
                }

                template <int STEP>
                DomStorageItemUpdatedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<DomStorageItemUpdatedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::DOMStorage::DomStorageItemUpdatedNotification> m_result;
            };

            static DomStorageItemUpdatedNotificationBuilder<0> create()
            {
                return DomStorageItemUpdatedNotificationBuilder<0>();
            }

        private:
            DomStorageItemUpdatedNotification()
            {
            }

            std::unique_ptr<protocol::DOMStorage::StorageId> m_storageId;
            String m_key;
            String m_oldValue;
            String m_newValue;
        };

        // ------------- Backend interface.

        class CORE_EXPORT Backend {
        public:
            virtual ~Backend() { }

            virtual DispatchResponse enable() = 0;
            virtual DispatchResponse disable() = 0;
            virtual DispatchResponse getDOMStorageItems(std::unique_ptr<protocol::DOMStorage::StorageId> in_storageId, std::unique_ptr<protocol::Array<protocol::Array<String>>>* out_entries) = 0;
            virtual DispatchResponse setDOMStorageItem(std::unique_ptr<protocol::DOMStorage::StorageId> in_storageId, const String& in_key, const String& in_value) = 0;
            virtual DispatchResponse removeDOMStorageItem(std::unique_ptr<protocol::DOMStorage::StorageId> in_storageId, const String& in_key) = 0;
        };

        // ------------- Frontend interface.

        class CORE_EXPORT Frontend {
        public:
            explicit Frontend(FrontendChannel* frontendChannel)
                : m_frontendChannel(frontendChannel)
            {
            }
            void domStorageItemsCleared(std::unique_ptr<protocol::DOMStorage::StorageId> storageId);
            void domStorageItemRemoved(std::unique_ptr<protocol::DOMStorage::StorageId> storageId, const String& key);
            void domStorageItemAdded(std::unique_ptr<protocol::DOMStorage::StorageId> storageId, const String& key, const String& newValue);
            void domStorageItemUpdated(std::unique_ptr<protocol::DOMStorage::StorageId> storageId, const String& key, const String& oldValue, const String& newValue);

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

    } // namespace DOMStorage
} // namespace blink
} // namespace protocol

#endif // !defined(blink_protocol_DOMStorage_h)
