/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkColorFilterImageFilter.h"
#include "SkColorMatrixFilter.h"
#include "SkImage.h"
#include "SkImageSource.h"
#include "SkTileImageFilter.h"
#include "gm.h"
#include "sk_tool_utils.h"

#define WIDTH 400
#define HEIGHT 200
#define MARGIN 12

=======
#include "sk_tool_utils.h"
#include "SkBitmapSource.h"
#include "SkColorFilterImageFilter.h"
#include "SkColorMatrixFilter.h"
#include "SkTileImageFilter.h"
#include "gm.h"

#define WIDTH 400
#define HEIGHT 100
#define MARGIN 12

static SkBitmap make_bitmap() {
    SkBitmap bitmap;
    bitmap.allocN32Pixels(50, 50);
    SkCanvas canvas(bitmap);
    canvas.clear(0xFF000000);
    SkPaint paint;
    paint.setAntiAlias(true);
    sk_tool_utils::set_portable_typeface(&paint);
    paint.setColor(0xD000D000);
    paint.setTextSize(SkIntToScalar(50));
    const char* str = "e";
    canvas.drawText(str, strlen(str), SkIntToScalar(10), SkIntToScalar(45), paint);
    return bitmap;
}


>>>>>>> miniblink49
namespace skiagm {

class TileImageFilterGM : public GM {
public:
<<<<<<< HEAD
    TileImageFilterGM()
    {
=======
    TileImageFilterGM() {
>>>>>>> miniblink49
        this->setBGColor(0xFF000000);
    }

protected:
<<<<<<< HEAD
    SkString onShortName() override
    {
        return SkString("tileimagefilter");
    }

    SkISize onISize() override
    {
        return SkISize::Make(WIDTH, HEIGHT);
    }

    void onOnceBeforeDraw() override
    {
        fBitmap = SkImage::MakeFromBitmap(
            sk_tool_utils::create_string_bitmap(50, 50, 0xD000D000, 10, 45, 50, "e"));

        fCheckerboard = SkImage::MakeFromBitmap(
            sk_tool_utils::create_checkerboard_bitmap(80, 80,
                sk_tool_utils::color_to_565(0xFFA0A0A0),
                sk_tool_utils::color_to_565(0xFF404040),
                8));
    }

    void onDraw(SkCanvas* canvas) override
    {
        canvas->clear(SK_ColorBLACK);
        SkPaint red;
        red.setColor(SK_ColorRED);
        red.setStyle(SkPaint::kStroke_Style);
        SkPaint blue;
        blue.setColor(SK_ColorBLUE);
        blue.setStyle(SkPaint::kStroke_Style);

        int x = 0, y = 0;
        for (size_t i = 0; i < 4; i++) {
            sk_sp<SkImage> image = (i & 0x01) ? fCheckerboard : fBitmap;
            SkRect srcRect = SkRect::MakeXYWH(SkIntToScalar(image->width() / 4),
                SkIntToScalar(image->height() / 4),
                SkIntToScalar(image->width() / (i + 1)),
                SkIntToScalar(image->height() / (i + 1)));
            SkRect dstRect = SkRect::MakeXYWH(SkIntToScalar(i * 8),
                SkIntToScalar(i * 4),
                SkIntToScalar(image->width() - i * 12),
                SkIntToScalar(image->height()) - i * 12);
            sk_sp<SkImageFilter> tileInput(SkImageSource::Make(image));
            sk_sp<SkImageFilter> filter(SkTileImageFilter::Make(srcRect,
                dstRect,
                std::move(tileInput)));
            canvas->save();
            canvas->translate(SkIntToScalar(x), SkIntToScalar(y));
            SkPaint paint;
            paint.setImageFilter(std::move(filter));
            canvas->drawImage(fBitmap.get(), 0, 0, &paint);
            canvas->drawRect(srcRect, red);
            canvas->drawRect(dstRect, blue);
            canvas->restore();
            x += image->width() + MARGIN;
            if (x + image->width() > WIDTH) {
                x = 0;
                y += image->height() + MARGIN;
=======
    SkString onShortName() override {
        return SkString("tileimagefilter");
    }

    SkISize onISize() override{
        return SkISize::Make(WIDTH, HEIGHT);
    }

    void onOnceBeforeDraw() override {
        fBitmap = make_bitmap();

        fCheckerboard.allocN32Pixels(80, 80);
        SkCanvas checkerboardCanvas(fCheckerboard);
        sk_tool_utils::draw_checkerboard(&checkerboardCanvas, 0xFFA0A0A0, 0xFF404040, 8);
    }

    void onDraw(SkCanvas* canvas) override {
        canvas->clear(SK_ColorBLACK);

        int x = 0, y = 0;
        for (size_t i = 0; i < 4; i++) {
            SkBitmap* bitmap = (i & 0x01) ? &fCheckerboard : &fBitmap;
            SkRect srcRect = SkRect::MakeXYWH(SkIntToScalar(bitmap->width()/4),
                                              SkIntToScalar(bitmap->height()/4),
                                              SkIntToScalar(bitmap->width()/(i+1)),
                                              SkIntToScalar(bitmap->height()/(i+1)));
            SkRect dstRect = SkRect::MakeXYWH(SkIntToScalar(i * 8),
                                              SkIntToScalar(i * 4),
                                              SkIntToScalar(bitmap->width() - i * 12),
                                              SkIntToScalar(bitmap->height()) - i * 12);
            SkAutoTUnref<SkImageFilter> tileInput(SkBitmapSource::Create(*bitmap));
            SkAutoTUnref<SkImageFilter> filter(
                SkTileImageFilter::Create(srcRect, dstRect, tileInput));
            canvas->save();
            canvas->translate(SkIntToScalar(x), SkIntToScalar(y));
            SkPaint paint;
            paint.setImageFilter(filter);
            canvas->drawBitmap(fBitmap, 0, 0, &paint);
            canvas->restore();
            x += bitmap->width() + MARGIN;
            if (x + bitmap->width() > WIDTH) {
                x = 0;
                y += bitmap->height() + MARGIN;
>>>>>>> miniblink49
            }
        }

        SkScalar matrix[20] = { SK_Scalar1, 0, 0, 0, 0,
<<<<<<< HEAD
            0, SK_Scalar1, 0, 0, 0,
            0, 0, SK_Scalar1, 0, 0,
            0, 0, 0, SK_Scalar1, 0 };

        SkRect srcRect = SkRect::MakeWH(SkIntToScalar(fBitmap->width()),
            SkIntToScalar(fBitmap->height()));
        SkRect dstRect = SkRect::MakeWH(SkIntToScalar(fBitmap->width() * 2),
            SkIntToScalar(fBitmap->height() * 2));
        sk_sp<SkImageFilter> tile(SkTileImageFilter::Make(srcRect, dstRect, nullptr));
        sk_sp<SkColorFilter> cf(SkColorFilter::MakeMatrixFilterRowMajor255(matrix));

        SkPaint paint;
        paint.setImageFilter(SkColorFilterImageFilter::Make(std::move(cf), std::move(tile)));
=======
                                0, SK_Scalar1, 0, 0, 0,
                                0, 0, SK_Scalar1, 0, 0,
                                0, 0, 0, SK_Scalar1, 0 };

        SkRect srcRect = SkRect::MakeWH(SkIntToScalar(fBitmap.width()),
                                        SkIntToScalar(fBitmap.height()));
        SkRect dstRect = SkRect::MakeWH(SkIntToScalar(fBitmap.width() * 2),
                                        SkIntToScalar(fBitmap.height() * 2));
        SkAutoTUnref<SkImageFilter> tile(SkTileImageFilter::Create(srcRect, dstRect, NULL));
        SkAutoTUnref<SkColorFilter> cf(SkColorMatrixFilter::Create(matrix));

        SkAutoTUnref<SkImageFilter> cfif(SkColorFilterImageFilter::Create(cf, tile.get()));
        SkPaint paint;
        paint.setImageFilter(cfif);
>>>>>>> miniblink49
        canvas->save();
        canvas->translate(SkIntToScalar(x), SkIntToScalar(y));
        canvas->clipRect(dstRect);
        canvas->saveLayer(&dstRect, &paint);
<<<<<<< HEAD
        canvas->drawImage(fBitmap.get(), 0, 0);
        canvas->restore();
        canvas->drawRect(srcRect, red);
        canvas->drawRect(dstRect, blue);
        canvas->restore();

        canvas->translate(0, SkIntToScalar(100));

        srcRect = SkRect::MakeXYWH(0, 0, 50, 50);
        dstRect = SkRect::MakeXYWH(0, 0, 100, 100);
        SkImageFilter::CropRect cropRect(SkRect::MakeXYWH(5, 5, 40, 40));
        sk_sp<SkColorFilter> greenCF = SkColorFilter::MakeModeFilter(SK_ColorGREEN,
            SkXfermode::kSrc_Mode);
        sk_sp<SkImageFilter> green(SkColorFilterImageFilter::Make(std::move(greenCF),
            nullptr,
            &cropRect));
        tile = SkTileImageFilter::Make(srcRect, dstRect, std::move(green));
        paint.setColor(SK_ColorRED);
        paint.setImageFilter(std::move(tile));
        canvas->drawRect(dstRect, paint);
    }

private:
    sk_sp<SkImage> fBitmap, fCheckerboard;
=======
        canvas->drawBitmap(fBitmap, 0, 0);
        canvas->restore();
        canvas->restore();
    }
private:
    SkBitmap fBitmap;
    SkBitmap fCheckerboard;
>>>>>>> miniblink49

    typedef GM INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
DEF_GM(return new TileImageFilterGM;)
=======
DEF_GM( return SkNEW(TileImageFilterGM); )

>>>>>>> miniblink49
}
