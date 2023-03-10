// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef UI_VIEWS_VIEW_TARGETER_DELEGATE_H_
#define UI_VIEWS_VIEW_TARGETER_DELEGATE_H_

#include "base/macros.h"
#include "ui/views/views_export.h"

namespace gfx {
class Rect;
}

namespace views {
class View;

// Defines the default behaviour for hit-testing and event-targeting against a
// View using a rectangular region representing an event's location. Views
// wishing to define custom hit-testing or event-targeting behaviour do so by
// extending ViewTargeterDelegate and then installing a ViewTargeter on
// themselves.
class VIEWS_EXPORT ViewTargeterDelegate {
public:
    ViewTargeterDelegate() { }
    virtual ~ViewTargeterDelegate() { }

    // Returns true if the bounds of |target| intersects |rect|, where |rect|
    // is in the local coodinate space of |target|. Overrides of this method by
    // a View subclass should enforce DCHECK_EQ(this, target).
    virtual bool DoesIntersectRect(const View* target,
        const gfx::Rect& rect) const;

    // If point-based targeting should be used, return the deepest visible
    // descendant of |root| that contains the center point of |rect|.
    // If rect-based targeting (i.e., fuzzing) should be used, return the
    // closest visible descendant of |root| having at least kRectTargetOverlap of
    // its area covered by |rect|. If no such descendant exists, return the
    // deepest visible descendant of |root| that contains the center point of
    // |rect|. See http://goo.gl/3Jp2BD for more information about rect-based
    // targeting.
    virtual View* TargetForRect(View* root, const gfx::Rect& rect);

private:
    DISALLOW_COPY_AND_ASSIGN(ViewTargeterDelegate);
};

} // namespace views

#endif // UI_VIEWS_VIEW_TARGETER_DELEGATE_H_
