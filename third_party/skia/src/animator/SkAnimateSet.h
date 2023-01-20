
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#ifndef SkAnimateSet_DEFINED
#define SkAnimateSet_DEFINED

#include "SkAnimate.h"

class SkSet : public SkAnimate {
    DECLARE_MEMBER_INFO(Set);
    SkSet();
#ifdef SK_DUMP_ENABLED
<<<<<<< HEAD
    void dump(SkAnimateMaker*) override;
#endif
    void onEndElement(SkAnimateMaker&) override;
    void refresh(SkAnimateMaker&) override;

=======
    void dump(SkAnimateMaker* ) override;
#endif
    void onEndElement(SkAnimateMaker& ) override;
    void refresh(SkAnimateMaker& ) override;
>>>>>>> miniblink49
private:
    typedef SkAnimate INHERITED;
};

#endif // SkAnimateSet_DEFINED
