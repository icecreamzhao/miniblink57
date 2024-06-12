// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format on
#include "V8AudioBuffer.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8ArrayBufferView.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8Float32Array.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/modules/v8/V8AudioBufferOptions.h"
#include "bindings/modules/v8/V8BaseAudioContext.h"
#include "core/dom/Document.h"
#include "core/dom/FlexibleArrayBufferView.h"
#include "core/frame/LocalDOMWindow.h"
#include "core/frame/UseCounter.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace blink {

// Suppress warning: global constructors, because struct WrapperTypeInfo is trivial
// and does not depend on another global objects.
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
const WrapperTypeInfo V8AudioBuffer::wrapperTypeInfo = { gin::kEmbedderBlink, V8AudioBuffer::domTemplate, V8AudioBuffer::trace, V8AudioBuffer::traceWrappers, 0, nullptr, "AudioBuffer", 0, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in AudioBuffer.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& AudioBuffer::s_wrapperTypeInfo = V8AudioBuffer::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, AudioBuffer>::value,
    "AudioBuffer inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&AudioBuffer::hasPendingActivity),
        decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "AudioBuffer is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace AudioBufferV8Internal {

    static void lengthAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        AudioBuffer* impl = V8AudioBuffer::toImpl(holder);

        v8SetReturnValueInt(info, impl->length());
    }

    MODULES_EXPORT void lengthAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        AudioBufferV8Internal::lengthAttributeGetter(info);
    }

    static void durationAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        AudioBuffer* impl = V8AudioBuffer::toImpl(holder);

        v8SetReturnValue(info, impl->duration());
    }

    MODULES_EXPORT void durationAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        AudioBufferV8Internal::durationAttributeGetter(info);
    }

    static void sampleRateAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        AudioBuffer* impl = V8AudioBuffer::toImpl(holder);

        v8SetReturnValue(info, impl->sampleRate());
    }

    MODULES_EXPORT void sampleRateAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        AudioBufferV8Internal::sampleRateAttributeGetter(info);
    }

    static void numberOfChannelsAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        AudioBuffer* impl = V8AudioBuffer::toImpl(holder);

        v8SetReturnValueUnsigned(info, impl->numberOfChannels());
    }

    MODULES_EXPORT void numberOfChannelsAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        AudioBufferV8Internal::numberOfChannelsAttributeGetter(info);
    }

    static void getChannelDataMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "AudioBuffer", "getChannelData");

        AudioBuffer* impl = V8AudioBuffer::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 1)) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
            return;
        }

        unsigned channelIndex;
        channelIndex = toUInt32(info.GetIsolate(), info[0], NormalConversion, exceptionState);
        if (exceptionState.hadException())
            return;

        DOMFloat32Array* result = impl->getChannelData(channelIndex, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
        v8SetReturnValue(info, result);
    }

    MODULES_EXPORT void getChannelDataMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        AudioBufferV8Internal::getChannelDataMethod(info);
    }

    static void copyFromChannelMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "AudioBuffer", "copyFromChannel");

        AudioBuffer* impl = V8AudioBuffer::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 2)) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(2, info.Length()));
            return;
        }

        DOMFloat32Array* destination;
        int channelNumber;
        unsigned startInChannel;
        destination = info[0]->IsFloat32Array() ? V8Float32Array::toImpl(v8::Local<v8::Float32Array>::Cast(info[0])) : 0;
        if (!destination) {
            exceptionState.throwTypeError("parameter 1 is not of type 'Float32Array'.");

            return;
        }

        channelNumber = toInt32(info.GetIsolate(), info[1], NormalConversion, exceptionState);
        if (exceptionState.hadException())
            return;

        if (!info[2]->IsUndefined()) {
            startInChannel = toUInt32(info.GetIsolate(), info[2], NormalConversion, exceptionState);
            if (exceptionState.hadException())
                return;
        } else {
            startInChannel = 0u;
        }

        impl->copyFromChannel(destination, channelNumber, startInChannel, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
    }

    MODULES_EXPORT void copyFromChannelMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        AudioBufferV8Internal::copyFromChannelMethod(info);
    }

    static void copyToChannelMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "AudioBuffer", "copyToChannel");

        AudioBuffer* impl = V8AudioBuffer::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 2)) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(2, info.Length()));
            return;
        }

        DOMFloat32Array* source;
        int channelNumber;
        unsigned startInChannel;
        source = info[0]->IsFloat32Array() ? V8Float32Array::toImpl(v8::Local<v8::Float32Array>::Cast(info[0])) : 0;
        if (!source) {
            exceptionState.throwTypeError("parameter 1 is not of type 'Float32Array'.");

            return;
        }

        channelNumber = toInt32(info.GetIsolate(), info[1], NormalConversion, exceptionState);
        if (exceptionState.hadException())
            return;

        if (!info[2]->IsUndefined()) {
            startInChannel = toUInt32(info.GetIsolate(), info[2], NormalConversion, exceptionState);
            if (exceptionState.hadException())
                return;
        } else {
            startInChannel = 0u;
        }

        impl->copyToChannel(source, channelNumber, startInChannel, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
    }

    MODULES_EXPORT void copyToChannelMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        AudioBufferV8Internal::copyToChannelMethod(info);
    }

    static void constructor(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ConstructionContext, "AudioBuffer");

        if (UNLIKELY(info.Length() < 2)) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(2, info.Length()));
            return;
        }

        BaseAudioContext* context;
        AudioBufferOptions options;
        context = V8BaseAudioContext::toImplWithTypeCheck(info.GetIsolate(), info[0]);
        if (!context) {
            exceptionState.throwTypeError("parameter 1 is not of type 'BaseAudioContext'.");

            return;
        }

        if (!isUndefinedOrNull(info[1]) && !info[1]->IsObject()) {
            exceptionState.throwTypeError("parameter 2 ('options') is not an object.");

            return;
        }
        V8AudioBufferOptions::toImpl(info.GetIsolate(), info[1], options, exceptionState);
        if (exceptionState.hadException())
            return;

        AudioBuffer* impl = AudioBuffer::create(context, options, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
        v8::Local<v8::Object> wrapper = info.Holder();
        wrapper = impl->associateWithWrapper(info.GetIsolate(), &V8AudioBuffer::wrapperTypeInfo, wrapper);
        v8SetReturnValue(info, wrapper);
    }

} // namespace AudioBufferV8Internal

