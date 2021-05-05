// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "content/browser/devtools/protocol/service_worker.h"

#include "content/browser/devtools/protocol/protocol.h"

namespace content {
namespace protocol {
    namespace ServiceWorker {

        // ------------- Enum values from types.

        const char Metainfo::domainName[] = "ServiceWorker";
        const char Metainfo::commandPrefix[] = "ServiceWorker.";
        const char Metainfo::version[] = "1.2";

        std::unique_ptr<ServiceWorkerRegistration> ServiceWorkerRegistration::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<ServiceWorkerRegistration> result(new ServiceWorkerRegistration());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* registrationIdValue = object->get("registrationId");
            errors->setName("registrationId");
            result->m_registrationId = ValueConversions<String>::fromValue(registrationIdValue, errors);
            protocol::Value* scopeURLValue = object->get("scopeURL");
            errors->setName("scopeURL");
            result->m_scopeURL = ValueConversions<String>::fromValue(scopeURLValue, errors);
            protocol::Value* isDeletedValue = object->get("isDeleted");
            errors->setName("isDeleted");
            result->m_isDeleted = ValueConversions<bool>::fromValue(isDeletedValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> ServiceWorkerRegistration::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("registrationId", ValueConversions<String>::toValue(m_registrationId));
            result->setValue("scopeURL", ValueConversions<String>::toValue(m_scopeURL));
            result->setValue("isDeleted", ValueConversions<bool>::toValue(m_isDeleted));
            return result;
        }

        std::unique_ptr<ServiceWorkerRegistration> ServiceWorkerRegistration::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        namespace ServiceWorkerVersionRunningStatusEnum {
            const char* Stopped = "stopped";
            const char* Starting = "starting";
            const char* Running = "running";
            const char* Stopping = "stopping";
        } // namespace ServiceWorkerVersionRunningStatusEnum

        namespace ServiceWorkerVersionStatusEnum {
            const char* New = "new";
            const char* Installing = "installing";
            const char* Installed = "installed";
            const char* Activating = "activating";
            const char* Activated = "activated";
            const char* Redundant = "redundant";
        } // namespace ServiceWorkerVersionStatusEnum

        std::unique_ptr<ServiceWorkerVersion> ServiceWorkerVersion::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<ServiceWorkerVersion> result(new ServiceWorkerVersion());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* versionIdValue = object->get("versionId");
            errors->setName("versionId");
            result->m_versionId = ValueConversions<String>::fromValue(versionIdValue, errors);
            protocol::Value* registrationIdValue = object->get("registrationId");
            errors->setName("registrationId");
            result->m_registrationId = ValueConversions<String>::fromValue(registrationIdValue, errors);
            protocol::Value* scriptURLValue = object->get("scriptURL");
            errors->setName("scriptURL");
            result->m_scriptURL = ValueConversions<String>::fromValue(scriptURLValue, errors);
            protocol::Value* runningStatusValue = object->get("runningStatus");
            errors->setName("runningStatus");
            result->m_runningStatus = ValueConversions<String>::fromValue(runningStatusValue, errors);
            protocol::Value* statusValue = object->get("status");
            errors->setName("status");
            result->m_status = ValueConversions<String>::fromValue(statusValue, errors);
            protocol::Value* scriptLastModifiedValue = object->get("scriptLastModified");
            if (scriptLastModifiedValue) {
                errors->setName("scriptLastModified");
                result->m_scriptLastModified = ValueConversions<double>::fromValue(scriptLastModifiedValue, errors);
            }
            protocol::Value* scriptResponseTimeValue = object->get("scriptResponseTime");
            if (scriptResponseTimeValue) {
                errors->setName("scriptResponseTime");
                result->m_scriptResponseTime = ValueConversions<double>::fromValue(scriptResponseTimeValue, errors);
            }
            protocol::Value* controlledClientsValue = object->get("controlledClients");
            if (controlledClientsValue) {
                errors->setName("controlledClients");
                result->m_controlledClients = ValueConversions<protocol::Array<String>>::fromValue(controlledClientsValue, errors);
            }
            protocol::Value* targetIdValue = object->get("targetId");
            if (targetIdValue) {
                errors->setName("targetId");
                result->m_targetId = ValueConversions<String>::fromValue(targetIdValue, errors);
            }
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> ServiceWorkerVersion::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("versionId", ValueConversions<String>::toValue(m_versionId));
            result->setValue("registrationId", ValueConversions<String>::toValue(m_registrationId));
            result->setValue("scriptURL", ValueConversions<String>::toValue(m_scriptURL));
            result->setValue("runningStatus", ValueConversions<String>::toValue(m_runningStatus));
            result->setValue("status", ValueConversions<String>::toValue(m_status));
            if (m_scriptLastModified.isJust())
                result->setValue("scriptLastModified", ValueConversions<double>::toValue(m_scriptLastModified.fromJust()));
            if (m_scriptResponseTime.isJust())
                result->setValue("scriptResponseTime", ValueConversions<double>::toValue(m_scriptResponseTime.fromJust()));
            if (m_controlledClients.isJust())
                result->setValue("controlledClients", ValueConversions<protocol::Array<String>>::toValue(m_controlledClients.fromJust()));
            if (m_targetId.isJust())
                result->setValue("targetId", ValueConversions<String>::toValue(m_targetId.fromJust()));
            return result;
        }

