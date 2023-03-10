// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "core/inspector/protocol/Network.h"

#include "core/inspector/protocol/Protocol.h"

namespace blink {
namespace protocol {
    namespace Network {

        // ------------- Enum values from types.

        const char Metainfo::domainName[] = "Network";
        const char Metainfo::commandPrefix[] = "Network.";
        const char Metainfo::version[] = "1.2";

        namespace ConnectionTypeEnum {
            const char* None = "none";
            const char* Cellular2g = "cellular2g";
            const char* Cellular3g = "cellular3g";
            const char* Cellular4g = "cellular4g";
            const char* Bluetooth = "bluetooth";
            const char* Ethernet = "ethernet";
            const char* Wifi = "wifi";
            const char* Wimax = "wimax";
            const char* Other = "other";
        } // namespace ConnectionTypeEnum

        namespace CookieSameSiteEnum {
            const char* Strict = "Strict";
            const char* Lax = "Lax";
        } // namespace CookieSameSiteEnum

        std::unique_ptr<ResourceTiming> ResourceTiming::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<ResourceTiming> result(new ResourceTiming());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* requestTimeValue = object->get("requestTime");
            errors->setName("requestTime");
            result->m_requestTime = ValueConversions<double>::fromValue(requestTimeValue, errors);
            protocol::Value* proxyStartValue = object->get("proxyStart");
            errors->setName("proxyStart");
            result->m_proxyStart = ValueConversions<double>::fromValue(proxyStartValue, errors);
            protocol::Value* proxyEndValue = object->get("proxyEnd");
            errors->setName("proxyEnd");
            result->m_proxyEnd = ValueConversions<double>::fromValue(proxyEndValue, errors);
            protocol::Value* dnsStartValue = object->get("dnsStart");
            errors->setName("dnsStart");
            result->m_dnsStart = ValueConversions<double>::fromValue(dnsStartValue, errors);
            protocol::Value* dnsEndValue = object->get("dnsEnd");
            errors->setName("dnsEnd");
            result->m_dnsEnd = ValueConversions<double>::fromValue(dnsEndValue, errors);
            protocol::Value* connectStartValue = object->get("connectStart");
            errors->setName("connectStart");
            result->m_connectStart = ValueConversions<double>::fromValue(connectStartValue, errors);
            protocol::Value* connectEndValue = object->get("connectEnd");
            errors->setName("connectEnd");
            result->m_connectEnd = ValueConversions<double>::fromValue(connectEndValue, errors);
            protocol::Value* sslStartValue = object->get("sslStart");
            errors->setName("sslStart");
            result->m_sslStart = ValueConversions<double>::fromValue(sslStartValue, errors);
            protocol::Value* sslEndValue = object->get("sslEnd");
            errors->setName("sslEnd");
            result->m_sslEnd = ValueConversions<double>::fromValue(sslEndValue, errors);
            protocol::Value* workerStartValue = object->get("workerStart");
            errors->setName("workerStart");
            result->m_workerStart = ValueConversions<double>::fromValue(workerStartValue, errors);
            protocol::Value* workerReadyValue = object->get("workerReady");
            errors->setName("workerReady");
            result->m_workerReady = ValueConversions<double>::fromValue(workerReadyValue, errors);
            protocol::Value* sendStartValue = object->get("sendStart");
            errors->setName("sendStart");
            result->m_sendStart = ValueConversions<double>::fromValue(sendStartValue, errors);
            protocol::Value* sendEndValue = object->get("sendEnd");
            errors->setName("sendEnd");
            result->m_sendEnd = ValueConversions<double>::fromValue(sendEndValue, errors);
            protocol::Value* pushStartValue = object->get("pushStart");
            errors->setName("pushStart");
            result->m_pushStart = ValueConversions<double>::fromValue(pushStartValue, errors);
            protocol::Value* pushEndValue = object->get("pushEnd");
            errors->setName("pushEnd");
            result->m_pushEnd = ValueConversions<double>::fromValue(pushEndValue, errors);
            protocol::Value* receiveHeadersEndValue = object->get("receiveHeadersEnd");
            errors->setName("receiveHeadersEnd");
            result->m_receiveHeadersEnd = ValueConversions<double>::fromValue(receiveHeadersEndValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> ResourceTiming::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("requestTime", ValueConversions<double>::toValue(m_requestTime));
            result->setValue("proxyStart", ValueConversions<double>::toValue(m_proxyStart));
            result->setValue("proxyEnd", ValueConversions<double>::toValue(m_proxyEnd));
            result->setValue("dnsStart", ValueConversions<double>::toValue(m_dnsStart));
            result->setValue("dnsEnd", ValueConversions<double>::toValue(m_dnsEnd));
            result->setValue("connectStart", ValueConversions<double>::toValue(m_connectStart));
            result->setValue("connectEnd", ValueConversions<double>::toValue(m_connectEnd));
            result->setValue("sslStart", ValueConversions<double>::toValue(m_sslStart));
            result->setValue("sslEnd", ValueConversions<double>::toValue(m_sslEnd));
            result->setValue("workerStart", ValueConversions<double>::toValue(m_workerStart));
            result->setValue("workerReady", ValueConversions<double>::toValue(m_workerReady));
            result->setValue("sendStart", ValueConversions<double>::toValue(m_sendStart));
            result->setValue("sendEnd", ValueConversions<double>::toValue(m_sendEnd));
            result->setValue("pushStart", ValueConversions<double>::toValue(m_pushStart));
            result->setValue("pushEnd", ValueConversions<double>::toValue(m_pushEnd));
            result->setValue("receiveHeadersEnd", ValueConversions<double>::toValue(m_receiveHeadersEnd));
            return result;
        }

        std::unique_ptr<ResourceTiming> ResourceTiming::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        namespace ResourcePriorityEnum {
            const char* VeryLow = "VeryLow";
            const char* Low = "Low";
            const char* Medium = "Medium";
            const char* High = "High";
            const char* VeryHigh = "VeryHigh";
        } // namespace ResourcePriorityEnum

        const char* Request::MixedContentTypeEnum::Blockable = "blockable";
        const char* Request::MixedContentTypeEnum::OptionallyBlockable = "optionally-blockable";
        const char* Request::MixedContentTypeEnum::None = "none";

        const char* Request::ReferrerPolicyEnum::UnsafeUrl = "unsafe-url";
        const char* Request::ReferrerPolicyEnum::NoReferrerWhenDowngrade = "no-referrer-when-downgrade";
        const char* Request::ReferrerPolicyEnum::NoReferrer = "no-referrer";
        const char* Request::ReferrerPolicyEnum::Origin = "origin";
        const char* Request::ReferrerPolicyEnum::OriginWhenCrossOrigin = "origin-when-cross-origin";
        const char* Request::ReferrerPolicyEnum::NoReferrerWhenDowngradeOriginWhenCrossOrigin = "no-referrer-when-downgrade-origin-when-cross-origin";

        std::unique_ptr<Request> Request::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<Request> result(new Request());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* urlValue = object->get("url");
            errors->setName("url");
            result->m_url = ValueConversions<String>::fromValue(urlValue, errors);
            protocol::Value* methodValue = object->get("method");
            errors->setName("method");
            result->m_method = ValueConversions<String>::fromValue(methodValue, errors);
            protocol::Value* headersValue = object->get("headers");
            errors->setName("headers");
            result->m_headers = ValueConversions<protocol::Network::Headers>::fromValue(headersValue, errors);
            protocol::Value* postDataValue = object->get("postData");
            if (postDataValue) {
                errors->setName("postData");
                result->m_postData = ValueConversions<String>::fromValue(postDataValue, errors);
            }
            protocol::Value* mixedContentTypeValue = object->get("mixedContentType");
            if (mixedContentTypeValue) {
                errors->setName("mixedContentType");
                result->m_mixedContentType = ValueConversions<String>::fromValue(mixedContentTypeValue, errors);
            }
            protocol::Value* initialPriorityValue = object->get("initialPriority");
            errors->setName("initialPriority");
            result->m_initialPriority = ValueConversions<String>::fromValue(initialPriorityValue, errors);
            protocol::Value* referrerPolicyValue = object->get("referrerPolicy");
            errors->setName("referrerPolicy");
            result->m_referrerPolicy = ValueConversions<String>::fromValue(referrerPolicyValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> Request::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("url", ValueConversions<String>::toValue(m_url));
            result->setValue("method", ValueConversions<String>::toValue(m_method));
            result->setValue("headers", ValueConversions<protocol::Network::Headers>::toValue(m_headers.get()));
            if (m_postData.isJust())
                result->setValue("postData", ValueConversions<String>::toValue(m_postData.fromJust()));
            if (m_mixedContentType.isJust())
                result->setValue("mixedContentType", ValueConversions<String>::toValue(m_mixedContentType.fromJust()));
            result->setValue("initialPriority", ValueConversions<String>::toValue(m_initialPriority));
            result->setValue("referrerPolicy", ValueConversions<String>::toValue(m_referrerPolicy));
            return result;
        }

