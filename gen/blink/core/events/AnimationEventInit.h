// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.h.tmpl

// clang-format on
#ifndef AnimationEventInit_h
#define AnimationEventInit_h

#include "core/CoreExport.h"
#include "core/events/EventInit.h"
#include "platform/heap/Handle.h"
#include "wtf/text/WTFString.h"

namespace blink {

class CORE_EXPORT AnimationEventInit : public EventInit {
    DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();

public:
    AnimationEventInit();
    virtual ~AnimationEventInit();
    AnimationEventInit(const AnimationEventInit&);
    AnimationEventInit& operator=(const AnimationEventInit&);

    bool hasAnimationName() const;
    String animationName() const;
    void setAnimationName(String);

    bool hasElapsedTime() const;
    double elapsedTime() const;
    void setElapsedTime(double);

    v8::Local<v8::Value> toV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
    DECLARE_VIRTUAL_TRACE();

private:
    String m_animationName;
    bool m_hasElapsedTime = false;
    double m_elapsedTime;

    friend class V8AnimationEventInit;
};

} // namespace blink

#endif // AnimationEventInit_h
