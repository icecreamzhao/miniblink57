// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/push_messaging/PushPermissionStatusCallbacks.h"

#include "bindings/core/v8/ScriptPromiseResolver.h"
#include "modules/push_messaging/PushError.h"
<<<<<<< HEAD
#include "wtf/Assertions.h"
=======
>>>>>>> miniblink49
#include "wtf/text/WTFString.h"

namespace blink {

<<<<<<< HEAD
PushPermissionStatusCallbacks::PushPermissionStatusCallbacks(
    ScriptPromiseResolver* resolver)
=======
PushPermissionStatusCallbacks::PushPermissionStatusCallbacks(PassRefPtrWillBeRawPtr<ScriptPromiseResolver> resolver)
>>>>>>> miniblink49
    : m_resolver(resolver)
{
}

<<<<<<< HEAD
PushPermissionStatusCallbacks::~PushPermissionStatusCallbacks() { }

void PushPermissionStatusCallbacks::onSuccess(WebPushPermissionStatus status)
{
    m_resolver->resolve(permissionString(status));
}

void PushPermissionStatusCallbacks::onError(const WebPushError& error)
{
    if (!m_resolver->getExecutionContext() || m_resolver->getExecutionContext()->isContextDestroyed())
        return;
    m_resolver->reject(PushError::take(m_resolver.get(), error));
}

// static
String PushPermissionStatusCallbacks::permissionString(
    WebPushPermissionStatus status)
=======
PushPermissionStatusCallbacks::~PushPermissionStatusCallbacks()
{
}

void PushPermissionStatusCallbacks::onSuccess(WebPushPermissionStatus* status)
{
    m_resolver->resolve(permissionString(*status));
}

void PushPermissionStatusCallbacks::onError(WebPushError* error)
{
    OwnPtr<WebPushError> ownError = adoptPtr(error);
    if (!m_resolver->executionContext() || m_resolver->executionContext()->activeDOMObjectsAreStopped())
        return;
    m_resolver->reject(PushError::take(m_resolver.get(), ownError.release()));
}

// static
String PushPermissionStatusCallbacks::permissionString(WebPushPermissionStatus status)
>>>>>>> miniblink49
{
    switch (status) {
    case WebPushPermissionStatusGranted:
        return "granted";
    case WebPushPermissionStatusDenied:
        return "denied";
    case WebPushPermissionStatusPrompt:
        return "prompt";
    }

<<<<<<< HEAD
    NOTREACHED();
=======
    ASSERT_NOT_REACHED();
>>>>>>> miniblink49
    return "denied";
}

} // namespace blink
