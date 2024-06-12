// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/partial_interface.cpp.tmpl

// clang-format on
#include "V8InternalsPartial.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/ScriptPromise.h"
#include "bindings/core/v8/ScriptState.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8Document.h"
#include "bindings/core/v8/V8Internals.h"
#include "bindings/core/v8/V8Navigator.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/core/v8/V8Window.h"
#include "bindings/modules/v8/V8MediaDeviceInfo.h"
#include "bindings/modules/v8/V8MediaStreamTrack.h"
#include "bindings/modules/v8/V8MediaTrackConstraints.h"
#include "bindings/modules/v8/V8RTCCertificate.h"
#include "bindings/modules/v8/V8Response.h"
#include "bindings/modules/v8/V8ServiceWorker.h"
#include "core/dom/Document.h"
#include "modules/accessibility/testing/InternalsAccessibility.h"
#include "modules/fetch/testing/InternalsFetch.h"
#include "modules/mediastream/testing/InternalsMediaStream.h"
#include "modules/navigatorcontentutils/testing/InternalsNavigatorContentUtils.h"
#include "modules/peerconnection/testing/InternalsRTCCertificate.h"
#include "modules/serviceworkers/testing/InternalsServiceWorker.h"
#include "modules/speech/testing/InternalsSpeechSynthesis.h"
#include "modules/vibration/testing/InternalsVibration.h"
#include "modules/webaudio/testing/InternalsWebAudio.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace blink {

namespace InternalsPartialV8Internal {

    static void numberOfLiveAXObjectsMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        Internals* impl = V8Internals::toImpl(info.Holder());

