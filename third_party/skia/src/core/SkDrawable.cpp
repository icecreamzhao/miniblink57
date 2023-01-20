/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkDrawable.h"
#include "SkAtomics.h"
#include "SkCanvas.h"

static int32_t next_generation_id()
{
=======
#include "SkAtomics.h"
#include "SkCanvas.h"
#include "SkDrawable.h"

static int32_t next_generation_id() {
>>>>>>> miniblink49
    static int32_t gCanvasDrawableGenerationID;

    // do a loop in case our global wraps around, as we never want to
    // return a 0
    int32_t genID;
    do {
        genID = sk_atomic_inc(&gCanvasDrawableGenerationID) + 1;
    } while (0 == genID);
    return genID;
}

<<<<<<< HEAD
SkDrawable::SkDrawable()
    : fGenerationID(0)
{
}

static void draw_bbox(SkCanvas* canvas, const SkRect& r)
{
=======
SkDrawable::SkDrawable() : fGenerationID(0) {}

static void draw_bbox(SkCanvas* canvas, const SkRect& r) {
>>>>>>> miniblink49
    SkPaint paint;
    paint.setStyle(SkPaint::kStroke_Style);
    paint.setColor(0xFFFF7088);
    canvas->drawRect(r, paint);
    canvas->drawLine(r.left(), r.top(), r.right(), r.bottom(), paint);
    canvas->drawLine(r.left(), r.bottom(), r.right(), r.top(), paint);
}

<<<<<<< HEAD
void SkDrawable::draw(SkCanvas* canvas, const SkMatrix* matrix)
{
=======
void SkDrawable::draw(SkCanvas* canvas, const SkMatrix* matrix) {
>>>>>>> miniblink49
    SkAutoCanvasRestore acr(canvas, true);
    if (matrix) {
        canvas->concat(*matrix);
    }
    this->onDraw(canvas);

    if (false) {
        draw_bbox(canvas, this->getBounds());
    }
}

<<<<<<< HEAD
void SkDrawable::draw(SkCanvas* canvas, SkScalar x, SkScalar y)
{
=======
void SkDrawable::draw(SkCanvas* canvas, SkScalar x, SkScalar y) {
>>>>>>> miniblink49
    SkMatrix matrix = SkMatrix::MakeTrans(x, y);
    this->draw(canvas, &matrix);
}

<<<<<<< HEAD
SkPicture* SkDrawable::newPictureSnapshot()
{
    return this->onNewPictureSnapshot();
}

uint32_t SkDrawable::getGenerationID()
{
=======
SkPicture* SkDrawable::newPictureSnapshot() {
    return this->onNewPictureSnapshot();
}

uint32_t SkDrawable::getGenerationID() {
>>>>>>> miniblink49
    if (0 == fGenerationID) {
        fGenerationID = next_generation_id();
    }
    return fGenerationID;
}

<<<<<<< HEAD
SkRect SkDrawable::getBounds()
{
    return this->onGetBounds();
}

void SkDrawable::notifyDrawingChanged()
{
=======
SkRect SkDrawable::getBounds() {
    return this->onGetBounds();
}

void SkDrawable::notifyDrawingChanged() {
>>>>>>> miniblink49
    fGenerationID = 0;
}

/////////////////////////////////////////////////////////////////////////////////////////

#include "SkPictureRecorder.h"

<<<<<<< HEAD
SkPicture* SkDrawable::onNewPictureSnapshot()
{
    SkPictureRecorder recorder;

    const SkRect bounds = this->getBounds();
    SkCanvas* canvas = recorder.beginRecording(bounds, nullptr, 0);
=======
SkPicture* SkDrawable::onNewPictureSnapshot() {
    SkPictureRecorder recorder;

    const SkRect bounds = this->getBounds();
    SkCanvas* canvas = recorder.beginRecording(bounds, NULL, 0);
>>>>>>> miniblink49
    this->draw(canvas);
    if (false) {
        draw_bbox(canvas, bounds);
    }
<<<<<<< HEAD
    return recorder.finishRecordingAsPicture().release();
=======
    return recorder.endRecording();
>>>>>>> miniblink49
}
