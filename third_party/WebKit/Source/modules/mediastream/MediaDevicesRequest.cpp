/*
 * Copyright (C) 2014 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY GOOGLE INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL GOOGLE INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

<<<<<<< HEAD
=======
#include "config.h"

>>>>>>> miniblink49
#include "modules/mediastream/MediaDevicesRequest.h"

#include "bindings/core/v8/ScriptPromiseResolver.h"
#include "bindings/core/v8/ScriptState.h"
#include "core/dom/DOMException.h"
#include "core/dom/Document.h"
<<<<<<< HEAD
=======
#include "core/dom/ExceptionCode.h"
>>>>>>> miniblink49
#include "modules/mediastream/UserMediaController.h"

namespace blink {

<<<<<<< HEAD
MediaDevicesRequest* MediaDevicesRequest::create(
    ScriptState* state,
    UserMediaController* controller)
{
    return new MediaDevicesRequest(state, controller);
}

MediaDevicesRequest::MediaDevicesRequest(ScriptState* state,
    UserMediaController* controller)
    : ContextLifecycleObserver(state->getExecutionContext())
=======
MediaDevicesRequest* MediaDevicesRequest::create(ScriptState* state, UserMediaController* controller)
{
    MediaDevicesRequest* request = new MediaDevicesRequest(state, controller);
    request->suspendIfNeeded();
    return request;
}

MediaDevicesRequest::MediaDevicesRequest(ScriptState* state, UserMediaController* controller)
    : ActiveDOMObject(state->executionContext())
>>>>>>> miniblink49
    , m_controller(controller)
    , m_resolver(ScriptPromiseResolver::create(state))
{
}

<<<<<<< HEAD
MediaDevicesRequest::~MediaDevicesRequest() { }

Document* MediaDevicesRequest::ownerDocument()
{
    if (ExecutionContext* context = getExecutionContext()) {
=======
MediaDevicesRequest::~MediaDevicesRequest()
{
}

Document* MediaDevicesRequest::ownerDocument()
{
    if (ExecutionContext* context = executionContext()) {
>>>>>>> miniblink49
        return toDocument(context);
    }

    return 0;
}

ScriptPromise MediaDevicesRequest::start()
{
<<<<<<< HEAD
    DCHECK(m_controller);
=======
    ASSERT(m_controller);
>>>>>>> miniblink49
    m_resolver->keepAliveWhilePending();
    m_controller->requestMediaDevices(this);
    return m_resolver->promise();
}

void MediaDevicesRequest::succeed(const MediaDeviceInfoVector& mediaDevices)
{
<<<<<<< HEAD
    if (!getExecutionContext() || !m_resolver)
=======
    if (!executionContext() || !m_resolver)
>>>>>>> miniblink49
        return;

    m_resolver->resolve(mediaDevices);
}

<<<<<<< HEAD
void MediaDevicesRequest::contextDestroyed(ExecutionContext*)
=======
void MediaDevicesRequest::stop()
>>>>>>> miniblink49
{
    m_controller.clear();
    m_resolver.clear();
}

DEFINE_TRACE(MediaDevicesRequest)
{
    visitor->trace(m_controller);
    visitor->trace(m_resolver);
<<<<<<< HEAD
    ContextLifecycleObserver::trace(visitor);
=======
    ActiveDOMObject::trace(visitor);
>>>>>>> miniblink49
}

} // namespace blink
