/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "GrBatchAtlas.h"
<<<<<<< HEAD
#include "GrBatchFlushState.h"
#include "GrRectanizer.h"
#include "GrTracing.h"

////////////////////////////////////////////////////////////////////////////////

GrBatchAtlas::BatchPlot::BatchPlot(int index, uint64_t genID, int offX, int offY, int width,
    int height, GrPixelConfig config)
    : fLastUpload(GrBatchDrawToken::AlreadyFlushedToken())
    , fLastUse(GrBatchDrawToken::AlreadyFlushedToken())
    , fIndex(index)
    , fGenID(genID)
    , fID(CreateId(fIndex, fGenID))
    , fData(nullptr)
    , fWidth(width)
    , fHeight(height)
    , fX(offX)
    , fY(offY)
    , fRects(nullptr)
    , fOffset(SkIPoint16::Make(fX * fWidth, fY * fHeight))
    , fConfig(config)
    , fBytesPerPixel(GrBytesPerPixel(config))
#ifdef SK_DEBUG
    , fDirty(false)
#endif
{
    fDirtyRect.setEmpty();
}

GrBatchAtlas::BatchPlot::~BatchPlot()
{
    sk_free(fData);
    delete fRects;
}

bool GrBatchAtlas::BatchPlot::addSubImage(int width, int height, const void* image,
    SkIPoint16* loc)
{
    SkASSERT(width <= fWidth && height <= fHeight);

    if (!fRects) {
        fRects = GrRectanizer::Factory(fWidth, fHeight);
    }

    if (!fRects->addRect(width, height, loc)) {
        return false;
    }

    if (!fData) {
        fData = reinterpret_cast<unsigned char*>(sk_calloc_throw(fBytesPerPixel * fWidth * fHeight));
    }
    size_t rowBytes = width * fBytesPerPixel;
    const unsigned char* imagePtr = (const unsigned char*)image;
    // point ourselves at the right starting spot
    unsigned char* dataPtr = fData;
    dataPtr += fBytesPerPixel * fWidth * loc->fY;
    dataPtr += fBytesPerPixel * loc->fX;
    // copy into the data buffer
    for (int i = 0; i < height; ++i) {
        memcpy(dataPtr, imagePtr, rowBytes);
        dataPtr += fBytesPerPixel * fWidth;
        imagePtr += rowBytes;
    }

    fDirtyRect.join(loc->fX, loc->fY, loc->fX + width, loc->fY + height);

    loc->fX += fOffset.fX;
    loc->fY += fOffset.fY;
    SkDEBUGCODE(fDirty = true;)

        return true;
}

void GrBatchAtlas::BatchPlot::uploadToTexture(GrDrawBatch::WritePixelsFn& writePixels,
    GrTexture* texture)
{
    // We should only be issuing uploads if we are in fact dirty
    SkASSERT(fDirty && fData && texture);
    TRACE_EVENT0(TRACE_DISABLED_BY_DEFAULT("skia.gpu"), "GrBatchPlot::uploadToTexture");
    size_t rowBytes = fBytesPerPixel * fWidth;
    const unsigned char* dataPtr = fData;
    dataPtr += rowBytes * fDirtyRect.fTop;
    dataPtr += fBytesPerPixel * fDirtyRect.fLeft;
    writePixels(texture, fOffset.fX + fDirtyRect.fLeft, fOffset.fY + fDirtyRect.fTop,
        fDirtyRect.width(), fDirtyRect.height(), fConfig, dataPtr, rowBytes);
    fDirtyRect.setEmpty();
    SkDEBUGCODE(fDirty = false;)
}

void GrBatchAtlas::BatchPlot::resetRects()
{
    if (fRects) {
        fRects->reset();
    }

    fGenID++;
    fID = CreateId(fIndex, fGenID);

    // zero out the plot
    if (fData) {
        sk_bzero(fData, fBytesPerPixel * fWidth * fHeight);
    }

    fDirtyRect.setEmpty();
    SkDEBUGCODE(fDirty = false;)
}
=======
#include "GrBatchTarget.h"
#include "GrGpu.h"
#include "GrRectanizer.h"
#include "GrTracing.h"
#include "GrVertexBuffer.h"

