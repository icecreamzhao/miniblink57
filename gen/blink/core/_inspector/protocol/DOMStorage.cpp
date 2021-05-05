// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "core/inspector/protocol/DOMStorage.h"

#include "core/inspector/protocol/Protocol.h"

namespace blink {
namespace protocol {
    namespace DOMStorage {

        // ------------- Enum values from types.

        const char Metainfo::domainName[] = "DOMStorage";
        const char Metainfo::commandPrefix[] = "DOMStorage.";
        const char Metainfo::version[] = "1.2";

        std::unique_ptr<StorageId> StorageId::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<StorageId> result(new StorageId());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* securityOriginValue = object->get("securityOrigin");
            errors->setName("securityOrigin");
            result->m_securityOrigin = ValueConversions<String>::fromValue(securityOriginValue, errors);
            protocol::Value* isLocalStorageValue = object->get("isLocalStorage");
            errors->setName("isLocalStorage");
            result->m_isLocalStorage = ValueConversions<bool>::fromValue(isLocalStorageValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> StorageId::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("securityOrigin", ValueConversions<String>::toValue(m_securityOrigin));
            result->setValue("isLocalStorage", ValueConversions<bool>::toValue(m_isLocalStorage));
            return result;
        }

        std::unique_ptr<StorageId> StorageId::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<DomStorageItemsClearedNotification> DomStorageItemsClearedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<DomStorageItemsClearedNotification> result(new DomStorageItemsClearedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* storageIdValue = object->get("storageId");
            errors->setName("storageId");
            result->m_storageId = ValueConversions<protocol::DOMStorage::StorageId>::fromValue(storageIdValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> DomStorageItemsClearedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("storageId", ValueConversions<protocol::DOMStorage::StorageId>::toValue(m_storageId.get()));
            return result;
        }

        std::unique_ptr<DomStorageItemsClearedNotification> DomStorageItemsClearedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<DomStorageItemRemovedNotification> DomStorageItemRemovedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<DomStorageItemRemovedNotification> result(new DomStorageItemRemovedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* storageIdValue = object->get("storageId");
            errors->setName("storageId");
            result->m_storageId = ValueConversions<protocol::DOMStorage::StorageId>::fromValue(storageIdValue, errors);
            protocol::Value* keyValue = object->get("key");
            errors->setName("key");
            result->m_key = ValueConversions<String>::fromValue(keyValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> DomStorageItemRemovedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("storageId", ValueConversions<protocol::DOMStorage::StorageId>::toValue(m_storageId.get()));
            result->setValue("key", ValueConversions<String>::toValue(m_key));
            return result;
        }

        std::unique_ptr<DomStorageItemRemovedNotification> DomStorageItemRemovedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<DomStorageItemAddedNotification> DomStorageItemAddedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<DomStorageItemAddedNotification> result(new DomStorageItemAddedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* storageIdValue = object->get("storageId");
            errors->setName("storageId");
            result->m_storageId = ValueConversions<protocol::DOMStorage::StorageId>::fromValue(storageIdValue, errors);
            protocol::Value* keyValue = object->get("key");
            errors->setName("key");
            result->m_key = ValueConversions<String>::fromValue(keyValue, errors);
            protocol::Value* newValueValue = object->get("newValue");
            errors->setName("newValue");
            result->m_newValue = ValueConversions<String>::fromValue(newValueValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> DomStorageItemAddedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("storageId", ValueConversions<protocol::DOMStorage::StorageId>::toValue(m_storageId.get()));
            result->setValue("key", ValueConversions<String>::toValue(m_key));
            result->setValue("newValue", ValueConversions<String>::toValue(m_newValue));
            return result;
        }

        std::unique_ptr<DomStorageItemAddedNotification> DomStorageItemAddedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<DomStorageItemUpdatedNotification> DomStorageItemUpdatedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<DomStorageItemUpdatedNotification> result(new DomStorageItemUpdatedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* storageIdValue = object->get("storageId");
            errors->setName("storageId");
            result->m_storageId = ValueConversions<protocol::DOMStorage::StorageId>::fromValue(storageIdValue, errors);
            protocol::Value* keyValue = object->get("key");
            errors->setName("key");
            result->m_key = ValueConversions<String>::fromValue(keyValue, errors);
            protocol::Value* oldValueValue = object->get("oldValue");
            errors->setName("oldValue");
            result->m_oldValue = ValueConversions<String>::fromValue(oldValueValue, errors);
            protocol::Value* newValueValue = object->get("newValue");
            errors->setName("newValue");
            result->m_newValue = ValueConversions<String>::fromValue(newValueValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> DomStorageItemUpdatedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("storageId", ValueConversions<protocol::DOMStorage::StorageId>::toValue(m_storageId.get()));
            result->setValue("key", ValueConversions<String>::toValue(m_key));
            result->setValue("oldValue", ValueConversions<String>::toValue(m_oldValue));
            result->setValue("newValue", ValueConversions<String>::toValue(m_newValue));
            return result;
        }

        std::unique_ptr<DomStorageItemUpdatedNotification> DomStorageItemUpdatedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        // ------------- Enum values from params.

        // ------------- Frontend notifications.

        void Frontend::domStorageItemsCleared(std::unique_ptr<protocol::DOMStorage::StorageId> storageId)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<DomStorageItemsClearedNotification> messageData = DomStorageItemsClearedNotification::create()
                                                                                  .setStorageId(std::move(storageId))
                                                                                  .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("DOMStorage.domStorageItemsCleared", std::move(messageData)));
        }

        void Frontend::domStorageItemRemoved(std::unique_ptr<protocol::DOMStorage::StorageId> storageId, const String& key)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<DomStorageItemRemovedNotification> messageData = DomStorageItemRemovedNotification::create()
                                                                                 .setStorageId(std::move(storageId))
                                                                                 .setKey(key)
                                                                                 .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("DOMStorage.domStorageItemRemoved", std::move(messageData)));
        }

