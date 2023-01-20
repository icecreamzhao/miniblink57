
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#ifndef SkDrawSaveLayer_DEFINED
#define SkDrawSaveLayer_DEFINED

#include "SkDrawGroup.h"
#include "SkMemberInfo.h"

class SkDrawPaint;
class SkDrawRect;

class SkSaveLayer : public SkGroup {
    DECLARE_MEMBER_INFO(SaveLayer);
    SkSaveLayer();
    virtual ~SkSaveLayer();
<<<<<<< HEAD
    bool draw(SkAnimateMaker&) override;
#ifdef SK_DUMP_ENABLED
    void dump(SkAnimateMaker*) override;
#endif
    void onEndElement(SkAnimateMaker&) override;

protected:
    SkDrawPaint* paint;
    SkDrawRect* bounds;

private:
    typedef SkGroup INHERITED;
=======
    bool draw(SkAnimateMaker& ) override;
#ifdef SK_DUMP_ENABLED
    void dump(SkAnimateMaker* ) override;
#endif
    void onEndElement(SkAnimateMaker& ) override;
protected:
    SkDrawPaint* paint;
    SkDrawRect* bounds;
private:
    typedef SkGroup INHERITED;

>>>>>>> miniblink49
};

#endif //SkDrawSaveLayer_DEFINED
