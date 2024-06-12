// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "content/browser/devtools/protocol/network.h"

#include "content/browser/devtools/protocol/protocol.h"

namespace content {
namespace protocol {
    namespace Network {

        // ------------- Enum values from types.

        const char Metainfo::domainName[] = "Network";
        const char Metainfo::commandPrefix[] = "Network.";
        const char Metainfo::version[] = "1.2";

        namespace CookieSameSiteEnum {
            const char* Strict = "Strict";
            const char* Lax = "Lax";
        } // namespace CookieSameSiteEnum

        std::unique_ptr<Cookie> Cookie::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<Cookie> result(new Cookie());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* nameValue = object->get("name");
            errors->setName("name");
            result->m_name = ValueConversions<String>::fromValue(nameValue, errors);
            protocol::Value* valueValue = object->get("value");
            errors->setName("value");
            result->m_value = ValueConversions<String>::fromValue(valueValue, errors);
            protocol::Value* domainValue = object->get("domain");
            errors->setName("domain");
            result->m_domain = ValueConversions<String>::fromValue(domainValue, errors);
            protocol::Value* pathValue = object->get("path");
            errors->setName("path");
            result->m_path = ValueConversions<String>::fromValue(pathValue, errors);
            protocol::Value* expiresValue = object->get("expires");
            errors->setName("expires");
            result->m_expires = ValueConversions<double>::fromValue(expiresValue, errors);
            protocol::Value* sizeValue = object->get("size");
            errors->setName("size");
            result->m_size = ValueConversions<int>::fromValue(sizeValue, errors);
            protocol::Value* httpOnlyValue = object->get("httpOnly");
            errors->setName("httpOnly");
            result->m_httpOnly = ValueConversions<bool>::fromValue(httpOnlyValue, errors);
            protocol::Value* secureValue = object->get("secure");
            errors->setName("secure");
            result->m_secure = ValueConversions<bool>::fromValue(secureValue, errors);
            protocol::Value* sessionValue = object->get("session");
            errors->setName("session");
            result->m_session = ValueConversions<bool>::fromValue(sessionValue, errors);
            protocol::Value* sameSiteValue = object->get("sameSite");
            if (sameSiteValue) {
                errors->setName("sameSite");
                result->m_sameSite = ValueConversions<String>::fromValue(sameSiteValue, errors);
            }
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> Cookie::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("name", ValueConversions<String>::toValue(m_name));
            result->setValue("value", ValueConversions<String>::toValue(m_value));
            result->setValue("domain", ValueConversions<String>::toValue(m_domain));
            result->setValue("path", ValueConversions<String>::toValue(m_path));
            result->setValue("expires", ValueConversions<double>::toValue(m_expires));
            result->setValue("size", ValueConversions<int>::toValue(m_size));
            result->setValue("httpOnly", ValueConversions<bool>::toValue(m_httpOnly));
            result->setValue("secure", ValueConversions<bool>::toValue(m_secure));
            result->setValue("session", ValueConversions<bool>::toValue(m_session));
            if (m_sameSite.isJust())
                result->setValue("sameSite", ValueConversions<String>::toValue(m_sameSite.fromJust()));
            return result;
        }

