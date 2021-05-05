// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_impl.h.tmpl

// clang-format off
#ifndef GamepadEventInit_h
#define GamepadEventInit_h

#include "core/events/EventInit.h"
#include "modules/ModulesExport.h"
#include "platform/heap/Handle.h"

namespace blink {

class Gamepad;

class MODULES_EXPORT GamepadEventInit : public EventInit {
  DISALLOW_NEW_EXCEPT_PLACEMENT_NEW();
 public:
  GamepadEventInit();
  virtual ~GamepadEventInit();
  GamepadEventInit(const GamepadEventInit&);
  GamepadEventInit& operator=(const GamepadEventInit&);

  bool hasGamepad() const;
  Gamepad* gamepad() const;
  void setGamepad(Gamepad*);
  void setGamepadToNull();

  v8::Local<v8::Value> toV8Impl(v8::Local<v8::Object>, v8::Isolate*) const override;
  DECLARE_VIRTUAL_TRACE();

 private:
  Member<Gamepad> m_gamepad;

  friend class V8GamepadEventInit;
};

}  // namespace blink

#endif  // GamepadEventInit_h
