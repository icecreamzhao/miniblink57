// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "modules/netinfo/NavigatorNetworkInformation.h"

#include "core/frame/LocalDOMWindow.h"
#include "core/frame/LocalFrame.h"
#include "core/frame/Navigator.h"
#include "modules/netinfo/NetworkInformation.h"

namespace blink {

NavigatorNetworkInformation::NavigatorNetworkInformation(Navigator& navigator)
<<<<<<< HEAD
    : ContextClient(navigator.frame())
{
}

NavigatorNetworkInformation& NavigatorNetworkInformation::from(
    Navigator& navigator)
=======
    : DOMWindowProperty(navigator.frame())
{
}

NavigatorNetworkInformation::~NavigatorNetworkInformation()
{
}

NavigatorNetworkInformation& NavigatorNetworkInformation::from(Navigator& navigator)
>>>>>>> miniblink49
{
    NavigatorNetworkInformation* supplement = toNavigatorNetworkInformation(navigator);
    if (!supplement) {
        supplement = new NavigatorNetworkInformation(navigator);
        provideTo(navigator, supplementName(), supplement);
    }
    return *supplement;
}

<<<<<<< HEAD
NavigatorNetworkInformation*
NavigatorNetworkInformation::toNavigatorNetworkInformation(
    Navigator& navigator)
{
    return static_cast<NavigatorNetworkInformation*>(
        Supplement<Navigator>::from(navigator, supplementName()));
=======
NavigatorNetworkInformation* NavigatorNetworkInformation::toNavigatorNetworkInformation(Navigator& navigator)
{
    return static_cast<NavigatorNetworkInformation*>(HeapSupplement<Navigator>::from(navigator, supplementName()));
>>>>>>> miniblink49
}

const char* NavigatorNetworkInformation::supplementName()
{
    return "NavigatorNetworkInformation";
}

<<<<<<< HEAD
NetworkInformation* NavigatorNetworkInformation::connection(
    Navigator& navigator)
=======
NetworkInformation* NavigatorNetworkInformation::connection(Navigator& navigator)
>>>>>>> miniblink49
{
    return NavigatorNetworkInformation::from(navigator).connection();
}

NetworkInformation* NavigatorNetworkInformation::connection()
{
    if (!m_connection && frame()) {
        ASSERT(frame()->domWindow());
<<<<<<< HEAD
        m_connection = NetworkInformation::create(frame()->domWindow()->getExecutionContext());
=======
        m_connection = NetworkInformation::create(frame()->domWindow()->executionContext());
>>>>>>> miniblink49
    }
    return m_connection.get();
}

DEFINE_TRACE(NavigatorNetworkInformation)
{
    visitor->trace(m_connection);
<<<<<<< HEAD
    Supplement<Navigator>::trace(visitor);
    ContextClient::trace(visitor);
=======
    HeapSupplement<Navigator>::trace(visitor);
    DOMWindowProperty::trace(visitor);
>>>>>>> miniblink49
}

} // namespace blink
