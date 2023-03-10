// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format on
#include "V8EXTDisjointTimerQueryWebGL2.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8GCController.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/modules/v8/V8WebGLQuery.h"
#include "core/dom/Document.h"
#include "core/dom/Element.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace blink {

// Suppress warning: global constructors, because struct WrapperTypeInfo is trivial
// and does not depend on another global objects.
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wglobal-constructors"
#endif
const WrapperTypeInfo V8EXTDisjointTimerQueryWebGL2::wrapperTypeInfo = { gin::kEmbedderBlink, V8EXTDisjointTimerQueryWebGL2::domTemplate, V8EXTDisjointTimerQueryWebGL2::trace, V8EXTDisjointTimerQueryWebGL2::traceWrappers, V8EXTDisjointTimerQueryWebGL2::visitDOMWrapper, nullptr, "EXTDisjointTimerQueryWebGL2", 0, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Dependent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in EXTDisjointTimerQueryWebGL2.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& EXTDisjointTimerQueryWebGL2::s_wrapperTypeInfo = V8EXTDisjointTimerQueryWebGL2::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, EXTDisjointTimerQueryWebGL2>::value,
    "EXTDisjointTimerQueryWebGL2 inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&EXTDisjointTimerQueryWebGL2::hasPendingActivity),
        decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "EXTDisjointTimerQueryWebGL2 is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace EXTDisjointTimerQueryWebGL2V8Internal {

    static void queryCounterEXTMethod(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "EXTDisjointTimerQueryWebGL2", "queryCounterEXT");

        EXTDisjointTimerQueryWebGL2* impl = V8EXTDisjointTimerQueryWebGL2::toImpl(info.Holder());

        if (UNLIKELY(info.Length() < 2)) {
            exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(2, info.Length()));
            return;
        }

        WebGLQuery* query;
        unsigned target;
        query = V8WebGLQuery::toImplWithTypeCheck(info.GetIsolate(), info[0]);
        if (!query) {
            exceptionState.throwTypeError("parameter 1 is not of type 'WebGLQuery'.");

            return;
        }

        target = toUInt32(info.GetIsolate(), info[1], NormalConversion, exceptionState);
        if (exceptionState.hadException())
            return;

        impl->queryCounterEXT(query, target);
    }

    MODULES_EXPORT void queryCounterEXTMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
    {
        EXTDisjointTimerQueryWebGL2V8Internal::queryCounterEXTMethod(info);
    }

} // namespace EXTDisjointTimerQueryWebGL2V8Internal

void V8EXTDisjointTimerQueryWebGL2::visitDOMWrapper(v8::Isolate* isolate, ScriptWrappable* scriptWrappable, const v8::Persistent<v8::Object>& wrapper)
{
    EXTDisjointTimerQueryWebGL2* impl = scriptWrappable->toImpl<EXTDisjointTimerQueryWebGL2>();
    // The canvas() method may return a reference or a pointer.
    if (Node* owner = WTF::getPtr(impl->canvas())) {
        Node* root = V8GCController::opaqueRootForGC(isolate, owner);
        isolate->SetReferenceFromGroup(v8::UniqueId(reinterpret_cast<intptr_t>(root)), wrapper);
        return;
    }
}

const V8DOMConfiguration::MethodConfiguration V8EXTDisjointTimerQueryWebGL2Methods[] = {
    { "queryCounterEXT", EXTDisjointTimerQueryWebGL2V8Internal::queryCounterEXTMethodCallback, 0, 2, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder },
};

static void installV8EXTDisjointTimerQueryWebGL2Template(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate)
{
    // Initialize the interface object's template.
    V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8EXTDisjointTimerQueryWebGL2::wrapperTypeInfo.interfaceName, v8::Local<v8::FunctionTemplate>(), V8EXTDisjointTimerQueryWebGL2::internalFieldCount);

    v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
    ALLOW_UNUSED_LOCAL(signature);
    v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
    ALLOW_UNUSED_LOCAL(instanceTemplate);
    v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
    ALLOW_UNUSED_LOCAL(prototypeTemplate);

    // Register DOM constants, attributes and operations.
    const V8DOMConfiguration::ConstantConfiguration V8EXTDisjointTimerQueryWebGL2Constants[] = {
        { "QUERY_COUNTER_BITS_EXT", 0x8864, 0, V8DOMConfiguration::ConstantTypeUnsignedLong },
        { "TIME_ELAPSED_EXT", 0x88BF, 0, V8DOMConfiguration::ConstantTypeUnsignedLong },
        { "TIMESTAMP_EXT", 0x8E28, 0, V8DOMConfiguration::ConstantTypeUnsignedLong },
        { "GPU_DISJOINT_EXT", 0x8FBB, 0, V8DOMConfiguration::ConstantTypeUnsignedLong },
    };
    V8DOMConfiguration::installConstants(isolate, interfaceTemplate, prototypeTemplate, V8EXTDisjointTimerQueryWebGL2Constants, WTF_ARRAY_LENGTH(V8EXTDisjointTimerQueryWebGL2Constants));
    V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8EXTDisjointTimerQueryWebGL2Methods, WTF_ARRAY_LENGTH(V8EXTDisjointTimerQueryWebGL2Methods));
}

v8::Local<v8::FunctionTemplate> V8EXTDisjointTimerQueryWebGL2::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world)
{
    return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8EXTDisjointTimerQueryWebGL2Template);
}

bool V8EXTDisjointTimerQueryWebGL2::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8EXTDisjointTimerQueryWebGL2::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate)
{
    return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

EXTDisjointTimerQueryWebGL2* V8EXTDisjointTimerQueryWebGL2::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value)
{
    return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

} // namespace blink
