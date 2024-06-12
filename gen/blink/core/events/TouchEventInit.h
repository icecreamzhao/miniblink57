// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.h.tmpl

// clang-format on
#ifndef TouchEventInit_h
#define TouchEventInit_h

#include "core/CoreExport.h"
#include "core/events/EventModifierInit.h"
#include "platform/heap/Handle.h"

namespace blink {

class Touch;

class CORE_EXPORT TouchEventInit : public EventModifierInit {
    DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();

public:
    TouchEventInit();
    virtual ~TouchEventInit();
    TouchEventInit(const TouchEventInit&);
    TouchEventInit& operator=(const TouchEventInit&);

    bool hasChangedTouches() const;
    const HeapVector<Member<Touch>>& changedTouches() const;
    void setChangedTouches(const HeapVector<Member<Touch>>&);

    bool hasTargetTouches() const;
    const HeapVector<Member<Touch>>& targetTouches() const;
    void setTargetTouches(const HeapVector<Member<Touch>>&);

    bool hasTouches() const;
    const HeapVector<Member<Touch>>& touches() const;
    void setTouches(const HeapVector<Member<Touch>>&);

    v8::Local<v8::Value> toV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
    DECLARE_VIRTUAL_TRACE();

private:
    bool m_hasChangedTouches = false;
    HeapVector<Member<Touch>> m_changedTouches;
    bool m_hasTargetTouches = false;
    HeapVector<Member<Touch>> m_targetTouches;
    bool m_hasTouches = false;
    HeapVector<Member<Touch>> m_touches;

    friend class V8TouchEventInit;
};

} // namespace blink

#endif // TouchEventInit_h
