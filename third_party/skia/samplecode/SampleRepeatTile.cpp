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
#include "SkKey.h"
#include "SkShader.h"
#include "SkView.h"

static void make_bitmap(SkBitmap* bm)
{
=======
#include "SkView.h"
#include "SkCanvas.h"
#include "SkShader.h"
#include "SkKey.h"

static void make_bitmap(SkBitmap* bm) {
>>>>>>> miniblink49
    const int W = 100;
    const int H = 100;
    bm->allocN32Pixels(W, H);

    SkPaint paint;
    SkCanvas canvas(*bm);
    canvas.drawColor(SK_ColorWHITE);

    const SkColor colors[] = {
        SK_ColorRED, SK_ColorGREEN, SK_ColorBLUE, SK_ColorWHITE
    };

    for (int ix = 0; ix < W; ix += 1) {
        SkScalar x = SkIntToScalar(ix) + SK_ScalarHalf;
        paint.setColor(colors[ix & 3]);
        canvas.drawLine(x, 0, x, SkIntToScalar(H - 1), paint);
    }
    paint.setColor(SK_ColorGRAY);
    canvas.drawLine(0, 0, SkIntToScalar(W), 0, paint);
}

<<<<<<< HEAD
static void make_paint(SkPaint* paint, SkShader::TileMode tm)
{
    SkBitmap bm;
    make_bitmap(&bm);

    paint->setShader(SkShader::MakeBitmapShader(bm, tm, tm));
=======
static void make_paint(SkPaint* paint, SkShader::TileMode tm) {
    SkBitmap bm;
    make_bitmap(&bm);

    SkShader* shader = SkShader::CreateBitmapShader(bm, tm, tm);
    paint->setShader(shader)->unref();
>>>>>>> miniblink49
}

class RepeatTileView : public SampleView {
public:
<<<<<<< HEAD
    RepeatTileView()
    {
=======
    RepeatTileView() {
>>>>>>> miniblink49
        this->setBGColor(SK_ColorGRAY);
    }

protected:
    // overrides from SkEventSink
<<<<<<< HEAD
    bool onQuery(SkEvent* evt) override
    {
=======
    bool onQuery(SkEvent* evt) override {
>>>>>>> miniblink49
        if (SampleCode::TitleQ(*evt)) {
            SampleCode::TitleR(evt, "RepeatTile");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

<<<<<<< HEAD
    void onDrawContent(SkCanvas* canvas) override
    {
        SkPaint paint;
        make_paint(&paint, SkShader::kRepeat_TileMode);

        //        canvas->scale(SK_Scalar1*2, SK_Scalar1);
=======
    void onDrawContent(SkCanvas* canvas) override {
        SkPaint paint;
        make_paint(&paint, SkShader::kRepeat_TileMode);

//        canvas->scale(SK_Scalar1*2, SK_Scalar1);
>>>>>>> miniblink49
        canvas->translate(SkIntToScalar(100), SkIntToScalar(100));
        canvas->drawPaint(paint);
    }

<<<<<<< HEAD
    SkView::Click* onFindClickHandler(SkScalar x, SkScalar y, unsigned modi) override
    {
        this->inval(nullptr);
=======
    SkView::Click* onFindClickHandler(SkScalar x, SkScalar y, unsigned modi) override {
        this->inval(NULL);
>>>>>>> miniblink49

        return this->INHERITED::onFindClickHandler(x, y, modi);
    }

<<<<<<< HEAD
    bool onClick(Click* click) override
    {
        return this->INHERITED::onClick(click);
    }

    virtual bool handleKey(SkKey)
    {
        this->inval(nullptr);
=======
    bool onClick(Click* click) override {
        return this->INHERITED::onClick(click);
    }

    virtual bool handleKey(SkKey) {
        this->inval(NULL);
>>>>>>> miniblink49
        return true;
    }

private:
    typedef SampleView INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new RepeatTileView; }
static SkViewRegister reg(MyFactory);
