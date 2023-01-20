
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#ifndef SkDrawClip_DEFINED
#define SkDrawClip_DEFINED

#include "SkADrawable.h"
#include "SkMemberInfo.h"
#include "SkRegion.h"

class SkDrawPath;
class SkDrawRect;

class SkDrawClip : public SkADrawable {
    DECLARE_DRAW_MEMBER_INFO(Clip);
    SkDrawClip();
<<<<<<< HEAD
    bool draw(SkAnimateMaker&) override;

=======
    bool draw(SkAnimateMaker& ) override;
>>>>>>> miniblink49
private:
    SkDrawRect* rect;
    SkDrawPath* path;
};

#endif // SkDrawClip_DEFINED
