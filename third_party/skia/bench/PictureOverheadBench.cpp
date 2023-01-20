/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

// A benchmark designed to isolate the constant overheads of picture recording.
// We record an empty picture and a picture with one draw op to force memory allocation.

#include "Benchmark.h"
#include "SkCanvas.h"
#include "SkPictureRecorder.h"

template <bool kDraw>
struct PictureOverheadBench : public Benchmark {
<<<<<<< HEAD
    const char* onGetName() override
    {
=======
    const char* onGetName() override {
>>>>>>> miniblink49
        return kDraw ? "picture_overhead_draw" : "picture_overhead_nodraw";
    }
    bool isSuitableFor(Backend backend) override { return backend == kNonRendering_Backend; }

<<<<<<< HEAD
    void onDraw(int loops, SkCanvas*) override
    {
        SkPictureRecorder rec;
        for (int i = 0; i < loops; i++) {
            rec.beginRecording(SkRect::MakeWH(2000, 3000));
            if (kDraw) {
                rec.getRecordingCanvas()->drawRect(SkRect::MakeXYWH(10, 10, 1000, 1000), SkPaint());
            }
            (void)rec.finishRecordingAsPicture();
=======
    void onDraw(const int loops, SkCanvas*) override {
        SkPictureRecorder rec;
        for (int i = 0; i < loops; i++) {
            rec.beginRecording(SkRect::MakeWH(2000,3000));
            if (kDraw) {
                rec.getRecordingCanvas()->drawRect(SkRect::MakeXYWH(10, 10, 1000, 1000), SkPaint());
            }
            SkAutoTUnref<SkPicture> pic(rec.endRecordingAsPicture());
>>>>>>> miniblink49
        }
    }
};

DEF_BENCH(return (new PictureOverheadBench<false>);)
<<<<<<< HEAD
DEF_BENCH(return (new PictureOverheadBench<true>);)
=======
DEF_BENCH(return (new PictureOverheadBench< true>);)
>>>>>>> miniblink49
