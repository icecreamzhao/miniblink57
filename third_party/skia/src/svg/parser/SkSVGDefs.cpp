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
#include "SkSVGDefs.h"

DEFINE_SVG_NO_INFO(Defs)

<<<<<<< HEAD
bool SkSVGDefs::isDef()
{
    return true;
}

bool SkSVGDefs::isNotDef()
{
    return false;
}

void SkSVGDefs::translate(SkSVGParser& parser, bool defState)
{
=======
bool SkSVGDefs::isDef() {
    return true;
}

bool SkSVGDefs::isNotDef() {
    return false;
}

void SkSVGDefs::translate(SkSVGParser& parser, bool defState) {
>>>>>>> miniblink49
    INHERITED::translate(parser, defState);
}
