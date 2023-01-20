/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "GrPathRendering.h"
<<<<<<< HEAD
#include "GrPathRange.h"
=======
>>>>>>> miniblink49
#include "SkDescriptor.h"
#include "SkGlyph.h"
#include "SkMatrix.h"
#include "SkTypeface.h"
<<<<<<< HEAD

const GrUserStencilSettings& GrPathRendering::GetStencilPassSettings(FillType fill)
{
    switch (fill) {
    default:
        SkFAIL("Unexpected path fill.");
    case GrPathRendering::kWinding_FillType: {
        constexpr static GrUserStencilSettings kWindingStencilPass(
            GrUserStencilSettings::StaticInit<
                0xffff,
                GrUserStencilTest::kAlwaysIfInClip,
                0xffff,
                GrUserStencilOp::kIncWrap,
                GrUserStencilOp::kIncWrap,
                0xffff>());
        return kWindingStencilPass;
    }
    case GrPathRendering::kEvenOdd_FillType: {
        constexpr static GrUserStencilSettings kEvenOddStencilPass(
            GrUserStencilSettings::StaticInit<
                0xffff,
                GrUserStencilTest::kAlwaysIfInClip,
                0xffff,
                GrUserStencilOp::kInvert,
                GrUserStencilOp::kInvert,
                0xffff>());
        return kEvenOddStencilPass;
    }
    }
}

class GlyphGenerator : public GrPathRange::PathGenerator {
public:
    GlyphGenerator(const SkTypeface& typeface, const SkScalerContextEffects& effects,
        const SkDescriptor& desc)
        : fScalerContext(typeface.createScalerContext(effects, &desc))
=======
#include "GrPathRange.h"

class GlyphGenerator : public GrPathRange::PathGenerator {
public:
    GlyphGenerator(const SkTypeface& typeface, const SkDescriptor& desc)
        : fScalerContext(typeface.createScalerContext(&desc))
>>>>>>> miniblink49
#ifdef SK_DEBUG
        , fDesc(desc.copy())
#endif
    {
<<<<<<< HEAD
    }

    virtual ~GlyphGenerator()
    {
=======
        fFlipMatrix.setScale(1, -1);
    }

    virtual ~GlyphGenerator() {
>>>>>>> miniblink49
#ifdef SK_DEBUG
        SkDescriptor::Free(fDesc);
#endif
    }

<<<<<<< HEAD
    int getNumPaths() override
    {
        return fScalerContext->getGlyphCount();
    }

    void generatePath(int glyphID, SkPath* out) override
    {
=======
    int getNumPaths() override {
        return fScalerContext->getGlyphCount();
    }

    void generatePath(int glyphID, SkPath* out) override {
>>>>>>> miniblink49
        SkGlyph skGlyph;
        skGlyph.initWithGlyphID(glyphID);
        fScalerContext->getMetrics(&skGlyph);

        fScalerContext->getPath(skGlyph, out);
<<<<<<< HEAD
    }
#ifdef SK_DEBUG
    bool isEqualTo(const SkDescriptor& desc) const override
    {
        return *fDesc == desc;
=======
        out->transform(fFlipMatrix); // Load glyphs with the inverted y-direction.
    }
#ifdef SK_DEBUG
    bool isEqualTo(const SkDescriptor& desc) const override {
        return fDesc->equals(desc);
>>>>>>> miniblink49
    }
#endif
private:
    const SkAutoTDelete<SkScalerContext> fScalerContext;
<<<<<<< HEAD
=======
    SkMatrix fFlipMatrix;
>>>>>>> miniblink49
#ifdef SK_DEBUG
    SkDescriptor* const fDesc;
#endif
};

GrPathRange* GrPathRendering::createGlyphs(const SkTypeface* typeface,
<<<<<<< HEAD
    const SkScalerContextEffects& effects,
    const SkDescriptor* desc,
    const GrStyle& style)
{
    if (nullptr == typeface) {
        typeface = SkTypeface::GetDefaultTypeface();
        SkASSERT(nullptr != typeface);
    }

    if (desc) {
        SkAutoTUnref<GlyphGenerator> generator(new GlyphGenerator(*typeface, effects, *desc));
        return this->createPathRange(generator, style);
=======
                                           const SkDescriptor* desc,
                                           const GrStrokeInfo& stroke) {
    if (NULL == typeface) {
        typeface = SkTypeface::GetDefaultTypeface();
        SkASSERT(NULL != typeface);
    }

    if (desc) {
        SkAutoTUnref<GlyphGenerator> generator(SkNEW_ARGS(GlyphGenerator, (*typeface, *desc)));
        return this->createPathRange(generator, stroke);
>>>>>>> miniblink49
    }

    SkScalerContextRec rec;
    memset(&rec, 0, sizeof(rec));
    rec.fFontID = typeface->uniqueID();
    rec.fTextSize = SkPaint::kCanonicalTextSizeForPaths;
    rec.fPreScaleX = rec.fPost2x2[0][0] = rec.fPost2x2[1][1] = SK_Scalar1;
    // Don't bake stroke information into the glyphs, we'll let the GPU do the stroking.

    SkAutoDescriptor ad(sizeof(rec) + SkDescriptor::ComputeOverhead(1));
<<<<<<< HEAD
    SkDescriptor* genericDesc = ad.getDesc();
=======
    SkDescriptor*    genericDesc = ad.getDesc();
>>>>>>> miniblink49

    genericDesc->init();
    genericDesc->addEntry(kRec_SkDescriptorTag, sizeof(rec), &rec);
    genericDesc->computeChecksum();

<<<<<<< HEAD
    // No effects, so we make a dummy struct
    SkScalerContextEffects noEffects;

    SkAutoTUnref<GlyphGenerator> generator(new GlyphGenerator(*typeface, noEffects, *genericDesc));
    return this->createPathRange(generator, style);
=======
    SkAutoTUnref<GlyphGenerator> generator(SkNEW_ARGS(GlyphGenerator, (*typeface, *genericDesc)));
    return this->createPathRange(generator, stroke);
>>>>>>> miniblink49
}
