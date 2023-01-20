/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkAAClip.h"
#include "SkCanvas.h"
#include "SkPath.h"
#include "gm.h"
=======

#include "gm.h"
#include "SkCanvas.h"
#include "SkAAClip.h"
>>>>>>> miniblink49

namespace skiagm {

static void paint_rgn(SkCanvas* canvas, const SkAAClip& clip,
<<<<<<< HEAD
    const SkPaint& paint)
{
=======
                      const SkPaint& paint) {
>>>>>>> miniblink49
    SkMask mask;
    SkBitmap bm;

    clip.copyToMask(&mask);

    SkAutoMaskFreeImage amfi(mask.fImage);

    bm.installMaskPixels(mask);

    // need to copy for deferred drawing test to work
    SkBitmap bm2;

    bm.deepCopyTo(&bm2);

    canvas->drawBitmap(bm2,
<<<<<<< HEAD
        SK_Scalar1 * mask.fBounds.fLeft,
        SK_Scalar1 * mask.fBounds.fTop,
        &paint);
=======
                       SK_Scalar1 * mask.fBounds.fLeft,
                       SK_Scalar1 * mask.fBounds.fTop,
                       &paint);
>>>>>>> miniblink49
}

//////////////////////////////////////////////////////////////////////////////
/*
 * This GM tests anti aliased single operation booleans with SkAAClips,
 * SkRect and SkPaths.
 */
class SimpleClipGM : public GM {
public:
    enum SkGeomTypes {
        kRect_GeomType,
        kPath_GeomType,
        kAAClip_GeomType
    };

