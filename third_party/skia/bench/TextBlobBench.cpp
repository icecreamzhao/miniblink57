<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "Benchmark.h"
#include "Resources.h"
#include "SkCanvas.h"
#include "SkPaint.h"
#include "SkRandom.h"
#include "SkStream.h"
#include "SkString.h"
#include "SkTemplates.h"
#include "SkTextBlob.h"
#include "SkTypeface.h"

#include "sk_tool_utils.h"

/*
 * A trivial test which benchmarks the performance of a textblob with a single run.
 */
class TextBlobBench : public Benchmark {
public:
<<<<<<< HEAD
    TextBlobBench() { }

protected:
    void onDelayedSetup() override
    {
        fTypeface = sk_tool_utils::create_portable_typeface("serif", SkFontStyle());
=======
    TextBlobBench()
        : fTypeface(NULL) {
    }

protected:
    void onPreDraw() override {
        fTypeface.reset(sk_tool_utils::create_portable_typeface("Times", SkTypeface::kNormal));
>>>>>>> miniblink49
        // make textblob
        SkPaint paint;
        paint.setTypeface(fTypeface);
        const char* text = "Hello blob!";
        SkTDArray<uint16_t> glyphs;
        size_t len = strlen(text);
<<<<<<< HEAD
        glyphs.append(paint.textToGlyphs(text, len, nullptr));
=======
        glyphs.append(paint.textToGlyphs(text, len, NULL));
>>>>>>> miniblink49
        paint.textToGlyphs(text, len, glyphs.begin());

        SkTextBlobBuilder builder;

        paint.setTextEncoding(SkPaint::kGlyphID_TextEncoding);
        const SkTextBlobBuilder::RunBuffer& run = builder.allocRun(paint, glyphs.count(), 10, 10,
<<<<<<< HEAD
            nullptr);
=======
                                                                   NULL);
>>>>>>> miniblink49
        memcpy(run.glyphs, glyphs.begin(), glyphs.count() * sizeof(uint16_t));

        fBlob.reset(builder.build());
    }

<<<<<<< HEAD
    const char* onGetName() override
    {
        return "TextBlobBench";
    }

    void onDraw(int loops, SkCanvas* canvas) override
    {
=======
    const char* onGetName() {
        return "TextBlobBench";
    }

    void onDraw(const int loops, SkCanvas* canvas) {
>>>>>>> miniblink49
        SkPaint paint;

        // To ensure maximum caching, we just redraw the blob at the same place everytime
        for (int i = 0; i < loops; i++) {
            canvas->drawTextBlob(fBlob, 0, 0, paint);
        }
    }

private:
<<<<<<< HEAD
    SkAutoTUnref<const SkTextBlob> fBlob;
    SkTDArray<uint16_t> fGlyphs;
    sk_sp<SkTypeface> fTypeface;
=======

    SkAutoTUnref<const SkTextBlob> fBlob;
    SkTDArray<uint16_t>      fGlyphs;
    SkAutoTUnref<SkTypeface> fTypeface;
>>>>>>> miniblink49

    typedef Benchmark INHERITED;
};

<<<<<<< HEAD
DEF_BENCH(return new TextBlobBench();)
=======
DEF_BENCH( return new TextBlobBench(); )
>>>>>>> miniblink49
