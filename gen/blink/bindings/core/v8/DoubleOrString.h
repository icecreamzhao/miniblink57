// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/union_container.h.tmpl

// clang-format on
#ifndef DoubleOrString_h
#define DoubleOrString_h

#include "bindings/core/v8/Dictionary.h"
#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/V8Binding.h"
#include "core/CoreExport.h"
#include "platform/heap/Handle.h"

namespace blink {

class CORE_EXPORT DoubleOrString final {
    DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();

public:
    DoubleOrString();
    bool isNull() const { return m_type == SpecificTypeNone; }

    bool isDouble() const { return m_type == SpecificTypeDouble; }
    double getAsDouble() const;
    void setDouble(double);
    static DoubleOrString fromDouble(double);

    bool isString() const { return m_type == SpecificTypeString; }
    String getAsString() const;
    void setString(String);
    static DoubleOrString fromString(String);

    DoubleOrString(const DoubleOrString&);
    ~DoubleOrString();
    DoubleOrString& operator=(const DoubleOrString&);
    DECLARE_TRACE();

private:
    enum SpecificTypes {
        SpecificTypeNone,
        SpecificTypeDouble,
        SpecificTypeString,
    };
    SpecificTypes m_type;

    double m_double;
    String m_string;

    friend CORE_EXPORT v8::Local<v8::Value> ToV8(const DoubleOrString&, v8::Local<v8::Object>, v8::Isolate*);
};

class V8DoubleOrString final {
public:
    CORE_EXPORT static void toImpl(v8::Isolate*, v8::Local<v8::Value>, DoubleOrString&, UnionTypeConversionMode, ExceptionState&);
};

CORE_EXPORT v8::Local<v8::Value> ToV8(const DoubleOrString&, v8::Local<v8::Object>, v8::Isolate*);

template <class CallbackInfo>
inline void v8SetReturnValue(const CallbackInfo& callbackInfo, DoubleOrString& impl)
{
    v8SetReturnValue(callbackInfo, ToV8(impl, callbackInfo.Holder(), callbackInfo.GetIsolate()));
}

template <>
struct NativeValueTraits<DoubleOrString> {
    CORE_EXPORT static DoubleOrString nativeValue(v8::Isolate*, v8::Local<v8::Value>, ExceptionState&);
};

} // namespace blink

// We need to set canInitializeWithMemset=true because HeapVector supports
// items that can initialize with memset or have a vtable. It is safe to
// set canInitializeWithMemset=true for a union type object in practice.
// See https://codereview.chromium.org/1118993002/#msg5 for more details.
WTF_ALLOW_MOVE_AND_INIT_WITH_MEM_FUNCTIONS(blink::DoubleOrString);

#endif // DoubleOrString_h
