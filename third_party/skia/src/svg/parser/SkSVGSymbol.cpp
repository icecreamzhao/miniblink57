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
#include "SkSVGSymbol.h"
#include "SkSVGParser.h"

const SkSVGAttribute SkSVGSymbol::gAttributes[] = {
    SVG_ATTRIBUTE(viewBox)
};

DEFINE_SVG_INFO(Symbol)

<<<<<<< HEAD
void SkSVGSymbol::translate(SkSVGParser& parser, bool defState)
{
=======
void SkSVGSymbol::translate(SkSVGParser& parser, bool defState) {
>>>>>>> miniblink49
    INHERITED::translate(parser, defState);
    // !!! children need to be written into document
}
