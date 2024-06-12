// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format on
#include "V8MessagePort.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/ScriptValue.h"
#include "bindings/core/v8/SerializedScriptValueFactory.h"
#include "bindings/core/v8/Transferables.h"
#include "bindings/core/v8/V8AbstractEventListener.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8EventListenerHelper.h"
#include "bindings/core/v8/V8MessagePort.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "core/dom/DOMArrayBufferBase.h"
#include "core/dom/Document.h"
#include "core/frame/ImageBitmap.h"
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
const WrapperTypeInfo V8MessagePort::wrapperTypeInfo = { gin::kEmbedderBlink, V8MessagePort::domTemplate, V8MessagePort::trace, V8MessagePort::traceWrappers, 0, nullptr, "MessagePort", &V8EventTarget::wrapperTypeInfo, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::InheritFromActiveScriptWrappable, WrapperTypeInfo::InheritFromEventTarget, WrapperTypeInfo::Dependent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in MessagePort.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& MessagePort::s_wrapperTypeInfo = V8MessagePort::wrapperTypeInfo;

// [ActiveScriptWrappable]
static_assert(
    std::is_base_of<ActiveScriptWrappableBase, MessagePort>::value,
    "MessagePort does not inherit from ActiveScriptWrappable<>, but specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    !std::is_same<decltype(&MessagePort::hasPendingActivity),
        decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "MessagePort is not overriding hasPendingActivity(), but is specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace MessagePortV8Internal {

    static void onmessageAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        MessagePort* impl = V8MessagePort::toImpl(holder);

        EventListener* cppValue(WTF::getPtr(impl->onmessage()));

        v8SetReturnValue(info, cppValue ? V8AbstractEventListener::cast(cppValue)->getListenerOrNull(info.GetIsolate(), impl->getExecutionContext()) : v8::Null(info.GetIsolate()).As<v8::Value>());
    }

    CORE_EXPORT void onmessageAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        MessagePortV8Internal::onmessageAttributeGetter(info);
    }

    static void onmessageAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        MessagePort* impl = V8MessagePort::toImpl(holder);

        // Prepare the value to be set.
        moveEventListenerToNewWrapper(info.GetIsolate(), holder, impl->onmessage(), v8Value, V8MessagePort::eventListenerCacheIndex);

        impl->setOnmessage(V8EventListenerHelper::getEventListener(ScriptState::forReceiverObject(info), v8Value, true, ListenerFindOrCreate));
    }

    CORE_EXPORT void onmessageAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        MessagePortV8Internal::onmessageAttributeSetter(v8Value, info);
    }

    static void postMessageImpl(const char* interfaceName, MessagePort* instance, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, interfaceName, "postMessage");
        if (UNLIKELY(info.Length() < 1)) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
            return;
        }

        Transferables transferables;
        if (info.Length() > 1) {
            const int transferablesArgIndex = 1;
            if (!SerializedScriptValue::extractTransferables(info.GetIsolate(), info[transferablesArgIndex], transferablesArgIndex, transferables, exceptionState)) {
                return;
            }
        }

        RefPtr<SerializedScriptValue> message;
        if (instance->canTransferArrayBuffersAndImageBitmaps()) {
            // This instance supports sending array buffers by move semantics.
            message = SerializedScriptValue::serialize(info.GetIsolate(), info[0], &transferables, nullptr, exceptionState);
            if (exceptionState.hadException())
                return;
        } else {
            // This instance doesn't support sending array buffers and image bitmaps
            // by move semantics. Emulate it by copy-and-neuter semantics that sends
            // array buffers and image bitmaps via structured clone and then neuters
            // the original objects

            // Clear references to array buffers and image bitmaps from transferables
            // so that the serializer can consider the array buffers as
            // non-transferable and serialize them into the message.
            ArrayBufferArray transferableArrayBuffers = transferables.arrayBuffers;
            transferables.arrayBuffers.clear();
            ImageBitmapArray transferableImageBitmaps = transferables.imageBitmaps;
            transferables.imageBitmaps.clear();
            message = SerializedScriptValue::serialize(info.GetIsolate(), info[0], &transferables, nullptr, exceptionState);
            if (exceptionState.hadException())
                return;

            // Neuter the original array buffers on the sender context.
            SerializedScriptValue::transferArrayBufferContents(info.GetIsolate(), transferableArrayBuffers, exceptionState);
            if (exceptionState.hadException())
                return;
            // Neuter the original image bitmaps on the sender context.
            SerializedScriptValue::transferImageBitmapContents(info.GetIsolate(), transferableImageBitmaps, exceptionState);
            if (exceptionState.hadException())
                return;
        }

        // FIXME: Only pass context/exceptionState if instance really requires it.
        ExecutionContext* context = currentExecutionContext(info.GetIsolate());
        instance->postMessage(context, message.release(), transferables.messagePorts, exceptionState);
    }

    CORE_EXPORT void postMessageMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::V8MessagePort_PostMessage_Method);
        postMessageImpl("MessagePort", V8MessagePort::toImpl(info.Holder()), info);
    }

    static void startMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        MessagePort* impl = V8MessagePort::toImpl(info.Holder());

        impl->start();
    }

    CORE_EXPORT void startMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::V8MessagePort_Start_Method);
        MessagePortV8Internal::startMethod(info);
    }

    static void closeMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        MessagePort* impl = V8MessagePort::toImpl(info.Holder());

        impl->close();
    }

    CORE_EXPORT void closeMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::V8MessagePort_Close_Method);
        MessagePortV8Internal::closeMethod(info);
    }

} // namespace MessagePortV8Internal

const V8DOMConfiguration::AccessorConfiguration V8MessagePortAccessors[] = {
    { "onmessage", MessagePortV8Internal::onmessageAttributeGetterCallback, MessagePortV8Internal::onmessageAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

const V8DOMConfiguration::MethodConfiguration V8MessagePortMethods[] = {
    { "postMessage", MessagePortV8Internal::postMessageMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "start", MessagePortV8Internal::startMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "close", MessagePortV8Internal::closeMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

static void installV8MessagePortTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8MessagePort::wrapperTypeInfo.interfaceName, V8EventTarget::domTemplate(isolate, world), V8MessagePort::internalFieldCount);

    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
    ALLOW_UNUSED_LOCAL(instanceTemplate);
    v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
    ALLOW_UNUSED_LOCAL(prototypeTemplate);

    // Register DOM constants, attributes and operations.
    V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8MessagePortAccessors, WTF_ARRAY_LENGTH(V8MessagePortAccessors));
    V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8MessagePortMethods, WTF_ARRAY_LENGTH(V8MessagePortMethods));
}

v8::Local<v8::FunctionTemplate> V8MessagePort::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world)
{
    return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8MessagePortTemplate);
}

bool V8MessagePort::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8MessagePort::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

MessagePort* V8MessagePort::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value)
{
    return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

} // namespace blink
