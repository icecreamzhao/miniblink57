
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#ifndef SkHitTest_DEFINED
#define SkHitTest_DEFINED

#include "SkADrawable.h"
#include "SkTypedArray.h"

class SkHitTest : public SkADrawable {
    DECLARE_MEMBER_INFO(HitTest);
    SkHitTest();
<<<<<<< HEAD
    bool draw(SkAnimateMaker&) override;
    bool enable(SkAnimateMaker&) override;
    bool hasEnable() const override;
    const SkMemberInfo* preferredChild(SkDisplayTypes type) override;

=======
    bool draw(SkAnimateMaker& ) override;
    bool enable(SkAnimateMaker& ) override;
    bool hasEnable() const override;
    const SkMemberInfo* preferredChild(SkDisplayTypes type) override;
>>>>>>> miniblink49
private:
    SkTDDisplayableArray bullets;
    SkTDIntArray hits;
    SkTDDisplayableArray targets;
    SkBool value;
};

#endif // SkHitTest_DEFINED
