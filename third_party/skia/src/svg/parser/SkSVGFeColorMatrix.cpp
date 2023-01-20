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
#include "SkSVGFeColorMatrix.h"
#include "SkSVGParser.h"

const SkSVGAttribute SkSVGFeColorMatrix::gAttributes[] = {
<<<<<<< HEAD
    SVG_LITERAL_ATTRIBUTE(color - interpolation - filters, f_color_interpolation_filters),
=======
    SVG_LITERAL_ATTRIBUTE(color-interpolation-filters, f_color_interpolation_filters),
>>>>>>> miniblink49
    SVG_ATTRIBUTE(result),
    SVG_ATTRIBUTE(type),
    SVG_ATTRIBUTE(values)
};

DEFINE_SVG_INFO(FeColorMatrix)

<<<<<<< HEAD
void SkSVGFeColorMatrix::translate(SkSVGParser& parser, bool defState)
{
=======
void SkSVGFeColorMatrix::translate(SkSVGParser& parser, bool defState) {
>>>>>>> miniblink49
    INHERITED::translate(parser, defState);
}
