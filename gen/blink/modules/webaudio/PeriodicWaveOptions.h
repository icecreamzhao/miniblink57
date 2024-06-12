// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.h.tmpl

// clang-format on
#ifndef PeriodicWaveOptions_h
#define PeriodicWaveOptions_h

#include "modules/ModulesExport.h"
#include "modules/webaudio/PeriodicWaveConstraints.h"
#include "platform/heap/Handle.h"
#include "wtf/Vector.h"

namespace blink {

class MODULES_EXPORT PeriodicWaveOptions : public PeriodicWaveConstraints {
    DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();

public:
    PeriodicWaveOptions();
    virtual ~PeriodicWaveOptions();
    PeriodicWaveOptions(const PeriodicWaveOptions&);
    PeriodicWaveOptions& operator=(const PeriodicWaveOptions&);

    bool hasImag() const;
    const Vector<float>& imag() const;
    void setImag(const Vector<float>&);

    bool hasReal() const;
    const Vector<float>& real() const;
    void setReal(const Vector<float>&);

    v8::Local<v8::Value> toV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
    DECLARE_VIRTUAL_TRACE();

private:
    bool m_hasImag = false;
    Vector<float> m_imag;
    bool m_hasReal = false;
    Vector<float> m_real;

    friend class V8PeriodicWaveOptions;
};

} // namespace blink

#endif // PeriodicWaveOptions_h
