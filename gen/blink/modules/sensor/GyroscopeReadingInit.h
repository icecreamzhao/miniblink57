// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.h.tmpl

// clang-format off
#ifndef GyroscopeReadingInit_h
#define GyroscopeReadingInit_h

#include "bindings/core/v8/IDLDictionaryBase.h"
#include "modules/ModulesExport.h"
#include "platform/heap/Handle.h"

namespace blink {

class MODULES_EXPORT GyroscopeReadingInit : public IDLDictionaryBase {
  DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();
 public:
  GyroscopeReadingInit();
  virtual ~GyroscopeReadingInit();
  GyroscopeReadingInit(const GyroscopeReadingInit&);
  GyroscopeReadingInit& operator=(const GyroscopeReadingInit&);

  bool hasX() const;
  double x() const;
  void setX(double);

  bool hasY() const;
  double y() const;
  void setY(double);

  bool hasZ() const;
  double z() const;
  void setZ(double);

  v8::Local<v8::Value> toV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  DECLARE_VIRTUAL_TRACE();

 private:
  bool m_hasX = false;
  double m_x;
  bool m_hasY = false;
  double m_y;
  bool m_hasZ = false;
  double m_z;

  friend class V8GyroscopeReadingInit;
};

}  // namespace blink

#endif  // GyroscopeReadingInit_h
