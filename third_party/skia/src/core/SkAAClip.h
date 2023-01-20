<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#ifndef SkAAClip_DEFINED
#define SkAAClip_DEFINED

#include "SkBlitter.h"
#include "SkRegion.h"

class SkAAClip {
public:
    SkAAClip();
    SkAAClip(const SkAAClip&);
    ~SkAAClip();

    SkAAClip& operator=(const SkAAClip&);
    friend bool operator==(const SkAAClip&, const SkAAClip&);
<<<<<<< HEAD
    friend bool operator!=(const SkAAClip& a, const SkAAClip& b)
    {
=======
    friend bool operator!=(const SkAAClip& a, const SkAAClip& b) {
>>>>>>> miniblink49
        return !(a == b);
    }

    void swap(SkAAClip&);

<<<<<<< HEAD
    bool isEmpty() const { return nullptr == fRunHead; }
=======
    bool isEmpty() const { return NULL == fRunHead; }
>>>>>>> miniblink49
    const SkIRect& getBounds() const { return fBounds; }

    // Returns true iff the clip is not empty, and is just a hard-edged rect (no partial alpha).
    // If true, getBounds() can be used in place of this clip.
    bool isRect() const;

    bool setEmpty();
    bool setRect(const SkIRect&);
    bool setRect(const SkRect&, bool doAA = true);
<<<<<<< HEAD
    bool setPath(const SkPath&, const SkRegion* clip = nullptr, bool doAA = true);
=======
    bool setPath(const SkPath&, const SkRegion* clip = NULL, bool doAA = true);
>>>>>>> miniblink49
    bool setRegion(const SkRegion&);
    bool set(const SkAAClip&);

    bool op(const SkAAClip&, const SkAAClip&, SkRegion::Op);

    // Helpers for op()
    bool op(const SkIRect&, SkRegion::Op);
    bool op(const SkRect&, SkRegion::Op, bool doAA);
    bool op(const SkAAClip&, SkRegion::Op);

    bool translate(int dx, int dy, SkAAClip* dst) const;
<<<<<<< HEAD
    bool translate(int dx, int dy)
    {
=======
    bool translate(int dx, int dy) {
>>>>>>> miniblink49
        return this->translate(dx, dy, this);
    }

    /**
     *  Allocates a mask the size of the aaclip, and expands its data into
     *  the mask, using kA8_Format
     */
    void copyToMask(SkMask*) const;

    // called internally

    bool quickContains(int left, int top, int right, int bottom) const;
<<<<<<< HEAD
    bool quickContains(const SkIRect& r) const
    {
        return this->quickContains(r.fLeft, r.fTop, r.fRight, r.fBottom);
    }

    const uint8_t* findRow(int y, int* lastYForRow = nullptr) const;
    const uint8_t* findX(const uint8_t data[], int x, int* initialCount = nullptr) const;
=======
    bool quickContains(const SkIRect& r) const {
        return this->quickContains(r.fLeft, r.fTop, r.fRight, r.fBottom);
    }

    const uint8_t* findRow(int y, int* lastYForRow = NULL) const;
    const uint8_t* findX(const uint8_t data[], int x, int* initialCount = NULL) const;
>>>>>>> miniblink49

    class Iter;
    struct RunHead;
    struct YOffset;
    class Builder;

#ifdef SK_DEBUG
    void validate() const;
<<<<<<< HEAD
    void debug(bool compress_y = false) const;
#else
    void validate() const
    {
    }
    void debug(bool compress_y = false) const { }
#endif

private:
    SkIRect fBounds;
=======
    void debug(bool compress_y=false) const;
#else
    void validate() const {}
    void debug(bool compress_y=false) const {}
#endif

private:
    SkIRect  fBounds;
>>>>>>> miniblink49
    RunHead* fRunHead;

    void freeRuns();
    bool trimBounds();
    bool trimTopBottom();
    bool trimLeftRight();

    friend class Builder;
    class BuilderBlitter;
    friend class BuilderBlitter;
};

///////////////////////////////////////////////////////////////////////////////

class SkAAClipBlitter : public SkBlitter {
public:
<<<<<<< HEAD
    SkAAClipBlitter()
        : fScanlineScratch(nullptr)
    {
    }
    virtual ~SkAAClipBlitter();

    void init(SkBlitter* blitter, const SkAAClip* aaclip)
    {
=======
    SkAAClipBlitter() : fScanlineScratch(NULL) {}
    virtual ~SkAAClipBlitter();

    void init(SkBlitter* blitter, const SkAAClip* aaclip) {
>>>>>>> miniblink49
        SkASSERT(aaclip && !aaclip->isEmpty());
        fBlitter = blitter;
        fAAClip = aaclip;
        fAAClipBounds = aaclip->getBounds();
    }

    void blitH(int x, int y, int width) override;
    void blitAntiH(int x, int y, const SkAlpha[], const int16_t runs[]) override;
    void blitV(int x, int y, int height, SkAlpha alpha) override;
    void blitRect(int x, int y, int width, int height) override;
    void blitMask(const SkMask&, const SkIRect& clip) override;
    const SkPixmap* justAnOpaqueColor(uint32_t* value) override;

private:
<<<<<<< HEAD
    SkBlitter* fBlitter;
    const SkAAClip* fAAClip;
    SkIRect fAAClipBounds;

    // point into fScanlineScratch
    int16_t* fRuns;
    SkAlpha* fAA;
=======
    SkBlitter*      fBlitter;
    const SkAAClip* fAAClip;
    SkIRect         fAAClipBounds;

    // point into fScanlineScratch
    int16_t*        fRuns;
    SkAlpha*        fAA;
>>>>>>> miniblink49

    enum {
        kSize = 32 * 32
    };
<<<<<<< HEAD
    SkAutoSMalloc<kSize> fGrayMaskScratch; // used for blitMask
    void* fScanlineScratch; // enough for a mask at 32bit, or runs+aa
=======
    SkAutoSMalloc<kSize> fGrayMaskScratch;  // used for blitMask
    void* fScanlineScratch;  // enough for a mask at 32bit, or runs+aa
>>>>>>> miniblink49

    void ensureRunsAndAA();
};

#endif
