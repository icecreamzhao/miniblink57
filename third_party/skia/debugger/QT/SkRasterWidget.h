<<<<<<< HEAD

/*
 * Copyright 2016 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

=======
/*
 * SkRasterWidget.h
 *
 *  Created on: Jul 28, 2012
 *      Author: chudy
 */


>>>>>>> miniblink49
#ifndef SKRASTERWIDGET_H_
#define SKRASTERWIDGET_H_

#include "SkSurface.h"
class SkDebugger;

#include <QWidget>

<<<<<<< HEAD
class SkRasterWidget : public QWidget {
=======
class  SkRasterWidget : public QWidget {
>>>>>>> miniblink49
    Q_OBJECT

public:
    SkRasterWidget(SkDebugger* debugger);

    void updateImage();

<<<<<<< HEAD
Q_SIGNALS:
=======
signals:
>>>>>>> miniblink49
    void drawComplete();

protected:
    void paintEvent(QPaintEvent* event);

    void resizeEvent(QResizeEvent* event);

private:
    SkDebugger* fDebugger;
<<<<<<< HEAD
    sk_sp<SkSurface> fSurface;
=======
    SkAutoTUnref<SkSurface> fSurface;
>>>>>>> miniblink49
    bool fNeedImageUpdate;
};

#endif /* SKRASTERWIDGET_H_ */
