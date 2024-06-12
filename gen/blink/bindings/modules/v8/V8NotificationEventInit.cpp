// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py.
// DO NOT MODIFY!

// This file has been generated from the Jinja2 template in
// third_party/WebKit/Source/bindings/templates/dictionary_v8.cpp.tmpl

// clang-format on
#include "V8NotificationEventInit.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/modules/v8/V8ExtendableEventInit.h"
#include "bindings/modules/v8/V8Notification.h"
#include "platform/RuntimeEnabledFeatures.h"

namespace blink {

void V8NotificationEventInit::toImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8Value, NotificationEventInit& impl, ExceptionState& exceptionState)
{
    if (isUndefinedOrNull(v8Value)) {
        exceptionState.throwTypeError("Missing required member(s): notification.");
        return;
    }
    if (!v8Value->IsObject()) {
        exceptionState.throwTypeError("cannot convert to dictionary.");
        return;
    }

    V8ExtendableEventInit::toImpl(isolate, v8Value, impl, exceptionState);
    if (exceptionState.hadException())
        return;

    v8::TryCatch block(isolate);
    v8::Local<v8::Object> v8Object;
    if (!v8Call(v8Value->ToObject(isolate->GetCurrentContext()), v8Object, block)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    v8::Local<v8::Value> actionValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "action")).ToLocal(&actionValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (actionValue.IsEmpty() || actionValue->IsUndefined()) {
        // Do nothing.
    } else {
        V8StringResource<> action = actionValue;
        if (!action.prepare(exceptionState))
            return;
        impl.setAction(action);
    }

    v8::Local<v8::Value> notificationValue;
    if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "notification")).ToLocal(&notificationValue)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    if (notificationValue.IsEmpty() || notificationValue->IsUndefined()) {
        exceptionState.throwTypeError("required member notification is undefined.");
        return;
    } else {
        Notification* notification = V8Notification::toImplWithTypeCheck(isolate, notificationValue);
        if (!notification) {
            exceptionState.throwTypeError("member notification is not of type Notification.");
            return;
        }
        impl.setNotification(notification);
    }

    if (RuntimeEnabledFeatures::notificationInlineRepliesEnabled()) {
        v8::Local<v8::Value> replyValue;
        if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "reply")).ToLocal(&replyValue)) {
            exceptionState.rethrowV8Exception(block.Exception());
            return;
        }
        if (replyValue.IsEmpty() || replyValue->IsUndefined()) {
            // Do nothing.
        } else if (replyValue->IsNull()) {
            impl.setReplyToNull();
        } else {
            V8StringResource<> reply = replyValue;
            if (!reply.prepare(exceptionState))
                return;
            impl.setReply(reply);
        }
    }
}

v8::Local<v8::Value> NotificationEventInit::toV8Impl(v8::Local<v8::Object> creationContext, v8::Isolate* isolate) const
{
    v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
    if (!toV8NotificationEventInit(*this, v8Object, creationContext, isolate))
        return v8::Undefined(isolate);
    return v8Object;
}

bool toV8NotificationEventInit(const NotificationEventInit& impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate)
{
    if (!toV8ExtendableEventInit(impl, dictionary, creationContext, isolate))
        return false;

    if (impl.hasAction()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "action"), v8String(isolate, impl.action()))))
            return false;
    } else {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "action"), v8String(isolate, String("")))))
            return false;
    }

    if (impl.hasNotification()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "notification"), ToV8(impl.notification(), creationContext, isolate))))
            return false;
    } else {
        NOTREACHED();
    }

    if (impl.hasReply()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "reply"), v8String(isolate, impl.reply()))))
            return false;
    } else {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "reply"), v8String(isolate, String("")))))
            return false;
    }

    return true;
}

NotificationEventInit NativeValueTraits<NotificationEventInit>::nativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exceptionState)
{
    NotificationEventInit impl;
    V8NotificationEventInit::toImpl(isolate, value, impl, exceptionState);
    return impl;
}

} // namespace blink
