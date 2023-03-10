// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.h.tmpl

// clang-format on
#ifndef DynamicsCompressorOptions_h
#define DynamicsCompressorOptions_h

#include "modules/ModulesExport.h"
#include "modules/webaudio/AudioNodeOptions.h"
#include "platform/heap/Handle.h"

namespace blink {

class MODULES_EXPORT DynamicsCompressorOptions : public AudioNodeOptions {
    DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();

public:
    DynamicsCompressorOptions();
    virtual ~DynamicsCompressorOptions();
    DynamicsCompressorOptions(const DynamicsCompressorOptions&);
    DynamicsCompressorOptions& operator=(const DynamicsCompressorOptions&);

    bool hasAttack() const;
    float attack() const;
    void setAttack(float);

    bool hasKnee() const;
    float knee() const;
    void setKnee(float);

    bool hasRatio() const;
    float ratio() const;
    void setRatio(float);

    bool hasRelease() const;
    float release() const;
    void setRelease(float);

    bool hasThreshold() const;
    float threshold() const;
    void setThreshold(float);

    v8::Local<v8::Value> toV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
    DECLARE_VIRTUAL_TRACE();

private:
    bool m_hasAttack = false;
    float m_attack;
    bool m_hasKnee = false;
    float m_knee;
    bool m_hasRatio = false;
    float m_ratio;
    bool m_hasRelease = false;
    float m_release;
    bool m_hasThreshold = false;
    float m_threshold;

    friend class V8DynamicsCompressorOptions;
};

} // namespace blink

#endif // DynamicsCompressorOptions_h
