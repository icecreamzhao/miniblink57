/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkVertState.h"

<<<<<<< HEAD
bool VertState::Triangles(VertState* state)
{
=======
bool VertState::Triangles(VertState* state) {
>>>>>>> miniblink49
    int index = state->fCurrIndex;
    if (index + 3 > state->fCount) {
        return false;
    }
    state->f0 = index + 0;
    state->f1 = index + 1;
    state->f2 = index + 2;
    state->fCurrIndex = index + 3;
    return true;
}

<<<<<<< HEAD
bool VertState::TrianglesX(VertState* state)
{
=======
bool VertState::TrianglesX(VertState* state) {
>>>>>>> miniblink49
    const uint16_t* indices = state->fIndices;
    int index = state->fCurrIndex;
    if (index + 3 > state->fCount) {
        return false;
    }
    state->f0 = indices[index + 0];
    state->f1 = indices[index + 1];
    state->f2 = indices[index + 2];
    state->fCurrIndex = index + 3;
    return true;
}

<<<<<<< HEAD
bool VertState::TriangleStrip(VertState* state)
{
=======
bool VertState::TriangleStrip(VertState* state) {
>>>>>>> miniblink49
    int index = state->fCurrIndex;
    if (index + 3 > state->fCount) {
        return false;
    }
    state->f2 = index + 2;
    if (index & 1) {
        state->f0 = index + 1;
        state->f1 = index + 0;
    } else {
        state->f0 = index + 0;
        state->f1 = index + 1;
    }
    state->fCurrIndex = index + 1;
    return true;
}

<<<<<<< HEAD
bool VertState::TriangleStripX(VertState* state)
{
=======
bool VertState::TriangleStripX(VertState* state) {
>>>>>>> miniblink49
    const uint16_t* indices = state->fIndices;
    int index = state->fCurrIndex;
    if (index + 3 > state->fCount) {
        return false;
    }
    state->f2 = indices[index + 2];
    if (index & 1) {
        state->f0 = indices[index + 1];
        state->f1 = indices[index + 0];
    } else {
        state->f0 = indices[index + 0];
        state->f1 = indices[index + 1];
    }
    state->fCurrIndex = index + 1;
    return true;
}

<<<<<<< HEAD
bool VertState::TriangleFan(VertState* state)
{
=======
bool VertState::TriangleFan(VertState* state) {
>>>>>>> miniblink49
    int index = state->fCurrIndex;
    if (index + 3 > state->fCount) {
        return false;
    }
    state->f0 = 0;
    state->f1 = index + 1;
    state->f2 = index + 2;
    state->fCurrIndex = index + 1;
    return true;
}

<<<<<<< HEAD
bool VertState::TriangleFanX(VertState* state)
{
=======
bool VertState::TriangleFanX(VertState* state) {
>>>>>>> miniblink49
    const uint16_t* indices = state->fIndices;
    int index = state->fCurrIndex;
    if (index + 3 > state->fCount) {
        return false;
    }
    state->f0 = indices[0];
    state->f1 = indices[index + 1];
    state->f2 = indices[index + 2];
    state->fCurrIndex = index + 1;
    return true;
}

<<<<<<< HEAD
VertState::Proc VertState::chooseProc(SkCanvas::VertexMode mode)
{
    switch (mode) {
    case SkCanvas::kTriangles_VertexMode:
        return fIndices ? TrianglesX : Triangles;
    case SkCanvas::kTriangleStrip_VertexMode:
        return fIndices ? TriangleStripX : TriangleStrip;
    case SkCanvas::kTriangleFan_VertexMode:
        return fIndices ? TriangleFanX : TriangleFan;
    default:
        return nullptr;
=======
VertState::Proc VertState::chooseProc(SkCanvas::VertexMode mode) {
    switch (mode) {
        case SkCanvas::kTriangles_VertexMode:
            return fIndices ? TrianglesX : Triangles;
        case SkCanvas::kTriangleStrip_VertexMode:
            return fIndices ? TriangleStripX : TriangleStrip;
        case SkCanvas::kTriangleFan_VertexMode:
            return fIndices ? TriangleFanX : TriangleFan;
        default:
            return NULL;
>>>>>>> miniblink49
    }
}
