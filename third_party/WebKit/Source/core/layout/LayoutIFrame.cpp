/*
 * Copyright (C) 2010 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "core/layout/LayoutIFrame.h"

#include "core/layout/LayoutAnalyzer.h"
#ifdef TENCENT_FITSCREEN_FRAEME_FLATTEN
#include "core/frame/LocalFrame.h"
#include "core/frame/Settings.h"
#include "core/html/HTMLIFrameElement.h"
#include "core/layout/LayoutFrameBase.h"
#endif

namespace blink {

LayoutIFrame::LayoutIFrame(Element* element)
    : LayoutPart(element)
{
}

bool LayoutIFrame::shouldComputeSizeAsReplaced() const
{
    return true;
}

bool LayoutIFrame::isInlineBlockOrInlineTable() const
{
    return isInline();
}

PaintLayerType LayoutIFrame::layerTypeRequired() const
{
    if (style()->resize() != RESIZE_NONE)
        return NormalPaintLayer;
    return LayoutPart::layerTypeRequired();
}

void LayoutIFrame::layout()
{
    ASSERT(needsLayout());
    LayoutAnalyzer::Scope analyzer(*this);

#if TENCENT_FITSCREEN
    if (document().needFitScreenLayout()) {
        LayoutSize size = intrinsicSize();
        size.setHeight(LayoutUnit(1));
        setIntrinsicSize(size);
    }
#endif

    updateLogicalWidth();
    // No kids to layout as a replaced element.
    updateLogicalHeight();

#ifdef TENCENT_FITSCREEN_FRAEME_FLATTEN
    if (flattenFrame() && style())
        layoutWithFlattening(style()->width().isFixed(), style()->height().isFixed());
#endif

    m_overflow.reset();
    addVisualEffectOverflow();
    updateLayerTransformAfterLayout();

    clearNeedsLayout();
}

#ifdef TENCENT_FITSCREEN_FRAEME_FLATTEN
bool LayoutIFrame::flattenFrame() const
{
    if (!node() || !node()->hasTagName(HTMLNames::iframeTag))
        return false;

    HTMLIFrameElement* element = reinterpret_cast<HTMLIFrameElement*>(node());
    if (!element)
        return false;

    LocalFrame* frame = element->document().frame();
    if (!frame)
        return false;

    //if (isSeamless())
    //  return false; // Seamless iframes are already "flat", don't try to flatten them.

    bool enabled = document().needFitScreenLayout() || (frame && frame->settings() && frame->settings()->frameFlatteningEnabled());

    if (!enabled || !frame->page())
        return false;

    if (style() && style()->width().isFixed() && style()->height().isFixed()) {
        // Do not flatten iframes with scrolling="no".
        if (element->scrollingMode() == ScrollbarAlwaysOff)
            return false;
        if (style()->width().value() <= 0 || style()->height().value() <= 0)
            return false;
    }

    // Do not flatten offscreen inner frames during frame flattening, as flattening might make them visible.
    IntRect boundingRect = absoluteBoundingBoxRectIgnoringTransforms();
    return boundingRect.maxX() > 0 && boundingRect.maxY() > 0;
}
#endif

#ifdef TENCENT_FITSCREEN
void LayoutIFrame::initialIntrinsicSize()
{
    LayoutSize size = intrinsicSize();
    if (size.height().toInt() == 1) {
        size.setHeight(LayoutUnit(150));
        setIntrinsicSize(size);
    }
}
#endif

} // namespace blink
