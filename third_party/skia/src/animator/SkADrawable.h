
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#ifndef SkADrawable_DEFINED
#define SkADrawable_DEFINED

#include "SkDisplayEvent.h"
#include "SkDisplayable.h"
=======

#ifndef SkADrawable_DEFINED
#define SkADrawable_DEFINED

#include "SkDisplayable.h"
#include "SkDisplayEvent.h"
>>>>>>> miniblink49
#include "SkMath.h"

struct SkEventState;

<<<<<<< HEAD
class SkADrawable : public SkDisplayable {
public:
    virtual bool doEvent(SkDisplayEvent::Kind, SkEventState* state);
    virtual bool draw(SkAnimateMaker&) = 0;
=======
class SkADrawable :  public SkDisplayable {
public:
    virtual bool doEvent(SkDisplayEvent::Kind , SkEventState* state );
    virtual bool draw(SkAnimateMaker& ) = 0;
>>>>>>> miniblink49
    virtual void initialize();
    virtual bool isDrawable() const;
    virtual void setSteps(int steps);
};

#endif // SkADrawable_DEFINED
