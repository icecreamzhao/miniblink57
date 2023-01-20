/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "GMSampleView.h"

<<<<<<< HEAD
GMSampleView::GMSampleView(GM* gm)
    : fShowSize(false)
    , fGM(gm)
{
}

GMSampleView::~GMSampleView()
{
    delete fGM;
}

SkEvent* GMSampleView::NewShowSizeEvt(bool doShowSize)
{
    SkEvent* evt = new SkEvent("GMSampleView::showSize");
=======
GMSampleView::GMSampleView(GM* gm) : fShowSize(false), fGM(gm) {}

GMSampleView::~GMSampleView() {
    delete fGM;
}

SkEvent* GMSampleView::NewShowSizeEvt(bool doShowSize) {
    SkEvent* evt = SkNEW_ARGS(SkEvent, ("GMSampleView::showSize"));
>>>>>>> miniblink49
    evt->setFast32(doShowSize);
    return evt;
}

<<<<<<< HEAD
bool GMSampleView::onQuery(SkEvent* evt)
{
=======
bool GMSampleView::onQuery(SkEvent* evt) {
>>>>>>> miniblink49
    if (SampleCode::TitleQ(*evt)) {
        SkString name("GM:");
        name.append(fGM->getName());
        SampleCode::TitleR(evt, name.c_str());
        return true;
    }
    return this->INHERITED::onQuery(evt);
}

<<<<<<< HEAD
bool GMSampleView::onEvent(const SkEvent& evt)
{
=======
bool GMSampleView::onEvent(const SkEvent& evt) {
>>>>>>> miniblink49
    if (evt.isType("GMSampleView::showSize")) {
        fShowSize = SkToBool(evt.getFast32());
        return true;
    }
    return this->INHERITED::onEvent(evt);
}

<<<<<<< HEAD
#include "SkPicture.h"
#include "SkStream.h"
static sk_sp<SkPicture> round_trip_serialize(SkPicture* src)
{
    SkDynamicMemoryWStream stream;
    src->serialize(&stream);
    SkAutoTDelete<SkStream> reader(stream.detachAsStream());
    return SkPicture::MakeFromStream(reader);
}

#include "SkPictureRecorder.h"
void GMSampleView::onDrawContent(SkCanvas* canvas)
{
    SkPictureRecorder recorder;
    SkCanvas* origCanvas = canvas;

    if (false) {
        SkISize size = fGM->getISize();
        canvas = recorder.beginRecording(SkRect::MakeIWH(size.width(), size.height()));
    }

=======
void GMSampleView::onDrawContent(SkCanvas* canvas) {
>>>>>>> miniblink49
    {
        SkAutoCanvasRestore acr(canvas, fShowSize);
        fGM->drawContent(canvas);
    }
<<<<<<< HEAD

    if (origCanvas != canvas) {
        sk_sp<SkPicture> pic = recorder.finishRecordingAsPicture();
        if (false) {
            pic = round_trip_serialize(pic.get());
        }
        origCanvas->drawPicture(pic);
        canvas = origCanvas;
    }

    if (fShowSize) {
        SkISize size = fGM->getISize();
        SkRect r = SkRect::MakeWH(SkIntToScalar(size.width()),
            SkIntToScalar(size.height()));
=======
    if (fShowSize) {
        SkISize size = fGM->getISize();
        SkRect r = SkRect::MakeWH(SkIntToScalar(size.width()),
                                  SkIntToScalar(size.height()));
>>>>>>> miniblink49
        SkPaint paint;
        paint.setColor(0x40FF8833);
        canvas->drawRect(r, paint);
    }
}

<<<<<<< HEAD
void GMSampleView::onDrawBackground(SkCanvas* canvas)
{
    fGM->drawBackground(canvas);
}

bool GMSampleView::onAnimate(const SkAnimTimer& timer)
{
    return fGM->animate(timer);
}
=======
void GMSampleView::onDrawBackground(SkCanvas* canvas) {
    fGM->drawBackground(canvas);
}

bool GMSampleView::onAnimate(const SkAnimTimer& timer) {
    return fGM->animate(timer);
}

>>>>>>> miniblink49
