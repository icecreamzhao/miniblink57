/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkArithmeticMode_DEFINED
#define SkArithmeticMode_DEFINED

#include "SkFlattenable.h"
#include "SkScalar.h"
<<<<<<< HEAD
#include "SkXfermode.h"
=======

class SkXfermode;
>>>>>>> miniblink49

class SK_API SkArithmeticMode {
public:
    /**
     *  result = clamp[k1 * src * dst + k2 * src + k3 * dst + k4]
     *
<<<<<<< HEAD
=======
     *  src and dst are treated as being [0.0 .. 1.0]. The polynomial is
     *  evaluated on their unpremultiplied components.
     *
>>>>>>> miniblink49
     *  k1=k2=k3=0, k4=1.0 results in returning opaque white
     *  k1=k3=k4=0, k2=1.0 results in returning the src
     *  k1=k2=k4=0, k3=1.0 results in returning the dst
     */
<<<<<<< HEAD
    static sk_sp<SkXfermode> Make(SkScalar k1, SkScalar k2, SkScalar k3, SkScalar k4,
        bool enforcePMColor = true);
#ifdef SK_SUPPORT_LEGACY_XFERMODE_PTR
    static SkXfermode* Create(SkScalar k1, SkScalar k2,
        SkScalar k3, SkScalar k4,
        bool enforcePMColor = true)
    {
        return Make(k1, k2, k3, k4, enforcePMColor).release();
    }
#endif
=======
    static SkXfermode* Create(SkScalar k1, SkScalar k2,
                              SkScalar k3, SkScalar k4,
                              bool enforcePMColor = true);
>>>>>>> miniblink49

    SK_DECLARE_FLATTENABLE_REGISTRAR_GROUP();

private:
    SkArithmeticMode(); // can't be instantiated
};

#endif
