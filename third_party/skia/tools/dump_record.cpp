/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "DumpRecord.h"
#include "SkCommandLineFlags.h"
#include "SkPicture.h"
#include "SkPictureRecorder.h"
#include "SkRecordDraw.h"
#include "SkRecordOpts.h"
#include "SkRecorder.h"
#include "SkStream.h"
#include <stdio.h>
=======
#include <stdio.h>

#include "SkCommandLineFlags.h"
#include "SkGraphics.h"
#include "SkPicture.h"
#include "SkRecordOpts.h"
#include "SkRecorder.h"
#include "SkStream.h"

#include "DumpRecord.h"
#include "LazyDecodeBitmap.h"
>>>>>>> miniblink49

DEFINE_string2(skps, r, "", ".SKPs to dump.");
DEFINE_string(match, "", "The usual filters on file names to dump.");
DEFINE_bool2(optimize, O, false, "Run SkRecordOptimize before dumping.");
<<<<<<< HEAD
DEFINE_bool(optimize2, false, "Run SkRecordOptimize2 before dumping.");
DEFINE_int32(tile, 1000000000, "Simulated tile size.");
DEFINE_bool(timeWithCommand, false, "If true, print time next to command, else in first column.");
DEFINE_string2(write, w, "", "Write the (optimized) picture to the named file.");

static void dump(const char* name, int w, int h, const SkRecord& record)
{
=======
DEFINE_int32(tile, 1000000000, "Simulated tile size.");
DEFINE_bool(timeWithCommand, false, "If true, print time next to command, else in first column.");

static void dump(const char* name, int w, int h, const SkRecord& record) {
>>>>>>> miniblink49
    SkBitmap bitmap;
    bitmap.allocN32Pixels(w, h);
    SkCanvas canvas(bitmap);
    canvas.clipRect(SkRect::MakeWH(SkIntToScalar(FLAGS_tile),
<<<<<<< HEAD
        SkIntToScalar(FLAGS_tile)));
=======
                                   SkIntToScalar(FLAGS_tile)));
>>>>>>> miniblink49

    printf("%s %s\n", FLAGS_optimize ? "optimized" : "not-optimized", name);

    DumpRecord(record, &canvas, FLAGS_timeWithCommand);
}

<<<<<<< HEAD
int tool_main(int argc, char** argv);
int tool_main(int argc, char** argv)
{
    SkCommandLineFlags::Parse(argc, argv);
=======

int tool_main(int argc, char** argv);
int tool_main(int argc, char** argv) {
    SkCommandLineFlags::Parse(argc, argv);
    SkAutoGraphics ag;
>>>>>>> miniblink49

    for (int i = 0; i < FLAGS_skps.count(); i++) {
        if (SkCommandLineFlags::ShouldSkip(FLAGS_match, FLAGS_skps[i])) {
            continue;
        }

        SkAutoTDelete<SkStream> stream(SkStream::NewFromFile(FLAGS_skps[i]));
        if (!stream) {
            SkDebugf("Could not read %s.\n", FLAGS_skps[i]);
<<<<<<< HEAD
            return 1;
        }
        sk_sp<SkPicture> src(SkPicture::MakeFromStream(stream));
        if (!src) {
            SkDebugf("Could not read %s as an SkPicture.\n", FLAGS_skps[i]);
            return 1;
=======
            exit(1);
        }
        SkAutoTUnref<SkPicture> src(
                SkPicture::CreateFromStream(stream, sk_tools::LazyDecodeBitmap));
        if (!src) {
            SkDebugf("Could not read %s as an SkPicture.\n", FLAGS_skps[i]);
            exit(1);
>>>>>>> miniblink49
        }
        const int w = SkScalarCeilToInt(src->cullRect().width());
        const int h = SkScalarCeilToInt(src->cullRect().height());

        SkRecord record;
        SkRecorder canvas(&record, w, h);
        src->playback(&canvas);

        if (FLAGS_optimize) {
            SkRecordOptimize(&record);
        }
<<<<<<< HEAD
        if (FLAGS_optimize2) {
            SkRecordOptimize2(&record);
        }

        dump(FLAGS_skps[i], w, h, record);

        if (FLAGS_write.count() > 0) {
            SkPictureRecorder r;
            SkRecordDraw(record,
                r.beginRecording(SkRect::MakeIWH(w, h)),
                nullptr,
                nullptr,
                0,
                nullptr,
                nullptr);
            sk_sp<SkPicture> dst(r.finishRecordingAsPicture());
            SkFILEWStream ostream(FLAGS_write[0]);
            dst->serialize(&ostream);
        }
=======

        dump(FLAGS_skps[i], w, h, record);
>>>>>>> miniblink49
    }

    return 0;
}

#if !defined SK_BUILD_FOR_IOS
<<<<<<< HEAD
int main(int argc, char* const argv[])
{
    return tool_main(argc, (char**)argv);
=======
int main(int argc, char * const argv[]) {
    return tool_main(argc, (char**) argv);
>>>>>>> miniblink49
}
#endif
