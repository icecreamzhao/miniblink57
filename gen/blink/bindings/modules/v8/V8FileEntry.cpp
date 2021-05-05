// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8FileEntry.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8BlobCallback.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/modules/v8/V8ErrorCallback.h"
#include "bindings/modules/v8/V8FileWriterCallback.h"
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
const WrapperTypeInfo V8FileEntry::wrapperTypeInfo = { gin::kEmbedderBlink, V8FileEntry::domTemplate, V8FileEntry::trace, V8FileEntry::traceWrappers, 0, nullptr, "FileEntry", &V8Entry::wrapperTypeInfo, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in FileEntry.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& FileEntry::s_wrapperTypeInfo = V8FileEntry::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, FileEntry>::value,
    "FileEntry inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&FileEntry::hasPendingActivity),
                 decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "FileEntry is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace FileEntryV8Internal {

static void createWriterMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  FileEntry* impl = V8FileEntry::toImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("createWriter", "FileEntry", ExceptionMessages::notEnoughArguments(1, info.Length())));
    return;
  }

  FileWriterCallback* successCallback;
  ErrorCallback* errorCallback;
  if (info.Length() <= 0 || !info[0]->IsFunction()) {
    V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("createWriter", "FileEntry", "The callback provided as parameter 1 is not a function."));

    return;
  }
  successCallback = V8FileWriterCallback::create(v8::Local<v8::Function>::Cast(info[0]), ScriptState::current(info.GetIsolate()));

  if (!isUndefinedOrNull(info[1])) {
    if (!info[1]->IsFunction()) {
      V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("createWriter", "FileEntry", "The callback provided as parameter 2 is not a function."));

      return;
    }
    errorCallback = V8ErrorCallback::create(v8::Local<v8::Function>::Cast(info[1]), ScriptState::current(info.GetIsolate()));
  } else {
    errorCallback = nullptr;
  }

  impl->createWriter(successCallback, errorCallback);
}

MODULES_EXPORT  void createWriterMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  FileEntryV8Internal::createWriterMethod(info);
}

static void fileMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  FileEntry* impl = V8FileEntry::toImpl(info.Holder());

  if (UNLIKELY(info.Length() < 1)) {
    V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("file", "FileEntry", ExceptionMessages::notEnoughArguments(1, info.Length())));
    return;
  }

  BlobCallback* successCallback;
  ErrorCallback* errorCallback;
  if (info.Length() <= 0 || !info[0]->IsFunction()) {
    V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("file", "FileEntry", "The callback provided as parameter 1 is not a function."));

    return;
  }
  successCallback = V8BlobCallback::create(v8::Local<v8::Function>::Cast(info[0]), ScriptState::current(info.GetIsolate()));

  if (!isUndefinedOrNull(info[1])) {
    if (!info[1]->IsFunction()) {
      V8ThrowException::throwTypeError(info.GetIsolate(), ExceptionMessages::failedToExecute("file", "FileEntry", "The callback provided as parameter 2 is not a function."));

      return;
    }
    errorCallback = V8ErrorCallback::create(v8::Local<v8::Function>::Cast(info[1]), ScriptState::current(info.GetIsolate()));
  } else {
    errorCallback = nullptr;
  }

  impl->file(successCallback, errorCallback);
}

MODULES_EXPORT  void fileMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  FileEntryV8Internal::fileMethod(info);
}

} // namespace FileEntryV8Internal

const V8DOMConfiguration::MethodConfiguration V8FileEntryMethods[] = {
    {"createWriter", FileEntryV8Internal::createWriterMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"file", FileEntryV8Internal::fileMethodCallback, 0, 1, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

static void installV8FileEntryTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate) {
  // Initialize the interface object's template.
  V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8FileEntry::wrapperTypeInfo.interfaceName, V8Entry::domTemplate(isolate, world), V8FileEntry::internalFieldCount);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instanceTemplate);
  v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototypeTemplate);

  // Register DOM constants, attributes and operations.
  V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8FileEntryMethods, WTF_ARRAY_LENGTH(V8FileEntryMethods));
}

v8::Local<v8::FunctionTemplate> V8FileEntry::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8FileEntryTemplate);
}

bool V8FileEntry::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8FileEntry::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

FileEntry* V8FileEntry::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink
