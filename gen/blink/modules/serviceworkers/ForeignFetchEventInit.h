// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.h.tmpl

// clang-format on
#ifndef ForeignFetchEventInit_h
#define ForeignFetchEventInit_h

#include "modules/ModulesExport.h"
#include "modules/serviceworkers/ExtendableEventInit.h"
#include "platform/heap/Handle.h"
#include "wtf/text/WTFString.h"

namespace blink {

class Request;

class MODULES_EXPORT ForeignFetchEventInit : public ExtendableEventInit {
    DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();

public:
    ForeignFetchEventInit();
    virtual ~ForeignFetchEventInit();
    ForeignFetchEventInit(const ForeignFetchEventInit&);
    ForeignFetchEventInit& operator=(const ForeignFetchEventInit&);

    bool hasOrigin() const;
    String origin() const;
    void setOrigin(String);

    bool hasRequest() const;
    Request* request() const;
    void setRequest(Request*);

    v8::Local<v8::Value> toV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
    DECLARE_VIRTUAL_TRACE();

private:
    String m_origin;
    Member<Request> m_request;

    friend class V8ForeignFetchEventInit;
};

} // namespace blink

#endif // ForeignFetchEventInit_h
