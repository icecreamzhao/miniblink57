// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.h.tmpl

// clang-format off
#ifndef EventListenerOptions_h
#define EventListenerOptions_h

#include "bindings/core/v8/IDLDictionaryBase.h"
#include "core/CoreExport.h"
#include "platform/heap/Handle.h"

namespace blink {

class CORE_EXPORT EventListenerOptions : public IDLDictionaryBase {
  DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();
 public:
  EventListenerOptions();
  virtual ~EventListenerOptions();
  EventListenerOptions(const EventListenerOptions&);
  EventListenerOptions& operator=(const EventListenerOptions&);

  bool hasCapture() const;
  bool capture() const;
  void setCapture(bool);

  v8::Local<v8::Value> toV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  DECLARE_VIRTUAL_TRACE();

 private:
  bool m_hasCapture = false;
  bool m_capture;

  friend class V8EventListenerOptions;
};

}  // namespace blink

#endif  // EventListenerOptions_h
