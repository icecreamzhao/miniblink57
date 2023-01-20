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
#include "SkSVGCircle.h"
#include "SkParse.h"
#include "SkSVGParser.h"
=======

#include "SkSVGCircle.h"
#include "SkSVGParser.h"
#include "SkParse.h"
>>>>>>> miniblink49
#include <stdio.h>

const SkSVGAttribute SkSVGCircle::gAttributes[] = {
    SVG_ATTRIBUTE(cx),
    SVG_ATTRIBUTE(cy),
    SVG_ATTRIBUTE(r)
};

DEFINE_SVG_INFO(Circle)

<<<<<<< HEAD
void SkSVGCircle::translate(SkSVGParser& parser, bool defState)
{
=======
void SkSVGCircle::translate(SkSVGParser& parser, bool defState) {
>>>>>>> miniblink49
    parser._startElement("oval");
    INHERITED::translate(parser, defState);
    SkScalar cx, cy, r;
    SkParse::FindScalar(f_cx.c_str(), &cx);
    SkParse::FindScalar(f_cy.c_str(), &cy);
    SkParse::FindScalar(f_r.c_str(), &r);
    SkScalar left, top, right, bottom;
    left = cx - r;
    top = cy - r;
    right = cx + r;
    bottom = cy + r;
    char scratch[16];
    sprintf(scratch, "%g", SkScalarToDouble(left));
    parser._addAttribute("left", scratch);
    sprintf(scratch, "%g", SkScalarToDouble(top));
    parser._addAttribute("top", scratch);
    sprintf(scratch, "%g", SkScalarToDouble(right));
    parser._addAttribute("right", scratch);
    sprintf(scratch, "%g", SkScalarToDouble(bottom));
    parser._addAttribute("bottom", scratch);
    parser._endElement();
}
