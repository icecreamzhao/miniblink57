// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef blink_protocol_Security_h
#define blink_protocol_Security_h

#include "core/CoreExport.h"
#include "core/inspector/protocol/Protocol.h"
// For each imported domain we generate a ValueConversions struct instead of a full domain definition
// and include Domain::API version from there.

namespace blink {
namespace protocol {
    namespace Security {

        // ------------- Forward and enum declarations.
        // An internal certificate ID value.
        using CertificateId = int;
        // The security level of a page or resource.
        using SecurityState = String;
        // An explanation of an factor contributing to the security state.
        class SecurityStateExplanation;
        // Information about insecure content on the page.
        class InsecureContentStatus;
        // Wrapper for notification params
        class SecurityStateChangedNotification;

        namespace SecurityStateEnum {
            CORE_EXPORT extern const char* Unknown;
            CORE_EXPORT extern const char* Neutral;
            CORE_EXPORT extern const char* Insecure;
            CORE_EXPORT extern const char* Warning;
            CORE_EXPORT extern const char* Secure;
            CORE_EXPORT extern const char* Info;
        } // namespace SecurityStateEnum

        // ------------- Type and builder declarations.

        // An explanation of an factor contributing to the security state.
        class CORE_EXPORT SecurityStateExplanation : public Serializable {
            PROTOCOL_DISALLOW_COPY(SecurityStateExplanation);

        public:
            static std::unique_ptr<SecurityStateExplanation> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~SecurityStateExplanation() override { }

            String getSecurityState() { return m_securityState; }
            void setSecurityState(const String& value) { m_securityState = value; }

            String getSummary() { return m_summary; }
            void setSummary(const String& value) { m_summary = value; }

            String getDescription() { return m_description; }
            void setDescription(const String& value) { m_description = value; }

            bool getHasCertificate() { return m_hasCertificate; }
            void setHasCertificate(bool value) { m_hasCertificate = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<SecurityStateExplanation> clone() const;

            template <int STATE>
            class SecurityStateExplanationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    SecurityStateSet = 1 << 1,
                    SummarySet = 1 << 2,
                    DescriptionSet = 1 << 3,
                    HasCertificateSet = 1 << 4,
                    AllFieldsSet = (SecurityStateSet | SummarySet | DescriptionSet | HasCertificateSet | 0)
                };

                SecurityStateExplanationBuilder<STATE | SecurityStateSet>& setSecurityState(const String& value)
                {
                    static_assert(!(STATE & SecurityStateSet), "property securityState should not be set yet");
                    m_result->setSecurityState(value);
                    return castState<SecurityStateSet>();
                }

                SecurityStateExplanationBuilder<STATE | SummarySet>& setSummary(const String& value)
                {
                    static_assert(!(STATE & SummarySet), "property summary should not be set yet");
                    m_result->setSummary(value);
                    return castState<SummarySet>();
                }

                SecurityStateExplanationBuilder<STATE | DescriptionSet>& setDescription(const String& value)
                {
                    static_assert(!(STATE & DescriptionSet), "property description should not be set yet");
                    m_result->setDescription(value);
                    return castState<DescriptionSet>();
                }

                SecurityStateExplanationBuilder<STATE | HasCertificateSet>& setHasCertificate(bool value)
                {
                    static_assert(!(STATE & HasCertificateSet), "property hasCertificate should not be set yet");
                    m_result->setHasCertificate(value);
                    return castState<HasCertificateSet>();
                }

                std::unique_ptr<SecurityStateExplanation> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class SecurityStateExplanation;
                SecurityStateExplanationBuilder()
                    : m_result(new SecurityStateExplanation())
                {
                }

                template <int STEP>
                SecurityStateExplanationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<SecurityStateExplanationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Security::SecurityStateExplanation> m_result;
            };

            static SecurityStateExplanationBuilder<0> create()
            {
                return SecurityStateExplanationBuilder<0>();
            }

        private:
            SecurityStateExplanation()
            {
                m_hasCertificate = false;
            }

            String m_securityState;
            String m_summary;
            String m_description;
            bool m_hasCertificate;
        };

        // Information about insecure content on the page.
        class CORE_EXPORT InsecureContentStatus : public Serializable {
            PROTOCOL_DISALLOW_COPY(InsecureContentStatus);

        public:
            static std::unique_ptr<InsecureContentStatus> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~InsecureContentStatus() override { }

            bool getRanMixedContent() { return m_ranMixedContent; }
            void setRanMixedContent(bool value) { m_ranMixedContent = value; }

            bool getDisplayedMixedContent() { return m_displayedMixedContent; }
            void setDisplayedMixedContent(bool value) { m_displayedMixedContent = value; }

