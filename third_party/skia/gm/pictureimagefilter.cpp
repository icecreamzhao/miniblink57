/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "gm.h"

#include "SkPictureImageFilter.h"
#include "SkPictureRecorder.h"

// This GM exercises the SkPictureImageFilter ImageFilter class.

<<<<<<< HEAD
static void fill_rect_filtered(SkCanvas* canvas,
    const SkRect& clipRect,
    sk_sp<SkImageFilter> filter)
{
    SkPaint paint;
    paint.setImageFilter(filter);
    canvas->save();
    canvas->clipRect(clipRect);
    canvas->drawPaint(paint);
    canvas->restore();
}

static sk_sp<SkPicture> make_picture()
{
    SkPictureRecorder recorder;
    SkCanvas* canvas = recorder.beginRecording(100, 100, nullptr, 0);
    SkPaint paint;
    paint.setAntiAlias(true);
    sk_tool_utils::set_portable_typeface(&paint);
    paint.setColor(0xFFFFFFFF);
    paint.setTextSize(SkIntToScalar(96));
    const char* str = "e";
    canvas->drawText(str, strlen(str), SkIntToScalar(20), SkIntToScalar(70), paint);
    return recorder.finishRecordingAsPicture();
}

// Create a picture that will draw LCD text
static sk_sp<SkPicture> make_LCD_picture()
{
    SkPictureRecorder recorder;
    SkCanvas* canvas = recorder.beginRecording(100, 100, nullptr, 0);
    canvas->clear(SK_ColorTRANSPARENT);
    SkPaint paint;
    paint.setLCDRenderText(true); // want LCD
    paint.setAntiAlias(true); // need AA for LCD
    sk_tool_utils::set_portable_typeface(&paint);
    paint.setColor(0xFFFFFFFF);
    // this has to be small enough that it doesn't become a path
    paint.setTextSize(SkIntToScalar(36));
    const char* str = "e";
    canvas->drawText(str, strlen(str), SkIntToScalar(20), SkIntToScalar(70), paint);
    return recorder.finishRecordingAsPicture();
}

class PictureImageFilterGM : public skiagm::GM {
public:
    PictureImageFilterGM() { }

protected:
    SkString onShortName() override
    {
        return SkString("pictureimagefilter");
    }

    SkISize onISize() override { return SkISize::Make(600, 300); }

    void onOnceBeforeDraw() override
    {
        fPicture = make_picture();
        fLCDPicture = make_LCD_picture();
    }

