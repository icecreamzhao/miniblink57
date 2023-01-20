/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "GrRecordReplaceDraw.h"
#include "GrContext.h"
#include "GrLayerCache.h"
#include "SkBigPicture.h"
#include "SkCanvasPriv.h"
#include "SkGr.h"
=======
#include "GrContext.h"
#include "GrLayerCache.h"
#include "GrRecordReplaceDraw.h"
#include "SkBigPicture.h"
#include "SkCanvasPriv.h"
#include "SkGrPixelRef.h"
>>>>>>> miniblink49
#include "SkImage.h"
#include "SkRecordDraw.h"
#include "SkRecords.h"

<<<<<<< HEAD
static inline void draw_replacement_bitmap(GrCachedLayer* layer, SkCanvas* canvas)
{
=======
static inline void wrap_texture(GrTexture* texture, int width, int height, SkBitmap* result) {
    SkImageInfo info = SkImageInfo::MakeN32Premul(width, height);
    result->setInfo(info);
    result->setPixelRef(SkNEW_ARGS(SkGrPixelRef, (info, texture)))->unref();
}

static inline void draw_replacement_bitmap(GrCachedLayer* layer, SkCanvas* canvas) {
>>>>>>> miniblink49

    // Some image filter can totally filter away a layer (e.g., SkPictureImageFilter's with
    // no picture).
    if (!layer->texture()) {
        return;
    }

    SkBitmap bm;
<<<<<<< HEAD
    GrWrapTextureInBitmap(layer->texture(),
        !layer->isAtlased() ? layer->rect().width() : layer->texture()->width(),
        !layer->isAtlased() ? layer->rect().height() : layer->texture()->height(),
        false,
        &bm);

    canvas->save();
    canvas->setMatrix(SkMatrix::I());
=======
    wrap_texture(layer->texture(),
                 !layer->isAtlased() ? layer->rect().width()  : layer->texture()->width(),
                 !layer->isAtlased() ? layer->rect().height() : layer->texture()->height(),
                 &bm);

>>>>>>> miniblink49
    if (layer->isAtlased()) {
        const SkRect src = SkRect::Make(layer->rect());
        const SkRect dst = SkRect::Make(layer->srcIR());

        SkASSERT(layer->offset().isZero());

<<<<<<< HEAD
        canvas->drawBitmapRect(bm, src, dst, layer->paint(), SkCanvas::kStrict_SrcRectConstraint);
    } else {
        canvas->drawBitmap(bm,
            SkIntToScalar(layer->srcIR().fLeft + layer->offset().fX),
            SkIntToScalar(layer->srcIR().fTop + layer->offset().fY),
            layer->paint());
    }
    canvas->restore();
=======
        canvas->save();
        canvas->setMatrix(SkMatrix::I());
        canvas->drawBitmapRectToRect(bm, &src, dst, layer->paint());
        canvas->restore();
    } else {
        canvas->drawSprite(bm,
                           layer->srcIR().fLeft + layer->offset().fX,
                           layer->srcIR().fTop + layer->offset().fY,
                           layer->paint());
    }
>>>>>>> miniblink49
}

// Used by GrRecordReplaceDraw. It intercepts nested drawPicture calls and
// also draws them with replaced layers.
class ReplaceDraw : public SkRecords::Draw {
public:
    ReplaceDraw(SkCanvas* canvas, GrLayerCache* layerCache,
<<<<<<< HEAD
        SkPicture const* const drawablePicts[], int drawableCount,
        const SkPicture* topLevelPicture,
        const SkBigPicture* picture,
        const SkMatrix& initialMatrix,
        SkPicture::AbortCallback* callback,
        const int* opIndices, int numIndices)
        : INHERITED(canvas, drawablePicts, nullptr, drawableCount)
=======
                SkPicture const* const drawablePicts[], int drawableCount,
                const SkPicture* topLevelPicture,
                const SkBigPicture* picture,
                const SkMatrix& initialMatrix,
                SkPicture::AbortCallback* callback,
                const unsigned* opIndices, int numIndices)
        : INHERITED(canvas, drawablePicts, NULL, drawableCount)
