/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

/*  Description:
 *      This test defines a series of elementatry test steps that perform
 *      a single or a small group of canvas API calls. Each test step is
 *      used in several test cases that verify that different types of SkCanvas
 *      flavors and derivatives pass it and yield consistent behavior. The
 *      test cases analyse results that are queryable through the API. They do
 *      not look at rendering results.
 *
 *  Adding test stepss:
 *      The general pattern for creating a new test step is to write a test
 *      function of the form:
 *
 *          static void MyTestStepFunction(SkCanvas* canvas,
<<<<<<< HEAD
 *                                         const TestData& d,
=======
>>>>>>> miniblink49
 *                                         skiatest::Reporter* reporter,
 *                                         CanvasTestStep* testStep)
 *          {
 *              canvas->someCanvasAPImethod();
 *              (...)
 *              REPORTER_ASSERT_MESSAGE(reporter, (...), \
 *                  testStep->assertMessage());
 *          }
 *
 *      The definition of the test step function should be followed by an
 *      invocation of the TEST_STEP macro, which generates a class and
 *      instance for the test step:
 *
 *          TEST_STEP(MyTestStep, MyTestStepFunction)
 *
 *      There are also short hand macros for defining simple test steps
 *      in a single line of code.  A simple test step is a one that is made
 *      of a single canvas API call.
 *
 *          SIMPLE_TEST_STEP(MytestStep, someCanvasAPIMethod());
 *
 *      There is another macro called SIMPLE_TEST_STEP_WITH_ASSERT that
 *      works the same way as SIMPLE_TEST_STEP, and additionally verifies
 *      that the invoked method returns a non-zero value.
 */
#include "SkBitmap.h"
#include "SkCanvas.h"
#include "SkClipStack.h"
<<<<<<< HEAD
=======
#include "SkDeferredCanvas.h"
#include "SkDevice.h"
>>>>>>> miniblink49
#include "SkDocument.h"
#include "SkMatrix.h"
#include "SkNWayCanvas.h"
#include "SkPaint.h"
#include "SkPaintFilterCanvas.h"
#include "SkPath.h"
#include "SkPicture.h"
#include "SkPictureRecord.h"
#include "SkPictureRecorder.h"
<<<<<<< HEAD
#include "SkRasterClip.h"
=======
>>>>>>> miniblink49
#include "SkRect.h"
#include "SkRegion.h"
#include "SkShader.h"
#include "SkStream.h"
#include "SkSurface.h"
#include "SkTDArray.h"
<<<<<<< HEAD
#include "SkTemplates.h"
=======
>>>>>>> miniblink49
#include "Test.h"

static const int kWidth = 2, kHeight = 2;

