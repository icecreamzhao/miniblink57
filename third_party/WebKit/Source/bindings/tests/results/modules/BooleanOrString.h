// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/union_container.h.tmpl

// clang-format off
#ifndef BooleanOrString_h
#define BooleanOrString_h

#include "bindings/core/v8/Dictionary.h"
#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/V8Binding.h"
#include "modules/ModulesExport.h"
#include "platform/heap/Handle.h"

namespace blink {

class MODULES_EXPORT BooleanOrString final {
  DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();
 public:
  BooleanOrString();
  bool isNull() const { return m_type == SpecificTypeNone; }

  bool isBoolean() const { return m_type == SpecificTypeBoolean; }
  bool getAsBoolean() const;
  void setBoolean(bool);
  static BooleanOrString fromBoolean(bool);

  bool isString() const { return m_type == SpecificTypeString; }
  String getAsString() const;
  void setString(String);
  static BooleanOrString fromString(String);

  BooleanOrString(const BooleanOrString&);
  ~BooleanOrString();
  BooleanOrString& operator=(const BooleanOrString&);
  DECLARE_TRACE();

 private:
  enum SpecificTypes {
    SpecificTypeNone,
    SpecificTypeBoolean,
    SpecificTypeString,
  };
  SpecificTypes m_type;

  bool m_boolean;
  String m_string;

  friend MODULES_EXPORT v8::Local<v8::Value> ToV8(const BooleanOrString&, v8::Local<v8::Object>, v8::Isolate*);
};

class V8BooleanOrString final {
 public:
  MODULES_EXPORT static void toImpl(v8::Isolate*, v8::Local<v8::Value>, BooleanOrString&, UnionTypeConversionMode, ExceptionState&);
};

MODULES_EXPORT v8::Local<v8::Value> ToV8(const BooleanOrString&, v8::Local<v8::Object>, v8::Isolate*);

template <class CallbackInfo>
inline void v8SetReturnValue(const CallbackInfo& callbackInfo, BooleanOrString& impl) {
  v8SetReturnValue(callbackInfo, ToV8(impl, callbackInfo.Holder(), callbackInfo.GetIsolate()));
}

template <>
struct NativeValueTraits<BooleanOrString> {
  MODULES_EXPORT static BooleanOrString nativeValue(v8::Isolate*, v8::Local<v8::Value>, ExceptionState&);
};

}  // namespace blink

// We need to set canInitializeWithMemset=true because HeapVector supports
// items that can initialize with memset or have a vtable. It is safe to
// set canInitializeWithMemset=true for a union type object in practice.
// See https://codereview.chromium.org/1118993002/#msg5 for more details.
WTF_ALLOW_MOVE_AND_INIT_WITH_MEM_FUNCTIONS(blink::BooleanOrString);

#endif  // BooleanOrString_h
