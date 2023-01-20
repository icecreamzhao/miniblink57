<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#include "SkAnnotation.h"
#include "SkCanvas.h"
#include "SkData.h"
#include "SkDocument.h"
#include "SkStream.h"
#include "Test.h"

/** Returns true if data (may contain null characters) contains needle (null
 *  terminated). */
<<<<<<< HEAD
static bool ContainsString(const char* data, size_t dataSize, const char* needle)
{
=======
static bool ContainsString(const char* data, size_t dataSize, const char* needle) {
>>>>>>> miniblink49
    size_t nSize = strlen(needle);
    for (size_t i = 0; i < dataSize - nSize; i++) {
        if (strncmp(&data[i], needle, nSize) == 0) {
            return true;
        }
    }
    return false;
}

<<<<<<< HEAD
DEF_TEST(Annotation_NoDraw, reporter)
{
=======
DEF_TEST(Annotation_NoDraw, reporter) {
>>>>>>> miniblink49
    SkBitmap bm;
    bm.allocN32Pixels(10, 10);
    bm.eraseColor(SK_ColorTRANSPARENT);

    SkCanvas canvas(bm);
    SkRect r = SkRect::MakeWH(SkIntToScalar(10), SkIntToScalar(10));

    SkAutoDataUnref data(SkData::NewWithCString("http://www.gooogle.com"));

    REPORTER_ASSERT(reporter, 0 == *bm.getAddr32(0, 0));
    SkAnnotateRectWithURL(&canvas, r, data.get());
    REPORTER_ASSERT(reporter, 0 == *bm.getAddr32(0, 0));
}

<<<<<<< HEAD
DEF_TEST(Annotation_PdfLink, reporter)
{
    REQUIRE_PDF_DOCUMENT(Annotation_PdfLink, reporter);
    SkDynamicMemoryWStream outStream;
    sk_sp<SkDocument> doc(SkDocument::MakePDF(&outStream));
=======
DEF_TEST(Annotation_PdfLink, reporter) {
    SkDynamicMemoryWStream outStream;
    SkAutoTUnref<SkDocument> doc(SkDocument::CreatePDF(&outStream));
>>>>>>> miniblink49
    SkCanvas* canvas = doc->beginPage(612.0f, 792.0f);
    REPORTER_ASSERT(reporter, canvas);

    SkRect r = SkRect::MakeXYWH(SkIntToScalar(72), SkIntToScalar(72),
<<<<<<< HEAD
        SkIntToScalar(288), SkIntToScalar(72));
=======
                                SkIntToScalar(288), SkIntToScalar(72));
>>>>>>> miniblink49
    SkAutoDataUnref data(SkData::NewWithCString("http://www.gooogle.com"));
    SkAnnotateRectWithURL(canvas, r, data.get());

    REPORTER_ASSERT(reporter, doc->close());
    SkAutoDataUnref out(outStream.copyToData());
    const char* rawOutput = (const char*)out->data();

    REPORTER_ASSERT(reporter, ContainsString(rawOutput, out->size(), "/Annots "));
}

<<<<<<< HEAD
DEF_TEST(Annotation_NamedDestination, reporter)
{
    REQUIRE_PDF_DOCUMENT(Annotation_NamedDestination, reporter);
    SkDynamicMemoryWStream outStream;
    sk_sp<SkDocument> doc(SkDocument::MakePDF(&outStream));
=======
DEF_TEST(Annotation_NamedDestination, reporter) {
    SkDynamicMemoryWStream outStream;
    SkAutoTUnref<SkDocument> doc(SkDocument::CreatePDF(&outStream));
>>>>>>> miniblink49
    SkCanvas* canvas = doc->beginPage(612.0f, 792.0f);
    REPORTER_ASSERT(reporter, canvas);

    SkPoint p = SkPoint::Make(SkIntToScalar(72), SkIntToScalar(72));
    SkAutoDataUnref data(SkData::NewWithCString("example"));
    SkAnnotateNamedDestination(canvas, p, data.get());

    REPORTER_ASSERT(reporter, doc->close());
    SkAutoDataUnref out(outStream.copyToData());
    const char* rawOutput = (const char*)out->data();

    REPORTER_ASSERT(reporter,
        ContainsString(rawOutput, out->size(), "/example "));
}