    SimpleClipGM(SkGeomTypes geomType)
<<<<<<< HEAD
        : fGeomType(geomType)
    {
    }

protected:
    void onOnceBeforeDraw() override
    {
        // offset the rects a bit so we get anti-aliasing in the rect case
        fBase.set(100.65f,
            100.65f,
            150.65f,
            150.65f);
=======
    : fGeomType(geomType) {
    }

protected:
    void onOnceBeforeDraw() override {
        // offset the rects a bit so we get anti-aliasing in the rect case
        fBase.set(100.65f,
                  100.65f,
                  150.65f,
                  150.65f);
>>>>>>> miniblink49
        fRect = fBase;
        fRect.inset(5, 5);
        fRect.offset(25, 25);

        fBasePath.addRoundRect(fBase, SkIntToScalar(5), SkIntToScalar(5));
        fRectPath.addRoundRect(fRect, SkIntToScalar(5), SkIntToScalar(5));
        INHERITED::setBGColor(sk_tool_utils::color_to_565(0xFFDDDDDD));
    }

<<<<<<< HEAD
    void buildRgn(SkAAClip* clip, SkRegion::Op op)
    {
        clip->setPath(fBasePath, nullptr, true);

        SkAAClip clip2;
        clip2.setPath(fRectPath, nullptr, true);
        clip->op(clip2, op);
    }

    void drawOrig(SkCanvas* canvas)
    {
        SkPaint paint;
=======
    void buildRgn(SkAAClip* clip, SkRegion::Op op) {
        clip->setPath(fBasePath, NULL, true);

        SkAAClip clip2;
        clip2.setPath(fRectPath, NULL, true);
        clip->op(clip2, op);
    }

    void drawOrig(SkCanvas* canvas) {
        SkPaint     paint;
>>>>>>> miniblink49

        paint.setStyle(SkPaint::kStroke_Style);
        paint.setColor(SK_ColorBLACK);

        canvas->drawRect(fBase, paint);
        canvas->drawRect(fRect, paint);
    }

<<<<<<< HEAD
    void drawRgnOped(SkCanvas* canvas, SkRegion::Op op, SkColor color)
    {
=======
    void drawRgnOped(SkCanvas* canvas, SkRegion::Op op, SkColor color) {
>>>>>>> miniblink49

        SkAAClip clip;

        this->buildRgn(&clip, op);
        this->drawOrig(canvas);

        SkPaint paint;
        paint.setColor(color);
        paint_rgn(canvas, clip, paint);
    }

<<<<<<< HEAD
    void drawPathsOped(SkCanvas* canvas, SkRegion::Op op, SkColor color)
    {
=======
    void drawPathsOped(SkCanvas* canvas, SkRegion::Op op, SkColor color) {
>>>>>>> miniblink49

        this->drawOrig(canvas);

        canvas->save();

        // create the clip mask with the supplied boolean op
        if (kPath_GeomType == fGeomType) {
            // path-based case
            canvas->clipPath(fBasePath, SkRegion::kReplace_Op, true);
            canvas->clipPath(fRectPath, op, true);
        } else {
            // rect-based case
            canvas->clipRect(fBase, SkRegion::kReplace_Op, true);
            canvas->clipRect(fRect, op, true);
        }

        // draw a rect that will entirely cover the clip mask area
        SkPaint paint;
        paint.setColor(color);

<<<<<<< HEAD
        SkRect r = SkRect::MakeLTRB(SkIntToScalar(90), SkIntToScalar(90),
            SkIntToScalar(180), SkIntToScalar(180));
=======
        SkRect r = SkRect::MakeLTRB(SkIntToScalar(90),  SkIntToScalar(90),
                                    SkIntToScalar(180), SkIntToScalar(180));
>>>>>>> miniblink49

        canvas->drawRect(r, paint);

        canvas->restore();
    }

<<<<<<< HEAD
    SkString onShortName() override
    {
        SkString str;
        str.printf("simpleaaclip_%s",
            kRect_GeomType == fGeomType ? "rect" : (kPath_GeomType == fGeomType ? "path" : "aaclip"));
        return str;
    }

    SkISize onISize() override
    {
        return SkISize::Make(640, 480);
    }

    void onDraw(SkCanvas* canvas) override
    {

        static const struct {
            SkColor fColor;
            const char* fName;
            SkRegion::Op fOp;
        } gOps[] = {
            { SK_ColorBLACK, "Difference", SkRegion::kDifference_Op },
            { SK_ColorRED, "Intersect", SkRegion::kIntersect_Op },
            { sk_tool_utils::color_to_565(0xFF008800), "Union", SkRegion::kUnion_Op },
            { SK_ColorGREEN, "Rev Diff", SkRegion::kReverseDifference_Op },
            { SK_ColorYELLOW, "Replace", SkRegion::kReplace_Op },
            { SK_ColorBLUE, "XOR", SkRegion::kXOR_Op },
=======
    virtual SkString onShortName() {
        SkString str;
        str.printf("simpleaaclip_%s",
                    kRect_GeomType == fGeomType ? "rect" :
                    (kPath_GeomType == fGeomType ? "path" :
                    "aaclip"));
        return str;
    }

    virtual SkISize onISize() {
        return SkISize::Make(640, 480);
    }

    virtual void onDraw(SkCanvas* canvas) {

        static const struct {
            SkColor         fColor;
            const char*     fName;
            SkRegion::Op    fOp;
        } gOps[] = {
            { SK_ColorBLACK,    "Difference", SkRegion::kDifference_Op    },
            { SK_ColorRED,      "Intersect",  SkRegion::kIntersect_Op     },
            { 0xFF008800,       "Union",      SkRegion::kUnion_Op         },
            { SK_ColorGREEN,    "Rev Diff",   SkRegion::kReverseDifference_Op },
            { SK_ColorYELLOW,   "Replace",    SkRegion::kReplace_Op       },
            { SK_ColorBLUE,     "XOR",        SkRegion::kXOR_Op           },
>>>>>>> miniblink49
        };

        SkPaint textPaint;
        textPaint.setAntiAlias(true);
<<<<<<< HEAD
        sk_tool_utils::set_portable_typeface(&textPaint);
        textPaint.setTextSize(SK_Scalar1 * 24);
=======
        sk_tool_utils::set_portable_typeface_always(&textPaint);
        textPaint.setTextSize(SK_Scalar1*24);
>>>>>>> miniblink49
        int xOff = 0;

        for (size_t op = 0; op < SK_ARRAY_COUNT(gOps); op++) {
            canvas->drawText(gOps[op].fName, strlen(gOps[op].fName),
<<<<<<< HEAD
                SkIntToScalar(75), SkIntToScalar(50),
                textPaint);
=======
                             SkIntToScalar(75), SkIntToScalar(50),
                             textPaint);
>>>>>>> miniblink49

            if (kAAClip_GeomType == fGeomType) {
                this->drawRgnOped(canvas, gOps[op].fOp, gOps[op].fColor);
            } else {
                this->drawPathsOped(canvas, gOps[op].fOp, gOps[op].fColor);
            }

            if (xOff >= 400) {
                canvas->translate(SkIntToScalar(-400), SkIntToScalar(250));
                xOff = 0;
            } else {
                canvas->translate(SkIntToScalar(200), 0);
                xOff += 200;
            }
        }
    }
<<<<<<< HEAD

private:
=======
private:

>>>>>>> miniblink49
    SkGeomTypes fGeomType;

    SkRect fBase;
    SkRect fRect;

<<<<<<< HEAD
    SkPath fBasePath; // fBase as a round rect
    SkPath fRectPath; // fRect as a round rect
=======
    SkPath fBasePath;       // fBase as a round rect
    SkPath fRectPath;       // fRect as a round rect
>>>>>>> miniblink49

    typedef GM INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

// rects
<<<<<<< HEAD
DEF_GM(return new SimpleClipGM(SimpleClipGM::kRect_GeomType);)
DEF_GM(return new SimpleClipGM(SimpleClipGM::kPath_GeomType);)
DEF_GM(return new SimpleClipGM(SimpleClipGM::kAAClip_GeomType);)
=======
DEF_GM( return new SimpleClipGM(SimpleClipGM::kRect_GeomType); )
DEF_GM( return new SimpleClipGM(SimpleClipGM::kPath_GeomType); )
DEF_GM( return new SimpleClipGM(SimpleClipGM::kAAClip_GeomType); )
>>>>>>> miniblink49

}
