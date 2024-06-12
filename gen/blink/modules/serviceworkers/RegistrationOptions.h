// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.h.tmpl

// clang-format on
#ifndef RegistrationOptions_h
#define RegistrationOptions_h

#include "bindings/core/v8/IDLDictionaryBase.h"
#include "modules/ModulesExport.h"
#include "platform/heap/Handle.h"
#include "wtf/text/WTFString.h"

namespace blink {

class MODULES_EXPORT RegistrationOptions : public IDLDictionaryBase {
    DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();

public:
    RegistrationOptions();
    virtual ~RegistrationOptions();
    RegistrationOptions(const RegistrationOptions&);
    RegistrationOptions& operator=(const RegistrationOptions&);

    bool hasScope() const;
    String scope() const;
    void setScope(String);

    v8::Local<v8::Value> toV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
    DECLARE_VIRTUAL_TRACE();

private:
    String m_scope;

    friend class V8RegistrationOptions;
};

} // namespace blink

#endif // RegistrationOptions_h
