/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "Resources.h"
<<<<<<< HEAD
#include "SkBitmap.h"
#include "SkCodec.h"
#include "SkOSFile.h"
#include "SkStream.h"
#include "Test.h"

DEF_TEST(BadImage, reporter)
{
    const char* const badImages[] = {
=======
#include "Test.h"
#include "SkBitmap.h"
#include "SkImageDecoder.h"
#include "SkOSFile.h"

DEF_TEST(BadIco, reporter) {
    const char* const badIcos [] = {
>>>>>>> miniblink49
        "sigabort_favicon.ico",
        "sigsegv_favicon.ico",
        "sigsegv_favicon_2.ico",
        "ico_leak01.ico",
        "ico_fuzz0.ico",
<<<<<<< HEAD
        "ico_fuzz1.ico",
        "skbug3442.webp",
        "skbug3429.webp",
    };

    const char* badImagesFolder = "invalid_images";

    SkString resourcePath = GetResourcePath(badImagesFolder);

    for (size_t i = 0; i < SK_ARRAY_COUNT(badImages); ++i) {
        SkString fullPath = SkOSPath::Join(resourcePath.c_str(), badImages[i]);
        SkAutoTDelete<SkStream> stream(SkStream::NewFromFile(fullPath.c_str()));
        SkAutoTDelete<SkCodec> codec(SkCodec::NewFromStream(stream.release()));

        // These images are corrupt.  It's not important whether we succeed/fail in codec
        // creation or decoding.  We just want to make sure that we don't crash.
        if (codec) {
            SkBitmap bm;
            bm.allocPixels(codec->getInfo());
            codec->getPixels(codec->getInfo(), bm.getPixels(),
                bm.rowBytes());
        }
=======
        "ico_fuzz1.ico"
    };

    const char* badIcoFolder = "invalid_images";

    SkString resourcePath = GetResourcePath(badIcoFolder);

    SkBitmap bm;
    for (size_t i = 0; i < SK_ARRAY_COUNT(badIcos); ++i) {
        SkString fullPath = SkOSPath::Join(resourcePath.c_str(), badIcos[i]);
        bool success = SkImageDecoder::DecodeFile(fullPath.c_str(), &bm);
        // These files are invalid, and should not decode. More importantly,
        // though, we reached here without crashing.
        REPORTER_ASSERT(reporter, !success);
>>>>>>> miniblink49
    }
}
