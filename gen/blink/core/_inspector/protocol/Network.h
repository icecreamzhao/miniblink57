// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef blink_protocol_Network_h
#define blink_protocol_Network_h

#include "core/CoreExport.h"
#include "core/inspector/protocol/Protocol.h"
// For each imported domain we generate a ValueConversions struct instead of a full domain definition
// and include Domain::API version from there.
#include "core/inspector/protocol/Runtime.h"
#include "core/inspector/protocol/Security.h"

namespace blink {
namespace protocol {
    namespace Network {

        // ------------- Forward and enum declarations.
        // Unique loader identifier.
        using LoaderId = String;
        // Unique request identifier.
        using RequestId = String;
        // Number of seconds since epoch.
        using Timestamp = double;
        // Request / response headers as keys / values of JSON object.
        using Headers = Object;
        // Loading priority of a resource request.
        using ConnectionType = String;
        // Represents the cookie's 'SameSite' status: https://tools.ietf.org/html/draft-west-first-party-cookies
        using CookieSameSite = String;
        // Timing information for the request.
        class ResourceTiming;
        // Loading priority of a resource request.
        using ResourcePriority = String;
        // HTTP request data.
        class Request;
        // Details of a signed certificate timestamp (SCT).
        class SignedCertificateTimestamp;
        // Security details about a request.
        class SecurityDetails;
        // The reason why request was blocked.
        using BlockedReason = String;
        // HTTP response data.
        class Response;
        // WebSocket request data.
        class WebSocketRequest;
        // WebSocket response data.
        class WebSocketResponse;
        // WebSocket frame data.
        class WebSocketFrame;
        // Information about the cached resource.
        class CachedResource;
        // Information about the request initiator.
        class Initiator;
        // Cookie object
        class Cookie;
        // Wrapper for notification params
        class ResourceChangedPriorityNotification;
        // Wrapper for notification params
        class RequestWillBeSentNotification;
        // Wrapper for notification params
        class RequestServedFromCacheNotification;
        // Wrapper for notification params
        class ResponseReceivedNotification;
        // Wrapper for notification params
        class DataReceivedNotification;
        // Wrapper for notification params
        class LoadingFinishedNotification;
        // Wrapper for notification params
        class LoadingFailedNotification;
        // Wrapper for notification params
        class WebSocketWillSendHandshakeRequestNotification;
        // Wrapper for notification params
        class WebSocketHandshakeResponseReceivedNotification;
        // Wrapper for notification params
        class WebSocketCreatedNotification;
        // Wrapper for notification params
        class WebSocketClosedNotification;
        // Wrapper for notification params
        class WebSocketFrameReceivedNotification;
        // Wrapper for notification params
        class WebSocketFrameErrorNotification;
        // Wrapper for notification params
        class WebSocketFrameSentNotification;
        // Wrapper for notification params
        class EventSourceMessageReceivedNotification;

        namespace ConnectionTypeEnum {
            CORE_EXPORT extern const char* None;
            CORE_EXPORT extern const char* Cellular2g;
            CORE_EXPORT extern const char* Cellular3g;
            CORE_EXPORT extern const char* Cellular4g;
            CORE_EXPORT extern const char* Bluetooth;
            CORE_EXPORT extern const char* Ethernet;
            CORE_EXPORT extern const char* Wifi;
            CORE_EXPORT extern const char* Wimax;
            CORE_EXPORT extern const char* Other;
        } // namespace ConnectionTypeEnum

        namespace CookieSameSiteEnum {
            CORE_EXPORT extern const char* Strict;
            CORE_EXPORT extern const char* Lax;
        } // namespace CookieSameSiteEnum

        namespace ResourcePriorityEnum {
            CORE_EXPORT extern const char* VeryLow;
            CORE_EXPORT extern const char* Low;
            CORE_EXPORT extern const char* Medium;
            CORE_EXPORT extern const char* High;
            CORE_EXPORT extern const char* VeryHigh;
        } // namespace ResourcePriorityEnum

        namespace BlockedReasonEnum {
            CORE_EXPORT extern const char* Csp;
            CORE_EXPORT extern const char* MixedContent;
            CORE_EXPORT extern const char* Origin;
            CORE_EXPORT extern const char* Inspector;
            CORE_EXPORT extern const char* SubresourceFilter;
            CORE_EXPORT extern const char* Other;
        } // namespace BlockedReasonEnum

        // ------------- Type and builder declarations.

        // Timing information for the request.
        class CORE_EXPORT ResourceTiming : public Serializable {
            PROTOCOL_DISALLOW_COPY(ResourceTiming);

        public:
            static std::unique_ptr<ResourceTiming> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~ResourceTiming() override { }

            double getRequestTime() { return m_requestTime; }
            void setRequestTime(double value) { m_requestTime = value; }

            double getProxyStart() { return m_proxyStart; }
            void setProxyStart(double value) { m_proxyStart = value; }

            double getProxyEnd() { return m_proxyEnd; }
            void setProxyEnd(double value) { m_proxyEnd = value; }

            double getDnsStart() { return m_dnsStart; }
            void setDnsStart(double value) { m_dnsStart = value; }

            double getDnsEnd() { return m_dnsEnd; }
            void setDnsEnd(double value) { m_dnsEnd = value; }

            double getConnectStart() { return m_connectStart; }
            void setConnectStart(double value) { m_connectStart = value; }

            double getConnectEnd() { return m_connectEnd; }
            void setConnectEnd(double value) { m_connectEnd = value; }

            double getSslStart() { return m_sslStart; }
            void setSslStart(double value) { m_sslStart = value; }

            double getSslEnd() { return m_sslEnd; }
            void setSslEnd(double value) { m_sslEnd = value; }

            double getWorkerStart() { return m_workerStart; }
            void setWorkerStart(double value) { m_workerStart = value; }

            double getWorkerReady() { return m_workerReady; }
            void setWorkerReady(double value) { m_workerReady = value; }

            double getSendStart() { return m_sendStart; }
            void setSendStart(double value) { m_sendStart = value; }

            double getSendEnd() { return m_sendEnd; }
            void setSendEnd(double value) { m_sendEnd = value; }

            double getPushStart() { return m_pushStart; }
            void setPushStart(double value) { m_pushStart = value; }

            double getPushEnd() { return m_pushEnd; }
            void setPushEnd(double value) { m_pushEnd = value; }

            double getReceiveHeadersEnd() { return m_receiveHeadersEnd; }
            void setReceiveHeadersEnd(double value) { m_receiveHeadersEnd = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<ResourceTiming> clone() const;

            template <int STATE>
            class ResourceTimingBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    RequestTimeSet = 1 << 1,
                    ProxyStartSet = 1 << 2,
                    ProxyEndSet = 1 << 3,
                    DnsStartSet = 1 << 4,
                    DnsEndSet = 1 << 5,
                    ConnectStartSet = 1 << 6,
                    ConnectEndSet = 1 << 7,
                    SslStartSet = 1 << 8,
                    SslEndSet = 1 << 9,
                    WorkerStartSet = 1 << 10,
                    WorkerReadySet = 1 << 11,
                    SendStartSet = 1 << 12,
                    SendEndSet = 1 << 13,
                    PushStartSet = 1 << 14,
                    PushEndSet = 1 << 15,
                    ReceiveHeadersEndSet = 1 << 16,
                    AllFieldsSet = (RequestTimeSet | ProxyStartSet | ProxyEndSet | DnsStartSet | DnsEndSet | ConnectStartSet | ConnectEndSet | SslStartSet | SslEndSet | WorkerStartSet | WorkerReadySet | SendStartSet | SendEndSet | PushStartSet | PushEndSet | ReceiveHeadersEndSet | 0)
                };

                ResourceTimingBuilder<STATE | RequestTimeSet>& setRequestTime(double value)
                {
                    static_assert(!(STATE & RequestTimeSet), "property requestTime should not be set yet");
                    m_result->setRequestTime(value);
                    return castState<RequestTimeSet>();
                }

                ResourceTimingBuilder<STATE | ProxyStartSet>& setProxyStart(double value)
                {
                    static_assert(!(STATE & ProxyStartSet), "property proxyStart should not be set yet");
                    m_result->setProxyStart(value);
                    return castState<ProxyStartSet>();
                }

                ResourceTimingBuilder<STATE | ProxyEndSet>& setProxyEnd(double value)
                {
                    static_assert(!(STATE & ProxyEndSet), "property proxyEnd should not be set yet");
                    m_result->setProxyEnd(value);
                    return castState<ProxyEndSet>();
                }

                ResourceTimingBuilder<STATE | DnsStartSet>& setDnsStart(double value)
                {
                    static_assert(!(STATE & DnsStartSet), "property dnsStart should not be set yet");
                    m_result->setDnsStart(value);
                    return castState<DnsStartSet>();
                }

                ResourceTimingBuilder<STATE | DnsEndSet>& setDnsEnd(double value)
                {
                    static_assert(!(STATE & DnsEndSet), "property dnsEnd should not be set yet");
                    m_result->setDnsEnd(value);
                    return castState<DnsEndSet>();
                }

                ResourceTimingBuilder<STATE | ConnectStartSet>& setConnectStart(double value)
                {
                    static_assert(!(STATE & ConnectStartSet), "property connectStart should not be set yet");
                    m_result->setConnectStart(value);
                    return castState<ConnectStartSet>();
                }

                ResourceTimingBuilder<STATE | ConnectEndSet>& setConnectEnd(double value)
                {
                    static_assert(!(STATE & ConnectEndSet), "property connectEnd should not be set yet");
                    m_result->setConnectEnd(value);
                    return castState<ConnectEndSet>();
                }

                ResourceTimingBuilder<STATE | SslStartSet>& setSslStart(double value)
                {
                    static_assert(!(STATE & SslStartSet), "property sslStart should not be set yet");
                    m_result->setSslStart(value);
                    return castState<SslStartSet>();
                }

                ResourceTimingBuilder<STATE | SslEndSet>& setSslEnd(double value)
                {
                    static_assert(!(STATE & SslEndSet), "property sslEnd should not be set yet");
                    m_result->setSslEnd(value);
                    return castState<SslEndSet>();
                }

                ResourceTimingBuilder<STATE | WorkerStartSet>& setWorkerStart(double value)
                {
                    static_assert(!(STATE & WorkerStartSet), "property workerStart should not be set yet");
                    m_result->setWorkerStart(value);
                    return castState<WorkerStartSet>();
                }

                ResourceTimingBuilder<STATE | WorkerReadySet>& setWorkerReady(double value)
                {
                    static_assert(!(STATE & WorkerReadySet), "property workerReady should not be set yet");
                    m_result->setWorkerReady(value);
                    return castState<WorkerReadySet>();
                }

                ResourceTimingBuilder<STATE | SendStartSet>& setSendStart(double value)
                {
                    static_assert(!(STATE & SendStartSet), "property sendStart should not be set yet");
                    m_result->setSendStart(value);
                    return castState<SendStartSet>();
                }

                ResourceTimingBuilder<STATE | SendEndSet>& setSendEnd(double value)
                {
                    static_assert(!(STATE & SendEndSet), "property sendEnd should not be set yet");
                    m_result->setSendEnd(value);
                    return castState<SendEndSet>();
                }

                ResourceTimingBuilder<STATE | PushStartSet>& setPushStart(double value)
                {
                    static_assert(!(STATE & PushStartSet), "property pushStart should not be set yet");
                    m_result->setPushStart(value);
                    return castState<PushStartSet>();
                }

                ResourceTimingBuilder<STATE | PushEndSet>& setPushEnd(double value)
                {
                    static_assert(!(STATE & PushEndSet), "property pushEnd should not be set yet");
                    m_result->setPushEnd(value);
                    return castState<PushEndSet>();
                }

                ResourceTimingBuilder<STATE | ReceiveHeadersEndSet>& setReceiveHeadersEnd(double value)
                {
                    static_assert(!(STATE & ReceiveHeadersEndSet), "property receiveHeadersEnd should not be set yet");
                    m_result->setReceiveHeadersEnd(value);
                    return castState<ReceiveHeadersEndSet>();
                }

                std::unique_ptr<ResourceTiming> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class ResourceTiming;
                ResourceTimingBuilder()
                    : m_result(new ResourceTiming())
                {
                }

                template <int STEP>
                ResourceTimingBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<ResourceTimingBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Network::ResourceTiming> m_result;
            };

            static ResourceTimingBuilder<0> create()
            {
                return ResourceTimingBuilder<0>();
            }

        private:
            ResourceTiming()
            {
                m_requestTime = 0;
                m_proxyStart = 0;
                m_proxyEnd = 0;
                m_dnsStart = 0;
                m_dnsEnd = 0;
                m_connectStart = 0;
                m_connectEnd = 0;
                m_sslStart = 0;
                m_sslEnd = 0;
                m_workerStart = 0;
                m_workerReady = 0;
                m_sendStart = 0;
                m_sendEnd = 0;
                m_pushStart = 0;
                m_pushEnd = 0;
                m_receiveHeadersEnd = 0;
            }

            double m_requestTime;
            double m_proxyStart;
            double m_proxyEnd;
            double m_dnsStart;
            double m_dnsEnd;
            double m_connectStart;
            double m_connectEnd;
            double m_sslStart;
            double m_sslEnd;
            double m_workerStart;
            double m_workerReady;
            double m_sendStart;
            double m_sendEnd;
            double m_pushStart;
            double m_pushEnd;
            double m_receiveHeadersEnd;
        };