        void Frontend::domStorageItemAdded(std::unique_ptr<protocol::DOMStorage::StorageId> storageId, const String& key, const String& newValue)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<DomStorageItemAddedNotification> messageData = DomStorageItemAddedNotification::create()
                                                                               .setStorageId(std::move(storageId))
                                                                               .setKey(key)
                                                                               .setNewValue(newValue)
                                                                               .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("DOMStorage.domStorageItemAdded", std::move(messageData)));
        }

        void Frontend::domStorageItemUpdated(std::unique_ptr<protocol::DOMStorage::StorageId> storageId, const String& key, const String& oldValue, const String& newValue)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<DomStorageItemUpdatedNotification> messageData = DomStorageItemUpdatedNotification::create()
                                                                                 .setStorageId(std::move(storageId))
                                                                                 .setKey(key)
                                                                                 .setOldValue(oldValue)
                                                                                 .setNewValue(newValue)
                                                                                 .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("DOMStorage.domStorageItemUpdated", std::move(messageData)));
        }

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
                m_dispatchMap["DOMStorage.enable"] = &DispatcherImpl::enable;
                m_dispatchMap["DOMStorage.disable"] = &DispatcherImpl::disable;
                m_dispatchMap["DOMStorage.getDOMStorageItems"] = &DispatcherImpl::getDOMStorageItems;
                m_dispatchMap["DOMStorage.setDOMStorageItem"] = &DispatcherImpl::setDOMStorageItem;
                m_dispatchMap["DOMStorage.removeDOMStorageItem"] = &DispatcherImpl::removeDOMStorageItem;
            }
            ~DispatcherImpl() override { }
            DispatchResponse::Status dispatch(int callId, const String& method, std::unique_ptr<protocol::DictionaryValue> messageObject) override;
            HashMap<String, String>& redirects() { return m_redirects; }

        protected:
            using CallHandler = DispatchResponse::Status (DispatcherImpl::*)(int callId, std::unique_ptr<DictionaryValue> messageObject, ErrorSupport* errors);
            using DispatchMap = protocol::HashMap<String, CallHandler>;
            DispatchMap m_dispatchMap;
            HashMap<String, String> m_redirects;

            DispatchResponse::Status enable(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status disable(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status getDOMStorageItems(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status setDOMStorageItem(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status removeDOMStorageItem(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);

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

        DispatchResponse::Status DispatcherImpl::enable(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->enable();
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::disable(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->disable();
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::getDOMStorageItems(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* storageIdValue = object ? object->get("storageId") : nullptr;
            errors->setName("storageId");
            std::unique_ptr<protocol::DOMStorage::StorageId> in_storageId = ValueConversions<protocol::DOMStorage::StorageId>::fromValue(storageIdValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }
            // Declare output parameters.
            std::unique_ptr<protocol::Array<protocol::Array<String>>> out_entries;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->getDOMStorageItems(std::move(in_storageId), &out_entries);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("entries", ValueConversions<protocol::Array<protocol::Array<String>>>::toValue(out_entries.get()));
            }
            if (weak->get())
                weak->get()->sendResponse(callId, response, std::move(result));
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::setDOMStorageItem(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* storageIdValue = object ? object->get("storageId") : nullptr;
            errors->setName("storageId");
            std::unique_ptr<protocol::DOMStorage::StorageId> in_storageId = ValueConversions<protocol::DOMStorage::StorageId>::fromValue(storageIdValue, errors);
            protocol::Value* keyValue = object ? object->get("key") : nullptr;
            errors->setName("key");
            String in_key = ValueConversions<String>::fromValue(keyValue, errors);
            protocol::Value* valueValue = object ? object->get("value") : nullptr;
            errors->setName("value");
            String in_value = ValueConversions<String>::fromValue(valueValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->setDOMStorageItem(std::move(in_storageId), in_key, in_value);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::removeDOMStorageItem(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* storageIdValue = object ? object->get("storageId") : nullptr;
            errors->setName("storageId");
            std::unique_ptr<protocol::DOMStorage::StorageId> in_storageId = ValueConversions<protocol::DOMStorage::StorageId>::fromValue(storageIdValue, errors);
            protocol::Value* keyValue = object ? object->get("key") : nullptr;
            errors->setName("key");
            String in_key = ValueConversions<String>::fromValue(keyValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->removeDOMStorageItem(std::move(in_storageId), in_key);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        // static
        void Dispatcher::wire(UberDispatcher* uber, Backend* backend)
        {
            std::unique_ptr<DispatcherImpl> dispatcher(new DispatcherImpl(uber->channel(), backend, uber->fallThroughForNotFound()));
            uber->setupRedirects(dispatcher->redirects());
            uber->registerBackend("DOMStorage", std::move(dispatcher));
        }

    } // DOMStorage
} // namespace blink
} // namespace protocol
