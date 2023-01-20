/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
#include "SkBlurDrawLooper.h"
#include "SkBlurMask.h"
#include "SkBlurMaskFilter.h"
#include "SkCanvas.h"
#include "SkEmbossMaskFilter.h"
#include "SkLayerDrawLooper.h"
#include "SkMath.h"
#include "SkPaint.h"
#include "SkPath.h"
=======
#include "SkBlurMask.h"
#include "SkBlurMaskFilter.h"
#include "SkBlurDrawLooper.h"
#include "SkLayerDrawLooper.h"
#include "SkEmbossMaskFilter.h"
#include "SkCanvas.h"
#include "SkMath.h"
#include "SkPaint.h"
>>>>>>> miniblink49
#include "Test.h"

#if SK_SUPPORT_GPU
#include "GrContextFactory.h"
#include "SkGpuDevice.h"
#endif

#define WRITE_CSV 0

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
#define ILLEGAL_MODE ((SkXfermode::Mode)-1)
=======
#define ILLEGAL_MODE    ((SkXfermode::Mode)-1)
>>>>>>> miniblink49

static const int outset = 100;
static const SkColor bgColor = SK_ColorWHITE;
static const int strokeWidth = 4;

<<<<<<< HEAD
static void create(SkBitmap* bm, const SkIRect& bound)
{
    bm->allocN32Pixels(bound.width(), bound.height());
}

static void drawBG(SkCanvas* canvas)
{
    canvas->drawColor(bgColor);
}

=======
static void create(SkBitmap* bm, const SkIRect& bound) {
    bm->allocN32Pixels(bound.width(), bound.height());
}

static void drawBG(SkCanvas* canvas) {
    canvas->drawColor(bgColor);
}


>>>>>>> miniblink49
struct BlurTest {
    void (*addPath)(SkPath*);
    int viewLen;
    SkIRect views[9];
};

//Path Draw Procs
//Beware that paths themselves my draw differently depending on the clip.
<<<<<<< HEAD
static void draw50x50Rect(SkPath* path)
{
=======
static void draw50x50Rect(SkPath* path) {
>>>>>>> miniblink49
    path->addRect(0, 0, SkIntToScalar(50), SkIntToScalar(50));
}

//Tests
static BlurTest tests[] = {
    { draw50x50Rect, 3, {
<<<<<<< HEAD
                            //inner half of blur
                            { 0, 0, 50, 50 },
                            //blur, but no path.
                            { 50 + strokeWidth / 2, 50 + strokeWidth / 2, 100, 100 },
                            //just an edge
                            { 40, strokeWidth, 60, 50 - strokeWidth },
                        } },
=======
        //inner half of blur
        { 0, 0, 50, 50 },
        //blur, but no path.
        { 50 + strokeWidth/2, 50 + strokeWidth/2, 100, 100 },
        //just an edge
        { 40, strokeWidth, 60, 50 - strokeWidth },
    }},
>>>>>>> miniblink49
};

/** Assumes that the ref draw was completely inside ref canvas --
    implies that everything outside is "bgColor".
    Checks that all overlap is the same and that all non-overlap on the
    ref is "bgColor".
 */
static bool compare(const SkBitmap& ref, const SkIRect& iref,
<<<<<<< HEAD
    const SkBitmap& test, const SkIRect& itest)
=======
                    const SkBitmap& test, const SkIRect& itest)
