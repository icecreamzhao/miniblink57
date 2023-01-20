/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "gm.h"
#include "SkShader.h"
using namespace skiagm;

<<<<<<< HEAD
GM::GM()
{
=======
GM::GM() {
>>>>>>> miniblink49
    fMode = kGM_Mode;
    fBGColor = SK_ColorWHITE;
    fCanvasIsDeferred = false;
    fHaveCalledOnceBeforeDraw = false;
    fStarterMatrix.reset();
}

<<<<<<< HEAD
GM::~GM() { }

void GM::draw(SkCanvas* canvas)
{
=======
GM::~GM() {}

void GM::draw(SkCanvas* canvas) {
>>>>>>> miniblink49
    this->drawBackground(canvas);
    this->drawContent(canvas);
}

<<<<<<< HEAD
void GM::drawContent(SkCanvas* canvas)
{
=======
void GM::drawContent(SkCanvas* canvas) {
>>>>>>> miniblink49
    if (!fHaveCalledOnceBeforeDraw) {
        fHaveCalledOnceBeforeDraw = true;
        this->onOnceBeforeDraw();
    }
    this->onDraw(canvas);
}

<<<<<<< HEAD
void GM::drawBackground(SkCanvas* canvas)
{
=======
void GM::drawBackground(SkCanvas* canvas) {
>>>>>>> miniblink49
    if (!fHaveCalledOnceBeforeDraw) {
        fHaveCalledOnceBeforeDraw = true;
        this->onOnceBeforeDraw();
    }
    this->onDrawBackground(canvas);
}

<<<<<<< HEAD
const char* GM::getName()
{
=======
const char* GM::getName() {
>>>>>>> miniblink49
    if (fShortName.size() == 0) {
        fShortName = this->onShortName();
    }
    return fShortName.c_str();
}

<<<<<<< HEAD
void GM::setBGColor(SkColor color)
{
    fBGColor = color;
}

bool GM::animate(const SkAnimTimer& timer)
{
=======
void GM::setBGColor(SkColor color) {
    fBGColor = color;
}

bool GM::animate(const SkAnimTimer& timer) {
>>>>>>> miniblink49
    return this->onAnimate(timer);
}

/////////////////////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void GM::onDrawBackground(SkCanvas* canvas)
{
    canvas->drawColor(fBGColor, SkXfermode::kSrc_Mode);
}

void GM::drawSizeBounds(SkCanvas* canvas, SkColor color)
{
    SkISize size = this->getISize();
    SkRect r = SkRect::MakeWH(SkIntToScalar(size.width()),
        SkIntToScalar(size.height()));
=======
void GM::onDrawBackground(SkCanvas* canvas) {
    canvas->drawColor(fBGColor, SkXfermode::kSrc_Mode);
}

void GM::drawSizeBounds(SkCanvas* canvas, SkColor color) {
    SkISize size = this->getISize();
    SkRect r = SkRect::MakeWH(SkIntToScalar(size.width()),
                              SkIntToScalar(size.height()));
>>>>>>> miniblink49
    SkPaint paint;
    paint.setColor(color);
    canvas->drawRect(r, paint);
}

<<<<<<< HEAD
void GM::DrawGpuOnlyMessage(SkCanvas* canvas)
{
=======
void GM::drawGpuOnlyMessage(SkCanvas* canvas) {
>>>>>>> miniblink49
    SkBitmap bmp;
    bmp.allocN32Pixels(128, 64);
    SkCanvas bmpCanvas(bmp);
    bmpCanvas.drawColor(SK_ColorWHITE);
    SkPaint paint;
    paint.setAntiAlias(true);
    paint.setTextSize(20);
    paint.setColor(SK_ColorRED);
<<<<<<< HEAD
    sk_tool_utils::set_portable_typeface(&paint);
=======
>>>>>>> miniblink49
    static const char kTxt[] = "GPU Only";
    bmpCanvas.drawText(kTxt, strlen(kTxt), 20, 40, paint);
    SkMatrix localM;
    localM.setRotate(35.f);
    localM.postTranslate(10.f, 0.f);
<<<<<<< HEAD
    paint.setShader(SkShader::MakeBitmapShader(bmp, SkShader::kMirror_TileMode,
        SkShader::kMirror_TileMode,
        &localM));
=======
    SkAutoTUnref<SkShader> shader(SkShader::CreateBitmapShader(bmp, SkShader::kMirror_TileMode,
                                                               SkShader::kMirror_TileMode,
                                                               &localM));
    paint.setShader(shader);
>>>>>>> miniblink49
    paint.setFilterQuality(kMedium_SkFilterQuality);
    canvas->drawPaint(paint);
    return;
}

// need to explicitly declare this, or we get some weird infinite loop llist
template GMRegistry* GMRegistry::gHead;

<<<<<<< HEAD
void skiagm::SimpleGM::onDraw(SkCanvas* canvas)
{
    fDrawProc(canvas);
}

SkISize skiagm::SimpleGM::onISize()
{
    return fSize;
}

SkString skiagm::SimpleGM::onShortName()
{
    return fName;
}
=======
void skiagm::SimpleGM::onDraw(SkCanvas* canvas) {
    fDrawProc(canvas);
}

SkISize skiagm::SimpleGM::onISize() {
    return fSize;
}

SkString skiagm::SimpleGM::onShortName() {
    return fName;
}

>>>>>>> miniblink49
