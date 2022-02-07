// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "core/inspector/protocol/CacheStorage.h"

#include "core/inspector/protocol/Protocol.h"

namespace blink {
namespace protocol {
    namespace CacheStorage {

        // ------------- Enum values from types.

        const char Metainfo::domainName[] = "CacheStorage";
        const char Metainfo::commandPrefix[] = "CacheStorage.";
        const char Metainfo::version[] = "1.2";

        std::unique_ptr<DataEntry> DataEntry::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<DataEntry> result(new DataEntry());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* requestValue = object->get("request");
            errors->setName("request");
            result->m_request = ValueConversions<String>::fromValue(requestValue, errors);
            protocol::Value* responseValue = object->get("response");
            errors->setName("response");
            result->m_response = ValueConversions<String>::fromValue(responseValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> DataEntry::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("request", ValueConversions<String>::toValue(m_request));
            result->setValue("response", ValueConversions<String>::toValue(m_response));
            return result;
        }

        std::unique_ptr<DataEntry> DataEntry::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<Cache> Cache::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<Cache> result(new Cache());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* cacheIdValue = object->get("cacheId");
            errors->setName("cacheId");
            result->m_cacheId = ValueConversions<String>::fromValue(cacheIdValue, errors);
            protocol::Value* securityOriginValue = object->get("securityOrigin");
            errors->setName("securityOrigin");
            result->m_securityOrigin = ValueConversions<String>::fromValue(securityOriginValue, errors);
            protocol::Value* cacheNameValue = object->get("cacheName");
            errors->setName("cacheName");
            result->m_cacheName = ValueConversions<String>::fromValue(cacheNameValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> Cache::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("cacheId", ValueConversions<String>::toValue(m_cacheId));
            result->setValue("securityOrigin", ValueConversions<String>::toValue(m_securityOrigin));
            result->setValue("cacheName", ValueConversions<String>::toValue(m_cacheName));
            return result;
        }

        std::unique_ptr<Cache> Cache::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        // ------------- Enum values from params.

        // ------------- Frontend notifications.

        void Frontend::flush()
        {
            m_frontendChannel->flushProtocolNotifications();
        }

        void Frontend::sendRawNotification(const String& notification)
        {
            m_frontendChannel->sendProtocolNotification(InternalRawNotification::create(notification));
        }

        // --------------------- Dispatcher.

        class DispatcherImpl : public protocol::DispatcherBase {
        public:
            DispatcherImpl(FrontendChannel* frontendChannel, Backend* backend, bool fallThroughForNotFound)
                : DispatcherBase(frontendChannel)
                , m_backend(backend)
                , m_fallThroughForNotFound(fallThroughForNotFound)
            {
                m_dispatchMap["CacheStorage.requestCacheNames"] = &DispatcherImpl::requestCacheNames;
                m_dispatchMap["CacheStorage.requestEntries"] = &DispatcherImpl::requestEntries;
                m_dispatchMap["CacheStorage.deleteCache"] = &DispatcherImpl::deleteCache;
                m_dispatchMap["CacheStorage.deleteEntry"] = &DispatcherImpl::deleteEntry;
            }
            ~DispatcherImpl() override { }
            DispatchResponse::Status dispatch(int callId, const String& method, std::unique_ptr<protocol::DictionaryValue> messageObject) override;
            HashMap<String, String>& redirects() { return m_redirects; }

        protected:
            using CallHandler = DispatchResponse::Status (DispatcherImpl::*)(int callId, std::unique_ptr<DictionaryValue> messageObject, ErrorSupport* errors);
            using DispatchMap = protocol::HashMap<String, CallHandler>;
            DispatchMap m_dispatchMap;
            HashMap<String, String> m_redirects;

