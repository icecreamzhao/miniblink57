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
#include "SkRandom.h"
#include "SkTArray.h"
#include "gm.h"
=======
#include "gm.h"
#include "SkRandom.h"
#include "SkTArray.h"
>>>>>>> miniblink49

class SkDoOnce : SkNoncopyable {
public:
    SkDoOnce() { fDidOnce = false; }

    bool needToDo() const { return !fDidOnce; }
    bool alreadyDone() const { return fDidOnce; }
<<<<<<< HEAD
    void accomplished()
    {
=======
    void accomplished() {
>>>>>>> miniblink49
        SkASSERT(!fDidOnce);
        fDidOnce = true;
    }

private:
    bool fDidOnce;
};

namespace skiagm {

class ConvexPathsGM : public GM {
    SkDoOnce fOnce;
<<<<<<< HEAD

public:
    ConvexPathsGM()
    {
=======
public:
    ConvexPathsGM() {
>>>>>>> miniblink49
        this->setBGColor(0xFF000000);
    }

protected:
<<<<<<< HEAD
    virtual SkString onShortName()
    {
        return SkString("convexpaths");
    }

    virtual SkISize onISize()
    {
        return SkISize::Make(1200, 1100);
    }

    void makePaths()
    {
=======

    virtual SkString onShortName() {
        return SkString("convexpaths");
    }


    virtual SkISize onISize() {
        return SkISize::Make(1200, 1100);
    }

    void makePaths() {
>>>>>>> miniblink49
        if (fOnce.alreadyDone()) {
            return;
        }
        fOnce.accomplished();

        fPaths.push_back().moveTo(0, 0);
        fPaths.back().quadTo(50 * SK_Scalar1, 100 * SK_Scalar1,
<<<<<<< HEAD
            0, 100 * SK_Scalar1);
=======
                             0, 100 * SK_Scalar1);
>>>>>>> miniblink49
        fPaths.back().lineTo(0, 0);

        fPaths.push_back().moveTo(0, 50 * SK_Scalar1);
        fPaths.back().quadTo(50 * SK_Scalar1, 0,
<<<<<<< HEAD
            100 * SK_Scalar1, 50 * SK_Scalar1);
        fPaths.back().quadTo(50 * SK_Scalar1, 100 * SK_Scalar1,
            0, 50 * SK_Scalar1);

        fPaths.push_back().addRect(0, 0,
            100 * SK_Scalar1, 100 * SK_Scalar1,
            SkPath::kCW_Direction);

        fPaths.push_back().addRect(0, 0,
            100 * SK_Scalar1, 100 * SK_Scalar1,
            SkPath::kCCW_Direction);

        fPaths.push_back().addCircle(50 * SK_Scalar1, 50 * SK_Scalar1,
            50 * SK_Scalar1, SkPath::kCW_Direction);

        fPaths.push_back().addOval(SkRect::MakeXYWH(0, 0,
                                       50 * SK_Scalar1,
                                       100 * SK_Scalar1),
            SkPath::kCW_Direction);

        fPaths.push_back().addOval(SkRect::MakeXYWH(0, 0,
                                       100 * SK_Scalar1,
                                       5 * SK_Scalar1),
            SkPath::kCCW_Direction);

        fPaths.push_back().addOval(SkRect::MakeXYWH(0, 0,
                                       SK_Scalar1,
                                       100 * SK_Scalar1),
            SkPath::kCCW_Direction);

        fPaths.push_back().addRoundRect(SkRect::MakeXYWH(0, 0,
                                            SK_Scalar1 * 100,
                                            SK_Scalar1 * 100),
            40 * SK_Scalar1, 20 * SK_Scalar1,
            SkPath::kCW_Direction);
=======
                             100 * SK_Scalar1, 50 * SK_Scalar1);
        fPaths.back().quadTo(50 * SK_Scalar1, 100 * SK_Scalar1,
                             0, 50 * SK_Scalar1);

        fPaths.push_back().addRect(0, 0,
                                   100 * SK_Scalar1, 100 * SK_Scalar1,
                                   SkPath::kCW_Direction);

        fPaths.push_back().addRect(0, 0,
                                   100 * SK_Scalar1, 100 * SK_Scalar1,
                                   SkPath::kCCW_Direction);

        fPaths.push_back().addCircle(50  * SK_Scalar1, 50  * SK_Scalar1,
                                     50  * SK_Scalar1, SkPath::kCW_Direction);


        fPaths.push_back().addOval(SkRect::MakeXYWH(0, 0,
                                                    50 * SK_Scalar1,
                                                    100 * SK_Scalar1),
                                   SkPath::kCW_Direction);

        fPaths.push_back().addOval(SkRect::MakeXYWH(0, 0,
                                                    100 * SK_Scalar1,
                                                    5 * SK_Scalar1),
                                   SkPath::kCCW_Direction);

        fPaths.push_back().addOval(SkRect::MakeXYWH(0, 0,
                                                    SK_Scalar1,
                                                    100 * SK_Scalar1),
                                                    SkPath::kCCW_Direction);

        fPaths.push_back().addRoundRect(SkRect::MakeXYWH(0, 0,
                                                         SK_Scalar1 * 100,
                                                         SK_Scalar1 * 100),
                                        40 * SK_Scalar1, 20 * SK_Scalar1,
                                        SkPath::kCW_Direction);
>>>>>>> miniblink49

        // large number of points
        enum {
            kLength = 100,
            kPtsPerSide = (1 << 12),
        };
        fPaths.push_back().moveTo(0, 0);
        for (int i = 1; i < kPtsPerSide; ++i) { // skip the first point due to moveTo.
            fPaths.back().lineTo(kLength * SkIntToScalar(i) / kPtsPerSide, 0);
        }
        for (int i = 0; i < kPtsPerSide; ++i) {
            fPaths.back().lineTo(kLength, kLength * SkIntToScalar(i) / kPtsPerSide);
        }
        for (int i = kPtsPerSide; i > 0; --i) {
            fPaths.back().lineTo(kLength * SkIntToScalar(i) / kPtsPerSide, kLength);
        }
        for (int i = kPtsPerSide; i > 0; --i) {
            fPaths.back().lineTo(0, kLength * SkIntToScalar(i) / kPtsPerSide);
        }

        // shallow diagonals
        fPaths.push_back().lineTo(100 * SK_Scalar1, SK_Scalar1);
        fPaths.back().lineTo(98 * SK_Scalar1, 100 * SK_Scalar1);
        fPaths.back().lineTo(3 * SK_Scalar1, 96 * SK_Scalar1);

        fPaths.push_back().arcTo(SkRect::MakeXYWH(0, 0,
<<<<<<< HEAD
                                     50 * SK_Scalar1,
                                     100 * SK_Scalar1),
            25 * SK_Scalar1, 130 * SK_Scalar1, false);

        // cubics
        fPaths.push_back().cubicTo(1 * SK_Scalar1, 1 * SK_Scalar1,
            10 * SK_Scalar1, 90 * SK_Scalar1,
            0 * SK_Scalar1, 100 * SK_Scalar1);
        fPaths.push_back().cubicTo(100 * SK_Scalar1, 50 * SK_Scalar1,
            20 * SK_Scalar1, 100 * SK_Scalar1,
            0 * SK_Scalar1, 0 * SK_Scalar1);
=======
                                                  50 * SK_Scalar1,
                                                  100 * SK_Scalar1),
                                                  25 * SK_Scalar1,  130 * SK_Scalar1, false);

