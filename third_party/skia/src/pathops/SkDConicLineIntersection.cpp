/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#include "SkIntersections.h"
#include "SkPathOpsConic.h"
#include "SkPathOpsLine.h"

class LineConicIntersections {
public:
    enum PinTPoint {
        kPointUninitialized,
        kPointInitialized
    };

    LineConicIntersections(const SkDConic& c, const SkDLine& l, SkIntersections* i)
        : fConic(c)
        , fLine(&l)
        , fIntersections(i)
<<<<<<< HEAD
        , fAllowNear(true)
    {
        i->setMax(3); // allow short partial coincidence plus discrete intersection
=======
        , fAllowNear(true) {
        i->setMax(3);  // allow short partial coincidence plus discrete intersection
>>>>>>> miniblink49
    }

    LineConicIntersections(const SkDConic& c)
        : fConic(c)
<<<<<<< HEAD
            SkDEBUGPARAMS(fLine(nullptr))
                SkDEBUGPARAMS(fIntersections(nullptr))
                    SkDEBUGPARAMS(fAllowNear(false))
    {
    }

    void allowNear(bool allow)
    {
        fAllowNear = allow;
    }

    void checkCoincident()
    {
        int last = fIntersections->used() - 1;
        for (int index = 0; index < last;) {
            double conicMidT = ((*fIntersections)[0][index] + (*fIntersections)[0][index + 1]) / 2;
            SkDPoint conicMidPt = fConic.ptAtT(conicMidT);
            double t = fLine->nearPoint(conicMidPt, nullptr);
=======
        SkDEBUGPARAMS(fLine(NULL))
        SkDEBUGPARAMS(fIntersections(NULL))
        SkDEBUGPARAMS(fAllowNear(false)) {
    }

    void allowNear(bool allow) {
        fAllowNear = allow;
    }

    void checkCoincident() {
        int last = fIntersections->used() - 1;
        for (int index = 0; index < last; ) {
            double conicMidT = ((*fIntersections)[0][index] + (*fIntersections)[0][index + 1]) / 2;
            SkDPoint conicMidPt = fConic.ptAtT(conicMidT);
            double t = fLine->nearPoint(conicMidPt, NULL);
>>>>>>> miniblink49
            if (t < 0) {
                ++index;
                continue;
            }
            if (fIntersections->isCoincident(index)) {
                fIntersections->removeOne(index);
                --last;
            } else if (fIntersections->isCoincident(index + 1)) {
                fIntersections->removeOne(index + 1);
                --last;
            } else {
                fIntersections->setCoincident(index++);
            }
            fIntersections->setCoincident(index);
        }
    }

#ifdef SK_DEBUG
<<<<<<< HEAD
    static bool close_to(double a, double b, const double c[3])
    {
=======
    static bool close_to(double a, double b, const double c[3]) {
>>>>>>> miniblink49
        double max = SkTMax(-SkTMin(SkTMin(c[0], c[1]), c[2]), SkTMax(SkTMax(c[0], c[1]), c[2]));
        return approximately_zero_when_compared_to(a - b, max);
    }
#endif
<<<<<<< HEAD
    int horizontalIntersect(double axisIntercept, double roots[2])
    {
=======
    int horizontalIntersect(double axisIntercept, double roots[2]) {
>>>>>>> miniblink49
        double conicVals[] = { fConic[0].fY, fConic[1].fY, fConic[2].fY };
        return this->validT(conicVals, axisIntercept, roots);
    }

<<<<<<< HEAD
    int horizontalIntersect(double axisIntercept, double left, double right, bool flipped)
    {
=======
    int horizontalIntersect(double axisIntercept, double left, double right, bool flipped) {
>>>>>>> miniblink49
        this->addExactHorizontalEndPoints(left, right, axisIntercept);
        if (fAllowNear) {
            this->addNearHorizontalEndPoints(left, right, axisIntercept);
        }
        double roots[2];
        int count = this->horizontalIntersect(axisIntercept, roots);
        for (int index = 0; index < count; ++index) {
            double conicT = roots[index];
            SkDPoint pt = fConic.ptAtT(conicT);
            SkDEBUGCODE_(double conicVals[] = { fConic[0].fY, fConic[1].fY, fConic[2].fY });
            SkASSERT(close_to(pt.fY, axisIntercept, conicVals));
            double lineT = (pt.fX - left) / (right - left);
            if (this->pinTs(&conicT, &lineT, &pt, kPointInitialized)
<<<<<<< HEAD
                && this->uniqueAnswer(conicT, pt)) {
=======
                    && this->uniqueAnswer(conicT, pt)) {
>>>>>>> miniblink49
                fIntersections->insert(conicT, lineT, pt);
            }
        }
        if (flipped) {
            fIntersections->flip();
        }
        this->checkCoincident();
        return fIntersections->used();
    }

<<<<<<< HEAD
    int intersect()
    {
=======
    int intersect() {
>>>>>>> miniblink49
        this->addExactEndPoints();
        if (fAllowNear) {
            this->addNearEndPoints();
        }
        double rootVals[2];
        int roots = this->intersectRay(rootVals);
        for (int index = 0; index < roots; ++index) {
            double conicT = rootVals[index];
            double lineT = this->findLineT(conicT);
<<<<<<< HEAD
#ifdef SK_DEBUG
            if (!fIntersections->debugGlobalState()
                || !fIntersections->debugGlobalState()->debugSkipAssert()) {
                SkDEBUGCODE(SkDPoint conicPt = fConic.ptAtT(conicT));
                SkDEBUGCODE(SkDPoint linePt = fLine->ptAtT(lineT));
                SkASSERT(conicPt.approximatelyEqual(linePt));
            }
#endif
            SkDPoint pt;
            if (this->pinTs(&conicT, &lineT, &pt, kPointUninitialized)
                && this->uniqueAnswer(conicT, pt)) {
=======
            SkDEBUGCODE(SkDPoint conicPt = fConic.ptAtT(conicT));
            SkDEBUGCODE(SkDPoint linePt = fLine->ptAtT(lineT));
            SkASSERT(conicPt.approximatelyEqual(linePt));
            SkDPoint pt;
            if (this->pinTs(&conicT, &lineT, &pt, kPointUninitialized)
                    && this->uniqueAnswer(conicT, pt)) {
>>>>>>> miniblink49
                fIntersections->insert(conicT, lineT, pt);
            }
        }
        this->checkCoincident();
        return fIntersections->used();
    }

<<<<<<< HEAD
    int intersectRay(double roots[2])
    {
=======
    int intersectRay(double roots[2]) {
>>>>>>> miniblink49
        double adj = (*fLine)[1].fX - (*fLine)[0].fX;
        double opp = (*fLine)[1].fY - (*fLine)[0].fY;
        double r[3];
        for (int n = 0; n < 3; ++n) {
            r[n] = (fConic[n].fY - (*fLine)[0].fY) * adj - (fConic[n].fX - (*fLine)[0].fX) * opp;
        }
        return this->validT(r, 0, roots);
    }

<<<<<<< HEAD
    int validT(double r[3], double axisIntercept, double roots[2])
    {
        double A = r[2];
        double B = r[1] * fConic.fWeight - axisIntercept * fConic.fWeight + axisIntercept;
        double C = r[0];
        A += C - 2 * B; // A = a + c - 2*(b*w - xCept*w + xCept)
        B -= C; // B = b*w - w * xCept + xCept - a
=======
    int validT(double r[3], double axisIntercept, double roots[2]) {
        double A = r[2];
        double B = r[1] * fConic.fWeight - axisIntercept * fConic.fWeight + axisIntercept;
        double C = r[0];
        A += C - 2 * B;  // A = a + c - 2*(b*w - xCept*w + xCept)
        B -= C;  // B = b*w - w * xCept + xCept - a
>>>>>>> miniblink49
        C -= axisIntercept;
        return SkDQuad::RootsValidT(A, 2 * B, C, roots);
    }

<<<<<<< HEAD
    int verticalIntersect(double axisIntercept, double roots[2])
    {
=======
    int verticalIntersect(double axisIntercept, double roots[2]) {
>>>>>>> miniblink49
        double conicVals[] = { fConic[0].fX, fConic[1].fX, fConic[2].fX };
        return this->validT(conicVals, axisIntercept, roots);
    }

<<<<<<< HEAD
    int verticalIntersect(double axisIntercept, double top, double bottom, bool flipped)
    {
=======
    int verticalIntersect(double axisIntercept, double top, double bottom, bool flipped) {
>>>>>>> miniblink49
        this->addExactVerticalEndPoints(top, bottom, axisIntercept);
        if (fAllowNear) {
            this->addNearVerticalEndPoints(top, bottom, axisIntercept);
        }
        double roots[2];
        int count = this->verticalIntersect(axisIntercept, roots);
        for (int index = 0; index < count; ++index) {
            double conicT = roots[index];
            SkDPoint pt = fConic.ptAtT(conicT);
            SkDEBUGCODE_(double conicVals[] = { fConic[0].fX, fConic[1].fX, fConic[2].fX });
<<<<<<< HEAD
            SkASSERT((fIntersections->debugGlobalState() && fIntersections->debugGlobalState()->debugSkipAssert()) || close_to(pt.fX, axisIntercept, conicVals));
            double lineT = (pt.fY - top) / (bottom - top);
            if (this->pinTs(&conicT, &lineT, &pt, kPointInitialized)
                && this->uniqueAnswer(conicT, pt)) {
=======
            SkASSERT(close_to(pt.fX, axisIntercept, conicVals));
            double lineT = (pt.fY - top) / (bottom - top);
            if (this->pinTs(&conicT, &lineT, &pt, kPointInitialized)
                    && this->uniqueAnswer(conicT, pt)) {
>>>>>>> miniblink49
                fIntersections->insert(conicT, lineT, pt);
            }
        }
        if (flipped) {
            fIntersections->flip();
        }
        this->checkCoincident();
        return fIntersections->used();
    }

protected:
<<<<<<< HEAD
    // OPTIMIZE: Functions of the form add .. points are indentical to the conic routines.
    // add endpoints first to get zero and one t values exactly
    void addExactEndPoints()
    {
=======
// OPTIMIZE: Functions of the form add .. points are indentical to the conic routines.
    // add endpoints first to get zero and one t values exactly
    void addExactEndPoints() {
>>>>>>> miniblink49
        for (int cIndex = 0; cIndex < SkDConic::kPointCount; cIndex += SkDConic::kPointLast) {
            double lineT = fLine->exactPoint(fConic[cIndex]);
            if (lineT < 0) {
                continue;
            }
<<<<<<< HEAD
            double conicT = (double)(cIndex >> 1);
=======
            double conicT = (double) (cIndex >> 1);
>>>>>>> miniblink49
            fIntersections->insert(conicT, lineT, fConic[cIndex]);
        }
    }

<<<<<<< HEAD
    void addNearEndPoints()
    {
        for (int cIndex = 0; cIndex < SkDConic::kPointCount; cIndex += SkDConic::kPointLast) {
            double conicT = (double)(cIndex >> 1);
            if (fIntersections->hasT(conicT)) {
                continue;
            }
            double lineT = fLine->nearPoint(fConic[cIndex], nullptr);
=======
    void addNearEndPoints() {
        for (int cIndex = 0; cIndex < SkDConic::kPointCount; cIndex += SkDConic::kPointLast) {
            double conicT = (double) (cIndex >> 1);
            if (fIntersections->hasT(conicT)) {
                continue;
            }
            double lineT = fLine->nearPoint(fConic[cIndex], NULL);
>>>>>>> miniblink49
            if (lineT < 0) {
                continue;
            }
            fIntersections->insert(conicT, lineT, fConic[cIndex]);
        }
        // FIXME: see if line end is nearly on conic
    }

<<<<<<< HEAD
    void addExactHorizontalEndPoints(double left, double right, double y)
    {
=======
    void addExactHorizontalEndPoints(double left, double right, double y) {
>>>>>>> miniblink49
        for (int cIndex = 0; cIndex < SkDConic::kPointCount; cIndex += SkDConic::kPointLast) {
            double lineT = SkDLine::ExactPointH(fConic[cIndex], left, right, y);
            if (lineT < 0) {
                continue;
            }
<<<<<<< HEAD
            double conicT = (double)(cIndex >> 1);
=======
            double conicT = (double) (cIndex >> 1);
>>>>>>> miniblink49
            fIntersections->insert(conicT, lineT, fConic[cIndex]);
        }
    }

<<<<<<< HEAD
    void addNearHorizontalEndPoints(double left, double right, double y)
    {
        for (int cIndex = 0; cIndex < SkDConic::kPointCount; cIndex += SkDConic::kPointLast) {
            double conicT = (double)(cIndex >> 1);
=======
    void addNearHorizontalEndPoints(double left, double right, double y) {
        for (int cIndex = 0; cIndex < SkDConic::kPointCount; cIndex += SkDConic::kPointLast) {
            double conicT = (double) (cIndex >> 1);
>>>>>>> miniblink49
            if (fIntersections->hasT(conicT)) {
                continue;
            }
            double lineT = SkDLine::NearPointH(fConic[cIndex], left, right, y);
            if (lineT < 0) {
                continue;
            }
            fIntersections->insert(conicT, lineT, fConic[cIndex]);
        }
        // FIXME: see if line end is nearly on conic
    }

<<<<<<< HEAD
    void addExactVerticalEndPoints(double top, double bottom, double x)
    {
=======
    void addExactVerticalEndPoints(double top, double bottom, double x) {
>>>>>>> miniblink49
        for (int cIndex = 0; cIndex < SkDConic::kPointCount; cIndex += SkDConic::kPointLast) {
            double lineT = SkDLine::ExactPointV(fConic[cIndex], top, bottom, x);
            if (lineT < 0) {
                continue;
            }
<<<<<<< HEAD
            double conicT = (double)(cIndex >> 1);
=======
            double conicT = (double) (cIndex >> 1);
>>>>>>> miniblink49
            fIntersections->insert(conicT, lineT, fConic[cIndex]);
        }
    }

<<<<<<< HEAD
    void addNearVerticalEndPoints(double top, double bottom, double x)
    {
        for (int cIndex = 0; cIndex < SkDConic::kPointCount; cIndex += SkDConic::kPointLast) {
            double conicT = (double)(cIndex >> 1);
=======
    void addNearVerticalEndPoints(double top, double bottom, double x) {
        for (int cIndex = 0; cIndex < SkDConic::kPointCount; cIndex += SkDConic::kPointLast) {
            double conicT = (double) (cIndex >> 1);
>>>>>>> miniblink49
            if (fIntersections->hasT(conicT)) {
                continue;
            }
            double lineT = SkDLine::NearPointV(fConic[cIndex], top, bottom, x);
            if (lineT < 0) {
                continue;
            }
            fIntersections->insert(conicT, lineT, fConic[cIndex]);
        }
        // FIXME: see if line end is nearly on conic
    }

<<<<<<< HEAD
    double findLineT(double t)
    {
=======
    double findLineT(double t) {
>>>>>>> miniblink49
        SkDPoint xy = fConic.ptAtT(t);
        double dx = (*fLine)[1].fX - (*fLine)[0].fX;
        double dy = (*fLine)[1].fY - (*fLine)[0].fY;
        if (fabs(dx) > fabs(dy)) {
            return (xy.fX - (*fLine)[0].fX) / dx;
        }
        return (xy.fY - (*fLine)[0].fY) / dy;
    }

<<<<<<< HEAD
    bool pinTs(double* conicT, double* lineT, SkDPoint* pt, PinTPoint ptSet)
    {
=======
    bool pinTs(double* conicT, double* lineT, SkDPoint* pt, PinTPoint ptSet) {
>>>>>>> miniblink49
        if (!approximately_one_or_less_double(*lineT)) {
            return false;
        }
        if (!approximately_zero_or_more_double(*lineT)) {
            return false;
        }
        double qT = *conicT = SkPinT(*conicT);
        double lT = *lineT = SkPinT(*lineT);
        if (lT == 0 || lT == 1 || (ptSet == kPointUninitialized && qT != 0 && qT != 1)) {
            *pt = (*fLine).ptAtT(lT);
        } else if (ptSet == kPointUninitialized) {
            *pt = fConic.ptAtT(qT);
        }
        SkPoint gridPt = pt->asSkPoint();
        if (SkDPoint::ApproximatelyEqual(gridPt, (*fLine)[0].asSkPoint())) {
            *pt = (*fLine)[0];
            *lineT = 0;
        } else if (SkDPoint::ApproximatelyEqual(gridPt, (*fLine)[1].asSkPoint())) {
            *pt = (*fLine)[1];
            *lineT = 1;
        }
        if (fIntersections->used() > 0 && approximately_equal((*fIntersections)[1][0], *lineT)) {
            return false;
        }
        if (gridPt == fConic[0].asSkPoint()) {
            *pt = fConic[0];
            *conicT = 0;
        } else if (gridPt == fConic[2].asSkPoint()) {
            *pt = fConic[2];
            *conicT = 1;
        }
        return true;
    }

<<<<<<< HEAD
    bool uniqueAnswer(double conicT, const SkDPoint& pt)
    {
=======
    bool uniqueAnswer(double conicT, const SkDPoint& pt) {
>>>>>>> miniblink49
        for (int inner = 0; inner < fIntersections->used(); ++inner) {
            if (fIntersections->pt(inner) != pt) {
                continue;
            }
            double existingConicT = (*fIntersections)[0][inner];
            if (conicT == existingConicT) {
                return false;
            }
            // check if midway on conic is also same point. If so, discard this
            double conicMidT = (existingConicT + conicT) / 2;
            SkDPoint conicMidPt = fConic.ptAtT(conicMidT);
            if (conicMidPt.approximatelyEqual(pt)) {
                return false;
            }
        }
#if ONE_OFF_DEBUG
        SkDPoint qPt = fConic.ptAtT(conicT);
        SkDebugf("%s pt=(%1.9g,%1.9g) cPt=(%1.9g,%1.9g)\n", __FUNCTION__, pt.fX, pt.fY,
<<<<<<< HEAD
            qPt.fX, qPt.fY);
=======
                qPt.fX, qPt.fY);
>>>>>>> miniblink49
#endif
        return true;
    }

private:
    const SkDConic& fConic;
    const SkDLine* fLine;
    SkIntersections* fIntersections;
    bool fAllowNear;
};

int SkIntersections::horizontal(const SkDConic& conic, double left, double right, double y,
<<<<<<< HEAD
    bool flipped)
{
    SkDLine line = { { { left, y }, { right, y } } };
=======
                                bool flipped) {
    SkDLine line = {{{ left, y }, { right, y }}};
>>>>>>> miniblink49
    LineConicIntersections c(conic, line, this);
    return c.horizontalIntersect(y, left, right, flipped);
}

int SkIntersections::vertical(const SkDConic& conic, double top, double bottom, double x,
<<<<<<< HEAD
    bool flipped)
{
    SkDLine line = { { { x, top }, { x, bottom } } };
=======
                              bool flipped) {
    SkDLine line = {{{ x, top }, { x, bottom }}};
>>>>>>> miniblink49
    LineConicIntersections c(conic, line, this);
    return c.verticalIntersect(x, top, bottom, flipped);
}

<<<<<<< HEAD
int SkIntersections::intersect(const SkDConic& conic, const SkDLine& line)
{
=======
int SkIntersections::intersect(const SkDConic& conic, const SkDLine& line) {
>>>>>>> miniblink49
    LineConicIntersections c(conic, line, this);
    c.allowNear(fAllowNear);
    return c.intersect();
}

<<<<<<< HEAD
int SkIntersections::intersectRay(const SkDConic& conic, const SkDLine& line)
{
=======
int SkIntersections::intersectRay(const SkDConic& conic, const SkDLine& line) {
>>>>>>> miniblink49
    LineConicIntersections c(conic, line, this);
    fUsed = c.intersectRay(fT[0]);
    for (int index = 0; index < fUsed; ++index) {
        fPt[index] = conic.ptAtT(fT[0][index]);
    }
    return fUsed;
}

<<<<<<< HEAD
int SkIntersections::HorizontalIntercept(const SkDConic& conic, SkScalar y, double* roots)
{
=======
int SkIntersections::HorizontalIntercept(const SkDConic& conic, SkScalar y, double* roots) {
>>>>>>> miniblink49
    LineConicIntersections c(conic);
    return c.horizontalIntersect(y, roots);
}

<<<<<<< HEAD
int SkIntersections::VerticalIntercept(const SkDConic& conic, SkScalar x, double* roots)
{
=======
int SkIntersections::VerticalIntercept(const SkDConic& conic, SkScalar x, double* roots) {
>>>>>>> miniblink49
    LineConicIntersections c(conic);
    return c.verticalIntersect(x, roots);
}
