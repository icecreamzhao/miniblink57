/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "DMSrcSink.h"
<<<<<<< HEAD
#include "Resources.h"
#include "SkAndroidCodec.h"
#include "SkCodec.h"
#include "SkCodecImageGenerator.h"
#include "SkColorSpace.h"
#include "SkColorSpaceXform.h"
#include "SkColorSpace_Base.h"
#include "SkCommonFlags.h"
#include "SkData.h"
#include "SkDocument.h"
#include "SkError.h"
#include "SkImageGenerator.h"
#include "SkImageGeneratorCG.h"
#include "SkImageGeneratorWIC.h"
#include "SkMallocPixelRef.h"
#include "SkMultiPictureDraw.h"
#include "SkNullCanvas.h"
#include "SkOSFile.h"
#include "SkOpts.h"
=======
#include "SamplePipeControllers.h"
#include "SkCodec.h"
#include "SkCommonFlags.h"
#include "SkData.h"
#include "SkDeferredCanvas.h"
#include "SkDocument.h"
#include "SkError.h"
#include "SkFunction.h"
#include "SkImageGenerator.h"
#include "SkMultiPictureDraw.h"
#include "SkNullCanvas.h"
#include "SkOSFile.h"
>>>>>>> miniblink49
#include "SkPictureData.h"
#include "SkPictureRecorder.h"
#include "SkRandom.h"
#include "SkRecordDraw.h"
#include "SkRecorder.h"
#include "SkSVGCanvas.h"
<<<<<<< HEAD
#include "SkStream.h"
#include "SkSwizzler.h"
#include "SkTLogic.h"
#include "SkXMLWriter.h"
#include <functional>

#if defined(SK_BUILD_FOR_WIN)
#include "SkAutoCoInitialize.h"
#endif

#if defined(SK_TEST_QCMS)
#include "qcms.h"
#endif

DEFINE_bool(multiPage, false, "For document-type backends, render the source"
                              " into multiple pages");
DEFINE_bool(RAW_threading, true, "Allow RAW decodes to run on multiple threads?");

using sk_gpu_test::GrContextFactory;

