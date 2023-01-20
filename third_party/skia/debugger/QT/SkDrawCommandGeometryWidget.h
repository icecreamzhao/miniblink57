/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#ifndef SKDRAWCOMMANDGEOMETRYWIDGET_H_
#define SKDRAWCOMMANDGEOMETRYWIDGET_H_

#include <QFrame>

#include "SkSurface.h"
class SkDebugger;

<<<<<<< HEAD
class SkDrawCommandGeometryWidget : public QFrame {
=======
class  SkDrawCommandGeometryWidget : public QFrame {
>>>>>>> miniblink49
    Q_OBJECT

public:
    SkDrawCommandGeometryWidget(SkDebugger* debugger);
    void setDrawCommandIndex(int index);

protected:
    void paintEvent(QPaintEvent* event);
    void resizeEvent(QResizeEvent* event);

private:
    void updateImage();

    SkDebugger* fDebugger;
<<<<<<< HEAD
    sk_sp<SkSurface> fSurface;
=======
    SkAutoTUnref<SkSurface> fSurface;
>>>>>>> miniblink49
    int fCommandIndex;
};

#endif /* SKDRAWCOMMANDGEOMETRYWIDGET_H_ */
