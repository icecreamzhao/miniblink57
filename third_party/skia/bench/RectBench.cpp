<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#include "Benchmark.h"
#include "SkCanvas.h"
#include "SkCommandLineFlags.h"
#include "SkPaint.h"
#include "SkRandom.h"
#include "SkShader.h"
#include "SkString.h"

DEFINE_double(strokeWidth, -1.0, "If set, use this stroke width in RectBench.");

class RectBench : public Benchmark {
public:
    int fShift, fStroke;
    enum {
        W = 640,
        H = 480,
        N = 300,
    };
<<<<<<< HEAD
    SkRect fRects[N];
=======
    SkRect  fRects[N];
>>>>>>> miniblink49
    SkColor fColors[N];

    RectBench(int shift, int stroke = 0)
        : fShift(shift)
<<<<<<< HEAD
        , fStroke(stroke)
    {
    }

    SkString fName;
    const char* computeName(const char root[])
    {
=======
        , fStroke(stroke) {}

    SkString fName;
    const char* computeName(const char root[]) {
>>>>>>> miniblink49
        fName.printf("%s_%d", root, fShift);
        if (fStroke > 0) {
            fName.appendf("_stroke_%d", fStroke);
        }
        return fName.c_str();
    }

<<<<<<< HEAD
    bool isVisual() override { return true; }

protected:
    virtual void drawThisRect(SkCanvas* c, const SkRect& r, const SkPaint& p)
    {
        c->drawRect(r, p);
    }

    const char* onGetName() override { return computeName("rects"); }

    void onDelayedSetup() override
    {
        SkRandom rand;
        const SkScalar offset = SK_Scalar1 / 3;
=======
protected:
    virtual void drawThisRect(SkCanvas* c, const SkRect& r, const SkPaint& p) {
        c->drawRect(r, p);
    }

    virtual const char* onGetName() { return computeName("rects"); }

    virtual void onPreDraw() {
        SkRandom rand;
        const SkScalar offset = SK_Scalar1/3;
>>>>>>> miniblink49
        for (int i = 0; i < N; i++) {
            int x = rand.nextU() % W;
            int y = rand.nextU() % H;
            int w = rand.nextU() % W;
            int h = rand.nextU() % H;
            w >>= fShift;
            h >>= fShift;
<<<<<<< HEAD
            x -= w / 2;
            y -= h / 2;
            fRects[i].set(SkIntToScalar(x), SkIntToScalar(y),
                SkIntToScalar(x + w), SkIntToScalar(y + h));
=======
            x -= w/2;
            y -= h/2;
            fRects[i].set(SkIntToScalar(x), SkIntToScalar(y),
                          SkIntToScalar(x+w), SkIntToScalar(y+h));
>>>>>>> miniblink49
            fRects[i].offset(offset, offset);
            fColors[i] = rand.nextU() | 0xFF808080;
        }
    }

<<<<<<< HEAD
    void onDraw(int loops, SkCanvas* canvas) override
    {
=======
    virtual void onDraw(const int loops, SkCanvas* canvas) {
>>>>>>> miniblink49
        SkPaint paint;
        if (fStroke > 0) {
            paint.setStyle(SkPaint::kStroke_Style);
            paint.setStrokeWidth(SkIntToScalar(fStroke));
        }
        for (int i = 0; i < loops; i++) {
            paint.setColor(fColors[i % N]);
            this->setupPaint(&paint);
            this->drawThisRect(canvas, fRects[i % N], paint);
        }
    }
<<<<<<< HEAD

=======
>>>>>>> miniblink49
private:
    typedef Benchmark INHERITED;
};

class SrcModeRectBench : public RectBench {
public:
<<<<<<< HEAD
    SrcModeRectBench()
        : INHERITED(1, 0)
    {
        fMode = SkXfermode::Make(SkXfermode::kSrc_Mode);
    }

protected:
    void setupPaint(SkPaint* paint) override
    {
=======
    SrcModeRectBench() : INHERITED(1, 0) {
        fMode = SkXfermode::Create(SkXfermode::kSrc_Mode);
    }

    virtual ~SrcModeRectBench() {
        SkSafeUnref(fMode);
    }

protected:
    void setupPaint(SkPaint* paint) override {
>>>>>>> miniblink49
        this->INHERITED::setupPaint(paint);
        // srcmode is most interesting when we're not opaque
        paint->setAlpha(0x80);
        paint->setXfermode(fMode);
    }

<<<<<<< HEAD
    const char* onGetName() override
    {
=======
    const char* onGetName() override {
>>>>>>> miniblink49
        fName.set(this->INHERITED::onGetName());
        fName.prepend("srcmode_");
        return fName.c_str();
    }

private:
    SkString fName;
<<<<<<< HEAD
    sk_sp<SkXfermode> fMode;

    typedef RectBench INHERITED;
};

class TransparentRectBench : public RectBench {
public:
    TransparentRectBench()
        : INHERITED(1, 0)
    {
    }

protected:
    void setupPaint(SkPaint* paint) override
    {
        this->INHERITED::setupPaint(paint);
        // draw non opaque rect
        paint->setAlpha(0x80);
    }

    const char* onGetName() override
    {
        fName.set(this->INHERITED::onGetName());
        fName.prepend("transparent_");
        return fName.c_str();
    }

private:
    SkString fName;
=======
    SkXfermode* fMode;
>>>>>>> miniblink49

    typedef RectBench INHERITED;
};

class OvalBench : public RectBench {
public:
<<<<<<< HEAD
    OvalBench(int shift, int stroke = 0)
        : RectBench(shift, stroke)
    {
    }

protected:
    void drawThisRect(SkCanvas* c, const SkRect& r, const SkPaint& p) override
    {
        c->drawOval(r, p);
    }
    const char* onGetName() override { return computeName("ovals"); }
=======
    OvalBench(int shift, int stroke = 0) : RectBench(shift, stroke) {}
protected:
    virtual void drawThisRect(SkCanvas* c, const SkRect& r, const SkPaint& p) {
        c->drawOval(r, p);
    }
    virtual const char* onGetName() { return computeName("ovals"); }
>>>>>>> miniblink49
};

class RRectBench : public RectBench {
public:
<<<<<<< HEAD
    RRectBench(int shift, int stroke = 0)
        : RectBench(shift, stroke)
    {
    }

protected:
    void drawThisRect(SkCanvas* c, const SkRect& r, const SkPaint& p) override
    {
        c->drawRoundRect(r, r.width() / 4, r.height() / 4, p);
    }
    const char* onGetName() override { return computeName("rrects"); }
=======
    RRectBench(int shift, int stroke = 0) : RectBench(shift, stroke) {}
protected:
    virtual void drawThisRect(SkCanvas* c, const SkRect& r, const SkPaint& p) {
        c->drawRoundRect(r, r.width() / 4, r.height() / 4, p);
    }
    virtual const char* onGetName() { return computeName("rrects"); }
>>>>>>> miniblink49
};

class PointsBench : public RectBench {
public:
    SkCanvas::PointMode fMode;
    const char* fName;

    PointsBench(SkCanvas::PointMode mode, const char* name)
        : RectBench(2)
<<<<<<< HEAD
        , fMode(mode)
    {
=======
        , fMode(mode) {
>>>>>>> miniblink49
        fName = name;
    }

protected:
<<<<<<< HEAD
    void onDraw(int loops, SkCanvas* canvas) override
    {
=======
    virtual void onDraw(const int loops, SkCanvas* canvas) {
>>>>>>> miniblink49
        SkScalar gSizes[] = {
            SkIntToScalar(7), 0
        };
        size_t sizes = SK_ARRAY_COUNT(gSizes);

        if (FLAGS_strokeWidth >= 0) {
            gSizes[0] = (SkScalar)FLAGS_strokeWidth;
            sizes = 1;
        }

        SkPaint paint;
        paint.setStrokeCap(SkPaint::kRound_Cap);

        for (int loop = 0; loop < loops; loop++) {
            for (size_t i = 0; i < sizes; i++) {
                paint.setStrokeWidth(gSizes[i]);
                this->setupPaint(&paint);
                canvas->drawPoints(fMode, N * 2, SkTCast<SkPoint*>(fRects), paint);
                paint.setColor(fColors[i % N]);
            }
        }
    }
<<<<<<< HEAD
    const char* onGetName() override { return fName; }
=======
    virtual const char* onGetName() { return fName; }
>>>>>>> miniblink49
};

/*******************************************************************************
 * to bench BlitMask [Opaque, Black, color, shader]
 *******************************************************************************/

class BlitMaskBench : public RectBench {
public:
    enum kMaskType {
        kMaskOpaque = 0,
        kMaskBlack,
        kMaskColor,
        KMaskShader
    };
    SkCanvas::PointMode fMode;
    const char* fName;

    BlitMaskBench(SkCanvas::PointMode mode,
<<<<<<< HEAD
        BlitMaskBench::kMaskType type, const char* name)
        : RectBench(2)
        , fMode(mode)
        , _type(type)
    {
=======
                  BlitMaskBench::kMaskType type, const char* name) :
        RectBench(2), fMode(mode), _type(type) {
>>>>>>> miniblink49
        fName = name;
    }

protected:
<<<<<<< HEAD
    void onDraw(int loops, SkCanvas* canvas) override
    {
=======
    virtual void onDraw(const int loops, SkCanvas* canvas) {
>>>>>>> miniblink49
        SkScalar gSizes[] = {
            SkIntToScalar(13), SkIntToScalar(24)
        };
        size_t sizes = SK_ARRAY_COUNT(gSizes);

        if (FLAGS_strokeWidth >= 0) {
            gSizes[0] = (SkScalar)FLAGS_strokeWidth;
            sizes = 1;
        }
        SkRandom rand;
        SkColor color = 0xFF000000;
        U8CPU alpha = 0xFF;
        SkPaint paint;
        paint.setStrokeCap(SkPaint::kRound_Cap);
        if (_type == KMaskShader) {
            SkBitmap srcBM;
            srcBM.allocN32Pixels(10, 1);
            srcBM.eraseColor(0xFF00FF00);

<<<<<<< HEAD
            paint.setShader(SkShader::MakeBitmapShader(srcBM, SkShader::kClamp_TileMode,
                SkShader::kClamp_TileMode));
=======
            SkShader* s;
            s  = SkShader::CreateBitmapShader(srcBM, SkShader::kClamp_TileMode,
                                              SkShader::kClamp_TileMode);
            paint.setShader(s)->unref();
>>>>>>> miniblink49
        }
        for (int loop = 0; loop < loops; loop++) {
            for (size_t i = 0; i < sizes; i++) {
                switch (_type) {
<<<<<<< HEAD
                case kMaskOpaque:
                    color = fColors[i];
                    alpha = 0xFF;
                    break;
                case kMaskBlack:
                    alpha = 0xFF;
                    color = 0xFF000000;
                    break;
                case kMaskColor:
                    color = fColors[i];
                    alpha = rand.nextU() & 255;
                    break;
                case KMaskShader:
                    break;
=======
                    case kMaskOpaque:
                        color = fColors[i];
                        alpha = 0xFF;
                        break;
                    case kMaskBlack:
                        alpha = 0xFF;
                        color = 0xFF000000;
                        break;
                    case kMaskColor:
                        color = fColors[i];
                        alpha = rand.nextU() & 255;
                        break;
                    case KMaskShader:
                        break;
>>>>>>> miniblink49
                }
                paint.setStrokeWidth(gSizes[i]);
                this->setupPaint(&paint);
                paint.setColor(color);
                paint.setAlpha(alpha);
                canvas->drawPoints(fMode, N * 2, SkTCast<SkPoint*>(fRects), paint);
<<<<<<< HEAD
            }
        }
    }
    const char* onGetName() override { return fName; }

=======
           }
        }
    }
    virtual const char* onGetName() { return fName; }
>>>>>>> miniblink49
private:
    typedef RectBench INHERITED;
    kMaskType _type;
};

<<<<<<< HEAD
DEF_BENCH(return new RectBench(1);)
DEF_BENCH(return new RectBench(1, 4);)
DEF_BENCH(return new RectBench(3);)
DEF_BENCH(return new RectBench(3, 4);)
DEF_BENCH(return new OvalBench(1);)
DEF_BENCH(return new OvalBench(3);)
DEF_BENCH(return new OvalBench(1, 4);)
DEF_BENCH(return new OvalBench(3, 4);)
DEF_BENCH(return new RRectBench(1);)
DEF_BENCH(return new RRectBench(1, 4);)
DEF_BENCH(return new RRectBench(3);)
DEF_BENCH(return new RRectBench(3, 4);)
DEF_BENCH(return new PointsBench(SkCanvas::kPoints_PointMode, "points");)
DEF_BENCH(return new PointsBench(SkCanvas::kLines_PointMode, "lines");)
DEF_BENCH(return new PointsBench(SkCanvas::kPolygon_PointMode, "polygon");)

DEF_BENCH(return new SrcModeRectBench();)

DEF_BENCH(return new TransparentRectBench();)

/* init the blitmask bench
 */
DEF_BENCH(return new BlitMaskBench(SkCanvas::kPoints_PointMode,
    BlitMaskBench::kMaskOpaque,
    "maskopaque");)
DEF_BENCH(return new BlitMaskBench(SkCanvas::kPoints_PointMode,
    BlitMaskBench::kMaskBlack,
    "maskblack");)
DEF_BENCH(return new BlitMaskBench(SkCanvas::kPoints_PointMode,
    BlitMaskBench::kMaskColor,
    "maskcolor");)
DEF_BENCH(return new BlitMaskBench(SkCanvas::kPoints_PointMode,
    BlitMaskBench::KMaskShader,
    "maskshader");)
=======

DEF_BENCH( return SkNEW_ARGS(RectBench, (1)); )
DEF_BENCH( return SkNEW_ARGS(RectBench, (1, 4)); )
DEF_BENCH( return SkNEW_ARGS(RectBench, (3)); )
DEF_BENCH( return SkNEW_ARGS(RectBench, (3, 4)); )
DEF_BENCH( return SkNEW_ARGS(OvalBench, (1)); )
DEF_BENCH( return SkNEW_ARGS(OvalBench, (3)); )
DEF_BENCH( return SkNEW_ARGS(OvalBench, (1, 4)); )
DEF_BENCH( return SkNEW_ARGS(OvalBench, (3, 4)); )
DEF_BENCH( return SkNEW_ARGS(RRectBench, (1)); )
DEF_BENCH( return SkNEW_ARGS(RRectBench, (1, 4)); )
DEF_BENCH( return SkNEW_ARGS(RRectBench, (3)); )
DEF_BENCH( return SkNEW_ARGS(RRectBench, (3, 4)); )
DEF_BENCH( return SkNEW_ARGS(PointsBench, (SkCanvas::kPoints_PointMode, "points")); )
DEF_BENCH( return SkNEW_ARGS(PointsBench, (SkCanvas::kLines_PointMode, "lines")); )
DEF_BENCH( return SkNEW_ARGS(PointsBench, (SkCanvas::kPolygon_PointMode, "polygon")); )

DEF_BENCH( return SkNEW_ARGS(SrcModeRectBench, ()); )

/* init the blitmask bench
 */
DEF_BENCH( return SkNEW_ARGS(BlitMaskBench,
                      (SkCanvas::kPoints_PointMode,
                      BlitMaskBench::kMaskOpaque, "maskopaque")
                      ); )
DEF_BENCH( return SkNEW_ARGS(BlitMaskBench,
                      (SkCanvas::kPoints_PointMode,
                      BlitMaskBench::kMaskBlack, "maskblack")
                      ); )
DEF_BENCH( return SkNEW_ARGS(BlitMaskBench,
                      (SkCanvas::kPoints_PointMode,
                      BlitMaskBench::kMaskColor, "maskcolor")
                      ); )
DEF_BENCH( return SkNEW_ARGS(BlitMaskBench,
                     (SkCanvas::kPoints_PointMode,
                     BlitMaskBench::KMaskShader, "maskshader")
                     ); )
>>>>>>> miniblink49