namespace DM {

GMSrc::GMSrc(skiagm::GMRegistry::Factory factory)
    : fFactory(factory)
{
}

Error GMSrc::draw(SkCanvas* canvas) const
{
    SkAutoTDelete<skiagm::GM> gm(fFactory(nullptr));
=======
#include "SkScanlineDecoder.h"
#include "SkStream.h"
#include "SkXMLWriter.h"

DEFINE_bool(multiPage, false, "For document-type backends, render the source"
            " into multiple pages");

static bool lazy_decode_bitmap(const void* src, size_t size, SkBitmap* dst) {
    SkAutoTUnref<SkData> encoded(SkData::NewWithCopy(src, size));
    return encoded && SkInstallDiscardablePixelRef(encoded, dst);
}

namespace DM {

GMSrc::GMSrc(skiagm::GMRegistry::Factory factory) : fFactory(factory) {}

Error GMSrc::draw(SkCanvas* canvas) const {
    SkAutoTDelete<skiagm::GM> gm(fFactory(NULL));
>>>>>>> miniblink49
    canvas->concat(gm->getInitialTransform());
    gm->draw(canvas);
    return "";
}

<<<<<<< HEAD
SkISize GMSrc::size() const
{
    SkAutoTDelete<skiagm::GM> gm(fFactory(nullptr));
    return gm->getISize();
}

Name GMSrc::name() const
{
    SkAutoTDelete<skiagm::GM> gm(fFactory(nullptr));
    return gm->getName();
}

void GMSrc::modifyGrContextOptions(GrContextOptions* options) const
{
    SkAutoTDelete<skiagm::GM> gm(fFactory(nullptr));
=======
SkISize GMSrc::size() const {
    SkAutoTDelete<skiagm::GM> gm(fFactory(NULL));
    return gm->getISize();
}

Name GMSrc::name() const {
    SkAutoTDelete<skiagm::GM> gm(fFactory(NULL));
    return gm->getName();
}

void GMSrc::modifyGrContextOptions(GrContextOptions* options) const {
    SkAutoTDelete<skiagm::GM> gm(fFactory(NULL));
>>>>>>> miniblink49
    gm->modifyGrContextOptions(options);
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

<<<<<<< HEAD
BRDSrc::BRDSrc(Path path, Mode mode, CodecSrc::DstColorType dstColorType, uint32_t sampleSize)
    : fPath(path)
    , fMode(mode)
    , fDstColorType(dstColorType)
    , fSampleSize(sampleSize)
{
}

bool BRDSrc::veto(SinkFlags flags) const
{
    // No need to test to non-raster or indirect backends.
    return flags.type != SinkFlags::kRaster
        || flags.approach != SinkFlags::kDirect;
}

static SkBitmapRegionDecoder* create_brd(Path path)
{
    SkAutoTUnref<SkData> encoded(SkData::NewFromFileName(path.c_str()));
    if (!encoded) {
        return NULL;
    }
    return SkBitmapRegionDecoder::Create(encoded, SkBitmapRegionDecoder::kAndroidCodec_Strategy);
}

Error BRDSrc::draw(SkCanvas* canvas) const
{
    SkColorType colorType = canvas->imageInfo().colorType();
    if (kRGB_565_SkColorType == colorType && CodecSrc::kGetFromCanvas_DstColorType != fDstColorType) {
        return Error::Nonfatal("Testing non-565 to 565 is uninteresting.");
    }
    switch (fDstColorType) {
    case CodecSrc::kGetFromCanvas_DstColorType:
        break;
    case CodecSrc::kIndex8_Always_DstColorType:
        colorType = kIndex_8_SkColorType;
        break;
    case CodecSrc::kGrayscale_Always_DstColorType:
        colorType = kGray_8_SkColorType;
        break;
    default:
        SkASSERT(false);
        break;
    }

    SkAutoTDelete<SkBitmapRegionDecoder> brd(create_brd(fPath));
    if (nullptr == brd.get()) {
        return Error::Nonfatal(SkStringPrintf("Could not create brd for %s.", fPath.c_str()));
    }

    if (!brd->conversionSupported(colorType)) {
        return Error::Nonfatal("Cannot convert to color type.");
    }

    const uint32_t width = brd->width();
    const uint32_t height = brd->height();
    // Visually inspecting very small output images is not necessary.
    if ((width / fSampleSize <= 10 || height / fSampleSize <= 10) && 1 != fSampleSize) {
        return Error::Nonfatal("Scaling very small images is uninteresting.");
    }
    switch (fMode) {
    case kFullImage_Mode: {
        SkBitmap bitmap;
        if (!brd->decodeRegion(&bitmap, nullptr, SkIRect::MakeXYWH(0, 0, width, height),
                fSampleSize, colorType, false)) {
            return "Cannot decode (full) region.";
        }
        if (colorType != bitmap.colorType()) {
            return Error::Nonfatal("Cannot convert to color type.");
        }
        canvas->drawBitmap(bitmap, 0, 0);
        return "";
    }
    case kDivisor_Mode: {
        const uint32_t divisor = 2;
        if (width < divisor || height < divisor) {
            return Error::Nonfatal("Divisor is larger than image dimension.");
        }

        // Use a border to test subsets that extend outside the image.
        // We will not allow the border to be larger than the image dimensions.  Allowing
        // these large borders causes off by one errors that indicate a problem with the
        // test suite, not a problem with the implementation.
        const uint32_t maxBorder = SkTMin(width, height) / (fSampleSize * divisor);
        const uint32_t scaledBorder = SkTMin(5u, maxBorder);
        const uint32_t unscaledBorder = scaledBorder * fSampleSize;

        // We may need to clear the canvas to avoid uninitialized memory.
        // Assume we are scaling a 780x780 image with sampleSize = 8.
        // The output image should be 97x97.
        // Each subset will be 390x390.
        // Each scaled subset be 48x48.
        // Four scaled subsets will only fill a 96x96 image.
        // The bottom row and last column will not be touched.
        // This is an unfortunate result of our rounding rules when scaling.
        // Maybe we need to consider testing scaled subsets without trying to
        // combine them to match the full scaled image?  Or maybe this is the
        // best we can do?
        canvas->clear(0);

        for (uint32_t x = 0; x < divisor; x++) {
            for (uint32_t y = 0; y < divisor; y++) {
                // Calculate the subset dimensions
                uint32_t subsetWidth = width / divisor;
                uint32_t subsetHeight = height / divisor;
                const int left = x * subsetWidth;
                const int top = y * subsetHeight;

                // Increase the size of the last subset in each row or column, when the
                // divisor does not divide evenly into the image dimensions
                subsetWidth += (x + 1 == divisor) ? (width % divisor) : 0;
                subsetHeight += (y + 1 == divisor) ? (height % divisor) : 0;

                // Increase the size of the subset in order to have a border on each side
                const int decodeLeft = left - unscaledBorder;
                const int decodeTop = top - unscaledBorder;
                const uint32_t decodeWidth = subsetWidth + unscaledBorder * 2;
                const uint32_t decodeHeight = subsetHeight + unscaledBorder * 2;
                SkBitmap bitmap;
                if (!brd->decodeRegion(&bitmap, nullptr, SkIRect::MakeXYWH(decodeLeft, decodeTop, decodeWidth, decodeHeight), fSampleSize, colorType, false)) {
                    return "Cannot decode region.";
                }
                if (colorType != bitmap.colorType()) {
                    return Error::Nonfatal("Cannot convert to color type.");
                }

                canvas->drawBitmapRect(bitmap,
                    SkRect::MakeXYWH((SkScalar)scaledBorder, (SkScalar)scaledBorder,
                        (SkScalar)(subsetWidth / fSampleSize),
                        (SkScalar)(subsetHeight / fSampleSize)),
                    SkRect::MakeXYWH((SkScalar)(left / fSampleSize),
                        (SkScalar)(top / fSampleSize),
                        (SkScalar)(subsetWidth / fSampleSize),
                        (SkScalar)(subsetHeight / fSampleSize)),
                    nullptr);
            }
        }
        return "";
    }
    default:
        SkASSERT(false);
        return "Error: Should not be reached.";
    }
}

SkISize BRDSrc::size() const
{
    SkAutoTDelete<SkBitmapRegionDecoder> brd(create_brd(fPath));
    if (brd) {
        return SkISize::Make(SkTMax(1, brd->width() / (int)fSampleSize),
            SkTMax(1, brd->height() / (int)fSampleSize));
    }
    return SkISize::Make(0, 0);
}

static SkString get_scaled_name(const Path& path, float scale)
{
    return SkStringPrintf("%s_%.3f", SkOSPath::Basename(path.c_str()).c_str(), scale);
}

Name BRDSrc::name() const
{
    // We will replicate the names used by CodecSrc so that images can
    // be compared in Gold.
    if (1 == fSampleSize) {
        return SkOSPath::Basename(fPath.c_str());
    }
    return get_scaled_name(fPath, 1.0f / (float)fSampleSize);
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

static bool serial_from_path_name(const SkString& path)
{
    if (!FLAGS_RAW_threading) {
        static const char* const exts[] = {
            "arw",
            "cr2",
            "dng",
            "nef",
            "nrw",
            "orf",
            "raf",
            "rw2",
            "pef",
            "srw",
            "ARW",
            "CR2",
            "DNG",
            "NEF",
            "NRW",
            "ORF",
            "RAF",
            "RW2",
            "PEF",
            "SRW",
        };
        const char* actualExt = strrchr(path.c_str(), '.');
        if (actualExt) {
            actualExt++;
            for (auto* ext : exts) {
                if (0 == strcmp(ext, actualExt)) {
                    return true;
                }
            }
        }
    }
    return false;
}

CodecSrc::CodecSrc(Path path, Mode mode, DstColorType dstColorType, SkAlphaType dstAlphaType,
    float scale)
    : fPath(path)
    , fMode(mode)
    , fDstColorType(dstColorType)
    , fDstAlphaType(dstAlphaType)
    , fScale(scale)
    , fRunSerially(serial_from_path_name(path))
{
}

bool CodecSrc::veto(SinkFlags flags) const
{
    // Test to direct raster backends (8888 and 565).
    return flags.type != SinkFlags::kRaster || flags.approach != SinkFlags::kDirect;
}

// Allows us to test decodes to non-native 8888.
static void swap_rb_if_necessary(SkBitmap& bitmap, CodecSrc::DstColorType dstColorType)
{
    if (CodecSrc::kNonNative8888_Always_DstColorType != dstColorType) {
        return;
    }

    for (int y = 0; y < bitmap.height(); y++) {
        uint32_t* row = (uint32_t*)bitmap.getAddr(0, y);
        SkOpts::RGBA_to_BGRA(row, row, bitmap.width());
    }
}

// FIXME: Currently we cannot draw unpremultiplied sources. skbug.com/3338 and skbug.com/3339.
// This allows us to still test unpremultiplied decodes.
static void premultiply_if_necessary(SkBitmap& bitmap)
{
    if (kUnpremul_SkAlphaType != bitmap.alphaType()) {
        return;
    }

    switch (bitmap.colorType()) {
    case kN32_SkColorType:
        for (int y = 0; y < bitmap.height(); y++) {
            uint32_t* row = (uint32_t*)bitmap.getAddr(0, y);
            SkOpts::RGBA_to_rgbA(row, row, bitmap.width());
        }
        break;
    case kIndex_8_SkColorType: {
        SkColorTable* colorTable = bitmap.getColorTable();
        SkPMColor* colorPtr = const_cast<SkPMColor*>(colorTable->readColors());
        SkOpts::RGBA_to_rgbA(colorPtr, colorPtr, colorTable->count());
        break;
    }
    default:
        // No need to premultiply kGray or k565 outputs.
        break;
    }

    // In the kIndex_8 case, the canvas won't even try to draw unless we mark the
    // bitmap as kPremul.
    bitmap.setAlphaType(kPremul_SkAlphaType);
}

static bool get_decode_info(SkImageInfo* decodeInfo, SkColorType canvasColorType,
    CodecSrc::DstColorType dstColorType, SkAlphaType dstAlphaType)
{
    switch (dstColorType) {
    case CodecSrc::kIndex8_Always_DstColorType:
        if (kRGB_565_SkColorType == canvasColorType) {
            return false;
        }
        *decodeInfo = decodeInfo->makeColorType(kIndex_8_SkColorType);
        break;
    case CodecSrc::kGrayscale_Always_DstColorType:
        if (kRGB_565_SkColorType == canvasColorType) {
            return false;
        }
        *decodeInfo = decodeInfo->makeColorType(kGray_8_SkColorType);
        break;
    case CodecSrc::kNonNative8888_Always_DstColorType:
        if (kRGB_565_SkColorType == canvasColorType) {
            return false;
        }
#ifdef SK_PMCOLOR_IS_RGBA
        *decodeInfo = decodeInfo->makeColorType(kBGRA_8888_SkColorType);
#else
        *decodeInfo = decodeInfo->makeColorType(kRGBA_8888_SkColorType);
#endif
        break;
    default:
        if (kRGB_565_SkColorType == canvasColorType && kOpaque_SkAlphaType != decodeInfo->alphaType()) {
            return false;
        }
        *decodeInfo = decodeInfo->makeColorType(canvasColorType);
        break;
    }

    *decodeInfo = decodeInfo->makeAlphaType(dstAlphaType);
    return true;
}

static void draw_to_canvas(SkCanvas* canvas, const SkImageInfo& info, void* pixels, size_t rowBytes,
    SkPMColor* colorPtr, int colorCount, CodecSrc::DstColorType dstColorType,
    SkScalar left = 0, SkScalar top = 0)
{
    SkAutoTUnref<SkColorTable> colorTable(new SkColorTable(colorPtr, colorCount));
    SkBitmap bitmap;
    bitmap.installPixels(info, pixels, rowBytes, colorTable.get(), nullptr, nullptr);
    premultiply_if_necessary(bitmap);
    swap_rb_if_necessary(bitmap, dstColorType);
    canvas->drawBitmap(bitmap, left, top);
}

Error CodecSrc::draw(SkCanvas* canvas) const
{
=======
CodecSrc::CodecSrc(Path path, Mode mode, DstColorType dstColorType, float scale)
    : fPath(path)
    , fMode(mode)
    , fDstColorType(dstColorType)
    , fScale(scale)
{}

Error CodecSrc::draw(SkCanvas* canvas) const {
    SkImageInfo canvasInfo;
    if (NULL == canvas->peekPixels(&canvasInfo, NULL)) {
        // TODO: Once we implement GPU paths (e.g. JPEG YUV), we should use a deferred decode to
        // let the GPU handle it.
        return Error::Nonfatal("No need to test decoding to non-raster backend.");
    }

>>>>>>> miniblink49
    SkAutoTUnref<SkData> encoded(SkData::NewFromFileName(fPath.c_str()));
    if (!encoded) {
        return SkStringPrintf("Couldn't read %s.", fPath.c_str());
    }
<<<<<<< HEAD

    SkAutoTDelete<SkCodec> codec(SkCodec::NewFromData(encoded));
    if (nullptr == codec.get()) {
        return SkStringPrintf("Couldn't create codec for %s.", fPath.c_str());
    }

    SkImageInfo decodeInfo = codec->getInfo();
    if (!get_decode_info(&decodeInfo, canvas->imageInfo().colorType(), fDstColorType,
            fDstAlphaType)) {
        return Error::Nonfatal("Testing non-565 to 565 is uninteresting.");
=======
    SkAutoTDelete<SkCodec> codec(SkCodec::NewFromData(encoded));
    if (NULL == codec.get()) {
        return SkStringPrintf("Couldn't create codec for %s.", fPath.c_str());
    }

    // Choose the color type to decode to
    SkImageInfo decodeInfo = codec->getInfo();
    SkColorType canvasColorType = canvasInfo.colorType();
    switch (fDstColorType) {
        case kIndex8_Always_DstColorType:
            decodeInfo = codec->getInfo().makeColorType(kIndex_8_SkColorType);
            if (kRGB_565_SkColorType == canvasColorType) {
                return Error::Nonfatal("Testing non-565 to 565 is uninteresting.");
            }
            break;
        case kGrayscale_Always_DstColorType:
            decodeInfo = codec->getInfo().makeColorType(kGray_8_SkColorType);
            if (kRGB_565_SkColorType == canvasColorType) {
                return Error::Nonfatal("Testing non-565 to 565 is uninteresting.");
            }
            break;
        default:
            decodeInfo = decodeInfo.makeColorType(canvasColorType);
            break;
>>>>>>> miniblink49
    }

    // Try to scale the image if it is desired
    SkISize size = codec->getScaledDimensions(fScale);
    if (size == decodeInfo.dimensions() && 1.0f != fScale) {
        return Error::Nonfatal("Test without scaling is uninteresting.");
    }
<<<<<<< HEAD

    // Visually inspecting very small output images is not necessary.  We will
    // cover these cases in unit testing.
    if ((size.width() <= 10 || size.height() <= 10) && 1.0f != fScale) {
        return Error::Nonfatal("Scaling very small images is uninteresting.");
    }
    decodeInfo = decodeInfo.makeWH(size.width(), size.height());

    const int bpp = SkColorTypeBytesPerPixel(decodeInfo.colorType());
    const size_t rowBytes = size.width() * bpp;
    SkAutoMalloc pixels(decodeInfo.getSafeSize(rowBytes));
    SkPMColor colorPtr[256];
    int colorCount = 256;

    SkCodec::Options options;
    if (kCodecZeroInit_Mode == fMode) {
        memset(pixels.get(), 0, size.height() * rowBytes);
        options.fZeroInitialized = SkCodec::kYes_ZeroInitialized;
    }

    SkImageInfo bitmapInfo = decodeInfo;
    if (kRGBA_8888_SkColorType == decodeInfo.colorType() || kBGRA_8888_SkColorType == decodeInfo.colorType()) {
        bitmapInfo = bitmapInfo.makeColorType(kN32_SkColorType);
    }

    switch (fMode) {
    case kCodecZeroInit_Mode:
    case kCodec_Mode: {
        switch (codec->getPixels(decodeInfo, pixels.get(), rowBytes, &options,
            colorPtr, &colorCount)) {
        case SkCodec::kSuccess:
            // We consider incomplete to be valid, since we should still decode what is
            // available.
        case SkCodec::kIncompleteInput:
            break;
        default:
            // Everything else is considered a failure.
            return SkStringPrintf("Couldn't getPixels %s.", fPath.c_str());
        }

        draw_to_canvas(canvas, bitmapInfo, pixels.get(), rowBytes, colorPtr, colorCount,
            fDstColorType);
        break;
    }
    case kScanline_Mode: {
        if (SkCodec::kSuccess != codec->startScanlineDecode(decodeInfo, NULL, colorPtr, &colorCount)) {
            return "Could not start scanline decoder";
        }

        void* dst = pixels.get();
        uint32_t height = decodeInfo.height();
        switch (codec->getScanlineOrder()) {
        case SkCodec::kTopDown_SkScanlineOrder:
        case SkCodec::kBottomUp_SkScanlineOrder:
        case SkCodec::kNone_SkScanlineOrder:
            // We do not need to check the return value.  On an incomplete
            // image, memory will be filled with a default value.
            codec->getScanlines(dst, height, rowBytes);
            break;
        case SkCodec::kOutOfOrder_SkScanlineOrder: {
            for (int y = 0; y < decodeInfo.height(); y++) {
                int dstY = codec->outputScanline(y);
                void* dstPtr = SkTAddOffset<void>(dst, rowBytes * dstY);
                // We complete the loop, even if this call begins to fail
                // due to an incomplete image.  This ensures any uninitialized
                // memory will be filled with the proper value.
                codec->getScanlines(dstPtr, 1, rowBytes);
            }
            break;
        }
        }

        draw_to_canvas(canvas, bitmapInfo, dst, rowBytes, colorPtr, colorCount, fDstColorType);
        break;
    }
    case kStripe_Mode: {
        const int height = decodeInfo.height();
        // This value is chosen arbitrarily.  We exercise more cases by choosing a value that
        // does not align with image blocks.
        const int stripeHeight = 37;
        const int numStripes = (height + stripeHeight - 1) / stripeHeight;
        void* dst = pixels.get();

        // Decode odd stripes
        if (SkCodec::kSuccess != codec->startScanlineDecode(decodeInfo, nullptr, colorPtr, &colorCount)) {
            return "Could not start scanline decoder";
        }

        // This mode was designed to test the new skip scanlines API in libjpeg-turbo.
        // Jpegs have kTopDown_SkScanlineOrder, and at this time, it is not interesting
        // to run this test for image types that do not have this scanline ordering.
        // We only run this on Jpeg, which is always kTopDown.
        SkASSERT(SkCodec::kTopDown_SkScanlineOrder == codec->getScanlineOrder());

        for (int i = 0; i < numStripes; i += 2) {
            // Skip a stripe
            const int linesToSkip = SkTMin(stripeHeight, height - i * stripeHeight);
            codec->skipScanlines(linesToSkip);

            // Read a stripe
            const int startY = (i + 1) * stripeHeight;
            const int linesToRead = SkTMin(stripeHeight, height - startY);
            if (linesToRead > 0) {
                codec->getScanlines(SkTAddOffset<void>(dst, rowBytes * startY), linesToRead,
                    rowBytes);
            }
        }

        // Decode even stripes
        const SkCodec::Result startResult = codec->startScanlineDecode(decodeInfo, nullptr,
            colorPtr, &colorCount);
        if (SkCodec::kSuccess != startResult) {
            return "Failed to restart scanline decoder with same parameters.";
        }
        for (int i = 0; i < numStripes; i += 2) {
            // Read a stripe
            const int startY = i * stripeHeight;
            const int linesToRead = SkTMin(stripeHeight, height - startY);
            codec->getScanlines(SkTAddOffset<void>(dst, rowBytes * startY), linesToRead,
                rowBytes);

            // Skip a stripe
            const int linesToSkip = SkTMin(stripeHeight, height - (i + 1) * stripeHeight);
            if (linesToSkip > 0) {
                codec->skipScanlines(linesToSkip);
            }
        }

        draw_to_canvas(canvas, bitmapInfo, dst, rowBytes, colorPtr, colorCount, fDstColorType);
        break;
    }
    case kCroppedScanline_Mode: {
        const int width = decodeInfo.width();
        const int height = decodeInfo.height();
        // This value is chosen because, as we move across the image, it will sometimes
        // align with the jpeg block sizes and it will sometimes not.  This allows us
        // to test interestingly different code paths in the implementation.
        const int tileSize = 36;

        SkCodec::Options opts;
        SkIRect subset;
        for (int x = 0; x < width; x += tileSize) {
            subset = SkIRect::MakeXYWH(x, 0, SkTMin(tileSize, width - x), height);
            opts.fSubset = &subset;
            if (SkCodec::kSuccess != codec->startScanlineDecode(decodeInfo, &opts, colorPtr, &colorCount)) {
                return "Could not start scanline decoder.";
            }

            codec->getScanlines(SkTAddOffset<void>(pixels.get(), x * bpp), height, rowBytes);
        }

        draw_to_canvas(canvas, bitmapInfo, pixels.get(), rowBytes, colorPtr, colorCount,
            fDstColorType);
        break;
    }
    case kSubset_Mode: {
        // Arbitrarily choose a divisor.
        int divisor = 2;
        // Total width/height of the image.
        const int W = codec->getInfo().width();
        const int H = codec->getInfo().height();
        if (divisor > W || divisor > H) {
            return Error::Nonfatal(SkStringPrintf("Cannot codec subset: divisor %d is too big "
                                                  "for %s with dimensions (%d x %d)",
                divisor,
                fPath.c_str(), W, H));
        }
        // subset dimensions
        // SkWebpCodec, the only one that supports subsets, requires even top/left boundaries.
        const int w = SkAlign2(W / divisor);
        const int h = SkAlign2(H / divisor);
        SkIRect subset;
        SkCodec::Options opts;
        opts.fSubset = &subset;
        SkBitmap subsetBm;
        // We will reuse pixel memory from bitmap.
        void* dst = pixels.get();
        // Keep track of left and top (for drawing subsetBm into canvas). We could use
        // fScale * x and fScale * y, but we want integers such that the next subset will start
        // where the last one ended. So we'll add decodeInfo.width() and height().
        int left = 0;
        for (int x = 0; x < W; x += w) {
            int top = 0;
            for (int y = 0; y < H; y += h) {
                // Do not make the subset go off the edge of the image.
                const int preScaleW = SkTMin(w, W - x);
                const int preScaleH = SkTMin(h, H - y);
                subset.setXYWH(x, y, preScaleW, preScaleH);
                // And scale
                // FIXME: Should we have a version of getScaledDimensions that takes a subset
                // into account?
                const int scaledW = SkTMax(1, SkScalarRoundToInt(preScaleW * fScale));
                const int scaledH = SkTMax(1, SkScalarRoundToInt(preScaleH * fScale));
                decodeInfo = decodeInfo.makeWH(scaledW, scaledH);
                SkImageInfo subsetBitmapInfo = bitmapInfo.makeWH(scaledW, scaledH);
                size_t subsetRowBytes = subsetBitmapInfo.minRowBytes();
                const SkCodec::Result result = codec->getPixels(decodeInfo, dst, subsetRowBytes,
                    &opts, colorPtr, &colorCount);
                switch (result) {
=======
    decodeInfo = decodeInfo.makeWH(size.width(), size.height());

    // Construct a color table for the decode if necessary
    SkAutoTUnref<SkColorTable> colorTable(NULL);
    SkPMColor* colorPtr = NULL;
    int* colorCountPtr = NULL;
    int maxColors = 256;
    if (kIndex_8_SkColorType == decodeInfo.colorType()) {
        SkPMColor colors[256];
        colorTable.reset(SkNEW_ARGS(SkColorTable, (colors, maxColors)));
        colorPtr = const_cast<SkPMColor*>(colorTable->readColors());
        colorCountPtr = &maxColors;
    }

    // FIXME: Currently we cannot draw unpremultiplied sources.
    if (decodeInfo.alphaType() == kUnpremul_SkAlphaType) {
        decodeInfo = decodeInfo.makeAlphaType(kPremul_SkAlphaType);
    }

    SkBitmap bitmap;
    if (!bitmap.tryAllocPixels(decodeInfo, NULL, colorTable.get())) {
        return SkStringPrintf("Image(%s) is too large (%d x %d)\n", fPath.c_str(),
                              decodeInfo.width(), decodeInfo.height());
    }

    switch (fMode) {
        case kNormal_Mode: {
            switch (codec->getPixels(decodeInfo, bitmap.getPixels(), bitmap.rowBytes(), NULL,
                    colorPtr, colorCountPtr)) {
                case SkCodec::kSuccess:
                    // We consider incomplete to be valid, since we should still decode what is
                    // available.
                case SkCodec::kIncompleteInput:
                    break;
                case SkCodec::kInvalidConversion:
                    return Error::Nonfatal("Incompatible colortype conversion");
                default:
                    // Everything else is considered a failure.
                    return SkStringPrintf("Couldn't getPixels %s.", fPath.c_str());
            }
            canvas->drawBitmap(bitmap, 0, 0);
            break;
        }
        case kScanline_Mode: {
            SkScanlineDecoder* scanlineDecoder = codec->getScanlineDecoder(decodeInfo, NULL,
                    colorPtr, colorCountPtr);
            if (NULL == scanlineDecoder) {
                return Error::Nonfatal("Cannot use scanline decoder for all images");
            }
            const SkCodec::Result result = scanlineDecoder->getScanlines(
                    bitmap.getAddr(0, 0), decodeInfo.height(), bitmap.rowBytes());
            switch (result) {
>>>>>>> miniblink49
                case SkCodec::kSuccess:
                case SkCodec::kIncompleteInput:
                    break;
                default:
<<<<<<< HEAD
                    return SkStringPrintf("subset codec failed to decode (%d, %d, %d, %d) "
                                          "from %s with dimensions (%d x %d)\t error %d",
                        x, y, decodeInfo.width(), decodeInfo.height(),
                        fPath.c_str(), W, H, result);
                }
                draw_to_canvas(canvas, subsetBitmapInfo, dst, subsetRowBytes, colorPtr,
                    colorCount, fDstColorType, SkIntToScalar(left),
                    SkIntToScalar(top));

                // translate by the scaled height.
                top += decodeInfo.height();
            }
            // translate by the scaled width.
            left += decodeInfo.width();
        }
        return "";
    }
    default:
        SkASSERT(false);
        return "Invalid fMode";
=======
                    return SkStringPrintf("%s failed with error message %d",
                                          fPath.c_str(), (int) result);
            }
            canvas->drawBitmap(bitmap, 0, 0);
            break;
        }
        case kScanline_Subset_Mode: {
            //this mode decodes the image in divisor*divisor subsets, using a scanline decoder
            const int divisor = 2;
            const int w = decodeInfo.width();
            const int h = decodeInfo.height();
            if (divisor > w || divisor > h) {
                return Error::Nonfatal(SkStringPrintf("Cannot decode subset: divisor %d is too big"
                        "for %s with dimensions (%d x %d)", divisor, fPath.c_str(), w, h));
            }
            const int subsetWidth = w/divisor;
            const int subsetHeight = h/divisor;
            // One of our subsets will be larger to contain any pixels that do not divide evenly.
            const int extraX = w % divisor;
            const int extraY = h % divisor;
            /*
            * if w or h are not evenly divided by divisor need to adjust width and height of end
            * subsets to cover entire image.
            * Add extraX and extraY to largestSubsetBm's width and height to adjust width
            * and height of end subsets.
            * subsetBm is extracted from largestSubsetBm.
            * subsetBm's size is determined based on the current subset and may be larger for end
            * subsets.
            */
            SkImageInfo largestSubsetDecodeInfo =
                    decodeInfo.makeWH(subsetWidth + extraX, subsetHeight + extraY);
            SkBitmap largestSubsetBm;
            if (!largestSubsetBm.tryAllocPixels(largestSubsetDecodeInfo, NULL, colorTable.get())) {
                return SkStringPrintf("Image(%s) is too large (%d x %d)\n", fPath.c_str(),
                        largestSubsetDecodeInfo.width(), largestSubsetDecodeInfo.height());
            }
            const size_t rowBytes = decodeInfo.minRowBytes();
            char* buffer = SkNEW_ARRAY(char, largestSubsetDecodeInfo.height() * rowBytes);
            SkAutoTDeleteArray<char> lineDeleter(buffer);
            for (int col = 0; col < divisor; col++) {
                //currentSubsetWidth may be larger than subsetWidth for rightmost subsets
                const int currentSubsetWidth = (col + 1 == divisor) ?
                        subsetWidth + extraX : subsetWidth;
                const int x = col * subsetWidth;
                for (int row = 0; row < divisor; row++) {
                    //currentSubsetHeight may be larger than subsetHeight for bottom subsets
                    const int currentSubsetHeight = (row + 1 == divisor) ?
                            subsetHeight + extraY : subsetHeight;
                    const int y = row * subsetHeight;
                    //create scanline decoder for each subset
                    SkScanlineDecoder* subsetScanlineDecoder = codec->getScanlineDecoder(decodeInfo,
                            NULL, colorPtr, colorCountPtr);
                    if (NULL == subsetScanlineDecoder) {
                        if (x == 0 && y == 0) {
                            //first try, image may not be compatible
                            return Error::Nonfatal("Cannot use scanline decoder for all images");
                        } else {
                            return "Error scanline decoder is NULL";
                        }
                    }
                    //skip to first line of subset
                    const SkCodec::Result skipResult =
                            subsetScanlineDecoder->skipScanlines(y);
                    switch (skipResult) {
                        case SkCodec::kSuccess:
                        case SkCodec::kIncompleteInput:
                            break;
                        default:
                            return SkStringPrintf("%s failed after attempting to skip %d scanlines"
                                    "with error message %d", fPath.c_str(), y, (int) skipResult);
                    }
                    //create and set size of subsetBm
                    SkBitmap subsetBm;
                    SkIRect bounds = SkIRect::MakeWH(subsetWidth, subsetHeight);
                    bounds.setXYWH(0, 0, currentSubsetWidth, currentSubsetHeight);
                    SkAssertResult(largestSubsetBm.extractSubset(&subsetBm, bounds));
                    SkAutoLockPixels autlockSubsetBm(subsetBm, true);
                    const SkCodec::Result subsetResult =
                        subsetScanlineDecoder->getScanlines(buffer, currentSubsetHeight, rowBytes);
                    switch (subsetResult) {
                        case SkCodec::kSuccess:
                        case SkCodec::kIncompleteInput:
                            break;
                        default:
                            return SkStringPrintf("%s failed with error message %d",
                                    fPath.c_str(), (int) subsetResult);
                    }
                    const size_t bpp = decodeInfo.bytesPerPixel();
                    /*
                     * we copy all the lines at once becuase when calling getScanlines for
                     * interlaced pngs the entire image must be read regardless of the number
                     * of lines requested.  Reading an interlaced png in a loop, line-by-line, would
                     * decode the entire image height times, which is very slow
                     * it is aknowledged that copying each line as you read it in a loop
                     * may be faster for other types of images.  Since this is a correctness test
                     * that's okay.
                    */
                    char* bufferRow = buffer;
                    for (int subsetY = 0; subsetY < currentSubsetHeight; ++subsetY) {
                        memcpy(subsetBm.getAddr(0, subsetY), bufferRow + x*bpp,
                                currentSubsetWidth*bpp);
                        bufferRow += rowBytes;
                    }

                    canvas->drawBitmap(subsetBm, SkIntToScalar(x), SkIntToScalar(y));
                }
            }
            break;
        }
        case kStripe_Mode: {
            const int height = decodeInfo.height();
            // This value is chosen arbitrarily.  We exercise more cases by choosing a value that
            // does not align with image blocks.
            const int stripeHeight = 37;
            const int numStripes = (height + stripeHeight - 1) / stripeHeight;

            // Decode odd stripes
            SkScanlineDecoder* decoder = codec->getScanlineDecoder(decodeInfo, NULL, colorPtr,
                    colorCountPtr);
            if (NULL == decoder) {
                return Error::Nonfatal("Cannot use scanline decoder for all images");
            }
            for (int i = 0; i < numStripes; i += 2) {
                // Skip a stripe
                const int linesToSkip = SkTMin(stripeHeight, height - i * stripeHeight);
                SkCodec::Result result = decoder->skipScanlines(linesToSkip);
                switch (result) {
                    case SkCodec::kSuccess:
                    case SkCodec::kIncompleteInput:
                        break;
                    default:
                        return SkStringPrintf("Cannot skip scanlines for %s.", fPath.c_str());
                }

                // Read a stripe
                const int startY = (i + 1) * stripeHeight;
                const int linesToRead = SkTMin(stripeHeight, height - startY);
                if (linesToRead > 0) {
                    result = decoder->getScanlines(bitmap.getAddr(0, startY),
                            linesToRead, bitmap.rowBytes());
                    switch (result) {
                        case SkCodec::kSuccess:
                        case SkCodec::kIncompleteInput:
                            break;
                        default:
                            return SkStringPrintf("Cannot get scanlines for %s.", fPath.c_str());
                    }
                }
            }

            // Decode even stripes
            decoder = codec->getScanlineDecoder(decodeInfo, NULL, colorPtr, colorCountPtr);
            if (NULL == decoder) {
                return "Failed to create second scanline decoder.";
            }
            for (int i = 0; i < numStripes; i += 2) {
                // Read a stripe
                const int startY = i * stripeHeight;
                const int linesToRead = SkTMin(stripeHeight, height - startY);
                SkCodec::Result result = decoder->getScanlines(bitmap.getAddr(0, startY),
                        linesToRead, bitmap.rowBytes());
                switch (result) {
                    case SkCodec::kSuccess:
                    case SkCodec::kIncompleteInput:
                        break;
                    default:
                        return SkStringPrintf("Cannot get scanlines for %s.", fPath.c_str());
                }

                // Skip a stripe
                const int linesToSkip = SkTMin(stripeHeight, height - (i + 1) * stripeHeight);
                if (linesToSkip > 0) {
                    result = decoder->skipScanlines(linesToSkip);
                    switch (result) {
                        case SkCodec::kSuccess:
                        case SkCodec::kIncompleteInput:
                            break;
                        default:
                            return SkStringPrintf("Cannot skip scanlines for %s.", fPath.c_str());
                    }
                }
            }
            canvas->drawBitmap(bitmap, 0, 0);
            break;
        }
>>>>>>> miniblink49
    }
    return "";
}

<<<<<<< HEAD
SkISize CodecSrc::size() const
{
    SkAutoTUnref<SkData> encoded(SkData::NewFromFileName(fPath.c_str()));
    SkAutoTDelete<SkCodec> codec(SkCodec::NewFromData(encoded));
    if (nullptr == codec) {
        return SkISize::Make(0, 0);
    }
    return codec->getScaledDimensions(fScale);
}

Name CodecSrc::name() const
{
    if (1.0f == fScale) {
        return SkOSPath::Basename(fPath.c_str());
    }
    return get_scaled_name(fPath, fScale);
=======
SkISize CodecSrc::size() const {
    SkAutoTUnref<SkData> encoded(SkData::NewFromFileName(fPath.c_str()));
    SkAutoTDelete<SkCodec> codec(SkCodec::NewFromData(encoded));
    if (NULL != codec) {
        SkISize size = codec->getScaledDimensions(fScale);
        return size;
    } else {
        return SkISize::Make(0, 0);
    }
}

Name CodecSrc::name() const {
    if (1.0f == fScale) {
        return SkOSPath::Basename(fPath.c_str());
    } else {
        return SkStringPrintf("%s_%.3f", SkOSPath::Basename(fPath.c_str()).c_str(), fScale);
    }
>>>>>>> miniblink49
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

<<<<<<< HEAD
AndroidCodecSrc::AndroidCodecSrc(Path path, CodecSrc::DstColorType dstColorType,
    SkAlphaType dstAlphaType, int sampleSize)
    : fPath(path)
    , fDstColorType(dstColorType)
    , fDstAlphaType(dstAlphaType)
    , fSampleSize(sampleSize)
    , fRunSerially(serial_from_path_name(path))
{
}

bool AndroidCodecSrc::veto(SinkFlags flags) const
{
    // No need to test decoding to non-raster or indirect backend.
    return flags.type != SinkFlags::kRaster
        || flags.approach != SinkFlags::kDirect;
}

Error AndroidCodecSrc::draw(SkCanvas* canvas) const
{
    SkAutoTUnref<SkData> encoded(SkData::NewFromFileName(fPath.c_str()));
    if (!encoded) {
        return SkStringPrintf("Couldn't read %s.", fPath.c_str());
    }
    SkAutoTDelete<SkAndroidCodec> codec(SkAndroidCodec::NewFromData(encoded));
    if (nullptr == codec.get()) {
        return SkStringPrintf("Couldn't create android codec for %s.", fPath.c_str());
    }

    SkImageInfo decodeInfo = codec->getInfo();
    if (!get_decode_info(&decodeInfo, canvas->imageInfo().colorType(), fDstColorType,
            fDstAlphaType)) {
        return Error::Nonfatal("Testing non-565 to 565 is uninteresting.");
    }

    // Scale the image if it is desired.
    SkISize size = codec->getSampledDimensions(fSampleSize);

    // Visually inspecting very small output images is not necessary.  We will
    // cover these cases in unit testing.
    if ((size.width() <= 10 || size.height() <= 10) && 1 != fSampleSize) {
        return Error::Nonfatal("Scaling very small images is uninteresting.");
    }
    decodeInfo = decodeInfo.makeWH(size.width(), size.height());

    int bpp = SkColorTypeBytesPerPixel(decodeInfo.colorType());
    size_t rowBytes = size.width() * bpp;
    SkAutoMalloc pixels(size.height() * rowBytes);
    SkPMColor colorPtr[256];
    int colorCount = 256;

    SkBitmap bitmap;
    SkImageInfo bitmapInfo = decodeInfo;
    if (kRGBA_8888_SkColorType == decodeInfo.colorType() || kBGRA_8888_SkColorType == decodeInfo.colorType()) {
        bitmapInfo = bitmapInfo.makeColorType(kN32_SkColorType);
    }

    // Create options for the codec.
    SkAndroidCodec::AndroidOptions options;
    options.fColorPtr = colorPtr;
    options.fColorCount = &colorCount;
    options.fSampleSize = fSampleSize;

    switch (codec->getAndroidPixels(decodeInfo, pixels.get(), rowBytes, &options)) {
    case SkCodec::kSuccess:
    case SkCodec::kIncompleteInput:
        break;
    default:
        return SkStringPrintf("Couldn't getPixels %s.", fPath.c_str());
    }
    draw_to_canvas(canvas, bitmapInfo, pixels.get(), rowBytes, colorPtr, colorCount, fDstColorType);
    return "";
}

SkISize AndroidCodecSrc::size() const
{
    SkAutoTUnref<SkData> encoded(SkData::NewFromFileName(fPath.c_str()));
    SkAutoTDelete<SkAndroidCodec> codec(SkAndroidCodec::NewFromData(encoded));
    if (nullptr == codec) {
        return SkISize::Make(0, 0);
    }
    return codec->getSampledDimensions(fSampleSize);
}

Name AndroidCodecSrc::name() const
{
    // We will replicate the names used by CodecSrc so that images can
    // be compared in Gold.
    if (1 == fSampleSize) {
        return SkOSPath::Basename(fPath.c_str());
    }
    return get_scaled_name(fPath, 1.0f / (float)fSampleSize);
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

ImageGenSrc::ImageGenSrc(Path path, Mode mode, SkAlphaType alphaType, bool isGpu)
    : fPath(path)
    , fMode(mode)
    , fDstAlphaType(alphaType)
    , fIsGpu(isGpu)
    , fRunSerially(serial_from_path_name(path))
{
}

bool ImageGenSrc::veto(SinkFlags flags) const
{
    if (fIsGpu) {
        return flags.type != SinkFlags::kGPU || flags.approach != SinkFlags::kDirect;
    }

    return flags.type != SinkFlags::kRaster || flags.approach != SinkFlags::kDirect;
}

Error ImageGenSrc::draw(SkCanvas* canvas) const
{
    if (kRGB_565_SkColorType == canvas->imageInfo().colorType()) {
        return Error::Nonfatal("Uninteresting to test image generator to 565.");
=======
ImageSrc::ImageSrc(Path path, int divisor) : fPath(path), fDivisor(divisor) {}

Error ImageSrc::draw(SkCanvas* canvas) const {
    SkImageInfo canvasInfo;
    if (NULL == canvas->peekPixels(&canvasInfo, NULL)) {
        // TODO: Instead, use lazy decoding to allow the GPU to handle cases like YUV.
        return Error::Nonfatal("No need to test decoding to non-raster backend.");
>>>>>>> miniblink49
    }

    SkAutoTUnref<SkData> encoded(SkData::NewFromFileName(fPath.c_str()));
    if (!encoded) {
        return SkStringPrintf("Couldn't read %s.", fPath.c_str());
    }
<<<<<<< HEAD

#if defined(SK_BUILD_FOR_WIN)
    // Initialize COM in order to test with WIC.
    SkAutoCoInitialize com;
    if (!com.succeeded()) {
        return "Could not initialize COM.";
    }
#endif

    SkAutoTDelete<SkImageGenerator> gen(nullptr);
    switch (fMode) {
    case kCodec_Mode:
        gen.reset(SkCodecImageGenerator::NewFromEncodedCodec(encoded));
        if (!gen) {
            return "Could not create codec image generator.";
        }
        break;
    case kPlatform_Mode: {
#if defined(SK_BUILD_FOR_MAC) || defined(SK_BUILD_FOR_IOS)
        gen.reset(SkImageGeneratorCG::NewFromEncodedCG(encoded));
#elif defined(SK_BUILD_FOR_WIN)
        gen.reset(SkImageGeneratorWIC::NewFromEncodedWIC(encoded));
#endif

        if (!gen) {
            return "Could not create platform image generator.";
        }
        break;
    }
    default:
        SkASSERT(false);
        return "Invalid image generator mode";
    }

    // Test deferred decoding path on GPU
    if (fIsGpu) {
        sk_sp<SkImage> image(SkImage::MakeFromGenerator(gen.release(), nullptr));
        if (!image) {
            return "Could not create image from codec image generator.";
        }
        canvas->drawImage(image, 0, 0);
        return "";
    }

    // Test various color and alpha types on CPU
    SkImageInfo decodeInfo = gen->getInfo().makeAlphaType(fDstAlphaType);

    int bpp = SkColorTypeBytesPerPixel(decodeInfo.colorType());
    size_t rowBytes = decodeInfo.width() * bpp;
    SkAutoMalloc pixels(decodeInfo.height() * rowBytes);
    SkPMColor colorPtr[256];
    int colorCount = 256;

    if (!gen->getPixels(decodeInfo, pixels.get(), rowBytes, colorPtr, &colorCount)) {
        return SkStringPrintf("Image generator could not getPixels() for %s\n", fPath.c_str());
    }

    draw_to_canvas(canvas, decodeInfo, pixels.get(), rowBytes, colorPtr, colorCount,
        CodecSrc::kGetFromCanvas_DstColorType);
    return "";
}

SkISize ImageGenSrc::size() const
{
    SkAutoTUnref<SkData> encoded(SkData::NewFromFileName(fPath.c_str()));
    SkAutoTDelete<SkCodec> codec(SkCodec::NewFromData(encoded));
    if (nullptr == codec) {
        return SkISize::Make(0, 0);
    }
    return codec->getInfo().dimensions();
}

Name ImageGenSrc::name() const
{
    return SkOSPath::Basename(fPath.c_str());
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

ColorCodecSrc::ColorCodecSrc(Path path, Mode mode)
    : fPath(path)
    , fMode(mode)
{
}

bool ColorCodecSrc::veto(SinkFlags flags) const
{
    // Test to direct raster backends (8888 and 565).
    return flags.type != SinkFlags::kRaster || flags.approach != SinkFlags::kDirect;
}

Error ColorCodecSrc::draw(SkCanvas* canvas) const
{
    if (kRGB_565_SkColorType == canvas->imageInfo().colorType()) {
        return Error::Nonfatal("No need to test color correction to 565 backend.");
    }

    SkAutoTUnref<SkData> encoded(SkData::NewFromFileName(fPath.c_str()));
    if (!encoded) {
        return SkStringPrintf("Couldn't read %s.", fPath.c_str());
    }

    SkAutoTDelete<SkCodec> codec(SkCodec::NewFromData(encoded));
    if (nullptr == codec.get()) {
        return SkStringPrintf("Couldn't create codec for %s.", fPath.c_str());
    }

    SkImageInfo info = codec->getInfo().makeColorType(kN32_SkColorType);
    SkBitmap bitmap;
    if (!bitmap.tryAllocPixels(info)) {
        return SkStringPrintf("Image(%s) is too large (%d x %d)", fPath.c_str(),
            info.width(), info.height());
    }

    SkImageInfo decodeInfo = info;
    if (kBaseline_Mode != fMode) {
        decodeInfo = decodeInfo.makeColorType(kRGBA_8888_SkColorType);
    }

    SkCodec::Result r = codec->getPixels(decodeInfo, bitmap.getPixels(), bitmap.rowBytes());
    if (SkCodec::kSuccess != r) {
        return SkStringPrintf("Couldn't getPixels %s. Error code %d", fPath.c_str(), r);
    }

    // Load the dst ICC profile.  This particular dst is fairly similar to Adobe RGB.
    sk_sp<SkData> dstData = SkData::MakeFromFileName(
        GetResourcePath("monitor_profiles/HP_ZR30w.icc").c_str());
    if (!dstData) {
        return "Cannot read monitor profile.  Is the resource path set correctly?";
    }

    switch (fMode) {
    case kBaseline_Mode:
        canvas->drawBitmap(bitmap, 0, 0);
        break;
    case kDst_sRGB_Mode:
    case kDst_HPZR30w_Mode: {
        sk_sp<SkColorSpace> srcSpace = sk_ref_sp(codec->getColorSpace());
        sk_sp<SkColorSpace> dstSpace = (kDst_sRGB_Mode == fMode) ? SkColorSpace::NewNamed(SkColorSpace::kSRGB_Named) : SkColorSpace::NewICC(dstData->data(), dstData->size());
        SkASSERT(dstSpace);

        std::unique_ptr<SkColorSpaceXform> xform = SkColorSpaceXform::New(srcSpace, dstSpace);
        if (!xform) {
            return "Unimplemented color conversion.";
        }

        uint32_t* row = (uint32_t*)bitmap.getPixels();
        for (int y = 0; y < info.height(); y++) {
            xform->xform_RGB1_8888(row, row, info.width());
            row = SkTAddOffset<uint32_t>(row, bitmap.rowBytes());
        }

        canvas->drawBitmap(bitmap, 0, 0);
        break;
    }
#if defined(SK_TEST_QCMS)
    case kQCMS_HPZR30w_Mode: {
        sk_sp<SkData> srcData = codec->getICCData();
        SkAutoTCallVProc<qcms_profile, qcms_profile_release>
            srcSpace(qcms_profile_from_memory(srcData->data(), srcData->size()));
        if (!srcSpace) {
            return Error::Nonfatal(SkStringPrintf("QCMS cannot create profile for %s.\n",
                fPath.c_str()));
        }

        SkAutoTCallVProc<qcms_profile, qcms_profile_release>
            dstSpace(qcms_profile_from_memory(dstData->data(), dstData->size()));
        SkASSERT(dstSpace);

        // Optimizes conversion by precomputing the inverse transformation to dst.  Also
        // causes QCMS to use a completely different codepath.  This is how Chrome uses QCMS.
        qcms_profile_precache_output_transform(dstSpace);
        SkAutoTCallVProc<qcms_transform, qcms_transform_release>
            transform(qcms_transform_create(srcSpace, QCMS_DATA_RGBA_8, dstSpace,
                QCMS_DATA_RGBA_8, QCMS_INTENT_PERCEPTUAL));
        if (!transform) {
            return SkStringPrintf("QCMS cannot create transform for %s.\n", fPath.c_str());
        }

#ifdef SK_PMCOLOR_IS_RGBA
        qcms_output_type outType = QCMS_OUTPUT_RGBX;
#else
        qcms_output_type outType = QCMS_OUTPUT_BGRX;
#endif

        // Perform color correction.
        uint32_t* row = (uint32_t*)bitmap.getPixels();
        for (int y = 0; y < info.height(); y++) {
            qcms_transform_data_type(transform, row, row, info.width(), outType);
            row = SkTAddOffset<uint32_t>(row, bitmap.rowBytes());
        }

        canvas->drawBitmap(bitmap, 0, 0);
        break;
    }
#endif
    default:
        SkASSERT(false);
        return "Invalid fMode";
    }
    return "";
}

SkISize ColorCodecSrc::size() const
{
    SkAutoTUnref<SkData> encoded(SkData::NewFromFileName(fPath.c_str()));
    SkAutoTDelete<SkCodec> codec(SkCodec::NewFromData(encoded));
    if (nullptr == codec) {
        return SkISize::Make(0, 0);
    }
    return SkISize::Make(codec->getInfo().width(), codec->getInfo().height());
}

Name ColorCodecSrc::name() const
{
=======
    const SkColorType dstColorType = canvasInfo.colorType();
    if (fDivisor == 0) {
        // Decode the full image.
        SkBitmap bitmap;
        if (!SkImageDecoder::DecodeMemory(encoded->data(), encoded->size(), &bitmap,
                                          dstColorType, SkImageDecoder::kDecodePixels_Mode)) {
            return SkStringPrintf("Couldn't decode %s.", fPath.c_str());
        }
        if (kRGB_565_SkColorType == dstColorType && !bitmap.isOpaque()) {
            // Do not draw a bitmap with alpha to a destination without alpha.
            return Error::Nonfatal("Uninteresting to decode image with alpha into 565.");
        }
        encoded.reset((SkData*)NULL);  // Might as well drop this when we're done with it.
        canvas->drawBitmap(bitmap, 0,0);
        return "";
    }
    // Decode subsets.  This is a little involved.
    SkAutoTDelete<SkMemoryStream> stream(new SkMemoryStream(encoded));
    SkAutoTDelete<SkImageDecoder> decoder(SkImageDecoder::Factory(stream.get()));
    if (!decoder) {
        return SkStringPrintf("Can't find a good decoder for %s.", fPath.c_str());
    }
    stream->rewind();
    int w,h;
    if (!decoder->buildTileIndex(stream.detach(), &w, &h)) {
        return Error::Nonfatal("Subset decoding not supported.");
    }

    // Divide the image into subsets that cover the entire image.
    if (fDivisor > w || fDivisor > h) {
        return Error::Nonfatal(SkStringPrintf("Cannot decode subset: divisor %d is too big"
                "for %s with dimensions (%d x %d)", fDivisor, fPath.c_str(), w, h));
    }
    const int subsetWidth  = w / fDivisor,
              subsetHeight = h / fDivisor;
    for (int y = 0; y < h; y += subsetHeight) {
        for (int x = 0; x < w; x += subsetWidth) {
            SkBitmap subset;
            SkIRect rect = SkIRect::MakeXYWH(x, y, subsetWidth, subsetHeight);
            if (!decoder->decodeSubset(&subset, rect, dstColorType)) {
                return SkStringPrintf("Could not decode subset (%d, %d, %d, %d).",
                                      x, y, x+subsetWidth, y+subsetHeight);
            }
            if (kRGB_565_SkColorType == dstColorType && !subset.isOpaque()) {
                // Do not draw a bitmap with alpha to a destination without alpha.
                // This is not an error, but there is nothing interesting to show.

                // This should only happen on the first iteration through the loop.
                SkASSERT(0 == x && 0 == y);

                return Error::Nonfatal("Uninteresting to decode image with alpha into 565.");
            }
            canvas->drawBitmap(subset, SkIntToScalar(x), SkIntToScalar(y));
        }
    }
    return "";
}

SkISize ImageSrc::size() const {
    SkAutoTUnref<SkData> encoded(SkData::NewFromFileName(fPath.c_str()));
    SkBitmap bitmap;
    if (!encoded || !SkImageDecoder::DecodeMemory(encoded->data(),
                                                  encoded->size(),
                                                  &bitmap,
                                                  kUnknown_SkColorType,
                                                  SkImageDecoder::kDecodeBounds_Mode)) {
        return SkISize::Make(0,0);
    }
    return bitmap.dimensions();
}

Name ImageSrc::name() const {
>>>>>>> miniblink49
    return SkOSPath::Basename(fPath.c_str());
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

<<<<<<< HEAD
static const SkRect kSKPViewport = { 0, 0, 1000, 1000 };

SKPSrc::SKPSrc(Path path)
    : fPath(path)
{
}

Error SKPSrc::draw(SkCanvas* canvas) const
{
=======
static const SkRect kSKPViewport = {0,0, 1000,1000};

SKPSrc::SKPSrc(Path path) : fPath(path) {}

Error SKPSrc::draw(SkCanvas* canvas) const {
>>>>>>> miniblink49
    SkAutoTDelete<SkStream> stream(SkStream::NewFromFile(fPath.c_str()));
    if (!stream) {
        return SkStringPrintf("Couldn't read %s.", fPath.c_str());
    }
<<<<<<< HEAD
    sk_sp<SkPicture> pic(SkPicture::MakeFromStream(stream));
    if (!pic) {
        return SkStringPrintf("Couldn't decode %s as a picture.", fPath.c_str());
    }
    stream.reset((SkStream*)nullptr); // Might as well drop this when we're done with it.
=======
    SkAutoTUnref<SkPicture> pic(SkPicture::CreateFromStream(stream, &lazy_decode_bitmap));
    if (!pic) {
        return SkStringPrintf("Couldn't decode %s as a picture.", fPath.c_str());
    }
    stream.reset((SkStream*)NULL);  // Might as well drop this when we're done with it.
>>>>>>> miniblink49

    canvas->clipRect(kSKPViewport);
    canvas->drawPicture(pic);
    return "";
}

<<<<<<< HEAD
SkISize SKPSrc::size() const
{
    SkAutoTDelete<SkStream> stream(SkStream::NewFromFile(fPath.c_str()));
    if (!stream) {
        return SkISize::Make(0, 0);
    }
    SkPictInfo info;
    if (!SkPicture::InternalOnly_StreamIsSKP(stream, &info)) {
        return SkISize::Make(0, 0);
    }
    SkRect viewport = kSKPViewport;
    if (!viewport.intersect(info.fCullRect)) {
        return SkISize::Make(0, 0);
=======
SkISize SKPSrc::size() const {
    SkAutoTDelete<SkStream> stream(SkStream::NewFromFile(fPath.c_str()));
    if (!stream) {
        return SkISize::Make(0,0);
    }
    SkPictInfo info;
    if (!SkPicture::InternalOnly_StreamIsSKP(stream, &info)) {
        return SkISize::Make(0,0);
    }
    SkRect viewport = kSKPViewport;
    if (!viewport.intersect(info.fCullRect)) {
        return SkISize::Make(0,0);
>>>>>>> miniblink49
    }
    return viewport.roundOut().size();
}

Name SKPSrc::name() const { return SkOSPath::Basename(fPath.c_str()); }

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

<<<<<<< HEAD
MSKPSrc::MSKPSrc(Path path)
    : fPath(path)
{
    std::unique_ptr<SkStreamAsset> stream(SkStream::NewFromFile(fPath.c_str()));
    (void)fReader.init(stream.get());
}

int MSKPSrc::pageCount() const { return fReader.pageCount(); }

SkISize MSKPSrc::size() const { return this->size(0); }
SkISize MSKPSrc::size(int i) const { return fReader.pageSize(i).toCeil(); }

Error MSKPSrc::draw(SkCanvas* c) const { return this->draw(0, c); }
Error MSKPSrc::draw(int i, SkCanvas* canvas) const
{
    std::unique_ptr<SkStreamAsset> stream(SkStream::NewFromFile(fPath.c_str()));
    if (!stream) {
        return SkStringPrintf("Unable to open file: %s", fPath.c_str());
    }
    if (fReader.pageCount() == 0) {
        return SkStringPrintf("Unable to parse MultiPictureDocument file: %s", fPath.c_str());
    }
    if (i >= fReader.pageCount()) {
        return SkStringPrintf("MultiPictureDocument page number out of range: %d", i);
    }
    sk_sp<SkPicture> page = fReader.readPage(stream.get(), i);
    if (!page) {
        return SkStringPrintf("SkMultiPictureDocumentReader failed on page %d: %s",
            i, fPath.c_str());
    }
    canvas->drawPicture(page);
    return "";
}

Name MSKPSrc::name() const { return SkOSPath::Basename(fPath.c_str()); }

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

Error NullSink::draw(const Src& src, SkBitmap*, SkWStream*, SkString*) const
{
=======
Error NullSink::draw(const Src& src, SkBitmap*, SkWStream*, SkString*) const {
>>>>>>> miniblink49
    SkAutoTDelete<SkCanvas> canvas(SkCreateNullCanvas());
    return src.draw(canvas);
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

DEFINE_bool(gpuStats, false, "Append GPU stats to the log for each GPU task?");

<<<<<<< HEAD
GPUSink::GPUSink(GrContextFactory::ContextType ct,
    GrContextFactory::ContextOptions options,
    int samples,
    bool diText,
    SkColorType colorType,
    sk_sp<SkColorSpace> colorSpace,
    bool threaded)
    : fContextType(ct)
    , fContextOptions(options)
    , fSampleCount(samples)
    , fUseDIText(diText)
    , fColorType(colorType)
    , fColorSpace(std::move(colorSpace))
    , fThreaded(threaded)
{
}

void PreAbandonGpuContextErrorHandler(SkError, void*) { }

DEFINE_bool(imm, false, "Run gpu configs in immediate mode.");
DEFINE_bool(batchClip, false, "Clip each GrBatch to its device bounds for testing.");
DEFINE_bool(batchBounds, false, "Draw a wireframe bounds of each GrBatch.");
DEFINE_int32(batchLookback, -1, "Maximum GrBatch lookback for combining, negative means default.");
DEFINE_int32(batchLookahead, -1, "Maximum GrBatch lookahead for combining, negative means "
                                 "default.");

Error GPUSink::draw(const Src& src, SkBitmap* dst, SkWStream*, SkString* log) const
{
    GrContextOptions grOptions;
    grOptions.fImmediateMode = FLAGS_imm;
    grOptions.fClipBatchToBounds = FLAGS_batchClip;
    grOptions.fDrawBatchBounds = FLAGS_batchBounds;
    grOptions.fMaxBatchLookback = FLAGS_batchLookback;
    grOptions.fMaxBatchLookahead = FLAGS_batchLookahead;

    src.modifyGrContextOptions(&grOptions);

    GrContextFactory factory(grOptions);
    const SkISize size = src.size();
    const SkImageInfo info = SkImageInfo::Make(size.width(), size.height(), fColorType,
        kPremul_SkAlphaType, fColorSpace);
#if SK_SUPPORT_GPU
    GrContext* context = factory.getContextInfo(fContextType, fContextOptions).grContext();
    const int maxDimension = context->caps()->maxTextureSize();
    if (maxDimension < SkTMax(size.width(), size.height())) {
        return Error::Nonfatal("Src too large to create a texture.\n");
    }
#endif

    auto surface(
        NewGpuSurface(&factory, fContextType, fContextOptions, info, fSampleCount, fUseDIText));
=======
GPUSink::GPUSink(GrContextFactory::GLContextType ct,
                 GrGLStandard api,
                 int samples,
                 bool dfText,
                 bool threaded)
    : fContextType(ct)
    , fGpuAPI(api)
    , fSampleCount(samples)
    , fUseDFText(dfText)
    , fThreaded(threaded) {}

int GPUSink::enclave() const {
    return fThreaded ? kAnyThread_Enclave : kGPU_Enclave;
}

void PreAbandonGpuContextErrorHandler(SkError, void*) {}

Error GPUSink::draw(const Src& src, SkBitmap* dst, SkWStream*, SkString* log) const {
    GrContextOptions options;
    src.modifyGrContextOptions(&options);

    GrContextFactory factory(options);
    const SkISize size = src.size();
    const SkImageInfo info =
        SkImageInfo::Make(size.width(), size.height(), kN32_SkColorType, kPremul_SkAlphaType);
    SkAutoTUnref<SkSurface> surface(
            NewGpuSurface(&factory, fContextType, fGpuAPI, info, fSampleCount, fUseDFText));
>>>>>>> miniblink49
    if (!surface) {
        return "Could not create a surface.";
    }
    if (FLAGS_preAbandonGpuContext) {
<<<<<<< HEAD
        SkSetErrorCallback(&PreAbandonGpuContextErrorHandler, nullptr);
=======
        SkSetErrorCallback(&PreAbandonGpuContextErrorHandler, NULL);
>>>>>>> miniblink49
        factory.abandonContexts();
    }
    SkCanvas* canvas = surface->getCanvas();
    Error err = src.draw(canvas);
    if (!err.isEmpty()) {
        return err;
    }
    canvas->flush();
    if (FLAGS_gpuStats) {
        canvas->getGrContext()->dumpCacheStats(log);
        canvas->getGrContext()->dumpGpuStats(log);
    }
    dst->allocPixels(info);
    canvas->readPixels(dst, 0, 0);
    if (FLAGS_abandonGpuContext) {
        factory.abandonContexts();
<<<<<<< HEAD
    } else if (FLAGS_releaseAndAbandonGpuContext) {
        factory.releaseResourcesAndAbandonContexts();
=======
>>>>>>> miniblink49
    }
    return "";
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

<<<<<<< HEAD
static Error draw_skdocument(const Src& src, SkDocument* doc, SkWStream* dst)
{
    if (src.size().isEmpty()) {
        return "Source has empty dimensions";
    }
    SkASSERT(doc);
    int pageCount = src.pageCount();
    for (int i = 0; i < pageCount; ++i) {
        int width = src.size(i).width(), height = src.size(i).height();
        SkCanvas* canvas = doc->beginPage(SkIntToScalar(width), SkIntToScalar(height));
        if (!canvas) {
            return "SkDocument::beginPage(w,h) returned nullptr";
        }
        Error err = src.draw(i, canvas);
=======
static Error draw_skdocument(const Src& src, SkDocument* doc, SkWStream* dst) {
    // Print the given DM:Src to a document, breaking on 8.5x11 pages.
    SkASSERT(doc);
    int width  = src.size().width(),
        height = src.size().height();

    if (FLAGS_multiPage) {
        const int kLetterWidth = 612,  // 8.5 * 72
                kLetterHeight = 792;   // 11 * 72
        const SkRect letter = SkRect::MakeWH(SkIntToScalar(kLetterWidth),
                                             SkIntToScalar(kLetterHeight));

        int xPages = ((width - 1) / kLetterWidth) + 1;
        int yPages = ((height - 1) / kLetterHeight) + 1;

        for (int y = 0; y < yPages; ++y) {
            for (int x = 0; x < xPages; ++x) {
                int w = SkTMin(kLetterWidth, width - (x * kLetterWidth));
                int h = SkTMin(kLetterHeight, height - (y * kLetterHeight));
                SkCanvas* canvas =
                        doc->beginPage(SkIntToScalar(w), SkIntToScalar(h));
                if (!canvas) {
                    return "SkDocument::beginPage(w,h) returned NULL";
                }
                canvas->clipRect(letter);
                canvas->translate(-letter.width() * x, -letter.height() * y);
                Error err = src.draw(canvas);
                if (!err.isEmpty()) {
                    return err;
                }
                doc->endPage();
            }
        }
    } else {
        SkCanvas* canvas =
                doc->beginPage(SkIntToScalar(width), SkIntToScalar(height));
        if (!canvas) {
            return "SkDocument::beginPage(w,h) returned NULL";
        }
        Error err = src.draw(canvas);
>>>>>>> miniblink49
        if (!err.isEmpty()) {
            return err;
        }
        doc->endPage();
    }
    if (!doc->close()) {
        return "SkDocument::close() returned false";
    }
    dst->flush();
    return "";
}

<<<<<<< HEAD
Error PDFSink::draw(const Src& src, SkBitmap*, SkWStream* dst, SkString*) const
{
    SkDocument::PDFMetadata metadata;
    metadata.fTitle = src.name();
    metadata.fSubject = "rendering correctness test";
    metadata.fCreator = "Skia/DM";
    sk_sp<SkDocument> doc = SkDocument::MakePDF(dst, SK_ScalarDefaultRasterDPI,
        metadata, nullptr, fPDFA);
    if (!doc) {
        return "SkDocument::MakePDF() returned nullptr";
=======
PDFSink::PDFSink() {}

Error PDFSink::draw(const Src& src, SkBitmap*, SkWStream* dst, SkString*) const {
    SkAutoTUnref<SkDocument> doc(SkDocument::CreatePDF(dst));
    if (!doc) {
        return "SkDocument::CreatePDF() returned NULL";
>>>>>>> miniblink49
    }
    return draw_skdocument(src, doc.get(), dst);
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

<<<<<<< HEAD
XPSSink::XPSSink() { }

Error XPSSink::draw(const Src& src, SkBitmap*, SkWStream* dst, SkString*) const
{
    sk_sp<SkDocument> doc(SkDocument::MakeXPS(dst));
    if (!doc) {
        return "SkDocument::MakeXPS() returned nullptr";
=======
XPSSink::XPSSink() {}

Error XPSSink::draw(const Src& src, SkBitmap*, SkWStream* dst, SkString*) const {
    SkAutoTUnref<SkDocument> doc(SkDocument::CreateXPS(dst));
    if (!doc) {
        return "SkDocument::CreateXPS() returned NULL";
>>>>>>> miniblink49
    }
    return draw_skdocument(src, doc.get(), dst);
}
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

<<<<<<< HEAD
SKPSink::SKPSink() { }

Error SKPSink::draw(const Src& src, SkBitmap*, SkWStream* dst, SkString*) const
{
=======
SKPSink::SKPSink() {}

Error SKPSink::draw(const Src& src, SkBitmap*, SkWStream* dst, SkString*) const {
>>>>>>> miniblink49
    SkSize size;
    size = src.size();
    SkPictureRecorder recorder;
    Error err = src.draw(recorder.beginRecording(size.width(), size.height()));
    if (!err.isEmpty()) {
        return err;
    }
<<<<<<< HEAD
    recorder.finishRecordingAsPicture()->serialize(dst);
=======
    SkAutoTUnref<SkPicture> pic(recorder.endRecording());
    pic->serialize(dst);
>>>>>>> miniblink49
    return "";
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

<<<<<<< HEAD
SVGSink::SVGSink() { }

Error SVGSink::draw(const Src& src, SkBitmap*, SkWStream* dst, SkString*) const
{
    SkAutoTDelete<SkXMLWriter> xmlWriter(new SkXMLStreamWriter(dst));
=======
SVGSink::SVGSink() {}

Error SVGSink::draw(const Src& src, SkBitmap*, SkWStream* dst, SkString*) const {
    SkAutoTDelete<SkXMLWriter> xmlWriter(SkNEW_ARGS(SkXMLStreamWriter, (dst)));
>>>>>>> miniblink49
    SkAutoTUnref<SkCanvas> canvas(SkSVGCanvas::Create(
        SkRect::MakeWH(SkIntToScalar(src.size().width()), SkIntToScalar(src.size().height())),
        xmlWriter));
    return src.draw(canvas);
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

<<<<<<< HEAD
RasterSink::RasterSink(SkColorType colorType, sk_sp<SkColorSpace> colorSpace)
    : fColorType(colorType)
    , fColorSpace(std::move(colorSpace))
{
}

Error RasterSink::draw(const Src& src, SkBitmap* dst, SkWStream*, SkString*) const
{
=======
RasterSink::RasterSink(SkColorType colorType) : fColorType(colorType) {}

Error RasterSink::draw(const Src& src, SkBitmap* dst, SkWStream*, SkString*) const {
>>>>>>> miniblink49
    const SkISize size = src.size();
    // If there's an appropriate alpha type for this color type, use it, otherwise use premul.
    SkAlphaType alphaType = kPremul_SkAlphaType;
    (void)SkColorTypeValidateAlphaType(fColorType, alphaType, &alphaType);

<<<<<<< HEAD
    SkMallocPixelRef::ZeroedPRFactory factory;
    dst->allocPixels(SkImageInfo::Make(size.width(), size.height(),
                         fColorType, alphaType, fColorSpace),
        &factory,
        nullptr /*colortable*/);
=======
    dst->allocPixels(SkImageInfo::Make(size.width(), size.height(), fColorType, alphaType));
    dst->eraseColor(SK_ColorTRANSPARENT);
>>>>>>> miniblink49
    SkCanvas canvas(*dst);
    return src.draw(&canvas);
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

// Handy for front-patching a Src.  Do whatever up-front work you need, then call draw_to_canvas(),
// passing the Sink draw() arguments, a size, and a function draws into an SkCanvas.
// Several examples below.

<<<<<<< HEAD
template <typename Fn>
static Error draw_to_canvas(Sink* sink, SkBitmap* bitmap, SkWStream* stream, SkString* log,
    SkISize size, const Fn& draw)
{
    class ProxySrc : public Src {
    public:
        ProxySrc(SkISize size, const Fn& draw)
            : fSize(size)
            , fDraw(draw)
        {
        }
        Error draw(SkCanvas* canvas) const override { return fDraw(canvas); }
        Name name() const override { return "ProxySrc"; }
        SkISize size() const override { return fSize; }

    private:
        SkISize fSize;
        const Fn& fDraw;
=======
static Error draw_to_canvas(Sink* sink, SkBitmap* bitmap, SkWStream* stream, SkString* log,
                            SkISize size, SkFunction<Error(SkCanvas*)> draw) {
    class ProxySrc : public Src {
    public:
        ProxySrc(SkISize size, SkFunction<Error(SkCanvas*)> draw) : fSize(size), fDraw(draw) {}
        Error   draw(SkCanvas* canvas) const override { return fDraw(canvas); }
        Name                    name() const override { sk_throw(); return ""; } // Won't be called.
        SkISize                 size() const override { return fSize; }
    private:
        SkISize                      fSize;
        SkFunction<Error(SkCanvas*)> fDraw;
>>>>>>> miniblink49
    };
    return sink->draw(ProxySrc(size, draw), bitmap, stream, log);
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

<<<<<<< HEAD
DEFINE_bool(check, true, "If true, have most Via- modes fail if they affect the output.");

// Is *bitmap identical to what you get drawing src into sink?
static Error check_against_reference(const SkBitmap* bitmap, const Src& src, Sink* sink)
{
    // We can only check raster outputs.
    // (Non-raster outputs like .pdf, .skp, .svg may differ but still draw identically.)
    if (FLAGS_check && bitmap) {
        SkBitmap reference;
        SkString log;
        SkDynamicMemoryWStream wStream;
        Error err = sink->draw(src, &reference, &wStream, &log);
        // If we can draw into this Sink via some pipeline, we should be able to draw directly.
        SkASSERT(err.isEmpty());
        if (!err.isEmpty()) {
            return err;
        }
        // The dimensions are a property of the Src only, and so should be identical.
        SkASSERT(reference.getSize() == bitmap->getSize());
        if (reference.getSize() != bitmap->getSize()) {
            return "Dimensions don't match reference";
        }
        // All SkBitmaps in DM are pre-locked and tight, so this comparison is easy.
        if (0 != memcmp(reference.getPixels(), bitmap->getPixels(), reference.getSize())) {
            return "Pixels don't match reference";
        }
    }
    return "";
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

static SkISize auto_compute_translate(SkMatrix* matrix, int srcW, int srcH)
{
=======
static SkISize auto_compute_translate(SkMatrix* matrix, int srcW, int srcH) {
>>>>>>> miniblink49
    SkRect bounds = SkRect::MakeIWH(srcW, srcH);
    matrix->mapRect(&bounds);
    matrix->postTranslate(-bounds.x(), -bounds.y());
    return SkISize::Make(SkScalarRoundToInt(bounds.width()), SkScalarRoundToInt(bounds.height()));
}

<<<<<<< HEAD
ViaMatrix::ViaMatrix(SkMatrix matrix, Sink* sink)
    : Via(sink)
    , fMatrix(matrix)
{
}

Error ViaMatrix::draw(const Src& src, SkBitmap* bitmap, SkWStream* stream, SkString* log) const
{
=======
ViaMatrix::ViaMatrix(SkMatrix matrix, Sink* sink) : Via(sink), fMatrix(matrix) {}

Error ViaMatrix::draw(const Src& src, SkBitmap* bitmap, SkWStream* stream, SkString* log) const {
>>>>>>> miniblink49
    SkMatrix matrix = fMatrix;
    SkISize size = auto_compute_translate(&matrix, src.size().width(), src.size().height());
    return draw_to_canvas(fSink, bitmap, stream, log, size, [&](SkCanvas* canvas) {
        canvas->concat(matrix);
        return src.draw(canvas);
    });
}

// Undoes any flip or 90 degree rotate without changing the scale of the bitmap.
// This should be pixel-preserving.
<<<<<<< HEAD
ViaUpright::ViaUpright(SkMatrix matrix, Sink* sink)
    : Via(sink)
    , fMatrix(matrix)
{
}

Error ViaUpright::draw(const Src& src, SkBitmap* bitmap, SkWStream* stream, SkString* log) const
{
=======
ViaUpright::ViaUpright(SkMatrix matrix, Sink* sink) : Via(sink), fMatrix(matrix) {}

Error ViaUpright::draw(const Src& src, SkBitmap* bitmap, SkWStream* stream, SkString* log) const {
>>>>>>> miniblink49
    Error err = fSink->draw(src, bitmap, stream, log);
    if (!err.isEmpty()) {
        return err;
    }

    SkMatrix inverse;
    if (!fMatrix.rectStaysRect() || !fMatrix.invert(&inverse)) {
        return "Cannot upright --matrix.";
    }
    SkMatrix upright = SkMatrix::I();
    upright.setScaleX(SkScalarSignAsScalar(inverse.getScaleX()));
    upright.setScaleY(SkScalarSignAsScalar(inverse.getScaleY()));
    upright.setSkewX(SkScalarSignAsScalar(inverse.getSkewX()));
    upright.setSkewY(SkScalarSignAsScalar(inverse.getSkewY()));

    SkBitmap uprighted;
    SkISize size = auto_compute_translate(&upright, bitmap->width(), bitmap->height());
    uprighted.allocPixels(bitmap->info().makeWH(size.width(), size.height()));

    SkCanvas canvas(uprighted);
    canvas.concat(upright);
    SkPaint paint;
    paint.setXfermodeMode(SkXfermode::kSrc_Mode);
    canvas.drawBitmap(*bitmap, 0, 0, &paint);

    *bitmap = uprighted;
    bitmap->lockPixels();
    return "";
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

<<<<<<< HEAD
Error ViaSerialization::draw(
    const Src& src, SkBitmap* bitmap, SkWStream* stream, SkString* log) const
{
=======
Error ViaPipe::draw(const Src& src, SkBitmap* bitmap, SkWStream* stream, SkString* log) const {
    auto size = src.size();
    return draw_to_canvas(fSink, bitmap, stream, log, size, [&](SkCanvas* canvas) {
        PipeController controller(canvas, &SkImageDecoder::DecodeMemory);
        SkGPipeWriter pipe;
        const uint32_t kFlags = 0; // We mirror SkDeferredCanvas, which doesn't use any flags.
        return src.draw(pipe.startRecording(&controller, kFlags, size.width(), size.height()));
    });
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

Error ViaDeferred::draw(const Src& src, SkBitmap* bitmap, SkWStream* stream, SkString* log) const {
    // We draw via a deferred canvas into a surface that's compatible with the original canvas,
    // then snap that surface as an image and draw it into the original canvas.
    return draw_to_canvas(fSink, bitmap, stream, log, src.size(), [&](SkCanvas* canvas) -> Error {
        SkAutoTUnref<SkSurface> surface(canvas->newSurface(canvas->imageInfo()));
        if (!surface.get()) {
            return "can't make surface for deferred canvas";
        }
        SkAutoTDelete<SkDeferredCanvas> defcan(SkDeferredCanvas::Create(surface));
        Error err = src.draw(defcan);
        if (!err.isEmpty()) {
            return err;
        }
        SkAutoTUnref<SkImage> image(defcan->newImageSnapshot());
        if (!image) {
            return "failed to create deferred image snapshot";
        }
        canvas->drawImage(image, 0, 0, NULL);
        return "";
    });
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

Error ViaSerialization::draw(
        const Src& src, SkBitmap* bitmap, SkWStream* stream, SkString* log) const {
>>>>>>> miniblink49
    // Record our Src into a picture.
    auto size = src.size();
    SkPictureRecorder recorder;
    Error err = src.draw(recorder.beginRecording(SkIntToScalar(size.width()),
<<<<<<< HEAD
        SkIntToScalar(size.height())));
    if (!err.isEmpty()) {
        return err;
    }
    sk_sp<SkPicture> pic(recorder.finishRecordingAsPicture());
=======
                                                 SkIntToScalar(size.height())));
    if (!err.isEmpty()) {
        return err;
    }
    SkAutoTUnref<SkPicture> pic(recorder.endRecording());
>>>>>>> miniblink49

    // Serialize it and then deserialize it.
    SkDynamicMemoryWStream wStream;
    pic->serialize(&wStream);
    SkAutoTDelete<SkStream> rStream(wStream.detachAsStream());
<<<<<<< HEAD
    sk_sp<SkPicture> deserialized(SkPicture::MakeFromStream(rStream));

    return draw_to_canvas(fSink, bitmap, stream, log, size, [&](SkCanvas* canvas) {
        canvas->drawPicture(deserialized);
        return check_against_reference(bitmap, src, fSink);
=======
    SkAutoTUnref<SkPicture> deserialized(SkPicture::CreateFromStream(rStream, &lazy_decode_bitmap));

    return draw_to_canvas(fSink, bitmap, stream, log, size, [&](SkCanvas* canvas) {
        canvas->drawPicture(deserialized);
        return "";
>>>>>>> miniblink49
    });
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

ViaTiles::ViaTiles(int w, int h, SkBBHFactory* factory, Sink* sink)
    : Via(sink)
    , fW(w)
    , fH(h)
<<<<<<< HEAD
    , fFactory(factory)
{
}

Error ViaTiles::draw(const Src& src, SkBitmap* bitmap, SkWStream* stream, SkString* log) const
{
    auto size = src.size();
    SkPictureRecorder recorder;
    Error err = src.draw(recorder.beginRecording(SkIntToScalar(size.width()),
        SkIntToScalar(size.height()),
        fFactory.get()));
    if (!err.isEmpty()) {
        return err;
    }
    sk_sp<SkPicture> pic(recorder.finishRecordingAsPicture());

    return draw_to_canvas(fSink, bitmap, stream, log, src.size(), [&](SkCanvas* canvas) {
        const int xTiles = (size.width() + fW - 1) / fW,
                  yTiles = (size.height() + fH - 1) / fH;
        SkMultiPictureDraw mpd(xTiles * yTiles);
        SkTArray<sk_sp<SkSurface>> surfaces;
        //        surfaces.setReserve(xTiles*yTiles);
=======
    , fFactory(factory) {}

Error ViaTiles::draw(const Src& src, SkBitmap* bitmap, SkWStream* stream, SkString* log) const {
    auto size = src.size();
    SkPictureRecorder recorder;
    Error err = src.draw(recorder.beginRecording(SkIntToScalar(size.width()),
                                                 SkIntToScalar(size.height()),
                                                 fFactory.get()));
    if (!err.isEmpty()) {
        return err;
    }
    SkAutoTUnref<SkPicture> pic(recorder.endRecordingAsPicture());

    return draw_to_canvas(fSink, bitmap, stream, log, src.size(), [&](SkCanvas* canvas) {
        const int xTiles = (size.width()  + fW - 1) / fW,
                  yTiles = (size.height() + fH - 1) / fH;
        SkMultiPictureDraw mpd(xTiles*yTiles);
        SkTDArray<SkSurface*> surfaces;
        surfaces.setReserve(xTiles*yTiles);
>>>>>>> miniblink49

        SkImageInfo info = canvas->imageInfo().makeWH(fW, fH);
        for (int j = 0; j < yTiles; j++) {
            for (int i = 0; i < xTiles; i++) {
                // This lets our ultimate Sink determine the best kind of surface.
                // E.g., if it's a GpuSink, the surfaces and images are textures.
<<<<<<< HEAD
                auto s = canvas->makeSurface(info);
                if (!s) {
                    s = SkSurface::MakeRaster(info); // Some canvases can't create surfaces.
                }
                surfaces.push_back(s);
                SkCanvas* c = s->getCanvas();
                c->translate(SkIntToScalar(-i * fW),
                    SkIntToScalar(-j * fH)); // Line up the canvas with this tile.
                mpd.add(c, pic.get());
=======
                SkSurface* s = canvas->newSurface(info);
                if (!s) {
                    s = SkSurface::NewRaster(info);  // Some canvases can't create surfaces.
                }
                surfaces.push(s);
                SkCanvas* c = s->getCanvas();
                c->translate(SkIntToScalar(-i * fW),
                             SkIntToScalar(-j * fH));  // Line up the canvas with this tile.
                mpd.add(c, pic);
>>>>>>> miniblink49
            }
        }
        mpd.draw();
        for (int j = 0; j < yTiles; j++) {
            for (int i = 0; i < xTiles; i++) {
<<<<<<< HEAD
                sk_sp<SkImage> image(surfaces[i + xTiles * j]->makeImageSnapshot());
                canvas->drawImage(image, SkIntToScalar(i * fW), SkIntToScalar(j * fH));
            }
        }
=======
                SkAutoTUnref<SkImage> image(surfaces[i+xTiles*j]->newImageSnapshot());
                canvas->drawImage(image, SkIntToScalar(i*fW), SkIntToScalar(j*fH));
            }
        }
        surfaces.unrefAll();
>>>>>>> miniblink49
        return "";
    });
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

<<<<<<< HEAD
Error ViaPicture::draw(const Src& src, SkBitmap* bitmap, SkWStream* stream, SkString* log) const
{
    auto size = src.size();
    return draw_to_canvas(fSink, bitmap, stream, log, size, [&](SkCanvas* canvas) -> Error {
        SkPictureRecorder recorder;
        sk_sp<SkPicture> pic;
        Error err = src.draw(recorder.beginRecording(SkIntToScalar(size.width()),
            SkIntToScalar(size.height())));
        if (!err.isEmpty()) {
            return err;
        }
        pic = recorder.finishRecordingAsPicture();
        canvas->drawPicture(pic);
        return check_against_reference(bitmap, src, fSink);
    });
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

// Draw the Src into two pictures, then draw the second picture into the wrapped Sink.
// This tests that any shortcuts we may take while recording that second picture are legal.
Error ViaSecondPicture::draw(
    const Src& src, SkBitmap* bitmap, SkWStream* stream, SkString* log) const
{
    auto size = src.size();
    return draw_to_canvas(fSink, bitmap, stream, log, size, [&](SkCanvas* canvas) -> Error {
        SkPictureRecorder recorder;
        sk_sp<SkPicture> pic;
        for (int i = 0; i < 2; i++) {
            Error err = src.draw(recorder.beginRecording(SkIntToScalar(size.width()),
                SkIntToScalar(size.height())));
            if (!err.isEmpty()) {
                return err;
            }
            pic = recorder.finishRecordingAsPicture();
        }
        canvas->drawPicture(pic);
        return check_against_reference(bitmap, src, fSink);
=======
// Draw the Src into two pictures, then draw the second picture into the wrapped Sink.
// This tests that any shortcuts we may take while recording that second picture are legal.
Error ViaSecondPicture::draw(
        const Src& src, SkBitmap* bitmap, SkWStream* stream, SkString* log) const {
    auto size = src.size();
    return draw_to_canvas(fSink, bitmap, stream, log, size, [&](SkCanvas* canvas) -> Error {
        SkPictureRecorder recorder;
        SkAutoTUnref<SkPicture> pic;
        for (int i = 0; i < 2; i++) {
            Error err = src.draw(recorder.beginRecording(SkIntToScalar(size.width()),
                                                         SkIntToScalar(size.height())));
            if (!err.isEmpty()) {
                return err;
            }
            pic.reset(recorder.endRecordingAsPicture());
        }
        canvas->drawPicture(pic);
        return "";
>>>>>>> miniblink49
    });
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

// Draw the Src twice.  This can help exercise caching.
<<<<<<< HEAD
Error ViaTwice::draw(const Src& src, SkBitmap* bitmap, SkWStream* stream, SkString* log) const
{
    return draw_to_canvas(fSink, bitmap, stream, log, src.size(), [&](SkCanvas* canvas) -> Error {
        for (int i = 0; i < 2; i++) {
            SkAutoCanvasRestore acr(canvas, true /*save now*/);
=======
Error ViaTwice::draw(const Src& src, SkBitmap* bitmap, SkWStream* stream, SkString* log) const {
    return draw_to_canvas(fSink, bitmap, stream, log, src.size(), [&](SkCanvas* canvas) -> Error {
        for (int i = 0; i < 2; i++) {
            SkAutoCanvasRestore acr(canvas, true/*save now*/);
>>>>>>> miniblink49
            canvas->clear(SK_ColorTRANSPARENT);
            Error err = src.draw(canvas);
            if (err.isEmpty()) {
                return err;
            }
        }
<<<<<<< HEAD
        return check_against_reference(bitmap, src, fSink);
=======
        return "";
>>>>>>> miniblink49
    });
}

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

// This is like SkRecords::Draw, in that it plays back SkRecords ops into a Canvas.
// Unlike SkRecords::Draw, it builds a single-op sub-picture out of each Draw-type op.
// This is an only-slightly-exaggerated simluation of Blink's Slimming Paint pictures.
struct DrawsAsSingletonPictures {
    SkCanvas* fCanvas;
    const SkDrawableList& fDrawables;
<<<<<<< HEAD
    SkRect fBounds;

    template <typename T>
    void draw(const T& op, SkCanvas* canvas)
    {
=======

    SK_CREATE_MEMBER_DETECTOR(paint);

    template <typename T>
    void draw(const T& op, SkCanvas* canvas) {
>>>>>>> miniblink49
        // We must pass SkMatrix::I() as our initial matrix.
        // By default SkRecords::Draw() uses the canvas' matrix as its initial matrix,
        // which would have the funky effect of applying transforms over and over.
        SkRecords::Draw d(canvas, nullptr, fDrawables.begin(), fDrawables.count(), &SkMatrix::I());
        d(op);
    }

<<<<<<< HEAD
    // Draws get their own picture.
    template <typename T>
    SK_WHEN(T::kTags& SkRecords::kDraw_Tag, void)
    operator()(const T& op)
    {
        SkPictureRecorder rec;
        this->draw(op, rec.beginRecording(fBounds));
        sk_sp<SkPicture> pic(rec.finishRecordingAsPicture());
        fCanvas->drawPicture(pic);
    }

    // We'll just issue non-draws directly.
    template <typename T>
    skstd::enable_if_t<!(T::kTags & SkRecords::kDraw_Tag), void> operator()(const T& op)
    {
        this->draw(op, fCanvas);
    }
=======
    // Most things that have paints are Draw-type ops.  Create sub-pictures for each.
    template <typename T>
    SK_WHEN(HasMember_paint<T>, void) operator()(const T& op) {
        SkPictureRecorder rec;
        this->draw(op, rec.beginRecording(SkRect::MakeLargest()));
        SkAutoTUnref<SkPicture> pic(rec.endRecordingAsPicture());
        fCanvas->drawPicture(pic);
    }

    // If you don't have a paint or are a SaveLayer, you're not a Draw-type op.
    // We cannot make subpictures out of these because they affect state.  Draw them directly.
    template <typename T>
    SK_WHEN(!HasMember_paint<T>, void) operator()(const T& op) { this->draw(op, fCanvas); }
    void operator()(const SkRecords::SaveLayer& op)            { this->draw(op, fCanvas); }
>>>>>>> miniblink49
};

// Record Src into a picture, then record it into a macro picture with a sub-picture for each draw.
// Then play back that macro picture into our wrapped sink.
Error ViaSingletonPictures::draw(
<<<<<<< HEAD
    const Src& src, SkBitmap* bitmap, SkWStream* stream, SkString* log) const
{
=======
        const Src& src, SkBitmap* bitmap, SkWStream* stream, SkString* log) const {
>>>>>>> miniblink49
    auto size = src.size();
    return draw_to_canvas(fSink, bitmap, stream, log, size, [&](SkCanvas* canvas) -> Error {
        // Use low-level (Skia-private) recording APIs so we can read the SkRecord.
        SkRecord skr;
        SkRecorder recorder(&skr, size.width(), size.height());
        Error err = src.draw(&recorder);
        if (!err.isEmpty()) {
            return err;
        }

        // Record our macro-picture, with each draw op as its own sub-picture.
        SkPictureRecorder macroRec;
        SkCanvas* macroCanvas = macroRec.beginRecording(SkIntToScalar(size.width()),
<<<<<<< HEAD
            SkIntToScalar(size.height()));
=======
                                                        SkIntToScalar(size.height()));
>>>>>>> miniblink49

        SkAutoTDelete<SkDrawableList> drawables(recorder.detachDrawableList());
        const SkDrawableList empty;

        DrawsAsSingletonPictures drawsAsSingletonPictures = {
            macroCanvas,
            drawables ? *drawables : empty,
<<<<<<< HEAD
            SkRect::MakeWH((SkScalar)size.width(), (SkScalar)size.height()),
        };
        for (int i = 0; i < skr.count(); i++) {
            skr.visit(i, drawsAsSingletonPictures);
        }
        sk_sp<SkPicture> macroPic(macroRec.finishRecordingAsPicture());

        canvas->drawPicture(macroPic);
        return check_against_reference(bitmap, src, fSink);
    });
}

} // namespace DM
=======
        };
        for (unsigned i = 0; i < skr.count(); i++) {
            skr.visit<void>(i, drawsAsSingletonPictures);
        }
        SkAutoTUnref<SkPicture> macroPic(macroRec.endRecordingAsPicture());

        canvas->drawPicture(macroPic);
        return "";
    });
}

}  // namespace DM
>>>>>>> miniblink49
