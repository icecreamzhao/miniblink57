/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef GrRectanizer_skyline_DEFINED
#define GrRectanizer_skyline_DEFINED

#include "GrRectanizer.h"
#include "SkTDArray.h"

// Pack rectangles and track the current silhouette
// Based, in part, on Jukka Jylanki's work at http://clb.demon.fi
class GrRectanizerSkyline : public GrRectanizer {
public:
<<<<<<< HEAD
    GrRectanizerSkyline(int w, int h)
        : INHERITED(w, h)
    {
        this->reset();
    }

    ~GrRectanizerSkyline() override { }

    void reset() override
    {
=======
    GrRectanizerSkyline(int w, int h) : INHERITED(w, h) {
        this->reset();
    }

    virtual ~GrRectanizerSkyline() { }

    void reset() override{
>>>>>>> miniblink49
        fAreaSoFar = 0;
        fSkyline.reset();
        SkylineSegment* seg = fSkyline.append(1);
        seg->fX = 0;
        seg->fY = 0;
        seg->fWidth = this->width();
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
    struct SkylineSegment {
<<<<<<< HEAD
        int fX;
        int fY;
        int fWidth;
=======
        int  fX;
        int  fY;
        int  fWidth;
>>>>>>> miniblink49
    };

    SkTDArray<SkylineSegment> fSkyline;

    int32_t fAreaSoFar;

    // Can a width x height rectangle fit in the free space represented by
    // the skyline segments >= 'skylineIndex'? If so, return true and fill in
<<<<<<< HEAD
    // 'y' with the y-location at which it fits (the x location is pulled from
=======
    // 'y' with the y-location at which it fits (the x location is pulled from 
>>>>>>> miniblink49
    // 'skylineIndex's segment.
    bool rectangleFits(int skylineIndex, int width, int height, int* y) const;
    // Update the skyline structure to include a width x height rect located
    // at x,y.
    void addSkylineLevel(int skylineIndex, int x, int y, int width, int height);

    typedef GrRectanizer INHERITED;
};

#endif
