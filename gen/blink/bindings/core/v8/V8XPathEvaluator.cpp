// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format on
#include "V8XPathEvaluator.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/ScriptValue.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8Node.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/core/v8/V8XPathExpression.h"
#include "bindings/core/v8/V8XPathNSResolver.h"
#include "bindings/core/v8/V8XPathResult.h"
#include "core/dom/Document.h"
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
const WrapperTypeInfo V8XPathEvaluator::wrapperTypeInfo = { gin::kEmbedderBlink, V8XPathEvaluator::domTemplate, V8XPathEvaluator::trace, V8XPathEvaluator::traceWrappers, 0, nullptr, "XPathEvaluator", 0, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in XPathEvaluator.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& XPathEvaluator::s_wrapperTypeInfo = V8XPathEvaluator::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, XPathEvaluator>::value,
    "XPathEvaluator inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&XPathEvaluator::hasPendingActivity),
        decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "XPathEvaluator is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace XPathEvaluatorV8Internal {

    static void createExpressionMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "XPathEvaluator", "createExpression");

        XPathEvaluator* impl = V8XPathEvaluator::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 1)) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(1, info.Length()));
            return;
        }

        V8StringResource<> expression;
        XPathNSResolver* resolver;
        expression = info[0];
        if (!expression.prepare())
            return;

        if (!info[1]->IsUndefined()) {
            resolver = toXPathNSResolver(ScriptState::current(info.GetIsolate()), info[1]);
            if (!resolver && !isUndefinedOrNull(info[1])) {
                exceptionState.throwTypeError("parameter 2 is not of type 'XPathNSResolver'.");

                return;
            }
        } else {
            resolver = nullptr;
        }

        XPathExpression* result = impl->createExpression(expression, resolver, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
        v8SetReturnValue(info, result);
    }

    CORE_EXPORT void createExpressionMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::V8XPathEvaluator_CreateExpression_Method);
        XPathEvaluatorV8Internal::createExpressionMethod(info);
    }

    static void createNSResolverMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        XPathEvaluator* impl = V8XPathEvaluator::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 1)) {
            V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("createNSResolver", "XPathEvaluator", ExceptionMessages::notEnoughArguments(1, info.Length())));
            return;
        }

        Node* nodeResolver;
        nodeResolver = V8Node::toImplWithTypeCheck(info.GetIsolate(), info[0]);
        if (!nodeResolver) {
            V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("createNSResolver", "XPathEvaluator", "parameter 1 is not of type 'Node'."));

            return;
        }

        v8SetReturnValue(info, impl->createNSResolver(nodeResolver));
    }

    CORE_EXPORT void createNSResolverMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::V8XPathEvaluator_CreateNSResolver_Method);
        XPathEvaluatorV8Internal::createNSResolverMethod(info);
    }

    static void evaluateMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "XPathEvaluator", "evaluate");

        XPathEvaluator* impl = V8XPathEvaluator::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 2)) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(2, info.Length()));
            return;
        }

        V8StringResource<> expression;
        Node* contextNode;
        XPathNSResolver* resolver;
        unsigned type;
        ScriptValue inResult;
        expression = info[0];
        if (!expression.prepare())
            return;

        contextNode = V8Node::toImplWithTypeCheck(info.GetIsolate(), info[1]);
        if (!contextNode) {
            exceptionState.throwTypeError("parameter 2 is not of type 'Node'.");

            return;
        }

        if (!info[2]->IsUndefined()) {
            resolver = toXPathNSResolver(ScriptState::current(info.GetIsolate()), info[2]);
            if (!resolver && !isUndefinedOrNull(info[2])) {
                exceptionState.throwTypeError("parameter 3 is not of type 'XPathNSResolver'.");

                return;
            }
        } else {
            resolver = nullptr;
        }
        if (!info[3]->IsUndefined()) {
            type = toUInt16(info.GetIsolate(), info[3], NormalConversion, exceptionState);
            if (exceptionState.hadException())
                return;
        } else {
            type = 0u;
        }
        if (!info[4]->IsUndefined()) {
            inResult = ScriptValue(ScriptState::current(info.GetIsolate()), info[4]);
        } else {
            inResult = ScriptValue();
        }

        XPathResult* result = impl->evaluate(expression, contextNode, resolver, type, inResult, exceptionState);
        if (exceptionState.hadException()) {
            return;
        }
        v8SetReturnValue(info, result);
    }

    CORE_EXPORT void evaluateMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::V8XPathEvaluator_Evaluate_Method);
        XPathEvaluatorV8Internal::evaluateMethod(info);
    }

    static void constructor(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        XPathEvaluator* impl = XPathEvaluator::create();
        v8::Local<v8::Object> wrapper = info.Holder();
        wrapper = impl->associateWithWrapper(info.GetIsolate(), &V8XPathEvaluator::wrapperTypeInfo, wrapper);
        v8SetReturnValue(info, wrapper);
    }

} // namespace XPathEvaluatorV8Internal

const V8DOMConfiguration::MethodConfiguration V8XPathEvaluatorMethods[] = {
    { "createExpression", XPathEvaluatorV8Internal::createExpressionMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "createNSResolver", XPathEvaluatorV8Internal::createNSResolverMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
    { "evaluate", XPathEvaluatorV8Internal::evaluateMethodCallback, 0, 2, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

void V8XPathEvaluator::constructorCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    UseCounter::count(currentExecutionContext(info.GetIsolate()), UseCounter::V8XPathEvaluator_Constructor);
    if (!info.IsConstructCall()) {
        V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::constructorNotCallableAsFunction("XPathEvaluator"));
        return;
    }

    if (ConstructorMode::current(info.GetIsolate()) == ConstructorMode::WrapExistingObject) {
        v8SetReturnValue(info, info.Holder());
        return;
    }

    XPathEvaluatorV8Internal::constructor(info);
}

static void installV8XPathEvaluatorTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8XPathEvaluator::wrapperTypeInfo.interfaceName, v8::Local<v8::FunctionTemplate>(), V8XPathEvaluator::internalFieldCount);
    interfaceTemplate->SetCallHandler(V8XPathEvaluator::constructorCallback);
    interfaceTemplate->SetLength(0);

    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
    ALLOW_UNUSED_LOCAL(instanceTemplate);
    v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
    ALLOW_UNUSED_LOCAL(prototypeTemplate);

    // Register DOM constants, attributes and operations.
    V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8XPathEvaluatorMethods, WTF_ARRAY_LENGTH(V8XPathEvaluatorMethods));
}

v8::Local<v8::FunctionTemplate> V8XPathEvaluator::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world)
{
    return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8XPathEvaluatorTemplate);
}

bool V8XPathEvaluator::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8XPathEvaluator::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

XPathEvaluator* V8XPathEvaluator::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value)
{
    return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

} // namespace blink
