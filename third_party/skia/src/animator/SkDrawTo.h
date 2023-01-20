
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#ifndef SkDrawTo_DEFINED
#define SkDrawTo_DEFINED

#include "SkDrawGroup.h"
#include "SkMemberInfo.h"

class SkDrawBitmap;

class SkDrawTo : public SkGroup {
    DECLARE_MEMBER_INFO(DrawTo);
    SkDrawTo();
<<<<<<< HEAD
    //  virtual ~SkDrawTo();
    bool draw(SkAnimateMaker&) override;
#ifdef SK_DUMP_ENABLED
    void dump(SkAnimateMaker*) override;
=======
//  virtual ~SkDrawTo();
    bool draw(SkAnimateMaker& ) override;
#ifdef SK_DUMP_ENABLED
    void dump(SkAnimateMaker* ) override;
>>>>>>> miniblink49
#endif
protected:
    SkBool drawOnce;
    SkDrawBitmap* use;
<<<<<<< HEAD

=======
>>>>>>> miniblink49
private:
    typedef SkGroup INHERITED;
    SkBool fDrawnOnce;
};

#endif // SkDrawTo_DEFINED
