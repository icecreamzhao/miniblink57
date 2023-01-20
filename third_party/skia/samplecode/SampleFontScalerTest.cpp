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
#include "Sk1DPathEffect.h"
#include "SkCanvas.h"
#include "SkColorFilter.h"
#include "SkColorPriv.h"
#include "SkCornerPathEffect.h"
#include "SkDither.h"
#include "SkPath.h"
#include "SkPathMeasure.h"
#include "SkRandom.h"
#include "SkRegion.h"
#include "SkShader.h"
#include "SkTypeface.h"
#include "SkUtils.h"
#include "SkView.h"

static const struct {
    const char* fName;
    SkTypeface::Style fStyle;
} gFaces[] = {
    { nullptr, SkTypeface::kNormal },
    { nullptr, SkTypeface::kBold },
=======
#include "SkView.h"
#include "SkCanvas.h"
#include "SkTypeface.h"
#include "SkPath.h"
#include "SkRegion.h"
#include "SkShader.h"
#include "SkUtils.h"
#include "Sk1DPathEffect.h"
#include "SkCornerPathEffect.h"
#include "SkPathMeasure.h"
#include "SkRandom.h"
#include "SkColorPriv.h"
#include "SkColorFilter.h"
#include "SkDither.h"

static const struct {
    const char* fName;
    SkTypeface::Style   fStyle;
} gFaces[] = {
    { NULL, SkTypeface::kNormal },
    { NULL, SkTypeface::kBold },
>>>>>>> miniblink49
    { "serif", SkTypeface::kNormal },
    { "serif", SkTypeface::kBold },
    { "serif", SkTypeface::kItalic },
    { "serif", SkTypeface::kBoldItalic },
    { "monospace", SkTypeface::kNormal }
};

static const int gFaceCount = SK_ARRAY_COUNT(gFaces);

class FontScalerTestView : public SampleView {
<<<<<<< HEAD
    sk_sp<SkTypeface> fFaces[gFaceCount];

public:
    FontScalerTestView()
    {
        for (int i = 0; i < gFaceCount; i++) {
            fFaces[i] = SkTypeface::MakeFromName(
                gFaces[i].fName, SkFontStyle::FromOldStyle(gFaces[i].fStyle));
        }
        //        this->setBGColor(0xFFDDDDDD);
=======
    SkTypeface* fFaces[gFaceCount];

public:
    FontScalerTestView() {
        for (int i = 0; i < gFaceCount; i++) {
            fFaces[i] = SkTypeface::CreateFromName(gFaces[i].fName,
                                                   gFaces[i].fStyle);
        }
//        this->setBGColor(0xFFDDDDDD);
    }

    virtual ~FontScalerTestView() {
        for (int i = 0; i < gFaceCount; i++) {
            SkSafeUnref(fFaces[i]);
        }
>>>>>>> miniblink49
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
            SampleCode::TitleR(evt, "FontScaler Test");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

<<<<<<< HEAD
    static void rotate_about(SkCanvas* canvas, SkScalar degrees, SkScalar px, SkScalar py)
    {
=======
    static void rotate_about(SkCanvas* canvas, SkScalar degrees, SkScalar px, SkScalar py) {
>>>>>>> miniblink49
        canvas->translate(px, py);
        canvas->rotate(degrees);
        canvas->translate(-px, -py);
    }

<<<<<<< HEAD
    virtual void onDrawContent(SkCanvas* canvas)
    {
=======
    virtual void onDrawContent(SkCanvas* canvas) {
>>>>>>> miniblink49
        SkPaint paint;

        // test handling of obscene cubic values (currently broken)
        if (false) {
            SkPoint pts[4];
            pts[0].set(1.61061274e+09f, 6291456);
            pts[1].set(-7.18397061e+15f,
<<<<<<< HEAD
                -1.53091184e+13f);
            pts[2].set(-1.30077315e+16f,
                -2.77196141e+13f);
            pts[3].set(-1.30077315e+16f,
                -2.77196162e+13f);
=======
                       -1.53091184e+13f);
            pts[2].set(-1.30077315e+16f,
                       -2.77196141e+13f);
            pts[3].set(-1.30077315e+16f,
                       -2.77196162e+13f);
>>>>>>> miniblink49

            SkPath path;
            path.moveTo(pts[0]);
            path.cubicTo(pts[1], pts[2], pts[3]);
            canvas->drawPath(path, paint);
        }

<<<<<<< HEAD
        //        paint.setSubpixelText(true);
        paint.setAntiAlias(true);
        paint.setLCDRenderText(true);
        paint.setTypeface(SkTypeface::MakeFromName("Times Roman", SkFontStyle()));

        //        const char* text = "abcdefghijklmnopqrstuvwxyz";
=======
//        paint.setSubpixelText(true);
        paint.setAntiAlias(true);
        paint.setLCDRenderText(true);
        SkSafeUnref(paint.setTypeface(SkTypeface::CreateFromName("Times Roman", SkTypeface::kNormal)));

//        const char* text = "abcdefghijklmnopqrstuvwxyz";
>>>>>>> miniblink49
        const char* text = "Hamburgefons ooo mmm";
        const size_t textLen = strlen(text);

        for (int j = 0; j < 2; ++j) {
            for (int i = 0; i < 6; ++i) {
                SkScalar x = SkIntToScalar(10);
                SkScalar y = SkIntToScalar(20);

                SkAutoCanvasRestore acr(canvas, true);
                canvas->translate(SkIntToScalar(50 + i * 230),
<<<<<<< HEAD
                    SkIntToScalar(20));
=======
                                  SkIntToScalar(20));
>>>>>>> miniblink49
                rotate_about(canvas, SkIntToScalar(i * 5), x, y * 10);

                {
                    SkPaint p;
                    p.setAntiAlias(true);
                    SkRect r;
<<<<<<< HEAD
                    r.set(x - 3, 15, x - 1, 280);
=======
                    r.set(x-3, 15, x-1, 280);
>>>>>>> miniblink49
                    canvas->drawRect(r, p);
                }

                int index = 0;
                for (int ps = 6; ps <= 22; ps++) {
                    paint.setTextSize(SkIntToScalar(ps));
                    canvas->drawText(text, textLen, x, y, paint);
<<<<<<< HEAD
                    y += paint.getFontMetrics(nullptr);
=======
                    y += paint.getFontMetrics(NULL);
>>>>>>> miniblink49
                    index += 1;
                }
            }
            canvas->translate(0, 400);
            paint.setSubpixelText(true);
        }
    }

private:
    typedef SkView INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new FontScalerTestView; }
static SkViewRegister reg(MyFactory);