    void onDraw(SkCanvas* canvas) override
    {
        canvas->clear(SK_ColorGRAY);
=======
class PictureImageFilterGM : public skiagm::GM {
public:
    PictureImageFilterGM() {
    }

protected:
    SkString onShortName() override {
        return SkString("pictureimagefilter");
    }

    void makePicture() {
        SkPictureRecorder recorder;
        SkCanvas* canvas = recorder.beginRecording(100, 100, NULL, 0);
        canvas->clear(SK_ColorBLACK);
        SkPaint paint;
        paint.setAntiAlias(true);
        sk_tool_utils::set_portable_typeface(&paint);
        paint.setColor(0xFFFFFFFF);
        paint.setTextSize(SkIntToScalar(96));
        const char* str = "e";
        canvas->drawText(str, strlen(str), SkIntToScalar(20), SkIntToScalar(70), paint);
        fPicture.reset(recorder.endRecording());
    }

    SkISize onISize() override { return SkISize::Make(600, 300); }

    void onOnceBeforeDraw() override {
        this->makePicture();
    }

    static void fillRectFiltered(SkCanvas* canvas, const SkRect& clipRect, SkImageFilter* filter) {
        SkPaint paint;
        paint.setImageFilter(filter);
        canvas->save();
        canvas->clipRect(clipRect);
        canvas->drawPaint(paint);
        canvas->restore();
    }

    void onDraw(SkCanvas* canvas) override {
        canvas->clear(SK_ColorBLACK);
>>>>>>> miniblink49
        {
            SkRect srcRect = SkRect::MakeXYWH(20, 20, 30, 30);
            SkRect emptyRect = SkRect::MakeXYWH(20, 20, 0, 0);
            SkRect bounds = SkRect::MakeXYWH(0, 0, 100, 100);
<<<<<<< HEAD
            sk_sp<SkImageFilter> pictureSource(SkPictureImageFilter::Make(fPicture));
            sk_sp<SkImageFilter> pictureSourceSrcRect(SkPictureImageFilter::Make(fPicture,
                srcRect));
            sk_sp<SkImageFilter> pictureSourceEmptyRect(SkPictureImageFilter::Make(fPicture,
                emptyRect));
            sk_sp<SkImageFilter> pictureSourceResampled(SkPictureImageFilter::MakeForLocalSpace(
                fPicture,
                fPicture->cullRect(),
                kLow_SkFilterQuality));
            sk_sp<SkImageFilter> pictureSourcePixelated(SkPictureImageFilter::MakeForLocalSpace(
                fPicture,
                fPicture->cullRect(),
                kNone_SkFilterQuality));

            canvas->save();
            // Draw the picture unscaled.
            fill_rect_filtered(canvas, bounds, pictureSource);
            canvas->translate(SkIntToScalar(100), 0);

            // Draw an unscaled subset of the source picture.
            fill_rect_filtered(canvas, bounds, pictureSourceSrcRect);
            canvas->translate(SkIntToScalar(100), 0);

            // Draw the picture to an empty rect (should draw nothing).
            fill_rect_filtered(canvas, bounds, pictureSourceEmptyRect);
            canvas->translate(SkIntToScalar(100), 0);

            // Draw the LCD picture to a layer
            {
                SkPaint stroke;
                stroke.setStyle(SkPaint::kStroke_Style);

                canvas->drawRect(bounds, stroke);

                SkPaint paint;
                paint.setImageFilter(SkPictureImageFilter::MakeForLocalSpace(
                    fLCDPicture,
                    fPicture->cullRect(),
                    kNone_SkFilterQuality));

                canvas->scale(4, 4);
                canvas->translate(-0.9f * srcRect.fLeft, -2.45f * srcRect.fTop);

                canvas->saveLayerPreserveLCDTextRequests(&bounds, &paint);
                canvas->restore();
            }

=======
            SkAutoTUnref<SkPictureImageFilter> pictureSource(
                SkPictureImageFilter::Create(fPicture));
            SkAutoTUnref<SkPictureImageFilter> pictureSourceSrcRect(
                SkPictureImageFilter::Create(fPicture, srcRect));
            SkAutoTUnref<SkPictureImageFilter> pictureSourceEmptyRect(
                SkPictureImageFilter::Create(fPicture, emptyRect));
            SkAutoTUnref<SkPictureImageFilter> pictureSourceResampled(
                SkPictureImageFilter::CreateForLocalSpace(fPicture, fPicture->cullRect(),
                    kLow_SkFilterQuality));
            SkAutoTUnref<SkPictureImageFilter> pictureSourcePixelated(
                SkPictureImageFilter::CreateForLocalSpace(fPicture, fPicture->cullRect(),
                    kNone_SkFilterQuality));

            canvas->save();
            // Draw the picture unscaled.
            fillRectFiltered(canvas, bounds, pictureSource);
            canvas->translate(SkIntToScalar(100), 0);

            // Draw an unscaled subset of the source picture.
            fillRectFiltered(canvas, bounds, pictureSourceSrcRect);
            canvas->translate(SkIntToScalar(100), 0);

            // Draw the picture to an empty rect (should draw nothing).
            fillRectFiltered(canvas, bounds, pictureSourceEmptyRect);
            canvas->translate(SkIntToScalar(100), 0);

>>>>>>> miniblink49
            canvas->restore();

            // Draw the picture scaled
            canvas->translate(0, SkIntToScalar(100));
            canvas->scale(200 / srcRect.width(), 200 / srcRect.height());
            canvas->translate(-srcRect.fLeft, -srcRect.fTop);
<<<<<<< HEAD
            fill_rect_filtered(canvas, srcRect, pictureSource);

            // Draw the picture scaled, but rasterized at original resolution
            canvas->translate(srcRect.width(), 0);
            fill_rect_filtered(canvas, srcRect, pictureSourceResampled);

            // Draw the picture scaled, pixelated
            canvas->translate(srcRect.width(), 0);
            fill_rect_filtered(canvas, srcRect, pictureSourcePixelated);
=======
            fillRectFiltered(canvas, srcRect, pictureSource);

            // Draw the picture scaled, but rasterized at original resolution
            canvas->translate(srcRect.width(), 0);
            fillRectFiltered(canvas, srcRect, pictureSourceResampled);

            // Draw the picture scaled, pixelated
            canvas->translate(srcRect.width(), 0);
            fillRectFiltered(canvas, srcRect, pictureSourcePixelated);
>>>>>>> miniblink49
        }
    }

private:
<<<<<<< HEAD
    sk_sp<SkPicture> fPicture;
    sk_sp<SkPicture> fLCDPicture;

=======
    SkAutoTUnref<SkPicture> fPicture;
>>>>>>> miniblink49
    typedef GM INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
DEF_GM(return new PictureImageFilterGM;)
=======
DEF_GM( return new PictureImageFilterGM; )
>>>>>>> miniblink49
