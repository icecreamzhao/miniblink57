<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#include "SkMeshUtils.h"
#include "SkCanvas.h"
#include "SkPaint.h"

<<<<<<< HEAD
SkMeshIndices::SkMeshIndices()
{
    sk_bzero(this, sizeof(*this));
}

SkMeshIndices::~SkMeshIndices()
{
=======
SkMeshIndices::SkMeshIndices() {
    sk_bzero(this, sizeof(*this));
}

SkMeshIndices::~SkMeshIndices() {
>>>>>>> miniblink49
    sk_free(fStorage);
}

bool SkMeshIndices::init(SkPoint tex[], uint16_t indices[],
<<<<<<< HEAD
    int texW, int texH, int rows, int cols)
{
    if (rows < 2 || cols < 2) {
        sk_free(fStorage);
        fStorage = nullptr;
        fTex = nullptr;
        fIndices = nullptr;
=======
                         int texW, int texH, int rows, int cols) {
    if (rows < 2 || cols < 2) {
        sk_free(fStorage);
        fStorage = NULL;
        fTex = NULL;
        fIndices = NULL;
>>>>>>> miniblink49
        fTexCount = fIndexCount = 0;
        return false;
    }

    sk_free(fStorage);
<<<<<<< HEAD
    fStorage = nullptr;
=======
    fStorage = NULL;
>>>>>>> miniblink49

    fTexCount = rows * cols;
    rows -= 1;
    cols -= 1;
    fIndexCount = rows * cols * 6;

    if (tex) {
        fTex = tex;
        fIndices = indices;
    } else {
<<<<<<< HEAD
        fStorage = sk_malloc_throw(fTexCount * sizeof(SkPoint) + fIndexCount * sizeof(uint16_t));
=======
        fStorage = sk_malloc_throw(fTexCount * sizeof(SkPoint) +
                                   fIndexCount * sizeof(uint16_t));
>>>>>>> miniblink49
        fTex = (SkPoint*)fStorage;
        fIndices = (uint16_t*)(fTex + fTexCount);
    }

    // compute the indices
    {
        uint16_t* idx = fIndices;
        int index = 0;
        for (int y = 0; y < cols; y++) {
            for (int x = 0; x < rows; x++) {
                *idx++ = index;
                *idx++ = index + rows + 1;
                *idx++ = index + 1;

                *idx++ = index + 1;
                *idx++ = index + rows + 1;
                *idx++ = index + rows + 2;

                index += 1;
            }
            index += 1;
        }
    }

    // compute texture coordinates
    {
        SkPoint* tex = fTex;
        const SkScalar dx = SkIntToScalar(texW) / rows;
        const SkScalar dy = SkIntToScalar(texH) / cols;
        for (int y = 0; y <= cols; y++) {
            for (int x = 0; x <= rows; x++) {
<<<<<<< HEAD
                tex->set(x * dx, y * dy);
=======
                tex->set(x*dx, y*dy);
>>>>>>> miniblink49
                tex += 1;
            }
        }
    }
    return true;
}

///////////////////////////////////////////////////////////////////////////////

#include "SkShader.h"

void SkMeshUtils::Draw(SkCanvas* canvas, const SkBitmap& bitmap,
<<<<<<< HEAD
    int rows, int cols, const SkPoint verts[],
    const SkColor colors[], const SkPaint& paint)
{
=======
                       int rows, int cols, const SkPoint verts[],
                       const SkColor colors[], const SkPaint& paint) {
>>>>>>> miniblink49
    SkMeshIndices idx;

    if (idx.init(bitmap.width(), bitmap.height(), rows, cols)) {
        SkPaint p(paint);
<<<<<<< HEAD
        p.setShader(SkShader::MakeBitmapShader(bitmap,
            SkShader::kClamp_TileMode,
            SkShader::kClamp_TileMode));
        canvas->drawVertices(SkCanvas::kTriangles_VertexMode,
            rows * cols, verts, idx.tex(), colors, nullptr,
            idx.indices(), idx.indexCount(), p);
=======
        p.setShader(SkShader::CreateBitmapShader(bitmap,
                                         SkShader::kClamp_TileMode,
                                         SkShader::kClamp_TileMode))->unref();
        canvas->drawVertices(SkCanvas::kTriangles_VertexMode,
                             rows * cols, verts, idx.tex(), colors, NULL,
                             idx.indices(), idx.indexCount(), p);
>>>>>>> miniblink49
    }
}
