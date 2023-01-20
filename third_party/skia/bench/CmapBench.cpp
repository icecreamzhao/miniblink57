/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "Benchmark.h"
#include "SkCanvas.h"
#include "SkPaint.h"
#include "SkTypeface.h"

enum {
    NGLYPHS = 100
};

<<<<<<< HEAD
static SkTypeface::Encoding paint2Encoding(const SkPaint& paint)
{
=======
static SkTypeface::Encoding paint2Encoding(const SkPaint& paint) {
>>>>>>> miniblink49
    SkPaint::TextEncoding enc = paint.getTextEncoding();
    SkASSERT(SkPaint::kGlyphID_TextEncoding != enc);
    return (SkTypeface::Encoding)enc;
}

typedef void (*TypefaceProc)(int loops, const SkPaint&, const void* text, size_t len,
<<<<<<< HEAD
    int glyphCount);

static void containsText_proc(int loops, const SkPaint& paint, const void* text, size_t len,
    int glyphCount)
{
=======
                             int glyphCount);

static void containsText_proc(int loops, const SkPaint& paint, const void* text, size_t len,
                              int glyphCount) {
>>>>>>> miniblink49
    for (int i = 0; i < loops; ++i) {
        paint.containsText(text, len);
    }
}

static void textToGlyphs_proc(int loops, const SkPaint& paint, const void* text, size_t len,
<<<<<<< HEAD
    int glyphCount)
{
=======
                              int glyphCount) {
>>>>>>> miniblink49
    uint16_t glyphs[NGLYPHS];
    SkASSERT(glyphCount <= NGLYPHS);

    for (int i = 0; i < loops; ++i) {
        paint.textToGlyphs(text, len, glyphs);
    }
}

static void charsToGlyphs_proc(int loops, const SkPaint& paint, const void* text,
<<<<<<< HEAD
    size_t len, int glyphCount)
{
=======
                               size_t len, int glyphCount) {
>>>>>>> miniblink49
    SkTypeface::Encoding encoding = paint2Encoding(paint);
    uint16_t glyphs[NGLYPHS];
    SkASSERT(glyphCount <= NGLYPHS);

    SkTypeface* face = paint.getTypeface();
    for (int i = 0; i < loops; ++i) {
        face->charsToGlyphs(text, encoding, glyphs, glyphCount);
    }
}

static void charsToGlyphsNull_proc(int loops, const SkPaint& paint, const void* text,
<<<<<<< HEAD
    size_t len, int glyphCount)
{
=======
                                   size_t len, int glyphCount) {
>>>>>>> miniblink49
    SkTypeface::Encoding encoding = paint2Encoding(paint);

    SkTypeface* face = paint.getTypeface();
    for (int i = 0; i < loops; ++i) {
<<<<<<< HEAD
        face->charsToGlyphs(text, encoding, nullptr, glyphCount);
=======
        face->charsToGlyphs(text, encoding, NULL, glyphCount);
>>>>>>> miniblink49
    }
}

class CMAPBench : public Benchmark {
    TypefaceProc fProc;
<<<<<<< HEAD
    SkString fName;
    char fText[NGLYPHS];
    SkPaint fPaint;

public:
    CMAPBench(TypefaceProc proc, const char name[])
    {
=======
    SkString     fName;
    char         fText[NGLYPHS];
    SkPaint      fPaint;

public:
    CMAPBench(TypefaceProc proc, const char name[]) {
>>>>>>> miniblink49
        fProc = proc;
        fName.printf("cmap_%s", name);

        for (int i = 0; i < NGLYPHS; ++i) {
            // we're jamming values into utf8, so we must keep it legal utf8
            fText[i] = 'A' + (i & 31);
        }
<<<<<<< HEAD
        fPaint.setTypeface(SkTypeface::MakeDefault());
    }

protected:
    const char* onGetName() override
    {
        return fName.c_str();
    }

    void onDraw(int loops, SkCanvas* canvas) override
    {
=======
        fPaint.setTypeface(SkTypeface::RefDefault())->unref();
    }

protected:
    const char* onGetName() override {
        return fName.c_str();
    }

    void onDraw(const int loops, SkCanvas* canvas) override {
>>>>>>> miniblink49
        fProc(loops, fPaint, fText, sizeof(fText), NGLYPHS);
    }

private:
<<<<<<< HEAD
=======

>>>>>>> miniblink49
    typedef Benchmark INHERITED;
};

//////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
DEF_BENCH(return new CMAPBench(containsText_proc, "paint_containsText");)
DEF_BENCH(return new CMAPBench(textToGlyphs_proc, "paint_textToGlyphs");)
DEF_BENCH(return new CMAPBench(charsToGlyphs_proc, "face_charsToGlyphs");)
DEF_BENCH(return new CMAPBench(charsToGlyphsNull_proc, "face_charsToGlyphs_null");)
=======
DEF_BENCH( return new CMAPBench(containsText_proc, "paint_containsText"); )
DEF_BENCH( return new CMAPBench(textToGlyphs_proc, "paint_textToGlyphs"); )
DEF_BENCH( return new CMAPBench(charsToGlyphs_proc, "face_charsToGlyphs"); )
DEF_BENCH( return new CMAPBench(charsToGlyphsNull_proc, "face_charsToGlyphs_null"); )
>>>>>>> miniblink49
