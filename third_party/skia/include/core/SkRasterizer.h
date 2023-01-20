
/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======

>>>>>>> miniblink49
#ifndef SkRasterizer_DEFINED
#define SkRasterizer_DEFINED

#include "SkFlattenable.h"
#include "SkMask.h"

class SkMaskFilter;
class SkMatrix;
class SkPath;
struct SkIRect;

class SK_API SkRasterizer : public SkFlattenable {
public:
    /** Turn the path into a mask, respecting the specified local->device matrix.
    */
    bool rasterize(const SkPath& path, const SkMatrix& matrix,
<<<<<<< HEAD
        const SkIRect* clipBounds, SkMaskFilter* filter,
        SkMask* mask, SkMask::CreateMode mode) const;
=======
                   const SkIRect* clipBounds, SkMaskFilter* filter,
                   SkMask* mask, SkMask::CreateMode mode) const;
>>>>>>> miniblink49

    SK_DEFINE_FLATTENABLE_TYPE(SkRasterizer)

protected:
<<<<<<< HEAD
    SkRasterizer() { }
    virtual bool onRasterize(const SkPath& path, const SkMatrix& matrix,
        const SkIRect* clipBounds,
        SkMask* mask, SkMask::CreateMode mode) const;
=======
    SkRasterizer() {}
    virtual bool onRasterize(const SkPath& path, const SkMatrix& matrix,
                             const SkIRect* clipBounds,
                             SkMask* mask, SkMask::CreateMode mode) const;
>>>>>>> miniblink49

private:
    typedef SkFlattenable INHERITED;
};

#endif
