/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkTypes.h"

#ifdef SAMPLE_PDF_FILE_VIEWER

#include "SampleCode.h"
#include "SkCanvas.h"
#include "SkColorFilter.h"
#include "SkColorPriv.h"
#include "SkDumpCanvas.h"
#include "SkGradientShader.h"
#include "SkGraphics.h"
=======
#ifdef SAMPLE_PDF_FILE_VIEWER

#include "SampleCode.h"
#include "SkDumpCanvas.h"
#include "SkView.h"
#include "SkCanvas.h"
#include "SkGradientShader.h"
#include "SkGraphics.h"
#include "SkImageDecoder.h"
>>>>>>> miniblink49
#include "SkOSFile.h"
#include "SkPath.h"
#include "SkPicture.h"
#include "SkRandom.h"
#include "SkRegion.h"
#include "SkShader.h"
<<<<<<< HEAD
#include "SkTime.h"
#include "SkTypeface.h"
#include "SkUtils.h"
#include "SkView.h"
=======
#include "SkUtils.h"
#include "SkColorPriv.h"
#include "SkColorFilter.h"
#include "SkTime.h"
#include "SkTypeface.h"
>>>>>>> miniblink49
#include "SkXfermode.h"

#include "SkPdfRenderer.h"

class PdfFileViewer : public SampleView {
private:
<<<<<<< HEAD
    SkString fFilename;
    SkPicture* fPicture; // TODO(edisonn): multiple pages, one page / picture, make it an array

    static SkPicture* LoadPdf(const char path[])
    {
        SkAutoTDelete<SkPdfRenderer> renderer(SkPdfRenderer::CreateFromFile(path));
        if (nullptr == renderer.get()) {
            return nullptr;
        }

        SkPicture* pic = new SkPicture;
        SkCanvas* canvas = pic->beginRecording((int)renderer->MediaBox(0).width(),
            (int)renderer->MediaBox(0).height());
=======
    SkString    fFilename;
    SkPicture*  fPicture;  // TODO(edisonn): multiple pages, one page / picture, make it an array

    static SkPicture* LoadPdf(const char path[]) {
        SkAutoTDelete<SkPdfRenderer> renderer(SkPdfRenderer::CreateFromFile(path));
        if (NULL == renderer.get()) {
            return NULL;
        }

        SkPicture* pic = SkNEW(SkPicture);
        SkCanvas* canvas = pic->beginRecording((int) renderer->MediaBox(0).width(),
                                               (int) renderer->MediaBox(0).height());
>>>>>>> miniblink49
        renderer->renderPage(0, canvas, renderer->MediaBox(0));
        pic->endRecording();
        return pic;
    }

public:
<<<<<<< HEAD
    PdfFileViewer(const char name[] = nullptr)
        : fFilename(name)
    {
        fPicture = nullptr;
    }

    virtual ~PdfFileViewer()
    {
=======
    PdfFileViewer(const char name[] = NULL) : fFilename(name) {
        fPicture = NULL;
    }

    virtual ~PdfFileViewer() {
>>>>>>> miniblink49
        SkSafeUnref(fPicture);
    }

protected:
    // overrides from SkEventSink
<<<<<<< HEAD
    virtual bool onQuery(SkEvent* evt)
    {
        if (SampleCode::TitleQ(*evt)) {
            SkString name("P:");
            const char* basename = strrchr(fFilename.c_str(), SkPATH_SEPARATOR);
            name.append(basename ? basename + 1 : fFilename.c_str());
=======
    virtual bool onQuery(SkEvent* evt) {
        if (SampleCode::TitleQ(*evt)) {
            SkString name("P:");
            const char* basename = strrchr(fFilename.c_str(), SkPATH_SEPARATOR);
            name.append(basename ? basename+1: fFilename.c_str());
>>>>>>> miniblink49
            SampleCode::TitleR(evt, name.c_str());
            return true;
        }
        return this->INHERITED::onQuery(evt);
    }

<<<<<<< HEAD
    virtual bool onEvent(const SkEvent& evt)
    {
=======
    virtual bool onEvent(const SkEvent& evt) {
>>>>>>> miniblink49
        // TODO(edisonn): add here event handlers to disable clipping, or to show helpful info
        // like pdf object from click, ...
        // TODO(edisonn): first, next, prev, last page navigation + slideshow
        return this->INHERITED::onEvent(evt);
    }

<<<<<<< HEAD
    virtual void onDrawContent(SkCanvas* canvas)
    {
=======
    virtual void onDrawContent(SkCanvas* canvas) {
>>>>>>> miniblink49
        if (!fPicture) {
            fPicture = LoadPdf(fFilename.c_str());
        }
        if (fPicture) {
            canvas->drawPicture(*fPicture);
        }
    }

private:
    typedef SampleView INHERITED;
};

SampleView* CreateSamplePdfFileViewer(const char filename[]);
<<<<<<< HEAD
SampleView* CreateSamplePdfFileViewer(const char filename[])
{
=======
SampleView* CreateSamplePdfFileViewer(const char filename[]) {
>>>>>>> miniblink49
    return new PdfFileViewer(filename);
}

//////////////////////////////////////////////////////////////////////////////

#if 0
static SkView* MyFactory() { return new PdfFileViewer; }
static SkViewRegister reg(MyFactory);
#endif

<<<<<<< HEAD
#endif // SAMPLE_PDF_FILE_VIEWER
=======
#endif  // SAMPLE_PDF_FILE_VIEWER
>>>>>>> miniblink49
