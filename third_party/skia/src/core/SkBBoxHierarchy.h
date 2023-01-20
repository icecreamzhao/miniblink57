/*
 * Copyright 2012 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkBBoxHierarchy_DEFINED
#define SkBBoxHierarchy_DEFINED

#include "SkRect.h"
#include "SkRefCnt.h"
#include "SkTDArray.h"
<<<<<<< HEAD
=======
#include "SkTemplates.h"
>>>>>>> miniblink49

/**
 * Interface for a spatial data structure that stores axis-aligned bounding
 * boxes and allows efficient retrieval of intersections with query rectangles.
 */
class SkBBoxHierarchy : public SkRefCnt {
public:
<<<<<<< HEAD
    SkBBoxHierarchy() { }
    virtual ~SkBBoxHierarchy() { }
=======
    SkBBoxHierarchy() {}
    virtual ~SkBBoxHierarchy() {}
>>>>>>> miniblink49

    /**
     * Insert N bounding boxes into the hierarchy.
     */
    virtual void insert(const SkRect[], int N) = 0;

    /**
     * Populate results with the indices of bounding boxes interesecting that query.
     */
<<<<<<< HEAD
    virtual void search(const SkRect& query, SkTDArray<int>* results) const = 0;
=======
    virtual void search(const SkRect& query, SkTDArray<unsigned>* results) const = 0;
>>>>>>> miniblink49

    virtual size_t bytesUsed() const = 0;

    // Get the root bound.
    virtual SkRect getRootBound() const = 0;

<<<<<<< HEAD
=======
    
>>>>>>> miniblink49
private:
    typedef SkRefCnt INHERITED;
};

#endif
