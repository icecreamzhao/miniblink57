// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef content_protocol_Network_h
#define content_protocol_Network_h

#include "content/browser/devtools/protocol/protocol.h"
#include "content/common/content_export.h"
// For each imported domain we generate a ValueConversions struct instead of a full domain definition
// and include Domain::API version from there.
#include "content/browser/devtools/protocol/security.h"

namespace content {
namespace protocol {
    namespace Network {

        // ------------- Forward and enum declarations.
        // Represents the cookie's 'SameSite' status: https://tools.ietf.org/html/draft-west-first-party-cookies
        using CookieSameSite = String;
        // Cookie object
        class Cookie;

        namespace CookieSameSiteEnum {
            CONTENT_EXPORT extern const char* Strict;
            CONTENT_EXPORT extern const char* Lax;
        } // namespace CookieSameSiteEnum

        // ------------- Type and builder declarations.

        // Cookie object
        class CONTENT_EXPORT Cookie : public Serializable {
            PROTOCOL_DISALLOW_COPY(Cookie);

        public:
            static std::unique_ptr<Cookie> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~Cookie() override { }

            String GetName() { return m_name; }
            void SetName(const String& value) { m_name = value; }

            String GetValue() { return m_value; }
            void SetValue(const String& value) { m_value = value; }

            String GetDomain() { return m_domain; }
            void SetDomain(const String& value) { m_domain = value; }

            String GetPath() { return m_path; }
            void SetPath(const String& value) { m_path = value; }

            double GetExpires() { return m_expires; }
            void SetExpires(double value) { m_expires = value; }

            int GetSize() { return m_size; }
            void SetSize(int value) { m_size = value; }

            bool GetHttpOnly() { return m_httpOnly; }
            void SetHttpOnly(bool value) { m_httpOnly = value; }

            bool GetSecure() { return m_secure; }
            void SetSecure(bool value) { m_secure = value; }

            bool GetSession() { return m_session; }
            void SetSession(bool value) { m_session = value; }

            bool HasSameSite() { return m_sameSite.isJust(); }
            String GetSameSite(const String& defaultValue) { return m_sameSite.isJust() ? m_sameSite.fromJust() : defaultValue; }
            void SetSameSite(const String& value) { m_sameSite = value; }

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

                CookieBuilder<STATE | NameSet>& SetName(const String& value)
                {
                    static_assert(!(STATE & NameSet), "property name should not be set yet");
                    m_result->SetName(value);
                    return castState<NameSet>();
                }

                CookieBuilder<STATE | ValueSet>& SetValue(const String& value)
                {
                    static_assert(!(STATE & ValueSet), "property value should not be set yet");
                    m_result->SetValue(value);
                    return castState<ValueSet>();
                }

                CookieBuilder<STATE | DomainSet>& SetDomain(const String& value)
                {
                    static_assert(!(STATE & DomainSet), "property domain should not be set yet");
                    m_result->SetDomain(value);
                    return castState<DomainSet>();
                }

                CookieBuilder<STATE | PathSet>& SetPath(const String& value)
                {
                    static_assert(!(STATE & PathSet), "property path should not be set yet");
                    m_result->SetPath(value);
                    return castState<PathSet>();
                }

                CookieBuilder<STATE | ExpiresSet>& SetExpires(double value)
                {
                    static_assert(!(STATE & ExpiresSet), "property expires should not be set yet");
                    m_result->SetExpires(value);
                    return castState<ExpiresSet>();
                }

                CookieBuilder<STATE | SizeSet>& SetSize(int value)
                {
                    static_assert(!(STATE & SizeSet), "property size should not be set yet");
                    m_result->SetSize(value);
                    return castState<SizeSet>();
                }

                CookieBuilder<STATE | HttpOnlySet>& SetHttpOnly(bool value)
                {
                    static_assert(!(STATE & HttpOnlySet), "property httpOnly should not be set yet");
                    m_result->SetHttpOnly(value);
                    return castState<HttpOnlySet>();
                }

