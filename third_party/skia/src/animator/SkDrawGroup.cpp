
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#include "SkDrawGroup.h"
#include "SkAnimateMaker.h"
#include "SkAnimatorScript.h"
#include "SkCanvas.h"
#include "SkDisplayApply.h"
#include "SkPaint.h"
#ifdef SK_DEBUG
#include "SkDisplayList.h"
#endif

#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkGroup::fInfo[] = {
    SK_MEMBER(condition, String),
    SK_MEMBER(enableCondition, String)
};

#endif

DEFINE_GET_MEMBER(SkGroup);

<<<<<<< HEAD
SkGroup::SkGroup()
    : fParentList(nullptr)
    , fOriginal(nullptr)
{
}

SkGroup::~SkGroup()
{
    if (fOriginal) // has been copied
=======
SkGroup::SkGroup() : fParentList(NULL), fOriginal(NULL) {
}

SkGroup::~SkGroup() {
    if (fOriginal)  // has been copied
>>>>>>> miniblink49
        return;
    int index = 0;
    int max = fCopies.count() << 5;
    for (SkADrawable** ptr = fChildren.begin(); ptr < fChildren.end(); ptr++) {
        if (index >= max || markedForDelete(index))
            delete *ptr;
<<<<<<< HEAD
        //      else {
        //          SkApply* apply = (SkApply*) *ptr;
        //          SkASSERT(apply->isApply());
        //          SkASSERT(apply->getScope());
        //          delete apply->getScope();
        //      }
=======
//      else {
//          SkApply* apply = (SkApply*) *ptr;
//          SkASSERT(apply->isApply());
//          SkASSERT(apply->getScope());
//          delete apply->getScope();
//      }
>>>>>>> miniblink49
        index++;
    }
}

<<<<<<< HEAD
bool SkGroup::addChild(SkAnimateMaker&, SkDisplayable* child)
{
    SkASSERT(child);
    //  SkASSERT(child->isDrawable());
    *fChildren.append() = (SkADrawable*)child;
    if (child->isGroup()) {
        SkGroup* groupie = (SkGroup*)child;
        SkASSERT(groupie->fParentList == nullptr);
=======
bool SkGroup::addChild(SkAnimateMaker& , SkDisplayable* child) {
    SkASSERT(child);
//  SkASSERT(child->isDrawable());
    *fChildren.append() = (SkADrawable*) child;
    if (child->isGroup()) {
        SkGroup* groupie = (SkGroup*) child;
        SkASSERT(groupie->fParentList == NULL);
>>>>>>> miniblink49
        groupie->fParentList = &fChildren;
    }
    return true;
}

<<<<<<< HEAD
bool SkGroup::contains(SkDisplayable* match)
{
=======
bool SkGroup::contains(SkDisplayable* match) {
>>>>>>> miniblink49
    for (SkADrawable** ptr = fChildren.begin(); ptr < fChildren.end(); ptr++) {
        SkADrawable* drawable = *ptr;
        if (drawable == match || drawable->contains(match))
            return true;
    }
    return false;
}

<<<<<<< HEAD
SkGroup* SkGroup::copy()
{
=======
SkGroup* SkGroup::copy() {
>>>>>>> miniblink49
    SkGroup* result = new SkGroup();
    result->fOriginal = this;
    result->fChildren = fChildren;
    return result;
}

<<<<<<< HEAD
SkBool SkGroup::copySet(int index)
{
    return (fCopies[index >> 5] & 1 << (index & 0x1f)) != 0;
}

SkDisplayable* SkGroup::deepCopy(SkAnimateMaker* maker)
{
=======
SkBool SkGroup::copySet(int index) {
    return (fCopies[index >> 5] & 1 << (index & 0x1f)) != 0;
}

SkDisplayable* SkGroup::deepCopy(SkAnimateMaker* maker) {
>>>>>>> miniblink49
    SkDisplayable* copy = INHERITED::deepCopy(maker);
    for (SkADrawable** ptr = fChildren.begin(); ptr < fChildren.end(); ptr++) {
        SkDisplayable* displayable = (SkDisplayable*)*ptr;
        SkDisplayable* deeperCopy = displayable->deepCopy(maker);
        ((SkGroup*)copy)->addChild(*maker, deeperCopy);
    }
    return copy;
}

<<<<<<< HEAD
bool SkGroup::doEvent(SkDisplayEvent::Kind kind, SkEventState* state)
{
=======
bool SkGroup::doEvent(SkDisplayEvent::Kind kind, SkEventState* state) {
>>>>>>> miniblink49
    bool handled = false;
    for (SkADrawable** ptr = fChildren.begin(); ptr < fChildren.end(); ptr++) {
        SkADrawable* drawable = *ptr;
        if (drawable->isDrawable() == false)
            continue;
        handled |= drawable->doEvent(kind, state);
    }
    return handled;
}

<<<<<<< HEAD
bool SkGroup::draw(SkAnimateMaker& maker)
{
=======
bool SkGroup::draw(SkAnimateMaker& maker) {
>>>>>>> miniblink49
    bool conditionTrue = ifCondition(maker, this, condition);
    bool result = false;
    for (SkADrawable** ptr = fChildren.begin(); ptr < fChildren.end(); ptr++) {
        SkADrawable* drawable = *ptr;
        if (drawable->isDrawable() == false)
            continue;
        if (conditionTrue == false) {
            if (drawable->isApply())
<<<<<<< HEAD
                ((SkApply*)drawable)->disable();
=======
                ((SkApply*) drawable)->disable();
>>>>>>> miniblink49
            continue;
        }
        maker.validate();
        result |= drawable->draw(maker);
        maker.validate();
    }
    return result;
}

#ifdef SK_DUMP_ENABLED
<<<<<<< HEAD
void SkGroup::dump(SkAnimateMaker* maker)
{
=======
void SkGroup::dump(SkAnimateMaker* maker) {
>>>>>>> miniblink49
    dumpBase(maker);
    if (condition.size() > 0)
        SkDebugf("condition=\"%s\" ", condition.c_str());
    if (enableCondition.size() > 0)
        SkDebugf("enableCondition=\"%s\" ", enableCondition.c_str());
    dumpDrawables(maker);
}

<<<<<<< HEAD
void SkGroup::dumpDrawables(SkAnimateMaker* maker)
{
=======
void SkGroup::dumpDrawables(SkAnimateMaker* maker) {
>>>>>>> miniblink49
    SkDisplayList::fIndent += 4;
    int save = SkDisplayList::fDumpIndex;
    SkDisplayList::fDumpIndex = 0;
    bool closedYet = false;
    for (SkADrawable** ptr = fChildren.begin(); ptr < fChildren.end(); ptr++) {
        if (closedYet == false) {
            closedYet = true;
            SkDebugf(">\n");
        }
        SkADrawable* drawable = *ptr;
        drawable->dump(maker);
        SkDisplayList::fDumpIndex++;
    }
    SkDisplayList::fIndent -= 4;
    SkDisplayList::fDumpIndex = save;
    if (closedYet) //we had children, now it's time to close the group
        dumpEnd(maker);
<<<<<<< HEAD
    else //no children
        SkDebugf("/>\n");
}

void SkGroup::dumpEvents()
{
=======
    else    //no children
        SkDebugf("/>\n");
}

void SkGroup::dumpEvents() {
>>>>>>> miniblink49
    for (SkADrawable** ptr = fChildren.begin(); ptr < fChildren.end(); ptr++) {
        SkADrawable* drawable = *ptr;
        drawable->dumpEvents();
    }
}
#endif

<<<<<<< HEAD
bool SkGroup::enable(SkAnimateMaker& maker)
{
=======
bool SkGroup::enable(SkAnimateMaker& maker ) {
>>>>>>> miniblink49
    reset();
    for (SkADrawable** ptr = fChildren.begin(); ptr < fChildren.end(); ptr++) {
        SkADrawable* drawable = *ptr;
        if (ifCondition(maker, drawable, enableCondition) == false)
            continue;
        drawable->enable(maker);
    }
<<<<<<< HEAD
    return true; // skip add; already added so that scope is findable by children
}

int SkGroup::findGroup(SkADrawable* match, SkTDDrawableArray** list,
    SkGroup** parent, SkGroup** found, SkTDDrawableArray** grandList)
{
=======
    return true;    // skip add; already added so that scope is findable by children
}

int SkGroup::findGroup(SkADrawable* match,  SkTDDrawableArray** list,
                 SkGroup** parent, SkGroup** found, SkTDDrawableArray** grandList) {
>>>>>>> miniblink49
    *list = &fChildren;
    for (SkADrawable** ptr = fChildren.begin(); ptr < fChildren.end(); ptr++) {
        SkADrawable* drawable = *ptr;
        if (drawable->isGroup()) {
<<<<<<< HEAD
            SkGroup* childGroup = (SkGroup*)drawable;
=======
            SkGroup* childGroup = (SkGroup*) drawable;
>>>>>>> miniblink49
            if (childGroup->fOriginal == match)
                goto foundMatch;
        }
        if (drawable == match) {
<<<<<<< HEAD
        foundMatch:
            *parent = this;
            return (int)(ptr - fChildren.begin());
=======
foundMatch:
            *parent = this;
            return (int) (ptr - fChildren.begin());
>>>>>>> miniblink49
        }
    }
    *grandList = &fChildren;
    return SkDisplayList::SearchForMatch(match, list, parent, found, grandList);
}

<<<<<<< HEAD
bool SkGroup::hasEnable() const
{
=======
bool SkGroup::hasEnable() const {
>>>>>>> miniblink49
    return true;
}

bool SkGroup::ifCondition(SkAnimateMaker& maker, SkADrawable*,
<<<<<<< HEAD
    SkString& conditionString)
{
=======
        SkString& conditionString) {
>>>>>>> miniblink49
    if (conditionString.size() == 0)
        return true;
    int32_t result;
    bool success = SkAnimatorScript::EvaluateInt(maker, this, conditionString.c_str(), &result);
#ifdef SK_DUMP_ENABLED
    if (maker.fDumpGConditions) {
        SkDebugf("group: ");
        dumpBase(&maker);
        SkDebugf("condition=%s ", conditionString.c_str());
        if (success == false)
            SkDebugf("(script failed)\n");
        else
            SkDebugf("success=%s\n", result != 0 ? "true" : "false");
    }
#endif
    return success && result != 0;
}

<<<<<<< HEAD
void SkGroup::initialize()
{
=======
void SkGroup::initialize() {
>>>>>>> miniblink49
    for (SkADrawable** ptr = fChildren.begin(); ptr < fChildren.end(); ptr++) {
        SkADrawable* drawable = *ptr;
        if (drawable->isDrawable() == false)
            continue;
        drawable->initialize();
    }
}

<<<<<<< HEAD
void SkGroup::markCopyClear(int index)
{
=======
void SkGroup::markCopyClear(int index) {
>>>>>>> miniblink49
    if (index < 0)
        index = fChildren.count();
    fCopies[index >> 5] &= ~(1 << (index & 0x1f));
}

<<<<<<< HEAD
void SkGroup::markCopySet(int index)
{
=======
void SkGroup::markCopySet(int index) {
>>>>>>> miniblink49
    if (index < 0)
        index = fChildren.count();
    fCopies[index >> 5] |= 1 << (index & 0x1f);
}

<<<<<<< HEAD
void SkGroup::markCopySize(int index)
{
=======
void SkGroup::markCopySize(int index) {
>>>>>>> miniblink49
    if (index < 0)
        index = fChildren.count() + 1;
    int oldLongs = fCopies.count();
    int newLongs = (index >> 5) + 1;
    if (oldLongs < newLongs) {
        fCopies.setCount(newLongs);
        memset(&fCopies[oldLongs], 0, (newLongs - oldLongs) << 2);
    }
}

<<<<<<< HEAD
void SkGroup::reset()
{
    if (fOriginal) // has been copied
=======
void SkGroup::reset() {
    if (fOriginal)  // has been copied
>>>>>>> miniblink49
        return;
    int index = 0;
    int max = fCopies.count() << 5;
    for (SkADrawable** ptr = fChildren.begin(); ptr < fChildren.end(); ptr++) {
        if (index >= max || copySet(index) == false)
            continue;
<<<<<<< HEAD
        SkApply* apply = (SkApply*)*ptr;
=======
        SkApply* apply = (SkApply*) *ptr;
>>>>>>> miniblink49
        SkASSERT(apply->isApply());
        SkASSERT(apply->getScope());
        *ptr = apply->getScope();
        markCopyClear(index);
        index++;
    }
}

<<<<<<< HEAD
bool SkGroup::resolveIDs(SkAnimateMaker& maker, SkDisplayable* orig, SkApply* apply)
{
    SkGroup* original = (SkGroup*)orig;
=======
bool SkGroup::resolveIDs(SkAnimateMaker& maker, SkDisplayable* orig, SkApply* apply) {
    SkGroup* original = (SkGroup*) orig;
>>>>>>> miniblink49
    SkTDDrawableArray& originalChildren = original->fChildren;
    SkADrawable** originalPtr = originalChildren.begin();
    SkADrawable** ptr = fChildren.begin();
    SkADrawable** end = fChildren.end();
<<<<<<< HEAD
    SkADrawable** origChild = ((SkGroup*)orig)->fChildren.begin();
=======
    SkADrawable** origChild = ((SkGroup*) orig)->fChildren.begin();
>>>>>>> miniblink49
    while (ptr < end) {
        SkADrawable* drawable = *ptr++;
        maker.resolveID(drawable, *origChild++);
        if (drawable->resolveIDs(maker, *originalPtr++, apply) == true)
            return true; // failed
    }
    return false;
}

<<<<<<< HEAD
void SkGroup::setSteps(int steps)
{
=======
void SkGroup::setSteps(int steps) {
>>>>>>> miniblink49
    for (SkADrawable** ptr = fChildren.begin(); ptr < fChildren.end(); ptr++) {
        SkADrawable* drawable = *ptr;
        if (drawable->isDrawable() == false)
            continue;
        drawable->setSteps(steps);
    }
}

#ifdef SK_DEBUG
<<<<<<< HEAD
void SkGroup::validate()
{
=======
void SkGroup::validate() {
>>>>>>> miniblink49
    for (SkADrawable** ptr = fChildren.begin(); ptr < fChildren.end(); ptr++) {
        SkADrawable* drawable = *ptr;
        drawable->validate();
    }
}
#endif

#if SK_USE_CONDENSED_INFO == 0

const SkMemberInfo SkSave::fInfo[] = {
    SK_MEMBER_INHERITED
};

#endif

DEFINE_GET_MEMBER(SkSave);

<<<<<<< HEAD
bool SkSave::draw(SkAnimateMaker& maker)
{
=======
bool SkSave::draw(SkAnimateMaker& maker) {
>>>>>>> miniblink49
    maker.fCanvas->save();
    SkPaint* save = maker.fPaint;
    SkPaint local = SkPaint(*maker.fPaint);
    maker.fPaint = &local;
    bool result = INHERITED::draw(maker);
    maker.fPaint = save;
    maker.fCanvas->restore();
    return result;
}
