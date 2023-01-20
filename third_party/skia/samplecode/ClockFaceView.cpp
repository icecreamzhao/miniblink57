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
#include "SkPath.h"
#include "SkReadBuffer.h"
#include "SkRegion.h"
#include "SkShader.h"
#include "SkStrokeRec.h"
#include "SkTypeface.h"
#include "SkUtils.h"
#include "SkView.h"
#include "SkWriteBuffer.h"

static inline SkPMColor rgb2gray(SkPMColor c)
{
=======
#include "SkView.h"
#include "SkCanvas.h"
#include "SkReadBuffer.h"
#include "SkWriteBuffer.h"
#include "SkGradientShader.h"
#include "SkPath.h"
#include "SkRegion.h"
#include "SkShader.h"
#include "SkUtils.h"
#include "SkColorPriv.h"
#include "SkColorFilter.h"
#include "SkTypeface.h"

static inline SkPMColor rgb2gray(SkPMColor c) {
>>>>>>> miniblink49
    unsigned r = SkGetPackedR32(c);
    unsigned g = SkGetPackedG32(c);
    unsigned b = SkGetPackedB32(c);

    unsigned x = (r * 5 + g * 7 + b * 4) >> 4;

    return SkPackARGB32(0, x, x, x) | (c & (SK_A32_MASK << SK_A32_SHIFT));
}

class SkGrayScaleColorFilter : public SkColorFilter {
public:
    virtual void filterSpan(const SkPMColor src[], int count,
<<<<<<< HEAD
        SkPMColor result[]) const override
    {
=======
                            SkPMColor result[]) const override {
>>>>>>> miniblink49
        for (int i = 0; i < count; i++) {
            result[i] = rgb2gray(src[i]);
        }
    }
};

class SkChannelMaskColorFilter : public SkColorFilter {
public:
<<<<<<< HEAD
    SkChannelMaskColorFilter(U8CPU redMask, U8CPU greenMask, U8CPU blueMask)
    {
=======
    SkChannelMaskColorFilter(U8CPU redMask, U8CPU greenMask, U8CPU blueMask) {
>>>>>>> miniblink49
        fMask = SkPackARGB32(0xFF, redMask, greenMask, blueMask);
    }

    virtual void filterSpan(const SkPMColor src[], int count,
<<<<<<< HEAD
        SkPMColor result[]) const override
    {
=======
                            SkPMColor result[]) const override {
>>>>>>> miniblink49
        SkPMColor mask = fMask;
        for (int i = 0; i < count; i++) {
            result[i] = src[i] & mask;
        }
    }

private:
<<<<<<< HEAD
    SkPMColor fMask;
=======
    SkPMColor   fMask;
>>>>>>> miniblink49
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
#include "SkBlurMaskFilter.h"
#include "SkGradientShader.h"
#include "SkLayerRasterizer.h"
=======
#include "SkGradientShader.h"
#include "SkLayerRasterizer.h"
#include "SkBlurMaskFilter.h"
>>>>>>> miniblink49

#include "Sk2DPathEffect.h"

class Dot2DPathEffect : public Sk2DPathEffect {
public:
    Dot2DPathEffect(SkScalar radius, const SkMatrix& matrix,
<<<<<<< HEAD
        SkTDArray<SkPoint>* pts)
        : Sk2DPathEffect(matrix)
        , fRadius(radius)
        , fPts(pts)
    {
    }

    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(Dot2DPathEffect)
    class Registrar {
    public:
        Registrar()
        {
            SkFlattenable::Register("Dot2DPathEffect",
                Dot2DPathEffect::CreateProc,
                Dot2DPathEffect::GetFlattenableType());
        }
    };

protected:
    void begin(const SkIRect& uvBounds, SkPath* dst) const override
    {
=======
                    SkTDArray<SkPoint>* pts)
    : Sk2DPathEffect(matrix), fRadius(radius), fPts(pts) {}

    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(Dot2DPathEffect)

protected:
    void begin(const SkIRect& uvBounds, SkPath* dst) const override {
>>>>>>> miniblink49
        if (fPts) {
            fPts->reset();
        }
        this->INHERITED::begin(uvBounds, dst);
    }

    virtual void next(const SkPoint& loc, int u, int v,
<<<<<<< HEAD
        SkPath* dst) const override
    {
=======
                      SkPath* dst) const override {
>>>>>>> miniblink49
        if (fPts) {
            *fPts->append() = loc;
        }
        dst->addCircle(loc.fX, loc.fY, fRadius);
    }

<<<<<<< HEAD
    void flatten(SkWriteBuffer& buffer) const override
    {
=======
    void flatten(SkWriteBuffer& buffer) const override {
>>>>>>> miniblink49
        buffer.writeMatrix(this->getMatrix());
        buffer.writeScalar(fRadius);
    }

private:
    SkScalar fRadius;
    SkTDArray<SkPoint>* fPts;

    typedef Sk2DPathEffect INHERITED;
};

<<<<<<< HEAD
static Dot2DPathEffect::Registrar gReg0;

sk_sp<SkFlattenable> Dot2DPathEffect::CreateProc(SkReadBuffer& buffer)
{
    SkMatrix matrix;
    buffer.readMatrix(&matrix);
    return sk_make_sp<Dot2DPathEffect>(buffer.readScalar(), matrix, nullptr);
=======
SkFlattenable* Dot2DPathEffect::CreateProc(SkReadBuffer& buffer) {
    SkMatrix matrix;
    buffer.readMatrix(&matrix);
    return SkNEW_ARGS(Dot2DPathEffect, (buffer.readScalar(), matrix, NULL));
>>>>>>> miniblink49
}

class InverseFillPE : public SkPathEffect {
public:
<<<<<<< HEAD
    InverseFillPE() { }
    virtual bool filterPath(SkPath* dst, const SkPath& src,
        SkStrokeRec*, const SkRect*) const override
    {
=======
    InverseFillPE() {}
    virtual bool filterPath(SkPath* dst, const SkPath& src,
                            SkStrokeRec*, const SkRect*) const override {
>>>>>>> miniblink49
        *dst = src;
        dst->setFillType(SkPath::kInverseWinding_FillType);
        return true;
    }

#ifndef SK_IGNORE_TO_STRING
<<<<<<< HEAD
    void toString(SkString* str) const override
    {
=======
    void toString(SkString* str) const override {
>>>>>>> miniblink49
        str->appendf("InverseFillPE: ()");
    }
#endif

    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(InverseFillPE)

private:
    typedef SkPathEffect INHERITED;
};

<<<<<<< HEAD
sk_sp<SkFlattenable> InverseFillPE::CreateProc(SkReadBuffer& buffer)
{
    return sk_make_sp<InverseFillPE>();
}

static sk_sp<SkPathEffect> makepe(float interp, SkTDArray<SkPoint>* pts)
{
    SkMatrix lattice;
    SkScalar rad = 3 + SkIntToScalar(4) * (1 - interp);
    lattice.setScale(rad * 2, rad * 2, 0, 0);
    lattice.postSkew(SK_Scalar1 / 3, 0, 0, 0);
    return sk_make_sp<Dot2DPathEffect>(rad, lattice, pts);
}

static void r7(SkLayerRasterizer::Builder* rastBuilder, SkPaint& p, SkScalar interp)
{
    p.setPathEffect(makepe(SkScalarToFloat(interp), nullptr));
=======
SkFlattenable* InverseFillPE::CreateProc(SkReadBuffer& buffer) {
    return SkNEW(InverseFillPE);
}

static SkPathEffect* makepe(float interp, SkTDArray<SkPoint>* pts) {
    SkMatrix    lattice;
    SkScalar    rad = 3 + SkIntToScalar(4) * (1 - interp);
    lattice.setScale(rad*2, rad*2, 0, 0);
    lattice.postSkew(SK_Scalar1/3, 0, 0, 0);
    return new Dot2DPathEffect(rad, lattice, pts);
}

static void r7(SkLayerRasterizer::Builder* rastBuilder, SkPaint& p, SkScalar interp) {
    p.setPathEffect(makepe(SkScalarToFloat(interp), NULL))->unref();
>>>>>>> miniblink49
    rastBuilder->addLayer(p);
#if 0
    p.setPathEffect(new InverseFillPE())->unref();
    p.setXfermodeMode(SkXfermode::kSrcIn_Mode);
    p.setXfermodeMode(SkXfermode::kClear_Mode);
    p.setAlpha((1 - interp) * 255);
    rastBuilder->addLayer(p);
#endif
}

typedef void (*raster_proc)(SkLayerRasterizer*, SkPaint&);

#include "SkXfermode.h"

static void apply_shader(SkPaint* paint, float scale)
{
    SkPaint p;
    SkLayerRasterizer::Builder rastBuilder;

    p.setAntiAlias(true);
    r7(&rastBuilder, p, scale);
<<<<<<< HEAD
    paint->setRasterizer(rastBuilder.detach());
=======
    paint->setRasterizer(rastBuilder.detachRasterizer())->unref();
>>>>>>> miniblink49

    paint->setColor(SK_ColorBLUE);
}

class ClockFaceView : public SkView {
<<<<<<< HEAD
    sk_sp<SkTypeface> fFace;
=======
    SkTypeface* fFace;
>>>>>>> miniblink49
    SkScalar fInterp;
    SkScalar fDx;

public:
<<<<<<< HEAD
    ClockFaceView()
    {
        fFace = SkTypeface::MakeFromFile("/Users/reed/Downloads/p052024l.pfb");
        fInterp = 0;
        fDx = SK_Scalar1 / 64;
=======
    ClockFaceView() {
        fFace = SkTypeface::CreateFromFile("/Users/reed/Downloads/p052024l.pfb");
        fInterp = 0;
        fDx = SK_Scalar1/64;
    }

    virtual ~ClockFaceView() {
        SkSafeUnref(fFace);
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
            SampleCode::TitleR(evt, "Text Effects");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

<<<<<<< HEAD
    void drawBG(SkCanvas* canvas)
    {
        //        canvas->drawColor(0xFFDDDDDD);
        canvas->drawColor(SK_ColorWHITE);
    }

    static void drawdots(SkCanvas* canvas, const SkPaint& orig)
    {
        SkTDArray<SkPoint> pts;
        auto pe = makepe(0, &pts);
=======
    void drawBG(SkCanvas* canvas) {
//        canvas->drawColor(0xFFDDDDDD);
        canvas->drawColor(SK_ColorWHITE);
    }

    static void drawdots(SkCanvas* canvas, const SkPaint& orig) {
        SkTDArray<SkPoint> pts;
        SkPathEffect* pe = makepe(0, &pts);
>>>>>>> miniblink49

        SkStrokeRec rec(SkStrokeRec::kFill_InitStyle);
        SkPath path, dstPath;
        orig.getTextPath("9", 1, 0, 0, &path);
<<<<<<< HEAD
        pe->filterPath(&dstPath, path, &rec, nullptr);
=======
        pe->filterPath(&dstPath, path, &rec, NULL);
>>>>>>> miniblink49

        SkPaint p;
        p.setAntiAlias(true);
        p.setStrokeWidth(10);
        p.setColor(SK_ColorRED);
<<<<<<< HEAD
        canvas->drawPoints(SkCanvas::kPoints_PointMode, pts.count(), pts.begin(), p);
    }

    virtual void onDraw(SkCanvas* canvas)
    {
        this->drawBG(canvas);

        SkScalar x = SkIntToScalar(20);
        SkScalar y = SkIntToScalar(300);
        SkPaint paint;

        paint.setAntiAlias(true);
        paint.setTextSize(SkIntToScalar(240));
        paint.setTypeface(SkTypeface::MakeFromName("sans-serif",
            SkFontStyle::FromOldStyle(SkTypeface::kBold)));
=======
        canvas->drawPoints(SkCanvas::kPoints_PointMode, pts.count(), pts.begin(),
                           p);
    }

    virtual void onDraw(SkCanvas* canvas) {
        this->drawBG(canvas);

        SkScalar    x = SkIntToScalar(20);
        SkScalar    y = SkIntToScalar(300);
        SkPaint     paint;

        paint.setAntiAlias(true);
        paint.setTextSize(SkIntToScalar(240));
        paint.setTypeface(SkTypeface::CreateFromName("sans-serif",
                                                     SkTypeface::kBold));
>>>>>>> miniblink49

        SkString str("9");

        paint.setTypeface(fFace);

        apply_shader(&paint, SkScalarToFloat(fInterp));
        canvas->drawText(str.c_str(), str.size(), x, y, paint);

<<<<<<< HEAD
        //    drawdots(canvas, paint);
=======
    //    drawdots(canvas, paint);
>>>>>>> miniblink49

        if (false) {
            fInterp += fDx;
            if (fInterp > 1) {
                fInterp = 1;
                fDx = -fDx;
            } else if (fInterp < 0) {
                fInterp = 0;
                fDx = -fDx;
            }
<<<<<<< HEAD
            this->inval(nullptr);
=======
            this->inval(NULL);
>>>>>>> miniblink49
        }
    }

private:
    typedef SkView INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new ClockFaceView; }
static SkViewRegister reg(MyFactory);
