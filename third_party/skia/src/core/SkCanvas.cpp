/*
 * Copyright 2008 The Android Open Source Project
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkCanvas.h"
<<<<<<< HEAD
#include "SkBitmapDevice.h"
#include "SkCanvasPriv.h"
#include "SkClipStack.h"
#include "SkColorFilter.h"
#include "SkDraw.h"
#include "SkDrawFilter.h"
#include "SkDrawLooper.h"
#include "SkDrawable.h"
#include "SkErrorInternals.h"
#include "SkImage.h"
#include "SkImageFilter.h"
#include "SkImageFilterCache.h"
#include "SkImage_Base.h"
#include "SkMatrixUtils.h"
#include "SkMetaData.h"
#include "SkNinePatchIter.h"
#include "SkPaintPriv.h"
#include "SkPatchUtils.h"
#include "SkPicture.h"
#include "SkRRect.h"
#include "SkRasterClip.h"
#include "SkReadPixelsRec.h"
#include "SkSmallAllocator.h"
#include "SkSpecialImage.h"
#include "SkSurface_Base.h"
#include "SkTLazy.h"
#include "SkTextBlob.h"
#include "SkTextFormatParams.h"
#include "SkTraceEvent.h"

#include <new>

#if SK_SUPPORT_GPU
#include "GrContext.h"
#include "GrRenderTarget.h"
#include "SkGr.h"
#endif

#define RETURN_ON_NULL(ptr)   \
    do {                      \
        if (nullptr == (ptr)) \
            return;           \
    } while (0)

//#define SK_SUPPORT_PRECHECK_CLIPRECT

/*
 *  Return true if the drawing this rect would hit every pixels in the canvas.
 *
 *  Returns false if
 *  - rect does not contain the canvas' bounds
 *  - paint is not fill
 *  - paint would blur or otherwise change the coverage of the rect
 */
bool SkCanvas::wouldOverwriteEntireSurface(const SkRect* rect, const SkPaint* paint,
    ShaderOverrideOpacity overrideOpacity) const
{
    static_assert((int)SkPaintPriv::kNone_ShaderOverrideOpacity == (int)kNone_ShaderOverrideOpacity,
        "need_matching_enums0");
    static_assert((int)SkPaintPriv::kOpaque_ShaderOverrideOpacity == (int)kOpaque_ShaderOverrideOpacity,
        "need_matching_enums1");
    static_assert((int)SkPaintPriv::kNotOpaque_ShaderOverrideOpacity == (int)kNotOpaque_ShaderOverrideOpacity,
        "need_matching_enums2");

    const SkISize size = this->getBaseLayerSize();
    const SkRect bounds = SkRect::MakeIWH(size.width(), size.height());
    if (!this->getClipStack()->quickContains(bounds)) {
        return false;
    }

    if (rect) {
        if (!this->getTotalMatrix().rectStaysRect()) {
            return false; // conservative
        }

        SkRect devRect;
        this->getTotalMatrix().mapRect(&devRect, *rect);
        if (!devRect.contains(bounds)) {
            return false;
        }
    }

    if (paint) {
        SkPaint::Style paintStyle = paint->getStyle();
        if (!(paintStyle == SkPaint::kFill_Style || paintStyle == SkPaint::kStrokeAndFill_Style)) {
            return false;
        }
        if (paint->getMaskFilter() || paint->getLooper()
            || paint->getPathEffect() || paint->getImageFilter()) {
            return false; // conservative
        }
    }
    return SkPaintPriv::Overwrites(paint, (SkPaintPriv::ShaderOverrideOpacity)overrideOpacity);
}

///////////////////////////////////////////////////////////////////////////////////////////////////

