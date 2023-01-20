/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "GMBench.h"

<<<<<<< HEAD
GMBench::GMBench(skiagm::GM* gm)
    : fGM(gm)
{
=======
GMBench::GMBench(skiagm::GM* gm) : fGM(gm) {
>>>>>>> miniblink49
    fName.printf("GM_%s", gm->getName());
}

GMBench::~GMBench() { delete fGM; }

<<<<<<< HEAD
const char* GMBench::onGetName()
{
    return fName.c_str();
}

bool GMBench::isSuitableFor(Backend backend)
{
    return kNonRendering_Backend != backend;
}

void GMBench::onDraw(int loops, SkCanvas* canvas)
{
    fGM->setMode(skiagm::GM::kBench_Mode);
=======
const char* GMBench::onGetName() {
    return fName.c_str();
}

bool GMBench::isSuitableFor(Backend backend) {
    return kNonRendering_Backend != backend;
}

void GMBench::onDraw(const int loops, SkCanvas* canvas) {
>>>>>>> miniblink49
    // Do we care about timing the draw of the background (once)?
    // Does the GM ever rely on drawBackground to lazily compute something?
    fGM->drawBackground(canvas);
    for (int i = 0; i < loops; ++i) {
        fGM->drawContent(canvas);
    }
}

<<<<<<< HEAD
SkIPoint GMBench::onGetSize()
{
    SkISize size = fGM->getISize();
    return SkIPoint::Make(size.fWidth, size.fHeight);
}
=======
SkIPoint GMBench::onGetSize() {
    SkISize size = fGM->getISize();
    return SkIPoint::Make(size.fWidth, size.fHeight);
}

>>>>>>> miniblink49
