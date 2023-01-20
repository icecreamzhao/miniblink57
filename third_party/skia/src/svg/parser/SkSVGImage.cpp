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
#include "SkSVGImage.h"
#include "SkSVGParser.h"

const SkSVGAttribute SkSVGImage::gAttributes[] = {
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

DEFINE_SVG_INFO(Image)

<<<<<<< HEAD
void SkSVGImage::translate(SkSVGParser& parser, bool defState)
{
=======
void SkSVGImage::translate(SkSVGParser& parser, bool defState) {
>>>>>>> miniblink49
    parser._startElement("image");
    INHERITED::translate(parser, defState);
    SVG_ADD_ATTRIBUTE(x);
    SVG_ADD_ATTRIBUTE(y);
<<<<<<< HEAD
    //  SVG_ADD_ATTRIBUTE(width);
    //  SVG_ADD_ATTRIBUTE(height);
=======
//  SVG_ADD_ATTRIBUTE(width);
//  SVG_ADD_ATTRIBUTE(height);
>>>>>>> miniblink49
    translateImage(parser);
    parser._endElement();
}

<<<<<<< HEAD
void SkSVGImage::translateImage(SkSVGParser& parser)
{
=======
void SkSVGImage::translateImage(SkSVGParser& parser) {
>>>>>>> miniblink49
    SkASSERT(f_xlink_href.size() > 0);
    const char* data = f_xlink_href.c_str();
    SkASSERT(strncmp(data, "data:image/", 11) == 0);
    data += 11;
    SkASSERT(strncmp(data, "png;", 4) == 0 || strncmp(data, "jpeg;", 5) == 0);
    data = strchr(data, ';');
    SkASSERT(strncmp(data, ";base64,", 8) == 0);
    data += 8;
    parser._addAttribute("base64", data);
}
