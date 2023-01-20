/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkImage.h"
#include "SkImageSource.h"
#include "SkOffsetImageFilter.h"
#include "SkSurface.h"
#include "gm.h"
#include "sk_tool_utils.h"
=======
#include "sk_tool_utils.h"
#include "SkBitmapSource.h"
#include "SkOffsetImageFilter.h"
#include "gm.h"
>>>>>>> miniblink49

#define WIDTH 600
#define HEIGHT 100
#define MARGIN 12

class OffsetImageFilterGM : public skiagm::GM {
public:
<<<<<<< HEAD
    OffsetImageFilterGM()
    {
=======
    OffsetImageFilterGM() {
>>>>>>> miniblink49
        this->setBGColor(0xFF000000);
    }

protected:
<<<<<<< HEAD
    SkString onShortName() override
    {
        return SkString("offsetimagefilter");
    }

    SkISize onISize() override
    {
        return SkISize::Make(WIDTH, HEIGHT);
    }

    void onOnceBeforeDraw() override
    {
        fBitmap = SkImage::MakeFromBitmap(
            sk_tool_utils::create_string_bitmap(80, 80, 0xD000D000, 15, 65, 96, "e"));

        fCheckerboard = SkImage::MakeFromBitmap(
            sk_tool_utils::create_checkerboard_bitmap(80, 80,
                sk_tool_utils::color_to_565(0xFFA0A0A0),
                sk_tool_utils::color_to_565(0xFF404040),
                8));
    }

    void onDraw(SkCanvas* canvas) override
    {
        canvas->clear(SK_ColorBLACK);
        SkPaint paint;

        for (int i = 0; i < 4; i++) {
            sk_sp<SkImage> image = (i & 0x01) ? fCheckerboard : fBitmap;
            SkIRect cropRect = SkIRect::MakeXYWH(i * 12,
                i * 8,
                image->width() - i * 8,
                image->height() - i * 12);
            SkImageFilter::CropRect rect(SkRect::Make(cropRect));
            sk_sp<SkImageFilter> tileInput(SkImageSource::Make(image));
            SkScalar dx = SkIntToScalar(i * 5);
            SkScalar dy = SkIntToScalar(i * 10);
            paint.setImageFilter(SkOffsetImageFilter::Make(dx, dy, std::move(tileInput), &rect));
            DrawClippedImage(canvas, image.get(), paint, 1, cropRect);
            canvas->translate(SkIntToScalar(image->width() + MARGIN), 0);
        }

        SkIRect cropRect = SkIRect::MakeXYWH(0, 0, 100, 100);
        SkImageFilter::CropRect rect(SkRect::Make(cropRect));
        paint.setImageFilter(SkOffsetImageFilter::Make(-5, -10, nullptr, &rect));
        DrawClippedImage(canvas, fBitmap.get(), paint, 2, cropRect);
    }

private:
    static void DrawClippedImage(SkCanvas* canvas, const SkImage* image, const SkPaint& paint,
        SkScalar scale, const SkIRect& cropRect)
    {
        SkRect clipRect = SkRect::MakeIWH(image->width(), image->height());
=======
    SkString onShortName() override {
        return SkString("offsetimagefilter");
    }

    void make_bitmap() {
        fBitmap.allocN32Pixels(80, 80);
        SkCanvas canvas(fBitmap);
        canvas.clear(0);
        SkPaint paint;
        paint.setAntiAlias(true);
        sk_tool_utils::set_portable_typeface(&paint);
        paint.setColor(0xD000D000);
        paint.setTextSize(96);
        canvas.drawText("e", 1, 15, 65, paint);
    }

    SkISize onISize() override {
        return SkISize::Make(WIDTH, HEIGHT);
    }

    void drawClippedBitmap(SkCanvas* canvas, const SkBitmap& bitmap, const SkPaint& paint,
                           SkScalar scale, const SkIRect& cropRect) {
        SkRect clipRect = SkRect::MakeIWH(bitmap.width(), bitmap.height());
>>>>>>> miniblink49

        canvas->save();
        canvas->clipRect(clipRect);
        canvas->scale(scale, scale);
<<<<<<< HEAD
        canvas->drawImage(image, 0, 0, &paint);
=======
        canvas->drawBitmap(bitmap, 0, 0, &paint);
>>>>>>> miniblink49
        canvas->restore();

        // Draw a boundary rect around the intersection of the clip rect and crop rect.
        SkRect cropRectFloat;
        SkMatrix::MakeScale(scale, scale).mapRect(&cropRectFloat, SkRect::Make(cropRect));
        if (clipRect.intersect(cropRectFloat)) {
            SkPaint strokePaint;
            strokePaint.setStyle(SkPaint::kStroke_Style);
<<<<<<< HEAD
            strokePaint.setStrokeWidth(2);
=======
>>>>>>> miniblink49
            strokePaint.setColor(SK_ColorRED);
            canvas->drawRect(clipRect, strokePaint);
        }
    }

<<<<<<< HEAD
    sk_sp<SkImage> fBitmap, fCheckerboard;

    typedef skiagm::GM INHERITED;
};
DEF_GM(return new OffsetImageFilterGM;)
=======
    void onOnceBeforeDraw() override {
        make_bitmap();
        
        fCheckerboard.allocN32Pixels(80, 80);
        SkCanvas checkerboardCanvas(fCheckerboard);
        sk_tool_utils::draw_checkerboard(&checkerboardCanvas, 0xFFA0A0A0, 0xFF404040, 8);
    }

    void onDraw(SkCanvas* canvas) override {
        canvas->clear(SK_ColorBLACK);
        SkPaint paint;

        for (int i = 0; i < 4; i++) {
            const SkBitmap* bitmap = (i & 0x01) ? &fCheckerboard : &fBitmap;
            SkIRect cropRect = SkIRect::MakeXYWH(i * 12,
                                                 i * 8,
                                                 bitmap->width() - i * 8,
                                                 bitmap->height() - i * 12);
            SkImageFilter::CropRect rect(SkRect::Make(cropRect));
            SkAutoTUnref<SkImageFilter> tileInput(SkBitmapSource::Create(*bitmap));
            SkScalar dx = SkIntToScalar(i*5);
            SkScalar dy = SkIntToScalar(i*10);
            SkAutoTUnref<SkImageFilter> filter(SkOffsetImageFilter::Create(dx, dy, tileInput,
                                                                           &rect));
            paint.setImageFilter(filter);
            drawClippedBitmap(canvas, *bitmap, paint, 1, cropRect);
            canvas->translate(SkIntToScalar(bitmap->width() + MARGIN), 0);
        }

        SkIRect cropRect = SkIRect::MakeXYWH(0, 0, 100, 100);
        SkImageFilter::CropRect rect(SkRect::Make(cropRect));
        SkAutoTUnref<SkImageFilter> filter(SkOffsetImageFilter::Create(-5, -10, NULL, &rect));
        paint.setImageFilter(filter);
        drawClippedBitmap(canvas, fBitmap, paint, 2, cropRect);
    }
private:
    typedef skiagm::GM INHERITED;
    SkBitmap fBitmap, fCheckerboard;
};
DEF_GM( return new OffsetImageFilterGM; )
>>>>>>> miniblink49

//////////////////////////////////////////////////////////////////////////////

class SimpleOffsetImageFilterGM : public skiagm::GM {
public:
<<<<<<< HEAD
    SimpleOffsetImageFilterGM() { }

protected:
    SkString onShortName() override
    {
        return SkString("simple-offsetimagefilter");
    }

