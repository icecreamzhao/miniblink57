
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#ifndef SkDisplayInclude_DEFINED
#define SkDisplayInclude_DEFINED

#include "SkDisplayable.h"
#include "SkMemberInfo.h"

class SkInclude : public SkDisplayable {
    DECLARE_MEMBER_INFO(Include);
<<<<<<< HEAD
    void onEndElement(SkAnimateMaker&) override;
    bool enable(SkAnimateMaker&) override;
    bool hasEnable() const override;

=======
    void onEndElement(SkAnimateMaker & ) override;
    bool enable(SkAnimateMaker & ) override;
    bool hasEnable() const override;
>>>>>>> miniblink49
protected:
    SkString src;
};

#endif // SkDisplayInclude_DEFINED
