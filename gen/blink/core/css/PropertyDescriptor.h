// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.h.tmpl

// clang-format on
#ifndef PropertyDescriptor_h
#define PropertyDescriptor_h

#include "bindings/core/v8/IDLDictionaryBase.h"
#include "core/CoreExport.h"
#include "platform/heap/Handle.h"
#include "wtf/text/WTFString.h"

namespace blink {

class CORE_EXPORT PropertyDescriptor : public IDLDictionaryBase {
    DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();

public:
    PropertyDescriptor();
    virtual ~PropertyDescriptor();
    PropertyDescriptor(const PropertyDescriptor&);
    PropertyDescriptor& operator=(const PropertyDescriptor&);

    bool hasInherits() const;
    bool inherits() const;
    void setInherits(bool);

    bool hasInitialValue() const;
    String initialValue() const;
    void setInitialValue(String);

    bool hasName() const;
    String name() const;
    void setName(String);

    bool hasSyntax() const;
    String syntax() const;
    void setSyntax(String);

    v8::Local<v8::Value> toV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
    DECLARE_VIRTUAL_TRACE();

private:
    bool m_hasInherits = false;
    bool m_inherits;
    String m_initialValue;
    String m_name;
    String m_syntax;

    friend class V8PropertyDescriptor;
};

} // namespace blink

#endif // PropertyDescriptor_h