        std::unique_ptr<Request> Request::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<SignedCertificateTimestamp> SignedCertificateTimestamp::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<SignedCertificateTimestamp> result(new SignedCertificateTimestamp());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* statusValue = object->get("status");
            errors->setName("status");
            result->m_status = ValueConversions<String>::fromValue(statusValue, errors);
            protocol::Value* originValue = object->get("origin");
            errors->setName("origin");
            result->m_origin = ValueConversions<String>::fromValue(originValue, errors);
            protocol::Value* logDescriptionValue = object->get("logDescription");
            errors->setName("logDescription");
            result->m_logDescription = ValueConversions<String>::fromValue(logDescriptionValue, errors);
            protocol::Value* logIdValue = object->get("logId");
            errors->setName("logId");
            result->m_logId = ValueConversions<String>::fromValue(logIdValue, errors);
            protocol::Value* timestampValue = object->get("timestamp");
            errors->setName("timestamp");
            result->m_timestamp = ValueConversions<double>::fromValue(timestampValue, errors);
            protocol::Value* hashAlgorithmValue = object->get("hashAlgorithm");
            errors->setName("hashAlgorithm");
            result->m_hashAlgorithm = ValueConversions<String>::fromValue(hashAlgorithmValue, errors);
            protocol::Value* signatureAlgorithmValue = object->get("signatureAlgorithm");
            errors->setName("signatureAlgorithm");
            result->m_signatureAlgorithm = ValueConversions<String>::fromValue(signatureAlgorithmValue, errors);
            protocol::Value* signatureDataValue = object->get("signatureData");
            errors->setName("signatureData");
            result->m_signatureData = ValueConversions<String>::fromValue(signatureDataValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> SignedCertificateTimestamp::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("status", ValueConversions<String>::toValue(m_status));
            result->setValue("origin", ValueConversions<String>::toValue(m_origin));
            result->setValue("logDescription", ValueConversions<String>::toValue(m_logDescription));
            result->setValue("logId", ValueConversions<String>::toValue(m_logId));
            result->setValue("timestamp", ValueConversions<double>::toValue(m_timestamp));
            result->setValue("hashAlgorithm", ValueConversions<String>::toValue(m_hashAlgorithm));
            result->setValue("signatureAlgorithm", ValueConversions<String>::toValue(m_signatureAlgorithm));
            result->setValue("signatureData", ValueConversions<String>::toValue(m_signatureData));
            return result;
        }

        std::unique_ptr<SignedCertificateTimestamp> SignedCertificateTimestamp::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<SecurityDetails> SecurityDetails::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<SecurityDetails> result(new SecurityDetails());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* protocolValue = object->get("protocol");
            errors->setName("protocol");
            result->m_protocol = ValueConversions<String>::fromValue(protocolValue, errors);
            protocol::Value* keyExchangeValue = object->get("keyExchange");
            errors->setName("keyExchange");
            result->m_keyExchange = ValueConversions<String>::fromValue(keyExchangeValue, errors);
            protocol::Value* keyExchangeGroupValue = object->get("keyExchangeGroup");
            if (keyExchangeGroupValue) {
                errors->setName("keyExchangeGroup");
                result->m_keyExchangeGroup = ValueConversions<String>::fromValue(keyExchangeGroupValue, errors);
            }
            protocol::Value* cipherValue = object->get("cipher");
            errors->setName("cipher");
            result->m_cipher = ValueConversions<String>::fromValue(cipherValue, errors);
            protocol::Value* macValue = object->get("mac");
            if (macValue) {
                errors->setName("mac");
                result->m_mac = ValueConversions<String>::fromValue(macValue, errors);
            }
            protocol::Value* certificateIdValue = object->get("certificateId");
            errors->setName("certificateId");
            result->m_certificateId = ValueConversions<int>::fromValue(certificateIdValue, errors);
            protocol::Value* subjectNameValue = object->get("subjectName");
            errors->setName("subjectName");
            result->m_subjectName = ValueConversions<String>::fromValue(subjectNameValue, errors);
            protocol::Value* sanListValue = object->get("sanList");
            errors->setName("sanList");
            result->m_sanList = ValueConversions<protocol::Array<String>>::fromValue(sanListValue, errors);
            protocol::Value* issuerValue = object->get("issuer");
            errors->setName("issuer");
            result->m_issuer = ValueConversions<String>::fromValue(issuerValue, errors);
            protocol::Value* validFromValue = object->get("validFrom");
            errors->setName("validFrom");
            result->m_validFrom = ValueConversions<double>::fromValue(validFromValue, errors);
            protocol::Value* validToValue = object->get("validTo");
            errors->setName("validTo");
            result->m_validTo = ValueConversions<double>::fromValue(validToValue, errors);
            protocol::Value* signedCertificateTimestampListValue = object->get("signedCertificateTimestampList");
            errors->setName("signedCertificateTimestampList");
            result->m_signedCertificateTimestampList = ValueConversions<protocol::Array<protocol::Network::SignedCertificateTimestamp>>::fromValue(signedCertificateTimestampListValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> SecurityDetails::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("protocol", ValueConversions<String>::toValue(m_protocol));
            result->setValue("keyExchange", ValueConversions<String>::toValue(m_keyExchange));
            if (m_keyExchangeGroup.isJust())
                result->setValue("keyExchangeGroup", ValueConversions<String>::toValue(m_keyExchangeGroup.fromJust()));
            result->setValue("cipher", ValueConversions<String>::toValue(m_cipher));
            if (m_mac.isJust())
                result->setValue("mac", ValueConversions<String>::toValue(m_mac.fromJust()));
            result->setValue("certificateId", ValueConversions<int>::toValue(m_certificateId));
            result->setValue("subjectName", ValueConversions<String>::toValue(m_subjectName));
            result->setValue("sanList", ValueConversions<protocol::Array<String>>::toValue(m_sanList.get()));
            result->setValue("issuer", ValueConversions<String>::toValue(m_issuer));
            result->setValue("validFrom", ValueConversions<double>::toValue(m_validFrom));
            result->setValue("validTo", ValueConversions<double>::toValue(m_validTo));
            result->setValue("signedCertificateTimestampList", ValueConversions<protocol::Array<protocol::Network::SignedCertificateTimestamp>>::toValue(m_signedCertificateTimestampList.get()));
            return result;
        }

        std::unique_ptr<SecurityDetails> SecurityDetails::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        namespace BlockedReasonEnum {
            const char* Csp = "csp";
            const char* MixedContent = "mixed-content";
            const char* Origin = "origin";
            const char* Inspector = "inspector";
            const char* SubresourceFilter = "subresource-filter";
            const char* Other = "other";
        } // namespace BlockedReasonEnum

