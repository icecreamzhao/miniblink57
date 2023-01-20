<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#ifndef SkSVGGroup_DEFINED
#define SkSVGGroup_DEFINED

#include "SkSVGElements.h"

class SkSVGGroup : public SkSVGElement {
public:
    SkSVGGroup();
    virtual SkSVGElement* getGradient();
    virtual bool isDef();
    virtual bool isFlushable();
    virtual bool isGroup();
    virtual bool isNotDef();
<<<<<<< HEAD
    void translate(SkSVGParser&, bool defState);

=======
    void translate(SkSVGParser& , bool defState);
>>>>>>> miniblink49
private:
    typedef SkSVGElement INHERITED;
};

#endif // SkSVGGroup_DEFINED
