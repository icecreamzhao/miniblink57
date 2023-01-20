
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#ifndef SkPostParts_DEFINED
#define SkPostParts_DEFINED

#include "SkDisplayInput.h"

class SkPost;

<<<<<<< HEAD
class SkDataInput : public SkInput {
=======
class SkDataInput: public SkInput {
>>>>>>> miniblink49
    DECLARE_MEMBER_INFO(DataInput);
    SkDataInput();
    bool add();
    void dirty() override;
    SkDisplayable* getParent() const override;
<<<<<<< HEAD
    void onEndElement(SkAnimateMaker&) override;
    bool setParent(SkDisplayable*) override;

=======
    void onEndElement(SkAnimateMaker& ) override;
    bool setParent(SkDisplayable* ) override;
>>>>>>> miniblink49
protected:
    SkPost* fParent;
    typedef SkInput INHERITED;
    friend class SkPost;
};

#endif // SkPostParts_DEFINED