            bool getRanContentWithCertErrors() { return m_ranContentWithCertErrors; }
            void setRanContentWithCertErrors(bool value) { m_ranContentWithCertErrors = value; }

            bool getDisplayedContentWithCertErrors() { return m_displayedContentWithCertErrors; }
            void setDisplayedContentWithCertErrors(bool value) { m_displayedContentWithCertErrors = value; }

            String getRanInsecureContentStyle() { return m_ranInsecureContentStyle; }
            void setRanInsecureContentStyle(const String& value) { m_ranInsecureContentStyle = value; }

            String getDisplayedInsecureContentStyle() { return m_displayedInsecureContentStyle; }
            void setDisplayedInsecureContentStyle(const String& value) { m_displayedInsecureContentStyle = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<InsecureContentStatus> clone() const;

            template <int STATE>
            class InsecureContentStatusBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    RanMixedContentSet = 1 << 1,
                    DisplayedMixedContentSet = 1 << 2,
                    RanContentWithCertErrorsSet = 1 << 3,
                    DisplayedContentWithCertErrorsSet = 1 << 4,
                    RanInsecureContentStyleSet = 1 << 5,
                    DisplayedInsecureContentStyleSet = 1 << 6,
                    AllFieldsSet = (RanMixedContentSet | DisplayedMixedContentSet | RanContentWithCertErrorsSet | DisplayedContentWithCertErrorsSet | RanInsecureContentStyleSet | DisplayedInsecureContentStyleSet | 0)
                };

                InsecureContentStatusBuilder<STATE | RanMixedContentSet>& setRanMixedContent(bool value)
                {
                    static_assert(!(STATE & RanMixedContentSet), "property ranMixedContent should not be set yet");
                    m_result->setRanMixedContent(value);
                    return castState<RanMixedContentSet>();
                }

                InsecureContentStatusBuilder<STATE | DisplayedMixedContentSet>& setDisplayedMixedContent(bool value)
                {
                    static_assert(!(STATE & DisplayedMixedContentSet), "property displayedMixedContent should not be set yet");
                    m_result->setDisplayedMixedContent(value);
                    return castState<DisplayedMixedContentSet>();
                }

                InsecureContentStatusBuilder<STATE | RanContentWithCertErrorsSet>& setRanContentWithCertErrors(bool value)
                {
                    static_assert(!(STATE & RanContentWithCertErrorsSet), "property ranContentWithCertErrors should not be set yet");
                    m_result->setRanContentWithCertErrors(value);
                    return castState<RanContentWithCertErrorsSet>();
                }

                InsecureContentStatusBuilder<STATE | DisplayedContentWithCertErrorsSet>& setDisplayedContentWithCertErrors(bool value)
                {
                    static_assert(!(STATE & DisplayedContentWithCertErrorsSet), "property displayedContentWithCertErrors should not be set yet");
                    m_result->setDisplayedContentWithCertErrors(value);
                    return castState<DisplayedContentWithCertErrorsSet>();
                }

                InsecureContentStatusBuilder<STATE | RanInsecureContentStyleSet>& setRanInsecureContentStyle(const String& value)
                {
                    static_assert(!(STATE & RanInsecureContentStyleSet), "property ranInsecureContentStyle should not be set yet");
                    m_result->setRanInsecureContentStyle(value);
                    return castState<RanInsecureContentStyleSet>();
                }

                InsecureContentStatusBuilder<STATE | DisplayedInsecureContentStyleSet>& setDisplayedInsecureContentStyle(const String& value)
                {
                    static_assert(!(STATE & DisplayedInsecureContentStyleSet), "property displayedInsecureContentStyle should not be set yet");
                    m_result->setDisplayedInsecureContentStyle(value);
                    return castState<DisplayedInsecureContentStyleSet>();
                }

                std::unique_ptr<InsecureContentStatus> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class InsecureContentStatus;
                InsecureContentStatusBuilder()
                    : m_result(new InsecureContentStatus())
                {
                }

                template <int STEP>
                InsecureContentStatusBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<InsecureContentStatusBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Security::InsecureContentStatus> m_result;
            };

            static InsecureContentStatusBuilder<0> create()
            {
                return InsecureContentStatusBuilder<0>();
            }

        private:
            InsecureContentStatus()
            {
                m_ranMixedContent = false;
                m_displayedMixedContent = false;
                m_ranContentWithCertErrors = false;
                m_displayedContentWithCertErrors = false;
            }

            bool m_ranMixedContent;
            bool m_displayedMixedContent;
            bool m_ranContentWithCertErrors;
            bool m_displayedContentWithCertErrors;
            String m_ranInsecureContentStyle;
            String m_displayedInsecureContentStyle;
        };

        // Wrapper for notification params
        class CORE_EXPORT SecurityStateChangedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(SecurityStateChangedNotification);