        std::unique_ptr<Response> Response::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<Response> result(new Response());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* urlValue = object->get("url");
            errors->setName("url");
            result->m_url = ValueConversions<String>::fromValue(urlValue, errors);
            protocol::Value* statusValue = object->get("status");
            errors->setName("status");
            result->m_status = ValueConversions<double>::fromValue(statusValue, errors);
            protocol::Value* statusTextValue = object->get("statusText");
            errors->setName("statusText");
            result->m_statusText = ValueConversions<String>::fromValue(statusTextValue, errors);
            protocol::Value* headersValue = object->get("headers");
            errors->setName("headers");
            result->m_headers = ValueConversions<protocol::Network::Headers>::fromValue(headersValue, errors);
            protocol::Value* headersTextValue = object->get("headersText");
            if (headersTextValue) {
                errors->setName("headersText");
                result->m_headersText = ValueConversions<String>::fromValue(headersTextValue, errors);
            }
            protocol::Value* mimeTypeValue = object->get("mimeType");
            errors->setName("mimeType");
            result->m_mimeType = ValueConversions<String>::fromValue(mimeTypeValue, errors);
            protocol::Value* requestHeadersValue = object->get("requestHeaders");
            if (requestHeadersValue) {
                errors->setName("requestHeaders");
                result->m_requestHeaders = ValueConversions<protocol::Network::Headers>::fromValue(requestHeadersValue, errors);
            }
            protocol::Value* requestHeadersTextValue = object->get("requestHeadersText");
            if (requestHeadersTextValue) {
                errors->setName("requestHeadersText");
                result->m_requestHeadersText = ValueConversions<String>::fromValue(requestHeadersTextValue, errors);
            }
            protocol::Value* connectionReusedValue = object->get("connectionReused");
            errors->setName("connectionReused");
            result->m_connectionReused = ValueConversions<bool>::fromValue(connectionReusedValue, errors);
            protocol::Value* connectionIdValue = object->get("connectionId");
            errors->setName("connectionId");
            result->m_connectionId = ValueConversions<double>::fromValue(connectionIdValue, errors);
            protocol::Value* remoteIPAddressValue = object->get("remoteIPAddress");
            if (remoteIPAddressValue) {
                errors->setName("remoteIPAddress");
                result->m_remoteIPAddress = ValueConversions<String>::fromValue(remoteIPAddressValue, errors);
            }
            protocol::Value* remotePortValue = object->get("remotePort");
            if (remotePortValue) {
                errors->setName("remotePort");
                result->m_remotePort = ValueConversions<int>::fromValue(remotePortValue, errors);
            }
            protocol::Value* fromDiskCacheValue = object->get("fromDiskCache");
            if (fromDiskCacheValue) {
                errors->setName("fromDiskCache");
                result->m_fromDiskCache = ValueConversions<bool>::fromValue(fromDiskCacheValue, errors);
            }
            protocol::Value* fromServiceWorkerValue = object->get("fromServiceWorker");
            if (fromServiceWorkerValue) {
                errors->setName("fromServiceWorker");
                result->m_fromServiceWorker = ValueConversions<bool>::fromValue(fromServiceWorkerValue, errors);
            }
            protocol::Value* encodedDataLengthValue = object->get("encodedDataLength");
            errors->setName("encodedDataLength");
            result->m_encodedDataLength = ValueConversions<double>::fromValue(encodedDataLengthValue, errors);
            protocol::Value* timingValue = object->get("timing");
            if (timingValue) {
                errors->setName("timing");
                result->m_timing = ValueConversions<protocol::Network::ResourceTiming>::fromValue(timingValue, errors);
            }
            protocol::Value* protocolValue = object->get("protocol");
            if (protocolValue) {
                errors->setName("protocol");
                result->m_protocol = ValueConversions<String>::fromValue(protocolValue, errors);
            }
            protocol::Value* securityStateValue = object->get("securityState");
            errors->setName("securityState");
            result->m_securityState = ValueConversions<String>::fromValue(securityStateValue, errors);
            protocol::Value* securityDetailsValue = object->get("securityDetails");
            if (securityDetailsValue) {
                errors->setName("securityDetails");
                result->m_securityDetails = ValueConversions<protocol::Network::SecurityDetails>::fromValue(securityDetailsValue, errors);
            }
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> Response::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("url", ValueConversions<String>::toValue(m_url));
            result->setValue("status", ValueConversions<double>::toValue(m_status));
            result->setValue("statusText", ValueConversions<String>::toValue(m_statusText));
            result->setValue("headers", ValueConversions<protocol::Network::Headers>::toValue(m_headers.get()));
            if (m_headersText.isJust())
                result->setValue("headersText", ValueConversions<String>::toValue(m_headersText.fromJust()));
            result->setValue("mimeType", ValueConversions<String>::toValue(m_mimeType));
            if (m_requestHeaders.isJust())
                result->setValue("requestHeaders", ValueConversions<protocol::Network::Headers>::toValue(m_requestHeaders.fromJust()));
            if (m_requestHeadersText.isJust())
                result->setValue("requestHeadersText", ValueConversions<String>::toValue(m_requestHeadersText.fromJust()));
            result->setValue("connectionReused", ValueConversions<bool>::toValue(m_connectionReused));
            result->setValue("connectionId", ValueConversions<double>::toValue(m_connectionId));
            if (m_remoteIPAddress.isJust())
                result->setValue("remoteIPAddress", ValueConversions<String>::toValue(m_remoteIPAddress.fromJust()));
            if (m_remotePort.isJust())
                result->setValue("remotePort", ValueConversions<int>::toValue(m_remotePort.fromJust()));
            if (m_fromDiskCache.isJust())
                result->setValue("fromDiskCache", ValueConversions<bool>::toValue(m_fromDiskCache.fromJust()));
            if (m_fromServiceWorker.isJust())
                result->setValue("fromServiceWorker", ValueConversions<bool>::toValue(m_fromServiceWorker.fromJust()));
            result->setValue("encodedDataLength", ValueConversions<double>::toValue(m_encodedDataLength));
            if (m_timing.isJust())
                result->setValue("timing", ValueConversions<protocol::Network::ResourceTiming>::toValue(m_timing.fromJust()));
            if (m_protocol.isJust())
                result->setValue("protocol", ValueConversions<String>::toValue(m_protocol.fromJust()));
            result->setValue("securityState", ValueConversions<String>::toValue(m_securityState));
            if (m_securityDetails.isJust())
                result->setValue("securityDetails", ValueConversions<protocol::Network::SecurityDetails>::toValue(m_securityDetails.fromJust()));
            return result;
        }

        std::unique_ptr<Response> Response::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<WebSocketRequest> WebSocketRequest::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<WebSocketRequest> result(new WebSocketRequest());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* headersValue = object->get("headers");
            errors->setName("headers");
            result->m_headers = ValueConversions<protocol::Network::Headers>::fromValue(headersValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> WebSocketRequest::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("headers", ValueConversions<protocol::Network::Headers>::toValue(m_headers.get()));
            return result;
        }

        std::unique_ptr<WebSocketRequest> WebSocketRequest::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<WebSocketResponse> WebSocketResponse::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<WebSocketResponse> result(new WebSocketResponse());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* statusValue = object->get("status");
            errors->setName("status");
            result->m_status = ValueConversions<double>::fromValue(statusValue, errors);
            protocol::Value* statusTextValue = object->get("statusText");
            errors->setName("statusText");
            result->m_statusText = ValueConversions<String>::fromValue(statusTextValue, errors);
            protocol::Value* headersValue = object->get("headers");
            errors->setName("headers");
            result->m_headers = ValueConversions<protocol::Network::Headers>::fromValue(headersValue, errors);
            protocol::Value* headersTextValue = object->get("headersText");
            if (headersTextValue) {
                errors->setName("headersText");
                result->m_headersText = ValueConversions<String>::fromValue(headersTextValue, errors);
            }
            protocol::Value* requestHeadersValue = object->get("requestHeaders");
            if (requestHeadersValue) {
                errors->setName("requestHeaders");
                result->m_requestHeaders = ValueConversions<protocol::Network::Headers>::fromValue(requestHeadersValue, errors);
            }
            protocol::Value* requestHeadersTextValue = object->get("requestHeadersText");
            if (requestHeadersTextValue) {
                errors->setName("requestHeadersText");
                result->m_requestHeadersText = ValueConversions<String>::fromValue(requestHeadersTextValue, errors);
            }
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> WebSocketResponse::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("status", ValueConversions<double>::toValue(m_status));
            result->setValue("statusText", ValueConversions<String>::toValue(m_statusText));
            result->setValue("headers", ValueConversions<protocol::Network::Headers>::toValue(m_headers.get()));
            if (m_headersText.isJust())
                result->setValue("headersText", ValueConversions<String>::toValue(m_headersText.fromJust()));
            if (m_requestHeaders.isJust())
                result->setValue("requestHeaders", ValueConversions<protocol::Network::Headers>::toValue(m_requestHeaders.fromJust()));
            if (m_requestHeadersText.isJust())
                result->setValue("requestHeadersText", ValueConversions<String>::toValue(m_requestHeadersText.fromJust()));
            return result;
        }

