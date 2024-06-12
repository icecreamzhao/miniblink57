// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "core/inspector/protocol/Input.h"

#include "core/inspector/protocol/Protocol.h"

namespace blink {
namespace protocol {
    namespace Input {

        // ------------- Enum values from types.

        const char Metainfo::domainName[] = "Input";
        const char Metainfo::commandPrefix[] = "Input.";
        const char Metainfo::version[] = "1.2";

        const char* TouchPoint::StateEnum::TouchPressed = "touchPressed";
        const char* TouchPoint::StateEnum::TouchReleased = "touchReleased";
        const char* TouchPoint::StateEnum::TouchMoved = "touchMoved";
        const char* TouchPoint::StateEnum::TouchStationary = "touchStationary";
        const char* TouchPoint::StateEnum::TouchCancelled = "touchCancelled";

        std::unique_ptr<TouchPoint> TouchPoint::fromValue(protocol::Value* value, ErrorSupport* errors)
        {
            if (!value || value->type() != protocol::Value::TypeObject) {
                errors->addError("object expected");
                return nullptr;
            }

            std::unique_ptr<TouchPoint> result(new TouchPoint());
            protocol::DictionaryValue* object = DictionaryValue::cast(value);
            errors->push();
            protocol::Value* stateValue = object->get("state");
            errors->setName("state");
            result->m_state = ValueConversions<String>::fromValue(stateValue, errors);
            protocol::Value* xValue = object->get("x");
            errors->setName("x");
            result->m_x = ValueConversions<int>::fromValue(xValue, errors);
            protocol::Value* yValue = object->get("y");
            errors->setName("y");
            result->m_y = ValueConversions<int>::fromValue(yValue, errors);
            protocol::Value* radiusXValue = object->get("radiusX");
            if (radiusXValue) {
                errors->setName("radiusX");
                result->m_radiusX = ValueConversions<int>::fromValue(radiusXValue, errors);
            }
            protocol::Value* radiusYValue = object->get("radiusY");
            if (radiusYValue) {
                errors->setName("radiusY");
                result->m_radiusY = ValueConversions<int>::fromValue(radiusYValue, errors);
            }
            protocol::Value* rotationAngleValue = object->get("rotationAngle");
            if (rotationAngleValue) {
                errors->setName("rotationAngle");
                result->m_rotationAngle = ValueConversions<double>::fromValue(rotationAngleValue, errors);
            }
            protocol::Value* forceValue = object->get("force");
            if (forceValue) {
                errors->setName("force");
                result->m_force = ValueConversions<double>::fromValue(forceValue, errors);
            }
            protocol::Value* idValue = object->get("id");
            if (idValue) {
                errors->setName("id");
                result->m_id = ValueConversions<double>::fromValue(idValue, errors);
            }
            errors->pop();
            if (errors->hasErrors())
                return nullptr;
            return result;
        }

        std::unique_ptr<protocol::DictionaryValue> TouchPoint::toValue() const
        {
            std::unique_ptr<protocol::DictionaryValue> result = DictionaryValue::create();
            result->setValue("state", ValueConversions<String>::toValue(m_state));
            result->setValue("x", ValueConversions<int>::toValue(m_x));
            result->setValue("y", ValueConversions<int>::toValue(m_y));
            if (m_radiusX.isJust())
                result->setValue("radiusX", ValueConversions<int>::toValue(m_radiusX.fromJust()));
            if (m_radiusY.isJust())
                result->setValue("radiusY", ValueConversions<int>::toValue(m_radiusY.fromJust()));
            if (m_rotationAngle.isJust())
                result->setValue("rotationAngle", ValueConversions<double>::toValue(m_rotationAngle.fromJust()));
            if (m_force.isJust())
                result->setValue("force", ValueConversions<double>::toValue(m_force.fromJust()));
            if (m_id.isJust())
                result->setValue("id", ValueConversions<double>::toValue(m_id.fromJust()));
            return result;
        }

        std::unique_ptr<TouchPoint> TouchPoint::clone() const
        {
            ErrorSupport errors;
            return fromValue(toValue().get(), &errors);
        }

        namespace GestureSourceTypeEnum {
            const char* Default = "default";
            const char* Touch = "touch";
            const char* Mouse = "mouse";
        } // namespace GestureSourceTypeEnum

        // ------------- Enum values from params.

