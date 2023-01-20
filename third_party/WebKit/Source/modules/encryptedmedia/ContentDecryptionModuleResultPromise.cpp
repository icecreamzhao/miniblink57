// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/encryptedmedia/ContentDecryptionModuleResultPromise.h"

#include "bindings/core/v8/ScriptPromise.h"
#include "bindings/core/v8/ScriptState.h"
<<<<<<< HEAD
#include "bindings/core/v8/V8ThrowException.h"
#include "core/dom/DOMException.h"
#include "core/dom/ExecutionContext.h"
#include "core/dom/ExecutionContextTask.h"
=======
#include "core/dom/DOMException.h"
>>>>>>> miniblink49
#include "public/platform/WebString.h"
#include "wtf/Assertions.h"

namespace blink {

<<<<<<< HEAD
ExceptionCode WebCdmExceptionToExceptionCode(
    WebContentDecryptionModuleException cdmException)
{
    switch (cdmException) {
    case WebContentDecryptionModuleExceptionTypeError:
        return V8TypeError;
=======
ExceptionCode WebCdmExceptionToExceptionCode(WebContentDecryptionModuleException cdmException)
{
    switch (cdmException) {
>>>>>>> miniblink49
    case WebContentDecryptionModuleExceptionNotSupportedError:
        return NotSupportedError;
    case WebContentDecryptionModuleExceptionInvalidStateError:
        return InvalidStateError;
<<<<<<< HEAD
=======
    case WebContentDecryptionModuleExceptionInvalidAccessError:
        return InvalidAccessError;
>>>>>>> miniblink49
    case WebContentDecryptionModuleExceptionQuotaExceededError:
        return QuotaExceededError;
    case WebContentDecryptionModuleExceptionUnknownError:
        return UnknownError;
<<<<<<< HEAD
    }

    NOTREACHED();
    return UnknownError;
}

ContentDecryptionModuleResultPromise::ContentDecryptionModuleResultPromise(
    ScriptState* scriptState)
=======
    case WebContentDecryptionModuleExceptionClientError:
    case WebContentDecryptionModuleExceptionOutputError:
        // Currently no matching DOMException for these 2 errors.
        // FIXME: Update DOMException to handle these if actually added to
        // the EME spec.
        return UnknownError;
    }

    ASSERT_NOT_REACHED();
    return UnknownError;
}

ContentDecryptionModuleResultPromise::ContentDecryptionModuleResultPromise(ScriptState* scriptState)
>>>>>>> miniblink49
    : m_resolver(ScriptPromiseResolver::create(scriptState))
{
}

<<<<<<< HEAD
ContentDecryptionModuleResultPromise::~ContentDecryptionModuleResultPromise() { }

void ContentDecryptionModuleResultPromise::complete()
{
    NOTREACHED();
    if (!isValidToFulfillPromise())
        return;
    reject(InvalidStateError, "Unexpected completion.");
}

void ContentDecryptionModuleResultPromise::completeWithContentDecryptionModule(
    WebContentDecryptionModule* cdm)
{
    NOTREACHED();
    if (!isValidToFulfillPromise())
        return;
    reject(InvalidStateError, "Unexpected completion.");
}

void ContentDecryptionModuleResultPromise::completeWithSession(
    WebContentDecryptionModuleResult::SessionStatus status)
{
    NOTREACHED();
    if (!isValidToFulfillPromise())
        return;
    reject(InvalidStateError, "Unexpected completion.");
}

void ContentDecryptionModuleResultPromise::completeWithError(
    WebContentDecryptionModuleException exceptionCode,
    unsigned long systemCode,
    const WebString& errorMessage)
{
    if (!isValidToFulfillPromise())
        return;

    // Non-zero |systemCode| is appended to the |errorMessage|. If the
    // |errorMessage| is empty, we'll report "Rejected with system code
    // (systemCode)".
    StringBuilder result;
    result.append(errorMessage);
    if (systemCode != 0) {
        if (result.isEmpty())
            result.append("Rejected with system code");
        result.append(" (");
        result.appendNumber(systemCode);
        result.append(')');
    }
    reject(WebCdmExceptionToExceptionCode(exceptionCode), result.toString());
=======
ContentDecryptionModuleResultPromise::~ContentDecryptionModuleResultPromise()
{
}

void ContentDecryptionModuleResultPromise::complete()
{
    ASSERT_NOT_REACHED();
    reject(InvalidStateError, "Unexpected completion.");
}

void ContentDecryptionModuleResultPromise::completeWithContentDecryptionModule(WebContentDecryptionModule* cdm)
{
    ASSERT_NOT_REACHED();
    reject(InvalidStateError, "Unexpected completion.");
}

void ContentDecryptionModuleResultPromise::completeWithSession(WebContentDecryptionModuleResult::SessionStatus status)
{
    ASSERT_NOT_REACHED();
    reject(InvalidStateError, "Unexpected completion.");
}

void ContentDecryptionModuleResultPromise::completeWithError(WebContentDecryptionModuleException exceptionCode, unsigned long systemCode, const WebString& errorMessage)
{
    // Non-zero |systemCode| is appended to the |errorMessage|. If the
    // |errorMessage| is empty, we'll report "Rejected with system code
    // (systemCode)".
    String errorString = errorMessage;
    if (systemCode != 0) {
        if (errorString.isEmpty())
            errorString.append("Rejected with system code");
        errorString.append(" (" + String::number(systemCode) + ")");
    }
    reject(WebCdmExceptionToExceptionCode(exceptionCode), errorString);
>>>>>>> miniblink49
}

ScriptPromise ContentDecryptionModuleResultPromise::promise()
{
    return m_resolver->promise();
}

<<<<<<< HEAD
void ContentDecryptionModuleResultPromise::reject(ExceptionCode code,
    const String& errorMessage)
{
    DCHECK(isValidToFulfillPromise());

    ScriptState::Scope scope(m_resolver->getScriptState());
    v8::Isolate* isolate = m_resolver->getScriptState()->isolate();
    m_resolver->reject(
        V8ThrowException::createDOMException(isolate, code, errorMessage));
    m_resolver.clear();
}

ExecutionContext* ContentDecryptionModuleResultPromise::getExecutionContext()
    const
{
    return m_resolver->getExecutionContext();
}

bool ContentDecryptionModuleResultPromise::isValidToFulfillPromise()
{
    // getExecutionContext() is no longer valid once the context is destroyed.
    // isContextDestroyed() is called to see if the context is in the
    // process of being destroyed. If it is, there is no need to fulfill this
    // promise which is about to go away anyway.
    return getExecutionContext() && !getExecutionContext()->isContextDestroyed();
=======
void ContentDecryptionModuleResultPromise::reject(ExceptionCode code, const String& errorMessage)
{
    m_resolver->reject(DOMException::create(code, errorMessage));
    m_resolver.clear();
}

ExecutionContext* ContentDecryptionModuleResultPromise::executionContext() const
{
    return m_resolver->executionContext();
>>>>>>> miniblink49
}

DEFINE_TRACE(ContentDecryptionModuleResultPromise)
{
    visitor->trace(m_resolver);
    ContentDecryptionModuleResult::trace(visitor);
}

} // namespace blink
