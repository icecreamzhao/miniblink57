
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#include "SkHitClear.h"

#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkHitClear::fInfo[] = {
    SK_MEMBER_ARRAY(targets, Displayable)
};

#endif

DEFINE_GET_MEMBER(SkHitClear);

<<<<<<< HEAD
bool SkHitClear::enable(SkAnimateMaker&)
{
=======
bool SkHitClear::enable(SkAnimateMaker&) {
>>>>>>> miniblink49
    for (int tIndex = 0; tIndex < targets.count(); tIndex++) {
        SkDisplayable* target = targets[tIndex];
        target->clearBounder();
    }
    return true;
}

<<<<<<< HEAD
bool SkHitClear::hasEnable() const
{
=======
bool SkHitClear::hasEnable() const {
>>>>>>> miniblink49
    return true;
}
