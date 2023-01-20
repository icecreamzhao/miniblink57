/*
 * Copyright (C) 2004, 2005, 2006, 2010 Apple Inc. All rights reserved.
 * Copyright (C) 2013 Google Inc. All rights reserved.
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

<<<<<<< HEAD
#include "platform/Widget.h"

#include "wtf/Assertions.h"

namespace blink {

=======
#include "config.h"
#include "platform/Widget.h"

#include "wtf/Assertions.h"
#include "wtf/RefCountedLeakCounter.h"

namespace blink {

#ifndef NDEBUG
    DEFINE_DEBUG_ONLY_GLOBAL(WTF::RefCountedLeakCounter, widgetCounter, ("widgetCounter"));
#endif

>>>>>>> miniblink49
Widget::Widget()
    : m_parent(nullptr)
    , m_selfVisible(false)
    , m_parentVisible(false)
{
<<<<<<< HEAD
}

Widget::~Widget() { }
=======
#ifndef NDEBUG
    widgetCounter.increment();
#endif
}

Widget::~Widget()
{
#if !ENABLE(OILPAN)
    ASSERT(!parent());
#endif
#ifndef NDEBUG
    widgetCounter.decrement();
#endif
}
>>>>>>> miniblink49

DEFINE_TRACE(Widget)
{
    visitor->trace(m_parent);
}

void Widget::setParent(Widget* widget)
{
    ASSERT(!widget || !m_parent);
    if (!widget || !widget->isVisible())
        setParentVisible(false);
    m_parent = widget;
    if (widget && widget->isVisible())
        setParentVisible(true);
}

Widget* Widget::root() const
{
    const Widget* top = this;
    while (top->parent())
        top = top->parent();
    if (top->isFrameView())
        return const_cast<Widget*>(static_cast<const Widget*>(top));
    return 0;
}

<<<<<<< HEAD
IntRect Widget::convertFromRootFrame(const IntRect& rectInRootFrame) const
{
    if (const Widget* parentWidget = parent()) {
        IntRect parentRect = parentWidget->convertFromRootFrame(rectInRootFrame);
        return convertFromContainingWidget(parentRect);
    }
    return rectInRootFrame;
}

IntRect Widget::convertToRootFrame(const IntRect& localRect) const
{
    if (const Widget* parentWidget = parent()) {
        IntRect parentRect = convertToContainingWidget(localRect);
        return parentWidget->convertToRootFrame(parentRect);
=======
IntRect Widget::convertFromContainingWindow(const IntRect& windowRect) const
{
    if (const Widget* parentWidget = parent()) {
        IntRect parentRect = parentWidget->convertFromContainingWindow(windowRect);
        return convertFromContainingView(parentRect);
    }
    return windowRect;
}

IntRect Widget::convertToContainingWindow(const IntRect& localRect) const
{
    if (const Widget* parentWidget = parent()) {
        IntRect parentRect = convertToContainingView(localRect);
        return parentWidget->convertToContainingWindow(parentRect);
>>>>>>> miniblink49
    }
    return localRect;
}

<<<<<<< HEAD
IntPoint Widget::convertFromRootFrame(const IntPoint& pointInRootFrame) const
{
    if (const Widget* parentWidget = parent()) {
        IntPoint parentPoint = parentWidget->convertFromRootFrame(pointInRootFrame);
        return convertFromContainingWidget(parentPoint);
    }
    return pointInRootFrame;
}

FloatPoint Widget::convertFromRootFrame(
    const FloatPoint& pointInRootFrame) const
{
    // Widgets / windows are required to be IntPoint aligned, but we may need to
    // convert FloatPoint values within them (eg. for event co-ordinates).
    IntPoint flooredPoint = flooredIntPoint(pointInRootFrame);
    FloatPoint parentPoint = this->convertFromRootFrame(flooredPoint);
    FloatSize windowFraction = pointInRootFrame - flooredPoint;
    // Use linear interpolation handle any fractional value (eg. for iframes
    // subject to a transform beyond just a simple translation).
    // FIXME: Add FloatPoint variants of all co-ordinate space conversion APIs.
    if (!windowFraction.isEmpty()) {
        const int kFactor = 1000;
        IntPoint parentLineEnd = this->convertFromRootFrame(
            flooredPoint + roundedIntSize(windowFraction.scaledBy(kFactor)));
=======
IntPoint Widget::convertFromContainingWindow(const IntPoint& windowPoint) const
{
    if (const Widget* parentWidget = parent()) {
        IntPoint parentPoint = parentWidget->convertFromContainingWindow(windowPoint);
        return convertFromContainingView(parentPoint);
    }
    return windowPoint;
}

FloatPoint Widget::convertFromContainingWindow(const FloatPoint& windowPoint) const
{
    // Widgets / windows are required to be IntPoint aligned, but we may need to convert
    // FloatPoint values within them (eg. for event co-ordinates).
    IntPoint flooredPoint = flooredIntPoint(windowPoint);
    FloatPoint parentPoint = this->convertFromContainingWindow(flooredPoint);
    FloatSize windowFraction = windowPoint - flooredPoint;
    // Use linear interpolation handle any fractional value (eg. for iframes subject to a transform
    // beyond just a simple translation).
    // FIXME: Add FloatPoint variants of all co-ordinate space conversion APIs.
    if (!windowFraction.isEmpty()) {
        const int kFactor = 1000;
        IntPoint parentLineEnd = this->convertFromContainingWindow(flooredPoint + roundedIntSize(windowFraction.scaledBy(kFactor)));
>>>>>>> miniblink49
        FloatSize parentFraction = (parentLineEnd - parentPoint).scaledBy(1.0f / kFactor);
        parentPoint.move(parentFraction);
    }
    return parentPoint;
}

<<<<<<< HEAD
IntPoint Widget::convertToRootFrame(const IntPoint& localPoint) const
{
    if (const Widget* parentWidget = parent()) {
        IntPoint parentPoint = convertToContainingWidget(localPoint);
        return parentWidget->convertToRootFrame(parentPoint);
=======
IntPoint Widget::convertToContainingWindow(const IntPoint& localPoint) const
{
    if (const Widget* parentWidget = parent()) {
        IntPoint parentPoint = convertToContainingView(localPoint);
        return parentWidget->convertToContainingWindow(parentPoint);
>>>>>>> miniblink49
    }
    return localPoint;
}

<<<<<<< HEAD
IntRect Widget::convertToContainingWidget(const IntRect& localRect) const
{
    if (const Widget* parentWidget = parent()) {
        IntRect parentRect(localRect);
        parentRect.setLocation(
            parentWidget->convertChildToSelf(this, localRect.location()));
=======
IntRect Widget::convertToContainingView(const IntRect& localRect) const
{
    if (const Widget* parentWidget = parent()) {
        IntRect parentRect(localRect);
        parentRect.setLocation(parentWidget->convertChildToSelf(this, localRect.location()));
>>>>>>> miniblink49
        return parentRect;
    }
    return localRect;
}

<<<<<<< HEAD
IntRect Widget::convertFromContainingWidget(const IntRect& parentRect) const
{
    if (const Widget* parentWidget = parent()) {
        IntRect localRect = parentRect;
        localRect.setLocation(
            parentWidget->convertSelfToChild(this, localRect.location()));
=======
IntRect Widget::convertFromContainingView(const IntRect& parentRect) const
{
    if (const Widget* parentWidget = parent()) {
        IntRect localRect = parentRect;
        localRect.setLocation(parentWidget->convertSelfToChild(this, localRect.location()));
>>>>>>> miniblink49
        return localRect;
    }

    return parentRect;
}

<<<<<<< HEAD
IntPoint Widget::convertToContainingWidget(const IntPoint& localPoint) const
=======
IntPoint Widget::convertToContainingView(const IntPoint& localPoint) const
>>>>>>> miniblink49
{
    if (const Widget* parentWidget = parent())
        return parentWidget->convertChildToSelf(this, localPoint);

    return localPoint;
}

<<<<<<< HEAD
IntPoint Widget::convertFromContainingWidget(
    const IntPoint& parentPoint) const
=======
IntPoint Widget::convertFromContainingView(const IntPoint& parentPoint) const
>>>>>>> miniblink49
{
    if (const Widget* parentWidget = parent())
        return parentWidget->convertSelfToChild(this, parentPoint);

    return parentPoint;
}

<<<<<<< HEAD
IntPoint Widget::convertChildToSelf(const Widget*,
    const IntPoint& point) const
=======
IntPoint Widget::convertChildToSelf(const Widget*, const IntPoint& point) const
>>>>>>> miniblink49
{
    return point;
}

<<<<<<< HEAD
IntPoint Widget::convertSelfToChild(const Widget*,
    const IntPoint& point) const
=======
IntPoint Widget::convertSelfToChild(const Widget*, const IntPoint& point) const
>>>>>>> miniblink49
{
    return point;
}

} // namespace blink
