
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#ifndef SkDrawRectangle_DEFINED
#define SkDrawRectangle_DEFINED

#include "SkBoundable.h"
#include "SkMemberInfo.h"
#include "SkRect.h"

class SkRectToRect;

class SkDrawRect : public SkBoundable {
    DECLARE_DRAW_MEMBER_INFO(Rect);
    SkDrawRect();
    void dirty() override;
<<<<<<< HEAD
    bool draw(SkAnimateMaker&) override;
#ifdef SK_DUMP_ENABLED
    void dump(SkAnimateMaker*) override;
=======
    bool draw(SkAnimateMaker& ) override;
#ifdef SK_DUMP_ENABLED
    void dump(SkAnimateMaker* ) override;
>>>>>>> miniblink49
#endif
    SkDisplayable* getParent() const override;
    bool getProperty(int index, SkScriptValue* value) const override;
    bool setParent(SkDisplayable* parent) override;
<<<<<<< HEAD
    bool setProperty(int index, SkScriptValue&) override;

protected:
    SkRect fRect;
    SkDisplayable* fParent;

=======
    bool setProperty(int index, SkScriptValue& ) override;
protected:
    SkRect fRect;
    SkDisplayable* fParent;
>>>>>>> miniblink49
private:
    friend class SkDrawClip;
    friend class SkRectToRect;
    friend class SkSaveLayer;
    typedef SkBoundable INHERITED;
};

class SkRoundRect : public SkDrawRect {
    DECLARE_MEMBER_INFO(RoundRect);
    SkRoundRect();
<<<<<<< HEAD
    bool draw(SkAnimateMaker&) override;
#ifdef SK_DUMP_ENABLED
    void dump(SkAnimateMaker*) override;
=======
    bool draw(SkAnimateMaker& ) override;
#ifdef SK_DUMP_ENABLED
    void dump(SkAnimateMaker* ) override;
>>>>>>> miniblink49
#endif
protected:
    SkScalar rx;
    SkScalar ry;
<<<<<<< HEAD

=======
>>>>>>> miniblink49
private:
    typedef SkDrawRect INHERITED;
};

#endif // SkDrawRectangle_DEFINED
