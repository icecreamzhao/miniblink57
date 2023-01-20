/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkDisplayList_DEFINED
#define SkDisplayList_DEFINED

<<<<<<< HEAD
#include "SkIntArray.h"
#include "SkOperand.h"
=======
#include "SkOperand.h"
#include "SkIntArray.h"
>>>>>>> miniblink49
#include "SkRect.h"
#include "SkRefCnt.h"

class SkAnimateMaker;
class SkActive;
class SkApply;
class SkADrawable;
class SkGroup;

class SkDisplayList : public SkRefCnt {
public:
    SkDisplayList();
    virtual ~SkDisplayList();
<<<<<<< HEAD
    void append(SkActive*);
    void clear() { fDrawList.reset(); }
    int count() { return fDrawList.count(); }
    bool draw(SkAnimateMaker&, SkMSec time);
=======
    void append(SkActive* );
    void clear() { fDrawList.reset(); }
    int count() { return fDrawList.count(); }
    bool draw(SkAnimateMaker& , SkMSec time);
>>>>>>> miniblink49
#ifdef SK_DUMP_ENABLED
    void dump(SkAnimateMaker* maker);
    void dumpInner(SkAnimateMaker* maker);
    static int fIndent;
    static int fDumpIndex;
#endif
    int findGroup(SkADrawable* match, SkTDDrawableArray** list,
        SkGroup** parent, SkGroup** found, SkTDDrawableArray** grandList);
    SkADrawable* get(int index) { return fDrawList[index]; }
    SkMSec getTime() { return fInTime; }
    SkTDDrawableArray* getDrawList() { return &fDrawList; }
    void hardReset();
    virtual bool onIRect(const SkIRect& r);
    void reset();
<<<<<<< HEAD
    void remove(SkActive*);
#ifdef SK_DEBUG
    void validate();
#else
    void validate()
    {
    }
#endif
    static int SearchForMatch(SkADrawable* match, SkTDDrawableArray** list,
        SkGroup** parent, SkGroup** found, SkTDDrawableArray** grandList);
    static bool SearchGroupForMatch(SkADrawable* draw, SkADrawable* match,
        SkTDDrawableArray** list, SkGroup** parent, SkGroup** found, SkTDDrawableArray** grandList,
        int& index);

=======
    void remove(SkActive* );
#ifdef SK_DEBUG
    void validate();
#else
    void validate() {}
#endif
    static int SearchForMatch(SkADrawable* match, SkTDDrawableArray** list,
        SkGroup** parent, SkGroup** found, SkTDDrawableArray**grandList);
    static bool SearchGroupForMatch(SkADrawable* draw, SkADrawable* match,
        SkTDDrawableArray** list, SkGroup** parent, SkGroup** found, SkTDDrawableArray** grandList,
        int &index);
>>>>>>> miniblink49
public:
    SkIRect fBounds;
    SkIRect fInvalBounds;
    bool fDrawBounds;
    bool fHasUnion;
    bool fUnionBounds;
<<<<<<< HEAD

=======
>>>>>>> miniblink49
private:
    SkTDDrawableArray fDrawList;
    SkTDActiveArray fActiveList;
    SkMSec fInTime;
    friend class SkEvents;
};

#endif // SkDisplayList_DEFINED
