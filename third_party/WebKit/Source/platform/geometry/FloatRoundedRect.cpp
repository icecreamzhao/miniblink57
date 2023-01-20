/*
 * Copyright (C) 2013 Adobe Systems Incorporated. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer.
 * 2. Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials
 *    provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
 * OF THE POSSIBILITY OF SUCH DAMAGE.
 */

<<<<<<< HEAD
#include "platform/geometry/FloatRoundedRect.h"

#include "platform/geometry/FloatQuad.h"
#include "wtf/text/WTFString.h"
#include <algorithm>

=======
#include "config.h"
#include "platform/geometry/FloatRoundedRect.h"

#include "platform/geometry/FloatQuad.h"

#include <algorithm>

#ifndef NDEBUG
#include <stdio.h>
#endif

>>>>>>> miniblink49
namespace blink {

FloatRoundedRect::FloatRoundedRect(float x, float y, float width, float height)
    : m_rect(x, y, width, height)
{
}

FloatRoundedRect::FloatRoundedRect(const FloatRect& rect, const Radii& radii)
    : m_rect(rect)
    , m_radii(radii)
{
}

<<<<<<< HEAD
FloatRoundedRect::FloatRoundedRect(const FloatRect& rect,
    const FloatSize& topLeft,
    const FloatSize& topRight,
    const FloatSize& bottomLeft,
    const FloatSize& bottomRight)
=======
FloatRoundedRect::FloatRoundedRect(const FloatRect& rect, const FloatSize& topLeft, const FloatSize& topRight, const FloatSize& bottomLeft, const FloatSize& bottomRight)
>>>>>>> miniblink49
    : m_rect(rect)
    , m_radii(topLeft, topRight, bottomLeft, bottomRight)
{
}

bool FloatRoundedRect::Radii::isZero() const
{
    return m_topLeft.isZero() && m_topRight.isZero() && m_bottomLeft.isZero() && m_bottomRight.isZero();
}

void FloatRoundedRect::Radii::scale(float factor)
{
    if (factor == 1)
        return;

    // If either radius on a corner becomes zero, reset both radii on that corner.
    m_topLeft.scale(factor);
    if (!m_topLeft.width() || !m_topLeft.height())
        m_topLeft = FloatSize();
    m_topRight.scale(factor);
    if (!m_topRight.width() || !m_topRight.height())
        m_topRight = FloatSize();
    m_bottomLeft.scale(factor);
    if (!m_bottomLeft.width() || !m_bottomLeft.height())
        m_bottomLeft = FloatSize();
    m_bottomRight.scale(factor);
    if (!m_bottomRight.width() || !m_bottomRight.height())
        m_bottomRight = FloatSize();
}

void FloatRoundedRect::Radii::scaleAndFloor(float factor)
{
    if (factor == 1)
        return;

    // If either radius on a corner becomes zero, reset both radii on that corner.
    m_topLeft.scaleAndFloor(factor);
    if (!m_topLeft.width() || !m_topLeft.height())
        m_topLeft = FloatSize();
    m_topRight.scaleAndFloor(factor);
    if (!m_topRight.width() || !m_topRight.height())
        m_topRight = FloatSize();
    m_bottomLeft.scaleAndFloor(factor);
    if (!m_bottomLeft.width() || !m_bottomLeft.height())
        m_bottomLeft = FloatSize();
    m_bottomRight.scaleAndFloor(factor);
    if (!m_bottomRight.width() || !m_bottomRight.height())
        m_bottomRight = FloatSize();
}

<<<<<<< HEAD
void FloatRoundedRect::Radii::shrink(float topWidth,
    float bottomWidth,
    float leftWidth,
    float rightWidth)
=======

void FloatRoundedRect::Radii::shrink(float topWidth, float bottomWidth, float leftWidth, float rightWidth)
>>>>>>> miniblink49
{
    ASSERT(topWidth >= 0 && bottomWidth >= 0 && leftWidth >= 0 && rightWidth >= 0);

    m_topLeft.setWidth(std::max<float>(0, m_topLeft.width() - leftWidth));
    m_topLeft.setHeight(std::max<float>(0, m_topLeft.height() - topWidth));

    m_topRight.setWidth(std::max<float>(0, m_topRight.width() - rightWidth));
    m_topRight.setHeight(std::max<float>(0, m_topRight.height() - topWidth));

    m_bottomLeft.setWidth(std::max<float>(0, m_bottomLeft.width() - leftWidth));
<<<<<<< HEAD
    m_bottomLeft.setHeight(
        std::max<float>(0, m_bottomLeft.height() - bottomWidth));

    m_bottomRight.setWidth(
        std::max<float>(0, m_bottomRight.width() - rightWidth));
    m_bottomRight.setHeight(
        std::max<float>(0, m_bottomRight.height() - bottomWidth));
}

void FloatRoundedRect::Radii::expand(float topWidth,
    float bottomWidth,
    float leftWidth,
    float rightWidth)
=======
    m_bottomLeft.setHeight(std::max<float>(0, m_bottomLeft.height() - bottomWidth));

