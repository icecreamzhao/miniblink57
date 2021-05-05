// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/union_container.h.tmpl

// clang-format off
#ifndef DoubleOrConstrainDoubleRange_h
#define DoubleOrConstrainDoubleRange_h

#include "bindings/core/v8/Dictionary.h"
#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/V8Binding.h"
#include "bindings/modules/v8/V8ConstrainDoubleRange.h"
#include "modules/ModulesExport.h"
#include "platform/heap/Handle.h"

namespace blink {

class MODULES_EXPORT DoubleOrConstrainDoubleRange final {
  DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();
 public:
  DoubleOrConstrainDoubleRange();
  bool isNull() const { return m_type == SpecificTypeNone; }

  bool isDouble() const { return m_type == SpecificTypeDouble; }
  double getAsDouble() const;
  void setDouble(double);
  static DoubleOrConstrainDoubleRange fromDouble(double);

  bool isConstrainDoubleRange() const { return m_type == SpecificTypeConstrainDoubleRange; }
  const ConstrainDoubleRange& getAsConstrainDoubleRange() const;
  void setConstrainDoubleRange(const ConstrainDoubleRange&);
  static DoubleOrConstrainDoubleRange fromConstrainDoubleRange(const ConstrainDoubleRange&);

  DoubleOrConstrainDoubleRange(const DoubleOrConstrainDoubleRange&);
  ~DoubleOrConstrainDoubleRange();
  DoubleOrConstrainDoubleRange& operator=(const DoubleOrConstrainDoubleRange&);
  DECLARE_TRACE();

 private:
  enum SpecificTypes {
    SpecificTypeNone,
    SpecificTypeDouble,
    SpecificTypeConstrainDoubleRange,
  };
  SpecificTypes m_type;

  double m_double;
  ConstrainDoubleRange m_constrainDoubleRange;

  friend MODULES_EXPORT v8::Local<v8::Value> ToV8(const DoubleOrConstrainDoubleRange&, v8::Local<v8::Object>, v8::Isolate*);
};

class V8DoubleOrConstrainDoubleRange final {
 public:
  MODULES_EXPORT static void toImpl(v8::Isolate*, v8::Local<v8::Value>, DoubleOrConstrainDoubleRange&, UnionTypeConversionMode, ExceptionState&);
};

MODULES_EXPORT v8::Local<v8::Value> ToV8(const DoubleOrConstrainDoubleRange&, v8::Local<v8::Object>, v8::Isolate*);

template <class CallbackInfo>
inline void v8SetReturnValue(const CallbackInfo& callbackInfo, DoubleOrConstrainDoubleRange& impl) {
  v8SetReturnValue(callbackInfo, ToV8(impl, callbackInfo.Holder(), callbackInfo.GetIsolate()));
}

template <>
struct NativeValueTraits<DoubleOrConstrainDoubleRange> {
  MODULES_EXPORT static DoubleOrConstrainDoubleRange nativeValue(v8::Isolate*, v8::Local<v8::Value>, ExceptionState&);
};

}  // namespace blink

// We need to set canInitializeWithMemset=true because HeapVector supports
// items that can initialize with memset or have a vtable. It is safe to
// set canInitializeWithMemset=true for a union type object in practice.
// See https://codereview.chromium.org/1118993002/#msg5 for more details.
WTF_ALLOW_MOVE_AND_INIT_WITH_MEM_FUNCTIONS(blink::DoubleOrConstrainDoubleRange);

#endif  // DoubleOrConstrainDoubleRange_h
