<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#include "SkCanvasStack.h"

SkCanvasStack::SkCanvasStack(int width, int height)
<<<<<<< HEAD
    : INHERITED(width, height)
{
}

SkCanvasStack::~SkCanvasStack()
{
    this->removeAll();
}

void SkCanvasStack::pushCanvas(SkCanvas* canvas, const SkIPoint& origin)
{
=======
        : INHERITED(width, height) {}

SkCanvasStack::~SkCanvasStack() {
    this->removeAll();
}

void SkCanvasStack::pushCanvas(SkCanvas* canvas, const SkIPoint& origin) {
>>>>>>> miniblink49
    if (canvas) {
        // compute the bounds of this canvas
        const SkIRect canvasBounds = SkIRect::MakeSize(canvas->getDeviceSize());

        // push the canvas onto the stack
        this->INHERITED::addCanvas(canvas);

        // push the canvas data onto the stack
        CanvasData* data = &fCanvasData.push_back();
        data->origin = origin;
        data->requiredClip.setRect(canvasBounds);

        // subtract this region from the canvas objects already on the stack.
        // This ensures they do not draw into the space occupied by the layers
        // above them.
        for (int i = fList.count() - 1; i > 0; --i) {
            SkIRect localBounds = canvasBounds;
<<<<<<< HEAD
            localBounds.offset(origin - fCanvasData[i - 1].origin);

            fCanvasData[i - 1].requiredClip.op(localBounds, SkRegion::kDifference_Op);
            fList[i - 1]->clipRegion(fCanvasData[i - 1].requiredClip);
=======
            localBounds.offset(origin - fCanvasData[i-1].origin);

            fCanvasData[i-1].requiredClip.op(localBounds, SkRegion::kDifference_Op);
            fList[i-1]->clipRegion(fCanvasData[i-1].requiredClip);
>>>>>>> miniblink49
        }
    }
    SkASSERT(fList.count() == fCanvasData.count());
}

<<<<<<< HEAD
void SkCanvasStack::removeAll()
{
=======
void SkCanvasStack::removeAll() {
>>>>>>> miniblink49
    fCanvasData.reset();
    this->INHERITED::removeAll();
}

/**
 * Traverse all canvases (e.g. layers) the stack and ensure that they are clipped
 * to their bounds and that the area covered by any canvas higher in the stack is
 * also clipped out.
 */
<<<<<<< HEAD
void SkCanvasStack::clipToZOrderedBounds()
{
=======
void SkCanvasStack::clipToZOrderedBounds() {
>>>>>>> miniblink49
    SkASSERT(fList.count() == fCanvasData.count());
    for (int i = 0; i < fList.count(); ++i) {
        fList[i]->clipRegion(fCanvasData[i].requiredClip, SkRegion::kIntersect_Op);
    }
}

////////////////////////////////////////////////////////////////////////////////

/**
 * We need to handle setMatrix specially as it overwrites the matrix in each
 * canvas unlike all other matrix operations (i.e. translate, scale, etc) which
 * just pre-concatenate with the existing matrix.
 */
<<<<<<< HEAD
void SkCanvasStack::didSetMatrix(const SkMatrix& matrix)
{
=======
void SkCanvasStack::didSetMatrix(const SkMatrix& matrix) {
>>>>>>> miniblink49
    SkASSERT(fList.count() == fCanvasData.count());
    for (int i = 0; i < fList.count(); ++i) {

        SkMatrix tempMatrix = matrix;
        tempMatrix.postTranslate(SkIntToScalar(-fCanvasData[i].origin.x()),
<<<<<<< HEAD
            SkIntToScalar(-fCanvasData[i].origin.y()));
=======
                                 SkIntToScalar(-fCanvasData[i].origin.y()));
>>>>>>> miniblink49
        fList[i]->setMatrix(tempMatrix);
    }
    this->SkCanvas::didSetMatrix(matrix);
}

<<<<<<< HEAD
void SkCanvasStack::onClipRect(const SkRect& r, SkRegion::Op op, ClipEdgeStyle edgeStyle)
{
=======
void SkCanvasStack::onClipRect(const SkRect& r, SkRegion::Op op, ClipEdgeStyle edgeStyle) {
>>>>>>> miniblink49
    this->INHERITED::onClipRect(r, op, edgeStyle);
    this->clipToZOrderedBounds();
}

<<<<<<< HEAD
void SkCanvasStack::onClipRRect(const SkRRect& rr, SkRegion::Op op, ClipEdgeStyle edgeStyle)
{
=======
void SkCanvasStack::onClipRRect(const SkRRect& rr, SkRegion::Op op, ClipEdgeStyle edgeStyle) {
>>>>>>> miniblink49
    this->INHERITED::onClipRRect(rr, op, edgeStyle);
    this->clipToZOrderedBounds();
}

<<<<<<< HEAD
void SkCanvasStack::onClipPath(const SkPath& p, SkRegion::Op op, ClipEdgeStyle edgeStyle)
{
=======
void SkCanvasStack::onClipPath(const SkPath& p, SkRegion::Op op, ClipEdgeStyle edgeStyle) {
>>>>>>> miniblink49
    this->INHERITED::onClipPath(p, op, edgeStyle);
    this->clipToZOrderedBounds();
}

<<<<<<< HEAD
void SkCanvasStack::onClipRegion(const SkRegion& deviceRgn, SkRegion::Op op)
{
=======
void SkCanvasStack::onClipRegion(const SkRegion& deviceRgn, SkRegion::Op op) {
>>>>>>> miniblink49
    SkASSERT(fList.count() == fCanvasData.count());
    for (int i = 0; i < fList.count(); ++i) {
        SkRegion tempRegion;
        deviceRgn.translate(-fCanvasData[i].origin.x(),
<<<<<<< HEAD
            -fCanvasData[i].origin.y(), &tempRegion);
=======
                            -fCanvasData[i].origin.y(), &tempRegion);
>>>>>>> miniblink49
        tempRegion.op(fCanvasData[i].requiredClip, SkRegion::kIntersect_Op);
        fList[i]->clipRegion(tempRegion, op);
    }
    this->SkCanvas::onClipRegion(deviceRgn, op);
}