    m_bottomRight.setWidth(std::max<float>(0, m_bottomRight.width() - rightWidth));
    m_bottomRight.setHeight(std::max<float>(0, m_bottomRight.height() - bottomWidth));
}

void FloatRoundedRect::Radii::expand(float topWidth, float bottomWidth, float leftWidth, float rightWidth)
>>>>>>> miniblink49
{
    ASSERT(topWidth >= 0 && bottomWidth >= 0 && leftWidth >= 0 && rightWidth >= 0);
    if (m_topLeft.width() > 0 && m_topLeft.height() > 0) {
        m_topLeft.setWidth(m_topLeft.width() + leftWidth);
        m_topLeft.setHeight(m_topLeft.height() + topWidth);
    }
    if (m_topRight.width() > 0 && m_topRight.height() > 0) {
        m_topRight.setWidth(m_topRight.width() + rightWidth);
        m_topRight.setHeight(m_topRight.height() + topWidth);
    }
    if (m_bottomLeft.width() > 0 && m_bottomLeft.height() > 0) {
        m_bottomLeft.setWidth(m_bottomLeft.width() + leftWidth);
        m_bottomLeft.setHeight(m_bottomLeft.height() + bottomWidth);
    }
    if (m_bottomRight.width() > 0 && m_bottomRight.height() > 0) {
        m_bottomRight.setWidth(m_bottomRight.width() + rightWidth);
        m_bottomRight.setHeight(m_bottomRight.height() + bottomWidth);
    }
}

<<<<<<< HEAD
=======
#ifndef NDEBUG
void FloatRoundedRect::Radii::show()
{
    fprintf(stderr, "topLeft=[%f,%f], topRight=[%f,%f], bottomLeft=[%f,%f], bottomRight=[%f,%f]\n",
        topLeft().width(), topLeft().height(), topRight().width(), topRight().height(),
        bottomLeft().width(), bottomLeft().height(), bottomRight().width(), bottomRight().height());
}
#endif

>>>>>>> miniblink49
static inline float cornerRectIntercept(float y, const FloatRect& cornerRect)
{
    ASSERT(cornerRect.height() > 0);
    return cornerRect.width() * sqrt(1 - (y * y) / (cornerRect.height() * cornerRect.height()));
}

FloatRect FloatRoundedRect::radiusCenterRect() const
{
    FloatRectOutsets maximumRadiusInsets(
        -std::max(m_radii.topLeft().height(), m_radii.topRight().height()),
        -std::max(m_radii.topRight().width(), m_radii.bottomRight().width()),
        -std::max(m_radii.bottomLeft().height(), m_radii.bottomRight().height()),
        -std::max(m_radii.topLeft().width(), m_radii.bottomLeft().width()));
    FloatRect centerRect(m_rect);
    centerRect.expand(maximumRadiusInsets);
    return centerRect;
}

