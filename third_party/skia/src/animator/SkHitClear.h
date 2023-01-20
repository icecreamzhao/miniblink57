
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#ifndef SkHitClear_DEFINED
#define SkHitClear_DEFINED

#include "SkDisplayable.h"
#include "SkMemberInfo.h"
#include "SkTypedArray.h"

class SkHitClear : public SkDisplayable {
    DECLARE_MEMBER_INFO(HitClear);
<<<<<<< HEAD
    bool enable(SkAnimateMaker&) override;
    bool hasEnable() const override;

=======
    bool enable(SkAnimateMaker& ) override;
    bool hasEnable() const override;
>>>>>>> miniblink49
private:
    SkTDDisplayableArray targets;
};

#endif // SkHitClear_DEFINED
