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
#ifndef SkSVGPolygon_DEFINED
#define SkSVGPolygon_DEFINED

#include "SkSVGPolyline.h"

class SkSVGPolygon : public SkSVGPolyline {
    DECLARE_SVG_INFO(Polygon);
<<<<<<< HEAD
    virtual void addAttribute(SkSVGParser&, int attrIndex,
        const char* attrValue, size_t attrLength);

=======
    virtual void addAttribute(SkSVGParser& , int attrIndex,
        const char* attrValue, size_t attrLength);
>>>>>>> miniblink49
private:
    typedef SkSVGPolyline INHERITED;
};

#endif // SkSVGPolygon_DEFINED
