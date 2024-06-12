// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/callback_interface.cpp.tmpl

// clang-format on
#include "V8MessageCallback.h"

#include "bindings/core/v8/ScriptController.h"
#include "bindings/core/v8/V8Binding.h"
#include "bindings/modules/v8/V8NFCMessage.h"
#include "core/dom/ExecutionContext.h"
#include "wtf/Assertions.h"
#include "wtf/GetPtr.h"
#include "wtf/RefPtr.h"

namespace blink {

V8MessageCallback::V8MessageCallback(v8::Local<v8::Function> callback, ScriptState* scriptState)
    : m_scriptState(scriptState)
{
    m_callback.set(scriptState->isolate(), callback);
}

V8MessageCallback::~V8MessageCallback() { }

DEFINE_TRACE(V8MessageCallback)
{
    MessageCallback::trace(visitor);
}

void V8MessageCallback::handleMessage(const NFCMessage& message)
{
    ExecutionContext* executionContext = m_scriptState->getExecutionContext();
    if (!executionContext || executionContext->isContextSuspended() || executionContext->isContextDestroyed())
        return;
    if (!m_scriptState->contextIsValid())
        return;
    ScriptState::Scope scope(m_scriptState.get());
    v8::Local<v8::Value> messageHandle = ToV8(message, m_scriptState->context()->Global(), m_scriptState->isolate());
    v8::Local<v8::Value> argv[] = { messageHandle };

    V8ScriptRunner::callFunction(m_callback.newLocal(m_scriptState->isolate()), m_scriptState->getExecutionContext(), v8::Undefined(m_scriptState->isolate()), 1, argv, m_scriptState->isolate());
}

} // namespace blink
