// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef blink_protocol_CacheStorage_h
#define blink_protocol_CacheStorage_h

#include "core/CoreExport.h"
#include "core/inspector/protocol/Protocol.h"
// For each imported domain we generate a ValueConversions struct instead of a full domain definition
// and include Domain::API version from there.

namespace blink {
namespace protocol {
    namespace CacheStorage {

        // ------------- Forward and enum declarations.
        // Unique identifier of the Cache object.
        using CacheId = String;
        // Data entry.
        class DataEntry;
        // Cache identifier.
        class Cache;

        // ------------- Type and builder declarations.

        // Data entry.
        class CORE_EXPORT DataEntry : public Serializable {
            PROTOCOL_DISALLOW_COPY(DataEntry);

        public:
            static std::unique_ptr<DataEntry> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~DataEntry() override { }

            String getRequest() { return m_request; }
            void setRequest(const String& value) { m_request = value; }

            String getResponse() { return m_response; }
            void setResponse(const String& value) { m_response = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<DataEntry> clone() const;

            template <int STATE>
            class DataEntryBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    RequestSet = 1 << 1,
                    ResponseSet = 1 << 2,
                    AllFieldsSet = (RequestSet | ResponseSet | 0)
                };

                DataEntryBuilder<STATE | RequestSet>& setRequest(const String& value)
                {
                    static_assert(!(STATE & RequestSet), "property request should not be set yet");
                    m_result->setRequest(value);
                    return castState<RequestSet>();
                }

                DataEntryBuilder<STATE | ResponseSet>& setResponse(const String& value)
                {
                    static_assert(!(STATE & ResponseSet), "property response should not be set yet");
                    m_result->setResponse(value);
                    return castState<ResponseSet>();
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

                std::unique_ptr<protocol::CacheStorage::DataEntry> m_result;
            };

            static DataEntryBuilder<0> create()
            {
                return DataEntryBuilder<0>();
            }

        private:
            DataEntry()
            {
            }

            String m_request;
            String m_response;
        };

        // Cache identifier.
        class CORE_EXPORT Cache : public Serializable {
            PROTOCOL_DISALLOW_COPY(Cache);

        public:
            static std::unique_ptr<Cache> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~Cache() override { }

            String getCacheId() { return m_cacheId; }
            void setCacheId(const String& value) { m_cacheId = value; }

            String getSecurityOrigin() { return m_securityOrigin; }
            void setSecurityOrigin(const String& value) { m_securityOrigin = value; }

            String getCacheName() { return m_cacheName; }
            void setCacheName(const String& value) { m_cacheName = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<Cache> clone() const;

            template <int STATE>
            class CacheBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    CacheIdSet = 1 << 1,
                    SecurityOriginSet = 1 << 2,
                    CacheNameSet = 1 << 3,
                    AllFieldsSet = (CacheIdSet | SecurityOriginSet | CacheNameSet | 0)
                };

                CacheBuilder<STATE | CacheIdSet>& setCacheId(const String& value)
                {
                    static_assert(!(STATE & CacheIdSet), "property cacheId should not be set yet");
                    m_result->setCacheId(value);
                    return castState<CacheIdSet>();
                }

                CacheBuilder<STATE | SecurityOriginSet>& setSecurityOrigin(const String& value)
                {
                    static_assert(!(STATE & SecurityOriginSet), "property securityOrigin should not be set yet");
                    m_result->setSecurityOrigin(value);
                    return castState<SecurityOriginSet>();
                }

                CacheBuilder<STATE | CacheNameSet>& setCacheName(const String& value)
                {
                    static_assert(!(STATE & CacheNameSet), "property cacheName should not be set yet");
                    m_result->setCacheName(value);
                    return castState<CacheNameSet>();
                }

                std::unique_ptr<Cache> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class Cache;
                CacheBuilder()
                    : m_result(new Cache())
                {
                }

                template <int STEP>
                CacheBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<CacheBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::CacheStorage::Cache> m_result;
            };

            static CacheBuilder<0> create()
            {
                return CacheBuilder<0>();
            }

        private:
            Cache()
            {
            }

            String m_cacheId;
            String m_securityOrigin;
            String m_cacheName;
        };

        // ------------- Backend interface.

        class CORE_EXPORT Backend {
        public:
            virtual ~Backend() { }

            class CORE_EXPORT RequestCacheNamesCallback {
            public:
                virtual void sendSuccess(std::unique_ptr<protocol::Array<protocol::CacheStorage::Cache>> caches) = 0;
                virtual void sendFailure(const DispatchResponse&) = 0;
                virtual void fallThrough() = 0;
                virtual ~RequestCacheNamesCallback() { }
            };
            virtual void requestCacheNames(const String& in_securityOrigin, std::unique_ptr<RequestCacheNamesCallback> callback) = 0;
            class CORE_EXPORT RequestEntriesCallback {
            public:
                virtual void sendSuccess(std::unique_ptr<protocol::Array<protocol::CacheStorage::DataEntry>> cacheDataEntries, bool hasMore) = 0;
                virtual void sendFailure(const DispatchResponse&) = 0;
                virtual void fallThrough() = 0;
                virtual ~RequestEntriesCallback() { }
            };
            virtual void requestEntries(const String& in_cacheId, int in_skipCount, int in_pageSize, std::unique_ptr<RequestEntriesCallback> callback) = 0;
            class CORE_EXPORT DeleteCacheCallback {
            public:
                virtual void sendSuccess() = 0;
                virtual void sendFailure(const DispatchResponse&) = 0;
                virtual void fallThrough() = 0;
                virtual ~DeleteCacheCallback() { }
            };
            virtual void deleteCache(const String& in_cacheId, std::unique_ptr<DeleteCacheCallback> callback) = 0;
            class CORE_EXPORT DeleteEntryCallback {
            public:
                virtual void sendSuccess() = 0;
                virtual void sendFailure(const DispatchResponse&) = 0;
                virtual void fallThrough() = 0;
                virtual ~DeleteEntryCallback() { }
            };
            virtual void deleteEntry(const String& in_cacheId, const String& in_request, std::unique_ptr<DeleteEntryCallback> callback) = 0;

            virtual DispatchResponse disable()
            {
                return DispatchResponse::OK();
            }
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

    } // namespace CacheStorage
} // namespace blink
} // namespace protocol

#endif // !defined(blink_protocol_CacheStorage_h)
