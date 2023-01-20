// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

<<<<<<< HEAD
=======
#include "config.h"
>>>>>>> miniblink49
#include "web/NavigatorContentUtilsClientImpl.h"

#include "public/web/WebFrameClient.h"
#include "web/WebLocalFrameImpl.h"

namespace blink {

<<<<<<< HEAD
NavigatorContentUtilsClientImpl* NavigatorContentUtilsClientImpl::create(
    WebLocalFrameImpl* webFrame)
{
    return new NavigatorContentUtilsClientImpl(webFrame);
}

NavigatorContentUtilsClientImpl::NavigatorContentUtilsClientImpl(
    WebLocalFrameImpl* webFrame)
=======
PassOwnPtr<NavigatorContentUtilsClientImpl> NavigatorContentUtilsClientImpl::create(WebLocalFrameImpl* webFrame)
{
    return adoptPtr(new NavigatorContentUtilsClientImpl(webFrame));
}

NavigatorContentUtilsClientImpl::NavigatorContentUtilsClientImpl(WebLocalFrameImpl* webFrame)
>>>>>>> miniblink49
    : m_webFrame(webFrame)
{
}

<<<<<<< HEAD
DEFINE_TRACE(NavigatorContentUtilsClientImpl)
{
    visitor->trace(m_webFrame);
    NavigatorContentUtilsClient::trace(visitor);
}

void NavigatorContentUtilsClientImpl::registerProtocolHandler(
    const String& scheme,
    const KURL& url,
    const String& title)
=======
void NavigatorContentUtilsClientImpl::registerProtocolHandler(const String& scheme, const KURL& url, const String& title)
>>>>>>> miniblink49
{
    m_webFrame->client()->registerProtocolHandler(scheme, url, title);
}

<<<<<<< HEAD
NavigatorContentUtilsClient::CustomHandlersState
NavigatorContentUtilsClientImpl::isProtocolHandlerRegistered(
    const String& scheme,
    const KURL& url)
{
    return static_cast<NavigatorContentUtilsClient::CustomHandlersState>(
        m_webFrame->client()->isProtocolHandlerRegistered(scheme, url));
}

void NavigatorContentUtilsClientImpl::unregisterProtocolHandler(
    const String& scheme,
    const KURL& url)
=======
NavigatorContentUtilsClient::CustomHandlersState NavigatorContentUtilsClientImpl::isProtocolHandlerRegistered(const String& scheme, const KURL& url)
{
    return static_cast<NavigatorContentUtilsClient::CustomHandlersState>(m_webFrame->client()->isProtocolHandlerRegistered(scheme, url));
}

void NavigatorContentUtilsClientImpl::unregisterProtocolHandler(const String& scheme, const KURL& url)
>>>>>>> miniblink49
{
    m_webFrame->client()->unregisterProtocolHandler(scheme, url);
}

} // namespace blink
<<<<<<< HEAD
=======

>>>>>>> miniblink49