const V8DOMConfiguration::AccessorConfiguration V8AudioBufferAccessors[] = {
    { "length", AudioBufferV8Internal::lengthAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "duration", AudioBufferV8Internal::durationAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "sampleRate", AudioBufferV8Internal::sampleRateAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "numberOfChannels", AudioBufferV8Internal::numberOfChannelsAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

const V8DOMConfiguration::MethodConfiguration V8AudioBufferMethods[] = {
    { "getChannelData", AudioBufferV8Internal::getChannelDataMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "copyFromChannel", AudioBufferV8Internal::copyFromChannelMethodCallback, 0, 2, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "copyToChannel", AudioBufferV8Internal::copyToChannelMethodCallback, 0, 2, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

void V8AudioBuffer::constructorCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::V8AudioBuffer_Constructor);
    if (!info.IsConstructCall()) {
        V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::constructorNotCallableAsFunction("AudioBuffer"));
        return;
    }

    if (ConstructorMode::current(info.GetIsolate()) == ConstructorMode::WrapExistingObject) {
        v8SetReturnValue(info, info.Holder());
        return;
    }

    AudioBufferV8Internal::constructor(info);
}

static void installV8AudioBufferTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8AudioBuffer::wrapperTypeInfo.interfaceName, v8::Local<v8::FunctionTemplate>(), V8AudioBuffer::internalFieldCount);
    interfaceTemplate->SetCallHandler(V8AudioBuffer::constructorCallback);
    interfaceTemplate->SetLength(2);

    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
    ALLOW_UNUSED_LOCAL(instanceTemplate);
    v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
    ALLOW_UNUSED_LOCAL(prototypeTemplate);

    // Register DOM constants, attributes and operations.
    V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8AudioBufferAccessors, WTF_ARRAY_LENGTH(V8AudioBufferAccessors));
    V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8AudioBufferMethods, WTF_ARRAY_LENGTH(V8AudioBufferMethods));
}

v8::Local<v8::FunctionTemplate> V8AudioBuffer::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world)
{
    return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8AudioBufferTemplate);
}

bool V8AudioBuffer::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8AudioBuffer::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

AudioBuffer* V8AudioBuffer::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value)
{
    return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

} // namespace blink
