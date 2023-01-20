/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "nanobenchAndroid.h"

<<<<<<< HEAD
/* These functions are only compiled in the Android Framework. */

HWUITarget::HWUITarget(const Config& c, Benchmark* bench)
    : Target(c)
{
}

void HWUITarget::setup()
{
    this->renderer.fence();
}

SkCanvas* HWUITarget::beginTiming(SkCanvas* canvas)
{
=======
#include "AnimationContext.h"
#include "IContextFactory.h"
#include "SkiaCanvasProxy.h"
#include "android/rect.h"
#include "android/native_window.h"
#include "renderthread/TimeLord.h"

/* These functions are only compiled in the Android Framework. */

HWUITarget::HWUITarget(const Config& c, Benchmark* bench) : Target(c) { }

void HWUITarget::setup() {
    this->renderer.proxy->fence();
}

SkCanvas* HWUITarget::beginTiming(SkCanvas* canvas) {
>>>>>>> miniblink49
    SkCanvas* targetCanvas = this->renderer.prepareToDraw();
    if (targetCanvas) {
        this->fc.reset(targetCanvas);
        canvas = &this->fc;
        // This might minimally distort timing, but canvas isn't valid outside the timer.
        canvas->clear(SK_ColorWHITE);
    }

    return canvas;
}

<<<<<<< HEAD
void HWUITarget::endTiming()
{
    this->renderer.finishDrawing();
}

void HWUITarget::fence()
{
    this->renderer.fence();
}

bool HWUITarget::needsFrameTiming(int* frameLag) const
{
=======
void HWUITarget::endTiming() {
    this->renderer.finishDrawing();
}

void HWUITarget::fence() {
    this->renderer.proxy->fence();
}

bool HWUITarget::needsFrameTiming(int* frameLag) const {
>>>>>>> miniblink49
    extern int FLAGS_gpuFrameLag;
    *frameLag = FLAGS_gpuFrameLag;
    return true;
}

<<<<<<< HEAD
bool HWUITarget::init(SkImageInfo info, Benchmark* bench)
{
    this->renderer.initialize(bench->getSize().x(), bench->getSize().y());
    return true;
}

bool HWUITarget::capturePixels(SkBitmap* bmp)
{
    return this->renderer.capturePixels(bmp);
}
=======
bool HWUITarget::init(SkImageInfo info, Benchmark* bench) {
    this->renderer.initialize({bench->getSize().x(), bench->getSize().y()});
    return true;
}

bool HWUITarget::capturePixels(SkBitmap* bmp) {
    return this->renderer.capturePixels(bmp);
}


>>>>>>> miniblink49
