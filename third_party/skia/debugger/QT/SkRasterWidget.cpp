
/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkRasterWidget.h"
#include "SkDebugger.h"
#include <QtGui>

<<<<<<< HEAD
SkRasterWidget::SkRasterWidget(SkDebugger* debugger)
    : QWidget()
    , fDebugger(debugger)
    , fNeedImageUpdate(false)
{
    this->setStyleSheet("QWidget {background-color: black; border: 1px solid #cccccc;}");
}

void SkRasterWidget::resizeEvent(QResizeEvent* event)
{
=======
SkRasterWidget::SkRasterWidget(SkDebugger *debugger)
    : QWidget()
    , fDebugger(debugger)
    , fNeedImageUpdate(false) {
    this->setStyleSheet("QWidget {background-color: black; border: 1px solid #cccccc;}");
}

void SkRasterWidget::resizeEvent(QResizeEvent* event) {
>>>>>>> miniblink49
    this->QWidget::resizeEvent(event);

    QRect r = this->contentsRect();
    if (r.width() == 0 || r.height() == 0) {
<<<<<<< HEAD
        fSurface = nullptr;
    } else {
        SkImageInfo info = SkImageInfo::MakeN32Premul(r.width(), r.height());
        fSurface = SkSurface::MakeRaster(info);
=======
        fSurface.reset(NULL);
    } else {
        SkImageInfo info = SkImageInfo::MakeN32Premul(r.width(), r.height());
        fSurface.reset(SkSurface::NewRaster(info));
>>>>>>> miniblink49
    }
    this->updateImage();
}

<<<<<<< HEAD
void SkRasterWidget::paintEvent(QPaintEvent* event)
{
=======
void SkRasterWidget::paintEvent(QPaintEvent* event) {
>>>>>>> miniblink49
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QStyleOption opt;
    opt.init(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);

    if (!fSurface) {
        return;
    }

    if (fNeedImageUpdate) {
        fDebugger->draw(fSurface->getCanvas());
        fSurface->getCanvas()->flush();
        fNeedImageUpdate = false;
<<<<<<< HEAD
        Q_EMIT drawComplete();
    }

    SkPixmap pixmap;

    if (fSurface->peekPixels(&pixmap)) {
        QImage image(reinterpret_cast<const uchar*>(pixmap.addr()),
            pixmap.width(),
            pixmap.height(),
            pixmap.rowBytes(),
            QImage::Format_ARGB32_Premultiplied);
=======
        emit drawComplete();
    }

    SkImageInfo info;
    size_t rowBytes;
    if (const void* pixels = fSurface->peekPixels(&info, &rowBytes)) {
        QImage image(reinterpret_cast<const uchar*>(pixels),
                     info.width(),
                     info.height(),
                     rowBytes,
                     QImage::Format_ARGB32_Premultiplied);
>>>>>>> miniblink49
#if SK_R32_SHIFT == 0
        painter.drawImage(this->contentsRect(), image.rgbSwapped());
#else
        painter.drawImage(this->contentsRect(), image);
#endif
    }
}

<<<<<<< HEAD
void SkRasterWidget::updateImage()
{
=======
void SkRasterWidget::updateImage() {
>>>>>>> miniblink49
    if (!fSurface) {
        return;
    }
    fNeedImageUpdate = true;
    this->update();
}
