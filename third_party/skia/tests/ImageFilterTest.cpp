/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkBitmap.h"
<<<<<<< HEAD
=======
#include "SkBitmapDevice.h"
#include "SkBitmapSource.h"
>>>>>>> miniblink49
#include "SkBlurImageFilter.h"
#include "SkCanvas.h"
#include "SkColorFilterImageFilter.h"
#include "SkColorMatrixFilter.h"
#include "SkComposeImageFilter.h"
#include "SkDisplacementMapEffect.h"
#include "SkDropShadowImageFilter.h"
#include "SkFlattenableSerialization.h"
#include "SkGradientShader.h"
<<<<<<< HEAD
#include "SkImage.h"
#include "SkImageSource.h"
=======
>>>>>>> miniblink49
#include "SkLightingImageFilter.h"
#include "SkMatrixConvolutionImageFilter.h"
#include "SkMergeImageFilter.h"
#include "SkMorphologyImageFilter.h"
#include "SkOffsetImageFilter.h"
<<<<<<< HEAD
#include "SkPaintImageFilter.h"
=======
>>>>>>> miniblink49
#include "SkPerlinNoiseShader.h"
#include "SkPicture.h"
#include "SkPictureImageFilter.h"
#include "SkPictureRecorder.h"
<<<<<<< HEAD
#include "SkPoint3.h"
#include "SkReadBuffer.h"
#include "SkRect.h"
#include "SkSpecialImage.h"
#include "SkSpecialSurface.h"
#include "SkSurface.h"
#include "SkTableColorFilter.h"
=======
#include "SkReadBuffer.h"
#include "SkRect.h"
#include "SkRectShaderImageFilter.h"
>>>>>>> miniblink49
#include "SkTileImageFilter.h"
#include "SkXfermodeImageFilter.h"
#include "Test.h"

#if SK_SUPPORT_GPU
<<<<<<< HEAD
#include "GrContext.h"
=======
#include "GrContextFactory.h"
#include "SkGpuDevice.h"
>>>>>>> miniblink49
#endif

static const int kBitmapSize = 4;

namespace {

class MatrixTestImageFilter : public SkImageFilter {
public:
<<<<<<< HEAD
    static sk_sp<SkImageFilter> Make(skiatest::Reporter* reporter,
        const SkMatrix& expectedMatrix)
    {
        return sk_sp<SkImageFilter>(new MatrixTestImageFilter(reporter, expectedMatrix));
=======
    MatrixTestImageFilter(skiatest::Reporter* reporter, const SkMatrix& expectedMatrix)
      : SkImageFilter(0, NULL), fReporter(reporter), fExpectedMatrix(expectedMatrix) {
    }

    virtual bool onFilterImage(Proxy*, const SkBitmap& src, const Context& ctx,
                               SkBitmap* result, SkIPoint* offset) const override {
        REPORTER_ASSERT(fReporter, ctx.ctm() == fExpectedMatrix);
        return true;
>>>>>>> miniblink49
    }

    SK_TO_STRING_OVERRIDE()
    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(MatrixTestImageFilter)

protected:
<<<<<<< HEAD
    sk_sp<SkSpecialImage> onFilterImage(SkSpecialImage* source, const Context& ctx,
        SkIPoint* offset) const override
    {
        REPORTER_ASSERT(fReporter, ctx.ctm() == fExpectedMatrix);
        offset->fX = offset->fY = 0;
        return sk_ref_sp<SkSpecialImage>(source);
    }

    void flatten(SkWriteBuffer& buffer) const override
    {
        SkDEBUGFAIL("Should never get here");
    }

private:
    MatrixTestImageFilter(skiatest::Reporter* reporter, const SkMatrix& expectedMatrix)
        : INHERITED(nullptr, 0, nullptr)
        , fReporter(reporter)
        , fExpectedMatrix(expectedMatrix)
    {
    }

=======
    void flatten(SkWriteBuffer& buffer) const override {
        this->INHERITED::flatten(buffer);
        buffer.writeFunctionPtr(fReporter);
        buffer.writeMatrix(fExpectedMatrix);
    }

private:
>>>>>>> miniblink49
    skiatest::Reporter* fReporter;
    SkMatrix fExpectedMatrix;

    typedef SkImageFilter INHERITED;
};

<<<<<<< HEAD
class FailImageFilter : public SkImageFilter {
public:
    FailImageFilter()
        : SkImageFilter(nullptr, 0, nullptr)
    {
    }

    sk_sp<SkSpecialImage> onFilterImage(SkSpecialImage* source,
        const Context& ctx,
        SkIPoint* offset) const override
    {
        return nullptr;
    }

    SK_TO_STRING_OVERRIDE()
    SK_DECLARE_PUBLIC_FLATTENABLE_DESERIALIZATION_PROCS(FailImageFilter)

private:
    typedef SkImageFilter INHERITED;
};

sk_sp<SkFlattenable> FailImageFilter::CreateProc(SkReadBuffer& buffer)
{
    SK_IMAGEFILTER_UNFLATTEN_COMMON(common, 0);
    return sk_sp<SkFlattenable>(new FailImageFilter());
}

#ifndef SK_IGNORE_TO_STRING
void FailImageFilter::toString(SkString* str) const
{
    str->appendf("FailImageFilter: (");
    str->append(")");
}
#endif

void draw_gradient_circle(SkCanvas* canvas, int width, int height)
{
    SkScalar x = SkIntToScalar(width / 2);
    SkScalar y = SkIntToScalar(height / 2);
    SkScalar radius = SkMinScalar(x, y) * 0.8f;
    canvas->clear(0x00000000);
    SkColor colors[2];
    colors[0] = SK_ColorWHITE;
    colors[1] = SK_ColorBLACK;
    sk_sp<SkShader> shader(
        SkGradientShader::MakeRadial(SkPoint::Make(x, y), radius, colors, nullptr, 2,
            SkShader::kClamp_TileMode));
    SkPaint paint;
    paint.setShader(shader);
    canvas->drawCircle(x, y, radius, paint);
}

SkBitmap make_gradient_circle(int width, int height)
{
    SkBitmap bitmap;
    bitmap.allocN32Pixels(width, height);
    SkCanvas canvas(bitmap);
    draw_gradient_circle(&canvas, width, height);
    return bitmap;
}

class FilterList {
public:
    FilterList(sk_sp<SkImageFilter> input, const SkImageFilter::CropRect* cropRect = nullptr)
    {
        SkPoint3 location = SkPoint3::Make(0, 0, SK_Scalar1);
        const SkScalar five = SkIntToScalar(5);

        {
            sk_sp<SkColorFilter> cf(SkColorFilter::MakeModeFilter(SK_ColorRED,
                SkXfermode::kSrcIn_Mode));

            this->addFilter("color filter",
                SkColorFilterImageFilter::Make(std::move(cf), input, cropRect));
        }

        {
            sk_sp<SkImage> gradientImage(SkImage::MakeFromBitmap(make_gradient_circle(64, 64)));
            sk_sp<SkImageFilter> gradientSource(SkImageSource::Make(std::move(gradientImage)));

            this->addFilter("displacement map",
                SkDisplacementMapEffect::Make(SkDisplacementMapEffect::kR_ChannelSelectorType,
                    SkDisplacementMapEffect::kB_ChannelSelectorType,
                    20.0f,
                    std::move(gradientSource), input, cropRect));
        }

        this->addFilter("blur", SkBlurImageFilter::Make(SK_Scalar1, SK_Scalar1, input, cropRect));
        this->addFilter("drop shadow", SkDropShadowImageFilter::Make(SK_Scalar1, SK_Scalar1, SK_Scalar1, SK_Scalar1, SK_ColorGREEN, SkDropShadowImageFilter::kDrawShadowAndForeground_ShadowMode, input, cropRect));
        this->addFilter("diffuse lighting",
            SkLightingImageFilter::MakePointLitDiffuse(location, SK_ColorGREEN, 0, 0,
                input, cropRect));
        this->addFilter("specular lighting",
            SkLightingImageFilter::MakePointLitSpecular(location, SK_ColorGREEN, 0, 0, 0,
                input, cropRect));
        {
            SkScalar kernel[9] = {
                SkIntToScalar(1),
                SkIntToScalar(1),
                SkIntToScalar(1),
                SkIntToScalar(1),
                SkIntToScalar(-7),
                SkIntToScalar(1),
                SkIntToScalar(1),
                SkIntToScalar(1),
                SkIntToScalar(1),
            };
            const SkISize kernelSize = SkISize::Make(3, 3);
            const SkScalar gain = SK_Scalar1, bias = 0;

            this->addFilter("matrix convolution",
                SkMatrixConvolutionImageFilter::Make(
                    kernelSize, kernel, gain, bias, SkIPoint::Make(1, 1),
                    SkMatrixConvolutionImageFilter::kRepeat_TileMode, false,
                    input, cropRect));
        }

        this->addFilter("merge", SkMergeImageFilter::Make(input, input, SkXfermode::kSrcOver_Mode, cropRect));

        {
            SkPaint greenColorShaderPaint;
            greenColorShaderPaint.setShader(SkShader::MakeColorShader(SK_ColorGREEN));

            SkImageFilter::CropRect leftSideCropRect(SkRect::MakeXYWH(0, 0, 32, 64));
            sk_sp<SkImageFilter> paintFilterLeft(SkPaintImageFilter::Make(greenColorShaderPaint,
                &leftSideCropRect));
            SkImageFilter::CropRect rightSideCropRect(SkRect::MakeXYWH(32, 0, 32, 64));
            sk_sp<SkImageFilter> paintFilterRight(SkPaintImageFilter::Make(greenColorShaderPaint,
                &rightSideCropRect));

            this->addFilter("merge with disjoint inputs", SkMergeImageFilter::Make(std::move(paintFilterLeft), std::move(paintFilterRight), SkXfermode::kSrcOver_Mode, cropRect));
        }

        this->addFilter("offset",
            SkOffsetImageFilter::Make(SK_Scalar1, SK_Scalar1, input,
                cropRect));
        this->addFilter("dilate", SkDilateImageFilter::Make(3, 2, input, cropRect));
        this->addFilter("erode", SkErodeImageFilter::Make(2, 3, input, cropRect));
        this->addFilter("tile", SkTileImageFilter::Make(SkRect::MakeXYWH(0, 0, 50, 50), cropRect ? cropRect->rect() : SkRect::MakeXYWH(0, 0, 100, 100), input));

        if (!cropRect) {
            SkMatrix matrix;

            matrix.setTranslate(SK_Scalar1, SK_Scalar1);
            matrix.postRotate(SkIntToScalar(45), SK_Scalar1, SK_Scalar1);

            this->addFilter("matrix",
                SkImageFilter::MakeMatrixFilter(matrix, kLow_SkFilterQuality, input));
        }
        {
            sk_sp<SkImageFilter> blur(SkBlurImageFilter::Make(five, five, input));

            this->addFilter("blur and offset", SkOffsetImageFilter::Make(five, five, std::move(blur), cropRect));
        }
        {
            SkRTreeFactory factory;
            SkPictureRecorder recorder;
            SkCanvas* recordingCanvas = recorder.beginRecording(64, 64, &factory, 0);

            SkPaint greenPaint;
            greenPaint.setColor(SK_ColorGREEN);
            recordingCanvas->drawRect(SkRect::Make(SkIRect::MakeXYWH(10, 10, 30, 20)), greenPaint);
            sk_sp<SkPicture> picture(recorder.finishRecordingAsPicture());
            sk_sp<SkImageFilter> pictureFilter(SkPictureImageFilter::Make(std::move(picture)));

            this->addFilter("picture and blur", SkBlurImageFilter::Make(five, five, std::move(pictureFilter), cropRect));
        }
        {
            SkPaint paint;
            paint.setShader(SkPerlinNoiseShader::MakeTurbulence(SK_Scalar1, SK_Scalar1, 1, 0));
            sk_sp<SkImageFilter> paintFilter(SkPaintImageFilter::Make(paint));

            this->addFilter("paint and blur", SkBlurImageFilter::Make(five, five, std::move(paintFilter), cropRect));
        }
        this->addFilter("xfermode", SkXfermodeImageFilter::Make(SkXfermode::Make(SkXfermode::kSrc_Mode), input, input, cropRect));
    }
    int count() const { return fFilters.count(); }
    SkImageFilter* getFilter(int index) const { return fFilters[index].fFilter.get(); }
    const char* getName(int index) const { return fFilters[index].fName; }

private:
    struct Filter {
        Filter()
            : fName(nullptr)
        {
        }
        Filter(const char* name, sk_sp<SkImageFilter> filter)
            : fName(name)
            , fFilter(std::move(filter))
        {
        }
        const char* fName;
        sk_sp<SkImageFilter> fFilter;
    };
    void addFilter(const char* name, sk_sp<SkImageFilter> filter)
    {
        fFilters.push_back(Filter(name, std::move(filter)));
    }

    SkTArray<Filter> fFilters;
};

}

sk_sp<SkFlattenable> MatrixTestImageFilter::CreateProc(SkReadBuffer& buffer)
{
    SkDEBUGFAIL("Should never get here");
    return nullptr;
}

#ifndef SK_IGNORE_TO_STRING
void MatrixTestImageFilter::toString(SkString* str) const
{
=======
}

SkFlattenable* MatrixTestImageFilter::CreateProc(SkReadBuffer& buffer) {
    SK_IMAGEFILTER_UNFLATTEN_COMMON(common, 1);
    skiatest::Reporter* reporter = (skiatest::Reporter*)buffer.readFunctionPtr();
    SkMatrix matrix;
    buffer.readMatrix(&matrix);
    return SkNEW_ARGS(MatrixTestImageFilter, (reporter, matrix));
}

#ifndef SK_IGNORE_TO_STRING
void MatrixTestImageFilter::toString(SkString* str) const {
>>>>>>> miniblink49
    str->appendf("MatrixTestImageFilter: (");
    str->append(")");
}
#endif

<<<<<<< HEAD
static sk_sp<SkImage> make_small_image()
{
    auto surface(SkSurface::MakeRasterN32Premul(kBitmapSize, kBitmapSize));
    SkCanvas* canvas = surface->getCanvas();
    canvas->clear(0x00000000);
=======
static void make_small_bitmap(SkBitmap& bitmap) {
    bitmap.allocN32Pixels(kBitmapSize, kBitmapSize);
    SkCanvas canvas(bitmap);
    canvas.clear(0x00000000);
>>>>>>> miniblink49
    SkPaint darkPaint;
    darkPaint.setColor(0xFF804020);
    SkPaint lightPaint;
    lightPaint.setColor(0xFF244484);
    const int i = kBitmapSize / 4;
    for (int y = 0; y < kBitmapSize; y += i) {
        for (int x = 0; x < kBitmapSize; x += i) {
<<<<<<< HEAD
            canvas->save();
            canvas->translate(SkIntToScalar(x), SkIntToScalar(y));
            canvas->drawRect(SkRect::MakeXYWH(0, 0,
                                 SkIntToScalar(i),
                                 SkIntToScalar(i)),
                darkPaint);
            canvas->drawRect(SkRect::MakeXYWH(SkIntToScalar(i),
                                 0,
                                 SkIntToScalar(i),
                                 SkIntToScalar(i)),
                lightPaint);
            canvas->drawRect(SkRect::MakeXYWH(0,
                                 SkIntToScalar(i),
                                 SkIntToScalar(i),
                                 SkIntToScalar(i)),
                lightPaint);
            canvas->drawRect(SkRect::MakeXYWH(SkIntToScalar(i),
                                 SkIntToScalar(i),
                                 SkIntToScalar(i),
                                 SkIntToScalar(i)),
                darkPaint);
            canvas->restore();
        }
    }

    return surface->makeImageSnapshot();
}

static sk_sp<SkImageFilter> make_scale(float amount, sk_sp<SkImageFilter> input)
{
    SkScalar s = amount;
    SkScalar matrix[20] = { s, 0, 0, 0, 0,
        0, s, 0, 0, 0,
        0, 0, s, 0, 0,
        0, 0, 0, s, 0 };
    sk_sp<SkColorFilter> filter(SkColorFilter::MakeMatrixFilterRowMajor255(matrix));
    return SkColorFilterImageFilter::Make(std::move(filter), std::move(input));
}

static sk_sp<SkImageFilter> make_grayscale(sk_sp<SkImageFilter> input,
    const SkImageFilter::CropRect* cropRect)
{
=======
            canvas.save();
            canvas.translate(SkIntToScalar(x), SkIntToScalar(y));
            canvas.drawRect(SkRect::MakeXYWH(0, 0,
                                             SkIntToScalar(i),
                                             SkIntToScalar(i)), darkPaint);
            canvas.drawRect(SkRect::MakeXYWH(SkIntToScalar(i),
                                             0,
                                             SkIntToScalar(i),
                                             SkIntToScalar(i)), lightPaint);
            canvas.drawRect(SkRect::MakeXYWH(0,
                                             SkIntToScalar(i),
                                             SkIntToScalar(i),
                                             SkIntToScalar(i)), lightPaint);
            canvas.drawRect(SkRect::MakeXYWH(SkIntToScalar(i),
                                             SkIntToScalar(i),
                                             SkIntToScalar(i),
                                             SkIntToScalar(i)), darkPaint);
            canvas.restore();
        }
    }
}

