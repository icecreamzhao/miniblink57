// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/callback_interface.h.tmpl

// clang-format on
#ifndef V8IdleRequestCallback_h
#define V8IdleRequestCallback_h

#include "bindings/core/v8/DOMWrapperWorld.h"
#include "bindings/core/v8/ScopedPersistent.h"
#include "core/CoreExport.h"
#include "core/dom/IdleRequestCallback.h"

namespace blink {

class V8IdleRequestCallback final : public IdleRequestCallback {
public:
    static V8IdleRequestCallback* create(v8::Local<v8::Function> callback, ScriptState* scriptState)
    {
        return new V8IdleRequestCallback(callback, scriptState);
    }

    ~V8IdleRequestCallback() override;

    DECLARE_VIRTUAL_TRACE();

    void handleEvent(IdleDeadline* deadline) override;

private:
    CORE_EXPORT V8IdleRequestCallback(v8::Local<v8::Function>, ScriptState*);

    ScopedPersistent<v8::Function> m_callback;
    RefPtr<ScriptState> m_scriptState;
};
}
#endif // V8IdleRequestCallback_h
