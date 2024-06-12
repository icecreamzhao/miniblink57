// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "core/inspector/protocol/Database.h"

#include "core/inspector/protocol/Protocol.h"

namespace blink {
namespace protocol {
    namespace Database {

        // ------------- Enum values from types.

        const char Metainfo::domainName[] = "Database";
        const char Metainfo::commandPrefix[] = "Database.";
        const char Metainfo::version[] = "1.2";

        std::unique_ptr<Database> Database::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<Database> result(new Database());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* idValue = object->get("id");
            errors->setName("id");
            result->m_id = ValueConversions<String>::fromValue(idValue, errors);
            protocol::Value* domainValue = object->get("domain");
            errors->setName("domain");
            result->m_domain = ValueConversions<String>::fromValue(domainValue, errors);
            protocol::Value* nameValue = object->get("name");
            errors->setName("name");
            result->m_name = ValueConversions<String>::fromValue(nameValue, errors);
            protocol::Value* versionValue = object->get("version");
            errors->setName("version");
            result->m_version = ValueConversions<String>::fromValue(versionValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> Database::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("id", ValueConversions<String>::toValue(m_id));
            result->setValue("domain", ValueConversions<String>::toValue(m_domain));
            result->setValue("name", ValueConversions<String>::toValue(m_name));
            result->setValue("version", ValueConversions<String>::toValue(m_version));
            return result;
        }

        std::unique_ptr<Database> Database::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<Error> Error::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<Error> result(new Error());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* messageValue = object->get("message");
            errors->setName("message");
            result->m_message = ValueConversions<String>::fromValue(messageValue, errors);
            protocol::Value* codeValue = object->get("code");
            errors->setName("code");
            result->m_code = ValueConversions<int>::fromValue(codeValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> Error::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("message", ValueConversions<String>::toValue(m_message));
            result->setValue("code", ValueConversions<int>::toValue(m_code));
            return result;
        }

        std::unique_ptr<Error> Error::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<AddDatabaseNotification> AddDatabaseNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<AddDatabaseNotification> result(new AddDatabaseNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* databaseValue = object->get("database");
            errors->setName("database");
            result->m_database = ValueConversions<protocol::Database::Database>::fromValue(databaseValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> AddDatabaseNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("database", ValueConversions<protocol::Database::Database>::toValue(m_database.get()));
            return result;
        }

        std::unique_ptr<AddDatabaseNotification> AddDatabaseNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        // ------------- Enum values from params.

        // ------------- Frontend notifications.

        void Frontend::addDatabase(std::unique_ptr<protocol::Database::Database> database)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<AddDatabaseNotification> messageData = AddDatabaseNotification::create()
                                                                       .setDatabase(std::move(database))
                                                                       .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("Database.addDatabase", std::move(messageData)));
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
                m_dispatchMap["Database.enable"] = &DispatcherImpl::enable;
                m_dispatchMap["Database.disable"] = &DispatcherImpl::disable;
                m_dispatchMap["Database.getDatabaseTableNames"] = &DispatcherImpl::getDatabaseTableNames;
                m_dispatchMap["Database.executeSQL"] = &DispatcherImpl::executeSQL;
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
            DispatchResponse::Status getDatabaseTableNames(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status executeSQL(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);

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

        DispatchResponse::Status DispatcherImpl::getDatabaseTableNames(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* databaseIdValue = object ? object->get("databaseId") : nullptr;
            errors->setName("databaseId");
            String in_databaseId = ValueConversions<String>::fromValue(databaseIdValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }
            // Declare output parameters.
            std::unique_ptr<protocol::Array<String>> out_tableNames;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->getDatabaseTableNames(in_databaseId, &out_tableNames);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("tableNames", ValueConversions<protocol::Array<String>>::toValue(out_tableNames.get()));
            }
            if (weak->get())
                weak->get()->sendResponse(callId, response, std::move(result));
            return response.status();
        }

        class ExecuteSQLCallbackImpl : public Backend::ExecuteSQLCallback, public DispatcherBase::Callback {
        public:
            ExecuteSQLCallbackImpl(std::unique_ptr<DispatcherBase::WeakPtr> backendImpl, int callId, int callbackId)
                : DispatcherBase::Callback(std::move(backendImpl), callId, callbackId)
            {
            }

            void sendSuccess(Maybe<protocol::Array<String>> columnNames, Maybe<protocol::Array<protocol::Value>> values, Maybe<protocol::Database::Error> sqlError) override
            {
                std::unique_ptr<protocol::DictionaryValue> resultObject = DictionaryValue::create();
                if (columnNames.isJust())
                    resultObject->setValue("columnNames", ValueConversions<protocol::Array<String>>::toValue(columnNames.fromJust()));
                if (values.isJust())
                    resultObject->setValue("values", ValueConversions<protocol::Array<protocol::Value>>::toValue(values.fromJust()));
                if (sqlError.isJust())
                    resultObject->setValue("sqlError", ValueConversions<protocol::Database::Error>::toValue(sqlError.fromJust()));
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

        DispatchResponse::Status DispatcherImpl::executeSQL(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* databaseIdValue = object ? object->get("databaseId") : nullptr;
            errors->setName("databaseId");
            String in_databaseId = ValueConversions<String>::fromValue(databaseIdValue, errors);
            protocol::Value* queryValue = object ? object->get("query") : nullptr;
            errors->setName("query");
            String in_query = ValueConversions<String>::fromValue(queryValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            std::unique_ptr<ExecuteSQLCallbackImpl> callback(new ExecuteSQLCallbackImpl(weakPtr(), callId, nextCallbackId()));
            m_backend->executeSQL(in_databaseId, in_query, std::move(callback));
            return (weak->get() && weak->get()->lastCallbackFallThrough()) ? DispatchResponse::kFallThrough : DispatchResponse::kAsync;
        }

        // static
        void Dispatcher::wire(UberDispatcher* uber, Backend* backend)
        {
            std::unique_ptr<DispatcherImpl> dispatcher(new DispatcherImpl(uber->channel(), backend, uber->fallThroughForNotFound()));
            uber->setupRedirects(dispatcher->redirects());
            uber->registerBackend("Database", std::move(dispatcher));
        }

    } // Database
} // namespace blink
} // namespace protocol
