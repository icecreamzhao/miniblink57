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
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDER "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY,
 * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
 * TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
 * THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifndef IntRectOutsets_h
#define IntRectOutsets_h

#include "platform/PlatformExport.h"
#include "wtf/Allocator.h"

namespace blink {

// Specifies integral lengths to be used to expand a rectangle.
// For example, |top()| returns the distance the top edge should be moved
// upward.
//
// Negative lengths can be used to express insets.
class PLATFORM_EXPORT IntRectOutsets {
    DISALLOW_NEW();

public:
    IntRectOutsets()
        : m_top(0)
        , m_right(0)
        , m_bottom(0)
        , m_left(0)
    {
    }

    IntRectOutsets(int top, int right, int bottom, int left)
        : m_top(top)
        , m_right(right)
        , m_bottom(bottom)
        , m_left(left)
    {
    }

    int top() const { return m_top; }
    int right() const { return m_right; }
    int bottom() const { return m_bottom; }
    int left() const { return m_left; }

    void setTop(int top) { m_top = top; }
    void setRight(int right) { m_right = right; }
    void setBottom(int bottom) { m_bottom = bottom; }
    void setLeft(int left) { m_left = left; }

    bool isZero() const { return !left() && !right() && !top() && !bottom(); }

private:
    int m_top;
    int m_right;
    int m_bottom;
    int m_left;
};

inline void operator+=(IntRectOutsets& a, const IntRectOutsets& b)
{
    a.setTop(a.top() + b.top());
    a.setRight(a.right() + b.right());
    a.setBottom(a.bottom() + b.bottom());
    a.setLeft(a.left() + b.left());
}

} // namespace blink

#endif // IntRectOutsets_h