        // cubics
        fPaths.push_back().cubicTo( 1 * SK_Scalar1,  1 * SK_Scalar1,
                                   10 * SK_Scalar1,  90 * SK_Scalar1,
                                    0 * SK_Scalar1, 100 * SK_Scalar1);
        fPaths.push_back().cubicTo(100 * SK_Scalar1,  50 * SK_Scalar1,
                                    20 * SK_Scalar1, 100 * SK_Scalar1,
                                     0 * SK_Scalar1,   0 * SK_Scalar1);
>>>>>>> miniblink49

        // path that has a cubic with a repeated first control point and
        // a repeated last control point.
        fPaths.push_back().moveTo(SK_Scalar1 * 10, SK_Scalar1 * 10);
        fPaths.back().cubicTo(10 * SK_Scalar1, 10 * SK_Scalar1,
<<<<<<< HEAD
            10 * SK_Scalar1, 0,
            20 * SK_Scalar1, 0);
        fPaths.back().lineTo(40 * SK_Scalar1, 0);
        fPaths.back().cubicTo(40 * SK_Scalar1, 0,
            50 * SK_Scalar1, 0,
            50 * SK_Scalar1, 10 * SK_Scalar1);
=======
                              10 * SK_Scalar1, 0,
                              20 * SK_Scalar1, 0);
        fPaths.back().lineTo(40 * SK_Scalar1, 0);
        fPaths.back().cubicTo(40 * SK_Scalar1, 0,
                              50 * SK_Scalar1, 0,
                              50 * SK_Scalar1, 10 * SK_Scalar1);
>>>>>>> miniblink49

