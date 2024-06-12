// This file is generated

// Copyright (c) 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "content/browser/devtools/protocol/input.h"

#include "content/browser/devtools/protocol/protocol.h"

namespace content {
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
                m_dispatchMap["Input.dispatchKeyEvent"] = &DispatcherImpl::dispatchKeyEvent;
                m_dispatchMap["Input.dispatchMouseEvent"] = &DispatcherImpl::dispatchMouseEvent;
                m_dispatchMap["Input.emulateTouchFromMouseEvent"] = &DispatcherImpl::emulateTouchFromMouseEvent;
                m_dispatchMap["Input.synthesizePinchGesture"] = &DispatcherImpl::synthesizePinchGesture;
                m_dispatchMap["Input.synthesizeScrollGesture"] = &DispatcherImpl::synthesizeScrollGesture;
                m_dispatchMap["Input.synthesizeTapGesture"] = &DispatcherImpl::synthesizeTapGesture;
            }
            ~DispatcherImpl() override { }
            DispatchResponse::Status dispatch(int callId, const String& method, std::unique_ptr<protocol::DictionaryValue> messageObject) override;
            HashMap<String, String>& redirects() { return m_redirects; }

        protected:
            using CallHandler = DispatchResponse::Status (DispatcherImpl::*)(int callId, std::unique_ptr<DictionaryValue> messageObject, ErrorSupport* errors);
            using DispatchMap = protocol::HashMap<String, CallHandler>;
            DispatchMap m_dispatchMap;
            HashMap<String, String> m_redirects;

            DispatchResponse::Status dispatchKeyEvent(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status dispatchMouseEvent(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status emulateTouchFromMouseEvent(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status synthesizePinchGesture(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status synthesizeScrollGesture(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);
            DispatchResponse::Status synthesizeTapGesture(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport*);

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

        class DispatchKeyEventCallbackImpl : public Backend::DispatchKeyEventCallback, public DispatcherBase::Callback {
        public:
            DispatchKeyEventCallbackImpl(std::unique_ptr<DispatcherBase::WeakPtr> backendImpl, int callId, int callbackId)
                : DispatcherBase::Callback(std::move(backendImpl), callId, callbackId)
            {
            }

            void sendSuccess() override
            {
                std::unique_ptr<protocol::DictionaryValue> resultObject = DictionaryValue::create();
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

        DispatchResponse::Status DispatcherImpl::dispatchKeyEvent(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* typeValue = object ? object->get("type") : nullptr;
            errors->setName("type");
            String in_type = ValueConversions<String>::fromValue(typeValue, errors);
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
            protocol::Value* textValue = object ? object->get("text") : nullptr;
            Maybe<String> in_text;
            if (textValue) {
                errors->setName("text");
                in_text = ValueConversions<String>::fromValue(textValue, errors);
            }
            protocol::Value* unmodifiedTextValue = object ? object->get("unmodifiedText") : nullptr;
            Maybe<String> in_unmodifiedText;
            if (unmodifiedTextValue) {
                errors->setName("unmodifiedText");
                in_unmodifiedText = ValueConversions<String>::fromValue(unmodifiedTextValue, errors);
            }
            protocol::Value* keyIdentifierValue = object ? object->get("keyIdentifier") : nullptr;
            Maybe<String> in_keyIdentifier;
            if (keyIdentifierValue) {
                errors->setName("keyIdentifier");
                in_keyIdentifier = ValueConversions<String>::fromValue(keyIdentifierValue, errors);
            }
            protocol::Value* codeValue = object ? object->get("code") : nullptr;
            Maybe<String> in_code;
            if (codeValue) {
                errors->setName("code");
                in_code = ValueConversions<String>::fromValue(codeValue, errors);
            }
            protocol::Value* keyValue = object ? object->get("key") : nullptr;
            Maybe<String> in_key;
            if (keyValue) {
                errors->setName("key");
                in_key = ValueConversions<String>::fromValue(keyValue, errors);
            }
            protocol::Value* windowsVirtualKeyCodeValue = object ? object->get("windowsVirtualKeyCode") : nullptr;
            Maybe<int> in_windowsVirtualKeyCode;
            if (windowsVirtualKeyCodeValue) {
                errors->setName("windowsVirtualKeyCode");
                in_windowsVirtualKeyCode = ValueConversions<int>::fromValue(windowsVirtualKeyCodeValue, errors);
            }
            protocol::Value* nativeVirtualKeyCodeValue = object ? object->get("nativeVirtualKeyCode") : nullptr;
            Maybe<int> in_nativeVirtualKeyCode;
            if (nativeVirtualKeyCodeValue) {
                errors->setName("nativeVirtualKeyCode");
                in_nativeVirtualKeyCode = ValueConversions<int>::fromValue(nativeVirtualKeyCodeValue, errors);
            }
            protocol::Value* autoRepeatValue = object ? object->get("autoRepeat") : nullptr;
            Maybe<bool> in_autoRepeat;
            if (autoRepeatValue) {
                errors->setName("autoRepeat");
                in_autoRepeat = ValueConversions<bool>::fromValue(autoRepeatValue, errors);
            }
            protocol::Value* isKeypadValue = object ? object->get("isKeypad") : nullptr;
            Maybe<bool> in_isKeypad;
            if (isKeypadValue) {
                errors->setName("isKeypad");
                in_isKeypad = ValueConversions<bool>::fromValue(isKeypadValue, errors);
            }
            protocol::Value* isSystemKeyValue = object ? object->get("isSystemKey") : nullptr;
            Maybe<bool> in_isSystemKey;
            if (isSystemKeyValue) {
                errors->setName("isSystemKey");
                in_isSystemKey = ValueConversions<bool>::fromValue(isSystemKeyValue, errors);
            }
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            std::unique_ptr<DispatchKeyEventCallbackImpl> callback(new DispatchKeyEventCallbackImpl(weakPtr(), callId, nextCallbackId()));
            m_backend->DispatchKeyEvent(in_type, std::move(in_modifiers), std::move(in_timestamp), std::move(in_text), std::move(in_unmodifiedText), std::move(in_keyIdentifier), std::move(in_code), std::move(in_key), std::move(in_windowsVirtualKeyCode), std::move(in_nativeVirtualKeyCode), std::move(in_autoRepeat), std::move(in_isKeypad), std::move(in_isSystemKey), std::move(callback));
            return (weak->get() && weak->get()->lastCallbackFallThrough()) ? DispatchResponse::kFallThrough : DispatchResponse::kAsync;
        }

        class DispatchMouseEventCallbackImpl : public Backend::DispatchMouseEventCallback, public DispatcherBase::Callback {
        public:
            DispatchMouseEventCallbackImpl(std::unique_ptr<DispatcherBase::WeakPtr> backendImpl, int callId, int callbackId)
                : DispatcherBase::Callback(std::move(backendImpl), callId, callbackId)
            {
            }

            void sendSuccess() override
            {
                std::unique_ptr<protocol::DictionaryValue> resultObject = DictionaryValue::create();
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

        DispatchResponse::Status DispatcherImpl::dispatchMouseEvent(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* typeValue = object ? object->get("type") : nullptr;
            errors->setName("type");
            String in_type = ValueConversions<String>::fromValue(typeValue, errors);
            protocol::Value* xValue = object ? object->get("x") : nullptr;
            errors->setName("x");
            int in_x = ValueConversions<int>::fromValue(xValue, errors);
            protocol::Value* yValue = object ? object->get("y") : nullptr;
            errors->setName("y");
            int in_y = ValueConversions<int>::fromValue(yValue, errors);
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
            protocol::Value* buttonValue = object ? object->get("button") : nullptr;
            Maybe<String> in_button;
            if (buttonValue) {
                errors->setName("button");
                in_button = ValueConversions<String>::fromValue(buttonValue, errors);
            }
            protocol::Value* clickCountValue = object ? object->get("clickCount") : nullptr;
            Maybe<int> in_clickCount;
            if (clickCountValue) {
                errors->setName("clickCount");
                in_clickCount = ValueConversions<int>::fromValue(clickCountValue, errors);
            }
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            std::unique_ptr<DispatchMouseEventCallbackImpl> callback(new DispatchMouseEventCallbackImpl(weakPtr(), callId, nextCallbackId()));
            m_backend->DispatchMouseEvent(in_type, in_x, in_y, std::move(in_modifiers), std::move(in_timestamp), std::move(in_button), std::move(in_clickCount), std::move(callback));
            return (weak->get() && weak->get()->lastCallbackFallThrough()) ? DispatchResponse::kFallThrough : DispatchResponse::kAsync;
        }

        DispatchResponse::Status DispatcherImpl::emulateTouchFromMouseEvent(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* typeValue = object ? object->get("type") : nullptr;
            errors->setName("type");
            String in_type = ValueConversions<String>::fromValue(typeValue, errors);
            protocol::Value* xValue = object ? object->get("x") : nullptr;
            errors->setName("x");
            int in_x = ValueConversions<int>::fromValue(xValue, errors);
            protocol::Value* yValue = object ? object->get("y") : nullptr;
            errors->setName("y");
            int in_y = ValueConversions<int>::fromValue(yValue, errors);
            protocol::Value* timestampValue = object ? object->get("timestamp") : nullptr;
            errors->setName("timestamp");
            double in_timestamp = ValueConversions<double>::fromValue(timestampValue, errors);
            protocol::Value* buttonValue = object ? object->get("button") : nullptr;
            errors->setName("button");
            String in_button = ValueConversions<String>::fromValue(buttonValue, errors);
            protocol::Value* deltaXValue = object ? object->get("deltaX") : nullptr;
            Maybe<double> in_deltaX;
            if (deltaXValue) {
                errors->setName("deltaX");
                in_deltaX = ValueConversions<double>::fromValue(deltaXValue, errors);
            }
            protocol::Value* deltaYValue = object ? object->get("deltaY") : nullptr;
            Maybe<double> in_deltaY;
            if (deltaYValue) {
                errors->setName("deltaY");
                in_deltaY = ValueConversions<double>::fromValue(deltaYValue, errors);
            }
            protocol::Value* modifiersValue = object ? object->get("modifiers") : nullptr;
            Maybe<int> in_modifiers;
            if (modifiersValue) {
                errors->setName("modifiers");
                in_modifiers = ValueConversions<int>::fromValue(modifiersValue, errors);
            }
            protocol::Value* clickCountValue = object ? object->get("clickCount") : nullptr;
            Maybe<int> in_clickCount;
            if (clickCountValue) {
                errors->setName("clickCount");
                in_clickCount = ValueConversions<int>::fromValue(clickCountValue, errors);
            }
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            DispatchResponse response = m_backend->EmulateTouchFromMouseEvent(in_type, in_x, in_y, in_timestamp, in_button, std::move(in_deltaX), std::move(in_deltaY), std::move(in_modifiers), std::move(in_clickCount));
            if (response.status() == DispatchResponse::kFallThrough)
                return response.status();
            if (weak->get())
                weak->get()->sendResponse(callId, response);
            return response.status();
        }

        class SynthesizePinchGestureCallbackImpl : public Backend::SynthesizePinchGestureCallback, public DispatcherBase::Callback {
        public:
            SynthesizePinchGestureCallbackImpl(std::unique_ptr<DispatcherBase::WeakPtr> backendImpl, int callId, int callbackId)
                : DispatcherBase::Callback(std::move(backendImpl), callId, callbackId)
            {
            }

            void sendSuccess() override
            {
                std::unique_ptr<protocol::DictionaryValue> resultObject = DictionaryValue::create();
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

        DispatchResponse::Status DispatcherImpl::synthesizePinchGesture(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* xValue = object ? object->get("x") : nullptr;
            errors->setName("x");
            int in_x = ValueConversions<int>::fromValue(xValue, errors);
            protocol::Value* yValue = object ? object->get("y") : nullptr;
            errors->setName("y");
            int in_y = ValueConversions<int>::fromValue(yValue, errors);
            protocol::Value* scaleFactorValue = object ? object->get("scaleFactor") : nullptr;
            errors->setName("scaleFactor");
            double in_scaleFactor = ValueConversions<double>::fromValue(scaleFactorValue, errors);
            protocol::Value* relativeSpeedValue = object ? object->get("relativeSpeed") : nullptr;
            Maybe<int> in_relativeSpeed;
            if (relativeSpeedValue) {
                errors->setName("relativeSpeed");
                in_relativeSpeed = ValueConversions<int>::fromValue(relativeSpeedValue, errors);
            }
            protocol::Value* gestureSourceTypeValue = object ? object->get("gestureSourceType") : nullptr;
            Maybe<String> in_gestureSourceType;
            if (gestureSourceTypeValue) {
                errors->setName("gestureSourceType");
                in_gestureSourceType = ValueConversions<String>::fromValue(gestureSourceTypeValue, errors);
            }
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            std::unique_ptr<SynthesizePinchGestureCallbackImpl> callback(new SynthesizePinchGestureCallbackImpl(weakPtr(), callId, nextCallbackId()));
            m_backend->SynthesizePinchGesture(in_x, in_y, in_scaleFactor, std::move(in_relativeSpeed), std::move(in_gestureSourceType), std::move(callback));
            return (weak->get() && weak->get()->lastCallbackFallThrough()) ? DispatchResponse::kFallThrough : DispatchResponse::kAsync;
        }

        class SynthesizeScrollGestureCallbackImpl : public Backend::SynthesizeScrollGestureCallback, public DispatcherBase::Callback {
        public:
            SynthesizeScrollGestureCallbackImpl(std::unique_ptr<DispatcherBase::WeakPtr> backendImpl, int callId, int callbackId)
                : DispatcherBase::Callback(std::move(backendImpl), callId, callbackId)
            {
            }

            void sendSuccess() override
            {
                std::unique_ptr<protocol::DictionaryValue> resultObject = DictionaryValue::create();
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

        DispatchResponse::Status DispatcherImpl::synthesizeScrollGesture(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* xValue = object ? object->get("x") : nullptr;
            errors->setName("x");
            int in_x = ValueConversions<int>::fromValue(xValue, errors);
            protocol::Value* yValue = object ? object->get("y") : nullptr;
            errors->setName("y");
            int in_y = ValueConversions<int>::fromValue(yValue, errors);
            protocol::Value* xDistanceValue = object ? object->get("xDistance") : nullptr;
            Maybe<int> in_xDistance;
            if (xDistanceValue) {
                errors->setName("xDistance");
                in_xDistance = ValueConversions<int>::fromValue(xDistanceValue, errors);
            }
            protocol::Value* yDistanceValue = object ? object->get("yDistance") : nullptr;
            Maybe<int> in_yDistance;
            if (yDistanceValue) {
                errors->setName("yDistance");
                in_yDistance = ValueConversions<int>::fromValue(yDistanceValue, errors);
            }
            protocol::Value* xOverscrollValue = object ? object->get("xOverscroll") : nullptr;
            Maybe<int> in_xOverscroll;
            if (xOverscrollValue) {
                errors->setName("xOverscroll");
                in_xOverscroll = ValueConversions<int>::fromValue(xOverscrollValue, errors);
            }
            protocol::Value* yOverscrollValue = object ? object->get("yOverscroll") : nullptr;
            Maybe<int> in_yOverscroll;
            if (yOverscrollValue) {
                errors->setName("yOverscroll");
                in_yOverscroll = ValueConversions<int>::fromValue(yOverscrollValue, errors);
            }
            protocol::Value* preventFlingValue = object ? object->get("preventFling") : nullptr;
            Maybe<bool> in_preventFling;
            if (preventFlingValue) {
                errors->setName("preventFling");
                in_preventFling = ValueConversions<bool>::fromValue(preventFlingValue, errors);
            }
            protocol::Value* speedValue = object ? object->get("speed") : nullptr;
            Maybe<int> in_speed;
            if (speedValue) {
                errors->setName("speed");
                in_speed = ValueConversions<int>::fromValue(speedValue, errors);
            }
            protocol::Value* gestureSourceTypeValue = object ? object->get("gestureSourceType") : nullptr;
            Maybe<String> in_gestureSourceType;
            if (gestureSourceTypeValue) {
                errors->setName("gestureSourceType");
                in_gestureSourceType = ValueConversions<String>::fromValue(gestureSourceTypeValue, errors);
            }
            protocol::Value* repeatCountValue = object ? object->get("repeatCount") : nullptr;
            Maybe<int> in_repeatCount;
            if (repeatCountValue) {
                errors->setName("repeatCount");
                in_repeatCount = ValueConversions<int>::fromValue(repeatCountValue, errors);
            }
            protocol::Value* repeatDelayMsValue = object ? object->get("repeatDelayMs") : nullptr;
            Maybe<int> in_repeatDelayMs;
            if (repeatDelayMsValue) {
                errors->setName("repeatDelayMs");
                in_repeatDelayMs = ValueConversions<int>::fromValue(repeatDelayMsValue, errors);
            }
            protocol::Value* interactionMarkerNameValue = object ? object->get("interactionMarkerName") : nullptr;
            Maybe<String> in_interactionMarkerName;
            if (interactionMarkerNameValue) {
                errors->setName("interactionMarkerName");
                in_interactionMarkerName = ValueConversions<String>::fromValue(interactionMarkerNameValue, errors);
            }
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            std::unique_ptr<SynthesizeScrollGestureCallbackImpl> callback(new SynthesizeScrollGestureCallbackImpl(weakPtr(), callId, nextCallbackId()));
            m_backend->SynthesizeScrollGesture(in_x, in_y, std::move(in_xDistance), std::move(in_yDistance), std::move(in_xOverscroll), std::move(in_yOverscroll), std::move(in_preventFling), std::move(in_speed), std::move(in_gestureSourceType), std::move(in_repeatCount), std::move(in_repeatDelayMs), std::move(in_interactionMarkerName), std::move(callback));
            return (weak->get() && weak->get()->lastCallbackFallThrough()) ? DispatchResponse::kFallThrough : DispatchResponse::kAsync;
        }

        class SynthesizeTapGestureCallbackImpl : public Backend::SynthesizeTapGestureCallback, public DispatcherBase::Callback {
        public:
            SynthesizeTapGestureCallbackImpl(std::unique_ptr<DispatcherBase::WeakPtr> backendImpl, int callId, int callbackId)
                : DispatcherBase::Callback(std::move(backendImpl), callId, callbackId)
            {
            }

            void sendSuccess() override
            {
                std::unique_ptr<protocol::DictionaryValue> resultObject = DictionaryValue::create();
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

        DispatchResponse::Status DispatcherImpl::synthesizeTapGesture(int callId, std::unique_ptr<DictionaryValue> requestMessageObject, ErrorSupport* errors)
        {
            // Prepare input parameters.
            protocol::DictionaryValue* object = DictionaryValue::cast(requestMessageObject->get("params"));
            errors->push();
            protocol::Value* xValue = object ? object->get("x") : nullptr;
            errors->setName("x");
            int in_x = ValueConversions<int>::fromValue(xValue, errors);
            protocol::Value* yValue = object ? object->get("y") : nullptr;
            errors->setName("y");
            int in_y = ValueConversions<int>::fromValue(yValue, errors);
            protocol::Value* durationValue = object ? object->get("duration") : nullptr;
            Maybe<int> in_duration;
            if (durationValue) {
                errors->setName("duration");
                in_duration = ValueConversions<int>::fromValue(durationValue, errors);
            }
            protocol::Value* tapCountValue = object ? object->get("tapCount") : nullptr;
            Maybe<int> in_tapCount;
            if (tapCountValue) {
                errors->setName("tapCount");
                in_tapCount = ValueConversions<int>::fromValue(tapCountValue, errors);
            }
            protocol::Value* gestureSourceTypeValue = object ? object->get("gestureSourceType") : nullptr;
            Maybe<String> in_gestureSourceType;
            if (gestureSourceTypeValue) {
                errors->setName("gestureSourceType");
                in_gestureSourceType = ValueConversions<String>::fromValue(gestureSourceTypeValue, errors);
            }
            errors->pop();
            if (errors->hasErrors()) {
                reportProtocolError(callId, DispatchResponse::kInvalidParams, kInvalidParamsString, errors);
                return DispatchResponse::kError;
            }

            std::unique_ptr<DispatcherBase::WeakPtr> weak = weakPtr();
            std::unique_ptr<SynthesizeTapGestureCallbackImpl> callback(new SynthesizeTapGestureCallbackImpl(weakPtr(), callId, nextCallbackId()));
            m_backend->SynthesizeTapGesture(in_x, in_y, std::move(in_duration), std::move(in_tapCount), std::move(in_gestureSourceType), std::move(callback));
            return (weak->get() && weak->get()->lastCallbackFallThrough()) ? DispatchResponse::kFallThrough : DispatchResponse::kAsync;
        }

        // static
        void Dispatcher::wire(UberDispatcher* uber, Backend* backend)
        {
            std::unique_ptr<DispatcherImpl> dispatcher(new DispatcherImpl(uber->channel(), backend, uber->fallThroughForNotFound()));
            uber->setupRedirects(dispatcher->redirects());
            uber->registerBackend("Input", std::move(dispatcher));
        }

    } // Input
} // namespace content
} // namespace protocol
