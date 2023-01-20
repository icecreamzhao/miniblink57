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

#include "SampleCode.h"
=======
#include "SampleCode.h"
#include "SkView.h"
>>>>>>> miniblink49
#include "SkCanvas.h"
#include "SkGradientShader.h"
#include "SkPath.h"
#include "SkRegion.h"
#include "SkShader.h"
#include "SkUtils.h"
<<<<<<< HEAD
#include "SkView.h"

#include <math.h>

static void test_strokerect(SkCanvas* canvas)
{
=======
#include "SkImageDecoder.h"

static void test_strokerect(SkCanvas* canvas) {
>>>>>>> miniblink49
    int width = 100;
    int height = 100;

    SkBitmap bitmap;
<<<<<<< HEAD
    bitmap.allocPixels(SkImageInfo::MakeA8(width * 2, height * 2));
=======
    bitmap.allocPixels(SkImageInfo::MakeA8(width*2, height*2));
>>>>>>> miniblink49
    bitmap.eraseColor(SK_ColorTRANSPARENT);

    SkScalar dx = 20;
    SkScalar dy = 20;

    SkPath path;
    path.addRect(0.0f, 0.0f,
<<<<<<< HEAD
        SkIntToScalar(width), SkIntToScalar(height),
        SkPath::kCW_Direction);
=======
                 SkIntToScalar(width), SkIntToScalar(height),
                 SkPath::kCW_Direction);
>>>>>>> miniblink49
    SkRect r = SkRect::MakeWH(SkIntToScalar(width), SkIntToScalar(height));

    SkCanvas c(bitmap);
    c.translate(dx, dy);

    SkPaint paint;
    paint.setStyle(SkPaint::kStroke_Style);
    paint.setStrokeWidth(1);

    // use the rect
    c.clear(SK_ColorTRANSPARENT);
    c.drawRect(r, paint);
<<<<<<< HEAD
    canvas->drawBitmap(bitmap, 0, 0, nullptr);
=======
    canvas->drawBitmap(bitmap, 0, 0, NULL);
>>>>>>> miniblink49

    // use the path
    c.clear(SK_ColorTRANSPARENT);
    c.drawPath(path, paint);
<<<<<<< HEAD
    canvas->drawBitmap(bitmap, SkIntToScalar(2 * width), 0, nullptr);
}

static void drawFadingText(SkCanvas* canvas,
    const char* text, size_t len, SkScalar x, SkScalar y,
    const SkPaint& paint)
{
=======
    canvas->drawBitmap(bitmap, SkIntToScalar(2*width), 0, NULL);
}

static void drawFadingText(SkCanvas* canvas,
                           const char* text, size_t len, SkScalar x, SkScalar y,
                           const SkPaint& paint) {
>>>>>>> miniblink49
    // Need a bounds for the text
    SkRect bounds;
    SkPaint::FontMetrics fm;

    paint.getFontMetrics(&fm);
    bounds.set(x, y + fm.fTop, x + paint.measureText(text, len), y + fm.fBottom);

    // may need to outset bounds a little, to account for hinting and/or
    // antialiasing
    bounds.inset(-SkIntToScalar(2), -SkIntToScalar(2));

<<<<<<< HEAD
    canvas->saveLayer(&bounds, nullptr);
=======
    canvas->saveLayer(&bounds, NULL);
>>>>>>> miniblink49
    canvas->drawText(text, len, x, y, paint);

    const SkPoint pts[] = {
        { bounds.fLeft, y },
        { bounds.fRight, y }
    };
    const SkColor colors[] = { SK_ColorBLACK, SK_ColorBLACK, 0 };

    // pos[1] value is where we start to fade, relative to the width
    // of our pts[] array.
    const SkScalar pos[] = { 0, 0.9f, SK_Scalar1 };

<<<<<<< HEAD
    SkPaint p;
    p.setShader(SkGradientShader::MakeLinear(pts, colors, pos, 3, SkShader::kClamp_TileMode));
=======
    SkShader* s = SkGradientShader::CreateLinear(pts, colors, pos, 3,
                                                 SkShader::kClamp_TileMode);
    SkPaint p;
    p.setShader(s)->unref();
>>>>>>> miniblink49
    p.setXfermodeMode(SkXfermode::kDstIn_Mode);
    canvas->drawRect(bounds, p);

    canvas->restore();
}

