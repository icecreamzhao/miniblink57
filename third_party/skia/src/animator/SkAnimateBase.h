
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#ifndef SkAnimateBase_DEFINED
#define SkAnimateBase_DEFINED

#include "SkDisplayable.h"
#include "SkMath.h"
#include "SkMemberInfo.h"
#include "SkTypedArray.h"

class SkApply;
class SkADrawable;

class SkAnimateBase : public SkDisplayable {
public:
    DECLARE_MEMBER_INFO(AnimateBase);
    SkAnimateBase();
    virtual ~SkAnimateBase();
    virtual int components();
<<<<<<< HEAD
    SkDisplayable* deepCopy(SkAnimateMaker*) override;
    void dirty() override;
#ifdef SK_DUMP_ENABLED
    void dump(SkAnimateMaker*) override;
#endif
    int entries()
    {
        return fValues.count() / components();
    }
=======
    SkDisplayable* deepCopy(SkAnimateMaker* ) override;
    void dirty() override;
#ifdef SK_DUMP_ENABLED
    void dump(SkAnimateMaker* ) override;
#endif
    int entries() { return fValues.count() / components(); }
>>>>>>> miniblink49
    virtual bool hasExecute() const;
    bool isDynamic() const { return SkToBool(fDynamic); }
    SkDisplayable* getParent() const override;
    bool getProperty(int index, SkScriptValue* value) const override;
    SkMSec getStart() const { return fStart; }
    SkOperand* getValues() { return fValues.begin(); }
    SkDisplayTypes getValuesType() { return fValues.getType(); }
<<<<<<< HEAD
    void onEndElement(SkAnimateMaker&) override;
    void packARGB(SkScalar[], int count, SkTDOperandArray*);
    virtual void refresh(SkAnimateMaker&);
    void setChanged(bool changed) { fChanged = changed; }
    void setHasEndEvent() { fHasEndEvent = true; }
    bool setParent(SkDisplayable*) override;
    bool setProperty(int index, SkScriptValue& value) override;
    void setTarget(SkAnimateMaker&);
    virtual bool targetNeedsInitialization() const;

=======
    void onEndElement(SkAnimateMaker& ) override;
    void packARGB(SkScalar [], int count, SkTDOperandArray* );
    virtual void refresh(SkAnimateMaker& );
    void setChanged(bool changed) { fChanged = changed; }
    void setHasEndEvent() { fHasEndEvent = true; }
    bool setParent(SkDisplayable* ) override;
    bool setProperty(int index, SkScriptValue& value) override;
    void setTarget(SkAnimateMaker& );
    virtual bool targetNeedsInitialization() const;
>>>>>>> miniblink49
protected:
    SkMSec begin;
    SkTDScalarArray blend;
    SkMSec dur;
    // !!! make field part of a union with fFieldInfo, or fValues, something known later?
    SkString field; // temporary; once target is known, this is reset
    SkString formula;
    SkString from;
    SkString lval;
    SkScalar repeat;
<<<<<<< HEAD
    SkString target; // temporary; once target is known, this is reset
=======
    SkString target;    // temporary; once target is known, this is reset
>>>>>>> miniblink49
    SkString to;
    SkApply* fApply;
    const SkMemberInfo* fFieldInfo;
    int fFieldOffset;
<<<<<<< HEAD
    SkMSec fStart; // corrected time when this apply was enabled
    SkADrawable* fTarget;
    SkTypedArray fValues;
    unsigned fChanged : 1; // true when value referenced by script has changed
    unsigned fDelayed : 1; // enabled, but undrawn pending delay
    unsigned fDynamic : 1;
    unsigned fHasEndEvent : 1;
    unsigned fHasValues : 1; // set if 'values' passed instead of 'to'
=======
    SkMSec fStart;  // corrected time when this apply was enabled
    SkADrawable* fTarget;
    SkTypedArray fValues;
    unsigned fChanged : 1; // true when value referenced by script has changed
    unsigned fDelayed : 1;  // enabled, but undrawn pending delay
    unsigned fDynamic : 1;
    unsigned fHasEndEvent : 1;
    unsigned fHasValues : 1;        // set if 'values' passed instead of 'to'
>>>>>>> miniblink49
    unsigned fMirror : 1;
    unsigned fReset : 1;
    unsigned fResetPending : 1;
    unsigned fTargetIsScope : 1;
<<<<<<< HEAD

=======
>>>>>>> miniblink49
private:
    typedef SkDisplayable INHERITED;
    friend class SkActive;
    friend class SkApply;
    friend class SkDisplayList;
};

#endif // SkAnimateBase_DEFINED