        // HTTP request data.
        class CORE_EXPORT Request : public Serializable {
            PROTOCOL_DISALLOW_COPY(Request);

        public:
            static std::unique_ptr<Request> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~Request() override { }

            String getUrl() { return m_url; }
            void setUrl(const String& value) { m_url = value; }

            String getMethod() { return m_method; }
            void setMethod(const String& value) { m_method = value; }

            protocol::Network::Headers* getHeaders() { return m_headers.get(); }
            void setHeaders(std::unique_ptr<protocol::Network::Headers> value) { m_headers = std::move(value); }

            bool hasPostData() { return m_postData.isJust(); }
            String getPostData(const String& defaultValue) { return m_postData.isJust() ? m_postData.fromJust() : defaultValue; }
            void setPostData(const String& value) { m_postData = value; }

            struct CORE_EXPORT MixedContentTypeEnum {
                static const char* Blockable;
                static const char* OptionallyBlockable;
                static const char* None;
            }; // MixedContentTypeEnum

            bool hasMixedContentType() { return m_mixedContentType.isJust(); }
            String getMixedContentType(const String& defaultValue) { return m_mixedContentType.isJust() ? m_mixedContentType.fromJust() : defaultValue; }
            void setMixedContentType(const String& value) { m_mixedContentType = value; }

            String getInitialPriority() { return m_initialPriority; }
            void setInitialPriority(const String& value) { m_initialPriority = value; }

            struct CORE_EXPORT ReferrerPolicyEnum {
                static const char* UnsafeUrl;
                static const char* NoReferrerWhenDowngrade;
                static const char* NoReferrer;
                static const char* Origin;
                static const char* OriginWhenCrossOrigin;
                static const char* NoReferrerWhenDowngradeOriginWhenCrossOrigin;
            }; // ReferrerPolicyEnum

            String getReferrerPolicy() { return m_referrerPolicy; }
            void setReferrerPolicy(const String& value) { m_referrerPolicy = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<Request> clone() const;

            template <int STATE>
            class RequestBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    UrlSet = 1 << 1,
                    MethodSet = 1 << 2,
                    HeadersSet = 1 << 3,
                    InitialPrioritySet = 1 << 4,
                    ReferrerPolicySet = 1 << 5,
                    AllFieldsSet = (UrlSet | MethodSet | HeadersSet | InitialPrioritySet | ReferrerPolicySet | 0)
                };

                RequestBuilder<STATE | UrlSet>& setUrl(const String& value)
                {
                    static_assert(!(STATE & UrlSet), "property url should not be set yet");
                    m_result->setUrl(value);
                    return castState<UrlSet>();
                }

                RequestBuilder<STATE | MethodSet>& setMethod(const String& value)
                {
                    static_assert(!(STATE & MethodSet), "property method should not be set yet");
                    m_result->setMethod(value);
                    return castState<MethodSet>();
                }

                RequestBuilder<STATE | HeadersSet>& setHeaders(std::unique_ptr<protocol::Network::Headers> value)
                {
                    static_assert(!(STATE & HeadersSet), "property headers should not be set yet");
                    m_result->setHeaders(std::move(value));
                    return castState<HeadersSet>();
                }

                RequestBuilder<STATE>& setPostData(const String& value)
                {
                    m_result->setPostData(value);
                    return *this;
                }

                RequestBuilder<STATE>& setMixedContentType(const String& value)
                {
                    m_result->setMixedContentType(value);
                    return *this;
                }

                RequestBuilder<STATE | InitialPrioritySet>& setInitialPriority(const String& value)
                {
                    static_assert(!(STATE & InitialPrioritySet), "property initialPriority should not be set yet");
                    m_result->setInitialPriority(value);
                    return castState<InitialPrioritySet>();
                }

                RequestBuilder<STATE | ReferrerPolicySet>& setReferrerPolicy(const String& value)
                {
                    static_assert(!(STATE & ReferrerPolicySet), "property referrerPolicy should not be set yet");
                    m_result->setReferrerPolicy(value);
                    return castState<ReferrerPolicySet>();
                }

                std::unique_ptr<Request> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class Request;
                RequestBuilder()
                    : m_result(new Request())
                {
                }

                template <int STEP>
                RequestBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<RequestBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Network::Request> m_result;
            };

            static RequestBuilder<0> create()
            {
                return RequestBuilder<0>();
            }

        private:
            Request()
            {
            }

            String m_url;
            String m_method;
            std::unique_ptr<protocol::Network::Headers> m_headers;
            Maybe<String> m_postData;
            Maybe<String> m_mixedContentType;
            String m_initialPriority;
            String m_referrerPolicy;
        };

        // Details of a signed certificate timestamp (SCT).
        class CORE_EXPORT SignedCertificateTimestamp : public Serializable {
            PROTOCOL_DISALLOW_COPY(SignedCertificateTimestamp);

        public:
            static std::unique_ptr<SignedCertificateTimestamp> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~SignedCertificateTimestamp() override { }

            String getStatus() { return m_status; }
            void setStatus(const String& value) { m_status = value; }

            String getOrigin() { return m_origin; }
            void setOrigin(const String& value) { m_origin = value; }

            String getLogDescription() { return m_logDescription; }
            void setLogDescription(const String& value) { m_logDescription = value; }

            String getLogId() { return m_logId; }
            void setLogId(const String& value) { m_logId = value; }

            double getTimestamp() { return m_timestamp; }
            void setTimestamp(double value) { m_timestamp = value; }

            String getHashAlgorithm() { return m_hashAlgorithm; }
            void setHashAlgorithm(const String& value) { m_hashAlgorithm = value; }

            String getSignatureAlgorithm() { return m_signatureAlgorithm; }
            void setSignatureAlgorithm(const String& value) { m_signatureAlgorithm = value; }

            String getSignatureData() { return m_signatureData; }
            void setSignatureData(const String& value) { m_signatureData = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<SignedCertificateTimestamp> clone() const;

            template <int STATE>
            class SignedCertificateTimestampBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    StatusSet = 1 << 1,
                    OriginSet = 1 << 2,
                    LogDescriptionSet = 1 << 3,
                    LogIdSet = 1 << 4,
                    TimestampSet = 1 << 5,
                    HashAlgorithmSet = 1 << 6,
                    SignatureAlgorithmSet = 1 << 7,
                    SignatureDataSet = 1 << 8,
                    AllFieldsSet = (StatusSet | OriginSet | LogDescriptionSet | LogIdSet | TimestampSet | HashAlgorithmSet | SignatureAlgorithmSet | SignatureDataSet | 0)
                };

                SignedCertificateTimestampBuilder<STATE | StatusSet>& setStatus(const String& value)
                {
                    static_assert(!(STATE & StatusSet), "property status should not be set yet");
                    m_result->setStatus(value);
                    return castState<StatusSet>();
                }

                SignedCertificateTimestampBuilder<STATE | OriginSet>& setOrigin(const String& value)
                {
                    static_assert(!(STATE & OriginSet), "property origin should not be set yet");
                    m_result->setOrigin(value);
                    return castState<OriginSet>();
                }

                SignedCertificateTimestampBuilder<STATE | LogDescriptionSet>& setLogDescription(const String& value)
                {
                    static_assert(!(STATE & LogDescriptionSet), "property logDescription should not be set yet");
                    m_result->setLogDescription(value);
                    return castState<LogDescriptionSet>();
                }

                SignedCertificateTimestampBuilder<STATE | LogIdSet>& setLogId(const String& value)
                {
                    static_assert(!(STATE & LogIdSet), "property logId should not be set yet");
                    m_result->setLogId(value);
                    return castState<LogIdSet>();
                }

                SignedCertificateTimestampBuilder<STATE | TimestampSet>& setTimestamp(double value)
                {
                    static_assert(!(STATE & TimestampSet), "property timestamp should not be set yet");
                    m_result->setTimestamp(value);
                    return castState<TimestampSet>();
                }

                SignedCertificateTimestampBuilder<STATE | HashAlgorithmSet>& setHashAlgorithm(const String& value)
                {
                    static_assert(!(STATE & HashAlgorithmSet), "property hashAlgorithm should not be set yet");
                    m_result->setHashAlgorithm(value);
                    return castState<HashAlgorithmSet>();
                }

                SignedCertificateTimestampBuilder<STATE | SignatureAlgorithmSet>& setSignatureAlgorithm(const String& value)
                {
                    static_assert(!(STATE & SignatureAlgorithmSet), "property signatureAlgorithm should not be set yet");
                    m_result->setSignatureAlgorithm(value);
                    return castState<SignatureAlgorithmSet>();
                }

                SignedCertificateTimestampBuilder<STATE | SignatureDataSet>& setSignatureData(const String& value)
                {
                    static_assert(!(STATE & SignatureDataSet), "property signatureData should not be set yet");
                    m_result->setSignatureData(value);
                    return castState<SignatureDataSet>();
                }

                std::unique_ptr<SignedCertificateTimestamp> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class SignedCertificateTimestamp;
                SignedCertificateTimestampBuilder()
                    : m_result(new SignedCertificateTimestamp())
                {
                }

                template <int STEP>
                SignedCertificateTimestampBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<SignedCertificateTimestampBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Network::SignedCertificateTimestamp> m_result;
            };

            static SignedCertificateTimestampBuilder<0> create()
            {
                return SignedCertificateTimestampBuilder<0>();
            }

        private:
            SignedCertificateTimestamp()
            {
                m_timestamp = 0;
            }

