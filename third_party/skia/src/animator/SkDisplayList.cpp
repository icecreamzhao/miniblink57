
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkDisplayList.h"
#include "SkADrawable.h"
=======

#include "SkDisplayList.h"
>>>>>>> miniblink49
#include "SkAnimateActive.h"
#include "SkAnimateBase.h"
#include "SkAnimateMaker.h"
#include "SkDisplayApply.h"
<<<<<<< HEAD
=======
#include "SkADrawable.h"
>>>>>>> miniblink49
#include "SkDrawGroup.h"
#include "SkDrawMatrix.h"
#include "SkInterpolator.h"
#include "SkTime.h"

<<<<<<< HEAD
SkDisplayList::SkDisplayList()
    : fDrawBounds(true)
    , fUnionBounds(false)
    , fInTime(0)
{
}

SkDisplayList::~SkDisplayList()
{
}

void SkDisplayList::append(SkActive* active)
{
    *fActiveList.append() = active;
}

bool SkDisplayList::draw(SkAnimateMaker& maker, SkMSec inTime)
{
=======
SkDisplayList::SkDisplayList() : fDrawBounds(true), fUnionBounds(false), fInTime(0) {
}

SkDisplayList::~SkDisplayList() {
}

void SkDisplayList::append(SkActive* active) {
    *fActiveList.append() = active;
}

bool SkDisplayList::draw(SkAnimateMaker& maker, SkMSec inTime) {
>>>>>>> miniblink49
    validate();
    fInTime = inTime;
    bool result = false;
    fInvalBounds.setEmpty();
    if (fDrawList.count()) {
        for (SkActive** activePtr = fActiveList.begin(); activePtr < fActiveList.end(); activePtr++) {
            SkActive* active = *activePtr;
            active->reset();
        }
        for (int index = 0; index < fDrawList.count(); index++) {
            SkADrawable* draw = fDrawList[index];
            draw->initialize(); // allow matrices to reset themselves
            SkASSERT(draw->isDrawable());
            validate();
            result |= draw->draw(maker);
        }
    }
    validate();
    return result;
}

int SkDisplayList::findGroup(SkADrawable* match, SkTDDrawableArray** list,
<<<<<<< HEAD
    SkGroup** parent, SkGroup** found, SkTDDrawableArray** grandList)
{
    *parent = nullptr;
=======
        SkGroup** parent, SkGroup** found, SkTDDrawableArray**grandList) {
    *parent = NULL;
>>>>>>> miniblink49
    *list = &fDrawList;
    *grandList = &fDrawList;
    return SearchForMatch(match, list, parent, found, grandList);
}

<<<<<<< HEAD
void SkDisplayList::hardReset()
{
=======
void SkDisplayList::hardReset() {
>>>>>>> miniblink49
    fDrawList.reset();
    fActiveList.reset();
}

<<<<<<< HEAD
bool SkDisplayList::onIRect(const SkIRect& r)
{
=======
bool SkDisplayList::onIRect(const SkIRect& r) {
>>>>>>> miniblink49
    fBounds = r;
    return fDrawBounds;
}

int SkDisplayList::SearchForMatch(SkADrawable* match, SkTDDrawableArray** list,
<<<<<<< HEAD
    SkGroup** parent, SkGroup** found, SkTDDrawableArray** grandList)
{
    *found = nullptr;
=======
        SkGroup** parent, SkGroup** found, SkTDDrawableArray**grandList) {
    *found = NULL;
>>>>>>> miniblink49
    for (int index = 0; index < (*list)->count(); index++) {
        SkADrawable* draw = (**list)[index];
        if (draw == match)
            return index;
        if (draw->isApply()) {
<<<<<<< HEAD
            SkApply* apply = (SkApply*)draw;
=======
            SkApply* apply = (SkApply*) draw;
>>>>>>> miniblink49
            if (apply->scope == match)
                return index;
            if (apply->scope->isGroup() && SearchGroupForMatch(apply->scope, match, list, parent, found, grandList, index))
                return index;
            if (apply->mode == SkApply::kMode_create) {
                for (SkADrawable** ptr = apply->fScopes.begin(); ptr < apply->fScopes.end(); ptr++) {
                    SkADrawable* scope = *ptr;
                    if (scope == match)
                        return index;
                    //perhaps should call SearchGroupForMatch here as well (on scope)
                }
            }
        }
        if (draw->isGroup() && SearchGroupForMatch(draw, match, list, parent, found, grandList, index))
            return index;
<<<<<<< HEAD
=======

>>>>>>> miniblink49
    }
    return -1;
}

bool SkDisplayList::SearchGroupForMatch(SkADrawable* draw, SkADrawable* match, SkTDDrawableArray** list,
<<<<<<< HEAD
    SkGroup** parent, SkGroup** found, SkTDDrawableArray** grandList, int& index)
{
    SkGroup* group = (SkGroup*)draw;
    if (group->getOriginal() == match)
        return true;
    SkTDDrawableArray* saveList = *list;
    int groupIndex = group->findGroup(match, list, parent, found, grandList);
    if (groupIndex >= 0) {
        *found = group;
        index = groupIndex;
        return true;
    }
    *list = saveList;
    return false;
}

void SkDisplayList::reset()
{
=======
        SkGroup** parent, SkGroup** found, SkTDDrawableArray** grandList, int &index) {
            SkGroup* group = (SkGroup*) draw;
            if (group->getOriginal() == match)
                return true;
            SkTDDrawableArray* saveList = *list;
            int groupIndex = group->findGroup(match, list, parent, found, grandList);
            if (groupIndex >= 0) {
                *found = group;
                index = groupIndex;
                return true;
            }
            *list = saveList;
            return false;
        }

void SkDisplayList::reset() {
>>>>>>> miniblink49
    for (int index = 0; index < fDrawList.count(); index++) {
        SkADrawable* draw = fDrawList[index];
        if (draw->isApply() == false)
            continue;
<<<<<<< HEAD
        SkApply* apply = (SkApply*)draw;
=======
        SkApply* apply = (SkApply*) draw;
>>>>>>> miniblink49
        apply->reset();
    }
}

<<<<<<< HEAD
void SkDisplayList::remove(SkActive* active)
{
    int index = fActiveList.find(active);
    SkASSERT(index >= 0);
    fActiveList.remove(index); // !!! could use shuffle instead
=======
void SkDisplayList::remove(SkActive* active) {
    int index = fActiveList.find(active);
    SkASSERT(index >= 0);
    fActiveList.remove(index);  // !!! could use shuffle instead
>>>>>>> miniblink49
    SkASSERT(fActiveList.find(active) < 0);
}

#ifdef SK_DUMP_ENABLED
int SkDisplayList::fDumpIndex;
int SkDisplayList::fIndent;

<<<<<<< HEAD
void SkDisplayList::dump(SkAnimateMaker* maker)
{
=======
void SkDisplayList::dump(SkAnimateMaker* maker) {
>>>>>>> miniblink49
    fIndent = 0;
    dumpInner(maker);
}

<<<<<<< HEAD
void SkDisplayList::dumpInner(SkAnimateMaker* maker)
{
=======
void SkDisplayList::dumpInner(SkAnimateMaker* maker) {
>>>>>>> miniblink49
    for (int index = 0; index < fDrawList.count(); index++) {
        fDumpIndex = index;
        fDrawList[fDumpIndex]->dump(maker);
    }
}

#endif

#ifdef SK_DEBUG
<<<<<<< HEAD
void SkDisplayList::validate()
{
=======
void SkDisplayList::validate() {
>>>>>>> miniblink49
    for (int index = 0; index < fDrawList.count(); index++) {
        SkADrawable* draw = fDrawList[index];
        draw->validate();
    }
}
#endif