static SkImageFilter* make_scale(float amount, SkImageFilter* input = NULL) {
    SkScalar s = amount;
    SkScalar matrix[20] = { s, 0, 0, 0, 0,
                            0, s, 0, 0, 0,
                            0, 0, s, 0, 0,
                            0, 0, 0, s, 0 };
    SkAutoTUnref<SkColorFilter> filter(SkColorMatrixFilter::Create(matrix));
    return SkColorFilterImageFilter::Create(filter, input);
}

static SkImageFilter* make_grayscale(SkImageFilter* input, const SkImageFilter::CropRect* cropRect) {
>>>>>>> miniblink49
    SkScalar matrix[20];
    memset(matrix, 0, 20 * sizeof(SkScalar));
    matrix[0] = matrix[5] = matrix[10] = 0.2126f;
    matrix[1] = matrix[6] = matrix[11] = 0.7152f;
    matrix[2] = matrix[7] = matrix[12] = 0.0722f;
    matrix[18] = 1.0f;
<<<<<<< HEAD
    sk_sp<SkColorFilter> filter(SkColorFilter::MakeMatrixFilterRowMajor255(matrix));
    return SkColorFilterImageFilter::Make(std::move(filter), std::move(input), cropRect);
}

static sk_sp<SkImageFilter> make_blue(sk_sp<SkImageFilter> input,
    const SkImageFilter::CropRect* cropRect)
{
    sk_sp<SkColorFilter> filter(SkColorFilter::MakeModeFilter(SK_ColorBLUE,
        SkXfermode::kSrcIn_Mode));
    return SkColorFilterImageFilter::Make(std::move(filter), std::move(input), cropRect);
}

static sk_sp<SkSpecialSurface> create_empty_special_surface(GrContext* context, int widthHeight)
{
#if SK_SUPPORT_GPU
    if (context) {
        return SkSpecialSurface::MakeRenderTarget(context,
            widthHeight, widthHeight,
            kSkia8888_GrPixelConfig);
    } else
#endif
    {
        const SkImageInfo info = SkImageInfo::MakeN32(widthHeight, widthHeight,
            kOpaque_SkAlphaType);
        return SkSpecialSurface::MakeRaster(info);
    }
}

static sk_sp<SkSurface> create_surface(GrContext* context, int width, int height)
{
    const SkImageInfo info = SkImageInfo::MakeN32(width, height, kOpaque_SkAlphaType);
#if SK_SUPPORT_GPU
    if (context) {
        return SkSurface::MakeRenderTarget(context, SkBudgeted::kNo, info);
    } else
#endif
    {
        return SkSurface::MakeRaster(info);
    }
}

static sk_sp<SkSpecialImage> create_empty_special_image(GrContext* context, int widthHeight)
{
    sk_sp<SkSpecialSurface> surf(create_empty_special_surface(context, widthHeight));

    SkASSERT(surf);

    SkCanvas* canvas = surf->getCanvas();
    SkASSERT(canvas);

    canvas->clear(0x0);

    return surf->makeImageSnapshot();
}

