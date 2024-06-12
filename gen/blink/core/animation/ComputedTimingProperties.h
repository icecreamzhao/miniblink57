// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.h.tmpl

// clang-format on
#ifndef ComputedTimingProperties_h
#define ComputedTimingProperties_h

#include "core/CoreExport.h"
#include "core/animation/AnimationEffectTimingProperties.h"
#include "platform/heap/Handle.h"

namespace blink {

class CORE_EXPORT ComputedTimingProperties : public AnimationEffectTimingProperties {
    DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();

public:
    ComputedTimingProperties();
    virtual ~ComputedTimingProperties();
    ComputedTimingProperties(const ComputedTimingProperties&);
    ComputedTimingProperties& operator=(const ComputedTimingProperties&);

    bool hasActiveDuration() const;
    double activeDuration() const;
    void setActiveDuration(double);

    bool hasCurrentIteration() const;
    double currentIteration() const;
    void setCurrentIteration(double);
    void setCurrentIterationToNull();

    bool hasEndTime() const;
    double endTime() const;
    void setEndTime(double);

    bool hasLocalTime() const;
    double localTime() const;
    void setLocalTime(double);
    void setLocalTimeToNull();

    bool hasProgress() const;
    double progress() const;
    void setProgress(double);
    void setProgressToNull();

    v8::Local<v8::Value> toV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
    DECLARE_VIRTUAL_TRACE();

private:
    bool m_hasActiveDuration = false;
    double m_activeDuration;
    bool m_hasCurrentIteration = false;
    double m_currentIteration;
    bool m_hasEndTime = false;
    double m_endTime;
    bool m_hasLocalTime = false;
    double m_localTime;
    bool m_hasProgress = false;
    double m_progress;

    friend class V8ComputedTimingProperties;
};

} // namespace blink

#endif // ComputedTimingProperties_h
