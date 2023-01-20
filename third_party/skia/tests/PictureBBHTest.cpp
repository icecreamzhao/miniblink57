/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkBBoxHierarchy.h"
#include "SkCanvas.h"
=======
#include "SkCanvas.h"
#include "SkBBoxHierarchy.h"
>>>>>>> miniblink49
#include "SkPaint.h"
#include "SkPicture.h"
#include "SkPictureRecorder.h"

#include "Test.h"

class PictureBBHTestBase {
public:
    PictureBBHTestBase(int playbackWidth, int playbackHeight,
<<<<<<< HEAD
        int recordWidth, int recordHeight)
    {
=======
        int recordWidth, int recordHeight) {
>>>>>>> miniblink49

        fResultBitmap.allocN32Pixels(playbackWidth, playbackHeight);
        fPictureWidth = recordWidth;
        fPictureHeight = recordHeight;
    }

    virtual ~PictureBBHTestBase() { }

    virtual void doTest(SkCanvas& playbackCanvas, SkCanvas& recordingCanvas) = 0;

<<<<<<< HEAD
    void run(skiatest::Reporter* reporter)
    {
        // No BBH
        this->run(nullptr, reporter);
=======
    void run(skiatest::Reporter* reporter) {
        // No BBH
        this->run(NULL, reporter);
>>>>>>> miniblink49

        // With an R-Tree
        SkRTreeFactory RTreeFactory;
        this->run(&RTreeFactory, reporter);
    }

private:
<<<<<<< HEAD
    void run(SkBBHFactory* factory, skiatest::Reporter* reporter)
    {
=======
    void run(SkBBHFactory* factory, skiatest::Reporter* reporter) {
>>>>>>> miniblink49
        SkCanvas playbackCanvas(fResultBitmap);
        playbackCanvas.clear(SK_ColorGREEN);
        SkPictureRecorder recorder;
        SkCanvas* recordCanvas = recorder.beginRecording(SkIntToScalar(fPictureWidth),
<<<<<<< HEAD
            SkIntToScalar(fPictureHeight),
            factory);
        this->doTest(playbackCanvas, *recordCanvas);
        sk_sp<SkPicture> picture(recorder.finishRecordingAsPicture());
=======
                                                         SkIntToScalar(fPictureHeight),
                                                         factory);
        this->doTest(playbackCanvas, *recordCanvas);
        SkAutoTUnref<SkPicture> picture(recorder.endRecording());
>>>>>>> miniblink49
        playbackCanvas.drawPicture(picture);
        REPORTER_ASSERT(reporter, SK_ColorGREEN == fResultBitmap.getColor(0, 0));
    }

    SkBitmap fResultBitmap;
    int fPictureWidth, fPictureHeight;
};

// Test to verify the playback of an empty picture
//
class DrawEmptyPictureBBHTest : public PictureBBHTestBase {
public:
    DrawEmptyPictureBBHTest()
<<<<<<< HEAD
        : PictureBBHTestBase(2, 2, 1, 1)
    {
    }
=======
        : PictureBBHTestBase(2, 2, 1, 1) { }
>>>>>>> miniblink49
    virtual ~DrawEmptyPictureBBHTest() { }

    void doTest(SkCanvas&, SkCanvas&) override { }
};

// Test to verify the playback of a picture into a canvas that has
// an empty clip.
//
class EmptyClipPictureBBHTest : public PictureBBHTestBase {
public:
    EmptyClipPictureBBHTest()
<<<<<<< HEAD
        : PictureBBHTestBase(2, 2, 3, 3)
    {
    }

    void doTest(SkCanvas& playbackCanvas, SkCanvas& recordingCanvas) override
    {
        // intersect with out of bounds rect -> empty clip.
        playbackCanvas.clipRect(SkRect::MakeXYWH(SkIntToScalar(10), SkIntToScalar(10),
                                    SkIntToScalar(1), SkIntToScalar(1)),
            SkRegion::kIntersect_Op);
        SkPaint paint;
        recordingCanvas.drawRect(SkRect::MakeXYWH(SkIntToScalar(0), SkIntToScalar(0),
                                     SkIntToScalar(3), SkIntToScalar(3)),
            paint);
=======
        : PictureBBHTestBase(2, 2, 3, 3) { }

    void doTest(SkCanvas& playbackCanvas, SkCanvas& recordingCanvas) override {
        // intersect with out of bounds rect -> empty clip.
        playbackCanvas.clipRect(SkRect::MakeXYWH(SkIntToScalar(10), SkIntToScalar(10),
            SkIntToScalar(1), SkIntToScalar(1)), SkRegion::kIntersect_Op);
        SkPaint paint;
        recordingCanvas.drawRect(SkRect::MakeXYWH(SkIntToScalar(0), SkIntToScalar(0),
            SkIntToScalar(3), SkIntToScalar(3)), paint);
>>>>>>> miniblink49
    }

    virtual ~EmptyClipPictureBBHTest() { }
};

<<<<<<< HEAD
DEF_TEST(PictureBBH, reporter)
{
=======
DEF_TEST(PictureBBH, reporter) {
>>>>>>> miniblink49

    DrawEmptyPictureBBHTest emptyPictureTest;
    emptyPictureTest.run(reporter);

    EmptyClipPictureBBHTest emptyClipPictureTest;
    emptyClipPictureTest.run(reporter);
}
