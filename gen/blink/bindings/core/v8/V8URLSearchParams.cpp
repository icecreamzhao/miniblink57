// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format on
#include "V8URLSearchParams.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/ScriptState.h"
#include "bindings/core/v8/ScriptValue.h"
#include "bindings/core/v8/USVStringOrURLSearchParams.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8Iterator.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/core/v8/V8URLSearchParams.h"
#include "core/dom/Document.h"
#include "core/frame/LocalDOMWindow.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace blink {

// Suppress warning: global constructors, because struct WrapperTypeInfo is trivial
// and does not depend on another global objects.
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
const WrapperTypeInfo V8URLSearchParams::wrapperTypeInfo = { gin::kEmbedderBlink, V8URLSearchParams::domTemplate, V8URLSearchParams::trace, V8URLSearchParams::traceWrappers, 0, nullptr, "URLSearchParams", 0, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in URLSearchParams.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& URLSearchParams::s_wrapperTypeInfo = V8URLSearchParams::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, URLSearchParams>::value,
    "URLSearchParams inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&URLSearchParams::hasPendingActivity),
        decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "URLSearchParams is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace URLSearchParamsV8Internal {

    static void appendMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "URLSearchParams", "append");

        URLSearchParams* impl = V8URLSearchParams::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 2)) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(2, info.Length()));
            return;
        }

        V8StringResource<> name;
        V8StringResource<> value;
        name = toUSVString(info.GetIsolate(), info[0], exceptionState);
        if (exceptionState.hadException())
            return;

        value = toUSVString(info.GetIsolate(), info[1], exceptionState);
        if (exceptionState.hadException())
            return;

        impl->append(name, value);
    }

    CORE_EXPORT void appendMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        URLSearchParamsV8Internal::appendMethod(info);
    }

    static void deleteMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "URLSearchParams", "delete");

        URLSearchParams* impl = V8URLSearchParams::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 1)) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
            return;
        }

        V8StringResource<> name;
        name = toUSVString(info.GetIsolate(), info[0], exceptionState);
        if (exceptionState.hadException())
            return;

        impl->deleteAllWithName(name);
    }

    CORE_EXPORT void deleteMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        URLSearchParamsV8Internal::deleteMethod(info);
    }

    static void getMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "URLSearchParams", "get");

        URLSearchParams* impl = V8URLSearchParams::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 1)) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
            return;
        }

        V8StringResource<> name;
        name = toUSVString(info.GetIsolate(), info[0], exceptionState);
        if (exceptionState.hadException())
            return;

        v8SetReturnValueStringOrNull(info, impl->get(name), info.GetIsolate());
    }

    CORE_EXPORT void getMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        URLSearchParamsV8Internal::getMethod(info);
    }

    static void getAllMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "URLSearchParams", "getAll");

        URLSearchParams* impl = V8URLSearchParams::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 1)) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
            return;
        }

        V8StringResource<> name;
        name = toUSVString(info.GetIsolate(), info[0], exceptionState);
        if (exceptionState.hadException())
            return;

        v8SetReturnValue(info, ToV8(impl->getAll(name), info.Holder(), info.GetIsolate()));
    }

    CORE_EXPORT void getAllMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        URLSearchParamsV8Internal::getAllMethod(info);
    }

    static void hasMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "URLSearchParams", "has");

        URLSearchParams* impl = V8URLSearchParams::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 1)) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
            return;
        }

        V8StringResource<> name;
        name = toUSVString(info.GetIsolate(), info[0], exceptionState);
        if (exceptionState.hadException())
            return;

        v8SetReturnValueBool(info, impl->has(name));
    }

    CORE_EXPORT void hasMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        URLSearchParamsV8Internal::hasMethod(info);
    }

    static void setMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "URLSearchParams", "set");

        URLSearchParams* impl = V8URLSearchParams::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 2)) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(2, info.Length()));
            return;
        }

        V8StringResource<> name;
        V8StringResource<> value;
        name = toUSVString(info.GetIsolate(), info[0], exceptionState);
        if (exceptionState.hadException())
            return;

        value = toUSVString(info.GetIsolate(), info[1], exceptionState);
        if (exceptionState.hadException())
            return;

        impl->set(name, value);
    }

    CORE_EXPORT void setMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        URLSearchParamsV8Internal::setMethod(info);
    }

    static void keysMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "URLSearchParams", "keys");

        URLSearchParams* impl = V8URLSearchParams::toImpl(info.Holder());

        ScriptState* scriptState = ScriptState::forReceiverObject(info);

        Iterator* result = impl->keysForBinding(scriptState, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
        v8SetReturnValue(info, result);
    }

    CORE_EXPORT void keysMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        URLSearchParamsV8Internal::keysMethod(info);
    }

    static void valuesMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "URLSearchParams", "values");

        URLSearchParams* impl = V8URLSearchParams::toImpl(info.Holder());

        ScriptState* scriptState = ScriptState::forReceiverObject(info);

        Iterator* result = impl->valuesForBinding(scriptState, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
        v8SetReturnValue(info, result);
    }

    CORE_EXPORT void valuesMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        URLSearchParamsV8Internal::valuesMethod(info);
    }

    static void entriesMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "URLSearchParams", "entries");

        URLSearchParams* impl = V8URLSearchParams::toImpl(info.Holder());

        ScriptState* scriptState = ScriptState::forReceiverObject(info);

        Iterator* result = impl->entriesForBinding(scriptState, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
        v8SetReturnValue(info, result);
    }

    CORE_EXPORT void entriesMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        URLSearchParamsV8Internal::entriesMethod(info);
    }

    static void forEachMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "URLSearchParams", "forEach");

        URLSearchParams* impl = V8URLSearchParams::toImpl(info.Holder());

        ScriptState* scriptState = ScriptState::forReceiverObject(info);

        if (UNLIKELY(info.Length() < 1)) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
            return;
        }

        ScriptValue callback;
        ScriptValue thisArg;
        if (!(info[0]->IsObject() && v8::Local<v8::Object>::Cast(info[0])->IsCallable())) {
            exceptionState.throwTypeError("The callback provided as parameter 1 is not a function.");

            return;
        }
        callback = ScriptValue(ScriptState::current(info.GetIsolate()), info[0]);

        thisArg = ScriptValue(ScriptState::current(info.GetIsolate()), info[1]);

        impl->forEachForBinding(scriptState, ScriptValue(scriptState, info.Holder()), callback, thisArg, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
    }

    CORE_EXPORT void forEachMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        URLSearchParamsV8Internal::forEachMethod(info);
    }

    static void toStringMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        URLSearchParams* impl = V8URLSearchParams::toImpl(info.Holder());

        v8SetReturnValueString(info, impl->toString(), info.GetIsolate());
    }

    CORE_EXPORT void toStringMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        URLSearchParamsV8Internal::toStringMethod(info);
    }

    static void iteratorMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "URLSearchParams", "iterator");

        URLSearchParams* impl = V8URLSearchParams::toImpl(info.Holder());

        ScriptState* scriptState = ScriptState::forReceiverObject(info);

        Iterator* result = impl->iterator(scriptState, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
        v8SetReturnValue(info, result);
    }

    CORE_EXPORT void iteratorMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        URLSearchParamsV8Internal::iteratorMethod(info);
    }

    static void constructor(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ConstructionContext, "URLSearchParams");

        USVStringOrURLSearchParams init;
        if (!info[0]->IsUndefined()) {
            V8USVStringOrURLSearchParams::toImpl(info.GetIsolate(), info[0], init, UnionTypeConversionMode::NotNullable, exceptionState);
            if (exceptionState.hadException())
                return;
        } else {
            init.setUSVString(String(""));
        }

        URLSearchParams* impl = URLSearchParams::create(init);
        v8::Local<v8::Object> wrapper = info.Holder();
        wrapper = impl->associateWithWrapper(info.GetIsolate(), &V8URLSearchParams::wrapperTypeInfo, wrapper);
        v8SetReturnValue(info, wrapper);
    }

} // namespace URLSearchParamsV8Internal

