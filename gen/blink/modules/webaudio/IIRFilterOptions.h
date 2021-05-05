// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.h.tmpl

// clang-format off
#ifndef IIRFilterOptions_h
#define IIRFilterOptions_h

#include "modules/ModulesExport.h"
#include "modules/webaudio/AudioNodeOptions.h"
#include "platform/heap/Handle.h"
#include "wtf/Vector.h"

namespace blink {

class MODULES_EXPORT IIRFilterOptions : public AudioNodeOptions {
  DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();
 public:
  IIRFilterOptions();
  virtual ~IIRFilterOptions();
  IIRFilterOptions(const IIRFilterOptions&);
  IIRFilterOptions& operator=(const IIRFilterOptions&);

  bool hasFeedback() const;
  const Vector<double>& feedback() const;
  void setFeedback(const Vector<double>&);

  bool hasFeedforward() const;
  const Vector<double>& feedforward() const;
  void setFeedforward(const Vector<double>&);

  v8::Local<v8::Value> toV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  DECLARE_VIRTUAL_TRACE();

 private:
  bool m_hasFeedback = false;
  Vector<double> m_feedback;
  bool m_hasFeedforward = false;
  Vector<double> m_feedforward;

  friend class V8IIRFilterOptions;
};

}  // namespace blink

#endif  // IIRFilterOptions_h
