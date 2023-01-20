<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#include "SkNWayCanvas.h"

SkNWayCanvas::SkNWayCanvas(int width, int height)
<<<<<<< HEAD
    : INHERITED(width, height)
{
}

SkNWayCanvas::~SkNWayCanvas()
{
    this->removeAll();
}

void SkNWayCanvas::addCanvas(SkCanvas* canvas)
{
=======
        : INHERITED(width, height) {}

SkNWayCanvas::~SkNWayCanvas() {
    this->removeAll();
}

void SkNWayCanvas::addCanvas(SkCanvas* canvas) {
>>>>>>> miniblink49
    if (canvas) {
        canvas->ref();
        *fList.append() = canvas;
    }
}

<<<<<<< HEAD
void SkNWayCanvas::removeCanvas(SkCanvas* canvas)
{
=======
void SkNWayCanvas::removeCanvas(SkCanvas* canvas) {
>>>>>>> miniblink49
    int index = fList.find(canvas);
    if (index >= 0) {
        canvas->unref();
        fList.removeShuffle(index);
    }
}

<<<<<<< HEAD
void SkNWayCanvas::removeAll()
{
=======
void SkNWayCanvas::removeAll() {
>>>>>>> miniblink49
    fList.unrefAll();
    fList.reset();
}

///////////////////////////////////////////////////////////////////////////
// These are forwarded to the N canvases we're referencing

class SkNWayCanvas::Iter {
public:
<<<<<<< HEAD
    Iter(const SkTDArray<SkCanvas*>& list)
        : fList(list)
    {
        fIndex = 0;
    }
    bool next()
    {
=======
    Iter(const SkTDArray<SkCanvas*>& list) : fList(list) {
        fIndex = 0;
    }
    bool next() {
>>>>>>> miniblink49
        if (fIndex < fList.count()) {
            fCanvas = fList[fIndex++];
            return true;
        }
        return false;
    }
    SkCanvas* operator->() { return fCanvas; }

private:
    const SkTDArray<SkCanvas*>& fList;
    int fIndex;
    SkCanvas* fCanvas;
};

<<<<<<< HEAD
void SkNWayCanvas::willSave()
{
=======
void SkNWayCanvas::willSave() {
>>>>>>> miniblink49
    Iter iter(fList);
    while (iter.next()) {
        iter->save();
    }

    this->INHERITED::willSave();
}

<<<<<<< HEAD
SkCanvas::SaveLayerStrategy SkNWayCanvas::getSaveLayerStrategy(const SaveLayerRec& rec)
{
    Iter iter(fList);
    while (iter.next()) {
        iter->saveLayer(rec);
    }

    this->INHERITED::getSaveLayerStrategy(rec);
=======
SkCanvas::SaveLayerStrategy SkNWayCanvas::willSaveLayer(const SkRect* bounds, const SkPaint* paint,
                                                        SaveFlags flags) {
    Iter iter(fList);
    while (iter.next()) {
        iter->saveLayer(bounds, paint, flags);
    }

    this->INHERITED::willSaveLayer(bounds, paint, flags);
>>>>>>> miniblink49
    // No need for a layer.
    return kNoLayer_SaveLayerStrategy;
}

<<<<<<< HEAD
void SkNWayCanvas::willRestore()
{
=======
void SkNWayCanvas::willRestore() {
>>>>>>> miniblink49
    Iter iter(fList);
    while (iter.next()) {
        iter->restore();
    }
    this->INHERITED::willRestore();
}

<<<<<<< HEAD
void SkNWayCanvas::didConcat(const SkMatrix& matrix)
{
=======
void SkNWayCanvas::didConcat(const SkMatrix& matrix) {
>>>>>>> miniblink49
    Iter iter(fList);
    while (iter.next()) {
        iter->concat(matrix);
    }
    this->INHERITED::didConcat(matrix);
}

<<<<<<< HEAD
void SkNWayCanvas::didSetMatrix(const SkMatrix& matrix)
{
=======
void SkNWayCanvas::didSetMatrix(const SkMatrix& matrix) {
>>>>>>> miniblink49
    Iter iter(fList);
    while (iter.next()) {
        iter->setMatrix(matrix);
    }
    this->INHERITED::didSetMatrix(matrix);
}

<<<<<<< HEAD
void SkNWayCanvas::onClipRect(const SkRect& rect, SkRegion::Op op, ClipEdgeStyle edgeStyle)
{
=======
void SkNWayCanvas::onClipRect(const SkRect& rect, SkRegion::Op op, ClipEdgeStyle edgeStyle) {
>>>>>>> miniblink49
    Iter iter(fList);
    while (iter.next()) {
        iter->clipRect(rect, op, kSoft_ClipEdgeStyle == edgeStyle);
    }
    this->INHERITED::onClipRect(rect, op, edgeStyle);
}

<<<<<<< HEAD
void SkNWayCanvas::onClipRRect(const SkRRect& rrect, SkRegion::Op op, ClipEdgeStyle edgeStyle)
{
=======
void SkNWayCanvas::onClipRRect(const SkRRect& rrect, SkRegion::Op op, ClipEdgeStyle edgeStyle) {
>>>>>>> miniblink49
    Iter iter(fList);
    while (iter.next()) {
        iter->clipRRect(rrect, op, kSoft_ClipEdgeStyle == edgeStyle);
    }
    this->INHERITED::onClipRRect(rrect, op, edgeStyle);
}

<<<<<<< HEAD
void SkNWayCanvas::onClipPath(const SkPath& path, SkRegion::Op op, ClipEdgeStyle edgeStyle)
{
=======
void SkNWayCanvas::onClipPath(const SkPath& path, SkRegion::Op op, ClipEdgeStyle edgeStyle) {
>>>>>>> miniblink49
    Iter iter(fList);
    while (iter.next()) {
        iter->clipPath(path, op, kSoft_ClipEdgeStyle == edgeStyle);
    }
    this->INHERITED::onClipPath(path, op, edgeStyle);
}

<<<<<<< HEAD
void SkNWayCanvas::onClipRegion(const SkRegion& deviceRgn, SkRegion::Op op)
{
=======
void SkNWayCanvas::onClipRegion(const SkRegion& deviceRgn, SkRegion::Op op) {
>>>>>>> miniblink49
    Iter iter(fList);
    while (iter.next()) {
        iter->clipRegion(deviceRgn, op);
    }
    this->INHERITED::onClipRegion(deviceRgn, op);
}

<<<<<<< HEAD
void SkNWayCanvas::onDrawPaint(const SkPaint& paint)
{
=======
void SkNWayCanvas::onDrawPaint(const SkPaint& paint) {
>>>>>>> miniblink49
    Iter iter(fList);
    while (iter.next()) {
        iter->drawPaint(paint);
    }
}

void SkNWayCanvas::onDrawPoints(PointMode mode, size_t count, const SkPoint pts[],
<<<<<<< HEAD
    const SkPaint& paint)
{
=======
                                const SkPaint& paint) {
>>>>>>> miniblink49
    Iter iter(fList);
    while (iter.next()) {
        iter->drawPoints(mode, count, pts, paint);
    }
}

<<<<<<< HEAD
void SkNWayCanvas::onDrawRect(const SkRect& rect, const SkPaint& paint)
{
=======
void SkNWayCanvas::onDrawRect(const SkRect& rect, const SkPaint& paint) {
>>>>>>> miniblink49
    Iter iter(fList);
    while (iter.next()) {
        iter->drawRect(rect, paint);
    }
}

<<<<<<< HEAD
void SkNWayCanvas::onDrawOval(const SkRect& rect, const SkPaint& paint)
{
=======
void SkNWayCanvas::onDrawOval(const SkRect& rect, const SkPaint& paint) {
>>>>>>> miniblink49
    Iter iter(fList);
    while (iter.next()) {
        iter->drawOval(rect, paint);
    }
}

<<<<<<< HEAD
void SkNWayCanvas::onDrawRRect(const SkRRect& rrect, const SkPaint& paint)
{
=======
void SkNWayCanvas::onDrawRRect(const SkRRect& rrect, const SkPaint& paint) {
>>>>>>> miniblink49
    Iter iter(fList);
    while (iter.next()) {
        iter->drawRRect(rrect, paint);
    }
}

<<<<<<< HEAD
void SkNWayCanvas::onDrawDRRect(const SkRRect& outer, const SkRRect& inner, const SkPaint& paint)
{
=======
void SkNWayCanvas::onDrawDRRect(const SkRRect& outer, const SkRRect& inner,
                                const SkPaint& paint) {
>>>>>>> miniblink49
    Iter iter(fList);
    while (iter.next()) {
        iter->drawDRRect(outer, inner, paint);
    }
}

<<<<<<< HEAD
void SkNWayCanvas::onDrawPath(const SkPath& path, const SkPaint& paint)
{
=======
void SkNWayCanvas::onDrawPath(const SkPath& path, const SkPaint& paint) {
>>>>>>> miniblink49
    Iter iter(fList);
    while (iter.next()) {
        iter->drawPath(path, paint);
    }
}

void SkNWayCanvas::onDrawBitmap(const SkBitmap& bitmap, SkScalar x, SkScalar y,
<<<<<<< HEAD
    const SkPaint* paint)
{
=======
                                const SkPaint* paint) {
>>>>>>> miniblink49
    Iter iter(fList);
    while (iter.next()) {
        iter->drawBitmap(bitmap, x, y, paint);
    }
}

void SkNWayCanvas::onDrawBitmapRect(const SkBitmap& bitmap, const SkRect* src, const SkRect& dst,
<<<<<<< HEAD
    const SkPaint* paint, SrcRectConstraint constraint)
{
    Iter iter(fList);
    while (iter.next()) {
        iter->legacy_drawBitmapRect(bitmap, src, dst, paint, (SrcRectConstraint)constraint);
=======
                                    const SkPaint* paint, DrawBitmapRectFlags flags) {
    Iter iter(fList);
    while (iter.next()) {
        iter->drawBitmapRectToRect(bitmap, src, dst, paint, flags);
>>>>>>> miniblink49
    }
}

void SkNWayCanvas::onDrawBitmapNine(const SkBitmap& bitmap, const SkIRect& center,
<<<<<<< HEAD
    const SkRect& dst, const SkPaint* paint)
{
=======
                                    const SkRect& dst, const SkPaint* paint) {
>>>>>>> miniblink49
    Iter iter(fList);
    while (iter.next()) {
        iter->drawBitmapNine(bitmap, center, dst, paint);
    }
}

void SkNWayCanvas::onDrawImage(const SkImage* image, SkScalar left, SkScalar top,
<<<<<<< HEAD
    const SkPaint* paint)
{
=======
                               const SkPaint* paint) {
>>>>>>> miniblink49
    Iter iter(fList);
    while (iter.next()) {
        iter->drawImage(image, left, top, paint);
    }
}

void SkNWayCanvas::onDrawImageRect(const SkImage* image, const SkRect* src, const SkRect& dst,
<<<<<<< HEAD
    const SkPaint* paint, SrcRectConstraint constraint)
{
    Iter iter(fList);
    while (iter.next()) {
        iter->legacy_drawImageRect(image, src, dst, paint, constraint);
=======
                                   const SkPaint* paint) {
    Iter iter(fList);
    while (iter.next()) {
        iter->drawImageRect(image, src, dst, paint);
    }
}

void SkNWayCanvas::onDrawSprite(const SkBitmap& bitmap, int x, int y, const SkPaint* paint) {
    Iter iter(fList);
    while (iter.next()) {
        iter->drawSprite(bitmap, x, y, paint);
>>>>>>> miniblink49
    }
}

void SkNWayCanvas::onDrawText(const void* text, size_t byteLength, SkScalar x, SkScalar y,
<<<<<<< HEAD
    const SkPaint& paint)
{
=======
                              const SkPaint& paint) {
>>>>>>> miniblink49
    Iter iter(fList);
    while (iter.next()) {
        iter->drawText(text, byteLength, x, y, paint);
    }
}

void SkNWayCanvas::onDrawPosText(const void* text, size_t byteLength, const SkPoint pos[],
<<<<<<< HEAD
    const SkPaint& paint)
{
=======
                                 const SkPaint& paint) {
>>>>>>> miniblink49
    Iter iter(fList);
    while (iter.next()) {
        iter->drawPosText(text, byteLength, pos, paint);
    }
}

void SkNWayCanvas::onDrawPosTextH(const void* text, size_t byteLength, const SkScalar xpos[],
<<<<<<< HEAD
    SkScalar constY, const SkPaint& paint)
{
=======
                                  SkScalar constY, const SkPaint& paint) {
>>>>>>> miniblink49
    Iter iter(fList);
    while (iter.next()) {
        iter->drawPosTextH(text, byteLength, xpos, constY, paint);
    }
}

void SkNWayCanvas::onDrawTextOnPath(const void* text, size_t byteLength, const SkPath& path,
<<<<<<< HEAD
    const SkMatrix* matrix, const SkPaint& paint)
{
=======
                                    const SkMatrix* matrix, const SkPaint& paint) {
>>>>>>> miniblink49
    Iter iter(fList);
    while (iter.next()) {
        iter->drawTextOnPath(text, byteLength, path, matrix, paint);
    }
}

void SkNWayCanvas::onDrawTextBlob(const SkTextBlob* blob, SkScalar x, SkScalar y,
<<<<<<< HEAD
    const SkPaint& paint)
{
=======
                                  const SkPaint &paint) {
>>>>>>> miniblink49
    Iter iter(fList);
    while (iter.next()) {
        iter->drawTextBlob(blob, x, y, paint);
    }
}

void SkNWayCanvas::onDrawPicture(const SkPicture* picture, const SkMatrix* matrix,
<<<<<<< HEAD
    const SkPaint* paint)
{
=======
                                 const SkPaint* paint) {
>>>>>>> miniblink49
    Iter iter(fList);
    while (iter.next()) {
        iter->drawPicture(picture, matrix, paint);
    }
}

void SkNWayCanvas::onDrawVertices(VertexMode vmode, int vertexCount,
<<<<<<< HEAD
    const SkPoint vertices[], const SkPoint texs[],
    const SkColor colors[], SkXfermode* xmode,
    const uint16_t indices[], int indexCount,
    const SkPaint& paint)
{
    Iter iter(fList);
    while (iter.next()) {
        iter->drawVertices(vmode, vertexCount, vertices, texs, colors, xmode,
            indices, indexCount, paint);
=======
                                  const SkPoint vertices[], const SkPoint texs[],
                                  const SkColor colors[], SkXfermode* xmode,
                                  const uint16_t indices[], int indexCount,
                                  const SkPaint& paint) {
    Iter iter(fList);
    while (iter.next()) {
        iter->drawVertices(vmode, vertexCount, vertices, texs, colors, xmode,
                           indices, indexCount, paint);
>>>>>>> miniblink49
    }
}

void SkNWayCanvas::onDrawPatch(const SkPoint cubics[12], const SkColor colors[4],
<<<<<<< HEAD
    const SkPoint texCoords[4], SkXfermode* xmode,
    const SkPaint& paint)
{
=======
                               const SkPoint texCoords[4], SkXfermode* xmode,
                               const SkPaint& paint) {
>>>>>>> miniblink49
    Iter iter(fList);
    while (iter.next()) {
        iter->drawPatch(cubics, colors, texCoords, xmode, paint);
    }
}

<<<<<<< HEAD
void SkNWayCanvas::onDrawAnnotation(const SkRect& rect, const char key[], SkData* data)
{
    Iter iter(fList);
    while (iter.next()) {
        iter->drawAnnotation(rect, key, data);
    }
}

#ifdef SK_SUPPORT_LEGACY_DRAWFILTER
SkDrawFilter* SkNWayCanvas::setDrawFilter(SkDrawFilter* filter)
{
=======
SkDrawFilter* SkNWayCanvas::setDrawFilter(SkDrawFilter* filter) {
>>>>>>> miniblink49
    Iter iter(fList);
    while (iter.next()) {
        iter->setDrawFilter(filter);
    }
    return this->INHERITED::setDrawFilter(filter);
}
<<<<<<< HEAD
#endif
=======
>>>>>>> miniblink49