const V8DOMConfiguration::MethodConfiguration V8URLSearchParamsMethods[] = {
    { "append", URLSearchParamsV8Internal::appendMethodCallback, 0, 2, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "delete", URLSearchParamsV8Internal::deleteMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "get", URLSearchParamsV8Internal::getMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "getAll", URLSearchParamsV8Internal::getAllMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "has", URLSearchParamsV8Internal::hasMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "set", URLSearchParamsV8Internal::setMethodCallback, 0, 2, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "keys", URLSearchParamsV8Internal::keysMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "values", URLSearchParamsV8Internal::valuesMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "entries", URLSearchParamsV8Internal::entriesMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "forEach", URLSearchParamsV8Internal::forEachMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "toString", URLSearchParamsV8Internal::toStringMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

void V8URLSearchParams::constructorCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    OutputDebugStringA("constructorCallback!!!!!!!!!!!!!!!!\n");
    if (!info.IsConstructCall()) {
        V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::constructorNotCallableAsFunction("URLSearchParams"));
        return;
    }

    if (ConstructorMode::current(info.GetIsolate()) == ConstructorMode::WrapExistingObject) {
        v8SetReturnValue(info, info.Holder());
        return;
    }

    URLSearchParamsV8Internal::constructor(info);
}

static void installV8URLSearchParamsTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8URLSearchParams::wrapperTypeInfo.interfaceName, v8::Local<v8::FunctionTemplate>(), V8URLSearchParams::internalFieldCount);
    interfaceTemplate->SetCallHandler(V8URLSearchParams::constructorCallback);
    interfaceTemplate->SetLength(0);

    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
    ALLOW_UNUSED_LOCAL(instanceTemplate);
    v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
    ALLOW_UNUSED_LOCAL(prototypeTemplate);

    // Register DOM constants, attributes and operations.
    V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8URLSearchParamsMethods, WTF_ARRAY_LENGTH(V8URLSearchParamsMethods));

    // Iterator (@@iterator)
    const V8DOMConfiguration::SymbolKeyedMethodConfiguration symbolKeyedIteratorConfiguration = { v8::Symbol::GetIterator, URLSearchParamsV8Internal::iteratorMethodCallback, 0, v8::DontEnum, V8DOMConfiguration::OnPrototype };
    V8DOMConfiguration::installMethod(isolate, world, prototypeTemplate, signature, symbolKeyedIteratorConfiguration);
}

v8::Local<v8::FunctionTemplate> V8URLSearchParams::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world)
{
    return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8URLSearchParamsTemplate);
}

bool V8URLSearchParams::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8URLSearchParams::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

URLSearchParams* V8URLSearchParams::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value)
{
    return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

} // namespace blink
