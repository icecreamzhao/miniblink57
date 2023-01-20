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
#include "SkSVGStop.h"
#include "SkSVGParser.h"

const SkSVGAttribute SkSVGStop::gAttributes[] = {
    SVG_ATTRIBUTE(offset)
};

DEFINE_SVG_INFO(Stop)

<<<<<<< HEAD
void SkSVGStop::translate(SkSVGParser& parser, bool defState)
{
=======
void SkSVGStop::translate(SkSVGParser& parser, bool defState) {
>>>>>>> miniblink49
    parser._startElement("color");
    INHERITED::translate(parser, defState);
    parser._addAttribute("color", parser.getPaintLast(SkSVGPaint::kStopColor));
    parser._endElement();
}
