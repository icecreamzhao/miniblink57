// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "NavigatorContentUtilsClientMock.h"

#include "modules/navigatorcontentutils/NavigatorContentUtilsClient.h"
#include "platform/weborigin/KURL.h"
#include "wtf/text/StringHash.h"

namespace blink {

<<<<<<< HEAD
void NavigatorContentUtilsClientMock::registerProtocolHandler(
    const String& scheme,
    const KURL& url,
    const String& title)
=======
void NavigatorContentUtilsClientMock::registerProtocolHandler(const String& scheme,
    const KURL& url, const String& title)
>>>>>>> miniblink49
{
    ProtocolInfo info;
    info.scheme = scheme;
    info.url = url;
    info.title = title;

    m_protocolMap.set(scheme, info);
}

<<<<<<< HEAD
NavigatorContentUtilsClient::CustomHandlersState
NavigatorContentUtilsClientMock::isProtocolHandlerRegistered(
    const String& scheme,
    const KURL& url)
{
    // "declined" state is checked by
    // NavigatorContentUtils::isProtocolHandlerRegistered() before calling this
    // function.
=======
NavigatorContentUtilsClient::CustomHandlersState NavigatorContentUtilsClientMock::isProtocolHandlerRegistered(const String& scheme,
    const KURL& url)
{
    // "declined" state is checked by NavigatorContentUtils::isProtocolHandlerRegistered() before calling this function.
>>>>>>> miniblink49
    if (m_protocolMap.contains(scheme))
        return NavigatorContentUtilsClient::CustomHandlersRegistered;

    return NavigatorContentUtilsClient::CustomHandlersNew;
}

<<<<<<< HEAD
void NavigatorContentUtilsClientMock::unregisterProtocolHandler(
    const String& scheme,
=======
void NavigatorContentUtilsClientMock::unregisterProtocolHandler(const String& scheme,
>>>>>>> miniblink49
    const KURL& url)
{
    m_protocolMap.remove(scheme);
}

} // namespace blink
