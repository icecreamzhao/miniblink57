// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format on
#include "V8OffscreenCanvas.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/ScriptPromise.h"
#include "bindings/core/v8/ScriptState.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8ImageBitmap.h"
#include "bindings/core/v8/V8ImageEncodeOptions.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "core/dom/Document.h"
#include "core/frame/LocalDOMWindow.h"
#include "core/frame/UseCounter.h"
#include "platform/RuntimeEnabledFeatures.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace blink {

// Suppress warning: global constructors, because struct WrapperTypeInfo is trivial
// and does not depend on another global objects.
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
WrapperTypeInfo V8OffscreenCanvas::wrapperTypeInfo = { gin::kEmbedderBlink, V8OffscreenCanvas::domTemplate, V8OffscreenCanvas::trace, V8OffscreenCanvas::traceWrappers, 0, nullptr, "OffscreenCanvas", &V8EventTarget::wrapperTypeInfo, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::InheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in OffscreenCanvas.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& OffscreenCanvas::s_wrapperTypeInfo = V8OffscreenCanvas::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, OffscreenCanvas>::value,
    "OffscreenCanvas inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&OffscreenCanvas::hasPendingActivity),
        decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "OffscreenCanvas is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace OffscreenCanvasV8Internal {

    static void widthAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        OffscreenCanvas* impl = V8OffscreenCanvas::toImpl(holder);

        v8SetReturnValueUnsigned(info, impl->width());
    }

    CORE_EXPORT void widthAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        OffscreenCanvasV8Internal::widthAttributeGetter(info);
    }

    static void widthAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        OffscreenCanvas* impl = V8OffscreenCanvas::toImpl(holder);

        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::SetterContext, "OffscreenCanvas", "width");

        // Prepare the value to be set.
        unsigned cppValue = toUInt32(info.GetIsolate(), v8Value, EnforceRange, exceptionState);
        if (exceptionState.hadException())
            return;

        impl->setWidth(cppValue);
    }

    CORE_EXPORT void widthAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        OffscreenCanvasV8Internal::widthAttributeSetter(v8Value, info);
    }

    static void heightAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();

        OffscreenCanvas* impl = V8OffscreenCanvas::toImpl(holder);

        v8SetReturnValueUnsigned(info, impl->height());
    }

    CORE_EXPORT void heightAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        OffscreenCanvasV8Internal::heightAttributeGetter(info);
    }

    static void heightAttributeSetter(v8::Local<v8::Value> v8Value, const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Object> holder = info.Holder();
        OffscreenCanvas* impl = V8OffscreenCanvas::toImpl(holder);

        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::SetterContext, "OffscreenCanvas", "height");

        // Prepare the value to be set.
        unsigned cppValue = toUInt32(info.GetIsolate(), v8Value, EnforceRange, exceptionState);
        if (exceptionState.hadException())
            return;

        impl->setHeight(cppValue);
    }

    CORE_EXPORT void heightAttributeSetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        v8::Local<v8::Value> v8Value = info[0];

        OffscreenCanvasV8Internal::heightAttributeSetter(v8Value, info);
    }

    static void transferToImageBitmapMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "OffscreenCanvas", "transferToImageBitmap");

        OffscreenCanvas* impl = V8OffscreenCanvas::toImpl(info.Holder());

        ScriptState* scriptState = ScriptState::forReceiverObject(info);

        ImageBitmap* result = impl->transferToImageBitmap(scriptState, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
        v8SetReturnValue(info, result);
    }

    CORE_EXPORT void transferToImageBitmapMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        OffscreenCanvasV8Internal::transferToImageBitmapMethod(info);
    }

    static void convertToBlobMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "OffscreenCanvas", "convertToBlob");
        ExceptionToRejectPromiseScope rejectPromiseScope(info, exceptionState);

        // V8DOMConfiguration::DoNotCheckHolder
        // Make sure that info.Holder() really points to an instance of the type.
        if (!V8OffscreenCanvas::hasInstance(info.Holder(), info.GetIsolate())) {
            exceptionState.throwTypeError("Illegal invocation");
            return;
        }
        OffscreenCanvas* impl = V8OffscreenCanvas::toImpl(info.Holder());

        ScriptState* scriptState = ScriptState::forReceiverObject(info);

        ImageEncodeOptions options;
        if (!isUndefinedOrNull(info[0]) && !info[0]->IsObject()) {
            exceptionState.throwTypeError("parameter 1 ('options') is not an object.");

            return;
        }
        V8ImageEncodeOptions::toImpl(info.GetIsolate(), info[0], options, exceptionState);
        if (exceptionState.hadException())
            return;

        ScriptPromise result = impl->convertToBlob(scriptState, options, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
        v8SetReturnValue(info, result.v8Value());
    }

    CORE_EXPORT void convertToBlobMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        OffscreenCanvasV8Internal::convertToBlobMethod(info);
    }

    static void constructor(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ConstructionContext, "OffscreenCanvas");

        if (UNLIKELY(info.Length() < 2)) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(2, info.Length()));
            return;
        }

        unsigned width;
        unsigned height;
        width = toUInt32(info.GetIsolate(), info[0], EnforceRange, exceptionState);
        if (exceptionState.hadException())
            return;

        height = toUInt32(info.GetIsolate(), info[1], EnforceRange, exceptionState);
        if (exceptionState.hadException())
            return;

        OffscreenCanvas* impl = OffscreenCanvas::create(width, height);
        v8::Local<v8::Object> wrapper = info.Holder();
        wrapper = impl->associateWithWrapper(info.GetIsolate(), &V8OffscreenCanvas::wrapperTypeInfo, wrapper);
        v8SetReturnValue(info, wrapper);
    }

} // namespace OffscreenCanvasV8Internal