        std::unique_ptr<Cookie> Cookie::clone() const
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
                m_dispatchMap["Network.enable"] = &DispatcherImpl::enable;
                m_dispatchMap["Network.disable"] = &DispatcherImpl::disable;
                m_dispatchMap["Network.setUserAgentOverride"] = &DispatcherImpl::setUserAgentOverride;
                m_dispatchMap["Network.clearBrowserCache"] = &DispatcherImpl::clearBrowserCache;
                m_dispatchMap["Network.clearBrowserCookies"] = &DispatcherImpl::clearBrowserCookies;
                m_dispatchMap["Network.getCookies"] = &DispatcherImpl::getCookies;
                m_dispatchMap["Network.getAllCookies"] = &DispatcherImpl::getAllCookies;
                m_dispatchMap["Network.deleteCookie"] = &DispatcherImpl::deleteCookie;
                m_dispatchMap["Network.setCookie"] = &DispatcherImpl::setCookie;
                m_dispatchMap["Network.canEmulateNetworkConditions"] = &DispatcherImpl::canEmulateNetworkConditions;
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
            DispatchResponse::Status setUserAgentOverride(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status clearBrowserCache(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status clearBrowserCookies(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status getCookies(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status getAllCookies(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status deleteCookie(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status setCookie(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status canEmulateNetworkConditions(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);

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
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* maxTotalBufferSizeValue = object ? object->get("maxTotalBufferSize") : nullptr;
            Maybe<int> in_maxTotalBufferSize;
            if (maxTotalBufferSizeValue) {
                errors->setName("maxTotalBufferSize");
                in_maxTotalBufferSize = ValueConversions<int>::fromValue(maxTotalBufferSizeValue, errors);
            }
            protocol::Value* maxResourceBufferSizeValue = object ? object->get("maxResourceBufferSize") : nullptr;
            Maybe<int> in_maxResourceBufferSize;
            if (maxResourceBufferSizeValue) {
                errors->setName("maxResourceBufferSize");
                in_maxResourceBufferSize = ValueConversions<int>::fromValue(maxResourceBufferSizeValue, errors);
            }
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->Enable(std::move(in_maxTotalBufferSize), std::move(in_maxResourceBufferSize));
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

        DispatchResponse::Status DispatcherImpl::setUserAgentOverride(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* userAgentValue = object ? object->get("userAgent") : nullptr;
            errors->setName("userAgent");
            String in_userAgent = ValueConversions<String>::fromValue(userAgentValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->SetUserAgentOverride(in_userAgent);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::clearBrowserCache(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->ClearBrowserCache();
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::clearBrowserCookies(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->ClearBrowserCookies();
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        class GetCookiesCallbackImpl : public Backend::GetCookiesCallback, public DispatcherBase::Callback {
        public:
            GetCookiesCallbackImpl(std::unique_ptr<DispatcherBase::WeakPtr> backendImpl, int callId, int callbackId)
                : DispatcherBase::Callback(std::move(backendImpl), callId, callbackId)
            {
            }

            void sendSuccess(std::unique_ptr<protocol::Array<protocol::Network::Cookie>> cookies) override
            {
                std::unique_ptr<protocol::DictionaryValue> resultObject = DictionaryValue::create();
                resultObject->setValue("cookies", ValueConversions<protocol::Array<protocol::Network::Cookie>>::toValue(cookies.get()));
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

        DispatchResponse::Status DispatcherImpl::getCookies(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            std::unique_ptr<GetCookiesCallbackImpl> callback(new GetCookiesCallbackImpl(weakPtr(), callId, nextCallbackId()));
            m_backend->GetCookies(std::move(callback));
            return (weak->get() && weak->get()->lastCallbackFallThrough()) ? DispatchResponse::kFallThrough : DispatchResponse::kAsync;
        }

        class GetAllCookiesCallbackImpl : public Backend::GetAllCookiesCallback, public DispatcherBase::Callback {
        public:
            GetAllCookiesCallbackImpl(std::unique_ptr<DispatcherBase::WeakPtr> backendImpl, int callId, int callbackId)
                : DispatcherBase::Callback(std::move(backendImpl), callId, callbackId)
            {
            }

            void sendSuccess(std::unique_ptr<protocol::Array<protocol::Network::Cookie>> cookies) override
            {
                std::unique_ptr<protocol::DictionaryValue> resultObject = DictionaryValue::create();
                resultObject->setValue("cookies", ValueConversions<protocol::Array<protocol::Network::Cookie>>::toValue(cookies.get()));
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

        DispatchResponse::Status DispatcherImpl::getAllCookies(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            std::unique_ptr<GetAllCookiesCallbackImpl> callback(new GetAllCookiesCallbackImpl(weakPtr(), callId, nextCallbackId()));
            m_backend->GetAllCookies(std::move(callback));
            return (weak->get() && weak->get()->lastCallbackFallThrough()) ? DispatchResponse::kFallThrough : DispatchResponse::kAsync;
        }

        class DeleteCookieCallbackImpl : public Backend::DeleteCookieCallback, public DispatcherBase::Callback {
        public:
            DeleteCookieCallbackImpl(std::unique_ptr<DispatcherBase::WeakPtr> backendImpl, int callId, int callbackId)
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

        DispatchResponse::Status DispatcherImpl::deleteCookie(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* cookieNameValue = object ? object->get("cookieName") : nullptr;
            errors->setName("cookieName");
            String in_cookieName = ValueConversions<String>::fromValue(cookieNameValue, errors);
            protocol::Value* urlValue = object ? object->get("url") : nullptr;
            errors->setName("url");
            String in_url = ValueConversions<String>::fromValue(urlValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            std::unique_ptr<DeleteCookieCallbackImpl> callback(new DeleteCookieCallbackImpl(weakPtr(), callId, nextCallbackId()));
            m_backend->DeleteCookie(in_cookieName, in_url, std::move(callback));
            return (weak->get() && weak->get()->lastCallbackFallThrough()) ? DispatchResponse::kFallThrough : DispatchResponse::kAsync;
        }

        class SetCookieCallbackImpl : public Backend::SetCookieCallback, public DispatcherBase::Callback {
        public:
            SetCookieCallbackImpl(std::unique_ptr<DispatcherBase::WeakPtr> backendImpl, int callId, int callbackId)
                : DispatcherBase::Callback(std::move(backendImpl), callId, callbackId)
            {
            }

            void sendSuccess(bool success) override
            {
                std::unique_ptr<protocol::DictionaryValue> resultObject = DictionaryValue::create();
                resultObject->setValue("success", ValueConversions<bool>::toValue(success));
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

        DispatchResponse::Status DispatcherImpl::setCookie(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* urlValue = object ? object->get("url") : nullptr;
            errors->setName("url");
            String in_url = ValueConversions<String>::fromValue(urlValue, errors);
            protocol::Value* nameValue = object ? object->get("name") : nullptr;
            errors->setName("name");
            String in_name = ValueConversions<String>::fromValue(nameValue, errors);
            protocol::Value* valueValue = object ? object->get("value") : nullptr;
            errors->setName("value");
            String in_value = ValueConversions<String>::fromValue(valueValue, errors);
            protocol::Value* domainValue = object ? object->get("domain") : nullptr;
            Maybe<String> in_domain;
            if (domainValue) {
                errors->setName("domain");
                in_domain = ValueConversions<String>::fromValue(domainValue, errors);
            }
            protocol::Value* pathValue = object ? object->get("path") : nullptr;
            Maybe<String> in_path;
            if (pathValue) {
                errors->setName("path");
                in_path = ValueConversions<String>::fromValue(pathValue, errors);
            }
            protocol::Value* secureValue = object ? object->get("secure") : nullptr;
            Maybe<bool> in_secure;
            if (secureValue) {
                errors->setName("secure");
                in_secure = ValueConversions<bool>::fromValue(secureValue, errors);
            }
            protocol::Value* httpOnlyValue = object ? object->get("httpOnly") : nullptr;
            Maybe<bool> in_httpOnly;
            if (httpOnlyValue) {
                errors->setName("httpOnly");
                in_httpOnly = ValueConversions<bool>::fromValue(httpOnlyValue, errors);
            }
            protocol::Value* sameSiteValue = object ? object->get("sameSite") : nullptr;
            Maybe<String> in_sameSite;
            if (sameSiteValue) {
                errors->setName("sameSite");
                in_sameSite = ValueConversions<String>::fromValue(sameSiteValue, errors);
            }
            protocol::Value* expirationDateValue = object ? object->get("expirationDate") : nullptr;
            Maybe<double> in_expirationDate;
            if (expirationDateValue) {
                errors->setName("expirationDate");
                in_expirationDate = ValueConversions<double>::fromValue(expirationDateValue, errors);
            }
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            std::unique_ptr<SetCookieCallbackImpl> callback(new SetCookieCallbackImpl(weakPtr(), callId, nextCallbackId()));
            m_backend->SetCookie(in_url, in_name, in_value, std::move(in_domain), std::move(in_path), std::move(in_secure), std::move(in_httpOnly), std::move(in_sameSite), std::move(in_expirationDate), std::move(callback));
            return (weak->get() && weak->get()->lastCallbackFallThrough()) ? DispatchResponse::kFallThrough : DispatchResponse::kAsync;
        }

        DispatchResponse::Status DispatcherImpl::canEmulateNetworkConditions(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Declare output parameters.
            bool out_result;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->CanEmulateNetworkConditions(&out_result);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            if (response.status() == DispatchResponse::kSuccess) {
                result->setValue("result", ValueConversions<bool>::toValue(out_result));
            }
            if (weak->get())
                weak->get()->sendResponse(callId, response, std::move(result));
            return response.status();
        }

        // static
        void Dispatcher::wire(UberDispatcher* uber, Backend* backend)
        {
            std::unique_ptr<DispatcherImpl> dispatcher(new DispatcherImpl(uber->channel(), backend, uber->fallThroughForNotFound()));
            uber->setupRedirects(dispatcher->redirects());
            uber->registerBackend("Network", std::move(dispatcher));
        }

    } // Network
} // namespace content
} // namespace protocol