        namespace DispatchKeyEvent {
            namespace TypeEnum {
                const char* KeyDown = "keyDown";
                const char* KeyUp = "keyUp";
                const char* RawKeyDown = "rawKeyDown";
                const char* Char = "char";
            } // namespace TypeEnum
        } // namespace DispatchKeyEvent

        namespace DispatchMouseEvent {
            namespace TypeEnum {
                const char* MousePressed = "mousePressed";
                const char* MouseReleased = "mouseReleased";
                const char* MouseMoved = "mouseMoved";
            } // namespace TypeEnum
        } // namespace DispatchMouseEvent

        namespace DispatchMouseEvent {
            namespace ButtonEnum {
                const char* None = "none";
                const char* Left = "left";
                const char* Middle = "middle";
                const char* Right = "right";
            } // namespace ButtonEnum
        } // namespace DispatchMouseEvent

        namespace DispatchTouchEvent {
            namespace TypeEnum {
                const char* TouchStart = "touchStart";
                const char* TouchEnd = "touchEnd";
                const char* TouchMove = "touchMove";
            } // namespace TypeEnum
        } // namespace DispatchTouchEvent

        namespace EmulateTouchFromMouseEvent {
            namespace TypeEnum {
                const char* MousePressed = "mousePressed";
                const char* MouseReleased = "mouseReleased";
                const char* MouseMoved = "mouseMoved";
                const char* MouseWheel = "mouseWheel";
            } // namespace TypeEnum
        } // namespace EmulateTouchFromMouseEvent

        namespace EmulateTouchFromMouseEvent {
            namespace ButtonEnum {
                const char* None = "none";
                const char* Left = "left";
                const char* Middle = "middle";
                const char* Right = "right";
            } // namespace ButtonEnum
        } // namespace EmulateTouchFromMouseEvent

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
                m_dispatchMap["Input.dispatchTouchEvent"] = &DispatcherImpl::dispatchTouchEvent;
            }
            ~DispatcherImpl() override { }
            DispatchResponse::Status dispatch(int callId, const String& method, std::unique_ptr<protocol::DictionaryValue> messageObject) override;
            HashMap<String, String>& redirects() { return m_redirects; }

        protected:
            using CallHandler = DispatchResponse::Status (DispatcherImpl::*)(int callId, std::unique_ptr<DictionaryValue> messageObject, ErrorSupport* errors);
            using DispatchMap = protocol::HashMap<String, CallHandler>;
            DispatchMap m_dispatchMap;
            HashMap<String, String> m_redirects;

            DispatchResponse::Status dispatchTouchEvent(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);

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

        DispatchResponse::Status DispatcherImpl::dispatchTouchEvent(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* typeValue = object ? object->get("type") : nullptr;
            errors->setName("type");
            String in_type = ValueConversions<String>::fromValue(typeValue, errors);
            protocol::Value* touchPointsValue = object ? object->get("touchPoints") : nullptr;
            errors->setName("touchPoints");
            std::unique_ptr<protocol::Array<protocol::Input::TouchPoint>> in_touchPoints = ValueConversions<protocol::Array<protocol::Input::TouchPoint>>::fromValue(touchPointsValue, errors);
            protocol::Value* modifiersValue = object ? object->get("modifiers") : nullptr;
            Maybe<int> in_modifiers;
            if (modifiersValue) {
                errors->setName("modifiers");
                in_modifiers = ValueConversions<int>::fromValue(modifiersValue, errors);
            }
            protocol::Value* timestampValue = object ? object->get("timestamp") : nullptr;
            Maybe<double> in_timestamp;
            if (timestampValue) {
                errors->setName("timestamp");
                in_timestamp = ValueConversions<double>::fromValue(timestampValue, errors);
            }
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->dispatchTouchEvent(in_type, std::move(in_touchPoints), std::move(in_modifiers), std::move(in_timestamp));
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        // static
        void Dispatcher::wire(UberDispatcher* uber, Backend* backend)
        {
            std::unique_ptr<DispatcherImpl> dispatcher(new DispatcherImpl(uber->channel(), backend, uber->fallThroughForNotFound()));
            uber->setupRedirects(dispatcher->redirects());
            uber->registerBackend("Input", std::move(dispatcher));
        }

    } // Input
} // namespace blink
} // namespace protocol
