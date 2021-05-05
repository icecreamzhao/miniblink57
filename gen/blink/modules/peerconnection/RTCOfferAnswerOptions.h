// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.h.tmpl

// clang-format off
#ifndef RTCOfferAnswerOptions_h
#define RTCOfferAnswerOptions_h

#include "bindings/core/v8/IDLDictionaryBase.h"
#include "modules/ModulesExport.h"
#include "platform/heap/Handle.h"

namespace blink {

class MODULES_EXPORT RTCOfferAnswerOptions : public IDLDictionaryBase {
  DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();
 public:
  RTCOfferAnswerOptions();
  virtual ~RTCOfferAnswerOptions();
  RTCOfferAnswerOptions(const RTCOfferAnswerOptions&);
  RTCOfferAnswerOptions& operator=(const RTCOfferAnswerOptions&);

  bool hasVoiceActivityDetection() const;
  bool voiceActivityDetection() const;
  void setVoiceActivityDetection(bool);

  v8::Local<v8::Value> toV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  DECLARE_VIRTUAL_TRACE();

 private:
  bool m_hasVoiceActivityDetection = false;
  bool m_voiceActivityDetection;

  friend class V8RTCOfferAnswerOptions;
};

}  // namespace blink

#endif  // RTCOfferAnswerOptions_h