static inline void adjust_for_offset(SkIPoint16* loc, const SkIPoint16& offset) {
    loc->fX += offset.fX;
    loc->fY += offset.fY;
}

static GrBatchAtlas::AtlasID create_id(uint32_t index, uint64_t generation) {
    SkASSERT(index < (1 << 16));
    SkASSERT(generation < ((uint64_t)1 << 48));
    return generation << 16 | index;
}

// The backing GrTexture for a GrBatchAtlas is broken into a spatial grid of GrBatchPlots.
// The GrBatchPlots keep track of subimage placement via their GrRectanizer. In turn, a GrBatchPlot
// manages the lifetime of its data using two tokens, a last ref toke and a last upload token.
// Once a GrBatchPlot is "full" (i.e. there is no room for the new subimage according to the
// GrRectanizer), it can no longer be used unless the last ref on the GrPlot has already been
// flushed through to the gpu.

class BatchPlot : public SkRefCnt {
public:
    typedef GrBatchAtlas::BatchToken BatchToken;
    
    SK_DECLARE_INTERNAL_LLIST_INTERFACE(BatchPlot);

    // index() refers to the index of the plot in the owning GrAtlas's plot array.  genID() is a
    // monotonically incrementing number which is bumped every time the cpu backing store is
    // wiped, or when the plot itself is evicted from the atlas(ie, there is continuity in genID()
    // across atlas spills)
    uint32_t index() const { return fIndex; }
    uint64_t genID() const { return fGenID; }
    GrBatchAtlas::AtlasID id() { return fID; }

    GrTexture* texture() const { return fTexture; }

    bool addSubImage(int width, int height, const void* image, SkIPoint16* loc, size_t rowBytes)  {
        if (!fRects->addRect(width, height, loc)) {
            return false;
        }

        if (!fData) {
            fData = reinterpret_cast<unsigned char*>(sk_calloc_throw(fBytesPerPixel * fWidth *
                                                                     fHeight));
        }
        const unsigned char* imagePtr = (const unsigned char*)image;
        // point ourselves at the right starting spot
        unsigned char* dataPtr = fData;
        dataPtr += fBytesPerPixel * fWidth * loc->fY;
        dataPtr += fBytesPerPixel * loc->fX;
        // copy into the data buffer
        for (int i = 0; i < height; ++i) {
            memcpy(dataPtr, imagePtr, rowBytes);
            dataPtr += fBytesPerPixel * fWidth;
            imagePtr += rowBytes;
        }

        fDirtyRect.join(loc->fX, loc->fY, loc->fX + width, loc->fY + height);
        adjust_for_offset(loc, fOffset);
        SkDEBUGCODE(fDirty = true;)

        return true;
    }

    // to manage the lifetime of a plot, we use two tokens.  We use last upload token to know when
    // we can 'piggy back' uploads, ie if the last upload hasn't been flushed to gpu, we don't need
    // to issue a new upload even if we update the cpu backing store.  We use lastref to determine
    // when we can evict a plot from the cache, ie if the last ref has already flushed through
    // the gpu then we can reuse the plot
    BatchToken lastUploadToken() const { return fLastUpload; }
    BatchToken lastUseToken() const { return fLastUse; }
    void setLastUploadToken(BatchToken batchToken) {
        SkASSERT(batchToken >= fLastUpload);
        fLastUpload = batchToken;
    }
    void setLastUseToken(BatchToken batchToken) {
        SkASSERT(batchToken >= fLastUse);
        fLastUse = batchToken;
    }

