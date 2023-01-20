
/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#include "SkGLWidget.h"

#if SK_SUPPORT_GPU

<<<<<<< HEAD
SkGLWidget::SkGLWidget(SkDebugger* debugger)
    : QGLWidget()
{
    fDebugger = debugger;
}

SkGLWidget::~SkGLWidget()
{
}

void SkGLWidget::setSampleCount(int sampleCount)
{
=======
SkGLWidget::SkGLWidget(SkDebugger* debugger) : QGLWidget() {
    fDebugger = debugger;
}

SkGLWidget::~SkGLWidget() {
}

void SkGLWidget::setSampleCount(int sampleCount) {
>>>>>>> miniblink49
    QGLFormat currentFormat = format();
    currentFormat.setSampleBuffers(sampleCount > 0);
    currentFormat.setSamples(sampleCount);
    setFormat(currentFormat);
}

<<<<<<< HEAD
void SkGLWidget::initializeGL()
{
=======
void SkGLWidget::initializeGL() {
>>>>>>> miniblink49
    if (!fCurIntf) {
        fCurIntf.reset(GrGLCreateNativeInterface());
    }
    if (!fCurIntf) {
        return;
    }
    // The call may come multiple times, for example after setSampleCount().  The QGLContext will be
    // different, but we do not have a mechanism to catch the destroying of QGLContext, so that
    // proper resource cleanup could be made.
    if (fCurContext) {
        fCurContext->abandonContext();
    }
<<<<<<< HEAD
    fGpuDevice.reset(nullptr);
    fCanvas.reset(nullptr);

    fCurContext.reset(GrContext::Create(kOpenGL_GrBackend, (GrBackendContext)fCurIntf.get()));
}

void SkGLWidget::createRenderTarget()
{
=======
    fGpuDevice.reset(NULL);
    fCanvas.reset(NULL);

    fCurContext.reset(GrContext::Create(kOpenGL_GrBackend, (GrBackendContext) fCurIntf.get()));
}

void SkGLWidget::createRenderTarget() {
>>>>>>> miniblink49
    if (!fCurContext) {
        return;
    }

    glDisable(GL_SCISSOR_TEST);
    glStencilMask(0xffffffff);
    glClearStencil(0);
    glClear(GL_STENCIL_BUFFER_BIT);
    fCurContext->resetContext();

<<<<<<< HEAD
    fGpuDevice.reset(nullptr);
    fCanvas.reset(nullptr);

    GrBackendRenderTargetDesc desc = this->getDesc(this->width(), this->height());
    desc.fOrigin = kBottomLeft_GrSurfaceOrigin;
    sk_sp<GrRenderTarget> curRenderTarget(
        fCurContext->textureProvider()->wrapBackendRenderTarget(desc));
    SkSurfaceProps props(0, kUnknown_SkPixelGeometry);
    fGpuDevice.reset(SkGpuDevice::Make(std::move(curRenderTarget), &props,
        SkGpuDevice::kUninit_InitContents)
                         .release());
    fCanvas.reset(new SkCanvas(fGpuDevice));
}

void SkGLWidget::resizeGL(int w, int h)
{
=======
    fGpuDevice.reset(NULL);
    fCanvas.reset(NULL);

    GrBackendRenderTargetDesc desc = this->getDesc(this->width(), this->height());
    desc.fOrigin = kBottomLeft_GrSurfaceOrigin;
    SkAutoTUnref<GrRenderTarget> curRenderTarget(
            fCurContext->textureProvider()->wrapBackendRenderTarget(desc));
    SkSurfaceProps props(0, kUnknown_SkPixelGeometry);
    fGpuDevice.reset(SkGpuDevice::Create(curRenderTarget, &props,
                                         SkGpuDevice::kUninit_InitContents));
    fCanvas.reset(new SkCanvas(fGpuDevice));
}

void SkGLWidget::resizeGL(int w, int h) {
>>>>>>> miniblink49
    SkASSERT(w == this->width() && h == this->height());
    this->createRenderTarget();
}

<<<<<<< HEAD
void SkGLWidget::paintGL()
{
=======
void SkGLWidget::paintGL() {
>>>>>>> miniblink49
    if (!this->isHidden() && fCanvas) {
        fCurContext->resetContext();
        fDebugger->draw(fCanvas.get());
        // TODO(chudy): Implement an optional flush button in Gui.
        fCanvas->flush();
<<<<<<< HEAD
        Q_EMIT drawComplete();
    }
}

GrBackendRenderTargetDesc SkGLWidget::getDesc(int w, int h)
{
=======
        emit drawComplete();
    }
}

GrBackendRenderTargetDesc SkGLWidget::getDesc(int w, int h) {
>>>>>>> miniblink49
    GrBackendRenderTargetDesc desc;
    desc.fWidth = SkScalarRoundToInt(this->width());
    desc.fHeight = SkScalarRoundToInt(this->height());
    desc.fConfig = kSkia8888_GrPixelConfig;
    GR_GL_GetIntegerv(fCurIntf, GR_GL_SAMPLES, &desc.fSampleCnt);
    GR_GL_GetIntegerv(fCurIntf, GR_GL_STENCIL_BITS, &desc.fStencilBits);
    GrGLint buffer;
    GR_GL_GetIntegerv(fCurIntf, GR_GL_FRAMEBUFFER_BINDING, &buffer);
    desc.fRenderTargetHandle = buffer;

    return desc;
}

#endif
