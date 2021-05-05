// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/callback_interface.h.tmpl

// clang-format off
#ifndef V8FileSystemCallback_h
#define V8FileSystemCallback_h

#include "bindings/core/v8/DOMWrapperWorld.h"
#include "bindings/core/v8/ScopedPersistent.h"
#include "modules/ModulesExport.h"
#include "modules/filesystem/FileSystemCallback.h"

namespace blink {

class V8FileSystemCallback final : public FileSystemCallback {
 public:
  static V8FileSystemCallback* create(v8::Local<v8::Function> callback, ScriptState* scriptState) {
    return new V8FileSystemCallback(callback, scriptState);
  }

  ~V8FileSystemCallback() override;

  DECLARE_VIRTUAL_TRACE();

  void handleEvent(DOMFileSystem* fileSystem) override;
 private:
  MODULES_EXPORT V8FileSystemCallback(v8::Local<v8::Function>, ScriptState*);

  ScopedPersistent<v8::Function> m_callback;
  RefPtr<ScriptState> m_scriptState;
};
}
#endif  // V8FileSystemCallback_h