    SkISize onISize() override { return SkISize::Make(640, 200); }

    void doDraw(SkCanvas* canvas, const SkRect& r, sk_sp<SkImageFilter> imgf,
        const SkRect* clipR = nullptr)
    {
=======
    SimpleOffsetImageFilterGM() {}
    
protected:
    SkString onShortName() override {
        return SkString("simple-offsetimagefilter");
    }
    
    SkISize onISize() override { return SkISize::Make(640, 200); }
    
    void doDraw(SkCanvas* canvas, const SkRect& r, SkImageFilter* imgf,
                const SkRect* clipR = NULL) {
>>>>>>> miniblink49
        SkPaint p;

        if (clipR) {
            p.setColor(0xFF00FF00);
            p.setStyle(SkPaint::kStroke_Style);
            canvas->drawRect(clipR->makeInset(SK_ScalarHalf, SK_ScalarHalf), p);
            p.setStyle(SkPaint::kFill_Style);
        }

        if (imgf && imgf->cropRectIsSet()) {
            SkImageFilter::CropRect cr = imgf->getCropRect();

            p.setColor(0x66FF00FF);
            p.setStyle(SkPaint::kStroke_Style);
            canvas->drawRect(cr.rect().makeInset(SK_ScalarHalf, SK_ScalarHalf), p);
            p.setStyle(SkPaint::kFill_Style);
        }

        p.setColor(0x660000FF);
        canvas->drawRect(r, p);

        if (clipR) {
            canvas->save();
            canvas->clipRect(*clipR);
        }
        if (imgf) {
<<<<<<< HEAD
            p.setImageFilter(std::move(imgf));
=======
            p.setImageFilter(imgf)->unref();
>>>>>>> miniblink49
        }
        p.setColor(0x66FF0000);
        canvas->drawRect(r, p);

        if (clipR) {
            canvas->restore();
        }
    }

<<<<<<< HEAD
    void onDraw(SkCanvas* canvas) override
    {
=======
    void onDraw(SkCanvas* canvas) override {
>>>>>>> miniblink49
        const SkRect r = SkRect::MakeWH(40, 40);
        SkImageFilter::CropRect cr0(r);
        SkImageFilter::CropRect cr1(SkRect::MakeWH(20, 20));
        const SkRect r2 = SkRect::MakeXYWH(40, 0, 40, 40);
        SkImageFilter::CropRect cr2(r2);

        canvas->translate(40, 40);
<<<<<<< HEAD

        canvas->save();
        this->doDraw(canvas, r, nullptr);

        canvas->translate(100, 0);
        this->doDraw(canvas, r, SkOffsetImageFilter::Make(20, 20, nullptr));

        canvas->translate(100, 0);
        this->doDraw(canvas, r, SkOffsetImageFilter::Make(20, 20, nullptr, &cr0));

        canvas->translate(100, 0);
        this->doDraw(canvas, r, SkOffsetImageFilter::Make(20, 20, nullptr), &r);

        canvas->translate(100, 0);
        this->doDraw(canvas, r, SkOffsetImageFilter::Make(20, 20, nullptr, &cr1));

        SkRect clipR = SkRect::MakeXYWH(40, 40, 40, 40);
        canvas->translate(100, 0);
        this->doDraw(canvas, r, SkOffsetImageFilter::Make(20, 20, nullptr, nullptr), &clipR);
=======
        
        canvas->save();
        this->doDraw(canvas, r, NULL);
        
        canvas->translate(100, 0);
        this->doDraw(canvas, r, SkOffsetImageFilter::Create(20, 20));
        
        canvas->translate(100, 0);
        this->doDraw(canvas, r, SkOffsetImageFilter::Create(20, 20, NULL, &cr0));
        
        canvas->translate(100, 0);
        this->doDraw(canvas, r, SkOffsetImageFilter::Create(20, 20), &r);
        
        canvas->translate(100, 0);
        this->doDraw(canvas, r, SkOffsetImageFilter::Create(20, 20, NULL, &cr1));
        
        SkRect clipR = SkRect::MakeXYWH(40, 40, 40, 40);
        canvas->translate(100, 0);
        this->doDraw(canvas, r, SkOffsetImageFilter::Create(20, 20, NULL, NULL), &clipR);
>>>>>>> miniblink49
        canvas->restore();

        // 2nd row
        canvas->translate(0, 80);

        /*
         *  combos of clip and crop rects that align with src and dst
         */

        // crop==clip==src
<<<<<<< HEAD
        this->doDraw(canvas, r, SkOffsetImageFilter::Make(40, 0, nullptr, &cr0), &r);

        // crop==src, clip==dst
        canvas->translate(100, 0);
        this->doDraw(canvas, r, SkOffsetImageFilter::Make(40, 0, nullptr, &cr0), &r2);

        // crop==dst, clip==src
        canvas->translate(100, 0);
        this->doDraw(canvas, r, SkOffsetImageFilter::Make(40, 0, nullptr, &cr2), &r);

        // crop==clip==dst
        canvas->translate(100, 0);
        this->doDraw(canvas, r, SkOffsetImageFilter::Make(40, 0, nullptr, &cr2), &r2);
=======
        this->doDraw(canvas, r, SkOffsetImageFilter::Create(40, 0, NULL, &cr0), &r);

        // crop==src, clip==dst
        canvas->translate(100, 0);
        this->doDraw(canvas, r, SkOffsetImageFilter::Create(40, 0, NULL, &cr0), &r2);

        // crop==dst, clip==src
        canvas->translate(100, 0);
        this->doDraw(canvas, r, SkOffsetImageFilter::Create(40, 0, NULL, &cr2), &r);

        // crop==clip==dst
        canvas->translate(100, 0);
        this->doDraw(canvas, r, SkOffsetImageFilter::Create(40, 0, NULL, &cr2), &r2);
>>>>>>> miniblink49
    }

private:
    typedef skiagm::GM INHERITED;
};
<<<<<<< HEAD
DEF_GM(return new SimpleOffsetImageFilterGM;)
=======
DEF_GM( return new SimpleOffsetImageFilterGM; )
>>>>>>> miniblink49
