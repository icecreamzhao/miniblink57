// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/interface.cpp.tmpl

// clang-format off
#include "V8MimeTypeArray.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/GeneratedCodeHelper.h"
#include "bindings/core/v8/V8DOMConfiguration.h"
#include "bindings/core/v8/V8ObjectConstructor.h"
#include "bindings/modules/v8/V8MimeType.h"
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
const WrapperTypeInfo V8MimeTypeArray::wrapperTypeInfo = { gin::kEmbedderBlink, V8MimeTypeArray::domTemplate, V8MimeTypeArray::trace, V8MimeTypeArray::traceWrappers, 0, nullptr, "MimeTypeArray", 0, WrapperTypeInfo::WrapperTypeObjectPrototype, WrapperTypeInfo::ObjectClassId, WrapperTypeInfo::NotInheritFromActiveScriptWrappable, WrapperTypeInfo::NotInheritFromEventTarget, WrapperTypeInfo::Independent };
#if defined(COMPONENT_BUILD) && defined(WIN32) && COMPILER(CLANG)
#pragma clang diagnostic pop
#endif

// This static member must be declared by DEFINE_WRAPPERTYPEINFO in DOMMimeTypeArray.h.
// For details, see the comment of DEFINE_WRAPPERTYPEINFO in
// bindings/core/v8/ScriptWrappable.h.
const WrapperTypeInfo& DOMMimeTypeArray::s_wrapperTypeInfo = V8MimeTypeArray::wrapperTypeInfo;

// not [ActiveScriptWrappable]
static_assert(
    !std::is_base_of<ActiveScriptWrappableBase, DOMMimeTypeArray>::value,
    "DOMMimeTypeArray inherits from ActiveScriptWrappable<>, but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");
static_assert(
    std::is_same<decltype(&DOMMimeTypeArray::hasPendingActivity),
                 decltype(&ScriptWrappable::hasPendingActivity)>::value,
    "DOMMimeTypeArray is overriding hasPendingActivity(), but is not specifying "
    "[ActiveScriptWrappable] extended attribute in the IDL file.  "
    "Be consistent.");

namespace DOMMimeTypeArrayV8Internal {

static void lengthAttributeGetter(const v8::FunctionCallbackInfo<v8::Value>& info) {
  v8::Local<v8::Object> holder = info.Holder();

  DOMMimeTypeArray* impl = V8MimeTypeArray::toImpl(holder);

  v8SetReturnValueUnsigned(info, impl->length());
}

MODULES_EXPORT void lengthAttributeGetterCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  DOMMimeTypeArrayV8Internal::lengthAttributeGetter(info);
}

static void itemMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  ExceptionState exceptionState(info.GetIsolate(), ExceptionState::ExecutionContext, "MimeTypeArray", "item");

  DOMMimeTypeArray* impl = V8MimeTypeArray::toImpl(info.Holder());

  unsigned index;
  index = toUInt32(info.GetIsolate(), info[0], NormalConversion, exceptionState);
  if (exceptionState.hadException())
    return;

  v8SetReturnValue(info, impl->item(index));
}

MODULES_EXPORT  void itemMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  DOMMimeTypeArrayV8Internal::itemMethod(info);
}

static void namedItemMethod(const v8::FunctionCallbackInfo<v8::Value>& info) {
  DOMMimeTypeArray* impl = V8MimeTypeArray::toImpl(info.Holder());

  V8StringResource<> name;
  name = info[0];
  if (!name.prepare())
    return;

  v8SetReturnValue(info, impl->namedItem(name));
}

MODULES_EXPORT  void namedItemMethodCallback(const v8::FunctionCallbackInfo<v8::Value>& info) {
  DOMMimeTypeArrayV8Internal::namedItemMethod(info);
}

static void namedPropertyGetter(const AtomicString& name, const v8::PropertyCallbackInfo<v8::Value>& info) {
  DOMMimeTypeArray* impl = V8MimeTypeArray::toImpl(info.Holder());
  DOMMimeType* result = impl->namedItem(name);
  if (!result)
    return;
  v8SetReturnValueFast(info, result, impl);
}

MODULES_EXPORT void namedPropertyGetterCallback(v8::Local<v8::Name> name, const v8::PropertyCallbackInfo<v8::Value>& info) {
  if (!name->IsString())
    return;
  const AtomicString& propertyName = toCoreAtomicString(name.As<v8::String>());

  DOMMimeTypeArrayV8Internal::namedPropertyGetter(propertyName, info);
}

static void indexedPropertyGetter(uint32_t index, const v8::PropertyCallbackInfo<v8::Value>& info) {
  DOMMimeTypeArray* impl = V8MimeTypeArray::toImpl(info.Holder());

  // We assume that all the implementations support length() method, although
  // the spec doesn't require that length() must exist.  It's okay that
  // the interface does not have length attribute as long as the
  // implementation supports length() member function.
  if (index >= impl->length())
    return;  // Returns undefined due to out-of-range.

  DOMMimeType* result = impl->item(index);
  v8SetReturnValueFast(info, result, impl);
}

