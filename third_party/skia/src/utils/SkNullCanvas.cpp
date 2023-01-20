/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkNullCanvas.h"

#include "SkCanvas.h"
#include "SkNWayCanvas.h"

<<<<<<< HEAD
SkCanvas* SkCreateNullCanvas()
{
    // An N-Way canvas forwards calls to N canvas's. When N == 0 it's
    // effectively a null canvas.
    return new SkNWayCanvas(0, 0);
}

std::unique_ptr<SkCanvas> SkMakeNullCanvas()
{
    // An N-Way canvas forwards calls to N canvas's. When N == 0 it's
    // effectively a null canvas.
    return std::unique_ptr<SkCanvas>(SkCreateNullCanvas());
=======

SkCanvas* SkCreateNullCanvas() {
    // An N-Way canvas forwards calls to N canvas's. When N == 0 it's
    // effectively a null canvas.
    return SkNEW_ARGS(SkNWayCanvas, (0,0));
>>>>>>> miniblink49
}
