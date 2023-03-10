// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.h.tmpl

// clang-format on
#ifndef ElementRegistrationOptions_h
#define ElementRegistrationOptions_h

#include "bindings/core/v8/IDLDictionaryBase.h"
#include "bindings/core/v8/ScriptValue.h"
#include "core/CoreExport.h"
#include "platform/heap/Handle.h"
#include "wtf/text/WTFString.h"

namespace blink {

class CORE_EXPORT ElementRegistrationOptions : public IDLDictionaryBase {
    DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();

public:
    ElementRegistrationOptions();
    virtual ~ElementRegistrationOptions();
    ElementRegistrationOptions(const ElementRegistrationOptions&);
    ElementRegistrationOptions& operator=(const ElementRegistrationOptions&);

    bool hasExtends() const;
    String extends() const;
    void setExtends(String);
    void setExtendsToNull();

    bool hasPrototype() const;
    ScriptValue prototype() const;
    void setPrototype(ScriptValue);
    void setPrototypeToNull();

    v8::Local<v8::Value> toV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
    DECLARE_VIRTUAL_TRACE();

private:
    String m_extends;
    ScriptValue m_prototype;

    friend class V8ElementRegistrationOptions;
};

} // namespace blink

#endif // ElementRegistrationOptions_h