            String m_status;
            String m_origin;
            String m_logDescription;
            String m_logId;
            double m_timestamp;
            String m_hashAlgorithm;
            String m_signatureAlgorithm;
            String m_signatureData;
        };

        // Security details about a request.
        class CORE_EXPORT SecurityDetails : public Serializable {
            PROTOCOL_DISALLOW_COPY(SecurityDetails);

        public:
            static std::unique_ptr<SecurityDetails> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~SecurityDetails() override { }

            String getProtocol() { return m_protocol; }
            void setProtocol(const String& value) { m_protocol = value; }

            String getKeyExchange() { return m_keyExchange; }
            void setKeyExchange(const String& value) { m_keyExchange = value; }

            bool hasKeyExchangeGroup() { return m_keyExchangeGroup.isJust(); }
            String getKeyExchangeGroup(const String& defaultValue) { return m_keyExchangeGroup.isJust() ? m_keyExchangeGroup.fromJust() : defaultValue; }
            void setKeyExchangeGroup(const String& value) { m_keyExchangeGroup = value; }

            String getCipher() { return m_cipher; }
            void setCipher(const String& value) { m_cipher = value; }

            bool hasMac() { return m_mac.isJust(); }
            String getMac(const String& defaultValue) { return m_mac.isJust() ? m_mac.fromJust() : defaultValue; }
            void setMac(const String& value) { m_mac = value; }

            int getCertificateId() { return m_certificateId; }
            void setCertificateId(int value) { m_certificateId = value; }

            String getSubjectName() { return m_subjectName; }
            void setSubjectName(const String& value) { m_subjectName = value; }

            protocol::Array<String>* getSanList() { return m_sanList.get(); }
            void setSanList(std::unique_ptr<protocol::Array<String>> value) { m_sanList = std::move(value); }

            String getIssuer() { return m_issuer; }
            void setIssuer(const String& value) { m_issuer = value; }

            double getValidFrom() { return m_validFrom; }
            void setValidFrom(double value) { m_validFrom = value; }

            double getValidTo() { return m_validTo; }
            void setValidTo(double value) { m_validTo = value; }

            protocol::Array<protocol::Network::SignedCertificateTimestamp>* getSignedCertificateTimestampList() { return m_signedCertificateTimestampList.get(); }
            void setSignedCertificateTimestampList(std::unique_ptr<protocol::Array<protocol::Network::SignedCertificateTimestamp>> value) { m_signedCertificateTimestampList = std::move(value); }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<SecurityDetails> clone() const;

            template <int STATE>
            class SecurityDetailsBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    ProtocolSet = 1 << 1,
                    KeyExchangeSet = 1 << 2,
                    CipherSet = 1 << 3,
                    CertificateIdSet = 1 << 4,
                    SubjectNameSet = 1 << 5,
                    SanListSet = 1 << 6,
                    IssuerSet = 1 << 7,
                    ValidFromSet = 1 << 8,
                    ValidToSet = 1 << 9,
                    SignedCertificateTimestampListSet = 1 << 10,
                    AllFieldsSet = (ProtocolSet | KeyExchangeSet | CipherSet | CertificateIdSet | SubjectNameSet | SanListSet | IssuerSet | ValidFromSet | ValidToSet | SignedCertificateTimestampListSet | 0)
                };

                SecurityDetailsBuilder<STATE | ProtocolSet>& setProtocol(const String& value)
                {
                    static_assert(!(STATE & ProtocolSet), "property protocol should not be set yet");
                    m_result->setProtocol(value);
                    return castState<ProtocolSet>();
                }

                SecurityDetailsBuilder<STATE | KeyExchangeSet>& setKeyExchange(const String& value)
                {
                    static_assert(!(STATE & KeyExchangeSet), "property keyExchange should not be set yet");
                    m_result->setKeyExchange(value);
                    return castState<KeyExchangeSet>();
                }

                SecurityDetailsBuilder<STATE>& setKeyExchangeGroup(const String& value)
                {
                    m_result->setKeyExchangeGroup(value);
                    return *this;
                }

                SecurityDetailsBuilder<STATE | CipherSet>& setCipher(const String& value)
                {
                    static_assert(!(STATE & CipherSet), "property cipher should not be set yet");
                    m_result->setCipher(value);
                    return castState<CipherSet>();
                }

                SecurityDetailsBuilder<STATE>& setMac(const String& value)
                {
                    m_result->setMac(value);
                    return *this;
                }

                SecurityDetailsBuilder<STATE | CertificateIdSet>& setCertificateId(int value)
                {
                    static_assert(!(STATE & CertificateIdSet), "property certificateId should not be set yet");
                    m_result->setCertificateId(value);
                    return castState<CertificateIdSet>();
                }

                SecurityDetailsBuilder<STATE | SubjectNameSet>& setSubjectName(const String& value)
                {
                    static_assert(!(STATE & SubjectNameSet), "property subjectName should not be set yet");
                    m_result->setSubjectName(value);
                    return castState<SubjectNameSet>();
                }

                SecurityDetailsBuilder<STATE | SanListSet>& setSanList(std::unique_ptr<protocol::Array<String>> value)
                {
                    static_assert(!(STATE & SanListSet), "property sanList should not be set yet");
                    m_result->setSanList(std::move(value));
                    return castState<SanListSet>();
                }

                SecurityDetailsBuilder<STATE | IssuerSet>& setIssuer(const String& value)
                {
                    static_assert(!(STATE & IssuerSet), "property issuer should not be set yet");
                    m_result->setIssuer(value);
                    return castState<IssuerSet>();
                }

                SecurityDetailsBuilder<STATE | ValidFromSet>& setValidFrom(double value)
                {
                    static_assert(!(STATE & ValidFromSet), "property validFrom should not be set yet");
                    m_result->setValidFrom(value);
                    return castState<ValidFromSet>();
                }

                SecurityDetailsBuilder<STATE | ValidToSet>& setValidTo(double value)
                {
                    static_assert(!(STATE & ValidToSet), "property validTo should not be set yet");
                    m_result->setValidTo(value);
                    return castState<ValidToSet>();
                }

                SecurityDetailsBuilder<STATE | SignedCertificateTimestampListSet>& setSignedCertificateTimestampList(std::unique_ptr<protocol::Array<protocol::Network::SignedCertificateTimestamp>> value)
                {
                    static_assert(!(STATE & SignedCertificateTimestampListSet), "property signedCertificateTimestampList should not be set yet");
                    m_result->setSignedCertificateTimestampList(std::move(value));
                    return castState<SignedCertificateTimestampListSet>();
                }

                std::unique_ptr<SecurityDetails> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class SecurityDetails;
                SecurityDetailsBuilder()
                    : m_result(new SecurityDetails())
                {
                }

                template <int STEP>
                SecurityDetailsBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<SecurityDetailsBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Network::SecurityDetails> m_result;
            };

            static SecurityDetailsBuilder<0> create()
            {
                return SecurityDetailsBuilder<0>();
            }

        private:
            SecurityDetails()
            {
                m_certificateId = 0;
                m_validFrom = 0;
                m_validTo = 0;
            }

            String m_protocol;
            String m_keyExchange;
            Maybe<String> m_keyExchangeGroup;
            String m_cipher;
            Maybe<String> m_mac;
            int m_certificateId;
            String m_subjectName;
            std::unique_ptr<protocol::Array<String>> m_sanList;
            String m_issuer;
            double m_validFrom;
            double m_validTo;
            std::unique_ptr<protocol::Array<protocol::Network::SignedCertificateTimestamp>> m_signedCertificateTimestampList;
        };

        // HTTP response data.
        class CORE_EXPORT Response : public Serializable {
            PROTOCOL_DISALLOW_COPY(Response);

        public:
            static std::unique_ptr<Response> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~Response() override { }

            String getUrl() { return m_url; }
            void setUrl(const String& value) { m_url = value; }

            double getStatus() { return m_status; }
            void setStatus(double value) { m_status = value; }

            String getStatusText() { return m_statusText; }
            void setStatusText(const String& value) { m_statusText = value; }

            protocol::Network::Headers* getHeaders() { return m_headers.get(); }
            void setHeaders(std::unique_ptr<protocol::Network::Headers> value) { m_headers = std::move(value); }

            bool hasHeadersText() { return m_headersText.isJust(); }
            String getHeadersText(const String& defaultValue) { return m_headersText.isJust() ? m_headersText.fromJust() : defaultValue; }
            void setHeadersText(const String& value) { m_headersText = value; }

            String getMimeType() { return m_mimeType; }
            void setMimeType(const String& value) { m_mimeType = value; }

            bool hasRequestHeaders() { return m_requestHeaders.isJust(); }
            protocol::Network::Headers* getRequestHeaders(protocol::Network::Headers* defaultValue) { return m_requestHeaders.isJust() ? m_requestHeaders.fromJust() : defaultValue; }
            void setRequestHeaders(std::unique_ptr<protocol::Network::Headers> value) { m_requestHeaders = std::move(value); }

            bool hasRequestHeadersText() { return m_requestHeadersText.isJust(); }
            String getRequestHeadersText(const String& defaultValue) { return m_requestHeadersText.isJust() ? m_requestHeadersText.fromJust() : defaultValue; }
            void setRequestHeadersText(const String& value) { m_requestHeadersText = value; }

            bool getConnectionReused() { return m_connectionReused; }
            void setConnectionReused(bool value) { m_connectionReused = value; }

            double getConnectionId() { return m_connectionId; }
            void setConnectionId(double value) { m_connectionId = value; }

            bool hasRemoteIPAddress() { return m_remoteIPAddress.isJust(); }
            String getRemoteIPAddress(const String& defaultValue) { return m_remoteIPAddress.isJust() ? m_remoteIPAddress.fromJust() : defaultValue; }
            void setRemoteIPAddress(const String& value) { m_remoteIPAddress = value; }

            bool hasRemotePort() { return m_remotePort.isJust(); }
            int getRemotePort(int defaultValue) { return m_remotePort.isJust() ? m_remotePort.fromJust() : defaultValue; }
            void setRemotePort(int value) { m_remotePort = value; }

            bool hasFromDiskCache() { return m_fromDiskCache.isJust(); }
            bool getFromDiskCache(bool defaultValue) { return m_fromDiskCache.isJust() ? m_fromDiskCache.fromJust() : defaultValue; }
            void setFromDiskCache(bool value) { m_fromDiskCache = value; }

            bool hasFromServiceWorker() { return m_fromServiceWorker.isJust(); }
            bool getFromServiceWorker(bool defaultValue) { return m_fromServiceWorker.isJust() ? m_fromServiceWorker.fromJust() : defaultValue; }
            void setFromServiceWorker(bool value) { m_fromServiceWorker = value; }

            double getEncodedDataLength() { return m_encodedDataLength; }
            void setEncodedDataLength(double value) { m_encodedDataLength = value; }

            bool hasTiming() { return m_timing.isJust(); }
            protocol::Network::ResourceTiming* getTiming(protocol::Network::ResourceTiming* defaultValue) { return m_timing.isJust() ? m_timing.fromJust() : defaultValue; }
            void setTiming(std::unique_ptr<protocol::Network::ResourceTiming> value) { m_timing = std::move(value); }

            bool hasProtocol() { return m_protocol.isJust(); }
            String getProtocol(const String& defaultValue) { return m_protocol.isJust() ? m_protocol.fromJust() : defaultValue; }
            void setProtocol(const String& value) { m_protocol = value; }

            String getSecurityState() { return m_securityState; }
            void setSecurityState(const String& value) { m_securityState = value; }

            bool hasSecurityDetails() { return m_securityDetails.isJust(); }
            protocol::Network::SecurityDetails* getSecurityDetails(protocol::Network::SecurityDetails* defaultValue) { return m_securityDetails.isJust() ? m_securityDetails.fromJust() : defaultValue; }
            void setSecurityDetails(std::unique_ptr<protocol::Network::SecurityDetails> value) { m_securityDetails = std::move(value); }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<Response> clone() const;

            template <int STATE>
            class ResponseBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    UrlSet = 1 << 1,
                    StatusSet = 1 << 2,
                    StatusTextSet = 1 << 3,
                    HeadersSet = 1 << 4,
                    MimeTypeSet = 1 << 5,
                    ConnectionReusedSet = 1 << 6,
                    ConnectionIdSet = 1 << 7,
                    EncodedDataLengthSet = 1 << 8,
                    SecurityStateSet = 1 << 9,
                    AllFieldsSet = (UrlSet | StatusSet | StatusTextSet | HeadersSet | MimeTypeSet | ConnectionReusedSet | ConnectionIdSet | EncodedDataLengthSet | SecurityStateSet | 0)
                };

                ResponseBuilder<STATE | UrlSet>& setUrl(const String& value)
                {
                    static_assert(!(STATE & UrlSet), "property url should not be set yet");
                    m_result->setUrl(value);
                    return castState<UrlSet>();
                }

                ResponseBuilder<STATE | StatusSet>& setStatus(double value)
                {
                    static_assert(!(STATE & StatusSet), "property status should not be set yet");
                    m_result->setStatus(value);
                    return castState<StatusSet>();
                }

                ResponseBuilder<STATE | StatusTextSet>& setStatusText(const String& value)
                {
                    static_assert(!(STATE & StatusTextSet), "property statusText should not be set yet");
                    m_result->setStatusText(value);
                    return castState<StatusTextSet>();
                }

                ResponseBuilder<STATE | HeadersSet>& setHeaders(std::unique_ptr<protocol::Network::Headers> value)
                {
                    static_assert(!(STATE & HeadersSet), "property headers should not be set yet");
                    m_result->setHeaders(std::move(value));
                    return castState<HeadersSet>();
                }

                ResponseBuilder<STATE>& setHeadersText(const String& value)
                {
                    m_result->setHeadersText(value);
                    return *this;
                }

                ResponseBuilder<STATE | MimeTypeSet>& setMimeType(const String& value)
                {
                    static_assert(!(STATE & MimeTypeSet), "property mimeType should not be set yet");
                    m_result->setMimeType(value);
                    return castState<MimeTypeSet>();
                }

                ResponseBuilder<STATE>& setRequestHeaders(std::unique_ptr<protocol::Network::Headers> value)
                {
                    m_result->setRequestHeaders(std::move(value));
                    return *this;
                }

                ResponseBuilder<STATE>& setRequestHeadersText(const String& value)
                {
                    m_result->setRequestHeadersText(value);
                    return *this;
                }

                ResponseBuilder<STATE | ConnectionReusedSet>& setConnectionReused(bool value)
                {
                    static_assert(!(STATE & ConnectionReusedSet), "property connectionReused should not be set yet");
                    m_result->setConnectionReused(value);
                    return castState<ConnectionReusedSet>();
                }

                ResponseBuilder<STATE | ConnectionIdSet>& setConnectionId(double value)
                {
                    static_assert(!(STATE & ConnectionIdSet), "property connectionId should not be set yet");
                    m_result->setConnectionId(value);
                    return castState<ConnectionIdSet>();
                }

                ResponseBuilder<STATE>& setRemoteIPAddress(const String& value)
                {
                    m_result->setRemoteIPAddress(value);
                    return *this;
                }

                ResponseBuilder<STATE>& setRemotePort(int value)
                {
                    m_result->setRemotePort(value);
                    return *this;
                }

                ResponseBuilder<STATE>& setFromDiskCache(bool value)
                {
                    m_result->setFromDiskCache(value);
                    return *this;
                }

                ResponseBuilder<STATE>& setFromServiceWorker(bool value)
                {
                    m_result->setFromServiceWorker(value);
                    return *this;
                }

                ResponseBuilder<STATE | EncodedDataLengthSet>& setEncodedDataLength(double value)
                {
                    static_assert(!(STATE & EncodedDataLengthSet), "property encodedDataLength should not be set yet");
                    m_result->setEncodedDataLength(value);
                    return castState<EncodedDataLengthSet>();
                }

                ResponseBuilder<STATE>& setTiming(std::unique_ptr<protocol::Network::ResourceTiming> value)
                {
                    m_result->setTiming(std::move(value));
                    return *this;
                }

                ResponseBuilder<STATE>& setProtocol(const String& value)
                {
                    m_result->setProtocol(value);
                    return *this;
                }

                ResponseBuilder<STATE | SecurityStateSet>& setSecurityState(const String& value)
                {
                    static_assert(!(STATE & SecurityStateSet), "property securityState should not be set yet");
                    m_result->setSecurityState(value);
                    return castState<SecurityStateSet>();
                }

                ResponseBuilder<STATE>& setSecurityDetails(std::unique_ptr<protocol::Network::SecurityDetails> value)
                {
                    m_result->setSecurityDetails(std::move(value));
                    return *this;
                }

                std::unique_ptr<Response> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class Response;
                ResponseBuilder()
                    : m_result(new Response())
                {
                }

                template <int STEP>
                ResponseBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<ResponseBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Network::Response> m_result;
            };

            static ResponseBuilder<0> create()
            {
                return ResponseBuilder<0>();
            }

        private:
            Response()
            {
                m_status = 0;
                m_connectionReused = false;
                m_connectionId = 0;
                m_encodedDataLength = 0;
            }

            String m_url;
            double m_status;
            String m_statusText;
            std::unique_ptr<protocol::Network::Headers> m_headers;
            Maybe<String> m_headersText;
            String m_mimeType;
            Maybe<protocol::Network::Headers> m_requestHeaders;
            Maybe<String> m_requestHeadersText;
            bool m_connectionReused;
            double m_connectionId;
            Maybe<String> m_remoteIPAddress;
            Maybe<int> m_remotePort;
            Maybe<bool> m_fromDiskCache;
            Maybe<bool> m_fromServiceWorker;
            double m_encodedDataLength;
            Maybe<protocol::Network::ResourceTiming> m_timing;
            Maybe<String> m_protocol;
            String m_securityState;
            Maybe<protocol::Network::SecurityDetails> m_securityDetails;
        };

        // WebSocket request data.
        class CORE_EXPORT WebSocketRequest : public Serializable {
            PROTOCOL_DISALLOW_COPY(WebSocketRequest);

        public:
            static std::unique_ptr<WebSocketRequest> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~WebSocketRequest() override { }

            protocol::Network::Headers* getHeaders() { return m_headers.get(); }
            void setHeaders(std::unique_ptr<protocol::Network::Headers> value) { m_headers = std::move(value); }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<WebSocketRequest> clone() const;

            template <int STATE>
            class WebSocketRequestBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    HeadersSet = 1 << 1,
                    AllFieldsSet = (HeadersSet | 0)
                };

                WebSocketRequestBuilder<STATE | HeadersSet>& setHeaders(std::unique_ptr<protocol::Network::Headers> value)
                {
                    static_assert(!(STATE & HeadersSet), "property headers should not be set yet");
                    m_result->setHeaders(std::move(value));
                    return castState<HeadersSet>();
                }

                std::unique_ptr<WebSocketRequest> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class WebSocketRequest;
                WebSocketRequestBuilder()
                    : m_result(new WebSocketRequest())
                {
                }

                template <int STEP>
                WebSocketRequestBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<WebSocketRequestBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Network::WebSocketRequest> m_result;
            };

            static WebSocketRequestBuilder<0> create()
            {
                return WebSocketRequestBuilder<0>();
            }

        private:
            WebSocketRequest()
            {
            }

            std::unique_ptr<protocol::Network::Headers> m_headers;
        };

        // WebSocket response data.
        class CORE_EXPORT WebSocketResponse : public Serializable {
            PROTOCOL_DISALLOW_COPY(WebSocketResponse);

        public:
            static std::unique_ptr<WebSocketResponse> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~WebSocketResponse() override { }

            double getStatus() { return m_status; }
            void setStatus(double value) { m_status = value; }

            String getStatusText() { return m_statusText; }
            void setStatusText(const String& value) { m_statusText = value; }

            protocol::Network::Headers* getHeaders() { return m_headers.get(); }
            void setHeaders(std::unique_ptr<protocol::Network::Headers> value) { m_headers = std::move(value); }

            bool hasHeadersText() { return m_headersText.isJust(); }
            String getHeadersText(const String& defaultValue) { return m_headersText.isJust() ? m_headersText.fromJust() : defaultValue; }
            void setHeadersText(const String& value) { m_headersText = value; }

            bool hasRequestHeaders() { return m_requestHeaders.isJust(); }
            protocol::Network::Headers* getRequestHeaders(protocol::Network::Headers* defaultValue) { return m_requestHeaders.isJust() ? m_requestHeaders.fromJust() : defaultValue; }
            void setRequestHeaders(std::unique_ptr<protocol::Network::Headers> value) { m_requestHeaders = std::move(value); }

            bool hasRequestHeadersText() { return m_requestHeadersText.isJust(); }
            String getRequestHeadersText(const String& defaultValue) { return m_requestHeadersText.isJust() ? m_requestHeadersText.fromJust() : defaultValue; }
            void setRequestHeadersText(const String& value) { m_requestHeadersText = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<WebSocketResponse> clone() const;

            template <int STATE>
            class WebSocketResponseBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    StatusSet = 1 << 1,
                    StatusTextSet = 1 << 2,
                    HeadersSet = 1 << 3,
                    AllFieldsSet = (StatusSet | StatusTextSet | HeadersSet | 0)
                };

                WebSocketResponseBuilder<STATE | StatusSet>& setStatus(double value)
                {
                    static_assert(!(STATE & StatusSet), "property status should not be set yet");
                    m_result->setStatus(value);
                    return castState<StatusSet>();
                }

                WebSocketResponseBuilder<STATE | StatusTextSet>& setStatusText(const String& value)
                {
                    static_assert(!(STATE & StatusTextSet), "property statusText should not be set yet");
                    m_result->setStatusText(value);
                    return castState<StatusTextSet>();
                }

                WebSocketResponseBuilder<STATE | HeadersSet>& setHeaders(std::unique_ptr<protocol::Network::Headers> value)
                {
                    static_assert(!(STATE & HeadersSet), "property headers should not be set yet");
                    m_result->setHeaders(std::move(value));
                    return castState<HeadersSet>();
                }

                WebSocketResponseBuilder<STATE>& setHeadersText(const String& value)
                {
                    m_result->setHeadersText(value);
                    return *this;
                }

                WebSocketResponseBuilder<STATE>& setRequestHeaders(std::unique_ptr<protocol::Network::Headers> value)
                {
                    m_result->setRequestHeaders(std::move(value));
                    return *this;
                }

                WebSocketResponseBuilder<STATE>& setRequestHeadersText(const String& value)
                {
                    m_result->setRequestHeadersText(value);
                    return *this;
                }

                std::unique_ptr<WebSocketResponse> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class WebSocketResponse;
                WebSocketResponseBuilder()
                    : m_result(new WebSocketResponse())
                {
                }

                template <int STEP>
                WebSocketResponseBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<WebSocketResponseBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Network::WebSocketResponse> m_result;
            };

            static WebSocketResponseBuilder<0> create()
            {
                return WebSocketResponseBuilder<0>();
            }

        private:
            WebSocketResponse()
            {
                m_status = 0;
            }

            double m_status;
            String m_statusText;
            std::unique_ptr<protocol::Network::Headers> m_headers;
            Maybe<String> m_headersText;
            Maybe<protocol::Network::Headers> m_requestHeaders;
            Maybe<String> m_requestHeadersText;
        };

        // WebSocket frame data.
        class CORE_EXPORT WebSocketFrame : public Serializable {
            PROTOCOL_DISALLOW_COPY(WebSocketFrame);

        public:
            static std::unique_ptr<WebSocketFrame> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~WebSocketFrame() override { }

            double getOpcode() { return m_opcode; }
            void setOpcode(double value) { m_opcode = value; }

            bool getMask() { return m_mask; }
            void setMask(bool value) { m_mask = value; }

            String getPayloadData() { return m_payloadData; }
            void setPayloadData(const String& value) { m_payloadData = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<WebSocketFrame> clone() const;

            template <int STATE>
            class WebSocketFrameBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    OpcodeSet = 1 << 1,
                    MaskSet = 1 << 2,
                    PayloadDataSet = 1 << 3,
                    AllFieldsSet = (OpcodeSet | MaskSet | PayloadDataSet | 0)
                };

                WebSocketFrameBuilder<STATE | OpcodeSet>& setOpcode(double value)
                {
                    static_assert(!(STATE & OpcodeSet), "property opcode should not be set yet");
                    m_result->setOpcode(value);
                    return castState<OpcodeSet>();
                }

                WebSocketFrameBuilder<STATE | MaskSet>& setMask(bool value)
                {
                    static_assert(!(STATE & MaskSet), "property mask should not be set yet");
                    m_result->setMask(value);
                    return castState<MaskSet>();
                }

                WebSocketFrameBuilder<STATE | PayloadDataSet>& setPayloadData(const String& value)
                {
                    static_assert(!(STATE & PayloadDataSet), "property payloadData should not be set yet");
                    m_result->setPayloadData(value);
                    return castState<PayloadDataSet>();
                }

                std::unique_ptr<WebSocketFrame> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class WebSocketFrame;
                WebSocketFrameBuilder()
                    : m_result(new WebSocketFrame())
                {
                }

                template <int STEP>
                WebSocketFrameBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<WebSocketFrameBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Network::WebSocketFrame> m_result;
            };

            static WebSocketFrameBuilder<0> create()
            {
                return WebSocketFrameBuilder<0>();
            }

        private:
            WebSocketFrame()
            {
                m_opcode = 0;
                m_mask = false;
            }

            double m_opcode;
            bool m_mask;
            String m_payloadData;
        };

        // Information about the cached resource.
        class CORE_EXPORT CachedResource : public Serializable {
            PROTOCOL_DISALLOW_COPY(CachedResource);

        public:
            static std::unique_ptr<CachedResource> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~CachedResource() override { }

            String getUrl() { return m_url; }
            void setUrl(const String& value) { m_url = value; }

            String getType() { return m_type; }
            void setType(const String& value) { m_type = value; }

            bool hasResponse() { return m_response.isJust(); }
            protocol::Network::Response* getResponse(protocol::Network::Response* defaultValue) { return m_response.isJust() ? m_response.fromJust() : defaultValue; }
            void setResponse(std::unique_ptr<protocol::Network::Response> value) { m_response = std::move(value); }

            double getBodySize() { return m_bodySize; }
            void setBodySize(double value) { m_bodySize = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<CachedResource> clone() const;

            template <int STATE>
            class CachedResourceBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    UrlSet = 1 << 1,
                    TypeSet = 1 << 2,
                    BodySizeSet = 1 << 3,
                    AllFieldsSet = (UrlSet | TypeSet | BodySizeSet | 0)
                };

                CachedResourceBuilder<STATE | UrlSet>& setUrl(const String& value)
                {
                    static_assert(!(STATE & UrlSet), "property url should not be set yet");
                    m_result->setUrl(value);
                    return castState<UrlSet>();
                }

                CachedResourceBuilder<STATE | TypeSet>& setType(const String& value)
                {
                    static_assert(!(STATE & TypeSet), "property type should not be set yet");
                    m_result->setType(value);
                    return castState<TypeSet>();
                }

                CachedResourceBuilder<STATE>& setResponse(std::unique_ptr<protocol::Network::Response> value)
                {
                    m_result->setResponse(std::move(value));
                    return *this;
                }

                CachedResourceBuilder<STATE | BodySizeSet>& setBodySize(double value)
                {
                    static_assert(!(STATE & BodySizeSet), "property bodySize should not be set yet");
                    m_result->setBodySize(value);
                    return castState<BodySizeSet>();
                }

                std::unique_ptr<CachedResource> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class CachedResource;
                CachedResourceBuilder()
                    : m_result(new CachedResource())
                {
                }

                template <int STEP>
                CachedResourceBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<CachedResourceBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Network::CachedResource> m_result;
            };

            static CachedResourceBuilder<0> create()
            {
                return CachedResourceBuilder<0>();
            }

        private:
            CachedResource()
            {
                m_bodySize = 0;
            }

            String m_url;
            String m_type;
            Maybe<protocol::Network::Response> m_response;
            double m_bodySize;
        };

        // Information about the request initiator.
        class CORE_EXPORT Initiator : public Serializable {
            PROTOCOL_DISALLOW_COPY(Initiator);

        public:
            static std::unique_ptr<Initiator> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~Initiator() override { }

            struct CORE_EXPORT TypeEnum {
                static const char* Parser;
                static const char* Script;
                static const char* Other;
            }; // TypeEnum

            String getType() { return m_type; }
            void setType(const String& value) { m_type = value; }

            bool hasStack() { return m_stack.isJust(); }
            v8_inspector::protocol::Runtime::API::StackTrace* getStack(v8_inspector::protocol::Runtime::API::StackTrace* defaultValue) { return m_stack.isJust() ? m_stack.fromJust() : defaultValue; }
            void setStack(std::unique_ptr<v8_inspector::protocol::Runtime::API::StackTrace> value) { m_stack = std::move(value); }

            bool hasUrl() { return m_url.isJust(); }
            String getUrl(const String& defaultValue) { return m_url.isJust() ? m_url.fromJust() : defaultValue; }
            void setUrl(const String& value) { m_url = value; }

            bool hasLineNumber() { return m_lineNumber.isJust(); }
            double getLineNumber(double defaultValue) { return m_lineNumber.isJust() ? m_lineNumber.fromJust() : defaultValue; }
            void setLineNumber(double value) { m_lineNumber = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<Initiator> clone() const;

            template <int STATE>
            class InitiatorBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    TypeSet = 1 << 1,
                    AllFieldsSet = (TypeSet | 0)
                };

                InitiatorBuilder<STATE | TypeSet>& setType(const String& value)
                {
                    static_assert(!(STATE & TypeSet), "property type should not be set yet");
                    m_result->setType(value);
                    return castState<TypeSet>();
                }

                InitiatorBuilder<STATE>& setStack(std::unique_ptr<v8_inspector::protocol::Runtime::API::StackTrace> value)
                {
                    m_result->setStack(std::move(value));
                    return *this;
                }

                InitiatorBuilder<STATE>& setUrl(const String& value)
                {
                    m_result->setUrl(value);
                    return *this;
                }

                InitiatorBuilder<STATE>& setLineNumber(double value)
                {
                    m_result->setLineNumber(value);
                    return *this;
                }

                std::unique_ptr<Initiator> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class Initiator;
                InitiatorBuilder()
                    : m_result(new Initiator())
                {
                }

                template <int STEP>
                InitiatorBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<InitiatorBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Network::Initiator> m_result;
            };

            static InitiatorBuilder<0> create()
            {
                return InitiatorBuilder<0>();
            }

        private:
            Initiator()
            {
            }

            String m_type;
            Maybe<v8_inspector::protocol::Runtime::API::StackTrace> m_stack;
            Maybe<String> m_url;
            Maybe<double> m_lineNumber;
        };

        // Cookie object
        class CORE_EXPORT Cookie : public Serializable {
            PROTOCOL_DISALLOW_COPY(Cookie);

        public:
            static std::unique_ptr<Cookie> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~Cookie() override { }

            String getName() { return m_name; }
            void setName(const String& value) { m_name = value; }

            String getValue() { return m_value; }
            void setValue(const String& value) { m_value = value; }

            String getDomain() { return m_domain; }
            void setDomain(const String& value) { m_domain = value; }

            String getPath() { return m_path; }
            void setPath(const String& value) { m_path = value; }

            double getExpires() { return m_expires; }
            void setExpires(double value) { m_expires = value; }

            int getSize() { return m_size; }
            void setSize(int value) { m_size = value; }

            bool getHttpOnly() { return m_httpOnly; }
            void setHttpOnly(bool value) { m_httpOnly = value; }

            bool getSecure() { return m_secure; }
            void setSecure(bool value) { m_secure = value; }

            bool getSession() { return m_session; }
            void setSession(bool value) { m_session = value; }

            bool hasSameSite() { return m_sameSite.isJust(); }
            String getSameSite(const String& defaultValue) { return m_sameSite.isJust() ? m_sameSite.fromJust() : defaultValue; }
            void setSameSite(const String& value) { m_sameSite = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<Cookie> clone() const;

            template <int STATE>
            class CookieBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    NameSet = 1 << 1,
                    ValueSet = 1 << 2,
                    DomainSet = 1 << 3,
                    PathSet = 1 << 4,
                    ExpiresSet = 1 << 5,
                    SizeSet = 1 << 6,
                    HttpOnlySet = 1 << 7,
                    SecureSet = 1 << 8,
                    SessionSet = 1 << 9,
                    AllFieldsSet = (NameSet | ValueSet | DomainSet | PathSet | ExpiresSet | SizeSet | HttpOnlySet | SecureSet | SessionSet | 0)
                };

                CookieBuilder<STATE | NameSet>& setName(const String& value)
                {
                    static_assert(!(STATE & NameSet), "property name should not be set yet");
                    m_result->setName(value);
                    return castState<NameSet>();
                }

                CookieBuilder<STATE | ValueSet>& setValue(const String& value)
                {
                    static_assert(!(STATE & ValueSet), "property value should not be set yet");
                    m_result->setValue(value);
                    return castState<ValueSet>();
                }

                CookieBuilder<STATE | DomainSet>& setDomain(const String& value)
                {
                    static_assert(!(STATE & DomainSet), "property domain should not be set yet");
                    m_result->setDomain(value);
                    return castState<DomainSet>();
                }

                CookieBuilder<STATE | PathSet>& setPath(const String& value)
                {
                    static_assert(!(STATE & PathSet), "property path should not be set yet");
                    m_result->setPath(value);
                    return castState<PathSet>();
                }

                CookieBuilder<STATE | ExpiresSet>& setExpires(double value)
                {
                    static_assert(!(STATE & ExpiresSet), "property expires should not be set yet");
                    m_result->setExpires(value);
                    return castState<ExpiresSet>();
                }

                CookieBuilder<STATE | SizeSet>& setSize(int value)
                {
                    static_assert(!(STATE & SizeSet), "property size should not be set yet");
                    m_result->setSize(value);
                    return castState<SizeSet>();
                }

                CookieBuilder<STATE | HttpOnlySet>& setHttpOnly(bool value)
                {
                    static_assert(!(STATE & HttpOnlySet), "property httpOnly should not be set yet");
                    m_result->setHttpOnly(value);
                    return castState<HttpOnlySet>();
                }

                CookieBuilder<STATE | SecureSet>& setSecure(bool value)
                {
                    static_assert(!(STATE & SecureSet), "property secure should not be set yet");
                    m_result->setSecure(value);
                    return castState<SecureSet>();
                }

                CookieBuilder<STATE | SessionSet>& setSession(bool value)
                {
                    static_assert(!(STATE & SessionSet), "property session should not be set yet");
                    m_result->setSession(value);
                    return castState<SessionSet>();
                }

                CookieBuilder<STATE>& setSameSite(const String& value)
                {
                    m_result->setSameSite(value);
                    return *this;
                }

                std::unique_ptr<Cookie> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class Cookie;
                CookieBuilder()
                    : m_result(new Cookie())
                {
                }

                template <int STEP>
                CookieBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<CookieBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Network::Cookie> m_result;
            };

            static CookieBuilder<0> create()
            {
                return CookieBuilder<0>();
            }

        private:
            Cookie()
            {
                m_expires = 0;
                m_size = 0;
                m_httpOnly = false;
                m_secure = false;
                m_session = false;
            }

            String m_name;
            String m_value;
            String m_domain;
            String m_path;
            double m_expires;
            int m_size;
            bool m_httpOnly;
            bool m_secure;
            bool m_session;
            Maybe<String> m_sameSite;
        };

        // Wrapper for notification params
        class CORE_EXPORT ResourceChangedPriorityNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(ResourceChangedPriorityNotification);

        public:
            static std::unique_ptr<ResourceChangedPriorityNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~ResourceChangedPriorityNotification() override { }

            String getRequestId() { return m_requestId; }
            void setRequestId(const String& value) { m_requestId = value; }

            String getNewPriority() { return m_newPriority; }
            void setNewPriority(const String& value) { m_newPriority = value; }

            double getTimestamp() { return m_timestamp; }
            void setTimestamp(double value) { m_timestamp = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<ResourceChangedPriorityNotification> clone() const;

            template <int STATE>
            class ResourceChangedPriorityNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    RequestIdSet = 1 << 1,
                    NewPrioritySet = 1 << 2,
                    TimestampSet = 1 << 3,
                    AllFieldsSet = (RequestIdSet | NewPrioritySet | TimestampSet | 0)
                };

                ResourceChangedPriorityNotificationBuilder<STATE | RequestIdSet>& setRequestId(const String& value)
                {
                    static_assert(!(STATE & RequestIdSet), "property requestId should not be set yet");
                    m_result->setRequestId(value);
                    return castState<RequestIdSet>();
                }

                ResourceChangedPriorityNotificationBuilder<STATE | NewPrioritySet>& setNewPriority(const String& value)
                {
                    static_assert(!(STATE & NewPrioritySet), "property newPriority should not be set yet");
                    m_result->setNewPriority(value);
                    return castState<NewPrioritySet>();
                }

                ResourceChangedPriorityNotificationBuilder<STATE | TimestampSet>& setTimestamp(double value)
                {
                    static_assert(!(STATE & TimestampSet), "property timestamp should not be set yet");
                    m_result->setTimestamp(value);
                    return castState<TimestampSet>();
                }

                std::unique_ptr<ResourceChangedPriorityNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class ResourceChangedPriorityNotification;
                ResourceChangedPriorityNotificationBuilder()
                    : m_result(new ResourceChangedPriorityNotification())
                {
                }

                template <int STEP>
                ResourceChangedPriorityNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<ResourceChangedPriorityNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Network::ResourceChangedPriorityNotification> m_result;
            };

            static ResourceChangedPriorityNotificationBuilder<0> create()
            {
                return ResourceChangedPriorityNotificationBuilder<0>();
            }

        private:
            ResourceChangedPriorityNotification()
            {
                m_timestamp = 0;
            }

            String m_requestId;
            String m_newPriority;
            double m_timestamp;
        };

        // Wrapper for notification params
        class CORE_EXPORT RequestWillBeSentNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(RequestWillBeSentNotification);

        public:
            static std::unique_ptr<RequestWillBeSentNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~RequestWillBeSentNotification() override { }

            String getRequestId() { return m_requestId; }
            void setRequestId(const String& value) { m_requestId = value; }

            String getFrameId() { return m_frameId; }
            void setFrameId(const String& value) { m_frameId = value; }

            String getLoaderId() { return m_loaderId; }
            void setLoaderId(const String& value) { m_loaderId = value; }

            String getDocumentURL() { return m_documentURL; }
            void setDocumentURL(const String& value) { m_documentURL = value; }

            protocol::Network::Request* getRequest() { return m_request.get(); }
            void setRequest(std::unique_ptr<protocol::Network::Request> value) { m_request = std::move(value); }

            double getTimestamp() { return m_timestamp; }
            void setTimestamp(double value) { m_timestamp = value; }

            double getWallTime() { return m_wallTime; }
            void setWallTime(double value) { m_wallTime = value; }

            protocol::Network::Initiator* getInitiator() { return m_initiator.get(); }
            void setInitiator(std::unique_ptr<protocol::Network::Initiator> value) { m_initiator = std::move(value); }

            bool hasRedirectResponse() { return m_redirectResponse.isJust(); }
            protocol::Network::Response* getRedirectResponse(protocol::Network::Response* defaultValue) { return m_redirectResponse.isJust() ? m_redirectResponse.fromJust() : defaultValue; }
            void setRedirectResponse(std::unique_ptr<protocol::Network::Response> value) { m_redirectResponse = std::move(value); }

            bool hasType() { return m_type.isJust(); }
            String getType(const String& defaultValue) { return m_type.isJust() ? m_type.fromJust() : defaultValue; }
            void setType(const String& value) { m_type = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<RequestWillBeSentNotification> clone() const;

            template <int STATE>
            class RequestWillBeSentNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    RequestIdSet = 1 << 1,
                    FrameIdSet = 1 << 2,
                    LoaderIdSet = 1 << 3,
                    DocumentURLSet = 1 << 4,
                    RequestSet = 1 << 5,
                    TimestampSet = 1 << 6,
                    WallTimeSet = 1 << 7,
                    InitiatorSet = 1 << 8,
                    AllFieldsSet = (RequestIdSet | FrameIdSet | LoaderIdSet | DocumentURLSet | RequestSet | TimestampSet | WallTimeSet | InitiatorSet | 0)
                };

                RequestWillBeSentNotificationBuilder<STATE | RequestIdSet>& setRequestId(const String& value)
                {
                    static_assert(!(STATE & RequestIdSet), "property requestId should not be set yet");
                    m_result->setRequestId(value);
                    return castState<RequestIdSet>();
                }

                RequestWillBeSentNotificationBuilder<STATE | FrameIdSet>& setFrameId(const String& value)
                {
                    static_assert(!(STATE & FrameIdSet), "property frameId should not be set yet");
                    m_result->setFrameId(value);
                    return castState<FrameIdSet>();
                }

                RequestWillBeSentNotificationBuilder<STATE | LoaderIdSet>& setLoaderId(const String& value)
                {
                    static_assert(!(STATE & LoaderIdSet), "property loaderId should not be set yet");
                    m_result->setLoaderId(value);
                    return castState<LoaderIdSet>();
                }

                RequestWillBeSentNotificationBuilder<STATE | DocumentURLSet>& setDocumentURL(const String& value)
                {
                    static_assert(!(STATE & DocumentURLSet), "property documentURL should not be set yet");
                    m_result->setDocumentURL(value);
                    return castState<DocumentURLSet>();
                }

                RequestWillBeSentNotificationBuilder<STATE | RequestSet>& setRequest(std::unique_ptr<protocol::Network::Request> value)
                {
                    static_assert(!(STATE & RequestSet), "property request should not be set yet");
                    m_result->setRequest(std::move(value));
                    return castState<RequestSet>();
                }

                RequestWillBeSentNotificationBuilder<STATE | TimestampSet>& setTimestamp(double value)
                {
                    static_assert(!(STATE & TimestampSet), "property timestamp should not be set yet");
                    m_result->setTimestamp(value);
                    return castState<TimestampSet>();
                }

                RequestWillBeSentNotificationBuilder<STATE | WallTimeSet>& setWallTime(double value)
                {
                    static_assert(!(STATE & WallTimeSet), "property wallTime should not be set yet");
                    m_result->setWallTime(value);
                    return castState<WallTimeSet>();
                }

                RequestWillBeSentNotificationBuilder<STATE | InitiatorSet>& setInitiator(std::unique_ptr<protocol::Network::Initiator> value)
                {
                    static_assert(!(STATE & InitiatorSet), "property initiator should not be set yet");
                    m_result->setInitiator(std::move(value));
                    return castState<InitiatorSet>();
                }

                RequestWillBeSentNotificationBuilder<STATE>& setRedirectResponse(std::unique_ptr<protocol::Network::Response> value)
                {
                    m_result->setRedirectResponse(std::move(value));
                    return *this;
                }

                RequestWillBeSentNotificationBuilder<STATE>& setType(const String& value)
                {
                    m_result->setType(value);
                    return *this;
                }

                std::unique_ptr<RequestWillBeSentNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class RequestWillBeSentNotification;
                RequestWillBeSentNotificationBuilder()
                    : m_result(new RequestWillBeSentNotification())
                {
                }

                template <int STEP>
                RequestWillBeSentNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<RequestWillBeSentNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Network::RequestWillBeSentNotification> m_result;
            };

            static RequestWillBeSentNotificationBuilder<0> create()
            {
                return RequestWillBeSentNotificationBuilder<0>();
            }

        private:
            RequestWillBeSentNotification()
            {
                m_timestamp = 0;
                m_wallTime = 0;
            }

            String m_requestId;
            String m_frameId;
            String m_loaderId;
            String m_documentURL;
            std::unique_ptr<protocol::Network::Request> m_request;
            double m_timestamp;
            double m_wallTime;
            std::unique_ptr<protocol::Network::Initiator> m_initiator;
            Maybe<protocol::Network::Response> m_redirectResponse;
            Maybe<String> m_type;
        };

        // Wrapper for notification params
        class CORE_EXPORT RequestServedFromCacheNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(RequestServedFromCacheNotification);

        public:
            static std::unique_ptr<RequestServedFromCacheNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~RequestServedFromCacheNotification() override { }

            String getRequestId() { return m_requestId; }
            void setRequestId(const String& value) { m_requestId = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<RequestServedFromCacheNotification> clone() const;

            template <int STATE>
            class RequestServedFromCacheNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    RequestIdSet = 1 << 1,
                    AllFieldsSet = (RequestIdSet | 0)
                };

                RequestServedFromCacheNotificationBuilder<STATE | RequestIdSet>& setRequestId(const String& value)
                {
                    static_assert(!(STATE & RequestIdSet), "property requestId should not be set yet");
                    m_result->setRequestId(value);
                    return castState<RequestIdSet>();
                }

                std::unique_ptr<RequestServedFromCacheNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class RequestServedFromCacheNotification;
                RequestServedFromCacheNotificationBuilder()
                    : m_result(new RequestServedFromCacheNotification())
                {
                }

                template <int STEP>
                RequestServedFromCacheNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<RequestServedFromCacheNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Network::RequestServedFromCacheNotification> m_result;
            };

            static RequestServedFromCacheNotificationBuilder<0> create()
            {
                return RequestServedFromCacheNotificationBuilder<0>();
            }

        private:
            RequestServedFromCacheNotification()
            {
            }

            String m_requestId;
        };

        // Wrapper for notification params
        class CORE_EXPORT ResponseReceivedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(ResponseReceivedNotification);

        public:
            static std::unique_ptr<ResponseReceivedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~ResponseReceivedNotification() override { }

            String getRequestId() { return m_requestId; }
            void setRequestId(const String& value) { m_requestId = value; }

            String getFrameId() { return m_frameId; }
            void setFrameId(const String& value) { m_frameId = value; }

            String getLoaderId() { return m_loaderId; }
            void setLoaderId(const String& value) { m_loaderId = value; }

            double getTimestamp() { return m_timestamp; }
            void setTimestamp(double value) { m_timestamp = value; }

            String getType() { return m_type; }
            void setType(const String& value) { m_type = value; }

            protocol::Network::Response* getResponse() { return m_response.get(); }
            void setResponse(std::unique_ptr<protocol::Network::Response> value) { m_response = std::move(value); }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<ResponseReceivedNotification> clone() const;

            template <int STATE>
            class ResponseReceivedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    RequestIdSet = 1 << 1,
                    FrameIdSet = 1 << 2,
                    LoaderIdSet = 1 << 3,
                    TimestampSet = 1 << 4,
                    TypeSet = 1 << 5,
                    ResponseSet = 1 << 6,
                    AllFieldsSet = (RequestIdSet | FrameIdSet | LoaderIdSet | TimestampSet | TypeSet | ResponseSet | 0)
                };

                ResponseReceivedNotificationBuilder<STATE | RequestIdSet>& setRequestId(const String& value)
                {
                    static_assert(!(STATE & RequestIdSet), "property requestId should not be set yet");
                    m_result->setRequestId(value);
                    return castState<RequestIdSet>();
                }

                ResponseReceivedNotificationBuilder<STATE | FrameIdSet>& setFrameId(const String& value)
                {
                    static_assert(!(STATE & FrameIdSet), "property frameId should not be set yet");
                    m_result->setFrameId(value);
                    return castState<FrameIdSet>();
                }

                ResponseReceivedNotificationBuilder<STATE | LoaderIdSet>& setLoaderId(const String& value)
                {
                    static_assert(!(STATE & LoaderIdSet), "property loaderId should not be set yet");
                    m_result->setLoaderId(value);
                    return castState<LoaderIdSet>();
                }

                ResponseReceivedNotificationBuilder<STATE | TimestampSet>& setTimestamp(double value)
                {
                    static_assert(!(STATE & TimestampSet), "property timestamp should not be set yet");
                    m_result->setTimestamp(value);
                    return castState<TimestampSet>();
                }

                ResponseReceivedNotificationBuilder<STATE | TypeSet>& setType(const String& value)
                {
                    static_assert(!(STATE & TypeSet), "property type should not be set yet");
                    m_result->setType(value);
                    return castState<TypeSet>();
                }

                ResponseReceivedNotificationBuilder<STATE | ResponseSet>& setResponse(std::unique_ptr<protocol::Network::Response> value)
                {
                    static_assert(!(STATE & ResponseSet), "property response should not be set yet");
                    m_result->setResponse(std::move(value));
                    return castState<ResponseSet>();
                }

                std::unique_ptr<ResponseReceivedNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class ResponseReceivedNotification;
                ResponseReceivedNotificationBuilder()
                    : m_result(new ResponseReceivedNotification())
                {
                }

                template <int STEP>
                ResponseReceivedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<ResponseReceivedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Network::ResponseReceivedNotification> m_result;
            };

            static ResponseReceivedNotificationBuilder<0> create()
            {
                return ResponseReceivedNotificationBuilder<0>();
            }

        private:
            ResponseReceivedNotification()
            {
                m_timestamp = 0;
            }

            String m_requestId;
            String m_frameId;
            String m_loaderId;
            double m_timestamp;
            String m_type;
            std::unique_ptr<protocol::Network::Response> m_response;
        };

        // Wrapper for notification params
        class CORE_EXPORT DataReceivedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(DataReceivedNotification);

        public:
            static std::unique_ptr<DataReceivedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~DataReceivedNotification() override { }

            String getRequestId() { return m_requestId; }
            void setRequestId(const String& value) { m_requestId = value; }

            double getTimestamp() { return m_timestamp; }
            void setTimestamp(double value) { m_timestamp = value; }

            int getDataLength() { return m_dataLength; }
            void setDataLength(int value) { m_dataLength = value; }

            int getEncodedDataLength() { return m_encodedDataLength; }
            void setEncodedDataLength(int value) { m_encodedDataLength = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<DataReceivedNotification> clone() const;

            template <int STATE>
            class DataReceivedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    RequestIdSet = 1 << 1,
                    TimestampSet = 1 << 2,
                    DataLengthSet = 1 << 3,
                    EncodedDataLengthSet = 1 << 4,
                    AllFieldsSet = (RequestIdSet | TimestampSet | DataLengthSet | EncodedDataLengthSet | 0)
                };

                DataReceivedNotificationBuilder<STATE | RequestIdSet>& setRequestId(const String& value)
                {
                    static_assert(!(STATE & RequestIdSet), "property requestId should not be set yet");
                    m_result->setRequestId(value);
                    return castState<RequestIdSet>();
                }

                DataReceivedNotificationBuilder<STATE | TimestampSet>& setTimestamp(double value)
                {
                    static_assert(!(STATE & TimestampSet), "property timestamp should not be set yet");
                    m_result->setTimestamp(value);
                    return castState<TimestampSet>();
                }

                DataReceivedNotificationBuilder<STATE | DataLengthSet>& setDataLength(int value)
                {
                    static_assert(!(STATE & DataLengthSet), "property dataLength should not be set yet");
                    m_result->setDataLength(value);
                    return castState<DataLengthSet>();
                }

                DataReceivedNotificationBuilder<STATE | EncodedDataLengthSet>& setEncodedDataLength(int value)
                {
                    static_assert(!(STATE & EncodedDataLengthSet), "property encodedDataLength should not be set yet");
                    m_result->setEncodedDataLength(value);
                    return castState<EncodedDataLengthSet>();
                }

                std::unique_ptr<DataReceivedNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class DataReceivedNotification;
                DataReceivedNotificationBuilder()
                    : m_result(new DataReceivedNotification())
                {
                }

                template <int STEP>
                DataReceivedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<DataReceivedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Network::DataReceivedNotification> m_result;
            };

            static DataReceivedNotificationBuilder<0> create()
            {
                return DataReceivedNotificationBuilder<0>();
            }

        private:
            DataReceivedNotification()
            {
                m_timestamp = 0;
                m_dataLength = 0;
                m_encodedDataLength = 0;
            }

            String m_requestId;
            double m_timestamp;
            int m_dataLength;
            int m_encodedDataLength;
        };

        // Wrapper for notification params
        class CORE_EXPORT LoadingFinishedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(LoadingFinishedNotification);

        public:
            static std::unique_ptr<LoadingFinishedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~LoadingFinishedNotification() override { }

            String getRequestId() { return m_requestId; }
            void setRequestId(const String& value) { m_requestId = value; }

            double getTimestamp() { return m_timestamp; }
            void setTimestamp(double value) { m_timestamp = value; }

            double getEncodedDataLength() { return m_encodedDataLength; }
            void setEncodedDataLength(double value) { m_encodedDataLength = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<LoadingFinishedNotification> clone() const;

            template <int STATE>
            class LoadingFinishedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    RequestIdSet = 1 << 1,
                    TimestampSet = 1 << 2,
                    EncodedDataLengthSet = 1 << 3,
                    AllFieldsSet = (RequestIdSet | TimestampSet | EncodedDataLengthSet | 0)
                };

                LoadingFinishedNotificationBuilder<STATE | RequestIdSet>& setRequestId(const String& value)
                {
                    static_assert(!(STATE & RequestIdSet), "property requestId should not be set yet");
                    m_result->setRequestId(value);
                    return castState<RequestIdSet>();
                }

                LoadingFinishedNotificationBuilder<STATE | TimestampSet>& setTimestamp(double value)
                {
                    static_assert(!(STATE & TimestampSet), "property timestamp should not be set yet");
                    m_result->setTimestamp(value);
                    return castState<TimestampSet>();
                }

                LoadingFinishedNotificationBuilder<STATE | EncodedDataLengthSet>& setEncodedDataLength(double value)
                {
                    static_assert(!(STATE & EncodedDataLengthSet), "property encodedDataLength should not be set yet");
                    m_result->setEncodedDataLength(value);
                    return castState<EncodedDataLengthSet>();
                }

                std::unique_ptr<LoadingFinishedNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class LoadingFinishedNotification;
                LoadingFinishedNotificationBuilder()
                    : m_result(new LoadingFinishedNotification())
                {
                }

                template <int STEP>
                LoadingFinishedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<LoadingFinishedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Network::LoadingFinishedNotification> m_result;
            };

            static LoadingFinishedNotificationBuilder<0> create()
            {
                return LoadingFinishedNotificationBuilder<0>();
            }

        private:
            LoadingFinishedNotification()
            {
                m_timestamp = 0;
                m_encodedDataLength = 0;
            }

            String m_requestId;
            double m_timestamp;
            double m_encodedDataLength;
        };

        // Wrapper for notification params
        class CORE_EXPORT LoadingFailedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(LoadingFailedNotification);

        public:
            static std::unique_ptr<LoadingFailedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~LoadingFailedNotification() override { }

            String getRequestId() { return m_requestId; }
            void setRequestId(const String& value) { m_requestId = value; }

            double getTimestamp() { return m_timestamp; }
            void setTimestamp(double value) { m_timestamp = value; }

            String getType() { return m_type; }
            void setType(const String& value) { m_type = value; }

            String getErrorText() { return m_errorText; }
            void setErrorText(const String& value) { m_errorText = value; }

            bool hasCanceled() { return m_canceled.isJust(); }
            bool getCanceled(bool defaultValue) { return m_canceled.isJust() ? m_canceled.fromJust() : defaultValue; }
            void setCanceled(bool value) { m_canceled = value; }

            bool hasBlockedReason() { return m_blockedReason.isJust(); }
            String getBlockedReason(const String& defaultValue) { return m_blockedReason.isJust() ? m_blockedReason.fromJust() : defaultValue; }
            void setBlockedReason(const String& value) { m_blockedReason = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<LoadingFailedNotification> clone() const;

            template <int STATE>
            class LoadingFailedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    RequestIdSet = 1 << 1,
                    TimestampSet = 1 << 2,
                    TypeSet = 1 << 3,
                    ErrorTextSet = 1 << 4,
                    AllFieldsSet = (RequestIdSet | TimestampSet | TypeSet | ErrorTextSet | 0)
                };

                LoadingFailedNotificationBuilder<STATE | RequestIdSet>& setRequestId(const String& value)
                {
                    static_assert(!(STATE & RequestIdSet), "property requestId should not be set yet");
                    m_result->setRequestId(value);
                    return castState<RequestIdSet>();
                }

                LoadingFailedNotificationBuilder<STATE | TimestampSet>& setTimestamp(double value)
                {
                    static_assert(!(STATE & TimestampSet), "property timestamp should not be set yet");
                    m_result->setTimestamp(value);
                    return castState<TimestampSet>();
                }

                LoadingFailedNotificationBuilder<STATE | TypeSet>& setType(const String& value)
                {
                    static_assert(!(STATE & TypeSet), "property type should not be set yet");
                    m_result->setType(value);
                    return castState<TypeSet>();
                }

                LoadingFailedNotificationBuilder<STATE | ErrorTextSet>& setErrorText(const String& value)
                {
                    static_assert(!(STATE & ErrorTextSet), "property errorText should not be set yet");
                    m_result->setErrorText(value);
                    return castState<ErrorTextSet>();
                }

                LoadingFailedNotificationBuilder<STATE>& setCanceled(bool value)
                {
                    m_result->setCanceled(value);
                    return *this;
                }

                LoadingFailedNotificationBuilder<STATE>& setBlockedReason(const String& value)
                {
                    m_result->setBlockedReason(value);
                    return *this;
                }

                std::unique_ptr<LoadingFailedNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class LoadingFailedNotification;
                LoadingFailedNotificationBuilder()
                    : m_result(new LoadingFailedNotification())
                {
                }

                template <int STEP>
                LoadingFailedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<LoadingFailedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Network::LoadingFailedNotification> m_result;
            };

            static LoadingFailedNotificationBuilder<0> create()
            {
                return LoadingFailedNotificationBuilder<0>();
            }

        private:
            LoadingFailedNotification()
            {
                m_timestamp = 0;
            }

            String m_requestId;
            double m_timestamp;
            String m_type;
            String m_errorText;
            Maybe<bool> m_canceled;
            Maybe<String> m_blockedReason;
        };

        // Wrapper for notification params
        class CORE_EXPORT WebSocketWillSendHandshakeRequestNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(WebSocketWillSendHandshakeRequestNotification);

        public:
            static std::unique_ptr<WebSocketWillSendHandshakeRequestNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~WebSocketWillSendHandshakeRequestNotification() override { }

            String getRequestId() { return m_requestId; }
            void setRequestId(const String& value) { m_requestId = value; }

            double getTimestamp() { return m_timestamp; }
            void setTimestamp(double value) { m_timestamp = value; }

            double getWallTime() { return m_wallTime; }
            void setWallTime(double value) { m_wallTime = value; }

            protocol::Network::WebSocketRequest* getRequest() { return m_request.get(); }
            void setRequest(std::unique_ptr<protocol::Network::WebSocketRequest> value) { m_request = std::move(value); }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<WebSocketWillSendHandshakeRequestNotification> clone() const;

            template <int STATE>
            class WebSocketWillSendHandshakeRequestNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    RequestIdSet = 1 << 1,
                    TimestampSet = 1 << 2,
                    WallTimeSet = 1 << 3,
                    RequestSet = 1 << 4,
                    AllFieldsSet = (RequestIdSet | TimestampSet | WallTimeSet | RequestSet | 0)
                };

                WebSocketWillSendHandshakeRequestNotificationBuilder<STATE | RequestIdSet>& setRequestId(const String& value)
                {
                    static_assert(!(STATE & RequestIdSet), "property requestId should not be set yet");
                    m_result->setRequestId(value);
                    return castState<RequestIdSet>();
                }

                WebSocketWillSendHandshakeRequestNotificationBuilder<STATE | TimestampSet>& setTimestamp(double value)
                {
                    static_assert(!(STATE & TimestampSet), "property timestamp should not be set yet");
                    m_result->setTimestamp(value);
                    return castState<TimestampSet>();
                }

                WebSocketWillSendHandshakeRequestNotificationBuilder<STATE | WallTimeSet>& setWallTime(double value)
                {
                    static_assert(!(STATE & WallTimeSet), "property wallTime should not be set yet");
                    m_result->setWallTime(value);
                    return castState<WallTimeSet>();
                }

                WebSocketWillSendHandshakeRequestNotificationBuilder<STATE | RequestSet>& setRequest(std::unique_ptr<protocol::Network::WebSocketRequest> value)
                {
                    static_assert(!(STATE & RequestSet), "property request should not be set yet");
                    m_result->setRequest(std::move(value));
                    return castState<RequestSet>();
                }

                std::unique_ptr<WebSocketWillSendHandshakeRequestNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class WebSocketWillSendHandshakeRequestNotification;
                WebSocketWillSendHandshakeRequestNotificationBuilder()
                    : m_result(new WebSocketWillSendHandshakeRequestNotification())
                {
                }

                template <int STEP>
                WebSocketWillSendHandshakeRequestNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<WebSocketWillSendHandshakeRequestNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Network::WebSocketWillSendHandshakeRequestNotification> m_result;
            };

            static WebSocketWillSendHandshakeRequestNotificationBuilder<0> create()
            {
                return WebSocketWillSendHandshakeRequestNotificationBuilder<0>();
            }

        private:
            WebSocketWillSendHandshakeRequestNotification()
            {
                m_timestamp = 0;
                m_wallTime = 0;
            }

            String m_requestId;
            double m_timestamp;
            double m_wallTime;
            std::unique_ptr<protocol::Network::WebSocketRequest> m_request;
        };

        // Wrapper for notification params
        class CORE_EXPORT WebSocketHandshakeResponseReceivedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(WebSocketHandshakeResponseReceivedNotification);

        public:
            static std::unique_ptr<WebSocketHandshakeResponseReceivedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~WebSocketHandshakeResponseReceivedNotification() override { }

            String getRequestId() { return m_requestId; }
            void setRequestId(const String& value) { m_requestId = value; }

            double getTimestamp() { return m_timestamp; }
            void setTimestamp(double value) { m_timestamp = value; }

            protocol::Network::WebSocketResponse* getResponse() { return m_response.get(); }
            void setResponse(std::unique_ptr<protocol::Network::WebSocketResponse> value) { m_response = std::move(value); }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<WebSocketHandshakeResponseReceivedNotification> clone() const;

            template <int STATE>
            class WebSocketHandshakeResponseReceivedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    RequestIdSet = 1 << 1,
                    TimestampSet = 1 << 2,
                    ResponseSet = 1 << 3,
                    AllFieldsSet = (RequestIdSet | TimestampSet | ResponseSet | 0)
                };

                WebSocketHandshakeResponseReceivedNotificationBuilder<STATE | RequestIdSet>& setRequestId(const String& value)
                {
                    static_assert(!(STATE & RequestIdSet), "property requestId should not be set yet");
                    m_result->setRequestId(value);
                    return castState<RequestIdSet>();
                }

                WebSocketHandshakeResponseReceivedNotificationBuilder<STATE | TimestampSet>& setTimestamp(double value)
                {
                    static_assert(!(STATE & TimestampSet), "property timestamp should not be set yet");
                    m_result->setTimestamp(value);
                    return castState<TimestampSet>();
                }

                WebSocketHandshakeResponseReceivedNotificationBuilder<STATE | ResponseSet>& setResponse(std::unique_ptr<protocol::Network::WebSocketResponse> value)
                {
                    static_assert(!(STATE & ResponseSet), "property response should not be set yet");
                    m_result->setResponse(std::move(value));
                    return castState<ResponseSet>();
                }

                std::unique_ptr<WebSocketHandshakeResponseReceivedNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class WebSocketHandshakeResponseReceivedNotification;
                WebSocketHandshakeResponseReceivedNotificationBuilder()
                    : m_result(new WebSocketHandshakeResponseReceivedNotification())
                {
                }

                template <int STEP>
                WebSocketHandshakeResponseReceivedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<WebSocketHandshakeResponseReceivedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Network::WebSocketHandshakeResponseReceivedNotification> m_result;
            };

            static WebSocketHandshakeResponseReceivedNotificationBuilder<0> create()
            {
                return WebSocketHandshakeResponseReceivedNotificationBuilder<0>();
            }

        private:
            WebSocketHandshakeResponseReceivedNotification()
            {
                m_timestamp = 0;
            }

            String m_requestId;
            double m_timestamp;
            std::unique_ptr<protocol::Network::WebSocketResponse> m_response;
        };

        // Wrapper for notification params
        class CORE_EXPORT WebSocketCreatedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(WebSocketCreatedNotification);

        public:
            static std::unique_ptr<WebSocketCreatedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~WebSocketCreatedNotification() override { }

            String getRequestId() { return m_requestId; }
            void setRequestId(const String& value) { m_requestId = value; }

            String getUrl() { return m_url; }
            void setUrl(const String& value) { m_url = value; }

            bool hasInitiator() { return m_initiator.isJust(); }
            protocol::Network::Initiator* getInitiator(protocol::Network::Initiator* defaultValue) { return m_initiator.isJust() ? m_initiator.fromJust() : defaultValue; }
            void setInitiator(std::unique_ptr<protocol::Network::Initiator> value) { m_initiator = std::move(value); }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<WebSocketCreatedNotification> clone() const;

            template <int STATE>
            class WebSocketCreatedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    RequestIdSet = 1 << 1,
                    UrlSet = 1 << 2,
                    AllFieldsSet = (RequestIdSet | UrlSet | 0)
                };

                WebSocketCreatedNotificationBuilder<STATE | RequestIdSet>& setRequestId(const String& value)
                {
                    static_assert(!(STATE & RequestIdSet), "property requestId should not be set yet");
                    m_result->setRequestId(value);
                    return castState<RequestIdSet>();
                }

                WebSocketCreatedNotificationBuilder<STATE | UrlSet>& setUrl(const String& value)
                {
                    static_assert(!(STATE & UrlSet), "property url should not be set yet");
                    m_result->setUrl(value);
                    return castState<UrlSet>();
                }

                WebSocketCreatedNotificationBuilder<STATE>& setInitiator(std::unique_ptr<protocol::Network::Initiator> value)
                {
                    m_result->setInitiator(std::move(value));
                    return *this;
                }

                std::unique_ptr<WebSocketCreatedNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class WebSocketCreatedNotification;
                WebSocketCreatedNotificationBuilder()
                    : m_result(new WebSocketCreatedNotification())
                {
                }

                template <int STEP>
                WebSocketCreatedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<WebSocketCreatedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Network::WebSocketCreatedNotification> m_result;
            };

            static WebSocketCreatedNotificationBuilder<0> create()
            {
                return WebSocketCreatedNotificationBuilder<0>();
            }

        private:
            WebSocketCreatedNotification()
            {
            }

            String m_requestId;
            String m_url;
            Maybe<protocol::Network::Initiator> m_initiator;
        };

        // Wrapper for notification params
        class CORE_EXPORT WebSocketClosedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(WebSocketClosedNotification);

        public:
            static std::unique_ptr<WebSocketClosedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~WebSocketClosedNotification() override { }

            String getRequestId() { return m_requestId; }
            void setRequestId(const String& value) { m_requestId = value; }

            double getTimestamp() { return m_timestamp; }
            void setTimestamp(double value) { m_timestamp = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<WebSocketClosedNotification> clone() const;

            template <int STATE>
            class WebSocketClosedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    RequestIdSet = 1 << 1,
                    TimestampSet = 1 << 2,
                    AllFieldsSet = (RequestIdSet | TimestampSet | 0)
                };

                WebSocketClosedNotificationBuilder<STATE | RequestIdSet>& setRequestId(const String& value)
                {
                    static_assert(!(STATE & RequestIdSet), "property requestId should not be set yet");
                    m_result->setRequestId(value);
                    return castState<RequestIdSet>();
                }

                WebSocketClosedNotificationBuilder<STATE | TimestampSet>& setTimestamp(double value)
                {
                    static_assert(!(STATE & TimestampSet), "property timestamp should not be set yet");
                    m_result->setTimestamp(value);
                    return castState<TimestampSet>();
                }

                std::unique_ptr<WebSocketClosedNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class WebSocketClosedNotification;
                WebSocketClosedNotificationBuilder()
                    : m_result(new WebSocketClosedNotification())
                {
                }

                template <int STEP>
                WebSocketClosedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<WebSocketClosedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Network::WebSocketClosedNotification> m_result;
            };

            static WebSocketClosedNotificationBuilder<0> create()
            {
                return WebSocketClosedNotificationBuilder<0>();
            }

        private:
            WebSocketClosedNotification()
            {
                m_timestamp = 0;
            }

            String m_requestId;
            double m_timestamp;
        };

        // Wrapper for notification params
        class CORE_EXPORT WebSocketFrameReceivedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(WebSocketFrameReceivedNotification);

        public:
            static std::unique_ptr<WebSocketFrameReceivedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~WebSocketFrameReceivedNotification() override { }

            String getRequestId() { return m_requestId; }
            void setRequestId(const String& value) { m_requestId = value; }

            double getTimestamp() { return m_timestamp; }
            void setTimestamp(double value) { m_timestamp = value; }

            protocol::Network::WebSocketFrame* getResponse() { return m_response.get(); }
            void setResponse(std::unique_ptr<protocol::Network::WebSocketFrame> value) { m_response = std::move(value); }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<WebSocketFrameReceivedNotification> clone() const;

            template <int STATE>
            class WebSocketFrameReceivedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    RequestIdSet = 1 << 1,
                    TimestampSet = 1 << 2,
                    ResponseSet = 1 << 3,
                    AllFieldsSet = (RequestIdSet | TimestampSet | ResponseSet | 0)
                };

                WebSocketFrameReceivedNotificationBuilder<STATE | RequestIdSet>& setRequestId(const String& value)
                {
                    static_assert(!(STATE & RequestIdSet), "property requestId should not be set yet");
                    m_result->setRequestId(value);
                    return castState<RequestIdSet>();
                }

                WebSocketFrameReceivedNotificationBuilder<STATE | TimestampSet>& setTimestamp(double value)
                {
                    static_assert(!(STATE & TimestampSet), "property timestamp should not be set yet");
                    m_result->setTimestamp(value);
                    return castState<TimestampSet>();
                }

                WebSocketFrameReceivedNotificationBuilder<STATE | ResponseSet>& setResponse(std::unique_ptr<protocol::Network::WebSocketFrame> value)
                {
                    static_assert(!(STATE & ResponseSet), "property response should not be set yet");
                    m_result->setResponse(std::move(value));
                    return castState<ResponseSet>();
                }

                std::unique_ptr<WebSocketFrameReceivedNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class WebSocketFrameReceivedNotification;
                WebSocketFrameReceivedNotificationBuilder()
                    : m_result(new WebSocketFrameReceivedNotification())
                {
                }

                template <int STEP>
                WebSocketFrameReceivedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<WebSocketFrameReceivedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Network::WebSocketFrameReceivedNotification> m_result;
            };

            static WebSocketFrameReceivedNotificationBuilder<0> create()
            {
                return WebSocketFrameReceivedNotificationBuilder<0>();
            }

        private:
            WebSocketFrameReceivedNotification()
            {
                m_timestamp = 0;
            }

            String m_requestId;
            double m_timestamp;
            std::unique_ptr<protocol::Network::WebSocketFrame> m_response;
        };

        // Wrapper for notification params
        class CORE_EXPORT WebSocketFrameErrorNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(WebSocketFrameErrorNotification);

        public:
            static std::unique_ptr<WebSocketFrameErrorNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~WebSocketFrameErrorNotification() override { }

            String getRequestId() { return m_requestId; }
            void setRequestId(const String& value) { m_requestId = value; }

            double getTimestamp() { return m_timestamp; }
            void setTimestamp(double value) { m_timestamp = value; }

            String getErrorMessage() { return m_errorMessage; }
            void setErrorMessage(const String& value) { m_errorMessage = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<WebSocketFrameErrorNotification> clone() const;

            template <int STATE>
            class WebSocketFrameErrorNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    RequestIdSet = 1 << 1,
                    TimestampSet = 1 << 2,
                    ErrorMessageSet = 1 << 3,
                    AllFieldsSet = (RequestIdSet | TimestampSet | ErrorMessageSet | 0)
                };

                WebSocketFrameErrorNotificationBuilder<STATE | RequestIdSet>& setRequestId(const String& value)
                {
                    static_assert(!(STATE & RequestIdSet), "property requestId should not be set yet");
                    m_result->setRequestId(value);
                    return castState<RequestIdSet>();
                }

                WebSocketFrameErrorNotificationBuilder<STATE | TimestampSet>& setTimestamp(double value)
                {
                    static_assert(!(STATE & TimestampSet), "property timestamp should not be set yet");
                    m_result->setTimestamp(value);
                    return castState<TimestampSet>();
                }

                WebSocketFrameErrorNotificationBuilder<STATE | ErrorMessageSet>& setErrorMessage(const String& value)
                {
                    static_assert(!(STATE & ErrorMessageSet), "property errorMessage should not be set yet");
                    m_result->setErrorMessage(value);
                    return castState<ErrorMessageSet>();
                }

                std::unique_ptr<WebSocketFrameErrorNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class WebSocketFrameErrorNotification;
                WebSocketFrameErrorNotificationBuilder()
                    : m_result(new WebSocketFrameErrorNotification())
                {
                }

                template <int STEP>
                WebSocketFrameErrorNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<WebSocketFrameErrorNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Network::WebSocketFrameErrorNotification> m_result;
            };

            static WebSocketFrameErrorNotificationBuilder<0> create()
            {
                return WebSocketFrameErrorNotificationBuilder<0>();
            }

        private:
            WebSocketFrameErrorNotification()
            {
                m_timestamp = 0;
            }

            String m_requestId;
            double m_timestamp;
            String m_errorMessage;
        };

        // Wrapper for notification params
        class CORE_EXPORT WebSocketFrameSentNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(WebSocketFrameSentNotification);

        public:
            static std::unique_ptr<WebSocketFrameSentNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~WebSocketFrameSentNotification() override { }

            String getRequestId() { return m_requestId; }
            void setRequestId(const String& value) { m_requestId = value; }

            double getTimestamp() { return m_timestamp; }
            void setTimestamp(double value) { m_timestamp = value; }

            protocol::Network::WebSocketFrame* getResponse() { return m_response.get(); }
            void setResponse(std::unique_ptr<protocol::Network::WebSocketFrame> value) { m_response = std::move(value); }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<WebSocketFrameSentNotification> clone() const;

            template <int STATE>
            class WebSocketFrameSentNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    RequestIdSet = 1 << 1,
                    TimestampSet = 1 << 2,
                    ResponseSet = 1 << 3,
                    AllFieldsSet = (RequestIdSet | TimestampSet | ResponseSet | 0)
                };

                WebSocketFrameSentNotificationBuilder<STATE | RequestIdSet>& setRequestId(const String& value)
                {
                    static_assert(!(STATE & RequestIdSet), "property requestId should not be set yet");
                    m_result->setRequestId(value);
                    return castState<RequestIdSet>();
                }

                WebSocketFrameSentNotificationBuilder<STATE | TimestampSet>& setTimestamp(double value)
                {
                    static_assert(!(STATE & TimestampSet), "property timestamp should not be set yet");
                    m_result->setTimestamp(value);
                    return castState<TimestampSet>();
                }

                WebSocketFrameSentNotificationBuilder<STATE | ResponseSet>& setResponse(std::unique_ptr<protocol::Network::WebSocketFrame> value)
                {
                    static_assert(!(STATE & ResponseSet), "property response should not be set yet");
                    m_result->setResponse(std::move(value));
                    return castState<ResponseSet>();
                }

                std::unique_ptr<WebSocketFrameSentNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class WebSocketFrameSentNotification;
                WebSocketFrameSentNotificationBuilder()
                    : m_result(new WebSocketFrameSentNotification())
                {
                }

                template <int STEP>
                WebSocketFrameSentNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<WebSocketFrameSentNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Network::WebSocketFrameSentNotification> m_result;
            };

            static WebSocketFrameSentNotificationBuilder<0> create()
            {
                return WebSocketFrameSentNotificationBuilder<0>();
            }

        private:
            WebSocketFrameSentNotification()
            {
                m_timestamp = 0;
            }

            String m_requestId;
            double m_timestamp;
            std::unique_ptr<protocol::Network::WebSocketFrame> m_response;
        };

        // Wrapper for notification params
        class CORE_EXPORT EventSourceMessageReceivedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(EventSourceMessageReceivedNotification);

        public:
            static std::unique_ptr<EventSourceMessageReceivedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~EventSourceMessageReceivedNotification() override { }

            String getRequestId() { return m_requestId; }
            void setRequestId(const String& value) { m_requestId = value; }

            double getTimestamp() { return m_timestamp; }
            void setTimestamp(double value) { m_timestamp = value; }

            String getEventName() { return m_eventName; }
            void setEventName(const String& value) { m_eventName = value; }

            String getEventId() { return m_eventId; }
            void setEventId(const String& value) { m_eventId = value; }

            String getData() { return m_data; }
            void setData(const String& value) { m_data = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<EventSourceMessageReceivedNotification> clone() const;

            template <int STATE>
            class EventSourceMessageReceivedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    RequestIdSet = 1 << 1,
                    TimestampSet = 1 << 2,
                    EventNameSet = 1 << 3,
                    EventIdSet = 1 << 4,
                    DataSet = 1 << 5,
                    AllFieldsSet = (RequestIdSet | TimestampSet | EventNameSet | EventIdSet | DataSet | 0)
                };

                EventSourceMessageReceivedNotificationBuilder<STATE | RequestIdSet>& setRequestId(const String& value)
                {
                    static_assert(!(STATE & RequestIdSet), "property requestId should not be set yet");
                    m_result->setRequestId(value);
                    return castState<RequestIdSet>();
                }

                EventSourceMessageReceivedNotificationBuilder<STATE | TimestampSet>& setTimestamp(double value)
                {
                    static_assert(!(STATE & TimestampSet), "property timestamp should not be set yet");
                    m_result->setTimestamp(value);
                    return castState<TimestampSet>();
                }

                EventSourceMessageReceivedNotificationBuilder<STATE | EventNameSet>& setEventName(const String& value)
                {
                    static_assert(!(STATE & EventNameSet), "property eventName should not be set yet");
                    m_result->setEventName(value);
                    return castState<EventNameSet>();
                }

                EventSourceMessageReceivedNotificationBuilder<STATE | EventIdSet>& setEventId(const String& value)
                {
                    static_assert(!(STATE & EventIdSet), "property eventId should not be set yet");
                    m_result->setEventId(value);
                    return castState<EventIdSet>();
                }

                EventSourceMessageReceivedNotificationBuilder<STATE | DataSet>& setData(const String& value)
                {
                    static_assert(!(STATE & DataSet), "property data should not be set yet");
                    m_result->setData(value);
                    return castState<DataSet>();
                }

                std::unique_ptr<EventSourceMessageReceivedNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class EventSourceMessageReceivedNotification;
                EventSourceMessageReceivedNotificationBuilder()
                    : m_result(new EventSourceMessageReceivedNotification())
                {
                }

                template <int STEP>
                EventSourceMessageReceivedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<EventSourceMessageReceivedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Network::EventSourceMessageReceivedNotification> m_result;
            };

            static EventSourceMessageReceivedNotificationBuilder<0> create()
            {
                return EventSourceMessageReceivedNotificationBuilder<0>();
            }

        private:
            EventSourceMessageReceivedNotification()
            {
                m_timestamp = 0;
            }

            String m_requestId;
            double m_timestamp;
            String m_eventName;
            String m_eventId;
            String m_data;
        };

        // ------------- Backend interface.

        class CORE_EXPORT Backend {
        public:
            virtual ~Backend() { }

            virtual DispatchResponse enable(Maybe<int> in_maxTotalBufferSize, Maybe<int> in_maxResourceBufferSize) = 0;
            virtual DispatchResponse disable() = 0;
            virtual DispatchResponse setUserAgentOverride(const String& in_userAgent) = 0;
            virtual DispatchResponse setExtraHTTPHeaders(std::unique_ptr<protocol::Network::Headers> in_headers) = 0;
            class CORE_EXPORT GetResponseBodyCallback {
            public:
                virtual void sendSuccess(const String& body, bool base64Encoded) = 0;
                virtual void sendFailure(const DispatchResponse&) = 0;
                virtual void fallThrough() = 0;
                virtual ~GetResponseBodyCallback() { }
            };
            virtual void getResponseBody(const String& in_requestId, std::unique_ptr<GetResponseBodyCallback> callback) = 0;
            virtual DispatchResponse addBlockedURL(const String& in_url) = 0;
            virtual DispatchResponse removeBlockedURL(const String& in_url) = 0;
            virtual DispatchResponse replayXHR(const String& in_requestId) = 0;
            virtual DispatchResponse setMonitoringXHREnabled(bool in_enabled) = 0;
            virtual DispatchResponse canClearBrowserCache(bool* out_result) = 0;
            virtual DispatchResponse canClearBrowserCookies(bool* out_result) = 0;
            virtual DispatchResponse emulateNetworkConditions(bool in_offline, double in_latency, double in_downloadThroughput, double in_uploadThroughput, Maybe<String> in_connectionType) = 0;
            virtual DispatchResponse setCacheDisabled(bool in_cacheDisabled) = 0;
            virtual DispatchResponse setBypassServiceWorker(bool in_bypass) = 0;
            virtual DispatchResponse setDataSizeLimitsForTest(int in_maxTotalSize, int in_maxResourceSize) = 0;
            virtual DispatchResponse getCertificate(const String& in_origin, std::unique_ptr<protocol::Array<String>>* out_tableNames) = 0;
        };

        // ------------- Frontend interface.

        class CORE_EXPORT Frontend {
        public:
            explicit Frontend(FrontendChannel* frontendChannel)
                : m_frontendChannel(frontendChannel)
            {
            }
            void resourceChangedPriority(const String& requestId, const String& newPriority, double timestamp);
            void requestWillBeSent(const String& requestId, const String& frameId, const String& loaderId, const String& documentURL, std::unique_ptr<protocol::Network::Request> request, double timestamp, double wallTime, std::unique_ptr<protocol::Network::Initiator> initiator, Maybe<protocol::Network::Response> redirectResponse = Maybe<protocol::Network::Response>(), Maybe<String> type = Maybe<String>());
            void requestServedFromCache(const String& requestId);
            void responseReceived(const String& requestId, const String& frameId, const String& loaderId, double timestamp, const String& type, std::unique_ptr<protocol::Network::Response> response);
            void dataReceived(const String& requestId, double timestamp, int dataLength, int encodedDataLength);
            void loadingFinished(const String& requestId, double timestamp, double encodedDataLength);
            void loadingFailed(const String& requestId, double timestamp, const String& type, const String& errorText, Maybe<bool> canceled = Maybe<bool>(), Maybe<String> blockedReason = Maybe<String>());
            void webSocketWillSendHandshakeRequest(const String& requestId, double timestamp, double wallTime, std::unique_ptr<protocol::Network::WebSocketRequest> request);
            void webSocketHandshakeResponseReceived(const String& requestId, double timestamp, std::unique_ptr<protocol::Network::WebSocketResponse> response);
            void webSocketCreated(const String& requestId, const String& url, Maybe<protocol::Network::Initiator> initiator = Maybe<protocol::Network::Initiator>());
            void webSocketClosed(const String& requestId, double timestamp);
            void webSocketFrameReceived(const String& requestId, double timestamp, std::unique_ptr<protocol::Network::WebSocketFrame> response);
            void webSocketFrameError(const String& requestId, double timestamp, const String& errorMessage);
            void webSocketFrameSent(const String& requestId, double timestamp, std::unique_ptr<protocol::Network::WebSocketFrame> response);
            void eventSourceMessageReceived(const String& requestId, double timestamp, const String& eventName, const String& eventId, const String& data);

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

    } // namespace Network
} // namespace blink
} // namespace protocol

#endif // !defined(blink_protocol_Network_h)