        v8SetReturnValueUnsigned(info, InternalsAccessibility::numberOfLiveAXObjects(*impl));
    }

    void numberOfLiveAXObjectsMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        InternalsPartialV8Internal::numberOfLiveAXObjectsMethod(info);
    }

    static void getInternalResponseURLListMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        Internals* impl = V8Internals::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 1)) {
            V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("getInternalResponseURLList", "Internals", ExceptionMessages::notEnoughArguments(1, info.Length())));
            return;
        }

        Response* response;
        response = V8Response::toImplWithTypeCheck(info.GetIsolate(), info[0]);
        if (!response) {
            V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("getInternalResponseURLList", "Internals", "parameter 1 is not of type 'Response'."));

            return;
        }

        v8SetReturnValue(info, ToV8(InternalsFetch::getInternalResponseURLList(*impl, response), info.Holder(), info.GetIsolate()));
    }

    void getInternalResponseURLListMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        InternalsPartialV8Internal::getInternalResponseURLListMethod(info);
    }

    static void addFakeDeviceMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "Internals", "addFakeDevice");
        ExceptionToRejectPromiseScope rejectPromiseScope(info, exceptionState);

        // V8DOMConfiguration::DoNotCheckHolder
        // Make sure that info.Holder() really points to an instance of the type.
        if (!V8Internals::hasInstance(info.Holder(), info.GetIsolate())) {
            exceptionState.throwTypeError("Illegal invocation");
            return;
        }
        Internals* impl = V8Internals::toImpl(info.Holder());

        ScriptState* scriptState = ScriptState::forReceiverObject(info);

        if (UNLIKELY(info.Length() < 3)) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(3, info.Length()));
            return;
        }

        MediaDeviceInfo* deviceInfo;
        MediaTrackConstraints capabilities;
        MediaStreamTrack* dataSource;
        deviceInfo = V8MediaDeviceInfo::toImplWithTypeCheck(info.GetIsolate(), info[0]);
        if (!deviceInfo) {
            exceptionState.throwTypeError("parameter 1 is not of type 'MediaDeviceInfo'.");

            return;
        }

        if (!isUndefinedOrNull(info[1]) && !info[1]->IsObject()) {
            exceptionState.throwTypeError("parameter 2 ('capabilities') is not an object.");

            return;
        }
        V8MediaTrackConstraints::toImpl(info.GetIsolate(), info[1], capabilities, exceptionState);
        if (exceptionState.hadException())
            return;

        dataSource = V8MediaStreamTrack::toImplWithTypeCheck(info.GetIsolate(), info[2]);
        if (!dataSource && !isUndefinedOrNull(info[2])) {
            exceptionState.throwTypeError("parameter 3 is not of type 'MediaStreamTrack'.");

            return;
        }

        ScriptPromise result = InternalsMediaStream::addFakeDevice(scriptState, *impl, deviceInfo, capabilities, dataSource);
        v8SetReturnValue(info, result.v8Value());
    }

    void addFakeDeviceMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        InternalsPartialV8Internal::addFakeDeviceMethod(info);
    }

    static void setNavigatorContentUtilsClientMockMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        Internals* impl = V8Internals::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 1)) {
            V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("setNavigatorContentUtilsClientMock", "Internals", ExceptionMessages::notEnoughArguments(1, info.Length())));
            return;
        }

        Document* document;
        document = V8Document::toImplWithTypeCheck(info.GetIsolate(), info[0]);
        if (!document) {
            V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("setNavigatorContentUtilsClientMock", "Internals", "parameter 1 is not of type 'Document'."));

            return;
        }

        InternalsNavigatorContentUtils::setNavigatorContentUtilsClientMock(*impl, document);
    }

    void setNavigatorContentUtilsClientMockMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        InternalsPartialV8Internal::setNavigatorContentUtilsClientMockMethod(info);
    }

    static void rtcCertificateEqualsMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        Internals* impl = V8Internals::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 2)) {
            V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("rtcCertificateEquals", "Internals", ExceptionMessages::notEnoughArguments(2, info.Length())));
            return;
        }

        RTCCertificate* a;
        RTCCertificate* b;
        a = V8RTCCertificate::toImplWithTypeCheck(info.GetIsolate(), info[0]);
        if (!a) {
            V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("rtcCertificateEquals", "Internals", "parameter 1 is not of type 'RTCCertificate'."));

            return;
        }

        b = V8RTCCertificate::toImplWithTypeCheck(info.GetIsolate(), info[1]);
        if (!b) {
            V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("rtcCertificateEquals", "Internals", "parameter 2 is not of type 'RTCCertificate'."));

            return;
        }

        v8SetReturnValueBool(info, InternalsRTCCertificate::rtcCertificateEquals(*impl, a, b));
    }

    void rtcCertificateEqualsMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        InternalsPartialV8Internal::rtcCertificateEqualsMethod(info);
    }

    static void terminateServiceWorkerMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        Internals* impl = V8Internals::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 1)) {
            V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("terminateServiceWorker", "Internals", ExceptionMessages::notEnoughArguments(1, info.Length())));
            return;
        }

        ServiceWorker* worker;
        worker = V8ServiceWorker::toImplWithTypeCheck(info.GetIsolate(), info[0]);
        if (!worker) {
            V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("terminateServiceWorker", "Internals", "parameter 1 is not of type 'ServiceWorker'."));

            return;
        }

        InternalsServiceWorker::terminateServiceWorker(*impl, worker);
    }

    void terminateServiceWorkerMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        InternalsPartialV8Internal::terminateServiceWorkerMethod(info);
    }

    static void enableMockSpeechSynthesizerMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        Internals* impl = V8Internals::toImpl(info.Holder());

        ScriptState* scriptState = ScriptState::forReceiverObject(info);

        if (UNLIKELY(info.Length() < 1)) {
            V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("enableMockSpeechSynthesizer", "Internals", ExceptionMessages::notEnoughArguments(1, info.Length())));
            return;
        }

        DOMWindow* window;
        window = toDOMWindow(info.GetIsolate(), info[0]);
        if (!window) {
            V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("enableMockSpeechSynthesizer", "Internals", "parameter 1 is not of type 'Window'."));

            return;
        }

        InternalsSpeechSynthesis::enableMockSpeechSynthesizer(scriptState, *impl, window);
    }

    void enableMockSpeechSynthesizerMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        InternalsPartialV8Internal::enableMockSpeechSynthesizerMethod(info);
    }

    static void isVibratingMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        Internals* impl = V8Internals::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 1)) {
            V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("isVibrating", "Internals", ExceptionMessages::notEnoughArguments(1, info.Length())));
            return;
        }

        Navigator* navigator;
        navigator = V8Navigator::toImplWithTypeCheck(info.GetIsolate(), info[0]);
        if (!navigator) {
            V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("isVibrating", "Internals", "parameter 1 is not of type 'Navigator'."));

            return;
        }

        v8SetReturnValueBool(info, InternalsVibration::isVibrating(*impl, navigator));
    }

    void isVibratingMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        InternalsPartialV8Internal::isVibratingMethod(info);
    }

    static void pendingVibrationPatternMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        Internals* impl = V8Internals::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 1)) {
            V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("pendingVibrationPattern", "Internals", ExceptionMessages::notEnoughArguments(1, info.Length())));
            return;
        }

        Navigator* navigator;
        navigator = V8Navigator::toImplWithTypeCheck(info.GetIsolate(), info[0]);
        if (!navigator) {
            V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("pendingVibrationPattern", "Internals", "parameter 1 is not of type 'Navigator'."));

            return;
        }

        v8SetReturnValue(info, ToV8(InternalsVibration::pendingVibrationPattern(*impl, navigator), info.Holder(), info.GetIsolate()));
    }

    void pendingVibrationPatternMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        InternalsPartialV8Internal::pendingVibrationPatternMethod(info);
    }

    static void audioHandlerCountMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        Internals* impl = V8Internals::toImpl(info.Holder());

        v8SetReturnValueUnsigned(info, InternalsWebAudio::audioHandlerCount(*impl));
    }

    void audioHandlerCountMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        InternalsPartialV8Internal::audioHandlerCountMethod(info);
    }

} // namespace InternalsPartialV8Internal

