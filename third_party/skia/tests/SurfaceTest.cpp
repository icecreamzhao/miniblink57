/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkCanvas.h"
#include "SkData.h"
#include "SkDevice.h"
<<<<<<< HEAD
#include "SkImage_Base.h"
#include "SkPath.h"
=======
#include "SkImageEncoder.h"
#include "SkImage_Base.h"
>>>>>>> miniblink49
#include "SkRRect.h"
#include "SkSurface.h"
#include "SkUtils.h"
#include "Test.h"
<<<<<<< HEAD
#include <functional>

#if SK_SUPPORT_GPU
#include "GrContext.h"
#include "GrDrawContext.h"
#include "GrGpu.h"
#include "GrResourceProvider.h"
#endif

#include <initializer_list>

static void release_direct_surface_storage(void* pixels, void* context)
{
    SkASSERT(pixels == context);
    sk_free(pixels);
}
static sk_sp<SkSurface> create_surface(SkAlphaType at = kPremul_SkAlphaType,
    SkImageInfo* requestedInfo = nullptr)
{
    const SkImageInfo info = SkImageInfo::MakeN32(10, 10, at);
    if (requestedInfo) {
        *requestedInfo = info;
    }
    return SkSurface::MakeRaster(info);
}
static sk_sp<SkSurface> create_direct_surface(SkAlphaType at = kPremul_SkAlphaType,
    SkImageInfo* requestedInfo = nullptr)
{
    const SkImageInfo info = SkImageInfo::MakeN32(10, 10, at);
    if (requestedInfo) {
        *requestedInfo = info;
    }
    const size_t rowBytes = info.minRowBytes();
    void* storage = sk_malloc_throw(info.getSafeSize(rowBytes));
    return SkSurface::MakeRasterDirectReleaseProc(info, storage, rowBytes,
        release_direct_surface_storage,
        storage);
}
#if SK_SUPPORT_GPU
static sk_sp<SkSurface> create_gpu_surface(GrContext* context, SkAlphaType at = kPremul_SkAlphaType,
    SkImageInfo* requestedInfo = nullptr)
{
    const SkImageInfo info = SkImageInfo::MakeN32(10, 10, at);
    if (requestedInfo) {
        *requestedInfo = info;
    }
    return SkSurface::MakeRenderTarget(context, SkBudgeted::kNo, info, 0, nullptr);
}
static sk_sp<SkSurface> create_gpu_scratch_surface(GrContext* context,
    SkAlphaType at = kPremul_SkAlphaType,
    SkImageInfo* requestedInfo = nullptr)
{
    const SkImageInfo info = SkImageInfo::MakeN32(10, 10, at);
    if (requestedInfo) {
        *requestedInfo = info;
    }
    return SkSurface::MakeRenderTarget(context, SkBudgeted::kYes, info, 0, nullptr);
}
#endif

DEF_TEST(SurfaceEmpty, reporter)
{
    const SkImageInfo info = SkImageInfo::Make(0, 0, kN32_SkColorType, kPremul_SkAlphaType);
    REPORTER_ASSERT(reporter, nullptr == SkSurface::MakeRaster(info));
    REPORTER_ASSERT(reporter, nullptr == SkSurface::MakeRasterDirect(info, nullptr, 0));
}
#if SK_SUPPORT_GPU
DEF_GPUTEST_FOR_RENDERING_CONTEXTS(SurfaceEmpty_Gpu, reporter, ctxInfo)
{
    const SkImageInfo info = SkImageInfo::Make(0, 0, kN32_SkColorType, kPremul_SkAlphaType);
    REPORTER_ASSERT(reporter, nullptr == SkSurface::MakeRenderTarget(ctxInfo.grContext(), SkBudgeted::kNo, info, 0, nullptr));
}
#endif

static void test_canvas_peek(skiatest::Reporter* reporter,
    sk_sp<SkSurface>& surface,
    const SkImageInfo& requestInfo,
    bool expectPeekSuccess)
{
    const SkColor color = SK_ColorRED;
    const SkPMColor pmcolor = SkPreMultiplyColor(color);
    surface->getCanvas()->clear(color);

    SkPixmap pmap;
    bool success = surface->getCanvas()->peekPixels(&pmap);
    REPORTER_ASSERT(reporter, expectPeekSuccess == success);

    SkPixmap pmap2;
    const void* addr2 = surface->peekPixels(&pmap2) ? pmap2.addr() : nullptr;

    if (success) {
        REPORTER_ASSERT(reporter, requestInfo == pmap.info());
        REPORTER_ASSERT(reporter, requestInfo.minRowBytes() <= pmap.rowBytes());
        REPORTER_ASSERT(reporter, pmcolor == *pmap.addr32());

        REPORTER_ASSERT(reporter, pmap.addr() == pmap2.addr());
        REPORTER_ASSERT(reporter, pmap.info() == pmap2.info());
        REPORTER_ASSERT(reporter, pmap.rowBytes() == pmap2.rowBytes());
    } else {
        REPORTER_ASSERT(reporter, nullptr == addr2);
    }
}
DEF_TEST(SurfaceCanvasPeek, reporter)
{
    for (auto& surface_func : { &create_surface, &create_direct_surface }) {
        SkImageInfo requestInfo;
        auto surface(surface_func(kPremul_SkAlphaType, &requestInfo));
        test_canvas_peek(reporter, surface, requestInfo, true);
    }
}
#if SK_SUPPORT_GPU
DEF_GPUTEST_FOR_RENDERING_CONTEXTS(SurfaceCanvasPeek_Gpu, reporter, ctxInfo)
{
    for (auto& surface_func : { &create_gpu_surface, &create_gpu_scratch_surface }) {
        SkImageInfo requestInfo;
        auto surface(surface_func(ctxInfo.grContext(), kPremul_SkAlphaType, &requestInfo));
        test_canvas_peek(reporter, surface, requestInfo, false);
    }
}
#endif
=======

#if SK_SUPPORT_GPU
#include "GrContextFactory.h"
#include "GrTest.h"
#include "gl/GrGLInterface.h"
#include "gl/GrGLUtil.h"
#else
class GrContextFactory;
class GrContext;
#endif

enum SurfaceType {
    kRaster_SurfaceType,
    kRasterDirect_SurfaceType,
    kGpu_SurfaceType,
    kGpuScratch_SurfaceType,

    kLastSurfaceType = kGpuScratch_SurfaceType
};
static const int kSurfaceTypeCnt = kLastSurfaceType + 1;

static void release_storage(void* pixels, void* context) {
    SkASSERT(pixels == context);
    sk_free(pixels);
}

static SkSurface* create_surface(SurfaceType surfaceType, GrContext* context,
                                 SkAlphaType at = kPremul_SkAlphaType,
                                 SkImageInfo* requestedInfo = NULL) {
    const SkImageInfo info = SkImageInfo::MakeN32(10, 10, at);

    if (requestedInfo) {
        *requestedInfo = info;
    }

    switch (surfaceType) {
        case kRaster_SurfaceType:
            return SkSurface::NewRaster(info);
        case kRasterDirect_SurfaceType: {
            const size_t rowBytes = info.minRowBytes();
            void* storage = sk_malloc_throw(info.getSafeSize(rowBytes));
            return SkSurface::NewRasterDirectReleaseProc(info, storage, rowBytes,
                                                         release_storage, storage);
        }
        case kGpu_SurfaceType:
            return SkSurface::NewRenderTarget(context, SkSurface::kNo_Budgeted, info, 0, NULL);
        case kGpuScratch_SurfaceType:
            return SkSurface::NewRenderTarget(context, SkSurface::kYes_Budgeted, info, 0, NULL);
    }
    return NULL;
}

enum ImageType {
    kRasterCopy_ImageType,
    kRasterData_ImageType,
    kRasterProc_ImageType,
    kGpu_ImageType,
    kCodec_ImageType,
};

#include "SkImageGenerator.h"

class EmptyGenerator : public SkImageGenerator {
public:
    EmptyGenerator() : SkImageGenerator(SkImageInfo::MakeN32Premul(0, 0)) {}
};

static void test_empty_image(skiatest::Reporter* reporter) {
    const SkImageInfo info = SkImageInfo::Make(0, 0, kN32_SkColorType, kPremul_SkAlphaType);
    
    REPORTER_ASSERT(reporter, NULL == SkImage::NewRasterCopy(info, NULL, 0));
    REPORTER_ASSERT(reporter, NULL == SkImage::NewRasterData(info, NULL, 0));
    REPORTER_ASSERT(reporter, NULL == SkImage::NewFromRaster(info, NULL, 0, NULL, NULL));
    REPORTER_ASSERT(reporter, NULL == SkImage::NewFromGenerator(SkNEW(EmptyGenerator)));
}

static void test_empty_surface(skiatest::Reporter* reporter, GrContext* ctx) {
    const SkImageInfo info = SkImageInfo::Make(0, 0, kN32_SkColorType, kPremul_SkAlphaType);
    
    REPORTER_ASSERT(reporter, NULL == SkSurface::NewRaster(info));
    REPORTER_ASSERT(reporter, NULL == SkSurface::NewRasterDirect(info, NULL, 0));
    if (ctx) {
        REPORTER_ASSERT(reporter, NULL ==
                        SkSurface::NewRenderTarget(ctx, SkSurface::kNo_Budgeted, info, 0, NULL));
    }
}

