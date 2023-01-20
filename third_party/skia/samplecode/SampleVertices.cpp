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
#include "SkColorFilter.h"
#include "SkColorPriv.h"
#include "SkGradientShader.h"
#include "SkGraphics.h"
=======
#include "SkView.h"
#include "SkCanvas.h"
#include "SkGradientShader.h"
#include "SkGraphics.h"
#include "SkImageDecoder.h"
>>>>>>> miniblink49
#include "SkPath.h"
#include "SkRandom.h"
#include "SkRegion.h"
#include "SkShader.h"
<<<<<<< HEAD
#include "SkTime.h"
#include "SkTypeface.h"
#include "SkUtils.h"
#include "SkView.h"
#include "SkXfermode.h"
=======
#include "SkUtils.h"
#include "SkXfermode.h"
#include "SkColorPriv.h"
#include "SkColorFilter.h"
#include "SkTime.h"
#include "SkTypeface.h"
>>>>>>> miniblink49

#include "SkOSFile.h"
#include "SkStream.h"

<<<<<<< HEAD
static sk_sp<SkShader> make_shader0(SkIPoint* size)
{
    SkBitmap bm;
=======
static SkShader* make_shader0(SkIPoint* size) {
    SkBitmap    bm;
>>>>>>> miniblink49
    size->set(2, 2);
    SkPMColor color0 = SkPreMultiplyARGB(0x80, 0x80, 0xff, 0x80);
    SkPMColor color1 = SkPreMultiplyARGB(0x40, 0xff, 0x00, 0xff);
    bm.allocN32Pixels(size->fX, size->fY);
    bm.eraseColor(color0);
    bm.lockPixels();
<<<<<<< HEAD
    uint32_t* pixels = (uint32_t*)bm.getPixels();
=======
    uint32_t* pixels = (uint32_t*) bm.getPixels();
>>>>>>> miniblink49
    pixels[0] = pixels[2] = color0;
    pixels[1] = pixels[3] = color1;
    bm.unlockPixels();

<<<<<<< HEAD
    return SkShader::MakeBitmapShader(bm, SkShader::kRepeat_TileMode, SkShader::kRepeat_TileMode);
}

static sk_sp<SkShader> make_shader1(const SkIPoint& size)
{
    SkPoint pts[] = { { 0, 0 },
        { SkIntToScalar(size.fX), SkIntToScalar(size.fY) } };
    SkColor colors[] = { SK_ColorRED, SK_ColorGREEN, SK_ColorBLUE, SK_ColorRED };
    return SkGradientShader::MakeLinear(pts, colors, nullptr,
        SK_ARRAY_COUNT(colors), SkShader::kMirror_TileMode);
}

class VerticesView : public SampleView {
    sk_sp<SkShader> fShader0;
    sk_sp<SkShader> fShader1;

public:
    VerticesView()
    {
        SkIPoint size;
=======
    return SkShader::CreateBitmapShader(bm, SkShader::kRepeat_TileMode,
                                            SkShader::kRepeat_TileMode);
}

static SkShader* make_shader1(const SkIPoint& size) {
    SkPoint pts[] = { { 0, 0 },
                      { SkIntToScalar(size.fX), SkIntToScalar(size.fY) } };
    SkColor colors[] = { SK_ColorRED, SK_ColorGREEN, SK_ColorBLUE, SK_ColorRED };
    return SkGradientShader::CreateLinear(pts, colors, NULL,
                    SK_ARRAY_COUNT(colors), SkShader::kMirror_TileMode);
}

class VerticesView : public SampleView {
    SkShader*   fShader0;
    SkShader*   fShader1;

public:
    VerticesView() {
        SkIPoint    size;
>>>>>>> miniblink49

        fShader0 = make_shader0(&size);
        fShader1 = make_shader1(size);

        make_strip(&fRecs[0], size.fX, size.fY);
        make_fan(&fRecs[1], size.fX, size.fY);
        make_tris(&fRecs[2]);

        fScale = SK_Scalar1;

        this->setBGColor(SK_ColorGRAY);
    }

<<<<<<< HEAD
protected:
    // overrides from SkEventSink
    bool onQuery(SkEvent* evt) override
    {
=======
    virtual ~VerticesView() {
        SkSafeUnref(fShader0);
        SkSafeUnref(fShader1);
    }

protected:
    // overrides from SkEventSink
    bool onQuery(SkEvent* evt) override {
>>>>>>> miniblink49
        if (SampleCode::TitleQ(*evt)) {
            SampleCode::TitleR(evt, "Vertices");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

    SkScalar fScale;

<<<<<<< HEAD
    void onDrawContent(SkCanvas* canvas) override
    {
=======
    void onDrawContent(SkCanvas* canvas) override {
>>>>>>> miniblink49
        SkPaint paint;
        paint.setDither(true);
        paint.setFilterQuality(kLow_SkFilterQuality);

        for (size_t i = 0; i < SK_ARRAY_COUNT(fRecs); i++) {
            canvas->save();

<<<<<<< HEAD
            paint.setShader(nullptr);
            canvas->drawVertices(fRecs[i].fMode, fRecs[i].fCount,
                fRecs[i].fVerts, fRecs[i].fTexs,
                nullptr, nullptr, nullptr, 0, paint);
=======
            paint.setShader(NULL);
            canvas->drawVertices(fRecs[i].fMode, fRecs[i].fCount,
                                 fRecs[i].fVerts, fRecs[i].fTexs,
                                 NULL, NULL, NULL, 0, paint);
>>>>>>> miniblink49

            canvas->translate(SkIntToScalar(250), 0);

            paint.setShader(fShader0);
            canvas->drawVertices(fRecs[i].fMode, fRecs[i].fCount,
<<<<<<< HEAD
                fRecs[i].fVerts, fRecs[i].fTexs,
                nullptr, nullptr, nullptr, 0, paint);
=======
                                 fRecs[i].fVerts, fRecs[i].fTexs,
                                 NULL, NULL, NULL, 0, paint);
>>>>>>> miniblink49

            canvas->translate(SkIntToScalar(250), 0);

            paint.setShader(fShader1);
            canvas->drawVertices(fRecs[i].fMode, fRecs[i].fCount,
<<<<<<< HEAD
                fRecs[i].fVerts, fRecs[i].fTexs,
                nullptr, nullptr, nullptr, 0, paint);
=======
                                 fRecs[i].fVerts, fRecs[i].fTexs,
                                 NULL, NULL, NULL, 0, paint);
>>>>>>> miniblink49
            canvas->restore();

            canvas->translate(0, SkIntToScalar(250));
        }
    }

<<<<<<< HEAD
    SkView::Click* onFindClickHandler(SkScalar x, SkScalar y, unsigned) override
    {
        return new Click(this);
    }

    bool onClick(Click* click) override
    {
        //    fCurrX = click->fICurr.fX;
        //    fCurrY = click->fICurr.fY;
        this->inval(nullptr);
=======
    SkView::Click* onFindClickHandler(SkScalar x, SkScalar y, unsigned) override {
        return new Click(this);
    }

    bool onClick(Click* click) override {
    //    fCurrX = click->fICurr.fX;
    //    fCurrY = click->fICurr.fY;
        this->inval(NULL);
>>>>>>> miniblink49
        return true;
    }

private:
    struct Rec {
<<<<<<< HEAD
        SkCanvas::VertexMode fMode;
        int fCount;
        SkPoint* fVerts;
        SkPoint* fTexs;

        Rec()
            : fCount(0)
            , fVerts(nullptr)
            , fTexs(nullptr)
        {
        }
        ~Rec()
        {
            delete[] fVerts;
            delete[] fTexs;
        }
    };

    void make_tris(Rec* rec)
    {
        int n = 10;
        SkRandom rand;
=======
        SkCanvas::VertexMode    fMode;
        int                     fCount;
        SkPoint*                fVerts;
        SkPoint*                fTexs;

        Rec() : fCount(0), fVerts(NULL), fTexs(NULL) {}
        ~Rec() { delete[] fVerts; delete[] fTexs; }
    };

    void make_tris(Rec* rec) {
        int n = 10;
        SkRandom    rand;
>>>>>>> miniblink49

        rec->fMode = SkCanvas::kTriangles_VertexMode;
        rec->fCount = n * 3;
        rec->fVerts = new SkPoint[rec->fCount];

        for (int i = 0; i < n; i++) {
<<<<<<< HEAD
            SkPoint* v = &rec->fVerts[i * 3];
=======
            SkPoint* v = &rec->fVerts[i*3];
>>>>>>> miniblink49
            for (int j = 0; j < 3; j++) {
                v[j].set(rand.nextUScalar1() * 250, rand.nextUScalar1() * 250);
            }
        }
    }

<<<<<<< HEAD
    void make_fan(Rec* rec, int texWidth, int texHeight)
    {
=======
    void make_fan(Rec* rec, int texWidth, int texHeight) {
>>>>>>> miniblink49
        const SkScalar tx = SkIntToScalar(texWidth);
        const SkScalar ty = SkIntToScalar(texHeight);
        const int n = 24;

        rec->fMode = SkCanvas::kTriangleFan_VertexMode;
        rec->fCount = n + 2;
        rec->fVerts = new SkPoint[rec->fCount];
<<<<<<< HEAD
        rec->fTexs = new SkPoint[rec->fCount];
=======
        rec->fTexs  = new SkPoint[rec->fCount];
>>>>>>> miniblink49

        SkPoint* v = rec->fVerts;
        SkPoint* t = rec->fTexs;

        v[0].set(0, 0);
        t[0].set(0, 0);
        for (int i = 0; i < n; i++) {
            SkScalar cos;
            SkScalar sin = SkScalarSinCos(SK_ScalarPI * 2 * i / n, &cos);
<<<<<<< HEAD
            v[i + 1].set(cos, sin);
            t[i + 1].set(i * tx / n, ty);
        }
        v[n + 1] = v[1];
        t[n + 1].set(tx, ty);
=======
            v[i+1].set(cos, sin);
            t[i+1].set(i*tx/n, ty);
        }
        v[n+1] = v[1];
        t[n+1].set(tx, ty);
>>>>>>> miniblink49

        SkMatrix m;
        m.setScale(SkIntToScalar(100), SkIntToScalar(100));
        m.postTranslate(SkIntToScalar(110), SkIntToScalar(110));
        m.mapPoints(v, rec->fCount);
    }

<<<<<<< HEAD
    void make_strip(Rec* rec, int texWidth, int texHeight)
    {
=======
    void make_strip(Rec* rec, int texWidth, int texHeight) {
>>>>>>> miniblink49
        const SkScalar tx = SkIntToScalar(texWidth);
        const SkScalar ty = SkIntToScalar(texHeight);
        const int n = 24;

        rec->fMode = SkCanvas::kTriangleStrip_VertexMode;
        rec->fCount = 2 * (n + 1);
        rec->fVerts = new SkPoint[rec->fCount];
<<<<<<< HEAD
        rec->fTexs = new SkPoint[rec->fCount];
=======
        rec->fTexs  = new SkPoint[rec->fCount];
>>>>>>> miniblink49

        SkPoint* v = rec->fVerts;
        SkPoint* t = rec->fTexs;

        for (int i = 0; i < n; i++) {
            SkScalar cos;
            SkScalar sin = SkScalarSinCos(SK_ScalarPI * 2 * i / n, &cos);
<<<<<<< HEAD
            v[i * 2 + 0].set(cos / 2, sin / 2);
            v[i * 2 + 1].set(cos, sin);

            t[i * 2 + 0].set(tx * i / n, ty);
            t[i * 2 + 1].set(tx * i / n, 0);
        }
        v[2 * n + 0] = v[0];
        v[2 * n + 1] = v[1];

        t[2 * n + 0].set(tx, ty);
        t[2 * n + 1].set(tx, 0);
=======
            v[i*2 + 0].set(cos/2, sin/2);
            v[i*2 + 1].set(cos, sin);

            t[i*2 + 0].set(tx * i / n, ty);
            t[i*2 + 1].set(tx * i / n, 0);
        }
        v[2*n + 0] = v[0];
        v[2*n + 1] = v[1];

        t[2*n + 0].set(tx, ty);
        t[2*n + 1].set(tx, 0);
>>>>>>> miniblink49

        SkMatrix m;
        m.setScale(SkIntToScalar(100), SkIntToScalar(100));
        m.postTranslate(SkIntToScalar(110), SkIntToScalar(110));
        m.mapPoints(v, rec->fCount);
    }

    Rec fRecs[3];

    typedef SampleView INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new VerticesView; }
static SkViewRegister reg(MyFactory);