        std::unique_ptr<WebSocketResponse> WebSocketResponse::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<WebSocketFrame> WebSocketFrame::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<WebSocketFrame> result(new WebSocketFrame());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* opcodeValue = object->get("opcode");
            errors->setName("opcode");
            result->m_opcode = ValueConversions<double>::fromValue(opcodeValue, errors);
            protocol::Value* maskValue = object->get("mask");
            errors->setName("mask");
            result->m_mask = ValueConversions<bool>::fromValue(maskValue, errors);
            protocol::Value* payloadDataValue = object->get("payloadData");
            errors->setName("payloadData");
            result->m_payloadData = ValueConversions<String>::fromValue(payloadDataValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> WebSocketFrame::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("opcode", ValueConversions<double>::toValue(m_opcode));
            result->setValue("mask", ValueConversions<bool>::toValue(m_mask));
            result->setValue("payloadData", ValueConversions<String>::toValue(m_payloadData));
            return result;
        }

        std::unique_ptr<WebSocketFrame> WebSocketFrame::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<CachedResource> CachedResource::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<CachedResource> result(new CachedResource());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* urlValue = object->get("url");
            errors->setName("url");
            result->m_url = ValueConversions<String>::fromValue(urlValue, errors);
            protocol::Value* typeValue = object->get("type");
            errors->setName("type");
            result->m_type = ValueConversions<String>::fromValue(typeValue, errors);
            protocol::Value* responseValue = object->get("response");
            if (responseValue) {
                errors->setName("response");
                result->m_response = ValueConversions<protocol::Network::Response>::fromValue(responseValue, errors);
            }
            protocol::Value* bodySizeValue = object->get("bodySize");
            errors->setName("bodySize");
            result->m_bodySize = ValueConversions<double>::fromValue(bodySizeValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> CachedResource::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("url", ValueConversions<String>::toValue(m_url));
            result->setValue("type", ValueConversions<String>::toValue(m_type));
            if (m_response.isJust())
                result->setValue("response", ValueConversions<protocol::Network::Response>::toValue(m_response.fromJust()));
            result->setValue("bodySize", ValueConversions<double>::toValue(m_bodySize));
            return result;
        }

        std::unique_ptr<CachedResource> CachedResource::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        const char* Initiator::TypeEnum::Parser = "parser";
        const char* Initiator::TypeEnum::Script = "script";
        const char* Initiator::TypeEnum::Other = "other";

