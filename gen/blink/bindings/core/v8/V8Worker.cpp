// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format on
#include "V8Worker.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/SerializedScriptValue.h"
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
#include "core/frame/LocalDOMWindow.h"
#include "core/workers/AbstractWorker.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace blink {

// Suppress warning: global constructors, because struct WrapperTypeInfo is trivial
// and does not depend on another global objects.
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
const WrapperTypeInfo V8Worker::wrapperTypeInfo = { gin::kEmbedderBlink, V8Worker::domTemplate, V8Worker::trace, V8Worker::traceWrappers, 0, nullptr, "Worker", &V8EventTarget::wrapperTypeInfo, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::InheritFromActiveScriptWrappable, WrapperTypeInfo::InheritFromEventTarget, WrapperTypeInfo::Dependent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in Worker.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& Worker::s_wrapperTypeInfo = V8Worker::wrapperTypeInfo;

// [ActiveScriptWrappable]
static_assert(
    std::is_base_of<ActiveScriptWrappableBase, Worker>::value,
    "Worker does not inherit from ActiveScriptWrappable<>, but specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    !std::is_same<decltype(&Worker::hasPendingActivity),
        decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "Worker is not overriding hasPendingActivity(), but is specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace WorkerV8Internal {

    static void onmessageAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        Worker* impl = V8Worker::toImpl(holder);

        EventListener* cppValue(WTF::getPtr(impl->onmessage()));

        v8SetReturnValue(info, cppValue ? V8AbstractEventListener::cast(cppValue)->getListenerOrNull(info.GetIsolate(), impl->getExecutionContext()) : v8::Null(info.GetIsolate()).As<v8::Value>());
    }

    CORE_EXPORT void onmessageAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        WorkerV8Internal::onmessageAttributeGetter(info);
    }

    static void onmessageAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        Worker* impl = V8Worker::toImpl(holder);

        // Prepare the value to be set.
        moveEventListenerToNewWrapper(info.GetIsolate(), holder, impl->onmessage(), v8Value, V8Worker::eventListenerCacheIndex);

        impl->setOnmessage(V8EventListenerHelper::getEventListener(ScriptState::forReceiverObject(info), v8Value, true, ListenerFindOrCreate));
    }

    CORE_EXPORT void onmessageAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        WorkerV8Internal::onmessageAttributeSetter(v8Value, info);
    }

    static void onerrorAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        Worker* impl = V8Worker::toImpl(holder);

        EventListener* cppValue(AbstractWorker::onerror(*impl));

        v8SetReturnValue(info, cppValue ? V8AbstractEventListener::cast(cppValue)->getListenerOrNull(info.GetIsolate(), impl->getExecutionContext()) : v8::Null(info.GetIsolate()).As<v8::Value>());
    }

    CORE_EXPORT void onerrorAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        WorkerV8Internal::onerrorAttributeGetter(info);
    }

    static void onerrorAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        Worker* impl = V8Worker::toImpl(holder);

        // Prepare the value to be set.
        moveEventListenerToNewWrapper(info.GetIsolate(), holder, AbstractWorker::onerror(*impl), v8Value, V8Worker::eventListenerCacheIndex);

        AbstractWorker::setOnerror(*impl, V8EventListenerHelper::getEventListener(ScriptState::forReceiverObject(info), v8Value, true, ListenerFindOrCreate));
    }

    CORE_EXPORT void onerrorAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        WorkerV8Internal::onerrorAttributeSetter(v8Value, info);
    }

    static void terminateMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        Worker* impl = V8Worker::toImpl(info.Holder());

        impl->terminate();
    }

    CORE_EXPORT void terminateMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        WorkerV8Internal::terminateMethod(info);
    }

    static void postMessageImpl(const char* interfaceName, Worker* instance, const v8::FunctionCallbackInfo<v8::Value>& info)
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
        postMessageImpl("Worker", V8Worker::toImpl(info.Holder()), info);
    }

    static void constructor(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ConstructionContext, "Worker");

        if (UNLIKELY(info.Length() < 1)) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
            return;
        }

        V8StringResource<> scriptUrl;
        scriptUrl = info[0];
        if (!scriptUrl.prepare())
            return;

        ExecutionContext* executionContext = currentExecutionContext(info.GetIsolate());
        Worker* impl = Worker::create(executionContext, scriptUrl, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
        v8::Local<v8::Object> wrapper = info.Holder();
        wrapper = impl->associateWithWrapper(info.GetIsolate(), &V8Worker::wrapperTypeInfo, wrapper);
        v8SetReturnValue(info, wrapper);
    }

} // namespace WorkerV8Internal

const V8DOMConfiguration::AccessorConfiguration V8WorkerAccessors[] = {
    { "onmessage", WorkerV8Internal::onmessageAttributeGetterCallback, WorkerV8Internal::onmessageAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "onerror", WorkerV8Internal::onerrorAttributeGetterCallback, WorkerV8Internal::onerrorAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

const V8DOMConfiguration::MethodConfiguration V8WorkerMethods[] = {
    { "terminate", WorkerV8Internal::terminateMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "postMessage", WorkerV8Internal::postMessageMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

void V8Worker::constructorCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (!info.IsConstructCall()) {
        V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::constructorNotCallableAsFunction("Worker"));
        return;
    }

    if (ConstructorMode::current(info.GetIsolate()) == ConstructorMode::WrapExistingObject) {
        v8SetReturnValue(info, info.Holder());
        return;
    }

    WorkerV8Internal::constructor(info);
}

static void installV8WorkerTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8Worker::wrapperTypeInfo.interfaceName, V8EventTarget::domTemplate(isolate, world), V8Worker::internalFieldCount);
    interfaceTemplate->SetCallHandler(V8Worker::constructorCallback);
    interfaceTemplate->SetLength(1);

    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
    ALLOW_UNUSED_LOCAL(instanceTemplate);
    v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
    ALLOW_UNUSED_LOCAL(prototypeTemplate);

    // Register DOM constants, attributes and operations.
    V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8WorkerAccessors, WTF_ARRAY_LENGTH(V8WorkerAccessors));
    V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8WorkerMethods, WTF_ARRAY_LENGTH(V8WorkerMethods));
}

v8::Local<v8::FunctionTemplate> V8Worker::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world)
{
    return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8WorkerTemplate);
}

bool V8Worker::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8Worker::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

Worker* V8Worker::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value)
{
    return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

} // namespace blink
