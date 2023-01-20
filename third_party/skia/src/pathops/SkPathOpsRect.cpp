/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
<<<<<<< HEAD
#include "SkPathOpsRect.h"
=======
>>>>>>> miniblink49
#include "SkPathOpsConic.h"
#include "SkPathOpsCubic.h"
#include "SkPathOpsLine.h"
#include "SkPathOpsQuad.h"
<<<<<<< HEAD

void SkDRect::setBounds(const SkDQuad& curve, const SkDQuad& sub, double startT, double endT)
{
=======
#include "SkPathOpsRect.h"

void SkDRect::setBounds(const SkDQuad& curve, const SkDQuad& sub, double startT, double endT) {
>>>>>>> miniblink49
    set(sub[0]);
    add(sub[2]);
    double tValues[2];
    int roots = 0;
    if (!sub.monotonicInX()) {
        roots = SkDQuad::FindExtrema(&sub[0].fX, tValues);
    }
    if (!sub.monotonicInY()) {
        roots += SkDQuad::FindExtrema(&sub[0].fY, &tValues[roots]);
    }
    for (int index = 0; index < roots; ++index) {
        double t = startT + (endT - startT) * tValues[index];
        add(curve.ptAtT(t));
    }
}

<<<<<<< HEAD
void SkDRect::setBounds(const SkDConic& curve, const SkDConic& sub, double startT, double endT)
{
=======
void SkDRect::setBounds(const SkDConic& curve, const SkDConic& sub, double startT, double endT) {
>>>>>>> miniblink49
    set(sub[0]);
    add(sub[2]);
    double tValues[2];
    int roots = 0;
    if (!sub.monotonicInX()) {
        roots = SkDConic::FindExtrema(&sub[0].fX, sub.fWeight, tValues);
    }
    if (!sub.monotonicInY()) {
        roots += SkDConic::FindExtrema(&sub[0].fY, sub.fWeight, &tValues[roots]);
    }
    for (int index = 0; index < roots; ++index) {
        double t = startT + (endT - startT) * tValues[index];
        add(curve.ptAtT(t));
    }
}

<<<<<<< HEAD
void SkDRect::setBounds(const SkDCubic& curve, const SkDCubic& sub, double startT, double endT)
{
=======
void SkDRect::setBounds(const SkDCubic& curve, const SkDCubic& sub, double startT, double endT) {
>>>>>>> miniblink49
    set(sub[0]);
    add(sub[3]);
    double tValues[4];
    int roots = 0;
    if (!sub.monotonicInX()) {
        roots = SkDCubic::FindExtrema(&sub[0].fX, tValues);
    }
    if (!sub.monotonicInY()) {
        roots += SkDCubic::FindExtrema(&sub[0].fY, &tValues[roots]);
    }
    for (int index = 0; index < roots; ++index) {
        double t = startT + (endT - startT) * tValues[index];
        add(curve.ptAtT(t));
    }
}
