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
#include "SkSVGPath.h"
#include "SkSVGParser.h"

const SkSVGAttribute SkSVGPath::gAttributes[] = {
    SVG_ATTRIBUTE(d)
};

DEFINE_SVG_INFO(Path)

<<<<<<< HEAD
void SkSVGPath::translate(SkSVGParser& parser, bool defState)
{
=======
void SkSVGPath::translate(SkSVGParser& parser, bool defState) {
>>>>>>> miniblink49
    parser._startElement("path");
    INHERITED::translate(parser, defState);
    bool hasMultiplePaths = false;
    const char* firstZ = strchr(f_d.c_str(), 'z');
<<<<<<< HEAD
    if (firstZ != nullptr) {
=======
    if (firstZ != NULL) {
>>>>>>> miniblink49
        firstZ++; // skip over 'z'
        while (*firstZ == ' ')
            firstZ++;
        hasMultiplePaths = *firstZ != '\0';
    }
    if (hasMultiplePaths) {
        SkString& fillRule = parser.getPaintLast(SkSVGPaint::kFillRule);
        if (fillRule.size() > 0)
            parser._addAttribute("fillType", fillRule.equals("evenodd") ? "evenOdd" : "winding");
    }
    SVG_ADD_ATTRIBUTE(d);
    parser._endElement();
}
