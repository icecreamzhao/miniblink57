// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/union_container.h.tmpl

// clang-format on
#ifndef StringOrStringSequence_h
#define StringOrStringSequence_h

#include "bindings/core/v8/Dictionary.h"
#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/V8Binding.h"
#include "modules/ModulesExport.h"
#include "platform/heap/Handle.h"

namespace blink {

class MODULES_EXPORT StringOrStringSequence final {
    DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();

public:
    StringOrStringSequence();
    bool isNull() const { return m_type == SpecificTypeNone; }

    bool isString() const { return m_type == SpecificTypeString; }
    String getAsString() const;
    void setString(String);
    static StringOrStringSequence fromString(String);

    bool isStringSequence() const { return m_type == SpecificTypeStringSequence; }
    const Vector<String>& getAsStringSequence() const;
    void setStringSequence(const Vector<String>&);
    static StringOrStringSequence fromStringSequence(const Vector<String>&);

    StringOrStringSequence(const StringOrStringSequence&);
    ~StringOrStringSequence();
    StringOrStringSequence& operator=(const StringOrStringSequence&);
    DECLARE_TRACE();

private:
    enum SpecificTypes {
        SpecificTypeNone,
        SpecificTypeString,
        SpecificTypeStringSequence,
    };
    SpecificTypes m_type;

    String m_string;
    Vector<String> m_stringSequence;

    friend MODULES_EXPORT v8::Local<v8::Value> ToV8(const StringOrStringSequence&, v8::Local<v8::Object>, v8::Isolate*);
};

class V8StringOrStringSequence final {
public:
    MODULES_EXPORT static void toImpl(v8::Isolate*, v8::Local<v8::Value>, StringOrStringSequence&, UnionTypeConversionMode, ExceptionState&);
};

MODULES_EXPORT v8::Local<v8::Value> ToV8(const StringOrStringSequence&, v8::Local<v8::Object>, v8::Isolate*);

template <class CallbackInfo>
inline void v8SetReturnValue(const CallbackInfo& callbackInfo, StringOrStringSequence& impl)
{
    v8SetReturnValue(callbackInfo, ToV8(impl, callbackInfo.Holder(), callbackInfo.GetIsolate()));
}

template <>
struct NativeValueTraits<StringOrStringSequence> {
    MODULES_EXPORT static StringOrStringSequence nativeValue(v8::Isolate*, v8::Local<v8::Value>, ExceptionState&);
};

} // namespace blink

// We need to set canInitializeWithMemset=true because HeapVector supports
// items that can initialize with memset or have a vtable. It is safe to
// set canInitializeWithMemset=true for a union type object in practice.
// See https://codereview.chromium.org/1118993002/#msg5 for more details.
WTF_ALLOW_MOVE_AND_INIT_WITH_MEM_FUNCTIONS(blink::StringOrStringSequence);

#endif // StringOrStringSequence_h