<<<<<<< HEAD
static void createBitmap(SkBitmap* bm, SkColor color)
{
=======
static void createBitmap(SkBitmap* bm, SkColor color) {
>>>>>>> miniblink49
    bm->allocN32Pixels(kWidth, kHeight);
    bm->eraseColor(color);
}

<<<<<<< HEAD
///////////////////////////////////////////////////////////////////////////////
// Constants used by test steps
const SkPoint kTestPoints[] = {
    { SkIntToScalar(0), SkIntToScalar(0) },
    { SkIntToScalar(2), SkIntToScalar(1) },
    { SkIntToScalar(0), SkIntToScalar(2) }
=======
static SkSurface* createSurface(SkColor color) {
    SkSurface* surface = SkSurface::NewRasterN32Premul(kWidth, kHeight);
    surface->getCanvas()->clear(color);
    return surface;
}

///////////////////////////////////////////////////////////////////////////////
// Constants used by test steps
const SkPoint kTestPoints[] = {
    {SkIntToScalar(0), SkIntToScalar(0)},
    {SkIntToScalar(2), SkIntToScalar(1)},
    {SkIntToScalar(0), SkIntToScalar(2)}
>>>>>>> miniblink49
};
const SkPoint kTestPoints2[] = {
    { SkIntToScalar(0), SkIntToScalar(1) },
    { SkIntToScalar(1), SkIntToScalar(1) },
    { SkIntToScalar(2), SkIntToScalar(1) },
    { SkIntToScalar(3), SkIntToScalar(1) },
    { SkIntToScalar(4), SkIntToScalar(1) },
    { SkIntToScalar(5), SkIntToScalar(1) },
    { SkIntToScalar(6), SkIntToScalar(1) },
    { SkIntToScalar(7), SkIntToScalar(1) },
    { SkIntToScalar(8), SkIntToScalar(1) },
    { SkIntToScalar(9), SkIntToScalar(1) },
    { SkIntToScalar(10), SkIntToScalar(1) }
};

struct TestData {
public:
    TestData()
<<<<<<< HEAD
        : fRect(SkRect::MakeXYWH(SkIntToScalar(0), SkIntToScalar(0),
            SkIntToScalar(2), SkIntToScalar(1)))
        , fMatrix(TestMatrix())
        , fPath(TestPath())
        , fNearlyZeroLengthPath(TestNearlyZeroLengthPath())
        , fIRect(SkIRect::MakeXYWH(0, 0, 2, 1))
        , fRegion(TestRegion())
        , fColor(0x01020304)
        , fPoints(kTestPoints)
        , fPointCount(3)
        , fWidth(2)
        , fHeight(2)
        , fText("Hello World")
        , fPoints2(kTestPoints2)
        , fBitmap(TestBitmap())
    {
    }
=======
    : fRect(SkRect::MakeXYWH(SkIntToScalar(0), SkIntToScalar(0),
                                 SkIntToScalar(2), SkIntToScalar(1)))
    , fMatrix(TestMatrix())
    , fPath(TestPath())
    , fNearlyZeroLengthPath(TestNearlyZeroLengthPath())
    , fIRect(SkIRect::MakeXYWH(0, 0, 2, 1))
    , fRegion(TestRegion())
    , fColor(0x01020304)
    , fPoints(kTestPoints)
    , fPointCount(3)
    , fWidth(2)
    , fHeight(2)
    , fText("Hello World")
    , fPoints2(kTestPoints2)
    , fBitmap(TestBitmap())
    { }
>>>>>>> miniblink49

    SkRect fRect;
    SkMatrix fMatrix;
    SkPath fPath;
    SkPath fNearlyZeroLengthPath;
    SkIRect fIRect;
    SkRegion fRegion;
    SkColor fColor;
    SkPaint fPaint;
    const SkPoint* fPoints;
    size_t fPointCount;
    int fWidth;
    int fHeight;
    SkString fText;
    const SkPoint* fPoints2;
    SkBitmap fBitmap;

private:
<<<<<<< HEAD
    static SkMatrix TestMatrix()
    {
=======
    static SkMatrix TestMatrix() {
>>>>>>> miniblink49
        SkMatrix matrix;
        matrix.reset();
        matrix.setScale(SkIntToScalar(2), SkIntToScalar(3));

        return matrix;
    }
<<<<<<< HEAD
    static SkPath TestPath()
    {
        SkPath path;
        path.addRect(SkRect::MakeXYWH(SkIntToScalar(0), SkIntToScalar(0),
            SkIntToScalar(2), SkIntToScalar(1)));
        return path;
    }
    static SkPath TestNearlyZeroLengthPath()
    {
=======
    static SkPath TestPath() {
        SkPath path;
        path.addRect(SkRect::MakeXYWH(SkIntToScalar(0), SkIntToScalar(0),
                                      SkIntToScalar(2), SkIntToScalar(1)));
        return path;
    }
    static SkPath TestNearlyZeroLengthPath() {
>>>>>>> miniblink49
        SkPath path;
        SkPoint pt1 = { 0, 0 };
        SkPoint pt2 = { 0, SK_ScalarNearlyZero };
        SkPoint pt3 = { SkIntToScalar(1), 0 };
<<<<<<< HEAD
        SkPoint pt4 = { SkIntToScalar(1), SK_ScalarNearlyZero / 2 };
=======
        SkPoint pt4 = { SkIntToScalar(1), SK_ScalarNearlyZero/2 };
>>>>>>> miniblink49
        path.moveTo(pt1);
        path.lineTo(pt2);
        path.lineTo(pt3);
        path.lineTo(pt4);
        return path;
    }
<<<<<<< HEAD
    static SkRegion TestRegion()
    {
=======
    static SkRegion TestRegion() {
>>>>>>> miniblink49
        SkRegion region;
        SkIRect rect = SkIRect::MakeXYWH(0, 0, 2, 1);
        region.setRect(rect);
        return region;
    }
<<<<<<< HEAD
    static SkBitmap TestBitmap()
    {
=======
    static SkBitmap TestBitmap() {
>>>>>>> miniblink49
        SkBitmap bitmap;
        createBitmap(&bitmap, 0x05060708);
        return bitmap;
    }
};

<<<<<<< HEAD
static bool equal_clips(const SkCanvas& a, const SkCanvas& b)
{
=======
static bool equal_clips(const SkCanvas& a, const SkCanvas& b) {
>>>>>>> miniblink49
    if (a.isClipEmpty()) {
        return b.isClipEmpty();
    }
    if (!a.isClipRect()) {
        // this is liberally true, since we don't expose a way to know this exactly (for non-rects)
        return !b.isClipRect();
    }
    SkIRect ar, br;
    a.getClipDeviceBounds(&ar);
    b.getClipDeviceBounds(&br);
    return ar == br;
}

class Canvas2CanvasClipVisitor : public SkCanvas::ClipVisitor {
public:
<<<<<<< HEAD
    Canvas2CanvasClipVisitor(SkCanvas* target)
        : fTarget(target)
    {
    }

    void clipRect(const SkRect& r, SkRegion::Op op, bool aa) override
    {
        fTarget->clipRect(r, op, aa);
    }
    void clipRRect(const SkRRect& r, SkRegion::Op op, bool aa) override
    {
        fTarget->clipRRect(r, op, aa);
    }
    void clipPath(const SkPath& p, SkRegion::Op op, bool aa) override
    {
=======
    Canvas2CanvasClipVisitor(SkCanvas* target) : fTarget(target) {}

    void clipRect(const SkRect& r, SkRegion::Op op, bool aa) override {
        fTarget->clipRect(r, op, aa);
    }
    void clipRRect(const SkRRect& r, SkRegion::Op op, bool aa) override {
        fTarget->clipRRect(r, op, aa);
    }
    void clipPath(const SkPath& p, SkRegion::Op op, bool aa) override {
>>>>>>> miniblink49
        fTarget->clipPath(p, op, aa);
    }

private:
    SkCanvas* fTarget;
};

<<<<<<< HEAD
static void test_clipVisitor(skiatest::Reporter* reporter, SkCanvas* canvas)
{
=======
static void test_clipVisitor(skiatest::Reporter* reporter, SkCanvas* canvas) {
>>>>>>> miniblink49
    SkISize size = canvas->getDeviceSize();

    SkBitmap bm;
    bm.setInfo(SkImageInfo::MakeN32Premul(size.width(), size.height()));
    SkCanvas c(bm);

    Canvas2CanvasClipVisitor visitor(&c);
    canvas->replayClips(&visitor);

    REPORTER_ASSERT(reporter, equal_clips(c, *canvas));
}

<<<<<<< HEAD
static void test_clipstack(skiatest::Reporter* reporter)
{
    // The clipstack is refcounted, and needs to be able to out-live the canvas if a client has
    // ref'd it.
    const SkClipStack* cs = nullptr;
=======
static void test_clipstack(skiatest::Reporter* reporter) {
    // The clipstack is refcounted, and needs to be able to out-live the canvas if a client has
    // ref'd it.
    const SkClipStack* cs = NULL;
>>>>>>> miniblink49
    {
        SkCanvas canvas(10, 10);
        cs = SkRef(canvas.getClipStack());
    }
    REPORTER_ASSERT(reporter, cs->unique());
    cs->unref();
}

// Format strings that describe the test context.  The %s token is where
// the name of the test step is inserted.  The context is required for
// disambiguating the error in the case of failures that are reported in
// functions that are called multiple times in different contexts (test
// cases and test steps).
static const char* const kDefaultAssertMessageFormat = "%s";
<<<<<<< HEAD
static const char* const kCanvasDrawAssertMessageFormat = "Drawing test step %s with SkCanvas";
static const char* const kNWayDrawAssertMessageFormat = "Drawing test step %s with SkNWayCanvas";
static const char* const kNWayStateAssertMessageFormat = "test step %s, SkNWayCanvas state consistency";
static const char* const kNWayIndirect1StateAssertMessageFormat = "test step %s, SkNWayCanvas indirect canvas 1 state consistency";
static const char* const kNWayIndirect2StateAssertMessageFormat = "test step %s, SkNWayCanvas indirect canvas 2 state consistency";
static const char* const kPdfAssertMessageFormat = "PDF sanity check failed %s";

class CanvasTestStep;
static SkTDArray<CanvasTestStep*>& testStepArray()
{
=======
static const char* const kCanvasDrawAssertMessageFormat =
    "Drawing test step %s with SkCanvas";
static const char* const kDeferredDrawAssertMessageFormat =
    "Drawing test step %s with SkDeferredCanvas";
static const char* const kNWayDrawAssertMessageFormat =
    "Drawing test step %s with SkNWayCanvas";
static const char* const kDeferredPreFlushAssertMessageFormat =
    "test step %s, SkDeferredCanvas state consistency before flush";
static const char* const kDeferredPostFlushPlaybackAssertMessageFormat =
    "test step %s, SkDeferredCanvas playback canvas state consistency after flush";
static const char* const kDeferredPostSilentFlushPlaybackAssertMessageFormat =
    "test step %s, SkDeferredCanvas playback canvas state consistency after silent flush";
static const char* const kNWayStateAssertMessageFormat =
    "test step %s, SkNWayCanvas state consistency";
static const char* const kNWayIndirect1StateAssertMessageFormat =
    "test step %s, SkNWayCanvas indirect canvas 1 state consistency";
static const char* const kNWayIndirect2StateAssertMessageFormat =
    "test step %s, SkNWayCanvas indirect canvas 2 state consistency";
static const char* const kPdfAssertMessageFormat =
    "PDF sanity check failed %s";

class CanvasTestStep;
static SkTDArray<CanvasTestStep*>& testStepArray() {
>>>>>>> miniblink49
    static SkTDArray<CanvasTestStep*> theTests;
    return theTests;
}

class CanvasTestStep {
public:
<<<<<<< HEAD
    CanvasTestStep(bool fEnablePdfTesting = true)
    {
=======
    CanvasTestStep(bool fEnablePdfTesting = true) {
>>>>>>> miniblink49
        *testStepArray().append() = this;
        fAssertMessageFormat = kDefaultAssertMessageFormat;
        this->fEnablePdfTesting = fEnablePdfTesting;
    }
    virtual ~CanvasTestStep() { }

    virtual void draw(SkCanvas*, const TestData&, skiatest::Reporter*) = 0;
    virtual const char* name() const = 0;

<<<<<<< HEAD
    const char* assertMessage()
    {
=======
    const char* assertMessage() {
>>>>>>> miniblink49
        fAssertMessage.printf(fAssertMessageFormat, name());
        return fAssertMessage.c_str();
    }

<<<<<<< HEAD
    void setAssertMessageFormat(const char* format)
    {
=======
    void setAssertMessageFormat(const char* format) {
>>>>>>> miniblink49
        fAssertMessageFormat = format;
    }

    bool enablePdfTesting() { return fEnablePdfTesting; }

private:
    SkString fAssertMessage;
    const char* fAssertMessageFormat;
    bool fEnablePdfTesting;
};

///////////////////////////////////////////////////////////////////////////////
// Macros for defining test steps

<<<<<<< HEAD
#define TEST_STEP(NAME, FUNCTION)                              \
    class NAME##_TestStep : public CanvasTestStep {            \
    public:                                                    \
        virtual void draw(SkCanvas* canvas, const TestData& d, \
            skiatest::Reporter* reporter)                      \
        {                                                      \
            FUNCTION(canvas, d, reporter, this);               \
        }                                                      \
        virtual const char* name() const { return #NAME; }     \
    };                                                         \
    static NAME##_TestStep NAME##_TestStepInstance;

#define TEST_STEP_NO_PDF(NAME, FUNCTION)                       \
    class NAME##_TestStep : public CanvasTestStep {            \
    public:                                                    \
        NAME##_TestStep()                                      \
            : CanvasTestStep(false)                            \
        {                                                      \
        }                                                      \
        virtual void draw(SkCanvas* canvas, const TestData& d, \
            skiatest::Reporter* reporter)                      \
        {                                                      \
            FUNCTION(canvas, d, reporter, this);               \
        }                                                      \
        virtual const char* name() const { return #NAME; }     \
    };                                                         \
    static NAME##_TestStep NAME##_TestStepInstance;

#define SIMPLE_TEST_STEP(NAME, CALL)                                \
    static void NAME##TestStep(SkCanvas* canvas, const TestData& d, \
        skiatest::Reporter*, CanvasTestStep*)                       \
    {                                                               \
        canvas->CALL;                                               \
    }                                                               \
    TEST_STEP(NAME, NAME##TestStep)

#define SIMPLE_TEST_STEP_WITH_ASSERT(NAME, CALL)                    \
    static void NAME##TestStep(SkCanvas* canvas, const TestData& d, \
        skiatest::Reporter*, CanvasTestStep* testStep)              \
    {                                                               \
        REPORTER_ASSERT_MESSAGE(reporter, canvas->CALL,             \
            testStep->assertMessage());                             \
    }                                                               \
    TEST_STEP(NAME, NAME##TestStep)
=======
#define TEST_STEP(NAME, FUNCTION)                                       \
class NAME##_TestStep : public CanvasTestStep{                          \
public:                                                                 \
    virtual void draw(SkCanvas* canvas, const TestData& d,       \
        skiatest::Reporter* reporter) {                                 \
        FUNCTION (canvas, d, reporter, this);                    \
    }                                                                   \
    virtual const char* name() const {return #NAME ;}                   \
};                                                                      \
static NAME##_TestStep NAME##_TestStepInstance;

#define TEST_STEP_NO_PDF(NAME, FUNCTION)                                \
class NAME##_TestStep : public CanvasTestStep{                          \
public:                                                                 \
    NAME##_TestStep() : CanvasTestStep(false) {}                        \
    virtual void draw(SkCanvas* canvas, const TestData& d,       \
        skiatest::Reporter* reporter) {                                 \
        FUNCTION (canvas, d, reporter, this);                    \
    }                                                                   \
    virtual const char* name() const {return #NAME ;}                   \
};                                                                      \
static NAME##_TestStep NAME##_TestStepInstance;

#define SIMPLE_TEST_STEP(NAME, CALL)                                    \
static void NAME##TestStep(SkCanvas* canvas, const TestData& d,  \
    skiatest::Reporter*, CanvasTestStep*) {                             \
    canvas-> CALL ;                                                     \
}                                                                       \
TEST_STEP(NAME, NAME##TestStep )

#define SIMPLE_TEST_STEP_WITH_ASSERT(NAME, CALL)                           \
static void NAME##TestStep(SkCanvas* canvas, const TestData& d,     \
    skiatest::Reporter*, CanvasTestStep* testStep) {                       \
    REPORTER_ASSERT_MESSAGE(reporter, canvas-> CALL ,                      \
        testStep->assertMessage());                                        \
}                                                                          \
TEST_STEP(NAME, NAME##TestStep )

>>>>>>> miniblink49

///////////////////////////////////////////////////////////////////////////////
// Basic test steps for most virtual methods in SkCanvas that draw or affect
// the state of the canvas.

SIMPLE_TEST_STEP(Translate, translate(SkIntToScalar(1), SkIntToScalar(2)));
SIMPLE_TEST_STEP(Scale, scale(SkIntToScalar(1), SkIntToScalar(2)));
SIMPLE_TEST_STEP(Rotate, rotate(SkIntToScalar(1)));
SIMPLE_TEST_STEP(Skew, skew(SkIntToScalar(1), SkIntToScalar(2)));
SIMPLE_TEST_STEP(Concat, concat(d.fMatrix));
SIMPLE_TEST_STEP(SetMatrix, setMatrix(d.fMatrix));
SIMPLE_TEST_STEP(ClipRect, clipRect(d.fRect));
SIMPLE_TEST_STEP(ClipPath, clipPath(d.fPath));
SIMPLE_TEST_STEP(ClipRegion, clipRegion(d.fRegion, SkRegion::kReplace_Op));
SIMPLE_TEST_STEP(Clear, clear(d.fColor));

///////////////////////////////////////////////////////////////////////////////
// Complex test steps

static void SaveMatrixClipStep(SkCanvas* canvas, const TestData& d,
<<<<<<< HEAD
    skiatest::Reporter* reporter, CanvasTestStep* testStep)
{
=======
                               skiatest::Reporter* reporter, CanvasTestStep* testStep) {
>>>>>>> miniblink49
    int saveCount = canvas->getSaveCount();
    canvas->save();
    canvas->translate(SkIntToScalar(1), SkIntToScalar(2));
    canvas->clipRegion(d.fRegion);
    canvas->restore();
    REPORTER_ASSERT_MESSAGE(reporter, canvas->getSaveCount() == saveCount,
        testStep->assertMessage());
    REPORTER_ASSERT_MESSAGE(reporter, canvas->getTotalMatrix().isIdentity(),
        testStep->assertMessage());
<<<<<<< HEAD
    //    REPORTER_ASSERT_MESSAGE(reporter, canvas->getTotalClip() != kTestRegion, testStep->assertMessage());
=======
//    REPORTER_ASSERT_MESSAGE(reporter, canvas->getTotalClip() != kTestRegion, testStep->assertMessage());
>>>>>>> miniblink49
}
TEST_STEP(SaveMatrixClip, SaveMatrixClipStep);

static void SaveLayerStep(SkCanvas* canvas, const TestData& d,
<<<<<<< HEAD
    skiatest::Reporter* reporter, CanvasTestStep* testStep)
{
    int saveCount = canvas->getSaveCount();
    canvas->saveLayer(nullptr, nullptr);
=======
                          skiatest::Reporter* reporter, CanvasTestStep* testStep) {
    int saveCount = canvas->getSaveCount();
    canvas->saveLayer(NULL, NULL);
>>>>>>> miniblink49
    canvas->restore();
    REPORTER_ASSERT_MESSAGE(reporter, canvas->getSaveCount() == saveCount,
        testStep->assertMessage());
}
TEST_STEP(SaveLayer, SaveLayerStep);

static void BoundedSaveLayerStep(SkCanvas* canvas, const TestData& d,
<<<<<<< HEAD
    skiatest::Reporter* reporter, CanvasTestStep* testStep)
{
    int saveCount = canvas->getSaveCount();
    canvas->saveLayer(&d.fRect, nullptr);
=======
                                 skiatest::Reporter* reporter, CanvasTestStep* testStep) {
    int saveCount = canvas->getSaveCount();
    canvas->saveLayer(&d.fRect, NULL);
>>>>>>> miniblink49
    canvas->restore();
    REPORTER_ASSERT_MESSAGE(reporter, canvas->getSaveCount() == saveCount,
        testStep->assertMessage());
}
TEST_STEP(BoundedSaveLayer, BoundedSaveLayerStep);

static void PaintSaveLayerStep(SkCanvas* canvas, const TestData& d,
<<<<<<< HEAD
    skiatest::Reporter* reporter, CanvasTestStep* testStep)
{
    int saveCount = canvas->getSaveCount();
    canvas->saveLayer(nullptr, &d.fPaint);
=======
                               skiatest::Reporter* reporter, CanvasTestStep* testStep) {
    int saveCount = canvas->getSaveCount();
    canvas->saveLayer(NULL, &d.fPaint);
>>>>>>> miniblink49
    canvas->restore();
    REPORTER_ASSERT_MESSAGE(reporter, canvas->getSaveCount() == saveCount,
        testStep->assertMessage());
}
TEST_STEP(PaintSaveLayer, PaintSaveLayerStep);

static void TwoClipOpsStep(SkCanvas* canvas, const TestData& d,
<<<<<<< HEAD
    skiatest::Reporter*, CanvasTestStep*)
{
=======
                           skiatest::Reporter*, CanvasTestStep*) {
>>>>>>> miniblink49
    // This test exercises a functionality in SkPicture that leads to the
    // recording of restore offset placeholders.  This test will trigger an
    // assertion at playback time if the placeholders are not properly
    // filled when the recording ends.
    canvas->clipRect(d.fRect);
    canvas->clipRegion(d.fRegion);
}
TEST_STEP(TwoClipOps, TwoClipOpsStep);

// exercise fix for http://code.google.com/p/skia/issues/detail?id=560
// ('SkPathStroker::lineTo() fails for line with length SK_ScalarNearlyZero')
static void DrawNearlyZeroLengthPathTestStep(SkCanvas* canvas, const TestData& d,
<<<<<<< HEAD
    skiatest::Reporter*, CanvasTestStep*)
{
=======
                                             skiatest::Reporter*, CanvasTestStep*) {
>>>>>>> miniblink49
    SkPaint paint;
    paint.setStrokeWidth(SkIntToScalar(1));
    paint.setStyle(SkPaint::kStroke_Style);

    canvas->drawPath(d.fNearlyZeroLengthPath, paint);
}
TEST_STEP(DrawNearlyZeroLengthPath, DrawNearlyZeroLengthPathTestStep);

static void DrawVerticesShaderTestStep(SkCanvas* canvas, const TestData& d,
<<<<<<< HEAD
    skiatest::Reporter*, CanvasTestStep*)
{
=======
                                       skiatest::Reporter*, CanvasTestStep*) {
>>>>>>> miniblink49
    SkPoint pts[4];
    pts[0].set(0, 0);
    pts[1].set(SkIntToScalar(d.fWidth), 0);
    pts[2].set(SkIntToScalar(d.fWidth), SkIntToScalar(d.fHeight));
    pts[3].set(0, SkIntToScalar(d.fHeight));
    SkPaint paint;
<<<<<<< HEAD
    paint.setShader(SkShader::MakeBitmapShader(d.fBitmap, SkShader::kClamp_TileMode,
        SkShader::kClamp_TileMode));
    canvas->drawVertices(SkCanvas::kTriangleFan_VertexMode, 4, pts, pts,
        nullptr, nullptr, nullptr, 0, paint);
=======
    SkShader* shader = SkShader::CreateBitmapShader(d.fBitmap,
        SkShader::kClamp_TileMode, SkShader::kClamp_TileMode);
    paint.setShader(shader)->unref();
    canvas->drawVertices(SkCanvas::kTriangleFan_VertexMode, 4, pts, pts,
                         NULL, NULL, NULL, 0, paint);
>>>>>>> miniblink49
}
// NYI: issue 240.
TEST_STEP_NO_PDF(DrawVerticesShader, DrawVerticesShaderTestStep);

static void DrawPictureTestStep(SkCanvas* canvas, const TestData& d,
<<<<<<< HEAD
    skiatest::Reporter*, CanvasTestStep*)
{
    SkPictureRecorder recorder;
    SkCanvas* testCanvas = recorder.beginRecording(SkIntToScalar(d.fWidth), SkIntToScalar(d.fHeight),
        nullptr, 0);
    testCanvas->scale(SkIntToScalar(2), SkIntToScalar(1));
    testCanvas->clipRect(d.fRect);
    testCanvas->drawRect(d.fRect, d.fPaint);

    canvas->drawPicture(recorder.finishRecordingAsPicture());
=======
                                skiatest::Reporter*, CanvasTestStep*) {
    SkPictureRecorder recorder;
    SkCanvas* testCanvas = recorder.beginRecording(SkIntToScalar(d.fWidth), SkIntToScalar(d.fHeight),
                                                   NULL, 0);
    testCanvas->scale(SkIntToScalar(2), SkIntToScalar(1));
    testCanvas->clipRect(d.fRect);
    testCanvas->drawRect(d.fRect, d.fPaint);
    SkAutoTUnref<SkPicture> testPicture(recorder.endRecording());

    canvas->drawPicture(testPicture);
>>>>>>> miniblink49
}
TEST_STEP(DrawPicture, DrawPictureTestStep);

static void SaveRestoreTestStep(SkCanvas* canvas, const TestData& d,
<<<<<<< HEAD
    skiatest::Reporter* reporter, CanvasTestStep* testStep)
{
=======
                                skiatest::Reporter* reporter, CanvasTestStep* testStep) {
>>>>>>> miniblink49
    int baseSaveCount = canvas->getSaveCount();
    int n = canvas->save();
    REPORTER_ASSERT_MESSAGE(reporter, baseSaveCount == n, testStep->assertMessage());
    REPORTER_ASSERT_MESSAGE(reporter, baseSaveCount + 1 == canvas->getSaveCount(),
        testStep->assertMessage());
    canvas->save();
    canvas->save();
    REPORTER_ASSERT_MESSAGE(reporter, baseSaveCount + 3 == canvas->getSaveCount(),
        testStep->assertMessage());
    canvas->restoreToCount(baseSaveCount + 1);
    REPORTER_ASSERT_MESSAGE(reporter, baseSaveCount + 1 == canvas->getSaveCount(),
        testStep->assertMessage());

    // should this pin to 1, or be a no-op, or crash?
    canvas->restoreToCount(0);
    REPORTER_ASSERT_MESSAGE(reporter, 1 == canvas->getSaveCount(),
        testStep->assertMessage());
}
TEST_STEP(SaveRestore, SaveRestoreTestStep);

static void NestedSaveRestoreWithSolidPaintTestStep(SkCanvas* canvas, const TestData& d,
<<<<<<< HEAD
    skiatest::Reporter*, CanvasTestStep*)
{
=======
                                                    skiatest::Reporter*, CanvasTestStep*) {
>>>>>>> miniblink49
    // This test step challenges the TestDeferredCanvasStateConsistency
    // test cases because the opaque paint can trigger an optimization
    // that discards previously recorded commands. The challenge is to maintain
    // correct clip and matrix stack state.
    canvas->resetMatrix();
    canvas->rotate(SkIntToScalar(30));
    canvas->save();
    canvas->translate(SkIntToScalar(2), SkIntToScalar(1));
    canvas->save();
    canvas->scale(SkIntToScalar(3), SkIntToScalar(3));
    SkPaint paint;
    paint.setColor(0xFFFFFFFF);
    canvas->drawPaint(paint);
    canvas->restore();
    canvas->restore();
}
<<<<<<< HEAD
TEST_STEP(NestedSaveRestoreWithSolidPaint,
    NestedSaveRestoreWithSolidPaintTestStep);

static void NestedSaveRestoreWithFlushTestStep(SkCanvas* canvas, const TestData& d,
    skiatest::Reporter*, CanvasTestStep*)
{
=======
TEST_STEP(NestedSaveRestoreWithSolidPaint, \
    NestedSaveRestoreWithSolidPaintTestStep);

static void NestedSaveRestoreWithFlushTestStep(SkCanvas* canvas, const TestData& d,
                                               skiatest::Reporter*, CanvasTestStep*) {
>>>>>>> miniblink49
    // This test step challenges the TestDeferredCanvasStateConsistency
    // test case because the canvas flush on a deferred canvas will
    // reset the recording session. The challenge is to maintain correct
    // clip and matrix stack state on the playback canvas.
    canvas->resetMatrix();
    canvas->rotate(SkIntToScalar(30));
    canvas->save();
    canvas->translate(SkIntToScalar(2), SkIntToScalar(1));
    canvas->save();
    canvas->scale(SkIntToScalar(3), SkIntToScalar(3));
<<<<<<< HEAD
    canvas->drawRect(d.fRect, d.fPaint);
=======
    canvas->drawRect(d.fRect,d.fPaint);
>>>>>>> miniblink49
    canvas->flush();
    canvas->restore();
    canvas->restore();
}
TEST_STEP(NestedSaveRestoreWithFlush, NestedSaveRestoreWithFlushTestStep);

<<<<<<< HEAD
static void DescribeTopLayerTestStep(SkCanvas* canvas,
    const TestData& d,
    skiatest::Reporter* reporter,
    CanvasTestStep* testStep)
{
    SkMatrix m;
    SkIRect r;
    // NOTE: adjustToTopLayer() does *not* reduce the clip size, even if the canvas
    // is smaller than 10x10!

    canvas->temporary_internal_describeTopLayer(&m, &r);
    REPORTER_ASSERT_MESSAGE(reporter, m.isIdentity(), testStep->assertMessage());
    REPORTER_ASSERT_MESSAGE(reporter, r == SkIRect::MakeXYWH(0, 0, 2, 2),
        testStep->assertMessage());

    // Putting a full-canvas layer on it should make no change to the results.
    SkRect layerBounds = SkRect::MakeXYWH(0.f, 0.f, 10.f, 10.f);
    canvas->saveLayer(layerBounds, nullptr);
    canvas->temporary_internal_describeTopLayer(&m, &r);
    REPORTER_ASSERT_MESSAGE(reporter, m.isIdentity(), testStep->assertMessage());
    REPORTER_ASSERT_MESSAGE(reporter, r == SkIRect::MakeXYWH(0, 0, 2, 2),
        testStep->assertMessage());
    canvas->restore();

    // Adding a translated layer translates the results.
    // Default canvas is only 2x2, so can't offset our layer by very much at all;
    // saveLayer() aborts if the bounds don't intersect.
    layerBounds = SkRect::MakeXYWH(1.f, 1.f, 6.f, 6.f);
    canvas->saveLayer(layerBounds, nullptr);
    canvas->temporary_internal_describeTopLayer(&m, &r);
    REPORTER_ASSERT_MESSAGE(reporter, m == SkMatrix::MakeTrans(-1.f, -1.f),
        testStep->assertMessage());
    REPORTER_ASSERT_MESSAGE(reporter, r == SkIRect::MakeXYWH(0, 0, 1, 1),
        testStep->assertMessage());
    canvas->restore();
}
TEST_STEP(DescribeTopLayer, DescribeTopLayerTestStep);

class CanvasTestingAccess {
public:
    static bool SameState(const SkCanvas* canvas1, const SkCanvas* canvas2)
    {
        SkCanvas::LayerIter layerIter1(const_cast<SkCanvas*>(canvas1), false);
        SkCanvas::LayerIter layerIter2(const_cast<SkCanvas*>(canvas2), false);
        while (!layerIter1.done() && !layerIter2.done()) {
            if (layerIter1.matrix() != layerIter2.matrix()) {
                return false;
            }
            if (layerIter1.clip() != layerIter2.clip()) {
                return false;
            }
            if (layerIter1.paint() != layerIter2.paint()) {
                return false;
            }
            if (layerIter1.x() != layerIter2.x()) {
                return false;
            }
            if (layerIter1.y() != layerIter2.y()) {
                return false;
            }
            layerIter1.next();
            layerIter2.next();
        }
        if (!layerIter1.done()) {
            return false;
        }
        if (!layerIter2.done()) {
            return false;
        }
        return true;
    }
};

static void AssertCanvasStatesEqual(skiatest::Reporter* reporter, const TestData& d,
    const SkCanvas* canvas1, const SkCanvas* canvas2,
    CanvasTestStep* testStep)
{
    REPORTER_ASSERT_MESSAGE(reporter, canvas1->getDeviceSize() == canvas2->getDeviceSize(), testStep->assertMessage());
    REPORTER_ASSERT_MESSAGE(reporter, canvas1->getSaveCount() == canvas2->getSaveCount(), testStep->assertMessage());
=======
static void AssertCanvasStatesEqual(skiatest::Reporter* reporter, const TestData& d,
                                    const SkCanvas* canvas1, const SkCanvas* canvas2,
                                    CanvasTestStep* testStep) {
    REPORTER_ASSERT_MESSAGE(reporter, canvas1->getDeviceSize() ==
        canvas2->getDeviceSize(), testStep->assertMessage());
    REPORTER_ASSERT_MESSAGE(reporter, canvas1->getSaveCount() ==
        canvas2->getSaveCount(), testStep->assertMessage());
>>>>>>> miniblink49

    SkRect bounds1, bounds2;
    REPORTER_ASSERT_MESSAGE(reporter,
        canvas1->getClipBounds(&bounds1) == canvas2->getClipBounds(&bounds2),
        testStep->assertMessage());
    REPORTER_ASSERT_MESSAGE(reporter, bounds1 == bounds2,
<<<<<<< HEAD
        testStep->assertMessage());

#ifdef SK_SUPPORT_LEGACY_DRAWFILTER
    REPORTER_ASSERT_MESSAGE(reporter, canvas1->getDrawFilter() == canvas2->getDrawFilter(), testStep->assertMessage());
#endif

    SkIRect deviceBounds1, deviceBounds2;
    REPORTER_ASSERT_MESSAGE(reporter,
        canvas1->getClipDeviceBounds(&deviceBounds1) == canvas2->getClipDeviceBounds(&deviceBounds2),
        testStep->assertMessage());
    REPORTER_ASSERT_MESSAGE(reporter, deviceBounds1 == deviceBounds2, testStep->assertMessage());
    REPORTER_ASSERT_MESSAGE(reporter, canvas1->getTotalMatrix() == canvas2->getTotalMatrix(), testStep->assertMessage());
    REPORTER_ASSERT_MESSAGE(reporter, equal_clips(*canvas1, *canvas2), testStep->assertMessage());

    REPORTER_ASSERT_MESSAGE(reporter,
        CanvasTestingAccess::SameState(canvas1, canvas2),
        testStep->assertMessage());
}

static void TestPdfDevice(skiatest::Reporter* reporter,
    const TestData& d,
    CanvasTestStep* testStep)
{
    SkDynamicMemoryWStream outStream;
    sk_sp<SkDocument> doc(SkDocument::MakePDF(&outStream));
#if SK_SUPPORT_PDF
    REPORTER_ASSERT(reporter, doc);
#else
    REPORTER_ASSERT(reporter, !doc);
#endif // SK_SUPPORT_PDF
    if (!doc) {
        return;
    }
    SkCanvas* canvas = doc->beginPage(SkIntToScalar(d.fWidth),
        SkIntToScalar(d.fHeight));
=======
                            testStep->assertMessage());

    REPORTER_ASSERT_MESSAGE(reporter, canvas1->getDrawFilter() ==
        canvas2->getDrawFilter(), testStep->assertMessage());
    SkIRect deviceBounds1, deviceBounds2;
    REPORTER_ASSERT_MESSAGE(reporter,
        canvas1->getClipDeviceBounds(&deviceBounds1) ==
        canvas2->getClipDeviceBounds(&deviceBounds2),
        testStep->assertMessage());
    REPORTER_ASSERT_MESSAGE(reporter, deviceBounds1 == deviceBounds2, testStep->assertMessage());
    REPORTER_ASSERT_MESSAGE(reporter, canvas1->getTotalMatrix() ==
        canvas2->getTotalMatrix(), testStep->assertMessage());
    REPORTER_ASSERT_MESSAGE(reporter, equal_clips(*canvas1, *canvas2), testStep->assertMessage());

    SkCanvas::LayerIter layerIter1(const_cast<SkCanvas*>(canvas1), false);
    SkCanvas::LayerIter layerIter2(const_cast<SkCanvas*>(canvas2), false);
    while (!layerIter1.done() && !layerIter2.done()) {
        REPORTER_ASSERT_MESSAGE(reporter, layerIter1.matrix() ==
            layerIter2.matrix(), testStep->assertMessage());
        REPORTER_ASSERT_MESSAGE(reporter, layerIter1.clip() ==
            layerIter2.clip(), testStep->assertMessage());
        REPORTER_ASSERT_MESSAGE(reporter, layerIter1.paint() ==
            layerIter2.paint(), testStep->assertMessage());
        REPORTER_ASSERT_MESSAGE(reporter, layerIter1.x() ==
            layerIter2.x(), testStep->assertMessage());
        REPORTER_ASSERT_MESSAGE(reporter, layerIter1.y() ==
            layerIter2.y(), testStep->assertMessage());
        layerIter1.next();
        layerIter2.next();
    }
    REPORTER_ASSERT_MESSAGE(reporter, layerIter1.done(),
        testStep->assertMessage());
    REPORTER_ASSERT_MESSAGE(reporter, layerIter2.done(),
        testStep->assertMessage());

}

static void TestPdfDevice(skiatest::Reporter* reporter,
                          const TestData& d,
                          CanvasTestStep* testStep) {
    SkDynamicMemoryWStream outStream;
    SkAutoTUnref<SkDocument> doc(SkDocument::CreatePDF(&outStream));
    SkCanvas* canvas = doc->beginPage(SkIntToScalar(d.fWidth),
                                      SkIntToScalar(d.fHeight));
>>>>>>> miniblink49
    REPORTER_ASSERT(reporter, canvas);
    testStep->setAssertMessageFormat(kPdfAssertMessageFormat);
    testStep->draw(canvas, d, reporter);

    REPORTER_ASSERT(reporter, doc->close());
}

<<<<<<< HEAD
=======
// The following class groups static functions that need to access
// the privates members of SkDeferredCanvas
class SkDeferredCanvasTester {
public:
    static void TestDeferredCanvasStateConsistency(
        skiatest::Reporter* reporter,
        const TestData& d,
        CanvasTestStep* testStep,
        const SkCanvas& referenceCanvas, bool silent) {

        SkAutoTUnref<SkSurface> surface(createSurface(0xFFFFFFFF));
        SkAutoTUnref<SkDeferredCanvas> deferredCanvas(SkDeferredCanvas::Create(surface.get()));

        testStep->setAssertMessageFormat(kDeferredDrawAssertMessageFormat);
        testStep->draw(deferredCanvas, d, reporter);
        testStep->setAssertMessageFormat(kDeferredPreFlushAssertMessageFormat);
        AssertCanvasStatesEqual(reporter, d, deferredCanvas, &referenceCanvas, testStep);

        if (silent) {
            deferredCanvas->silentFlush();
        } else {
            deferredCanvas->flush();
        }

        testStep->setAssertMessageFormat(
            silent ? kDeferredPostSilentFlushPlaybackAssertMessageFormat :
            kDeferredPostFlushPlaybackAssertMessageFormat);
        AssertCanvasStatesEqual(reporter, d, deferredCanvas->immediateCanvas(),
                                &referenceCanvas, testStep);

        // Verified that deferred canvas state is not affected by flushing
        // pending draw operations

        // The following test code is commented out because it currently fails.
        // Issue: http://code.google.com/p/skia/issues/detail?id=496
        /*
        testStep->setAssertMessageFormat(kDeferredPostFlushAssertMessageFormat);
        AssertCanvasStatesEqual(reporter, &deferredCanvas, &referenceCanvas,
            testStep);
        */
    }
};

>>>>>>> miniblink49
// unused
static void TestNWayCanvasStateConsistency(
    skiatest::Reporter* reporter,
    const TestData& d,
    CanvasTestStep* testStep,
<<<<<<< HEAD
    const SkCanvas& referenceCanvas)
{
=======
    const SkCanvas& referenceCanvas) {
>>>>>>> miniblink49

    SkBitmap indirectStore1;
    createBitmap(&indirectStore1, 0xFFFFFFFF);
    SkCanvas indirectCanvas1(indirectStore1);

    SkBitmap indirectStore2;
    createBitmap(&indirectStore2, 0xFFFFFFFF);
    SkCanvas indirectCanvas2(indirectStore2);

    SkISize canvasSize = referenceCanvas.getDeviceSize();
    SkNWayCanvas nWayCanvas(canvasSize.width(), canvasSize.height());
    nWayCanvas.addCanvas(&indirectCanvas1);
    nWayCanvas.addCanvas(&indirectCanvas2);

    testStep->setAssertMessageFormat(kNWayDrawAssertMessageFormat);
    testStep->draw(&nWayCanvas, d, reporter);
    // Verify that the SkNWayCanvas reports consitent state
    testStep->setAssertMessageFormat(kNWayStateAssertMessageFormat);
    AssertCanvasStatesEqual(reporter, d, &nWayCanvas, &referenceCanvas, testStep);
    // Verify that the indirect canvases report consitent state
    testStep->setAssertMessageFormat(kNWayIndirect1StateAssertMessageFormat);
    AssertCanvasStatesEqual(reporter, d, &indirectCanvas1, &referenceCanvas, testStep);
    testStep->setAssertMessageFormat(kNWayIndirect2StateAssertMessageFormat);
    AssertCanvasStatesEqual(reporter, d, &indirectCanvas2, &referenceCanvas, testStep);
}

/*
 * This sub-test verifies that the test step passes when executed
 * with SkCanvas and with classes derrived from SkCanvas. It also verifies
 * that the all canvas derivatives report the same state as an SkCanvas
 * after having executed the test step.
 */
static void TestOverrideStateConsistency(skiatest::Reporter* reporter, const TestData& d,
<<<<<<< HEAD
    CanvasTestStep* testStep)
{
=======
                                         CanvasTestStep* testStep) {
>>>>>>> miniblink49
    SkBitmap referenceStore;
    createBitmap(&referenceStore, 0xFFFFFFFF);
    SkCanvas referenceCanvas(referenceStore);
    testStep->setAssertMessageFormat(kCanvasDrawAssertMessageFormat);
    testStep->draw(&referenceCanvas, d, reporter);

<<<<<<< HEAD
=======
    SkDeferredCanvasTester::TestDeferredCanvasStateConsistency(reporter, d, testStep, referenceCanvas, false);

    SkDeferredCanvasTester::TestDeferredCanvasStateConsistency(reporter, d, testStep, referenceCanvas, true);

>>>>>>> miniblink49
    // The following test code is disabled because SkNWayCanvas does not
    // report correct clipping and device bounds information
    // Issue: http://code.google.com/p/skia/issues/detail?id=501

    if (false) { // avoid bit rot, suppress warning
        TestNWayCanvasStateConsistency(reporter, d, testStep, referenceCanvas);
    }

    if (false) { // avoid bit rot, suppress warning
        test_clipVisitor(reporter, &referenceCanvas);
    }
    test_clipstack(reporter);
}

<<<<<<< HEAD
static void test_newraster(skiatest::Reporter* reporter)
{
    SkImageInfo info = SkImageInfo::MakeN32Premul(10, 10);
    const size_t minRowBytes = info.minRowBytes();
    const size_t size = info.getSafeSize(minRowBytes);
    SkAutoTMalloc<SkPMColor> storage(size);
    SkPMColor* baseAddr = storage.get();
=======
static void test_newraster(skiatest::Reporter* reporter) {
    SkImageInfo info = SkImageInfo::MakeN32Premul(10, 10);
    const size_t minRowBytes = info.minRowBytes();
    const size_t size = info.getSafeSize(minRowBytes);
    SkAutoMalloc storage(size);
    SkPMColor* baseAddr = static_cast<SkPMColor*>(storage.get());
>>>>>>> miniblink49
    sk_bzero(baseAddr, size);

    SkCanvas* canvas = SkCanvas::NewRasterDirect(info, baseAddr, minRowBytes);
    REPORTER_ASSERT(reporter, canvas);

<<<<<<< HEAD
    SkPixmap pmap;
    const SkPMColor* addr = canvas->peekPixels(&pmap) ? pmap.addr32() : nullptr;
    REPORTER_ASSERT(reporter, addr);
    REPORTER_ASSERT(reporter, info == pmap.info());
    REPORTER_ASSERT(reporter, minRowBytes == pmap.rowBytes());
=======
    SkImageInfo info2;
    size_t rowBytes;
    const SkPMColor* addr = (const SkPMColor*)canvas->peekPixels(&info2, &rowBytes);
    REPORTER_ASSERT(reporter, addr);
    REPORTER_ASSERT(reporter, info == info2);
    REPORTER_ASSERT(reporter, minRowBytes == rowBytes);
>>>>>>> miniblink49
    for (int y = 0; y < info.height(); ++y) {
        for (int x = 0; x < info.width(); ++x) {
            REPORTER_ASSERT(reporter, 0 == addr[x]);
        }
<<<<<<< HEAD
        addr = (const SkPMColor*)((const char*)addr + pmap.rowBytes());
    }
    delete canvas;

    // now try a deliberately bad info
    info = info.makeWH(-1, info.height());
    REPORTER_ASSERT(reporter, nullptr == SkCanvas::NewRasterDirect(info, baseAddr, minRowBytes));

    // too big
    info = info.makeWH(1 << 30, 1 << 30);
    REPORTER_ASSERT(reporter, nullptr == SkCanvas::NewRasterDirect(info, baseAddr, minRowBytes));

    // not a valid pixel type
    info = SkImageInfo::Make(10, 10, kUnknown_SkColorType, info.alphaType());
    REPORTER_ASSERT(reporter, nullptr == SkCanvas::NewRasterDirect(info, baseAddr, minRowBytes));
=======
        addr = (const SkPMColor*)((const char*)addr + rowBytes);
    }
    SkDELETE(canvas);

    // now try a deliberately bad info
    info = info.makeWH(-1, info.height());
    REPORTER_ASSERT(reporter, NULL == SkCanvas::NewRasterDirect(info, baseAddr, minRowBytes));

    // too big
    info = info.makeWH(1 << 30, 1 << 30);
    REPORTER_ASSERT(reporter, NULL == SkCanvas::NewRasterDirect(info, baseAddr, minRowBytes));

    // not a valid pixel type
    info = SkImageInfo::Make(10, 10, kUnknown_SkColorType, info.alphaType());
    REPORTER_ASSERT(reporter, NULL == SkCanvas::NewRasterDirect(info, baseAddr, minRowBytes));
>>>>>>> miniblink49

    // We should succeed with a zero-sized valid info
    info = SkImageInfo::MakeN32Premul(0, 0);
    canvas = SkCanvas::NewRasterDirect(info, baseAddr, minRowBytes);
    REPORTER_ASSERT(reporter, canvas);
<<<<<<< HEAD
    delete canvas;
}

DEF_TEST(Canvas, reporter)
{
=======
    SkDELETE(canvas);
}

DEF_TEST(Canvas, reporter) {
>>>>>>> miniblink49
    TestData d;

    for (int testStep = 0; testStep < testStepArray().count(); testStep++) {
        TestOverrideStateConsistency(reporter, d, testStepArray()[testStep]);
        if (testStepArray()[testStep]->enablePdfTesting()) {
            TestPdfDevice(reporter, d, testStepArray()[testStep]);
        }
    }

    test_newraster(reporter);
}

<<<<<<< HEAD
DEF_TEST(Canvas_SaveState, reporter)
{
=======
DEF_TEST(Canvas_SaveState, reporter) {
>>>>>>> miniblink49
    SkCanvas canvas(10, 10);
    REPORTER_ASSERT(reporter, 1 == canvas.getSaveCount());

    int n = canvas.save();
    REPORTER_ASSERT(reporter, 1 == n);
    REPORTER_ASSERT(reporter, 2 == canvas.getSaveCount());

<<<<<<< HEAD
    n = canvas.saveLayer(nullptr, nullptr);
    REPORTER_ASSERT(reporter, 2 == n);
    REPORTER_ASSERT(reporter, 3 == canvas.getSaveCount());

=======
    n = canvas.saveLayer(NULL, NULL);
    REPORTER_ASSERT(reporter, 2 == n);
    REPORTER_ASSERT(reporter, 3 == canvas.getSaveCount());
    
>>>>>>> miniblink49
    canvas.restore();
    REPORTER_ASSERT(reporter, 2 == canvas.getSaveCount());
    canvas.restore();
    REPORTER_ASSERT(reporter, 1 == canvas.getSaveCount());
}

<<<<<<< HEAD
DEF_TEST(Canvas_ClipEmptyPath, reporter)
{
=======
DEF_TEST(Canvas_ClipEmptyPath, reporter) {
>>>>>>> miniblink49
    SkCanvas canvas(10, 10);
    canvas.save();
    SkPath path;
    canvas.clipPath(path);
    canvas.restore();
    canvas.save();
    path.moveTo(5, 5);
    canvas.clipPath(path);
    canvas.restore();
    canvas.save();
    path.moveTo(7, 7);
<<<<<<< HEAD
    canvas.clipPath(path); // should not assert here
=======
    canvas.clipPath(path);  // should not assert here
>>>>>>> miniblink49
    canvas.restore();
}

namespace {

class MockFilterCanvas : public SkPaintFilterCanvas {
public:
<<<<<<< HEAD
    MockFilterCanvas(SkCanvas* canvas)
        : INHERITED(canvas)
    {
    }

protected:
    bool onFilter(SkTCopyOnFirstWrite<SkPaint>*, Type) const override { return true; }
=======
    MockFilterCanvas(SkCanvas* canvas) : INHERITED(canvas) { }

protected:
    void onFilterPaint(SkPaint *paint, Type type) const override { }
>>>>>>> miniblink49

private:
    typedef SkPaintFilterCanvas INHERITED;
};

} // anonymous namespace

// SkPaintFilterCanvas should inherit the initial target canvas state.
<<<<<<< HEAD
DEF_TEST(PaintFilterCanvas_ConsistentState, reporter)
{
=======
DEF_TEST(PaintFilterCanvas_ConsistentState, reporter) {
>>>>>>> miniblink49
    SkCanvas canvas(100, 100);
    canvas.clipRect(SkRect::MakeXYWH(12.7f, 12.7f, 75, 75));
    canvas.scale(0.5f, 0.75f);

    SkRect clip1, clip2;

    MockFilterCanvas filterCanvas(&canvas);
    REPORTER_ASSERT(reporter, canvas.getTotalMatrix() == filterCanvas.getTotalMatrix());
    REPORTER_ASSERT(reporter, canvas.getClipBounds(&clip1) == filterCanvas.getClipBounds(&clip2));
    REPORTER_ASSERT(reporter, clip1 == clip2);

    filterCanvas.clipRect(SkRect::MakeXYWH(30.5f, 30.7f, 100, 100));
    filterCanvas.scale(0.75f, 0.5f);
    REPORTER_ASSERT(reporter, canvas.getTotalMatrix() == filterCanvas.getTotalMatrix());
    REPORTER_ASSERT(reporter, canvas.getClipBounds(&clip1) == filterCanvas.getClipBounds(&clip2));
    REPORTER_ASSERT(reporter, clip1 == clip2);
}
