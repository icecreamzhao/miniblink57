
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#include "SkTextOnPath.h"
#include "SkAnimateMaker.h"
#include "SkCanvas.h"
#include "SkDrawPath.h"
#include "SkDrawText.h"
#include "SkPaint.h"

#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkTextOnPath::fInfo[] = {
    SK_MEMBER(offset, Float),
    SK_MEMBER(path, Path),
    SK_MEMBER(text, Text)
};

#endif

DEFINE_GET_MEMBER(SkTextOnPath);

<<<<<<< HEAD
SkTextOnPath::SkTextOnPath()
    : offset(0)
    , path(nullptr)
    , text(nullptr)
{
}

bool SkTextOnPath::draw(SkAnimateMaker& maker)
{
=======
SkTextOnPath::SkTextOnPath() : offset(0), path(NULL), text(NULL) {
}

bool SkTextOnPath::draw(SkAnimateMaker& maker) {
>>>>>>> miniblink49
    SkASSERT(text);
    SkASSERT(path);
    SkBoundableAuto boundable(this, maker);
    maker.fCanvas->drawTextOnPathHV(text->getText(), text->getSize(),
<<<<<<< HEAD
        path->getPath(), offset, 0, *maker.fPaint);
=======
                                    path->getPath(), offset, 0, *maker.fPaint);
>>>>>>> miniblink49
    return false;
}
