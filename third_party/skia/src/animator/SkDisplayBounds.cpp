
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#include "SkDisplayBounds.h"
#include "SkAnimateMaker.h"

#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkDisplayBounds::fInfo[] = {
    SK_MEMBER_INHERITED,
    SK_MEMBER(inval, Boolean)
};

#endif

DEFINE_GET_MEMBER(SkDisplayBounds);

<<<<<<< HEAD
SkDisplayBounds::SkDisplayBounds()
    : inval(false)
{
}

bool SkDisplayBounds::draw(SkAnimateMaker& maker)
{
=======
SkDisplayBounds::SkDisplayBounds() : inval(false) {
}

bool SkDisplayBounds::draw(SkAnimateMaker& maker) {
>>>>>>> miniblink49
    maker.fDisplayList.fUnionBounds = SkToBool(inval);
    maker.fDisplayList.fDrawBounds = false;
    fBounds.setEmpty();
    bool result = INHERITED::draw(maker);
    maker.fDisplayList.fUnionBounds = false;
    maker.fDisplayList.fDrawBounds = true;
    if (inval && fBounds.isEmpty() == false) {
        SkIRect& rect = maker.fDisplayList.fInvalBounds;
        maker.fDisplayList.fHasUnion = true;
        if (rect.isEmpty())
            rect = fBounds;
        else
            rect.join(fBounds);
    }
    return result;
}
