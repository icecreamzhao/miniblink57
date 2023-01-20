<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2009 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#ifndef SkEdgeClipper_DEFINED
#define SkEdgeClipper_DEFINED

#include "SkPath.h"

/** This is basically an iterator. It is initialized with an edge and a clip,
    and then next() is called until it returns kDone_Verb.
 */
class SkEdgeClipper {
public:
<<<<<<< HEAD
    SkEdgeClipper(bool canCullToTheRight)
        : fCanCullToTheRight(canCullToTheRight)
    {
    }
=======
    SkEdgeClipper(bool canCullToTheRight) : fCanCullToTheRight(canCullToTheRight) {}
>>>>>>> miniblink49

    bool clipQuad(const SkPoint pts[3], const SkRect& clip);
    bool clipCubic(const SkPoint pts[4], const SkRect& clip);

    SkPath::Verb next(SkPoint pts[]);

    bool canCullToTheRight() const { return fCanCullToTheRight; }

private:
<<<<<<< HEAD
    SkPoint* fCurrPoint;
    SkPath::Verb* fCurrVerb;
    const bool fCanCullToTheRight;
=======
    SkPoint*        fCurrPoint;
    SkPath::Verb*   fCurrVerb;
    const bool      fCanCullToTheRight;
>>>>>>> miniblink49

    enum {
        kMaxVerbs = 13,
        kMaxPoints = 32
    };
<<<<<<< HEAD
    SkPoint fPoints[kMaxPoints];
    SkPath::Verb fVerbs[kMaxVerbs];
=======
    SkPoint         fPoints[kMaxPoints];
    SkPath::Verb    fVerbs[kMaxVerbs];
>>>>>>> miniblink49

    void clipMonoQuad(const SkPoint srcPts[3], const SkRect& clip);
    void clipMonoCubic(const SkPoint srcPts[4], const SkRect& clip);
    void appendVLine(SkScalar x, SkScalar y0, SkScalar y1, bool reverse);
    void appendQuad(const SkPoint pts[3], bool reverse);
    void appendCubic(const SkPoint pts[4], bool reverse);
};

#ifdef SK_DEBUG
<<<<<<< HEAD
void sk_assert_monotonic_x(const SkPoint pts[], int count);
void sk_assert_monotonic_y(const SkPoint pts[], int count);
#else
#define sk_assert_monotonic_x(pts, count)
#define sk_assert_monotonic_y(pts, count)
=======
    void sk_assert_monotonic_x(const SkPoint pts[], int count);
    void sk_assert_monotonic_y(const SkPoint pts[], int count);
#else
    #define sk_assert_monotonic_x(pts, count)
    #define sk_assert_monotonic_y(pts, count)
>>>>>>> miniblink49
#endif

#endif