                CookieBuilder<STATE | SecureSet>& SetSecure(bool value)
                {
                    static_assert(!(STATE & SecureSet), "property secure should not be set yet");
                    m_result->SetSecure(value);
                    return castState<SecureSet>();
                }

                CookieBuilder<STATE | SessionSet>& SetSession(bool value)
                {
                    static_assert(!(STATE & SessionSet), "property session should not be set yet");
                    m_result->SetSession(value);
                    return castState<SessionSet>();
                }

                CookieBuilder<STATE>& SetSameSite(const String& value)
                {
                    m_result->SetSameSite(value);
                    return *this;
                }

                std::unique_ptr<Cookie> Build()
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

            static CookieBuilder<0> Create()
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

        // ------------- Backend interface.

        class CONTENT_EXPORT Backend {
        public:
            virtual ~Backend() { }

            virtual DispatchResponse Enable(Maybe<int> in_maxTotalBufferSize, Maybe<int> in_maxResourceBufferSize) = 0;
            virtual DispatchResponse Disable() = 0;
            virtual DispatchResponse SetUserAgentOverride(const String& in_userAgent) = 0;
            virtual DispatchResponse ClearBrowserCache() = 0;
            virtual DispatchResponse ClearBrowserCookies() = 0;
            class CONTENT_EXPORT GetCookiesCallback {
            public:
                virtual void sendSuccess(std::unique_ptr<protocol::Array<protocol::Network::Cookie>> cookies) = 0;
                virtual void sendFailure(const DispatchResponse&) = 0;
                virtual void fallThrough() = 0;
                virtual ~GetCookiesCallback() { }
            };
            virtual void GetCookies(std::unique_ptr<GetCookiesCallback> callback) = 0;
            class CONTENT_EXPORT GetAllCookiesCallback {
            public:
                virtual void sendSuccess(std::unique_ptr<protocol::Array<protocol::Network::Cookie>> cookies) = 0;
                virtual void sendFailure(const DispatchResponse&) = 0;
                virtual void fallThrough() = 0;
                virtual ~GetAllCookiesCallback() { }
            };
            virtual void GetAllCookies(std::unique_ptr<GetAllCookiesCallback> callback) = 0;
            class CONTENT_EXPORT DeleteCookieCallback {
            public:
                virtual void sendSuccess() = 0;
                virtual void sendFailure(const DispatchResponse&) = 0;
                virtual void fallThrough() = 0;
                virtual ~DeleteCookieCallback() { }
            };
            virtual void DeleteCookie(const String& in_cookieName, const String& in_url, std::unique_ptr<DeleteCookieCallback> callback) = 0;
            class CONTENT_EXPORT SetCookieCallback {
            public:
                virtual void sendSuccess(bool success) = 0;
                virtual void sendFailure(const DispatchResponse&) = 0;
                virtual void fallThrough() = 0;
                virtual ~SetCookieCallback() { }
            };
            virtual void SetCookie(const String& in_url, const String& in_name, const String& in_value, Maybe<String> in_domain, Maybe<String> in_path, Maybe<bool> in_secure, Maybe<bool> in_httpOnly, Maybe<String> in_sameSite, Maybe<double> in_expirationDate, std::unique_ptr<SetCookieCallback> callback) = 0;
            virtual DispatchResponse CanEmulateNetworkConditions(bool* out_result) = 0;
        };

        // ------------- Frontend interface.

        class CONTENT_EXPORT Frontend {
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

        class CONTENT_EXPORT Dispatcher {
        public:
            static void wire(UberDispatcher*, Backend*);

        private:
            Dispatcher() { }
        };

        // ------------- Metainfo.

        class CONTENT_EXPORT Metainfo {
        public:
            using BackendClass = Backend;
            using FrontendClass = Frontend;
            using DispatcherClass = Dispatcher;
            static const char domainName[];
            static const char commandPrefix[];
            static const char version[];
        };

    } // namespace Network
} // namespace content
} // namespace protocol

#endif // !defined(content_protocol_Network_h)
