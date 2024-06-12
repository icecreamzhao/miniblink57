// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.h.tmpl

// clang-format on
#ifndef IDBVersionChangeEventInit_h
#define IDBVersionChangeEventInit_h

#include "core/events/EventInit.h"
#include "modules/ModulesExport.h"
#include "platform/heap/Handle.h"
#include "wtf/text/WTFString.h"

namespace blink {

class MODULES_EXPORT IDBVersionChangeEventInit : public EventInit {
    DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();

public:
    IDBVersionChangeEventInit();
    virtual ~IDBVersionChangeEventInit();
    IDBVersionChangeEventInit(const IDBVersionChangeEventInit&);
    IDBVersionChangeEventInit& operator=(const IDBVersionChangeEventInit&);

    bool hasDataLoss() const;
    String dataLoss() const;
    void setDataLoss(String);

    bool hasNewVersion() const;
    unsigned long long newVersion() const;
    void setNewVersion(unsigned long long);
    void setNewVersionToNull();

    bool hasOldVersion() const;
    unsigned long long oldVersion() const;
    void setOldVersion(unsigned long long);

    v8::Local<v8::Value> toV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
    DECLARE_VIRTUAL_TRACE();

private:
    String m_dataLoss;
    bool m_hasNewVersion = false;
    unsigned long long m_newVersion;
    bool m_hasOldVersion = false;
    unsigned long long m_oldVersion;

    friend class V8IDBVersionChangeEventInit;
};

} // namespace blink

#endif // IDBVersionChangeEventInit_h
