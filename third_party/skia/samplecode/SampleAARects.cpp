<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#include "SampleCode.h"
<<<<<<< HEAD
#include "SkCanvas.h"
#include "SkPaint.h"
#include "SkShader.h"
#include "SkView.h"

static SkBitmap createBitmap(int n)
{
=======
#include "SkView.h"
#include "SkCanvas.h"
#include "SkDevice.h"
#include "SkPaint.h"
#include "SkShader.h"

static SkBitmap createBitmap(int n) {
>>>>>>> miniblink49
    SkBitmap bitmap;
    bitmap.allocN32Pixels(n, n);
    bitmap.eraseColor(SK_ColorGREEN);

    SkCanvas canvas(bitmap);
    SkRect r;
    r.set(0, 0, SkIntToScalar(n), SkIntToScalar(n));
    SkPaint paint;
    paint.setAntiAlias(true);

    paint.setColor(SK_ColorRED);
    canvas.drawOval(r, paint);
    paint.setColor(SK_ColorBLUE);
<<<<<<< HEAD
    paint.setStrokeWidth(SkIntToScalar(n) / 15);
=======
    paint.setStrokeWidth(SkIntToScalar(n)/15);
>>>>>>> miniblink49
    paint.setStyle(SkPaint::kStroke_Style);
    canvas.drawLine(0, 0, r.fRight, r.fBottom, paint);
    canvas.drawLine(0, r.fBottom, r.fRight, 0, paint);

    return bitmap;
}

class AARectView : public SampleView {
    SkBitmap fBitmap;
    enum {
        N = 64
    };
<<<<<<< HEAD

public:
    AARectView()
    {
=======
public:
    AARectView() {
>>>>>>> miniblink49
        fBitmap = createBitmap(N);

        fWidth = N;
    }

protected:
    // overrides from SkEventSink
<<<<<<< HEAD
    virtual bool onQuery(SkEvent* evt)
    {
=======
    virtual bool onQuery(SkEvent* evt) {
>>>>>>> miniblink49
        if (SampleCode::TitleQ(*evt)) {
            SampleCode::TitleR(evt, "AA Rects");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

<<<<<<< HEAD
    virtual void onDrawContent(SkCanvas* canvas)
    {
=======
    virtual void onDrawContent(SkCanvas* canvas) {
>>>>>>> miniblink49
        canvas->translate(SkIntToScalar(10), SkIntToScalar(10));

        SkPaint bluePaint;
        bluePaint.setARGB(0xff, 0x0, 0x0, 0xff);
        SkPaint bmpPaint;
<<<<<<< HEAD
        bmpPaint.setShader(SkShader::MakeBitmapShader(fBitmap, SkShader::kRepeat_TileMode,
            SkShader::kRepeat_TileMode));
=======
        SkShader* bmpShader = SkShader::CreateBitmapShader(fBitmap, SkShader::kRepeat_TileMode, SkShader::kRepeat_TileMode);
        bmpPaint.setShader(bmpShader);
        bmpShader->unref();

>>>>>>> miniblink49
        bluePaint.setStrokeWidth(3);
        bmpPaint.setStrokeWidth(3);

        SkPaint paints[] = { bluePaint, bmpPaint };

        SkRect rect;

        SkScalar dx = SkIntToScalar(80);
        SkScalar dy = SkIntToScalar(100);
        SkMatrix matrix;
        for (size_t p = 0; p < SK_ARRAY_COUNT(paints); ++p) {
            for (int stroke = 0; stroke < 2; ++stroke) {
                paints[p].setStyle(stroke ? SkPaint::kStroke_Style : SkPaint::kFill_Style);
<<<<<<< HEAD
                for (int a = 0; a < 3; ++a) {
=======
                for (int a = 0; a < 3; ++ a) {
>>>>>>> miniblink49
                    paints[p].setAntiAlias(a > 0);
                    paints[p].setAlpha(a > 1 ? 0x80 : 0xff);

                    canvas->save();
<<<<<<< HEAD
                    rect = SkRect::MakeLTRB(0.f,
                        0.f,
                        40.f,
                        40.f);
                    canvas->drawRect(rect, paints[p]);
                    canvas->translate(dx, 0);

                    rect = SkRect::MakeLTRB(0.5f,
                        0.5f,
                        40.5f,
                        40.5f);
                    canvas->drawRect(rect, paints[p]);
                    canvas->translate(dx, 0);

                    rect = SkRect::MakeLTRB(0.5f,
                        0.5f,
                        40.f,
                        40.f);
                    canvas->drawRect(rect, paints[p]);
                    canvas->translate(dx, 0);

                    rect = SkRect::MakeLTRB(0.75f,
                        0.75f,
                        40.75f,
                        40.75f);
                    canvas->drawRect(rect, paints[p]);
                    canvas->translate(dx, 0);

                    canvas->save();
                    canvas->translate(.33f, .67f);
                    rect = SkRect::MakeLTRB(0.0f,
                        0.0f,
                        40.0f,
                        40.0f);
                    canvas->drawRect(rect, paints[p]);
                    canvas->restore();
                    canvas->translate(dx, 0);

                    canvas->save();
                    matrix.setRotate(45.f);
                    canvas->concat(matrix);
                    canvas->translate(20.0f / sqrtf(2.f),
                        20.0f / sqrtf(2.f));
                    rect = SkRect::MakeLTRB(-20.0f,
                        -20.0f,
                        20.0f,
                        20.0f);
                    canvas->drawRect(rect, paints[p]);
                    canvas->restore();
                    canvas->translate(dx, 0);

                    canvas->save();
                    canvas->rotate(90.f);
                    rect = SkRect::MakeLTRB(0.0f,
                        0.0f,
                        40.0f,
                        -40.0f);
                    canvas->drawRect(rect, paints[p]);
                    canvas->restore();
                    canvas->translate(dx, 0);

                    canvas->save();
                    canvas->rotate(90.f);
                    rect = SkRect::MakeLTRB(0.5f,
                        0.5f,
                        40.5f,
                        -40.5f);
                    canvas->drawRect(rect, paints[p]);
                    canvas->restore();
                    canvas->translate(dx, 0);

                    canvas->save();
                    matrix.setScale(-1.f, -1.f);
                    canvas->concat(matrix);
                    rect = SkRect::MakeLTRB(0.5f,
                        0.5f,
                        -40.5f,
                        -40.5f);
                    canvas->drawRect(rect, paints[p]);
                    canvas->restore();
                    canvas->translate(dx, 0);

                    canvas->save();
                    matrix.setScale(2.1f, 4.1f);
                    canvas->concat(matrix);
                    rect = SkRect::MakeLTRB(0.1f,
                        0.1f,
                        19.1f,
                        9.1f);
                    canvas->drawRect(rect, paints[p]);
                    canvas->restore();
                    canvas->translate(dx, 0);
=======
                        rect = SkRect::MakeLTRB(0.f,
                                                0.f,
                                                40.f,
                                                40.f);
                        canvas->drawRect(rect, paints[p]);
                        canvas->translate(dx, 0);

                        rect = SkRect::MakeLTRB(0.5f,
                                                0.5f,
                                                40.5f,
                                                40.5f);
                        canvas->drawRect(rect, paints[p]);
                        canvas->translate(dx, 0);

                        rect = SkRect::MakeLTRB(0.5f,
                                                0.5f,
                                                40.f,
                                                40.f);
                        canvas->drawRect(rect, paints[p]);
                        canvas->translate(dx, 0);

                        rect = SkRect::MakeLTRB(0.75f,
                                                0.75f,
                                                40.75f,
                                                40.75f);
                        canvas->drawRect(rect, paints[p]);
                        canvas->translate(dx, 0);

                        canvas->save();
                            canvas->translate(.33f, .67f);
                            rect = SkRect::MakeLTRB(0.0f,
                                                    0.0f,
                                                    40.0f,
                                                    40.0f);
                            canvas->drawRect(rect, paints[p]);
                        canvas->restore();
                        canvas->translate(dx, 0);

                        canvas->save();
                            matrix.setRotate(45.f);
                            canvas->concat(matrix);
                            canvas->translate(20.0f / sqrtf(2.f),
                                                20.0f / sqrtf(2.f));
                            rect = SkRect::MakeLTRB(-20.0f,
                                                    -20.0f,
                                                    20.0f,
                                                    20.0f);
                            canvas->drawRect(rect, paints[p]);
                        canvas->restore();
                        canvas->translate(dx, 0);

                        canvas->save();
                            canvas->rotate(90.f);
                            rect = SkRect::MakeLTRB(0.0f,
                                                    0.0f,
                                                    40.0f,
                                                    -40.0f);
                            canvas->drawRect(rect, paints[p]);
                        canvas->restore();
                        canvas->translate(dx, 0);

                        canvas->save();
                            canvas->rotate(90.f);
                            rect = SkRect::MakeLTRB(0.5f,
                                                    0.5f,
                                                    40.5f,
                                                    -40.5f);
                            canvas->drawRect(rect, paints[p]);
                        canvas->restore();
                        canvas->translate(dx, 0);

                        canvas->save();
                            matrix.setScale(-1.f, -1.f);
                            canvas->concat(matrix);
                            rect = SkRect::MakeLTRB(0.5f,
                                                    0.5f,
                                                    -40.5f,
                                                    -40.5f);
                            canvas->drawRect(rect, paints[p]);
                        canvas->restore();
                        canvas->translate(dx, 0);

                        canvas->save();
                            matrix.setScale(2.1f, 4.1f);
                            canvas->concat(matrix);
                            rect = SkRect::MakeLTRB(0.1f,
                                                    0.1f,
                                                    19.1f,
                                                    9.1f);
                            canvas->drawRect(rect, paints[p]);
                        canvas->restore();
                        canvas->translate(dx, 0);
>>>>>>> miniblink49

                    canvas->restore();
                    canvas->translate(0, dy);
                }
            }
        }
    }

private:
    int fWidth;

    typedef SampleView INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new AARectView; }
static SkViewRegister reg(MyFactory);
