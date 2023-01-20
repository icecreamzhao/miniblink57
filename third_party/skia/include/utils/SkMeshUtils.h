
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#ifndef SkMeshUtils_DEFINED
#define SkMeshUtils_DEFINED

<<<<<<< HEAD
#include "SkColor.h"
#include "SkPoint.h"
=======
#include "SkPoint.h"
#include "SkColor.h"
>>>>>>> miniblink49

class SkBitmap;
class SkCanvas;
class SkPaint;

class SkMeshIndices {
public:
    SkMeshIndices();
    ~SkMeshIndices();

<<<<<<< HEAD
    bool init(int texW, int texH, int rows, int cols)
    {
=======
    bool init(int texW, int texH, int rows, int cols) {
>>>>>>> miniblink49
        return this->init(NULL, NULL, texW, texH, rows, cols);
    }

    bool init(SkPoint tex[], uint16_t indices[],
<<<<<<< HEAD
        int texW, int texH, int rows, int cols);

    int indexCount() const { return fIndexCount; }
    const uint16_t* indices() const { return fIndices; }

    size_t texCount() const { return fTexCount; }
    const SkPoint* tex() const { return fTex; }

private:
    int fIndexCount, fTexCount;
    SkPoint* fTex;
    uint16_t* fIndices;
    void* fStorage; // may be null
=======
              int texW, int texH, int rows, int cols);

    int             indexCount() const { return fIndexCount; }
    const uint16_t* indices() const { return fIndices; }

    size_t          texCount() const { return fTexCount; }
    const SkPoint*  tex() const { return fTex; }

private:
    int         fIndexCount, fTexCount;
    SkPoint*    fTex;
    uint16_t*   fIndices;
    void*       fStorage; // may be null
>>>>>>> miniblink49
};

class SkMeshUtils {
public:
    static void Draw(SkCanvas*, const SkBitmap&, int rows, int cols,
<<<<<<< HEAD
        const SkPoint verts[], const SkColor colors[],
        const SkPaint& paint);
=======
                     const SkPoint verts[], const SkColor colors[],
                     const SkPaint& paint);
>>>>>>> miniblink49
};

#endif
