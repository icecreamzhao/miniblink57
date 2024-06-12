// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef blink_protocol_Emulation_h
#define blink_protocol_Emulation_h

#include "core/CoreExport.h"
#include "core/inspector/protocol/Protocol.h"
// For each imported domain we generate a ValueConversions struct instead of a full domain definition
// and include Domain::API version from there.

namespace blink {
namespace protocol {
    namespace Emulation {

        // ------------- Forward and enum declarations.
        // Screen orientation.
        class ScreenOrientation;
        // advance: If the scheduler runs out of immediate work, the virtual time base may fast forward to allow the next delayed task (if any) to run; pause: The virtual time base may not advance; pauseIfNetworkFetchesPending: The virtual time base may not advance if there are any pending resource fetches.
        using VirtualTimePolicy = String;
        // Wrapper for notification params
        using VirtualTimeBudgetExpiredNotification = Object;

        namespace VirtualTimePolicyEnum {
            CORE_EXPORT extern const char* Advance;
            CORE_EXPORT extern const char* Pause;
            CORE_EXPORT extern const char* PauseIfNetworkFetchesPending;
        } // namespace VirtualTimePolicyEnum

        namespace SetTouchEmulationEnabled {
            namespace ConfigurationEnum {
                CORE_EXPORT extern const char* Mobile;
                CORE_EXPORT extern const char* Desktop;
            } // ConfigurationEnum
        } // SetTouchEmulationEnabled

        // ------------- Type and builder declarations.

        // Screen orientation.
        class CORE_EXPORT ScreenOrientation : public Serializable {
            PROTOCOL_DISALLOW_COPY(ScreenOrientation);

        public:
            static std::unique_ptr<ScreenOrientation> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~ScreenOrientation() override { }

            struct CORE_EXPORT TypeEnum {
                static const char* PortraitPrimary;
                static const char* PortraitSecondary;
                static const char* LandscapePrimary;
                static const char* LandscapeSecondary;
            }; // TypeEnum

            String getType() { return m_type; }
            void setType(const String& value) { m_type = value; }

            int getAngle() { return m_angle; }
            void setAngle(int value) { m_angle = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<ScreenOrientation> clone() const;

            template <int STATE>
            class ScreenOrientationBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    TypeSet = 1 << 1,
                    AngleSet = 1 << 2,
                    AllFieldsSet = (TypeSet | AngleSet | 0)
                };

                ScreenOrientationBuilder<STATE | TypeSet>& setType(const String& value)
                {
                    static_assert(!(STATE & TypeSet), "property type should not be set yet");
                    m_result->setType(value);
                    return castState<TypeSet>();
                }

                ScreenOrientationBuilder<STATE | AngleSet>& setAngle(int value)
                {
                    static_assert(!(STATE & AngleSet), "property angle should not be set yet");
                    m_result->setAngle(value);
                    return castState<AngleSet>();
                }

                std::unique_ptr<ScreenOrientation> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class ScreenOrientation;
                ScreenOrientationBuilder()
                    : m_result(new ScreenOrientation())
                {
                }

                template <int STEP>
                ScreenOrientationBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<ScreenOrientationBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Emulation::ScreenOrientation> m_result;
            };

            static ScreenOrientationBuilder<0> create()
            {
                return ScreenOrientationBuilder<0>();
            }

        private:
            ScreenOrientation()
            {
                m_angle = 0;
            }

            String m_type;
            int m_angle;
        };

        // ------------- Backend interface.

        class CORE_EXPORT Backend {
        public:
            virtual ~Backend() { }

            virtual DispatchResponse forceViewport(double in_x, double in_y, double in_scale) = 0;
            virtual DispatchResponse resetViewport() = 0;
            virtual DispatchResponse resetPageScaleFactor() = 0;
            virtual DispatchResponse setPageScaleFactor(double in_pageScaleFactor) = 0;
            virtual DispatchResponse setScriptExecutionDisabled(bool in_value) = 0;
            virtual DispatchResponse setTouchEmulationEnabled(bool in_enabled, Maybe<String> in_configuration) = 0;
            virtual DispatchResponse setEmulatedMedia(const String& in_media) = 0;
            virtual DispatchResponse setCPUThrottlingRate(double in_rate) = 0;
            virtual DispatchResponse setVirtualTimePolicy(const String& in_policy, Maybe<int> in_budget) = 0;

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
            void virtualTimeBudgetExpired();

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

    } // namespace Emulation
} // namespace blink
} // namespace protocol

#endif // !defined(blink_protocol_Emulation_h)
