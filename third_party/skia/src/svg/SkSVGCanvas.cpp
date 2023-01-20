/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkSVGCanvas.h"
#include "SkSVGDevice.h"

<<<<<<< HEAD
SkCanvas* SkSVGCanvas::Create(const SkRect& bounds, SkXMLWriter* writer)
{
=======
SkCanvas* SkSVGCanvas::Create(const SkRect& bounds, SkXMLWriter* writer) {
>>>>>>> miniblink49
    // TODO: pass full bounds to the device
    SkISize size = bounds.roundOut().size();
    SkAutoTUnref<SkBaseDevice> device(SkSVGDevice::Create(size, writer));

<<<<<<< HEAD
    return new SkCanvas(device);
=======
    return SkNEW_ARGS(SkCanvas, (device));
>>>>>>> miniblink49
}
