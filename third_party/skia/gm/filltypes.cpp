<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
<<<<<<< HEAD

#include "SkPath.h"
=======
>>>>>>> miniblink49
#include "gm.h"

namespace skiagm {

class FillTypeGM : public GM {
    SkPath fPath;
<<<<<<< HEAD

public:
    FillTypeGM()
    {
        this->setBGColor(sk_tool_utils::color_to_565(0xFFDDDDDD));
    }

    void makePath()
    {
=======
public:
    FillTypeGM() {
        this->setBGColor(sk_tool_utils::color_to_565(0xFFDDDDDD));
    }

    void makePath() {
>>>>>>> miniblink49
        if (fPath.isEmpty()) {
            const SkScalar radius = SkIntToScalar(45);
            fPath.addCircle(SkIntToScalar(50), SkIntToScalar(50), radius);
            fPath.addCircle(SkIntToScalar(100), SkIntToScalar(100), radius);
        }
    }

protected:
<<<<<<< HEAD
    SkString onShortName() override
    {
        return SkString("filltypes");
    }

    SkISize onISize() override
    {
=======

    SkString onShortName() override {
        return SkString("filltypes");
    }

    SkISize onISize() override {
>>>>>>> miniblink49
        return SkISize::Make(835, 840);
    }

    void showPath(SkCanvas* canvas, int x, int y, SkPath::FillType ft,
<<<<<<< HEAD
        SkScalar scale, const SkPaint& paint)
    {
=======
                  SkScalar scale, const SkPaint& paint) {
>>>>>>> miniblink49
        const SkRect r = { 0, 0, SkIntToScalar(150), SkIntToScalar(150) };

        canvas->save();
        canvas->translate(SkIntToScalar(x), SkIntToScalar(y));
        canvas->clipRect(r);
        canvas->drawColor(SK_ColorWHITE);
        fPath.setFillType(ft);
        canvas->translate(r.centerX(), r.centerY());
        canvas->scale(scale, scale);
        canvas->translate(-r.centerX(), -r.centerY());
        canvas->drawPath(fPath, paint);
        canvas->restore();
    }

<<<<<<< HEAD
    void showFour(SkCanvas* canvas, SkScalar scale, const SkPaint& paint)
    {
        showPath(canvas, 0, 0, SkPath::kWinding_FillType,
            scale, paint);
        showPath(canvas, 200, 0, SkPath::kEvenOdd_FillType,
            scale, paint);
        showPath(canvas, 00, 200, SkPath::kInverseWinding_FillType,
            scale, paint);
        showPath(canvas, 200, 200, SkPath::kInverseEvenOdd_FillType,
            scale, paint);
    }

    void onDraw(SkCanvas* canvas) override
    {
=======
    void showFour(SkCanvas* canvas, SkScalar scale, const SkPaint& paint) {
        showPath(canvas,   0,   0, SkPath::kWinding_FillType,
                 scale, paint);
        showPath(canvas, 200,   0, SkPath::kEvenOdd_FillType,
                 scale, paint);
        showPath(canvas,  00, 200, SkPath::kInverseWinding_FillType,
                 scale, paint);
        showPath(canvas, 200, 200, SkPath::kInverseEvenOdd_FillType,
                 scale, paint);
    }

    void onDraw(SkCanvas* canvas) override {
>>>>>>> miniblink49
        this->makePath();

        canvas->translate(SkIntToScalar(20), SkIntToScalar(20));

        SkPaint paint;
<<<<<<< HEAD
        const SkScalar scale = SkIntToScalar(5) / 4;
=======
        const SkScalar scale = SkIntToScalar(5)/4;
>>>>>>> miniblink49

        paint.setAntiAlias(false);

        showFour(canvas, SK_Scalar1, paint);
        canvas->translate(SkIntToScalar(450), 0);
        showFour(canvas, scale, paint);

        paint.setAntiAlias(true);

        canvas->translate(SkIntToScalar(-450), SkIntToScalar(450));
        showFour(canvas, SK_Scalar1, paint);
        canvas->translate(SkIntToScalar(450), 0);
        showFour(canvas, scale, paint);
    }

private:
    typedef GM INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

static GM* MyFactory(void*) { return new FillTypeGM; }
static GMRegistry reg(MyFactory);

}
