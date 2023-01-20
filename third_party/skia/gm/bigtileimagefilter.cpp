/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkImageSource.h"
#include "SkSurface.h"
#include "SkTileImageFilter.h"
#include "gm.h"

static sk_sp<SkImage> create_circle_texture(int size, SkColor color)
{
    auto surface(SkSurface::MakeRasterN32Premul(size, size));
    SkCanvas* canvas = surface->getCanvas();
    canvas->clear(0xFF000000);
=======
#include "SkBitmapSource.h"
#include "SkTileImageFilter.h"
#include "gm.h"

static void create_circle_texture(SkBitmap* bm, SkColor color) {
    SkCanvas canvas(*bm);
    canvas.clear(0xFF000000);
>>>>>>> miniblink49

    SkPaint paint;
    paint.setColor(color);
    paint.setStrokeWidth(3);
    paint.setStyle(SkPaint::kStroke_Style);

<<<<<<< HEAD
    canvas->drawCircle(SkScalarHalf(size), SkScalarHalf(size), SkScalarHalf(size), paint);

    return surface->makeImageSnapshot();
=======
    canvas.drawCircle(SkScalarHalf(bm->width()), SkScalarHalf(bm->height()),
                      SkScalarHalf(bm->width()), paint);
>>>>>>> miniblink49
}

namespace skiagm {

class BigTileImageFilterGM : public GM {
public:
<<<<<<< HEAD
    BigTileImageFilterGM()
    {
=======
    BigTileImageFilterGM() {
>>>>>>> miniblink49
        this->setBGColor(0xFF000000);
    }

protected:
<<<<<<< HEAD
    SkString onShortName() override
    {
        return SkString("bigtileimagefilter");
    }

    SkISize onISize() override
    {
        return SkISize::Make(kWidth, kHeight);
    }

    void onOnceBeforeDraw() override
    {
        fRedImage = create_circle_texture(kBitmapSize, SK_ColorRED);
        fGreenImage = create_circle_texture(kBitmapSize, SK_ColorGREEN);
    }

    void onDraw(SkCanvas* canvas) override
    {
=======

    SkString onShortName() override {
        return SkString("bigtileimagefilter");
    }

    SkISize onISize() override{
        return SkISize::Make(kWidth, kHeight);
    }

    void onOnceBeforeDraw() override {
        fRedBitmap.allocN32Pixels(kBitmapSize, kBitmapSize);
        create_circle_texture(&fRedBitmap, SK_ColorRED);

        fGreenBitmap.allocN32Pixels(kBitmapSize, kBitmapSize);
        create_circle_texture(&fGreenBitmap, SK_ColorGREEN);
    }

    void onDraw(SkCanvas* canvas) override {
>>>>>>> miniblink49
        canvas->clear(SK_ColorBLACK);

        {
            SkPaint p;

<<<<<<< HEAD
            const SkRect bound = SkRect::MakeIWH(kWidth, kHeight);
            sk_sp<SkImageFilter> imageSource(SkImageSource::Make(fRedImage));

            sk_sp<SkImageFilter> tif(SkTileImageFilter::Make(
                SkRect::MakeIWH(kBitmapSize, kBitmapSize),
                SkRect::MakeIWH(kWidth, kHeight),
                std::move(imageSource)));

            p.setImageFilter(std::move(tif));
=======
            SkRect bound = SkRect::MakeWH(SkIntToScalar(kWidth), SkIntToScalar(kHeight));
            SkAutoTUnref<SkBitmapSource> bms(SkBitmapSource::Create(fRedBitmap));
            SkAutoTUnref<SkTileImageFilter> tif(SkTileImageFilter::Create(
                            SkRect::MakeWH(SkIntToScalar(kBitmapSize), SkIntToScalar(kBitmapSize)),
                            SkRect::MakeWH(SkIntToScalar(kWidth), SkIntToScalar(kHeight)),
                            bms));
            p.setImageFilter(tif);
>>>>>>> miniblink49

            canvas->saveLayer(&bound, &p);
            canvas->restore();
        }

        {
            SkPaint p2;

<<<<<<< HEAD
            const SkRect bound2 = SkRect::MakeIWH(kBitmapSize, kBitmapSize);

            sk_sp<SkImageFilter> tif(SkTileImageFilter::Make(
                SkRect::MakeIWH(kBitmapSize, kBitmapSize),
                SkRect::MakeIWH(kBitmapSize, kBitmapSize),
                nullptr));

            p2.setImageFilter(std::move(tif));
=======
            SkRect bound2 = SkRect::MakeWH(SkIntToScalar(kBitmapSize), SkIntToScalar(kBitmapSize));

            SkAutoTUnref<SkTileImageFilter> tif2(SkTileImageFilter::Create(
                            SkRect::MakeWH(SkIntToScalar(kBitmapSize), SkIntToScalar(kBitmapSize)),
                            SkRect::MakeWH(SkIntToScalar(kBitmapSize), SkIntToScalar(kBitmapSize)),
                            NULL));
            p2.setImageFilter(tif2);
>>>>>>> miniblink49

            canvas->translate(320, 320);
            canvas->saveLayer(&bound2, &p2);
            canvas->setMatrix(SkMatrix::I());

            SkRect bound3 = SkRect::MakeXYWH(320, 320,
<<<<<<< HEAD
                SkIntToScalar(kBitmapSize),
                SkIntToScalar(kBitmapSize));
            canvas->drawImageRect(fGreenImage.get(), bound2, bound3, nullptr,
                SkCanvas::kStrict_SrcRectConstraint);
=======
                                             SkIntToScalar(kBitmapSize),
                                             SkIntToScalar(kBitmapSize));
            canvas->drawBitmapRectToRect(fGreenBitmap, &bound2, bound3);
>>>>>>> miniblink49
            canvas->restore();
        }
    }

private:
    static const int kWidth = 512;
    static const int kHeight = 512;
    static const int kBitmapSize = 64;

<<<<<<< HEAD
    sk_sp<SkImage> fRedImage;
    sk_sp<SkImage> fGreenImage;
=======
    SkBitmap fRedBitmap;
    SkBitmap fGreenBitmap;
>>>>>>> miniblink49

    typedef GM INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
DEF_GM(return new BigTileImageFilterGM;)
=======
DEF_GM( return SkNEW(BigTileImageFilterGM); )

>>>>>>> miniblink49
}
