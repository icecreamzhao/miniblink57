
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#include "SkDrawDash.h"
#include "SkDashPathEffect.h"

#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkDash::fInfo[] = {
    SK_MEMBER_ARRAY(intervals, Float),
    SK_MEMBER(phase, Float)
};

#endif

DEFINE_GET_MEMBER(SkDash);

<<<<<<< HEAD
SkDash::SkDash()
    : phase(0)
{
}

SkDash::~SkDash()
{
}

SkPathEffect* SkDash::getPathEffect()
{
    int count = intervals.count();
    if (count == 0)
        return nullptr;
    return SkDashPathEffect::Make(intervals.begin(), count, phase).release();
=======
SkDash::SkDash() : phase(0) {
}

SkDash::~SkDash() {
}

SkPathEffect* SkDash::getPathEffect() {
    int count = intervals.count();
    if (count == 0)
        return NULL;
    return SkDashPathEffect::Create(intervals.begin(), count, phase);
>>>>>>> miniblink49
}
