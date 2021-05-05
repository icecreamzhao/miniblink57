// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef blink_protocol_Input_h
#define blink_protocol_Input_h

#include "core/CoreExport.h"
#include "core/inspector/protocol/Protocol.h"
// For each imported domain we generate a ValueConversions struct instead of a full domain definition
// and include Domain::API version from there.

namespace blink {
namespace protocol {
    namespace Input {

        // ------------- Forward and enum declarations.
        //
        class TouchPoint;
        //
        using GestureSourceType = String;

        namespace GestureSourceTypeEnum {
            CORE_EXPORT extern const char* Default;
            CORE_EXPORT extern const char* Touch;
            CORE_EXPORT extern const char* Mouse;
        } // namespace GestureSourceTypeEnum

        namespace DispatchKeyEvent {
            namespace TypeEnum {
                CORE_EXPORT extern const char* KeyDown;
                CORE_EXPORT extern const char* KeyUp;
                CORE_EXPORT extern const char* RawKeyDown;
                CORE_EXPORT extern const char* Char;
            } // TypeEnum
        } // DispatchKeyEvent

        namespace DispatchMouseEvent {
            namespace TypeEnum {
                CORE_EXPORT extern const char* MousePressed;
                CORE_EXPORT extern const char* MouseReleased;
                CORE_EXPORT extern const char* MouseMoved;
            } // TypeEnum
        } // DispatchMouseEvent

        namespace DispatchMouseEvent {
            namespace ButtonEnum {
                CORE_EXPORT extern const char* None;
                CORE_EXPORT extern const char* Left;
                CORE_EXPORT extern const char* Middle;
                CORE_EXPORT extern const char* Right;
            } // ButtonEnum
        } // DispatchMouseEvent

        namespace DispatchTouchEvent {
            namespace TypeEnum {
                CORE_EXPORT extern const char* TouchStart;
                CORE_EXPORT extern const char* TouchEnd;
                CORE_EXPORT extern const char* TouchMove;
            } // TypeEnum
        } // DispatchTouchEvent

        namespace EmulateTouchFromMouseEvent {
            namespace TypeEnum {
                CORE_EXPORT extern const char* MousePressed;
                CORE_EXPORT extern const char* MouseReleased;
                CORE_EXPORT extern const char* MouseMoved;
                CORE_EXPORT extern const char* MouseWheel;
            } // TypeEnum
        } // EmulateTouchFromMouseEvent

        namespace EmulateTouchFromMouseEvent {
            namespace ButtonEnum {
                CORE_EXPORT extern const char* None;
                CORE_EXPORT extern const char* Left;
                CORE_EXPORT extern const char* Middle;
                CORE_EXPORT extern const char* Right;
            } // ButtonEnum
        } // EmulateTouchFromMouseEvent

        // ------------- Type and builder declarations.

        //
        class CORE_EXPORT TouchPoint : public Serializable {
            PROTOCOL_DISALLOW_COPY(TouchPoint);

        public:
            static std::unique_ptr<TouchPoint> fromValue(protocol::Value* value, ErrorSupport* errors);

            ~TouchPoint() override { }

            struct CORE_EXPORT StateEnum {
                static const char* TouchPressed;
                static const char* TouchReleased;
                static const char* TouchMoved;
                static const char* TouchStationary;
                static const char* TouchCancelled;
            }; // StateEnum

            String getState() { return m_state; }
            void setState(const String& value) { m_state = value; }

            int getX() { return m_x; }
            void setX(int value) { m_x = value; }

            int getY() { return m_y; }
            void setY(int value) { m_y = value; }

            bool hasRadiusX() { return m_radiusX.isJust(); }
            int getRadiusX(int defaultValue) { return m_radiusX.isJust() ? m_radiusX.fromJust() : defaultValue; }
            void setRadiusX(int value) { m_radiusX = value; }

            bool hasRadiusY() { return m_radiusY.isJust(); }
            int getRadiusY(int defaultValue) { return m_radiusY.isJust() ? m_radiusY.fromJust() : defaultValue; }
            void setRadiusY(int value) { m_radiusY = value; }