>>>>>>> miniblink49
        , fCanvas(canvas)
        , fLayerCache(layerCache)
        , fTopLevelPicture(topLevelPicture)
        , fPicture(picture)
        , fInitialMatrix(initialMatrix)
        , fCallback(callback)
        , fIndex(0)
<<<<<<< HEAD
        , fNumReplaced(0)
    {
        fOpIndexStack.append(numIndices, opIndices);
    }

    int draw()
    {
        const SkBBoxHierarchy* bbh = fPicture->bbh();
        const SkRecord* record = fPicture->record();
        if (nullptr == record) {
=======
        , fNumReplaced(0) {
        fOpIndexStack.append(numIndices, opIndices);
    }

    int draw() {
        const SkBBoxHierarchy* bbh = fPicture->bbh();
        const SkRecord* record = fPicture->record();
        if (NULL == record) {
>>>>>>> miniblink49
            return 0;
        }

        fNumReplaced = 0;

        fOps.rewind();

        if (bbh) {
            // Draw only ops that affect pixels in the canvas's current clip.
            // The SkRecord and BBH were recorded in identity space.  This canvas
            // is not necessarily in that same space.  getClipBounds() returns us
            // this canvas' clip bounds transformed back into identity space, which
            // lets us query the BBH.
            SkRect query = { 0, 0, 0, 0 };
            (void)fCanvas->getClipBounds(&query);

            bbh->search(query, &fOps);

            for (fIndex = 0; fIndex < fOps.count(); ++fIndex) {
                if (fCallback && fCallback->abort()) {
                    return fNumReplaced;
                }

<<<<<<< HEAD
                record->visit(fOps[fIndex], *this);
            }

        } else {
            for (fIndex = 0; fIndex < (int)record->count(); ++fIndex) {
=======
                record->visit<void>(fOps[fIndex], *this);
            }

        } else {
            for (fIndex = 0; fIndex < (int) record->count(); ++fIndex) {
>>>>>>> miniblink49
                if (fCallback && fCallback->abort()) {
                    return fNumReplaced;
                }

<<<<<<< HEAD
                record->visit(fIndex, *this);
=======
                record->visit<void>(fIndex, *this);
>>>>>>> miniblink49
            }
        }

        return fNumReplaced;
    }

    // Same as Draw for all ops except DrawPicture and SaveLayer.
<<<<<<< HEAD
    template <typename T>
    void operator()(const T& r)
    {
        this->INHERITED::operator()(r);
    }
    void operator()(const SkRecords::DrawPicture& dp)
    {
=======
    template <typename T> void operator()(const T& r) {
        this->INHERITED::operator()(r);
    }
    void operator()(const SkRecords::DrawPicture& dp) {
>>>>>>> miniblink49

        int drawPictureOffset;
        if (fOps.count()) {
            drawPictureOffset = fOps[fIndex];
        } else {
            drawPictureOffset = fIndex;
        }

        fOpIndexStack.push(drawPictureOffset);

        SkAutoCanvasMatrixPaint acmp(fCanvas, &dp.matrix, dp.paint, dp.picture->cullRect());

        if (const SkBigPicture* bp = dp.picture->asSkBigPicture()) {
            // Draw sub-pictures with the same replacement list but a different picture
            ReplaceDraw draw(fCanvas, fLayerCache,
<<<<<<< HEAD
                this->drawablePicts(), this->drawableCount(),
                fTopLevelPicture, bp, fInitialMatrix, fCallback,
                fOpIndexStack.begin(), fOpIndexStack.count());
=======
                             this->drawablePicts(), this->drawableCount(),
                             fTopLevelPicture, bp, fInitialMatrix, fCallback,
                             fOpIndexStack.begin(), fOpIndexStack.count());
>>>>>>> miniblink49
            fNumReplaced += draw.draw();
        } else {
            // TODO: can we assume / assert this doesn't happen?
            dp.picture->playback(fCanvas, fCallback);
        }

        fOpIndexStack.pop();
    }
<<<<<<< HEAD
    void operator()(const SkRecords::SaveLayer& sl)
    {

        // For a saveLayer command, check if it can be replaced by a drawBitmap
        // call and, if so, draw it and then update the current op index accordingly.
        int startOffset;
=======
    void operator()(const SkRecords::SaveLayer& sl) {

        // For a saveLayer command, check if it can be replaced by a drawBitmap
        // call and, if so, draw it and then update the current op index accordingly.
        unsigned startOffset;
>>>>>>> miniblink49
        if (fOps.count()) {
            startOffset = fOps[fIndex];
        } else {
            startOffset = fIndex;
        }

        fOpIndexStack.push(startOffset);

        GrCachedLayer* layer = fLayerCache->findLayer(fTopLevelPicture->uniqueID(),
<<<<<<< HEAD
            fInitialMatrix,
            fOpIndexStack.begin(),
            fOpIndexStack.count());
=======
                                                      fInitialMatrix,
                                                      fOpIndexStack.begin(),
                                                      fOpIndexStack.count());
>>>>>>> miniblink49

        if (layer) {
            fNumReplaced++;

            draw_replacement_bitmap(layer, fCanvas);

            if (fPicture->bbh()) {
                while (fOps[fIndex] < layer->stop()) {
                    ++fIndex;
                }
                SkASSERT(fOps[fIndex] == layer->stop());
            } else {
                fIndex = layer->stop();
            }
            fOpIndexStack.pop();
            return;
        }

        // This is a fail for layer hoisting
        this->INHERITED::operator()(sl);

        fOpIndexStack.pop();
    }

private:
<<<<<<< HEAD
    SkCanvas* fCanvas;
    GrLayerCache* fLayerCache;
    const SkPicture* fTopLevelPicture;
    const SkBigPicture* fPicture;
    const SkMatrix fInitialMatrix;
    SkPicture::AbortCallback* fCallback;

    SkTDArray<int> fOps;
    int fIndex;
    int fNumReplaced;

    // The op code indices of all the enclosing drawPicture and saveLayer calls
    SkTDArray<int> fOpIndexStack;
=======
    SkCanvas*                 fCanvas;
    GrLayerCache*             fLayerCache;
    const SkPicture*          fTopLevelPicture;
    const SkBigPicture*       fPicture;
    const SkMatrix            fInitialMatrix;
    SkPicture::AbortCallback* fCallback;

    SkTDArray<unsigned>       fOps;
    int                       fIndex;
    int                       fNumReplaced;

    // The op code indices of all the enclosing drawPicture and saveLayer calls
    SkTDArray<unsigned>       fOpIndexStack;
>>>>>>> miniblink49

    typedef Draw INHERITED;
};

int GrRecordReplaceDraw(const SkPicture* picture,
<<<<<<< HEAD
    SkCanvas* canvas,
    GrLayerCache* layerCache,
    const SkMatrix& initialMatrix,
    SkPicture::AbortCallback* callback)
{
=======
                        SkCanvas* canvas,
                        GrLayerCache* layerCache,
                        const SkMatrix& initialMatrix,
                        SkPicture::AbortCallback* callback) {
>>>>>>> miniblink49
    SkAutoCanvasRestore saveRestore(canvas, true /*save now, restore at exit*/);

    if (const SkBigPicture* bp = picture->asSkBigPicture()) {
        // TODO: drawablePicts?
<<<<<<< HEAD
        ReplaceDraw draw(canvas, layerCache, nullptr, 0,
            bp, bp,
            initialMatrix, callback, nullptr, 0);
=======
        ReplaceDraw draw(canvas, layerCache, NULL, 0,
                         bp, bp,
                         initialMatrix, callback, NULL, 0);
>>>>>>> miniblink49
        return draw.draw();
    } else {
        // TODO: can we assume / assert this doesn't happen?
        picture->playback(canvas, callback);
        return 0;
    }
}
