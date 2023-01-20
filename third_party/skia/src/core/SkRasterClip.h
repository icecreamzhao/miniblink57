/*
 * Copyright 2010 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkRasterClip_DEFINED
#define SkRasterClip_DEFINED

<<<<<<< HEAD
#include "SkAAClip.h"
#include "SkRegion.h"

class SkRRect;

/**
 *  Wraps a SkRegion and SkAAClip, so we have a single object that can represent either our
 *  BW or antialiased clips.
 *
 *  This class is optimized for the raster backend of canvas, but can be expense to keep up2date,
 *  so it supports a runtime option (force-conservative-rects) to turn it into a super-fast
 *  rect-only tracker. The gpu backend uses this since it does not need the result (it uses
 *  SkClipStack instead).
 */
=======
#include "SkRegion.h"
#include "SkAAClip.h"

>>>>>>> miniblink49
class SkRasterClip {
public:
    SkRasterClip(bool forceConservativeRects = false);
    SkRasterClip(const SkIRect&, bool forceConservativeRects = false);
<<<<<<< HEAD
    SkRasterClip(const SkRegion&);
    SkRasterClip(const SkRasterClip&);
    ~SkRasterClip();

    // Only compares the current state. Does not compare isForceConservativeRects(), so that field
    // could be different but this could still return true.
    bool operator==(const SkRasterClip&) const;
    bool operator!=(const SkRasterClip& other) const
    {
        return !(*this == other);
    }

=======
    SkRasterClip(const SkRasterClip&);
    ~SkRasterClip();

>>>>>>> miniblink49
    bool isForceConservativeRects() const { return fForceConservativeRects; }

    bool isBW() const { return fIsBW; }
    bool isAA() const { return !fIsBW; }
<<<<<<< HEAD
    const SkRegion& bwRgn() const
    {
        SkASSERT(fIsBW);
        return fBW;
    }
    const SkAAClip& aaRgn() const
    {
        SkASSERT(!fIsBW);
        return fAA;
    }