        std::unique_ptr<ServiceWorkerVersion> ServiceWorkerVersion::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<ServiceWorkerErrorMessage> ServiceWorkerErrorMessage::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<ServiceWorkerErrorMessage> result(new ServiceWorkerErrorMessage());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* errorMessageValue = object->get("errorMessage");
            errors->setName("errorMessage");
            result->m_errorMessage = ValueConversions<String>::fromValue(errorMessageValue, errors);
            protocol::Value* registrationIdValue = object->get("registrationId");
            errors->setName("registrationId");
            result->m_registrationId = ValueConversions<String>::fromValue(registrationIdValue, errors);
            protocol::Value* versionIdValue = object->get("versionId");
            errors->setName("versionId");
            result->m_versionId = ValueConversions<String>::fromValue(versionIdValue, errors);
            protocol::Value* sourceURLValue = object->get("sourceURL");
            errors->setName("sourceURL");
            result->m_sourceURL = ValueConversions<String>::fromValue(sourceURLValue, errors);
            protocol::Value* lineNumberValue = object->get("lineNumber");
            errors->setName("lineNumber");
            result->m_lineNumber = ValueConversions<int>::fromValue(lineNumberValue, errors);
            protocol::Value* columnNumberValue = object->get("columnNumber");
            errors->setName("columnNumber");
            result->m_columnNumber = ValueConversions<int>::fromValue(columnNumberValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> ServiceWorkerErrorMessage::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("errorMessage", ValueConversions<String>::toValue(m_errorMessage));
            result->setValue("registrationId", ValueConversions<String>::toValue(m_registrationId));
            result->setValue("versionId", ValueConversions<String>::toValue(m_versionId));
            result->setValue("sourceURL", ValueConversions<String>::toValue(m_sourceURL));
            result->setValue("lineNumber", ValueConversions<int>::toValue(m_lineNumber));
            result->setValue("columnNumber", ValueConversions<int>::toValue(m_columnNumber));
            return result;
        }

