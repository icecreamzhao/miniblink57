// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef content_protocol_Inspector_h
#define content_protocol_Inspector_h

#include "content/browser/devtools/protocol/protocol.h"
#include "content/common/content_export.h"
// For each imported domain we generate a ValueConversions struct instead of a full domain definition
// and include Domain::API version from there.

namespace content {
namespace protocol {
    namespace Inspector {

        // ------------- Forward and enum declarations.
        // Wrapper for notification params
        class DetachedNotification;
        // Wrapper for notification params
        using TargetCrashedNotification = Object;

        // ------------- Type and builder declarations.

        // Wrapper for notification params
        class CONTENT_EXPORT DetachedNotification : public Serializable {
            PROTOCOL_DISALLOW_COPY(DetachedNotification);

        public:
            static std::unique_ptr<DetachedNotification> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~DetachedNotification() override { }

            String GetReason() { return m_reason; }
            void SetReason(const String& value) { m_reason = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<DetachedNotification> clone() const;

            template <int STATE>
            class DetachedNotificationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    ReasonSet = 1 << 1,
                    AllFieldsSet = (ReasonSet | 0)
                };

                DetachedNotificationBuilder<STATE | ReasonSet>& SetReason(const String& value)
                {
                    static_assert(!(STATE & ReasonSet), "property reason should not be set yet");
                    m_result->SetReason(value);
                    return castState<ReasonSet>();
                }

                std::unique_ptr<DetachedNotification> Build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class DetachedNotification;
                DetachedNotificationBuilder()
                    : m_result(new DetachedNotification())
                {
                }

                template <int STEP>
                DetachedNotificationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<DetachedNotificationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Inspector::DetachedNotification> m_result;
            };

            static DetachedNotificationBuilder<0> Create()
            {
                return DetachedNotificationBuilder<0>();
            }

        private:
            DetachedNotification()
            {
            }

            String m_reason;
        };

        // ------------- Backend interface.

        class CONTENT_EXPORT Backend {
        public:
            virtual ~Backend() { }

            virtual DispatchResponse Enable() = 0;
            virtual DispatchResponse Disable() = 0;
        };

        // ------------- Frontend interface.

        class CONTENT_EXPORT Frontend {
        public:
            explicit Frontend(FrontendChannel* frontendChannel)
                : m_frontendChannel(frontendChannel)
            {
            }
            void Detached(const String& reason);
            void TargetCrashed();

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

    } // namespace Inspector
} // namespace content
} // namespace protocol

#endif // !defined(content_protocol_Inspector_h)
