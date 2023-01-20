/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkDrawLooper.h"
#include "SkCanvas.h"
#include "SkMatrix.h"
#include "SkPaint.h"
#include "SkRect.h"
#include "SkSmallAllocator.h"

<<<<<<< HEAD
bool SkDrawLooper::canComputeFastBounds(const SkPaint& paint) const
{
=======
bool SkDrawLooper::canComputeFastBounds(const SkPaint& paint) const {
>>>>>>> miniblink49
    SkCanvas canvas;
    SkSmallAllocator<1, 32> allocator;
    void* buffer = allocator.reserveT<SkDrawLooper::Context>(this->contextSize());

    SkDrawLooper::Context* context = this->createContext(&canvas, buffer);
    for (;;) {
        SkPaint p(paint);
        if (context->next(&canvas, &p)) {
<<<<<<< HEAD
            p.setLooper(nullptr);
=======
            p.setLooper(NULL);
>>>>>>> miniblink49
            if (!p.canComputeFastBounds()) {
                return false;
            }
        } else {
            break;
        }
    }
    return true;
}

void SkDrawLooper::computeFastBounds(const SkPaint& paint, const SkRect& s,
<<<<<<< HEAD
    SkRect* dst) const
{
=======
                                     SkRect* dst) const {
>>>>>>> miniblink49
    // src and dst rects may alias and we need to keep the original src, so copy it.
    const SkRect src = s;

    SkCanvas canvas;
    SkSmallAllocator<1, 32> allocator;
    void* buffer = allocator.reserveT<SkDrawLooper::Context>(this->contextSize());

<<<<<<< HEAD
    *dst = src; // catch case where there are no loops
=======
    *dst = src;   // catch case where there are no loops
>>>>>>> miniblink49
    SkDrawLooper::Context* context = this->createContext(&canvas, buffer);
    for (bool firstTime = true;; firstTime = false) {
        SkPaint p(paint);
        if (context->next(&canvas, &p)) {
            SkRect r(src);

<<<<<<< HEAD
            p.setLooper(nullptr);
=======
            p.setLooper(NULL);
>>>>>>> miniblink49
            p.computeFastBounds(r, &r);
            canvas.getTotalMatrix().mapRect(&r);

            if (firstTime) {
                *dst = r;
            } else {
                dst->join(r);
            }
        } else {
            break;
        }
    }
}

<<<<<<< HEAD
bool SkDrawLooper::asABlurShadow(BlurShadowRec*) const
{
=======
bool SkDrawLooper::asABlurShadow(BlurShadowRec*) const {
>>>>>>> miniblink49
    return false;
}
