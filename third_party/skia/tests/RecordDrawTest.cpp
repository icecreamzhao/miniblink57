/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "RecordTestUtils.h"
#include "Test.h"
=======
#include "Test.h"
#include "RecordTestUtils.h"
>>>>>>> miniblink49

#include "SkDebugCanvas.h"
#include "SkDropShadowImageFilter.h"
#include "SkImagePriv.h"
#include "SkRecord.h"
#include "SkRecordDraw.h"
#include "SkRecordOpts.h"
#include "SkRecorder.h"
#include "SkRecords.h"
#include "SkSurface.h"

static const int W = 1920, H = 1080;

class JustOneDraw : public SkPicture::AbortCallback {
public:
<<<<<<< HEAD
    JustOneDraw()
        : fCalls(0)
    {
    }

    bool abort() override { return fCalls++ > 0; }

=======
    JustOneDraw() : fCalls(0) {}

    bool abort() override { return fCalls++ > 0; }
>>>>>>> miniblink49
private:
    int fCalls;
};

<<<<<<< HEAD
DEF_TEST(RecordDraw_LazySaves, r)
{
=======
DEF_TEST(RecordDraw_LazySaves, r) {
>>>>>>> miniblink49
    // Record two commands.
    SkRecord record;
    SkRecorder recorder(&record, W, H);

    REPORTER_ASSERT(r, 0 == record.count());
    recorder.save();
<<<<<<< HEAD
    REPORTER_ASSERT(r, 0 == record.count()); // the save was not recorded (yet)
    recorder.drawColor(SK_ColorRED);
    REPORTER_ASSERT(r, 1 == record.count());
    recorder.scale(2, 2);
    REPORTER_ASSERT(r, 3 == record.count()); // now we see the save
=======
    REPORTER_ASSERT(r, 0 == record.count());    // the save was not recorded (yet)
    recorder.drawColor(SK_ColorRED);
    REPORTER_ASSERT(r, 1 == record.count());
    recorder.scale(2, 2);
    REPORTER_ASSERT(r, 3 == record.count());    // now we see the save
>>>>>>> miniblink49
    recorder.restore();
    REPORTER_ASSERT(r, 4 == record.count());

    assert_type<SkRecords::DrawPaint>(r, record, 0);
<<<<<<< HEAD
    assert_type<SkRecords::Save>(r, record, 1);
    assert_type<SkRecords::Concat>(r, record, 2);
    assert_type<SkRecords::Restore>(r, record, 3);
=======
    assert_type<SkRecords::Save>     (r, record, 1);
    assert_type<SkRecords::SetMatrix>(r, record, 2);
    assert_type<SkRecords::Restore>  (r, record, 3);
>>>>>>> miniblink49

    recorder.save();
    recorder.save();
    recorder.restore();
    recorder.restore();
    REPORTER_ASSERT(r, 4 == record.count());
}

<<<<<<< HEAD
DEF_TEST(RecordDraw_Abort, r)
{
=======
DEF_TEST(RecordDraw_Abort, r) {
>>>>>>> miniblink49
    // Record two commands.
    SkRecord record;
    SkRecorder recorder(&record, W, H);
    recorder.drawRect(SkRect::MakeWH(200, 300), SkPaint());
    recorder.clipRect(SkRect::MakeWH(100, 200));

    SkRecord rerecord;
    SkRecorder canvas(&rerecord, W, H);

    JustOneDraw callback;
<<<<<<< HEAD
    SkRecordDraw(record, &canvas, nullptr, nullptr, 0, nullptr /*bbh*/, &callback);
=======
    SkRecordDraw(record, &canvas, NULL, NULL, 0, NULL/*bbh*/, &callback);
>>>>>>> miniblink49

    REPORTER_ASSERT(r, 1 == count_instances_of_type<SkRecords::DrawRect>(rerecord));
    REPORTER_ASSERT(r, 0 == count_instances_of_type<SkRecords::ClipRect>(rerecord));
}

<<<<<<< HEAD
DEF_TEST(RecordDraw_Unbalanced, r)
{
    SkRecord record;
    SkRecorder recorder(&record, W, H);
    recorder.save(); // We won't balance this, but SkRecordDraw will for us.
=======
DEF_TEST(RecordDraw_Unbalanced, r) {
    SkRecord record;
    SkRecorder recorder(&record, W, H);
    recorder.save();  // We won't balance this, but SkRecordDraw will for us.
>>>>>>> miniblink49
    recorder.scale(2, 2);

    SkRecord rerecord;
    SkRecorder canvas(&rerecord, W, H);
<<<<<<< HEAD
    SkRecordDraw(record, &canvas, nullptr, nullptr, 0, nullptr /*bbh*/, nullptr /*callback*/);
=======
    SkRecordDraw(record, &canvas, NULL, NULL, 0, NULL/*bbh*/, NULL/*callback*/);
>>>>>>> miniblink49

    int save_count = count_instances_of_type<SkRecords::Save>(rerecord);
    int restore_count = count_instances_of_type<SkRecords::Save>(rerecord);
    REPORTER_ASSERT(r, save_count == restore_count);
}

<<<<<<< HEAD
DEF_TEST(RecordDraw_SetMatrixClobber, r)
{
=======
DEF_TEST(RecordDraw_SetMatrixClobber, r) {
>>>>>>> miniblink49
    // Set up an SkRecord that just scales by 2x,3x.
    SkRecord scaleRecord;
    SkRecorder scaleCanvas(&scaleRecord, W, H);
    SkMatrix scale;
    scale.setScale(2, 3);
    scaleCanvas.setMatrix(scale);

    // Set up an SkRecord with an initial +20, +20 translate.
    SkRecord translateRecord;
    SkRecorder translateCanvas(&translateRecord, W, H);
    SkMatrix translate;
    translate.setTranslate(20, 20);
    translateCanvas.setMatrix(translate);

<<<<<<< HEAD
    SkRecordDraw(scaleRecord, &translateCanvas, nullptr, nullptr, 0, nullptr /*bbh*/, nullptr /*callback*/);
    REPORTER_ASSERT(r, 4 == translateRecord.count());
    assert_type<SkRecords::SetMatrix>(r, translateRecord, 0);
    assert_type<SkRecords::Save>(r, translateRecord, 1);
    assert_type<SkRecords::SetMatrix>(r, translateRecord, 2);
    assert_type<SkRecords::Restore>(r, translateRecord, 3);
=======
    SkRecordDraw(scaleRecord, &translateCanvas, NULL, NULL, 0, NULL/*bbh*/, NULL/*callback*/);
    REPORTER_ASSERT(r, 4 == translateRecord.count());
    assert_type<SkRecords::SetMatrix>(r, translateRecord, 0);
    assert_type<SkRecords::Save>     (r, translateRecord, 1);
    assert_type<SkRecords::SetMatrix>(r, translateRecord, 2);
    assert_type<SkRecords::Restore>  (r, translateRecord, 3);
>>>>>>> miniblink49

    // When we look at translateRecord now, it should have its first +20,+20 translate,
    // then a 2x,3x scale that's been concatted with that +20,+20 translate.
    const SkRecords::SetMatrix* setMatrix;
    setMatrix = assert_type<SkRecords::SetMatrix>(r, translateRecord, 0);
    REPORTER_ASSERT(r, setMatrix->matrix == translate);

    setMatrix = assert_type<SkRecords::SetMatrix>(r, translateRecord, 2);
    SkMatrix expected = scale;
    expected.postConcat(translate);
    REPORTER_ASSERT(r, setMatrix->matrix == expected);
}

<<<<<<< HEAD
// Like a==b, with a little slop recognizing that float equality can be weird.
static bool sloppy_rect_eq(SkRect a, SkRect b)
{
=======
struct TestBBH : public SkBBoxHierarchy {
    void insert(const SkRect boundsArray[], int N) override {
        fEntries.setCount(N);
        for (int i = 0; i < N; i++) {
            Entry e = { (unsigned)i, boundsArray[i] };
            fEntries[i] = e;
        }
    }

    void search(const SkRect& query, SkTDArray<unsigned>* results) const override {}
    size_t bytesUsed() const override { return 0; }
    SkRect getRootBound() const override { return SkRect::MakeEmpty(); }

    struct Entry {
        unsigned opIndex;
        SkRect bounds;
    };
    SkTDArray<Entry> fEntries;
};

// Like a==b, with a little slop recognizing that float equality can be weird.
static bool sloppy_rect_eq(SkRect a, SkRect b) {
>>>>>>> miniblink49
    SkRect inset(a), outset(a);
    inset.inset(1, 1);
    outset.outset(1, 1);
    return outset.contains(b) && !inset.contains(b);
}

<<<<<<< HEAD
DEF_TEST(RecordDraw_BasicBounds, r)
{
    SkRecord record;
    SkRecorder recorder(&record, W, H);
    recorder.save();
    recorder.clipRect(SkRect::MakeWH(400, 500));
    recorder.scale(2, 2);
    recorder.drawRect(SkRect::MakeWH(320, 240), SkPaint());
    recorder.restore();

    SkAutoTMalloc<SkRect> bounds(record.count());
    SkRecordFillBounds(SkRect::MakeWH(SkIntToScalar(W), SkIntToScalar(H)), record, bounds);

    for (int i = 0; i < record.count(); i++) {
        REPORTER_ASSERT(r, sloppy_rect_eq(SkRect::MakeWH(400, 480), bounds[i]));
=======
// This test is not meant to make total sense yet.  It's testing the status quo
// of SkRecordFillBounds(), which itself doesn't make total sense yet.
DEF_TEST(RecordDraw_BBH, r) {
    SkRecord record;
    SkRecorder recorder(&record, W, H);
    recorder.save();
        recorder.clipRect(SkRect::MakeWH(400, 500));
        recorder.scale(2, 2);
        recorder.drawRect(SkRect::MakeWH(320, 240), SkPaint());
    recorder.restore();

    TestBBH bbh;
    SkRecordFillBounds(SkRect::MakeWH(SkIntToScalar(W), SkIntToScalar(H)), record, &bbh);

    REPORTER_ASSERT(r, bbh.fEntries.count() == 5);
    for (int i = 0; i < bbh.fEntries.count(); i++) {
        REPORTER_ASSERT(r, bbh.fEntries[i].opIndex == (unsigned)i);

        REPORTER_ASSERT(r, sloppy_rect_eq(SkRect::MakeWH(400, 480), bbh.fEntries[i].bounds));
>>>>>>> miniblink49
    }
}

// A regression test for crbug.com/409110.
<<<<<<< HEAD
DEF_TEST(RecordDraw_TextBounds, r)
{
=======
DEF_TEST(RecordDraw_TextBounds, r) {
>>>>>>> miniblink49
    SkRecord record;
    SkRecorder recorder(&record, W, H);

    // Two Chinese characters in UTF-8.
    const char text[] = { '\xe6', '\xbc', '\xa2', '\xe5', '\xad', '\x97' };
    const size_t bytes = SK_ARRAY_COUNT(text);

    const SkScalar xpos[] = { 10, 20 };
    recorder.drawPosTextH(text, bytes, xpos, 30, SkPaint());

<<<<<<< HEAD
    const SkPoint pos[] = { { 40, 50 }, { 60, 70 } };
    recorder.drawPosText(text, bytes, pos, SkPaint());

    SkAutoTMalloc<SkRect> bounds(record.count());
    SkRecordFillBounds(SkRect::MakeWH(SkIntToScalar(W), SkIntToScalar(H)), record, bounds);
=======
    const SkPoint pos[] = { {40, 50}, {60, 70} };
    recorder.drawPosText(text, bytes, pos, SkPaint());

    TestBBH bbh;
    SkRecordFillBounds(SkRect::MakeWH(SkIntToScalar(W), SkIntToScalar(H)), record, &bbh);
    REPORTER_ASSERT(r, bbh.fEntries.count() == 2);
>>>>>>> miniblink49

    // We can make these next assertions confidently because SkRecordFillBounds
    // builds its bounds by overestimating font metrics in a platform-independent way.
    // If that changes, these tests will need to be more flexible.
<<<<<<< HEAD
    REPORTER_ASSERT(r, sloppy_rect_eq(bounds[0], SkRect::MakeLTRB(0, 0, 140, 60)));
    REPORTER_ASSERT(r, sloppy_rect_eq(bounds[1], SkRect::MakeLTRB(0, 20, 180, 100)));
}

// Base test to ensure start/stop range is respected
DEF_TEST(RecordDraw_PartialStartStop, r)
{
    static const int kWidth = 10, kHeight = 10;

    SkRect r1 = { 0, 0, kWidth, kHeight };
    SkRect r2 = { 0, 0, kWidth, kHeight / 2 };
    SkRect r3 = { 0, 0, kWidth / 2, kHeight };
=======
    REPORTER_ASSERT(r, sloppy_rect_eq(bbh.fEntries[0].bounds, SkRect::MakeLTRB(0,  0, 140, 60)));
    REPORTER_ASSERT(r, sloppy_rect_eq(bbh.fEntries[1].bounds, SkRect::MakeLTRB(0, 20, 180, 100)));
}

// Base test to ensure start/stop range is respected
DEF_TEST(RecordDraw_PartialStartStop, r) {
    static const int kWidth = 10, kHeight = 10;

    SkRect r1 = { 0, 0, kWidth,   kHeight };
    SkRect r2 = { 0, 0, kWidth,   kHeight/2 };
    SkRect r3 = { 0, 0, kWidth/2, kHeight };
>>>>>>> miniblink49
    SkPaint p;

    SkRecord record;
    SkRecorder recorder(&record, kWidth, kHeight);
    recorder.drawRect(r1, p);
    recorder.drawRect(r2, p);
    recorder.drawRect(r3, p);

    SkRecord rerecord;
    SkRecorder canvas(&rerecord, kWidth, kHeight);
<<<<<<< HEAD
    SkRecordPartialDraw(record, &canvas, nullptr, 0, 1, 2, SkMatrix::I()); // replay just drawRect of r2
=======
    SkRecordPartialDraw(record, &canvas, NULL, 0, 1, 2, SkMatrix::I()); // replay just drawRect of r2
>>>>>>> miniblink49

    REPORTER_ASSERT(r, 1 == count_instances_of_type<SkRecords::DrawRect>(rerecord));
    int index = find_first_instances_of_type<SkRecords::DrawRect>(rerecord);
    const SkRecords::DrawRect* drawRect = assert_type<SkRecords::DrawRect>(r, rerecord, index);
    REPORTER_ASSERT(r, drawRect->rect == r2);
}

<<<<<<< HEAD
// A regression test for crbug.com/415468 and https://bug.skia.org/2957 .
=======
// A regression test for crbug.com/415468 and skbug.com/2957.
>>>>>>> miniblink49
//
// This also now serves as a regression test for crbug.com/418417.  We used to adjust the
// bounds for the saveLayer, clip, and restore to be greater than the bounds of the picture.
// (We were applying the saveLayer paint to the bounds after restore, which makes no sense.)
<<<<<<< HEAD
DEF_TEST(RecordDraw_SaveLayerAffectsClipBounds, r)
{
=======
DEF_TEST(RecordDraw_SaveLayerAffectsClipBounds, r) {
>>>>>>> miniblink49
    SkRecord record;
    SkRecorder recorder(&record, 50, 50);

    // We draw a rectangle with a long drop shadow.  We used to not update the clip
    // bounds based on SaveLayer paints, so the drop shadow could be cut off.
    SkPaint paint;
<<<<<<< HEAD
    paint.setImageFilter(SkDropShadowImageFilter::Make(
        20, 0, 0, 0, SK_ColorBLACK,
        SkDropShadowImageFilter::kDrawShadowAndForeground_ShadowMode,
        nullptr));

    recorder.saveLayer(nullptr, &paint);
    recorder.clipRect(SkRect::MakeWH(20, 40));
    recorder.drawRect(SkRect::MakeWH(20, 40), SkPaint());
=======
    paint.setImageFilter(SkDropShadowImageFilter::Create(20, 0, 0, 0, SK_ColorBLACK,
                         SkDropShadowImageFilter::kDrawShadowAndForeground_ShadowMode))->unref();

    recorder.saveLayer(NULL, &paint);
        recorder.clipRect(SkRect::MakeWH(20, 40));
        recorder.drawRect(SkRect::MakeWH(20, 40), SkPaint());
>>>>>>> miniblink49
    recorder.restore();

    // Under the original bug, the right edge value of the drawRect would be 20 less than asserted
    // here because we intersected it with a clip that had not been adjusted for the drop shadow.
    //
    // The second bug showed up as adjusting the picture bounds (0,0,50,50) by the drop shadow too.
    // The saveLayer, clipRect, and restore bounds were incorrectly (0,0,70,50).
<<<<<<< HEAD
    SkAutoTMalloc<SkRect> bounds(record.count());
    SkRecordFillBounds(SkRect::MakeWH(50, 50), record, bounds);
    REPORTER_ASSERT(r, sloppy_rect_eq(bounds[0], SkRect::MakeLTRB(0, 0, 50, 50)));
    REPORTER_ASSERT(r, sloppy_rect_eq(bounds[1], SkRect::MakeLTRB(0, 0, 50, 50)));
    REPORTER_ASSERT(r, sloppy_rect_eq(bounds[2], SkRect::MakeLTRB(0, 0, 40, 40)));
    REPORTER_ASSERT(r, sloppy_rect_eq(bounds[3], SkRect::MakeLTRB(0, 0, 50, 50)));
=======
    TestBBH bbh;
    SkRecordFillBounds(SkRect::MakeWH(50, 50), record, &bbh);
    REPORTER_ASSERT(r, bbh.fEntries.count() == 4);
    REPORTER_ASSERT(r, sloppy_rect_eq(bbh.fEntries[0].bounds, SkRect::MakeLTRB(0, 0, 50, 50)));
    REPORTER_ASSERT(r, sloppy_rect_eq(bbh.fEntries[1].bounds, SkRect::MakeLTRB(0, 0, 50, 50)));
    REPORTER_ASSERT(r, sloppy_rect_eq(bbh.fEntries[2].bounds, SkRect::MakeLTRB(0, 0, 40, 40)));
    REPORTER_ASSERT(r, sloppy_rect_eq(bbh.fEntries[3].bounds, SkRect::MakeLTRB(0, 0, 50, 50)));
>>>>>>> miniblink49
}

// When a saveLayer provides an explicit bound and has a complex paint (e.g., one that
// affects transparent black), that bound should serve to shrink the area of the required
// backing store.
<<<<<<< HEAD
DEF_TEST(RecordDraw_SaveLayerBoundsAffectsClipBounds, r)
{
=======
DEF_TEST(RecordDraw_SaveLayerBoundsAffectsClipBounds, r) {
>>>>>>> miniblink49
    SkRecord record;
    SkRecorder recorder(&record, 50, 50);

    SkPaint p;
    p.setXfermodeMode(SkXfermode::kSrc_Mode);

<<<<<<< HEAD
    SkRect layerBounds = SkRect::MakeLTRB(10, 10, 40, 40);
    recorder.saveLayer(&layerBounds, &p);
    recorder.drawRect(SkRect::MakeLTRB(20, 20, 30, 30), SkPaint());
    recorder.restore();

    SkAutoTMalloc<SkRect> bounds(record.count());
    SkRecordFillBounds(SkRect::MakeWH(50, 50), record, bounds);
    if (!SkCanvas::Internal_Private_GetIgnoreSaveLayerBounds()) {
        REPORTER_ASSERT(r, sloppy_rect_eq(bounds[0], SkRect::MakeLTRB(10, 10, 40, 40)));
        REPORTER_ASSERT(r, sloppy_rect_eq(bounds[1], SkRect::MakeLTRB(20, 20, 30, 30)));
        REPORTER_ASSERT(r, sloppy_rect_eq(bounds[2], SkRect::MakeLTRB(10, 10, 40, 40)));
    }
}

DEF_TEST(RecordDraw_drawImage, r)
{
    class SkCanvasMock : public SkCanvas {
    public:
        SkCanvasMock(int width, int height)
            : SkCanvas(width, height)
        {
=======
    SkRect bounds = SkRect::MakeLTRB(10, 10, 40, 40);
    recorder.saveLayer(&bounds, &p);
    recorder.drawRect(SkRect::MakeLTRB(20, 20, 30, 30), SkPaint());
    recorder.restore();

    TestBBH bbh;
    SkRecordFillBounds(SkRect::MakeWH(50, 50), record, &bbh);
    REPORTER_ASSERT(r, bbh.fEntries.count() == 3);
    if (!SkCanvas::Internal_Private_GetIgnoreSaveLayerBounds()) {
        REPORTER_ASSERT(r, sloppy_rect_eq(bbh.fEntries[0].bounds, SkRect::MakeLTRB(10, 10, 40, 40)));
        REPORTER_ASSERT(r, sloppy_rect_eq(bbh.fEntries[1].bounds, SkRect::MakeLTRB(20, 20, 30, 30)));
        REPORTER_ASSERT(r, sloppy_rect_eq(bbh.fEntries[2].bounds, SkRect::MakeLTRB(10, 10, 40, 40)));
    }
}

DEF_TEST(RecordDraw_drawImage, r){
    class SkCanvasMock : public SkCanvas {
    public:
        SkCanvasMock(int width, int height) : SkCanvas(width, height) {
>>>>>>> miniblink49
            this->resetTestValues();
        }

        void onDrawImage(const SkImage* image, SkScalar left, SkScalar top,
<<<<<<< HEAD
            const SkPaint* paint) override
        {
=======
                         const SkPaint* paint) override {
>>>>>>> miniblink49
            fDrawImageCalled = true;
        }

        void onDrawImageRect(const SkImage* image, const SkRect* src, const SkRect& dst,
<<<<<<< HEAD
            const SkPaint* paint, SrcRectConstraint) override
        {
            fDrawImageRectCalled = true;
        }

        void resetTestValues()
        {
=======
                             const SkPaint* paint) override {
            fDrawImageRectCalled = true;
        }

        void resetTestValues() {
>>>>>>> miniblink49
            fDrawImageCalled = fDrawImageRectCalled = false;
        }

        bool fDrawImageCalled;
        bool fDrawImageRectCalled;
    };

<<<<<<< HEAD
    auto surface(SkSurface::MakeRasterN32Premul(10, 10));
    surface->getCanvas()->clear(SK_ColorGREEN);
    sk_sp<SkImage> image(surface->makeImageSnapshot());
=======
    SkAutoTUnref<SkSurface> surface(SkSurface::NewRasterN32Premul(10, 10));
    surface->getCanvas()->clear(SK_ColorGREEN);
    SkAutoTUnref<SkImage> image(surface->newImageSnapshot());
>>>>>>> miniblink49

    SkCanvasMock canvas(10, 10);

    {
        SkRecord record;
        SkRecorder recorder(&record, 10, 10);
        recorder.drawImage(image, 0, 0);
<<<<<<< HEAD
        SkRecordDraw(record, &canvas, nullptr, nullptr, 0, nullptr, 0);
=======
        SkRecordDraw(record, &canvas, NULL, NULL, 0, NULL, 0);
>>>>>>> miniblink49
    }
    REPORTER_ASSERT(r, canvas.fDrawImageCalled);
    canvas.resetTestValues();

    {
        SkRecord record;
        SkRecorder recorder(&record, 10, 10);
<<<<<<< HEAD
        recorder.drawImageRect(image, SkRect::MakeWH(10, 10), nullptr);
        SkRecordDraw(record, &canvas, nullptr, nullptr, 0, nullptr, 0);
    }
    REPORTER_ASSERT(r, canvas.fDrawImageRectCalled);
=======
        recorder.drawImageRect(image, 0, SkRect::MakeWH(10, 10));
        SkRecordDraw(record, &canvas, NULL, NULL, 0, NULL, 0);
    }
    REPORTER_ASSERT(r, canvas.fDrawImageRectCalled);

>>>>>>> miniblink49
}
