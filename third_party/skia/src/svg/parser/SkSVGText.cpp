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
#include "SkSVGText.h"
#include "SkSVGParser.h"

const SkSVGAttribute SkSVGText::gAttributes[] = {
    SVG_ATTRIBUTE(x),
    SVG_ATTRIBUTE(y)
};

DEFINE_SVG_INFO(Text)

<<<<<<< HEAD
void SkSVGText::translate(SkSVGParser& parser, bool defState)
{
=======
void SkSVGText::translate(SkSVGParser& parser, bool defState) {
>>>>>>> miniblink49
    parser._startElement("text");
    INHERITED::translate(parser, defState);
    SVG_ADD_ATTRIBUTE(x);
    SVG_ADD_ATTRIBUTE(y);
    SVG_ADD_ATTRIBUTE(text);
    parser._endElement();
}

<<<<<<< HEAD
=======

>>>>>>> miniblink49
const SkSVGAttribute SkSVGTspan::gAttributes[] = {
    SVG_ATTRIBUTE(x),
    SVG_ATTRIBUTE(y)
};

DEFINE_SVG_INFO(Tspan)

<<<<<<< HEAD
void SkSVGTspan::translate(SkSVGParser& parser, bool defState)
{
=======
void SkSVGTspan::translate(SkSVGParser& parser, bool defState) {
>>>>>>> miniblink49
    INHERITED::translate(parser, defState);
}
