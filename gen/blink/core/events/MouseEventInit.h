// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.h.tmpl

// clang-format on
#ifndef MouseEventInit_h
#define MouseEventInit_h

#include "core/CoreExport.h"
#include "core/events/EventModifierInit.h"
#include "platform/heap/Handle.h"
#include "wtf/text/WTFString.h"

namespace blink {

class EventTarget;

class CORE_EXPORT MouseEventInit : public EventModifierInit {
    DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();

public:
    MouseEventInit();
    virtual ~MouseEventInit();
    MouseEventInit(const MouseEventInit&);
    MouseEventInit& operator=(const MouseEventInit&);

    bool hasButton() const;
    int button() const;
    void setButton(int);

    bool hasButtons() const;
    unsigned buttons() const;
    void setButtons(unsigned);

    bool hasClientX() const;
    double clientX() const;
    void setClientX(double);

    bool hasClientY() const;
    double clientY() const;
    void setClientY(double);

    bool hasMovementX() const;
    int movementX() const;
    void setMovementX(int);

    bool hasMovementY() const;
    int movementY() const;
    void setMovementY(int);

    bool hasRegion() const;
    String region() const;
    void setRegion(String);
    void setRegionToNull();

    bool hasRelatedTarget() const;
    EventTarget* relatedTarget() const;
    void setRelatedTarget(EventTarget*);
    void setRelatedTargetToNull();

    bool hasScreenX() const;
    double screenX() const;
    void setScreenX(double);

    bool hasScreenY() const;
    double screenY() const;
    void setScreenY(double);

    v8::Local<v8::Value> toV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
    DECLARE_VIRTUAL_TRACE();

private:
    bool m_hasButton = false;
    int m_button;
    bool m_hasButtons = false;
    unsigned m_buttons;
    bool m_hasClientX = false;
    double m_clientX;
    bool m_hasClientY = false;
    double m_clientY;
    bool m_hasMovementX = false;
    int m_movementX;
    bool m_hasMovementY = false;
    int m_movementY;
    String m_region;
    Member<EventTarget> m_relatedTarget;
    bool m_hasScreenX = false;
    double m_screenX;
    bool m_hasScreenY = false;
    double m_screenY;

    friend class V8MouseEventInit;
};

} // namespace blink

#endif // MouseEventInit_h