        std::unique_ptr<ServiceWorkerErrorMessage> ServiceWorkerErrorMessage::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<WorkerRegistrationUpdatedNotification> WorkerRegistrationUpdatedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<WorkerRegistrationUpdatedNotification> result(new WorkerRegistrationUpdatedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* registrationsValue = object->get("registrations");
            errors->setName("registrations");
            result->m_registrations = ValueConversions<protocol::Array<protocol::ServiceWorker::ServiceWorkerRegistration>>::fromValue(registrationsValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> WorkerRegistrationUpdatedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("registrations", ValueConversions<protocol::Array<protocol::ServiceWorker::ServiceWorkerRegistration>>::toValue(m_registrations.get()));
            return result;
        }

        std::unique_ptr<WorkerRegistrationUpdatedNotification> WorkerRegistrationUpdatedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<WorkerVersionUpdatedNotification> WorkerVersionUpdatedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<WorkerVersionUpdatedNotification> result(new WorkerVersionUpdatedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* versionsValue = object->get("versions");
            errors->setName("versions");
            result->m_versions = ValueConversions<protocol::Array<protocol::ServiceWorker::ServiceWorkerVersion>>::fromValue(versionsValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> WorkerVersionUpdatedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("versions", ValueConversions<protocol::Array<protocol::ServiceWorker::ServiceWorkerVersion>>::toValue(m_versions.get()));
            return result;
        }

        std::unique_ptr<WorkerVersionUpdatedNotification> WorkerVersionUpdatedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<WorkerErrorReportedNotification> WorkerErrorReportedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<WorkerErrorReportedNotification> result(new WorkerErrorReportedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* errorMessageValue = object->get("errorMessage");
            errors->setName("errorMessage");
            result->m_errorMessage = ValueConversions<protocol::ServiceWorker::ServiceWorkerErrorMessage>::fromValue(errorMessageValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> WorkerErrorReportedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("errorMessage", ValueConversions<protocol::ServiceWorker::ServiceWorkerErrorMessage>::toValue(m_errorMessage.get()));
            return result;
        }

        std::unique_ptr<WorkerErrorReportedNotification> WorkerErrorReportedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        // ------------- Enum values from params.

        // ------------- Frontend notifications.

        void Frontend::WorkerRegistrationUpdated(std::unique_ptr<protocol::Array<protocol::ServiceWorker::ServiceWorkerRegistration>> registrations)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<WorkerRegistrationUpdatedNotification> messageData = WorkerRegistrationUpdatedNotification::Create()
                                                                                     .SetRegistrations(std::move(registrations))
                                                                                     .Build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("ServiceWorker.workerRegistrationUpdated", std::move(messageData)));
        }

        void Frontend::WorkerVersionUpdated(std::unique_ptr<protocol::Array<protocol::ServiceWorker::ServiceWorkerVersion>> versions)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<WorkerVersionUpdatedNotification> messageData = WorkerVersionUpdatedNotification::Create()
                                                                                .SetVersions(std::move(versions))
                                                                                .Build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("ServiceWorker.workerVersionUpdated", std::move(messageData)));
        }

