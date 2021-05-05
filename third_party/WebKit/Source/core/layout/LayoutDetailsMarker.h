/*
 * Copyright (C) 2010, 2011 Nokia Corporation and/or its subsidiary(-ies)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public License
 * along with this library; see the file COPYING.LIB.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 */

#ifndef LayoutDetailsMarker_h
#define LayoutDetailsMarker_h

#include "core/layout/LayoutBlockFlow.h"

namespace blink {

class LayoutDetailsMarker final : public LayoutBlockFlow {
public:
    LayoutDetailsMarker(Element*);

    enum Orientation { Up,
        Down,
        Left,
        Right };

    Orientation getOrientation() const;

    const char* name() const override { return "LayoutDetailsMarker"; }

private:
    bool isOfType(LayoutObjectType type) const override
    {
        return type == LayoutObjectDetailsMarker || LayoutBlockFlow::isOfType(type);
    }
    void paint(const PaintInfo&, const LayoutPoint&) const override;
    bool paintedOutputOfObjectHasNoEffectRegardlessOfSize() const override
    {
        return false;
    }

    bool isOpen() const;
};

DEFINE_LAYOUT_OBJECT_TYPE_CASTS(LayoutDetailsMarker, isDetailsMarker());

} // namespace blink

#endif // LayoutDetailsMarker_h
