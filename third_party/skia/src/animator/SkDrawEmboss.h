
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#ifndef SkDrawEmboss_DEFINED
#define SkDrawEmboss_DEFINED

#include "SkDrawBlur.h"

class SkDrawEmboss : public SkDrawMaskFilter {
    DECLARE_DRAW_MEMBER_INFO(Emboss);
    SkDrawEmboss();
    SkMaskFilter* getMaskFilter() override;
<<<<<<< HEAD

protected:
    SkTDScalarArray fDirection;
    SkScalar fSigma;
    SkScalar fAmbient;
    SkScalar fSpecular;
=======
protected:
    SkTDScalarArray fDirection;
    SkScalar        fSigma;
    SkScalar        fAmbient;
    SkScalar        fSpecular;
>>>>>>> miniblink49

    typedef SkDrawMaskFilter INHERITED;
};

#endif // SkDrawEmboss_DEFINED
