/*
 * Copyright 2013 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */
#include "GrGLProgramDesc.h"

<<<<<<< HEAD
#include "GrPipeline.h"
#include "GrProcessor.h"
#include "GrRenderTargetPriv.h"
#include "SkChecksum.h"
#include "gl/GrGLDefines.h"
#include "gl/GrGLTexture.h"
#include "gl/GrGLTypes.h"
#include "glsl/GrGLSLCaps.h"
#include "glsl/GrGLSLFragmentProcessor.h"
#include "glsl/GrGLSLFragmentShaderBuilder.h"

static uint16_t sampler_key(GrSLType samplerType, GrPixelConfig config, GrShaderFlags visibility,
    const GrGLSLCaps& caps)
{
    enum {
        kFirstSamplerType = kSampler2D_GrSLType,
        kLastSamplerType = kSamplerBuffer_GrSLType,
        kSamplerTypeKeyBits = 4
    };
    GR_STATIC_ASSERT(kLastSamplerType - kFirstSamplerType < (1 << kSamplerTypeKeyBits));

    SkASSERT((int)samplerType >= kFirstSamplerType && (int)samplerType <= kLastSamplerType);
    int samplerTypeKey = samplerType - kFirstSamplerType;

    return SkToU16(caps.configTextureSwizzle(config).asKey() | (samplerTypeKey << 8) | (caps.samplerPrecision(config, visibility) << (8 + kSamplerTypeKeyBits)));
}

