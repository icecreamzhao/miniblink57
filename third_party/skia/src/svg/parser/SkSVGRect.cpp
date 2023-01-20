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
#include "SkSVGRect.h"
#include "SkSVGParser.h"

const SkSVGAttribute SkSVGRect::gAttributes[] = {
    SVG_ATTRIBUTE(height),
    SVG_ATTRIBUTE(width),
    SVG_ATTRIBUTE(x),
    SVG_ATTRIBUTE(y)
};

DEFINE_SVG_INFO(Rect)

<<<<<<< HEAD
SkSVGRect::SkSVGRect()
{
=======
SkSVGRect::SkSVGRect() {
>>>>>>> miniblink49
    f_x.set("0");
    f_y.set("0");
}

<<<<<<< HEAD
void SkSVGRect::translate(SkSVGParser& parser, bool defState)
{
=======
void SkSVGRect::translate(SkSVGParser& parser, bool defState) {
>>>>>>> miniblink49
    parser._startElement("rect");
    INHERITED::translate(parser, defState);
    SVG_ADD_ATTRIBUTE_ALIAS(left, x);
    SVG_ADD_ATTRIBUTE_ALIAS(top, y);
    SVG_ADD_ATTRIBUTE(width);
    SVG_ADD_ATTRIBUTE(height);
    parser._endElement();
}
