// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
#include "modules/audio_output_devices/SetSinkIdCallbacks.h"

#include "bindings/core/v8/ScriptPromiseResolver.h"
#include "core/dom/DOMException.h"
#include "modules/audio_output_devices/HTMLMediaElementAudioOutputDevice.h"

namespace blink {

namespace {

    DOMException* ToException(WebSetSinkIdError error)
    {
        switch (error) {
        case WebSetSinkIdError::NotFound:
            return DOMException::create(NotFoundError, "Requested device not found");
        case WebSetSinkIdError::NotAuthorized:
            return DOMException::create(SecurityError,
                "No permission to use requested device");
        case WebSetSinkIdError::Aborted:
            return DOMException::create(
                AbortError, "The operation could not be performed and was aborted");
        case WebSetSinkIdError::NotSupported:
            return DOMException::create(NotSupportedError, "Operation not supported");
        default:
            ASSERT_NOT_REACHED();
            return DOMException::create(AbortError, "Invalid error code");
        }
    }

} // namespace

SetSinkIdCallbacks::SetSinkIdCallbacks(ScriptPromiseResolver* resolver,
    HTMLMediaElement& element,
    const String& sinkId)
=======
#include "config.h"
#include "modules/audio_output_devices/SetSinkIdCallbacks.h"

#include "bindings/core/v8/ScriptPromiseResolver.h"
#include "modules/audio_output_devices/HTMLMediaElementAudioOutputDevice.h"
#include "platform/Logging.h"
#include "public/platform/WebSetSinkIdError.h"

namespace blink {

SetSinkIdCallbacks::SetSinkIdCallbacks(PassRefPtrWillBeRawPtr<ScriptPromiseResolver> resolver, HTMLMediaElement& element, const String& sinkId)
>>>>>>> miniblink49
    : m_resolver(resolver)
    , m_element(element)
    , m_sinkId(sinkId)
{
    ASSERT(m_resolver);
<<<<<<< HEAD
}

SetSinkIdCallbacks::~SetSinkIdCallbacks() { }

void SetSinkIdCallbacks::onSuccess()
{
    if (!m_resolver->getExecutionContext() || m_resolver->getExecutionContext()->isContextDestroyed())
=======
    WTF_LOG(Media, __FUNCTION__);
}

SetSinkIdCallbacks::~SetSinkIdCallbacks()
{
    WTF_LOG(Media, __FUNCTION__);
}

void SetSinkIdCallbacks::onSuccess()
{
    if (!m_resolver->executionContext() || m_resolver->executionContext()->activeDOMObjectsAreStopped())
>>>>>>> miniblink49
        return;

    HTMLMediaElementAudioOutputDevice& aodElement = HTMLMediaElementAudioOutputDevice::from(*m_element);
    aodElement.setSinkId(m_sinkId);
    m_resolver->resolve();
}

<<<<<<< HEAD
void SetSinkIdCallbacks::onError(WebSetSinkIdError error)
{
    if (!m_resolver->getExecutionContext() || m_resolver->getExecutionContext()->isContextDestroyed())
        return;

    m_resolver->reject(ToException(error));
=======
void SetSinkIdCallbacks::onError(WebSetSinkIdError* rawError)
{
    ASSERT(rawError);
    OwnPtr<WebSetSinkIdError> error = adoptPtr(rawError);
    if (!m_resolver->executionContext() || m_resolver->executionContext()->activeDOMObjectsAreStopped())
        return;

    switch (error->errorType) {
    case WebSetSinkIdError::ErrorTypeNotFound:
        m_resolver->reject(DOMException::create(NotFoundError, error->message));
        break;
    case WebSetSinkIdError::ErrorTypeSecurity:
        m_resolver->reject(DOMException::create(SecurityError, error->message));
        break;
    case WebSetSinkIdError::ErrorTypeNotSupported:
        m_resolver->reject(DOMException::create(NotSupportedError, error->message));
        break;
    case WebSetSinkIdError::ErrorTypeAbort:
        m_resolver->reject(DOMException::create(AbortError, error->message));
        break;
    default:
        ASSERT_NOT_REACHED();
    }
>>>>>>> miniblink49
}

} // namespace blink
