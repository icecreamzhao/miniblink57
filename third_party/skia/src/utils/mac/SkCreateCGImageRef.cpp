<<<<<<< HEAD
=======

>>>>>>> miniblink49
/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
<<<<<<< HEAD

#include "SkTypes.h"
#if defined(SK_BUILD_FOR_MAC) || defined(SK_BUILD_FOR_IOS)

#include "SkBitmap.h"
#include "SkCGUtils.h"
#include "SkColorPriv.h"

static CGBitmapInfo ComputeCGAlphaInfo_RGBA(SkAlphaType at)
{
    CGBitmapInfo info = kCGBitmapByteOrder32Big;
    switch (at) {
    case kUnknown_SkAlphaType:
        break;
    case kOpaque_SkAlphaType:
        info |= kCGImageAlphaNoneSkipLast;
        break;
    case kPremul_SkAlphaType:
        info |= kCGImageAlphaPremultipliedLast;
        break;
    case kUnpremul_SkAlphaType:
        info |= kCGImageAlphaLast;
        break;
=======
#include "SkCGUtils.h"
#include "SkBitmap.h"
#include "SkColorPriv.h"

static CGBitmapInfo ComputeCGAlphaInfo_RGBA(SkAlphaType at) {
    CGBitmapInfo info = kCGBitmapByteOrder32Big;
    switch (at) {
        case kUnknown_SkAlphaType:
            break;
        case kOpaque_SkAlphaType:
            info |= kCGImageAlphaNoneSkipLast;
            break;
        case kPremul_SkAlphaType:
            info |= kCGImageAlphaPremultipliedLast;
            break;
        case kUnpremul_SkAlphaType:
            info |= kCGImageAlphaLast;
            break;
>>>>>>> miniblink49
    }
    return info;
}

<<<<<<< HEAD
static CGBitmapInfo ComputeCGAlphaInfo_BGRA(SkAlphaType at)
{
    CGBitmapInfo info = kCGBitmapByteOrder32Little;
    switch (at) {
    case kUnknown_SkAlphaType:
        break;
    case kOpaque_SkAlphaType:
        info |= kCGImageAlphaNoneSkipFirst;
        break;
    case kPremul_SkAlphaType:
        info |= kCGImageAlphaPremultipliedFirst;
        break;
    case kUnpremul_SkAlphaType:
        info |= kCGImageAlphaFirst;
        break;
=======
static CGBitmapInfo ComputeCGAlphaInfo_BGRA(SkAlphaType at) {
    CGBitmapInfo info = kCGBitmapByteOrder32Little;
    switch (at) {
        case kUnknown_SkAlphaType:
            break;
        case kOpaque_SkAlphaType:
            info |= kCGImageAlphaNoneSkipFirst;
            break;
        case kPremul_SkAlphaType:
            info |= kCGImageAlphaPremultipliedFirst;
            break;
        case kUnpremul_SkAlphaType:
            info |= kCGImageAlphaFirst;
            break;
>>>>>>> miniblink49
    }
    return info;
}

<<<<<<< HEAD
static void SkBitmap_ReleaseInfo(void* info, const void* pixelData, size_t size)
{
=======
static void SkBitmap_ReleaseInfo(void* info, const void* pixelData, size_t size) {
>>>>>>> miniblink49
    SkBitmap* bitmap = reinterpret_cast<SkBitmap*>(info);
    delete bitmap;
}

static bool getBitmapInfo(const SkBitmap& bm,
<<<<<<< HEAD
    size_t* bitsPerComponent,
    CGBitmapInfo* info,
    bool* upscaleTo32)
{
=======
                          size_t* bitsPerComponent,
                          CGBitmapInfo* info,
                          bool* upscaleTo32) {
>>>>>>> miniblink49
    if (upscaleTo32) {
        *upscaleTo32 = false;
    }

    switch (bm.colorType()) {
<<<<<<< HEAD
    case kRGB_565_SkColorType:
=======
        case kRGB_565_SkColorType:
>>>>>>> miniblink49
#if 0
            // doesn't see quite right. Are they thinking 1555?
            *bitsPerComponent = 5;
            *info = kCGBitmapByteOrder16Little | kCGImageAlphaNone;
#else
<<<<<<< HEAD
        if (upscaleTo32) {
            *upscaleTo32 = true;
        }
        // now treat like RGBA
        *bitsPerComponent = 8;
        *info = ComputeCGAlphaInfo_RGBA(kOpaque_SkAlphaType);
#endif
        break;
    case kRGBA_8888_SkColorType:
        *bitsPerComponent = 8;
        *info = ComputeCGAlphaInfo_RGBA(bm.alphaType());
        break;
    case kBGRA_8888_SkColorType:
        *bitsPerComponent = 8;
        *info = ComputeCGAlphaInfo_BGRA(bm.alphaType());
        break;
    case kARGB_4444_SkColorType:
        *bitsPerComponent = 4;
        *info = kCGBitmapByteOrder16Little;
        if (bm.isOpaque()) {
            *info |= kCGImageAlphaNoneSkipLast;
        } else {
            *info |= kCGImageAlphaPremultipliedLast;
        }
        break;
    default:
        return false;
=======
            if (upscaleTo32) {
                *upscaleTo32 = true;
            }
            // now treat like RGBA
            *bitsPerComponent = 8;
            *info = ComputeCGAlphaInfo_RGBA(kOpaque_SkAlphaType);
#endif
            break;
        case kRGBA_8888_SkColorType:
            *bitsPerComponent = 8;
            *info = ComputeCGAlphaInfo_RGBA(bm.alphaType());
            break;
        case kBGRA_8888_SkColorType:
            *bitsPerComponent = 8;
            *info = ComputeCGAlphaInfo_BGRA(bm.alphaType());
            break;
        case kARGB_4444_SkColorType:
            *bitsPerComponent = 4;
            *info = kCGBitmapByteOrder16Little;
            if (bm.isOpaque()) {
                *info |= kCGImageAlphaNoneSkipLast;
            } else {
                *info |= kCGImageAlphaPremultipliedLast;
            }
            break;
        default:
            return false;
>>>>>>> miniblink49
    }
    return true;
}

static SkBitmap* prepareForImageRef(const SkBitmap& bm,
<<<<<<< HEAD
    size_t* bitsPerComponent,
    CGBitmapInfo* info)
{
    bool upscaleTo32;
    if (!getBitmapInfo(bm, bitsPerComponent, info, &upscaleTo32)) {
        return nullptr;
=======
                                    size_t* bitsPerComponent,
                                    CGBitmapInfo* info) {
    bool upscaleTo32;
    if (!getBitmapInfo(bm, bitsPerComponent, info, &upscaleTo32)) {
        return NULL;
>>>>>>> miniblink49
    }

    SkBitmap* copy;
    if (upscaleTo32) {
        copy = new SkBitmap;
        // here we make a ceep copy of the pixels, since CG won't take our
        // 565 directly
        bm.copyTo(copy, kN32_SkColorType);
    } else {
        copy = new SkBitmap(bm);
    }
    return copy;
}

CGImageRef SkCreateCGImageRefWithColorspace(const SkBitmap& bm,
<<<<<<< HEAD
    CGColorSpaceRef colorSpace)
{
    size_t bitsPerComponent SK_INIT_TO_AVOID_WARNING;
    CGBitmapInfo info SK_INIT_TO_AVOID_WARNING;

    SkBitmap* bitmap = prepareForImageRef(bm, &bitsPerComponent, &info);
    if (nullptr == bitmap) {
        return nullptr;
=======
                                            CGColorSpaceRef colorSpace) {
    size_t bitsPerComponent SK_INIT_TO_AVOID_WARNING;
    CGBitmapInfo info       SK_INIT_TO_AVOID_WARNING;

    SkBitmap* bitmap = prepareForImageRef(bm, &bitsPerComponent, &info);
    if (NULL == bitmap) {
        return NULL;
>>>>>>> miniblink49
    }

    const int w = bitmap->width();
    const int h = bitmap->height();
    const size_t s = bitmap->getSize();

    // our provider "owns" the bitmap*, and will take care of deleting it
    // we initially lock it, so we can access the pixels. The bitmap will be deleted in the release
    // proc, which will in turn unlock the pixels
    bitmap->lockPixels();
    CGDataProviderRef dataRef = CGDataProviderCreateWithData(bitmap, bitmap->getPixels(), s,
<<<<<<< HEAD
        SkBitmap_ReleaseInfo);

    bool releaseColorSpace = false;
    if (nullptr == colorSpace) {
=======
                                                             SkBitmap_ReleaseInfo);

    bool releaseColorSpace = false;
    if (NULL == colorSpace) {
>>>>>>> miniblink49
        colorSpace = CGColorSpaceCreateDeviceRGB();
        releaseColorSpace = true;
    }

    CGImageRef ref = CGImageCreate(w, h, bitsPerComponent,
<<<<<<< HEAD
        bitmap->bytesPerPixel() * 8,
        bitmap->rowBytes(), colorSpace, info, dataRef,
        nullptr, false, kCGRenderingIntentDefault);
=======
                                   bitmap->bytesPerPixel() * 8,
                                   bitmap->rowBytes(), colorSpace, info, dataRef,
                                   NULL, false, kCGRenderingIntentDefault);
>>>>>>> miniblink49

    if (releaseColorSpace) {
        CGColorSpaceRelease(colorSpace);
    }
    CGDataProviderRelease(dataRef);
    return ref;
}

<<<<<<< HEAD
void SkCGDrawBitmap(CGContextRef cg, const SkBitmap& bm, float x, float y)
{
=======
void SkCGDrawBitmap(CGContextRef cg, const SkBitmap& bm, float x, float y) {
>>>>>>> miniblink49
    CGImageRef img = SkCreateCGImageRef(bm);

    if (img) {
        CGRect r = CGRectMake(0, 0, bm.width(), bm.height());

        CGContextSaveGState(cg);
        CGContextTranslateCTM(cg, x, r.size.height + y);
        CGContextScaleCTM(cg, 1, -1);

        CGContextDrawImage(cg, r, img);

        CGContextRestoreGState(cg);

        CGImageRelease(img);
    }
}

///////////////////////////////////////////////////////////////////////////////

#include "SkStream.h"

class SkAutoPDFRelease {
public:
<<<<<<< HEAD
    SkAutoPDFRelease(CGPDFDocumentRef doc)
        : fDoc(doc)
    {
    }
    ~SkAutoPDFRelease()
    {
=======
    SkAutoPDFRelease(CGPDFDocumentRef doc) : fDoc(doc) {}
    ~SkAutoPDFRelease() {
>>>>>>> miniblink49
        if (fDoc) {
            CGPDFDocumentRelease(fDoc);
        }
    }
<<<<<<< HEAD

=======
>>>>>>> miniblink49
private:
    CGPDFDocumentRef fDoc;
};
#define SkAutoPDFRelease(...) SK_REQUIRE_LOCAL_VAR(SkAutoPDFRelease)

<<<<<<< HEAD
bool SkPDFDocumentToBitmap(SkStream* stream, SkBitmap* output)
{
    CGDataProviderRef data = SkCreateDataProviderFromStream(stream);
    if (nullptr == data) {
=======
bool SkPDFDocumentToBitmap(SkStream* stream, SkBitmap* output) {
    CGDataProviderRef data = SkCreateDataProviderFromStream(stream);
    if (NULL == data) {
>>>>>>> miniblink49
        return false;
    }

    CGPDFDocumentRef pdf = CGPDFDocumentCreateWithProvider(data);
    CGDataProviderRelease(data);
<<<<<<< HEAD
    if (nullptr == pdf) {
=======
    if (NULL == pdf) {
>>>>>>> miniblink49
        return false;
    }
    SkAutoPDFRelease releaseMe(pdf);

    CGPDFPageRef page = CGPDFDocumentGetPage(pdf, 1);
<<<<<<< HEAD
    if (nullptr == page) {
=======
    if (NULL == page) {
>>>>>>> miniblink49
        return false;
    }

    CGRect bounds = CGPDFPageGetBoxRect(page, kCGPDFMediaBox);

    int w = (int)CGRectGetWidth(bounds);
    int h = (int)CGRectGetHeight(bounds);

    SkBitmap bitmap;
    if (!bitmap.tryAllocN32Pixels(w, h)) {
        return false;
    }
    bitmap.eraseColor(SK_ColorWHITE);

    size_t bitsPerComponent;
    CGBitmapInfo info;
<<<<<<< HEAD
    getBitmapInfo(bitmap, &bitsPerComponent, &info, nullptr);

    CGColorSpaceRef cs = CGColorSpaceCreateDeviceRGB();
    CGContextRef ctx = CGBitmapContextCreate(bitmap.getPixels(), w, h,
        bitsPerComponent, bitmap.rowBytes(),
        cs, info);
=======
    getBitmapInfo(bitmap, &bitsPerComponent, &info, NULL);

    CGColorSpaceRef cs = CGColorSpaceCreateDeviceRGB();
    CGContextRef ctx = CGBitmapContextCreate(bitmap.getPixels(), w, h,
                                             bitsPerComponent, bitmap.rowBytes(),
                                             cs, info);
>>>>>>> miniblink49
    CGColorSpaceRelease(cs);

    if (ctx) {
        CGContextDrawPDFPage(ctx, page);
        CGContextRelease(ctx);
    }

    output->swap(bitmap);
    return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////////

SK_API bool SkCopyPixelsFromCGImage(const SkImageInfo& info, size_t rowBytes, void* pixels,
<<<<<<< HEAD
    CGImageRef image)
{
    CGBitmapInfo cg_bitmap_info = 0;
    size_t bitsPerComponent = 0;
    switch (info.colorType()) {
    case kRGBA_8888_SkColorType:
        bitsPerComponent = 8;
        cg_bitmap_info = ComputeCGAlphaInfo_RGBA(info.alphaType());
        break;
    case kBGRA_8888_SkColorType:
        bitsPerComponent = 8;
        cg_bitmap_info = ComputeCGAlphaInfo_BGRA(info.alphaType());
        break;
    default:
        return false; // no other colortypes are supported (for now)
=======
                                    CGImageRef image) {
    CGBitmapInfo cg_bitmap_info = 0;
    size_t bitsPerComponent = 0;
    switch (info.colorType()) {
        case kRGBA_8888_SkColorType:
            bitsPerComponent = 8;
            cg_bitmap_info = ComputeCGAlphaInfo_RGBA(info.alphaType());
            break;
        case kBGRA_8888_SkColorType:
            bitsPerComponent = 8;
            cg_bitmap_info = ComputeCGAlphaInfo_BGRA(info.alphaType());
            break;
        default:
            return false;   // no other colortypes are supported (for now)
>>>>>>> miniblink49
    }

    CGColorSpaceRef cs = CGColorSpaceCreateDeviceRGB();
    CGContextRef cg = CGBitmapContextCreate(pixels, info.width(), info.height(), bitsPerComponent,
<<<<<<< HEAD
        rowBytes, cs, cg_bitmap_info);
    CFRelease(cs);
    if (nullptr == cg) {
=======
                                            rowBytes, cs, cg_bitmap_info);
    CFRelease(cs);
    if (NULL == cg) {
>>>>>>> miniblink49
        return false;
    }

    // use this blend mode, to avoid having to erase the pixels first, and to avoid CG performing
    // any blending (which could introduce errors and be slower).
    CGContextSetBlendMode(cg, kCGBlendModeCopy);

    CGContextDrawImage(cg, CGRectMake(0, 0, info.width(), info.height()), image);
    CGContextRelease(cg);
    return true;
}

<<<<<<< HEAD
bool SkCreateBitmapFromCGImage(SkBitmap* dst, CGImageRef image, SkISize* scaleToFit)
{
=======
bool SkCreateBitmapFromCGImage(SkBitmap* dst, CGImageRef image, SkISize* scaleToFit) {
>>>>>>> miniblink49
    const int width = scaleToFit ? scaleToFit->width() : SkToInt(CGImageGetWidth(image));
    const int height = scaleToFit ? scaleToFit->height() : SkToInt(CGImageGetHeight(image));
    SkImageInfo info = SkImageInfo::MakeN32Premul(width, height);

    SkBitmap tmp;
    if (!tmp.tryAllocPixels(info)) {
        return false;
    }

    if (!SkCopyPixelsFromCGImage(tmp.info(), tmp.rowBytes(), tmp.getPixels(), image)) {
        return false;
    }

    CGImageAlphaInfo cgInfo = CGImageGetAlphaInfo(image);
    switch (cgInfo) {
<<<<<<< HEAD
    case kCGImageAlphaNone:
    case kCGImageAlphaNoneSkipLast:
    case kCGImageAlphaNoneSkipFirst:
        SkASSERT(SkBitmap::ComputeIsOpaque(tmp));
        tmp.setAlphaType(kOpaque_SkAlphaType);
        break;
    default:
        // we don't know if we're opaque or not, so compute it.
        if (SkBitmap::ComputeIsOpaque(tmp)) {
            tmp.setAlphaType(kOpaque_SkAlphaType);
        }
=======
        case kCGImageAlphaNone:
        case kCGImageAlphaNoneSkipLast:
        case kCGImageAlphaNoneSkipFirst:
            SkASSERT(SkBitmap::ComputeIsOpaque(tmp));
            tmp.setAlphaType(kOpaque_SkAlphaType);
            break;
        default:
            // we don't know if we're opaque or not, so compute it.
            if (SkBitmap::ComputeIsOpaque(tmp)) {
                tmp.setAlphaType(kOpaque_SkAlphaType);
            }
>>>>>>> miniblink49
    }

    *dst = tmp;
    return true;
}
<<<<<<< HEAD

#endif //defined(SK_BUILD_FOR_MAC) || defined(SK_BUILD_FOR_IOS)
=======
>>>>>>> miniblink49
