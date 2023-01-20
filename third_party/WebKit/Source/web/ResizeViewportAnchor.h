// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef ResizeViewportAnchor_h
#define ResizeViewportAnchor_h

<<<<<<< HEAD
#include "core/page/Page.h"
#include "platform/heap/Handle.h"
#include "platform/scroll/ScrollTypes.h"
=======
#include "platform/geometry/DoublePoint.h"
#include "platform/heap/Handle.h"
#include "web/ViewportAnchor.h"
>>>>>>> miniblink49

namespace blink {

class FrameView;
<<<<<<< HEAD

// This class scrolls the viewports to compensate for bounds clamping caused by
// viewport size changes.
//
// It is needed when the layout viewport grows (causing its own scroll position
// to be clamped) and also when it shrinks (causing the visual viewport's scroll
// position to be clamped).
class ResizeViewportAnchor final
    : public GarbageCollected<ResizeViewportAnchor> {
    WTF_MAKE_NONCOPYABLE(ResizeViewportAnchor);

public:
    ResizeViewportAnchor(Page& page)
        : m_page(page)
        , m_scopeCount(0)
    {
    }

    class ResizeScope {
        STACK_ALLOCATED();

    public:
        explicit ResizeScope(ResizeViewportAnchor& anchor)
            : m_anchor(anchor)
        {
            m_anchor->beginScope();
        }
        ~ResizeScope() { m_anchor->endScope(); }

    private:
        Member<ResizeViewportAnchor> m_anchor;
    };

    void resizeFrameView(IntSize);

    DEFINE_INLINE_TRACE() { visitor->trace(m_page); }

private:
    void beginScope() { m_scopeCount++; }
    void endScope();
    FrameView* rootFrameView();

    // The amount of resize-induced clamping drift accumulated during the
    // ResizeScope.  Note that this should NOT include other kinds of scrolling
    // that may occur during layout, such as from ScrollAnchor.
    ScrollOffset m_drift;
    Member<Page> m_page;
    int m_scopeCount;
=======
class PinchViewport;

// The resize anchor saves the current scroll offset of the visual viewport and
// restores to that scroll offset so that document location appears exactly
// unchanged to the user.
class ResizeViewportAnchor : public ViewportAnchor {
    STACK_ALLOCATED();
public:
    ResizeViewportAnchor(FrameView& rootFrameView, PinchViewport&);
    ~ResizeViewportAnchor();

private:
    // Inner viewport origin in the reference frame of the root document, in CSS
    // pixels.
    DoublePoint m_pinchViewportInDocument;
>>>>>>> miniblink49
};

} // namespace blink

#endif // ResizeViewportAnchor_h