        void Frontend::WorkerErrorReported(std::unique_ptr<protocol::ServiceWorker::ServiceWorkerErrorMessage> errorMessage)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<WorkerErrorReportedNotification> messageData = WorkerErrorReportedNotification::Create()
                                                                               .SetErrorMessage(std::move(errorMessage))
                                                                               .Build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("ServiceWorker.workerErrorReported", std::move(messageData)));
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
                m_dispatchMap["ServiceWorker.enable"] = &DispatcherImpl::enable;
                m_dispatchMap["ServiceWorker.disable"] = &DispatcherImpl::disable;
                m_dispatchMap["ServiceWorker.unregister"] = &DispatcherImpl::unregister;
                m_dispatchMap["ServiceWorker.updateRegistration"] = &DispatcherImpl::updateRegistration;
                m_dispatchMap["ServiceWorker.startWorker"] = &DispatcherImpl::startWorker;
                m_dispatchMap["ServiceWorker.skipWaiting"] = &DispatcherImpl::skipWaiting;
                m_dispatchMap["ServiceWorker.stopWorker"] = &DispatcherImpl::stopWorker;
                m_dispatchMap["ServiceWorker.inspectWorker"] = &DispatcherImpl::inspectWorker;
                m_dispatchMap["ServiceWorker.setForceUpdateOnPageLoad"] = &DispatcherImpl::setForceUpdateOnPageLoad;
                m_dispatchMap["ServiceWorker.deliverPushMessage"] = &DispatcherImpl::deliverPushMessage;
                m_dispatchMap["ServiceWorker.dispatchSyncEvent"] = &DispatcherImpl::dispatchSyncEvent;
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
            DispatchResponse::Status unregister(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status updateRegistration(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status startWorker(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status skipWaiting(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status stopWorker(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status inspectWorker(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status setForceUpdateOnPageLoad(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status deliverPushMessage(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status dispatchSyncEvent(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);

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
            DispatchResponse response = m_backend->Enable();
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::disable(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->Disable();
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::unregister(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* scopeURLValue = object ? object->get("scopeURL") : nullptr;
            errors->setName("scopeURL");
            String in_scopeURL = ValueConversions<String>::fromValue(scopeURLValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->Unregister(in_scopeURL);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::updateRegistration(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* scopeURLValue = object ? object->get("scopeURL") : nullptr;
            errors->setName("scopeURL");
            String in_scopeURL = ValueConversions<String>::fromValue(scopeURLValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->UpdateRegistration(in_scopeURL);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::startWorker(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* scopeURLValue = object ? object->get("scopeURL") : nullptr;
            errors->setName("scopeURL");
            String in_scopeURL = ValueConversions<String>::fromValue(scopeURLValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->StartWorker(in_scopeURL);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::skipWaiting(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* scopeURLValue = object ? object->get("scopeURL") : nullptr;
            errors->setName("scopeURL");
            String in_scopeURL = ValueConversions<String>::fromValue(scopeURLValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->SkipWaiting(in_scopeURL);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::stopWorker(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* versionIdValue = object ? object->get("versionId") : nullptr;
            errors->setName("versionId");
            String in_versionId = ValueConversions<String>::fromValue(versionIdValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->StopWorker(in_versionId);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::inspectWorker(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* versionIdValue = object ? object->get("versionId") : nullptr;
            errors->setName("versionId");
            String in_versionId = ValueConversions<String>::fromValue(versionIdValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->InspectWorker(in_versionId);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::setForceUpdateOnPageLoad(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* forceUpdateOnPageLoadValue = object ? object->get("forceUpdateOnPageLoad") : nullptr;
            errors->setName("forceUpdateOnPageLoad");
            bool in_forceUpdateOnPageLoad = ValueConversions<bool>::fromValue(forceUpdateOnPageLoadValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->SetForceUpdateOnPageLoad(in_forceUpdateOnPageLoad);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::deliverPushMessage(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* originValue = object ? object->get("origin") : nullptr;
            errors->setName("origin");
            String in_origin = ValueConversions<String>::fromValue(originValue, errors);
            protocol::Value* registrationIdValue = object ? object->get("registrationId") : nullptr;
            errors->setName("registrationId");
            String in_registrationId = ValueConversions<String>::fromValue(registrationIdValue, errors);
            protocol::Value* dataValue = object ? object->get("data") : nullptr;
            errors->setName("data");
            String in_data = ValueConversions<String>::fromValue(dataValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->DeliverPushMessage(in_origin, in_registrationId, in_data);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::dispatchSyncEvent(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* originValue = object ? object->get("origin") : nullptr;
            errors->setName("origin");
            String in_origin = ValueConversions<String>::fromValue(originValue, errors);
            protocol::Value* registrationIdValue = object ? object->get("registrationId") : nullptr;
            errors->setName("registrationId");
            String in_registrationId = ValueConversions<String>::fromValue(registrationIdValue, errors);
            protocol::Value* tagValue = object ? object->get("tag") : nullptr;
            errors->setName("tag");
            String in_tag = ValueConversions<String>::fromValue(tagValue, errors);
            protocol::Value* lastChanceValue = object ? object->get("lastChance") : nullptr;
            errors->setName("lastChance");
            bool in_lastChance = ValueConversions<bool>::fromValue(lastChanceValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->DispatchSyncEvent(in_origin, in_registrationId, in_tag, in_lastChance);
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
            uber->registerBackend("ServiceWorker", std::move(dispatcher));
        }

    } // ServiceWorker
} // namespace content
} // namespace protocol
