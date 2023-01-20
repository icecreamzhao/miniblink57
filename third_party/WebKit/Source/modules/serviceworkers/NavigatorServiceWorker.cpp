// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/serviceworkers/NavigatorServiceWorker.h"

#include "core/dom/Document.h"
#include "core/frame/LocalDOMWindow.h"
#include "core/frame/LocalFrame.h"
#include "core/frame/Navigator.h"
#include "modules/serviceworkers/ServiceWorkerContainer.h"

namespace blink {

<<<<<<< HEAD
NavigatorServiceWorker::NavigatorServiceWorker(Navigator& navigator) { }
=======
NavigatorServiceWorker::NavigatorServiceWorker(Navigator& navigator)
    : DOMWindowProperty(navigator.frame())
{
}

NavigatorServiceWorker::~NavigatorServiceWorker()
{
}
>>>>>>> miniblink49

NavigatorServiceWorker* NavigatorServiceWorker::from(Document& document)
{
    if (!document.frame() || !document.frame()->domWindow())
        return nullptr;
    Navigator& navigator = *document.frame()->domWindow()->navigator();
    return &from(navigator);
}

NavigatorServiceWorker& NavigatorServiceWorker::from(Navigator& navigator)
{
    NavigatorServiceWorker* supplement = toNavigatorServiceWorker(navigator);
    if (!supplement) {
        supplement = new NavigatorServiceWorker(navigator);
        provideTo(navigator, supplementName(), supplement);
<<<<<<< HEAD
        if (navigator.frame() && navigator.frame()->securityContext()->getSecurityOrigin()->canAccessServiceWorkers()) {
            // Initialize ServiceWorkerContainer too.
            supplement->serviceWorker(navigator.frame(), ASSERT_NO_EXCEPTION);
=======
        if (navigator.frame() && navigator.frame()->securityContext()->securityOrigin()->canAccessServiceWorkers()) {
            // Initialize ServiceWorkerContainer too.
            supplement->serviceWorker(ASSERT_NO_EXCEPTION);
>>>>>>> miniblink49
        }
    }
    return *supplement;
}

<<<<<<< HEAD
NavigatorServiceWorker* NavigatorServiceWorker::toNavigatorServiceWorker(
    Navigator& navigator)
{
    return static_cast<NavigatorServiceWorker*>(
        Supplement<Navigator>::from(navigator, supplementName()));
=======
NavigatorServiceWorker* NavigatorServiceWorker::toNavigatorServiceWorker(Navigator& navigator)
{
    return static_cast<NavigatorServiceWorker*>(HeapSupplement<Navigator>::from(navigator, supplementName()));
>>>>>>> miniblink49
}

const char* NavigatorServiceWorker::supplementName()
{
    return "NavigatorServiceWorker";
}

<<<<<<< HEAD
ServiceWorkerContainer* NavigatorServiceWorker::serviceWorker(
    ExecutionContext* executionContext,
    Navigator& navigator,
    ExceptionState& exceptionState)
{
    DCHECK(!navigator.frame() || executionContext->getSecurityOrigin()->canAccessCheckSuborigins(navigator.frame()->securityContext()->getSecurityOrigin()));
    return NavigatorServiceWorker::from(navigator).serviceWorker(
        navigator.frame(), exceptionState);
}

ServiceWorkerContainer* NavigatorServiceWorker::serviceWorker(
    ExecutionContext* executionContext,
    Navigator& navigator,
    String& errorMessage)
{
    DCHECK(!navigator.frame() || executionContext->getSecurityOrigin()->canAccessCheckSuborigins(navigator.frame()->securityContext()->getSecurityOrigin()));
    return NavigatorServiceWorker::from(navigator).serviceWorker(
        navigator.frame(), errorMessage);
}

ServiceWorkerContainer* NavigatorServiceWorker::serviceWorker(
    LocalFrame* frame,
    ExceptionState& exceptionState)
{
    String errorMessage;
    ServiceWorkerContainer* result = serviceWorker(frame, errorMessage);
    if (!errorMessage.isEmpty()) {
        DCHECK(!result);
        exceptionState.throwSecurityError(errorMessage);
    }
    return result;
}

ServiceWorkerContainer* NavigatorServiceWorker::serviceWorker(
    LocalFrame* frame,
    String& errorMessage)
{
    if (frame && !frame->securityContext()->getSecurityOrigin()->canAccessServiceWorkers()) {
        if (frame->securityContext()->isSandboxed(SandboxOrigin)) {
            errorMessage = "Service worker is disabled because the context is sandboxed and "
                           "lacks the 'allow-same-origin' flag.";
        } else if (frame->securityContext()->getSecurityOrigin()->hasSuborigin()) {
            errorMessage = "Service worker is disabled because the context is in a suborigin.";
        } else {
            errorMessage = "Access to service workers is denied in this document origin.";
        }
        return nullptr;
    }
    if (!m_serviceWorker && frame) {
        // We need to create a new ServiceWorkerContainer when the frame
        // navigates to a new document. In practice, this happens only when the
        // frame navigates from the initial empty page to a new same-origin page.
        DCHECK(frame->domWindow());
        m_serviceWorker = ServiceWorkerContainer::create(
            frame->domWindow()->getExecutionContext(), this);
=======
ServiceWorkerContainer* NavigatorServiceWorker::serviceWorker(Navigator& navigator, ExceptionState& exceptionState)
{
    return NavigatorServiceWorker::from(navigator).serviceWorker(exceptionState);
}

ServiceWorkerContainer* NavigatorServiceWorker::serviceWorker(ExceptionState& exceptionState)
{
    if (frame() && !frame()->securityContext()->securityOrigin()->canAccessServiceWorkers()) {
        if (frame()->securityContext()->isSandboxed(SandboxOrigin))
            exceptionState.throwSecurityError("Service worker is disabled because the context is sandboxed and lacks the 'allow-same-origin' flag.");
        else
            exceptionState.throwSecurityError("Access to service workers is denied in this document origin.");
        return nullptr;
    }
    if (!m_serviceWorker && frame()) {
        ASSERT(frame()->domWindow());
        m_serviceWorker = ServiceWorkerContainer::create(frame()->domWindow()->executionContext());
>>>>>>> miniblink49
    }
    return m_serviceWorker.get();
}

<<<<<<< HEAD
void NavigatorServiceWorker::clearServiceWorker()
{
    m_serviceWorker = nullptr;
=======
void NavigatorServiceWorker::willDetachGlobalObjectFromFrame()
{
    if (m_serviceWorker) {
        m_serviceWorker->willBeDetachedFromFrame();
        m_serviceWorker = nullptr;
    }
>>>>>>> miniblink49
}

DEFINE_TRACE(NavigatorServiceWorker)
{
    visitor->trace(m_serviceWorker);
<<<<<<< HEAD
    Supplement<Navigator>::trace(visitor);
=======
    HeapSupplement<Navigator>::trace(visitor);
    DOMWindowProperty::trace(visitor);
>>>>>>> miniblink49
}

} // namespace blink
