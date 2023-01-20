/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#include "SkPathOpsPoint.h"

<<<<<<< HEAD
SkDVector operator-(const SkDPoint& a, const SkDPoint& b)
{
    SkDVector v = { a.fX - b.fX, a.fY - b.fY };
=======
SkDVector operator-(const SkDPoint& a, const SkDPoint& b) {
    SkDVector v = {a.fX - b.fX, a.fY - b.fY};
>>>>>>> miniblink49
    return v;
}
