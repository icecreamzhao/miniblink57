// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.h.tmpl

// clang-format off
#ifndef StereoPannerOptions_h
#define StereoPannerOptions_h

#include "modules/ModulesExport.h"
#include "modules/webaudio/AudioNodeOptions.h"
#include "platform/heap/Handle.h"

namespace blink {

class MODULES_EXPORT StereoPannerOptions : public AudioNodeOptions {
  DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();
 public:
  StereoPannerOptions();
  virtual ~StereoPannerOptions();
  StereoPannerOptions(const StereoPannerOptions&);
  StereoPannerOptions& operator=(const StereoPannerOptions&);

  bool hasPan() const;
  float pan() const;
  void setPan(float);

  v8::Local<v8::Value> toV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  DECLARE_VIRTUAL_TRACE();

 private:
  bool m_hasPan = false;
  float m_pan;

  friend class V8StereoPannerOptions;
};

}  // namespace blink

#endif  // StereoPannerOptions_h
