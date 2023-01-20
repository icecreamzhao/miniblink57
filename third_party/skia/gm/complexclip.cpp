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
#include "SkCanvas.h"
#include "gm.h"
=======
#include "gm.h"
#include "SkCanvas.h"
>>>>>>> miniblink49
//#include "SkParsePath.h"
#include "SkPath.h"
//#include "SkRandom.h"

namespace skiagm {

static const SkColor gPathColor = SK_ColorBLACK;
static const SkColor gClipAColor = SK_ColorBLUE;
static const SkColor gClipBColor = SK_ColorRED;

class ComplexClipGM : public GM {
public:
    ComplexClipGM(bool aaclip, bool saveLayer, bool invertDraw)
<<<<<<< HEAD
        : fDoAAClip(aaclip)
        , fDoSaveLayer(saveLayer)
        , fInvertDraw(invertDraw)
    {
=======
    : fDoAAClip(aaclip)
    , fDoSaveLayer(saveLayer)
    , fInvertDraw(invertDraw) {
>>>>>>> miniblink49
        this->setBGColor(0xFFDEDFDE);
    }

protected:
<<<<<<< HEAD
    SkString onShortName()
    {
        SkString str;
        str.printf("complexclip_%s%s%s",
            fDoAAClip ? "aa" : "bw",
            fDoSaveLayer ? "_layer" : "",
            fInvertDraw ? "_invert" : "");
=======


    SkString onShortName() {
        SkString str;
        str.printf("complexclip_%s%s%s",
                   fDoAAClip ? "aa" : "bw",
                   fDoSaveLayer ? "_layer" : "",
                   fInvertDraw ? "_invert" : "");
>>>>>>> miniblink49
        return str;
    }

    SkISize onISize() { return SkISize::Make(970, 780); }

<<<<<<< HEAD
    virtual void onDraw(SkCanvas* canvas)
    {
        SkPath path;
        path.moveTo(SkIntToScalar(0), SkIntToScalar(50));
        path.quadTo(SkIntToScalar(0), SkIntToScalar(0), SkIntToScalar(50), SkIntToScalar(0));
        path.lineTo(SkIntToScalar(175), SkIntToScalar(0));
        path.quadTo(SkIntToScalar(200), SkIntToScalar(0), SkIntToScalar(200), SkIntToScalar(25));
        path.lineTo(SkIntToScalar(200), SkIntToScalar(150));
        path.quadTo(SkIntToScalar(200), SkIntToScalar(200), SkIntToScalar(150), SkIntToScalar(200));
        path.lineTo(SkIntToScalar(0), SkIntToScalar(200));
        path.close();
        path.moveTo(SkIntToScalar(50), SkIntToScalar(50));
        path.lineTo(SkIntToScalar(150), SkIntToScalar(50));
        path.lineTo(SkIntToScalar(150), SkIntToScalar(125));
        path.quadTo(SkIntToScalar(150), SkIntToScalar(150), SkIntToScalar(125), SkIntToScalar(150));
        path.lineTo(SkIntToScalar(50), SkIntToScalar(150));
=======
    virtual void onDraw(SkCanvas* canvas) {
        SkPath path;
        path.moveTo(SkIntToScalar(0),   SkIntToScalar(50));
        path.quadTo(SkIntToScalar(0),   SkIntToScalar(0),   SkIntToScalar(50),  SkIntToScalar(0));
        path.lineTo(SkIntToScalar(175), SkIntToScalar(0));
        path.quadTo(SkIntToScalar(200), SkIntToScalar(0),   SkIntToScalar(200), SkIntToScalar(25));
        path.lineTo(SkIntToScalar(200), SkIntToScalar(150));
        path.quadTo(SkIntToScalar(200), SkIntToScalar(200), SkIntToScalar(150), SkIntToScalar(200));
        path.lineTo(SkIntToScalar(0),   SkIntToScalar(200));
        path.close();
        path.moveTo(SkIntToScalar(50),  SkIntToScalar(50));
        path.lineTo(SkIntToScalar(150), SkIntToScalar(50));
        path.lineTo(SkIntToScalar(150), SkIntToScalar(125));
        path.quadTo(SkIntToScalar(150), SkIntToScalar(150), SkIntToScalar(125), SkIntToScalar(150));
        path.lineTo(SkIntToScalar(50),  SkIntToScalar(150));
>>>>>>> miniblink49
        path.close();
        if (fInvertDraw) {
            path.setFillType(SkPath::kInverseEvenOdd_FillType);
        } else {
            path.setFillType(SkPath::kEvenOdd_FillType);
        }
        SkPaint pathPaint;
        pathPaint.setAntiAlias(true);
        pathPaint.setColor(gPathColor);

        SkPath clipA;
<<<<<<< HEAD
        clipA.moveTo(SkIntToScalar(10), SkIntToScalar(20));
        clipA.lineTo(SkIntToScalar(165), SkIntToScalar(22));
        clipA.lineTo(SkIntToScalar(70), SkIntToScalar(105));
        clipA.lineTo(SkIntToScalar(165), SkIntToScalar(177));
        clipA.lineTo(SkIntToScalar(-5), SkIntToScalar(180));
        clipA.close();

        SkPath clipB;
        clipB.moveTo(SkIntToScalar(40), SkIntToScalar(10));
        clipB.lineTo(SkIntToScalar(190), SkIntToScalar(15));
        clipB.lineTo(SkIntToScalar(195), SkIntToScalar(190));
        clipB.lineTo(SkIntToScalar(40), SkIntToScalar(185));
=======
        clipA.moveTo(SkIntToScalar(10),  SkIntToScalar(20));
        clipA.lineTo(SkIntToScalar(165), SkIntToScalar(22));
        clipA.lineTo(SkIntToScalar(70),  SkIntToScalar(105));
        clipA.lineTo(SkIntToScalar(165), SkIntToScalar(177));
        clipA.lineTo(SkIntToScalar(-5),  SkIntToScalar(180));
        clipA.close();

        SkPath clipB;
        clipB.moveTo(SkIntToScalar(40),  SkIntToScalar(10));
        clipB.lineTo(SkIntToScalar(190), SkIntToScalar(15));
        clipB.lineTo(SkIntToScalar(195), SkIntToScalar(190));
        clipB.lineTo(SkIntToScalar(40),  SkIntToScalar(185));
>>>>>>> miniblink49
        clipB.lineTo(SkIntToScalar(155), SkIntToScalar(100));
        clipB.close();

        SkPaint paint;
        paint.setAntiAlias(true);
<<<<<<< HEAD
        sk_tool_utils::set_portable_typeface(&paint);
=======
        sk_tool_utils::set_portable_typeface_always(&paint);
>>>>>>> miniblink49
        paint.setTextSize(SkIntToScalar(20));

        static const struct {
            SkRegion::Op fOp;
<<<<<<< HEAD
            const char* fName;
        } gOps[] = { //extra spaces in names for measureText
            { SkRegion::kIntersect_Op, "Isect " },
            { SkRegion::kDifference_Op, "Diff " },
            { SkRegion::kUnion_Op, "Union " },
            { SkRegion::kXOR_Op, "Xor " },
            { SkRegion::kReverseDifference_Op, "RDiff " }
=======
            const char*  fName;
        } gOps[] = { //extra spaces in names for measureText
            {SkRegion::kIntersect_Op,         "Isect "},
            {SkRegion::kDifference_Op,        "Diff " },
            {SkRegion::kUnion_Op,             "Union "},
            {SkRegion::kXOR_Op,               "Xor "  },
            {SkRegion::kReverseDifference_Op, "RDiff "}
>>>>>>> miniblink49
        };

        canvas->translate(SkIntToScalar(20), SkIntToScalar(20));
        canvas->scale(3 * SK_Scalar1 / 4, 3 * SK_Scalar1 / 4);

        if (fDoSaveLayer) {
            // We want the layer to appear symmetric relative to actual
            // device boundaries so we need to "undo" the effect of the
            // scale and translate
            SkRect bounds = SkRect::MakeLTRB(
<<<<<<< HEAD
                4.0f / 3.0f * -20,
                4.0f / 3.0f * -20,
                4.0f / 3.0f * (this->getISize().fWidth - 20),
                4.0f / 3.0f * (this->getISize().fHeight - 20));
=======
              4.0f/3.0f * -20,
              4.0f/3.0f * -20,
              4.0f/3.0f * (this->getISize().fWidth - 20),
              4.0f/3.0f * (this->getISize().fHeight - 20));
>>>>>>> miniblink49

            bounds.inset(SkIntToScalar(100), SkIntToScalar(100));
            SkPaint boundPaint;
            boundPaint.setColor(SK_ColorRED);
            boundPaint.setStyle(SkPaint::kStroke_Style);
            canvas->drawRect(bounds, boundPaint);
<<<<<<< HEAD
            canvas->saveLayer(&bounds, nullptr);
=======
            canvas->saveLayer(&bounds, NULL);
>>>>>>> miniblink49
        }

        for (int invBits = 0; invBits < 4; ++invBits) {
            canvas->save();
            for (size_t op = 0; op < SK_ARRAY_COUNT(gOps); ++op) {
                this->drawHairlines(canvas, path, clipA, clipB);

                bool doInvA = SkToBool(invBits & 1);
                bool doInvB = SkToBool(invBits & 2);
                canvas->save();
<<<<<<< HEAD
                // set clip
                clipA.setFillType(doInvA ? SkPath::kInverseEvenOdd_FillType : SkPath::kEvenOdd_FillType);
                clipB.setFillType(doInvB ? SkPath::kInverseEvenOdd_FillType : SkPath::kEvenOdd_FillType);
                canvas->clipPath(clipA, SkRegion::kIntersect_Op, fDoAAClip);
                canvas->clipPath(clipB, gOps[op].fOp, fDoAAClip);

                // In the inverse case we need to prevent the draw from covering the whole
                // canvas.
                if (fInvertDraw) {
                    SkRect rectClip = clipA.getBounds();
                    rectClip.join(path.getBounds());
                    rectClip.join(path.getBounds());
                    rectClip.outset(5, 5);
                    canvas->clipRect(rectClip);
                }

                // draw path clipped
                canvas->drawPath(path, pathPaint);
                canvas->restore();

=======
                    // set clip
                    clipA.setFillType(doInvA ? SkPath::kInverseEvenOdd_FillType :
                                      SkPath::kEvenOdd_FillType);
                    clipB.setFillType(doInvB ? SkPath::kInverseEvenOdd_FillType :
                                      SkPath::kEvenOdd_FillType);
                    canvas->clipPath(clipA, SkRegion::kIntersect_Op, fDoAAClip);
                    canvas->clipPath(clipB, gOps[op].fOp, fDoAAClip);

                    // In the inverse case we need to prevent the draw from covering the whole
                    // canvas.
                    if (fInvertDraw) {
                        SkRect rectClip = clipA.getBounds();
                        rectClip.join(path.getBounds());
                        rectClip.join(path.getBounds());
                        rectClip.outset(5, 5);
                        canvas->clipRect(rectClip);
                    }

                    // draw path clipped
                    canvas->drawPath(path, pathPaint);
                canvas->restore();


>>>>>>> miniblink49
                SkScalar txtX = SkIntToScalar(45);
                paint.setColor(gClipAColor);
                const char* aTxt = doInvA ? "InvA " : "A ";
                canvas->drawText(aTxt, strlen(aTxt), txtX, SkIntToScalar(220), paint);
                txtX += paint.measureText(aTxt, strlen(aTxt));
                paint.setColor(SK_ColorBLACK);
                canvas->drawText(gOps[op].fName, strlen(gOps[op].fName),
<<<<<<< HEAD
                    txtX, SkIntToScalar(220), paint);
=======
                                    txtX, SkIntToScalar(220), paint);
>>>>>>> miniblink49
                txtX += paint.measureText(gOps[op].fName, strlen(gOps[op].fName));
                paint.setColor(gClipBColor);
                const char* bTxt = doInvB ? "InvB " : "B ";
                canvas->drawText(bTxt, strlen(bTxt), txtX, SkIntToScalar(220), paint);

<<<<<<< HEAD
                canvas->translate(SkIntToScalar(250), 0);
=======
                canvas->translate(SkIntToScalar(250),0);
>>>>>>> miniblink49
            }
            canvas->restore();
            canvas->translate(0, SkIntToScalar(250));
        }

        if (fDoSaveLayer) {
            canvas->restore();
        }
    }
<<<<<<< HEAD

private:
    void drawHairlines(SkCanvas* canvas, const SkPath& path,
        const SkPath& clipA, const SkPath& clipB)
    {
=======
private:
    void drawHairlines(SkCanvas* canvas, const SkPath& path,
                       const SkPath& clipA, const SkPath& clipB) {
>>>>>>> miniblink49
        SkPaint paint;
        paint.setAntiAlias(true);
        paint.setStyle(SkPaint::kStroke_Style);
        const SkAlpha fade = 0x33;

        // draw path in hairline
<<<<<<< HEAD
        paint.setColor(gPathColor);
        paint.setAlpha(fade);
        canvas->drawPath(path, paint);

        // draw clips in hair line
        paint.setColor(gClipAColor);
        paint.setAlpha(fade);
        canvas->drawPath(clipA, paint);
        paint.setColor(gClipBColor);
        paint.setAlpha(fade);
=======
        paint.setColor(gPathColor); paint.setAlpha(fade);
        canvas->drawPath(path, paint);

        // draw clips in hair line
        paint.setColor(gClipAColor); paint.setAlpha(fade);
        canvas->drawPath(clipA, paint);
        paint.setColor(gClipBColor); paint.setAlpha(fade);
>>>>>>> miniblink49
        canvas->drawPath(clipB, paint);
    }

    bool fDoAAClip;
    bool fDoSaveLayer;
    bool fInvertDraw;

    typedef GM INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
DEF_GM(return new ComplexClipGM(false, false, false);)
DEF_GM(return new ComplexClipGM(false, false, true);)
DEF_GM(return new ComplexClipGM(false, true, false);)
DEF_GM(return new ComplexClipGM(false, true, true);)
DEF_GM(return new ComplexClipGM(true, false, false);)
DEF_GM(return new ComplexClipGM(true, false, true);)
DEF_GM(return new ComplexClipGM(true, true, false);)
DEF_GM(return new ComplexClipGM(true, true, true);)
=======
DEF_GM( return SkNEW_ARGS(ComplexClipGM, (false, false, false)); )
DEF_GM( return SkNEW_ARGS(ComplexClipGM, (false, false, true));  )
DEF_GM( return SkNEW_ARGS(ComplexClipGM, (false, true,  false)); )
DEF_GM( return SkNEW_ARGS(ComplexClipGM, (false, true,  true));  )
DEF_GM( return SkNEW_ARGS(ComplexClipGM, (true,  false, false)); )
DEF_GM( return SkNEW_ARGS(ComplexClipGM, (true,  false, true));  )
DEF_GM( return SkNEW_ARGS(ComplexClipGM, (true,  true,  false)); )
DEF_GM( return SkNEW_ARGS(ComplexClipGM, (true,  true,  true));  )

>>>>>>> miniblink49
}
