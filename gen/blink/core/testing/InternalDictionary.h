// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.h.tmpl

// clang-format off
#ifndef InternalDictionary_h
#define InternalDictionary_h

#include "bindings/core/v8/Dictionary.h"
#include "bindings/core/v8/DoubleOrString.h"
#include "bindings/core/v8/IDLDictionaryBase.h"
#include "bindings/core/v8/ScriptValue.h"
#include "platform/heap/Handle.h"
#include "wtf/Vector.h"
#include "wtf/text/WTFString.h"

namespace blink {

class EventTarget;
class Element;

class InternalDictionary : public IDLDictionaryBase {
  DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();
 public:
  InternalDictionary();
  virtual ~InternalDictionary();
  InternalDictionary(const InternalDictionary&);
  InternalDictionary& operator=(const InternalDictionary&);

  bool hasBooleanMember() const;
  bool booleanMember() const;
  void setBooleanMember(bool);

  bool hasByteStringMember() const;
  String byteStringMember() const;
  void setByteStringMember(String);

  bool hasDictionaryMember() const;
  Dictionary dictionaryMember() const;
  void setDictionaryMember(Dictionary);

  bool hasDoubleMember() const;
  double doubleMember() const;
  void setDoubleMember(double);

  bool hasDoubleOrStringMember() const;
  const DoubleOrString& doubleOrStringMember() const;
  void setDoubleOrStringMember(const DoubleOrString&);

  bool hasDoubleOrStringSequenceMember() const;
  const HeapVector<DoubleOrString>& doubleOrStringSequenceMember() const;
  void setDoubleOrStringSequenceMember(const HeapVector<DoubleOrString>&);

  bool hasElementMember() const;
  Element* elementMember() const;
  void setElementMember(Element*);

  bool hasElementOrNullMember() const;
  Element* elementOrNullMember() const;
  void setElementOrNullMember(Element*);
  void setElementOrNullMemberToNull();

  bool hasEnumArrayMember() const;
  const Vector<String>& enumArrayMember() const;
  void setEnumArrayMember(const Vector<String>&);

  bool hasEnumMember() const;
  String enumMember() const;
  void setEnumMember(String);

  bool hasEnumMemberWithDefault() const;
  String enumMemberWithDefault() const;
  void setEnumMemberWithDefault(String);

  bool hasEnumOrNullMember() const;
  String enumOrNullMember() const;
  void setEnumOrNullMember(String);
  void setEnumOrNullMemberToNull();

  bool hasEventTargetOrNullMember() const;
  EventTarget* eventTargetOrNullMember() const;
  void setEventTargetOrNullMember(EventTarget*);
  void setEventTargetOrNullMemberToNull();

  bool hasLongMember() const;
  int longMember() const;
  void setLongMember(int);

  bool hasLongMemberWithClamp() const;
  int longMemberWithClamp() const;
  void setLongMemberWithClamp(int);

  bool hasLongMemberWithDefault() const;
  int longMemberWithDefault() const;
  void setLongMemberWithDefault(int);

  bool hasLongMemberWithEnforceRange() const;
  int longMemberWithEnforceRange() const;
  void setLongMemberWithEnforceRange(int);

  bool hasLongOrNullMember() const;
  int longOrNullMember() const;
  void setLongOrNullMember(int);
  void setLongOrNullMemberToNull();

  bool hasLongOrNullMemberWithDefault() const;
  int longOrNullMemberWithDefault() const;
  void setLongOrNullMemberWithDefault(int);
  void setLongOrNullMemberWithDefaultToNull();

  bool hasObjectMember() const;
  ScriptValue objectMember() const;
  void setObjectMember(ScriptValue);

  bool hasObjectOrNullMemberWithDefault() const;
  ScriptValue objectOrNullMemberWithDefault() const;
  void setObjectOrNullMemberWithDefault(ScriptValue);
  void setObjectOrNullMemberWithDefaultToNull();

  bool hasPrefixGetMember() const;
  ScriptValue getPrefixGetMember() const;
  void setPrefixGetMember(ScriptValue);

  bool hasStringMember() const;
  String stringMember() const;
  void setStringMember(String);

  bool hasStringMemberWithDefault() const;
  String stringMemberWithDefault() const;
  void setStringMemberWithDefault(String);

  bool hasStringSequenceMember() const;
  const Vector<String>& stringSequenceMember() const;
  void setStringSequenceMember(const Vector<String>&);

  bool hasStringSequenceMemberWithDefault() const;
  const Vector<String>& stringSequenceMemberWithDefault() const;
  void setStringSequenceMemberWithDefault(const Vector<String>&);

  bool hasStringSequenceOrNullMember() const;
  const Vector<String>& stringSequenceOrNullMember() const;
  void setStringSequenceOrNullMember(const Vector<String>&);
  void setStringSequenceOrNullMemberToNull();

  bool hasUnrestrictedDoubleMember() const;
  double unrestrictedDoubleMember() const;
  void setUnrestrictedDoubleMember(double);

  bool hasUsvStringMember() const;
  String usvStringMember() const;
  void setUsvStringMember(String);

  v8::Local<v8::Value> toV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  DECLARE_VIRTUAL_TRACE();

 private:
  bool m_hasBooleanMember = false;
  bool m_booleanMember;
  String m_byteStringMember;
  Dictionary m_dictionaryMember;
  bool m_hasDoubleMember = false;
  double m_doubleMember;
  DoubleOrString m_doubleOrStringMember;
  bool m_hasDoubleOrStringSequenceMember = false;
  HeapVector<DoubleOrString> m_doubleOrStringSequenceMember;
  Member<Element> m_elementMember;
  Member<Element> m_elementOrNullMember;
  bool m_hasEnumArrayMember = false;
  Vector<String> m_enumArrayMember;
  String m_enumMember;
  String m_enumMemberWithDefault;
  String m_enumOrNullMember;
  Member<EventTarget> m_eventTargetOrNullMember;
  bool m_hasLongMember = false;
  int m_longMember;
  bool m_hasLongMemberWithClamp = false;
  int m_longMemberWithClamp;
  bool m_hasLongMemberWithDefault = false;
  int m_longMemberWithDefault;
  bool m_hasLongMemberWithEnforceRange = false;
  int m_longMemberWithEnforceRange;
  bool m_hasLongOrNullMember = false;
  int m_longOrNullMember;
  bool m_hasLongOrNullMemberWithDefault = false;
  int m_longOrNullMemberWithDefault;
  ScriptValue m_objectMember;
  ScriptValue m_objectOrNullMemberWithDefault;
  ScriptValue m_prefixGetMember;
  String m_stringMember;
  String m_stringMemberWithDefault;
  bool m_hasStringSequenceMember = false;
  Vector<String> m_stringSequenceMember;
  bool m_hasStringSequenceMemberWithDefault = false;
  Vector<String> m_stringSequenceMemberWithDefault;
  bool m_hasStringSequenceOrNullMember = false;
  Vector<String> m_stringSequenceOrNullMember;
  bool m_hasUnrestrictedDoubleMember = false;
  double m_unrestrictedDoubleMember;
  String m_usvStringMember;

  friend class V8InternalDictionary;
};

}  // namespace blink

#endif  // InternalDictionary_h
