/*
 * Copyright (C) 2012 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
<<<<<<< HEAD
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 */

=======
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "config.h"
>>>>>>> miniblink49
#include "public/web/WebSurroundingText.h"

#include "core/dom/Element.h"
#include "core/dom/Node.h"
#include "core/dom/Range.h"
#include "core/dom/Text.h"
<<<<<<< HEAD
#include "core/editing/FrameSelection.h"
=======
>>>>>>> miniblink49
#include "core/editing/SurroundingText.h"
#include "core/editing/VisiblePosition.h"
#include "core/layout/LayoutObject.h"
#include "public/platform/WebPoint.h"
#include "public/web/WebHitTestResult.h"
<<<<<<< HEAD
#include "web/WebLocalFrameImpl.h"

namespace blink {

WebSurroundingText::WebSurroundingText() { }

WebSurroundingText::~WebSurroundingText() { }

void WebSurroundingText::initialize(const WebNode& webNode,
    const WebPoint& nodePoint,
    size_t maxLength)
{
    const Node* node = webNode.constUnwrap<Node>();
    if (!node)
        return;

    // VisiblePosition and SurroundingText must be created with clean layout.
    node->document().updateStyleAndLayoutIgnorePendingStylesheets();
    DocumentLifecycle::DisallowTransitionScope disallowTransition(
        node->document().lifecycle());

    if (!node->layoutObject())
        return;

    // TODO(xiaochengh): The followinng SurroundingText can hold a null Range,
    // in which case we should prevent it from being stored in |m_private|.
    m_private.reset(new SurroundingText(
        createVisiblePosition(node->layoutObject()->positionForPoint(
                                  static_cast<IntPoint>(nodePoint)))
            .deepEquivalent()
            .parentAnchoredEquivalent(),
        maxLength));
}

void WebSurroundingText::initializeFromCurrentSelection(WebLocalFrame* frame,
    size_t maxLength)
{
    LocalFrame* webFrame = toWebLocalFrameImpl(frame)->frame();

    // TODO(xiaochengh): The use of updateStyleAndLayoutIgnorePendingStylesheets
    // needs to be audited.  See http://crbug.com/590369 for more details.
    webFrame->document()->updateStyleAndLayoutIgnorePendingStylesheets();

    if (Range* range = createRange(
            webFrame->selection().selection().toNormalizedEphemeralRange())) {
        // TODO(xiaochengh): The followinng SurroundingText can hold a null Range,
        // in which case we should prevent it from being stored in |m_private|.
        m_private.reset(new SurroundingText(*range, maxLength));
    }
=======

namespace blink {

void WebSurroundingText::initialize(const WebNode& webNode, const WebPoint& nodePoint, size_t maxLength)
{
    const Node* node = webNode.constUnwrap<Node>();
    if (!node || !node->layoutObject())
        return;

    m_private.reset(new SurroundingText(VisiblePosition(node->layoutObject()->positionForPoint(static_cast<IntPoint>(nodePoint))).deepEquivalent().parentAnchoredEquivalent(), maxLength));
}

void WebSurroundingText::initialize(const WebRange& webRange, size_t maxLength)
{
    if (RefPtrWillBeRawPtr<Range> range = static_cast<PassRefPtrWillBeRawPtr<Range>>(webRange))
        m_private.reset(new SurroundingText(*range, maxLength));
>>>>>>> miniblink49
}

WebString WebSurroundingText::textContent() const
{
    return m_private->content();
}

size_t WebSurroundingText::hitOffsetInTextContent() const
{
<<<<<<< HEAD
    DCHECK_EQ(m_private->startOffsetInContent(), m_private->endOffsetInContent());
=======
    ASSERT(m_private->startOffsetInContent() == m_private->endOffsetInContent());
>>>>>>> miniblink49
    return m_private->startOffsetInContent();
}

size_t WebSurroundingText::startOffsetInTextContent() const
{
    return m_private->startOffsetInContent();
}

size_t WebSurroundingText::endOffsetInTextContent() const
{
    return m_private->endOffsetInContent();
}

<<<<<<< HEAD
=======
WebRange WebSurroundingText::rangeFromContentOffsets(size_t startOffsetInContent, size_t endOffsetInContent)
{
    return m_private->rangeFromContentOffsets(startOffsetInContent, endOffsetInContent);
}

>>>>>>> miniblink49
bool WebSurroundingText::isNull() const
{
    return !m_private.get();
}

<<<<<<< HEAD
=======
void WebSurroundingText::reset()
{
    m_private.reset(0);
}

>>>>>>> miniblink49
} // namespace blink
