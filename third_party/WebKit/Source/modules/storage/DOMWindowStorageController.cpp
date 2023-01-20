// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/storage/DOMWindowStorageController.h"

#include "core/dom/Document.h"
#include "core/events/Event.h"
<<<<<<< HEAD
=======
#include "core/frame/LocalDOMWindow.h"
>>>>>>> miniblink49
#include "core/page/Page.h"
#include "modules/storage/DOMWindowStorage.h"

namespace blink {

DOMWindowStorageController::DOMWindowStorageController(Document& document)
<<<<<<< HEAD
    : Supplement<Document>(document)
{
    document.domWindow()->registerEventListenerObserver(this);
}

DEFINE_TRACE(DOMWindowStorageController)
{
    Supplement<Document>::trace(visitor);
=======
    : DOMWindowLifecycleObserver(document.domWindow())
    , m_document(document)
{
}

DEFINE_EMPTY_DESTRUCTOR_WILL_BE_REMOVED(DOMWindowStorageController);

DEFINE_TRACE(DOMWindowStorageController)
{
    visitor->trace(m_document);
    WillBeHeapSupplement<Document>::trace(visitor);
    DOMWindowLifecycleObserver::trace(visitor);
>>>>>>> miniblink49
}

// static
const char* DOMWindowStorageController::supplementName()
{
    return "DOMWindowStorageController";
}

// static
<<<<<<< HEAD
DOMWindowStorageController& DOMWindowStorageController::from(
    Document& document)
{
    DOMWindowStorageController* controller = static_cast<DOMWindowStorageController*>(
        Supplement<Document>::from(document, supplementName()));
    if (!controller) {
        controller = new DOMWindowStorageController(document);
        Supplement<Document>::provideTo(document, supplementName(), controller);
=======
DOMWindowStorageController& DOMWindowStorageController::from(Document& document)
{
    DOMWindowStorageController* controller = static_cast<DOMWindowStorageController*>(WillBeHeapSupplement<Document>::from(document, supplementName()));
    if (!controller) {
        controller = new DOMWindowStorageController(document);
        WillBeHeapSupplement<Document>::provideTo(document, supplementName(), adoptPtrWillBeNoop(controller));
>>>>>>> miniblink49
    }
    return *controller;
}

<<<<<<< HEAD
void DOMWindowStorageController::didAddEventListener(
    LocalDOMWindow* window,
    const AtomicString& eventType)
{
    if (eventType == EventTypeNames::storage) {
        // Creating these blink::Storage objects informs the system that we'd like
        // to receive notifications about storage events that might be triggered in
        // other processes. Rather than subscribe to these notifications explicitly,
        // we subscribe to them implicitly to simplify the work done by the system.
        DOMWindowStorage::from(*window).localStorage(IGNORE_EXCEPTION_FOR_TESTING);
        DOMWindowStorage::from(*window).sessionStorage(
            IGNORE_EXCEPTION_FOR_TESTING);
=======
void DOMWindowStorageController::didAddEventListener(LocalDOMWindow* window, const AtomicString& eventType)
{
    if (eventType == EventTypeNames::storage) {
        // Creating these blink::Storage objects informs the system that we'd like to receive
        // notifications about storage events that might be triggered in other processes. Rather
        // than subscribe to these notifications explicitly, we subscribe to them implicitly to
        // simplify the work done by the system.
        DOMWindowStorage::from(*window).localStorage(IGNORE_EXCEPTION);
        DOMWindowStorage::from(*window).sessionStorage(IGNORE_EXCEPTION);
>>>>>>> miniblink49
    }
}

} // namespace blink