    void uploadToTexture(GrBatchTarget::TextureUploader uploader)  {
        // We should only be issuing uploads if we are in fact dirty
        SkASSERT(fDirty && fData && fTexture);
        TRACE_EVENT0(TRACE_DISABLED_BY_DEFAULT("skia.gpu"), "GrBatchPlot::uploadToTexture");
        size_t rowBytes = fBytesPerPixel * fRects->width();
        const unsigned char* dataPtr = fData;
        dataPtr += rowBytes * fDirtyRect.fTop;
        dataPtr += fBytesPerPixel * fDirtyRect.fLeft;
        uploader.writeTexturePixels(fTexture,
                                    fOffset.fX + fDirtyRect.fLeft, fOffset.fY + fDirtyRect.fTop,
                                    fDirtyRect.width(), fDirtyRect.height(),
                                    fTexture->config(), dataPtr, rowBytes);
        fDirtyRect.setEmpty();
        SkDEBUGCODE(fDirty = false;)
    }

    void resetRects() {
        SkASSERT(fRects);
        fRects->reset();
        fGenID++;
        fID = create_id(fIndex, fGenID);

        // zero out the plot
        if (fData) {
            sk_bzero(fData, fBytesPerPixel * fWidth * fHeight);
        }

        fDirtyRect.setEmpty();
        SkDEBUGCODE(fDirty = false;)
    }

    uint32_t x() const { return fX; }
    uint32_t y() const { return fY; }

private:
    BatchPlot()
        : fLastUpload(0)
        , fLastUse(0)
        , fIndex(-1)
        , fGenID(-1)
        , fID(0)
        , fData(NULL)
        , fWidth(0)
        , fHeight(0)
        , fX(0)
        , fY(0)
        , fTexture(NULL)
        , fRects(NULL)
        , fAtlas(NULL)
        , fBytesPerPixel(1)
    #ifdef SK_DEBUG
        , fDirty(false)
    #endif
    {
        fOffset.set(0, 0);
    }

    ~BatchPlot() {
        sk_free(fData);
        fData = NULL;
        delete fRects;
    }

    void init(GrBatchAtlas* atlas, GrTexture* texture, int index, uint64_t generation,
              int offX, int offY, int width, int height, size_t bpp) {
        fIndex = index;
        fGenID = generation;
        fID = create_id(index, generation);
        fWidth = width;
        fHeight = height;
        fX = offX;
        fY = offY;
        fRects = GrRectanizer::Factory(width, height);
        fAtlas = atlas;
        fOffset.set(offX * width, offY * height);
        fBytesPerPixel = bpp;
        fData = NULL;
        fDirtyRect.setEmpty();
        SkDEBUGCODE(fDirty = false;)
        fTexture = texture;
    }

    BatchToken fLastUpload;
    BatchToken fLastUse;

    uint32_t fIndex;
    uint64_t fGenID;
    GrBatchAtlas::AtlasID fID;
    unsigned char* fData;
    uint32_t fWidth;
    uint32_t fHeight;
    uint32_t fX;
    uint32_t fY;
    GrTexture* fTexture;
    GrRectanizer* fRects;
    GrBatchAtlas* fAtlas;
    SkIPoint16 fOffset;        // the offset of the plot in the backing texture
    size_t fBytesPerPixel;
    SkIRect fDirtyRect;
    SkDEBUGCODE(bool fDirty;)

    friend class GrBatchAtlas;

    typedef SkRefCnt INHERITED;
};

////////////////////////////////////////////////////////////////////////////////

class GrPlotUploader : public GrBatchTarget::Uploader {
public:
    GrPlotUploader(BatchPlot* plot)
        : INHERITED(plot->lastUploadToken())
        , fPlot(SkRef(plot)) {
        SkASSERT(plot);
    }

    void upload(GrBatchTarget::TextureUploader uploader) override {
        fPlot->uploadToTexture(uploader);
    }

private:
    SkAutoTUnref<BatchPlot> fPlot;

    typedef GrBatchTarget::Uploader INHERITED;
};
>>>>>>> miniblink49

///////////////////////////////////////////////////////////////////////////////

GrBatchAtlas::GrBatchAtlas(GrTexture* texture, int numPlotsX, int numPlotsY)
    : fTexture(texture)