        std::unique_ptr<Initiator> Initiator::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<Initiator> result(new Initiator());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* typeValue = object->get("type");
            errors->setName("type");
            result->m_type = ValueConversions<String>::fromValue(typeValue, errors);
            protocol::Value* stackValue = object->get("stack");
            if (stackValue) {
                errors->setName("stack");
                result->m_stack = ValueConversions<v8_inspector::protocol::Runtime::API::StackTrace>::fromValue(stackValue, errors);
            }
            protocol::Value* urlValue = object->get("url");
            if (urlValue) {
                errors->setName("url");
                result->m_url = ValueConversions<String>::fromValue(urlValue, errors);
            }
            protocol::Value* lineNumberValue = object->get("lineNumber");
            if (lineNumberValue) {
                errors->setName("lineNumber");
                result->m_lineNumber = ValueConversions<double>::fromValue(lineNumberValue, errors);
            }
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> Initiator::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("type", ValueConversions<String>::toValue(m_type));
            if (m_stack.isJust())
                result->setValue("stack", ValueConversions<v8_inspector::protocol::Runtime::API::StackTrace>::toValue(m_stack.fromJust()));
            if (m_url.isJust())
                result->setValue("url", ValueConversions<String>::toValue(m_url.fromJust()));
            if (m_lineNumber.isJust())
                result->setValue("lineNumber", ValueConversions<double>::toValue(m_lineNumber.fromJust()));
            return result;
        }

        std::unique_ptr<Initiator> Initiator::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

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

        std::unique_ptr<ResourceChangedPriorityNotification> ResourceChangedPriorityNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<ResourceChangedPriorityNotification> result(new ResourceChangedPriorityNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* requestIdValue = object->get("requestId");
            errors->setName("requestId");
            result->m_requestId = ValueConversions<String>::fromValue(requestIdValue, errors);
            protocol::Value* newPriorityValue = object->get("newPriority");
            errors->setName("newPriority");
            result->m_newPriority = ValueConversions<String>::fromValue(newPriorityValue, errors);
            protocol::Value* timestampValue = object->get("timestamp");
            errors->setName("timestamp");
            result->m_timestamp = ValueConversions<double>::fromValue(timestampValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> ResourceChangedPriorityNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("requestId", ValueConversions<String>::toValue(m_requestId));
            result->setValue("newPriority", ValueConversions<String>::toValue(m_newPriority));
            result->setValue("timestamp", ValueConversions<double>::toValue(m_timestamp));
            return result;
        }

        std::unique_ptr<ResourceChangedPriorityNotification> ResourceChangedPriorityNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<RequestWillBeSentNotification> RequestWillBeSentNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<RequestWillBeSentNotification> result(new RequestWillBeSentNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* requestIdValue = object->get("requestId");
            errors->setName("requestId");
            result->m_requestId = ValueConversions<String>::fromValue(requestIdValue, errors);
            protocol::Value* frameIdValue = object->get("frameId");
            errors->setName("frameId");
            result->m_frameId = ValueConversions<String>::fromValue(frameIdValue, errors);
            protocol::Value* loaderIdValue = object->get("loaderId");
            errors->setName("loaderId");
            result->m_loaderId = ValueConversions<String>::fromValue(loaderIdValue, errors);
            protocol::Value* documentURLValue = object->get("documentURL");
            errors->setName("documentURL");
            result->m_documentURL = ValueConversions<String>::fromValue(documentURLValue, errors);
            protocol::Value* requestValue = object->get("request");
            errors->setName("request");
            result->m_request = ValueConversions<protocol::Network::Request>::fromValue(requestValue, errors);
            protocol::Value* timestampValue = object->get("timestamp");
            errors->setName("timestamp");
            result->m_timestamp = ValueConversions<double>::fromValue(timestampValue, errors);
            protocol::Value* wallTimeValue = object->get("wallTime");
            errors->setName("wallTime");
            result->m_wallTime = ValueConversions<double>::fromValue(wallTimeValue, errors);
            protocol::Value* initiatorValue = object->get("initiator");
            errors->setName("initiator");
            result->m_initiator = ValueConversions<protocol::Network::Initiator>::fromValue(initiatorValue, errors);
            protocol::Value* redirectResponseValue = object->get("redirectResponse");
            if (redirectResponseValue) {
                errors->setName("redirectResponse");
                result->m_redirectResponse = ValueConversions<protocol::Network::Response>::fromValue(redirectResponseValue, errors);
            }
            protocol::Value* typeValue = object->get("type");
            if (typeValue) {
                errors->setName("type");
                result->m_type = ValueConversions<String>::fromValue(typeValue, errors);
            }
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> RequestWillBeSentNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("requestId", ValueConversions<String>::toValue(m_requestId));
            result->setValue("frameId", ValueConversions<String>::toValue(m_frameId));
            result->setValue("loaderId", ValueConversions<String>::toValue(m_loaderId));
            result->setValue("documentURL", ValueConversions<String>::toValue(m_documentURL));
            result->setValue("request", ValueConversions<protocol::Network::Request>::toValue(m_request.get()));
            result->setValue("timestamp", ValueConversions<double>::toValue(m_timestamp));
            result->setValue("wallTime", ValueConversions<double>::toValue(m_wallTime));
            result->setValue("initiator", ValueConversions<protocol::Network::Initiator>::toValue(m_initiator.get()));
            if (m_redirectResponse.isJust())
                result->setValue("redirectResponse", ValueConversions<protocol::Network::Response>::toValue(m_redirectResponse.fromJust()));
            if (m_type.isJust())
                result->setValue("type", ValueConversions<String>::toValue(m_type.fromJust()));
            return result;
        }

        std::unique_ptr<RequestWillBeSentNotification> RequestWillBeSentNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<RequestServedFromCacheNotification> RequestServedFromCacheNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<RequestServedFromCacheNotification> result(new RequestServedFromCacheNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* requestIdValue = object->get("requestId");
            errors->setName("requestId");
            result->m_requestId = ValueConversions<String>::fromValue(requestIdValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> RequestServedFromCacheNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("requestId", ValueConversions<String>::toValue(m_requestId));
            return result;
        }

        std::unique_ptr<RequestServedFromCacheNotification> RequestServedFromCacheNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<ResponseReceivedNotification> ResponseReceivedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<ResponseReceivedNotification> result(new ResponseReceivedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* requestIdValue = object->get("requestId");
            errors->setName("requestId");
            result->m_requestId = ValueConversions<String>::fromValue(requestIdValue, errors);
            protocol::Value* frameIdValue = object->get("frameId");
            errors->setName("frameId");
            result->m_frameId = ValueConversions<String>::fromValue(frameIdValue, errors);
            protocol::Value* loaderIdValue = object->get("loaderId");
            errors->setName("loaderId");
            result->m_loaderId = ValueConversions<String>::fromValue(loaderIdValue, errors);
            protocol::Value* timestampValue = object->get("timestamp");
            errors->setName("timestamp");
            result->m_timestamp = ValueConversions<double>::fromValue(timestampValue, errors);
            protocol::Value* typeValue = object->get("type");
            errors->setName("type");
            result->m_type = ValueConversions<String>::fromValue(typeValue, errors);
            protocol::Value* responseValue = object->get("response");
            errors->setName("response");
            result->m_response = ValueConversions<protocol::Network::Response>::fromValue(responseValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> ResponseReceivedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("requestId", ValueConversions<String>::toValue(m_requestId));
            result->setValue("frameId", ValueConversions<String>::toValue(m_frameId));
            result->setValue("loaderId", ValueConversions<String>::toValue(m_loaderId));
            result->setValue("timestamp", ValueConversions<double>::toValue(m_timestamp));
            result->setValue("type", ValueConversions<String>::toValue(m_type));
            result->setValue("response", ValueConversions<protocol::Network::Response>::toValue(m_response.get()));
            return result;
        }

        std::unique_ptr<ResponseReceivedNotification> ResponseReceivedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<DataReceivedNotification> DataReceivedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<DataReceivedNotification> result(new DataReceivedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* requestIdValue = object->get("requestId");
            errors->setName("requestId");
            result->m_requestId = ValueConversions<String>::fromValue(requestIdValue, errors);
            protocol::Value* timestampValue = object->get("timestamp");
            errors->setName("timestamp");
            result->m_timestamp = ValueConversions<double>::fromValue(timestampValue, errors);
            protocol::Value* dataLengthValue = object->get("dataLength");
            errors->setName("dataLength");
            result->m_dataLength = ValueConversions<int>::fromValue(dataLengthValue, errors);
            protocol::Value* encodedDataLengthValue = object->get("encodedDataLength");
            errors->setName("encodedDataLength");
            result->m_encodedDataLength = ValueConversions<int>::fromValue(encodedDataLengthValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> DataReceivedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("requestId", ValueConversions<String>::toValue(m_requestId));
            result->setValue("timestamp", ValueConversions<double>::toValue(m_timestamp));
            result->setValue("dataLength", ValueConversions<int>::toValue(m_dataLength));
            result->setValue("encodedDataLength", ValueConversions<int>::toValue(m_encodedDataLength));
            return result;
        }

        std::unique_ptr<DataReceivedNotification> DataReceivedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<LoadingFinishedNotification> LoadingFinishedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<LoadingFinishedNotification> result(new LoadingFinishedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* requestIdValue = object->get("requestId");
            errors->setName("requestId");
            result->m_requestId = ValueConversions<String>::fromValue(requestIdValue, errors);
            protocol::Value* timestampValue = object->get("timestamp");
            errors->setName("timestamp");
            result->m_timestamp = ValueConversions<double>::fromValue(timestampValue, errors);
            protocol::Value* encodedDataLengthValue = object->get("encodedDataLength");
            errors->setName("encodedDataLength");
            result->m_encodedDataLength = ValueConversions<double>::fromValue(encodedDataLengthValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> LoadingFinishedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("requestId", ValueConversions<String>::toValue(m_requestId));
            result->setValue("timestamp", ValueConversions<double>::toValue(m_timestamp));
            result->setValue("encodedDataLength", ValueConversions<double>::toValue(m_encodedDataLength));
            return result;
        }

        std::unique_ptr<LoadingFinishedNotification> LoadingFinishedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<LoadingFailedNotification> LoadingFailedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<LoadingFailedNotification> result(new LoadingFailedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* requestIdValue = object->get("requestId");
            errors->setName("requestId");
            result->m_requestId = ValueConversions<String>::fromValue(requestIdValue, errors);
            protocol::Value* timestampValue = object->get("timestamp");
            errors->setName("timestamp");
            result->m_timestamp = ValueConversions<double>::fromValue(timestampValue, errors);
            protocol::Value* typeValue = object->get("type");
            errors->setName("type");
            result->m_type = ValueConversions<String>::fromValue(typeValue, errors);
            protocol::Value* errorTextValue = object->get("errorText");
            errors->setName("errorText");
            result->m_errorText = ValueConversions<String>::fromValue(errorTextValue, errors);
            protocol::Value* canceledValue = object->get("canceled");
            if (canceledValue) {
                errors->setName("canceled");
                result->m_canceled = ValueConversions<bool>::fromValue(canceledValue, errors);
            }
            protocol::Value* blockedReasonValue = object->get("blockedReason");
            if (blockedReasonValue) {
                errors->setName("blockedReason");
                result->m_blockedReason = ValueConversions<String>::fromValue(blockedReasonValue, errors);
            }
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> LoadingFailedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("requestId", ValueConversions<String>::toValue(m_requestId));
            result->setValue("timestamp", ValueConversions<double>::toValue(m_timestamp));
            result->setValue("type", ValueConversions<String>::toValue(m_type));
            result->setValue("errorText", ValueConversions<String>::toValue(m_errorText));
            if (m_canceled.isJust())
                result->setValue("canceled", ValueConversions<bool>::toValue(m_canceled.fromJust()));
            if (m_blockedReason.isJust())
                result->setValue("blockedReason", ValueConversions<String>::toValue(m_blockedReason.fromJust()));
            return result;
        }

        std::unique_ptr<LoadingFailedNotification> LoadingFailedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<WebSocketWillSendHandshakeRequestNotification> WebSocketWillSendHandshakeRequestNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<WebSocketWillSendHandshakeRequestNotification> result(new WebSocketWillSendHandshakeRequestNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* requestIdValue = object->get("requestId");
            errors->setName("requestId");
            result->m_requestId = ValueConversions<String>::fromValue(requestIdValue, errors);
            protocol::Value* timestampValue = object->get("timestamp");
            errors->setName("timestamp");
            result->m_timestamp = ValueConversions<double>::fromValue(timestampValue, errors);
            protocol::Value* wallTimeValue = object->get("wallTime");
            errors->setName("wallTime");
            result->m_wallTime = ValueConversions<double>::fromValue(wallTimeValue, errors);
            protocol::Value* requestValue = object->get("request");
            errors->setName("request");
            result->m_request = ValueConversions<protocol::Network::WebSocketRequest>::fromValue(requestValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> WebSocketWillSendHandshakeRequestNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("requestId", ValueConversions<String>::toValue(m_requestId));
            result->setValue("timestamp", ValueConversions<double>::toValue(m_timestamp));
            result->setValue("wallTime", ValueConversions<double>::toValue(m_wallTime));
            result->setValue("request", ValueConversions<protocol::Network::WebSocketRequest>::toValue(m_request.get()));
            return result;
        }

        std::unique_ptr<WebSocketWillSendHandshakeRequestNotification> WebSocketWillSendHandshakeRequestNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<WebSocketHandshakeResponseReceivedNotification> WebSocketHandshakeResponseReceivedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<WebSocketHandshakeResponseReceivedNotification> result(new WebSocketHandshakeResponseReceivedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* requestIdValue = object->get("requestId");
            errors->setName("requestId");
            result->m_requestId = ValueConversions<String>::fromValue(requestIdValue, errors);
            protocol::Value* timestampValue = object->get("timestamp");
            errors->setName("timestamp");
            result->m_timestamp = ValueConversions<double>::fromValue(timestampValue, errors);
            protocol::Value* responseValue = object->get("response");
            errors->setName("response");
            result->m_response = ValueConversions<protocol::Network::WebSocketResponse>::fromValue(responseValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> WebSocketHandshakeResponseReceivedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("requestId", ValueConversions<String>::toValue(m_requestId));
            result->setValue("timestamp", ValueConversions<double>::toValue(m_timestamp));
            result->setValue("response", ValueConversions<protocol::Network::WebSocketResponse>::toValue(m_response.get()));
            return result;
        }

        std::unique_ptr<WebSocketHandshakeResponseReceivedNotification> WebSocketHandshakeResponseReceivedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<WebSocketCreatedNotification> WebSocketCreatedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<WebSocketCreatedNotification> result(new WebSocketCreatedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* requestIdValue = object->get("requestId");
            errors->setName("requestId");
            result->m_requestId = ValueConversions<String>::fromValue(requestIdValue, errors);
            protocol::Value* urlValue = object->get("url");
            errors->setName("url");
            result->m_url = ValueConversions<String>::fromValue(urlValue, errors);
            protocol::Value* initiatorValue = object->get("initiator");
            if (initiatorValue) {
                errors->setName("initiator");
                result->m_initiator = ValueConversions<protocol::Network::Initiator>::fromValue(initiatorValue, errors);
            }
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> WebSocketCreatedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("requestId", ValueConversions<String>::toValue(m_requestId));
            result->setValue("url", ValueConversions<String>::toValue(m_url));
            if (m_initiator.isJust())
                result->setValue("initiator", ValueConversions<protocol::Network::Initiator>::toValue(m_initiator.fromJust()));
            return result;
        }

        std::unique_ptr<WebSocketCreatedNotification> WebSocketCreatedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<WebSocketClosedNotification> WebSocketClosedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<WebSocketClosedNotification> result(new WebSocketClosedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* requestIdValue = object->get("requestId");
            errors->setName("requestId");
            result->m_requestId = ValueConversions<String>::fromValue(requestIdValue, errors);
            protocol::Value* timestampValue = object->get("timestamp");
            errors->setName("timestamp");
            result->m_timestamp = ValueConversions<double>::fromValue(timestampValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> WebSocketClosedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("requestId", ValueConversions<String>::toValue(m_requestId));
            result->setValue("timestamp", ValueConversions<double>::toValue(m_timestamp));
            return result;
        }

        std::unique_ptr<WebSocketClosedNotification> WebSocketClosedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<WebSocketFrameReceivedNotification> WebSocketFrameReceivedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<WebSocketFrameReceivedNotification> result(new WebSocketFrameReceivedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* requestIdValue = object->get("requestId");
            errors->setName("requestId");
            result->m_requestId = ValueConversions<String>::fromValue(requestIdValue, errors);
            protocol::Value* timestampValue = object->get("timestamp");
            errors->setName("timestamp");
            result->m_timestamp = ValueConversions<double>::fromValue(timestampValue, errors);
            protocol::Value* responseValue = object->get("response");
            errors->setName("response");
            result->m_response = ValueConversions<protocol::Network::WebSocketFrame>::fromValue(responseValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> WebSocketFrameReceivedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("requestId", ValueConversions<String>::toValue(m_requestId));
            result->setValue("timestamp", ValueConversions<double>::toValue(m_timestamp));
            result->setValue("response", ValueConversions<protocol::Network::WebSocketFrame>::toValue(m_response.get()));
            return result;
        }

        std::unique_ptr<WebSocketFrameReceivedNotification> WebSocketFrameReceivedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<WebSocketFrameErrorNotification> WebSocketFrameErrorNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<WebSocketFrameErrorNotification> result(new WebSocketFrameErrorNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* requestIdValue = object->get("requestId");
            errors->setName("requestId");
            result->m_requestId = ValueConversions<String>::fromValue(requestIdValue, errors);
            protocol::Value* timestampValue = object->get("timestamp");
            errors->setName("timestamp");
            result->m_timestamp = ValueConversions<double>::fromValue(timestampValue, errors);
            protocol::Value* errorMessageValue = object->get("errorMessage");
            errors->setName("errorMessage");
            result->m_errorMessage = ValueConversions<String>::fromValue(errorMessageValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> WebSocketFrameErrorNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("requestId", ValueConversions<String>::toValue(m_requestId));
            result->setValue("timestamp", ValueConversions<double>::toValue(m_timestamp));
            result->setValue("errorMessage", ValueConversions<String>::toValue(m_errorMessage));
            return result;
        }

        std::unique_ptr<WebSocketFrameErrorNotification> WebSocketFrameErrorNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<WebSocketFrameSentNotification> WebSocketFrameSentNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<WebSocketFrameSentNotification> result(new WebSocketFrameSentNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* requestIdValue = object->get("requestId");
            errors->setName("requestId");
            result->m_requestId = ValueConversions<String>::fromValue(requestIdValue, errors);
            protocol::Value* timestampValue = object->get("timestamp");
            errors->setName("timestamp");
            result->m_timestamp = ValueConversions<double>::fromValue(timestampValue, errors);
            protocol::Value* responseValue = object->get("response");
            errors->setName("response");
            result->m_response = ValueConversions<protocol::Network::WebSocketFrame>::fromValue(responseValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> WebSocketFrameSentNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("requestId", ValueConversions<String>::toValue(m_requestId));
            result->setValue("timestamp", ValueConversions<double>::toValue(m_timestamp));
            result->setValue("response", ValueConversions<protocol::Network::WebSocketFrame>::toValue(m_response.get()));
            return result;
        }

        std::unique_ptr<WebSocketFrameSentNotification> WebSocketFrameSentNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        std::unique_ptr<EventSourceMessageReceivedNotification> EventSourceMessageReceivedNotification::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<EventSourceMessageReceivedNotification> result(new EventSourceMessageReceivedNotification());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* requestIdValue = object->get("requestId");
            errors->setName("requestId");
            result->m_requestId = ValueConversions<String>::fromValue(requestIdValue, errors);
            protocol::Value* timestampValue = object->get("timestamp");
            errors->setName("timestamp");
            result->m_timestamp = ValueConversions<double>::fromValue(timestampValue, errors);
            protocol::Value* eventNameValue = object->get("eventName");
            errors->setName("eventName");
            result->m_eventName = ValueConversions<String>::fromValue(eventNameValue, errors);
            protocol::Value* eventIdValue = object->get("eventId");
            errors->setName("eventId");
            result->m_eventId = ValueConversions<String>::fromValue(eventIdValue, errors);
            protocol::Value* dataValue = object->get("data");
            errors->setName("data");
            result->m_data = ValueConversions<String>::fromValue(dataValue, errors);
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> EventSourceMessageReceivedNotification::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("requestId", ValueConversions<String>::toValue(m_requestId));
            result->setValue("timestamp", ValueConversions<double>::toValue(m_timestamp));
            result->setValue("eventName", ValueConversions<String>::toValue(m_eventName));
            result->setValue("eventId", ValueConversions<String>::toValue(m_eventId));
            result->setValue("data", ValueConversions<String>::toValue(m_data));
            return result;
        }

        std::unique_ptr<EventSourceMessageReceivedNotification> EventSourceMessageReceivedNotification::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        // ------------- Enum values from params.

        // ------------- Frontend notifications.

        void Frontend::resourceChangedPriority(const String& requestId, const String& newPriority, double timestamp)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<ResourceChangedPriorityNotification> messageData = ResourceChangedPriorityNotification::create()
                                                                                   .setRequestId(requestId)
                                                                                   .setNewPriority(newPriority)
                                                                                   .setTimestamp(timestamp)
                                                                                   .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("Network.resourceChangedPriority", std::move(messageData)));
        }

        void Frontend::requestWillBeSent(const String& requestId, const String& frameId, const String& loaderId, const String& documentURL, std::unique_ptr<protocol::Network::Request> request, double timestamp, double wallTime, std::unique_ptr<protocol::Network::Initiator> initiator, Maybe<protocol::Network::Response> redirectResponse, Maybe<String> type)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<RequestWillBeSentNotification> messageData = RequestWillBeSentNotification::create()
                                                                             .setRequestId(requestId)
                                                                             .setFrameId(frameId)
                                                                             .setLoaderId(loaderId)
                                                                             .setDocumentURL(documentURL)
                                                                             .setRequest(std::move(request))
                                                                             .setTimestamp(timestamp)
                                                                             .setWallTime(wallTime)
                                                                             .setInitiator(std::move(initiator))
                                                                             .build();
            if (redirectResponse.isJust())
                messageData->setRedirectResponse(std::move(redirectResponse).takeJust());
            if (type.isJust())
                messageData->setType(std::move(type).takeJust());
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("Network.requestWillBeSent", std::move(messageData)));
        }

        void Frontend::requestServedFromCache(const String& requestId)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<RequestServedFromCacheNotification> messageData = RequestServedFromCacheNotification::create()
                                                                                  .setRequestId(requestId)
                                                                                  .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("Network.requestServedFromCache", std::move(messageData)));
        }

        void Frontend::responseReceived(const String& requestId, const String& frameId, const String& loaderId, double timestamp, const String& type, std::unique_ptr<protocol::Network::Response> response)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<ResponseReceivedNotification> messageData = ResponseReceivedNotification::create()
                                                                            .setRequestId(requestId)
                                                                            .setFrameId(frameId)
                                                                            .setLoaderId(loaderId)
                                                                            .setTimestamp(timestamp)
                                                                            .setType(type)
                                                                            .setResponse(std::move(response))
                                                                            .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("Network.responseReceived", std::move(messageData)));
        }

        void Frontend::dataReceived(const String& requestId, double timestamp, int dataLength, int encodedDataLength)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<DataReceivedNotification> messageData = DataReceivedNotification::create()
                                                                        .setRequestId(requestId)
                                                                        .setTimestamp(timestamp)
                                                                        .setDataLength(dataLength)
                                                                        .setEncodedDataLength(encodedDataLength)
                                                                        .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("Network.dataReceived", std::move(messageData)));
        }

        void Frontend::loadingFinished(const String& requestId, double timestamp, double encodedDataLength)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<LoadingFinishedNotification> messageData = LoadingFinishedNotification::create()
                                                                           .setRequestId(requestId)
                                                                           .setTimestamp(timestamp)
                                                                           .setEncodedDataLength(encodedDataLength)
                                                                           .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("Network.loadingFinished", std::move(messageData)));
        }

        void Frontend::loadingFailed(const String& requestId, double timestamp, const String& type, const String& errorText, Maybe<bool> canceled, Maybe<String> blockedReason)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<LoadingFailedNotification> messageData = LoadingFailedNotification::create()
                                                                         .setRequestId(requestId)
                                                                         .setTimestamp(timestamp)
                                                                         .setType(type)
                                                                         .setErrorText(errorText)
                                                                         .build();
            if (canceled.isJust())
                messageData->setCanceled(std::move(canceled).takeJust());
            if (blockedReason.isJust())
                messageData->setBlockedReason(std::move(blockedReason).takeJust());
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("Network.loadingFailed", std::move(messageData)));
        }

        void Frontend::webSocketWillSendHandshakeRequest(const String& requestId, double timestamp, double wallTime, std::unique_ptr<protocol::Network::WebSocketRequest> request)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<WebSocketWillSendHandshakeRequestNotification> messageData = WebSocketWillSendHandshakeRequestNotification::create()
                                                                                             .setRequestId(requestId)
                                                                                             .setTimestamp(timestamp)
                                                                                             .setWallTime(wallTime)
                                                                                             .setRequest(std::move(request))
                                                                                             .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("Network.webSocketWillSendHandshakeRequest", std::move(messageData)));
        }

        void Frontend::webSocketHandshakeResponseReceived(const String& requestId, double timestamp, std::unique_ptr<protocol::Network::WebSocketResponse> response)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<WebSocketHandshakeResponseReceivedNotification> messageData = WebSocketHandshakeResponseReceivedNotification::create()
                                                                                              .setRequestId(requestId)
                                                                                              .setTimestamp(timestamp)
                                                                                              .setResponse(std::move(response))
                                                                                              .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("Network.webSocketHandshakeResponseReceived", std::move(messageData)));
        }

        void Frontend::webSocketCreated(const String& requestId, const String& url, Maybe<protocol::Network::Initiator> initiator)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<WebSocketCreatedNotification> messageData = WebSocketCreatedNotification::create()
                                                                            .setRequestId(requestId)
                                                                            .setUrl(url)
                                                                            .build();
            if (initiator.isJust())
                messageData->setInitiator(std::move(initiator).takeJust());
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("Network.webSocketCreated", std::move(messageData)));
        }

        void Frontend::webSocketClosed(const String& requestId, double timestamp)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<WebSocketClosedNotification> messageData = WebSocketClosedNotification::create()
                                                                           .setRequestId(requestId)
                                                                           .setTimestamp(timestamp)
                                                                           .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("Network.webSocketClosed", std::move(messageData)));
        }

        void Frontend::webSocketFrameReceived(const String& requestId, double timestamp, std::unique_ptr<protocol::Network::WebSocketFrame> response)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<WebSocketFrameReceivedNotification> messageData = WebSocketFrameReceivedNotification::create()
                                                                                  .setRequestId(requestId)
                                                                                  .setTimestamp(timestamp)
                                                                                  .setResponse(std::move(response))
                                                                                  .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("Network.webSocketFrameReceived", std::move(messageData)));
        }

        void Frontend::webSocketFrameError(const String& requestId, double timestamp, const String& errorMessage)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<WebSocketFrameErrorNotification> messageData = WebSocketFrameErrorNotification::create()
                                                                               .setRequestId(requestId)
                                                                               .setTimestamp(timestamp)
                                                                               .setErrorMessage(errorMessage)
                                                                               .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("Network.webSocketFrameError", std::move(messageData)));
        }

        void Frontend::webSocketFrameSent(const String& requestId, double timestamp, std::unique_ptr<protocol::Network::WebSocketFrame> response)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<WebSocketFrameSentNotification> messageData = WebSocketFrameSentNotification::create()
                                                                              .setRequestId(requestId)
                                                                              .setTimestamp(timestamp)
                                                                              .setResponse(std::move(response))
                                                                              .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("Network.webSocketFrameSent", std::move(messageData)));
        }

        void Frontend::eventSourceMessageReceived(const String& requestId, double timestamp, const String& eventName, const String& eventId, const String& data)
        {
            if (!m_frontendChannel)
                return;
            std::unique_ptr<EventSourceMessageReceivedNotification> messageData = EventSourceMessageReceivedNotification::create()
                                                                                      .setRequestId(requestId)
                                                                                      .setTimestamp(timestamp)
                                                                                      .setEventName(eventName)
                                                                                      .setEventId(eventId)
                                                                                      .setData(data)
                                                                                      .build();
            m_frontendChannel->sendProtocolNotification(InternalResponse::createNotification("Network.eventSourceMessageReceived", std::move(messageData)));
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
                m_dispatchMap["Network.enable"] = &DispatcherImpl::enable;
                m_dispatchMap["Network.disable"] = &DispatcherImpl::disable;
                m_dispatchMap["Network.setUserAgentOverride"] = &DispatcherImpl::setUserAgentOverride;
                m_dispatchMap["Network.setExtraHTTPHeaders"] = &DispatcherImpl::setExtraHTTPHeaders;
                m_dispatchMap["Network.getResponseBody"] = &DispatcherImpl::getResponseBody;
                m_dispatchMap["Network.addBlockedURL"] = &DispatcherImpl::addBlockedURL;
                m_dispatchMap["Network.removeBlockedURL"] = &DispatcherImpl::removeBlockedURL;
                m_dispatchMap["Network.replayXHR"] = &DispatcherImpl::replayXHR;
                m_dispatchMap["Network.setMonitoringXHREnabled"] = &DispatcherImpl::setMonitoringXHREnabled;
                m_dispatchMap["Network.canClearBrowserCache"] = &DispatcherImpl::canClearBrowserCache;
                m_dispatchMap["Network.canClearBrowserCookies"] = &DispatcherImpl::canClearBrowserCookies;
                m_dispatchMap["Network.emulateNetworkConditions"] = &DispatcherImpl::emulateNetworkConditions;
                m_dispatchMap["Network.setCacheDisabled"] = &DispatcherImpl::setCacheDisabled;
                m_dispatchMap["Network.setBypassServiceWorker"] = &DispatcherImpl::setBypassServiceWorker;
                m_dispatchMap["Network.setDataSizeLimitsForTest"] = &DispatcherImpl::setDataSizeLimitsForTest;
                m_dispatchMap["Network.getCertificate"] = &DispatcherImpl::getCertificate;
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
            DispatchResponse::Status setExtraHTTPHeaders(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status getResponseBody(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status addBlockedURL(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status removeBlockedURL(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status replayXHR(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status setMonitoringXHREnabled(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status canClearBrowserCache(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status canClearBrowserCookies(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status emulateNetworkConditions(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status setCacheDisabled(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status setBypassServiceWorker(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status setDataSizeLimitsForTest(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status getCertificate(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);

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
            DispatchResponse response = m_backend->enable(std::move(in_maxTotalBufferSize), std::move(in_maxResourceBufferSize));
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
            DispatchResponse response = m_backend->setUserAgentOverride(in_userAgent);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::setExtraHTTPHeaders(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* headersValue = object ? object->get("headers") : nullptr;
            errors->setName("headers");
            std::unique_ptr<protocol::Network::Headers> in_headers = ValueConversions<protocol::Network::Headers>::fromValue(headersValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->setExtraHTTPHeaders(std::move(in_headers));
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        class GetResponseBodyCallbackImpl : public Backend::GetResponseBodyCallback, public DispatcherBase::Callback {
        public:
            GetResponseBodyCallbackImpl(std::unique_ptr<DispatcherBase::WeakPtr> backendImpl, int callId, int callbackId)
                : DispatcherBase::Callback(std::move(backendImpl), callId, callbackId)
            {
            }

            void sendSuccess(const String& body, bool base64Encoded) override
            {
                std::unique_ptr<protocol::DictionaryValue> resultObject = DictionaryValue::create();
                resultObject->setValue("body", ValueConversions<String>::toValue(body));
                resultObject->setValue("base64Encoded", ValueConversions<bool>::toValue(base64Encoded));
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

        DispatchResponse::Status DispatcherImpl::getResponseBody(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* requestIdValue = object ? object->get("requestId") : nullptr;
            errors->setName("requestId");
            String in_requestId = ValueConversions<String>::fromValue(requestIdValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            std::unique_ptr<GetResponseBodyCallbackImpl> callback(new GetResponseBodyCallbackImpl(weakPtr(), callId, nextCallbackId()));
            m_backend->getResponseBody(in_requestId, std::move(callback));
            return (weak->get() && weak->get()->lastCallbackFallThrough()) ? DispatchResponse::kFallThrough : DispatchResponse::kAsync;
        }

        DispatchResponse::Status DispatcherImpl::addBlockedURL(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* urlValue = object ? object->get("url") : nullptr;
            errors->setName("url");
            String in_url = ValueConversions<String>::fromValue(urlValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->addBlockedURL(in_url);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::removeBlockedURL(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* urlValue = object ? object->get("url") : nullptr;
            errors->setName("url");
            String in_url = ValueConversions<String>::fromValue(urlValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->removeBlockedURL(in_url);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::replayXHR(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* requestIdValue = object ? object->get("requestId") : nullptr;
            errors->setName("requestId");
            String in_requestId = ValueConversions<String>::fromValue(requestIdValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->replayXHR(in_requestId);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::setMonitoringXHREnabled(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* enabledValue = object ? object->get("enabled") : nullptr;
            errors->setName("enabled");
            bool in_enabled = ValueConversions<bool>::fromValue(enabledValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->setMonitoringXHREnabled(in_enabled);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::canClearBrowserCache(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Declare output parameters.
            bool out_result;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->canClearBrowserCache(&out_result);
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

        DispatchResponse::Status DispatcherImpl::canClearBrowserCookies(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Declare output parameters.
            bool out_result;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->canClearBrowserCookies(&out_result);
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

        DispatchResponse::Status DispatcherImpl::emulateNetworkConditions(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* offlineValue = object ? object->get("offline") : nullptr;
            errors->setName("offline");
            bool in_offline = ValueConversions<bool>::fromValue(offlineValue, errors);
            protocol::Value* latencyValue = object ? object->get("latency") : nullptr;
            errors->setName("latency");
            double in_latency = ValueConversions<double>::fromValue(latencyValue, errors);
            protocol::Value* downloadThroughputValue = object ? object->get("downloadThroughput") : nullptr;
            errors->setName("downloadThroughput");
            double in_downloadThroughput = ValueConversions<double>::fromValue(downloadThroughputValue, errors);
            protocol::Value* uploadThroughputValue = object ? object->get("uploadThroughput") : nullptr;
            errors->setName("uploadThroughput");
            double in_uploadThroughput = ValueConversions<double>::fromValue(uploadThroughputValue, errors);
            protocol::Value* connectionTypeValue = object ? object->get("connectionType") : nullptr;
            Maybe<String> in_connectionType;
            if (connectionTypeValue) {
                errors->setName("connectionType");
                in_connectionType = ValueConversions<String>::fromValue(connectionTypeValue, errors);
            }
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->emulateNetworkConditions(in_offline, in_latency, in_downloadThroughput, in_uploadThroughput, std::move(in_connectionType));
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::setCacheDisabled(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* cacheDisabledValue = object ? object->get("cacheDisabled") : nullptr;
            errors->setName("cacheDisabled");
            bool in_cacheDisabled = ValueConversions<bool>::fromValue(cacheDisabledValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->setCacheDisabled(in_cacheDisabled);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::setBypassServiceWorker(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* bypassValue = object ? object->get("bypass") : nullptr;
            errors->setName("bypass");
            bool in_bypass = ValueConversions<bool>::fromValue(bypassValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->setBypassServiceWorker(in_bypass);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::setDataSizeLimitsForTest(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* maxTotalSizeValue = object ? object->get("maxTotalSize") : nullptr;
            errors->setName("maxTotalSize");
            int in_maxTotalSize = ValueConversions<int>::fromValue(maxTotalSizeValue, errors);
            protocol::Value* maxResourceSizeValue = object ? object->get("maxResourceSize") : nullptr;
            errors->setName("maxResourceSize");
            int in_maxResourceSize = ValueConversions<int>::fromValue(maxResourceSizeValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->setDataSizeLimitsForTest(in_maxTotalSize, in_maxResourceSize);
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        DispatchResponse::Status DispatcherImpl::getCertificate(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* originValue = object ? object->get("origin") : nullptr;
            errors->setName("origin");
            String in_origin = ValueConversions<String>::fromValue(originValue, errors);
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }
            // Declare output parameters.
            std::unique_ptr<protocol::Array<String>> out_tableNames;

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->getCertificate(in_origin, &out_tableNames);
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

        // static
        void Dispatcher::wire(UberDispatcher* uber, Backend* backend)
        {
            std::unique_ptr<DispatcherImpl> dispatcher(new DispatcherImpl(uber->channel(), backend, uber->fallThroughForNotFound()));
            uber->setupRedirects(dispatcher->redirects());
            uber->registerBackend("Network", std::move(dispatcher));
        }

    } // Network
} // namespace blink
} // namespace protocol