DEF_TEST(ImageFilter, reporter)
{
    {
        // Check that two non-clipping color-matrice-filters concatenate into a single filter.
        sk_sp<SkImageFilter> halfBrightness(make_scale(0.5f, nullptr));
        sk_sp<SkImageFilter> quarterBrightness(make_scale(0.5f, std::move(halfBrightness)));
        REPORTER_ASSERT(reporter, nullptr == quarterBrightness->getInput(0));
        SkColorFilter* cf;
        REPORTER_ASSERT(reporter, quarterBrightness->asColorFilter(&cf));
        REPORTER_ASSERT(reporter, cf->asColorMatrix(nullptr));
=======
    SkAutoTUnref<SkColorFilter> filter(SkColorMatrixFilter::Create(matrix));
    return SkColorFilterImageFilter::Create(filter, input, cropRect);
}

static SkImageFilter* make_blue(SkImageFilter* input, const SkImageFilter::CropRect* cropRect) {
    SkAutoTUnref<SkColorFilter> filter(SkColorFilter::CreateModeFilter(SK_ColorBLUE,
                                                                       SkXfermode::kSrcIn_Mode));
    return SkColorFilterImageFilter::Create(filter, input, cropRect);
}

DEF_TEST(ImageFilter, reporter) {
    {
        // Check that two non-clipping color-matrice-filters concatenate into a single filter.
        SkAutoTUnref<SkImageFilter> halfBrightness(make_scale(0.5f));
        SkAutoTUnref<SkImageFilter> quarterBrightness(make_scale(0.5f, halfBrightness));
        REPORTER_ASSERT(reporter, NULL == quarterBrightness->getInput(0));
        SkColorFilter* cf;
        REPORTER_ASSERT(reporter, quarterBrightness->asColorFilter(&cf));
        REPORTER_ASSERT(reporter, cf->asColorMatrix(NULL));
>>>>>>> miniblink49
        cf->unref();
    }

    {
        // Check that a clipping color-matrice-filter followed by a color-matrice-filters
        // concatenates into a single filter, but not a matrixfilter (due to clamping).
<<<<<<< HEAD
        sk_sp<SkImageFilter> doubleBrightness(make_scale(2.0f, nullptr));
        sk_sp<SkImageFilter> halfBrightness(make_scale(0.5f, std::move(doubleBrightness)));
        REPORTER_ASSERT(reporter, nullptr == halfBrightness->getInput(0));
        SkColorFilter* cf;
        REPORTER_ASSERT(reporter, halfBrightness->asColorFilter(&cf));
        REPORTER_ASSERT(reporter, !cf->asColorMatrix(nullptr));
=======
        SkAutoTUnref<SkImageFilter> doubleBrightness(make_scale(2.0f));
        SkAutoTUnref<SkImageFilter> halfBrightness(make_scale(0.5f, doubleBrightness));
        REPORTER_ASSERT(reporter, NULL == halfBrightness->getInput(0));
        SkColorFilter* cf;
        REPORTER_ASSERT(reporter, halfBrightness->asColorFilter(&cf));
        REPORTER_ASSERT(reporter, !cf->asColorMatrix(NULL));
>>>>>>> miniblink49
        cf->unref();
    }

    {
        // Check that a color filter image filter without a crop rect can be
        // expressed as a color filter.
<<<<<<< HEAD
        sk_sp<SkImageFilter> gray(make_grayscale(nullptr, nullptr));
        REPORTER_ASSERT(reporter, true == gray->asColorFilter(nullptr));
    }

    {
        // Check that a colorfilterimage filter without a crop rect but with an input
        // that is another colorfilterimage can be expressed as a colorfilter (composed).
        sk_sp<SkImageFilter> mode(make_blue(nullptr, nullptr));
        sk_sp<SkImageFilter> gray(make_grayscale(std::move(mode), nullptr));
        REPORTER_ASSERT(reporter, true == gray->asColorFilter(nullptr));
=======
        SkAutoTUnref<SkImageFilter> gray(make_grayscale(NULL, NULL));
        REPORTER_ASSERT(reporter, true == gray->asColorFilter(NULL));
    }
    
    {
        // Check that a colorfilterimage filter without a crop rect but with an input
        // that is another colorfilterimage can be expressed as a colorfilter (composed).
        SkAutoTUnref<SkImageFilter> mode(make_blue(NULL, NULL));
        SkAutoTUnref<SkImageFilter> gray(make_grayscale(mode, NULL));
        REPORTER_ASSERT(reporter, true == gray->asColorFilter(NULL));
>>>>>>> miniblink49
    }

    {
        // Test that if we exceed the limit of what ComposeColorFilter can combine, we still
        // can build the DAG and won't assert if we call asColorFilter.
<<<<<<< HEAD
        sk_sp<SkImageFilter> filter(make_blue(nullptr, nullptr));
        const int kWayTooManyForComposeColorFilter = 100;
        for (int i = 0; i < kWayTooManyForComposeColorFilter; ++i) {
            filter = make_blue(filter, nullptr);
            // the first few of these will succeed, but after we hit the internal limit,
            // it will then return false.
            (void)filter->asColorFilter(nullptr);
=======
        SkAutoTUnref<SkImageFilter> filter(make_blue(NULL, NULL));
        const int kWayTooManyForComposeColorFilter = 100;
        for (int i = 0; i < kWayTooManyForComposeColorFilter; ++i) {
            filter.reset(make_blue(filter, NULL));
            // the first few of these will succeed, but after we hit the internal limit,
            // it will then return false.
            (void)filter->asColorFilter(NULL);
>>>>>>> miniblink49
        }
    }

    {
        // Check that a color filter image filter with a crop rect cannot
        // be expressed as a color filter.
        SkImageFilter::CropRect cropRect(SkRect::MakeXYWH(0, 0, 100, 100));
<<<<<<< HEAD
        sk_sp<SkImageFilter> grayWithCrop(make_grayscale(nullptr, &cropRect));
        REPORTER_ASSERT(reporter, false == grayWithCrop->asColorFilter(nullptr));
=======
        SkAutoTUnref<SkImageFilter> grayWithCrop(make_grayscale(NULL, &cropRect));
        REPORTER_ASSERT(reporter, false == grayWithCrop->asColorFilter(NULL));
>>>>>>> miniblink49
    }

    {
        // Check that two non-commutative matrices are concatenated in
        // the correct order.
        SkScalar blueToRedMatrix[20] = { 0 };
        blueToRedMatrix[2] = blueToRedMatrix[18] = SK_Scalar1;
        SkScalar redToGreenMatrix[20] = { 0 };
        redToGreenMatrix[5] = redToGreenMatrix[18] = SK_Scalar1;
<<<<<<< HEAD
        sk_sp<SkColorFilter> blueToRed(SkColorFilter::MakeMatrixFilterRowMajor255(blueToRedMatrix));
        sk_sp<SkImageFilter> filter1(SkColorFilterImageFilter::Make(std::move(blueToRed),
            nullptr));
        sk_sp<SkColorFilter> redToGreen(SkColorFilter::MakeMatrixFilterRowMajor255(redToGreenMatrix));
        sk_sp<SkImageFilter> filter2(SkColorFilterImageFilter::Make(std::move(redToGreen),
            std::move(filter1)));
=======
        SkAutoTUnref<SkColorFilter> blueToRed(SkColorMatrixFilter::Create(blueToRedMatrix));
        SkAutoTUnref<SkImageFilter> filter1(SkColorFilterImageFilter::Create(blueToRed.get()));
        SkAutoTUnref<SkColorFilter> redToGreen(SkColorMatrixFilter::Create(redToGreenMatrix));
        SkAutoTUnref<SkImageFilter> filter2(SkColorFilterImageFilter::Create(redToGreen.get(), filter1.get()));
>>>>>>> miniblink49

        SkBitmap result;
        result.allocN32Pixels(kBitmapSize, kBitmapSize);

        SkPaint paint;
        paint.setColor(SK_ColorBLUE);
<<<<<<< HEAD
        paint.setImageFilter(std::move(filter2));
=======
        paint.setImageFilter(filter2.get());
>>>>>>> miniblink49
        SkCanvas canvas(result);
        canvas.clear(0x0);
        SkRect rect = SkRect::Make(SkIRect::MakeWH(kBitmapSize, kBitmapSize));
        canvas.drawRect(rect, paint);
        uint32_t pixel = *result.getAddr32(0, 0);
        // The result here should be green, since we have effectively shifted blue to green.
        REPORTER_ASSERT(reporter, pixel == SK_ColorGREEN);
    }

    {
        // Tests pass by not asserting
<<<<<<< HEAD
        sk_sp<SkImage> image(make_small_image());
        SkBitmap result;
=======
        SkBitmap bitmap, result;
        make_small_bitmap(bitmap);
>>>>>>> miniblink49
        result.allocN32Pixels(kBitmapSize, kBitmapSize);

        {
            // This tests for :
            // 1 ) location at (0,0,1)
<<<<<<< HEAD
            SkPoint3 location = SkPoint3::Make(0, 0, SK_Scalar1);
            // 2 ) location and target at same value
            SkPoint3 target = SkPoint3::Make(location.fX, location.fY, location.fZ);
            // 3 ) large negative specular exponent value
            SkScalar specularExponent = -1000;

            sk_sp<SkImageFilter> bmSrc(SkImageSource::Make(std::move(image)));
            SkPaint paint;
            paint.setImageFilter(SkLightingImageFilter::MakeSpotLitSpecular(
                location, target, specularExponent, 180,
                0xFFFFFFFF, SK_Scalar1, SK_Scalar1, SK_Scalar1,
                std::move(bmSrc)));
            SkCanvas canvas(result);
            SkRect r = SkRect::MakeWH(SkIntToScalar(kBitmapSize),
                SkIntToScalar(kBitmapSize));
=======
            SkPoint3 location(0, 0, SK_Scalar1);
            // 2 ) location and target at same value
            SkPoint3 target(location.fX, location.fY, location.fZ);
            // 3 ) large negative specular exponent value
            SkScalar specularExponent = -1000;

            SkAutoTUnref<SkImageFilter> bmSrc(SkBitmapSource::Create(bitmap));
            SkPaint paint;
            paint.setImageFilter(SkLightingImageFilter::CreateSpotLitSpecular(
                    location, target, specularExponent, 180,
                    0xFFFFFFFF, SK_Scalar1, SK_Scalar1, SK_Scalar1,
                    bmSrc))->unref();
            SkCanvas canvas(result);
            SkRect r = SkRect::MakeWH(SkIntToScalar(kBitmapSize),
                                      SkIntToScalar(kBitmapSize));
>>>>>>> miniblink49
            canvas.drawRect(r, paint);
        }
    }
}

<<<<<<< HEAD
static void test_crop_rects(skiatest::Reporter* reporter,
    GrContext* context)
{
    // Check that all filters offset to their absolute crop rect,
    // unaffected by the input crop rect.
    // Tests pass by not asserting.
    sk_sp<SkSpecialImage> srcImg(create_empty_special_image(context, 100));
    SkASSERT(srcImg);

    SkImageFilter::CropRect inputCropRect(SkRect::MakeXYWH(8, 13, 80, 80));
    SkImageFilter::CropRect cropRect(SkRect::MakeXYWH(20, 30, 60, 60));
    sk_sp<SkImageFilter> input(make_grayscale(nullptr, &inputCropRect));

    FilterList filters(input, &cropRect);

    for (int i = 0; i < filters.count(); ++i) {
        SkImageFilter* filter = filters.getFilter(i);
        SkIPoint offset;
        SkImageFilter::Context ctx(SkMatrix::I(), SkIRect::MakeWH(100, 100), nullptr);
        sk_sp<SkSpecialImage> resultImg(filter->filterImage(srcImg.get(), ctx, &offset));
        REPORTER_ASSERT_MESSAGE(reporter, resultImg, filters.getName(i));
        REPORTER_ASSERT_MESSAGE(reporter, offset.fX == 20 && offset.fY == 30, filters.getName(i));
    }
}

static void test_negative_blur_sigma(skiatest::Reporter* reporter,
    GrContext* context)
{
    // Check that SkBlurImageFilter will accept a negative sigma, either in
    // the given arguments or after CTM application.
    const int width = 32, height = 32;
    const SkScalar five = SkIntToScalar(5);

    sk_sp<SkImageFilter> positiveFilter(SkBlurImageFilter::Make(five, five, nullptr));
    sk_sp<SkImageFilter> negativeFilter(SkBlurImageFilter::Make(-five, five, nullptr));

    SkBitmap gradient = make_gradient_circle(width, height);
    sk_sp<SkSpecialImage> imgSrc(SkSpecialImage::MakeFromRaster(SkIRect::MakeWH(width, height),
        gradient));

    SkIPoint offset;
    SkImageFilter::Context ctx(SkMatrix::I(), SkIRect::MakeWH(32, 32), nullptr);

    sk_sp<SkSpecialImage> positiveResult1(positiveFilter->filterImage(imgSrc.get(), ctx, &offset));
    REPORTER_ASSERT(reporter, positiveResult1);

    sk_sp<SkSpecialImage> negativeResult1(negativeFilter->filterImage(imgSrc.get(), ctx, &offset));
    REPORTER_ASSERT(reporter, negativeResult1);

    SkMatrix negativeScale;
    negativeScale.setScale(-SK_Scalar1, SK_Scalar1);
    SkImageFilter::Context negativeCTX(negativeScale, SkIRect::MakeWH(32, 32), nullptr);

    sk_sp<SkSpecialImage> negativeResult2(positiveFilter->filterImage(imgSrc.get(),
        negativeCTX,
        &offset));
    REPORTER_ASSERT(reporter, negativeResult2);

    sk_sp<SkSpecialImage> positiveResult2(negativeFilter->filterImage(imgSrc.get(),
        negativeCTX,
        &offset));
    REPORTER_ASSERT(reporter, positiveResult2);

    SkBitmap positiveResultBM1, positiveResultBM2;
    SkBitmap negativeResultBM1, negativeResultBM2;

    REPORTER_ASSERT(reporter, positiveResult1->getROPixels(&positiveResultBM1));
    REPORTER_ASSERT(reporter, positiveResult2->getROPixels(&positiveResultBM2));
    REPORTER_ASSERT(reporter, negativeResult1->getROPixels(&negativeResultBM1));
    REPORTER_ASSERT(reporter, negativeResult2->getROPixels(&negativeResultBM2));

    SkAutoLockPixels lockP1(positiveResultBM1);
    SkAutoLockPixels lockP2(positiveResultBM2);
    SkAutoLockPixels lockN1(negativeResultBM1);
    SkAutoLockPixels lockN2(negativeResultBM2);
    for (int y = 0; y < height; y++) {
        int diffs = memcmp(positiveResultBM1.getAddr32(0, y),
            negativeResultBM1.getAddr32(0, y),
            positiveResultBM1.rowBytes());
=======
static void test_crop_rects(SkImageFilter::Proxy* proxy, skiatest::Reporter* reporter) {
    // Check that all filters offset to their absolute crop rect,
    // unaffected by the input crop rect.
    // Tests pass by not asserting.
    SkBitmap bitmap;
    bitmap.allocN32Pixels(100, 100);
    bitmap.eraseARGB(0, 0, 0, 0);

    SkImageFilter::CropRect inputCropRect(SkRect::MakeXYWH(8, 13, 80, 80));
    SkImageFilter::CropRect cropRect(SkRect::MakeXYWH(20, 30, 60, 60));
    SkAutoTUnref<SkImageFilter> input(make_grayscale(NULL, &inputCropRect));

    SkAutoTUnref<SkColorFilter> cf(SkColorFilter::CreateModeFilter(SK_ColorRED, SkXfermode::kSrcIn_Mode));
    SkPoint3 location(0, 0, SK_Scalar1);
    SkPoint3 target(SK_Scalar1, SK_Scalar1, SK_Scalar1);
    SkScalar kernel[9] = {
        SkIntToScalar( 1), SkIntToScalar( 1), SkIntToScalar( 1),
        SkIntToScalar( 1), SkIntToScalar(-7), SkIntToScalar( 1),
        SkIntToScalar( 1), SkIntToScalar( 1), SkIntToScalar( 1),
    };
    SkISize kernelSize = SkISize::Make(3, 3);
    SkScalar gain = SK_Scalar1, bias = 0;

    SkImageFilter* filters[] = {
        SkColorFilterImageFilter::Create(cf.get(), input.get(), &cropRect),
        SkDisplacementMapEffect::Create(SkDisplacementMapEffect::kR_ChannelSelectorType,
                                        SkDisplacementMapEffect::kB_ChannelSelectorType,
                                        40.0f, input.get(), input.get(), &cropRect),
        SkBlurImageFilter::Create(SK_Scalar1, SK_Scalar1, input.get(), &cropRect),
        SkDropShadowImageFilter::Create(SK_Scalar1, SK_Scalar1, SK_Scalar1, SK_Scalar1,
            SK_ColorGREEN, SkDropShadowImageFilter::kDrawShadowAndForeground_ShadowMode,
            input.get(), &cropRect),
        SkLightingImageFilter::CreatePointLitDiffuse(location, SK_ColorGREEN, 0, 0, input.get(), &cropRect),
        SkLightingImageFilter::CreatePointLitSpecular(location, SK_ColorGREEN, 0, 0, 0, input.get(), &cropRect),
        SkMatrixConvolutionImageFilter::Create(kernelSize, kernel, gain, bias, SkIPoint::Make(1, 1), SkMatrixConvolutionImageFilter::kRepeat_TileMode, false, input.get(), &cropRect),
        SkMergeImageFilter::Create(input.get(), input.get(), SkXfermode::kSrcOver_Mode, &cropRect),
        SkOffsetImageFilter::Create(SK_Scalar1, SK_Scalar1, input.get(), &cropRect),
        SkOffsetImageFilter::Create(SK_Scalar1, SK_Scalar1, input.get(), &cropRect),
        SkDilateImageFilter::Create(3, 2, input.get(), &cropRect),
        SkErodeImageFilter::Create(2, 3, input.get(), &cropRect),
        SkTileImageFilter::Create(inputCropRect.rect(), cropRect.rect(), input.get()),
        SkXfermodeImageFilter::Create(SkXfermode::Create(SkXfermode::kSrcOver_Mode), input.get(), input.get(), &cropRect),
    };

    for (size_t i = 0; i < SK_ARRAY_COUNT(filters); ++i) {
        SkImageFilter* filter = filters[i];
        SkBitmap result;
        SkIPoint offset;
        SkString str;
        str.printf("filter %d", static_cast<int>(i));
        SkImageFilter::Context ctx(SkMatrix::I(), SkIRect::MakeLargest(), NULL);
        REPORTER_ASSERT_MESSAGE(reporter, filter->filterImage(proxy, bitmap, ctx,
                                &result, &offset), str.c_str());
        REPORTER_ASSERT_MESSAGE(reporter, offset.fX == 20 && offset.fY == 30, str.c_str());
    }

    for (size_t i = 0; i < SK_ARRAY_COUNT(filters); ++i) {
        SkSafeUnref(filters[i]);
    }
}

static SkBitmap make_gradient_circle(int width, int height) {
    SkBitmap bitmap;
    SkScalar x = SkIntToScalar(width / 2);
    SkScalar y = SkIntToScalar(height / 2);
    SkScalar radius = SkMinScalar(x, y) * 0.8f;
    bitmap.allocN32Pixels(width, height);
    SkCanvas canvas(bitmap);
    canvas.clear(0x00000000);
    SkColor colors[2];
    colors[0] = SK_ColorWHITE;
    colors[1] = SK_ColorBLACK;
    SkAutoTUnref<SkShader> shader(
        SkGradientShader::CreateRadial(SkPoint::Make(x, y), radius, colors, NULL, 2,
                                       SkShader::kClamp_TileMode)
    );
    SkPaint paint;
    paint.setShader(shader);
    canvas.drawCircle(x, y, radius, paint);
    return bitmap;
}

static void test_negative_blur_sigma(SkImageFilter::Proxy* proxy, skiatest::Reporter* reporter) {
    // Check that SkBlurImageFilter will accept a negative sigma, either in
    // the given arguments or after CTM application.
    int width = 32, height = 32;
    SkScalar five = SkIntToScalar(5);

    SkAutoTUnref<SkBlurImageFilter> positiveFilter(
        SkBlurImageFilter::Create(five, five)
    );

    SkAutoTUnref<SkBlurImageFilter> negativeFilter(
        SkBlurImageFilter::Create(-five, five)
    );

    SkBitmap gradient = make_gradient_circle(width, height);
    SkBitmap positiveResult1, negativeResult1;
    SkBitmap positiveResult2, negativeResult2;
    SkIPoint offset;
    SkImageFilter::Context ctx(SkMatrix::I(), SkIRect::MakeLargest(), NULL);
    positiveFilter->filterImage(proxy, gradient, ctx, &positiveResult1, &offset);
    negativeFilter->filterImage(proxy, gradient, ctx, &negativeResult1, &offset);
    SkMatrix negativeScale;
    negativeScale.setScale(-SK_Scalar1, SK_Scalar1);
    SkImageFilter::Context negativeCTX(negativeScale, SkIRect::MakeLargest(), NULL);
    positiveFilter->filterImage(proxy, gradient, negativeCTX, &negativeResult2, &offset);
    negativeFilter->filterImage(proxy, gradient, negativeCTX, &positiveResult2, &offset);
    SkAutoLockPixels lockP1(positiveResult1);
    SkAutoLockPixels lockP2(positiveResult2);
    SkAutoLockPixels lockN1(negativeResult1);
    SkAutoLockPixels lockN2(negativeResult2);
    for (int y = 0; y < height; y++) {
        int diffs = memcmp(positiveResult1.getAddr32(0, y), negativeResult1.getAddr32(0, y), positiveResult1.rowBytes());
>>>>>>> miniblink49
        REPORTER_ASSERT(reporter, !diffs);
        if (diffs) {
            break;
        }
<<<<<<< HEAD
        diffs = memcmp(positiveResultBM1.getAddr32(0, y),
            negativeResultBM2.getAddr32(0, y),
            positiveResultBM1.rowBytes());
=======
        diffs = memcmp(positiveResult1.getAddr32(0, y), negativeResult2.getAddr32(0, y), positiveResult1.rowBytes());
>>>>>>> miniblink49
        REPORTER_ASSERT(reporter, !diffs);
        if (diffs) {
            break;
        }
<<<<<<< HEAD
        diffs = memcmp(positiveResultBM1.getAddr32(0, y),
            positiveResultBM2.getAddr32(0, y),
            positiveResultBM1.rowBytes());
=======
        diffs = memcmp(positiveResult1.getAddr32(0, y), positiveResult2.getAddr32(0, y), positiveResult1.rowBytes());
>>>>>>> miniblink49
        REPORTER_ASSERT(reporter, !diffs);
        if (diffs) {
            break;
        }
    }
}

<<<<<<< HEAD
DEF_TEST(ImageFilterNegativeBlurSigma, reporter)
{
    test_negative_blur_sigma(reporter, nullptr);
}

#if SK_SUPPORT_GPU
DEF_GPUTEST_FOR_RENDERING_CONTEXTS(ImageFilterNegativeBlurSigma_Gpu, reporter, ctxInfo)
{
    test_negative_blur_sigma(reporter, ctxInfo.grContext());
}
#endif

static void test_zero_blur_sigma(skiatest::Reporter* reporter, GrContext* context)
{
    // Check that SkBlurImageFilter with a zero sigma and a non-zero srcOffset works correctly.
    SkImageFilter::CropRect cropRect(SkRect::Make(SkIRect::MakeXYWH(5, 0, 5, 10)));
    sk_sp<SkImageFilter> input(SkOffsetImageFilter::Make(0, 0, nullptr, &cropRect));
    sk_sp<SkImageFilter> filter(SkBlurImageFilter::Make(0, 0, std::move(input), &cropRect));

    sk_sp<SkSpecialSurface> surf(create_empty_special_surface(context, 10));
    surf->getCanvas()->clear(SK_ColorGREEN);
    sk_sp<SkSpecialImage> image(surf->makeImageSnapshot());

    SkIPoint offset;
    SkImageFilter::Context ctx(SkMatrix::I(), SkIRect::MakeWH(32, 32), nullptr);

    sk_sp<SkSpecialImage> result(filter->filterImage(image.get(), ctx, &offset));
    REPORTER_ASSERT(reporter, offset.fX == 5 && offset.fY == 0);
    REPORTER_ASSERT(reporter, result);
    REPORTER_ASSERT(reporter, result->width() == 5 && result->height() == 10);

    SkBitmap resultBM;

    REPORTER_ASSERT(reporter, result->getROPixels(&resultBM));

    SkAutoLockPixels lock(resultBM);
    for (int y = 0; y < resultBM.height(); y++) {
        for (int x = 0; x < resultBM.width(); x++) {
            bool diff = *resultBM.getAddr32(x, y) != SK_ColorGREEN;
            REPORTER_ASSERT(reporter, !diff);
            if (diff) {
                break;
            }
        }
    }
}

DEF_TEST(ImageFilterZeroBlurSigma, reporter)
{
    test_zero_blur_sigma(reporter, nullptr);
}

#if SK_SUPPORT_GPU
DEF_GPUTEST_FOR_RENDERING_CONTEXTS(ImageFilterZeroBlurSigma_Gpu, reporter, ctxInfo)
{
    test_zero_blur_sigma(reporter, ctxInfo.grContext());
}
#endif

// Tests that, even when an upstream filter has returned null (due to failure or clipping), a
// downstream filter that affects transparent black still does so even with a nullptr input.
static void test_fail_affects_transparent_black(skiatest::Reporter* reporter, GrContext* context)
{
    sk_sp<FailImageFilter> failFilter(new FailImageFilter());
    sk_sp<SkSpecialImage> source(create_empty_special_image(context, 5));
    SkImageFilter::Context ctx(SkMatrix::I(), SkIRect::MakeXYWH(0, 0, 1, 1), nullptr);
    sk_sp<SkColorFilter> green(SkColorFilter::MakeModeFilter(SK_ColorGREEN, SkXfermode::kSrc_Mode));
    SkASSERT(green->affectsTransparentBlack());
    sk_sp<SkImageFilter> greenFilter(SkColorFilterImageFilter::Make(std::move(green),
        std::move(failFilter)));
    SkIPoint offset;
    sk_sp<SkSpecialImage> result(greenFilter->filterImage(source.get(), ctx, &offset));
    REPORTER_ASSERT(reporter, nullptr != result.get());
    if (result.get()) {
        SkBitmap resultBM;
        REPORTER_ASSERT(reporter, result->getROPixels(&resultBM));
        SkAutoLockPixels lock(resultBM);
        REPORTER_ASSERT(reporter, *resultBM.getAddr32(0, 0) == SK_ColorGREEN);
    }
}

DEF_TEST(ImageFilterFailAffectsTransparentBlack, reporter)
{
    test_fail_affects_transparent_black(reporter, nullptr);
}

#if SK_SUPPORT_GPU
DEF_GPUTEST_FOR_RENDERING_CONTEXTS(ImageFilterFailAffectsTransparentBlack_Gpu, reporter, ctxInfo)
{
    test_fail_affects_transparent_black(reporter, ctxInfo.grContext());
}
#endif

DEF_TEST(ImageFilterDrawTiled, reporter)
{
=======
DEF_TEST(TestNegativeBlurSigma, reporter) {
    const SkImageInfo info = SkImageInfo::MakeN32Premul(100, 100);
    const SkSurfaceProps props(SkSurfaceProps::kLegacyFontHost_InitType);

    SkAutoTUnref<SkBaseDevice> device(SkBitmapDevice::Create(info, props));
    SkImageFilter::Proxy proxy(device);

    test_negative_blur_sigma(&proxy, reporter);
}

DEF_TEST(ImageFilterDrawTiled, reporter) {
>>>>>>> miniblink49
    // Check that all filters when drawn tiled (with subsequent clip rects) exactly
    // match the same filters drawn with a single full-canvas bitmap draw.
    // Tests pass by not asserting.

<<<<<<< HEAD
    FilterList filters(nullptr);

    SkBitmap untiledResult, tiledResult;
    const int width = 64, height = 64;
=======
    SkAutoTUnref<SkColorFilter> cf(SkColorFilter::CreateModeFilter(SK_ColorRED, SkXfermode::kSrcIn_Mode));
    SkPoint3 location(0, 0, SK_Scalar1);
    SkPoint3 target(SK_Scalar1, SK_Scalar1, SK_Scalar1);
    SkScalar kernel[9] = {
        SkIntToScalar( 1), SkIntToScalar( 1), SkIntToScalar( 1),
        SkIntToScalar( 1), SkIntToScalar(-7), SkIntToScalar( 1),
        SkIntToScalar( 1), SkIntToScalar( 1), SkIntToScalar( 1),
    };
    SkISize kernelSize = SkISize::Make(3, 3);
    SkScalar gain = SK_Scalar1, bias = 0;
    SkScalar five = SkIntToScalar(5);

    SkAutoTUnref<SkImageFilter> gradient_source(SkBitmapSource::Create(make_gradient_circle(64, 64)));
    SkAutoTUnref<SkImageFilter> blur(SkBlurImageFilter::Create(five, five));
    SkMatrix matrix;

    matrix.setTranslate(SK_Scalar1, SK_Scalar1);
    matrix.postRotate(SkIntToScalar(45), SK_Scalar1, SK_Scalar1);

    SkRTreeFactory factory;
    SkPictureRecorder recorder;
    SkCanvas* recordingCanvas = recorder.beginRecording(64, 64, &factory, 0);

    SkPaint greenPaint;
    greenPaint.setColor(SK_ColorGREEN);
    recordingCanvas->drawRect(SkRect::Make(SkIRect::MakeXYWH(10, 10, 30, 20)), greenPaint);
    SkAutoTUnref<SkPicture> picture(recorder.endRecording());
    SkAutoTUnref<SkImageFilter> pictureFilter(SkPictureImageFilter::Create(picture.get()));
    SkAutoTUnref<SkShader> shader(SkPerlinNoiseShader::CreateTurbulence(SK_Scalar1, SK_Scalar1, 1, 0));

    SkAutoTUnref<SkImageFilter> rectShaderFilter(SkRectShaderImageFilter::Create(shader.get()));

    SkAutoTUnref<SkShader> greenColorShader(SkShader::CreateColorShader(SK_ColorGREEN));
    SkImageFilter::CropRect leftSideCropRect(SkRect::MakeXYWH(0, 0, 32, 64));
    SkAutoTUnref<SkImageFilter> rectShaderFilterLeft(SkRectShaderImageFilter::Create(greenColorShader.get(), &leftSideCropRect));
    SkImageFilter::CropRect rightSideCropRect(SkRect::MakeXYWH(32, 0, 32, 64));
    SkAutoTUnref<SkImageFilter> rectShaderFilterRight(SkRectShaderImageFilter::Create(greenColorShader.get(), &rightSideCropRect));

    struct {
        const char*    fName;
        SkImageFilter* fFilter;
    } filters[] = {
        { "color filter", SkColorFilterImageFilter::Create(cf.get()) },
        { "displacement map", SkDisplacementMapEffect::Create(
              SkDisplacementMapEffect::kR_ChannelSelectorType,
              SkDisplacementMapEffect::kB_ChannelSelectorType,
              20.0f, gradient_source.get()) },
        { "blur", SkBlurImageFilter::Create(SK_Scalar1, SK_Scalar1) },
        { "drop shadow", SkDropShadowImageFilter::Create(
              SK_Scalar1, SK_Scalar1, SK_Scalar1, SK_Scalar1, SK_ColorGREEN,
              SkDropShadowImageFilter::kDrawShadowAndForeground_ShadowMode) },
        { "diffuse lighting", SkLightingImageFilter::CreatePointLitDiffuse(
              location, SK_ColorGREEN, 0, 0) },
        { "specular lighting",
              SkLightingImageFilter::CreatePointLitSpecular(location, SK_ColorGREEN, 0, 0, 0) },
        { "matrix convolution",
              SkMatrixConvolutionImageFilter::Create(
                  kernelSize, kernel, gain, bias, SkIPoint::Make(1, 1),
                  SkMatrixConvolutionImageFilter::kRepeat_TileMode, false) },
        { "merge", SkMergeImageFilter::Create(NULL, NULL, SkXfermode::kSrcOver_Mode) },
        { "merge with disjoint inputs", SkMergeImageFilter::Create(
              rectShaderFilterLeft, rectShaderFilterRight, SkXfermode::kSrcOver_Mode) },
        { "offset", SkOffsetImageFilter::Create(SK_Scalar1, SK_Scalar1) },
        { "dilate", SkDilateImageFilter::Create(3, 2) },
        { "erode", SkErodeImageFilter::Create(2, 3) },
        { "tile", SkTileImageFilter::Create(SkRect::MakeXYWH(0, 0, 50, 50),
                                            SkRect::MakeXYWH(0, 0, 100, 100), NULL) },
        { "matrix", SkImageFilter::CreateMatrixFilter(matrix, kLow_SkFilterQuality) },
        { "blur and offset", SkOffsetImageFilter::Create(five, five, blur.get()) },
        { "picture and blur", SkBlurImageFilter::Create(five, five, pictureFilter.get()) },
        { "rect shader and blur", SkBlurImageFilter::Create(five, five, rectShaderFilter.get()) },
    };

    SkBitmap untiledResult, tiledResult;
    int width = 64, height = 64;
>>>>>>> miniblink49
    untiledResult.allocN32Pixels(width, height);
    tiledResult.allocN32Pixels(width, height);
    SkCanvas tiledCanvas(tiledResult);
    SkCanvas untiledCanvas(untiledResult);
    int tileSize = 8;

    for (int scale = 1; scale <= 2; ++scale) {
<<<<<<< HEAD
        for (int i = 0; i < filters.count(); ++i) {
            tiledCanvas.clear(0);
            untiledCanvas.clear(0);
            SkPaint paint;
            paint.setImageFilter(filters.getFilter(i));
=======
        for (size_t i = 0; i < SK_ARRAY_COUNT(filters); ++i) {
            tiledCanvas.clear(0);
            untiledCanvas.clear(0);
            SkPaint paint;
            paint.setImageFilter(filters[i].fFilter);
>>>>>>> miniblink49
            paint.setTextSize(SkIntToScalar(height));
            paint.setColor(SK_ColorWHITE);
            SkString str;
            const char* text = "ABC";
            SkScalar ypos = SkIntToScalar(height);
            untiledCanvas.save();
            untiledCanvas.scale(SkIntToScalar(scale), SkIntToScalar(scale));
            untiledCanvas.drawText(text, strlen(text), 0, ypos, paint);
            untiledCanvas.restore();
            for (int y = 0; y < height; y += tileSize) {
                for (int x = 0; x < width; x += tileSize) {
                    tiledCanvas.save();
                    tiledCanvas.clipRect(SkRect::Make(SkIRect::MakeXYWH(x, y, tileSize, tileSize)));
                    tiledCanvas.scale(SkIntToScalar(scale), SkIntToScalar(scale));
                    tiledCanvas.drawText(text, strlen(text), 0, ypos, paint);
                    tiledCanvas.restore();
                }
            }
            untiledCanvas.flush();
            tiledCanvas.flush();
            for (int y = 0; y < height; y++) {
                int diffs = memcmp(untiledResult.getAddr32(0, y), tiledResult.getAddr32(0, y), untiledResult.rowBytes());
<<<<<<< HEAD
                REPORTER_ASSERT_MESSAGE(reporter, !diffs, filters.getName(i));
=======
                REPORTER_ASSERT_MESSAGE(reporter, !diffs, filters[i].fName);
>>>>>>> miniblink49
                if (diffs) {
                    break;
                }
            }
        }
    }
<<<<<<< HEAD
}

static void draw_saveLayer_picture(int width, int height, int tileSize,
    SkBBHFactory* factory, SkBitmap* result)
{
=======

    for (size_t i = 0; i < SK_ARRAY_COUNT(filters); ++i) {
        SkSafeUnref(filters[i].fFilter);
    }
}

static void draw_saveLayer_picture(int width, int height, int tileSize,
                                   SkBBHFactory* factory, SkBitmap* result) {
>>>>>>> miniblink49

    SkMatrix matrix;
    matrix.setTranslate(SkIntToScalar(50), 0);

<<<<<<< HEAD
    sk_sp<SkColorFilter> cf(SkColorFilter::MakeModeFilter(SK_ColorWHITE, SkXfermode::kSrc_Mode));
    sk_sp<SkImageFilter> cfif(SkColorFilterImageFilter::Make(std::move(cf), nullptr));
    sk_sp<SkImageFilter> imageFilter(SkImageFilter::MakeMatrixFilter(matrix,
        kNone_SkFilterQuality,
        std::move(cfif)));

    SkPaint paint;
    paint.setImageFilter(std::move(imageFilter));
    SkPictureRecorder recorder;
    SkRect bounds = SkRect::Make(SkIRect::MakeXYWH(0, 0, 50, 50));
    SkCanvas* recordingCanvas = recorder.beginRecording(SkIntToScalar(width),
        SkIntToScalar(height),
        factory, 0);
    recordingCanvas->translate(-55, 0);
    recordingCanvas->saveLayer(&bounds, &paint);
    recordingCanvas->restore();
    sk_sp<SkPicture> picture1(recorder.finishRecordingAsPicture());
=======
    SkAutoTUnref<SkColorFilter> cf(SkColorFilter::CreateModeFilter(SK_ColorWHITE, SkXfermode::kSrc_Mode));
    SkAutoTUnref<SkImageFilter> cfif(SkColorFilterImageFilter::Create(cf.get()));
    SkAutoTUnref<SkImageFilter> imageFilter(SkImageFilter::CreateMatrixFilter(matrix, kNone_SkFilterQuality, cfif.get()));

    SkPaint paint;
    paint.setImageFilter(imageFilter.get());
    SkPictureRecorder recorder;
    SkRect bounds = SkRect::Make(SkIRect::MakeXYWH(0, 0, 50, 50));
    SkCanvas* recordingCanvas = recorder.beginRecording(SkIntToScalar(width),
                                                        SkIntToScalar(height),
                                                        factory, 0);
    recordingCanvas->translate(-55, 0);
    recordingCanvas->saveLayer(&bounds, &paint);
    recordingCanvas->restore();
    SkAutoTUnref<SkPicture> picture1(recorder.endRecording());
>>>>>>> miniblink49

    result->allocN32Pixels(width, height);
    SkCanvas canvas(*result);
    canvas.clear(0);
    canvas.clipRect(SkRect::Make(SkIRect::MakeWH(tileSize, tileSize)));
    canvas.drawPicture(picture1.get());
}

<<<<<<< HEAD
DEF_TEST(ImageFilterDrawMatrixBBH, reporter)
{
=======
DEF_TEST(ImageFilterDrawMatrixBBH, reporter) {
>>>>>>> miniblink49
    // Check that matrix filter when drawn tiled with BBH exactly
    // matches the same thing drawn without BBH.
    // Tests pass by not asserting.

    const int width = 200, height = 200;
    const int tileSize = 100;
    SkBitmap result1, result2;
    SkRTreeFactory factory;

    draw_saveLayer_picture(width, height, tileSize, &factory, &result1);
<<<<<<< HEAD
    draw_saveLayer_picture(width, height, tileSize, nullptr, &result2);
=======
    draw_saveLayer_picture(width, height, tileSize, NULL, &result2);
>>>>>>> miniblink49

    for (int y = 0; y < height; y++) {
        int diffs = memcmp(result1.getAddr32(0, y), result2.getAddr32(0, y), result1.rowBytes());
        REPORTER_ASSERT(reporter, !diffs);
        if (diffs) {
            break;
        }
    }
}

<<<<<<< HEAD
static sk_sp<SkImageFilter> make_blur(sk_sp<SkImageFilter> input)
{
    return SkBlurImageFilter::Make(SK_Scalar1, SK_Scalar1, std::move(input));
}

static sk_sp<SkImageFilter> make_drop_shadow(sk_sp<SkImageFilter> input)
{
    return SkDropShadowImageFilter::Make(
        SkIntToScalar(100), SkIntToScalar(100),
        SkIntToScalar(10), SkIntToScalar(10),
        SK_ColorBLUE, SkDropShadowImageFilter::kDrawShadowAndForeground_ShadowMode,
        std::move(input));
}

DEF_TEST(ImageFilterBlurThenShadowBounds, reporter)
{
    sk_sp<SkImageFilter> filter1(make_blur(nullptr));
    sk_sp<SkImageFilter> filter2(make_drop_shadow(std::move(filter1)));

    SkIRect bounds = SkIRect::MakeXYWH(0, 0, 100, 100);
    SkIRect expectedBounds = SkIRect::MakeXYWH(-133, -133, 236, 236);
    bounds = filter2->filterBounds(bounds, SkMatrix::I());
=======
static SkImageFilter* makeBlur(SkImageFilter* input = NULL) {
    return SkBlurImageFilter::Create(SK_Scalar1, SK_Scalar1, input);
}

static SkImageFilter* makeDropShadow(SkImageFilter* input = NULL) {
    return SkDropShadowImageFilter::Create(
        SkIntToScalar(100), SkIntToScalar(100),
        SkIntToScalar(10), SkIntToScalar(10),
        SK_ColorBLUE, SkDropShadowImageFilter::kDrawShadowAndForeground_ShadowMode,
        input, NULL);
}

DEF_TEST(ImageFilterBlurThenShadowBounds, reporter) {
    SkAutoTUnref<SkImageFilter> filter1(makeBlur());
    SkAutoTUnref<SkImageFilter> filter2(makeDropShadow(filter1.get()));

    SkIRect bounds = SkIRect::MakeXYWH(0, 0, 100, 100);
    SkIRect expectedBounds = SkIRect::MakeXYWH(-133, -133, 236, 236);
    filter2->filterBounds(bounds, SkMatrix::I(), &bounds);
>>>>>>> miniblink49

    REPORTER_ASSERT(reporter, bounds == expectedBounds);
}

<<<<<<< HEAD
DEF_TEST(ImageFilterShadowThenBlurBounds, reporter)
{
    sk_sp<SkImageFilter> filter1(make_drop_shadow(nullptr));
    sk_sp<SkImageFilter> filter2(make_blur(std::move(filter1)));

    SkIRect bounds = SkIRect::MakeXYWH(0, 0, 100, 100);
    SkIRect expectedBounds = SkIRect::MakeXYWH(-133, -133, 236, 236);
    bounds = filter2->filterBounds(bounds, SkMatrix::I());
=======
DEF_TEST(ImageFilterShadowThenBlurBounds, reporter) {
    SkAutoTUnref<SkImageFilter> filter1(makeDropShadow());
    SkAutoTUnref<SkImageFilter> filter2(makeBlur(filter1.get()));

    SkIRect bounds = SkIRect::MakeXYWH(0, 0, 100, 100);
    SkIRect expectedBounds = SkIRect::MakeXYWH(-133, -133, 236, 236);
    filter2->filterBounds(bounds, SkMatrix::I(), &bounds);
>>>>>>> miniblink49

    REPORTER_ASSERT(reporter, bounds == expectedBounds);
}

<<<<<<< HEAD
DEF_TEST(ImageFilterDilateThenBlurBounds, reporter)
{
    sk_sp<SkImageFilter> filter1(SkDilateImageFilter::Make(2, 2, nullptr));
    sk_sp<SkImageFilter> filter2(make_drop_shadow(std::move(filter1)));

    SkIRect bounds = SkIRect::MakeXYWH(0, 0, 100, 100);
    SkIRect expectedBounds = SkIRect::MakeXYWH(-132, -132, 234, 234);
    bounds = filter2->filterBounds(bounds, SkMatrix::I());
=======
DEF_TEST(ImageFilterDilateThenBlurBounds, reporter) {
    SkAutoTUnref<SkImageFilter> filter1(SkDilateImageFilter::Create(2, 2));
    SkAutoTUnref<SkImageFilter> filter2(makeDropShadow(filter1.get()));

    SkIRect bounds = SkIRect::MakeXYWH(0, 0, 100, 100);
    SkIRect expectedBounds = SkIRect::MakeXYWH(-132, -132, 234, 234);
    filter2->filterBounds(bounds, SkMatrix::I(), &bounds);
>>>>>>> miniblink49

    REPORTER_ASSERT(reporter, bounds == expectedBounds);
}

<<<<<<< HEAD
DEF_TEST(ImageFilterComposedBlurFastBounds, reporter)
{
    sk_sp<SkImageFilter> filter1(make_blur(nullptr));
    sk_sp<SkImageFilter> filter2(make_blur(nullptr));
    sk_sp<SkImageFilter> composedFilter(SkComposeImageFilter::Make(std::move(filter1),
        std::move(filter2)));
=======
DEF_TEST(ImageFilterComposedBlurFastBounds, reporter) {
    SkAutoTUnref<SkImageFilter> filter1(makeBlur());
    SkAutoTUnref<SkImageFilter> filter2(makeBlur());
    SkAutoTUnref<SkImageFilter> composedFilter(SkComposeImageFilter::Create(filter1.get(), filter2.get()));
>>>>>>> miniblink49

    SkRect boundsSrc = SkRect::MakeWH(SkIntToScalar(100), SkIntToScalar(100));
    SkRect expectedBounds = SkRect::MakeXYWH(
        SkIntToScalar(-6), SkIntToScalar(-6), SkIntToScalar(112), SkIntToScalar(112));
<<<<<<< HEAD
    SkRect boundsDst = composedFilter->computeFastBounds(boundsSrc);
=======
    SkRect boundsDst = SkRect::MakeEmpty();
    composedFilter->computeFastBounds(boundsSrc, &boundsDst);
>>>>>>> miniblink49

    REPORTER_ASSERT(reporter, boundsDst == expectedBounds);
}

<<<<<<< HEAD
DEF_TEST(ImageFilterUnionBounds, reporter)
{
    sk_sp<SkImageFilter> offset(SkOffsetImageFilter::Make(50, 0, nullptr));
    // Regardless of which order they appear in, the image filter bounds should
    // be combined correctly.
    {
        sk_sp<SkImageFilter> composite(SkXfermodeImageFilter::Make(nullptr, offset));
        SkRect bounds = SkRect::MakeWH(100, 100);
        // Intentionally aliasing here, as that's what the real callers do.
        bounds = composite->computeFastBounds(bounds);
        REPORTER_ASSERT(reporter, bounds == SkRect::MakeWH(150, 100));
    }
    {
        sk_sp<SkImageFilter> composite(SkXfermodeImageFilter::Make(nullptr, nullptr,
            offset, nullptr));
        SkRect bounds = SkRect::MakeWH(100, 100);
        // Intentionally aliasing here, as that's what the real callers do.
        bounds = composite->computeFastBounds(bounds);
        REPORTER_ASSERT(reporter, bounds == SkRect::MakeWH(150, 100));
    }
}

static void test_imagefilter_merge_result_size(skiatest::Reporter* reporter, GrContext* context)
{
    SkBitmap greenBM;
    greenBM.allocN32Pixels(20, 20);
    greenBM.eraseColor(SK_ColorGREEN);
    sk_sp<SkImage> greenImage(SkImage::MakeFromBitmap(greenBM));
    sk_sp<SkImageFilter> source(SkImageSource::Make(std::move(greenImage)));
    sk_sp<SkImageFilter> merge(SkMergeImageFilter::Make(source, source));

    sk_sp<SkSpecialImage> srcImg(create_empty_special_image(context, 1));

    SkImageFilter::Context ctx(SkMatrix::I(), SkIRect::MakeXYWH(0, 0, 100, 100), nullptr);
    SkIPoint offset;

    sk_sp<SkSpecialImage> resultImg(merge->filterImage(srcImg.get(), ctx, &offset));
    REPORTER_ASSERT(reporter, resultImg);

    REPORTER_ASSERT(reporter, resultImg->width() == 20 && resultImg->height() == 20);
}

DEF_TEST(ImageFilterMergeResultSize, reporter)
{
    test_imagefilter_merge_result_size(reporter, nullptr);
}

#if SK_SUPPORT_GPU
DEF_GPUTEST_FOR_RENDERING_CONTEXTS(ImageFilterMergeResultSize_Gpu, reporter, ctxInfo)
{
    test_imagefilter_merge_result_size(reporter, ctxInfo.grContext());
}
#endif

static void draw_blurred_rect(SkCanvas* canvas)
{
    SkPaint filterPaint;
    filterPaint.setColor(SK_ColorWHITE);
    filterPaint.setImageFilter(SkBlurImageFilter::Make(SkIntToScalar(8), 0, nullptr));
    canvas->saveLayer(nullptr, &filterPaint);
=======
static void draw_blurred_rect(SkCanvas* canvas) {
    SkAutoTUnref<SkImageFilter> filter(SkBlurImageFilter::Create(SkIntToScalar(8), 0));
    SkPaint filterPaint;
    filterPaint.setColor(SK_ColorWHITE);
    filterPaint.setImageFilter(filter);
    canvas->saveLayer(NULL, &filterPaint);
>>>>>>> miniblink49
    SkPaint whitePaint;
    whitePaint.setColor(SK_ColorWHITE);
    canvas->drawRect(SkRect::Make(SkIRect::MakeWH(4, 4)), whitePaint);
    canvas->restore();
}

<<<<<<< HEAD
static void draw_picture_clipped(SkCanvas* canvas, const SkRect& clipRect, const SkPicture* picture)
{
=======
static void draw_picture_clipped(SkCanvas* canvas, const SkRect& clipRect, const SkPicture* picture) {
>>>>>>> miniblink49
    canvas->save();
    canvas->clipRect(clipRect);
    canvas->drawPicture(picture);
    canvas->restore();
}

<<<<<<< HEAD
DEF_TEST(ImageFilterDrawTiledBlurRTree, reporter)
{
=======
DEF_TEST(ImageFilterDrawTiledBlurRTree, reporter) {
>>>>>>> miniblink49
    // Check that the blur filter when recorded with RTree acceleration,
    // and drawn tiled (with subsequent clip rects) exactly
    // matches the same filter drawn with without RTree acceleration.
    // This tests that the "bleed" from the blur into the otherwise-blank
    // tiles is correctly rendered.
    // Tests pass by not asserting.

    int width = 16, height = 8;
    SkBitmap result1, result2;
    result1.allocN32Pixels(width, height);
    result2.allocN32Pixels(width, height);
    SkCanvas canvas1(result1);
    SkCanvas canvas2(result2);
    int tileSize = 8;

    canvas1.clear(0);
    canvas2.clear(0);

    SkRTreeFactory factory;

    SkPictureRecorder recorder1, recorder2;
    // The only difference between these two pictures is that one has RTree aceleration.
    SkCanvas* recordingCanvas1 = recorder1.beginRecording(SkIntToScalar(width),
<<<<<<< HEAD
        SkIntToScalar(height),
        nullptr, 0);
    SkCanvas* recordingCanvas2 = recorder2.beginRecording(SkIntToScalar(width),
        SkIntToScalar(height),
        &factory, 0);
    draw_blurred_rect(recordingCanvas1);
    draw_blurred_rect(recordingCanvas2);
    sk_sp<SkPicture> picture1(recorder1.finishRecordingAsPicture());
    sk_sp<SkPicture> picture2(recorder2.finishRecordingAsPicture());
    for (int y = 0; y < height; y += tileSize) {
        for (int x = 0; x < width; x += tileSize) {
            SkRect tileRect = SkRect::Make(SkIRect::MakeXYWH(x, y, tileSize, tileSize));
            draw_picture_clipped(&canvas1, tileRect, picture1.get());
            draw_picture_clipped(&canvas2, tileRect, picture2.get());
=======
                                                          SkIntToScalar(height),
                                                          NULL, 0);
    SkCanvas* recordingCanvas2 = recorder2.beginRecording(SkIntToScalar(width),
                                                          SkIntToScalar(height),
                                                          &factory, 0);
    draw_blurred_rect(recordingCanvas1);
    draw_blurred_rect(recordingCanvas2);
    SkAutoTUnref<SkPicture> picture1(recorder1.endRecording());
    SkAutoTUnref<SkPicture> picture2(recorder2.endRecording());
    for (int y = 0; y < height; y += tileSize) {
        for (int x = 0; x < width; x += tileSize) {
            SkRect tileRect = SkRect::Make(SkIRect::MakeXYWH(x, y, tileSize, tileSize));
            draw_picture_clipped(&canvas1, tileRect, picture1);
            draw_picture_clipped(&canvas2, tileRect, picture2);
>>>>>>> miniblink49
        }
    }
    for (int y = 0; y < height; y++) {
        int diffs = memcmp(result1.getAddr32(0, y), result2.getAddr32(0, y), result1.rowBytes());
        REPORTER_ASSERT(reporter, !diffs);
        if (diffs) {
            break;
        }
    }
}

<<<<<<< HEAD
DEF_TEST(ImageFilterMatrixConvolution, reporter)
{
    // Check that a 1x3 filter does not cause a spurious assert.
    SkScalar kernel[3] = {
        SkIntToScalar(1),
        SkIntToScalar(1),
        SkIntToScalar(1),
=======
DEF_TEST(ImageFilterMatrixConvolution, reporter) {
    // Check that a 1x3 filter does not cause a spurious assert.
    SkScalar kernel[3] = {
        SkIntToScalar( 1), SkIntToScalar( 1), SkIntToScalar( 1),
>>>>>>> miniblink49
    };
    SkISize kernelSize = SkISize::Make(1, 3);
    SkScalar gain = SK_Scalar1, bias = 0;
    SkIPoint kernelOffset = SkIPoint::Make(0, 0);

<<<<<<< HEAD
    sk_sp<SkImageFilter> filter(SkMatrixConvolutionImageFilter::Make(
        kernelSize, kernel,
        gain, bias, kernelOffset,
        SkMatrixConvolutionImageFilter::kRepeat_TileMode,
        false, nullptr));
=======
    SkAutoTUnref<SkImageFilter> filter(
        SkMatrixConvolutionImageFilter::Create(
            kernelSize, kernel, gain, bias, kernelOffset,
            SkMatrixConvolutionImageFilter::kRepeat_TileMode, false));
>>>>>>> miniblink49

    SkBitmap result;
    int width = 16, height = 16;
    result.allocN32Pixels(width, height);
    SkCanvas canvas(result);
    canvas.clear(0);

    SkPaint paint;
<<<<<<< HEAD
    paint.setImageFilter(std::move(filter));
=======
    paint.setImageFilter(filter);
>>>>>>> miniblink49
    SkRect rect = SkRect::Make(SkIRect::MakeWH(width, height));
    canvas.drawRect(rect, paint);
}

<<<<<<< HEAD
DEF_TEST(ImageFilterMatrixConvolutionBorder, reporter)
{
    // Check that a filter with borders outside the target bounds
    // does not crash.
    SkScalar kernel[3] = {
        0,
        0,
        0,
=======
DEF_TEST(ImageFilterMatrixConvolutionBorder, reporter) {
    // Check that a filter with borders outside the target bounds
    // does not crash.
    SkScalar kernel[3] = {
        0, 0, 0,
>>>>>>> miniblink49
    };
    SkISize kernelSize = SkISize::Make(3, 1);
    SkScalar gain = SK_Scalar1, bias = 0;
    SkIPoint kernelOffset = SkIPoint::Make(2, 0);

<<<<<<< HEAD
    sk_sp<SkImageFilter> filter(SkMatrixConvolutionImageFilter::Make(
        kernelSize, kernel, gain, bias, kernelOffset,
        SkMatrixConvolutionImageFilter::kClamp_TileMode,
        true, nullptr));
=======
    SkAutoTUnref<SkImageFilter> filter(
        SkMatrixConvolutionImageFilter::Create(
            kernelSize, kernel, gain, bias, kernelOffset,
            SkMatrixConvolutionImageFilter::kClamp_TileMode, true));
>>>>>>> miniblink49

    SkBitmap result;

    int width = 10, height = 10;
    result.allocN32Pixels(width, height);
    SkCanvas canvas(result);
    canvas.clear(0);

    SkPaint filterPaint;
<<<<<<< HEAD
    filterPaint.setImageFilter(std::move(filter));
=======
    filterPaint.setImageFilter(filter);
>>>>>>> miniblink49
    SkRect bounds = SkRect::MakeWH(1, 10);
    SkRect rect = SkRect::Make(SkIRect::MakeWH(width, height));
    SkPaint rectPaint;
    canvas.saveLayer(&bounds, &filterPaint);
    canvas.drawRect(rect, rectPaint);
    canvas.restore();
}

<<<<<<< HEAD
static void test_big_kernel(skiatest::Reporter* reporter, GrContext* context)
{
    // Check that a kernel that is too big for the GPU still works
    SkScalar identityKernel[49] = {
        0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 1, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0
    };
    SkISize kernelSize = SkISize::Make(7, 7);
    SkScalar gain = SK_Scalar1, bias = 0;
    SkIPoint kernelOffset = SkIPoint::Make(0, 0);

    sk_sp<SkImageFilter> filter(SkMatrixConvolutionImageFilter::Make(
        kernelSize, identityKernel, gain, bias, kernelOffset,
        SkMatrixConvolutionImageFilter::kClamp_TileMode,
        true, nullptr));

    sk_sp<SkSpecialImage> srcImg(create_empty_special_image(context, 100));
    SkASSERT(srcImg);

    SkIPoint offset;
    SkImageFilter::Context ctx(SkMatrix::I(), SkIRect::MakeWH(100, 100), nullptr);
    sk_sp<SkSpecialImage> resultImg(filter->filterImage(srcImg.get(), ctx, &offset));
    REPORTER_ASSERT(reporter, resultImg);
    REPORTER_ASSERT(reporter, SkToBool(context) == resultImg->isTextureBacked());
    REPORTER_ASSERT(reporter, resultImg->width() == 100 && resultImg->height() == 100);
    REPORTER_ASSERT(reporter, offset.fX == 0 && offset.fY == 0);
}

DEF_TEST(ImageFilterMatrixConvolutionBigKernel, reporter)
{
    test_big_kernel(reporter, nullptr);
}

#if SK_SUPPORT_GPU
DEF_GPUTEST_FOR_RENDERING_CONTEXTS(ImageFilterMatrixConvolutionBigKernel_Gpu,
    reporter, ctxInfo)
{
    test_big_kernel(reporter, ctxInfo.grContext());
}
#endif

DEF_TEST(ImageFilterCropRect, reporter)
{
    test_crop_rects(reporter, nullptr);
}

#if SK_SUPPORT_GPU
DEF_GPUTEST_FOR_RENDERING_CONTEXTS(ImageFilterCropRect_Gpu, reporter, ctxInfo)
{
    test_crop_rects(reporter, ctxInfo.grContext());
}
#endif

DEF_TEST(ImageFilterMatrix, reporter)
{
=======
DEF_TEST(ImageFilterCropRect, reporter) {
    const SkImageInfo info = SkImageInfo::MakeN32Premul(100, 100);
    const SkSurfaceProps props(SkSurfaceProps::kLegacyFontHost_InitType);

    SkAutoTUnref<SkBaseDevice> device(SkBitmapDevice::Create(info, props));
    SkImageFilter::Proxy proxy(device);

    test_crop_rects(&proxy, reporter);
}

DEF_TEST(ImageFilterMatrix, reporter) {
>>>>>>> miniblink49
    SkBitmap temp;
    temp.allocN32Pixels(100, 100);
    SkCanvas canvas(temp);
    canvas.scale(SkIntToScalar(2), SkIntToScalar(2));

    SkMatrix expectedMatrix = canvas.getTotalMatrix();

    SkRTreeFactory factory;
    SkPictureRecorder recorder;
    SkCanvas* recordingCanvas = recorder.beginRecording(100, 100, &factory, 0);

    SkPaint paint;
<<<<<<< HEAD
    paint.setImageFilter(MatrixTestImageFilter::Make(reporter, expectedMatrix));
    recordingCanvas->saveLayer(nullptr, &paint);
=======
    SkAutoTUnref<MatrixTestImageFilter> imageFilter(
        new MatrixTestImageFilter(reporter, expectedMatrix));
    paint.setImageFilter(imageFilter.get());
    recordingCanvas->saveLayer(NULL, &paint);
>>>>>>> miniblink49
    SkPaint solidPaint;
    solidPaint.setColor(0xFFFFFFFF);
    recordingCanvas->save();
    recordingCanvas->scale(SkIntToScalar(10), SkIntToScalar(10));
    recordingCanvas->drawRect(SkRect::Make(SkIRect::MakeWH(100, 100)), solidPaint);
    recordingCanvas->restore(); // scale
    recordingCanvas->restore(); // saveLayer
<<<<<<< HEAD

    canvas.drawPicture(recorder.finishRecordingAsPicture());
}

DEF_TEST(ImageFilterCrossProcessPictureImageFilter, reporter)
{
=======
    SkAutoTUnref<SkPicture> picture(recorder.endRecording());

    canvas.drawPicture(picture);
}

DEF_TEST(ImageFilterCrossProcessPictureImageFilter, reporter) {
>>>>>>> miniblink49
    SkRTreeFactory factory;
    SkPictureRecorder recorder;
    SkCanvas* recordingCanvas = recorder.beginRecording(1, 1, &factory, 0);

    // Create an SkPicture which simply draws a green 1x1 rectangle.
    SkPaint greenPaint;
    greenPaint.setColor(SK_ColorGREEN);
    recordingCanvas->drawRect(SkRect::Make(SkIRect::MakeWH(1, 1)), greenPaint);
<<<<<<< HEAD
    sk_sp<SkPicture> picture(recorder.finishRecordingAsPicture());

    // Wrap that SkPicture in an SkPictureImageFilter.
    sk_sp<SkImageFilter> imageFilter(SkPictureImageFilter::Make(picture));
=======
    SkAutoTUnref<SkPicture> picture(recorder.endRecording());

    // Wrap that SkPicture in an SkPictureImageFilter.
    SkAutoTUnref<SkImageFilter> imageFilter(
        SkPictureImageFilter::Create(picture.get()));
>>>>>>> miniblink49

    // Check that SkPictureImageFilter successfully serializes its contained
    // SkPicture when not in cross-process mode.
    SkPaint paint;
<<<<<<< HEAD
    paint.setImageFilter(imageFilter);
=======
    paint.setImageFilter(imageFilter.get());
>>>>>>> miniblink49
    SkPictureRecorder outerRecorder;
    SkCanvas* outerCanvas = outerRecorder.beginRecording(1, 1, &factory, 0);
    SkPaint redPaintWithFilter;
    redPaintWithFilter.setColor(SK_ColorRED);
<<<<<<< HEAD
    redPaintWithFilter.setImageFilter(imageFilter);
    outerCanvas->drawRect(SkRect::Make(SkIRect::MakeWH(1, 1)), redPaintWithFilter);
    sk_sp<SkPicture> outerPicture(outerRecorder.finishRecordingAsPicture());
=======
    redPaintWithFilter.setImageFilter(imageFilter.get());
    outerCanvas->drawRect(SkRect::Make(SkIRect::MakeWH(1, 1)), redPaintWithFilter);
    SkAutoTUnref<SkPicture> outerPicture(outerRecorder.endRecording());
>>>>>>> miniblink49

    SkBitmap bitmap;
    bitmap.allocN32Pixels(1, 1);
    SkCanvas canvas(bitmap);

    // The result here should be green, since the filter replaces the primitive's red interior.
    canvas.clear(0x0);
    canvas.drawPicture(outerPicture);
    uint32_t pixel = *bitmap.getAddr32(0, 0);
    REPORTER_ASSERT(reporter, pixel == SK_ColorGREEN);

    // Check that, for now, SkPictureImageFilter does not serialize or
    // deserialize its contained picture when the filter is serialized
    // cross-process. Do this by "laundering" it through SkValidatingReadBuffer.
<<<<<<< HEAD
    sk_sp<SkData> data(SkValidatingSerializeFlattenable(imageFilter.get()));
    sk_sp<SkFlattenable> flattenable(SkValidatingDeserializeFlattenable(
=======
    SkAutoTUnref<SkData> data(SkValidatingSerializeFlattenable(imageFilter.get()));
    SkAutoTUnref<SkFlattenable> flattenable(SkValidatingDeserializeFlattenable(
>>>>>>> miniblink49
        data->data(), data->size(), SkImageFilter::GetFlattenableType()));
    SkImageFilter* unflattenedFilter = static_cast<SkImageFilter*>(flattenable.get());

    redPaintWithFilter.setImageFilter(unflattenedFilter);
    SkPictureRecorder crossProcessRecorder;
    SkCanvas* crossProcessCanvas = crossProcessRecorder.beginRecording(1, 1, &factory, 0);
    crossProcessCanvas->drawRect(SkRect::Make(SkIRect::MakeWH(1, 1)), redPaintWithFilter);
<<<<<<< HEAD
    sk_sp<SkPicture> crossProcessPicture(crossProcessRecorder.finishRecordingAsPicture());
=======
    SkAutoTUnref<SkPicture> crossProcessPicture(crossProcessRecorder.endRecording());
>>>>>>> miniblink49

    canvas.clear(0x0);
    canvas.drawPicture(crossProcessPicture);
    pixel = *bitmap.getAddr32(0, 0);
    // If the security precautions are enabled, the result here should not be green, since the
    // filter draws nothing.
<<<<<<< HEAD
    REPORTER_ASSERT(reporter, SkPicture::PictureIOSecurityPrecautionsEnabled() ? pixel != SK_ColorGREEN : pixel == SK_ColorGREEN);
}

static void test_clipped_picture_imagefilter(skiatest::Reporter* reporter, GrContext* context)
{
    sk_sp<SkPicture> picture;

    {
        SkRTreeFactory factory;
        SkPictureRecorder recorder;
        SkCanvas* recordingCanvas = recorder.beginRecording(1, 1, &factory, 0);

        // Create an SkPicture which simply draws a green 1x1 rectangle.
        SkPaint greenPaint;
        greenPaint.setColor(SK_ColorGREEN);
        recordingCanvas->drawRect(SkRect::Make(SkIRect::MakeWH(1, 1)), greenPaint);
        picture = recorder.finishRecordingAsPicture();
    }

    sk_sp<SkSpecialImage> srcImg(create_empty_special_image(context, 2));

    sk_sp<SkImageFilter> imageFilter(SkPictureImageFilter::Make(picture));

    SkIPoint offset;
    SkImageFilter::Context ctx(SkMatrix::I(), SkIRect::MakeXYWH(1, 1, 1, 1), nullptr);

    sk_sp<SkSpecialImage> resultImage(imageFilter->filterImage(srcImg.get(), ctx, &offset));
    REPORTER_ASSERT(reporter, !resultImage);
}

DEF_TEST(ImageFilterClippedPictureImageFilter, reporter)
{
    test_clipped_picture_imagefilter(reporter, nullptr);
}

#if SK_SUPPORT_GPU
DEF_GPUTEST_FOR_RENDERING_CONTEXTS(ImageFilterClippedPictureImageFilter_Gpu, reporter, ctxInfo)
{
    test_clipped_picture_imagefilter(reporter, ctxInfo.grContext());
}
#endif

DEF_TEST(ImageFilterEmptySaveLayer, reporter)
{
=======
    REPORTER_ASSERT(reporter, SkPicture::PictureIOSecurityPrecautionsEnabled() 
        ? pixel != SK_ColorGREEN : pixel == SK_ColorGREEN);
}

DEF_TEST(ImageFilterClippedPictureImageFilter, reporter) {
    SkRTreeFactory factory;
    SkPictureRecorder recorder;
    SkCanvas* recordingCanvas = recorder.beginRecording(1, 1, &factory, 0);

    // Create an SkPicture which simply draws a green 1x1 rectangle.
    SkPaint greenPaint;
    greenPaint.setColor(SK_ColorGREEN);
    recordingCanvas->drawRect(SkRect::Make(SkIRect::MakeWH(1, 1)), greenPaint);
    SkAutoTUnref<SkPicture> picture(recorder.endRecording());

    SkAutoTUnref<SkImageFilter> imageFilter(SkPictureImageFilter::Create(picture.get()));

    SkBitmap result;
    SkIPoint offset;
    SkImageFilter::Context ctx(SkMatrix::I(), SkIRect::MakeXYWH(1, 1, 1, 1), NULL);
    SkBitmap bitmap;
    bitmap.allocN32Pixels(2, 2);
    const SkSurfaceProps props(SkSurfaceProps::kLegacyFontHost_InitType);
    SkBitmapDevice device(bitmap, props);
    SkImageFilter::Proxy proxy(&device);
    REPORTER_ASSERT(reporter, !imageFilter->filterImage(&proxy, bitmap, ctx, &result, &offset));
}

DEF_TEST(ImageFilterEmptySaveLayer, reporter) {
>>>>>>> miniblink49
    // Even when there's an empty saveLayer()/restore(), ensure that an image
    // filter or color filter which affects transparent black still draws.

    SkBitmap bitmap;
    bitmap.allocN32Pixels(10, 10);
    SkCanvas canvas(bitmap);

    SkRTreeFactory factory;
    SkPictureRecorder recorder;

<<<<<<< HEAD
    sk_sp<SkColorFilter> green(SkColorFilter::MakeModeFilter(SK_ColorGREEN,
        SkXfermode::kSrc_Mode));
    sk_sp<SkImageFilter> imageFilter(SkColorFilterImageFilter::Make(green, nullptr));
    SkPaint imageFilterPaint;
    imageFilterPaint.setImageFilter(std::move(imageFilter));
    SkPaint colorFilterPaint;
    colorFilterPaint.setColorFilter(green);
=======
    SkAutoTUnref<SkColorFilter> green(
        SkColorFilter::CreateModeFilter(SK_ColorGREEN, SkXfermode::kSrc_Mode));
    SkAutoTUnref<SkColorFilterImageFilter> imageFilter(
        SkColorFilterImageFilter::Create(green.get()));
    SkPaint imageFilterPaint;
    imageFilterPaint.setImageFilter(imageFilter.get());
    SkPaint colorFilterPaint;
    colorFilterPaint.setColorFilter(green.get());
>>>>>>> miniblink49

    SkRect bounds = SkRect::MakeWH(10, 10);

    SkCanvas* recordingCanvas = recorder.beginRecording(10, 10, &factory, 0);
    recordingCanvas->saveLayer(&bounds, &imageFilterPaint);
    recordingCanvas->restore();
<<<<<<< HEAD
    sk_sp<SkPicture> picture(recorder.finishRecordingAsPicture());
=======
    SkAutoTUnref<SkPicture> picture(recorder.endRecording());
>>>>>>> miniblink49

    canvas.clear(0);
    canvas.drawPicture(picture);
    uint32_t pixel = *bitmap.getAddr32(0, 0);
    REPORTER_ASSERT(reporter, pixel == SK_ColorGREEN);

    recordingCanvas = recorder.beginRecording(10, 10, &factory, 0);
<<<<<<< HEAD
    recordingCanvas->saveLayer(nullptr, &imageFilterPaint);
    recordingCanvas->restore();
    sk_sp<SkPicture> picture2(recorder.finishRecordingAsPicture());
=======
    recordingCanvas->saveLayer(NULL, &imageFilterPaint);
    recordingCanvas->restore();
    SkAutoTUnref<SkPicture> picture2(recorder.endRecording());
>>>>>>> miniblink49

    canvas.clear(0);
    canvas.drawPicture(picture2);
    pixel = *bitmap.getAddr32(0, 0);
    REPORTER_ASSERT(reporter, pixel == SK_ColorGREEN);

    recordingCanvas = recorder.beginRecording(10, 10, &factory, 0);
    recordingCanvas->saveLayer(&bounds, &colorFilterPaint);
    recordingCanvas->restore();
<<<<<<< HEAD
    sk_sp<SkPicture> picture3(recorder.finishRecordingAsPicture());
=======
    SkAutoTUnref<SkPicture> picture3(recorder.endRecording());
>>>>>>> miniblink49

    canvas.clear(0);
    canvas.drawPicture(picture3);
    pixel = *bitmap.getAddr32(0, 0);
    REPORTER_ASSERT(reporter, pixel == SK_ColorGREEN);
}

<<<<<<< HEAD
static void test_huge_blur(SkCanvas* canvas, skiatest::Reporter* reporter)
{
=======
static void test_huge_blur(SkCanvas* canvas, skiatest::Reporter* reporter) {
>>>>>>> miniblink49
    SkBitmap bitmap;
    bitmap.allocN32Pixels(100, 100);
    bitmap.eraseARGB(0, 0, 0, 0);

    // Check that a blur with an insane radius does not crash or assert.
<<<<<<< HEAD
    SkPaint paint;
    paint.setImageFilter(SkBlurImageFilter::Make(SkIntToScalar(1 << 30),
        SkIntToScalar(1 << 30),
        nullptr));
    canvas->drawBitmap(bitmap, 0, 0, &paint);
}

DEF_TEST(HugeBlurImageFilter, reporter)
{
=======
    SkAutoTUnref<SkImageFilter> blur(SkBlurImageFilter::Create(SkIntToScalar(1<<30), SkIntToScalar(1<<30)));

    SkPaint paint;
    paint.setImageFilter(blur);
    canvas->drawSprite(bitmap, 0, 0, &paint);
}

DEF_TEST(HugeBlurImageFilter, reporter) {
>>>>>>> miniblink49
    SkBitmap temp;
    temp.allocN32Pixels(100, 100);
    SkCanvas canvas(temp);
    test_huge_blur(&canvas, reporter);
}

<<<<<<< HEAD
DEF_TEST(ImageFilterMatrixConvolutionSanityTest, reporter)
{
=======
DEF_TEST(MatrixConvolutionSanityTest, reporter) {
>>>>>>> miniblink49
    SkScalar kernel[1] = { 0 };
    SkScalar gain = SK_Scalar1, bias = 0;
    SkIPoint kernelOffset = SkIPoint::Make(1, 1);

<<<<<<< HEAD
    // Check that an enormous (non-allocatable) kernel gives a nullptr filter.
    sk_sp<SkImageFilter> conv(SkMatrixConvolutionImageFilter::Make(
        SkISize::Make(1 << 30, 1 << 30),
=======
    // Check that an enormous (non-allocatable) kernel gives a NULL filter.
    SkAutoTUnref<SkImageFilter> conv(SkMatrixConvolutionImageFilter::Create(
        SkISize::Make(1<<30, 1<<30),
>>>>>>> miniblink49
        kernel,
        gain,
        bias,
        kernelOffset,
        SkMatrixConvolutionImageFilter::kRepeat_TileMode,
<<<<<<< HEAD
        false,
        nullptr));

    REPORTER_ASSERT(reporter, nullptr == conv.get());

    // Check that a nullptr kernel gives a nullptr filter.
    conv = SkMatrixConvolutionImageFilter::Make(
        SkISize::Make(1, 1),
        nullptr,
=======
        false));

    REPORTER_ASSERT(reporter, NULL == conv.get());

    // Check that a NULL kernel gives a NULL filter.
    conv.reset(SkMatrixConvolutionImageFilter::Create(
        SkISize::Make(1, 1),
        NULL,
>>>>>>> miniblink49
        gain,
        bias,
        kernelOffset,
        SkMatrixConvolutionImageFilter::kRepeat_TileMode,
<<<<<<< HEAD
        false,
        nullptr);

    REPORTER_ASSERT(reporter, nullptr == conv.get());

    // Check that a kernel width < 1 gives a nullptr filter.
    conv = SkMatrixConvolutionImageFilter::Make(
=======
        false));

    REPORTER_ASSERT(reporter, NULL == conv.get());

    // Check that a kernel width < 1 gives a NULL filter.
    conv.reset(SkMatrixConvolutionImageFilter::Create(
>>>>>>> miniblink49
        SkISize::Make(0, 1),
        kernel,
        gain,
        bias,
        kernelOffset,
        SkMatrixConvolutionImageFilter::kRepeat_TileMode,
<<<<<<< HEAD
        false,
        nullptr);

    REPORTER_ASSERT(reporter, nullptr == conv.get());

    // Check that kernel height < 1 gives a nullptr filter.
    conv = SkMatrixConvolutionImageFilter::Make(
=======
        false));

    REPORTER_ASSERT(reporter, NULL == conv.get());

    // Check that kernel height < 1 gives a NULL filter.
    conv.reset(SkMatrixConvolutionImageFilter::Create(
>>>>>>> miniblink49
        SkISize::Make(1, -1),
        kernel,
        gain,
        bias,
        kernelOffset,
        SkMatrixConvolutionImageFilter::kRepeat_TileMode,
<<<<<<< HEAD
        false,
        nullptr);

    REPORTER_ASSERT(reporter, nullptr == conv.get());
}

static void test_xfermode_cropped_input(SkCanvas* canvas, skiatest::Reporter* reporter)
{
=======
        false));

    REPORTER_ASSERT(reporter, NULL == conv.get());
}

static void test_xfermode_cropped_input(SkCanvas* canvas, skiatest::Reporter* reporter) {
>>>>>>> miniblink49
    canvas->clear(0);

    SkBitmap bitmap;
    bitmap.allocN32Pixels(1, 1);
    bitmap.eraseARGB(255, 255, 255, 255);

<<<<<<< HEAD
    sk_sp<SkColorFilter> green(SkColorFilter::MakeModeFilter(SK_ColorGREEN,
        SkXfermode::kSrcIn_Mode));
    sk_sp<SkImageFilter> greenFilter(SkColorFilterImageFilter::Make(green, nullptr));
    SkImageFilter::CropRect cropRect(SkRect::MakeEmpty());
    sk_sp<SkImageFilter> croppedOut(SkColorFilterImageFilter::Make(green, nullptr, &cropRect));

    // Check that an xfermode image filter whose input has been cropped out still draws the other
    // input. Also check that drawing with both inputs cropped out doesn't cause a GPU warning.
    sk_sp<SkXfermode> mode(SkXfermode::Make(SkXfermode::kSrcOver_Mode));
    sk_sp<SkImageFilter> xfermodeNoFg(SkXfermodeImageFilter::Make(mode, greenFilter,
        croppedOut, nullptr));
    sk_sp<SkImageFilter> xfermodeNoBg(SkXfermodeImageFilter::Make(mode, croppedOut,
        greenFilter, nullptr));
    sk_sp<SkImageFilter> xfermodeNoFgNoBg(SkXfermodeImageFilter::Make(mode, croppedOut,
        croppedOut, nullptr));

    SkPaint paint;
    paint.setImageFilter(std::move(xfermodeNoFg));
    canvas->drawBitmap(bitmap, 0, 0, &paint); // drawSprite
=======
    SkAutoTUnref<SkColorFilter> green(
        SkColorFilter::CreateModeFilter(SK_ColorGREEN, SkXfermode::kSrcIn_Mode));
    SkAutoTUnref<SkColorFilterImageFilter> greenFilter(
        SkColorFilterImageFilter::Create(green.get()));
    SkImageFilter::CropRect cropRect(SkRect::MakeEmpty());
    SkAutoTUnref<SkColorFilterImageFilter> croppedOut(
        SkColorFilterImageFilter::Create(green.get(), NULL, &cropRect));

    // Check that an xfermode image filter whose input has been cropped out still draws the other
    // input. Also check that drawing with both inputs cropped out doesn't cause a GPU warning.
    SkXfermode* mode = SkXfermode::Create(SkXfermode::kSrcOver_Mode);
    SkAutoTUnref<SkImageFilter> xfermodeNoFg(
        SkXfermodeImageFilter::Create(mode, greenFilter, croppedOut));
    SkAutoTUnref<SkImageFilter> xfermodeNoBg(
        SkXfermodeImageFilter::Create(mode, croppedOut, greenFilter));
    SkAutoTUnref<SkImageFilter> xfermodeNoFgNoBg(
        SkXfermodeImageFilter::Create(mode, croppedOut, croppedOut));

    SkPaint paint;
    paint.setImageFilter(xfermodeNoFg);
    canvas->drawSprite(bitmap, 0, 0, &paint);
>>>>>>> miniblink49

    uint32_t pixel;
    SkImageInfo info = SkImageInfo::Make(1, 1, kBGRA_8888_SkColorType, kUnpremul_SkAlphaType);
    canvas->readPixels(info, &pixel, 4, 0, 0);
    REPORTER_ASSERT(reporter, pixel == SK_ColorGREEN);

<<<<<<< HEAD
    paint.setImageFilter(std::move(xfermodeNoBg));
    canvas->drawBitmap(bitmap, 0, 0, &paint); // drawSprite
    canvas->readPixels(info, &pixel, 4, 0, 0);
    REPORTER_ASSERT(reporter, pixel == SK_ColorGREEN);

    paint.setImageFilter(std::move(xfermodeNoFgNoBg));
    canvas->drawBitmap(bitmap, 0, 0, &paint); // drawSprite
=======
    paint.setImageFilter(xfermodeNoBg);
    canvas->drawSprite(bitmap, 0, 0, &paint);
    canvas->readPixels(info, &pixel, 4, 0, 0);
    REPORTER_ASSERT(reporter, pixel == SK_ColorGREEN);

    paint.setImageFilter(xfermodeNoFgNoBg);
    canvas->drawSprite(bitmap, 0, 0, &paint);
>>>>>>> miniblink49
    canvas->readPixels(info, &pixel, 4, 0, 0);
    REPORTER_ASSERT(reporter, pixel == SK_ColorGREEN);
}

<<<<<<< HEAD
DEF_TEST(ImageFilterNestedSaveLayer, reporter)
{
=======
DEF_TEST(ImageFilterNestedSaveLayer, reporter) {
>>>>>>> miniblink49
    SkBitmap temp;
    temp.allocN32Pixels(50, 50);
    SkCanvas canvas(temp);
    canvas.clear(0x0);

    SkBitmap bitmap;
    bitmap.allocN32Pixels(10, 10);
    bitmap.eraseColor(SK_ColorGREEN);

    SkMatrix matrix;
    matrix.setScale(SkIntToScalar(2), SkIntToScalar(2));
    matrix.postTranslate(SkIntToScalar(-20), SkIntToScalar(-20));
<<<<<<< HEAD
    sk_sp<SkImageFilter> matrixFilter(
        SkImageFilter::MakeMatrixFilter(matrix, kLow_SkFilterQuality, nullptr));
=======
    SkAutoTUnref<SkImageFilter> matrixFilter(
        SkImageFilter::CreateMatrixFilter(matrix, kLow_SkFilterQuality));
>>>>>>> miniblink49

    // Test that saveLayer() with a filter nested inside another saveLayer() applies the
    // correct offset to the filter matrix.
    SkRect bounds1 = SkRect::MakeXYWH(10, 10, 30, 30);
<<<<<<< HEAD
    canvas.saveLayer(&bounds1, nullptr);
    SkPaint filterPaint;
    filterPaint.setImageFilter(std::move(matrixFilter));
=======
    canvas.saveLayer(&bounds1, NULL);
    SkPaint filterPaint;
    filterPaint.setImageFilter(matrixFilter);
>>>>>>> miniblink49
    SkRect bounds2 = SkRect::MakeXYWH(20, 20, 10, 10);
    canvas.saveLayer(&bounds2, &filterPaint);
    SkPaint greenPaint;
    greenPaint.setColor(SK_ColorGREEN);
    canvas.drawRect(bounds2, greenPaint);
    canvas.restore();
    canvas.restore();
    SkPaint strokePaint;
    strokePaint.setStyle(SkPaint::kStroke_Style);
    strokePaint.setColor(SK_ColorRED);

    SkImageInfo info = SkImageInfo::Make(1, 1, kBGRA_8888_SkColorType, kUnpremul_SkAlphaType);
    uint32_t pixel;
    canvas.readPixels(info, &pixel, 4, 25, 25);
    REPORTER_ASSERT(reporter, pixel == SK_ColorGREEN);

    // Test that drawSprite() with a filter nested inside a saveLayer() applies the
    // correct offset to the filter matrix.
    canvas.clear(0x0);
    canvas.readPixels(info, &pixel, 4, 25, 25);
<<<<<<< HEAD
    canvas.saveLayer(&bounds1, nullptr);
    canvas.drawBitmap(bitmap, 20, 20, &filterPaint); // drawSprite
=======
    canvas.saveLayer(&bounds1, NULL);
    canvas.drawSprite(bitmap, 20, 20, &filterPaint);
>>>>>>> miniblink49
    canvas.restore();

    canvas.readPixels(info, &pixel, 4, 25, 25);
    REPORTER_ASSERT(reporter, pixel == SK_ColorGREEN);
}

<<<<<<< HEAD
DEF_TEST(XfermodeImageFilterCroppedInput, reporter)
{
=======
DEF_TEST(XfermodeImageFilterCroppedInput, reporter) {
>>>>>>> miniblink49
    SkBitmap temp;
    temp.allocN32Pixels(100, 100);
    SkCanvas canvas(temp);
    test_xfermode_cropped_input(&canvas, reporter);
}

<<<<<<< HEAD
static void test_composed_imagefilter_offset(skiatest::Reporter* reporter, GrContext* context)
{
    sk_sp<SkSpecialImage> srcImg(create_empty_special_image(context, 100));

    SkImageFilter::CropRect cropRect(SkRect::MakeXYWH(1, 0, 20, 20));
    sk_sp<SkImageFilter> offsetFilter(SkOffsetImageFilter::Make(0, 0, nullptr, &cropRect));
    sk_sp<SkImageFilter> blurFilter(SkBlurImageFilter::Make(SK_Scalar1, SK_Scalar1,
        nullptr, &cropRect));
    sk_sp<SkImageFilter> composedFilter(SkComposeImageFilter::Make(std::move(blurFilter),
        std::move(offsetFilter)));
    SkIPoint offset;
    SkImageFilter::Context ctx(SkMatrix::I(), SkIRect::MakeWH(100, 100), nullptr);

    sk_sp<SkSpecialImage> resultImg(composedFilter->filterImage(srcImg.get(), ctx, &offset));
    REPORTER_ASSERT(reporter, resultImg);
    REPORTER_ASSERT(reporter, offset.fX == 1 && offset.fY == 0);
}

DEF_TEST(ComposedImageFilterOffset, reporter)
{
    test_composed_imagefilter_offset(reporter, nullptr);
}

#if SK_SUPPORT_GPU
DEF_GPUTEST_FOR_RENDERING_CONTEXTS(ComposedImageFilterOffset_Gpu, reporter, ctxInfo)
{
    test_composed_imagefilter_offset(reporter, ctxInfo.grContext());
}
#endif

static void test_composed_imagefilter_bounds(skiatest::Reporter* reporter, GrContext* context)
{
    // The bounds passed to the inner filter must be filtered by the outer
    // filter, so that the inner filter produces the pixels that the outer
    // filter requires as input. This matters if the outer filter moves pixels.
    // Here, accounting for the outer offset is necessary so that the green
    // pixels of the picture are not clipped.

    SkPictureRecorder recorder;
    SkCanvas* recordingCanvas = recorder.beginRecording(SkRect::MakeWH(200, 100));
    recordingCanvas->clipRect(SkRect::MakeXYWH(100, 0, 100, 100));
    recordingCanvas->clear(SK_ColorGREEN);
    sk_sp<SkPicture> picture(recorder.finishRecordingAsPicture());
    sk_sp<SkImageFilter> pictureFilter(SkPictureImageFilter::Make(picture));
    SkImageFilter::CropRect cropRect(SkRect::MakeWH(100, 100));
    sk_sp<SkImageFilter> offsetFilter(SkOffsetImageFilter::Make(-100, 0, nullptr, &cropRect));
    sk_sp<SkImageFilter> composedFilter(SkComposeImageFilter::Make(std::move(offsetFilter),
        std::move(pictureFilter)));

    sk_sp<SkSpecialImage> sourceImage(create_empty_special_image(context, 100));
    SkImageFilter::Context ctx(SkMatrix::I(), SkIRect::MakeWH(100, 100), nullptr);
    SkIPoint offset;
    sk_sp<SkSpecialImage> result(composedFilter->filterImage(sourceImage.get(), ctx, &offset));
    REPORTER_ASSERT(reporter, offset.isZero());
    REPORTER_ASSERT(reporter, result);
    REPORTER_ASSERT(reporter, result->subset().size() == SkISize::Make(100, 100));

    SkBitmap resultBM;
    REPORTER_ASSERT(reporter, result->getROPixels(&resultBM));
    SkAutoLockPixels lock(resultBM);
    REPORTER_ASSERT(reporter, resultBM.getColor(50, 50) == SK_ColorGREEN);
}

DEF_TEST(ComposedImageFilterBounds, reporter)
{
    test_composed_imagefilter_bounds(reporter, nullptr);
}

#if SK_SUPPORT_GPU
DEF_GPUTEST_FOR_RENDERING_CONTEXTS(ComposedImageFilterBounds_Gpu, reporter, ctxInfo)
{
    test_composed_imagefilter_bounds(reporter, ctxInfo.grContext());
}
#endif

static void test_partial_crop_rect(skiatest::Reporter* reporter, GrContext* context)
{
    sk_sp<SkSpecialImage> srcImg(create_empty_special_image(context, 100));

    SkImageFilter::CropRect cropRect(SkRect::MakeXYWH(100, 0, 20, 30),
        SkImageFilter::CropRect::kHasWidth_CropEdge | SkImageFilter::CropRect::kHasHeight_CropEdge);
    sk_sp<SkImageFilter> filter(make_grayscale(nullptr, &cropRect));
    SkIPoint offset;
    SkImageFilter::Context ctx(SkMatrix::I(), SkIRect::MakeWH(100, 100), nullptr);

    sk_sp<SkSpecialImage> resultImg(filter->filterImage(srcImg.get(), ctx, &offset));
    REPORTER_ASSERT(reporter, resultImg);

    REPORTER_ASSERT(reporter, offset.fX == 0);
    REPORTER_ASSERT(reporter, offset.fY == 0);
    REPORTER_ASSERT(reporter, resultImg->width() == 20);
    REPORTER_ASSERT(reporter, resultImg->height() == 30);
}

DEF_TEST(ImageFilterPartialCropRect, reporter)
{
    test_partial_crop_rect(reporter, nullptr);
}

#if SK_SUPPORT_GPU
DEF_GPUTEST_FOR_RENDERING_CONTEXTS(ImageFilterPartialCropRect_Gpu, reporter, ctxInfo)
{
    test_partial_crop_rect(reporter, ctxInfo.grContext());
}
#endif

DEF_TEST(ImageFilterCanComputeFastBounds, reporter)
{

    {
        SkPoint3 location = SkPoint3::Make(0, 0, SK_Scalar1);
        sk_sp<SkImageFilter> lighting(SkLightingImageFilter::MakePointLitDiffuse(location,
            SK_ColorGREEN,
            0, 0, nullptr));
        REPORTER_ASSERT(reporter, !lighting->canComputeFastBounds());
    }

    {
        sk_sp<SkImageFilter> gray(make_grayscale(nullptr, nullptr));
        REPORTER_ASSERT(reporter, gray->canComputeFastBounds());
        {
            SkColorFilter* grayCF;
            REPORTER_ASSERT(reporter, gray->asAColorFilter(&grayCF));
            REPORTER_ASSERT(reporter, !grayCF->affectsTransparentBlack());
            grayCF->unref();
        }
        REPORTER_ASSERT(reporter, gray->canComputeFastBounds());

        sk_sp<SkImageFilter> grayBlur(SkBlurImageFilter::Make(SK_Scalar1, SK_Scalar1,
            std::move(gray)));
        REPORTER_ASSERT(reporter, grayBlur->canComputeFastBounds());
    }

    {
        SkScalar greenMatrix[20] = { 0, 0, 0, 0, 0,
            0, 0, 0, 0, 1,
            0, 0, 0, 0, 0,
            0, 0, 0, 0, 1 };
        sk_sp<SkColorFilter> greenCF(SkColorFilter::MakeMatrixFilterRowMajor255(greenMatrix));
        sk_sp<SkImageFilter> green(SkColorFilterImageFilter::Make(greenCF, nullptr));

        REPORTER_ASSERT(reporter, greenCF->affectsTransparentBlack());
        REPORTER_ASSERT(reporter, !green->canComputeFastBounds());

        sk_sp<SkImageFilter> greenBlur(SkBlurImageFilter::Make(SK_Scalar1, SK_Scalar1,
            std::move(green)));
        REPORTER_ASSERT(reporter, !greenBlur->canComputeFastBounds());
    }

    uint8_t allOne[256], identity[256];
    for (int i = 0; i < 256; ++i) {
        identity[i] = i;
        allOne[i] = 255;
    }

    sk_sp<SkColorFilter> identityCF(SkTableColorFilter::MakeARGB(identity, identity,
        identity, allOne));
    sk_sp<SkImageFilter> identityFilter(SkColorFilterImageFilter::Make(identityCF, nullptr));
    REPORTER_ASSERT(reporter, !identityCF->affectsTransparentBlack());
    REPORTER_ASSERT(reporter, identityFilter->canComputeFastBounds());

    sk_sp<SkColorFilter> forceOpaqueCF(SkTableColorFilter::MakeARGB(allOne, identity,
        identity, identity));
    sk_sp<SkImageFilter> forceOpaque(SkColorFilterImageFilter::Make(forceOpaqueCF, nullptr));
    REPORTER_ASSERT(reporter, forceOpaqueCF->affectsTransparentBlack());
    REPORTER_ASSERT(reporter, !forceOpaque->canComputeFastBounds());
}

// Verify that SkImageSource survives serialization
DEF_TEST(ImageFilterImageSourceSerialization, reporter)
{
    auto surface(SkSurface::MakeRasterN32Premul(10, 10));
    surface->getCanvas()->clear(SK_ColorGREEN);
    sk_sp<SkImage> image(surface->makeImageSnapshot());
    sk_sp<SkImageFilter> filter(SkImageSource::Make(std::move(image)));

    sk_sp<SkData> data(SkValidatingSerializeFlattenable(filter.get()));
    sk_sp<SkFlattenable> flattenable(SkValidatingDeserializeFlattenable(
        data->data(), data->size(), SkImageFilter::GetFlattenableType()));
    SkImageFilter* unflattenedFilter = static_cast<SkImageFilter*>(flattenable.get());
    REPORTER_ASSERT(reporter, unflattenedFilter);

    SkBitmap bm;
    bm.allocN32Pixels(10, 10);
    bm.eraseColor(SK_ColorBLUE);
    SkPaint paint;
    paint.setColor(SK_ColorRED);
    paint.setImageFilter(unflattenedFilter);

    SkCanvas canvas(bm);
    canvas.drawRect(SkRect::MakeWH(10, 10), paint);
    REPORTER_ASSERT(reporter, *bm.getAddr32(0, 0) == SkPreMultiplyColor(SK_ColorGREEN));
}

static void test_large_blur_input(skiatest::Reporter* reporter, SkCanvas* canvas)
{
    SkBitmap largeBmp;
    int largeW = 5000;
    int largeH = 5000;
#if SK_SUPPORT_GPU
    // If we're GPU-backed make the bitmap too large to be converted into a texture.
    if (GrContext* ctx = canvas->getGrContext()) {
        largeW = ctx->caps()->maxTextureSize() + 1;
    }
#endif

    largeBmp.allocN32Pixels(largeW, largeH);
    largeBmp.eraseColor(0);
    if (!largeBmp.getPixels()) {
        ERRORF(reporter, "Failed to allocate large bmp.");
        return;
    }

    sk_sp<SkImage> largeImage(SkImage::MakeFromBitmap(largeBmp));
    if (!largeImage) {
        ERRORF(reporter, "Failed to create large image.");
        return;
    }

    sk_sp<SkImageFilter> largeSource(SkImageSource::Make(std::move(largeImage)));
    if (!largeSource) {
        ERRORF(reporter, "Failed to create large SkImageSource.");
        return;
    }

    sk_sp<SkImageFilter> blur(SkBlurImageFilter::Make(10.f, 10.f, std::move(largeSource)));
    if (!blur) {
        ERRORF(reporter, "Failed to create SkBlurImageFilter.");
        return;
    }

    SkPaint paint;
    paint.setImageFilter(std::move(blur));

    // This should not crash (http://crbug.com/570479).
    canvas->drawRect(SkRect::MakeIWH(largeW, largeH), paint);
}

DEF_TEST(ImageFilterBlurLargeImage, reporter)
{
    auto surface(SkSurface::MakeRaster(SkImageInfo::MakeN32Premul(100, 100)));
    test_large_blur_input(reporter, surface->getCanvas());
}

static void test_make_with_filter(skiatest::Reporter* reporter, GrContext* context)
{
    sk_sp<SkSurface> surface(create_surface(context, 100, 100));
    surface->getCanvas()->clear(SK_ColorRED);
    SkPaint bluePaint;
    bluePaint.setColor(SK_ColorBLUE);
    SkIRect subset = SkIRect::MakeXYWH(25, 20, 50, 50);
    surface->getCanvas()->drawRect(SkRect::Make(subset), bluePaint);
    sk_sp<SkImage> sourceImage = surface->makeImageSnapshot();

    sk_sp<SkImageFilter> filter = make_grayscale(nullptr, nullptr);
    SkIRect clipBounds = SkIRect::MakeXYWH(30, 35, 100, 100);
    SkIRect outSubset;
    SkIPoint offset;
    sk_sp<SkImage> result;

    result = sourceImage->makeWithFilter(nullptr, subset, clipBounds, &outSubset, &offset);
    REPORTER_ASSERT(reporter, !result);

    result = sourceImage->makeWithFilter(filter.get(), subset, clipBounds, nullptr, &offset);
    REPORTER_ASSERT(reporter, !result);

    result = sourceImage->makeWithFilter(filter.get(), subset, clipBounds, &outSubset, nullptr);
    REPORTER_ASSERT(reporter, !result);

    SkIRect bigSubset = SkIRect::MakeXYWH(-10000, -10000, 20000, 20000);
    result = sourceImage->makeWithFilter(filter.get(), bigSubset, clipBounds, &outSubset, &offset);
    REPORTER_ASSERT(reporter, !result);

    SkIRect empty = SkIRect::MakeEmpty();
    result = sourceImage->makeWithFilter(filter.get(), empty, clipBounds, &outSubset, &offset);
    REPORTER_ASSERT(reporter, !result);

    result = sourceImage->makeWithFilter(filter.get(), subset, empty, &outSubset, &offset);
    REPORTER_ASSERT(reporter, !result);

    SkIRect leftField = SkIRect::MakeXYWH(-1000, 0, 100, 100);
    result = sourceImage->makeWithFilter(filter.get(), subset, leftField, &outSubset, &offset);
    REPORTER_ASSERT(reporter, !result);

    result = sourceImage->makeWithFilter(filter.get(), subset, clipBounds, &outSubset, &offset);

    REPORTER_ASSERT(reporter, result);
    REPORTER_ASSERT(reporter, result->bounds().contains(outSubset));
    SkIRect destRect = SkIRect::MakeXYWH(offset.x(), offset.y(),
        outSubset.width(), outSubset.height());
    REPORTER_ASSERT(reporter, clipBounds.contains(destRect));
}

DEF_TEST(ImageFilterMakeWithFilter, reporter)
{
    test_make_with_filter(reporter, nullptr);
}

#if SK_SUPPORT_GPU
DEF_GPUTEST_FOR_RENDERING_CONTEXTS(ImageFilterMakeWithFilter_Gpu, reporter, ctxInfo)
{
    test_make_with_filter(reporter, ctxInfo.grContext());
}
#endif

#if SK_SUPPORT_GPU

DEF_GPUTEST_FOR_RENDERING_CONTEXTS(ImageFilterHugeBlur_Gpu, reporter, ctxInfo)
{

    sk_sp<SkSurface> surf(SkSurface::MakeRenderTarget(ctxInfo.grContext(),
        SkBudgeted::kNo,
        SkImageInfo::MakeN32Premul(100, 100)));

    SkCanvas* canvas = surf->getCanvas();

    test_huge_blur(canvas, reporter);
}

DEF_GPUTEST_FOR_RENDERING_CONTEXTS(XfermodeImageFilterCroppedInput_Gpu, reporter, ctxInfo)
{

    sk_sp<SkSurface> surf(SkSurface::MakeRenderTarget(ctxInfo.grContext(),
        SkBudgeted::kNo,
        SkImageInfo::MakeN32Premul(1, 1)));

    SkCanvas* canvas = surf->getCanvas();

    test_xfermode_cropped_input(canvas, reporter);
}

DEF_GPUTEST_FOR_ALL_CONTEXTS(ImageFilterBlurLargeImage_Gpu, reporter, ctxInfo)
{
    auto surface(SkSurface::MakeRenderTarget(ctxInfo.grContext(), SkBudgeted::kYes,
        SkImageInfo::MakeN32Premul(100, 100)));
    test_large_blur_input(reporter, surface->getCanvas());
}
#endif

/*
 *  Test that colorfilterimagefilter does not require its CTM to be decomposed when it has more
 *  than just scale/translate, but that other filters do.
 */
DEF_TEST(ImageFilterComplexCTM, reporter)
{
    // just need a colorfilter to exercise the corresponding imagefilter
    sk_sp<SkColorFilter> cf = SkColorFilter::MakeModeFilter(SK_ColorRED, SkXfermode::kSrcATop_Mode);
    sk_sp<SkImageFilter> cfif = SkColorFilterImageFilter::Make(cf, nullptr); // can handle
    sk_sp<SkImageFilter> blif = SkBlurImageFilter::Make(3, 3, nullptr); // cannot handle

    struct {
        sk_sp<SkImageFilter> fFilter;
        bool fExpectCanHandle;
    } recs[] = {
        { cfif, true },
        { SkColorFilterImageFilter::Make(cf, cfif), true },
        { SkMergeImageFilter::Make(cfif, cfif), true },
        { SkComposeImageFilter::Make(cfif, cfif), true },

        { blif, false },
        { SkBlurImageFilter::Make(3, 3, cfif), false },
        { SkColorFilterImageFilter::Make(cf, blif), false },
        { SkMergeImageFilter::Make(cfif, blif), false },
        { SkComposeImageFilter::Make(blif, cfif), false },
    };

    for (const auto& rec : recs) {
        const bool canHandle = rec.fFilter->canHandleComplexCTM();
        REPORTER_ASSERT(reporter, canHandle == rec.fExpectCanHandle);
    }
}
=======
DEF_TEST(ComposedImageFilterOffset, reporter) {
    SkBitmap bitmap;
    bitmap.allocN32Pixels(100, 100);
    bitmap.eraseARGB(0, 0, 0, 0);
    const SkSurfaceProps props(SkSurfaceProps::kLegacyFontHost_InitType);
    SkBitmapDevice device(bitmap, props);
    SkImageFilter::Proxy proxy(&device);

    SkImageFilter::CropRect cropRect(SkRect::MakeXYWH(1, 0, 20, 20));
    SkAutoTUnref<SkImageFilter> offsetFilter(SkOffsetImageFilter::Create(0, 0, NULL, &cropRect));
    SkAutoTUnref<SkImageFilter> blurFilter(makeBlur());
    SkAutoTUnref<SkImageFilter> composedFilter(SkComposeImageFilter::Create(blurFilter, offsetFilter.get()));
    SkBitmap result;
    SkIPoint offset;
    SkImageFilter::Context ctx(SkMatrix::I(), SkIRect::MakeLargest(), NULL);
    REPORTER_ASSERT(reporter, composedFilter->filterImage(&proxy, bitmap, ctx, &result, &offset));
    REPORTER_ASSERT(reporter, offset.fX == 1 && offset.fY == 0);
}

#if SK_SUPPORT_GPU

DEF_GPUTEST(ImageFilterCropRectGPU, reporter, factory) {
    GrContext* context = factory->get(static_cast<GrContextFactory::GLContextType>(0));
    if (NULL == context) {
        return;
    }
    const SkSurfaceProps props(SkSurfaceProps::kLegacyFontHost_InitType);

    SkAutoTUnref<SkGpuDevice> device(SkGpuDevice::Create(context,
                                                         SkSurface::kNo_Budgeted,
                                                         SkImageInfo::MakeN32Premul(100, 100),
                                                         0,
                                                         &props,
                                                         SkGpuDevice::kUninit_InitContents));
    SkImageFilter::Proxy proxy(device);

    test_crop_rects(&proxy, reporter);
}

DEF_GPUTEST(HugeBlurImageFilterGPU, reporter, factory) {
    GrContext* context = factory->get(static_cast<GrContextFactory::GLContextType>(0));
    if (NULL == context) {
        return;
    }
    const SkSurfaceProps props(SkSurfaceProps::kLegacyFontHost_InitType);

    SkAutoTUnref<SkGpuDevice> device(SkGpuDevice::Create(context,
                                                         SkSurface::kNo_Budgeted,
                                                         SkImageInfo::MakeN32Premul(100, 100),
                                                         0,
                                                         &props,
                                                         SkGpuDevice::kUninit_InitContents));
    SkCanvas canvas(device);

    test_huge_blur(&canvas, reporter);
}

DEF_GPUTEST(XfermodeImageFilterCroppedInputGPU, reporter, factory) {
    GrContext* context = factory->get(static_cast<GrContextFactory::GLContextType>(0));
    if (NULL == context) {
        return;
    }
    const SkSurfaceProps props(SkSurfaceProps::kLegacyFontHost_InitType);

    SkAutoTUnref<SkGpuDevice> device(SkGpuDevice::Create(context,
                                                         SkSurface::kNo_Budgeted,
                                                         SkImageInfo::MakeN32Premul(1, 1),
                                                         0,
                                                         &props,
                                                         SkGpuDevice::kUninit_InitContents));
    SkCanvas canvas(device);

    test_xfermode_cropped_input(&canvas, reporter);
}

DEF_GPUTEST(TestNegativeBlurSigmaGPU, reporter, factory) {
    GrContext* context = factory->get(static_cast<GrContextFactory::GLContextType>(0));
    if (NULL == context) {
        return;
    }
    const SkSurfaceProps props(SkSurfaceProps::kLegacyFontHost_InitType);

    SkAutoTUnref<SkGpuDevice> device(SkGpuDevice::Create(context,
                                                         SkSurface::kNo_Budgeted,
                                                         SkImageInfo::MakeN32Premul(1, 1),
                                                         0,
                                                         &props,
                                                         SkGpuDevice::kUninit_InitContents));
    SkImageFilter::Proxy proxy(device);

    test_negative_blur_sigma(&proxy, reporter);
}
#endif
>>>>>>> miniblink49
