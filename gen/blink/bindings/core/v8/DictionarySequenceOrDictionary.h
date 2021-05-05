// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/union_container.h.tmpl

// clang-format off
#ifndef DictionarySequenceOrDictionary_h
#define DictionarySequenceOrDictionary_h

#include "bindings/core/v8/Dictionary.h"
#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/V8Binding.h"
#include "core/CoreExport.h"
#include "platform/heap/Handle.h"

namespace blink {

class CORE_EXPORT DictionarySequenceOrDictionary final {
  DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();
 public:
  DictionarySequenceOrDictionary();
  bool isNull() const { return m_type == SpecificTypeNone; }

  bool isDictionarySequence() const { return m_type == SpecificTypeDictionarySequence; }
  const Vector<Dictionary>& getAsDictionarySequence() const;
  void setDictionarySequence(const Vector<Dictionary>&);
  static DictionarySequenceOrDictionary fromDictionarySequence(const Vector<Dictionary>&);

  bool isDictionary() const { return m_type == SpecificTypeDictionary; }
  Dictionary getAsDictionary() const;
  void setDictionary(Dictionary);
  static DictionarySequenceOrDictionary fromDictionary(Dictionary);

  DictionarySequenceOrDictionary(const DictionarySequenceOrDictionary&);
  ~DictionarySequenceOrDictionary();
  DictionarySequenceOrDictionary& operator=(const DictionarySequenceOrDictionary&);
  DECLARE_TRACE();

 private:
  enum SpecificTypes {
    SpecificTypeNone,
    SpecificTypeDictionarySequence,
    SpecificTypeDictionary,
  };
  SpecificTypes m_type;

  Vector<Dictionary> m_dictionarySequence;
  Dictionary m_dictionary;

  friend CORE_EXPORT v8::Local<v8::Value> ToV8(const DictionarySequenceOrDictionary&, v8::Local<v8::Object>, v8::Isolate*);
};

class V8DictionarySequenceOrDictionary final {
 public:
  CORE_EXPORT static void toImpl(v8::Isolate*, v8::Local<v8::Value>, DictionarySequenceOrDictionary&, UnionTypeConversionMode, ExceptionState&);
};

CORE_EXPORT v8::Local<v8::Value> ToV8(const DictionarySequenceOrDictionary&, v8::Local<v8::Object>, v8::Isolate*);

template <class CallbackInfo>
inline void v8SetReturnValue(const CallbackInfo& callbackInfo, DictionarySequenceOrDictionary& impl) {
  v8SetReturnValue(callbackInfo, ToV8(impl, callbackInfo.Holder(), callbackInfo.GetIsolate()));
}

template <>
struct NativeValueTraits<DictionarySequenceOrDictionary> {
  CORE_EXPORT static DictionarySequenceOrDictionary nativeValue(v8::Isolate*, v8::Local<v8::Value>, ExceptionState&);
};

}  // namespace blink

// We need to set canInitializeWithMemset=true because HeapVector supports
// items that can initialize with memset or have a vtable. It is safe to
// set canInitializeWithMemset=true for a union type object in practice.
// See https://codereview.chromium.org/1118993002/#msg5 for more details.
WTF_ALLOW_MOVE_AND_INIT_WITH_MEM_FUNCTIONS(blink::DictionarySequenceOrDictionary);

#endif  // DictionarySequenceOrDictionary_h