        // path that has two cubics with repeated middle control points.
        fPaths.push_back().moveTo(SK_Scalar1 * 10, SK_Scalar1 * 10);
        fPaths.back().cubicTo(10 * SK_Scalar1, 0,
<<<<<<< HEAD
            10 * SK_Scalar1, 0,
            20 * SK_Scalar1, 0);
        fPaths.back().lineTo(40 * SK_Scalar1, 0);
        fPaths.back().cubicTo(50 * SK_Scalar1, 0,
            50 * SK_Scalar1, 0,
            50 * SK_Scalar1, 10 * SK_Scalar1);
=======
                              10 * SK_Scalar1, 0,
                              20 * SK_Scalar1, 0);
        fPaths.back().lineTo(40 * SK_Scalar1, 0);
        fPaths.back().cubicTo(50 * SK_Scalar1, 0,
                              50 * SK_Scalar1, 0,
                              50 * SK_Scalar1, 10 * SK_Scalar1);
>>>>>>> miniblink49

        // cubic where last three points are almost a line
        fPaths.push_back().moveTo(0, 228 * SK_Scalar1 / 8);
        fPaths.back().cubicTo(628 * SK_Scalar1 / 8, 82 * SK_Scalar1 / 8,
<<<<<<< HEAD
            1255 * SK_Scalar1 / 8, 141 * SK_Scalar1 / 8,
            1883 * SK_Scalar1 / 8, 202 * SK_Scalar1 / 8);
=======
                              1255 * SK_Scalar1 / 8, 141 * SK_Scalar1 / 8,
                              1883 * SK_Scalar1 / 8, 202 * SK_Scalar1 / 8);
>>>>>>> miniblink49

        // flat cubic where the at end point tangents both point outward.
        fPaths.push_back().moveTo(10 * SK_Scalar1, 0);
        fPaths.back().cubicTo(0, SK_Scalar1,
<<<<<<< HEAD
            30 * SK_Scalar1, SK_Scalar1,
            20 * SK_Scalar1, 0);
=======
                              30 * SK_Scalar1, SK_Scalar1,
                              20 * SK_Scalar1, 0);
>>>>>>> miniblink49

        // flat cubic where initial tangent is in, end tangent out
        fPaths.push_back().moveTo(0, 0 * SK_Scalar1);
        fPaths.back().cubicTo(10 * SK_Scalar1, SK_Scalar1,
<<<<<<< HEAD
            30 * SK_Scalar1, SK_Scalar1,
            20 * SK_Scalar1, 0);
=======
                              30 * SK_Scalar1, SK_Scalar1,
                              20 * SK_Scalar1, 0);
>>>>>>> miniblink49

        // flat cubic where initial tangent is out, end tangent in
        fPaths.push_back().moveTo(10 * SK_Scalar1, 0);
        fPaths.back().cubicTo(0, SK_Scalar1,
<<<<<<< HEAD
            20 * SK_Scalar1, SK_Scalar1,
            30 * SK_Scalar1, 0);

        // triangle where one edge is a degenerate quad
        fPaths.push_back().moveTo(8.59375f, 45 * SK_Scalar1);
        fPaths.back().quadTo(16.9921875f, 45 * SK_Scalar1,
            31.25f, 45 * SK_Scalar1);
        fPaths.back().lineTo(100 * SK_Scalar1, 100 * SK_Scalar1);
        fPaths.back().lineTo(8.59375f, 45 * SK_Scalar1);
=======
                              20 * SK_Scalar1, SK_Scalar1,
                              30 * SK_Scalar1, 0);

        // triangle where one edge is a degenerate quad
        fPaths.push_back().moveTo(8.59375f, 45 * SK_Scalar1);
        fPaths.back().quadTo(16.9921875f,   45 * SK_Scalar1,
                             31.25f,        45 * SK_Scalar1);
        fPaths.back().lineTo(100 * SK_Scalar1,              100 * SK_Scalar1);
        fPaths.back().lineTo(8.59375f,      45 * SK_Scalar1);
