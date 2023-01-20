/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkBitmapDevice.h"
#include "SkConfig8888.h"
#include "SkDraw.h"
<<<<<<< HEAD
#include "SkImageFilterCache.h"
#include "SkMallocPixelRef.h"
#include "SkMatrix.h"
#include "SkPaint.h"
#include "SkPath.h"
#include "SkPixelRef.h"
#include "SkPixmap.h"
#include "SkShader.h"
#include "SkSurface.h"
#include "SkXfermode.h"

class SkColorTable;

static bool valid_for_bitmap_device(const SkImageInfo& info,
    SkAlphaType* newAlphaType)
{
=======
#include "SkPixelRef.h"
#include "SkRasterClip.h"
#include "SkShader.h"
#include "SkSurface.h"

#define CHECK_FOR_ANNOTATION(paint) \
    do { if (paint.getAnnotation()) { return; } } while (0)

static bool valid_for_bitmap_device(const SkImageInfo& info,
                                    SkAlphaType* newAlphaType) {
>>>>>>> miniblink49
    if (info.width() < 0 || info.height() < 0) {
        return false;
    }

    // TODO: can we stop supporting kUnknown in SkBitmkapDevice?
    if (kUnknown_SkColorType == info.colorType()) {
        if (newAlphaType) {
            *newAlphaType = kUnknown_SkAlphaType;
        }
        return true;
    }

    switch (info.alphaType()) {
<<<<<<< HEAD
    case kPremul_SkAlphaType:
    case kOpaque_SkAlphaType:
        break;
    default:
        return false;
=======
        case kPremul_SkAlphaType:
        case kOpaque_SkAlphaType:
            break;
        default:
            return false;
>>>>>>> miniblink49
    }

    SkAlphaType canonicalAlphaType = info.alphaType();

    switch (info.colorType()) {
<<<<<<< HEAD
    case kAlpha_8_SkColorType:
        break;
    case kRGB_565_SkColorType:
        canonicalAlphaType = kOpaque_SkAlphaType;
        break;
    case kN32_SkColorType:
        break;
    case kRGBA_F16_SkColorType:
        break;
    default:
        return false;
=======
        case kAlpha_8_SkColorType:
            break;
        case kRGB_565_SkColorType:
            canonicalAlphaType = kOpaque_SkAlphaType;
            break;
		case kN32_SkColorType:
            break;
        default:
            return false;
>>>>>>> miniblink49
    }

    if (newAlphaType) {
        *newAlphaType = canonicalAlphaType;
    }
    return true;
}

SkBitmapDevice::SkBitmapDevice(const SkBitmap& bitmap)
    : INHERITED(SkSurfaceProps(SkSurfaceProps::kLegacyFontHost_InitType))
<<<<<<< HEAD
    , fBitmap(bitmap)
{
    SkASSERT(valid_for_bitmap_device(bitmap.info(), nullptr));
}

SkBitmapDevice* SkBitmapDevice::Create(const SkImageInfo& info)
{
=======
    , fBitmap(bitmap) {
    SkASSERT(valid_for_bitmap_device(bitmap.info(), NULL));
}

SkBitmapDevice* SkBitmapDevice::Create(const SkImageInfo& info) {
>>>>>>> miniblink49
    return Create(info, SkSurfaceProps(SkSurfaceProps::kLegacyFontHost_InitType));
}

SkBitmapDevice::SkBitmapDevice(const SkBitmap& bitmap, const SkSurfaceProps& surfaceProps)
    : INHERITED(surfaceProps)
<<<<<<< HEAD
    , fBitmap(bitmap)
{
    SkASSERT(valid_for_bitmap_device(bitmap.info(), nullptr));
}

SkBitmapDevice* SkBitmapDevice::Create(const SkImageInfo& origInfo,
    const SkSurfaceProps& surfaceProps)
{
    SkAlphaType newAT = origInfo.alphaType();
    if (!valid_for_bitmap_device(origInfo, &newAT)) {
        return nullptr;
=======
    , fBitmap(bitmap) {
    SkASSERT(valid_for_bitmap_device(bitmap.info(), NULL));
}

SkBitmapDevice* SkBitmapDevice::Create(const SkImageInfo& origInfo,
                                       const SkSurfaceProps& surfaceProps) {
    SkAlphaType newAT = origInfo.alphaType();
    if (!valid_for_bitmap_device(origInfo, &newAT)) {
        return NULL;
>>>>>>> miniblink49
    }

    const SkImageInfo info = origInfo.makeAlphaType(newAT);
    SkBitmap bitmap;

    if (kUnknown_SkColorType == info.colorType()) {
        if (!bitmap.setInfo(info)) {
<<<<<<< HEAD
            return nullptr;
        }
    } else if (info.isOpaque()) {
        // If this bitmap is opaque, we don't have any sensible default color,
        // so we just return uninitialized pixels.
        if (!bitmap.tryAllocPixels(info)) {
            return nullptr;
        }
    } else {
        // This bitmap has transparency, so we'll zero the pixels (to transparent).
        // We use a ZeroedPRFactory as a faster alloc-then-eraseColor(SK_ColorTRANSPARENT).
        SkMallocPixelRef::ZeroedPRFactory factory;
        if (!bitmap.tryAllocPixels(info, &factory, nullptr /*color table*/)) {
            return nullptr;
        }
    }

    return new SkBitmapDevice(bitmap, surfaceProps);
}

SkImageInfo SkBitmapDevice::imageInfo() const
{
    return fBitmap.info();
}

void SkBitmapDevice::setNewSize(const SkISize& size)
{
=======
            return NULL;
        }
    } else {
        if (!bitmap.tryAllocPixels(info)) {
            return NULL;
        }
        if (!bitmap.info().isOpaque()) {
            bitmap.eraseColor(SK_ColorTRANSPARENT);
        }
    }

    return SkNEW_ARGS(SkBitmapDevice, (bitmap, surfaceProps));
}

SkImageInfo SkBitmapDevice::imageInfo() const {
    return fBitmap.info();
}

void SkBitmapDevice::setNewSize(const SkISize& size) {
>>>>>>> miniblink49
    SkASSERT(!fBitmap.pixelRef());
    fBitmap.setInfo(fBitmap.info().makeWH(size.fWidth, size.fHeight));
}

<<<<<<< HEAD
void SkBitmapDevice::replaceBitmapBackendForRasterSurface(const SkBitmap& bm)
{
    SkASSERT(bm.width() == fBitmap.width());
    SkASSERT(bm.height() == fBitmap.height());
    fBitmap = bm; // intent is to use bm's pixelRef (and rowbytes/config)
    fBitmap.lockPixels();
}

SkBaseDevice* SkBitmapDevice::onCreateDevice(const CreateInfo& cinfo, const SkPaint*)
{
=======
void SkBitmapDevice::replaceBitmapBackendForRasterSurface(const SkBitmap& bm) {
    SkASSERT(bm.width() == fBitmap.width());
    SkASSERT(bm.height() == fBitmap.height());
    fBitmap = bm;   // intent is to use bm's pixelRef (and rowbytes/config)
    fBitmap.lockPixels();
}

SkBaseDevice* SkBitmapDevice::onCreateDevice(const CreateInfo& cinfo, const SkPaint*) {
>>>>>>> miniblink49
    const SkSurfaceProps surfaceProps(this->surfaceProps().flags(), cinfo.fPixelGeometry);
    return SkBitmapDevice::Create(cinfo.fInfo, surfaceProps);
}

<<<<<<< HEAD
const SkBitmap& SkBitmapDevice::onAccessBitmap()
{
    return fBitmap;
}

bool SkBitmapDevice::onAccessPixels(SkPixmap* pmap)
{
=======
const SkBitmap& SkBitmapDevice::onAccessBitmap() {
    return fBitmap;
}

bool SkBitmapDevice::onAccessPixels(SkPixmap* pmap) {
>>>>>>> miniblink49
    if (fBitmap.lockPixelsAreWritable() && this->onPeekPixels(pmap)) {
        fBitmap.notifyPixelsChanged();
        return true;
    }
    return false;
}

<<<<<<< HEAD
bool SkBitmapDevice::onPeekPixels(SkPixmap* pmap)
{
    const SkImageInfo info = fBitmap.info();
    if (fBitmap.getPixels() && (kUnknown_SkColorType != info.colorType())) {
        SkColorTable* ctable = nullptr;
=======
bool SkBitmapDevice::onPeekPixels(SkPixmap* pmap) {
    const SkImageInfo info = fBitmap.info();
    if (fBitmap.getPixels() && (kUnknown_SkColorType != info.colorType())) {
        SkColorTable* ctable = NULL;
>>>>>>> miniblink49
        pmap->reset(fBitmap.info(), fBitmap.getPixels(), fBitmap.rowBytes(), ctable);
        return true;
    }
    return false;
}

bool SkBitmapDevice::onWritePixels(const SkImageInfo& srcInfo, const void* srcPixels,
<<<<<<< HEAD
    size_t srcRowBytes, int x, int y)
{
    // since we don't stop creating un-pixeled devices yet, check for no pixels here
    if (nullptr == fBitmap.getPixels()) {
=======
                                   size_t srcRowBytes, int x, int y) {
    // since we don't stop creating un-pixeled devices yet, check for no pixels here
    if (NULL == fBitmap.getPixels()) {
>>>>>>> miniblink49
        return false;
    }

    const SkImageInfo dstInfo = fBitmap.info().makeWH(srcInfo.width(), srcInfo.height());

    void* dstPixels = fBitmap.getAddr(x, y);
    size_t dstRowBytes = fBitmap.rowBytes();

    if (SkPixelInfo::CopyPixels(dstInfo, dstPixels, dstRowBytes, srcInfo, srcPixels, srcRowBytes)) {
        fBitmap.notifyPixelsChanged();
        return true;
    }
    return false;
}

bool SkBitmapDevice::onReadPixels(const SkImageInfo& dstInfo, void* dstPixels, size_t dstRowBytes,
<<<<<<< HEAD
    int x, int y)
{
    return fBitmap.readPixels(dstInfo, dstPixels, dstRowBytes, x, y);
}

void SkBitmapDevice::onAttachToCanvas(SkCanvas* canvas)
{
=======
                                  int x, int y) {
    return fBitmap.readPixels(dstInfo, dstPixels, dstRowBytes, x, y);
}

void SkBitmapDevice::onAttachToCanvas(SkCanvas* canvas) {
>>>>>>> miniblink49
    INHERITED::onAttachToCanvas(canvas);
    if (fBitmap.lockPixelsAreWritable()) {
        fBitmap.lockPixels();
    }
}

<<<<<<< HEAD
void SkBitmapDevice::onDetachFromCanvas()
{
=======
void SkBitmapDevice::onDetachFromCanvas() {
>>>>>>> miniblink49
    INHERITED::onDetachFromCanvas();
    if (fBitmap.lockPixelsAreWritable()) {
        fBitmap.unlockPixels();
    }
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void SkBitmapDevice::drawPaint(const SkDraw& draw, const SkPaint& paint)
{
=======
void SkBitmapDevice::drawPaint(const SkDraw& draw, const SkPaint& paint) {
>>>>>>> miniblink49
    draw.drawPaint(paint);
}

void SkBitmapDevice::drawPoints(const SkDraw& draw, SkCanvas::PointMode mode, size_t count,
<<<<<<< HEAD
    const SkPoint pts[], const SkPaint& paint)
{
    draw.drawPoints(mode, count, pts, paint);
}

void SkBitmapDevice::drawRect(const SkDraw& draw, const SkRect& r, const SkPaint& paint)
{
    draw.drawRect(r, paint);
}

void SkBitmapDevice::drawOval(const SkDraw& draw, const SkRect& oval, const SkPaint& paint)
{
=======
                                const SkPoint pts[], const SkPaint& paint) {
    CHECK_FOR_ANNOTATION(paint);
    draw.drawPoints(mode, count, pts, paint);
}

void SkBitmapDevice::drawRect(const SkDraw& draw, const SkRect& r, const SkPaint& paint) {
    CHECK_FOR_ANNOTATION(paint);
    draw.drawRect(r, paint);
}

void SkBitmapDevice::drawOval(const SkDraw& draw, const SkRect& oval, const SkPaint& paint) {
    CHECK_FOR_ANNOTATION(paint);

>>>>>>> miniblink49
    SkPath path;
    path.addOval(oval);
    // call the VIRTUAL version, so any subclasses who do handle drawPath aren't
    // required to override drawOval.
<<<<<<< HEAD
    this->drawPath(draw, path, paint, nullptr, true);
}

void SkBitmapDevice::drawRRect(const SkDraw& draw, const SkRRect& rrect, const SkPaint& paint)
{
#ifdef SK_IGNORE_BLURRED_RRECT_OPT
    SkPath path;
=======
    this->drawPath(draw, path, paint, NULL, true);
}

void SkBitmapDevice::drawRRect(const SkDraw& draw, const SkRRect& rrect, const SkPaint& paint) {
    CHECK_FOR_ANNOTATION(paint);

#ifdef SK_IGNORE_BLURRED_RRECT_OPT
    SkPath  path;
>>>>>>> miniblink49

    path.addRRect(rrect);
    // call the VIRTUAL version, so any subclasses who do handle drawPath aren't
    // required to override drawRRect.
<<<<<<< HEAD
    this->drawPath(draw, path, paint, nullptr, true);
=======
    this->drawPath(draw, path, paint, NULL, true);
>>>>>>> miniblink49
#else
    draw.drawRRect(rrect, paint);
#endif
}

void SkBitmapDevice::drawPath(const SkDraw& draw, const SkPath& path,
<<<<<<< HEAD
    const SkPaint& paint, const SkMatrix* prePathMatrix,
    bool pathIsMutable)
{
=======
                              const SkPaint& paint, const SkMatrix* prePathMatrix,
                              bool pathIsMutable) {
    CHECK_FOR_ANNOTATION(paint);
>>>>>>> miniblink49
    draw.drawPath(path, paint, prePathMatrix, pathIsMutable);
}

void SkBitmapDevice::drawBitmap(const SkDraw& draw, const SkBitmap& bitmap,
<<<<<<< HEAD
    const SkMatrix& matrix, const SkPaint& paint)
{
    LogDrawScaleFactor(SkMatrix::Concat(*draw.fMatrix, matrix), paint.getFilterQuality());
    draw.drawBitmap(bitmap, matrix, nullptr, paint);
}

void SkBitmapDevice::drawBitmapRect(const SkDraw& draw, const SkBitmap& bitmap,
    const SkRect* src, const SkRect& dst,
    const SkPaint& paint, SkCanvas::SrcRectConstraint constraint)
{
    SkMatrix matrix;
    SkRect bitmapBounds, tmpSrc, tmpDst;
    SkBitmap tmpBitmap;
=======
                                const SkMatrix& matrix, const SkPaint& paint) {
    draw.drawBitmap(bitmap, matrix, NULL, paint);
}

void SkBitmapDevice::drawBitmapRect(const SkDraw& draw, const SkBitmap& bitmap,
                                    const SkRect* src, const SkRect& dst,
                                    const SkPaint& paint,
                                    SkCanvas::DrawBitmapRectFlags flags) {
    SkMatrix    matrix;
    SkRect      bitmapBounds, tmpSrc, tmpDst;
    SkBitmap    tmpBitmap;
>>>>>>> miniblink49

    bitmapBounds.isetWH(bitmap.width(), bitmap.height());

    // Compute matrix from the two rectangles
    if (src) {
        tmpSrc = *src;
    } else {
        tmpSrc = bitmapBounds;
    }
    matrix.setRectToRect(tmpSrc, dst, SkMatrix::kFill_ScaleToFit);

<<<<<<< HEAD
    LogDrawScaleFactor(SkMatrix::Concat(*draw.fMatrix, matrix), paint.getFilterQuality());

=======
>>>>>>> miniblink49
    const SkRect* dstPtr = &dst;
    const SkBitmap* bitmapPtr = &bitmap;

    // clip the tmpSrc to the bounds of the bitmap, and recompute dstRect if
    // needed (if the src was clipped). No check needed if src==null.
    if (src) {
        if (!bitmapBounds.contains(*src)) {
            if (!tmpSrc.intersect(bitmapBounds)) {
                return; // nothing to draw
            }
            // recompute dst, based on the smaller tmpSrc
            matrix.mapRect(&tmpDst, tmpSrc);
            dstPtr = &tmpDst;
        }

        // since we may need to clamp to the borders of the src rect within
        // the bitmap, we extract a subset.
        const SkIRect srcIR = tmpSrc.roundOut();
<<<<<<< HEAD
        if (bitmap.pixelRef()->getTexture()) {
            // Accelerated source canvas, don't use extractSubset but readPixels to get the subset.
            // This way, the pixels are copied in CPU memory instead of GPU memory.
            bitmap.pixelRef()->readPixels(&tmpBitmap, kN32_SkColorType, &srcIR);
=======
        if(bitmap.pixelRef()->getTexture()) {
            // Accelerated source canvas, don't use extractSubset but readPixels to get the subset.
            // This way, the pixels are copied in CPU memory instead of GPU memory.
            bitmap.pixelRef()->readPixels(&tmpBitmap, &srcIR);
>>>>>>> miniblink49
        } else {
            if (!bitmap.extractSubset(&tmpBitmap, srcIR)) {
                return;
            }
        }
        bitmapPtr = &tmpBitmap;

        // Since we did an extract, we need to adjust the matrix accordingly
        SkScalar dx = 0, dy = 0;
        if (srcIR.fLeft > 0) {
            dx = SkIntToScalar(srcIR.fLeft);
        }
        if (srcIR.fTop > 0) {
            dy = SkIntToScalar(srcIR.fTop);
        }
        if (dx || dy) {
            matrix.preTranslate(dx, dy);
        }

        SkRect extractedBitmapBounds;
        extractedBitmapBounds.isetWH(bitmapPtr->width(), bitmapPtr->height());
        if (extractedBitmapBounds == tmpSrc) {
            // no fractional part in src, we can just call drawBitmap
            goto USE_DRAWBITMAP;
        }
    } else {
<<<<<<< HEAD
    USE_DRAWBITMAP:
=======
        USE_DRAWBITMAP:
>>>>>>> miniblink49
        // We can go faster by just calling drawBitmap, which will concat the
        // matrix with the CTM, and try to call drawSprite if it can. If not,
        // it will make a shader and call drawRect, as we do below.
        draw.drawBitmap(*bitmapPtr, matrix, dstPtr, paint);
        return;
    }

    // construct a shader, so we can call drawRect with the dst
<<<<<<< HEAD
    auto s = SkShader::MakeBitmapShader(*bitmapPtr, SkShader::kClamp_TileMode,
        SkShader::kClamp_TileMode, &matrix);
    if (!s) {
=======
    SkShader* s = SkShader::CreateBitmapShader(*bitmapPtr,
                                               SkShader::kClamp_TileMode,
                                               SkShader::kClamp_TileMode,
                                               &matrix);
    if (NULL == s) {
>>>>>>> miniblink49
        return;
    }

    SkPaint paintWithShader(paint);
    paintWithShader.setStyle(SkPaint::kFill_Style);
<<<<<<< HEAD
    paintWithShader.setShader(std::move(s));
=======
    paintWithShader.setShader(s)->unref();
>>>>>>> miniblink49

    // Call ourself, in case the subclass wanted to share this setup code
    // but handle the drawRect code themselves.
    this->drawRect(draw, *dstPtr, paintWithShader);
}

void SkBitmapDevice::drawSprite(const SkDraw& draw, const SkBitmap& bitmap,
<<<<<<< HEAD
    int x, int y, const SkPaint& paint)
{
=======
                                int x, int y, const SkPaint& paint) {
>>>>>>> miniblink49
    draw.drawSprite(bitmap, x, y, paint);
}

void SkBitmapDevice::drawText(const SkDraw& draw, const void* text, size_t len,
<<<<<<< HEAD
    SkScalar x, SkScalar y, const SkPaint& paint)
{
=======
                              SkScalar x, SkScalar y, const SkPaint& paint) {
>>>>>>> miniblink49
    draw.drawText((const char*)text, len, x, y, paint);
}

void SkBitmapDevice::drawPosText(const SkDraw& draw, const void* text, size_t len,
<<<<<<< HEAD
    const SkScalar xpos[], int scalarsPerPos,
    const SkPoint& offset, const SkPaint& paint)
{
=======
                                 const SkScalar xpos[], int scalarsPerPos,
                                 const SkPoint& offset, const SkPaint& paint) {
>>>>>>> miniblink49
    draw.drawPosText((const char*)text, len, xpos, scalarsPerPos, offset, paint);
}

void SkBitmapDevice::drawVertices(const SkDraw& draw, SkCanvas::VertexMode vmode,
<<<<<<< HEAD
    int vertexCount,
    const SkPoint verts[], const SkPoint textures[],
    const SkColor colors[], SkXfermode* xmode,
    const uint16_t indices[], int indexCount,
    const SkPaint& paint)
{
    draw.drawVertices(vmode, vertexCount, verts, textures, colors, xmode,
        indices, indexCount, paint);
}

void SkBitmapDevice::drawDevice(const SkDraw& draw, SkBaseDevice* device,
    int x, int y, const SkPaint& paint)
{
    draw.drawSprite(static_cast<SkBitmapDevice*>(device)->fBitmap, x, y, paint);
}

sk_sp<SkSurface> SkBitmapDevice::makeSurface(const SkImageInfo& info, const SkSurfaceProps& props)
{
    return SkSurface::MakeRaster(info, &props);
}

SkImageFilterCache* SkBitmapDevice::getImageFilterCache()
{
    SkImageFilterCache* cache = SkImageFilterCache::Get();
=======
                                  int vertexCount,
                                  const SkPoint verts[], const SkPoint textures[],
                                  const SkColor colors[], SkXfermode* xmode,
                                  const uint16_t indices[], int indexCount,
                                  const SkPaint& paint) {
    draw.drawVertices(vmode, vertexCount, verts, textures, colors, xmode,
                      indices, indexCount, paint);
}

void SkBitmapDevice::drawDevice(const SkDraw& draw, SkBaseDevice* device,
                                int x, int y, const SkPaint& paint) {
    draw.drawSprite(static_cast<SkBitmapDevice*>(device)->fBitmap, x, y, paint);
}

SkSurface* SkBitmapDevice::newSurface(const SkImageInfo& info, const SkSurfaceProps& props) {
    return SkSurface::NewRaster(info, &props);
}

SkImageFilter::Cache* SkBitmapDevice::getImageFilterCache() {
    SkImageFilter::Cache* cache = SkImageFilter::Cache::Get();
>>>>>>> miniblink49
    cache->ref();
    return cache;
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
bool SkBitmapDevice::onShouldDisableLCD(const SkPaint& paint) const
{
    if (kN32_SkColorType != fBitmap.colorType() || paint.getRasterizer() || paint.getPathEffect() || paint.isFakeBoldText() || paint.getStyle() != SkPaint::kFill_Style || !SkXfermode::IsMode(paint.getXfermode(), SkXfermode::kSrcOver_Mode)) {
=======
bool SkBitmapDevice::onShouldDisableLCD(const SkPaint& paint) const {
    if (kN32_SkColorType != fBitmap.colorType() ||
        paint.getRasterizer() ||
        paint.getPathEffect() ||
        paint.isFakeBoldText() ||
        paint.getStyle() != SkPaint::kFill_Style ||
        !SkXfermode::IsMode(paint.getXfermode(), SkXfermode::kSrcOver_Mode))
    {
>>>>>>> miniblink49
        return true;
    }
    return false;
}
