// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format on
#include "V8CallbackFunctionTest.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/TestCallback.h"
#include "bindings/core/v8/TestInterfaceCallback.h"
#include "bindings/core/v8/TestReceiverObjectCallback.h"
#include "bindings/core/v8/TestSequenceCallback.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8HTMLDivElement.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "core/dom/Document.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace blink {

// Suppress warning: global constructors, because struct WrapperTypeInfo is trivial
// and does not depend on another global objects.
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
const WrapperTypeInfo V8CallbackFunctionTest::wrapperTypeInfo = { gin::kEmbedderBlink, V8CallbackFunctionTest::domTemplate, V8CallbackFunctionTest::trace, V8CallbackFunctionTest::traceWrappers, 0, nullptr, "CallbackFunctionTest", 0, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in CallbackFunctionTest.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& CallbackFunctionTest::s_wrapperTypeInfo = V8CallbackFunctionTest::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, CallbackFunctionTest>::value,
    "CallbackFunctionTest inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&CallbackFunctionTest::hasPendingActivity),
        decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "CallbackFunctionTest is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace CallbackFunctionTestV8Internal {

    static void testCallbackMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "CallbackFunctionTest", "testCallback");

        CallbackFunctionTest* impl = V8CallbackFunctionTest::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 3)) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(3, info.Length()));
            return;
        }

        TestCallback* callback;
        V8StringResource<> message1;
        V8StringResource<> message2;
        if (!(info[0]->IsObject() && v8::Local<v8::Object>::Cast(info[0])->IsCallable())) {
            exceptionState.throwTypeError("The callback provided as parameter 1 is not a function.");

            return;
        }
        callback = TestCallback::create(ScriptState::current(info.GetIsolate()), info[0]);

        message1 = info[1];
        if (!message1.prepare())
            return;

        message2 = info[2];
        if (!message2.prepare())
            return;

        String result = impl->testCallback(callback, message1, message2, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
        v8SetReturnValueString(info, result, info.GetIsolate());
    }

    void testCallbackMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CallbackFunctionTestV8Internal::testCallbackMethod(info);
    }

    static void testNullableCallbackMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "CallbackFunctionTest", "testNullableCallback");

        CallbackFunctionTest* impl = V8CallbackFunctionTest::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 3)) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(3, info.Length()));
            return;
        }

        TestCallback* callback;
        V8StringResource<> message1;
        V8StringResource<> message2;
        if (!isUndefinedOrNull(info[0]) && !(info[0]->IsObject() && v8::Local<v8::Object>::Cast(info[0])->IsCallable())) {
            exceptionState.throwTypeError("The callback provided as parameter 1 is not a function.");

            return;
        }
        callback = TestCallback::create(ScriptState::current(info.GetIsolate()), info[0]);

        message1 = info[1];
        if (!message1.prepare())
            return;

        message2 = info[2];
        if (!message2.prepare())
            return;

        String result = impl->testNullableCallback(callback, message1, message2, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
        v8SetReturnValueString(info, result, info.GetIsolate());
    }

    void testNullableCallbackMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CallbackFunctionTestV8Internal::testNullableCallbackMethod(info);
    }

    static void testInterfaceCallbackMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "CallbackFunctionTest", "testInterfaceCallback");

        CallbackFunctionTest* impl = V8CallbackFunctionTest::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 2)) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(2, info.Length()));
            return;
        }

        TestInterfaceCallback* callback;
        HTMLDivElement* divElement;
        if (!(info[0]->IsObject() && v8::Local<v8::Object>::Cast(info[0])->IsCallable())) {
            exceptionState.throwTypeError("The callback provided as parameter 1 is not a function.");

            return;
        }
        callback = TestInterfaceCallback::create(ScriptState::current(info.GetIsolate()), info[0]);

        divElement = V8HTMLDivElement::toImplWithTypeCheck(info.GetIsolate(), info[1]);
        if (!divElement) {
            exceptionState.throwTypeError("parameter 2 is not of type 'HTMLDivElement'.");

            return;
        }

        impl->testInterfaceCallback(callback, divElement, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
    }

    void testInterfaceCallbackMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CallbackFunctionTestV8Internal::testInterfaceCallbackMethod(info);
    }

    static void testReceiverObjectCallbackMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "CallbackFunctionTest", "testReceiverObjectCallback");

        CallbackFunctionTest* impl = V8CallbackFunctionTest::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 1)) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
            return;
        }

        TestReceiverObjectCallback* callback;
        if (!(info[0]->IsObject() && v8::Local<v8::Object>::Cast(info[0])->IsCallable())) {
            exceptionState.throwTypeError("The callback provided as parameter 1 is not a function.");

            return;
        }
        callback = TestReceiverObjectCallback::create(ScriptState::current(info.GetIsolate()), info[0]);

        impl->testReceiverObjectCallback(callback, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
    }

    void testReceiverObjectCallbackMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CallbackFunctionTestV8Internal::testReceiverObjectCallbackMethod(info);
    }

    static void testSequenceCallbackMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "CallbackFunctionTest", "testSequenceCallback");

        CallbackFunctionTest* impl = V8CallbackFunctionTest::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 2)) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(2, info.Length()));
            return;
        }

        TestSequenceCallback* callback;
        Vector<int> numbers;
        if (!(info[0]->IsObject() && v8::Local<v8::Object>::Cast(info[0])->IsCallable())) {
            exceptionState.throwTypeError("The callback provided as parameter 1 is not a function.");

            return;
        }
        callback = TestSequenceCallback::create(ScriptState::current(info.GetIsolate()), info[0]);

        numbers = toImplArray<Vector<int>>(info[1], 2, info.GetIsolate(), exceptionState);
        if (exceptionState.hadException())
            return;

        Vector<String> result = impl->testSequenceCallback(callback, numbers, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
        v8SetReturnValue(info, ToV8(result, info.Holder(), info.GetIsolate()));
    }

    void testSequenceCallbackMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        CallbackFunctionTestV8Internal::testSequenceCallbackMethod(info);
    }

} // namespace CallbackFunctionTestV8Internal

const V8DOMConfiguration::MethodConfiguration V8CallbackFunctionTestMethods[] = {
    { "testCallback", CallbackFunctionTestV8Internal::testCallbackMethodCallback, 0, 3, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "testNullableCallback", CallbackFunctionTestV8Internal::testNullableCallbackMethodCallback, 0, 3, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "testInterfaceCallback", CallbackFunctionTestV8Internal::testInterfaceCallbackMethodCallback, 0, 2, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "testReceiverObjectCallback", CallbackFunctionTestV8Internal::testReceiverObjectCallbackMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "testSequenceCallback", CallbackFunctionTestV8Internal::testSequenceCallbackMethodCallback, 0, 2, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

static void installV8CallbackFunctionTestTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8CallbackFunctionTest::wrapperTypeInfo.interfaceName, v8::Local<v8::FunctionTemplate>(), V8CallbackFunctionTest::internalFieldCount);

    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
    ALLOW_UNUSED_LOCAL(instanceTemplate);
    v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
    ALLOW_UNUSED_LOCAL(prototypeTemplate);

    // Register DOM constants, attributes and operations.
    V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8CallbackFunctionTestMethods, WTF_ARRAY_LENGTH(V8CallbackFunctionTestMethods));
}

v8::Local<v8::FunctionTemplate> V8CallbackFunctionTest::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world)
{
    return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8CallbackFunctionTestTemplate);
}

bool V8CallbackFunctionTest::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8CallbackFunctionTest::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

CallbackFunctionTest* V8CallbackFunctionTest::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value)
{
    return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

} // namespace blink
