/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkDrawDash_DEFINED
#define SkDrawDash_DEFINED

<<<<<<< HEAD
#include "SkIntArray.h"
#include "SkPaintPart.h"
=======
#include "SkPaintPart.h"
#include "SkIntArray.h"
>>>>>>> miniblink49

class SkDash : public SkDrawPathEffect {
    DECLARE_MEMBER_INFO(Dash);
    SkDash();
    virtual ~SkDash();
    SkPathEffect* getPathEffect() override;
<<<<<<< HEAD

=======
>>>>>>> miniblink49
private:
    SkTDScalarArray intervals;
    SkScalar phase;
};

#endif // SkDrawDash_DEFINED
