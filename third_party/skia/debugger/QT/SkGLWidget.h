
/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#ifndef SKGLWIDGET_H_
#define SKGLWIDGET_H_

#if SK_SUPPORT_GPU

<<<<<<< HEAD
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
=======
#include <QtOpenGL/QGLWidget>
#include "SkDebugCanvas.h"
#include "SkDebugger.h"
#include "SkDevice.h"
#include "SkGpuDevice.h"
#include "GrContext.h"
#include "gl/GrGLInterface.h"
#include "gl/GrGLUtil.h"
#include "GrRenderTarget.h"

class SkGLWidget : public QGLWidget {
Q_OBJECT
>>>>>>> miniblink49

public:
    SkGLWidget(SkDebugger* debugger);

    ~SkGLWidget();

<<<<<<< HEAD
    void updateImage()
    {
=======
    void updateImage() {
>>>>>>> miniblink49
        this->updateGL();
    }
    void setSampleCount(int sampleCount);

<<<<<<< HEAD
Q_SIGNALS:
=======
signals:
>>>>>>> miniblink49
    void drawComplete();

protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

<<<<<<< HEAD
=======

>>>>>>> miniblink49
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
