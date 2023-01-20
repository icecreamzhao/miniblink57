// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/credentialmanager/NavigatorCredentials.h"

#include "core/dom/Document.h"
#include "core/frame/LocalDOMWindow.h"
#include "core/frame/LocalFrame.h"
#include "core/frame/Navigator.h"
#include "modules/credentialmanager/CredentialsContainer.h"

namespace blink {

NavigatorCredentials::NavigatorCredentials(Navigator& navigator)
<<<<<<< HEAD
    : Supplement<Navigator>(navigator)
=======
    : DOMWindowProperty(navigator.frame())
{
}

NavigatorCredentials::~NavigatorCredentials()
>>>>>>> miniblink49
{
}

NavigatorCredentials& NavigatorCredentials::from(Navigator& navigator)
{
<<<<<<< HEAD
    NavigatorCredentials* supplement = static_cast<NavigatorCredentials*>(
        Supplement<Navigator>::from(navigator, supplementName()));
=======
    NavigatorCredentials* supplement = static_cast<NavigatorCredentials*>(HeapSupplement<Navigator>::from(navigator, supplementName()));
>>>>>>> miniblink49
    if (!supplement) {
        supplement = new NavigatorCredentials(navigator);
        provideTo(navigator, supplementName(), supplement);
    }
    return *supplement;
}

const char* NavigatorCredentials::supplementName()
{
    return "NavigatorCredentials";
}

CredentialsContainer* NavigatorCredentials::credentials(Navigator& navigator)
{
    return NavigatorCredentials::from(navigator).credentials();
}

CredentialsContainer* NavigatorCredentials::credentials()
{
<<<<<<< HEAD
    if (!m_credentialsContainer)
=======
    if (!m_credentialsContainer && frame())
>>>>>>> miniblink49
        m_credentialsContainer = CredentialsContainer::create();
    return m_credentialsContainer.get();
}

DEFINE_TRACE(NavigatorCredentials)
{
    visitor->trace(m_credentialsContainer);
<<<<<<< HEAD
    Supplement<Navigator>::trace(visitor);
=======
    HeapSupplement<Navigator>::trace(visitor);
    DOMWindowProperty::trace(visitor);
>>>>>>> miniblink49
}

} // namespace blink