    bool isEmpty() const
    {
=======
    const SkRegion& bwRgn() const { SkASSERT(fIsBW); return fBW; }
    const SkAAClip& aaRgn() const { SkASSERT(!fIsBW); return fAA; }

    bool isEmpty() const {
>>>>>>> miniblink49
        SkASSERT(this->computeIsEmpty() == fIsEmpty);
        return fIsEmpty;
    }

<<<<<<< HEAD
    bool isRect() const
    {
=======
    bool isRect() const {
>>>>>>> miniblink49
        SkASSERT(this->computeIsRect() == fIsRect);
        return fIsRect;
    }

    bool isComplex() const;
    const SkIRect& getBounds() const;

    bool setEmpty();
    bool setRect(const SkIRect&);

    bool op(const SkIRect&, SkRegion::Op);
    bool op(const SkRegion&, SkRegion::Op);
<<<<<<< HEAD
    bool op(const SkRect&, const SkIRect&, SkRegion::Op, bool doAA);
    bool op(const SkRRect&, const SkIRect&, SkRegion::Op, bool doAA);
    bool op(const SkPath&, const SkIRect&, SkRegion::Op, bool doAA);

    void translate(int dx, int dy, SkRasterClip* dst) const;
    void translate(int dx, int dy)
    {
=======
    bool op(const SkRect&, const SkISize&, SkRegion::Op, bool doAA);
    bool op(const SkPath&, const SkISize&, SkRegion::Op, bool doAA);
    
    void translate(int dx, int dy, SkRasterClip* dst) const;
    void translate(int dx, int dy) {
>>>>>>> miniblink49
        this->translate(dx, dy, this);
    }

    bool quickContains(const SkIRect& rect) const;
<<<<<<< HEAD
    bool quickContains(int left, int top, int right, int bottom) const
    {
=======
    bool quickContains(int left, int top, int right, int bottom) const {
>>>>>>> miniblink49
        return quickContains(SkIRect::MakeLTRB(left, top, right, bottom));
    }

    /**
     *  Return true if this region is empty, or if the specified rectangle does
     *  not intersect the region. Returning false is not a guarantee that they
     *  intersect, but returning true is a guarantee that they do not.
     */
<<<<<<< HEAD
    bool quickReject(const SkIRect& rect) const
    {
=======
    bool quickReject(const SkIRect& rect) const {
>>>>>>> miniblink49
        return !SkIRect::Intersects(this->getBounds(), rect);
    }

    // hack for SkCanvas::getTotalClip
    const SkRegion& forceGetBW();

#ifdef SK_DEBUG
    void validate() const;
#else
<<<<<<< HEAD
    void validate() const
    {
    }
#endif

private:
    SkRegion fBW;
    SkAAClip fAA;
    bool fForceConservativeRects;
    bool fIsBW;
    // these 2 are caches based on querying the right obj based on fIsBW
    bool fIsEmpty;
    bool fIsRect;

    bool computeIsEmpty() const
    {
        return fIsBW ? fBW.isEmpty() : fAA.isEmpty();
    }

    bool computeIsRect() const
    {
        return fIsBW ? fBW.isRect() : fAA.isRect();
    }

    bool updateCacheAndReturnNonEmpty(bool detectAARect = true)
    {
=======
    void validate() const {}
#endif

private:
    SkRegion    fBW;
    SkAAClip    fAA;
    bool        fForceConservativeRects;
    bool        fIsBW;
    // these 2 are caches based on querying the right obj based on fIsBW
    bool        fIsEmpty;
    bool        fIsRect;

    bool computeIsEmpty() const {
        return fIsBW ? fBW.isEmpty() : fAA.isEmpty();
    }

    bool computeIsRect() const {
        return fIsBW ? fBW.isRect() : fAA.isRect();
    }

    bool updateCacheAndReturnNonEmpty(bool detectAARect = true) {
>>>>>>> miniblink49
        fIsEmpty = this->computeIsEmpty();

        // detect that our computed AA is really just a (hard-edged) rect
        if (detectAARect && !fIsEmpty && !fIsBW && fAA.isRect()) {
            fBW.setRect(fAA.getBounds());
            fAA.setEmpty(); // don't need this guy anymore
            fIsBW = true;
        }

        fIsRect = this->computeIsRect();
        return !fIsEmpty;
    }

    void convertToAA();

    bool setPath(const SkPath& path, const SkRegion& clip, bool doAA);
    bool setPath(const SkPath& path, const SkIRect& clip, bool doAA);
    bool op(const SkRasterClip&, SkRegion::Op);
    bool setConservativeRect(const SkRect& r, const SkIRect& clipR, bool isInverse);
};

class SkAutoRasterClipValidate : SkNoncopyable {
public:
<<<<<<< HEAD
    SkAutoRasterClipValidate(const SkRasterClip& rc)
        : fRC(rc)
    {
        fRC.validate();
    }
    ~SkAutoRasterClipValidate()
    {
        fRC.validate();
    }

=======
    SkAutoRasterClipValidate(const SkRasterClip& rc) : fRC(rc) {
        fRC.validate();
    }
    ~SkAutoRasterClipValidate() {
        fRC.validate();
    }
>>>>>>> miniblink49
private:
    const SkRasterClip& fRC;
};
#define SkAutoRasterClipValidate(...) SK_REQUIRE_LOCAL_VAR(SkAutoRasterClipValidate)

#ifdef SK_DEBUG
<<<<<<< HEAD
#define AUTO_RASTERCLIP_VALIDATE(rc) SkAutoRasterClipValidate arcv(rc)
#else
#define AUTO_RASTERCLIP_VALIDATE(rc)
=======
    #define AUTO_RASTERCLIP_VALIDATE(rc)    SkAutoRasterClipValidate arcv(rc)
#else
    #define AUTO_RASTERCLIP_VALIDATE(rc)
>>>>>>> miniblink49
#endif

///////////////////////////////////////////////////////////////////////////////

/**
 *  Encapsulates the logic of deciding if we need to change/wrap the blitter
 *  for aaclipping. If so, getRgn and getBlitter return modified values. If
 *  not, they return the raw blitter and (bw) clip region.
 *
 *  We need to keep the constructor/destructor cost as small as possible, so we
 *  can freely put this guy on the stack, and not pay too much for the case when
 *  we're really BW anyways.
 */
class SkAAClipBlitterWrapper {
public:
    SkAAClipBlitterWrapper();
    SkAAClipBlitterWrapper(const SkRasterClip&, SkBlitter*);
    SkAAClipBlitterWrapper(const SkAAClip*, SkBlitter*);

    void init(const SkRasterClip&, SkBlitter*);

<<<<<<< HEAD
    const SkIRect& getBounds() const
    {
        SkASSERT(fClipRgn);
        return fClipRgn->getBounds();
    }
    const SkRegion& getRgn() const
    {
        SkASSERT(fClipRgn);
        return *fClipRgn;
    }
    SkBlitter* getBlitter()
    {
=======
    const SkIRect& getBounds() const {
        SkASSERT(fClipRgn);
        return fClipRgn->getBounds();
    }
    const SkRegion& getRgn() const {
        SkASSERT(fClipRgn);
        return *fClipRgn;
    }
    SkBlitter* getBlitter() {
>>>>>>> miniblink49
        SkASSERT(fBlitter);
        return fBlitter;
    }

private:
<<<<<<< HEAD
    SkRegion fBWRgn;
=======
    SkRegion        fBWRgn;
>>>>>>> miniblink49
    SkAAClipBlitter fAABlitter;
    // what we return
    const SkRegion* fClipRgn;
    SkBlitter* fBlitter;
};

#endif