const V8DOMConfiguration::AccessorConfiguration V8OffscreenCanvasAccessors[] = {
    { "width", OffscreenCanvasV8Internal::widthAttributeGetterCallback, OffscreenCanvasV8Internal::widthAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "height", OffscreenCanvasV8Internal::heightAttributeGetterCallback, OffscreenCanvasV8Internal::heightAttributeSetterCallback, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::None), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

const V8DOMConfiguration::MethodConfiguration V8OffscreenCanvasMethods[] = {
    { "transferToImageBitmap", OffscreenCanvasV8Internal::transferToImageBitmapMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "convertToBlob", OffscreenCanvasV8Internal::convertToBlobMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::DoNotCheckHolder },
};

void V8OffscreenCanvas::constructorCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::OffscreenCanvas);
    if (!info.IsConstructCall()) {
        V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::constructorNotCallableAsFunction("OffscreenCanvas"));
        return;
    }

    if (ConstructorMode::current(info.GetIsolate()) == ConstructorMode::WrapExistingObject) {
        v8SetReturnValue(info, info.Holder());
        return;
    }

    OffscreenCanvasV8Internal::constructor(info);
}

void V8OffscreenCanvas::installV8OffscreenCanvasTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8OffscreenCanvas::wrapperTypeInfo.interfaceName, V8EventTarget::domTemplate(isolate, world), V8OffscreenCanvas::internalFieldCount);
    interfaceTemplate->SetCallHandler(V8OffscreenCanvas::constructorCallback);
    interfaceTemplate->SetLength(2);

    if (!RuntimeEnabledFeatures::experimentalCanvasFeaturesEnabled()) {
        return;
    }

    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
    ALLOW_UNUSED_LOCAL(instanceTemplate);
    v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
    ALLOW_UNUSED_LOCAL(prototypeTemplate);

    // Register DOM constants, attributes and operations.
    V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8OffscreenCanvasAccessors, WTF_ARRAY_LENGTH(V8OffscreenCanvasAccessors));
    V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8OffscreenCanvasMethods, WTF_ARRAY_LENGTH(V8OffscreenCanvasMethods));
}

v8::Local<v8::FunctionTemplate> V8OffscreenCanvas::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world)
{
    return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), V8OffscreenCanvas::installV8OffscreenCanvasTemplateFunction);
}

bool V8OffscreenCanvas::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8OffscreenCanvas::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

OffscreenCanvas* V8OffscreenCanvas::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value)
{
    return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

InstallTemplateFunction V8OffscreenCanvas::installV8OffscreenCanvasTemplateFunction = (InstallTemplateFunction)&V8OffscreenCanvas::installV8OffscreenCanvasTemplate;

void V8OffscreenCanvas::updateWrapperTypeInfo(InstallTemplateFunction installTemplateFunction, PreparePrototypeAndInterfaceObjectFunction preparePrototypeAndInterfaceObjectFunction)
{
    V8OffscreenCanvas::installV8OffscreenCanvasTemplateFunction = installTemplateFunction;
    if (preparePrototypeAndInterfaceObjectFunction)
        V8OffscreenCanvas::wrapperTypeInfo.preparePrototypeAndInterfaceObjectFunction = preparePrototypeAndInterfaceObjectFunction;
}

} // namespace blink
