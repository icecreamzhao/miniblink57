
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkDrawClip.h"
#include "SkAnimateMaker.h"
#include "SkCanvas.h"
#include "SkDrawPath.h"
#include "SkDrawRectangle.h"
=======

#include "SkDrawClip.h"
#include "SkAnimateMaker.h"
#include "SkCanvas.h"
#include "SkDrawRectangle.h"
#include "SkDrawPath.h"

>>>>>>> miniblink49

#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkDrawClip::fInfo[] = {
    SK_MEMBER(path, Path),
    SK_MEMBER(rect, Rect)
};

#endif

DEFINE_GET_MEMBER(SkDrawClip);

<<<<<<< HEAD
SkDrawClip::SkDrawClip()
    : rect(nullptr)
    , path(nullptr)
{
}

bool SkDrawClip::draw(SkAnimateMaker& maker)
{
    if (rect != nullptr)
        maker.fCanvas->clipRect(rect->fRect);
    else {
        SkASSERT(path != nullptr);
=======
SkDrawClip::SkDrawClip() : rect(NULL), path(NULL) {
}

bool SkDrawClip::draw(SkAnimateMaker& maker ) {
    if (rect != NULL)
        maker.fCanvas->clipRect(rect->fRect);
    else {
        SkASSERT(path != NULL);
>>>>>>> miniblink49
        maker.fCanvas->clipPath(path->fPath);
    }
    return false;
}