<<<<<<< HEAD
    , fAtlasGeneration(kInvalidAtlasGeneration + 1)
{

    fPlotWidth = texture->width() / numPlotsX;
    fPlotHeight = texture->height() / numPlotsY;
    SkASSERT(numPlotsX * numPlotsY <= BulkUseTokenUpdater::kMaxPlots);
    SkASSERT(fPlotWidth * numPlotsX == texture->width());
    SkASSERT(fPlotHeight * numPlotsY == texture->height());

    SkDEBUGCODE(fNumPlots = numPlotsX * numPlotsY;)

        // We currently do not support compressed atlases...
        SkASSERT(!GrPixelConfigIsCompressed(texture->desc().fConfig));

    // set up allocated plots
    fPlotArray = new SkAutoTUnref<BatchPlot>[numPlotsX * numPlotsY];

    SkAutoTUnref<BatchPlot>* currPlot = fPlotArray;
    for (int y = numPlotsY - 1, r = 0; y >= 0; --y, ++r) {
        for (int x = numPlotsX - 1, c = 0; x >= 0; --x, ++c) {
            uint32_t index = r * numPlotsX + c;
            currPlot->reset(new BatchPlot(index, 1, x, y, fPlotWidth, fPlotHeight,
                texture->desc().fConfig));
=======
    , fNumPlotsX(numPlotsX)
    , fNumPlotsY(numPlotsY)
    , fPlotWidth(texture->width() / numPlotsX)
    , fPlotHeight(texture->height() / numPlotsY)
    , fAtlasGeneration(kInvalidAtlasGeneration + 1) {
    SkASSERT(fNumPlotsX * fNumPlotsY <= BulkUseTokenUpdater::kMaxPlots);
    SkASSERT(fPlotWidth * fNumPlotsX == static_cast<uint32_t>(texture->width()));
    SkASSERT(fPlotHeight * fNumPlotsY == static_cast<uint32_t>(texture->height()));

    // We currently do not support compressed atlases...
    SkASSERT(!GrPixelConfigIsCompressed(texture->desc().fConfig));

    // set up allocated plots
    fBPP = GrBytesPerPixel(texture->desc().fConfig);
    fPlotArray = SkNEW_ARRAY(SkAutoTUnref<BatchPlot>, (fNumPlotsX * fNumPlotsY));

    SkAutoTUnref<BatchPlot>* currPlot = fPlotArray;
    for (int y = fNumPlotsY - 1, r = 0; y >= 0; --y, ++r) {
        for (int x = fNumPlotsX - 1, c = 0; x >= 0; --x, ++c) {
            uint32_t id = r * fNumPlotsX + c;
            currPlot->reset(SkNEW(BatchPlot));
            (*currPlot)->init(this, texture, id, 1, x, y, fPlotWidth, fPlotHeight, fBPP);
>>>>>>> miniblink49

            // build LRU list
            fPlotList.addToHead(currPlot->get());
            ++currPlot;
        }
    }
}

<<<<<<< HEAD
GrBatchAtlas::~GrBatchAtlas()
{
    SkSafeUnref(fTexture);
    delete[] fPlotArray;
}

void GrBatchAtlas::processEviction(AtlasID id)
{
=======
GrBatchAtlas::~GrBatchAtlas() {
    SkSafeUnref(fTexture);
    SkDELETE_ARRAY(fPlotArray);
}

void GrBatchAtlas::processEviction(AtlasID id) {
>>>>>>> miniblink49
    for (int i = 0; i < fEvictionCallbacks.count(); i++) {
        (*fEvictionCallbacks[i].fFunc)(id, fEvictionCallbacks[i].fData);
    }
}

<<<<<<< HEAD
inline void GrBatchAtlas::updatePlot(GrDrawBatch::Target* target, AtlasID* id, BatchPlot* plot)
{
=======
void GrBatchAtlas::makeMRU(BatchPlot* plot) {
    if (fPlotList.head() == plot) {
        return;
    }

    fPlotList.remove(plot);
    fPlotList.addToHead(plot);
}

inline void GrBatchAtlas::updatePlot(GrBatchTarget* batchTarget, AtlasID* id, BatchPlot* plot) {
>>>>>>> miniblink49
    this->makeMRU(plot);

    // If our most recent upload has already occurred then we have to insert a new
    // upload. Otherwise, we already have a scheduled upload that hasn't yet ocurred.
    // This new update will piggy back on that previously scheduled update.
<<<<<<< HEAD
    if (target->hasDrawBeenFlushed(plot->lastUploadToken())) {
        // With c+14 we could move sk_sp into lamba to only ref once.
        sk_sp<BatchPlot> plotsp(SkRef(plot));
        GrTexture* texture = fTexture;
        GrBatchDrawToken lastUploadToken = target->addAsapUpload(
            [plotsp, texture](GrDrawBatch::WritePixelsFn& writePixels) {
                plotsp->uploadToTexture(writePixels, texture);
            });
        plot->setLastUploadToken(lastUploadToken);
=======
    if (batchTarget->isIssued(plot->lastUploadToken())) {
        plot->setLastUploadToken(batchTarget->asapToken());
        SkAutoTUnref<GrPlotUploader> uploader(SkNEW_ARGS(GrPlotUploader, (plot)));
        batchTarget->upload(uploader);
>>>>>>> miniblink49
    }
    *id = plot->id();
}

<<<<<<< HEAD
bool GrBatchAtlas::addToAtlas(AtlasID* id, GrDrawBatch::Target* target,
    int width, int height, const void* image, SkIPoint16* loc)
{
    // We should already have a texture, TODO clean this up
    SkASSERT(fTexture);
    if (width > fPlotWidth || height > fPlotHeight) {
        return false;
    }
=======
bool GrBatchAtlas::addToAtlas(AtlasID* id, GrBatchTarget* batchTarget,
                              int width, int height, const void* image, SkIPoint16* loc) {
    // We should already have a texture, TODO clean this up
    SkASSERT(fTexture &&
             static_cast<uint32_t>(width) <= fPlotWidth &&
             static_cast<uint32_t>(height) <= fPlotHeight);
>>>>>>> miniblink49

    // now look through all allocated plots for one we can share, in Most Recently Refed order
    GrBatchPlotList::Iter plotIter;
    plotIter.init(fPlotList, GrBatchPlotList::Iter::kHead_IterStart);
    BatchPlot* plot;
    while ((plot = plotIter.get())) {
<<<<<<< HEAD
        SkASSERT(GrBytesPerPixel(fTexture->desc().fConfig) == plot->bpp());
        if (plot->addSubImage(width, height, image, loc)) {
            this->updatePlot(target, id, plot);
=======
        if (plot->addSubImage(width, height, image, loc, fBPP * width)) {
            this->updatePlot(batchTarget, id, plot);
>>>>>>> miniblink49
            return true;
        }
        plotIter.next();
    }

    // If the above fails, then see if the least recently refed plot has already been flushed to the
    // gpu
<<<<<<< HEAD
    plot = fPlotList.tail();
    SkASSERT(plot);
    if (target->hasDrawBeenFlushed(plot->lastUseToken())) {
        this->processEviction(plot->id());
        plot->resetRects();
        SkASSERT(GrBytesPerPixel(fTexture->desc().fConfig) == plot->bpp());
        SkDEBUGCODE(bool verify =) plot->addSubImage(width, height, image, loc);
        SkASSERT(verify);
        this->updatePlot(target, id, plot);
=======
    plotIter.init(fPlotList, GrBatchPlotList::Iter::kTail_IterStart);
    plot = plotIter.get();
    SkASSERT(plot);
    if (batchTarget->isIssued(plot->lastUseToken())) {
        this->processEviction(plot->id());
        plot->resetRects();
        SkDEBUGCODE(bool verify = )plot->addSubImage(width, height, image, loc, fBPP * width);
        SkASSERT(verify);
        this->updatePlot(batchTarget, id, plot);
>>>>>>> miniblink49
        fAtlasGeneration++;
        return true;
    }

<<<<<<< HEAD
    // If this plot has been used in a draw that is currently being prepared by a batch, then we
    // have to fail. This gives the batch a chance to enqueue the draw, and call back into this
    // function. When that draw is enqueued, the draw token advances, and the subsequent call will
    // continue past this branch and prepare an inline upload that will occur after the enqueued
    // draw which references the plot's pre-upload content.
    if (plot->lastUseToken() == target->nextDrawToken()) {
        return false;
    }

    SkASSERT(!plot->unique()); // The GrPlotUpdater should have a ref too
=======
    // The least recently refed plot hasn't been flushed to the gpu yet, however, if we have flushed
    // it to the batch target than we can reuse it.  Our last ref token is guaranteed to be less
    // than or equal to the current token.  If its 'less than' the current token, than we can spin
    // off the plot(ie let the batch target manage it) and create a new plot in its place in our
    // array.  If it is equal to the currentToken, then the caller has to flush draws to the batch
    // target so we can spin off the plot
    if (plot->lastUseToken() == batchTarget->currentToken()) {
        return false;
    }

    // We take an extra ref here so our plot isn't deleted when we reset its index in the array.
    plot->ref();
    int index = plot->index();
    int x = plot->x();
    int y = plot->y();
    uint64_t generation = plot->genID();
>>>>>>> miniblink49

    this->processEviction(plot->id());
    fPlotList.remove(plot);
    SkAutoTUnref<BatchPlot>& newPlot = fPlotArray[plot->index()];
<<<<<<< HEAD
    newPlot.reset(plot->clone());

    fPlotList.addToHead(newPlot.get());
    SkASSERT(GrBytesPerPixel(fTexture->desc().fConfig) == newPlot->bpp());
    SkDEBUGCODE(bool verify =) newPlot->addSubImage(width, height, image, loc);
    SkASSERT(verify);

    // Note that this plot will be uploaded inline with the draws whereas the
    // one it displaced most likely was uploaded asap.
    // With c+14 we could move sk_sp into lamba to only ref once.
    sk_sp<BatchPlot> plotsp(SkRef(newPlot.get()));
    GrTexture* texture = fTexture;
    GrBatchDrawToken lastUploadToken = target->addInlineUpload(
        [plotsp, texture](GrDrawBatch::WritePixelsFn& writePixels) {
            plotsp->uploadToTexture(writePixels, texture);
        });
    newPlot->setLastUploadToken(lastUploadToken);

    *id = newPlot->id();

    fAtlasGeneration++;
    return true;
}
=======
    newPlot.reset(SkNEW(BatchPlot));
    newPlot->init(this, fTexture, index, ++generation, x, y, fPlotWidth, fPlotHeight, fBPP);

    fPlotList.addToHead(newPlot.get());
    SkDEBUGCODE(bool verify = )newPlot->addSubImage(width, height, image, loc, fBPP * width);
    SkASSERT(verify);
    newPlot->setLastUploadToken(batchTarget->currentToken());
    SkAutoTUnref<GrPlotUploader> uploader(SkNEW_ARGS(GrPlotUploader, (newPlot)));
    batchTarget->upload(uploader);
    *id = newPlot->id();
    plot->unref();
    fAtlasGeneration++;
    return true;
}

bool GrBatchAtlas::hasID(AtlasID id) {
    uint32_t index = GetIndexFromID(id);
    SkASSERT(index < fNumPlotsX * fNumPlotsY);
    return fPlotArray[index]->genID() == GetGenerationFromID(id);
}

void GrBatchAtlas::setLastUseToken(AtlasID id, BatchToken batchToken) {
    SkASSERT(this->hasID(id));
    uint32_t index = GetIndexFromID(id);
    SkASSERT(index < fNumPlotsX * fNumPlotsY);
    this->makeMRU(fPlotArray[index]);
    fPlotArray[index]->setLastUseToken(batchToken);
}

void GrBatchAtlas::setLastUseTokenBulk(const BulkUseTokenUpdater& updater, BatchToken batchToken) {
    int count = updater.fPlotsToUpdate.count();
    for (int i = 0; i < count; i++) {
        BatchPlot* plot = fPlotArray[updater.fPlotsToUpdate[i]];
        this->makeMRU(plot);
        plot->setLastUseToken(batchToken);
    }
}
>>>>>>> miniblink49