>>>>>>> miniblink49
{
    const int xOff = itest.fLeft - iref.fLeft;
    const int yOff = itest.fTop - iref.fTop;

    SkAutoLockPixels alpRef(ref);
    SkAutoLockPixels alpTest(test);

    for (int y = 0; y < test.height(); ++y) {
        for (int x = 0; x < test.width(); ++x) {
            SkColor testColor = test.getColor(x, y);
            int refX = x + xOff;
            int refY = y + yOff;
            SkColor refColor;
<<<<<<< HEAD
            if (refX >= 0 && refX < ref.width() && refY >= 0 && refY < ref.height()) {
=======
            if (refX >= 0 && refX < ref.width() &&
                refY >= 0 && refY < ref.height())
            {
>>>>>>> miniblink49
                refColor = ref.getColor(refX, refY);
            } else {
                refColor = bgColor;
            }
            if (refColor != testColor) {
                return false;
            }
        }
    }
    return true;
}

<<<<<<< HEAD
DEF_TEST(BlurDrawing, reporter)
{
=======
static void test_blur_drawing(skiatest::Reporter* reporter) {

>>>>>>> miniblink49
    SkPaint paint;
    paint.setColor(SK_ColorGRAY);
    paint.setStyle(SkPaint::kStroke_Style);
    paint.setStrokeWidth(SkIntToScalar(strokeWidth));

    SkScalar sigma = SkBlurMask::ConvertRadiusToSigma(SkIntToScalar(5));
    for (int style = 0; style <= kLastEnum_SkBlurStyle; ++style) {
        SkBlurStyle blurStyle = static_cast<SkBlurStyle>(style);

        const uint32_t flagPermutations = SkBlurMaskFilter::kAll_BlurFlag;
        for (uint32_t flags = 0; flags < flagPermutations; ++flags) {
<<<<<<< HEAD
            paint.setMaskFilter(SkBlurMaskFilter::Make(blurStyle, sigma, flags));
=======
            SkMaskFilter* filter;
            filter = SkBlurMaskFilter::Create(blurStyle, sigma, flags);

            paint.setMaskFilter(filter);
            filter->unref();
>>>>>>> miniblink49

            for (size_t test = 0; test < SK_ARRAY_COUNT(tests); ++test) {
                SkPath path;
                tests[test].addPath(&path);
                SkPath strokedPath;
                paint.getFillPath(path, &strokedPath);
                SkRect refBound = strokedPath.getBounds();
                SkIRect iref;
                refBound.roundOut(&iref);
                iref.inset(-outset, -outset);
                SkBitmap refBitmap;
                create(&refBitmap, iref);

                SkCanvas refCanvas(refBitmap);
                refCanvas.translate(SkIntToScalar(-iref.fLeft),
<<<<<<< HEAD
                    SkIntToScalar(-iref.fTop));
=======
                                    SkIntToScalar(-iref.fTop));
>>>>>>> miniblink49
                drawBG(&refCanvas);
                refCanvas.drawPath(path, paint);

                for (int view = 0; view < tests[test].viewLen; ++view) {
                    SkIRect itest = tests[test].views[view];
                    SkBitmap testBitmap;
                    create(&testBitmap, itest);

                    SkCanvas testCanvas(testBitmap);
                    testCanvas.translate(SkIntToScalar(-itest.fLeft),
<<<<<<< HEAD
                        SkIntToScalar(-itest.fTop));
=======
                                         SkIntToScalar(-itest.fTop));
>>>>>>> miniblink49
                    drawBG(&testCanvas);
                    testCanvas.drawPath(path, paint);

                    REPORTER_ASSERT(reporter,
                        compare(refBitmap, iref, testBitmap, itest));
                }
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////

// Use SkBlurMask::BlurGroundTruth to blur a 'width' x 'height' solid
// white rect. Return the right half of the middle row in 'result'.
static void ground_truth_2d(int width, int height,
<<<<<<< HEAD
    SkScalar sigma,
    int* result, int resultCount)
{
=======
                            SkScalar sigma,
                            int* result, int resultCount) {
>>>>>>> miniblink49
    SkMask src, dst;

    src.fBounds.set(0, 0, width, height);
    src.fFormat = SkMask::kA8_Format;
    src.fRowBytes = src.fBounds.width();
    src.fImage = SkMask::AllocImage(src.computeTotalImageSize());

    memset(src.fImage, 0xff, src.computeTotalImageSize());

<<<<<<< HEAD
    if (!SkBlurMask::BlurGroundTruth(sigma, &dst, src, kNormal_SkBlurStyle)) {
        return;
    }
=======
    dst.fImage = NULL;
    SkBlurMask::BlurGroundTruth(sigma, &dst, src, kNormal_SkBlurStyle);
>>>>>>> miniblink49

    int midX = dst.fBounds.centerX();
    int midY = dst.fBounds.centerY();
    uint8_t* bytes = dst.getAddr8(midX, midY);
    int i;
<<<<<<< HEAD
    for (i = 0; i < dst.fBounds.width() - (midX - dst.fBounds.fLeft); ++i) {
=======
    for (i = 0; i < dst.fBounds.width()-(midX-dst.fBounds.fLeft); ++i) {
>>>>>>> miniblink49
        if (i < resultCount) {
            result[i] = bytes[i];
        }
    }
<<<<<<< HEAD
    for (; i < resultCount; ++i) {
=======
    for ( ; i < resultCount; ++i) {
>>>>>>> miniblink49
        result[i] = 0;
    }

    SkMask::FreeImage(src.fImage);
    SkMask::FreeImage(dst.fImage);
}

// Implement a step function that is 255 between min and max; 0 elsewhere.
<<<<<<< HEAD
static int step(int x, SkScalar min, SkScalar max)
{
=======
static int step(int x, SkScalar min, SkScalar max) {
>>>>>>> miniblink49
    if (min < x && x < max) {
        return 255;
    }
    return 0;
}

// Implement a Gaussian function with 0 mean and std.dev. of 'sigma'.
<<<<<<< HEAD
static float gaussian(int x, SkScalar sigma)
{
    float k = SK_Scalar1 / (sigma * sqrtf(2.0f * SK_ScalarPI));
=======
static float gaussian(int x, SkScalar sigma) {
    float k = SK_Scalar1/(sigma * sqrtf(2.0f*SK_ScalarPI));
>>>>>>> miniblink49
    float exponent = -(x * x) / (2 * sigma * sigma);
    return k * expf(exponent);
}

// Perform a brute force convolution of a step function with a Gaussian.
// Return the right half in 'result'
static void brute_force_1d(SkScalar stepMin, SkScalar stepMax,
<<<<<<< HEAD
    SkScalar gaussianSigma,
    int* result, int resultCount)
{
=======
                           SkScalar gaussianSigma,
                           int* result, int resultCount) {
>>>>>>> miniblink49

    int gaussianRange = SkScalarCeilToInt(10 * gaussianSigma);

    for (int i = 0; i < resultCount; ++i) {
        SkScalar sum = 0.0f;
        for (int j = -gaussianRange; j < gaussianRange; ++j) {
<<<<<<< HEAD
            sum += gaussian(j, gaussianSigma) * step(i - j, stepMin, stepMax);
=======
            sum += gaussian(j, gaussianSigma) * step(i-j, stepMin, stepMax);
>>>>>>> miniblink49
        }

        result[i] = SkClampMax(SkClampPos(int(sum + 0.5f)), 255);
    }
}

static void blur_path(SkCanvas* canvas, const SkPath& path,
<<<<<<< HEAD
    SkScalar gaussianSigma)
{
=======
                      SkScalar gaussianSigma) {
>>>>>>> miniblink49

    SkScalar midX = path.getBounds().centerX();
    SkScalar midY = path.getBounds().centerY();

    canvas->translate(-midX, -midY);

    SkPaint blurPaint;
    blurPaint.setColor(SK_ColorWHITE);
<<<<<<< HEAD
    blurPaint.setMaskFilter(SkBlurMaskFilter::Make(kNormal_SkBlurStyle, gaussianSigma,
        SkBlurMaskFilter::kHighQuality_BlurFlag));
=======
    SkMaskFilter* filter = SkBlurMaskFilter::Create(kNormal_SkBlurStyle,
                                                    gaussianSigma,
                                                    SkBlurMaskFilter::kHighQuality_BlurFlag);
    blurPaint.setMaskFilter(filter)->unref();
>>>>>>> miniblink49

    canvas->drawColor(SK_ColorBLACK);
    canvas->drawPath(path, blurPaint);
}

// Readback the blurred draw results from the canvas
<<<<<<< HEAD
static void readback(SkCanvas* canvas, int* result, int resultCount)
{
=======
static void readback(SkCanvas* canvas, int* result, int resultCount) {
>>>>>>> miniblink49
    SkBitmap readback;
    readback.allocN32Pixels(resultCount, 30);

    SkIRect readBackRect = { 0, 0, resultCount, 30 };

    canvas->readPixels(readBackRect, &readback);

    readback.lockPixels();
<<<<<<< HEAD
    SkPMColor* pixels = (SkPMColor*)readback.getAddr32(0, 15);
=======
    SkPMColor* pixels = (SkPMColor*) readback.getAddr32(0, 15);
>>>>>>> miniblink49

    for (int i = 0; i < resultCount; ++i) {
        result[i] = SkColorGetR(pixels[i]);
    }
}

// Draw a blurred version of the provided path.
// Return the right half of the middle row in 'result'.
static void cpu_blur_path(const SkPath& path, SkScalar gaussianSigma,
<<<<<<< HEAD
    int* result, int resultCount)
{
=======
                          int* result, int resultCount) {
>>>>>>> miniblink49

    SkBitmap bitmap;
    bitmap.allocN32Pixels(resultCount, 30);
    SkCanvas canvas(bitmap);

    blur_path(&canvas, path, gaussianSigma);
    readback(&canvas, result, resultCount);
}

#if SK_SUPPORT_GPU
#if 0
// temporary disable; see below for explanation
<<<<<<< HEAD
static bool gpu_blur_path(GrContext* context, const SkPath& path,
                          SkScalar gaussianSigma,
                          int* result, int resultCount) {
=======
static bool gpu_blur_path(GrContextFactory* factory, const SkPath& path,
                          SkScalar gaussianSigma,
                          int* result, int resultCount) {

    GrContext* grContext = factory->get(GrContextFactory::kNative_GLContextType);
    if (NULL == grContext) {
        return false;
    }

>>>>>>> miniblink49
    GrSurfaceDesc desc;
    desc.fConfig = kSkia8888_GrPixelConfig;
    desc.fFlags = kRenderTarget_GrSurfaceFlag;
    desc.fWidth = resultCount;
    desc.fHeight = 30;
    desc.fSampleCnt = 0;

<<<<<<< HEAD
    SkAutoTUnref<GrTexture> texture(grContext->createTexture(desc, false, nullptr, 0));
    SkAutoTUnref<SkGpuDevice> device(new SkGpuDevice  (grContext, texture.get()));
=======
    SkAutoTUnref<GrTexture> texture(grContext->createTexture(desc, false, NULL, 0));
    SkAutoTUnref<SkGpuDevice> device(SkNEW_ARGS(SkGpuDevice, (grContext, texture.get())));
>>>>>>> miniblink49
    SkCanvas canvas(device.get());

    blur_path(&canvas, path, gaussianSigma);
    readback(&canvas, result, resultCount);
    return true;
}
#endif
#endif

#if WRITE_CSV
<<<<<<< HEAD
static void write_as_csv(const char* label, SkScalar scale, int* data, int count)
{
    SkDebugf("%s_%.2f,", label, scale);
    for (int i = 0; i < count - 1; ++i) {
        SkDebugf("%d,", data[i]);
    }
    SkDebugf("%d\n", data[count - 1]);
}
#endif

static bool match(int* first, int* second, int count, int tol)
{
=======
static void write_as_csv(const char* label, SkScalar scale, int* data, int count) {
    SkDebugf("%s_%.2f,", label, scale);
    for (int i = 0; i < count-1; ++i) {
        SkDebugf("%d,", data[i]);
    }
    SkDebugf("%d\n", data[count-1]);
}
#endif

static bool match(int* first, int* second, int count, int tol) {
>>>>>>> miniblink49
    int delta;
    for (int i = 0; i < count; ++i) {
        delta = first[i] - second[i];
        if (delta > tol || delta < -tol) {
            return false;
        }
    }

    return true;
}

// Test out the normal blur style with a wide range of sigmas
<<<<<<< HEAD
DEF_TEST(BlurSigmaRange, reporter)
{
=======
static void test_sigma_range(skiatest::Reporter* reporter, GrContextFactory* factory) {

>>>>>>> miniblink49
    static const int kSize = 100;

    // The geometry is offset a smidge to trigger:
    // https://code.google.com/p/chromium/issues/detail?id=282418
    SkPath rectPath;
    rectPath.addRect(0.3f, 0.3f, 100.3f, 100.3f);

    SkPoint polyPts[] = {
        { 0.3f, 0.3f },
        { 100.3f, 0.3f },
        { 100.3f, 100.3f },
        { 0.3f, 100.3f },
<<<<<<< HEAD
        { 2.3f, 50.3f } // a little divet to throw off the rect special case
=======
        { 2.3f, 50.3f }     // a little divet to throw off the rect special case
>>>>>>> miniblink49
    };
    SkPath polyPath;
    polyPath.addPoly(polyPts, SK_ARRAY_COUNT(polyPts), true);

    int rectSpecialCaseResult[kSize];
    int generalCaseResult[kSize];
    int groundTruthResult[kSize];
    int bruteForce1DResult[kSize];

    SkScalar sigma = 10.0f;

    for (int i = 0; i < 4; ++i, sigma /= 10) {

        cpu_blur_path(rectPath, sigma, rectSpecialCaseResult, kSize);
        cpu_blur_path(polyPath, sigma, generalCaseResult, kSize);

        ground_truth_2d(100, 100, sigma, groundTruthResult, kSize);
        brute_force_1d(-50.0f, 50.0f, sigma, bruteForce1DResult, kSize);

        REPORTER_ASSERT(reporter, match(rectSpecialCaseResult, bruteForce1DResult, kSize, 5));
        REPORTER_ASSERT(reporter, match(generalCaseResult, bruteForce1DResult, kSize, 15));
#if SK_SUPPORT_GPU
#if 0
        int gpuResult[kSize];
<<<<<<< HEAD
        bool haveGPUResult = gpu_blur_path(context, rectPath, sigma, gpuResult, kSize);
=======
        bool haveGPUResult = gpu_blur_path(factory, rectPath, sigma, gpuResult, kSize);
>>>>>>> miniblink49
        // Disabling this test for now -- I don't think it's a legit comparison.
        // Will continue to investigate this.
        if (haveGPUResult) {
            // 1 works everywhere but: Ubuntu13 & Nexus4
            REPORTER_ASSERT(reporter, match(gpuResult, bruteForce1DResult, kSize, 10));
        }
#endif
#endif
        REPORTER_ASSERT(reporter, match(groundTruthResult, bruteForce1DResult, kSize, 1));

#if WRITE_CSV
        write_as_csv("RectSpecialCase", sigma, rectSpecialCaseResult, kSize);
        write_as_csv("GeneralCase", sigma, generalCaseResult, kSize);
#if SK_SUPPORT_GPU
        write_as_csv("GPU", sigma, gpuResult, kSize);
#endif
        write_as_csv("GroundTruth2D", sigma, groundTruthResult, kSize);
        write_as_csv("BruteForce1D", sigma, bruteForce1DResult, kSize);
#endif
    }
}

///////////////////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
static SkBlurQuality blurMaskFilterFlags_as_quality(uint32_t blurMaskFilterFlags)
{
    return (blurMaskFilterFlags & SkBlurMaskFilter::kHighQuality_BlurFlag) ? kHigh_SkBlurQuality : kLow_SkBlurQuality;
}

static uint32_t blurMaskFilterFlags_to_blurDrawLooperFlags(uint32_t bmf)
{
=======
static SkBlurQuality blurMaskFilterFlags_as_quality(uint32_t blurMaskFilterFlags) {
    return (blurMaskFilterFlags & SkBlurMaskFilter::kHighQuality_BlurFlag) ?
            kHigh_SkBlurQuality : kLow_SkBlurQuality;
}

static uint32_t blurMaskFilterFlags_to_blurDrawLooperFlags(uint32_t bmf) {
>>>>>>> miniblink49
    const struct {
        uint32_t fBlurMaskFilterFlag;
        uint32_t fBlurDrawLooperFlag;
    } pairs[] = {
        { SkBlurMaskFilter::kIgnoreTransform_BlurFlag, SkBlurDrawLooper::kIgnoreTransform_BlurFlag },
<<<<<<< HEAD
        { SkBlurMaskFilter::kHighQuality_BlurFlag, SkBlurDrawLooper::kHighQuality_BlurFlag },
=======
        { SkBlurMaskFilter::kHighQuality_BlurFlag,     SkBlurDrawLooper::kHighQuality_BlurFlag },
>>>>>>> miniblink49
    };

    uint32_t bdl = 0;
    for (size_t i = 0; i < SK_ARRAY_COUNT(pairs); ++i) {
        if (bmf & pairs[i].fBlurMaskFilterFlag) {
            bdl |= pairs[i].fBlurDrawLooperFlag;
        }
    }
    return bdl;
}

static void test_blurDrawLooper(skiatest::Reporter* reporter, SkScalar sigma,
<<<<<<< HEAD
    SkBlurStyle style, uint32_t blurMaskFilterFlags)
{
=======
                                SkBlurStyle style, uint32_t blurMaskFilterFlags) {
>>>>>>> miniblink49
    if (kNormal_SkBlurStyle != style) {
        return; // blurdrawlooper only supports normal
    }

    const SkColor color = 0xFF335577;
    const SkScalar dx = 10;
    const SkScalar dy = -5;
    const SkBlurQuality quality = blurMaskFilterFlags_as_quality(blurMaskFilterFlags);
    uint32_t flags = blurMaskFilterFlags_to_blurDrawLooperFlags(blurMaskFilterFlags);

<<<<<<< HEAD
    sk_sp<SkDrawLooper> lp(SkBlurDrawLooper::Make(color, sigma, dx, dy, flags));

    const bool expectSuccess = sigma > 0 && 0 == (flags & SkBlurDrawLooper::kIgnoreTransform_BlurFlag);

    if (nullptr == lp) {
=======
    SkAutoTUnref<SkDrawLooper> lp(SkBlurDrawLooper::Create(color, sigma, dx, dy, flags));

    const bool expectSuccess = sigma > 0 &&
                               0 == (flags & SkBlurDrawLooper::kIgnoreTransform_BlurFlag);

    if (NULL == lp.get()) {
>>>>>>> miniblink49
        REPORTER_ASSERT(reporter, sigma <= 0);
    } else {
        SkDrawLooper::BlurShadowRec rec;
        bool success = lp->asABlurShadow(&rec);
        REPORTER_ASSERT(reporter, success == expectSuccess);
        if (success) {
            REPORTER_ASSERT(reporter, rec.fSigma == sigma);
            REPORTER_ASSERT(reporter, rec.fOffset.x() == dx);
            REPORTER_ASSERT(reporter, rec.fOffset.y() == dy);
            REPORTER_ASSERT(reporter, rec.fColor == color);
            REPORTER_ASSERT(reporter, rec.fStyle == style);
            REPORTER_ASSERT(reporter, rec.fQuality == quality);
        }
    }
}

<<<<<<< HEAD
static void test_looper(skiatest::Reporter* reporter, sk_sp<SkDrawLooper> lp, SkScalar sigma,
    SkBlurStyle style, SkBlurQuality quality, bool expectSuccess)
{
=======
static void test_delete_looper(skiatest::Reporter* reporter, SkDrawLooper* lp, SkScalar sigma,
                               SkBlurStyle style, SkBlurQuality quality, bool expectSuccess) {
>>>>>>> miniblink49
    SkDrawLooper::BlurShadowRec rec;
    bool success = lp->asABlurShadow(&rec);
    REPORTER_ASSERT(reporter, success == expectSuccess);
    if (success != expectSuccess) {
        lp->asABlurShadow(&rec);
    }
    if (success) {
        REPORTER_ASSERT(reporter, rec.fSigma == sigma);
        REPORTER_ASSERT(reporter, rec.fStyle == style);
        REPORTER_ASSERT(reporter, rec.fQuality == quality);
    }
<<<<<<< HEAD
}

static void make_noop_layer(SkLayerDrawLooper::Builder* builder)
{
=======
    lp->unref();
}

static void make_noop_layer(SkLayerDrawLooper::Builder* builder) {
>>>>>>> miniblink49
    SkLayerDrawLooper::LayerInfo info;

    info.fPaintBits = 0;
    info.fColorMode = SkXfermode::kDst_Mode;
    builder->addLayer(info);
}

<<<<<<< HEAD
static void make_blur_layer(SkLayerDrawLooper::Builder* builder, sk_sp<SkMaskFilter> mf)
{
=======
static void make_blur_layer(SkLayerDrawLooper::Builder* builder, SkMaskFilter* mf) {
>>>>>>> miniblink49
    SkLayerDrawLooper::LayerInfo info;

    info.fPaintBits = SkLayerDrawLooper::kMaskFilter_Bit;
    info.fColorMode = SkXfermode::kSrc_Mode;
    SkPaint* paint = builder->addLayer(info);
<<<<<<< HEAD
    paint->setMaskFilter(std::move(mf));
}

static void test_layerDrawLooper(skiatest::Reporter* reporter, sk_sp<SkMaskFilter> mf,
    SkScalar sigma, SkBlurStyle style, SkBlurQuality quality,
    bool expectSuccess)
{
=======
    paint->setMaskFilter(mf);
}

static void test_layerDrawLooper(skiatest::Reporter* reporter, SkMaskFilter* mf, SkScalar sigma,
                                 SkBlurStyle style, SkBlurQuality quality, bool expectSuccess) {
>>>>>>> miniblink49

    SkLayerDrawLooper::LayerInfo info;
    SkLayerDrawLooper::Builder builder;

    // 1 layer is too few
    make_noop_layer(&builder);
<<<<<<< HEAD
    test_looper(reporter, builder.detach(), sigma, style, quality, false);
=======
    test_delete_looper(reporter, builder.detachLooper(), sigma, style, quality, false);
>>>>>>> miniblink49

    // 2 layers is good, but need blur
    make_noop_layer(&builder);
    make_noop_layer(&builder);
<<<<<<< HEAD
    test_looper(reporter, builder.detach(), sigma, style, quality, false);
=======
    test_delete_looper(reporter, builder.detachLooper(), sigma, style, quality, false);
>>>>>>> miniblink49

    // 2 layers is just right
    make_noop_layer(&builder);
    make_blur_layer(&builder, mf);
<<<<<<< HEAD
    test_looper(reporter, builder.detach(), sigma, style, quality, expectSuccess);
=======
    test_delete_looper(reporter, builder.detachLooper(), sigma, style, quality, expectSuccess);
>>>>>>> miniblink49

    // 3 layers is too many
    make_noop_layer(&builder);
    make_blur_layer(&builder, mf);
    make_noop_layer(&builder);
<<<<<<< HEAD
    test_looper(reporter, builder.detach(), sigma, style, quality, false);
}

DEF_TEST(BlurAsABlur, reporter)
{
=======
    test_delete_looper(reporter, builder.detachLooper(), sigma, style, quality, false);
}

static void test_asABlur(skiatest::Reporter* reporter) {
>>>>>>> miniblink49
    const SkBlurStyle styles[] = {
        kNormal_SkBlurStyle, kSolid_SkBlurStyle, kOuter_SkBlurStyle, kInner_SkBlurStyle
    };
    const SkScalar sigmas[] = {
        // values <= 0 should not success for a blur
        -1, 0, 0.5f, 2
    };

    // Test asABlur for SkBlurMaskFilter
    //
    for (size_t i = 0; i < SK_ARRAY_COUNT(styles); ++i) {
        const SkBlurStyle style = (SkBlurStyle)styles[i];
        for (size_t j = 0; j < SK_ARRAY_COUNT(sigmas); ++j) {
            const SkScalar sigma = sigmas[j];
            for (int flags = 0; flags <= SkBlurMaskFilter::kAll_BlurFlag; ++flags) {
                const SkBlurQuality quality = blurMaskFilterFlags_as_quality(flags);

<<<<<<< HEAD
                sk_sp<SkMaskFilter> mf(SkBlurMaskFilter::Make(style, sigma, flags));
                if (nullptr == mf.get()) {
=======
                SkAutoTUnref<SkMaskFilter> mf(SkBlurMaskFilter::Create(style, sigma, flags));
                if (NULL == mf.get()) {
>>>>>>> miniblink49
                    REPORTER_ASSERT(reporter, sigma <= 0);
                } else {
                    REPORTER_ASSERT(reporter, sigma > 0);
                    SkMaskFilter::BlurRec rec;
                    bool success = mf->asABlur(&rec);
                    if (flags & SkBlurMaskFilter::kIgnoreTransform_BlurFlag) {
                        REPORTER_ASSERT(reporter, !success);
                    } else {
                        REPORTER_ASSERT(reporter, success);
                        REPORTER_ASSERT(reporter, rec.fSigma == sigma);
                        REPORTER_ASSERT(reporter, rec.fStyle == style);
                        REPORTER_ASSERT(reporter, rec.fQuality == quality);
                    }
<<<<<<< HEAD
                    test_layerDrawLooper(reporter, std::move(mf), sigma, style, quality, success);
=======
                    test_layerDrawLooper(reporter, mf, sigma, style, quality, success);
>>>>>>> miniblink49
                }
                test_blurDrawLooper(reporter, sigma, style, flags);
            }
        }
    }

    // Test asABlur for SkEmbossMaskFilter -- should never succeed
    //
    {
        SkEmbossMaskFilter::Light light = {
            { 1, 1, 1 }, 0, 127, 127
        };
        for (size_t j = 0; j < SK_ARRAY_COUNT(sigmas); ++j) {
            const SkScalar sigma = sigmas[j];
<<<<<<< HEAD
            auto mf(SkEmbossMaskFilter::Make(sigma, light));
            if (mf) {
=======
            SkAutoTUnref<SkMaskFilter> mf(SkEmbossMaskFilter::Create(sigma, light));
            if (mf.get()) {
>>>>>>> miniblink49
                SkMaskFilter::BlurRec rec;
                bool success = mf->asABlur(&rec);
                REPORTER_ASSERT(reporter, !success);
            }
        }
    }
}

<<<<<<< HEAD
#if SK_SUPPORT_GPU

// This exercises the problem discovered in crbug.com/570232. The return value from
// SkBlurMask::BoxBlur wasn't being checked in SkBlurMaskFilter.cpp::GrRRectBlurEffect::Create
DEF_GPUTEST_FOR_RENDERING_CONTEXTS(SmallBoxBlurBug, reporter, ctxInfo)
{

    SkImageInfo info = SkImageInfo::MakeN32Premul(128, 128);
    auto surface(SkSurface::MakeRenderTarget(ctxInfo.grContext(), SkBudgeted::kNo, info));
    SkCanvas* canvas = surface->getCanvas();

    SkRect r = SkRect::MakeXYWH(10, 10, 100, 100);
    SkRRect rr = SkRRect::MakeRectXY(r, 10, 10);

    SkPaint p;
    p.setMaskFilter(SkBlurMaskFilter::Make(kNormal_SkBlurStyle, 0.01f));

    canvas->drawRRect(rr, p);
}

#endif

///////////////////////////////////////////////////////////////////////////////////////////
=======
///////////////////////////////////////////////////////////////////////////////////////////

DEF_GPUTEST(Blur, reporter, factory) {
    test_blur_drawing(reporter);
    test_sigma_range(reporter, factory);
    test_asABlur(reporter);
}
>>>>>>> miniblink49
