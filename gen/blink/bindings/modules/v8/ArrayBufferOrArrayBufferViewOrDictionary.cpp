// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/union_container.cpp.tmpl

// clang-format off
#include "ArrayBufferOrArrayBufferViewOrDictionary.h"

#include "bindings/core/v8/Dictionary.h"
#include "bindings/core/v8/ToV8.h"
#include "bindings/core/v8/V8ArrayBuffer.h"
#include "bindings/core/v8/V8ArrayBufferView.h"
#include "core/dom/FlexibleArrayBufferView.h"

namespace blink {

ArrayBufferOrArrayBufferViewOrDictionary::ArrayBufferOrArrayBufferViewOrDictionary() : m_type(SpecificTypeNone) {}

DOMArrayBuffer* ArrayBufferOrArrayBufferViewOrDictionary::getAsArrayBuffer() const {
  DCHECK(isArrayBuffer());
  return m_arrayBuffer;
}

void ArrayBufferOrArrayBufferViewOrDictionary::setArrayBuffer(DOMArrayBuffer* value) {
  DCHECK(isNull());
  m_arrayBuffer = value;
  m_type = SpecificTypeArrayBuffer;
}

ArrayBufferOrArrayBufferViewOrDictionary ArrayBufferOrArrayBufferViewOrDictionary::fromArrayBuffer(DOMArrayBuffer* value) {
  ArrayBufferOrArrayBufferViewOrDictionary container;
  container.setArrayBuffer(value);
  return container;
}

DOMArrayBufferView* ArrayBufferOrArrayBufferViewOrDictionary::getAsArrayBufferView() const {
  DCHECK(isArrayBufferView());
  return m_arrayBufferView;
}

void ArrayBufferOrArrayBufferViewOrDictionary::setArrayBufferView(DOMArrayBufferView* value) {
  DCHECK(isNull());
  m_arrayBufferView = value;
  m_type = SpecificTypeArrayBufferView;
}

ArrayBufferOrArrayBufferViewOrDictionary ArrayBufferOrArrayBufferViewOrDictionary::fromArrayBufferView(DOMArrayBufferView* value) {
  ArrayBufferOrArrayBufferViewOrDictionary container;
  container.setArrayBufferView(value);
  return container;
}

Dictionary ArrayBufferOrArrayBufferViewOrDictionary::getAsDictionary() const {
  DCHECK(isDictionary());
  return m_dictionary;
}

void ArrayBufferOrArrayBufferViewOrDictionary::setDictionary(Dictionary value) {
  DCHECK(isNull());
  m_dictionary = value;
  m_type = SpecificTypeDictionary;
}

ArrayBufferOrArrayBufferViewOrDictionary ArrayBufferOrArrayBufferViewOrDictionary::fromDictionary(Dictionary value) {
  ArrayBufferOrArrayBufferViewOrDictionary container;
  container.setDictionary(value);
  return container;
}

ArrayBufferOrArrayBufferViewOrDictionary::ArrayBufferOrArrayBufferViewOrDictionary(const ArrayBufferOrArrayBufferViewOrDictionary&) = default;
ArrayBufferOrArrayBufferViewOrDictionary::~ArrayBufferOrArrayBufferViewOrDictionary() = default;
ArrayBufferOrArrayBufferViewOrDictionary& ArrayBufferOrArrayBufferViewOrDictionary::operator=(const ArrayBufferOrArrayBufferViewOrDictionary&) = default;

DEFINE_TRACE(ArrayBufferOrArrayBufferViewOrDictionary) {
  visitor->trace(m_arrayBuffer);
  visitor->trace(m_arrayBufferView);
}

void V8ArrayBufferOrArrayBufferViewOrDictionary::toImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8Value, ArrayBufferOrArrayBufferViewOrDictionary& impl, UnionTypeConversionMode conversionMode, ExceptionState& exceptionState) {
  if (v8Value.IsEmpty())
    return;

  if (conversionMode == UnionTypeConversionMode::Nullable && isUndefinedOrNull(v8Value))
    return;

  if (v8Value->IsArrayBuffer()) {
    DOMArrayBuffer* cppValue = V8ArrayBuffer::toImpl(v8::Local<v8::Object>::Cast(v8Value));
    impl.setArrayBuffer(cppValue);
    return;
  }

  if (v8Value->IsArrayBufferView()) {
    DOMArrayBufferView* cppValue = V8ArrayBufferView::toImpl(v8::Local<v8::Object>::Cast(v8Value));
    impl.setArrayBufferView(cppValue);
    return;
  }

  if (isUndefinedOrNull(v8Value) || v8Value->IsObject()) {
    Dictionary cppValue = Dictionary(isolate, v8Value, exceptionState);
    if (exceptionState.hadException())
      return;
    impl.setDictionary(cppValue);
    return;
  }

  exceptionState.throwTypeError("The provided value is not of type '(ArrayBuffer or ArrayBufferView or Dictionary)'");
}

v8::Local<v8::Value> ToV8(const ArrayBufferOrArrayBufferViewOrDictionary& impl, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  switch (impl.m_type) {
    case ArrayBufferOrArrayBufferViewOrDictionary::SpecificTypeNone:
      return v8::Null(isolate);
    case ArrayBufferOrArrayBufferViewOrDictionary::SpecificTypeArrayBuffer:
      return ToV8(impl.getAsArrayBuffer(), creationContext, isolate);
    case ArrayBufferOrArrayBufferViewOrDictionary::SpecificTypeArrayBufferView:
      return ToV8(impl.getAsArrayBufferView(), creationContext, isolate);
    case ArrayBufferOrArrayBufferViewOrDictionary::SpecificTypeDictionary:
      return impl.getAsDictionary().v8Value();
    default:
      NOTREACHED();
  }
  return v8::Local<v8::Value>();
}

ArrayBufferOrArrayBufferViewOrDictionary NativeValueTraits<ArrayBufferOrArrayBufferViewOrDictionary>::nativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exceptionState) {
  ArrayBufferOrArrayBufferViewOrDictionary impl;
  V8ArrayBufferOrArrayBufferViewOrDictionary::toImpl(isolate, value, impl, UnionTypeConversionMode::NotNullable, exceptionState);
  return impl;
}

}  // namespace blink
