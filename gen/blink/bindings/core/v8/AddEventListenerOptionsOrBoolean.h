// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/union_container.h.tmpl

// clang-format off
#ifndef AddEventListenerOptionsOrBoolean_h
#define AddEventListenerOptionsOrBoolean_h

#include "bindings/core/v8/Dictionary.h"
#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/V8AddEventListenerOptions.h"
#include "bindings/core/v8/V8Binding.h"
#include "core/CoreExport.h"
#include "platform/heap/Handle.h"

namespace blink {

class CORE_EXPORT AddEventListenerOptionsOrBoolean final {
  DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();
 public:
  AddEventListenerOptionsOrBoolean();
  bool isNull() const { return m_type == SpecificTypeNone; }

  bool isAddEventListenerOptions() const { return m_type == SpecificTypeAddEventListenerOptions; }
  const AddEventListenerOptions& getAsAddEventListenerOptions() const;
  void setAddEventListenerOptions(const AddEventListenerOptions&);
  static AddEventListenerOptionsOrBoolean fromAddEventListenerOptions(const AddEventListenerOptions&);

  bool isBoolean() const { return m_type == SpecificTypeBoolean; }
  bool getAsBoolean() const;
  void setBoolean(bool);
  static AddEventListenerOptionsOrBoolean fromBoolean(bool);

  AddEventListenerOptionsOrBoolean(const AddEventListenerOptionsOrBoolean&);
  ~AddEventListenerOptionsOrBoolean();
  AddEventListenerOptionsOrBoolean& operator=(const AddEventListenerOptionsOrBoolean&);
  DECLARE_TRACE();

 private:
  enum SpecificTypes {
    SpecificTypeNone,
    SpecificTypeAddEventListenerOptions,
    SpecificTypeBoolean,
  };
  SpecificTypes m_type;

  AddEventListenerOptions m_addEventListenerOptions;
  bool m_boolean;

  friend CORE_EXPORT v8::Local<v8::Value> ToV8(const AddEventListenerOptionsOrBoolean&, v8::Local<v8::Object>, v8::Isolate*);
};

class V8AddEventListenerOptionsOrBoolean final {
 public:
  CORE_EXPORT static void toImpl(v8::Isolate*, v8::Local<v8::Value>, AddEventListenerOptionsOrBoolean&, UnionTypeConversionMode, ExceptionState&);
};

CORE_EXPORT v8::Local<v8::Value> ToV8(const AddEventListenerOptionsOrBoolean&, v8::Local<v8::Object>, v8::Isolate*);

template <class CallbackInfo>
inline void v8SetReturnValue(const CallbackInfo& callbackInfo, AddEventListenerOptionsOrBoolean& impl) {
  v8SetReturnValue(callbackInfo, ToV8(impl, callbackInfo.Holder(), callbackInfo.GetIsolate()));
}

template <>
struct NativeValueTraits<AddEventListenerOptionsOrBoolean> {
  CORE_EXPORT static AddEventListenerOptionsOrBoolean nativeValue(v8::Isolate*, v8::Local<v8::Value>, ExceptionState&);
};

}  // namespace blink

// We need to set canInitializeWithMemset=true because HeapVector supports
// items that can initialize with memset or have a vtable. It is safe to
// set canInitializeWithMemset=true for a union type object in practice.
// See https://codereview.chromium.org/1118993002/#msg5 for more details.
WTF_ALLOW_MOVE_AND_INIT_WITH_MEM_FUNCTIONS(blink::AddEventListenerOptionsOrBoolean);

#endif  // AddEventListenerOptionsOrBoolean_h
