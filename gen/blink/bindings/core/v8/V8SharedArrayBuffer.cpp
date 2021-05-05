// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8SharedArrayBuffer.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8ArrayBuffer.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/core/v8/V8SharedArrayBuffer.h"
#include "core/dom/Document.h"
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
const WrapperTypeInfo V8SharedArrayBuffer::wrapperTypeInfo = { gin::kEmbedderBlink, 0, V8SharedArrayBuffer::trace, V8SharedArrayBuffer::traceWrappers, 0, nullptr, "SharedArrayBuffer", 0, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in DOMSharedArrayBuffer.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& DOMSharedArrayBuffer::s_wrapperTypeInfo = V8SharedArrayBuffer::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, DOMSharedArrayBuffer>::value,
    "DOMSharedArrayBuffer inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&DOMSharedArrayBuffer::hasPendingActivity),
                 decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "DOMSharedArrayBuffer is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

DOMSharedArrayBuffer* V8SharedArrayBuffer::toImpl(v8::Local<v8::Object> object) {
  DCHECK(object->IsSharedArrayBuffer());
  v8::Local<v8::SharedArrayBuffer> v8buffer = object.As<v8::SharedArrayBuffer>();
  if (v8buffer->IsExternal()) {
    const WrapperTypeInfo* wrapperTypeInfo = toWrapperTypeInfo(object);
    CHECK(wrapperTypeInfo);
    CHECK_EQ(wrapperTypeInfo->ginEmbedder, gin::kEmbedderBlink);
    return toScriptWrappable(object)->toImpl<DOMSharedArrayBuffer>();
  }

  // Transfer the ownership of the allocated memory to an SharedArrayBuffer without
  // copying.
  v8::SharedArrayBuffer::Contents v8Contents = v8buffer->Externalize();
  WTF::ArrayBufferContents contents(v8Contents.Data(), v8Contents.ByteLength(), WTF::ArrayBufferContents::Shared);
  DOMSharedArrayBuffer* buffer = DOMSharedArrayBuffer::create(contents);
  v8::Local<v8::Object> associatedWrapper = buffer->associateWithWrapper(v8::Isolate::GetCurrent(), buffer->wrapperTypeInfo(), object);
  DCHECK(associatedWrapper == object);

  return buffer;
}

DOMSharedArrayBuffer* V8SharedArrayBuffer::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return value->IsSharedArrayBuffer() ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink
