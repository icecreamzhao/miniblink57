/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

// Need to include something before #if SK_SUPPORT_GPU so that the Android
// framework build, which gets its defines from SkTypes rather than a makefile,
// has the definition before checking it.
<<<<<<< HEAD
#include "SkMultiPictureDraw.h"
#include "SkCanvas.h"
#include "SkCanvasPriv.h"
=======
#include "SkCanvas.h"
#include "SkCanvasPriv.h"
#include "SkMultiPictureDraw.h"
>>>>>>> miniblink49
#include "SkPicture.h"
#include "SkTaskGroup.h"

#if SK_SUPPORT_GPU
#include "GrContext.h"
<<<<<<< HEAD
#include "GrDrawContext.h"
=======
>>>>>>> miniblink49
#include "GrLayerHoister.h"
#include "GrRecordReplaceDraw.h"
#include "GrRenderTarget.h"
#endif

<<<<<<< HEAD
void SkMultiPictureDraw::DrawData::draw()
{
=======
void SkMultiPictureDraw::DrawData::draw() {
>>>>>>> miniblink49
    fCanvas->drawPicture(fPicture, &fMatrix, fPaint);
}

void SkMultiPictureDraw::DrawData::init(SkCanvas* canvas, const SkPicture* picture,
<<<<<<< HEAD
    const SkMatrix* matrix, const SkPaint* paint)
{
=======
                                        const SkMatrix* matrix, const SkPaint* paint) {
>>>>>>> miniblink49
    fPicture = SkRef(picture);
    fCanvas = SkRef(canvas);
    if (matrix) {
        fMatrix = *matrix;
    } else {
        fMatrix.setIdentity();
    }
    if (paint) {
<<<<<<< HEAD
        fPaint = new SkPaint(*paint);
    } else {
        fPaint = nullptr;
    }
}

void SkMultiPictureDraw::DrawData::Reset(SkTDArray<DrawData>& data)
{
    for (int i = 0; i < data.count(); ++i) {
        data[i].fPicture->unref();
        data[i].fCanvas->unref();
        delete data[i].fPaint;
=======
        fPaint = SkNEW_ARGS(SkPaint, (*paint));
    } else {
        fPaint = NULL;
    }
}

void SkMultiPictureDraw::DrawData::Reset(SkTDArray<DrawData>& data) {
    for (int i = 0; i < data.count(); ++i) {
        data[i].fPicture->unref();
        data[i].fCanvas->unref();
        SkDELETE(data[i].fPaint);
>>>>>>> miniblink49
    }
    data.rewind();
}

//////////////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
SkMultiPictureDraw::SkMultiPictureDraw(int reserve)
{
=======
SkMultiPictureDraw::SkMultiPictureDraw(int reserve) {
>>>>>>> miniblink49
    if (reserve > 0) {
        fGPUDrawData.setReserve(reserve);
        fThreadSafeDrawData.setReserve(reserve);
    }
}

<<<<<<< HEAD
void SkMultiPictureDraw::reset()
{
=======
void SkMultiPictureDraw::reset() {
>>>>>>> miniblink49
    DrawData::Reset(fGPUDrawData);
    DrawData::Reset(fThreadSafeDrawData);
}

void SkMultiPictureDraw::add(SkCanvas* canvas,
<<<<<<< HEAD
    const SkPicture* picture,
    const SkMatrix* matrix,
    const SkPaint* paint)
{
    if (nullptr == canvas || nullptr == picture) {
        SkDEBUGFAIL("parameters to SkMultiPictureDraw::add should be non-nullptr");
=======
                             const SkPicture* picture,
                             const SkMatrix* matrix,
                             const SkPaint* paint) {
    if (NULL == canvas || NULL == picture) {
        SkDEBUGFAIL("parameters to SkMultiPictureDraw::add should be non-NULL");
>>>>>>> miniblink49
        return;
    }

    SkTDArray<DrawData>& array = canvas->getGrContext() ? fGPUDrawData : fThreadSafeDrawData;
    array.append()->init(canvas, picture, matrix, paint);
}

class AutoMPDReset : SkNoncopyable {
    SkMultiPictureDraw* fMPD;
<<<<<<< HEAD

public:
    AutoMPDReset(SkMultiPictureDraw* mpd)
        : fMPD(mpd)
    {
    }
=======
public:
    AutoMPDReset(SkMultiPictureDraw* mpd) : fMPD(mpd) {}
>>>>>>> miniblink49
    ~AutoMPDReset() { fMPD->reset(); }
};

//#define FORCE_SINGLE_THREAD_DRAWING_FOR_TESTING

<<<<<<< HEAD
void SkMultiPictureDraw::draw(bool flush)
{
=======
void SkMultiPictureDraw::draw(bool flush) {
>>>>>>> miniblink49
    AutoMPDReset mpdreset(this);

#ifdef FORCE_SINGLE_THREAD_DRAWING_FOR_TESTING
    for (int i = 0; i < fThreadSafeDrawData.count(); ++i) {
        fThreadSafeDrawData[i].draw();
    }
#else
<<<<<<< HEAD
    SkTaskGroup().batch(fThreadSafeDrawData.count(), [&](int i) {
=======
    sk_parallel_for(fThreadSafeDrawData.count(), [&](int i) {
>>>>>>> miniblink49
        fThreadSafeDrawData[i].draw();
    });
#endif

    // N.B. we could get going on any GPU work from this main thread while the CPU work runs.
    // But in practice, we've either got GPU work or CPU work, not both.

    const int count = fGPUDrawData.count();
    if (0 == count) {
        return;
    }

#if !defined(SK_IGNORE_GPU_LAYER_HOISTING) && SK_SUPPORT_GPU
    GrContext* context = fGPUDrawData[0].fCanvas->getGrContext();
    SkASSERT(context);

    // Start by collecting all the layers that are going to be atlased and render
    // them (if necessary). Hoisting the free floating layers is deferred until
    // drawing the canvas that requires them.
    SkTDArray<GrHoistedLayer> atlasedNeedRendering, atlasedRecycled;

<<<<<<< HEAD
    GrLayerHoister::Begin(context);

=======
>>>>>>> miniblink49
    for (int i = 0; i < count; ++i) {
        const DrawData& data = fGPUDrawData[i];
        // we only expect 1 context for all the canvases
        SkASSERT(data.fCanvas->getGrContext() == context);

<<<<<<< HEAD
        if (!data.fPaint && (kRGBA_8888_SkColorType == data.fCanvas->imageInfo().colorType() || kBGRA_8888_SkColorType == data.fCanvas->imageInfo().colorType())) {
=======
        if (!data.fPaint) {
>>>>>>> miniblink49
            SkRect clipBounds;
            if (!data.fCanvas->getClipBounds(&clipBounds)) {
                continue;
            }

            SkMatrix initialMatrix = data.fCanvas->getTotalMatrix();
            initialMatrix.preConcat(data.fMatrix);

<<<<<<< HEAD
            GrDrawContext* dc = data.fCanvas->internal_private_accessTopLayerDrawContext();
            SkASSERT(dc);
=======
            GrRenderTarget* rt = data.fCanvas->internal_private_accessTopLayerRenderTarget();
            SkASSERT(rt);
>>>>>>> miniblink49

            // TODO: sorting the cacheable layers from smallest to largest
            // would improve the packing and reduce the number of swaps
            // TODO: another optimization would be to make a first pass to
            // lock any required layer that is already in the atlas
            GrLayerHoister::FindLayersToAtlas(context, data.fPicture, initialMatrix,
<<<<<<< HEAD
                clipBounds,
                &atlasedNeedRendering, &atlasedRecycled,
                dc->numColorSamples());
=======
                                              clipBounds,
                                              &atlasedNeedRendering, &atlasedRecycled,
                                              rt->numColorSamples());
>>>>>>> miniblink49
        }
    }

    GrLayerHoister::DrawLayersToAtlas(context, atlasedNeedRendering);

    SkTDArray<GrHoistedLayer> needRendering, recycled;
#endif

    for (int i = 0; i < count; ++i) {
        const DrawData& data = fGPUDrawData[i];
        SkCanvas* canvas = data.fCanvas;
        const SkPicture* picture = data.fPicture;

#if !defined(SK_IGNORE_GPU_LAYER_HOISTING) && SK_SUPPORT_GPU
        if (!data.fPaint) {

            SkRect clipBounds;
            if (!canvas->getClipBounds(&clipBounds)) {
                continue;
            }

            SkAutoCanvasMatrixPaint acmp(canvas, &data.fMatrix, data.fPaint, picture->cullRect());

            const SkMatrix initialMatrix = canvas->getTotalMatrix();

<<<<<<< HEAD
            GrDrawContext* dc = data.fCanvas->internal_private_accessTopLayerDrawContext();
            SkASSERT(dc);
=======
            GrRenderTarget* rt = data.fCanvas->internal_private_accessTopLayerRenderTarget();
            SkASSERT(rt);
>>>>>>> miniblink49

            // Find the layers required by this canvas. It will return atlased
            // layers in the 'recycled' list since they have already been drawn.
            GrLayerHoister::FindLayersToHoist(context, picture, initialMatrix,
<<<<<<< HEAD
                clipBounds, &needRendering, &recycled,
                dc->numColorSamples());
=======
                                              clipBounds, &needRendering, &recycled,
                                              rt->numColorSamples());
>>>>>>> miniblink49

            GrLayerHoister::DrawLayers(context, needRendering);

            // Render the entire picture using new layers
            GrRecordReplaceDraw(picture, canvas, context->getLayerCache(),
<<<<<<< HEAD
                initialMatrix, nullptr);
=======
                                initialMatrix, NULL);
>>>>>>> miniblink49

            GrLayerHoister::UnlockLayers(context, needRendering);
            GrLayerHoister::UnlockLayers(context, recycled);

            needRendering.rewind();
            recycled.rewind();
        } else
#endif
        {
            canvas->drawPicture(picture, &data.fMatrix, data.fPaint);
        }
        if (flush) {
            canvas->flush();
        }
    }

#if !defined(SK_IGNORE_GPU_LAYER_HOISTING) && SK_SUPPORT_GPU
    GrLayerHoister::UnlockLayers(context, atlasedNeedRendering);
    GrLayerHoister::UnlockLayers(context, atlasedRecycled);
<<<<<<< HEAD
    GrLayerHoister::End(context);
#endif
}
=======
#if !GR_CACHE_HOISTED_LAYERS
    GrLayerHoister::PurgeCache(context);
#endif
#endif
}

>>>>>>> miniblink49
