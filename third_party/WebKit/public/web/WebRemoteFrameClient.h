// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef WebRemoteFrameClient_h
#define WebRemoteFrameClient_h

<<<<<<< HEAD
#include "public/platform/WebFocusType.h"
#include "public/platform/WebSecurityOrigin.h"
#include "public/web/WebDOMMessageEvent.h"
#include "public/web/WebFrame.h"

namespace blink {
class WebInputEvent;
enum class WebClientRedirectPolicy;
enum class WebFrameLoadType;
=======
#include "public/platform/WebSecurityOrigin.h"
#include "public/web/WebDOMMessageEvent.h"

namespace blink {
class WebInputEvent;
class WebLocalFrame;
class WebRemoteFrame;
>>>>>>> miniblink49
struct WebRect;

class WebRemoteFrameClient {
public:
    // Specifies the reason for the detachment.
<<<<<<< HEAD
    enum class DetachType { Remove,
        Swap };
=======
    enum class DetachType { Remove, Swap };
>>>>>>> miniblink49

    // Notify the embedder that it should remove this frame from the frame tree
    // and release any resources associated with it.
    virtual void frameDetached(DetachType) { }

    // Notifies the embedder that a postMessage was issued to a remote frame.
<<<<<<< HEAD
    virtual void forwardPostMessage(WebLocalFrame* sourceFrame,
=======
    virtual void postMessageEvent(
        WebLocalFrame* sourceFrame,
>>>>>>> miniblink49
        WebRemoteFrame* targetFrame,
        WebSecurityOrigin targetOrigin,
        WebDOMMessageEvent) { }

<<<<<<< HEAD
    // A remote frame was asked to start a navigation.
    virtual void navigate(const WebURLRequest& request,
        bool shouldReplaceCurrentEntry) { }
    virtual void reload(WebFrameLoadType, WebClientRedirectPolicy) { }
=======
    // Send initial drawing parameters to a child frame that is being rendered
    // out of process.
    virtual void initializeChildFrame(
        const WebRect& frameRect,
        float scaleFactor) { }

    // A remote frame was asked to start a navigation.
    virtual void navigate(const WebURLRequest& request, bool shouldReplaceCurrentEntry) { }
    virtual void reload(bool ignoreCache, bool isClientRedirect) { }
>>>>>>> miniblink49

    // FIXME: Remove this method once we have input routing in the browser
    // process. See http://crbug.com/339659.
    virtual void forwardInputEvent(const WebInputEvent*) { }
<<<<<<< HEAD

    virtual void frameRectsChanged(const WebRect&) { }

    virtual void updateRemoteViewportIntersection(
        const WebRect& viewportIntersection) { }

    virtual void visibilityChanged(bool visible) { }

    // This frame updated its opener to another frame.
    virtual void didChangeOpener(WebFrame* opener) { }

    // Continue sequential focus navigation in this frame.  This is called when
    // the |source| frame is searching for the next focusable element (e.g., in
    // response to <tab>) and encounters a remote frame.
    virtual void advanceFocus(WebFocusType type, WebLocalFrame* source) { }

    // This frame was focused by another frame.
    virtual void frameFocused() { }
=======
>>>>>>> miniblink49
};

} // namespace blink

#endif // WebRemoteFrameClient_h
