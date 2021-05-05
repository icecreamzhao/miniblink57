// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8EntrySync.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8HiddenValue.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/modules/v8/V8DOMFileSystemSync.h"
#include "bindings/modules/v8/V8DirectoryEntrySync.h"
#include "bindings/modules/v8/V8EntrySync.h"
#include "bindings/modules/v8/V8Metadata.h"
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
const WrapperTypeInfo V8EntrySync::wrapperTypeInfo = { gin::kEmbedderBlink, V8EntrySync::domTemplate, V8EntrySync::trace, V8EntrySync::traceWrappers, 0, nullptr, "EntrySync", 0, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in EntrySync.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& EntrySync::s_wrapperTypeInfo = V8EntrySync::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, EntrySync>::value,
    "EntrySync inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&EntrySync::hasPendingActivity),
                 decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "EntrySync is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace EntrySyncV8Internal {

static void isFileAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  EntrySync* impl = V8EntrySync::toImpl(holder);

  v8SetReturnValueBool(info, impl->isFile());
}

MODULES_EXPORT void isFileAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  EntrySyncV8Internal::isFileAttributeGetter(info);
}

static void isDirectoryAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  EntrySync* impl = V8EntrySync::toImpl(holder);

  v8SetReturnValueBool(info, impl->isDirectory());
}

MODULES_EXPORT void isDirectoryAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  EntrySyncV8Internal::isDirectoryAttributeGetter(info);
}

static void nameAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  EntrySync* impl = V8EntrySync::toImpl(holder);

  v8SetReturnValueString(info, impl->name(), info.GetIsolate());
}

MODULES_EXPORT void nameAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  EntrySyncV8Internal::nameAttributeGetter(info);
}

static void fullPathAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  EntrySync* impl = V8EntrySync::toImpl(holder);

  v8SetReturnValueString(info, impl->fullPath(), info.GetIsolate());
}

MODULES_EXPORT void fullPathAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  EntrySyncV8Internal::fullPathAttributeGetter(info);
}

static void filesystemAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  EntrySync* impl = V8EntrySync::toImpl(holder);

  DOMFileSystemSync* cppValue(WTF::getPtr(impl->filesystem()));

  // Keep the wrapper object for the return value alive as long as |this|
  // object is alive in order to save creation time of the wrapper object.
  if (cppValue && DOMDataStore::setReturnValue(info.GetReturnValue(), cppValue))
    return;
  v8::Local<v8::Value> v8Value(ToV8(cppValue, holder, info.GetIsolate()));
  const char kKeepAliveKey[] = "KeepAlive#EntrySync#filesystem";
  V8HiddenValue::setHiddenValue(ScriptState::current(info.GetIsolate()), holder, v8AtomicString(info.GetIsolate(), StringView(kKeepAliveKey, sizeof kKeepAliveKey)), v8Value);

  v8SetReturnValue(info, v8Value);
}

MODULES_EXPORT void filesystemAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  EntrySyncV8Internal::filesystemAttributeGetter(info);
}

static void getMetadataMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "EntrySync", "getMetadata");

  EntrySync* impl = V8EntrySync::toImpl(info.Holder());

  Metadata* result = impl->getMetadata(exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
  v8SetReturnValue(info, result);
}

MODULES_EXPORT  void getMetadataMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  EntrySyncV8Internal::getMetadataMethod(info);
}

static void moveToMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "EntrySync", "moveTo");

  EntrySync* impl = V8EntrySync::toImpl(info.Holder());

  if (UNLIKELY(info.Length() < 2)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(2, info.Length()));
    return;
  }

  DirectoryEntrySync* parent;
  V8StringResource<TreatNullAndUndefinedAsNullString> name;
  parent = V8DirectoryEntrySync::toImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!parent) {
    exceptionState.throwTypeError("parameter 1 is not of type 'DirectoryEntrySync'.");

    return;
  }

  name = info[1];
  if (!name.prepare())
    return;

  EntrySync* result = impl->moveTo(parent, name, exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
  v8SetReturnValue(info, result);
}

MODULES_EXPORT  void moveToMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  EntrySyncV8Internal::moveToMethod(info);
}

static void copyToMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "EntrySync", "copyTo");

  EntrySync* impl = V8EntrySync::toImpl(info.Holder());

  if (UNLIKELY(info.Length() < 2)) {
    exceptionState.throwTypeError(ExceptionMessages::notEnoughArguments(2, info.Length()));
    return;
  }

  DirectoryEntrySync* parent;
  V8StringResource<TreatNullAndUndefinedAsNullString> name;
  parent = V8DirectoryEntrySync::toImplWithTypeCheck(info.GetIsolate(), info[0]);
  if (!parent) {
    exceptionState.throwTypeError("parameter 1 is not of type 'DirectoryEntrySync'.");

    return;
  }

  name = info[1];
  if (!name.prepare())
    return;

  EntrySync* result = impl->copyTo(parent, name, exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
  v8SetReturnValue(info, result);
}

MODULES_EXPORT  void copyToMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  EntrySyncV8Internal::copyToMethod(info);
}

static void toURLMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  EntrySync* impl = V8EntrySync::toImpl(info.Holder());

  v8SetReturnValueString(info, impl->toURL(), info.GetIsolate());
}

MODULES_EXPORT  void toURLMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  EntrySyncV8Internal::toURLMethod(info);
}

static void removeMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "EntrySync", "remove");

  EntrySync* impl = V8EntrySync::toImpl(info.Holder());

  impl->remove(exceptionState);
  if (exceptionState.hadException()) {
    return;
  }
}

MODULES_EXPORT  void removeMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  EntrySyncV8Internal::removeMethod(info);
}

static void getParentMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  EntrySync* impl = V8EntrySync::toImpl(info.Holder());

  v8SetReturnValue(info, impl->getParent());
}

MODULES_EXPORT  void getParentMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  EntrySyncV8Internal::getParentMethod(info);
}

} // namespace EntrySyncV8Internal

const V8DOMConfiguration::AccessorConfiguration V8EntrySyncAccessors[] = {
    {"isFile", EntrySyncV8Internal::isFileAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"isDirectory", EntrySyncV8Internal::isDirectoryAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"name", EntrySyncV8Internal::nameAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"fullPath", EntrySyncV8Internal::fullPathAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"filesystem", EntrySyncV8Internal::filesystemAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

const V8DOMConfiguration::MethodConfiguration V8EntrySyncMethods[] = {
    {"getMetadata", EntrySyncV8Internal::getMetadataMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"moveTo", EntrySyncV8Internal::moveToMethodCallback, 0, 2, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"copyTo", EntrySyncV8Internal::copyToMethodCallback, 0, 2, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"toURL", EntrySyncV8Internal::toURLMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"remove", EntrySyncV8Internal::removeMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"getParent", EntrySyncV8Internal::getParentMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

static void installV8EntrySyncTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate) {
  // Initialize the interface object's template.
  V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8EntrySync::wrapperTypeInfo.interfaceName, v8::Local<v8::FunctionTemplate>(), V8EntrySync::internalFieldCount);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instanceTemplate);
  v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototypeTemplate);

  // Register DOM constants, attributes and operations.
  V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8EntrySyncAccessors, WTF_ARRAY_LENGTH(V8EntrySyncAccessors));
  V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8EntrySyncMethods, WTF_ARRAY_LENGTH(V8EntrySyncMethods));
}

v8::Local<v8::FunctionTemplate> V8EntrySync::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8EntrySyncTemplate);
}

bool V8EntrySync::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8EntrySync::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

EntrySync* V8EntrySync::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink
