
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#ifndef SkDisplayEvents_DEFINED
#define SkDisplayEvents_DEFINED

#include "SkDisplayEvent.h"
#include "SkEvent.h"
=======

#ifndef SkDisplayEvents_DEFINED
#define SkDisplayEvents_DEFINED

#include "SkEvent.h"
#include "SkDisplayEvent.h"
>>>>>>> miniblink49

struct SkEventState {
    SkEventState();
    int fCode;
    SkBool fDisable;
    SkDisplayable* fDisplayable;
    SkScalar fX;
    SkScalar fY;
};

class SkEvents {
public:
    SkEvents();
    ~SkEvents();
    void addEvent(SkDisplayEvent* evt) { *fEvents.append() = evt; }
<<<<<<< HEAD
    bool doEvent(SkAnimateMaker&, SkDisplayEvent::Kind, SkEventState*);
#ifdef SK_DUMP_ENABLED
    void dump(SkAnimateMaker&);
#endif
    void reset()
    {
        fEvents.reset();
    }
    void removeEvent(SkDisplayEvent::Kind kind, SkEventState*);

=======
    bool doEvent(SkAnimateMaker& , SkDisplayEvent::Kind , SkEventState* );
#ifdef SK_DUMP_ENABLED
    void dump(SkAnimateMaker& );
#endif
    void reset() { fEvents.reset(); }
    void removeEvent(SkDisplayEvent::Kind kind, SkEventState* );
>>>>>>> miniblink49
private:
    SkTDDisplayEventArray fEvents;
    SkBool fError;
    friend class SkDisplayXMLParser;
};

#endif // SkDisplayEvents_DEFINED
