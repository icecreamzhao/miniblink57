// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/union_container.h.tmpl

// clang-format on
#ifndef ArrayBufferOrArrayBufferViewOrUSVString_h
#define ArrayBufferOrArrayBufferViewOrUSVString_h

#include "bindings/core/v8/Dictionary.h"
#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/V8Binding.h"
#include "modules/ModulesExport.h"
#include "platform/heap/Handle.h"

namespace blink {

class DOMArrayBuffer;
class DOMArrayBufferView;

class MODULES_EXPORT ArrayBufferOrArrayBufferViewOrUSVString final {
    DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();

public:
    ArrayBufferOrArrayBufferViewOrUSVString();
    bool isNull() const { return m_type == SpecificTypeNone; }

    bool isArrayBuffer() const { return m_type == SpecificTypeArrayBuffer; }
    DOMArrayBuffer* getAsArrayBuffer() const;
    void setArrayBuffer(DOMArrayBuffer*);
    static ArrayBufferOrArrayBufferViewOrUSVString fromArrayBuffer(DOMArrayBuffer*);

    bool isArrayBufferView() const { return m_type == SpecificTypeArrayBufferView; }
    DOMArrayBufferView* getAsArrayBufferView() const;
    void setArrayBufferView(DOMArrayBufferView*);
    static ArrayBufferOrArrayBufferViewOrUSVString fromArrayBufferView(DOMArrayBufferView*);

    bool isUSVString() const { return m_type == SpecificTypeUSVString; }
    String getAsUSVString() const;
    void setUSVString(String);
    static ArrayBufferOrArrayBufferViewOrUSVString fromUSVString(String);

    ArrayBufferOrArrayBufferViewOrUSVString(const ArrayBufferOrArrayBufferViewOrUSVString&);
    ~ArrayBufferOrArrayBufferViewOrUSVString();
    ArrayBufferOrArrayBufferViewOrUSVString& operator=(const ArrayBufferOrArrayBufferViewOrUSVString&);
    DECLARE_TRACE();

private:
    enum SpecificTypes {
        SpecificTypeNone,
        SpecificTypeArrayBuffer,
        SpecificTypeArrayBufferView,
        SpecificTypeUSVString,
    };
    SpecificTypes m_type;

    Member<DOMArrayBuffer> m_arrayBuffer;
    Member<DOMArrayBufferView> m_arrayBufferView;
    String m_uSVString;

    friend MODULES_EXPORT v8::Local<v8::Value> ToV8(const ArrayBufferOrArrayBufferViewOrUSVString&, v8::Local<v8::Object>, v8::Isolate*);
};

class V8ArrayBufferOrArrayBufferViewOrUSVString final {
public:
    MODULES_EXPORT static void toImpl(v8::Isolate*, v8::Local<v8::Value>, ArrayBufferOrArrayBufferViewOrUSVString&, UnionTypeConversionMode, ExceptionState&);
};

MODULES_EXPORT v8::Local<v8::Value> ToV8(const ArrayBufferOrArrayBufferViewOrUSVString&, v8::Local<v8::Object>, v8::Isolate*);

template <class CallbackInfo>
inline void v8SetReturnValue(const CallbackInfo& callbackInfo, ArrayBufferOrArrayBufferViewOrUSVString& impl)
{
    v8SetReturnValue(callbackInfo, ToV8(impl, callbackInfo.Holder(), callbackInfo.GetIsolate()));
}

template <>
struct NativeValueTraits<ArrayBufferOrArrayBufferViewOrUSVString> {
    MODULES_EXPORT static ArrayBufferOrArrayBufferViewOrUSVString nativeValue(v8::Isolate*, v8::Local<v8::Value>, ExceptionState&);
};

} // namespace blink

// We need to set canInitializeWithMemset=true because HeapVector supports
// items that can initialize with memset or have a vtable. It is safe to
// set canInitializeWithMemset=true for a union type object in practice.
// See https://codereview.chromium.org/1118993002/#msg5 for more details.
WTF_ALLOW_MOVE_AND_INIT_WITH_MEM_FUNCTIONS(blink::ArrayBufferOrArrayBufferViewOrUSVString);

#endif // ArrayBufferOrArrayBufferViewOrUSVString_h
