// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef NavigatorContentUtilsClientImpl_h
#define NavigatorContentUtilsClientImpl_h

#include "modules/navigatorcontentutils/NavigatorContentUtilsClient.h"
<<<<<<< HEAD
#include "platform/heap/Handle.h"
=======
>>>>>>> miniblink49
#include "platform/weborigin/KURL.h"

namespace blink {

class WebLocalFrameImpl;

<<<<<<< HEAD
class NavigatorContentUtilsClientImpl final
    : public NavigatorContentUtilsClient {
public:
    static NavigatorContentUtilsClientImpl* create(WebLocalFrameImpl*);
    ~NavigatorContentUtilsClientImpl() override { }

    void registerProtocolHandler(const String& scheme,
        const KURL&,
        const String& title) override;
    CustomHandlersState isProtocolHandlerRegistered(const String& scheme,
        const KURL&) override;
    void unregisterProtocolHandler(const String& scheme, const KURL&) override;

    DECLARE_VIRTUAL_TRACE();

private:
    explicit NavigatorContentUtilsClientImpl(WebLocalFrameImpl*);

    Member<WebLocalFrameImpl> m_webFrame;
=======
class NavigatorContentUtilsClientImpl final : public NavigatorContentUtilsClient {
public:
    static PassOwnPtr<NavigatorContentUtilsClientImpl> create(WebLocalFrameImpl*);
    ~NavigatorContentUtilsClientImpl() override { }

    void registerProtocolHandler(const String& scheme, const KURL&, const String& title) override;
    CustomHandlersState isProtocolHandlerRegistered(const String& scheme, const KURL&) override;
    void unregisterProtocolHandler(const String& scheme, const KURL&) override;

private:
    explicit NavigatorContentUtilsClientImpl(WebLocalFrameImpl*);

    WebLocalFrameImpl* m_webFrame;
>>>>>>> miniblink49
};

} // namespace blink

#endif // NavigatorContentUtilsClientImpl_h
