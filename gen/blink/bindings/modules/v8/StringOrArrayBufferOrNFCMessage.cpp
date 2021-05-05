// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/union_container.cpp.tmpl

// clang-format off
#include "StringOrArrayBufferOrNFCMessage.h"

#include "bindings/core/v8/ToV8.h"
#include "bindings/core/v8/V8ArrayBuffer.h"

namespace blink {

StringOrArrayBufferOrNFCMessage::StringOrArrayBufferOrNFCMessage() : m_type(SpecificTypeNone) {}

String StringOrArrayBufferOrNFCMessage::getAsString() const {
  DCHECK(isString());
  return m_string;
}

void StringOrArrayBufferOrNFCMessage::setString(String value) {
  DCHECK(isNull());
  m_string = value;
  m_type = SpecificTypeString;
}

StringOrArrayBufferOrNFCMessage StringOrArrayBufferOrNFCMessage::fromString(String value) {
  StringOrArrayBufferOrNFCMessage container;
  container.setString(value);
  return container;
}

DOMArrayBuffer* StringOrArrayBufferOrNFCMessage::getAsArrayBuffer() const {
  DCHECK(isArrayBuffer());
  return m_arrayBuffer;
}

void StringOrArrayBufferOrNFCMessage::setArrayBuffer(DOMArrayBuffer* value) {
  DCHECK(isNull());
  m_arrayBuffer = value;
  m_type = SpecificTypeArrayBuffer;
}

StringOrArrayBufferOrNFCMessage StringOrArrayBufferOrNFCMessage::fromArrayBuffer(DOMArrayBuffer* value) {
  StringOrArrayBufferOrNFCMessage container;
  container.setArrayBuffer(value);
  return container;
}

const NFCMessage& StringOrArrayBufferOrNFCMessage::getAsNFCMessage() const {
  DCHECK(isNFCMessage());
  return m_nFCMessage;
}

void StringOrArrayBufferOrNFCMessage::setNFCMessage(const NFCMessage& value) {
  DCHECK(isNull());
  m_nFCMessage = value;
  m_type = SpecificTypeNFCMessage;
}

StringOrArrayBufferOrNFCMessage StringOrArrayBufferOrNFCMessage::fromNFCMessage(const NFCMessage& value) {
  StringOrArrayBufferOrNFCMessage container;
  container.setNFCMessage(value);
  return container;
}

StringOrArrayBufferOrNFCMessage::StringOrArrayBufferOrNFCMessage(const StringOrArrayBufferOrNFCMessage&) = default;
StringOrArrayBufferOrNFCMessage::~StringOrArrayBufferOrNFCMessage() = default;
StringOrArrayBufferOrNFCMessage& StringOrArrayBufferOrNFCMessage::operator=(const StringOrArrayBufferOrNFCMessage&) = default;

DEFINE_TRACE(StringOrArrayBufferOrNFCMessage) {
  visitor->trace(m_arrayBuffer);
  visitor->trace(m_nFCMessage);
}

void V8StringOrArrayBufferOrNFCMessage::toImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8Value, StringOrArrayBufferOrNFCMessage& impl, UnionTypeConversionMode conversionMode, ExceptionState& exceptionState) {
  if (v8Value.IsEmpty())
    return;

  if (conversionMode == UnionTypeConversionMode::Nullable && isUndefinedOrNull(v8Value))
    return;

  if (isUndefinedOrNull(v8Value)) {
    NFCMessage cppValue;
    V8NFCMessage::toImpl(isolate, v8Value, cppValue, exceptionState);
    if (exceptionState.hadException())
      return;
    impl.setNFCMessage(cppValue);
    return;
  }

  if (v8Value->IsArrayBuffer()) {
    DOMArrayBuffer* cppValue = V8ArrayBuffer::toImpl(v8::Local<v8::Object>::Cast(v8Value));
    impl.setArrayBuffer(cppValue);
    return;
  }

  if (v8Value->IsObject()) {
    NFCMessage cppValue;
    V8NFCMessage::toImpl(isolate, v8Value, cppValue, exceptionState);
    if (exceptionState.hadException())
      return;
    impl.setNFCMessage(cppValue);
    return;
  }

  {
    V8StringResource<> cppValue = v8Value;
    if (!cppValue.prepare(exceptionState))
      return;
    impl.setString(cppValue);
    return;
  }
}

v8::Local<v8::Value> ToV8(const StringOrArrayBufferOrNFCMessage& impl, v8::Local<v8::Object> creationContext, v8::Isolate* isolate) {
  switch (impl.m_type) {
    case StringOrArrayBufferOrNFCMessage::SpecificTypeNone:
      return v8::Null(isolate);
    case StringOrArrayBufferOrNFCMessage::SpecificTypeString:
      return v8String(isolate, impl.getAsString());
    case StringOrArrayBufferOrNFCMessage::SpecificTypeArrayBuffer:
      return ToV8(impl.getAsArrayBuffer(), creationContext, isolate);
    case StringOrArrayBufferOrNFCMessage::SpecificTypeNFCMessage:
      return ToV8(impl.getAsNFCMessage(), creationContext, isolate);
    default:
      NOTREACHED();
  }
  return v8::Local<v8::Value>();
}

StringOrArrayBufferOrNFCMessage NativeValueTraits<StringOrArrayBufferOrNFCMessage>::nativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exceptionState) {
  StringOrArrayBufferOrNFCMessage impl;
  V8StringOrArrayBufferOrNFCMessage::toImpl(isolate, value, impl, UnionTypeConversionMode::NotNullable, exceptionState);
  return impl;
}

}  // namespace blink
