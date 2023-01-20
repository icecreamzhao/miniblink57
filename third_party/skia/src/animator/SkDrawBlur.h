/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkDrawBlur_DEFINED
#define SkDrawBlur_DEFINED

<<<<<<< HEAD
#include "SkBlurMaskFilter.h"
#include "SkPaintPart.h"
=======
#include "SkPaintPart.h"
#include "SkBlurMaskFilter.h"
>>>>>>> miniblink49

class SkDrawBlur : public SkDrawMaskFilter {
    DECLARE_DRAW_MEMBER_INFO(Blur);
    SkDrawBlur();
    SkMaskFilter* getMaskFilter() override;
<<<<<<< HEAD

=======
>>>>>>> miniblink49
protected:
    SkScalar fSigma;
    int /*SkBlurStyle*/ fBlurStyle;

    typedef SkDrawMaskFilter INHERITED;
};

#endif // SkDrawBlur_DEFINED
