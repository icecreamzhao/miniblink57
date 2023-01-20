/*
* Copyright 2014 Google Inc.
*
* Use of this source code is governed by a BSD-style license that can be
* found in the LICENSE file.
*/

#ifndef GrRectanizer_pow2_DEFINED
#define GrRectanizer_pow2_DEFINED

#include "GrRectanizer.h"
<<<<<<< HEAD
#include "SkMathPriv.h"
=======
>>>>>>> miniblink49
#include "SkPoint.h"

// This Rectanizer quantizes the incoming rects to powers of 2. Each power
// of two can have, at most, one active row/shelf. Once a row/shelf for
// a particular power of two gets full its fRows entry is recycled to point
// to a new row.
// The skyline algorithm almost always provides a better packing.
class GrRectanizerPow2 : public GrRectanizer {
public:
<<<<<<< HEAD
    GrRectanizerPow2(int w, int h)
        : INHERITED(w, h)
    {
=======
    GrRectanizerPow2(int w, int h) : INHERITED(w, h) {
>>>>>>> miniblink49
        this->reset();
    }

    virtual ~GrRectanizerPow2() { }

<<<<<<< HEAD
    void reset() override
    {
=======
    void reset() override {
>>>>>>> miniblink49
        fNextStripY = 0;
        fAreaSoFar = 0;
        sk_bzero(fRows, sizeof(fRows));
    }

    bool addRect(int w, int h, SkIPoint16* loc) override;

<<<<<<< HEAD
    float percentFull() const override
    {
=======
    float percentFull() const override {
>>>>>>> miniblink49
        return fAreaSoFar / ((float)this->width() * this->height());
    }

private:
    static const int kMIN_HEIGHT_POW2 = 2;
    static const int kMaxExponent = 16;

    struct Row {
<<<<<<< HEAD
        SkIPoint16 fLoc;
        // fRowHeight is actually known by this struct's position in fRows
        // but it is used to signal if there exists an open row of this height
        int fRowHeight;

        bool canAddWidth(int width, int containerWidth) const
        {
=======
        SkIPoint16  fLoc;
        // fRowHeight is actually known by this struct's position in fRows
        // but it is used to signal if there exists an open row of this height
        int         fRowHeight;

        bool canAddWidth(int width, int containerWidth) const {
>>>>>>> miniblink49
            return fLoc.fX + width <= containerWidth;
        }
    };

<<<<<<< HEAD
    Row fRows[kMaxExponent]; // 0-th entry will be unused
=======
    Row fRows[kMaxExponent];    // 0-th entry will be unused
>>>>>>> miniblink49

    int fNextStripY;
    int32_t fAreaSoFar;

<<<<<<< HEAD
    static int HeightToRowIndex(int height)
    {
=======
    static int HeightToRowIndex(int height) {
>>>>>>> miniblink49
        SkASSERT(height >= kMIN_HEIGHT_POW2);
        int index = 32 - SkCLZ(height - 1);
        SkASSERT(index < kMaxExponent);
        return index;
    }

<<<<<<< HEAD
    bool canAddStrip(int height) const
    {
        return fNextStripY + height <= this->height();
    }

    void initRow(Row* row, int rowHeight)
    {
=======
    bool canAddStrip(int height) const {
        return fNextStripY + height <= this->height();
    }

    void initRow(Row* row, int rowHeight) {
>>>>>>> miniblink49
        row->fLoc.set(0, fNextStripY);
        row->fRowHeight = rowHeight;
        fNextStripY += rowHeight;
    }

    typedef GrRectanizer INHERITED;
};

#endif
