// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef content_protocol_DOM_h
#define content_protocol_DOM_h

#include "content/browser/devtools/protocol/protocol.h"
#include "content/common/content_export.h"
// For each imported domain we generate a ValueConversions struct instead of a full domain definition
// and include Domain::API version from there.

namespace content {
namespace protocol {
    namespace DOM {

        // ------------- Forward and enum declarations.
        // Unique DOM node identifier.
        using NodeId = int;
        // A structure holding an RGBA color.
        class RGBA;

        // ------------- Type and builder declarations.

        // A structure holding an RGBA color.
        class CONTENT_EXPORT RGBA : public Serializable {
            PROTOCOL_DISALLOW_COPY(RGBA);

        public:
            static std::unique_ptr<RGBA> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~RGBA() override { }

            int GetR() { return m_r; }
            void SetR(int value) { m_r = value; }

            int GetG() { return m_g; }
            void SetG(int value) { m_g = value; }

            int GetB() { return m_b; }
            void SetB(int value) { m_b = value; }

            bool HasA() { return m_a.isJust(); }
            double GetA(double defaultValue) { return m_a.isJust() ? m_a.fromJust() : defaultValue; }
            void SetA(double value) { m_a = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<RGBA> clone() const;

            template <int STATE>
            class RGBABuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    RSet = 1 << 1,
                    GSet = 1 << 2,
                    BSet = 1 << 3,
                    AllFieldsSet = (RSet | GSet | BSet | 0)
                };

                RGBABuilder<STATE | RSet>& SetR(int value)
                {
                    static_assert(!(STATE & RSet), "property r should not be set yet");
                    m_result->SetR(value);
                    return castState<RSet>();
                }

                RGBABuilder<STATE | GSet>& SetG(int value)
                {
                    static_assert(!(STATE & GSet), "property g should not be set yet");
                    m_result->SetG(value);
                    return castState<GSet>();
                }

                RGBABuilder<STATE | BSet>& SetB(int value)
                {
                    static_assert(!(STATE & BSet), "property b should not be set yet");
                    m_result->SetB(value);
                    return castState<BSet>();
                }

                RGBABuilder<STATE>& SetA(double value)
                {
                    m_result->SetA(value);
                    return *this;
                }

                std::unique_ptr<RGBA> Build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class RGBA;
                RGBABuilder()
                    : m_result(new RGBA())
                {
                }

                template <int STEP>
                RGBABuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<RGBABuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::DOM::RGBA> m_result;
            };

            static RGBABuilder<0> Create()
            {
                return RGBABuilder<0>();
            }

        private:
            RGBA()
            {
                m_r = 0;
                m_g = 0;
                m_b = 0;
            }

            int m_r;
            int m_g;
            int m_b;
            Maybe<double> m_a;
        };

        // ------------- Backend interface.

        class CONTENT_EXPORT Backend {
        public:
            virtual ~Backend() { }

            virtual DispatchResponse SetFileInputFiles(int in_nodeId, std::unique_ptr<protocol::Array<String>> in_files) = 0;

            virtual DispatchResponse Disable()
            {
                return DispatchResponse::OK();
            }
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

    } // namespace DOM
} // namespace content
} // namespace protocol

#endif // !defined(content_protocol_DOM_h)
