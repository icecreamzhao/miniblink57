/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkBlurImageFilter.h"
#include "SkDropShadowImageFilter.h"
#include "SkImageSource.h"
=======
#include "gm.h"
#include "SkBitmapSource.h"
#include "SkBlurImageFilter.h"
#include "SkDropShadowImageFilter.h"
>>>>>>> miniblink49
#include "SkOffsetImageFilter.h"
#include "SkPictureImageFilter.h"
#include "SkPictureRecorder.h"
#include "SkRandom.h"
<<<<<<< HEAD
#include "SkSurface.h"
#include "SkTileImageFilter.h"
#include "gm.h"
=======
>>>>>>> miniblink49

namespace skiagm {

// Each method of this type must draw its geometry inside 'r' using 'p'
<<<<<<< HEAD
typedef void (*drawMth)(SkCanvas* canvas, const SkRect& r, const SkPaint& p);

static void draw_rect(SkCanvas* canvas, const SkRect& r, const SkPaint& p)
{
    canvas->drawRect(r, p);
}

static void draw_oval(SkCanvas* canvas, const SkRect& r, const SkPaint& p)
{
    canvas->drawOval(r, p);
}

static void draw_rrect(SkCanvas* canvas, const SkRect& r, const SkPaint& p)
{
=======
typedef void(*drawMth)(SkCanvas* canvas, const SkRect& r, const SkPaint& p);

static void draw_rect(SkCanvas* canvas, const SkRect& r, const SkPaint& p) {
    canvas->drawRect(r, p);
}

static void draw_oval(SkCanvas* canvas, const SkRect& r, const SkPaint& p) {
    canvas->drawOval(r, p);
}

static void draw_rrect(SkCanvas* canvas, const SkRect& r, const SkPaint& p) {
>>>>>>> miniblink49
    SkScalar xRad = r.width() / 4.0f;
    SkScalar yRad = r.height() / 4.0f;

    SkRRect rr;
    rr.setRectXY(r, xRad, yRad);
    canvas->drawRRect(rr, p);
}

<<<<<<< HEAD
static void draw_drrect(SkCanvas* canvas, const SkRect& r, const SkPaint& p)
{
=======
static void draw_drrect(SkCanvas* canvas, const SkRect& r, const SkPaint& p) {
>>>>>>> miniblink49
    SkScalar xRad = r.width() / 4.0f;
    SkScalar yRad = r.height() / 4.0f;

    SkRRect outer;
    outer.setRectXY(r, xRad, yRad);
    SkRRect inner = outer;
    inner.inset(xRad, yRad);
    canvas->drawDRRect(outer, inner, p);
}

<<<<<<< HEAD
static void draw_path(SkCanvas* canvas, const SkRect& r, const SkPaint& p)
{
=======
static void draw_path(SkCanvas* canvas, const SkRect& r, const SkPaint& p) {
>>>>>>> miniblink49
    SkPath path;

    path.moveTo(r.fLeft, r.fTop);
    path.lineTo(r.fLeft, r.fBottom);
    path.lineTo(r.fRight, r.fBottom);
    path.close();

    canvas->drawPath(path, p);
}

<<<<<<< HEAD
static void draw_points(SkCanvas* canvas, const SkRect& r, const SkPaint& p)
{
=======
static void draw_points(SkCanvas* canvas, const SkRect& r, const SkPaint& p) {
>>>>>>> miniblink49
    SkPoint pts0[2] = { { r.fLeft, r.fTop }, { r.fRight, r.fBottom } };
    SkPoint pts1[2] = { { r.fLeft, r.fBottom }, { r.fRight, r.fTop } };

    canvas->drawPoints(SkCanvas::kLines_PointMode, 2, pts0, p);
    canvas->drawPoints(SkCanvas::kLines_PointMode, 2, pts1, p);
}

<<<<<<< HEAD
static void draw_bitmap(SkCanvas* canvas, const SkRect& r, const SkPaint& p)
{
=======
static void draw_bitmap(SkCanvas* canvas, const SkRect& r, const SkPaint& p) {
>>>>>>> miniblink49
    SkBitmap bm;

    bm.allocN32Pixels(64, 64);
    SkCanvas temp(bm);
    temp.clear(SK_ColorMAGENTA);

    canvas->drawBitmapRect(bm, r, &p);
}

static const drawMth gDrawMthds[] = {
    draw_rect, draw_oval, draw_rrect, draw_drrect, draw_path, draw_points, draw_bitmap
};

<<<<<<< HEAD
static void add_paint(SkTArray<SkPaint>* paints, sk_sp<SkImageFilter> filter)
{
    SkPaint& p = paints->push_back();
    p.setImageFilter(std::move(filter));
=======
static void add_paint(SkImageFilter* filter, SkTArray<SkPaint>* paints) {
    SkPaint& p = paints->push_back();
    p.setImageFilter(filter);
>>>>>>> miniblink49
    SkASSERT(p.canComputeFastBounds());
}

// Create a selection of imagefilter-based paints to test
<<<<<<< HEAD
static void create_paints(SkTArray<SkPaint>* paints, sk_sp<SkImageFilter> source)
{
=======
static void create_paints(SkImageFilter* source, SkTArray<SkPaint>* paints) {
>>>>>>> miniblink49
    {
        SkMatrix scale;
        scale.setScale(2.0f, 2.0f);

<<<<<<< HEAD
        sk_sp<SkImageFilter> scaleMIF(
            SkImageFilter::MakeMatrixFilter(scale, kLow_SkFilterQuality, source));

        add_paint(paints, std::move(scaleMIF));
=======
        SkAutoTUnref<SkImageFilter> scaleMIF(
            SkImageFilter::CreateMatrixFilter(scale, kLow_SkFilterQuality, source));

        add_paint(scaleMIF, paints);
>>>>>>> miniblink49
    }

    {
        SkMatrix rot;
        rot.setRotate(-33.3f);

<<<<<<< HEAD
        sk_sp<SkImageFilter> rotMIF(
            SkImageFilter::MakeMatrixFilter(rot, kLow_SkFilterQuality, source));

        add_paint(paints, std::move(rotMIF));
    }

    {
        SkRect src = SkRect::MakeXYWH(20, 20, 10, 10);
        SkRect dst = SkRect::MakeXYWH(30, 30, 30, 30);
        sk_sp<SkImageFilter> tileIF(SkTileImageFilter::Make(src, dst, nullptr));

        add_paint(paints, std::move(tileIF));
    }

    {
        static const SkDropShadowImageFilter::ShadowMode kBoth = SkDropShadowImageFilter::kDrawShadowAndForeground_ShadowMode;

        sk_sp<SkImageFilter> dsif(SkDropShadowImageFilter::Make(10.0f, 10.0f,
            3.0f, 3.0f,
            SK_ColorRED, kBoth,
            source));

        add_paint(paints, std::move(dsif));
    }

    {
        sk_sp<SkImageFilter> dsif(
            SkDropShadowImageFilter::Make(27.0f, 27.0f,
                3.0f, 3.0f,
                SK_ColorRED,
                SkDropShadowImageFilter::kDrawShadowOnly_ShadowMode,
                source));

        add_paint(paints, std::move(dsif));
    }

    add_paint(paints, SkBlurImageFilter::Make(3, 3, source));
    add_paint(paints, SkOffsetImageFilter::Make(15, 15, source));
=======
        SkAutoTUnref<SkImageFilter> rotMIF(
            SkImageFilter::CreateMatrixFilter(rot, kLow_SkFilterQuality, source));

        add_paint(rotMIF, paints);
    }

    {
        static const SkDropShadowImageFilter::ShadowMode kBoth =
                    SkDropShadowImageFilter::kDrawShadowAndForeground_ShadowMode;

        SkAutoTUnref<SkDropShadowImageFilter> dsif(
            SkDropShadowImageFilter::Create(10.0f, 10.0f,
                                            3.0f, 3.0f,
                                            SK_ColorRED, kBoth,
                                            source, NULL));

        add_paint(dsif, paints);
    }

    {
        SkAutoTUnref<SkDropShadowImageFilter> dsif(
            SkDropShadowImageFilter::Create(27.0f, 27.0f,
                                            3.0f, 3.0f,
                                            SK_ColorRED,
                                            SkDropShadowImageFilter::kDrawShadowOnly_ShadowMode,
                                            source, NULL));

        add_paint(dsif, paints);
    }

    {
        SkAutoTUnref<SkBlurImageFilter> bif(SkBlurImageFilter::Create(3, 3, source));

        add_paint(bif, paints);
    }

    {
        SkAutoTUnref<SkOffsetImageFilter> oif(SkOffsetImageFilter::Create(15, 15, source));

        add_paint(oif, paints);
    }
>>>>>>> miniblink49
}

// This GM visualizes the fast bounds for various combinations of geometry
// and image filter
class ImageFilterFastBoundGM : public GM {
public:
<<<<<<< HEAD
    ImageFilterFastBoundGM()
    {
=======
    ImageFilterFastBoundGM() {
>>>>>>> miniblink49
        this->setBGColor(sk_tool_utils::color_to_565(0xFFCCCCCC));
    }

protected:
    static const int kTileWidth = 100;
    static const int kTileHeight = 100;
<<<<<<< HEAD
    static const int kNumVertTiles = 7;
    static const int kNumXtraCols = 2;

    SkString onShortName() override { return SkString("filterfastbounds"); }

    SkISize onISize() override
    {
        return SkISize::Make((SK_ARRAY_COUNT(gDrawMthds) + kNumXtraCols) * kTileWidth,
            kNumVertTiles * kTileHeight);
    }

    static void draw_geom_with_paint(drawMth draw, const SkIPoint& off,
        SkCanvas* canvas, const SkPaint& p)
    {
=======
    static const int kNumVertTiles = 6;
    static const int kNumXtraCols = 2;

    SkString onShortName() override{ return SkString("filterfastbounds"); }

    SkISize onISize() override{
        return SkISize::Make((SK_ARRAY_COUNT(gDrawMthds) + kNumXtraCols) * kTileWidth,
                             kNumVertTiles * kTileHeight);
    }

    static void draw_geom_with_paint(drawMth draw, const SkIPoint& off,
                                     SkCanvas* canvas, const SkPaint& p) {
>>>>>>> miniblink49
        SkPaint redStroked;
        redStroked.setColor(SK_ColorRED);
        redStroked.setStyle(SkPaint::kStroke_Style);

        SkPaint blueStroked;
        blueStroked.setColor(SK_ColorBLUE);
        blueStroked.setStyle(SkPaint::kStroke_Style);

        const SkRect r = SkRect::MakeLTRB(20, 20, 30, 30);
        SkRect storage;

        canvas->save();
<<<<<<< HEAD
        canvas->translate(SkIntToScalar(off.fX), SkIntToScalar(off.fY));
        canvas->scale(1.5f, 1.5f);

        const SkRect& fastBound = p.computeFastBounds(r, &storage);

        canvas->save();
        canvas->clipRect(fastBound);
        (*draw)(canvas, r, p);
        canvas->restore();

        canvas->drawRect(r, redStroked);
        canvas->drawRect(fastBound, blueStroked);
=======
            canvas->translate(SkIntToScalar(off.fX), SkIntToScalar(off.fY));
            canvas->scale(1.5f, 1.5f);

            const SkRect& fastBound = p.computeFastBounds(r, &storage);

            canvas->save();
                canvas->clipRect(fastBound);
                (*draw)(canvas, r, p);
            canvas->restore();

            canvas->drawRect(r, redStroked);
            canvas->drawRect(fastBound, blueStroked);
>>>>>>> miniblink49
        canvas->restore();
    }

    static void draw_savelayer_with_paint(const SkIPoint& off,
<<<<<<< HEAD
        SkCanvas* canvas,
        const SkPaint& p)
    {
=======
                                          SkCanvas* canvas,
                                          const SkPaint& p) {
>>>>>>> miniblink49
        SkPaint redStroked;
        redStroked.setColor(SK_ColorRED);
        redStroked.setStyle(SkPaint::kStroke_Style);

        SkPaint blueStroked;
        blueStroked.setColor(SK_ColorBLUE);
        blueStroked.setStyle(SkPaint::kStroke_Style);

        const SkRect bounds = SkRect::MakeWH(10, 10);
        SkRect storage;

        canvas->save();
<<<<<<< HEAD
        canvas->translate(30, 30);
        canvas->translate(SkIntToScalar(off.fX), SkIntToScalar(off.fY));
        canvas->scale(1.5f, 1.5f);

        const SkRect& fastBound = p.computeFastBounds(bounds, &storage);

        canvas->saveLayer(&fastBound, &p);
        canvas->restore();

        canvas->drawRect(bounds, redStroked);
        canvas->drawRect(fastBound, blueStroked);
        canvas->restore();
    }

    void onDraw(SkCanvas* canvas) override
    {
=======
            canvas->translate(30, 30);
            canvas->translate(SkIntToScalar(off.fX), SkIntToScalar(off.fY));
            canvas->scale(1.5f, 1.5f);

            const SkRect& fastBound = p.computeFastBounds(bounds, &storage);

            canvas->saveLayer(&fastBound, &p);
            canvas->restore();

            canvas->drawRect(bounds, redStroked);
            canvas->drawRect(fastBound, blueStroked);
        canvas->restore();
    }

    void onDraw(SkCanvas* canvas) override{
>>>>>>> miniblink49

        SkPaint blackFill;

        //-----------
        // Normal paints (no source)
        SkTArray<SkPaint> paints;
<<<<<<< HEAD
        create_paints(&paints, nullptr);

        //-----------
        // Paints with a PictureImageFilter as a source
        sk_sp<SkPicture> pic;
=======
        create_paints(NULL, &paints);

        //-----------
        // Paints with a PictureImageFilter as a source
        SkAutoTUnref<SkPicture> pic;
>>>>>>> miniblink49

        {
            SkPictureRecorder rec;

            SkCanvas* c = rec.beginRecording(10, 10);
            c->drawRect(SkRect::MakeWH(10, 10), blackFill);
<<<<<<< HEAD
            pic = rec.finishRecordingAsPicture();
        }

        SkTArray<SkPaint> pifPaints;
        create_paints(&pifPaints, SkPictureImageFilter::Make(pic));

        //-----------
        // Paints with a SkImageSource as a source

        auto surface(SkSurface::MakeRasterN32Premul(10, 10));
        {
            SkPaint p;
            SkCanvas* temp = surface->getCanvas();
            temp->clear(SK_ColorYELLOW);
            p.setColor(SK_ColorBLUE);
            temp->drawRect(SkRect::MakeLTRB(5, 5, 10, 10), p);
            p.setColor(SK_ColorGREEN);
            temp->drawRect(SkRect::MakeLTRB(5, 0, 10, 5), p);
        }

        sk_sp<SkImage> image(surface->makeImageSnapshot());
        sk_sp<SkImageFilter> imageSource(SkImageSource::Make(std::move(image)));
        SkTArray<SkPaint> bmsPaints;
        create_paints(&bmsPaints, std::move(imageSource));
=======
            pic.reset(rec.endRecording());
        }

        SkAutoTUnref<SkPictureImageFilter> pif(SkPictureImageFilter::Create(pic));

        SkTArray<SkPaint> pifPaints;
        create_paints(pif, &pifPaints);

        //-----------
        // Paints with a BitmapSource as a source
        SkBitmap bm;

        {
            SkPaint p;
            bm.allocN32Pixels(10, 10);
            SkCanvas temp(bm);
            temp.clear(SK_ColorYELLOW);
            p.setColor(SK_ColorBLUE);
            temp.drawRect(SkRect::MakeLTRB(5, 5, 10, 10), p);
            p.setColor(SK_ColorGREEN);
            temp.drawRect(SkRect::MakeLTRB(5, 0, 10, 5), p);
        }

        SkAutoTUnref<SkBitmapSource> bms(SkBitmapSource::Create(bm));

        SkTArray<SkPaint> bmsPaints;
        create_paints(bms, &bmsPaints);
>>>>>>> miniblink49

        //-----------
        SkASSERT(paints.count() == kNumVertTiles);
        SkASSERT(paints.count() == pifPaints.count());
        SkASSERT(paints.count() == bmsPaints.count());

        // horizontal separators
        for (int i = 1; i < paints.count(); ++i) {
            canvas->drawLine(0,
<<<<<<< HEAD
                i * SkIntToScalar(kTileHeight),
                SkIntToScalar((SK_ARRAY_COUNT(gDrawMthds) + kNumXtraCols) * kTileWidth),
                i * SkIntToScalar(kTileHeight),
                blackFill);
=======
                             i*SkIntToScalar(kTileHeight),
                             SkIntToScalar((SK_ARRAY_COUNT(gDrawMthds) + kNumXtraCols)*kTileWidth),
                             i*SkIntToScalar(kTileHeight),
                             blackFill);
>>>>>>> miniblink49
        }
        // vertical separators
        for (int i = 0; i < (int)SK_ARRAY_COUNT(gDrawMthds) + kNumXtraCols; ++i) {
            canvas->drawLine(SkIntToScalar(i * kTileWidth),
<<<<<<< HEAD
                0,
                SkIntToScalar(i * kTileWidth),
                SkIntToScalar(paints.count() * kTileWidth),
                blackFill);
=======
                             0,
                             SkIntToScalar(i * kTileWidth), 
                             SkIntToScalar(paints.count() * kTileWidth),
                             blackFill);
>>>>>>> miniblink49
        }

        // A column of saveLayers with PictureImageFilters
        for (int i = 0; i < pifPaints.count(); ++i) {
<<<<<<< HEAD
            draw_savelayer_with_paint(SkIPoint::Make(0, i * kTileHeight),
                canvas, pifPaints[i]);
=======
            draw_savelayer_with_paint(SkIPoint::Make(0, i*kTileHeight), 
                                      canvas, pifPaints[i]);
>>>>>>> miniblink49
        }

        // A column of saveLayers with BitmapSources
        for (int i = 0; i < pifPaints.count(); ++i) {
<<<<<<< HEAD
            draw_savelayer_with_paint(SkIPoint::Make(kTileWidth, i * kTileHeight),
                canvas, bmsPaints[i]);
=======
            draw_savelayer_with_paint(SkIPoint::Make(kTileWidth, i*kTileHeight),
                                      canvas, bmsPaints[i]);
>>>>>>> miniblink49
        }

        // Multiple columns with different geometry
        for (int i = 0; i < (int)SK_ARRAY_COUNT(gDrawMthds); ++i) {
            for (int j = 0; j < paints.count(); ++j) {
                draw_geom_with_paint(*gDrawMthds[i],
<<<<<<< HEAD
                    SkIPoint::Make((i + kNumXtraCols) * kTileWidth, j * kTileHeight),
                    canvas, paints[j]);
            }
        }
=======
                                     SkIPoint::Make((i+kNumXtraCols) * kTileWidth, j*kTileHeight),
                                     canvas, paints[j]);
            }
        }

>>>>>>> miniblink49
    }

private:
    typedef GM INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
DEF_GM(return new ImageFilterFastBoundGM;)
=======
DEF_GM(return SkNEW(ImageFilterFastBoundGM);)

>>>>>>> miniblink49
}
