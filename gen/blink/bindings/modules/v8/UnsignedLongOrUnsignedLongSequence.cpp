// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/union_container.cpp.tmpl

// clang-format off
#include "UnsignedLongOrUnsignedLongSequence.h"

#include "bindings/core/v8/ToV8.h"

namespace blink {

UnsignedLongOrUnsignedLongSequence::UnsignedLongOrUnsignedLongSequence() : m_type(SpecificTypeNone) {}

unsigned UnsignedLongOrUnsignedLongSequence::getAsUnsignedLong() const {
  DCHECK(isUnsignedLong());
  return m_unsignedLong;
}

void UnsignedLongOrUnsignedLongSequence::setUnsignedLong(unsigned value) {
  DCHECK(isNull());
  m_unsignedLong = value;
  m_type = SpecificTypeUnsignedLong;
}

UnsignedLongOrUnsignedLongSequence UnsignedLongOrUnsignedLongSequence::fromUnsignedLong(unsigned value) {
  UnsignedLongOrUnsignedLongSequence container;
  container.setUnsignedLong(value);
  return container;
}

const Vector<unsigned>& UnsignedLongOrUnsignedLongSequence::getAsUnsignedLongSequence() const {
  DCHECK(isUnsignedLongSequence());
  return m_unsignedLongSequence;
}

void UnsignedLongOrUnsignedLongSequence::setUnsignedLongSequence(const Vector<unsigned>& value) {
  DCHECK(isNull());
  m_unsignedLongSequence = value;
  m_type = SpecificTypeUnsignedLongSequence;
}

UnsignedLongOrUnsignedLongSequence UnsignedLongOrUnsignedLongSequence::fromUnsignedLongSequence(const Vector<unsigned>& value) {
  UnsignedLongOrUnsignedLongSequence container;
  container.setUnsignedLongSequence(value);
  return container;
}

UnsignedLongOrUnsignedLongSequence::UnsignedLongOrUnsignedLongSequence(const UnsignedLongOrUnsignedLongSequence&) = default;
UnsignedLongOrUnsignedLongSequence::~UnsignedLongOrUnsignedLongSequence() = default;
UnsignedLongOrUnsignedLongSequence& UnsignedLongOrUnsignedLongSequence::operator=(const UnsignedLongOrUnsignedLongSequence&) = default;

DEFINE_TRACE(UnsignedLongOrUnsignedLongSequence) {
}

void V8UnsignedLongOrUnsignedLongSequence::toImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8Value, UnsignedLongOrUnsignedLongSequence& impl, UnionTypeConversionMode conversionMode, ExceptionState& exceptionState) {
  if (v8Value.IsEmpty())
    return;

  if (conversionMode == UnionTypeConversionMode::Nullable && isUndefinedOrNull(v8Value))
    return;

  if (v8Value->IsArray()) {
    Vector<unsigned> cppValue = toImplArray<Vector<unsigned>>(v8Value, 0, isolate, exceptionState);
    if (exceptionState.hadException())
      return;
    impl.setUnsignedLongSequence(cppValue);
    return;
  }

  if (v8Value->IsNumber()) {
    unsigned cppValue = toUInt32(isolate, v8Value, NormalConversion, exceptionState);
    if (exceptionState.hadException())
      return;
    impl.setUnsignedLong(cppValue);
    return;
  }

  {
    unsigned cppValue = toUInt32(isolate, v8Value, NormalConversion, exceptionState);
    if (exceptionState.hadException())
      return;
    impl.setUnsignedLong(cppValue);
    return;
  }
}

v8::Local<v8::Value> ToV8(const UnsignedLongOrUnsignedLongSequence& impl, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  switch (impl.m_type) {
    case UnsignedLongOrUnsignedLongSequence::SpecificTypeNone:
      return v8::Null(isolate);
    case UnsignedLongOrUnsignedLongSequence::SpecificTypeUnsignedLong:
      return v8::Integer::NewFromUnsigned(isolate, impl.getAsUnsignedLong());
    case UnsignedLongOrUnsignedLongSequence::SpecificTypeUnsignedLongSequence:
      return ToV8(impl.getAsUnsignedLongSequence(), creationContext, isolate);
    default:
      NOTREACHED();
  }
  return v8::Local<v8::Value>();
}

UnsignedLongOrUnsignedLongSequence NativeValueTraits<UnsignedLongOrUnsignedLongSequence>::nativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exceptionState) {
  UnsignedLongOrUnsignedLongSequence impl;
  V8UnsignedLongOrUnsignedLongSequence::toImpl(isolate, value, impl, UnionTypeConversionMode::NotNullable, exceptionState);
  return impl;
}

}  // namespace blink
