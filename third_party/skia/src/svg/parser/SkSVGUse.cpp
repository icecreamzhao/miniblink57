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
#include "SkSVGUse.h"
#include "SkSVGParser.h"

const SkSVGAttribute SkSVGUse::gAttributes[] = {
    SVG_ATTRIBUTE(height),
    SVG_ATTRIBUTE(width),
    SVG_ATTRIBUTE(x),
<<<<<<< HEAD
    SVG_LITERAL_ATTRIBUTE(xlink
                          : href, f_xlink_href),
=======
    SVG_LITERAL_ATTRIBUTE(xlink:href, f_xlink_href),
>>>>>>> miniblink49
    SVG_ATTRIBUTE(y)
};

DEFINE_SVG_INFO(Use)

<<<<<<< HEAD
void SkSVGUse::translate(SkSVGParser& parser, bool defState)
{
=======
void SkSVGUse::translate(SkSVGParser& parser, bool defState) {
>>>>>>> miniblink49
    INHERITED::translate(parser, defState);
    parser._startElement("add");
    const char* start = strchr(f_xlink_href.c_str(), '#') + 1;
    SkASSERT(start);
    parser._addAttributeLen("use", start, strlen(start) - 1);
<<<<<<< HEAD
    parser._endElement(); // clip
=======
    parser._endElement();   // clip
>>>>>>> miniblink49
}
