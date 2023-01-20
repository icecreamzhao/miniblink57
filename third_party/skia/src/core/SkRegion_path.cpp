/*
 * Copyright 2006 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkBlitter.h"
#include "SkPath.h"
#include "SkRegionPriv.h"
#include "SkScan.h"
#include "SkTDArray.h"
#include "SkTSort.h"

// The rgnbuilder caller *seems* to pass short counts, possible often seens early failure, so
// we may not want to promote this to a "std" routine just yet.
static bool sk_memeq32(const int32_t* SK_RESTRICT a, const int32_t* SK_RESTRICT b, int count)
{
=======
#include "SkRegionPriv.h"
#include "SkBlitter.h"
#include "SkScan.h"
#include "SkTDArray.h"
#include "SkPath.h"

// The rgnbuilder caller *seems* to pass short counts, possible often seens early failure, so
// we may not want to promote this to a "std" routine just yet.
static bool sk_memeq32(const int32_t* SK_RESTRICT a, const int32_t* SK_RESTRICT b, int count) {
>>>>>>> miniblink49
    for (int i = 0; i < count; ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

class SkRgnBuilder : public SkBlitter {
public:
    SkRgnBuilder();
    virtual ~SkRgnBuilder();

    // returns true if it could allocate the working storage needed
    bool init(int maxHeight, int maxTransitions, bool pathIsInverse);

<<<<<<< HEAD
    void done()
    {
        if (fCurrScanline != nullptr) {
=======
    void done() {
        if (fCurrScanline != NULL) {
>>>>>>> miniblink49
            fCurrScanline->fXCount = (SkRegion::RunType)((int)(fCurrXPtr - fCurrScanline->firstX()));
            if (!this->collapsWithPrev()) { // flush the last line
                fCurrScanline = fCurrScanline->nextScanline();
            }
        }
    }

<<<<<<< HEAD
    int computeRunCount() const;
    void copyToRect(SkIRect*) const;
    void copyToRgn(SkRegion::RunType runs[]) const;

    void blitH(int x, int y, int width) override;
    void blitAntiH(int x, int y, const SkAlpha antialias[], const int16_t runs[]) override
    {
        SkDEBUGFAIL("blitAntiH not implemented");
    }

#ifdef SK_DEBUG
    void dump() const
    {
=======
    int     computeRunCount() const;
    void    copyToRect(SkIRect*) const;
    void    copyToRgn(SkRegion::RunType runs[]) const;

    void blitH(int x, int y, int width) override;

#ifdef SK_DEBUG
    void dump() const {
>>>>>>> miniblink49
        SkDebugf("SkRgnBuilder: Top = %d\n", fTop);
        const Scanline* line = (Scanline*)fStorage;
        while (line < fCurrScanline) {
            SkDebugf("SkRgnBuilder::Scanline: LastY=%d, fXCount=%d", line->fLastY, line->fXCount);
            for (int i = 0; i < line->fXCount; i++) {
                SkDebugf(" %d", line->firstX()[i]);
            }
            SkDebugf("\n");

            line = line->nextScanline();
        }
    }
#endif
private:
    /*
     *  Scanline mimics a row in the region, nearly. A row in a region is:
     *      [Bottom IntervalCount [L R]... Sentinel]
     *  while a Scanline is
     *      [LastY XCount [L R]... uninitialized]
     *  The two are the same length (which is good), but we have to transmute
     *  the scanline a little when we convert it to a region-row.
     *
     *  Potentially we could recode this to exactly match the row format, in
     *  which case copyToRgn() could be a single memcpy. Not sure that is worth
     *  the effort.
     */
    struct Scanline {
        SkRegion::RunType fLastY;
        SkRegion::RunType fXCount;

        SkRegion::RunType* firstX() const { return (SkRegion::RunType*)(this + 1); }
<<<<<<< HEAD
        Scanline* nextScanline() const
        {
=======
        Scanline* nextScanline() const {
>>>>>>> miniblink49
            // add final +1 for the x-sentinel
            return (Scanline*)((SkRegion::RunType*)(this + 1) + fXCount + 1);
        }
    };
<<<<<<< HEAD
    SkRegion::RunType* fStorage;
    Scanline* fCurrScanline;
    Scanline* fPrevScanline;
    //  points at next avialable x[] in fCurrScanline
    SkRegion::RunType* fCurrXPtr;
    SkRegion::RunType fTop; // first Y value

    int fStorageCount;

    bool collapsWithPrev()
    {
        if (fPrevScanline != nullptr && fPrevScanline->fLastY + 1 == fCurrScanline->fLastY && fPrevScanline->fXCount == fCurrScanline->fXCount && sk_memeq32(fPrevScanline->firstX(), fCurrScanline->firstX(), fCurrScanline->fXCount)) {
=======
    SkRegion::RunType*  fStorage;
    Scanline*           fCurrScanline;
    Scanline*           fPrevScanline;
    //  points at next avialable x[] in fCurrScanline
    SkRegion::RunType*  fCurrXPtr;
    SkRegion::RunType   fTop;           // first Y value

    int fStorageCount;

    bool collapsWithPrev() {
        if (fPrevScanline != NULL &&
            fPrevScanline->fLastY + 1 == fCurrScanline->fLastY &&
            fPrevScanline->fXCount == fCurrScanline->fXCount &&
            sk_memeq32(fPrevScanline->firstX(), fCurrScanline->firstX(), fCurrScanline->fXCount))
        {
>>>>>>> miniblink49
            // update the height of fPrevScanline
            fPrevScanline->fLastY = fCurrScanline->fLastY;
            return true;
        }
        return false;
    }
};

SkRgnBuilder::SkRgnBuilder()
<<<<<<< HEAD
    : fStorage(nullptr)
{
}

SkRgnBuilder::~SkRgnBuilder()
{
    sk_free(fStorage);
}

bool SkRgnBuilder::init(int maxHeight, int maxTransitions, bool pathIsInverse)
{
=======
    : fStorage(NULL) {
}

SkRgnBuilder::~SkRgnBuilder() {
    sk_free(fStorage);
}

bool SkRgnBuilder::init(int maxHeight, int maxTransitions, bool pathIsInverse) {
>>>>>>> miniblink49
    if ((maxHeight | maxTransitions) < 0) {
        return false;
    }

    if (pathIsInverse) {
        // allow for additional X transitions to "invert" each scanline
        // [ L' ... normal transitions ... R' ]
        //
        maxTransitions += 2;
    }

    // compute the count with +1 and +3 slop for the working buffer
    int64_t count = sk_64_mul(maxHeight + 1, 3 + maxTransitions);

    if (pathIsInverse) {
        // allow for two "empty" rows for the top and bottom
        //      [ Y, 1, L, R, S] == 5 (*2 for top and bottom)
        count += 10;
    }

    if (count < 0 || !sk_64_isS32(count)) {
        return false;
    }
    fStorageCount = sk_64_asS32(count);

    int64_t size = sk_64_mul(fStorageCount, sizeof(SkRegion::RunType));
    if (size < 0 || !sk_64_isS32(size)) {
        return false;
    }

    fStorage = (SkRegion::RunType*)sk_malloc_flags(sk_64_asS32(size), 0);
<<<<<<< HEAD
    if (nullptr == fStorage) {
        return false;
    }

    fCurrScanline = nullptr; // signal empty collection
    fPrevScanline = nullptr; // signal first scanline
    return true;
}

void SkRgnBuilder::blitH(int x, int y, int width)
{
    if (fCurrScanline == nullptr) { // first time
=======
    if (NULL == fStorage) {
        return false;
    }

    fCurrScanline = NULL;    // signal empty collection
    fPrevScanline = NULL;    // signal first scanline
    return true;
}

void SkRgnBuilder::blitH(int x, int y, int width) {
    if (fCurrScanline == NULL) {  // first time
>>>>>>> miniblink49
        fTop = (SkRegion::RunType)(y);
        fCurrScanline = (Scanline*)fStorage;
        fCurrScanline->fLastY = (SkRegion::RunType)(y);
        fCurrXPtr = fCurrScanline->firstX();
    } else {
        SkASSERT(y >= fCurrScanline->fLastY);

        if (y > fCurrScanline->fLastY) {
            // if we get here, we're done with fCurrScanline
            fCurrScanline->fXCount = (SkRegion::RunType)((int)(fCurrXPtr - fCurrScanline->firstX()));

            int prevLastY = fCurrScanline->fLastY;
            if (!this->collapsWithPrev()) {
                fPrevScanline = fCurrScanline;
                fCurrScanline = fCurrScanline->nextScanline();
<<<<<<< HEAD
            }
            if (y - 1 > prevLastY) { // insert empty run
=======

            }
            if (y - 1 > prevLastY) {  // insert empty run
>>>>>>> miniblink49
                fCurrScanline->fLastY = (SkRegion::RunType)(y - 1);
                fCurrScanline->fXCount = 0;
                fCurrScanline = fCurrScanline->nextScanline();
            }
            // setup for the new curr line
            fCurrScanline->fLastY = (SkRegion::RunType)(y);
            fCurrXPtr = fCurrScanline->firstX();
        }
    }
    //  check if we should extend the current run, or add a new one
    if (fCurrXPtr > fCurrScanline->firstX() && fCurrXPtr[-1] == x) {
        fCurrXPtr[-1] = (SkRegion::RunType)(x + width);
    } else {
        fCurrXPtr[0] = (SkRegion::RunType)(x);
        fCurrXPtr[1] = (SkRegion::RunType)(x + width);
        fCurrXPtr += 2;
    }
    SkASSERT(fCurrXPtr - fStorage < fStorageCount);
}

<<<<<<< HEAD
int SkRgnBuilder::computeRunCount() const
{
    if (fCurrScanline == nullptr) {
        return 0;
    }

    const SkRegion::RunType* line = fStorage;
    const SkRegion::RunType* stop = (const SkRegion::RunType*)fCurrScanline;
=======
int SkRgnBuilder::computeRunCount() const {
    if (fCurrScanline == NULL) {
        return 0;
    }

    const SkRegion::RunType*  line = fStorage;
    const SkRegion::RunType*  stop = (const SkRegion::RunType*)fCurrScanline;
>>>>>>> miniblink49

    return 2 + (int)(stop - line);
}

<<<<<<< HEAD
void SkRgnBuilder::copyToRect(SkIRect* r) const
{
    SkASSERT(fCurrScanline != nullptr);
=======
void SkRgnBuilder::copyToRect(SkIRect* r) const {
    SkASSERT(fCurrScanline != NULL);
>>>>>>> miniblink49
    // A rect's scanline is [bottom intervals left right sentinel] == 5
    SkASSERT((const SkRegion::RunType*)fCurrScanline - fStorage == 5);

    const Scanline* line = (const Scanline*)fStorage;
    SkASSERT(line->fXCount == 2);

    r->set(line->firstX()[0], fTop, line->firstX()[1], line->fLastY + 1);
}

<<<<<<< HEAD
void SkRgnBuilder::copyToRgn(SkRegion::RunType runs[]) const
{
    SkASSERT(fCurrScanline != nullptr);
=======
void SkRgnBuilder::copyToRgn(SkRegion::RunType runs[]) const {
    SkASSERT(fCurrScanline != NULL);
>>>>>>> miniblink49
    SkASSERT((const SkRegion::RunType*)fCurrScanline - fStorage > 4);

    const Scanline* line = (const Scanline*)fStorage;
    const Scanline* stop = fCurrScanline;

    *runs++ = fTop;
    do {
        *runs++ = (SkRegion::RunType)(line->fLastY + 1);
        int count = line->fXCount;
<<<<<<< HEAD
        *runs++ = count >> 1; // intervalCount
=======
        *runs++ = count >> 1;   // intervalCount
>>>>>>> miniblink49
        if (count) {
            memcpy(runs, line->firstX(), count * sizeof(SkRegion::RunType));
            runs += count;
        }
        *runs++ = SkRegion::kRunTypeSentinel;
        line = line->nextScanline();
    } while (line < stop);
    SkASSERT(line == stop);
    *runs = SkRegion::kRunTypeSentinel;
}

<<<<<<< HEAD
static unsigned verb_to_initial_last_index(unsigned verb)
{
    static const uint8_t gPathVerbToInitialLastIndex[] = {
        0, //  kMove_Verb
        1, //  kLine_Verb
        2, //  kQuad_Verb
        2, //  kConic_Verb
        3, //  kCubic_Verb
        0, //  kClose_Verb
        0 //  kDone_Verb
=======
static unsigned verb_to_initial_last_index(unsigned verb) {
    static const uint8_t gPathVerbToInitialLastIndex[] = {
        0,  //  kMove_Verb
        1,  //  kLine_Verb
        2,  //  kQuad_Verb
        2,  //  kConic_Verb
        3,  //  kCubic_Verb
        0,  //  kClose_Verb
        0   //  kDone_Verb
>>>>>>> miniblink49
    };
    SkASSERT((unsigned)verb < SK_ARRAY_COUNT(gPathVerbToInitialLastIndex));
    return gPathVerbToInitialLastIndex[verb];
}

<<<<<<< HEAD
static unsigned verb_to_max_edges(unsigned verb)
{
    static const uint8_t gPathVerbToMaxEdges[] = {
        0, //  kMove_Verb
        1, //  kLine_Verb
        2, //  kQuad_VerbB
        2, //  kConic_VerbB
        3, //  kCubic_Verb
        0, //  kClose_Verb
        0 //  kDone_Verb
=======
static unsigned verb_to_max_edges(unsigned verb) {
    static const uint8_t gPathVerbToMaxEdges[] = {
        0,  //  kMove_Verb
        1,  //  kLine_Verb
        2,  //  kQuad_VerbB
        2,  //  kConic_VerbB
        3,  //  kCubic_Verb
        0,  //  kClose_Verb
        0   //  kDone_Verb
>>>>>>> miniblink49
    };
    SkASSERT((unsigned)verb < SK_ARRAY_COUNT(gPathVerbToMaxEdges));
    return gPathVerbToMaxEdges[verb];
}

// If returns 0, ignore itop and ibot
<<<<<<< HEAD
static int count_path_runtype_values(const SkPath& path, int* itop, int* ibot)
{
    SkPath::Iter iter(path, true);
    SkPoint pts[4];
    SkPath::Verb verb;

    int maxEdges = 0;
    SkScalar top = SkIntToScalar(SK_MaxS16);
    SkScalar bot = SkIntToScalar(SK_MinS16);
=======
static int count_path_runtype_values(const SkPath& path, int* itop, int* ibot) {
    SkPath::Iter    iter(path, true);
    SkPoint         pts[4];
    SkPath::Verb    verb;

    int maxEdges = 0;
    SkScalar    top = SkIntToScalar(SK_MaxS16);
    SkScalar    bot = SkIntToScalar(SK_MinS16);
>>>>>>> miniblink49

    while ((verb = iter.next(pts, false)) != SkPath::kDone_Verb) {
        maxEdges += verb_to_max_edges(verb);

        int lastIndex = verb_to_initial_last_index(verb);
        if (lastIndex > 0) {
            for (int i = 1; i <= lastIndex; i++) {
                if (top > pts[i].fY) {
                    top = pts[i].fY;
                } else if (bot < pts[i].fY) {
                    bot = pts[i].fY;
                }
            }
        } else if (SkPath::kMove_Verb == verb) {
            if (top > pts[0].fY) {
                top = pts[0].fY;
            } else if (bot < pts[0].fY) {
                bot = pts[0].fY;
            }
        }
    }
    if (0 == maxEdges) {
<<<<<<< HEAD
        return 0; // we have only moves+closes
=======
        return 0;   // we have only moves+closes
>>>>>>> miniblink49
    }

    SkASSERT(top <= bot);
    *itop = SkScalarRoundToInt(top);
    *ibot = SkScalarRoundToInt(bot);
    return maxEdges;
}

<<<<<<< HEAD
static bool check_inverse_on_empty_return(SkRegion* dst, const SkPath& path, const SkRegion& clip)
{
=======
static bool check_inverse_on_empty_return(SkRegion* dst, const SkPath& path, const SkRegion& clip) {
>>>>>>> miniblink49
    if (path.isInverseFillType()) {
        return dst->set(clip);
    } else {
        return dst->setEmpty();
    }
}

<<<<<<< HEAD
bool SkRegion::setPath(const SkPath& path, const SkRegion& clip)
{
    SkDEBUGCODE(this->validate();)

        if (clip.isEmpty())
    {
=======
bool SkRegion::setPath(const SkPath& path, const SkRegion& clip) {
    SkDEBUGCODE(this->validate();)

    if (clip.isEmpty()) {
>>>>>>> miniblink49
        return this->setEmpty();
    }

    if (path.isEmpty()) {
        return check_inverse_on_empty_return(this, path, clip);
    }

    //  compute worst-case rgn-size for the path
    int pathTop, pathBot;
    int pathTransitions = count_path_runtype_values(path, &pathTop, &pathBot);
    if (0 == pathTransitions) {
        return check_inverse_on_empty_return(this, path, clip);
    }

    int clipTop, clipBot;
    int clipTransitions = clip.count_runtype_values(&clipTop, &clipBot);

    int top = SkMax32(pathTop, clipTop);
    int bot = SkMin32(pathBot, clipBot);
    if (top >= bot) {
        return check_inverse_on_empty_return(this, path, clip);
    }

    SkRgnBuilder builder;

    if (!builder.init(bot - top,
<<<<<<< HEAD
            SkMax32(pathTransitions, clipTransitions),
            path.isInverseFillType())) {
=======
                      SkMax32(pathTransitions, clipTransitions),
                      path.isInverseFillType())) {
>>>>>>> miniblink49
        // can't allocate working space, so return false
        return this->setEmpty();
    }

    SkScan::FillPath(path, clip, &builder);
    builder.done();

    int count = builder.computeRunCount();
    if (count == 0) {
        return this->setEmpty();
    } else if (count == kRectRegionRuns) {
        builder.copyToRect(&fBounds);
        this->setRect(fBounds);
    } else {
        SkRegion tmp;

        tmp.fRunHead = RunHead::Alloc(count);
        builder.copyToRgn(tmp.fRunHead->writable_runs());
        tmp.fRunHead->computeRunBounds(&tmp.fBounds);
        this->swap(tmp);
    }
<<<<<<< HEAD
    SkDEBUGCODE(this->validate();) return true;
=======
    SkDEBUGCODE(this->validate();)
    return true;
>>>>>>> miniblink49
}

/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

struct Edge {
    enum {
        kY0Link = 0x01,
        kY1Link = 0x02,

        kCompleteLink = (kY0Link | kY1Link)
    };

    SkRegion::RunType fX;
    SkRegion::RunType fY0, fY1;
    uint8_t fFlags;
<<<<<<< HEAD
    Edge* fNext;

    void set(int x, int y0, int y1)
    {
=======
    Edge*   fNext;

    void set(int x, int y0, int y1) {
>>>>>>> miniblink49
        SkASSERT(y0 != y1);

        fX = (SkRegion::RunType)(x);
        fY0 = (SkRegion::RunType)(y0);
        fY1 = (SkRegion::RunType)(y1);
        fFlags = 0;
<<<<<<< HEAD
        SkDEBUGCODE(fNext = nullptr;)
    }

    int top() const
    {
=======
        SkDEBUGCODE(fNext = NULL;)
    }

    int top() const {
>>>>>>> miniblink49
        return SkFastMin32(fY0, fY1);
    }
};

<<<<<<< HEAD
static void find_link(Edge* base, Edge* stop)
{
=======
static void find_link(Edge* base, Edge* stop) {
>>>>>>> miniblink49
    SkASSERT(base < stop);

    if (base->fFlags == Edge::kCompleteLink) {
        SkASSERT(base->fNext);
        return;
    }

    SkASSERT(base + 1 < stop);

    int y0 = base->fY0;
    int y1 = base->fY1;

    Edge* e = base;
    if ((base->fFlags & Edge::kY0Link) == 0) {
        for (;;) {
            e += 1;
            if ((e->fFlags & Edge::kY1Link) == 0 && y0 == e->fY1) {
<<<<<<< HEAD
                SkASSERT(nullptr == e->fNext);
=======
                SkASSERT(NULL == e->fNext);
>>>>>>> miniblink49
                e->fNext = base;
                e->fFlags = SkToU8(e->fFlags | Edge::kY1Link);
                break;
            }
        }
    }

    e = base;
    if ((base->fFlags & Edge::kY1Link) == 0) {
        for (;;) {
            e += 1;
            if ((e->fFlags & Edge::kY0Link) == 0 && y1 == e->fY0) {
<<<<<<< HEAD
                SkASSERT(nullptr == base->fNext);
=======
                SkASSERT(NULL == base->fNext);
>>>>>>> miniblink49
                base->fNext = e;
                e->fFlags = SkToU8(e->fFlags | Edge::kY0Link);
                break;
            }
        }
    }

    base->fFlags = Edge::kCompleteLink;
}

<<<<<<< HEAD
static int extract_path(Edge* edge, Edge* stop, SkPath* path)
{
=======
static int extract_path(Edge* edge, Edge* stop, SkPath* path) {
>>>>>>> miniblink49
    while (0 == edge->fFlags) {
        edge++; // skip over "used" edges
    }

    SkASSERT(edge < stop);

    Edge* base = edge;
    Edge* prev = edge;
    edge = edge->fNext;
    SkASSERT(edge != base);

    int count = 1;
    path->moveTo(SkIntToScalar(prev->fX), SkIntToScalar(prev->fY0));
    prev->fFlags = 0;
    do {
        if (prev->fX != edge->fX || prev->fY1 != edge->fY0) { // skip collinear
<<<<<<< HEAD
            path->lineTo(SkIntToScalar(prev->fX), SkIntToScalar(prev->fY1)); // V
            path->lineTo(SkIntToScalar(edge->fX), SkIntToScalar(edge->fY0)); // H
=======
            path->lineTo(SkIntToScalar(prev->fX), SkIntToScalar(prev->fY1));    // V
            path->lineTo(SkIntToScalar(edge->fX), SkIntToScalar(edge->fY0));    // H
>>>>>>> miniblink49
        }
        prev = edge;
        edge = edge->fNext;
        count += 1;
        prev->fFlags = 0;
    } while (edge != base);
<<<<<<< HEAD
    path->lineTo(SkIntToScalar(prev->fX), SkIntToScalar(prev->fY1)); // V
=======
    path->lineTo(SkIntToScalar(prev->fX), SkIntToScalar(prev->fY1));    // V
>>>>>>> miniblink49
    path->close();
    return count;
}

<<<<<<< HEAD
struct EdgeLT {
    bool operator()(const Edge& a, const Edge& b) const
    {
        return (a.fX == b.fX) ? a.top() < b.top() : a.fX < b.fX;
    }
};

bool SkRegion::getBoundaryPath(SkPath* path) const
{
    // path could safely be nullptr if we're empty, but the caller shouldn't
=======
#include "SkTSearch.h"

static int EdgeProc(const Edge* a, const Edge* b) {
    return (a->fX == b->fX) ? a->top() - b->top() : a->fX - b->fX;
}

bool SkRegion::getBoundaryPath(SkPath* path) const {
    // path could safely be NULL if we're empty, but the caller shouldn't
>>>>>>> miniblink49
    // *know* that
    SkASSERT(path);

    if (this->isEmpty()) {
        return false;
    }

    const SkIRect& bounds = this->getBounds();

    if (this->isRect()) {
<<<<<<< HEAD
        SkRect r;
        r.set(bounds); // this converts the ints to scalars
=======
        SkRect  r;
        r.set(bounds);      // this converts the ints to scalars
>>>>>>> miniblink49
        path->addRect(r);
        return true;
    }

<<<<<<< HEAD
    SkRegion::Iterator iter(*this);
    SkTDArray<Edge> edges;
=======
    SkRegion::Iterator  iter(*this);
    SkTDArray<Edge>     edges;
>>>>>>> miniblink49

    for (const SkIRect& r = iter.rect(); !iter.done(); iter.next()) {
        Edge* edge = edges.append(2);
        edge[0].set(r.fLeft, r.fBottom, r.fTop);
        edge[1].set(r.fRight, r.fTop, r.fBottom);
    }
<<<<<<< HEAD
=======
    qsort(edges.begin(), edges.count(), sizeof(Edge), SkCastForQSort(EdgeProc));
>>>>>>> miniblink49

    int count = edges.count();
    Edge* start = edges.begin();
    Edge* stop = start + count;
<<<<<<< HEAD
    SkTQSort<Edge>(start, stop - 1, EdgeLT());

    Edge* e;
=======
    Edge* e;

>>>>>>> miniblink49
    for (e = start; e != stop; e++) {
        find_link(e, stop);
    }

#ifdef SK_DEBUG
    for (e = start; e != stop; e++) {
<<<<<<< HEAD
        SkASSERT(e->fNext != nullptr);
=======
        SkASSERT(e->fNext != NULL);
>>>>>>> miniblink49
        SkASSERT(e->fFlags == Edge::kCompleteLink);
    }
#endif

    path->incReserve(count << 1);
    do {
        SkASSERT(count > 1);
        count -= extract_path(start, stop, path);
    } while (count > 0);

    return true;
}
