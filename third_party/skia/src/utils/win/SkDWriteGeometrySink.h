/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkDWriteToPath_DEFINED
#define SkDWriteToPath_DEFINED

#include "SkTypes.h"

class SkPath;

<<<<<<< HEAD
#include <d2d1.h>
#include <dwrite.h>
=======
#include <dwrite.h>
#include <d2d1.h>
>>>>>>> miniblink49

class SkDWriteGeometrySink : public IDWriteGeometrySink {
private:
    LONG fRefCount;
    SkPath* fPath;

    SkDWriteGeometrySink(const SkDWriteGeometrySink&);
    SkDWriteGeometrySink& operator=(const SkDWriteGeometrySink&);

protected:
    explicit SkDWriteGeometrySink(SkPath* path);
    virtual ~SkDWriteGeometrySink();

public:
<<<<<<< HEAD
    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID iid, void** object) override;
=======
    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID iid, void **object) override;
>>>>>>> miniblink49
    ULONG STDMETHODCALLTYPE AddRef(void) override;
    ULONG STDMETHODCALLTYPE Release(void) override;

    void STDMETHODCALLTYPE SetFillMode(D2D1_FILL_MODE fillMode) override;
    void STDMETHODCALLTYPE SetSegmentFlags(D2D1_PATH_SEGMENT vertexFlags) override;
    void STDMETHODCALLTYPE BeginFigure(D2D1_POINT_2F startPoint, D2D1_FIGURE_BEGIN figureBegin) override;
<<<<<<< HEAD
    void STDMETHODCALLTYPE AddLines(const D2D1_POINT_2F* points, UINT pointsCount) override;
    void STDMETHODCALLTYPE AddBeziers(const D2D1_BEZIER_SEGMENT* beziers, UINT beziersCount) override;
=======
    void STDMETHODCALLTYPE AddLines(const D2D1_POINT_2F *points, UINT pointsCount) override;
    void STDMETHODCALLTYPE AddBeziers(const D2D1_BEZIER_SEGMENT *beziers, UINT beziersCount) override;
>>>>>>> miniblink49
    void STDMETHODCALLTYPE EndFigure(D2D1_FIGURE_END figureEnd) override;
    HRESULT STDMETHODCALLTYPE Close() override;

    static HRESULT Create(SkPath* path, IDWriteGeometrySink** geometryToPath);
};

#endif