static void add_sampler_keys(GrProcessorKeyBuilder* b, const GrProcessor& proc,
    const GrGLSLCaps& caps)
{
    int numTextures = proc.numTextures();
    int numSamplers = numTextures + proc.numBuffers();
    // Need two bytes per key (swizzle, sampler type, and precision).
    int word32Count = (numSamplers + 1) / 2;
    if (0 == word32Count) {
        return;
    }
    uint16_t* k16 = SkTCast<uint16_t*>(b->add32n(word32Count));
    int i = 0;
    for (; i < numTextures; ++i) {
        const GrTextureAccess& access = proc.textureAccess(i);
        const GrTexture* tex = access.getTexture();
        k16[i] = sampler_key(tex->samplerType(), tex->config(), access.getVisibility(), caps);
    }
    for (; i < numSamplers; ++i) {
        const GrBufferAccess& access = proc.bufferAccess(i - numTextures);
        k16[i] = sampler_key(kSamplerBuffer_GrSLType, access.texelConfig(), access.visibility(),
            caps);
    }
    // zero the last 16 bits if the number of samplers is odd.
    if (numSamplers & 0x1) {
        k16[numSamplers] = 0;
    }
=======
#include "GrGLProcessor.h"
#include "GrProcessor.h"
#include "GrGLGpu.h"
#include "GrPipeline.h"
#include "SkChecksum.h"
#include "gl/builders/GrGLFragmentShaderBuilder.h"

/**
 * Do we need to either map r,g,b->a or a->r. configComponentMask indicates which channels are
 * present in the texture's config. swizzleComponentMask indicates the channels present in the
 * shader swizzle.
 */
static bool swizzle_requires_alpha_remapping(const GrGLCaps& caps,
                                             uint32_t configComponentMask,
                                             uint32_t swizzleComponentMask) {
    if (caps.textureSwizzleSupport()) {
        // Any remapping is handled using texture swizzling not shader modifications.
        return false;
    }
    // check if the texture is alpha-only
    if (kA_GrColorComponentFlag == configComponentMask) {
        if (caps.textureRedSupport() && (kA_GrColorComponentFlag & swizzleComponentMask)) {
            // we must map the swizzle 'a's to 'r'.
            return true;
        }
        if (kRGB_GrColorComponentFlags & swizzleComponentMask) {
            // The 'r', 'g', and/or 'b's must be mapped to 'a' according to our semantics that
            // alpha-only textures smear alpha across all four channels when read.
            return true;
        }
    }
    return false;
}

static uint32_t gen_texture_key(const GrProcessor& proc, const GrGLCaps& caps) {
    uint32_t key = 0;
    int numTextures = proc.numTextures();
    for (int t = 0; t < numTextures; ++t) {
        const GrTextureAccess& access = proc.textureAccess(t);
        uint32_t configComponentMask = GrPixelConfigComponentMask(access.getTexture()->config());
        if (swizzle_requires_alpha_remapping(caps, configComponentMask, access.swizzleMask())) {
            key |= 1 << t;
        }
    }
    return key;
>>>>>>> miniblink49
}

/**
 * A function which emits a meta key into the key builder.  This is required because shader code may
 * be dependent on properties of the effect that the effect itself doesn't use
 * in its key (e.g. the pixel format of textures used). So we create a meta-key for
 * every effect using this function. It is also responsible for inserting the effect's class ID
 * which must be different for every GrProcessor subclass. It can fail if an effect uses too many
<<<<<<< HEAD
 * transforms, etc, for the space allotted in the meta-key.  NOTE, both FPs and GPs share this
 * function because it is hairy, though FPs do not have attribs, and GPs do not have transforms
 */
static bool gen_meta_key(const GrProcessor& proc,
    const GrGLSLCaps& glslCaps,
    uint32_t transformKey,
    GrProcessorKeyBuilder* b)
{
    size_t processorKeySize = b->size();
    uint32_t classID = proc.classID();

    // Currently we allow 16 bits for the class id and the overall processor key size.
    static const uint32_t kMetaKeyInvalidMask = ~((uint32_t)SK_MaxU16);
    if ((processorKeySize | classID) & kMetaKeyInvalidMask) {
        return false;
    }

    add_sampler_keys(b, proc, glslCaps);

    uint32_t* key = b->add32n(2);
    key[0] = (classID << 16) | SkToU32(processorKeySize);
    key[1] = transformKey;
    return true;
}

static bool gen_frag_proc_and_meta_keys(const GrPrimitiveProcessor& primProc,
    const GrFragmentProcessor& fp,
    const GrGLSLCaps& glslCaps,
    GrProcessorKeyBuilder* b)
{
    for (int i = 0; i < fp.numChildProcessors(); ++i) {
        if (!gen_frag_proc_and_meta_keys(primProc, fp.childProcessor(i), glslCaps, b)) {
            return false;
        }
    }

    fp.getGLSLProcessorKey(glslCaps, b);

    return gen_meta_key(fp, glslCaps, primProc.getTransformKey(fp.coordTransforms(), fp.numTransformsExclChildren()), b);
}

bool GrGLProgramDescBuilder::Build(GrProgramDesc* desc,
    const GrPrimitiveProcessor& primProc,
    const GrPipeline& pipeline,
    const GrGLSLCaps& glslCaps)
{
=======
 * textures, transforms, etc, for the space allotted in the meta-key.  NOTE, both FPs and GPs share
 * this function because it is hairy, though FPs do not have attribs, and GPs do not have transforms
 */
static bool get_meta_key(const GrProcessor& proc,
                         const GrGLCaps& caps,
                         uint32_t transformKey,
                         GrProcessorKeyBuilder* b) {
    size_t processorKeySize = b->size();
    uint32_t textureKey = gen_texture_key(proc, caps);
    uint32_t classID = proc.classID();

    // Currently we allow 16 bits for each of the above portions of the meta-key. Fail if they
    // don't fit.
    static const uint32_t kMetaKeyInvalidMask = ~((uint32_t) SK_MaxU16);
    if ((textureKey | transformKey | classID) & kMetaKeyInvalidMask) {
        return false;
    }
    if (processorKeySize > SK_MaxU16) {
        return false;
    }

    uint32_t* key = b->add32n(2);
    key[0] = (textureKey << 16 | transformKey);
    key[1] = (classID << 16 | SkToU16(processorKeySize));
    return true;
}

bool GrGLProgramDescBuilder::Build(GrProgramDesc* desc,
                                   const GrPrimitiveProcessor& primProc,
                                   const GrPipeline& pipeline,
                                   const GrGLGpu* gpu,
                                   const GrBatchTracker& batchTracker) {
>>>>>>> miniblink49
    // The descriptor is used as a cache key. Thus when a field of the
    // descriptor will not affect program generation (because of the attribute
    // bindings in use or other descriptor field settings) it should be set
    // to a canonical value to avoid duplicate programs with different keys.

<<<<<<< HEAD
    GrGLProgramDesc* glDesc = (GrGLProgramDesc*)desc;
=======
    GrGLProgramDesc* glDesc = (GrGLProgramDesc*) desc;
>>>>>>> miniblink49

    GR_STATIC_ASSERT(0 == kProcessorKeysOffset % sizeof(uint32_t));
    // Make room for everything up to the effect keys.
    glDesc->key().reset();
    glDesc->key().push_back_n(kProcessorKeysOffset);

    GrProcessorKeyBuilder b(&glDesc->key());

<<<<<<< HEAD
    primProc.getGLSLProcessorKey(glslCaps, &b);
    if (!gen_meta_key(primProc, glslCaps, 0, &b)) {
        glDesc->key().reset();
        return false;
    }
    GrProcessor::RequiredFeatures requiredFeatures = primProc.requiredFeatures();

    for (int i = 0; i < pipeline.numFragmentProcessors(); ++i) {
        const GrFragmentProcessor& fp = pipeline.getFragmentProcessor(i);
        if (!gen_frag_proc_and_meta_keys(primProc, fp, glslCaps, &b)) {
            glDesc->key().reset();
            return false;
        }
        requiredFeatures |= fp.requiredFeatures();
    }

    const GrXferProcessor& xp = pipeline.getXferProcessor();
    xp.getGLSLProcessorKey(glslCaps, &b);
    if (!gen_meta_key(xp, glslCaps, 0, &b)) {
        glDesc->key().reset();
        return false;
    }
    requiredFeatures |= xp.requiredFeatures();
=======
    primProc.getGLProcessorKey(batchTracker, *gpu->glCaps().glslCaps(), &b);
    //**** use glslCaps here?
    if (!get_meta_key(primProc, gpu->glCaps(), 0, &b)) {
        glDesc->key().reset();
        return false;
    }

    for (int s = 0; s < pipeline.numFragmentStages(); ++s) {
        const GrPendingFragmentStage& fps = pipeline.getFragmentStage(s);
        const GrFragmentProcessor& fp = *fps.processor();
        fp.getGLProcessorKey(*gpu->glCaps().glslCaps(), &b);
        //**** use glslCaps here?
        if (!get_meta_key(fp, gpu->glCaps(), primProc.getTransformKey(fp.coordTransforms()), &b)) {
            glDesc->key().reset();
            return false;
        }
    }

    const GrXferProcessor& xp = *pipeline.getXferProcessor();
    xp.getGLProcessorKey(*gpu->glCaps().glslCaps(), &b);
    //**** use glslCaps here?
    if (!get_meta_key(xp, gpu->glCaps(), 0, &b)) {
        glDesc->key().reset();
        return false;
    }
>>>>>>> miniblink49

    // --------DO NOT MOVE HEADER ABOVE THIS LINE--------------------------------------------------
    // Because header is a pointer into the dynamic array, we can't push any new data into the key
    // below here.
    KeyHeader* header = glDesc->atOffset<KeyHeader, kHeaderOffset>();

    // make sure any padding in the header is zeroed.
    memset(header, 0, kHeaderSize);

<<<<<<< HEAD
    GrRenderTarget* rt = pipeline.getRenderTarget();

    if (requiredFeatures & (GrProcessor::kFragmentPosition_RequiredFeature | GrProcessor::kSampleLocations_RequiredFeature)) {
        header->fSurfaceOriginKey = GrGLSLFragmentShaderBuilder::KeyForSurfaceOrigin(rt->origin());
    } else {
        header->fSurfaceOriginKey = 0;
    }

    if (requiredFeatures & GrProcessor::kSampleLocations_RequiredFeature) {
        SkASSERT(pipeline.isHWAntialiasState());
        header->fSamplePatternKey = rt->renderTargetPriv().getMultisampleSpecs(pipeline.getStencil()).fUniqueID;
    } else {
        header->fSamplePatternKey = 0;
    }

    header->fOutputSwizzle = glslCaps.configOutputSwizzle(rt->config()).asKey();

    if (pipeline.ignoresCoverage()) {
        header->fIgnoresCoverage = 1;
    } else {
        header->fIgnoresCoverage = 0;
    }

    header->fSnapVerticesToPixelCenters = pipeline.snapVerticesToPixelCenters();
    header->fColorEffectCnt = pipeline.numColorFragmentProcessors();
    header->fCoverageEffectCnt = pipeline.numCoverageFragmentProcessors();
=======
    if (pipeline.readsFragPosition()) {
        header->fFragPosKey =
                GrGLFragmentShaderBuilder::KeyForFragmentPosition(pipeline.getRenderTarget(),
                                                                  gpu->glCaps());
    } else {
        header->fFragPosKey = 0;
    }
    header->fSnapVerticesToPixelCenters = pipeline.snapVerticesToPixelCenters();
    header->fColorEffectCnt = pipeline.numColorFragmentStages();
    header->fCoverageEffectCnt = pipeline.numCoverageFragmentStages();
>>>>>>> miniblink49
    glDesc->finalize();
    return true;
}
