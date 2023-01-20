// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/storage/DOMWindowStorage.h"

#include "core/dom/Document.h"
#include "core/frame/FrameHost.h"
#include "core/frame/LocalDOMWindow.h"
#include "core/frame/LocalFrame.h"
#include "core/frame/Settings.h"
#include "core/page/Page.h"
#include "modules/storage/Storage.h"
#include "modules/storage/StorageNamespace.h"
#include "modules/storage/StorageNamespaceController.h"
#include "wtf/PassRefPtr.h"

namespace blink {

DOMWindowStorage::DOMWindowStorage(LocalDOMWindow& window)
<<<<<<< HEAD
    : Supplement<LocalDOMWindow>(window)
{
}

DEFINE_TRACE(DOMWindowStorage)
{
    visitor->trace(m_sessionStorage);
    visitor->trace(m_localStorage);
    Supplement<LocalDOMWindow>::trace(visitor);
=======
    : DOMWindowProperty(window.frame())
    , m_window(&window)
{
}

DEFINE_EMPTY_DESTRUCTOR_WILL_BE_REMOVED(DOMWindowStorage);

DEFINE_TRACE(DOMWindowStorage)
{
    visitor->trace(m_window);
    visitor->trace(m_sessionStorage);
    visitor->trace(m_localStorage);
    WillBeHeapSupplement<LocalDOMWindow>::trace(visitor);
    DOMWindowProperty::trace(visitor);
>>>>>>> miniblink49
}

// static
const char* DOMWindowStorage::supplementName()
{
    return "DOMWindowStorage";
}

// static
DOMWindowStorage& DOMWindowStorage::from(LocalDOMWindow& window)
{
<<<<<<< HEAD
    DOMWindowStorage* supplement = static_cast<DOMWindowStorage*>(
        Supplement<LocalDOMWindow>::from(window, supplementName()));
    if (!supplement) {
        supplement = new DOMWindowStorage(window);
        provideTo(window, supplementName(), supplement);
=======
    DOMWindowStorage* supplement = static_cast<DOMWindowStorage*>(WillBeHeapSupplement<LocalDOMWindow>::from(window, supplementName()));
    if (!supplement) {
        supplement = new DOMWindowStorage(window);
        provideTo(window, supplementName(), adoptPtrWillBeNoop(supplement));
>>>>>>> miniblink49
    }
    return *supplement;
}

// static
<<<<<<< HEAD
Storage* DOMWindowStorage::sessionStorage(DOMWindow& window,
    ExceptionState& exceptionState)
=======
Storage* DOMWindowStorage::sessionStorage(DOMWindow& window, ExceptionState& exceptionState)
>>>>>>> miniblink49
{
    return from(toLocalDOMWindow(window)).sessionStorage(exceptionState);
}

// static
<<<<<<< HEAD
Storage* DOMWindowStorage::localStorage(DOMWindow& window,
    ExceptionState& exceptionState)
=======
Storage* DOMWindowStorage::localStorage(DOMWindow& window, ExceptionState& exceptionState)
>>>>>>> miniblink49
{
    return from(toLocalDOMWindow(window)).localStorage(exceptionState);
}

<<<<<<< HEAD
Storage* DOMWindowStorage::sessionStorage(
    ExceptionState& exceptionState) const
{
    if (!supplementable()->frame())
        return nullptr;

    Document* document = supplementable()->frame()->document();
    DCHECK(document);
    String accessDeniedMessage = "Access is denied for this document.";
    if (!document->getSecurityOrigin()->canAccessLocalStorage()) {
        if (document->isSandboxed(SandboxOrigin))
            exceptionState.throwSecurityError(
                "The document is sandboxed and lacks the 'allow-same-origin' flag.");
        else if (document->url().protocolIs("data"))
            exceptionState.throwSecurityError(
                "Storage is disabled inside 'data:' URLs.");
=======
Storage* DOMWindowStorage::sessionStorage(ExceptionState& exceptionState) const
{
    if (!m_window->isCurrentlyDisplayedInFrame())
        return nullptr;

    Document* document = m_window->document();
    if (!document)
        return nullptr;

    String accessDeniedMessage = "Access is denied for this document.";
    if (!document->securityOrigin()->canAccessLocalStorage()) {
        if (document->isSandboxed(SandboxOrigin))
            exceptionState.throwSecurityError("The document is sandboxed and lacks the 'allow-same-origin' flag.");
        else if (document->url().protocolIs("data"))
            exceptionState.throwSecurityError("Storage is disabled inside 'data:' URLs.");
>>>>>>> miniblink49
        else
            exceptionState.throwSecurityError(accessDeniedMessage);
        return nullptr;
    }

    if (m_sessionStorage) {
<<<<<<< HEAD
        if (!m_sessionStorage->area()->canAccessStorage(document->frame())) {
=======
        if (!m_sessionStorage->area()->canAccessStorage(m_window->frame())) {
>>>>>>> miniblink49
            exceptionState.throwSecurityError(accessDeniedMessage);
            return nullptr;
        }
        return m_sessionStorage;
    }

    Page* page = document->page();
    if (!page)
        return nullptr;

<<<<<<< HEAD
    StorageArea* storageArea = StorageNamespaceController::from(page)->sessionStorage()->storageArea(
        document->getSecurityOrigin());
    if (!storageArea->canAccessStorage(document->frame())) {
=======
    StorageArea* storageArea = StorageNamespaceController::from(page)->sessionStorage()->storageArea(document->securityOrigin());
    if (!storageArea->canAccessStorage(m_window->frame())) {
>>>>>>> miniblink49
        exceptionState.throwSecurityError(accessDeniedMessage);
        return nullptr;
    }

<<<<<<< HEAD
    m_sessionStorage = Storage::create(document->frame(), storageArea);
=======
    m_sessionStorage = Storage::create(m_window->frame(), storageArea);
>>>>>>> miniblink49
    return m_sessionStorage;
}

Storage* DOMWindowStorage::localStorage(ExceptionState& exceptionState) const
{
<<<<<<< HEAD
    if (!supplementable()->frame())
        return nullptr;

    Document* document = supplementable()->frame()->document();
    DCHECK(document);
    String accessDeniedMessage = "Access is denied for this document.";
    if (!document->getSecurityOrigin()->canAccessLocalStorage()) {
        if (document->isSandboxed(SandboxOrigin))
            exceptionState.throwSecurityError(
                "The document is sandboxed and lacks the 'allow-same-origin' flag.");
        else if (document->url().protocolIs("data"))
            exceptionState.throwSecurityError(
                "Storage is disabled inside 'data:' URLs.");
=======
    if (!m_window->isCurrentlyDisplayedInFrame())
        return nullptr;
    Document* document = m_window->document();
    if (!document)
        return nullptr;
    String accessDeniedMessage = "Access is denied for this document.";
    if (!document->securityOrigin()->canAccessLocalStorage()) {
        if (document->isSandboxed(SandboxOrigin))
            exceptionState.throwSecurityError("The document is sandboxed and lacks the 'allow-same-origin' flag.");
        else if (document->url().protocolIs("data"))
            exceptionState.throwSecurityError("Storage is disabled inside 'data:' URLs.");
>>>>>>> miniblink49
        else
            exceptionState.throwSecurityError(accessDeniedMessage);
        return nullptr;
    }
    if (m_localStorage) {
<<<<<<< HEAD
        if (!m_localStorage->area()->canAccessStorage(document->frame())) {
=======
        if (!m_localStorage->area()->canAccessStorage(m_window->frame())) {
>>>>>>> miniblink49
            exceptionState.throwSecurityError(accessDeniedMessage);
            return nullptr;
        }
        return m_localStorage;
    }
    // FIXME: Seems this check should be much higher?
    FrameHost* host = document->frameHost();
<<<<<<< HEAD
    if (!host || !host->settings().getLocalStorageEnabled())
        return nullptr;

#ifndef MINIBLINK_NO_PAGE_LOCALSTORAGE
    Page* page = document->page();
    if (!page)
        return nullptr;
    StorageArea* storageArea = StorageNamespaceController::from(page)->localStorage()->storageArea(document->getSecurityOrigin());
#else
    StorageArea* storageArea = StorageNamespace::localStorageArea(document->getSecurityOrigin());
    if (!storageArea->canAccessStorage(document->frame())) {
        exceptionState.throwSecurityError(accessDeniedMessage);
        return nullptr;
    }
#endif

    m_localStorage = Storage::create(document->frame(), storageArea);
=======
    if (!host || !host->settings().localStorageEnabled())
        return nullptr;

    StorageArea* storageArea = StorageNamespace::localStorageArea(document->securityOrigin());
    if (!storageArea->canAccessStorage(m_window->frame())) {
        exceptionState.throwSecurityError(accessDeniedMessage);
        return nullptr;
    }

    m_localStorage = Storage::create(m_window->frame(), storageArea);
>>>>>>> miniblink49
    return m_localStorage;
}

} // namespace blink
