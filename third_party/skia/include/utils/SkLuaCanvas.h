/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkLuaCanvas_DEFINED
#define SkLuaCanvas_DEFINED

#include "SkCanvas.h"
#include "SkString.h"

struct lua_State;

class SkLuaCanvas : public SkCanvas {
public:
    void pushThis();

    SkLuaCanvas(int width, int height, lua_State*, const char function[]);
    virtual ~SkLuaCanvas();

protected:
    void willSave() override;
<<<<<<< HEAD
    SaveLayerStrategy getSaveLayerStrategy(const SaveLayerRec&) override;
=======
    SaveLayerStrategy willSaveLayer(const SkRect*, const SkPaint*, SaveFlags) override;
>>>>>>> miniblink49
    void willRestore() override;

    void didConcat(const SkMatrix&) override;
    void didSetMatrix(const SkMatrix&) override;

    void onDrawDRRect(const SkRRect&, const SkRRect&, const SkPaint&) override;
    virtual void onDrawText(const void* text, size_t byteLength, SkScalar x, SkScalar y,
<<<<<<< HEAD
        const SkPaint&) override;
    virtual void onDrawPosText(const void* text, size_t byteLength, const SkPoint pos[],
        const SkPaint&) override;
    virtual void onDrawPosTextH(const void* text, size_t byteLength, const SkScalar xpos[],
        SkScalar constY, const SkPaint&) override;
    virtual void onDrawTextOnPath(const void* text, size_t byteLength, const SkPath& path,
        const SkMatrix* matrix, const SkPaint&) override;
    virtual void onDrawTextBlob(const SkTextBlob* blob, SkScalar x, SkScalar y,
        const SkPaint& paint) override;
=======
                            const SkPaint&) override;
    virtual void onDrawPosText(const void* text, size_t byteLength, const SkPoint pos[],
                               const SkPaint&) override;
    virtual void onDrawPosTextH(const void* text, size_t byteLength, const SkScalar xpos[],
                                SkScalar constY, const SkPaint&) override;
    virtual void onDrawTextOnPath(const void* text, size_t byteLength, const SkPath& path,
                                  const SkMatrix* matrix, const SkPaint&) override;
    virtual void onDrawTextBlob(const SkTextBlob* blob, SkScalar x, SkScalar y,
                                const SkPaint& paint) override;
>>>>>>> miniblink49

    void onDrawPaint(const SkPaint&) override;
    void onDrawPoints(PointMode, size_t count, const SkPoint pts[], const SkPaint&) override;
    void onDrawRect(const SkRect&, const SkPaint&) override;
    void onDrawOval(const SkRect&, const SkPaint&) override;
    void onDrawRRect(const SkRRect&, const SkPaint&) override;
    void onDrawPath(const SkPath&, const SkPaint&) override;
    void onDrawBitmap(const SkBitmap&, SkScalar left, SkScalar top, const SkPaint*) override;
    void onDrawBitmapRect(const SkBitmap&, const SkRect* src, const SkRect& dst, const SkPaint*,
<<<<<<< HEAD
        SrcRectConstraint) override;
    void onDrawImage(const SkImage*, SkScalar left, SkScalar top, const SkPaint*) override;
    void onDrawImageRect(const SkImage*, const SkRect* src, const SkRect& dst,
        const SkPaint*, SrcRectConstraint) override;
    void onDrawBitmapNine(const SkBitmap&, const SkIRect& center, const SkRect& dst,
        const SkPaint*) override;
    void onDrawVertices(VertexMode vmode, int vertexCount,
        const SkPoint vertices[], const SkPoint texs[],
        const SkColor colors[], SkXfermode* xmode,
        const uint16_t indices[], int indexCount,
        const SkPaint&) override;
=======
                          DrawBitmapRectFlags flags) override;
    void onDrawImage(const SkImage*, SkScalar left, SkScalar top, const SkPaint*) override;
    void onDrawImageRect(const SkImage*, const SkRect* src, const SkRect& dst,
                         const SkPaint*) override;
    void onDrawBitmapNine(const SkBitmap&, const SkIRect& center, const SkRect& dst,
                          const SkPaint*) override;
    void onDrawSprite(const SkBitmap&, int left, int top, const SkPaint*) override;
    void onDrawVertices(VertexMode vmode, int vertexCount,
                        const SkPoint vertices[], const SkPoint texs[],
                        const SkColor colors[], SkXfermode* xmode,
                        const uint16_t indices[], int indexCount,
                        const SkPaint&) override;
>>>>>>> miniblink49

    void onClipRect(const SkRect&, SkRegion::Op, ClipEdgeStyle) override;
    void onClipRRect(const SkRRect&, SkRegion::Op, ClipEdgeStyle) override;
    void onClipPath(const SkPath&, SkRegion::Op, ClipEdgeStyle) override;
    void onClipRegion(const SkRegion&, SkRegion::Op) override;

    void onDrawPicture(const SkPicture*, const SkMatrix*, const SkPaint*) override;

private:
<<<<<<< HEAD
    lua_State* fL;
    SkString fFunc;
=======
    lua_State*  fL;
    SkString    fFunc;
>>>>>>> miniblink49

    void sendverb(const char verb[]);

    typedef SkCanvas INHERITED;
};

#endif
