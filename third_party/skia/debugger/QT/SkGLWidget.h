
/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SKGLWIDGET_H_
#define SKGLWIDGET_H_

#if SK_SUPPORT_GPU

#include "GrContext.h"
#include "GrRenderTarget.h"
#include "SkDebugCanvas.h"
#include "SkDebugger.h"
#include "SkGpuDevice.h"
#include "gl/GrGLInterface.h"
#include "gl/GrGLUtil.h"
#include <QtOpenGL/QGLWidget>

class SkGLWidget : public QGLWidget {
    Q_OBJECT

public:
    SkGLWidget(SkDebugger* debugger);

    ~SkGLWidget();

    void updateImage()
    {
        this->updateGL();
    }
    void setSampleCount(int sampleCount);

Q_SIGNALS:
    void drawComplete();

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

private:
    void createRenderTarget();
    SkAutoTUnref<const GrGLInterface> fCurIntf;
    SkAutoTUnref<GrContext> fCurContext;
    SkAutoTUnref<SkGpuDevice> fGpuDevice;
    SkAutoTUnref<SkCanvas> fCanvas;
    SkDebugger* fDebugger;
    GrBackendRenderTargetDesc getDesc(int w, int h);
};

#endif /* SK_SUPPORT_GPU */

#endif /* SKGLWIDGET_H_ */
