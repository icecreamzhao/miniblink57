// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/callback_interface.h.tmpl

// clang-format off
#ifndef V8TestCallbackInterface_h
#define V8TestCallbackInterface_h

#include "bindings/core/v8/DOMWrapperWorld.h"
#include "bindings/core/v8/ScopedPersistent.h"
#include "bindings/tests/idls/core/TestCallbackInterface.h"
#include "core/CoreExport.h"

namespace blink {

class V8TestCallbackInterface final : public TestCallbackInterface {
 public:
  static V8TestCallbackInterface* create(v8::Local<v8::Function> callback, ScriptState* scriptState) {
    return new V8TestCallbackInterface(callback, scriptState);
  }

  ~V8TestCallbackInterface() override;

  DECLARE_VIRTUAL_TRACE();

  void voidMethod() override;
  bool booleanMethod() override;
  void voidMethodBooleanArg(bool boolArg) override;
  void voidMethodSequenceArg(const HeapVector<Member<TestInterfaceEmpty>>& sequenceArg) override;
  void voidMethodFloatArg(float floatArg) override;
  void voidMethodTestInterfaceEmptyArg(TestInterfaceEmpty* testInterfaceEmptyArg) override;
  void voidMethodTestInterfaceEmptyStringArg(TestInterfaceEmpty* testInterfaceEmptyArg, const String& stringArg) override;
  void callbackWithThisValueVoidMethodStringArg(ScriptValue thisValue, const String& stringArg) override;
  void customVoidMethodTestInterfaceEmptyArg(TestInterfaceEmpty* testInterfaceEmptyArg) override;
 private:
  CORE_EXPORT V8TestCallbackInterface(v8::Local<v8::Function>, ScriptState*);

  ScopedPersistent<v8::Function> m_callback;
  RefPtr<ScriptState> m_scriptState;
};
}
#endif  // V8TestCallbackInterface_h
