
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#ifndef SkAnimateActive_DEFINED
#define SkAnimateActive_DEFINED

#include "SkDisplayApply.h"
<<<<<<< HEAD
#include "SkIntArray.h"
#include "SkOperandInterpolator.h"
=======
#include "SkOperandInterpolator.h"
#include "SkIntArray.h"
>>>>>>> miniblink49

class SkAnimateMaker;

class SkActive {
public:
<<<<<<< HEAD
    SkActive(SkApply&, SkAnimateMaker&);
    ~SkActive();
    void advance();
    void append(SkApply*);
=======
    SkActive(SkApply& , SkAnimateMaker& );
    ~SkActive();
    void advance();
    void append(SkApply* );
>>>>>>> miniblink49
    void calcDurations(int index);
    void create(SkADrawable* scope, SkMSec time);
    bool draw() { return immediate(false); }
    bool enable() { return immediate(true); }
<<<<<<< HEAD
    void init();
=======
    void init( );
>>>>>>> miniblink49
    SkMSec getTime(SkMSec inTime, int animatorIndex);
    void pickUp(SkActive* existing);
    void reset() { fDrawIndex = 0; }
    void setInterpolator(int index, SkOperand* from);
    void start();
#ifdef SK_DEBUG
    void validate();
#endif
private:
    void appendSave(int oldCount);
    void fixInterpolator(SkBool save);
    bool immediate(bool enable);
    bool initializeSave();
<<<<<<< HEAD
    void initState(SkApply*, int offset);
=======
    void initState(SkApply* , int offset);
>>>>>>> miniblink49
    void resetInterpolators();
    void resetState();
    void restoreInterpolatorValues(int index);
    void saveInterpolatorValues(int index);
    void setSteps(int steps);
    struct SkState {
<<<<<<< HEAD
        //      void bumpSave();
=======
//      void bumpSave();
>>>>>>> miniblink49
        SkMSec getRelativeTime(SkMSec time);
        SkApply::Mode fMode;
        SkApply::Transition fTransition;
        SkBool8 fPickup;
        SkBool8 fRestore;
        SkBool8 fStarted;
        SkBool8 fUnpostedEndEvent;
        int32_t fSteps;
        SkMSec fBegin;
        SkMSec fStartTime;
        SkMSec fDuration;
        SkMSec fSave;
        SkMSec fTicks;
    };
<<<<<<< HEAD
    SkActive& operator=(const SkActive&);
    SkTDArray<SkOperandInterpolator*> fInterpolators;
    SkApply& fApply;
    SkTDArray<SkState> fState; // one per animator
    SkTDOperandPtrArray fSaveRestore; // if apply has restore="true"
    SkTDOperandPtrArray fSaveInterpolators;
    SkTDAnimateArray fAnimators;
    SkMSec fMaxTime; // greatest of all animation durations; only used by immediate mode
=======
    SkActive& operator= (const SkActive& );
    SkTDArray<SkOperandInterpolator*> fInterpolators;
    SkApply& fApply;
    SkTDArray<SkState> fState;  // one per animator
    SkTDOperandPtrArray fSaveRestore;   // if apply has restore="true"
    SkTDOperandPtrArray fSaveInterpolators;
    SkTDAnimateArray fAnimators;
    SkMSec fMaxTime;    // greatest of all animation durations; only used by immediate mode
>>>>>>> miniblink49
    SkAnimateMaker& fMaker;
    int fDrawIndex;
    int fDrawMax;
    friend class SkApply;
};

#endif // SkAnimateActive_DEFINED
