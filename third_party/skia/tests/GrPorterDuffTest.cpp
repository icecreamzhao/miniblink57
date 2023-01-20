/*
 * Copyright 2015 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkXfermode.h"
#include "Test.h"

#if SK_SUPPORT_GPU

<<<<<<< HEAD
=======
#include "GrBatch.h"
>>>>>>> miniblink49
#include "GrContextFactory.h"
#include "GrContextOptions.h"
#include "GrGpu.h"
#include "GrResourceProvider.h"
#include "GrXferProcessor.h"
<<<<<<< HEAD
#include "batches/GrVertexBatch.h"
=======
>>>>>>> miniblink49
#include "effects/GrPorterDuffXferProcessor.h"
#include "gl/GrGLCaps.h"

////////////////////////////////////////////////////////////////////////////////

static void test_color_unknown_with_coverage(skiatest::Reporter* reporter, const GrCaps& caps);
static void test_color_unknown_no_coverage(skiatest::Reporter* reporter, const GrCaps& caps);
static void test_color_opaque_with_coverage(skiatest::Reporter* reporter, const GrCaps& caps);
static void test_color_opaque_no_coverage(skiatest::Reporter* reporter, const GrCaps& caps);
static void test_lcd_coverage(skiatest::Reporter* reporter, const GrCaps& caps);
<<<<<<< HEAD
static void test_lcd_coverage_fallback_case(skiatest::Reporter* reporter, const GrCaps& caps);

DEF_GPUTEST_FOR_NULLGL_CONTEXT(GrPorterDuff, reporter, ctxInfo)
{
    const GrCaps& caps = *ctxInfo.grContext()->getGpu()->caps();
=======
static void test_no_dual_source_blending(skiatest::Reporter* reporter);

DEF_GPUTEST(GrPorterDuff, reporter, factory) {
    GrContext* ctx = factory->get(GrContextFactory::kNull_GLContextType);
    if (!ctx) {
        SkFAIL("Failed to create null context.");
        return;
    }

    const GrCaps& caps = *ctx->getGpu()->caps();
>>>>>>> miniblink49
    if (!caps.shaderCaps()->dualSourceBlendingSupport()) {
        SkFAIL("Null context does not support dual source blending.");
        return;
    }

    test_color_unknown_with_coverage(reporter, caps);
    test_color_unknown_no_coverage(reporter, caps);
    test_color_opaque_with_coverage(reporter, caps);
    test_color_opaque_no_coverage(reporter, caps);
    test_lcd_coverage(reporter, caps);
<<<<<<< HEAD
    test_lcd_coverage_fallback_case(reporter, caps);
=======
    test_no_dual_source_blending(reporter);
>>>>>>> miniblink49
}

////////////////////////////////////////////////////////////////////////////////

#define TEST_ASSERT(...) REPORTER_ASSERT(reporter, __VA_ARGS__)

enum {
    kNone_OutputType,
    kCoverage_OutputType,
    kModulate_OutputType,
<<<<<<< HEAD
    kSAModulate_OutputType,
=======
>>>>>>> miniblink49
    kISAModulate_OutputType,
    kISCModulate_OutputType
};

enum {
<<<<<<< HEAD
    kNone_OptFlags = GrXferProcessor::kNone_OptFlags,
    kSkipDraw_OptFlag = GrXferProcessor::kSkipDraw_OptFlag,
    kIgnoreColor_OptFlag = GrXferProcessor::kIgnoreColor_OptFlag,
    kIgnoreCoverage_OptFlag = GrXferProcessor::kIgnoreCoverage_OptFlag,
=======
    kNone_OptFlags                    = GrXferProcessor::kNone_OptFlags,
    kSkipDraw_OptFlag                 = GrXferProcessor::kSkipDraw_OptFlag,
    kIgnoreColor_OptFlag              = GrXferProcessor::kIgnoreColor_OptFlag,
    kIgnoreCoverage_OptFlag           = GrXferProcessor::kIgnoreCoverage_OptFlag,
>>>>>>> miniblink49
    kCanTweakAlphaForCoverage_OptFlag = GrXferProcessor::kCanTweakAlphaForCoverage_OptFlag
};

class GrPorterDuffTest {
public:
    struct XPInfo {
        XPInfo(skiatest::Reporter* reporter, SkXfermode::Mode xfermode, const GrCaps& caps,
<<<<<<< HEAD
            const GrPipelineOptimizations& optimizations)
        {
            sk_sp<GrXPFactory> xpf(GrPorterDuffXPFactory::Make(xfermode));
            SkAutoTUnref<GrXferProcessor> xp(
                xpf->createXferProcessor(optimizations, false, nullptr, caps));
            TEST_ASSERT(!xpf->willNeedDstTexture(caps, optimizations));
            xpf->getInvariantBlendedColor(optimizations.fColorPOI, &fBlendedColor);
            fOptFlags = xp->getOptimizations(optimizations, false, nullptr, caps);
=======
               const GrProcOptInfo& colorPOI, const GrProcOptInfo& covPOI) {
            SkAutoTUnref<GrXPFactory> xpf(GrPorterDuffXPFactory::Create(xfermode));
            SkAutoTUnref<GrXferProcessor> xp(
                xpf->createXferProcessor(colorPOI, covPOI, false, NULL, caps));
            TEST_ASSERT(!xpf->willNeedDstTexture(caps, colorPOI, covPOI, false));
            xpf->getInvariantBlendedColor(colorPOI, &fBlendedColor);
            fOptFlags = xp->getOptimizations(colorPOI, covPOI, false, NULL, caps);
>>>>>>> miniblink49
            GetXPOutputTypes(xp, &fPrimaryOutputType, &fSecondaryOutputType);
            xp->getBlendInfo(&fBlendInfo);
            TEST_ASSERT(!xp->willReadDstColor());
            TEST_ASSERT(xp->hasSecondaryOutput() == GrBlendCoeffRefsSrc2(fBlendInfo.fDstBlend));
        }

        GrXPFactory::InvariantBlendedColor fBlendedColor;
        int fOptFlags;
        int fPrimaryOutputType;
        int fSecondaryOutputType;
        GrXferProcessor::BlendInfo fBlendInfo;
    };

<<<<<<< HEAD
    static void GetXPOutputTypes(const GrXferProcessor* xp, int* outPrimary, int* outSecondary)
    {
=======
    static void GetXPOutputTypes(const GrXferProcessor* xp, int* outPrimary, int* outSecondary) {
>>>>>>> miniblink49
        GrPorterDuffXPFactory::TestGetXPOutputTypes(xp, outPrimary, outSecondary);
    }
};

<<<<<<< HEAD
static void test_lcd_coverage(skiatest::Reporter* reporter, const GrCaps& caps)
{
    GrPipelineOptimizations opt;
    opt.fColorPOI.calcWithInitialValues(NULL, 0, 0, kNone_GrColorComponentFlags, false);
    // Setting 2nd to last value to false and last to true will force covPOI to LCD coverage.
    opt.fCoveragePOI.calcWithInitialValues(NULL, 0, 0, kNone_GrColorComponentFlags, false, true);

    SkASSERT(!opt.fColorPOI.isOpaque());
    SkASSERT(!opt.fColorPOI.isSolidWhite());
    SkASSERT(!opt.fCoveragePOI.isSolidWhite());
    SkASSERT(opt.fCoveragePOI.isFourChannelOutput());

    for (int m = 0; m <= SkXfermode::kLastCoeffMode; m++) {
        SkXfermode::Mode xfermode = static_cast<SkXfermode::Mode>(m);
        const GrPorterDuffTest::XPInfo xpi(reporter, xfermode, caps, opt);

        switch (xfermode) {
        case SkXfermode::kClear_Mode:
            TEST_ASSERT(!xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(0 == xpi.fBlendedColor.fKnownColor);
            TEST_ASSERT(kRGBA_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kIgnoreColor_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kCoverage_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kReverseSubtract_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kDC_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kSrc_Mode:
            TEST_ASSERT(!xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kNone_OptFlags) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kCoverage_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kIS2C_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kDst_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kSkipDraw_OptFlag | kIgnoreColor_OptFlag | kIgnoreCoverage_OptFlag | kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kNone_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(!xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kSrcOver_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kNone_OptFlags) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kSAModulate_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kIS2C_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kDstOver_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kNone_OptFlags) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kIDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kSrcIn_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kNone_OptFlags) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kCoverage_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kIS2C_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kDstIn_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kNone_OptFlags) == xpi.fOptFlags);
            TEST_ASSERT(kISAModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kReverseSubtract_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kDC_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kSrcOut_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kNone_OptFlags) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kCoverage_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kIDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kIS2C_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kDstOut_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kNone_OptFlags) == xpi.fOptFlags);
            TEST_ASSERT(kSAModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kISC_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kSrcATop_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kNone_OptFlags) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kSAModulate_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kIS2C_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kDstATop_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kNone_OptFlags) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kISAModulate_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kIDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kIS2C_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kXor_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kNone_OptFlags) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kSAModulate_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kIDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kIS2C_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kPlus_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kNone_OptFlags) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kModulate_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kNone_OptFlags) == xpi.fOptFlags);
            TEST_ASSERT(kISCModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kReverseSubtract_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kDC_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kScreen_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kNone_OptFlags) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kISC_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        default:
            ERRORF(reporter, "Invalid xfermode.");
            break;
        }
    }
}
static void test_color_unknown_with_coverage(skiatest::Reporter* reporter, const GrCaps& caps)
{
    GrPipelineOptimizations optimizations;
    optimizations.fColorPOI.calcWithInitialValues(nullptr, 0, 0, kNone_GrColorComponentFlags,
        false);
    optimizations.fCoveragePOI.calcWithInitialValues(nullptr, 0, 0, kNone_GrColorComponentFlags,
        true);

    SkASSERT(!optimizations.fColorPOI.isOpaque());
    SkASSERT(!optimizations.fColorPOI.isSolidWhite());
    SkASSERT(!optimizations.fCoveragePOI.isSolidWhite());
    SkASSERT(!optimizations.fCoveragePOI.isFourChannelOutput());

    for (int m = 0; m <= SkXfermode::kLastCoeffMode; m++) {
        SkXfermode::Mode xfermode = static_cast<SkXfermode::Mode>(m);
        const GrPorterDuffTest::XPInfo xpi(reporter, xfermode, caps, optimizations);

        switch (xfermode) {
        case SkXfermode::kClear_Mode:
            TEST_ASSERT(!xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(0 == xpi.fBlendedColor.fKnownColor);
            TEST_ASSERT(kRGBA_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kIgnoreColor_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kCoverage_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kReverseSubtract_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kDC_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kSrc_Mode:
            TEST_ASSERT(!xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kNone_OptFlags) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kCoverage_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kIS2A_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kDst_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kSkipDraw_OptFlag | kIgnoreColor_OptFlag | kIgnoreCoverage_OptFlag | kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kNone_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(!xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kSrcOver_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kISA_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kDstOver_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kIDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kSrcIn_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kNone_OptFlags) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kCoverage_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kIS2A_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kDstIn_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kNone_OptFlags) == xpi.fOptFlags);
            TEST_ASSERT(kISAModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kReverseSubtract_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kDC_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kSrcOut_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kNone_OptFlags) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kCoverage_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kIDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kIS2A_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kDstOut_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kISA_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kSrcATop_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kISA_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kDstATop_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kNone_OptFlags) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kISAModulate_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kIDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kIS2C_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kXor_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kIDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kISA_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kPlus_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kModulate_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kNone_OptFlags) == xpi.fOptFlags);
            TEST_ASSERT(kISCModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kReverseSubtract_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kDC_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kScreen_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kISC_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        default:
            ERRORF(reporter, "Invalid xfermode.");
            break;
=======
static void test_color_unknown_with_coverage(skiatest::Reporter* reporter, const GrCaps& caps) {
    GrProcOptInfo colorPOI, covPOI;
    colorPOI.calcWithInitialValues(NULL, 0, 0, kNone_GrColorComponentFlags, false);
    covPOI.calcWithInitialValues(NULL, 0, 0, kNone_GrColorComponentFlags, true);

    SkASSERT(!colorPOI.isOpaque());
    SkASSERT(!colorPOI.isSolidWhite());
    SkASSERT(!covPOI.isSolidWhite());
    SkASSERT(!covPOI.isFourChannelOutput());

    for (int m = 0; m <= SkXfermode::kLastCoeffMode; m++) {
        SkXfermode::Mode xfermode = static_cast<SkXfermode::Mode>(m);
        const GrPorterDuffTest::XPInfo xpi(reporter, xfermode, caps, colorPOI, covPOI);

        switch (xfermode) {
            case SkXfermode::kClear_Mode:
                TEST_ASSERT(!xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(0 == xpi.fBlendedColor.fKnownColor);
                TEST_ASSERT(kRGBA_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kIgnoreColor_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kCoverage_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kReverseSubtract_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kDC_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kSrc_Mode:
                TEST_ASSERT(!xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kNone_OptFlags) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kCoverage_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kIS2A_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kDst_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kSkipDraw_OptFlag |
                             kIgnoreColor_OptFlag |
                             kIgnoreCoverage_OptFlag |
                             kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kNone_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(!xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kSrcOver_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kISA_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kDstOver_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kIDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kSrcIn_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kNone_OptFlags) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kCoverage_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kIS2A_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kDstIn_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kNone_OptFlags) == xpi.fOptFlags);
                TEST_ASSERT(kISAModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kReverseSubtract_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kDC_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kSrcOut_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kNone_OptFlags) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kCoverage_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kIDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kIS2A_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kDstOut_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kISA_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kSrcATop_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kISA_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kDstATop_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kNone_OptFlags) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kISAModulate_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kIDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kIS2C_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kXor_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kIDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kISA_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kPlus_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kModulate_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kNone_OptFlags) == xpi.fOptFlags);
                TEST_ASSERT(kISCModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kReverseSubtract_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kDC_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kScreen_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kISC_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            default:
                ERRORF(reporter, "Invalid xfermode.");
                break;
>>>>>>> miniblink49
        }
    }
}

<<<<<<< HEAD
static void test_color_unknown_no_coverage(skiatest::Reporter* reporter, const GrCaps& caps)
{
    GrPipelineOptimizations optimizations;
    optimizations.fColorPOI.calcWithInitialValues(nullptr, 0, GrColorPackRGBA(229, 0, 154, 0),
        kR_GrColorComponentFlag | kB_GrColorComponentFlag, false);
    optimizations.fCoveragePOI.calcWithInitialValues(nullptr, 0, GrColorPackA4(255),
        kRGBA_GrColorComponentFlags, true);

    SkASSERT(!optimizations.fColorPOI.isOpaque());
    SkASSERT(!optimizations.fColorPOI.isSolidWhite());
    SkASSERT(optimizations.fCoveragePOI.isSolidWhite());
    SkASSERT(!optimizations.fCoveragePOI.isFourChannelOutput());

    for (int m = 0; m <= SkXfermode::kLastCoeffMode; m++) {
        SkXfermode::Mode xfermode = static_cast<SkXfermode::Mode>(m);
        const GrPorterDuffTest::XPInfo xpi(reporter, xfermode, caps, optimizations);

        switch (xfermode) {
        case SkXfermode::kClear_Mode:
            TEST_ASSERT(!xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(0 == xpi.fBlendedColor.fKnownColor);
            TEST_ASSERT(kRGBA_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kIgnoreColor_OptFlag | kIgnoreCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kNone_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kSrc_Mode:
            TEST_ASSERT(!xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(229 == GrColorUnpackR(xpi.fBlendedColor.fKnownColor));
            TEST_ASSERT(154 == GrColorUnpackB(xpi.fBlendedColor.fKnownColor));
            TEST_ASSERT((kR_GrColorComponentFlag | kB_GrColorComponentFlag) == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kIgnoreCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kDst_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kSkipDraw_OptFlag | kIgnoreColor_OptFlag | kIgnoreCoverage_OptFlag | kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kNone_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(!xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kSrcOver_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kIgnoreCoverage_OptFlag | kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kISA_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kDstOver_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kIgnoreCoverage_OptFlag | kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kIDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kSrcIn_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kIgnoreCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kDstIn_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kIgnoreCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kSA_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kSrcOut_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kIgnoreCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kIDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kDstOut_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kIgnoreCoverage_OptFlag | kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kISA_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kSrcATop_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kIgnoreCoverage_OptFlag | kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kISA_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kDstATop_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kIgnoreCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kIDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kSA_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kXor_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kIgnoreCoverage_OptFlag | kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kIDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kISA_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kPlus_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kIgnoreCoverage_OptFlag | kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kModulate_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kIgnoreCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kSC_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kScreen_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kIgnoreCoverage_OptFlag | kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kISC_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        default:
            ERRORF(reporter, "Invalid xfermode.");
            break;
=======
static void test_color_unknown_no_coverage(skiatest::Reporter* reporter, const GrCaps& caps) {
    GrProcOptInfo colorPOI, covPOI;
    colorPOI.calcWithInitialValues(NULL, 0, GrColorPackRGBA(229, 0, 154, 0),
                                   kR_GrColorComponentFlag | kB_GrColorComponentFlag, false);
    covPOI.calcWithInitialValues(NULL, 0, GrColorPackA4(255), kRGBA_GrColorComponentFlags, true);

    SkASSERT(!colorPOI.isOpaque());
    SkASSERT(!colorPOI.isSolidWhite());
    SkASSERT(covPOI.isSolidWhite());
    SkASSERT(!covPOI.isFourChannelOutput());

    for (int m = 0; m <= SkXfermode::kLastCoeffMode; m++) {
        SkXfermode::Mode xfermode = static_cast<SkXfermode::Mode>(m);
        const GrPorterDuffTest::XPInfo xpi(reporter, xfermode, caps, colorPOI, covPOI);

        switch (xfermode) {
            case SkXfermode::kClear_Mode:
                TEST_ASSERT(!xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(0 == xpi.fBlendedColor.fKnownColor);
                TEST_ASSERT(kRGBA_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kIgnoreColor_OptFlag |
                             kIgnoreCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kNone_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kSrc_Mode:
                TEST_ASSERT(!xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(229 == GrColorUnpackR(xpi.fBlendedColor.fKnownColor));
                TEST_ASSERT(154 == GrColorUnpackB(xpi.fBlendedColor.fKnownColor));
                TEST_ASSERT((kR_GrColorComponentFlag |
                             kB_GrColorComponentFlag) == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kIgnoreCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kDst_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kSkipDraw_OptFlag |
                             kIgnoreColor_OptFlag |
                             kIgnoreCoverage_OptFlag |
                             kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kNone_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(!xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kSrcOver_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kIgnoreCoverage_OptFlag |
                             kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kISA_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kDstOver_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kIgnoreCoverage_OptFlag |
                             kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kIDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kSrcIn_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kIgnoreCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kDstIn_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kIgnoreCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kSA_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kSrcOut_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kIgnoreCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kIDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kDstOut_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kIgnoreCoverage_OptFlag |
                             kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kISA_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kSrcATop_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kIgnoreCoverage_OptFlag |
                             kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kISA_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kDstATop_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kIgnoreCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kIDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kSA_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kXor_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kIgnoreCoverage_OptFlag |
                             kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kIDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kISA_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kPlus_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kIgnoreCoverage_OptFlag |
                             kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kModulate_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kIgnoreCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kSC_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kScreen_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kIgnoreCoverage_OptFlag |
                             kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kISC_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            default:
                ERRORF(reporter, "Invalid xfermode.");
                break;
>>>>>>> miniblink49
        }
    }
}

<<<<<<< HEAD
static void test_color_opaque_with_coverage(skiatest::Reporter* reporter, const GrCaps& caps)
{
    GrPipelineOptimizations optimizations;
    optimizations.fColorPOI.calcWithInitialValues(nullptr, 0, GrColorPackA4(255),
        kA_GrColorComponentFlag, false);
    optimizations.fCoveragePOI.calcWithInitialValues(nullptr, 0, 0, kNone_GrColorComponentFlags,
        true);

    SkASSERT(optimizations.fColorPOI.isOpaque());
    SkASSERT(!optimizations.fColorPOI.isSolidWhite());
    SkASSERT(!optimizations.fCoveragePOI.isSolidWhite());
    SkASSERT(!optimizations.fCoveragePOI.isFourChannelOutput());

    for (int m = 0; m <= SkXfermode::kLastCoeffMode; m++) {
        SkXfermode::Mode xfermode = static_cast<SkXfermode::Mode>(m);
        const GrPorterDuffTest::XPInfo xpi(reporter, xfermode, caps, optimizations);

        switch (xfermode) {
        case SkXfermode::kClear_Mode:
            TEST_ASSERT(!xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(0 == xpi.fBlendedColor.fKnownColor);
            TEST_ASSERT(kRGBA_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kIgnoreColor_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kCoverage_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kReverseSubtract_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kDC_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kSrc_Mode:
            TEST_ASSERT(!xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(255 == GrColorUnpackA(xpi.fBlendedColor.fKnownColor));
            TEST_ASSERT(kA_GrColorComponentFlag == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kISA_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kDst_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kSkipDraw_OptFlag | kIgnoreColor_OptFlag | kIgnoreCoverage_OptFlag | kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kNone_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(!xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kSrcOver_Mode:
            TEST_ASSERT(!xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(255 == GrColorUnpackA(xpi.fBlendedColor.fKnownColor));
            TEST_ASSERT(kA_GrColorComponentFlag == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kISA_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kDstOver_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kIDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kSrcIn_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kISA_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kDstIn_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kSkipDraw_OptFlag | kIgnoreColor_OptFlag | kIgnoreCoverage_OptFlag | kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kNone_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(!xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kSrcOut_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kIDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kISA_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kDstOut_Mode:
            TEST_ASSERT(!xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(0 == xpi.fBlendedColor.fKnownColor);
            TEST_ASSERT(kRGBA_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kIgnoreColor_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kCoverage_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kReverseSubtract_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kDC_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kSrcATop_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kISA_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kDstATop_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kIDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kXor_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kIDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kISA_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kPlus_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kModulate_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kNone_OptFlags) == xpi.fOptFlags);
            TEST_ASSERT(kISCModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kReverseSubtract_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kDC_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kScreen_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kISC_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        default:
            ERRORF(reporter, "Invalid xfermode.");
            break;
=======
static void test_color_opaque_with_coverage(skiatest::Reporter* reporter, const GrCaps& caps) {
    GrProcOptInfo colorPOI, covPOI;
    colorPOI.calcWithInitialValues(NULL, 0, GrColorPackA4(255), kA_GrColorComponentFlag, false);
    covPOI.calcWithInitialValues(NULL, 0, 0, kNone_GrColorComponentFlags, true);

    SkASSERT(colorPOI.isOpaque());
    SkASSERT(!colorPOI.isSolidWhite());
    SkASSERT(!covPOI.isSolidWhite());
    SkASSERT(!covPOI.isFourChannelOutput());

    for (int m = 0; m <= SkXfermode::kLastCoeffMode; m++) {
        SkXfermode::Mode xfermode = static_cast<SkXfermode::Mode>(m);
        const GrPorterDuffTest::XPInfo xpi(reporter, xfermode, caps, colorPOI, covPOI);

        switch (xfermode) {
            case SkXfermode::kClear_Mode:
                TEST_ASSERT(!xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(0 == xpi.fBlendedColor.fKnownColor);
                TEST_ASSERT(kRGBA_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kIgnoreColor_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kCoverage_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kReverseSubtract_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kDC_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kSrc_Mode:
                TEST_ASSERT(!xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(255 == GrColorUnpackA(xpi.fBlendedColor.fKnownColor));
                TEST_ASSERT(kA_GrColorComponentFlag == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kISA_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kDst_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kSkipDraw_OptFlag |
                             kIgnoreColor_OptFlag |
                             kIgnoreCoverage_OptFlag |
                             kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kNone_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(!xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kSrcOver_Mode:
                TEST_ASSERT(!xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(255 == GrColorUnpackA(xpi.fBlendedColor.fKnownColor));
                TEST_ASSERT(kA_GrColorComponentFlag == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kISA_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kDstOver_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kIDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kSrcIn_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kISA_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kDstIn_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kSkipDraw_OptFlag |
                             kIgnoreColor_OptFlag |
                             kIgnoreCoverage_OptFlag |
                             kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kNone_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(!xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kSrcOut_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kIDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kISA_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kDstOut_Mode:
                TEST_ASSERT(!xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(0 == xpi.fBlendedColor.fKnownColor);
                TEST_ASSERT(kRGBA_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kIgnoreColor_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kCoverage_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kReverseSubtract_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kDC_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kSrcATop_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kISA_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kDstATop_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kIDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kXor_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kIDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kISA_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kPlus_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kModulate_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kNone_OptFlags) == xpi.fOptFlags);
                TEST_ASSERT(kISCModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kReverseSubtract_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kDC_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kScreen_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kISC_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            default:
                ERRORF(reporter, "Invalid xfermode.");
                break;
>>>>>>> miniblink49
        }
    }
}

<<<<<<< HEAD
static void test_color_opaque_no_coverage(skiatest::Reporter* reporter, const GrCaps& caps)
{
    GrPipelineOptimizations optimizations;
    optimizations.fColorPOI.calcWithInitialValues(nullptr, 0, GrColorPackRGBA(0, 82, 0, 255),
        kG_GrColorComponentFlag | kA_GrColorComponentFlag, false);
    optimizations.fCoveragePOI.calcWithInitialValues(nullptr, 0, GrColorPackA4(255),
        kRGBA_GrColorComponentFlags, true);

    SkASSERT(optimizations.fColorPOI.isOpaque());
    SkASSERT(!optimizations.fColorPOI.isSolidWhite());
    SkASSERT(optimizations.fCoveragePOI.isSolidWhite());
    SkASSERT(!optimizations.fCoveragePOI.isFourChannelOutput());

    for (int m = 0; m <= SkXfermode::kLastCoeffMode; m++) {
        SkXfermode::Mode xfermode = static_cast<SkXfermode::Mode>(m);
        const GrPorterDuffTest::XPInfo xpi(reporter, xfermode, caps, optimizations);

        switch (xfermode) {
        case SkXfermode::kClear_Mode:
            TEST_ASSERT(!xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(0 == xpi.fBlendedColor.fKnownColor);
            TEST_ASSERT(kRGBA_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kIgnoreColor_OptFlag | kIgnoreCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kNone_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kSrc_Mode:
            TEST_ASSERT(!xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(82 == GrColorUnpackG(xpi.fBlendedColor.fKnownColor));
            TEST_ASSERT(255 == GrColorUnpackA(xpi.fBlendedColor.fKnownColor));
            TEST_ASSERT((kG_GrColorComponentFlag | kA_GrColorComponentFlag) == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kIgnoreCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kDst_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kSkipDraw_OptFlag | kIgnoreColor_OptFlag | kIgnoreCoverage_OptFlag | kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kNone_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(!xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kSrcOver_Mode:
            TEST_ASSERT(!xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(82 == GrColorUnpackG(xpi.fBlendedColor.fKnownColor));
            TEST_ASSERT(255 == GrColorUnpackA(xpi.fBlendedColor.fKnownColor));
            TEST_ASSERT((kG_GrColorComponentFlag | kA_GrColorComponentFlag) == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kIgnoreCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kDstOver_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kIgnoreCoverage_OptFlag | kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kIDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kSrcIn_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kIgnoreCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kDstIn_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kSkipDraw_OptFlag | kIgnoreColor_OptFlag | kIgnoreCoverage_OptFlag | kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kNone_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(!xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kSrcOut_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kIgnoreCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kIDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kDstOut_Mode:
            TEST_ASSERT(!xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(0 == xpi.fBlendedColor.fKnownColor);
            TEST_ASSERT(kRGBA_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kIgnoreColor_OptFlag | kIgnoreCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kNone_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kSrcATop_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kIgnoreCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kDstATop_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kIgnoreCoverage_OptFlag | kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kIDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kXor_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kIgnoreCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kIDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kPlus_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kIgnoreCoverage_OptFlag | kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kModulate_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kIgnoreCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kSC_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        case SkXfermode::kScreen_Mode:
            TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
            TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
            TEST_ASSERT((kIgnoreCoverage_OptFlag | kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
            TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
            TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
            TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
            TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
            TEST_ASSERT(kISC_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
            TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
            break;
        default:
            ERRORF(reporter, "Invalid xfermode.");
            break;
=======
static void test_color_opaque_no_coverage(skiatest::Reporter* reporter, const GrCaps& caps) {
    GrProcOptInfo colorPOI, covPOI;
    colorPOI.calcWithInitialValues(NULL, 0, GrColorPackRGBA(0, 82, 0, 255),
                                   kG_GrColorComponentFlag | kA_GrColorComponentFlag, false);
    covPOI.calcWithInitialValues(NULL, 0, GrColorPackA4(255), kRGBA_GrColorComponentFlags, true);

    SkASSERT(colorPOI.isOpaque());
    SkASSERT(!colorPOI.isSolidWhite());
    SkASSERT(covPOI.isSolidWhite());
    SkASSERT(!covPOI.isFourChannelOutput());

    for (int m = 0; m <= SkXfermode::kLastCoeffMode; m++) {
        SkXfermode::Mode xfermode = static_cast<SkXfermode::Mode>(m);
        const GrPorterDuffTest::XPInfo xpi(reporter, xfermode, caps, colorPOI, covPOI);

        switch (xfermode) {
            case SkXfermode::kClear_Mode:
                TEST_ASSERT(!xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(0 == xpi.fBlendedColor.fKnownColor);
                TEST_ASSERT(kRGBA_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kIgnoreColor_OptFlag |
                             kIgnoreCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kNone_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kSrc_Mode:
                TEST_ASSERT(!xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(82 == GrColorUnpackG(xpi.fBlendedColor.fKnownColor));
                TEST_ASSERT(255 == GrColorUnpackA(xpi.fBlendedColor.fKnownColor));
                TEST_ASSERT((kG_GrColorComponentFlag |
                             kA_GrColorComponentFlag) == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kIgnoreCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kDst_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kSkipDraw_OptFlag |
                             kIgnoreColor_OptFlag |
                             kIgnoreCoverage_OptFlag |
                             kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kNone_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(!xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kSrcOver_Mode:
                TEST_ASSERT(!xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(82 == GrColorUnpackG(xpi.fBlendedColor.fKnownColor));
                TEST_ASSERT(255 == GrColorUnpackA(xpi.fBlendedColor.fKnownColor));
                TEST_ASSERT((kG_GrColorComponentFlag |
                             kA_GrColorComponentFlag) == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kIgnoreCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kDstOver_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kIgnoreCoverage_OptFlag |
                             kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kIDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kSrcIn_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kIgnoreCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kDstIn_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kSkipDraw_OptFlag |
                             kIgnoreColor_OptFlag |
                             kIgnoreCoverage_OptFlag |
                             kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kNone_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(!xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kSrcOut_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kIgnoreCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kIDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kDstOut_Mode:
                TEST_ASSERT(!xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(0 == xpi.fBlendedColor.fKnownColor);
                TEST_ASSERT(kRGBA_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kIgnoreColor_OptFlag |
                             kIgnoreCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kNone_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kSrcATop_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kIgnoreCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kDstATop_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kIgnoreCoverage_OptFlag |
                             kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kIDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kXor_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kIgnoreCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kIDA_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kPlus_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kIgnoreCoverage_OptFlag |
                             kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kModulate_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kIgnoreCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kZero_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kSC_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            case SkXfermode::kScreen_Mode:
                TEST_ASSERT(xpi.fBlendedColor.fWillBlendWithDst);
                TEST_ASSERT(kNone_GrColorComponentFlags == xpi.fBlendedColor.fKnownColorFlags);
                TEST_ASSERT((kIgnoreCoverage_OptFlag |
                             kCanTweakAlphaForCoverage_OptFlag) == xpi.fOptFlags);
                TEST_ASSERT(kModulate_OutputType == xpi.fPrimaryOutputType);
                TEST_ASSERT(kNone_OutputType == xpi.fSecondaryOutputType);
                TEST_ASSERT(kAdd_GrBlendEquation == xpi.fBlendInfo.fEquation);
                TEST_ASSERT(kOne_GrBlendCoeff == xpi.fBlendInfo.fSrcBlend);
                TEST_ASSERT(kISC_GrBlendCoeff == xpi.fBlendInfo.fDstBlend);
                TEST_ASSERT(xpi.fBlendInfo.fWriteColor);
                break;
            default:
                ERRORF(reporter, "Invalid xfermode.");
                break;
>>>>>>> miniblink49
        }
    }
}

<<<<<<< HEAD
static void test_lcd_coverage_fallback_case(skiatest::Reporter* reporter, const GrCaps& caps)
{
    class TestLCDCoverageBatch : public GrVertexBatch {
    public:
        DEFINE_BATCH_CLASS_ID

        TestLCDCoverageBatch()
            : INHERITED(ClassID())
        {
        }

    private:
        void computePipelineOptimizations(GrInitInvariantOutput* color,
            GrInitInvariantOutput* coverage,
            GrBatchToXPOverrides* overrides) const override
        {
            color->setKnownFourComponents(GrColorPackRGBA(123, 45, 67, 221));
            coverage->setUnknownFourComponents();
            coverage->setUsingLCDCoverage();
        }

        const char* name() const override { return "Test LCD Text Batch"; }
        void initBatchTracker(const GrXPOverridesForBatch&) override { }
        bool onCombineIfPossible(GrBatch*, const GrCaps&) override { return false; }
        void onPrepareDraws(Target*) const override {};

        typedef GrVertexBatch INHERITED;
    } testLCDCoverageBatch;

    GrPipelineOptimizations opts;
    testLCDCoverageBatch.getPipelineOptimizations(&opts);
    GrProcOptInfo colorPOI = opts.fColorPOI;
    GrProcOptInfo covPOI = opts.fCoveragePOI;
=======
static void test_lcd_coverage(skiatest::Reporter* reporter, const GrCaps& caps) {
    class : public GrBatch {
        void getInvariantOutputColor(GrInitInvariantOutput* out) const override {
            out->setKnownFourComponents(GrColorPackRGBA(123, 45, 67, 221));
        }

        void getInvariantOutputCoverage(GrInitInvariantOutput* out) const override {
            out->setUnknownFourComponents();
            out->setUsingLCDCoverage();
        }

        const char* name() const override { return "Test LCD Text Batch"; }
        void initBatchTracker(const GrPipelineInfo&) override {}
        bool onCombineIfPossible(GrBatch*) override  { return false; }
        void generateGeometry(GrBatchTarget*, const GrPipeline*) override {}

    } testLCDCoverageBatch;

    GrProcOptInfo colorPOI, covPOI;
    colorPOI.calcColorWithBatch(&testLCDCoverageBatch, NULL, 0);
    covPOI.calcCoverageWithBatch(&testLCDCoverageBatch, NULL, 0);
>>>>>>> miniblink49

    SkASSERT(kRGBA_GrColorComponentFlags == colorPOI.validFlags());
    SkASSERT(covPOI.isFourChannelOutput());

<<<<<<< HEAD
    sk_sp<GrXPFactory> xpf(GrPorterDuffXPFactory::Make(SkXfermode::kSrcOver_Mode));
    TEST_ASSERT(!xpf->willNeedDstTexture(caps, opts));

    SkAutoTUnref<GrXferProcessor> xp(
        xpf->createXferProcessor(opts, false, nullptr, caps));
=======
    SkAutoTUnref<GrXPFactory> xpf(GrPorterDuffXPFactory::Create(SkXfermode::kSrcOver_Mode));
    TEST_ASSERT(!xpf->willNeedDstTexture(caps, colorPOI, covPOI, false));

    SkAutoTUnref<GrXferProcessor> xp(
        xpf->createXferProcessor(colorPOI, covPOI, false, NULL, caps));
>>>>>>> miniblink49
    if (!xp) {
        ERRORF(reporter, "Failed to create an XP with LCD coverage.");
        return;
    }

    GrXPFactory::InvariantBlendedColor blendedColor;
    xpf->getInvariantBlendedColor(colorPOI, &blendedColor);
    TEST_ASSERT(blendedColor.fWillBlendWithDst);
    TEST_ASSERT(kNone_GrColorComponentFlags == blendedColor.fKnownColorFlags);

    GrColor overrideColor;
<<<<<<< HEAD
    xp->getOptimizations(opts, false, &overrideColor, caps);
=======
    xp->getOptimizations(colorPOI, covPOI, false, &overrideColor, caps);
>>>>>>> miniblink49

    GrXferProcessor::BlendInfo blendInfo;
    xp->getBlendInfo(&blendInfo);
    TEST_ASSERT(blendInfo.fWriteColor);
}

<<<<<<< HEAD
DEF_GPUTEST(PorterDuffNoDualSourceBlending, reporter, /*factory*/)
{
    GrContextOptions opts;
    opts.fSuppressDualSourceBlending = true;
    sk_gpu_test::GrContextFactory mockFactory(opts);
    GrContext* ctx = mockFactory.get(sk_gpu_test::GrContextFactory::kNullGL_ContextType);
=======
static void test_no_dual_source_blending(skiatest::Reporter* reporter) {
    GrContextOptions opts;
    opts.fSuppressDualSourceBlending = true;
    GrContextFactory factory(opts);
    factory.get(GrContextFactory::kNull_GLContextType);
    GrContext* ctx = factory.get(GrContextFactory::kNull_GLContextType);
>>>>>>> miniblink49
    if (!ctx) {
        SkFAIL("Failed to create null context without ARB_blend_func_extended.");
        return;
    }

    const GrCaps& caps = *ctx->caps();
    if (caps.shaderCaps()->dualSourceBlendingSupport()) {
        SkFAIL("Null context failed to honor request for no ARB_blend_func_extended.");
        return;
    }

<<<<<<< HEAD
    GrBackendObject backendTex = ctx->getGpu()->createTestingOnlyBackendTexture(nullptr, 100, 100,
        kRGBA_8888_GrPixelConfig);
    GrBackendTextureDesc fakeDesc;
    fakeDesc.fConfig = kRGBA_8888_GrPixelConfig;
    fakeDesc.fWidth = fakeDesc.fHeight = 100;
    fakeDesc.fTextureHandle = backendTex;
    SkAutoTUnref<GrTexture> fakeTexture(ctx->textureProvider()->wrapBackendTexture(fakeDesc,
=======
    GrBackendTextureDesc fakeDesc;
    fakeDesc.fConfig = kRGBA_8888_GrPixelConfig;
    fakeDesc.fWidth = fakeDesc.fHeight = 100;
    fakeDesc.fTextureHandle = 1;
    SkAutoTUnref<GrTexture> fakeTexture(ctx->resourceProvider()->wrapBackendTexture(fakeDesc,
>>>>>>> miniblink49
        kBorrow_GrWrapOwnership));
    GrXferProcessor::DstTexture fakeDstTexture;
    fakeDstTexture.setTexture(fakeTexture);

    static const GrColor testColors[] = {
        0,
        GrColorPackRGBA(0, 82, 0, 255),
        GrColorPackA4(255)
    };
    static const GrColorComponentFlags testColorFlags[] = {
        kNone_GrColorComponentFlags,
        kG_GrColorComponentFlag | kA_GrColorComponentFlag,
        kRGBA_GrColorComponentFlags
    };
    GR_STATIC_ASSERT(SK_ARRAY_COUNT(testColors) == SK_ARRAY_COUNT(testColorFlags));

    for (size_t c = 0; c < SK_ARRAY_COUNT(testColors); c++) {
<<<<<<< HEAD
        GrPipelineOptimizations optimizations;
        optimizations.fColorPOI.calcWithInitialValues(nullptr, 0, testColors[c], testColorFlags[c],
            false);
        for (int f = 0; f <= 1; f++) {
            if (!f) {
                optimizations.fCoveragePOI.calcWithInitialValues(nullptr, 0, 0,
                    kNone_GrColorComponentFlags, true);
            } else {
                optimizations.fCoveragePOI.calcWithInitialValues(nullptr, 0, GrColorPackA4(255),
                    kRGBA_GrColorComponentFlags, true);
            }
            for (int m = 0; m <= SkXfermode::kLastCoeffMode; m++) {
                SkXfermode::Mode xfermode = static_cast<SkXfermode::Mode>(m);
                sk_sp<GrXPFactory> xpf(GrPorterDuffXPFactory::Make(xfermode));
                GrXferProcessor::DstTexture* dstTexture = xpf->willNeedDstTexture(caps, optimizations) ? &fakeDstTexture : 0;
                SkAutoTUnref<GrXferProcessor> xp(
                    xpf->createXferProcessor(optimizations, false, dstTexture, caps));
=======
        GrProcOptInfo colorPOI;
        colorPOI.calcWithInitialValues(NULL, 0, testColors[c], testColorFlags[c], false);
        for (int f = 0; f <= 1; f++) {
            GrProcOptInfo covPOI;
            if (!f) {
                covPOI.calcWithInitialValues(NULL, 0, 0, kNone_GrColorComponentFlags, true);
            } else {
                covPOI.calcWithInitialValues(NULL, 0, GrColorPackA4(255),
                                             kRGBA_GrColorComponentFlags, true);
            }
            for (int m = 0; m <= SkXfermode::kLastCoeffMode; m++) {
                SkXfermode::Mode xfermode = static_cast<SkXfermode::Mode>(m);
                SkAutoTUnref<GrXPFactory> xpf(GrPorterDuffXPFactory::Create(xfermode));
                GrXferProcessor::DstTexture* dstTexture =
                    xpf->willNeedDstTexture(caps, colorPOI, covPOI, false) ? &fakeDstTexture : 0;
                SkAutoTUnref<GrXferProcessor> xp(
                    xpf->createXferProcessor(colorPOI, covPOI, false, dstTexture, caps));
>>>>>>> miniblink49
                if (!xp) {
                    ERRORF(reporter, "Failed to create an XP without dual source blending.");
                    return;
                }
                TEST_ASSERT(!xp->hasSecondaryOutput());
<<<<<<< HEAD
                xp->getOptimizations(optimizations, false, 0, caps);
=======
                xp->getOptimizations(colorPOI, covPOI, false, 0, caps);
>>>>>>> miniblink49
                TEST_ASSERT(!xp->hasSecondaryOutput());
            }
        }
    }
<<<<<<< HEAD
    ctx->getGpu()->deleteTestingOnlyBackendTexture(backendTex);
}

#endif
=======
}

#endif

>>>>>>> miniblink49