#if SK_SUPPORT_GPU
static void test_wrapped_texture_surface(skiatest::Reporter* reporter, GrContext* ctx) {
    if (NULL == ctx) {
        return;
    }

    GrTestTarget tt;
    ctx->getTestTarget(&tt);
    if (!tt.target()) {
        SkDEBUGFAIL("Couldn't get Gr test target.");
        return;
    }

    // We currently have only implemented the texture uploads for GL.
    const GrGLInterface* gl = tt.glContext()->interface();
    if (!gl) {
        return;
    }

    // Test the wrapped factory for SkSurface by creating a texture using GL and then wrap it in
    // a SkSurface.
    GrGLuint texID;
    static const int kW = 100;
    static const int kH = 100;
    static const uint32_t kOrigColor = 0xFFAABBCC;
    SkAutoTArray<uint32_t> pixels(kW * kH);
    sk_memset32(pixels.get(), kOrigColor, kW * kH);
    GR_GL_CALL(gl, GenTextures(1, &texID));
    GR_GL_CALL(gl, ActiveTexture(GR_GL_TEXTURE0));
    GR_GL_CALL(gl, PixelStorei(GR_GL_UNPACK_ALIGNMENT, 1));
    GR_GL_CALL(gl, BindTexture(GR_GL_TEXTURE_2D, texID));
    GR_GL_CALL(gl, TexParameteri(GR_GL_TEXTURE_2D, GR_GL_TEXTURE_MAG_FILTER,
                                 GR_GL_NEAREST));
    GR_GL_CALL(gl, TexParameteri(GR_GL_TEXTURE_2D, GR_GL_TEXTURE_MIN_FILTER,
                                 GR_GL_NEAREST));
    GR_GL_CALL(gl, TexParameteri(GR_GL_TEXTURE_2D, GR_GL_TEXTURE_WRAP_S,
                                 GR_GL_CLAMP_TO_EDGE));
    GR_GL_CALL(gl, TexParameteri(GR_GL_TEXTURE_2D, GR_GL_TEXTURE_WRAP_T,
                                 GR_GL_CLAMP_TO_EDGE));
    GR_GL_CALL(gl, TexImage2D(GR_GL_TEXTURE_2D, 0, GR_GL_RGBA, kW, kH, 0, GR_GL_RGBA,
                              GR_GL_UNSIGNED_BYTE,
                              pixels.get()));

    GrBackendTextureDesc wrappedDesc;
    wrappedDesc.fConfig = kRGBA_8888_GrPixelConfig;
    wrappedDesc.fWidth = kW;
    wrappedDesc.fHeight = kH;
    wrappedDesc.fOrigin = kBottomLeft_GrSurfaceOrigin;
    wrappedDesc.fSampleCnt = 0;
    wrappedDesc.fFlags = kRenderTarget_GrBackendTextureFlag;
    wrappedDesc.fTextureHandle = texID;

    SkAutoTUnref<SkSurface> surface(SkSurface::NewWrappedRenderTarget(ctx, wrappedDesc, NULL));
    REPORTER_ASSERT(reporter, surface);
    if (surface) {
        // Validate that we can draw to the canvas and that the original texture color is preserved
        // in pixels that aren't rendered to via the surface.
        SkPaint paint;
        static const SkColor kRectColor = ~kOrigColor | 0xFF000000;
        paint.setColor(kRectColor);
        surface->getCanvas()->drawRect(SkRect::MakeWH(SkIntToScalar(kW), SkIntToScalar(kH)/2),
                                       paint);
        SkImageInfo readInfo = SkImageInfo::MakeN32Premul(kW, kH);
        surface->readPixels(readInfo, pixels.get(), kW * sizeof(uint32_t), 0, 0);
        bool stop = false;
        SkPMColor origColorPM = SkPackARGB32((kOrigColor >> 24 & 0xFF),
                                             (kOrigColor >>  0 & 0xFF),
                                             (kOrigColor >>  8 & 0xFF),
                                             (kOrigColor >> 16 & 0xFF));
        SkPMColor rectColorPM = SkPackARGB32((kRectColor >> 24 & 0xFF),
                                             (kRectColor >> 16 & 0xFF),
                                             (kRectColor >>  8 & 0xFF),
                                             (kRectColor >>  0 & 0xFF));
        for (int y = 0; y < kH/2 && !stop; ++y) {
            for (int x = 0; x < kW && !stop; ++x) {
                REPORTER_ASSERT(reporter, rectColorPM == pixels[x + y * kW]);
                if (rectColorPM != pixels[x + y * kW]) {
                    stop = true;
                }
            }
        }
        stop = false;
        for (int y = kH/2; y < kH && !stop; ++y) {
            for (int x = 0; x < kW && !stop; ++x) {
                REPORTER_ASSERT(reporter, origColorPM == pixels[x + y * kW]);
                if (origColorPM != pixels[x + y * kW]) {
                    stop = true;
                }
            }
        }
    }
}
#endif


static void test_image(skiatest::Reporter* reporter) {
    SkImageInfo info = SkImageInfo::MakeN32Premul(1, 1);
    size_t rowBytes = info.minRowBytes();
    size_t size = info.getSafeSize(rowBytes);
    SkData* data = SkData::NewUninitialized(size);

    REPORTER_ASSERT(reporter, data->unique());
    SkImage* image = SkImage::NewRasterData(info, data, rowBytes);
    REPORTER_ASSERT(reporter, !data->unique());
    image->unref();
    REPORTER_ASSERT(reporter, data->unique());
    data->unref();
}

// Want to ensure that our Release is called when the owning image is destroyed
struct ReleaseDataContext {
    skiatest::Reporter* fReporter;
    SkData*             fData;

    static void Release(const void* pixels, void* context) {
        ReleaseDataContext* state = (ReleaseDataContext*)context;
        REPORTER_ASSERT(state->fReporter, state->fData);
        state->fData->unref();
        state->fData = NULL;
    }
};

// May we (soon) eliminate the need to keep testing this, by hiding the bloody device!
#include "SkDevice.h"
static uint32_t get_legacy_gen_id(SkSurface* surf) {
    SkBaseDevice* device = surf->getCanvas()->getDevice_just_for_deprecated_compatibility_testing();
    return device->accessBitmap(false).getGenerationID();
}

/*
 *  Test legacy behavor of bumping the surface's device's bitmap's genID when we access its
 *  texture handle for writing.
 *
 *  Note: this needs to be tested separately from checking newImageSnapshot, as calling that
 *  can also incidentally bump the genID (when a new backing surface is created).
 */
template <class F>
static void test_texture_handle_genID(skiatest::Reporter* reporter, SkSurface* surf, F f) {
    const uint32_t gen0 = get_legacy_gen_id(surf);
    f(surf, SkSurface::kFlushRead_BackendHandleAccess);
    const uint32_t gen1 = get_legacy_gen_id(surf);
    REPORTER_ASSERT(reporter, gen0 == gen1);

    f(surf, SkSurface::kFlushWrite_BackendHandleAccess);
    const uint32_t gen2 = get_legacy_gen_id(surf);
    REPORTER_ASSERT(reporter, gen0 != gen2);

    f(surf, SkSurface::kDiscardWrite_BackendHandleAccess);
    const uint32_t gen3 = get_legacy_gen_id(surf);
    REPORTER_ASSERT(reporter, gen0 != gen3);
    REPORTER_ASSERT(reporter, gen2 != gen3);
}

template <class F>
static void test_backend_handle(skiatest::Reporter* reporter, SkSurface* surf, F f) {
    SkAutoTUnref<SkImage> image0(surf->newImageSnapshot());
    GrBackendObject obj = f(surf, SkSurface::kFlushRead_BackendHandleAccess);
    REPORTER_ASSERT(reporter, obj != 0);
    SkAutoTUnref<SkImage> image1(surf->newImageSnapshot());
    // just read access should not affect the snapshot
    REPORTER_ASSERT(reporter, image0->uniqueID() == image1->uniqueID());

    obj = f(surf, SkSurface::kFlushWrite_BackendHandleAccess);
    REPORTER_ASSERT(reporter, obj != 0);
    SkAutoTUnref<SkImage> image2(surf->newImageSnapshot());
    // expect a new image, since we claimed we would write
    REPORTER_ASSERT(reporter, image0->uniqueID() != image2->uniqueID());

    obj = f(surf, SkSurface::kDiscardWrite_BackendHandleAccess);
    REPORTER_ASSERT(reporter, obj != 0);
    SkAutoTUnref<SkImage> image3(surf->newImageSnapshot());
    // expect a new(er) image, since we claimed we would write
    REPORTER_ASSERT(reporter, image0->uniqueID() != image3->uniqueID());
    REPORTER_ASSERT(reporter, image2->uniqueID() != image3->uniqueID());
}

static SkImage* create_image(skiatest::Reporter* reporter,
                             ImageType imageType, GrContext* context, SkColor color,
                             ReleaseDataContext* releaseContext) {
    const SkPMColor pmcolor = SkPreMultiplyColor(color);
    const SkImageInfo info = SkImageInfo::MakeN32Premul(10, 10);
    const size_t rowBytes = info.minRowBytes();
    const size_t size = rowBytes * info.height();

    SkAutoTUnref<SkData> data(SkData::NewUninitialized(size));
    void* addr = data->writable_data();
    sk_memset32((SkPMColor*)addr, pmcolor, SkToInt(size >> 2));

    switch (imageType) {
        case kRasterCopy_ImageType:
            return SkImage::NewRasterCopy(info, addr, rowBytes);
        case kRasterData_ImageType:
            return SkImage::NewRasterData(info, data, rowBytes);
        case kRasterProc_ImageType:
            SkASSERT(releaseContext);
            releaseContext->fData = SkRef(data.get());
            return SkImage::NewFromRaster(info, addr, rowBytes,
                                          ReleaseDataContext::Release, releaseContext);
        case kGpu_ImageType: {
            SkAutoTUnref<SkSurface> surf(
                SkSurface::NewRenderTarget(context, SkSurface::kNo_Budgeted, info, 0));
            surf->getCanvas()->clear(color);
            // test our backing texture / rendertarget while were here...
            auto textureAccessorFunc =
                    [](SkSurface* surf, SkSurface::BackendHandleAccess access) -> GrBackendObject {
                        return surf->getTextureHandle(access); };
            auto renderTargetAccessorFunc =
                    [](SkSurface* surf, SkSurface::BackendHandleAccess access) -> GrBackendObject {
                        GrBackendObject obj;
                        SkAssertResult(surf->getRenderTargetHandle(&obj, access));
                        return obj; };
            test_backend_handle(reporter, surf, textureAccessorFunc);
            test_backend_handle(reporter, surf, renderTargetAccessorFunc);
            test_texture_handle_genID(reporter, surf, textureAccessorFunc);
            test_texture_handle_genID(reporter, surf, renderTargetAccessorFunc);

            // redraw so our returned image looks as expected.
            surf->getCanvas()->clear(color);
            return surf->newImageSnapshot();
        }
        case kCodec_ImageType: {
            SkBitmap bitmap;
            bitmap.installPixels(info, addr, rowBytes);
            SkAutoTUnref<SkData> src(
                 SkImageEncoder::EncodeData(bitmap, SkImageEncoder::kPNG_Type, 100));
            return SkImage::NewFromEncoded(src);
        }
    }
    SkASSERT(false);
    return NULL;
}

static void set_pixels(SkPMColor pixels[], int count, SkPMColor color) {
    sk_memset32(pixels, color, count);
}
static bool has_pixels(const SkPMColor pixels[], int count, SkPMColor expected) {
    for (int i = 0; i < count; ++i) {
        if (pixels[i] != expected) {
            return false;
        }
    }
    return true;
}

static void test_image_readpixels(skiatest::Reporter* reporter, SkImage* image,
                                  SkPMColor expected) {
    const SkPMColor notExpected = ~expected;

    const int w = 2, h = 2;
    const size_t rowBytes = w * sizeof(SkPMColor);
    SkPMColor pixels[w*h];

    SkImageInfo info;

    info = SkImageInfo::MakeUnknown(w, h);
    REPORTER_ASSERT(reporter, !image->readPixels(info, pixels, rowBytes, 0, 0));

    // out-of-bounds should fail
    info = SkImageInfo::MakeN32Premul(w, h);
    REPORTER_ASSERT(reporter, !image->readPixels(info, pixels, rowBytes, -w, 0));
    REPORTER_ASSERT(reporter, !image->readPixels(info, pixels, rowBytes, 0, -h));
    REPORTER_ASSERT(reporter, !image->readPixels(info, pixels, rowBytes, image->width(), 0));
    REPORTER_ASSERT(reporter, !image->readPixels(info, pixels, rowBytes, 0, image->height()));

    // top-left should succeed
    set_pixels(pixels, w*h, notExpected);
    REPORTER_ASSERT(reporter, image->readPixels(info, pixels, rowBytes, 0, 0));
    REPORTER_ASSERT(reporter, has_pixels(pixels, w*h, expected));

    // bottom-right should succeed
    set_pixels(pixels, w*h, notExpected);
    REPORTER_ASSERT(reporter, image->readPixels(info, pixels, rowBytes,
                                                image->width() - w, image->height() - h));
    REPORTER_ASSERT(reporter, has_pixels(pixels, w*h, expected));

    // partial top-left should succeed
    set_pixels(pixels, w*h, notExpected);
    REPORTER_ASSERT(reporter, image->readPixels(info, pixels, rowBytes, -1, -1));
    REPORTER_ASSERT(reporter, pixels[3] == expected);
    REPORTER_ASSERT(reporter, has_pixels(pixels, w*h - 1, notExpected));

    // partial bottom-right should succeed
    set_pixels(pixels, w*h, notExpected);
    REPORTER_ASSERT(reporter, image->readPixels(info, pixels, rowBytes,
                                                image->width() - 1, image->height() - 1));
    REPORTER_ASSERT(reporter, pixels[0] == expected);
    REPORTER_ASSERT(reporter, has_pixels(&pixels[1], w*h - 1, notExpected));
}

static void test_legacy_bitmap(skiatest::Reporter* reporter, const SkImage* image) {
    const SkImage::LegacyBitmapMode modes[] = {
        SkImage::kRO_LegacyBitmapMode,
        SkImage::kRW_LegacyBitmapMode,
    };
    for (size_t i = 0; i < SK_ARRAY_COUNT(modes); ++i) {
        SkBitmap bitmap;
        REPORTER_ASSERT(reporter, image->asLegacyBitmap(&bitmap, modes[i]));

        REPORTER_ASSERT(reporter, image->width() == bitmap.width());
        REPORTER_ASSERT(reporter, image->height() == bitmap.height());
        REPORTER_ASSERT(reporter, image->isOpaque() == bitmap.isOpaque());

        bitmap.lockPixels();
        REPORTER_ASSERT(reporter, bitmap.getPixels());

        const SkImageInfo info = SkImageInfo::MakeN32(1, 1, bitmap.alphaType());
        SkPMColor imageColor;
        REPORTER_ASSERT(reporter, image->readPixels(info, &imageColor, sizeof(SkPMColor), 0, 0));
        REPORTER_ASSERT(reporter, imageColor == *bitmap.getAddr32(0, 0));

        if (SkImage::kRO_LegacyBitmapMode == modes[i]) {
            REPORTER_ASSERT(reporter, bitmap.isImmutable());
        }
    }
}

static void test_imagepeek(skiatest::Reporter* reporter, GrContextFactory* factory) {
    static const struct {
        ImageType   fType;
        bool        fPeekShouldSucceed;
        const char* fName;
    } gRec[] = {
        { kRasterCopy_ImageType,    true,       "RasterCopy"    },
        { kRasterData_ImageType,    true,       "RasterData"    },
        { kRasterProc_ImageType,    true,       "RasterProc"    },
        { kGpu_ImageType,           false,      "Gpu"           },
        { kCodec_ImageType,         false,      "Codec"         },
    };

    const SkColor color = SK_ColorRED;
    const SkPMColor pmcolor = SkPreMultiplyColor(color);

    GrContext* ctx = NULL;
#if SK_SUPPORT_GPU
    ctx = factory->get(GrContextFactory::kNative_GLContextType);
    if (NULL == ctx) {
        return;
    }
#endif

    ReleaseDataContext releaseCtx;
    releaseCtx.fReporter = reporter;

    for (size_t i = 0; i < SK_ARRAY_COUNT(gRec); ++i) {
        SkImageInfo info;
        size_t rowBytes;

        releaseCtx.fData = NULL;
        SkAutoTUnref<SkImage> image(create_image(reporter, gRec[i].fType, ctx, color, &releaseCtx));
        if (!image.get()) {
            SkDebugf("failed to createImage[%d] %s\n", i, gRec[i].fName);
            continue;   // gpu may not be enabled
        }
        if (kRasterProc_ImageType == gRec[i].fType) {
            REPORTER_ASSERT(reporter, NULL != releaseCtx.fData);  // we are tracking the data
        } else {
            REPORTER_ASSERT(reporter, NULL == releaseCtx.fData);  // we ignored the context
        }

        test_legacy_bitmap(reporter, image);

        const void* addr = image->peekPixels(&info, &rowBytes);
        bool success = SkToBool(addr);
        REPORTER_ASSERT(reporter, gRec[i].fPeekShouldSucceed == success);
        if (success) {
            REPORTER_ASSERT(reporter, 10 == info.width());
            REPORTER_ASSERT(reporter, 10 == info.height());
            REPORTER_ASSERT(reporter, kN32_SkColorType == info.colorType());
            REPORTER_ASSERT(reporter, kPremul_SkAlphaType == info.alphaType() ||
                            kOpaque_SkAlphaType == info.alphaType());
            REPORTER_ASSERT(reporter, info.minRowBytes() <= rowBytes);
            REPORTER_ASSERT(reporter, pmcolor == *(const SkPMColor*)addr);
        }

        test_image_readpixels(reporter, image, pmcolor);
    }
    REPORTER_ASSERT(reporter, NULL == releaseCtx.fData);  // we released the data
}

static void test_canvaspeek(skiatest::Reporter* reporter,
                            GrContextFactory* factory) {
    static const struct {
        SurfaceType fType;
        bool        fPeekShouldSucceed;
    } gRec[] = {
        { kRaster_SurfaceType,          true    },
        { kRasterDirect_SurfaceType,    true    },
#if SK_SUPPORT_GPU
        { kGpu_SurfaceType,             false   },
        { kGpuScratch_SurfaceType,      false   },
#endif
    };

    const SkColor color = SK_ColorRED;
    const SkPMColor pmcolor = SkPreMultiplyColor(color);

    int cnt;
#if SK_SUPPORT_GPU
    cnt = GrContextFactory::kGLContextTypeCnt;
#else
    cnt = 1;
#endif

    for (int i= 0; i < cnt; ++i) {
        GrContext* context = NULL;
#if SK_SUPPORT_GPU
        GrContextFactory::GLContextType glCtxType = (GrContextFactory::GLContextType) i;
        if (!GrContextFactory::IsRenderingGLContext(glCtxType)) {
            continue;
        }
        context = factory->get(glCtxType);

        if (NULL == context) {
            continue;
        }
#endif
        for (size_t i = 0; i < SK_ARRAY_COUNT(gRec); ++i) {
            SkImageInfo info, requestInfo;
            size_t rowBytes;

            SkAutoTUnref<SkSurface> surface(create_surface(gRec[i].fType, context,
                                                           kPremul_SkAlphaType, &requestInfo));
            surface->getCanvas()->clear(color);

            const void* addr = surface->getCanvas()->peekPixels(&info, &rowBytes);
            bool success = SkToBool(addr);
            REPORTER_ASSERT(reporter, gRec[i].fPeekShouldSucceed == success);

            SkImageInfo info2;
            size_t rb2;
            const void* addr2 = surface->peekPixels(&info2, &rb2);

            if (success) {
                REPORTER_ASSERT(reporter, requestInfo == info);
                REPORTER_ASSERT(reporter, requestInfo.minRowBytes() <= rowBytes);
                REPORTER_ASSERT(reporter, pmcolor == *(const SkPMColor*)addr);

                REPORTER_ASSERT(reporter, addr2 == addr);
                REPORTER_ASSERT(reporter, info2 == info);
                REPORTER_ASSERT(reporter, rb2 == rowBytes);
            } else {
                REPORTER_ASSERT(reporter, NULL == addr2);
            }
        }
    }
}
>>>>>>> miniblink49

// For compatibility with clients that still call accessBitmap(), we need to ensure that we bump
// the bitmap's genID when we draw to it, else they won't know it has new values. When they are
// exclusively using surface/image, and we can hide accessBitmap from device, we can remove this
// test.
<<<<<<< HEAD
void test_access_pixels(skiatest::Reporter* reporter, const sk_sp<SkSurface>& surface)
{
    SkCanvas* canvas = surface->getCanvas();
    canvas->clear(0);

    SkBaseDevice* device = canvas->getDevice_just_for_deprecated_compatibility_testing();
    SkBitmap bm = device->accessBitmap(false);
    uint32_t genID0 = bm.getGenerationID();
    // Now we draw something, which needs to "dirty" the genID (sorta like copy-on-write)
    canvas->drawColor(SK_ColorBLUE);
    // Now check that we get a different genID
    uint32_t genID1 = bm.getGenerationID();
    REPORTER_ASSERT(reporter, genID0 != genID1);
}
DEF_TEST(SurfaceAccessPixels, reporter)
{
    for (auto& surface_func : { &create_surface, &create_direct_surface }) {
        auto surface(surface_func(kPremul_SkAlphaType, nullptr));
        test_access_pixels(reporter, surface);
    }
}
#if SK_SUPPORT_GPU
DEF_GPUTEST_FOR_RENDERING_CONTEXTS(SurfaceAccessPixels_Gpu, reporter, ctxInfo)
{
    for (auto& surface_func : { &create_gpu_surface, &create_gpu_scratch_surface }) {
        auto surface(surface_func(ctxInfo.grContext(), kPremul_SkAlphaType, nullptr));
        test_access_pixels(reporter, surface);
    }
}
#endif

static void test_snapshot_alphatype(skiatest::Reporter* reporter, const sk_sp<SkSurface>& surface,
    bool expectOpaque)
{
    REPORTER_ASSERT(reporter, surface);
    if (surface) {
        sk_sp<SkImage> image(surface->makeImageSnapshot());
        REPORTER_ASSERT(reporter, image);
        if (image) {
            REPORTER_ASSERT(reporter, image->isOpaque() == SkToBool(expectOpaque));
        }
    }
}
DEF_TEST(SurfaceSnapshotAlphaType, reporter)
{
    for (auto& surface_func : { &create_surface, &create_direct_surface }) {
        for (auto& isOpaque : { true, false }) {
            SkAlphaType alphaType = isOpaque ? kOpaque_SkAlphaType : kPremul_SkAlphaType;
            auto surface(surface_func(alphaType, nullptr));
            test_snapshot_alphatype(reporter, surface, isOpaque);
        }
    }
}
#if SK_SUPPORT_GPU
DEF_GPUTEST_FOR_RENDERING_CONTEXTS(SurfaceSnapshotAlphaType_Gpu, reporter, ctxInfo)
{
    for (auto& surface_func : { &create_gpu_surface, &create_gpu_scratch_surface }) {
        for (auto& isOpaque : { true, false }) {
            SkAlphaType alphaType = isOpaque ? kOpaque_SkAlphaType : kPremul_SkAlphaType;
            auto surface(surface_func(ctxInfo.grContext(), alphaType, nullptr));
            test_snapshot_alphatype(reporter, surface, isOpaque);
        }
    }
}
#endif

static GrBackendObject get_surface_backend_texture_handle(
    SkSurface* s, SkSurface::BackendHandleAccess a)
{
    return s->getTextureHandle(a);
}
static GrBackendObject get_surface_backend_render_target_handle(
    SkSurface* s, SkSurface::BackendHandleAccess a)
{
    GrBackendObject result;
    if (!s->getRenderTargetHandle(&result, a)) {
        return 0;
    }
    return result;
}

