/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef GrOvalEffect_DEFINED
#define GrOvalEffect_DEFINED

#include "GrTypes.h"
#include "GrTypesPriv.h"
<<<<<<< HEAD
#include "SkRefCnt.h"
=======
>>>>>>> miniblink49

class GrFragmentProcessor;
struct SkRect;

namespace GrOvalEffect {
<<<<<<< HEAD
/**
     * Creates an effect that performs clipping against an oval.
     */
sk_sp<GrFragmentProcessor> Make(GrPrimitiveEdgeType, const SkRect&);
=======
    /**
     * Creates an effect that performs clipping against an oval.
     */
    GrFragmentProcessor* Create(GrPrimitiveEdgeType, const SkRect&);
>>>>>>> miniblink49
};

#endif
