
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#ifndef SkDisplayAdd_DEFINED
#define SkDisplayAdd_DEFINED

#include "SkADrawable.h"
#include "SkMemberInfo.h"

class SkAdd : public SkADrawable {
    DECLARE_MEMBER_INFO(Add);
    SkAdd();

    enum Mode {
        kMode_indirect,
        kMode_immediate
    };

<<<<<<< HEAD
    SkDisplayable* deepCopy(SkAnimateMaker*) override;
    bool draw(SkAnimateMaker&) override;
#ifdef SK_DUMP_ENABLED
    void dump(SkAnimateMaker*) override;
#endif
    bool enable(SkAnimateMaker&) override;
    bool hasEnable() const override;
    void initialize() override;
    bool isDrawable() const override;

protected:
    //  struct _A {
    Mode mode;
    int32_t offset;
    SkADrawable* use;
    SkADrawable* where; // if nullptr, offset becomes index
    //  } A;
=======
    SkDisplayable* deepCopy(SkAnimateMaker* ) override;
    bool draw(SkAnimateMaker& ) override;
#ifdef SK_DUMP_ENABLED
    void dump(SkAnimateMaker* ) override;
#endif
    bool enable(SkAnimateMaker& ) override;
    bool hasEnable() const override;
    void initialize() override;
    bool isDrawable() const override;
protected:
//  struct _A {
        Mode mode;
        int32_t offset;
        SkADrawable* use;
        SkADrawable* where;  // if NULL, offset becomes index
//  } A;
>>>>>>> miniblink49
private:
    typedef SkADrawable INHERITED;
};

class SkClear : public SkDisplayable {
<<<<<<< HEAD
    virtual bool enable(SkAnimateMaker&);
=======
    virtual bool enable(SkAnimateMaker& );
>>>>>>> miniblink49
};

class SkMove : public SkAdd {
    DECLARE_MEMBER_INFO(Move);
<<<<<<< HEAD

=======
>>>>>>> miniblink49
private:
    typedef SkAdd INHERITED;
};

class SkRemove : public SkAdd {
    DECLARE_MEMBER_INFO(Remove);
    SkRemove();
<<<<<<< HEAD

protected:
    SkBool fDelete;

=======
protected:
    SkBool fDelete;
>>>>>>> miniblink49
private:
    friend class SkAdd;
    typedef SkAdd INHERITED;
};

class SkReplace : public SkAdd {
    DECLARE_MEMBER_INFO(Replace);
<<<<<<< HEAD

=======
>>>>>>> miniblink49
private:
    typedef SkAdd INHERITED;
};

#endif // SkDisplayAdd_DEFINED
