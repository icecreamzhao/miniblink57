/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkBitmap.h"
#include "SkCanvas.h"
#include "SkDumpCanvas.h"
#include "SkGraphics.h"
#include "SkOSFile.h"
#include "SkPicture.h"
#include "SkStream.h"
#include "SkString.h"

static sk_sp<SkPicture> inspect(const char path[])
{
    SkFILEStream stream(path);
    if (!stream.isValid()) {
        printf("-- Can't open '%s'\n", path);
        return nullptr;
=======
#include "LazyDecodeBitmap.h"
#include "SkBitmap.h"
#include "SkCanvas.h"
#include "SkGraphics.h"
#include "SkOSFile.h"
#include "SkImageDecoder.h"
#include "SkPicture.h"
#include "SkStream.h"
#include "SkString.h"
#include "SkDumpCanvas.h"

static SkPicture* inspect(const char path[]) {
    SkFILEStream stream(path);
    if (!stream.isValid()) {
        printf("-- Can't open '%s'\n", path);
        return NULL;
>>>>>>> miniblink49
    }

    printf("Opening '%s'...\n", path);

    {
        int32_t header[3];
        if (stream.read(header, sizeof(header)) != sizeof(header)) {
            printf("-- Failed to read header (12 bytes)\n");
<<<<<<< HEAD
            return nullptr;
=======
            return NULL;
>>>>>>> miniblink49
        }
        printf("version:%d width:%d height:%d\n", header[0], header[1], header[2]);
    }

    stream.rewind();
<<<<<<< HEAD
    auto pic = SkPicture::MakeFromStream(&stream);
    if (nullptr == pic) {
        SkDebugf("Could not create SkPicture: %s\n", path);
        return nullptr;
    }
    printf("picture cullRect: [%f %f %f %f]\n",
        pic->cullRect().fLeft, pic->cullRect().fTop,
        pic->cullRect().fRight, pic->cullRect().fBottom);
    return pic;
}

static void dumpOps(SkPicture* pic)
{
#ifdef SK_DEBUG
=======
    SkPicture* pic = SkPicture::CreateFromStream(&stream, &sk_tools::LazyDecodeBitmap);
    if (NULL == pic) {
        SkDebugf("Could not create SkPicture: %s\n", path);
        return NULL;
    }
    printf("picture cullRect: [%f %f %f %f]\n", 
           pic->cullRect().fLeft, pic->cullRect().fTop,
           pic->cullRect().fRight, pic->cullRect().fBottom);
    return pic;
}

static void dumpOps(SkPicture* pic) {
#ifdef SK_DEVELOPER
>>>>>>> miniblink49
    SkDebugfDumper dumper;
    SkDumpCanvas canvas(&dumper);
    canvas.drawPicture(pic);
#else
<<<<<<< HEAD
    printf("SK_DEBUG mode not enabled\n");
=======
    printf("SK_DEVELOPER mode not enabled\n");
>>>>>>> miniblink49
#endif
}

int tool_main(int argc, char** argv);
<<<<<<< HEAD
int tool_main(int argc, char** argv)
{
=======
int tool_main(int argc, char** argv) {
>>>>>>> miniblink49
    SkAutoGraphics ag;
    if (argc < 2) {
        printf("Usage: pinspect [--dump-ops] filename [filename ...]\n");
        return 1;
    }

    bool doDumpOps = false;

    int index = 1;
    if (!strcmp(argv[index], "--dump-ops")) {
        index += 1;
        doDumpOps = true;
    }

    for (; index < argc; ++index) {
<<<<<<< HEAD
        auto pic(inspect(argv[index]));
        if (doDumpOps) {
            dumpOps(pic.get());
=======
        SkAutoTUnref<SkPicture> pic(inspect(argv[index]));
        if (doDumpOps) {
            dumpOps(pic);
>>>>>>> miniblink49
        }
        if (index < argc - 1) {
            printf("\n");
        }
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
