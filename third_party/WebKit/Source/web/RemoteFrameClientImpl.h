// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef RemoteFrameClientImpl_h
#define RemoteFrameClientImpl_h

#include "core/frame/RemoteFrameClient.h"

namespace blink {
class WebRemoteFrameImpl;

class RemoteFrameClientImpl final : public RemoteFrameClient {
public:
<<<<<<< HEAD
    static RemoteFrameClientImpl* create(WebRemoteFrameImpl*);

    DECLARE_VIRTUAL_TRACE();
=======
    explicit RemoteFrameClientImpl(WebRemoteFrameImpl*);
>>>>>>> miniblink49

    // FrameClient overrides:
    bool inShadowTree() const override;
    void willBeDetached() override;
    void detached(FrameDetachType) override;
    Frame* opener() const override;
    void setOpener(Frame*) override;
    Frame* parent() const override;
    Frame* top() const override;
<<<<<<< HEAD
    Frame* nextSibling() const override;
    Frame* firstChild() const override;
    void frameFocused() const override;

    // RemoteFrameClient overrides:
    void navigate(const ResourceRequest&,
        bool shouldReplaceCurrentEntry) override;
    void reload(FrameLoadType, ClientRedirectPolicy) override;
    unsigned backForwardLength() override;
    void forwardPostMessage(MessageEvent*,
        PassRefPtr<SecurityOrigin> target,
        LocalFrame* source) const override;
    void forwardInputEvent(Event*) override;
    void frameRectsChanged(const IntRect& frameRect) override;
    void updateRemoteViewportIntersection(const IntRect&) override;
    void advanceFocus(WebFocusType, LocalFrame*) override;
    void visibilityChanged(bool visible) override;
=======
    Frame* previousSibling() const override;
    Frame* nextSibling() const override;
    Frame* firstChild() const override;
    Frame* lastChild() const override;
    bool willCheckAndDispatchMessageEvent(SecurityOrigin*, MessageEvent*, LocalFrame*) const override;

    // RemoteFrameClient overrides:
    void navigate(const ResourceRequest&, bool shouldReplaceCurrentEntry) override;
    void reload(FrameLoadType, ClientRedirectPolicy) override;
    unsigned backForwardLength() override;
    void forwardInputEvent(Event*) override;
>>>>>>> miniblink49

    WebRemoteFrameImpl* webFrame() const { return m_webFrame; }

private:
<<<<<<< HEAD
    explicit RemoteFrameClientImpl(WebRemoteFrameImpl*);

    Member<WebRemoteFrameImpl> m_webFrame;
=======
    WebRemoteFrameImpl* m_webFrame;
>>>>>>> miniblink49
};

} // namespace blink

#endif // RemoteFrameClientImpl_h
