
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#ifndef SkDrawText_DEFINED
#define SkDrawText_DEFINED

#include "SkBoundable.h"
#include "SkMemberInfo.h"

class SkText : public SkBoundable {
    DECLARE_MEMBER_INFO(Text);
    SkText();
    virtual ~SkText();
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
    bool getProperty(int index, SkScriptValue* value) const override;
    const char* getText() { return text.c_str(); }
    size_t getSize() { return text.size(); }
<<<<<<< HEAD

=======
>>>>>>> miniblink49
protected:
    SkString text;
    SkScalar x;
    SkScalar y;
<<<<<<< HEAD

=======
>>>>>>> miniblink49
private:
    friend class SkTextToPath;
    typedef SkBoundable INHERITED;
};

#endif // SkDrawText_DEFINED