static void test_backend_handle_access_copy_on_write(
    skiatest::Reporter* reporter, SkSurface* surface, SkSurface::BackendHandleAccess mode,
    GrBackendObject (*func)(SkSurface*, SkSurface::BackendHandleAccess))
{
    GrBackendObject obj1 = func(surface, mode);
    sk_sp<SkImage> snap1(surface->makeImageSnapshot());

    GrBackendObject obj2 = func(surface, mode);
    sk_sp<SkImage> snap2(surface->makeImageSnapshot());

    // If the access mode triggers CoW, then the backend objects should reflect it.
    REPORTER_ASSERT(reporter, (obj1 == obj2) == (snap1 == snap2));
}
DEF_TEST(SurfaceBackendHandleAccessCopyOnWrite, reporter)
{
    const SkSurface::BackendHandleAccess accessModes[] = {
        SkSurface::kFlushRead_BackendHandleAccess,
        SkSurface::kFlushWrite_BackendHandleAccess,
        SkSurface::kDiscardWrite_BackendHandleAccess,
    };
    for (auto& handle_access_func :
        { &get_surface_backend_texture_handle, &get_surface_backend_render_target_handle }) {
        for (auto& accessMode : accessModes) {
            auto surface(create_surface());
            test_backend_handle_access_copy_on_write(reporter, surface.get(), accessMode,
                handle_access_func);
        }
    }
}
#if SK_SUPPORT_GPU
DEF_GPUTEST_FOR_RENDERING_CONTEXTS(SurfaceBackendHandleAccessCopyOnWrite_Gpu, reporter, ctxInfo)
{
    const SkSurface::BackendHandleAccess accessModes[] = {
        SkSurface::kFlushRead_BackendHandleAccess,
        SkSurface::kFlushWrite_BackendHandleAccess,
        SkSurface::kDiscardWrite_BackendHandleAccess,
    };
    for (auto& surface_func : { &create_gpu_surface, &create_gpu_scratch_surface }) {
        for (auto& handle_access_func :
            { &get_surface_backend_texture_handle, &get_surface_backend_render_target_handle }) {
            for (auto& accessMode : accessModes) {
                auto surface(surface_func(ctxInfo.grContext(), kPremul_SkAlphaType, nullptr));
                test_backend_handle_access_copy_on_write(reporter, surface.get(), accessMode,
                    handle_access_func);
=======
static void test_accessPixels(skiatest::Reporter* reporter, GrContextFactory* factory) {
    static const struct {
        SurfaceType fType;
        bool        fPeekShouldSucceed;
    } gRec[] = {
        { kRaster_SurfaceType,          true    },
        { kRasterDirect_SurfaceType,    true    },
#if SK_SUPPORT_GPU
        { kGpu_SurfaceType,             false   },
        { kGpuScratch_SurfaceType,      false   },
#endif
    };
    
    int cnt;
#if SK_SUPPORT_GPU
    cnt = GrContextFactory::kGLContextTypeCnt;
#else
    cnt = 1;
#endif
    
    for (int i= 0; i < cnt; ++i) {
        GrContext* context = NULL;
#if SK_SUPPORT_GPU
        GrContextFactory::GLContextType glCtxType = (GrContextFactory::GLContextType) i;
        if (!GrContextFactory::IsRenderingGLContext(glCtxType)) {
            continue;
        }
        context = factory->get(glCtxType);
        
        if (NULL == context) {
            continue;
        }
#endif
        for (size_t j = 0; j < SK_ARRAY_COUNT(gRec); ++j) {
            SkImageInfo info, requestInfo;
            
            SkAutoTUnref<SkSurface> surface(create_surface(gRec[j].fType, context,
                                                           kPremul_SkAlphaType,  &requestInfo));
            SkCanvas* canvas = surface->getCanvas();
            canvas->clear(0);

            SkBaseDevice* device = canvas->getDevice_just_for_deprecated_compatibility_testing();
            SkBitmap bm = device->accessBitmap(false);
            uint32_t genID0 = bm.getGenerationID();
            // Now we draw something, which needs to "dirty" the genID (sorta like copy-on-write)
            canvas->drawColor(SK_ColorBLUE);
            // Now check that we get a different genID
            uint32_t genID1 = bm.getGenerationID();
            REPORTER_ASSERT(reporter, genID0 != genID1);
        }
    }
}

static void test_snap_alphatype(skiatest::Reporter* reporter, GrContextFactory* factory) {
    GrContext* context = NULL;
#if SK_SUPPORT_GPU
    context = factory->get(GrContextFactory::kNative_GLContextType);
    if (NULL == context) {
        return;
    }
#endif
    for (int opaque = 0; opaque < 2; ++opaque) {
        SkAlphaType atype = SkToBool(opaque) ? kOpaque_SkAlphaType : kPremul_SkAlphaType;
        for (int st = 0; st < kSurfaceTypeCnt; ++st) {
            SurfaceType stype = (SurfaceType)st;
            SkAutoTUnref<SkSurface> surface(create_surface(stype, context, atype));
            REPORTER_ASSERT(reporter, surface);
            if (surface) {
                SkAutoTUnref<SkImage> image(surface->newImageSnapshot());
                REPORTER_ASSERT(reporter, image);
                if (image) {
                    REPORTER_ASSERT(reporter, image->isOpaque() == SkToBool(opaque));
                }
>>>>>>> miniblink49
            }
        }
    }
}
<<<<<<< HEAD
#endif

static bool same_image(SkImage* a, SkImage* b,
    std::function<intptr_t(SkImage*)> getImageBackingStore)
{
    return getImageBackingStore(a) == getImageBackingStore(b);
}

static bool same_image_surf(SkImage* a, SkSurface* b,
    std::function<intptr_t(SkImage*)> getImageBackingStore,
    std::function<intptr_t(SkSurface*)> getSurfaceBackingStore)
{
    return getImageBackingStore(a) == getSurfaceBackingStore(b);
}

static void test_unique_image_snap(skiatest::Reporter* reporter, SkSurface* surface,
    bool surfaceIsDirect,
    std::function<intptr_t(SkImage*)> imageBackingStore,
    std::function<intptr_t(SkSurface*)> surfaceBackingStore)
{
    std::function<intptr_t(SkImage*)> ibs = imageBackingStore;
    std::function<intptr_t(SkSurface*)> sbs = surfaceBackingStore;
    static const SkBudgeted kB = SkBudgeted::kNo;
    {
        sk_sp<SkImage> image(surface->makeImageSnapshot(kB, SkSurface::kYes_ForceUnique));
        REPORTER_ASSERT(reporter, !same_image_surf(image.get(), surface, ibs, sbs));
        REPORTER_ASSERT(reporter, image->unique());
    }
    {
        sk_sp<SkImage> image1(surface->makeImageSnapshot(kB, SkSurface::kYes_ForceUnique));
        REPORTER_ASSERT(reporter, !same_image_surf(image1.get(), surface, ibs, sbs));
        REPORTER_ASSERT(reporter, image1->unique());
        sk_sp<SkImage> image2(surface->makeImageSnapshot(kB, SkSurface::kYes_ForceUnique));
        REPORTER_ASSERT(reporter, !same_image_surf(image2.get(), surface, ibs, sbs));
        REPORTER_ASSERT(reporter, !same_image(image1.get(), image2.get(), ibs));
        REPORTER_ASSERT(reporter, image2->unique());
    }
    {
        sk_sp<SkImage> image1(surface->makeImageSnapshot(kB, SkSurface::kNo_ForceUnique));
        sk_sp<SkImage> image2(surface->makeImageSnapshot(kB, SkSurface::kYes_ForceUnique));
        sk_sp<SkImage> image3(surface->makeImageSnapshot(kB, SkSurface::kNo_ForceUnique));
        sk_sp<SkImage> image4(surface->makeImageSnapshot(kB, SkSurface::kYes_ForceUnique));
        // Image 1 and 3 ought to be the same (or we're missing an optimization).
        REPORTER_ASSERT(reporter, same_image(image1.get(), image3.get(), ibs));
        // If the surface is not direct then images 1 and 3 should alias the surface's
        // store.
        REPORTER_ASSERT(reporter, !surfaceIsDirect == same_image_surf(image1.get(), surface, ibs, sbs));
        // Image 2 should not be shared with any other image.
        REPORTER_ASSERT(reporter, !same_image(image1.get(), image2.get(), ibs) && !same_image(image3.get(), image2.get(), ibs) && !same_image(image4.get(), image2.get(), ibs));
        REPORTER_ASSERT(reporter, image2->unique());
        REPORTER_ASSERT(reporter, !same_image_surf(image2.get(), surface, ibs, sbs));
        // Image 4 should not be shared with any other image.
        REPORTER_ASSERT(reporter, !same_image(image1.get(), image4.get(), ibs) && !same_image(image3.get(), image4.get(), ibs));
        REPORTER_ASSERT(reporter, !same_image_surf(image4.get(), surface, ibs, sbs));
        REPORTER_ASSERT(reporter, image4->unique());
    }
}

DEF_TEST(UniqueImageSnapshot, reporter)
{
    auto getImageBackingStore = [reporter](SkImage* image) {
        SkPixmap pm;
        bool success = image->peekPixels(&pm);
        REPORTER_ASSERT(reporter, success);
        return reinterpret_cast<intptr_t>(pm.addr());
    };
    auto getSufaceBackingStore = [reporter](SkSurface* surface) {
        SkPixmap pmap;
        const void* pixels = surface->getCanvas()->peekPixels(&pmap) ? pmap.addr() : nullptr;
        REPORTER_ASSERT(reporter, pixels);
        return reinterpret_cast<intptr_t>(pixels);
    };

    auto surface(create_surface());
    test_unique_image_snap(reporter, surface.get(), false, getImageBackingStore,
        getSufaceBackingStore);
    surface = create_direct_surface();
    test_unique_image_snap(reporter, surface.get(), true, getImageBackingStore,
        getSufaceBackingStore);
}

#if SK_SUPPORT_GPU
DEF_GPUTEST_FOR_RENDERING_CONTEXTS(UniqueImageSnapshot_Gpu, reporter, ctxInfo)
{
    GrContext* context = ctxInfo.grContext();
    for (auto& surface_func : { &create_gpu_surface, &create_gpu_scratch_surface }) {
        auto surface(surface_func(context, kOpaque_SkAlphaType, nullptr));

        auto imageBackingStore = [reporter](SkImage* image) {
            GrTexture* texture = as_IB(image)->peekTexture();
            if (!texture) {
                ERRORF(reporter, "Not texture backed.");
                return static_cast<intptr_t>(0);
            }
            return static_cast<intptr_t>(texture->getUniqueID());
        };

        auto surfaceBackingStore = [reporter](SkSurface* surface) {
            GrDrawContext* dc = surface->getCanvas()->internal_private_accessTopLayerDrawContext();
            GrRenderTarget* rt = dc->accessRenderTarget();
            if (!rt) {
                ERRORF(reporter, "Not render target backed.");
                return static_cast<intptr_t>(0);
            }
            return static_cast<intptr_t>(rt->getUniqueID());
        };

        test_unique_image_snap(reporter, surface.get(), false, imageBackingStore,
            surfaceBackingStore);

        // Test again with a "direct" render target;
        GrBackendObject textureObject = context->getGpu()->createTestingOnlyBackendTexture(nullptr,
            10, 10, kRGBA_8888_GrPixelConfig, true);
        GrBackendTextureDesc desc;
        desc.fConfig = kRGBA_8888_GrPixelConfig;
        desc.fWidth = 10;
        desc.fHeight = 10;
        desc.fFlags = kRenderTarget_GrBackendTextureFlag;
        desc.fTextureHandle = textureObject;
        GrTexture* texture = context->textureProvider()->wrapBackendTexture(desc);
        {
            auto surface(SkSurface::MakeRenderTargetDirect(texture->asRenderTarget()));
            test_unique_image_snap(reporter, surface.get(), true, imageBackingStore,
                surfaceBackingStore);
        }
        texture->unref();
        context->getGpu()->deleteTestingOnlyBackendTexture(textureObject);
    }
}
#endif

#if SK_SUPPORT_GPU
// May we (soon) eliminate the need to keep testing this, by hiding the bloody device!
static uint32_t get_legacy_gen_id(SkSurface* surface)
{
    SkBaseDevice* device = surface->getCanvas()->getDevice_just_for_deprecated_compatibility_testing();
    return device->accessBitmap(false).getGenerationID();
}
/*
 *  Test legacy behavor of bumping the surface's device's bitmap's genID when we access its
 *  texture handle for writing.
 *
 *  Note: this needs to be tested separately from checking makeImageSnapshot, as calling that
 *  can also incidentally bump the genID (when a new backing surface is created).
 */
static void test_backend_handle_gen_id(
    skiatest::Reporter* reporter, SkSurface* surface,
    GrBackendObject (*func)(SkSurface*, SkSurface::BackendHandleAccess))
{
    const uint32_t gen0 = get_legacy_gen_id(surface);
    func(surface, SkSurface::kFlushRead_BackendHandleAccess);
    const uint32_t gen1 = get_legacy_gen_id(surface);
    REPORTER_ASSERT(reporter, gen0 == gen1);

    func(surface, SkSurface::kFlushWrite_BackendHandleAccess);
    const uint32_t gen2 = get_legacy_gen_id(surface);
    REPORTER_ASSERT(reporter, gen0 != gen2);

    func(surface, SkSurface::kDiscardWrite_BackendHandleAccess);
    const uint32_t gen3 = get_legacy_gen_id(surface);
    REPORTER_ASSERT(reporter, gen0 != gen3);
    REPORTER_ASSERT(reporter, gen2 != gen3);
}
static void test_backend_handle_unique_id(
    skiatest::Reporter* reporter, SkSurface* surface,
    GrBackendObject (*func)(SkSurface*, SkSurface::BackendHandleAccess))
{
    sk_sp<SkImage> image0(surface->makeImageSnapshot());
    GrBackendObject obj = func(surface, SkSurface::kFlushRead_BackendHandleAccess);
    REPORTER_ASSERT(reporter, obj != 0);
    sk_sp<SkImage> image1(surface->makeImageSnapshot());
    // just read access should not affect the snapshot
    REPORTER_ASSERT(reporter, image0->uniqueID() == image1->uniqueID());

    obj = func(surface, SkSurface::kFlushWrite_BackendHandleAccess);
    REPORTER_ASSERT(reporter, obj != 0);
    sk_sp<SkImage> image2(surface->makeImageSnapshot());
    // expect a new image, since we claimed we would write
    REPORTER_ASSERT(reporter, image0->uniqueID() != image2->uniqueID());

    obj = func(surface, SkSurface::kDiscardWrite_BackendHandleAccess);
    REPORTER_ASSERT(reporter, obj != 0);
    sk_sp<SkImage> image3(surface->makeImageSnapshot());
    // expect a new(er) image, since we claimed we would write
    REPORTER_ASSERT(reporter, image0->uniqueID() != image3->uniqueID());
    REPORTER_ASSERT(reporter, image2->uniqueID() != image3->uniqueID());
}
// No CPU test.
DEF_GPUTEST_FOR_RENDERING_CONTEXTS(SurfaceBackendHandleAccessIDs_Gpu, reporter, ctxInfo)
{
    for (auto& surface_func : { &create_gpu_surface, &create_gpu_scratch_surface }) {
        for (auto& test_func : { &test_backend_handle_unique_id, &test_backend_handle_gen_id }) {
            for (auto& handle_access_func :
                { &get_surface_backend_texture_handle, &get_surface_backend_render_target_handle }) {
                auto surface(surface_func(ctxInfo.grContext(), kPremul_SkAlphaType, nullptr));
                test_func(reporter, surface.get(), handle_access_func);
            }
        }
    }
}
#endif

// Verify that the right canvas commands trigger a copy on write.
static void test_copy_on_write(skiatest::Reporter* reporter, SkSurface* surface)
{
    SkCanvas* canvas = surface->getCanvas();

    const SkRect testRect = SkRect::MakeXYWH(SkIntToScalar(0), SkIntToScalar(0),
        SkIntToScalar(4), SkIntToScalar(5));
    SkPath testPath;
    testPath.addRect(SkRect::MakeXYWH(SkIntToScalar(0), SkIntToScalar(0),
        SkIntToScalar(2), SkIntToScalar(1)));
=======

static void TestSurfaceCopyOnWrite(skiatest::Reporter* reporter, SurfaceType surfaceType,
                                   GrContext* context) {
    // Verify that the right canvas commands trigger a copy on write
    SkSurface* surface = create_surface(surfaceType, context);
    SkAutoTUnref<SkSurface> aur_surface(surface);
    SkCanvas* canvas = surface->getCanvas();

    const SkRect testRect =
        SkRect::MakeXYWH(SkIntToScalar(0), SkIntToScalar(0),
                         SkIntToScalar(4), SkIntToScalar(5));
    SkPath testPath;
    testPath.addRect(SkRect::MakeXYWH(SkIntToScalar(0), SkIntToScalar(0),
                                      SkIntToScalar(2), SkIntToScalar(1)));
>>>>>>> miniblink49

    const SkIRect testIRect = SkIRect::MakeXYWH(0, 0, 2, 1);

    SkRegion testRegion;
    testRegion.setRect(testIRect);

<<<<<<< HEAD
    const SkColor testColor = 0x01020304;
    const SkPaint testPaint;
    const SkPoint testPoints[3] = {
        { SkIntToScalar(0), SkIntToScalar(0) },
        { SkIntToScalar(2), SkIntToScalar(1) },
        { SkIntToScalar(0), SkIntToScalar(2) }
=======

    const SkColor testColor = 0x01020304;
    const SkPaint testPaint;
    const SkPoint testPoints[3] = {
        {SkIntToScalar(0), SkIntToScalar(0)},
        {SkIntToScalar(2), SkIntToScalar(1)},
        {SkIntToScalar(0), SkIntToScalar(2)}
>>>>>>> miniblink49
    };
    const size_t testPointCount = 3;

    SkBitmap testBitmap;
    testBitmap.allocN32Pixels(10, 10);
    testBitmap.eraseColor(0);

    SkRRect testRRect;
    testRRect.setRectXY(testRect, SK_Scalar1, SK_Scalar1);

    SkString testText("Hello World");
    const SkPoint testPoints2[] = {
        { SkIntToScalar(0), SkIntToScalar(1) },
        { SkIntToScalar(1), SkIntToScalar(1) },
        { SkIntToScalar(2), SkIntToScalar(1) },
        { SkIntToScalar(3), SkIntToScalar(1) },
        { SkIntToScalar(4), SkIntToScalar(1) },
        { SkIntToScalar(5), SkIntToScalar(1) },
        { SkIntToScalar(6), SkIntToScalar(1) },
        { SkIntToScalar(7), SkIntToScalar(1) },
        { SkIntToScalar(8), SkIntToScalar(1) },
        { SkIntToScalar(9), SkIntToScalar(1) },
        { SkIntToScalar(10), SkIntToScalar(1) },
    };

<<<<<<< HEAD
#define EXPECT_COPY_ON_WRITE(command)                              \
    {                                                              \
        sk_sp<SkImage> imageBefore = surface->makeImageSnapshot(); \
        sk_sp<SkImage> aur_before(imageBefore);                    \
        canvas->command;                                           \
        sk_sp<SkImage> imageAfter = surface->makeImageSnapshot();  \
        sk_sp<SkImage> aur_after(imageAfter);                      \
        REPORTER_ASSERT(reporter, imageBefore != imageAfter);      \
=======
#define EXPECT_COPY_ON_WRITE(command)                               \
    {                                                               \
        SkImage* imageBefore = surface->newImageSnapshot();         \
        SkAutoTUnref<SkImage> aur_before(imageBefore);              \
        canvas-> command ;                                          \
        SkImage* imageAfter = surface->newImageSnapshot();          \
        SkAutoTUnref<SkImage> aur_after(imageAfter);                \
        REPORTER_ASSERT(reporter, imageBefore != imageAfter);       \
>>>>>>> miniblink49
    }

    EXPECT_COPY_ON_WRITE(clear(testColor))
    EXPECT_COPY_ON_WRITE(drawPaint(testPaint))
<<<<<<< HEAD
    EXPECT_COPY_ON_WRITE(drawPoints(SkCanvas::kPoints_PointMode, testPointCount, testPoints,
=======
    EXPECT_COPY_ON_WRITE(drawPoints(SkCanvas::kPoints_PointMode, testPointCount, testPoints, \
>>>>>>> miniblink49
        testPaint))
    EXPECT_COPY_ON_WRITE(drawOval(testRect, testPaint))
    EXPECT_COPY_ON_WRITE(drawRect(testRect, testPaint))
    EXPECT_COPY_ON_WRITE(drawRRect(testRRect, testPaint))
    EXPECT_COPY_ON_WRITE(drawPath(testPath, testPaint))
    EXPECT_COPY_ON_WRITE(drawBitmap(testBitmap, 0, 0))
<<<<<<< HEAD
    EXPECT_COPY_ON_WRITE(drawBitmapRect(testBitmap, testRect, nullptr))
    EXPECT_COPY_ON_WRITE(drawBitmapNine(testBitmap, testIRect, testRect, nullptr))
    EXPECT_COPY_ON_WRITE(drawText(testText.c_str(), testText.size(), 0, 1, testPaint))
    EXPECT_COPY_ON_WRITE(drawPosText(testText.c_str(), testText.size(), testPoints2,
        testPaint))
    EXPECT_COPY_ON_WRITE(drawTextOnPath(testText.c_str(), testText.size(), testPath, nullptr,
        testPaint))
}
DEF_TEST(SurfaceCopyOnWrite, reporter)
{
    test_copy_on_write(reporter, create_surface().get());
}
#if SK_SUPPORT_GPU
DEF_GPUTEST_FOR_RENDERING_CONTEXTS(SurfaceCopyOnWrite_Gpu, reporter, ctxInfo)
{
    for (auto& surface_func : { &create_gpu_surface, &create_gpu_scratch_surface }) {
        auto surface(surface_func(ctxInfo.grContext(), kPremul_SkAlphaType, nullptr));
        test_copy_on_write(reporter, surface.get());
    }
}
#endif

static void test_writable_after_snapshot_release(skiatest::Reporter* reporter,
    SkSurface* surface)
{
    // This test succeeds by not triggering an assertion.
    // The test verifies that the surface remains writable (usable) after
    // acquiring and releasing a snapshot without triggering a copy on write.
    SkCanvas* canvas = surface->getCanvas();
    canvas->clear(1);
    surface->makeImageSnapshot(); // Create and destroy SkImage
    canvas->clear(2); // Must not assert internally
}
DEF_TEST(SurfaceWriteableAfterSnapshotRelease, reporter)
{
    test_writable_after_snapshot_release(reporter, create_surface().get());
}
#if SK_SUPPORT_GPU
DEF_GPUTEST_FOR_RENDERING_CONTEXTS(SurfaceWriteableAfterSnapshotRelease_Gpu, reporter, ctxInfo)
{
    for (auto& surface_func : { &create_gpu_surface, &create_gpu_scratch_surface }) {
        auto surface(surface_func(ctxInfo.grContext(), kPremul_SkAlphaType, nullptr));
        test_writable_after_snapshot_release(reporter, surface.get());
    }
}
#endif

#if SK_SUPPORT_GPU
static void test_crbug263329(skiatest::Reporter* reporter,
    SkSurface* surface1,
    SkSurface* surface2)
{
=======
    EXPECT_COPY_ON_WRITE(drawBitmapRect(testBitmap, NULL, testRect))
    EXPECT_COPY_ON_WRITE(drawBitmapNine(testBitmap, testIRect, testRect, NULL))
    EXPECT_COPY_ON_WRITE(drawSprite(testBitmap, 0, 0, NULL))
    EXPECT_COPY_ON_WRITE(drawText(testText.c_str(), testText.size(), 0, 1, testPaint))
    EXPECT_COPY_ON_WRITE(drawPosText(testText.c_str(), testText.size(), testPoints2, \
        testPaint))
    EXPECT_COPY_ON_WRITE(drawTextOnPath(testText.c_str(), testText.size(), testPath, NULL, \
        testPaint))
}

static void TestSurfaceWritableAfterSnapshotRelease(skiatest::Reporter* reporter,
                                                    SurfaceType surfaceType,
                                                    GrContext* context) {
    // This test succeeds by not triggering an assertion.
    // The test verifies that the surface remains writable (usable) after
    // acquiring and releasing a snapshot without triggering a copy on write.
    SkAutoTUnref<SkSurface> surface(create_surface(surfaceType, context));
    SkCanvas* canvas = surface->getCanvas();
    canvas->clear(1);
    surface->newImageSnapshot()->unref();  // Create and destroy SkImage
    canvas->clear(2);  // Must not assert internally
}

#if SK_SUPPORT_GPU
static void Test_crbug263329(skiatest::Reporter* reporter,
                             SurfaceType surfaceType,
                             GrContext* context) {
>>>>>>> miniblink49
    // This is a regression test for crbug.com/263329
    // Bug was caused by onCopyOnWrite releasing the old surface texture
    // back to the scratch texture pool even though the texture is used
    // by and active SkImage_Gpu.
<<<<<<< HEAD
    SkCanvas* canvas1 = surface1->getCanvas();
    SkCanvas* canvas2 = surface2->getCanvas();
    canvas1->clear(1);
    sk_sp<SkImage> image1(surface1->makeImageSnapshot());
    // Trigger copy on write, new backing is a scratch texture
    canvas1->clear(2);
    sk_sp<SkImage> image2(surface1->makeImageSnapshot());
=======
    SkAutoTUnref<SkSurface> surface1(create_surface(surfaceType, context));
    SkAutoTUnref<SkSurface> surface2(create_surface(surfaceType, context));
    SkCanvas* canvas1 = surface1->getCanvas();
    SkCanvas* canvas2 = surface2->getCanvas();
    canvas1->clear(1);
    SkAutoTUnref<SkImage> image1(surface1->newImageSnapshot());
    // Trigger copy on write, new backing is a scratch texture
    canvas1->clear(2);
    SkAutoTUnref<SkImage> image2(surface1->newImageSnapshot());
>>>>>>> miniblink49
    // Trigger copy on write, old backing should not be returned to scratch
    // pool because it is held by image2
    canvas1->clear(3);

    canvas2->clear(4);
<<<<<<< HEAD
    sk_sp<SkImage> image3(surface2->makeImageSnapshot());
    // Trigger copy on write on surface2. The new backing store should not
    // be recycling a texture that is held by an existing image.
    canvas2->clear(5);
    sk_sp<SkImage> image4(surface2->makeImageSnapshot());
    REPORTER_ASSERT(reporter, as_IB(image4)->peekTexture() != as_IB(image3)->peekTexture());
    // The following assertion checks crbug.com/263329
    REPORTER_ASSERT(reporter, as_IB(image4)->peekTexture() != as_IB(image2)->peekTexture());
    REPORTER_ASSERT(reporter, as_IB(image4)->peekTexture() != as_IB(image1)->peekTexture());
    REPORTER_ASSERT(reporter, as_IB(image3)->peekTexture() != as_IB(image2)->peekTexture());
    REPORTER_ASSERT(reporter, as_IB(image3)->peekTexture() != as_IB(image1)->peekTexture());
    REPORTER_ASSERT(reporter, as_IB(image2)->peekTexture() != as_IB(image1)->peekTexture());
}
DEF_GPUTEST_FOR_RENDERING_CONTEXTS(SurfaceCRBug263329_Gpu, reporter, ctxInfo)
{
    for (auto& surface_func : { &create_gpu_surface, &create_gpu_scratch_surface }) {
        auto surface1(surface_func(ctxInfo.grContext(), kPremul_SkAlphaType, nullptr));
        auto surface2(surface_func(ctxInfo.grContext(), kPremul_SkAlphaType, nullptr));
        test_crbug263329(reporter, surface1.get(), surface2.get());
    }
}
#endif

DEF_TEST(SurfaceGetTexture, reporter)
{
    auto surface(create_surface());
    sk_sp<SkImage> image(surface->makeImageSnapshot());
    REPORTER_ASSERT(reporter, as_IB(image)->peekTexture() == nullptr);
    surface->notifyContentWillChange(SkSurface::kDiscard_ContentChangeMode);
    REPORTER_ASSERT(reporter, as_IB(image)->peekTexture() == nullptr);
}
#if SK_SUPPORT_GPU
DEF_GPUTEST_FOR_RENDERING_CONTEXTS(SurfacepeekTexture_Gpu, reporter, ctxInfo)
{
    for (auto& surface_func : { &create_gpu_surface, &create_gpu_scratch_surface }) {
        auto surface(surface_func(ctxInfo.grContext(), kPremul_SkAlphaType, nullptr));
        sk_sp<SkImage> image(surface->makeImageSnapshot());
        GrTexture* texture = as_IB(image)->peekTexture();
        REPORTER_ASSERT(reporter, texture);
        REPORTER_ASSERT(reporter, 0 != texture->getTextureHandle());
        surface->notifyContentWillChange(SkSurface::kDiscard_ContentChangeMode);
        REPORTER_ASSERT(reporter, as_IB(image)->peekTexture() == texture);
    }
}
#endif

#if SK_SUPPORT_GPU
=======
    SkAutoTUnref<SkImage> image3(surface2->newImageSnapshot());
    // Trigger copy on write on surface2. The new backing store should not
    // be recycling a texture that is held by an existing image.
    canvas2->clear(5);
    SkAutoTUnref<SkImage> image4(surface2->newImageSnapshot());
    REPORTER_ASSERT(reporter, as_IB(image4)->getTexture() != as_IB(image3)->getTexture());
    // The following assertion checks crbug.com/263329
    REPORTER_ASSERT(reporter, as_IB(image4)->getTexture() != as_IB(image2)->getTexture());
    REPORTER_ASSERT(reporter, as_IB(image4)->getTexture() != as_IB(image1)->getTexture());
    REPORTER_ASSERT(reporter, as_IB(image3)->getTexture() != as_IB(image2)->getTexture());
    REPORTER_ASSERT(reporter, as_IB(image3)->getTexture() != as_IB(image1)->getTexture());
    REPORTER_ASSERT(reporter, as_IB(image2)->getTexture() != as_IB(image1)->getTexture());
}

static void TestGetTexture(skiatest::Reporter* reporter,
                                 SurfaceType surfaceType,
                                 GrContext* context) {
    SkAutoTUnref<SkSurface> surface(create_surface(surfaceType, context));
    SkAutoTUnref<SkImage> image(surface->newImageSnapshot());
    GrTexture* texture = as_IB(image)->getTexture();
    if (surfaceType == kGpu_SurfaceType || surfaceType == kGpuScratch_SurfaceType) {
        REPORTER_ASSERT(reporter, texture);
        REPORTER_ASSERT(reporter, 0 != texture->getTextureHandle());
    } else {
        REPORTER_ASSERT(reporter, NULL == texture);
    }
    surface->notifyContentWillChange(SkSurface::kDiscard_ContentChangeMode);
    REPORTER_ASSERT(reporter, as_IB(image)->getTexture() == texture);
}

>>>>>>> miniblink49
#include "GrGpuResourcePriv.h"
#include "SkGpuDevice.h"
#include "SkImage_Gpu.h"
#include "SkSurface_Gpu.h"

<<<<<<< HEAD
static SkBudgeted is_budgeted(const sk_sp<SkSurface>& surf)
{
    SkSurface_Gpu* gsurf = (SkSurface_Gpu*)surf.get();
    return gsurf->getDevice()->accessRenderTarget()->resourcePriv().isBudgeted();
}

static SkBudgeted is_budgeted(SkImage* image)
{
    return ((SkImage_Gpu*)image)->peekTexture()->resourcePriv().isBudgeted();
}

static SkBudgeted is_budgeted(const sk_sp<SkImage> image)
{
    return is_budgeted(image.get());
}

DEF_GPUTEST_FOR_RENDERING_CONTEXTS(SurfaceBudget, reporter, ctxInfo)
{
    SkImageInfo info = SkImageInfo::MakeN32Premul(8, 8);
    for (auto sbudgeted : { SkBudgeted::kNo, SkBudgeted::kYes }) {
        for (auto ibudgeted : { SkBudgeted::kNo, SkBudgeted::kYes }) {
            auto surface(SkSurface::MakeRenderTarget(ctxInfo.grContext(), sbudgeted, info));
            SkASSERT(surface);
            REPORTER_ASSERT(reporter, sbudgeted == is_budgeted(surface));

            sk_sp<SkImage> image(surface->makeImageSnapshot(ibudgeted));
=======
SkSurface::Budgeted is_budgeted(SkSurface* surf) {
    return ((SkSurface_Gpu*)surf)->getDevice()->accessRenderTarget()->resourcePriv().isBudgeted() ?
        SkSurface::kYes_Budgeted : SkSurface::kNo_Budgeted;
}

SkSurface::Budgeted is_budgeted(SkImage* image) {
    return ((SkImage_Gpu*)image)->getTexture()->resourcePriv().isBudgeted() ?
        SkSurface::kYes_Budgeted : SkSurface::kNo_Budgeted;
}

static void test_surface_budget(skiatest::Reporter* reporter, GrContext* context) {
    SkImageInfo info = SkImageInfo::MakeN32Premul(8,8);
    for (int i = 0; i < 2; ++i) {
        SkSurface::Budgeted sbudgeted = i ? SkSurface::kYes_Budgeted : SkSurface::kNo_Budgeted;
        for (int j = 0; j < 2; ++j) {
            SkSurface::Budgeted ibudgeted = j ? SkSurface::kYes_Budgeted : SkSurface::kNo_Budgeted;
            SkAutoTUnref<SkSurface>
                surface(SkSurface::NewRenderTarget(context, sbudgeted, info, 0));
            SkASSERT(surface);
            REPORTER_ASSERT(reporter, sbudgeted == is_budgeted(surface));

            SkAutoTUnref<SkImage> image(surface->newImageSnapshot(ibudgeted));
>>>>>>> miniblink49

            // Initially the image shares a texture with the surface, and the surface decides
            // whether it is budgeted or not.
            REPORTER_ASSERT(reporter, sbudgeted == is_budgeted(surface));
            REPORTER_ASSERT(reporter, sbudgeted == is_budgeted(image));

            // Now trigger copy-on-write
            surface->getCanvas()->clear(SK_ColorBLUE);

            // They don't share a texture anymore. They should each have made their own budget
            // decision.
            REPORTER_ASSERT(reporter, sbudgeted == is_budgeted(surface));
            REPORTER_ASSERT(reporter, ibudgeted == is_budgeted(image));
        }
    }
}
<<<<<<< HEAD
#endif

static void test_no_canvas1(skiatest::Reporter* reporter,
    SkSurface* surface,
    SkSurface::ContentChangeMode mode)
{
    // Test passes by not asserting
    surface->notifyContentWillChange(mode);
    SkDEBUGCODE(surface->validate();)
}
static void test_no_canvas2(skiatest::Reporter* reporter,
    SkSurface* surface,
    SkSurface::ContentChangeMode mode)
{
    // Verifies the robustness of SkSurface for handling use cases where calls
    // are made before a canvas is created.
    sk_sp<SkImage> image1 = surface->makeImageSnapshot();
    sk_sp<SkImage> aur_image1(image1);
    SkDEBUGCODE(image1->validate();)
        SkDEBUGCODE(surface->validate();)
            surface->notifyContentWillChange(mode);
    SkDEBUGCODE(image1->validate();)
        SkDEBUGCODE(surface->validate();)
            sk_sp<SkImage>
                image2 = surface->makeImageSnapshot();
    sk_sp<SkImage> aur_image2(image2);
    SkDEBUGCODE(image2->validate();)
        SkDEBUGCODE(surface->validate();)
            REPORTER_ASSERT(reporter, image1 != image2);
}
DEF_TEST(SurfaceNoCanvas, reporter)
{
    SkSurface::ContentChangeMode modes[] = { SkSurface::kDiscard_ContentChangeMode, SkSurface::kRetain_ContentChangeMode };
    for (auto& test_func : { &test_no_canvas1, &test_no_canvas2 }) {
        for (auto& mode : modes) {
            test_func(reporter, create_surface().get(), mode);
        }
    }
}
#if SK_SUPPORT_GPU
DEF_GPUTEST_FOR_RENDERING_CONTEXTS(SurfaceNoCanvas_Gpu, reporter, ctxInfo)
{
    SkSurface::ContentChangeMode modes[] = { SkSurface::kDiscard_ContentChangeMode, SkSurface::kRetain_ContentChangeMode };
    for (auto& surface_func : { &create_gpu_surface, &create_gpu_scratch_surface }) {
        for (auto& test_func : { &test_no_canvas1, &test_no_canvas2 }) {
            for (auto& mode : modes) {
                auto surface(surface_func(ctxInfo.grContext(), kPremul_SkAlphaType, nullptr));
                test_func(reporter, surface.get(), mode);
            }
        }
    }
}
#endif

static void check_rowbytes_remain_consistent(SkSurface* surface, skiatest::Reporter* reporter)
{
    SkPixmap surfacePM;
    REPORTER_ASSERT(reporter, surface->peekPixels(&surfacePM));

    sk_sp<SkImage> image(surface->makeImageSnapshot());
    SkPixmap pm;
    REPORTER_ASSERT(reporter, image->peekPixels(&pm));

    REPORTER_ASSERT(reporter, surfacePM.rowBytes() == pm.rowBytes());

    // trigger a copy-on-write
    surface->getCanvas()->drawPaint(SkPaint());
    sk_sp<SkImage> image2(surface->makeImageSnapshot());
    REPORTER_ASSERT(reporter, image->uniqueID() != image2->uniqueID());

    SkPixmap pm2;
    REPORTER_ASSERT(reporter, image2->peekPixels(&pm2));
    REPORTER_ASSERT(reporter, pm2.rowBytes() == pm.rowBytes());
}

DEF_TEST(surface_rowbytes, reporter)
{
    const SkImageInfo info = SkImageInfo::MakeN32Premul(100, 100);

    auto surf0(SkSurface::MakeRaster(info));
    check_rowbytes_remain_consistent(surf0.get(), reporter);

    // specify a larger rowbytes
    auto surf1(SkSurface::MakeRaster(info, 500, nullptr));
    check_rowbytes_remain_consistent(surf1.get(), reporter);

    // Try some illegal rowByte values
    auto s = SkSurface::MakeRaster(info, 396, nullptr); // needs to be at least 400
    REPORTER_ASSERT(reporter, nullptr == s);
    s = SkSurface::MakeRaster(info, 1 << 30, nullptr); // allocation to large
    REPORTER_ASSERT(reporter, nullptr == s);
}

#if SK_SUPPORT_GPU
static sk_sp<SkSurface> create_gpu_surface_backend_texture(
    GrContext* context, int sampleCnt, uint32_t color, GrBackendObject* outTexture)
{
    const int kWidth = 10;
    const int kHeight = 10;
    SkAutoTDeleteArray<uint32_t> pixels(new uint32_t[kWidth * kHeight]);
    sk_memset32(pixels.get(), color, kWidth * kHeight);
    GrBackendTextureDesc desc;
    desc.fConfig = kRGBA_8888_GrPixelConfig;
    desc.fWidth = kWidth;
    desc.fHeight = kHeight;
    desc.fFlags = kRenderTarget_GrBackendTextureFlag;
    desc.fTextureHandle = context->getGpu()->createTestingOnlyBackendTexture(
        pixels.get(), kWidth, kHeight, kRGBA_8888_GrPixelConfig, true);
    desc.fSampleCnt = sampleCnt;
    sk_sp<SkSurface> surface = SkSurface::MakeFromBackendTexture(context, desc, nullptr);
    if (!surface) {
        context->getGpu()->deleteTestingOnlyBackendTexture(desc.fTextureHandle);
        return nullptr;
    }
    *outTexture = desc.fTextureHandle;
    return surface;
}

static sk_sp<SkSurface> create_gpu_surface_backend_texture_as_render_target(
    GrContext* context, int sampleCnt, uint32_t color, GrBackendObject* outTexture)
{
    const int kWidth = 10;
    const int kHeight = 10;
    SkAutoTDeleteArray<uint32_t> pixels(new uint32_t[kWidth * kHeight]);
    sk_memset32(pixels.get(), color, kWidth * kHeight);
    GrBackendTextureDesc desc;
    desc.fConfig = kRGBA_8888_GrPixelConfig;
    desc.fWidth = kWidth;
    desc.fHeight = kHeight;
    desc.fFlags = kRenderTarget_GrBackendTextureFlag;
    desc.fTextureHandle = context->getGpu()->createTestingOnlyBackendTexture(
        pixels.get(), kWidth, kHeight, kRGBA_8888_GrPixelConfig, true);
    desc.fSampleCnt = sampleCnt;
    sk_sp<SkSurface> surface = SkSurface::MakeFromBackendTextureAsRenderTarget(context, desc,
        nullptr);
    if (!surface) {
        context->getGpu()->deleteTestingOnlyBackendTexture(desc.fTextureHandle);
        return nullptr;
    }
    *outTexture = desc.fTextureHandle;
    return surface;
}

static void test_surface_clear(skiatest::Reporter* reporter, sk_sp<SkSurface> surface,
    std::function<GrSurface*(SkSurface*)> grSurfaceGetter,
    uint32_t expectedValue)
{
    if (!surface) {
        ERRORF(reporter, "Could not create GPU SkSurface.");
        return;
    }
    int w = surface->width();
    int h = surface->height();
    SkAutoTDeleteArray<uint32_t> pixels(new uint32_t[w * h]);
    sk_memset32(pixels.get(), ~expectedValue, w * h);

    SkAutoTUnref<GrSurface> grSurface(SkSafeRef(grSurfaceGetter(surface.get())));
    if (!grSurface) {
        ERRORF(reporter, "Could access render target of GPU SkSurface.");
        return;
    }
    surface.reset();
    grSurface->readPixels(0, 0, w, h, kRGBA_8888_GrPixelConfig, pixels.get());
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            uint32_t pixel = pixels.get()[y * w + x];
            if (pixel != expectedValue) {
                SkString msg;
                if (expectedValue) {
                    msg = "SkSurface should have left render target unmodified";
                } else {
                    msg = "SkSurface should have cleared the render target";
                }
                ERRORF(reporter,
                    "%s but read 0x%08x (instead of 0x%08x) at %x,%d", msg.c_str(), pixel,
                    expectedValue, x, y);
                return;
            }
        }
    }
}

DEF_GPUTEST_FOR_GL_RENDERING_CONTEXTS(SurfaceClear_Gpu, reporter, ctxInfo)
{
    GrContext* context = ctxInfo.grContext();

    std::function<GrSurface*(SkSurface*)> grSurfaceGetters[] = {
        [](SkSurface* s) {
            GrDrawContext* dc = s->getCanvas()->internal_private_accessTopLayerDrawContext();
            return dc->accessRenderTarget(); },
        [](SkSurface* s) {
            SkBaseDevice* d =
                s->getCanvas()->getDevice_just_for_deprecated_compatibility_testing();
            return d->accessRenderTarget(); },
        [](SkSurface* s) { sk_sp<SkImage> i(s->makeImageSnapshot());
                           return as_IB(i)->peekTexture(); }
    };

    for (auto grSurfaceGetter : grSurfaceGetters) {
        // Test that non-wrapped RTs are created clear.
        for (auto& surface_func : { &create_gpu_surface, &create_gpu_scratch_surface }) {
            auto surface = surface_func(context, kPremul_SkAlphaType, nullptr);
            test_surface_clear(reporter, surface, grSurfaceGetter, 0x0);
        }
        // Wrapped RTs are *not* supposed to clear (to allow client to partially update a surface).
        const uint32_t kOrigColor = 0xABABABAB;
        for (auto& surfaceFunc : { &create_gpu_surface_backend_texture,
                 &create_gpu_surface_backend_texture_as_render_target }) {
            GrBackendObject textureObject;
            auto surface = surfaceFunc(context, 0, kOrigColor, &textureObject);
            test_surface_clear(reporter, surface, grSurfaceGetter, kOrigColor);
            surface.reset();
            context->getGpu()->deleteTestingOnlyBackendTexture(textureObject);
        }
    }
}

static void test_surface_draw_partially(
    skiatest::Reporter* reporter, sk_sp<SkSurface> surface, uint32_t origColor)
{
    const int kW = surface->width();
    const int kH = surface->height();
    SkPaint paint;
    const SkColor kRectColor = ~origColor | 0xFF000000;
    paint.setColor(kRectColor);
    surface->getCanvas()->drawRect(SkRect::MakeWH(SkIntToScalar(kW), SkIntToScalar(kH) / 2),
        paint);
    SkAutoTDeleteArray<uint32_t> pixels(new uint32_t[kW * kH]);
    sk_memset32(pixels.get(), ~origColor, kW * kH);
    // Read back RGBA to avoid format conversions that may not be supported on all platforms.
    SkImageInfo readInfo = SkImageInfo::Make(kW, kH, kRGBA_8888_SkColorType, kPremul_SkAlphaType);
    SkAssertResult(surface->readPixels(readInfo, pixels.get(), kW * sizeof(uint32_t), 0, 0));
    bool stop = false;
    SkPMColor origColorPM = SkPackARGB_as_RGBA((origColor >> 24 & 0xFF),
        (origColor >> 0 & 0xFF),
        (origColor >> 8 & 0xFF),
        (origColor >> 16 & 0xFF));
    SkPMColor rectColorPM = SkPackARGB_as_RGBA((kRectColor >> 24 & 0xFF),
        (kRectColor >> 16 & 0xFF),
        (kRectColor >> 8 & 0xFF),
        (kRectColor >> 0 & 0xFF));
    for (int y = 0; y < kH / 2 && !stop; ++y) {
        for (int x = 0; x < kW && !stop; ++x) {
            REPORTER_ASSERT(reporter, rectColorPM == pixels[x + y * kW]);
            if (rectColorPM != pixels[x + y * kW]) {
                stop = true;
            }
        }
    }
    stop = false;
    for (int y = kH / 2; y < kH && !stop; ++y) {
        for (int x = 0; x < kW && !stop; ++x) {
            REPORTER_ASSERT(reporter, origColorPM == pixels[x + y * kW]);
            if (origColorPM != pixels[x + y * kW]) {
                stop = true;
            }
        }
    }
}

DEF_GPUTEST_FOR_RENDERING_CONTEXTS(SurfacePartialDraw_Gpu, reporter, ctxInfo)
{
    GrGpu* gpu = ctxInfo.grContext()->getGpu();
    if (!gpu) {
        return;
    }
    static const uint32_t kOrigColor = 0xFFAABBCC;

    for (auto& surfaceFunc : { &create_gpu_surface_backend_texture,
             &create_gpu_surface_backend_texture_as_render_target }) {
        // Validate that we can draw to the canvas and that the original texture color is
        // preserved in pixels that aren't rendered to via the surface.
        // This works only for non-multisampled case.
        GrBackendObject textureObject;
        auto surface = surfaceFunc(ctxInfo.grContext(), 0, kOrigColor, &textureObject);
        if (surface) {
            test_surface_draw_partially(reporter, surface, kOrigColor);
            surface.reset();
            gpu->deleteTestingOnlyBackendTexture(textureObject);
        }
    }
}

DEF_GPUTEST_FOR_GL_RENDERING_CONTEXTS(SurfaceAttachStencil_Gpu, reporter, ctxInfo)
{
    GrGpu* gpu = ctxInfo.grContext()->getGpu();
    if (!gpu) {
        return;
    }
    static const uint32_t kOrigColor = 0xFFAABBCC;

    for (auto& surfaceFunc : { &create_gpu_surface_backend_texture,
             &create_gpu_surface_backend_texture_as_render_target }) {
        for (int sampleCnt : { 0, 4, 8 }) {
            GrBackendObject textureObject;
            auto surface = surfaceFunc(ctxInfo.grContext(), sampleCnt, kOrigColor, &textureObject);

            if (!surface && sampleCnt > 0) {
                // Certain platforms don't support MSAA, skip these.
                continue;
            }

            // Validate that we can attach a stencil buffer to an SkSurface created by either of
            // our surface functions.
            GrRenderTarget* rt = surface->getCanvas()->internal_private_accessTopLayerDrawContext()->accessRenderTarget();
            REPORTER_ASSERT(reporter,
                ctxInfo.grContext()->resourceProvider()->attachStencilAttachment(rt));
            gpu->deleteTestingOnlyBackendTexture(textureObject);
        }
    }
=======

#endif

static void TestSurfaceNoCanvas(skiatest::Reporter* reporter,
                                          SurfaceType surfaceType,
                                          GrContext* context,
                                          SkSurface::ContentChangeMode mode) {
    // Verifies the robustness of SkSurface for handling use cases where calls
    // are made before a canvas is created.
    {
        // Test passes by not asserting
        SkSurface* surface = create_surface(surfaceType, context);
        SkAutoTUnref<SkSurface> aur_surface(surface);
        surface->notifyContentWillChange(mode);
        SkDEBUGCODE(surface->validate();)
    }
    {
        SkSurface* surface = create_surface(surfaceType, context);
        SkAutoTUnref<SkSurface> aur_surface(surface);
        SkImage* image1 = surface->newImageSnapshot();
        SkAutoTUnref<SkImage> aur_image1(image1);
        SkDEBUGCODE(image1->validate();)
        SkDEBUGCODE(surface->validate();)
        surface->notifyContentWillChange(mode);
        SkDEBUGCODE(image1->validate();)
        SkDEBUGCODE(surface->validate();)
        SkImage* image2 = surface->newImageSnapshot();
        SkAutoTUnref<SkImage> aur_image2(image2);
        SkDEBUGCODE(image2->validate();)
        SkDEBUGCODE(surface->validate();)
        REPORTER_ASSERT(reporter, image1 != image2);
    }

}

DEF_GPUTEST(Surface, reporter, factory) {
    test_image(reporter);

    TestSurfaceCopyOnWrite(reporter, kRaster_SurfaceType, NULL);
    TestSurfaceWritableAfterSnapshotRelease(reporter, kRaster_SurfaceType, NULL);
    TestSurfaceNoCanvas(reporter, kRaster_SurfaceType, NULL, SkSurface::kDiscard_ContentChangeMode);
    TestSurfaceNoCanvas(reporter, kRaster_SurfaceType, NULL, SkSurface::kRetain_ContentChangeMode);

    test_empty_image(reporter);
    test_empty_surface(reporter, NULL);

    test_imagepeek(reporter, factory);
    test_canvaspeek(reporter, factory);

    test_accessPixels(reporter, factory);

    test_snap_alphatype(reporter, factory);

#if SK_SUPPORT_GPU
    TestGetTexture(reporter, kRaster_SurfaceType, NULL);
    if (factory) {
        for (int i= 0; i < GrContextFactory::kGLContextTypeCnt; ++i) {
            GrContextFactory::GLContextType glCtxType = (GrContextFactory::GLContextType) i;
            if (!GrContextFactory::IsRenderingGLContext(glCtxType)) {
                continue;
            }
            GrContext* context = factory->get(glCtxType);
            if (context) {
                Test_crbug263329(reporter, kGpu_SurfaceType, context);
                Test_crbug263329(reporter, kGpuScratch_SurfaceType, context);
                TestSurfaceCopyOnWrite(reporter, kGpu_SurfaceType, context);
                TestSurfaceCopyOnWrite(reporter, kGpuScratch_SurfaceType, context);
                TestSurfaceWritableAfterSnapshotRelease(reporter, kGpu_SurfaceType, context);
                TestSurfaceWritableAfterSnapshotRelease(reporter, kGpuScratch_SurfaceType, context);
                TestSurfaceNoCanvas(reporter, kGpu_SurfaceType, context, SkSurface::kDiscard_ContentChangeMode);
                TestSurfaceNoCanvas(reporter, kGpuScratch_SurfaceType, context, SkSurface::kDiscard_ContentChangeMode);
                TestSurfaceNoCanvas(reporter, kGpu_SurfaceType, context, SkSurface::kRetain_ContentChangeMode);
                TestSurfaceNoCanvas(reporter, kGpuScratch_SurfaceType, context, SkSurface::kRetain_ContentChangeMode);
                TestGetTexture(reporter, kGpu_SurfaceType, context);
                TestGetTexture(reporter, kGpuScratch_SurfaceType, context);
                test_empty_surface(reporter, context);
                test_surface_budget(reporter, context);
                test_wrapped_texture_surface(reporter, context);
            }
        }
    }
#endif
}

#if SK_SUPPORT_GPU

struct ReleaseTextureContext {
    ReleaseTextureContext(skiatest::Reporter* reporter) {
        fReporter = reporter;
        fIsReleased = false;
    }

    skiatest::Reporter* fReporter;
    bool                fIsReleased;

    void doRelease() {
        REPORTER_ASSERT(fReporter, false == fIsReleased);
        fIsReleased = true;
    }

    static void ReleaseProc(void* context) {
        ((ReleaseTextureContext*)context)->doRelease();
    }
};

static SkImage* make_desc_image(GrContext* ctx, int w, int h, GrBackendObject texID,
                                ReleaseTextureContext* releaseContext) {
    GrBackendTextureDesc desc;
    desc.fConfig = kSkia8888_GrPixelConfig;
    // need to be a rendertarget for now...
    desc.fFlags = kRenderTarget_GrBackendTextureFlag;
    desc.fWidth = w;
    desc.fHeight = h;
    desc.fSampleCnt = 0;
    desc.fTextureHandle = texID;
    return releaseContext
                ? SkImage::NewFromTexture(ctx, desc, kPremul_SkAlphaType,
                                          ReleaseTextureContext::ReleaseProc, releaseContext)
                : SkImage::NewFromTextureCopy(ctx, desc, kPremul_SkAlphaType);
}

static void test_image_color(skiatest::Reporter* reporter, SkImage* image, SkPMColor expected) {
    const SkImageInfo info = SkImageInfo::MakeN32Premul(1, 1);
    SkPMColor pixel;
    REPORTER_ASSERT(reporter, image->readPixels(info, &pixel, sizeof(pixel), 0, 0));
    REPORTER_ASSERT(reporter, pixel == expected);
}

DEF_GPUTEST(SkImage_NewFromTexture, reporter, factory) {
    GrContext* ctx = factory->get(GrContextFactory::kNative_GLContextType);
    if (!ctx) {
        REPORTER_ASSERT(reporter, false);
        return;
    }
    GrTextureProvider* provider = ctx->textureProvider();
    
    const int w = 10;
    const int h = 10;
    SkPMColor storage[w * h];
    const SkPMColor expected0 = SkPreMultiplyColor(SK_ColorRED);
    sk_memset32(storage, expected0, w * h);
    
    GrSurfaceDesc desc;
    desc.fFlags = kRenderTarget_GrSurfaceFlag;  // needs to be a rendertarget for readpixels();
    desc.fOrigin = kDefault_GrSurfaceOrigin;
    desc.fWidth = w;
    desc.fHeight = h;
    desc.fConfig = kSkia8888_GrPixelConfig;
    desc.fSampleCnt = 0;
    
    SkAutoTUnref<GrTexture> tex(provider->createTexture(desc, false, storage, w * 4));
    if (!tex) {
        REPORTER_ASSERT(reporter, false);
        return;
    }

    GrBackendObject srcTex = tex->getTextureHandle();
    ReleaseTextureContext releaseCtx(reporter);

    SkAutoTUnref<SkImage> refImg(make_desc_image(ctx, w, h, srcTex, &releaseCtx));
    SkAutoTUnref<SkImage> cpyImg(make_desc_image(ctx, w, h, srcTex, NULL));

    test_image_color(reporter, refImg, expected0);
    test_image_color(reporter, cpyImg, expected0);

    // Now lets jam new colors into our "external" texture, and see if the images notice
    const SkPMColor expected1 = SkPreMultiplyColor(SK_ColorBLUE);
    sk_memset32(storage, expected1, w * h);
    tex->writePixels(0, 0, w, h, kSkia8888_GrPixelConfig, storage, GrContext::kFlushWrites_PixelOp);

    // We expect the ref'd image to see the new color, but cpy'd one should still see the old color
    test_image_color(reporter, refImg, expected1);
    test_image_color(reporter, cpyImg, expected0);

    // Now exercise the release proc
    REPORTER_ASSERT(reporter, !releaseCtx.fIsReleased);
    refImg.reset(NULL); // force a release of the image
    REPORTER_ASSERT(reporter, releaseCtx.fIsReleased);
>>>>>>> miniblink49
}
#endif
