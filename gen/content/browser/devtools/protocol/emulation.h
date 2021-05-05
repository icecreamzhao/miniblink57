// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef content_protocol_Emulation_h
#define content_protocol_Emulation_h

#include "content/browser/devtools/protocol/protocol.h"
#include "content/common/content_export.h"
// For each imported domain we generate a ValueConversions struct instead of a full domain definition
// and include Domain::API version from there.

namespace content {
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
            CONTENT_EXPORT extern const char* Advance;
            CONTENT_EXPORT extern const char* Pause;
            CONTENT_EXPORT extern const char* PauseIfNetworkFetchesPending;
        } // namespace VirtualTimePolicyEnum

        namespace SetTouchEmulationEnabled {
            namespace ConfigurationEnum {
                CONTENT_EXPORT extern const char* Mobile;
                CONTENT_EXPORT extern const char* Desktop;
            } // ConfigurationEnum
        } // SetTouchEmulationEnabled

        // ------------- Type and builder declarations.

        // Screen orientation.
        class CONTENT_EXPORT ScreenOrientation : public Serializable {
            PROTOCOL_DISALLOW_COPY(ScreenOrientation);

        public:
            static std::unique_ptr<ScreenOrientation> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~ScreenOrientation() override { }

            struct CONTENT_EXPORT TypeEnum {
                static const char* PortraitPrimary;
                static const char* PortraitSecondary;
                static const char* LandscapePrimary;
                static const char* LandscapeSecondary;
            }; // TypeEnum

            String GetType() { return m_type; }
            void SetType(const String& value) { m_type = value; }

            int GetAngle() { return m_angle; }
            void SetAngle(int value) { m_angle = value; }

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

                ScreenOrientationBuilder<STATE | TypeSet>& SetType(const String& value)
                {
                    static_assert(!(STATE & TypeSet), "property type should not be set yet");
                    m_result->SetType(value);
                    return castState<TypeSet>();
                }

                ScreenOrientationBuilder<STATE | AngleSet>& SetAngle(int value)
                {
                    static_assert(!(STATE & AngleSet), "property angle should not be set yet");
                    m_result->SetAngle(value);
                    return castState<AngleSet>();
                }

                std::unique_ptr<ScreenOrientation> Build()
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

            static ScreenOrientationBuilder<0> Create()
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

        class CONTENT_EXPORT Backend {
        public:
            virtual ~Backend() { }

            virtual DispatchResponse SetDeviceMetricsOverride(int in_width, int in_height, double in_deviceScaleFactor, bool in_mobile, bool in_fitWindow, Maybe<double> in_scale, Maybe<double> in_offsetX, Maybe<double> in_offsetY, Maybe<int> in_screenWidth, Maybe<int> in_screenHeight, Maybe<int> in_positionX, Maybe<int> in_positionY, Maybe<protocol::Emulation::ScreenOrientation> in_screenOrientation) = 0;
            virtual DispatchResponse ClearDeviceMetricsOverride() = 0;
            virtual DispatchResponse SetVisibleSize(int in_width, int in_height) = 0;
            virtual DispatchResponse SetGeolocationOverride(Maybe<double> in_latitude, Maybe<double> in_longitude, Maybe<double> in_accuracy) = 0;
            virtual DispatchResponse ClearGeolocationOverride() = 0;
            virtual DispatchResponse SetTouchEmulationEnabled(bool in_enabled, Maybe<String> in_configuration) = 0;
            virtual DispatchResponse CanEmulate(bool* out_result) = 0;

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
            void VirtualTimeBudgetExpired();

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

    } // namespace Emulation
} // namespace content
} // namespace protocol

#endif // !defined(content_protocol_Emulation_h)
