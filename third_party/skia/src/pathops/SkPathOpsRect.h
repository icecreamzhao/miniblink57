/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#ifndef SkPathOpsRect_DEFINED
#define SkPathOpsRect_DEFINED

#include "SkPathOpsPoint.h"

struct SkDRect {
    double fLeft, fTop, fRight, fBottom;

<<<<<<< HEAD
    void add(const SkDPoint& pt)
    {
=======
    void add(const SkDPoint& pt) {
>>>>>>> miniblink49
        fLeft = SkTMin(fLeft, pt.fX);
        fTop = SkTMin(fTop, pt.fY);
        fRight = SkTMax(fRight, pt.fX);
        fBottom = SkTMax(fBottom, pt.fY);
    }

<<<<<<< HEAD
    bool contains(const SkDPoint& pt) const
    {
        return approximately_between(fLeft, pt.fX, fRight)
            && approximately_between(fTop, pt.fY, fBottom);
    }

    void debugInit();

    bool intersects(const SkDRect& r) const
    {
=======
    bool contains(const SkDPoint& pt) const {
        return approximately_between(fLeft, pt.fX, fRight)
                && approximately_between(fTop, pt.fY, fBottom);
    }

    bool intersects(const SkDRect& r) const {
>>>>>>> miniblink49
        SkASSERT(fLeft <= fRight);
        SkASSERT(fTop <= fBottom);
        SkASSERT(r.fLeft <= r.fRight);
        SkASSERT(r.fTop <= r.fBottom);
        return r.fLeft <= fRight && fLeft <= r.fRight && r.fTop <= fBottom && fTop <= r.fBottom;
    }

<<<<<<< HEAD
    void set(const SkDPoint& pt)
    {
=======
    void set(const SkDPoint& pt) {
>>>>>>> miniblink49
        fLeft = fRight = pt.fX;
        fTop = fBottom = pt.fY;
    }

<<<<<<< HEAD
    double width() const
    {
        return fRight - fLeft;
    }

    double height() const
    {
        return fBottom - fTop;
    }

    void setBounds(const SkDConic& curve)
    {
=======
    double width() const {
        return fRight - fLeft;
    }

    double height() const {
        return fBottom - fTop;
    }

    void setBounds(const SkDConic& curve) {
>>>>>>> miniblink49
        setBounds(curve, curve, 0, 1);
    }

    void setBounds(const SkDConic& curve, const SkDConic& sub, double tStart, double tEnd);

<<<<<<< HEAD
    void setBounds(const SkDCubic& curve)
    {
=======
    void setBounds(const SkDCubic& curve) {
>>>>>>> miniblink49
        setBounds(curve, curve, 0, 1);
    }

    void setBounds(const SkDCubic& curve, const SkDCubic& sub, double tStart, double tEnd);

<<<<<<< HEAD
    void setBounds(const SkDQuad& curve)
    {
=======
    void setBounds(const SkDQuad& curve) {
>>>>>>> miniblink49
        setBounds(curve, curve, 0, 1);
    }

    void setBounds(const SkDQuad& curve, const SkDQuad& sub, double tStart, double tEnd);
};

#endif
