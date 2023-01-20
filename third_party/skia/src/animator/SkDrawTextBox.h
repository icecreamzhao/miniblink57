
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#ifndef SkDrawTextBox_DEFINED
#define SkDrawTextBox_DEFINED

#include "SkDrawRectangle.h"
#include "SkTextBox.h"

class SkDrawTextBox : public SkDrawRect {
    DECLARE_DRAW_MEMBER_INFO(TextBox);
    SkDrawTextBox();

    // overrides
<<<<<<< HEAD
    bool draw(SkAnimateMaker&) override;
#ifdef SK_DUMP_ENABLED
    void dump(SkAnimateMaker*) override;
#endif
    bool getProperty(int index, SkScriptValue* value) const override;
    bool setProperty(int index, SkScriptValue&) override;
=======
    bool draw(SkAnimateMaker& ) override;
#ifdef SK_DUMP_ENABLED
    void dump(SkAnimateMaker* ) override;
#endif
    bool getProperty(int index, SkScriptValue* value) const override;
    bool setProperty(int index, SkScriptValue& ) override;
>>>>>>> miniblink49

private:
    SkString fText;
    SkScalar fSpacingMul;
    SkScalar fSpacingAdd;
<<<<<<< HEAD
    int /*SkTextBox::Mode*/ mode;
=======
    int /*SkTextBox::Mode*/  mode;
>>>>>>> miniblink49
    int /*SkTextBox::SpacingAlign*/ spacingAlign;

    typedef SkDrawRect INHERITED;
};

#endif // SkDrawTextBox_DEFINED