        public:
            static std::unique_ptr<SecurityStateChangedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~SecurityStateChangedNotification() override { }

            String getSecurityState() { return m_securityState; }
            void setSecurityState(const String& value) { m_securityState = value; }

            bool getSchemeIsCryptographic() { return m_schemeIsCryptographic; }
            void setSchemeIsCryptographic(bool value) { m_schemeIsCryptographic = value; }

            protocol::Array<protocol::Security::SecurityStateExplanation>* getExplanations() { return m_explanations.get(); }
            void setExplanations(std::unique_ptr<protocol::Array<protocol::Security::SecurityStateExplanation>> value) { m_explanations = std::move(value); }

            protocol::Security::InsecureContentStatus* getInsecureContentStatus() { return m_insecureContentStatus.get(); }
            void setInsecureContentStatus(std::unique_ptr<protocol::Security::InsecureContentStatus> value) { m_insecureContentStatus = std::move(value); }

            bool hasSummary() { return m_summary.isJust(); }
            String getSummary(const String& defaultValue) { return m_summary.isJust() ? m_summary.fromJust() : defaultValue; }
            void setSummary(const String& value) { m_summary = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<SecurityStateChangedNotification> clone() const;

            template <int STATE>
            class SecurityStateChangedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    SecurityStateSet = 1 << 1,
                    SchemeIsCryptographicSet = 1 << 2,
                    ExplanationsSet = 1 << 3,
                    InsecureContentStatusSet = 1 << 4,
                    AllFieldsSet = (SecurityStateSet | SchemeIsCryptographicSet | ExplanationsSet | InsecureContentStatusSet | 0)
                };

                SecurityStateChangedNotificationBuilder<STATE | SecurityStateSet>& setSecurityState(const String& value)
                {
                    static_assert(!(STATE & SecurityStateSet), "property securityState should not be set yet");
                    m_result->setSecurityState(value);
                    return castState<SecurityStateSet>();
                }

                SecurityStateChangedNotificationBuilder<STATE | SchemeIsCryptographicSet>& setSchemeIsCryptographic(bool value)
                {
                    static_assert(!(STATE & SchemeIsCryptographicSet), "property schemeIsCryptographic should not be set yet");
                    m_result->setSchemeIsCryptographic(value);
                    return castState<SchemeIsCryptographicSet>();
                }

                SecurityStateChangedNotificationBuilder<STATE | ExplanationsSet>& setExplanations(std::unique_ptr<protocol::Array<protocol::Security::SecurityStateExplanation>> value)
                {
                    static_assert(!(STATE & ExplanationsSet), "property explanations should not be set yet");
                    m_result->setExplanations(std::move(value));
                    return castState<ExplanationsSet>();
                }

                SecurityStateChangedNotificationBuilder<STATE | InsecureContentStatusSet>& setInsecureContentStatus(std::unique_ptr<protocol::Security::InsecureContentStatus> value)
                {
                    static_assert(!(STATE & InsecureContentStatusSet), "property insecureContentStatus should not be set yet");
                    m_result->setInsecureContentStatus(std::move(value));
                    return castState<InsecureContentStatusSet>();
                }

                SecurityStateChangedNotificationBuilder<STATE>& setSummary(const String& value)
                {
                    m_result->setSummary(value);
                    return *this;
                }

                std::unique_ptr<SecurityStateChangedNotification> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class SecurityStateChangedNotification;
                SecurityStateChangedNotificationBuilder()
                    : m_result(new SecurityStateChangedNotification())
                {
                }

                template <int STEP>
                SecurityStateChangedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<SecurityStateChangedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Security::SecurityStateChangedNotification> m_result;
            };

            static SecurityStateChangedNotificationBuilder<0> create()
            {
                return SecurityStateChangedNotificationBuilder<0>();
            }

        private:
            SecurityStateChangedNotification()
            {
                m_schemeIsCryptographic = false;
            }

            String m_securityState;
            bool m_schemeIsCryptographic;
            std::unique_ptr<protocol::Array<protocol::Security::SecurityStateExplanation>> m_explanations;
            std::unique_ptr<protocol::Security::InsecureContentStatus> m_insecureContentStatus;
            Maybe<String> m_summary;
        };

        // ------------- Backend interface.

        class CORE_EXPORT Backend {
        public:
            virtual ~Backend() { }

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
            void securityStateChanged(const String& securityState, bool schemeIsCryptographic, std::unique_ptr<protocol::Array<protocol::Security::SecurityStateExplanation>> explanations, std::unique_ptr<protocol::Security::InsecureContentStatus> insecureContentStatus, Maybe<String> summary = Maybe<String>());

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

    } // namespace Security
} // namespace blink
} // namespace protocol

#endif // !defined(blink_protocol_Security_h)
