// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/union_container.h.tmpl

// clang-format on
#ifndef HTMLOptionElementOrHTMLOptGroupElement_h
#define HTMLOptionElementOrHTMLOptGroupElement_h

#include "bindings/core/v8/Dictionary.h"
#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/V8Binding.h"
#include "core/CoreExport.h"
#include "platform/heap/Handle.h"

namespace blink {

class HTMLOptGroupElement;
class HTMLOptionElement;

class CORE_EXPORT HTMLOptionElementOrHTMLOptGroupElement final {
    DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();

public:
    HTMLOptionElementOrHTMLOptGroupElement();
    bool isNull() const { return m_type == SpecificTypeNone; }

    bool isHTMLOptionElement() const { return m_type == SpecificTypeHTMLOptionElement; }
    HTMLOptionElement* getAsHTMLOptionElement() const;
    void setHTMLOptionElement(HTMLOptionElement*);
    static HTMLOptionElementOrHTMLOptGroupElement fromHTMLOptionElement(HTMLOptionElement*);

    bool isHTMLOptGroupElement() const { return m_type == SpecificTypeHTMLOptGroupElement; }
    HTMLOptGroupElement* getAsHTMLOptGroupElement() const;
    void setHTMLOptGroupElement(HTMLOptGroupElement*);
    static HTMLOptionElementOrHTMLOptGroupElement fromHTMLOptGroupElement(HTMLOptGroupElement*);

    HTMLOptionElementOrHTMLOptGroupElement(const HTMLOptionElementOrHTMLOptGroupElement&);
    ~HTMLOptionElementOrHTMLOptGroupElement();
    HTMLOptionElementOrHTMLOptGroupElement& operator=(const HTMLOptionElementOrHTMLOptGroupElement&);
    DECLARE_TRACE();

private:
    enum SpecificTypes {
        SpecificTypeNone,
        SpecificTypeHTMLOptionElement,
        SpecificTypeHTMLOptGroupElement,
    };
    SpecificTypes m_type;

    Member<HTMLOptionElement> m_htmlOptionElement;
    Member<HTMLOptGroupElement> m_htmlOptGroupElement;

    friend CORE_EXPORT v8::Local<v8::Value> ToV8(const HTMLOptionElementOrHTMLOptGroupElement&, v8::Local<v8::Object>, v8::Isolate*);
};

class V8HTMLOptionElementOrHTMLOptGroupElement final {
public:
    CORE_EXPORT static void toImpl(v8::Isolate*, v8::Local<v8::Value>, HTMLOptionElementOrHTMLOptGroupElement&, UnionTypeConversionMode, ExceptionState&);
};

CORE_EXPORT v8::Local<v8::Value> ToV8(const HTMLOptionElementOrHTMLOptGroupElement&, v8::Local<v8::Object>, v8::Isolate*);

template <class CallbackInfo>
inline void v8SetReturnValue(const CallbackInfo& callbackInfo, HTMLOptionElementOrHTMLOptGroupElement& impl)
{
    v8SetReturnValue(callbackInfo, ToV8(impl, callbackInfo.Holder(), callbackInfo.GetIsolate()));
}

template <>
struct NativeValueTraits<HTMLOptionElementOrHTMLOptGroupElement> {
    CORE_EXPORT static HTMLOptionElementOrHTMLOptGroupElement nativeValue(v8::Isolate*, v8::Local<v8::Value>, ExceptionState&);
};

} // namespace blink

// We need to set canInitializeWithMemset=true because HeapVector supports
// items that can initialize with memset or have a vtable. It is safe to
// set canInitializeWithMemset=true for a union type object in practice.
// See https://codereview.chromium.org/1118993002/#msg5 for more details.
WTF_ALLOW_MOVE_AND_INIT_WITH_MEM_FUNCTIONS(blink::HTMLOptionElementOrHTMLOptGroupElement);

#endif // HTMLOptionElementOrHTMLOptGroupElement_h