const V8DOMConfiguration::MethodConfiguration V8InternalsMethods[] = {
    { "numberOfLiveAXObjects", InternalsPartialV8Internal::numberOfLiveAXObjectsMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "getInternalResponseURLList", InternalsPartialV8Internal::getInternalResponseURLListMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "addFakeDevice", InternalsPartialV8Internal::addFakeDeviceMethodCallback, 0, 3, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::DoNotCheckHolder },
    { "setNavigatorContentUtilsClientMock", InternalsPartialV8Internal::setNavigatorContentUtilsClientMockMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "rtcCertificateEquals", InternalsPartialV8Internal::rtcCertificateEqualsMethodCallback, 0, 2, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "terminateServiceWorker", InternalsPartialV8Internal::terminateServiceWorkerMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "enableMockSpeechSynthesizer", InternalsPartialV8Internal::enableMockSpeechSynthesizerMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "isVibrating", InternalsPartialV8Internal::isVibratingMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "pendingVibrationPattern", InternalsPartialV8Internal::pendingVibrationPatternMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "audioHandlerCount", InternalsPartialV8Internal::audioHandlerCountMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

void V8InternalsPartial::installV8InternalsTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8Internals::installV8InternalsTemplate(isolate, world, interfaceTemplate);

    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
    ALLOW_UNUSED_LOCAL(instanceTemplate);
    v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
    ALLOW_UNUSED_LOCAL(prototypeTemplate);

    // Register DOM constants, attributes and operations.
    V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8InternalsMethods, WTF_ARRAY_LENGTH(V8InternalsMethods));
}

void V8InternalsPartial::initialize()
{
    // Should be invoked from ModulesInitializer.
    V8Internals::updateWrapperTypeInfo(
        &V8InternalsPartial::installV8InternalsTemplate,
        nullptr);
}

} // namespace blink
