
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#ifndef SkDrawPoint_DEFINED
#define SkDrawPoint_DEFINED

#include "SkBoundable.h"
#include "SkMemberInfo.h"
#include "SkPoint.h"

struct Sk_Point {
    DECLARE_NO_VIRTUALS_MEMBER_INFO(_Point);
    Sk_Point();
<<<<<<< HEAD

=======
>>>>>>> miniblink49
private:
    SkPoint fPoint;
};

class SkDrawPoint : public SkDisplayable {
    DECLARE_MEMBER_INFO(DrawPoint);
    SkDrawPoint();
<<<<<<< HEAD
    void getBounds(SkRect*) override;

=======
    void getBounds(SkRect* ) override;
>>>>>>> miniblink49
private:
    SkPoint fPoint;
    typedef SkDisplayable INHERITED;
};

#endif // SkDrawPoint_DEFINED
