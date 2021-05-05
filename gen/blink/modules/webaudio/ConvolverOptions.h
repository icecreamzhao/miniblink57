// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.h.tmpl

// clang-format off
#ifndef ConvolverOptions_h
#define ConvolverOptions_h

#include "modules/ModulesExport.h"
#include "modules/webaudio/AudioNodeOptions.h"
#include "platform/heap/Handle.h"

namespace blink {

class AudioBuffer;

class MODULES_EXPORT ConvolverOptions : public AudioNodeOptions {
  DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();
 public:
  ConvolverOptions();
  virtual ~ConvolverOptions();
  ConvolverOptions(const ConvolverOptions&);
  ConvolverOptions& operator=(const ConvolverOptions&);

  bool hasBuffer() const;
  AudioBuffer* buffer() const;
  void setBuffer(AudioBuffer*);
  void setBufferToNull();

  bool hasDisableNormalization() const;
  bool disableNormalization() const;
  void setDisableNormalization(bool);

  v8::Local<v8::Value> toV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  DECLARE_VIRTUAL_TRACE();

 private:
  Member<AudioBuffer> m_buffer;
  bool m_hasDisableNormalization = false;
  bool m_disableNormalization;

  friend class V8ConvolverOptions;
};

}  // namespace blink

#endif  // ConvolverOptions_h
