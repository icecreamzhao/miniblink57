// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.h.tmpl

// clang-format on
#ifndef TransitionEventInit_h
#define TransitionEventInit_h

#include "core/CoreExport.h"
#include "core/events/EventInit.h"
#include "platform/heap/Handle.h"
#include "wtf/text/WTFString.h"

namespace blink {

class CORE_EXPORT TransitionEventInit : public EventInit {
    DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();

public:
    TransitionEventInit();
    virtual ~TransitionEventInit();
    TransitionEventInit(const TransitionEventInit&);
    TransitionEventInit& operator=(const TransitionEventInit&);

    bool hasElapsedTime() const;
    double elapsedTime() const;
    void setElapsedTime(double);

    bool hasPropertyName() const;
    String propertyName() const;
    void setPropertyName(String);

    bool hasPseudoElement() const;
    String pseudoElement() const;
    void setPseudoElement(String);

    v8::Local<v8::Value> toV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
    DECLARE_VIRTUAL_TRACE();

private:
    bool m_hasElapsedTime = false;
    double m_elapsedTime;
    String m_propertyName;
    String m_pseudoElement;

    friend class V8TransitionEventInit;
};

} // namespace blink

#endif // TransitionEventInit_h