>>>>>>> miniblink49

        // triangle where one edge is a quad with a repeated point
        fPaths.push_back().moveTo(0, 25 * SK_Scalar1);
        fPaths.back().lineTo(50 * SK_Scalar1, 0);
        fPaths.back().quadTo(50 * SK_Scalar1, 50 * SK_Scalar1, 50 * SK_Scalar1, 50 * SK_Scalar1);

        // triangle where one edge is a cubic with a 2x repeated point
        fPaths.push_back().moveTo(0, 25 * SK_Scalar1);
        fPaths.back().lineTo(50 * SK_Scalar1, 0);
        fPaths.back().cubicTo(50 * SK_Scalar1, 0,
<<<<<<< HEAD
            50 * SK_Scalar1, 50 * SK_Scalar1,
            50 * SK_Scalar1, 50 * SK_Scalar1);
=======
                              50 * SK_Scalar1, 50 * SK_Scalar1,
                              50 * SK_Scalar1, 50 * SK_Scalar1);
>>>>>>> miniblink49

        // triangle where one edge is a quad with a nearly repeated point
        fPaths.push_back().moveTo(0, 25 * SK_Scalar1);
        fPaths.back().lineTo(50 * SK_Scalar1, 0);
        fPaths.back().quadTo(50 * SK_Scalar1, 49.95f,
<<<<<<< HEAD
            50 * SK_Scalar1, 50 * SK_Scalar1);
=======
                             50 * SK_Scalar1, 50 * SK_Scalar1);
>>>>>>> miniblink49

        // triangle where one edge is a cubic with a 3x nearly repeated point
        fPaths.push_back().moveTo(0, 25 * SK_Scalar1);
        fPaths.back().lineTo(50 * SK_Scalar1, 0);
        fPaths.back().cubicTo(50 * SK_Scalar1, 49.95f,
<<<<<<< HEAD
            50 * SK_Scalar1, 49.97f,
            50 * SK_Scalar1, 50 * SK_Scalar1);
=======
                              50 * SK_Scalar1, 49.97f,
                              50 * SK_Scalar1, 50 * SK_Scalar1);
>>>>>>> miniblink49

        // triangle where there is a point degenerate cubic at one corner
        fPaths.push_back().moveTo(0, 25 * SK_Scalar1);
        fPaths.back().lineTo(50 * SK_Scalar1, 0);
        fPaths.back().lineTo(50 * SK_Scalar1, 50 * SK_Scalar1);
        fPaths.back().cubicTo(50 * SK_Scalar1, 50 * SK_Scalar1,
<<<<<<< HEAD
            50 * SK_Scalar1, 50 * SK_Scalar1,
            50 * SK_Scalar1, 50 * SK_Scalar1);
=======
                              50 * SK_Scalar1, 50 * SK_Scalar1,
                              50 * SK_Scalar1, 50 * SK_Scalar1);
>>>>>>> miniblink49

        // point line
        fPaths.push_back().moveTo(50 * SK_Scalar1, 50 * SK_Scalar1);
        fPaths.back().lineTo(50 * SK_Scalar1, 50 * SK_Scalar1);

        // point quad
        fPaths.push_back().moveTo(50 * SK_Scalar1, 50 * SK_Scalar1);
        fPaths.back().quadTo(50 * SK_Scalar1, 50 * SK_Scalar1,
<<<<<<< HEAD
            50 * SK_Scalar1, 50 * SK_Scalar1);
=======
                             50 * SK_Scalar1, 50 * SK_Scalar1);
>>>>>>> miniblink49

        // point cubic
        fPaths.push_back().moveTo(50 * SK_Scalar1, 50 * SK_Scalar1);
        fPaths.back().cubicTo(50 * SK_Scalar1, 50 * SK_Scalar1,
<<<<<<< HEAD
            50 * SK_Scalar1, 50 * SK_Scalar1,
            50 * SK_Scalar1, 50 * SK_Scalar1);
=======
                              50 * SK_Scalar1, 50 * SK_Scalar1,
                              50 * SK_Scalar1, 50 * SK_Scalar1);