<<<<<<< HEAD
bool FloatRoundedRect::xInterceptsAtY(float y,
    float& minXIntercept,
    float& maxXIntercept) const
{
    if (y < rect().y() || y > rect().maxY())
=======
bool FloatRoundedRect::xInterceptsAtY(float y, float& minXIntercept, float& maxXIntercept) const
{
    if (y < rect().y() || y >  rect().maxY())
>>>>>>> miniblink49
        return false;

    if (!isRounded()) {
        minXIntercept = rect().x();
        maxXIntercept = rect().maxX();
        return true;
    }

    const FloatRect& topLeftRect = topLeftCorner();
    const FloatRect& bottomLeftRect = bottomLeftCorner();

    if (!topLeftRect.isEmpty() && y >= topLeftRect.y() && y < topLeftRect.maxY())
        minXIntercept = topLeftRect.maxX() - cornerRectIntercept(topLeftRect.maxY() - y, topLeftRect);
    else if (!bottomLeftRect.isEmpty() && y >= bottomLeftRect.y() && y <= bottomLeftRect.maxY())
<<<<<<< HEAD
        minXIntercept = bottomLeftRect.maxX() - cornerRectIntercept(y - bottomLeftRect.y(), bottomLeftRect);
=======
        minXIntercept =  bottomLeftRect.maxX() - cornerRectIntercept(y - bottomLeftRect.y(), bottomLeftRect);
>>>>>>> miniblink49
    else
        minXIntercept = m_rect.x();

    const FloatRect& topRightRect = topRightCorner();
    const FloatRect& bottomRightRect = bottomRightCorner();

    if (!topRightRect.isEmpty() && y >= topRightRect.y() && y <= topRightRect.maxY())
        maxXIntercept = topRightRect.x() + cornerRectIntercept(topRightRect.maxY() - y, topRightRect);
    else if (!bottomRightRect.isEmpty() && y >= bottomRightRect.y() && y <= bottomRightRect.maxY())
        maxXIntercept = bottomRightRect.x() + cornerRectIntercept(y - bottomRightRect.y(), bottomRightRect);
    else
        maxXIntercept = m_rect.maxX();

    return true;
}

void FloatRoundedRect::inflateWithRadii(int size)
{
    FloatRect old = m_rect;

    m_rect.inflate(size);
<<<<<<< HEAD
    // Considering the inflation factor of shorter size to scale the radii seems
    // appropriate here
=======
    // Considering the inflation factor of shorter size to scale the radii seems appropriate here
>>>>>>> miniblink49
    float factor;
    if (m_rect.width() < m_rect.height())
        factor = old.width() ? (float)m_rect.width() / old.width() : int(0);
    else
        factor = old.height() ? (float)m_rect.height() / old.height() : int(0);

    m_radii.scale(factor);
}

bool FloatRoundedRect::intersectsQuad(const FloatQuad& quad) const
{
    if (!quad.intersectsRect(m_rect))
        return false;

    const FloatSize& topLeft = m_radii.topLeft();
    if (!topLeft.isEmpty()) {
        FloatRect rect(m_rect.x(), m_rect.y(), topLeft.width(), topLeft.height());
        if (quad.intersectsRect(rect)) {
<<<<<<< HEAD
            FloatPoint center(m_rect.x() + topLeft.width(),
                m_rect.y() + topLeft.height());
=======
            FloatPoint center(m_rect.x() + topLeft.width(), m_rect.y() + topLeft.height());
>>>>>>> miniblink49
            FloatSize size(topLeft.width(), topLeft.height());
            if (!quad.intersectsEllipse(center, size))
                return false;
        }
    }

    const FloatSize& topRight = m_radii.topRight();
    if (!topRight.isEmpty()) {
<<<<<<< HEAD
        FloatRect rect(m_rect.maxX() - topRight.width(), m_rect.y(),
            topRight.width(), topRight.height());
        if (quad.intersectsRect(rect)) {
            FloatPoint center(m_rect.maxX() - topRight.width(),
                m_rect.y() + topRight.height());
=======
        FloatRect rect(m_rect.maxX() - topRight.width(), m_rect.y(), topRight.width(), topRight.height());
        if (quad.intersectsRect(rect)) {
            FloatPoint center(m_rect.maxX() - topRight.width(), m_rect.y() + topRight.height());
>>>>>>> miniblink49
            FloatSize size(topRight.width(), topRight.height());
            if (!quad.intersectsEllipse(center, size))
                return false;
        }
    }

    const FloatSize& bottomLeft = m_radii.bottomLeft();
    if (!bottomLeft.isEmpty()) {
<<<<<<< HEAD
        FloatRect rect(m_rect.x(), m_rect.maxY() - bottomLeft.height(),
            bottomLeft.width(), bottomLeft.height());
        if (quad.intersectsRect(rect)) {
            FloatPoint center(m_rect.x() + bottomLeft.width(),
                m_rect.maxY() - bottomLeft.height());
=======
        FloatRect rect(m_rect.x(), m_rect.maxY() - bottomLeft.height(), bottomLeft.width(), bottomLeft.height());
        if (quad.intersectsRect(rect)) {
            FloatPoint center(m_rect.x() + bottomLeft.width(), m_rect.maxY() - bottomLeft.height());
>>>>>>> miniblink49
            FloatSize size(bottomLeft.width(), bottomLeft.height());
            if (!quad.intersectsEllipse(center, size))
                return false;
        }
    }

    const FloatSize& bottomRight = m_radii.bottomRight();
    if (!bottomRight.isEmpty()) {
<<<<<<< HEAD
        FloatRect rect(m_rect.maxX() - bottomRight.width(),
            m_rect.maxY() - bottomRight.height(), bottomRight.width(),
            bottomRight.height());
        if (quad.intersectsRect(rect)) {
            FloatPoint center(m_rect.maxX() - bottomRight.width(),
                m_rect.maxY() - bottomRight.height());
=======
        FloatRect rect(m_rect.maxX() - bottomRight.width(), m_rect.maxY() - bottomRight.height(), bottomRight.width(), bottomRight.height());
        if (quad.intersectsRect(rect)) {
            FloatPoint center(m_rect.maxX() - bottomRight.width(), m_rect.maxY() - bottomRight.height());
>>>>>>> miniblink49
            FloatSize size(bottomRight.width(), bottomRight.height());
            if (!quad.intersectsEllipse(center, size))
                return false;
        }
    }

    return true;
}

<<<<<<< HEAD
void FloatRoundedRect::Radii::includeLogicalEdges(
    const FloatRoundedRect::Radii& edges,
    bool isHorizontal,
    bool includeLogicalLeftEdge,
    bool includeLogicalRightEdge)
=======
void FloatRoundedRect::Radii::includeLogicalEdges(const FloatRoundedRect::Radii& edges, bool isHorizontal, bool includeLogicalLeftEdge, bool includeLogicalRightEdge)
>>>>>>> miniblink49
{
    if (includeLogicalLeftEdge) {
        if (isHorizontal)
            m_bottomLeft = edges.bottomLeft();
        else
            m_topRight = edges.topRight();
        m_topLeft = edges.topLeft();
    }

    if (includeLogicalRightEdge) {
        if (isHorizontal)
            m_topRight = edges.topRight();
        else
            m_bottomLeft = edges.bottomLeft();
        m_bottomRight = edges.bottomRight();
    }
}

<<<<<<< HEAD
float calcBorderRadiiConstraintScaleFor(const FloatRect& rect,
    const FloatRoundedRect::Radii& radii)
=======
float calcBorderRadiiConstraintScaleFor(const FloatRect& rect, const FloatRoundedRect::Radii& radii)
>>>>>>> miniblink49
{
    float factor = 1;
    float radiiSum;

    // top
    radiiSum = radii.topLeft().width() + radii.topRight().width(); // Casts to avoid integer overflow.
    if (radiiSum > rect.width())
        factor = std::min(rect.width() / radiiSum, factor);

    // bottom
    radiiSum = radii.bottomLeft().width() + radii.bottomRight().width();
    if (radiiSum > rect.width())
        factor = std::min(rect.width() / radiiSum, factor);

    // left
    radiiSum = radii.topLeft().height() + radii.bottomLeft().height();
    if (radiiSum > rect.height())
        factor = std::min(rect.height() / radiiSum, factor);

    // right
    radiiSum = radii.topRight().height() + radii.bottomRight().height();
    if (radiiSum > rect.height())
        factor = std::min(rect.height() / radiiSum, factor);

    ASSERT(factor <= 1);
    return factor;
}

void FloatRoundedRect::constrainRadii()
{
<<<<<<< HEAD
    m_radii.scaleAndFloor(calcBorderRadiiConstraintScaleFor(rect(), getRadii()));
}

void FloatRoundedRect::includeLogicalEdges(const Radii& edges,
    bool isHorizontal,
    bool includeLogicalLeftEdge,
    bool includeLogicalRightEdge)
{
    m_radii.includeLogicalEdges(edges, isHorizontal, includeLogicalLeftEdge,
        includeLogicalRightEdge);
=======
    m_radii.scaleAndFloor(calcBorderRadiiConstraintScaleFor(rect(), radii()));
}

void FloatRoundedRect::includeLogicalEdges(const Radii& edges, bool isHorizontal, bool includeLogicalLeftEdge, bool includeLogicalRightEdge)
{
    m_radii.includeLogicalEdges(edges, isHorizontal, includeLogicalLeftEdge, includeLogicalRightEdge);
>>>>>>> miniblink49
}

bool FloatRoundedRect::isRenderable() const
{
    // FIXME: remove the 0.0001 slop once this class is converted to layout units.
<<<<<<< HEAD
    return m_radii.topLeft().width() + m_radii.topRight().width() <= m_rect.width() + 0.0001 && m_radii.bottomLeft().width() + m_radii.bottomRight().width() <= m_rect.width() + 0.0001 && m_radii.topLeft().height() + m_radii.bottomLeft().height() <= m_rect.height() + 0.0001 && m_radii.topRight().height() + m_radii.bottomRight().height() <= m_rect.height() + 0.0001;
=======
    return m_radii.topLeft().width() + m_radii.topRight().width() <= m_rect.width() + 0.0001
        && m_radii.bottomLeft().width() + m_radii.bottomRight().width() <= m_rect.width() + 0.0001
        && m_radii.topLeft().height() + m_radii.bottomLeft().height() <= m_rect.height() + 0.0001
        && m_radii.topRight().height() + m_radii.bottomRight().height() <= m_rect.height() + 0.0001;
>>>>>>> miniblink49
}

void FloatRoundedRect::adjustRadii()
{
<<<<<<< HEAD
    float maxRadiusWidth = std::max(m_radii.topLeft().width() + m_radii.topRight().width(),
        m_radii.bottomLeft().width() + m_radii.bottomRight().width());
    float maxRadiusHeight = std::max(m_radii.topLeft().height() + m_radii.bottomLeft().height(),
        m_radii.topRight().height() + m_radii.bottomRight().height());
=======
    float maxRadiusWidth = std::max(m_radii.topLeft().width() + m_radii.topRight().width(), m_radii.bottomLeft().width() + m_radii.bottomRight().width());
    float maxRadiusHeight = std::max(m_radii.topLeft().height() + m_radii.bottomLeft().height(), m_radii.topRight().height() + m_radii.bottomRight().height());
>>>>>>> miniblink49

    if (maxRadiusWidth <= 0 || maxRadiusHeight <= 0) {
        m_radii.scale(0.0f);
        return;
    }
    float widthRatio = static_cast<float>(m_rect.width()) / maxRadiusWidth;
    float heightRatio = static_cast<float>(m_rect.height()) / maxRadiusHeight;
    m_radii.scale(widthRatio < heightRatio ? widthRatio : heightRatio);
}

<<<<<<< HEAD
String FloatRoundedRect::Radii::toString() const
{
    return String::format("tl:%s; tr:%s; bl:%s; br:%s",
        topLeft().toString().ascii().data(),
        topRight().toString().ascii().data(),
        bottomLeft().toString().ascii().data(),
        bottomRight().toString().ascii().data());
}

String FloatRoundedRect::toString() const
{
    return String::format("%s radii:(%s)", rect().toString().ascii().data(),
        getRadii().toString().ascii().data());
}
=======
#ifndef NDEBUG
void FloatRoundedRect::show()
{
    fprintf(stderr, "FloatRoundedRect:\n rect: ");
    m_rect.show();
    fprintf(stderr, " radii: ");
    m_radii.show();
}
#endif
>>>>>>> miniblink49

} // namespace blink
