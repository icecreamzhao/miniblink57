/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkPaint.h"
#include "SkPictureRecorder.h"
#include "gm.h"

static sk_sp<SkPicture> make_picture()
{
=======
#include "gm.h"
#include "SkPaint.h"
#include "SkPictureRecorder.h"

static SkPicture* make_picture() {
>>>>>>> miniblink49
    SkPictureRecorder rec;
    SkCanvas* canvas = rec.beginRecording(100, 100);

    SkPaint paint;
    paint.setAntiAlias(true);
    SkPath path;

    paint.setColor(0x800000FF);
    canvas->drawRect(SkRect::MakeWH(100, 100), paint);

    paint.setColor(0x80FF0000);
<<<<<<< HEAD
    path.moveTo(0, 0);
    path.lineTo(100, 0);
    path.lineTo(100, 100);
    canvas->drawPath(path, paint);

    paint.setColor(0x8000FF00);
    path.reset();
    path.moveTo(0, 0);
    path.lineTo(100, 0);
    path.lineTo(0, 100);
=======
    path.moveTo(0, 0); path.lineTo(100, 0); path.lineTo(100, 100);
    canvas->drawPath(path, paint);
    
    paint.setColor(0x8000FF00);
    path.reset(); path.moveTo(0, 0); path.lineTo(100, 0); path.lineTo(0, 100);
>>>>>>> miniblink49
    canvas->drawPath(path, paint);

    paint.setColor(0x80FFFFFF);
    paint.setXfermodeMode(SkXfermode::kPlus_Mode);
    canvas->drawRect(SkRect::MakeXYWH(25, 25, 50, 50), paint);

<<<<<<< HEAD
    return rec.finishRecordingAsPicture();
=======
    return rec.endRecording();
>>>>>>> miniblink49
}

// Exercise the optional arguments to drawPicture
//
class PictureGM : public skiagm::GM {
public:
    PictureGM()
<<<<<<< HEAD
        : fPicture(nullptr)
    {
    }

protected:
    void onOnceBeforeDraw() override
    {
        fPicture = make_picture();
    }

    SkString onShortName() override
    {
        return SkString("pictures");
    }

    SkISize onISize() override
    {
        return SkISize::Make(450, 120);
    }

    void onDraw(SkCanvas* canvas) override
    {
=======
        : fPicture(NULL)
    {}

protected:
    void onOnceBeforeDraw() override {
         fPicture.reset(make_picture());
    }

    SkString onShortName() override {
        return SkString("pictures");
    }

    SkISize onISize() override {
        return SkISize::Make(450, 120);
    }

    void onDraw(SkCanvas* canvas) override {
>>>>>>> miniblink49
        canvas->translate(10, 10);

        SkMatrix matrix;
        SkPaint paint;

        canvas->drawPicture(fPicture);
<<<<<<< HEAD

        matrix.setTranslate(110, 0);
        canvas->drawPicture(fPicture, &matrix, nullptr);

=======
        
        matrix.setTranslate(110, 0);
        canvas->drawPicture(fPicture, &matrix, NULL);
        
>>>>>>> miniblink49
        matrix.postTranslate(110, 0);
        canvas->drawPicture(fPicture, &matrix, &paint);

        paint.setAlpha(0x80);
        matrix.postTranslate(110, 0);
        canvas->drawPicture(fPicture, &matrix, &paint);
    }

private:
<<<<<<< HEAD
    sk_sp<SkPicture> fPicture;
=======
    SkAutoTUnref<SkPicture> fPicture;
>>>>>>> miniblink49

    typedef skiagm::GM INHERITED;
};

<<<<<<< HEAD
DEF_GM(return new PictureGM;)
=======
DEF_GM( return SkNEW(PictureGM); )
>>>>>>> miniblink49
