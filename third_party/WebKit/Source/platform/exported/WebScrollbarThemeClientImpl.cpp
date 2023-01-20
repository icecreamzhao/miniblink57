/*
 * Copyright (C) 2012 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

<<<<<<< HEAD
=======
#include "config.h"

>>>>>>> miniblink49
#include "platform/exported/WebScrollbarThemeClientImpl.h"

#include "platform/scroll/ScrollbarTheme.h"

namespace blink {

<<<<<<< HEAD
WebScrollbarThemeClientImpl::WebScrollbarThemeClientImpl(
    WebScrollbar& scrollbar)
    : m_scrollbar(scrollbar)
{
    ScrollbarTheme::theme().registerScrollbar(*this);
=======
WebScrollbarThemeClientImpl::WebScrollbarThemeClientImpl(WebScrollbar* scrollbar)
    : m_scrollbar(scrollbar)
{
    ScrollbarTheme::theme()->registerScrollbar(this);
>>>>>>> miniblink49
}

WebScrollbarThemeClientImpl::~WebScrollbarThemeClientImpl()
{
<<<<<<< HEAD
    ScrollbarTheme::theme().unregisterScrollbar(*this);
=======
    ScrollbarTheme::theme()->unregisterScrollbar(this);
>>>>>>> miniblink49
}

int WebScrollbarThemeClientImpl::x() const
{
    return location().x();
}

int WebScrollbarThemeClientImpl::y() const
{
    return location().y();
}

int WebScrollbarThemeClientImpl::width() const
{
    return size().width();
}

int WebScrollbarThemeClientImpl::height() const
{
    return size().height();
}

IntSize WebScrollbarThemeClientImpl::size() const
{
<<<<<<< HEAD
    return m_scrollbar.size();
=======
    return m_scrollbar->size();
>>>>>>> miniblink49
}

IntPoint WebScrollbarThemeClientImpl::location() const
{
<<<<<<< HEAD
    return m_scrollbar.location();
=======
    return m_scrollbar->location();
>>>>>>> miniblink49
}

Widget* WebScrollbarThemeClientImpl::parent() const
{
    // Unused by Chromium scrollbar themes.
    ASSERT_NOT_REACHED();
    return 0;
}

Widget* WebScrollbarThemeClientImpl::root() const
{
    // Unused by Chromium scrollbar themes.
    ASSERT_NOT_REACHED();
    return 0;
}

void WebScrollbarThemeClientImpl::setFrameRect(const IntRect&)
{
    // Unused by Chromium scrollbar themes.
    ASSERT_NOT_REACHED();
}

IntRect WebScrollbarThemeClientImpl::frameRect() const
{
    return IntRect(location(), size());
}

void WebScrollbarThemeClientImpl::invalidate()
{
    // Unused by Chromium scrollbar themes.
    ASSERT_NOT_REACHED();
}

void WebScrollbarThemeClientImpl::invalidateRect(const IntRect&)
{
    // Unused by Chromium scrollbar themes.
    ASSERT_NOT_REACHED();
}

<<<<<<< HEAD
ScrollbarOverlayColorTheme
WebScrollbarThemeClientImpl::getScrollbarOverlayColorTheme() const
{
    return static_cast<ScrollbarOverlayColorTheme>(
        m_scrollbar.scrollbarOverlayColorTheme());
}

void WebScrollbarThemeClientImpl::getTickmarks(
    Vector<IntRect>& tickmarks) const
{
    WebVector<WebRect> webTickmarks;
    m_scrollbar.getTickmarks(webTickmarks);
=======
ScrollbarOverlayStyle WebScrollbarThemeClientImpl::scrollbarOverlayStyle() const
{
    return static_cast<ScrollbarOverlayStyle>(m_scrollbar->scrollbarOverlayStyle());
}

void WebScrollbarThemeClientImpl::getTickmarks(Vector<IntRect>& tickmarks) const
{
    WebVector<WebRect> webTickmarks;
    m_scrollbar->getTickmarks(webTickmarks);
>>>>>>> miniblink49
    tickmarks.resize(webTickmarks.size());
    for (size_t i = 0; i < webTickmarks.size(); ++i)
        tickmarks[i] = webTickmarks[i];
}

bool WebScrollbarThemeClientImpl::isScrollableAreaActive() const
{
<<<<<<< HEAD
    return m_scrollbar.isScrollableAreaActive();
}

IntPoint WebScrollbarThemeClientImpl::convertFromRootFrame(
    const IntPoint& pointInRootFrame) const
{
    // Unused by Chromium scrollbar themes.
    ASSERT_NOT_REACHED();
    return pointInRootFrame;
=======
    return m_scrollbar->isScrollableAreaActive();
}

IntPoint WebScrollbarThemeClientImpl::convertFromContainingWindow(const IntPoint& windowPoint)
{
    // Unused by Chromium scrollbar themes.
    ASSERT_NOT_REACHED();
    return windowPoint;
>>>>>>> miniblink49
}

bool WebScrollbarThemeClientImpl::isCustomScrollbar() const
{
<<<<<<< HEAD
    return m_scrollbar.isCustomScrollbar();
=======
    return m_scrollbar->isCustomScrollbar();
>>>>>>> miniblink49
}

ScrollbarOrientation WebScrollbarThemeClientImpl::orientation() const
{
<<<<<<< HEAD
    return static_cast<ScrollbarOrientation>(m_scrollbar.orientation());
=======
    return static_cast<ScrollbarOrientation>(m_scrollbar->orientation());
>>>>>>> miniblink49
}

bool WebScrollbarThemeClientImpl::isLeftSideVerticalScrollbar() const
{
<<<<<<< HEAD
    return m_scrollbar.isLeftSideVerticalScrollbar();
=======
    return m_scrollbar->isLeftSideVerticalScrollbar();
>>>>>>> miniblink49
}

int WebScrollbarThemeClientImpl::value() const
{
<<<<<<< HEAD
    return m_scrollbar.value();
=======
    return m_scrollbar->value();
>>>>>>> miniblink49
}

float WebScrollbarThemeClientImpl::currentPos() const
{
    return value();
}

int WebScrollbarThemeClientImpl::visibleSize() const
{
    return totalSize() - maximum();
}

int WebScrollbarThemeClientImpl::totalSize() const
{
<<<<<<< HEAD
    return m_scrollbar.totalSize();
=======
    return m_scrollbar->totalSize();
>>>>>>> miniblink49
}

int WebScrollbarThemeClientImpl::maximum() const
{
<<<<<<< HEAD
    return m_scrollbar.maximum();
=======
    return m_scrollbar->maximum();
>>>>>>> miniblink49
}

ScrollbarControlSize WebScrollbarThemeClientImpl::controlSize() const
{
<<<<<<< HEAD
    return static_cast<ScrollbarControlSize>(m_scrollbar.controlSize());
=======
    return static_cast<ScrollbarControlSize>(m_scrollbar->controlSize());
>>>>>>> miniblink49
}

ScrollbarPart WebScrollbarThemeClientImpl::pressedPart() const
{
<<<<<<< HEAD
    return static_cast<ScrollbarPart>(m_scrollbar.pressedPart());
=======
    return static_cast<ScrollbarPart>(m_scrollbar->pressedPart());
>>>>>>> miniblink49
}

ScrollbarPart WebScrollbarThemeClientImpl::hoveredPart() const
{
<<<<<<< HEAD
    return static_cast<ScrollbarPart>(m_scrollbar.hoveredPart());
=======
    return static_cast<ScrollbarPart>(m_scrollbar->hoveredPart());
>>>>>>> miniblink49
}

void WebScrollbarThemeClientImpl::styleChanged()
{
    ASSERT_NOT_REACHED();
}

<<<<<<< HEAD
void WebScrollbarThemeClientImpl::setScrollbarsHidden(bool hidden)
{
    ASSERT_NOT_REACHED();
}

bool WebScrollbarThemeClientImpl::enabled() const
{
    return m_scrollbar.enabled();
=======
bool WebScrollbarThemeClientImpl::enabled() const
{
    return m_scrollbar->enabled();
>>>>>>> miniblink49
}

void WebScrollbarThemeClientImpl::setEnabled(bool)
{
    ASSERT_NOT_REACHED();
}

bool WebScrollbarThemeClientImpl::isOverlayScrollbar() const
{
<<<<<<< HEAD
    return m_scrollbar.isOverlay();
=======
    return m_scrollbar->isOverlay();
}

bool WebScrollbarThemeClientImpl::isAlphaLocked() const
{
    return m_scrollbar->isAlphaLocked();
}

void WebScrollbarThemeClientImpl::setIsAlphaLocked(bool flag)
{
    m_scrollbar->setIsAlphaLocked(flag);
>>>>>>> miniblink49
}

float WebScrollbarThemeClientImpl::elasticOverscroll() const
{
<<<<<<< HEAD
    return m_scrollbar.elasticOverscroll();
}

void WebScrollbarThemeClientImpl::setElasticOverscroll(
    float elasticOverscroll)
{
    return m_scrollbar.setElasticOverscroll(elasticOverscroll);
=======
    return m_scrollbar->elasticOverscroll();
}

void WebScrollbarThemeClientImpl::setElasticOverscroll(float elasticOverscroll)
{
    return m_scrollbar->setElasticOverscroll(elasticOverscroll);
}

DisplayItemClient WebScrollbarThemeClientImpl::displayItemClient() const
{
    ASSERT_NOT_REACHED();
    return toDisplayItemClient(this);
}

String WebScrollbarThemeClientImpl::debugName() const
{
    return "WebScrollbarThemeClientImpl";
>>>>>>> miniblink49
}

} // namespace blink