static bool gIgnoreSaveLayerBounds;
void SkCanvas::Internal_Private_SetIgnoreSaveLayerBounds(bool ignore)
{
    gIgnoreSaveLayerBounds = ignore;
}
bool SkCanvas::Internal_Private_GetIgnoreSaveLayerBounds()
{
=======
#include "SkCanvasPriv.h"
#include "SkBitmapDevice.h"
#include "SkColorFilter.h"
#include "SkDraw.h"
#include "SkDrawable.h"
#include "SkDrawFilter.h"
#include "SkDrawLooper.h"
#include "SkErrorInternals.h"
#include "SkImage.h"
#include "SkMetaData.h"
#include "SkNinePatchIter.h"
#include "SkPathOps.h"
#include "SkPatchUtils.h"
#include "SkPicture.h"
#include "SkRasterClip.h"
#include "SkReadPixelsRec.h"
#include "SkRRect.h"
#include "SkSmallAllocator.h"
#include "SkSurface_Base.h"
#include "SkTemplates.h"
#include "SkTextBlob.h"
#include "SkTextFormatParams.h"
#include "SkTLazy.h"
#include "SkTraceEvent.h"
#include "SkUtils.h"

#if SK_SUPPORT_GPU
#include "GrRenderTarget.h"
#endif

static bool gIgnoreSaveLayerBounds;
void SkCanvas::Internal_Private_SetIgnoreSaveLayerBounds(bool ignore) {
    gIgnoreSaveLayerBounds = ignore;
}
bool SkCanvas::Internal_Private_GetIgnoreSaveLayerBounds() {
>>>>>>> miniblink49
    return gIgnoreSaveLayerBounds;
}

static bool gTreatSpriteAsBitmap;
<<<<<<< HEAD
void SkCanvas::Internal_Private_SetTreatSpriteAsBitmap(bool spriteAsBitmap)
{
    gTreatSpriteAsBitmap = spriteAsBitmap;
}
bool SkCanvas::Internal_Private_GetTreatSpriteAsBitmap()
{
=======
void SkCanvas::Internal_Private_SetTreatSpriteAsBitmap(bool spriteAsBitmap) {
    gTreatSpriteAsBitmap = spriteAsBitmap;
}
bool SkCanvas::Internal_Private_GetTreatSpriteAsBitmap() {
>>>>>>> miniblink49
    return gTreatSpriteAsBitmap;
}

// experimental for faster tiled drawing...
//#define SK_ENABLE_CLIP_QUICKREJECT
<<<<<<< HEAD
//#define SK_TRACE_SAVERESTORE

#ifdef SK_TRACE_SAVERESTORE
static int gLayerCounter;
static void inc_layer()
{
    ++gLayerCounter;
    printf("----- inc layer %d\n", gLayerCounter);
}
static void dec_layer()
{
    --gLayerCounter;
    printf("----- dec layer %d\n", gLayerCounter);
}

static int gRecCounter;
static void inc_rec()
{
    ++gRecCounter;
    printf("----- inc rec %d\n", gRecCounter);
}
static void dec_rec()
{
    --gRecCounter;
    printf("----- dec rec %d\n", gRecCounter);
}

static int gCanvasCounter;
static void inc_canvas()
{
    ++gCanvasCounter;
    printf("----- inc canvas %d\n", gCanvasCounter);
}
static void dec_canvas()
{
    --gCanvasCounter;
    printf("----- dec canvas %d\n", gCanvasCounter);
}
#else
#define inc_layer()
#define dec_layer()
#define inc_rec()
#define dec_rec()
#define inc_canvas()
#define dec_canvas()
=======

//#define SK_TRACE_SAVERESTORE

#ifdef SK_TRACE_SAVERESTORE
    static int gLayerCounter;
    static void inc_layer() { ++gLayerCounter; printf("----- inc layer %d\n", gLayerCounter); }
    static void dec_layer() { --gLayerCounter; printf("----- dec layer %d\n", gLayerCounter); }

    static int gRecCounter;
    static void inc_rec() { ++gRecCounter; printf("----- inc rec %d\n", gRecCounter); }
    static void dec_rec() { --gRecCounter; printf("----- dec rec %d\n", gRecCounter); }

    static int gCanvasCounter;
    static void inc_canvas() { ++gCanvasCounter; printf("----- inc canvas %d\n", gCanvasCounter); }
    static void dec_canvas() { --gCanvasCounter; printf("----- dec canvas %d\n", gCanvasCounter); }
#else
    #define inc_layer()
    #define dec_layer()
    #define inc_rec()
    #define dec_rec()
    #define inc_canvas()
    #define dec_canvas()
>>>>>>> miniblink49
#endif

typedef SkTLazy<SkPaint> SkLazyPaint;

<<<<<<< HEAD
void SkCanvas::predrawNotify(bool willOverwritesEntireSurface)
{
    if (fSurfaceBase) {
        fSurfaceBase->aboutToDraw(willOverwritesEntireSurface
                ? SkSurface::kDiscard_ContentChangeMode
                : SkSurface::kRetain_ContentChangeMode);
    }
}

void SkCanvas::predrawNotify(const SkRect* rect, const SkPaint* paint,
    ShaderOverrideOpacity overrideOpacity)
{
    if (fSurfaceBase) {
        SkSurface::ContentChangeMode mode = SkSurface::kRetain_ContentChangeMode;
        // Since willOverwriteAllPixels() may not be complete free to call, we only do so if
        // there is an outstanding snapshot, since w/o that, there will be no copy-on-write
        // and therefore we don't care which mode we're in.
        //
        if (fSurfaceBase->outstandingImageSnapshot()) {
            if (this->wouldOverwriteEntireSurface(rect, paint, overrideOpacity)) {
                mode = SkSurface::kDiscard_ContentChangeMode;
            }
        }
        fSurfaceBase->aboutToDraw(mode);
=======
void SkCanvas::predrawNotify() {
    if (fSurfaceBase) {
        fSurfaceBase->aboutToDraw(SkSurface::kRetain_ContentChangeMode);
>>>>>>> miniblink49
    }
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
static uint32_t filter_paint_flags(const SkSurfaceProps& props, uint32_t flags)
{
=======
static uint32_t filter_paint_flags(const SkSurfaceProps& props, uint32_t flags) {
>>>>>>> miniblink49
    const uint32_t propFlags = props.flags();
    if (propFlags & SkSurfaceProps::kDisallowDither_Flag) {
        flags &= ~SkPaint::kDither_Flag;
    }
    if (propFlags & SkSurfaceProps::kDisallowAntiAlias_Flag) {
        flags &= ~SkPaint::kAntiAlias_Flag;
    }
    return flags;
}

///////////////////////////////////////////////////////////////////////////////

/*  This is the record we keep for each SkBaseDevice that the user installs.
    The clip/matrix/proc are fields that reflect the top of the save/restore
    stack. Whenever the canvas changes, it marks a dirty flag, and then before
    these are used (assuming we're not on a layer) we rebuild these cache
    values: they reflect the top of the save stack, but translated and clipped
    by the device's XY offset and bitmap-bounds.
*/
struct DeviceCM {
<<<<<<< HEAD
    DeviceCM* fNext;
    SkBaseDevice* fDevice;
    SkRasterClip fClip;
    SkPaint* fPaint; // may be null (in the future)
    const SkMatrix* fMatrix;
    SkMatrix fMatrixStorage;
    SkMatrix fStashedMatrix; // original CTM; used by imagefilter in saveLayer
    const bool fDeviceIsBitmapDevice;

    DeviceCM(SkBaseDevice* device, const SkPaint* paint, SkCanvas* canvas,
        bool conservativeRasterClip, bool deviceIsBitmapDevice, const SkMatrix& stashed)
        : fNext(nullptr)
        , fClip(conservativeRasterClip)
        , fStashedMatrix(stashed)
        , fDeviceIsBitmapDevice(deviceIsBitmapDevice)
    {
        if (nullptr != device) {
=======
    DeviceCM*           fNext;
    SkBaseDevice*       fDevice;
    SkRasterClip        fClip;
    SkPaint*            fPaint; // may be null (in the future)
    const SkMatrix*     fMatrix;
    SkMatrix            fMatrixStorage;
    const bool          fDeviceIsBitmapDevice;

    DeviceCM(SkBaseDevice* device, const SkPaint* paint, SkCanvas* canvas,
             bool conservativeRasterClip, bool deviceIsBitmapDevice)
        : fNext(NULL)
        , fClip(conservativeRasterClip)
        , fDeviceIsBitmapDevice(deviceIsBitmapDevice)
    {
        if (NULL != device) {
>>>>>>> miniblink49
            device->ref();
            device->onAttachToCanvas(canvas);
        }
        fDevice = device;
<<<<<<< HEAD
        fPaint = paint ? new SkPaint(*paint) : nullptr;
    }

    ~DeviceCM()
    {
=======
        fPaint = paint ? SkNEW_ARGS(SkPaint, (*paint)) : NULL;
    }

    ~DeviceCM() {
>>>>>>> miniblink49
        if (fDevice) {
            fDevice->onDetachFromCanvas();
            fDevice->unref();
        }
<<<<<<< HEAD
        delete fPaint;
    }

    void reset(const SkIRect& bounds)
    {
=======
        SkDELETE(fPaint);
    }

    void reset(const SkIRect& bounds) {
>>>>>>> miniblink49
        SkASSERT(!fPaint);
        SkASSERT(!fNext);
        SkASSERT(fDevice);
        fClip.setRect(bounds);
    }

    void updateMC(const SkMatrix& totalMatrix, const SkRasterClip& totalClip,
<<<<<<< HEAD
        const SkClipStack& clipStack, SkRasterClip* updateClip)
    {
=======
                  const SkClipStack& clipStack, SkRasterClip* updateClip) {
>>>>>>> miniblink49
        int x = fDevice->getOrigin().x();
        int y = fDevice->getOrigin().y();
        int width = fDevice->width();
        int height = fDevice->height();

        if ((x | y) == 0) {
            fMatrix = &totalMatrix;
            fClip = totalClip;
        } else {
            fMatrixStorage = totalMatrix;
            fMatrixStorage.postTranslate(SkIntToScalar(-x),
<<<<<<< HEAD
                SkIntToScalar(-y));
=======
                                         SkIntToScalar(-y));
>>>>>>> miniblink49
            fMatrix = &fMatrixStorage;

            totalClip.translate(-x, -y, &fClip);
        }

        fClip.op(SkIRect::MakeWH(width, height), SkRegion::kIntersect_Op);

        // intersect clip, but don't translate it (yet)

        if (updateClip) {
            updateClip->op(SkIRect::MakeXYWH(x, y, width, height),
<<<<<<< HEAD
                SkRegion::kDifference_Op);
=======
                           SkRegion::kDifference_Op);
>>>>>>> miniblink49
        }

        fDevice->setMatrixClip(*fMatrix, fClip.forceGetBW(), clipStack);

#ifdef SK_DEBUG
        if (!fClip.isEmpty()) {
            SkIRect deviceR;
            deviceR.set(0, 0, width, height);
            SkASSERT(deviceR.contains(fClip.getBounds()));
        }
#endif
    }
};

/*  This is the record we keep for each save/restore level in the stack.
    Since a level optionally copies the matrix and/or stack, we have pointers
    for these fields. If the value is copied for this level, the copy is
    stored in the ...Storage field, and the pointer points to that. If the
    value is not copied for this level, we ignore ...Storage, and just point
    at the corresponding value in the previous level in the stack.
*/
class SkCanvas::MCRec {
public:
<<<<<<< HEAD
    SkDrawFilter* fFilter; // the current filter (or null)
    DeviceCM* fLayer;
=======
    SkDrawFilter*   fFilter;    // the current filter (or null)
    DeviceCM*       fLayer;
>>>>>>> miniblink49
    /*  If there are any layers in the stack, this points to the top-most
        one that is at or below this level in the stack (so we know what
        bitmap/device to draw into from this level. This value is NOT
        reference counted, since the real owner is either our fLayer field,
        or a previous one in a lower level.)
    */
<<<<<<< HEAD
    DeviceCM* fTopLayer;
    SkRasterClip fRasterClip;
    SkMatrix fMatrix;
    int fDeferredSaveCount;

    MCRec(bool conservativeRasterClip)
        : fRasterClip(conservativeRasterClip)
    {
        fFilter = nullptr;
        fLayer = nullptr;
        fTopLayer = nullptr;
=======
    DeviceCM*       fTopLayer;
    SkRasterClip    fRasterClip;
    SkMatrix        fMatrix;
    int             fDeferredSaveCount;

    MCRec(bool conservativeRasterClip) : fRasterClip(conservativeRasterClip) {
        fFilter     = NULL;
        fLayer      = NULL;
        fTopLayer   = NULL;
>>>>>>> miniblink49
        fMatrix.reset();
        fDeferredSaveCount = 0;

        // don't bother initializing fNext
        inc_rec();
    }
<<<<<<< HEAD
    MCRec(const MCRec& prev)
        : fRasterClip(prev.fRasterClip)
        , fMatrix(prev.fMatrix)
    {
        fFilter = SkSafeRef(prev.fFilter);
        fLayer = nullptr;
=======
    MCRec(const MCRec& prev) : fRasterClip(prev.fRasterClip), fMatrix(prev.fMatrix) {
        fFilter = SkSafeRef(prev.fFilter);
        fLayer = NULL;
>>>>>>> miniblink49
        fTopLayer = prev.fTopLayer;
        fDeferredSaveCount = 0;

        // don't bother initializing fNext
        inc_rec();
    }
<<<<<<< HEAD
    ~MCRec()
    {
        SkSafeUnref(fFilter);
        delete fLayer;
        dec_rec();
    }

    void reset(const SkIRect& bounds)
    {
=======
    ~MCRec() {
        SkSafeUnref(fFilter);
        SkDELETE(fLayer);
        dec_rec();
    }

    void reset(const SkIRect& bounds) {
>>>>>>> miniblink49
        SkASSERT(fLayer);
        SkASSERT(fDeferredSaveCount == 0);

        fMatrix.reset();
        fRasterClip.setRect(bounds);
        fLayer->reset(bounds);
    }
};

class SkDrawIter : public SkDraw {
public:
<<<<<<< HEAD
    SkDrawIter(SkCanvas* canvas, bool skipEmptyClips = true)
    {
=======
    SkDrawIter(SkCanvas* canvas, bool skipEmptyClips = true) {
>>>>>>> miniblink49
        canvas = canvas->canvasForDrawIter();
        fCanvas = canvas;
        canvas->updateDeviceCMCache();

        fClipStack = canvas->fClipStack;
        fCurrLayer = canvas->fMCRec->fTopLayer;
        fSkipEmptyClips = skipEmptyClips;
    }

<<<<<<< HEAD
    bool next()
    {
=======
    bool next() {
>>>>>>> miniblink49
        // skip over recs with empty clips
        if (fSkipEmptyClips) {
            while (fCurrLayer && fCurrLayer->fClip.isEmpty()) {
                fCurrLayer = fCurrLayer->fNext;
            }
        }

        const DeviceCM* rec = fCurrLayer;
        if (rec && rec->fDevice) {

            fMatrix = rec->fMatrix;
<<<<<<< HEAD
            fRC = &rec->fClip;
            fDevice = rec->fDevice;
            if (!fDevice->accessPixels(&fDst)) {
                fDst.reset(fDevice->imageInfo(), nullptr, 0);
            }
            fPaint = rec->fPaint;
            SkDEBUGCODE(this->validate();)

                fCurrLayer
                = rec->fNext;
            // fCurrLayer may be nullptr now
=======
            fClip   = &((SkRasterClip*)&rec->fClip)->forceGetBW();
            fRC     = &rec->fClip;
            fDevice = rec->fDevice;
            if (!fDevice->accessPixels(&fDst)) {
                fDst.reset(fDevice->imageInfo(), NULL, 0);
            }
            fPaint  = rec->fPaint;
            SkDEBUGCODE(this->validate();)

            fCurrLayer = rec->fNext;
            // fCurrLayer may be NULL now
>>>>>>> miniblink49

            return true;
        }
        return false;
    }

    SkBaseDevice* getDevice() const { return fDevice; }
<<<<<<< HEAD
    const SkRasterClip& getClip() const { return *fRC; }
    int getX() const { return fDevice->getOrigin().x(); }
    int getY() const { return fDevice->getOrigin().y(); }
    const SkMatrix& getMatrix() const { return *fMatrix; }
    const SkPaint* getPaint() const { return fPaint; }

private:
    SkCanvas* fCanvas;
    const DeviceCM* fCurrLayer;
    const SkPaint* fPaint; // May be null.
    SkBool8 fSkipEmptyClips;
=======
    int getX() const { return fDevice->getOrigin().x(); }
    int getY() const { return fDevice->getOrigin().y(); }
    const SkMatrix& getMatrix() const { return *fMatrix; }
    const SkRegion& getClip() const { return *fClip; }
    const SkPaint* getPaint() const { return fPaint; }

private:
    SkCanvas*       fCanvas;
    const DeviceCM* fCurrLayer;
    const SkPaint*  fPaint;     // May be null.
    SkBool8         fSkipEmptyClips;
>>>>>>> miniblink49

    typedef SkDraw INHERITED;
};

/////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
static SkPaint* set_if_needed(SkLazyPaint* lazy, const SkPaint& orig)
{
=======
static SkPaint* set_if_needed(SkLazyPaint* lazy, const SkPaint& orig) {
>>>>>>> miniblink49
    return lazy->isValid() ? lazy->get() : lazy->set(orig);
}

/**
 *  If the paint has an imagefilter, but it can be simplified to just a colorfilter, return that
<<<<<<< HEAD
 *  colorfilter, else return nullptr.
 */
static sk_sp<SkColorFilter> image_to_color_filter(const SkPaint& paint)
{
    SkImageFilter* imgf = paint.getImageFilter();
    if (!imgf) {
        return nullptr;
    }

    SkColorFilter* imgCFPtr;
    if (!imgf->asAColorFilter(&imgCFPtr)) {
        return nullptr;
    }
    sk_sp<SkColorFilter> imgCF(imgCFPtr);

    SkColorFilter* paintCF = paint.getColorFilter();
    if (nullptr == paintCF) {
=======
 *  colorfilter, else return NULL.
 */
static SkColorFilter* image_to_color_filter(const SkPaint& paint) {
    SkImageFilter* imgf = paint.getImageFilter();
    if (!imgf) {
        return NULL;
    }

    SkColorFilter* imgCF;
    if (!imgf->asAColorFilter(&imgCF)) {
        return NULL;
    }

    SkColorFilter* paintCF = paint.getColorFilter();
    if (NULL == paintCF) {
>>>>>>> miniblink49
        // there is no existing paint colorfilter, so we can just return the imagefilter's
        return imgCF;
    }

    // The paint has both a colorfilter(paintCF) and an imagefilter-which-is-a-colorfilter(imgCF)
    // and we need to combine them into a single colorfilter.
<<<<<<< HEAD
    return SkColorFilter::MakeComposeFilter(std::move(imgCF), sk_ref_sp(paintCF));
}

/**
 * There are many bounds in skia. A circle's bounds is just its center extended by its radius.
 * However, if we stroke a circle, then the "bounds" of that is larger, since it will now draw
 * outside of its raw-bounds by 1/2 the stroke width.  SkPaint has lots of optional
 * effects/attributes that can modify the effective bounds of a given primitive -- maskfilters,
 * patheffects, stroking, etc.  This function takes a raw bounds and a paint, and returns the
 * conservative "effective" bounds based on the settings in the paint... with one exception. This
 * function does *not* look at the imagefilter, which can also modify the effective bounds. It is
 * deliberately ignored.
 */
static const SkRect& apply_paint_to_bounds_sans_imagefilter(const SkPaint& paint,
    const SkRect& rawBounds,
    SkRect* storage)
{
    SkPaint tmpUnfiltered(paint);
    tmpUnfiltered.setImageFilter(nullptr);
    if (tmpUnfiltered.canComputeFastBounds()) {
        return tmpUnfiltered.computeFastBounds(rawBounds, storage);
    } else {
        return rawBounds;
    }
=======
    SkAutoTUnref<SkColorFilter> autoImgCF(imgCF);
    return SkColorFilter::CreateComposeFilter(imgCF, paintCF);
>>>>>>> miniblink49
}

class AutoDrawLooper {
public:
<<<<<<< HEAD
    // "rawBounds" is the original bounds of the primitive about to be drawn, unmodified by the
    // paint. It's used to determine the size of the offscreen layer for filters.
    // If null, the clip will be used instead.
    AutoDrawLooper(SkCanvas* canvas, const SkSurfaceProps& props, const SkPaint& paint,
        bool skipLayerForImageFilter = false,
        const SkRect* rawBounds = nullptr)
        : fOrigPaint(paint)
    {
        fCanvas = canvas;
#ifdef SK_SUPPORT_LEGACY_DRAWFILTER
        fFilter = canvas->getDrawFilter();
#else
        fFilter = nullptr;
#endif
=======
    AutoDrawLooper(SkCanvas* canvas, const SkSurfaceProps& props, const SkPaint& paint,
                   bool skipLayerForImageFilter = false,
                   const SkRect* bounds = NULL) : fOrigPaint(paint) {
        fCanvas = canvas;
        fFilter = canvas->getDrawFilter();
>>>>>>> miniblink49
        fPaint = &fOrigPaint;
        fSaveCount = canvas->getSaveCount();
        fTempLayerForImageFilter = false;
        fDone = false;

<<<<<<< HEAD
        auto simplifiedCF = image_to_color_filter(fOrigPaint);
        if (simplifiedCF) {
            SkPaint* paint = set_if_needed(&fLazyPaintInit, fOrigPaint);
            paint->setColorFilter(std::move(simplifiedCF));
            paint->setImageFilter(nullptr);
=======
        SkColorFilter* simplifiedCF = image_to_color_filter(fOrigPaint);
        if (simplifiedCF) {
            SkPaint* paint = set_if_needed(&fLazyPaintInit, fOrigPaint);
            paint->setColorFilter(simplifiedCF)->unref();
            paint->setImageFilter(NULL);
>>>>>>> miniblink49
            fPaint = paint;
        }

        if (!skipLayerForImageFilter && fPaint->getImageFilter()) {
            /**
             *  We implement ImageFilters for a given draw by creating a layer, then applying the
             *  imagefilter to the pixels of that layer (its backing surface/image), and then
             *  we call restore() to xfer that layer to the main canvas.
             *
             *  1. SaveLayer (with a paint containing the current imagefilter and xfermode)
             *  2. Generate the src pixels:
             *      Remove the imagefilter and the xfermode from the paint that we (AutoDrawLooper)
             *      return (fPaint). We then draw the primitive (using srcover) into a cleared
             *      buffer/surface.
             *  3. Restore the layer created in #1
             *      The imagefilter is passed the buffer/surface from the layer (now filled with the
             *      src pixels of the primitive). It returns a new "filtered" buffer, which we
             *      draw onto the previous layer using the xfermode from the original paint.
             */
            SkPaint tmp;
            tmp.setImageFilter(fPaint->getImageFilter());
<<<<<<< HEAD
            tmp.setXfermode(sk_ref_sp(fPaint->getXfermode()));
            SkRect storage;
            if (rawBounds) {
                // Make rawBounds include all paint outsets except for those due to image filters.
                rawBounds = &apply_paint_to_bounds_sans_imagefilter(*fPaint, *rawBounds, &storage);
            }
            (void)canvas->internalSaveLayer(SkCanvas::SaveLayerRec(rawBounds, &tmp),
                SkCanvas::kFullLayer_SaveLayerStrategy);
=======
            tmp.setXfermode(fPaint->getXfermode());
            (void)canvas->internalSaveLayer(bounds, &tmp, SkCanvas::kARGB_ClipLayer_SaveFlag,
                                            SkCanvas::kFullLayer_SaveLayerStrategy);
>>>>>>> miniblink49
            fTempLayerForImageFilter = true;
            // we remove the imagefilter/xfermode inside doNext()
        }

        if (SkDrawLooper* looper = paint.getLooper()) {
            void* buffer = fLooperContextAllocator.reserveT<SkDrawLooper::Context>(
<<<<<<< HEAD
                looper->contextSize());
            fLooperContext = looper->createContext(canvas, buffer);
            fIsSimple = false;
        } else {
            fLooperContext = nullptr;
=======
                    looper->contextSize());
            fLooperContext = looper->createContext(canvas, buffer);
            fIsSimple = false;
        } else {
            fLooperContext = NULL;
>>>>>>> miniblink49
            // can we be marked as simple?
            fIsSimple = !fFilter && !fTempLayerForImageFilter;
        }

        uint32_t oldFlags = paint.getFlags();
        fNewPaintFlags = filter_paint_flags(props, oldFlags);
        if (fIsSimple && (fNewPaintFlags != oldFlags)) {
            SkPaint* paint = set_if_needed(&fLazyPaintInit, fOrigPaint);
            paint->setFlags(fNewPaintFlags);
            fPaint = paint;
            // if we're not simple, doNext() will take care of calling setFlags()
        }
    }

<<<<<<< HEAD
    ~AutoDrawLooper()
    {
=======
    ~AutoDrawLooper() {
>>>>>>> miniblink49
        if (fTempLayerForImageFilter) {
            fCanvas->internalRestore();
        }
        SkASSERT(fCanvas->getSaveCount() == fSaveCount);
    }

<<<<<<< HEAD
    const SkPaint& paint() const
    {
=======
    const SkPaint& paint() const {
>>>>>>> miniblink49
        SkASSERT(fPaint);
        return *fPaint;
    }

<<<<<<< HEAD
    bool next(SkDrawFilter::Type drawType)
    {
=======
    bool next(SkDrawFilter::Type drawType) {
>>>>>>> miniblink49
        if (fDone) {
            return false;
        } else if (fIsSimple) {
            fDone = true;
            return !fPaint->nothingToDraw();
        } else {
            return this->doNext(drawType);
        }
    }

private:
<<<<<<< HEAD
    SkLazyPaint fLazyPaintInit; // base paint storage in case we need to modify it
    SkLazyPaint fLazyPaintPerLooper; // per-draw-looper storage, so the looper can modify it
    SkCanvas* fCanvas;
    const SkPaint& fOrigPaint;
    SkDrawFilter* fFilter;
    const SkPaint* fPaint;
    int fSaveCount;
    uint32_t fNewPaintFlags;
    bool fTempLayerForImageFilter;
    bool fDone;
    bool fIsSimple;
=======
    SkLazyPaint     fLazyPaintInit; // base paint storage in case we need to modify it
    SkLazyPaint     fLazyPaintPerLooper;  // per-draw-looper storage, so the looper can modify it
    SkCanvas*       fCanvas;
    const SkPaint&  fOrigPaint;
    SkDrawFilter*   fFilter;
    const SkPaint*  fPaint;
    int             fSaveCount;
    uint32_t        fNewPaintFlags;
    bool            fTempLayerForImageFilter;
    bool            fDone;
    bool            fIsSimple;
>>>>>>> miniblink49
    SkDrawLooper::Context* fLooperContext;
    SkSmallAllocator<1, 32> fLooperContextAllocator;

    bool doNext(SkDrawFilter::Type drawType);
};

<<<<<<< HEAD
bool AutoDrawLooper::doNext(SkDrawFilter::Type drawType)
{
    fPaint = nullptr;
    SkASSERT(!fIsSimple);
    SkASSERT(fLooperContext || fFilter || fTempLayerForImageFilter);

    SkPaint* paint = fLazyPaintPerLooper.set(fLazyPaintInit.isValid() ? *fLazyPaintInit.get() : fOrigPaint);
    paint->setFlags(fNewPaintFlags);

    if (fTempLayerForImageFilter) {
        paint->setImageFilter(nullptr);
        paint->setXfermode(nullptr);
=======
bool AutoDrawLooper::doNext(SkDrawFilter::Type drawType) {
    fPaint = NULL;
    SkASSERT(!fIsSimple);
    SkASSERT(fLooperContext || fFilter || fTempLayerForImageFilter);

    SkPaint* paint = fLazyPaintPerLooper.set(fLazyPaintInit.isValid() ?
                                             *fLazyPaintInit.get() : fOrigPaint);
    paint->setFlags(fNewPaintFlags);

    if (fTempLayerForImageFilter) {
        paint->setImageFilter(NULL);
        paint->setXfermode(NULL);
>>>>>>> miniblink49
    }

    if (fLooperContext && !fLooperContext->next(fCanvas, paint)) {
        fDone = true;
        return false;
    }
    if (fFilter) {
        if (!fFilter->filter(paint, drawType)) {
            fDone = true;
            return false;
        }
<<<<<<< HEAD
        if (nullptr == fLooperContext) {
=======
        if (NULL == fLooperContext) {
>>>>>>> miniblink49
            // no looper means we only draw once
            fDone = true;
        }
    }
    fPaint = paint;

    // if we only came in here for the imagefilter, mark us as done
    if (!fLooperContext && !fFilter) {
        fDone = true;
    }

    // call this after any possible paint modifiers
    if (fPaint->nothingToDraw()) {
<<<<<<< HEAD
        fPaint = nullptr;
=======
        fPaint = NULL;
>>>>>>> miniblink49
        return false;
    }
    return true;
}

////////// macros to place around the internal draw calls //////////////////

<<<<<<< HEAD
#define LOOPER_BEGIN_DRAWBITMAP(paint, skipLayerForFilter, bounds)          \
    this->predrawNotify();                                                  \
    AutoDrawLooper looper(this, fProps, paint, skipLayerForFilter, bounds); \
    while (looper.next(SkDrawFilter::kBitmap_Type)) {                       \
        SkDrawIter iter(this);

#define LOOPER_BEGIN_DRAWDEVICE(paint, type)          \
    this->predrawNotify();                            \
    AutoDrawLooper looper(this, fProps, paint, true); \
    while (looper.next(type)) {                       \
        SkDrawIter iter(this);

#define LOOPER_BEGIN(paint, type, bounds)                      \
    this->predrawNotify();                                     \
    AutoDrawLooper looper(this, fProps, paint, false, bounds); \
    while (looper.next(type)) {                                \
        SkDrawIter iter(this);

#define LOOPER_BEGIN_CHECK_COMPLETE_OVERWRITE(paint, type, bounds, auxOpaque) \
    this->predrawNotify(bounds, &paint, auxOpaque);                           \
    AutoDrawLooper looper(this, fProps, paint, false, bounds);                \
    while (looper.next(type)) {                                               \
        SkDrawIter iter(this);

#define LOOPER_END }

////////////////////////////////////////////////////////////////////////////

void SkCanvas::resetForNextPicture(const SkIRect& bounds)
{
=======
#define LOOPER_BEGIN_DRAWDEVICE(paint, type)                        \
    this->predrawNotify();                                          \
    AutoDrawLooper  looper(this, fProps, paint, true);              \
    while (looper.next(type)) {                                     \
        SkDrawIter          iter(this);

#define LOOPER_BEGIN(paint, type, bounds)                           \
    this->predrawNotify();                                          \
    AutoDrawLooper  looper(this, fProps, paint, false, bounds);     \
    while (looper.next(type)) {                                     \
        SkDrawIter          iter(this);

#define LOOPER_END    }

////////////////////////////////////////////////////////////////////////////

void SkCanvas::resetForNextPicture(const SkIRect& bounds) {
>>>>>>> miniblink49
    this->restoreToCount(1);
    fCachedLocalClipBounds.setEmpty();
    fCachedLocalClipBoundsDirty = true;
    fClipStack->reset();
    fMCRec->reset(bounds);

    // We're peering through a lot of structs here.  Only at this scope do we
    // know that the device is an SkBitmapDevice (really an SkNoPixelsBitmapDevice).
    static_cast<SkBitmapDevice*>(fMCRec->fLayer->fDevice)->setNewSize(bounds.size());
}

<<<<<<< HEAD
SkBaseDevice* SkCanvas::init(SkBaseDevice* device, InitFlags flags)
{
    if (device && device->forceConservativeRasterClip()) {
        flags = InitFlags(flags | kConservativeRasterClip_InitFlag);
    }
    // Since init() is only called once by our constructors, it is safe to perform this
    // const-cast.
    *const_cast<bool*>(&fConservativeRasterClip) = SkToBool(flags & kConservativeRasterClip_InitFlag);

=======
SkBaseDevice* SkCanvas::init(SkBaseDevice* device, InitFlags flags) {
    fConservativeRasterClip = SkToBool(flags & kConservativeRasterClip_InitFlag);
>>>>>>> miniblink49
    fCachedLocalClipBounds.setEmpty();
    fCachedLocalClipBoundsDirty = true;
    fAllowSoftClip = true;
    fAllowSimplifyClip = false;
    fDeviceCMDirty = true;
    fSaveCount = 1;
<<<<<<< HEAD
    fMetaData = nullptr;

    fClipStack.reset(new SkClipStack);
=======
    fMetaData = NULL;

    fClipStack.reset(SkNEW(SkClipStack));
>>>>>>> miniblink49

    fMCRec = (MCRec*)fMCStack.push_back();
    new (fMCRec) MCRec(fConservativeRasterClip);

    SkASSERT(sizeof(DeviceCM) <= sizeof(fDeviceCMStorage));
    fMCRec->fLayer = (DeviceCM*)fDeviceCMStorage;
<<<<<<< HEAD
    new (fDeviceCMStorage) DeviceCM(nullptr, nullptr, nullptr, fConservativeRasterClip, false,
        fMCRec->fMatrix);

    fMCRec->fTopLayer = fMCRec->fLayer;

    fSurfaceBase = nullptr;
=======
    new (fDeviceCMStorage) DeviceCM(NULL, NULL, NULL, fConservativeRasterClip, false);

    fMCRec->fTopLayer = fMCRec->fLayer;

    fSurfaceBase = NULL;
>>>>>>> miniblink49

    if (device) {
        // The root device and the canvas should always have the same pixel geometry
        SkASSERT(fProps.pixelGeometry() == device->surfaceProps().pixelGeometry());
<<<<<<< HEAD
=======
        if (device->forceConservativeRasterClip()) {
            fConservativeRasterClip = true;
        }
>>>>>>> miniblink49
        device->onAttachToCanvas(this);
        fMCRec->fLayer->fDevice = SkRef(device);
        fMCRec->fRasterClip.setRect(device->getGlobalBounds());
    }
    return device;
}

SkCanvas::SkCanvas()
    : fMCStack(sizeof(MCRec), fMCRecStorage, sizeof(fMCRecStorage))
    , fProps(SkSurfaceProps::kLegacyFontHost_InitType)
<<<<<<< HEAD
    , fConservativeRasterClip(false)
{
    inc_canvas();

    this->init(nullptr, kDefault_InitFlags);
}

static SkBitmap make_nopixels(int width, int height)
{
=======
{
    inc_canvas();

    this->init(NULL, kDefault_InitFlags);
}

static SkBitmap make_nopixels(int width, int height) {
>>>>>>> miniblink49
    SkBitmap bitmap;
    bitmap.setInfo(SkImageInfo::MakeUnknown(width, height));
    return bitmap;
}

class SkNoPixelsBitmapDevice : public SkBitmapDevice {
public:
    SkNoPixelsBitmapDevice(const SkIRect& bounds, const SkSurfaceProps& surfaceProps)
        : INHERITED(make_nopixels(bounds.width(), bounds.height()), surfaceProps)
    {
        this->setOrigin(bounds.x(), bounds.y());
    }

private:
<<<<<<< HEAD
=======

>>>>>>> miniblink49
    typedef SkBitmapDevice INHERITED;
};

SkCanvas::SkCanvas(int width, int height, const SkSurfaceProps* props)
    : fMCStack(sizeof(MCRec), fMCRecStorage, sizeof(fMCRecStorage))
    , fProps(SkSurfacePropsCopyOrDefault(props))
<<<<<<< HEAD
    , fConservativeRasterClip(false)
{
    inc_canvas();

    this->init(new SkNoPixelsBitmapDevice(SkIRect::MakeWH(width, height), fProps),
            kDefault_InitFlags)
        ->unref();
=======
{
    inc_canvas();

    this->init(SkNEW_ARGS(SkNoPixelsBitmapDevice,
                          (SkIRect::MakeWH(width, height), fProps)), kDefault_InitFlags)->unref();
>>>>>>> miniblink49
}

SkCanvas::SkCanvas(const SkIRect& bounds, InitFlags flags)
    : fMCStack(sizeof(MCRec), fMCRecStorage, sizeof(fMCRecStorage))
    , fProps(SkSurfaceProps::kLegacyFontHost_InitType)
<<<<<<< HEAD
    , fConservativeRasterClip(false)
{
    inc_canvas();

    this->init(new SkNoPixelsBitmapDevice(bounds, fProps), flags)->unref();
=======
{
    inc_canvas();

    this->init(SkNEW_ARGS(SkNoPixelsBitmapDevice, (bounds, fProps)), flags)->unref();
>>>>>>> miniblink49
}

SkCanvas::SkCanvas(SkBaseDevice* device)
    : fMCStack(sizeof(MCRec), fMCRecStorage, sizeof(fMCRecStorage))
    , fProps(device->surfaceProps())
<<<<<<< HEAD
    , fConservativeRasterClip(false)
=======
>>>>>>> miniblink49
{
    inc_canvas();

    this->init(device, kDefault_InitFlags);
}

SkCanvas::SkCanvas(SkBaseDevice* device, InitFlags flags)
    : fMCStack(sizeof(MCRec), fMCRecStorage, sizeof(fMCRecStorage))
    , fProps(device->surfaceProps())
<<<<<<< HEAD
    , fConservativeRasterClip(false)
=======
>>>>>>> miniblink49
{
    inc_canvas();

    this->init(device, flags);
}

SkCanvas::SkCanvas(const SkBitmap& bitmap, const SkSurfaceProps& props)
    : fMCStack(sizeof(MCRec), fMCRecStorage, sizeof(fMCRecStorage))
    , fProps(props)
<<<<<<< HEAD
    , fConservativeRasterClip(false)
{
    inc_canvas();

    SkAutoTUnref<SkBaseDevice> device(new SkBitmapDevice(bitmap, fProps));
=======
{
    inc_canvas();

    SkAutoTUnref<SkBaseDevice> device(SkNEW_ARGS(SkBitmapDevice, (bitmap, fProps)));
>>>>>>> miniblink49
    this->init(device, kDefault_InitFlags);
}

SkCanvas::SkCanvas(const SkBitmap& bitmap)
    : fMCStack(sizeof(MCRec), fMCRecStorage, sizeof(fMCRecStorage))
    , fProps(SkSurfaceProps::kLegacyFontHost_InitType)
<<<<<<< HEAD
    , fConservativeRasterClip(false)
{
    inc_canvas();

    SkAutoTUnref<SkBaseDevice> device(new SkBitmapDevice(bitmap, fProps));
    this->init(device, kDefault_InitFlags);
}

SkCanvas::~SkCanvas()
{
    // free up the contents of our deque
    this->restoreToCount(1); // restore everything but the last

    this->internalRestore(); // restore the last, since we're going away

    delete fMetaData;
=======
{
    inc_canvas();

    SkAutoTUnref<SkBaseDevice> device(SkNEW_ARGS(SkBitmapDevice, (bitmap, fProps)));
    this->init(device, kDefault_InitFlags);
}

SkCanvas::~SkCanvas() {
    // free up the contents of our deque
    this->restoreToCount(1);    // restore everything but the last

    this->internalRestore();    // restore the last, since we're going away

    SkDELETE(fMetaData);
>>>>>>> miniblink49

    dec_canvas();
}

<<<<<<< HEAD
#ifdef SK_SUPPORT_LEGACY_DRAWFILTER
SkDrawFilter* SkCanvas::getDrawFilter() const
{
    return fMCRec->fFilter;
}

SkDrawFilter* SkCanvas::setDrawFilter(SkDrawFilter* filter)
{
=======
SkDrawFilter* SkCanvas::getDrawFilter() const {
    return fMCRec->fFilter;
}

SkDrawFilter* SkCanvas::setDrawFilter(SkDrawFilter* filter) {
>>>>>>> miniblink49
    this->checkForDeferredSave();
    SkRefCnt_SafeAssign(fMCRec->fFilter, filter);
    return filter;
}
<<<<<<< HEAD
#endif

SkMetaData& SkCanvas::getMetaData()
{
    // metadata users are rare, so we lazily allocate it. If that changes we
    // can decide to just make it a field in the device (rather than a ptr)
    if (nullptr == fMetaData) {
=======

SkMetaData& SkCanvas::getMetaData() {
    // metadata users are rare, so we lazily allocate it. If that changes we
    // can decide to just make it a field in the device (rather than a ptr)
    if (NULL == fMetaData) {
>>>>>>> miniblink49
        fMetaData = new SkMetaData;
    }
    return *fMetaData;
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void SkCanvas::flush()
{
=======
void SkCanvas::flush() {
>>>>>>> miniblink49
    SkBaseDevice* device = this->getDevice();
    if (device) {
        device->flush();
    }
}

<<<<<<< HEAD
SkISize SkCanvas::getBaseLayerSize() const
{
=======
SkISize SkCanvas::getTopLayerSize() const {
    SkBaseDevice* d = this->getTopDevice();
    return d ? SkISize::Make(d->width(), d->height()) : SkISize::Make(0, 0);
}

SkIPoint SkCanvas::getTopLayerOrigin() const {
    SkBaseDevice* d = this->getTopDevice();
    return d ? d->getOrigin() : SkIPoint::Make(0, 0);
}

SkISize SkCanvas::getBaseLayerSize() const {
>>>>>>> miniblink49
    SkBaseDevice* d = this->getDevice();
    return d ? SkISize::Make(d->width(), d->height()) : SkISize::Make(0, 0);
}

<<<<<<< HEAD
SkIRect SkCanvas::getTopLayerBounds() const
{
    SkBaseDevice* d = this->getTopDevice();
    if (!d) {
        return SkIRect::MakeEmpty();
    }
    return SkIRect::MakeXYWH(d->getOrigin().x(), d->getOrigin().y(), d->width(), d->height());
}

SkBaseDevice* SkCanvas::getDevice() const
{
    // return root device
    MCRec* rec = (MCRec*)fMCStack.front();
=======
SkBaseDevice* SkCanvas::getDevice() const {
    // return root device
    MCRec* rec = (MCRec*) fMCStack.front();
>>>>>>> miniblink49
    SkASSERT(rec && rec->fLayer);
    return rec->fLayer->fDevice;
}

<<<<<<< HEAD
SkBaseDevice* SkCanvas::getTopDevice(bool updateMatrixClip) const
{
=======
SkBaseDevice* SkCanvas::getTopDevice(bool updateMatrixClip) const {
>>>>>>> miniblink49
    if (updateMatrixClip) {
        const_cast<SkCanvas*>(this)->updateDeviceCMCache();
    }
    return fMCRec->fTopLayer->fDevice;
}

<<<<<<< HEAD
bool SkCanvas::readPixels(SkBitmap* bitmap, int x, int y)
{
=======
bool SkCanvas::readPixels(SkBitmap* bitmap, int x, int y) {
>>>>>>> miniblink49
    if (kUnknown_SkColorType == bitmap->colorType() || bitmap->getTexture()) {
        return false;
    }

    bool weAllocated = false;
<<<<<<< HEAD
    if (nullptr == bitmap->pixelRef()) {
=======
    if (NULL == bitmap->pixelRef()) {
>>>>>>> miniblink49
        if (!bitmap->tryAllocPixels()) {
            return false;
        }
        weAllocated = true;
    }

    SkAutoPixmapUnlock unlocker;
    if (bitmap->requestLock(&unlocker)) {
        const SkPixmap& pm = unlocker.pixmap();
        if (this->readPixels(pm.info(), pm.writable_addr(), pm.rowBytes(), x, y)) {
            return true;
        }
    }

    if (weAllocated) {
<<<<<<< HEAD
        bitmap->setPixelRef(nullptr);
=======
        bitmap->setPixelRef(NULL);
>>>>>>> miniblink49
    }
    return false;
}

<<<<<<< HEAD
bool SkCanvas::readPixels(const SkIRect& srcRect, SkBitmap* bitmap)
{
=======
bool SkCanvas::readPixels(const SkIRect& srcRect, SkBitmap* bitmap) {
>>>>>>> miniblink49
    SkIRect r = srcRect;
    const SkISize size = this->getBaseLayerSize();
    if (!r.intersect(0, 0, size.width(), size.height())) {
        bitmap->reset();
        return false;
    }

    if (!bitmap->tryAllocN32Pixels(r.width(), r.height())) {
        // bitmap will already be reset.
        return false;
    }
    if (!this->readPixels(bitmap->info(), bitmap->getPixels(), bitmap->rowBytes(), r.x(), r.y())) {
        bitmap->reset();
        return false;
    }
    return true;
}

<<<<<<< HEAD
bool SkCanvas::readPixels(const SkImageInfo& dstInfo, void* dstP, size_t rowBytes, int x, int y)
{
=======
bool SkCanvas::readPixels(const SkImageInfo& dstInfo, void* dstP, size_t rowBytes, int x, int y) {
>>>>>>> miniblink49
    SkBaseDevice* device = this->getDevice();
    if (!device) {
        return false;
    }
    const SkISize size = this->getBaseLayerSize();

    SkReadPixelsRec rec(dstInfo, dstP, rowBytes, x, y);
    if (!rec.trim(size.width(), size.height())) {
        return false;
    }

    // The device can assert that the requested area is always contained in its bounds
    return device->readPixels(rec.fInfo, rec.fPixels, rec.fRowBytes, rec.fX, rec.fY);
}

<<<<<<< HEAD
bool SkCanvas::writePixels(const SkBitmap& bitmap, int x, int y)
{
=======
bool SkCanvas::writePixels(const SkBitmap& bitmap, int x, int y) {
>>>>>>> miniblink49
    if (bitmap.getTexture()) {
        return false;
    }

    SkAutoPixmapUnlock unlocker;
    if (bitmap.requestLock(&unlocker)) {
        const SkPixmap& pm = unlocker.pixmap();
        return this->writePixels(pm.info(), pm.addr(), pm.rowBytes(), x, y);
    }
    return false;
}

bool SkCanvas::writePixels(const SkImageInfo& origInfo, const void* pixels, size_t rowBytes,
<<<<<<< HEAD
    int x, int y)
{
    switch (origInfo.colorType()) {
    case kUnknown_SkColorType:
    case kIndex_8_SkColorType:
        return false;
    default:
        break;
    }
    if (nullptr == pixels || rowBytes < origInfo.minRowBytes()) {
=======
                           int x, int y) {
    switch (origInfo.colorType()) {
        case kUnknown_SkColorType:
        case kIndex_8_SkColorType:
            return false;
        default:
            break;
    }
    if (NULL == pixels || rowBytes < origInfo.minRowBytes()) {
>>>>>>> miniblink49
        return false;
    }

    const SkISize size = this->getBaseLayerSize();
    SkIRect target = SkIRect::MakeXYWH(x, y, origInfo.width(), origInfo.height());
    if (!target.intersect(0, 0, size.width(), size.height())) {
        return false;
    }

    SkBaseDevice* device = this->getDevice();
    if (!device) {
        return false;
    }

    // the intersect may have shrunk info's logical size
    const SkImageInfo info = origInfo.makeWH(target.width(), target.height());

    // if x or y are negative, then we have to adjust pixels
    if (x > 0) {
        x = 0;
    }
    if (y > 0) {
        y = 0;
    }
    // here x,y are either 0 or negative
    pixels = ((const char*)pixels - y * rowBytes - x * info.bytesPerPixel());

    // Tell our owning surface to bump its generation ID
<<<<<<< HEAD
    const bool completeOverwrite = info.dimensions() == size;
    this->predrawNotify(completeOverwrite);
=======
    this->predrawNotify();
>>>>>>> miniblink49

    // The device can assert that the requested area is always contained in its bounds
    return device->writePixels(info, pixels, rowBytes, target.x(), target.y());
}

<<<<<<< HEAD
SkCanvas* SkCanvas::canvasForDrawIter()
{
=======
SkCanvas* SkCanvas::canvasForDrawIter() {
>>>>>>> miniblink49
    return this;
}

//////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void SkCanvas::updateDeviceCMCache()
{
    if (fDeviceCMDirty) {
        const SkMatrix& totalMatrix = this->getTotalMatrix();
        const SkRasterClip& totalClip = fMCRec->fRasterClip;
        DeviceCM* layer = fMCRec->fTopLayer;

        if (nullptr == layer->fNext) { // only one layer
            layer->updateMC(totalMatrix, totalClip, *fClipStack, nullptr);
=======
void SkCanvas::updateDeviceCMCache() {
    if (fDeviceCMDirty) {
        const SkMatrix& totalMatrix = this->getTotalMatrix();
        const SkRasterClip& totalClip = fMCRec->fRasterClip;
        DeviceCM*       layer = fMCRec->fTopLayer;

        if (NULL == layer->fNext) {   // only one layer
            layer->updateMC(totalMatrix, totalClip, *fClipStack, NULL);
>>>>>>> miniblink49
        } else {
            SkRasterClip clip(totalClip);
            do {
                layer->updateMC(totalMatrix, clip, *fClipStack, &clip);
<<<<<<< HEAD
            } while ((layer = layer->fNext) != nullptr);
=======
            } while ((layer = layer->fNext) != NULL);
>>>>>>> miniblink49
        }
        fDeviceCMDirty = false;
    }
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void SkCanvas::checkForDeferredSave()
{
=======
void SkCanvas::checkForDeferredSave() {
>>>>>>> miniblink49
    if (fMCRec->fDeferredSaveCount > 0) {
        this->doSave();
    }
}

<<<<<<< HEAD
int SkCanvas::getSaveCount() const
{
=======
int SkCanvas::getSaveCount() const {
>>>>>>> miniblink49
#ifdef SK_DEBUG
    int count = 0;
    SkDeque::Iter iter(fMCStack, SkDeque::Iter::kFront_IterStart);
    for (;;) {
        const MCRec* rec = (const MCRec*)iter.next();
        if (!rec) {
            break;
        }
        count += 1 + rec->fDeferredSaveCount;
    }
    SkASSERT(count == fSaveCount);
#endif
    return fSaveCount;
}

<<<<<<< HEAD
int SkCanvas::save()
{
    fSaveCount += 1;
    fMCRec->fDeferredSaveCount += 1;
    return this->getSaveCount() - 1; // return our prev value
}

void SkCanvas::doSave()
{
=======
int SkCanvas::save() {
    fSaveCount += 1;
    fMCRec->fDeferredSaveCount += 1;
    return this->getSaveCount() - 1;  // return our prev value
}

void SkCanvas::doSave() {
>>>>>>> miniblink49
    this->willSave();

    SkASSERT(fMCRec->fDeferredSaveCount > 0);
    fMCRec->fDeferredSaveCount -= 1;
    this->internalSave();
}

<<<<<<< HEAD
void SkCanvas::restore()
{
=======
void SkCanvas::restore() {
>>>>>>> miniblink49
    if (fMCRec->fDeferredSaveCount > 0) {
        SkASSERT(fSaveCount > 1);
        fSaveCount -= 1;
        fMCRec->fDeferredSaveCount -= 1;
    } else {
        // check for underflow
        if (fMCStack.count() > 1) {
            this->willRestore();
            SkASSERT(fSaveCount > 1);
            fSaveCount -= 1;
            this->internalRestore();
            this->didRestore();
        }
    }
}

<<<<<<< HEAD
void SkCanvas::restoreToCount(int count)
{
=======
void SkCanvas::restoreToCount(int count) {
>>>>>>> miniblink49
    // sanity check
    if (count < 1) {
        count = 1;
    }

    int n = this->getSaveCount() - count;
    for (int i = 0; i < n; ++i) {
        this->restore();
    }
}

<<<<<<< HEAD
void SkCanvas::internalSave()
{
    MCRec* newTop = (MCRec*)fMCStack.push_back();
    new (newTop) MCRec(*fMCRec); // balanced in restore()
=======
void SkCanvas::internalSave() {
    MCRec* newTop = (MCRec*)fMCStack.push_back();
    new (newTop) MCRec(*fMCRec);    // balanced in restore()
>>>>>>> miniblink49
    fMCRec = newTop;

    fClipStack->save();
}

<<<<<<< HEAD
bool SkCanvas::BoundsAffectsClip(SaveLayerFlags saveLayerFlags)
{
#ifdef SK_SUPPORT_LEGACY_CLIPTOLAYERFLAG
    return !(saveLayerFlags & SkCanvas::kDontClipToLayer_PrivateSaveLayerFlag);
=======
static bool bounds_affects_clip(SkCanvas::SaveFlags flags) {
#ifdef SK_SUPPORT_LEGACY_CLIPTOLAYERFLAG
    return (flags & SkCanvas::kClipToLayer_SaveFlag) != 0;
>>>>>>> miniblink49
#else
    return true;
#endif
}

<<<<<<< HEAD
bool SkCanvas::clipRectBounds(const SkRect* bounds, SaveLayerFlags saveLayerFlags,
    SkIRect* intersection, const SkImageFilter* imageFilter)
{
=======
bool SkCanvas::clipRectBounds(const SkRect* bounds, SaveFlags flags,
                              SkIRect* intersection, const SkImageFilter* imageFilter) {
>>>>>>> miniblink49
    SkIRect clipBounds;
    if (!this->getClipDeviceBounds(&clipBounds)) {
        return false;
    }

<<<<<<< HEAD
    const SkMatrix& ctm = fMCRec->fMatrix; // this->getTotalMatrix()

    if (imageFilter) {
        clipBounds = imageFilter->filterBounds(clipBounds, ctm);
        if (bounds && !imageFilter->canComputeFastBounds()) {
            bounds = nullptr;
        }
=======
    const SkMatrix& ctm = fMCRec->fMatrix;  // this->getTotalMatrix()

    if (imageFilter) {
        imageFilter->filterBounds(clipBounds, ctm, &clipBounds);
>>>>>>> miniblink49
    }
    SkIRect ir;
    if (bounds) {
        SkRect r;

        ctm.mapRect(&r, *bounds);
        r.roundOut(&ir);
        // early exit if the layer's bounds are clipped out
        if (!ir.intersect(clipBounds)) {
<<<<<<< HEAD
            if (BoundsAffectsClip(saveLayerFlags)) {
=======
            if (bounds_affects_clip(flags)) {
>>>>>>> miniblink49
                fCachedLocalClipBoundsDirty = true;
                fMCRec->fRasterClip.setEmpty();
            }
            return false;
        }
<<<<<<< HEAD
    } else { // no user bounds, so just use the clip
=======
    } else {    // no user bounds, so just use the clip
>>>>>>> miniblink49
        ir = clipBounds;
    }
    SkASSERT(!ir.isEmpty());

<<<<<<< HEAD
    if (BoundsAffectsClip(saveLayerFlags)) {
=======
    if (bounds_affects_clip(flags)) {
>>>>>>> miniblink49
        // Simplify the current clips since they will be applied properly during restore()
        fCachedLocalClipBoundsDirty = true;
        fClipStack->clipDevRect(ir, SkRegion::kReplace_Op);
        fMCRec->fRasterClip.setRect(ir);
    }

    if (intersection) {
        *intersection = ir;
    }
    return true;
}

<<<<<<< HEAD
int SkCanvas::saveLayer(const SkRect* bounds, const SkPaint* paint)
{
    return this->saveLayer(SaveLayerRec(bounds, paint, 0));
}

int SkCanvas::saveLayerPreserveLCDTextRequests(const SkRect* bounds, const SkPaint* paint)
{
    return this->saveLayer(SaveLayerRec(bounds, paint, kPreserveLCDText_SaveLayerFlag));
}

int SkCanvas::saveLayer(const SaveLayerRec& origRec)
{
    SaveLayerRec rec(origRec);
    if (gIgnoreSaveLayerBounds) {
        rec.fBounds = nullptr;
    }
    SaveLayerStrategy strategy = this->getSaveLayerStrategy(rec);
    fSaveCount += 1;
    this->internalSaveLayer(rec, strategy);
    return this->getSaveCount() - 1;
}

static void draw_filter_into_device(SkBaseDevice* src, const SkImageFilter* filter,
    SkBaseDevice* dst, const SkMatrix& ctm)
{

    SkBitmap srcBM;

#if SK_SUPPORT_GPU
    // TODO: remove this virtual usage of accessRenderTarget! It is preventing
    // removal of the virtual on SkBaseDevice.
    GrRenderTarget* srcRT = src->accessRenderTarget();
    if (srcRT && !srcRT->asTexture() && dst->accessRenderTarget()) {
        // When both the src & the dst are on the gpu but the src doesn't have a texture,
        // we create a temporary texture for the draw.
        // TODO: we should actually only copy the portion of the source needed to apply the image
        // filter
        GrContext* context = srcRT->getContext();
        SkAutoTUnref<GrTexture> tex(context->textureProvider()->createTexture(srcRT->desc(),
            SkBudgeted::kYes));

        context->copySurface(tex, srcRT);

        GrWrapTextureInBitmap(tex, src->width(), src->height(), src->isOpaque(), &srcBM);
    } else
#endif
    {
        srcBM = src->accessBitmap(false);
    }

    SkCanvas c(dst);

    SkPaint p;
    p.setImageFilter(filter->makeWithLocalMatrix(ctm));
    const SkScalar x = SkIntToScalar(src->getOrigin().x());
    const SkScalar y = SkIntToScalar(src->getOrigin().y());
    c.drawBitmap(srcBM, x, y, &p);
}

static SkImageInfo make_layer_info(const SkImageInfo& prev, int w, int h, bool isOpaque,
    const SkPaint* paint)
{
    // need to force L32 for now if we have an image filter. Once filters support other colortypes
    // e.g. sRGB or F16, we can remove this check
    // SRGBTODO: Can we remove this check now?
    const bool hasImageFilter = paint && paint->getImageFilter();

    SkAlphaType alphaType = isOpaque ? kOpaque_SkAlphaType : kPremul_SkAlphaType;
    if ((prev.bytesPerPixel() < 4) || hasImageFilter) {
        // force to L32
        return SkImageInfo::MakeN32(w, h, alphaType);
    } else {
        // keep the same characteristics as the prev
        return SkImageInfo::Make(w, h, prev.colorType(), alphaType, sk_ref_sp(prev.colorSpace()));
    }
}

void SkCanvas::internalSaveLayer(const SaveLayerRec& rec, SaveLayerStrategy strategy)
{
    const SkRect* bounds = rec.fBounds;
    const SkPaint* paint = rec.fPaint;
    SaveLayerFlags saveLayerFlags = rec.fSaveLayerFlags;

#ifndef SK_SUPPORT_LEGACY_CLIPTOLAYERFLAG
    saveLayerFlags &= ~kDontClipToLayer_PrivateSaveLayerFlag;
#endif

    SkLazyPaint lazyP;
    SkImageFilter* imageFilter = paint ? paint->getImageFilter() : NULL;
    SkMatrix stashedMatrix = fMCRec->fMatrix;
    SkMatrix remainder;
    SkSize scale;
    /*
     *  ImageFilters (so far) do not correctly handle matrices (CTM) that contain rotation/skew/etc.
     *  but they do handle scaling. To accommodate this, we do the following:
     *
     *  1. Stash off the current CTM
     *  2. Decompose the CTM into SCALE and REMAINDER
     *  3. Wack the CTM to be just SCALE, and wrap the imagefilter with a MatrixImageFilter that
     *     contains the REMAINDER
     *  4. Proceed as usual, allowing the client to draw into the layer (now with a scale-only CTM)
     *  5. During restore, we process the MatrixImageFilter, which applies REMAINDER to the output
     *     of the original imagefilter, and draw that (via drawSprite)
     *  6. Unwack the CTM to its original state (i.e. stashedMatrix)
     *
     *  Perhaps in the future we could augment #5 to apply REMAINDER as part of the draw (no longer
     *  a sprite operation) to avoid the extra buffer/overhead of MatrixImageFilter.
     */
    if (imageFilter && !stashedMatrix.isScaleTranslate() && !imageFilter->canHandleComplexCTM() && stashedMatrix.decomposeScale(&scale, &remainder)) {
        // We will restore the matrix (which we are overwriting here) in restore via fStashedMatrix
        this->internalSetMatrix(SkMatrix::MakeScale(scale.width(), scale.height()));
        SkPaint* p = lazyP.set(*paint);
        p->setImageFilter(SkImageFilter::MakeMatrixFilter(remainder,
            SkFilterQuality::kLow_SkFilterQuality,
            sk_ref_sp(imageFilter)));
        imageFilter = p->getImageFilter();
        paint = p;
    }

=======
int SkCanvas::saveLayer(const SkRect* bounds, const SkPaint* paint) {
    if (gIgnoreSaveLayerBounds) {
        bounds = NULL;
    }
    SaveLayerStrategy strategy = this->willSaveLayer(bounds, paint, kARGB_ClipLayer_SaveFlag);
    fSaveCount += 1;
    this->internalSaveLayer(bounds, paint, kARGB_ClipLayer_SaveFlag, strategy);
    return this->getSaveCount() - 1;
}

int SkCanvas::saveLayer(const SkRect* bounds, const SkPaint* paint, SaveFlags flags) {
    if (gIgnoreSaveLayerBounds) {
        bounds = NULL;
    }
    SaveLayerStrategy strategy = this->willSaveLayer(bounds, paint, flags);
    fSaveCount += 1;
    this->internalSaveLayer(bounds, paint, flags, strategy);
    return this->getSaveCount() - 1;
}

void SkCanvas::internalSaveLayer(const SkRect* bounds, const SkPaint* paint, SaveFlags flags,
                                 SaveLayerStrategy strategy) {
#ifndef SK_SUPPORT_LEGACY_CLIPTOLAYERFLAG
    flags |= kClipToLayer_SaveFlag;
#endif

>>>>>>> miniblink49
    // do this before we create the layer. We don't call the public save() since
    // that would invoke a possibly overridden virtual
    this->internalSave();

    fDeviceCMDirty = true;

    SkIRect ir;
<<<<<<< HEAD
    if (!this->clipRectBounds(bounds, saveLayerFlags, &ir, imageFilter)) {
=======
    if (!this->clipRectBounds(bounds, flags, &ir, paint ? paint->getImageFilter() : NULL)) {
>>>>>>> miniblink49
        return;
    }

    // FIXME: do willSaveLayer() overriders returning kNoLayer_SaveLayerStrategy really care about
    // the clipRectBounds() call above?
    if (kNoLayer_SaveLayerStrategy == strategy) {
        return;
    }

<<<<<<< HEAD
    bool isOpaque = SkToBool(saveLayerFlags & kIsOpaque_SaveLayerFlag);
=======
    bool isOpaque = !SkToBool(flags & kHasAlphaLayer_SaveFlag);
>>>>>>> miniblink49
    SkPixelGeometry geo = fProps.pixelGeometry();
    if (paint) {
        // TODO: perhaps add a query to filters so we might preserve opaqueness...
        if (paint->getImageFilter() || paint->getColorFilter()) {
            isOpaque = false;
            geo = kUnknown_SkPixelGeometry;
        }
    }
<<<<<<< HEAD

    SkBaseDevice* device = this->getTopDevice();
    if (nullptr == device) {
=======
    SkImageInfo info = SkImageInfo::MakeN32(ir.width(), ir.height(),
                        isOpaque ? kOpaque_SkAlphaType : kPremul_SkAlphaType);

    SkBaseDevice* device = this->getTopDevice();
    if (NULL == device) {
>>>>>>> miniblink49
        SkDebugf("Unable to find device for layer.");
        return;
    }

<<<<<<< HEAD
    SkImageInfo info = make_layer_info(device->imageInfo(), ir.width(), ir.height(), isOpaque,
        paint);

    bool forceSpriteOnRestore = false;
    {
        const bool preserveLCDText = kOpaque_SkAlphaType == info.alphaType() || (saveLayerFlags & kPreserveLCDText_SaveLayerFlag);
        const SkBaseDevice::TileUsage usage = SkBaseDevice::kNever_TileUsage;
        const SkBaseDevice::CreateInfo createInfo = SkBaseDevice::CreateInfo(info, usage, geo,
            preserveLCDText, false);
        SkBaseDevice* newDev = device->onCreateDevice(createInfo, paint);
        if (nullptr == newDev) {
            // If onCreateDevice didn't succeed, try raster (e.g. PDF couldn't handle the paint)
            const SkSurfaceProps surfaceProps(fProps.flags(), createInfo.fPixelGeometry);
            newDev = SkBitmapDevice::Create(createInfo.fInfo, surfaceProps);
            if (nullptr == newDev) {
                SkErrorInternals::SetError(kInternalError_SkError,
                    "Unable to create device for layer.");
=======
    bool forceSpriteOnRestore = false;
    {
        const SkBaseDevice::TileUsage usage = SkBaseDevice::kNever_TileUsage;
        const SkBaseDevice::CreateInfo createInfo = SkBaseDevice::CreateInfo(info, usage, geo);
        SkBaseDevice* newDev = device->onCreateDevice(createInfo, paint);
        if (NULL == newDev) {
            // If onCreateDevice didn't succeed, try raster (e.g. PDF couldn't handle the paint)
            const SkSurfaceProps surfaceProps(fProps.flags(), createInfo.fPixelGeometry);
            newDev = SkBitmapDevice::Create(createInfo.fInfo, surfaceProps);
            if (NULL == newDev) {
                SkErrorInternals::SetError(kInternalError_SkError,
                                           "Unable to create device for layer.");
>>>>>>> miniblink49
                return;
            }
            forceSpriteOnRestore = true;
        }
        device = newDev;
    }
<<<<<<< HEAD
    device->setOrigin(ir.fLeft, ir.fTop);

    if (rec.fBackdrop) {
        draw_filter_into_device(fMCRec->fTopLayer->fDevice, rec.fBackdrop, device, fMCRec->fMatrix);
    }

    DeviceCM* layer = new DeviceCM(device, paint, this, fConservativeRasterClip,
        forceSpriteOnRestore, stashedMatrix);
=======

    device->setOrigin(ir.fLeft, ir.fTop);
    DeviceCM* layer = SkNEW_ARGS(DeviceCM, (device, paint, this, fConservativeRasterClip,
                                            forceSpriteOnRestore));
>>>>>>> miniblink49
    device->unref();

    layer->fNext = fMCRec->fTopLayer;
    fMCRec->fLayer = layer;
<<<<<<< HEAD
    fMCRec->fTopLayer = layer; // this field is NOT an owner of layer
}

int SkCanvas::saveLayerAlpha(const SkRect* bounds, U8CPU alpha)
{
    if (0xFF == alpha) {
        return this->saveLayer(bounds, nullptr);
    } else {
        SkPaint tmpPaint;
        tmpPaint.setAlpha(alpha);
        return this->saveLayer(bounds, &tmpPaint);
    }
}

void SkCanvas::internalRestore()
{
=======
    fMCRec->fTopLayer = layer;    // this field is NOT an owner of layer
}

int SkCanvas::saveLayerAlpha(const SkRect* bounds, U8CPU alpha) {
    return this->saveLayerAlpha(bounds, alpha, kARGB_ClipLayer_SaveFlag);
}

int SkCanvas::saveLayerAlpha(const SkRect* bounds, U8CPU alpha,
                             SaveFlags flags) {
    if (0xFF == alpha) {
        return this->saveLayer(bounds, NULL, flags);
    } else {
        SkPaint tmpPaint;
        tmpPaint.setAlpha(alpha);
        return this->saveLayer(bounds, &tmpPaint, flags);
    }
}

void SkCanvas::internalRestore() {
>>>>>>> miniblink49
    SkASSERT(fMCStack.count() != 0);

    fDeviceCMDirty = true;
    fCachedLocalClipBoundsDirty = true;

    fClipStack->restore();

    // reserve our layer (if any)
<<<<<<< HEAD
    DeviceCM* layer = fMCRec->fLayer; // may be null
    // now detach it from fMCRec so we can pop(). Gets freed after its drawn
    fMCRec->fLayer = nullptr;

    // now do the normal restore()
    fMCRec->~MCRec(); // balanced in save()
=======
    DeviceCM* layer = fMCRec->fLayer;   // may be null
    // now detach it from fMCRec so we can pop(). Gets freed after its drawn
    fMCRec->fLayer = NULL;

    // now do the normal restore()
    fMCRec->~MCRec();       // balanced in save()
>>>>>>> miniblink49
    fMCStack.pop_back();
    fMCRec = (MCRec*)fMCStack.back();

    /*  Time to draw the layer's offscreen. We can't call the public drawSprite,
        since if we're being recorded, we don't want to record this (the
        recorder will have already recorded the restore).
    */
    if (layer) {
        if (layer->fNext) {
            const SkIPoint& origin = layer->fDevice->getOrigin();
            this->internalDrawDevice(layer->fDevice, origin.x(), origin.y(),
<<<<<<< HEAD
                layer->fPaint, layer->fDeviceIsBitmapDevice);
            // restore what we smashed in internalSaveLayer
            fMCRec->fMatrix = layer->fStashedMatrix;
            // reset this, since internalDrawDevice will have set it to true
            fDeviceCMDirty = true;
            delete layer;
=======
                                     layer->fPaint, layer->fDeviceIsBitmapDevice);
            // reset this, since internalDrawDevice will have set it to true
            fDeviceCMDirty = true;
            SkDELETE(layer);
>>>>>>> miniblink49
        } else {
            // we're at the root
            SkASSERT(layer == (void*)fDeviceCMStorage);
            layer->~DeviceCM();
<<<<<<< HEAD
            // no need to update fMCRec, 'cause we're killing the canvas
=======
>>>>>>> miniblink49
        }
    }
}

<<<<<<< HEAD
sk_sp<SkSurface> SkCanvas::makeSurface(const SkImageInfo& info, const SkSurfaceProps* props)
{
    if (nullptr == props) {
=======
SkSurface* SkCanvas::newSurface(const SkImageInfo& info, const SkSurfaceProps* props) {
    if (NULL == props) {
>>>>>>> miniblink49
        props = &fProps;
    }
    return this->onNewSurface(info, *props);
}

<<<<<<< HEAD
sk_sp<SkSurface> SkCanvas::onNewSurface(const SkImageInfo& info, const SkSurfaceProps& props)
{
    SkBaseDevice* dev = this->getDevice();
    return dev ? dev->makeSurface(info, props) : nullptr;
}

SkImageInfo SkCanvas::imageInfo() const
{
=======
SkSurface* SkCanvas::onNewSurface(const SkImageInfo& info, const SkSurfaceProps& props) {
    SkBaseDevice* dev = this->getDevice();
    return dev ? dev->newSurface(info, props) : NULL;
}

SkImageInfo SkCanvas::imageInfo() const {
>>>>>>> miniblink49
    SkBaseDevice* dev = this->getDevice();
    if (dev) {
        return dev->imageInfo();
    } else {
        return SkImageInfo::MakeUnknown(0, 0);
    }
}

<<<<<<< HEAD
bool SkCanvas::getProps(SkSurfaceProps* props) const
{
    SkBaseDevice* dev = this->getDevice();
    if (dev) {
        if (props) {
            *props = fProps;
        }
        return true;
    } else {
        return false;
    }
}

#ifdef SK_SUPPORT_LEGACY_PEEKPIXELS_PARMS
const void* SkCanvas::peekPixels(SkImageInfo* info, size_t* rowBytes)
{
    SkPixmap pmap;
    if (this->peekPixels(&pmap)) {
        if (info) {
            *info = pmap.info();
        }
        if (rowBytes) {
            *rowBytes = pmap.rowBytes();
        }
        return pmap.addr();
    }
    return nullptr;
}
#endif

bool SkCanvas::peekPixels(SkPixmap* pmap)
{
    return this->onPeekPixels(pmap);
}

bool SkCanvas::onPeekPixels(SkPixmap* pmap)
{
=======
const void* SkCanvas::peekPixels(SkImageInfo* info, size_t* rowBytes) {
    SkPixmap pmap;
    if (!this->onPeekPixels(&pmap)) {
        return NULL;
    }
    if (info) {
        *info = pmap.info();
    }
    if (rowBytes) {
        *rowBytes = pmap.rowBytes();
    }
    return pmap.addr();
}

bool SkCanvas::onPeekPixels(SkPixmap* pmap) {
>>>>>>> miniblink49
    SkBaseDevice* dev = this->getDevice();
    return dev && dev->peekPixels(pmap);
}

<<<<<<< HEAD
void* SkCanvas::accessTopLayerPixels(SkImageInfo* info, size_t* rowBytes, SkIPoint* origin)
{
    SkPixmap pmap;
    if (!this->onAccessTopLayerPixels(&pmap)) {
        return nullptr;
=======
void* SkCanvas::accessTopLayerPixels(SkImageInfo* info, size_t* rowBytes, SkIPoint* origin) {
    SkPixmap pmap;
    if (!this->onAccessTopLayerPixels(&pmap)) {
        return NULL;
>>>>>>> miniblink49
    }
    if (info) {
        *info = pmap.info();
    }
    if (rowBytes) {
        *rowBytes = pmap.rowBytes();
    }
    if (origin) {
        *origin = this->getTopDevice(false)->getOrigin();
    }
    return pmap.writable_addr();
}

<<<<<<< HEAD
bool SkCanvas::onAccessTopLayerPixels(SkPixmap* pmap)
{
=======
bool SkCanvas::onAccessTopLayerPixels(SkPixmap* pmap) {
>>>>>>> miniblink49
    SkBaseDevice* dev = this->getTopDevice();
    return dev && dev->accessPixels(pmap);
}

<<<<<<< HEAD
/////////////////////////////////////////////////////////////////////////////

void SkCanvas::internalDrawDevice(SkBaseDevice* srcDev, int x, int y,
    const SkPaint* paint, bool deviceIsBitmapDevice)
{
    SkPaint tmp;
    if (nullptr == paint) {
=======
SkAutoROCanvasPixels::SkAutoROCanvasPixels(SkCanvas* canvas) {
    fAddr = canvas->peekPixels(&fInfo, &fRowBytes);
    if (NULL == fAddr) {
        fInfo = canvas->imageInfo();
        if (kUnknown_SkColorType == fInfo.colorType() || !fBitmap.tryAllocPixels(fInfo)) {
            return; // failure, fAddr is NULL
        }
        if (!canvas->readPixels(&fBitmap, 0, 0)) {
            return; // failure, fAddr is NULL
        }
        fAddr = fBitmap.getPixels();
        fRowBytes = fBitmap.rowBytes();
    }
    SkASSERT(fAddr);    // success
}

bool SkAutoROCanvasPixels::asROBitmap(SkBitmap* bitmap) const {
    if (fAddr) {
        return bitmap->installPixels(fInfo, const_cast<void*>(fAddr), fRowBytes);
    } else {
        bitmap->reset();
        return false;
    }
}

/////////////////////////////////////////////////////////////////////////////
void SkCanvas::internalDrawBitmap(const SkBitmap& bitmap,
                                const SkMatrix& matrix, const SkPaint* paint) {
    if (bitmap.drawsNothing()) {
        return;
    }

    SkLazyPaint lazy;
    if (NULL == paint) {
        paint = lazy.init();
    }

    SkDEBUGCODE(bitmap.validate();)

    SkRect storage;
    const SkRect* bounds = NULL;
    if (paint && paint->canComputeFastBounds()) {
        bitmap.getBounds(&storage);
        matrix.mapRect(&storage);
        bounds = &paint->computeFastBounds(storage, &storage);
    }

    LOOPER_BEGIN(*paint, SkDrawFilter::kBitmap_Type, bounds)

    while (iter.next()) {
        iter.fDevice->drawBitmap(iter, bitmap, matrix, looper.paint());
    }

    LOOPER_END
}

void SkCanvas::internalDrawDevice(SkBaseDevice* srcDev, int x, int y,
                                  const SkPaint* paint, bool deviceIsBitmapDevice) {
    SkPaint tmp;
    if (NULL == paint) {
>>>>>>> miniblink49
        paint = &tmp;
    }

    LOOPER_BEGIN_DRAWDEVICE(*paint, SkDrawFilter::kBitmap_Type)
    while (iter.next()) {
        SkBaseDevice* dstDev = iter.fDevice;
        paint = &looper.paint();
        SkImageFilter* filter = paint->getImageFilter();
        SkIPoint pos = { x - iter.getX(), y - iter.getY() };
<<<<<<< HEAD
        if (filter) {
            const SkBitmap& srcBM = srcDev->accessBitmap(false);
            dstDev->drawSpriteWithFilter(iter, srcBM, pos.x(), pos.y(), *paint);
=======
        if (filter && !dstDev->canHandleImageFilter(filter)) {
            SkImageFilter::Proxy proxy(dstDev);
            SkBitmap dst;
            SkIPoint offset = SkIPoint::Make(0, 0);
            const SkBitmap& src = srcDev->accessBitmap(false);
            SkMatrix matrix = *iter.fMatrix;
            matrix.postTranslate(SkIntToScalar(-pos.x()), SkIntToScalar(-pos.y()));
            SkIRect clipBounds = SkIRect::MakeWH(srcDev->width(), srcDev->height());
            SkAutoTUnref<SkImageFilter::Cache> cache(dstDev->getImageFilterCache());
            SkImageFilter::Context ctx(matrix, clipBounds, cache.get());
            if (filter->filterImage(&proxy, src, ctx, &dst, &offset)) {
                SkPaint tmpUnfiltered(*paint);
                tmpUnfiltered.setImageFilter(NULL);
                dstDev->drawSprite(iter, dst, pos.x() + offset.x(), pos.y() + offset.y(),
                                   tmpUnfiltered);
            }
>>>>>>> miniblink49
        } else if (deviceIsBitmapDevice) {
            const SkBitmap& src = static_cast<SkBitmapDevice*>(srcDev)->fBitmap;
            dstDev->drawSprite(iter, src, pos.x(), pos.y(), *paint);
        } else {
            dstDev->drawDevice(iter, srcDev, pos.x(), pos.y(), *paint);
        }
    }
    LOOPER_END
}

<<<<<<< HEAD
/////////////////////////////////////////////////////////////////////////////

void SkCanvas::translate(SkScalar dx, SkScalar dy)
{
=======
void SkCanvas::onDrawSprite(const SkBitmap& bitmap, int x, int y, const SkPaint* paint) {
    if (gTreatSpriteAsBitmap) {
        this->save();
        this->resetMatrix();
        this->drawBitmap(bitmap, SkIntToScalar(x), SkIntToScalar(y), paint);
        this->restore();
        return;
    }

    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawSprite()");
    if (bitmap.drawsNothing()) {
        return;
    }
    SkDEBUGCODE(bitmap.validate();)

    SkPaint tmp;
    if (NULL == paint) {
        paint = &tmp;
    }

    LOOPER_BEGIN_DRAWDEVICE(*paint, SkDrawFilter::kBitmap_Type)

    while (iter.next()) {
        paint = &looper.paint();
        SkImageFilter* filter = paint->getImageFilter();
        SkIPoint pos = { x - iter.getX(), y - iter.getY() };
        if (filter && !iter.fDevice->canHandleImageFilter(filter)) {
            SkImageFilter::Proxy proxy(iter.fDevice);
            SkBitmap dst;
            SkIPoint offset = SkIPoint::Make(0, 0);
            SkMatrix matrix = *iter.fMatrix;
            matrix.postTranslate(SkIntToScalar(-pos.x()), SkIntToScalar(-pos.y()));
            const SkIRect clipBounds = bitmap.bounds();
            SkAutoTUnref<SkImageFilter::Cache> cache(iter.fDevice->getImageFilterCache());
            SkImageFilter::Context ctx(matrix, clipBounds, cache.get());
            if (filter->filterImage(&proxy, bitmap, ctx, &dst, &offset)) {
                SkPaint tmpUnfiltered(*paint);
                tmpUnfiltered.setImageFilter(NULL);
                iter.fDevice->drawSprite(iter, dst, pos.x() + offset.x(), pos.y() + offset.y(),
                                         tmpUnfiltered);
            }
        } else {
            iter.fDevice->drawSprite(iter, bitmap, pos.x(), pos.y(), *paint);
        }
    }
    LOOPER_END
}

/////////////////////////////////////////////////////////////////////////////
void SkCanvas::translate(SkScalar dx, SkScalar dy) {
>>>>>>> miniblink49
    SkMatrix m;
    m.setTranslate(dx, dy);
    this->concat(m);
}

<<<<<<< HEAD
void SkCanvas::scale(SkScalar sx, SkScalar sy)
{
=======
void SkCanvas::scale(SkScalar sx, SkScalar sy) {
>>>>>>> miniblink49
    SkMatrix m;
    m.setScale(sx, sy);
    this->concat(m);
}

<<<<<<< HEAD
void SkCanvas::rotate(SkScalar degrees)
{
=======
void SkCanvas::rotate(SkScalar degrees) {
>>>>>>> miniblink49
    SkMatrix m;
    m.setRotate(degrees);
    this->concat(m);
}

<<<<<<< HEAD
void SkCanvas::skew(SkScalar sx, SkScalar sy)
{
=======
void SkCanvas::skew(SkScalar sx, SkScalar sy) {
>>>>>>> miniblink49
    SkMatrix m;
    m.setSkew(sx, sy);
    this->concat(m);
}

<<<<<<< HEAD
void SkCanvas::concat(const SkMatrix& matrix)
{
=======
void SkCanvas::concat(const SkMatrix& matrix) {
>>>>>>> miniblink49
    if (matrix.isIdentity()) {
        return;
    }

    this->checkForDeferredSave();
    fDeviceCMDirty = true;
    fCachedLocalClipBoundsDirty = true;
    fMCRec->fMatrix.preConcat(matrix);

    this->didConcat(matrix);
}

<<<<<<< HEAD
void SkCanvas::internalSetMatrix(const SkMatrix& matrix)
{
    fDeviceCMDirty = true;
    fCachedLocalClipBoundsDirty = true;
    fMCRec->fMatrix = matrix;
}

void SkCanvas::setMatrix(const SkMatrix& matrix)
{
    this->checkForDeferredSave();
    this->internalSetMatrix(matrix);
    this->didSetMatrix(matrix);
}

void SkCanvas::resetMatrix()
{
    this->setMatrix(SkMatrix::I());
=======
void SkCanvas::setMatrix(const SkMatrix& matrix) {
    this->checkForDeferredSave();
    fDeviceCMDirty = true;
    fCachedLocalClipBoundsDirty = true;
    fMCRec->fMatrix = matrix;
    this->didSetMatrix(matrix);
}

void SkCanvas::resetMatrix() {
    SkMatrix matrix;

    matrix.reset();
    this->setMatrix(matrix);
>>>>>>> miniblink49
}

//////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void SkCanvas::clipRect(const SkRect& rect, SkRegion::Op op, bool doAA)
{
    if (!fAllowSoftClip) {
        doAA = false;
    }

#ifdef SK_SUPPORT_PRECHECK_CLIPRECT
    // Check if we can quick-accept the clip call (and do nothing)
    //
    if (SkRegion::kIntersect_Op == op && !doAA && fMCRec->fMatrix.rectStaysRect()) {
        SkRect devR;
        fMCRec->fMatrix.mapRect(&devR, rect);
        // NOTE: this check is CTM specific, since we might round differently with a different
        //       CTM. Thus this is only 100% reliable if there is not global CTM scale to be
        //       applied later (i.e. if this is going into a picture).
        if (devR.round().contains(fMCRec->fRasterClip.getBounds())) {
#if 0
            SkDebugf("ignored clipRect [%g %g %g %g]\n",
                     rect.left(), rect.top(), rect.right(), rect.bottom());
#endif
            return;
        }
    }
#endif

=======
void SkCanvas::clipRect(const SkRect& rect, SkRegion::Op op, bool doAA) {
>>>>>>> miniblink49
    this->checkForDeferredSave();
    ClipEdgeStyle edgeStyle = doAA ? kSoft_ClipEdgeStyle : kHard_ClipEdgeStyle;
    this->onClipRect(rect, op, edgeStyle);
}

<<<<<<< HEAD
void SkCanvas::onClipRect(const SkRect& rect, SkRegion::Op op, ClipEdgeStyle edgeStyle)
{
#ifdef SK_ENABLE_CLIP_QUICKREJECT
    if (SkRegion::kIntersect_Op == op) {
        if (fMCRec->fRasterClip.isEmpty()) {
            return;
=======
void SkCanvas::onClipRect(const SkRect& rect, SkRegion::Op op, ClipEdgeStyle edgeStyle) {
#ifdef SK_ENABLE_CLIP_QUICKREJECT
    if (SkRegion::kIntersect_Op == op) {
        if (fMCRec->fRasterClip.isEmpty()) {
            return false;
>>>>>>> miniblink49
        }

        if (this->quickReject(rect)) {
            fDeviceCMDirty = true;
            fCachedLocalClipBoundsDirty = true;

            fClipStack->clipEmpty();
<<<<<<< HEAD
            (void)fMCRec->fRasterClip.setEmpty();
            return;
        }
    }
#endif

    const bool rectStaysRect = fMCRec->fMatrix.rectStaysRect();
    SkRect devR;
    if (rectStaysRect) {
        fMCRec->fMatrix.mapRect(&devR, rect);
    }

#ifndef SK_SUPPORT_PRECHECK_CLIPRECT
    if (SkRegion::kIntersect_Op == op && kHard_ClipEdgeStyle == edgeStyle
        && rectStaysRect) {
        if (devR.round().contains(fMCRec->fRasterClip.getBounds())) {
#if 0
            SkDebugf("------- ignored clipRect [%g %g %g %g]\n",
                     rect.left(), rect.top(), rect.right(), rect.bottom());
#endif
            return;
=======
            return fMCRec->fRasterClip.setEmpty();
>>>>>>> miniblink49
        }
    }
#endif

    AutoValidateClip avc(this);

    fDeviceCMDirty = true;
    fCachedLocalClipBoundsDirty = true;
<<<<<<< HEAD

    if (rectStaysRect) {
        const bool isAA = kSoft_ClipEdgeStyle == edgeStyle;
        fClipStack->clipDevRect(devR, op, isAA);
        fMCRec->fRasterClip.op(devR, this->getTopLayerBounds(), op, isAA);
=======
    if (!fAllowSoftClip) {
        edgeStyle = kHard_ClipEdgeStyle;
    }

    if (fMCRec->fMatrix.rectStaysRect()) {
        // for these simpler matrices, we can stay a rect even after applying
        // the matrix. This means we don't have to a) make a path, and b) tell
        // the region code to scan-convert the path, only to discover that it
        // is really just a rect.
        SkRect      r;

        fMCRec->fMatrix.mapRect(&r, rect);
        fClipStack->clipDevRect(r, op, kSoft_ClipEdgeStyle == edgeStyle);
        fMCRec->fRasterClip.op(r, this->getBaseLayerSize(), op, kSoft_ClipEdgeStyle == edgeStyle);
>>>>>>> miniblink49
    } else {
        // since we're rotated or some such thing, we convert the rect to a path
        // and clip against that, since it can handle any matrix. However, to
        // avoid recursion in the case where we are subclassed (e.g. Pictures)
        // we explicitly call "our" version of clipPath.
<<<<<<< HEAD
        SkPath path;
=======
        SkPath  path;
>>>>>>> miniblink49

        path.addRect(rect);
        this->SkCanvas::onClipPath(path, op, edgeStyle);
    }
}

<<<<<<< HEAD
void SkCanvas::clipRRect(const SkRRect& rrect, SkRegion::Op op, bool doAA)
{
=======
static void rasterclip_path(SkRasterClip* rc, const SkCanvas* canvas, const SkPath& devPath,
                            SkRegion::Op op, bool doAA) {
    rc->op(devPath, canvas->getBaseLayerSize(), op, doAA);
}

void SkCanvas::clipRRect(const SkRRect& rrect, SkRegion::Op op, bool doAA) {
>>>>>>> miniblink49
    this->checkForDeferredSave();
    ClipEdgeStyle edgeStyle = doAA ? kSoft_ClipEdgeStyle : kHard_ClipEdgeStyle;
    if (rrect.isRect()) {
        this->onClipRect(rrect.getBounds(), op, edgeStyle);
    } else {
        this->onClipRRect(rrect, op, edgeStyle);
    }
}

<<<<<<< HEAD
void SkCanvas::onClipRRect(const SkRRect& rrect, SkRegion::Op op, ClipEdgeStyle edgeStyle)
{
=======
void SkCanvas::onClipRRect(const SkRRect& rrect, SkRegion::Op op, ClipEdgeStyle edgeStyle) {
>>>>>>> miniblink49
    SkRRect transformedRRect;
    if (rrect.transform(fMCRec->fMatrix, &transformedRRect)) {
        AutoValidateClip avc(this);

        fDeviceCMDirty = true;
        fCachedLocalClipBoundsDirty = true;
        if (!fAllowSoftClip) {
            edgeStyle = kHard_ClipEdgeStyle;
        }

        fClipStack->clipDevRRect(transformedRRect, op, kSoft_ClipEdgeStyle == edgeStyle);

<<<<<<< HEAD
        fMCRec->fRasterClip.op(transformedRRect, this->getTopLayerBounds(), op,
            kSoft_ClipEdgeStyle == edgeStyle);
=======
        SkPath devPath;
        devPath.addRRect(transformedRRect);

        rasterclip_path(&fMCRec->fRasterClip, this, devPath, op, kSoft_ClipEdgeStyle == edgeStyle);
>>>>>>> miniblink49
        return;
    }

    SkPath path;
    path.addRRect(rrect);
    // call the non-virtual version
    this->SkCanvas::onClipPath(path, op, edgeStyle);
}

<<<<<<< HEAD
void SkCanvas::clipPath(const SkPath& path, SkRegion::Op op, bool doAA)
{
    this->checkForDeferredSave();
    ClipEdgeStyle edgeStyle = doAA ? kSoft_ClipEdgeStyle : kHard_ClipEdgeStyle;

    if (!path.isInverseFillType() && fMCRec->fMatrix.rectStaysRect()) {
        SkRect r;
        if (path.isRect(&r)) {
            this->onClipRect(r, op, edgeStyle);
            return;
        }
        SkRRect rrect;
        if (path.isOval(&r)) {
            rrect.setOval(r);
            this->onClipRRect(rrect, op, edgeStyle);
            return;
        }
        if (path.isRRect(&rrect)) {
            this->onClipRRect(rrect, op, edgeStyle);
            return;
        }
    }

    this->onClipPath(path, op, edgeStyle);
}

void SkCanvas::onClipPath(const SkPath& path, SkRegion::Op op, ClipEdgeStyle edgeStyle)
{
#ifdef SK_ENABLE_CLIP_QUICKREJECT
    if (SkRegion::kIntersect_Op == op && !path.isInverseFillType()) {
        if (fMCRec->fRasterClip.isEmpty()) {
            return;
=======
void SkCanvas::clipPath(const SkPath& path, SkRegion::Op op, bool doAA) {
    this->checkForDeferredSave();
    ClipEdgeStyle edgeStyle = doAA ? kSoft_ClipEdgeStyle : kHard_ClipEdgeStyle;
    SkRect r;
    if (!path.isInverseFillType() && path.isRect(&r)) {
        this->onClipRect(r, op, edgeStyle);
    } else {
        this->onClipPath(path, op, edgeStyle);
    }
}

void SkCanvas::onClipPath(const SkPath& path, SkRegion::Op op, ClipEdgeStyle edgeStyle) {
#ifdef SK_ENABLE_CLIP_QUICKREJECT
    if (SkRegion::kIntersect_Op == op && !path.isInverseFillType()) {
        if (fMCRec->fRasterClip.isEmpty()) {
            return false;
>>>>>>> miniblink49
        }

        if (this->quickReject(path.getBounds())) {
            fDeviceCMDirty = true;
            fCachedLocalClipBoundsDirty = true;

            fClipStack->clipEmpty();
<<<<<<< HEAD
            (void)fMCRec->fRasterClip.setEmpty();
            return;
=======
            return fMCRec->fRasterClip.setEmpty();
>>>>>>> miniblink49
        }
    }
#endif

    AutoValidateClip avc(this);

    fDeviceCMDirty = true;
    fCachedLocalClipBoundsDirty = true;
    if (!fAllowSoftClip) {
        edgeStyle = kHard_ClipEdgeStyle;
    }

    SkPath devPath;
    path.transform(fMCRec->fMatrix, &devPath);

    // Check if the transfomation, or the original path itself
    // made us empty. Note this can also happen if we contained NaN
    // values. computing the bounds detects this, and will set our
    // bounds to empty if that is the case. (see SkRect::set(pts, count))
    if (devPath.getBounds().isEmpty()) {
        // resetting the path will remove any NaN or other wanky values
        // that might upset our scan converter.
        devPath.reset();
    }

    // if we called path.swap() we could avoid a deep copy of this path
    fClipStack->clipDevPath(devPath, op, kSoft_ClipEdgeStyle == edgeStyle);

    if (fAllowSimplifyClip) {
        bool clipIsAA = getClipStack()->asPath(&devPath);
        if (clipIsAA) {
            edgeStyle = kSoft_ClipEdgeStyle;
        }

        op = SkRegion::kReplace_Op;
    }

<<<<<<< HEAD
    fMCRec->fRasterClip.op(devPath, this->getTopLayerBounds(), op, edgeStyle);
}

void SkCanvas::clipRegion(const SkRegion& rgn, SkRegion::Op op)
{
=======
    rasterclip_path(&fMCRec->fRasterClip, this, devPath, op, edgeStyle);
}

void SkCanvas::clipRegion(const SkRegion& rgn, SkRegion::Op op) {
>>>>>>> miniblink49
    this->checkForDeferredSave();
    this->onClipRegion(rgn, op);
}

<<<<<<< HEAD
void SkCanvas::onClipRegion(const SkRegion& rgn, SkRegion::Op op)
{
=======
void SkCanvas::onClipRegion(const SkRegion& rgn, SkRegion::Op op) {
>>>>>>> miniblink49
    AutoValidateClip avc(this);

    fDeviceCMDirty = true;
    fCachedLocalClipBoundsDirty = true;

    // todo: signal fClipStack that we have a region, and therefore (I guess)
    // we have to ignore it, and use the region directly?
    fClipStack->clipDevRect(rgn.getBounds(), op);

    fMCRec->fRasterClip.op(rgn, op);
}

#ifdef SK_DEBUG
<<<<<<< HEAD
void SkCanvas::validateClip() const
{
=======
void SkCanvas::validateClip() const {
>>>>>>> miniblink49
    // construct clipRgn from the clipstack
    const SkBaseDevice* device = this->getDevice();
    if (!device) {
        SkASSERT(this->isClipEmpty());
        return;
    }

    SkIRect ir;
    ir.set(0, 0, device->width(), device->height());
    SkRasterClip tmpClip(ir, fConservativeRasterClip);

<<<<<<< HEAD
    SkClipStack::B2TIter iter(*fClipStack);
    const SkClipStack::Element* element;
    while ((element = iter.next()) != nullptr) {
        switch (element->getType()) {
        case SkClipStack::Element::kRect_Type:
            element->getRect().round(&ir);
            tmpClip.op(ir, element->getOp());
            break;
        case SkClipStack::Element::kEmpty_Type:
            tmpClip.setEmpty();
            break;
        default: {
            SkPath path;
            element->asPath(&path);
            tmpClip.op(path, this->getTopLayerBounds(), element->getOp(), element->isAA());
            break;
        }
=======
    SkClipStack::B2TIter                iter(*fClipStack);
    const SkClipStack::Element* element;
    while ((element = iter.next()) != NULL) {
        switch (element->getType()) {
            case SkClipStack::Element::kRect_Type:
                element->getRect().round(&ir);
                tmpClip.op(ir, element->getOp());
                break;
            case SkClipStack::Element::kEmpty_Type:
                tmpClip.setEmpty();
                break;
            default: {
                SkPath path;
                element->asPath(&path);
                rasterclip_path(&tmpClip, this, path, element->getOp(), element->isAA());
                break;
            }
>>>>>>> miniblink49
        }
    }
}
#endif

<<<<<<< HEAD
void SkCanvas::replayClips(ClipVisitor* visitor) const
{
    SkClipStack::B2TIter iter(*fClipStack);
    const SkClipStack::Element* element;

    while ((element = iter.next()) != nullptr) {
=======
void SkCanvas::replayClips(ClipVisitor* visitor) const {
    SkClipStack::B2TIter                iter(*fClipStack);
    const SkClipStack::Element*         element;

    while ((element = iter.next()) != NULL) {
>>>>>>> miniblink49
        element->replay(visitor);
    }
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
bool SkCanvas::isClipEmpty() const
{
    return fMCRec->fRasterClip.isEmpty();
}

bool SkCanvas::isClipRect() const
{
    return fMCRec->fRasterClip.isRect();
}

bool SkCanvas::quickReject(const SkRect& rect) const
{
=======
bool SkCanvas::isClipEmpty() const {
    return fMCRec->fRasterClip.isEmpty();
}

bool SkCanvas::isClipRect() const {
    return fMCRec->fRasterClip.isRect();
}

bool SkCanvas::quickReject(const SkRect& rect) const {
>>>>>>> miniblink49
    if (!rect.isFinite())
        return true;

    if (fMCRec->fRasterClip.isEmpty()) {
        return true;
    }

    if (fMCRec->fMatrix.hasPerspective()) {
        SkRect dst;
        fMCRec->fMatrix.mapRect(&dst, rect);
        return !SkIRect::Intersects(dst.roundOut(), fMCRec->fRasterClip.getBounds());
    } else {
        const SkRect& clipR = this->getLocalClipBounds();

        // for speed, do the most likely reject compares first
        // TODO: should we use | instead, or compare all 4 at once?
        if (rect.fTop >= clipR.fBottom || rect.fBottom <= clipR.fTop) {
            return true;
        }
        if (rect.fLeft >= clipR.fRight || rect.fRight <= clipR.fLeft) {
            return true;
        }
        return false;
    }
}

<<<<<<< HEAD
bool SkCanvas::quickReject(const SkPath& path) const
{
    return path.isEmpty() || this->quickReject(path.getBounds());
}

bool SkCanvas::getClipBounds(SkRect* bounds) const
{
=======
bool SkCanvas::quickReject(const SkPath& path) const {
    return path.isEmpty() || this->quickReject(path.getBounds());
}

bool SkCanvas::getClipBounds(SkRect* bounds) const {
>>>>>>> miniblink49
    SkIRect ibounds;
    if (!this->getClipDeviceBounds(&ibounds)) {
        return false;
    }

    SkMatrix inverse;
    // if we can't invert the CTM, we can't return local clip bounds
    if (!fMCRec->fMatrix.invert(&inverse)) {
        if (bounds) {
            bounds->setEmpty();
        }
        return false;
    }

    if (bounds) {
        SkRect r;
        // adjust it outwards in case we are antialiasing
        const int inset = 1;

        r.iset(ibounds.fLeft - inset, ibounds.fTop - inset,
<<<<<<< HEAD
            ibounds.fRight + inset, ibounds.fBottom + inset);
=======
               ibounds.fRight + inset, ibounds.fBottom + inset);
>>>>>>> miniblink49
        inverse.mapRect(bounds, r);
    }
    return true;
}

<<<<<<< HEAD
bool SkCanvas::getClipDeviceBounds(SkIRect* bounds) const
{
=======
bool SkCanvas::getClipDeviceBounds(SkIRect* bounds) const {
>>>>>>> miniblink49
    const SkRasterClip& clip = fMCRec->fRasterClip;
    if (clip.isEmpty()) {
        if (bounds) {
            bounds->setEmpty();
        }
        return false;
    }

    if (bounds) {
        *bounds = clip.getBounds();
    }
    return true;
}

<<<<<<< HEAD
const SkMatrix& SkCanvas::getTotalMatrix() const
{
    return fMCRec->fMatrix;
}

const SkRegion& SkCanvas::internal_private_getTotalClip() const
{
    return fMCRec->fRasterClip.forceGetBW();
}

GrDrawContext* SkCanvas::internal_private_accessTopLayerDrawContext()
{
    SkBaseDevice* dev = this->getTopDevice();
    return dev ? dev->accessDrawContext() : nullptr;
}

GrContext* SkCanvas::getGrContext()
{
    SkBaseDevice* device = this->getTopDevice();
    return device ? device->context() : nullptr;
}

void SkCanvas::drawDRRect(const SkRRect& outer, const SkRRect& inner,
    const SkPaint& paint)
{
=======
const SkMatrix& SkCanvas::getTotalMatrix() const {
    return fMCRec->fMatrix;
}

const SkRegion& SkCanvas::internal_private_getTotalClip() const {
    return fMCRec->fRasterClip.forceGetBW();
}

GrRenderTarget* SkCanvas::internal_private_accessTopLayerRenderTarget() {
    SkBaseDevice* dev = this->getTopDevice();
    return dev ? dev->accessRenderTarget() : NULL;
}

GrContext* SkCanvas::getGrContext() {
#if SK_SUPPORT_GPU
    SkBaseDevice* device = this->getTopDevice();
    if (device) {
        GrRenderTarget* renderTarget = device->accessRenderTarget();
        if (renderTarget) {
            return renderTarget->getContext();
        }
    }
#endif

    return NULL;

}

void SkCanvas::drawDRRect(const SkRRect& outer, const SkRRect& inner,
                          const SkPaint& paint) {
>>>>>>> miniblink49
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawDRRect()");
    if (outer.isEmpty()) {
        return;
    }
    if (inner.isEmpty()) {
        this->drawRRect(outer, paint);
        return;
    }

    // We don't have this method (yet), but technically this is what we should
    // be able to assert...
    // SkASSERT(outer.contains(inner));
    //
    // For now at least check for containment of bounds
    SkASSERT(outer.getBounds().contains(inner.getBounds()));

    this->onDrawDRRect(outer, inner, paint);
}

// These need to stop being virtual -- clients need to override the onDraw... versions

<<<<<<< HEAD
void SkCanvas::drawPaint(const SkPaint& paint)
{
    this->onDrawPaint(paint);
}

void SkCanvas::drawRect(const SkRect& r, const SkPaint& paint)
{
    this->onDrawRect(r, paint);
}

void SkCanvas::drawOval(const SkRect& r, const SkPaint& paint)
{
    this->onDrawOval(r, paint);
}

void SkCanvas::drawRRect(const SkRRect& rrect, const SkPaint& paint)
{
    this->onDrawRRect(rrect, paint);
}

void SkCanvas::drawPoints(PointMode mode, size_t count, const SkPoint pts[], const SkPaint& paint)
{
=======
void SkCanvas::drawPaint(const SkPaint& paint) {
    this->onDrawPaint(paint);
}

void SkCanvas::drawRect(const SkRect& r, const SkPaint& paint) {
    this->onDrawRect(r, paint);
}

void SkCanvas::drawOval(const SkRect& r, const SkPaint& paint) {
    this->onDrawOval(r, paint);
}

void SkCanvas::drawRRect(const SkRRect& rrect, const SkPaint& paint) {
    this->onDrawRRect(rrect, paint);
}

void SkCanvas::drawPoints(PointMode mode, size_t count, const SkPoint pts[], const SkPaint& paint) {
>>>>>>> miniblink49
    this->onDrawPoints(mode, count, pts, paint);
}

void SkCanvas::drawVertices(VertexMode vmode, int vertexCount, const SkPoint vertices[],
<<<<<<< HEAD
    const SkPoint texs[], const SkColor colors[], SkXfermode* xmode,
    const uint16_t indices[], int indexCount, const SkPaint& paint)
{
    this->onDrawVertices(vmode, vertexCount, vertices, texs, colors, xmode,
        indices, indexCount, paint);
}

void SkCanvas::drawPath(const SkPath& path, const SkPaint& paint)
{
    this->onDrawPath(path, paint);
}

void SkCanvas::drawImage(const SkImage* image, SkScalar x, SkScalar y, const SkPaint* paint)
{
    RETURN_ON_NULL(image);
    this->onDrawImage(image, x, y, paint);
}

void SkCanvas::drawImageRect(const SkImage* image, const SkRect& src, const SkRect& dst,
    const SkPaint* paint, SrcRectConstraint constraint)
{
    RETURN_ON_NULL(image);
    if (dst.isEmpty() || src.isEmpty()) {
        return;
    }
    this->onDrawImageRect(image, &src, dst, paint, constraint);
}

void SkCanvas::drawImageRect(const SkImage* image, const SkIRect& isrc, const SkRect& dst,
    const SkPaint* paint, SrcRectConstraint constraint)
{
    RETURN_ON_NULL(image);
    this->drawImageRect(image, SkRect::Make(isrc), dst, paint, constraint);
}

void SkCanvas::drawImageRect(const SkImage* image, const SkRect& dst, const SkPaint* paint,
    SrcRectConstraint constraint)
{
    RETURN_ON_NULL(image);
    this->drawImageRect(image, SkRect::MakeIWH(image->width(), image->height()), dst, paint,
        constraint);
}

void SkCanvas::drawImageNine(const SkImage* image, const SkIRect& center, const SkRect& dst,
    const SkPaint* paint)
{
    RETURN_ON_NULL(image);
=======
                            const SkPoint texs[], const SkColor colors[], SkXfermode* xmode,
                            const uint16_t indices[], int indexCount, const SkPaint& paint) {
    this->onDrawVertices(vmode, vertexCount, vertices, texs, colors, xmode,
                         indices, indexCount, paint);
}

void SkCanvas::drawBitmapMatrix(const SkBitmap&, const SkMatrix&, const SkPaint* paint) {
    DebugBreak();
}


void SkCanvas::drawPath(const SkPath& path, const SkPaint& paint) {
    this->onDrawPath(path, paint);
}

void SkCanvas::drawImage(const SkImage* image, SkScalar x, SkScalar y, const SkPaint* paint) {
    this->onDrawImage(image, x, y, paint);
}

void SkCanvas::drawImageRect(const SkImage* image, const SkRect* src, const SkRect& dst,
                             const SkPaint* paint) {
    if (dst.isEmpty()) {
        return;
    }
    this->onDrawImageRect(image, src, dst, paint);
}

void SkCanvas::drawImageNine(const SkImage* image, const SkIRect& center, const SkRect& dst,
                             const SkPaint* paint) {
>>>>>>> miniblink49
    if (dst.isEmpty()) {
        return;
    }
    if (!SkNinePatchIter::Valid(image->width(), image->height(), center)) {
<<<<<<< HEAD
        this->drawImageRect(image, dst, paint);
=======
        this->drawImageRect(image, NULL, dst, paint);
>>>>>>> miniblink49
    }
    this->onDrawImageNine(image, center, dst, paint);
}

<<<<<<< HEAD
void SkCanvas::drawBitmap(const SkBitmap& bitmap, SkScalar dx, SkScalar dy, const SkPaint* paint)
{
=======
void SkCanvas::drawBitmap(const SkBitmap& bitmap, SkScalar dx, SkScalar dy, const SkPaint* paint) {
>>>>>>> miniblink49
    if (bitmap.drawsNothing()) {
        return;
    }
    this->onDrawBitmap(bitmap, dx, dy, paint);
}

<<<<<<< HEAD
void SkCanvas::drawBitmapRect(const SkBitmap& bitmap, const SkRect& src, const SkRect& dst,
    const SkPaint* paint, SrcRectConstraint constraint)
{
    if (bitmap.drawsNothing() || dst.isEmpty() || src.isEmpty()) {
        return;
    }
    this->onDrawBitmapRect(bitmap, &src, dst, paint, constraint);
}

void SkCanvas::drawBitmapRect(const SkBitmap& bitmap, const SkIRect& isrc, const SkRect& dst,
    const SkPaint* paint, SrcRectConstraint constraint)
{
    this->drawBitmapRect(bitmap, SkRect::Make(isrc), dst, paint, constraint);
}

void SkCanvas::drawBitmapRect(const SkBitmap& bitmap, const SkRect& dst, const SkPaint* paint,
    SrcRectConstraint constraint)
{
    this->drawBitmapRect(bitmap, SkRect::MakeIWH(bitmap.width(), bitmap.height()), dst, paint,
        constraint);
}

void SkCanvas::drawBitmapNine(const SkBitmap& bitmap, const SkIRect& center, const SkRect& dst,
    const SkPaint* paint)
{
=======
void SkCanvas::drawBitmapRectToRect(const SkBitmap& bitmap, const SkRect* src, const SkRect& dst,
                                    const SkPaint* paint, DrawBitmapRectFlags flags) {
    if (bitmap.drawsNothing() || dst.isEmpty()) {
        return;
    }
    this->onDrawBitmapRect(bitmap, src, dst, paint, flags);
}

void SkCanvas::drawBitmapNine(const SkBitmap& bitmap, const SkIRect& center, const SkRect& dst,
                              const SkPaint* paint) {
>>>>>>> miniblink49
    if (bitmap.drawsNothing() || dst.isEmpty()) {
        return;
    }
    if (!SkNinePatchIter::Valid(bitmap.width(), bitmap.height(), center)) {
<<<<<<< HEAD
        this->drawBitmapRect(bitmap, dst, paint);
=======
        this->drawBitmapRectToRect(bitmap, NULL, dst, paint);
>>>>>>> miniblink49
    }
    this->onDrawBitmapNine(bitmap, center, dst, paint);
}

<<<<<<< HEAD
void SkCanvas::drawAtlas(const SkImage* atlas, const SkRSXform xform[], const SkRect tex[],
    const SkColor colors[], int count, SkXfermode::Mode mode,
    const SkRect* cull, const SkPaint* paint)
{
    RETURN_ON_NULL(atlas);
=======
void SkCanvas::drawSprite(const SkBitmap& bitmap, int left, int top, const SkPaint* paint) {
    if (bitmap.drawsNothing()) {
        return;
    }
    this->onDrawSprite(bitmap, left, top, paint);
}

void SkCanvas::drawAtlas(const SkImage* atlas, const SkRSXform xform[], const SkRect tex[],
                         const SkColor colors[], int count, SkXfermode::Mode mode,
                         const SkRect* cull, const SkPaint* paint) {
>>>>>>> miniblink49
    if (count <= 0) {
        return;
    }
    SkASSERT(atlas);
    SkASSERT(xform);
    SkASSERT(tex);
    this->onDrawAtlas(atlas, xform, tex, colors, count, mode, cull, paint);
}

<<<<<<< HEAD
void SkCanvas::drawAnnotation(const SkRect& rect, const char key[], SkData* value)
{
    if (key) {
        this->onDrawAnnotation(rect, key, value);
    }
}

void SkCanvas::legacy_drawImageRect(const SkImage* image, const SkRect* src, const SkRect& dst,
    const SkPaint* paint, SrcRectConstraint constraint)
{
    if (src) {
        this->drawImageRect(image, *src, dst, paint, constraint);
    } else {
        this->drawImageRect(image, SkRect::MakeIWH(image->width(), image->height()),
            dst, paint, constraint);
    }
}
void SkCanvas::legacy_drawBitmapRect(const SkBitmap& bitmap, const SkRect* src, const SkRect& dst,
    const SkPaint* paint, SrcRectConstraint constraint)
{
    if (src) {
        this->drawBitmapRect(bitmap, *src, dst, paint, constraint);
    } else {
        this->drawBitmapRect(bitmap, SkRect::MakeIWH(bitmap.width(), bitmap.height()),
            dst, paint, constraint);
    }
}

void SkCanvas::temporary_internal_describeTopLayer(SkMatrix* matrix, SkIRect* clip_bounds)
{
    SkIRect layer_bounds = this->getTopLayerBounds();
    if (matrix) {
        *matrix = this->getTotalMatrix();
        matrix->preTranslate(-layer_bounds.left(), -layer_bounds.top());
    }
    if (clip_bounds) {
        this->getClipDeviceBounds(clip_bounds);
        clip_bounds->offset(-layer_bounds.left(), -layer_bounds.top());
    }
}

=======
>>>>>>> miniblink49
//////////////////////////////////////////////////////////////////////////////
//  These are the virtual drawing methods
//////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void SkCanvas::onDiscard()
{
=======
void SkCanvas::onDiscard() {
>>>>>>> miniblink49
    if (fSurfaceBase) {
        fSurfaceBase->aboutToDraw(SkSurface::kDiscard_ContentChangeMode);
    }
}

<<<<<<< HEAD
void SkCanvas::onDrawPaint(const SkPaint& paint)
{
=======
void SkCanvas::onDrawPaint(const SkPaint& paint) {
>>>>>>> miniblink49
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawPaint()");
    this->internalDrawPaint(paint);
}

<<<<<<< HEAD
void SkCanvas::internalDrawPaint(const SkPaint& paint)
{
    LOOPER_BEGIN_CHECK_COMPLETE_OVERWRITE(paint, SkDrawFilter::kPaint_Type, nullptr, false)
=======
void SkCanvas::internalDrawPaint(const SkPaint& paint) {
    LOOPER_BEGIN(paint, SkDrawFilter::kPaint_Type, NULL)
>>>>>>> miniblink49

    while (iter.next()) {
        iter.fDevice->drawPaint(iter, looper.paint());
    }

    LOOPER_END
}

void SkCanvas::onDrawPoints(PointMode mode, size_t count, const SkPoint pts[],
<<<<<<< HEAD
    const SkPaint& paint)
{
=======
                            const SkPaint& paint) {
>>>>>>> miniblink49
    TRACE_EVENT1("disabled-by-default-skia", "SkCanvas::drawPoints()", "count", static_cast<uint64_t>(count));
    if ((long)count <= 0) {
        return;
    }

    SkRect r, storage;
<<<<<<< HEAD
    const SkRect* bounds = nullptr;
=======
    const SkRect* bounds = NULL;
>>>>>>> miniblink49
    if (paint.canComputeFastBounds()) {
        // special-case 2 points (common for drawing a single line)
        if (2 == count) {
            r.set(pts[0], pts[1]);
        } else {
            r.set(pts, SkToInt(count));
        }
<<<<<<< HEAD
        if (this->quickReject(paint.computeFastStrokeBounds(r, &storage))) {
            return;
        }
        bounds = &r;
    }

    SkASSERT(pts != nullptr);
=======
        bounds = &paint.computeFastStrokeBounds(r, &storage);
        if (this->quickReject(*bounds)) {
            return;
        }
    }

    SkASSERT(pts != NULL);
>>>>>>> miniblink49

    LOOPER_BEGIN(paint, SkDrawFilter::kPoint_Type, bounds)

    while (iter.next()) {
        iter.fDevice->drawPoints(iter, mode, count, pts, looper.paint());
    }

    LOOPER_END
}

<<<<<<< HEAD
void SkCanvas::onDrawRect(const SkRect& r, const SkPaint& paint)
{
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawRect()");
    SkRect storage;
    const SkRect* bounds = nullptr;
=======
void SkCanvas::onDrawRect(const SkRect& r, const SkPaint& paint) {
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawRect()");
    SkRect storage;
    const SkRect* bounds = NULL;
>>>>>>> miniblink49
    if (paint.canComputeFastBounds()) {
        // Skia will draw an inverted rect, because it explicitly "sorts" it downstream.
        // To prevent accidental rejecting at this stage, we have to sort it before we check.
        SkRect tmp(r);
        tmp.sort();

<<<<<<< HEAD
        if (this->quickReject(paint.computeFastBounds(tmp, &storage))) {
            return;
        }
        bounds = &r;
    }

    LOOPER_BEGIN_CHECK_COMPLETE_OVERWRITE(paint, SkDrawFilter::kRect_Type, bounds, false)
=======
        bounds = &paint.computeFastBounds(tmp, &storage);
        if (this->quickReject(*bounds)) {
            return;
        }
    }

    LOOPER_BEGIN(paint, SkDrawFilter::kRect_Type, bounds)
>>>>>>> miniblink49

    while (iter.next()) {
        iter.fDevice->drawRect(iter, r, looper.paint());
    }

    LOOPER_END
}

<<<<<<< HEAD
void SkCanvas::onDrawOval(const SkRect& oval, const SkPaint& paint)
{
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawOval()");
    SkRect storage;
    const SkRect* bounds = nullptr;
    if (paint.canComputeFastBounds()) {
        if (this->quickReject(paint.computeFastBounds(oval, &storage))) {
            return;
        }
        bounds = &oval;
=======
void SkCanvas::onDrawOval(const SkRect& oval, const SkPaint& paint) {
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawOval()");
    SkRect storage;
    const SkRect* bounds = NULL;
    if (paint.canComputeFastBounds()) {
        bounds = &paint.computeFastBounds(oval, &storage);
        if (this->quickReject(*bounds)) {
            return;
        }
>>>>>>> miniblink49
    }

    LOOPER_BEGIN(paint, SkDrawFilter::kOval_Type, bounds)

    while (iter.next()) {
        iter.fDevice->drawOval(iter, oval, looper.paint());
    }

    LOOPER_END
}

<<<<<<< HEAD
void SkCanvas::onDrawRRect(const SkRRect& rrect, const SkPaint& paint)
{
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawRRect()");
    SkRect storage;
    const SkRect* bounds = nullptr;
    if (paint.canComputeFastBounds()) {
        if (this->quickReject(paint.computeFastBounds(rrect.getBounds(), &storage))) {
            return;
        }
        bounds = &rrect.getBounds();
=======
void SkCanvas::onDrawRRect(const SkRRect& rrect, const SkPaint& paint) {
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawRRect()");
    SkRect storage;
    const SkRect* bounds = NULL;
    if (paint.canComputeFastBounds()) {
        bounds = &paint.computeFastBounds(rrect.getBounds(), &storage);
        if (this->quickReject(*bounds)) {
            return;
        }
>>>>>>> miniblink49
    }

    if (rrect.isRect()) {
        // call the non-virtual version
        this->SkCanvas::drawRect(rrect.getBounds(), paint);
        return;
    } else if (rrect.isOval()) {
        // call the non-virtual version
        this->SkCanvas::drawOval(rrect.getBounds(), paint);
        return;
    }

    LOOPER_BEGIN(paint, SkDrawFilter::kRRect_Type, bounds)

    while (iter.next()) {
        iter.fDevice->drawRRect(iter, rrect, looper.paint());
    }

    LOOPER_END
}

void SkCanvas::onDrawDRRect(const SkRRect& outer, const SkRRect& inner,
<<<<<<< HEAD
    const SkPaint& paint)
{
    SkRect storage;
    const SkRect* bounds = nullptr;
    if (paint.canComputeFastBounds()) {
        if (this->quickReject(paint.computeFastBounds(outer.getBounds(), &storage))) {
            return;
        }
        bounds = &outer.getBounds();
=======
                            const SkPaint& paint) {
    SkRect storage;
    const SkRect* bounds = NULL;
    if (paint.canComputeFastBounds()) {
        bounds = &paint.computeFastBounds(outer.getBounds(), &storage);
        if (this->quickReject(*bounds)) {
            return;
        }
>>>>>>> miniblink49
    }

    LOOPER_BEGIN(paint, SkDrawFilter::kRRect_Type, bounds)

    while (iter.next()) {
        iter.fDevice->drawDRRect(iter, outer, inner, looper.paint());
    }

    LOOPER_END
}

<<<<<<< HEAD
void SkCanvas::onDrawPath(const SkPath& path, const SkPaint& paint)
{
=======
void SkCanvas::onDrawPath(const SkPath& path, const SkPaint& paint) {
>>>>>>> miniblink49
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawPath()");
    if (!path.isFinite()) {
        return;
    }

    SkRect storage;
<<<<<<< HEAD
    const SkRect* bounds = nullptr;
    if (!path.isInverseFillType() && paint.canComputeFastBounds()) {
        const SkRect& pathBounds = path.getBounds();
        if (this->quickReject(paint.computeFastBounds(pathBounds, &storage))) {
            return;
        }
        bounds = &pathBounds;
=======
    const SkRect* bounds = NULL;
    if (!path.isInverseFillType() && paint.canComputeFastBounds()) {
        const SkRect& pathBounds = path.getBounds();
        bounds = &paint.computeFastBounds(pathBounds, &storage);
        if (this->quickReject(*bounds)) {
            return;
        }
>>>>>>> miniblink49
    }

    const SkRect& r = path.getBounds();
    if (r.width() <= 0 && r.height() <= 0) {
        if (path.isInverseFillType()) {
            this->internalDrawPaint(paint);
<<<<<<< HEAD
            return;
        }
=======
        }
        return;
>>>>>>> miniblink49
    }

    LOOPER_BEGIN(paint, SkDrawFilter::kPath_Type, bounds)

    while (iter.next()) {
        iter.fDevice->drawPath(iter, path, looper.paint());
    }

    LOOPER_END
}

<<<<<<< HEAD
bool SkCanvas::canDrawBitmapAsSprite(SkScalar x, SkScalar y, int w, int h, const SkPaint& paint)
{
    if (!paint.getImageFilter()) {
        return false;
    }

    const SkMatrix& ctm = this->getTotalMatrix();
    if (!SkTreatAsSprite(ctm, SkISize::Make(w, h), paint)) {
        return false;
    }

    // Currently we can only use the filterSprite code if we are clipped to the bitmap's bounds.
    // Once we can filter and the filter will return a result larger than itself, we should be
    // able to remove this constraint.
    // skbug.com/4526
    //
    SkPoint pt;
    ctm.mapXY(x, y, &pt);
    SkIRect ir = SkIRect::MakeXYWH(SkScalarRoundToInt(pt.x()), SkScalarRoundToInt(pt.y()), w, h);
    return ir.contains(fMCRec->fRasterClip.getBounds());
}

void SkCanvas::onDrawImage(const SkImage* image, SkScalar x, SkScalar y, const SkPaint* paint)
{
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawImage()");
    SkRect bounds = SkRect::MakeXYWH(x, y,
        SkIntToScalar(image->width()), SkIntToScalar(image->height()));
    if (nullptr == paint || paint->canComputeFastBounds()) {
        SkRect tmp = bounds;
        if (paint) {
            paint->computeFastBounds(tmp, &tmp);
        }
        if (this->quickReject(tmp)) {
            return;
        }
    }

    SkLazyPaint lazy;
    if (nullptr == paint) {
        paint = lazy.init();
    }

    bool drawAsSprite = this->canDrawBitmapAsSprite(x, y, image->width(), image->height(),
        *paint);
    if (drawAsSprite && paint->getImageFilter()) {
        SkBitmap bitmap;
        if (!as_IB(image)->asBitmapForImageFilters(&bitmap)) {
            drawAsSprite = false;
        } else {
            // Until imagefilters are updated, they cannot handle any src type but N32...
            if (bitmap.info().colorType() != kN32_SkColorType || bitmap.info().gammaCloseToSRGB()) {
                drawAsSprite = false;
            }
        }
    }

    LOOPER_BEGIN_DRAWBITMAP(*paint, drawAsSprite, &bounds)

    while (iter.next()) {
        const SkPaint& pnt = looper.paint();
        if (drawAsSprite && pnt.getImageFilter()) {
            SkBitmap bitmap;
            if (as_IB(image)->asBitmapForImageFilters(&bitmap)) {
                SkPoint pt;
                iter.fMatrix->mapXY(x, y, &pt);
                iter.fDevice->drawSpriteWithFilter(iter, bitmap,
                    SkScalarRoundToInt(pt.fX),
                    SkScalarRoundToInt(pt.fY), pnt);
            }
        } else {
            iter.fDevice->drawImage(iter, image, x, y, pnt);
        }
    }

=======
void SkCanvas::onDrawImage(const SkImage* image, SkScalar x, SkScalar y, const SkPaint* paint) {
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawImage()");
    SkRect bounds = SkRect::MakeXYWH(x, y,
                                     SkIntToScalar(image->width()), SkIntToScalar(image->height()));
    if (NULL == paint || paint->canComputeFastBounds()) {
        if (paint) {
            paint->computeFastBounds(bounds, &bounds);
        }
        if (this->quickReject(bounds)) {
            return;
        }
    }
    
    SkLazyPaint lazy;
    if (NULL == paint) {
        paint = lazy.init();
    }
    
    LOOPER_BEGIN(*paint, SkDrawFilter::kBitmap_Type, &bounds)
    
    while (iter.next()) {
        iter.fDevice->drawImage(iter, image, x, y, looper.paint());
    }
    
>>>>>>> miniblink49
    LOOPER_END
}

void SkCanvas::onDrawImageRect(const SkImage* image, const SkRect* src, const SkRect& dst,
<<<<<<< HEAD
    const SkPaint* paint, SrcRectConstraint constraint)
{
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawImageRect()");
    if (nullptr == paint || paint->canComputeFastBounds()) {
        SkRect storage = dst;
        if (paint) {
            paint->computeFastBounds(dst, &storage);
        }
        if (this->quickReject(storage)) {
=======
                               const SkPaint* paint) {
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawImageRect()");
    SkRect storage;
    const SkRect* bounds = &dst;
    if (NULL == paint || paint->canComputeFastBounds()) {
        if (paint) {
            bounds = &paint->computeFastBounds(dst, &storage);
        }
        if (this->quickReject(*bounds)) {
>>>>>>> miniblink49
            return;
        }
    }
    SkLazyPaint lazy;
<<<<<<< HEAD
    if (nullptr == paint) {
        paint = lazy.init();
    }

    LOOPER_BEGIN_CHECK_COMPLETE_OVERWRITE(*paint, SkDrawFilter::kBitmap_Type, &dst,
        image->isOpaque())

    while (iter.next()) {
        iter.fDevice->drawImageRect(iter, image, src, dst, looper.paint(), constraint);
    }

    LOOPER_END
}

void SkCanvas::onDrawBitmap(const SkBitmap& bitmap, SkScalar x, SkScalar y, const SkPaint* paint)
{
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawBitmap()");
    SkDEBUGCODE(bitmap.validate();)

        if (bitmap.drawsNothing())
    {
        return;
    }

    SkLazyPaint lazy;
    if (nullptr == paint) {
        paint = lazy.init();
    }

    const SkMatrix matrix = SkMatrix::MakeTrans(x, y);

    SkRect storage;
    const SkRect* bounds = nullptr;
    if (paint->canComputeFastBounds()) {
        bitmap.getBounds(&storage);
        matrix.mapRect(&storage);
        SkRect tmp = storage;
        if (this->quickReject(paint->computeFastBounds(tmp, &tmp))) {
            return;
        }
        bounds = &storage;
    }

    bool drawAsSprite = bounds && this->canDrawBitmapAsSprite(x, y, bitmap.width(), bitmap.height(), *paint);
    if (drawAsSprite && paint->getImageFilter()) {
        // Until imagefilters are updated, they cannot handle any src type but N32...
        if (bitmap.info().colorType() != kN32_SkColorType || bitmap.info().gammaCloseToSRGB()) {
            drawAsSprite = false;
        }
    }

    LOOPER_BEGIN_DRAWBITMAP(*paint, drawAsSprite, bounds)

    while (iter.next()) {
        const SkPaint& pnt = looper.paint();
        if (drawAsSprite && pnt.getImageFilter()) {
            SkPoint pt;
            iter.fMatrix->mapXY(x, y, &pt);
            iter.fDevice->drawSpriteWithFilter(iter, bitmap,
                SkScalarRoundToInt(pt.fX),
                SkScalarRoundToInt(pt.fY), pnt);
        } else {
            iter.fDevice->drawBitmap(iter, bitmap, matrix, looper.paint());
        }
    }

    LOOPER_END
=======
    if (NULL == paint) {
        paint = lazy.init();
    }
    
    LOOPER_BEGIN(*paint, SkDrawFilter::kBitmap_Type, bounds)
    
    while (iter.next()) {
        iter.fDevice->drawImageRect(iter, image, src, dst, looper.paint());
    }
    
    LOOPER_END
}

void SkCanvas::onDrawBitmap(const SkBitmap& bitmap, SkScalar x, SkScalar y, const SkPaint* paint) {
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawBitmap()");
    SkDEBUGCODE(bitmap.validate();)

    if (NULL == paint || paint->canComputeFastBounds()) {
        SkRect bounds = {
            x, y,
            x + SkIntToScalar(bitmap.width()),
            y + SkIntToScalar(bitmap.height())
        };
        if (paint) {
            (void)paint->computeFastBounds(bounds, &bounds);
        }
        if (this->quickReject(bounds)) {
            return;
        }
    }

    SkMatrix matrix;
    matrix.setTranslate(x, y);
    this->internalDrawBitmap(bitmap, matrix, paint);
>>>>>>> miniblink49
}

// this one is non-virtual, so it can be called safely by other canvas apis
void SkCanvas::internalDrawBitmapRect(const SkBitmap& bitmap, const SkRect* src,
<<<<<<< HEAD
    const SkRect& dst, const SkPaint* paint,
    SrcRectConstraint constraint)
{
=======
                                      const SkRect& dst, const SkPaint* paint,
                                      DrawBitmapRectFlags flags) {
>>>>>>> miniblink49
    if (bitmap.drawsNothing() || dst.isEmpty()) {
        return;
    }

<<<<<<< HEAD
    if (nullptr == paint || paint->canComputeFastBounds()) {
        SkRect storage;
        if (this->quickReject(paint ? paint->computeFastBounds(dst, &storage) : dst)) {
=======
    SkRect storage;
    const SkRect* bounds = &dst;
    if (NULL == paint || paint->canComputeFastBounds()) {
        if (paint) {
            bounds = &paint->computeFastBounds(dst, &storage);
        }
        if (this->quickReject(*bounds)) {
>>>>>>> miniblink49
            return;
        }
    }

    SkLazyPaint lazy;
<<<<<<< HEAD
    if (nullptr == paint) {
        paint = lazy.init();
    }

    LOOPER_BEGIN_CHECK_COMPLETE_OVERWRITE(*paint, SkDrawFilter::kBitmap_Type, &dst,
        bitmap.isOpaque())

    while (iter.next()) {
        iter.fDevice->drawBitmapRect(iter, bitmap, src, dst, looper.paint(), constraint);
=======
    if (NULL == paint) {
        paint = lazy.init();
    }

    LOOPER_BEGIN(*paint, SkDrawFilter::kBitmap_Type, bounds)

    while (iter.next()) {
        iter.fDevice->drawBitmapRect(iter, bitmap, src, dst, looper.paint(), flags);
>>>>>>> miniblink49
    }

    LOOPER_END
}

void SkCanvas::onDrawBitmapRect(const SkBitmap& bitmap, const SkRect* src, const SkRect& dst,
<<<<<<< HEAD
    const SkPaint* paint, SrcRectConstraint constraint)
{
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawBitmapRectToRect()");
    SkDEBUGCODE(bitmap.validate();) this->internalDrawBitmapRect(bitmap, src, dst, paint, constraint);
}

void SkCanvas::onDrawImageNine(const SkImage* image, const SkIRect& center, const SkRect& dst,
    const SkPaint* paint)
{
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawImageNine()");

    if (nullptr == paint || paint->canComputeFastBounds()) {
        SkRect storage;
        if (this->quickReject(paint ? paint->computeFastBounds(dst, &storage) : dst)) {
            return;
        }
    }

    SkLazyPaint lazy;
    if (nullptr == paint) {
        paint = lazy.init();
    }

    LOOPER_BEGIN(*paint, SkDrawFilter::kBitmap_Type, &dst)

    while (iter.next()) {
        iter.fDevice->drawImageNine(iter, image, center, dst, looper.paint());
    }

=======
                                const SkPaint* paint, DrawBitmapRectFlags flags) {
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawBitmapRectToRect()");
    SkDEBUGCODE(bitmap.validate();)
    this->internalDrawBitmapRect(bitmap, src, dst, paint, flags);
}

void SkCanvas::onDrawImageNine(const SkImage* image, const SkIRect& center, const SkRect& dst,
                               const SkPaint* paint) {
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawImageNine()");
    
    SkRect storage;
    const SkRect* bounds = &dst;
    if (NULL == paint || paint->canComputeFastBounds()) {
        if (paint) {
            bounds = &paint->computeFastBounds(dst, &storage);
        }
        if (this->quickReject(*bounds)) {
            return;
        }
    }
    
    SkLazyPaint lazy;
    if (NULL == paint) {
        paint = lazy.init();
    }
    
    LOOPER_BEGIN(*paint, SkDrawFilter::kBitmap_Type, bounds)
    
    while (iter.next()) {
        iter.fDevice->drawImageNine(iter, image, center, dst, looper.paint());
    }
    
>>>>>>> miniblink49
    LOOPER_END
}

void SkCanvas::onDrawBitmapNine(const SkBitmap& bitmap, const SkIRect& center, const SkRect& dst,
<<<<<<< HEAD
    const SkPaint* paint)
{
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawBitmapNine()");
    SkDEBUGCODE(bitmap.validate();)

        if (nullptr == paint || paint->canComputeFastBounds())
    {
        SkRect storage;
        if (this->quickReject(paint ? paint->computeFastBounds(dst, &storage) : dst)) {
            return;
        }
    }

    SkLazyPaint lazy;
    if (nullptr == paint) {
        paint = lazy.init();
    }

    LOOPER_BEGIN(*paint, SkDrawFilter::kBitmap_Type, &dst)

    while (iter.next()) {
        iter.fDevice->drawBitmapNine(iter, bitmap, center, dst, looper.paint());
    }

=======
                                const SkPaint* paint) {
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawBitmapNine()");
    SkDEBUGCODE(bitmap.validate();)

    SkRect storage;
    const SkRect* bounds = &dst;
    if (NULL == paint || paint->canComputeFastBounds()) {
        if (paint) {
            bounds = &paint->computeFastBounds(dst, &storage);
        }
        if (this->quickReject(*bounds)) {
            return;
        }
    }
    
    SkLazyPaint lazy;
    if (NULL == paint) {
        paint = lazy.init();
    }
    
    LOOPER_BEGIN(*paint, SkDrawFilter::kBitmap_Type, bounds)
    
    while (iter.next()) {
        iter.fDevice->drawBitmapNine(iter, bitmap, center, dst, looper.paint());
    }
    
>>>>>>> miniblink49
    LOOPER_END
}

class SkDeviceFilteredPaint {
public:
<<<<<<< HEAD
    SkDeviceFilteredPaint(SkBaseDevice* device, const SkPaint& paint)
    {
=======
    SkDeviceFilteredPaint(SkBaseDevice* device, const SkPaint& paint) {
>>>>>>> miniblink49
        uint32_t filteredFlags = device->filterTextFlags(paint);
        if (filteredFlags != paint.getFlags()) {
            SkPaint* newPaint = fLazy.set(paint);
            newPaint->setFlags(filteredFlags);
            fPaint = newPaint;
        } else {
            fPaint = &paint;
        }
    }

    const SkPaint& paint() const { return *fPaint; }

private:
<<<<<<< HEAD
    const SkPaint* fPaint;
    SkLazyPaint fLazy;
};

void SkCanvas::DrawRect(const SkDraw& draw, const SkPaint& paint,
    const SkRect& r, SkScalar textSize)
{
=======
    const SkPaint*  fPaint;
    SkLazyPaint     fLazy;
};

void SkCanvas::DrawRect(const SkDraw& draw, const SkPaint& paint,
                        const SkRect& r, SkScalar textSize) {
>>>>>>> miniblink49
    if (paint.getStyle() == SkPaint::kFill_Style) {
        draw.fDevice->drawRect(draw, r, paint);
    } else {
        SkPaint p(paint);
        p.setStrokeWidth(SkScalarMul(textSize, paint.getStrokeWidth()));
        draw.fDevice->drawRect(draw, r, p);
    }
}

void SkCanvas::DrawTextDecorations(const SkDraw& draw, const SkPaint& paint,
<<<<<<< HEAD
    const char text[], size_t byteLength,
    SkScalar x, SkScalar y)
{
    SkASSERT(byteLength == 0 || text != nullptr);

    // nothing to draw
    if (text == nullptr || byteLength == 0 || draw.fRC->isEmpty() || (paint.getAlpha() == 0 && paint.getXfermode() == nullptr)) {
        return;
    }

    SkScalar width = 0;
    SkPoint start;

    start.set(0, 0); // to avoid warning
    if (paint.getFlags() & (SkPaint::kUnderlineText_Flag | SkPaint::kStrikeThruText_Flag)) {
=======
                                   const char text[], size_t byteLength,
                                   SkScalar x, SkScalar y) {
    SkASSERT(byteLength == 0 || text != NULL);

    // nothing to draw
    if (text == NULL || byteLength == 0 ||
        draw.fClip->isEmpty() ||
        (paint.getAlpha() == 0 && paint.getXfermode() == NULL)) {
        return;
    }

    SkScalar    width = 0;
    SkPoint     start;

    start.set(0, 0);    // to avoid warning
    if (paint.getFlags() & (SkPaint::kUnderlineText_Flag |
                            SkPaint::kStrikeThruText_Flag)) {
>>>>>>> miniblink49
        width = paint.measureText(text, byteLength);

        SkScalar offsetX = 0;
        if (paint.getTextAlign() == SkPaint::kCenter_Align) {
            offsetX = SkScalarHalf(width);
        } else if (paint.getTextAlign() == SkPaint::kRight_Align) {
            offsetX = width;
        }
        start.set(x - offsetX, y);
    }

    if (0 == width) {
        return;
    }

    uint32_t flags = paint.getFlags();

<<<<<<< HEAD
    if (flags & (SkPaint::kUnderlineText_Flag | SkPaint::kStrikeThruText_Flag)) {
        SkScalar textSize = paint.getTextSize();
        SkScalar height = SkScalarMul(textSize, kStdUnderline_Thickness);
        SkRect r;
=======
    if (flags & (SkPaint::kUnderlineText_Flag |
                 SkPaint::kStrikeThruText_Flag)) {
        SkScalar textSize = paint.getTextSize();
        SkScalar height = SkScalarMul(textSize, kStdUnderline_Thickness);
        SkRect   r;
>>>>>>> miniblink49

        r.fLeft = start.fX;
        r.fRight = start.fX + width;

        if (flags & SkPaint::kUnderlineText_Flag) {
            SkScalar offset = SkScalarMulAdd(textSize, kStdUnderline_Offset,
<<<<<<< HEAD
                start.fY);
            r.fTop = offset;
            r.fBottom = offset + height;
            DrawRect(draw, paint, r, 1);
        }
        if (flags & SkPaint::kStrikeThruText_Flag) {
            SkScalar offset = SkScalarMulAdd(textSize, kStdStrikeThru_Offset,
                start.fY);
            r.fTop = offset;
            r.fBottom = offset + height;
            DrawRect(draw, paint, r, 1);
=======
                                             start.fY);
            r.fTop = offset;
            r.fBottom = offset + height;
            DrawRect(draw, paint, r, textSize);
        }
        if (flags & SkPaint::kStrikeThruText_Flag) {
            SkScalar offset = SkScalarMulAdd(textSize, kStdStrikeThru_Offset,
                                             start.fY);
            r.fTop = offset;
            r.fBottom = offset + height;
            DrawRect(draw, paint, r, textSize);
>>>>>>> miniblink49
        }
    }
}

void SkCanvas::onDrawText(const void* text, size_t byteLength, SkScalar x, SkScalar y,
<<<<<<< HEAD
    const SkPaint& paint)
{
    LOOPER_BEGIN(paint, SkDrawFilter::kText_Type, nullptr)
=======
                          const SkPaint& paint) {
    LOOPER_BEGIN(paint, SkDrawFilter::kText_Type, NULL)
>>>>>>> miniblink49

    while (iter.next()) {
        SkDeviceFilteredPaint dfp(iter.fDevice, looper.paint());
        iter.fDevice->drawText(iter, text, byteLength, x, y, dfp.paint());
        DrawTextDecorations(iter, dfp.paint(),
<<<<<<< HEAD
            static_cast<const char*>(text), byteLength, x, y);
=======
                            static_cast<const char*>(text), byteLength, x, y);
>>>>>>> miniblink49
    }

    LOOPER_END
}

void SkCanvas::onDrawPosText(const void* text, size_t byteLength, const SkPoint pos[],
<<<<<<< HEAD
    const SkPaint& paint)
{
    SkPoint textOffset = SkPoint::Make(0, 0);

    LOOPER_BEGIN(paint, SkDrawFilter::kText_Type, nullptr)
=======
                             const SkPaint& paint) {
    SkPoint textOffset = SkPoint::Make(0, 0);

    LOOPER_BEGIN(paint, SkDrawFilter::kText_Type, NULL)
>>>>>>> miniblink49

    while (iter.next()) {
        SkDeviceFilteredPaint dfp(iter.fDevice, looper.paint());
        iter.fDevice->drawPosText(iter, text, byteLength, &pos->fX, 2, textOffset,
<<<<<<< HEAD
            dfp.paint());
=======
                                  dfp.paint());
>>>>>>> miniblink49
    }

    LOOPER_END
}

void SkCanvas::onDrawPosTextH(const void* text, size_t byteLength, const SkScalar xpos[],
<<<<<<< HEAD
    SkScalar constY, const SkPaint& paint)
{

    SkPoint textOffset = SkPoint::Make(0, constY);

    LOOPER_BEGIN(paint, SkDrawFilter::kText_Type, nullptr)
=======
                              SkScalar constY, const SkPaint& paint) {

    SkPoint textOffset = SkPoint::Make(0, constY);

    LOOPER_BEGIN(paint, SkDrawFilter::kText_Type, NULL)
>>>>>>> miniblink49

    while (iter.next()) {
        SkDeviceFilteredPaint dfp(iter.fDevice, looper.paint());
        iter.fDevice->drawPosText(iter, text, byteLength, xpos, 1, textOffset,
<<<<<<< HEAD
            dfp.paint());
=======
                                  dfp.paint());
>>>>>>> miniblink49
    }

    LOOPER_END
}

void SkCanvas::onDrawTextOnPath(const void* text, size_t byteLength, const SkPath& path,
<<<<<<< HEAD
    const SkMatrix* matrix, const SkPaint& paint)
{
    LOOPER_BEGIN(paint, SkDrawFilter::kText_Type, nullptr)

    while (iter.next()) {
        iter.fDevice->drawTextOnPath(iter, text, byteLength, path,
            matrix, looper.paint());
=======
                                const SkMatrix* matrix, const SkPaint& paint) {
    LOOPER_BEGIN(paint, SkDrawFilter::kText_Type, NULL)

    while (iter.next()) {
        iter.fDevice->drawTextOnPath(iter, text, byteLength, path,
                                     matrix, looper.paint());
>>>>>>> miniblink49
    }

    LOOPER_END
}

void SkCanvas::onDrawTextBlob(const SkTextBlob* blob, SkScalar x, SkScalar y,
<<<<<<< HEAD
    const SkPaint& paint)
{

    SkRect storage;
    const SkRect* bounds = nullptr;
    if (paint.canComputeFastBounds()) {
        storage = blob->bounds().makeOffset(x, y);
        SkRect tmp;
        if (this->quickReject(paint.computeFastBounds(storage, &tmp))) {
            return;
        }
        bounds = &storage;
=======
                              const SkPaint& paint) {

    SkRect storage;
    const SkRect* bounds = NULL;
    if (paint.canComputeFastBounds()) {
        storage = blob->bounds().makeOffset(x, y);
        bounds = &paint.computeFastBounds(storage, &storage);

        if (this->quickReject(*bounds)) {
            return;
        }
>>>>>>> miniblink49
    }

    // We cannot filter in the looper as we normally do, because the paint is
    // incomplete at this point (text-related attributes are embedded within blob run paints).
    SkDrawFilter* drawFilter = fMCRec->fFilter;
<<<<<<< HEAD
    fMCRec->fFilter = nullptr;
=======
    fMCRec->fFilter = NULL;
>>>>>>> miniblink49

    LOOPER_BEGIN(paint, SkDrawFilter::kText_Type, bounds)

    while (iter.next()) {
        SkDeviceFilteredPaint dfp(iter.fDevice, looper.paint());
        iter.fDevice->drawTextBlob(iter, blob, x, y, dfp.paint(), drawFilter);
    }

    LOOPER_END

    fMCRec->fFilter = drawFilter;
}

// These will become non-virtual, so they always call the (virtual) onDraw... method
void SkCanvas::drawText(const void* text, size_t byteLength, SkScalar x, SkScalar y,
<<<<<<< HEAD
    const SkPaint& paint)
{
=======
                        const SkPaint& paint) {
>>>>>>> miniblink49
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawText()");
    this->onDrawText(text, byteLength, x, y, paint);
}
void SkCanvas::drawPosText(const void* text, size_t byteLength, const SkPoint pos[],
<<<<<<< HEAD
    const SkPaint& paint)
{
=======
                           const SkPaint& paint) {
>>>>>>> miniblink49
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawPosText()");
    this->onDrawPosText(text, byteLength, pos, paint);
}
void SkCanvas::drawPosTextH(const void* text, size_t byteLength, const SkScalar xpos[],
<<<<<<< HEAD
    SkScalar constY, const SkPaint& paint)
{
=======
                            SkScalar constY, const SkPaint& paint) {
>>>>>>> miniblink49
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawPosTextH()");
    this->onDrawPosTextH(text, byteLength, xpos, constY, paint);
}
void SkCanvas::drawTextOnPath(const void* text, size_t byteLength, const SkPath& path,
<<<<<<< HEAD
    const SkMatrix* matrix, const SkPaint& paint)
{
=======
                              const SkMatrix* matrix, const SkPaint& paint) {
>>>>>>> miniblink49
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawTextOnPath()");
    this->onDrawTextOnPath(text, byteLength, path, matrix, paint);
}
void SkCanvas::drawTextBlob(const SkTextBlob* blob, SkScalar x, SkScalar y,
<<<<<<< HEAD
    const SkPaint& paint)
{
    RETURN_ON_NULL(blob);
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawTextBlob()");
    this->onDrawTextBlob(blob, x, y, paint);
}

void SkCanvas::onDrawVertices(VertexMode vmode, int vertexCount,
    const SkPoint verts[], const SkPoint texs[],
    const SkColor colors[], SkXfermode* xmode,
    const uint16_t indices[], int indexCount,
    const SkPaint& paint)
{
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawVertices()");
    LOOPER_BEGIN(paint, SkDrawFilter::kPath_Type, nullptr)

    while (iter.next()) {
        iter.fDevice->drawVertices(iter, vmode, vertexCount, verts, texs,
            colors, xmode, indices, indexCount,
            looper.paint());
=======
                            const SkPaint& paint) {
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawTextBlob()");
    if (blob) {
        this->onDrawTextBlob(blob, x, y, paint);
    }
}

void SkCanvas::onDrawVertices(VertexMode vmode, int vertexCount,
                              const SkPoint verts[], const SkPoint texs[],
                              const SkColor colors[], SkXfermode* xmode,
                              const uint16_t indices[], int indexCount,
                              const SkPaint& paint) {
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawVertices()");
    LOOPER_BEGIN(paint, SkDrawFilter::kPath_Type, NULL)

    while (iter.next()) {
        iter.fDevice->drawVertices(iter, vmode, vertexCount, verts, texs,
                                   colors, xmode, indices, indexCount,
                                   looper.paint());
>>>>>>> miniblink49
    }

    LOOPER_END
}

void SkCanvas::drawPatch(const SkPoint cubics[12], const SkColor colors[4],
<<<<<<< HEAD
    const SkPoint texCoords[4], SkXfermode* xmode, const SkPaint& paint)
{
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawPatch()");
    if (nullptr == cubics) {
=======
                         const SkPoint texCoords[4], SkXfermode* xmode, const SkPaint& paint) {
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawPatch()");
    if (NULL == cubics) {
>>>>>>> miniblink49
        return;
    }

    // Since a patch is always within the convex hull of the control points, we discard it when its
    // bounding rectangle is completely outside the current clip.
    SkRect bounds;
    bounds.set(cubics, SkPatchUtils::kNumCtrlPts);
    if (this->quickReject(bounds)) {
        return;
    }

    this->onDrawPatch(cubics, colors, texCoords, xmode, paint);
}

void SkCanvas::onDrawPatch(const SkPoint cubics[12], const SkColor colors[4],
<<<<<<< HEAD
    const SkPoint texCoords[4], SkXfermode* xmode, const SkPaint& paint)
{

    LOOPER_BEGIN(paint, SkDrawFilter::kPath_Type, nullptr)
=======
                           const SkPoint texCoords[4], SkXfermode* xmode, const SkPaint& paint) {

    LOOPER_BEGIN(paint, SkDrawFilter::kPath_Type, NULL)
>>>>>>> miniblink49

    while (iter.next()) {
        iter.fDevice->drawPatch(iter, cubics, colors, texCoords, xmode, paint);
    }

    LOOPER_END
}

<<<<<<< HEAD
void SkCanvas::drawDrawable(SkDrawable* dr, SkScalar x, SkScalar y)
{
    RETURN_ON_NULL(dr);
    if (x || y) {
        SkMatrix matrix = SkMatrix::MakeTrans(x, y);
        this->onDrawDrawable(dr, &matrix);
    } else {
        this->onDrawDrawable(dr, nullptr);
    }
}

void SkCanvas::drawDrawable(SkDrawable* dr, const SkMatrix* matrix)
{
    RETURN_ON_NULL(dr);
    if (matrix && matrix->isIdentity()) {
        matrix = nullptr;
    }
    this->onDrawDrawable(dr, matrix);
}

void SkCanvas::onDrawDrawable(SkDrawable* dr, const SkMatrix* matrix)
{
=======
void SkCanvas::drawDrawable(SkDrawable* dr, SkScalar x, SkScalar y) {
    if (dr) {
        if (x || y) {
            SkMatrix matrix = SkMatrix::MakeTrans(x, y);
            this->onDrawDrawable(dr, &matrix);
        } else {
            this->onDrawDrawable(dr, NULL);
        }
    }
}

void SkCanvas::drawDrawable(SkDrawable* dr, const SkMatrix* matrix) {
    if (dr) {
        if (matrix && matrix->isIdentity()) {
            matrix = NULL;
        }
        this->onDrawDrawable(dr, matrix);
    }
}

void SkCanvas::onDrawDrawable(SkDrawable* dr, const SkMatrix* matrix) {
>>>>>>> miniblink49
    SkRect bounds = dr->getBounds();
    if (matrix) {
        matrix->mapRect(&bounds);
    }
    if (this->quickReject(bounds)) {
        return;
    }
    dr->draw(this, matrix);
}

void SkCanvas::onDrawAtlas(const SkImage* atlas, const SkRSXform xform[], const SkRect tex[],
<<<<<<< HEAD
    const SkColor colors[], int count, SkXfermode::Mode mode,
    const SkRect* cull, const SkPaint* paint)
{
=======
                           const SkColor colors[], int count, SkXfermode::Mode mode,
                           const SkRect* cull, const SkPaint* paint) {
>>>>>>> miniblink49
    if (cull && this->quickReject(*cull)) {
        return;
    }

    SkPaint pnt;
    if (paint) {
        pnt = *paint;
    }
<<<<<<< HEAD

    LOOPER_BEGIN(pnt, SkDrawFilter::kPath_Type, nullptr)
=======
    
    LOOPER_BEGIN(pnt, SkDrawFilter::kPath_Type, NULL)
>>>>>>> miniblink49
    while (iter.next()) {
        iter.fDevice->drawAtlas(iter, atlas, xform, tex, colors, count, mode, pnt);
    }
    LOOPER_END
}

<<<<<<< HEAD
void SkCanvas::onDrawAnnotation(const SkRect& rect, const char key[], SkData* value)
{
    SkASSERT(key);

    SkPaint paint;
    LOOPER_BEGIN(paint, SkDrawFilter::kRect_Type, nullptr)
    while (iter.next()) {
        iter.fDevice->drawAnnotation(iter, rect, key, value);
    }
    LOOPER_END
}

=======
>>>>>>> miniblink49
//////////////////////////////////////////////////////////////////////////////
// These methods are NOT virtual, and therefore must call back into virtual
// methods, rather than actually drawing themselves.
//////////////////////////////////////////////////////////////////////////////

void SkCanvas::drawARGB(U8CPU a, U8CPU r, U8CPU g, U8CPU b,
<<<<<<< HEAD
    SkXfermode::Mode mode)
{
=======
                        SkXfermode::Mode mode) {
>>>>>>> miniblink49
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawARGB()");
    SkPaint paint;

    paint.setARGB(a, r, g, b);
    if (SkXfermode::kSrcOver_Mode != mode) {
        paint.setXfermodeMode(mode);
    }
    this->drawPaint(paint);
}

<<<<<<< HEAD
void SkCanvas::drawColor(SkColor c, SkXfermode::Mode mode)
{
=======
void SkCanvas::drawColor(SkColor c, SkXfermode::Mode mode) {
>>>>>>> miniblink49
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawColor()");
    SkPaint paint;

    paint.setColor(c);
    if (SkXfermode::kSrcOver_Mode != mode) {
        paint.setXfermodeMode(mode);
    }
    this->drawPaint(paint);
}

<<<<<<< HEAD
void SkCanvas::drawPoint(SkScalar x, SkScalar y, const SkPaint& paint)
{
=======
void SkCanvas::drawPoint(SkScalar x, SkScalar y, const SkPaint& paint) {
>>>>>>> miniblink49
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawPoint(SkPaint)");
    SkPoint pt;

    pt.set(x, y);
    this->drawPoints(kPoints_PointMode, 1, &pt, paint);
}

<<<<<<< HEAD
void SkCanvas::drawPoint(SkScalar x, SkScalar y, SkColor color)
{
=======
void SkCanvas::drawPoint(SkScalar x, SkScalar y, SkColor color) {
>>>>>>> miniblink49
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawPoint(SkColor)");
    SkPoint pt;
    SkPaint paint;

    pt.set(x, y);
    paint.setColor(color);
    this->drawPoints(kPoints_PointMode, 1, &pt, paint);
}

void SkCanvas::drawLine(SkScalar x0, SkScalar y0, SkScalar x1, SkScalar y1,
<<<<<<< HEAD
    const SkPaint& paint)
{
=======
                        const SkPaint& paint) {
>>>>>>> miniblink49
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawLine()");
    SkPoint pts[2];

    pts[0].set(x0, y0);
    pts[1].set(x1, y1);
    this->drawPoints(kLines_PointMode, 2, pts, paint);
}

void SkCanvas::drawRectCoords(SkScalar left, SkScalar top,
<<<<<<< HEAD
    SkScalar right, SkScalar bottom,
    const SkPaint& paint)
{
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawRectCoords()");
    SkRect r;
=======
                              SkScalar right, SkScalar bottom,
                              const SkPaint& paint) {
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawRectCoords()");
    SkRect  r;
>>>>>>> miniblink49

    r.set(left, top, right, bottom);
    this->drawRect(r, paint);
}

void SkCanvas::drawCircle(SkScalar cx, SkScalar cy, SkScalar radius,
<<<<<<< HEAD
    const SkPaint& paint)
{
=======
                          const SkPaint& paint) {
>>>>>>> miniblink49
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawCircle()");
    if (radius < 0) {
        radius = 0;
    }

<<<<<<< HEAD
    SkRect r;
=======
    SkRect  r;
>>>>>>> miniblink49
    r.set(cx - radius, cy - radius, cx + radius, cy + radius);
    this->drawOval(r, paint);
}

void SkCanvas::drawRoundRect(const SkRect& r, SkScalar rx, SkScalar ry,
<<<<<<< HEAD
    const SkPaint& paint)
{
=======
                             const SkPaint& paint) {
>>>>>>> miniblink49
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawRoundRect()");
    if (rx > 0 && ry > 0) {
        if (paint.canComputeFastBounds()) {
            SkRect storage;
            if (this->quickReject(paint.computeFastBounds(r, &storage))) {
                return;
            }
        }
        SkRRect rrect;
        rrect.setRectXY(r, rx, ry);
        this->drawRRect(rrect, paint);
    } else {
        this->drawRect(r, paint);
    }
}

void SkCanvas::drawArc(const SkRect& oval, SkScalar startAngle,
<<<<<<< HEAD
    SkScalar sweepAngle, bool useCenter,
    const SkPaint& paint)
{
=======
                       SkScalar sweepAngle, bool useCenter,
                       const SkPaint& paint) {
>>>>>>> miniblink49
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawArc()");
    if (SkScalarAbs(sweepAngle) >= SkIntToScalar(360)) {
        this->drawOval(oval, paint);
    } else {
<<<<<<< HEAD
        SkPath path;
=======
        SkPath  path;
>>>>>>> miniblink49
        if (useCenter) {
            path.moveTo(oval.centerX(), oval.centerY());
        }
        path.arcTo(oval, startAngle, sweepAngle, !useCenter);
        if (useCenter) {
            path.close();
        }
        this->drawPath(path, paint);
    }
}

void SkCanvas::drawTextOnPathHV(const void* text, size_t byteLength,
<<<<<<< HEAD
    const SkPath& path, SkScalar hOffset,
    SkScalar vOffset, const SkPaint& paint)
{
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawTextOnPathHV()");
    SkMatrix matrix;
=======
                                const SkPath& path, SkScalar hOffset,
                                SkScalar vOffset, const SkPaint& paint) {
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawTextOnPathHV()");
    SkMatrix    matrix;
>>>>>>> miniblink49

    matrix.setTranslate(hOffset, vOffset);
    this->drawTextOnPath(text, byteLength, path, &matrix, paint);
}

///////////////////////////////////////////////////////////////////////////////

/**
 *  This constant is trying to balance the speed of ref'ing a subpicture into a parent picture,
 *  against the playback cost of recursing into the subpicture to get at its actual ops.
 *
 *  For now we pick a conservatively small value, though measurement (and other heuristics like
 *  the type of ops contained) may justify changing this value.
 */
<<<<<<< HEAD
#define kMaxPictureOpsToUnrollInsteadOfRef 1

void SkCanvas::drawPicture(const SkPicture* picture, const SkMatrix* matrix, const SkPaint* paint)
{
    RETURN_ON_NULL(picture);

    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawPicture()");
    if (matrix && matrix->isIdentity()) {
        matrix = nullptr;
    }
    if (picture->approximateOpCount() <= kMaxPictureOpsToUnrollInsteadOfRef) {
        SkAutoCanvasMatrixPaint acmp(this, matrix, paint, picture->cullRect());
        picture->playback(this);
    } else {
        this->onDrawPicture(picture, matrix, paint);
=======
#define kMaxPictureOpsToUnrollInsteadOfRef  1

void SkCanvas::drawPicture(const SkPicture* picture, const SkMatrix* matrix, const SkPaint* paint) {
    TRACE_EVENT0("disabled-by-default-skia", "SkCanvas::drawPicture()");
    if (picture) {
        if (matrix && matrix->isIdentity()) {
            matrix = NULL;
        }
        if (picture->approximateOpCount() <= kMaxPictureOpsToUnrollInsteadOfRef) {
            SkAutoCanvasMatrixPaint acmp(this, matrix, paint, picture->cullRect());
            picture->playback(this);
        } else {
            this->onDrawPicture(picture, matrix, paint);
        }
>>>>>>> miniblink49
    }
}

void SkCanvas::onDrawPicture(const SkPicture* picture, const SkMatrix* matrix,
<<<<<<< HEAD
    const SkPaint* paint)
{
    if (!paint || paint->canComputeFastBounds()) {
        SkRect bounds = picture->cullRect();
        if (paint) {
            paint->computeFastBounds(bounds, &bounds);
        }
        if (matrix) {
            matrix->mapRect(&bounds);
        }
        if (this->quickReject(bounds)) {
            return;
        }
    }

=======
                             const SkPaint* paint) {
>>>>>>> miniblink49
    SkBaseDevice* device = this->getTopDevice();
    if (device) {
        // Canvas has to first give the device the opportunity to render
        // the picture itself.
        if (device->EXPERIMENTAL_drawPicture(this, picture, matrix, paint)) {
            return; // the device has rendered the entire picture
        }
    }

    SkAutoCanvasMatrixPaint acmp(this, matrix, paint, picture->cullRect());
    picture->playback(this);
}

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
SkCanvas::LayerIter::LayerIter(SkCanvas* canvas, bool skipEmptyClips)
{
    static_assert(sizeof(fStorage) >= sizeof(SkDrawIter), "fStorage_too_small");
=======
SkCanvas::LayerIter::LayerIter(SkCanvas* canvas, bool skipEmptyClips) {
    SK_COMPILE_ASSERT(sizeof(fStorage) >= sizeof(SkDrawIter), fStorage_too_small);
>>>>>>> miniblink49

    SkASSERT(canvas);

    fImpl = new (fStorage) SkDrawIter(canvas, skipEmptyClips);
    fDone = !fImpl->next();
}

<<<<<<< HEAD
SkCanvas::LayerIter::~LayerIter()
{
    fImpl->~SkDrawIter();
}

void SkCanvas::LayerIter::next()
{
    fDone = !fImpl->next();
}

SkBaseDevice* SkCanvas::LayerIter::device() const
{
    return fImpl->getDevice();
}

const SkMatrix& SkCanvas::LayerIter::matrix() const
{
    return fImpl->getMatrix();
}

const SkPaint& SkCanvas::LayerIter::paint() const
{
    const SkPaint* paint = fImpl->getPaint();
    if (nullptr == paint) {
=======
SkCanvas::LayerIter::~LayerIter() {
    fImpl->~SkDrawIter();
}

void SkCanvas::LayerIter::next() {
    fDone = !fImpl->next();
}

SkBaseDevice* SkCanvas::LayerIter::device() const {
    return fImpl->getDevice();
}

const SkMatrix& SkCanvas::LayerIter::matrix() const {
    return fImpl->getMatrix();
}

const SkPaint& SkCanvas::LayerIter::paint() const {
    const SkPaint* paint = fImpl->getPaint();
    if (NULL == paint) {
>>>>>>> miniblink49
        paint = &fDefaultPaint;
    }
    return *paint;
}

<<<<<<< HEAD
const SkRasterClip& SkCanvas::LayerIter::clip() const { return fImpl->getClip(); }
=======
const SkRegion& SkCanvas::LayerIter::clip() const { return fImpl->getClip(); }
>>>>>>> miniblink49
int SkCanvas::LayerIter::x() const { return fImpl->getX(); }
int SkCanvas::LayerIter::y() const { return fImpl->getY(); }

///////////////////////////////////////////////////////////////////////////////

SkCanvasClipVisitor::~SkCanvasClipVisitor() { }

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
static bool supported_for_raster_canvas(const SkImageInfo& info)
{
    switch (info.alphaType()) {
    case kPremul_SkAlphaType:
    case kOpaque_SkAlphaType:
        break;
    default:
        return false;
    }

    switch (info.colorType()) {
    case kAlpha_8_SkColorType:
    case kRGB_565_SkColorType:
    case kN32_SkColorType:
        break;
    default:
        return false;
=======
static bool supported_for_raster_canvas(const SkImageInfo& info) {
    switch (info.alphaType()) {
        case kPremul_SkAlphaType:
        case kOpaque_SkAlphaType:
            break;
        default:
            return false;
    }

    switch (info.colorType()) {
        case kAlpha_8_SkColorType:
        case kRGB_565_SkColorType:
        case kN32_SkColorType:
            break;
        default:
            return false;
>>>>>>> miniblink49
    }

    return true;
}

<<<<<<< HEAD
SkCanvas* SkCanvas::NewRasterDirect(const SkImageInfo& info, void* pixels, size_t rowBytes)
{
    if (!supported_for_raster_canvas(info)) {
        return nullptr;
=======
SkCanvas* SkCanvas::NewRasterDirect(const SkImageInfo& info, void* pixels, size_t rowBytes) {
    if (!supported_for_raster_canvas(info)) {
        return NULL;
>>>>>>> miniblink49
    }

    SkBitmap bitmap;
    if (!bitmap.installPixels(info, pixels, rowBytes)) {
<<<<<<< HEAD
        return nullptr;
    }
    return new SkCanvas(bitmap);
=======
        return NULL;
    }
    return SkNEW_ARGS(SkCanvas, (bitmap));
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////

SkAutoCanvasMatrixPaint::SkAutoCanvasMatrixPaint(SkCanvas* canvas, const SkMatrix* matrix,
<<<<<<< HEAD
    const SkPaint* paint, const SkRect& bounds)
=======
                                                 const SkPaint* paint, const SkRect& bounds)
>>>>>>> miniblink49
    : fCanvas(canvas)
    , fSaveCount(canvas->getSaveCount())
{
    if (paint) {
        SkRect newBounds = bounds;
        if (matrix) {
            matrix->mapRect(&newBounds);
        }
        canvas->saveLayer(&newBounds, paint);
    } else if (matrix) {
        canvas->save();
    }

    if (matrix) {
        canvas->concat(*matrix);
    }
}

<<<<<<< HEAD
SkAutoCanvasMatrixPaint::~SkAutoCanvasMatrixPaint()
{
    fCanvas->restoreToCount(fSaveCount);
}

#ifdef SK_SUPPORT_LEGACY_NEW_SURFACE_API
SkSurface* SkCanvas::newSurface(const SkImageInfo& info, const SkSurfaceProps* props)
{
    return this->makeSurface(info, props).release();
}
#endif
=======
SkAutoCanvasMatrixPaint::~SkAutoCanvasMatrixPaint() {
    fCanvas->restoreToCount(fSaveCount);
}
>>>>>>> miniblink49
