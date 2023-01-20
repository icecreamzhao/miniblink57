/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "GrBitmapTextGeoProc.h"
<<<<<<< HEAD
#include "GrInvariantOutput.h"
#include "GrTexture.h"
#include "glsl/GrGLSLFragmentShaderBuilder.h"
#include "glsl/GrGLSLGeometryProcessor.h"
#include "glsl/GrGLSLProgramDataManager.h"
#include "glsl/GrGLSLUniformHandler.h"
#include "glsl/GrGLSLVarying.h"
#include "glsl/GrGLSLVertexShaderBuilder.h"

class GrGLBitmapTextGeoProc : public GrGLSLGeometryProcessor {
public:
    GrGLBitmapTextGeoProc()
        : fColor(GrColor_ILLEGAL)
    {
    }

    void onEmitCode(EmitArgs& args, GrGPArgs* gpArgs) override
    {
        const GrBitmapTextGeoProc& cte = args.fGP.cast<GrBitmapTextGeoProc>();

        GrGLSLVertexBuilder* vertBuilder = args.fVertBuilder;
        GrGLSLVaryingHandler* varyingHandler = args.fVaryingHandler;
        GrGLSLUniformHandler* uniformHandler = args.fUniformHandler;

        // emit attributes
        varyingHandler->emitAttributes(cte);

        // compute numbers to be hardcoded to convert texture coordinates from int to float
        SkASSERT(cte.numTextures() == 1);
        SkDEBUGCODE(GrTexture* atlas = cte.textureAccess(0).getTexture());
        SkASSERT(atlas && SkIsPow2(atlas->width()) && SkIsPow2(atlas->height()));

        GrGLSLVertToFrag v(kVec2f_GrSLType);
        varyingHandler->addVarying("TextureCoords", &v, kHigh_GrSLPrecision);
        vertBuilder->codeAppendf("%s = %s;", v.vsOut(),
            cte.inTextureCoords()->fName);

        GrGLSLPPFragmentBuilder* fragBuilder = args.fFragBuilder;
        // Setup pass through color
        if (!cte.colorIgnored()) {
            if (cte.hasVertexColor()) {
                varyingHandler->addPassThroughAttribute(cte.inColor(), args.fOutputColor);
            } else {
                this->setupUniformColor(fragBuilder, uniformHandler, args.fOutputColor,
                    &fColorUniform);
=======
#include "GrFontAtlasSizes.h"
#include "GrInvariantOutput.h"
#include "GrTexture.h"
#include "gl/GrGLProcessor.h"
#include "gl/GrGLTexture.h"
#include "gl/GrGLGeometryProcessor.h"
#include "gl/builders/GrGLProgramBuilder.h"

class GrGLBitmapTextGeoProc : public GrGLGeometryProcessor {
public:
    GrGLBitmapTextGeoProc(const GrGeometryProcessor&, const GrBatchTracker&)
        : fColor(GrColor_ILLEGAL) {}

    void onEmitCode(EmitArgs& args, GrGPArgs* gpArgs) override{
        const GrBitmapTextGeoProc& cte = args.fGP.cast<GrBitmapTextGeoProc>();

        GrGLGPBuilder* pb = args.fPB;
        GrGLVertexBuilder* vsBuilder = pb->getVertexShaderBuilder();

        // emit attributes
        vsBuilder->emitAttributes(cte);

        GrGLVertToFrag v(kVec2f_GrSLType);
        pb->addVarying("TextureCoords", &v);
        // this is only used with text, so our texture bounds always match the glyph atlas
        if (cte.maskFormat() == kA8_GrMaskFormat) {
            vsBuilder->codeAppendf("%s = vec2(" GR_FONT_ATLAS_A8_RECIP_WIDTH ", "
                                   GR_FONT_ATLAS_RECIP_HEIGHT ")*%s;", v.vsOut(),
                                   cte.inTextureCoords()->fName);
        } else {
            vsBuilder->codeAppendf("%s = vec2(" GR_FONT_ATLAS_RECIP_WIDTH ", "
                                   GR_FONT_ATLAS_RECIP_HEIGHT ")*%s;", v.vsOut(),
                                   cte.inTextureCoords()->fName);
        }

        // Setup pass through color
        if (!cte.colorIgnored()) {
            if (cte.hasVertexColor()) {
                pb->addPassThroughAttribute(cte.inColor(), args.fOutputColor);
            } else {
                this->setupUniformColor(pb, args.fOutputColor, &fColorUniform);
>>>>>>> miniblink49
            }
        }

        // Setup position
<<<<<<< HEAD
        this->setupPosition(vertBuilder, gpArgs, cte.inPosition()->fName);

        // emit transforms
        this->emitTransforms(vertBuilder,
            varyingHandler,
            uniformHandler,
            gpArgs->fPositionVar,
            cte.inPosition()->fName,
            cte.localMatrix(),
            args.fTransformsIn,
            args.fTransformsOut);

        if (cte.maskFormat() == kARGB_GrMaskFormat) {
            fragBuilder->codeAppendf("%s = ", args.fOutputColor);
            fragBuilder->appendTextureLookupAndModulate(args.fOutputColor,
                args.fTexSamplers[0],
                v.fsIn(),
                kVec2f_GrSLType);
            fragBuilder->codeAppend(";");
            fragBuilder->codeAppendf("%s = vec4(1);", args.fOutputCoverage);
        } else {
            fragBuilder->codeAppendf("%s = ", args.fOutputCoverage);
            fragBuilder->appendTextureLookup(args.fTexSamplers[0], v.fsIn(), kVec2f_GrSLType);
            fragBuilder->codeAppend(";");
            if (cte.maskFormat() == kA565_GrMaskFormat) {
                // set alpha to be max of rgb coverage
                fragBuilder->codeAppendf("%s.a = max(max(%s.r, %s.g), %s.b);",
                    args.fOutputCoverage, args.fOutputCoverage,
                    args.fOutputCoverage, args.fOutputCoverage);
            }
        }
    }

    void setData(const GrGLSLProgramDataManager& pdman, const GrPrimitiveProcessor& gp) override
    {
        const GrBitmapTextGeoProc& btgp = gp.cast<GrBitmapTextGeoProc>();
        if (btgp.color() != fColor && !btgp.hasVertexColor()) {
            float c[4];
=======
        this->setupPosition(pb, gpArgs, cte.inPosition()->fName);

        // emit transforms
        this->emitTransforms(args.fPB, gpArgs->fPositionVar, cte.inPosition()->fName,
                             cte.localMatrix(), args.fTransformsIn, args.fTransformsOut);

        GrGLFragmentBuilder* fsBuilder = pb->getFragmentShaderBuilder();
        if (cte.maskFormat() == kARGB_GrMaskFormat) {
            fsBuilder->codeAppendf("%s = ", args.fOutputColor);
            fsBuilder->appendTextureLookupAndModulate(args.fOutputColor,
                                                      args.fSamplers[0],
                                                      v.fsIn(),
                                                      kVec2f_GrSLType);
            fsBuilder->codeAppend(";");
            fsBuilder->codeAppendf("%s = vec4(1);", args.fOutputCoverage);
        } else {
            fsBuilder->codeAppendf("%s = ", args.fOutputCoverage);
            fsBuilder->appendTextureLookup(args.fSamplers[0], v.fsIn(), kVec2f_GrSLType);
            fsBuilder->codeAppend(";");
        }
    }

    virtual void setData(const GrGLProgramDataManager& pdman,
                         const GrPrimitiveProcessor& gp,
                         const GrBatchTracker& bt) override {
        const GrBitmapTextGeoProc& btgp = gp.cast<GrBitmapTextGeoProc>();
        if (btgp.color() != fColor && !btgp.hasVertexColor()) {
            GrGLfloat c[4];
>>>>>>> miniblink49
            GrColorToRGBAFloat(btgp.color(), c);
            pdman.set4fv(fColorUniform, 1, c);
            fColor = btgp.color();
        }
    }

    void setTransformData(const GrPrimitiveProcessor& primProc,
<<<<<<< HEAD
        const GrGLSLProgramDataManager& pdman,
        int index,
        const SkTArray<const GrCoordTransform*, true>& transforms) override
    {
=======
                          const GrGLProgramDataManager& pdman,
                          int index,
                          const SkTArray<const GrCoordTransform*, true>& transforms) override {
>>>>>>> miniblink49
        this->setTransformDataHelper<GrBitmapTextGeoProc>(primProc, pdman, index, transforms);
    }

    static inline void GenKey(const GrGeometryProcessor& proc,
<<<<<<< HEAD
        const GrGLSLCaps&,
        GrProcessorKeyBuilder* b)
    {
=======
                              const GrBatchTracker& bt,
                              const GrGLSLCaps&,
                              GrProcessorKeyBuilder* b) {
>>>>>>> miniblink49
        const GrBitmapTextGeoProc& gp = proc.cast<GrBitmapTextGeoProc>();
        uint32_t key = 0;
        key |= gp.usesLocalCoords() && gp.localMatrix().hasPerspective() ? 0x1 : 0x0;
        key |= gp.colorIgnored() ? 0x2 : 0x0;
        key |= gp.maskFormat() << 3;
        b->add32(key);
<<<<<<< HEAD

        // Currently we hardcode numbers to convert atlas coordinates to normalized floating point
        SkASSERT(gp.numTextures() == 1);
        GrTexture* atlas = gp.textureAccess(0).getTexture();
        SkASSERT(atlas);
        b->add32(atlas->width());
        b->add32(atlas->height());
=======
>>>>>>> miniblink49
    }

private:
    GrColor fColor;
    UniformHandle fColorUniform;

<<<<<<< HEAD
    typedef GrGLSLGeometryProcessor INHERITED;
=======
    typedef GrGLGeometryProcessor INHERITED;
>>>>>>> miniblink49
};

///////////////////////////////////////////////////////////////////////////////

GrBitmapTextGeoProc::GrBitmapTextGeoProc(GrColor color, GrTexture* texture,
<<<<<<< HEAD
    const GrTextureParams& params, GrMaskFormat format,
    const SkMatrix& localMatrix, bool usesLocalCoords)
=======
                                         const GrTextureParams& params, GrMaskFormat format,
                                         const SkMatrix& localMatrix, bool usesLocalCoords)
>>>>>>> miniblink49
    : fColor(color)
    , fLocalMatrix(localMatrix)
    , fUsesLocalCoords(usesLocalCoords)
    , fTextureAccess(texture, params)
<<<<<<< HEAD
    , fInColor(nullptr)
    , fMaskFormat(format)
{
    this->initClassID<GrBitmapTextGeoProc>();
    fInPosition = &this->addVertexAttrib(Attribute("inPosition", kVec2f_GrVertexAttribType));

    bool hasVertexColor = kA8_GrMaskFormat == fMaskFormat || kA565_GrMaskFormat == fMaskFormat;
=======
    , fInColor(NULL)
    , fMaskFormat(format) {
    this->initClassID<GrBitmapTextGeoProc>();
    fInPosition = &this->addVertexAttrib(Attribute("inPosition", kVec2f_GrVertexAttribType));

    // TODO we could think about removing this attribute if color is ignored, but unfortunately
    // we don't do text positioning in batch, so we can't quite do that yet.
    bool hasVertexColor = kA8_GrMaskFormat == fMaskFormat;
>>>>>>> miniblink49
    if (hasVertexColor) {
        fInColor = &this->addVertexAttrib(Attribute("inColor", kVec4ub_GrVertexAttribType));
    }
    fInTextureCoords = &this->addVertexAttrib(Attribute("inTextureCoords",
<<<<<<< HEAD
        kVec2us_GrVertexAttribType,
        kHigh_GrSLPrecision));
    this->addTextureAccess(&fTextureAccess);
}

void GrBitmapTextGeoProc::getGLSLProcessorKey(const GrGLSLCaps& caps,
    GrProcessorKeyBuilder* b) const
{
    GrGLBitmapTextGeoProc::GenKey(*this, caps, b);
}

GrGLSLPrimitiveProcessor* GrBitmapTextGeoProc::createGLSLInstance(const GrGLSLCaps& caps) const
{
    return new GrGLBitmapTextGeoProc();
=======
                                                        kVec2s_GrVertexAttribType));
    this->addTextureAccess(&fTextureAccess);
}

void GrBitmapTextGeoProc::getGLProcessorKey(const GrBatchTracker& bt,
                                            const GrGLSLCaps& caps,
                                            GrProcessorKeyBuilder* b) const {
    GrGLBitmapTextGeoProc::GenKey(*this, bt, caps, b);
}

GrGLPrimitiveProcessor*
GrBitmapTextGeoProc::createGLInstance(const GrBatchTracker& bt,
                                      const GrGLSLCaps& caps) const {
    return SkNEW_ARGS(GrGLBitmapTextGeoProc, (*this, bt));
>>>>>>> miniblink49
}

///////////////////////////////////////////////////////////////////////////////

GR_DEFINE_GEOMETRY_PROCESSOR_TEST(GrBitmapTextGeoProc);

<<<<<<< HEAD
sk_sp<GrGeometryProcessor> GrBitmapTextGeoProc::TestCreate(GrProcessorTestData* d)
{
    int texIdx = d->fRandom->nextBool() ? GrProcessorUnitTest::kSkiaPMTextureIdx : GrProcessorUnitTest::kAlphaTextureIdx;
=======
GrGeometryProcessor* GrBitmapTextGeoProc::TestCreate(GrProcessorTestData* d) {
    int texIdx = d->fRandom->nextBool() ? GrProcessorUnitTest::kSkiaPMTextureIdx :
                                          GrProcessorUnitTest::kAlphaTextureIdx;
>>>>>>> miniblink49
    static const SkShader::TileMode kTileModes[] = {
        SkShader::kClamp_TileMode,
        SkShader::kRepeat_TileMode,
        SkShader::kMirror_TileMode,
    };
    SkShader::TileMode tileModes[] = {
        kTileModes[d->fRandom->nextULessThan(SK_ARRAY_COUNT(kTileModes))],
        kTileModes[d->fRandom->nextULessThan(SK_ARRAY_COUNT(kTileModes))],
    };
<<<<<<< HEAD
    GrTextureParams params(tileModes, d->fRandom->nextBool() ? GrTextureParams::kBilerp_FilterMode : GrTextureParams::kNone_FilterMode);

    GrMaskFormat format = kARGB_GrMaskFormat; // init to avoid warning
    switch (d->fRandom->nextULessThan(3)) {
    case 0:
        format = kA8_GrMaskFormat;
        break;
    case 1:
        format = kA565_GrMaskFormat;
        break;
    case 2:
        format = kARGB_GrMaskFormat;
        break;
    }

    return GrBitmapTextGeoProc::Make(GrRandomColor(d->fRandom), d->fTextures[texIdx], params,
        format, GrTest::TestMatrix(d->fRandom),
        d->fRandom->nextBool());
=======
    GrTextureParams params(tileModes, d->fRandom->nextBool() ? GrTextureParams::kBilerp_FilterMode :
                                                           GrTextureParams::kNone_FilterMode);

    GrMaskFormat format;
    switch (d->fRandom->nextULessThan(3)) {
        case 0:
            format = kA8_GrMaskFormat;
            break;
        case 1:
            format = kA565_GrMaskFormat;
            break;
        case 2:
            format = kARGB_GrMaskFormat;
            break;
    }

    return GrBitmapTextGeoProc::Create(GrRandomColor(d->fRandom), d->fTextures[texIdx], params,
                                       format, GrTest::TestMatrix(d->fRandom),
                                       d->fRandom->nextBool());
>>>>>>> miniblink49
}
