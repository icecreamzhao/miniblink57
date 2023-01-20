/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkColorCubeFilter.h"
#include "SkColorPriv.h"
#include "SkOnce.h"
<<<<<<< HEAD
#include "SkOpts.h"
=======
>>>>>>> miniblink49
#include "SkReadBuffer.h"
#include "SkUnPreMultiply.h"
#include "SkWriteBuffer.h"
#if SK_SUPPORT_GPU
#include "GrContext.h"
#include "GrCoordTransform.h"
#include "GrInvariantOutput.h"
#include "GrTexturePriv.h"
#include "SkGr.h"
<<<<<<< HEAD
#include "glsl/GrGLSLFragmentProcessor.h"
#include "glsl/GrGLSLFragmentShaderBuilder.h"
#include "glsl/GrGLSLProgramDataManager.h"
#include "glsl/GrGLSLUniformHandler.h"
=======
#include "gl/GrGLProcessor.h"
#include "gl/builders/GrGLProgramBuilder.h"
>>>>>>> miniblink49
#endif

///////////////////////////////////////////////////////////////////////////////
namespace {

<<<<<<< HEAD
int32_t SkNextColorCubeUniqueID()
{
=======
int32_t SkNextColorCubeUniqueID() {
>>>>>>> miniblink49
    static int32_t gColorCubeUniqueID;
    // do a loop in case our global wraps around, as we never want to return a 0
    int32_t genID;
    do {
        genID = sk_atomic_inc(&gColorCubeUniqueID) + 1;
    } while (0 == genID);
    return genID;
}

} // end namespace

static const int MIN_CUBE_SIZE = 4;
static const int MAX_CUBE_SIZE = 64;

<<<<<<< HEAD
static bool is_valid_3D_lut(SkData* cubeData, int cubeDimension)
{
    size_t minMemorySize = sizeof(uint8_t) * 4 * cubeDimension * cubeDimension * cubeDimension;
    return (cubeDimension >= MIN_CUBE_SIZE) && (cubeDimension <= MAX_CUBE_SIZE) && (nullptr != cubeData) && (cubeData->size() >= minMemorySize);
}

sk_sp<SkColorFilter> SkColorCubeFilter::Make(sk_sp<SkData> cubeData, int cubeDimension)
{
    if (!is_valid_3D_lut(cubeData.get(), cubeDimension)) {
        return nullptr;
    }

    return sk_sp<SkColorFilter>(new SkColorCubeFilter(std::move(cubeData), cubeDimension));
}

SkColorCubeFilter::SkColorCubeFilter(sk_sp<SkData> cubeData, int cubeDimension)
    : fCubeData(std::move(cubeData))
    , fUniqueID(SkNextColorCubeUniqueID())
    , fCache(cubeDimension)
{
}

uint32_t SkColorCubeFilter::getFlags() const
{
=======
static bool is_valid_3D_lut(SkData* cubeData, int cubeDimension) {
    size_t minMemorySize = sizeof(uint8_t) * 4 * cubeDimension * cubeDimension * cubeDimension;
    return (cubeDimension >= MIN_CUBE_SIZE) && (cubeDimension <= MAX_CUBE_SIZE) &&
           (NULL != cubeData) && (cubeData->size() >= minMemorySize);
}

SkColorFilter* SkColorCubeFilter::Create(SkData* cubeData, int cubeDimension) {
    if (!is_valid_3D_lut(cubeData, cubeDimension)) {
        return NULL;
    }

    return SkNEW_ARGS(SkColorCubeFilter, (cubeData, cubeDimension));
}

SkColorCubeFilter::SkColorCubeFilter(SkData* cubeData, int cubeDimension)
  : fCubeData(SkRef(cubeData))
  , fUniqueID(SkNextColorCubeUniqueID())
  , fCache(cubeDimension) {
}

uint32_t SkColorCubeFilter::getFlags() const {
>>>>>>> miniblink49
    return this->INHERITED::getFlags() | kAlphaUnchanged_Flag;
}

SkColorCubeFilter::ColorCubeProcesingCache::ColorCubeProcesingCache(int cubeDimension)
<<<<<<< HEAD
    : fCubeDimension(cubeDimension)
{
    fColorToIndex[0] = fColorToIndex[1] = nullptr;
    fColorToFactors[0] = fColorToFactors[1] = nullptr;
    fColorToScalar = nullptr;
=======
  : fCubeDimension(cubeDimension)
  , fLutsInited(false) {
    fColorToIndex[0] = fColorToIndex[1] = NULL;
    fColorToFactors[0] = fColorToFactors[1] = NULL;
    fColorToScalar = NULL;
>>>>>>> miniblink49
}

void SkColorCubeFilter::ColorCubeProcesingCache::getProcessingLuts(
    const int* (*colorToIndex)[2], const SkScalar* (*colorToFactors)[2],
<<<<<<< HEAD
    const SkScalar** colorToScalar)
{
    fLutsInitOnce(SkColorCubeFilter::ColorCubeProcesingCache::initProcessingLuts, this);

    SkASSERT((fColorToIndex[0] != nullptr) && (fColorToIndex[1] != nullptr) && (fColorToFactors[0] != nullptr) && (fColorToFactors[1] != nullptr) && (fColorToScalar != nullptr));
=======
    const SkScalar** colorToScalar) {
    SkOnce(&fLutsInited, &fLutsMutex,
           SkColorCubeFilter::ColorCubeProcesingCache::initProcessingLuts, this);
    SkASSERT((fColorToIndex[0] != NULL) &&
             (fColorToIndex[1] != NULL) &&
             (fColorToFactors[0] != NULL) &&
             (fColorToFactors[1] != NULL) &&
             (fColorToScalar != NULL));
>>>>>>> miniblink49
    (*colorToIndex)[0] = fColorToIndex[0];
    (*colorToIndex)[1] = fColorToIndex[1];
    (*colorToFactors)[0] = fColorToFactors[0];
    (*colorToFactors)[1] = fColorToFactors[1];
    (*colorToScalar) = fColorToScalar;
}

void SkColorCubeFilter::ColorCubeProcesingCache::initProcessingLuts(
<<<<<<< HEAD
    SkColorCubeFilter::ColorCubeProcesingCache* cache)
{
=======
    SkColorCubeFilter::ColorCubeProcesingCache* cache) {
>>>>>>> miniblink49
    static const SkScalar inv8bit = SkScalarInvert(SkIntToScalar(255));

    // We need 256 int * 2 for fColorToIndex, so a total of 512 int.
    // We need 256 SkScalar * 2 for fColorToFactors and 256 SkScalar
    // for fColorToScalar, so a total of 768 SkScalar.
    cache->fLutStorage.reset(512 * sizeof(int) + 768 * sizeof(SkScalar));
<<<<<<< HEAD
    uint8_t* storage = cache->fLutStorage.get();
=======
    uint8_t* storage = (uint8_t*)cache->fLutStorage.get();
>>>>>>> miniblink49
    cache->fColorToIndex[0] = (int*)storage;
    cache->fColorToIndex[1] = cache->fColorToIndex[0] + 256;
    cache->fColorToFactors[0] = (SkScalar*)(storage + (512 * sizeof(int)));
    cache->fColorToFactors[1] = cache->fColorToFactors[0] + 256;
    cache->fColorToScalar = cache->fColorToFactors[1] + 256;

    SkScalar size = SkIntToScalar(cache->fCubeDimension);
    SkScalar scale = (size - SK_Scalar1) * inv8bit;

    for (int i = 0; i < 256; ++i) {
        SkScalar index = scale * i;
        cache->fColorToIndex[0][i] = SkScalarFloorToInt(index);
        cache->fColorToIndex[1][i] = cache->fColorToIndex[0][i] + 1;
        cache->fColorToScalar[i] = inv8bit * i;
        if (cache->fColorToIndex[1][i] < cache->fCubeDimension) {
            cache->fColorToFactors[1][i] = index - SkIntToScalar(cache->fColorToIndex[0][i]);
            cache->fColorToFactors[0][i] = SK_Scalar1 - cache->fColorToFactors[1][i];
        } else {
            cache->fColorToIndex[1][i] = cache->fColorToIndex[0][i];
            cache->fColorToFactors[0][i] = SK_Scalar1;
            cache->fColorToFactors[1][i] = 0;
        }
    }
}

<<<<<<< HEAD
void SkColorCubeFilter::filterSpan(const SkPMColor src[], int count, SkPMColor dst[]) const
{
=======
void SkColorCubeFilter::filterSpan(const SkPMColor src[], int count, SkPMColor dst[]) const {
>>>>>>> miniblink49
    const int* colorToIndex[2];
    const SkScalar* colorToFactors[2];
    const SkScalar* colorToScalar;
    fCache.getProcessingLuts(&colorToIndex, &colorToFactors, &colorToScalar);

<<<<<<< HEAD
    SkOpts::color_cube_filter_span(src, count, dst, colorToIndex,
        colorToFactors, fCache.cubeDimension(),
        (const SkColor*)fCubeData->data());
}

sk_sp<SkFlattenable> SkColorCubeFilter::CreateProc(SkReadBuffer& buffer)
{
    int cubeDimension = buffer.readInt();
    auto cubeData(buffer.readByteArrayAsData());
    if (!buffer.validate(is_valid_3D_lut(cubeData.get(), cubeDimension))) {
        return nullptr;
    }
    return Make(std::move(cubeData), cubeDimension);
}

void SkColorCubeFilter::flatten(SkWriteBuffer& buffer) const
{
    this->INHERITED::flatten(buffer);
    buffer.writeInt(fCache.cubeDimension());
    buffer.writeDataAsByteArray(fCubeData.get());
}

#ifndef SK_IGNORE_TO_STRING
void SkColorCubeFilter::toString(SkString* str) const
{
=======
    const int dim = fCache.cubeDimension();
    SkColor* colorCube = (SkColor*)fCubeData->data();
    for (int i = 0; i < count; ++i) {
        SkColor inputColor = SkUnPreMultiply::PMColorToColor(src[i]);
        uint8_t r = SkColorGetR(inputColor);
        uint8_t g = SkColorGetG(inputColor);
        uint8_t b = SkColorGetB(inputColor);
        uint8_t a = SkColorGetA(inputColor);
        SkScalar rOut(0), gOut(0), bOut(0);
        for (int x = 0; x < 2; ++x) {
            for (int y = 0; y < 2; ++y) {
                for (int z = 0; z < 2; ++z) {
                    SkColor lutColor = colorCube[colorToIndex[x][r] +
                                                (colorToIndex[y][g] +
                                                 colorToIndex[z][b] * dim) * dim];
                    SkScalar factor = colorToFactors[x][r] *
                                      colorToFactors[y][g] *
                                      colorToFactors[z][b];
                    rOut += colorToScalar[SkColorGetR(lutColor)] * factor;
                    gOut += colorToScalar[SkColorGetG(lutColor)] * factor;
                    bOut += colorToScalar[SkColorGetB(lutColor)] * factor;
                }
            }
        }
        const SkScalar aOut = SkIntToScalar(a);
        dst[i] = SkPackARGB32(a,
            SkScalarRoundToInt(rOut * aOut),
            SkScalarRoundToInt(gOut * aOut),
            SkScalarRoundToInt(bOut * aOut));
    }
}

SkFlattenable* SkColorCubeFilter::CreateProc(SkReadBuffer& buffer) {
    int cubeDimension = buffer.readInt();
    SkAutoDataUnref cubeData(buffer.readByteArrayAsData());
    if (!buffer.validate(is_valid_3D_lut(cubeData, cubeDimension))) {
        return NULL;
    }
    return Create(cubeData, cubeDimension);
}

void SkColorCubeFilter::flatten(SkWriteBuffer& buffer) const {
    this->INHERITED::flatten(buffer);
    buffer.writeInt(fCache.cubeDimension());
    buffer.writeDataAsByteArray(fCubeData);
}

#ifndef SK_IGNORE_TO_STRING
void SkColorCubeFilter::toString(SkString* str) const {
>>>>>>> miniblink49
    str->append("SkColorCubeFilter ");
}
#endif

///////////////////////////////////////////////////////////////////////////////
#if SK_SUPPORT_GPU

class GrColorCubeEffect : public GrFragmentProcessor {
public:
<<<<<<< HEAD
    static sk_sp<GrFragmentProcessor> Make(GrTexture* colorCube)
    {
        return (nullptr != colorCube) ? sk_sp<GrFragmentProcessor>(new GrColorCubeEffect(colorCube))
                                      : nullptr;
=======
    static GrFragmentProcessor* Create(GrTexture* colorCube) {
        return (NULL != colorCube) ? SkNEW_ARGS(GrColorCubeEffect, (colorCube)) : NULL;
>>>>>>> miniblink49
    }

    virtual ~GrColorCubeEffect();

    const char* name() const override { return "ColorCube"; }

<<<<<<< HEAD
    int colorCubeSize() const { return fColorCubeAccess.getTexture()->width(); }

    void onComputeInvariantOutput(GrInvariantOutput*) const override;

    class GLSLProcessor : public GrGLSLFragmentProcessor {
    public:
        void emitCode(EmitArgs&) override;

        static inline void GenKey(const GrProcessor&, const GrGLSLCaps&, GrProcessorKeyBuilder*);

    protected:
        void onSetData(const GrGLSLProgramDataManager&, const GrProcessor&) override;

    private:
        GrGLSLProgramDataManager::UniformHandle fColorCubeSizeUni;
        GrGLSLProgramDataManager::UniformHandle fColorCubeInvSizeUni;

        typedef GrGLSLFragmentProcessor INHERITED;
    };

private:
    virtual void onGetGLSLProcessorKey(const GrGLSLCaps& caps,
        GrProcessorKeyBuilder* b) const override;

    GrGLSLFragmentProcessor* onCreateGLSLInstance() const override;

=======
    virtual void getGLProcessorKey(const GrGLSLCaps& caps,
                                   GrProcessorKeyBuilder* b) const override;

    GrGLFragmentProcessor* createGLInstance() const override;
    int colorCubeSize() const { return fColorCubeAccess.getTexture()->width(); }


    void onComputeInvariantOutput(GrInvariantOutput*) const override;

    class GLProcessor : public GrGLFragmentProcessor {
    public:
        GLProcessor(const GrProcessor&);
        virtual ~GLProcessor();

        virtual void emitCode(GrGLFPBuilder*,
                              const GrFragmentProcessor&,
                              const char* outputColor,
                              const char* inputColor,
                              const TransformedCoordsArray&,
                              const TextureSamplerArray&) override;

        static inline void GenKey(const GrProcessor&, const GrGLSLCaps&, GrProcessorKeyBuilder*);

        void setData(const GrGLProgramDataManager&, const GrProcessor&) override;

    private:
        GrGLProgramDataManager::UniformHandle fColorCubeSizeUni;
        GrGLProgramDataManager::UniformHandle fColorCubeInvSizeUni;

        typedef GrGLFragmentProcessor INHERITED;
    };

private:
>>>>>>> miniblink49
    bool onIsEqual(const GrFragmentProcessor&) const override { return true; }

    GrColorCubeEffect(GrTexture* colorCube);

<<<<<<< HEAD
    GrTextureAccess fColorCubeAccess;
=======
    GrTextureAccess     fColorCubeAccess;
>>>>>>> miniblink49

    typedef GrFragmentProcessor INHERITED;
};

///////////////////////////////////////////////////////////////////////////////

GrColorCubeEffect::GrColorCubeEffect(GrTexture* colorCube)
<<<<<<< HEAD
    : fColorCubeAccess(colorCube, GrTextureParams::kBilerp_FilterMode)
{
=======
    : fColorCubeAccess(colorCube, "bgra", GrTextureParams::kBilerp_FilterMode) {
>>>>>>> miniblink49
    this->initClassID<GrColorCubeEffect>();
    this->addTextureAccess(&fColorCubeAccess);
}

<<<<<<< HEAD
GrColorCubeEffect::~GrColorCubeEffect()
{
}

void GrColorCubeEffect::onGetGLSLProcessorKey(const GrGLSLCaps& caps,
    GrProcessorKeyBuilder* b) const
{
    GLSLProcessor::GenKey(*this, caps, b);
}

GrGLSLFragmentProcessor* GrColorCubeEffect::onCreateGLSLInstance() const
{
    return new GLSLProcessor;
}

void GrColorCubeEffect::onComputeInvariantOutput(GrInvariantOutput* inout) const
{
=======
GrColorCubeEffect::~GrColorCubeEffect() {
}

void GrColorCubeEffect::getGLProcessorKey(const GrGLSLCaps& caps, GrProcessorKeyBuilder* b) const {
    GLProcessor::GenKey(*this, caps, b);
}

GrGLFragmentProcessor* GrColorCubeEffect::createGLInstance() const {
    return SkNEW_ARGS(GLProcessor, (*this));
}

void GrColorCubeEffect::onComputeInvariantOutput(GrInvariantOutput* inout) const {
>>>>>>> miniblink49
    inout->setToUnknown(GrInvariantOutput::kWill_ReadInput);
}

///////////////////////////////////////////////////////////////////////////////

<<<<<<< HEAD
void GrColorCubeEffect::GLSLProcessor::emitCode(EmitArgs& args)
{
    if (nullptr == args.fInputColor) {
        args.fInputColor = "vec4(1)";
    }

    GrGLSLUniformHandler* uniformHandler = args.fUniformHandler;
    fColorCubeSizeUni = uniformHandler->addUniform(kFragment_GrShaderFlag,
        kFloat_GrSLType, kDefault_GrSLPrecision,
        "Size");
    const char* colorCubeSizeUni = uniformHandler->getUniformCStr(fColorCubeSizeUni);
    fColorCubeInvSizeUni = uniformHandler->addUniform(kFragment_GrShaderFlag,
        kFloat_GrSLType, kDefault_GrSLPrecision,
        "InvSize");
    const char* colorCubeInvSizeUni = uniformHandler->getUniformCStr(fColorCubeInvSizeUni);
=======
GrColorCubeEffect::GLProcessor::GLProcessor(const GrProcessor&) {
}

GrColorCubeEffect::GLProcessor::~GLProcessor() {
}

void GrColorCubeEffect::GLProcessor::emitCode(GrGLFPBuilder* builder,
                                              const GrFragmentProcessor&,
                                              const char* outputColor,
                                              const char* inputColor,
                                              const TransformedCoordsArray& coords,
                                              const TextureSamplerArray& samplers) {
    if (NULL == inputColor) {
        inputColor = "vec4(1)";
    }

    fColorCubeSizeUni = builder->addUniform(GrGLProgramBuilder::kFragment_Visibility,
                                            kFloat_GrSLType, kDefault_GrSLPrecision,
                                            "Size");
    const char* colorCubeSizeUni = builder->getUniformCStr(fColorCubeSizeUni);
    fColorCubeInvSizeUni = builder->addUniform(GrGLProgramBuilder::kFragment_Visibility,
                                               kFloat_GrSLType, kDefault_GrSLPrecision,
                                               "InvSize");
    const char* colorCubeInvSizeUni = builder->getUniformCStr(fColorCubeInvSizeUni);
>>>>>>> miniblink49

    const char* nonZeroAlpha = "nonZeroAlpha";
    const char* unPMColor = "unPMColor";
    const char* cubeIdx = "cubeIdx";
    const char* cCoords1 = "cCoords1";
    const char* cCoords2 = "cCoords2";

    // Note: if implemented using texture3D in OpenGL ES older than OpenGL ES 3.0,
    //       the shader might need "#extension GL_OES_texture_3D : enable".

<<<<<<< HEAD
    GrGLSLFPFragmentBuilder* fragBuilder = args.fFragBuilder;

    // Unpremultiply color
    fragBuilder->codeAppendf("\tfloat %s = max(%s.a, 0.00001);\n", nonZeroAlpha, args.fInputColor);
    fragBuilder->codeAppendf("\tvec4 %s = vec4(%s.rgb / %s, %s);\n",
        unPMColor, args.fInputColor, nonZeroAlpha, nonZeroAlpha);

    // Fit input color into the cube.
    fragBuilder->codeAppendf(
=======
    GrGLFragmentBuilder* fsBuilder = builder->getFragmentShaderBuilder();

    // Unpremultiply color
    fsBuilder->codeAppendf("\tfloat %s = max(%s.a, 0.00001);\n", nonZeroAlpha, inputColor);
    fsBuilder->codeAppendf("\tvec4 %s = vec4(%s.rgb / %s, %s);\n",
                           unPMColor, inputColor, nonZeroAlpha, nonZeroAlpha);

    // Fit input color into the cube.
    fsBuilder->codeAppendf(
>>>>>>> miniblink49
        "vec3 %s = vec3(%s.rg * vec2((%s - 1.0) * %s) + vec2(0.5 * %s), %s.b * (%s - 1.0));\n",
        cubeIdx, unPMColor, colorCubeSizeUni, colorCubeInvSizeUni, colorCubeInvSizeUni,
        unPMColor, colorCubeSizeUni);

    // Compute y coord for for texture fetches.
<<<<<<< HEAD
    fragBuilder->codeAppendf("vec2 %s = vec2(%s.r, (floor(%s.b) + %s.g) * %s);\n",
        cCoords1, cubeIdx, cubeIdx, cubeIdx, colorCubeInvSizeUni);
    fragBuilder->codeAppendf("vec2 %s = vec2(%s.r, (ceil(%s.b) + %s.g) * %s);\n",
        cCoords2, cubeIdx, cubeIdx, cubeIdx, colorCubeInvSizeUni);

    // Apply the cube.
    fragBuilder->codeAppendf("%s = vec4(mix(", args.fOutputColor);
    fragBuilder->appendTextureLookup(args.fTexSamplers[0], cCoords1);
    fragBuilder->codeAppend(".bgr, ");
    fragBuilder->appendTextureLookup(args.fTexSamplers[0], cCoords2);

    // Premultiply color by alpha. Note that the input alpha is not modified by this shader.
    fragBuilder->codeAppendf(".bgr, fract(%s.b)) * vec3(%s), %s.a);\n",
        cubeIdx, nonZeroAlpha, args.fInputColor);
}

void GrColorCubeEffect::GLSLProcessor::onSetData(const GrGLSLProgramDataManager& pdman,
    const GrProcessor& proc)
{
=======
    fsBuilder->codeAppendf("vec2 %s = vec2(%s.r, (floor(%s.b) + %s.g) * %s);\n",
                           cCoords1, cubeIdx, cubeIdx, cubeIdx, colorCubeInvSizeUni);
    fsBuilder->codeAppendf("vec2 %s = vec2(%s.r, (ceil(%s.b) + %s.g) * %s);\n",
                           cCoords2, cubeIdx, cubeIdx, cubeIdx, colorCubeInvSizeUni);

    // Apply the cube.
    fsBuilder->codeAppendf("%s = vec4(mix(", outputColor);
    fsBuilder->appendTextureLookup(samplers[0], cCoords1);
    fsBuilder->codeAppend(".rgb, ");
    fsBuilder->appendTextureLookup(samplers[0], cCoords2);

    // Premultiply color by alpha. Note that the input alpha is not modified by this shader.
    fsBuilder->codeAppendf(".rgb, fract(%s.b)) * vec3(%s), %s.a);\n",
                           cubeIdx, nonZeroAlpha, inputColor);
}

void GrColorCubeEffect::GLProcessor::setData(const GrGLProgramDataManager& pdman,
                                             const GrProcessor& proc) {
>>>>>>> miniblink49
    const GrColorCubeEffect& colorCube = proc.cast<GrColorCubeEffect>();
    SkScalar size = SkIntToScalar(colorCube.colorCubeSize());
    pdman.set1f(fColorCubeSizeUni, SkScalarToFloat(size));
    pdman.set1f(fColorCubeInvSizeUni, SkScalarToFloat(SkScalarInvert(size)));
}

<<<<<<< HEAD
void GrColorCubeEffect::GLSLProcessor::GenKey(const GrProcessor& proc,
    const GrGLSLCaps&, GrProcessorKeyBuilder* b)
{
}

sk_sp<GrFragmentProcessor> SkColorCubeFilter::asFragmentProcessor(GrContext* context) const
{
=======
void GrColorCubeEffect::GLProcessor::GenKey(const GrProcessor& proc,
                                            const GrGLSLCaps&, GrProcessorKeyBuilder* b) {
}

bool SkColorCubeFilter::asFragmentProcessors(GrContext* context, GrProcessorDataManager*,
                                             SkTDArray<GrFragmentProcessor*>* array) const {
>>>>>>> miniblink49
    static const GrUniqueKey::Domain kDomain = GrUniqueKey::GenerateDomain();
    GrUniqueKey key;
    GrUniqueKey::Builder builder(&key, kDomain, 2);
    builder[0] = fUniqueID;
    builder[1] = fCache.cubeDimension();
    builder.finish();

    GrSurfaceDesc desc;
    desc.fWidth = fCache.cubeDimension();
    desc.fHeight = fCache.cubeDimension() * fCache.cubeDimension();
    desc.fConfig = kRGBA_8888_GrPixelConfig;
<<<<<<< HEAD
    desc.fIsMipMapped = false;
=======
>>>>>>> miniblink49

    SkAutoTUnref<GrTexture> textureCube(
        context->textureProvider()->findAndRefTextureByUniqueKey(key));
    if (!textureCube) {
        textureCube.reset(context->textureProvider()->createTexture(
<<<<<<< HEAD
            desc, SkBudgeted::kYes, fCubeData->data(), 0));
        if (textureCube) {
            context->textureProvider()->assignUniqueKeyToTexture(key, textureCube);
        } else {
            return nullptr;
        }
    }

    return sk_sp<GrFragmentProcessor>(GrColorCubeEffect::Make(textureCube));
=======
            desc, true, fCubeData->data(), 0));
        if (textureCube) {
            context->textureProvider()->assignUniqueKeyToTexture(key, textureCube);
        }
    }

    GrFragmentProcessor* frag = textureCube ? GrColorCubeEffect::Create(textureCube) : NULL;
    if (frag) {
        if (array) {
            *array->append() = frag;
        } else {
            frag->unref();
            SkDEBUGCODE(frag = NULL;)
        }
        return true;
    }
    return false;
>>>>>>> miniblink49
}
#endif