MODULES_EXPORT void indexedPropertyGetterCallback(uint32_t index, const v8::PropertyCallbackInfo<v8::Value>& info) {
  DOMMimeTypeArrayV8Internal::indexedPropertyGetter(index, info);
}

} // namespace DOMMimeTypeArrayV8Internal

const V8DOMConfiguration::AccessorConfiguration V8MimeTypeArrayAccessors[] = {
    {"length", DOMMimeTypeArrayV8Internal::lengthAttributeGetterCallback, 0, 0, 0, nullptr, 0, v8::DEFAULT, static_cast<v8::PropertyAttribute>(v8::ReadOnly), V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

const V8DOMConfiguration::MethodConfiguration V8MimeTypeArrayMethods[] = {
    {"item", DOMMimeTypeArrayV8Internal::itemMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
    {"namedItem", DOMMimeTypeArrayV8Internal::namedItemMethodCallback, 0, 0, v8::None, V8DOMConfiguration::OnPrototype, V8DOMConfiguration::CheckHolder},
};

static void installV8MimeTypeArrayTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world, v8::Local<v8::FunctionTemplate> interfaceTemplate) {
  // Initialize the interface object's template.
  V8DOMConfiguration::initializeDOMInterfaceTemplate(isolate, interfaceTemplate, V8MimeTypeArray::wrapperTypeInfo.interfaceName, v8::Local<v8::FunctionTemplate>(), V8MimeTypeArray::internalFieldCount);

  v8::Local<v8::Signature> signature = v8::Signature::New(isolate, interfaceTemplate);
  ALLOW_UNUSED_LOCAL(signature);
  v8::Local<v8::ObjectTemplate> instanceTemplate = interfaceTemplate->InstanceTemplate();
  ALLOW_UNUSED_LOCAL(instanceTemplate);
  v8::Local<v8::ObjectTemplate> prototypeTemplate = interfaceTemplate->PrototypeTemplate();
  ALLOW_UNUSED_LOCAL(prototypeTemplate);

  // Register DOM constants, attributes and operations.
  V8DOMConfiguration::installAccessors(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8MimeTypeArrayAccessors, WTF_ARRAY_LENGTH(V8MimeTypeArrayAccessors));
  V8DOMConfiguration::installMethods(isolate, world, instanceTemplate, prototypeTemplate, interfaceTemplate, signature, V8MimeTypeArrayMethods, WTF_ARRAY_LENGTH(V8MimeTypeArrayMethods));

  // Indexed properties
  v8::IndexedPropertyHandlerConfiguration indexedPropertyHandlerConfig(DOMMimeTypeArrayV8Internal::indexedPropertyGetterCallback, 0, 0, 0, indexedPropertyEnumerator<DOMMimeTypeArray>, v8::Local<v8::Value>(), v8::PropertyHandlerFlags::kNone);
  instanceTemplate->SetHandler(indexedPropertyHandlerConfig);
  // Named properties
  v8::NamedPropertyHandlerConfiguration namedPropertyHandlerConfig(DOMMimeTypeArrayV8Internal::namedPropertyGetterCallback, 0, 0, 0, 0, v8::Local<v8::Value>(), static_cast<v8::PropertyHandlerFlags>(int(v8::PropertyHandlerFlags::kOnlyInterceptStrings) | int(v8::PropertyHandlerFlags::kNonMasking)));
  instanceTemplate->SetHandler(namedPropertyHandlerConfig);

  // Array iterator (@@iterator)
  prototypeTemplate->SetIntrinsicDataProperty(v8::Symbol::GetIterator(isolate), v8::kArrayProto_values, v8::DontEnum);
}

v8::Local<v8::FunctionTemplate> V8MimeTypeArray::domTemplate(v8::Isolate* isolate, const DOMWrapperWorld& world) {
  return V8DOMConfiguration::domClassTemplate(isolate, world, const_cast<WrapperTypeInfo*>(&wrapperTypeInfo), installV8MimeTypeArrayTemplate);
}

bool V8MimeTypeArray::hasInstance(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->hasInstance(&wrapperTypeInfo, v8Value);
}

v8::Local<v8::Object> V8MimeTypeArray::findInstanceInPrototypeChain(v8::Local<v8::Value> v8Value, v8::Isolate* isolate) {
  return V8PerIsolateData::from(isolate)->findInstanceInPrototypeChain(&wrapperTypeInfo, v8Value);
}

DOMMimeTypeArray* V8MimeTypeArray::toImplWithTypeCheck(v8::Isolate* isolate, v8::Local<v8::Value> value) {
  return hasInstance(value, isolate) ? toImpl(v8::Local<v8::Object>::Cast(value)) : nullptr;
}

}  // namespace blink
