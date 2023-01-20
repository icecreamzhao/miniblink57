/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkPath.h"
#include "SkRRect.h"
#include "SkRandom.h"
#include "gm.h"
=======
#include "gm.h"
#include "SkRandom.h"
#include "SkRRect.h"
>>>>>>> miniblink49

namespace skiagm {

// Test out various combinations of nested rects, ovals and rrects.
class NestedGM : public GM {
public:
<<<<<<< HEAD
    NestedGM(bool doAA, bool flipped)
        : fDoAA(doAA)
        , fFlipped(flipped)
    {
=======
    NestedGM(bool doAA, bool flipped) : fDoAA(doAA), fFlipped(flipped) {
>>>>>>> miniblink49
        this->setBGColor(sk_tool_utils::color_to_565(0xFFDDDDDD));
    }

protected:
<<<<<<< HEAD
    SkString onShortName() override
    {
=======

    SkString onShortName() override {
>>>>>>> miniblink49
        SkString name("nested");
        if (fFlipped) {
            name.append("_flipY");
        }
        if (fDoAA) {
            name.append("_aa");
        } else {
            name.append("_bw");
        }
        return name;
    }

<<<<<<< HEAD
    SkISize onISize() override
    {
=======
    SkISize onISize() override {
>>>>>>> miniblink49
        return SkISize::Make(kImageWidth, kImageHeight);
    }

    enum Shapes {
        kRect_Shape = 0,
        kRRect_Shape,
        kOval_Shape,
        kShapeCount
    };

<<<<<<< HEAD
    static void AddShape(SkPath* path, const SkRect& rect, Shapes shape, SkPath::Direction dir)
    {
        switch (shape) {
        case kRect_Shape:
            path->addRect(rect, dir);
            break;
        case kRRect_Shape: {
            SkRRect rr;
            rr.setRectXY(rect, 5, 5);
            path->addRRect(rr, dir);
            break;
        }
        case kOval_Shape:
            path->addOval(rect, dir);
            break;
        default:
            break;
        }
    }

    void onDraw(SkCanvas* canvas) override
    {
=======
    static void AddShape(SkPath* path, const SkRect& rect, Shapes shape, SkPath::Direction dir) {
        switch (shape) {
            case kRect_Shape:
                path->addRect(rect, dir);
                break;
            case kRRect_Shape: {
                SkRRect rr;
                rr.setRectXY(rect, 5, 5);
                path->addRRect(rr, dir);
                break;
                }
            case kOval_Shape:
                path->addOval(rect, dir);
                break;
            default:
                break;
        }
    }

    void onDraw(SkCanvas* canvas) override {
>>>>>>> miniblink49

        SkPaint shapePaint;
        shapePaint.setColor(SK_ColorBLACK);
        shapePaint.setAntiAlias(fDoAA);

        SkRect outerRect = SkRect::MakeWH(40, 40);

        SkRect innerRects[] = {
<<<<<<< HEAD
            { 10, 10, 30, 30 }, // small
            { .5f, 18, 4.5f, 22 } // smaller and offset to left
=======
            { 10, 10, 30, 30 },     // small
            { .5f, 18, 4.5f, 22 }   // smaller and offset to left
>>>>>>> miniblink49
        };

        // draw a background pattern to make transparency errors more apparent
        SkRandom rand;

        for (int y = 0; y < kImageHeight; y += 10) {
            for (int x = 0; x < kImageWidth; x += 10) {
                SkRect r = SkRect::MakeXYWH(SkIntToScalar(x),
<<<<<<< HEAD
                    SkIntToScalar(y),
                    10, 10);
=======
                                            SkIntToScalar(y),
                                            10, 10);
>>>>>>> miniblink49
                SkPaint p;
                p.setColor(rand.nextU() | 0xFF000000);
                canvas->drawRect(r, p);
            }
        }

        SkScalar xOff = 2, yOff = 2;
        for (int outerShape = 0; outerShape < kShapeCount; ++outerShape) {
            for (int innerShape = 0; innerShape < kShapeCount; ++innerShape) {
                for (size_t innerRect = 0; innerRect < SK_ARRAY_COUNT(innerRects); ++innerRect) {
                    SkPath path;

<<<<<<< HEAD
                    AddShape(&path, outerRect, (Shapes)outerShape, SkPath::kCW_Direction);
                    AddShape(&path, innerRects[innerRect], (Shapes)innerShape,
                        SkPath::kCCW_Direction);
=======
                    AddShape(&path, outerRect, (Shapes) outerShape, SkPath::kCW_Direction);
                    AddShape(&path, innerRects[innerRect], (Shapes) innerShape,
                             SkPath::kCCW_Direction);
>>>>>>> miniblink49

                    canvas->save();
                    if (fFlipped) {
                        canvas->scale(1.0f, -1.0f);
                        canvas->translate(xOff, -yOff - 40.0f);
                    } else {
                        canvas->translate(xOff, yOff);
                    }

                    canvas->drawPath(path, shapePaint);
                    canvas->restore();

                    xOff += 45;
                }
            }

            xOff = 2;
            yOff += 45;
        }
<<<<<<< HEAD
=======

>>>>>>> miniblink49
    }

private:
    static const int kImageWidth = 269;
    static const int kImageHeight = 134;

    bool fDoAA;
    bool fFlipped;

    typedef GM INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
DEF_GM(return new NestedGM(/* doAA = */ true, /* flipped = */ false);)
DEF_GM(return new NestedGM(/* doAA = */ false, /* flipped = */ false);)
DEF_GM(return new NestedGM(/* doAA = */ true, /* flipped = */ true);)
DEF_GM(return new NestedGM(/* doAA = */ false, /* flipped = */ true);)
=======
DEF_GM( return new NestedGM(/* doAA = */ true,  /* flipped = */ false); )
DEF_GM( return new NestedGM(/* doAA = */ false, /* flipped = */ false); )
DEF_GM( return new NestedGM(/* doAA = */ true,  /* flipped = */ true); )
DEF_GM( return new NestedGM(/* doAA = */ false, /* flipped = */ true); )
>>>>>>> miniblink49

}
