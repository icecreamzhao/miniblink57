/*
 * Copyright 2015 Google Inc.
 *
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 *
 */

#include "HelloWorld.h"

<<<<<<< HEAD
#include "GrContext.h"
#include "SkApplication.h"
#include "SkCanvas.h"
#include "SkGr.h"
#include "SkGradientShader.h"
#include "SkGraphics.h"
#include "gl/GrGLInterface.h"

void application_init()
{
=======
#include "gl/GrGLInterface.h"
#include "SkApplication.h"
#include "SkCanvas.h"
#include "SkGradientShader.h"
#include "SkGraphics.h"
#include "SkGr.h"

void application_init() {
>>>>>>> miniblink49
    SkGraphics::Init();
    SkEvent::Init();
}

<<<<<<< HEAD
void application_term()
{
    SkEvent::Term();
}

HelloWorldWindow::HelloWorldWindow(void* hwnd)
    : INHERITED(hwnd)
{
=======
void application_term() {
    SkEvent::Term();
    SkGraphics::Term();
}

HelloWorldWindow::HelloWorldWindow(void* hwnd)
    : INHERITED(hwnd) {
>>>>>>> miniblink49
    fType = kGPU_DeviceType;
    fRenderTarget = NULL;
    fRotationAngle = 0;
    this->setTitle();
    this->setUpBackend();
}

<<<<<<< HEAD
HelloWorldWindow::~HelloWorldWindow()
{
    tearDownBackend();
}

void HelloWorldWindow::tearDownBackend()
{
=======
HelloWorldWindow::~HelloWorldWindow() {
    tearDownBackend();
}

void HelloWorldWindow::tearDownBackend() {
>>>>>>> miniblink49
    SkSafeUnref(fContext);
    fContext = NULL;

    SkSafeUnref(fInterface);
    fInterface = NULL;

    SkSafeUnref(fRenderTarget);
    fRenderTarget = NULL;

<<<<<<< HEAD
    INHERITED::release();
}

void HelloWorldWindow::setTitle()
{
=======
    INHERITED::detach();
}

void HelloWorldWindow::setTitle() {
>>>>>>> miniblink49
    SkString title("Hello World ");
    title.appendf(fType == kRaster_DeviceType ? "raster" : "opengl");
    INHERITED::setTitle(title.c_str());
}

<<<<<<< HEAD
bool HelloWorldWindow::setUpBackend()
{
    this->setVisibleP(true);
    this->setClipToBounds(false);

    bool result = attach(kNativeGL_BackEndType, 0 /*msaa*/, false, &fAttachmentInfo);
    if (false == result) {
        SkDebugf("Not possible to create backend.\n");
        release();
=======
bool HelloWorldWindow::setUpBackend() {
    this->setColorType(kRGBA_8888_SkColorType);
    this->setVisibleP(true);
    this->setClipToBounds(false);

    bool result = attach(kNativeGL_BackEndType, 0 /*msaa*/, &fAttachmentInfo);
    if (false == result) {
        SkDebugf("Not possible to create backend.\n");
        detach();
>>>>>>> miniblink49
        return false;
    }

    fInterface = GrGLCreateNativeInterface();

    SkASSERT(NULL != fInterface);

    fContext = GrContext::Create(kOpenGL_GrBackend, (GrBackendContext)fInterface);
    SkASSERT(NULL != fContext);

    this->setUpRenderTarget();
    return true;
}

<<<<<<< HEAD
void HelloWorldWindow::setUpRenderTarget()
{
=======
void HelloWorldWindow::setUpRenderTarget() {
>>>>>>> miniblink49
    SkSafeUnref(fRenderTarget);
    fRenderTarget = this->renderTarget(fAttachmentInfo, fInterface, fContext);
}

<<<<<<< HEAD
void HelloWorldWindow::drawContents(SkCanvas* canvas)
{
=======
void HelloWorldWindow::drawContents(SkCanvas* canvas) {
>>>>>>> miniblink49
    // Clear background
    canvas->drawColor(SK_ColorWHITE);

    SkPaint paint;
    paint.setColor(SK_ColorRED);

    // Draw a rectangle with red paint
<<<<<<< HEAD
    SkRect rect = SkRect::MakeXYWH(10, 10, 128, 128);
=======
    SkRect rect = {
            10, 10,
            128, 128
    };
>>>>>>> miniblink49
    canvas->drawRect(rect, paint);

    // Set up a linear gradient and draw a circle
    {
        SkPoint linearPoints[] = {
<<<<<<< HEAD
            { 0, 0 },
            { 300, 300 }
        };
        SkColor linearColors[] = { SK_ColorGREEN, SK_ColorBLACK };

        paint.setShader(SkGradientShader::MakeLinear(
            linearPoints, linearColors, nullptr, 2,
            SkShader::kMirror_TileMode));
=======
                {0, 0},
                {300, 300}
        };
        SkColor linearColors[] = {SK_ColorGREEN, SK_ColorBLACK};

        SkShader* shader = SkGradientShader::CreateLinear(
                linearPoints, linearColors, NULL, 2,
                SkShader::kMirror_TileMode);
        SkAutoUnref shader_deleter(shader);

        paint.setShader(shader);
>>>>>>> miniblink49
        paint.setFlags(SkPaint::kAntiAlias_Flag);

        canvas->drawCircle(200, 200, 64, paint);

        // Detach shader
<<<<<<< HEAD
        paint.setShader(nullptr);
=======
        paint.setShader(NULL);
>>>>>>> miniblink49
    }

    // Draw a message with a nice black paint.
    paint.setFlags(
<<<<<<< HEAD
        SkPaint::kAntiAlias_Flag | SkPaint::kSubpixelText_Flag | // ... avoid waggly text when rotating.
        SkPaint::kUnderlineText_Flag);
=======
            SkPaint::kAntiAlias_Flag |
            SkPaint::kSubpixelText_Flag |  // ... avoid waggly text when rotating.
            SkPaint::kUnderlineText_Flag);
>>>>>>> miniblink49
    paint.setColor(SK_ColorBLACK);
    paint.setTextSize(20);

    canvas->save();

    static const char message[] = "Hello World";

    // Translate and rotate
    canvas->translate(300, 300);
    fRotationAngle += 0.2f;
    if (fRotationAngle > 360) {
        fRotationAngle -= 360;
    }
    canvas->rotate(fRotationAngle);

    // Draw the text:
    canvas->drawText(message, strlen(message), 0, 0, paint);

    canvas->restore();
}

<<<<<<< HEAD
void HelloWorldWindow::draw(SkCanvas* canvas)
{
=======
void HelloWorldWindow::draw(SkCanvas* canvas) {
>>>>>>> miniblink49
    drawContents(canvas);
    // in case we have queued drawing calls
    fContext->flush();
    // Invalidate the window to force a redraw. Poor man's animation mechanism.
    this->inval(NULL);

    if (kRaster_DeviceType == fType) {
        // need to send the raster bits to the (gpu) window
<<<<<<< HEAD
        sk_sp<SkImage> snap = fSurface->makeImageSnapshot();
        SkPixmap pmap;
        if (snap->peekPixels(&pmap)) {
            const SkImageInfo& info = pmap.info();
            fRenderTarget->writePixels(0, 0, snap->width(), snap->height(),
                SkImageInfo2GrPixelConfig(info, *fContext->caps()),
                pmap.addr(), pmap.rowBytes(),
                GrContext::kFlushWrites_PixelOp);
        }
=======
        SkImage* snap = fSurface->newImageSnapshot();
        size_t rowBytes;
        SkImageInfo info;
        const void* pixels = snap->peekPixels(&info, &rowBytes);
        fRenderTarget->writePixels(0, 0, snap->width(), snap->height(),
                                        SkImageInfo2GrPixelConfig(info.colorType(),
                                                                info.alphaType(),
                                                                info.profileType()),
                                        pixels,
                                        rowBytes,
                                        GrContext::kFlushWrites_PixelOp);
        SkSafeUnref(snap);
>>>>>>> miniblink49
    }
    INHERITED::present();
}

<<<<<<< HEAD
void HelloWorldWindow::onSizeChange()
{
    setUpRenderTarget();
}

bool HelloWorldWindow::onHandleChar(SkUnichar unichar)
{
    if (' ' == unichar) {
        fType = fType == kRaster_DeviceType ? kGPU_DeviceType : kRaster_DeviceType;
=======
void HelloWorldWindow::onSizeChange() {
    setUpRenderTarget();
}

bool HelloWorldWindow::onHandleChar(SkUnichar unichar) {
    if (' ' == unichar) {
        fType = fType == kRaster_DeviceType ? kGPU_DeviceType: kRaster_DeviceType;
>>>>>>> miniblink49
        tearDownBackend();
        setUpBackend();
        this->setTitle();
        this->inval(NULL);
    }
    return true;
}

<<<<<<< HEAD
SkOSWindow* create_sk_window(void* hwnd, int, char**)
{
=======
SkOSWindow* create_sk_window(void* hwnd, int , char** ) {
>>>>>>> miniblink49
    return new HelloWorldWindow(hwnd);
}
