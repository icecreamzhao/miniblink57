/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

<<<<<<< HEAD
=======
#include "SkTypes.h"
#if SK_SUPPORT_GPU
#include "GrContextFactory.h"
#endif
>>>>>>> miniblink49
#include "SkCanvas.h"
#include "SkImage.h"
#include "SkShader.h"
#include "SkSurface.h"
<<<<<<< HEAD
#include "SkTypes.h"
#include "Test.h"

#if SK_SUPPORT_GPU
#include "GrContext.h"
#endif

void testBitmapEquality(skiatest::Reporter* reporter, SkBitmap& bm1, SkBitmap& bm2)
{
=======

#include "Test.h"

void testBitmapEquality(skiatest::Reporter* reporter, SkBitmap& bm1, SkBitmap& bm2) {
>>>>>>> miniblink49
    SkAutoLockPixels lockBm1(bm1);
    SkAutoLockPixels lockBm2(bm2);

    REPORTER_ASSERT(reporter, bm1.getSize() == bm2.getSize());
    REPORTER_ASSERT(reporter, 0 == memcmp(bm1.getPixels(), bm2.getPixels(), bm1.getSize()));
}

<<<<<<< HEAD
void paintSource(SkSurface* sourceSurface)
{
=======
void paintSource(SkSurface* sourceSurface) {
>>>>>>> miniblink49
    SkCanvas* sourceCanvas = sourceSurface->getCanvas();
    sourceCanvas->clear(0xFFDEDEDE);

    SkPaint paintColor;
    paintColor.setColor(0xFFFF0000);
    paintColor.setStyle(SkPaint::kFill_Style);

    SkRect rect = SkRect::MakeXYWH(
<<<<<<< HEAD
        SkIntToScalar(1),
        SkIntToScalar(0),
        SkIntToScalar(1),
        SkIntToScalar(sourceSurface->height()));
=======
            SkIntToScalar(1),
            SkIntToScalar(0),
            SkIntToScalar(1),
            SkIntToScalar(sourceSurface->height()));
>>>>>>> miniblink49

    sourceCanvas->drawRect(rect, paintColor);
}

<<<<<<< HEAD
void runShaderTest(skiatest::Reporter* reporter, SkSurface* sourceSurface, SkSurface* destinationSurface, SkImageInfo& info)
{
    paintSource(sourceSurface);

    sk_sp<SkImage> sourceImage(sourceSurface->makeImageSnapshot());
    sk_sp<SkShader> sourceShader = sourceImage->makeShader(
        SkShader::kRepeat_TileMode,
        SkShader::kRepeat_TileMode);
=======
void runShaderTest(skiatest::Reporter* reporter, SkSurface* sourceSurface, SkSurface* destinationSurface, SkImageInfo& info) {
    paintSource(sourceSurface);

    SkAutoTUnref<SkImage> sourceImage(sourceSurface->newImageSnapshot());
    SkAutoTUnref<SkShader> sourceShader(sourceImage->newShader(
            SkShader::kRepeat_TileMode,
            SkShader::kRepeat_TileMode));
>>>>>>> miniblink49

    SkPaint paint;
    paint.setShader(sourceShader);

    SkCanvas* destinationCanvas = destinationSurface->getCanvas();
    destinationCanvas->clear(SK_ColorTRANSPARENT);
    destinationCanvas->drawPaint(paint);

    SkIRect rect = info.bounds();

    SkBitmap bmOrig;
    sourceSurface->getCanvas()->readPixels(rect, &bmOrig);

<<<<<<< HEAD
=======

>>>>>>> miniblink49
    SkBitmap bm;
    destinationCanvas->readPixels(rect, &bm);

    testBitmapEquality(reporter, bmOrig, bm);

<<<<<<< HEAD
=======


>>>>>>> miniblink49
    // Test with a translated shader
    SkMatrix matrix;
    matrix.setTranslate(SkIntToScalar(-1), SkIntToScalar(0));

<<<<<<< HEAD
    sk_sp<SkShader> sourceShaderTranslated = sourceImage->makeShader(
        SkShader::kRepeat_TileMode,
        SkShader::kRepeat_TileMode,
        &matrix);
=======
    SkAutoTUnref<SkShader> sourceShaderTranslated(sourceImage->newShader(
            SkShader::kRepeat_TileMode,
            SkShader::kRepeat_TileMode,
            &matrix));
>>>>>>> miniblink49

    destinationCanvas->clear(SK_ColorTRANSPARENT);

    SkPaint paintTranslated;
    paintTranslated.setShader(sourceShaderTranslated);

    destinationCanvas->drawPaint(paintTranslated);

    SkBitmap bmt;
    destinationCanvas->readPixels(rect, &bmt);

    //  Test correctness
    {
        SkAutoLockPixels lockBm(bmt);
        for (int y = 0; y < info.height(); y++) {
            REPORTER_ASSERT(reporter, 0xFFFF0000 == bmt.getColor(0, y));

            for (int x = 1; x < info.width(); x++) {
                REPORTER_ASSERT(reporter, 0xFFDEDEDE == bmt.getColor(x, y));
            }
        }
    }
}

<<<<<<< HEAD
DEF_TEST(ImageNewShader, reporter)
{
    SkImageInfo info = SkImageInfo::MakeN32Premul(5, 5);

    auto sourceSurface(SkSurface::MakeRaster(info));
    auto destinationSurface(SkSurface::MakeRaster(info));
=======
DEF_TEST(ImageNewShader, reporter) {
    SkImageInfo info = SkImageInfo::MakeN32Premul(5, 5);

    SkAutoTUnref<SkSurface> sourceSurface(SkSurface::NewRaster(info));
    SkAutoTUnref<SkSurface> destinationSurface(SkSurface::NewRaster(info));
>>>>>>> miniblink49

    runShaderTest(reporter, sourceSurface.get(), destinationSurface.get(), info);
}

#if SK_SUPPORT_GPU

<<<<<<< HEAD
void gpuToGpu(skiatest::Reporter* reporter, GrContext* context)
{
    SkImageInfo info = SkImageInfo::MakeN32Premul(5, 5);

    auto sourceSurface(SkSurface::MakeRenderTarget(context, SkBudgeted::kNo, info));
    auto destinationSurface(SkSurface::MakeRenderTarget(context, SkBudgeted::kNo, info));
=======
void gpuToGpu(skiatest::Reporter* reporter, GrContext* context) {
    SkImageInfo info = SkImageInfo::MakeN32Premul(5, 5);

    SkAutoTUnref<SkSurface> sourceSurface(
        SkSurface::NewRenderTarget(context, SkSurface::kNo_Budgeted, info));
    SkAutoTUnref<SkSurface> destinationSurface(
        SkSurface::NewRenderTarget(context, SkSurface::kNo_Budgeted, info));
>>>>>>> miniblink49

    runShaderTest(reporter, sourceSurface.get(), destinationSurface.get(), info);
}

<<<<<<< HEAD
void gpuToRaster(skiatest::Reporter* reporter, GrContext* context)
{
    SkImageInfo info = SkImageInfo::MakeN32Premul(5, 5);

    auto sourceSurface(SkSurface::MakeRenderTarget(context, SkBudgeted::kNo, info));
    auto destinationSurface(SkSurface::MakeRaster(info));
=======
void gpuToRaster(skiatest::Reporter* reporter, GrContext* context) {
    SkImageInfo info = SkImageInfo::MakeN32Premul(5, 5);

    SkAutoTUnref<SkSurface> sourceSurface(SkSurface::NewRenderTarget(context,
        SkSurface::kNo_Budgeted, info));
    SkAutoTUnref<SkSurface> destinationSurface(SkSurface::NewRaster(info));
>>>>>>> miniblink49

    runShaderTest(reporter, sourceSurface.get(), destinationSurface.get(), info);
}

<<<<<<< HEAD
void rasterToGpu(skiatest::Reporter* reporter, GrContext* context)
{
    SkImageInfo info = SkImageInfo::MakeN32Premul(5, 5);

    auto sourceSurface(SkSurface::MakeRaster(info));
    auto destinationSurface(SkSurface::MakeRenderTarget(context, SkBudgeted::kNo, info));
=======
void rasterToGpu(skiatest::Reporter* reporter, GrContext* context) {
    SkImageInfo info = SkImageInfo::MakeN32Premul(5, 5);

    SkAutoTUnref<SkSurface> sourceSurface(SkSurface::NewRaster(info));
    SkAutoTUnref<SkSurface> destinationSurface(SkSurface::NewRenderTarget(context,
        SkSurface::kNo_Budgeted, info));
>>>>>>> miniblink49

    runShaderTest(reporter, sourceSurface.get(), destinationSurface.get(), info);
}

<<<<<<< HEAD
DEF_GPUTEST_FOR_RENDERING_CONTEXTS(ImageNewShader_GPU, reporter, ctxInfo)
{
    //  GPU -> GPU
    gpuToGpu(reporter, ctxInfo.grContext());

    //  GPU -> RASTER
    gpuToRaster(reporter, ctxInfo.grContext());

    //  RASTER -> GPU
    rasterToGpu(reporter, ctxInfo.grContext());
=======
DEF_GPUTEST(ImageNewShader_GPU, reporter, factory) {
    for (int i = 0; i < GrContextFactory::kGLContextTypeCnt; ++i) {
        GrContextFactory::GLContextType glCtxType = (GrContextFactory::GLContextType) i;

        if (!GrContextFactory::IsRenderingGLContext(glCtxType)) {
            continue;
        }

        GrContext* context = factory->get(glCtxType);

        if (NULL == context) {
            continue;
        }

        //  GPU -> GPU
        gpuToGpu(reporter, context);

        //  GPU -> RASTER
        gpuToRaster(reporter, context);

        //  RASTER -> GPU
        rasterToGpu(reporter, context);
    }
>>>>>>> miniblink49
}

#endif