            bool hasRotationAngle() { return m_rotationAngle.isJust(); }
            double getRotationAngle(double defaultValue) { return m_rotationAngle.isJust() ? m_rotationAngle.fromJust() : defaultValue; }
            void setRotationAngle(double value) { m_rotationAngle = value; }

            bool hasForce() { return m_force.isJust(); }
            double getForce(double defaultValue) { return m_force.isJust() ? m_force.fromJust() : defaultValue; }
            void setForce(double value) { m_force = value; }

            bool hasId() { return m_id.isJust(); }
            double getId(double defaultValue) { return m_id.isJust() ? m_id.fromJust() : defaultValue; }
            void setId(double value) { m_id = value; }

            std::unique_ptr<protocol::DictionaryValue> toValue() const;
            String serialize() override { return toValue()->serialize(); }
            std::unique_ptr<TouchPoint> clone() const;

            template <int STATE>
            class TouchPointBuilder {
            public:
                enum {
                    NoFieldsSet = 0,
                    StateSet = 1 << 1,
                    XSet = 1 << 2,
                    YSet = 1 << 3,
                    AllFieldsSet = (StateSet | XSet | YSet | 0)
                };

                TouchPointBuilder<STATE | StateSet>& setState(const String& value)
                {
                    static_assert(!(STATE & StateSet), "property state should not be set yet");
                    m_result->setState(value);
                    return castState<StateSet>();
                }

                TouchPointBuilder<STATE | XSet>& setX(int value)
                {
                    static_assert(!(STATE & XSet), "property x should not be set yet");
                    m_result->setX(value);
                    return castState<XSet>();
                }

                TouchPointBuilder<STATE | YSet>& setY(int value)
                {
                    static_assert(!(STATE & YSet), "property y should not be set yet");
                    m_result->setY(value);
                    return castState<YSet>();
                }

                TouchPointBuilder<STATE>& setRadiusX(int value)
                {
                    m_result->setRadiusX(value);
                    return *this;
                }

                TouchPointBuilder<STATE>& setRadiusY(int value)
                {
                    m_result->setRadiusY(value);
                    return *this;
                }

                TouchPointBuilder<STATE>& setRotationAngle(double value)
                {
                    m_result->setRotationAngle(value);
                    return *this;
                }

                TouchPointBuilder<STATE>& setForce(double value)
                {
                    m_result->setForce(value);
                    return *this;
                }

                TouchPointBuilder<STATE>& setId(double value)
                {
                    m_result->setId(value);
                    return *this;
                }

                std::unique_ptr<TouchPoint> build()
                {
                    static_assert(STATE == AllFieldsSet, "state should be AllFieldsSet");
                    return std::move(m_result);
                }

            private:
                friend class TouchPoint;
                TouchPointBuilder()
                    : m_result(new TouchPoint())
                {
                }

                template <int STEP>
                TouchPointBuilder<STATE | STEP>& castState()
                {
                    return *reinterpret_cast<TouchPointBuilder<STATE | STEP>*>(this);
                }

                std::unique_ptr<protocol::Input::TouchPoint> m_result;
            };

            static TouchPointBuilder<0> create()
            {
                return TouchPointBuilder<0>();
            }

        private:
            TouchPoint()
            {
                m_x = 0;
                m_y = 0;
            }

            String m_state;
            int m_x;
            int m_y;
            Maybe<int> m_radiusX;
            Maybe<int> m_radiusY;
            Maybe<double> m_rotationAngle;
            Maybe<double> m_force;
            Maybe<double> m_id;
        };

        // ------------- Backend interface.

        class CORE_EXPORT Backend {
        public:
            virtual ~Backend() { }

            virtual DispatchResponse dispatchTouchEvent(const String& in_type, std::unique_ptr<protocol::Array<protocol::Input::TouchPoint>> in_touchPoints, Maybe<int> in_modifiers, Maybe<double> in_timestamp) = 0;

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

    } // namespace Input
} // namespace blink
} // namespace protocol

#endif // !defined(blink_protocol_Input_h)