<<<<<<< HEAD
static void test_text(SkCanvas* canvas)
{
=======
static void test_text(SkCanvas* canvas) {
>>>>>>> miniblink49
    SkPaint paint;
    paint.setAntiAlias(true);
    paint.setTextSize(20);

    const char* str = "Hamburgefons";
    size_t len = strlen(str);
    SkScalar x = 20;
    SkScalar y = 20;

    canvas->drawText(str, len, x, y, paint);

    y += 20;

    const SkPoint pts[] = { { x, y }, { x + paint.measureText(str, len), y } };
    const SkColor colors[] = { SK_ColorBLACK, SK_ColorBLACK, 0 };
    const SkScalar pos[] = { 0, 0.9f, 1 };
<<<<<<< HEAD
    paint.setShader(SkGradientShader::MakeLinear(pts, colors, pos,
        SK_ARRAY_COUNT(colors),
        SkShader::kClamp_TileMode));
    canvas->drawText(str, len, x, y, paint);

    y += 20;
    paint.setShader(nullptr);
    drawFadingText(canvas, str, len, x, y, paint);
}

#ifdef SK_DEBUG
static void make_rgn(SkRegion* rgn, int left, int top, int right, int bottom,
    int count, int32_t runs[])
{
=======
    SkShader* s = SkGradientShader::CreateLinear(pts, colors, pos,
                                                 SK_ARRAY_COUNT(colors),
                                                 SkShader::kClamp_TileMode);
    paint.setShader(s)->unref();
    canvas->drawText(str, len, x, y, paint);

    y += 20;
    paint.setShader(NULL);
    drawFadingText(canvas, str, len, x, y, paint);
}

#ifdef SK_BUILD_FOR_WIN
// windows doesn't have roundf
inline float roundf(float x) { return (x-floor(x))>0.5 ? ceil(x) : floor(x); }
#endif

#ifdef SK_DEBUG
static void make_rgn(SkRegion* rgn, int left, int top, int right, int bottom,
                     int count, int32_t runs[]) {
>>>>>>> miniblink49
    SkIRect r;
    r.set(left, top, right, bottom);

    rgn->debugSetRuns(runs, count);
    SkASSERT(rgn->getBounds() == r);
}

<<<<<<< HEAD
static void test_union_bug_1505668(SkRegion* ra, SkRegion* rb, SkRegion* rc)
{
=======
static void test_union_bug_1505668(SkRegion* ra, SkRegion* rb, SkRegion* rc) {
>>>>>>> miniblink49
    static int32_t dataA[] = {
        0x00000001,
        0x000001dd, 2, 0x00000001, 0x0000000c, 0x0000000d, 0x00000025, 0x7fffffff,
        0x000001de, 1, 0x00000001, 0x00000025, 0x7fffffff,
        0x000004b3, 1, 0x00000001, 0x00000026, 0x7fffffff,
        0x000004b4, 1, 0x0000000c, 0x00000026, 0x7fffffff,
        0x00000579, 1, 0x00000000, 0x0000013a, 0x7fffffff,
        0x000005d8, 1, 0x00000000, 0x0000013b, 0x7fffffff,
        0x7fffffff
    };
    make_rgn(ra, 0, 1, 315, 1496, SK_ARRAY_COUNT(dataA), dataA);

    static int32_t dataB[] = {
        0x000000b6,
        0x000000c4, 1, 0x000000a1, 0x000000f0, 0x7fffffff,
        0x000000d6, 0, 0x7fffffff,
        0x000000e4, 2, 0x00000070, 0x00000079, 0x000000a1, 0x000000b0, 0x7fffffff,
        0x000000e6, 0, 0x7fffffff,
        0x000000f4, 2, 0x00000070, 0x00000079, 0x000000a1, 0x000000b0, 0x7fffffff,
        0x000000f6, 0, 0x7fffffff,
        0x00000104, 1, 0x000000a1, 0x000000b0, 0x7fffffff,
        0x7fffffff
    };
    make_rgn(rb, 112, 182, 240, 260, SK_ARRAY_COUNT(dataB), dataB);

    rc->op(*ra, *rb, SkRegion::kUnion_Op);
}
#endif

<<<<<<< HEAD
static void scale_rect(SkIRect* dst, const SkIRect& src, float scale)
{
=======
static void scale_rect(SkIRect* dst, const SkIRect& src, float scale) {
>>>>>>> miniblink49
    dst->fLeft = (int)::roundf(src.fLeft * scale);
    dst->fTop = (int)::roundf(src.fTop * scale);
    dst->fRight = (int)::roundf(src.fRight * scale);
    dst->fBottom = (int)::roundf(src.fBottom * scale);
}

<<<<<<< HEAD
static void scale_rgn(SkRegion* dst, const SkRegion& src, float scale)
{
=======
static void scale_rgn(SkRegion* dst, const SkRegion& src, float scale) {
>>>>>>> miniblink49
    SkRegion tmp;
    SkRegion::Iterator iter(src);

    for (; !iter.done(); iter.next()) {
        SkIRect r;
        scale_rect(&r, iter.rect(), scale);
        tmp.op(r, SkRegion::kUnion_Op);
    }
    dst->swap(tmp);
}

static void paint_rgn(SkCanvas* canvas, const SkRegion& rgn,
<<<<<<< HEAD
    const SkPaint& paint)
{
    SkRegion scaled;
    scale_rgn(&scaled, rgn, 0.5f);

    SkRegion::Iterator iter(rgn);

    for (; !iter.done(); iter.next()) {
        SkRect r;
=======
                      const SkPaint& paint) {
    SkRegion scaled;
    scale_rgn(&scaled, rgn, 0.5f);

    SkRegion::Iterator  iter(rgn);

    for (; !iter.done(); iter.next())
    {
        SkRect    r;
>>>>>>> miniblink49
        r.set(iter.rect());
        canvas->drawRect(r, paint);
    }
}

class RegionView : public SampleView {
public:
<<<<<<< HEAD
    RegionView()
    {
=======
    RegionView() {
>>>>>>> miniblink49
        fBase.set(100, 100, 150, 150);
        fRect = fBase;
        fRect.inset(5, 5);
        fRect.offset(25, 25);
        this->setBGColor(0xFFDDDDDD);
    }

<<<<<<< HEAD
    void build_base_rgn(SkRegion* rgn)
    {
=======
    void build_base_rgn(SkRegion* rgn) {
>>>>>>> miniblink49
        rgn->setRect(fBase);
        SkIRect r = fBase;
        r.offset(75, 20);
        rgn->op(r, SkRegion::kUnion_Op);
    }

<<<<<<< HEAD
    void build_rgn(SkRegion* rgn, SkRegion::Op op)
    {
=======
    void build_rgn(SkRegion* rgn, SkRegion::Op op) {
>>>>>>> miniblink49
        build_base_rgn(rgn);
        rgn->op(fRect, op);
    }

<<<<<<< HEAD
protected:
    // overrides from SkEventSink
    bool onQuery(SkEvent* evt) override
    {
=======

protected:
    // overrides from SkEventSink
    bool onQuery(SkEvent* evt) override {
>>>>>>> miniblink49
        if (SampleCode::TitleQ(*evt)) {
            SampleCode::TitleR(evt, "Regions");
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

    static void drawstr(SkCanvas* canvas, const char text[], const SkPoint& loc,
<<<<<<< HEAD
        bool hilite)
    {
=======
                        bool hilite) {
>>>>>>> miniblink49
        SkPaint paint;
        paint.setAntiAlias(true);
        paint.setTextSize(SkIntToScalar(20));
        paint.setColor(hilite ? SK_ColorRED : 0x40FF0000);
        canvas->drawText(text, strlen(text), loc.fX, loc.fY, paint);
    }

<<<<<<< HEAD
    void drawPredicates(SkCanvas* canvas, const SkPoint pts[])
    {
=======
    void drawPredicates(SkCanvas* canvas, const SkPoint pts[]) {
>>>>>>> miniblink49
        SkRegion rgn;
        build_base_rgn(&rgn);

        drawstr(canvas, "Intersects", pts[0], rgn.intersects(fRect));
        drawstr(canvas, "Contains", pts[1], rgn.contains(fRect));
    }

<<<<<<< HEAD
    void drawOrig(SkCanvas* canvas, bool bg)
    {
        SkRect r;
        SkPaint paint;
=======
    void drawOrig(SkCanvas* canvas, bool bg) {
        SkRect      r;
        SkPaint     paint;
>>>>>>> miniblink49

        paint.setStyle(SkPaint::kStroke_Style);
        if (bg)
            paint.setColor(0xFFBBBBBB);

        SkRegion rgn;
        build_base_rgn(&rgn);
        paint_rgn(canvas, rgn, paint);

        r.set(fRect);
        canvas->drawRect(r, paint);
    }

<<<<<<< HEAD
    void drawRgnOped(SkCanvas* canvas, SkRegion::Op op, SkColor color)
    {
        SkRegion rgn;
=======
    void drawRgnOped(SkCanvas* canvas, SkRegion::Op op, SkColor color) {
        SkRegion    rgn;
>>>>>>> miniblink49

        this->build_rgn(&rgn, op);

        {
            SkRegion tmp, tmp2(rgn);

            tmp = tmp2;
            tmp.translate(5, -3);

            {
<<<<<<< HEAD
                char buffer[1000];
                SkDEBUGCODE(size_t size =) tmp.writeToMemory(nullptr);
                SkASSERT(size <= sizeof(buffer));
                SkDEBUGCODE(size_t size2 =) tmp.writeToMemory(buffer);
                SkASSERT(size == size2);

                SkRegion tmp3;
                SkDEBUGCODE(size2 =) tmp3.readFromMemory(buffer, 1000);
=======
                char    buffer[1000];
                SkDEBUGCODE(size_t  size = ) tmp.writeToMemory(NULL);
                SkASSERT(size <= sizeof(buffer));
                SkDEBUGCODE(size_t  size2 = ) tmp.writeToMemory(buffer);
                SkASSERT(size == size2);

                SkRegion    tmp3;
                SkDEBUGCODE(size2 = ) tmp3.readFromMemory(buffer, 1000);
>>>>>>> miniblink49
                SkASSERT(size == size2);

                SkASSERT(tmp3 == tmp);
            }

            rgn.translate(20, 30, &tmp);
            SkASSERT(rgn.isEmpty() || tmp != rgn);
            tmp.translate(-20, -30);
            SkASSERT(tmp == rgn);
        }

        this->drawOrig(canvas, true);

        SkPaint paint;
        paint.setColor((color & ~(0xFF << 24)) | (0x44 << 24));
        paint_rgn(canvas, rgn, paint);

        paint.setStyle(SkPaint::kStroke_Style);
        paint.setColor(color);
        paint_rgn(canvas, rgn, paint);
    }

<<<<<<< HEAD
    void drawPathOped(SkCanvas* canvas, SkRegion::Op op, SkColor color)
    {
        SkRegion rgn;
        SkPath path;
=======
    void drawPathOped(SkCanvas* canvas, SkRegion::Op op, SkColor color) {
        SkRegion    rgn;
        SkPath      path;
>>>>>>> miniblink49

        this->build_rgn(&rgn, op);
        rgn.getBoundaryPath(&path);

        this->drawOrig(canvas, true);

        SkPaint paint;

        paint.setStyle(SkPaint::kFill_Style);
        paint.setColor((color & ~(0xFF << 24)) | (0x44 << 24));
        canvas->drawPath(path, paint);
        paint.setColor(color);
        paint.setStyle(SkPaint::kStroke_Style);
        canvas->drawPath(path, paint);
    }

<<<<<<< HEAD
    void onDrawContent(SkCanvas* canvas) override
    {
=======
    void onDrawContent(SkCanvas* canvas) override {
>>>>>>> miniblink49
        if (false) { // avoid bit rot, suppress warning
            test_strokerect(canvas);
            return;
        }
        if (false) { // avoid bit rot, suppress warning
            test_text(canvas);
            return;
        }
#ifdef SK_DEBUG
        if (true) {
            SkRegion a, b, c;
            test_union_bug_1505668(&a, &b, &c);

<<<<<<< HEAD
            if (false) { // draw the result of the test
=======
            if (false) {    // draw the result of the test
>>>>>>> miniblink49
                SkPaint paint;

                canvas->translate(SkIntToScalar(10), SkIntToScalar(10));
                paint.setColor(SK_ColorRED);
                paint_rgn(canvas, a, paint);
                paint.setColor(0x800000FF);
                paint_rgn(canvas, b, paint);
                paint.setColor(SK_ColorBLACK);
                paint.setStyle(SkPaint::kStroke_Style);
<<<<<<< HEAD
                //   paint_rgn(canvas, c, paint);
=======
             //   paint_rgn(canvas, c, paint);
>>>>>>> miniblink49
                return;
            }
        }
#endif
        const SkPoint origins[] = {
<<<<<<< HEAD
            { 30 * SK_Scalar1, 50 * SK_Scalar1 },
            { 150 * SK_Scalar1, 50 * SK_Scalar1 },
=======
            { 30*SK_Scalar1, 50*SK_Scalar1 },
            { 150*SK_Scalar1, 50*SK_Scalar1 },
>>>>>>> miniblink49
        };
        this->drawPredicates(canvas, origins);

        static const struct {
<<<<<<< HEAD
            SkColor fColor;
            const char* fName;
            SkRegion::Op fOp;
        } gOps[] = {
            { SK_ColorBLACK, "Difference", SkRegion::kDifference_Op },
            { SK_ColorRED, "Intersect", SkRegion::kIntersect_Op },
            { 0xFF008800, "Union", SkRegion::kUnion_Op },
            { SK_ColorBLUE, "XOR", SkRegion::kXOR_Op }
=======
            SkColor         fColor;
            const char*     fName;
            SkRegion::Op    fOp;
        } gOps[] = {
            { SK_ColorBLACK,    "Difference",   SkRegion::kDifference_Op    },
            { SK_ColorRED,      "Intersect",    SkRegion::kIntersect_Op     },
            { 0xFF008800,       "Union",        SkRegion::kUnion_Op         },
            { SK_ColorBLUE,     "XOR",          SkRegion::kXOR_Op           }
>>>>>>> miniblink49
        };

        SkPaint textPaint;
        textPaint.setAntiAlias(true);
<<<<<<< HEAD
        textPaint.setTextSize(SK_Scalar1 * 24);

        this->drawOrig(canvas, false);
        canvas->save();
        canvas->translate(SkIntToScalar(200), 0);
        this->drawRgnOped(canvas, SkRegion::kUnion_Op, SK_ColorBLACK);
=======
        textPaint.setTextSize(SK_Scalar1*24);

        this->drawOrig(canvas, false);
        canvas->save();
            canvas->translate(SkIntToScalar(200), 0);
            this->drawRgnOped(canvas, SkRegion::kUnion_Op, SK_ColorBLACK);
>>>>>>> miniblink49
        canvas->restore();

        canvas->translate(0, SkIntToScalar(200));

        for (size_t op = 0; op < SK_ARRAY_COUNT(gOps); op++) {
            canvas->drawText(gOps[op].fName, strlen(gOps[op].fName), SkIntToScalar(75), SkIntToScalar(50), textPaint);

            this->drawRgnOped(canvas, gOps[op].fOp, gOps[op].fColor);

            canvas->save();
            canvas->translate(0, SkIntToScalar(200));
            this->drawPathOped(canvas, gOps[op].fOp, gOps[op].fColor);
            canvas->restore();

            canvas->translate(SkIntToScalar(200), 0);
        }
    }

    virtual SkView::Click* onFindClickHandler(SkScalar x, SkScalar y,
<<<<<<< HEAD
        unsigned modi) override
    {
        return fRect.contains(SkScalarRoundToInt(x),
                   SkScalarRoundToInt(y))
            ? new Click(this)
            : nullptr;
    }

    bool onClick(Click* click) override
    {
        fRect.offset(click->fICurr.fX - click->fIPrev.fX,
            click->fICurr.fY - click->fIPrev.fY);
        this->inval(nullptr);
=======
                                              unsigned modi) override {
        return fRect.contains(SkScalarRoundToInt(x),
                              SkScalarRoundToInt(y)) ? new Click(this) : NULL;
    }

    bool onClick(Click* click) override {
        fRect.offset(click->fICurr.fX - click->fIPrev.fX,
                     click->fICurr.fY - click->fIPrev.fY);
        this->inval(NULL);
>>>>>>> miniblink49
        return true;
    }

private:
<<<<<<< HEAD
    SkIRect fBase, fRect;
=======
    SkIRect    fBase, fRect;
>>>>>>> miniblink49

    typedef SampleView INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

static SkView* MyFactory() { return new RegionView; }
static SkViewRegister reg(MyFactory);