>>>>>>> miniblink49

        // moveTo only paths
        fPaths.push_back().moveTo(0, 0);
        fPaths.back().moveTo(0, 0);
        fPaths.back().moveTo(SK_Scalar1, SK_Scalar1);
        fPaths.back().moveTo(SK_Scalar1, SK_Scalar1);
        fPaths.back().moveTo(10 * SK_Scalar1, 10 * SK_Scalar1);

        fPaths.push_back().moveTo(0, 0);
        fPaths.back().moveTo(0, 0);

        // line degenerate
        fPaths.push_back().lineTo(100 * SK_Scalar1, 100 * SK_Scalar1);
        fPaths.push_back().quadTo(100 * SK_Scalar1, 100 * SK_Scalar1, 0, 0);
        fPaths.push_back().quadTo(100 * SK_Scalar1, 100 * SK_Scalar1,
<<<<<<< HEAD
            50 * SK_Scalar1, 50 * SK_Scalar1);
        fPaths.push_back().quadTo(50 * SK_Scalar1, 50 * SK_Scalar1,
            100 * SK_Scalar1, 100 * SK_Scalar1);
        fPaths.push_back().cubicTo(0, 0,
            0, 0,
            100 * SK_Scalar1, 100 * SK_Scalar1);
=======
                                  50 * SK_Scalar1, 50 * SK_Scalar1);
        fPaths.push_back().quadTo(50 * SK_Scalar1, 50 * SK_Scalar1,
                                  100 * SK_Scalar1, 100 * SK_Scalar1);
        fPaths.push_back().cubicTo(0, 0,
                                   0, 0,
                                   100 * SK_Scalar1, 100 * SK_Scalar1);
>>>>>>> miniblink49

        // small circle. This is listed last so that it has device coords far
        // from the origin (small area relative to x,y values).
        fPaths.push_back().addCircle(0, 0, 1.2f);
    }

<<<<<<< HEAD
    virtual void onDraw(SkCanvas* canvas)
    {
        this->makePaths();

        SkPaint paint;
        paint.setAntiAlias(true);
        SkRandom rand;
        canvas->translate(20 * SK_Scalar1, 20 * SK_Scalar1);

        // As we've added more paths this has gotten pretty big. Scale the whole thing down.
        canvas->scale(2 * SK_Scalar1 / 3, 2 * SK_Scalar1 / 3);

        for (int i = 0; i < fPaths.count(); ++i) {
            canvas->save();
            // position the path, and make it at off-integer coords.
            canvas->translate(SK_Scalar1 * 200 * (i % 5) + SK_Scalar1 / 10,
                SK_Scalar1 * 200 * (i / 5) + 9 * SK_Scalar1 / 10);
            SkColor color = rand.nextU();
            color |= 0xff000000;
            paint.setColor(color);
#if 0 // This hitting on 32bit Linux builds for some paths. Temporarily disabling while it is \
    // debugged.
        SkASSERT(fPaths[i].isConvex());
#endif
            canvas->drawPath(fPaths[i], paint);
            canvas->restore();
        }
=======
    virtual void onDraw(SkCanvas* canvas) {
        this->makePaths();

    SkPaint paint;
    paint.setAntiAlias(true);
    SkRandom rand;
    canvas->translate(20 * SK_Scalar1, 20 * SK_Scalar1);

    // As we've added more paths this has gotten pretty big. Scale the whole thing down.
    canvas->scale(2 * SK_Scalar1 / 3, 2 * SK_Scalar1 / 3);

    for (int i = 0; i < fPaths.count(); ++i) {
        canvas->save();
        // position the path, and make it at off-integer coords.
        canvas->translate(SK_Scalar1 * 200 * (i % 5) + SK_Scalar1 / 10,
                          SK_Scalar1 * 200 * (i / 5) + 9 * SK_Scalar1 / 10);
        SkColor color = rand.nextU();
        color |= 0xff000000;
        paint.setColor(color);
#if 0 // This hitting on 32bit Linux builds for some paths. Temporarily disabling while it is
      // debugged.
        SkASSERT(fPaths[i].isConvex());
#endif
        canvas->drawPath(fPaths[i], paint);
        canvas->restore();
    }
>>>>>>> miniblink49
    }

private:
    typedef GM INHERITED;
    SkTArray<SkPath> fPaths;
};

//////////////////////////////////////////////////////////////////////////////

static GM* MyFactory(void*) { return new ConvexPathsGM; }
static GMRegistry reg(MyFactory);

}