            DispatchResponse::Status requestCacheNames(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status requestEntries(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status deleteCache(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status deleteEntry(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);

            Backend* m_backend;
            bool m_fallThroughForNotFound;
        };

        DispatchResponse::Status DispatcherImpl::dispatch(int callId, const String& method, std::unique_ptr<protocol::DictionaryValue> messageObject)
        {
            protocol::HashMap<String, CallHandler>::iterator it = m_dispatchMap.find(method);
            if (it == m_dispatchMap.end()) {
                if (m_fallThroughForNotFound)
                    return DispatchResponse::kFallThrough;
                reportProtocolError(callId, DispatchResponse::kMethodNotFound, "'" + method + "' wasn't found", nullptr);
                return DispatchResponse::kError;
            }

            protocol::ErrorSupport errors;
            return (this->*(it->second))(callId, std::move(messageObject), &errors);
        }

        class RequestCacheNamesCallbackImpl : public Backend::RequestCacheNamesCallback, public DispatcherBase::Callback {
        public:
            RequestCacheNamesCallbackImpl(std::unique_ptr<DispatcherBase::WeakPtr> backendImpl, int callId, int callbackId)
                : DispatcherBase::Callback(std::move(backendImpl), callId, callbackId)
            {
            }

            void sendSuccess(std::unique_ptr<protocol::Array<protocol::CacheStorage::Cache>> caches) override
            {
                std::unique_ptr<protocol::DictionaryValue> resultObject = DictionaryValue::create();
                resultObject->setValue("caches", ValueConversions<protocol::Array<protocol::CacheStorage::Cache>>::toValue(caches.get()));
                sendIfActive(std::move(resultObject), DispatchResponse::OK());
            }

            void fallThrough() override
            {
                fallThroughIfActive();
            }

            void sendFailure(const DispatchResponse& response) override
            {
                DCHECK(response.status() == DispatchResponse::kError);
                sendIfActive(nullptr, response);
            }
        };

        DispatchResponse::Status DispatcherImpl::requestCacheNames(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* securityOriginValue = object ? object->get("securityOrigin") : nullptr;
            errors->setName("securityOrigin");
            String in_securityOrigin = ValueConversions<String>::fromValue(securityOriginValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            std::unique_ptr<RequestCacheNamesCallbackImpl> callback(new RequestCacheNamesCallbackImpl(weakPtr(), callId, nextCallbackId()));
            m_backend->requestCacheNames(in_securityOrigin, std::move(callback));
            return (weak->get() && weak->get()->lastCallbackFallThrough()) ? DispatchResponse::kFallThrough : DispatchResponse::kAsync;
        }

        class RequestEntriesCallbackImpl : public Backend::RequestEntriesCallback, public DispatcherBase::Callback {
        public:
            RequestEntriesCallbackImpl(std::unique_ptr<DispatcherBase::WeakPtr> backendImpl, int callId, int callbackId)
                : DispatcherBase::Callback(std::move(backendImpl), callId, callbackId)
            {
            }

            void sendSuccess(std::unique_ptr<protocol::Array<protocol::CacheStorage::DataEntry>> cacheDataEntries, bool hasMore) override
            {
                std::unique_ptr<protocol::DictionaryValue> resultObject = DictionaryValue::create();
                resultObject->setValue("cacheDataEntries", ValueConversions<protocol::Array<protocol::CacheStorage::DataEntry>>::toValue(cacheDataEntries.get()));
                resultObject->setValue("hasMore", ValueConversions<bool>::toValue(hasMore));
                sendIfActive(std::move(resultObject), DispatchResponse::OK());
            }

            void fallThrough() override
            {
                fallThroughIfActive();
            }

            void sendFailure(const DispatchResponse& response) override
            {
                DCHECK(response.status() == DispatchResponse::kError);
                sendIfActive(nullptr, response);
            }
        };

        DispatchResponse::Status DispatcherImpl::requestEntries(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* cacheIdValue = object ? object->get("cacheId") : nullptr;
            errors->setName("cacheId");
            String in_cacheId = ValueConversions<String>::fromValue(cacheIdValue, errors);
            protocol::Value* skipCountValue = object ? object->get("skipCount") : nullptr;
            errors->setName("skipCount");
            int in_skipCount = ValueConversions<int>::fromValue(skipCountValue, errors);
            protocol::Value* pageSizeValue = object ? object->get("pageSize") : nullptr;
            errors->setName("pageSize");
            int in_pageSize = ValueConversions<int>::fromValue(pageSizeValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            std::unique_ptr<RequestEntriesCallbackImpl> callback(new RequestEntriesCallbackImpl(weakPtr(), callId, nextCallbackId()));
            m_backend->requestEntries(in_cacheId, in_skipCount, in_pageSize, std::move(callback));
            return (weak->get() && weak->get()->lastCallbackFallThrough()) ? DispatchResponse::kFallThrough : DispatchResponse::kAsync;
        }

        class DeleteCacheCallbackImpl : public Backend::DeleteCacheCallback, public DispatcherBase::Callback {
        public:
            DeleteCacheCallbackImpl(std::unique_ptr<DispatcherBase::WeakPtr> backendImpl, int callId, int callbackId)
                : DispatcherBase::Callback(std::move(backendImpl), callId, callbackId)
            {
            }

            void sendSuccess() override
            {
                std::unique_ptr<protocol::DictionaryValue> resultObject = DictionaryValue::create();
                sendIfActive(std::move(resultObject), DispatchResponse::OK());
            }

            void fallThrough() override
            {
                fallThroughIfActive();
            }

            void sendFailure(const DispatchResponse& response) override
            {
                DCHECK(response.status() == DispatchResponse::kError);
                sendIfActive(nullptr, response);
            }
        };

        DispatchResponse::Status DispatcherImpl::deleteCache(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* cacheIdValue = object ? object->get("cacheId") : nullptr;
            errors->setName("cacheId");
            String in_cacheId = ValueConversions<String>::fromValue(cacheIdValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            std::unique_ptr<DeleteCacheCallbackImpl> callback(new DeleteCacheCallbackImpl(weakPtr(), callId, nextCallbackId()));
            m_backend->deleteCache(in_cacheId, std::move(callback));
            return (weak->get() && weak->get()->lastCallbackFallThrough()) ? DispatchResponse::kFallThrough : DispatchResponse::kAsync;
        }

        class DeleteEntryCallbackImpl : public Backend::DeleteEntryCallback, public DispatcherBase::Callback {
        public:
            DeleteEntryCallbackImpl(std::unique_ptr<DispatcherBase::WeakPtr> backendImpl, int callId, int callbackId)
                : DispatcherBase::Callback(std::move(backendImpl), callId, callbackId)
            {
            }

            void sendSuccess() override
            {
                std::unique_ptr<protocol::DictionaryValue> resultObject = DictionaryValue::create();
                sendIfActive(std::move(resultObject), DispatchResponse::OK());
            }

            void fallThrough() override
            {
                fallThroughIfActive();
            }

            void sendFailure(const DispatchResponse& response) override
            {
                DCHECK(response.status() == DispatchResponse::kError);
                sendIfActive(nullptr, response);
            }
        };

        DispatchResponse::Status DispatcherImpl::deleteEntry(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* cacheIdValue = object ? object->get("cacheId") : nullptr;
            errors->setName("cacheId");
            String in_cacheId = ValueConversions<String>::fromValue(cacheIdValue, errors);
            protocol::Value* requestValue = object ? object->get("request") : nullptr;
            errors->setName("request");
            String in_request = ValueConversions<String>::fromValue(requestValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            std::unique_ptr<DeleteEntryCallbackImpl> callback(new DeleteEntryCallbackImpl(weakPtr(), callId, nextCallbackId()));
            m_backend->deleteEntry(in_cacheId, in_request, std::move(callback));
            return (weak->get() && weak->get()->lastCallbackFallThrough()) ? DispatchResponse::kFallThrough : DispatchResponse::kAsync;
        }

        // static
        void Dispatcher::wire(UberDispatcher* uber, Backend* backend)
        {
            std::unique_ptr<DispatcherImpl> dispatcher(new DispatcherImpl(uber->channel(), backend, uber->fallThroughForNotFound()));
            uber->setupRedirects(dispatcher->redirects());
            uber->registerBackend("CacheStorage", std::move(dispatcher));
        }

    } // CacheStorage
} // namespace blink
} // namespace protocol
