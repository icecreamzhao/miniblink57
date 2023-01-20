
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#ifndef SkDump_DEFINED
#define SkDump_DEFINED

#include "SkDisplayable.h"
#include "SkMemberInfo.h"

class SkAnimateMaker;
class SkString;

class SkDump : public SkDisplayable {
    DECLARE_MEMBER_INFO(Dump);
#ifdef SK_DUMP_ENABLED
    SkDump();
<<<<<<< HEAD
    bool enable(SkAnimateMaker&) override;
    bool evaluate(SkAnimateMaker&);
    bool hasEnable() const override;
    static void GetEnumString(SkDisplayTypes, int index, SkString* result);
=======
    bool enable(SkAnimateMaker & ) override;
    bool evaluate(SkAnimateMaker &);
    bool hasEnable() const override;
    static void GetEnumString(SkDisplayTypes , int index, SkString* result);
>>>>>>> miniblink49
    SkBool displayList;
    SkBool eventList;
    SkBool events;
    SkString name;
    SkBool groups;
    SkBool posts;
    SkString script;
#else
<<<<<<< HEAD
    bool enable(SkAnimateMaker&) override;
    bool hasEnable() const override;
    bool setProperty(int index, SkScriptValue&) override;
#endif
};

=======
    virtual bool enable(SkAnimateMaker & );
    virtual bool hasEnable() const;
    virtual bool setProperty(int index, SkScriptValue& );
#endif
};


>>>>>>> miniblink49
#endif // SkDump_DEFINED
