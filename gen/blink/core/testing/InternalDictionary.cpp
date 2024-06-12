// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.cpp.tmpl

// clang-format on
#include "InternalDictionary.h"

#include "bindings/core/v8/DoubleOrString.h"
#include "core/dom/Element.h"
#include "core/events/EventTarget.h"

namespace blink {

InternalDictionary::InternalDictionary()
{
    setEnumMemberWithDefault(String("foo"));
    setLongMemberWithDefault(42);
    setStringMemberWithDefault(String("defaultStringValue"));
    setStringSequenceMemberWithDefault(Vector<String>());
}

InternalDictionary::~InternalDictionary() { }

InternalDictionary::InternalDictionary(const InternalDictionary&) = default;

InternalDictionary& InternalDictionary::operator=(const InternalDictionary&) = default;

bool InternalDictionary::hasBooleanMember() const
{
    return m_hasBooleanMember;
}
bool InternalDictionary::booleanMember() const
{
    DCHECK(m_hasBooleanMember);
    return m_booleanMember;
}
void InternalDictionary::setBooleanMember(bool value)
{
    m_booleanMember = value;
    m_hasBooleanMember = true;
}
bool InternalDictionary::hasByteStringMember() const
{
    return !m_byteStringMember.isNull();
}
String InternalDictionary::byteStringMember() const
{
    return m_byteStringMember;
}
void InternalDictionary::setByteStringMember(String value)
{
    m_byteStringMember = value;
}
bool InternalDictionary::hasDictionaryMember() const
{
    return !m_dictionaryMember.isUndefinedOrNull();
}
Dictionary InternalDictionary::dictionaryMember() const
{
    return m_dictionaryMember;
}
void InternalDictionary::setDictionaryMember(Dictionary value)
{
    m_dictionaryMember = value;
}
bool InternalDictionary::hasDoubleMember() const
{
    return m_hasDoubleMember;
}
double InternalDictionary::doubleMember() const
{
    DCHECK(m_hasDoubleMember);
    return m_doubleMember;
}
void InternalDictionary::setDoubleMember(double value)
{
    m_doubleMember = value;
    m_hasDoubleMember = true;
}
bool InternalDictionary::hasDoubleOrStringMember() const
{
    return !m_doubleOrStringMember.isNull();
}
const DoubleOrString& InternalDictionary::doubleOrStringMember() const
{
    return m_doubleOrStringMember;
}
void InternalDictionary::setDoubleOrStringMember(const DoubleOrString& value)
{
    m_doubleOrStringMember = value;
}
bool InternalDictionary::hasDoubleOrStringSequenceMember() const
{
    return m_hasDoubleOrStringSequenceMember;
}
const HeapVector<DoubleOrString>& InternalDictionary::doubleOrStringSequenceMember() const
{
    DCHECK(m_hasDoubleOrStringSequenceMember);
    return m_doubleOrStringSequenceMember;
}
void InternalDictionary::setDoubleOrStringSequenceMember(const HeapVector<DoubleOrString>& value)
{
    m_doubleOrStringSequenceMember = value;
    m_hasDoubleOrStringSequenceMember = true;
}
bool InternalDictionary::hasElementMember() const
{
    return m_elementMember;
}
Element* InternalDictionary::elementMember() const
{
    return m_elementMember;
}
void InternalDictionary::setElementMember(Element* value)
{
    m_elementMember = value;
}
bool InternalDictionary::hasElementOrNullMember() const
{
    return m_elementOrNullMember;
}
Element* InternalDictionary::elementOrNullMember() const
{
    return m_elementOrNullMember;
}
void InternalDictionary::setElementOrNullMember(Element* value)
{
    m_elementOrNullMember = value;
}
void InternalDictionary::setElementOrNullMemberToNull()
{
    m_elementOrNullMember = Member<Element>();
}
bool InternalDictionary::hasEnumArrayMember() const
{
    return m_hasEnumArrayMember;
}
const Vector<String>& InternalDictionary::enumArrayMember() const
{
    DCHECK(m_hasEnumArrayMember);
    return m_enumArrayMember;
}
void InternalDictionary::setEnumArrayMember(const Vector<String>& value)
{
    m_enumArrayMember = value;
    m_hasEnumArrayMember = true;
}
bool InternalDictionary::hasEnumMember() const
{
    return !m_enumMember.isNull();
}
String InternalDictionary::enumMember() const
{
    return m_enumMember;
}
void InternalDictionary::setEnumMember(String value)
{
    m_enumMember = value;
}
bool InternalDictionary::hasEnumMemberWithDefault() const
{
    return !m_enumMemberWithDefault.isNull();
}
String InternalDictionary::enumMemberWithDefault() const
{
    return m_enumMemberWithDefault;
}
void InternalDictionary::setEnumMemberWithDefault(String value)
{
    m_enumMemberWithDefault = value;
}
bool InternalDictionary::hasEnumOrNullMember() const
{
    return !m_enumOrNullMember.isNull();
}
String InternalDictionary::enumOrNullMember() const
{
    return m_enumOrNullMember;
}
void InternalDictionary::setEnumOrNullMember(String value)
{
    m_enumOrNullMember = value;
}
void InternalDictionary::setEnumOrNullMemberToNull()
{
    m_enumOrNullMember = String();
}
bool InternalDictionary::hasEventTargetOrNullMember() const
{
    return m_eventTargetOrNullMember;
}
EventTarget* InternalDictionary::eventTargetOrNullMember() const
{
    return m_eventTargetOrNullMember;
}
void InternalDictionary::setEventTargetOrNullMember(EventTarget* value)
{
    m_eventTargetOrNullMember = value;
}
void InternalDictionary::setEventTargetOrNullMemberToNull()
{
    m_eventTargetOrNullMember = Member<EventTarget>();
}
bool InternalDictionary::hasLongMember() const
{
    return m_hasLongMember;
}
int InternalDictionary::longMember() const
{
    DCHECK(m_hasLongMember);
    return m_longMember;
}
void InternalDictionary::setLongMember(int value)
{
    m_longMember = value;
    m_hasLongMember = true;
}
bool InternalDictionary::hasLongMemberWithClamp() const
{
    return m_hasLongMemberWithClamp;
}
int InternalDictionary::longMemberWithClamp() const
{
    DCHECK(m_hasLongMemberWithClamp);
    return m_longMemberWithClamp;
}
void InternalDictionary::setLongMemberWithClamp(int value)
{
    m_longMemberWithClamp = value;
    m_hasLongMemberWithClamp = true;
}
bool InternalDictionary::hasLongMemberWithDefault() const
{
    return m_hasLongMemberWithDefault;
}
int InternalDictionary::longMemberWithDefault() const
{
    DCHECK(m_hasLongMemberWithDefault);
    return m_longMemberWithDefault;
}
void InternalDictionary::setLongMemberWithDefault(int value)
{
    m_longMemberWithDefault = value;
    m_hasLongMemberWithDefault = true;
}
bool InternalDictionary::hasLongMemberWithEnforceRange() const
{
    return m_hasLongMemberWithEnforceRange;
}
int InternalDictionary::longMemberWithEnforceRange() const
{
    DCHECK(m_hasLongMemberWithEnforceRange);
    return m_longMemberWithEnforceRange;
}
void InternalDictionary::setLongMemberWithEnforceRange(int value)
{
    m_longMemberWithEnforceRange = value;
    m_hasLongMemberWithEnforceRange = true;
}
bool InternalDictionary::hasLongOrNullMember() const
{
    return m_hasLongOrNullMember;
}
int InternalDictionary::longOrNullMember() const
{
    DCHECK(m_hasLongOrNullMember);
    return m_longOrNullMember;
}
void InternalDictionary::setLongOrNullMember(int value)
{
    m_longOrNullMember = value;
    m_hasLongOrNullMember = true;
}
void InternalDictionary::setLongOrNullMemberToNull()
{
    m_hasLongOrNullMember = false;
}
bool InternalDictionary::hasLongOrNullMemberWithDefault() const
{
    return m_hasLongOrNullMemberWithDefault;
}
int InternalDictionary::longOrNullMemberWithDefault() const
{
    DCHECK(m_hasLongOrNullMemberWithDefault);
    return m_longOrNullMemberWithDefault;
}
void InternalDictionary::setLongOrNullMemberWithDefault(int value)
{
    m_longOrNullMemberWithDefault = value;
    m_hasLongOrNullMemberWithDefault = true;
}
void InternalDictionary::setLongOrNullMemberWithDefaultToNull()
{
    m_hasLongOrNullMemberWithDefault = false;
}
bool InternalDictionary::hasObjectMember() const
{
    return !(m_objectMember.isEmpty() || m_objectMember.isNull() || m_objectMember.isUndefined());
}
ScriptValue InternalDictionary::objectMember() const
{
    return m_objectMember;
}
void InternalDictionary::setObjectMember(ScriptValue value)
{
    m_objectMember = value;
}
bool InternalDictionary::hasObjectOrNullMemberWithDefault() const
{
    return !(m_objectOrNullMemberWithDefault.isEmpty() || m_objectOrNullMemberWithDefault.isNull() || m_objectOrNullMemberWithDefault.isUndefined());
}
ScriptValue InternalDictionary::objectOrNullMemberWithDefault() const
{
    return m_objectOrNullMemberWithDefault;
}
void InternalDictionary::setObjectOrNullMemberWithDefault(ScriptValue value)
{
    m_objectOrNullMemberWithDefault = value;
}
void InternalDictionary::setObjectOrNullMemberWithDefaultToNull()
{
    m_objectOrNullMemberWithDefault = ScriptValue();
}
bool InternalDictionary::hasPrefixGetMember() const
{
    return !(m_prefixGetMember.isEmpty() || m_prefixGetMember.isNull() || m_prefixGetMember.isUndefined());
}
ScriptValue InternalDictionary::getPrefixGetMember() const
{
    return m_prefixGetMember;
}
void InternalDictionary::setPrefixGetMember(ScriptValue value)
{
    m_prefixGetMember = value;
}
bool InternalDictionary::hasStringMember() const
{
    return !m_stringMember.isNull();
}
String InternalDictionary::stringMember() const
{
    return m_stringMember;
}
void InternalDictionary::setStringMember(String value)
{
    m_stringMember = value;
}
bool InternalDictionary::hasStringMemberWithDefault() const
{
    return !m_stringMemberWithDefault.isNull();
}
String InternalDictionary::stringMemberWithDefault() const
{
    return m_stringMemberWithDefault;
}
void InternalDictionary::setStringMemberWithDefault(String value)
{
    m_stringMemberWithDefault = value;
}
bool InternalDictionary::hasStringSequenceMember() const
{
    return m_hasStringSequenceMember;
}
const Vector<String>& InternalDictionary::stringSequenceMember() const
{
    DCHECK(m_hasStringSequenceMember);
    return m_stringSequenceMember;
}
void InternalDictionary::setStringSequenceMember(const Vector<String>& value)
{
    m_stringSequenceMember = value;
    m_hasStringSequenceMember = true;
}
bool InternalDictionary::hasStringSequenceMemberWithDefault() const
{
    return m_hasStringSequenceMemberWithDefault;
}
const Vector<String>& InternalDictionary::stringSequenceMemberWithDefault() const
{
    DCHECK(m_hasStringSequenceMemberWithDefault);
    return m_stringSequenceMemberWithDefault;
}
void InternalDictionary::setStringSequenceMemberWithDefault(const Vector<String>& value)
{
    m_stringSequenceMemberWithDefault = value;
    m_hasStringSequenceMemberWithDefault = true;
}
bool InternalDictionary::hasStringSequenceOrNullMember() const
{
    return m_hasStringSequenceOrNullMember;
}
const Vector<String>& InternalDictionary::stringSequenceOrNullMember() const
{
    DCHECK(m_hasStringSequenceOrNullMember);
    return m_stringSequenceOrNullMember;
}
void InternalDictionary::setStringSequenceOrNullMember(const Vector<String>& value)
{
    m_stringSequenceOrNullMember = value;
    m_hasStringSequenceOrNullMember = true;
}
void InternalDictionary::setStringSequenceOrNullMemberToNull()
{
    m_hasStringSequenceOrNullMember = false;
}
bool InternalDictionary::hasUnrestrictedDoubleMember() const
{
    return m_hasUnrestrictedDoubleMember;
}
double InternalDictionary::unrestrictedDoubleMember() const
{
    DCHECK(m_hasUnrestrictedDoubleMember);
    return m_unrestrictedDoubleMember;
}
void InternalDictionary::setUnrestrictedDoubleMember(double value)
{
    m_unrestrictedDoubleMember = value;
    m_hasUnrestrictedDoubleMember = true;
}
bool InternalDictionary::hasUsvStringMember() const
{
    return !m_usvStringMember.isNull();
}
String InternalDictionary::usvStringMember() const
{
    return m_usvStringMember;
}
void InternalDictionary::setUsvStringMember(String value)
{
    m_usvStringMember = value;
}

DEFINE_TRACE(InternalDictionary)
{
    visitor->trace(m_doubleOrStringMember);
    visitor->trace(m_doubleOrStringSequenceMember);
    visitor->trace(m_elementMember);
    visitor->trace(m_elementOrNullMember);
    visitor->trace(m_eventTargetOrNullMember);
    IDLDictionaryBase::trace(visitor);
}

} // namespace blink
