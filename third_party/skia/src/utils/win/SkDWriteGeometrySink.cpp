/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkTypes.h"
<<<<<<< HEAD
#if defined(SK_BUILD_FOR_WIN32)
=======
>>>>>>> miniblink49

#include "SkDWriteGeometrySink.h"
#include "SkFloatUtils.h"
#include "SkPath.h"

<<<<<<< HEAD
#include <d2d1.h>
#include <dwrite.h>

SkDWriteGeometrySink::SkDWriteGeometrySink(SkPath* path)
    : fRefCount(1)
    , fPath(path)
{
}

SkDWriteGeometrySink::~SkDWriteGeometrySink() { }

HRESULT STDMETHODCALLTYPE SkDWriteGeometrySink::QueryInterface(REFIID iid, void** object)
{
    if (nullptr == object) {
=======
#include <dwrite.h>
#include <d2d1.h>

SkDWriteGeometrySink::SkDWriteGeometrySink(SkPath* path) : fRefCount(1), fPath(path) { }

SkDWriteGeometrySink::~SkDWriteGeometrySink() { }

HRESULT STDMETHODCALLTYPE SkDWriteGeometrySink::QueryInterface(REFIID iid, void **object) {
    if (NULL == object) {
>>>>>>> miniblink49
        return E_INVALIDARG;
    }
    if (iid == __uuidof(IUnknown) || iid == __uuidof(IDWriteGeometrySink)) {
        *object = static_cast<IDWriteGeometrySink*>(this);
        this->AddRef();
        return S_OK;
    } else {
<<<<<<< HEAD
        *object = nullptr;
=======
        *object = NULL;
>>>>>>> miniblink49
        return E_NOINTERFACE;
    }
}

<<<<<<< HEAD
ULONG STDMETHODCALLTYPE SkDWriteGeometrySink::AddRef(void)
{
    return static_cast<ULONG>(InterlockedIncrement(&fRefCount));
}

ULONG STDMETHODCALLTYPE SkDWriteGeometrySink::Release(void)
{
=======
ULONG STDMETHODCALLTYPE SkDWriteGeometrySink::AddRef(void) {
    return static_cast<ULONG>(InterlockedIncrement(&fRefCount));
}

ULONG STDMETHODCALLTYPE SkDWriteGeometrySink::Release(void) {
>>>>>>> miniblink49
    ULONG res = static_cast<ULONG>(InterlockedDecrement(&fRefCount));
    if (0 == res) {
        delete this;
    }
    return res;
}

<<<<<<< HEAD
void STDMETHODCALLTYPE SkDWriteGeometrySink::SetFillMode(D2D1_FILL_MODE fillMode)
{
=======
void STDMETHODCALLTYPE SkDWriteGeometrySink::SetFillMode(D2D1_FILL_MODE fillMode) {
>>>>>>> miniblink49
    switch (fillMode) {
    case D2D1_FILL_MODE_ALTERNATE:
        fPath->setFillType(SkPath::kEvenOdd_FillType);
        break;
    case D2D1_FILL_MODE_WINDING:
        fPath->setFillType(SkPath::kWinding_FillType);
        break;
    default:
        SkDEBUGFAIL("Unknown D2D1_FILL_MODE.");
        break;
    }
}

<<<<<<< HEAD
void STDMETHODCALLTYPE SkDWriteGeometrySink::SetSegmentFlags(D2D1_PATH_SEGMENT vertexFlags)
{
=======
void STDMETHODCALLTYPE SkDWriteGeometrySink::SetSegmentFlags(D2D1_PATH_SEGMENT vertexFlags) {
>>>>>>> miniblink49
    if (vertexFlags == D2D1_PATH_SEGMENT_NONE || vertexFlags == D2D1_PATH_SEGMENT_FORCE_ROUND_LINE_JOIN) {
        SkDEBUGFAIL("Invalid D2D1_PATH_SEGMENT value.");
    }
}

<<<<<<< HEAD
void STDMETHODCALLTYPE SkDWriteGeometrySink::BeginFigure(D2D1_POINT_2F startPoint, D2D1_FIGURE_BEGIN figureBegin)
{
=======
void STDMETHODCALLTYPE SkDWriteGeometrySink::BeginFigure(D2D1_POINT_2F startPoint, D2D1_FIGURE_BEGIN figureBegin) {
>>>>>>> miniblink49
    fPath->moveTo(startPoint.x, startPoint.y);
    if (figureBegin == D2D1_FIGURE_BEGIN_HOLLOW) {
        SkDEBUGFAIL("Invalid D2D1_FIGURE_BEGIN value.");
    }
}

<<<<<<< HEAD
void STDMETHODCALLTYPE SkDWriteGeometrySink::AddLines(const D2D1_POINT_2F* points, UINT pointsCount)
{
    for (const D2D1_POINT_2F* end = &points[pointsCount]; points < end; ++points) {
=======
void STDMETHODCALLTYPE SkDWriteGeometrySink::AddLines(const D2D1_POINT_2F *points, UINT pointsCount) {
    for (const D2D1_POINT_2F *end = &points[pointsCount]; points < end; ++points) {
>>>>>>> miniblink49
        fPath->lineTo(points->x, points->y);
    }
}

<<<<<<< HEAD
static bool approximately_equal(float a, float b)
{
=======
static bool approximately_equal(float a, float b) {
>>>>>>> miniblink49
    const SkFloatingPoint<float, 10> lhs(a), rhs(b);
    return lhs.AlmostEquals(rhs);
}

typedef struct {
    float x;
    float y;
} Cubic[4], Quadratic[3];

<<<<<<< HEAD
static bool check_quadratic(const Cubic& cubic, Quadratic& reduction)
{
=======
static bool check_quadratic(const Cubic& cubic, Quadratic& reduction) {
>>>>>>> miniblink49
    float dx10 = cubic[1].x - cubic[0].x;
    float dx23 = cubic[2].x - cubic[3].x;
    float midX = cubic[0].x + dx10 * 3 / 2;
    //NOTE: !approximately_equal(midX - cubic[3].x, dx23 * 3 / 2)
    //does not work as subnormals get in between the left side and 0.
    if (!approximately_equal(midX, (dx23 * 3 / 2) + cubic[3].x)) {
        return false;
    }
    float dy10 = cubic[1].y - cubic[0].y;
    float dy23 = cubic[2].y - cubic[3].y;
    float midY = cubic[0].y + dy10 * 3 / 2;
    if (!approximately_equal(midY, (dy23 * 3 / 2) + cubic[3].y)) {
        return false;
    }
    reduction[0] = cubic[0];
    reduction[1].x = midX;
    reduction[1].y = midY;
    reduction[2] = cubic[3];
    return true;
}

<<<<<<< HEAD
void STDMETHODCALLTYPE SkDWriteGeometrySink::AddBeziers(const D2D1_BEZIER_SEGMENT* beziers, UINT beziersCount)
{
=======
void STDMETHODCALLTYPE SkDWriteGeometrySink::AddBeziers(const D2D1_BEZIER_SEGMENT *beziers, UINT beziersCount) {
>>>>>>> miniblink49
    SkPoint lastPt;
    fPath->getLastPt(&lastPt);
    D2D1_POINT_2F prevPt = { SkScalarToFloat(lastPt.fX), SkScalarToFloat(lastPt.fY) };

<<<<<<< HEAD
    for (const D2D1_BEZIER_SEGMENT* end = &beziers[beziersCount]; beziers < end; ++beziers) {
        Cubic cubic = {
            { prevPt.x, prevPt.y },
            { beziers->point1.x, beziers->point1.y },
            { beziers->point2.x, beziers->point2.y },
            { beziers->point3.x, beziers->point3.y },
        };
        Quadratic quadratic;
        if (check_quadratic(cubic, quadratic)) {
            fPath->quadTo(quadratic[1].x, quadratic[1].y,
                quadratic[2].x, quadratic[2].y);
        } else {
            fPath->cubicTo(beziers->point1.x, beziers->point1.y,
                beziers->point2.x, beziers->point2.y,
                beziers->point3.x, beziers->point3.y);
=======
    for (const D2D1_BEZIER_SEGMENT *end = &beziers[beziersCount]; beziers < end; ++beziers) {
        Cubic cubic = { { prevPt.x, prevPt.y },
                        { beziers->point1.x, beziers->point1.y },
                        { beziers->point2.x, beziers->point2.y },
                        { beziers->point3.x, beziers->point3.y }, };
        Quadratic quadratic;
        if (check_quadratic(cubic, quadratic)) {
            fPath->quadTo(quadratic[1].x, quadratic[1].y,
                          quadratic[2].x, quadratic[2].y);
        } else {
            fPath->cubicTo(beziers->point1.x, beziers->point1.y,
                           beziers->point2.x, beziers->point2.y,
                           beziers->point3.x, beziers->point3.y);
>>>>>>> miniblink49
        }
        prevPt = beziers->point3;
    }
}

<<<<<<< HEAD
void STDMETHODCALLTYPE SkDWriteGeometrySink::EndFigure(D2D1_FIGURE_END figureEnd)
{
    fPath->close();
}

HRESULT SkDWriteGeometrySink::Close()
{
    return S_OK;
}

HRESULT SkDWriteGeometrySink::Create(SkPath* path, IDWriteGeometrySink** geometryToPath)
{
    *geometryToPath = new SkDWriteGeometrySink(path);
    return S_OK;
}

#endif //defined(SK_BUILD_FOR_WIN32)
=======
void STDMETHODCALLTYPE SkDWriteGeometrySink::EndFigure(D2D1_FIGURE_END figureEnd) {
    fPath->close();
}

HRESULT SkDWriteGeometrySink::Close() {
    return S_OK;
}

HRESULT SkDWriteGeometrySink::Create(SkPath* path, IDWriteGeometrySink** geometryToPath) {
    *geometryToPath = new SkDWriteGeometrySink(path);
    return S_OK;
}
>>>>>>> miniblink49
