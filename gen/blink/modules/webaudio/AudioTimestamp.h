// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.h.tmpl

// clang-format off
#ifndef AudioTimestamp_h
#define AudioTimestamp_h

#include "bindings/core/v8/IDLDictionaryBase.h"
#include "modules/ModulesExport.h"
#include "platform/heap/Handle.h"

namespace blink {

class MODULES_EXPORT AudioTimestamp : public IDLDictionaryBase {
  DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();
 public:
  AudioTimestamp();
  virtual ~AudioTimestamp();
  AudioTimestamp(const AudioTimestamp&);
  AudioTimestamp& operator=(const AudioTimestamp&);

  bool hasContextTime() const;
  double contextTime() const;
  void setContextTime(double);

  bool hasPerformanceTime() const;
  double performanceTime() const;
  void setPerformanceTime(double);

  v8::Local<v8::Value> toV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  DECLARE_VIRTUAL_TRACE();

 private:
  bool m_hasContextTime = false;
  double m_contextTime;
  bool m_hasPerformanceTime = false;
  double m_performanceTime;

  friend class V8AudioTimestamp;
};

}  // namespace blink

#endif  // AudioTimestamp_h
