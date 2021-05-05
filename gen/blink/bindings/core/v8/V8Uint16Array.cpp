// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8Uint16Array.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8ArrayBuffer.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/core/v8/V8SharedArrayBuffer.h"
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
const WrapperTypeInfo V8Uint16Array::wrapperTypeInfo = { gin::kEmbedderBlink, 0, V8Uint16Array::trace, V8Uint16Array::traceWrappers, 0, nullptr, "Uint16Array", &V8ArrayBufferView::wrapperTypeInfo, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, DOMUint16Array>::value,
    "DOMUint16Array inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&DOMUint16Array::hasPendingActivity),
                 decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "DOMUint16Array is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

DOMUint16Array* V8Uint16Array::toImpl(v8::Local<v8::Object> object) {
  DCHECK(object->IsUint16Array());
  ScriptWrappable* scriptWrappable = toScriptWrappable(object);
  if (scriptWrappable)
    return scriptWrappable->toImpl<DOMUint16Array>();

  v8::Local<v8::Uint16Array> v8View = object.As<v8::Uint16Array>();
  v8::Local<v8::Object> arrayBuffer = v8View->Buffer();
  DOMUint16Array* typedArray = nullptr;
  if (arrayBuffer->IsArrayBuffer()) {
    typedArray = DOMUint16Array::create(V8ArrayBuffer::toImpl(arrayBuffer), v8View->ByteOffset(), v8View->Length());
  } else if (arrayBuffer->IsSharedArrayBuffer()) {
    typedArray = DOMUint16Array::create(V8SharedArrayBuffer::toImpl(arrayBuffer), v8View->ByteOffset(), v8View->Length());
  } else {
    NOTREACHED();
  }
  v8::Local<v8::Object> associatedWrapper = typedArray->associateWithWrapper(v8::Isolate::GetCurrent(), typedArray->wrapperTypeInfo(), object);
  DCHECK(associatedWrapper == object);

  return typedArray->toImpl<DOMUint16Array>();
}

DOMUint16Array* V8Uint16Array::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return value->IsUint16Array() ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink
